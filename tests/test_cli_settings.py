"""Framework tests for project-level CLI settings."""

from __future__ import annotations

import json
from pathlib import Path

from typer.testing import CliRunner

from flexsoc.cli import app


def test_settings_command_persists_project_defaults(tmp_path: Path) -> None:
    """The CLI can save settings that later appear in the resolved payload."""

    runner = CliRunner()
    result = runner.invoke(
        app,
        [
            "settings",
            "--project-root",
            str(tmp_path),
            "--set",
            "TOP=demo",
            "--set",
            "HOST=apb",
            "--json",
        ],
    )

    assert result.exit_code == 0
    payload = json.loads(result.output)
    assert payload["resolved"]["TOP"] == "demo"
    assert payload["resolved"]["HOST"] == "apb"
    assert (tmp_path / ".flexsoc" / "settings.json").exists()


def test_settings_command_resets_project_defaults(tmp_path: Path) -> None:
    """The CLI can remove saved settings and fall back to defaults."""

    runner = CliRunner()
    runner.invoke(app, ["settings", "--project-root", str(tmp_path), "--set", "TOP=demo"])
    result = runner.invoke(app, ["settings", "--project-root", str(tmp_path), "--reset", "--json"])

    assert result.exit_code == 0
    payload = json.loads(result.output)
    assert payload["saved"] == {}
    assert payload["resolved"]["TOP"] == "test"
