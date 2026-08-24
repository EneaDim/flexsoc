"""Vectorless and activity-based power engine for FlexSoC sign-off."""

from __future__ import annotations

import json
import re
import shutil
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping

from flexsoc.backend.core import layout_from_values
from .sta import (
    ACTIVITY_PERCENT_RE, ACTIVITY_RE, FLOAT_RE, POWER_RE, SDF_MODES, SignoffContext,
    _base_context, _common_init, _execute_script, _header, _liberties, _load_json,
    _returncode_text, _selection, _selector, _timing_values, _write, scenario_corner,
)

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
        return f"{self.top}_{self.pdk}_{self.test}_{self.backend}_{scenario_corner(self.mode)}"

    @property
    def workload(self) -> str:
        """Return the sign-off workload name using the aligned PVT corner."""

        return f"{self.test}_{self.backend}_{scenario_corner(self.mode)}"

    @property
    def legacy_workload(self) -> str:
        """Return the pre-scenario workload name used before corner naming."""

        return f"{self.test}_{self.backend}_{self.mode}"

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
    scenario = scenario_corner(mode)
    canonical = stage_dir / f"{top}_{report_stage}_{test}_{backend}_{scenario}.json"
    if canonical.is_file():
        return canonical
    legacy = stage_dir / f"{top}_{report_stage}_{test}_{backend}_{mode}.json"
    return legacy if legacy.is_file() else canonical

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
    expected_corner = scenario_corner(mode)
    reported_scenario = payload.get("scenario")
    if reported_scenario is not None and reported_scenario != expected_corner:
        raise ValueError(
            f"GLS source scenario mismatch: expected {expected_corner}, "
            f"report has {reported_scenario!r}: {report}"
        )
    reported_corner = payload.get("sdf_corner")
    if reported_corner is None:
        raw_sdf = payload.get("sdf")
        if isinstance(raw_sdf, str) and raw_sdf.strip():
            reported_corner = Path(raw_sdf).expanduser().parent.name
    if reported_corner != expected_corner:
        raise ValueError(
            f"GLS source is not scenario-aligned: TIMING_MODE={mode} requires "
            f"SDF corner {expected_corner}, report has {reported_corner!r}: {report}"
        )
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
        try:
            payload = _load_json(report)
        except (ValueError, OSError):
            continue
        if payload.get("stage") != report_stage or payload.get("top") != top:
            continue
        test = str(payload.get("test_name", "")).strip()
        backend = str(payload.get("backend", "")).strip()
        mode = str(payload.get("timing_mode", "")).strip()
        if test and backend in {"sv", "cocotb"} and mode in SDF_MODES:
            rows.add((test, backend, mode))
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
            ("modes", modes, available_columns[2]),
        )
        if requested != ("all",) and set(requested) - present
    }
    if backends != ("all",) and not set(backends) & available_columns[1]:
        missing["backends"] = list(backends)
    if missing:
        raise ValueError(f"requested GLS reports are missing: {missing}")
    if not selected:
        raise ValueError(
            "no direct GLS reports match power selectors: "
            f"tests={tests} backends={backends} modes={modes}"
        )

    # Backends are alternative activity sources for one scenario, not dimensions.
    # Prefer the selected backend, then fall back to the other qualified source.
    preferred = values.get("POWER_GLS_BACKEND", values.get("GLS_BACKEND", "sv")).strip().lower()
    allowed = {"sv", "cocotb"} if backends == ("all",) else set(backends)
    backend_order = tuple(
        backend
        for backend in (preferred, "sv", "cocotb")
        if backend in allowed
    )
    backend_order = tuple(dict.fromkeys(backend_order))
    grouped: dict[tuple[str, str], set[str]] = {}
    for test, backend, mode in selected:
        grouped.setdefault((test, mode), set()).add(backend)

    specs: list[ActivitySpec] = []
    rejected: dict[str, list[str]] = {}
    mode_order = {mode: index for index, mode in enumerate(SDF_MODES)}
    for test, mode in sorted(grouped, key=lambda item: (mode_order[item[1]], item[0])):
        reasons: list[str] = []
        for backend in backend_order:
            if backend not in grouped[(test, mode)]:
                continue
            try:
                spec = _qualified_spec(
                    root, values, test=test, backend=backend, mode=mode
                )
            except ValueError as exc:
                reasons.append(f"{backend}: {exc}")
                continue
            specs.append(spec)
            break
        else:
            rejected[f"{test}/{mode}"] = reasons or ["no selected backend report"]

    if rejected:
        detail = "; ".join(
            f"{scenario}: {' | '.join(reasons)}"
            for scenario, reasons in rejected.items()
        )
        raise ValueError(
            "no qualified GLS backend is available for one or more selected scenarios: "
            + detail
        )
    return tuple(specs)

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
    """Resolve an explicit or generated DUT scope against the VCD header."""

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
        log.unlink(missing_ok=True)
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
        log.unlink(missing_ok=True)
        return "stdout"

    detail = ", ".join(
        f"{method}:rc={returncode}:bytes={size}"
        for method, returncode, size in attempts
    )
    raise ValueError(f"fst2vcd conversion failed ({detail}); log: {log}")

def _activity_vcd(
    spec: ActivitySpec, values: Mapping[str, str], capture_dir: Path, *, runner=None, on: str = "local"
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
    if runner is None:
        method = _convert_fst(
            executable=Path(executable), source=spec.wave, output=output, log=log
        )
    else:
        from flexsoc.backend.core import CommandRequest
        request = CommandRequest(
            (str(executable), "-f", str(spec.wave), "-o", str(output)),
            spec.wave.parent, {}, log, inputs=(spec.wave,), outputs=(output,),
        )
        result = runner.run(request, on=on)
        if result.returncode or not _valid_vcd(output):
            raise ValueError(f"fst2vcd conversion failed; log: {log}")
        method = "named-output"
    return output, None, method

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

def _activity_percent(text: str) -> float | None:
    """Return the compact activity-annotation percentage emitted by FlexSoC."""

    match = ACTIVITY_PERCENT_RE.search(text)
    return float(match.group(1)) if match else None

def _power_report_excerpt(text: str, limit: int = 12) -> str:
    """Return compact non-empty report lines for actionable parser errors."""

    lines = [line.strip() for line in text.splitlines() if line.strip()]
    return " | ".join(lines[:limit]) or "<no non-empty lines>"

def _instance_name(prefix: str) -> str:
    """Extract the instance column from one OpenSTA table-row prefix."""

    tokens = prefix.split()
    if tokens and tokens[0].isdigit():
        tokens.pop(0)
    if not tokens:
        return ""
    return tokens[0].rstrip(":")

def _power_instance_rows(path: Path) -> list[dict[str, Any]]:
    """Normalize OpenSTA instance-power JSON, tables, or marked report blocks."""

    try:
        text = path.read_text(encoding="utf-8")
    except OSError as exc:
        raise ValueError(f"cannot read OpenSTA power report {path}: {exc}") from exc
    if not text.strip():
        raise ValueError(f"empty OpenSTA power report: {path}")

    payload: Any = None
    items: list[dict[str, Any]] = []
    if text.lstrip().startswith(("[", "{")):
        try:
            payload = json.loads(text)
        except json.JSONDecodeError as exc:
            raise ValueError(f"invalid OpenSTA power report {path}: {exc}") from exc
        if isinstance(payload, dict):
            for key in ("instances", "power", "data"):
                if isinstance(payload.get(key), list):
                    payload = payload[key]
                    break
            else:
                payload = [
                    {"instance": name, **item}
                    for name, item in payload.items()
                    if isinstance(item, dict)
                ]
        items = [item for item in payload if isinstance(item, dict)] if isinstance(payload, list) else []
    else:
        marker = re.compile(
            r"^===\s+(?:FLEXSOC_)?INSTANCE\s+(.+?)\s+===$",
            re.MULTILINE,
        )
        marked = list(marker.finditer(text))
        for index, match in enumerate(marked):
            block = text[match.end() : marked[index + 1].start() if index + 1 < len(marked) else None]
            total = POWER_RE.search(block)
            if total:
                items.append(
                    {
                        "instance": match.group(1).strip(),
                        "internal": total.group(1),
                        "switching": total.group(2),
                        "leakage": total.group(3),
                        "total": total.group(4),
                    }
                )

        generic_marker = re.compile(
            r"^\s*(?:Power\s+for\s+)?Instance\s*[:=]\s*(\S+)\s*$",
            re.IGNORECASE | re.MULTILINE,
        )
        generic = list(generic_marker.finditer(text))
        for index, match in enumerate(generic):
            block = text[match.end() : generic[index + 1].start() if index + 1 < len(generic) else None]
            total = POWER_RE.search(block)
            if total:
                items.append(
                    {
                        "instance": match.group(1),
                        "internal": total.group(1),
                        "switching": total.group(2),
                        "leakage": total.group(3),
                        "total": total.group(4),
                    }
                )

        numeric = re.compile(FLOAT_RE.pattern)
        for line in text.splitlines():
            tokens = line.split()
            if len(tokens) == 5:
                try:
                    powers = [float(value) for value in tokens[:4]]
                except ValueError:
                    pass
                else:
                    items.append(
                        {
                            "instance": tokens[4],
                            "internal": powers[0],
                            "switching": powers[1],
                            "leakage": powers[2],
                            "total": powers[3],
                        }
                    )
                    continue
            matches = list(numeric.finditer(line))
            if len(matches) < 4:
                continue
            power_matches = matches[-5:-1] if line.rstrip().endswith("%") and len(matches) >= 5 else matches[-4:]
            prefix = line[: power_matches[0].start()].strip()
            name = _instance_name(prefix)
            if not name or name.lower() in {
                "sequential",
                "combinational",
                "macro",
                "pad",
                "total",
                "group",
            }:
                continue
            items.append(
                {
                    "instance": name,
                    "internal": power_matches[0].group(),
                    "switching": power_matches[1].group(),
                    "leakage": power_matches[2].group(),
                    "total": power_matches[3].group(),
                }
            )


    rows: list[dict[str, Any]] = []
    seen: set[str] = set()
    for item in items:
        name = str(item.get("instance", item.get("name", ""))).strip()
        if not name or name in seen:
            continue

        def number(*keys: str) -> float:
            for key in keys:
                value = item.get(key)
                if value is not None:
                    try:
                        return float(value)
                    except (TypeError, ValueError):
                        pass
            return 0.0

        internal = number("internal", "internal_power")
        switching = number("switching", "switching_power")
        leakage = number("leakage", "leakage_power")
        total = number("total", "total_power") or internal + switching + leakage
        rows.append(
            {
                "instance": name,
                "internal": internal,
                "switching": switching,
                "dynamic": internal + switching,
                "leakage": leakage,
                "total": total,
            }
        )
        seen.add(name)
    if not rows:
        raise ValueError(
            f"OpenSTA power report contains no instance rows: {path}; "
            f"excerpt={_power_report_excerpt(text)}"
        )
    return rows

def _power_reports(ctx: SignoffContext, *, activity_coverage: bool) -> list[str]:
    """Append concise public power sections to ``$report``."""

    lines = [
        "flexsoc_section $report Units",
        "# Record the unit system used by the power and activity values below.",
        "flexsoc_append_opensta $report report_units",
        "flexsoc_section $report {Constraint validation}",
        "# Append timing-setup diagnostics because power must use the same correctly linked and constrained design.",
        "flexsoc_append_opensta $report check_setup -verbose",
    ]
    if activity_coverage:
        lines += [
            "flexsoc_section $report {Activity annotation}",
            "# Report annotation coverage as one percentage and list only pins missing direct VCD/SAIF activity.",
            "flexsoc_append_activity_coverage $report",
        ]
    lines += [
        "flexsoc_section $report {Power summary}",
        "# Report average internal, switching, leakage, and total cell power for the complete design.",
        "flexsoc_append_opensta $report report_power",
        'puts "report=$report"',
    ]
    return lines

def render_power_estimate_tcl(ctx: SignoffContext) -> str:
    model = "global" if ctx.global_activity else "input"
    limitations = (
        "This is a vectorless estimate; it does not represent a simulated workload.",
        "Activity is assigned to primary inputs and propagated unless global activity is requested.",
    )
    activity_cmd = "-global" if ctx.global_activity else "-input"
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=False),
            "",
            "# Seed vectorless switching activity on primary inputs (or globally) and let OpenSTA propagate it through the design.",
            f"set_power_activity {activity_cmd} -activity {ctx.estimated_activity} -duty {ctx.estimated_duty}",
            "# Create one compact vectorless power report and record the assumptions used to produce it.",
            "set report [file join $report_dir power.rpt]",
            "set fp [open $report w]",
            'puts $fp "analysis=power_estimate activity_source=input_assumption"',
            f'puts $fp "activity_model={model}"',
            f'puts $fp "activity={ctx.estimated_activity}"',
            f'puts $fp "duty={ctx.estimated_duty}"',
            f'puts $fp "corner={ctx.corner} stage={ctx.stage}"',
            'puts $fp "liberty=$liberty"',
            'puts $fp "netlist=$netlist"',
            'puts $fp "sdc=$sdc"',
            'puts $fp "spef=$spef"',
            "close $fp",
            *_power_reports(ctx, activity_coverage=False),
        ]
    )

def render_power_analysis_tcl(ctx: SignoffContext) -> str:
    limitations = (
        "Power is average cell power derived from the selected Liberty models and annotated activity.",
        "Unannotated objects and scope mismatches remain visible in the activity section.",
    )
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=True),
            "",
            "# Create one compact workload-driven power report after GLS activity has been annotated.",
            "set report [file join $report_dir power.rpt]",
            "set fp [open $report w]",
            f'puts $fp "analysis=power_analysis corner={ctx.corner} stage={ctx.stage}"',
            f'puts $fp "workload={ctx.workload}"',
            f'puts $fp "gls_report={ctx.gls_report or ""}"',
            f'puts $fp "activity_file={ctx.activity_file or ""}"',
            f'puts $fp "activity_scope={ctx.activity_scope}"',
            'puts $fp "liberty=$liberty"',
            'puts $fp "netlist=$netlist"',
            'puts $fp "sdc=$sdc"',
            'puts $fp "spef=$spef"',
            "close $fp",
            *_power_reports(ctx, activity_coverage=True),
        ]
    )

def _annotate_power_summary(report_dir: Path, name: str = "power.rpt") -> None:
    """Append explicit normalized power terminology to one primary report."""

    report = report_dir / name
    if not report.is_file():
        return
    text = report.read_text(encoding="utf-8", errors="replace")
    values = _power_values(text)
    lines = [
        "",
        "=== FlexSoC normalized power fields ===",
        "dynamic_power_definition=internal_power+switching_power",
        "power_unit=OpenSTA report unit; see Units section",
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

def _write_activity_table(
    analysis: str,
    workload_root: Path,
    workload: str,
    corners: Mapping[str, Mapping[str, Any]],
) -> Path:
    """Write one human-readable corner table pointing to the primary reports."""

    def metric(item: Mapping[str, Any], name: str) -> str:
        value = item.get(name)
        return f"{float(value):g}" if isinstance(value, int | float) else "n/a"

    filename = "fusion_table.rpt" if analysis == "fusion_analysis" else "power_table.rpt"
    path = workload_root / filename
    lines = [
        f"analysis={analysis}",
        f"workload={workload}",
        f"report_root={workload_root}",
        "timing_unit=OpenSTA current unit; see each report Units section",
        "power_unit=OpenSTA current unit; see each report Units section",
        "",
    ]
    if analysis == "fusion_analysis":
        lines += [
            "corner/mode status       wns       tns    internal   switching     leakage       total  annotated report",
            "----------- ------ --------- --------- ----------- ----------- ----------- ----------- ---------- ------",
        ]
    else:
        lines += [
            "corner status    internal   switching     leakage       total   coverage report",
            "------ ------ ----------- ----------- ----------- ----------- ---------- ------",
        ]
    for key, item in corners.items():
        raw_report = item.get("report")
        if raw_report:
            report = Path(str(raw_report))
            try:
                report_name = str(report.relative_to(workload_root))
            except ValueError:
                report_name = str(report)
        else:
            report_name = "n/a"
        values = [metric(item, name) for name in ("internal_w", "switching_w", "leakage_w", "total_w")]
        count = item.get("activity_annotation_count")
        percent = item.get("activity_annotation_percent")
        annotated = (
            f"{float(percent):.2f}%"
            if isinstance(percent, int | float)
            else (str(count) if count is not None else "n/a")
        )
        if analysis == "fusion_analysis":
            lines.append(
                f"{key:<11} {str(item.get('status', 'fail')):<6} "
                f"{metric(item, 'wns'):>9} {metric(item, 'tns'):>9} "
                f"{values[0]:>11} {values[1]:>11} {values[2]:>11} {values[3]:>11} "
                f"{annotated:>10} {report_name}"
            )
        else:
            lines.append(
                f"{key:<6} {str(item.get('status', 'fail')):<6} "
                f"{values[0]:>11} {values[1]:>11} {values[2]:>11} {values[3]:>11} "
                f"{annotated:>10} {report_name}"
            )
    return _write(path, "\n".join(lines))

def _enrich_fusion_report(*args, **kwargs):
    """Delegate fusion enrichment without creating an import cycle."""

    from .fusion import _enrich_fusion_report as enrich
    return enrich(*args, **kwargs)


def analyze_activity_spec(
    analysis: str,
    project_root: Path,
    values: Mapping[str, str],
    spec: ActivitySpec,
    *,
    progress_label: str = "",
    runner=None,
    on: str = "local",
) -> dict[str, Any]:
    """Execute one workload-dependent analysis in its aligned sign-off scenario."""

    if analysis not in {"power_analysis", "fusion_analysis"}:
        raise ValueError(f"unsupported activity analysis: {analysis}")
    layout = layout_from_values(project_root, values)
    stage = values.get("SIGNOFF_STAGE", "post_syn")
    root = layout.signoff_stage_root(stage)
    log_root = layout.signoff_stage_log_root(stage)
    activity_args = (spec, values, root / "power" / "activity" / "captures")
    capture, conversion_log, conversion_method = (
        _activity_vcd(*activity_args)
        if runner is None
        else _activity_vcd(*activity_args, runner=runner, on=on)
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
    liberties = _liberties(values)
    configured_corners = _selection(
        values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
    )
    aligned_corner = scenario_corner(spec.mode)
    if aligned_corner not in configured_corners:
        raise ValueError(
            f"GLS timing mode {spec.mode!r} belongs to sign-off scenario "
            f"{aligned_corner!r}, but SIGNOFF_CORNERS={configured_corners}"
        )
    selected_corners = (aligned_corner,)
    modes = (
        _selection(values.get("STA_MODES"), "setup hold", ("setup", "hold"), "STA mode")
        if analysis == "fusion_analysis"
        else ("",)
    )
    if analysis == "power_analysis":
        workload_root = root / "power" / "analysis" / spec.workload
        legacy_root = root / "power" / "analysis" / spec.legacy_workload
        script = root / "power" / "analysis" / "power_analysis.tcl"
        primary_name = "power.rpt"
    else:
        workload_root = root / "fusion" / spec.workload
        legacy_root = root / "fusion" / spec.legacy_workload
        script = root / "fusion" / "fusion_analysis.tcl"
        primary_name = "fusion.rpt"
    # One workload directory represents one aligned PVT scenario.
    # Rebuild it so reruns cannot retain mixed legacy corner naming.
    if workload_root.is_dir():
        shutil.rmtree(workload_root)
    if legacy_root != workload_root and legacy_root.is_dir():
        shutil.rmtree(legacy_root)
    total_runs = len(selected_corners) * len(modes)
    run_index = 0
    if progress_label:
        print(
            f"[{progress_label}] activity={capture} scope={scope} "
            f"scenario={aligned_corner}/{spec.mode} runs={total_runs}",
            flush=True,
        )
    for corner in selected_corners:
        liberty = liberties[corner]
        for mode in modes:
            run_index += 1
            if analysis == "power_analysis":
                report_dir = workload_root
                log = log_root / "power" / "analysis" / spec.workload / f"{spec.top}.log"
                key = corner
            else:
                report_dir = workload_root / mode
                log = log_root / "fusion" / spec.workload / mode / f"{spec.top}.log"
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
            if progress_label:
                print(
                    f"[{progress_label}] run {run_index}/{total_runs} START "
                    f"workload={spec.workload} corner={corner} mode={mode or 'n/a'}",
                    flush=True,
                )
            try:
                execute_kwargs = dict(
                    analysis=analysis, ctx=ctx, script=script, log=log
                )
                if runner is not None:
                    execute_kwargs.update({"runner": runner, "on": on})
                rc = _execute_script(project_root, values, **execute_kwargs)
                text = log.read_text(encoding="utf-8", errors="replace") if log.is_file() else ""
                primary = report_dir / primary_name
                fusion_details: dict[str, Any] = {}
                if analysis == "fusion_analysis":
                    fusion_details = _enrich_fusion_report(
                        project_root,
                        values,
                        ctx,
                        log,
                        progress_label=progress_label,
                        run_index=run_index,
                        total_runs=total_runs,
                    )
                report_text = primary.read_text(encoding="utf-8", errors="replace")
                numbers = _power_values(report_text) or _power_values(text)
                annotated = _activity_count(report_text)
                if annotated is None:
                    annotated = _activity_count(text)
                annotation_percent = _activity_percent(report_text)
                has_activity = (
                    annotation_percent > 0.0
                    if annotation_percent is not None
                    else (annotated > 0 if annotated is not None else None)
                )
                ok = rc == 0 and has_activity is not False
                corners[key] = {
                    "status": "pass" if ok else "fail",
                    "returncode": rc,
                    "liberty": str(liberty),
                    "script": str(script),
                    "log": str(log),
                    "report": str(primary),
                    "activity_annotation_count": annotated,
                    "activity_annotation_percent": annotation_percent,
                    **(_timing_values(report_text) if analysis == "fusion_analysis" else {}),
                    **fusion_details,
                    **numbers,
                }
                if ok:
                    if progress_label:
                        print(
                            f"[{progress_label}] run {run_index}/{total_runs} PASS "
                            f"report={primary}",
                            flush=True,
                        )
                    if analysis == "fusion_analysis":
                        print(f"[report] {key} {primary}", flush=True)
                else:
                    reason = (
                        f"OpenSTA {_returncode_text(rc)}"
                        if rc
                        else "OpenSTA annotated zero activity"
                    )
                    failures.append(f"{key}: {reason}")
                    if progress_label:
                        print(
                            f"[{progress_label}] run {run_index}/{total_runs} FAIL "
                            f"reason={reason} log={log}",
                            flush=True,
                        )
            except (OSError, ValueError, subprocess.SubprocessError) as exc:
                failures.append(f"{key}: {exc}")
                corners[key] = {"status": "fail", "reason": str(exc)}
                if progress_label:
                    print(
                        f"[{progress_label}] run {run_index}/{total_runs} FAIL "
                        f"reason={exc} log={log}",
                        flush=True,
                    )
    table = _write_activity_table(analysis, workload_root, spec.workload, corners)
    return {
        "schema_version": 4,
        "analysis": analysis,
        "status": "pass" if corners and not failures else "fail",
        "top": spec.top,
        "pdk": spec.pdk,
        "test": spec.test,
        "backend": spec.backend,
        "timing_mode": spec.mode,
        "scenario": {"corner": aligned_corner, "sdf_mode": spec.mode},
        "workload": spec.workload,
        "activity_source": (
            "post_pnr_gls_vcd"
            if values.get("SIGNOFF_STAGE") == "post_route"
            else "post_syn_gls_vcd"
        ),
        "scope_requested": requested_scope,
        "scope": scope,
        "vcd_scopes": list(scopes),
        "source_gls_report": str(spec.report),
        "source_wave": str(spec.wave),
        "activity_file": str(capture),
        "conversion_method": conversion_method,
        "conversion_log": str(conversion_log) if conversion_log and conversion_log.is_file() else None,
        "table": str(table),
        "corners": corners,
        "failures": failures,
    }

def execute_activity(
    analysis: str,
    action: str,
    project_root: Path,
    values: Mapping[str, str],
    *,
    runner=None,
    on: str = "local",
) -> int:
    specs = discover_specs(action, values, project_root)
    label = f"{analysis}_all" if action == "all" else analysis
    reports: list[dict[str, Any]] = []
    print(f"[{label}] workloads={len(specs)}", flush=True)
    for index, spec in enumerate(specs, 1):
        print(
            f"[{label}] workload {index}/{len(specs)} START "
            f"test={spec.test} backend={spec.backend} timing={spec.mode} "
            f"name={spec.workload}",
            flush=True,
        )
        try:
            kwargs = {"progress_label": label}
            if runner is not None:
                kwargs.update({"runner": runner, "on": on})
            report = analyze_activity_spec(analysis, project_root, values, spec, **kwargs)
        except (OSError, ValueError, subprocess.SubprocessError) as exc:
            report = {"status": "fail", "spec": spec.stem, "reason": str(exc)}
        reports.append(report)
        passed_now = sum(item.get("status") == "pass" for item in reports)
        print(
            f"[{label}] workload {index}/{len(specs)} "
            f"{str(report.get('status', 'fail')).upper()} "
            f"progress={index}/{len(specs)} passed={passed_now} failed={index - passed_now}"
            + (f" table={report['table']}" if report.get("table") else ""),
            flush=True,
        )
        if report.get("table"):
            print(
                f"[report] workload={report.get('workload')} table={report['table']}",
                flush=True,
            )
    passed = sum(report.get("status") == "pass" for report in reports)
    layout = layout_from_values(project_root, values)
    root = layout.signoff_stage_root(values.get("SIGNOFF_STAGE", "post_syn"))
    summary_root = root / "power" / "analysis" if analysis == "power_analysis" else root / "fusion"
    legacy = summary_root / "reports"
    if legacy.is_dir():
        shutil.rmtree(legacy)
    summary = {
        "schema_version": 4,
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
    print(f"[{label}] {passed}/{len(reports)} PASS", flush=True)
    print(f"[report] machine_summary={summary_path}", flush=True)
    return 0 if reports and passed == len(reports) else 2


@dataclass(slots=True)
class PowerAnalysis:
    """Run vectorless or workload-driven power for one sign-off stage."""

    project_root: Path
    values: Mapping[str, str]
    runner: object | None = None

    def setup_estimate(self) -> Path:
        """Generate only the vectorless power Tcl template."""

        from .sta import generate_family
        return generate_family(self.project_root, self.values, "power_estimate")

    def setup_activity(self) -> Path:
        """Generate only the activity-power Tcl template."""

        from .sta import generate_family
        return generate_family(self.project_root, self.values, "power_analysis")

    def estimate(self, *, on: str = "local") -> int:
        """Run vectorless power over configured corners."""

        from .sta import execute_static
        return execute_static(
            "power_estimate", self.project_root, self.values, runner=self.runner, on=on
        )

    def activity(self, *, all_workloads: bool = False, on: str = "local") -> int:
        """Run one or all qualified GLS activity analyses."""

        return execute_activity(
            "power_analysis",
            "all" if all_workloads else "run",
            self.project_root,
            self.values,
            runner=self.runner,
            on=on,
        )
