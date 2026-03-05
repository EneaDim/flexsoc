from __future__ import annotations

# reporting.py
#
# Parser + writer per report.json (flow-level).
# I test vogliono:
#   workspace/runs/<top>/<run_id>/report.json

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


def _first_existing(paths: list[Path]) -> str:
    for p in paths:
        if p.exists():
            return _read_text(p)
    return ""


def parse_ip_start_flow(flow_run_dir: Path) -> Report:
    """Parse minimale e robusto per ip_start (tool-agnostic)."""
    logs = flow_run_dir / "logs"

    lint_log = _first_existing(list(logs.glob("*_lint.log")))
    sim_log = _first_existing(list(logs.glob("*_sim.log")))

    merged = "\n".join([lint_log, sim_log])
    merged = ANSI_RE.sub("", merged)

    errors = len(re.findall(r"(?m)^%Error", merged)) + len(re.findall(r"(?m)\bError:", merged))
    warnings = len(re.findall(r"(?m)^%Warning", merged)) + len(re.findall(r"(?m)\bWarning:", merged))

    warning_types: Dict[str, int] = {}
    for m in re.finditer(r"(?m)^%Warning-([A-Z0-9_]+):", merged):
        t = m.group(1)
        warning_types[t] = warning_types.get(t, 0) + 1

    cov = None
    m = re.search(r"Coverage:\s*([0-9]+(?:\.[0-9]+)?)%", merged)
    if m:
        cov = float(m.group(1))

    summary: Dict[str, Any] = {
        "has_tlul_read_done": "TLUL READ DONE" in merged,
        "has_finish": "$finish" in merged,
        "has_verilator": "Verilator" in merged,
        "warning_types_top": dict(sorted(warning_types.items(), key=lambda kv: kv[1], reverse=True)[:10]),
    }

    return Report(ok=(errors == 0), coverage=cov, errors=errors, warnings=warnings, summary=summary)


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


def postprocess_ip_start(flow_run_dir: Path) -> None:
    """Genera report.json per ip_start."""
    rep = parse_ip_start_flow(flow_run_dir)
    write_report_json(rep, flow_run_dir / "report.json")
