"""Activity-based OpenSTA power analysis from direct SDF-backed GLS waveforms."""

from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import shutil
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

from flexsoc.backend.output import print_script
from flexsoc.backend.setup_signoff import liberty_corner
from flexsoc.run_layout import layout_from_values


SDF_MODES = ("min", "typ", "max")
POWER_RE = re.compile(
    r"^\s*Total\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)",
    re.MULTILINE,
)
ACTIVITY_RE = re.compile(
    r"Annotated\s+(\d+)\s+(?:pin\s+)?activities",
    re.IGNORECASE,
)


@dataclass(frozen=True, slots=True)
class ActivitySpec:
    """One test/backend/timing trace used for power analysis."""

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
        raise ValueError("no ss/tt/ff Liberty views resolved for activity power analysis")
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
    return layout.post_syn_sim_dir / f"{top}_post_syn_{test}_{backend}_{mode}.json"


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
            f"activity power requires back-annotated GLS mode min/typ/max, got {mode!r}"
        )
    report = _post_syn_report(project_root, values, test=test, backend=backend, mode=mode)
    if not report.is_file():
        raise ValueError(
            f"GLS report not found: {report}; run `fx sim_post_syn --set TEST_NAME={test} "
            f"--set GLS_BACKEND={backend} --set TIMING_MODE={mode}` first"
        )
    payload = _load_json(report)
    top = values.get("TOP", "test")
    pdk = values.get("PDK", "sky130")
    expected = {
        "stage": "post_syn",
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
    prefix = f"{top}_post_syn_"
    rows: set[tuple[str, str, str]] = set()
    for report in layout.post_syn_sim_dir.glob(f"{prefix}*.json"):
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
        raise ValueError(f"no direct SDF-backed GLS reports found in {layout.post_syn_sim_dir}")
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


def render_power_activity_tcl(
    *, top: str, liberty: Path, netlist: Path, sdc: Path, vcd: Path, scope: str,
    source_report: Path, scope_requested: str = "auto",
) -> str:
    """Render one OpenSTA power run driven by a direct GLS VCD."""

    def quote(path: Path) -> str:
        return "{" + path.resolve().as_posix() + "}"

    return "\n".join(
        [
            'puts ""',
            'puts "=== FlexSoC activity-based power analysis ==="',
            f'puts "analysis=activity activity_source=post_syn_gls_vcd scope_requested={scope_requested} scope_resolved={scope}"',
            f'puts "gls_report={source_report.resolve().as_posix()}"',
            f'puts "activity_file={vcd.resolve().as_posix()}"',
            f"read_liberty {quote(liberty)}",
            f"read_verilog {quote(netlist)}",
            f"link_design {top}",
            f"read_sdc {quote(sdc)}",
            f"read_vcd -scope {scope} {quote(vcd)}",
            'puts "=== Activity annotation ==="',
            "report_activity_annotation",
            'puts "=== Power report ==="',
            "report_power",
            "",
        ]
    )


def _run_sta(command: Sequence[str], *, cwd: Path, log: Path) -> int:
    log.parent.mkdir(parents=True, exist_ok=True)
    if _live():
        print("$ " + shlex.join(command), flush=True)
    with log.open("w", encoding="utf-8") as stream:
        proc = subprocess.Popen(
            list(command), cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True
        )
        assert proc.stdout is not None
        for line in proc.stdout:
            stream.write(line)
            if _live():
                sys.stdout.write(line)
        return proc.wait()


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


def analyze_spec(project_root: Path, values: Mapping[str, str], spec: ActivitySpec) -> dict[str, Any]:
    """Analyze one direct GLS trace at every configured Liberty corner."""

    layout = layout_from_values(project_root, values)
    power_root = layout.power_dir / "activity"
    log_root = layout.power_log_dir / "activity"
    capture, conversion_log, conversion_method = _activity_vcd(
        spec, values, power_root / "captures"
    )
    netlist = Path(values.get("NETLIST") or layout.syn_dir / f"{spec.top}_synth.v").expanduser().resolve()
    sdc = layout.constraints_dir / f"{spec.top}.sdc"
    if not netlist.is_file():
        raise ValueError(f"synthesized netlist not found: {netlist}")
    if not sdc.is_file():
        raise ValueError(f"SDC not found: {sdc}")
    scope_requested = values.get("POWER_VCD_SCOPE", "auto").strip() or "auto"
    scope, vcd_scopes = _resolve_vcd_scope(
        capture,
        requested=scope_requested,
        top=spec.top,
        dut_instance=values.get("POWER_DUT_INSTANCE", "auto").strip() or "auto",
    )
    corners: dict[str, Any] = {}
    for corner, liberty in _liberties(values).items():
        script = power_root / "scripts" / f"{spec.stem}_{corner}.tcl"
        script.parent.mkdir(parents=True, exist_ok=True)
        script.write_text(
            render_power_activity_tcl(
                top=spec.top,
                liberty=liberty,
                netlist=netlist,
                sdc=sdc,
                vcd=capture,
                scope=scope,
                source_report=spec.report,
                scope_requested=scope_requested,
            ),
            encoding="utf-8",
        )
        print_script(script)
        log = log_root / f"{spec.stem}_{corner}.log"
        rc = _run_sta(
            [values.get("STA", "sta"), "-exit", "-no_init", str(script)],
            cwd=project_root,
            log=log,
        )
        text = log.read_text(encoding="utf-8", errors="replace")
        numbers = _power_values(text)
        annotated = _activity_count(text)
        annotation_ok = annotated is None or annotated > 0
        corners[corner] = {
            "status": "pass" if rc == 0 and numbers and annotation_ok else "fail",
            "returncode": rc,
            "activity_annotation_count": annotated,
            "activity_annotation_evidence": "reported" if annotated is not None else "not-reported-by-tool",
            "liberty": str(liberty),
            "script": str(script),
            "log": str(log),
            **numbers,
        }
    status = "pass" if corners and all(item["status"] == "pass" for item in corners.values()) else "fail"
    report = {
        "schema_version": 1,
        "status": status,
        "top": spec.top,
        "pdk": spec.pdk,
        "test": spec.test,
        "backend": spec.backend,
        "timing_mode": spec.mode,
        "activity_source": "post_syn_gls_vcd",
        "scope_requested": scope_requested,
        "dut_instance_requested": values.get("POWER_DUT_INSTANCE", "auto").strip() or "auto",
        "scope": scope,
        "vcd_scopes": list(vcd_scopes),
        "source_gls_report": str(spec.report),
        "source_wave": str(spec.wave),
        "activity_vcd": str(capture),
        "conversion_method": conversion_method,
        "conversion_log": str(conversion_log) if conversion_log else None,
        "corners": corners,
    }
    report_path = power_root / "reports" / f"{spec.stem}.json"
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    report["report"] = str(report_path)
    return report


def _report_key(report: Mapping[str, Any]) -> tuple[str, str, str]:
    return (
        str(report.get("test", "")),
        str(report.get("backend", "")),
        str(report.get("timing_mode", "")),
    )


def _write_failure_report(
    project_root: Path,
    values: Mapping[str, str],
    spec: ActivitySpec,
    reason: str,
) -> dict[str, Any]:
    layout = layout_from_values(project_root, values)
    report = {
        "schema_version": 1,
        "status": "fail",
        "top": spec.top,
        "pdk": spec.pdk,
        "test": spec.test,
        "backend": spec.backend,
        "timing_mode": spec.mode,
        "reason": reason,
    }
    path = layout.power_dir / "activity" / "reports" / f"{spec.stem}.json"
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    report["report"] = str(path)
    return report


def _write_summary(
    project_root: Path,
    values: Mapping[str, str],
    reports: Sequence[dict[str, Any]],
) -> Path:
    """Write an aggregate summary from independently executed power analyses."""

    layout = layout_from_values(project_root, values)
    root = layout.power_dir / "activity"
    merged: dict[tuple[str, str, str], dict[str, Any]] = {}
    report_dir = root / "reports"
    if report_dir.is_dir():
        for path in sorted(report_dir.glob("*.json")):
            try:
                report = _load_json(path)
            except ValueError:
                continue
            if report.get("top") != values.get("TOP", "test"):
                continue
            if report.get("pdk") != values.get("PDK", "sky130"):
                continue
            report["report"] = str(path)
            merged[_report_key(report)] = report
    for report in reports:
        merged[_report_key(report)] = report
    ordered = [merged[key] for key in sorted(merged)]
    passed = sum(report.get("status") == "pass" for report in ordered)
    summary = {
        "schema_version": 1,
        "status": "pass" if ordered and passed == len(ordered) else "fail",
        "top": values.get("TOP", "test"),
        "pdk": values.get("PDK", "sky130"),
        "passed": passed,
        "failed": len(ordered) - passed,
        "total": len(ordered),
        "reports": ordered,
    }
    path = root / "summary.json"
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return path

def execute(action: str, project_root: Path, values: Mapping[str, str]) -> int:
    specs = discover_specs(action, values, project_root)
    reports: list[dict[str, Any]] = []
    failures: list[str] = []
    for spec in specs:
        try:
            report = analyze_spec(project_root, values, spec)
        except (OSError, ValueError, subprocess.SubprocessError) as exc:
            failures.append(f"{spec.stem}: {exc}")
            report = _write_failure_report(project_root, values, spec, str(exc))
        reports.append(report)
        if _live():
            print(f"[power-analysis] {spec.stem}: {str(report.get('status')).upper()}", flush=True)
    summary = _write_summary(project_root, values, reports)
    passed = sum(report.get("status") == "pass" for report in reports)
    print(
        f"[power-analysis] {passed}/{len(reports)} PASS summary={summary}",
        flush=True,
    )
    if failures and _live():
        for failure in failures:
            print(f"[power-analysis] FAIL {failure}", file=sys.stderr)
    return 0 if reports and passed == len(reports) else 2


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--action", choices=("single", "all"), required=True)
    parser.add_argument("--project-root", type=Path, required=True)
    parser.add_argument("--values-json", required=True)
    return parser.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    try:
        values = json.loads(args.values_json)
        if not isinstance(values, dict):
            raise ValueError("--values-json must decode to an object")
        return execute(args.action, args.project_root.expanduser().resolve(), values)
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
