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


def test_hub_no_args():
    p = _run()
    assert p.returncode == 0
    out = _out(p)
    assert "flexsoc" in out
    assert "Overview" in out or "Learn" in out


def test_hub_shortcuts():
    for cmd in (["?"], ["h"]):
        p = _run(*cmd)
        assert p.returncode == 0
        out = _out(p)
        assert "flexsoc" in out


def test_help_topics():
    p = _run("help", "topics")
    assert p.returncode == 0
    out = _out(p)
    assert "flexsoc help" in out or "help" in out.lower()


def test_quickstart_tutorial_ip_guides():
    cases = [
        (["q"], "Quickstart"),
        (["t"], "Tutorial"),
        (["ip"], "IP"),
    ]
    for argv, needle in cases:
        p = _run(*argv)
        assert p.returncode == 0
        assert needle in _out(p)
