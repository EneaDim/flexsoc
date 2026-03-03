from __future__ import annotations

import json
import os
import subprocess
import sys
from pathlib import Path


def _run(*args: str, env=None):
    e = os.environ.copy()
    if env:
        e.update(env)
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
        env=e,
    )


def _latest_runner_dir(ws: Path, suffix: str) -> Path:
    runs_root = ws / "runs"
    assert runs_root.exists(), f"Missing runs root: {runs_root}"
    dirs = sorted([d for d in runs_root.iterdir() if d.is_dir() and d.name.endswith(suffix)])
    assert dirs, f"No runner dirs ending with {suffix} under {runs_root}. Existing: {[d.name for d in runs_root.iterdir() if d.is_dir()]}"
    return dirs[-1]


def test_make_list_targets():
    p = _run("make", "--list")
    assert p.returncode == 0
    out = p.stdout
    # Rich may wrap title; assert stable table content instead
    assert "Target" in out
    assert "flow" in out


def test_make_help_creates_runner_logs_and_manifest(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    p = _run("make", "help", "--workspace", str(ws))
    assert p.returncode == 0

    # Summary must be on stderr (keep stdout clean for piping / JSON)
    assert "Runner dir:" in p.stderr
    assert "Runner dir:" not in p.stdout

    # Don't parse stdout (Rich wraps). Discover runner dir from workspace.
    runner_dir = _latest_runner_dir(ws, "_make_help")
    assert runner_dir.exists()

    stdout_log = runner_dir / "stdout.log"
    stderr_log = runner_dir / "stderr.log"
    manifest = runner_dir / "manifest.json"

    assert stdout_log.exists(), f"Missing {stdout_log}"
    assert stderr_log.exists(), f"Missing {stderr_log}"
    assert manifest.exists(), f"Missing {manifest}"

    m = json.loads(manifest.read_text(encoding="utf-8"))
    assert m["exit_code"] == 0
    assert "cmd" in m
    assert "signature" in m
