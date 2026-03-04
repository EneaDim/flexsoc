from __future__ import annotations

import subprocess
from pathlib import Path
import os
import sys


def _run(*args: str):
    # Ensure subprocesses can import flexsoc when using system python
    repo_root = Path(__file__).resolve().parents[2]
    src = str(repo_root / "src")
    env = os.environ.copy()
    env["PYTHONPATH"] = src + (":" + env["PYTHONPATH"] if env.get("PYTHONPATH") else "")
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
        env=env)


def test_hub_no_args():
    p = _run()
    assert p.returncode == 0
    assert "flexsoc" in p.stdout
    assert "Quick actions" in p.stdout or "Quick actions" in p.stderr  # rich can split streams


def test_hub_shortcuts():
    for cmd in (["?"], ["h"]):
        p = _run(*cmd)
        assert p.returncode == 0
        assert "flexsoc" in p.stdout


def test_help_topics():
    p = _run("help", "topics")
    assert p.returncode == 0
    assert "Help topics" in p.stdout


def test_quickstart_tutorial_ip_guides():
    cases = [
        (["q"], "Quickstart"),
        (["t"], "Tutorial"),
        (["ip"], "IP flow guide"),
    ]
    for argv, needle in cases:
        p = _run(*argv)
        assert p.returncode == 0
        assert needle in p.stdout
