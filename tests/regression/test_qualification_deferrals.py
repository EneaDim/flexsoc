"""Engineering deferrals cannot turn a failed technical gate into a release PASS."""
from flexsoc.backend.release.qualification import QualificationFlow


def _report(deferrals=None):
    return QualificationFlow.build_qualification_report(
        ip_name="generic_ip", reg_interface="tlul", pdk="sky130",
        spec={"fingerprint": "abc", "required_evidence": ["lint", "cdc_rdc"],
              "baselined_requirements": 0, "covered_requirements": 0},
        stage_states={"lint": "CLEAN", "cdc_rdc": "CLEAN"},
        stage_outcomes={"lint": "PASS", "cdc_rdc": "FAILED"},
        contract_ready=True, requested_level="rtl", deferrals=deferrals,
    )


def test_failure_is_preserved_with_engineering_deferral():
    note = {"cdc_rdc": {"stage":"cdc_rdc", "owner":"team", "reason":"clock mux", "resolve_by":"pre-signoff", "fingerprint":"abc"}}
    report = _report(note)
    assert report["evidence"]["cdc_rdc"] == "FAILED"
    assert report["levels"]["2"]["status"] == "BLOCKED"
    assert report["target_satisfied"] is False
    assert "cdc_rdc" in report["levels"]["2"]["deferred_evidence"]
    assert report["maximum_level"] == 1


def test_no_deferral_stays_blocking():
    report = _report()
    assert report["levels"]["2"]["deferred_evidence"] == []
    assert "cdc_rdc" in report["levels"]["2"]["development_blocking_evidence"]
