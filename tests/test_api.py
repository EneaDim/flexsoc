"""Minimal checks for the FlexSoC API and fx CLI."""

from __future__ import annotations

import io
import json
import os
import subprocess
import sys
from pathlib import Path

import pytest

from flexsoc import FlexSoC, FlexSoCConfig
from flexsoc.api import NATIVE_TARGETS, POWER_ANALYSIS_TARGETS
from flexsoc.backend.eqy_debug import _replace_gate_netlist, synthesis_boundary_diagnosis
from flexsoc.backend.hjson_gen import main as hjson_main
from flexsoc.backend.metrics import collect_metrics, collect_post_syn_gls, eqy_solver_stats, show_metrics
from flexsoc.backend.power_analysis import (
    ActivitySpec,
    _activity_count,
    _activity_vcd,
    discover_specs,
    render_power_activity_tcl,
)
from flexsoc.backend.output import print_script, strip_ansi
from flexsoc.backend.post_sim import (
    GateSimPaths,
    _normalize_cocotb_wave,
    cocotb_command,
    compile_command,
    resolve_paths,
    run_command,
    run_environment,
    sdf_annotation_summary,
)
from flexsoc.backend.setup_cocotb import (
    CocotbConfig,
    cocotb_makefile_text,
    cocotb_py_text,
    cocotb_reg_driver_py_text,
    cocotb_sv_text,
    render_makefile,
    render_python_test,
    render_reg_driver_py,
    render_tlul_wrapper,
)
from flexsoc.backend.setup_model import _regmap_tests_text, _tests_text
from flexsoc.backend.setup_sdc import render_clock_config_sdc
from flexsoc.backend.setup_signoff import (
    EquivalenceConfig,
    NetlistPort,
    _gate_model_reads,
    liberty_corner,
    main as signoff_main,
    render_formal_protocol_view,
)
from flexsoc.backend.setup_tb import render_testbench, render_tlul_interface
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
    api_only = (set(NATIVE_TARGETS) | set(POWER_ANALYSIS_TARGETS)) - make
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
    assert "async def _response_sample_phase(clk):" in cocotb_driver
    assert cocotb_driver.count("await _response_sample_phase(clk)") == 2
    assert cocotb_driver.index("await _response_sample_phase(clk)") < cocotb_driver.index(
        'checking write response addr=0x{addr:08x}'
    )
    assert cocotb_driver.rindex("await _response_sample_phase(clk)") < cocotb_driver.index(
        'reading response data addr=0x{addr:08x}'
    )
    compile(cocotb_driver, "<reg_driver.py>", "exec")

    sv_driver = render_tlul_interface()
    assert "(mask == 4'hf) ? FLEXSOC_TL_PUT_FULL : FLEXSOC_TL_PUT_PARTIAL" in sv_driver
    assert '$fatal(1, "[%0t] TLUL WRITE ERROR' in sv_driver
    assert '$fatal(1, "[%0t] TLUL READ ERROR' in sv_driver


def test_generated_tlul_sv_driver_runs_vectors_without_verilator_classes(tmp_path: Path) -> None:
    """The SV GLS path uses the same generated vectors without class support."""

    sig = {
        "parameters": [],
        "localparams": [],
        "ports_in": [("clk_i", 1), ("rst_ni", 1), ("tl_i", "tlul_pkg::tl_h2d_t")],
        "ports_out": [("tl_o", "tlul_pkg::tl_d2h_t")],
        "clks": ["clk_i"],
        "rsts": ["rst_ni"],
    }
    body = render_testbench("demo", 10, tmp_path, tmp_path, "tlul", "iverilog", "sv", sig)
    assert "tlul_utils" not in body
    assert "tlul_if tl_if" in body
    assert "tl_if.init();" in body
    assert body.index("tl_if.init();") < body.index("initial reset pulse cycles")
    assert "parameter int INITIAL_RESET_CYCLES = 5;" in body
    assert "rst_ni = 1'b1;" in body
    assert "rst_ni = 1'b0;" in body
    assert body.index("rst_ni = 1'b1;") < body.index("rst_ni = 1'b0;")
    assert "initial reset pulse cycles" in body
    assert "repeat (INITIAL_RESET_CYCLES) @(posedge clk_i);" in body
    assert body.count("@(negedge clk_i); #1;") >= 2
    assert "run_reg_config(cfg_path);" in body
    assert "run_vectors(data_in_path, data_out_path);" in body
    assert "tl_if.tlul_write" not in body  # calls live in the included reg sequence



def test_generated_tlul_gls_wrappers_are_package_free(tmp_path: Path) -> None:
    """Gate wrappers must not require RTL packages unsupported by Icarus."""

    rtl = tmp_path / "rtl"
    rtl.mkdir()
    (rtl / "demo.sv").write_text(
        "module demo(input logic clk_i, input logic rst_ni, "
        "input tlul_pkg::tl_h2d_t tl_i, output tlul_pkg::tl_d2h_t tl_o); endmodule\n",
        encoding="utf-8",
    )
    wrapper = render_tlul_wrapper(CocotbConfig(
        top="demo", interface="tlul", output=tmp_path / "cocotb", rtl_dir=rtl
    ))
    interface = render_tlul_interface()
    for source in (wrapper, interface):
        assert "tlul_pkg::" not in source
        assert "top_pkg::" not in source
        assert "prim_mubi_pkg::" not in source
        assert "flexsoc_tlul_cmd_intg" in source
        assert "flexsoc_tlul_data_intg" in source
    assert "logic [108:0] tl_i" in wrapper
    assert "assign tl_o_d_data   = tl_o[47:16]" in wrapper
    assert "logic [108:0] h2d" in interface
    assert "d2h[47:16]" in interface



def test_cocotb_single_clock_initializes_bus_before_common_reset() -> None:
    """Every cocotb test begins from initialized inputs and a safe reset edge."""

    text = render_python_test("demo")
    assert "reset_cycles = max(1" in text
    assert text.index("await init_register_bus") < text.index("await apply_reset")
    assert "from cocotb.triggers import FallingEdge, RisingEdge, Timer" in text
    assert "await FallingEdge(dut.clk_i)" in text
    assert "dut.rst_ni.value = 1" in text
    assert "dut.rst_ni.value = 0" in text
    assert text.index("dut.rst_ni.value = 1") < text.index("dut.rst_ni.value = 0")
    assert "initial reset cycles=%d" in text


def test_scaffold_transactions_preserve_reset_state_valid_low_check() -> None:
    """Starter smoke checks reset-cleared payload while the valid output is low."""

    text = _tests_text("demo")
    assert "inputs = {name: value for name in INPUTS}" in text
    assert 'name: (1 if name.lower().endswith("valid_i") else value)' not in text


def test_cocotb_wave_is_normalized_to_requested_e2e_path(tmp_path: Path) -> None:
    """Adopt cocotb's build-local dump when its plusarg is ignored."""

    paths = _gate_sim_paths(tmp_path / "wave", sdf=False, cocotb=True)
    build = paths.stage_dir / "cocotb_build"
    build.mkdir(parents=True, exist_ok=True)
    actual = build / "demo_tb.fst"
    actual.write_bytes(b"FST")
    assert _normalize_cocotb_wave(paths, {"WAVE_FORMAT": "fst"}) == paths.wave
    assert paths.wave.read_bytes() == b"FST"
    assert not actual.exists()

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
    assert "output wire [1:0] tl_o__flexsoc_eqy_handshake" in view
    assert "output wire [31:0] tl_o__flexsoc_eqy_d_data" in view
    assert "assign tl_o__flexsoc_eqy_handshake = {tl_o__raw[65], tl_o__raw[0]};" in view
    assert "assign tl_o__flexsoc_eqy_d_data = (tl_o__raw[65] && (tl_o__raw[64:62] == 3'h1) && !tl_o__raw[1])" in view
    assert "output wire [65:0] tl_o" not in view
    assert "assign tl_o = {" not in view


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


def test_eqy_reset_diagnostic_replaces_generated_normalization() -> None:
    """Diagnostic reset replay replaces, rather than duplicates, the normal block."""

    from flexsoc.backend.eqy_debug import _inject_reset_initialization

    source = """[script]
prep -top demo -flatten
async2sync
# FlexSoC EQY reset normalization begin
uniquify
sim -clock clk_i -resetn rst_ni -rstlen 2 -n 2 -w
# FlexSoC EQY reset normalization end
"""
    rewritten = _inject_reset_initialization(
        source, clock="clk_i", reset="rst_ni", reset_active="low", reset_cycles=4
    )
    assert rewritten.count("FlexSoC EQY reset normalization begin") == 1
    assert "-rstlen 2 -n 2" not in rewritten
    assert "-rstlen 4 -n 4" in rewritten


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


def test_eqy_command_isolates_ambient_strategy_overrides(tmp_path: Path, monkeypatch) -> None:
    """Only explicit project/command EQY settings may change the proof portfolio."""

    monkeypatch.setenv("EQY_STRATEGY_ORDER", "pdr")
    client = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"))
    default = client.command(
        "eqy", N_CLOCKS=1, CLOCK_DOMAINS="core:clk_i:rst_ni:10:low"
    )
    assert "EQY_STRATEGY_ORDER" not in default.env

    explicit = client.command(
        "eqy",
        N_CLOCKS=1,
        CLOCK_DOMAINS="core:clk_i:rst_ni:10:low",
        EQY_STRATEGY_ORDER="pdr,smt",
    )
    assert explicit.env["EQY_STRATEGY_ORDER"] == "pdr,smt"


def test_eqy_parallelizes_partitions_with_configurable_jobs(tmp_path: Path) -> None:
    """Independent EQY partitions run concurrently without hiding the knob."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    block = text.split("\neqy:", 1)[1].split("\n\n", 1)[0]
    assert "EQY_JOBS ?= 4" in text
    assert "EQY_ENGINE ?= abc pdr\n" in text
    assert "abc pdr -rfi" not in text
    assert '"$(EQY)" -j "$(EQY_JOBS)" -f' in block
    command = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws")).command(
        "eqy", EQY_JOBS=8, EQY_JOIN_OUTPUTS=0, EQY_QUICK_TIMEOUT=3,
        EQY_STRATEGY_ORDER="pdr,smt", EQY_RESET_NORMALIZE=1, EQY_RESET_CYCLES=3,
    )
    assert "EQY_JOBS=8" in command.argv
    assert "EQY_JOIN_OUTPUTS=0" in command.argv
    assert "EQY_QUICK_TIMEOUT=3" in command.argv
    assert "EQY_STRATEGY_ORDER=pdr,smt" in command.argv
    assert "EQY_RESET_NORMALIZE=1" in command.argv
    assert "EQY_RESET_CYCLES=3" in command.argv


def test_eqy_tlul_witnesses_partition_protocol_fields(tmp_path: Path, monkeypatch) -> None:
    """TL-UL outputs use bounded protocol witnesses and post-reset initialization."""

    from flexsoc.backend.setup_signoff import EquivalenceConfig, generate_equivalence_config

    rtl_f = tmp_path / "rtl.f"
    netlist = tmp_path / "demo_synth.v"
    liberty = tmp_path / "cells.lib"
    clock_gate = tmp_path / "clock_gates.v"
    config = tmp_path / "demo.eqy"
    rtl_f.write_text("demo.sv\n", encoding="utf-8")
    netlist.write_text(
        "module demo(clk_i, rst_ni, tl_i, tl_o);\n"
        "input clk_i;\ninput rst_ni;\ninput [108:0] tl_i;\noutput [65:0] tl_o;\n"
        "assign tl_o = '0;\nendmodule\n",
        encoding="utf-8",
    )
    liberty.write_text("library(test) {}\n", encoding="utf-8")
    monkeypatch.setenv("FLEXSOC_PDK", "ihp-sg13g2")
    generate_equivalence_config(EquivalenceConfig(
        top="demo", filelists=(rtl_f,), netlist=netlist, liberty=liberty,
        cell_models=(), sky130_clock_gate_model=clock_gate, engine="abc pdr",
        depth=2, sat_depth=5, output=config, use_sat=True, use_pdr=True,
        reset_normalize=True, reset_cycles=2,
        reset_domains=(("clk_i", "rst_ni", "low"),),
    ))
    text = config.read_text(encoding="utf-8")
    assert "gold-match tl_o\n" not in text
    assert "gold-match tl_o__flexsoc_eqy_handshake" in text
    assert "gold-match tl_o__flexsoc_eqy_a_ready" not in text
    assert "gold-match tl_o__flexsoc_eqy_d_valid" not in text
    assert "gold-match tl_o__flexsoc_eqy_d_ctrl" in text
    assert "gold-match tl_o__flexsoc_eqy_d_data" in text
    assert "gold-match tl_o__flexsoc_eqy_d_meta" in text
    assert "join tl_o__flexsoc_eqy_handshake" in text
    assert "join tl_o__flexsoc_eqy_d_data" in text
    assert "join tl_o\n" not in text
    formal_view = (tmp_path / "demo_eqy_view.sv").read_text(encoding="utf-8")
    assert "output wire [65:0] tl_o" not in formal_view
    assert "wire [65:0] tl_o__raw;" in formal_view
    assert "assign tl_o__flexsoc_eqy_handshake = {tl_o__raw[65], tl_o__raw[0]};" in formal_view
    assert "assign tl_o = {" not in formal_view
    assert "sim -clock clk_i -resetn rst_ni -rstlen 2 -n 2 -w" in text


def test_eqy_single_clock_prefers_pdr_before_inductive_smt(tmp_path: Path) -> None:
    """A failed SMT induction must not prevent PDR from closing reachable-state equivalence."""

    from flexsoc.backend.setup_signoff import EquivalenceConfig, render_eqy

    rtl_f = tmp_path / "rtl.f"
    netlist = tmp_path / "demo_synth.v"
    liberty = tmp_path / "cells.lib"
    clock_gate = tmp_path / "clock_gates.v"
    rtl_f.write_text("demo.sv\n", encoding="utf-8")
    netlist.write_text(
        "module demo(input clk_i, input rst_ni, output data_o);\n"
        "assign data_o = clk_i;\n"
        "endmodule\n",
        encoding="utf-8",
    )
    liberty.write_text("library(test) {}\n", encoding="utf-8")
    clock_gate.write_text("// unused\n", encoding="utf-8")
    text = render_eqy(EquivalenceConfig(
        top="demo", filelists=(rtl_f,), netlist=netlist, liberty=liberty,
        cell_models=(), sky130_clock_gate_model=clock_gate, engine="abc pdr",
        depth=2, sat_depth=5, output=tmp_path / "demo.eqy",
        use_sat=True, use_pdr=True,
    ))
    assert text.index("[strategy sat]") < text.index("[strategy pdr]")
    assert text.index("[strategy pdr]") < text.index("[strategy smt]")


def test_generated_scripts_use_common_plain_and_colored_rendering(capsys, monkeypatch, tmp_path: Path) -> None:
    """Script output is readable on terminals and remains ANSI-free in logs."""

    script = tmp_path / "sta.tcl"
    script.write_text("set corner ss\nreport_checks\n", encoding="utf-8")

    plain = io.StringIO()
    print_script(script, stream=plain, color=False)
    assert plain.getvalue() == f"[script] {script.resolve()}\n"

    live_plain = io.StringIO()
    print_script(script, stream=live_plain, color=False, content=True)
    assert live_plain.getvalue() == f"[script] {script.resolve()}\nset corner ss\nreport_checks\n"

    colored = io.StringIO()
    print_script(script, stream=colored, color=True, content=True)
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
    assert "=== Static timing analysis ===" not in output
    assert "=== Estimated power analysis ===" not in output
    assert "=== Write SDF ===" not in output
    assert "\x1b[" not in output

    monkeypatch.setenv("FLEXSOC_LIVE", "1")
    assert signoff_main([
        "analysis", "--top", "demo",
        "--sta-dir", str(tmp_path / "live_sta"),
        "--power-dir", str(tmp_path / "live_power"),
        "--sdf-dir", str(tmp_path / "live_sdf"),
    ]) == 0
    live_output = capsys.readouterr().out
    assert "=== Static timing analysis ===" in live_output
    assert "=== Estimated power analysis ===" in live_output
    assert "=== Write SDF ===" in live_output


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
    assert command.env["FLEXSOC_LIVE"] == "0"

def test_ihp_signoff_maps_native_corner_names() -> None:
    """IHP slow/typ/fast Liberty names map onto the public ss/tt/ff modes."""

    assert liberty_corner(Path("sg13g2_stdcell_slow_1p35V_125C.lib")) == "ss"
    assert liberty_corner(Path("sg13g2_stdcell_typ_1p20V_25C.lib")) == "tt"
    assert liberty_corner(Path("sg13g2_stdcell_fast_1p32V_m40C.lib")) == "ff"
    assert liberty_corner(Path("nom_slow_1p08V_125C.lib")) == "ss"
    assert liberty_corner(Path("nom_typ_1p20V_25C.lib")) == "tt"
    assert liberty_corner(Path("nom_fast_1p32V_m40C.lib")) == "ff"


def test_ihp_eqy_uses_discovered_liberty_not_aggregate_verilog(
    monkeypatch, tmp_path: Path
) -> None:
    """Yosys must not parse IHP conditional specify blocks during EQY."""

    monkeypatch.setenv("FLEXSOC_PDK", "ihp-sg13g2")
    liberty = (
        tmp_path
        / "ihp-sg13g2"
        / "libs.ref"
        / "sg13g2_stdcell"
        / "lib"
        / "sg13g2_stdcell_typ_1p20V_25C.lib"
    )
    model = (
        tmp_path
        / "ihp-sg13g2"
        / "libs.ref"
        / "sg13g2_stdcell"
        / "verilog"
        / "sg13g2_stdcell.v"
    )
    netlist = tmp_path / "demo_synth.v"
    filelist = tmp_path / "demo.f"
    clock_gate = tmp_path / "unused_clock_gate.v"
    output = tmp_path / "demo.eqy"
    for path in (liberty, model):
        path.parent.mkdir(parents=True, exist_ok=True)
    liberty.write_text("library(sg13g2) {}\n", encoding="utf-8")
    model.write_text(
        "specify if ((A == 1'b1)) (A => Y) = 0; endspecify\n",
        encoding="utf-8",
    )
    netlist.write_text(
        "module demo(input clk_i, output data_o); "
        "assign data_o = clk_i; endmodule\n",
        encoding="utf-8",
    )
    filelist.write_text("demo.sv\n", encoding="utf-8")
    clock_gate.write_text("// unused for IHP\n", encoding="utf-8")
    cfg = EquivalenceConfig(
        top="demo",
        filelists=(filelist,),
        netlist=netlist,
        liberty=liberty,
        cell_models=(model,),
        sky130_clock_gate_model=clock_gate,
        engine="abc pdr",
        depth=2,
        sat_depth=2,
        output=output,
    )
    reads = _gate_model_reads(
        cfg, liberty=liberty, netlist=netlist, cell_models=(model,)
    )
    assert reads[0] == f"read_liberty -ignore_miss_func {liberty}"
    assert not any(str(model) in line for line in reads)
    assert reads[-1] == f"read_verilog -formal -sv {netlist}"


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



def _gate_sim_paths(tmp_path: Path, *, sdf: bool = False, cocotb: bool = False) -> GateSimPaths:
    """Create a minimal resolved GLS tree for command-generation tests."""

    run = tmp_path / "runs" / "demo" / "dev"
    stage = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
    tb_dir = run / "dv" / "functional" / "tb" / ("cocotb" if cocotb else "sv")
    tb_dir.mkdir(parents=True)
    tb = tb_dir / "demo_tb.sv"
    tb.write_text("module demo_tb; endmodule\n", encoding="utf-8")
    if not cocotb:
        (tb_dir / "tlul_if.sv").write_text("interface tlul_if; endinterface\n", encoding="utf-8")
    if cocotb:
        (tb_dir / "Makefile").write_text("# generated\n", encoding="utf-8")
    netlist = run / "syn" / "sky130" / "demo_synth.v"
    netlist.parent.mkdir(parents=True)
    netlist.write_text("module demo; endmodule\n", encoding="utf-8")
    sdf_path = run / "signoff" / "sdf" / "sky130" / "demo_ss.sdf"
    if sdf:
        sdf_path.parent.mkdir(parents=True)
        sdf_path.write_text("(DELAYFILE)\n", encoding="utf-8")
    tests = run / "dv" / "functional" / "tests" / "auto_toggle"
    tests.mkdir(parents=True)
    for name in ("config.regs", "data_in.vec", "data_out.vec"):
        (tests / name).write_text("# test\n", encoding="utf-8")
    stage.mkdir(parents=True)
    log = run / "logs" / "post_syn.log"
    return GateSimPaths(
        run,
        run / "pnr_openroad" / "sky130",
        run / "signoff" / "sdf" / "sky130",
        run / "logs" / "signoff" / "sdf" / "sky130",
        stage,
        tb,
        netlist,
        sdf_path if sdf else None,
        stage / "demo.fst",
        stage / "demo.vvp",
        log,
        stage / "report.json",
    )


def test_gate_sim_timing_modes_are_explicit(tmp_path: Path) -> None:
    """Zero/unit/SDF modes must not silently collapse into one another."""

    model = tmp_path / "cells.v"
    model.write_text("`timescale 1ns/1ps\nmodule cell; endmodule\n", encoding="utf-8")
    zero_paths = _gate_sim_paths(tmp_path)
    base = {
        "TOP": "demo",
        "TESTBENCH": "demo_tb",
        "GLS_BACKEND": "sv",
        "GLS_SIMULATOR": "iverilog",
        "PRIM": str(model),
        "TEST_NAME": "auto_toggle",
    }

    zero = compile_command(ROOT, {**base, "TIMING_MODE": "zero"}, "post_syn", zero_paths)
    assert "-gno-specify" in zero
    assert "-DUNIT_DELAY=#0" in zero
    assert "-gspecify" not in zero
    assert not any("FLEXSOC_ENABLE_SDF" in arg for arg in zero)
    assert str((zero_paths.tb.parent / "tlul_if.sv").resolve()) in zero
    assert not any(path.name.endswith("_pkg.sv") for path in map(Path, zero))

    unit = compile_command(ROOT, {**base, "TIMING_MODE": "unit"}, "post_syn", zero_paths)
    assert "-DUNIT_DELAY=#0.001" in unit
    assert "-gspecify" not in unit

    sdf_paths = _gate_sim_paths(tmp_path / "sdf", sdf=True)
    timed = compile_command(ROOT, {**base, "TIMING_MODE": "max"}, "post_syn", sdf_paths)
    assert {"-gspecify", "-Tmax", "-DFLEXSOC_ENABLE_SDF", "-DFLEXSOC_SDF_MAX"} <= set(timed)

    with pytest.raises(ValueError, match="requires an SDF file"):
        compile_command(ROOT, {**base, "TIMING_MODE": "max"}, "post_syn", zero_paths)


def test_sv_and_cocotb_gls_share_vectors_netlist_models_and_sdf(tmp_path: Path) -> None:
    """Both GLS drivers consume the same source-of-truth artifacts."""

    model = tmp_path / "cells.v"
    model.write_text("module cell; endmodule\n", encoding="utf-8")
    sv_paths = _gate_sim_paths(tmp_path / "sv", sdf=True)
    co_paths = _gate_sim_paths(tmp_path / "co", sdf=True, cocotb=True)
    common = {
        "TOP": "demo",
        "TESTBENCH": "demo_tb",
        "GLS_SIMULATOR": "iverilog",
        "TIMING_MODE": "max",
        "PRIM": str(model),
        "TEST_NAME": "auto_toggle",
    }

    sv = run_command({**common, "GLS_BACKEND": "sv"}, sv_paths)
    assert "-fst" not in sv
    assert run_environment({"WAVE_FORMAT": "fst"}) == {"IVERILOG_DUMPER": "fst"}
    assert run_environment({"WAVE_FORMAT": "vcd"}) == {}
    co = cocotb_command("sim", {**common, "GLS_BACKEND": "cocotb"}, co_paths)
    for suffix in ("config.regs", "data_in.vec", "data_out.vec"):
        assert any(arg.endswith(suffix) for arg in sv)
        assert any(arg.endswith(suffix) for arg in co)
    assert "-sdf-verbose" not in sv
    assert f"+SDF={sv_paths.sdf}" in sv
    assert f"SDF_FILE={co_paths.sdf}" in co
    assert f"GLS_NETLIST={co_paths.netlist}" in co
    assert f"GLS_MODELS={model.resolve()}" in co
    assert "TIMING_MODE=max" in co
    assert "GLS_UNIT_DELAY_DEFINE=0" in co
    assert "WAVES=1" in co
    assert "WAVES=" not in co
    assert not any(arg.startswith("IVERILOG_DUMPER=") for arg in co)


def test_cocotb_unit_delay_is_model_precision_normalized(tmp_path: Path) -> None:
    """The cocotb backend receives the same suffix-free model delay as SV."""

    model = tmp_path / "ihp_cells.v"
    model.write_text("`timescale 1ns/10ps\nmodule cell; endmodule\n", encoding="utf-8")
    paths = _gate_sim_paths(tmp_path / "co_unit", cocotb=True)
    command = cocotb_command(
        "sim",
        {
            "TOP": "demo",
            "TESTBENCH": "demo_tb",
            "GLS_BACKEND": "cocotb",
            "GLS_SIMULATOR": "iverilog",
            "TIMING_MODE": "unit",
            "GLS_UNIT_DELAY": "1ps",
            "PRIM": str(model),
            "TEST_NAME": "smoke",
        },
        paths,
    )
    assert "GLS_UNIT_DELAY_DEFINE=0.01" in command
    assert not any("1ps" in arg for arg in command)


def test_generated_cocotb_gls_is_count_agnostic_and_sdf_capable(tmp_path: Path) -> None:
    """Single-clock and N-clock cocotb wrappers expose the same GLS modes."""

    cfg = CocotbConfig(
        top="demo",
        interface="tlul",
        output=tmp_path / "tb" / "cocotb",
        rtl_dir=tmp_path / "rtl",
    )
    single = render_makefile(cfg, [])
    multi = cocotb_makefile_text("demo", tmp_path / "rtl")
    for makefile in (single, multi):
        assert "GLS_SUPPORT_SOURCES" not in makefile
        assert "TIMING_MODE ?= zero" in makefile
        assert "GLS_UNIT_DELAY_DEFINE ?= 1" in makefile
        assert "-DUNIT_DELAY=\\#$(GLS_UNIT_DELAY_DEFINE)" in makefile
        assert "SDF_FILE is required" in makefile
        assert "SIM_ARGS += -sdf-verbose" not in makefile

    clocks = clock_config({
        "N_CLOCKS": "3",
        "CLOCK_DOMAINS": "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low",
    })
    wrapper = cocotb_sv_text("demo", clocks)
    assert wrapper.count("[TB] sdf =") == 3
    assert "$sdf_annotate(sdf_path, u_dut);" in wrapper
    assert '"MINIMUM"' not in next(line for line in wrapper.splitlines() if "$sdf_annotate" in line)
    assert "tlul_pkg::" not in wrapper
    assert "logic [108:0] cfg_tl_i" in wrapper
    assert "flexsoc_tlul_h2d" in wrapper


def test_post_pnr_sdf_paths_are_timing_mode_specific(tmp_path: Path) -> None:
    """Post-layout min/typ/max exports cannot overwrite or reuse one another."""

    run = tmp_path / "runs" / "demo" / "dev"
    pnr = run / "pnr_openroad" / "sky130" / "results" / "sky130hd" / "demo" / "base"
    pnr.mkdir(parents=True)
    (pnr / "6_final.v").write_text("module demo; endmodule\n", encoding="utf-8")
    common = {
        "TOP": "demo",
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "WORKSPACE": str(tmp_path),
        "PDK": "sky130",
        "ORS_TECH": "sky130hd",
        "GLS_BACKEND": "sv",
    }
    paths = {
        mode: resolve_paths(ROOT, {**common, "TIMING_MODE": mode}, "post_pnr").sdf
        for mode in ("min", "typ", "max")
    }
    assert len(set(paths.values())) == 3
    assert paths["min"].name == "demo_post_pnr_min.sdf"
    assert paths["typ"].name == "demo_post_pnr_typ.sdf"
    assert paths["max"].name == "demo_post_pnr_max.sdf"


def test_sdf_annotation_summary_detects_partial_or_failed_annotation() -> None:
    """SDF reports distinguish an invoked annotation from warning/error cases."""

    clean = sdf_annotation_summary(
        "[TB] sdf = /tmp/demo.sdf scope=u_dut mode=MAXIMUM\nSDF annotation complete\n"
    )
    assert clean["requested_marker"] is True
    assert clean["warnings"] == [] and clean["errors"] == []
    assert clean["annotated_cells"] is None and clean["timing_checks"] is None

    partial = sdf_annotation_summary(
        "[TB] sdf = /tmp/demo.sdf scope=u_dut mode=MAXIMUM\n"
        "SDF WARNING: unable to annotate timing check\n"
    )
    assert partial["warnings"]

    failed = sdf_annotation_summary("SDF ERROR: instance not found\n")
    assert failed["requested_marker"] is False
    assert failed["errors"]


def test_gate_sim_defaults_to_zero_delay_and_selectable_backend(tmp_path: Path) -> None:
    """The public API exposes one post-sim command with explicit SV/cocotb selection."""

    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"), TOP="demo")
    default = fx.command("sim_post_syn")
    cocotb = fx.command("sim_post_syn", GLS_BACKEND="cocotb", TIMING_MODE="unit")
    assert default.values["GLS_BACKEND"] == "sv"
    assert default.values["TIMING_MODE"] == "zero"
    assert default.values["SDF_STRICT"] == "1"
    assert cocotb.values["GLS_BACKEND"] == "cocotb"
    assert cocotb.values["TIMING_MODE"] == "unit"


def test_gls_iverilog_uses_functional_models_and_portable_sv(tmp_path: Path) -> None:
    from flexsoc.backend.post_sim import TimingConfig, _compile_timing_args
    from flexsoc.backend.setup_cocotb import CocotbConfig, render_makefile
    from flexsoc.clocking import clock_config
    from flexsoc.backend.setup_tb import (
        render_sv_reg_sequence,
        render_sv_vec_driver,
        render_sv_vec_monitor,
        render_tlul_interface,
        sv_monitor_text,
        sv_driver_text,
        sv_vec_driver_text,
    )

    assert _compile_timing_args(TimingConfig("zero")) == [
        "-DFUNCTIONAL",
        "-DUNIT_DELAY=#0",
        "-gno-specify",
    ]
    ns_model = tmp_path / "ns_model.v"
    ns_model.write_text("`timescale 1ns/1ps\nmodule cell; endmodule\n", encoding="utf-8")
    ihp_model = tmp_path / "ihp_model.v"
    ihp_model.write_text("`timescale 1ns/10ps\nmodule cell2; endmodule\n", encoding="utf-8")
    assert _compile_timing_args(TimingConfig("unit"), models=(ns_model,)) == [
        "-DFUNCTIONAL",
        "-gno-specify",
        "-DUNIT_DELAY=#0.001",
    ]
    assert _compile_timing_args(
        TimingConfig("unit"), {"GLS_UNIT_DELAY": "1ps"}, (ihp_model,)
    )[-1] == "-DUNIT_DELAY=#0.01"
    assert _compile_timing_args(
        TimingConfig("unit"), {"GLS_UNIT_DELAY": "15ps"}, (ihp_model,)
    )[-1] == "-DUNIT_DELAY=#0.02"
    with pytest.raises(ValueError, match="explicit non-negative time literal"):
        _compile_timing_args(TimingConfig("unit"), {"GLS_UNIT_DELAY": "1"}, (ns_model,))
    assert "-DFUNCTIONAL" not in _compile_timing_args(TimingConfig("max"))

    makefile = render_makefile(CocotbConfig("uart", "tlul", tmp_path, rtl_dir=tmp_path), [])
    assert "COMPILE_ARGS += -DFUNCTIONAL -DUNIT_DELAY=\\#0 -gno-specify" in makefile
    assert "GLS_UNIT_DELAY_DEFINE ?= 1" in makefile
    assert "COMPILE_ARGS += -DFUNCTIONAL -gno-specify -DUNIT_DELAY=\\#$(GLS_UNIT_DELAY_DEFINE)" in makefile
    assert "-DFLEXSOC_COCOTB_WAVE_OWNER" in makefile
    assert "COCOTB_PLUSARGS += +dumpfile_path=$(WAVE_FILE)" in makefile

    sources = [
        render_sv_reg_sequence("uart", "tlul", "clk_i", active=True, registers=[]),
        render_sv_vec_monitor("uart", ["cio_tx_o"]),
        render_sv_vec_driver("uart", "clk_i", "rst_ni", ["cio_rx_i"], ["cio_tx_o"]),
        sv_driver_text("test", clock_config({"N_CLOCKS": "1"})),
        sv_vec_driver_text("test"),
        sv_monitor_text("test"),
    ]
    branches: list[tuple[str, str]] = []
    for source in sources:
        assert source.count("`ifdef VERILATOR") == 1
        assert source.count("`else") == 1
        assert source.count("`endif") == 1
        verilator_branch, portable_tail = source.split("`else", 1)
        portable_branch = portable_tail.rsplit("`endif", 1)[0]
        branches.append((verilator_branch, portable_branch))

        # Both implementations keep the structured-loop portability changes.
        assert "continue;" not in source
        assert "break;" not in source
        assert "return;" not in source
        assert ".getc(" not in source
        assert "$fgets(line, fd)" not in source

        # Verilator handles native strings and uses them for RTL regression.
        if "$fgets(" in source:
            assert "string line;" in verilator_branch
            assert 'line = $sformatf("%0s", line_buf);' in verilator_branch

        # Icarus gate-level simulation retains the packed-token fallback.
        assert 'line = $sformatf("%0s", line_buf);' not in portable_branch
        assert ".len()" not in portable_branch
        assert ".substr(" not in portable_branch
        if "$fgets(" in portable_branch:
            assert "tb_line_t line_buf;" in portable_branch
            assert "$fgets(line_buf, fd)" in portable_branch
        assert "function automatic void tb_tokenize9" not in portable_branch
        assert "function automatic void tb_cfg_tokenize9" not in portable_branch
        for line in portable_branch.splitlines():
            if line.lstrip().startswith("function automatic"):
                assert "output " not in line

    reg_verilator, reg_icarus = branches[0]
    assert "input string line" in reg_verilator
    assert "output string w0" in reg_verilator
    assert "typedef reg [8*FLEXSOC_TB_LINE_BYTES-1:0] tb_line_t;" in reg_icarus
    assert "typedef reg [8*FLEXSOC_TB_TOKEN_BYTES-1:0] tb_token_t;" in reg_icarus
    assert "task automatic tb_tokenize9" in reg_icarus
    assert "input tb_line_t line" in reg_icarus
    assert "output tb_token_t w0" in reg_icarus
    assert "function automatic logic [32:0] tb_parse_u32" in reg_icarus
    assert "function automatic logic [32:0] tb_parse_cfg_u32" in reg_icarus
    assert "input string name" in branches[1][0]
    assert "input tb_token_t name" in branches[1][1]
    assert "input string reg_key" in branches[2][0]
    assert "input tb_token_t reg_key" in branches[2][1]

    nclock_driver = branches[3][1]
    tokenizer = nclock_driver.split("task automatic tb_tokenize9", 1)[1].split("endtask", 1)[0]
    assert '$sscanf(line, "%s %s %s %s %s %s %s %s %s"' in tokenizer
    assert "$sscanf(line_buf," not in tokenizer

    tlul = render_tlul_interface()
    assert "wait_d2h_high" in tlul
    assert "is X/Z; check reset and gate-level cell model mode" in tlul


def test_icarus_sdf_model_keeps_paths_and_disables_unsupported_checks(tmp_path: Path) -> None:
    from flexsoc.backend.post_sim import _icarus_path_delay_model

    source = """module ff(input CLK, D, output Q);
  reg notifier;
  wire CLK_delayed;
  wire D_delayed;
  udp d(Q, D_delayed, CLK_delayed, notifier);
  specify
    (posedge CLK => (Q : D)) = (1:2:3);
    $width(posedge CLK, 1:2:3, 0, notifier);
    $setuphold(posedge CLK, posedge D, 1:2:3, 1:2:3, notifier, , , CLK_delayed, D_delayed);
  endspecify
endmodule
"""
    rendered, stats = _icarus_path_delay_model(source)
    assert "(posedge CLK => (Q : D))" in rendered
    assert "$width" not in rendered
    assert "$setuphold" not in rendered
    assert "assign CLK_delayed = CLK;" in rendered
    assert "assign D_delayed = D;" in rendered
    assert "initial notifier = 1'b0;" in rendered
    assert stats == {
        "timing_checks_removed": 2,
        "delayed_inputs_bound": 2,
        "notifiers_initialized": 1,
        "ifnone_paths_removed": 0,
    }


def test_ihp_gls_discovers_udp_and_sanitizes_delayed_inputs(tmp_path: Path) -> None:
    """IHP GLS includes its UDP support and derives an Icarus-compatible view."""

    from flexsoc.backend.post_sim import _icarus_path_delay_model
    from flexsoc.pdk import discover_views

    verilog = (
        tmp_path
        / "ihp-sg13g2"
        / "libs.ref"
        / "sg13g2_stdcell"
        / "verilog"
    )
    lib = verilog.parent / "lib"
    verilog.mkdir(parents=True)
    lib.mkdir()
    udp = verilog / "sg13g2_udp.v"
    cells = verilog / "sg13g2_stdcell.v"
    udp.write_text("primitive ihp_mux2 (q, a, b, s); endprimitive\n", encoding="utf-8")
    cells.write_text("module sg13g2_mux2_1; endmodule\n", encoding="utf-8")
    (lib / "sg13g2_stdcell_typ_1p20V_25C.lib").write_text("library(x) {}\n", encoding="utf-8")

    views = discover_views(tmp_path, "ihp-sg13g2")
    assert views.verilog_models == (udp.resolve(), cells.resolve())

    source = """module ff(input CLK, D, RESET_B, output Q);
  reg notifier;
  wire delayed_D, delayed_RESET_B, delayed_CLK;
  ihp_dff_r (Q, notifier, delayed_CLK, delayed_D, delayed_RESET_B, 1'b0);
  specify
    ifnone
      (posedge CLK => (Q : D)) = (1:2:3);
    (posedge CLK => (Q : D)) = (1:2:3);
    $setuphold(posedge CLK, posedge D, 1:2:3, 1:2:3, notifier, , , delayed_CLK, delayed_D);
  endspecify
endmodule
"""
    rendered, stats = _icarus_path_delay_model(
        source, remove_ifnone=True, inject_unit_delay=True
    )
    assert "assign delayed_CLK = CLK;" in rendered
    assert "assign delayed_D = D;" in rendered
    assert "assign delayed_RESET_B = RESET_B;" in rendered
    assert "ihp_dff_r `UNIT_DELAY (" in rendered
    assert "ifnone" not in rendered
    assert "$setuphold" not in rendered
    assert "(posedge CLK => (Q : D))" in rendered
    assert stats == {
        "timing_checks_removed": 1,
        "delayed_inputs_bound": 3,
        "notifiers_initialized": 1,
        "ifnone_paths_removed": 1,
    }

    functional, functional_stats = _icarus_path_delay_model(
        source, remove_ifnone=True, inject_unit_delay=True
    )
    assert "ifnone" not in functional
    assert "ihp_dff_r `UNIT_DELAY (" in functional
    assert functional_stats["ifnone_paths_removed"] == 1


def test_generated_gls_defaults_serial_rx_high_and_has_one_sdf_call(tmp_path: Path) -> None:
    from flexsoc.backend.setup_cocotb import CocotbConfig, render_tlul_wrapper
    from flexsoc.backend.setup_tb import render_sv_vec_driver

    rtl = tmp_path / "rtl"
    rtl.mkdir()
    (rtl / "uart.sv").write_text(
        "module uart(input logic clk_i, input logic rst_ni, input logic cio_rx_i, "
        "input logic [108:0] tl_i, output logic [65:0] tl_o); endmodule\n",
        encoding="utf-8",
    )
    wrapper = render_tlul_wrapper(CocotbConfig("uart", "tlul", tmp_path, rtl_dir=rtl))
    assert "cio_rx_i = '1;" in wrapper
    assert wrapper.count("$sdf_annotate(sdf_path, u_uart);") == 3
    assert "FLEXSOC_COCOTB_WAVE_OWNER" in wrapper
    assert "owner=cocotb" in wrapper and "owner=wrapper" in wrapper

    driver = render_sv_vec_driver("uart", "clk_i", "rst_ni", ["cio_rx_i"], [])
    assert "cio_rx_i = '1;" in driver


def test_uart_smoke_resets_before_live_status_checks(tmp_path: Path) -> None:
    """Timing-mode smoke resets short line-loopback pulses before status reads."""

    model_dir = ROOT / "hw" / "ips" / "uart" / "dv" / "functional" / "model"
    helper = model_dir / "uart_tests.py"
    tests_dir = tmp_path / "tests"
    subprocess.run(
        [sys.executable, str(helper), "--tests-dir", str(tests_dir), "--test", "smoke"],
        cwd=model_dir,
        check=True,
    )
    data_in = (tests_dir / "smoke" / "data_in.vec").read_text(encoding="utf-8")
    data_out = (tests_dir / "smoke" / "data_out.vec").read_text(encoding="utf-8")
    assert "40 @reset 4" in data_in
    assert "48 @write clk_i.CTRL" in data_in
    assert "52 @write clk_i.FIFO_CTRL" in data_in
    assert "80 @read clk_i.STATUS" in data_out
    assert "80 @read clk_i.FIFO_STATUS" in data_out


def test_generated_icarus_sdf_calls_use_supported_two_argument_form(tmp_path: Path) -> None:
    """Icarus path-delay wrappers avoid its ignored extended SDF arguments."""

    from flexsoc.backend.setup_cocotb import CocotbConfig, render_tlul_wrapper
    rtl = tmp_path / "rtl"
    rtl.mkdir()
    (rtl / "uart.sv").write_text(
        "module uart(input logic clk_i, input logic rst_ni, input logic cio_rx_i, "
        "input logic [108:0] tl_i, output logic [65:0] tl_o); endmodule\n",
        encoding="utf-8",
    )
    cocotb_wrapper = render_tlul_wrapper(CocotbConfig("uart", "tlul", tmp_path, rtl_dir=rtl))
    assert cocotb_wrapper.count("$sdf_annotate(sdf_path, u_uart);") == 3
    assert ", , ," not in "\n".join(
        line for line in cocotb_wrapper.splitlines() if "$sdf_annotate" in line
    )


def _write_gls_qualification(
    run_dir: Path,
    *,
    top: str = "demo",
    pdk: str = "ihp-sg13g2",
    failing_stem: str | None = None,
) -> Path:
    """Create a small archived E2E GLS matrix for metrics/check tests."""

    qualification = run_dir / "dv" / "functional" / "sim" / "post_syn" / pdk / "e2e_qualification"
    for name in ("reports", "logs", "waves"):
        (qualification / name).mkdir(parents=True, exist_ok=True)
    tests = ["smoke", "auto_toggle"]
    backends = ["sv", "cocotb"]
    modes = ["zero", "typ"]
    failures = []
    for mode in modes:
        for test_name in tests:
            for backend in backends:
                stem = f"{top}_{pdk}_{test_name}_{backend}_{mode}"
                status = "fail" if stem == failing_stem else "pass"
                report = {
                    "status": status,
                    "returncode": 238 if status == "fail" else 0,
                    "phase": "compile" if status == "fail" else "run",
                    "backend": backend,
                    "timing_mode": mode,
                    "timing_model": "icarus-path-delay-only" if mode == "typ" else "functional-zero-delay",
                    "annotation": (
                        {"requested_marker": True, "warnings": [], "errors": []}
                        if mode == "typ"
                        else None
                    ),
                }
                (qualification / "reports" / f"{stem}.json").write_text(json.dumps(report), encoding="utf-8")
                (qualification / "logs" / f"{stem}.log").write_text("gate simulation\n", encoding="utf-8")
                (qualification / "waves" / f"{stem}.fst").write_bytes(b"FST")
                if status == "fail":
                    failures.append(f"{stem}: fx sim_post_syn failed for {stem}")
    (qualification / "matrix.json").write_text(
        json.dumps(
            {
                "top": top,
                "run_id": "dev",
                "pdk": pdk,
                "tests": tests,
                "backends": backends,
                "timing_modes": modes,
                "sdf_strict": True,
                "failures": failures,
            }
        ),
        encoding="utf-8",
    )
    return qualification


def test_metrics_collects_and_summarizes_archived_gls_matrix(tmp_path: Path) -> None:
    """The selected PDK GLS matrix is machine-readable and closure-visible."""

    run_dir = tmp_path / "runs" / "demo" / "dev"
    _write_gls_qualification(run_dir)
    gls = collect_post_syn_gls("demo", run_dir, "ihp-sg13g2")
    assert gls is not None
    assert gls["status"] == "pass"
    assert gls["passed"] == gls["total"] == 8
    assert gls["by_backend"]["sv"]["passed"] == 4
    assert gls["by_mode"]["typ"]["passed"] == 4

    metrics = collect_metrics("demo", run_dir, pdk="ihp-sg13g2")
    assert metrics["schema_version"] == 10
    assert metrics["post_syn_gls"]["status"] == "pass"
    assert metrics["closure"]["stages"]["post_syn_gls"] == "pass"
    assert metrics["closure"]["order"][-1] == "post_syn_gls"


def test_check_prints_compact_gls_failure_summary(capsys, tmp_path: Path) -> None:
    """Check surfaces the failing IHP combination and evidence path."""

    run_dir = tmp_path / "runs" / "demo" / "dev"
    stem = "demo_ihp-sg13g2_smoke_cocotb_typ"
    _write_gls_qualification(run_dir, failing_stem=stem)
    metrics = collect_metrics("demo", run_dir, pdk="ihp-sg13g2")
    output = tmp_path / "metrics.json"
    output.write_text(json.dumps(metrics), encoding="utf-8")
    show_metrics(output)
    rendered = capsys.readouterr().out
    assert "Post-synthesis GLS" in rendered
    assert "7/8 passed" in rendered
    assert stem in rendered
    assert "compile failed returncode=238" in rendered


def test_check_target_refreshes_metrics_before_display() -> None:
    """A manual ``fx check`` cannot display stale pre-GLS metrics."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    assert "check: metrics ## Refresh and show" in text



def test_power_analysis_target_is_native_and_technology_scoped(tmp_path: Path) -> None:
    """Power analysis receives the complete PDK/run values without Make quoting."""

    fx = FlexSoC(project_root=ROOT, workdir=tmp_path)
    command = fx.command(
        "power_analysis",
        TOP="demo",
        PDK="sky130",
        POWER_TEST_NAME="smoke",
        POWER_GLS_BACKEND="sv",
        POWER_TIMING_MODE="typ",
    )
    assert command.argv[1:3] == ("-m", "flexsoc.backend.power_analysis")
    assert "--action" in command.argv and "single" in command.argv


def test_power_activity_tcl_uses_qualified_vcd_and_scope(tmp_path: Path) -> None:
    """OpenSTA power consumes a GLS VCD and reports annotation before power."""

    files = {name: tmp_path / name for name in ("tt.lib", "demo.v", "demo.sdc", "smoke.vcd", "gls.json")}
    for path in files.values():
        path.write_text("x\n", encoding="utf-8")
    text = render_power_activity_tcl(
        top="demo",
        liberty=files["tt.lib"],
        netlist=files["demo.v"],
        sdc=files["demo.sdc"],
        vcd=files["smoke.vcd"],
        scope="test_tb/u_dut",
        source_report=files["gls.json"],
    )
    assert "read_vcd -scope test_tb/u_dut" in text
    assert "report_activity_annotation" in text
    assert "report_power" in text
    assert "activity_source=post_syn_gls_vcd" in text




def test_power_vcd_scope_resolution_uses_generated_instance_conventions(tmp_path: Path) -> None:
    """Auto scope supports canonical u_<TOP> and wrapper u_dut conventions."""

    from flexsoc.backend.power_analysis import _resolve_vcd_scope, _vcd_scopes

    canonical = tmp_path / "canonical.vcd"
    canonical.write_text(
        """$date now $end
$scope module test_tb $end
$scope module tb_helper $end
$upscope $end
$scope module u_test $end
$var wire 1 ! clk_i $end
$upscope $end
$upscope $end
$enddefinitions $end
#0
0!
""",
        encoding="utf-8",
    )
    assert _vcd_scopes(canonical) == (
        "test_tb", "test_tb/tb_helper", "test_tb/u_test"
    )
    assert _resolve_vcd_scope(canonical, requested="auto", top="test")[0] == "test_tb/u_test"
    assert _resolve_vcd_scope(
        canonical, requested="auto", top="test", dut_instance="u_dut"
    )[0] == "test_tb/u_test"

    wrapper = tmp_path / "wrapper.vcd"
    wrapper.write_text(
        """$scope module test_tb $end
$scope module u_dut $end
$var wire 1 ! clk_i $end
$upscope $end
$upscope $end
$enddefinitions $end
""",
        encoding="utf-8",
    )
    assert _resolve_vcd_scope(wrapper, requested="auto", top="test")[0] == "test_tb/u_dut"
    assert _resolve_vcd_scope(
        wrapper, requested="test_tb.u_dut", top="test"
    )[0] == "test_tb/u_dut"


def test_power_vcd_scope_resolution_rejects_unknown_scope(tmp_path: Path) -> None:
    """A wrong explicit scope fails before OpenSTA can silently annotate zero pins."""

    from flexsoc.backend.power_analysis import _resolve_vcd_scope

    vcd = tmp_path / "trace.vcd"
    vcd.write_text(
        "$scope module test_tb $end\n$enddefinitions $end\n",
        encoding="utf-8",
    )
    with pytest.raises(ValueError, match="OpenSTA scope levels use '/'"):
        _resolve_vcd_scope(vcd, requested="missing.scope", top="test")


def test_metrics_collects_activity_power_and_check_uses_consistent_status_colors(capsys, tmp_path: Path) -> None:
    """Activity power is closure-visible and PASS/FAIL use green/red consistently."""

    run_dir = tmp_path / "runs" / "demo" / "dev"
    root = run_dir / "signoff" / "power" / "ihp-sg13g2" / "activity"
    root.mkdir(parents=True)
    (root / "summary.json").write_text(
        json.dumps(
            {
                "status": "pass", "passed": 1, "failed": 0, "total": 1,
                "reports": [
                    {
                        "status": "pass", "test": "smoke", "backend": "sv",
                        "timing_mode": "typ",
                        "corners": {"tt": {"status": "pass", "total_w": 0.001}},
                    }
                ],
            }
        ),
        encoding="utf-8",
    )
    metrics = collect_metrics("demo", run_dir, pdk="ihp-sg13g2")
    assert metrics["schema_version"] == 10
    assert metrics["power_analysis"]["status"] == "pass"
    assert metrics["closure"]["stages"]["power_activity"] == "pass"
    assert metrics["closure"]["order"][-2:] == ["post_syn_gls", "power_activity"] or metrics["closure"]["order"][-1:] == ["power_activity"]
    output = tmp_path / "metrics.json"
    output.write_text(json.dumps(metrics), encoding="utf-8")
    show_metrics(output)
    rendered = capsys.readouterr().out
    assert "Post-GLS activity power" in rendered
    assert "Activity power" in rendered


def test_power_activity_count_rejects_explicit_zero_annotation() -> None:
    """OpenSTA activity evidence is parsed without requiring one exact release format."""

    assert _activity_count("Annotated 173 pin activities") == 173
    assert _activity_count("Annotated 0 activities") == 0
    assert _activity_count("report_activity_annotation output without summary") is None


def test_post_sim_report_records_test_name() -> None:
    """A gate report identifies the vector scenario that produced its activity."""

    text = (ROOT / "src/flexsoc/backend/post_sim.py").read_text(encoding="utf-8")
    assert '"test_name": values.get("TEST_NAME", "smoke")' in text


def test_gls_and_power_targets_are_quiet_without_live() -> None:
    """Heavy event-driven output is captured unless the user explicitly selects --live."""

    from flexsoc.api import QUIET_BY_DEFAULT_TARGETS

    assert {"sim_post_syn", "sim_post_pnr", "power_analysis", "power_analysis_all"} <= QUIET_BY_DEFAULT_TARGETS



def test_nonlive_gls_stream_is_captured_to_command_log(monkeypatch, capsys, tmp_path: Path) -> None:
    """Default GLS output stays out of the terminal and remains available in a log."""

    pdk_root = tmp_path / "pdk"
    pdk_root.mkdir()
    log_dir = tmp_path / "logs"
    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"))
    base = fx.command("setup")
    command = type(base)(
        "sim_post_syn",
        (sys.executable, "-c", 'print("very noisy simulator output")'),
        tmp_path,
        base.env,
        {
            **base.values,
            "PDK": "demo",
            "PDK_ROOT": str(pdk_root),
            "LIB_SYN": str(tmp_path / "demo.lib"),
            "SYNDIR": str(tmp_path / "syn"),
            "COMMAND_LOGDIR": str(log_dir),
        },
    )
    monkeypatch.setattr(fx, "commands", lambda *targets, **overrides: (command,))
    results = fx.run("sim_post_syn", check=False)
    assert results[0].returncode == 0
    rendered = capsys.readouterr().out
    assert "very noisy simulator output" not in rendered
    assert "log:" in rendered
    assert (log_dir / "sim_post_syn.log").read_text(encoding="utf-8") == "very noisy simulator output\n"


def test_generated_vector_backends_share_atomic_cycle_semantics(tmp_path: Path) -> None:
    """SV and cocotb must drive every same-cycle signal as one atomic batch."""

    from flexsoc.backend.setup_cocotb import render_vec_driver_py
    from flexsoc.backend.setup_model import _tests_text
    from flexsoc.backend.setup_tb import render_sv_vec_driver

    cocotb_driver = render_vec_driver_py()
    assert "def _coalesce_rows(rows):" in cocotb_driver
    assert "for cycle, pairs in _coalesce_rows(rows):" in cocotb_driver
    assert "commands cannot share a cycle" in cocotb_driver
    assert 'await Timer(1, unit="ns")' in cocotb_driver

    sv_driver = render_sv_vec_driver("demo", "clk_i", "rst_ni", ["a_i", "b_i"], ["y_o"])
    assert "cycle_open" in sv_driver
    assert "tb_drive_signal_pairs" in sv_driver
    assert "@(negedge clk_i); #1;" in sv_driver

    generated = _tests_text("demo")
    assert 'input_pairs = " ".join(' in generated
    assert 'data_in = [f"{drive_cycle} {input_pairs}"] if input_pairs else []' in generated
    assert 'output_pairs = " ".join(' in generated


def test_fst2vcd_is_required_and_automatic_for_activity_power(tmp_path: Path) -> None:
    """FST conversion uses GTKWave's documented input/output interface."""

    from flexsoc.doctor import TOOLS

    rows = {executable: required for _, executable, _, required, _ in TOOLS}
    assert rows["fst2vcd"] is True
    converter = tmp_path / "fst2vcd"
    converter.write_text(
        "#!/bin/sh\n"
        "set -eu\n"
        "test \"$1\" = -f\n"
        "test \"$3\" = -o\n"
        "cat >\"$4\" <<'VCD'\n"
        "$date now $end\n"
        "$scope module test_tb $end\n"
        "$var wire 1 ! clk $end\n"
        "$upscope $end\n"
        "$enddefinitions $end\n"
        "#0\n0!\n"
        "VCD\n",
        encoding="utf-8",
    )
    converter.chmod(0o755)
    wave = tmp_path / "trace.fst"
    wave.write_bytes(b"FST")
    spec = ActivitySpec("test", "ihp-sg13g2", "smoke", "sv", "typ", tmp_path / "report.json", wave)

    vcd, log, method = _activity_vcd(
        spec, {"FST2VCD": str(converter)}, tmp_path / "captures"
    )

    assert method == "named-output"
    assert log is not None and "-f" in log.read_text() and "-o" in log.read_text()
    assert "$enddefinitions" in vcd.read_text()


def test_fst2vcd_stdout_fallback_is_supported(tmp_path: Path) -> None:
    """Older converter wrappers that emit only stdout remain usable."""

    converter = tmp_path / "fst2vcd"
    converter.write_text(
        "#!/bin/sh\n"
        "set -eu\n"
        "if [ \"${1:-}\" = -f ]; then exit 2; fi\n"
        "cat <<'VCD'\n"
        "$date now $end\n"
        "$scope module test_tb $end\n"
        "$var wire 1 ! clk $end\n"
        "$upscope $end\n"
        "$enddefinitions $end\n"
        "#0\n0!\n"
        "VCD\n",
        encoding="utf-8",
    )
    converter.chmod(0o755)
    wave = tmp_path / "trace.fst"
    wave.write_bytes(b"FST")
    spec = ActivitySpec("test", "sky130", "smoke", "sv", "typ", tmp_path / "report.json", wave)

    vcd, log, method = _activity_vcd(
        spec, {"FST2VCD": str(converter)}, tmp_path / "captures"
    )

    assert method == "stdout"
    assert log is not None and "retry=stdout" in log.read_text()
    assert "$enddefinitions" in vcd.read_text()


def test_managed_toolchain_has_status_prune_and_stable_link_contract() -> None:
    """Managed installs stay versioned, inspectable, and safely prunable."""

    deps = (ROOT / "src/flexsoc/backend/deps.sh").read_text(encoding="utf-8")
    make = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    assert "status                 Show managed prefixes" in deps
    assert "prune                  Remove obsolete managed prefixes" in deps
    assert "STABLE_LINK=${XDG_DATA_HOME:-$HOME/.local/share}/flexsoc/toolchain" in deps
    assert "DRY_RUN=1; pass --apply" in deps
    assert "deps-status:" in make
    assert "deps-prune:" in make


def test_ci_uses_preverified_locked_container_image() -> None:
    """Normal CI pulls an immutable digest and never builds the EDA image."""

    dockerfile = (ROOT / "docker/ci/Dockerfile").read_text(encoding="utf-8")
    ignore = (ROOT / "docker/ci/Dockerfile.dockerignore").read_text(encoding="utf-8")
    ci = (ROOT / ".github/workflows/ci.yml").read_text(encoding="utf-8")
    image = (ROOT / ".github/workflows/toolchain-image.yml").read_text(encoding="utf-8")
    common = (ROOT / "docker/scripts/common.sh").read_text(encoding="utf-8")
    publish = (ROOT / "docker/scripts/publish.sh").read_text(encoding="utf-8")
    assert not (ROOT / ".dockerignore").exists()
    assert "deps.sh install --system --profile base" in dockerfile
    assert "uv sync --frozen --no-install-project" in dockerfile
    assert "docker/.state" in ignore
    assert "docker/scripts/check-lock.sh" in ci
    assert "docker pull" in ci
    assert "buildx build" not in ci
    assert "docker/build-push-action" not in ci
    assert "workflow_dispatch" in image
    assert "push:" not in image.split("permissions:", 1)[0]
    assert "validate_lock" in common
    assert "docker buildx imagetools inspect" in publish
    assert "Commit %s before pushing source changes" in publish


def test_docker_release_scripts_require_build_verify_publish_order() -> None:
    """The local image must be verified before publishing and locking a digest."""

    build = (ROOT / "docker/scripts/build.sh").read_text(encoding="utf-8")
    verify = (ROOT / "docker/scripts/verify.sh").read_text(encoding="utf-8")
    run_ci = (ROOT / "docker/scripts/run-ci.sh").read_text(encoding="utf-8")
    lock = (ROOT / "docker/ci/image.lock").read_text(encoding="utf-8")
    assert "--metadata-file" in build
    assert "verified.env" in verify
    assert "DEPS_MODE=system fx deps-doctor" in run_ci
    assert "pytest -q tests/test_api.py" in run_ci
    assert "inputs_sha256=" in lock
    assert "tag=toolchain-" in lock



def test_gtkwave_managed_build_is_explicitly_gtk3_and_prefix_local() -> None:
    """GTKWave must not auto-select GTK2 or satisfy fst2vcd from the host."""

    deps = (ROOT / "src/flexsoc/backend/deps.sh").read_text(encoding="utf-8")
    assert './configure --enable-gtk3 --prefix="$PREFIX"' in deps
    assert '[[ -x "$PREFIX/bin/fst2vcd" ]]' in deps
    assert 'write_gtkwave_version_receipt' in deps
    assert '"$MARKERS/gtkwave.version"' in deps


def test_gtkwave_doctor_is_headless_and_checks_dynamic_linkage() -> None:
    """The container doctor must not initialize GTK merely to read a version."""

    deps = (ROOT / "src/flexsoc/backend/deps.sh").read_text(encoding="utf-8")
    assert '"$PREFIX/bin/gtkwave" --version' not in deps
    assert 'out=$(cat "$MARKERS/gtkwave.version")' in deps
    assert 'ldd "$PREFIX/bin/gtkwave"' in deps
    assert '[[ "$linkage" != *"not found"* ]]' in deps
    assert 'headless receipt; shared libraries resolved' in deps


def test_docker_only_workstation_scripts_are_guarded_and_system_scoped() -> None:
    """Host inventory ignores managed prefixes and cleanup requires a verified image."""

    inventory = (ROOT / "docker/scripts/system-inventory.sh").read_text(encoding="utf-8")
    preflight = (ROOT / "docker/scripts/preflight.sh").read_text(encoding="utf-8")
    cleanup = (ROOT / "docker/scripts/cleanup-managed-toolchain.sh").read_text(encoding="utf-8")
    build = (ROOT / "docker/scripts/build.sh").read_text(encoding="utf-8")
    dockerfile = (ROOT / "docker/ci/Dockerfile").read_text(encoding="utf-8")

    assert 'managed_root="${XDG_DATA_HOME:-$HOME/.local/share}/flexsoc"' in inventory
    assert "FlexSoC managed prefixes and the repository .venv are deliberately excluded" in inventory
    assert "docker system df" in preflight
    assert "RECOMMENDED_DOCKER_MEMORY_GB" in preflight
    assert '[[ -f "$verified" ]]' in cleanup
    assert "Refusing cleanup: Docker verification record is stale" in cleanup
    assert "repository .venv, /usr, /usr/local" in cleanup
    assert '"$DOCKER_DIR/scripts/preflight.sh"' in build
    assert "deps.sh doctor --system --profile base" in dockerfile

def test_base_toolchain_declares_sby_python_runtime_dependency() -> None:
    """SymbiYosys must not reach doctor without its click runtime module."""

    deps = (ROOT / "src/flexsoc/backend/deps.sh").read_text(encoding="utf-8")
    assert "python3-click" in deps
    assert "BASE_PYTHON_MODULES=(click)" in deps
    assert 'python3 -c "import ${module}"' in deps
    assert 'missing+=("python:${module}")' in deps


def test_docker_toolchain_build_has_resumable_install_checkpoint() -> None:
    """Installation, doctor, and runtime must be separate recoverable stages."""

    dockerfile = (ROOT / "docker/ci/Dockerfile").read_text(encoding="utf-8")
    common = (ROOT / "docker/scripts/common.sh").read_text(encoding="utf-8")
    build = (ROOT / "docker/scripts/build.sh").read_text(encoding="utf-8")

    assert "AS toolchain-prereqs" in dockerfile
    assert "AS toolchain-installed" in dockerfile
    assert "AS toolchain-verified" in dockerfile
    assert "AS runtime" in dockerfile
    assert "id=flexsoc-toolchain-build" in dockerfile
    assert "id=flexsoc-toolchain-prefix" in dockerfile
    assert "sharing=locked" in dockerfile
    assert "deps.sh install --system --profile base" in dockerfile
    assert "deps.sh doctor --system --profile base" in dockerfile
    assert dockerfile.index("AS toolchain-installed") < dockerfile.index("AS toolchain-verified")
    assert "toolchain_checkpoint_ref" in common
    assert "--target toolchain-installed" in build
    assert "--target runtime" in build
    assert "toolchain-checkpoint.env" in build

def test_sby_install_has_deterministic_release_version_and_self_repair() -> None:
    """A shallow pinned checkout must not install a bare ``SBY`` version string."""

    deps = (ROOT / "src/flexsoc/backend/deps.sh").read_text(encoding="utf-8")
    assert 'expected="SBY v$(version_var SBY)"' in deps
    assert 'YOSYS_RELEASE_VERSION="$expected"' in deps
    assert 'info "repair sby release string:' in deps
    assert 'contains "$out" "$expected" sby' in deps


def test_eqy_install_has_deterministic_release_version_and_self_repair() -> None:
    """A shallow pinned checkout must not install a bare ``EQY`` version string."""

    deps = (ROOT / "src/flexsoc/backend/deps.sh").read_text(encoding="utf-8")
    assert 'expected="EQY v$(version_var EQY)"' in deps
    assert 'YOSYS_CONFIG="$PREFIX/bin/yosys-config" YOSYS_RELEASE_VERSION="$expected"' in deps
    assert 'info "repair eqy release string:' in deps
    assert 'contains "$out" "$expected" eqy' in deps



def test_eqy_reuses_existing_profile_unless_force_is_explicit() -> None:
    """Loaded IP profiles survive normal eqy runs; --force remains the overwrite switch."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    setup = text.split("setup_eqy:", 1)[1].split("\neqy:", 1)[0]
    assert 'if [ -f "$(EQY_CONFIG)" ] && [ "$(FORCE)" != "1" ]' in setup
    assert "(existing)" in setup
    assert "(generated)" in setup
    assert "eqy-bind" in setup
    assert "eqy_saved" not in text


def test_ip_load_is_complete_and_ip_save_is_eqy_only(tmp_path: Path) -> None:
    """Load mirrors the complete package while save persists only the selected PDK profile."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    load = text.split("\nip_load:", 1)[1].split("\nip_save:", 1)[0]
    save = text.split("\nip_save:", 1)[1].split("\n# ====", 1)[0]
    assert 'for entry in "$$src_ip"/* "$$src_ip"/.[!.]* "$$src_ip"/..?*' in load
    assert 'cp -a "$$src_ip"/. "$$dst_dir"/' in load
    assert "eqy-export" in save
    assert "$(EQY_CONFIG)" in save and "$(EQY_VIEW)" in save
    assert "for sub in rtl" not in save
    assert "src_run=" not in save

    command = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws")
    ).command("ip_save", PDK="ihp-sg13g2")
    assert "PDK=ihp-sg13g2" in command.argv


def test_eqy_profile_export_is_portable_and_bindable(tmp_path: Path, monkeypatch) -> None:
    """The two saved profile files contain no workspace/PDK absolute dependencies."""

    from flexsoc.backend.setup_signoff import (
        bind_equivalence_profile,
        export_equivalence_profile,
    )

    sources = tmp_path / "source"
    sources.mkdir()
    common = sources / "rtl_common.f"
    ip = sources / "rtl_ip.f"
    netlist = sources / "demo_synth.v"
    liberty = sources / "cells.lib"
    model = sources / "cells.v"
    clock_gate = sources / "sky130_clock_gates_formal.v"
    view = sources / "demo_eqy_view.sv"
    for path, body in (
        (common, "demo_pkg.sv\n"),
        (ip, "demo.sv\n"),
        (netlist, "module demo; endmodule\n"),
        (liberty, "library(test) {}\n"),
        (model, "module cell; endmodule\n"),
        (clock_gate, "module gate; endmodule\n"),
        (view, "module demo; endmodule\n"),
    ):
        path.write_text(body, encoding="utf-8")
    config = sources / "demo_rtl_vs_syn.eqy"
    config.write_text(
        "\n".join((
            "[gold]",
            f"read_slang -f {common.resolve()} -f {ip.resolve()} --top demo",
            f"read_verilog -formal -sv {view.resolve()}",
            "[gate]",
            f"read_liberty -ignore_miss_func {liberty.resolve()}",
            f"read_verilog -formal -sv {model.resolve()}",
            f"read_verilog -formal -sv {clock_gate.resolve()}",
            f"read_verilog -formal -sv {netlist.resolve()}",
            "",
        )),
        encoding="utf-8",
    )

    profile = tmp_path / "profile"
    saved_config, saved_view = export_equivalence_profile(
        config=config,
        view=view,
        output_dir=profile,
        filelists=(common, ip),
        netlist=netlist,
        liberty=liberty,
        cell_models=(model,),
        clock_gate_model=clock_gate,
    )
    text = saved_config.read_text(encoding="utf-8")
    assert str(tmp_path) not in text
    for name in (
        "rtl_common.f", "rtl_ip.f", "netlist.v", "library.lib",
        "cell_model_0.v", "sky130_clock_gates_formal.v", "demo_eqy_view.sv",
    ):
        assert name in text
    assert saved_view.read_text(encoding="utf-8") == view.read_text(encoding="utf-8")
    assert sorted(path.name for path in profile.iterdir()) == [
        "demo_eqy_view.sv", "demo_rtl_vs_syn.eqy"
    ]

    monkeypatch.setenv("FLEXSOC_PDK", "ihp-sg13g2")
    bound = bind_equivalence_profile(
        top="demo",
        output_dir=profile,
        filelists=(common, ip),
        netlist=netlist,
        liberty=liberty,
        cell_models=(model,),
        formal_pdk_proc=None,
        clock_gate_model=clock_gate,
        config=saved_config,
    )
    assert bound
    for name in ("rtl_common.f", "rtl_ip.f", "netlist.v", "library.lib", "cell_model_0.v"):
        assert (profile / name).is_symlink()
