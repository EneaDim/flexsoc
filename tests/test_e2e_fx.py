from __future__ import annotations

from pathlib import Path
import os
import subprocess
from typing import Iterable

import pytest


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_RUN_ID = "dev"
DEFAULT_HOST = "uart"


# -----------------------------------------------------------------------------
# Small command helpers
# -----------------------------------------------------------------------------


def _live() -> bool:
    """Return True when fx should stream full tool output with --live."""

    return os.environ.get("FLEXSOC_E2E_LIVE") == "1" or os.environ.get("FLEXSOC_FULL_FLOW_LIVE") == "1"


def _run_signoff_enabled(request: pytest.FixtureRequest) -> bool:
    """Return True unless pytest was launched with --no-signoff."""

    return not bool(request.config.getoption("--no-signoff"))


def _print_section(title: str) -> None:
    """Print a large readable section header for pytest -s runs."""

    print("\n" + "=" * 72, flush=True)
    print(title, flush=True)
    print("=" * 72, flush=True)


def _print_step(args: Iterable[str]) -> None:
    """Print one fx command before executing it."""

    print("\n>>> fx " + " ".join(args), flush=True)


def _recent_logs(top: str, run_id: str, limit: int = 8) -> list[Path]:
    """Return the most recently modified log files for one run."""

    log_root = REPO_ROOT / "workspace" / "runs" / top / run_id / "logs"
    if not log_root.exists():
        return []

    logs = [path for path in log_root.rglob("*") if path.is_file()]
    return sorted(logs, key=lambda path: path.stat().st_mtime)[-limit:]


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
    """Run one fx command and dump useful logs if it fails."""

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

    _run_fx(
        [
            "settings",
            f"TOP={top}",
            f"RUN_TOP={top}",
            f"RUN_ID={run_id}",
            f"HOST={host}",
            f"CLOCK_MODE={clock_mode}",
        ]
    )


# -----------------------------------------------------------------------------
# Shared flow sections
# -----------------------------------------------------------------------------


def _run_generated_rtl_flow(top: str, *, run_id: str = DEFAULT_RUN_ID) -> None:
    """Generate the normal editable RTL/model flow for generated examples."""

    _run_fx(["setup", "--force"], top=top, run_id=run_id)
    _run_fx(["hjson", "--force"], top=top, run_id=run_id)
    _run_fx(["reg", "doc", "--force"], top=top, run_id=run_id)
    _run_fx(["rtl_stub", "--force"], top=top, run_id=run_id)
    _run_fx(["top_from_core", "--force"], top=top, run_id=run_id)
    _run_fx(["flist", "--force"], top=top, run_id=run_id)


def _run_lint_suite(top: str, *, run_id: str = DEFAULT_RUN_ID) -> None:
    """Run lint and focused lint diagnostics."""

    _run_fx(["lint"], top=top, run_id=run_id)
    _run_fx(["lint_latch"], top=top, run_id=run_id)
    _run_fx(["lint_width"], top=top, run_id=run_id)
    _run_fx(["lint_unconnected"], top=top, run_id=run_id)
    _run_fx(["lint_undriven"], top=top, run_id=run_id)
    _run_fx(["lint_unused"], top=top, run_id=run_id)


def _run_generated_model_and_tests(top: str, *, run_id: str = DEFAULT_RUN_ID) -> None:
    """Generate model, tests, SV/cocotb testbenches, and run verification."""

    _run_fx(["setup_model", "--force"], top=top, run_id=run_id)
    _run_fx(["tests_gen"], top=top, run_id=run_id)
    _run_fx(["tests"], top=top, run_id=run_id)
    _run_fx(["setup_tb", "--force"], top=top, run_id=run_id)
    _run_fx(["setup_cocotb", "--force"], top=top, run_id=run_id)
    _run_fx(["sim_tests"], top=top, run_id=run_id)
    _run_fx(["cocotb_tests"], top=top, run_id=run_id)


def _run_loaded_ip_tests(top: str, *, run_id: str = DEFAULT_RUN_ID) -> None:
    """Run verification for an IP loaded from hw/ips without regenerating sources.

    This flow intentionally does not call:
      - hjson
      - reg doc
      - rtl_stub
      - top_from_core
      - setup_model
    """

    _run_fx(["setup", "--force"], top=top, run_id=run_id)
    _run_fx(["ip_load", "--force"], top=top, run_id=run_id)
    _run_fx(["flist", "--force"], top=top, run_id=run_id)

    _run_lint_suite(top, run_id=run_id)

    _run_fx(["regmap_py", "--force"], top=top, run_id=run_id)
    _run_fx(["tests_gen", "--force"], top=top, run_id=run_id)
    _run_fx(["tests"], top=top, run_id=run_id)
    _run_fx(["setup_tb", "--force"], top=top, run_id=run_id)
    _run_fx(["setup_cocotb", "--force"], top=top, run_id=run_id)
    _run_fx(["sim_tests"], top=top, run_id=run_id)
    _run_fx(["cocotb_tests"], top=top, run_id=run_id)


def _run_signoff(top: str, *, run_id: str = DEFAULT_RUN_ID, multi_clock: bool = False) -> None:
    """Run synthesis/signoff targets."""

    if multi_clock:
        _run_fx(["sdc_multi", "--force"], top=top, run_id=run_id)

    _run_fx(["syn", "sdf", "sta", "power", "--force"], top=top, run_id=run_id)


# -----------------------------------------------------------------------------
# Complete flows
# -----------------------------------------------------------------------------


def _run_single_clock_flow(*, run_signoff: bool) -> None:
    """Run the generated single-clock example flow."""

    top = os.environ.get("FLEXSOC_SINGLE_TOP", "test")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"single-clock generated flow: TOP={top} RUN_ID={run_id}")

    _settings(top, clock_mode="single", run_id=run_id, host=host)
    _run_generated_rtl_flow(top, run_id=run_id)
    _run_lint_suite(top, run_id=run_id)
    _run_generated_model_and_tests(top, run_id=run_id)

    if run_signoff:
        _run_signoff(top, run_id=run_id, multi_clock=False)
    else:
        print("\n>>> skip signoff because --no-signoff was passed", flush=True)


def _run_multi_clock_flow(*, run_signoff: bool) -> None:
    """Run the generated multi-clock example flow."""

    top = os.environ.get("FLEXSOC_MULTI_TOP", "tri_stream_dsp")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"multi-clock generated flow: TOP={top} RUN_ID={run_id}")

    _settings(top, clock_mode="multi", run_id=run_id, host=host)
    _run_generated_rtl_flow(top, run_id=run_id)
    _run_lint_suite(top, run_id=run_id)
    _run_generated_model_and_tests(top, run_id=run_id)

    if run_signoff:
        _run_signoff(top, run_id=run_id, multi_clock=True)
    else:
        print("\n>>> skip signoff because --no-signoff was passed", flush=True)


def _run_cordic_ip_load_flow(*, run_signoff: bool) -> None:
    """Run the CORDIC ip_load-backed flow."""

    top = os.environ.get("FLEXSOC_CORDIC_TOP", "cordic")
    run_id = os.environ.get("FLEXSOC_CORDIC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"CORDIC ip_load flow: TOP={top} RUN_ID={run_id}")

    _settings(top, clock_mode="single", run_id=run_id, host=host)
    _run_loaded_ip_tests(top, run_id=run_id)

    if run_signoff:
        _run_signoff(top, run_id=run_id, multi_clock=False)
    else:
        print("\n>>> skip signoff because --no-signoff was passed", flush=True)


# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------


@pytest.mark.e2e
def test_fx_full_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run the generated single-clock and multi-clock FlexSoC flows."""

    run_signoff = _run_signoff_enabled(request)

    _print_section("FlexSoC generated full-flow regression")
    print(f"repo: {REPO_ROOT}", flush=True)
    print(f"live output: {_live()}", flush=True)
    print(f"signoff: {run_signoff}", flush=True)

    _run_single_clock_flow(run_signoff=run_signoff)
    _run_multi_clock_flow(run_signoff=run_signoff)

    _print_section("FlexSoC generated full-flow regression passed")


@pytest.mark.e2e
def test_fx_cordic_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Run CORDIC through ip_load without regenerating editable IP sources."""

    run_signoff = _run_signoff_enabled(request)

    _print_section("FlexSoC CORDIC ip_load regression")
    print(f"repo: {REPO_ROOT}", flush=True)
    print(f"live output: {_live()}", flush=True)
    print(f"signoff: {run_signoff}", flush=True)

    _run_cordic_ip_load_flow(run_signoff=run_signoff)

    _print_section("FlexSoC CORDIC ip_load regression passed")
