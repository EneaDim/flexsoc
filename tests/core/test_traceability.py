"""Traceability remains a checked mapping, never manufactured execution evidence."""

from __future__ import annotations

import shutil
from pathlib import Path

import pytest
import yaml

from flexsoc.backend.release.qualification import QualificationFlow
from flexsoc.backend.release.traceability import TraceabilityFlow


REPO = Path(__file__).resolve().parents[2]
IP_NAMES = ("uart", "gpio", "rv_timer", "uart_master")


@pytest.mark.parametrize("name", IP_NAMES)
def test_four_ip_traceability_is_bidirectional(name: str) -> None:
    root = REPO / "hw" / "ips" / name / "1.0.0" / "spec"
    doc = QualificationFlow.validate_spec_bundle(root, ip_name=name)["spec_traceability"]
    assert doc["status"] == "MAPPED_NOT_EXECUTED"
    assert doc["summary"]["requirements"] == len(doc["requirements_to_technical"])
    assert all(doc["technical_to_requirements"][tds] for tds in doc["technical_to_customer"])
    for customer, technical in doc["customer_to_technical"].items():
        for tid in technical:
            assert customer in doc["technical_to_customer"][tid]
    for req, technical in doc["requirements_to_technical"].items():
        for tid in technical:
            assert req in doc["technical_to_requirements"][tid]
    for tp, record in doc["testplan_to_tests"].items():
        for scenario in record["rtl"]:
            assert tp in doc["tests_to_testplan"][scenario]
        for scenario in record["model"]:
            assert tp in doc["model_cases_to_testplan"][scenario]


def _copy_specs(tmp_path: Path) -> Path:
    source = REPO / "hw/ips/gpio/1.0.0/spec"
    destination = tmp_path / "spec"
    shutil.copytree(source, destination)
    return destination


def test_reject_orphan_customer(tmp_path: Path) -> None:
    root = _copy_specs(tmp_path)
    with (root / "customer.md").open("a", encoding="utf-8") as file:
        file.write("\n## CRS-999 — orphan\n\nUnallocated input.\n")
    with pytest.raises(ValueError, match="orphan customer"):
        TraceabilityFlow(root).validate()


def test_reject_broken_tds_link(tmp_path: Path) -> None:
    root = _copy_specs(tmp_path)
    path = root / "requirements.yaml"
    text = path.read_text(encoding="utf-8")
    text = text.replace("spec_refs: [TDS-001]", "spec_refs: [TDS-999]", 1)
    path.write_text(text, encoding="utf-8")
    with pytest.raises(ValueError, match="unknown technical reference"):
        QualificationFlow.validate_spec_bundle(root, ip_name="gpio")


def test_reject_duplicate_tds(tmp_path: Path) -> None:
    root = _copy_specs(tmp_path)
    with (root / "ip.md").open("a", encoding="utf-8") as file:
        file.write("\n### TDS-001 — duplicate\n\nCustomer refs: CRS-001\n")
    with pytest.raises(ValueError, match="duplicate TDS"):
        TraceabilityFlow(root).validate()


def test_old_spec_without_crs_stays_valid(tmp_path: Path) -> None:
    root = _copy_specs(tmp_path)
    (root / "customer.md").unlink()
    spec = QualificationFlow.validate_spec_bundle(root, ip_name="gpio")
    assert spec["spec_traceability"]["status"] == "NOT_CONFIGURED"
    assert "customer.md" not in spec["hashes"]


def test_optional_customer_hash_is_part_of_release_contract(tmp_path: Path) -> None:
    root = _copy_specs(tmp_path)
    before = QualificationFlow.validate_spec_bundle(root, ip_name="gpio")
    assert "customer.md" in before["hashes"]
    with (root / "customer.md").open("a", encoding="utf-8") as file:
        file.write("\nEditorial revision.\n")
    after = QualificationFlow.validate_spec_bundle(root, ip_name="gpio")
    assert before["fingerprint"] != after["fingerprint"]


def test_planned_uart_master_response_not_claimed_qualified() -> None:
    root = REPO / "hw/ips/uart_master/1.0.0/spec"
    data = yaml.safe_load((root / "requirements.yaml").read_text(encoding="utf-8"))
    response = next(item for item in data["requirements"] if item["id"] == "UM-RESP-001")
    assert response["status"] == "planned"
    mapping = TraceabilityFlow(root).validate()
    assert "read_response_format" in mapping["testplan_to_tests"]["UM-TP-006"]["model"]
    assert mapping["status"] == "MAPPED_NOT_EXECUTED"


def test_model_results_require_matching_spec_and_sources(tmp_path: Path) -> None:
    import hashlib
    import json

    root = REPO / "hw/ips/gpio/1.0.0"
    spec = QualificationFlow.validate_spec_bundle(root / "spec", ip_name="gpio")
    model_dir = root / "interfaces/tlul/dv/functional/py"
    inputs = {
        filename: hashlib.sha256((model_dir / filename).read_bytes()).hexdigest()
        for filename in sorted(path.name for path in model_dir.glob("*.py"))
    }
    summary = tmp_path / "summary.json"
    summary.write_text(json.dumps({
        "ip": "gpio", "status": "PASS", "contract_fingerprint": spec["fingerprint"],
        "inputs_sha256": inputs, "cases": {"input_filter": "PASS", "interrupt_levels": "PASS"},
    }), encoding="utf-8")
    view = TraceabilityFlow.model_evidence(
        report=spec["spec_traceability"], summary=summary,
        fingerprint=spec["fingerprint"], model_dir=model_dir, ip="gpio",
    )
    assert view["status"] == "PASS"
    stale = TraceabilityFlow.model_evidence(
        report=spec["spec_traceability"], summary=summary,
        fingerprint="invalidated-spec", model_dir=model_dir, ip="gpio",
    )
    assert stale["status"] == "STALE"
    assert set(stale["cases"].values()) == {"NOT_RUN"}


def test_execution_matrix_reads_both_stages_without_claiming_qualification(tmp_path: Path) -> None:
    import json

    report = TraceabilityFlow(REPO / "hw/ips/gpio/1.0.0/spec").validate()
    summary = tmp_path / "regression" / "summary.json"
    summary.parent.mkdir()
    summary.write_text(json.dumps({
        "top": "gpio", "status": "FAILED", "backends": ["sv", "cocotb"],
        "matrix": {
            "input_filter": {"sv": {"status": "PASS", "log": "sv/filter.log"},
                             "cocotb": {"status": "FAILED", "log": "cocotb/filter.log"}},
            "interrupt_levels": {"sv": {"status": "PASS"}, "cocotb": {"status": "PASS"}},
        },
    }))
    rtl = TraceabilityFlow.rtl_evidence(report=report, summary=summary, ip="gpio")
    assert rtl["status"] == "FAILED"
    assert rtl["provenance"] == "NOT_VERIFIED"
    assert rtl["tests"]["input_filter"]["cocotb"]["reported"] == "FAILED"
    model = {"status": "PASS", "cases": {"input_filter": "PASS", "interrupt_levels": "PASS"}}
    matrix = TraceabilityFlow.execution_matrix(report=report, model=model, rtl=rtl)
    assert matrix["GPIO-TP-002"]["model"]["input_filter"] == "PASS"
    assert matrix["GPIO-TP-002"]["rtl"]["input_filter"]["cocotb"]["reported"] == "FAILED"
    assert matrix["GPIO-TP-003"]["model"] == {}
    assert matrix["GPIO-TP-003"]["properties"] == ["gpio_prove"]


def test_rtl_evidence_absent_and_mismatched_top_cannot_be_pass(tmp_path: Path) -> None:
    import json

    report = TraceabilityFlow(REPO / "hw/ips/gpio/1.0.0/spec").validate()
    summary = tmp_path / "summary.json"
    assert TraceabilityFlow.rtl_evidence(report=report, summary=summary, ip="gpio")["status"] == "NOT_RUN"
    summary.write_text(json.dumps({"top": "uart", "status": "PASS", "matrix": {}, "backends": ["sv"]}))
    assert TraceabilityFlow.rtl_evidence(report=report, summary=summary, ip="gpio")["status"] == "INVALID"
