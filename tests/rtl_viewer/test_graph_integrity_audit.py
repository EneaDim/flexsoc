"""Audit must preserve the distinction between an AST fact and an ELK edge."""
from flexsoc.backend.dv.rtl_viewer.graph_integrity import inspect_graph
from test_v6_connectivity import graph


def test_classifies_rendering_without_changing_semantics():
    nodes = [{"id": "signal"}, {"id": "operator"}]
    edges = [{"id": "wire", "source": "signal", "target": "operator", "type": "data", "rendered": True},
             {"id": "guard", "source": "signal", "target": "operator", "type": "control", "rendered": False},
             {"id": "missing", "source": "signal", "target": "operator", "type": "data", "rendered": False,
              "routingStatus": "unresolved_operand_multiple_nets", "pin": "A"}]
    before = [dict(e) for e in edges]
    result = inspect_graph(nodes, edges)
    assert result["status"] == "ok"
    assert result["rendered"] == 1 and result["not_rendered"] == 2
    assert result["suppressed_by_reason"] == {"nonphysical_dependency": 1, "unresolved_operand_multiple_nets": 1}
    assert edges == before


def test_detects_dangling_and_duplicate_edges():
    report = inspect_graph([{"id": "a"}], [
        {"id": "x", "source": "a", "target": "missing"},
        {"id": "x", "source": "a", "target": "a"}])
    assert report["status"] == "invalid"
    assert {i["reason"] for i in report["invalid"]} == {"missing_endpoint", "duplicate_or_missing_edge_id"}


def test_real_diagram_exposes_integrity_in_audit():
    design = graph()
    diagram = design.diagram()
    report = design.audit()
    assert diagram["graph_integrity"]["edges"] == len(diagram["edges"])
    assert report["totals"]["graph_integrity"]["rendered"] + report["totals"]["graph_integrity"]["not_rendered"] == report["totals"]["edges"]
    assert report["totals"]["graph_integrity"]["invalid_scopes"] == 0
