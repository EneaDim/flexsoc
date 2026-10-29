"""Fail-closed identity and bounded-cone semantics (AST-only fixtures)."""
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign


def design():
    child = {"kind": "Instance", "name": "u", "body": {"kind": "InstanceBody", "name": "child", "members": [
        {"kind": "Port", "name": "a", "direction": "In"}]},
        "connections": [{"port": "a", "expression": {"kind": "NamedValue", "symbol": "17 a"}}]}
    root = {"kind": "Instance", "name": "top", "body": {"kind": "InstanceBody", "name": "top", "members": [
        {"kind": "Port", "name": "a", "addr": 17, "direction": "In"}, child]}}
    return RtlDesign({"design": {"members": [root]}}, root=Path(__file__).parent, top="top")


def test_follow_requires_canonical_parent_scoped_identity():
    d = design()
    assert d.follow("/", "/u", "/::sig:a")["status"] == "resolved"
    assert d.follow("/", "/u", "a")["status"] == "unresolved"
    assert d.follow("/", "/u", "/other::sig:a")["status"] == "unresolved"
    assert d.follow("/", "/u", "/::inst:a")["status"] == "unresolved"


def test_cone_never_claims_no_path_when_projection_is_truncated():
    d = design()
    original = d.diagram
    a, b = "/::sig:a", "/::sig:b"
    def graph(*args, **kwargs):
        return {"nodes": [{"id": a, "type": "port"}, {"id": b, "type": "port"}],
                "edges": [], "truncated": True}
    d.diagram = graph
    result = d.cone("/", a, b)
    assert result["status"] == "incomplete" and result["truncated"] is True
    assert result["paths"] == []
    assert d.cone("/", a, "/::sig:missing")["status"] == "unresolved"
    d.diagram = lambda *args, **kwargs: {**graph(), "truncated": False}
    assert d.cone("/", a, b)["status"] == "no_path"
    d.diagram = original


def test_cone_depth_limit_is_not_proof_of_disconnection():
    d = design()
    nodes = [{"id": f"n{i}", "type": "operator"} for i in range(42)]
    edges = [{"source": f"n{i}", "target": f"n{i+1}", "resolved": True}
             for i in range(41)]
    d.diagram = lambda *args, **kwargs: {"nodes": nodes, "edges": edges, "truncated": False}
    result = d.cone("/", "n0", "n41")
    assert result["status"] == "incomplete" and result["truncated"]


def test_cone_unknown_edges_prevent_false_negative():
    d = design()
    nodes = [{"id": k, "type": "port"} for k in ("a", "b")]
    edges = [{"source": "a", "target": "b", "resolved": False}]
    d.diagram = lambda *args, **kwargs: {"nodes": nodes, "edges": edges, "truncated": False}
    assert d.cone("/", "a", "b")["status"] == "incomplete"


def test_cone_paths_are_deterministic_across_edge_order():
    d = design()
    nodes = [{"id": k, "type": "port"} for k in ("a", "b", "c", "d")]
    edges = [{"source": a, "target": b, "resolved": True}
             for a, b in (("a", "c"), ("a", "b"), ("c", "d"), ("b", "d"))]
    d.diagram = lambda *args, **kwargs: {"nodes": nodes, "edges": edges, "truncated": False}
    first = d.cone("/", "a", "d")
    d.diagram = lambda *args, **kwargs: {"nodes": nodes, "edges": list(reversed(edges)), "truncated": False}
    assert first["paths"] == [["a", "b", "d"], ["a", "c", "d"]]
    assert d.cone("/", "a", "d")["paths"] == first["paths"]
