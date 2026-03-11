from __future__ import annotations

import subprocess
import sys


def run_cli(*args: str):
    return subprocess.run(
        [sys.executable, "-m", "flexsoc.cli", *args],
        capture_output=True,
        text=True,
        check=False,
    )


def test_quickstart_entrypoint():
    res = run_cli("q")
    assert res.returncode == 0
    assert "Quickstart" in res.stderr


def test_tutorials_entrypoint():
    res = run_cli("t")
    assert res.returncode == 0
    assert "Tutorials" in res.stderr


def test_ip_guide_entrypoint():
    res = run_cli("ip")
    assert res.returncode == 0
    assert "IP flow guide" in res.stderr
