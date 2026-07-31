"""Gate-level simulation and waveform contract checks."""

from __future__ import annotations

from pathlib import Path

from flexsoc.backend.post_sim import compile_command, resolve_paths, run_command
from flexsoc.backend.setup_cocotb import CocotbConfig, _render_tlul_wrapper, render_makefile
from flexsoc.backend.setup_multiclock import sv_tb_text
from flexsoc.backend.setup_pnr import render_config


def _tree(tmp_path: Path) -> tuple[Path, dict[str, str]]:
    run = tmp_path / "ws" / "runs" / "demo" / "r1"
    tb = run / "dv" / "functional" / "tb" / "sv" / "demo_tb.sv"
    tb.parent.mkdir(parents=True)
    tb.write_text('`include "include_demo_tb.sv"\nmodule demo_tb; endmodule\n')
    include = tb.parent / "include_demo_tb.sv"
    include.write_text('`ifdef SYN\n`include "demo_synth.v"\n`endif\n')
    netlist = run / "syn" / "sky130" / "demo_synth.v"
    netlist.parent.mkdir(parents=True)
    netlist.write_text("module demo; endmodule\n")
    prim = tmp_path / "pdk" / "cells.v"
    prim.parent.mkdir(parents=True)
    prim.write_text("module BUF; endmodule\n")
    values = {
        "WORKSPACE": str(tmp_path / "ws"),
        "TOP": "demo",
        "RUN_TOP": "demo",
        "RUN_ID": "r1",
        "TESTBENCH": "demo_tb",
        "WAVE_FORMAT": "fst",
        "TIMING_MODE": "max",
        "GLS_SIMULATOR": "iverilog",
        "PRIM": str(prim),
    }
    return run, values


def test_post_syn_defaults_to_icarus_fst_and_max_timing(tmp_path: Path) -> None:
    run, values = _tree(tmp_path)
    paths = resolve_paths(tmp_path, values, "post_syn")
    compile_argv = compile_command(tmp_path, values, "post_syn", paths)
    run_argv = run_command(values, paths)
    assert compile_argv[:4] == ["iverilog", "-g2012", "-gspecify", "-Tmax"]
    assert "-DFLEXSOC_ENABLE_SDF" in compile_argv
    assert "-DFLEXSOC_SDF_MAX" in compile_argv
    assert run_argv[0:2] == ["vvp", "-fst"]
    assert str(paths.wave).endswith("demo_tb.fst")
    assert paths.wave.parent == run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
    assert f"+TEST_ROOT={paths.run_root / 'dv' / 'functional' / 'tests'}" in run_argv
    assert paths.pnr_dir == paths.run_root / "pnr_openroad" / "sky130"
    assert "+TEST_NAME=smoke" in run_argv


def test_vcd_is_explicit_opt_in(tmp_path: Path) -> None:
    _, values = _tree(tmp_path)
    values["WAVE_FORMAT"] = "vcd"
    paths = resolve_paths(tmp_path, values, "post_syn")
    assert run_command(values, paths)[0] == "vvp"
    assert "-fst" not in run_command(values, paths)
    assert paths.wave.suffix == ".vcd"


def test_multiclock_tb_never_invents_root_vcd_and_supports_sdf() -> None:
    text = sv_tb_text("tri_stream_dsp", "tri_stream_dsp_tb")
    assert '$value$plusargs("WAVE=%s", wave_path)' in text
    assert '$value$plusargs("VCD=%s", wave_path)' in text
    assert 'wave_path = ""' in text
    assert 'tri_stream_dsp_tb.vcd' not in text
    assert '`ifdef FLEXSOC_ENABLE_SDF' in text
    assert '$sdf_annotate(sdf_path, u_dut' in text
    assert '"MAXIMUM"' in text
    assert 'SDF_MODE' not in text
    assert '`include "tri_stream_dsp_synth.v"' in text


def test_cocotb_gate_scaffold_is_icarus_fst_sdf_ready(tmp_path: Path) -> None:
    cfg = CocotbConfig(
        top="demo",
        rtl_dir=tmp_path,
        output=tmp_path / "cocotb",
        simulator="verilator",
        clk="clk_i",
        rst="rst_ni",
        interface="tlul",
        ips_root=tmp_path,
    )
    makefile = render_makefile(cfg, [])
    assert "SIM := icarus" in makefile
    assert "WAVE_FORMAT ?= fst" in makefile
    assert "-gspecify -T$(TIMING_MODE)" in makefile
    assert "+SDF=$(abspath $(SDF_FILE))" in makefile
    assert "GLS_MODELS" in makefile and "GLS_NETLIST" in makefile
    assert "GLS_NETLIST       ?= ../../../../syn/$(PDK)/demo_synth.v" in makefile
    assert "-DFLEXSOC_ENABLE_SDF" in makefile

    previous = "module demo_tb;\n  logic clk_i;\n  logic rst_ni;\n  logic tl_i_a_valid;\nendmodule\n"
    wrapper = _render_tlul_wrapper(cfg, previous)
    assert 'wave_path = ""' in wrapper
    assert "demo_tb.fst" not in wrapper
    assert '`ifdef FLEXSOC_ENABLE_SDF' in wrapper
    assert '$sdf_annotate(sdf_path, u_demo' in wrapper


def test_post_pnr_discovers_outputs_below_selected_pdk(tmp_path: Path) -> None:
    run, values = _tree(tmp_path)
    values["ORS_TECH"] = "sky130hd"
    final_dir = run / "pnr_openroad" / "sky130" / "results" / "sky130hd" / "demo" / "base"
    final_dir.mkdir(parents=True)
    (final_dir / "6_final.v").write_text("module demo; endmodule\n")
    (final_dir / "6_final.sdc").write_text("create_clock -period 10 [get_ports clk_i]\n")
    (final_dir / "6_final.spef").write_text("*SPEF \"IEEE 1481-1998\"\n")
    paths = resolve_paths(tmp_path, values, "post_pnr")
    assert paths.netlist == (final_dir / "6_final.v").resolve()
    assert paths.pnr_dir == run / "pnr_openroad" / "sky130"
    assert paths.stage_dir == run / "dv" / "functional" / "sim" / "post_pnr" / "sky130"


def test_pnr_config_reuses_shared_logical_sdc(tmp_path: Path) -> None:
    sdc = tmp_path / "runs" / "demo" / "r1" / "constraints" / "demo.sdc"
    text = render_config(
        top="demo",
        inc_dirs=[],
        vfiles=[],
        outdir=tmp_path / "runs" / "demo" / "r1" / "pnr_openroad" / "sky130",
        platform="sky130hd",
        sdc_file=sdc,
    )
    assert f"export SDC_FILE           = {sdc}" in text
