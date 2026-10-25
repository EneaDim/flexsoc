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

@pytest.mark.parametrize("changed", ("rtl/demo.sv", "meta/sky130/qualification.json", "dv/functional/model_tests/summary.json"))
def test_l2_package_detects_modified_saved_evidence(tmp_path: Path, changed: str) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    path = saved / changed
    path.write_text(path.read_text(encoding="utf-8") + "\nchanged\n", encoding="utf-8")
    with pytest.raises(ValueError, match="(changed|stale)"):
        QualificationFlow.validate_release_package(saved)


def test_l2_reload_replaces_old_run_files_without_losing_settings(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    workspace = tmp_path / "loaded"
    run = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                    run_top="demo", run_id="l2", workspace=workspace)
    assert QualificationFlow.evidence_integrity(run, "sky130")
    (run / "rtl" / "old.sv").write_text("module old; endmodule\n", encoding="utf-8")
    (run / "dv" / "old.log").write_text("stale\n", encoding="utf-8")
    (run / "meta" / "settings.json").write_text('{}', encoding="utf-8")
    (run / "logs").mkdir(exist_ok=True)
    (run / "logs" / "history.log").write_text("keep\n", encoding="utf-8")
    with pytest.raises(ValueError, match="dv/old.log"):
        QualificationFlow.evidence_integrity(run, "sky130")
    flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
              run_top="demo", run_id="l2", workspace=workspace)
    assert QualificationFlow.evidence_integrity(run, "sky130")
    assert not (run / "rtl" / "old.sv").exists()
    assert not (run / "dv" / "old.log").exists()
    assert (run / "meta" / "settings.json").is_file()
    assert (run / "logs" / "history.log").read_text() == "keep\n"
    assert QualificationFlow.evidence_integrity(saved, "sky130")


def test_loaded_shared_primitive_does_not_invalidate_frozen_release(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    run = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                    run_top="demo", run_id="l2", workspace=tmp_path / "loaded")
    primitive = "rtl/deps/flexsoc/prim/prim_ff_2sync.sv"
    # Simulate a dependency materialized by ip_load but not shipped by ip_save.
    # The filelist is part of the hashed release and cannot be edited afterwards.
    filelist = saved / "rtl" / "rtl_common.f"
    filelist.write_text(primitive + "\n", encoding="utf-8")
    QualificationFlow.evidence_integrity(saved, "sky130", write=True)
    (run / "rtl" / "rtl_common.f").write_text(primitive + "\n", encoding="utf-8")
    QualificationFlow.evidence_integrity(run, "sky130", write=True)
    materialized = run / primitive
    materialized.parent.mkdir(parents=True)
    materialized.write_text("module prim_ff_2sync; endmodule\n", encoding="utf-8")
    assert QualificationFlow.evidence_integrity(run, "sky130")
    (run / "rtl" / "demo.sv").write_text("module changed; endmodule\n", encoding="utf-8")
    with pytest.raises(ValueError, match="rtl/demo.sv"):
        QualificationFlow.evidence_integrity(run, "sky130")


def test_save_refreshes_lint_metrics_from_shipped_summary(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    run = Path(args["qualification_json"]).parents[2]
    lint = run / "dv" / "lint"
    lint.mkdir(parents=True)
    (lint / "summary.json").write_text(
        json.dumps({"top": "demo", "status": "PASS", "tools": {"slang": {}, "verilator": {}}}),
        encoding="utf-8",
    )
    metrics = run / "meta" / "sky130" / "metrics.json"
    metrics.write_text(json.dumps({"top": "demo", "closure": {"stages": {"lint": "missing"}}}), encoding="utf-8")
    args["metrics_json"] = metrics

    saved = flow.save(**args)
    exported = json.loads((saved / "meta/sky130/metrics.json").read_text(encoding="utf-8"))
    assert exported["lint"]["status"] == "PASS"
    assert exported["closure"]["stages"]["lint"] == "PASS"

    loaded = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                       run_top="demo", run_id="import", workspace=tmp_path / "reloaded")
    imported = json.loads((loaded / "meta/sky130/metrics.json").read_text(encoding="utf-8"))
    assert imported["closure"]["stages"]["lint"] == "PASS"


def test_model_python_cache_does_not_invalidate_l2(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    run = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                    run_top="demo", run_id="import", workspace=tmp_path / "loaded")
    cache = run / "dv/functional/py/model/__pycache__/scenarios.cpython-311.pyc"
    cache.parent.mkdir(parents=True, exist_ok=True)
    cache.write_bytes(b"generated runtime bytecode")
    assert QualificationFlow.evidence_integrity(run, "sky130")
    assert not (saved / cache.relative_to(run)).exists()
    (run / "rtl/demo.sv").write_text("module modified; endmodule\n", encoding="utf-8")
    with pytest.raises(ValueError, match="rtl/demo.sv"):
        QualificationFlow.evidence_integrity(run, "sky130")


def test_legacy_cache_entries_do_not_invalidate_l2(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    record = saved / "meta/sky130/evidence_integrity.json"
    data = json.loads(record.read_text(encoding="utf-8"))
    data = {"schema": 1, "files": {**data["sources"], **{name: item["sha256"] for name, item in data["generated"].items()}}}
    data["files"]["dv/functional/py/model/__pycache__/old.pyc"] = "0" * 64
    record.write_text(json.dumps(data), encoding="utf-8")
    assert QualificationFlow.evidence_integrity(saved, "sky130")


def test_mtest_runtime_results_do_not_invalidate_release(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    run = Path(args["qualification_json"]).parents[2]
    runtime = run / "dv/functional/py/model/results"
    runtime.mkdir(parents=True)
    (runtime / "junit.xml").write_text("original")
    (runtime / "summary.json").write_text("original")
    saved = flow.save(**args)
    assert not (saved / "dv/functional/py/model/results").exists()
    loaded = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                       run_top="demo", run_id="import", workspace=tmp_path / "loaded")
    results = loaded / "dv/functional/py/model/results"
    results.mkdir(parents=True)
    (results / "junit.xml").write_text("new test run")
    (results / "summary.json").write_text("new test run")
    assert QualificationFlow.evidence_integrity(loaded, "sky130")
    official = loaded / "dv/functional/model_tests/summary.json"
    official.write_text("tampered")
    with pytest.raises(ValueError, match="dv/functional/model_tests/summary.json"):
        QualificationFlow.evidence_integrity(loaded, "sky130")


def test_old_manifest_runtime_results_do_not_invalidate_release(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    record = saved / "meta/sky130/evidence_integrity.json"
    data = json.loads(record.read_text())
    data = {"schema": 1, "files": {**data["sources"], **{name: item["sha256"] for name, item in data["generated"].items()}}}
    data["files"]["dv/functional/py/model/results/junit.xml"] = "0" * 64
    data["files"]["dv/functional/py/model/results/summary.json"] = "0" * 64
    record.write_text(json.dumps(data))
    assert QualificationFlow.evidence_integrity(saved, "sky130")


def test_model_cases_are_required_for_l2() -> None:
    spec = {"required_evidence": ["traceability", "lint", "functional", "cdc_rdc", "formal"],
            "spec_traceability": {"model_cases_to_testplan": {"corners": ["DEMO-TP-001"]}}}
    assert QualificationFlow.required_stages(spec, 2)[:3] == (
        "requirements_traceability", "model_tests", "lint"
    )
    assert "model_tests" not in QualificationFlow.required_stages({"required_evidence": ["lint"]}, 2)
    report = QualificationFlow.build_qualification_report(
        ip_name="demo", reg_interface="tlul", pdk="sky130", spec={**spec, "fingerprint": "test",
        "baselined_requirements": 1, "covered_requirements": 1},
        stage_states={stage: "CLEAN" for stage in QualificationFlow.required_stages(spec, 2)
                      if stage != "model_tests"},
        stage_outcomes={stage: "PASS" for stage in QualificationFlow.required_stages(spec, 2)
                        if stage != "model_tests"},
        contract_ready=True, requested_level="rtl",
    )
    assert report["levels"]["2"]["status"] == "BLOCKED"
    assert "model_tests" in report["levels"]["2"]["blocking_evidence"]


def test_save_rejects_old_l2_report_when_model_cases_exist(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    flow, args = _run(tmp_path, passing=True)
    real_validate = QualificationFlow.validate_spec_bundle

    def with_model_cases(*params, **kwargs):
        spec = real_validate(*params, **kwargs)
        spec["spec_traceability"] = {"model_cases_to_testplan": {"corners": ["DEMO-TP-001"]}}
        return spec

    monkeypatch.setattr(QualificationFlow, "validate_spec_bundle", with_model_cases)
    with pytest.raises(ValueError, match="model tests PASS"):
        flow.save(**args)


def test_requalification_reseals_verified_loaded_run(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    flow.save(**args)
    loaded = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                       run_top="demo", run_id="import", workspace=tmp_path / "reload")
    pdk = "sky130"
    assert QualificationFlow.evidence_integrity(loaded, pdk)
    report = json.loads((loaded / "meta" / pdk / "qualification.json").read_text())
    report["evidence"] = {"model_tests": "PASS"}
    QualificationFlow.write_qualification_report(loaded, pdk, report)
    assert QualificationFlow.evidence_integrity(loaded, pdk)
    assert json.loads((loaded / "meta" / pdk / "qualification.json").read_text())["evidence"]["model_tests"] == "PASS"
    (loaded / "rtl" / "demo.sv").write_text("module demo; wire changed; endmodule\n")
    with pytest.raises(ValueError, match="rtl/demo.sv"):
        QualificationFlow.write_qualification_report(loaded, pdk, report)


def test_modeling_metrics_and_manifest_use_retained_evidence(tmp_path: Path) -> None:
    from flexsoc.backend.release.reporting import Reporting

    flow, args = _run(tmp_path, passing=True)
    saved = flow.save(**args)
    metrics = Reporting.collect_metrics("demo", saved, pdk="sky130")
    assert metrics["modeling"]["status"] == "PASS"
    assert metrics["closure"]["stages"]["modeling"] == "PASS"
    assert metrics["flow"]["stages"]["modeling"] == "pass"
    manifest_path = saved / "meta" / "sky130" / "manifest.json"
    if manifest_path.is_file():
        manifest = json.loads(manifest_path.read_text())
        assert manifest["analysis"]["modeling"]["status"] == "PASS"

@pytest.mark.parametrize("relative", (
    "rtl/deps/flexsoc/prim/prim_ff_2sync.sv",
    "rtl/deps/flexsoc/hw/ips/prim/prim_ff_2sync.sv",
))
def test_load_materializes_shared_gpio_primitive_in_both_layouts(tmp_path: Path, relative: str) -> None:
    project = tmp_path / "project"
    primitive = project / "hw/ips/prim/prim_ff_2sync.sv"
    primitive.parent.mkdir(parents=True)
    primitive.write_text("module prim_ff_2sync; endmodule\n", encoding="utf-8")
    run = tmp_path / "run"
    (run / "rtl").mkdir(parents=True)
    (run / "rtl/rtl_common.f").write_text(relative + "\n", encoding="utf-8")
    PackageFlow(project, {})._materialize_shared_rtl(run)
    assert (run / relative).read_bytes() == primitive.read_bytes()


def test_flist_roots_search_direct_and_nested_modules(tmp_path: Path) -> None:
    from flexsoc.backend.design.ip.rtl import RtlFlow

    rtl = tmp_path / "rtl"
    prim = rtl / "deps" / "flexsoc" / "hw" / "ips" / "prim"
    rtl.mkdir()
    prim.mkdir(parents=True)
    (rtl / "gpio.sv").write_text("module gpio; prim_ff_2sync u_sync(); endmodule\n")
    (prim / "prim_ff_2sync.sv").write_text("module prim_ff_2sync; endmodule\n")

    roots = RtlFlow._ordered_roots(tmp_path, rtl / "gpio.sv", [rtl, prim])
    args = RtlFlow._recursive_search_args(roots)
    libraries = [args[i + 1] for i, arg in enumerate(args[:-1]) if arg == "--libdir"]
    assert libraries == [str(rtl), str(prim), str(prim / "...")]


def test_gpio_flist_uses_both_frozen_primitive_layouts(tmp_path: Path) -> None:
    """A partial legacy prim root cannot shadow the packaged GPIO primitive."""
    from types import SimpleNamespace
    from flexsoc.backend.design.ip.ip import IpDesign

    rtl = tmp_path / "workspace" / "rtl"
    frozen = rtl / "deps" / "flexsoc"
    for relative in (
        "hw/ips/pkgs", "hw/ips/prim", "hw/ips/prim_opentitan",
        "prim", "vendor/lowrisc_ip/ip/tlul/rtl",
    ):
        (frozen / relative).mkdir(parents=True)
    (frozen / "prim" / "old_prim.sv").write_text("module old_prim; endmodule\n")
    (frozen / "hw/ips/prim/prim_ff_2sync.sv").write_text(
        "module prim_ff_2sync; endmodule\n"
    )
    (rtl / "gpio.sv").write_text("module gpio; prim_ff_2sync u_sync(); endmodule\n")

    class SpyRtl:
        def setup_filelists(self, **kwargs):
            return kwargs

    ip = object.__new__(IpDesign)
    ip.context = SimpleNamespace(
        values={"REG_ITF": "tlul", "SLANG": "slang"},
        paths=SimpleNamespace(rtl=rtl, top="gpio", rtl_common=rtl / "rtl_common.f",
                              rtl_ip=rtl / "rtl_ip.f"),
        project_root=tmp_path,
    )
    ip.rtl = SpyRtl()
    options = ip._setup_filelists(on="local")
    roots = options["search_roots"]
    assert frozen / "hw/ips/prim" in roots
    assert frozen / "prim" in roots
    assert tmp_path / "hw/ips/prim" not in roots
    assert (frozen / "hw/ips/prim/prim_ff_2sync.sv").is_file()


def test_split_filelists_use_run_root_not_checkout(tmp_path: Path) -> None:
    """Filelists consumed by lint are relative to RUN_ROOT, including external runs."""
    from flexsoc.backend.design.ip.rtl import RtlFlow

    project = tmp_path / "checkout"
    run = tmp_path / "external" / "gpio"
    common = run / "hw/ips/prim/prim_ff_2sync.sv"
    ip = run / "rtl/gpio.sv"
    common.parent.mkdir(parents=True)
    ip.parent.mkdir(parents=True)
    common.write_text("module prim_ff_2sync; endmodule\n")
    ip.write_text("module gpio; endmodule\n")
    project.mkdir()
    RtlFlow._split_flow_filelists(
        common_out=run / "rtl/rtl_common.f",
        ip_out=run / "rtl/rtl_ip.f",
        modules=[common, ip],
        includes=[], common_roots=[common.parent],
        extra_args="", root=run, synthesis=True,
    )
    assert "hw/ips/prim/prim_ff_2sync.sv" in (run / "rtl/rtl_common.f").read_text()
    assert "rtl/gpio.sv" in (run / "rtl/rtl_ip.f").read_text()
    assert str(tmp_path) not in (run / "rtl/rtl_common.f").read_text()


def test_run_flist_writes_paths_relative_to_external_run(tmp_path: Path, monkeypatch) -> None:
    """Exercise the command generator, not just its file-writing helper."""
    from types import SimpleNamespace
    from flexsoc.backend.design.ip.rtl import RtlFlow

    project = tmp_path / "checkout"
    run = tmp_path / "external" / "gpio"
    shared = run / "hw/ips/prim/prim_ff_2sync.sv"
    top = run / "rtl/gpio.sv"
    shared.parent.mkdir(parents=True)
    top.parent.mkdir(parents=True)
    project.mkdir()
    shared.write_text("module prim_ff_2sync; endmodule\n")
    top.write_text("module gpio; prim_ff_2sync u(); endmodule\n")

    def fake_slang(**kwargs):
        argv = kwargs["action_args"]
        Path(argv[argv.index("--Mmodule") + 1]).write_text(
            f"{shared}\n{top}\n"
        )
        Path(argv[argv.index("--Minclude") + 1]).write_text("")
        return "gpio"

    monkeypatch.setattr(RtlFlow, "_run_slang", staticmethod(fake_slang))
    RtlFlow.run_flist(SimpleNamespace(
        root=project, output=None, common_out=run / "rtl/rtl_common.f",
        ip_out=run / "rtl/rtl_ip.f", slang="slang", search_root=[shared.parent],
        top_file=top, top="gpio", extra_args="", synthesis=True,
        common_root=[shared.parent],
    ))
    assert "hw/ips/prim/prim_ff_2sync.sv" in (run / "rtl/rtl_common.f").read_text()
    assert "rtl/gpio.sv" in (run / "rtl/rtl_ip.f").read_text()


def test_setup_provenance_preserved_through_save_load_and_requalify(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    run = Path(args["qualification_json"]).parents[2]
    tb = run / "dv/functional/tb/cocotb/Makefile"
    tb.parent.mkdir(parents=True, exist_ok=True)
    tb.write_text("initial\n", encoding="utf-8")
    provenance = run / "meta/provenance.json"
    provenance.write_text(json.dumps({"schema_version": 1, "stages": {
        "cocotb.setup": {"generated": [{"path": "dv/functional/tb/cocotb/Makefile"}]}
    }}), encoding="utf-8")
    saved = flow.save(**args)
    assert (saved / "meta/provenance.json").is_file()
    sealed = json.loads((saved / "meta/sky130/evidence_integrity.json").read_text())
    assert sealed["generated"]["dv/functional/tb/cocotb/Makefile"]["stage"] == "cocotb.setup"
    loaded = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                       run_top="demo", run_id="import", workspace=tmp_path / "loaded")
    (loaded / "dv/functional/tb/cocotb/Makefile").write_text("regenerated\n")
    QualificationFlow.write_qualification_report(loaded, "sky130", {"maximum_level": 2})
    assert QualificationFlow.evidence_integrity(loaded, "sky130")
    (loaded / "rtl/demo.sv").write_text("tampered\n")
    with pytest.raises(ValueError, match="rtl/demo.sv"):
        QualificationFlow.write_qualification_report(loaded, "sky130", {"maximum_level": 2})


def test_freeze_deduplicates_historical_run_local_rtl(tmp_path: Path) -> None:
    root = tmp_path / "package"
    rtl = root / "rtl"
    rtl.mkdir(parents=True)
    canonical = rtl / "uart.sv"
    canonical.write_text("module uart; endmodule\n", encoding="utf-8")
    relative = "rtl/deps/flexsoc/workspace/runs/uart/l2_uart/rtl/uart.sv"
    duplicate = root / relative
    duplicate.parent.mkdir(parents=True)
    duplicate.write_bytes(canonical.read_bytes())
    (rtl / "rtl_ip.f").write_text(relative + "\n", encoding="utf-8")

    PackageFlow._freeze_rtl_dependencies(root, tmp_path)

    assert (rtl / "rtl_ip.f").read_text(encoding="utf-8") == "rtl/uart.sv\n"
    assert not (rtl / "deps").exists()
    PackageFlow._validate_frozen_filelists(root)


def test_freeze_rejects_conflicting_historical_rtl(tmp_path: Path) -> None:
    root = tmp_path / "package"
    rtl = root / "rtl"
    rtl.mkdir(parents=True)
    (rtl / "uart.sv").write_text("module uart; endmodule\n", encoding="utf-8")
    relative = "rtl/deps/flexsoc/workspace/runs/uart/l2_uart/rtl/uart.sv"
    duplicate = root / relative
    duplicate.parent.mkdir(parents=True)
    duplicate.write_text("module uart; wire changed; endmodule\n", encoding="utf-8")
    (rtl / "rtl_ip.f").write_text(relative + "\n", encoding="utf-8")

    with pytest.raises(ValueError, match="conflicting frozen RTL dependency"):
        PackageFlow._freeze_rtl_dependencies(root, tmp_path)


@pytest.mark.parametrize("referred", [False, True])
def test_load_shadow_dependency_pruning_is_safe(tmp_path: Path, referred: bool) -> None:
    destination = tmp_path / "run"
    rtl = destination / "rtl"
    shadow = rtl / "deps" / "flexsoc" / "workspace" / "runs" / "old" / "rtl"
    shadow.mkdir(parents=True)
    (shadow / "demo.sv").write_text("module demo; endmodule\n", encoding="utf-8")
    (rtl / "demo.sv").write_text("module demo; endmodule\n", encoding="utf-8")
    (rtl / "rtl_ip.f").write_text(
        "rtl/deps/flexsoc/workspace/runs/old/rtl/demo.sv\n" if referred else "rtl/demo.sv\n",
        encoding="utf-8",
    )
    if referred:
        PackageFlow._prune_unused_rtl_dependencies(destination)
        assert shadow.exists()
    else:
        PackageFlow._prune_unused_rtl_dependencies(destination)
        assert not (rtl / "deps").exists()
        PackageFlow._prune_unused_rtl_dependencies(destination)


def test_l2_save_indexes_technology_neutral_qualification(tmp_path: Path) -> None:
    flow, args = _run(tmp_path, passing=True)
    run = args["qualification_json"].parents[2]
    report = json.loads(args["qualification_json"].read_text(encoding="utf-8"))
    QualificationFlow.write_rtl_qualification_report(run, report)
    saved = flow.save(**args)
    manifest = json.loads((saved / "ip.json").read_text(encoding="utf-8"))
    assert manifest["qualification"]["rtl"] == "meta/rtl_qualification.json"
    assert QualificationFlow.validate_release_package(saved)["ip"] == "demo"
    rtl = saved / "meta/rtl_qualification.json"
    altered = json.loads(rtl.read_text(encoding="utf-8"))
    altered["levels"]["2"]["status"] = "BLOCKED"
    rtl.write_text(json.dumps(altered), encoding="utf-8")
    with pytest.raises(ValueError, match="canonical RTL|L1/L2 qualification"):
        QualificationFlow.validate_release_package(saved)


def test_managed_shared_rtl_pinned_without_copy(tmp_path: Path) -> None:
    project = tmp_path / "project"
    shared = project / "hw/ips/prim/prim_ff_2sync.sv"
    shared.parent.mkdir(parents=True)
    shared.write_text("module prim_ff_2sync; endmodule\n", encoding="utf-8")
    vendor = project / "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv"
    vendor.parent.mkdir(parents=True)
    vendor.write_text("package tlul_pkg; endpackage\n", encoding="utf-8")
    release = tmp_path / "release"
    rtl = release / "rtl"
    rtl.mkdir(parents=True)
    (rtl / "uart.sv").write_text("module uart; endmodule\n", encoding="utf-8")
    (rtl / "rtl_ip.f").write_text("rtl/uart.sv\n", encoding="utf-8")
    (rtl / "rtl_common.f").write_text(
        "+incdir+hw/ips/prim\nhw/ips/prim/prim_ff_2sync.sv\n"
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv\n", encoding="utf-8"
    )
    PackageFlow._freeze_rtl_dependencies(release, project)
    PackageFlow._validate_frozen_filelists(release, project)
    PackageFlow._validate_shared_rtl(release, project)
    assert not (release / "dependencies").exists()
    assert not (release / "hw").exists()
    assert not (release / "vendor").exists()
    assert (rtl / "rtl_ip.f").read_text() == "rtl/uart.sv\n"
    assert "hw/ips/prim/prim_ff_2sync.sv" in (rtl / "rtl_common.f").read_text()
    manifest = json.loads((release / "meta/shared_rtl.json").read_text())
    assert set(manifest["files"]) == {
        "hw/ips/prim/prim_ff_2sync.sv",
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv",
    }
    shared.write_text("module tampered; endmodule\n", encoding="utf-8")
    with pytest.raises(ValueError, match="shared RTL changed"):
        PackageFlow._validate_shared_rtl(release, project)


def test_package_manifest_indexes_canonical_behavioral_model(tmp_path: Path) -> None:
    """Published model, tests and evidence must be discoverable independently."""
    staged = tmp_path / "uart"
    model = staged / "dv/functional/py/model"
    model.mkdir(parents=True)
    for name in ("uart_model.py", "uart_model_tests.py", "scenarios.py"):
        (model / name).write_text("# source\n", encoding="utf-8")
    evidence = staged / "dv/functional/model_tests/summary.json"
    evidence.parent.mkdir(parents=True)
    evidence.write_text('{"status":"PASS"}\n', encoding="utf-8")

    PackageFlow(tmp_path, {})._write_package_manifest(
        staged, "uart", "uart", "tlul", version="1.0.0"
    )
    content = json.loads((staged / "ip.json").read_text())["content"]
    for key, expected in (
        ("behavioral_model", "uart_model.py"),
        ("behavioral_model_tests", "uart_model_tests.py"),
        ("behavioral_scenarios", "scenarios.py"),
    ):
        path = staged / content[key]
        assert path.is_file() and path.name == expected
    assert content["behavioral_model_evidence"] == "dv/functional/model_tests/summary.json"


def test_package_manifest_does_not_invent_missing_model(tmp_path: Path) -> None:
    staged = tmp_path / "demo"
    staged.mkdir()
    PackageFlow(tmp_path, {})._write_package_manifest(staged, "demo", "demo", "tlul")
    content = json.loads((staged / "ip.json").read_text())["content"]
    assert not any(name.startswith("behavioral_") for name in content)


def test_l2_save_reload_managed_shared_sources_and_model(tmp_path: Path) -> None:
    """Release carries UART-like sources and model but not shared libraries."""
    import shutil

    flow, args = _run(tmp_path, passing=True)
    project = flow.project_root
    shared = project / "hw/ips/pkgs/top_pkg.sv"
    shared.parent.mkdir(parents=True, exist_ok=True)
    shared.write_text("package top_pkg; endpackage\n", encoding="utf-8")
    vendor = project / "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv"
    vendor.parent.mkdir(parents=True, exist_ok=True)
    vendor.write_text("package tlul_pkg; endpackage\n", encoding="utf-8")
    run = Path(args["qualification_json"]).parents[2]
    (run / "rtl/rtl_common.f").write_text(
        "+incdir+hw/ips/pkgs\nhw/ips/pkgs/top_pkg.sv\n"
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv\n", encoding="utf-8")
    model = run / "dv/functional/py/model"
    model.mkdir(parents=True)
    (model / "demo_model.py").write_text("class DemoModel: pass\n", encoding="utf-8")
    (model / "demo_model_tests.py").write_text("def test_demo(): pass\n", encoding="utf-8")

    saved = flow.save(**args)
    PackageFlow._validate_frozen_filelists(saved, project)
    assert not (saved / "dependencies").exists()
    assert not (saved / "hw").exists()
    assert not (saved / "vendor").exists()
    assert (saved / "dv/functional/py/model/demo_model.py").is_file()
    index = json.loads((saved / "ip.json").read_text())
    assert index["content"]["behavioral_model"].endswith("demo_model.py")
    assert index["content"]["shared_rtl"] == "meta/shared_rtl.json"
    loaded = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                       run_top="demo", run_id="reload", workspace=tmp_path / "loaded")
    assert (loaded / "rtl/demo.sv").read_bytes() == (saved / "rtl/demo.sv").read_bytes()
    assert not (loaded / "dependencies").exists()
    assert QualificationFlow.evidence_integrity(loaded, "sky130")
    # Relocate the checkout: managed paths must not retain the old absolute root.
    portable_root = tmp_path / "other_machine" / "project"
    shutil.copytree(project, portable_root)
    portable = PackageFlow(portable_root, {})
    imported = portable.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                             run_top="demo", run_id="portable", workspace=tmp_path / "relocated_runs")
    assert (imported / "rtl/demo.sv").is_file()
    assert QualificationFlow.evidence_integrity(imported, "sky130")
    assert str(project) not in (imported / "rtl/rtl_common.f").read_text()
    shared.write_text("package altered; endpackage\n", encoding="utf-8")
    with pytest.raises(ValueError, match="shared RTL changed"):
        flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                  run_top="demo", run_id="reload", workspace=tmp_path / "loaded")
    # Rejection happens before resetting the previous run.
    assert (loaded / "rtl/demo.sv").is_file()


def test_l2_neutral_save_load_and_tamper_rejection(tmp_path: Path) -> None:
    """L2 release is one PDK-independent sealed unit, not a per-PDK branch."""
    flow, args = _run(tmp_path, passing=True)
    run = Path(args["synth_dir"]).parents[1]
    legacy = json.loads(Path(args["qualification_json"]).read_text(encoding="utf-8"))
    legacy["evidence"] = {"lint": "PASS", "regression": "PASS"}
    neutral = QualificationFlow.rtl_qualification_report(legacy)
    canonical = run / "meta" / "rtl_qualification.json"
    canonical.write_text(json.dumps(neutral) + "\n", encoding="utf-8")
    args["qualification_json"] = canonical

    package = flow.save(**args)
    manifest = json.loads((package / "ip.json").read_text(encoding="utf-8"))
    assert manifest["qualification"]["summary"]["maximum_level"] == 2
    assert manifest["qualification"]["technologies"] == {}
    assert not (package / "meta" / "sky130").exists()
    assert QualificationFlow.rtl_evidence_integrity(package)

    loaded = flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                       run_top="demo", run_id="import", workspace=tmp_path / "reloaded")
    assert QualificationFlow.rtl_evidence_integrity(loaded)
    from types import SimpleNamespace
    context = SimpleNamespace(paths=SimpleNamespace(run=loaded, pdk="ihp-sg13g2"))
    spec = QualificationFlow.validate_spec_bundle(loaded / "spec", ip_name="demo")
    frozen = QualificationFlow(context)._frozen_evidence(
        spec_root=loaded / "spec", spec=spec, ip_name="demo", reg_interface="tlul"
    )
    assert frozen["lint"] == "PASS"
    assert frozen["regression"] == "PASS"

    rtl = package / "rtl" / "demo.sv"
    rtl.write_text(rtl.read_text(encoding="utf-8") + "// tampered\n", encoding="utf-8")
    with pytest.raises(ValueError, match="stale|changed"):
        QualificationFlow.validate_release_package(package)
    with pytest.raises(ValueError, match="stale|changed"):
        flow.load(ip_name="demo", reg_interface="tlul", version="1.0.0",
                  run_top="demo", run_id="tamper", workspace=tmp_path / "reloaded")
    assert not (tmp_path / "reloaded" / "runs" / "demo" / "tamper").exists()
