"""CLI contracts for running multiple flow steps in one call."""

from __future__ import annotations

from typer.testing import CliRunner

from flexsoc.cli import app


def test_step_multi_dry_run_reuses_one_implicit_run_id() -> None:
    """A single `fx step a b` call must pass one RUN_ID to every Make step."""

    result = CliRunner().invoke(app, ["step", "hjson_gen", "reg", "doc", "--dry-run", "--script"])

    assert result.exit_code == 0
    lines = [line for line in result.output.splitlines() if line.startswith("make ")]
    assert len(lines) == 3

    run_ids = []
    for line in lines:
        fields = dict(field.split("=", 1) for field in line.split() if "=" in field)
        run_ids.append(fields["RUN_ID"])

    assert len(set(run_ids)) == 1


def test_step_multi_dry_run_keeps_explicit_run_id() -> None:
    """An explicit RUN_ID must be preserved across every requested step."""

    result = CliRunner().invoke(
        app,
        ["step", "hjson_gen", "reg", "doc", "--dry-run", "--script", "--set", "RUN_ID=manual"],
    )

    assert result.exit_code == 0
    assert result.output.count("RUN_ID=manual") == 3
