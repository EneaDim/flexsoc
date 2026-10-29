"""New clock-topology spec scaffolds have usable, explicitly unapproved mappings."""
from pathlib import Path

import pytest
import yaml

from flexsoc.backend.release.qualification import QualificationFlow


@pytest.mark.parametrize(
    "domains,relationships,expected",
    [
        (("core:clk_i:rst_ni:10:low",), (), (3, 5, 5)),
        (("cfg:cfg_clk_i:cfg_rst_ni:20:low", "rx:rx_clk_i:rx_rst_ni:16:low", "dsp:dsp_clk_i:dsp_rst_ni:30:low"),
         ("async:cfg:rx", "async:cfg:dsp", "async:rx:dsp"), (4, 7, 6)),
    ],
)
def test_generated_spec_is_traced_but_not_executed(tmp_path: Path, domains, relationships, expected):
    spec = tmp_path / "spec"
    paths = QualificationFlow.write_spec_scaffold(
        spec, ip_name="my_ip", clock_domains=domains, clock_relationships=relationships,
    )
    assert len(paths) == 3  # existing public return contract preserved
    report = QualificationFlow.validate_spec_bundle(spec, ip_name="my_ip")
    trace = report["spec_traceability"]
    assert trace["status"] == "MAPPED_NOT_EXECUTED"
    assert len(trace["customer_to_technical"]) == expected[0]
    assert len(trace["technical_to_requirements"]) == expected[1]
    assert len(trace["requirements_to_testplan"]) == expected[1]
    assert len(trace["testplan_to_tests"]) == expected[2]
    assert trace["model_cases_to_testplan"]
    assert "not** customer-approved" in (spec / "customer.md").read_text()
    requirements = yaml.safe_load((spec / "requirements.yaml").read_text())
    assert all(row["category"] == "technical" and row["spec_refs"] for row in requirements["requirements"])
    assert "customer.md" in report["hashes"]

    before = {path.name: path.read_bytes() for path in spec.iterdir()}
    (spec / "customer.md").write_text((spec / "customer.md").read_text() + "\nDesigner note.\n")
    QualificationFlow.write_spec_scaffold(spec, ip_name="my_ip", clock_domains=domains, clock_relationships=relationships)
    assert (spec / "customer.md").read_text().endswith("Designer note.\n")
    assert all((spec / name).read_bytes() == data for name, data in before.items() if name != "customer.md")

    QualificationFlow.write_spec_scaffold(spec, ip_name="my_ip", clock_domains=domains, clock_relationships=relationships, force=True)
    assert "Designer note" not in (spec / "customer.md").read_text()
    assert QualificationFlow.validate_spec_bundle(spec, ip_name="my_ip")["spec_traceability"]["status"] == "MAPPED_NOT_EXECUTED"


@pytest.mark.parametrize(
    "domains,relationships",
    [
        (("core:clk_i:rst_ni:10:low",), ()),
        (("cfg:cfg_clk_i:cfg_rst_ni:20:low", "rx:rx_clk_i:rx_rst_ni:16:low"), ("async:cfg:rx",)),
    ],
)
def test_spec_safely_upgrades_untouched_legacy_files(tmp_path, domains, relationships):
    root = tmp_path / "spec"
    root.mkdir()
    if len(domains) > 1:
        legacy_spec, requirements, testplan = QualificationFlow._multi_clock_spec("my_ip", domains, relationships)
    else:
        legacy_spec, requirements, testplan = QualificationFlow._single_clock_spec("my_ip", domains)
    (root / "ip.md").write_text(legacy_spec, encoding="utf-8")
    (root / "requirements.yaml").write_text(yaml.safe_dump(requirements, sort_keys=False, allow_unicode=True))
    (root / "testplan.yaml").write_text(yaml.safe_dump(testplan, sort_keys=False, allow_unicode=True))

    QualificationFlow.write_spec_scaffold(root, ip_name="my_ip", clock_domains=domains, clock_relationships=relationships)
    assert "## CRS-001" in (root / "customer.md").read_text()
    assert "### TDS-001" in (root / "ip.md").read_text()
    assert QualificationFlow.validate_spec_bundle(root, ip_name="my_ip")["spec_traceability"]["status"] == "MAPPED_NOT_EXECUTED"

    before = {f.name: f.read_bytes() for f in root.iterdir()}
    QualificationFlow.write_spec_scaffold(root, ip_name="my_ip", clock_domains=domains, clock_relationships=relationships)
    assert {f.name: f.read_bytes() for f in root.iterdir()} == before


def test_invalid_authored_spec_fails_without_partial_writes(tmp_path):
    root = tmp_path / "spec"
    root.mkdir()
    (root / "ip.md").write_text("# Manually edited IP design without technical headings\n")
    before = (root / "ip.md").read_bytes()
    with pytest.raises(ValueError, match="No files changed.*fx spec --force"):
        QualificationFlow.write_spec_scaffold(
            root, ip_name="my_ip", clock_domains=("core:clk_i:rst_ni:10:low",),
        )
    assert sorted(f.name for f in root.iterdir()) == ["ip.md"]
    assert (root / "ip.md").read_bytes() == before


def test_legacy_bundle_with_preexisting_generated_customer_upgrades(tmp_path):
    root = tmp_path / "spec"
    domains = ("core:clk_i:rst_ni:10:low",)
    QualificationFlow.write_spec_scaffold(root, ip_name="my_ip", clock_domains=domains)
    customer = (root / "customer.md").read_bytes()
    old_spec, requirements, plan = QualificationFlow._single_clock_spec("my_ip", domains)
    (root / "ip.md").write_text(old_spec)
    (root / "requirements.yaml").write_text(yaml.safe_dump(requirements, sort_keys=False, allow_unicode=True))
    (root / "testplan.yaml").write_text(yaml.safe_dump(plan, sort_keys=False, allow_unicode=True))

    QualificationFlow.write_spec_scaffold(root, ip_name="my_ip", clock_domains=domains)
    assert (root / "customer.md").read_bytes() == customer
    assert QualificationFlow.validate_spec_bundle(root, ip_name="my_ip")["spec_traceability"]["status"] == "MAPPED_NOT_EXECUTED"
