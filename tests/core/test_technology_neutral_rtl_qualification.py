"""L1/L2 qualification is a source-level property, not a PDK result."""

import json

import pytest

from flexsoc.backend.release.qualification import QualificationFlow


def _report(pdk):
    return {
        "ip": "uart", "reg_interface": "tlul", "pdk": pdk,
        "contract_fingerprint": "sha-demo", "requested_level": 2,
        "levels": {
            "1": {"status": "PASS"}, "2": {"status": "PASS"},
            "3": {"status": "BLOCKED", "blocking_evidence": ["syn"]},
        },
        "evidence": {"lint": "PASS", "model_tests": "PASS", "syn": "MISSING"},
        "outcomes": {"lint": "PASS", "syn": None},
        "freshness": {"lint": "CLEAN", "syn": "MISSING"},
    }


def test_rtl_report_is_pdk_independent_and_idempotent():
    a = QualificationFlow.rtl_qualification_report(_report("sky130"))
    b = QualificationFlow.rtl_qualification_report(_report("ihp-sg13g2"))
    assert a == b
    assert a == QualificationFlow.rtl_qualification_report(a)
    assert a["maximum_level"] == 2
    assert "pdk" not in a
    assert "3" not in a["levels"]
    assert "syn" not in a["evidence"]


def test_rtl_report_written_in_common_meta(tmp_path):
    path = QualificationFlow.write_rtl_qualification_report(tmp_path, _report("sky130"))
    assert path == tmp_path / "meta" / "rtl_qualification.json"
    assert json.loads(path.read_text()) == QualificationFlow.rtl_qualification_report(_report("ihp-sg13g2"))
