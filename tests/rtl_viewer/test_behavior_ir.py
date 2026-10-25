"""Behavioral IR keeps AST-derived data, predicates and event polarity distinct."""
import json
from pathlib import Path

import pytest
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign


def ref(address):
    return {"kind": "NamedValue", "symbol": f"{address} local"}


def sample():
    declarations = [{"kind": "Variable", "name": name, "addr": i}
                    for i, name in enumerate(("clk", "rst_n", "enable", "data", "q"), 1)]
    assign = {"kind": "Assignment", "left": ref(5), "right": ref(4)}
    process = {"kind": "ProceduralBlock", "procedureKind": "AlwaysFF", "body": {
        "kind": "Timed", "timing": {"kind": "EventList", "events": [
            {"kind": "SignalEvent", "edge": "PosEdge", "expr": ref(1)},
            {"kind": "SignalEvent", "edge": "NegEdge", "expr": ref(2)}]},
        "stmt": {"kind": "Conditional", "conditions": [{"expr": ref(3)}],
                 "ifTrue": assign, "ifFalse": assign}}}
    return {"design": {"members": [{"kind": "Instance", "name": "top", "body": {
        "kind": "InstanceBody", "name": "top", "members": [*declarations, process]}}]}}


def test_typed_roles_and_edge_polarity(tmp_path):
    design = RtlDesign(sample(), root=tmp_path, top="top")
    data = design.behavior()
    assert data["schema"] == "flexsoc.rtl_viewer.behavior.v1"
    assert len(data["processes"]) == 1
    process = data["processes"][0]
    assert process["events"] == [{"source": "clk", "edge": "PosEdge"},
                                 {"source": "rst_n", "edge": "NegEdge"}]
    assert {(d["destination"], d["source"], d["role"]) for d in process["dependencies"]} == {
        ("q", "data", "data"), ("q", "enable", "control"),
        ("q", "clk", "event"), ("q", "rst_n", "event")}
    assert all(d["mapping"] in {"direct", "partial"} for d in process["dependencies"])


def test_real_uart_control_and_event_roles():
    root = Path(__file__).resolve().parents[2]
    ast = root / "workspace/runs/uart/qualification_l2/dv/slang_hier/ast.json"
    if not ast.exists():
        pytest.skip("UART AST integration fixture not included")
    design = RtlDesign(json.loads(ast.read_text()), root=root, top="uart")
    rx = design.behavior("/u_uart_core/uart_rx")
    dependencies = [d for p in rx["processes"] for d in p["dependencies"]]
    assert len(rx["processes"]) == 3
    assert {d["destination"] for d in dependencies
            if d["source"] == "rx_enable" and d["role"] == "control"} == {
                "sreg_d", "bit_cnt_d", "baud_div_d", "tick_baud_d", "idle_d"}
    assert any(d["source"] == "clk_i" and d["role"] == "event" for d in dependencies)
    assert any(d["source"] == "rst_ni" and d["role"] == "event" for d in dependencies)


def test_scope_isolation(tmp_path):
    design = RtlDesign(sample(), root=tmp_path, top="top")
    result = design.behavior()
    assert result["scope"] == "/"
    assert result["semantics"].startswith("conservative behavioral")
