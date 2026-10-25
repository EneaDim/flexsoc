"""Specific Slang timescale notices must not mask unrelated diagnostics."""

from flexsoc.backend.dv.lint.slang_lint import SlangLint


def test_missing_timescale_is_p3_independent_of_severity():
    lint = SlangLint.__new__(SlangLint)
    message = "design element does not have a time scale defined but others in the design do"
    assert lint._priority( "diagnostic", "warning", message) == "P3"
    assert lint._priority("diagnostic", "error", message) == "P3"
    assert lint._priority("diagnostic", "fatal", "  design element does not have a time scale defined but  others in the design do  ") == "P3"
    assert lint._priority("diagnostic", "error", "unrelated fatal diagnostic") == "P0"
    assert lint._priority( "diagnostic", "warning", "other diagnostic") == "P2"
    assert lint._priority( "width-trunc", "warning", "truncation") == "P0"
