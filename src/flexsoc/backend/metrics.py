"""Collect compact machine-readable metrics from one FlexSoC run."""

from __future__ import annotations

import argparse
import json
import os
import re
from pathlib import Path
from typing import Any, Sequence

from rich.console import Console
from rich.markup import escape
from rich.table import Table

from flexsoc.run_layout import pdk_run_layout


LINT_KINDS = ("latch", "undriven", "width", "unconnected", "unused")
FLOAT = r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?"
COVERAGE_DISPLAY_COLUMNS = ("line", "toggle", "expr", "branch", "fsm", "user", "total")
COVERAGE_TYPE_GROUPS = {
    "line": ("line",),
    "toggle": ("toggle",),
    "expr": ("expr",),
    "branch": ("branch",),
    "fsm": ("fsm_state", "fsm_arc"),
    "user": ("user", "covergroup"),
}


def read_text(path: Path) -> str:
    """Read a text artifact without failing on tool-specific encoding noise."""

    return path.read_text(encoding="utf-8", errors="replace")


def line_count(path: Path) -> int:
    """Count non-empty lines in a generated diagnostic file."""

    if not path.is_file():
        return 0
    return sum(1 for line in read_text(path).splitlines() if line.strip())


def latest(paths: Sequence[Path]) -> Path | None:
    """Return the newest existing path."""

    existing = [path for path in paths if path.is_file()]
    return max(existing, key=lambda path: path.stat().st_mtime) if existing else None


def last_number(pattern: str, text: str, cast: type[int] | type[float]) -> int | float | None:
    """Return the last numeric regex match."""

    matches = re.findall(pattern, text, flags=re.IGNORECASE | re.MULTILINE)
    return cast(matches[-1]) if matches else None


def relative(path: Path, run_dir: Path) -> str:
    """Return a stable run-relative artifact path."""

    return path.resolve().relative_to(run_dir.resolve()).as_posix()


def marked_section(text: str, start: str, end: str) -> str:
    """Return text between two explicit report markers."""

    if start not in text or end not in text:
        return ""
    return text.split(start, 1)[1].split(end, 1)[0]


def collect_lint_tool(top: str, run_dir: Path, tool: str) -> dict[str, Any] | None:
    """Collect one lint backend from its tool-specific logs."""

    log_dir = run_dir / "logs" / "lint"
    full_log = log_dir / f"{top}_lint_{tool}_all.log"
    raw_log = log_dir / "raw" / f"{top}_lint_{tool}_all_raw.log"
    if not full_log.is_file():
        return None

    text = read_text(full_log)
    diagnostics: dict[str, int] = {}
    for kind in LINT_KINDS:
        path = log_dir / f"{top}_lint_{tool}_{kind}_all.log"
        kind_text = read_text(path) if path.is_file() else ""
        diagnostics[kind] = 0 if kind_text.startswith("No ") else line_count(path)

    warnings = len(re.findall(r"(?:%Warning-|\bwarning:)", text, flags=re.IGNORECASE))
    errors = len(re.findall(r"(?:%Error-|\berror:)", text, flags=re.IGNORECASE))
    command = read_text(raw_log).splitlines()[0] if raw_log.is_file() else ""
    return {
        "status": "pass" if errors == 0 else "fail",
        "errors": errors,
        "warnings": warnings,
        "diagnostics": diagnostics,
        "command": command,
        "log": relative(full_log, run_dir),
    }


def collect_lint(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect Slang and Verilator lint independently, in execution order."""

    tools: dict[str, Any] = {}
    for tool in ("slang", "verilator"):
        data = collect_lint_tool(top, run_dir, tool)
        if data is not None:
            tools[tool] = data
    if not tools:
        return None
    return {
        "order": ["slang", "verilator"],
        "status": "pass" if len(tools) == 2 and all(item["status"] == "pass" for item in tools.values()) else "partial",
        "tools": tools,
    }


def parse_coverage_summary(path: Path) -> dict[str, Any]:
    """Parse legacy/plain FlexSoC coverage scope totals."""

    scopes: dict[str, Any] = {}
    if not path.is_file():
        return scopes
    for line in read_text(path).splitlines():
        match = re.match(
            r"^\s*([A-Za-z_]+)\s+(\d+)(?:/|\s+)(\d+)\s+([0-9.]+)%\s*$",
            line,
        )
        if not match:
            continue
        name, hit, total, percent = match.groups()
        scopes[name] = {"hit": int(hit), "total": int(total), "percent": float(percent)}
    return scopes


def parse_coverage_matrix(path: Path) -> dict[str, Any]:
    """Read the machine-readable scope-by-type coverage matrix."""

    if not path.is_file():
        return {}
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (json.JSONDecodeError, OSError):
        return {}
    if not isinstance(data, dict) or not isinstance(data.get("scopes"), dict):
        return {}
    return data



def collect_regression(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect generated regression execution and coverage data."""

    test_root = run_dir / "dv" / "functional" / "tests"
    log_root = run_dir / "logs" / "dv" / "functional" / "regression"
    coverage_dir = run_dir / "dv" / "functional" / "coverage"
    tests = sorted(path.name for path in test_root.iterdir() if path.is_dir()) if test_root.is_dir() else []
    backends: dict[str, Any] = {}
    patterns = {
        "sv": (f"{top}_sv_sim_*.log", f"{top}_sv_sim_"),
        "cocotb": (f"{top}_cocotb_*.log", f"{top}_cocotb_"),
    }
    for backend, (pattern, prefix) in patterns.items():
        backend_dir = log_root / backend
        logs = sorted(backend_dir.glob(pattern)) if backend_dir.is_dir() else []
        logged_tests = sorted(
            path.stem[len(prefix):] for path in logs if path.stem.startswith(prefix)
        )
        backends[backend] = {
            "tests_logged": len(logs),
            "logged_tests": logged_tests,
            "missing_tests": sorted(set(tests) - set(logged_tests)),
            "extra_tests": sorted(set(logged_tests) - set(tests)),
            "logs": [relative(path, run_dir) for path in logs],
        }

    summary = coverage_dir / "summary.txt"
    summary_json = coverage_dir / "summary.json"
    coverage_matrix = parse_coverage_matrix(summary_json)
    matrix_scopes = coverage_matrix.get("scopes", {}) if coverage_matrix else {}
    coverage = {
        scope: values.get("total", {})
        for scope, values in matrix_scopes.items()
        if isinstance(values, dict) and isinstance(values.get("total"), dict)
    }
    if not coverage:
        coverage = parse_coverage_summary(summary)
    expected = len(tests)
    regression_ok = bool(
        expected
        and all(not data["missing_tests"] for data in backends.values())
        and (coverage_dir / "merged.dat").is_file()
        and coverage
    )
    if not tests and not any(data["logs"] for data in backends.values()) and not coverage:
        return None
    return {
        "status": "pass" if regression_ok else "partial",
        "tests": tests,
        "test_count": expected,
        "backends": backends,
        "coverage": coverage,
        "coverage_matrix": coverage_matrix,
        "coverage_summary": relative(summary, run_dir) if summary.is_file() else None,
        "coverage_summary_json": relative(summary_json, run_dir) if summary_json.is_file() else None,
        "coverage_merged": (
            relative(coverage_dir / "merged.dat", run_dir)
            if (coverage_dir / "merged.dat").is_file()
            else None
        ),
    }


def synthesis_diagnostic_count(text: str, severity: str) -> int:
    """Count real Yosys or Slang diagnostics, not signal names containing error/warning."""

    label = "Warning" if severity == "warning" else "ERROR"
    slang = severity.lower()
    pattern = (
        rf"^(?:{label}:|%{label.capitalize()}-|"
        rf".+:\d+(?::\d+)?:\s*{slang}:)"
    )
    return len(re.findall(pattern, text, flags=re.IGNORECASE | re.MULTILINE))


def yosys_statistics(top: str, text: str) -> dict[str, Any]:
    """Parse the top-module table printed by Yosys `stat -liberty`."""

    headers = list(re.finditer(r"^===\s+(.+?)\s+===$", text, flags=re.MULTILINE))
    section = ""
    for index, header in enumerate(headers):
        module = header.group(1).strip().lstrip("\\")
        if module != top:
            continue
        end = headers[index + 1].start() if index + 1 < len(headers) else len(text)
        section = text[header.end() : end]

    source = section
    fields = {
        "wires": r"^\s*(\d+)\s+-\s+wires\s*$",
        "wire_bits": r"^\s*(\d+)\s+-\s+wire bits\s*$",
        "public_wires": r"^\s*(\d+)\s+-\s+public wires\s*$",
        "public_wire_bits": r"^\s*(\d+)\s+-\s+public wire bits\s*$",
        "ports": r"^\s*(\d+)\s+-\s+ports\s*$",
        "port_bits": r"^\s*(\d+)\s+-\s+port bits\s*$",
    }
    stats: dict[str, Any] = {}
    for name, pattern in fields.items():
        value = last_number(pattern, source, int)
        if value is not None:
            stats[name] = value

    cells = re.search(
        r"^\s*(\d+)\s+(?:" + FLOAT + r")\s+cells\s*$",
        source,
        flags=re.MULTILINE,
    )
    if cells:
        stats["cells"] = int(cells.group(1))
    else:
        legacy_cells = last_number(r"^\s*Number of cells:\s*(\d+)\s*$", text, int)
        if legacy_cells is not None:
            stats["cells"] = legacy_cells

    area_source = source or text
    area = last_number(
        r"^\s*Chip area for module .*?:\s*(" + FLOAT + r")\s*$",
        area_source,
        float,
    )
    if area is not None:
        stats["area"] = area
        stats["area_unit"] = "liberty"

    sequential = re.search(
        r"^\s*of which used for sequential elements:\s*("
        + FLOAT
        + r")\s+\(("
        + FLOAT
        + r")%\)\s*$",
        source,
        flags=re.MULTILINE,
    )
    if sequential:
        stats["sequential_area"] = float(sequential.group(1))
        stats["sequential_area_pct"] = float(sequential.group(2))

    cell_types: dict[str, dict[str, int | float]] = {}
    for count, cell_area, cell_type in re.findall(
        r"^\s*(\d+)\s+(" + FLOAT + r")\s+(\S+)\s*$",
        source,
        flags=re.MULTILINE,
    ):
        if cell_type == "cells":
            continue
        cell_types[cell_type] = {"count": int(count), "area": float(cell_area)}
    if cell_types:
        stats["cell_types"] = cell_types
    return stats


def collect_synthesis(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect useful statistics from the selected PDK synthesis log."""

    log_dir = pdk_run_layout(run_dir, pdk=pdk, top=top).synthesis_log_dir
    log = latest(tuple(log_dir.glob(f"{top}_synth_opt_*.log")))
    if log is None:
        return None

    text = read_text(log)
    prefix = f"{top}_synth_opt_"
    strategy = log.stem[len(prefix) :] if log.stem.startswith(prefix) else "unknown"
    data: dict[str, Any] = {
        "strategy": strategy,
        "warnings": synthesis_diagnostic_count(text, "warning"),
        "errors": synthesis_diagnostic_count(text, "error"),
        "log": relative(log, run_dir),
    }
    data.update(yosys_statistics(top, text))
    return data


def collect_sta(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect timing summary metrics for the selected PDK."""

    log_dir = pdk_run_layout(run_dir, pdk=pdk, top=top).sta_log_dir
    prefix = f"{top}_sta_"
    scenarios: dict[str, dict[str, Any]] = {}

    for log in sorted(log_dir.glob(f"{top}_sta_*.log")):
        stem = log.stem
        if not stem.startswith(prefix):
            continue
        name = stem[len(prefix) :]
        if "_" not in name:
            continue
        corner, mode = name.rsplit("_", 1)
        if mode not in {"setup", "hold"}:
            continue

        text = read_text(log)
        wns = last_number(r"^\s*wns\s+(" + FLOAT + r")\s*$", text, float)
        tns = last_number(r"^\s*tns\s+(" + FLOAT + r")\s*$", text, float)
        unconstrained = marked_section(
            text,
            "=== flexsoc unconstrained paths ===",
            "=== flexsoc unconstrained paths end ===",
        )
        data: dict[str, Any] = {
            "reported_violating_paths": len(re.findall(r"slack\s*\(VIOLATED\)", text, flags=re.IGNORECASE)),
            "reported_unconstrained_paths": len(re.findall(r"^Startpoint:", unconstrained, flags=re.MULTILINE)),
            "log": relative(log, run_dir),
        }
        if wns is not None:
            data["wns"] = wns
        if tns is not None:
            data["tns"] = tns
        scenarios.setdefault(corner, {})[mode] = data

    return scenarios or None


def collect_power_estimate(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect global-activity power estimates for the selected PDK."""

    log_dir = pdk_run_layout(run_dir, pdk=pdk, top=top).power_log_dir
    prefix = f"{top}_power_estimate_"
    corners: dict[str, Any] = {}
    activity: float | None = None
    duty: float | None = None

    for log in sorted(log_dir.glob(f"{top}_power_estimate_*.log")):
        if not log.stem.startswith(prefix):
            continue
        corner = log.stem[len(prefix) :]
        text = read_text(log)

        assumption = re.search(
            r"analysis=estimate\s+activity_source=global\s+activity=("
            + FLOAT
            + r")\s+transitions_per_cycle\s+duty=("
            + FLOAT
            + r")",
            text,
        )
        if assumption:
            activity = float(assumption.group(1))
            duty = float(assumption.group(2))

        total = re.search(
            r"^\s*Total\s+("
            + FLOAT
            + r")\s+("
            + FLOAT
            + r")\s+("
            + FLOAT
            + r")\s+("
            + FLOAT
            + r")",
            text,
            flags=re.MULTILINE,
        )
        data: dict[str, Any] = {"log": relative(log, run_dir)}
        if total:
            internal, switching, leakage, overall = (float(value) for value in total.groups())
            data.update(
                {
                    "internal_w": internal,
                    "switching_w": switching,
                    "leakage_w": leakage,
                    "total_w": overall,
                }
            )
        corners[corner] = data

    if not corners:
        return None

    result: dict[str, Any] = {
        "analysis": "estimate",
        "activity_source": "global",
        "corners": corners,
    }
    if activity is not None:
        result["activity_transitions_per_cycle"] = activity
    if duty is not None:
        result["duty"] = duty
    return result


def status_word(path: Path, log: Path | None = None) -> str:
    """Return pass/fail/error/unknown from a tool status file or log."""

    texts: list[str] = []
    if path.is_file():
        texts.append(read_text(path))
    if log is not None and log.is_file():
        texts.append(read_text(log))
    text = "\n".join(texts)
    if re.search(r"\bPASS(?:ED)?\b|DONE \(PASS", text, flags=re.IGNORECASE):
        return "pass"
    if re.search(r"DONE \(FAIL|\bFAIL(?:ED)?\b", text, flags=re.IGNORECASE):
        return "fail"
    if re.search(r"DONE \(ERROR|\bERROR\b", text, flags=re.IGNORECASE):
        return "error"
    return "unknown"


def formal_stage(run_dir: Path, workdir: Path, log: Path) -> dict[str, Any] | None:
    """Collect one SBY task including its persisted status and traces."""

    status = workdir / "status"
    if not status.is_file() and not log.is_file() and not workdir.is_dir():
        return None
    traces = sorted(
        path
        for path in workdir.rglob("trace*")
        if path.is_file() and path.suffix in {".vcd", ".yw", ".v", ".smtc"}
    ) if workdir.is_dir() else []
    elapsed = None
    if log.is_file():
        elapsed = last_number(r"Elapsed clock time .*?\((\d+)\)", read_text(log), int)
    result: dict[str, Any] = {
        "status": status_word(status, log),
        "workdir": relative(workdir, run_dir) if workdir.exists() else None,
        "log": relative(log, run_dir) if log.is_file() else None,
        "trace_count": len(traces),
    }
    if elapsed is not None:
        result["elapsed_s"] = elapsed
    if traces:
        result["traces"] = [relative(path, run_dir) for path in traces[:8]]
    return result


def collect_formal(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect CSR and authored-property BMC/prove/cover status."""

    formal = run_dir / "dv" / "formal" / "runs"
    logs = run_dir / "logs" / "dv" / "formal"
    specs = {
        "csr": {
            "bmc": (formal / "csr" / "prove" / f"{top}_csr_bmc", logs / "csr" / f"{top}_bmc.log"),
            "prove": (formal / "csr" / "prove" / f"{top}_csr_prove", logs / "csr" / f"{top}_prove.log"),
            "cover": (formal / "csr" / "cover" / f"{top}_csr_cover", logs / "csr" / f"{top}_cover.log"),
        },
        "properties": {
            "bmc": (formal / "properties" / "prove" / f"{top}_bmc", logs / "properties" / f"{top}_bmc.log"),
            "prove": (formal / "properties" / "prove" / f"{top}_prove", logs / "properties" / f"{top}_prove.log"),
            "cover": (formal / "properties" / "cover" / f"{top}_cover", logs / "properties" / f"{top}_cover.log"),
        },
    }
    result: dict[str, Any] = {}
    for suite, stages in specs.items():
        suite_data: dict[str, Any] = {}
        for name, (workdir, log) in stages.items():
            data = formal_stage(run_dir, workdir, log)
            if data is not None:
                suite_data[name] = data
        if suite_data:
            result[suite] = suite_data
    if not result:
        return None
    statuses = [stage.get("status") for suite in result.values() for stage in suite.values()]
    by_stage: dict[str, Any] = {}
    for stage_name in ("bmc", "prove", "cover"):
        stage_statuses = [
            result.get(suite, {}).get(stage_name, {}).get("status")
            for suite in ("csr", "properties")
        ]
        by_stage[stage_name] = {
            "passed": sum(item == "pass" for item in stage_statuses),
            "total": 2,
        }
    result["summary"] = {
        "passed": sum(item == "pass" for item in statuses),
        "observed": len(statuses),
        "total": 6,
        "elapsed_s": sum(
            int(stage.get("elapsed_s", 0))
            for suite in result.values()
            if isinstance(suite, dict)
            for stage in suite.values()
            if isinstance(stage, dict) and "status" in stage
        ),
        "traces": sum(
            int(stage.get("trace_count", 0))
            for suite in result.values()
            if isinstance(suite, dict)
            for stage in suite.values()
            if isinstance(stage, dict) and "status" in stage
        ),
        "stages": by_stage,
    }
    result["status"] = "pass" if len(statuses) == 6 and all(item == "pass" for item in statuses) else "partial"
    return result


def _eqy_partition_summary(result_dir: Path, log: Path) -> dict[str, Any]:
    """Summarize partition closure without confusing engine errors with mismatch."""

    strategy_root = result_dir / "strategies"
    partition_dirs = sorted(path for path in strategy_root.iterdir() if path.is_dir()) if strategy_root.is_dir() else []
    counts = {"proven": 0, "failed": 0, "errors": 0, "timeouts": 0, "unknown": 0}

    if partition_dirs:
        for partition in partition_dirs:
            states: list[str] = []
            for status_path in partition.rglob("status"):
                words = read_text(status_path).strip().upper().split()
                if words:
                    states.append(words[0])
            if "PASS" in states:
                counts["proven"] += 1
            elif "ERROR" in states:
                counts["errors"] += 1
            elif "FAIL" in states:
                counts["failed"] += 1
            elif "TIMEOUT" in states:
                counts["timeouts"] += 1
            else:
                counts["unknown"] += 1
        total = len(partition_dirs)
    else:
        text = read_text(log) if log.is_file() else ""
        final = re.search(r"Failed to prove equivalence for\s+(\d+)/(\d+)\s+partitions", text)
        if final:
            unproved, total = (int(value) for value in final.groups())
            counts["proven"] = max(0, total - unproved)
            counts["failed"] = unproved
        else:
            proved = set(re.findall(r"Proved equivalence of partition '([^']+)'", text))
            attempted = set(re.findall(r"Running strategy '[^']+' on '([^']+)'", text))
            errored = set(re.findall(r"strategy '[^']+' on partition '([^']+)' encountered an error", text))
            total = len(attempted | proved | errored)
            counts["proven"] = len(proved)
            counts["errors"] = len(errored - proved)
            counts["unknown"] = max(0, total - counts["proven"] - counts["errors"])

    percent = 100.0 * counts["proven"] / total if total else 0.0
    return {**counts, "total": total, "percent": percent}


def eqy_solver_stats(log: Path) -> dict[str, dict[str, int]]:
    """Count EQY strategy attempts and which strategies actually proved partitions."""

    text = read_text(log) if log.is_file() else ""
    names = re.findall(r"Running strategy '([^']+)' on '[^']+'", text)
    stats = {name: {"attempts": names.count(name), "proved": 0, "unproved": 0, "errors": 0} for name in dict.fromkeys(names)}
    for field, pattern in (
        ("proved", r"Proved equivalence of partition '[^']+' using strategy '([^']+)'"),
        ("unproved", r"Could not prove equivalence of partition '[^']+' using strategy '([^']+)'"),
        ("errors", r"Execution of strategy '([^']+)' on partition '[^']+' encountered an error"),
    ):
        for name in re.findall(pattern, text):
            stats.setdefault(name, {"attempts": 0, "proved": 0, "unproved": 0, "errors": 0})[field] += 1
    return stats


def collect_equivalence(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect sign-off EQY closure for the selected PDK."""

    layout = pdk_run_layout(run_dir, pdk=pdk, top=top)
    log = layout.equivalence_log
    result_dir = layout.equivalence_dir / f"{top}_rtl_vs_syn"
    if not log.is_file() and not result_dir.exists():
        return None

    partitions = _eqy_partition_summary(result_dir, log)
    if (result_dir / "PASS").is_file() or (partitions["total"] and partitions["proven"] == partitions["total"]):
        status = "pass"
    elif partitions["failed"]:
        status = "fail"
    elif partitions["errors"] or partitions["timeouts"] or partitions["unknown"] or partitions["proven"]:
        status = "partial"
    elif (result_dir / "FAIL").is_file():
        status = "fail"
    else:
        status = "unknown"

    return {
        "status": status,
        "partitions": partitions,
        "strategies": eqy_solver_stats(log),
        "log": relative(log, run_dir) if log.is_file() else None,
        "result_dir": relative(result_dir, run_dir) if result_dir.exists() else None,
    }


def collect_sdf(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect generated SDF files for the selected PDK."""

    sdf_dir = pdk_run_layout(run_dir, pdk=pdk, top=top).sdf_dir
    files = sorted(sdf_dir.glob(f"{top}_*.sdf")) if sdf_dir.is_dir() else []
    if not files:
        return None
    corners: dict[str, Any] = {}
    prefix = f"{top}_"
    for path in files:
        corner = path.stem[len(prefix):] if path.stem.startswith(prefix) else path.stem
        corners[corner] = {"bytes": path.stat().st_size, "path": relative(path, run_dir)}
    return {"status": "pass", "count": len(files), "corners": corners}


def _json_object(path: Path) -> dict[str, Any]:
    """Read one JSON object, returning an empty mapping for invalid artifacts."""

    if not path.is_file():
        return {}
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except (json.JSONDecodeError, OSError):
        return {}
    return value if isinstance(value, dict) else {}


def _gls_group(records: Sequence[dict[str, Any]]) -> dict[str, Any]:
    """Summarize one subset of archived GLS qualification records."""

    total = len(records)
    passed = sum(record.get("status") == "pass" for record in records)
    failed = sum(record.get("status") == "fail" for record in records)
    missing = sum(record.get("status") == "missing" for record in records)
    if total and passed == total:
        status = "pass"
    elif failed:
        status = "fail"
    elif missing or total:
        status = "partial"
    else:
        status = "missing"
    return {
        "status": status,
        "total": total,
        "passed": passed,
        "failed": failed,
        "missing": missing,
    }


def _matrix_failure_map(values: Sequence[object]) -> dict[str, str]:
    """Split ``<stem>: <reason>`` failure rows written by the E2E matrix."""

    result: dict[str, str] = {}
    for value in values:
        row = str(value)
        stem, separator, reason = row.partition(": ")
        if separator and stem:
            result[stem] = reason
    return result


def _gls_report_reason(
    report: dict[str, Any],
    *,
    mode: str,
    report_path: Path,
    wave_path: Path,
    matrix_reason: str | None,
) -> str | None:
    """Return the first concrete reason one GLS combination is not qualified."""

    if not report_path.is_file():
        return matrix_reason or "qualification report missing"
    if not report:
        return matrix_reason or "qualification report is not valid JSON"
    if str(report.get("status", "unknown")) != "pass":
        phase = str(report.get("phase", "simulation"))
        return f"{phase} failed returncode={report.get('returncode', '?')}"
    if matrix_reason:
        return matrix_reason
    if not wave_path.is_file() or wave_path.stat().st_size == 0:
        return "waveform missing or empty"
    if mode in {"min", "typ", "max"}:
        annotation = report.get("annotation")
        if not isinstance(annotation, dict) or not annotation.get("requested_marker"):
            return "SDF annotation marker missing"
        errors = annotation.get("errors") or []
        warnings = annotation.get("warnings") or []
        if errors:
            return f"SDF annotation error: {errors[0]}"
        if warnings:
            return f"SDF annotation warning: {warnings[0]}"
        if report.get("timing_model") != "icarus-path-delay-only":
            return f"unexpected timing model={report.get('timing_model', 'missing')}"
    return None


def collect_post_syn_gls(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect the archived E2E post-synthesis GLS/back-annotation matrix."""

    layout = pdk_run_layout(run_dir, pdk=pdk, top=top)
    qualification = layout.post_syn_sim_dir / "e2e_qualification"
    matrix_path = qualification / "matrix.json"
    report_dir = qualification / "reports"
    matrix = _json_object(matrix_path)
    discovered_reports = sorted(report_dir.glob("*.json")) if report_dir.is_dir() else []
    if not matrix and not discovered_reports:
        return None

    tests = [str(value) for value in matrix.get("tests", [])]
    backends = [str(value) for value in matrix.get("backends", [])]
    modes = [str(value) for value in matrix.get("timing_modes", [])]
    failure_map = _matrix_failure_map(matrix.get("failures", []))

    expected: list[tuple[str, str, str, str]] = []
    if tests and backends and modes:
        for mode in modes:
            for test_name in tests:
                for backend in backends:
                    stem = f"{top}_{pdk}_{test_name}_{backend}_{mode}"
                    expected.append((stem, test_name, backend, mode))
    else:
        prefix = f"{top}_{pdk}_"
        known_backends = ("cocotb", "sv")
        known_modes = ("zero", "unit", "min", "typ", "max")
        for path in discovered_reports:
            stem = path.stem
            if not stem.startswith(prefix):
                continue
            tail = stem[len(prefix):]
            parsed = None
            for mode in known_modes:
                for backend in known_backends:
                    suffix = f"_{backend}_{mode}"
                    if tail.endswith(suffix):
                        parsed = (tail[: -len(suffix)], backend, mode)
                        break
                if parsed:
                    break
            if parsed:
                test_name, backend, mode = parsed
                expected.append((stem, test_name, backend, mode))
        tests = sorted({item[1] for item in expected})
        backends = sorted({item[2] for item in expected})
        modes = [mode for mode in ("zero", "unit", "min", "typ", "max") if any(item[3] == mode for item in expected)]

    records: list[dict[str, Any]] = []
    for stem, test_name, backend, mode in expected:
        report_path = report_dir / f"{stem}.json"
        log_path = qualification / "logs" / f"{stem}.log"
        wave_path = qualification / "waves" / f"{stem}.fst"
        report = _json_object(report_path)
        reason = _gls_report_reason(
            report,
            mode=mode,
            report_path=report_path,
            wave_path=wave_path,
            matrix_reason=failure_map.get(stem),
        )
        status = "missing" if not report_path.is_file() else ("fail" if reason else "pass")
        records.append(
            {
                "stem": stem,
                "test": test_name,
                "backend": backend,
                "timing_mode": mode,
                "status": status,
                "reason": reason,
                "report": relative(report_path, run_dir) if report_path.is_file() else None,
                "log": relative(log_path, run_dir) if log_path.is_file() else None,
                "wave": relative(wave_path, run_dir) if wave_path.is_file() else None,
            }
        )

    summary = _gls_group(records)
    by_backend = {
        backend: _gls_group([record for record in records if record["backend"] == backend])
        for backend in backends
    }
    by_mode = {
        mode: _gls_group([record for record in records if record["timing_mode"] == mode])
        for mode in modes
    }
    by_test = {
        test_name: _gls_group([record for record in records if record["test"] == test_name])
        for test_name in tests
    }
    failures = [record for record in records if record["status"] != "pass"]
    return {
        **summary,
        "pdk": pdk,
        "tests": tests,
        "backends": backends,
        "timing_modes": modes,
        "sdf_strict": bool(matrix.get("sdf_strict", True)),
        "qualification": relative(qualification, run_dir),
        "matrix": relative(matrix_path, run_dir) if matrix_path.is_file() else None,
        "by_backend": by_backend,
        "by_mode": by_mode,
        "by_test": by_test,
        "records": records,
        "failures": failures,
    }



def collect_power_analysis(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect activity-based power analysis driven by qualified GLS traces."""

    path = pdk_run_layout(run_dir, pdk=pdk, top=top).power_dir / "activity" / "summary.json"
    if not path.is_file():
        return None
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None
    if not isinstance(data, dict) or not isinstance(data.get("reports"), list):
        return None
    data["summary"] = relative(path, run_dir)
    return data


def verification_summary(metrics: dict[str, Any]) -> dict[str, Any]:
    """Summarize PDK-independent functional and property-formal verification."""

    result: dict[str, Any] = {}
    regression = metrics.get("regression")
    if isinstance(regression, dict):
        coverage = regression.get("coverage", {})
        result["functional"] = {
            "status": regression.get("status", "unknown"),
            "tests": regression.get("test_count", 0),
            "coverage_all": coverage.get("all"),
            "coverage_design": coverage.get("design"),
            "coverage_matrix": regression.get("coverage_matrix", {}),
        }

    formal = metrics.get("formal")
    if isinstance(formal, dict):
        result["formal"] = {
            "status": formal.get("status", "unknown"),
            **formal.get("summary", {}),
        }

    return result


def signoff_summary(metrics: dict[str, Any]) -> dict[str, Any]:
    """Summarize technology-dependent sign-off for the selected PDK."""

    result: dict[str, Any] = {}
    equivalence = metrics.get("equivalence")
    if isinstance(equivalence, dict):
        result["equivalence"] = {
            "status": equivalence.get("status", "unknown"),
            **equivalence.get("partitions", {}),
            "strategies": equivalence.get("strategies", {}),
        }

    sdf = metrics.get("sdf")
    if isinstance(sdf, dict):
        result["sdf"] = {"status": sdf.get("status", "unknown"), "count": sdf.get("count", 0)}
    if metrics.get("sta"):
        result["sta"] = {"status": "pass"}
    if metrics.get("power_estimate"):
        result["power"] = {"status": "pass"}
    power_activity = metrics.get("power_analysis")
    if isinstance(power_activity, dict):
        result["power_activity"] = {
            "status": power_activity.get("status", "unknown"),
            "passed": power_activity.get("passed", 0),
            "total": power_activity.get("total", 0),
        }
    gls = metrics.get("post_syn_gls")
    if isinstance(gls, dict):
        result["post_syn_gls"] = {
            "status": gls.get("status", "unknown"),
            "passed": gls.get("passed", 0),
            "total": gls.get("total", 0),
            "failed": gls.get("failed", 0),
            "missing": gls.get("missing", 0),
        }
    return result


def closure_status(metrics: dict[str, Any]) -> dict[str, Any]:
    """Summarize whether the current run contains every standard closure stage."""

    stages: dict[str, str] = {}
    lint = metrics.get("lint")
    stages["lint"] = str(lint.get("status")) if isinstance(lint, dict) else "missing"
    regression = metrics.get("regression")
    stages["regression"] = str(regression.get("status")) if isinstance(regression, dict) else "missing"
    formal = metrics.get("formal")
    stages["formal"] = str(formal.get("status")) if isinstance(formal, dict) else "missing"
    synthesis = metrics.get("synthesis")
    synthesis_ok = (
        isinstance(synthesis, dict)
        and int(synthesis.get("errors", 0)) == 0
        and bool(synthesis.get("netlist"))
    )
    stages["synthesis"] = "pass" if synthesis_ok else "missing"
    equiv = metrics.get("equivalence")
    stages["equivalence"] = str(equiv.get("status")) if isinstance(equiv, dict) else "missing"
    sdf = metrics.get("sdf")
    stages["sdf"] = str(sdf.get("status")) if isinstance(sdf, dict) else "missing"
    stages["sta"] = "pass" if metrics.get("sta") else "missing"
    stages["power"] = "pass" if metrics.get("power_estimate") else "missing"
    order = ["lint", "regression", "formal", "synthesis", "equivalence", "sdf", "sta", "power"]
    gls = metrics.get("post_syn_gls")
    if isinstance(gls, dict):
        stages["post_syn_gls"] = str(gls.get("status", "unknown"))
        order.append("post_syn_gls")
    power_activity = metrics.get("power_analysis")
    if isinstance(power_activity, dict):
        stages["power_activity"] = str(power_activity.get("status", "unknown"))
        order.append("power_activity")
    return {
        "order": order,
        "stages": stages,
        "complete": all(status == "pass" for status in stages.values()),
    }


def collect_metrics(
    top: str,
    run_dir: Path,
    *,
    pdk: str | None = None,
) -> dict[str, Any]:
    """Collect one logical run plus the selected PDK-scoped implementation."""

    selected_pdk = pdk or "sky130"
    layout = pdk_run_layout(run_dir, pdk=selected_pdk, top=top)
    metrics: dict[str, Any] = {
        "schema_version": 10,
        "top": top,
        "run_root": str(run_dir.resolve()),
        "technology": {
            "pdk": selected_pdk,
            "artifacts": layout.as_dict(),
        },
    }

    # PDK-independent closure is shared by every implementation branch.
    for name, collector in (
        ("lint", collect_lint),
        ("regression", collect_regression),
        ("formal", collect_formal),
    ):
        data = collector(top, run_dir)
        if data is not None:
            metrics[name] = data

    # Technology-dependent implementation/sign-off is selected by PDK.
    for name, collector in (
        ("synthesis", collect_synthesis),
        ("equivalence", collect_equivalence),
        ("sdf", collect_sdf),
        ("post_syn_gls", collect_post_syn_gls),
        ("sta", collect_sta),
        ("power_estimate", collect_power_estimate),
        ("power_analysis", collect_power_analysis),
    ):
        data = collector(top, run_dir, selected_pdk)
        if data is not None:
            metrics[name] = data

    synthesis = metrics.get("synthesis")
    if isinstance(synthesis, dict):
        netlist = layout.syn_dir / f"{top}_synth.v"
        synthesis["netlist"] = relative(netlist, run_dir) if netlist.is_file() else None
    metrics["verification"] = verification_summary(metrics)
    metrics["signoff"] = signoff_summary(metrics)
    metrics["closure"] = closure_status(metrics)
    return metrics



def count_color(value: int, *, error: bool = False) -> str:
    """Use green/yellow/red consistently for diagnostic counts."""

    return "green" if value == 0 else ("red" if error else "yellow")


def timing_color(value: float) -> str:
    """Color timing slack by sign without applying a quality policy."""

    return "green" if value >= 0 else "red"


def coverage_markup(record: dict[str, Any]) -> str:
    """Render one coverage record without turning coverage into a gate."""

    total = int(record.get("total", 0) or 0)
    hit = int(record.get("hit", 0) or 0)
    if total == 0:
        return "[grey70]-[/grey70]"
    percent = float(record.get("percent", 0.0) or 0.0)
    color = "green" if percent >= 100.0 else "yellow"
    return f"[{color}]{hit}/{total}  {percent:.2f}%[/{color}]"


def _coverage_column_record(values: dict[str, Any], column: str) -> dict[str, Any]:
    """Return one normalized display column, with compatibility for schema v1."""

    columns = values.get("columns")
    if isinstance(columns, dict):
        record = columns.get(column)
        if isinstance(record, dict):
            return record
    if column == "total":
        record = values.get("total")
        return record if isinstance(record, dict) else {}

    by_type = values.get("types")
    if not isinstance(by_type, dict):
        return {}
    hit = 0
    total = 0
    for kind in COVERAGE_TYPE_GROUPS[column]:
        record = by_type.get(kind)
        if not isinstance(record, dict):
            continue
        hit += int(record.get("hit", 0) or 0)
        total += int(record.get("total", 0) or 0)
    return {"hit": hit, "total": total, "percent": 100.0 * hit / total if total else 0.0}


def coverage_matrix_table(matrix: dict[str, Any]) -> Table | None:
    """Return the fixed scope × {line,toggle,expr,branch,fsm,user,total} matrix."""

    scopes = matrix.get("scopes") if isinstance(matrix, dict) else None
    if not isinstance(scopes, dict) or not scopes:
        return None

    table = Table(box=None, pad_edge=False, header_style="bold grey70")
    table.add_column("Scope", style="white", no_wrap=True)
    for column in COVERAGE_DISPLAY_COLUMNS:
        table.add_column(column, justify="right", no_wrap=True)

    for scope in ("design", "registers", "common", "other", "all"):
        values = scopes.get(scope)
        if not isinstance(values, dict):
            continue
        table.add_row(
            scope,
            *(coverage_markup(_coverage_column_record(values, column)) for column in COVERAGE_DISPLAY_COLUMNS),
        )
    return table


def metric_table() -> Table:
    """Return one compact two-column metrics table."""

    table = Table(show_header=False, box=None, pad_edge=False)
    table.add_column("Metric", style="cyan", no_wrap=True)
    table.add_column("Value")
    return table


def status_markup(status: str) -> str:
    """Return a compact colored status label."""

    colors = {
        "pass": "bold green",
        "fail": "bold red",
        "error": "bold red",
        "partial": "bold yellow",
        "missing": "bold grey70",
        "unknown": "bold grey70",
    }
    color = colors.get(status, "grey70")
    return f"[{color}]{status.upper()}[/{color}]"


def show_metrics(path: Path) -> None:
    """Print a colored end-of-run closure summary from metrics.json."""

    if not path.is_file():
        raise FileNotFoundError(f"metrics file not found: {path}; run: fx metrics")

    data = json.loads(path.read_text(encoding="utf-8"))
    console = Console()
    console.print(f"[bold cyan]FlexSoC run check[/bold cyan] · [bold white]{data.get('top', 'unknown')}[/bold white]")

    closure = data.get("closure", {})
    if closure:
        console.print("\n[bold cyan]Closure[/bold cyan]")
        table = Table(box=None, pad_edge=False, header_style="bold cyan")
        table.add_column("Stage")
        table.add_column("Status")
        for name in closure.get("order", []):
            status = str(closure.get("stages", {}).get(name, "missing"))
            table.add_row(name, status_markup(status))
        console.print(table)
        overall = "PASS" if closure.get("complete") else "INCOMPLETE"
        color = "green" if closure.get("complete") else "red"
        console.print(f"[grey70]Standard closure:[/grey70] [bold {color}]{overall}[/bold {color}]")

    verification = data.get("verification", {})
    if verification:
        console.print("\n[bold cyan]Verification summary[/bold cyan]")
        table = metric_table()
        functional = verification.get("functional", {})
        if functional:
            table.add_row("Functional regression", status_markup(str(functional.get("status", "unknown"))))
            for label, key in (("Functional coverage", "coverage_all"), ("Design coverage", "coverage_design")):
                coverage = functional.get(key)
                if coverage:
                    table.add_row(label, f"{coverage['hit']}/{coverage['total']}  {coverage['percent']:.2f}%")
        formal_summary = verification.get("formal", {})
        if formal_summary:
            table.add_row(
                "Formal stages",
                f"{formal_summary.get('passed', 0)}/{formal_summary.get('total', 6)}  "
                + status_markup(
                    "pass"
                    if formal_summary.get("passed", 0) == formal_summary.get("total", 6)
                    else "partial"
                ),
            )
            for stage in ("bmc", "prove", "cover"):
                values = formal_summary.get("stages", {}).get(stage, {})
                table.add_row(
                    f"Formal {stage.upper()}",
                    f"{values.get('passed', 0)}/{values.get('total', 2)}  "
                    + status_markup(
                        "pass"
                        if values.get("passed", 0) == values.get("total", 2)
                        else "partial"
                    ),
                )
        console.print(table)

    signoff = data.get("signoff", {})
    if signoff:
        console.print("\n[bold cyan]Sign-off summary[/bold cyan]")
        table = metric_table()
        equivalence = signoff.get("equivalence", {})
        if equivalence:
            total = int(equivalence.get("total", 0) or 0)
            proven = int(equivalence.get("proven", 0) or 0)
            percent = float(equivalence.get("percent", 0.0) or 0.0)
            closure = f"{proven}/{total}  {percent:.2f}%  " if total else ""
            table.add_row(
                "RTL ↔ synthesis",
                closure + status_markup(str(equivalence.get("status", "unknown"))),
            )
        for label, key in (("SDF", "sdf"), ("STA", "sta"), ("Power estimate", "power")):
            stage = signoff.get(key, {})
            if stage:
                table.add_row(label, status_markup(str(stage.get("status", "unknown"))))
        gls_summary = signoff.get("post_syn_gls", {})
        if gls_summary:
            table.add_row(
                "Post-synthesis GLS",
                f"{gls_summary.get('passed', 0)}/{gls_summary.get('total', 0)}  "
                + status_markup(str(gls_summary.get("status", "unknown"))),
            )
        activity_summary = signoff.get("power_activity", {})
        if activity_summary:
            table.add_row(
                "Activity power",
                f"{activity_summary.get('passed', 0)}/{activity_summary.get('total', 0)}  "
                + status_markup(str(activity_summary.get("status", "unknown"))),
            )
        console.print(table)

    lint = data.get("lint")
    if lint:
        console.print("\n[bold cyan]Lint[/bold cyan]  [cyan]Slang → Verilator[/cyan]")
        table = Table(box=None, pad_edge=False, header_style="bold cyan")
        table.add_column("Tool")
        table.add_column("Status")
        table.add_column("Errors", justify="right")
        table.add_column("Warnings", justify="right")
        table.add_column("Latch", justify="right")
        table.add_column("Width", justify="right")
        table.add_column("Unused", justify="right")
        for tool in lint.get("order", []):
            values = lint.get("tools", {}).get(tool)
            if not values:
                table.add_row(tool, status_markup("missing"), "-", "-", "-", "-", "-")
                continue
            diag = values.get("diagnostics", {})
            table.add_row(
                tool,
                status_markup(str(values.get("status", "unknown"))),
                str(values.get("errors", 0)),
                str(values.get("warnings", 0)),
                str(diag.get("latch", 0)),
                str(diag.get("width", 0)),
                str(diag.get("unused", 0)),
            )
        console.print(table)

    regression = data.get("regression")
    if regression:
        console.print("\n[bold cyan]Functional regression[/bold cyan]")
        table = metric_table()
        table.add_row("Status", status_markup(str(regression.get("status", "unknown"))))
        table.add_row("Generated tests", str(regression.get("test_count", 0)))
        for backend, values in regression.get("backends", {}).items():
            table.add_row(f"{backend} logs", str(values.get("tests_logged", 0)))
        all_cov = regression.get("coverage", {}).get("all")
        if all_cov:
            table.add_row("Coverage all", f"{all_cov['hit']}/{all_cov['total']}  {all_cov['percent']:.2f}%")
        design_cov = regression.get("coverage", {}).get("design")
        if design_cov:
            table.add_row("Coverage design", f"{design_cov['hit']}/{design_cov['total']}  {design_cov['percent']:.2f}%")
        console.print(table)

        matrix_table = coverage_matrix_table(regression.get("coverage_matrix", {}))
        if matrix_table is not None:
            console.print("\n[bold cyan]Functional coverage — scope × type[/bold cyan]")
            console.print(matrix_table)

    formal = data.get("formal")
    if formal:
        console.print("\n[bold cyan]Formal[/bold cyan]")
        table = Table(box=None, pad_edge=False, header_style="bold cyan")
        table.add_column("Suite")
        table.add_column("Stage")
        table.add_column("Status")
        table.add_column("Time", justify="right")
        table.add_column("Traces", justify="right")
        for suite in ("csr", "properties"):
            for stage in ("bmc", "prove", "cover"):
                values = formal.get(suite, {}).get(stage)
                if not values:
                    table.add_row(suite, stage, status_markup("missing"), "-", "-")
                    continue
                elapsed = values.get("elapsed_s")
                table.add_row(
                    suite,
                    stage,
                    status_markup(str(values.get("status", "unknown"))),
                    "-" if elapsed is None else f"{elapsed}s",
                    str(values.get("trace_count", 0)),
                )
        console.print(table)

    synthesis = data.get("synthesis")
    if synthesis:
        console.print("\n[bold cyan]Synthesis[/bold cyan]")
        table = metric_table()
        table.add_row("Strategy", str(synthesis.get("strategy", "unknown")))
        table.add_row("Netlist", str(synthesis.get("netlist", "missing")))
        for label, key in (("Cells", "cells"), ("Area", "area"), ("Sequential area", "sequential_area")):
            if key in synthesis:
                table.add_row(label, str(synthesis[key]))
        errors = int(synthesis.get("errors", 0))
        warnings = int(synthesis.get("warnings", 0))
        table.add_row("Errors", f"[{count_color(errors, error=True)}]{errors}[/]")
        table.add_row("Warnings", f"[{count_color(warnings)}]{warnings}[/]")
        console.print(table)

    equiv = data.get("equivalence")
    if equiv:
        console.print("\n[bold cyan]RTL ↔ synthesis equivalence[/bold cyan]")
        table = metric_table()
        table.add_row("Status", status_markup(str(equiv.get("status", "unknown"))))
        partitions = equiv.get("partitions", {})
        if isinstance(partitions, dict) and int(partitions.get("total", 0) or 0):
            table.add_row(
                "Partitions proven",
                f"{partitions.get('proven', 0)}/{partitions.get('total', 0)}  "
                f"{float(partitions.get('percent', 0.0) or 0.0):.2f}%",
            )
            table.add_row("Partitions failed", str(partitions.get("failed", 0)))
            table.add_row("Engine errors", str(partitions.get("errors", 0)))
            table.add_row("Timeouts", str(partitions.get("timeouts", 0)))
            table.add_row("Unknown", str(partitions.get("unknown", 0)))
        for name, values in equiv.get("strategies", {}).items():
            table.add_row(f"Strategy {name}", f"{values.get('proved', 0)}/{values.get('attempts', 0)} proven")
        table.add_row("Log", str(equiv.get("log", "-")))
        console.print(table)

    sdf = data.get("sdf")
    if sdf:
        console.print("\n[bold cyan]SDF[/bold cyan]")
        table = Table(box=None, pad_edge=False, header_style="bold cyan")
        table.add_column("Corner")
        table.add_column("Bytes", justify="right")
        table.add_column("Artifact")
        for corner, values in sdf.get("corners", {}).items():
            table.add_row(corner, str(values.get("bytes", 0)), str(values.get("path", "-")))
        console.print(table)

    gls = data.get("post_syn_gls")
    if gls:
        pdk = data.get("technology", {}).get("pdk", gls.get("pdk", "unknown"))
        console.print(f"\n[bold cyan]Post-synthesis GLS[/bold cyan] · [bold white]{escape(str(pdk))}[/bold white]")
        table = metric_table()
        table.add_row("Status", status_markup(str(gls.get("status", "unknown"))))
        table.add_row(
            "Matrix",
            f"{gls.get('passed', 0)}/{gls.get('total', 0)} passed · "
            f"{gls.get('failed', 0)} failed · {gls.get('missing', 0)} missing",
        )
        table.add_row("Tests", ", ".join(str(value) for value in gls.get("tests", [])) or "-")
        table.add_row("Backends", ", ".join(str(value) for value in gls.get("backends", [])) or "-")
        table.add_row("Timing modes", ", ".join(str(value) for value in gls.get("timing_modes", [])) or "-")
        table.add_row("SDF strict", "yes" if gls.get("sdf_strict") else "no")
        table.add_row("Qualification", str(gls.get("qualification", "-")))
        table.add_row("Matrix JSON", str(gls.get("matrix", "-")))
        console.print(table)

        records = gls.get("records", [])
        backends = [str(value) for value in gls.get("backends", [])]
        modes = [str(value) for value in gls.get("timing_modes", [])]
        if records and backends and modes:
            matrix = Table(box=None, pad_edge=False, header_style="bold cyan")
            matrix.add_column("Mode", style="white", no_wrap=True)
            for backend in backends:
                matrix.add_column(backend, justify="right", no_wrap=True)
            matrix.add_column("Total", justify="right", no_wrap=True)
            for mode in modes:
                row = [record for record in records if record.get("timing_mode") == mode]
                cells = []
                for backend in backends:
                    group = _gls_group([record for record in row if record.get("backend") == backend])
                    cells.append(
                        f"{group['passed']}/{group['total']} "
                        + status_markup(str(group["status"]))
                    )
                total = _gls_group(row)
                matrix.add_row(
                    mode,
                    *cells,
                    f"{total['passed']}/{total['total']} " + status_markup(str(total["status"])),
                )
            console.print("\n[bold cyan]GLS qualification matrix[/bold cyan]")
            console.print(matrix)

        failures = gls.get("failures", [])
        if failures:
            console.print("\n[bold red]GLS failures[/bold red]")
            for record in failures[:8]:
                evidence = record.get("log") or record.get("report") or record.get("wave") or "-"
                console.print(
                    f"[bold red]FAIL[/bold red] [white]{escape(str(record.get('stem', 'unknown')))}[/white]"
                )
                console.print(f"  [grey70]reason:[/grey70] {escape(str(record.get('reason') or 'not qualified'))}")
                console.print(f"  [grey70]evidence:[/grey70] {escape(str(evidence))}")
            remaining = len(failures) - 8
            if remaining > 0:
                console.print(f"[grey70]... {remaining} additional GLS failure(s); inspect matrix JSON.[/grey70]")


    power_activity = data.get("power_analysis")
    if power_activity:
        console.print("\n[bold cyan]Post-GLS activity power[/bold cyan]")
        summary = metric_table()
        summary.add_row("Status", status_markup(str(power_activity.get("status", "unknown"))))
        summary.add_row(
            "Analyses",
            f"{power_activity.get('passed', 0)}/{power_activity.get('total', 0)} passed · "
            f"{power_activity.get('failed', 0)} failed",
        )
        summary.add_row("Summary JSON", str(power_activity.get("summary", "-")))
        console.print(summary)
        table = Table(box=None, pad_edge=False, header_style="bold cyan")
        table.add_column("Test")
        table.add_column("Backend")
        table.add_column("GLS")
        table.add_column("Corner")
        table.add_column("Annotated", justify="right")
        table.add_column("Total W", justify="right")
        table.add_column("Status")
        for report in power_activity.get("reports", []):
            corners = report.get("corners", {}) if isinstance(report, dict) else {}
            if not corners:
                table.add_row(
                    str(report.get("test", "-")), str(report.get("backend", "-")),
                    str(report.get("timing_mode", "-")), "-", "-", "-",
                    status_markup(str(report.get("status", "fail"))),
                )
                continue
            for corner, values in corners.items():
                table.add_row(
                    str(report.get("test", "-")), str(report.get("backend", "-")),
                    str(report.get("timing_mode", "-")), str(corner),
                    str(values.get("activity_annotation_count", "-")),
                    str(values.get("total_w", "-")),
                    status_markup(str(values.get("status", "unknown"))),
                )
        console.print(table)

    sta = data.get("sta")
    if sta:
        console.print("\n[bold cyan]STA[/bold cyan]")
        table = Table(box=None, pad_edge=False, header_style="bold cyan")
        table.add_column("Corner")
        table.add_column("Mode")
        table.add_column("WNS", justify="right")
        table.add_column("TNS", justify="right")
        table.add_column("Viol.", justify="right")
        table.add_column("Unconstr.", justify="right")
        for corner, modes in sta.items():
            for mode, values in modes.items():
                wns = values.get("wns")
                tns = values.get("tns")
                wns_text = "-" if wns is None else f"[{timing_color(float(wns))}]{wns}[/]"
                tns_text = "-" if tns is None else f"[{timing_color(float(tns))}]{tns}[/]"
                table.add_row(
                    corner,
                    mode,
                    wns_text,
                    tns_text,
                    str(values.get("reported_violating_paths", 0)),
                    str(values.get("reported_unconstrained_paths", 0)),
                )
        console.print(table)

    power = data.get("power_estimate")
    if power:
        console.print("\n[bold cyan]Power estimate[/bold cyan]")
        table = Table(box=None, pad_edge=False, header_style="bold cyan")
        table.add_column("Corner")
        table.add_column("Total W", justify="right")
        table.add_column("Internal W", justify="right")
        table.add_column("Switching W", justify="right")
        table.add_column("Leakage W", justify="right")
        for corner, values in power.get("corners", {}).items():
            table.add_row(
                corner,
                str(values.get("total_w", "-")),
                str(values.get("internal_w", "-")),
                str(values.get("switching_w", "-")),
                str(values.get("leakage_w", "-")),
            )
        console.print(table)


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    """Parse the small metrics collector CLI."""

    parser = argparse.ArgumentParser(description="Collect or display FlexSoC run metrics.")
    parser.add_argument("--top")
    parser.add_argument("--run-dir", type=Path)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--show", type=Path)
    args = parser.parse_args(argv)
    if args.show is None and not all((args.top, args.run_dir, args.output)):
        parser.error("collection requires --top, --run-dir, and --output")
    return args


def main(argv: Sequence[str] | None = None) -> int:
    """Write one deterministic metrics.json file."""

    args = parse_args(argv)
    if args.show is not None:
        try:
            show_metrics(args.show)
        except (FileNotFoundError, json.JSONDecodeError) as exc:
            print(f"ERROR: {exc}")
            return 2
        return 0

    pdk = os.environ.get("FLEXSOC_PDK") or None
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(
        json.dumps(
            collect_metrics(args.top, args.run_dir, pdk=pdk),
            indent=2,
        ) + "\n",
        encoding="utf-8",
    )
    print(f"[metrics] output: {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
