"""Minimal checks for the FlexSoC API and fx CLI."""

from __future__ import annotations

import io
import json
import os
import subprocess
import sys
from pathlib import Path

from flexsoc import FlexSoC, FlexSoCConfig
from flexsoc.api import NATIVE_TARGETS
from flexsoc.backend.eqy_debug import _replace_gate_netlist, synthesis_boundary_diagnosis
from flexsoc.backend.hjson_gen import main as hjson_main
from flexsoc.backend.metrics import eqy_solver_stats
from flexsoc.backend.output import print_script, strip_ansi
from flexsoc.backend.setup_cocotb import (
    cocotb_py_text,
    cocotb_reg_driver_py_text,
    render_reg_driver_py,
)
from flexsoc.backend.setup_model import _regmap_tests_text
from flexsoc.backend.setup_sdc import render_clock_config_sdc
from flexsoc.backend.setup_signoff import NetlistPort, main as signoff_main, render_formal_protocol_view
from flexsoc.backend.setup_tb import render_tlul_utils
from flexsoc.backend.setup_syn import config_from_args as synthesis_config_from_args, parse_args as parse_synthesis_args
from flexsoc.cli import app
from flexsoc.clocking import clock_config


ROOT = Path(__file__).resolve().parents[1]
BACKEND_MAKEFILE = ROOT / "src" / "flexsoc" / "backend" / "Makefile"


def _makefile_targets() -> set[str]:
    """Return every target declared in PHONY_TARGETS."""

    targets: set[str] = set()
    for line in BACKEND_MAKEFILE.read_text(encoding="utf-8").splitlines():
        if line.startswith("PHONY_TARGETS +="):
            targets.update(line.split("+=", 1)[1].split())
    return targets


def test_api_catalog_matches_makefile_targets() -> None:
    """The API covers public Make targets plus intentional Python-native ones."""

    api = set(FlexSoC(project_root=ROOT).target_names())
    make = _makefile_targets() - {"_formal_scaffold"}
    api_only = {"deps-bootstrap", "deps-doctor", "deps-versions", "deps-env"} | (set(NATIVE_TARGETS) - make)
    assert make <= api
    assert api - make == api_only


def test_backend_exposes_one_clock_count_neutral_pipeline() -> None:
    """Public phases stay unified and legacy multi-clock routing is gone."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    assert "setup_multiclock" not in text
    assert "CLOCK_MODE" not in text
    assert "MULTICLOCK" not in text
    assert not any(name.endswith("_multi") for name in _makefile_targets())
    assert {
        "hjson", "reg", "rtl_stub", "top_from_core", "setup_model", "tests_gen",
        "setup_tb", "setup_cocotb", "setup_sdc", "setup_syn", "setup_formal",
        "setup_eqy", "setup_signoff", "sta", "sdf", "power_estimate",
    } <= _makefile_targets()


def test_settings_clear_stale_relationships_when_clock_domains_change(capsys, monkeypatch, tmp_path: Path) -> None:
    """Switching an existing project back to one clock cannot retain N-clock edges."""

    monkeypatch.chdir(tmp_path)
    multi = "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low"
    relationships = "async:cfg:rx,async:cfg:dsp,async:rx:dsp"
    assert app(["settings", "N_CLOCKS=3", f"CLOCK_DOMAINS={multi}", f"CLOCK_RELATIONSHIPS={relationships}"]) == 0
    capsys.readouterr()
    assert app(["settings", "N_CLOCKS=1", "CLOCK_DOMAINS=core:clk_i:rst_ni:10:low"]) == 0
    values = json.loads((tmp_path / ".flexsoc" / "settings.json").read_text())
    assert values["N_CLOCKS"] == "1"
    assert values["CLOCK_RELATIONSHIPS"] == ""
    assert "CLOCK_MODE" not in values


def test_make_pipeline_dry_runs_with_canonical_clock_settings(tmp_path: Path) -> None:
    """Every downstream phase resolves through the same public N-clock targets."""

    domains = "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low"
    command = [
        "make", "-n", "-f", str(BACKEND_MAKEFILE),
        "setup_model", "tests_gen", "setup_tb", "setup_cocotb", "setup_sdc",
        "setup_syn", "setup_formal", "setup_eqy", "setup_signoff", "sta", "sdf", "power_estimate",
        "TOP=demo", "RUN_TOP=demo", "RUN_ID=dev", f"WORKSPACE={tmp_path}",
        "N_CLOCKS=3", f"CLOCK_DOMAINS={domains}", "CLOCK_RELATIONSHIPS=async:cfg:rx",
    ]
    result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True, check=False)
    assert result.returncode == 0, result.stderr
    output = result.stdout + result.stderr
    assert "setup_multiclock" not in output
    assert "_multi" not in output


def test_api_builds_ordered_commands_and_overrides(tmp_path: Path) -> None:
    """Settings, overrides, dashed names, and command order stay explicit."""

    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"), top="base")
    first, second = fx.override(top="cordic").commands("lint-width", "yosys_vgen", RUN_ID="r1")

    assert [first.target, second.target] == ["lint_width", "yosys-vgen"]
    assert first.cwd == tmp_path.resolve()
    assert "TOP=cordic" in first.argv
    assert "RUN_ID=r1" in first.argv
    assert f"WORKSPACE={tmp_path / 'ws'}" in first.argv

    gate = fx.command("sim_post_syn", TOP="cordic")
    legacy_alias = fx.command("sim_syn", TOP="cordic")
    assert gate.argv[1:4] == ("-m", "flexsoc.backend.post_sim", "--action")
    assert legacy_alias.argv[1:4] == ("-m", "flexsoc.backend.post_sim", "--action")
    assert "post_syn" in gate.argv
    assert gate.values["WAVE_FORMAT"] == "fst"



def test_slang_targets_forward_explicit_analysis_roots(tmp_path: Path) -> None:
    """Slang analysis overrides must reach Make instead of falling back to REPO_ROOT."""

    rtl = tmp_path / "run" / "rtl"
    top_file = rtl / "demo.sv"
    search = tmp_path / "shared"
    command = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws")).command(
        "slang_ast", SLANG_ROOT=rtl, SLANG_TOP_FILE=top_file, SLANG_SEARCH_ARGS=f"--search-root {search}"
    )
    joined = " ".join(command.argv)
    assert f"SLANG_ROOT={rtl}" in joined
    assert f"SLANG_TOP_FILE={top_file}" in joined
    assert f"SLANG_SEARCH_ARGS=--search-root {search}" in joined


def test_eqy_solver_stats_reports_the_strategy_that_closes_partitions(tmp_path: Path) -> None:
    log = tmp_path / "eqy.log"
    log.write_text(
        "Running strategy 'sat' on 'demo.out.0'..\n"
        "Could not prove equivalence of partition 'demo.out.0' using strategy 'sat'\n"
        "Running strategy 'pdr' on 'demo.out.0'..\n"
        "Proved equivalence of partition 'demo.out.0' using strategy 'pdr'\n"
        "Running strategy 'pdr' on 'demo.out.1'..\n"
        "Proved equivalence of partition 'demo.out.1' using strategy 'pdr'\n",
        encoding="utf-8",
    )
    assert eqy_solver_stats(log) == {
        "sat": {"attempts": 1, "proved": 0, "unproved": 1, "errors": 0},
        "pdr": {"attempts": 2, "proved": 2, "unproved": 0, "errors": 0},
    }


def test_rtl_make_commands_do_not_leak_pdk_libs_into_verilator(tmp_path: Path) -> None:
    """Technology libraries are scoped to technology-dependent Make targets."""

    pdk = tmp_path / ".flexsoc" / "pdks" / "sky130"
    (pdk / "lib").mkdir(parents=True)
    (pdk / "verilog").mkdir(parents=True)
    (pdk / "lib" / "sky130_fd_sc_hd__tt_025C_1v80.lib").write_text("library(test) {}\n")
    (pdk / "verilog" / "sky130_fd_sc_hd.v").write_text("module sky130_fd_sc_hd__buf_1; endmodule\n")

    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"), TOP="demo")
    rtl = fx.command("compile_sv")
    syn = fx.command("syn")

    assert not any(arg.startswith("LIBS=") or arg.startswith("LIB_SYN=") for arg in rtl.argv)
    assert any(arg.startswith("LIB_SYN=") for arg in syn.argv)
    assert "CLOCK_MODE" not in rtl.env
    assert rtl.env["N_CLOCKS"] == "1"



def test_clock_config_is_count_agnostic_and_relationships_are_explicit(tmp_path: Path) -> None:
    """N-clock routing has no dual-clock special case and assumes no relationships."""

    domains = ",".join(f"c{i}:clk{i}_i:rst{i}_ni:{10-i}:low" for i in range(4))
    cfg = clock_config({"N_CLOCKS": 4, "CLOCK_DOMAINS": domains})
    assert cfg.n_clocks == 4 and cfg.multiclock and cfg.relationships == ()

    fx = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"),
        TOP="demo", N_CLOCKS=4, CLOCK_DOMAINS=domains,
    )
    tb = fx.command("setup_tb")
    sdc = fx.command("setup_sdc")
    assert tb.argv[3] == "setup_tb"
    assert sdc.argv[3] == "setup_sdc"
    assert "CLOCK_MODE" not in tb.values
    assert tb.env["CLOCK_DOMAINS"] == domains




def test_nclock_generators_use_clock_config_and_create_outputs(monkeypatch, tmp_path: Path) -> None:
    """Starter metadata and cocotb timing come from one canonical clock model."""

    domains = "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low"
    monkeypatch.setenv("N_CLOCKS", "3")
    monkeypatch.setenv("CLOCK_DOMAINS", domains)
    assert hjson_main(["--force", "--top", "demo", "--interface", "tlul", "--output-dir", str(tmp_path / "data")]) == 0
    assert {path.name for path in (tmp_path / "data").glob("*.hjson")} == {"demo_cfg.hjson", "demo_dsp.hjson"}

    clocks = clock_config({"N_CLOCKS": 3, "CLOCK_DOMAINS": domains})
    test_text = cocotb_py_text("demo", clocks)
    driver_text = cocotb_reg_driver_py_text("demo", clocks)
    assert all(domain.signal in test_text for domain in clocks.domains)
    assert all(domain.reset in driver_text for domain in clocks.domains)
    assert 'int(polarity == "high")' in driver_text
    assert 'int(polarity == "low")' in driver_text
    compile(test_text, "<demo_tb.py>", "exec")
    compile(driver_text, "<reg_driver.py>", "exec")


def test_auto_toggle_uses_tlul_byte_masks_and_protocol_opcodes(tmp_path: Path) -> None:
    """CSR field masks must not be truncated into invalid TL-UL byte enables."""

    model_dir = tmp_path / "model"
    tests_dir = tmp_path / "tests"
    model_dir.mkdir()
    uart_model = ROOT / "hw" / "ips" / "uart" / "dv" / "functional" / "model"
    for name in ("uart_model.py", "uart_regmap.py"):
        (model_dir / name).write_bytes((uart_model / name).read_bytes())
    helper = model_dir / "uart_regmap_tests.py"
    helper.write_text(_regmap_tests_text("uart"), encoding="utf-8")

    env = os.environ.copy()
    env["PYTHONPATH"] = str(model_dir)
    result = subprocess.run(
        [sys.executable, str(helper), "--tests-dir", str(tests_dir), "--test", "auto_toggle"],
        text=True,
        capture_output=True,
        env=env,
        check=False,
    )
    assert result.returncode == 0, result.stderr
    rows = [
        line for line in (tests_dir / "auto_toggle" / "data_in.vec").read_text().splitlines()
        if line and not line.startswith("#")
    ]
    assert rows[0] == "0 @write clk_i.CTRL 0xb48000f7 0x0000000f"

    cocotb_driver = render_reg_driver_py()
    assert "0 if mask == 0xF else 1  # PutFullData / PutPartialData" in cocotb_driver
    assert "TL-UL write mask is zero" in cocotb_driver
    compile(cocotb_driver, "<reg_driver.py>", "exec")

    sv_driver = render_tlul_utils()
    assert "(mask == '1) ? tlul_pkg::PutFullData : tlul_pkg::PutPartialData" in sv_driver
    assert '$fatal(1, "[%0t] TLUL WRITE ERROR' in sv_driver
    assert '$fatal(1, "[%0t] TLUL READ ERROR' in sv_driver


def test_synthesis_uses_fastest_configured_clock(monkeypatch, tmp_path: Path) -> None:
    """ABC timing follows ClockConfig rather than a stale Make default."""

    monkeypatch.setenv("N_CLOCKS", "3")
    monkeypatch.setenv(
        "CLOCK_DOMAINS",
        "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low",
    )
    args = parse_synthesis_args([
        "--top", "demo", "--topdir", str(tmp_path), "--target", "asic",
        "--liberty", str(tmp_path / "cells.lib"), "--clk", "20",
    ])
    assert synthesis_config_from_args(args).clk_period_ns == 6


def test_clock_config_sdc_emits_only_declared_relationships() -> None:
    cfg = clock_config({
        "N_CLOCKS": 3,
        "CLOCK_DOMAINS": "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:16:low",
        "CLOCK_RELATIONSHIPS": "async:cfg:rx,generated:rx:dsp:2",
    })
    text = render_clock_config_sdc("demo", cfg)
    assert "create_clock -name cfg -period 10 [get_ports cfg_clk_i]" in text
    assert "create_clock -name rx -period 8 [get_ports rx_clk_i]" in text
    assert "create_generated_clock -name dsp -source [get_ports rx_clk_i] -divide_by 2 [get_ports dsp_clk_i]" in text
    assert "set_clock_groups -asynchronous -group [get_clocks cfg] -group [get_clocks rx]" in text
    assert "cfg] -group [get_clocks dsp" not in text


def test_clock_config_validates_count_and_relationship_endpoints() -> None:
    """Clock count and relationship names fail early instead of creating wrong constraints."""

    domains = "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low"
    try:
        clock_config({"N_CLOCKS": 3, "CLOCK_DOMAINS": domains})
    except ValueError as exc:
        assert "defines 2" in str(exc)
    else:
        raise AssertionError("N_CLOCKS mismatch was accepted")

    try:
        clock_config({"N_CLOCKS": 2, "CLOCK_DOMAINS": domains, "CLOCK_RELATIONSHIPS": "async:cfg:dsp"})
    except ValueError as exc:
        assert "endpoints" in str(exc)
    else:
        raise AssertionError("unknown relationship endpoint was accepted")


def test_api_dry_run_does_not_spawn_processes(monkeypatch, tmp_path: Path) -> None:
    """Dry-run returns previews only."""

    def fail(*args, **kwargs):  # noqa: ANN001, ANN002, ANN003
        raise AssertionError("subprocess.run should not be called")

    monkeypatch.setattr(subprocess, "run", fail)
    result = FlexSoC(project_root=tmp_path).run("setup", "reg", dry_run=True, TOP="demo")

    assert [item.target for item in result] == ["setup", "reg"]
    assert all(item.cwd == tmp_path.resolve() for item in result)


def test_cli_help_settings_commands_and_dry_run(capsys, monkeypatch, tmp_path: Path) -> None:
    """fx keeps Typer help, settings, catalog, and dry-runs minimal."""

    monkeypatch.chdir(tmp_path)

    assert app(["--help"]) == 0
    help_out = capsys.readouterr().out
    assert "IP development" in help_out
    assert "System-on-chip building" in help_out
    assert "--install-completion" in help_out

    assert app(["settings", "TOP=cordic", "RUN_ID=e2e"]) == 0
    assert json.loads((tmp_path / ".flexsoc" / "settings.json").read_text())["TOP"] == "cordic"
    capsys.readouterr()

    assert app(["commands", "--json"]) == 0
    names = {item["name"] for item in json.loads(capsys.readouterr().out)}
    assert {"lint_latch", "lint_width", "top_from_core", "ip_load", "soc_run", "clean_all"} <= names

    assert app(["pdk", "list", "--json"]) == 0
    pdk_rows = json.loads(capsys.readouterr().out)
    assert {"sky130", "gf180mcu", "ihp-sg13g2", "asap7", "nangate45"} <= {row["name"] for row in pdk_rows}

    assert app(["lint_width", "syn", "--dry-run", "--set", "LINT_PART=all"]) == 0
    out = capsys.readouterr().out
    assert " lint_width " in out
    assert " syn " in out
    assert "TOP=cordic" in out
    assert "LINT_PART=all" in out


def test_technology_targets_are_isolated_by_pdk(tmp_path: Path) -> None:
    """PDK names appear locally under each technology-dependent flow branch."""

    for name in ("sky130", "ihp-sg13g2"):
        pdk = tmp_path / ".flexsoc" / "pdks" / name
        (pdk / "lib").mkdir(parents=True)
        (pdk / "verilog").mkdir(parents=True)
        (pdk / "lib" / f"{name}_tt.lib").write_text("library(test) {}\n")
        (pdk / "verilog" / f"{name}.v").write_text("module cell; endmodule\n")

    fx = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"),
        TOP="demo",
        RUN_TOP="demo",
        RUN_ID="r1",
        PDK="sky130",
    )
    rtl = fx.command("regression")
    sky_syn = fx.command("syn")
    ihp_syn = fx.command("syn", PDK="ihp-sg13g2")
    sky_eq = fx.command("eqy")

    shared = tmp_path / "ws" / "runs" / "demo" / "r1"
    assert not any("SYNDIR=" in arg for arg in rtl.argv)
    assert f"SYNDIR={shared / 'syn' / 'sky130'}" in sky_syn.argv
    assert f"EQUIVDIR={shared / 'signoff' / 'equivalence' / 'sky130' / 'rtl_vs_syn'}" in sky_eq.argv
    assert any(
        arg.startswith("PRIM=") and str(tmp_path / ".flexsoc" / "pdks" / "sky130" / "verilog" / "sky130.v") in arg
        for arg in sky_eq.argv
    )
    assert f"SYNDIR={shared / 'syn' / 'ihp-sg13g2'}" in ihp_syn.argv
    assert ihp_syn.values["PDK_ROOT"].endswith("/.flexsoc/pdks/ihp-sg13g2")


def test_one_shot_pdk_switch_does_not_reuse_stale_root(tmp_path: Path) -> None:
    """PDK override without PDK_ROOT resolves the new managed installation."""

    sky = tmp_path / ".flexsoc" / "pdks" / "sky130"
    ihp = tmp_path / ".flexsoc" / "pdks" / "ihp-sg13g2"
    for root in (sky, ihp):
        (root / "lib").mkdir(parents=True)
        (root / "verilog").mkdir(parents=True)
        (root / "lib" / "tt.lib").write_text("library(test) {}\n")
        (root / "verilog" / "cells.v").write_text("module cell; endmodule\n")

    fx = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"),
        PDK="sky130",
        PDK_ROOT=str(sky),
    )
    command = fx.command("syn", PDK="ihp-sg13g2")
    assert command.values["PDK"] == "ihp-sg13g2"
    assert command.values["PDK_ROOT"] == str(ihp.resolve())


def test_equivalence_generator_belongs_to_setup_signoff() -> None:
    """The Make surface routes EQY generation through the sign-off backend."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    block = text.split("setup_eqy:", 1)[1].split("\neqy:", 1)[0]
    assert "flexsoc.backend.setup_signoff eqy" in block
    assert "flexsoc.backend.setup_formal eqy" not in text


def test_eqy_formal_view_recognizes_primary_tlul_response() -> None:
    """The canonical top-level tl_o receives protocol-aware EQY normalization."""

    ports = (
        NetlistPort("input", "clk_i"),
        NetlistPort("input", "rst_ni"),
        NetlistPort("input", "tl_i", "[108:0]"),
        NetlistPort("output", "tl_o", "[65:0]"),
    )
    view = render_formal_protocol_view("cordic", ports)
    assert "wire [65:0] tl_o__raw;" in view
    assert "assign tl_o[65] = tl_o__raw[65];" in view
    assert "assign tl_o[47:16] = (tl_o__raw[65] && !tl_o__raw[1])" in view


def test_eqy_checkpoint_probe_preserves_protocol_wrapper(tmp_path: Path) -> None:
    """Synthesis diagnostics replace the netlist, not the formal TL-UL view."""

    checkpoint = tmp_path / "cordic_generic.il"
    checkpoint.write_text("checkpoint\n", encoding="utf-8")
    source = """[gate]
read_verilog -formal -sv formal_pdk.v
read_verilog -formal -sv cordic_synth.v
rename cordic cordic__eqy_impl
read_verilog -formal -sv cordic_eqy_view.sv

[script]
prep -top cordic
"""
    rewritten = _replace_gate_netlist(source, checkpoint)
    assert "cordic_synth.v" not in rewritten
    assert f"read_rtlil {checkpoint.resolve()}" in rewritten
    assert "rename cordic cordic__eqy_impl" in rewritten
    assert "read_verilog -formal -sv cordic_eqy_view.sv" in rewritten
    assert rewritten.index(f"read_rtlil {checkpoint.resolve()}") < rewritten.index("rename cordic")


def test_eqy_checkpoint_diagnosis_keeps_timeouts_inconclusive() -> None:
    """A solver timeout must not be reported as a proven synthesis mismatch."""

    assert synthesis_boundary_diagnosis({
        "generic": {"status": "TIMEOUT"},
        "dffmap": {"status": "FAIL"},
        "abc": {"status": "FAIL"},
        "clean": {"status": "FAIL"},
    }) == "generic_inconclusive"
    assert synthesis_boundary_diagnosis({
        "generic": {"status": "PASS"},
        "dffmap": {"status": "FAIL"},
        "abc": {"status": "FAIL"},
        "clean": {"status": "FAIL"},
    }) == "dffmap_fail"


def test_eqy_parallelizes_partitions_with_configurable_jobs(tmp_path: Path) -> None:
    """Independent EQY partitions run concurrently without hiding the knob."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    block = text.split("\neqy:", 1)[1].split("\n\n", 1)[0]
    assert "EQY_JOBS ?= 4" in text
    assert '"$(EQY)" -j "$(EQY_JOBS)" -f' in block
    command = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws")).command(
        "eqy", EQY_JOBS=8, EQY_JOIN_OUTPUTS=0, EQY_QUICK_TIMEOUT=3,
        EQY_STRATEGY_ORDER="pdr,smt",
    )
    assert "EQY_JOBS=8" in command.argv
    assert "EQY_JOIN_OUTPUTS=0" in command.argv
    assert "EQY_QUICK_TIMEOUT=3" in command.argv
    assert "EQY_STRATEGY_ORDER=pdr,smt" in command.argv


def test_generated_scripts_use_common_plain_and_colored_rendering(capsys, monkeypatch, tmp_path: Path) -> None:
    """Script output is readable on terminals and remains ANSI-free in logs."""

    script = tmp_path / "sta.tcl"
    script.write_text("set corner ss\nreport_checks\n", encoding="utf-8")

    plain = io.StringIO()
    print_script(script, stream=plain, color=False)
    assert plain.getvalue() == f"[script] {script.resolve()}\nset corner ss\nreport_checks\n"

    colored = io.StringIO()
    print_script(script, stream=colored, color=True)
    assert "\x1b[" in colored.getvalue()
    assert strip_ansi(colored.getvalue()).startswith(f"[script] {script.resolve()}\n")

    monkeypatch.setenv("FLEXSOC_COLOR", "never")
    assert signoff_main([
        "analysis", "--top", "demo",
        "--sta-dir", str(tmp_path / "sta"),
        "--power-dir", str(tmp_path / "power"),
        "--sdf-dir", str(tmp_path / "sdf"),
    ]) == 0
    output = capsys.readouterr().out
    assert output.count("[script]") == 4
    assert "=== Static timing analysis ===" in output
    assert "=== Estimated power analysis ===" in output
    assert "=== Write SDF ===" in output
    assert "\x1b[" not in output


def test_live_command_logs_strip_terminal_escapes(monkeypatch, tmp_path: Path) -> None:
    """Live terminal color must never leak into persisted command logs."""

    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"))
    command = fx.command("setup")
    command = type(command)(
        command.target,
        (sys.executable, "-c", 'print("\x1b[31mred\x1b[0m")'),
        command.cwd,
        command.env,
        command.values,
    )
    monkeypatch.setattr(sys.stdout, "isatty", lambda: True)
    log = tmp_path / "live.log"
    result = fx._run_live(command, log)
    assert result.returncode == 0
    assert log.read_text(encoding="utf-8") == "red\n"


def test_pdk_scoped_paths_keep_flow_before_technology(tmp_path: Path) -> None:
    """Technology-dependent targets share one logical run and split only at local PDK leaves."""

    for name in ("sky130", "ihp-sg13g2"):
        root = tmp_path / ".flexsoc" / "pdks" / name
        (root / "lib").mkdir(parents=True)
        (root / "verilog").mkdir(parents=True)
        (root / "lib" / "tt.lib").write_text("library(test) {}\n")
        (root / "verilog" / "cells.v").write_text("module cell; endmodule\n")

    fx = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"),
        TOP="demo",
        RUN_TOP="demo",
        RUN_ID="r1",
        PDK="sky130",
    )
    shared = tmp_path / "ws" / "runs" / "demo" / "r1"
    for pdk in ("sky130", "ihp-sg13g2"):
        values = fx.command("eqy", PDK=pdk).values
        assert values["RUN_ROOT"] == str(shared)
        assert values["SYNDIR"] == str(shared / "syn" / pdk)
        assert values["EQUIVDIR"] == str(shared / "signoff" / "equivalence" / pdk / "rtl_vs_syn")
        assert values["SIGNOFF_STA_DIR"] == str(shared / "signoff" / "sta" / pdk)
        assert values["SIGNOFF_POWER_DIR"] == str(shared / "signoff" / "power" / pdk)
        assert values["SIGNOFF_SDF_DIR"] == str(shared / "signoff" / "sdf" / pdk)
        assert values["ORSDIR"] == str(shared / "pnr_openroad" / pdk)
        assert values["POST_SYN_SIMDIR"] == str(shared / "dv" / "functional" / "sim" / "post_syn" / pdk)
        assert values["POST_LAYOUT_SIMDIR"] == str(shared / "dv" / "functional" / "sim" / "post_pnr" / pdk)
        assert values["METADIR"] == str(shared / "meta" / pdk)
        assert "/tech/" not in "\n".join(values.values())
