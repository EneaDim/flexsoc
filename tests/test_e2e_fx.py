from __future__ import annotations

from contextlib import contextmanager
from pathlib import Path
import json
import os
import shutil
import subprocess
import tempfile
from typing import Iterable, Iterator

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


def _e2e_root(request: pytest.FixtureRequest) -> Path:
    """Return the base directory used for isolated E2E workspaces."""

    configured = request.config.getoption("--e2e-root") or os.environ.get("FLEXSOC_E2E_ROOT") or "/tmp"
    root = Path(configured).expanduser().resolve()
    root.mkdir(parents=True, exist_ok=True)
    return root


def _print_section(title: str) -> None:
    """Print a large readable section header for pytest -s runs."""

    print("\n" + "=" * 72, flush=True)
    print(title, flush=True)
    print("=" * 72, flush=True)


def _print_step(args: Iterable[str]) -> None:
    """Print one fx command before executing it."""

    print("\n>>> fx " + " ".join(args), flush=True)


def _recent_logs(
    top: str,
    run_id: str,
    limit: int = 8,
    *,
    workspace: Path,
) -> list[Path]:
    """Return the most recently modified log files for one run."""

    log_root = workspace / "runs" / top / run_id / "logs"
    if not log_root.exists():
        return []

    logs = [path for path in log_root.rglob("*") if path.is_file()]
    return sorted(logs, key=lambda path: path.stat().st_mtime)[-limit:]


def _dump_recent_logs(
    top: str,
    run_id: str,
    *,
    workspace: Path,
) -> None:
    """Print recent log paths and the tail of the latest log after a failure."""

    logs = _recent_logs(top, run_id, workspace=workspace)

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


def _run_fx(
    args: list[str],
    *,
    top: str | None = None,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
) -> None:
    """Run one fx command and dump useful logs if it fails."""

    full_args = list(args)

    full_args.extend(["--workdir", str(workspace)])

    if _live() and full_args and full_args[0] != "settings" and "--live" not in full_args:
        full_args.append("--live")

    _print_step(full_args)

    completed = subprocess.run(["fx", *full_args], cwd=REPO_ROOT, check=False)
    if completed.returncode == 0:
        return

    if top is not None:
        _dump_recent_logs(top, run_id, workspace=workspace)

    pytest.fail(f"fx {' '.join(full_args)} failed with exit code {completed.returncode}")


def _settings(
    top: str,
    *,
    clock_mode: str,
    run_id: str = DEFAULT_RUN_ID,
    host: str = DEFAULT_HOST,
    workspace: Path,
) -> None:
    """Select one run configuration before launching flow targets."""

    _run_fx(
        [
            "settings",
            f"TOP={top}",
            f"RUN_TOP={top}",
            f"RUN_ID={run_id}",
            f"HOST={host}",
            f"CLOCK_MODE={clock_mode}",
        ],
        workspace=workspace,
    )


@contextmanager
def _temporary_workspace(prefix: str, *, root: Path) -> Iterator[Path]:
    """Create one isolated workspace and retain it only after failures."""

    workspace = Path(tempfile.mkdtemp(prefix=prefix, dir=root))
    try:
        yield workspace
    except BaseException:
        print(f"[debug] retained failed workspace: {workspace}", flush=True)
        raise
    else:
        shutil.rmtree(workspace, ignore_errors=True)


# -----------------------------------------------------------------------------
# Shared flow sections
# -----------------------------------------------------------------------------


def _run_generated_rtl_flow(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
) -> None:
    """Generate the normal editable RTL/model flow for generated examples."""

    _run_fx(["setup", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["hjson", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["reg", "doc", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["rtl_stub", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["top_from_core", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["flist", "--force"], top=top, run_id=run_id, workspace=workspace)


def _run_lint_suite(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
) -> None:
    """Run the complete lint suite with both supported frontends."""

    _run_fx(["lint_suite", "--set", "LINT_TOOL=verilator"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["lint_suite", "--set", "LINT_TOOL=slang"], top=top, run_id=run_id, workspace=workspace)


def _run_slang_ast(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
) -> None:
    """Generate and validate the Slang AST for the active run hierarchy."""

    rtl_dir = workspace / "runs" / top / run_id / "rtl"
    search_roots = (
        REPO_ROOT / "hw" / "ips" / "pkgs",
        REPO_ROOT / "hw" / "ips" / "prim",
        REPO_ROOT / "hw" / "ips" / "prim_opentitan",
        REPO_ROOT / "hw" / "ips" / "tlul",
    )
    search_args = " ".join(f"--search-root {path}" for path in search_roots)

    _run_fx(
        [
            "slang_ast",
            "--set",
            f"SLANG_ROOT={rtl_dir}",
            "--set",
            f"SLANG_TOP_FILE={rtl_dir / f'{top}.sv'}",
            "--set",
            f"SLANG_SEARCH_ARGS={search_args}",
        ],
        top=top,
        run_id=run_id,
        workspace=workspace,
    )

    ast = workspace / "runs" / top / run_id / "analysis" / "slang" / f"{top}_ast.json"
    assert ast.is_file() and ast.stat().st_size > 0, f"missing or empty Slang AST: {ast}"



def _run_metrics(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    expect_signoff: bool,
    workspace: Path,
) -> None:
    """Collect and validate the run-level metrics summary."""

    _run_fx(["metrics"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["manifest"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["check"], top=top, run_id=run_id, workspace=workspace)

    path = workspace / "runs" / top / run_id / "meta" / "metrics.json"
    data = json.loads(path.read_text(encoding="utf-8"))

    assert data["schema_version"] == 2
    assert data["top"] == top
    assert "lint" in data

    manifest_path = workspace / "runs" / top / run_id / "meta" / "manifest.json"
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    assert manifest["schema_version"] == 1
    assert manifest["run"] == {"top": top, "run_top": top, "run_id": run_id}
    assert "python" in manifest["environment"]
    assert "flexsoc" in manifest["environment"]
    assert isinstance(manifest["tools"], dict)
    if expect_signoff:
        assert "synthesis" in data
        assert "sta" in data
        assert "power_estimate" in data
        assert data["power_estimate"]["analysis"] == "estimate"

def _run_generated_model_and_tests(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
) -> None:
    """Generate model, tests, SV/cocotb testbenches, and run verification."""

    _run_fx(["setup_model", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["tests_gen"], top=top, run_id=run_id, workspace=workspace)
    test_root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    for test in ("smoke", "corners", "random_seed_1", "random_seed_2", "reconfig"):
        assert (test_root / test).is_dir()
    _run_fx(["tests"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["setup_tb", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["setup_cocotb", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["sim_tests"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["cocotb_tests"], top=top, run_id=run_id, workspace=workspace)


def _run_loaded_ip_tests(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
) -> None:
    """Run an existing IP through the flow without regenerating IP RTL/model.

    The loaded HJSON, RTL top/core, and behavioral model are source artifacts.
    Register RTL/documentation may be regenerated from HJSON, but the existing
    top wrapper and model are preserved intentionally.
    """

    _run_fx(["setup", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["ip_load", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["reg", "doc", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["flist", "--force"], top=top, run_id=run_id, workspace=workspace)

    _run_lint_suite(top, run_id=run_id, workspace=workspace)
    _run_slang_ast(top, run_id=run_id, workspace=workspace)

    _run_fx(["regmap_py", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["tests_gen", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["tests"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["setup_tb", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["setup_cocotb", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["sim_tests"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["cocotb_tests"], top=top, run_id=run_id, workspace=workspace)


def _run_regression_smoke(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
) -> None:
    """Exercise the full generated SV regression and native Verilator coverage."""

    _run_fx(
        [
            "regression",
            "--set",
            "REGRESSION_BACKENDS=sv",
        ],
        top=top,
        run_id=run_id,
        workspace=workspace,
    )
    coverage = workspace / "runs" / top / run_id / "dv" / "functional" / "coverage"
    assert (coverage / "merged.dat").is_file()
    summary = coverage / "summary.txt"
    assert summary.is_file()
    assert "Coverage summary" in summary.read_text(encoding="utf-8")
    _run_fx(["coverage_detail"], top=top, run_id=run_id, workspace=workspace)
    assert (coverage / "annotated").is_dir()
    detail_log = (
        workspace
        / "runs"
        / top
        / run_id
        / "logs"
        / "dv"
        / "functional"
        / "coverage"
        / f"{top}_coverage_detail.log"
    )
    assert detail_log.is_file()


def _run_signoff(
    top: str,
    *,
    run_id: str = DEFAULT_RUN_ID,
    multi_clock: bool = False,
    workspace: Path,
) -> None:
    """Run synthesis/signoff targets."""

    if multi_clock:
        _run_fx(["sdc_multi", "--force"], top=top, run_id=run_id, workspace=workspace)

    _run_fx(
        ["syn", "sdf", "sta", "power_estimate", "--force"],
        top=top,
        run_id=run_id,
        workspace=workspace,
    )


# -----------------------------------------------------------------------------
# Complete flows
# -----------------------------------------------------------------------------


def _run_single_clock_flow(*, run_signoff: bool, workspace: Path) -> None:
    """Run the generated single-clock example flow."""

    top = os.environ.get("FLEXSOC_SINGLE_TOP", "test")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"single-clock generated flow: TOP={top} RUN_ID={run_id}")

    _settings(top, clock_mode="single", run_id=run_id, host=host, workspace=workspace)
    _run_generated_rtl_flow(top, run_id=run_id, workspace=workspace)
    _run_lint_suite(top, run_id=run_id, workspace=workspace)
    _run_slang_ast(top, run_id=run_id, workspace=workspace)
    _run_generated_model_and_tests(top, run_id=run_id, workspace=workspace)
    _run_regression_smoke(top, run_id=run_id, workspace=workspace)

    if run_signoff:
        _run_signoff(top, run_id=run_id, multi_clock=False, workspace=workspace)
    else:
        print("\n>>> skip signoff because --no-signoff was passed", flush=True)

    _run_metrics(top, run_id=run_id, expect_signoff=run_signoff, workspace=workspace)


def _run_multi_clock_flow(*, run_signoff: bool, workspace: Path) -> None:
    """Run the generated multi-clock example flow."""

    top = os.environ.get("FLEXSOC_MULTI_TOP", "tri_stream_dsp")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"multi-clock generated flow: TOP={top} RUN_ID={run_id}")

    _settings(top, clock_mode="multi", run_id=run_id, host=host, workspace=workspace)
    _run_generated_rtl_flow(top, run_id=run_id, workspace=workspace)
    _run_lint_suite(top, run_id=run_id, workspace=workspace)
    _run_slang_ast(top, run_id=run_id, workspace=workspace)
    _run_generated_model_and_tests(top, run_id=run_id, workspace=workspace)

    if run_signoff:
        _run_signoff(top, run_id=run_id, multi_clock=True, workspace=workspace)
    else:
        print("\n>>> skip signoff because --no-signoff was passed", flush=True)

    _run_metrics(top, run_id=run_id, expect_signoff=run_signoff, workspace=workspace)


def _run_cordic_ip_load_flow(*, run_signoff: bool, workspace: Path) -> None:
    """Run the CORDIC ip_load-backed flow."""

    top = os.environ.get("FLEXSOC_CORDIC_TOP", "cordic")
    run_id = os.environ.get("FLEXSOC_CORDIC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"CORDIC ip_load flow: TOP={top} RUN_ID={run_id}")

    _settings(top, clock_mode="single", run_id=run_id, host=host, workspace=workspace)
    _run_loaded_ip_tests(top, run_id=run_id, workspace=workspace)

    if run_signoff:
        _run_signoff(top, run_id=run_id, multi_clock=False, workspace=workspace)
    else:
        print("\n>>> skip signoff because --no-signoff was passed", flush=True)

    _run_metrics(top, run_id=run_id, expect_signoff=run_signoff, workspace=workspace)


def _run_uart_ip_load_flow(*, run_signoff: bool, workspace: Path) -> None:
    """Run the UART existing-IP flow entirely in a temporary workspace."""

    top = os.environ.get("FLEXSOC_UART_TOP", "uart")
    run_id = os.environ.get("FLEXSOC_UART_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"UART ip_load flow: TOP={top} RUN_ID={run_id}")
    print(f"workspace: {workspace}", flush=True)

    _settings(
        top,
        clock_mode="single",
        run_id=run_id,
        host=host,
        workspace=workspace,
    )
    _run_loaded_ip_tests(top, run_id=run_id, workspace=workspace)

    if run_signoff:
        _run_signoff(top, run_id=run_id, multi_clock=False, workspace=workspace)
    else:
        print("\n>>> skip signoff because --no-signoff was passed", flush=True)

    _run_metrics(top, run_id=run_id, expect_signoff=run_signoff, workspace=workspace)


# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------


@pytest.mark.e2e
def test_fx_full_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run generated single- and multi-clock flows in an isolated workspace."""

    run_signoff = _run_signoff_enabled(request)

    with _temporary_workspace("flexsoc-full-e2e-", root=_e2e_root(request)) as workspace:
        _print_section("FlexSoC generated full-flow regression")
        print(f"repo: {REPO_ROOT}", flush=True)
        print(f"workspace: {workspace}", flush=True)
        print(f"live output: {_live()}", flush=True)
        print(f"signoff: {run_signoff}", flush=True)

        _run_single_clock_flow(run_signoff=run_signoff, workspace=workspace)
        _run_multi_clock_flow(run_signoff=run_signoff, workspace=workspace)

        _print_section("FlexSoC generated full-flow regression passed")


@pytest.mark.e2e
def test_fx_cordic_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Run CORDIC as an existing IP in an isolated workspace."""

    run_signoff = _run_signoff_enabled(request)

    with _temporary_workspace("flexsoc-cordic-e2e-", root=_e2e_root(request)) as workspace:
        _print_section("FlexSoC CORDIC ip_load regression")
        print(f"repo: {REPO_ROOT}", flush=True)
        print(f"workspace: {workspace}", flush=True)
        print(f"live output: {_live()}", flush=True)
        print(f"signoff: {run_signoff}", flush=True)

        _run_cordic_ip_load_flow(run_signoff=run_signoff, workspace=workspace)

        _print_section("FlexSoC CORDIC ip_load regression passed")


@pytest.mark.e2e
def test_fx_uart_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Run UART as an existing IP in an isolated workspace."""

    run_signoff = _run_signoff_enabled(request)

    with _temporary_workspace("flexsoc-uart-e2e-", root=_e2e_root(request)) as workspace:
        _print_section("FlexSoC UART ip_load regression")
        print(f"repo: {REPO_ROOT}", flush=True)
        print(f"workspace: {workspace}", flush=True)
        print(f"live output: {_live()}", flush=True)
        print(f"signoff: {run_signoff}", flush=True)

        _run_uart_ip_load_flow(run_signoff=run_signoff, workspace=workspace)

        _print_section("FlexSoC UART ip_load regression passed")
