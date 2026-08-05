"""Public FlexSoC Python API and ``fx`` CLI contract tests."""

from __future__ import annotations

import json
import subprocess
import sys
from pathlib import Path

import pytest

import flexsoc.cli as cli_module
import flexsoc.doctor as doctor_module
from flexsoc import (
    FlexSoC,
    FlexSoCCommand,
    FlexSoCConfig,
    FlexSoCResult,
    FlexSoCTarget,
)
from flexsoc.api import (
    AUTO_SETUP_TARGETS,
    DEFAULT_SETTINGS,
    NATIVE_TARGETS,
    POWER_ANALYSIS_TARGETS,
    TARGETS,
    TECHNOLOGY_TARGETS,
    main as api_main,
)
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
    assert sky130["CONSTRAINTSDIR"] == ihp["CONSTRAINTSDIR"]
    for key in (
        "SYNDIR",
        "EQUIVDIR",
        "SIGNOFF_STA_DIR",
        "SIGNOFF_POWER_DIR",
        "SIGNOFF_SDF_DIR",
        "POST_SYN_SIMDIR",
        "METADIR",
        "COMMAND_LOGDIR",
    ):
        assert sky130[key] != ihp[key]
        assert "sky130" in Path(sky130[key]).parts
        assert "ihp-sg13g2" in Path(ihp[key]).parts


def test_commands_route_make_native_and_power_targets(tmp_path: Path) -> None:
    fx = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work", TOP="base")

    lint, ast = fx.override(top="cordic").commands(
        "lint-width", "slang_ast", RUN_ID="r1", UNUSED="ignored"
    )
    assert [lint.target, ast.target] == ["lint_width", "slang_ast"]
    assert lint.argv[:4] == ("make", "-f", str(ROOT / "src/flexsoc/backend/Makefile"), "lint_width")
    assert "TOP=cordic" in lint.argv and "RUN_ID=r1" in lint.argv
    assert not any(arg.startswith("UNUSED=") for arg in lint.argv)

    for name, (action, stage) in NATIVE_TARGETS.items():
        command = fx.command(name)
        assert command.argv[:4] == (
            sys.executable, "-m", "flexsoc.backend.post_sim", "--action"
        )
        assert action in command.argv and stage in command.argv

    for name, action in POWER_ANALYSIS_TARGETS.items():
        command = fx.command(name)
        assert command.argv[:4] == (
            sys.executable, "-m", "flexsoc.backend.power_analysis", "--action"
        )
        assert action in command.argv


def test_ip_save_forwards_package_name_and_library_root(tmp_path: Path) -> None:
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
    assert any(arg.startswith("SIGNOFF_STA_DIR=") for arg in command.argv)
    assert any(arg.startswith("SIGNOFF_SDF_DIR=") for arg in command.argv)
    assert any(arg.startswith("SIGNOFF_POWER_DIR=") for arg in command.argv)


def test_auto_setup_expansion_is_ordered_deduplicated_and_optional(
    tmp_path: Path,
) -> None:
    fx = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work")

    assert AUTO_SETUP_TARGETS["setup_syn"] == ("setup_sdc",)
    assert AUTO_SETUP_TARGETS["syn"] == ("setup_syn",)
    assert "regression" not in AUTO_SETUP_TARGETS
    assert AUTO_SETUP_TARGETS["setup_pnr"] == ("setup_sdc",)
    assert AUTO_SETUP_TARGETS["pnr"] == ("setup_pnr",)
    assert AUTO_SETUP_TARGETS["setup_formal_prove"] == ("setup_formal",)
    assert AUTO_SETUP_TARGETS["formal_bmc"] == ("setup_formal_prove",)
    assert [command.target for command in fx.commands("syn")] == [
        "setup_sdc", "setup_syn", "syn"
    ]
    assert [command.target for command in fx.commands("regression")] == ["regression"]
    assert [command.target for command in fx.commands("sdf", "sta", "power_estimate")] == [
        "setup_sdc", "setup_signoff", "sdf", "sta", "power_estimate"
    ]
    assert [
        command.target
        for command in fx.commands("setup_sdc", "setup_syn", "syn")
    ] == ["setup_sdc", "setup_syn", "syn"]
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


def test_run_capture_returns_results_and_writes_log(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    def fake_run(argv: tuple[str, ...], **kwargs: object) -> subprocess.CompletedProcess[str]:
        assert kwargs["cwd"] == tmp_path.resolve()
        assert kwargs["capture_output"] is True
        return _completed(argv, stdout="generated\n")

    monkeypatch.setattr(subprocess, "run", fake_run)
    result, = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work").run(
        "hjson", capture=True, TOP="demo", RUN_ID="api"
    )

    assert isinstance(result, FlexSoCResult)
    assert result.ok and result.stdout == "generated\n"
    assert result.log_path is not None
    assert result.log_path.read_text(encoding="utf-8") == "generated\n"


def test_gate_and_power_logs_are_scoped_by_gls_case(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: Path,
) -> None:
    pdk = _fake_pdk(tmp_path / "pdk")
    monkeypatch.setattr(
        subprocess,
        "run",
        lambda argv, **kwargs: _completed(argv, stdout="quiet output\n"),
    )
    fx = FlexSoC(
        project_root=tmp_path,
        workdir=tmp_path / "work",
        PDK="sky130",
        PDK_ROOT=pdk,
        TOP="demo",
    )

    smoke, = fx.run(
        "sim_post_syn",
        TEST_NAME="smoke",
        GLS_BACKEND="sv",
        TIMING_MODE="typ",
        auto_setup=False,
    )
    corners, = fx.run(
        "sim_post_syn",
        TEST_NAME="corners",
        GLS_BACKEND="sv",
        TIMING_MODE="typ",
        auto_setup=False,
    )
    power, = fx.run(
        "power_analysis",
        POWER_TEST_NAME="smoke",
        POWER_GLS_BACKEND="sv",
        POWER_TIMING_MODE="typ",
    )
    power_all, = fx.run(
        "power_analysis_all",
        POWER_TEST_NAMES="all",
        POWER_GLS_BACKENDS="all",
        POWER_TIMING_MODES="all",
    )

    assert smoke.log_path is not None and smoke.log_path.name == "sim_post_syn_smoke_sv_typ.log"
    assert corners.log_path is not None and corners.log_path.name == (
        "sim_post_syn_corners_sv_typ.log"
    )
    assert power.log_path is not None and power.log_path.name == (
        "power_analysis_smoke_sv_typ.log"
    )
    assert power_all.log_path is not None and power_all.log_path.name == (
        "power_analysis_all_all_all_all.log"
    )


def test_run_check_and_nonchecking_failure_modes(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    monkeypatch.setattr(
        subprocess,
        "run",
        lambda argv, **kwargs: _completed(argv, returncode=7),
    )
    fx = FlexSoC(project_root=tmp_path)

    with pytest.raises(RuntimeError, match="exit code 7"):
        fx.run("hjson")
    result, = fx.run("hjson", check=False)
    assert isinstance(result, FlexSoCResult)
    assert result.returncode == 7 and not result.ok


def test_live_run_prints_only_log_block_and_keeps_plain_log(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
    tmp_path: Path,
) -> None:
    class FakeProcess:
        stdout = iter(("generated line\n", "\033[38;5;208m[script]\033[0m file.tcl\n"))

        def wait(self) -> int:
            return 0

    monkeypatch.setattr(subprocess, "Popen", lambda *args, **kwargs: FakeProcess())
    result, = FlexSoC(project_root=tmp_path, workdir=tmp_path / "work").run(
        "hjson", live=True, TOP="demo"
    )

    output = capsys.readouterr().out
    assert output.startswith("[log] ")
    assert "generated line" in output and "[script]" in output
    assert "→ hjson" not in output and "✓ hjson" not in output
    assert result.ok and result.log_path is not None
    assert result.log_path.read_text(encoding="utf-8") == (
        "generated line\n[script] file.tcl\n"
    )


def test_technology_execution_requires_an_activated_pdk(tmp_path: Path) -> None:
    fx = FlexSoC(project_root=tmp_path, PDK="sky130", PDK_ROOT=tmp_path / "missing")
    with pytest.raises(RuntimeError, match="fx pdk fetch"):
        fx.run(next(iter(TECHNOLOGY_TARGETS)))


def test_api_main_delegates_to_cli(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr(cli_module, "app", lambda argv=None: 23)
    assert api_main(["commands"]) == 23


# ---------------------------------------------------------------------------
# Command-line interface
# ---------------------------------------------------------------------------


def test_cli_help_and_commands_json(capsys: pytest.CaptureFixture[str], tmp_path: Path) -> None:
    assert app(["--help"]) == 0
    help_text = capsys.readouterr().out
    assert "fx settings" in help_text and "fx commands" in help_text

    assert app(["commands", "--json", "--project-root", str(tmp_path)]) == 0
    catalog = json.loads(capsys.readouterr().out)
    assert [item["name"] for item in catalog] == list(TARGETS)
    assert all({"name", "group", "description", "params"} == set(item) for item in catalog)


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
    assert [line.split()[3] for line in lines] == ["setup_sdc", "setup_syn", "syn"]

    assert app(["syn", "--no-setup", "--dry-run", *root_args]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert len(lines) == 1 and " syn " in lines[0]

    assert app(["regression", "--dry-run", *root_args]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert len(lines) == 1 and " regression " in lines[0]

    assert app(["regression", "--no-setup", "--dry-run", *root_args]) == 0
    lines = capsys.readouterr().out.strip().splitlines()
    assert len(lines) == 1 and " regression " in lines[0]


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
