"""Small FlexSoC Python API for launching backend Make targets."""

from __future__ import annotations

import json
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
DEFAULT_SETTINGS = {
    "TOP": "test",
    "HOST": "uart",
    "FORCE": "0",
    "RUN_ID": "default",
    "N_CLOCKS": "1",
    "PDK": "sky130",
    "WAVE_FORMAT": "fst",
    "GLS_SIMULATOR": "iverilog",
    "GLS_BACKEND": "sv",
    "TIMING_MODE": "zero",
    "SDF_STRICT": "1",
}

# Parameter bundles keep the target table compact; every value is still overrideable.
NONE = ()
CLOCKS = ("N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS")
BASE = ("TOP", "RUN_ID", "WORKSPACE", *CLOCKS)
COMMON = (*BASE, "RUN_TOP", "FORCE")
IP_DEV = (*BASE, "REG_ITF", "FORCE")
FETCH = (*BASE, "VENDOR", "TARGET", "FORCE")
IP_FULL = (*COMMON, "REG_ITF", "LINT_TOOL", "LINT_PART", "TARGET_SYN", "TARGET_OPT")
LINT = (*COMMON, "LINT_TOOL", "LINT_PART", "VSV")
SLANG = (*LINT, "SLANG_ROOT", "SLANG_TOP_FILE", "SLANG_TOP", "SLANG_ARGS", "SLANG_SEARCH_ARGS", "SLANG_AST_SCOPE")
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
    "WAVE_FORMAT",
    "WAVE_FILE",
)
VIEW = (*COMMON, "WAVE_VIEWER", "SURFER_BACKEND")
SYN = (*COMMON, "PDK", "PDK_ROOT", "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT", "VSV", "LIB_SYN")
FORMAL = (
    *COMMON,
    "SBY",
    "FORMAL_DEPTH",
    "FORMAL_BMC_DEPTH",
    "FORMAL_BMC_APPEND",
    "FORMAL_BMC_ENGINE",
    "FORMAL_PROVE_ENGINE",
    "FORMAL_COVER_ENGINE",
)
EQUIV = (
    *SYN,
    "SBY",
    "EQY",
    "EQY_SAT_DEPTH",
    "EQY_DEPTH",
    "EQY_ENGINE",
    "EQY_TIMEOUT",
    "EQY_QUICK_TIMEOUT",
    "EQY_JOBS",
    "EQY_USE_SAT",
    "EQY_SPLITNETS",
    "EQY_USE_PDR",
    "EQY_PDR_ENGINE",
    "EQY_SMT_ENGINE",
    "EQY_SMT_DEPTH",
    "EQY_XPROP",
    "EQY_JOIN_OUTPUTS",
    "EQY_STRATEGY_ORDER",
    "PRIM",
    "FORMAL_PDK_PROC",
)
SIGNOFF = (
    *COMMON,
    "PDK",
    "PDK_ROOT",
    "LIBS",
    "LIB_SYN",
    "PRIM",
    "WAVE_FORMAT",
    "WAVE_FILE",
    "GLS_SIMULATOR",
    "GLS_BACKEND",
    "TIMING_MODE",
    "SDF_STRICT",
    "SDF_FILE",
    "SDF_CORNER",
    "NETLIST",
    "SPEF_FILE",
    "PNR_SDC_FILE",
    "POWER_ACTIVITY",
    "POWER_DUTY",
    "PATH_VIEW_FILE",
    "NPATHS",
)
GATE_SIM = (
    *SIGNOFF,
    "TESTBENCH",
    "TEST_NAME",
    "TEST_ROOT",
    "REGCFG",
    "DATA_IN",
    "DATA_OUT",
)
PNR = (*COMMON, "PDK", "PDK_ROOT", "ORS", "ORS_TECH")
IP_LOAD = (*COMMON, "IP_NAME")
SOC = (*COMMON, "HOST", "SOC_CFG_MODE", "DEVLIST")
FSM = (*BASE, "FSM", "FORCE")
TUTORIAL = ("TUTORIAL_WS", "TUTORIAL_RUN_ID", *COMMON)
CLEAN = (*BASE, "RUN_TOP")
DEPS = ("DEPS_MODE", "DEPS_PROFILE", "DEPS_JOBS")


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
    "ip_flow": ("IP flow", "Run regression, formal, synthesis, signoff, and final reports", IP_FULL),
    "ip_flow_noreg": ("IP flow", "Run full closure without regenerating registers", IP_DEV),
    "ip_flow_all": ("IP flow", "Run full IP flow including PnR", IP_FULL),
    "lint": ("Linting", "Run Slang lint first, then Verilator lint", LINT),
    "lint_slang": ("Linting", "Run Slang HDL lint", LINT),
    "lint_verilator": ("Linting", "Run Verilator HDL lint", LINT),
    "lint_slang_suite": ("Linting", "Run the full Slang lint suite", LINT),
    "lint_verilator_suite": ("Linting", "Run the full Verilator lint suite", LINT),
    "lint_suite": ("Linting", "Run full Slang suite, then full Verilator suite", LINT),
    "lint_v": ("Linting", "Run Verilog lint checks", LINT),
    "lint_sv": ("Linting", "Run SystemVerilog lint checks", LINT),
    "lint_latch": ("Linting", "Run latch-focused HDL lint diagnostics", LINT),
    "lint_undriven": ("Linting", "Run undriven-signal HDL lint diagnostics", LINT),
    "lint_width": ("Linting", "Run width-focused HDL lint diagnostics", LINT),
    "lint_unconnected": ("Linting", "Run unconnected-port HDL lint diagnostics", LINT),
    "lint_unused": ("Linting", "Run unused-object HDL lint diagnostics", LINT),
    "_lint_run": ("Linting", "Internal lint dispatcher", LINT),
    "slang_hier": ("Linting", "Generate hierarchy text with slang-hier", SLANG),
    "slang_ast": ("Linting", "Generate Slang AST JSON", SLANG),
    "slang_flist": ("Linting", "Generate a trimmed topological RTL filelist with Slang", SLANG),
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
    "setup_formal": ("DV formal", "Prepare CSR formal and any authored design-property configurations", FORMAL),
    "setup_formal_csr_prove": ("DV formal", "Generate shared CSR BMC/prove configuration", FORMAL),
    "setup_formal_csr_cover": ("DV formal", "Generate automatic CSR cover configuration", FORMAL),
    "formal_csr_bmc": ("DV formal", "Bounded-check automatic CSR assertions", FORMAL),
    "formal_csr_prove": ("DV formal", "Prove automatic CSR semantics with SymbiYosys", FORMAL),
    "formal_csr_cover": ("DV formal", "Reach automatic CSR cover points with SymbiYosys", FORMAL),
    "formal_csr": ("DV formal", "Run CSR BMC, prove, then cover", FORMAL),
    "formal": ("DV formal", "Run all formal stages BMC, prove, then cover", FORMAL),
    "setup_formal_prove": ("DV formal", "Generate shared design BMC/prove configuration", FORMAL),
    "setup_formal_cover": ("DV formal", "Generate authored-property cover configuration", FORMAL),
    "formal_bmc": ("DV formal", "Bounded-check authored design assertions", FORMAL),
    "formal_prove": ("DV formal", "Prove authored properties with SymbiYosys", FORMAL),
    "formal_cover": ("DV formal", "Reach authored cover properties with SymbiYosys", FORMAL),
    "setup_eqy": ("Signoff", "Generate RTL-vs-post-synthesis EQY configuration", EQUIV),
    "eqy": ("Signoff", "Prove RTL equivalent to the post-synthesis netlist with EQY", EQUIV),
    "setup_signoff": ("Signoff", "Generate signoff scripts", SIGNOFF),
    "compile_syn": ("Signoff", "Compile post-synthesis simulation", SIGNOFF),
    "sim_syn": ("Signoff", "Run post-synthesis simulation", SIGNOFF),
    "compile_post_syn": ("Gate simulation", "Compile post-synthesis gate-level simulation with Icarus", GATE_SIM),
    "sim_post_syn": ("Gate simulation", "Run post-synthesis gate-level simulation with optional SDF", GATE_SIM),
    "compile_post_pnr": ("Gate simulation", "Compile post-PnR gate-level simulation with Icarus", GATE_SIM),
    "sdf_post_pnr": ("Gate simulation", "Export post-PnR SDF from final netlist, SDC and SPEF", GATE_SIM),
    "sim_post_pnr": ("Gate simulation", "Run post-PnR gate-level simulation with optional SDF", GATE_SIM),
    "sta": ("Signoff", "Run static timing analysis", SIGNOFF),
    "sdf": ("Signoff", "Write SDF timing files", SIGNOFF),
    "power_estimate": ("Signoff", "Estimate power using global switching activity", SIGNOFF),
    "sta_violators": ("Signoff", "Report timing violators", SIGNOFF),
    "path_view": ("Signoff", "Build interactive STA path view", SIGNOFF),
    "metrics": ("Run metadata", "Collect functional/formal/synthesis/signoff metrics", COMMON),
    "manifest": ("Run metadata", "Collect automatic run identity into meta/manifest.json", COMMON),
    "manifest_show": ("Run metadata", "Show the current run manifest in color", COMMON),
    "check": ("Run metadata", "Show complete current run closure status and metrics", COMMON),
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
    "deps-bootstrap": ("Dependencies", "Check/install prerequisites for a dependency profile", DEPS),
    "deps": ("Dependencies", "Install pinned base, impl, or riscv profile", DEPS),
    "deps-doctor": ("Dependencies", "Verify the selected pinned dependency profile", DEPS),
    "deps-versions": ("Dependencies", "Show pinned tool versions and revisions", NONE),
    "deps-env": ("Dependencies", "Print shell exports for the pinned toolchain", DEPS),
    "clean-pyc": ("Cleanup", "Remove Python caches", CLEAN),
    "clean_doc": ("Cleanup", "Remove generated docs", CLEAN),
    "clean_log": ("Cleanup", "Remove logs", CLEAN),
    "clean_rtl": ("Cleanup", "Remove generated RTL", CLEAN),
    "clean_sim": ("Cleanup", "Remove simulation outputs", CLEAN),
    "clean_cocotb": ("Cleanup", "Remove cocotb outputs", CLEAN),
    "clean_formal": ("Cleanup", "Remove property-formal proof outputs", CLEAN),
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





TECHNOLOGY_TARGETS = {
    "setup_syn", "syn", "syn_v", "syn_sv",
    "setup_eqy", "eqy",
    "compile_syn", "sim_syn", "compile_post_syn", "sim_post_syn",
    "compile_post_pnr", "sdf_post_pnr", "sim_post_pnr",
    "setup_signoff", "sta", "sdf", "power_estimate", "sta_violators",
    "path_view", "sta_corners", "power_estimate_corners", "signoff_corners",
    "setup_pnr", "pnr", "pnr_gui",
    "metrics", "manifest", "manifest_show", "check",
    "clean_syn", "clean_signoff", "clean_pnr", "clean_meta",
}


TECHNOLOGY_PATH_KEYS = {
    "RUN_ROOT", "CONSTRAINTSDIR", "SYNDIR", "SYNTH_LOGDIR",
    "EQUIVDIR", "EQUIV_LOG", "SIGNOFFDIR",
    "SIGNOFF_STA_DIR", "SIGNOFF_POWER_DIR", "SIGNOFF_SDF_DIR", "SIGNOFF_PATH_VIEW_DIR",
    "STA_LOGDIR", "POWER_LOGDIR", "SDF_LOGDIR",
    "ORSDIR", "OR_WORKDIR", "OR_LOGDIR",
    "POST_SYN_SIMDIR", "POST_LAYOUT_SIMDIR",
    "METADIR", "METRICS_JSON", "MANIFEST_JSON", "COMMAND_LOGDIR",
}


NATIVE_TARGETS: dict[str, tuple[str, str]] = {
    # Existing fx names are intentionally routed away from the legacy Make
    # implementation, which is VCD/SKY130-specific. Direct `make compile_syn`
    # remains available for compatibility while `fx` uses this backend.
    "compile_syn": ("compile", "post_syn"),
    "sim_syn": ("sim", "post_syn"),
    "compile_post_syn": ("compile", "post_syn"),
    "sim_post_syn": ("sim", "post_syn"),
    "compile_post_pnr": ("compile", "post_pnr"),
    "sdf_post_pnr": ("sdf", "post_pnr"),
    "sim_post_pnr": ("sim", "post_pnr"),
}



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
        """Merge defaults, discovered PDK views, workspace, and call overrides."""

        call_overrides = _upper(dict(overrides or {}))
        explicit = _upper({**DEFAULT_SETTINGS, **self.settings, **call_overrides})
        if {"N_CLOCKS", "CLOCK_DOMAINS"} & call_overrides.keys() and "CLOCK_RELATIONSHIPS" not in call_overrides:
            explicit.pop("CLOCK_RELATIONSHIPS", None)
        if (
            "PDK" in call_overrides
            and "PDK_ROOT" not in call_overrides
            and call_overrides["PDK"] != self.settings.get("PDK")
        ):
            # A one-shot PDK switch must not inherit the previously activated
            # technology's absolute PDK_ROOT. Resolve the selected catalogue
            # entry from its managed default root instead.
            explicit.pop("PDK_ROOT", None)
        pdk_values: dict[str, str] = {}
        pdk_name = explicit.get("PDK", DEFAULT_SETTINGS["PDK"])
        try:
            from .pdk import make_overrides

            pdk_values = make_overrides(
                self.project_root,
                pdk_name,
                explicit.get("PDK_ROOT"),
            )
        except ValueError:
            # Preserve target preview/help for a not-yet-fetched PDK. Commands
            # that actually need technology views will fail at their tool
            # boundary with the missing LIB/PRIM path instead of breaking lint.
            pdk_values = {"PDK": pdk_name}

        values = _upper({"WORKSPACE": self.workdir, **pdk_values, **explicit})
        from .clocking import clock_config
        from .run_layout import pdk_make_paths

        values.update(clock_config(values).make_values())
        values.update(pdk_make_paths(self.project_root, values))
        fmt = values.get("WAVE_FORMAT", "fst").lower()
        if fmt not in {"fst", "vcd"}:
            raise ValueError("WAVE_FORMAT must be 'fst' or 'vcd'")
        values["WAVE_FORMAT"] = fmt
        values.setdefault("WAVE_EXT", fmt)
        # Make's packaged default is FST-only. Override it from the Python
        # surface so WAVE_FORMAT=vcd genuinely changes Verilator's trace
        # backend instead of merely changing the filename extension.
        trace_flag = "--trace-fst" if fmt == "fst" else "--trace-vcd"
        values.setdefault(
            "VERILATOR_FLAGS",
            "-Wall -Wno-fatal --binary --timing --Mdir $(SIMDIR)/$(COMPILER) "
            f"{trace_flag} --trace-structs "
            "+incdir+$(RTLDIR) +incdir+$(TBDIR) +incdir+$(MODELDIR) "
            "+incdir+$(INC_PRIM) +incdir+$(INC_PKGS) +incdir+$(INC_PRIM_OT) +incdir+$(INC_TLUL)",
        )
        return values

    def command(self, target: str, **overrides: Any) -> FlexSoCCommand:
        """Build one backend command without executing it."""

        name, values = _target(target), self.values(overrides)
        if name in NATIVE_TARGETS:
            action, stage = NATIVE_TARGETS[name]
            argv = (
                sys.executable,
                "-m",
                "flexsoc.backend.post_sim",
                "--action",
                action,
                "--stage",
                stage,
                "--project-root",
                str(self.project_root),
                "--values-json",
                json.dumps(values, sort_keys=True),
            )
        else:
            # Only forward variables declared by this target.  In particular,
            # never leak PDK variables such as LIBS into RTL simulation: the
            # generated Verilator makefile uses the conventional LIBS variable
            # for C++ linker inputs, so a Liberty file there is interpreted as
            # a linker script.  Technology views belong only to technology
            # dependent targets.
            params = set(TARGETS[name][2])
            make_values = {key: value for key, value in values.items() if key in params}
            if name in TECHNOLOGY_TARGETS:
                make_values.update(
                    {key: value for key, value in values.items() if key in TECHNOLOGY_PATH_KEYS}
                )
            argv = (
                "make",
                "-f",
                str(_backend_makefile()),
                name,
                *(f"{k}={v}" for k, v in make_values.items()),
            )
        return FlexSoCCommand(name, tuple(argv), self.project_root, self._env(values), values)

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
            if command.target in TECHNOLOGY_TARGETS:
                pdk_root = (
                    Path(command.values.get("PDK_ROOT", "")).expanduser()
                    if command.values.get("PDK_ROOT")
                    else None
                )
                if pdk_root is None or not pdk_root.is_dir() or not command.values.get("LIB_SYN"):
                    pdk_name = command.values.get("PDK", DEFAULT_SETTINGS["PDK"])
                    raise RuntimeError(
                        f"target {command.target!r} requires an activated digital PDK; "
                        f"{pdk_name!r} is not ready. Run `fx pdk fetch <pdk>` then "
                        f"`fx pdk use <pdk>`."
                    )
                if not capture:
                    print(
                        f"\033[38;5;214m[technology]\033[0m "
                        f"pdk={command.values.get('PDK')} "
                        f"syn={command.values.get('SYNDIR')}",
                        flush=True,
                    )
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
                if ok and command.target == "eqy":
                    from .backend.metrics import eqy_solver_stats

                    stats = eqy_solver_stats(Path(command.values["EQUIV_LOG"]))
                    if stats:
                        summary = " · ".join(
                            f"{name} {row['proved']}/{row['attempts']} proven"
                            + (f", {row['errors']} error(s)" if row["errors"] else "")
                            for name, row in stats.items()
                        )
                        winners = ", ".join(
                            f"{name} ({row['proved']})"
                            for name, row in stats.items()
                            if row["proved"]
                        )
                        print(f"{orange}[eqy]{reset} {blue}strategies:{reset} {summary}", flush=True)
                        if winners:
                            print(
                                f"{orange}[eqy]{reset} {blue}successful solver/strategy:{reset} {winners}",
                                flush=True,
                            )

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
        if command.target in TECHNOLOGY_TARGETS and values.get("COMMAND_LOGDIR"):
            return Path(values["COMMAND_LOGDIR"]) / f"{name}.log"
        return workspace / "runs" / run_top / run_id / "logs" / "commands" / f"{name}.log"

    def _run_live(self, command: FlexSoCCommand, log_path: Path) -> subprocess.CompletedProcess[str]:
        """Run a command while teeing stdout/stderr to terminal and log."""

        from .backend.output import strip_ansi

        env = dict(command.env)
        env["FLEXSOC_LIVE"] = "1"
        env["FLEXSOC_COLOR"] = (
            "always"
            if sys.stdout.isatty()
            and os.environ.get("NO_COLOR") is None
            and os.environ.get("TERM") != "dumb"
            else "never"
        )
        with log_path.open("w", encoding="utf-8") as log:
            proc = subprocess.Popen(
                command.argv,
                cwd=command.cwd,
                env=env,
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True,
            )
            assert proc.stdout is not None
            for line in proc.stdout:
                sys.stdout.write(line)
                log.write(strip_ansi(line))
            return subprocess.CompletedProcess(command.argv, proc.wait())

    def _env(self, values: Mapping[str, str] | None = None) -> dict[str, str]:
        """Prepend this checkout to PYTHONPATH and export flow abstractions."""

        env = os.environ.copy()
        env["FLEXSOC_LIVE"] = "0"
        extra = os.pathsep + env["PYTHONPATH"] if env.get("PYTHONPATH") else ""
        env["PYTHONPATH"] = str(self.project_root / "src") + extra
        vals = values or {}
        fmt = vals.get("WAVE_FORMAT", "fst").lower()
        env["IVERILOG_DUMPER"] = "fst" if fmt == "fst" else "vcd"
        env["WAVE_FORMAT"] = fmt
        env["FLEXSOC_PDK"] = vals.get("PDK", "")
        env["FLEXSOC_PDK_CLASS"] = vals.get("PDK_CLASS", "")
        env["FLEXSOC_RUN_ROOT"] = vals.get("RUN_ROOT", "")
        env["FLEXSOC_DRIVING_CELL"] = vals.get("DRIVING_CELL", "")
        for key in ("N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS"):
            env[key] = vals.get(key, "")
        # setup_signoff consumes EQY debug/closure knobs directly from the
        # environment so the generated sign-off config can evolve without
        # Makefile-specific plumbing for every strategy option.
        for key, value in vals.items():
            if key.startswith("EQY_"):
                env[key] = value
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
