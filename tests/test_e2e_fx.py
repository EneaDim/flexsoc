from __future__ import annotations

import os
from pathlib import Path
import subprocess
from typing import Iterable

import pytest


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_RUN_ID = "dev"
DEFAULT_HOST = "uart"


# -----------------------------------------------------------------------------
# Small command helpers
# -----------------------------------------------------------------------------


def _enabled() -> bool:
    """Return True when the long E2E flow was explicitly requested."""
    return os.environ.get("FLEXSOC_RUN_E2E") == "1" or os.environ.get("FLEXSOC_RUN_FULL_FLOW") == "1"


def _live() -> bool:
    """Return True when fx should stream full tool output with --live."""
    return os.environ.get("FLEXSOC_E2E_LIVE") == "1" or os.environ.get("FLEXSOC_FULL_FLOW_LIVE") == "1"


def _skip_signoff() -> bool:
    """Return True when synthesis/signoff should be skipped for quicker debug."""
    return os.environ.get("FLEXSOC_E2E_SKIP_SIGNOFF") == "1" or os.environ.get("FLEXSOC_FULL_FLOW_SKIP_SIGNOFF") == "1"


def _print_section(title: str) -> None:
    """Print a large readable section header for pytest -s runs."""
    print("\n" + "=" * 72, flush=True)
    print(title, flush=True)
    print("=" * 72, flush=True)


def _print_step(args: Iterable[str]) -> None:
    """Print one command before executing it."""
    print("\n>>> fx " + " ".join(args), flush=True)


def _recent_logs(top: str, run_id: str, limit: int = 8) -> list[Path]:
    """Return the most recently modified log files for one run."""
    log_root = REPO_ROOT / "workspace" / "runs" / top / run_id / "logs"
    if not log_root.exists():
        return []
    logs = [p for p in log_root.rglob("*") if p.is_file()]
    return sorted(logs, key=lambda p: p.stat().st_mtime)[-limit:]


def _dump_recent_logs(top: str, run_id: str) -> None:
    """Print recent log paths and the tail of the latest log after a failure."""
    logs = _recent_logs(top, run_id)
    print(f"\n[debug] recent logs for TOP={top} RUN_ID={run_id}:", flush=True)
    if not logs:
        print("[debug] no logs found", flush=True)
        return

    for log in logs:
        print(f"  {log}", flush=True)

    latest = logs[-1]
    print(f"\n[debug] tail -120 {latest}", flush=True)
    try:
        lines = latest.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError as exc:
        print(f"[debug] could not read {latest}: {exc}", flush=True)
        return
    for line in lines[-120:]:
        print(line, flush=True)


def _run_fx(args: list[str], *, top: str | None = None, run_id: str = DEFAULT_RUN_ID) -> None:
    """Run one fx command and show useful context if it fails."""
    full_args = list(args)
    if _live() and full_args and full_args[0] != "settings" and "--live" not in full_args:
        full_args.append("--live")

    _print_step(full_args)
    completed = subprocess.run(["fx", *full_args], cwd=REPO_ROOT, check=False)
    if completed.returncode == 0:
        return

    if top is not None:
        _dump_recent_logs(top, run_id)
    pytest.fail(f"fx {' '.join(full_args)} failed with exit code {completed.returncode}")


def _settings(top: str, *, clock_mode: str, run_id: str = DEFAULT_RUN_ID, host: str = DEFAULT_HOST) -> None:
    """Select one run configuration before launching flow targets."""
    _run_fx([
        "settings",
        f"TOP={top}",
        f"RUN_TOP={top}",
        f"RUN_ID={run_id}",
        f"HOST={host}",
        f"CLOCK_MODE={clock_mode}",
    ])


# -----------------------------------------------------------------------------
# Flow sections
# -----------------------------------------------------------------------------


def _run_rtl_generation(top: str, *, run_id: str = DEFAULT_RUN_ID) -> None:
    """Generate setup, regmap, RTL core/wrapper and filelists."""
    _run_fx(["setup", "--force"], top=top, run_id=run_id)
    _run_fx(["hjson", "--force"], top=top, run_id=run_id)
    _run_fx(["reg", "doc", "--force"], top=top, run_id=run_id)
    _run_fx(["rtl_stub", "--force"], top=top, run_id=run_id)
    _run_fx(["top_from_core", "--force"], top=top, run_id=run_id)
    _run_fx(["flist", "--force"], top=top, run_id=run_id)


def _run_lint_suite(top: str, *, run_id: str = DEFAULT_RUN_ID) -> None:
    """Run the general lint plus focused lint diagnostics."""
    _run_fx(["lint"], top=top, run_id=run_id)
    _run_fx(["lint_latch"], top=top, run_id=run_id)
    _run_fx(["lint_width"], top=top, run_id=run_id)
    _run_fx(["lint_unconnected"], top=top, run_id=run_id)
    _run_fx(["lint_undriven"], top=top, run_id=run_id)
    _run_fx(["lint_unused"], top=top, run_id=run_id)


def _run_model_and_verification(top: str, *, run_id: str = DEFAULT_RUN_ID) -> None:
    """Generate the editable model, vectors, TB scaffolds and all tests."""
    _run_fx(["setup_model", "--force"], top=top, run_id=run_id)
    _run_fx(["tests_gen"], top=top, run_id=run_id)
    _run_fx(["tests"], top=top, run_id=run_id)
    _run_fx(["setup_tb", "--force"], top=top, run_id=run_id)
    _run_fx(["setup_cocotb", "--force"], top=top, run_id=run_id)
    _run_fx(["sim_tests"], top=top, run_id=run_id)
    _run_fx(["cocotb_tests"], top=top, run_id=run_id)


def _run_signoff(top: str, *, run_id: str = DEFAULT_RUN_ID, multi_clock: bool = False) -> None:
    """Run SDC generation when needed and the synthesis/signoff targets."""
    if _skip_signoff():
        print("\n>>> skip signoff because FLEXSOC_E2E_SKIP_SIGNOFF=1", flush=True)
        return
    if multi_clock:
        _run_fx(["sdc_multi", "--force"], top=top, run_id=run_id)
    _run_fx(["syn", "sdf", "sta", "power", "--force"], top=top, run_id=run_id)


def _run_single_clock_flow() -> None:
    """Run the full single-clock example flow."""
    top = os.environ.get("FLEXSOC_SINGLE_TOP", "test")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"single-clock full flow: TOP={top} RUN_ID={run_id}")
    _settings(top, clock_mode="single", run_id=run_id, host=host)
    _run_rtl_generation(top, run_id=run_id)
    _run_lint_suite(top, run_id=run_id)
    _run_model_and_verification(top, run_id=run_id)
    _run_signoff(top, run_id=run_id, multi_clock=False)


def _run_multi_clock_flow() -> None:
    """Run the full multi-clock example flow."""
    top = os.environ.get("FLEXSOC_MULTI_TOP", "tri_stream_dsp")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"multi-clock full flow: TOP={top} RUN_ID={run_id}")
    _settings(top, clock_mode="multi", run_id=run_id, host=host)
    _run_rtl_generation(top, run_id=run_id)
    _run_lint_suite(top, run_id=run_id)
    _run_model_and_verification(top, run_id=run_id)
    _run_signoff(top, run_id=run_id, multi_clock=True)


# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------


@pytest.mark.e2e
def test_fx_full_flow_debug() -> None:
    """Run the complete single-clock and multi-clock FlexSoC flows."""
    if not _enabled():
        pytest.skip("set FLEXSOC_RUN_E2E=1 or FLEXSOC_RUN_FULL_FLOW=1 to run the full flow")

    _print_section("FlexSoC full-flow debug regression")
    print(f"repo: {REPO_ROOT}", flush=True)
    print(f"live output: {_live()}", flush=True)
    print(f"skip signoff: {_skip_signoff()}", flush=True)

    _run_single_clock_flow()
    _run_multi_clock_flow()

    _print_section("FlexSoC full-flow debug regression passed")
