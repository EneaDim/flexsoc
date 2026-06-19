"""CLI tests for multi-step execution and backend tool paths."""

from __future__ import annotations

import json
from pathlib import Path

from typer.testing import CliRunner

from flexsoc.cli import app


def test_step_command_accepts_multiple_targets_for_dry_run() -> None:
    """The CLI can preview several space-separated steps in order."""

    result = CliRunner().invoke(
        app,
        ["step", "setup", "hjson_gen", "--dry-run", "--json", "--set", "TOP=demo"],
    )

    assert result.exit_code == 0, result.output
    payload = json.loads(result.output)
    assert [item["request"]["target"] for item in payload] == ["setup", "hjson_gen"]


def test_step_command_renders_multi_step_script_preview() -> None:
    """The CLI can render a copy-ready script for multiple step previews."""

    result = CliRunner().invoke(app, ["step", "reg", "doc", "--dry-run", "--script"])

    assert result.exit_code == 0, result.output
    assert result.output.startswith("#!/usr/bin/env bash")
    assert " reg " in result.output
    assert " doc " in result.output


def test_backend_makefile_uses_repo_root_and_python_tools() -> None:
    """Backend tools are rooted at the repository and run via the Python interpreter."""

    text = Path("src/flexsoc/backend/Makefile").read_text()

    assert "REPO_ROOT    ?= $(abspath $(THIS_MK_DIR)/../../..)" in text
    assert "REGTOOL     ?= $(UTILROOT)/regtool.py" in text
    assert "$(PYTHON) $(REGTOOL)" in text
