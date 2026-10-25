"""Technology-neutral RTL evidence must not be confused with L3+ closure."""

from flexsoc.backend.release.reporting import Reporting


def test_rtl_closure_independent_of_technology() -> None:
    metrics = {"closure": {"stages": {
        "modeling": "pass", "lint": "pass", "cdc_rdc": "pass",
        "formal": "pass", "regression": "pass", "synthesis": "missing",
        "sta": "missing", "implementation": "missing",
    }}}
    result = Reporting.rtl_closure(metrics)
    assert result["status"] == "pass"
    assert result["qualification_authority"] == "fx qualify"
    assert result["complete"] is True


def test_rtl_closure_never_passes_missing_or_failed_evidence() -> None:
    for state, expected in (("missing", "incomplete"), ("fail", "fail"),
                            ("partial", "incomplete"), ("review", "review")):
        metrics = {"closure": {"stages": {
            "modeling": "pass", "lint": "pass", "cdc_rdc": "pass",
            "formal": state, "regression": "pass",
        }}}
        assert Reporting.rtl_closure(metrics)["status"] == expected
    assert Reporting.rtl_closure({})["status"] == "incomplete"
