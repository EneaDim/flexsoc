"""Slang lint execution and diagnostic normalization."""

from __future__ import annotations

from dataclasses import dataclass
import json
from pathlib import Path
import re
from typing import Any, Mapping

from ...core import BackendContext, CommandRequest, ToolRunner
from ...core.runtime.execution import Terminal


@dataclass(slots=True)
class SlangLint:
    """Run one full Slang elaboration and normalize its diagnostics."""

    context: BackendContext
    runner: ToolRunner
    filelists: tuple[Path, ...] | None = None
    top: str | None = None

    _P0 = (
        "width-trunc", "port-width-trunc", "overflow", "out-of-bounds", "outside-range",
        "multiple-driver", "multi-driven", "inferred-latch", "undriven", "unassigned",
        "implicit-net", "unconnected-input-port", "empty-input-connection", "case-overlap",
        "case-incomplete", "case-dup", "case-none", "divide-by-zero", "event-const",
        "parameter-override",
    )
    _P1 = (
        "sign-conversion", "sign-compare", "signed", "implicit-conv", "constant-conversion",
        "arith-op-mismatch", "bitwise-op-mismatch", "comparison-mismatch", "precedence",
        "shadow", "shift", "case-unreachable", "unused-but-set", "ineffective-sign",
    )
    _P3 = (
        "unused-typedef", "unused-import", "unused-wildcard-import", "unused-result",
        "empty-member", "empty-stmt", "misleading-indentation", "header-guard", "pragma", "dpi",
    )

    def _source_filelists(self) -> tuple[Path, ...]:
        """Return the explicit lint source contract for this design."""

        paths = self.context.paths
        files = self.filelists or (paths.rtl_common, paths.rtl_ip)
        missing = [path for path in files if not path.is_file()]
        if missing:
            raise FileNotFoundError(
                "RTL filelists missing; generate them before lint: "
                + ", ".join(str(path) for path in missing)
            )
        return tuple(files)

    # Execution

    def run(self, *, profile: str, on: str = "local") -> tuple[object, dict[str, Any]]:
        """Run Slang once; diagnostics are evidence and never gate lint in development mode."""

        paths = self.context.paths
        self._source_filelists()
        if profile not in {"critical", "everything"}:
            raise ValueError("LINT_PROFILE must be critical or everything")

        analysis = paths.lint / "slang"
        diagnostics_path = analysis / "slang_diag.json"
        log = paths.logs / "dv" / "lint" / "slang" / "slang.log"
        analysis.mkdir(parents=True, exist_ok=True)
        log.parent.mkdir(parents=True, exist_ok=True)
        diagnostics_path.unlink(missing_ok=True)

        Terminal.print_label("lint", f"tool=slang · profile={profile}")
        Terminal.print_path_label("diagnostics", diagnostics_path)
        Terminal.print_path_label("log", log)
        command = self._command(profile, diagnostics_path)
        result = self.runner.run(
            CommandRequest(
                command, self.context.project_root, {}, log, outputs=(diagnostics_path,),
            ),
            on=on,
        )

        diagnostics = self._diagnostics(diagnostics_path)
        complete = diagnostics is not None
        diagnostics = diagnostics or []
        counts = {priority: 0 for priority in ("P0", "P1", "P2", "P3")}
        for item in diagnostics:
            counts[item["priority"]] += 1

        summary = {
            "schema": "flexsoc.lint.tool.v1", "top": self.top or paths.top, "tool": "slang",
            "profile": profile, "status": "PASS" if complete else "FAILED",
            "returncode": result.returncode, "counts": counts, "total": len(diagnostics),
            "command": list(command), "diagnostics": diagnostics,
            "artifacts": {
                "diagnostics": "dv/lint/slang/slang_diag.json",
                "log": "logs/dv/lint/slang/slang.log",
            },
        }
        (analysis / "summary.json").write_text(
            json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
        )
        Terminal.print_status_label(
            "lint", summary["status"], f"tool=slang · diagnostics={summary['total']}"
        )
        return result, summary

    def _command(self, profile: str, diagnostics: Path) -> tuple[str, ...]:
        """Build the single full-elaboration Slang invocation."""

        paths, values = self.context.paths, self.context.values
        top = self.top or paths.top
        source_args = tuple(
            item for path in self._source_filelists() for item in ("-f", str(path))
        )
        warnings = (
            ("-Weverything",)
            if profile == "everything"
            else (
                "-Wextra", "-Wconversion", "-Wshadow", "-Wparentheses",
                "-Wunconnected-port", "-Wempty-connection", "-Wimplicit-net",
                "-Wundriven-net", "-Wundriven-port", "-Wunused-but-set-net",
                "-Wunused-but-set-variable", "-Wunused-but-set-port", "-Wsign-compare",
                "-Wcomparison-mismatch", "-Warith-op-mismatch", "-Wbitwise-op-mismatch",
            )
        )
        waiver_args: tuple[str, ...] = ()
        if value := values.get("SLANG_WAIVER_FILE"):
            waiver = Path(str(value)).expanduser()
            if not waiver.is_absolute():
                waiver = self.context.project_root / waiver
            waiver_args = ("--waiver-file", str(waiver))
        return (
            values.get("SLANG", "slang"), "--single-unit", "--top", top, "-DSYNTHESIS",
            "--diag-abs-paths", "--diag-hierarchy", "never", "--diag-json", str(diagnostics),
            *warnings, *waiver_args, *source_args,
        )

    # Diagnostics

    def _diagnostics(self, path: Path) -> list[dict[str, Any]] | None:
        """Read valid Slang JSON and normalize it; return None when evidence is unusable."""

        if not path.is_file():
            return None
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            return None
        items = payload.get("diagnostics", ()) if isinstance(payload, Mapping) else payload
        if not isinstance(items, list):
            return None

        diagnostics: list[dict[str, Any]] = []
        for item in items:
            if not isinstance(item, Mapping):
                continue
            message = str(item.get("message") or item.get("text") or "diagnostic")
            severity = str(item.get("severity") or "warning").lower()
            code = item.get("optionName") or item.get("option") or item.get("code") or item.get("name")
            if isinstance(code, Mapping):
                code = code.get("value") or code.get("name")
            if not code:
                match = re.search(r"\[-W([A-Za-z0-9_-]+)\]", message)
                code = match.group(1) if match else "diagnostic"
            code = str(code).removeprefix("-W")

            location = item.get("location")
            if isinstance(location, str):
                match = re.match(r"^(.*):(\d+):(\d+)$", location)
                location = (
                    {"file": match.group(1), "line": match.group(2), "column": match.group(3)}
                    if match else {"file": location}
                )
            if not isinstance(location, Mapping):
                locations = item.get("locations") or item.get("ranges") or ()
                location = locations[0] if isinstance(locations, list) and locations else {}
            if not isinstance(location, Mapping):
                location = {}
            start = location.get("start") if isinstance(location.get("start"), Mapping) else location
            file = (
                start.get("fileName") or start.get("filename") or start.get("file") or start.get("path")
                or location.get("fileName") or location.get("filename") or location.get("file")
                or item.get("fileName") or item.get("filename") or item.get("file") or item.get("path") or ""
            )
            line = start.get("line") or start.get("lineNumber") or item.get("line") or item.get("lineNumber") or 0
            column = (
                start.get("column") or start.get("columnNumber")
                or item.get("column") or item.get("columnNumber") or 0
            )
            diagnostics.append({
                "tool": "slang", "priority": self._priority(code, severity),
                "severity": severity, "code": code, "message": message,
                "file": self._relative(file), "line": int(line), "column": int(column),
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
        """Map one Slang diagnostic to P0-P3 without changing target status."""

        if severity in {"error", "fatal"}:
            return "P0"
        token = code.lower()
        if any(part in token for part in self._P0):
            return "P0"
        if any(part in token for part in self._P1):
            return "P1"
        if any(part in token for part in self._P3):
            return "P3"
        return "P2"
