"""The functional index is a derived regression output, not an authored source."""

import json

from flexsoc.backend.core.flow.lifecycle import STAGE_CONTRACTS
from flexsoc.backend.release.qualification import EvidenceOwnership


def test_regression_owns_derived_functional_summary(tmp_path):
    assert "dv/functional/summary.json" in STAGE_CONTRACTS["regression"].owned_outputs

    meta = tmp_path / "meta"
    meta.mkdir()
    (meta / "provenance.json").write_text(json.dumps({
        "stages": {"regression": {"generated": [{
            "path": "dv/functional/regression/summary.json",
        }]}}
    }))
    baseline = {
        "dv/functional/summary.json": "old-summary-hash",
        "dv/functional/py/model.py": "model-hash",
        "rtl/uart.sv": "rtl-hash",
    }
    owned = EvidenceOwnership.from_provenance(tmp_path, "ihp-sg13g2", baseline)
    assert owned.generated["dv/functional/summary.json"]["stage"] == "regression"
    assert owned.sources["dv/functional/py/model.py"] == "model-hash"
    assert owned.sources["rtl/uart.sv"] == "rtl-hash"


def test_unrecorded_regression_may_not_reclassify_functional_summary(tmp_path):
    (tmp_path / "meta").mkdir()
    (tmp_path / "meta/provenance.json").write_text(json.dumps({"stages": {}}))
    owned = EvidenceOwnership.from_provenance(
        tmp_path, "ihp-sg13g2", {"dv/functional/summary.json": "old-hash"}
    )
    assert "dv/functional/summary.json" in owned.sources
    assert not owned.generated
