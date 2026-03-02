from __future__ import annotations

import json
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, Optional


ANSI_RE = re.compile(r"\x1b\[[0-9;]*m")


@dataclass
class Report:
    ok: bool
    coverage: Optional[float]
    errors: int
    warnings: int
    summary: Dict[str, Any]


def _read_text(p: Path) -> str:
    try:
        return p.read_text(encoding="utf-8", errors="replace")
    except FileNotFoundError:
        return ""


def parse_ip_start_flow(flow_run_dir: Path) -> Report:
    """
    Parse a flow run directory (workspace/runs/<top>/<run_id>/...) into a stable report.
    This is intentionally conservative and only extracts invariants.
    """
    logs = flow_run_dir / "logs"
    lint_log = _read_text(logs / f"{flow_run_dir.name}_lint.log")  # may not match; fallback below
    if not lint_log:
        # fallback: search any *_lint.log
        cands = list(logs.glob("*_lint.log"))
        lint_log = _read_text(cands[0]) if cands else ""

    sim_log = _read_text(logs / f"{flow_run_dir.name}_sim.log")
    if not sim_log:
        cands = list(logs.glob("*_sim.log"))
        sim_log = _read_text(cands[0]) if cands else ""

    # also accept stdout-style messages in sim log
    merged = "\n".join([lint_log, sim_log])
    merged = ANSI_RE.sub("", merged)

    # Count errors/warnings in a tool-agnostic way
    errors = len(re.findall(r"(?m)^%Error", merged)) + len(re.findall(r"(?m)\bError:", merged))
    warnings = len(re.findall(r"(?m)^%Warning", merged)) + len(re.findall(r"(?m)\bWarning:", merged))

    cov = None
    m = re.search(r"Coverage:\s*([0-9]+(?:\.[0-9]+)?)%", merged)
    if m:
        cov = float(m.group(1))

    ok = errors == 0

    summary: Dict[str, Any] = {
        "has_tlul_read_done": "TLUL READ DONE" in merged,
        "has_finish": "$finish" in merged,
        "has_verilator": "Verilator" in merged,
    }

    return Report(ok=ok, coverage=cov, errors=errors, warnings=warnings, summary=summary)


def write_report_json(report: Report, out_path: Path) -> None:
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(
        json.dumps(
            {
                "ok": report.ok,
                "coverage": report.coverage,
                "errors": report.errors,
                "warnings": report.warnings,
                "summary": report.summary,
            },
            indent=2,
        )
        + "\n",
        encoding="utf-8",
    )
