"""Collect normalized run metrics and immutable manifest evidence."""

from __future__ import annotations

import hashlib
import json
import os
import platform
import re
import tomllib
from dataclasses import dataclass
from importlib import metadata
from pathlib import Path
from typing import TYPE_CHECKING, Any, Mapping, Sequence

from flexsoc.backend.signoff.sta import SDF_MODE_TO_CORNER
from flexsoc.backend.core import PDKRunLayout
from flexsoc.backend.core.runtime.toolchain import Toolchain


if TYPE_CHECKING:
    from flexsoc.backend.core.core import BackendContext
    from flexsoc.backend.core.flow.target import Target


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

@dataclass(slots=True)
class Reporting:
    """Collect lifecycle evidence and route external probes through ToolRunner."""

    runner: object | None = None

    def run(
        self,
        target: "Target",
        context: "BackendContext",
        *,
        provenance: Mapping[str, object] | None = None,
        on: str = "local",
    ) -> object:
        """Execute one reporting target from the declarative registry."""

        paths = context.paths
        if target.action == "metrics":
            return self.write_metrics(
                paths.top, paths.run, paths.metrics, pdk=paths.pdk, provenance=provenance,
            )
        if target.action == "manifest":
            return self.write_manifest(
                top=paths.top, run_top=paths.run_top, run_id=paths.run_id,
                repo_root=context.project_root, output=paths.manifest,
                pdk=paths.pdk, run_root=paths.run, on=on,
            )
        if target.action == "show" and target.show:
            from ..core.render.show import ShowRenderer

            return ShowRenderer.load_and_render(paths.run, top=paths.top, pdk=paths.pdk, key=target.show)
        raise ValueError(f"unsupported reporting target: {target.name}")

    def metrics(
        self, top: str, run_dir: Path, *, pdk: str | None = None,
        provenance: Mapping[str, Any] | None = None,
    ) -> dict[str, Any]:
        """Collect normalized flow metrics."""

        return Reporting.collect_metrics(top, run_dir, pdk=pdk, provenance=provenance)

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
        on: str = "local",
    ) -> dict[str, object]:
        """Collect immutable run/tool identity."""

        return Reporting.collect_manifest(
            top=top, run_top=run_top, run_id=run_id, repo_root=repo_root,
            pdk=pdk, run_root=run_root, runner=self.runner, on=on,
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
        on: str = "local",
    ) -> Path:
        """Collect and write manifest JSON."""

        data = self.manifest(
            top=top, run_top=run_top, run_id=run_id, repo_root=repo_root,
            pdk=pdk, run_root=run_root, on=on,
        )
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
        return output


    @staticmethod
    def read_text(path: Path) -> str:
        """Read a text artifact without failing on tool-specific encoding noise."""

        return path.read_text(encoding="utf-8", errors="replace")

    @staticmethod
    def line_count(path: Path) -> int:
        """Count non-empty lines in a generated diagnostic file."""

        if not path.is_file():
            return 0
        return sum(1 for line in Reporting.read_text(path).splitlines() if line.strip())

    @staticmethod
    def unique_file(paths: Sequence[Path], *, label: str) -> Path | None:
        """Return one existing artifact, rejecting ambiguous fallbacks."""

        existing = sorted(path for path in paths if path.is_file())
        if len(existing) > 1:
            raise ValueError(f"ambiguous {label}: " + ", ".join(str(path) for path in existing))
        return existing[0] if existing else None

    @staticmethod
    def last_number(pattern: str, text: str, cast: type[int] | type[float]) -> int | float | None:
        """Return the last numeric regex match."""

        matches = re.findall(pattern, text, flags=re.IGNORECASE | re.MULTILINE)
        return cast(matches[-1]) if matches else None

    @staticmethod
    def relative(path: Path, run_dir: Path) -> str:
        """Return a stable run-relative artifact path."""

        return path.resolve().relative_to(run_dir.resolve()).as_posix()

    @staticmethod
    def marked_section(text: str, start: str, end: str) -> str:
        """Return text between two explicit report markers."""

        if start not in text or end not in text:
            return ""
        return text.split(start, 1)[1].split(end, 1)[0]

    @staticmethod
    def collect_lint(top: str, run_dir: Path) -> dict[str, Any] | None:
        """Load the canonical aggregated lint summary."""

        summary = Reporting._json_object(run_dir / "dv" / "lint" / "summary.json")
        if summary.get("top") != top or not isinstance(summary.get("tools"), dict):
            return None
        return summary

    @staticmethod
    def collect_cdc_rdc(top: str, run_dir: Path) -> dict[str, Any] | None:
        """Collect the custom structural CDC/RDC summary emitted after lint."""

        summary_path = run_dir / "dv" / "cdc_rdc" / "summary.json"
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
        result["summary"] = Reporting.relative(summary_path, run_dir)
        report_path = run_dir / "dv" / "cdc_rdc" / "cdc_rdc.rpt"
        if report_path.is_file():
            result["report"] = Reporting.relative(report_path, run_dir)
        return result

    @staticmethod
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

    @staticmethod
    def collect_regression(top: str, run_dir: Path) -> dict[str, Any] | None:
        """Collect regression metrics from the canonical DV summary."""

        summary_path = run_dir / "dv" / "functional" / "regression" / "summary.json"
        if not summary_path.is_file():
            return None
        try:
            summary = json.loads(summary_path.read_text(encoding="utf-8"))
        except (json.JSONDecodeError, OSError):
            return None
        if not isinstance(summary, dict):
            return None

        coverage_dir = run_dir / "dv" / "functional" / "coverage"
        coverage_path = coverage_dir / "summary.json"
        coverage_matrix = Reporting.parse_coverage_matrix(coverage_path)
        scopes = coverage_matrix.get("scopes", {}) if coverage_matrix else {}
        coverage = {
            scope: values.get("total", {})
            for scope, values in scopes.items()
            if isinstance(values, dict) and isinstance(values.get("total"), dict)
        }
        matrix: dict[str, dict[str, str]] = {}
        raw_matrix = summary.get("matrix", {})
        if isinstance(raw_matrix, dict):
            for test, row in raw_matrix.items():
                if not isinstance(row, dict):
                    continue
                matrix[str(test)] = {
                    str(backend): {
                        "PASS": "pass",
                        "FAILED": "fail",
                        "NOT_RUN": "not_run",
                    }.get(str(item.get("status", "UNKNOWN")).upper(), "partial")
                    for backend, item in row.items()
                    if isinstance(item, dict)
                }

        status = str(summary.get("status", "PARTIAL")).upper()
        return {
            "status": {"PASS": "pass", "FAILED": "fail"}.get(status, "partial"),
            "tests": list(summary.get("tests", ())),
            "test_count": int(summary.get("test_count", 0)),
            "backends": summary.get("backend_counts", {}),
            "matrix": matrix,
            "coverage": coverage,
            "coverage_matrix": coverage_matrix,
            "summary": Reporting.relative(summary_path, run_dir),
            "coverage_summary_json": Reporting.relative(coverage_path, run_dir) if coverage_path.is_file() else None,
            "coverage_merged": (
                Reporting.relative(coverage_dir / "merged.dat", run_dir)
                if (coverage_dir / "merged.dat").is_file() else None
            ),
        }

    @staticmethod
    def synthesis_diagnostic_count(text: str, severity: str) -> int:
        """Count real Yosys or Slang diagnostics, not signal names containing error/warning."""

        label = "Warning" if severity == "warning" else "ERROR"
        slang = severity.lower()
        pattern = (
            rf"^(?:{label}:|%{label.capitalize()}-|"
            rf".+:\d+(?::\d+)?:\s*{slang}:)"
        )
        return len(re.findall(pattern, text, flags=re.IGNORECASE | re.MULTILINE))

    @staticmethod
    def collect_synthesis(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
        """Consume the synthesis owner summary without reparsing Yosys logs."""

        layout = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top)
        summary = Reporting._json_object(layout.syn_dir / "summary.json")
        if not summary:
            return None
        metrics = summary.get("metrics", {}) if isinstance(summary.get("metrics"), dict) else {}
        artifacts = summary.get("artifacts", {}) if isinstance(summary.get("artifacts"), dict) else {}
        logs = summary.get("logs", ()) if isinstance(summary.get("logs"), list) else ()
        return {
            "status": {"PASS": "pass", "FAILED": "fail"}.get(str(summary.get("status")), "incomplete"),
            "strategy": summary.get("profile", "unknown"),
            **metrics,
            "netlist": artifacts.get("netlist"),
            "log": logs[-1] if logs else None,
            "evidence": Reporting.relative(layout.syn_dir / "summary.json", run_dir),
        }

    @staticmethod
    def collect_sta(
        top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
    ) -> dict[str, Any] | None:
        """Consume canonical per-corner STA summary evidence."""

        layout = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top)
        root = layout.signoff_stage_root(stage)
        log_root = layout.signoff_stage_log_root(stage)
        canonical = root / "sta" / "summary.json"
        payload = Reporting._json_object(canonical)
        if not payload:
            return None
        scenarios: dict[str, dict[str, Any]] = {}
        for item in payload.get("scenarios", []):
            if not isinstance(item, Mapping):
                continue
            corner = str(item.get("corner", ""))
            mode = str(item.get("mode", ""))
            if not corner or mode not in {"setup", "hold"}:
                continue
            data: dict[str, Any] = {
                "reported_violating_paths": int(item.get("violating_paths", 0)),
                "reported_unconstrained_paths": int(item.get("unconstrained_paths", 0)),
                "report": Reporting.relative(root / "sta" / "sta.rpt", run_dir),
                "log": Reporting.relative(log_root / "sta" / corner / mode / f"{top}.log", run_dir),
                "scenario": item.get("id", f"{mode}_{corner}"),
                "timing_role": item.get("timing_role", "gating"),
                "violation_types": dict(item.get("violation_types", {}))
                if isinstance(item.get("violation_types"), Mapping) else {},
                "status": item.get("status", "unknown"),
            }
            if item.get("wns") is not None:
                data["wns"] = float(item["wns"])
            if item.get("tns") is not None:
                data["tns"] = float(item["tns"])
            scenarios.setdefault(corner, {})[mode] = data
        return scenarios or None

    @staticmethod
    def collect_power_estimate(
        top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
    ) -> dict[str, Any] | None:
        """Consume canonical vectorless power summary evidence."""

        layout = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top)
        root = layout.signoff_stage_root(stage)
        summary = Reporting._json_object(root / "power" / "estimate" / "summary.json")
        if not isinstance(summary.get("corners"), dict):
            return None
        return {
            key: summary[key]
            for key in ("activity", "duty", "activity_source", "corners", "status")
            if key in summary
        }

    @staticmethod
    def status_word(path: Path, log: Path | None = None) -> str:
        """Return pass/fail/error/unknown from a tool status file or log."""

        texts: list[str] = []
        if path.is_file():
            texts.append(Reporting.read_text(path))
        if log is not None and log.is_file():
            texts.append(Reporting.read_text(log))
        text = "\n".join(texts)
        if re.search(r"\bPASS(?:ED)?\b|DONE \(PASS", text, flags=re.IGNORECASE):
            return "pass"
        if re.search(r"DONE \(FAIL|\bFAIL(?:ED)?\b", text, flags=re.IGNORECASE):
            return "fail"
        if re.search(r"DONE \(ERROR|\bERROR\b", text, flags=re.IGNORECASE):
            return "error"
        return "unknown"

    @staticmethod
    def collect_formal(top: str, run_dir: Path) -> dict[str, Any] | None:
        """Collect formal metrics from the canonical FormalFlow summary."""

        del top
        summary_path = run_dir / "dv" / "formal" / "summary.json"
        if not summary_path.is_file():
            return None
        try:
            data = json.loads(summary_path.read_text(encoding="utf-8"))
        except (json.JSONDecodeError, OSError):
            return None
        if not isinstance(data, dict):
            return None

        raw_matrix = data.get("matrix", {}) if isinstance(data.get("matrix"), dict) else {}
        matrix: dict[str, dict[str, dict[str, Any]]] = {}
        for suite, row in raw_matrix.items():
            if not isinstance(row, dict):
                continue
            matrix[str(suite)] = {}
            for stage, item in row.items():
                if not isinstance(item, dict):
                    continue
                normalized = dict(item)
                normalized["status"] = {
                    "PASS": "pass",
                    "FAILED": "fail",
                }.get(str(item.get("status", "UNKNOWN")).upper(), "unknown")
                matrix[str(suite)][str(stage)] = normalized
        counts = data.get("counts", {}) if isinstance(data.get("counts"), dict) else {}
        stage_counts = data.get("stage_counts", {}) if isinstance(data.get("stage_counts"), dict) else {}
        traces = int(data.get("trace_count", 0))
        status = str(data.get("status", "PARTIAL")).upper()
        return {
            "csr": matrix.get("csr", {}),
            "properties": matrix.get("properties", {}),
            "summary": {
                "passed": int(counts.get("passed", 0)),
                "observed": int(counts.get("observed", 0)),
                "total": int(counts.get("total", 6)),
                "elapsed_s": int(data.get("elapsed_s", 0)),
                "traces": traces,
                "stages": stage_counts,
            },
            "status": {"PASS": "pass", "FAILED": "fail"}.get(status, "partial"),
            "evidence": Reporting.relative(summary_path, run_dir),
        }

    @staticmethod
    def collect_equivalence(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
        """Consume canonical EQY summary evidence without reparsing runtime logs."""

        layout = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top)
        path = layout.equivalence_dir / "summary.json"
        summary = Reporting._json_object(path)
        if not summary:
            return None
        result = summary.get("result", {}) if isinstance(summary.get("result"), dict) else {}
        counts = result.get("counts", {}) if isinstance(result.get("counts"), dict) else {}
        total = int(result.get("total", 0))
        proven = int(counts.get("PASS", 0))
        partitions = {
            "proven": proven,
            "failed": int(counts.get("FAIL", 0)),
            "errors": int(counts.get("ERROR", 0)),
            "timeouts": int(counts.get("TIMEOUT", 0)),
            "unknown": int(counts.get("UNKNOWN", 0)) + int(counts.get("MISSING", 0)),
            "total": total,
            "percent": 100.0 * proven / total if total else 0.0,
        }
        return {
            "status": {"PASS": "pass", "FAILED": "fail", "REVIEW": "partial"}.get(
                str(summary.get("status")), "unknown"
            ),
            "partitions": partitions,
            "strategies": summary.get("strategies", {}),
            "log": summary.get("artifacts", {}).get("log") if isinstance(summary.get("artifacts"), dict) else None,
            "result_dir": summary.get("artifacts", {}).get("result_dir") if isinstance(summary.get("artifacts"), dict) else None,
            "evidence": Reporting.relative(path, run_dir),
        }

    @staticmethod
    def collect_sdf(
        top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
    ) -> dict[str, Any] | None:
        """Collect generated SDF files for one sign-off stage."""

        layout = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top)
        sdf_dir = layout.signoff_stage_root(stage) / "sdf"
        files = sorted(sdf_dir.glob(f"*/{top}_*.sdf")) if sdf_dir.is_dir() else []
        if not files:
            return None
        corners: dict[str, Any] = {}
        prefix = f"{top}_"
        for path in files:
            corner = path.stem[len(prefix):] if path.stem.startswith(prefix) else path.stem
            corners[corner] = {"bytes": path.stat().st_size, "path": Reporting.relative(path, run_dir)}
        return {"status": "pass", "count": len(files), "corners": corners}

    @staticmethod
    def _json_object(path: Path) -> dict[str, Any]:
        """Read one JSON object, returning an empty mapping for invalid artifacts."""

        if not path.is_file():
            return {}
        try:
            value = json.loads(path.read_text(encoding="utf-8"))
        except (json.JSONDecodeError, OSError):
            return {}
        return value if isinstance(value, dict) else {}

    @staticmethod
    def _gls_scenario(mode: str) -> str:
        """Return the user-facing GLS scenario while retaining zero/unit as DV modes."""

        return SDF_MODE_TO_CORNER.get(mode, mode)

    @staticmethod
    def _activity_scenario(report: dict[str, Any], fallback: str = "-") -> str:
        """Return the PVT scenario recorded by one activity analysis report."""

        scenario = report.get("scenario")
        if isinstance(scenario, dict):
            return str(scenario.get("corner", fallback))
        if scenario:
            return str(scenario)
        return Reporting._gls_scenario(str(report.get("timing_mode", fallback)))

    @staticmethod
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

    @staticmethod
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
                    "stem": f"{test}_{Reporting._gls_scenario(mode)}",
                    "test": test,
                    "timing_mode": mode,
                    "scenario": Reporting._gls_scenario(mode),
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

    @staticmethod
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

    @staticmethod
    def collect_post_syn_gls(
        top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
    ) -> dict[str, Any] | None:
        """Collect direct GLS reports from one gate-level stage."""

        layout = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top)
        report_stage = "post_impl" if stage == "post_impl" else "post_syn"
        stage_dir = layout.post_impl_sim_dir if report_stage == "post_impl" else layout.post_syn_sim_dir
        report_paths = sorted(stage_dir.glob(f"{top}_{report_stage}_*.json"))
        if not report_paths:
            return None

        record_map: dict[tuple[str, str, str], tuple[bool, dict[str, Any]]] = {}
        for report_path in report_paths:
            report = Reporting._json_object(report_path)
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
            reason = Reporting._gls_report_reason(
                report,
                mode=mode,
                wave_path=wave_path,
                interconnect_expected=report_stage == "post_impl",
            )
            record = {
                "stem": report_path.stem,
                "test": test_name,
                "backend": backend,
                "timing_mode": mode,
                "scenario": str(report.get("scenario") or Reporting._gls_scenario(mode)),
                "status": "fail" if reason else "pass",
                "reason": reason,
                "report": Reporting.relative(report_path, run_dir),
                "log": Reporting.relative(log_path, run_dir) if raw_log and log_path.is_file() else None,
                "wave": Reporting.relative(wave_path, run_dir) if raw_wave and wave_path.is_file() else None,
            }
            key = (test_name, backend, mode)
            canonical = report_path.stem.endswith(f"_{backend}_{Reporting._gls_scenario(mode)}")
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
        scenarios = Reporting._gls_scenario_records(records)
        summary = Reporting._gls_group(scenarios)
        by_backend = {
            backend: Reporting._gls_group([record for record in records if record["backend"] == backend])
            for backend in backends
        }
        by_mode = {
            mode: Reporting._gls_group([record for record in scenarios if record["timing_mode"] == mode])
            for mode in modes
        }
        by_scenario = {
            Reporting._gls_scenario(mode): Reporting._gls_group(
                [record for record in scenarios if record["timing_mode"] == mode]
            )
            for mode in modes
        }
        by_test = {
            test_name: Reporting._gls_group([record for record in scenarios if record["test"] == test_name])
            for test_name in tests
        }
        return {
            **summary,
            "pdk": pdk,
            "tests": tests,
            "backends": backends,
            "timing_modes": modes,
            "scenarios": [Reporting._gls_scenario(mode) for mode in modes],
            "artifacts": Reporting.relative(stage_dir, run_dir),
            "interconnect_delays": (
                ("enabled" if report_stage == "post_impl" else "none")
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

    @staticmethod
    def _collect_activity_analysis(
        top: str, run_dir: Path, pdk: str, stage: str, subdir: str
    ) -> dict[str, Any] | None:
        """Collect one activity-driven sign-off summary."""

        path = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top).signoff_stage_root(stage) / subdir / "summary.json"
        data = Reporting._json_object(path)
        if not isinstance(data.get("reports"), list):
            return None
        data["summary"] = Reporting.relative(path, run_dir)
        return data

    @staticmethod
    def collect_power_analysis(
        top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
    ) -> dict[str, Any] | None:
        """Collect activity-based power analysis driven by direct GLS traces."""

        return Reporting._collect_activity_analysis(top, run_dir, pdk, stage, "power/analysis")

    @staticmethod
    def collect_fusion_analysis(
        top: str, run_dir: Path, pdk: str, stage: str = "post_syn"
    ) -> dict[str, Any] | None:
        """Collect workload-correlated timing/power analysis."""

        return Reporting._collect_activity_analysis(top, run_dir, pdk, stage, "fusion")

    @staticmethod
    def collect_implementation(top: str, run_dir: Path, pdk: str) -> dict[str, Any] | None:
        """Consume canonical implementation summary evidence."""

        layout = PDKRunLayout.from_run(run_dir, pdk=pdk, top=top)
        path = layout.pnr_dir / "summary.json"
        summary = Reporting._json_object(path)
        if not summary or summary.get("top") != top:
            return None
        return {
            "status": {"PASS": "pass", "FAILED": "fail"}.get(
                str(summary.get("status", "")), "incomplete"
            ),
            "platform": summary.get("platform"),
            "phases": summary.get("phases", []),
            "artifacts": summary.get("artifacts", {}),
            "log": summary.get("log"),
            "evidence": Reporting.relative(path, run_dir),
        }

    @staticmethod
    def _normalize_paths(value: Any, run_dir: Path) -> Any:
        """Normalize absolute artifact paths to run-relative paths."""

        if isinstance(value, dict):
            return {key: Reporting._normalize_paths(item, run_dir) for key, item in value.items()}
        if isinstance(value, list):
            return [Reporting._normalize_paths(item, run_dir) for item in value]
        if isinstance(value, str):
            candidate = Path(value)
            if candidate.is_absolute():
                return Reporting.relative(candidate, run_dir)
        return value

    @staticmethod
    def collect_physical_signoff(run_dir: Path, pdk: str) -> dict[str, Any] | None:
        """Collect ORFS physical checks as part of post-implementation sign-off."""

        path = run_dir / "signoff" / pdk / "post_impl" / "physical" / "summary.json"
        if not path.is_file():
            return None
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            return {"status": "unknown", "summary": Reporting.relative(path, run_dir)}
        if not isinstance(data, dict):
            return {"status": "unknown", "summary": Reporting.relative(path, run_dir)}

        result = Reporting._normalize_paths(data, run_dir)
        result["summary"] = Reporting.relative(path, run_dir)
        return result

    @staticmethod
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

    @staticmethod
    def _metric_status(metrics: Mapping[str, Any], name: str) -> str:
        """Return one normalized metric status."""

        value = metrics.get(name)
        if isinstance(value, dict):
            return str(value.get("status", "pass" if value else "missing"))
        return "missing"

    @staticmethod
    def _sta_status(value: object) -> str:
        """Return the canonical STA outcome without treating advisory warnings as failures."""

        if not isinstance(value, Mapping):
            return "missing"
        statuses = [
            str(mode.get("status", "unknown"))
            for corner in value.values() if isinstance(corner, Mapping)
            for mode in corner.values() if isinstance(mode, Mapping)
        ]
        if not statuses:
            return "missing"
        if any(status in {"fail", "error"} for status in statuses):
            return "fail"
        if any(status in {"missing", "partial", "unknown", "incomplete"} for status in statuses):
            return "incomplete"
        return "pass"

    @staticmethod
    def flow_summary(metrics: dict[str, Any]) -> dict[str, Any]:
        """Summarize the complete FlexSoC lifecycle in user-facing order."""

        synthesis = metrics.get("synthesis")
        synthesis_status = "missing"
        if isinstance(synthesis, dict):
            synthesis_status = (
                "pass"
                if int(synthesis.get("errors", 0)) == 0 and bool(synthesis.get("netlist"))
                else "fail"
            )

        pre = Reporting._phase_status(
            Reporting._metric_status(metrics, "sdf"),
            Reporting._sta_status(metrics.get("sta")),
            "pass" if metrics.get("power_estimate") else "missing",
            Reporting._metric_status(metrics, "post_syn_gls"),
            Reporting._metric_status(metrics, "power_analysis"),
            Reporting._metric_status(metrics, "fusion_analysis"),
        )
        implementation = Reporting._metric_status(metrics, "implementation")
        routed = metrics.get("post_impl")
        if isinstance(routed, dict):
            post = Reporting._phase_status(
                str(routed.get("sdf", {}).get("status", "missing")) if isinstance(routed.get("sdf"), dict) else "missing",
                Reporting._sta_status(routed.get("sta")),
                "pass" if routed.get("power_estimate") else "missing",
                str(routed.get("gls", {}).get("status", "missing")) if isinstance(routed.get("gls"), dict) else "missing",
                str(routed.get("power_analysis", {}).get("status", "missing")) if isinstance(routed.get("power_analysis"), dict) else "missing",
                str(routed.get("fusion_analysis", {}).get("status", "missing")) if isinstance(routed.get("fusion_analysis"), dict) else "missing",
            )
        else:
            post = "missing"

        stages = {
            "lint": Reporting._metric_status(metrics, "lint"),
            "cdc_rdc": Reporting._metric_status(metrics, "cdc_rdc"),
            "functional": Reporting._metric_status(metrics, "regression"),
            "formal": Reporting._metric_status(metrics, "formal"),
            "synthesis": synthesis_status,
            "equivalence": Reporting._metric_status(metrics, "equivalence"),
            "pre_implementation_signoff": pre,
            "implementation": implementation,
            "post_implementation_signoff": Reporting._phase_status(post, Reporting._metric_status(metrics, "physical_signoff")),
        }
        overall = Reporting._phase_status(*stages.values())
        return {
            "order": list(stages),
            "stages": stages,
            "status": overall,
            "complete": overall == "pass",
        }

    @staticmethod
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

    @staticmethod
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
            result["sta"] = {
                "status": Reporting._sta_status(metrics.get("sta")),
                "clock_model": "ideal",
                "interconnect": "none",
            }
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
        post_impl = metrics.get("post_impl")
        if isinstance(post_impl, dict):
            routed: dict[str, Any] = {}
            sdf = post_impl.get("sdf")
            if isinstance(sdf, dict):
                routed["sdf"] = {"status": sdf.get("status", "unknown"), "count": sdf.get("count", 0)}
            if post_impl.get("sta"):
                routed["sta"] = {
                    "status": Reporting._sta_status(post_impl.get("sta")),
                    "clock_model": "propagated",
                    "interconnect": "spef",
                }
            if post_impl.get("power_estimate"):
                routed["power"] = {"status": "pass"}
            gls = post_impl.get("gls")
            if isinstance(gls, dict):
                routed["gls"] = {
                    "status": gls.get("status", "unknown"),
                    "passed": gls.get("passed", 0),
                    "total": gls.get("total", 0),
                    "interconnect_delays": gls.get("interconnect_delays", "unknown"),
                }
            activity = post_impl.get("power_analysis")
            if isinstance(activity, dict):
                routed["power_activity"] = {
                    "status": activity.get("status", "unknown"),
                    "passed": activity.get("passed", 0),
                    "total": activity.get("total", 0),
                }
            fusion = post_impl.get("fusion_analysis")
            if isinstance(fusion, dict):
                routed["fusion"] = {
                    "status": fusion.get("status", "unknown"),
                    "passed": fusion.get("passed", 0),
                    "total": fusion.get("total", 0),
                }
            if routed:
                result["post_impl"] = routed
        physical = metrics.get("physical_signoff")
        if isinstance(physical, dict):
            routed = result.setdefault("post_impl", {})
            routed["physical"] = {
                "status": physical.get("status", "unknown"),
                "checks": physical.get("checks", {}),
                "summary": physical.get("summary"),
            }
        return result

    @staticmethod
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
        stages["sta"] = Reporting._sta_status(metrics.get("sta"))
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

        post_impl = metrics.get("post_impl")
        routed = post_impl if isinstance(post_impl, dict) else {}
        routed_sdf = routed.get("sdf")
        stages["post_impl_sdf"] = (
            str(routed_sdf.get("status", "unknown")) if isinstance(routed_sdf, dict) else "missing"
        )
        stages["post_impl_sta"] = Reporting._sta_status(routed.get("sta"))
        stages["post_impl_power"] = "pass" if routed.get("power_estimate") else "missing"
        routed_gls = routed.get("gls")
        stages["post_impl_gls"] = (
            str(routed_gls.get("status", "unknown")) if isinstance(routed_gls, dict) else "missing"
        )
        routed_activity = routed.get("power_analysis")
        stages["post_impl_power_activity"] = (
            str(routed_activity.get("status", "unknown"))
            if isinstance(routed_activity, dict)
            else "missing"
        )
        routed_fusion = routed.get("fusion_analysis")
        stages["post_impl_fusion"] = (
            str(routed_fusion.get("status", "unknown")) if isinstance(routed_fusion, dict) else "missing"
        )
        order.extend((
            "post_impl_sdf", "post_impl_sta", "post_impl_gls", "post_impl_power",
            "post_impl_power_activity", "post_impl_fusion",
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

    @staticmethod
    def collect_metrics(
        top: str,
        run_dir: Path,
        *,
        pdk: str | None = None,
        provenance: Mapping[str, Any] | None = None,
    ) -> dict[str, Any]:
        """Collect one logical run plus the selected PDK-scoped implementation."""

        selected_pdk = pdk or "sky130"
        layout = PDKRunLayout.from_run(run_dir, pdk=selected_pdk, top=top)
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
            ("lint", Reporting.collect_lint),
            ("cdc_rdc", Reporting.collect_cdc_rdc),
            ("formal", Reporting.collect_formal),
            ("regression", Reporting.collect_regression),
        ):
            data = collector(top, run_dir)
            if data is not None:
                metrics[name] = data

        # Technology-dependent implementation/sign-off is selected by PDK.
        for name, collector in (
            ("synthesis", Reporting.collect_synthesis),
            ("equivalence", Reporting.collect_equivalence),
            ("sdf", Reporting.collect_sdf),
            ("post_syn_gls", Reporting.collect_post_syn_gls),
            ("sta", Reporting.collect_sta),
            ("power_estimate", Reporting.collect_power_estimate),
            ("power_analysis", Reporting.collect_power_analysis),
            ("fusion_analysis", Reporting.collect_fusion_analysis),
        ):
            data = collector(top, run_dir, selected_pdk)
            if data is not None:
                metrics[name] = data

        implementation = Reporting.collect_implementation(top, run_dir, selected_pdk)
        if implementation is not None:
            metrics["implementation"] = implementation

        post_impl: dict[str, Any] = {}
        for name, collector in (
            ("sdf", Reporting.collect_sdf),
            ("gls", Reporting.collect_post_syn_gls),
            ("sta", Reporting.collect_sta),
            ("power_estimate", Reporting.collect_power_estimate),
            ("power_analysis", Reporting.collect_power_analysis),
            ("fusion_analysis", Reporting.collect_fusion_analysis),
        ):
            data = collector(top, run_dir, selected_pdk, "post_impl")
            if data is not None:
                post_impl[name] = data
        if post_impl:
            metrics["post_impl"] = post_impl

        physical = Reporting.collect_physical_signoff(run_dir, selected_pdk)
        if physical is not None:
            metrics["physical_signoff"] = physical

        synthesis = metrics.get("synthesis")
        if isinstance(synthesis, dict):
            netlist = layout.syn_dir / f"{top}_synth.v"
            synthesis["netlist"] = Reporting.relative(netlist, run_dir) if netlist.is_file() else None
        metrics["verification"] = Reporting.verification_summary(metrics)
        metrics["signoff"] = Reporting.signoff_summary(metrics)
        metrics["flow"] = Reporting.flow_summary(metrics)
        metrics["closure"] = Reporting.closure_status(metrics)
        metrics["technical_status"] = Reporting.technical_status(metrics)
        if provenance is not None:
            metrics["provenance"] = dict(provenance)
        return metrics

    @staticmethod
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

    @staticmethod
    def _git(
        root: Path, *args: str, runner=None, on: str = "local"
    ) -> str | None:
        """Return one Git command result through ToolRunner."""

        from ..core.runtime.execution import CommandRequest, ToolRunner

        active_runner = runner or ToolRunner(project_root=root)
        label = "-".join(part.replace("/", "_") for part in args[:2]) or "command"
        log = root / ".flexsoc" / "logs" / "reporting" / f"git-{label}.log"
        result = active_runner.run(
            CommandRequest(("git", "-C", str(root), *args), root, {}, log), on=on
        )
        if result.returncode != 0:
            return None
        return log.read_text(encoding="utf-8", errors="replace").strip()

    @staticmethod
    def _file_sha256(path: Path) -> str | None:
        """Return a SHA256 digest when the file exists."""

        if not path.is_file():
            return None
        return hashlib.sha256(path.read_bytes()).hexdigest()

    @staticmethod
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

    @staticmethod
    def _analysis_evidence(run_root: Path) -> dict[str, object]:
        """Return lightweight post-lint analysis evidence for the run manifest."""

        result: dict[str, object] = {}
        lint_dir = run_root / "dv" / "lint"
        if lint_dir.is_dir():
            result["lint"] = {"path": lint_dir.relative_to(run_root).as_posix()}
        summary = run_root / "dv" / "cdc_rdc" / "summary.json"
        if summary.is_file():
            record: dict[str, object] = {
                "path": summary.relative_to(run_root).as_posix(),
                "sha256": Reporting._file_sha256(summary),
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

    @staticmethod
    def collect_manifest(
        *,
        top: str,
        run_top: str,
        run_id: str,
        repo_root: Path,
        pdk: str | None = None,
        run_root: Path | None = None,
        runner=None,
        on: str = "local",
    ) -> dict[str, object]:
        """Collect run identity, source revision, environment, and tool versions."""

        environment = Toolchain.collect(repo_root, runner=runner, on=on)
        commit = Reporting._git(repo_root, "rev-parse", "HEAD", runner=runner, on=on)
        status = Reporting._git(repo_root, "status", "--porcelain", runner=runner, on=on)
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
            evidence = Reporting._analysis_evidence(Path(run_root_value))
            analysis = evidence or None
        if pdk and run_root_value:
            run_root = Path(run_root_value)
            candidates = PDKRunLayout.from_run(run_root, pdk=pdk, top=top).as_dict()
            artifact_paths = {
                name: value
                for name, value in candidates.items()
                if Path(value).exists()
            }
            metrics = Reporting.collect_metrics(top, run_root, pdk=pdk)
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
                "flexsoc": Reporting._flexsoc_version(repo_root),
                "python": platform.python_version(),
                "platform": platform.platform(),
                "machine": platform.machine(),
                "uv_lock_sha256": Reporting._file_sha256(repo_root / "uv.lock"),
                "toolchain_lock_sha256": Reporting._file_sha256(
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
