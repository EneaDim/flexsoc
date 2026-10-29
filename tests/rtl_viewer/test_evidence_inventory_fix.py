"""Bounded run-wide diagnostics inventory, without inferred instance identity."""
import json
from flexsoc.backend.dv.rtl_viewer import RtlDesign
from test_rtl_viewer import fixture_ast


def test_evidence_inventory_preserves_unknown_sources(tmp_path):
    run = tmp_path / "run"
    directory = run / "dv/lint/slang"
    directory.mkdir(parents=True)
    (directory / "summary.json").write_text(json.dumps({"diagnostics": [
        {"file": "DSP.sv", "priority": "P0"},
        {"file": "outside/other.sv", "severity": "warning"},
        {"message": "unattributed"},
        "non-diagnostic",
    ]}), encoding="utf-8")
    design = RtlDesign(fixture_ast(), root=tmp_path, top="DSP", run=run)
    report = design.evidence()
    assert report["status"] == "available"
    assert report["total"] == 3
    assert report["source_files"] == 2
    assert report["priorities"] == {"P0": 1, "unknown": 1, "warning": 1}
    assert "instance" in report["attribution"]
    assert "diagnostics" not in report


def test_evidence_without_run_is_explicit(tmp_path):
    design = RtlDesign(fixture_ast(), root=tmp_path, top="DSP")
    assert design.evidence() == {"status": "unavailable", "total": 0, "reason": "no run attached"}
