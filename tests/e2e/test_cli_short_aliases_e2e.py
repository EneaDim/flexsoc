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


def test_short_aliases_render_pages():
    cases = [
        ("q", "Quickstart"),
        ("t", "Tutorial"),
        ("ip", "IP"),
        ("h", "flexsoc"),
    ]
    for cmd, needle in cases:
        p = _run(cmd)
        assert p.returncode == 0
        assert needle in _out(p)
