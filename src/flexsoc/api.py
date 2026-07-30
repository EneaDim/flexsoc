"""Small FlexSoC Python API for launching backend Make targets."""

from __future__ import annotations

import os
import re
import shlex
import subprocess
import sys
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
SIM = (
    *COMMON,
    "TESTBENCH",
    "TEST_NAMES",
    "TEST_NAME",
    "REGCFG",
    "DATA_IN",
    "DATA_OUT",
    "VSV",
    "COMPILER",
    "COCOTB_WAVES",
    "SEED",
    "REGRESSION_BACKENDS",
    "COVERAGE",
    "COVERAGE_DETAIL_LIMIT",
)
VIEW = (*COMMON, "WAVE_VIEWER", "SURFER_BACKEND")
SYN = (*COMMON, "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT", "VSV")
SIGNOFF = (*COMMON, "LIBS", "POWER_ACTIVITY", "POWER_DUTY", "PATH_VIEW_FILE", "NPATHS")
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
    "hjson_multi": ("Multi-clock", "Generate multi-clock HJSON register templates", IP_DEV),
    "reg_multi": ("Multi-clock", "Generate selected or changed multi-clock register RTL", IP_DEV),
    "doc_multi": ("Multi-clock", "Generate selected or changed multi-clock register docs", IP_DEV),
    "rtl_stub_multi": ("Multi-clock", "Generate multi-clock RTL core and wrapper", IP_DEV),
    "top_from_core_multi": ("Multi-clock", "Regenerate multi-clock wrapper from edited core ports", IP_DEV),
    "sdc_multi": ("Multi-clock", "Generate multi-clock IP timing constraints", SYN),
    "notes_multi": ("Multi-clock", "Generate local multi-clock scaffold notes", IP_DEV),
    "setup_model_multi": ("Multi-clock", "Generate multi-clock model, CSR regmap, and test scaffolds", SIM),
    "tests_gen_multi": ("Multi-clock", "Generate all multi-clock vector tests from <top>_tests.py", SIM),
    "test_gen_multi": ("Multi-clock", "Generate one multi-clock vector test selected by TEST_NAME", SIM),
    "setup_tb_multi": ("Multi-clock", "Generate a multi-clock SystemVerilog testbench scaffold", SIM),
    "setup_cocotb_multi": ("Multi-clock", "Generate a multi-clock cocotb scaffold", SIM),
    "multiclock_scaffold": ("Multi-clock", "Bootstrap the decomposed multi-clock IP scaffold", IP_DEV),
    "sta_corners": ("Signoff", "Run STA setup/hold for each configured corner", SIGNOFF),
    "power_estimate_corners": ("Signoff", "Estimate power for each corner using global activity", SIGNOFF),
    "signoff_corners": ("Signoff", "Run SDF, multi-corner STA and estimated power", SIGNOFF),
    "hjson": ("IP flow", "Generate an HJSON register template", IP_DEV),
    "hjson_gen": ("IP flow", "Compatibility alias for HJSON generation", IP_DEV),
    "reg": ("IP flow", "Generate register RTL from HJSON", IP_DEV),
    "doc": ("IP flow", "Generate register documentation", IP_DEV),
    "rtl_stub": ("IP flow", "Generate RTL core and aligned top wrapper", IP_DEV),
    "top_from_core": ("IP flow", "Regenerate top wrapper from edited core ports", IP_DEV),
    "flist": ("IP flow", "Generate Slang-ordered common/IP RTL filelists", IP_DEV),
    "driver": ("IP flow", "Generate C driver files from HJSON", IP_DEV),
    "fetch": ("IP flow", "Fetch or update a vendored dependency", FETCH),
    "ip_start": ("IP flow", "Bootstrap a complete IP run", IP_FULL),
    "ip_flow": ("IP flow", "Run the standard IP flow", IP_FULL),
    "ip_flow_noreg": ("IP flow", "Run IP flow without regenerating registers", IP_DEV),
    "ip_flow_all": ("IP flow", "Run full IP flow including PnR", IP_FULL),
    "lint": ("Linting", "Run HDL lint checks", LINT),
    "lint_suite": ("Linting", "Run the complete HDL lint diagnostic suite", LINT),
    "lint_v": ("Linting", "Run Verilog lint checks", LINT),
    "lint_sv": ("Linting", "Run SystemVerilog lint checks", LINT),
    "lint_latch": ("Linting", "Run latch-focused HDL lint diagnostics", LINT),
    "lint_undriven": ("Linting", "Run undriven-signal HDL lint diagnostics", LINT),
    "lint_width": ("Linting", "Run width-focused HDL lint diagnostics", LINT),
    "lint_unconnected": ("Linting", "Run unconnected-port HDL lint diagnostics", LINT),
    "lint_unused": ("Linting", "Run unused-object HDL lint diagnostics", LINT),
    "_lint_run": ("Linting", "Internal lint dispatcher", LINT),
    "slang_hier": ("Linting", "Generate hierarchy text with slang-hier", LINT),
    "slang_ast": ("Linting", "Generate Slang AST JSON", LINT),
    "slang_flist": ("Linting", "Generate a trimmed topological RTL filelist with Slang", LINT),
    "setup_tb": ("DV functional", "Generate a SystemVerilog testbench scaffold", SIM),
    "setup_cocotb": ("DV functional", "Generate a cocotb scaffold", SIM),
    "setup_model": ("DV functional", "Generate Python model, CSR regmap, and test scaffolds", SIM),
    "regmap_py": ("DV functional", "Regenerate only <top>_regmap.py from HJSON", SIM),
    "tests_gen": ("DV functional", "Generate all vector tests from <top>_tests.py", SIM),
    "test_gen": ("DV functional", "Generate one vector test selected by TEST_NAME", SIM),
    "tests": ("DV functional", "List generated vector tests", SIM),
    "compile": ("DV functional", "Compile the current testbench", SIM),
    "compile_v": ("DV functional", "Compile Verilog simulation", SIM),
    "compile_sv": ("DV functional", "Compile SystemVerilog simulation", SIM),
    "sim": ("DV functional", "Run simulation", SIM),
    "sim_v": ("DV functional", "Run Verilog simulation", SIM),
    "sim_sv": ("DV functional", "Run SystemVerilog simulation", SIM),
    "sim_tests": ("DV functional", "Run every generated SystemVerilog vector test", SIM),
    "cocotb": ("DV functional", "Run cocotb tests", SIM),
    "cocotb_tests": ("DV functional", "Run every generated cocotb vector test", SIM),
    "regression": ("DV functional", "Run all tests on selected backends with Verilator coverage", SIM),
    "coverage": ("DV functional", "Merge and report existing Verilator coverage data", SIM),
    "coverage_detail": ("DV functional", "Show uncovered Verilator coverage points", SIM),
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
    "power_estimate": ("Signoff", "Estimate power using global switching activity", SIGNOFF),
    "sta_violators": ("Signoff", "Report timing violators", SIGNOFF),
    "path_view": ("Signoff", "Build interactive STA path view", SIGNOFF),
    "metrics": ("Run metadata", "Collect available run metrics into meta/metrics.json", COMMON),
    "manifest": ("Run metadata", "Collect automatic run identity into meta/manifest.json", COMMON),
    "check": ("Run metadata", "Print current run metrics; informational only", COMMON),
    "setup_pnr": ("Place and route", "Generate OpenROAD config", PNR),
    "pnr": ("Place and route", "Run OpenROAD place and route", PNR),
    "pnr_gui": ("Place and route", "Open OpenROAD GUI", PNR),
    "ip_load": ("IP load/save", "Load an IP into a run workspace", IP_LOAD),
    "ip_save": ("IP load/save", "Save authored IP sources back to hw/ips", IP_LOAD),
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
    "soc_flist": ("SoC flow", "Generate Slang-ordered SoC common/IP filelists", SOC),
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
    "clean_meta": ("Cleanup", "Remove run metadata", CLEAN),
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
    log_path: Path | None = None

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
            "log_path": str(self.log_path) if self.log_path else None,
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


def _safe_log_name(value: str) -> str:
    """Return a filesystem-safe log filename fragment."""

    safe = re.sub(r"[^A-Za-z0-9_.-]+", "_", str(value).strip())
    return safe.strip("._") or "target"



MULTICLOCK_TARGET_ALIASES = {
    "hjson": "hjson_multi",
    "reg": "reg_multi",
    "doc": "doc_multi",
    "rtl_stub": "rtl_stub_multi",
    "top_from_core": "top_from_core_multi",
    "setup_model": "setup_model_multi",
    "tests_gen": "tests_gen_multi",
    "test_gen": "test_gen_multi",
    "setup_tb": "setup_tb_multi",
    "setup_cocotb": "setup_cocotb_multi",
    "setup_sdc": "sdc_multi",
}
MULTICLOCK_TRUE_VALUES = {"1", "true", "yes", "on", "multi", "multiclock"}


def _is_multiclock_run(target: str, values: Mapping[str, Any], project_root: Path) -> bool:
    """Return true when generic targets should resolve to multi-clock targets."""
    for key in ("CLOCK_MODE", "MODE", "IP_MODE"):
        if str(values.get(key, "")).lower() in {"multi", "multiclock"}:
            return True
    for key in ("MULTICLOCK", "MULTI_CLOCK"):
        if str(values.get(key, "")).lower() in MULTICLOCK_TRUE_VALUES:
            return True
    if target == "hjson":
        return False
    workspace = Path(values.get("WORKSPACE", project_root / "workspace"))
    top = str(values.get("TOP", ""))
    run_top = str(values.get("RUN_TOP") or top or "run")
    run_id = str(values.get("RUN_ID", "default"))
    data_dir = workspace / "runs" / run_top / run_id / "data"
    return bool(top and any(data_dir.glob(f"{top}_*.hjson")))


def _resolve_target_for_run(target: str, values: Mapping[str, Any], project_root: Path) -> str:
    """Map a user-facing target to the Make target for this run."""
    if target in MULTICLOCK_TARGET_ALIASES and _is_multiclock_run(target, values, project_root):
        return MULTICLOCK_TARGET_ALIASES[target]
    return target


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
        make_target = _resolve_target_for_run(name, values, self.project_root)
        argv = ("make", "-f", str(_backend_makefile()), make_target, *(f"{k}={v}" for k, v in values.items()))
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
        live: bool = False,
        **overrides: Any,
    ) -> tuple[FlexSoCCommand | FlexSoCResult, ...]:
        """Run or preview one or more targets."""

        commands = self.commands(*targets, **overrides)
        if dry_run:
            return commands

        results: list[FlexSoCResult] = []
        for command in commands:
            log_path = self._command_log_path(command) if capture or live else None
            if log_path:
                log_path.parent.mkdir(parents=True, exist_ok=True)

            if capture:
                done = subprocess.run(
                    command.argv,
                    cwd=command.cwd,
                    env=command.env,
                    check=False,
                    capture_output=True,
                    text=True,
                )
                assert log_path is not None
                log_path.write_text((done.stdout or "") + (done.stderr or ""), encoding="utf-8")
            else:
                _, description, _ = TARGETS.get(command.target, ("Target", "Run target", ()))
                orange, blue, green, red, reset = "\033[38;5;214m", "\033[94m", "\033[92m", "\033[91m", "\033[0m"
                print(f"{orange}→ {command.target}{reset}: {blue}{description}{reset}", flush=True)
                print(f"{orange}[{command.target}]{reset} {blue}{description}{reset}", flush=True)
                if live:
                    assert log_path is not None
                    done = self._run_live(command, log_path)
                else:
                    done = subprocess.run(
                        command.argv,
                        cwd=command.cwd,
                        env=command.env,
                        check=False,
                        text=True,
                    )
                ok = done.returncode == 0
                status = f"{green}✓{reset}" if ok else f"{red}✗{reset}"
                suffix = "done" if ok else f"failed ({done.returncode})"
                print(f"{status} {orange}{command.target}{reset}: {blue}{suffix}{reset}", flush=True)

            result = FlexSoCResult(
                command,
                done.returncode,
                done.stdout if capture else None,
                done.stderr if capture else None,
                log_path,
            )
            results.append(result)
            if check and done.returncode:
                detail = f"; log: {log_path}" if log_path else ""
                raise RuntimeError(
                    f"target '{command.target}' failed with exit code {done.returncode}{detail}"
                )
        return tuple(results)

    def _command_log_path(self, command: FlexSoCCommand) -> Path:
        """Return the per-target command log path."""

        values = command.values
        workspace = Path(values.get("WORKSPACE", str(self.workdir)))
        run_top = values.get("RUN_TOP") or values.get("TOP") or "run"
        run_id = values.get("RUN_ID", "default")
        name = _safe_log_name(command.target)
        if command.target in {"sim", "sim_v", "sim_sv", "cocotb"} and values.get("TEST_NAME"):
            name = f"{name}_{_safe_log_name(values['TEST_NAME'])}"
        return workspace / "runs" / run_top / run_id / "logs" / "commands" / f"{name}.log"

    def _run_live(self, command: FlexSoCCommand, log_path: Path) -> subprocess.CompletedProcess[str]:
        """Run a command while teeing stdout/stderr to terminal and log."""

        with log_path.open("w", encoding="utf-8") as log:
            proc = subprocess.Popen(
                command.argv,
                cwd=command.cwd,
                env=command.env,
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True,
            )
            assert proc.stdout is not None
            for line in proc.stdout:
                sys.stdout.write(line)
                log.write(line)
            return subprocess.CompletedProcess(command.argv, proc.wait())

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
