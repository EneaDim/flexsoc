from __future__ import annotations

import json
import os
import subprocess
import sys
from pathlib import Path


def _run(*args: str, env=None):
    repo_root = Path(__file__).resolve().parents[2]
    src = str(repo_root / "src")
    merged_env = os.environ.copy()
    merged_env["PYTHONPATH"] = src + (":" + merged_env["PYTHONPATH"] if merged_env.get("PYTHONPATH") else "")
    if env:
        merged_env.update(env)
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
        env=merged_env,
    )


def _out(p: subprocess.CompletedProcess[str]) -> str:
    return (p.stdout or "") + (p.stderr or "")


def _latest_runner_dir(ws: Path, suffix: str) -> Path:
    runs_root = ws / "sessions"
    assert runs_root.exists(), f"Missing runs root: {runs_root}"
    dirs = sorted([d for d in runs_root.iterdir() if d.is_dir() and d.name.endswith(suffix)])
    assert dirs, f"No runner dirs ending with {suffix} under {runs_root}. Existing: {[d.name for d in runs_root.iterdir() if d.is_dir()]}"
    return dirs[-1]


def test_make_list_targets():
    p = _run("make", "--list")
    assert p.returncode == 0
    out = _out(p)
    assert "Target" in out
    assert "help" in out


def test_make_help_creates_runner_logs_and_manifest(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    p = _run("make", "help", "--workspace", str(ws))
    assert p.returncode == 0
    assert "Runner dir:" in p.stderr
    assert "Runner dir:" not in p.stdout

    runner_dir = _latest_runner_dir(ws, "_make_help")
    assert runner_dir.exists()

    stdout_log = runner_dir / "stdout.log"
    stderr_log = runner_dir / "stderr.log"
    manifest = runner_dir / "manifest.json"

    assert stdout_log.exists()
    assert stderr_log.exists()
    assert manifest.exists()

    m = json.loads(manifest.read_text(encoding="utf-8"))
    assert m["exit_code"] == 0
    assert "cmd" in m
    assert "signature" in m


def test_make_help_with_run_metadata(tmp_path: Path):
    ws = tmp_path / "workspace"
    ws.mkdir(parents=True, exist_ok=True)

    p = _run("make", "help", "--workspace", str(ws), "--run-top", "spi_host", "--run-id", "dev1", "--top", "spi_host")
    assert p.returncode == 0

    run_dir = ws / "runs" / "spi_host" / "dev1"
    assert (run_dir / "run.yaml").exists()
    assert (run_dir / "manifest.json").exists()
    hist = run_dir / "history"
    assert hist.exists()
    assert list(hist.glob("*.json"))
