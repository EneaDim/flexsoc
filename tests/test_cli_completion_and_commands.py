"""CLI tests for command discovery and dynamic completion."""

from __future__ import annotations

from typer.testing import CliRunner

from flexsoc.cli import app, _step_name_completion, _workflow_name_completion


def test_commands_renders_chronological_catalog() -> None:
    """The commands view is a human catalog ordered by development phase."""

    result = CliRunner().invoke(app, ["commands"])

    assert result.exit_code == 0, result.output
    assert "fx settings" in result.output
    assert "fx workflows" in result.output
    assert "fx step" in result.output
    assert "fx smoke" in result.output


def test_help_is_chronological() -> None:
    """The extended help guide follows the normal flow lifecycle."""

    result = CliRunner().invoke(app, ["help"])

    assert result.exit_code == 0, result.output
    assert "0. Shell discovery" in result.output
    assert "1. Project settings" in result.output
    assert "4. IP development flow" in result.output
    assert "5. SoC development flow" in result.output


def test_step_completion_uses_api_catalog() -> None:
    """Step completion is driven by the same API catalog used by fx steps."""

    assert "syn" in _step_name_completion("s")
    assert "soc" in _step_name_completion("so")


def test_workflow_completion_uses_api_catalog() -> None:
    """Workflow completion is driven by the public API workflow list."""

    assert "ip_development" in _workflow_name_completion("ip")
    assert "soc_development" in _workflow_name_completion("soc")
