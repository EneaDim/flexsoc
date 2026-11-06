"""Procedural case is control flow, never a free-standing electrical gate.

Check native Slang Case.items shape, compiler-backed enum identities, ordered
blocking updates, NBAs and unsupported case matching without parsing RTL text.
"""
from __future__ import annotations

import json
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.lowering import ProcessLowerer


def ref(addr):
    return {"kind": "NamedValue", "symbol": f"{addr} compiler_symbol"}


def lit(value):
    return {"kind": "IntegerLiteral", "type": "logic[2:0]", "value": value}


def assignment(dst, value, *, nba=False):
    return {"kind": "ExpressionStatement", "expr": {
        "kind": "Assignment", "isNonBlocking": nba,
        "left": ref(dst), "right": value}}


def case_process(*, condition="Normal", include_default=True):
    member = [
        {"kind": "Variable", "name": "state", "addr": 101},
        {"kind": "Variable", "name": "next", "addr": 102},
        {"kind": "Variable", "name": "d", "addr": 103},
        {"kind": "EnumType", "name": "mode_e", "members": [
            {"kind": "EnumValue", "name": "IDLE", "addr": 201, "value": "3'b0"},
            {"kind": "EnumValue", "name": "READY", "addr": 202, "value": "3'b1"},
        ]},
    ]
    case = {"kind": "Case", "condition": condition, "check": "Unique",
            "expr": ref(101), "items": [
        {"expressions": [ref(201)], "stmt": assignment(102, ref(103))},
        {"expressions": [ref(202), lit("3'b10")],
         "stmt": assignment(102, ref(101))},
    ]}
    if include_default:
        case["defaultCase"] = assignment(102, lit("3'b111"))
    member.append({"kind": "ProceduralBlock", "procedureKind": "AlwaysComb",
                   "body": {"kind": "Block", "body": {"kind": "List", "list": [
                       assignment(102, lit("3'b0")), case
                   ]}}})
    return member


def test_normal_case_emits_ordered_symbolic_next_value():
    members = case_process()
    lowered = ProcessLowerer(members, {"state", "next", "d"}).lower(members[-1], 0)
    assert lowered["status"] == "supported", lowered["diagnostics"]
    value = lowered["blocking_final"]["next"]
    assert value["op"] == "select"
    assert value["condition"]["op"] == "case_match_any"
    assert value["condition"]["patterns"][0]["value"] == "3'b0"
    assert value["true"] == {"op": "ref", "name": "d"}
    assert len(value["false"]["condition"]["patterns"]) == 2
    assert value["false"]["false"]["value"] == "3'b111"


def test_case_without_default_preserves_previous_value():
    members = case_process(include_default=False)
    lowered = ProcessLowerer(members, {"state", "next", "d"}).lower(members[-1], 0)
    assert lowered["status"] == "supported"
    assert lowered["blocking_final"]["next"]["false"]["false"]["value"] == "3'b0"


def test_unsupported_wildcard_case_never_exposes_partial_state():
    members = case_process(condition="WildcardXOrZ")
    lowered = ProcessLowerer(members, {"state", "next", "d"}).lower(members[-1], 0)
    assert lowered["status"] == "unsupported"
    assert lowered["blocking_final"] == {}
    assert lowered["scheduled_nba"] == {}


def test_malformed_case_arm_fails_closed():
    members = case_process()
    members[-1]["body"]["body"]["list"][1]["items"][0]["expressions"] = []
    lowered = ProcessLowerer(members, {"state", "next", "d"}).lower(members[-1], 0)
    assert lowered["status"] == "unsupported"
    assert not lowered["blocking_final"]


def test_native_case_evidence_has_no_fictitious_electrical_block():
    """Small compiled-style AST, same Case.items as the genuine Ethernet AST."""
    members = case_process()
    body = {"kind": "InstanceBody", "name": "case_top", "members": members}
    ast = {"design": {"members": [{"kind": "Instance", "name": "case_top",
                                   "body": body}]}}
    graph = RtlDesign(ast, root=Path.cwd(), top="case_top").diagram()
    target = next(n for n in graph["nodes"] if n["name"] == "next")
    # The supported ordered case is now translated into one physical value
    # cone rather than suppressing all of its assignment candidates.
    assert not target.get("proceduralStatus")
    incoming = [edge for edge in graph["edges"] if edge["target"] == target["id"]]
    physical = [edge for edge in incoming if edge["rendered"] and edge["type"] == "data"]
    assert len(physical) == 1
    assert physical[0]["source"].startswith("/::op:")
    muxes = [node for node in graph["nodes"] if node.get("shape") == "mux"]
    assert len(muxes) == 2
    matches = [node for node in graph["nodes"] if node.get("kind") == "CaseMatch"]
    assert len(matches) == 2
    assert all(node.get("shape") == "case" for node in matches)
    assert {tuple(m["literalOperands"]["patterns"]) for m in matches} == {
        ("3'b0",), ("3'b1", "3'b10")}
    assert any(m.get("controlBadge") == "CASE" and m.get("controlSource") == "state"
               for m in matches)
    assert any(m.get("controlBadge") == "CASE" and m.get("controlSource") == "state"
               for m in muxes)
    for operator in (*muxes, *matches):
        for pin in ("A", "B", "S") if operator.get("shape") == "mux" else ("A",):
            feeds = [e for e in graph["edges"] if e["target"] == operator["id"]
                     and e["pin"] == pin and e["rendered"]]
            assert len(feeds) == 1, (operator["id"], pin, feeds)
    behavior = RtlDesign(ast, root=Path.cwd(), top="case_top").behavior()
    assert behavior["processes"][0]["assignments"]


def test_case_item_body_alias_preserves_conditional_write():
    members = case_process()
    case = members[-1]["body"]["body"]["list"][1]
    item = case["items"][0]
    item["body"] = item.pop("stmt")
    lowered = ProcessLowerer(members, {"state", "next", "d"}).lower(members[-1], 0)
    assert lowered["status"] == "supported", lowered["diagnostics"]
    value = lowered["blocking_final"]["next"]
    assert value["condition"]["op"] == "case_match_any"
    assert value["true"] == {"op": "ref", "name": "d"}


def test_missing_case_body_fails_closed_instead_of_losing_write():
    members = case_process()
    case = members[-1]["body"]["body"]["list"][1]
    case["items"][0].pop("stmt")
    lowered = ProcessLowerer(members, {"state", "next", "d"}).lower(members[-1], 0)
    assert lowered["status"] == "unsupported"
    assert lowered["blocking_final"] == {}
    assert lowered["scheduled_nba"] == {}


def test_ambiguous_case_arm_aliases_fail_closed():
    members = case_process()
    item = members[-1]["body"]["body"]["list"][1]["items"][0]
    item["body"] = assignment(102, lit("3'b100"))
    lowered = ProcessLowerer(members, {"state", "next", "d"}).lower(members[-1], 0)
    assert lowered["status"] == "unsupported"
    assert lowered["blocking_final"] == {}


def test_registered_enum_case_propagates_fsm_badge_to_value_muxes():
    members = [
        {"kind": "EnumType", "name": "state_e", "members": [
            {"kind": "EnumValue", "name": "IDLE", "addr": 201, "value": "2'b00"},
            {"kind": "EnumValue", "name": "PAYLOAD", "addr": 202, "value": "2'b01"},
        ]},
        {"kind": "Variable", "name": "clk", "addr": 1},
        {"kind": "Variable", "name": "state_reg", "addr": 2, "type": {"kind": "EnumType", "text": "enum state_e"}},
        {"kind": "Variable", "name": "state_next", "addr": 3, "type": {"kind": "EnumType", "text": "enum state_e"}},
        {"kind": "Variable", "name": "error_bad_fcs_next", "addr": 4},
        {"kind": "Variable", "name": "flag", "addr": 5},
        {"kind": "ProceduralBlock", "procedureKind": "AlwaysFF", "body": {
            "kind": "Timed", "timing": {"kind": "SignalEvent", "edge": "PosEdge", "expr": ref(1)},
            "stmt": assignment(2, ref(3), nba=True)}},
        {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "body": {"kind": "Block", "body": {"kind": "List", "list": [
            assignment(4, {"kind": "IntegerLiteral", "type": "logic", "value": "1'b0"}),
            {"kind": "Case", "condition": "Normal", "expr": ref(2), "items": [
                {"expressions": [ref(202)], "stmt": {"kind": "Block", "body": {"kind": "List", "list": [
                    {"kind": "Conditional", "conditions": [{"expr": ref(5)}], "ifTrue": assignment(4, {"kind": "IntegerLiteral", "type": "logic", "value": "1'b1"})}
                ]}}}
            ]}
        ]}}}
    ]
    body = {"kind": "InstanceBody", "name": "fsm_top", "members": members}
    ast = {"design": {"members": [{"kind": "Instance", "name": "fsm_top", "body": body}]}}
    graph = RtlDesign(ast, root=Path.cwd(), top="fsm_top").diagram(limit=96)
    state = next(n for n in graph["nodes"] if n["name"] == "state_reg")
    assert state["type"] == "fsm"
    muxes = [node for node in graph["nodes"] if node.get("shape") == "mux"]
    assert any(node.get("controlBadge") == "FSM" and node.get("controlSource") == "state_reg"
               for node in muxes)
    matches = [node for node in graph["nodes"] if node.get("kind") == "CaseMatch"]
    assert any(node.get("controlBadge") == "FSM" and node.get("controlSource") == "state_reg"
               for node in matches)
