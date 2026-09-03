"""Run metrics, manifest, closure qualification and terminal reporting."""

from __future__ import annotations

import hashlib
import json
import os
import platform
import re
import subprocess
import tomllib
from dataclasses import dataclass
from importlib import metadata
from pathlib import Path
from typing import Any, Mapping, Sequence

from rich.console import Console
from rich.table import Table

from flexsoc.backend.signoff.sta import SDF_MODE_TO_CORNER
from flexsoc.backend.core import pdk_run_layout
from flexsoc.backend.core.toolchain import collect as collect_environment


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


def unique_file(paths: Sequence[Path], *, label: str) -> Path | None:
    """Return one existing artifact, rejecting ambiguous fallbacks."""

    existing = sorted(path for path in paths if path.is_file())
    if len(existing) > 1:
        raise ValueError(f"ambiguous {label}: " + ", ".join(str(path) for path in existing))
    return existing[0] if existing else None


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


def collect_cdc_rdc(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect the custom structural CDC/RDC summary emitted after lint."""

    summary_path = run_dir / "analysis" / "cdc_rdc" / "summary.json"
    if not summary_path.is_file():
        return None
    try:
        summary = json.loads(summary_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None
    if not isinstance(summary, dict) or summary.get("top") != top:
        return None
    result = {
        key: summary.get(key)
        for key in (
            "schema", "top", "status", "clock_domains", "reset_domains",
            "sequential_elements", "dependencies", "verification_obligations",
        )
        if key in summary
    }
    for key in ("cdc", "rdc", "setup", "glitch"):
        values = summary.get(key)
        if isinstance(values, dict):
            result[key] = {
                name: value
                for name, value in values.items()
                if name not in {"findings", "crossings"}
            }
    result["summary"] = relative(summary_path, run_dir)
    report_path = run_dir / "analysis" / "cdc_rdc" / "cdc_rdc.rpt"
    if report_path.is_file():
        result["report"] = relative(report_path, run_dir)
    return result


def parse_coverage_summary(path: Path) -> dict[str, Any]:
    """Parse plain FlexSoC coverage scope totals."""

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
        fallback_cells = last_number(r"^\s*Number of cells:\s*(\d+)\s*$", text, int)
        if fallback_cells is not None:
            stats["cells"] = fallback_cells

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
    log = unique_file(tuple(log_dir.glob(f"{top}_synth_opt_*.log")), label=f"synthesis log for {top}")
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


def collect_sta(
    top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
) -> dict[str, Any] | None:
    """Collect per-corner setup/hold data from one sign-off stage."""

    layout = pdk_run_layout(run_dir, pdk=pdk, top=top)
    root = layout.signoff_stage_root(stage)
    log_root = layout.signoff_stage_log_root(stage)
    canonical = root / "sta" / "sta.json"
    if canonical.is_file():
        payload = json.loads(canonical.read_text(encoding="utf-8"))
        scenarios: dict[str, dict[str, Any]] = {}
        for item in payload.get("scenarios", []):
            corner = str(item.get("corner", ""))
            mode = str(item.get("mode", ""))
            if not corner or mode not in {"setup", "hold"}:
                continue
            data = {
                "reported_violating_paths": int(item.get("violating_paths", 0)),
                "reported_unconstrained_paths": int(item.get("unconstrained_paths", 0)),
                "report": relative(root / "sta" / "sta.rpt", run_dir),
                "log": relative(log_root / "sta" / corner / mode / f"{top}.log", run_dir),
                "scenario": item.get("id", f"{mode}_{corner}"),
                "status": item.get("status", "unknown"),
            }
            if item.get("wns") is not None:
                data["wns"] = float(item["wns"])
            if item.get("tns") is not None:
                data["tns"] = float(item["tns"])
            scenarios.setdefault(corner, {})[mode] = data
        return scenarios or None

    scenarios: dict[str, dict[str, Any]] = {}
    for report in sorted((root / "sta").glob("*/*/timing.rpt")):
        corner = report.parent.parent.name
        mode = report.parent.name
        if mode not in {"setup", "hold"}:
            continue
        text = read_text(report)
        wns = last_number(r"^\s*wns(?:\s+\w+)?\s+(" + FLOAT + r")\s*$", text, float)
        tns = last_number(r"^\s*tns(?:\s+\w+)?\s+(" + FLOAT + r")\s*$", text, float)
        violating = (
            marked_section(text, "=== Violating paths ===", "=== Near-critical paths ===") or text
        )
        if wns is None:
            slacks = re.findall(
                r"^\s*(" + FLOAT + r")\s+slack\s+\(VIOLATED\)",
                violating,
                flags=re.IGNORECASE | re.MULTILINE,
            )
            wns = min(map(float, slacks)) if slacks else None
        constraint = marked_section(text, "=== Constraint validation ===", "=== Violating paths ===") or ""
        unconstrained = re.search(
            r"\bThere (?:is|are)\s+(\d+)\s+unconstrained endpoints?\b",
            constraint, flags=re.IGNORECASE,
        )
        data: dict[str, Any] = {
            "reported_violating_paths": len(
                re.findall(r"slack\s*\(VIOLATED\)", violating, flags=re.IGNORECASE)
            ),
            "reported_unconstrained_paths": int(unconstrained.group(1)) if unconstrained else 0,
            "report": relative(report, run_dir),
            "log": relative(log_root / "sta" / corner / mode / f"{top}.log", run_dir),
        }
        if wns is not None:
            data["wns"] = wns
        if tns is not None:
            data["tns"] = tns
        scenarios.setdefault(corner, {})[mode] = data
    return scenarios or None

def collect_power_estimate(
    top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
) -> dict[str, Any] | None:
    """Collect vectorless input-activity power estimates by corner."""

    layout = pdk_run_layout(run_dir, pdk=pdk, top=top)
    root = layout.signoff_stage_root(stage)
    log_root = layout.signoff_stage_log_root(stage)
    corners: dict[str, Any] = {}
    activity: float | None = None
    duty: float | None = None
    for report in sorted((root / "power" / "estimate").glob("*/power.rpt")):
        corner = report.parent.name
        text = read_text(report)
        activity_match = re.search(r"^activity=(" + FLOAT + r")$", text, flags=re.MULTILINE)
        duty_match = re.search(r"^duty=(" + FLOAT + r")$", text, flags=re.MULTILINE)
        if activity_match:
            activity = float(activity_match.group(1))
        if duty_match:
            duty = float(duty_match.group(1))
        total = re.search(
            r"^\s*Total\s+(" + FLOAT + r")\s+(" + FLOAT + r")\s+(" + FLOAT + r")\s+(" + FLOAT + r")",
            text,
            flags=re.MULTILINE,
        )
        data: dict[str, Any] = {
            "report": relative(report, run_dir),
            "log": relative(log_root / "power" / "estimate" / corner / f"{top}.log", run_dir),
        }
        if total:
            internal, switching, leakage, overall = (float(value) for value in total.groups())
            data.update({
                "internal_w": internal,
                "switching_w": switching,
                "dynamic_w": internal + switching,
                "leakage_w": leakage,
                "total_w": overall,
            })
        corners[corner] = data
    if not corners:
        return None
    result: dict[str, Any] = {"activity_source": "input_assumption", "corners": corners}
    if activity is not None:
        result["activity"] = activity
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
    traces = (
        sorted(
            path
            for path in workdir.rglob("trace*")
            if path.is_file() and path.suffix in {".vcd", ".yw", ".v", ".smtc"}
        )
        if workdir.is_dir()
        else []
    )
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


def collect_sdf(
    top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
) -> dict[str, Any] | None:
    """Collect generated SDF files for one sign-off stage."""

    layout = pdk_run_layout(run_dir, pdk=pdk, top=top)
    sdf_dir = layout.signoff_stage_root(stage) / "sdf"
    files = sorted(sdf_dir.glob(f"*/{top}_*.sdf")) if sdf_dir.is_dir() else []
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


def _gls_scenario(mode: str) -> str:
    """Return the user-facing GLS scenario while retaining zero/unit as DV modes."""

    return SDF_MODE_TO_CORNER.get(mode, mode)


def _activity_scenario(report: dict[str, Any], fallback: str = "-") -> str:
    """Return the PVT scenario recorded by one activity analysis report."""

    scenario = report.get("scenario")
    if isinstance(scenario, dict):
        return str(scenario.get("corner", fallback))
    if scenario:
        return str(scenario)
    return _gls_scenario(str(report.get("timing_mode", fallback)))


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


def _gls_scenario_records(records: Sequence[dict[str, Any]]) -> list[dict[str, Any]]:
    """Collapse backend alternatives into one qualification result per test/scenario."""

    grouped: dict[tuple[str, str], list[dict[str, Any]]] = {}
    for record in records:
        grouped.setdefault(
            (str(record.get("test", "")), str(record.get("timing_mode", ""))), []
        ).append(record)

    scenarios: list[dict[str, Any]] = []
    mode_order = {mode: index for index, mode in enumerate(("zero", "unit", "min", "typ", "max"))}
    backend_order = {"sv": 0, "cocotb": 1}
    for (test, mode), candidates in sorted(
        grouped.items(), key=lambda item: (mode_order.get(item[0][1], 99), item[0][0])
    ):
        ordered = sorted(
            candidates, key=lambda record: backend_order.get(str(record.get("backend", "")), 99)
        )
        passing = [record for record in ordered if record.get("status") == "pass"]
        selected = passing[0] if passing else ordered[0]
        failures = [record for record in ordered if record.get("status") != "pass"]
        scenarios.append(
            {
                "stem": f"{test}_{_gls_scenario(mode)}",
                "test": test,
                "timing_mode": mode,
                "scenario": _gls_scenario(mode),
                "status": "pass" if passing else "fail",
                "backend": selected.get("backend") if passing else None,
                "available_backends": [record.get("backend") for record in ordered],
                "failed_backends": [record.get("backend") for record in failures],
                "reason": None if passing else "; ".join(
                    f"{record.get('backend')}: {record.get('reason') or 'not qualified'}"
                    for record in failures
                ),
                "report": selected.get("report"),
                "log": selected.get("log"),
                "wave": selected.get("wave"),
            }
        )
    return scenarios


def _gls_report_reason(
    report: dict[str, Any],
    *,
    mode: str,
    wave_path: Path,
    interconnect_expected: bool,
) -> str | None:
    """Return the first concrete reason one direct GLS result is not usable."""

    if not report:
        return "GLS report is not valid JSON"
    if str(report.get("status", "unknown")) != "pass":
        phase = str(report.get("phase", "simulation"))
        return f"{phase} failed returncode={report.get('returncode', '?')}"
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
        expected = "enabled" if interconnect_expected else "none"
        if report.get("interconnect_delays") != expected:
            return (
                "SDF interconnect delays are not enabled"
                if interconnect_expected
                else "post-synthesis SDF unexpectedly enables interconnect delays"
            )
    return None


def collect_post_syn_gls(
    top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
) -> dict[str, Any] | None:
    """Collect direct GLS reports from one gate-level stage."""

    layout = pdk_run_layout(run_dir, pdk=pdk, top=top)
    report_stage = "post_pnr" if stage == "post_route" else "post_syn"
    stage_dir = layout.post_pnr_sim_dir if report_stage == "post_pnr" else layout.post_syn_sim_dir
    report_paths = sorted(stage_dir.glob(f"{top}_{report_stage}_*.json"))
    if not report_paths:
        return None

    record_map: dict[tuple[str, str, str], tuple[bool, dict[str, Any]]] = {}
    for report_path in report_paths:
        report = _json_object(report_path)
        if report.get("stage") != report_stage:
            continue
        test_name = str(report.get("test_name", ""))
        backend = str(report.get("backend", ""))
        mode = str(report.get("timing_mode", ""))
        if not test_name or backend not in {"sv", "cocotb"}:
            continue
        if mode not in {"zero", "unit", "min", "typ", "max"}:
            continue
        raw_wave = report.get("wave")
        wave_path = Path(str(raw_wave)).expanduser() if raw_wave else Path()
        if raw_wave and not wave_path.is_absolute():
            wave_path = (report_path.parent / wave_path).resolve()
        raw_log = report.get("log")
        log_path = Path(str(raw_log)).expanduser() if raw_log else Path()
        if raw_log and not log_path.is_absolute():
            log_path = (report_path.parent / log_path).resolve()
        reason = _gls_report_reason(
            report,
            mode=mode,
            wave_path=wave_path,
            interconnect_expected=report_stage == "post_pnr",
        )
        record = {
            "stem": report_path.stem,
            "test": test_name,
            "backend": backend,
            "timing_mode": mode,
            "scenario": str(report.get("scenario") or _gls_scenario(mode)),
            "status": "fail" if reason else "pass",
            "reason": reason,
            "report": relative(report_path, run_dir),
            "log": relative(log_path, run_dir) if raw_log and log_path.is_file() else None,
            "wave": relative(wave_path, run_dir) if raw_wave and wave_path.is_file() else None,
        }
        key = (test_name, backend, mode)
        canonical = report_path.stem.endswith(f"_{backend}_{_gls_scenario(mode)}")
        previous = record_map.get(key)
        if previous is None or (canonical and not previous[0]):
            record_map[key] = (canonical, record)
    records = [entry[1] for entry in record_map.values()]
    if not records:
        return None

    tests = sorted({record["test"] for record in records})
    backends = sorted({record["backend"] for record in records})
    modes = [
        mode
        for mode in ("zero", "unit", "min", "typ", "max")
        if any(record["timing_mode"] == mode for record in records)
    ]
    scenarios = _gls_scenario_records(records)
    summary = _gls_group(scenarios)
    by_backend = {
        backend: _gls_group([record for record in records if record["backend"] == backend])
        for backend in backends
    }
    by_mode = {
        mode: _gls_group([record for record in scenarios if record["timing_mode"] == mode])
        for mode in modes
    }
    by_scenario = {
        _gls_scenario(mode): _gls_group(
            [record for record in scenarios if record["timing_mode"] == mode]
        )
        for mode in modes
    }
    by_test = {
        test_name: _gls_group([record for record in scenarios if record["test"] == test_name])
        for test_name in tests
    }
    return {
        **summary,
        "pdk": pdk,
        "tests": tests,
        "backends": backends,
        "timing_modes": modes,
        "scenarios": [_gls_scenario(mode) for mode in modes],
        "artifacts": relative(stage_dir, run_dir),
        "interconnect_delays": (
            ("enabled" if report_stage == "post_pnr" else "none")
            if any(mode in {"min", "typ", "max"} for mode in modes)
            else "not-applicable"
        ),
        "by_backend": by_backend,
        "by_mode": by_mode,
        "by_scenario": by_scenario,
        "by_test": by_test,
        "records": records,
        "scenario_records": scenarios,
        "failures": [record for record in scenarios if record["status"] != "pass"],
        "backend_failures": [record for record in records if record["status"] != "pass"],
    }


def _collect_activity_analysis(
    top: str, run_dir: Path, pdk: str, stage: str, subdir: str
) -> dict[str, Any] | None:
    """Collect one activity-driven sign-off summary."""

    path = pdk_run_layout(run_dir, pdk=pdk, top=top).signoff_stage_root(stage) / subdir / "summary.json"
    data = _json_object(path)
    if not isinstance(data.get("reports"), list):
        return None
    data["summary"] = relative(path, run_dir)
    return data


def collect_power_analysis(
    top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
) -> dict[str, Any] | None:
    """Collect activity-based power analysis driven by direct GLS traces."""

    return _collect_activity_analysis(top, run_dir, pdk, stage, "power/analysis")


def collect_fusion_analysis(
    top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
) -> dict[str, Any] | None:
    """Collect workload-correlated timing/power analysis."""

    return _collect_activity_analysis(top, run_dir, pdk, stage, "fusion")


def collect_implementation(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect final ORFS implementation artifacts for one PDK."""

    layout = pdk_run_layout(run_dir, pdk=pdk, top=top)
    roots = sorted(
        root.resolve()
        for root in (layout.pnr_dir / "results").glob(f"*/{top}/base")
        if root.is_dir()
    )
    if len(roots) > 1:
        raise ValueError(
            f"ambiguous ORFS results for {top}: " + ", ".join(str(root) for root in roots)
        )
    if not roots:
        return None
    root = roots[0]
    required = ("6_final.v", "6_final.sdc", "6_final.spef", "6_final.odb", "6_final.gds")
    artifacts = {name: relative(root / name, run_dir) for name in required if (root / name).is_file()}
    status = "pass" if len(artifacts) == len(required) else "partial"
    log = layout.pnr_log_dir / f"{top}_pnr.log"
    return {
        "status": status,
        "platform_root": relative(root, run_dir),
        "artifacts": artifacts,
        "log": relative(log, run_dir) if log.is_file() else None,
    }


def collect_physical_signoff(run_dir: Path, pdk: str) -> dict[str, Any] | None:
    """Collect ORFS physical checks as part of post-implementation sign-off."""

    path = run_dir / "signoff" / pdk / "post_pnr" / "physical" / "summary.json"
    if not path.is_file():
        return None
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return {"status": "unknown", "summary": relative(path, run_dir)}
    if not isinstance(data, dict):
        return {"status": "unknown", "summary": relative(path, run_dir)}

    def normalize(value: Any) -> Any:
        if isinstance(value, dict):
            return {key: normalize(item) for key, item in value.items()}
        if isinstance(value, list):
            return [normalize(item) for item in value]
        if isinstance(value, str):
            candidate = Path(value)
            if candidate.is_absolute():
                return relative(candidate, run_dir)
        return value

    result = normalize(data)
    result["summary"] = relative(path, run_dir)
    return result

def _phase_status(*values: str | None) -> str:
    """Aggregate ordered lifecycle evidence into one phase status."""

    statuses = [str(value or "missing") for value in values]
    if any(value in {"fail", "error"} for value in statuses):
        return "fail"
    if "unsupported" in statuses:
        return "unsupported"
    if any(value in {"review", "warn"} for value in statuses):
        return "review"
    if any(value in {"missing", "partial", "unknown", "incomplete"} for value in statuses):
        return "incomplete"
    return "pass"


def flow_summary(metrics: dict[str, Any]) -> dict[str, Any]:
    """Summarize the complete FlexSoC lifecycle in user-facing order."""

    def status(name: str) -> str:
        value = metrics.get(name)
        if isinstance(value, dict):
            return str(value.get("status", "pass" if value else "missing"))
        return "missing"

    synthesis = metrics.get("synthesis")
    synthesis_status = "missing"
    if isinstance(synthesis, dict):
        synthesis_status = (
            "pass"
            if int(synthesis.get("errors", 0)) == 0 and bool(synthesis.get("netlist"))
            else "fail"
        )

    pre = _phase_status(
        status("sdf"),
        "pass" if metrics.get("sta") else "missing",
        "pass" if metrics.get("power_estimate") else "missing",
        status("post_syn_gls"),
        status("power_analysis"),
        status("fusion_analysis"),
    )
    implementation = status("implementation")
    routed = metrics.get("post_pnr")
    if isinstance(routed, dict):
        post = _phase_status(
            str(routed.get("sdf", {}).get("status", "missing")) if isinstance(routed.get("sdf"), dict) else "missing",
            "pass" if routed.get("sta") else "missing",
            "pass" if routed.get("power_estimate") else "missing",
            str(routed.get("gls", {}).get("status", "missing")) if isinstance(routed.get("gls"), dict) else "missing",
            str(routed.get("power_analysis", {}).get("status", "missing")) if isinstance(routed.get("power_analysis"), dict) else "missing",
            str(routed.get("fusion_analysis", {}).get("status", "missing")) if isinstance(routed.get("fusion_analysis"), dict) else "missing",
        )
    else:
        post = "missing"

    stages = {
        "lint": status("lint"),
        "cdc_rdc": status("cdc_rdc"),
        "functional": status("regression"),
        "formal": status("formal"),
        "synthesis": synthesis_status,
        "equivalence": status("equivalence"),
        "pre_implementation_signoff": pre,
        "implementation": implementation,
        "post_implementation_signoff": _phase_status(post, status("physical_signoff")),
    }
    overall = _phase_status(*stages.values())
    return {
        "order": list(stages),
        "stages": stages,
        "status": overall,
        "complete": overall == "pass",
    }

def verification_summary(metrics: dict[str, Any]) -> dict[str, Any]:
    """Summarize PDK-independent verification in lifecycle order."""

    result: dict[str, Any] = {}
    cdc_rdc = metrics.get("cdc_rdc")
    if isinstance(cdc_rdc, dict):
        result["cdc_rdc"] = {
            "status": cdc_rdc.get("status", "unknown"),
            "cdc": cdc_rdc.get("cdc", {}),
            "rdc": cdc_rdc.get("rdc", {}),
            "obligations": cdc_rdc.get("verification_obligations", 0),
        }

    formal = metrics.get("formal")
    if isinstance(formal, dict):
        result["formal"] = {
            "status": formal.get("status", "unknown"),
            **formal.get("summary", {}),
        }

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
        result["sta"] = {"status": "pass", "clock_model": "ideal", "interconnect": "none"}
    if metrics.get("power_estimate"):
        result["power"] = {"status": "pass"}
    power_activity = metrics.get("power_analysis")
    if isinstance(power_activity, dict):
        result["power_activity"] = {
            "status": power_activity.get("status", "unknown"),
            "passed": power_activity.get("passed", 0),
            "total": power_activity.get("total", 0),
        }
    fusion = metrics.get("fusion_analysis")
    if isinstance(fusion, dict):
        result["fusion"] = {
            "status": fusion.get("status", "unknown"),
            "passed": fusion.get("passed", 0),
            "total": fusion.get("total", 0),
        }
    gls = metrics.get("post_syn_gls")
    if isinstance(gls, dict):
        result["post_syn_gls"] = {
            "status": gls.get("status", "unknown"),
            "passed": gls.get("passed", 0),
            "total": gls.get("total", 0),
            "failed": gls.get("failed", 0),
            "missing": gls.get("missing", 0),
            "interconnect_delays": gls.get("interconnect_delays", "unknown"),
        }
    post_pnr = metrics.get("post_pnr")
    if isinstance(post_pnr, dict):
        routed: dict[str, Any] = {}
        sdf = post_pnr.get("sdf")
        if isinstance(sdf, dict):
            routed["sdf"] = {"status": sdf.get("status", "unknown"), "count": sdf.get("count", 0)}
        if post_pnr.get("sta"):
            routed["sta"] = {"status": "pass", "clock_model": "propagated", "interconnect": "spef"}
        if post_pnr.get("power_estimate"):
            routed["power"] = {"status": "pass"}
        gls = post_pnr.get("gls")
        if isinstance(gls, dict):
            routed["gls"] = {
                "status": gls.get("status", "unknown"),
                "passed": gls.get("passed", 0),
                "total": gls.get("total", 0),
                "interconnect_delays": gls.get("interconnect_delays", "unknown"),
            }
        activity = post_pnr.get("power_analysis")
        if isinstance(activity, dict):
            routed["power_activity"] = {
                "status": activity.get("status", "unknown"),
                "passed": activity.get("passed", 0),
                "total": activity.get("total", 0),
            }
        fusion = post_pnr.get("fusion_analysis")
        if isinstance(fusion, dict):
            routed["fusion"] = {
                "status": fusion.get("status", "unknown"),
                "passed": fusion.get("passed", 0),
                "total": fusion.get("total", 0),
            }
        if routed:
            result["post_pnr"] = routed
    physical = metrics.get("physical_signoff")
    if isinstance(physical, dict):
        routed = result.setdefault("post_pnr", {})
        routed["physical"] = {
            "status": physical.get("status", "unknown"),
            "checks": physical.get("checks", {}),
            "summary": physical.get("summary"),
        }
    return result


def closure_status(metrics: dict[str, Any]) -> dict[str, Any]:
    """Summarize whether the current run contains every standard closure stage."""

    stages: dict[str, str] = {}
    lint = metrics.get("lint")
    stages["lint"] = str(lint.get("status")) if isinstance(lint, dict) else "missing"
    cdc_rdc = metrics.get("cdc_rdc")
    stages["cdc_rdc"] = str(cdc_rdc.get("status")) if isinstance(cdc_rdc, dict) else "missing"
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
    order = ["lint", "cdc_rdc", "formal", "regression", "synthesis", "equivalence", "sdf", "sta", "power"]
    gls = metrics.get("post_syn_gls")
    stages["post_syn_gls"] = str(gls.get("status", "unknown")) if isinstance(gls, dict) else "missing"
    order.append("post_syn_gls")
    power_activity = metrics.get("power_analysis")
    stages["power_activity"] = (
        str(power_activity.get("status", "unknown")) if isinstance(power_activity, dict) else "missing"
    )
    order.append("power_activity")
    fusion = metrics.get("fusion_analysis")
    stages["fusion"] = str(fusion.get("status", "unknown")) if isinstance(fusion, dict) else "missing"
    order.append("fusion")

    implementation = metrics.get("implementation")
    stages["implementation"] = (
        str(implementation.get("status", "unknown")) if isinstance(implementation, dict) else "missing"
    )
    order.append("implementation")

    physical = metrics.get("physical_signoff")
    stages["physical_signoff"] = (
        str(physical.get("status", "unknown")) if isinstance(physical, dict) else "missing"
    )
    order.append("physical_signoff")

    post_pnr = metrics.get("post_pnr")
    routed = post_pnr if isinstance(post_pnr, dict) else {}
    routed_sdf = routed.get("sdf")
    stages["post_pnr_sdf"] = (
        str(routed_sdf.get("status", "unknown")) if isinstance(routed_sdf, dict) else "missing"
    )
    stages["post_pnr_sta"] = "pass" if routed.get("sta") else "missing"
    stages["post_pnr_power"] = "pass" if routed.get("power_estimate") else "missing"
    routed_gls = routed.get("gls")
    stages["post_pnr_gls"] = (
        str(routed_gls.get("status", "unknown")) if isinstance(routed_gls, dict) else "missing"
    )
    routed_activity = routed.get("power_analysis")
    stages["post_pnr_power_activity"] = (
        str(routed_activity.get("status", "unknown"))
        if isinstance(routed_activity, dict)
        else "missing"
    )
    routed_fusion = routed.get("fusion_analysis")
    stages["post_pnr_fusion"] = (
        str(routed_fusion.get("status", "unknown")) if isinstance(routed_fusion, dict) else "missing"
    )
    order.extend((
        "post_pnr_sdf", "post_pnr_sta", "post_pnr_gls", "post_pnr_power",
        "post_pnr_power_activity", "post_pnr_fusion",
    ))
    values = tuple(stages.values())
    if any(status in {"fail", "error"} for status in values):
        overall = "fail"
    elif any(status in {"missing", "partial", "unknown"} for status in values):
        overall = "incomplete"
    elif any(status in {"review", "warn"} for status in values):
        overall = "review"
    else:
        overall = "pass"
    return {
        "order": order,
        "stages": stages,
        "status": overall,
        "complete": overall == "pass",
    }


def collect_metrics(
    top: str,
    run_dir: Path,
    *,
    pdk: str | None = None,
    provenance: Mapping[str, Any] | None = None,
) -> dict[str, Any]:
    """Collect one logical run plus the selected PDK-scoped implementation."""

    selected_pdk = pdk or "sky130"
    layout = pdk_run_layout(run_dir, pdk=selected_pdk, top=top)
    metrics: dict[str, Any] = {
        "schema_version": 18,
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
        ("cdc_rdc", collect_cdc_rdc),
        ("formal", collect_formal),
        ("regression", collect_regression),
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
        ("fusion_analysis", collect_fusion_analysis),
    ):
        data = collector(top, run_dir, selected_pdk)
        if data is not None:
            metrics[name] = data

    implementation = collect_implementation(top, run_dir, selected_pdk)
    if implementation is not None:
        metrics["implementation"] = implementation

    post_pnr: dict[str, Any] = {}
    for name, collector in (
        ("sdf", collect_sdf),
        ("gls", collect_post_syn_gls),
        ("sta", collect_sta),
        ("power_estimate", collect_power_estimate),
        ("power_analysis", collect_power_analysis),
        ("fusion_analysis", collect_fusion_analysis),
    ):
        data = collector(top, run_dir, selected_pdk, "post_route")
        if data is not None:
            post_pnr[name] = data
    if post_pnr:
        metrics["post_pnr"] = post_pnr

    physical = collect_physical_signoff(run_dir, selected_pdk)
    if physical is not None:
        metrics["physical_signoff"] = physical

    synthesis = metrics.get("synthesis")
    if isinstance(synthesis, dict):
        netlist = layout.syn_dir / f"{top}_synth.v"
        synthesis["netlist"] = relative(netlist, run_dir) if netlist.is_file() else None
    metrics["verification"] = verification_summary(metrics)
    metrics["signoff"] = signoff_summary(metrics)
    metrics["flow"] = flow_summary(metrics)
    metrics["closure"] = closure_status(metrics)
    metrics["technical_status"] = technical_status(metrics)
    if provenance is not None:
        metrics["provenance"] = dict(provenance)
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
    table.add_column("Metric", style="bright_cyan", no_wrap=True)
    table.add_column("Value", style="white")
    return table


def status_markup(status: str) -> str:
    """Return a compact colored technical status label."""

    colors = {
        "pass": "bold green",
        "fail": "bold red",
        "error": "bold red",
        "review": "bold orange1",
        "partial": "bold orange1",
        "warn": "bold orange1",
        "safe": "bold bright_cyan",
        "unsupported": "bold bright_cyan",
        "missing": "bold bright_cyan",
        "unknown": "bold bright_cyan",
        "incomplete": "bold orange1",
    }
    normalized = status.strip().lower()
    color = colors.get(normalized, "bright_cyan")
    return f"[{color}]{normalized.upper()}[/{color}]"


def _number_markup(value: object, *, digits: int = 6, scale: float = 1.0, suffix: str = "") -> str:
    """Render one optional numeric QoR value with sign-aware color."""

    if value is None:
        return "[grey70]—[/grey70]"
    number = float(value) * scale
    color = "green" if number >= 0 else "red"
    return f"[{color}]{number:+.{digits}f}{suffix}[/{color}]"


def sta_qor_table(scenarios: Mapping[str, Any]) -> Table | None:
    """Render one compact corner/mode STA matrix from normalized metrics."""

    rows: list[tuple[str, str, Mapping[str, Any]]] = []
    for corner in ("ss", "tt", "ff"):
        modes = scenarios.get(corner)
        if not isinstance(modes, Mapping):
            continue
        for mode in ("setup", "hold"):
            values = modes.get(mode)
            if isinstance(values, Mapping):
                rows.append((corner, mode, values))
    if not rows:
        return None

    table = Table(box=None, pad_edge=False, header_style="bold grey70")
    table.add_column("Corner", style="white", no_wrap=True)
    table.add_column("Mode", style="white", no_wrap=True)
    table.add_column("Status", no_wrap=True)
    table.add_column("WNS (ns)", justify="right", no_wrap=True)
    table.add_column("TNS (ns)", justify="right", no_wrap=True)
    table.add_column("Viol", justify="right", no_wrap=True)
    table.add_column("Unconstr", justify="right", no_wrap=True)
    for corner, mode, values in rows:
        violations = int(values.get("reported_violating_paths", 0) or 0)
        unconstrained = int(values.get("reported_unconstrained_paths", 0) or 0)
        table.add_row(
            corner, mode, status_markup(str(values.get("status", "unknown"))),
            _number_markup(values.get("wns")), _number_markup(values.get("tns")),
            f"[{count_color(violations, error=True)}]{violations}[/]",
            f"[{count_color(unconstrained, error=True)}]{unconstrained}[/]",
        )
    return table


def gls_matrix_table(gls: Mapping[str, Any]) -> Table | None:
    """Render test × timing-mode GLS qualification without parsing raw reports."""

    tests = [str(item) for item in gls.get("tests", [])]
    modes = [str(item) for item in gls.get("timing_modes", [])]
    records = gls.get("scenario_records")
    if not tests or not modes or not isinstance(records, list):
        return None
    indexed = {
        (str(item.get("test", "")), str(item.get("timing_mode", ""))): item
        for item in records if isinstance(item, Mapping)
    }
    table = Table(box=None, pad_edge=False, header_style="bold grey70")
    table.add_column("Test", style="white", no_wrap=True)
    for mode in modes:
        table.add_column(mode, justify="center", no_wrap=True)
    for test in tests:
        cells = []
        for mode in modes:
            record = indexed.get((test, mode))
            if record is None:
                cells.append("[grey70]—[/grey70]")
                continue
            status = str(record.get("status", "unknown"))
            backend = str(record.get("backend") or "")
            cell = status_markup(status)
            if backend:
                cell += f" [grey70]{backend}[/grey70]"
            cells.append(cell)
        table.add_row(test, *cells)
    return table


def power_estimate_table(power: Mapping[str, Any]) -> Table | None:
    """Render vectorless power by corner in human units while keeping JSON in watts."""

    corners = power.get("corners")
    if not isinstance(corners, Mapping) or not corners:
        return None
    table = Table(box=None, pad_edge=False, header_style="bold grey70")
    table.add_column("Corner", style="white", no_wrap=True)
    table.add_column("Internal (mW)", justify="right")
    table.add_column("Switching (mW)", justify="right")
    table.add_column("Leakage (µW)", justify="right")
    table.add_column("Total (mW)", justify="right")
    for corner in ("ss", "tt", "ff"):
        values = corners.get(corner)
        if not isinstance(values, Mapping):
            continue
        table.add_row(
            corner,
            _number_markup(values.get("internal_w"), digits=3, scale=1e3),
            _number_markup(values.get("switching_w"), digits=3, scale=1e3),
            _number_markup(values.get("leakage_w"), digits=3, scale=1e6),
            _number_markup(values.get("total_w"), digits=3, scale=1e3),
        )
    return table


def workload_table(summary: Mapping[str, Any]) -> Table | None:
    """Render one activity/fusion workload catalogue from its normalized reports."""

    reports = summary.get("reports")
    if not isinstance(reports, list) or not reports:
        return None
    table = Table(box=None, pad_edge=False, header_style="bold grey70")
    table.add_column("Workload", style="white", no_wrap=True)
    table.add_column("Test", style="grey70", no_wrap=True)
    table.add_column("Backend", justify="center", no_wrap=True)
    table.add_column("Timing", justify="center", no_wrap=True)
    table.add_column("Status", no_wrap=True)
    for report in reports:
        if not isinstance(report, Mapping):
            continue
        table.add_row(
            str(report.get("workload", report.get("spec", "-"))),
            str(report.get("test", "-")),
            str(report.get("backend", "-")),
            str(report.get("timing_mode", "-")),
            status_markup(str(report.get("status", "unknown"))),
        )
    return table


def technical_status(metrics: Mapping[str, Any]) -> str:
    """Normalize flow closure to the public technical status contract."""

    flow = metrics.get("flow")
    status = str(
        flow.get("status", "incomplete") if isinstance(flow, dict) else "incomplete"
    ).lower()
    if status in {"fail", "error"}:
        return "FAIL"
    if status == "unsupported":
        return "UNSUPPORTED"
    return "PASS" if status == "pass" else "REVIEW"


def provenance_summary(states: Mapping[str, str]) -> dict[str, Any]:
    """Return deterministic setup states and the strongest provenance condition."""

    normalized = {stage: str(state).upper() for stage, state in sorted(states.items())}
    order = ("INVALID", "STALE", "MODIFIED", "VALIDATED_OVERRIDE", "CLEAN")
    overall = next((state for state in order if state in normalized.values()), "INVALID")
    return {"status": overall, "stages": normalized}


def provenance_markup(status: str) -> str:
    """Render provenance independently from technical PASS/FAIL semantics."""

    normalized = status.strip().upper()
    color = {
        "CLEAN": "bold bright_cyan",
        "VALIDATED_OVERRIDE": "bold #87afff",
        "MODIFIED": "bold orange1",
        "STALE": "bold orange1",
        "INVALID": "bold red",
    }.get(normalized, "bold bright_cyan")
    return f"[{color}]{normalized}[/{color}]"


def _show_signoff_stage(console: Console, title: str, stage: dict[str, Any]) -> None:
    """Render one compact sign-off stage in execution order."""

    console.print(f"\n[bold orange1]{title}[/bold orange1]")
    table = metric_table()

    physical = stage.get("physical", {})
    if isinstance(physical, dict) and physical:
        table.add_row("Physical closure", status_markup(str(physical.get("status", "unknown"))))
        checks = physical.get("checks", {})
        if isinstance(checks, dict):
            for label, key in (
                ("Route DRC", "route_drc"),
                ("Antenna", "antenna"),
                ("GDS DRC", "gds_drc"),
                ("LVS", "lvs"),
                ("IR / PDN", "ir_drop"),
            ):
                check = checks.get(key)
                if isinstance(check, dict):
                    table.add_row(label, status_markup(str(check.get("status", "unknown"))))

    sdf = stage.get("sdf", {})
    if isinstance(sdf, dict) and sdf:
        count = int(sdf.get("count", 0) or 0)
        suffix = f" · corners={count}" if count else ""
        table.add_row("SDF", status_markup(str(sdf.get("status", "unknown"))) + suffix)

    sta = stage.get("sta", {})
    if isinstance(sta, dict) and sta:
        table.add_row(
            "STA",
            status_markup(str(sta.get("status", "unknown")))
            + f" · {sta.get('clock_model', 'unknown')} clock · {sta.get('interconnect', 'unknown')}",
        )

    gls = stage.get("gls", stage.get("post_syn_gls", {}))
    if isinstance(gls, dict) and gls:
        table.add_row(
            "Gate-level simulation",
            f"{gls.get('passed', 0)}/{gls.get('total', 0)}  "
            + status_markup(str(gls.get("status", "unknown")))
            + f" · interconnect {gls.get('interconnect_delays', 'unknown')}",
        )

    power = stage.get("power", {})
    if isinstance(power, dict) and power:
        table.add_row("Power estimate", status_markup(str(power.get("status", "unknown"))))

    activity = stage.get("power_activity", {})
    if isinstance(activity, dict) and activity:
        table.add_row(
            "Activity power",
            f"{activity.get('passed', 0)}/{activity.get('total', 0)}  "
            + status_markup(str(activity.get("status", "unknown"))),
        )

    fusion = stage.get("fusion", {})
    if isinstance(fusion, dict) and fusion:
        table.add_row(
            "Timing / power fusion",
            f"{fusion.get('passed', 0)}/{fusion.get('total', 0)}  "
            + status_markup(str(fusion.get("status", "unknown"))),
        )

    console.print(table)


def show_check(path: Path) -> None:
    """Render one lifecycle-ordered closure dashboard from saved metrics."""

    if not path.is_file():
        raise FileNotFoundError(f"metrics file not found: {path}; run: fx metrics")

    data = json.loads(path.read_text(encoding="utf-8"))
    console = Console()
    console.print(
        f"[bold orange1]FlexSoC run check[/bold orange1] · "
        f"[bold bright_cyan]{data.get('top', 'unknown')}[/bold bright_cyan]"
    )
    provenance = data.get("provenance", {})
    provenance_status = (
        str(provenance.get("status", "INVALID")) if isinstance(provenance, dict) else "INVALID"
    )
    console.print(
        f"[bright_cyan]Technical[/bright_cyan] "
        f"{status_markup(str(data.get('technical_status', technical_status(data))))} · "
        f"[bright_cyan]Provenance[/bright_cyan] {provenance_markup(provenance_status)}"
    )

    flow = data.get("flow", {})
    if isinstance(flow, dict) and flow:
        console.print("\n[bold orange1]Flow[/bold orange1]")
        table = Table(box=None, pad_edge=False, header_style="bold bright_cyan")
        table.add_column("Main step")
        table.add_column("Status")
        labels = {
            "lint": "RTL lint",
            "cdc_rdc": "CDC / RDC",
            "functional": "Functional verification",
            "formal": "Formal verification",
            "synthesis": "Synthesis",
            "equivalence": "RTL ↔ synthesis equivalence",
            "pre_implementation_signoff": "Pre-implementation sign-off",
            "implementation": "Implementation / PnR",
            "post_implementation_signoff": "Post Sign-Off",
        }
        for name in flow.get("order", []):
            status = str(flow.get("stages", {}).get(name, "missing"))
            table.add_row(labels.get(name, name), status_markup(status))
        console.print(table)
        overall = str(flow.get("status", "incomplete"))
        style = {"pass": "green", "review": "orange1", "fail": "red"}.get(overall, "bright_cyan")
        console.print(
            f"[bright_cyan]Run status:[/bright_cyan] "
            f"[bold {style}]{overall.upper()}[/bold {style}]"
        )

    if isinstance(provenance, dict) and isinstance(provenance.get("stages"), dict):
        console.print("\n[bold orange1]Provenance[/bold orange1]")
        table = Table(box=None, pad_edge=False, header_style="bold bright_cyan")
        table.add_column("Setup", style="bright_cyan", no_wrap=True)
        table.add_column("State")
        table.add_column("Action", style="#87d7ff")
        for stage, state in provenance["stages"].items():
            normalized = str(state).upper()
            action = (
                f"fx validate_override --set STAGE={stage}" if normalized == "MODIFIED"
                else f"fx {stage}" if normalized == "STALE"
                else f"repair inputs; fx {stage}" if normalized == "INVALID"
                else "accepted for current lineage" if normalized == "VALIDATED_OVERRIDE"
                else "-"
            )
            table.add_row(str(stage), provenance_markup(normalized), action)
        console.print(table)

    lint = data.get("lint")
    if isinstance(lint, dict):
        console.print(
            "\n[bold orange1]RTL lint[/bold orange1]  "
            "[bright_cyan]Slang → Verilator[/bright_cyan]"
        )
        table = Table(box=None, pad_edge=False, header_style="bold bright_cyan")
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

    cdc_rdc = data.get("cdc_rdc")
    if isinstance(cdc_rdc, dict):
        console.print(
            "\n[bold orange1]CDC / RDC[/bold orange1]  "
            "[bright_cyan]post-lint structural analysis[/bright_cyan]"
        )
        table = metric_table()
        table.add_row("Status", status_markup(str(cdc_rdc.get("status", "unknown"))))
        table.add_row(
            "Domains",
            f"clocks={cdc_rdc.get('clock_domains', 0)} · resets={cdc_rdc.get('reset_domains', 0)} · "
            f"sequential={cdc_rdc.get('sequential_elements', 0)}",
        )
        for label, key in (("CDC", "cdc"), ("RDC", "rdc")):
            values = cdc_rdc.get(key, {})
            if isinstance(values, dict):
                table.add_row(
                    label,
                    f"raw={values.get('raw_crossings', 0)} · safe={values.get('safe', 0)} · "
                    f"review={values.get('review', 0)} · warn={values.get('warnings', 0)} · "
                    f"error={values.get('errors', 0)}",
                )
        table.add_row("Obligations", str(cdc_rdc.get("verification_obligations", 0)))
        table.add_row("Report", str(cdc_rdc.get("report", "-")))
        console.print(table)

    regression = data.get("regression")
    if isinstance(regression, dict):
        console.print("\n[bold orange1]Functional verification[/bold orange1]")
        table = metric_table()
        table.add_row("Status", status_markup(str(regression.get("status", "unknown"))))
        table.add_row("Generated tests", str(regression.get("test_count", 0)))
        for backend, values in regression.get("backends", {}).items():
            table.add_row(f"{backend} logs", str(values.get("tests_logged", 0)))
        coverage = regression.get("coverage", {})
        for label, key in (("Coverage all", "all"), ("Coverage design", "design")):
            values = coverage.get(key, {}) if isinstance(coverage, dict) else {}
            if isinstance(values, dict) and values:
                table.add_row(
                    label,
                    f"{values.get('hit', 0)}/{values.get('total', 0)}  "
                    f"{float(values.get('percent', 0.0) or 0.0):.2f}%",
                )
        console.print(table)

    formal = data.get("formal")
    if isinstance(formal, dict):
        console.print("\n[bold orange1]Formal verification[/bold orange1]")
        table = Table(box=None, pad_edge=False, header_style="bold bright_cyan")
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
    if isinstance(synthesis, dict):
        console.print("\n[bold orange1]Synthesis[/bold orange1]")
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
    if isinstance(equiv, dict):
        console.print("\n[bold orange1]RTL ↔ synthesis equivalence[/bold orange1]")
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

    signoff = data.get("signoff", {})
    if isinstance(signoff, dict) and signoff:
        _show_signoff_stage(console, "Pre-implementation sign-off", signoff)
        sta_table = sta_qor_table(data.get("sta", {}))
        if sta_table is not None:
            console.print("[bold bright_cyan]STA QoR[/bold bright_cyan]")
            console.print(sta_table)
        gls_table = gls_matrix_table(data.get("post_syn_gls", {}))
        if gls_table is not None:
            console.print("[bold bright_cyan]GLS matrix[/bold bright_cyan]")
            console.print(gls_table)
        power_table = power_estimate_table(data.get("power_estimate", {}))
        if power_table is not None:
            console.print("[bold bright_cyan]Power estimate[/bold bright_cyan]")
            console.print(power_table)
        for label, key in (("Activity power workloads", "power_analysis"), ("Timing / power fusion workloads", "fusion_analysis")):
            table = workload_table(data.get(key, {}))
            if table is not None:
                console.print(f"[bold bright_cyan]{label}[/bold bright_cyan]")
                console.print(table)

    implementation = data.get("implementation")
    if isinstance(implementation, dict):
        console.print("\n[bold orange1]Implementation / PnR[/bold orange1]")
        table = metric_table()
        table.add_row("Status", status_markup(str(implementation.get("status", "unknown"))))
        table.add_row("Results", str(implementation.get("platform_root", "-")))
        artifacts = implementation.get("artifacts", {})
        if isinstance(artifacts, dict):
            table.add_row("Final artifacts", f"{len(artifacts)}/5")
        if implementation.get("log"):
            table.add_row("Log", str(implementation.get("log")))
        console.print(table)

    routed = signoff.get("post_pnr", {}) if isinstance(signoff, dict) else {}
    if isinstance(routed, dict):
        routed = dict(routed)
        physical = data.get("physical_signoff")
        if isinstance(physical, dict):
            routed["physical"] = physical
        if routed:
            _show_signoff_stage(console, "Post Sign-Off", routed)
            post_pnr = data.get("post_pnr", {})
            if isinstance(post_pnr, dict):
                sta_table = sta_qor_table(post_pnr.get("sta", {}))
                if sta_table is not None:
                    console.print("[bold bright_cyan]STA QoR[/bold bright_cyan]")
                    console.print(sta_table)
                gls_table = gls_matrix_table(post_pnr.get("gls", {}))
                if gls_table is not None:
                    console.print("[bold bright_cyan]GLS matrix[/bold bright_cyan]")
                    console.print(gls_table)
                power_table = power_estimate_table(post_pnr.get("power_estimate", {}))
                if power_table is not None:
                    console.print("[bold bright_cyan]Power estimate[/bold bright_cyan]")
                    console.print(power_table)
                for label, key in (("Activity power workloads", "power_analysis"), ("Timing / power fusion workloads", "fusion_analysis")):
                    table = workload_table(post_pnr.get(key, {}))
                    if table is not None:
                        console.print(f"[bold bright_cyan]{label}[/bold bright_cyan]")
                        console.print(table)

    console.print(f"\n[bright_cyan]Detailed metrics:[/bright_cyan] [#87d7ff]{path}[/#87d7ff]")


def _git(root: Path, *args: str) -> str | None:
    """Return one Git command result, or None outside a Git checkout."""

    result = subprocess.run(
        ["git", "-C", str(root), *args],
        check=False,
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        return None
    return result.stdout.strip()


def _file_sha256(path: Path) -> str | None:
    """Return a SHA256 digest when the file exists."""

    if not path.is_file():
        return None
    return hashlib.sha256(path.read_bytes()).hexdigest()


def _path_sha256(path: Path) -> str | None:
    """Hash one file or directory tree without embedding its absolute path."""

    path = path.expanduser().absolute()
    if path.is_file():
        return _file_sha256(path)
    if not path.is_dir():
        return None
    digest = hashlib.sha256()
    for item in sorted(candidate for candidate in path.rglob("*") if candidate.is_file()):
        digest.update(item.relative_to(path).as_posix().encode())
        digest.update(bytes.fromhex(_file_sha256(item) or ""))
    return digest.hexdigest()


def _json_sha256(data: object) -> str:
    """Hash canonical JSON for deterministic configuration fingerprints."""

    payload = json.dumps(data, sort_keys=True, separators=(",", ":"), ensure_ascii=True)
    return hashlib.sha256(payload.encode()).hexdigest()


@dataclass(slots=True)
class Provenance:
    """Track generated collateral against effective inputs and validated overrides."""

    path: Path
    run_root: Path

    def _load(self) -> dict[str, Any]:
        if not self.path.is_file():
            return {"schema_version": 1, "stages": {}}
        try:
            data = json.loads(self.path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            raise ValueError(f"invalid provenance manifest {self.path}: {exc}") from exc
        if data.get("schema_version") != 1 or not isinstance(data.get("stages"), dict):
            raise ValueError(f"invalid provenance manifest: {self.path}")
        return data

    def _write(self, data: Mapping[str, Any]) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        temp = self.path.with_name(f".{self.path.name}.{os.getpid()}.tmp")
        temp.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        temp.replace(self.path)

    def _key(self, path: Path) -> str:
        resolved = path.expanduser().absolute()
        try:
            return resolved.relative_to(self.run_root.resolve()).as_posix()
        except ValueError:
            return str(resolved)

    def _resolve(self, key: str) -> Path:
        path = Path(key)
        return path if path.is_absolute() else self.run_root / path

    def _snapshot(self, paths: Sequence[Path]) -> list[dict[str, str | None]]:
        return [{"path": self._key(path), "sha256": _path_sha256(path)} for path in paths]

    @staticmethod
    def _fingerprint(record: Mapping[str, Any]) -> str:
        return _json_sha256({
            "config": record.get("config", {}),
            "parents": record.get("parents", {}),
            "inputs": [item.get("sha256") for item in record.get("inputs", ())],
            "input_paths_match": record.get("input_paths_match", True),
            "generated": [
                (item.get("path"), item.get("effective_sha256"))
                for item in record.get("generated", ())
            ],
        })

    def current_fingerprint(
        self, stage: str, *, inputs: Sequence[Path], config: Mapping[str, object],
        parents: Mapping[str, str | None] | None = None,
    ) -> str | None:
        """Fingerprint the effective stage state, including unsaved upstream changes."""

        record = self._load()["stages"].get(stage)
        if not isinstance(record, dict):
            return None
        current_inputs = self._snapshot(inputs)
        current = {
            "config": dict(sorted(config.items())),
            "parents": dict(parents or {}),
            "inputs": current_inputs,
            "input_paths_match": [item.get("path") for item in record.get("inputs", ())]
            == [item["path"] for item in current_inputs],
            "generated": [
                {
                    "path": item.get("path"),
                    "effective_sha256": _path_sha256(
                        self._resolve(str(item.get("path", "")))
                    ),
                }
                for item in record.get("generated", ())
            ],
        }
        return self._fingerprint(current)

    def record(
        self, stage: str, *, inputs: Sequence[Path], generated: Sequence[Path],
        config: Mapping[str, object], parents: Mapping[str, str | None] | None = None,
    ) -> str:
        """Record one successful canonical setup and return its fingerprint."""

        generated_state = self._snapshot(generated)
        missing = [item["path"] for item in generated_state if item["sha256"] is None]
        if missing:
            raise FileNotFoundError(f"{stage}: generated artifact missing: {', '.join(missing)}")
        data = self._load()
        record: dict[str, Any] = {
            "config": dict(sorted(config.items())),
            "parents": dict(parents or {}),
            "inputs": self._snapshot(inputs),
            "input_paths_match": True,
            "generated": [
                {
                    "path": item["path"],
                    "generated_sha256": item["sha256"],
                    "effective_sha256": item["sha256"],
                }
                for item in generated_state
            ],
        }
        record["fingerprint"] = self._fingerprint(record)
        data["stages"][stage] = record
        self._write(data)
        return str(record["fingerprint"])

    def generated(self, stage: str) -> tuple[Path, ...]:
        """Return generated artifacts recorded for one stage."""

        record = self._load()["stages"].get(stage)
        if not isinstance(record, dict):
            return ()
        return tuple(
            self._resolve(str(item["path"]))
            for item in record.get("generated", ())
            if isinstance(item, dict) and item.get("path")
        )

    def stages(self) -> tuple[str, ...]:
        """Return recorded setup stages in deterministic order."""

        return tuple(sorted(self._load()["stages"]))

    def state(
        self, stage: str, *, inputs: Sequence[Path], config: Mapping[str, object],
        parents: Mapping[str, str | None] | None = None,
    ) -> str:
        """Derive the current stage state from disk; stored status is never trusted."""

        record = self._load()["stages"].get(stage)
        if not isinstance(record, dict):
            return "INVALID"
        generated = record.get("generated")
        if not isinstance(generated, list) or not generated:
            return "INVALID"
        current_inputs = self._snapshot(inputs)
        if (
            record.get("config") != dict(sorted(config.items()))
            or record.get("parents") != dict(parents or {})
        ):
            return "STALE"
        if record.get("inputs") != current_inputs:
            return "INVALID" if any(item["sha256"] is None for item in current_inputs) else "STALE"

        overridden = False
        for item in generated:
            current = _path_sha256(self._resolve(str(item.get("path", ""))))
            if current is None:
                return "INVALID"
            canonical = item.get("generated_sha256")
            if current == canonical:
                continue
            if current != item.get("effective_sha256"):
                return "MODIFIED"
            overridden = True
        return "VALIDATED_OVERRIDE" if overridden else "CLEAN"

    def validate(
        self, stage: str, *, inputs: Sequence[Path], config: Mapping[str, object],
        parents: Mapping[str, str | None] | None = None,
    ) -> str:
        """Accept only current generated-file edits; stale lineage remains rejected."""

        state = self.state(stage, inputs=inputs, config=config, parents=parents)
        if state != "MODIFIED":
            if state == "STALE":
                raise ValueError(
                    f"{stage}: provenance is STALE; source, configuration, or parent lineage changed. "
                    f"Rerun the corresponding `fx <keyword> --setup` phase with the intended effective settings; for a multi-command "
                    "flow persist them with `fx settings ...`. validate_override is only for manually "
                    "MODIFIED generated collateral."
                )
            if state == "INVALID":
                raise ValueError(
                    f"{stage}: provenance is INVALID; required inputs, generated files, or provenance "
                    f"metadata are missing/inconsistent. Rerun the corresponding `fx <keyword> --setup` phase after repairing the inputs."
                )
            raise ValueError(
                f"{stage}: override cannot be validated from state {state}; "
                "validate_override only accepts MODIFIED generated collateral."
            )
        data = self._load()
        record = data["stages"][stage]
        for item in record["generated"]:
            item["effective_sha256"] = _path_sha256(self._resolve(item["path"]))
        record["fingerprint"] = self._fingerprint(record)
        self._write(data)
        return "VALIDATED_OVERRIDE"


def _flexsoc_version(repo_root: Path) -> str:
    """Return the installed or repository FlexSoC version."""

    try:
        return metadata.version("flexsoc")
    except metadata.PackageNotFoundError:
        pyproject = repo_root / "pyproject.toml"
        if not pyproject.is_file():
            return "unknown"
        data = tomllib.loads(pyproject.read_text(encoding="utf-8"))
        return str(data.get("project", {}).get("version", "unknown"))


def _analysis_evidence(run_root: Path) -> dict[str, object]:
    """Return lightweight post-lint analysis evidence for the run manifest."""

    result: dict[str, object] = {}
    lint_dir = run_root / "logs" / "lint"
    if lint_dir.is_dir():
        result["lint"] = {"path": lint_dir.relative_to(run_root).as_posix()}
    summary = run_root / "analysis" / "cdc_rdc" / "summary.json"
    if summary.is_file():
        record: dict[str, object] = {
            "path": summary.relative_to(run_root).as_posix(),
            "sha256": _file_sha256(summary),
        }
        try:
            data = json.loads(summary.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            data = {}
        if isinstance(data, dict):
            record["status"] = data.get("status", "unknown")
            record["cdc_raw"] = data.get("cdc", {}).get("raw_crossings", 0) if isinstance(data.get("cdc"), dict) else 0
            record["rdc_raw"] = data.get("rdc", {}).get("raw_crossings", 0) if isinstance(data.get("rdc"), dict) else 0
            record["obligations"] = data.get("verification_obligations", 0)
        result["cdc_rdc"] = record
    return result


def collect_manifest(
    *,
    top: str,
    run_top: str,
    run_id: str,
    repo_root: Path,
    pdk: str | None = None,
    run_root: Path | None = None,
) -> dict[str, object]:
    """Collect run identity, source revision, environment, and tool versions."""

    environment = collect_environment(repo_root)
    commit = _git(repo_root, "rev-parse", "HEAD")
    status = _git(repo_root, "status", "--porcelain")
    pdk = pdk or os.environ.get("FLEXSOC_PDK") or None
    run_root_value = str(run_root) if run_root is not None else (os.environ.get("FLEXSOC_RUN_ROOT") or None)
    artifact_paths: dict[str, str] | None = None
    analysis: dict[str, object] | None = None
    signoff: dict[str, object] | None = None
    flow: dict[str, object] | None = None
    implementation: dict[str, object] | None = None
    physical_signoff: dict[str, object] | None = None
    closure: dict[str, object] | None = None
    if run_root_value:
        evidence = _analysis_evidence(Path(run_root_value))
        analysis = evidence or None
    if pdk and run_root_value:
        run_root = Path(run_root_value)
        candidates = pdk_run_layout(run_root, pdk=pdk, top=top).as_dict()
        artifact_paths = {
            name: value
            for name, value in candidates.items()
            if Path(value).exists()
        }
        metrics = collect_metrics(top, run_root, pdk=pdk)
        signoff = metrics.get("signoff") if isinstance(metrics.get("signoff"), dict) else None
        flow = metrics.get("flow") if isinstance(metrics.get("flow"), dict) else None
        implementation = metrics.get("implementation") if isinstance(metrics.get("implementation"), dict) else None
        physical_signoff = metrics.get("physical_signoff") if isinstance(metrics.get("physical_signoff"), dict) else None
        closure = metrics.get("closure") if isinstance(metrics.get("closure"), dict) else None

    tools = {
        item["executable"]: {
            "version": item["version"],
            "path": item["path"],
            "version_ok": item.get("version_ok", True),
            "lock_match": item.get("lock_match"),
            "minimum_version": item.get("minimum_version"),
            "locked_version": item.get("locked_version"),
            "locked_ref": item.get("locked_ref"),
            "install_mode": item.get("install_mode"),
        }
        for item in environment["tools"]
        if item["found"]
    }

    return {
        "schema_version": 9,
        "run": {
            "top": top,
            "run_top": run_top,
            "run_id": run_id,
            "pdk": pdk,
            "run_root": run_root_value,
            "artifacts": artifact_paths,
        },
        "git": {
            "commit": commit,
            "dirty": None if status is None else bool(status),
        },
        "environment": {
            "flexsoc": _flexsoc_version(repo_root),
            "python": platform.python_version(),
            "platform": platform.platform(),
            "machine": platform.machine(),
            "uv_lock_sha256": _file_sha256(repo_root / "uv.lock"),
            "toolchain_lock_sha256": _file_sha256(
                repo_root / "src" / "flexsoc" / "backend" / "core" / "toolchain.lock"
            ),
        },
        "toolchain": environment.get("toolchain_lock", {}),
        "analysis": analysis,
        "flow": flow,
        "implementation": implementation,
        "signoff": signoff,
        "physical_signoff": physical_signoff,
        "closure": closure,
        "tools": tools,
    }


def show_manifest(path: Path) -> None:
    """Render run identity, artifacts, environment, and tools in flow order."""

    if not path.is_file():
        raise FileNotFoundError(f"manifest file not found: {path}; run: fx manifest")
    data = json.loads(path.read_text(encoding="utf-8"))
    console = Console()
    run = data.get("run", {})
    env = data.get("environment", {})
    console.print(
        "[bold orange1]FlexSoC manifest[/bold orange1] · "
        f"[bold bright_cyan]{run.get('top', 'unknown')} / "
        f"{run.get('run_id', 'unknown')}[/bold bright_cyan]"
    )

    def section(title: str, rows: list[tuple[str, object]]) -> None:
        console.print(f"\n[bold bright_cyan]{title}[/bold bright_cyan]")
        table = Table(show_header=False, box=None, pad_edge=False)
        table.add_column("Field", style="grey70", no_wrap=True)
        table.add_column("Value", style="white")
        for key, value in rows:
            table.add_row(key, str(value))
        console.print(table)

    dirty = data.get("git", {}).get("dirty")
    section(
        "Run",
        [
            ("TOP", run.get("top", "-")),
            ("RUN_TOP", run.get("run_top", "-")),
            ("RUN_ID", run.get("run_id", "-")),
            ("PDK", run.get("pdk") or "-"),
            ("RUN_ROOT", run.get("run_root") or "-"),
        ],
    )

    flow = data.get("flow")
    if isinstance(flow, dict):
        labels = {
            "lint": "RTL lint",
            "cdc_rdc": "CDC / RDC",
            "functional": "Functional verification",
            "formal": "Formal verification",
            "synthesis": "Synthesis",
            "equivalence": "RTL ↔ synthesis equivalence",
            "pre_implementation_signoff": "Pre-implementation sign-off",
            "implementation": "Implementation / PnR",
            "post_implementation_signoff": "Post Sign-Off",
        }
        stages = flow.get("stages", {})
        section(
            "Flow",
            [
                (labels.get(name, name), str(stages.get(name, "missing")).upper())
                for name in flow.get("order", [])
            ] + [("Overall", str(flow.get("status", "incomplete")).upper())],
        )

    section(
        "Source / environment",
        [
            ("Git commit", data.get("git", {}).get("commit") or "unavailable"),
            ("Git tree", "unknown" if dirty is None else ("dirty" if dirty else "clean")),
            ("FlexSoC", env.get("flexsoc", "unknown")),
            ("Python", env.get("python", "unknown")),
            ("Platform", env.get("platform", "unknown")),
            ("Machine", env.get("machine", "unknown")),
            ("uv.lock SHA256", env.get("uv_lock_sha256") or "missing"),
            ("toolchain.lock SHA256", env.get("toolchain_lock_sha256") or "missing"),
        ],
    )

    analysis = data.get("analysis")
    if isinstance(analysis, dict):
        rows: list[tuple[str, object]] = []
        lint = analysis.get("lint")
        if isinstance(lint, dict):
            rows.append(("RTL lint", lint.get("path", "-")))
        cdc_rdc = analysis.get("cdc_rdc")
        if isinstance(cdc_rdc, dict):
            rows.append((
                "CDC / RDC",
                f"{str(cdc_rdc.get('status', 'unknown')).upper()} · "
                f"CDC raw={cdc_rdc.get('cdc_raw', 0)} · RDC raw={cdc_rdc.get('rdc_raw', 0)} · "
                f"obligations={cdc_rdc.get('obligations', 0)} · {cdc_rdc.get('path', '-')}",
            ))
        if rows:
            section("Verification evidence", rows)

    signoff = data.get("signoff")
    if isinstance(signoff, dict):
        rows: list[tuple[str, object]] = []
        for label, key in (
            ("SDF", "sdf"),
            ("STA", "sta"),
            ("GLS", "post_syn_gls"),
            ("Power estimate", "power"),
            ("Activity power", "power_activity"),
            ("Timing / power fusion", "fusion"),
        ):
            stage = signoff.get(key)
            if not isinstance(stage, dict):
                continue
            detail = str(stage.get("status", "unknown")).upper()
            if key == "sta":
                detail += f" · {stage.get('clock_model', 'ideal')} clock · {stage.get('interconnect', 'none')}"
            if key == "post_syn_gls":
                detail += f" · interconnect {stage.get('interconnect_delays', 'unknown')}"
            rows.append((label, detail))
        if rows:
            section("Pre-implementation sign-off", rows)

    implementation = data.get("implementation")
    if isinstance(implementation, dict):
        artifacts = implementation.get("artifacts", {})
        section(
            "Implementation / PnR",
            [
                ("Status", str(implementation.get("status", "unknown")).upper()),
                ("Results", implementation.get("platform_root", "-")),
                ("Final artifacts", f"{len(artifacts)}/5" if isinstance(artifacts, dict) else "-"),
                ("Log", implementation.get("log") or "-"),
            ],
        )

    if isinstance(signoff, dict):
        routed = signoff.get("post_pnr")
        if isinstance(routed, dict):
            rows = []
            physical = routed.get("physical")
            if isinstance(physical, dict):
                rows.append(("Physical closure", str(physical.get("status", "unknown")).upper()))
                checks = physical.get("checks", {})
                if isinstance(checks, dict):
                    for label, key in (
                        ("Route DRC", "route_drc"),
                        ("Antenna", "antenna"),
                        ("GDS DRC", "gds_drc"),
                        ("LVS", "lvs"),
                        ("IR / PDN", "ir_drop"),
                    ):
                        check = checks.get(key)
                        if isinstance(check, dict):
                            rows.append((label, str(check.get("status", "unknown")).upper()))
            for label, key in (
                ("SDF", "sdf"),
                ("STA", "sta"),
                ("GLS", "gls"),
                ("Power estimate", "power"),
                ("Activity power", "power_activity"),
                ("Timing / power fusion", "fusion"),
            ):
                stage = routed.get(key)
                if not isinstance(stage, dict):
                    continue
                detail = str(stage.get("status", "unknown")).upper()
                if key == "sta":
                    detail += f" · {stage.get('clock_model', 'propagated')} clock · {stage.get('interconnect', 'spef')}"
                if key == "gls":
                    detail += f" · interconnect {stage.get('interconnect_delays', 'unknown')}"
                rows.append((label, detail))
            if rows:
                section("Post Sign-Off", rows)

    artifacts = run.get("artifacts")
    if isinstance(artifacts, dict):
        section(
            "Artifacts",
            [(name.replace("_", " ").title(), value) for name, value in artifacts.items()],
        )

    tools = data.get("tools", {})
    if tools:
        groups = (
            ("RTL / lint", {"slang", "verilator", "slang-hier"}),
            (
                "Formal / equivalence",
                {"yosys", "sby", "eqy", "bitwuzla", "boolector", "btormc", "btorsim"},
            ),
            (
                "Simulation / debug",
                {"iverilog", "gtkwave", "fst2vcd", "surfer", "sv2v", "netlistsvg"},
            ),
            ("Implementation / sign-off", {"sta", "openroad", "klayout"}),
            ("Environment", {"uv"}),
        )
        for title, names in groups:
            rows = [(name, tools[name]) for name in sorted(names) if name in tools]
            if not rows:
                continue
            console.print(f"\n[bold bright_cyan]{title} tools[/bold bright_cyan]")
            table = Table(box=None, pad_edge=False, header_style="bold grey70")
            table.add_column("Executable", style="white")
            table.add_column("Version", style="grey70")
            table.add_column("Lock", style="grey70")
            for executable, value in rows:
                if isinstance(value, dict):
                    lock_match = value.get("lock_match")
                    locked = value.get("locked_version")
                    lock = (
                        "match"
                        if lock_match is True
                        else (
                            f"tested {locked}"
                            if lock_match is False and locked
                            else "-"
                        )
                    )
                    table.add_row(
                        executable,
                        str(value.get("version", "unknown")),
                        lock,
                    )
                else:
                    table.add_row(executable, str(value), "-")
            console.print(table)


@dataclass(slots=True)
class Reporting:
    """Collect and render lifecycle evidence without executing EDA."""

    def metrics(
        self, top: str, run_dir: Path, *, pdk: str | None = None,
        provenance: Mapping[str, Any] | None = None,
    ) -> dict[str, Any]:
        """Collect normalized flow metrics."""

        return collect_metrics(top, run_dir, pdk=pdk, provenance=provenance)

    def write_metrics(
        self,
        top: str,
        run_dir: Path,
        output: Path,
        *,
        pdk: str | None = None,
        provenance: Mapping[str, Any] | None = None,
    ) -> Path:
        """Collect and write metrics JSON."""

        data = self.metrics(top, run_dir, pdk=pdk, provenance=provenance)
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
        return output

    def manifest(
        self,
        *,
        top: str,
        run_top: str,
        run_id: str,
        repo_root: Path,
        pdk: str | None = None,
        run_root: Path | None = None,
    ) -> dict[str, object]:
        """Collect immutable run/tool identity."""

        return collect_manifest(
            top=top, run_top=run_top, run_id=run_id, repo_root=repo_root,
            pdk=pdk, run_root=run_root,
        )

    def write_manifest(
        self,
        *,
        top: str,
        run_top: str,
        run_id: str,
        repo_root: Path,
        output: Path,
        pdk: str | None = None,
        run_root: Path | None = None,
    ) -> Path:
        """Collect and write manifest JSON."""

        data = self.manifest(
            top=top, run_top=run_top, run_id=run_id, repo_root=repo_root,
            pdk=pdk, run_root=run_root,
        )
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
        return output

    def show_manifest(self, path: Path) -> None:
        show_manifest(path)

    def check(self, path: Path) -> None:
        """Render the saved metrics snapshot without recollecting evidence."""

        show_check(path)

    def flow(
        self,
        *,
        top: str,
        run_top: str,
        run_id: str,
        repo_root: Path,
        run_dir: Path,
        metrics_output: Path,
        manifest_output: Path,
        pdk: str | None = None,
    ) -> tuple[Path, Path]:
        """Write metrics and manifest in lifecycle order."""

        metrics = self.write_metrics(top, run_dir, metrics_output, pdk=pdk)
        manifest = self.write_manifest(
            top=top, run_top=run_top, run_id=run_id,
            repo_root=repo_root, output=manifest_output,
        )
        return metrics, manifest
