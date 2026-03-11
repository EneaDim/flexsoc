from __future__ import annotations

import subprocess
import sys
from pathlib import Path


def run_cli(*args: str):
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
        check=False,
    )


def test_doctor_command_exists():
    res = run_cli("doctor")
    assert res.returncode in (0, 1)
    combined = res.stdout + res.stderr
    assert "python deps" in combined.lower()


def test_clean_pycache_command(tmp_path: Path):
    pycache_dir = tmp_path / "pkg" / "__pycache__"
    pycache_dir.mkdir(parents=True, exist_ok=True)
    (pycache_dir / "x.pyc").write_bytes(b"123")

    res = run_cli("clean-pycache", "--root", str(tmp_path))
    assert res.returncode == 0
    assert "Removed" in res.stdout
    assert not pycache_dir.exists()


def test_clean_run_command(tmp_path: Path):
    ws = tmp_path / "workspace"
    run_dir = ws / "runs" / "demo" / "dev1"
    run_dir.mkdir(parents=True, exist_ok=True)

    res = run_cli(
        "clean-run",
        "--workspace",
        str(ws),
        "--run-top",
        "demo",
        "--run-id",
        "dev1",
    )
    assert res.returncode == 0
    assert not run_dir.exists()
