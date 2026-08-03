from __future__ import annotations

from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tempfile
from typing import Iterable, Iterator

import pytest
from rich.console import Console

from flexsoc.backend.setup_model import NCLOCK_DESIGN_TESTS, SHARED_VECTOR_TESTS


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_RUN_ID = "dev"
DEFAULT_HOST = "uart"
SINGLE_CLOCK_DOMAINS = "core:clk_i:rst_ni:10:low"
MULTI_CLOCK_DOMAINS = "cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low"
MULTI_CLOCK_RELATIONSHIPS = "async:cfg:rx,async:cfg:dsp,async:rx:dsp"
RTL_SOURCE_SUFFIXES = {".sv", ".svh", ".v", ".vh"}
DEFAULT_E2E_PDKS = ("sky130", "ihp-sg13g2")
DEFAULT_GLS_MODES = ("zero", "unit", "min", "typ", "max")
DEFAULT_GLS_BACKENDS = ("sv", "cocotb")
DEFAULT_GLS_TESTS = ("smoke", "auto_toggle")
SDF_GLS_MODES = {"min", "typ", "max"}

SAVED_IP_CUSTOM_TESTS = {
    "cordic": ("smoke_zero", "rotate_45deg", "quadrant_sweep", "random_small"),
    "uart": ("line_loopback", "rx_fifo", "noise_filter", "parity_reconfig"),
}
CONSOLE = Console()


@dataclass(frozen=True, slots=True)
class E2EPlan:
    """Technology and post-synthesis qualification matrix for one E2E test."""

    run_signoff: bool
    run_post_syn: bool
    pdks: tuple[str, ...]
    gls_modes: tuple[str, ...]
    gls_backends: tuple[str, ...]
    gls_tests: tuple[str, ...]


# -----------------------------------------------------------------------------
# Small command helpers
# -----------------------------------------------------------------------------


def _live() -> bool:
    """Return True when fx should stream full tool output with --live."""

    return os.environ.get("FLEXSOC_E2E_LIVE") == "1" or os.environ.get("FLEXSOC_FULL_FLOW_LIVE") == "1"


def _run_signoff_enabled(request: pytest.FixtureRequest) -> bool:
    """Return True unless pytest was launched with --no-signoff."""

    return not bool(request.config.getoption("--no-signoff"))


def _csv_option(
    request: pytest.FixtureRequest,
    option: str,
    environment: str,
    default: tuple[str, ...],
) -> tuple[str, ...]:
    """Resolve one comma-separated pytest/environment E2E option."""

    raw = request.config.getoption(option) or os.environ.get(environment, "")
    values = tuple(item.strip() for item in str(raw).split(",") if item.strip())
    return values or default


def _e2e_plan(request: pytest.FixtureRequest) -> E2EPlan:
    """Build and validate the full technology/GLS matrix for one E2E test."""

    from flexsoc.pdk import normalize_name

    run_signoff = _run_signoff_enabled(request)
    pdks = tuple(
        dict.fromkeys(
            normalize_name(name)
            for name in _csv_option(
                request, "e2e_pdks", "FLEXSOC_E2E_PDKS", DEFAULT_E2E_PDKS
            )
        )
    )
    modes = _csv_option(
        request, "e2e_gls_modes", "FLEXSOC_E2E_GLS_MODES", DEFAULT_GLS_MODES
    )
    invalid_modes = sorted(set(modes) - set(DEFAULT_GLS_MODES))
    if invalid_modes:
        raise pytest.UsageError(f"unsupported E2E GLS timing modes: {invalid_modes}")

    backends = _csv_option(
        request,
        "e2e_gls_backends",
        "FLEXSOC_E2E_GLS_BACKENDS",
        DEFAULT_GLS_BACKENDS,
    )
    invalid_backends = sorted(set(backends) - set(DEFAULT_GLS_BACKENDS))
    if invalid_backends:
        raise pytest.UsageError(f"unsupported E2E GLS backends: {invalid_backends}")

    tests = _csv_option(
        request, "e2e_gls_tests", "FLEXSOC_E2E_GLS_TESTS", DEFAULT_GLS_TESTS
    )
    if "all" in tests and tests != ("all",):
        raise pytest.UsageError("E2E GLS test selector 'all' cannot be combined with names")

    run_post_syn = run_signoff and not bool(request.config.getoption("--no-post-syn-gls"))
    return E2EPlan(run_signoff, run_post_syn, pdks, modes, backends, tests)


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


def _print_context(*, workspace: Path, plan: E2EPlan) -> None:
    """Print the common E2E run context and qualification matrix."""

    CONSOLE.print(f"[bold]repo:[/bold] {REPO_ROOT}")
    CONSOLE.print(f"[bold]workspace:[/bold] {workspace}")
    CONSOLE.print(f"[bold]live output:[/bold] {_live()}")
    CONSOLE.print(f"[bold]signoff:[/bold] {plan.run_signoff}")
    CONSOLE.print(f"[bold]post-synthesis GLS:[/bold] {plan.run_post_syn}")
    CONSOLE.print(f"[bold]PDKs:[/bold] {', '.join(plan.pdks)}")
    CONSOLE.print(f"[bold]GLS modes:[/bold] {', '.join(plan.gls_modes)}")
    CONSOLE.print(f"[bold]GLS backends:[/bold] {', '.join(plan.gls_backends)}")
    CONSOLE.print(f"[bold]GLS tests:[/bold] {', '.join(plan.gls_tests)}")


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
    clock_domains: str,
    clock_relationships: str = "",
    run_id: str = DEFAULT_RUN_ID,
    host: str = DEFAULT_HOST,
    pdk: str | None = None,
    workspace: Path,
) -> None:
    """Select one canonical run/clock/technology configuration."""

    n_clocks = len([item for item in clock_domains.split(",") if item.strip()])
    args = [
        "settings", f"TOP={top}", f"RUN_TOP={top}", f"RUN_ID={run_id}", f"HOST={host}",
        f"N_CLOCKS={n_clocks}", f"CLOCK_DOMAINS={clock_domains}",
        f"CLOCK_RELATIONSHIPS={clock_relationships}",
    ]
    if pdk:
        args.append(f"PDK={pdk}")
    _run_fx(args, workspace=workspace)


def _run_preflight(*, pdk: str, workspace: Path) -> None:
    """Validate the CLI/toolchain and activate one usable digital PDK."""

    _print_section("Preflight — environment")
    _run_fx(["doctor"], workspace=workspace)
    _print_section(f"Preflight — PDK {pdk}")
    _run_fx(["pdk", "use", pdk], workspace=workspace)
    _run_fx(["pdk", "info", pdk], workspace=workspace)



@contextmanager
def _preserve_project_settings() -> Iterator[None]:
    """Restore project-local settings after an E2E technology matrix."""

    path = REPO_ROOT / ".flexsoc" / "settings.json"
    existed = path.is_file()
    original = path.read_bytes() if existed else b""
    try:
        yield
    finally:
        if existed:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(original)
        else:
            path.unlink(missing_ok=True)


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
        if os.environ.get("FLEXSOC_E2E_KEEP") == "1":
            CONSOLE.print(
                f"[bold green][debug] retained successful workspace:[/bold green] {workspace}"
            )
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
    """Check one saved IP package and its editable functional-test catalogue."""

    root = REPO_ROOT / "hw" / "ips" / top
    required_dirs = (
        "data", "doc", "drivers", "rtl", "dv/functional/model",
        "dv/functional/tests", "dv/functional/tb/sv", "dv/functional/tb/cocotb",
        "dv/formal/properties/prove", "dv/formal/properties/cover",
        "syn", "signoff", "pnr_openroad",
    )
    required_files = (
        f"data/{top}.hjson", f"doc/{top}.md", f"doc/{top}_interfaces.md",
        f"drivers/{top}.c", f"drivers/{top}.h", f"rtl/{top}.sv",
        f"rtl/{top}_core.sv", "rtl/rtl_common.f", "rtl/rtl_ip.f",
        f"dv/functional/model/{top}_model.py",
        f"dv/functional/model/{top}_regmap.py",
        f"dv/functional/model/{top}_tests.py",
        "dv/functional/model/README.md",
        f"dv/formal/properties/prove/{top}_prove.sv",
        f"dv/formal/properties/cover/{top}_cover.sv",
        "syn/synth.ys", "syn/synth_sv.ys", "syn/abc.constr", "syn/area.abc",
        "signoff/power.tcl", "signoff/sta.tcl",
        "signoff/sta_violators.tcl", "signoff/write_sdf.tcl",
        "pnr_openroad/config.mk", f"pnr_openroad/{top}.sdc",
    )
    missing = [
        path for path in (
            *(root / item for item in required_dirs),
            *(root / item for item in required_files),
        ) if not path.exists()
    ]
    assert not missing, f"invalid {top} IP structure; missing: {missing}"

    tests_file = root / "dv" / "functional" / "model" / f"{top}_tests.py"
    completed = subprocess.run(
        [sys.executable, str(tests_file), "--list"],
        cwd=tests_file.parent,
        check=True,
        capture_output=True,
        text=True,
    )
    actual = tuple(line for line in completed.stdout.splitlines() if line)
    expected = (*SHARED_VECTOR_TESTS[:-1], *SAVED_IP_CUSTOM_TESTS[top])
    assert actual == expected, f"unexpected {top} source test catalogue: {actual}"

    vectors = root / "dv" / "functional" / "tests"
    vector_names = {path.name for path in vectors.iterdir() if path.is_dir()}
    expected_vectors = {*SHARED_VECTOR_TESTS, *SAVED_IP_CUSTOM_TESTS[top]}
    assert vector_names == expected_vectors, (
        f"unexpected saved {top} vector catalogue: {sorted(vector_names)}"
    )
    for name in expected_vectors:
        missing_vectors = [
            file for file in ("config.regs", "data_in.vec", "data_out.vec")
            if not (vectors / name / file).is_file()
        ]
        assert not missing_vectors, f"incomplete saved {top}/{name}: {missing_vectors}"


@contextmanager
def _protect_ip_sources(top: str) -> Iterator[dict[Path, str]]:
    """Fail if an ip_load E2E run changes saved HJSON, RTL source, or model files."""

    _validate_ip_layout(top)
    snapshot = {path: _sha256(path) for path in _ip_protected_sources(top)}
    yield snapshot
    changed = [path for path, digest in snapshot.items() if _sha256(path) != digest]
    assert not changed, f"{top} source artifacts changed during ip_load E2E: {changed}"


def _assert_loaded_ip_tests(top: str, run_id: str, workspace: Path) -> None:
    """Require the six shared tests plus every saved-IP custom scenario."""

    root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    expected = {*SHARED_VECTOR_TESTS, *SAVED_IP_CUSTOM_TESTS[top]}
    actual = {path.name for path in root.iterdir() if path.is_dir()}
    assert actual == expected, f"unexpected generated {top} tests: {sorted(actual)}"
    for name in expected:
        folder = root / name
        missing = [
            file for file in ("config.regs", "data_in.vec", "data_out.vec")
            if not (folder / file).is_file()
        ]
        assert not missing, f"incomplete {top}/{name} vectors: {missing}"


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
    """Generate N-clock artifacts only through the generic public targets."""

    for targets in (
        ["setup", "--force"], ["hjson", "--force"], ["reg", "doc", "--force"],
        ["rtl_stub", "--force"], ["top_from_core", "--force"], ["flist", "--force"],
        ["setup_model", "--force"], ["tests_gen"],
        ["setup_tb", "setup_cocotb", "--force"],
    ):
        _run_fx(targets, top=top, run_id=run_id, workspace=workspace)


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

    _print_section("Timing constraints")
    _run_fx(["setup_sdc", "--force"], top=top, run_id=run_id, workspace=workspace)

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


def _selected_gls_tests(
    top: str, run_id: str, workspace: Path, requested: tuple[str, ...]
) -> tuple[str, ...]:
    """Resolve named or all generated vector tests for post-synthesis GLS."""

    root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    available = tuple(sorted(path.name for path in root.iterdir() if path.is_dir()))
    if requested == ("all",):
        return available
    missing = sorted(set(requested) - set(available))
    assert not missing, f"post-synthesis tests missing for {top}: {missing}"
    return requested


def _assert_sdf_payload(path: Path) -> None:
    """Require a non-empty SDF containing real delay records."""

    assert path.is_file() and path.stat().st_size > 0, f"missing or empty SDF: {path}"
    text = path.read_text(encoding="utf-8", errors="replace")
    assert "(DELAYFILE" in text, f"invalid SDF header: {path}"
    assert "(CELL" in text, f"SDF contains no CELL records: {path}"
    assert any(token in text for token in ("(IOPATH", "(INTERCONNECT", "(PORT")), (
        f"SDF contains no path/interconnect/port delays: {path}"
    )


def _assert_post_syn_report(
    path: Path,
    *,
    top: str,
    pdk: str,
    backend: str,
    mode: str,
    wave: Path,
) -> dict[str, object]:
    """Validate one GLS report and prove that requested SDF was exercised."""

    assert path.is_file(), f"missing post-synthesis report: {path}"
    report = json.loads(path.read_text(encoding="utf-8"))
    assert report.get("status") == "pass", f"post-synthesis report failed: {path}"
    assert report.get("stage") == "post_syn"
    assert report.get("backend") == backend
    assert report.get("timing_mode") == mode

    netlist = Path(str(report.get("netlist", ""))).resolve()
    assert netlist.is_file() and netlist.stat().st_size > 0, f"missing netlist: {netlist}"
    assert pdk in netlist.parts, f"netlist is not scoped to PDK={pdk}: {netlist}"

    reported_wave = Path(str(report.get("wave", ""))).resolve()
    assert reported_wave == wave.resolve(), (
        f"unexpected waveform path: report={reported_wave} requested={wave.resolve()}"
    )
    assert wave.is_file() and wave.stat().st_size > 0, f"missing or empty waveform: {wave}"

    if mode in SDF_GLS_MODES:
        sdf = Path(str(report.get("sdf", ""))).resolve()
        _assert_sdf_payload(sdf)
        assert pdk in sdf.parts, f"SDF is not scoped to PDK={pdk}: {sdf}"
        expected_corner = {"min": "ff", "typ": "tt", "max": "ss"}[mode]
        assert sdf.name == f"{top}_{expected_corner}.sdf", (
            f"unexpected SDF corner for mode={mode}: {sdf}"
        )
        assert report.get("timing_model") == "icarus-path-delay-only"
        assert report.get("timing_checks") == "disabled-unsupported-by-icarus"
        model_manifest = path.parent / "icarus_timing_models" / "manifest.json"
        assert model_manifest.is_file(), f"missing Icarus timing-model manifest: {model_manifest}"
        model_data = json.loads(model_manifest.read_text(encoding="utf-8"))
        assert model_data.get("mode") == "path-delay-only"
        annotation = report.get("annotation")
        assert isinstance(annotation, dict), f"missing annotation evidence: {path}"
        assert annotation.get("requested_marker") is True, f"$sdf_annotate marker missing: {path}"
        assert annotation.get("warnings") == [], f"SDF warnings found: {annotation.get('warnings')}"
        assert annotation.get("errors") == [], f"SDF errors found: {annotation.get('errors')}"
        markers = annotation.get("markers") or []
        assert any(sdf.name in str(marker) for marker in markers), (
            f"annotation marker does not identify {sdf.name}: {markers}"
        )
    else:
        assert report.get("sdf") is None
        assert report.get("annotation") is None
        expected = "functional-unit-delay" if mode == "unit" else "functional-zero-delay"
        assert report.get("timing_model") == expected
    return report


def _run_post_syn_gate_matrix(
    top: str,
    *,
    run_id: str,
    pdk: str,
    plan: E2EPlan,
    workspace: Path,
) -> list[str]:
    """Run and archive the complete post-synthesis qualification matrix."""

    from flexsoc.run_layout import pdk_run_layout, run_root

    _print_section(f"Post-synthesis GLS/back-annotation — PDK={pdk}")
    _run_fx(["setup_tb", "setup_cocotb", "--force"], top=top, run_id=run_id, workspace=workspace)
    selected_tests = _selected_gls_tests(top, run_id, workspace, plan.gls_tests)
    layout = pdk_run_layout(
        run_root(workspace, run_top=top, run_id=run_id), pdk=pdk, top=top
    )
    qualification = layout.post_syn_sim_dir / "e2e_qualification"
    failures: list[str] = []

    for mode in plan.gls_modes:
        for test_name in selected_tests:
            for backend in plan.gls_backends:
                stem = f"{top}_{pdk}_{test_name}_{backend}_{mode}"
                wave = qualification / "waves" / f"{stem}.fst"
                report_copy = qualification / "reports" / f"{stem}.json"
                log_copy = qualification / "logs" / f"{stem}.log"
                wave.parent.mkdir(parents=True, exist_ok=True)
                report_copy.parent.mkdir(parents=True, exist_ok=True)
                log_copy.parent.mkdir(parents=True, exist_ok=True)

                source_report = layout.post_syn_sim_dir / f"{top}_post_syn_{backend}_{mode}.json"
                source_report.unlink(missing_ok=True)
                ok = _run_fx(
                    [
                        "sim_post_syn",
                        "--set", f"GLS_BACKEND={backend}",
                        "--set", f"TIMING_MODE={mode}",
                        "--set", f"TEST_NAME={test_name}",
                        "--set", "SDF_STRICT=1",
                        "--set", "WAVE_FORMAT=fst",
                        "--set", f"WAVE_FILE={wave}",
                    ],
                    top=top,
                    run_id=run_id,
                    workspace=workspace,
                    required=False,
                )
                if source_report.is_file():
                    shutil.copy2(source_report, report_copy)
                    try:
                        payload = json.loads(source_report.read_text(encoding="utf-8"))
                        source_log = Path(str(payload.get("log", "")))
                        if source_log.is_file():
                            shutil.copy2(source_log, log_copy)
                    except (OSError, ValueError, TypeError):
                        pass

                try:
                    assert ok, f"fx sim_post_syn failed for {stem}"
                    _assert_post_syn_report(
                        source_report,
                        top=top,
                        pdk=pdk,
                        backend=backend,
                        mode=mode,
                        wave=wave,
                    )
                except AssertionError as exc:
                    failures.append(f"{stem}: {exc}")
                    CONSOLE.print(f"[bold red][GLS FAIL][/bold red] {stem}: {exc}")
                else:
                    CONSOLE.print(f"[bold green][GLS PASS][/bold green] {stem}")

    manifest = qualification / "matrix.json"
    manifest.write_text(
        json.dumps(
            {
                "top": top,
                "run_id": run_id,
                "pdk": pdk,
                "tests": list(selected_tests),
                "backends": list(plan.gls_backends),
                "timing_modes": list(plan.gls_modes),
                "sdf_strict": True,
                "failures": failures,
            },
            indent=2,
            sort_keys=True,
        )
        + "\n",
        encoding="utf-8",
    )

    sdf_modes = [mode for mode in plan.gls_modes if mode in SDF_GLS_MODES]
    if sdf_modes and selected_tests:
        power_mode = "typ" if "typ" in sdf_modes else sdf_modes[0]
        power_backend = "sv" if "sv" in plan.gls_backends else plan.gls_backends[0]
        _print_section(
            f"Post-GLS activity power — PDK={pdk} backend={power_backend} mode={power_mode}"
        )
        ok = _run_fx(
            [
                "power_analysis_all",
                "--set", f"POWER_TEST_NAMES={','.join(selected_tests)}",
                "--set", f"POWER_GLS_BACKEND={power_backend}",
                "--set", f"POWER_TIMING_MODE={power_mode}",
            ],
            top=top,
            run_id=run_id,
            workspace=workspace,
            required=False,
        )
        if not ok:
            failures.append(
                f"{top}/{pdk}: post-GLS activity power failed "
                f"for backend={power_backend} mode={power_mode}"
            )
    else:
        CONSOLE.print(
            "[yellow][power-analysis] skipped: E2E matrix contains no min/typ/max GLS mode[/yellow]"
        )

    return failures


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
    clock_domains: str,
    clock_relationships: str,
    host: str,
    plan: E2EPlan,
    workspace: Path,
) -> None:
    """Run common verification once, then complete sign-off for every PDK."""

    _run_lint_stages(top, run_id=run_id, workspace=workspace)
    _run_slang_ast(top, run_id=run_id, workspace=workspace)
    _run_regression(top, run_id=run_id, workspace=workspace)

    if not plan.run_signoff:
        _run_reports(top, run_id=run_id, workspace=workspace)
        return

    failures: list[str] = []
    for pdk in plan.pdks:
        _print_section(f"Technology flow — PDK={pdk}")
        _settings(
            top,
            clock_domains=clock_domains,
            clock_relationships=clock_relationships,
            run_id=run_id,
            host=host,
            pdk=pdk,
            workspace=workspace,
        )
        _run_preflight(pdk=pdk, workspace=workspace)
        equivalence_ok = _run_signoff_stages(
            top, run_id=run_id, clock_mode=clock_mode, workspace=workspace
        )
        if plan.run_post_syn:
            failures.extend(
                _run_post_syn_gate_matrix(
                    top, run_id=run_id, pdk=pdk, plan=plan, workspace=workspace
                )
            )
        _run_reports(top, run_id=run_id, workspace=workspace)
        if not equivalence_ok:
            failures.append(f"{top}/{pdk}: EQY equivalence did not close")

    if failures:
        pytest.fail("E2E technology matrix failures:\n  - " + "\n  - ".join(failures))


# -----------------------------------------------------------------------------
# Complete flows
# -----------------------------------------------------------------------------


def _run_single_clock_flow(*, plan: E2EPlan, workspace: Path) -> None:
    """Run the generated single-clock example target-by-target."""

    top = os.environ.get("FLEXSOC_SINGLE_TOP", "test")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"Single-clock generated flow — TOP={top} RUN_ID={run_id}")
    _settings(
        top,
        clock_domains=SINGLE_CLOCK_DOMAINS,
        run_id=run_id,
        host=host,
        pdk=plan.pdks[0],
        workspace=workspace,
    )
    _run_preflight(pdk=plan.pdks[0], workspace=workspace)
    _print_section("Generate RTL / model")
    _run_generated_rtl_flow(top, run_id=run_id, workspace=workspace)
    _author_generated_design_properties(
        top, run_id=run_id, clock_mode="single", workspace=workspace
    )
    _run_visible_flow(
        top,
        run_id=run_id,
        clock_mode="single",
        clock_domains=SINGLE_CLOCK_DOMAINS,
        clock_relationships="",
        host=host,
        plan=plan,
        workspace=workspace,
    )

    test_root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    for test in SHARED_VECTOR_TESTS:
        assert (test_root / test).is_dir()


def _run_multi_clock_flow(*, plan: E2EPlan, workspace: Path) -> None:
    """Run the generated multi-clock example target-by-target."""

    top = os.environ.get("FLEXSOC_MULTI_TOP", "tri_stream_dsp")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)

    _print_section(f"Multi-clock generated flow — TOP={top} RUN_ID={run_id}")
    _settings(
        top,
        clock_domains=MULTI_CLOCK_DOMAINS,
        clock_relationships=MULTI_CLOCK_RELATIONSHIPS,
        run_id=run_id,
        host=host,
        pdk=plan.pdks[0],
        workspace=workspace,
    )
    _run_preflight(pdk=plan.pdks[0], workspace=workspace)
    _print_section("Generate multi-clock RTL / model")
    _run_multiclock_rtl_flow(top, run_id=run_id, workspace=workspace)
    _author_generated_design_properties(
        top, run_id=run_id, clock_mode="multi", workspace=workspace
    )

    test_root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    auto_dir = test_root / "auto_toggle"
    auto_config = (auto_dir / "config.regs").read_text(encoding="utf-8")
    auto_toggle = (auto_dir / "data_in.vec").read_text(encoding="utf-8")
    auto_rows = [line for line in auto_toggle.splitlines() if line and not line.startswith("#")]
    assert all("@reset" not in row for row in auto_rows)
    assert "cfg.CTRL 0x00000001" in auto_config
    assert "@write cfg.CTRL" not in auto_toggle
    assert "@write cfg.GAIN" in auto_toggle

    _run_visible_flow(
        top,
        run_id=run_id,
        clock_mode="multi",
        clock_domains=MULTI_CLOCK_DOMAINS,
        clock_relationships=MULTI_CLOCK_RELATIONSHIPS,
        host=host,
        plan=plan,
        workspace=workspace,
    )

    for test in (*SHARED_VECTOR_TESTS, *NCLOCK_DESIGN_TESTS):
        assert (test_root / test).is_dir()


def _run_loaded_ip_flow(
    top: str,
    *,
    run_id: str,
    host: str,
    plan: E2EPlan,
    workspace: Path,
) -> None:
    """Run one saved IP without touching HJSON, RTL source, or functional model."""

    _print_section(f"{top.upper()} ip_load flow — TOP={top} RUN_ID={run_id}")
    with _protect_ip_sources(top) as snapshot:
        _settings(
            top,
            clock_domains=SINGLE_CLOCK_DOMAINS,
            run_id=run_id,
            host=host,
            pdk=plan.pdks[0],
            workspace=workspace,
        )
        _run_preflight(pdk=plan.pdks[0], workspace=workspace)
        _print_section("Load saved IP")
        _run_loaded_ip_setup(top, run_id=run_id, workspace=workspace, snapshot=snapshot)
        _run_visible_flow(
            top,
            run_id=run_id,
            clock_mode="single",
            clock_domains=SINGLE_CLOCK_DOMAINS,
            clock_relationships="",
            host=host,
            plan=plan,
            workspace=workspace,
        )
        _assert_loaded_sources_match(top, run_id, workspace, snapshot)
        _assert_loaded_ip_tests(top, run_id, workspace)


# -----------------------------------------------------------------------------
# E2E tests
# -----------------------------------------------------------------------------


@pytest.mark.e2e
def test_fx_single_clock_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run the generated single-clock flow across the complete PDK matrix."""

    plan = _e2e_plan(request)
    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-single-e2e-", root=_e2e_root(request)
    ) as workspace:
        _print_section("FlexSoC single-clock E2E")
        _print_context(workspace=workspace, plan=plan)
        _run_single_clock_flow(plan=plan, workspace=workspace)
        _print_section("FlexSoC single-clock E2E passed")


@pytest.mark.e2e
def test_fx_multi_clock_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run the generated multi-clock flow across the complete PDK matrix."""

    plan = _e2e_plan(request)
    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-multiclock-e2e-", root=_e2e_root(request)
    ) as workspace:
        _print_section("FlexSoC multi-clock E2E")
        _print_context(workspace=workspace, plan=plan)
        _run_multi_clock_flow(plan=plan, workspace=workspace)
        _print_section("FlexSoC multi-clock E2E passed")


@pytest.mark.e2e
def test_fx_cordic_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Run CORDIC across both technology and post-synthesis matrices."""

    plan = _e2e_plan(request)
    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-cordic-e2e-", root=_e2e_root(request)
    ) as workspace:
        _print_section("FlexSoC CORDIC ip_load E2E")
        _print_context(workspace=workspace, plan=plan)
        _run_loaded_ip_flow(
            os.environ.get("FLEXSOC_CORDIC_TOP", "cordic"),
            run_id=os.environ.get("FLEXSOC_CORDIC_RUN_ID", DEFAULT_RUN_ID),
            host=os.environ.get("FLEXSOC_HOST", DEFAULT_HOST),
            plan=plan,
            workspace=workspace,
        )
        _print_section("FlexSoC CORDIC ip_load E2E passed")


@pytest.mark.e2e
def test_fx_uart_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Run UART across both technology and post-synthesis matrices."""

    plan = _e2e_plan(request)
    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-uart-e2e-", root=_e2e_root(request)
    ) as workspace:
        _print_section("FlexSoC UART ip_load E2E")
        _print_context(workspace=workspace, plan=plan)
        _run_loaded_ip_flow(
            os.environ.get("FLEXSOC_UART_TOP", "uart"),
            run_id=os.environ.get("FLEXSOC_UART_RUN_ID", DEFAULT_RUN_ID),
            host=os.environ.get("FLEXSOC_HOST", DEFAULT_HOST),
            plan=plan,
            workspace=workspace,
        )
        _print_section("FlexSoC UART ip_load E2E passed")
