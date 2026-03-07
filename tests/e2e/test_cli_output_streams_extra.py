from __future__ import annotations

import json
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


def test_dump_registry_is_stdout_only_json():
    p = _run("dump-registry")
    assert p.returncode == 0
    assert p.stderr == ""
    data = json.loads(p.stdout)
    assert "actions" in data


def test_actions_ui_goes_to_stderr():
    p = _run("actions")
    assert p.returncode == 0
    assert "Action" in p.stderr
