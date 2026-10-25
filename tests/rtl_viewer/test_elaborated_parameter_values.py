"""Parameter identity is compile-time data, never an electrical net."""
from flexsoc.backend.dv.rtl_viewer.lowering import ProcessLowerer


def ref(addr, name):
    return {"kind": "NamedValue", "symbol": f"{addr} {name}"}


def test_parameter_read_is_a_typed_elaborated_literal():
    members = [
        {"kind": "Variable", "addr": 10, "name": "q"},
        {"kind": "Parameter", "addr": 20, "name": "ResetValue", "type": "logic[3:0]", "value": "4'b1010"},
    ]
    block = {"body": {"kind": "Assignment", "left": ref(10, "q"),
                      "right": ref(20, "ResetValue")}}
    result = ProcessLowerer(members, {"q"}).lower(block, 0)
    assert result["status"] == "supported"
    assert result["blocking_final"]["q"] == {
        "op": "literal", "value": "4'b1010", "type": "logic[3:0]"}


def test_unknown_same_named_symbol_is_not_substituted():
    members = [{"kind": "Variable", "addr": 10, "name": "q"},
               {"kind": "Parameter", "addr": 20, "name": "Width", "type": "int", "value": "4"}]
    result = ProcessLowerer(members, {"q"}).lower({"body": {
        "kind": "Assignment", "left": ref(10, "q"), "right": ref(999, "Width")}}, 0)
    assert result["status"] == "unsupported"
    assert result["blocking_final"] == {}


def test_parameter_not_valid_as_assignment_destination():
    members = [{"kind": "Parameter", "addr": 20, "name": "P", "type": "int", "value": "4"}]
    result = ProcessLowerer(members, set()).lower({"body": {
        "kind": "Assignment", "left": ref(20, "P"),
        "right": {"kind": "IntegerLiteral", "value": "2"}}}, 0)
    assert result["status"] == "unsupported"


def test_package_constant_resolved_by_global_identity_only():
    members = [{"kind": "Variable", "addr": 10, "name": "q"}]
    global_constants = {"77": {"op": "literal", "value": "5'h12", "type": "logic[4:0]"}}
    result = ProcessLowerer(members, {"q"}, global_constants).lower({"body": {
        "kind": "Assignment", "left": ref(10, "q"), "right": ref(77, "PKG_OFFSET")}}, 0)
    assert result["status"] == "supported"
    assert result["blocking_final"]["q"] == global_constants["77"]


def test_slang_global_constant_address_conflict_rejected():
    import pytest
    from flexsoc.backend.dv.rtl_viewer.slang import SlangReferences
    with pytest.raises(ValueError, match="conflicting Slang constant address"):
        SlangReferences({"design": {"members": [
            {"kind": "Parameter", "addr": 77, "value": "1"},
            {"kind": "Parameter", "addr": 77, "value": "2"}]}})
