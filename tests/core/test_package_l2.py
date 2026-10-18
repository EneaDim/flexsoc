"""RTL-only IP release does not depend on synthesis or EQY products."""

from __future__ import annotations

import json
from pathlib import Path

import pytest

from flexsoc.backend.release.package import PackageFlow
from flexsoc.backend.release.qualification import QualificationFlow


def _run(tmp_path: Path, *, passing: bool) -> tuple[PackageFlow, dict[str, object]]:
    top, pdk = "demo", "sky130"
    project = tmp_path / "project"
    run = project / "work" / "runs" / top / "l2"
    for dirname in ("rtl", "csr", "constraints", "spec", "dv/functional/model_tests"):
        (run / dirname).mkdir(parents=True, exist_ok=True)
    (run / "rtl" / "demo.sv").write_text("module demo; endmodule\n", encoding="utf-8")
    (run / "rtl" / "rtl_ip.f").write_text("rtl/demo.sv\n", encoding="utf-8")
    (run / "csr" / "demo.hjson").write_text('{name: "demo"}\n', encoding="utf-8")
    (run / "constraints" / "demo.sdc").write_text("create_clock -period 10 clk_i\n", encoding="utf-8")
    (run / "spec" / "ip.md").write_text("# Demo\n", encoding="utf-8")
    (run / "spec" / "requirements.yaml").write_text(
        "schema: 1\nip: demo\nversion: 1.0.0\nrequirements:\n"
        "  - id: DEMO-FUNC-001\n    statement: Demo shall operate.\n"
        "    scope: common\n    origin: derived\n    status: baselined\n", encoding="utf-8"
    )
    (run / "spec" / "testplan.yaml").write_text(
        "schema: 1\nip: demo\nversion: 1.0.0\nqualification:\n"
        "  required_evidence: [traceability, lint, functional, cdc_rdc, formal]\n"
        "items:\n  - id: DEMO-TP-001\n    requirements: [DEMO-FUNC-001]\n"
        "    methods: [simulation]\n    tests: [smoke]\n", encoding="utf-8"
    )
    fingerprint = QualificationFlow.validate_spec_bundle(run / "spec", ip_name=top)["fingerprint"]
    report = {
        "ip": top, "reg_interface": "tlul", "pdk": pdk,
        "contract_fingerprint": fingerprint,
        "maximum_level": 2 if passing else 1,
        "maximum_qualification": "RTL Qualified" if passing else "Contract Valid",
        "levels": {"2": {"status": "PASS" if passing else "BLOCKED"}},
    }
    qualification = run / "meta" / pdk / "qualification.json"
    qualification.parent.mkdir(parents=True)
    qualification.write_text(json.dumps(report) + "\n", encoding="utf-8")
    (run / "dv" / "functional" / "model_tests" / "summary.json").write_text(
        '{"status":"PASS","cases":{"smoke":"PASS"}}\n', encoding="utf-8"
    )
    args = dict(ip_name=top, reg_interface="tlul", top=top, pdk=pdk,
                library_root=project / "hw" / "ips", synth_dir=run / "syn" / pdk,
                signoff_dir=run / "signoff" / pdk, sdc_file=run / "constraints" / "demo.sdc",
                eqy_config=run / "signoff" / pdk / "missing.eqy",
                eqy_view=run / "signoff" / pdk / "missing.sv",
                filelists=(run / "rtl" / "rtl_ip.f",),
                netlist=run / "syn" / pdk / "demo_synth.v", liberty=run / "missing.lib",
                cell_models=(), clock_gate_model=run / "missing_gate.v",
                qualification_json=qualification, release_level=2, version="1.0.0")
    return PackageFlow(project, {}), args


def test_l2_package_without_l3_and_strict_reload(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    assert (saved / "dv/functional/model_tests/summary.json").is_file()
    assert (saved / "meta/sky130/qualification.json").is_file()
    assert not (saved / "syn/sky130").exists()
    assert not (saved / "signoff/sky130").exists()
    manifest = json.loads((saved / "ip.json").read_text(encoding="utf-8"))
    assert manifest["qualification"]["summary"]["maximum_level"] == 2
    QualificationFlow.validate_release_package(saved)
    loaded = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                       run_top="demo", run_id="import", workspace=tmp_path / "reloaded")
    assert (loaded / "rtl" / "demo.sv").is_file()
    assert not (loaded / "syn/sky130").exists()
    # Replacing a previously populated PDK branch must not retain fake L3 data.
    for relative in ("syn/sky130/stale.v", "signoff/sky130/post_syn/stale.json", "impl/sky130/stale.odb"):
        artifact = saved / relative
        artifact.parent.mkdir(parents=True, exist_ok=True)
        artifact.write_text("stale\n", encoding="utf-8")
    sibling = saved.parent / "axi_lite" / "sentinel.txt"
    sibling.parent.mkdir(parents=True)
    sibling.write_text("keep\n", encoding="utf-8")
    saved = flow.save(**args)
    assert sibling.read_text(encoding="utf-8") == "keep\n"
    for relative in ("syn/sky130", "signoff/sky130", "impl/sky130"):
        assert not (saved / relative).exists()


def test_l2_save_refuses_incomplete_qualification(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=False)
    with pytest.raises(ValueError, match="matching L2 PASS"):
        flow.save(**args)
    assert not args["library_root"].exists()


def test_l2_save_refuses_missing_report(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    Path(args["qualification_json"]).unlink()
    with pytest.raises(FileNotFoundError, match="required ip_save input"):
        flow.save(**args)
    assert not args["library_root"].exists()


def _add_pdk_branch(saved: Path, pdk: str) -> None:
    """Represent a qualification frozen for a second technology branch."""
    original = json.loads((saved / "meta/sky130/qualification.json").read_text(encoding="utf-8"))
    original["pdk"] = pdk
    destination = saved / "meta" / pdk / "qualification.json"
    destination.parent.mkdir(parents=True)
    destination.write_text(json.dumps(original) + "\n", encoding="utf-8")
    artifact = saved / "syn" / pdk / "old_netlist.v"
    artifact.parent.mkdir(parents=True)
    artifact.write_text("// historic netlist\n", encoding="utf-8")


def test_l2_save_removes_other_pdk_with_old_spec_fingerprint(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    _add_pdk_branch(saved, "ihp-sg13g2")
    old_regression = saved / "dv/functional/regression/summary.json"
    old_regression.parent.mkdir(parents=True)
    old_regression.write_text('{"status":"PASS","old":true}\n', encoding="utf-8")
    old_formal = saved / "dv/formal/summary.json"
    old_formal.parent.mkdir(parents=True)
    old_formal.write_text('{"status":"PASS","old":true}\n', encoding="utf-8")
    run = Path(args["qualification_json"]).parents[2]
    (run / "spec/ip.md").write_text("# Demo updated TDS\n", encoding="utf-8")
    fingerprint = QualificationFlow.validate_spec_bundle(run / "spec", ip_name="demo")["fingerprint"]
    report = json.loads(Path(args["qualification_json"]).read_text(encoding="utf-8"))
    report["contract_fingerprint"] = fingerprint
    Path(args["qualification_json"]).write_text(json.dumps(report) + "\n", encoding="utf-8")

    saved = flow.save(**args)
    assert not (saved / "meta/ihp-sg13g2").exists()
    assert not (saved / "syn/ihp-sg13g2").exists()
    assert not (saved / "dv/functional/regression/summary.json").exists()
    assert not (saved / "dv/formal/summary.json").exists()
    assert (saved / "meta/sky130/qualification.json").is_file()
    assert QualificationFlow.validate_release_package(saved)["contract_fingerprint"] == fingerprint


def test_l2_save_preserves_other_pdk_when_spec_unchanged(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    _add_pdk_branch(saved, "ihp-sg13g2")
    saved = flow.save(**args)
    assert (saved / "meta/ihp-sg13g2/qualification.json").is_file()
    assert (saved / "syn/ihp-sg13g2/old_netlist.v").is_file()
    QualificationFlow.validate_release_package(saved)


def test_l2_save_refuses_old_report_for_changed_spec(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    run = Path(args["qualification_json"]).parents[2]
    (run / "spec/ip.md").write_text("# Changed after qualification\n", encoding="utf-8")
    with pytest.raises(ValueError, match="report is stale against current specifications"):
        flow.save(**args)
    QualificationFlow.validate_release_package(saved)
