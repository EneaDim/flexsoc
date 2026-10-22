"""Generic elaboration sidecar contract tests."""
import json
import pytest

from flexsoc.backend.dv.func.rtl_parameters import read_rtl_parameters, write_rtl_parameters


def test_missing_sidecar_preserves_defaults(tmp_path):
    assert read_rtl_parameters(tmp_path) == {}


def test_roundtrip(tmp_path):
    write_rtl_parameters(tmp_path, {"SIZE": 8, "MODE": "1'b1"})
    assert read_rtl_parameters(tmp_path) == {"MODE": "1'b1", "SIZE": 8}


@pytest.mark.parametrize("params", [{"bad-name": 1}, {"MODE": True}, {"MODE": [1]}, {"MODE": "bad\nvalue"}])
def test_invalid_requests_fail_closed(tmp_path, params):
    (tmp_path / "rtl_parameters.json").write_text(json.dumps({"schema": 1, "parameters": params}))
    with pytest.raises(ValueError):
        read_rtl_parameters(tmp_path)
