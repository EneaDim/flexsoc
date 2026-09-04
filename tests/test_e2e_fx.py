from __future__ import annotations

from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
import hashlib
import json
import os
import shlex
import shutil
import subprocess
import tempfile
from typing import Iterator

import pytest

from flexsoc.backend.design.model import NCLOCK_DESIGN_TESTS, SHARED_VECTOR_TESTS


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_RUN_ID = "dev"
DEFAULT_HOST = "uart"
SINGLE_CLOCK_DOMAINS = "core:clk_i:rst_ni:10:low"
MULTI_CLOCK_DOMAINS = (
    "cfg:cfg_clk_i:cfg_rst_ni:20:low,"
    "rx:rx_clk_i:rx_rst_ni:16:low,"
    "dsp:dsp_clk_i:dsp_rst_ni:30:low"
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
    "N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS", "REG_ITF", "CLK_PERIOD", "FORCE",
    "GLS_SIMULATOR", "WAVE_FORMAT", "TIMING_MODE", "FST2VCD", "GLS_BACKEND",
    "GLS_UNIT_DELAY", "SDF_STRICT", "SIGNOFF_STAGE", "SYN_DIR", "EQUIV_DIR", "IMPL_DIR",
)

REG_ITFS = ("tlul", "reg_iface", "axi_lite")


def _fetch_register_vendors(
    reg_itf: str, *, workspace: Path, top: str, run_id: str
) -> None:
    """Fetch the external RTL dependencies required by one register transport."""

    commands = {
        "tlul": (
            "fx fetch --set VENDOR=pulp_register_interface",
            "fx fetch --set VENDOR=lowrisc_ip",
        ),
        "reg_iface": ("fx fetch --set VENDOR=pulp_register_interface",),
        "axi_lite": (
            "fx fetch --set VENDOR=pulp_register_interface",
            "fx fetch --set VENDOR=pulp_common_cells",
            "fx fetch --set VENDOR=pulp_axi",
        ),
    }
    try:
        selected = commands[reg_itf]
    except KeyError as exc:
        raise AssertionError(f"unsupported E2E REG_ITF: {reg_itf}") from exc
    if not selected:
        print(f"[vendor] REG_ITF={reg_itf}: no external transport vendor required", flush=True)
    for command in selected:
        _run(
            f"{command} --workdir {shlex.quote(str(workspace))}",
            workspace=workspace, top=top, run_id=run_id,
        )


@dataclass(frozen=True, slots=True)
class E2EConfig:
    """Sign-off and implementation controls shared by both technology branches."""

    run_signoff: bool
    run_post_syn: bool
    run_pnr: bool
    gls_mode: str
    gls_backend: str
    ors: Path | None


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
    """Return technology-dependent E2E controls for the selected qualifying flows."""

    mode = _one_value(request, "e2e_gls_modes", "FLEXSOC_E2E_GLS_MODES", "typ")
    backend = _one_value(request, "e2e_gls_backends", "FLEXSOC_E2E_GLS_BACKENDS", "sv")
    if mode not in {"zero", "unit", "min", "typ", "max"}:
        raise pytest.UsageError(f"unsupported E2E GLS timing mode: {mode}")
    if backend not in {"sv", "cocotb"}:
        raise pytest.UsageError(f"unsupported E2E GLS backend: {backend}")
    run_signoff = not bool(request.config.getoption("--no-signoff"))
    run_post_syn = run_signoff and not bool(request.config.getoption("--no-post-syn-gls"))
    run_pnr = run_signoff and not bool(request.config.getoption("--no-pnr"))
    ors = _e2e_ors(request) if run_pnr else None
    return E2EConfig(run_signoff, run_post_syn, run_pnr, mode, backend, ors)


def _e2e_ors(request: pytest.FixtureRequest) -> Path:
    """Return the configured ORFS flow root without touching external tools."""

    configured = request.config.getoption("--e2e-ors") or os.environ.get("FLEXSOC_E2E_ORS")
    return Path(configured or (Path.home() / "OpenROAD-flow-scripts" / "flow")).expanduser().resolve()


def _e2e_root(request: pytest.FixtureRequest) -> Path:
    """Return the base directory used for isolated E2E workspaces."""

    configured = request.config.getoption("--e2e-root") or os.environ.get("FLEXSOC_E2E_ROOT")
    root = Path(configured or "/tmp").expanduser().resolve()
    root.mkdir(parents=True, exist_ok=True)
    return root


def _require_active_venv() -> None:
    """Require E2E commands to use the explicitly activated project virtualenv."""

    venv = os.environ.get("VIRTUAL_ENV")
    fx = shutil.which("fx")
    expected = Path(venv) / "bin" / "fx" if venv else None
    if expected is None or fx is None or Path(fx).resolve() != expected.resolve():
        pytest.fail("FlexSoC E2E requires an active venv; run: source .venv/bin/activate")


def _fx_subprocess_env() -> dict[str, str]:
    """Return an environment that cannot override workspace-local fx settings."""

    environment = os.environ.copy()
    for key in AMBIENT_FX_SETTING_KEYS:
        environment.pop(key, None)
        environment.pop(f"FLEXSOC_{key}", None)
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


def _assert_e2e_ip_save_isolated(argv: list[str]) -> None:
    """Require every E2E ip_save to target a non-repository library root."""

    if "ip_save" not in argv:
        return
    settings = [
        argv[index + 1]
        for index, token in enumerate(argv[:-1])
        if token == "--set"
    ]
    roots = [item.split("=", 1)[1] for item in settings if item.startswith("IP_LIBRARY_ROOT=")]
    assert len(roots) == 1, "E2E ip_save must set exactly one IP_LIBRARY_ROOT"
    target = Path(roots[0]).expanduser().resolve()
    repository_library = (REPO_ROOT / "hw" / "ips").resolve()
    assert target != repository_library and not target.is_relative_to(repository_library), (
        f"E2E ip_save must not write repository IPs: {target}"
    )


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
    argv = shlex.split(command)
    if argv and argv[0] == "fx":
        _require_active_venv()
    _assert_e2e_ip_save_isolated(argv)
    completed = subprocess.run(
        argv,
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


def _known_orfs_sky130_lvs_parser_failure(
    *, summary: dict[str, object], ors_flow: Path, platform: str
) -> bool:
    """Return true only for the known upstream SKY130 CDL parser failure.

    This is deliberately an E2E-only classifier.  Production physical sign-off keeps
    returning non-zero and keeps LVS as missing; the E2E may continue collecting later
    stages only when the exact upstream ORFS/KLayout failure is present.
    """

    if platform != "sky130hd":
        return False
    checks = summary.get("checks")
    if not isinstance(checks, dict):
        return False
    lvs = checks.get("lvs")
    if not isinstance(lvs, dict) or lvs.get("status") != "missing":
        return False
    log_value = lvs.get("log")
    if not isinstance(log_value, str) or not log_value:
        return False
    log = Path(log_value)
    if not log.is_file():
        return False
    text = log.read_text(encoding="utf-8", errors="replace")
    signature = (
        "Pin count mismatch between circuit definition and circuit call: "
        "6 expected, got 7"
    )
    if signature not in text or "sky130hd.lylvs" not in text:
        return False

    platform_cdl = ors_flow / "platforms" / platform / "cdl" / f"{platform}.cdl"
    if not platform_cdl.is_file():
        return False
    cdl = platform_cdl.read_text(encoding="utf-8", errors="replace")
    return (
        ".SUBCKT sky130_fd_sc_hd__macro_sparecell VGND VNB VPB VPWR LO" in cdl
        and "XI1 VGND VNB VPB VPWR net59 LO / sky130_fd_sc_hd__conb_1" in cdl
    )


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
        "constraints", "syn/sky130", "signoff/sky130/equivalence",
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
        f"constraints/{top}.sdc",
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
    implementation = root / "impl" / "sky130"
    if implementation.exists():
        assert implementation.is_dir()
        assert (implementation / "config.mk").is_file(), (
            f"invalid optional {top} implementation branch: {implementation}"
        )
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


def _seed_saved_ip_library(library_root: Path, top: str) -> None:
    """Clone the package so ip_save updates only a disposable E2E library."""

    shutil.copytree(REPO_ROOT / "hw" / "ips" / top, library_root / top)


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


def _assert_functional_clock_driver(run: Path, top: str) -> None:
    """Require SV/cocotb parity for SDC phase, duty and seeded jitter."""

    sv = (run / "dv" / "functional" / "tb" / "sv" / f"{top}_tb.sv").read_text(encoding="utf-8")
    py = (run / "dv" / "functional" / "tb" / "cocotb" / f"{top}_tb.py").read_text(encoding="utf-8")
    for delay in ("0.1", "4.95"):
        assert f"#{delay};" in sv
        assert f'Timer({delay}, unit="ns")' in py
    assert "jitter_next_ps = (jitter_state % 51) - 25;" in sv
    assert "low_delay_ns = (5050 + jitter_next_ps - jitter_prev_ps) / 1000.0;" in sv
    assert "jitter_next_ps = int(jitter_state % 51) - 25" in py
    assert "low_delay_ps = 5050 + jitter_next_ps - jitter_prev_ps" in py
    assert "FLEXSOC_SEED" in sv
    assert "FLEXSOC_SEED" in py
    assert "cocotb.start_soon(_flexsoc_clock(dut.clk_i))" in py

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


def _assert_provenance_blocked(command: str, *, workspace: Path, stage: str) -> None:
    """Require one consumer to reject an unvalidated modification."""

    print(f"\n>>> {command}", flush=True)
    completed = subprocess.run(
        shlex.split(command), cwd=REPO_ROOT, check=False,
        env=_fx_subprocess_env(), capture_output=True, text=True,
    )
    output = (completed.stdout or "") + (completed.stderr or "")
    print(output, end="" if output.endswith("\n") else "\n", flush=True)
    assert completed.returncode != 0 and f"{stage} provenance is MODIFIED" in output, (
        f"{command} was not blocked by modified {stage} provenance"
    )


def _assert_provenance_state(
    *, workspace: Path, top: str, run_id: str, run: Path, workdir: str,
    stage: str, expected: str,
) -> None:
    """Snapshot current metrics, render check, and require one provenance state."""

    _run(
        f"fx metrics --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id,
    )
    _run(
        f"fx check --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id,
    )
    metrics_paths = list((run / "meta").glob("*/metrics.json"))
    assert len(metrics_paths) == 1, f"expected one active PDK metrics file: {metrics_paths}"
    metrics = json.loads(metrics_paths[0].read_text(encoding="utf-8"))
    assert metrics["provenance"]["stages"][stage] == expected


def _exercise_stage_override(
    *, workspace: Path, top: str, run_id: str, run: Path, workdir: str,
    stage: str, artifact: Path, command: str, required: bool = True,
) -> None:
    """Exercise modify -> block -> validate -> consume -> restore for one setup stage."""

    assert artifact.is_file(), f"missing generated override artifact: {artifact}"
    canonical = artifact.read_bytes()
    comment = b"//" if artifact.suffix.lower() in {".v", ".vh", ".sv", ".svh"} else b"#"

    print(f"\n[provenance] {stage}: MODIFY generated artifact", flush=True)
    artifact.write_bytes(canonical + b"\n" + comment + b" FlexSoC E2E validated override\n")

    print(f"[provenance] {stage}: BLOCK unvalidated consumer", flush=True)
    _assert_provenance_blocked(command, workspace=workspace, stage=stage)

    print(f"[provenance] {stage}: VALIDATE designer override", flush=True)
    _run(
        f"fx validate_override --set STAGE={stage} --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id,
    )

    print(f"[provenance] {stage}: CONSUME validated override", flush=True)
    _run(command, workspace=workspace, top=top, run_id=run_id, required=required)
    _assert_provenance_state(
        workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
        stage=stage, expected="VALIDATED_OVERRIDE",
    )

    print(f"[provenance] {stage}: RESTORE generated artifact", flush=True)
    artifact.write_bytes(canonical)
    _assert_provenance_state(
        workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
        stage=stage, expected="CLEAN",
    )


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


def _gls_scenario(mode: str) -> str:
    """Return the scenario label used in SDF-backed GLS artifact names."""

    return {"min": "ff", "typ": "tt", "max": "ss"}.get(mode, mode)


def _assert_post_syn_report(
    path: Path,
    *,
    top: str,
    pdk: str,
    test: str,
    backend: str,
    mode: str,
) -> None:
    """Validate one post-synthesis GLS report and its generated waveform."""

    assert path.is_file(), f"missing post-synthesis report: {path}"
    report = json.loads(path.read_text(encoding="utf-8"))
    assert report.get("status") == "pass", f"post-synthesis report failed: {path}"
    assert report.get("stage") == "post_syn"
    assert report.get("top") == top
    assert report.get("pdk") == pdk
    assert report.get("test_name") == test
    assert report.get("backend") == backend
    assert report.get("timing_mode") == mode
    assert report.get("scenario") == _gls_scenario(mode)
    wave = Path(str(report.get("wave", ""))).resolve()
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
        assert report.get("interconnect_delays") == "none"
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
            f"fx {target} {selectors}--workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )


def _run_gls_all(
    *, workspace: Path, top: str, run_id: str, workdir: str, config: E2EConfig,
    stage: str = "post_syn",
) -> None:
    """Qualify every GLS test and timing scenario with both drivers."""

    other = "cocotb" if config.gls_backend == "sv" else "sv"
    for backend in (config.gls_backend, other):
        _run(
            (
                f"fx sim_{stage}_all "
                f"--set GLS_BACKEND={backend} --set TIMING_MODES=all "
                "--set TEST_NAMES=all --set SDF_STRICT=1 "
                f"--workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )


def _assert_post_pnr_gls_evidence(top: str, run: Path, pdk: str) -> None:
    """Require routed GLS reports to prove interconnect-delay simulation."""

    sim = run / "dv" / "functional" / "sim" / "post_pnr" / pdk
    reports = []
    for path in sorted(sim.glob(f"{top}_post_pnr_*.json")):
        report = json.loads(path.read_text(encoding="utf-8"))
        if report.get("phase") == "run":
            reports.append(report)
    assert reports, f"missing post-PnR GLS reports: {sim}"
    sdf_reports = [report for report in reports if report.get("timing_mode") in SDF_GLS_MODES]
    assert sdf_reports, f"missing routed SDF GLS reports: {sim}"
    assert all(report.get("status") == "pass" for report in reports)
    assert all(report.get("interconnect_delays") == "enabled" for report in sdf_reports)


def _run_post_pnr_signoff(
    *, workspace: Path, top: str, run_id: str, run: Path, workdir: str,
    pdk: str, config: E2EConfig,
) -> None:
    """Run routed STA/SDF/power and optional timing-aware GLS."""

    _run(
        f"fx signoff_post_pnr --setup --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id,
    )
    for target in ("sdf_post_pnr", "sta_post_pnr"):
        _run(
            f"fx {target} --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )

    root = run / "signoff" / pdk / "post_pnr"
    for corner in ("ss", "tt", "ff"):
        sdf = root / "sdf" / corner / f"{top}_{corner}.sdf"
        assert sdf.is_file() and sdf.stat().st_size > 0, f"missing post-PnR SDF: {sdf}"
        sdf_text = sdf.read_text(encoding="utf-8", errors="replace")
        assert "::" not in "\n".join(sdf_text.splitlines()[:12]), f"missing SDF typ header value: {sdf}"
        assert "(INTERCONNECT" in sdf_text, f"missing routed INTERCONNECT delays: {sdf}"
        for mode in ("setup", "hold"):
            timing = root / "sta" / corner / mode / "timing.rpt"
            assert timing.is_file() and timing.stat().st_size > 0, f"missing routed STA: {timing}"
            text = timing.read_text(encoding="utf-8", errors="replace")
            assert "clock_network=propagated" in text
            assert "interconnect=spef" in text
            assert "Routed parasitic annotation" in text
            assert "Clock latency and skew" in text
            assert "Worst routed paths" in text

    if config.run_post_syn:
        _run_gls_all(
            workspace=workspace, top=top, run_id=run_id, workdir=workdir,
            config=config, stage="post_pnr",
        )
        _assert_post_pnr_gls_evidence(top, run, pdk)

    _run(
        f"fx power_estimate_post_pnr --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id,
    )
    for corner in ("ss", "tt", "ff"):
        power = root / "power" / "estimate" / corner / "power.rpt"
        assert power.is_file() and power.stat().st_size > 0, f"missing post-PnR power: {power}"

    if not config.run_post_syn:
        return
    for target in ("power_analysis_post_pnr_all", "fusion_analysis_post_pnr_all"):
        _run(
            f"fx {target} --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
    assert (root / "power" / "analysis" / "summary.json").is_file()
    assert (root / "fusion" / "summary.json").is_file()


def _run_implementation(
    *, workspace: Path, top: str, run_id: str, run: Path, workdir: str,
    pdk: str, platform: str, config: E2EConfig,
) -> None:
    """Run physical implementation from the FlexSoC netlist and shared SDC."""

    if not config.run_pnr:
        return
    assert config.ors is not None
    if not (config.ors / "Makefile").is_file():
        raise pytest.UsageError(
            f"ORFS flow not found: {config.ors}; use --e2e-ors <flow> or --no-pnr"
        )
    ors = shlex.quote(f"ORS={config.ors}")
    _run(
        f"fx pnr --setup --set {ors} --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id,
    )
    impl = run / "impl" / pdk
    cfg = impl / "config.mk"
    text = cfg.read_text(encoding="utf-8")
    netlist = (run / "syn" / pdk / f"{top}_synth.v").resolve()
    sdc = (run / "constraints" / f"{top}.sdc").resolve()
    assert f"SYNTH_NETLIST_FILES := {netlist}" in text
    assert f"SDC_FILE             := {sdc}" in text
    assert "VERILOG_FILES" not in text
    assert "SYNTH_HDL_FRONTEND" not in text
    assert "ABC_AREA" not in text and "STRATEGY" not in text
    _run(
        f"fx pnr --set {ors} --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id,
    )
    log = run / "logs" / "pnr" / pdk / f"{top}_pnr.log"
    assert log.is_file() and log.stat().st_size > 0, f"missing PnR log: {log}"
    results = impl / "results" / platform / top / "base"
    for name in ("6_final.v", "6_final.sdc", "6_final.spef", "6_final.odb", "6_final.gds"):
        artifact = results / name
        assert artifact.is_file() and artifact.stat().st_size > 0, f"missing PnR artifact: {artifact}"
    physical_ok = _run(
        f"fx physical_signoff --set {ors} --workdir {workdir}",
        workspace=workspace, top=top, run_id=run_id, required=False,
    )
    summary_path = run / "signoff" / pdk / "post_pnr" / "physical" / "summary.json"
    assert summary_path.is_file() and summary_path.stat().st_size > 0
    summary = json.loads(summary_path.read_text(encoding="utf-8"))
    assert summary.get("status") in {"pass", "review", "fail"}
    checks = summary.get("checks", {})
    for name in ("route_drc", "antenna", "gds_drc", "lvs", "ir_drop"):
        assert isinstance(checks.get(name), dict), f"missing physical sign-off check: {name}"

    known_sky130_lvs_parser_failure = _known_orfs_sky130_lvs_parser_failure(
        summary=summary, ors_flow=config.ors, platform=platform,
    )
    if not physical_ok:
        if known_sky130_lvs_parser_failure:
            detail = "upstream ORFS sky130hd CDL parser rejects macro_sparecell '/' instance syntax"
        else:
            detail = ", ".join(
                f"{name}={check.get('status')}"
                for name, check in checks.items()
                if isinstance(check, dict) and check.get("status") not in {"pass", "unsupported"}
            ) or f"status={summary.get('status')}"
        print(f"[e2e] REVIEW · physical sign-off not clean ({detail}); continuing", flush=True)
    _run_post_pnr_signoff(
        workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
        pdk=pdk, config=config,
    )


def _slang_values(top: str, run: Path) -> tuple[str, str, str]:
    """Return quoted Slang overrides; dependency roots come from generated filelists."""

    rtl = run / "rtl"
    return (
        shlex.quote(f"SLANG_ROOT={rtl}"),
        shlex.quote(f"SLANG_TOP_FILE={rtl / f'{top}.sv'}"),
        shlex.quote("SLANG_SEARCH_ARGS="),
    )


def _assert_ast(top: str, run: Path) -> None:
    """Require the Slang AST generated by the visible command."""

    ast = run / "analysis" / "slang" / f"{top}_ast.json"
    assert ast.is_file() and ast.stat().st_size > 0, f"missing or empty Slang AST: {ast}"

def _assert_cdc_rdc_outputs(top: str, run: Path) -> None:
    """Require one complete CDC/RDC JSON plus one human report and raw extraction evidence."""

    analysis = run / "analysis" / "cdc_rdc"
    for name in ("summary.json", "cdc_rdc.rpt", "extract.ys", "design.json"):
        path = analysis / name
        assert path.is_file() and path.stat().st_size > 0, f"missing CDC/RDC artifact: {path}"
    summary = json.loads((analysis / "summary.json").read_text(encoding="utf-8"))
    assert summary.get("top") == top and summary.get("schema") == "flexsoc.cdc_rdc.v3"
    assert "findings" in summary["cdc"] and "findings" in summary["rdc"]
    assert isinstance(summary.get("obligations"), list)
    for obsolete in ("inventory.json", "cdc.json", "rdc.json", "setup.json", "glitch.json", "obligations.json"):
        assert not (analysis / obsolete).exists(), f"obsolete CDC/RDC artifact survived: {analysis / obsolete}"
    extract_log = run / "logs" / "analysis" / "cdc_rdc" / "extract.log"
    assert extract_log.is_file() and extract_log.stat().st_size > 0, f"missing CDC/RDC extraction log: {extract_log}"

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
    for corner in ("ss", "tt", "ff"):
        sdf = run / "signoff" / pdk / "sdf" / corner / f"{top}_{corner}.sdf"
        assert sdf.is_file() and sdf.stat().st_size > 0, f"missing post-synthesis SDF: {sdf}"
        assert "(INTERCONNECT" not in sdf.read_text(encoding="utf-8", errors="replace")
    manifest_path = run / "meta" / pdk / "manifest.json"
    metrics_path = run / "meta" / pdk / "metrics.json"
    assert manifest_path.is_file()
    assert metrics_path.is_file()
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    metrics = json.loads(metrics_path.read_text(encoding="utf-8"))
    assert isinstance(manifest.get("analysis", {}).get("cdc_rdc"), dict)
    assert isinstance(metrics.get("cdc_rdc"), dict)
    assert metrics.get("closure", {}).get("order", [])[:2] == ["lint", "cdc_rdc"]
    flow = metrics.get("flow", {})
    assert flow.get("order", []) == [
        "lint", "cdc_rdc", "functional", "formal", "synthesis", "equivalence",
        "pre_implementation_signoff", "implementation", "post_implementation_signoff",
    ]
    if (run / "signoff" / pdk / "post_pnr").is_dir():
        assert metrics.get("implementation", {}).get("status") == "pass"
        assert manifest.get("implementation", {}).get("status") == "pass"
        assert isinstance(manifest.get("signoff", {}).get("post_pnr"), dict)
        assert isinstance(metrics.get("post_pnr", {}).get("fusion_analysis"), dict)
        physical = metrics.get("physical_signoff")
        assert isinstance(physical, dict)
        post_status = flow.get("stages", {}).get("post_implementation_signoff")
        if physical.get("status") == "fail":
            assert post_status == "fail"
        else:
            assert post_status in {"pass", "review"}
        assert isinstance(manifest.get("physical_signoff"), dict)
        closure_order = metrics.get("closure", {}).get("order", [])
        assert "physical_signoff" in closure_order and "post_pnr_fusion" in closure_order
        assert closure_order.index("physical_signoff") < closure_order.index("post_pnr_sdf")



def _assert_pre_impl_ip_branch(top: str, run: Path, pdk: str) -> None:
    """Require IP-load qualification to stop before EQY execution and PnR."""

    assert (run / "syn" / pdk / f"{top}_synth.v").is_file()
    assert (run / "signoff" / pdk / "sdf").is_dir()
    assert (run / "signoff" / pdk / "sta").is_dir()
    assert (run / "signoff" / pdk / "power").is_dir()
    assert not (run / "logs" / "signoff" / pdk / "equivalence" / f"{top}_rtl_vs_syn.log").exists()
    assert not (run / "logs" / "pnr" / pdk / f"{top}_pnr.log").exists()
    metrics_path = run / "meta" / pdk / "metrics.json"
    manifest_path = run / "meta" / pdk / "manifest.json"
    assert metrics_path.is_file() and manifest_path.is_file()
    metrics = json.loads(metrics_path.read_text(encoding="utf-8"))
    flow = metrics.get("flow", {}).get("stages", {})
    assert flow.get("pre_implementation_signoff") == "pass"
    # A loaded package may carry prior EQY metrics; the missing current-run EQY
    # log above is the source of truth that this qualification branch skipped it.
    assert flow.get("implementation") == "missing"
    assert flow.get("post_implementation_signoff") == "incomplete"
    assert metrics.get("technical_status") == "REVIEW"
    provenance = metrics.get("provenance", {})
    assert isinstance(provenance, dict) and provenance.get("status") == "CLEAN"


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
    assert (root / "constraints" / f"{top}.sdc").is_file()
    assert not any(signoff.glob("*.sdc")), "SDC must not be duplicated in a PDK branch"
    assert (signoff / "equivalence" / "rtl_vs_syn").is_dir()
    canonical = {
        signoff / "sta" / "sta.tcl",
        signoff / "sdf" / "write_sdf.tcl",
        signoff / "power" / "estimate" / "power_estimate.tcl",
        signoff / "power" / "analysis" / "power_analysis.tcl",
        signoff / "fusion" / "fusion_analysis.tcl",
    }
    assert all(path.is_file() for path in canonical)
    assert (signoff / "sta" / "sta.rpt").is_file()
    assert (signoff / "sta" / "sta.json").is_file()
    assert not any(signoff.glob("sta/*/*/timing.rpt")), "scenario-local timing reports must not be packaged"
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
        and (
            path.name.startswith(".")
            or path.suffix not in {".tcl", ".sdc", ".rpt", ".json", ".sdf"}
        )
    ]
    assert not forbidden, f"unexpected saved sign-off artifacts for {pdk}: {forbidden}"


def _assert_saved_multitech_layout(library_root: Path, top: str) -> None:
    """Require load -> two complete technology flows -> save to preserve both branches."""

    root = library_root / top
    for common in ("data", "doc", "drivers", "rtl", "dv"):
        assert (root / common).is_dir(), f"missing saved {top}/{common}"
    assert (root / "logs" / "lint").is_dir(), f"missing saved {top} lint evidence"
    assert (root / "analysis" / "cdc_rdc" / "summary.json").is_file(), f"missing saved {top} CDC/RDC summary"
    assert (root / "analysis" / "cdc_rdc" / "cdc_rdc.rpt").is_file(), f"missing saved {top} CDC/RDC report"
    assert not (root / "logs" / "analysis" / "cdc_rdc").exists(), "CDC/RDC raw logs must not be packaged"
    assert not (root / "logs" / "lint" / "raw").exists(), "raw lint logs must not be packaged"
    design_intent = root / "meta" / "design_intent.json"
    assert design_intent.is_file(), f"missing saved {top} design intent"
    intent = json.loads(design_intent.read_text(encoding="utf-8"))["design_intent"]
    assert (root / "constraints" / f"{top}.sdc").is_file(), f"missing saved {top} canonical SDC"
    settings_by_pdk = {}
    for pdk in ("sky130", "ihp-sg13g2"):
        assert (root / "syn" / pdk).is_dir(), f"missing saved {top} synthesis for {pdk}"
        assert not any((root / "signoff" / pdk).glob("*.sdc"))
        meta = root / "meta" / pdk
        assert (meta / "manifest.json").is_file(), f"missing saved {top} manifest for {pdk}"
        assert (meta / "metrics.json").is_file(), f"missing saved {top} metrics for {pdk}"
        assert (meta / "settings.json").is_file(), f"missing saved {top} settings for {pdk}"
        assert (meta / "check.rpt").is_file(), f"missing saved {top} closure report for {pdk}"
        settings_by_pdk[pdk] = json.loads((meta / "settings.json").read_text(encoding="utf-8"))
        assert settings_by_pdk[pdk]["pdk"] == pdk
        assert settings_by_pdk[pdk]["effective"]["PDK"] == pdk
        assert settings_by_pdk[pdk]["design_intent"] == intent
        profile = root / "signoff" / pdk / "equivalence" / "rtl_vs_syn"
        assert (profile / f"{top}_rtl_vs_syn.eqy").is_file()
        assert (profile / f"{top}_eqy_view.sv").is_file()
    assert (root / "impl").is_dir()
    for implementation in (root / "impl").iterdir():
        if implementation.is_dir():
            assert (implementation / "config.mk").is_file()
    assert not any(path.name == "__pycache__" for path in root.rglob("__pycache__"))
    assert not any(path.suffix in {".pyc", ".pyo"} for path in root.rglob("*"))


# Every test below keeps its ordered fx flow explicit; vendor bootstrap is shared above.

@pytest.mark.e2e
@pytest.mark.parametrize("reg_itf", REG_ITFS, ids=REG_ITFS)
def test_fx_single_clock_flow_debug(
    request: pytest.FixtureRequest, reg_itf: str
) -> None:
    """Qualify each register transport through the full single-clock lifecycle."""
    print(f"\n=== E2E · single-clock scaffold · REG_ITF={reg_itf} ===", flush=True)

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_SINGLE_TOP", "test")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    n_clocks = 1
    clock_domains = SINGLE_CLOCK_DOMAINS
    clock_relationships = ""

    with _preserve_project_settings(), _temporary_workspace(
        f"flexsoc-single-{reg_itf}-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        slang_root, slang_top, slang_search = _slang_values(top, run)
        _run(
            (
                f"fx settings --reset TOP={top} RUN_TOP={top} "
                f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} REG_ITF={reg_itf} "
                f"CLOCK_DOMAINS={clock_domains} "
                f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx doctor --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _fetch_register_vendors(
            reg_itf, workspace=workspace, top=top, run_id=run_id
        )
        _run(
            f"fx setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx hjson --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx reg --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx doc --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx systemrdl --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx rtl_stub --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx top_from_core --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx flist --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx lint_slang_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx lint_verilator_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx sdc --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx cdc_rdc --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx cdc_rdc --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id, required=False,
        )
        _assert_cdc_rdc_outputs(top, run)
        _run(
            f"fx model --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx tests_gen --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx tests --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx tb --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx cocotb --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_reset_driver_parity(run, top, multiclock=False)
        _assert_functional_clock_driver(run, top)
        _run(
            (
                f"fx slang_hier --set {slang_root} "
                f"--set {slang_top} --set {slang_search} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            (
                f"fx slang_ast --set {slang_root} "
                f"--set {slang_top} --set {slang_search} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_ast(top, run)
        _run(
            f"fx regression --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx coverage --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx coverage_detail --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

        _run(
            f"fx formal --setup --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_design_formal_sources(top, run)
        _run(
            f"fx formal_csr_bmc --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_bmc --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_csr_prove --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_prove --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_csr_cover --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_cover --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )

        if config.run_signoff:
            # sky130: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"fx pdk use sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx pdk info sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx tb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cocotb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id, required=False,
            )
            _run(
                f"fx signoff --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sdf --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sta --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx power_estimate --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                _run_gls_all(
                    workspace=workspace, top=top, run_id=run_id,
                    workdir=workdir, config=config,
                )
                sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run_implementation(
                workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
                pdk="sky130", platform="sky130hd", config=config,
            )
            _run(
                f"fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "sky130")

            # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"fx pdk use ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx pdk info ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx tb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cocotb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id, required=False,
            )
            _run(
                f"fx signoff --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sdf --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sta --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx power_estimate --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                _run_gls_all(
                    workspace=workspace, top=top, run_id=run_id,
                    workdir=workdir, config=config,
                )
                ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run_implementation(
                workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
                pdk="ihp-sg13g2", platform="ihp-sg13g2", config=config,
            )
            _run(
                f"fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "ihp-sg13g2")
        test_root = run / "dv" / "functional" / "tests"
        for test_name in SHARED_VECTOR_TESTS:
            assert (test_root / test_name).is_dir()

@pytest.mark.e2e
@pytest.mark.parametrize("reg_itf", REG_ITFS, ids=REG_ITFS)
def test_fx_multi_clock_flow_debug(
    request: pytest.FixtureRequest, reg_itf: str
) -> None:
    """Qualify each register transport through the full multi-clock lifecycle."""
    print(f"\n=== E2E · multi-clock scaffold · REG_ITF={reg_itf} ===", flush=True)

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_MULTI_TOP", "tri_stream_dsp")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    n_clocks = 3
    clock_domains = MULTI_CLOCK_DOMAINS
    clock_relationships = MULTI_CLOCK_RELATIONSHIPS

    with _preserve_project_settings(), _temporary_workspace(
        f"flexsoc-multiclock-{reg_itf}-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        slang_root, slang_top, slang_search = _slang_values(top, run)
        _run(
            (
                f"fx settings --reset TOP={top} RUN_TOP={top} "
                f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} REG_ITF={reg_itf} "
                f"CLOCK_DOMAINS={clock_domains} "
                f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx doctor --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _fetch_register_vendors(
            reg_itf, workspace=workspace, top=top, run_id=run_id
        )
        _run(
            f"fx setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx hjson --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx reg --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx doc --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx systemrdl --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx rtl_stub --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx top_from_core --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx flist --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx lint_slang_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx lint_verilator_suite --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx sdc --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx cdc_rdc --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx cdc_rdc --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id, required=False,
        )
        _assert_cdc_rdc_outputs(top, run)
        _run(
            f"fx model --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx tests_gen --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx tests --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx tb --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx cocotb --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_reset_driver_parity(run, top, multiclock=True)
        _run(
            (
                f"fx slang_hier --set {slang_root} "
                f"--set {slang_top} --set {slang_search} --workdir {workdir}"
            ),
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            (
                f"fx slang_ast --set {slang_root} "
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
            f"fx regression --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx coverage --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx coverage_detail --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

        _run(
            f"fx formal --setup --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _assert_design_formal_sources(top, run)
        _run(
            f"fx formal_csr_bmc --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_bmc --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_csr_prove --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_prove --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_csr_cover --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _run(
            f"fx formal_cover --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )

        if config.run_signoff:
            # sky130: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"fx pdk use sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx pdk info sky130 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx tb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cocotb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id, required=False,
            )
            _run(
                f"fx signoff --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sdf --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sta --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx power_estimate --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                _run_gls_all(
                    workspace=workspace, top=top, run_id=run_id,
                    workdir=workdir, config=config,
                )
                sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_mac_smoke_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="mac_smoke",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="mac_smoke", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_absdiff_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="absdiff",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="absdiff", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    sky130_post_syn / (
                        f"{top}_post_syn_energy_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="sky130", test="energy",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="energy", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run_implementation(
                workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
                pdk="sky130", platform="sky130hd", config=config,
            )
            _run(
                f"fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "sky130")

            # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
            _run(
                f"fx pdk use ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx settings --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx pdk info ihp-sg13g2 --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx tb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cocotb --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx syn --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx eqy --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id, required=False,
            )
            _run(
                f"fx signoff --setup --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sdf --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sta --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx power_estimate --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            if config.run_post_syn:
                _run_gls_all(
                    workspace=workspace, top=top, run_id=run_id,
                    workdir=workdir, config=config,
                )
                ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_smoke_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="smoke",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                )

                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_corners_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="corners",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="corners", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_1",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="random_seed_2",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_reconfig_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="reconfig",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="auto_toggle",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_mac_smoke_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="mac_smoke",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="mac_smoke", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_absdiff_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="absdiff",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="absdiff", backend=config.gls_backend, mode=config.gls_mode,
                )
                _assert_post_syn_report(
                    ihp_sg13g2_post_syn / (
                        f"{top}_post_syn_energy_{config.gls_backend}_"
                        f"{_gls_scenario(config.gls_mode)}.json"
                    ),
                    top=top, pdk="ihp-sg13g2", test="energy",
                    backend=config.gls_backend, mode=config.gls_mode,
                )
                _run_power_and_fusion(
                    workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                    test="energy", backend=config.gls_backend, mode=config.gls_mode,
                )
            _run_implementation(
                workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
                pdk="ihp-sg13g2", platform="ihp-sg13g2", config=config,
            )
            _run(
                f"fx manifest --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx manifest_show --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx metrics --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx check --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_technology_closure(top, run, "ihp-sg13g2")
        test_root = run / "dv" / "functional" / "tests"
        for test_name in (*SHARED_VECTOR_TESTS, *NCLOCK_DESIGN_TESTS):
            assert (test_root / test_name).is_dir()

@pytest.mark.e2e
def test_fx_cordic_ip_load_debug(request: pytest.FixtureRequest) -> None:
    """Load CORDIC once and qualify the unchanged IP on SKY130 and IHP."""
    print("\n=== E2E 3/5 · CORDIC payload ===", flush=True)

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_CORDIC_TOP", "cordic")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    reg_itf = "tlul"
    n_clocks = 1
    clock_domains = SINGLE_CLOCK_DOMAINS
    clock_relationships = ""
    target_opt = os.environ.get("FLEXSOC_E2E_TARGET_OPT", "delay1")

    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-cordic-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        saved_library = workspace / "saved_ip_library"
        saved_library_arg = shlex.quote(str(saved_library))
        _seed_saved_ip_library(saved_library, top)
        slang_root, slang_top, slang_search = _slang_values(top, run)
        with _protect_ip_sources("cordic") as source_snapshot:
            _run(
                (
                    f"fx settings --reset TOP={top} RUN_TOP={top} "
                    f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} REG_ITF={reg_itf} TARGET_OPT={target_opt} "
                    f"CLOCK_DOMAINS={clock_domains} "
                    f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx doctor --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _fetch_register_vendors(
                reg_itf, workspace=workspace, top=top, run_id=run_id
            )
            _run(
                f"fx ip_load --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_sources_match(top, run_id, workspace, source_snapshot)
            _assert_loaded_ip_tests(top, run_id, workspace)

            # Rebuild machine-owned collateral with the current package contract.
            _run(
                f"fx top_from_core --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx flist --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx lint_slang_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx lint_verilator_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sdc --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cdc_rdc --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cdc_rdc --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_cdc_rdc_outputs(top, run)

            _run(
                f"fx regmap_py --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx tests_gen --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            stale_tb_markers = _seed_stale_tb_scaffold(run)
            _run(
                f"fx tb --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cocotb --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_tb_scaffolds_recreated(stale_tb_markers, run, top)
            _assert_reset_driver_parity(run, top, multiclock=False)
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"fx tests --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"fx slang_hier --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"fx slang_ast --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_ast(top, run)
            _run(
                f"fx regression --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"fx coverage --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx coverage_detail --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

            if config.run_signoff:
                _assert_design_formal_sources(top, run)
                _run(
                    f"fx formal --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_csr_bmc --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_bmc --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_csr_prove --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_prove --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_csr_cover --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_cover --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )

                # sky130: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"fx pdk use sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx pdk info sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx tb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx cocotb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx signoff --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sdf --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sta --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx power_estimate --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    _run_gls_all(
                        workspace=workspace, top=top, run_id=run_id,
                        workdir=workdir, config=config,
                    )
                    sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_smoke_zero_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="smoke_zero",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke_zero", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_rotate_45deg_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="rotate_45deg",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rotate_45deg", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_quadrant_sweep_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="quadrant_sweep",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="quadrant_sweep", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_small_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="random_small",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_small", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_pre_impl_ip_branch(top, run, "sky130")
                _run(
                    (
                        f"fx ip_save --force --set IP_NAME={top} "
                        f"--set IP_LIBRARY_ROOT={saved_library_arg} --workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_saved_signoff_scripts(
                    saved_library, top, "sky130", activity_count=30
                )

                # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"fx pdk use ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx pdk info ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx tb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx cocotb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx signoff --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sdf --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sta --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx power_estimate --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    _run_gls_all(
                        workspace=workspace, top=top, run_id=run_id,
                        workdir=workdir, config=config,
                    )
                    ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_smoke_zero_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="smoke_zero",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke_zero", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_rotate_45deg_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="rotate_45deg",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rotate_45deg", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_quadrant_sweep_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="quadrant_sweep",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="quadrant_sweep", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_small_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_small",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_small", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_pre_impl_ip_branch(top, run, "ihp-sg13g2")
                _run(
                    (
                        f"fx ip_save --force --set IP_NAME={top} "
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
    print("\n=== E2E 4/5 · UART payload ===", flush=True)

    config = _e2e_config(request)
    top = os.environ.get("FLEXSOC_UART_TOP", "uart")
    run_id = os.environ.get("FLEXSOC_RUN_ID", DEFAULT_RUN_ID)
    host = os.environ.get("FLEXSOC_HOST", DEFAULT_HOST)
    reg_itf = "tlul"
    n_clocks = 1
    clock_domains = SINGLE_CLOCK_DOMAINS
    clock_relationships = ""
    target_opt = os.environ.get("FLEXSOC_E2E_TARGET_OPT", "delay1")

    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-uart-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        saved_library = workspace / "saved_ip_library"
        saved_library_arg = shlex.quote(str(saved_library))
        _seed_saved_ip_library(saved_library, top)
        slang_root, slang_top, slang_search = _slang_values(top, run)
        with _protect_ip_sources("uart") as source_snapshot:
            _run(
                (
                    f"fx settings --reset TOP={top} RUN_TOP={top} "
                    f"RUN_ID={run_id} HOST={host} N_CLOCKS={n_clocks} REG_ITF={reg_itf} TARGET_OPT={target_opt} "
                    f"CLOCK_DOMAINS={clock_domains} "
                    f"CLOCK_RELATIONSHIPS={clock_relationships} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx doctor --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _fetch_register_vendors(
                reg_itf, workspace=workspace, top=top, run_id=run_id
            )
            _run(
                f"fx ip_load --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_sources_match(top, run_id, workspace, source_snapshot)
            _assert_loaded_ip_tests(top, run_id, workspace)
            ihp_eqy = Path("signoff/ihp-sg13g2/equivalence/rtl_vs_syn/uart_rtl_vs_syn.eqy")
            assert _sha256(run / ihp_eqy) == _sha256(REPO_ROOT / "hw" / "ips" / top / ihp_eqy)

            # Rebuild machine-owned collateral with the current package contract.
            _run(
                f"fx top_from_core --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx flist --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx lint_slang_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx lint_verilator_suite --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx sdc --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cdc_rdc --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cdc_rdc --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_cdc_rdc_outputs(top, run)

            _run(
                f"fx regmap_py --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx tests_gen --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            stale_tb_markers = _seed_stale_tb_scaffold(run)
            _run(
                f"fx tb --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx cocotb --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_tb_scaffolds_recreated(stale_tb_markers, run, top)
            _assert_reset_driver_parity(run, top, multiclock=False)
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"fx tests --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"fx slang_hier --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                (
                    f"fx slang_ast --set {slang_root} "
                    f"--set {slang_top} --set {slang_search} --workdir {workdir}"
                ),
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_ast(top, run)
            _run(
                f"fx regression --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_loaded_ip_tests(top, run_id, workspace)
            _run(
                f"fx coverage --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _run(
                f"fx coverage_detail --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
            _assert_coverage_outputs(run / "dv" / "functional" / "coverage")

            if config.run_signoff:
                _assert_design_formal_sources(top, run)
                _run(
                    f"fx formal --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_csr_bmc --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_bmc --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_csr_prove --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_prove --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_csr_cover --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx formal_cover --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )

                # sky130: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"fx pdk use sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx pdk info sky130 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx tb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx cocotb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx signoff --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sdf --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sta --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx power_estimate --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    _run_gls_all(
                        workspace=workspace, top=top, run_id=run_id,
                        workdir=workdir, config=config,
                    )
                    sky130_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "sky130"
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_line_loopback_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="line_loopback",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="line_loopback", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_rx_fifo_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="rx_fifo",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rx_fifo", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_noise_filter_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="noise_filter",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="noise_filter", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        sky130_post_syn / (
                            f"{top}_post_syn_parity_reconfig_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="sky130", test="parity_reconfig",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="parity_reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_pre_impl_ip_branch(top, run, "sky130")
                _run(
                    (
                        f"fx ip_save --force --set IP_NAME={top} "
                        f"--set IP_LIBRARY_ROOT={saved_library_arg} --workdir {workdir}"
                    ),
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_saved_signoff_scripts(
                    saved_library, top, "sky130", activity_count=30
                )

                # ihp-sg13g2: rerun only technology-bound synthesis/sign-off stages.
                _run(
                    f"fx pdk use ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx settings --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx pdk info ihp-sg13g2 --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx tb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx cocotb --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx syn --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx eqy --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx signoff --setup --force --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sdf --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx sta --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx power_estimate --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                if config.run_post_syn:
                    _run_gls_all(
                        workspace=workspace, top=top, run_id=run_id,
                        workdir=workdir, config=config,
                    )
                    ihp_sg13g2_post_syn = run / "dv" / "functional" / "sim" / "post_syn" / "ihp-sg13g2"
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_smoke_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="smoke",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="smoke", backend=config.gls_backend, mode=config.gls_mode,
                    )

                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_corners_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="corners",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="corners", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_1_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_1",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_1", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_random_seed_2_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="random_seed_2",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="random_seed_2", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_reconfig_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="reconfig",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_auto_toggle_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="auto_toggle",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="auto_toggle", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_line_loopback_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="line_loopback",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="line_loopback", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_rx_fifo_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="rx_fifo",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="rx_fifo", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_noise_filter_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="noise_filter",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="noise_filter", backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _assert_post_syn_report(
                        ihp_sg13g2_post_syn / (
                            f"{top}_post_syn_parity_reconfig_{config.gls_backend}_"
                            f"{_gls_scenario(config.gls_mode)}.json"
                        ),
                        top=top, pdk="ihp-sg13g2", test="parity_reconfig",
                        backend=config.gls_backend, mode=config.gls_mode,
                    )
                    _run_power_and_fusion(
                        workspace=workspace, top=top, run_id=run_id, workdir=workdir,
                        test="parity_reconfig", backend=config.gls_backend, mode=config.gls_mode,
                    )
                _run(
                    f"fx manifest --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx manifest_show --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx metrics --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _run(
                    f"fx check --workdir {workdir}",
                    workspace=workspace, top=top, run_id=run_id,
                )
                _assert_pre_impl_ip_branch(top, run, "ihp-sg13g2")
                _run(
                    (
                        f"fx ip_save --force --set IP_NAME={top} "
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
def test_fx_provenance_lifecycle_debug(request: pytest.FixtureRequest) -> None:
    """Qualify modify/block/validate/consume/restore across setup provenance."""

    print("\n=== E2E 5/5 · setup provenance lifecycle ===", flush=True)

    config = _e2e_config(request)
    top = "test"
    run_id = DEFAULT_RUN_ID
    with _preserve_project_settings(), _temporary_workspace(
        "flexsoc-provenance-e2e-", _e2e_root(request)
    ) as workspace:
        workdir = shlex.quote(str(workspace))
        run = workspace / "runs" / top / run_id
        for command in (
            f"fx settings --reset TOP={top} RUN_TOP={top} RUN_ID={run_id} "
            f"HOST={DEFAULT_HOST} N_CLOCKS=1 CLOCK_DOMAINS={SINGLE_CLOCK_DOMAINS} "
            f"CLOCK_RELATIONSHIPS= --workdir {workdir}",
            f"fx setup --force --workdir {workdir}",
            f"fx hjson --force --workdir {workdir}",
            f"fx reg --force --workdir {workdir}",
            f"fx rtl_stub --force --workdir {workdir}",
            f"fx top_from_core --force --workdir {workdir}",
            f"fx flist --force --workdir {workdir}",
            f"fx sdc --setup --force --workdir {workdir}",
            f"fx model --setup --force --workdir {workdir}",
            f"fx tests_gen --workdir {workdir}",
            f"fx pdk use sky130 --workdir {workdir}",
        ):
            _run(command, workspace=workspace, top=top, run_id=run_id)

        cases = (
            (
                "tb.setup", "tb",
                run / "dv/functional/tb/sv" / f"{top}_tb.sv",
                f"fx compile --set TEST_NAME=smoke --workdir {workdir}",
                True,
            ),
            (
                "cocotb.setup", "cocotb",
                run / "dv/functional/tb/cocotb" / f"{top}_tb.py",
                f"fx cocotb --set TEST_NAME=smoke --workdir {workdir}",
                True,
            ),
            (
                "cdc_rdc.setup", "cdc_rdc",
                run / "analysis/cdc_rdc/extract.ys",
                f"fx cdc_rdc --workdir {workdir}",
                True,
            ),
        )
        for _, keyword, _, _, _ in cases:
            _run(
                f"fx {keyword} --setup --force --workdir {workdir}",
                workspace=workspace, top=top, run_id=run_id,
            )
        for stage, _, artifact, command, required in cases:
            _exercise_stage_override(
                workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
                stage=stage, artifact=artifact, command=command, required=required,
            )

        _run(
            f"fx status --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )

        if not config.run_signoff:
            return

        _run(
            f"fx formal --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        formal_cases = (
            (
                "formal.csr_prove.setup",
                run / "dv/formal/runs/csr/prove" / f"{top}_csr_prove.sby",
                f"fx formal_csr_bmc --workdir {workdir}",
            ),
            (
                "formal.prove.setup",
                run / "dv/formal/runs/properties/prove" / f"{top}_prove.sby",
                f"fx formal_bmc --workdir {workdir}",
            ),
            (
                "formal.csr_cover.setup",
                run / "dv/formal/runs/csr/cover" / f"{top}_csr_cover.sby",
                f"fx formal_csr_cover --workdir {workdir}",
            ),
            (
                "formal.cover.setup",
                run / "dv/formal/runs/properties/cover" / f"{top}_cover.sby",
                f"fx formal_cover --workdir {workdir}",
            ),
        )
        for stage, artifact, command in formal_cases:
            _exercise_stage_override(
                workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
                stage=stage, artifact=artifact, command=command,
            )

        _run(
            f"fx syn --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _exercise_stage_override(
            workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
            stage="syn.setup", artifact=run / "syn/sky130/synth_sv.ys",
            command=f"fx syn --workdir {workdir}",
        )

        _run(
            f"fx eqy --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _exercise_stage_override(
            workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
            stage="eqy.setup",
            artifact=run / "signoff/sky130/equivalence/rtl_vs_syn" / f"{top}_rtl_vs_syn.eqy",
            command=f"fx eqy --workdir {workdir}",
            required=False,
        )

        _run(
            f"fx signoff --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _exercise_stage_override(
            workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
            stage="signoff.setup", artifact=run / "signoff/sky130/sta/sta.tcl",
            command=f"fx sdf --workdir {workdir}",
        )

        if not config.run_pnr:
            return
        assert config.ors is not None
        ors = shlex.quote(f"ORS={config.ors}")
        _run(
            f"fx pnr --setup --force --set {ors} --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _exercise_stage_override(
            workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
            stage="pnr.setup", artifact=run / "impl/sky130/config.mk",
            command=f"fx pnr --set {ors} --workdir {workdir}",
        )
        _run(
            f"fx signoff_post_pnr --setup --force --workdir {workdir}",
            workspace=workspace, top=top, run_id=run_id,
        )
        _exercise_stage_override(
            workspace=workspace, top=top, run_id=run_id, run=run, workdir=workdir,
            stage="signoff_post_pnr.setup",
            artifact=run / "signoff/sky130/post_pnr/sdf/write_sdf.tcl",
            command=f"fx sdf_post_pnr --workdir {workdir}",
        )
