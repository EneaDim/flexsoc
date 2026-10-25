"""Procedural assignment trace preserves order, branch identity and assignment scheduling."""
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign


def reference(addr):
    return {"kind": "NamedValue", "symbol": f"{addr} local"}


def test_nested_ordered_assignments_and_branch_exclusivity(tmp_path):
    decl = [{"kind": "Variable", "name": name, "addr": i}
            for i, name in enumerate(("sel", "a", "b", "q"), 1)]
    def assign(src, nonblocking=False):
        return {"kind": "Assignment", "left": reference(4), "right": reference(src),
                "isNonBlocking": nonblocking}
    statements = {"kind": "Block", "body": [
        assign(2),
        {"kind": "Conditional", "conditions": [{"expr": reference(1)}],
         "ifTrue": assign(3, True), "ifFalse": assign(2)},
    ]}
    ast = {"design": {"members": [{"kind": "Instance", "name": "top",
        "body": {"kind": "InstanceBody", "name": "top", "members": [
            *decl, {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "body": statements}]}}]}}
    result = RtlDesign(ast, root=tmp_path, top="top").behavior()["processes"][0]
    ops = result["assignments"]
    assert [o["ordinal"] for o in ops] == [0, 1, 2]
    assert [o["reads"] for o in ops] == [["a"], ["b"], ["a"]]
    assert [o["blocking"] for o in ops] == [True, False, True]
    assert [o["guards"][-1]["branch"] if o["guards"] else None for o in ops] == [
        None, "ifTrue", "ifFalse"]


def test_case_arm_trace_is_not_flattened(tmp_path):
    decl = [{"kind": "Variable", "name": name, "addr": i}
            for i, name in enumerate(("sel", "a", "b", "q"), 1)]
    case = {"kind": "Case", "expr": reference(1), "items": [
        {"expressions": [{"kind": "IntegerLiteral", "value": "0"}],
         "stmt": {"kind": "Assignment", "left": reference(4), "right": reference(2)}},
        {"expressions": [{"kind": "IntegerLiteral", "value": "1"}],
         "stmt": {"kind": "Assignment", "left": reference(4), "right": reference(3)}}]}
    ast = {"design": {"members": [{"kind": "Instance", "name": "top",
        "body": {"kind": "InstanceBody", "name": "top", "members": [
            *decl, {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "body": case}]}}]}}
    p = RtlDesign(ast, root=tmp_path, top="top").behavior()["processes"][0]
    assert [o["guards"][0]["index"] for o in p["assignments"]] == [0, 1]
    assert {d["source"] for d in p["dependencies"] if d["role"] == "control"} == {"sel"}
