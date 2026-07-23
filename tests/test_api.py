"""Minimal checks for the FlexSoC API and fx CLI."""

from __future__ import annotations

import json
import subprocess
from pathlib import Path

from flexsoc import FlexSoC, FlexSoCConfig
from flexsoc.cli import app


ROOT = Path(__file__).resolve().parents[1]
BACKEND_MAKEFILE = ROOT / "src" / "flexsoc" / "backend" / "Makefile"


def _makefile_targets() -> set[str]:
    """Return every target declared in PHONY_TARGETS."""

    targets: set[str] = set()
    for line in BACKEND_MAKEFILE.read_text(encoding="utf-8").splitlines():
        if line.startswith("PHONY_TARGETS +="):
            targets.update(line.split("+=", 1)[1].split())
    return targets


def test_api_catalog_matches_makefile_targets() -> None:
    """The API exposes every callable backend target."""

    assert set(FlexSoC(project_root=ROOT).target_names()) == _makefile_targets()


def test_api_builds_ordered_commands_and_overrides(tmp_path: Path) -> None:
    """Settings, overrides, dashed names, and command order stay explicit."""

    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"), top="base")
    first, second = fx.override(top="cordic").commands("lint-width", "yosys_vgen", RUN_ID="r1")

    assert [first.target, second.target] == ["lint_width", "yosys-vgen"]
    assert first.cwd == tmp_path.resolve()
    assert "TOP=cordic" in first.argv
    assert "RUN_ID=r1" in first.argv
    assert f"WORKSPACE={tmp_path / 'ws'}" in first.argv


def test_api_dry_run_does_not_spawn_processes(monkeypatch, tmp_path: Path) -> None:
    """Dry-run returns previews only."""

    def fail(*args, **kwargs):  # noqa: ANN001, ANN002, ANN003
        raise AssertionError("subprocess.run should not be called")

    monkeypatch.setattr(subprocess, "run", fail)
    result = FlexSoC(project_root=tmp_path).run("setup", "reg", dry_run=True, TOP="demo")

    assert [item.target for item in result] == ["setup", "reg"]
    assert all(item.cwd == tmp_path.resolve() for item in result)


def test_cli_help_settings_commands_and_dry_run(capsys, monkeypatch, tmp_path: Path) -> None:
    """fx keeps Typer help, settings, catalog, and dry-runs minimal."""

    monkeypatch.chdir(tmp_path)

    assert app(["--help"]) == 0
    help_out = capsys.readouterr().out
    assert "IP development" in help_out
    assert "System-on-chip building" in help_out
    assert "--install-completion" in help_out

    assert app(["settings", "TOP=cordic", "RUN_ID=e2e"]) == 0
    assert json.loads((tmp_path / ".flexsoc" / "settings.json").read_text())["TOP"] == "cordic"
    capsys.readouterr()

    assert app(["commands", "--json"]) == 0
    names = {item["name"] for item in json.loads(capsys.readouterr().out)}
    assert {"lint_latch", "lint_width", "top_from_core", "ip_load", "soc_run", "clean_all"} <= names

    assert app(["lint_width", "syn", "--dry-run", "--set", "LINT_PART=all"]) == 0
    out = capsys.readouterr().out
    assert " lint_width " in out
    assert " syn " in out
    assert "TOP=cordic" in out
    assert "LINT_PART=all" in out
