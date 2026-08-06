"""Generate and execute FlexSoC OpenSTA sign-off analyses.

The Makefile remains the public orchestrator.  This module resolves technology
inputs, writes self-contained Tcl, executes OpenSTA, and validates the produced
reports for STA, vectorless power estimation, activity-based power, and
workload-aware timing/power fusion.  EQY lives in :mod:`setup_eqy`.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import signal
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
WNS_RE = re.compile(r"^\s*wns(?:\s+\w+)?\s+([-+0-9.eE]+)\s*$", re.IGNORECASE | re.MULTILINE)
TNS_RE = re.compile(r"^\s*tns(?:\s+\w+)?\s+([-+0-9.eE]+)\s*$", re.IGNORECASE | re.MULTILINE)
COMPLETE_PREFIX = "FLEXSOC_SIGNOFF_COMPLETE"


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
    power_top_instances: int = 20


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


def _selection(
    value: str | None, default: str, allowed: Sequence[str], label: str
) -> tuple[str, ...]:
    selected = _split(value or default)
    if not selected:
        raise ValueError(f"{label} must select at least one value")
    unknown = tuple(item for item in selected if item not in allowed)
    if unknown:
        raise ValueError(f"unsupported {label}: {unknown}; allowed={tuple(allowed)}")
    if len(set(selected)) != len(selected):
        raise ValueError(f"duplicate {label}: {selected}")
    return selected


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
    return output, None, method


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


def _returncode_text(returncode: int) -> str:
    if returncode >= 0:
        return f"exit {returncode}"
    number = -returncode
    try:
        name = signal.Signals(number).name
    except ValueError:
        name = "UNKNOWN"
    return f"signal {number} ({name})"


def _activity_count(text: str) -> int | None:
    """Return OpenSTA's annotated-activity count when the version reports one."""

    match = ACTIVITY_RE.search(text)
    return int(match.group(1)) if match else None


def _timing_values(text: str) -> dict[str, float]:
    """Extract public ``report_wns``/``report_tns`` values when available."""

    values: dict[str, float] = {}
    for name, pattern in (("wns", WNS_RE), ("tns", TNS_RE)):
        match = pattern.search(text)
        if match:
            values[name] = float(match.group(1))
    return values

FLOAT_RE = re.compile(r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?")
PATH_START_RE = re.compile(r"(?=^Startpoint:)", re.MULTILINE)
PATH_PIN_RE = re.compile(r"^\s*(.*?)\s+([\^v])?\s*(\S+)\s+\(([^)]+)\)\s*$")
PATH_SLACK_RE = re.compile(
    r"^\s*(%s)\s+slack\s+\((MET|VIOLATED)\)" % FLOAT_RE.pattern,
    re.MULTILINE,
)


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


def _power_instance_rows(path: Path, *, names_only_ok: bool = False) -> list[dict[str, Any]]:
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

        if not items and names_only_ok:
            excluded = {
                "group",
                "instance",
                "internal",
                "switching",
                "leakage",
                "total",
                "power",
                "sequential",
                "combinational",
                "macro",
                "pad",
            }
            for line in text.splitlines():
                stripped = line.strip().strip(":")
                if not stripped or set(stripped) <= {"-", "="}:
                    continue
                tokens = stripped.split()
                if tokens and tokens[0].isdigit():
                    tokens.pop(0)
                if len(tokens) != 1 or tokens[0].lower() in excluded:
                    continue
                if re.fullmatch(r"[A-Za-z_\\][A-Za-z0-9_.$/\\\[\]:-]*", tokens[0]):
                    items.append({"instance": tokens[0]})

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


def _timing_path_blocks(text: str) -> list[dict[str, Any]]:
    """Parse public ``report_checks`` text into paths and gate stages."""

    paths: list[dict[str, Any]] = []
    for block in PATH_START_RE.split(text):
        if not block.startswith("Startpoint:"):
            continue
        slack_match = PATH_SLACK_RE.search(block)
        if not slack_match:
            continue
        header: dict[str, str] = {}
        for key in ("Startpoint", "Endpoint", "Path Group", "Path Type"):
            match = re.search(rf"^{re.escape(key)}:\s*(.+)$", block, re.MULTILINE)
            header[key] = match.group(1).strip() if match else ""
        data = block.split("data arrival time", 1)[0]
        stages: list[dict[str, Any]] = []
        for line in data.splitlines():
            match = PATH_PIN_RE.match(line)
            if not match:
                continue
            prefix, _edge, pin, cell = match.groups()
            if "/" not in pin:
                continue
            numbers = [float(value) for value in FLOAT_RE.findall(prefix)]
            if not numbers:
                continue
            instance = pin.rsplit("/", 1)[0]
            if cell == "net":
                if stages and len(numbers) >= 2:
                    stages[-1]["fanout"], stages[-1]["capacitance"] = numbers[-2:]
                continue
            values: dict[str, float | None] = {
                "fanout": None,
                "capacitance": None,
                "slew": None,
                "delay": None,
                "arrival": None,
            }
            if len(numbers) >= 5:
                values.update(zip(values, numbers[-5:]))
            elif len(numbers) >= 3:
                values.update({"slew": numbers[-3], "delay": numbers[-2], "arrival": numbers[-1]})
            elif len(numbers) >= 2:
                values.update({"delay": numbers[-2], "arrival": numbers[-1]})
            if stages and stages[-1]["instance"] == instance:
                stage = stages[-1]
                stage["pins"].append(pin.rsplit("/", 1)[1])
                stage["cell"] = cell
                for key, value in values.items():
                    if value is not None:
                        stage[key] = value
            else:
                stages.append(
                    {
                        "instance": instance,
                        "cell": cell,
                        "pins": [pin.rsplit("/", 1)[1]],
                        **values,
                    }
                )
        paths.append(
            {
                "startpoint": header["Startpoint"],
                "endpoint": header["Endpoint"],
                "group": header["Path Group"],
                "type": header["Path Type"],
                "slack": float(slack_match.group(1)),
                "status": slack_match.group(2).lower(),
                "stages": stages,
                "raw": block.rstrip(),
            }
        )
    return paths


def _sta_pattern(name: str) -> str:
    """Escape one exact hierarchical name for OpenSTA collection patterns."""

    return re.sub(r"([\\*?\[\]])", r"\\\1", name)


def _fusion_detail_tcl(
    ctx: SignoffContext,
    instances: Sequence[str],
    hotspots: Sequence[str],
) -> tuple[str, str]:
    """Render a second public-API pass for instance power and hotspot paths."""

    delay_type = "min" if ctx.mode == "hold" else "max"
    marker = (
        f"FLEXSOC_FUSION_DETAIL_COMPLETE corner={ctx.corner} "
        f"mode={ctx.mode} workload={ctx.workload}"
    )
    instance_names = " ".join(_quote(name) for name in instances)
    instance_patterns = " ".join(_quote(_sta_pattern(name)) for name in instances)
    lines = [
        _header(
            ctx,
            (
                "This transient pass reports only selected path and hotspot instances.",
                "Only public report_power/report_checks collection commands are used.",
            ),
        ),
        _common_init(ctx, activity=True),
        "",
        f"set delay_type {delay_type}",
        f"set instance_names [list {instance_names}]",
        f"set instance_patterns [list {instance_patterns}]",
        "set instance_report [file join $report_dir .instance_power.rpt]",
        "set fp [open $instance_report w]",
        'puts $fp "# FlexSoC marked OpenSTA instance-power blocks"',
        "close $fp",
        "foreach instance_name $instance_names instance_pattern $instance_patterns {",
        "  set instances [get_cells [list $instance_pattern]]",
        "  set fp [open $instance_report a]",
        '  puts $fp "=== FLEXSOC_INSTANCE $instance_name ==="',
        "  close $fp",
        "  if {[llength $instances] == 1} {",
        "    report_power -instances $instances -digits 12 >> $instance_report",
        "  } else {",
        "    set fp [open $instance_report a]",
        '    puts $fp "instance_lookup_count=[llength $instances]"',
        "    close $fp",
        "  }",
        "}",
        "set hotspot_report [file join $report_dir .hotspot_paths.rpt]",
        "set hp [open $hotspot_report w]",
        'puts $hp "analysis=fusion_hotspot_paths"',
        "close $hp",
    ]
    for rank, name in enumerate(hotspots, 1):
        lines.extend(
            (
                "set hp [open $hotspot_report a]",
                f"puts $hp {_quote(f'=== HOTSPOT rank={rank} instance={name} ===')}",
                "close $hp",
                f"set pins [get_pins [list {_quote(_sta_pattern(name) + '/*')}]]",
                "if {[llength $pins] == 0} {",
                "  set hp [open $hotspot_report a]",
                '  puts $hp "targeted_timing_path=instance_pins_not_found"',
                "  close $hp",
                "} else {",
                (
                    "  report_checks -through $pins -path_delay $delay_type "
                    "-group_path_count 1 -endpoint_path_count 1 -sort_by_slack "
                    "-format full_clock_expanded "
                    "-fields {slew capacitance input_pin net fanout} -digits 6 "
                    ">> $hotspot_report"
                ),
                "}",
            )
        )
    lines.append(f"puts {_quote(marker)}")
    return "\n".join(lines), marker


def _fusion_power_tcl(
    ctx: SignoffContext,
    instances: Sequence[str],
) -> tuple[str, str]:
    """Render one transient public power query for additional path instances."""

    marker = (
        f"FLEXSOC_FUSION_POWER_COMPLETE corner={ctx.corner} "
        f"mode={ctx.mode} workload={ctx.workload}"
    )
    instance_names = " ".join(_quote(name) for name in instances)
    instance_patterns = " ".join(_quote(_sta_pattern(name)) for name in instances)
    return "\n".join(
        (
            _header(
                ctx,
                ("This transient pass reports power only for newly discovered path instances.",),
            ),
            _common_init(ctx, activity=True),
            f"set instance_names [list {instance_names}]",
            f"set instance_patterns [list {instance_patterns}]",
            "set instance_report [file join $report_dir .additional_power.rpt]",
            "set fp [open $instance_report w]",
            'puts $fp "# FlexSoC marked OpenSTA instance-power blocks"',
            "close $fp",
            "foreach instance_name $instance_names instance_pattern $instance_patterns {",
            "  set instances [get_cells [list $instance_pattern]]",
            "  set fp [open $instance_report a]",
            '  puts $fp "=== FLEXSOC_INSTANCE $instance_name ==="',
            "  close $fp",
            "  if {[llength $instances] == 1} {",
            "    report_power -instances $instances -digits 12 >> $instance_report",
            "  } else {",
            "    set fp [open $instance_report a]",
            '    puts $fp "instance_lookup_count=[llength $instances]"',
            "    close $fp",
            "  }",
            "}",
            f"puts {_quote(marker)}",
        )
    ), marker


def _format_number(value: Any) -> str:
    return "-" if value is None else f"{float(value):.6g}"


def _path_fusion_lines(
    title: str,
    path: Mapping[str, Any],
    powers: Mapping[str, Mapping[str, Any]],
) -> list[str]:
    """Return one gate-by-gate timing/power table."""

    stages = path.get("stages", [])
    unique = {str(stage.get("instance", "")) for stage in stages}
    missing = sorted(name for name in unique if name not in powers)
    totals = {
        key: sum(float(powers.get(name, {}).get(key, 0.0)) for name in unique)
        for key in ("internal", "switching", "dynamic", "leakage", "total")
    }
    lines = [
        f"{title}: status={path.get('status')} slack={_format_number(path.get('slack'))} "
        f"type={path.get('type')} group={path.get('group')}",
        f"startpoint={path.get('startpoint')}",
        f"endpoint={path.get('endpoint')}",
        f"path_power_complete={'false' if missing else 'true'}"
        + (f" missing_power_instances={','.join(missing)}" if missing else ""),
        "path_average_power_sum "
        + " ".join(f"{key}={_format_number(value)}" for key, value in totals.items()),
        (
            "stage instance cell pins fanout capacitance slew delay arrival "
            "internal switching dynamic leakage total"
        ),
    ]
    for stage_index, stage in enumerate(stages, 1):
        power = powers.get(str(stage.get("instance", "")), {})
        lines.append(
            " ".join(
                (
                    str(stage_index),
                    str(stage.get("instance", "")),
                    str(stage.get("cell", "")),
                    ",".join(str(pin) for pin in stage.get("pins", [])),
                    _format_number(stage.get("fanout")),
                    _format_number(stage.get("capacitance")),
                    _format_number(stage.get("slew")),
                    _format_number(stage.get("delay")),
                    _format_number(stage.get("arrival")),
                    *(
                        _format_number(power.get(key))
                        for key in ("internal", "switching", "dynamic", "leakage", "total")
                    ),
                )
            )
        )
    return lines


def _hotspot_path_blocks(text: str) -> dict[str, dict[str, Any]]:
    """Parse the single worst public timing report emitted for each hotspot."""

    paths: dict[str, dict[str, Any]] = {}
    for block in re.split(r"(?=^=== HOTSPOT rank=)", text, flags=re.MULTILINE):
        marker = re.match(r"^=== HOTSPOT rank=\d+ instance=(.+?) ===", block)
        if not marker:
            continue
        parsed = _timing_path_blocks(block)
        if parsed:
            paths[marker.group(1)] = min(parsed, key=lambda path: float(path["slack"]))
    return paths


def _append_fusion_tables(
    report: Path,
    paths: Sequence[Mapping[str, Any]],
    powers: Mapping[str, Mapping[str, Any]],
    hotspots: Sequence[Mapping[str, Any]],
    hotspot_paths: Mapping[str, Mapping[str, Any]],
) -> None:
    """Append complete path tables and reverse hotspot-to-path lookup."""

    lines = [
        "",
        "=== Gate-level timing/power fusion ===",
        "power_semantics=average_instance_power_from_the_same_VCD_SAIF_context",
        "path_power_sum=unique_instance_average_power_sum_not_incremental_path_energy",
        "fanout_capacitance_source=OpenSTA_report_checks_output_pin_fields",
        "",
    ]
    for index, path in enumerate(paths, 1):
        lines.extend(_path_fusion_lines(f"Worst path {index}", path, powers))
        lines.append("")
    lines.extend(("=== Highest-power instances and worst path through each ===", ""))
    for rank, hotspot in enumerate(hotspots, 1):
        name = str(hotspot.get("instance", ""))
        memberships = sorted(
            {
                index
                for index, path in enumerate(paths, 1)
                if any(stage.get("instance") == name for stage in path.get("stages", []))
            }
        )
        lines.append(
            (
                f"Hotspot {rank}: instance={name} "
                f"selected_worst_paths={','.join(map(str, memberships)) or 'none'} "
            )
            + " ".join(
                f"{key}={_format_number(hotspot.get(key))}"
                for key in ("internal", "switching", "dynamic", "leakage", "total")
            )
        )
        targeted = hotspot_paths.get(name)
        if targeted:
            lines.extend(_path_fusion_lines("Worst path through hotspot", targeted, powers))
            lines.extend(("OpenSTA targeted timing report:", str(targeted.get("raw", ""))))
        else:
            lines.append("targeted_timing_path=not_found_or_unconstrained")
        lines.append("")
    report.write_text(
        report.read_text(encoding="utf-8").rstrip()
        + "\n"
        + "\n".join(lines).rstrip()
        + "\n",
        encoding="utf-8",
    )


def _enrich_fusion_report(
    project_root: Path,
    values: Mapping[str, str],
    ctx: SignoffContext,
    log: Path,
    *,
    progress_label: str,
    run_index: int,
    total_runs: int,
) -> dict[str, Any]:
    """Correlate worst paths and power hotspots using public OpenSTA commands."""

    report = ctx.report_dir / "fusion.rpt"
    paths = _timing_path_blocks(report.read_text(encoding="utf-8", errors="replace"))
    if not paths:
        raise ValueError(
            f"fusion discovery found no constrained timing paths; report={report}"
        )
    hotspots = _power_instance_rows(
        ctx.report_dir / ".highest_power.rpt", names_only_ok=True
    )
    if ctx.power_top_instances > 0 and not hotspots:
        raise ValueError(
            "fusion discovery found no instance-power rows; "
            f"report={ctx.report_dir / '.highest_power.rpt'}"
        )
    initial_instances = sorted(
        {
            str(stage.get("instance", ""))
            for path in paths
            for stage in path.get("stages", [])
            if stage.get("instance")
        }
        | {str(row["instance"]) for row in hotspots}
    )
    if progress_label:
        print(
            f"[{progress_label}] run {run_index}/{total_runs} DISCOVERY PASS "
            f"paths={len(paths)} path_instances={len(initial_instances)} hotspots={len(hotspots)}",
            flush=True,
        )
        print(
            f"[{progress_label}] run {run_index}/{total_runs} HOTSPOT TIMING START "
            f"hotspots={len(hotspots)}",
            flush=True,
        )
    detail_script = ctx.report_dir / ".fusion_detail.tcl"
    detail_log = log.with_name(f"{log.stem}_detail{log.suffix}")
    script_text, marker = _fusion_detail_tcl(
        ctx,
        initial_instances,
        [str(row["instance"]) for row in hotspots],
    )
    _write(detail_script, script_text)
    rc = _run_sta(
        [values.get("STA", "sta"), "-exit", "-no_init", str(detail_script)],
        cwd=project_root,
        log=detail_log,
    )
    transcript = detail_log.read_text(encoding="utf-8", errors="replace") if detail_log.is_file() else ""
    if rc or marker not in transcript:
        raise ValueError(
            f"fusion detail pass failed with {_returncode_text(rc)}; log={detail_log}"
            if rc
            else f"fusion detail pass ended before completion marker; log={detail_log}"
        )
    power_rows = _power_instance_rows(ctx.report_dir / ".instance_power.rpt")
    power_map = {str(row["instance"]): row for row in power_rows}
    hotspots = [power_map.get(str(row["instance"]), row) for row in hotspots]
    hotspot_paths = _hotspot_path_blocks(
        (ctx.report_dir / ".hotspot_paths.rpt").read_text(
            encoding="utf-8", errors="replace"
        )
    )
    if progress_label:
        print(
            f"[{progress_label}] run {run_index}/{total_runs} HOTSPOT TIMING PASS "
            f"targeted_paths={len(hotspot_paths)} log={detail_log}",
            flush=True,
        )
    target_instances = {
        str(stage.get("instance", ""))
        for path in hotspot_paths.values()
        for stage in path.get("stages", [])
        if stage.get("instance")
    }
    additional = sorted(target_instances - power_map.keys())
    power_log: Path | None = None
    power_script: Path | None = None
    if additional:
        if progress_label:
            print(
                f"[{progress_label}] run {run_index}/{total_runs} POWER EXTEND START "
                f"instances={len(additional)}",
                flush=True,
            )
        power_script = ctx.report_dir / ".fusion_power.tcl"
        power_log = log.with_name(f"{log.stem}_power{log.suffix}")
        power_text, power_marker = _fusion_power_tcl(ctx, additional)
        _write(power_script, power_text)
        rc = _run_sta(
            [values.get("STA", "sta"), "-exit", "-no_init", str(power_script)],
            cwd=project_root,
            log=power_log,
        )
        transcript = power_log.read_text(encoding="utf-8", errors="replace") if power_log.is_file() else ""
        if rc or power_marker not in transcript:
            raise ValueError(
                f"fusion power extension failed with {_returncode_text(rc)}; log={power_log}"
                if rc
                else f"fusion power extension ended before completion marker; log={power_log}"
            )
        for row in _power_instance_rows(ctx.report_dir / ".additional_power.rpt"):
            power_map[str(row["instance"])] = row
        if progress_label:
            print(
                f"[{progress_label}] run {run_index}/{total_runs} POWER EXTEND PASS "
                f"instances={len(additional)} log={power_log}",
                flush=True,
            )
    _append_fusion_tables(report, paths, power_map, hotspots, hotspot_paths)
    for artifact in (
        ctx.report_dir / ".highest_power.rpt",
        ctx.report_dir / ".instance_power.rpt",
        ctx.report_dir / ".additional_power.rpt",
        ctx.report_dir / ".hotspot_paths.rpt",
        detail_script,
        power_script,
    ):
        if artifact is not None:
            artifact.unlink(missing_ok=True)
    if progress_label:
        print(
            f"[{progress_label}] run {run_index}/{total_runs} FUSION PASS "
            f"worst_paths={len(paths)} hotspot_paths={len(hotspot_paths)} report={report}",
            flush=True,
        )
    return {
        "timing_path_count": len(paths),
        "path_instance_count": len(power_map),
        "power_hotspot_count": len(hotspots),
        "hotspot_path_count": len(hotspot_paths),
        "detail_log": str(detail_log),
        "power_detail_log": str(power_log) if power_log else None,
    }


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
        "# Generated baseline: review or edit as needed; regeneration replaces this file.",
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
        "proc flexsoc_section {path title} {",
        "  set fp [open $path a]",
        '  puts $fp ""',
        '  puts $fp "=== $title ==="',
        "  close $fp",
        "}",
        "proc flexsoc_label {path label} {",
        "  set fp [open $path a]",
        '  puts -nonewline $fp "$label "',
        "  close $fp",
        "}",
        "",
        'puts "=== Step 6/7: Validate timing setup ==="',
        "check_setup -verbose",
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
    """Render one concise timing report for a concrete corner and mode."""

    delay_type = "min" if ctx.mode == "hold" else "max"
    threshold = ctx.near_critical_hold if ctx.mode == "hold" else ctx.near_critical_setup
    limitations = (
        "Violating, near-critical and unconstrained paths are separate sections of one report.",
        "Post-synthesis capacitance excludes routed parasitics unless an explicit SPEF is supplied.",
    )
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=False),
            "",
            f"set delay_type {delay_type}",
            f"set endpoint_group_limit {ctx.endpoint_group_limit}",
            f"set endpoint_path_limit {ctx.endpoint_path_limit}",
            f"set near_critical_limit {threshold:.6f}",
            "set report [file join $report_dir timing.rpt]",
            "set fp [open $report w]",
            f'puts $fp "analysis=sta corner={ctx.corner} mode={ctx.mode} stage={ctx.stage}"',
            'puts $fp "liberty=$liberty"',
            'puts $fp "netlist=$netlist"',
            'puts $fp "sdc=$sdc"',
            'puts $fp "spef=$spef"',
            "close $fp",
            "flexsoc_section $report Units",
            "sta::redirect_file_append_begin $report",
            "report_units",
            "sta::redirect_file_end",
            "flexsoc_section $report {Timing summary}",
            'flexsoc_label $report "wns $delay_type"',
            "sta::redirect_file_append_begin $report",
            "report_wns -$delay_type",
            "sta::redirect_file_end",
            'flexsoc_label $report "tns $delay_type"',
            "sta::redirect_file_append_begin $report",
            "report_tns -$delay_type",
            "sta::redirect_file_end",
            "flexsoc_section $report {Constraint validation}",
            "sta::redirect_file_append_begin $report",
            "check_setup -verbose",
            "report_check_types -max_slew -max_capacitance -max_fanout -recovery -removal -min_pulse_width -min_period -min_delay -max_delay",
            "sta::redirect_file_end",
            "flexsoc_section $report {Violating paths}",
            "report_checks -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count $endpoint_path_limit -unique_paths_to_endpoint -sort_by_slack -slack_max 0.0 -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6 >> $report",
            "flexsoc_section $report {Near-critical paths}",
            "report_checks -path_delay $delay_type -group_path_count 3000 -endpoint_path_count 3 -unique_paths_to_endpoint -sort_by_slack -slack_min 0.0 -slack_max $near_critical_limit -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6 >> $report",
            "flexsoc_section $report {Unconstrained paths}",
            "report_checks -unconstrained -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count 1 -sort_by_slack -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6 >> $report",
            'puts "report=$report"',
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
    """Append concise public power sections to ``$report``."""

    return [
        "flexsoc_section $report Units",
        "sta::redirect_file_append_begin $report",
        "report_units",
        "sta::redirect_file_end",
        "flexsoc_section $report {Constraint validation}",
        "check_setup -verbose >> $report",
        "flexsoc_section $report {Activity annotation}",
        "report_activity_annotation -report_annotated -report_unannotated >> $report",
        "flexsoc_section $report {Power summary}",
        "report_power >> $report",
        "flexsoc_section $report {Highest-power instances}",
        f"report_power -highest_power_instances {ctx.power_top_instances} >> $report",
        'puts "report=$report"',
    ]

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
            f"set_power_activity {activity_cmd} -activity {ctx.estimated_activity} -duty {ctx.estimated_duty}",
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
            *_power_reports(ctx),
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
            *_power_reports(ctx),
        ]
    )

def render_fusion_analysis_tcl(ctx: SignoffContext) -> str:
    """Render discovery reports used by public-API timing/power fusion."""

    delay_type = "min" if ctx.mode == "hold" else "max"
    limitations = (
        "Timing and average power use the same netlist, corner, mode and activity trace.",
        "Per-cell values are average instance power, not incremental path energy.",
    )
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=True),
            "",
            f"set delay_type {delay_type}",
            f"set endpoint_path_limit {ctx.endpoint_path_limit}",
            "set report [file join $report_dir fusion.rpt]",
            "set fp [open $report w]",
            f'puts $fp "analysis=fusion_analysis corner={ctx.corner} mode={ctx.mode} stage={ctx.stage}"',
            f'puts $fp "workload={ctx.workload}"',
            'puts $fp "methodology=staged_public_opensta"',
            'puts $fp "path_power_semantics=average_instance_power_in_same_analysis_context"',
            f'puts $fp "activity_file={ctx.activity_file or ""}"',
            f'puts $fp "activity_scope={ctx.activity_scope}"',
            'puts $fp "liberty=$liberty"',
            'puts $fp "netlist=$netlist"',
            'puts $fp "sdc=$sdc"',
            'puts $fp "spef=$spef"',
            "close $fp",
            "flexsoc_section $report Units",
            "sta::redirect_file_append_begin $report",
            "report_units",
            "sta::redirect_file_end",
            "flexsoc_section $report {Constraint validation}",
            "check_setup -verbose >> $report",
            "flexsoc_section $report {Timing summary}",
            'flexsoc_label $report "wns $delay_type"',
            "sta::redirect_file_append_begin $report",
            "report_wns -$delay_type",
            "sta::redirect_file_end",
            'flexsoc_label $report "tns $delay_type"',
            "sta::redirect_file_append_begin $report",
            "report_tns -$delay_type",
            "sta::redirect_file_end",
            "flexsoc_section $report {Power summary}",
            "report_power >> $report",
            "flexsoc_section $report {Worst timing paths (violated or met)}",
            (
                "report_checks -path_delay $delay_type "
                "-group_path_count $endpoint_path_limit -endpoint_path_count 1 "
                "-unique_paths_to_endpoint -sort_by_slack "
                "-format full_clock_expanded "
                "-fields {slew capacitance input_pin net fanout} -digits 6 >> $report"
            ),
            (
                f"report_power -highest_power_instances {ctx.power_top_instances} "
                "-digits 12 > [file join $report_dir .highest_power.rpt]"
            ),
            'puts "report=$report"',
        ]
    )

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
        power_top_instances=int(values.get("POWER_TOP_INSTANCES", "20")),
    )


def _completion_marker(ctx: SignoffContext) -> str:
    return (
        f"{COMPLETE_PREFIX} analysis={ctx.analysis} corner={ctx.corner} "
        f"mode={ctx.mode or 'n/a'} workload={ctx.workload or 'n/a'}"
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
        script = renderers[analysis](ctx)
    except KeyError as exc:
        raise ValueError(f"unsupported sign-off analysis: {analysis}") from exc
    return script.rstrip() + f"\nputs {_quote(_completion_marker(ctx))}\n"


def generate_families(project_root: Path, values: Mapping[str, str]) -> tuple[Path, ...]:
    """Generate the four public Tcl families plus SDF under one PDK branch."""

    layout = layout_from_values(project_root, values)
    liberties = _liberties(values)
    corner = "tt" if "tt" in liberties else next(iter(liberties))
    liberty = liberties[corner]
    root = layout.signoff_pdk_root
    generated: list[tuple[Path, SignoffContext]] = []
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
        generated.append((_write(path, _render(analysis, ctx)), ctx))
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
        generated.append((_write(path, _render(analysis, ctx)), ctx))
    for path, ctx in generated:
        print_script(
            path,
            details={
                "analysis": ctx.analysis,
                "stage": ctx.stage,
                "corner": ctx.corner,
                "mode": ctx.mode or "n/a",
                "workload": ctx.workload or "template",
                "liberty": ctx.liberty.name,
            },
        )
    return tuple(path for path, _ in generated)


def _required_reports(analysis: str, ctx: SignoffContext) -> tuple[Path, ...]:
    names = {
        "sta": ("timing.rpt",),
        "power_estimate": ("power.rpt",),
        "power_analysis": ("power.rpt",),
        "fusion_analysis": ("fusion.rpt",),
        "sdf": (f"{ctx.top}_{ctx.corner}.sdf",),
    }
    try:
        selected = names[analysis]
    except KeyError as exc:
        raise ValueError(f"unsupported analysis: {analysis}") from exc
    return tuple(ctx.report_dir / name for name in selected)

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

    if ctx.report_dir.is_symlink() or ctx.report_dir.is_file():
        ctx.report_dir.unlink()
    elif ctx.report_dir.exists():
        shutil.rmtree(ctx.report_dir)
    ctx.report_dir.mkdir(parents=True)
    _write(script, _render(analysis, ctx))
    print_script(
        script,
        details={
            "analysis": analysis,
            "stage": ctx.stage,
            "corner": ctx.corner,
            "mode": ctx.mode or "n/a",
            "workload": ctx.workload or "n/a",
            "liberty": ctx.liberty.name,
            "report_dir": ctx.report_dir,
        },
    )
    rc = _run_sta(
        [values.get("STA", "sta"), "-exit", "-no_init", str(script)],
        cwd=project_root,
        log=log,
    )
    if rc != 0:
        return rc
    transcript = (
        log.read_text(encoding="utf-8", errors="replace") if log.is_file() else ""
    )
    marker = _completion_marker(ctx)
    if marker not in transcript:
        tail = "\n".join(transcript.rstrip().splitlines()[-20:])
        raise ValueError(
            f"{analysis} ended before its completion marker; log={log}"
            + (f"\n--- OpenSTA tail ---\n{tail}" if tail else "")
        )
    missing = [path for path in _required_reports(analysis, ctx) if not path.is_file()]
    if missing:
        rendered = "\n  ".join(str(path) for path in missing)
        raise ValueError(f"{analysis} completed without required report(s):\n  {rendered}")
    if analysis in {"power_estimate", "power_analysis", "fusion_analysis"}:
        _annotate_power_summary(
            ctx.report_dir,
            "fusion.rpt" if analysis == "fusion_analysis" else "power.rpt",
        )
    return 0


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

def execute_static(analysis: str, project_root: Path, values: Mapping[str, str]) -> int:
    """Generate and execute STA, SDF or vectorless power at every configured corner."""

    if analysis not in {"sta", "sdf", "power_estimate"}:
        raise ValueError(f"static analysis is not supported: {analysis}")
    layout = layout_from_values(project_root, values)
    liberties = _liberties(values)
    corners = _selection(
        values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
    )
    modes = (
        _selection(values.get("STA_MODES"), "setup hold", ("setup", "hold"), "STA mode")
        if analysis == "sta"
        else ("",)
    )
    failures: list[str] = []
    for corner in corners:
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
            else:
                for report in _required_reports(analysis, ctx):
                    print(f"[report] {corner}/{mode or analysis} {report}", flush=True)
    for failure in failures:
        print(f"ERROR: {failure}", file=sys.stderr)
    return 0 if not failures else 2


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
            "corner status    internal   switching     leakage       total  annotated report",
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
        annotated = str(count) if count is not None else "n/a"
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

def analyze_activity_spec(
    analysis: str,
    project_root: Path,
    values: Mapping[str, str],
    spec: ActivitySpec,
    *,
    progress_label: str = "",
) -> dict[str, Any]:
    """Execute one workload-dependent analysis for every selected corner."""

    if analysis not in {"power_analysis", "fusion_analysis"}:
        raise ValueError(f"unsupported activity analysis: {analysis}")
    layout = layout_from_values(project_root, values)
    capture, conversion_log, conversion_method = _activity_vcd(
        spec, values, layout.power_dir / "activity" / "captures"
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
    selected_corners = _selection(
        values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
    )
    modes = (
        _selection(values.get("STA_MODES"), "setup hold", ("setup", "hold"), "STA mode")
        if analysis == "fusion_analysis"
        else ("",)
    )
    if analysis == "power_analysis":
        workload_root = layout.power_dir / "analysis" / spec.workload
        script = layout.power_dir / "analysis" / "power_analysis.tcl"
        primary_name = "power.rpt"
    else:
        workload_root = layout.fusion_dir / spec.workload
        script = layout.fusion_dir / "fusion_analysis.tcl"
        primary_name = "fusion.rpt"
    total_runs = len(selected_corners) * len(modes)
    run_index = 0
    if progress_label:
        print(
            f"[{progress_label}] activity={capture} scope={scope} runs={total_runs}",
            flush=True,
        )
    for corner in selected_corners:
        liberty = liberties[corner]
        for mode in modes:
            run_index += 1
            if analysis == "power_analysis":
                report_dir = workload_root / corner
                log = layout.power_log_dir / "analysis" / spec.workload / corner / f"{spec.top}.log"
                key = corner
            else:
                report_dir = workload_root / corner / mode
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
            if progress_label:
                print(
                    f"[{progress_label}] run {run_index}/{total_runs} START "
                    f"workload={spec.workload} corner={corner} mode={mode or 'n/a'}",
                    flush=True,
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
                ok = rc == 0 and (annotated is None or annotated > 0)
                corners[key] = {
                    "status": "pass" if ok else "fail",
                    "returncode": rc,
                    "liberty": str(liberty),
                    "script": str(script),
                    "log": str(log),
                    "report": str(primary),
                    "activity_annotation_count": annotated,
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
        "schema_version": 3,
        "analysis": analysis,
        "status": "pass" if corners and not failures else "fail",
        "top": spec.top,
        "pdk": spec.pdk,
        "test": spec.test,
        "backend": spec.backend,
        "timing_mode": spec.mode,
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
            report = analyze_activity_spec(
                analysis,
                project_root,
                values,
                spec,
                progress_label=label,
            )
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
    summary_root = layout.power_dir / "analysis" if analysis == "power_analysis" else layout.fusion_dir
    legacy = summary_root / "reports"
    if legacy.is_dir():
        shutil.rmtree(legacy)
    summary = {
        "schema_version": 3,
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
    parser.add_argument("--power-top-instances", default="20")


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
