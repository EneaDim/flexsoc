"""Generate and execute FlexSoC OpenSTA sign-off analyses.

The Makefile remains the public orchestrator.  This module resolves technology
inputs, writes self-contained Tcl, executes OpenSTA, and validates the produced
reports for STA, vectorless power estimation, activity-based power, and
workload-aware timing/power fusion.  EQY lives in :mod:`setup_eqy`.
"""

from __future__ import annotations

import argparse
import csv
import json
import os
import re
import shlex
import shutil
import subprocess
import sys
from dataclasses import dataclass, replace
from pathlib import Path
from typing import Any, Mapping, Sequence

from flexsoc.backend.output import print_script
from flexsoc.run_layout import layout_from_values

SDF_MODES = ("min", "typ", "max")
ANALYSES = ("sta", "power_estimate", "power_analysis", "fusion_analysis")
POWER_RE = re.compile(
    r"^\s*Total\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)",
    re.MULTILINE,
)
ACTIVITY_RE = re.compile(r"Annotated\s+(\d+)\s+(?:pin\s+)?activities", re.IGNORECASE)


@dataclass(frozen=True, slots=True)
class ActivitySpec:
    """One test/backend/timing trace used for workload-dependent sign-off."""

    top: str
    pdk: str
    test: str
    backend: str
    mode: str
    report: Path
    wave: Path

    @property
    def stem(self) -> str:
        return f"{self.top}_{self.pdk}_{self.test}_{self.backend}_{self.mode}"

    @property
    def workload(self) -> str:
        return f"{self.test}_{self.backend}_{self.mode}"


@dataclass(frozen=True, slots=True)
class SignoffContext:
    """Resolved inputs for one concrete OpenSTA script."""

    analysis: str
    design: str
    variant: str
    pdk: str
    stage: str
    corner: str
    mode: str
    workload: str
    top: str
    liberty: Path
    macro_liberties: tuple[Path, ...]
    netlist: Path
    sdc: Path
    report_dir: Path
    spef: Path | None = None
    activity_file: Path | None = None
    activity_scope: str = ""
    gls_report: Path | None = None
    estimated_activity: float = 0.1
    estimated_duty: float = 0.5
    global_activity: bool = False
    endpoint_group_limit: int = 10000
    endpoint_path_limit: int = 10
    near_critical_setup: float = 0.200
    near_critical_hold: float = 0.100
    high_fanout_threshold: int = 16
    power_top_instances: int = 200
    power_paths_per_instance: int = 2
    power_top_paths: int = 100


def liberty_corner(path: Path) -> str:
    """Infer ``ss``, ``tt`` or ``ff`` from a Liberty filename."""

    name = path.name.lower()
    aliases = {
        "ss": ("ss", "slow", "worst"),
        "tt": ("tt", "typ", "typical"),
        "ff": ("ff", "fast", "best"),
    }
    for corner, tokens in aliases.items():
        for token in tokens:
            if (
                f"__{token}_" in name
                or f"_{token}_" in name
                or name.startswith(f"{token}_")
                or name.startswith(f"nom_{token}_")
            ):
                return corner
    return path.stem


def _quote(path: Path | str) -> str:
    """Return a Tcl brace-quoted value."""

    return "{" + str(path).replace("}", "\\}") + "}"


def _write(path: Path, text: str) -> Path:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text.rstrip() + "\n", encoding="utf-8")
    return path


def _require_file(path: Path, label: str) -> Path:
    path = path.expanduser().resolve()
    if not path.is_file():
        raise ValueError(f"missing {label}: {path}")
    return path


def _optional_file(path: Path | None, label: str) -> Path | None:
    if path is None:
        return None
    return _require_file(path, label)
def _split(value: str | None) -> tuple[str, ...]:
    return tuple(item.strip() for item in str(value or "").replace(",", " ").split() if item.strip())


def _truth(value: str | None) -> bool:
    return str(value or "").strip().lower() in {"1", "true", "yes", "on"}


def _live() -> bool:
    return _truth(os.environ.get("FLEXSOC_LIVE"))


def _paths(value: str | None) -> tuple[Path, ...]:
    return tuple(Path(item).expanduser().resolve() for item in _split(value))


def _liberties(values: Mapping[str, str]) -> dict[str, Path]:
    paths = [path for path in _paths(values.get("LIBS")) if path.is_file()]
    lib_syn = Path(values["LIB_SYN"]).expanduser().resolve() if values.get("LIB_SYN") else None
    if lib_syn and lib_syn.is_file() and lib_syn not in paths:
        paths.append(lib_syn)
    corners: dict[str, Path] = {}
    for path in paths:
        corner = liberty_corner(path)
        if corner in {"ss", "tt", "ff"}:
            corners.setdefault(corner, path)
    if not corners:
        raise ValueError("no ss/tt/ff Liberty views resolved for OpenSTA sign-off")
    return {corner: corners[corner] for corner in ("ss", "tt", "ff") if corner in corners}


def _load_json(path: Path) -> dict[str, Any]:
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as exc:
        raise ValueError(f"invalid JSON artifact {path}: {exc}") from exc
    if not isinstance(data, dict):
        raise ValueError(f"invalid JSON object: {path}")
    return data


def _selector(values: Mapping[str, str], plural: str, singular: str, default: str) -> tuple[str, ...]:
    raw = values.get(plural) or values.get(singular) or default
    return _split(raw)


def _post_syn_report(
    project_root: Path,
    values: Mapping[str, str],
    *,
    test: str,
    backend: str,
    mode: str,
) -> Path:
    layout = layout_from_values(project_root, values)
    top = values.get("TOP", "test")
    signoff_stage = values.get("SIGNOFF_STAGE", "post_syn")
    report_stage = "post_pnr" if signoff_stage == "post_route" else "post_syn"
    stage_dir = layout.post_pnr_sim_dir if report_stage == "post_pnr" else layout.post_syn_sim_dir
    return stage_dir / f"{top}_{report_stage}_{test}_{backend}_{mode}.json"


def _qualified_spec(
    project_root: Path,
    values: Mapping[str, str],
    *,
    test: str,
    backend: str,
    mode: str,
) -> ActivitySpec:
    """Resolve one successful SDF-backed GLS report without a matrix manifest."""

    if mode not in SDF_MODES:
        raise ValueError(
            f"workload sign-off requires back-annotated GLS mode min/typ/max, got {mode!r}"
        )
    report = _post_syn_report(project_root, values, test=test, backend=backend, mode=mode)
    if not report.is_file():
        raise ValueError(
            f"GLS report not found: {report}; run the matching GLS simulation with TEST_NAME={test} "
            f"--set GLS_BACKEND={backend} --set TIMING_MODE={mode}` first"
        )
    payload = _load_json(report)
    top = values.get("TOP", "test")
    pdk = values.get("PDK", "sky130")
    report_stage = "post_pnr" if values.get("SIGNOFF_STAGE", "post_syn") == "post_route" else "post_syn"
    expected = {
        "stage": report_stage,
        "top": top,
        "pdk": pdk,
        "test_name": test,
        "backend": backend,
        "timing_mode": mode,
    }
    mismatches = {
        key: (payload.get(key), value)
        for key, value in expected.items()
        if payload.get(key) != value
    }
    if mismatches:
        detail = ", ".join(
            f"{key}={actual!r} expected {wanted!r}"
            for key, (actual, wanted) in mismatches.items()
        )
        raise ValueError(f"GLS report metadata mismatch in {report}: {detail}")
    if payload.get("status") != "pass":
        raise ValueError(f"GLS source report is not PASS: {report}")
    annotation = payload.get("annotation")
    if not isinstance(annotation, dict) or annotation.get("requested_marker") is not True:
        raise ValueError(f"GLS source lacks confirmed $sdf_annotate evidence: {report}")
    raw_wave = payload.get("wave")
    if not isinstance(raw_wave, str) or not raw_wave.strip():
        raise ValueError(f"GLS source report does not identify a waveform: {report}")
    wave = Path(raw_wave).expanduser()
    if not wave.is_absolute():
        wave = (report.parent / wave).resolve()
    else:
        wave = wave.resolve()
    if not wave.is_file() or wave.stat().st_size == 0:
        raise ValueError(f"GLS activity waveform is missing or empty: {wave}")
    return ActivitySpec(top, pdk, test, backend, mode, report.resolve(), wave)


def _available_gls(
    project_root: Path, values: Mapping[str, str]
) -> tuple[tuple[str, str, str], ...]:
    """Discover direct post-synthesis reports as ``(test, backend, mode)`` rows."""

    layout = layout_from_values(project_root, values)
    top = values.get("TOP", "test")
    report_stage = "post_pnr" if values.get("SIGNOFF_STAGE", "post_syn") == "post_route" else "post_syn"
    stage_dir = layout.post_pnr_sim_dir if report_stage == "post_pnr" else layout.post_syn_sim_dir
    prefix = f"{top}_{report_stage}_"
    rows: set[tuple[str, str, str]] = set()
    for report in stage_dir.glob(f"{prefix}*.json"):
        tail = report.stem[len(prefix):]
        for mode in SDF_MODES:
            for backend in ("sv", "cocotb"):
                suffix = f"_{backend}_{mode}"
                if tail.endswith(suffix) and tail[: -len(suffix)]:
                    rows.add((tail[: -len(suffix)], backend, mode))
    mode_order = {mode: index for index, mode in enumerate(SDF_MODES)}
    return tuple(sorted(rows, key=lambda row: (mode_order[row[2]], row[0], row[1])))


def _one(values: tuple[str, ...], label: str) -> str:
    if len(values) != 1 or values == ("all",):
        raise ValueError(f"{label} must select exactly one value")
    return values[0]


def discover_specs(
    action: str,
    values: Mapping[str, str],
    project_root: Path | None = None,
) -> tuple[ActivitySpec, ...]:
    """Resolve one GLS trace or discover all direct traces matching the selectors."""

    root = (project_root or Path.cwd()).expanduser().resolve()
    tests = _selector(
        values,
        "POWER_TEST_NAMES",
        "POWER_TEST_NAME",
        "all" if action == "all" else values.get("TEST_NAME", "smoke"),
    )
    backends = _selector(
        values,
        "POWER_GLS_BACKENDS",
        "POWER_GLS_BACKEND",
        "all" if action == "all" else values.get("GLS_BACKEND", "sv"),
    )
    modes = _selector(
        values,
        "POWER_TIMING_MODES",
        "POWER_TIMING_MODE",
        "all" if action == "all" else values.get("TIMING_MODE", "typ"),
    )
    if action == "single":
        return (
            _qualified_spec(
                root,
                values,
                test=_one(tests, "POWER_TEST_NAME"),
                backend=_one(backends, "POWER_GLS_BACKEND"),
                mode=_one(modes, "POWER_TIMING_MODE"),
            ),
        )

    available = _available_gls(root, values)
    if not available:
        layout = layout_from_values(root, values)
        raise ValueError(f"no direct SDF-backed GLS reports found for SIGNOFF_STAGE={values.get('SIGNOFF_STAGE', 'post_syn')}")
    selected = tuple(
        row
        for row in available
        if (tests == ("all",) or row[0] in tests)
        and (backends == ("all",) or row[1] in backends)
        and (modes == ("all",) or row[2] in modes)
    )
    available_columns = (
        {row[0] for row in available},
        {row[1] for row in available},
        {row[2] for row in available},
    )
    missing = {
        label: sorted(set(requested) - present)
        for label, requested, present in (
            ("tests", tests, available_columns[0]),
            ("backends", backends, available_columns[1]),
            ("modes", modes, available_columns[2]),
        )
        if requested != ("all",) and set(requested) - present
    }
    if missing:
        raise ValueError(f"requested GLS reports are missing: {missing}")
    if not selected:
        raise ValueError(
            "no direct GLS reports match power selectors: "
            f"tests={tests} backends={backends} modes={modes}"
        )
    return tuple(
        _qualified_spec(root, values, test=test, backend=backend, mode=mode)
        for test, backend, mode in selected
    )


def _valid_vcd(path: Path) -> bool:
    """Return true when *path* looks like a non-empty VCD capture."""

    if not path.is_file() or path.stat().st_size == 0:
        return False
    limit = 8 * 1024 * 1024
    with path.open("rb") as stream:
        header = stream.read(limit)
    return b"$enddefinitions" in header and (b"$scope" in header or b"$var" in header)


def _vcd_scopes(path: Path) -> tuple[str, ...]:
    """Return VCD hierarchy scopes using OpenSTA's slash separator."""

    stack: list[str] = []
    scopes: list[str] = []
    with path.open("r", encoding="utf-8", errors="replace") as stream:
        for line in stream:
            stripped = line.strip()
            if stripped.startswith("$scope "):
                fields = stripped.split()
                if len(fields) >= 4 and fields[-1] == "$end":
                    stack.append(fields[2])
                    scopes.append("/".join(stack))
            elif stripped.startswith("$upscope"):
                if stack:
                    stack.pop()
            elif "$enddefinitions" in stripped:
                break
    return tuple(dict.fromkeys(scopes))


def _resolve_vcd_scope(
    vcd: Path, *, requested: str | None, top: str, dut_instance: str = "auto"
) -> tuple[str, tuple[str, ...]]:
    """Resolve an explicit or generated DUT scope against the VCD header.

    Generated FlexSoC testbenches use two DUT naming conventions: the canonical
    single-clock scaffold instantiates ``u_<TOP>`` while N-clock and cocotb
    wrappers use ``u_dut``.  Automatic scope resolution understands both and
    treats ``POWER_DUT_INSTANCE`` as an optional hint rather than a fragile
    hard-coded requirement.
    """

    scopes = _vcd_scopes(vcd)
    if not scopes:
        raise ValueError(f"VCD contains no hierarchy scopes: {vcd}")

    raw = str(requested or "auto").strip() or "auto"
    if raw.lower() != "auto":
        candidates = [raw]
        if "/" not in raw and "." in raw:
            candidates.append(raw.replace(".", "/"))
        for candidate in dict.fromkeys(candidates):
            if candidate in scopes:
                return candidate, scopes
        preview = ", ".join(scopes[:12])
        suffix = " ..." if len(scopes) > 12 else ""
        raise ValueError(
            f"POWER_VCD_SCOPE={raw!r} is not present in {vcd}; "
            f"OpenSTA scope levels use '/'; available scopes: {preview}{suffix}"
        )

    hint = str(dut_instance or "auto").strip() or "auto"
    leaves: list[str] = []
    if hint.lower() != "auto":
        leaves.append(hint)
    leaves.extend((f"u_{top}", "u_dut", top, "dut"))
    leaf_candidates = tuple(dict.fromkeys(leaves))

    roots = [f"{top}_tb", "test_tb"]
    roots.extend(scope for scope in scopes if "/" not in scope and scope.endswith("_tb"))
    root_candidates = tuple(dict.fromkeys(roots))

    for root in root_candidates:
        for leaf in leaf_candidates:
            candidate = f"{root}/{leaf}"
            if candidate in scopes:
                return candidate, scopes

    for leaf in leaf_candidates:
        leaf_matches = tuple(
            scope for scope in scopes if scope.rsplit("/", 1)[-1] == leaf
        )
        if len(leaf_matches) == 1:
            return leaf_matches[0], scopes

    preview = ", ".join(scopes[:12])
    suffix = " ..." if len(scopes) > 12 else ""
    raise ValueError(
        f"cannot resolve DUT scope automatically in {vcd}; "
        f"tried generated instance names {', '.join(leaf_candidates)}; "
        f"set POWER_VCD_SCOPE with '/' separators or POWER_DUT_INSTANCE; "
        f"available scopes: {preview}{suffix}"
    )


def _convert_fst(
    *, executable: Path, source: Path, output: Path, log: Path
) -> str:
    """Convert one FST using the documented interface with a stdout fallback."""

    output.unlink(missing_ok=True)
    log.parent.mkdir(parents=True, exist_ok=True)
    attempts: list[tuple[str, int, int]] = []

    command = [str(executable), "-f", str(source), "-o", str(output)]
    with log.open("w", encoding="utf-8") as stream:
        stream.write("[fst2vcd] command=" + shlex.join(command) + "\n")
        done = subprocess.run(
            command,
            check=False,
            text=True,
            stdout=stream,
            stderr=subprocess.STDOUT,
        )
        size = output.stat().st_size if output.is_file() else 0
        stream.write(f"[fst2vcd] returncode={done.returncode} output_bytes={size}\n")
    attempts.append(("named-output", done.returncode, size))
    if done.returncode == 0 and _valid_vcd(output):
        return "named-output"

    output.unlink(missing_ok=True)
    command = [str(executable), str(source)]
    with log.open("a", encoding="utf-8") as stream:
        stream.write("[fst2vcd] retry=stdout command=" + shlex.join(command) + "\n")
        with output.open("wb") as capture:
            done = subprocess.run(
                command,
                check=False,
                stdout=capture,
                stderr=stream,
            )
        size = output.stat().st_size if output.is_file() else 0
        stream.write(f"[fst2vcd] returncode={done.returncode} output_bytes={size}\n")
    attempts.append(("stdout", done.returncode, size))
    if done.returncode == 0 and _valid_vcd(output):
        return "stdout"

    detail = ", ".join(
        f"{method}:rc={returncode}:bytes={size}"
        for method, returncode, size in attempts
    )
    raise ValueError(f"fst2vcd conversion failed ({detail}); log: {log}")


def _activity_vcd(
    spec: ActivitySpec, values: Mapping[str, str], capture_dir: Path
) -> tuple[Path, Path | None, str]:
    """Return a validated VCD, converting an FST deterministically when required."""

    if spec.wave.suffix.lower() == ".vcd":
        if not _valid_vcd(spec.wave):
            raise ValueError(f"qualified activity VCD is invalid: {spec.wave}")
        return spec.wave, None, "native-vcd"
    if spec.wave.suffix.lower() != ".fst":
        raise ValueError(f"unsupported activity waveform format: {spec.wave}")
    converter = values.get("FST2VCD", "fst2vcd")
    executable = shutil.which(converter) if not Path(converter).is_absolute() else converter
    if not executable or not Path(executable).is_file():
        raise ValueError(
            "required tool fst2vcd was not found; run fx deps or install GTKWave tools"
        )
    capture_dir.mkdir(parents=True, exist_ok=True)
    output = capture_dir / f"{spec.stem}.vcd"
    log = capture_dir / f"{spec.stem}_fst2vcd.log"
    method = _convert_fst(
        executable=Path(executable), source=spec.wave, output=output, log=log
    )
    return output, log, method


def _run_sta(command: Sequence[str], *, cwd: Path, log: Path) -> int:
    log.parent.mkdir(parents=True, exist_ok=True)
    live = _live()
    if live:
        print("$ " + shlex.join(command), flush=True)
    with log.open("w", encoding="utf-8") as stream:
        proc = subprocess.Popen(
            list(command), cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True
        )
        assert proc.stdout is not None
        for line in proc.stdout:
            stream.write(line)
            if live:
                sys.stdout.write(line)
        rc = proc.wait()
    return rc


def _power_values(text: str) -> dict[str, float]:
    match = POWER_RE.search(text)
    if not match:
        return {}
    internal, switching, leakage, total = (float(value) for value in match.groups())
    return {
        "internal_w": internal,
        "switching_w": switching,
        "leakage_w": leakage,
        "total_w": total,
    }


def _activity_count(text: str) -> int | None:
    """Return OpenSTA's annotated-activity count when the version reports one."""

    match = ACTIVITY_RE.search(text)
    return int(match.group(1)) if match else None


def _header(ctx: SignoffContext, limitations: Sequence[str]) -> str:
    macros = ", ".join(str(path) for path in ctx.macro_liberties) or "not used"
    lines = [
        "# =============================================================================",
        "# AUTO-GENERATED FLEXSOC OPENSTA ANALYSIS",
        "#",
        f"# Analysis : {ctx.analysis}",
        f"# Design   : {ctx.design}",
        f"# Variant  : {ctx.variant}",
        f"# PDK      : {ctx.pdk}",
        f"# Stage    : {ctx.stage}",
        f"# Corner   : {ctx.corner}",
        f"# Mode     : {ctx.mode or 'not applicable'}",
        f"# Workload : {ctx.workload or 'not applicable'}",
        f"# Top      : {ctx.top}",
        "#",
        "# Inputs:",
        f"#   Liberty       : {ctx.liberty}",
        f"#   Macro Liberty : {macros}",
        f"#   Netlist       : {ctx.netlist}",
        f"#   SDC           : {ctx.sdc}",
        f"#   SPEF          : {ctx.spef or 'not used'}",
        f"#   VCD or SAIF   : {ctx.activity_file or 'not used'}",
        f"#   Activity scope: {ctx.activity_scope or 'not used'}",
        f"#   GLS report    : {ctx.gls_report or 'not used'}",
        f"#   Report dir    : {ctx.report_dir}",
        "#",
        "# Limitations:",
        *[f"#   - {item}" for item in limitations],
        "#",
        "# This file is generated by FlexSoC. Do not edit it in place.",
        "# =============================================================================",
    ]
    return "\n".join(lines)


def _common_init(ctx: SignoffContext, *, activity: bool) -> str:
    macro_list = " ".join(_quote(path) for path in ctx.macro_liberties)
    lines = [
        "",
        "# -----------------------------------------------------------------------------",
        "# Runtime validation and common OpenSTA initialization",
        "#",
        "# Each required input is checked before OpenSTA reads it.  The resulting linked",
        "# network associates netlist instances and pins with Liberty timing arcs,",
        "# sequential checks and power models.  A link failure normally identifies a",
        "# missing standard-cell or macro Liberty view.",
        "# -----------------------------------------------------------------------------",
        "proc flexsoc_require_readable {label path} {",
        "  if {![file exists $path] || ![file readable $path]} {",
        "    puts stderr \"ERROR: missing or unreadable $label: $path\"",
        "    exit 2",
        "  }",
        "}",
        f"set report_dir {_quote(ctx.report_dir)}",
        "file mkdir $report_dir",
        f"set liberty {_quote(ctx.liberty)}",
        f"set macro_liberties {{{macro_list}}}",
        f"set netlist {_quote(ctx.netlist)}",
        f"set sdc {_quote(ctx.sdc)}",
        f"set spef {_quote(ctx.spef) if ctx.spef else '{}'}",
        f"set top {_quote(ctx.top)}",
        f"set stage {_quote(ctx.stage)}",
        "flexsoc_require_readable \"standard-cell Liberty\" $liberty",
        "flexsoc_require_readable \"gate-level netlist\" $netlist",
        "flexsoc_require_readable \"SDC constraints\" $sdc",
        "foreach macro_lib $macro_liberties {flexsoc_require_readable \"macro Liberty\" $macro_lib}",
        "if {$spef ne \"\"} {flexsoc_require_readable \"SPEF parasitics\" $spef}",
        "",
        'puts "=== Step 1/7: Read Liberty ==="',
        'puts "liberty=$liberty"',
        "read_liberty $liberty",
        "foreach macro_lib $macro_liberties {",
        '  puts "macro_liberty=$macro_lib"',
        "  read_liberty $macro_lib",
        "}",
        "",
        'puts "=== Step 2/7: Read netlist ==="',
        'puts "netlist=$netlist"',
        "read_verilog $netlist",
        "",
        'puts "=== Step 3/7: Link design ==="',
        'puts "top=$top"',
        "link_design $top",
        "",
        'puts "=== Step 4/7: Read SDC ==="',
        'puts "sdc=$sdc"',
        "read_sdc $sdc",
        "",
        'puts "=== Step 5/7: Read parasitics / establish clock model ==="',
        "if {$spef ne \"\"} {",
        '  puts "spef=$spef"',
        "  read_spef $spef",
        "} else {",
        '  puts "spef=not_used"',
        "}",
        "if {$stage eq \"post_route\"} {",
        "  set clocks [get_clocks *]",
        "  if {[llength $clocks] > 0} {set_propagated_clock $clocks}",
        '  puts "clock_model=propagated"',
        "} else {",
        '  puts "clock_model=ideal post_synthesis"',
        "}",
        "sta::redirect_file_begin [file join $report_dir units.rpt]",
        "report_units",
        "sta::redirect_file_end",
        "",
        'puts "=== Step 6/7: Validate timing setup ==="',
        "check_setup -verbose > [file join $report_dir check_setup.rpt]",
    ]
    if activity:
        lines += [
            "",
            'puts "=== Step 7/7: Read activity ==="',
            f"set activity_file {_quote(ctx.activity_file) if ctx.activity_file else '{}'}",
            f"set activity_scope {_quote(ctx.activity_scope)}",
            "flexsoc_require_readable \"activity VCD/SAIF\" $activity_file",
            'puts "activity_file=$activity_file"',
            'puts "activity_scope=$activity_scope"',
            "set activity_ext [string tolower [file extension $activity_file]]",
            "if {$activity_ext eq \".saif\"} {",
            "  read_saif -scope $activity_scope $activity_file",
            "} elseif {$activity_ext eq \".vcd\"} {",
            "  read_vcd -scope $activity_scope $activity_file",
            "} else {",
            '  puts stderr "ERROR: activity file must be VCD or SAIF: $activity_file"',
            "  exit 2",
            "}",
        ]
    else:
        lines += ["", 'puts "=== Step 7/7: Analysis-specific reporting ==="']
    return "\n".join(lines)


def render_sta_tcl(ctx: SignoffContext) -> str:
    delay_type = "min" if ctx.mode == "hold" else "max"
    threshold = ctx.near_critical_hold if ctx.mode == "hold" else ctx.near_critical_setup
    limitations = (
        "Endpoint coverage reports the worst selected path per endpoint; it is not an enumeration of every topological path.",
        "Post-synthesis capacitance excludes routed parasitics unless an explicit SPEF is supplied.",
    )
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=False),
            "",
            "# -----------------------------------------------------------------------------",
            "# Static timing reports",
            "#",
            "# Setup analysis uses max delay; hold analysis uses min delay.  Violating,",
            "# near-critical and unconstrained paths are kept separate so a missing",
            "# constraint cannot be mistaken for a valid timing path.",
            "# -----------------------------------------------------------------------------",
            f"set delay_type {delay_type}",
            f"set endpoint_group_limit {ctx.endpoint_group_limit}",
            f"set endpoint_path_limit {ctx.endpoint_path_limit}",
            f"set near_critical_limit {threshold:.6f}",
            f'set summary [file join $report_dir summary.rpt]',
            "set fp [open $summary w]",
            f'puts $fp "analysis_type=sta"',
            f'puts $fp "design={ctx.design}"',
            f'puts $fp "variant={ctx.variant}"',
            f'puts $fp "pdk={ctx.pdk}"',
            f'puts $fp "stage={ctx.stage}"',
            f'puts $fp "corner={ctx.corner}"',
            f'puts $fp "mode={ctx.mode}"',
            f'puts $fp "top={ctx.top}"',
            'puts $fp "liberty=$liberty"',
            'puts $fp "macro_liberty=$macro_liberties"',
            'puts $fp "netlist=$netlist"',
            'puts $fp "sdc=$sdc"',
            'puts $fp "spef=$spef"',
            'puts $fp "clock_model=[expr {$stage eq \"post_route\" ? \"propagated\" : \"ideal\"}]"',
            "close $fp",
            "sta::redirect_file_append_begin $summary",
            "report_units",
            "sta::redirect_file_end",
            f"report_wns -{delay_type} >> $summary",
            f"report_tns -{delay_type} >> $summary",
            "check_setup -verbose > [file join $report_dir check_setup.rpt]",
            "check_setup -verbose >> $summary",
            "",
            "report_checks -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count 1 -sort_by_slack -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6 > [file join $report_dir endpoint_coverage.rpt]",
            "report_checks -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count $endpoint_path_limit -unique_paths_to_endpoint -sort_by_slack -slack_max 0.0 -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6 > [file join $report_dir violating.rpt]",
            "report_checks -path_delay $delay_type -group_path_count 3000 -endpoint_path_count 3 -unique_paths_to_endpoint -sort_by_slack -slack_min 0.0 -slack_max $near_critical_limit -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6 > [file join $report_dir near_critical.rpt]",
            "report_checks -unconstrained -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count 1 -sort_by_slack -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6 > [file join $report_dir unconstrained.rpt]",
            "report_check_types -max_slew -max_capacitance -max_fanout -recovery -removal -min_pulse_width -min_period -min_delay -max_delay > [file join $report_dir check_types.rpt]",
            "if {[catch {report_checks -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count 1 -sort_by_slack -format json > [file join $report_dir endpoint_coverage.json]} json_error]} {",
            '  puts "WARNING: optional report_checks JSON unavailable: $json_error"',
            "}",
            'puts "reports=$report_dir"',
        ]
    )


def render_sdf_tcl(ctx: SignoffContext) -> str:
    limitations = ("SDF reflects the linked netlist and timing model for the selected corner.",)
    sdf = ctx.report_dir / f"{ctx.top}_{ctx.corner}.sdf"
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=False),
            "",
            "# write_sdf serializes the linked timing model for gate-level simulation.",
            f"set sdf_file {_quote(sdf)}",
            'puts "sdf=$sdf_file"',
            "write_sdf -divider . -include_typ $sdf_file",
        ]
    )


def _power_reports(ctx: SignoffContext) -> list[str]:
    return [
        "report_activity_annotation -report_annotated -report_unannotated > [file join $report_dir activity_annotation.rpt]",
        "report_power > [file join $report_dir power_summary.rpt]",
        f"report_power -highest_power_instances {ctx.power_top_instances} > [file join $report_dir highest_power_instances.rpt]",
        "if {[catch {report_power -format json > [file join $report_dir power.json]} power_json_error]} {",
        '  puts "WARNING: optional report_power JSON unavailable: $power_json_error"',
        "}",
        f"if {{[catch {{report_power -highest_power_instances {ctx.power_top_instances} -format json > [file join $report_dir highest_power_instances.json]}} highest_json_error]}} {{",
        '  puts "WARNING: optional highest-power JSON unavailable: $highest_json_error"',
        "}",
    ]


def render_power_estimate_tcl(ctx: SignoffContext) -> str:
    model = "global" if ctx.global_activity else "input"
    limitations = (
        "This is a vectorless estimate; it does not represent a simulated workload.",
        "Activity is assigned to primary inputs and propagated by OpenSTA unless global activity is explicitly requested.",
    )
    activity_cmd = "-global" if ctx.global_activity else "-input"
    lines = [
        _header(ctx, limitations),
        _common_init(ctx, activity=False),
        "",
        "# -----------------------------------------------------------------------------",
        "# Vectorless activity model",
        "#",
        "# The default -input model applies activity assumptions only to primary data",
        "# inputs. OpenSTA then propagates activity through the linked design.  A global",
        "# assumption is used only when explicitly selected by configuration.",
        "# -----------------------------------------------------------------------------",
        f'set_power_activity {activity_cmd} -activity {ctx.estimated_activity} -duty {ctx.estimated_duty}',
        "set assumptions [open [file join $report_dir activity_assumptions.rpt] w]",
        'puts $assumptions "analysis=estimate"',
        'puts $assumptions "activity_source=input_assumption"',
        f'puts $assumptions "activity_model={model}"',
        f'puts $assumptions "activity={ctx.estimated_activity}"',
        f'puts $assumptions "duty={ctx.estimated_duty}"',
        f'puts $assumptions "corner={ctx.corner}"',
        f'puts $assumptions "stage={ctx.stage}"',
        'puts $assumptions "liberty=$liberty"',
        'puts $assumptions "macro_liberty=$macro_liberties"',
        'puts $assumptions "netlist=$netlist"',
        'puts $assumptions "sdc=$sdc"',
        'puts $assumptions "spef=$spef"',
        'puts $assumptions "limitations=vectorless input activity propagated by OpenSTA"',
        "close $assumptions",
        *_power_reports(ctx),
    ]
    return "\n".join(lines)


def render_power_analysis_tcl(ctx: SignoffContext) -> str:
    limitations = (
        "Power is average cell power derived from the selected Liberty models and annotated activity.",
        "Unannotated objects and scope mismatches remain visible in activity_annotation.rpt.",
    )
    lines = [
        _header(ctx, limitations),
        _common_init(ctx, activity=True),
        "",
        f'puts "analysis=activity activity_source={ctx.activity_file.suffix.lower().lstrip(".") if ctx.activity_file else "none"}"',
        f'puts "gls_report={ctx.gls_report or ""}"',
        f'puts "activity_file={ctx.activity_file or ""}"',
        f'puts "activity_scope={ctx.activity_scope}"',
        *_power_reports(ctx),
    ]
    return "\n".join(lines)


_FUSION_HELPERS = r'''
# -----------------------------------------------------------------------------
# Version-gated fusion adapters
#
# The pinned OpenSTA exposes find_timing_paths plus internal power/network APIs.
# These adapters deliberately fail with a clear diagnostic when an indispensable
# API is absent instead of emitting partial CSV data as if it were valid.
# -----------------------------------------------------------------------------
proc flexsoc_require_command {name} {
  if {[llength [info commands $name]] == 0} {
    puts stderr "ERROR: fusion_analysis requires OpenSTA command/API: $name"
    exit 2
  }
}
foreach required {find_timing_paths sta::instance_power sta::cmd_scene sta::network_leaf_instances get_full_name get_pins get_cells get_nets} {
  flexsoc_require_command $required
}
proc flexsoc_try {scripts} {
  foreach script $scripts {
    if {![catch {uplevel 1 $script} value]} {return $value}
  }
  return ""
}
proc flexsoc_path_value {path field} {
  set value [flexsoc_try [list [list get_property $path $field] [list $path $field] [list sta::path_end_$field $path]]]
  return $value
}
proc flexsoc_path_pins {path} {
  set pins [flexsoc_try [list [list get_property $path pins] [list $path pins] [list sta::path_end_pins $path]]]
  if {$pins eq ""} {
    puts stderr "ERROR: fusion_analysis cannot recover ordered pins from timing path; required path API is unavailable"
    exit 2
  }
  return $pins
}
proc flexsoc_pin_instance {pin} {
  set cells [flexsoc_try [list [list get_cells -of_objects $pin] [list get_property $pin instance]]]
  if {[llength $cells] == 0} {return ""}
  return [lindex $cells 0]
}
proc flexsoc_pin_net {pin} {
  set nets [flexsoc_try [list [list get_nets -of_objects $pin] [list get_property $pin net]]]
  if {[llength $nets] == 0} {return ""}
  return [lindex $nets 0]
}
proc flexsoc_pin_slew {pin} {
  return [flexsoc_try [list [list get_property $pin slew] [list sta::pin_slew $pin]]]
}
proc flexsoc_pin_capacitance {pin} {
  return [flexsoc_try [list [list get_property $pin capacitance] [list sta::pin_capacitance $pin]]]
}
proc flexsoc_net_fanout {net} {
  if {$net eq ""} {return ""}
  set loads [flexsoc_try [list [list get_pins -of_objects $net -filter {direction == input}] [list sta::net_load_pins $net]]]
  if {$loads eq ""} {return ""}
  return [llength $loads]
}
proc flexsoc_instance_power {inst corner_handle} {
  if {$inst eq ""} {return [list "" "" "" "" ""]}
  lassign [sta::instance_power $inst $scene] internal switching leakage total
  set dynamic [expr {$internal + $switching}]
  return [list $internal $switching $dynamic $leakage $total]
}
proc flexsoc_csv {value} {
  set escaped [string map [list "\"" "\"\""] $value]
  return "\"$escaped\""
}
'''


_FUSION_BODY = r'''
set delay_type @DELAY_TYPE@
set near_limit @NEAR_LIMIT@
set corner {@CORNER@}
set mode {@MODE@}
set high_fanout_threshold @HIGH_FANOUT@
set power_top_instances @POWER_INSTANCES@
set power_paths_per_instance @PATHS_PER_INSTANCE@
set power_top_paths @TOP_PATHS@
set power_corner NULL

# Normalize path pins to launch-to-capture order before assigning roles. Set
# FLEXSOC_FUSION_REVERSE_PINS=1 only for an OpenSTA build whose internal path
# API is verified to return endpoint-to-startpoint order.
set reverse_path_pins [expr {[info exists ::env(FLEXSOC_FUSION_REVERSE_PINS)] && $::env(FLEXSOC_FUSION_REVERSE_PINS) eq "1"}]
proc flexsoc_ordered_path_pins {path} {
  global reverse_path_pins
  set pins [flexsoc_path_pins $path]
  return [expr {$reverse_path_pins ? [lreverse $pins] : $pins}]
}
proc flexsoc_instance_ref {inst} {
  return [flexsoc_try [list [list get_property $inst ref_name] [list get_property $inst liberty_cell]]]
}
proc flexsoc_instance_path_pin {inst pins prefer_output} {
  foreach pin $pins {
    set pin_inst [flexsoc_pin_instance $pin]
    if {$pin_inst eq "" || [get_full_name $pin_inst] ne [get_full_name $inst]} {continue}
    set direction [string tolower [flexsoc_try [list [list get_property $pin direction]]]]
    if {$prefer_output && $direction eq "output"} {return $pin}
    if {!$prefer_output && $direction eq "input"} {return $pin}
  }
  return ""
}
proc flexsoc_emit_path {path section rank seed paths_csv inst_csv report} {
  global corner mode high_fanout_threshold scene
  set pins [flexsoc_ordered_path_pins $path]
  if {[llength $pins] < 2} {return ""}
  set pin_names {}
  foreach pin $pins {lappend pin_names [get_full_name $pin]}
  set signature [join $pin_names {|}]
  set startpoint [lindex $pin_names 0]
  set endpoint [lindex $pin_names end]
  set slack [flexsoc_path_value $path slack]
  set arrival [flexsoc_path_value $path arrival]
  set required [flexsoc_path_value $path required]
  set source_latency [flexsoc_path_value $path source_clock_latency]
  set target_latency [flexsoc_path_value $path target_clock_latency]
  set clock_skew ""
  if {$source_latency ne "" && $target_latency ne ""} {set clock_skew [expr {$target_latency - $source_latency}]}
  set launch_clock [flexsoc_path_value $path launch_clock]
  set capture_clock [flexsoc_path_value $path capture_clock]
  set timing_status [expr {$slack ne "" && $slack <= 0.0 ? "TIMING_VIOLATING" : "TIMING_SAFE"}]

  set instances {}
  set instance_seen {}
  foreach pin $pins {
    set inst [flexsoc_pin_instance $pin]
    if {$inst eq ""} {continue}
    set name [get_full_name $inst]
    if {![dict exists $instance_seen $name]} {dict set instance_seen $name 1; lappend instances $inst}
  }
  set path_class UNKNOWN
  set first_inst [flexsoc_pin_instance [lindex $pins 0]]
  set last_inst [flexsoc_pin_instance [lindex $pins end]]
  if {$first_inst ne "" && $last_inst ne ""} {set path_class SEQ_TO_SEQ}
  if {$first_inst eq "" && $last_inst ne ""} {set path_class INPUT_TO_SEQ}
  if {$first_inst ne "" && $last_inst eq ""} {set path_class SEQ_TO_OUTPUT}
  if {$first_inst eq "" && $last_inst eq ""} {set path_class INPUT_TO_OUTPUT}

  set internal_proxy 0.0; set switching_proxy 0.0; set dynamic_proxy 0.0; set leakage_proxy 0.0; set total_proxy 0.0
  set max_cap ""; set sum_cap 0.0; set cap_count 0; set max_fanout ""; set sum_fanout 0.0; set fanout_count 0; set high_fanout_count 0; set max_slew ""
  set instance_order 0

  puts $report "================================================================================"
  puts $report "PATH $rank"
  puts $report "section=$section"
  puts $report "timing_status=$timing_status"
  puts $report "class=$path_class"
  puts $report "analysis=$mode"
  puts $report "slack=$slack"
  puts $report "arrival=$arrival"
  puts $report "required=$required"
  puts $report "startpoint=$startpoint"
  puts $report "endpoint=$endpoint"
  puts $report "launch_clock=$launch_clock"
  puts $report "capture_clock=$capture_clock"
  puts $report "source_clock_latency=$source_latency"
  puts $report "target_clock_latency=$target_latency"
  puts $report "clock_skew=$clock_skew"
  puts $report "IDX ROLE INSTANCE REF_CELL INPUT_PIN OUTPUT_PIN OUTPUT_NET OUTPUT_SLEW OUTPUT_CAPACITANCE FANOUT INTERNAL_POWER SWITCHING_POWER DYNAMIC_POWER LEAKAGE_POWER TOTAL_POWER"

  foreach inst $instances {
    incr instance_order
    set inst_name [get_full_name $inst]
    set role DATA
    if {$instance_order == 1} {set role LAUNCH_SEQ}
    if {$instance_order == [llength $instances]} {set role CAPTURE_SEQ}
    set input_pin [flexsoc_instance_path_pin $inst $pins 0]
    set output_pin ""; set output_net ""; set slew ""; set cap ""; set fanout ""
    if {$role ne "CAPTURE_SEQ"} {
      set output_pin [flexsoc_instance_path_pin $inst $pins 1]
      if {$output_pin eq ""} {
        foreach candidate [get_pins -of_objects $inst] {
          if {[string tolower [flexsoc_try [list [list get_property $candidate direction]]]] eq "output"} {set output_pin $candidate; break}
        }
      }
      if {$output_pin ne ""} {
        set output_net [flexsoc_pin_net $output_pin]
        set slew [flexsoc_pin_slew $output_pin]
        set cap [flexsoc_pin_capacitance $output_pin]
        set fanout [flexsoc_net_fanout $output_net]
        if {$cap ne ""} {set sum_cap [expr {$sum_cap + $cap}]; incr cap_count; if {$max_cap eq "" || $cap > $max_cap} {set max_cap $cap}}
        if {$fanout ne ""} {set sum_fanout [expr {$sum_fanout + $fanout}]; incr fanout_count; if {$max_fanout eq "" || $fanout > $max_fanout} {set max_fanout $fanout}; if {$fanout > $high_fanout_threshold} {incr high_fanout_count}}
        if {$slew ne "" && ($max_slew eq "" || $slew > $max_slew)} {set max_slew $slew}
      }
    }
    lassign [flexsoc_instance_power $inst $power_corner] internal switching dynamic leakage total
    set internal_proxy [expr {$internal_proxy + $internal}]
    set switching_proxy [expr {$switching_proxy + $switching}]
    set dynamic_proxy [expr {$dynamic_proxy + $dynamic}]
    set leakage_proxy [expr {$leakage_proxy + $leakage}]
    set total_proxy [expr {$total_proxy + $total}]
    set ref_cell [flexsoc_instance_ref $inst]
    set input_name [expr {$input_pin eq "" ? "" : [get_full_name $input_pin]}]
    set output_name [expr {$output_pin eq "" ? "" : [get_full_name $output_pin]}]
    set net_name [expr {$output_net eq "" ? "" : [get_full_name $output_net]}]
    puts $inst_csv [join [list $rank $rank $instance_order $role [flexsoc_csv $inst_name] [flexsoc_csv $ref_cell] [flexsoc_csv $input_name] [flexsoc_csv $output_name] [flexsoc_csv $net_name] [flexsoc_csv $signature] $slew $cap $fanout $internal $switching $dynamic $leakage $total] ,]
    puts $report "$instance_order $role $inst_name $ref_cell $input_name $output_name $net_name $slew $cap $fanout $internal $switching $dynamic $leakage $total"
  }
  set avg_cap [expr {$cap_count ? $sum_cap / $cap_count : ""}]
  set avg_fanout [expr {$fanout_count ? $sum_fanout / $fanout_count : ""}]
  set activity_weighted_capacitance ""
  puts $paths_csv [join [list $rank $section $rank $corner $mode $timing_status $path_class [flexsoc_csv $startpoint] [flexsoc_csv $endpoint] [flexsoc_csv $launch_clock] [flexsoc_csv $capture_clock] $slack $arrival $required $source_latency $target_latency $clock_skew [llength $instances] $internal_proxy $switching_proxy $dynamic_proxy $leakage_proxy $total_proxy $max_cap $sum_cap $avg_cap $max_fanout $avg_fanout $high_fanout_count $max_slew $sum_cap $activity_weighted_capacitance [flexsoc_csv $seed]] ,]
  puts $report "PATH DYNAMIC POWER PROXY=$dynamic_proxy"
  puts $report "PATH TOTAL POWER PROXY=$total_proxy"
  puts $report "PATH CAPACITANCE SUM PROXY=$sum_cap"
  puts $report "MAX PATH FANOUT=$max_fanout"
  puts $report "MAX PATH SLEW=$max_slew"
  puts $report "proxy_note=complete cell power and complete driven-net load may contribute to multiple paths"
  return $signature
}

set paths_csv [open [file join $report_dir paths.csv] w]
puts $paths_csv "path_id,section,rank,corner,mode,timing_status,path_class,startpoint,endpoint,launch_clock,capture_clock,slack,arrival,required,source_clock_latency,target_clock_latency,clock_skew,instance_count,internal_power_proxy,switching_power_proxy,dynamic_power_proxy,leakage_power_proxy,total_power_proxy,max_output_capacitance,sum_output_capacitance_proxy,average_output_capacitance,max_fanout,average_fanout,high_fanout_stage_count,max_slew,switched_capacitance_proxy,activity_weighted_capacitance_proxy,power_hotspot_seed"
set inst_csv [open [file join $report_dir path_instances.csv] w]
puts $inst_csv "path_id,path_rank,instance_order,role,instance,ref_cell,input_pin,output_pin,output_net,pin_sequence,output_slew,output_capacitance,fanout,internal_power,switching_power,dynamic_power,leakage_power,total_power"
set violating_report [open [file join $report_dir timing_violating_power.rpt] w]
set near_report [open [file join $report_dir timing_near_critical_power.rpt] w]
set power_report [open [file join $report_dir power_driven_paths.rpt] w]
puts $power_report "Power-driven selection has no slack filter. timing-safe paths are valid results."
puts $power_report "Power and capacitance sums are attribution proxies, not exclusive path energy."

set global_rank 0
set violating_count 0
set violating_paths [find_timing_paths -path_delay $delay_type -group_path_count 10000 -endpoint_path_count 10 -unique_paths_to_endpoint -sort_by_slack -slack_max 0.0]
foreach path $violating_paths {incr global_rank; incr violating_count; flexsoc_emit_path $path TIMING_VIOLATING $global_rank "" $paths_csv $inst_csv $violating_report}
set near_count 0
set near_paths [find_timing_paths -path_delay $delay_type -group_path_count 3000 -endpoint_path_count 3 -unique_paths_to_endpoint -sort_by_slack -slack_min 0.0 -slack_max $near_limit]
foreach path $near_paths {incr global_rank; incr near_count; flexsoc_emit_path $path TIMING_NEAR_CRITICAL $global_rank "" $paths_csv $inst_csv $near_report}

# POWER_DRIVEN deliberately has no -slack_min/-slack_max selection.
set hotspot_rows {}
foreach inst [sta::network_leaf_instances] {
  lassign [flexsoc_instance_power $inst $scene] internal switching dynamic leakage total
  lappend hotspot_rows [list $dynamic $total [get_full_name $inst] $inst]
}
set hotspot_rows [lsort -real -decreasing -index 0 $hotspot_rows]
set hotspot_rows [lrange $hotspot_rows 0 [expr {$power_top_instances - 1}]]
set power_seen {}
set power_count 0
foreach hotspot $hotspot_rows {
  lassign $hotspot hotspot_dynamic hotspot_total hotspot_name hotspot_inst
  set through_pins [get_pins -of_objects $hotspot_inst]
  if {[llength $through_pins] == 0} {continue}
  set candidate_paths [find_timing_paths -through $through_pins -path_delay $delay_type -group_path_count $power_paths_per_instance -endpoint_path_count 1 -sort_by_slack]
  foreach path $candidate_paths {
    set pins [flexsoc_ordered_path_pins $path]
    set pin_names {}
    foreach pin $pins {lappend pin_names [get_full_name $pin]}
    set signature [join $pin_names {|}]
    if {[dict exists $power_seen $signature]} {continue}
    dict set power_seen $signature 1
    incr global_rank; incr power_count
    flexsoc_emit_path $path POWER_DRIVEN $global_rank $hotspot_name $paths_csv $inst_csv $power_report
    if {$power_count >= $power_top_paths} {break}
  }
  if {$power_count >= $power_top_paths} {break}
}
close $paths_csv; close $inst_csv; close $violating_report; close $near_report; close $power_report

set summary [open [file join $report_dir summary.rpt] w]
puts $summary "analysis=fusion_analysis"
puts $summary "stage=$stage"
puts $summary "corner=$corner"
puts $summary "mode=$mode"
puts $summary "timing_violating_paths=$violating_count"
puts $summary "timing_near_critical_paths=$near_count"
puts $summary "power_driven_paths=$power_count"
puts $summary "methodology=TIMING_DRIVEN and POWER_DRIVEN selections are independent"
puts $summary "power_filter=no_slack_filter"
puts $summary "dynamic_power=internal_power+switching_power"
puts $summary "proxy_note=cell power and complete net capacitance may contribute to multiple rankings"
close $summary
'''


def render_fusion_analysis_tcl(ctx: SignoffContext) -> str:
    delay_type = "min" if ctx.mode == "hold" else "max"
    threshold = ctx.near_critical_hold if ctx.mode == "hold" else ctx.near_critical_setup
    limitations = (
        "Per-path power is an attribution proxy: a shared cell can contribute its complete average power to multiple paths.",
        "sum_output_capacitance_proxy includes complete driven-net load, including off-path loads, and may be repeated across paths.",
        "Activity-weighted capacitance is left empty when reliable pin/net activity is unavailable.",
    )
    body = (
        _FUSION_BODY.replace("@DELAY_TYPE@", delay_type)
        .replace("@NEAR_LIMIT@", f"{threshold:.6f}")
        .replace("@CORNER@", ctx.corner)
        .replace("@MODE@", ctx.mode)
        .replace("@HIGH_FANOUT@", str(ctx.high_fanout_threshold))
        .replace("@POWER_INSTANCES@", str(ctx.power_top_instances))
        .replace("@PATHS_PER_INSTANCE@", str(ctx.power_paths_per_instance))
        .replace("@TOP_PATHS@", str(ctx.power_top_paths))
    )
    return "\n".join([
        _header(ctx, limitations),
        _common_init(ctx, activity=True),
        _FUSION_HELPERS,
        body,
        *_power_reports(ctx),
    ])


def _macro_liberties(values: Mapping[str, str]) -> tuple[Path, ...]:
    """Resolve and validate every configured macro Liberty view."""

    return tuple(_require_file(path, "macro Liberty") for path in _paths(values.get("MACRO_LIBS")))


def _stage_inputs(project_root: Path, values: Mapping[str, str]) -> tuple[Path, Path | None]:
    """Resolve netlist and optional SPEF from the existing synthesis/PnR trees."""

    layout = layout_from_values(project_root, values)
    stage = values.get("SIGNOFF_STAGE", "post_syn").strip().lower()
    if stage not in {"post_syn", "post_route"}:
        raise ValueError(f"SIGNOFF_STAGE must be post_syn or post_route, got {stage!r}")
    top = values.get("TOP", "test")
    if stage == "post_route":
        raw_netlist = values.get("NETLIST") or values.get("PNR_NETLIST")
        if raw_netlist:
            netlist = Path(raw_netlist)
        else:
            candidates = sorted((layout.pnr_dir / "results").glob(f"**/{top}/**/6_final.v"))
            if not candidates:
                candidates = sorted((layout.pnr_dir / "results").glob("**/6_final.v"))
            if not candidates:
                raise ValueError(f"post-route netlist not found under {layout.pnr_dir / 'results'}")
            netlist = candidates[-1]
        raw_spef = values.get("SPEF_FILE", "").strip()
        if raw_spef:
            spef = Path(raw_spef)
        else:
            candidates = sorted((layout.pnr_dir / "results").glob(f"**/{top}/**/6_final.spef"))
            if not candidates:
                candidates = sorted((layout.pnr_dir / "results").glob("**/6_final.spef"))
            if not candidates:
                raise ValueError(f"post-route SPEF not found under {layout.pnr_dir / 'results'}")
            spef = candidates[-1]
        return _require_file(netlist, "post-route netlist"), _require_file(spef, "SPEF")
    netlist = Path(values.get("NETLIST") or layout.syn_dir / f"{top}_synth.v")
    raw_spef = values.get("SPEF_FILE", "").strip()
    spef = Path(raw_spef).expanduser().resolve() if raw_spef else None
    return _require_file(netlist, "gate-level netlist"), _optional_file(spef, "SPEF")


def _base_context(
    project_root: Path,
    values: Mapping[str, str],
    *,
    analysis: str,
    corner: str,
    mode: str = "",
    workload: str = "",
    report_dir: Path,
    liberty: Path,
    activity_file: Path | None = None,
    activity_scope: str = "",
    gls_report: Path | None = None,
) -> SignoffContext:
    """Resolve one concrete analysis context from the existing run settings."""

    layout = layout_from_values(project_root, values)
    netlist, spef = _stage_inputs(project_root, values)
    sdc = _require_file(
        Path(values.get("PNR_SDC_FILE") or layout.constraints_dir / f"{values.get('TOP', 'test')}.sdc"),
        "SDC",
    )
    return SignoffContext(
        analysis=analysis,
        design=values.get("RUN_TOP") or values.get("TOP", "test"),
        variant=values.get("RUN_ID", "default"),
        pdk=values.get("PDK", "sky130"),
        stage=values.get("SIGNOFF_STAGE", "post_syn"),
        corner=corner,
        mode=mode,
        workload=workload,
        top=values.get("TOP", "test"),
        liberty=_require_file(liberty, f"{corner} Liberty"),
        macro_liberties=_macro_liberties(values),
        netlist=netlist,
        sdc=sdc,
        report_dir=report_dir.expanduser().resolve(),
        spef=spef,
        activity_file=_optional_file(activity_file, "activity file"),
        activity_scope=activity_scope,
        gls_report=_optional_file(gls_report, "GLS report"),
        estimated_activity=float(values.get("POWER_ACTIVITY", "0.1")),
        estimated_duty=float(values.get("POWER_DUTY", "0.5")),
        global_activity=_truth(values.get("POWER_GLOBAL_ACTIVITY")),
        endpoint_group_limit=int(values.get("STA_ENDPOINT_GROUP_LIMIT", "10000")),
        endpoint_path_limit=int(values.get("STA_ENDPOINT_PATH_LIMIT", "10")),
        near_critical_setup=float(values.get("STA_NEAR_CRITICAL_SETUP", "0.200")),
        near_critical_hold=float(values.get("STA_NEAR_CRITICAL_HOLD", "0.100")),
        high_fanout_threshold=int(values.get("FUSION_HIGH_FANOUT_THRESHOLD", "16")),
        power_top_instances=int(values.get("POWER_TOP_INSTANCES", "200")),
        power_paths_per_instance=int(values.get("FUSION_PATHS_PER_INSTANCE", "2")),
        power_top_paths=int(values.get("FUSION_TOP_PATHS", "100")),
    )


def _render(analysis: str, ctx: SignoffContext) -> str:
    renderers = {
        "sta": render_sta_tcl,
        "sdf": render_sdf_tcl,
        "power_estimate": render_power_estimate_tcl,
        "power_analysis": render_power_analysis_tcl,
        "fusion_analysis": render_fusion_analysis_tcl,
    }
    try:
        return renderers[analysis](ctx)
    except KeyError as exc:
        raise ValueError(f"unsupported sign-off analysis: {analysis}") from exc


def generate_families(project_root: Path, values: Mapping[str, str]) -> tuple[Path, ...]:
    """Generate the four public Tcl families plus SDF under one PDK branch."""

    layout = layout_from_values(project_root, values)
    liberties = _liberties(values)
    corner = "tt" if "tt" in liberties else next(iter(liberties))
    liberty = liberties[corner]
    root = layout.signoff_pdk_root
    generated: list[Path] = []
    specs = (
        ("sta", root / "sta" / "sta.tcl", "setup", root / "sta" / "template_reports"),
        ("sdf", root / "sdf" / "write_sdf.tcl", "", root / "sdf" / "template_reports"),
        (
            "power_estimate",
            root / "power" / "estimate" / "power_estimate.tcl",
            "",
            root / "power" / "estimate" / "template_reports",
        ),
    )
    for analysis, path, mode, report_dir in specs:
        ctx = _base_context(
            project_root,
            values,
            analysis=analysis,
            corner=corner,
            mode=mode,
            report_dir=report_dir,
            liberty=liberty,
        )
        generated.append(_write(path, _render(analysis, ctx)))
    # Workload-dependent families are complete templates with explicit sentinel
    # paths. Concrete, executable instances are generated only after GLS exists.
    sentinel_activity = root / "power" / "activity" / "ACTIVITY_REQUIRED.vcd"
    sentinel_report = root / "power" / "activity" / "GLS_REPORT_REQUIRED.json"
    for analysis, path in (
        ("power_analysis", root / "power" / "analysis" / "power_analysis.tcl"),
        ("fusion_analysis", root / "fusion" / "fusion_analysis.tcl"),
    ):
        ctx = _base_context(
            project_root,
            values,
            analysis=analysis,
            corner=corner,
            mode="setup" if analysis == "fusion_analysis" else "",
            workload="GLS_WORKLOAD_REQUIRED",
            report_dir=path.parent / "template_reports",
            liberty=liberty,
            activity_file=None,
            activity_scope="DUT_SCOPE_REQUIRED",
            gls_report=None,
        )
        # Header and analysis Tcl intentionally expose sentinel names without
        # requiring the placeholder files to exist during setup_signoff.
        ctx = replace(
            ctx,
            activity_file=sentinel_activity,
            gls_report=sentinel_report,
        )
        generated.append(_write(path, _render(analysis, ctx)))
    for path in generated:
        print_script(path)
    return tuple(generated)


def _required_reports(analysis: str, ctx: SignoffContext) -> tuple[Path, ...]:
    if analysis == "sta":
        names = (
            "summary.rpt",
            "check_setup.rpt",
            "endpoint_coverage.rpt",
            "violating.rpt",
            "near_critical.rpt",
            "unconstrained.rpt",
            "check_types.rpt",
        )
    elif analysis == "power_estimate":
        names = (
            "activity_assumptions.rpt",
            "activity_annotation.rpt",
            "power_summary.rpt",
            "highest_power_instances.rpt",
        )
    elif analysis == "power_analysis":
        names = (
            "activity_annotation.rpt",
            "power_summary.rpt",
            "highest_power_instances.rpt",
        )
    elif analysis == "fusion_analysis":
        names = (
            "timing_violating_power.rpt",
            "timing_near_critical_power.rpt",
            "power_driven_paths.rpt",
            "summary.rpt",
            "paths.csv",
            "path_instances.csv",
            "activity_annotation.rpt",
            "power_summary.rpt",
        )
    elif analysis == "sdf":
        names = (f"{ctx.top}_{ctx.corner}.sdf",)
    else:
        raise ValueError(f"unsupported analysis: {analysis}")
    return tuple(ctx.report_dir / name for name in names)


def _execute_script(
    project_root: Path,
    values: Mapping[str, str],
    *,
    analysis: str,
    ctx: SignoffContext,
    script: Path,
    log: Path,
) -> int:
    """Execute one OpenSTA script and reject truncated/incomplete output."""

    ctx.report_dir.mkdir(parents=True, exist_ok=True)
    _write(script, _render(analysis, ctx))
    print_script(script)
    rc = _run_sta(
        [values.get("STA", "sta"), "-exit", "-no_init", str(script)],
        cwd=project_root,
        log=log,
    )
    if rc != 0:
        return rc
    missing = [path for path in _required_reports(analysis, ctx) if not path.is_file()]
    if missing:
        rendered = "\n  ".join(str(path) for path in missing)
        raise ValueError(f"{analysis} completed without required report(s):\n  {rendered}")
    if analysis in {"power_estimate", "power_analysis", "fusion_analysis"}:
        _annotate_power_summary(ctx.report_dir)
    return 0


def _annotate_power_summary(report_dir: Path) -> None:
    """Append explicit normalized power terminology to the OpenSTA text report."""

    report = report_dir / "power_summary.rpt"
    if not report.is_file():
        return
    text = report.read_text(encoding="utf-8", errors="replace")
    values = _power_values(text)
    lines = [
        "",
        "# FlexSoC normalized power fields",
        "dynamic_power_definition=internal_power+switching_power",
        "power_unit=OpenSTA report unit; see units.rpt",
        "display_power_unit=OpenSTA report unit; see units.rpt",
    ]
    if values:
        lines.extend(
            (
                f"internal_power={values['internal_w']}",
                f"switching_power={values['switching_w']}",
                f"dynamic_power={values['internal_w'] + values['switching_w']}",
                f"leakage_power={values['leakage_w']}",
                f"total_power={values['total_w']}",
            )
        )
    report.write_text(text.rstrip() + "\n" + "\n".join(lines) + "\n", encoding="utf-8")


def execute_static(analysis: str, project_root: Path, values: Mapping[str, str]) -> int:
    """Generate and execute STA, SDF or vectorless power at every configured corner."""

    if analysis not in {"sta", "sdf", "power_estimate"}:
        raise ValueError(f"static analysis is not supported: {analysis}")
    layout = layout_from_values(project_root, values)
    corners = _split(values.get("SIGNOFF_CORNERS") or "ss tt ff")
    modes = _split(values.get("STA_MODES") or "setup hold") if analysis == "sta" else ("",)
    liberties = _liberties(values)
    failures: list[str] = []
    for corner in corners:
        if corner not in liberties:
            failures.append(f"{corner}: no Liberty view")
            continue
        for mode in modes:
            if analysis == "sta":
                report_dir = layout.sta_dir / corner / mode
                script = layout.sta_dir / "sta.tcl"
                log = layout.sta_log_dir / corner / mode / f"{values.get('TOP', 'test')}.log"
            elif analysis == "sdf":
                report_dir = layout.sdf_dir / corner
                script = layout.sdf_dir / "write_sdf.tcl"
                log = layout.sdf_log_dir / corner / f"{values.get('TOP', 'test')}.log"
            else:
                report_dir = layout.power_dir / "estimate" / corner
                script = layout.power_dir / "estimate" / "power_estimate.tcl"
                log = layout.power_log_dir / "estimate" / corner / f"{values.get('TOP', 'test')}.log"
            ctx = _base_context(
                project_root,
                values,
                analysis=analysis,
                corner=corner,
                mode=mode,
                report_dir=report_dir,
                liberty=liberties[corner],
            )
            try:
                rc = _execute_script(
                    project_root,
                    values,
                    analysis=analysis,
                    ctx=ctx,
                    script=script,
                    log=log,
                )
            except (OSError, ValueError, subprocess.SubprocessError) as exc:
                failures.append(f"{corner}/{mode or analysis}: {exc}")
                continue
            if rc != 0:
                failures.append(f"{corner}/{mode or analysis}: OpenSTA return code {rc}; log={log}")
            elif analysis == "power_estimate":
                _highest_power_csv(report_dir)
    for failure in failures:
        print(f"ERROR: {failure}", file=sys.stderr)
    return 0 if not failures else 2


def _highest_power_csv(report_dir: Path) -> None:
    """Create the required CSV when OpenSTA emitted optional JSON."""

    output = report_dir / "highest_power_instances.csv"
    source = report_dir / "highest_power_instances.json"
    output.parent.mkdir(parents=True, exist_ok=True)
    if not source.is_file():
        output.write_text(
            "instance,internal_power,switching_power,dynamic_power,leakage_power,total_power\n",
            encoding="utf-8",
        )
        return
    try:
        payload = json.loads(source.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        payload = []
    rows = payload if isinstance(payload, list) else payload.get("instances", []) if isinstance(payload, dict) else []
    lines = ["instance,internal_power,switching_power,dynamic_power,leakage_power,total_power"]
    for item in rows:
        if not isinstance(item, dict):
            continue
        internal = float(item.get("internal", item.get("internal_power", 0.0)) or 0.0)
        switching = float(item.get("switching", item.get("switching_power", 0.0)) or 0.0)
        leakage = float(item.get("leakage", item.get("leakage_power", 0.0)) or 0.0)
        total = float(item.get("total", item.get("total_power", internal + switching + leakage)) or 0.0)
        lines.append(
            f"{item.get('instance', item.get('name', ''))},{internal},{switching},{internal + switching},{leakage},{total}"
        )
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")



def _number(row: Mapping[str, str], field: str, default: float = float("-inf")) -> float:
    try:
        return float(row.get(field, ""))
    except (TypeError, ValueError):
        return default


def _write_fusion_rankings(report_dir: Path) -> None:
    """Derive deterministic ranking reports from the OpenSTA path CSV."""

    paths_file = report_dir / "paths.csv"
    instances_file = report_dir / "path_instances.csv"
    if not paths_file.is_file() or not instances_file.is_file():
        raise ValueError(f"fusion CSV output missing under {report_dir}")
    with paths_file.open(newline="", encoding="utf-8") as stream:
        rows = list(csv.DictReader(stream))
    with instances_file.open(newline="", encoding="utf-8") as stream:
        instance_rows = list(csv.DictReader(stream))
    metrics = (
        "dynamic_power_proxy",
        "total_power_proxy",
        "max_output_capacitance",
        "sum_output_capacitance_proxy",
        "max_fanout",
        "max_slew",
    )
    for metric in metrics:
        ordered = sorted(rows, key=lambda row: _number(row, metric), reverse=True)
        output = report_dir / f"ranking_{metric}.rpt"
        lines = [f"ranking={metric}", "rank path_id section timing_status slack value startpoint endpoint"]
        for rank, row in enumerate(ordered, 1):
            lines.append(
                " ".join(
                    (
                        str(rank),
                        row.get("path_id", ""),
                        row.get("section", ""),
                        row.get("timing_status", ""),
                        row.get("slack", ""),
                        row.get(metric, ""),
                        row.get("startpoint", ""),
                        row.get("endpoint", ""),
                    )
                )
            )
        output.write_text("\n".join(lines) + "\n", encoding="utf-8")

    def best(predicate: Any, metric: str, *, reverse: bool = True) -> Mapping[str, str] | None:
        selected = [row for row in rows if predicate(row)]
        if not selected:
            return None
        return sorted(selected, key=lambda row: _number(row, metric), reverse=reverse)[0]

    summary = report_dir / "summary.rpt"
    with summary.open("a", encoding="utf-8") as stream:
        stream.write(f"selected_paths={len(rows)}\n")
        for metric in metrics:
            ordered = sorted(rows, key=lambda row: _number(row, metric), reverse=True)
            stream.write(f"\n[RANKING {metric}]\n")
            stream.write("rank path_id section timing_status slack value startpoint endpoint\n")
            for rank, row in enumerate(ordered[:20], 1):
                stream.write(
                    " ".join(
                        (
                            str(rank),
                            row.get("path_id", ""),
                            row.get("section", ""),
                            row.get("timing_status", ""),
                            row.get("slack", ""),
                            row.get(metric, ""),
                            row.get("startpoint", ""),
                            row.get("endpoint", ""),
                        )
                    )
                    + "\n"
                )
        categories = {
            "timing_critical_high_power": lambda row: row.get("timing_status") == "TIMING_VIOLATING",
            "timing_safe_high_power": lambda row: row.get("timing_status") == "TIMING_SAFE",
        }
        for label, predicate in categories.items():
            row = best(predicate, "dynamic_power_proxy")
            if row:
                stream.write(
                    f"{label}=path:{row.get('path_id')} dynamic:{row.get('dynamic_power_proxy')} "
                    f"slack:{row.get('slack')}\n"
                )
        extrema = {
            "worst_slack": ("slack", False),
            "maximum_dynamic_power_proxy": ("dynamic_power_proxy", True),
            "maximum_total_power_proxy": ("total_power_proxy", True),
            "maximum_output_capacitance": ("max_output_capacitance", True),
            "maximum_capacitance_sum_proxy": ("sum_output_capacitance_proxy", True),
            "maximum_fanout": ("max_fanout", True),
            "maximum_slew": ("max_slew", True),
        }
        for label, (metric, reverse) in extrema.items():
            row = best(lambda _: True, metric, reverse=reverse)
            if row:
                stream.write(f"{label}=path:{row.get('path_id')} value:{row.get(metric)}\n")
        counts: dict[str, int] = {}
        for row in instance_rows:
            name = row.get("instance", "")
            if name:
                counts[name] = counts.get(name, 0) + 1
        recurrent = sorted(counts.items(), key=lambda item: (-item[1], item[0]))[:20]
        stream.write(
            "recurrent_instances=" + ",".join(f"{name}:{count}" for name, count in recurrent) + "\n"
        )

def analyze_activity_spec(
    analysis: str,
    project_root: Path,
    values: Mapping[str, str],
    spec: ActivitySpec,
) -> dict[str, Any]:
    """Execute one workload-dependent analysis for every Liberty corner."""

    if analysis not in {"power_analysis", "fusion_analysis"}:
        raise ValueError(f"unsupported activity analysis: {analysis}")
    layout = layout_from_values(project_root, values)
    activity_root = layout.power_dir / "activity"
    capture, conversion_log, conversion_method = _activity_vcd(
        spec, values, activity_root / "captures"
    )
    requested_scope = values.get("POWER_VCD_SCOPE", "auto").strip() or "auto"
    scope, scopes = _resolve_vcd_scope(
        capture,
        requested=requested_scope,
        top=spec.top,
        dut_instance=values.get("POWER_DUT_INSTANCE", "auto").strip() or "auto",
    )
    corners: dict[str, Any] = {}
    failures: list[str] = []
    for corner, liberty in _liberties(values).items():
        modes = _split(values.get("STA_MODES") or "setup hold") if analysis == "fusion_analysis" else ("",)
        for mode in modes:
            if analysis == "power_analysis":
                report_dir = layout.power_dir / "analysis" / spec.workload / corner
                script = layout.power_dir / "analysis" / "power_analysis.tcl"
                log = layout.power_log_dir / "analysis" / spec.workload / corner / f"{spec.top}.log"
                key = corner
            else:
                report_dir = layout.fusion_dir / spec.workload / corner / mode
                script = layout.fusion_dir / "fusion_analysis.tcl"
                log = layout.fusion_log_dir / spec.workload / corner / mode / f"{spec.top}.log"
                key = f"{corner}/{mode}"
            ctx = _base_context(
                project_root,
                values,
                analysis=analysis,
                corner=corner,
                mode=mode,
                workload=spec.workload,
                report_dir=report_dir,
                liberty=liberty,
                activity_file=capture,
                activity_scope=scope,
                gls_report=spec.report,
            )
            try:
                rc = _execute_script(
                    project_root,
                    values,
                    analysis=analysis,
                    ctx=ctx,
                    script=script,
                    log=log,
                )
                if analysis == "power_analysis":
                    _highest_power_csv(report_dir)
                else:
                    _write_fusion_rankings(report_dir)
                text = log.read_text(encoding="utf-8", errors="replace") if log.is_file() else ""
                power_text = (report_dir / "power_summary.rpt").read_text(encoding="utf-8", errors="replace")
                annotation_text = (report_dir / "activity_annotation.rpt").read_text(encoding="utf-8", errors="replace")
                numbers = _power_values(power_text) or _power_values(text)
                annotated = _activity_count(annotation_text)
                if annotated is None:
                    annotated = _activity_count(text)
                ok = rc == 0 and (annotated is None or annotated > 0)
                corners[key] = {
                    "status": "pass" if ok else "fail",
                    "returncode": rc,
                    "liberty": str(liberty),
                    "script": str(script),
                    "log": str(log),
                    "report_dir": str(report_dir),
                    "activity_annotation_count": annotated,
                    **numbers,
                }
                if not ok:
                    failures.append(f"{key}: OpenSTA returned {rc} or annotated zero activity")
            except (OSError, ValueError, subprocess.SubprocessError) as exc:
                failures.append(f"{key}: {exc}")
                corners[key] = {"status": "fail", "reason": str(exc)}
    status = "pass" if corners and not failures else "fail"
    report = {
        "schema_version": 2,
        "analysis": analysis,
        "status": status,
        "top": spec.top,
        "pdk": spec.pdk,
        "test": spec.test,
        "backend": spec.backend,
        "timing_mode": spec.mode,
        "workload": spec.workload,
        "activity_source": ("post_pnr_gls_vcd" if values.get("SIGNOFF_STAGE") == "post_route" else "post_syn_gls_vcd"),
        "scope_requested": requested_scope,
        "scope": scope,
        "vcd_scopes": list(scopes),
        "source_gls_report": str(spec.report),
        "source_wave": str(spec.wave),
        "activity_file": str(capture),
        "conversion_method": conversion_method,
        "conversion_log": str(conversion_log) if conversion_log else None,
        "corners": corners,
        "failures": failures,
    }
    root = layout.power_dir / "analysis" if analysis == "power_analysis" else layout.fusion_dir
    path = root / "reports" / f"{spec.stem}.json"
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    report["report"] = str(path)
    return report


def execute_activity(
    analysis: str,
    action: str,
    project_root: Path,
    values: Mapping[str, str],
) -> int:
    specs = discover_specs(action, values, project_root)
    reports: list[dict[str, Any]] = []
    for spec in specs:
        try:
            reports.append(analyze_activity_spec(analysis, project_root, values, spec))
        except (OSError, ValueError, subprocess.SubprocessError) as exc:
            reports.append({"status": "fail", "spec": spec.stem, "reason": str(exc)})
    passed = sum(report.get("status") == "pass" for report in reports)
    layout = layout_from_values(project_root, values)
    summary_root = layout.power_dir / "analysis" if analysis == "power_analysis" else layout.fusion_dir
    summary = {
        "schema_version": 2,
        "analysis": analysis,
        "status": "pass" if reports and passed == len(reports) else "fail",
        "top": values.get("TOP", "test"),
        "pdk": values.get("PDK", "sky130"),
        "passed": passed,
        "failed": len(reports) - passed,
        "total": len(reports),
        "reports": reports,
    }
    summary_path = summary_root / "summary.json"
    summary_path.parent.mkdir(parents=True, exist_ok=True)
    summary_path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(f"[{analysis}] {passed}/{len(reports)} PASS summary={summary_path}", flush=True)
    return 0 if reports and passed == len(reports) else 2


def _add_common_arguments(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--project-root", type=Path, required=True)
    parser.add_argument("--workspace", type=Path, required=True)
    parser.add_argument("--run-top", required=True)
    parser.add_argument("--run-id", required=True)
    parser.add_argument("--top", required=True)
    parser.add_argument("--pdk", required=True)
    parser.add_argument("--signoff-stage", choices=("post_syn", "post_route"), default="post_syn")
    parser.add_argument("--liberty", action="append", default=[])
    parser.add_argument("--lib-syn")
    parser.add_argument("--macro-liberty", action="append", default=[])
    parser.add_argument("--netlist")
    parser.add_argument("--spef")
    parser.add_argument("--sdc")
    parser.add_argument("--sta", default="sta")
    parser.add_argument("--corners", default="ss tt ff")
    parser.add_argument("--modes", default="setup hold")
    parser.add_argument("--power-activity", default="0.1")
    parser.add_argument("--power-duty", default="0.5")
    parser.add_argument("--power-global-activity", action="store_true")
    parser.add_argument("--power-vcd-scope", default="auto")
    parser.add_argument("--power-dut-instance", default="auto")
    parser.add_argument("--fst2vcd", default="fst2vcd")
    parser.add_argument("--endpoint-group-limit", default="10000")
    parser.add_argument("--endpoint-path-limit", default="10")
    parser.add_argument("--near-critical-setup", default="0.200")
    parser.add_argument("--near-critical-hold", default="0.100")
    parser.add_argument("--power-top-instances", default="200")
    parser.add_argument("--fusion-power-metric", choices=("dynamic", "total"), default="dynamic")
    parser.add_argument("--fusion-paths-per-instance", default="2")
    parser.add_argument("--fusion-top-paths", default="100")
    parser.add_argument("--fusion-high-fanout-threshold", default="16")


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="command", required=True)
    generate = subparsers.add_parser("generate", help="Generate all OpenSTA Tcl families.")
    _add_common_arguments(generate)
    run = subparsers.add_parser("run", help="Execute one static OpenSTA analysis family.")
    _add_common_arguments(run)
    run.add_argument("--analysis", choices=("sta", "sdf", "power_estimate"), required=True)
    activity = subparsers.add_parser("activity", help="Execute workload-dependent power or fusion.")
    _add_common_arguments(activity)
    activity.add_argument("--analysis", choices=("power_analysis", "fusion_analysis"), required=True)
    activity.add_argument("--action", choices=("single", "all"), required=True)
    activity.add_argument("--test-name", default="smoke")
    activity.add_argument("--gls-backend", default="sv")
    activity.add_argument("--timing-mode", default="typ")
    activity.add_argument("--test-names", default="")
    activity.add_argument("--gls-backends", default="")
    activity.add_argument("--timing-modes", default="")
    return parser.parse_args(argv)


def _values(args: argparse.Namespace) -> dict[str, str]:
    values = {
        "WORKSPACE": str(args.workspace.expanduser().resolve()),
        "RUN_TOP": args.run_top,
        "RUN_ID": args.run_id,
        "TOP": args.top,
        "PDK": args.pdk,
        "SIGNOFF_STAGE": args.signoff_stage,
        "LIBS": " ".join(args.liberty),
        "LIB_SYN": args.lib_syn or "",
        "MACRO_LIBS": " ".join(args.macro_liberty),
        "NETLIST": args.netlist or "",
        "SPEF_FILE": args.spef or "",
        "PNR_SDC_FILE": args.sdc or "",
        "STA": args.sta,
        "SIGNOFF_CORNERS": args.corners,
        "STA_MODES": args.modes,
        "POWER_ACTIVITY": args.power_activity,
        "POWER_DUTY": args.power_duty,
        "POWER_GLOBAL_ACTIVITY": "1" if args.power_global_activity else "0",
        "POWER_VCD_SCOPE": args.power_vcd_scope,
        "POWER_DUT_INSTANCE": args.power_dut_instance,
        "FST2VCD": args.fst2vcd,
        "STA_ENDPOINT_GROUP_LIMIT": args.endpoint_group_limit,
        "STA_ENDPOINT_PATH_LIMIT": args.endpoint_path_limit,
        "STA_NEAR_CRITICAL_SETUP": args.near_critical_setup,
        "STA_NEAR_CRITICAL_HOLD": args.near_critical_hold,
        "POWER_TOP_INSTANCES": args.power_top_instances,
        "FUSION_PATHS_PER_INSTANCE": args.fusion_paths_per_instance,
        "FUSION_TOP_PATHS": args.fusion_top_paths,
        "FUSION_HIGH_FANOUT_THRESHOLD": args.fusion_high_fanout_threshold,
    }
    if args.command == "activity":
        values.update(
            {
                "TEST_NAME": args.test_name,
                "GLS_BACKEND": args.gls_backend,
                "TIMING_MODE": args.timing_mode,
                "POWER_TEST_NAME": args.test_name,
                "POWER_GLS_BACKEND": args.gls_backend,
                "POWER_TIMING_MODE": args.timing_mode,
                "POWER_TEST_NAMES": args.test_names,
                "POWER_GLS_BACKENDS": args.gls_backends,
                "POWER_TIMING_MODES": args.timing_modes,
            }
        )
    return values


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    try:
        root = args.project_root.expanduser().resolve()
        values = _values(args)
        if args.command == "generate":
            generate_families(root, values)
            return 0
        if args.command == "run":
            return execute_static(args.analysis, root, values)
        return execute_activity(args.analysis, args.action, root, values)
    except (OSError, ValueError, json.JSONDecodeError, subprocess.SubprocessError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
