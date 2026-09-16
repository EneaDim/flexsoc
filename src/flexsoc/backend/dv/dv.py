"""DV facade and lint orchestration."""

from __future__ import annotations

import json
from dataclasses import dataclass, field
from pathlib import Path

from ..core import BackendContext, Target, ToolRunner
from .cdc import CdcFlow
from .coverage import CoverageFlow
from .formal import FormalFlow
from .functional import FunctionalFlow
from .testbench import CocotbConfig, TestbenchConfig, TestbenchFlow


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

    def run_target(self, target: Target, *, inputs=(), on: str = "local"):
        """Execute one registered target through the owning DV component."""

        action = target.action or ""
        if action in {"tests_generate", "test_generate", "tests_list"}:
            return self._run_test_target(action, on=on)
        if action in {"tb_setup", "cocotb_setup", "coverage", "coverage_detail"} or action.startswith("functional_"):
            return self._run_functional_target(action, on=on)
        if action == "lint_slang":
            return self.lint_slang(on=on)
        if action == "lint_verilator":
            return self.lint_verilator(on=on)
        if action == "lint_slang_suite":
            return self.lint_suite(tools=("slang",), on=on)
        if action == "lint_verilator_suite":
            return self.lint_suite(tools=("verilator",), on=on)
        if action == "lint_focus":
            values = self.context.values
            kind = target.name.removeprefix("lint_") if target.name.startswith("lint_") else "all"
            tool = values.get("LINT_TOOL", "slang")
            part = values.get("LINT_PART", "ip")
            if kind not in {"latch", "undriven", "width", "unconnected", "unused"}:
                return self.lint_suite(tools=(tool,), part=part, on=on)
            return (
                self.lint_slang(kind=kind, part=part, on=on),
                self.lint_verilator(kind=kind, part=part, on=on),
            )
        if action == "cdc_setup":
            paths = self.context.paths
            analysis = paths.cdc_rdc
            return self.cdc.setup(
                top=paths.top, script=analysis / "extract.ys",
                design_json=analysis / "design.json", repo_root=self.context.project_root,
                filelists=(paths.rtl_common, paths.rtl_ip),
            )
        if action == "cdc":
            return self.cdc.run_from_context(self.context, inputs=inputs, on=on)
        if action.startswith("formal"):
            return self.formal.run_target(target, self.context, inputs=inputs, on=on)
        raise ValueError(f"unsupported DV action: {action!r}")

    def _run_test_target(self, action: str, *, on: str):
        """Generate or list model-owned functional vectors."""

        values, paths = self.context.values, self.context.paths
        if action == "tests_list":
            tests = self.functional.tests(paths.tests)
            print("\n".join(tests))
            return tests
        hjson = paths.csr / f"{paths.top}.hjson"
        force = self._bool(values.get("FORCE"))
        if action == "test_generate":
            return self.functional.setup_test(
                values.get("TEST_NAME", "smoke"), paths.tests, paths.top, hjson,
                force=force, on=on,
            )
        return self.functional.setup_tests(
            paths.tests, paths.top, hjson, force=force, on=on,
        )

    def _run_functional_target(self, action: str, *, on: str):
        """Run one functional-DV scaffold, simulation, regression or coverage action."""

        values, paths = self.context.values, self.context.paths
        if action in {"tb_setup", "cocotb_setup"}:
            sv, cocotb = self._testbench_configs()
            from ..signoff.sdc import read_clock_config

            clocks = read_clock_config(paths.sdc, self.context.clocks)
            if action == "tb_setup":
                return self.testbench.setup_systemverilog(sv, clocks=clocks)
            return self.testbench.setup_cocotb(cocotb, clocks=clocks)
        if action == "functional_compile":
            return self.functional.run_compile_systemverilog(
                top=paths.top, tb_dir=paths.tb, sim_dir=paths.sim / "rtl",
                common_filelist=paths.rtl_common, ip_filelist=paths.rtl_ip,
                test_name=values.get("TEST_NAME", "smoke"),
                compiler=values.get("COMPILER", "verilator"),
                coverage=self._bool(values.get("COVERAGE")),
                log=paths.logs / "dv" / "functional" / f"{paths.top}_compile.log", on=on,
            )
        if action == "functional_sim":
            test = values.get("TEST_NAME", "smoke")
            return self.functional.run_systemverilog(
                top=paths.top, test_root=paths.tests, tb_dir=paths.tb, sim_dir=paths.sim / "rtl",
                test_name=test, compiler=values.get("COMPILER", "verilator"),
                seed=int(values.get("SEED", "1")),
                log=paths.logs / "dv" / "functional" / f"{paths.top}_sim_{test}.log", on=on,
            )
        if action == "functional_cocotb":
            test = values.get("TEST_NAME", "smoke")
            return self.functional.run_cocotb(
                top=paths.top, test_root=paths.tests, tb_dir=paths.tb, rtl_sources=self._rtl_sources(),
                test_name=test, simulator=values.get("COMPILER", "verilator"),
                seed=int(values.get("SEED", "1")),
                reset_settle_cycles=int(values.get("RESET_SETTLE_CYCLES", "8")),
                waves=self._bool(values.get("COCOTB_WAVES"), True),
                log=paths.logs / "dv" / "functional" / f"{paths.top}_cocotb_{test}.log", on=on,
            )
        if action.startswith("functional_regression"):
            backends = {
                "functional_regression_sv": ("sv",),
                "functional_regression_cocotb": ("cocotb",),
            }.get(action)
            if backends is None:
                return self.functional.flow_from_context(self.context, on=on)
            return self.functional.run_regression(
                top=paths.top, test_root=paths.tests, tb_dir=paths.tb, sim_dir=paths.sim / "rtl",
                common_filelist=paths.rtl_common, ip_filelist=paths.rtl_ip,
                rtl_sources=self._rtl_sources(), compiler=values.get("COMPILER", "verilator"),
                backends=backends, seed=int(values.get("SEED", "1")),
                reset_settle_cycles=int(values.get("RESET_SETTLE_CYCLES", "8")),
                log_dir=paths.logs / "dv" / "functional", on=on,
            )
        if action in {"coverage", "coverage_detail"}:
            return self.coverage.flow_from_context(
                self.context, detail=action == "coverage_detail", on=on,
            )
        raise ValueError(f"unsupported functional DV action: {action!r}")

    @staticmethod
    def _bool(value: object, default: bool = False) -> bool:
        if value is None:
            return default
        return str(value).strip().lower() in {"1", "true", "yes", "on"}

    def _rtl_sources(self) -> tuple[Path, ...]:
        sources: list[Path] = []
        for filelist in (self.context.paths.rtl_common, self.context.paths.rtl_ip):
            if not filelist.is_file():
                continue
            for raw in filelist.read_text(encoding="utf-8").splitlines():
                item = raw.strip()
                if item and not item.startswith(("#", "+", "-")):
                    sources.append(Path(item))
        return tuple(sources)

    def _testbench_configs(self) -> tuple[TestbenchConfig, CocotbConfig]:
        values, paths = self.context.values, self.context.paths
        period = float(values.get("CLK_PERIOD", "20"))
        interface = values.get("REG_ITF", "tlul")
        io_delay_pct = float(values.get("SDC_IO_DELAY_PCT", "0.2"))
        force = self._bool(values.get("FORCE"))
        sv = TestbenchConfig(
            top=paths.top, rtldir=paths.rtl, simdir=paths.sim / "rtl", syndir=paths.syn,
            prims=tuple(part for part in values.get("PRIM", "").replace(",", " ").split() if part),
            clk_period_ns=max(1, int(period)), io_delay_pct=io_delay_pct,
            compiler=values.get("COMPILER", "verilator"), interface=interface,
            vsv=values.get("VSV", "sv"), output=paths.tb / "sv", force=force,
        )
        cocotb = CocotbConfig(
            top=paths.top, interface=interface, output=paths.tb / "cocotb", rtl_dir=paths.rtl,
            ips_root=self.context.project_root / "hw" / "ips",
            simulator=values.get("COMPILER", "verilator"), period_ns=period,
            io_delay_pct=io_delay_pct, vsv=values.get("VSV", "sv"), force=force,
        )
        return sv, cocotb

    def debug_target(self, target: Target, *, output: str | None = None) -> int:
        """List the concrete functional-DV artifacts produced by one target."""

        paths = self.context.paths
        roots = (
            (paths.logs / "dv" / "functional", paths.sim, paths.tb / "cocotb", paths.coverage)
            if target.debug == "functional"
            else (paths.coverage, paths.logs / "dv" / "functional" / "coverage")
        )
        artifact_suffixes = {".dat", ".fst", ".json", ".log", ".txt", ".vcd"}
        files = tuple(sorted(
            path for root in roots if root.exists()
            for path in root.rglob("*")
            if path.is_file() and path.suffix.lower() in artifact_suffixes
        ))
        lines = [f"{target.name} debug artifacts"] + [str(path) for path in files]
        text = "\n".join(lines) + "\n"
        if output:
            destination = Path(output)
            if not destination.is_absolute():
                destination = self.context.project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(text, encoding="utf-8")
        print(text, end="")
        return 0 if files else 1

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
        """Run every supported focused lint class and refresh compact QoR."""
        results = tuple(
            self._lint(tool, kind=kind, part=part, on=on)
            for tool in tools
            for kind in ("all", "latch", "undriven", "width", "unconnected", "unused")
        )
        from ..core.reporting import collect_lint

        summary = collect_lint(self.context.paths.top, self.context.paths.run)
        if summary:
            for values in summary.get("tools", {}).values():
                values.pop("command", None)
                values.pop("log", None)
            path = self.context.paths.lint / "summary.json"
            path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return results

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

        analysis_dir = paths.lint / tool
        logdir = paths.logs / "dv" / "lint" / tool
        raw = logdir / "raw" / f"{paths.top}_lint_{tool}_{kind}_raw.log"
        full = analysis_dir / f"{paths.top}_lint_{tool}_{kind}.log"
        raw.parent.mkdir(parents=True, exist_ok=True)
        full.parent.mkdir(parents=True, exist_ok=True)
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
