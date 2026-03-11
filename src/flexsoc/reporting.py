from __future__ import annotations

import json
import re
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Any, Dict, Optional

ANSI_RE = re.compile(r"\x1b\[[0-9;]*m")


@dataclass
class Report:
    ok: bool
    action: str
    coverage: Optional[float]
    errors: int
    warnings: int
    summary: Dict[str, Any]


_ACTION_PATTERNS: dict[str, list[str]] = {
    "ip_start": ["*_lint.log", "*_sim.log"],
    "make:lint": ["*_lint.log"],
    "make:sim": ["*_sim.log", "*_compile.log"],
    "make:syn": ["*_synth_opt_*.log"],
    "make:sta": ["*_sta_opt_*.log"],
    "make:power": ["*_power.log"],
    "make:compile": ["*_compile.log"],
    "make:compile_syn": ["*_compile_syn.log"],
    "make:sim_syn": ["*_syn_sim.log", "*_compile_syn.log"],
    "make:sta_violators": ["*_sta.violators"],
}


def _read_text(p: Path) -> str:
    try:
        return p.read_text(encoding="utf-8", errors="replace")
    except FileNotFoundError:
        return ""


def _normalize_text(text: str) -> str:
    return ANSI_RE.sub("", text or "")


def _glob_many(root: Path, patterns: list[str]) -> list[Path]:
    out: list[Path] = []
    seen: set[Path] = set()
    for pattern in patterns:
        for p in sorted(root.glob(pattern)):
            if p not in seen and p.is_file():
                seen.add(p)
                out.append(p)
    return out


def _count_matches(text: str, patterns: list[str]) -> int:
    total = 0
    for pat in patterns:
        total += len(re.findall(pat, text, flags=re.MULTILINE))
    return total


def _parse_coverage(text: str) -> Optional[float]:
    m = re.search(r"Coverage:\s*([0-9]+(?:\.[0-9]+)?)%", text)
    if m:
        return float(m.group(1))
    return None


def _warning_types(text: str) -> Dict[str, int]:
    out: Dict[str, int] = {}
    for m in re.finditer(r"(?m)^%Warning-([A-Z0-9_]+):", text):
        t = m.group(1)
        out[t] = out.get(t, 0) + 1
    return dict(sorted(out.items(), key=lambda kv: kv[1], reverse=True)[:10])


def _action_candidates(action: str) -> list[str]:
    candidates = [action]
    if action.startswith("make_"):
        candidates.append(f"make:{action.split('_', 1)[1]}")
    if action.startswith("make:"):
        candidates.append(action.replace("make:", "make_"))
    return candidates


def _collect_action_logs(
    *,
    flow_run_dir: Path,
    action: str,
    runner_dir: Optional[Path] = None,
) -> tuple[list[Path], str]:
    logs_dir = flow_run_dir / "logs"
    collected: list[Path] = []

    for candidate in _action_candidates(action):
        patterns = _ACTION_PATTERNS.get(candidate, [])
        if patterns and logs_dir.exists():
            collected.extend(_glob_many(logs_dir, patterns))

    unique: list[Path] = []
    seen: set[Path] = set()
    for p in collected:
        if p not in seen:
            seen.add(p)
            unique.append(p)

    if unique:
        merged = "\n\n".join(_normalize_text(_read_text(p)) for p in unique)
        return unique, merged

    runner_logs: list[Path] = []
    if runner_dir is not None:
        for name in ("stderr.log", "stdout.log"):
            p = runner_dir / name
            if p.exists():
                runner_logs.append(p)

    merged = "\n\n".join(_normalize_text(_read_text(p)) for p in runner_logs)
    return runner_logs, merged


def parse_action_flow(
    *,
    flow_run_dir: Path,
    action: str,
    runner_dir: Optional[Path] = None,
) -> Report:
    matched_files, merged = _collect_action_logs(
        flow_run_dir=flow_run_dir,
        action=action,
        runner_dir=runner_dir,
    )

    errors = _count_matches(
        merged,
        [
            r"(?m)^%Error",
            r"(?m)\bError:",
            r"(?m)\bERROR:",
            r"(?m)^\s*error\b",
            r"(?m)\bfailed\b",
        ],
    )
    warnings = _count_matches(
        merged,
        [
            r"(?m)^%Warning",
            r"(?m)\bWarning:",
            r"(?m)\bWARNING:",
        ],
    )

    summary: Dict[str, Any] = {
        "matched_files": [str(p) for p in matched_files],
        "matched_file_count": len(matched_files),
        "has_finish": "$finish" in merged,
        "has_verilator": "Verilator" in merged,
        "has_opensta": "OpenSTA" in merged or "opensta" in merged.lower(),
        "has_yosys": "Yosys" in merged or "yosys" in merged.lower(),
        "has_tlul_read_done": "TLUL READ DONE" in merged,
        "warning_types_top": _warning_types(merged),
        "coverage_found": _parse_coverage(merged) is not None,
        "line_count": len(merged.splitlines()) if merged else 0,
        "diagnostic": "no log content found" if not merged.strip() else "",
    }

    return Report(
        ok=(errors == 0),
        action=action,
        coverage=_parse_coverage(merged),
        errors=errors,
        warnings=warnings,
        summary=summary,
    )


def write_report_json(report: Report, out_path: Path) -> None:
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(json.dumps(asdict(report), indent=2) + "\n", encoding="utf-8")


def postprocess_action(
    *,
    action: str,
    flow_run_dir: Path,
    runner_dir: Optional[Path] = None,
) -> None:
    rep = parse_action_flow(
        flow_run_dir=flow_run_dir,
        action=action,
        runner_dir=runner_dir,
    )
    write_report_json(rep, flow_run_dir / "report.json")


def parse_ip_start_flow(flow_run_dir: Path) -> Report:
    return parse_action_flow(flow_run_dir=flow_run_dir, action="ip_start", runner_dir=None)


def postprocess_ip_start(flow_run_dir: Path) -> None:
    postprocess_action(action="ip_start", flow_run_dir=flow_run_dir, runner_dir=None)
