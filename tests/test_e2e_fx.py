"""Opt-in end-to-end test that launches the scratch IP-development flow."""

from __future__ import annotations

import os
import re
import shlex
import shutil
import subprocess
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
SETTINGS_FILE = ROOT / ".flexsoc" / "settings.json"
RUN_DIR = ROOT / "workspace" / "runs" / "test" / "dev"
SETTINGS = ("settings", "TOP=test", "RUN_TOP=test", "RUN_ID=dev", "HOST=uart")
FLOW = (
    "setup",
    "hjson",
    "reg",
    "doc",
    "rtl_stub",
    "lint",
    "setup_model",
    "setup_tb",
    "setup_cocotb",
    "sim",
    "cocotb",
    "sim_tests",
    "syn",
    "sdf",
    "sta",
    "power",
    "--force",
)

pytestmark = [
    pytest.mark.e2e,
    pytest.mark.skipif(
        os.environ.get("FLEXSOC_RUN_E2E") != "1",
        reason="set FLEXSOC_RUN_E2E=1 or run `make test-e2e`",
    ),
]


def _fx() -> list[str]:
    """Return the configured fx launcher."""

    return shlex.split(os.environ.get("FLEXSOC_E2E_FX", "fx"))


def _env() -> dict[str, str]:
    """Import this checkout before any installed package."""

    env = os.environ.copy()
    extra = os.pathsep + env["PYTHONPATH"] if env.get("PYTHONPATH") else ""
    env["PYTHONPATH"] = str(ROOT / "src") + extra
    return env


def _run_fx(tmp_path: Path, *args: str) -> None:
    """Run one real fx command and save its combined log."""

    cmd = [*_fx(), *args]
    done = subprocess.run(
        cmd,
        cwd=ROOT,
        env=_env(),
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        timeout=int(os.environ.get("FLEXSOC_E2E_TIMEOUT", "1200")),
        check=False,
    )
    name = re.sub(r"[^A-Za-z0-9_.-]+", "_", "_".join(args))[:180] or "fx"
    log = tmp_path / f"{name}.log"
    log.write_text(done.stdout, encoding="utf-8")
    assert done.returncode == 0, f"failed: {shlex.join(cmd)}\nlog: {log}\n{done.stdout}"


def test_e2e_fx_scratch_ip_flow(tmp_path: Path) -> None:
    """Run the current scratch-IP generation, verification, and signoff flow."""

    old_settings = SETTINGS_FILE.read_bytes() if SETTINGS_FILE.exists() else None
    shutil.rmtree(RUN_DIR, ignore_errors=True)
    try:
        _run_fx(tmp_path, *SETTINGS)
        _run_fx(tmp_path, *FLOW)
        assert (RUN_DIR / "rtl" / "test.sv").exists()
        assert (RUN_DIR / "rtl" / "test_core.sv").exists()
        assert (RUN_DIR / "tb" / "tests" / "smoke" / "data_in.vec").exists()
        assert (RUN_DIR / "tb" / "tests" / "smoke" / "data_out.vec").exists()
        assert (RUN_DIR / "tb" / "cocotb" / "Makefile").exists()
        assert (RUN_DIR / "logs").exists()
    finally:
        if old_settings is None:
            SETTINGS_FILE.unlink(missing_ok=True)
        else:
            SETTINGS_FILE.parent.mkdir(parents=True, exist_ok=True)
            SETTINGS_FILE.write_bytes(old_settings)
