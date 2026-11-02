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
    assert not any(node.get("name") == "CASE" for node in graph["nodes"])
    target = next(n for n in graph["nodes"] if n["name"] == "next")
    assert target.get("proceduralStatus")
    incoming = [edge for edge in graph["edges"] if edge["target"] == target["id"]]
    assert not any(edge["rendered"] and edge["type"] == "data" for edge in incoming)
    behavior = RtlDesign(ast, root=Path.cwd(), top="case_top").behavior()
    assert behavior["processes"][0]["assignments"]
