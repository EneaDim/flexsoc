from __future__ import annotations

import subprocess
import sys


def _run(*args: str):
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
    )


def test_actions_list_contains_known_actions():
    p = _run("actions")
    assert p.returncode == 0
    # must show some known action ids from registry
    out = p.stdout
    assert "ip_start" in out
    assert "lint" in out


def test_action_detail_shows_params_and_examples():
    p = _run("action", "ip_start")
    assert p.returncode == 0
    out = p.stdout
    assert "Action info" in out
    assert "Parameters" in out
    # from registry params
    assert "top" in out
    # examples panel
    assert "Examples" in out or "Usage" in out


def test_help_action_alias():
    p = _run("help", "action", "ip_start")
    assert p.returncode == 0
    assert "Action info" in p.stdout
