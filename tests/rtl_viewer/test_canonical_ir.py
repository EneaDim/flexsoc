"""Cross-projection contract checks, including actual elaborated UART."""
import json
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from test_slang_reference_identity import ast_fixture


def test_canonical_does_not_confuse_electrical_nets_and_dependencies(tmp_path):
    payload = RtlDesign(ast_fixture(), root=tmp_path, top="top").canonical()
    assert payload["schema"] == "flexsoc.rtl_viewer.canonical.v1"
    assert payload["integrity"] == {"status": "ok", "diagnostics": []}
    assert len(payload["structure"]["instances"]) == 2
    assert len(payload["structure"]["nets"][0]["terminals"]) == 2
    assert payload["behavior"]["processes"] == payload["values"]["processes"] == []


def test_detects_missing_bound_terminal(tmp_path):
    from flexsoc.backend.dv.rtl_viewer.canonical import CanonicalCircuit
    circuit = CanonicalCircuit(RtlDesign(ast_fixture(), root=tmp_path, top="top"), "/")
    circuit.structure["nets"][0]["terminals"].clear()
    circuit.diagnostics.clear()
    circuit._validate()
    assert any(d["kind"] == "missing_binding" for d in circuit.diagnostics)


def test_actual_uart_cross_projection():
    root = Path(__file__).resolve().parents[2]
    source = root / "workspace/runs/uart/qualification_l2/dv/slang_hier/ast.json"
    if not source.exists():
        pytest.skip("real UART AST not provided")
    design = RtlDesign(json.loads(source.read_text()), root=root, top="uart")
    top = design.canonical()
    assert top["integrity"]["status"] == "ok", top["integrity"]["diagnostics"]
    assert len(top["structure"]["instances"]) == 4
    assert {i["name"] for i in top["structure"]["instances"]} == {
        "u_reg_reset_sync", "u_core_reset_sync", "u_uart_reg", "u_uart_core"}
    for name, count in (("clk_i", 4), ("rst_ni", 2)):
        net = next(n for n in top["structure"]["nets"] if n["name"] == name)
        assert len(net["terminals"]) == count
    rx_path = next(path for path, scope in design.scopes.items() if scope.module == "uart_rx")
    rx = design.canonical(rx_path)
    assert rx["integrity"]["status"] == "ok", rx["integrity"]["diagnostics"]
    assert rx["values"]["processes"]
