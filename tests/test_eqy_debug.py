"""EQY counterexample discovery and viewer checks."""

from __future__ import annotations

from pathlib import Path

import pytest

from flexsoc.backend.eqy_debug import (
    choose_trace,
    discover_result_dir,
    explain_counterexample,
    failure_metadata,
    first_vcd_divergence,
    interesting_log_lines,
    ranked_signals,
    run_reset_normalized_diagnostic,
    run_synthesis_boundary_diagnostics,
    scan,
    select,
    write_gtkwave_session,
)
from flexsoc.cli import app


def _fixture(tmp_path: Path) -> tuple[Path, Path]:
    workspace = tmp_path / "workspace"
    result = workspace / "runs" / "test" / "dev" / "signoff" / "equivalence" / "sky130" / "rtl_vs_syn" / "test_rtl_vs_syn"

    passed = result / "strategies" / "test.data_o.0" / "smt_fast" / "test.data_o.0"
    passed.mkdir(parents=True)
    (passed.parent / "status").write_text("PASS\n")
    (passed / "status").write_text("PASS\n")

    failed = result / "strategies" / "test.tl_o.65" / "smt_fast" / "test.tl_o.65"
    engine = failed / "engine_0"
    engine.mkdir(parents=True)
    (failed.parent / "status").write_text("FAIL\n")
    (failed / "status").write_text("FAIL\n")
    (failed / "logfile.txt").write_text("SBY: engine_0: Status returned by engine: FAIL\n")
    (engine / "logfile_basecase.txt").write_text(
        "SBY engine_0.basecase: BMC failed!\n"
        "SBY summary: failed assertion miter.assert_eq at partition.sv:74 step 2\n"
        "Assert failed in miter: partition.sv:74.37-74.49; counterexample trace generated\n"
    )
    (engine / "logfile_induction.txt").write_text("induction finished\n")
    vcd = engine / "trace.vcd"
    vcd.write_text(
        "$scope module test $end\n"
        "$scope module gold $end\n"
        "$var wire 1 ! tl_o_65 $end\n"
        "$var wire 1 \" clk_i $end\n"
        "$upscope $end\n"
        "$scope module gate $end\n"
        "$var wire 1 # tl_o_65 $end\n"
        "$var wire 1 $ rst_ni $end\n"
        "$upscope $end\n"
        "$upscope $end\n"
        "$enddefinitions $end\n"
        "#0\n0!\n0#\n0\"\n1$\n"
        "#1\n0!\n0#\n1\"\n1$\n"
        "#2\n0!\n1#\n0\"\n1$\n",
        encoding="utf-8",
    )
    (engine / "trace_induct.vcd").write_text(vcd.read_text())
    (engine / "trace.yw").write_text("witness\n")
    return workspace, result


def test_eqy_counterexample_discovery_selection_and_signals(tmp_path: Path) -> None:
    workspace, result = _fixture(tmp_path)
    resolved = discover_result_dir(
        tmp_path, workspace, top="test", run_top="test", run_id="dev", pdk="sky130"
    )
    assert resolved == result

    rows = scan(result)
    assert len(rows) == 2
    item = select(rows)
    assert item.partition == "test.tl_o.65"
    assert item.status == "FAIL"
    assert item.failing_strategy is not None
    assert item.failing_strategy.name == "smt_fast"

    trace = choose_trace(item.failing_strategy)
    assert trace.name == "trace.vcd"
    assert choose_trace(item.failing_strategy, "induction").name == "trace_induct.vcd"
    signals = ranked_signals(trace, item.partition)
    assert any("gold.tl_o_65" in signal for signal in signals)
    assert any("gate.tl_o_65" in signal for signal in signals)
    assert any("clk_i" in signal for signal in signals)

    diagnostics = interesting_log_lines(item.failing_strategy)
    assert any("FAIL" in line for line in diagnostics)
    assert any("counterexample" in line for line in diagnostics)

    session = write_gtkwave_session(trace, item.partition)
    text = session.read_text()
    assert str(trace) in text
    assert "gold.tl_o_65" in text
    assert "gate.tl_o_65" in text



def test_eqy_counterexample_prefers_strategy_with_real_artifacts(tmp_path: Path) -> None:
    """Inherited FAIL markers must not hide the strategy that produced the trace."""

    _, result = _fixture(tmp_path)
    partition = result / "strategies" / "test.tl_o.65"

    # EQY may leave a FAIL status on a later strategy without actually running it.
    inherited = partition / "smt_deep"
    inherited.mkdir()
    (inherited / "status").write_text("FAIL\n")

    item = select(scan(result))
    assert item.status == "FAIL"
    assert item.failing_strategy is not None
    assert item.failing_strategy.name == "smt_fast"
    assert choose_trace(item.failing_strategy).name == "trace.vcd"

def test_eqy_counterexample_explain_finds_first_gold_gate_divergence(tmp_path: Path) -> None:
    _, result = _fixture(tmp_path)
    item = select(scan(result))
    strategy = item.failing_strategy
    assert strategy is not None

    metadata = failure_metadata(strategy)
    assert metadata["phase"] == "basecase"
    assert metadata["step"] == 2

    trace = choose_trace(strategy)
    divergence = first_vcd_divergence(trace, item.partition)
    assert divergence is not None
    assert divergence["time"] == 2
    assert divergence["gold"] == "0"
    assert divergence["gate"] == "1"
    assert divergence["class"] == "boolean-data"

    explanation = explain_counterexample(item)
    assert explanation["classification"] == "boolean-data"
    assert explanation["failure"]["step"] == 2
    assert explanation["first_divergence"]["time"] == 2


def test_cli_eqy_debug_combines_closure_and_explanation(tmp_path: Path, monkeypatch, capsys) -> None:
    _fixture(tmp_path)
    settings = tmp_path / ".flexsoc" / "settings.json"
    settings.parent.mkdir()
    settings.write_text('{"TOP":"test","RUN_TOP":"test","RUN_ID":"dev"}\n')
    monkeypatch.chdir(tmp_path)

    assert app(["eqy_debug"]) == 0
    output = capsys.readouterr().out
    assert "EQY debug" in output
    assert "1/2 partitions proven" in output
    assert "test.tl_o.65" in output
    assert "basecase" in output
    assert "step 2" in output
    assert "boolean-data" in output
    assert "fx eqy_debug --wave test.tl_o.65" in output


def test_eqy_xprop_masks_raw_data_difference_until_gold_is_known(tmp_path: Path) -> None:
    """A raw D-bit difference under gold X must not be called Boolean mismatch."""

    vcd = tmp_path / "xprop.vcd"
    vcd.write_text(
        "$scope module miter $end\n"
        "$var wire 1 ! __po_tl_o__65__gold_d $end\n"
        "$var wire 1 \" __po_tl_o__65__gold_x $end\n"
        "$var wire 1 # __po_tl_o__65__gate_d $end\n"
        "$var wire 1 $ __po_tl_o__65__gate_x $end\n"
        "$upscope $end\n"
        "$enddefinitions $end\n"
        "#0\n0!\n1\"\n1#\n0$\n"  # raw data differs, but gold is X: compatible
        "#10\n0!\n0\"\n0#\n0$\n"
        "#20\n0!\n0\"\n1#\n0$\n",  # first semantic mismatch
        encoding="utf-8",
    )

    divergence = first_vcd_divergence(vcd, "test.tl_o.65")
    assert divergence is not None
    assert divergence["time"] == 20
    assert divergence["class"] == "boolean-data"
    assert divergence["gold"] == "0"
    assert divergence["gate"] == "1"
    assert divergence["gold_x"] == "0"
    assert divergence["gate_x"] == "0"


def test_reset_normalized_diagnostic_injects_reset_on_gold_and_gate(tmp_path: Path) -> None:
    """Reset replay must initialize both EQY sides and preserve the baseline."""

    _, result = _fixture(tmp_path)
    config = result.parent / "test_rtl_vs_syn.eqy"
    config.write_text(
        "[gold]\n"
        "read_verilog gold.v\n"
        "prep -top test\n"
        "flatten\n"
        "\n"
        "[gate]\n"
        "read_verilog gate.v\n"
        "prep -top test\n"
        "flatten\n"
        "\n"
        "[strategy smt_fast]\n"
        "use sby\n"
        "engine smtbmc bitwuzla\n"
        "depth 5\n"
        "xprop on\n",
        encoding="utf-8",
    )
    fake_eqy = tmp_path / "fake-eqy-reset"
    fake_eqy.write_text(
        "#!/bin/sh\nset -eu\nstem=${3%.eqy}\n"
        "d=\"$stem/strategies/test.tl_o.65/smt_fast\"\nmkdir -p \"$d\"\n"
        "target='strategies/test.tl_o.65/smt_fast/status'\n"
        "printf '%s\\n' \"$target\" > \"$stem/summary_targets.list\"\n"
        "printf '%s:\\n\\t@printf \"PASS\\\\n\" > %s\\n' \"$target\" \"$target\" > \"$stem/strategies.mk\"\n",
        encoding="utf-8",
    )
    fake_eqy.chmod(0o755)

    diagnostic = run_reset_normalized_diagnostic(
        result,
        partition="test.tl_o.65",
        clock="clk_i",
        reset="rst_ni",
        reset_active="low",
        reset_cycles=2,
        eqy=str(fake_eqy),
    )
    assert diagnostic["valid"] is True
    assert diagnostic["status"] == "PASS"
    assert diagnostic["pass"] is True
    rewritten = Path(str(diagnostic["config"])).read_text(encoding="utf-8")
    reset_line = "sim -clock clk_i -resetn rst_ni -rstlen 2 -n 2 -w"
    assert rewritten.count("uniquify") == 2
    assert rewritten.count(reset_line) == 2
    assert "xprop on" in rewritten
    assert diagnostic["cached"] is False
    cached = run_reset_normalized_diagnostic(
        result, partition="test.tl_o.65", clock="clk_i", reset="rst_ni",
        reset_active="low", reset_cycles=2, eqy=str(fake_eqy),
    )
    assert cached["cached"] is True
    assert cached["status"] == "PASS"
    assert result.is_dir()


def test_reset_normalized_diagnostic_uses_shared_eqy_script_once(tmp_path: Path) -> None:
    """Modern EQY configs inject one reset replay into the shared normalization."""

    _, result = _fixture(tmp_path)
    config = result.parent / "test_rtl_vs_syn.eqy"
    config.write_text(
        "[gold]\nread_verilog gold.v\n\n"
        "[gate]\nread_verilog gate.v\n\n"
        "[script]\nprep -top test -flatten\nmemory -nomap\nasync2sync\n\n"
        "[strategy sat]\nuse sat\ndepth 5\n",
        encoding="utf-8",
    )
    fake_eqy = tmp_path / "fake-eqy-shared-reset"
    fake_eqy.write_text(
        "#!/bin/sh\nset -eu\nstem=${3%.eqy}\n"
        "d=\"$stem/strategies/test.tl_o.65/sat\"\nmkdir -p \"$d\"\n"
        "target='strategies/test.tl_o.65/sat/status'\n"
        "printf '%s\\n' \"$target\" > \"$stem/summary_targets.list\"\n"
        "printf '%s:\n\t@printf \"PASS\\\\n\" > %s\n' \"$target\" \"$target\" > \"$stem/strategies.mk\"\n",
        encoding="utf-8",
    )
    fake_eqy.chmod(0o755)

    diagnostic = run_reset_normalized_diagnostic(
        result, partition="test.tl_o.65", reset_cycles=1, eqy=str(fake_eqy)
    )
    rewritten = Path(str(diagnostic["config"])).read_text(encoding="utf-8")
    assert diagnostic["status"] == "PASS"
    assert rewritten.count("uniquify") == 1
    assert rewritten.count("sim -clock clk_i -resetn rst_ni -rstlen 1 -n 1 -w") == 1
    assert rewritten.index("async2sync") < rewritten.index("uniquify")


def test_reset_diagnostic_zero_partitions_is_marked_invalid(tmp_path: Path) -> None:
    """A replay that never reaches EQY partitioning must not look like 0/0 closure."""

    _, result = _fixture(tmp_path)
    config = result.parent / "test_rtl_vs_syn.eqy"
    config.write_text(
        "[gold]\nread_verilog gold.v\nprep -top test\n\n"
        "[gate]\nread_verilog gate.v\nprep -top test\n\n"
        "[strategy smt_fast]\nuse sby\nxprop on\n",
        encoding="utf-8",
    )
    fake_eqy = tmp_path / "fake-eqy-empty"
    fake_eqy.write_text(
        "#!/bin/sh\n"
        "set -eu\n"
        "stem=${2%.eqy}\n"
        "mkdir -p \"$stem\"\n"
        "printf 'ERROR: gate simulation stopped before partitioning\n'\n",
        encoding="utf-8",
    )
    fake_eqy.chmod(0o755)

    with pytest.raises(RuntimeError, match="summary_targets|setup"):
        run_reset_normalized_diagnostic(
            result, partition="test.tl_o.65", eqy=str(fake_eqy)
        )




def test_synthesis_script_emits_mapping_checkpoints_and_abc_constraints(tmp_path: Path) -> None:
    """ASIC synthesis must expose mapping boundaries and use ABC's own constraint format."""

    from flexsoc.backend.setup_syn import render_abc_constraints, yosys_synth_asic_slang

    rtl = tmp_path / "rtl.f"
    rtl.write_text("demo.sv\n", encoding="utf-8")
    text = yosys_synth_asic_slang(
        "demo", tmp_path / "cells.lib", 10.0, "delay", tmp_path, tmp_path / "syn", (rtl,)
    )
    generic = "write_rtlil " + (tmp_path / "syn" / "demo_generic.il").as_posix()
    dffmap = "write_rtlil " + (tmp_path / "syn" / "demo_dffmap.il").as_posix()
    abc = "write_rtlil " + (tmp_path / "syn" / "demo_abc.il").as_posix()
    clean = "write_rtlil " + (tmp_path / "syn" / "demo_clean.il").as_posix()
    assert text.index(generic) < text.index("dfflibmap -liberty") < text.index(dffmap) < text.index("abc -D") < text.index(abc) < text.index("opt_clean") < text.index(clean)
    constraint_line = next(line for line in text.splitlines() if "-constr " in line)
    assert (tmp_path / "syn" / "abc.constr").as_posix() in constraint_line
    assert "opt_clean -purge" not in text
    assert not constraint_line.rstrip().endswith("\\")
    assert f"-constr {(tmp_path / 'demo.sdc').as_posix()}" not in text
    assert render_abc_constraints("BUF_X1", 10.0) == "set_driving_cell BUF_X1\nset_load 10\n"


def test_synthesis_boundary_diagnostic_replays_rtlil_checkpoints(tmp_path: Path) -> None:
    """Boundary probe must reuse the main EQY config and replace only its gate netlist."""

    _, result = _fixture(tmp_path)
    config = result.parent / "test_rtl_vs_syn.eqy"
    mapped = tmp_path / "syn" / "test_synth.v"
    mapped.parent.mkdir()
    mapped.write_text("module test; endmodule\n", encoding="utf-8")
    config.write_text(
        "[gold]\nread_verilog gold.v\nprep -top test\n\n"
        "[gate]\nread_liberty cells.lib\nread_verilog clock_gate.v\n"
        f"read_verilog {mapped}\nprep -top test\n\n"
        "[strategy smt_fast]\nuse sby\nxprop on\n",
        encoding="utf-8",
    )
    for name in ("generic", "dffmap", "abc", "clean"):
        (mapped.parent / f"test_{name}.il").write_text("module \\test\nend\n", encoding="utf-8")

    fake_eqy = tmp_path / "fake-eqy-boundary"
    fake_eqy.write_text(
        "#!/bin/sh\nset -eu\nstem=${3%.eqy}\n"
        "d=\"$stem/strategies/test.tl_o.65/smt_fast\"\nmkdir -p \"$d\"\n"
        "target='strategies/test.tl_o.65/smt_fast/status'\n"
        "printf '%s\\n' \"$target\" > \"$stem/summary_targets.list\"\n"
        "printf '%s:\\n\\t@printf \"PASS\\\\n\" > %s\\n' \"$target\" \"$target\" > \"$stem/strategies.mk\"\n",
        encoding="utf-8",
    )
    fake_eqy.chmod(0o755)

    probe = run_synthesis_boundary_diagnostics(
        result, top="test", syn_dir=mapped.parent, partition="test.tl_o.65",
        eqy=str(fake_eqy)
    )
    for stage_name in ("generic", "dffmap", "abc", "clean"):
        stage = probe["stages"][stage_name]
        assert stage["valid"] is True
        assert stage["status"] == "PASS"
        rewritten = Path(stage["config"]).read_text(encoding="utf-8")
        assert f"read_rtlil {mapped.parent / ('test_' + stage_name + '.il')}" in rewritten
        assert f"read_verilog {mapped}" not in rewritten
        assert "read_liberty cells.lib" in rewritten
        assert "read_verilog clock_gate.v" in rewritten


def test_eqy_debug_caps_large_failure_lists(tmp_path: Path, monkeypatch, capsys) -> None:
    """A broken match policy must not flood the terminal with thousands of rows."""

    workspace = tmp_path / "workspace"
    result = workspace / "runs" / "test" / "dev" / "signoff" / "equivalence" / "sky130" / "rtl_vs_syn" / "test_rtl_vs_syn"
    for index in range(30):
        strategy = result / "strategies" / f"test.out.{index}" / "smt_fast"
        strategy.mkdir(parents=True)
        (strategy / "status").write_text("FAIL\n", encoding="utf-8")
    settings = tmp_path / ".flexsoc" / "settings.json"
    settings.parent.mkdir()
    settings.write_text('{"TOP":"test","RUN_TOP":"test","RUN_ID":"dev","PDK":"sky130"}\n')
    monkeypatch.chdir(tmp_path)

    assert app(["eqy_debug"]) == 0
    output = capsys.readouterr().out
    assert "Showing 24/30 non-PASS partitions" in output
    assert "6 omitted" in output
    assert "test.out.3" in output
    assert "test.out.4" not in output
