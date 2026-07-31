"""EQY configuration generation checks."""

from __future__ import annotations

from dataclasses import replace
from pathlib import Path

from flexsoc.backend.setup_signoff import EquivalenceConfig, generate_equivalence_config, render_eqy


def _cfg(
    tmp_path: Path,
    *,
    multiclock: bool,
    use_sat: bool | None = None,
    use_pdr: bool = True,
    pdk_model: bool = False,
) -> EquivalenceConfig:
    rtl = tmp_path / "rtl.f"
    netlist = tmp_path / "demo_synth.v"
    liberty = tmp_path / "cells.lib"
    model = tmp_path / "cells.v"
    clock_gate = tmp_path / "clock_gate.v"
    rtl.write_text("demo.sv\n")
    netlist.write_text(
        "module demo(clk_i, rst_ni, data_o);\n"
        " input clk_i;\n input rst_ni;\n output [7:0] data_o;\n"
        " wire internal_q;\nendmodule\n"
    )
    liberty.write_text("library(test) {}\n")
    model.write_text("module demo_cell(input A, output X); assign X = A; endmodule\n")
    return EquivalenceConfig(
        top="demo",
        filelists=(rtl,),
        netlist=netlist,
        liberty=liberty,
        cell_models=(model,) if pdk_model else (),
        sky130_clock_gate_model=clock_gate,
        engine="abc pdr -rfi",
        depth=2,
        sat_depth=5,
        output=tmp_path / "demo.eqy",
        timeout=30,
        multiclock=multiclock,
        splitnets="off",
        use_sat=(not multiclock) if use_sat is None else use_sat,
        use_pdr=use_pdr,
        pdr_engine="abc pdr -rfi",
        smt_engine="smtbmc bitwuzla",
        smt_depth=5 if multiclock else 2,
    )


def test_single_clock_eqy_uses_shared_normalization_and_sat_pdr_smt(tmp_path: Path) -> None:
    text = render_eqy(_cfg(tmp_path, multiclock=False))
    assert "splitnets off" in text
    assert "[script]\nhierarchy -check -top demo\nproc\nprep -top demo -flatten\nmemory -nomap\nasync2sync\n" in text
    assert text.count("prep -top demo") == 1
    assert "memory_map" not in text
    assert "[strategy sat]\nuse sat\ndepth 5" in text
    assert "[strategy pdr]\nuse sby\nengine abc pdr -rfi" in text
    assert "[strategy smt]\nuse sby\nengine smtbmc bitwuzla\ndepth 2" in text
    assert "[strategy smt_fast]" not in text
    assert "[strategy smt_deep]" not in text


def test_multiclock_eqy_keeps_pdr_smt_and_multiclock_option(tmp_path: Path) -> None:
    text = render_eqy(_cfg(tmp_path, multiclock=True))
    assert "[strategy sat]" not in text
    assert "[strategy pdr]" in text
    assert "[strategy smt]" in text
    assert "depth 5" in text
    assert text.count("option multiclock on") == 2


def test_single_clock_sat_can_be_disabled_explicitly(tmp_path: Path) -> None:
    text = render_eqy(_cfg(tmp_path, multiclock=False, use_sat=False))
    assert "[strategy sat]" not in text
    assert "[strategy pdr]" in text
    assert "[strategy smt]" in text


def test_eqy_matches_only_top_ports_without_joining_vectors(tmp_path: Path) -> None:
    text = render_eqy(_cfg(tmp_path, multiclock=False))
    assert "[match demo]\nnodefault\n" in text
    for port in ("clk_i", "rst_ni", "data_o"):
        assert f"gold-match {port}\n" in text
    assert "gold-match internal_q" not in text
    assert "[collect demo]" not in text
    assert "join *" not in text


def test_non_sky130_gate_prefers_functional_verilog_models(tmp_path: Path, monkeypatch) -> None:
    monkeypatch.setenv("FLEXSOC_PDK", "ihp-sg13g2")
    cfg = _cfg(tmp_path, multiclock=False, pdk_model=True)
    text = render_eqy(cfg)
    model = cfg.cell_models[0].resolve()
    assert f"read_verilog -formal -sv -DFUNCTIONAL {model}" in text
    assert "read_liberty -ignore_miss_func" not in text
    assert f"read_verilog -formal -sv {cfg.netlist.resolve()}" in text


def test_sky130_uses_prepared_formal_model_when_available(tmp_path: Path, monkeypatch) -> None:
    monkeypatch.setenv("FLEXSOC_PDK", "sky130")
    cfg = _cfg(tmp_path, multiclock=False, pdk_model=True)
    formal = tmp_path / "formal_pdk.v"
    formal.write_text("module demo_cell(input A, output X); assign X = A; endmodule\n")
    cfg = replace(cfg, formal_cell_model=formal)
    text = render_eqy(cfg)
    assert f"read_verilog -formal -sv {formal}" in text
    assert "read_liberty -ignore_miss_func" not in text



def test_sky130_without_formal_adapter_falls_back_to_liberty(tmp_path: Path, monkeypatch) -> None:
    monkeypatch.setenv("FLEXSOC_PDK", "sky130")
    monkeypatch.setattr("flexsoc.backend.setup_signoff.shutil.which", lambda name: None)
    cfg = _cfg(tmp_path, multiclock=False, pdk_model=True)
    path = generate_equivalence_config(cfg)
    text = path.read_text()
    assert not (tmp_path / "formal_pdk.v").exists()
    assert f"read_liberty -ignore_miss_func {cfg.liberty.resolve()}" in text


def test_sky130_generation_uses_explicit_formal_adapter(tmp_path: Path, monkeypatch) -> None:
    monkeypatch.setenv("FLEXSOC_PDK", "sky130")
    processor = tmp_path / "formal_pdk_proc.py"
    processor.write_text("#!/usr/bin/env python3\n")

    def fake_run(command, **kwargs):
        assert command[0] == str(processor.resolve())
        output = Path(command[command.index("--output") + 1])
        output.write_text("module demo_cell(input A, output X); assign X = A; endmodule\n")
        class Result:
            returncode = 0
            stdout = ""
            stderr = ""
        return Result()

    monkeypatch.setattr("flexsoc.backend.setup_signoff.subprocess.run", fake_run)
    cfg = replace(_cfg(tmp_path, multiclock=False, pdk_model=True), formal_pdk_proc=processor)
    text = generate_equivalence_config(cfg).read_text()
    assert f"read_verilog -formal -sv {tmp_path / 'formal_pdk.v'}" in text
    assert "read_liberty -ignore_miss_func" not in text


def test_sky130_generation_auto_prepares_functional_pdk_model(tmp_path: Path, monkeypatch) -> None:
    monkeypatch.setenv("FLEXSOC_PDK", "sky130")
    monkeypatch.setattr("flexsoc.backend.setup_signoff.shutil.which", lambda name: "/usr/bin/eqy.formal_pdk_proc" if name == "eqy.formal_pdk_proc" else None)

    def fake_run(command, **kwargs):
        output = Path(command[command.index("--output") + 1])
        output.write_text("module demo_cell(input A, output X); assign X = A; endmodule\n")
        class Result:
            returncode = 0
            stdout = ""
            stderr = ""
        return Result()

    monkeypatch.setattr("flexsoc.backend.setup_signoff.subprocess.run", fake_run)
    cfg = _cfg(tmp_path, multiclock=False, pdk_model=True)
    path = generate_equivalence_config(cfg)
    text = path.read_text()
    formal = tmp_path / "formal_pdk.v"
    assert formal.is_file()
    assert f"read_verilog -formal -sv {formal}" in text
    assert "read_liberty -ignore_miss_func" not in text
