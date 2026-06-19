"""Public API layer for FlexSoC.

This module is the stable boundary used by future CLI, web, and frontend code.
"""

from __future__ import annotations

import os
import subprocess
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any


@dataclass(frozen=True, slots=True)
class FlowResult:
    """Result returned after executing one backend flow step.

    The object keeps subprocess details small and stable for CLI or web callers.
    """

    command: "FlowCommand"
    returncode: int
    stdout: str | None = None
    stderr: str | None = None

    @property
    def ok(self) -> bool:
        """Return True when the executed command completed successfully."""

        return self.returncode == 0

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-ready result for CLI, frontend, or service callers."""

        return {
            "ok": self.ok,
            "returncode": self.returncode,
            "command": self.command.to_dict(),
            "stdout": self.stdout,
            "stderr": self.stderr,
        }


@dataclass(slots=True)
class FlexSoCConfig:
    """Configuration object shared by workflow and step calls.

    Extra values keep the first API thin while backend contracts are stabilized.
    """

    project_root: Path | None = None
    workdir: Path | None = None
    options: dict[str, Any] = field(default_factory=dict)

    @classmethod
    def from_values(cls, config: "FlexSoCConfig | None" = None, **overrides: Any) -> "FlexSoCConfig":
        """Build a config from an optional object plus keyword overrides."""

        base = config or cls()
        project_root = overrides.pop("project_root", base.project_root)
        workdir = overrides.pop("workdir", base.workdir)
        options = dict(base.options)
        options.update(overrides.pop("options", {}) or {})
        options.update(overrides)
        return cls(project_root=project_root, workdir=workdir, options=options)


@dataclass(frozen=True, slots=True)
class FlowParameter:
    """Document one Make variable accepted by a flow step.

    Parameters are exposed to CLI, web, and UI layers through the public API.
    """

    name: str
    description: str
    default: str | None = None
    required: bool = False

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-ready parameter description for frontend callers."""

        return {
            "name": self.name,
            "description": self.description,
            "default": self.default,
            "required": self.required,
        }


@dataclass(frozen=True, slots=True)
class FlowStep:
    """Public description for one Make-backed workflow step."""

    name: str
    group: str
    description: str
    params: tuple[FlowParameter, ...] = ()

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-ready step description for CLI and UI callers."""

        return {
            "name": self.name,
            "group": self.group,
            "description": self.description,
            "params": [param.to_dict() for param in self.params],
        }


@dataclass(frozen=True, slots=True)
class FlowWorkflow:
    """Public high-level workflow that maps to one or more advanced steps."""

    name: str
    steps: tuple[str, ...]
    description: str

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-ready workflow description for CLI and UI callers."""

        return {"name": self.name, "steps": list(self.steps), "description": self.description}


@dataclass(frozen=True, slots=True)
class FlowPlan:
    """Preview for a high-level workflow resolved into backend commands."""

    name: str
    commands: tuple["FlowCommand", ...]

    def shell_lines(self) -> tuple[str, ...]:
        """Return one shell-ready command preview per workflow step."""

        return tuple(command.shell_line() for command in self.commands)

    def shell_script(self) -> str:
        """Return a compact shell script preview for reproducible workflow runs."""

        lines = ["#!/usr/bin/env bash", "set -euo pipefail", *self.shell_lines()]
        return "\n".join(lines) + "\n"

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-ready workflow preview for CLI and UI callers."""

        return {
            "name": self.name,
            "commands": [command.to_dict() for command in self.commands],
            "shell": list(self.shell_lines()),
        }


@dataclass(frozen=True, slots=True)
class FlowRequest:
    """Normalized request for one API-triggered backend flow step."""

    target: str
    make_vars: dict[str, str]

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-ready request for UI and CLI previews."""

        return {"target": self.target, "make_vars": dict(self.make_vars)}


@dataclass(frozen=True, slots=True)
class FlowCommand:
    """Command description for one Make-backed FlexSoC workflow step."""

    argv: tuple[str, ...]
    cwd: Path
    env: dict[str, str]
    request: FlowRequest

    def shell_line(self) -> str:
        """Return a readable command preview for CLI and frontend integrations."""

        return " ".join(self.argv)

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-ready command preview without subprocess internals."""

        return {
            "argv": list(self.argv),
            "cwd": str(self.cwd),
            "env": {"PYTHONPATH": self.env.get("PYTHONPATH", "")},
            "request": self.request.to_dict(),
            "shell": self.shell_line(),
        }


class FlexSoC:
    """Thin public client for FlexSoC workflows and advanced backend steps."""

    def __init__(self, config: FlexSoCConfig | None = None, **overrides: Any) -> None:
        """Create a client and normalize user-provided configuration values."""

        self.config = FlexSoCConfig.from_values(config, **overrides)

    def describe(self) -> dict[str, Any]:
        """Return a small, testable description of the configured API client."""

        return {
            "package": "flexsoc",
            "api": "FlexSoC",
            "project_root": str(self.project_root),
            "workdir": str(self.workdir),
            "options": dict(self.config.options),
        }

    @property
    def project_root(self) -> Path:
        """Return the repository root used as default execution directory."""

        return (self.config.project_root or Path.cwd()).resolve()

    @property
    def workdir(self) -> Path:
        """Return the workspace directory passed to Make-backed flow steps."""

        return (self.config.workdir or self.project_root / "workspace").resolve()

    def list_workflows(self) -> tuple[FlowWorkflow, ...]:
        """List stable high-level workflows exposed by the public API."""

        return self._workflows()

    def workflow_names(self) -> tuple[str, ...]:
        """Return only workflow names for compact CLI and frontend menus."""

        return tuple(workflow.name for workflow in self.list_workflows())

    def prepare_workflow(self, name: str) -> tuple[str, ...]:
        """Resolve one high-level workflow name into advanced backend steps."""

        return self._workflow_by_name(name).steps

    def inspect_workflow(
        self,
        name: str,
        config: FlexSoCConfig | None = None,
        **overrides: Any,
    ) -> FlowPlan:
        """Preview one high-level workflow without executing backend commands."""

        commands = tuple(
            self.flow_command(step, config, **overrides)
            for step in self.prepare_workflow(name)
        )
        return FlowPlan(name=name, commands=commands)

    def run_workflow(
        self,
        name: str,
        config: FlexSoCConfig | None = None,
        *,
        check: bool = True,
        dry_run: bool = False,
        capture: bool = False,
        **overrides: Any,
    ) -> tuple[FlowCommand | FlowResult, ...]:
        """Run or preview a high-level workflow through the same step API."""

        if dry_run:
            return self.inspect_workflow(name, config, **overrides).commands
        return tuple(
            self.run_step(
                step,
                config,
                check=check,
                capture=capture,
                **overrides,
            )
            for step in self.prepare_workflow(name)
        )

    def list_steps(self, group: str | None = None) -> tuple[FlowStep, ...]:
        """List available Make-backed workflow steps exposed through the API."""

        steps = tuple(sorted(self._discover_flow_steps(), key=lambda step: (step.group, step.name)))
        if group is None:
            return steps
        return tuple(step for step in steps if step.group == group)

    def step_names(self, group: str | None = None) -> tuple[str, ...]:
        """Return only the step names for compact API and CLI output."""

        return tuple(step.name for step in self.list_steps(group))

    def step_info(self, name: str) -> FlowStep:
        """Return one documented step or fail with a clear API error."""

        for step in self.list_steps():
            if step.name == name:
                return step
        raise ValueError(f"unknown step: {name}")

    def prepare_step(
        self,
        target: str,
        config: FlexSoCConfig | None = None,
        **overrides: Any,
    ) -> FlowRequest:
        """Normalize one backend step request before command creation or execution."""

        values = self._flow_values(config, overrides)
        return FlowRequest(target=target, make_vars=values)

    def flow_command(
        self,
        target: str,
        config: FlexSoCConfig | None = None,
        **overrides: Any,
    ) -> FlowCommand:
        """Build the command line for a Make-backed workflow step without running it."""

        request = self.prepare_step(target, config, **overrides)
        argv = ["make", "-f", str(self._flow_makefile()), request.target]
        argv.extend(f"{key}={value}" for key, value in request.make_vars.items())
        return FlowCommand(tuple(argv), self.project_root, self._flow_env(), request)

    def inspect_step(
        self,
        target: str,
        config: FlexSoCConfig | None = None,
        **overrides: Any,
    ) -> dict[str, Any]:
        """Return a JSON-ready preview of one backend step without executing it."""

        return self.flow_command(target, config, **overrides).to_dict()

    def run_step(
        self,
        target: str,
        config: FlexSoCConfig | None = None,
        *,
        check: bool = True,
        dry_run: bool = False,
        capture: bool = False,
        **overrides: Any,
    ) -> FlowCommand | FlowResult:
        """Run or preview one advanced flow step through the API boundary."""

        command = self.flow_command(target, config, **overrides)
        if dry_run:
            return command
        completed = subprocess.run(
            command.argv,
            cwd=command.cwd,
            env=command.env,
            check=check,
            capture_output=capture,
            text=capture,
        )
        return FlowResult(
            command=command,
            returncode=completed.returncode,
            stdout=completed.stdout if capture else None,
            stderr=completed.stderr if capture else None,
        )

    def _flow_values(
        self,
        config: FlexSoCConfig | None,
        overrides: dict[str, Any],
    ) -> dict[str, str]:
        """Merge client, call config, and call-specific Make variable overrides."""

        local = FlexSoCConfig.from_values(config) if config else FlexSoCConfig()
        merged = {**self.config.options, **local.options, **overrides, "WORKSPACE": self.workdir}
        return {str(key).upper(): str(value) for key, value in merged.items() if value is not None}

    def _flow_env(self) -> dict[str, str]:
        """Create a subprocess environment that can import the local package."""

        env = os.environ.copy()
        src = str(self.project_root / "src")
        env["PYTHONPATH"] = src + (os.pathsep + env["PYTHONPATH"] if env.get("PYTHONPATH") else "")
        return env

    def _workflow_by_name(self, name: str) -> FlowWorkflow:
        """Return one workflow description or fail with a clear API error."""

        for workflow in self._workflows():
            if workflow.name == name:
                return workflow
        raise ValueError(f"unknown workflow: {name}")

    @staticmethod
    def _workflows() -> tuple[FlowWorkflow, ...]:
        """Return the small public workflow catalog backed by advanced steps."""

        return (
            FlowWorkflow("prepare", ("setup",), "Prepare a FlexSoC workspace."),
            FlowWorkflow("soc", ("soc",), "Generate or refresh the SoC project."),
            FlowWorkflow("fsm", ("fsm_gen",), "Run the bundled FSM generator utility."),
            FlowWorkflow(
                "soc_development",
                ("setup", "soc_start", "soc_flow", "soc_prepare", "soc_build_sw", "soc_sim", "soc_run"),
                "Run the explicit SoC development flow from IP loading to software-backed simulation.",
            ),
            FlowWorkflow(
                "ip_development",
                (
                    "setup",
                    "hjson_gen",
                    "reg",
                    "doc",
                    "rtl_stub",
                    "setup_tb",
                    "sim",
                    "syn",
                    "sta",
                    "power",
                    "pnr",
                    "sim_syn",
                    "cocotb",
                ),
                "Run the explicit IP development flow from templates to simulation, synthesis, signoff, and PnR.",
            ),
        )

    @classmethod
    def _discover_flow_steps(cls) -> set[FlowStep]:
        """Return the documented flow step catalog exposed by the API."""

        return set(cls._step_catalog())

    @staticmethod
    def _common_params() -> tuple[FlowParameter, ...]:
        """Return variables shared by most flow steps."""

        return (
            FlowParameter("TOP", "IP or SoC top-level name.", "test", True),
            FlowParameter("RUN_ID", "Run identifier under the workspace.", "timestamp", True),
            FlowParameter("WORKSPACE", "Workspace root used for generated artifacts.", "workspace"),
            FlowParameter("RUN_TOP", "Run namespace; defaults to TOP when omitted.", "TOP"),
            FlowParameter("FORCE", "Overwrite generated files when set to 1.", "0"),
        )

    @classmethod
    def _step(cls, name: str, group: str, description: str, *params: FlowParameter) -> FlowStep:
        """Build one catalog entry with common variables plus step variables."""

        names = {param.name for param in params}
        common = tuple(param for param in cls._common_params() if param.name not in names)
        return FlowStep(name, group, description, common + params)

    @classmethod
    def _step_catalog(cls) -> tuple[FlowStep, ...]:
        """Return the explicit step catalog used by help, CLI, and UI layers."""

        p = cls._params()
        return (
            cls._step("setup", "setup", "Create the run directory tree and common output folders."),
            cls._step("setup_tb", "setup", "Create the SystemVerilog testbench template.", p["COMPILER"]),
            cls._step("setup_cocotb", "setup", "Create a Cocotb testbench scaffold."),
            cls._step("setup_model", "setup", "Create a lightweight software model scaffold."),
            cls._step("setup_sdc", "setup", "Create timing constraint files.", p["CLK_PERIOD"]),
            cls._step("setup_syn", "setup", "Create synthesis scripts.", p["TARGET_SYN"], p["TARGET_OPT"]),
            cls._step("setup_signoff", "setup", "Create signoff scripts.", p["LIBS"], p["ACTIVITY"]),
            cls._step("setup_pnr", "setup", "Create OpenROAD configuration.", p["ORS_TECH"]),
            cls._step("hjson", "ip", "Create the initial IP HJSON description.", p["REG_ITF"]),
            cls._step("hjson_gen", "ip", "Create the initial IP HJSON description.", p["REG_ITF"]),
            cls._step("reg", "ip", "Generate register RTL from the HJSON description.", p["REG_ITF"]),
            cls._step("doc", "ip", "Generate register documentation from the IP description."),
            cls._step("rtl_stub", "ip", "Generate core and wrapper RTL stubs for the IP.", p["REG_ITF"]),
            cls._step("ip_start", "ip", "Run setup, HJSON, reg, docs, RTL stub, filelist, TB, and simulation."),
            cls._step("soc_start", "ip", "Load generated IP bundles into a SoC run."),
            cls._step("flist", "ip", "Generate the RTL filelist consumed by downstream tools."),
            cls._step("driver", "ip", "Generate software driver files from the HJSON description.", p["MOD_ADD"]),
            cls._step("fetch", "ip", "Update one vendored dependency description.", p["VENDOR"]),
            cls._step("ip_load", "ip", "Load an IP bundle into the workspace.", p["IP_NAME"]),
            cls._step("ip_save", "ip", "Save generated IP artifacts as a reusable bundle.", p["IP_NAME"]),
            cls._step("ip_flow", "ip", "Run the standard IP implementation flow."),
            cls._step("ip_flow_noreg", "ip", "Run the IP flow from an existing register description."),
            cls._step("ip_flow_all", "ip", "Run generation, signoff, and PnR for one IP."),
            cls._step("lint", "simulation", "Run lint according to the selected RTL flavor.", p["VSV"], p["LINTER"]),
            cls._step("lint_v", "simulation", "Run Verilog lint.", p["LINTER"]),
            cls._step("lint_sv", "simulation", "Run SystemVerilog lint.", p["LINTER"]),
            cls._step("sv2v", "simulation", "Convert SystemVerilog sources to Verilog."),
            cls._step("compile", "simulation", "Compile simulation according to the selected RTL flavor.", p["VSV"], p["COMPILER"]),
            cls._step("compile_v", "simulation", "Compile Verilog simulation.", p["COMPILER"]),
            cls._step("compile_sv", "simulation", "Compile SystemVerilog simulation.", p["COMPILER"]),
            cls._step("sim", "simulation", "Compile and run RTL simulation.", p["VSV"], p["COMPILER"]),
            cls._step("sim_v", "simulation", "Run Verilog simulation.", p["COMPILER"]),
            cls._step("sim_sv", "simulation", "Run SystemVerilog simulation.", p["COMPILER"]),
            cls._step("compile_syn", "simulation", "Compile post-synthesis simulation.", p["COMPILER"]),
            cls._step("sim_syn", "simulation", "Run post-synthesis simulation using generated SDF.", p["COMPILER"]),
            cls._step("cocotb", "simulation", "Run the Cocotb testbench for the selected top-level."),
            cls._step("tb_save", "simulation", "Save the current testbench as a reusable artifact."),
            cls._step("tb_view", "simulation", "Open the testbench waveform view."),
            cls._step("syn", "implementation", "Run synthesis for the selected top-level.", p["TARGET_SYN"], p["TARGET_OPT"], p["VSV"]),
            cls._step("syn_v", "implementation", "Run Verilog synthesis.", p["TARGET_SYN"], p["TARGET_OPT"]),
            cls._step("syn_sv", "implementation", "Run SystemVerilog synthesis.", p["TARGET_SYN"], p["TARGET_OPT"]),
            cls._step("yosys-vgen", "implementation", "Export Verilog from the synthesis database."),
            cls._step("plot_postsyn", "implementation", "Plot the post-synthesis netlist."),
            cls._step("view_presyn", "implementation", "Open the pre-synthesis schematic view.", p["VSV"]),
            cls._step("view_presyn_v", "implementation", "Open the Verilog pre-synthesis schematic view."),
            cls._step("view_presyn_sv", "implementation", "Open the SystemVerilog pre-synthesis schematic view."),
            cls._step("sta", "signoff", "Run static timing analysis on synthesized output.", p["LIBS"]),
            cls._step("sdf", "signoff", "Generate SDF timing data.", p["LIBS"]),
            cls._step("power", "signoff", "Run power analysis using generated signoff scripts.", p["ACTIVITY"]),
            cls._step("sta_violators", "signoff", "Report the worst timing violators.", p["NPATHS"]),
            cls._step("path_view", "signoff", "Open a timing path view.", p["PATH_VIEW_FILE"]),
            cls._step("pnr", "implementation", "Run place-and-route using the configured OpenROAD flow.", p["ORS_TECH"]),
            cls._step("pnr_gui", "implementation", "Open the OpenROAD GUI for the current run.", p["ORS_TECH"]),
            cls._step("view", "view", "Open the default RTL simulation waveform.", p["VIEWER"]),
            cls._step("view_cocotb", "view", "Open Cocotb waveform output.", p["VIEWER"]),
            cls._step("view_syn", "view", "Open post-synthesis waveform output.", p["VIEWER"]),
            cls._step("soc_cfg", "soc", "Generate SoC configuration for the current run.", p["HOST"], p["SOC_CFG_MODE"]),
            cls._step("fsoc_init", "soc", "Generate a run-local FuseSoC core.", p["HOST"], p["PRJ"]),
            cls._step("fsoc", "soc", "Run FuseSoC for the configured target.", p["TARGET_FSOC"], p["FUSESOC_TOOL"]),
            cls._step("xbar", "soc", "Generate and build the SoC crossbar.", p["HOST"], p["SOC_CFG_MODE"]),
            cls._step("xbar_init", "soc", "Generate crossbar inputs for the current SoC."),
            cls._step("xbar_build", "soc", "Build generated crossbar RTL."),
            cls._step("soc", "soc", "Generate or refresh the SoC top-level RTL.", p["HOST"]),
            cls._step("soc_stage_tops", "soc", "Stage IP tops into the SoC run."),
            cls._step("soc_flist", "soc", "Generate the SoC RTL filelist."),
            cls._step("soc_flow", "soc", "Run crossbar, SoC generation, and SoC filelist generation.", p["HOST"]),
            cls._step("soc_uart_gen", "soc", "Generate a UART-hosted SoC."),
            cls._step("soc_ibex_gen", "soc", "Generate an Ibex-hosted SoC."),
            cls._step("sw_soc", "soc", "Generate SoC software support files."),
            cls._step("soc_prepare", "soc", "Prepare SoC software build inputs."),
            cls._step("soc_build_sw", "soc", "Build SoC software."),
            cls._step("soc_sim", "soc", "Run SoC simulation."),
            cls._step("soc_run", "soc", "Run the generated SoC executable."),
            cls._step("soc_run_only", "soc", "Run the SoC executable without rebuilding."),
            cls._step("soc_view", "soc", "Open SoC waveform output.", p["VIEWER"]),
            cls._step("soc_uart_tutorial", "tutorial", "Run the UART SoC tutorial."),
            cls._step("soc_ibex_fetch", "tutorial", "Fetch or prepare Ibex SoC tutorial inputs."),
            cls._step("soc_ibex_tutorial", "tutorial", "Run the Ibex SoC tutorial."),
            cls._step("fsm_init", "fsm", "Create FSM input and output directories.", p["FSM"]),
            cls._step("fsm_example_load", "fsm", "Load the bundled FSM example.", p["FSM"]),
            cls._step("fsm_setup", "fsm", "Prepare the bundled FSM generator.", p["FSM"]),
            cls._step("fsm_gen", "fsm", "Run the bundled FSM generator.", p["FSM"], p["F_CLK"]),
            cls._step("fsm_plot", "fsm", "Render FSM plots.", p["FSM"]),
            cls._step("fsm_flow", "fsm", "Generate and plot one FSM.", p["FSM"], p["F_CLK"]),
            cls._step("fsm_install", "fsm", "Install generated FSM artifacts into the IP run.", p["FSM"]),
            cls._step("deps", "environment", "Install IP development dependencies."),
            cls._step("deps-soc", "environment", "Install SoC development dependencies."),
            cls._step("help", "help", "Show the backend Make help."),
            cls._step("help_ip", "help", "Show IP flow help."),
            cls._step("help_soc", "help", "Show SoC flow help."),
            cls._step("help_doc", "help", "Show documentation flow help."),
            cls._step("help_fsm", "help", "Show FSM flow help."),
            cls._step("clean-pyc", "clean", "Remove Python caches."),
            cls._step("clean_doc", "clean", "Remove generated documentation."),
            cls._step("clean_log", "clean", "Remove generated logs."),
            cls._step("clean_rtl", "clean", "Remove generated RTL outputs."),
            cls._step("clean_sim", "clean", "Remove simulation outputs."),
            cls._step("clean_cocotb", "clean", "Remove Cocotb outputs."),
            cls._step("clean_syn", "clean", "Remove synthesis outputs."),
            cls._step("clean_signoff", "clean", "Remove signoff outputs."),
            cls._step("clean_pnr", "clean", "Remove PnR outputs."),
            cls._step("clean_fsm", "clean", "Remove generated FSM artifacts."),
            cls._step("clean_fsm_all", "clean", "Remove all FSM working files."),
            cls._step("clean_agent", "clean", "Remove agent-generated files."),
            cls._step("clean_fsoc", "clean", "Remove FuseSoC outputs."),
            cls._step("clean_soc", "clean", "Remove SoC outputs."),
            cls._step("clean_sw", "clean", "Remove generated software outputs."),
            cls._step("clean_vendor", "clean", "Remove vendored dependency outputs."),
            cls._step("clean_subdir", "clean", "Run clean in generated subdirectories."),
            cls._step("clean", "clean", "Clean generated run artifacts but keep vendored sources."),
            cls._step("clean_all", "clean", "Clean generated artifacts, FSM cache, vendor cache, and agents."),
            cls._step("full_tutorial", "tutorial", "Run the full tutorial flow."),
            cls._step("fsm_tutorial", "tutorial", "Run the FSM tutorial flow."),
            cls._step("ip_tutorial", "tutorial", "Run the IP tutorial flow."),
            cls._step("soc_pless", "tutorial", "Run the P-less SoC tutorial flow."),
        )

    @staticmethod
    def _params() -> dict[str, FlowParameter]:
        """Return reusable step parameter descriptions keyed by Make variable."""

        return {
            "ACTIVITY": FlowParameter("ACTIVITY", "Default switching activity percentage.", "10"),
            "CLK_PERIOD": FlowParameter("CLK_PERIOD", "Clock period used for constraints, in ns.", "20"),
            "COMPILER": FlowParameter("COMPILER", "Simulator compiler command.", "verilator"),
            "F_CLK": FlowParameter("F_CLK", "FSM generator clock frequency value.", "32"),
            "FSM": FlowParameter("FSM", "FSM name to generate or install.", "fsm_example", True),
            "FUSESOC_TOOL": FlowParameter("FUSESOC_TOOL", "FuseSoC backend tool override."),
            "HOST": FlowParameter("HOST", "SoC host wrapper selection.", "uart"),
            "IP_NAME": FlowParameter("IP_NAME", "IP bundle name used by load/save steps.", "TOP"),
            "LIBS": FlowParameter("LIBS", "Timing liberty files used by OpenSTA."),
            "LINTER": FlowParameter("LINTER", "RTL linter command.", "verilator"),
            "MOD_ADD": FlowParameter("MOD_ADD", "Driver base address value.", "0x80000000"),
            "NPATHS": FlowParameter("NPATHS", "Number of timing paths to report.", "20"),
            "ORS_TECH": FlowParameter("ORS_TECH", "OpenROAD technology name.", "sky130hd"),
            "PATH_VIEW_FILE": FlowParameter("PATH_VIEW_FILE", "Timing report file to inspect."),
            "PRJ": FlowParameter("PRJ", "Project/vendor prefix for generated FuseSoC cores.", "prj"),
            "REG_ITF": FlowParameter("REG_ITF", "Register bus interface for generated wrappers.", "tlul"),
            "SOC_CFG_MODE": FlowParameter("SOC_CFG_MODE", "SoC configuration source mode.", "auto"),
            "TARGET_FSOC": FlowParameter("TARGET_FSOC", "FuseSoC target to run.", "lint"),
            "TARGET_OPT": FlowParameter("TARGET_OPT", "Synthesis optimization goal.", "area"),
            "TARGET_SYN": FlowParameter("TARGET_SYN", "Synthesis target style.", "asic"),
            "VENDOR": FlowParameter("VENDOR", "Vendor manifest name to update.", "lowrisc_ip"),
            "VIEWER": FlowParameter("VIEWER", "Waveform viewer command.", "gtkwave"),
            "VSV": FlowParameter("VSV", "RTL flavor selector: v or sv.", "sv"),
        }

    @staticmethod
    def _flow_makefile() -> Path:
        """Return the packaged Make entrypoint used by flow targets."""

        return Path(__file__).with_name("backend") / "Makefile"
