"""Verilator lint execution and SARIF normalization."""

from __future__ import annotations

from dataclasses import dataclass
import json
from pathlib import Path
from typing import Any, Mapping

from ...core import BackendContext, CommandRequest, ToolRunner
from ...core.runtime.execution import Terminal


@dataclass(slots=True)
class VerilatorLint:
    """Run one Verilator lint pass and normalize SARIF diagnostics."""

    context: BackendContext
    runner: ToolRunner

    _P0 = {
        "BLKANDNBLK", "MULTIDRIVEN", "MULTIDRIVENPROC", "LATCH", "CASEOVERLAP",
        "CASEINCOMPLETE", "WIDTH", "WIDTHTRUNC", "PINMISSING", "UNDRIVEN",
        "ALWCOMBORDER", "ASSIGNIN", "INFINITELOOP",
    }
    _P1 = {
        "BLKSEQ", "SYNCASYNCNET", "UNSIGNED", "CMPCONST", "VARHIDDEN",
        "PINCONNECTEMPTY", "CASEX", "CASEWITHX",
    }
    _P2 = {
        "UNOPTFLAT", "GENUNNAMED", "DEFPARAM", "WIDTHEXPAND", "IMPORTSTAR",
        "UNUSEDSIGNAL", "UNUSEDLOOP",
    }
    _P3 = {"EOFNEWLINE", "DECLFILENAME", "UNUSEDPARAM", "UNUSEDGENVAR", "PINNOCONNECT"}

    # Execution

    def run(self, *, profile: str, on: str = "local") -> tuple[object, dict[str, Any]]:
        """Run Verilator once; diagnostics are evidence and never gate lint in development mode."""

        paths = self.context.paths
        if not paths.rtl_common.is_file() or not paths.rtl_ip.is_file():
            raise FileNotFoundError("RTL filelists missing; generate them before lint")
        if profile not in {"critical", "everything"}:
            raise ValueError("LINT_PROFILE must be critical or everything")

        analysis = paths.lint / "verilator"
        sarif = analysis / "verilator.sarif"
        log = paths.logs / "dv" / "lint" / "verilator" / "verilator.log"
        analysis.mkdir(parents=True, exist_ok=True)
        log.parent.mkdir(parents=True, exist_ok=True)
        sarif.unlink(missing_ok=True)

        Terminal.print_label("lint", f"tool=verilator · profile={profile}")
        Terminal.print_path_label("diagnostics", sarif)
        Terminal.print_path_label("log", log)
        result = self.runner.run(
            CommandRequest(self._command(profile, sarif), self.context.project_root, {}, log),
            on=on,
        )

        diagnostics = self._diagnostics(sarif)
        complete = diagnostics is not None
        if diagnostics is None:
            diagnostics = [{
                "tool": "verilator", "priority": "P0", "severity": "error",
                "code": "TOOL-EXECUTION",
                "message": f"verilator exited with status {result.returncode}",
                "file": "", "line": 0, "column": 0,
            }]
        counts = {priority: 0 for priority in ("P0", "P1", "P2", "P3")}
        for item in diagnostics:
            counts[item["priority"]] += 1

        summary = {
            "schema": "flexsoc.lint.tool.v1", "top": paths.top, "tool": "verilator",
            "profile": profile, "status": "PASS" if complete else "FAILED",
            "returncode": result.returncode, "counts": counts, "total": len(diagnostics),
            "diagnostics": diagnostics,
            "artifacts": {"diagnostics": str(sarif), "log": str(log)},
        }
        (analysis / "summary.json").write_text(
            json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
        )
        Terminal.print_status_label(
            "lint", summary["status"], f"tool=verilator · diagnostics={summary['total']}"
        )
        return result, summary

    def _command(self, profile: str, sarif: Path) -> tuple[str, ...]:
        """Build one portable Verilator 5.050+ lint invocation."""

        paths, values = self.context.paths, self.context.values
        warnings = (
            ("-Wall",)
            if profile == "everything"
            else (
                "-Wwarn-lint", "-Wno-style", "-Wwarn-BLKSEQ", "-Wwarn-SYNCASYNCNET",
                "-Wwarn-VARHIDDEN", "-Wwarn-PINCONNECTEMPTY", "-Wwarn-CASEX",
                "-Wwarn-CASEWITHX",
            )
        )
        waiver_args: tuple[str, ...] = ()
        if value := values.get("VERILATOR_WAIVER_FILE"):
            waiver = Path(str(value)).expanduser()
            if not waiver.is_absolute():
                waiver = self.context.project_root / waiver
            waiver_args = (str(waiver),)
        return (
            values.get("VERILATOR", "verilator"), "--lint-only", "--sv", "-Wno-fatal",
            *warnings, "--diagnostics-sarif-output", str(sarif), *waiver_args,
            "-f", str(paths.rtl_common), "-f", str(paths.rtl_ip), "--top-module", paths.top,
        )

    # Diagnostics

    def _diagnostics(self, path: Path) -> list[dict[str, Any]] | None:
        """Read valid SARIF and normalize it; return None when evidence is unusable."""

        if not path.is_file():
            return None
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            return None
        if not isinstance(payload, Mapping) or not isinstance(payload.get("runs", []), list):
            return None

        diagnostics: list[dict[str, Any]] = []
        for run in payload.get("runs", ()):
            if not isinstance(run, Mapping):
                continue
            for item in run.get("results", ()):
                if not isinstance(item, Mapping):
                    continue
                code = str(item.get("ruleId") or "diagnostic").upper()
                severity = str(item.get("level") or "warning").lower()
                message_data = item.get("message") if isinstance(item.get("message"), Mapping) else {}
                message = str(message_data.get("text") or message_data.get("markdown") or "diagnostic")

                file, line, column = "", 0, 0
                locations = item.get("locations") or ()
                if isinstance(locations, list) and locations and isinstance(locations[0], Mapping):
                    physical = locations[0].get("physicalLocation")
                    if isinstance(physical, Mapping):
                        artifact = physical.get("artifactLocation")
                        artifact = artifact if isinstance(artifact, Mapping) else {}
                        region = physical.get("region")
                        region = region if isinstance(region, Mapping) else {}
                        file = self._relative(artifact.get("uri"))
                        line = int(region.get("startLine") or 0)
                        column = int(region.get("startColumn") or 0)

                diagnostics.append({
                    "tool": "verilator", "priority": self._priority(code, severity),
                    "severity": severity, "code": code, "message": message,
                    "file": file, "line": line, "column": column,
                })
        return diagnostics

    def _relative(self, value: object) -> str:
        """Prefer run- or project-relative source paths in stored diagnostics."""

        if not value:
            return ""
        path = Path(str(value).removeprefix("file://").removeprefix("file:"))
        for root in (getattr(self.context.paths, "run", None), self.context.project_root):
            if root is None:
                continue
            try:
                return path.resolve().relative_to(Path(root).resolve()).as_posix()
            except (OSError, ValueError):
                pass
        return str(path)

    # Priority policy

    def _priority(self, code: str, severity: str) -> str:
        """Map one Verilator diagnostic to P0-P3 without changing target status."""

        if severity in {"error", "fatal"}:
            return "P0"
        if code in self._P0:
            return "P0"
        if code in self._P1:
            return "P1"
        if code in self._P3:
            return "P3"
        return "P2"
