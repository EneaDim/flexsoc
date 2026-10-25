"""Slang AST process controls must never disappear from schematic connectivity."""
from pathlib import Path
import json

from flexsoc.backend.dv.rtl_viewer.model import RtlDesign


def ref(address):
    return {"kind": "NamedValue", "symbol": f"{address} source_alias"}


def assignment(destination, source):
    return {"kind": "Assignment", "left": ref(destination), "right": ref(source)}


def diagram(members):
    ast = {"design": {"members": [{"kind": "Instance", "name": "dut", "body": {
        "kind": "InstanceBody", "name": "dut", "members": members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top="dut").diagram()


def signal(name, address):
    return {"kind": "Variable", "name": name, "addr": address}


def test_nested_if_and_case_propagate_predicates_not_only_rhs():
    members = [signal(name, i) for i, name in enumerate(("enable", "mode", "data", "result"), 1)]
    process = {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "body": {
        "kind": "Conditional", "conditions": [{"expr": ref(1)}],
        "ifTrue": {"kind": "Case", "expr": ref(2), "items": [assignment(4, 3)]},
        "ifFalse": assignment(4, 3)}}
    graph = diagram([*members, process])
    pairs = {(e["source"].split("::")[-1], e["target"].split("::")[-1], e["type"])
             for e in graph["edges"]}
    assert ("sig:enable", "sig:result", "control") in pairs
    assert ("sig:mode", "sig:result", "control") in pairs
    assert ("sig:data", "sig:result", "data") in pairs


def test_clock_edges_and_conditionals_reach_sequential_targets():
    members = [signal(name, i) for i, name in enumerate(("clock", "reset_n", "data", "q"), 1)]
    block = {"kind": "ProceduralBlock", "procedureKind": "AlwaysFF", "body": {
        "kind": "Timed", "timing": {"kind": "EventList", "events": [
            {"kind": "SignalEvent", "edge": "PosEdge", "expr": ref(1)},
            {"kind": "SignalEvent", "edge": "NegEdge", "expr": ref(2)}]},
        "stmt": {"kind": "Conditional", "conditions": [{"expr": ref(2)}],
                 "ifTrue": assignment(4, 3), "ifFalse": assignment(4, 3)}}}
    graph = diagram([*members, block])
    pairs = {(e["source"].split("::")[-1], e["target"].split("::")[-1], e["type"])
             for e in graph["edges"]}
    assert ("sig:clock", "sig:q", "event") in pairs
    assert ("sig:reset_n", "sig:q", "event") in pairs
    assert ("sig:reset_n", "sig:q", "control") in pairs


def test_real_uart_rx_controls_are_not_lost():
    root = Path(__file__).resolve().parents[2]
    path = root / "workspace/runs/uart/qualification_l2/dv/slang_hier/ast.json"
    if not path.is_file():
        import pytest
        pytest.skip("integration AST not present in minimal checkout")
    design = RtlDesign(json.loads(path.read_text()), root=root, top="uart")
    graph = design.diagram("/u_uart_core/uart_rx", limit=1500)
    outputs = lambda signal: [e for e in graph["edges"] if e["source"].endswith("sig:" + signal)]
    assert any(e["type"] == "control" for e in outputs("rx_enable"))
    assert any(e["type"] == "event" for e in outputs("clk_i"))
    assert any(e["type"] == "event" for e in outputs("rst_ni"))
