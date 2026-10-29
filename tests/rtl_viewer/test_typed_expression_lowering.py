"""Slang elaborated expression nodes must not lose their type or selectors."""
from flexsoc.backend.dv.rtl_viewer.lowering import ProcessLowerer


def lower(rhs):
    members = [{"kind": "Variable", "addr": n, "name": name}
               for n, name in [(1, "q"), (2, "a"), (3, "idx")]]
    block = {"body": {"kind": "Assignment", "left": {"kind": "NamedValue", "symbol": "1 q"},
                      "right": rhs}}
    return ProcessLowerer(members, {"q", "a", "idx"}).lower(block, 0)


def ref(n):
    return {"kind": "NamedValue", "symbol": f"{n} signal"}


def test_conversion_preserves_slang_type_and_operand():
    result = lower({"kind": "Conversion", "type": "logic[7:0]", "operand": ref(2)})
    assert result["status"] == "supported"
    assert result["blocking_final"]["q"] == {"op": "conversion", "type": "logic[7:0]",
                                             "operand": {"op": "ref", "name": "a"}}


def test_dynamic_selector_remains_symbolic_and_typed():
    result = lower({"kind": "ElementSelect", "type": "logic", "value": ref(2), "selector": ref(3)})
    assert result["blocking_final"]["q"] == {"op": "element_select", "type": "logic",
                                             "base": {"op": "ref", "name": "a"},
                                             "index": {"op": "ref", "name": "idx"}}


def test_range_selection_preserves_declared_kind():
    def lit(n):
        return {"kind": "IntegerLiteral", "value": str(n)}
    result = lower({"kind": "RangeSelect", "type": "logic[3:0]", "selectionKind": "Simple",
                    "value": ref(2), "left": lit(7), "right": lit(4)})
    assert result["status"] == "supported"
    expr = result["blocking_final"]["q"]
    assert expr["op"] == "range_select" and expr["type"] == "logic[3:0]"
    assert expr["left"]["value"] == "7" and expr["right"]["value"] == "4"


def test_member_access_preserves_symbol_identity():
    result = lower({"kind": "MemberAccess", "type": "logic", "member": "123 valid", "value": ref(2)})
    assert result["blocking_final"]["q"]["member"] == "123 valid"


def test_unknown_conversion_type_fails_closed():
    result = lower({"kind": "Conversion", "operand": ref(2)})
    assert result["status"] == "unsupported" and result["blocking_final"] == {}


def test_partial_write_is_preserved_as_symbolic_update():
    result = ProcessLowerer([{"kind":"Variable","addr":1,"name":"q"}], {"q"}).lower(
        {"body": {"kind": "Assignment", "left": {"kind":"ElementSelect",
         "value": {"kind":"NamedValue","symbol":"1 q"},
         "selector":{"kind":"IntegerLiteral","value":"0"}},
         "right":{"kind":"IntegerLiteral","value":"1"}}}, 0)
    assert result["status"] == "supported"
    assert result["blocking_final"]["q"]["op"] == "update"
