"""DV facade and lint orchestration."""

from __future__ import annotations

from dataclasses import dataclass, field

from ..core import BackendContext, ToolRunner
from .cdc import CdcFlow
from .coverage import CoverageFlow
from .formal import FormalFlow
from .functional import FunctionalFlow
from .testbench import TestbenchFlow


@dataclass(slots=True)
class DvFlow:
    """Expose DV components without hiding their operation-specific APIs."""

    context: BackendContext
    runner: ToolRunner | None = None
    testbench: TestbenchFlow = field(init=False)
    functional: FunctionalFlow = field(init=False)
    coverage: CoverageFlow = field(init=False)
    cdc: CdcFlow = field(init=False)
    formal: FormalFlow = field(init=False)

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)
        self.testbench = TestbenchFlow()
        self.functional = FunctionalFlow(self.runner)
        self.coverage = CoverageFlow(self.runner)
        self.cdc = CdcFlow(self.runner)
        self.formal = FormalFlow(self.runner)

    def flow(self, *, lint: bool = True, functional: bool = True, formal: bool = True):
        """Run the configured canonical DV stages in lifecycle order."""
        results = []
        if lint:
            results.append(self.lint_suite())
        if functional:
            results.append(self.functional.flow_from_context(self.context))
            results.append(self.coverage.flow_from_context(self.context))
        results.append(self.cdc.flow_from_context(self.context))
        if formal:
            results.append(self.formal.flow_from_context(self.context))
        return tuple(results)

    def lint_slang(self, *, kind: str = "all", part: str = "ip", on: str = "local"):
        """Run Slang lint for one diagnostic class."""
        return self._lint("slang", kind=kind, part=part, on=on)

    def lint_verilator(self, *, kind: str = "all", part: str = "ip", on: str = "local"):
        """Run Verilator lint for one diagnostic class."""
        return self._lint("verilator", kind=kind, part=part, on=on)

    def lint_suite(self, *, tools=("slang", "verilator"), part: str = "ip", on: str = "local"):
        """Run every supported focused lint class for selected tools."""
        return tuple(
            self._lint(tool, kind=kind, part=part, on=on)
            for tool in tools
            for kind in ("all", "latch", "undriven", "width", "unconnected", "unused")
        )

    def _lint(self, tool: str, *, kind: str, part: str, on: str):
        """Run one exact lint class through the shared runner."""
        import re
        from ..core import CommandRequest
        from ..core.execution import print_label, print_path_label, print_status_label

        values, paths = self.context.values, self.context.paths
        if not paths.rtl_common.is_file() or not paths.rtl_ip.is_file():
            raise FileNotFoundError("RTL filelists missing; generate them before lint")
        if tool not in {"slang", "verilator"}:
            raise ValueError("lint tool must be slang or verilator")
        if kind not in {"all", "latch", "undriven", "width", "unconnected", "unused"}:
            raise ValueError(f"unsupported lint kind: {kind}")
        if part not in {"ip", "common", "all"}:
            raise ValueError("lint part must be ip, common, or all")

        logdir = paths.logs / "lint"
        raw = logdir / "raw" / f"{paths.top}_lint_{tool}_{kind}_raw.log"
        full = logdir / f"{paths.top}_lint_{tool}_{kind}.log"
        raw.parent.mkdir(parents=True, exist_ok=True)
        print_label("lint", f"tool={tool} · kind={kind} · part={part}")
        print_path_label("log", full)
        print_path_label("raw-log", raw)
        argv = self._lint_command(tool, kind, paths, values)
        result = self.runner.run(CommandRequest(argv, self.context.project_root, {}, raw), on=on)
        raw_text = raw.read_text(encoding="utf-8", errors="replace") if raw.exists() else ""
        if result.returncode:
            full.write_text(raw_text, encoding="utf-8")
            print_status_label("lint", "FAIL", f"tool={tool} · kind={kind} · part={part}")
            raise RuntimeError(f"{tool} lint failed; log: {raw}")
        if kind == "all":
            full.write_text(raw_text, encoding="utf-8")
            print_status_label("lint", "PASS", f"tool={tool} · kind={kind} · part={part}")
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
        full.write_text(("\n".join(selected) + "\n") if selected else f"No {kind} diagnostics for {part}.\n", encoding="utf-8")
        print_status_label("lint", "PASS", f"tool={tool} · kind={kind} · part={part}")
        return result

    @staticmethod
    def _lint_command(tool: str, kind: str, paths, values) -> tuple[str, ...]:
        """Build the exact focused Slang or Verilator lint command."""
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
            return (values.get("LINTER", "verilator"), *flags, "-f", str(paths.rtl_common), "-f", str(paths.rtl_ip), "--top-module", paths.top)

        focused = {
            "all": (),
            "latch": ("-Winferred-latch",),
            "undriven": ("-Wundriven-port",),
            "width": ("-Wwidth-trunc", "-Wwidth-expand", "-Wport-width-trunc", "-Wport-width-expand"),
            "unconnected": ("-Wunconnected-input-port", "-Wunconnected-output-port", "-Wunconnected-inout-port", "-Wempty-input-connection", "-Wempty-output-connection", "-Wempty-inout-connection"),
            "unused": ("-Wunused-def", "-Wunused-net", "-Wunused-port", "-Wunused-variable", "-Wunused-parameter", "-Wunused-typedef", "-Wunused-import"),
        }
        base = ("--lint-only", "--single-unit", "--top", paths.top, "-DSYNTHESIS", "--diag-abs-paths", "--diag-hierarchy", "never")
        return (values.get("SLANG", "slang"), *base, *focused[kind], "-f", str(paths.rtl_common), "-f", str(paths.rtl_ip))
