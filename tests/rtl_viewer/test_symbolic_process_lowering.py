"""Semantic invariants of the bounded process lowerer."""
from flexsoc.backend.dv.rtl_viewer.lowering import ProcessLowerer


def ref(i):
    return {"kind": "NamedValue", "symbol": f"{i} local"}


def assign(dst, rhs, nba=False):
    return {"kind": "Assignment", "left": ref(dst), "right": rhs, "isNonBlocking": nba}


def analyzer():
    members = [{"kind": "Variable", "name": name, "addr": i}
               for i, name in enumerate(("sel", "a", "b", "q", "t"), 1)]
    return ProcessLowerer(members, {m["name"] for m in members})


def test_blocking_read_uses_updated_value():
    block = {"body": {"kind": "Block", "body": [assign(5, ref(2)), assign(4, ref(5))]}}
    result = analyzer().lower(block, 0)
    assert result["status"] == "supported"
    assert result["blocking_final"]["q"] == {"op": "ref", "name": "a"}


def test_nba_read_uses_previous_value():
    block = {"body": {"kind": "Block", "body": [assign(5, ref(2), True), assign(4, ref(5), True)]}}
    result = analyzer().lower(block, 0)
    assert result["scheduled_nba"]["t"] == {"op": "ref", "name": "a"}
    assert result["scheduled_nba"]["q"] == {"op": "ref", "name": "t"}


def test_branch_merging_creates_a_select_and_preserves_default():
    block = {"body": {"kind": "Conditional", "conditions": [{"expr": ref(1)}],
                      "ifTrue": assign(4, ref(2)), "ifFalse": assign(4, ref(3))}}
    result = analyzer().lower(block, 0)
    assert result["blocking_final"]["q"] == {
        "op": "select", "condition": {"op": "ref", "name": "sel"},
        "true": {"op": "ref", "name": "a"}, "false": {"op": "ref", "name": "b"}}


def test_nba_branch_override_preserves_previous_scheduled_assignment():
    block = {"body": {"kind": "Block", "body": [
        assign(4, ref(2), True),
        {"kind": "Conditional", "conditions": [{"expr": ref(1)}], "ifTrue": assign(4, ref(3), True)}]}}
    result = analyzer().lower(block, 0)
    assert result["scheduled_nba"]["q"]["false"] == {"op": "ref", "name": "a"}


def test_unsupported_cases_fail_closed():
    block = {"body": {"kind": "Block", "body": [assign(4, ref(2)), {"kind": "Case"}]}}
    result = analyzer().lower(block, 0)
    assert result["status"] == "unsupported"
    assert result["blocking_final"] == {}
    assert result["diagnostics"]


def test_unknown_symbol_fails_closed():
    result = analyzer().lower({"body": assign(4, ref(999))}, 0)
    assert result["status"] == "unsupported"
