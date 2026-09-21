"""Unified RTL lint orchestration and canonical summary ownership."""

from __future__ import annotations

from dataclasses import dataclass, field, replace
from io import StringIO
import json
from pathlib import Path
from typing import Any, Mapping

from rich.console import Console

from ...core import BackendContext, ToolRunner
from ...core.render.show import ShowRenderer
from .slang_lint import SlangLint
from .verilator_lint import VerilatorLint


@dataclass(slots=True)
class Lint:
    """Own lint execution, aggregation and presentation for one backend context."""

    context: BackendContext
    runner: ToolRunner
    slang: SlangLint = field(init=False)
    verilator: VerilatorLint = field(init=False)

    def __post_init__(self) -> None:
        self.slang = SlangLint(self.context, self.runner)
        self.verilator = VerilatorLint(self.context, self.runner)

    # Execution

    def run(self, *, on: str = "local") -> int:
        """Run Slang and Verilator once each; priorities are reporting-only in development mode."""

        profile = self._profile()
        (self.context.paths.lint / "summary.json").unlink(missing_ok=True)
        self.slang.run(profile=profile, on=on)
        self.verilator.run(profile=profile, on=on)
        return 0 if self._write_summary()["status"] == "PASS" else 1

    def run_slang(self, *, on: str = "local") -> int:
        """Run only the atomic Slang target."""

        _, summary = self.slang.run(profile=self._profile(), on=on)
        return 0 if summary["status"] == "PASS" else 1

    def run_verilator(self, *, on: str = "local") -> int:
        """Run only the atomic Verilator target."""

        _, summary = self.verilator.run(profile=self._profile(), on=on)
        return 0 if summary["status"] == "PASS" else 1

    # Presentation

    def show(
        self,
        *,
        tool: str | None = None,
        debug: bool = False,
        summary: bool = False,
        output: str | None = None,
        as_json: bool = False,
    ) -> int:
        """Render existing lint evidence, optionally filtered to one tool."""

        summary_path = self.context.paths.lint / "summary.json"
        if not summary_path.is_file():
            raise FileNotFoundError(f"lint summary not found: {summary_path}; run `fx lint` first")
        if tool not in {None, "slang", "verilator"}:
            raise ValueError("--tool must be slang or verilator")

        document = ShowRenderer.load_file(self.context.paths.run, "dv/lint/summary.json")
        data = dict(document.data)
        if tool:
            tools = data.get("tools", {})
            selected = tools.get(tool) if isinstance(tools, Mapping) else None
            if not isinstance(selected, Mapping):
                raise ValueError(f"lint summary has no {tool} evidence")
            data["selected_tool"] = tool
            data["order"] = [tool]
            data["tools"] = {tool: dict(selected)}
            data["counts"] = dict(selected.get("counts", {}))
            data["total"] = int(selected.get("total", 0))
            data["diagnostics"] = [
                item for item in data.get("diagnostics", ())
                if isinstance(item, Mapping) and item.get("tool") == tool
            ]
            document = replace(document, data=data)

        if summary:
            data["summary_only"] = True
            document = replace(document, data=data)

        capture = StringIO() if output else None
        console = Console(file=capture, force_terminal=False) if capture else Console()
        if as_json:
            text = json.dumps(data, indent=2, sort_keys=True) + "\n"
            print(text, end="", file=capture or None)
        else:
            ShowRenderer(console).render(document)
            if debug:
                counts = data.get("counts", {}) if isinstance(data.get("counts"), Mapping) else {}
                console.print()
                console.print("[bold]Hints[/bold]")
                if int(counts.get("P0", 0)):
                    console.print("[red]P0[/red] Critical diagnostics are present; lint remains reporting-only.")
                if int(counts.get("P1", 0)):
                    console.print("[orange1]P1[/orange1] Functional-risk diagnostics should be fixed or waived explicitly.")
                if not int(counts.get("P0", 0)) and not int(counts.get("P1", 0)):
                    console.print("[green]No P0/P1 diagnostics.[/green]")
                console.print(f"[grey70]summary[/grey70] {summary_path}")
                console.print(f"[grey70]slang JSON[/grey70] {self.context.paths.lint / 'slang' / 'slang_diag.json'}")
                console.print(f"[grey70]verilator SARIF[/grey70] {self.context.paths.lint / 'verilator' / 'verilator.sarif'}")

        if output and capture is not None:
            destination = Path(output)
            if not destination.is_absolute():
                destination = self.context.project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(capture.getvalue(), encoding="utf-8")
        return 0

    # Summary

    def _profile(self) -> str:
        """Return the selected developer/nightly lint profile."""

        profile = str(self.context.values.get("LINT_PROFILE", "everything")).strip().lower()
        if profile not in {"critical", "everything"}:
            raise ValueError("LINT_PROFILE must be critical or everything")
        return profile

    def _write_summary(self) -> dict[str, Any]:
        """Aggregate both tool summaries into the only release-facing lint artifact."""

        tools: dict[str, Any] = {}
        diagnostics: list[dict[str, Any]] = []
        counts = {priority: 0 for priority in ("P0", "P1", "P2", "P3")}
        for name in ("slang", "verilator"):
            path = self.context.paths.lint / name / "summary.json"
            if not path.is_file():
                continue
            try:
                item = json.loads(path.read_text(encoding="utf-8"))
            except (OSError, json.JSONDecodeError):
                continue
            if not isinstance(item, Mapping):
                continue

            tools[name] = {
                key: value for key, value in item.items()
                if key not in {"diagnostics", "artifacts"}
            }
            for priority in counts:
                counts[priority] += int(item.get("counts", {}).get(priority, 0))
            diagnostics.extend(
                entry for entry in item.get("diagnostics", ()) if isinstance(entry, dict)
            )

        status = (
            "PASS"
            if len(tools) == 2 and all(item.get("status") == "PASS" for item in tools.values())
            else "FAILED"
        )
        summary = {
            "schema": "flexsoc.lint.v1",
            "stage": "lint",
            "policy": "reporting-only",
            "top": self.context.paths.top,
            "profile": self._profile(),
            "status": status,
            "order": [name for name in ("slang", "verilator") if name in tools],
            "counts": counts,
            "total": len(diagnostics),
            "tools": tools,
            "artifacts": {"summary": "dv/lint/summary.json"},
            "diagnostics": sorted(
                diagnostics,
                key=lambda item: (
                    str(item.get("priority", "P3")),
                    str(item.get("tool", "")),
                    str(item.get("file", "")),
                    int(item.get("line") or 0),
                    str(item.get("code", "")),
                ),
            ),
        }
        path = self.context.paths.lint / "summary.json"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return summary
