"""Public FlexSoC Python API and ``fx`` CLI contract tests."""

from __future__ import annotations

import inspect
import io
import json
import os
import subprocess
import sys
from pathlib import Path

import pytest

import flexsoc.api as api_module
import flexsoc.backend.syn.eqy as setup_eqy_module
import flexsoc.backend.signoff.sta as signoff_sta_module
import flexsoc.backend.signoff.power as signoff_power_module
import flexsoc.backend.signoff.fusion as signoff_fusion_module
import flexsoc.backend.syn.syn as setup_syn_module
import flexsoc.backend.impl.impl as setup_pnr_module
import flexsoc.backend.signoff.gls as post_sim_module
import flexsoc.cli as cli_module
import flexsoc.backend.core.toolchain as doctor_module
from flexsoc import (
    FlexSoC,
    FlexSoCCommand,
    FlexSoCConfig,
    FlexSoCResult,
    FlexSoCTarget,
)
from flexsoc.api import (
    ACTIVITY_ANALYSIS_TARGETS,
    AUTO_SETUP_TARGETS,
    DEFAULT_SETTINGS,
    NATIVE_TARGETS,
    STREAM_BY_DEFAULT_TARGETS,
    TARGETS,
    TECHNOLOGY_TARGETS,
    main as api_main,
)
from flexsoc.backend.core.package import PackageFlow
from flexsoc.backend.core.reporting import collect_manifest
from flexsoc.backend.core.reporting import (
    collect_formal,
    collect_fusion_analysis,
    collect_metrics,
    collect_physical_signoff,
    collect_post_syn_gls,
    collect_power_estimate,
    collect_sta,
    formal_stage,
    flow_summary,
    signoff_summary,
    status_word,
)
from flexsoc.backend.signoff.gls import _cocotb_wrapper, execute_all
from flexsoc.backend.dv.testbench import (
    CocotbConfig,
    cocotb_reg_driver_py_text,
    cocotb_vec_driver_py_text,
    render_gls_make_block,
    render_reg_driver_py,
    render_tlul_interface,
    sv_driver_text,
    write_cocotb_scaffold,
)
from flexsoc.backend.signoff.sta import (
    SIGNOFF_SCENARIOS,
    SDF_MODE_TO_CORNER,
    SignoffContext,
    _run_sta,
    _timing_values,
    _selection,
    generate_families,
    render_sta_tcl,
    scenario_corner,
)
from flexsoc.backend.signoff.power import (
    _annotate_power_summary,
    _write_activity_table,
    render_power_analysis_tcl,
    render_power_estimate_tcl,
)
from flexsoc.backend.signoff.fusion import render_fusion_analysis_tcl
from flexsoc.backend.core.execution import print_script, strip_ansi
from flexsoc.backend.core import ClockConfig, ClockDomain
from flexsoc.backend.core import pdk_run_layout
from flexsoc.cli import app


ROOT = Path(__file__).resolve().parents[1]


def _fake_pdk(root: Path) -> Path:
    """Create the minimum digital views accepted by ``fx pdk use``."""

    (root / "lib").mkdir(parents=True)
    (root / "verilog").mkdir(parents=True)
    (root / "lib" / "sky130_fd_sc_hd__tt_025C_1v80.lib").write_text(
        "library(sky130_fd_sc_hd) {}\n", encoding="utf-8"
    )
    (root / "verilog" / "sky130_fd_sc_hd.v").write_text(
        "module sky130_fd_sc_hd__buf_1; endmodule\n", encoding="utf-8"
    )
    return root


def _completed(
    argv: tuple[str, ...],
    returncode: int = 0,
    stdout: str = "",
    stderr: str = "",
) -> subprocess.CompletedProcess[str]:
    return subprocess.CompletedProcess(argv, returncode, stdout, stderr)


def test_pnr_resolves_orfs_tools_from_active_path(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setenv("OPENROAD_EXE", "/usr/local/OpenROAD/bin/openroad")
    monkeypatch.setenv("YOSYS_EXE", "/stale/yosys")
    monkeypatch.setenv("KLAYOUT_CMD", "/stale/klayout")
    resolved = {
        "openroad": "/active/bin/openroad",
        "yosys": "/active/bin/yosys",
        "klayout": "/active/bin/klayout",
    }
    monkeypatch.setattr(doctor_module.shutil, "which", resolved.get)

    env = doctor_module.orfs_environment()

    assert env["OPENROAD_EXE"] == resolved["openroad"]
    assert env["YOSYS_EXE"] == resolved["yosys"]
    assert env["KLAYOUT_CMD"] == resolved["klayout"]


# ---------------------------------------------------------------------------
# Python API
# ---------------------------------------------------------------------------


def test_public_value_objects_are_serializable(tmp_path: Path) -> None:
    target = FlexSoCTarget("lint", "RTL", "Lint RTL", ("TOP",))
    command = FlexSoCCommand(
        "lint",
        ("make", "lint", "TOP=demo"),
        tmp_path,
        {"PATH": "/bin"},
        {"TOP": "demo"},
    )
    result = FlexSoCResult(command, 0, "ok\n", "", tmp_path / "lint.log")

    assert target.to_dict() == {
        "name": "lint",
        "group": "RTL",
        "description": "Lint RTL",
        "params": ["TOP"],
    }
    assert command.shell_line() == "make lint TOP=demo"
    assert command.to_dict() == {
        "target": "lint",
        "argv": ["make", "lint", "TOP=demo"],
        "cwd": str(tmp_path),
        "values": {"TOP": "demo"},
        "shell": "make lint TOP=demo",
    }
    assert result.ok
    assert result.to_dict()["log_path"] == str(tmp_path / "lint.log")


def test_config_describe_set_and_override(tmp_path: Path) -> None:
    config = FlexSoCConfig(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        options={"TOP": "legacy", "RUN_ID": "dev"},
        values={"TOP": "demo"},
    )
    fx = FlexSoC(config, HOST="uart")

    assert config.make_values() == {"TOP": "demo", "RUN_ID": "dev"}
    assert fx.describe() == {
        "package": "flexsoc",
        "project_root": str(tmp_path.resolve()),
        "workdir": str((tmp_path / "work").resolve()),
        "settings": {"TOP": "demo", "RUN_ID": "dev", "HOST": "uart"},
    }
    assert fx.set(run_top="chip") is fx
    clone = fx.override(top="cordic")
    assert fx.settings["TOP"] == "demo"
    assert clone.settings["TOP"] == "cordic"
    assert clone.settings["RUN_TOP"] == "chip"


def test_target_catalog_metadata_aliases_and_command_construction(tmp_path: Path) -> None:
    fx = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work")

    assert fx.target_names() == tuple(TARGETS)
    assert tuple(target.name for target in fx.targets()) == fx.target_names()
    assert fx.target_info("lint-width") == fx.target_info("lint_width")
    assert all(fx.command(name).target == name for name in fx.target_names())
    with pytest.raises(ValueError, match="unknown target"):
        fx.target_info("not-a-target")


def test_values_normalize_clock_wave_and_pdk_settings(tmp_path: Path) -> None:
    pdk = _fake_pdk(tmp_path / "pdk")
    domains = "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:high"
    fx = FlexSoC(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        PDK="sky130",
        PDK_ROOT=pdk,
        N_CLOCKS=2,
        CLOCK_DOMAINS=domains,
        CLOCK_RELATIONSHIPS="async:cfg:rx",
        WAVE_FORMAT="VCD",
    )

    values = fx.values()
    assert values["WORKSPACE"] == str((tmp_path / "work").resolve())
    assert values["PDK"] == "sky130"
    assert values["LIB_SYN"].endswith("sky130_fd_sc_hd__tt_025C_1v80.lib")
    assert values["N_CLOCKS"] == "2"
    assert values["CLOCK_DOMAINS"] == domains
    assert values["CLOCK_RELATIONSHIPS"] == "async:cfg:rx"
    assert values["WAVE_FORMAT"] == values["WAVE_EXT"] == "vcd"
    assert "--trace-vcd" in values["VERILATOR_FLAGS"]

    single = fx.values({"N_CLOCKS": 1, "CLOCK_DOMAINS": "core:clk_i:rst_ni:10:low"})
    assert single["CLOCK_RELATIONSHIPS"] == ""
    with pytest.raises(ValueError, match="WAVE_FORMAT"):
        fx.values({"WAVE_FORMAT": "wlf"})


def test_pdk_switch_keeps_shared_run_artifacts_and_reselects_technology_paths(
    tmp_path: Path,
) -> None:
    pdk = _fake_pdk(tmp_path / "pdk")
    fx = FlexSoC(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        TOP="demo",
        RUN_ID="dev",
        PDK="sky130",
        PDK_ROOT=pdk,
    )

    sky130 = fx.values()
    ihp = fx.values({"PDK": "ihp-sg13g2", "PDK_ROOT": pdk})

    assert sky130["RUN_ROOT"] == ihp["RUN_ROOT"]
    assert sky130["SIGNOFF_SDC_FILE"] != ihp["SIGNOFF_SDC_FILE"]
    assert sky130["SIGNOFF_SDC_FILE"].endswith("signoff/sky130/demo.sdc")
    assert ihp["SIGNOFF_SDC_FILE"].endswith("signoff/ihp-sg13g2/demo.sdc")
    for key in (
        "SYNDIR",
        "EQUIVDIR",
        "SIGNOFF_STA_DIR",
        "SIGNOFF_POWER_DIR",
        "SIGNOFF_SDF_DIR",
        "SIGNOFF_FUSION_DIR",
        "POST_SYN_SIMDIR",
        "METADIR",
        "COMMAND_LOGDIR",
    ):
        assert sky130[key] != ihp[key]
        assert "sky130" in Path(sky130[key]).parts
        assert "ihp-sg13g2" in Path(ihp[key]).parts



def test_commands_route_direct_backend_targets(tmp_path: Path) -> None:
    fx = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work", TOP="base")

    lint, ast_cmd = fx.override(top="cordic").commands(
        "lint-width", "slang_ast", RUN_ID="r1", UNUSED="ignored"
    )
    assert [lint.target, ast_cmd.target] == ["lint_width", "slang_ast"]
    assert lint.argv[:2] == ("fx", "lint_width")
    assert "RUN_ID=r1" in lint.argv
    assert not any("UNUSED=" in arg for arg in lint.argv)
    assert "make" not in lint.argv
    assert "flexsoc.backend.setup_" not in lint.shell_line()

    for name in (*NATIVE_TARGETS, *ACTIVITY_ANALYSIS_TARGETS):
        command = fx.command(name)
        assert command.argv[:2] == ("fx", name)
        assert "flexsoc.backend." not in command.shell_line()




def test_ip_save_preview_keeps_user_parameters_and_derives_artifacts_in_backend(tmp_path: Path) -> None:
    command = FlexSoC(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        TOP="cordic",
    ).command(
        "ip_save",
        IP_NAME="cordic_release",
        IP_LIBRARY_ROOT=tmp_path / "ip-library",
    )

    assert command.target == "ip_save"
    assert "IP_NAME=cordic_release" in command.argv
    assert f"IP_LIBRARY_ROOT={tmp_path / 'ip-library'}" in command.argv
    assert command.argv[:2] == ("fx", "ip_save")
    assert not any("SIGNOFF_STA_DIR=" in arg for arg in command.argv)
    assert "eqy_view" in inspect.signature(PackageFlow.save).parameters



def test_view_selects_named_gls_waveform_and_avoids_wayland_on_wsl(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch,
) -> None:
    stage = tmp_path / "post_pnr" / "ihp-sg13g2"
    stage.mkdir(parents=True)
    wanted = stage / "test_tb_smoke_sv_tt.fst"
    other = stage / "test_tb_corners_sv_ss.fst"
    wanted.write_text("wave\n", encoding="utf-8")
    other.write_text("wave\n", encoding="utf-8")

    assert api_module._select_waveform(stage, "test", "smoke_sv_tt") == wanted
    assert api_module._select_waveform(stage, "test", wanted.name) == wanted
    with pytest.raises(FileNotFoundError, match="available: corners_sv_ss, smoke_sv_tt"):
        api_module._select_waveform(stage, "test", "missing_sv_tt")
    empty = tmp_path / "empty"
    empty.mkdir()
    with pytest.raises(FileNotFoundError, match="run the matching simulation first"):
        api_module._select_waveform(empty, "test", "smoke_sv_tt")

    monkeypatch.setenv("WSL_DISTRO_NAME", "Ubuntu")
    assert api_module._viewer_environment("surfer", "auto") == {"WAYLAND_DISPLAY": ""}
    assert api_module._viewer_environment("/usr/bin/surfer", "x11") == {"WAYLAND_DISPLAY": ""}
    assert api_module._viewer_environment("surfer", "wayland") == {}
    assert api_module._viewer_environment("gtkwave", "x11") == {}
    assert {"PDK", "SIGNOFF_STAGE", "SIM_NAME", "WAVE_VIEWER", "SURFER_BACKEND"} <= set(TARGETS["view"][2])


def test_auto_setup_expansion_is_ordered_deduplicated_and_optional(
    tmp_path: Path,
) -> None:
    fx = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work")

    assert "setup_syn" not in AUTO_SETUP_TARGETS
    assert AUTO_SETUP_TARGETS["syn"] == ("setup_syn",)
    assert "regression" not in AUTO_SETUP_TARGETS
    assert AUTO_SETUP_TARGETS["setup_pnr"] == ("syn", "setup_signoff")
    assert AUTO_SETUP_TARGETS["pnr"] == ("setup_pnr",)
    assert "physical_signoff" in TARGETS
    assert "physical_signoff" in TECHNOLOGY_TARGETS
    assert AUTO_SETUP_TARGETS["sim_post_syn_all"] == ("sdf",)
    assert AUTO_SETUP_TARGETS["setup_formal_prove"] == ("setup_formal",)
    assert AUTO_SETUP_TARGETS["formal_bmc"] == ("setup_formal_prove",)
    assert [command.target for command in fx.commands("syn")] == ["setup_syn", "syn"]
    assert [command.target for command in fx.commands("regression")] == ["regression"]
    assert [command.target for command in fx.commands("sdf", "sta", "power_estimate", "fusion_analysis")] == [
        "setup_signoff", "sdf", "sta", "power_estimate", "fusion_analysis"
    ]
    assert [
        command.target
        for command in fx.commands("setup_signoff", "setup_syn", "syn")
    ] == ["setup_signoff", "setup_syn", "syn"]
    assert [
        command.target for command in fx.commands("eqy", auto_setup=False)
    ] == ["eqy"]
    assert [
        command.target
        for command in fx.commands("sim_post_syn", GLS_BACKEND="sv")
    ] == ["sim_post_syn"]
    assert [
        command.target
        for command in fx.commands("sim_post_syn", GLS_BACKEND="cocotb")
    ] == ["sim_post_syn"]
    assert [
        command.target
        for command in fx.commands("sim_post_syn", TIMING_MODE="typ")
    ] == ["setup_signoff", "sdf", "sim_post_syn"]
    assert [
        command.target
        for command in fx.commands("sim_post_pnr", TIMING_MODE="typ")
    ] == ["setup_signoff_post_pnr", "sdf_post_pnr", "sim_post_pnr"]
    assert [
        command.target
        for command in fx.commands("sim_post_pnr", TIMING_MODE="typ", auto_setup=False)
    ] == ["sim_post_pnr"]


def test_synthesis_defaults_to_area_and_finishes_for_physical_implementation(tmp_path: Path) -> None:
    liberty = tmp_path / "cells.lib"
    liberty.write_text("library(test) {}\n", encoding="utf-8")
    cfg = setup_syn_module.SynthesisConfig(
        top="demo",
        topdir=tmp_path,
        target="asic",
        clk_period_ns=10.0,
        output=tmp_path / "syn",
        liberty=liberty,
        tie_hi=("TIEHI", "Y"),
        tie_lo=("TIELO", "Y"),
        min_buffer=("BUF", "A", "Y"),
    )
    assert cfg.opt == "area"
    script = setup_syn_module.yosys_synth_asic_verilog(
        cfg.top, cfg.topdir, liberty, cfg.clk_period_ns, cfg.opt, cfg.sdcdir, cfg.output,
        tie_hi=cfg.tie_hi, tie_lo=cfg.tie_lo, min_buffer=cfg.min_buffer,
    )
    assert f"read_liberty -overwrite -setattr liberty_cell -lib {liberty}" in script
    assert script.index("read_liberty") < script.index("read_verilog")
    assert "dfflibmap -prepare" in script
    assert "abc -keepff" in script
    assert "dfflibmap -map-only" in script
    assert script.index("check -assert") < script.index("splitnets")
    assert "splitnets" in script
    assert "hilomap -singleton -hicell TIEHI Y -locell TIELO Y" in script
    assert "insbuf -buf BUF A Y" in script
    assert "check -assert -mapped" in script
    assert "write_verilog -nohex -nodec" in script


def test_setup_pnr_consumes_only_mapped_netlist_and_sdc(tmp_path: Path) -> None:
    netlist = tmp_path / "demo_synth.v"
    sdc = tmp_path / "demo.sdc"
    netlist.write_text("module demo; endmodule\n", encoding="utf-8")
    sdc.write_text("current_design demo\n", encoding="utf-8")
    text = setup_pnr_module.render_config("demo", "sky130hd", netlist, sdc)
    assert f"SYNTH_NETLIST_FILES := {netlist}" in text
    assert f"SDC_FILE             := {sdc}" in text
    assert "VERILOG_FILES" not in text
    assert "SYNTH_HDL_FRONTEND" not in text
    assert "ABC_AREA" not in text
    assert "STRATEGY" not in text
    assert "PLACE_DENSITY ?= 0.58" in text


def test_dry_run_returns_commands_without_spawning(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    monkeypatch.setattr(
        subprocess,
        "run",
        lambda *args, **kwargs: pytest.fail("dry_run must not spawn a process"),
    )
    commands = FlexSoC(project_root=tmp_path).run("hjson", "reg", dry_run=True, TOP="demo")
    assert [command.target for command in commands] == ["hjson", "reg"]
    assert all(isinstance(command, FlexSoCCommand) for command in commands)



def test_run_exception_is_visible_and_persisted_in_command_log(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
    tmp_path: Path,
) -> None:
    def execute(self, target: str) -> int:
        raise ValueError("missing routed SDF")

    monkeypatch.setattr(api_module._TargetRouter, "execute", execute)
    fx = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work")
    with pytest.raises(RuntimeError, match="missing routed SDF"):
        fx.run("hjson", TOP="demo")

    output = capsys.readouterr()
    assert "[error] missing routed SDF" in output.out
    log = fx._command_log_path(fx.command("hjson", TOP="demo"))
    assert log.read_text(encoding="utf-8") == "[error] missing routed SDF\n"


def test_run_capture_executes_direct_backend_and_writes_log(tmp_path: Path) -> None:
    result, = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work").run(
        "hjson", capture=True, TOP="demo", RUN_ID="api"
    )

    assert isinstance(result, FlexSoCResult)
    assert result.ok
    assert (tmp_path / "work/runs/demo/api/data/demo.hjson").is_file()
    assert result.log_path is not None and result.log_path.is_file()
    assert "make" not in result.command.argv




def test_gate_and_power_logs_are_scoped_by_gls_case(tmp_path: Path) -> None:
    pdk = _fake_pdk(tmp_path / "pdk")
    fx = FlexSoC(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        PDK="sky130",
        PDK_ROOT=pdk,
        TOP="demo",
    )

    def log(target: str, **values: str) -> Path:
        return fx._command_log_path(fx.command(target, **values))

    assert log(
        "sim_post_syn", TEST_NAME="smoke", GLS_BACKEND="sv", TIMING_MODE="typ"
    ).name == "sim_post_syn_smoke_sv_tt.log"
    assert log(
        "sim_post_syn", TEST_NAME="corners", GLS_BACKEND="sv", TIMING_MODE="typ"
    ).name == "sim_post_syn_corners_sv_tt.log"
    assert log(
        "sim_post_syn_all", TEST_NAMES="all", GLS_BACKEND="sv", TIMING_MODES="all"
    ).name == "sim_post_syn_all.log"
    assert log(
        "power_analysis",
        POWER_TEST_NAME="smoke",
        POWER_GLS_BACKEND="sv",
        POWER_TIMING_MODE="typ",
    ).name == "power_analysis_smoke_sv_tt.log"
    assert log(
        "power_analysis_all",
        POWER_TEST_NAMES="all",
        POWER_GLS_BACKENDS="all",
        POWER_TIMING_MODES="all",
    ).name == "power_analysis_all.log"




def test_all_target_log_names_omit_default_all_selectors(tmp_path: Path) -> None:
    fx = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work", TOP="demo")
    default = fx.command(
        "sim_post_syn_all",
        TEST_NAMES="all",
        GLS_BACKEND="sv",
        TIMING_MODES="all",
        auto_setup=False,
    )
    selected = fx.command(
        "sim_post_syn_all",
        TEST_NAMES="smoke corners",
        GLS_BACKEND="cocotb",
        TIMING_MODES="typ max",
        auto_setup=False,
    )

    assert fx._command_log_path(default).name == "sim_post_syn_all.log"
    assert fx._command_log_path(selected).name == (
        "sim_post_syn_all_tests_smoke_corners_backend_cocotb_timing_tt_ss.log"
    )


def test_terminal_rendering_uses_one_semantic_palette() -> None:
    from io import StringIO

    from flexsoc.backend.core.execution import (
        print_label,
        print_live_line,
        print_target_result,
        print_target_start,
    )

    stream = StringIO()
    print_target_start("sta", "Run STA", stream=stream, color=True)
    print_label("log", "/tmp/sta.log", stream=stream, color=True)
    print_live_line("[report] /tmp/timing.rpt\n", stream=stream, color=True)
    print_target_result("sta", 0, stream=stream, color=True)
    text = stream.getvalue()

    assert "\x1b[38;5;208m→ sta\x1b[0m" in text
    assert "\x1b[38;5;208m[log]\x1b[0m \x1b[94m/tmp/sta.log\x1b[0m" in text
    assert "\x1b[38;5;208m[report]\x1b[0m \x1b[94m/tmp/timing.rpt\x1b[0m" in text
    assert "\x1b[92m✓\x1b[0m \x1b[38;5;208msta\x1b[0m: \x1b[92mdone\x1b[0m" in text



def test_sim_post_syn_all_discovers_matrix_and_writes_dv_summary(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    for name in ("corners", "smoke"):
        test = run / "dv/functional/tests" / name
        test.mkdir(parents=True)
        for filename in ("config.regs", "data_in.vec", "data_out.vec"):
            (test / filename).write_text("0\n", encoding="utf-8")

    seen: list[tuple[str, str, str]] = []

    def fake_execute(
        action: str, stage: str, project_root: Path, values: dict[str, str]
    ) -> int:
        assert action == "sim" and stage == "post_syn"
        seen.append((values["TEST_NAME"], values["GLS_BACKEND"], values["TIMING_MODE"]))
        paths = post_sim_module.resolve_paths(project_root, values, stage)
        paths.report.parent.mkdir(parents=True, exist_ok=True)
        paths.report.write_text(
            json.dumps(
                {
                    "status": "pass",
                    "returncode": 0,
                    "stage": stage,
                    "test_name": values["TEST_NAME"],
                    "backend": values["GLS_BACKEND"],
                    "timing_mode": values["TIMING_MODE"],
                }
            )
            + "\n",
            encoding="utf-8",
        )
        return 0

    monkeypatch.setattr(post_sim_module, "execute", fake_execute)
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "TOP": "demo",
        "PDK": "sky130",
        "TEST_NAMES": "all",
        "GLS_BACKEND": "cocotb",
        "TIMING_MODES": "zero typ",
    }

    assert execute_all(tmp_path, values) == 0
    assert seen == [
        (test, "cocotb", mode)
        for test in ("corners", "smoke")
        for mode in ("zero", "typ")
    ]
    summary_path = run / "dv/functional/sim/post_syn/sky130/summary_cocotb.json"
    summary = json.loads(summary_path.read_text(encoding="utf-8"))
    assert summary["status"] == "pass"
    assert summary["total"] == 4
    assert summary["tests"] == ["corners", "smoke"]
    assert summary["backend"] == "cocotb"
    assert summary["timing_modes"] == ["zero", "typ"]
    assert summary["scenarios"] == ["zero", "tt"]



def test_post_syn_sdf_artifacts_use_pvt_scenario_names(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "TOP": "demo",
        "PDK": "sky130",
        "TEST_NAME": "smoke",
        "TESTBENCH": "demo_tb",
        "GLS_BACKEND": "sv",
        "WAVE_FORMAT": "fst",
    }
    expected = {"min": "ff", "typ": "tt", "max": "ss"}
    for mode, scenario in expected.items():
        paths = post_sim_module.resolve_paths(
            tmp_path, {**values, "TIMING_MODE": mode}, "post_syn"
        )
        assert paths.report.name == f"demo_post_syn_smoke_sv_{scenario}.json"
        assert paths.wave.name == f"demo_tb_smoke_sv_{scenario}.fst"
        assert paths.executable.name == f"demo_tb_smoke_sv_{scenario}.vvp"
        assert paths.log.name == f"demo_post_syn_smoke_sv_{scenario}.log"
        assert paths.sdf == (
            workspace / f"runs/demo/dev/signoff/sky130/sdf/{scenario}/demo_{scenario}.sdf"
        ).resolve()


def test_sdf_gls_enables_icarus_interconnect_for_all_timing_stages(
    tmp_path: Path,
) -> None:
    stage = tmp_path / "stage"
    stage.mkdir()
    tb = tmp_path / "demo_tb.sv"
    netlist = tmp_path / "demo.v"
    sdf = tmp_path / "demo.sdf"
    sources = (
        (tb, "module demo_tb; endmodule\n"),
        (netlist, "module demo; endmodule\n"),
        (sdf, "(DELAYFILE)\n"),
    )
    for path, text in sources:
        path.write_text(text, encoding="utf-8")
    paths = post_sim_module.GateSimPaths(
        tmp_path, tmp_path / "impl", stage, tb, netlist, sdf,
        stage / "wave.fst", stage / "sim.vvp", stage / "sim.log", stage / "sim.json",
    )
    values = {
        "TOP": "demo", "TESTBENCH": "demo_tb",
        "GLS_BACKEND": "sv", "TIMING_MODE": "typ",
    }

    routed = post_sim_module.compile_command(tmp_path, values, "post_pnr", paths)
    post_syn = post_sim_module.compile_command(tmp_path, values, "post_syn", paths)
    assert "-ginterconnect" in routed
    assert "-ginterconnect" not in post_syn
    assert "-ginterconnect" not in post_sim_module.compile_command(
        tmp_path, {**values, "TIMING_MODE": "unit"}, "post_pnr", paths
    )

    (tmp_path / "Makefile").write_text("all:\n", encoding="utf-8")
    cocotb_paths = post_sim_module.GateSimPaths(
        tmp_path, tmp_path / "impl", stage, tmp_path / "demo_tb.sv", netlist, sdf,
        stage / "cocotb.fst", stage / "cocotb.vvp", stage / "cocotb.log", stage / "cocotb.json",
    )
    cocotb = {**values, "GLS_BACKEND": "cocotb"}
    assert "GLS_INTERCONNECT=1" in post_sim_module.cocotb_command(
        "compile", cocotb, "post_pnr", cocotb_paths
    )
    assert "GLS_INTERCONNECT=0" in post_sim_module.cocotb_command(
        "compile", cocotb, "post_syn", cocotb_paths
    )
    block = render_gls_make_block(str(netlist))
    assert "ifeq ($(GLS_INTERCONNECT),1)" in block
    assert "COMPILE_ARGS += -ginterconnect" in block


def test_icarus_sdf_strict_ignores_only_unsupported_timingchecks() -> None:
    summary = post_sim_module.sdf_annotation_summary(
        "[TB] sdf = /tmp/demo.sdf scope=u_demo mode=TYPICAL\n"
        "SDF WARNING: /tmp/demo.sdf:10: TIMINGCHECK not supported.\n"
        "SDF WARNING: Unable to match ModPath A -> Y in u_demo._1_\n"
    )
    assert summary["ignored_warnings"] == {"timingcheck_unsupported": 1}
    assert len(summary["warnings"]) == 1
    assert "Unable to match ModPath" in summary["warnings"][0]


def test_post_pnr_gls_metrics_require_interconnect_delays(tmp_path: Path) -> None:
    run = tmp_path / "runs/demo/dev"
    sim = pdk_run_layout(run, pdk="sky130", top="demo").post_pnr_sim_dir
    sim.mkdir(parents=True)
    wave = sim / "demo_tb_smoke_sv_tt.fst"
    wave.write_text("wave\n", encoding="utf-8")
    report = sim / "demo_post_pnr_smoke_sv_tt.json"
    common = {
        "stage": "post_pnr", "top": "demo", "pdk": "sky130", "test_name": "smoke",
        "backend": "sv", "timing_mode": "typ", "scenario": "tt", "status": "pass",
        "timing_model": "icarus-path-delay-only", "wave": str(wave),
        "annotation": {"requested_marker": True, "errors": [], "warnings": []},
    }
    report.write_text(
        json.dumps({**common, "interconnect_delays": "disabled"}) + "\n",
        encoding="utf-8",
    )
    gls = collect_post_syn_gls("demo", run, "sky130", "post_route")
    assert gls is not None and gls["status"] == "fail"
    assert "interconnect delays are not enabled" in gls["failures"][0]["reason"]

    report.write_text(
        json.dumps({**common, "interconnect_delays": "enabled"}) + "\n",
        encoding="utf-8",
    )
    gls = collect_post_syn_gls("demo", run, "sky130", "post_route")
    assert gls is not None and gls["status"] == "pass"
    assert gls["interconnect_delays"] == "enabled"
    summary = signoff_summary({"post_pnr": {"gls": gls}})
    assert summary["post_pnr"]["gls"]["interconnect_delays"] == "enabled"


def test_post_syn_gls_metrics_require_no_interconnect_delays(tmp_path: Path) -> None:
    run = tmp_path / "runs/demo/dev"
    sim = pdk_run_layout(run, pdk="sky130", top="demo").post_syn_sim_dir
    sim.mkdir(parents=True)
    wave = sim / "demo_tb_smoke_sv_tt.fst"
    wave.write_text("wave\n", encoding="utf-8")
    report = sim / "demo_post_syn_smoke_sv_tt.json"
    common = {
        "stage": "post_syn", "top": "demo", "pdk": "sky130", "test_name": "smoke",
        "backend": "sv", "timing_mode": "typ", "scenario": "tt", "status": "pass",
        "timing_model": "icarus-path-delay-only", "wave": str(wave),
        "annotation": {"requested_marker": True, "errors": [], "warnings": []},
    }
    report.write_text(
        json.dumps({**common, "interconnect_delays": "enabled"}) + "\n",
        encoding="utf-8",
    )
    gls = collect_post_syn_gls("demo", run, "sky130")
    assert gls is not None and gls["status"] == "fail"
    assert "unexpectedly enables interconnect delays" in gls["failures"][0]["reason"]

    report.write_text(
        json.dumps({**common, "interconnect_delays": "none"}) + "\n",
        encoding="utf-8",
    )
    gls = collect_post_syn_gls("demo", run, "sky130")
    assert gls is not None and gls["status"] == "pass"
    assert gls["interconnect_delays"] == "none"
    summary = signoff_summary({"post_syn_gls": gls})
    assert summary["post_syn_gls"]["interconnect_delays"] == "none"


def test_successful_sdf_gls_cleanup_removes_legacy_mode_artifacts(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "TOP": "demo",
        "PDK": "sky130",
        "TEST_NAME": "smoke",
        "TESTBENCH": "demo_tb",
        "GLS_BACKEND": "sv",
        "TIMING_MODE": "typ",
        "WAVE_FORMAT": "fst",
    }
    paths = post_sim_module.resolve_paths(tmp_path, values, "post_syn")
    stage = workspace / "runs/demo/dev/dv/functional/sim/post_syn/sky130"
    logs = workspace / "runs/demo/dev/logs/dv/functional/post_syn/sky130"
    legacy = (
        stage / "demo_tb_smoke_sv_typ.fst",
        stage / "demo_tb_smoke_sv_typ.vvp",
        stage / "demo_post_syn_smoke_sv_typ.json",
        logs / "demo_post_syn_smoke_sv_typ.log",
        logs / "demo_post_syn_smoke_sv_typ_compile.log",
    )
    for path in legacy:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("legacy\n", encoding="utf-8")
    for path in (paths.wave, paths.executable, paths.log, paths.report):
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("canonical\n", encoding="utf-8")

    post_sim_module._cleanup_legacy_sdf_artifacts(tmp_path, values, "post_syn", paths)

    assert not any(path.exists() for path in legacy)
    assert all(path.exists() for path in (paths.wave, paths.executable, paths.log, paths.report))


def test_sim_post_syn_all_rejects_legacy_multi_backend_selector(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    test = workspace / "runs/demo/dev/dv/functional/tests/smoke"
    test.mkdir(parents=True)
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "TOP": "demo",
        "PDK": "sky130",
        "TEST_NAMES": "all",
        "GLS_BACKEND": "sv",
        "GLS_BACKENDS": "all",
        "TIMING_MODES": "typ",
    }
    with pytest.raises(ValueError, match="GLS_BACKENDS is not supported"):
        execute_all(tmp_path, values)


def test_sim_post_syn_all_continues_after_one_failed_case(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    for name in ("a", "b"):
        (run / "dv/functional/tests" / name).mkdir(parents=True)

    seen: list[str] = []

    def fake_execute(
        action: str, stage: str, project_root: Path, values: dict[str, str]
    ) -> int:
        del action, stage, project_root
        seen.append(values["TEST_NAME"])
        if values["TEST_NAME"] == "a":
            raise ValueError("synthetic failure")
        paths = post_sim_module.resolve_paths(tmp_path, values, "post_syn")
        paths.report.parent.mkdir(parents=True, exist_ok=True)
        paths.report.write_text(
            json.dumps(
                {
                    "status": "pass",
                    "returncode": 0,
                    "test_name": values["TEST_NAME"],
                    "backend": values["GLS_BACKEND"],
                    "timing_mode": values["TIMING_MODE"],
                }
            )
            + "\n",
            encoding="utf-8",
        )
        return 0

    monkeypatch.setattr(post_sim_module, "execute", fake_execute)
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "TOP": "demo",
        "PDK": "sky130",
        "TEST_NAMES": "all",
        "GLS_BACKEND": "sv",
        "TIMING_MODES": "zero",
    }
    assert execute_all(tmp_path, values) == 2
    assert seen == ["a", "b"]
    summary = json.loads(
        (run / "dv/functional/sim/post_syn/sky130/summary_sv.json").read_text(encoding="utf-8")
    )
    assert summary["passed"] == 1
    assert summary["failed"] == 1
    assert summary["total"] == 2



def test_run_check_and_nonchecking_failure_modes(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    monkeypatch.setattr(api_module._TargetRouter, "execute", lambda self, target: 7)
    fx = FlexSoC(project_root=tmp_path)

    with pytest.raises(RuntimeError, match="exit code 7"):
        fx.run("hjson")
    result, = fx.run("hjson", check=False)
    assert isinstance(result, FlexSoCResult)
    assert result.returncode == 7 and not result.ok




def test_live_run_streams_direct_backend_and_keeps_plain_log(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
    tmp_path: Path,
) -> None:
    def execute(self, target: str) -> int:
        print("generated line")
        print("\033[38;5;208m[script]\033[0m file.tcl")
        return 0

    monkeypatch.setattr(api_module._TargetRouter, "execute", execute)
    result, = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work").run(
        "hjson", live=True, TOP="demo"
    )

    output = capsys.readouterr().out
    assert output.startswith("→ hjson: ")
    assert "[log] " in output
    assert "generated line" in output and "[script]" in output
    assert "✓ hjson: done" in output
    assert result.ok and result.log_path is not None
    assert result.log_path.read_text(encoding="utf-8") == (
        "generated line\n[script] file.tcl\n"
    )




def test_sim_post_syn_all_prints_uniform_header_artifacts_and_done(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
    tmp_path: Path,
) -> None:
    def execute(self, target: str) -> int:
        print("[sim_post_syn_all] 1/1 START test=smoke backend=sv timing=typ")
        print("[report] smoke/sv/typ /tmp/smoke.json")
        print("[report] machine_summary=/tmp/summary_sv.json")
        return 0

    monkeypatch.setattr(api_module._TargetRouter, "execute", execute)
    pdk = _fake_pdk(tmp_path / "pdk")
    result, = FlexSoC(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        PDK="sky130",
        PDK_ROOT=pdk,
        TOP="demo",
    ).run(
        "sim_post_syn_all",
        auto_setup=False,
        TEST_NAMES="all",
        GLS_BACKEND="sv",
        TIMING_MODES="all",
    )

    output = capsys.readouterr().out
    assert output.startswith(
        "→ sim_post_syn_all: Run every selected post-synthesis GLS test/timing combination with one backend\n"
    )
    assert "[log] " in output and "sim_post_syn_all.log" in output
    assert "[report] smoke/sv/typ /tmp/smoke.json" in output
    assert "[report] machine_summary=/tmp/summary_sv.json" in output
    assert "1/1 START" not in output
    assert "✓ sim_post_syn_all: done" in output
    assert result.ok





def test_fusion_streams_only_artifact_paths_by_default_and_keeps_full_log(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
    tmp_path: Path,
) -> None:
    seen_env: dict[str, str] = {}

    def execute(self, target: str) -> int:
        seen_env["FLEXSOC_LIVE"] = os.environ["FLEXSOC_LIVE"]
        seen_env["PYTHONUNBUFFERED"] = os.environ["PYTHONUNBUFFERED"]
        print("[fusion_analysis] run 1/6 START workload=smoke_sv_tt corner=tt mode=setup")
        print("[script] /tmp/fusion_analysis.tcl · corner=tt · mode=setup")
        print("[fusion_analysis] run 1/6 DISCOVERY PASS paths=20 hotspots=18")
        print("[report] tt/setup /tmp/fusion.rpt")
        return 0

    monkeypatch.setattr(api_module._TargetRouter, "execute", execute)
    pdk = _fake_pdk(tmp_path / "pdk")
    result, = FlexSoC(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        PDK="sky130",
        PDK_ROOT=pdk,
        TOP="demo",
    ).run(
        "fusion_analysis",
        auto_setup=False,
        POWER_TEST_NAME="smoke",
        POWER_GLS_BACKEND="sv",
        POWER_TIMING_MODE="typ",
    )

    output = capsys.readouterr().out
    assert STREAM_BY_DEFAULT_TARGETS == {
        "sim_post_syn_all", "sim_post_pnr_all",
        "power_analysis_all", "power_analysis_post_pnr_all",
        "fusion_analysis", "fusion_analysis_all",
        "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
    }
    assert output.startswith("→ fusion_analysis: Correlate timing and power in one aligned GLS scenario\n")
    assert "[log] " in output
    assert "[script] /tmp/fusion_analysis.tcl" in output
    assert "[report] tt/setup /tmp/fusion.rpt" in output
    assert "run 1/6 START" not in output
    assert "DISCOVERY PASS" not in output
    assert "✓" in output and "fusion_analysis" in output and "done" in output
    assert seen_env == {"FLEXSOC_LIVE": "0", "PYTHONUNBUFFERED": "1"}
    assert result.log_path is not None
    assert result.log_path.read_text(encoding="utf-8") == (
        "[fusion_analysis] run 1/6 START workload=smoke_sv_tt corner=tt mode=setup\n"
        "[script] /tmp/fusion_analysis.tcl · corner=tt · mode=setup\n"
        "[fusion_analysis] run 1/6 DISCOVERY PASS paths=20 hotspots=18\n"
        "[report] tt/setup /tmp/fusion.rpt\n"
    )



def test_technology_execution_requires_an_activated_pdk(tmp_path: Path) -> None:
    fx = FlexSoC(project_root=tmp_path, PDK="sky130", PDK_ROOT=tmp_path / "missing")
    with pytest.raises(RuntimeError, match="fx pdk fetch"):
        fx.run(next(iter(TECHNOLOGY_TARGETS)))


def test_eqy_bind_uses_sky130_liberty_fallback_without_adapter(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    output = tmp_path / "eqy"
    output.mkdir()
    filelist = tmp_path / "rtl_ip.f"
    netlist = tmp_path / "netlist.v"
    liberty = tmp_path / "library.lib"
    cell_model = tmp_path / "cells.v"
    for path in (filelist, netlist, liberty, cell_model):
        path.write_text("placeholder\n", encoding="utf-8")
    config = output / "cordic_rtl_vs_syn.eqy"
    config.write_text(
        "[gate]\nread_verilog -formal -sv formal_pdk.v\n"
        "read_verilog -formal -sv netlist.v\n",
        encoding="utf-8",
    )

    monkeypatch.setenv("FLEXSOC_PDK", "sky130")
    monkeypatch.setattr(setup_eqy_module, "_formal_pdk_processor", lambda _cfg: None)
    setup_eqy_module.bind_equivalence_profile(
        top="cordic",
        output_dir=output,
        filelists=(filelist,),
        netlist=netlist,
        liberty=liberty,
        cell_models=(cell_model,),
        formal_pdk_proc=None,
        clock_gate_model=output / "sky130_clock_gates_formal.v",
        config=config,
    )

    bound = config.read_text(encoding="utf-8")
    assert "formal_pdk.v" not in bound
    assert "read_liberty -ignore_miss_func library.lib" in bound
    assert "read_verilog -formal -sv sky130_clock_gates_formal.v" in bound




def test_ip_save_optional_pnr_and_e2e_activity_order(tmp_path: Path) -> None:
    """Packaging stays atomic/optional-PnR and GLS workloads keep power→fusion order."""
    top, pdk = "demo", "sky130"
    run = tmp_path / "run"
    synth = run / "syn" / pdk
    signoff = run / "signoff" / pdk
    eqy = signoff / "equivalence" / "rtl_vs_syn"
    synth.mkdir(parents=True)
    eqy.mkdir(parents=True)
    (synth / f"{top}_synth.v").write_text("module demo; endmodule\n", encoding="utf-8")
    (synth / f"{top}_generic.il").write_text("checkpoint\n", encoding="utf-8")
    sdc = signoff / f"{top}.sdc"
    sdc.write_text("create_clock -period 10 clk_i\n", encoding="utf-8")
    (signoff / "sta").mkdir()
    (signoff / "sta/sta.tcl").write_text("# sta\n", encoding="utf-8")
    config = eqy / f"{top}_rtl_vs_syn.eqy"
    view = eqy / f"{top}_eqy_view.sv"
    config.write_text("[gold]\n", encoding="utf-8")
    view.write_text("module demo; endmodule\n", encoding="utf-8")
    flist = run / "rtl.f"
    flist.write_text("", encoding="utf-8")
    liberty = tmp_path / "cells.lib"
    liberty.write_text("library(cells) {}\n", encoding="utf-8")
    model = tmp_path / "cells.v"
    model.write_text("module cell; endmodule\n", encoding="utf-8")
    gate = eqy / "sky130_clock_gates_formal.v"
    gate.write_text("// gates\n", encoding="utf-8")
    library = tmp_path / "library"

    flow = PackageFlow(tmp_path, {})
    saved = flow.save(
        ip_name=top,
        top=top,
        pdk=pdk,
        library_root=library,
        synth_dir=synth,
        signoff_dir=signoff,
        sdc_file=sdc,
        eqy_config=config,
        eqy_view=view,
        filelists=(flist,),
        netlist=synth / f"{top}_synth.v",
        liberty=liberty,
        cell_models=(model,),
        clock_gate_model=gate,
    )
    assert not (saved / "impl" / pdk).exists()
    assert not (saved / "syn" / pdk / f"{top}_generic.il").exists()

    implementation = run / "impl" / pdk
    implementation.mkdir(parents=True)
    (implementation / "config.mk").write_text("DESIGN_NAME := demo\n", encoding="utf-8")
    flow.save(
        ip_name=top,
        top=top,
        pdk=pdk,
        library_root=library,
        synth_dir=synth,
        signoff_dir=signoff,
        sdc_file=sdc,
        eqy_config=config,
        eqy_view=view,
        filelists=(flist,),
        netlist=synth / f"{top}_synth.v",
        liberty=liberty,
        cell_models=(model,),
        clock_gate_model=gate,
        impl_dir=implementation,
        force=True,
    )
    assert (saved / "impl" / pdk / "config.mk").is_file()

    e2e = (ROOT / "tests/test_e2e_fx.py").read_text(encoding="utf-8")
    assert 'for target in ("power_analysis", "fusion_analysis")' in e2e
    assert e2e.count("_run_power_and_fusion(") == 71
    assert "_assert_saved_multitech_layout(saved_library, top)" in e2e
    assert "_assert_e2e_ip_save_isolated(argv)" in e2e
    assert "E2E ip_save must not write repository IPs" in e2e
    assert e2e.count("IP_LIBRARY_ROOT={saved_library_arg}") == e2e.count("fx ip_save")
    assert e2e.count("fx ip_save --force") == e2e.count("fx ip_save")
    assert "fx power_analysis --no-setup" not in e2e
    assert "fx fusion_analysis --no-setup" not in e2e



def test_uart_eqy_flow_is_consistent_across_pdks() -> None:
    """UART EQY differs by technology model only, not proof structure."""

    root = ROOT / "hw/ips/uart/signoff"
    sky = (root / "sky130/equivalence/rtl_vs_syn/uart_rtl_vs_syn.eqy").read_text(encoding="utf-8")
    ihp = (root / "ihp-sg13g2/equivalence/rtl_vs_syn/uart_rtl_vs_syn.eqy").read_text(encoding="utf-8")
    expected_ihp = sky.replace(
        "read_verilog -formal -sv formal_pdk.v",
        "read_liberty -ignore_miss_func library.lib",
        1,
    )

    assert ihp == expected_ihp
    matches = [line for line in sky.splitlines() if line.startswith("gold-match ")]
    assert matches == [
        "gold-match clk_i",
        "gold-match rst_ni",
        "gold-match tl_i",
        "gold-match tl_o__flexsoc_eqy_handshake",
        "gold-match tl_o__flexsoc_eqy_d_ctrl",
        "gold-match tl_o__flexsoc_eqy_d_data",
        "gold-match tl_o__flexsoc_eqy_d_meta",
        "gold-match cio_rx_i",
        "gold-match cio_tx_o",
        "gold-match cio_tx_en_o",
    ]
    assert not any("*" in line for line in matches)

def test_api_main_delegates_to_cli(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr(cli_module, "app", lambda argv=None: 23)
    assert api_main(["commands"]) == 23


# ---------------------------------------------------------------------------
# Command-line interface
# ---------------------------------------------------------------------------


def test_cli_help_and_commands_json(capsys: pytest.CaptureFixture[str], tmp_path: Path) -> None:
    for argv in ([], ["help"], ["-h"], ["--help"]):
        assert app(argv) == 0
        help_text = capsys.readouterr().out
        assert "Canonical IP lifecycle" in help_text
        assert "Step" in help_text and "Command" in help_text and "Purpose" in help_text
        assert help_text.index("1. Configure the run") < help_text.index("2. Create a new IP scaffold")
        assert help_text.index("sim_post_syn") < help_text.index("power_analysis")
        assert "sim_post_syn_all" in help_text
        assert help_text.index("power_analysis") < help_text.index("fusion_analysis")
        assert "6. Run post-synthesis sign-off" in help_text
        assert "fx <command> --help" in help_text

    assert app(["commands", "--json", "--project-root", str(tmp_path)]) == 0
    catalog = json.loads(capsys.readouterr().out)
    assert [item["name"] for item in catalog] == list(TARGETS)
    assert all({"name", "group", "description", "params"} == set(item) for item in catalog)



def test_cli_completion_protocol_bypasses_custom_guide(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str],
) -> None:
    """Shell TAB completion must reach Click instead of printing the lifecycle."""

    calls: list[tuple[list[str], str, bool]] = []

    class CompletionCommand:
        def main(self, *, args: list[str], prog_name: str, standalone_mode: bool) -> int:
            calls.append((args, prog_name, standalone_mode))
            print("sim_post_syn\nsim_post_pnr")
            return 0

    monkeypatch.setenv("_FX_COMPLETE", "complete_bash")
    monkeypatch.setattr(cli_module, "_click_command", lambda: CompletionCommand())
    assert app([]) == 0
    output = capsys.readouterr().out
    assert output == "sim_post_syn\nsim_post_pnr\n"
    assert calls == [([], "fx", False)]
    assert "Canonical IP lifecycle" not in output

def test_cli_dedicated_help_aliases_and_signoff_selectors(
    capsys: pytest.CaptureFixture[str],
) -> None:
    for argv in (
        ["fusion_analysis", "--help"],
        ["fusion_analysis", "-h"],
        ["fusion_analysis", "help"],
        ["fusion_analysis", "info"],
        ["help", "fusion_analysis"],
    ):
        assert app(argv) == 0
        output = capsys.readouterr().out
        assert "fx fusion_analysis" in output
        assert "Correlate timing and power" in output
        assert "POWER_TEST_NAME" in output
        assert "POWER_GLS_BACKEND" in output
        assert "POWER_TIMING_MODE" in output
        assert "Automatic setup" in output and "setup_signoff" in output

    assert app(["pdk", "--help"]) == 0
    pdk_help = capsys.readouterr().out
    assert "fx pdk list" in pdk_help and "fx pdk use sky130" in pdk_help


def test_cli_settings_persist_reset_unset_and_derive_paths(
    capsys: pytest.CaptureFixture[str], tmp_path: Path
) -> None:
    workdir = tmp_path / "external"
    domains = "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low"
    assert app([
        "settings",
        "--reset",
        "TOP=demo",
        "N_CLOCKS=2",
        f"CLOCK_DOMAINS={domains}",
        "CLOCK_RELATIONSHIPS=async:cfg:rx",
        "--project-root", str(tmp_path),
        "--workdir", str(workdir),
        "--json",
    ]) == 0
    shown = json.loads(capsys.readouterr().out)
    stored = json.loads((tmp_path / ".flexsoc/settings.json").read_text(encoding="utf-8"))
    assert stored["TOP"] == "demo"
    assert stored["WAVE_FORMAT"] == DEFAULT_SETTINGS["WAVE_FORMAT"]
    assert shown["WORKSPACE"] == str(workdir.resolve())
    assert shown["RUN_ROOT"].startswith(str(workdir.resolve()))

    assert app([
        "settings",
        "N_CLOCKS=1",
        "CLOCK_DOMAINS=core:clk_i:rst_ni:10:low",
        "--unset", "TOP",
        "--project-root", str(tmp_path),
        "--json",
    ]) == 0
    updated = json.loads(capsys.readouterr().out)
    assert "TOP" not in updated
    assert updated["CLOCK_RELATIONSHIPS"] == ""


def test_cli_target_info_dry_run_and_script_output(
    capsys: pytest.CaptureFixture[str], tmp_path: Path
) -> None:
    root_args = ["--project-root", str(tmp_path), "--workdir", str(tmp_path / "work")]

    assert app(["hjson", "--info", "--json", *root_args]) == 0
    info = json.loads(capsys.readouterr().out)
    assert info["name"] == "hjson" and info["description"] == TARGETS["hjson"][1]

    assert app([
        "hjson", "reg", "--dry-run", "--set", "TOP=demo", "--force", *root_args
    ]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert len(lines) == 2
    assert " hjson " in lines[0] and " reg " in lines[1]
    assert all("TOP=demo" in line and "FORCE=1" in line for line in lines)

    assert app(["setup_signoff", "--dry-run", "--script", *root_args]) == 0
    script = capsys.readouterr().out
    assert script.startswith("#!/usr/bin/env bash\nset -euo pipefail\n")
    assert " setup_signoff " in script



def test_cli_auto_setup_and_no_setup_dry_run(
    capsys: pytest.CaptureFixture[str], tmp_path: Path
) -> None:
    root_args = ["--project-root", str(tmp_path), "--workdir", str(tmp_path / "work")]

    assert app(["syn", "--dry-run", *root_args]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert [line.split()[1] for line in lines] == ["setup_syn", "syn"]

    assert app(["syn", "--no-setup", "--dry-run", *root_args]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert len(lines) == 1 and lines[0].split()[1] == "syn"

    assert app(["regression", "--dry-run", *root_args]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert len(lines) == 1 and lines[0].split()[1] == "regression"

    assert app(["regression", "--no-setup", "--dry-run", *root_args]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert len(lines) == 1 and lines[0].split()[1] == "regression"



def test_cli_tool_and_dependency_options_are_forwarded(
    capsys: pytest.CaptureFixture[str], tmp_path: Path
) -> None:
    assert app([
        "lint", "--dry-run", "--tool", "verilator",
        "--project-root", str(tmp_path),
    ]) == 0
    assert "LINT_TOOL=verilator" in capsys.readouterr().out

    assert app([
        "deps-status", "--dry-run", "--user", "--profile", "base", "--jobs", "3",
        "--project-root", str(tmp_path),
    ]) == 0
    output = capsys.readouterr().out
    assert "DEPS_MODE=user" in output
    assert "DEPS_PROFILE=base" in output
    assert "DEPS_JOBS=3" in output


@pytest.mark.parametrize(
    ("argv", "message"),
    [
        (["settings", "BROKEN"], "expected KEY=VALUE"),
        (["missing-target", "--dry-run"], "unknown target"),
        (["deps", "--user", "--system"], "choose only one"),
        (["deps", "--profile", "unknown"], "profile must be"),
        (["deps", "--jobs", "0"], "positive integer"),
        (["hjson", "--user"], "only valid for dependency targets"),
    ],
)


def test_cli_reports_invalid_user_input(
    capsys: pytest.CaptureFixture[str], tmp_path: Path, argv: list[str], message: str
) -> None:
    assert app([*argv, "--project-root", str(tmp_path)]) == 2
    assert message in capsys.readouterr().err


def test_cli_pdk_list_info_and_use(capsys: pytest.CaptureFixture[str], tmp_path: Path) -> None:
    assert app(["pdk", "list", "--json", "--project-root", str(tmp_path)]) == 0
    catalog = json.loads(capsys.readouterr().out)
    assert {item["name"] for item in catalog} >= {"sky130", "ihp-sg13g2", "asap7"}

    assert app(["pdk", "info", "sky130hd", "--json", "--project-root", str(tmp_path)]) == 0
    assert json.loads(capsys.readouterr().out)["name"] == "sky130"

    pdk = _fake_pdk(tmp_path / "prepared-pdk")
    assert app([
        "pdk", "use", "sky130", "--set", f"PDK_ROOT={pdk}",
        "--project-root", str(tmp_path), "--json",
    ]) == 0
    selected = json.loads(capsys.readouterr().out)
    settings = json.loads((tmp_path / ".flexsoc/settings.json").read_text(encoding="utf-8"))
    assert selected["active"] == "sky130"
    assert settings["PDK"] == "sky130"
    assert settings["PDK_ROOT"] == str(pdk.resolve())

    assert app([
        "pdk", "use", "sky130", "--set", f"PDK_ROOT={pdk}",
        "--project-root", str(tmp_path),
    ]) == 0
    output = capsys.readouterr().out
    assert "Shared RTL, DV, formal, and SDC artifacts remain valid" in output
    assert "setup_syn/syn" in output and "setup_eqy/eqy" in output


def test_doctor_opensta_31_and_versionless_btorsim(monkeypatch: pytest.MonkeyPatch) -> None:
    assert doctor_module._numeric_version("OpenSTA 3.1.0 e8af2e8ad9", "sta") == (3, 1, 0)
    version_ok, lock_match = doctor_module._assess_tool(
        "sta",
        "OpenSTA 3.1.0 e8af2e8ad9",
        {"minimum_version": "3.1.0", "locked_version": "3.1.0"},
    )
    assert version_ok and lock_match

    monkeypatch.setattr(doctor_module.shutil, "which", lambda executable: f"/usr/bin/{executable}")
    assert doctor_module._version("btorsim", ("--version",)) == (
        "/usr/bin/btorsim",
        "installed · version not exposed",
    )


def test_cli_dispatches_doctor_eqy_debug_and_shell(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    calls: list[tuple[str, object]] = []

    monkeypatch.setattr(
        doctor_module,
        "run",
        lambda root, as_json=False: calls.append(("doctor", (root, as_json))) or 4,
    )
    monkeypatch.setattr(
        cli_module,
        "_eqy_debug",
        lambda root, workdir, args, sets, as_json=False: calls.append(
            ("eqy_debug", (root, workdir, args, sets, as_json))
        ) or 5,
    )
    monkeypatch.setattr(
        cli_module,
        "_shell",
        lambda root, workdir: calls.append(("shell", (root, workdir))) or 6,
    )

    assert app(["doctor", "--json", "--project-root", str(tmp_path)]) == 4
    assert app([
        "eqy_debug", "partition.0", "--wave", "--set", "EQY_RESET_CYCLES=2",
        "--project-root", str(tmp_path),
    ]) == 5
    assert app([
        "shell", "--project-root", str(tmp_path), "--workdir", str(tmp_path / "work")
    ]) == 6
    assert [name for name, _ in calls] == ["doctor", "eqy_debug", "shell"]


def test_cli_execution_output_modes(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
    tmp_path: Path,
) -> None:
    seen: list[dict[str, object]] = []

    def fake_run(
        self: FlexSoC, *targets: str, **kwargs: object
    ) -> tuple[FlexSoCResult, ...]:
        seen.append({"targets": targets, **kwargs})
        overrides = {key: value for key, value in kwargs.items() if key.isupper()}
        command = self.command(targets[0], **overrides)
        return (FlexSoCResult(command, 0, "captured\n", "", tmp_path / "command.log"),)

    monkeypatch.setattr(FlexSoC, "run", fake_run)

    assert app(["hjson", "--capture", "--project-root", str(tmp_path)]) == 0
    assert capsys.readouterr().out == "captured\n"

    assert app(["hjson", "--json", "--project-root", str(tmp_path)]) == 0
    payload = json.loads(capsys.readouterr().out)
    assert payload["ok"] is True and payload["command"]["target"] == "hjson"

    assert app(["hjson", "--live", "--project-root", str(tmp_path)]) == 0
    assert capsys.readouterr().out == ""
    assert seen[-1]["live"] is True and seen[-1]["LIVE"] == "1"


# ---------------------------------------------------------------------------
# Backend contracts retained in the public API suite
# ---------------------------------------------------------------------------


def test_tlul_tb_scaffolds_drive_negedge_sample_posedge() -> None:
    single = render_tlul_interface()
    assert "TB timing contract: drive DUT inputs on negedge, sample DUT outputs on posedge" in single
    assert "task automatic drive_cycle();\n    @(negedge clk_i);" in single
    assert "task automatic sample_cycle();\n    @(posedge clk_i);" in single
    for kind in ("write", "read"):
        assert (
            f'wait_d2h_high(0, "{kind} a_ready");\n'
            "    drive_cycle();\n"
            "    h2d[108] <= 1'b0;"
        ) in single

    clocks = ClockConfig(
        domains=(
            ClockDomain("cfg", "cfg_clk_i", "cfg_rst_ni", 10.0),
            ClockDomain("rx", "rx_clk_i", "rx_rst_ni", 8.0),
            ClockDomain("dsp", "dsp_clk_i", "dsp_rst_ni", 5.0),
        )
    )
    multi = sv_driver_text("tri_stream_dsp", clocks)
    assert "TB timing contract: drive DUT inputs on negedge, sample DUT outputs on posedge" in multi
    for prefix in ("cfg", "dsp"):
        assert f"@(negedge {prefix}_clk_i);" in multi
        assert f"do @(posedge {prefix}_clk_i); while (!{prefix}_tl_o[0]);" in multi
        assert (
            f"do @(posedge {prefix}_clk_i); while (!{prefix}_tl_o[0]);\n"
            f"        @(negedge {prefix}_clk_i);\n"
            f"        {prefix}_tl_i[108] = 1'b0;"
        ) in multi

    cocotb = render_reg_driver_py()
    assert "async def _drive_cycle(clk):" in cocotb
    assert "await FallingEdge(clk)" in cocotb
    assert (
        'async def _sample_cycle(clk):\n'
        '    """Sample DUT outputs at the rising edge before the handshake is consumed."""\n\n'
        "    await RisingEdge(clk)\n"
        "\n\nasync def _drive_cycle(clk):"
    ) in cocotb
    assert cocotb.index("await _drive_cycle(clk)") < cocotb.index(
        '_get(dut, "tl_i_a_valid").value = 1'
    )
    assert cocotb.count("await RisingEdge(clk)") == 1
    assert cocotb.count("await FallingEdge(clk)") == 1
    assert "await _cycle(" not in cocotb
    assert "await _wait_cycles(_clock(dut, clk), wait_cycles)" in cocotb

    multi_cocotb = cocotb_reg_driver_py_text("tri_stream_dsp", clocks)
    assert multi_cocotb.count("await RisingEdge(clk)") == 1
    assert multi_cocotb.count("await FallingEdge(clk)") == 1
    assert "Sample one TL-UL handshake only on rising edges." in multi_cocotb
    assert "await _sample_cycle(clk)" in multi_cocotb
    assert "await _drive_cycle(clk)" in multi_cocotb
    assert (
        'await _wait_high(dut, f"{domain}_d_valid", clk)\n'
        '    data = int(getattr(dut, f"{domain}_d_data").value)'
    ) in multi_cocotb
    assert "TL-UL write error on {domain}" in multi_cocotb

    multi_vectors = cocotb_vec_driver_py_text("tri_stream_dsp")
    assert "FallingEdge" not in multi_vectors
    assert "RisingEdge" not in multi_vectors
    assert "await _drive_cycle(dut.rx_clk_i)" in multi_vectors
    assert "await _sample_cycle(dut.rx_clk_i)" in multi_vectors


def test_multiclock_cocotb_uses_canonical_wrapper_name(tmp_path: Path) -> None:
    output = tmp_path / "run" / "dv" / "functional" / "tb" / "cocotb"
    cfg = CocotbConfig(
        top="tri_stream_dsp",
        interface="tlul",
        output=output,
        rtl_dir=tmp_path / "rtl",
    )
    clocks = ClockConfig(
        domains=(
            ClockDomain("cfg", "cfg_clk_i", "cfg_rst_ni", 10.0),
            ClockDomain("rx", "rx_clk_i", "rx_rst_ni", 8.0),
            ClockDomain("dsp", "dsp_clk_i", "dsp_rst_ni", 5.0),
        )
    )

    write_cocotb_scaffold(cfg, clocks)

    wrapper = output / "tri_stream_dsp_tb.sv"
    assert wrapper.is_file()
    assert not (output / "tri_stream_dsp_cocotb_tb.sv").exists()
    assert "module tri_stream_dsp_tb;" in wrapper.read_text(encoding="utf-8")

    makefile = (output / "Makefile").read_text(encoding="utf-8")
    assert "COCOTB_TOPLEVEL = tri_stream_dsp_tb" in makefile
    assert "VERILOG_SOURCES += $(PWD)/tri_stream_dsp_tb.sv" in makefile
    assert _cocotb_wrapper(tmp_path / "run", "tri_stream_dsp") == wrapper


def test_manifest_lists_only_existing_artifact_directories(
    tmp_path: Path, monkeypatch,
) -> None:
    run = tmp_path / "runs" / "demo" / "dev"
    syn = run / "syn" / "sky130"
    syn.mkdir(parents=True)
    routed = run / "signoff/sky130/post_pnr/sta/tt/setup/timing.rpt"
    routed.parent.mkdir(parents=True)
    routed.write_text("wns max 0.100\ntns max 0.000\n", encoding="utf-8")
    monkeypatch.setenv("FLEXSOC_PDK", "sky130")
    monkeypatch.setenv("FLEXSOC_RUN_ROOT", str(run))

    data = collect_manifest(
        top="demo",
        run_top="demo",
        run_id="dev",
        repo_root=tmp_path,
    )

    artifacts = data["run"]["artifacts"]
    assert isinstance(artifacts, dict)
    assert artifacts == {
        "synthesis": str(syn.resolve()),
        "post_pnr_signoff": str((run / "signoff/sky130/post_pnr").resolve()),
    }
    assert data["signoff"]["post_pnr"]["sta"] == {
        "status": "pass", "clock_model": "propagated", "interconnect": "spef"
    }

def test_manifest_explicit_context_survives_native_router_without_environment(
    tmp_path: Path, monkeypatch,
) -> None:
    run = tmp_path / "runs" / "demo" / "dev"
    syn = run / "syn" / "sky130"
    syn.mkdir(parents=True)
    lock = tmp_path / "src" / "flexsoc" / "backend" / "core" / "toolchain.lock"
    lock.parent.mkdir(parents=True)
    lock.write_text("KLAYOUT_VERSION=0.30.7\n", encoding="utf-8")
    monkeypatch.delenv("FLEXSOC_PDK", raising=False)
    monkeypatch.delenv("FLEXSOC_RUN_ROOT", raising=False)

    data = collect_manifest(
        top="demo",
        run_top="demo",
        run_id="dev",
        repo_root=tmp_path,
        pdk="sky130",
        run_root=run,
    )

    assert data["run"]["pdk"] == "sky130"
    assert data["run"]["run_root"] == str(run)
    assert data["run"]["artifacts"] == {"synthesis": str(syn.resolve())}
    assert data["environment"]["toolchain_lock_sha256"] is not None


def _write_formal_stage(run: Path, top: str, suite: str, stage: str) -> None:
    formal = run / "dv" / "formal" / "runs"
    logs = run / "logs" / "dv" / "formal"
    if suite == "csr":
        category = "cover" if stage == "cover" else "prove"
        workdir = formal / "csr" / category / f"{top}_csr_{stage}"
        log = logs / "csr" / f"{top}_{stage}.log"
    else:
        category = "cover" if stage == "cover" else "prove"
        workdir = formal / "properties" / category / f"{top}_{stage}"
        log = logs / "properties" / f"{top}_{stage}.log"
    workdir.mkdir(parents=True, exist_ok=True)
    log.parent.mkdir(parents=True, exist_ok=True)
    (workdir / "status").write_text("PASS\n", encoding="utf-8")
    (workdir / "trace0.vcd").write_text("$enddefinitions $end\n", encoding="utf-8")
    log.write_text("DONE (PASS)\nElapsed clock time [00:00:03] (3)\n", encoding="utf-8")


def test_status_word_prefers_persisted_tool_result(tmp_path: Path) -> None:
    status = tmp_path / "status"
    log = tmp_path / "run.log"
    status.write_text("PASS\n", encoding="utf-8")
    log.write_text("informational ERROR counter: 0\n", encoding="utf-8")

    assert status_word(status, log) == "pass"


def test_formal_stage_collects_status_elapsed_and_trace(tmp_path: Path) -> None:
    run = tmp_path / "run"
    workdir = run / "dv/formal/runs/properties/prove/demo_prove"
    log = run / "logs/dv/formal/properties/demo_prove.log"
    workdir.mkdir(parents=True)
    log.parent.mkdir(parents=True)
    (workdir / "status").write_text("PASS\n", encoding="utf-8")
    (workdir / "trace0.vcd").write_text("trace\n", encoding="utf-8")
    log.write_text("Elapsed clock time [00:00:09] (9)\n", encoding="utf-8")

    data = formal_stage(run, workdir, log)

    assert data == {
        "status": "pass",
        "workdir": "dv/formal/runs/properties/prove/demo_prove",
        "log": "logs/dv/formal/properties/demo_prove.log",
        "trace_count": 1,
        "elapsed_s": 9,
        "traces": ["dv/formal/runs/properties/prove/demo_prove/trace0.vcd"],
    }


def test_collect_formal_reports_all_six_stages(tmp_path: Path) -> None:
    run = tmp_path / "run"
    top = "demo"
    for suite in ("csr", "properties"):
        for stage in ("bmc", "prove", "cover"):
            _write_formal_stage(run, top, suite, stage)

    data = collect_formal(top, run)

    assert data is not None
    assert data["status"] == "pass"
    assert data["summary"] == {
        "passed": 6,
        "observed": 6,
        "total": 6,
        "elapsed_s": 18,
        "traces": 6,
        "stages": {
            "bmc": {"passed": 2, "total": 2},
            "prove": {"passed": 2, "total": 2},
            "cover": {"passed": 2, "total": 2},
        },
    }


def _context(tmp_path: Path, *, analysis: str, mode: str = "setup") -> SignoffContext:
    liberty = tmp_path / "demo__tt.lib"
    netlist = tmp_path / "demo_synth.v"
    sdc = tmp_path / "demo.sdc"
    activity = tmp_path / "smoke.vcd"
    gls = tmp_path / "smoke.json"
    for path, text in (
        (liberty, "library(demo) {}\n"),
        (netlist, "module demo; endmodule\n"),
        (sdc, "create_clock -period 10 [get_ports clk]\n"),
        (activity, "$enddefinitions $end\n"),
        (gls, "{}\n"),
    ):
        path.write_text(text, encoding="utf-8")
    return SignoffContext(
        analysis=analysis,
        design="demo",
        variant="dev",
        pdk="sky130",
        stage="post_syn",
        corner="tt",
        mode=mode,
        workload="smoke_sv_tt" if "analysis" in analysis else "",
        top="demo",
        liberty=liberty,
        macro_liberties=(),
        netlist=netlist,
        sdc=sdc,
        report_dir=tmp_path / "reports",
        activity_file=activity if analysis in {"power_analysis", "fusion_analysis"} else None,
        activity_scope="demo_tb/u_demo",
        gls_report=gls if analysis in {"power_analysis", "fusion_analysis"} else None,
    )


def test_failed_opensta_keeps_details_in_log(
    tmp_path: Path, capsys: pytest.CaptureFixture[str]
) -> None:
    tool = tmp_path / "fake_sta.py"
    tool.write_text(
        "#!/usr/bin/env python3\n"
        "print('Error: synthetic OpenSTA failure')\n"
        "raise SystemExit(7)\n",
        encoding="utf-8",
    )
    tool.chmod(0o755)
    log = tmp_path / "sta.log"

    assert _run_sta([str(tool)], cwd=tmp_path, log=log) == 7

    captured = capsys.readouterr()
    assert captured.out == ""
    assert captured.err == ""
    assert "synthetic OpenSTA failure" in log.read_text(encoding="utf-8")


def test_sdf_writer_uses_pinned_opensta_command_contract(tmp_path: Path) -> None:
    from flexsoc.backend.signoff.sta import render_sdf_tcl

    script = render_sdf_tcl(_context(tmp_path, analysis="sdf", mode=""))
    assert "write_sdf -divider . -include_typ -no_timestamp -no_version $sdf_file" in script
    assert "proc flexsoc_complete_sdf_typ_header {path}" in script
    assert "flexsoc_complete_sdf_typ_header $sdf_file" in script
    assert "proc flexsoc_strip_sdf_interconnect_cell {path}" in script
    assert 'if {$stage eq "post_syn"} {' in script
    assert "flexsoc_strip_sdf_interconnect_cell $sdf_file" in script
    assert "sdf_interconnect=retained stage=post_route" in script
    assert "VOLTAGE" in script and "PROCESS" in script and "TEMPERATURE" in script
    assert "demo_tt.sdf" in script
    assert "units.rpt" not in script
    assert "check_setup.rpt" not in script


def test_sta_setup_hold_and_compact_report_contract(tmp_path: Path) -> None:
    setup = render_sta_tcl(_context(tmp_path, analysis="sta", mode="setup"))
    hold = render_sta_tcl(_context(tmp_path, analysis="sta", mode="hold"))

    assert "set delay_type max" in setup
    assert "set delay_type min" in hold
    assert "flexsoc_append_opensta $report report_wns -$delay_type" in setup
    assert "flexsoc_append_opensta $report report_tns -$delay_type" in setup
    assert "flexsoc_append_opensta $report report_units" in setup
    assert "sta::" not in setup
    assert "# Report worst negative slack" in setup
    assert "# Report the worst violating paths first" in setup
    assert "timing.rpt" in setup
    for section in (
        "Timing summary",
        "Constraint validation",
        "Violating paths",
        "Near-critical paths",
        "Unconstrained paths",
    ):
        assert section in setup
    for obsolete in (
        "summary.rpt",
        "check_setup.rpt",
        "endpoint_coverage.rpt",
        "violating.rpt",
        "near_critical.rpt",
        "unconstrained.rpt",
        "check_types.rpt",
        "endpoint_coverage.json",
        "units.rpt",
    ):
        assert obsolete not in setup


def test_power_estimate_uses_one_primary_report(tmp_path: Path) -> None:
    script = render_power_estimate_tcl(_context(tmp_path, analysis="power_estimate"))

    assert "set_power_activity -input" in script
    assert "set_power_activity -global" not in script
    assert "sta::" not in script
    assert "# Seed vectorless switching activity" in script
    assert "# Report average internal, switching, leakage, and total cell power" in script
    assert "Activity annotation" not in script
    assert "report_activity_annotation" not in script
    assert "annotated_percent=" not in script
    assert "analysis=power_estimate" in script
    assert "activity_source=input_assumption" in script
    assert "power.rpt" in script
    for obsolete in (
        "activity_assumptions.rpt",
        "activity_annotation.rpt",
        "power_summary.rpt",
        "highest_power_instances.rpt",
        "power.json",
        "highest_power_instances.json",
        "units.rpt",
        "check_setup.rpt",
    ):
        assert obsolete not in script


def test_activity_power_reads_trace_into_one_primary_report(tmp_path: Path) -> None:
    script = render_power_analysis_tcl(_context(tmp_path, analysis="power_analysis"))

    assert "read_vcd -scope $activity_scope $activity_file" in script
    assert "read_saif -scope $activity_scope $activity_file" in script
    assert "sta::" not in script
    assert "# Annotate signal transitions from the GLS VCD" in script
    assert "# Create one compact workload-driven power report" in script
    assert "report_activity_annotation -report_unannotated" in script
    assert "-report_annotated" not in script
    assert "annotated_percent=%.2f%%" in script
    assert "Unannotated pins:" in script
    assert "flexsoc_append_activity_coverage $report" in script
    assert "report_power -highest_power_instances" not in script
    assert "power.rpt" in script
    assert "power.json" not in script
    assert "highest_power_instances.json" not in script

def test_compact_activity_percent_parser() -> None:
    assert signoff_power_module._activity_percent("annotated_percent=99.75%\n") == 99.75
    assert signoff_power_module._activity_percent("Unannotated pins: none\n") is None


def test_opensta_signal_returncode_is_actionable() -> None:
    assert signoff_sta_module._returncode_text(-11) == "signal 11 (SIGSEGV)"
    assert signoff_sta_module._returncode_text(2) == "exit 2"


def test_fusion_discovers_worst_met_or_violated_paths_with_public_reports(tmp_path: Path) -> None:
    ctx = _context(tmp_path, analysis="fusion_analysis")
    script = render_fusion_analysis_tcl(ctx)

    assert script.index("flexsoc_append_opensta $report report_power") < script.index("Worst timing paths")
    assert "fusion.rpt" in script
    assert "methodology=staged_public_opensta" in script
    assert "Worst timing paths (violated or met)" in script
    assert "-slack_max" not in script
    assert "-group_path_count $endpoint_path_limit -endpoint_path_count 1" in script
    assert "-fields {slew capacitance input_pin net fanout}" in script
    assert "report_power -highest_power_instances" not in script
    assert "set highest_power_report [file join $report_dir .highest_power.rpt]" in script
    assert "set all_instances [get_cells -hierarchical *]" in script
    assert "report_power -instances $all_instances -digits 12" in script
    assert "sta::" not in script
    assert "# Discover the worst paths even when timing is met" in script
    assert "# Collect public per-instance power rows" in script
    for private in (
        "sta::instance_power",
        "sta::network_leaf_instances",
        "find_timing_paths",
        "get_property",
    ):
        assert private not in script


def test_signoff_tcl_uses_only_public_opensta_commands_and_explains_steps(tmp_path: Path) -> None:
    scripts = {
        "sta": render_sta_tcl(_context(tmp_path, analysis="sta", mode="setup")),
        "power_estimate": render_power_estimate_tcl(_context(tmp_path, analysis="power_estimate")),
        "power_analysis": render_power_analysis_tcl(_context(tmp_path, analysis="power_analysis")),
        "fusion_analysis": render_fusion_analysis_tcl(_context(tmp_path, analysis="fusion_analysis")),
    }

    for name, script in scripts.items():
        assert "sta::" not in script, name
        assert "# Load the standard-cell Liberty view" in script, name
        assert "# Read the mapped gate-level Verilog netlist" in script, name
        assert "# Link the selected top" in script, name
        assert "# Apply clocks, I/O delays" in script, name
        assert "# Validate clocks, endpoints, constraints" in script, name
        assert "flexsoc_append_opensta $report report_units" in script, name
        assert "log_begin $capture" in script, name
        assert "log_end" in script, name
        assert ">> $report" not in script, name
        assert "sta::redirect_file" not in script, name


def test_opensta_report_capture_uses_public_logging_not_private_redirects(tmp_path: Path) -> None:
    script = render_sta_tcl(_context(tmp_path, analysis="sta", mode="setup"))

    assert "proc flexsoc_append_opensta {path args}" in script
    assert "log_begin $capture" in script
    assert "log_end" in script
    assert "fcopy $src $dst" in script
    assert "sta::redirect_file" not in script
    assert "report_units >>" not in script
    assert "report_wns -$delay_type >>" not in script
    assert "report_tns -$delay_type >>" not in script


def test_fusion_parses_gate_timing_fanout_and_capacitance() -> None:
    report = """Startpoint: r1 (rising edge-triggered flip-flop clocked by clk)
Endpoint: r2 (rising edge-triggered flip-flop clocked by clk)
Path Group: clk
Path Type: max

 Fanout Cap Slew Delay Time Description
 ---------------------------------------------------------
 1 0.010 0.020 0.100 0.100 ^ r1/Q (DFF_X1)
 0.021 0.005 0.105 ^ u1/A (BUF_X1)
 3 0.030 0.022 0.080 0.185 ^ u1/Y (BUF_X1)
 0.024 0.004 0.189 ^ r2/D (DFF_X1)
 0.189 data arrival time
 0.250 data required time
 0.061 slack (MET)
"""
    paths = signoff_fusion_module._timing_path_blocks(report)

    assert len(paths) == 1
    assert paths[0]["status"] == "met"
    assert paths[0]["slack"] == pytest.approx(0.061)
    assert [stage["instance"] for stage in paths[0]["stages"]] == ["r1", "u1", "r2"]
    gate = paths[0]["stages"][1]
    assert gate["pins"] == ["A", "Y"]
    assert gate["fanout"] == pytest.approx(3.0)
    assert gate["capacitance"] == pytest.approx(0.03)
    assert gate["slew"] == pytest.approx(0.022)
    assert gate["delay"] == pytest.approx(0.08)
    assert gate["arrival"] == pytest.approx(0.185)


def test_fusion_normalizes_opensta_instance_power_json(tmp_path: Path) -> None:
    source = tmp_path / "power.json"
    source.write_text(
        json.dumps(
            [
                {
                    "name": "u1",
                    "internal": 1.0,
                    "switching": 2.0,
                    "leakage": 0.1,
                    "total": 3.1,
                }
            ]
        ),
        encoding="utf-8",
    )

    assert signoff_power_module._power_instance_rows(source) == [
        {
            "instance": "u1",
            "internal": 1.0,
            "switching": 2.0,
            "dynamic": 3.0,
            "leakage": 0.1,
            "total": 3.1,
        }
    ]


def test_fusion_normalizes_opensta_27_instance_power_text(tmp_path: Path) -> None:
    source = tmp_path / "power.rpt"
    source.write_text(
        """Instance                         Internal      Switching        Leakage          Total
                                      Power          Power          Power          Power (Watts)
-----------------------------------------------------------------------------------------------
u_top/u1                      1.000000e+00   2.000000e+00   1.000000e-01   3.100000e+00
u_top/u2                      4.000000e-03   5.000000e-04   2.000000e-05   4.520000e-03  1.2%
""",
        encoding="utf-8",
    )

    rows = signoff_power_module._power_instance_rows(source)
    assert rows[0] == {
        "instance": "u_top/u1",
        "internal": 1.0,
        "switching": 2.0,
        "dynamic": 3.0,
        "leakage": 0.1,
        "total": 3.1,
    }
    assert rows[1]["instance"] == "u_top/u2"
    assert rows[1]["total"] == pytest.approx(0.00452)


def test_fusion_normalizes_opensta_instance_power_name_at_end(tmp_path: Path) -> None:
    source = tmp_path / "power.rpt"
    source.write_text(
        """   Internal  Switching    Leakage      Total
      Power      Power      Power      Power (Watts)
--------------------------------------------
   1.20e-04   1.95e-04   2.12e-10   3.16e-04 u_top/u1
""",
        encoding="utf-8",
    )

    rows = signoff_power_module._power_instance_rows(source)
    assert rows == [
        {
            "instance": "u_top/u1",
            "internal": 1.2e-4,
            "switching": 1.95e-4,
            "dynamic": 3.15e-4,
            "leakage": 2.12e-10,
            "total": 3.16e-4,
        }
    ]


def test_fusion_normalizes_opensta_instance_power_with_cell_column(tmp_path: Path) -> None:
    source = tmp_path / "highest_power.rpt"
    source.write_text(
        """Rank Instance Cell Internal Switching Leakage Total Percent
1 u_top/u1 sky130_fd_sc_hd__buf_1 1.000000e+00 2.000000e+00 1.000000e-01 3.100000e+00 60.0%
2 u_top/u2 sky130_fd_sc_hd__inv_1 4.000000e-03 5.000000e-04 2.000000e-05 4.520000e-03 1.2%
""",
        encoding="utf-8",
    )

    rows = signoff_power_module._power_instance_rows(source)
    assert [row["instance"] for row in rows] == ["u_top/u1", "u_top/u2"]
    assert rows[0]["total"] == pytest.approx(3.1)
    assert rows[1]["leakage"] == pytest.approx(2.0e-5)


def test_fusion_normalizes_marked_per_instance_power_blocks(tmp_path: Path) -> None:
    source = tmp_path / "instance_power.rpt"
    source.write_text(
        """# FlexSoC marked OpenSTA instance-power blocks
=== FLEXSOC_INSTANCE u_top/u1 ===
Group Internal Switching Leakage Total
Sequential 0 0 0 0
Combinational 1.0 2.0 0.1 3.1
Total 1.0 2.0 0.1 3.1
=== FLEXSOC_INSTANCE u_top/u2 ===
Group Internal Switching Leakage Total
Total 4.0e-3 5.0e-4 2.0e-5 4.52e-3
""",
        encoding="utf-8",
    )

    rows = signoff_power_module._power_instance_rows(source)
    assert [row["instance"] for row in rows] == ["u_top/u1", "u_top/u2"]
    assert rows[0]["dynamic"] == pytest.approx(3.0)
    assert rows[1]["total"] == pytest.approx(4.52e-3)


def test_fusion_detail_pass_uses_public_power_and_timing_commands(tmp_path: Path) -> None:
    ctx = _context(tmp_path, analysis="fusion_analysis")
    script, marker = signoff_fusion_module._fusion_detail_tcl(
        ctx,
        ("u1", "array_reg[3]"),
        ("u1",),
    )

    assert "report_power -instances $instances -digits 12" in script
    assert "=== FLEXSOC_INSTANCE $instance_name ===" in script
    assert "foreach instance_name $instance_names instance_pattern $instance_patterns" in script
    assert "flexsoc_append_opensta $hotspot_report report_checks -through $pins" in script
    assert ">> $hotspot_report" not in script
    assert "get_cells" in script
    assert "get_pins [list" in script
    assert r"array_reg\[3\]" in script
    assert marker in script
    for private in ("sta::instance_power", "find_timing_paths", "get_property"):
        assert private not in script


def test_fusion_report_contains_path_gate_power_and_hotspot_reverse_lookup(tmp_path: Path) -> None:
    report = tmp_path / "fusion.rpt"
    report.write_text("analysis=fusion_analysis\n", encoding="utf-8")
    paths = [
        {
            "status": "met",
            "slack": 0.1,
            "type": "max",
            "group": "core",
            "startpoint": "r1",
            "endpoint": "r2",
            "stages": [
                {
                    "instance": "u1",
                    "cell": "BUF_X1",
                    "pins": ["A", "Y"],
                    "fanout": 2.0,
                    "capacitance": 0.03,
                    "slew": 0.02,
                    "delay": 0.08,
                    "arrival": 0.18,
                }
            ],
        }
    ]
    power = {
        "u1": {
            "internal": 1.0,
            "switching": 2.0,
            "dynamic": 3.0,
            "leakage": 0.1,
            "total": 3.1,
        }
    }
    hotspot = [{"instance": "u1", **power["u1"]}]
    signoff_fusion_module._append_fusion_tables(
        report,
        paths,
        power,
        hotspot,
        {"u1": {**paths[0], "raw": "Startpoint: r1\n0.1 slack (MET)"}},
    )
    text = report.read_text(encoding="utf-8")
    assert "Gate-level timing/power fusion" in text
    assert "stage instance cell pins fanout capacitance" in text
    assert "u1 BUF_X1 A,Y 2 0.03 0.02 0.08 0.18 1 2 3 0.1 3.1" in text
    assert "selected_worst_paths=1" in text
    assert "Startpoint: r1" in text


def test_fusion_enrichment_extends_power_to_hotspot_path_instances(
    tmp_path: Path,
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    ctx = _context(tmp_path, analysis="fusion_analysis")
    ctx.report_dir.mkdir(parents=True)
    ctx.report_dir.joinpath("fusion.rpt").write_text(
        """Startpoint: r1
Endpoint: r2
Path Group: core
Path Type: max
1 0.01 0.02 0.10 0.10 ^ u1/Y (BUF_X1)
0.10 data arrival time
0.20 data required time
0.10 slack (MET)
""",
        encoding="utf-8",
    )
    ctx.report_dir.joinpath(".highest_power.rpt").write_text(
        "u1 1.000000000000e+00 2.000000000000e+00 1.000000000000e-01 3.100000000000e+00\n",
        encoding="utf-8",
    )

    def fake_run(command: object, *, cwd: Path, log: Path) -> int:
        del cwd
        script = Path(command[-1])  # type: ignore[index]
        log.parent.mkdir(parents=True, exist_ok=True)
        if script.name == ".fusion_detail.tcl":
            ctx.report_dir.joinpath(".instance_power.rpt").write_text(
                "u1 1.000000000000e+00 2.000000000000e+00 1.000000000000e-01 3.100000000000e+00\n",
                encoding="utf-8",
            )
            ctx.report_dir.joinpath(".hotspot_paths.rpt").write_text(
                """=== HOTSPOT rank=1 instance=u1 ===
Startpoint: r3
Endpoint: r4
Path Group: core
Path Type: max
1 0.02 0.03 0.05 0.05 ^ u1/Y (BUF_X1)
2 0.04 0.04 0.06 0.11 ^ u2/Y (BUF_X2)
0.11 data arrival time
0.20 data required time
0.09 slack (MET)
""",
                encoding="utf-8",
            )
            log.write_text(
                "FLEXSOC_FUSION_DETAIL_COMPLETE corner=tt mode=setup workload=smoke_sv_tt\n",
                encoding="utf-8",
            )
        else:
            ctx.report_dir.joinpath(".additional_power.rpt").write_text(
                "u2 4.000000000000e+00 5.000000000000e+00 2.000000000000e-01 9.200000000000e+00\n",
                encoding="utf-8",
            )
            log.write_text(
                "FLEXSOC_FUSION_POWER_COMPLETE corner=tt mode=setup workload=smoke_sv_tt\n",
                encoding="utf-8",
            )
        return 0

    monkeypatch.setattr(signoff_fusion_module, "_run_sta", fake_run)
    result = signoff_fusion_module._enrich_fusion_report(
        tmp_path,
        {"STA": "sta"},
        ctx,
        tmp_path / "fusion.log",
        progress_label="",
        run_index=1,
        total_runs=1,
    )

    report = ctx.report_dir.joinpath("fusion.rpt").read_text(encoding="utf-8")
    assert result["hotspot_path_count"] == 1
    assert "u2 BUF_X2 Y 2 0.04 0.04 0.06 0.11 4 5 9 0.2 9.2" in report
    assert "path_power_complete=true" in report
    assert not tuple(ctx.report_dir.glob(".*power*.rpt"))
    assert not tuple(ctx.report_dir.glob(".fusion_*.tcl"))


def test_pre_layout_signoff_scenarios_are_canonical() -> None:
    assert SIGNOFF_SCENARIOS == {"ff": "min", "tt": "typ", "ss": "max"}
    assert SDF_MODE_TO_CORNER == {"min": "ff", "typ": "tt", "max": "ss"}
    assert scenario_corner("min") == "ff"
    assert scenario_corner("typ") == "tt"
    assert scenario_corner("max") == "ss"
    with pytest.raises(ValueError, match="no sign-off scenario"):
        scenario_corner("unit")


def test_activity_source_requires_aligned_sdf_corner(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    report = tmp_path / "demo_post_syn_smoke_sv_typ.json"
    wave = tmp_path / "wave.vcd"
    wave.write_text("$enddefinitions $end\n", encoding="utf-8")
    report.write_text(
        json.dumps(
            {
                "status": "pass",
                "stage": "post_syn",
                "top": "demo",
                "pdk": "sky130",
                "test_name": "smoke",
                "backend": "sv",
                "timing_mode": "typ",
                "sdf_corner": "ss",
                "sdf": str(tmp_path / "sdf" / "ss" / "demo_ss.sdf"),
                "wave": str(wave),
                "annotation": {"requested_marker": True},
            }
        )
        + "\n",
        encoding="utf-8",
    )
    monkeypatch.setattr(signoff_power_module, "_post_syn_report", lambda *args, **kwargs: report)

    with pytest.raises(ValueError, match="TIMING_MODE=typ requires SDF corner tt"):
        signoff_power_module._qualified_spec(
            tmp_path,
            {"TOP": "demo", "PDK": "sky130"},
            test="smoke",
            backend="sv",
            mode="typ",
        )


def test_fusion_table_is_compact_and_points_to_primary_reports(tmp_path: Path) -> None:
    workload_root = tmp_path / "smoke_sv_tt"
    reports = {
        "ss/setup": {
            "status": "pass",
            "wns": -0.01,
            "tns": -0.05,
            "internal_w": 0.1,
            "switching_w": 0.02,
            "leakage_w": 0.001,
            "total_w": 0.121,
            "activity_annotation_count": 5120,
            "report": str(workload_root / "setup/fusion.rpt"),
        }
    }

    table = _write_activity_table("fusion_analysis", workload_root, "smoke_sv_tt", reports)
    text = table.read_text(encoding="utf-8")
    assert table == workload_root / "fusion_table.rpt"
    assert "corner/mode status" in text
    assert "ss/setup" in text
    assert "setup/fusion.rpt" in text
    assert "activity_annotation.rpt" not in text


def test_activity_workload_uses_corner_name_and_flat_report_layout(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    spec = signoff_power_module.ActivitySpec(
        top="demo", pdk="sky130", test="smoke", backend="sv", mode="max",
        report=tmp_path / "gls.json", wave=tmp_path / "wave.vcd",
    )
    assert spec.workload == "smoke_sv_ss"
    assert spec.legacy_workload == "smoke_sv_max"

    liberties = {corner: tmp_path / f"{corner}.lib" for corner in ("ss", "tt", "ff")}
    for corner, liberty in liberties.items():
        liberty.write_text(f"library({corner}) {{}}\n", encoding="utf-8")
    spec.report.write_text("{}\n", encoding="utf-8")
    spec.wave.write_text("$enddefinitions $end\n", encoding="utf-8")

    class Layout:
        power_dir = tmp_path / "power"
        fusion_dir = tmp_path / "fusion"
        power_log_dir = tmp_path / "logs/power"
        fusion_log_dir = tmp_path / "logs/fusion"

        def signoff_stage_root(self, stage: str) -> Path:
            assert stage == "post_syn"
            return tmp_path

        def signoff_stage_log_root(self, stage: str) -> Path:
            assert stage == "post_syn"
            return tmp_path / "logs"

    legacy = Layout.power_dir / "analysis/smoke_sv_max/ss"
    legacy.mkdir(parents=True)
    (legacy / "power.rpt").write_text("stale\n", encoding="utf-8")

    monkeypatch.setattr(signoff_power_module, "layout_from_values", lambda *args: Layout())
    monkeypatch.setattr(signoff_power_module, "_liberties", lambda values: liberties)
    monkeypatch.setattr(
        signoff_power_module, "_activity_vcd", lambda *args: (spec.wave, None, "direct-vcd")
    )
    monkeypatch.setattr(
        signoff_power_module, "_resolve_vcd_scope", lambda *args, **kwargs: ("tb/dut", ("tb/dut",))
    )

    def fake_context(project_root: Path, values: object, **kwargs: object) -> SignoffContext:
        del project_root, values
        return SignoffContext(
            analysis=str(kwargs["analysis"]), design="demo", variant="dev", pdk="sky130",
            stage="post_syn", corner=str(kwargs["corner"]), mode=str(kwargs["mode"]),
            workload=str(kwargs["workload"]), top="demo", liberty=kwargs["liberty"],
            macro_liberties=(), netlist=tmp_path / "demo_synth.v", sdc=tmp_path / "demo.sdc",
            report_dir=kwargs["report_dir"], activity_file=kwargs["activity_file"],
            activity_scope=str(kwargs["activity_scope"]), gls_report=kwargs["gls_report"],
        )

    def fake_execute(
        project_root: Path, values: object, *, analysis: str, ctx: SignoffContext,
        script: Path, log: Path
    ) -> int:
        del project_root, values, analysis, script
        ctx.report_dir.mkdir(parents=True, exist_ok=True)
        (ctx.report_dir / "power.rpt").write_text(
            "annotated_percent=100.00%\nTotal 1.0 2.0 0.1 3.1\n", encoding="utf-8"
        )
        log.parent.mkdir(parents=True, exist_ok=True)
        log.write_text("complete\n", encoding="utf-8")
        return 0

    monkeypatch.setattr(signoff_power_module, "_base_context", fake_context)
    monkeypatch.setattr(signoff_power_module, "_execute_script", fake_execute)

    result = signoff_power_module.analyze_activity_spec(
        "power_analysis", tmp_path, {"SIGNOFF_CORNERS": "ss tt ff"}, spec
    )
    root = Layout.power_dir / "analysis/smoke_sv_ss"
    assert result["workload"] == "smoke_sv_ss"
    assert Path(result["corners"]["ss"]["report"]) == root / "power.rpt"
    assert (root / "power_table.rpt").is_file()
    assert not (root / "ss").exists()
    assert not (Layout.power_dir / "analysis/smoke_sv_max").exists()


def test_fusion_all_prints_workload_and_corner_progress(
    tmp_path: Path,
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
) -> None:
    liberties = {corner: tmp_path / f"{corner}.lib" for corner in ("ss", "tt", "ff")}
    wave = tmp_path / "demo_smoke_sv_typ.vcd"
    gls_report = tmp_path / "demo_smoke_sv_typ.json"
    fixtures = (
        *((path, f"library({corner}) {{}}\n") for corner, path in liberties.items()),
        (wave, "$enddefinitions $end\n"),
        (gls_report, "{}\n"),
    )
    for path, content in fixtures:
        path.write_text(content, encoding="utf-8")
    spec = signoff_power_module.ActivitySpec(
        top="demo",
        pdk="sky130",
        test="smoke",
        backend="sv",
        mode="typ",
        report=gls_report,
        wave=wave,
    )

    class Layout:
        fusion_dir = tmp_path / "fusion"
        power_dir = tmp_path / "power"
        fusion_log_dir = tmp_path / "logs/fusion"
        power_log_dir = tmp_path / "logs/power"

        def signoff_stage_root(self, stage: str) -> Path:
            assert stage == "post_syn"
            return tmp_path

        def signoff_stage_log_root(self, stage: str) -> Path:
            assert stage == "post_syn"
            return tmp_path / "logs"

    monkeypatch.setattr(signoff_power_module, "discover_specs", lambda *args: [spec])
    monkeypatch.setattr(signoff_power_module, "layout_from_values", lambda *args: Layout())
    monkeypatch.setattr(
        signoff_power_module,
        "_activity_vcd",
        lambda *args: (wave, None, "direct-vcd"),
    )
    monkeypatch.setattr(
        signoff_power_module,
        "_resolve_vcd_scope",
        lambda *args, **kwargs: ("demo_tb/u_demo", ("demo_tb/u_demo",)),
    )
    monkeypatch.setattr(signoff_power_module, "_liberties", lambda values: liberties)

    def fake_context(
        project_root: Path,
        values: object,
        **kwargs: object,
    ) -> SignoffContext:
        del project_root, values
        return SignoffContext(
            analysis=str(kwargs["analysis"]),
            design="demo",
            variant="dev",
            pdk="sky130",
            stage="post_syn",
            corner=str(kwargs["corner"]),
            mode=str(kwargs["mode"]),
            workload=str(kwargs["workload"]),
            top="demo",
            liberty=kwargs["liberty"],
            macro_liberties=(),
            netlist=tmp_path / "demo_synth.v",
            sdc=tmp_path / "demo.sdc",
            report_dir=kwargs["report_dir"],
            activity_file=kwargs["activity_file"],
            activity_scope=str(kwargs["activity_scope"]),
            gls_report=kwargs["gls_report"],
        )

    def fake_execute(
        project_root: Path,
        values: object,
        *,
        analysis: str,
        ctx: SignoffContext,
        script: Path,
        log: Path,
    ) -> int:
        del project_root, values, analysis, script
        ctx.report_dir.mkdir(parents=True, exist_ok=True)
        report = ctx.report_dir / "fusion.rpt"
        report.write_text(
            "Annotated 5120 pin activities.\n"
            "wns max 0.100\n"
            "tns max 0.000\n"
            "Total 1.0 2.0 0.1 3.1\n",
            encoding="utf-8",
        )
        log.parent.mkdir(parents=True, exist_ok=True)
        log.write_text("complete\n", encoding="utf-8")
        return 0

    def fake_enrich(
        project_root: Path,
        values: object,
        ctx: SignoffContext,
        log: Path,
        *,
        progress_label: str,
        run_index: int,
        total_runs: int,
    ) -> dict[str, object]:
        del project_root, values, log
        print(
            f"[{progress_label}] run {run_index}/{total_runs} DISCOVERY PASS "
            "paths=2 path_instances=4 hotspots=3"
        )
        print(
            f"[{progress_label}] run {run_index}/{total_runs} HOTSPOT TIMING START "
            "hotspots=3"
        )
        print(
            f"[{progress_label}] run {run_index}/{total_runs} HOTSPOT TIMING PASS "
            "targeted_paths=3 log=fake_detail.log"
        )
        print(
            f"[{progress_label}] run {run_index}/{total_runs} FUSION PASS "
            f"worst_paths=2 hotspot_paths=3 report={ctx.report_dir / 'fusion.rpt'}"
        )
        return {
            "timing_path_count": 2,
            "path_instance_count": 4,
            "power_hotspot_count": 3,
        }

    monkeypatch.setattr(signoff_power_module, "_base_context", fake_context)
    monkeypatch.setattr(signoff_power_module, "_execute_script", fake_execute)
    monkeypatch.setattr(signoff_power_module, "_enrich_fusion_report", fake_enrich)

    assert signoff_power_module.execute_activity(
        "fusion_analysis",
        "all",
        tmp_path,
        {
            "TOP": "demo",
            "PDK": "sky130",
            "SIGNOFF_CORNERS": "ss tt ff",
            "STA_MODES": "setup hold",
        },
    ) == 0

    output = capsys.readouterr().out
    assert "[fusion_analysis_all] workloads=1" in output
    assert "workload 1/1 START test=smoke backend=sv timing=typ name=smoke_sv_tt" in output
    assert "activity=" in output and "scope=demo_tb/u_demo scenario=tt/typ runs=2" in output
    assert "run 1/2 START workload=smoke_sv_tt corner=tt mode=setup" in output
    assert "run 1/2 DISCOVERY PASS paths=2 path_instances=4 hotspots=3" in output
    assert "run 1/2 HOTSPOT TIMING START hotspots=3" in output
    assert "run 1/2 HOTSPOT TIMING PASS targeted_paths=3" in output
    assert "run 1/2 FUSION PASS worst_paths=2 hotspot_paths=3 report=" in output
    assert "run 1/2 PASS report=" in output
    setup_report = "[report] tt/setup "
    hold_start = "run 2/2 START workload=smoke_sv_tt corner=tt mode=hold"
    assert setup_report in output
    assert output.index(setup_report) < output.index(hold_start)
    assert output.count(setup_report) == 1
    assert hold_start in output
    assert "[report] tt/hold " in output
    assert "workload 1/1 PASS progress=1/1 passed=1 failed=0" in output
    assert "[report] workload=smoke_sv_tt table=" in output
    assert "[report] machine_summary=" in output
    assert "[fusion_analysis_all] 1/1 PASS" in output
    assert "corner=ss" not in output and "corner=ff" not in output
    fusion_root = tmp_path / "fusion/smoke_sv_tt"
    assert (fusion_root / "setup/fusion.rpt").is_file()
    assert (fusion_root / "hold/fusion.rpt").is_file()
    assert not (fusion_root / "tt").exists()

    assert signoff_power_module.execute_activity(
        "fusion_analysis",
        "single",
        tmp_path,
        {
            "TOP": "demo",
            "PDK": "sky130",
            "SIGNOFF_CORNERS": "ss tt ff",
            "STA_MODES": "setup hold",
        },
    ) == 0
    single_output = capsys.readouterr().out
    assert "[fusion_analysis] workloads=1" in single_output
    assert "[report] tt/setup " in single_output
    assert single_output.index("[report] tt/setup ") < single_output.index(hold_start)
    assert "[report] tt/hold " in single_output
    assert "[report] machine_summary=" in single_output


def test_activity_all_uses_backends_as_alternative_sources(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    calls: list[str] = []

    monkeypatch.setattr(
        signoff_power_module,
        "_available_gls",
        lambda *args: (("smoke", "sv", "typ"), ("smoke", "cocotb", "typ")),
    )

    def fake_qualified(
        project_root: Path,
        values: object,
        *,
        test: str,
        backend: str,
        mode: str,
    ) -> signoff_power_module.ActivitySpec:
        del project_root, values
        calls.append(backend)
        if backend == "cocotb":
            raise ValueError("waveform missing or empty")
        return signoff_power_module.ActivitySpec(
            top="demo", pdk="sky130", test=test, backend=backend, mode=mode,
            report=tmp_path / "sv.json", wave=tmp_path / "sv.vcd",
        )

    monkeypatch.setattr(signoff_power_module, "_qualified_spec", fake_qualified)
    specs = signoff_power_module.discover_specs(
        "all",
        {
            "POWER_TEST_NAMES": "smoke",
            "POWER_GLS_BACKENDS": "all",
            "POWER_GLS_BACKEND": "cocotb",
            "POWER_TIMING_MODES": "typ",
        },
        tmp_path,
    )

    assert calls == ["cocotb", "sv"]
    assert len(specs) == 1
    assert specs[0].backend == "sv"
    assert specs[0].mode == "typ"


def test_gls_closure_requires_one_passing_backend_per_test_mode(tmp_path: Path) -> None:
    run = tmp_path / "runs/demo/dev"
    sim = pdk_run_layout(run, pdk="sky130", top="demo").post_syn_sim_dir
    sim.mkdir(parents=True)
    sv_wave = sim / "demo_tb_smoke_sv_tt.vcd"
    sv_wave.write_text("$enddefinitions $end\n", encoding="utf-8")

    common = {
        "stage": "post_syn",
        "top": "demo",
        "pdk": "sky130",
        "test_name": "smoke",
        "timing_mode": "typ",
        "scenario": "tt",
        "status": "pass",
        "timing_model": "icarus-path-delay-only",
        "interconnect_delays": "none",
        "annotation": {"requested_marker": True, "errors": [], "warnings": []},
    }
    (sim / "demo_post_syn_smoke_sv_tt.json").write_text(
        json.dumps({**common, "backend": "sv", "wave": str(sv_wave)}) + "\n",
        encoding="utf-8",
    )
    (sim / "demo_post_syn_smoke_cocotb_tt.json").write_text(
        json.dumps(
            {
                **common,
                "backend": "cocotb",
                "wave": str(sim / "missing_cocotb.fst"),
            }
        )
        + "\n",
        encoding="utf-8",
    )

    gls = collect_post_syn_gls("demo", run, "sky130")
    assert gls is not None
    assert gls["status"] == "pass"
    assert (gls["passed"], gls["failed"], gls["total"]) == (1, 0, 1)
    assert gls["by_backend"]["sv"]["status"] == "pass"
    assert gls["by_backend"]["cocotb"]["status"] == "fail"
    assert gls["scenario_records"][0]["backend"] == "sv"
    assert gls["failures"] == []
    assert len(gls["backend_failures"]) == 1


def test_activity_analysis_rejects_incoherent_corner_selection(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    spec = signoff_power_module.ActivitySpec(
        top="demo", pdk="sky130", test="smoke", backend="sv", mode="typ",
        report=tmp_path / "gls.json", wave=tmp_path / "wave.vcd",
    )
    spec.report.write_text("{}\n", encoding="utf-8")
    spec.wave.write_text("$enddefinitions $end\n", encoding="utf-8")
    liberties = {corner: tmp_path / f"{corner}.lib" for corner in ("ss", "tt", "ff")}
    for corner, liberty in liberties.items():
        liberty.write_text(f"library({corner}) {{}}\n", encoding="utf-8")
    monkeypatch.setattr(signoff_power_module, "_liberties", lambda values: liberties)
    monkeypatch.setattr(
        signoff_power_module, "_activity_vcd", lambda *args: (spec.wave, None, "direct-vcd")
    )
    monkeypatch.setattr(
        signoff_power_module, "_resolve_vcd_scope", lambda *args, **kwargs: ("tb/dut", ("tb/dut",))
    )

    with pytest.raises(ValueError, match="belongs to sign-off scenario 'tt'"):
        signoff_power_module.analyze_activity_spec(
            "power_analysis", tmp_path, {"SIGNOFF_CORNERS": "ss"}, spec
        )


def test_timing_summary_parser_accepts_opensta_wns_tns() -> None:
    assert _timing_values("wns max -0.125\ntns max -1.250\n") == {
        "wns": -0.125,
        "tns": -1.25,
    }

def test_signoff_execution_rejects_truncated_zero_exit_and_stale_reports(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    ctx = _context(tmp_path, analysis="power_analysis")
    ctx.report_dir.mkdir(parents=True)
    stale = ctx.report_dir / "power_summary.rpt"
    stale.write_text("stale\n", encoding="utf-8")

    def fake_run(command: object, *, cwd: Path, log: Path) -> int:
        del command, cwd
        log.parent.mkdir(parents=True, exist_ok=True)
        log.write_text("OpenSTA stopped without a Tcl error code\n", encoding="utf-8")
        return 0

    monkeypatch.setattr(signoff_sta_module, "_run_sta", fake_run)
    with pytest.raises(ValueError, match="completion marker"):
        signoff_sta_module._execute_script(
            tmp_path,
            {"STA": "sta"},
            analysis="power_analysis",
            ctx=ctx,
            script=tmp_path / "power_analysis.tcl",
            log=tmp_path / "power_analysis.log",
        )
    assert not stale.exists()


def test_signoff_render_appends_deterministic_completion_marker(tmp_path: Path) -> None:
    ctx = _context(tmp_path, analysis="fusion_analysis", mode="hold")
    script = signoff_sta_module._render("fusion_analysis", ctx)

    assert script.rstrip().endswith(
        "puts {FLEXSOC_SIGNOFF_COMPLETE analysis=fusion_analysis corner=tt "
        "mode=hold workload=smoke_sv_tt}"
    )


def test_pdk_first_layout_for_all_technology_artifacts(tmp_path: Path) -> None:
    layout = pdk_run_layout(tmp_path / "run", pdk="ihp-sg13g2", top="demo")

    assert layout.syn_dir == tmp_path / "run/syn/ihp-sg13g2"
    assert layout.pnr_dir == tmp_path / "run/impl/ihp-sg13g2"
    assert layout.signoff_sdc == tmp_path / "run/signoff/ihp-sg13g2/demo.sdc"
    assert layout.equivalence_dir == tmp_path / "run/signoff/ihp-sg13g2/equivalence/rtl_vs_syn"
    assert layout.sta_dir == tmp_path / "run/signoff/ihp-sg13g2/sta"
    assert layout.power_dir == tmp_path / "run/signoff/ihp-sg13g2/power"
    assert layout.fusion_dir == tmp_path / "run/signoff/ihp-sg13g2/fusion"
    assert layout.sdf_dir == tmp_path / "run/signoff/ihp-sg13g2/sdf"





def test_synthesis_uses_abc_constraints_not_sdc() -> None:
    makefile = (ROOT / "src/flexsoc/backend/Makefile").read_text(encoding="utf-8")
    synthesis = (ROOT / "src/flexsoc/backend/syn/syn.py").read_text(encoding="utf-8")

    assert "setup_syn:" not in makefile
    assert "python -m flexsoc.backend" not in makefile
    assert "compatibility Make shim" in makefile
    assert "read_sdc" not in synthesis
    assert "SIGNOFF_SDC_FILE" not in synthesis
    assert "abc.constr" in synthesis
    assert "-constr" in synthesis



def test_eqy_and_opensta_modules_are_separated() -> None:
    root = Path(__file__).resolve().parents[1] / "src/flexsoc/backend"
    signoff = (root / "signoff/sta.py").read_text(encoding="utf-8")
    eqy = (root / "syn/eqy.py").read_text(encoding="utf-8")

    assert "eqy-export" not in signoff
    assert "generate_equivalence_config" not in signoff
    assert "render_sta_tcl" not in eqy
    assert "render_power_analysis_tcl" not in eqy
    assert not (root / "power_analysis.py").exists()


def test_saved_ip_packages_use_pdk_first_technology_branches() -> None:
    root = Path(__file__).resolve().parents[1] / "hw/ips"
    technology_packages = []
    for package in sorted(path for path in root.iterdir() if path.is_dir()):
        if not any((package / stage).is_dir() for stage in ("syn", "impl", "signoff")):
            continue
        technology_packages.append(package.name)
        for stage in ("syn", "impl"):
            directory = package / stage
            if directory.is_dir():
                assert not any(path.is_file() for path in directory.iterdir()), (
                    package.name,
                    stage,
                )
        signoff = package / "signoff"
        if signoff.is_dir():
            assert not any(path.is_file() for path in signoff.iterdir()), package.name
            assert not (signoff / "equivalence").exists(), package.name
    assert {"cordic", "uart", "cache_wrapper", "fft_core", "gpio", "pwm"}.issubset(
        technology_packages
    )
    for top in ("cordic", "uart"):
        package = root / top
        assert (package / "syn/sky130").is_dir()
        implementation = package / "impl/sky130"
        if implementation.exists():
            assert (implementation / "config.mk").is_file()
            assert not (implementation / f"{top}.sdc").exists()
        assert (package / f"signoff/sky130/{top}.sdc").is_file()
        assert (package / "signoff/sky130/equivalence/rtl_vs_syn").is_dir()
        assert (package / "signoff/ihp-sg13g2/equivalence/rtl_vs_syn").is_dir()



def test_formal_scaffold_uses_explicit_multiclock_context(tmp_path: Path) -> None:
    from flexsoc.backend.dv.formal import generate_scaffold

    prove, cover = generate_scaffold("tri_stream_dsp", tmp_path, multiclock=True)
    prove_text = prove.read_text(encoding="utf-8")
    cover_text = cover.read_text(encoding="utf-8")
    assert "dsp_clk_i" in prove_text
    assert "fifo_rready" in prove_text
    assert "pipe_q1" not in prove_text
    assert "cfg_clk_i" in cover_text
    assert "rx_clk_i" in cover_text


def test_cordic_signoff_sdc_default_uses_lighter_io_budget(tmp_path: Path) -> None:
    from flexsoc.backend.signoff.sta import generate_signoff_sdc

    workspace = tmp_path / "workspace"
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "cordic",
        "RUN_ID": "dev",
        "TOP": "cordic",
        "PDK": "sky130",
        "N_CLOCKS": "1",
        "CLOCK_DOMAINS": "core:clk_i:rst_ni:10:low",
    }
    text = generate_signoff_sdc(tmp_path, values).read_text(encoding="utf-8")
    assert "create_clock -name core -period 20" in text
    assert "set_input_delay [expr 20 * 0.1]" in text
    assert "set_output_delay [expr 20 * 0.1]" in text

def test_signoff_sdc_defaults_every_domain_to_20ns_and_allows_override(tmp_path: Path) -> None:
    from flexsoc.backend.signoff.sta import generate_signoff_sdc

    values = {
        "WORKSPACE": str(tmp_path / "workspace"),
        "RUN_TOP": "multi",
        "RUN_ID": "dev",
        "TOP": "multi",
        "PDK": "sky130",
        "N_CLOCKS": "3",
        "CLOCK_DOMAINS": "cfg:cfg_clk_i:cfg_rst_ni:20:low,rx:rx_clk_i:rx_rst_ni:16:low,dsp:dsp_clk_i:dsp_rst_ni:30:low",
        "CLOCK_RELATIONSHIPS": "async:cfg:rx,async:cfg:dsp,async:rx:dsp",
    }
    text = generate_signoff_sdc(tmp_path, values).read_text(encoding="utf-8")
    assert text.count("-period 20") == 3
    values["SDC_CLOCK_PERIOD_NS"] = "25"
    text = generate_signoff_sdc(tmp_path, values).read_text(encoding="utf-8")
    assert text.count("-period 25") == 3


def test_setup_signoff_generates_five_families_without_activity_scripts(
    tmp_path: Path,
) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    (run / "syn/sky130").mkdir(parents=True)
    liberties = []
    for corner in ("ss", "tt", "ff"):
        path = tmp_path / f"demo__{corner}_view.lib"
        path.write_text("library(demo) {}\n", encoding="utf-8")
        liberties.append(path)
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "TOP": "demo",
        "PDK": "sky130",
        "LIBS": " ".join(str(path) for path in liberties),
    }

    paths = generate_families(tmp_path, values)

    assert {path.relative_to(run).as_posix() for path in paths} == {
        "signoff/sky130/sta/sta.tcl",
        "signoff/sky130/sdf/write_sdf.tcl",
        "signoff/sky130/power/estimate/power_estimate.tcl",
        "signoff/sky130/power/analysis/power_analysis.tcl",
        "signoff/sky130/fusion/fusion_analysis.tcl",
    }
    sdc = run / "signoff/sky130/demo.sdc"
    assert sdc.is_file()
    assert "create_clock -name core -period 20 [get_ports clk_i]" in sdc.read_text(encoding="utf-8")
    sta_template = run / "signoff/sky130/sta/sta.tcl"
    assert str(run / "syn/sky130/demo_synth.v") in sta_template.read_text(encoding="utf-8")
    assert not (run / "syn/sky130/demo_synth.v").exists()
    assert not (run / "constraints").exists()
    assert not (run / "signoff/sky130/power/activity/scripts").exists()


def test_common_header_and_runtime_validation_are_complete(tmp_path: Path) -> None:
    ctx = _context(tmp_path, analysis="sta", mode="setup")
    script = render_sta_tcl(ctx)

    for label in (
        "Analysis : sta",
        "Design   : demo",
        "Variant  : dev",
        "PDK      : sky130",
        "Stage    : post_syn",
        "Corner   : tt",
        "Mode     : setup",
        "Top      : demo",
        "Macro Liberty",
        "Report dir",
        "Limitations:",
    ):
        assert label in script
    assert "flexsoc_require_readable" in script
    assert "read_liberty $liberty" in script
    assert "read_verilog $netlist" in script
    assert "link_design $top" in script
    assert "read_sdc $sdc" in script
    assert "report_units" in script


def test_post_route_context_uses_pnr_netlist_spef_and_propagated_clocks(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    results = run / "impl/sky130/results/demo/base"
    results.mkdir(parents=True)
    (results / "6_final.v").write_text("module demo; endmodule\n", encoding="utf-8")
    (results / "6_final.spef").write_text("*SPEF \"IEEE 1481-1998\"\n", encoding="utf-8")
    (results / "6_final.sdc").write_text("create_clock -period 10 [get_ports clk_i]\n", encoding="utf-8")
    liberty = tmp_path / "demo__tt_view.lib"
    liberty.write_text("library(demo) {}\n", encoding="utf-8")
    paths = generate_families(
        tmp_path,
        {
            "WORKSPACE": str(workspace),
            "RUN_TOP": "demo",
            "RUN_ID": "dev",
            "TOP": "demo",
            "PDK": "sky130",
            "SIGNOFF_STAGE": "post_route",
            "LIBS": str(liberty),
            },
    )
    sta = next(path for path in paths if path.name == "sta.tcl").read_text(encoding="utf-8")
    assert str(results / "6_final.v") in sta
    assert str(results / "6_final.spef") in sta
    assert str(results / "6_final.sdc") in sta
    assert "set_propagated_clock" in sta
    assert "report_parasitic_annotation -report_unannotated" in sta
    assert "report_clock_latency -include_internal_latency" in sta
    assert "report_clock_skew -setup -include_internal_latency" in sta
    assert "report_clock_skew -hold -include_internal_latency" in sta
    assert 'clock_network=propagated' in sta
    assert 'interconnect=spef' in sta
    assert "Worst routed paths" in sta
    assert "Stage    : post_route" in sta
    assert all("/post_pnr/" in str(path) for path in paths)


def test_missing_configured_macro_liberty_is_an_error(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    (run / "syn/sky130").mkdir(parents=True)
    (run / "syn/sky130/demo_synth.v").write_text("module demo; endmodule\n", encoding="utf-8")
    liberty = tmp_path / "demo__tt_view.lib"
    liberty.write_text("library(demo) {}\n", encoding="utf-8")
    with pytest.raises(ValueError, match="missing macro Liberty"):
        generate_families(
            tmp_path,
            {
                "WORKSPACE": str(workspace),
                "RUN_TOP": "demo",
                "RUN_ID": "dev",
                "TOP": "demo",
                "PDK": "sky130",
                "LIBS": str(liberty),
                "MACRO_LIBS": str(tmp_path / "missing_macro.lib"),
                    },
        )



def test_metrics_read_unified_timing_and_power_reports(tmp_path: Path) -> None:
    run = tmp_path / "run"
    timing = run / "signoff/sky130/sta/ss/setup/timing.rpt"
    timing.parent.mkdir(parents=True)
    timing.write_text(
        "wns max -0.125\ntns max -1.250\n"
        "=== Violating paths ===\nslack (VIOLATED)\n"
        "=== Unconstrained paths ===\nStartpoint: floating\n",
        encoding="utf-8",
    )
    power = run / "signoff/sky130/power/estimate/ss/power.rpt"
    power.parent.mkdir(parents=True)
    power.write_text(
        "activity=0.1\nduty=0.5\nTotal 1.0 2.0 0.25 3.25\n",
        encoding="utf-8",
    )

    sta = collect_sta("demo", run, "sky130")
    assert sta is not None
    assert sta["ss"]["setup"]["wns"] == -0.125
    assert sta["ss"]["setup"]["tns"] == -1.25
    assert sta["ss"]["setup"]["reported_violating_paths"] == 1
    assert sta["ss"]["setup"]["reported_unconstrained_paths"] == 1
    assert sta["ss"]["setup"]["report"].endswith("timing.rpt")

    estimate = collect_power_estimate("demo", run, "sky130")
    assert estimate is not None
    assert estimate["activity"] == 0.1
    assert estimate["duty"] == 0.5
    assert estimate["corners"]["ss"]["dynamic_w"] == 3.0
    assert estimate["corners"]["ss"]["report"].endswith("power.rpt")

    routed_timing = run / "signoff/sky130/post_pnr/sta/tt/hold/timing.rpt"
    routed_timing.parent.mkdir(parents=True)
    routed_timing.write_text("wns min 0.075\ntns min 0.000\n", encoding="utf-8")
    routed_power = run / "signoff/sky130/post_pnr/power/estimate/tt/power.rpt"
    routed_power.parent.mkdir(parents=True)
    routed_power.write_text("activity=0.2\nduty=0.5\nTotal 2.0 1.0 0.1 3.1\n", encoding="utf-8")

    fusion = run / "signoff/sky130/post_pnr/fusion/summary.json"
    fusion.parent.mkdir(parents=True)
    fusion.write_text('{"status":"pass","passed":2,"total":2,"reports":[]}\n', encoding="utf-8")

    routed_sta = collect_sta("demo", run, "sky130", "post_route")
    routed_estimate = collect_power_estimate("demo", run, "sky130", "post_route")
    routed_fusion = collect_fusion_analysis("demo", run, "sky130", "post_route")
    assert routed_sta is not None and routed_sta["tt"]["hold"]["wns"] == 0.075
    assert routed_estimate is not None and routed_estimate["corners"]["tt"]["total_w"] == 3.1
    assert routed_fusion is not None and routed_fusion["status"] == "pass"
    assert "/post_pnr/" in routed_sta["tt"]["hold"]["report"]

    metrics = collect_metrics("demo", run, pdk="sky130")
    assert metrics["signoff"]["post_pnr"]["sta"]["clock_model"] == "propagated"
    assert metrics["signoff"]["post_pnr"]["sta"]["interconnect"] == "spef"
    assert metrics["signoff"]["post_pnr"]["fusion"]["status"] == "pass"
    assert "post_pnr_fusion" in metrics["closure"]["order"]

def test_power_summary_gets_explicit_dynamic_definition(tmp_path: Path) -> None:
    report = tmp_path / "power.rpt"
    report.write_text("Total 1.0 2.5 0.25 3.75\n", encoding="utf-8")
    _annotate_power_summary(tmp_path)
    text = report.read_text(encoding="utf-8")
    assert "dynamic_power_definition=internal_power+switching_power" in text
    assert "internal_power=1.0" in text
    assert "switching_power=2.5" in text
    assert "dynamic_power=3.5" in text
    assert "total_power=3.75" in text


def test_script_output_includes_context_and_keeps_logs_plain(tmp_path: Path) -> None:
    script = tmp_path / "sta.tcl"
    script.write_text("# comment\nset corner ss\nreport_checks\n", encoding="utf-8")
    details = {"analysis": "sta", "corner": "ss", "mode": "setup"}

    plain = io.StringIO()
    print_script(script, details=details, stream=plain, color=False, content=True)
    output = plain.getvalue()
    assert output.startswith(
        f"[script] {script.resolve()} · analysis=sta · corner=ss · mode=setup\n"
    )
    assert "\x1b" not in output

    colored = io.StringIO()
    print_script(script, details=details, stream=colored, color=True, content=True)
    assert "\x1b" in colored.getvalue()
    colored_plain = strip_ansi(colored.getvalue())
    assert "[script]" in colored_plain
    assert colored_plain.endswith("report_checks\n")


def test_signoff_selector_rejects_unknown_and_duplicate_values() -> None:
    assert _selection("ss tt", "", ("ss", "tt", "ff"), "corner") == ("ss", "tt")
    with pytest.raises(ValueError, match="unsupported corner"):
        _selection("ss wc", "", ("ss", "tt", "ff"), "corner")
    with pytest.raises(ValueError, match="duplicate corner"):
        _selection("ss ss", "", ("ss", "tt", "ff"), "corner")

def test_ci_toolchain_contract() -> None:
    """Keep the locked container and repository CI on one tool/ORFS contract."""

    lock = (ROOT / "src/flexsoc/backend/core/toolchain.lock").read_text(encoding="utf-8")
    deps = (ROOT / "src/flexsoc/backend/core/deps.sh").read_text(encoding="utf-8")
    dockerfile = (ROOT / "docker/ci/Dockerfile").read_text(encoding="utf-8")
    verify = (ROOT / "docker/scripts/verify.sh").read_text(encoding="utf-8")
    run_ci = (ROOT / "docker/scripts/run-ci.sh").read_text(encoding="utf-8")
    workflow = (ROOT / ".github/workflows/toolchain-image.yml").read_text(encoding="utf-8")
    assert "IVERILOG_VERSION=13.0" in lock and "IVERILOG_MIN_VERSION=13.0" in lock
    assert "iverilog -g2012 -ginterconnect -V" in deps
    assert "orfs-klayout.version" in dockerfile
    assert 'test "$required_klayout" = "$KLAYOUT_VERSION"' in dockerfile
    assert 'orfs_klayout_required=$(cat /opt/flexsoc/toolchain/.flexsoc/orfs-klayout.version)' in verify
    assert 'test "$orfs_klayout_required" = "$KLAYOUT_VERSION"' in verify
    assert 'make test E2E_ORS="$ORFS_ROOT/flow"' in run_ci
    assert "gh workflow run ci.yml" in workflow



def test_physical_signoff_metrics_collector(tmp_path: Path) -> None:
    run = tmp_path / "run"
    summary = run / "signoff" / "sky130" / "post_pnr" / "physical" / "summary.json"
    report = run / "impl" / "sky130" / "reports" / "sky130hd" / "demo" / "base" / "6_drc.lyrdb"
    report.parent.mkdir(parents=True)
    report.write_text("clean\n", encoding="utf-8")
    summary.parent.mkdir(parents=True)
    summary.write_text(json.dumps({
        "status": "pass",
        "checks": {"gds_drc": {"status": "pass", "violations": 0, "report": str(report)}},
    }), encoding="utf-8")
    data = collect_physical_signoff(run, "sky130")
    assert data is not None
    assert data["status"] == "pass"
    assert data["checks"]["gds_drc"]["report"].startswith("impl/sky130/")
    assert data["summary"] == "signoff/sky130/post_pnr/physical/summary.json"


def test_post_impl_signoff_flow_declares_physical_first() -> None:
    from flexsoc.backend.signoff import SignoffFlow

    source = inspect.getsource(SignoffFlow.flow)
    assert source.index("run_physical") < source.index("write_sdf")
    assert source.index("write_sdf") < source.index("run_sta")
    assert source.index("run_sta") < source.index("gls.flow")
    assert source.index("gls.flow") < source.index("run_power_estimate")
    assert source.index("run_power_estimate") < source.index("run_power_activity")
    assert source.index("run_power_activity") < source.index("run_fusion")


def test_tool_runner_executes_local_commands(tmp_path: Path) -> None:
    from flexsoc.backend.core import CommandRequest, ToolRunner

    log = tmp_path / "run.log"
    request = CommandRequest(
        (sys.executable, "-c", "print('ok')"), tmp_path, {}, log,
    )
    result = ToolRunner(project_root=tmp_path).run(request)

    assert result.returncode == 0
    assert log.read_text(encoding="utf-8").strip() == "ok"


def test_tool_runner_streams_line_callback_while_logging(tmp_path: Path) -> None:
    from flexsoc.backend.core import CommandRequest, ToolRunner

    seen: list[str] = []
    log = tmp_path / "stream.log"
    request = CommandRequest(
        (sys.executable, "-c", "print('stage 1_import', flush=True); print('stage 2_floorplan', flush=True)"),
        tmp_path,
        {},
        log,
        line_callback=seen.append,
    )
    result = ToolRunner(project_root=tmp_path).run(request)

    assert result.returncode == 0
    assert [line.strip() for line in seen] == ["stage 1_import", "stage 2_floorplan"]
    assert log.read_text(encoding="utf-8").splitlines() == ["stage 1_import", "stage 2_floorplan"]


def test_flow_summary_merges_physical_into_post_signoff() -> None:
    metrics = {
        "lint": {"status": "pass"},
        "cdc_rdc": {"status": "review"},
        "regression": {"status": "pass"},
        "formal": {"status": "pass"},
        "synthesis": {"errors": 0, "netlist": "demo.v"},
        "equivalence": {"status": "partial"},
        "sdf": {"status": "pass"},
        "sta": {"tt": {}},
        "power_estimate": {"corners": {}},
        "post_syn_gls": {"status": "pass"},
        "power_analysis": {"status": "pass"},
        "fusion_analysis": {"status": "pass"},
        "implementation": {"status": "pass"},
        "post_pnr": {
            "sdf": {"status": "pass"},
            "sta": {"tt": {}},
            "power_estimate": {"corners": {}},
            "gls": {"status": "pass"},
            "power_analysis": {"status": "pass"},
            "fusion_analysis": {"status": "pass"},
        },
        "physical_signoff": {"status": "review"},
    }
    flow = flow_summary(metrics)
    assert flow["order"][-1] == "post_implementation_signoff"
    assert "physical_signoff" not in flow["order"]
    assert flow["stages"]["post_implementation_signoff"] == "review"


def test_tool_runner_rejects_unknown_execution_target(tmp_path: Path) -> None:
    from flexsoc.backend.core import CommandRequest, ToolRunner

    request = CommandRequest((sys.executable, "-c", "pass"), tmp_path, {}, tmp_path / "run.log")
    with pytest.raises(ValueError, match="unknown execution target"):
        ToolRunner(project_root=tmp_path).run(request, on="missing")


def test_make_shim_forwards_command_line_overrides() -> None:
    makefile = (ROOT / "src/flexsoc/backend/Makefile").read_text(encoding="utf-8")

    assert "FLEXSOC_SET_ARGS" in makefile
    assert "--set $(key)=$($(key))" in makefile
    assert "export FLEXSOC_$(key)" not in makefile


def test_eqy_explicit_pdk_and_multiclock_contract(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    from flexsoc.backend.syn.eqy import EquivalenceFlow

    monkeypatch.delenv("FLEXSOC_PDK", raising=False)
    monkeypatch.delenv("N_CLOCKS", raising=False)
    flow = EquivalenceFlow()
    cfg = flow.config(
        top="tri_stream_dsp",
        filelists=(),
        netlist=tmp_path / "netlist.v",
        liberty=tmp_path / "library.lib",
        cell_models=(),
        clock_gate_model=tmp_path / "cg.v",
        engine="abc pdr", depth=20, sat_depth=20, output=tmp_path / "demo.eqy",
        pdk="sky130", multiclock=True,
        reset_domains=(("cfg_clk_i", "cfg_rst_ni", "low"), ("dsp_clk_i", "dsp_rst_ni", "low")),
    )
    assert cfg.pdk == "sky130"
    assert cfg.multiclock is True
    assert cfg.reset_normalize is False
    assert cfg.reset_domains[0][1] == "cfg_rst_ni"
    assert all(reset != "rst_ni" for _, reset, _ in cfg.reset_domains)


def test_eqy_pdr_engine_is_independent_from_legacy_engine(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    from flexsoc.backend.syn.eqy import EquivalenceFlow

    monkeypatch.delenv("EQY_PDR_ENGINE", raising=False)
    flow = EquivalenceFlow()
    cfg = flow.config(
        top="demo", filelists=(), netlist=tmp_path / "netlist.v",
        liberty=tmp_path / "library.lib", cell_models=(),
        clock_gate_model=tmp_path / "cg.v", engine="sat", depth=20, sat_depth=20,
        output=tmp_path / "demo.eqy", pdk="sky130", multiclock=False,
    )
    assert cfg.engine == "sat"
    assert cfg.pdr_engine == "abc pdr"

    overridden = flow.config(
        top="demo", filelists=(), netlist=tmp_path / "netlist.v",
        liberty=tmp_path / "library.lib", cell_models=(),
        clock_gate_model=tmp_path / "cg.v", engine="sat", depth=20, sat_depth=20,
        output=tmp_path / "demo.eqy", pdk="sky130", multiclock=True,
        pdr_engine="abc pdr",
    )
    assert overridden.pdr_engine == "abc pdr"


def test_router_setup_pnr_leaves_platform_physical_views_to_orfs(tmp_path: Path) -> None:
    import flexsoc.api as api_module

    project = tmp_path / "project"
    project.mkdir()
    client = api_module.FlexSoC(project_root=project, workdir=tmp_path / "work")
    values = {
        **api_module.DEFAULT_SETTINGS,
        "TOP": "demo", "RUN_TOP": "demo", "RUN_ID": "dev",
        "PDK": "sky130", "ORS_TECH": "sky130hd",
    }
    router = api_module._TargetRouter(client, values)
    router.paths.syn.mkdir(parents=True, exist_ok=True)
    (router.paths.syn / "demo_synth.v").write_text(
        "module demo; endmodule\n", encoding="utf-8"
    )
    router.paths.sdc.parent.mkdir(parents=True, exist_ok=True)
    router.paths.sdc.write_text("current_design demo\n", encoding="utf-8")

    config = router._setup_pnr()
    text = config.read_text(encoding="utf-8")
    assert "CDL_FILE" not in text
    assert "KLAYOUT" not in text
    assert "SYNTH_NETLIST_FILES" in text
    assert "SDC_FILE" in text


def test_orfs_config_does_not_override_platform_cdl(tmp_path: Path) -> None:
    from flexsoc.backend.impl.impl import render_config

    text = render_config(
        "demo", "sky130hd", tmp_path / "demo.v", tmp_path / "demo.sdc"
    )
    assert "CDL_FILE" not in text
    assert "Platform-owned physical views" in text


def test_orfs_make_argv_uses_native_flow_directory_and_work_home(tmp_path: Path) -> None:
    from flexsoc.backend.impl.impl import orfs_make_argv

    flow = tmp_path / "OpenROAD-flow-scripts" / "flow"
    makefile = flow / "Makefile"
    config = tmp_path / "run" / "config.mk"
    work = tmp_path / "run"
    argv = orfs_make_argv(
        makefile=makefile, config=config, workdir=work, targets=("drc", "lvs"),
    )
    assert argv == (
        "make", "-C", str(flow.resolve()), "--no-print-dir",
        f"DESIGN_CONFIG={config.resolve()}", f"WORK_HOME={work.resolve()}",
        "drc", "lvs",
    )
    assert not any(item.startswith("--file=") for item in argv)


def test_orfs_klayout_requirement_matches_selected_checkout(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    from flexsoc.backend.core.toolchain import (
        orfs_klayout_requirement,
        validate_orfs_klayout,
    )

    root = tmp_path / "OpenROAD-flow-scripts"
    flow = root / "flow"
    etc = root / "etc"
    flow.mkdir(parents=True)
    etc.mkdir(parents=True)
    makefile = flow / "Makefile"
    makefile.write_text("all:\n\t@true\n", encoding="utf-8")
    (etc / "DependencyInstaller.sh").write_text(
        "klayoutVersion=0.30.7\n", encoding="utf-8"
    )
    monkeypatch.setattr(
        doctor_module.subprocess,
        "run",
        lambda *args, **kwargs: _completed(tuple(args[0]), stdout="KLayout 0.30.8\n"),
    )
    assert orfs_klayout_requirement(makefile) == "0.30.7"
    assert validate_orfs_klayout(
        makefile, {"KLAYOUT_CMD": "/tools/klayout"}
    ) == ("0.30.8", "0.30.7")


def test_orfs_klayout_preflight_rejects_old_binary(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    from flexsoc.backend.core.toolchain import validate_orfs_klayout

    root = tmp_path / "OpenROAD-flow-scripts"
    flow = root / "flow"
    etc = root / "etc"
    flow.mkdir(parents=True)
    etc.mkdir(parents=True)
    makefile = flow / "Makefile"
    makefile.write_text("all:\n\t@true\n", encoding="utf-8")
    (etc / "DependencyInstaller.sh").write_text(
        "klayoutVersion=0.30.7\n", encoding="utf-8"
    )
    monkeypatch.setattr(
        doctor_module.subprocess,
        "run",
        lambda *args, **kwargs: _completed(tuple(args[0]), stdout="KLayout 0.28.16\n"),
    )
    with pytest.raises(
        ValueError, match=r"KLayout 0\.28\.16 incompatible.*need >= 0\.30\.7"
    ):
        validate_orfs_klayout(makefile, {"KLAYOUT_CMD": "/tools/klayout"})


def test_toolchain_metadata_tracks_locked_klayout_version() -> None:
    from flexsoc.backend.core.toolchain import toolchain_metadata

    metadata = toolchain_metadata(ROOT)
    assert metadata["expected"]["klayout"]["locked_version"] == "0.30.7"


def test_physical_signoff_reaches_summary_after_native_orfs_run(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    import flexsoc.backend.signoff as signoff_module

    class Runner:
        def __init__(self) -> None:
            self.requests = []

        def run(self, request, *, on="local"):
            self.requests.append(request)
            return type("Result", (), {"returncode": 0})()

    root = tmp_path / "OpenROAD-flow-scripts"
    flow = root / "flow"
    etc = root / "etc"
    flow.mkdir(parents=True)
    etc.mkdir(parents=True)
    makefile = flow / "Makefile"
    makefile.write_text("all:\n\t@true\n", encoding="utf-8")
    (etc / "DependencyInstaller.sh").write_text(
        "klayoutVersion=0.30.7\n", encoding="utf-8"
    )
    config = tmp_path / "work" / "config.mk"
    config.parent.mkdir(parents=True)
    config.write_text("export PLATFORM = sky130hd\n", encoding="utf-8")
    output = tmp_path / "summary.json"
    log = tmp_path / "physical.log"
    runner = Runner()
    monkeypatch.setattr(
        signoff_module, "orfs_environment",
        lambda: {"KLAYOUT_CMD": "/tools/klayout", "OPENROAD_EXE": "/tools/openroad"},
    )
    monkeypatch.setattr(
        signoff_module, "validate_orfs_klayout",
        lambda makefile, env: ("0.30.7", "0.30.7"),
    )
    monkeypatch.setattr(signoff_module, "_run_antenna", lambda **kwargs: None)
    monkeypatch.setattr(
        signoff_module, "collect",
        lambda **kwargs: {
            "status": "review",
            "checks": {"ir_drop": {"status": "unsupported"}},
        },
    )

    rc = signoff_module._run_physical(
        makefile=makefile, config=config, workdir=config.parent, top="demo",
        output=output, log=log, runner=runner,
    )
    assert rc == 0
    assert output.is_file()
    assert json.loads(output.read_text(encoding="utf-8"))["orfs_returncode"] == 0
    argv = runner.requests[0].argv
    assert argv[:3] == ("make", "-C", str(flow.resolve()))
    assert f"WORK_HOME={config.parent.resolve()}" in argv
    assert argv[-2:] == ("drc", "lvs")



def test_eqy_explicit_sky130_never_reads_raw_primitive_models(tmp_path: Path) -> None:
    from flexsoc.backend.syn.eqy import EquivalenceConfig, _gate_model_reads

    model = tmp_path / "primitives.v"
    liberty = tmp_path / "library.lib"
    netlist = tmp_path / "netlist.v"
    cfg = EquivalenceConfig(
        top="demo",
        filelists=(),
        netlist=netlist,
        liberty=liberty,
        cell_models=(model,),
        engine="sat",
        depth=20,
        sat_depth=20,
        pdk="sky130",
        sky130_clock_gate_model=tmp_path / "sky130_clock_gates_formal.v",
        output=tmp_path / "demo.eqy",
    )
    reads = _gate_model_reads(cfg, liberty=liberty, netlist=netlist, cell_models=(model,))
    assert not any(str(model) in line for line in reads)
    assert f"read_liberty -ignore_miss_func {liberty}" in reads


def test_physical_antenna_explicit_count_is_machine_readable(tmp_path: Path) -> None:
    from flexsoc.backend.signoff import _antenna

    log = tmp_path / "antenna.log"
    log.write_text("FLEXSOC_ANTENNA_VIOLATIONS=0\n", encoding="utf-8")
    result = _antenna(log)
    assert result["status"] == "pass"
    assert result["net_violations"] == 0

def test_post_impl_signoff_maps_lifecycle_stage_to_post_pnr_gls(tmp_path: Path) -> None:
    from flexsoc.backend.signoff import Signoff, SignoffStage

    signoff = Signoff(tmp_path, {"TOP": "demo", "PDK": "sky130"})

    pre = signoff.pre
    post = signoff.post
    assert pre.stage is SignoffStage.PRE_IMPL
    assert pre.gls.stage == "post_syn"
    assert post.stage is SignoffStage.POST_IMPL
    assert post.stage.value == "post_route"
    assert post.gls.stage == "post_pnr"

