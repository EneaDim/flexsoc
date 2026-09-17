"""Focused RTL lint orchestration."""

from __future__ import annotations

from dataclasses import dataclass
import json
import re

from ...core import BackendContext, CommandRequest, ToolRunner
from ...core.runtime.execution import Terminal
from ...release.reporting import Reporting


@dataclass(slots=True)
class Lint:
    """Run focused Slang and Verilator lint targets for one backend context."""

    context: BackendContext
    runner: ToolRunner

    def run_slang(self, *, kind: str = "all", part: str = "ip", on: str = "local"):
        return self._run("slang", kind=kind, part=part, on=on)

    def run_verilator(self, *, kind: str = "all", part: str = "ip", on: str = "local"):
        return self._run("verilator", kind=kind, part=part, on=on)

    def run_suite(self, *, tools=("slang", "verilator"), part: str = "ip", on: str = "local"):
        """Run every focused lint class and refresh compact machine-readable QoR."""

        results = tuple(
            self._run(tool, kind=kind, part=part, on=on)
            for tool in tools
            for kind in ("all", "latch", "undriven", "width", "unconnected", "unused")
        )
        summary = Reporting.collect_lint(self.context.paths.top, self.context.paths.run)
        if summary:
            for values in summary.get("tools", {}).values():
                values.pop("command", None)
                values.pop("log", None)
            path = self.context.paths.lint / "summary.json"
            path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return results

    def _run(self, tool: str, *, kind: str, part: str, on: str):
        """Run one exact lint class through the shared execution abstraction."""

        paths = self.context.paths
        if not paths.rtl_common.is_file() or not paths.rtl_ip.is_file():
            raise FileNotFoundError("RTL filelists missing; generate them before lint")
        if tool not in {"slang", "verilator"}:
            raise ValueError("lint tool must be slang or verilator")
        if kind not in {"all", "latch", "undriven", "width", "unconnected", "unused"}:
            raise ValueError(f"unsupported lint kind: {kind}")
        if part not in {"ip", "common", "all"}:
            raise ValueError("lint part must be ip, common, or all")

        analysis_dir = paths.lint / tool
        logdir = paths.logs / "dv" / "lint" / tool
        raw = logdir / "raw" / f"{paths.top}_lint_{tool}_{kind}_raw.log"
        full = analysis_dir / f"{paths.top}_lint_{tool}_{kind}.log"
        raw.parent.mkdir(parents=True, exist_ok=True)
        full.parent.mkdir(parents=True, exist_ok=True)
        Terminal.print_label("lint", f"tool={tool} · kind={kind} · part={part}")
        Terminal.print_path_label("log", full)
        Terminal.print_path_label("raw-log", raw)
        result = self.runner.run(
            CommandRequest(self._command(tool, kind), self.context.project_root, {}, raw),
            on=on,
        )
        raw_text = raw.read_text(encoding="utf-8", errors="replace") if raw.exists() else ""
        if result.returncode:
            full.write_text(raw_text, encoding="utf-8")
            Terminal.print_status_label("lint", "FAIL", f"tool={tool} · kind={kind} · part={part}")
            raise RuntimeError(f"{tool} lint failed; log: {raw}")
        if kind == "all":
            full.write_text(raw_text, encoding="utf-8")
            Terminal.print_status_label("lint", "PASS", f"tool={tool} · kind={kind} · part={part}")
            return result

        patterns = {
            "latch": r"latch",
            "undriven": r"undriven|un-driven|unassigned",
            "width": r"width|truncate|extend",
            "unconnected": r"unconnected|pinconnectempty|pinnoconnect|pinmissing",
            "unused": r"unused|unusedsignal|unusedparam",
        }
        selected = [line for line in raw_text.splitlines() if re.search(patterns[kind], line, re.I)]
        rtl_prefix = str(paths.rtl)
        if part == "ip":
            selected = [line for line in selected if rtl_prefix in line]
        elif part == "common":
            selected = [line for line in selected if rtl_prefix not in line]
        full.write_text(
            ("\n".join(selected) + "\n") if selected else f"No {kind} diagnostics for {part}.\n",
            encoding="utf-8",
        )
        Terminal.print_status_label("lint", "PASS", f"tool={tool} · kind={kind} · part={part}")
        return result

    def _command(self, tool: str, kind: str) -> tuple[str, ...]:
        """Build the exact focused Slang or Verilator command."""

        paths, values = self.context.paths, self.context.values
        if tool == "verilator":
            disabled = (
                "-Wno-DECLFILENAME", "-Wno-PINMISSING", "-Wno-PINCONNECTEMPTY",
                "-Wno-PINNOCONNECT", "-Wno-UNDRIVEN", "-Wno-UNUSEDSIGNAL",
                "-Wno-UNUSEDPARAM", "-Wno-WIDTH", "-Wno-WIDTHEXPAND",
                "-Wno-WIDTHTRUNC", "-Wno-LATCH",
            )
            focused = {
                "all": ("-Wall",),
                "latch": ("-Wwarn-LATCH",),
                "undriven": ("-Wwarn-UNDRIVEN",),
                "width": ("-Wwarn-WIDTH", "-Wwarn-WIDTHEXPAND", "-Wwarn-WIDTHTRUNC"),
                "unconnected": ("-Wwarn-PINMISSING", "-Wwarn-PINCONNECTEMPTY", "-Wwarn-PINNOCONNECT"),
                "unused": ("-Wwarn-UNUSEDSIGNAL", "-Wwarn-UNUSEDPARAM"),
            }
            flags = ("--lint-only", "--sv", "-Wno-fatal", *(() if kind == "all" else disabled), *focused[kind])
            return (
                values.get("LINTER", "verilator"), *flags,
                "-f", str(paths.rtl_common), "-f", str(paths.rtl_ip),
                "--top-module", paths.top,
            )

        focused = {
            "all": (),
            "latch": ("-Winferred-latch",),
            "undriven": ("-Wundriven-port",),
            "width": ("-Wwidth-trunc", "-Wwidth-expand", "-Wport-width-trunc", "-Wport-width-expand"),
            "unconnected": (
                "-Wunconnected-input-port", "-Wunconnected-output-port", "-Wunconnected-inout-port",
                "-Wempty-input-connection", "-Wempty-output-connection", "-Wempty-inout-connection",
            ),
            "unused": (
                "-Wunused-def", "-Wunused-net", "-Wunused-port", "-Wunused-variable",
                "-Wunused-parameter", "-Wunused-typedef", "-Wunused-import",
            ),
        }
        base = (
            "--lint-only", "--single-unit", "--top", paths.top, "-DSYNTHESIS",
            "--diag-abs-paths", "--diag-hierarchy", "never",
        )
        return (
            values.get("SLANG", "slang"), *base, *focused[kind],
            "-f", str(paths.rtl_common), "-f", str(paths.rtl_ip),
        )
