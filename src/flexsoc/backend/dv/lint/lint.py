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
        contract = getattr(self.context, "rtl_contract", None)
        if contract is None:
            self.slang = SlangLint(self.context, self.runner)
            self.verilator = VerilatorLint(self.context, self.runner)
            return
        self.slang = SlangLint(
            self.context, self.runner, filelists=contract.filelists, top=contract.top
        )
        self.verilator = VerilatorLint(
            self.context, self.runner, filelists=contract.filelists, top=contract.top
        )

    def _lint_top(self) -> str:
        """Return the design top represented by the active RTL source contract."""

        contract = getattr(self.context, "rtl_contract", None)
        return contract.top if contract is not None else self.context.paths.top

    # Execution

    def run(self, *, on: str = "local") -> int:
        """Run Slang and Verilator once each; priorities are reporting-only in development mode."""

        profile = self._profile()
        (self.context.paths.lint / "summary.json").unlink(missing_ok=True)
        self.slang.run(profile=profile, on=on)
        self.verilator.run(profile=profile, on=on)
        return 0 if self._write_summary()["status"] == "PASS" else 1

    # Presentation

    def debug(
        self,
        *,
        tool: str | None = None,
        priority: str | None = None,
        scope: str | None = None,
        warning_type: str | None = None,
        output: str | None = None,
        as_json: bool = False,
    ) -> int:
        """Render canonical lint evidence plus diagnostic hints."""

        return self.show(tool=tool, priority=priority, scope=scope, warning_type=warning_type, debug=True, output=output, as_json=as_json)

    def show(
        self,
        *,
        tool: str | None = None,
        priority: str | None = None,
        scope: str | None = None,
        warning_type: str | None = None,
        debug: bool = False,
        summary: bool = False,
        output: str | None = None,
        as_json: bool = False,
    ) -> int:
        """Render existing lint evidence, optionally filtered by tool and priority."""

        summary_path = self.context.paths.lint / "summary.json"
        if not summary_path.is_file():
            raise FileNotFoundError(f"lint summary not found: {summary_path}; run `fx lint` first")
        if tool not in {None, "slang", "verilator"}:
            raise ValueError("--tool must be slang or verilator")

        document = ShowRenderer.load_file(self.context.paths.run, "dv/lint/summary.json")
        data = dict(document.data)
        data["diagnostics"] = [
            {**item, "scope": self._scope(str(item.get("file", ""))),
             "type": str(item.get("code") or "unknown"),
             "owner": self._owner(str(item.get("file", "")), data.get("top", "ip"))}
            for item in data.get("diagnostics", ()) if isinstance(item, Mapping)
        ]
        if "scopes" not in data:
            data["scopes"] = self._scope_counts(data["diagnostics"])
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
            data["scopes"] = self._scope_counts(data["diagnostics"])
            document = replace(document, data=data)

        if scope is not None and scope.lower() not in {"common", "ip", "soc", "all"}:
            raise ValueError("--scope must be common, ip, soc, or all")
        selected_scope = scope.lower() if scope else "all"
        data["selected_scope"] = selected_scope
        data["selected_type"] = warning_type
        data["diagnostics"] = [
            item for item in data.get("diagnostics", ())
            if isinstance(item, Mapping)
            and (selected_scope == "all" or item.get("scope") == selected_scope)
            and (warning_type is None or str(item.get("code", "")).lower() == warning_type.lower())
        ]
        priorities = self._selected_priorities(priority)
        data["selected_priorities"] = list(priorities)
        data["diagnostics"] = [
            item for item in data.get("diagnostics", ())
            if isinstance(item, Mapping) and item.get("priority") in priorities
        ]
        data["visible_total"] = len(data["diagnostics"])
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
                tools = data.get("tools", {}) if isinstance(data.get("tools"), Mapping) else {}
                for name in data.get("order", ()):
                    item = tools.get(name, {}) if isinstance(tools, Mapping) else {}
                    command = item.get("command", ()) if isinstance(item, Mapping) else ()
                    if command:
                        console.print(f"[grey70]{name} command[/grey70] {' '.join(map(str, command))}")
                    artifacts = item.get("artifacts", {}) if isinstance(item, Mapping) else {}
                    if isinstance(artifacts, Mapping):
                        for kind, path in artifacts.items():
                            console.print(f"[grey70]{name} {kind}[/grey70] {path}")

        if output and capture is not None:
            destination = Path(output)
            if not destination.is_absolute():
                destination = self.context.project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(capture.getvalue(), encoding="utf-8")
        return 0

    @staticmethod
    def _selected_priorities(value: str | None) -> tuple[str, ...]:
        """Return the diagnostic priorities visible in a lint evidence view."""

        if value is None:
            return ("P0", "P1")
        tokens = tuple(part.strip().upper() for part in value.split(",") if part.strip())
        if not tokens:
            raise ValueError("--priority must be P0, P1, P2, P3, all, or a comma-separated list")
        if tokens == ("ALL",):
            return ("P0", "P1", "P2", "P3")
        allowed = {"P0", "P1", "P2", "P3"}
        if any(token not in allowed for token in tokens):
            raise ValueError("--priority must be P0, P1, P2, P3, all, or a comma-separated list")
        return tuple(dict.fromkeys(tokens))

    @staticmethod
    def _scope(filename: str) -> str:
        """Classify diagnostics by source ownership, never by warning text."""
        from pathlib import PurePosixPath
        path = filename.replace("\\", "/").lower()
        parts = PurePosixPath(path).parts
        if "soc" in parts or "soc_top" in parts:
            return "soc"
        if "vendor" in parts or "deps" in parts or "prim" in parts or "prim_opentitan" in parts or "pkgs" in parts:
            return "common"
        if "hw" in parts and "ips" in parts and "prim" not in parts:
            return "common" if "tlul" in parts else "ip"
        return "ip"

    @staticmethod
    def _owner(filename: str, top: str) -> str:
        """Preserve IP ownership where paths identify the source IP."""
        parts = filename.replace("\\", "/").split("/")
        if "ips" in parts:
            index = parts.index("ips")
            if index + 1 < len(parts) and parts[index + 1] not in {"pkgs", "prim", "prim_opentitan"}:
                return parts[index + 1]
        return str(top)

    @staticmethod
    def _scope_counts(diagnostics: list[dict[str, Any]]) -> dict[str, Any]:
        """Build per-scope priority and warning-type totals."""
        scopes = {name: {"total": 0, "counts": {p: 0 for p in ("P0", "P1", "P2", "P3")}, "types": {}, "owners": {}}
                  for name in ("soc", "ip", "common")}
        for item in diagnostics:
            group = scopes[item["scope"]]
            group["total"] += 1
            priority = item.get("priority", "P3")
            group["counts"][priority] = group["counts"].get(priority, 0) + 1
            owner = item.get("owner", "-")
            group["owners"][owner] = group["owners"].get(owner, 0) + 1
            kind = item["type"]
            group["types"][kind] = group["types"].get(kind, 0) + 1
        return scopes

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
                if key != "diagnostics"
            }
            for priority in counts:
                counts[priority] += int(item.get("counts", {}).get(priority, 0))
            diagnostics.extend(
                {**entry, "scope": self._scope(str(entry.get("file", ""))),
                 "type": str(entry.get("code") or "unknown"),
                 "owner": self._owner(str(entry.get("file", "")), self._lint_top())}
                for entry in item.get("diagnostics", ()) if isinstance(entry, dict)
            )

        status = (
            "PASS"
            if len(tools) == 2 and all(item.get("status") == "PASS" for item in tools.values())
            else "FAILED"
        )
        scopes = self._scope_counts(diagnostics)
        summary = {
            "schema": "flexsoc.lint.v1",
            "stage": "lint",
            "policy": "reporting-only",
            "top": self._lint_top(),
            "profile": self._profile(),
            "status": status,
            "order": [name for name in ("slang", "verilator") if name in tools],
            "counts": counts,
            "scopes": scopes,
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
