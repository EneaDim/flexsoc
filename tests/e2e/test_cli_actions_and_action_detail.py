from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path


def _run(*args: str):
    repo_root = Path(__file__).resolve().parents[2]
    src = str(repo_root / "src")
    env = os.environ.copy()
    env["PYTHONPATH"] = src + (":" + env["PYTHONPATH"] if env.get("PYTHONPATH") else "")
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
        env=env,
    )


def _out(p: subprocess.CompletedProcess[str]) -> str:
    return (p.stdout or "") + (p.stderr or "")


def test_actions_list_contains_known_actions():
    p = _run("actions")
    assert p.returncode == 0
    out = _out(p)
    assert "ip_start" in out
    assert "lint" in out
    assert "Action" in out


def test_help_action_detail_shows_info():
    p = _run("help", "action", "ip_start")
    assert p.returncode == 0
    out = _out(p)
    assert "ip_start" in out
    assert (
        "Description" in out
        or "Action info" in out
        or "Action:" in out
        or "╭─ Action" in out
        or "Command:" in out
    )


def test_help_action_alias_smoke():
    p = _run("help", "action", "lint")
    assert p.returncode == 0
    out = _out(p)
    assert "lint" in out


def test_action_command_smoke():
    p = _run("action", "ip_start")
    assert p.returncode == 0


def test_action_unknown_does_not_crash():
    p = _run("action", "does_not_exist")
    assert p.returncode == 0
