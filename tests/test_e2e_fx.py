from __future__ import annotations

from contextlib import contextmanager
from pathlib import Path
import hashlib
import json
import os
import shutil
import subprocess
import tempfile
from typing import Iterable, Iterator

import pytest
from rich.console import Console


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_RUN_ID = "dev"
DEFAULT_HOST = "uart"
RTL_SOURCE_SUFFIXES = {".sv", ".svh", ".v", ".vh"}
CONSOLE = Console()


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
    """Print one consistent section header for pytest -s runs."""

    CONSOLE.print()
    CONSOLE.rule(f"[bold cyan]{title}[/bold cyan]")


def _print_context(*, workspace: Path, signoff: bool) -> None:
    """Print the common E2E run context consistently."""

    CONSOLE.print(f"[bold]repo:[/bold] {REPO_ROOT}")
    CONSOLE.print(f"[bold]workspace:[/bold] {workspace}")
    CONSOLE.print(f"[bold]live output:[/bold] {_live()}")
    CONSOLE.print(f"[bold]signoff:[/bold] {signoff}")


def _print_step(args: Iterable[str]) -> None:
    """Print one fx command before executing it."""

    CONSOLE.print()
    CONSOLE.print(f"[bold bright_cyan]>>>[/bold bright_cyan] [bold]fx {' '.join(args)}[/bold]")


def _recent_logs(top: str, run_id: str, limit: int = 8, *, workspace: Path) -> list[Path]:
    """Return the most recently modified log files for one run."""

    log_root = workspace / "runs" / top / run_id / "logs"
    if not log_root.exists():
        return []
    logs = [path for path in log_root.rglob("*") if path.is_file()]
    return sorted(logs, key=lambda path: path.stat().st_mtime)[-limit:]


def _dump_recent_logs(top: str, run_id: str, *, workspace: Path) -> None:
    """Print recent log paths and the tail of the latest log after a failure."""

    logs = _recent_logs(top, run_id, workspace=workspace)
    CONSOLE.print(f"\n[bold yellow][debug] recent logs for TOP={top} RUN_ID={run_id}[/bold yellow]")
    if not logs:
        CONSOLE.print("[dim][debug] no logs found[/dim]")
        return
    for log in logs:
        CONSOLE.print(f"  {log}")

    latest = logs[-1]
    CONSOLE.print(f"\n[bold yellow][debug] tail -120 {latest}[/bold yellow]")
    try:
        lines = latest.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError as exc:
        CONSOLE.print(f"[red][debug] could not read {latest}: {exc}[/red]")
        return
    for line in lines[-120:]:
        print(line, flush=True)


def _run_fx(
    args: list[str],
    *,
    top: str | None = None,
    run_id: str = DEFAULT_RUN_ID,
    workspace: Path,
    required: bool = True,
) -> bool:
    """Run one fx target; reporting targets may be explicitly non-blocking."""

    full_args = [*args, "--workdir", str(workspace)]
    if _live() and full_args and full_args[0] != "settings" and "--live" not in full_args:
        full_args.append("--live")

    _print_step(full_args)
    completed = subprocess.run(["fx", *full_args], cwd=REPO_ROOT, check=False)
    if completed.returncode == 0:
        return True

    if top is not None:
        _dump_recent_logs(top, run_id, workspace=workspace)
    message = f"fx {' '.join(full_args)} failed with exit code {completed.returncode}"
    if required:
        pytest.fail(message)
    CONSOLE.print(f"[bold yellow][report] non-blocking: {message}[/bold yellow]")
    return False


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


def _run_preflight(*, workspace: Path) -> None:
    """Validate the CLI/toolchain and show the active technology before the flow."""

    _print_section("Preflight — environment")
    _run_fx(["doctor"], workspace=workspace)
    _print_section("Preflight — PDK")
    _run_fx(["pdk", "info", os.environ.get("FLEXSOC_PDK", "sky130")], workspace=workspace)



@contextmanager
def _temporary_workspace(prefix: str, *, root: Path) -> Iterator[Path]:
    """Create one isolated workspace and retain it only after failures."""

    workspace = Path(tempfile.mkdtemp(prefix=prefix, dir=root))
    try:
        yield workspace
    except BaseException:
        CONSOLE.print(f"[bold yellow][debug] retained failed workspace:[/bold yellow] {workspace}")
        raise
    else:
        shutil.rmtree(workspace, ignore_errors=True)


def _sha256(path: Path) -> str:
    """Hash one source artifact used by an ip_load regression."""

    return hashlib.sha256(path.read_bytes()).hexdigest()


# -----------------------------------------------------------------------------
# Saved-IP integrity
# -----------------------------------------------------------------------------


def _ip_protected_sources(top: str) -> tuple[Path, ...]:
    """Return HJSON, RTL source, and model artifacts that must stay immutable."""

    root = REPO_ROOT / "hw" / "ips" / top
    protected = [*sorted((root / "data").rglob("*.hjson"))]
    protected.extend(
        sorted(
            path
            for path in (root / "rtl").rglob("*")
            if path.is_file() and path.suffix.lower() in RTL_SOURCE_SUFFIXES
        )
    )
    model = root / "dv" / "functional" / "model"
    protected.extend(
        sorted(
            path
            for path in model.rglob("*")
            if path.is_file()
            and "__pycache__" not in path.parts
            and path.suffix not in {".pyc", ".pyo"}
        )
    )
    if not protected:
        raise AssertionError(f"invalid {top} source layout: no protected HJSON/RTL/model files")
    return tuple(protected)


def _validate_ip_layout(top: str) -> None:
    """Check that a saved IP follows the current load/verification layout."""

    root = REPO_ROOT / "hw" / "ips" / top
    required = (
        root / "rtl" / "rtl_common.f",
        root / "rtl" / "rtl_ip.f",
        root / "drivers",
        root / "syn",
        root / "signoff",
        root / "pnr_openroad",
        root / "dv" / "functional" / "model" / f"{top}_model.py",
        root / "dv" / "functional" / "model" / f"{top}_regmap.py",
        root / "dv" / "functional" / "model" / f"{top}_tests.py",
        root / "dv" / "formal" / "properties" / "prove" / f"{top}_prove.sv",
        root / "dv" / "formal" / "properties" / "cover" / f"{top}_cover.sv",
    )
    missing = [path for path in required if not path.exists()]
    assert not missing, f"invalid {top} IP structure; missing: {missing}"


@contextmanager
def _protect_ip_sources(top: str) -> Iterator[dict[Path, str]]:
    """Fail if an ip_load E2E run changes saved HJSON, RTL source, or model files."""

    _validate_ip_layout(top)
    snapshot = {path: _sha256(path) for path in _ip_protected_sources(top)}
    yield snapshot
    changed = [path for path, digest in snapshot.items() if _sha256(path) != digest]
    assert not changed, f"{top} source artifacts changed during ip_load E2E: {changed}"


def _assert_loaded_sources_match(
    top: str, run_id: str, workspace: Path, snapshot: dict[Path, str]
) -> None:
    """Verify loaded HJSON, RTL source, and model files remain byte-identical."""

    source_root = REPO_ROOT / "hw" / "ips" / top
    run_root = workspace / "runs" / top / run_id
    changed = []
    for source, digest in snapshot.items():
        loaded = run_root / source.relative_to(source_root)
        if not loaded.is_file() or _sha256(loaded) != digest:
            changed.append(loaded)
    assert not changed, f"{top} loaded HJSON/RTL/model changed during flow: {changed}"


# -----------------------------------------------------------------------------
# Flow preparation
# -----------------------------------------------------------------------------


def _run_generated_rtl_flow(top: str, *, run_id: str, workspace: Path) -> None:
    """Generate the normal editable RTL/model flow for generated examples."""

    _run_fx(["setup", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["hjson", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["reg", "doc", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["rtl_stub", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["top_from_core", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["flist", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["setup_model", "--force"], top=top, run_id=run_id, workspace=workspace)


def _run_multiclock_rtl_flow(top: str, *, run_id: str, workspace: Path) -> None:
    """Generate the complete decomposed multi-clock scaffold and filelists."""

    _run_fx(["multiclock_scaffold", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["flist", "--force"], top=top, run_id=run_id, workspace=workspace)


def _run_loaded_ip_setup(
    top: str,
    *,
    run_id: str,
    workspace: Path,
    snapshot: dict[Path, str],
) -> None:
    """Load one saved IP without regenerating its HJSON, RTL source, or model."""

    _run_fx(["setup", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["ip_load", "--force"], top=top, run_id=run_id, workspace=workspace)
    _assert_loaded_sources_match(top, run_id, workspace, snapshot)
    # setup_model may add machine-owned helpers, but existing editable model files stay intact.
    _run_fx(["setup_model"], top=top, run_id=run_id, workspace=workspace)
    _assert_loaded_sources_match(top, run_id, workspace, snapshot)


# -----------------------------------------------------------------------------
# Individual verification / signoff stages
# -----------------------------------------------------------------------------


def _run_lint_stages(top: str, *, run_id: str, workspace: Path) -> None:
    """Run Slang first and Verilator second as separately visible targets."""

    _print_section("Lint — Slang")
    _run_fx(["lint_slang_suite"], top=top, run_id=run_id, workspace=workspace)
    _print_section("Lint — Verilator")
    _run_fx(["lint_verilator_suite"], top=top, run_id=run_id, workspace=workspace)


def _run_slang_ast(top: str, *, run_id: str, workspace: Path) -> None:
    """Generate and validate the Slang AST for the active run hierarchy."""

    _print_section("Slang AST")
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


def _run_regression(top: str, *, run_id: str, workspace: Path) -> None:
    """Run combined SV+cocotb regression and expose functional coverage."""

    _print_section("Functional regression")
    _run_fx(["regression"], top=top, run_id=run_id, workspace=workspace)
    coverage = workspace / "runs" / top / run_id / "dv" / "functional" / "coverage"
    assert (coverage / "merged.dat").is_file()
    summary = coverage / "summary.txt"
    summary_json = coverage / "summary.json"
    assert summary.is_file()
    assert summary_json.is_file()

    # Validate the machine-readable contract rather than a presentation heading.
    # This keeps the E2E flow from breaking when coverage text rendering changes.
    coverage_data = json.loads(summary_json.read_text(encoding="utf-8"))
    assert coverage_data.get("schema_version") == 2
    assert coverage_data.get("display_columns") == [
        "line", "toggle", "expr", "branch", "fsm", "user", "total"
    ]
    scopes = coverage_data.get("scopes")
    assert isinstance(scopes, dict)
    assert all(scope in scopes for scope in ("design", "registers", "common", "other", "all"))

    _print_section("Functional coverage detail")
    _run_fx(["coverage_detail"], top=top, run_id=run_id, workspace=workspace)
    assert (coverage / "annotated").is_dir()


def _author_generated_design_properties(
    top: str, *, run_id: str, clock_mode: str, workspace: Path
) -> None:
    """Write E2E-owned design properties, mirroring a real user-authored formal layer."""

    root = workspace / "runs" / top / run_id / "dv" / "formal" / "properties"
    prove = root / "prove" / f"{top}_prove.sv"
    cover = root / "cover" / f"{top}_cover.sv"
    prove.parent.mkdir(parents=True, exist_ok=True)
    cover.parent.mkdir(parents=True, exist_ok=True)

    if clock_mode == "multi":
        prove.write_text(
            f"""// E2E-authored multi-clock design assertions for {top}_core.
module {top}_e2e_prove (
  input logic dsp_clk_i, dsp_rst_ni,
  input logic enable_rx, fifo_wready, rx_ready_o,
  input logic enable_dsp, fifo_rvalid, dsp_valid_o, dsp_ready_i, fifo_rready,
  input logic clk_gate_en_dsp, dsp_clk_active, soft_reset_dsp,
  input logic signed [31:0] dsp_result_o,
  input logic dsp_above_threshold_o, dsp_overflow_o
);
  logic past_valid = 1'b0;

  always_comb begin
    assert (rx_ready_o == (enable_rx & fifo_wready));
    assert (fifo_rready == (enable_dsp & fifo_rvalid & (!dsp_valid_o | dsp_ready_i)));
    assert (dsp_clk_active == (enable_dsp & (!clk_gate_en_dsp | fifo_rvalid | dsp_valid_o)));
  end

  always_ff @(posedge dsp_clk_i) begin
    if (past_valid && (!$past(dsp_rst_ni) || $past(soft_reset_dsp))) begin
      assert (!dsp_valid_o);
      assert (dsp_result_o == '0);
      assert (!dsp_above_threshold_o);
      assert (!dsp_overflow_o);
    end
    past_valid <= 1'b1;
  end
endmodule

bind {top}_core {top}_e2e_prove {top}_e2e_prove_i (
  .dsp_clk_i(dsp_clk_i), .dsp_rst_ni(dsp_rst_ni),
  .enable_rx(enable_rx), .fifo_wready(fifo_wready), .rx_ready_o(rx_ready_o),
  .enable_dsp(enable_dsp), .fifo_rvalid(fifo_rvalid), .dsp_valid_o(dsp_valid_o),
  .dsp_ready_i(dsp_ready_i), .fifo_rready(fifo_rready),
  .clk_gate_en_dsp(clk_gate_en_dsp), .dsp_clk_active(dsp_clk_active),
  .soft_reset_dsp(soft_reset_dsp), .dsp_result_o(dsp_result_o),
  .dsp_above_threshold_o(dsp_above_threshold_o), .dsp_overflow_o(dsp_overflow_o)
);
""",
            encoding="utf-8",
        )
        cover.write_text(
            f"""// E2E-authored multi-clock design covers for {top}_core.
module {top}_e2e_cover (
  input logic cfg_clk_i, cfg_rst_ni, cfg_enable,
  input logic rx_clk_i, rx_rst_ni, rx_valid_i, rx_ready_o,
  input logic dsp_clk_i, dsp_rst_ni, fifo_rvalid, dsp_valid_o, dsp_ready_i
);
  always_ff @(posedge cfg_clk_i) if (cfg_rst_ni) cover (cfg_enable);
  always_ff @(posedge rx_clk_i) if (rx_rst_ni) cover (rx_valid_i && rx_ready_o);
  always_ff @(posedge dsp_clk_i) if (dsp_rst_ni) begin
    cover (fifo_rvalid);
    cover (dsp_valid_o);
    cover (dsp_valid_o && dsp_ready_i);
  end
endmodule

bind {top}_core {top}_e2e_cover {top}_e2e_cover_i (
  .cfg_clk_i(cfg_clk_i), .cfg_rst_ni(cfg_rst_ni), .cfg_enable(cfg_enable),
  .rx_clk_i(rx_clk_i), .rx_rst_ni(rx_rst_ni), .rx_valid_i(rx_valid_i), .rx_ready_o(rx_ready_o),
  .dsp_clk_i(dsp_clk_i), .dsp_rst_ni(dsp_rst_ni), .fifo_rvalid(fifo_rvalid),
  .dsp_valid_o(dsp_valid_o), .dsp_ready_i(dsp_ready_i)
);
""",
            encoding="utf-8",
        )
        return

    prove.write_text(
        f"""// E2E-authored single-clock design assertions for {top}_core.
module {top}_e2e_prove (
  input logic clk_i, rst_ni,
  input logic [31:0] data_o, pipe_q1,
  input logic valid_o, valid_q1
);
  logic past_valid = 1'b0;

  always_comb begin
    assert (data_o == pipe_q1);
    assert (valid_o == valid_q1);
  end

  always_ff @(posedge clk_i) begin
    if (past_valid && !$past(rst_ni)) begin
      assert (data_o == '0);
      assert (!valid_o);
    end
    past_valid <= 1'b1;
  end
endmodule

bind {top}_core {top}_e2e_prove {top}_e2e_prove_i (
  .clk_i(clk_i), .rst_ni(rst_ni), .data_o(data_o), .pipe_q1(pipe_q1),
  .valid_o(valid_o), .valid_q1(valid_q1)
);
""",
        encoding="utf-8",
    )
    cover.write_text(
        f"""// E2E-authored single-clock design covers for {top}_core.
module {top}_e2e_cover (
  input logic clk_i, rst_ni, valid_i, valid_o,
  input logic [31:0] data_o
);
  logic past_valid = 1'b0;

  always_ff @(posedge clk_i) begin
    if (rst_ni) begin
      cover (valid_i);
      cover (valid_o);
      cover (valid_o && |data_o);
      if (past_valid) cover (valid_i && !$past(valid_i));
    end
    past_valid <= 1'b1;
  end
endmodule

bind {top}_core {top}_e2e_cover {top}_e2e_cover_i (
  .clk_i(clk_i), .rst_ni(rst_ni), .valid_i(valid_i),
  .valid_o(valid_o), .data_o(data_o)
);
""",
        encoding="utf-8",
    )


def _run_formal_stages(top: str, *, run_id: str, workspace: Path) -> None:
    """Run every formal target explicitly in BMC → PROVE → COVER order."""

    stages = (
        ("Formal BMC — CSR", "formal_csr_bmc"),
        ("Formal BMC — design properties", "formal_bmc"),
        ("Formal PROVE — CSR", "formal_csr_prove"),
        ("Formal PROVE — design properties", "formal_prove"),
        ("Formal COVER — CSR", "formal_csr_cover"),
        ("Formal COVER — design properties", "formal_cover"),
    )
    for title, target in stages:
        _print_section(title)
        _run_fx([target, "--force"], top=top, run_id=run_id, workspace=workspace)


def _run_signoff_stages(
    top: str,
    *,
    run_id: str,
    clock_mode: str,
    workspace: Path,
) -> bool:
    """Run synthesis/equivalence/signoff as individually visible targets."""

    if clock_mode == "multi":
        _print_section("Multi-clock constraints")
        _run_fx(["sdc_multi", "--force"], top=top, run_id=run_id, workspace=workspace)

    _print_section(f"Formal setup — {clock_mode} clock")
    _run_fx(["setup_formal", "--force"], top=top, run_id=run_id, workspace=workspace)
    _run_formal_stages(top, run_id=run_id, workspace=workspace)
    equivalence_ok = True
    for title, target in (
        ("Synthesis", "syn"),
        ("RTL ↔ synthesis equivalence", "eqy"),
        ("SDF", "sdf"),
        ("STA", "sta"),
        ("Power estimate", "power_estimate"),
    ):
        _print_section(title)
        ok = _run_fx(
            [target, "--force"], top=top, run_id=run_id, workspace=workspace,
            required=target != "eqy",
        )
        if target == "eqy":
            equivalence_ok = ok
    return equivalence_ok


def _run_reports(top: str, *, run_id: str, workspace: Path) -> None:
    """Render end-of-run reports without turning metrics/check into flow gates."""

    _print_section("Run manifest")
    _run_fx(["manifest"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["manifest_show"], top=top, run_id=run_id, workspace=workspace)

    _print_section("Metrics and verification summary — informational")
    _run_fx(["metrics"], top=top, run_id=run_id, workspace=workspace)
    _run_fx(["check"], top=top, run_id=run_id, workspace=workspace)


def _run_visible_flow(
    top: str,
    *,
    run_id: str,
    clock_mode: str,
    run_signoff: bool,
    workspace: Path,
) -> None:
    """Run every public stage individually so the E2E log mirrors the pipeline."""

    _run_lint_stages(top, run_id=run_id, workspace=workspace)
    _run_slang_ast(top, run_id=run_id, workspace=workspace)
    _run_regression(top, run_id=run_id, workspace=workspace)
    equivalence_ok = True
    if run_signoff:
        equivalence_ok = _run_signoff_stages(top, run_id=run_id, clock_mode=clock_mode, workspace=workspace)
    _run_reports(top, run_id=run_id, workspace=workspace)
    if not equivalence_ok:
        pytest.fail("EQY equivalence did not close; all independent sign-off stages and reports were still completed")


# -----------------------------------------------------------------------------
# Complete flows
# -----------------------------------------------------------------------------


def _run_single_clock_flow(*, run_signoff: bool, workspace: Path) -> None:
    """Run the generated single-clock example target-by-target."""

    top = os.environ.get("FLEXSOC_SINGLE_TOP", "test")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"Single-clock generated flow — TOP={top} RUN_ID={run_id}")
    _settings(top, clock_mode="single", run_id=run_id, host=host, workspace=workspace)
    _run_preflight(workspace=workspace)
    _print_section("Generate RTL / model")
    _run_generated_rtl_flow(top, run_id=run_id, workspace=workspace)
    _author_generated_design_properties(
        top, run_id=run_id, clock_mode="single", workspace=workspace
    )
    _run_visible_flow(
        top,
        run_id=run_id,
        clock_mode="single",
        run_signoff=run_signoff,
        workspace=workspace,
    )

    test_root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    for test in ("smoke", "corners", "random_seed_1", "random_seed_2", "reconfig"):
        assert (test_root / test).is_dir()


def _run_multi_clock_flow(*, run_signoff: bool, workspace: Path) -> None:
    """Run the generated multi-clock example target-by-target."""

    top = os.environ.get("FLEXSOC_MULTI_TOP", "tri_stream_dsp")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"Multi-clock generated flow — TOP={top} RUN_ID={run_id}")
    _settings(top, clock_mode="multi", run_id=run_id, host=host, workspace=workspace)
    _run_preflight(workspace=workspace)
    _print_section("Generate multi-clock RTL / model")
    _run_multiclock_rtl_flow(top, run_id=run_id, workspace=workspace)
    _author_generated_design_properties(
        top, run_id=run_id, clock_mode="multi", workspace=workspace
    )
    _run_visible_flow(
        top,
        run_id=run_id,
        clock_mode="multi",
        run_signoff=run_signoff,
        workspace=workspace,
    )

    test_root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    for test in ("mac_smoke", "absdiff", "energy"):
        assert (test_root / test).is_dir()


def _run_loaded_ip_flow(
    top: str,
    *,
    run_id: str,
    host: str,
    run_signoff: bool,
    workspace: Path,
) -> None:
    """Run one saved IP without touching HJSON, RTL source, or functional model."""

    _print_section(f"{top.upper()} ip_load flow — TOP={top} RUN_ID={run_id}")
    with _protect_ip_sources(top) as snapshot:
        _settings(top, clock_mode="single", run_id=run_id, host=host, workspace=workspace)
        _run_preflight(workspace=workspace)
        _print_section("Load saved IP")
        _run_loaded_ip_setup(top, run_id=run_id, workspace=workspace, snapshot=snapshot)
        _run_visible_flow(
            top,
            run_id=run_id,
            clock_mode="single",
            run_signoff=run_signoff,
            workspace=workspace,
        )
        _assert_loaded_sources_match(top, run_id, workspace, snapshot)


# -----------------------------------------------------------------------------
# E2E tests
# -----------------------------------------------------------------------------


@pytest.mark.e2e
def test_fx_single_clock_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run the generated single-clock flow in its own isolated workspace."""

    run_signoff = _run_signoff_enabled(request)
    with _temporary_workspace("flexsoc-single-e2e-", root=_e2e_root(request)) as workspace:
        _print_section("FlexSoC single-clock E2E")
        _print_context(workspace=workspace, signoff=run_signoff)
        _run_single_clock_flow(run_signoff=run_signoff, workspace=workspace)
        _print_section("FlexSoC single-clock E2E passed")


@pytest.mark.e2e
def test_fx_multi_clock_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run the generated multi-clock flow independently from single-clock."""

    run_signoff = _run_signoff_enabled(request)
    with _temporary_workspace("flexsoc-multiclock-e2e-", root=_e2e_root(request)) as workspace:
        _print_section("FlexSoC multi-clock E2E")
        _print_context(workspace=workspace, signoff=run_signoff)
        _run_multi_clock_flow(run_signoff=run_signoff, workspace=workspace)
        _print_section("FlexSoC multi-clock E2E passed")


@pytest.mark.e2e
def test_fx_cordic_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Run CORDIC as an existing IP in an isolated workspace."""

    run_signoff = _run_signoff_enabled(request)
    with _temporary_workspace("flexsoc-cordic-e2e-", root=_e2e_root(request)) as workspace:
        _print_section("FlexSoC CORDIC ip_load E2E")
        _print_context(workspace=workspace, signoff=run_signoff)
        _run_loaded_ip_flow(
            os.environ.get("FLEXSOC_CORDIC_TOP", "cordic"),
            run_id=os.environ.get("FLEXSOC_CORDIC_RUN_ID", DEFAULT_RUN_ID),
            host=os.environ.get("FLEXSOC_HOST", DEFAULT_HOST),
            run_signoff=run_signoff,
            workspace=workspace,
        )
        _print_section("FlexSoC CORDIC ip_load E2E passed")


@pytest.mark.e2e
def test_fx_uart_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Run UART as an existing IP in an isolated workspace."""

    run_signoff = _run_signoff_enabled(request)
    with _temporary_workspace("flexsoc-uart-e2e-", root=_e2e_root(request)) as workspace:
        _print_section("FlexSoC UART ip_load E2E")
        _print_context(workspace=workspace, signoff=run_signoff)
        _run_loaded_ip_flow(
            os.environ.get("FLEXSOC_UART_TOP", "uart"),
            run_id=os.environ.get("FLEXSOC_UART_RUN_ID", DEFAULT_RUN_ID),
            host=os.environ.get("FLEXSOC_HOST", DEFAULT_HOST),
            run_signoff=run_signoff,
            workspace=workspace,
        )
        _print_section("FlexSoC UART ip_load E2E passed")
