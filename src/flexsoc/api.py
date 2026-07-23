"""Small FlexSoC Python API for launching backend Make targets."""

from __future__ import annotations

import os
import shlex
import subprocess
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping


# ---------------------------------------------------------------------------
# Configuration data
# ---------------------------------------------------------------------------

PathLike = str | os.PathLike[str] | Path | None
TargetSpec = tuple[str, str, tuple[str, ...]]
DEFAULT_SETTINGS = {"TOP": "test", "HOST": "uart", "FORCE": "0", "RUN_ID": "default"}

# Parameter bundles keep the target table compact; every value is still overrideable.
NONE = ()
BASE = ("TOP", "RUN_ID", "WORKSPACE")
COMMON = (*BASE, "RUN_TOP", "FORCE")
IP_DEV = (*BASE, "REG_ITF", "FORCE")
FETCH = (*BASE, "VENDOR", "TARGET", "FORCE")
IP_FULL = (*COMMON, "REG_ITF", "LINT_TOOL", "LINT_PART", "TARGET_SYN", "TARGET_OPT")
LINT = (*COMMON, "LINT_TOOL", "LINT_PART", "VSV")
SIM = (*COMMON, "TESTBENCH", "TEST_NAMES", "TEST_NAME", "REGCFG", "DATA_IN", "DATA_OUT", "VSV", "COMPILER", "COCOTB_WAVES")
VIEW = (*COMMON, "WAVE_VIEWER", "SURFER_BACKEND")
SYN = (*COMMON, "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT", "VSV")
SIGNOFF = (*COMMON, "LIBS", "ACTIVITY", "PATH_VIEW_FILE", "NPATHS")
PNR = (*COMMON, "ORS", "ORS_TECH")
IP_LOAD = (*COMMON, "IP_NAME")
SOC = (*COMMON, "HOST", "SOC_CFG_MODE", "DEVLIST")
FSM = (*BASE, "FSM", "FORCE")
TUTORIAL = ("TUTORIAL_WS", "TUTORIAL_RUN_ID", *COMMON)
CLEAN = (*BASE, "RUN_TOP")


# ---------------------------------------------------------------------------
# Make targets: one row per callable backend target
# ---------------------------------------------------------------------------

TARGETS: dict[str, TargetSpec] = {
    "help": ("Help", "Show backend target help", NONE),
    "help_ip": ("Help", "Show IP-flow help", NONE),
    "help_soc": ("Help", "Show SoC-flow help", NONE),
    "help_doc": ("Help", "Show documentation-flow help", NONE),
    "help_fsm": ("Help", "Show FSM-flow help", NONE),
    "setup": ("Setup", "Create the run directory tree", BASE),
    "soc_cfg": ("Setup", "Render SoC configuration variables", SOC),
    "soc_start": ("Setup", "Initialize a SoC run from loaded IPs", SOC),
    "hjson": ("IP flow", "Generate an HJSON register template", IP_DEV),
    "hjson_gen": ("IP flow", "Compatibility alias for HJSON generation", IP_DEV),
    "reg": ("IP flow", "Generate register RTL from HJSON", IP_DEV),
    "doc": ("IP flow", "Generate register documentation", IP_DEV),
    "rtl_stub": ("IP flow", "Generate RTL core and aligned top wrapper", IP_DEV),
    "top_from_core": ("IP flow", "Regenerate top wrapper from edited core ports", IP_DEV),
    "flist": ("IP flow", "Generate the RTL filelist", IP_DEV),
    "flist_split": ("IP flow", "Split common and IP RTL filelists", IP_DEV),
    "driver": ("IP flow", "Generate C driver files from HJSON", IP_DEV),
    "fetch": ("IP flow", "Fetch or update a vendored dependency", FETCH),
    "ip_start": ("IP flow", "Bootstrap a complete IP run", IP_FULL),
    "ip_flow": ("IP flow", "Run the standard IP flow", IP_FULL),
    "ip_flow_noreg": ("IP flow", "Run IP flow without regenerating registers", IP_DEV),
    "ip_flow_all": ("IP flow", "Run full IP flow including PnR", IP_FULL),
    "lint": ("Linting", "Run HDL lint checks", LINT),
    "lint_v": ("Linting", "Run Verilog lint checks", LINT),
    "lint_sv": ("Linting", "Run SystemVerilog lint checks", LINT),
    "lint_latch": ("Linting", "Run latch-focused HDL lint diagnostics", LINT),
    "lint_undriven": ("Linting", "Run undriven-signal HDL lint diagnostics", LINT),
    "lint_width": ("Linting", "Run width-focused HDL lint diagnostics", LINT),
    "lint_unconnected": ("Linting", "Run unconnected-port HDL lint diagnostics", LINT),
    "lint_unused": ("Linting", "Run unused-object HDL lint diagnostics", LINT),
    "_lint_run": ("Linting", "Internal lint dispatcher", LINT),
    "slang_hier": ("Linting", "Print hierarchy with slang-hier", LINT),
    "setup_tb": ("Simulation", "Generate a SystemVerilog testbench", SIM),
    "setup_cocotb": ("Simulation", "Generate a cocotb scaffold", SIM),
    "setup_model": ("Simulation", "Generate a Python model scaffold", SIM),
    "tests": ("Simulation", "List generated vector tests", SIM),
    "compile": ("Simulation", "Compile the current testbench", SIM),
    "compile_v": ("Simulation", "Compile Verilog simulation", SIM),
    "compile_sv": ("Simulation", "Compile SystemVerilog simulation", SIM),
    "sim": ("Simulation", "Run simulation", SIM),
    "sim_v": ("Simulation", "Run Verilog simulation", SIM),
    "sim_sv": ("Simulation", "Run SystemVerilog simulation", SIM),
    "sim_tests": ("Simulation", "Run every generated SystemVerilog vector test", SIM),
    "cocotb": ("Simulation", "Run cocotb tests", SIM),
    "cocotb_tests": ("Simulation", "Run every generated cocotb vector test", SIM),
    "view": ("Viewing", "Open latest waveform", VIEW),
    "view_cocotb": ("Viewing", "Open latest cocotb waveform", VIEW),
    "view_syn": ("Viewing", "Reserved synthesis waveform viewer target", VIEW),
    "plot_postsyn": ("Viewing", "Open post-synthesis graph", VIEW),
    "view_presyn": ("Viewing", "Open pre-synthesis graph", VIEW),
    "view_presyn_v": ("Viewing", "Open pre-synthesis graph from Verilog", VIEW),
    "view_presyn_sv": ("Viewing", "Open pre-synthesis graph from SV", VIEW),
    "tb_save": ("Viewing", "Save testbench regression artifacts", VIEW),
    "tb_view": ("Viewing", "Open saved testbench waveform", VIEW),
    "setup_sdc": ("Synthesis", "Generate timing constraints", SYN),
    "setup_syn": ("Synthesis", "Generate Yosys synthesis scripts", SYN),
    "syn": ("Synthesis", "Run synthesis", SYN),
    "syn_v": ("Synthesis", "Run Verilog synthesis", SYN),
    "syn_sv": ("Synthesis", "Run SystemVerilog synthesis", SYN),
    "yosys-vgen": ("Synthesis", "Convert SV to Verilog with Yosys", SYN),
    "sv2v": ("Synthesis", "Convert SV to Verilog with sv2v", SYN),
    "setup_signoff": ("Signoff", "Generate signoff scripts", SIGNOFF),
    "compile_syn": ("Signoff", "Compile post-synthesis simulation", SIGNOFF),
    "sim_syn": ("Signoff", "Run post-synthesis simulation", SIGNOFF),
    "sta": ("Signoff", "Run static timing analysis", SIGNOFF),
    "sdf": ("Signoff", "Write SDF timing files", SIGNOFF),
    "power": ("Signoff", "Run power analysis", SIGNOFF),
    "sta_violators": ("Signoff", "Report timing violators", SIGNOFF),
    "path_view": ("Signoff", "Build interactive STA path view", SIGNOFF),
    "setup_pnr": ("Place and route", "Generate OpenROAD config", PNR),
    "pnr": ("Place and route", "Run OpenROAD place and route", PNR),
    "pnr_gui": ("Place and route", "Open OpenROAD GUI", PNR),
    "ip_load": ("IP load/save", "Load an IP into a run workspace", IP_LOAD),
    "ip_save": ("IP load/save", "Save run artifacts back to hw/ips", IP_LOAD),
    "soc_vendor_deps": (
        "SoC flow",
        "Fetch pinned lowRISC dependencies required by SoC simulation",
        SOC,
    ),
    "fsoc_init": ("SoC flow", "Initialize FuseSoC metadata", SOC),
    "fsoc": ("SoC flow", "Generate FuseSoC core file", SOC),
    "xbar": ("SoC flow", "Generate crossbar artifacts", SOC),
    "xbar_init": ("SoC flow", "Generate crossbar input config", SOC),
    "xbar_build": ("SoC flow", "Run tlgen for crossbar RTL", SOC),
    "soc": ("SoC flow", "Generate SoC RTL", SOC),
    "soc_stage_tops": ("SoC flow", "Stage SoC top-level files", SOC),
    "soc_flist": ("SoC flow", "Generate SoC filelist", SOC),
    "soc_flow": ("SoC flow", "Generate crossbar, SoC RTL and filelist", SOC),
    "soc_uart_gen": ("SoC flow", "Generate UART-host SoC artifacts", SOC),
    "soc_ibex_gen": ("SoC flow", "Generate Ibex-host SoC artifacts", SOC),
    "sw_soc": ("SoC flow", "Generate SoC software scaffold", SOC),
    "soc_prepare": ("SoC flow", "Prepare SoC build directory", SOC),
    "soc_build_sw": ("SoC flow", "Build SoC software", SOC),
    "soc_sim": ("SoC flow", "Build SoC simulator", SOC),
    "soc_run": ("SoC flow", "Run SoC simulation", SOC),
    "soc_run_only": ("SoC flow", "Alias for SoC simulation run", SOC),
    "soc_view": ("SoC flow", "Open SoC waveform", SOC),
    "fsm_init": ("FSM flow", "Create FSM workspace directories", FSM),
    "fsm_setup": ("FSM flow", "Set up the FSM generator", FSM),
    "fsm_example_load": ("FSM flow", "Load the FSM example inputs", FSM),
    "fsm_gen": ("FSM flow", "Generate FSM RTL", FSM),
    "fsm_plot": ("FSM flow", "Plot FSM diagrams", FSM),
    "fsm_flow": ("FSM flow", "Generate and plot FSM artifacts", FSM),
    "fsm_install": ("FSM flow", "Install FSM artifacts into the IP run", FSM),
    "fsm2rtl": ("FSM flow", "Alias for FSM RTL installation", FSM),
    "soc_uart_tutorial": ("Tutorials", "Run UART-host SoC tutorial", TUTORIAL),
    "soc_ibex_fetch": ("Tutorials", "Fetch Ibex tutorial dependencies", TUTORIAL),
    "soc_ibex_tutorial": ("Tutorials", "Run Ibex-host SoC tutorial", TUTORIAL),
    "full_tutorial": ("Tutorials", "Run the full IP tutorial flow", TUTORIAL),
    "fsm_tutorial": ("Tutorials", "Run the FSM tutorial flow", TUTORIAL),
    "ip_tutorial": ("Tutorials", "Run the IP tutorial flow", TUTORIAL),
    "soc_pless": ("Tutorials", "Run the tiny SoC tutorial flow", TUTORIAL),
    "deps": ("Dependencies", "Install IP development dependencies", NONE),
    "deps-soc": ("Dependencies", "Install SoC development dependencies", NONE),
    "clean-pyc": ("Cleanup", "Remove Python caches", CLEAN),
    "clean_doc": ("Cleanup", "Remove generated docs", CLEAN),
    "clean_log": ("Cleanup", "Remove logs", CLEAN),
    "clean_rtl": ("Cleanup", "Remove generated RTL", CLEAN),
    "clean_sim": ("Cleanup", "Remove simulation outputs", CLEAN),
    "clean_cocotb": ("Cleanup", "Remove cocotb outputs", CLEAN),
    "clean_syn": ("Cleanup", "Remove synthesis outputs", CLEAN),
    "clean_signoff": ("Cleanup", "Remove signoff outputs", CLEAN),
    "clean_pnr": ("Cleanup", "Remove PnR outputs", CLEAN),
    "clean_fsm": ("Cleanup", "Clean FSM generator outputs", CLEAN),
    "clean_fsm_all": ("Cleanup", "Deep-clean FSM generator outputs", CLEAN),
    "clean_agent": ("Cleanup", "Remove old agent outputs", CLEAN),
    "clean_fsoc": ("Cleanup", "Remove FuseSoC build outputs", CLEAN),
    "clean_soc": ("Cleanup", "Remove SoC build outputs", CLEAN),
    "clean_sw": ("Cleanup", "Clean SoC software outputs", CLEAN),
    "clean_vendor": ("Cleanup", "Remove vendored IP checkouts", CLEAN),
    "clean_subdir": ("Cleanup", "Clean helper subdirectories", CLEAN),
    "clean": ("Cleanup", "Clean generated flow outputs", CLEAN),
    "clean_all": ("Cleanup", "Remove all generated run outputs", CLEAN),
}


# ---------------------------------------------------------------------------
# API objects
# ---------------------------------------------------------------------------

@dataclass(slots=True)
class FlexSoCConfig:
    """Store project paths and default Make variables."""

    project_root: PathLike = None
    workdir: PathLike = None
    values: Mapping[str, Any] = field(default_factory=dict)
    options: Mapping[str, Any] = field(default_factory=dict)

    def make_values(self) -> dict[str, Any]:
        """Merge the new values field with the old options alias."""

        return {**dict(self.options), **dict(self.values)}


@dataclass(frozen=True, slots=True)
class FlexSoCTarget:
    """Describe one callable Make target."""

    name: str
    group: str
    description: str
    params: tuple[str, ...] = ()

    def to_dict(self) -> dict[str, Any]:
        """Return target metadata as plain data."""

        return {
            "name": self.name,
            "group": self.group,
            "description": self.description,
            "params": list(self.params),
        }


@dataclass(frozen=True, slots=True)
class FlexSoCCommand:
    """Preview one Make invocation."""

    target: str
    argv: tuple[str, ...]
    cwd: Path
    env: Mapping[str, str]
    values: Mapping[str, str]

    def shell_line(self) -> str:
        """Render the command for a shell."""

        return shlex.join(self.argv)

    def to_dict(self) -> dict[str, Any]:
        """Return command data as plain data."""

        return {
            "target": self.target,
            "argv": list(self.argv),
            "cwd": str(self.cwd),
            "values": dict(self.values),
            "shell": self.shell_line(),
        }


@dataclass(frozen=True, slots=True)
class FlexSoCResult:
    """Store one executed command result."""

    command: FlexSoCCommand
    returncode: int
    stdout: str | None = None
    stderr: str | None = None

    @property
    def ok(self) -> bool:
        """Report whether Make exited successfully."""

        return self.returncode == 0

    def to_dict(self) -> dict[str, Any]:
        """Return execution data as plain data."""

        return {
            "ok": self.ok,
            "returncode": self.returncode,
            "command": self.command.to_dict(),
            "stdout": self.stdout,
            "stderr": self.stderr,
        }


# ---------------------------------------------------------------------------
# Small helpers
# ---------------------------------------------------------------------------

def _backend_makefile() -> Path:
    """Return the packaged backend Makefile."""

    return Path(__file__).with_name("backend") / "Makefile"


def _path(value: PathLike, fallback: Path) -> Path:
    """Resolve a path-like value or fallback."""

    return (Path(value) if value is not None else fallback).resolve()


def _upper(values: Mapping[str, Any]) -> dict[str, str]:
    """Convert settings to Make-style uppercase strings."""

    return {str(key).upper(): str(value) for key, value in values.items() if value is not None}


def _target(name: str) -> str:
    """Accept exact, dashed, or underscored target spelling."""

    for item in (name, name.replace("-", "_"), name.replace("_", "-")):
        if item in TARGETS:
            return item
    raise ValueError(f"unknown target {name!r}; run `fx commands` to list targets")


def _target_object(name: str) -> FlexSoCTarget:
    """Build one target object from the unified table."""

    group, description, params = TARGETS[name]
    return FlexSoCTarget(name, group, description, params)


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------

class FlexSoC:
    """Configure and launch backend Make targets."""

    def __init__(
        self,
        config: FlexSoCConfig | None = None,
        project_root: PathLike = None,
        workdir: PathLike = None,
        **values: Any,
    ) -> None:
        """Create a client with paths and initial Make-variable defaults."""

        base = config or FlexSoCConfig()
        self.config = FlexSoCConfig(
            project_root if project_root is not None else base.project_root,
            workdir if workdir is not None else base.workdir,
            base.make_values(),
        )
        self.settings = _upper({**self.config.make_values(), **values})

    @property
    def project_root(self) -> Path:
        """Return the repository root used as cwd."""

        return _path(self.config.project_root, Path.cwd())

    @property
    def workdir(self) -> Path:
        """Return the workspace directory passed to Make."""

        return _path(self.config.workdir, self.project_root / "workspace")

    def describe(self) -> dict[str, Any]:
        """Return the current client configuration."""

        return {
            "package": "flexsoc",
            "project_root": str(self.project_root),
            "workdir": str(self.workdir),
            "settings": dict(self.settings),
        }

    def set(self, **values: Any) -> "FlexSoC":
        """Update default Make variables in place."""

        self.settings.update(_upper(values))
        return self

    def override(self, **values: Any) -> "FlexSoC":
        """Return a copy with extra Make-variable defaults."""

        return FlexSoC(FlexSoCConfig(self.project_root, self.workdir, self.settings), **values)

    def targets(self) -> tuple[FlexSoCTarget, ...]:
        """List every backend Make target exposed by fx."""

        return tuple(_target_object(name) for name in TARGETS)

    def target_names(self) -> tuple[str, ...]:
        """Return only callable target names."""

        return tuple(TARGETS)

    def target_info(self, target: str) -> FlexSoCTarget:
        """Return metadata for one target."""

        return _target_object(_target(target))

    def values(self, overrides: Mapping[str, Any] | None = None) -> dict[str, str]:
        """Merge defaults, workspace, and call overrides."""

        return _upper({"WORKSPACE": self.workdir, **self.settings, **dict(overrides or {})})

    def command(self, target: str, **overrides: Any) -> FlexSoCCommand:
        """Build one Make command without executing it."""

        name, values = _target(target), self.values(overrides)
        argv = ("make", "-f", str(_backend_makefile()), name, *(f"{k}={v}" for k, v in values.items()))
        return FlexSoCCommand(name, tuple(argv), self.project_root, self._env(), values)

    def commands(self, *targets: str, **overrides: Any) -> tuple[FlexSoCCommand, ...]:
        """Build several Make commands in user order."""

        return tuple(self.command(target, **overrides) for target in targets)

    def run(
        self,
        *targets: str,
        check: bool = True,
        dry_run: bool = False,
        capture: bool = False,
        **overrides: Any,
    ) -> tuple[FlexSoCCommand | FlexSoCResult, ...]:
        """Run or preview one or more targets."""

        commands = self.commands(*targets, **overrides)
        if dry_run:
            return commands
        results: list[FlexSoCResult] = []
        for command in commands:
            done = subprocess.run(
                command.argv,
                cwd=command.cwd,
                env=command.env,
                check=check,
                capture_output=capture,
                text=capture,
            )
            results.append(
                FlexSoCResult(
                    command,
                    done.returncode,
                    done.stdout if capture else None,
                    done.stderr if capture else None,
                )
            )
        return tuple(results)

    def _env(self) -> dict[str, str]:
        """Prepend this checkout to PYTHONPATH."""

        env = os.environ.copy()
        extra = os.pathsep + env["PYTHONPATH"] if env.get("PYTHONPATH") else ""
        env["PYTHONPATH"] = str(self.project_root / "src") + extra
        return env


# ---------------------------------------------------------------------------
# Backward-compatible script hook
# ---------------------------------------------------------------------------

def main(argv: list[str] | None = None) -> int:
    """Delegate old script entry points to the CLI module."""

    from .cli import app

    return app(argv)


if __name__ == "__main__":
    raise SystemExit(main())
