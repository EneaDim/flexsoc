"""Deferral file policy is independent from qualification orchestration."""

import json

import pytest

from flexsoc.backend.release.deferrals import QualificationDeferrals


def test_missing_file_has_no_deferrals(tmp_path):
    assert QualificationDeferrals.load(tmp_path / "missing.json", fingerprint="f", allowed_stages=("lint",)) == {}


def test_valid_deferral_preserves_metadata(tmp_path):
    entry = {"stage": "lint", "reason": "review", "owner": "dv", "resolve_by": "release", "fingerprint": "f"}
    path = tmp_path / "qualification_deferrals.json"
    path.write_text(json.dumps({"schema": 1, "deferrals": [entry]}))
    assert QualificationDeferrals.load(path, fingerprint="f", allowed_stages=("lint",)) == {"lint": entry}


@pytest.mark.parametrize("entries,reason", [
    ([{"stage": "lint", "reason": "r", "owner": "o", "resolve_by": "d", "fingerprint": "old"}], "stale"),
    ([{"stage": "unknown", "reason": "r", "owner": "o", "resolve_by": "d", "fingerprint": "f"}], "unknown"),
    ([{"stage": "lint", "reason": "r", "owner": "o", "resolve_by": "d", "fingerprint": "f"}] * 2, "duplicate"),
])
def test_reject_invalid_deferrals(tmp_path, entries, reason):
    path = tmp_path / "qualification_deferrals.json"
    path.write_text(json.dumps({"schema": 1, "deferrals": entries}))
    with pytest.raises(ValueError, match=reason):
        QualificationDeferrals.load(path, fingerprint="f", allowed_stages=("lint",))
