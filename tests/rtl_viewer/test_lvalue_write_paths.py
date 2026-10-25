"""Semantic write paths retain identity, selection order and procedural state."""
from flexsoc.backend.dv.rtl_viewer.lowering import ProcessLowerer


def ref(i):
    return {"kind": "NamedValue", "symbol": f"{i} signal"}


def lit(v):
    return {"kind": "IntegerLiteral", "value": str(v)}


def assign(lhs, rhs, nba=False):
    return {"kind": "Assignment", "left": lhs, "right": rhs, "isNonBlocking": nba}


def lower(*statements):
    members = [{"kind": "Variable", "addr": i, "name": n}
               for i, n in enumerate(("q", "a", "i", "sel", "out"), 1)]
    return ProcessLowerer(members, {m["name"] for m in members}).lower(
        {"body": {"kind": "Block", "body": list(statements)}}, 0)


def element(base, index):
    return {"kind": "ElementSelect", "value": base, "selector": index}


def test_partial_blocking_update_feeds_later_read():
    result = lower(assign(element(ref(1), ref(3)), ref(2)), assign(ref(5), ref(1)))
    assert result["status"] == "supported"
    update = result["blocking_final"]["q"]
    assert update == {"op": "update", "base": {"op": "ref", "name": "q"},
                      "path": [{"kind": "element", "index": {"op": "ref", "name": "i"}}],
                      "value": {"op": "ref", "name": "a"}}
    assert result["blocking_final"]["out"] == update


def test_multiple_nba_partial_writes_do_not_change_immediate_read():
    result = lower(assign(element(ref(1), lit(0)), lit(1), True),
                   assign(element(ref(1), lit(1)), lit(0), True),
                   assign(ref(5), ref(1)))
    assert result["status"] == "supported"
    assert result["blocking_final"]["out"] == {"op": "ref", "name": "q"}
    update = result["scheduled_nba"]["q"]
    assert update["op"] == "update" and update["base"]["op"] == "update"
    assert update["base"]["base"] == {"op": "ref", "name": "q"}


def test_range_and_nested_member_paths():
    member = {"kind": "MemberAccess", "value": ref(1), "member": "123 field"}
    span = {"kind": "RangeSelect", "value": member, "left": lit(7), "right": lit(4),
            "selectionKind": "Simple"}
    result = lower(assign(span, ref(2)))
    assert result["status"] == "supported"
    assert [p["kind"] for p in result["blocking_final"]["q"]["path"]] == ["member", "range"]


def test_partial_write_in_conditional_preserves_previous_value():
    result = lower({"kind": "Conditional", "conditions": [{"expr": ref(4)}],
                    "ifTrue": assign(element(ref(1), lit(0)), lit(1))})
    assert result["status"] == "supported"
    assert result["blocking_final"]["q"]["op"] == "select"
    assert result["blocking_final"]["q"]["false"] == {"op": "ref", "name": "q"}


def test_unknown_target_fails_closed():
    result = lower(assign(element(ref(999), lit(0)), lit(1)))
    assert result["status"] == "unsupported" and result["blocking_final"] == {}


def test_concatenated_write_splits_using_elaborated_widths():
    left = {"kind": "Concatenation", "type": "logic[4:0]", "operands": [
        {**ref(1), "type": "logic"}, {**ref(5), "type": "logic[3:0]"}]}
    result = lower(assign(left, ref(2), True))
    assert result["status"] == "supported"
    assert result["scheduled_nba"]["q"]["lsb"] == 4
    assert result["scheduled_nba"]["q"]["width"] == 1
    assert result["scheduled_nba"]["out"]["lsb"] == 0
    assert result["scheduled_nba"]["out"]["width"] == 4


def test_concatenated_write_rejects_unknown_widths():
    result = lower(assign({"kind": "Concatenation", "operands": [ref(1), ref(5)]}, ref(2)))
    assert result["status"] == "unsupported"
