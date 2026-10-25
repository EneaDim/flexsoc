"""Technology-neutral reporting contracts for qualified RTL packages."""
import json
from pathlib import Path
from types import SimpleNamespace

from flexsoc.backend.release.reporting import Reporting
from flexsoc.backend.release.package import PackageFlow


def test_rtl_snapshots_exclude_implementation_and_pdk():
    original = {
        "top": "uart", "technology": {"pdk": "sky130"},
        "modeling": {"status": "pass"}, "regression": {"status": "pass"},
        "synthesis": {"status": "pass"},
        "rtl_closure": {"status": "pass", "stages": {"modeling": "pass"}},
    }
    snapshot = Reporting.rtl_metrics_snapshot(original)
    assert snapshot["scope"] == "rtl"
    assert snapshot["rtl_closure"]["status"] == "pass"
    assert "technology" not in snapshot
    assert "synthesis" not in snapshot
    manifest = Reporting.rtl_manifest_snapshot({
        "run": {"top": "uart", "run_top": "uart", "run_id": "l2", "pdk": "sky130", "run_root": "/tmp/run", "artifacts": {}},
        "git": {"commit": "abc"}, "environment": {}, "tools": {},
        "signoff": {"status": "pass"},
    })
    assert manifest["run"]["run_id"] == "l2"
    assert "pdk" not in manifest["run"]
    assert "signoff" not in manifest


def test_reporting_run_emits_common_and_technology_snapshots(tmp_path: Path):
    run = tmp_path / "run"
    tech = run / "meta" / "sky130"
    paths = SimpleNamespace(top="uart", run=run, pdk="sky130", metrics=tech / "metrics.json")
    context = SimpleNamespace(paths=paths)
    target = SimpleNamespace(action="metrics")
    output = Reporting().run(target, context)
    assert output == run / "meta" / "metrics.json"
    common = json.loads(output.read_text())
    technology = json.loads(paths.metrics.read_text())
    assert common["scope"] == "rtl"
    assert "technology" not in common
    assert technology["technology"]["pdk"] == "sky130"


def test_package_stages_common_reports(tmp_path: Path):
    run = tmp_path / "run"
    meta = run / "meta"
    tech = meta / "sky130"
    tech.mkdir(parents=True)
    for name in ("metrics.json", "manifest.json"):
        (meta / name).write_text(json.dumps({"scope": "rtl"}))
        (tech / name).write_text(json.dumps({"technology": {"pdk": "sky130"}}))
    staged = tmp_path / "package"
    PackageFlow._stage_optional_reports(
        staged, "sky130", post_syn_sim_dir=None, coverage_dir=None,
        manifest_json=tech / "manifest.json", metrics_json=tech / "metrics.json",
        provenance_json=None, settings_json=None, design_intent_json=None, qualification_json=None,
    )
    assert json.loads((staged / "meta" / "metrics.json").read_text())["scope"] == "rtl"
    assert json.loads((staged / "meta" / "sky130" / "metrics.json").read_text())["technology"]["pdk"] == "sky130"
