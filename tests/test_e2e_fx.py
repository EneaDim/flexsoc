from __future__ import annotations

from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
import hashlib
import json
import os
import shlex
import subprocess
import tempfile
from typing import Iterator

import pytest

from flexsoc.backend.setup_model import NCLOCK_DESIGN_TESTS, SHARED_VECTOR_TESTS


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_RUN_ID = "dev"
DEFAULT_HOST = "uart"
SINGLE_CLOCK_DOMAINS = "core:clk_i:rst_ni:10:low"
MULTI_CLOCK_DOMAINS = (
    "cfg:cfg_clk_i:cfg_rst_ni:20:low,"
    "rx:rx_clk_i:rx_rst_ni:16:low,"
    "dsp:dsp_clk_i:dsp_rst_ni:12:low"
)
MULTI_CLOCK_RELATIONSHIPS = "async:cfg:rx,async:cfg:dsp,async:rx:dsp"
RTL_SOURCE_SUFFIXES = {".sv", ".svh", ".v", ".vh"}
SDF_GLS_MODES = {"min", "typ", "max"}
SAVED_IP_CUSTOM_TESTS = {
    "cordic": ("smoke_zero", "rotate_45deg", "quadrant_sweep", "random_small"),
    "uart": ("line_loopback", "rx_fifo", "noise_filter", "parity_reconfig"),
}
AMBIENT_FX_SETTING_KEYS = (
    "TOP", "RUN_TOP", "RUN_ID", "HOST", "WORKSPACE", "RUN_ROOT", "PDK",
    "N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS", "CLK_PERIOD", "FORCE",
    "GLS_SIMULATOR", "WAVE_FORMAT", "TIMING_MODE", "FST2VCD", "GLS_BACKEND",
    "GLS_UNIT_DELAY", "SDF_STRICT", "SYN_DIR", "EQUIV_DIR", "IMPL_DIR",
)


@dataclass(frozen=True, slots=True)
class E2EConfig:
    """GLS controls shared by both mandatory technology branches."""

    run_signoff: bool
    run_post_syn: bool
    gls_mode: str
    gls_backend: str


def _one_value(
    request: pytest.FixtureRequest,
    option: str,
    environment: str,
    default: str,
) -> str:
    """Resolve one scalar E2E option and reject hidden comma-separated sweeps."""

    raw = str(request.config.getoption(option) or os.environ.get(environment, default))
    values = [value.strip() for value in raw.split(",") if value.strip()]
    if len(values) != 1:
        raise pytest.UsageError(
            f"{option} accepts exactly one value per pytest run; use the CI matrix "
            "to run multiple configurations"
        )
    return values[0]


def _e2e_config(request: pytest.FixtureRequest) -> E2EConfig:
    """Return GLS controls; every full E2E always runs SKY130 then IHP."""

    mode = _one_value(request, "e2e_gls_modes", "FLEXSOC_E2E_GLS_MODES", "typ")
    backend = _one_value(request, "e2e_gls_backends", "FLEXSOC_E2E_GLS_BACKENDS", "sv")
    if mode not in {"zero", "unit", "min", "typ", "max"}:
        raise pytest.UsageError(f"unsupported E2E GLS timing mode: {mode}")
    if backend not in {"sv", "cocotb"}:
        raise pytest.UsageError(f"unsupported E2E GLS backend: {backend}")
    run_signoff = not bool(request.config.getoption("--no-signoff"))
    run_post_syn = run_signoff and not bool(request.config.getoption("--no-post-syn-gls"))
    return E2EConfig(run_signoff, run_post_syn, mode, backend)


def _e2e_root(request: pytest.FixtureRequest) -> Path:
    """Return the base directory used for isolated E2E workspaces."""

    configured = request.config.getoption("--e2e-root") or os.environ.get("FLEXSOC_E2E_ROOT")
    root = Path(configured or "/tmp").expanduser().resolve()
    root.mkdir(parents=True, exist_ok=True)
    return root


def _fx_subprocess_env() -> dict[str, str]:
    """Return an environment that cannot override workspace-local fx settings."""

    environment = os.environ.copy()
    for key in AMBIENT_FX_SETTING_KEYS:
        environment.pop(key, None)
    return environment


def _recent_logs(top: str, run_id: str, workspace: Path, limit: int = 8) -> list[Path]:
    """Return the most recently modified logs for one run."""

    root = workspace / "runs" / top / run_id / "logs"
    if not root.exists():
        return []
    logs = [path for path in root.rglob("*") if path.is_file()]
    return sorted(logs, key=lambda path: path.stat().st_mtime)[-limit:]


def _dump_recent_logs(top: str, run_id: str, workspace: Path) -> None:
    """Print recent log paths and the tail of the newest log after a failure."""

    logs = _recent_logs(top, run_id, workspace)
    print(f"\n[debug] recent logs for TOP={top} RUN_ID={run_id}", flush=True)
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


def _run(
    command: str,
    *,
    workspace: Path,
    top: str | None = None,
    run_id: str = DEFAULT_RUN_ID,
    required: bool = True,
) -> bool:
    """Print and execute exactly one complete command written in the test body."""

    print(f"\n>>> {command}", flush=True)
    completed = subprocess.run(
        shlex.split(command),
        cwd=REPO_ROOT,
        check=False,
        env=_fx_subprocess_env(),
    )
    if completed.returncode == 0:
        return True
    if top is not None:
        _dump_recent_logs(top, run_id, workspace)
    message = f"{command} failed with exit code {completed.returncode}"
    if required:
        pytest.fail(message)
    print(f"[non-blocking] {message}", flush=True)
    return False


@contextmanager
def _preserve_project_settings() -> Iterator[None]:
    """Restore project-local settings after an E2E run."""

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
def _temporary_workspace(prefix: str, root: Path) -> Iterator[Path]:
    """Create one isolated workspace and always preserve it for inspection."""

    workspace = Path(tempfile.mkdtemp(prefix=prefix, dir=root))
    try:
        yield workspace
    finally:
        print(f"[debug] retained workspace: {workspace}", flush=True)


def _sha256(path: Path) -> str:
    """Hash one source artifact used by an ip_load regression."""

    return hashlib.sha256(path.read_bytes()).hexdigest()


def _ip_protected_sources(top: str) -> tuple[Path, ...]:
    """Return authored HJSON, RTL, and model artifacts that must stay immutable."""

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
    derived_model = model / f"{top}_regmap.py"
    protected.extend(
        sorted(
            path
            for path in model.rglob("*")
            if path.is_file()
            and path != derived_model
            and "__pycache__" not in path.parts
            and path.suffix not in {".pyc", ".pyo"}
        )
    )
    if not protected:
        raise AssertionError(f"invalid {top} source layout: no protected sources")
    return tuple(protected)


def _validate_ip_layout(top: str) -> None:
    """Check one saved IP package without launching a hidden subprocess."""

    root = REPO_ROOT / "hw" / "ips" / top
    required_dirs = (
        "data", "doc", "drivers", "rtl", "dv/functional/model",
        "dv/functional/tests", "dv/functional/tb/sv", "dv/functional/tb/cocotb",
        "dv/formal/properties/prove", "dv/formal/properties/cover",
        "syn/sky130", "signoff/sky130/equivalence", "impl/sky130",
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
        "syn/sky130/synth.ys", "syn/sky130/synth_sv.ys",
        "syn/sky130/abc.constr", "syn/sky130/area.abc",
        "impl/sky130/config.mk", f"signoff/sky130/{top}.sdc",
    )
    missing = [
        path
        for path in (
            *(root / item for item in required_dirs),
            *(root / item for item in required_files),
        )
        if not path.exists()
    ]
    assert not missing, f"invalid {top} IP structure; missing: {missing}"
    vector_names = {
        path.name for path in (root / "dv" / "functional" / "tests").iterdir()
        if path.is_dir()
    }
    expected = {*SHARED_VECTOR_TESTS, *SAVED_IP_CUSTOM_TESTS[top]}
    assert vector_names == expected, f"unexpected saved {top} vectors: {sorted(vector_names)}"


@contextmanager
def _protect_ip_sources(top: str) -> Iterator[dict[Path, str]]:
    """Fail if ip_load/ip_save changes the repository-owned IP package."""

    _validate_ip_layout(top)
    root = REPO_ROOT / "hw" / "ips" / top
    snapshot = {path: _sha256(path) for path in _ip_protected_sources(top)}
    package_snapshot = {
        path.relative_to(root): _sha256(path)
        for path in sorted(root.rglob("*"))
        if path.is_file() and "__pycache__" not in path.parts and path.suffix != ".pyc"
    }
    yield snapshot
    changed = [path for path, digest in snapshot.items() if _sha256(path) != digest]
    current_package = {
        path.relative_to(root): _sha256(path)
        for path in sorted(root.rglob("*"))
        if path.is_file() and "__pycache__" not in path.parts and path.suffix != ".pyc"
    }
    assert current_package == package_snapshot, (
        f"{top} package changed during E2E; ip_save must use IP_LIBRARY_ROOT"
    )
    assert not changed, f"{top} source artifacts changed during ip_load E2E: {changed}"


def _assert_loaded_sources_match(
    top: str, run_id: str, workspace: Path, snapshot: dict[Path, str]
) -> None:
    """Verify loaded authored HJSON, RTL, and model files remain byte-identical."""

    source_root = REPO_ROOT / "hw" / "ips" / top
    run_root = workspace / "runs" / top / run_id
    changed = []
    for source, digest in snapshot.items():
        loaded = run_root / source.relative_to(source_root)
        if not loaded.is_file() or _sha256(loaded) != digest:
            changed.append(loaded)
    assert not changed, f"{top} loaded authored sources changed: {changed}"


def _assert_loaded_ip_tests(top: str, run_id: str, workspace: Path) -> None:
    """Require the shared tests plus every saved-IP custom scenario."""

    root = workspace / "runs" / top / run_id / "dv" / "functional" / "tests"
    expected = {*SHARED_VECTOR_TESTS, *SAVED_IP_CUSTOM_TESTS[top]}
    actual = {path.name for path in root.iterdir() if path.is_dir()}
    assert actual == expected, f"unexpected generated {top} tests: {sorted(actual)}"
    for name in expected:
        missing = [
            file
            for file in ("config.regs", "data_in.vec", "data_out.vec")
            if not (root / name / file).is_file()
        ]
        assert not missing, f"incomplete {top}/{name} vectors: {missing}"


def _seed_stale_tb_scaffold(run: Path) -> tuple[Path, Path]:
    """Plant stale files that complete setup must remove from both backends."""

    sv = run / "dv" / "functional" / "tb" / "sv" / "stale_loaded_ip.marker"
    cocotb = run / "dv" / "functional" / "tb" / "cocotb" / "stale_loaded_ip.marker"
    sv.write_text("stale\n", encoding="utf-8")
    cocotb.write_text("stale\n", encoding="utf-8")
    return sv, cocotb


def _assert_tb_scaffolds_recreated(
    markers: tuple[Path, Path], run: Path, top: str
) -> None:
    """Require both setup commands to replace their complete generated trees."""

    assert not any(path.exists() for path in markers), (
        f"stale loaded-IP scaffold survived setup: {markers}"
    )
    required = (
        run / "dv" / "functional" / "tb" / "sv" / f"{top}_tb.sv",
        run / "dv" / "functional" / "tb" / "sv" / "tlul_if.sv",
        run / "dv" / "functional" / "tb" / "sv" / "drivers" /
        f"{top}_vec_driver.svh",
        run / "dv" / "functional" / "tb" / "cocotb" / f"{top}_tb.py",
        run / "dv" / "functional" / "tb" / "cocotb" / f"{top}_tb.sv",
        run / "dv" / "functional" / "tb" / "cocotb" / "drivers" /
        "vec_driver.py",
    )
    missing = [path for path in required if not path.is_file()]
    assert not missing, f"incomplete regenerated {top} testbench scaffold: {missing}"


def _assert_reset_driver_parity(run: Path, top: str, *, multiclock: bool) -> None:
    """Require SV and cocotb drivers to accept the same named reset grammar."""

    sv_driver_dir = run / "dv" / "functional" / "tb" / "sv" / "drivers"
    cocotb_driver_dir = run / "dv" / "functional" / "tb" / "cocotb" / "drivers"
    sv = "\n".join(
        path.read_text(encoding="utf-8")
        for path in sorted(sv_driver_dir.glob("*.svh"))
    )
    cocotb = "\n".join(
        path.read_text(encoding="utf-8")
        for path in sorted(cocotb_driver_dir.glob("*.py"))
    )
    assert "@reset" in sv
    assert "[TB][RESET]" in sv
    assert "unknown reset selector" in sv
    assert "@reset" in cocotb
    assert "[TB][RESET]" in cocotb
    assert "unknown reset selector" in cocotb
    if multiclock:
        assert "reset_selector" in sv
        assert "await reset(dut, selector" in cocotb
    else:
        assert "tb_apply_reset" in sv
        assert "reset_selector =" in sv
        assert "_default_reset_runner" in cocotb
        assert "_selected_reset_domains" in cocotb


def _assert_coverage_outputs(coverage: Path) -> None:
    """Validate functional coverage artifacts."""

    assert (coverage / "merged.dat").is_file()
    summary = coverage / "summary.txt"
    summary_json = coverage / "summary.json"
    assert summary.is_file()
    assert summary_json.is_file()
    data = json.loads(summary_json.read_text(encoding="utf-8"))
    assert data.get("schema_version") == 2
    assert data.get("display_columns") == [
        "line", "toggle", "expr", "branch", "fsm", "user", "total"
    ]


def _assert_post_syn_report(
    path: Path,
    *,
    top: str,
    pdk: str,
    test: str,
    backend: str,
    mode: str,
    wave: Path,
) -> None:
    """Validate one post-synthesis GLS report and its requested waveform."""

    assert path.is_file(), f"missing post-synthesis report: {path}"
    report = json.loads(path.read_text(encoding="utf-8"))
    assert report.get("status") == "pass", f"post-synthesis report failed: {path}"
    assert report.get("stage") == "post_syn"
    assert report.get("top") == top
    assert report.get("pdk") == pdk
    assert report.get("test_name") == test
    assert report.get("backend") == backend
    assert report.get("timing_mode") == mode
    assert Path(str(report.get("wave", ""))).resolve() == wave.resolve()
    assert wave.is_file() and wave.stat().st_size > 0, f"missing waveform: {wave}"
    netlist = Path(str(report.get("netlist", ""))).resolve()
    assert netlist.is_file() and pdk in netlist.parts, f"invalid netlist: {netlist}"
    if mode in SDF_GLS_MODES:
        sdf = Path(str(report.get("sdf", ""))).resolve()
        assert sdf.is_file() and sdf.stat().st_size > 0, f"missing SDF: {sdf}"
        assert pdk in sdf.parts
        annotation = report.get("annotation")
        assert isinstance(annotation, dict), f"missing SDF annotation evidence: {path}"
        assert annotation.get("requested_marker") is True
        assert annotation.get("warnings") == []
        assert annotation.get("errors") == []
    else:
        assert report.get("sdf") is None
        assert report.get("annotation") is None


def _run_power_and_fusion(
    *, workspace: Path, top: str, run_id: str, workdir: str,
    test: str, backend: str, mode: str,
) -> None:
    """Run activity power, then timing/power fusion for one GLS workload."""

    selectors = (
        f"--set POWER_TEST_NAME={test} "
        f"--set POWER_GLS_BACKEND={backend} "
        f"--set POWER_TIMING_MODE={mode} "
    )
    for target in ("power_analysis", "fusion_analysis"):
        _run(
            f"uv run --no-sync fx {target} --no-setup {selectors}--workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )


def _slang_values(top: str, run: Path) -> tuple[str, str, str]:
    """Return quoted Slang overrides; this helper does not execute commands."""

    rtl = run / "rtl"
    roots = (
        REPO_ROOT / "hw" / "ips" / "pkgs",
        REPO_ROOT / "hw" / "ips" / "prim",
        REPO_ROOT / "hw" / "ips" / "prim_opentitan",
        REPO_ROOT / "hw" / "ips" / "tlul",
    )
    search = " ".join(f"--search-root {path}" for path in roots)
    return (
        shlex.quote(f"SLANG_ROOT={rtl}"),
        shlex.quote(f"SLANG_TOP_FILE={rtl / f'{top}.sv'}"),
        shlex.quote(f"SLANG_SEARCH_ARGS={search}"),
    )


def _assert_ast(top: str, run: Path) -> None:
    """Require the Slang AST generated by the visible command."""

    ast = run / "analysis" / "slang" / f"{top}_ast.json"
    assert ast.is_file() and ast.stat().st_size > 0, f"missing or empty Slang AST: {ast}"

def _assert_design_formal_sources(top: str, run: Path) -> None:
    """Require real designer-owned prove and cover sources."""

    prove = run / "dv" / "formal" / "properties" / "prove" / f"{top}_prove.sv"
    cover = run / "dv" / "formal" / "properties" / "cover" / f"{top}_cover.sv"
    assert prove.is_file() and prove.stat().st_size > 0, f"missing formal prove scaffold: {prove}"
    assert cover.is_file() and cover.stat().st_size > 0, f"missing formal cover scaffold: {cover}"


def _assert_technology_closure(top: str, run: Path, pdk: str) -> None:
    """Require one isolated technology branch without inspecting saved IP sources."""

    assert (run / "syn" / pdk / f"{top}_synth.v").is_file()
    assert (run / "signoff" / pdk / "equivalence" / "rtl_vs_syn").is_dir()
    assert (run / "signoff" / pdk / "sdf").is_dir()
    assert (run / "signoff" / pdk / "sta").is_dir()
    assert (run / "signoff" / pdk / "power").is_dir()
    assert (run / "meta" / pdk / "manifest.json").is_file()
    assert (run / "meta" / pdk / "metrics.json").is_file()


def _assert_saved_signoff_scripts(
    library_root: Path, top: str, pdk: str, *, activity_count: int
) -> None:
    """Require one canonical Tcl per sign-off family in the saved PDK branch."""

    del activity_count  # Workload/corner multiplicity belongs to reports, not Tcl files.
    root = library_root / top
    syn = root / "syn" / pdk
    assert syn.is_dir()
    debug_checkpoints = [syn / f"{top}_{stage}.il" for stage in ("generic", "dffmap", "abc", "clean")]
    assert not any(path.exists() for path in debug_checkpoints), (
        f"diagnostic RTLIL checkpoints leaked into saved {top}/{pdk}: {debug_checkpoints}"
    )
    meta = root / "meta" / pdk
    assert (meta / "manifest.json").is_file()
    assert (meta / "metrics.json").is_file()
    assert (meta / "check.rpt").is_file() and (meta / "check.rpt").stat().st_size > 0
    assert not any(path.name == "__pycache__" for path in root.rglob("__pycache__"))
    assert not any(path.suffix in {".pyc", ".pyo"} for path in root.rglob("*"))
    assert (root / "impl").is_dir()
    pnr = root / "impl" / pdk
    assert not pnr.exists() or pnr.is_dir()
    signoff = root / "signoff" / pdk
    assert (signoff / f"{top}.sdc").is_file()
    assert (signoff / "equivalence" / "rtl_vs_syn").is_dir()
    canonical = {
        signoff / "sta" / "sta.tcl",
        signoff / "sdf" / "write_sdf.tcl",
        signoff / "power" / "estimate" / "power_estimate.tcl",
        signoff / "power" / "analysis" / "power_analysis.tcl",
        signoff / "fusion" / "fusion_analysis.tcl",
    }
    assert all(path.is_file() for path in canonical)
    all_tcl = {path for path in signoff.rglob("*.tcl")}
    assert all_tcl == canonical, (
        f"expected only five canonical OpenSTA Tcl files for {pdk}, "
        f"got {sorted(str(path.relative_to(signoff)) for path in all_tcl)}"
    )
    assert not (signoff / "power" / "activity" / "scripts").exists()
    forbidden = [
        path for path in signoff.rglob("*")
        if path.is_file()
        and "equivalence" not in path.parts
        and path.suffix not in {".tcl", ".sdc"}
    ]
    assert not forbidden, f"non-Tcl sign-off snapshots saved for {pdk}: {forbidden}"


def _assert_saved_multitech_layout(library_root: Path, top: str) -> None:
    """Require load -> two complete technology flows -> save to preserve both branches."""

    root = library_root / top
    for common in ("data", "doc", "drivers", "rtl", "dv"):
        assert (root / common).is_dir(), f"missing saved {top}/{common}"
    for pdk in ("sky130", "ihp-sg13g2"):
        assert (root / "syn" / pdk).is_dir(), f"missing saved {top} synthesis for {pdk}"
        assert (root / "signoff" / pdk / f"{top}.sdc").is_file()
        meta = root / "meta" / pdk
        assert (meta / "manifest.json").is_file(), f"missing saved {top} manifest for {pdk}"
        assert (meta / "metrics.json").is_file(), f"missing saved {top} metrics for {pdk}"
        assert (meta / "check.rpt").is_file(), f"missing saved {top} closure report for {pdk}"
        profile = root / "signoff" / pdk / "equivalence" / "rtl_vs_syn"
        assert (profile / f"{top}_rtl_vs_syn.eqy").is_file()
        assert (profile / f"{top}_eqy_view.sv").is_file()
    assert (root / "impl" / "sky130").is_dir()
    assert not any(path.name == "__pycache__" for path in root.rglob("__pycache__"))
    assert not any(path.suffix in {".pyc", ".pyo"} for path in root.rglob("*"))


# Every test below contains its complete ordered sequence of one-command fx invocations.

@pytest.mark.e2e
def test_fx_single_clock_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run one shared logical flow, then SKY130 and IHP sign-off branches."""

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_SINGLE_TOP", "test")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    n_clocks = 1
    clock_domains = SINGLE_CLOCK_DOMAINS
    clock_relationships = ""

    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-single-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        slang_root, slang_top, slang_search = _slang_values(top, run)
        _run(
            (
                f"uv run --no-sync fx settings --reset TOP={top} RUN_TOP={top} "
                f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} "
                f"CLOCK_DOMAINS={clock_domains} "
                f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx doctor --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx hjson --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx reg --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx doc --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx rtl_stub --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx top_from_core --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx flist --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup_model --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx tests_gen --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx tests --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup_tb --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup_cocotb --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_reset_driver_parity(run, top, multiclock=False)
        _run(
            f"uv run --no-sync fx lint_slang_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx lint_verilator_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            (
                f"uv run --no-sync fx slang_hier --set {slang_root} "
                f"--set {slang_top} --set {slang_search} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            (
                f"uv run --no-sync fx slang_ast --set {slang_root} "
                f"--set {slang_top} --set {slang_search} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_ast(top, run)
        _run(
            f"uv run --no-sync fx regression --no-setup --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx coverage --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx coverage_detail --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

        if config.run_signoff:
            _run(
                f"uv run --no-sync fx setup_formal --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_design_formal_sources(top, run)
            _run(
                f"uv run --no-sync fx setup_formal_csr_prove --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_formal_prove --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_csr_bmc --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_bmc --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_csr_prove --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_prove --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_formal_csr_cover --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_formal_cover --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_csr_cover --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_cover --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )

            # sky130: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"uv run --no-sync fx pdk use sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx pdk info sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_tb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                sky130_wave_smoke = sky130_post_syn / (
                    f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_smoke_arg = shlex.quote(str(sky130_wave_smoke))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_smoke,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                sky130_wave_corners = sky130_post_syn / (
                    f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_corners_arg = shlex.quote(str(sky130_wave_corners))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_corners,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_random_seed_1 = sky130_post_syn / (
                    f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_random_seed_1_arg = shlex.quote(str(sky130_wave_random_seed_1))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_1,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_random_seed_2 = sky130_post_syn / (
                    f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_random_seed_2_arg = shlex.quote(str(sky130_wave_random_seed_2))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_2,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_reconfig = sky130_post_syn / (
                    f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_reconfig_arg = shlex.quote(str(sky130_wave_reconfig))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_reconfig,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_auto_toggle = sky130_post_syn / (
                    f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_auto_toggle_arg = shlex.quote(str(sky130_wave_auto_toggle))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_auto_toggle,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run(
                f"uv run --no-sync fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "sky130")

            # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"uv run --no-sync fx pdk use ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx pdk info ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_tb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                ihp_sg13g2_wave_smoke = ihp_sg13g2_post_syn / (
                    f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_smoke_arg = shlex.quote(str(ihp_sg13g2_wave_smoke))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_smoke,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                ihp_sg13g2_wave_corners = ihp_sg13g2_post_syn / (
                    f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_corners_arg = shlex.quote(str(ihp_sg13g2_wave_corners))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_corners,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_random_seed_1 = ihp_sg13g2_post_syn / (
                    f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_random_seed_1_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_1))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_1,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_random_seed_2 = ihp_sg13g2_post_syn / (
                    f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_random_seed_2_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_2))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_2,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_reconfig = ihp_sg13g2_post_syn / (
                    f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_reconfig_arg = shlex.quote(str(ihp_sg13g2_wave_reconfig))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_reconfig,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_auto_toggle = ihp_sg13g2_post_syn / (
                    f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_auto_toggle_arg = shlex.quote(str(ihp_sg13g2_wave_auto_toggle))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_auto_toggle,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run(
                f"uv run --no-sync fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "ihp-sg13g2")
        test_root = run / "dv" / "functional" / "tests"
        for test_name in SHARED_VECTOR_TESTS:
            assert (test_root / test_name).is_dir()

@pytest.mark.e2e
def test_fx_multi_clock_flow_debug(request: pytest.FixtureRequest) -> None:
    """Run one N-clock logical flow, then SKY130 and IHP sign-off branches."""

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_MULTI_TOP", "tri_stream_dsp")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    n_clocks = 3
    clock_domains = MULTI_CLOCK_DOMAINS
    clock_relationships = MULTI_CLOCK_RELATIONSHIPS

    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-multiclock-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        slang_root, slang_top, slang_search = _slang_values(top, run)
        _run(
            (
                f"uv run --no-sync fx settings --reset TOP={top} RUN_TOP={top} "
                f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} "
                f"CLOCK_DOMAINS={clock_domains} "
                f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx doctor --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx hjson --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx reg --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx doc --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx rtl_stub --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx top_from_core --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx flist --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup_model --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx tests_gen --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx tests --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup_tb --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx setup_cocotb --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_reset_driver_parity(run, top, multiclock=True)
        _run(
            f"uv run --no-sync fx lint_slang_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx lint_verilator_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            (
                f"uv run --no-sync fx slang_hier --set {slang_root} "
                f"--set {slang_top} --set {slang_search} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            (
                f"uv run --no-sync fx slang_ast --set {slang_root} "
                f"--set {slang_top} --set {slang_search} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_ast(top, run)
        test_root = run / "dv" / "functional" / "tests"
        auto_config = (test_root / "auto_toggle" / "config.regs").read_text(encoding="utf-8")
        auto_toggle = (test_root / "auto_toggle" / "data_in.vec").read_text(encoding="utf-8")
        rows = [line for line in auto_toggle.splitlines() if line and not line.startswith("#")]
        assert all("@reset" not in row for row in rows)
        assert "cfg.CTRL 0x00000001" in auto_config
        assert "@write cfg.CTRL" not in auto_toggle
        assert "@write cfg.GAIN" in auto_toggle
        _run(
            f"uv run --no-sync fx regression --no-setup --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx coverage --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"uv run --no-sync fx coverage_detail --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

        if config.run_signoff:
            _run(
                f"uv run --no-sync fx setup_formal --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_design_formal_sources(top, run)
            _run(
                f"uv run --no-sync fx setup_formal_csr_prove --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_formal_prove --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_csr_bmc --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_bmc --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_csr_prove --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_prove --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_formal_csr_cover --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_formal_cover --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_csr_cover --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx formal_cover --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )

            # sky130: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"uv run --no-sync fx pdk use sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx pdk info sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_tb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                sky130_wave_smoke = sky130_post_syn / (
                    f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_smoke_arg = shlex.quote(str(sky130_wave_smoke))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_smoke,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                sky130_wave_corners = sky130_post_syn / (
                    f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_corners_arg = shlex.quote(str(sky130_wave_corners))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_corners,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_random_seed_1 = sky130_post_syn / (
                    f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_random_seed_1_arg = shlex.quote(str(sky130_wave_random_seed_1))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_1,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_random_seed_2 = sky130_post_syn / (
                    f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_random_seed_2_arg = shlex.quote(str(sky130_wave_random_seed_2))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_2,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_reconfig = sky130_post_syn / (
                    f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_reconfig_arg = shlex.quote(str(sky130_wave_reconfig))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_reconfig,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_auto_toggle = sky130_post_syn / (
                    f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_auto_toggle_arg = shlex.quote(str(sky130_wave_auto_toggle))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_auto_toggle,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_mac_smoke = sky130_post_syn / (
                    f"{top}_mac_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_mac_smoke_arg = shlex.quote(str(sky130_wave_mac_smoke))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=mac_smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_mac_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=mac_smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_mac_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_mac_smoke_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="mac_smoke",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_mac_smoke,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="mac_smoke", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_absdiff = sky130_post_syn / (
                    f"{top}_absdiff_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_absdiff_arg = shlex.quote(str(sky130_wave_absdiff))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=absdiff --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_absdiff_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=absdiff --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_absdiff_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_absdiff_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="absdiff",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_absdiff,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="absdiff", backend=config.gls_backend, mode=config.gls_mode,
                )
                sky130_wave_energy = sky130_post_syn / (
                    f"{top}_energy_{config.gls_backend}_{config.gls_mode}.fst"
                )
                sky130_wave_energy_arg = shlex.quote(str(sky130_wave_energy))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=energy --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_energy_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=energy --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_energy_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_energy_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="sky130", test="energy",
                    backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_energy,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="energy", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run(
                f"uv run --no-sync fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "sky130")

            # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"uv run --no-sync fx pdk use ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx pdk info ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_tb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                ihp_sg13g2_wave_smoke = ihp_sg13g2_post_syn / (
                    f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_smoke_arg = shlex.quote(str(ihp_sg13g2_wave_smoke))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_smoke,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                ihp_sg13g2_wave_corners = ihp_sg13g2_post_syn / (
                    f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_corners_arg = shlex.quote(str(ihp_sg13g2_wave_corners))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_corners,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_random_seed_1 = ihp_sg13g2_post_syn / (
                    f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_random_seed_1_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_1))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_1,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_random_seed_2 = ihp_sg13g2_post_syn / (
                    f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_random_seed_2_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_2))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_2,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_reconfig = ihp_sg13g2_post_syn / (
                    f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_reconfig_arg = shlex.quote(str(ihp_sg13g2_wave_reconfig))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_reconfig,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_auto_toggle = ihp_sg13g2_post_syn / (
                    f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_auto_toggle_arg = shlex.quote(str(ihp_sg13g2_wave_auto_toggle))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_auto_toggle,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_mac_smoke = ihp_sg13g2_post_syn / (
                    f"{top}_mac_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_mac_smoke_arg = shlex.quote(str(ihp_sg13g2_wave_mac_smoke))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=mac_smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_mac_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=mac_smoke --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_mac_smoke_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_mac_smoke_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="mac_smoke",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_mac_smoke,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="mac_smoke", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_absdiff = ihp_sg13g2_post_syn / (
                    f"{top}_absdiff_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_absdiff_arg = shlex.quote(str(ihp_sg13g2_wave_absdiff))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=absdiff --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_absdiff_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=absdiff --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_absdiff_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_absdiff_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="absdiff",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_absdiff,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="absdiff", backend=config.gls_backend, mode=config.gls_mode,
                )
                ihp_sg13g2_wave_energy = ihp_sg13g2_post_syn / (
                    f"{top}_energy_{config.gls_backend}_{config.gls_mode}.fst"
                )
                ihp_sg13g2_wave_energy_arg = shlex.quote(str(ihp_sg13g2_wave_energy))
                _run(
                    (
                        f"uv run --no-sync fx compile_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=energy --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_energy_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    (
                        f"uv run --no-sync fx sim_post_syn --no-setup "
                        f"--set GLS_BACKEND={config.gls_backend} "
                        f"--set TIMING_MODE={config.gls_mode} "
                        f"--set TEST_NAME=energy --set SDF_STRICT=1 "
                        f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_energy_arg} "
                        f"--workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_energy_{config.gls_backend}_"
                        f"{config.gls_mode}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="energy",
                    backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_energy,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="energy", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run(
                f"uv run --no-sync fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "ihp-sg13g2")
        test_root = run / "dv" / "functional" / "tests"
        for test_name in (*SHARED_VECTOR_TESTS, *NCLOCK_DESIGN_TESTS):
            assert (test_root / test_name).is_dir()

@pytest.mark.e2e
def test_fx_cordic_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Load CORDIC once and qualify the unchanged IP on SKY130 and IHP."""

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_CORDIC_TOP", "cordic")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    n_clocks = 1
    clock_domains = SINGLE_CLOCK_DOMAINS
    clock_relationships = ""

    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-cordic-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        saved_library = workspace / "saved_ip_library"
        saved_library_arg = shlex.quote(str(saved_library))
        slang_root, slang_top, slang_search = _slang_values(top, run)
        with _protect_ip_sources("cordic") as source_snapshot:
            _run(
                (
                    f"uv run --no-sync fx settings --reset TOP={top} RUN_TOP={top} "
                    f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} "
                    f"CLOCK_DOMAINS={clock_domains} "
                    f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx doctor --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx ip_load --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_sources_match(top, run_id, workspace, source_snapshot)
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"uv run --no-sync fx regmap_py --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx tests_gen --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            stale_tb_markers = _seed_stale_tb_scaffold(run)
            _run(
                f"uv run --no-sync fx setup_tb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_tb_scaffolds_recreated(stale_tb_markers, run, top)
            _assert_reset_driver_parity(run, top, multiclock=False)
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"uv run --no-sync fx tests --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx lint_slang_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx lint_verilator_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"uv run --no-sync fx slang_hier --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"uv run --no-sync fx slang_ast --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_ast(top, run)
            _run(
                f"uv run --no-sync fx regression --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"uv run --no-sync fx coverage --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx coverage_detail --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

            if config.run_signoff:
                _assert_design_formal_sources(top, run)
                _run(
                    f"uv run --no-sync fx setup_formal_csr_prove --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_formal_prove --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_csr_bmc --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_bmc --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_csr_prove --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_prove --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_formal_csr_cover --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_formal_cover --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_csr_cover --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_cover --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )

                # sky130: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"uv run --no-sync fx pdk use sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx pdk info sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_tb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                    sky130_wave_smoke = sky130_post_syn / (
                        f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_smoke_arg = shlex.quote(str(sky130_wave_smoke))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_smoke,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    sky130_wave_corners = sky130_post_syn / (
                        f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_corners_arg = shlex.quote(str(sky130_wave_corners))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_corners,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_random_seed_1 = sky130_post_syn / (
                        f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_random_seed_1_arg = shlex.quote(str(sky130_wave_random_seed_1))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_1,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_random_seed_2 = sky130_post_syn / (
                        f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_random_seed_2_arg = shlex.quote(str(sky130_wave_random_seed_2))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_2,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_reconfig = sky130_post_syn / (
                        f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_reconfig_arg = shlex.quote(str(sky130_wave_reconfig))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_reconfig,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_auto_toggle = sky130_post_syn / (
                        f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_auto_toggle_arg = shlex.quote(str(sky130_wave_auto_toggle))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_auto_toggle,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_smoke_zero = sky130_post_syn / (
                        f"{top}_smoke_zero_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_smoke_zero_arg = shlex.quote(str(sky130_wave_smoke_zero))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke_zero --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_zero_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke_zero --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_zero_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_smoke_zero_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="smoke_zero",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_smoke_zero,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke_zero", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_rotate_45deg = sky130_post_syn / (
                        f"{top}_rotate_45deg_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_rotate_45deg_arg = shlex.quote(str(sky130_wave_rotate_45deg))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rotate_45deg --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_rotate_45deg_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rotate_45deg --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_rotate_45deg_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_rotate_45deg_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="rotate_45deg",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_rotate_45deg,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rotate_45deg", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_quadrant_sweep = sky130_post_syn / (
                        f"{top}_quadrant_sweep_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_quadrant_sweep_arg = shlex.quote(str(sky130_wave_quadrant_sweep))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=quadrant_sweep --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_quadrant_sweep_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=quadrant_sweep --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_quadrant_sweep_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_quadrant_sweep_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="quadrant_sweep",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_quadrant_sweep,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="quadrant_sweep", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_random_small = sky130_post_syn / (
                        f"{top}_random_small_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_random_small_arg = shlex.quote(str(sky130_wave_random_small))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_small --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_small_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_small --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_small_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_small_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="random_small",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_small,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_small", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"uv run --no-sync fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_technology_closure(top, run, "sky130")
                _run(
                    (
                        f"uv run --no-sync fx ip_save --set IP_NAME={top} "
                        f"--set IP_LIBRARY_ROOT={saved_library_arg} --workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_saved_signoff_scripts(
                    saved_library, top, "sky130", activity_count=30
                )

                # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"uv run --no-sync fx pdk use ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx pdk info ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_tb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                    ihp_sg13g2_wave_smoke = ihp_sg13g2_post_syn / (
                        f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_smoke_arg = shlex.quote(str(ihp_sg13g2_wave_smoke))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_smoke,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    ihp_sg13g2_wave_corners = ihp_sg13g2_post_syn / (
                        f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_corners_arg = shlex.quote(str(ihp_sg13g2_wave_corners))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_corners,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_random_seed_1 = ihp_sg13g2_post_syn / (
                        f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_random_seed_1_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_1))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_1,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_random_seed_2 = ihp_sg13g2_post_syn / (
                        f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_random_seed_2_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_2))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_2,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_reconfig = ihp_sg13g2_post_syn / (
                        f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_reconfig_arg = shlex.quote(str(ihp_sg13g2_wave_reconfig))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_reconfig,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_auto_toggle = ihp_sg13g2_post_syn / (
                        f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_auto_toggle_arg = shlex.quote(str(ihp_sg13g2_wave_auto_toggle))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_auto_toggle,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_smoke_zero = ihp_sg13g2_post_syn / (
                        f"{top}_smoke_zero_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_smoke_zero_arg = shlex.quote(str(ihp_sg13g2_wave_smoke_zero))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke_zero --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_zero_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke_zero --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_zero_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_smoke_zero_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="smoke_zero",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_smoke_zero,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke_zero", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_rotate_45deg = ihp_sg13g2_post_syn / (
                        f"{top}_rotate_45deg_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_rotate_45deg_arg = shlex.quote(str(ihp_sg13g2_wave_rotate_45deg))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rotate_45deg --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_rotate_45deg_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rotate_45deg --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_rotate_45deg_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_rotate_45deg_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="rotate_45deg",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_rotate_45deg,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rotate_45deg", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_quadrant_sweep = ihp_sg13g2_post_syn / (
                        f"{top}_quadrant_sweep_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_quadrant_sweep_arg = shlex.quote(str(ihp_sg13g2_wave_quadrant_sweep))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=quadrant_sweep --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_quadrant_sweep_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=quadrant_sweep --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_quadrant_sweep_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_quadrant_sweep_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="quadrant_sweep",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_quadrant_sweep,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="quadrant_sweep", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_random_small = ihp_sg13g2_post_syn / (
                        f"{top}_random_small_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_random_small_arg = shlex.quote(str(ihp_sg13g2_wave_random_small))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_small --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_small_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_small --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_small_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_small_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_small",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_small,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_small", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"uv run --no-sync fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_technology_closure(top, run, "ihp-sg13g2")
                _run(
                    (
                        f"uv run --no-sync fx ip_save --set IP_NAME={top} "
                        f"--set IP_LIBRARY_ROOT={saved_library_arg} --workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_saved_signoff_scripts(
                    saved_library, top, "ihp-sg13g2", activity_count=30
                )
                _assert_saved_multitech_layout(saved_library, top)
            _assert_loaded_sources_match(top, run_id, workspace, source_snapshot)

@pytest.mark.e2e
def test_fx_uart_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Load UART once and qualify the unchanged IP on SKY130 and IHP."""

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_UART_TOP", "uart")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    n_clocks = 1
    clock_domains = SINGLE_CLOCK_DOMAINS
    clock_relationships = ""

    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-uart-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        saved_library = workspace / "saved_ip_library"
        saved_library_arg = shlex.quote(str(saved_library))
        slang_root, slang_top, slang_search = _slang_values(top, run)
        with _protect_ip_sources("uart") as source_snapshot:
            _run(
                (
                    f"uv run --no-sync fx settings --reset TOP={top} RUN_TOP={top} "
                    f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} "
                    f"CLOCK_DOMAINS={clock_domains} "
                    f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx doctor --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx ip_load --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_sources_match(top, run_id, workspace, source_snapshot)
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"uv run --no-sync fx regmap_py --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx tests_gen --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            stale_tb_markers = _seed_stale_tb_scaffold(run)
            _run(
                f"uv run --no-sync fx setup_tb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_tb_scaffolds_recreated(stale_tb_markers, run, top)
            _assert_reset_driver_parity(run, top, multiclock=False)
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"uv run --no-sync fx tests --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx lint_slang_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx lint_verilator_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"uv run --no-sync fx slang_hier --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"uv run --no-sync fx slang_ast --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_ast(top, run)
            _run(
                f"uv run --no-sync fx regression --no-setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"uv run --no-sync fx coverage --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"uv run --no-sync fx coverage_detail --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

            if config.run_signoff:
                _assert_design_formal_sources(top, run)
                _run(
                    f"uv run --no-sync fx setup_formal_csr_prove --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_formal_prove --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_csr_bmc --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_bmc --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_csr_prove --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_prove --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_formal_csr_cover --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_formal_cover --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_csr_cover --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx formal_cover --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )

                # sky130: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"uv run --no-sync fx pdk use sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx pdk info sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_tb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                    sky130_wave_smoke = sky130_post_syn / (
                        f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_smoke_arg = shlex.quote(str(sky130_wave_smoke))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_smoke,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    sky130_wave_corners = sky130_post_syn / (
                        f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_corners_arg = shlex.quote(str(sky130_wave_corners))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_corners,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_random_seed_1 = sky130_post_syn / (
                        f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_random_seed_1_arg = shlex.quote(str(sky130_wave_random_seed_1))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_1,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_random_seed_2 = sky130_post_syn / (
                        f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_random_seed_2_arg = shlex.quote(str(sky130_wave_random_seed_2))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_random_seed_2,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_reconfig = sky130_post_syn / (
                        f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_reconfig_arg = shlex.quote(str(sky130_wave_reconfig))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_reconfig,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_auto_toggle = sky130_post_syn / (
                        f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_auto_toggle_arg = shlex.quote(str(sky130_wave_auto_toggle))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_auto_toggle,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_line_loopback = sky130_post_syn / (
                        f"{top}_line_loopback_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_line_loopback_arg = shlex.quote(str(sky130_wave_line_loopback))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=line_loopback --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_line_loopback_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=line_loopback --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_line_loopback_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_line_loopback_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="line_loopback",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_line_loopback,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="line_loopback", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_rx_fifo = sky130_post_syn / (
                        f"{top}_rx_fifo_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_rx_fifo_arg = shlex.quote(str(sky130_wave_rx_fifo))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rx_fifo --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_rx_fifo_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rx_fifo --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_rx_fifo_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_rx_fifo_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="rx_fifo",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_rx_fifo,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rx_fifo", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_noise_filter = sky130_post_syn / (
                        f"{top}_noise_filter_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_noise_filter_arg = shlex.quote(str(sky130_wave_noise_filter))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=noise_filter --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_noise_filter_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=noise_filter --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_noise_filter_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_noise_filter_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="noise_filter",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_noise_filter,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="noise_filter", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    sky130_wave_parity_reconfig = sky130_post_syn / (
                        f"{top}_parity_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    sky130_wave_parity_reconfig_arg = shlex.quote(str(sky130_wave_parity_reconfig))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=parity_reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_parity_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=parity_reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={sky130_wave_parity_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_parity_reconfig_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="sky130", test="parity_reconfig",
                        backend=config.gls_backend, mode=config.gls_mode, wave=sky130_wave_parity_reconfig,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="parity_reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"uv run --no-sync fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_technology_closure(top, run, "sky130")
                _run(
                    (
                        f"uv run --no-sync fx ip_save --set IP_NAME={top} "
                        f"--set IP_LIBRARY_ROOT={saved_library_arg} --workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_saved_signoff_scripts(
                    saved_library, top, "sky130", activity_count=30
                )

                # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"uv run --no-sync fx pdk use ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx pdk info ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_tb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_cocotb --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx syn --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx eqy --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx setup_signoff --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sdf --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx sta --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx power_estimate --no-setup --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                    ihp_sg13g2_wave_smoke = ihp_sg13g2_post_syn / (
                        f"{top}_smoke_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_smoke_arg = shlex.quote(str(ihp_sg13g2_wave_smoke))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=smoke --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_smoke_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_smoke,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    ihp_sg13g2_wave_corners = ihp_sg13g2_post_syn / (
                        f"{top}_corners_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_corners_arg = shlex.quote(str(ihp_sg13g2_wave_corners))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=corners --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_corners_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_corners,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_random_seed_1 = ihp_sg13g2_post_syn / (
                        f"{top}_random_seed_1_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_random_seed_1_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_1))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_1 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_1_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_1,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_random_seed_2 = ihp_sg13g2_post_syn / (
                        f"{top}_random_seed_2_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_random_seed_2_arg = shlex.quote(str(ihp_sg13g2_wave_random_seed_2))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=random_seed_2 --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_random_seed_2_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_random_seed_2,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_reconfig = ihp_sg13g2_post_syn / (
                        f"{top}_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_reconfig_arg = shlex.quote(str(ihp_sg13g2_wave_reconfig))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_reconfig,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_auto_toggle = ihp_sg13g2_post_syn / (
                        f"{top}_auto_toggle_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_auto_toggle_arg = shlex.quote(str(ihp_sg13g2_wave_auto_toggle))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=auto_toggle --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_auto_toggle_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_auto_toggle,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_line_loopback = ihp_sg13g2_post_syn / (
                        f"{top}_line_loopback_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_line_loopback_arg = shlex.quote(str(ihp_sg13g2_wave_line_loopback))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=line_loopback --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_line_loopback_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=line_loopback --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_line_loopback_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_line_loopback_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="line_loopback",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_line_loopback,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="line_loopback", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_rx_fifo = ihp_sg13g2_post_syn / (
                        f"{top}_rx_fifo_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_rx_fifo_arg = shlex.quote(str(ihp_sg13g2_wave_rx_fifo))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rx_fifo --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_rx_fifo_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=rx_fifo --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_rx_fifo_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_rx_fifo_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="rx_fifo",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_rx_fifo,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rx_fifo", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_noise_filter = ihp_sg13g2_post_syn / (
                        f"{top}_noise_filter_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_noise_filter_arg = shlex.quote(str(ihp_sg13g2_wave_noise_filter))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=noise_filter --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_noise_filter_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=noise_filter --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_noise_filter_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_noise_filter_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="noise_filter",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_noise_filter,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="noise_filter", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    ihp_sg13g2_wave_parity_reconfig = ihp_sg13g2_post_syn / (
                        f"{top}_parity_reconfig_{config.gls_backend}_{config.gls_mode}.fst"
                    )
                    ihp_sg13g2_wave_parity_reconfig_arg = shlex.quote(str(ihp_sg13g2_wave_parity_reconfig))
                    _run(
                        (
                            f"uv run --no-sync fx compile_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=parity_reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_parity_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _run(
                        (
                            f"uv run --no-sync fx sim_post_syn --no-setup "
                            f"--set GLS_BACKEND={config.gls_backend} "
                            f"--set TIMING_MODE={config.gls_mode} "
                            f"--set TEST_NAME=parity_reconfig --set SDF_STRICT=1 "
                            f"--set WAVE_FORMAT=fst --set WAVE_FILE={ihp_sg13g2_wave_parity_reconfig_arg} "
                            f"--workdir {workdir}"
                        ),
                        workspace=workspace, top=top, run_id=run_id,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_parity_reconfig_{config.gls_backend}_"
                            f"{config.gls_mode}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="parity_reconfig",
                        backend=config.gls_backend, mode=config.gls_mode, wave=ihp_sg13g2_wave_parity_reconfig,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="parity_reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"uv run --no-sync fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"uv run --no-sync fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_technology_closure(top, run, "ihp-sg13g2")
                _run(
                    (
                        f"uv run --no-sync fx ip_save --set IP_NAME={top} "
                        f"--set IP_LIBRARY_ROOT={saved_library_arg} --workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_saved_signoff_scripts(
                    saved_library, top, "ihp-sg13g2", activity_count=30
                )
                _assert_saved_multitech_layout(saved_library, top)
            _assert_loaded_sources_match(top, run_id, workspace, source_snapshot)
