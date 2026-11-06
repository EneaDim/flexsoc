"""Compiler-AST case arm and lvalue selector regression coverage."""
from flexsoc.backend.dv.rtl_viewer.connectivity import SymbolTable
from flexsoc.backend.dv.rtl_viewer.process import ProcessAnalyzer


def _ref(address):
    return {"kind": "NamedValue", "symbol": f"{address} wrong_name"}


def _members():
    return [{"kind": "Variable", "name": name, "addr": addr}
            for addr, name in ((101, "sel"), (102, "out"), (103, "data"), (104, "index"))]


def test_case_item_body_preserves_control_and_data_reads():
    analyzer = ProcessAnalyzer(_members(), {"sel", "out", "data", "index"})
    process = {"procedureKind": "AlwaysComb", "body": {
        "kind": "CaseStatement", "expr": _ref(101), "items": [{
            "kind": "CaseItem", "expressions": [], "body": {
                "kind": "Assignment", "left": _ref(102), "right": _ref(103)}}]}}
    result = analyzer.process(process, 0)
    assert len(result["assignments"]) == 1
    assert result["assignments"][0]["destinations"] == ["out"]
    assert result["assignments"][0]["reads"] == ["data"]
    assert {(d["source"], d["destination"], d["role"]) for d in result["dependencies"]} == {
        ("sel", "out", "control"), ("data", "out", "data")}


def test_parenthesized_indexed_lvalue_reads_index_not_written_index():
    symbols = SymbolTable(_members(), {"sel", "out", "data", "index"})
    lhs = {"kind": "ParenthesizedExpression", "operand": {
        "kind": "ElementSelect", "value": _ref(102), "selector": _ref(104)}}
    assert symbols.writes(lhs) == ("out",)
    assert symbols.address_reads(lhs) == ("index",)
    analyzer = ProcessAnalyzer(_members(), {"sel", "out", "data", "index"})
    result = analyzer.process({"body": {"kind": "Assignment", "left": lhs,
                                          "right": _ref(103)}}, 0)
    assert result["assignments"][0]["address_reads"] == ["index"]
    assert ("index", "out", "address") in {
        (d["source"], d["destination"], d["role"]) for d in result["dependencies"]}


def test_assignment_conversion_preserves_index_as_address_dependency():
    members = _members()
    symbols = SymbolTable(members, {"sel", "out", "data", "index"})
    lhs = {"kind": "AssignmentConversion", "operand": {
        "kind": "ElementSelect", "value": _ref(102), "selector": _ref(104)}}
    assert symbols.writes(lhs) == ("out",)
    assert symbols.address_reads(lhs) == ("index",)
    result = ProcessAnalyzer(members, {"sel", "out", "data", "index"}).process(
        {"body": {"kind": "Assignment", "left": lhs, "right": _ref(103)}}, 0)
    assert ("index", "out", "address") in {
        (d["source"], d["destination"], d["role"]) for d in result["dependencies"]}


def test_nested_conversion_and_concatenation_keep_distinct_address_reads():
    symbols = SymbolTable(_members(), {"sel", "out", "data", "index"})
    lhs = {"kind": "Concatenation", "operands": [
        {"kind": "ImplicitConversion", "operand": {
            "kind": "ElementSelect", "value": _ref(102), "selector": _ref(104)}},
        {"kind": "RangeSelect", "value": _ref(103), "left": _ref(101), "right": _ref(104)},
    ]}
    assert symbols.writes(lhs) == ("out", "data")
    assert symbols.address_reads(lhs) == ("index", "sel") or symbols.address_reads(lhs) == ("sel", "index")


def test_assignment_pattern_lvalue_preserves_dynamic_address_reads():
    members = _members()
    lhs = {"kind": "AssignmentPattern", "elements": [
        {"kind": "ElementSelect", "value": _ref(102), "selector": _ref(104)},
        {"kind": "RangeSelect", "value": _ref(103), "left": _ref(101), "right": _ref(104)},
    ]}
    symbols = SymbolTable(members, {"sel", "out", "data", "index"})
    assert symbols.writes(lhs) == ("out", "data")
    assert set(symbols.address_reads(lhs)) == {"sel", "index"}
    result = ProcessAnalyzer(members, {"sel", "out", "data", "index"}).process(
        {"body": {"kind": "Assignment", "left": lhs, "right": _ref(103)}}, 0)
    deps = {(d["source"], d["destination"], d["role"]) for d in result["dependencies"]}
    assert {("index", "out", "address"), ("sel", "data", "address"),
            ("index", "data", "address")} <= deps
