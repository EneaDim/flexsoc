"""Transparent lvalue wrappers must preserve Slang-indexed write semantics."""
from flexsoc.backend.dv.rtl_viewer.lowering import ProcessLowerer


def ref(addr):
    return {"kind": "NamedValue", "symbol": f"{addr} compiler_symbol"}


def block(lhs):
    members = [
        {"kind": "Variable", "addr": 101, "name": "buffer"},
        {"kind": "Variable", "addr": 102, "name": "index"},
        {"kind": "Variable", "addr": 103, "name": "data"},
    ]
    process = {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "body": {
        "kind": "Block", "body": {"kind": "List", "list": [
            {"kind": "ExpressionStatement", "expr": {"kind": "Assignment",
             "isNonBlocking": False, "left": lhs, "right": ref(103)}}
        ]}}}
    members.append(process)
    return ProcessLowerer(members, {"buffer", "index", "data"}).lower(process, 0)


def test_parenthesized_indexed_lvalue_preserves_address_read_and_update():
    lhs = {"kind": "ParenthesizedExpression", "expression": {
        "kind": "ElementSelect", "value": ref(101), "selector": ref(102)}}
    result = block(lhs)
    assert result["status"] == "supported", result["diagnostics"]
    assert result["blocking_final"]["buffer"] == {
        "op": "update", "base": {"op": "ref", "name": "buffer"},
        "path": [{"kind": "element", "index": {"op": "ref", "name": "index"}}],
        "value": {"op": "ref", "name": "data"},
    }
    assert "index" not in result["blocking_final"]


def test_nested_parenthesized_lvalue_is_transparent():
    lhs = {"kind": "ParenthesizedExpression", "operand": {
        "kind": "ParenthesizedExpression", "expression": ref(101)}}
    result = block(lhs)
    assert result["status"] == "supported", result["diagnostics"]
    assert result["blocking_final"] == {"buffer": {"op": "ref", "name": "data"}}


def test_invalid_parenthesized_destination_fails_closed():
    result = block({"kind": "ParenthesizedExpression"})
    assert result["status"] == "unsupported"
    assert result["blocking_final"] == {}
