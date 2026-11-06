"""Graph contract at the ProcessLowerer → layout boundary.

These checks do not equate a control dependency to an electrical wire.
"""
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.procedural_value_graph import (
    UnrepresentableValue, project_value,
)


def ref(name):
    return {"op": "ref", "name": name}


def lit(value):
    return {"op": "literal", "value": value}


def test_prioritized_select_has_one_driver_per_pin():
    value = {"op": "select", "condition": ref("enable"), "true": ref("d"),
             "false": lit("1'b0")}
    nodes, edges = project_value(value, "out", {"enable", "d", "out"}, start=16)
    assert nodes[0]["key"] == "op:16"
    assert nodes[0]["shape"] == "mux"
    assert {(e["pin"], e["source"]) for e in edges if e["target"] == "op:16"} == {
        ("S", "enable"), ("A", "d"), ("B", "op:17")}
    assert edges[-1]["source"] == "op:16" and edges[-1]["target"] == "out"
    assert len({n["key"] for n in nodes}) == len(nodes)


@pytest.mark.parametrize("expr", [
    ref("out"),
    {"op": "select", "condition": ref("out"), "true": ref("d"), "false": lit("0")},
    {"op": "case_match_any", "selector": ref("d"), "patterns": [ref("enable")],
     "semantics": "SystemVerilog four-state case equality"},
    {"op": "case_match_any", "selector": ref("d"), "patterns": [lit("1'b1")],
     "semantics": "WildcardXOrZ"},
    {"op": "update", "base": ref("d"), "value": lit("1")},
])
def test_unsupported_expression_fails_closed(expr):
    with pytest.raises(UnrepresentableValue):
        project_value(expr, "out", {"enable", "d", "out"}, start=0)


def test_bounded_projection_does_not_return_half_a_mux():
    expr = {"op": "select", "condition": ref("enable"), "true": ref("d"),
            "false": lit("0")}
    with pytest.raises(UnrepresentableValue):
        project_value(expr, "out", {"enable", "d", "out"}, start=0, max_nodes=1)


def test_case_without_default_cannot_invent_implicit_latch_driver():
    expr = {"op": "select", "condition": ref("enable"), "true": ref("d"),
            "false": ref("out")}
    with pytest.raises(UnrepresentableValue):
        project_value(expr, "out", {"enable", "d", "out"}, start=0)


def test_case_graph_truncation_is_atomic():
    declarations = [
        {"kind": "Variable", "name": name, "addr": i}
        for i, name in [(1, "sel"), (2, "data"), (3, "out")]
    ]
    def ref_ast(i):
        return {"kind": "NamedValue", "symbol": f"{i} local"}
    def assign(rhs):
        return {"kind": "Assignment", "left": ref_ast(3), "right": rhs}
    process = {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb",
               "body": {"kind": "Block", "body": [
                   assign({"kind": "IntegerLiteral", "value": "1'b0"}),
                   {"kind": "Case", "condition": "Normal", "expr": ref_ast(1),
                    "items": [{"expressions": [{"kind": "IntegerLiteral", "value": "1'b1"}],
                               "stmt": assign(ref_ast(2))}]}
               ]}}
    ast = {"design": {"members": [{"kind": "Instance", "name": "demo",
                                   "body": {"kind": "InstanceBody", "name": "demo",
                                            "members": declarations + [process]}}]}}
    design = RtlDesign(ast, root=Path.cwd(), top="demo")
    small = design.diagram(limit=4)
    assert not any(node.get("origin") == "ProcessLowerer" for node in small["nodes"])
    assert not any(e["rendered"] and e["target"].endswith("sig:out") for e in small["edges"])
    large = design.diagram(limit=64)
    assert any(node.get("origin") == "ProcessLowerer" for node in large["nodes"])
    assert len([e for e in large["edges"] if e["rendered"] and
                e["target"].endswith("sig:out")]) == 1
    assert len(large["nodes"]) <= 64


def test_superseded_operator_pruning_respects_shared_live_consumers():
    from flexsoc.backend.dv.rtl_viewer.procedural_value_graph import prune_superseded_operators
    operators = [{"key": "op:0"}, {"key": "op:1"}, {"key": "op:2"}]
    edges = [
        {"source": "op:0", "target": "out", "rendered": False,
         "proceduralStatus": "superseded by ordered ProcessLowerer value"},
        {"source": "op:1", "target": "op:0", "rendered": True},
        {"source": "op:2", "target": "op:1", "rendered": True},
        {"source": "op:2", "target": "another_out", "rendered": True},
    ]
    prune_superseded_operators(operators, edges, {"op:0", "op:1", "op:2"})
    assert {n["key"] for n in operators} == {"op:2"}
    assert len(edges) == 1 and edges[0]["target"] == "another_out"


def test_case_projection_exposes_case_operator_and_mux_control_metadata():
    value = {
        "op": "select",
        "condition": {"op": "case_match_any", "selector": ref("state_reg"),
                       "patterns": [lit("2'b01")],
                       "semantics": "SystemVerilog four-state case equality"},
        "true": lit("1'b1"),
        "false": lit("1'b0"),
    }
    nodes, edges = project_value(value, "flag", {"state_reg", "flag"}, start=9)
    matcher = next(node for node in nodes if node["kind"] == "CaseMatch")
    mux = next(node for node in nodes if node["shape"] == "mux")
    assert matcher["shape"] == "case"
    assert matcher["casePatterns"] == ["2'b01"]
    assert mux["controlKind"] == "case"
    assert mux["controlSource"] == "state_reg"
    assert mux["controlPatterns"] == ["2'b01"]
    assert any(e["target"] == "op:9" and e["source"] == "op:10" for e in edges)


def test_concatenated_comparison_preserves_independent_ordered_inputs():
    value = {"op": "BinaryOp", "operator": "Equality", "args": [
        {"op": "concatenation", "type": "logic[15:0]", "parts": [ref("hi"), ref("lo")]},
        ref("expect"),
    ]}
    operators, edges = project_value(value, "match", {"hi", "lo", "expect", "match"}, start=5)
    concat = next(n for n in operators if n["kind"] == "Concatenation")
    assert concat["pins"] == ["I0", "I1", "Y"]
    data = {(edge["pin"], edge["source"]) for edge in edges if edge["target"] == concat["key"]}
    assert data == {("I0", "hi"), ("I1", "lo")}
    assert any(edge["source"] == concat["key"] and edge["target"] == "op:5" for edge in edges)
    assert len([edge for edge in edges if edge["target"] == "match"]) == 1
