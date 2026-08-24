"""Public FlexSoC API over the object-oriented backend flow."""

from __future__ import annotations

import os
import re
import shlex
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping

from .backend.signoff.sta import SDF_MODE_TO_CORNER


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
    "TARGET_OPT": "area",
    "WAVE_FORMAT": "fst",
    "GLS_SIMULATOR": "iverilog",
    "GLS_BACKEND": "sv",
    "TIMING_MODE": "zero",
    "GLS_UNIT_DELAY": "1ps",
    "SDF_STRICT": "1",
    "FST2VCD": "fst2vcd",
    "SIGNOFF_STAGE": "post_syn",
    "POWER_VCD_SCOPE": "auto",
    "POWER_DUT_INSTANCE": "auto",
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
CDC_RDC = (*COMMON, "CLK_PERIOD", "CDC_RDC_HEARTBEAT", "CDC_RDC_STRICT")
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
SYN = (*COMMON, "PDK", "PDK_ROOT", "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT", "VSV", "LIB_SYN", "TIEHI_CELL_AND_PORT", "TIELO_CELL_AND_PORT", "MIN_BUF_CELL_AND_PORTS")
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
    "EQY_RESET_NORMALIZE",
    "EQY_RESET_CYCLES",
    "PRIM",
    "FORMAL_PDK_PROC",
)
SIGNOFF = (
    *COMMON,
    "PDK",
    "PDK_ROOT",
    "CLK_PERIOD",
    "LIBS",
    "LIB_SYN",
    "PRIM",
    "WAVE_FORMAT",
    "WAVE_FILE",
    "GLS_SIMULATOR",
    "GLS_BACKEND",
    "TIMING_MODE",
    "GLS_UNIT_DELAY",
    "SDF_STRICT",
    "SDF_FILE",
    "SDF_CORNER",
    "NETLIST",
    "SPEF_FILE",
    "PNR_SDC_FILE",
    "POWER_ACTIVITY",
    "POWER_DUTY",
    "POWER_GLOBAL_ACTIVITY",
    "MACRO_LIBS",
    "SIGNOFF_STAGE",
    "STA_ENDPOINT_GROUP_LIMIT",
    "STA_ENDPOINT_PATH_LIMIT",
    "STA_NEAR_CRITICAL_SETUP",
    "STA_NEAR_CRITICAL_HOLD",
    "POWER_TOP_INSTANCES",
    "POWER_TEST_NAME",
    "POWER_TEST_NAMES",
    "POWER_GLS_BACKEND",
    "POWER_GLS_BACKENDS",
    "POWER_TIMING_MODE",
    "POWER_TIMING_MODES",
    "POWER_VCD_SCOPE",
    "POWER_DUT_INSTANCE",
    "FST2VCD",
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
GATE_SIM_ALL = tuple(dict.fromkeys((*GATE_SIM, "TEST_NAMES", "TIMING_MODES")))
PNR = (*COMMON, "PDK", "PDK_ROOT", "CLK_PERIOD", "ORS", "ORS_TECH")
IP_LOAD = (*COMMON, "IP_NAME")
IP_SAVE = tuple(dict.fromkeys((*EQUIV, *SIGNOFF, "IP_NAME", "IP_LIBRARY_ROOT")))
SOC = (*COMMON, "HOST", "SOC_CFG_MODE", "DEVLIST")
FSM = (*BASE, "FSM", "FORCE")
TUTORIAL = ("TUTORIAL_WS", "TUTORIAL_RUN_ID", *COMMON)
CLEAN = (*BASE, "RUN_TOP")
DEPS = ("DEPS_MODE", "DEPS_PROFILE", "DEPS_JOBS", "DEPS_PRUNE_APPLY", "DEPS_PRUNE_CACHE")


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
    "setup_cdc_rdc": ("Domain analysis", "Generate pre-technology CDC/RDC structural extraction", CDC_RDC),
    "cdc_rdc": ("Domain analysis", "Run structural CDC/RDC, protocol, reset, setup, and glitch checks", CDC_RDC),
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
    "setup_syn": ("Synthesis", "Generate Yosys synthesis scripts", SYN),
    "syn": ("Synthesis", "Run synthesis", SYN),
    "syn_v": ("Synthesis", "Run Verilog synthesis", SYN),
    "syn_sv": ("Synthesis", "Run SystemVerilog synthesis", SYN),
    "yosys-vgen": ("Synthesis", "Convert SV to Verilog with Yosys", SYN),
    "sv2v": ("Synthesis", "Convert SV to Verilog with sv2v", SYN),
    "setup_formal": ("DV formal", "Create or preserve starter design assertions and covers", FORMAL),
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
    "setup_signoff": ("Signoff", "Generate PDK-scoped SDC and signoff scripts", SIGNOFF),
    "compile_syn": ("Signoff", "Compile post-synthesis simulation", SIGNOFF),
    "sim_syn": ("Signoff", "Run post-synthesis simulation", SIGNOFF),
    "compile_post_syn": ("Gate simulation", "Compile post-synthesis gate-level simulation with Icarus", GATE_SIM),
    "sim_post_syn": ("Gate simulation", "Run post-synthesis gate-level simulation with optional SDF", GATE_SIM),
    "sim_post_syn_all": ("Gate simulation", "Run every selected post-synthesis GLS test/timing combination with one backend", GATE_SIM_ALL),
    "compile_post_pnr": ("Gate simulation", "Compile post-PnR gate-level simulation with Icarus", GATE_SIM),
    "setup_signoff_post_pnr": ("Post-PnR signoff", "Generate post-PnR OpenSTA scripts from final ORFS artifacts", SIGNOFF),
    "signoff_post_pnr": ("Post-PnR signoff", "Run post-PnR SDF, STA and vectorless power", SIGNOFF),
    "sdf_post_pnr": ("Post-PnR signoff", "Write post-PnR SDF from final netlist, SDC and SPEF", SIGNOFF),
    "sta_post_pnr": ("Post-PnR signoff", "Run SPEF-aware STA with propagated clock reporting", SIGNOFF),
    "power_estimate_post_pnr": ("Post-PnR signoff", "Estimate post-PnR power with extracted parasitics", SIGNOFF),
    "sim_post_pnr": ("Gate simulation", "Run post-PnR gate-level simulation with optional SDF", GATE_SIM),
    "sim_post_pnr_all": ("Gate simulation", "Run every selected post-PnR GLS test/timing combination", GATE_SIM_ALL),
    "power_analysis_post_pnr": ("Post-PnR signoff", "Analyze post-PnR power for one GLS workload", SIGNOFF),
    "power_analysis_post_pnr_all": ("Post-PnR signoff", "Analyze post-PnR power for all matching GLS workloads", SIGNOFF),
    "fusion_analysis_post_pnr": ("Post-PnR signoff", "Correlate routed timing and power for one GLS workload", SIGNOFF),
    "fusion_analysis_post_pnr_all": ("Post-PnR signoff", "Correlate routed timing and power for all GLS workloads", SIGNOFF),
    "sta": ("Signoff", "Run static timing analysis", SIGNOFF),
    "sdf": ("Signoff", "Write SDF timing files", SIGNOFF),
    "power_estimate": ("Signoff", "Estimate power using global switching activity", SIGNOFF),
    "power_analysis": ("Signoff", "Analyze power in the GLS trace aligned signoff scenario", SIGNOFF),
    "power_analysis_all": ("Signoff", "Analyze power for all matching aligned GLS scenarios", SIGNOFF),
    "fusion_analysis": ("Signoff", "Correlate timing and power in one aligned GLS scenario", SIGNOFF),
    "fusion_analysis_all": ("Signoff", "Correlate timing and power for all aligned GLS scenarios", SIGNOFF),
    "sta_violators": ("Signoff", "Report timing violators", SIGNOFF),
    "path_view": ("Signoff", "Build interactive STA path view", SIGNOFF),
    "metrics": ("Run metadata", "Collect functional/formal/synthesis/signoff metrics", COMMON),
    "manifest": ("Run metadata", "Collect automatic run identity into meta/manifest.json", COMMON),
    "manifest_show": ("Run metadata", "Show the current run manifest in color", COMMON),
    "check": ("Run metadata", "Show existing complete run closure status and metrics", COMMON),
    "setup_pnr": ("Implementation", "Generate OpenROAD implementation config", PNR),
    "pnr": ("Implementation", "Run OpenROAD implementation", PNR),
    "pnr_gui": ("Implementation", "Open OpenROAD GUI", PNR),
    "physical_signoff": ("Physical signoff", "Run ORFS DRC/LVS and qualify physical sign-off", PNR),
    "ip_load": ("IP load/save", "Load the complete IP package into a run workspace", IP_LOAD),
    "ip_save": (
        "IP load/save",
        "Save reusable current-PDK collateral and qualification metadata",
        IP_SAVE,
    ),
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
    "deps-status": ("Dependencies", "Show managed toolchains, disk use, and command duplicates", DEPS),
    "deps-prune": ("Dependencies", "Prune obsolete managed toolchains and optional build caches", DEPS),
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
    """Store one executed backend operation result."""

    command: FlexSoCCommand
    returncode: int
    stdout: str | None = None
    stderr: str | None = None
    log_path: Path | None = None

    @property
    def ok(self) -> bool:
        """Report whether the backend operation completed successfully."""

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




def _scenario_log_value(value: str) -> str:
    """Render SDF min/typ/max selectors as their aligned ff/tt/ss scenarios."""

    tokens = [part for part in re.split(r"[\s,]+", str(value).strip()) if part]
    return " ".join(SDF_MODE_TO_CORNER.get(token.lower(), token) for token in tokens)

def _selector_log_suffix(selectors: tuple[tuple[str, str], ...]) -> str:
    """Return a concise suffix containing only non-default matrix selectors."""

    parts: list[str] = []
    for label, value in selectors:
        text = str(value).strip()
        if not text or text.lower() == "all":
            continue
        parts.extend((label, _safe_log_name(text)))
    return "_".join(parts)


TECHNOLOGY_TARGETS = {
    "setup_syn", "syn", "syn_v", "syn_sv",
    "setup_eqy", "eqy",
    "compile_syn", "sim_syn", "compile_post_syn", "sim_post_syn", "sim_post_syn_all",
    "compile_post_pnr", "sim_post_pnr", "sim_post_pnr_all",
    "setup_signoff_post_pnr", "signoff_post_pnr", "sdf_post_pnr", "sta_post_pnr", "power_estimate_post_pnr",
    "power_analysis_post_pnr", "power_analysis_post_pnr_all", "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
    "setup_signoff", "sta", "sdf", "power_estimate", "power_analysis", "power_analysis_all", "fusion_analysis", "fusion_analysis_all", "sta_violators",
    "path_view", "sta_corners", "power_estimate_corners", "signoff_corners",
    "setup_pnr", "pnr", "pnr_gui", "physical_signoff",
    "ip_save",
    "metrics", "manifest", "manifest_show", "check",
    "clean_syn", "clean_signoff", "clean_pnr", "clean_meta",
}


AUTO_SETUP_TARGETS: dict[str, tuple[str, ...]] = {
    # Functional testbench setup is always explicit: it may be refreshed after
    # a technology switch without rewriting authored tests or vectors.
    # Setup targets encode their own setup-only dependencies once.
    "syn": ("setup_syn",),
    "syn_v": ("setup_syn",),
    "syn_sv": ("setup_syn",),
    "formal_csr_bmc": ("setup_formal_csr_prove",),
    "formal_csr_prove": ("setup_formal_csr_prove",),
    "formal_csr_cover": ("setup_formal_csr_cover",),
    "setup_formal_prove": ("setup_formal",),
    "setup_formal_cover": ("setup_formal",),
    "formal_bmc": ("setup_formal_prove",),
    "formal_prove": ("setup_formal_prove",),
    "formal_cover": ("setup_formal_cover",),
    "eqy": ("setup_eqy",),
    "cdc_rdc": ("setup_cdc_rdc",),
    "sim_post_syn_all": ("sdf",),
    "sdf_post_pnr": ("setup_signoff_post_pnr",),
    "sta_post_pnr": ("setup_signoff_post_pnr",),
    "power_estimate_post_pnr": ("setup_signoff_post_pnr",),
    "sim_post_pnr_all": ("sdf_post_pnr",),
    "power_analysis_post_pnr": ("setup_signoff_post_pnr",),
    "power_analysis_post_pnr_all": ("setup_signoff_post_pnr",),
    "fusion_analysis_post_pnr": ("setup_signoff_post_pnr",),
    "fusion_analysis_post_pnr_all": ("setup_signoff_post_pnr",),
    "sta": ("setup_signoff",),
    "sta_corners": ("setup_signoff",),
    "sdf": ("setup_signoff",),
    "power_estimate": ("setup_signoff",),
    "power_estimate_corners": ("setup_signoff",),
    "sta_violators": ("setup_signoff",),
    "power_analysis": ("setup_signoff",),
    "power_analysis_all": ("setup_signoff",),
    "fusion_analysis": ("setup_signoff",),
    "fusion_analysis_all": ("setup_signoff",),
    "setup_pnr": ("syn", "setup_signoff"),
    "pnr": ("setup_pnr",),
    "pnr_gui": ("setup_pnr",),
}


TECHNOLOGY_PATH_KEYS = {
    "RUN_ROOT", "SIGNOFF_SDC_FILE", "SYNDIR", "SYNTH_LOGDIR",
    "EQUIVDIR", "EQUIV_LOG", "SIGNOFFDIR", "SIGNOFF_PDK_DIR",
    "SIGNOFF_STA_DIR", "SIGNOFF_POWER_DIR", "SIGNOFF_SDF_DIR", "SIGNOFF_FUSION_DIR", "SIGNOFF_PATH_VIEW_DIR",
    "STA_LOGDIR", "POWER_LOGDIR", "SDF_LOGDIR", "FUSION_LOGDIR",
    "ORSDIR", "OR_WORKDIR", "OR_LOGDIR",
    "PHYSICAL_SIGNOFF_DIR", "PHYSICAL_SIGNOFF_JSON", "PHYSICAL_SIGNOFF_LOG",
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
    "sim_post_syn_all": ("sim_all", "post_syn"),
    "compile_post_pnr": ("compile", "post_pnr"),
    "sim_post_pnr": ("sim", "post_pnr"),
    "sim_post_pnr_all": ("sim_all", "post_pnr"),
}

TARGET_ALIASES = {
    "setup_signoff_post_pnr": "setup_signoff",
    "signoff_post_pnr": "signoff_corners",
    "sdf_post_pnr": "sdf",
    "sta_post_pnr": "sta",
    "power_estimate_post_pnr": "power_estimate",
    "power_analysis_post_pnr": "power_analysis",
    "power_analysis_post_pnr_all": "power_analysis_all",
    "fusion_analysis_post_pnr": "fusion_analysis",
    "fusion_analysis_post_pnr_all": "fusion_analysis_all",
}
POST_PNR_SIGNOFF_TARGETS = set(TARGET_ALIASES) | {"sim_post_pnr_all"}


ACTIVITY_ANALYSIS_TARGETS = {
    "power_analysis", "power_analysis_all", "fusion_analysis", "fusion_analysis_all",
    "power_analysis_post_pnr", "power_analysis_post_pnr_all",
    "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
}

STREAM_BY_DEFAULT_TARGETS = {
    "sim_post_syn_all", "sim_post_pnr_all", "fusion_analysis", "fusion_analysis_all",
    "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
}

QUIET_BY_DEFAULT_TARGETS = {
    "compile_post_syn", "sim_post_syn",
    "compile_post_pnr", "sdf_post_pnr", "sim_post_pnr",
    "power_analysis", "power_analysis_all", "power_analysis_post_pnr", "power_analysis_post_pnr_all",
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


class _TargetRouter:
    """Map historical CLI targets to the new object-oriented backend API."""

    def __init__(self, client: "FlexSoC", values: Mapping[str, str], *, on: str = "local"):
        from .backend import Backend, BackendContext
        from .backend.core import ToolRunner

        self.client = client
        self.values = dict(values)
        self.on = on
        self.context = BackendContext(client.project_root, client.workdir, self.values)
        self.runner = ToolRunner(client.execution_targets, project_root=client.project_root)
        self.backend = Backend(self.context, self.runner)
        self.paths = self.context.paths

    @staticmethod
    def _bool(value: object, default: bool = False) -> bool:
        if value is None:
            return default
        return str(value).strip().lower() in {"1", "true", "yes", "on"}

    def _path(self, key: str, default: Path) -> Path:
        value = self.values.get(key)
        return Path(value).expanduser().resolve() if value else default.resolve()

    def _words(self, key: str, default: str = "") -> tuple[str, ...]:
        return tuple(part for part in self.values.get(key, default).replace(",", " ").split() if part)

    def _slang_inputs(self) -> tuple[Path, Path, tuple[Path, ...], str]:
        root = self._path("SLANG_ROOT", self.paths.rtl)
        top_file = self._path("SLANG_TOP_FILE", root / f"{self.paths.top}.sv")
        tokens = iter(shlex.split(self.values.get("SLANG_SEARCH_ARGS", "")))
        roots, extra = [], []
        for token in tokens:
            if token == "--search-root":
                try:
                    roots.append(Path(next(tokens)).expanduser().resolve())
                except StopIteration as exc:
                    raise ValueError("SLANG_SEARCH_ARGS: --search-root requires a path") from exc
            elif token.startswith("--search-root="):
                roots.append(Path(token.split("=", 1)[1]).expanduser().resolve())
            else:
                extra.append(token)
        if not roots:
            for filelist in (self.paths.rtl_common, self.paths.rtl_ip):
                if not filelist.is_file():
                    continue
                for raw in filelist.read_text(encoding="utf-8").splitlines():
                    item = raw.strip()
                    if not item or item.startswith(("#", "+define+")):
                        continue
                    items = item.removeprefix("+incdir+").split("+") if item.startswith("+incdir+") else [str(Path(item).parent)]
                    roots.extend((root / path if not path.is_absolute() else path).resolve() for path in map(Path, items) if str(path))
            roots = list(dict.fromkeys(roots)) or [self.paths.rtl, self.client.project_root / "hw" / "ips", self.client.project_root / "vendor"]
        args = [*shlex.split(self.values.get("SLANG_ARGS", "")), *extra]
        return root, top_file, tuple(roots), shlex.join(args)

    def _run_cmd(self, argv, *, cwd: Path | None = None, log: Path | None = None, inputs=(), outputs=()) -> int:
        from .backend.core import CommandRequest

        cwd = (cwd or self.client.project_root).resolve()
        log = log or self.paths.logs / "commands" / f"{_safe_log_name(str(argv[0]))}.log"
        request = CommandRequest(tuple(str(x) for x in argv), cwd, {}, log, tuple(inputs), tuple(outputs))
        return self.runner.run(request, on=self.on).returncode

    def _tb_configs(self):
        from .backend.dv import CocotbConfig, TestbenchConfig

        top = self.paths.top
        period = float(self.values.get("CLK_PERIOD", "20"))
        interface = self.values.get("REG_ITF", "tlul")
        sv = TestbenchConfig(
            top=top,
            rtldir=self.paths.rtl,
            simdir=self.paths.sim / "rtl",
            syndir=self.paths.syn,
            prims=self._words("PRIM"),
            clk_period_ns=max(1, int(period)),
            compiler=self.values.get("COMPILER", "verilator"),
            interface=interface,
            vsv=self.values.get("VSV", "sv"),
            output=self.paths.tb / "sv",
            force=self._bool(self.values.get("FORCE")),
        )
        cocotb = CocotbConfig(
            top=top,
            interface=interface,
            output=self.paths.tb / "cocotb",
            rtl_dir=self.paths.rtl,
            ips_root=self.client.project_root / "hw" / "ips",
            simulator=self.values.get("COMPILER", "verilator"),
            period_ns=period,
            vsv=self.values.get("VSV", "sv"),
            force=self._bool(self.values.get("FORCE")),
        )
        return sv, cocotb

    def _rtl_sources(self) -> tuple[Path, ...]:
        sources: list[Path] = []
        for filelist in (self.paths.rtl_common, self.paths.rtl_ip):
            if not filelist.is_file():
                continue
            for line in filelist.read_text(encoding="utf-8").splitlines():
                item = line.strip()
                if item and not item.startswith(("#", "+", "-")):
                    sources.append(Path(item))
        return tuple(sources)

    def _setup_synthesis(self) -> object:
        flow = self.backend.syn.synthesis
        target = self.values.get("TARGET_SYN", "asic").lower()
        period = float(self.values.get("CLK_PERIOD", "20"))
        if target in {"xilinx", "xc7"}:
            return flow.setup_xilinx(top=self.paths.top, topdir=self.paths.rtl, clk_period_ns=period, output=self.paths.syn)
        if target in {"ice40", "ice"}:
            return flow.setup_ice40(top=self.paths.top, topdir=self.paths.rtl, clk_period_ns=period, output=self.paths.syn)
        liberty = Path(self.values["LIB_SYN"])
        return flow.setup_asic(
            top=self.paths.top, topdir=self.paths.rtl, liberty=liberty,
            clk_period_ns=period, output=self.paths.syn,
            opt=self.values.get("TARGET_OPT", "area"),
            filelists=(self.paths.rtl_common, self.paths.rtl_ip),
            tie_hi=self._tuple("TIEHI_CELL_AND_PORT", 2),
            tie_lo=self._tuple("TIELO_CELL_AND_PORT", 2),
            min_buffer=self._tuple("MIN_BUF_CELL_AND_PORTS", 3),
        )

    def _tuple(self, key: str, size: int):
        parts = self._words(key)
        return tuple(parts) if len(parts) == size else None

    def _setup_eqy(self) -> object:
        flow = self.backend.syn.eqy
        layout = self.context.layout
        out = layout.equivalence_dir
        config = out / f"{self.paths.top}_rtl_vs_syn.eqy"
        models = tuple(Path(x) for x in self._words("PRIM"))
        formal_proc = self.values.get("FORMAL_PDK_PROC")
        return flow.setup(
            top=self.paths.top,
            output_dir=out,
            filelists=(self.paths.rtl_common, self.paths.rtl_ip),
            netlist=self.paths.syn / f"{self.paths.top}_synth.v",
            liberty=Path(self.values["LIB_SYN"]),
            cell_models=models,
            clock_gate_model=out / "sky130_clock_gates_formal.v",
            engine=self.values.get("EQY_ENGINE", "sat"),
            depth=int(self.values.get("EQY_DEPTH", "20")),
            sat_depth=int(self.values.get("EQY_SAT_DEPTH", "20")),
            config=config,
            formal_pdk_proc=Path(formal_proc) if formal_proc else None,
            force=self._bool(self.values.get("FORCE")),
            on=self.on,
        )

    def _run_eqy(self) -> int:
        layout = self.context.layout
        return self.backend.syn.eqy.run(
            config=layout.equivalence_dir / f"{self.paths.top}_rtl_vs_syn.eqy",
            log=layout.equivalence_log,
            jobs=int(self.values.get("EQY_JOBS", "1")),
            eqy=self.values.get("EQY", "eqy"),
            on=self.on,
        )

    def _formal_setup(self, *, csr: bool, mode: str) -> Path:
        flow = self.backend.dv.formal
        top = self.paths.top
        props = self.paths.formal / ("csr" if csr else "properties") / mode
        runs = self.paths.formal / "runs" / ("csr" if csr else "properties") / mode
        runs.mkdir(parents=True, exist_ok=True)
        output = runs / f"{top}_{'csr_' if csr else ''}{mode}.sby"
        common = (self.paths.rtl_common, self.paths.rtl_ip)
        kwargs = dict(
            top=top, filelists=common, properties_dir=props, mode=mode,
            engine=self.values.get("FORMAL_PROVE_ENGINE" if mode == "prove" else "FORMAL_COVER_ENGINE", "abc pdr" if mode == "prove" else "btor btormc"),
            output=output, depth=int(self.values.get("FORMAL_DEPTH", "20")),
            bmc_engine=self.values.get("FORMAL_BMC_ENGINE", "smtbmc bitwuzla"),
            bmc_depth=int(self.values.get("FORMAL_BMC_DEPTH", "30")),
            bmc_append=int(self.values.get("FORMAL_BMC_APPEND", "5")),
            multiclock=self.context.clocks.multiclock,
        )
        if csr:
            kwargs["generated"] = props / f"{top}_csr_auto_{mode}.sv"
            return flow.setup_csr(**kwargs)
        return flow.setup_design(**kwargs)

    def _run_formal(self, target: str) -> object:
        flow = self.backend.dv.formal
        top = self.paths.top
        logs = self.paths.logs / "dv" / "formal"
        sby = self.values.get("SBY", "sby")
        if target.startswith("formal_csr_"):
            mode = target.rsplit("_", 1)[-1]
            config = self._formal_setup(csr=True, mode="cover" if mode == "cover" else "prove")
            log = logs / "csr" / f"{top}_{mode}.log"
            return getattr(flow, f"run_csr_{mode}")(config, **({} if mode == "cover" else {"top": top}), log=log, sby=sby, on=self.on)
        mode = target.rsplit("_", 1)[-1]
        config = self._formal_setup(csr=False, mode="cover" if mode == "cover" else "prove")
        log = logs / "properties" / f"{top}_{mode}.log"
        return getattr(flow, f"run_{mode}")(config, **({} if mode == "cover" else {"top": top}), log=log, sby=sby, on=self.on)

    def _setup_pnr(self) -> Path:
        ors_tech = self.values.get("ORS_TECH", self.values.get("PDK", "sky130"))
        return self.backend.impl.setup(
            top=self.paths.top,
            output_dir=self.paths.impl,
            platform=ors_tech,
            netlist=self.paths.syn / f"{self.paths.top}_synth.v",
            sdc_file=self.paths.sdc,
        )

    def _orfs(self) -> tuple[Path, Path]:
        ors = Path(self.values.get("ORS", "")).expanduser()
        makefile = ors / "Makefile"
        return makefile.resolve(), self.paths.impl / "config.mk"

    def _run_pnr(self, *, gui: bool = False) -> int:
        makefile, config = self._orfs()
        log = self.paths.logs / "implementation" / self.paths.pdk / ("gui.log" if gui else "pnr.log")
        if gui:
            return self.backend.impl.view(makefile=makefile, config=config, workdir=self.paths.impl, log=log, on=self.on)
        return self.backend.impl.run(makefile=makefile, config=config, workdir=self.paths.impl, log=log, on=self.on)

    def _report(self, target: str) -> object:
        report = self.backend.reporting
        if target == "metrics":
            return report.write_metrics(self.paths.top, self.paths.run, self.paths.metrics, pdk=self.paths.pdk)
        if target == "manifest":
            return report.write_manifest(top=self.paths.top, run_top=self.paths.run_top, run_id=self.paths.run_id, repo_root=self.client.project_root, output=self.paths.manifest)
        if target == "manifest_show":
            return report.show_manifest(self.paths.manifest)
        return report.check(self.paths.metrics)

    def execute(self, target: str) -> object:
        """Execute one public target without invoking the backend Makefile."""
        b, p, v = self.backend, self.paths, self.values
        top, force = p.top, self._bool(v.get("FORCE"))
        interface = v.get("REG_ITF", "tlul")

        if target.startswith("help"):
            print(TARGETS[target][1])
            return 0
        if target == "setup":
            return p.ensure()
        if target in {"hjson", "hjson_gen"}:
            return b.design.regs.setup_hjson(top, interface, p.data, force=force, clocks=self.context.clocks)
        if target == "reg":
            return b.design.regs.generate_rtl(top, p.data, p.rtl, regmap=v.get("REGMAP"), on=self.on)
        if target == "doc":
            return b.design.regs.generate_docs(top, p.data, p.doc, regmap=v.get("REGMAP"), on=self.on)
        if target == "driver":
            return b.design.regs.generate_driver(p.data / f"{top}.hjson", p.drivers, base_address=v.get("BASE_ADDRESS", "0x0"))
        if target == "regmap_py":
            return b.design.regs.generate_regmap_py(top, p.data, p.model, force=force, refresh_tests=True, clocks=self.context.clocks)
        if target == "rtl_stub":
            hjson = p.data / f"{top}.hjson"
            return b.design.rtl.setup_scaffold(hjson if hjson.exists() else None, interface, p.rtl, top=top, force=force, clocks=self.context.clocks)
        if target == "top_from_core":
            return b.design.rtl.generate_top(top, p.rtl, interface, force=force, clocks=self.context.clocks)
        if target in {"flist", "slang_flist"}:
            return b.design.rtl.generate_filelists(root=self.client.project_root, top_file=p.rtl / f"{top}.sv", common_out=p.rtl_common, ip_out=p.rtl_ip, search_roots=(p.rtl, self.client.project_root / "hw" / "ips", self.client.project_root / "vendor"), common_roots=(self.client.project_root / "hw" / "ips", self.client.project_root / "vendor"), top=top, slang=v.get("SLANG", "slang"), on=self.on)
        if target == "fetch":
            vendor = v.get("VENDOR") or v.get("TARGET")
            if not vendor:
                raise ValueError("fetch requires VENDOR=<name>")
            return b.design.rtl.fetch_vendor(self.client.project_root / "vendor" / f"{vendor}.vendor.hjson", target_dir=self.client.project_root, force=force, on=self.on)
        if target in {"slang_hier", "slang_ast"}:
            root, top_file, search_roots, extra_args = self._slang_inputs()
            output = p.run / "analysis" / "slang" / f"{top}_{'hier.txt' if target == 'slang_hier' else 'ast.json'}"
            if target == "slang_hier":
                return b.design.rtl.show_hierarchy(root=root, top_file=top_file, output=output, search_roots=search_roots, top=v.get("SLANG_TOP", top), extra_args=extra_args, slang_hier=v.get("SLANG_HIER", "slang-hier"), on=self.on)
            return b.design.rtl.show_ast(root=root, top_file=top_file, output=output, search_roots=search_roots, top=v.get("SLANG_TOP", top), extra_args=extra_args, slang=v.get("SLANG", "slang"), scope=v.get("SLANG_AST_SCOPE"), on=self.on)
        if target == "setup_model":
            return b.design.model.flow(top, p.data, p.model, p.rtl, force=force, clocks=self.context.clocks)
        if target in {"setup_tb", "setup_cocotb"}:
            sv, cocotb = self._tb_configs()
            return b.dv.testbench.setup_systemverilog(sv, clocks=self.context.clocks) if target == "setup_tb" else b.dv.testbench.setup_cocotb(cocotb, clocks=self.context.clocks)
        if target in {"tests_gen", "test_gen", "tests"}:
            if target == "tests":
                tests = b.dv.functional.tests(p.tests)
                print("\n".join(tests))
                return tests
            hjson = p.data / f"{top}.hjson"
            if target == "test_gen":
                return b.dv.functional.generate_test(v.get("TEST_NAME", "smoke"), p.tests, top, hjson, force=force)
            return b.dv.functional.generate_tests(p.tests, top, hjson, force=force)

        if target.startswith("lint") or target == "_lint_run":
            kind = target.removeprefix("lint_") if target.startswith("lint_") else "all"
            if target == "lint_slang":
                return b.dv.lint_slang(on=self.on)
            if target == "lint_verilator":
                return b.dv.lint_verilator(on=self.on)
            if target == "lint_slang_suite":
                return b.dv.lint_suite(tools=("slang",), on=self.on)
            if target == "lint_verilator_suite":
                return b.dv.lint_suite(tools=("verilator",), on=self.on)
            if target in {"lint", "lint_suite"}:
                return b.dv.lint_suite(on=self.on)
            if target in {"lint_v", "lint_sv"}:
                return b.dv.lint_verilator(kind="all", on=self.on)
            return b.dv.lint_suite(tools=(v.get("LINT_TOOL", "slang"),), part=v.get("LINT_PART", "ip"), on=self.on) if kind not in {"latch","undriven","width","unconnected","unused"} else (b.dv.lint_slang(kind=kind, part=v.get("LINT_PART","ip"), on=self.on), b.dv.lint_verilator(kind=kind, part=v.get("LINT_PART","ip"), on=self.on))

        if target in {"setup_cdc_rdc", "cdc_rdc"}:
            analysis = p.run / "analysis" / "cdc_rdc"
            script, design_json = analysis / "extract.ys", analysis / "design.json"
            if target == "setup_cdc_rdc":
                return b.dv.cdc.setup(top=top, script=script, design_json=design_json, repo_root=self.client.project_root, filelists=(p.rtl_common, p.rtl_ip))
            return b.dv.cdc.flow_from_context(self.context, on=self.on)

        if target in {"compile", "compile_v", "compile_sv"}:
            return b.dv.functional.compile_systemverilog(top=top, tb_dir=p.tb, sim_dir=p.sim / "rtl", common_filelist=p.rtl_common, ip_filelist=p.rtl_ip, test_name=v.get("TEST_NAME","smoke"), compiler=v.get("COMPILER","verilator"), coverage=self._bool(v.get("COVERAGE")), log=p.logs / "dv" / "functional" / f"{top}_compile.log", on=self.on)
        if target in {"sim", "sim_v", "sim_sv"}:
            return b.dv.functional.run_systemverilog(top=top, test_root=p.tests, tb_dir=p.tb, sim_dir=p.sim / "rtl", test_name=v.get("TEST_NAME","smoke"), compiler=v.get("COMPILER","verilator"), seed=int(v.get("SEED","1")), log=p.logs / "dv" / "functional" / f"{top}_sim_{v.get('TEST_NAME','smoke')}.log", on=self.on)
        if target == "sim_tests":
            return b.dv.functional.run_regression(top=top, test_root=p.tests, tb_dir=p.tb, sim_dir=p.sim / "rtl", common_filelist=p.rtl_common, ip_filelist=p.rtl_ip, rtl_sources=self._rtl_sources(), compiler=v.get("COMPILER","verilator"), backends=("sv",), seed=int(v.get("SEED","1")), log_dir=p.logs / "dv" / "functional", on=self.on)
        if target in {"cocotb", "cocotb_tests"}:
            if target == "cocotb_tests":
                return b.dv.functional.run_regression(top=top, test_root=p.tests, tb_dir=p.tb, sim_dir=p.sim / "rtl", common_filelist=p.rtl_common, ip_filelist=p.rtl_ip, rtl_sources=self._rtl_sources(), compiler=v.get("COMPILER","verilator"), backends=("cocotb",), seed=int(v.get("SEED","1")), log_dir=p.logs / "dv" / "functional", on=self.on)
            return b.dv.functional.run_cocotb(top=top, test_root=p.tests, tb_dir=p.tb, rtl_sources=self._rtl_sources(), test_name=v.get("TEST_NAME","smoke"), simulator=v.get("COMPILER","verilator"), seed=int(v.get("SEED","1")), waves=self._bool(v.get("COCOTB_WAVES"), True), log=p.logs / "dv" / "functional" / f"{top}_cocotb_{v.get('TEST_NAME','smoke')}.log", on=self.on)
        if target == "regression":
            return b.dv.functional.flow_from_context(self.context, on=self.on)
        if target in {"coverage", "coverage_detail"}:
            return b.dv.coverage.flow_from_context(self.context, detail=target == "coverage_detail", on=self.on)

        if target in {"setup_formal", "setup_formal_prove", "setup_formal_cover", "setup_formal_csr_prove", "setup_formal_csr_cover"}:
            b.dv.formal.setup_scaffold(top, p.formal)
            if target == "setup_formal":
                return 0
            csr = "csr" in target
            mode = "cover" if target.endswith("cover") else "prove"
            return self._formal_setup(csr=csr, mode=mode)
        if target in {"formal_bmc", "formal_prove", "formal_cover", "formal_csr_bmc", "formal_csr_prove", "formal_csr_cover"}:
            return self._run_formal(target)
        if target == "formal_csr":
            return (self._run_formal("formal_csr_bmc"), self._run_formal("formal_csr_prove"), self._run_formal("formal_csr_cover"))
        if target == "formal":
            return b.dv.formal.flow_from_context(self.context, on=self.on)

        if target == "setup_syn":
            return self._setup_synthesis()
        if target in {"syn", "syn_v", "syn_sv"}:
            return b.syn.synthesis.run_asic(output=p.syn, top=top, log_dir=p.logs / "synthesis" / p.pdk, opt=v.get("TARGET_OPT","area"), yosys=v.get("YOSYS","yosys"), systemverilog=(target != "syn_v" and v.get("VSV","sv") != "v"), on=self.on)
        if target == "yosys-vgen":
            return b.syn.synthesis.run_yosys_vgen(top=top, cwd=p.run, output=p.rtl / f"{top}.v", yosys=v.get("YOSYS","yosys"), on=self.on)
        if target == "sv2v":
            return 0
        if target == "setup_eqy":
            return self._setup_eqy()
        if target == "eqy":
            return self._run_eqy()

        pre = b.signoff.pre
        post = b.signoff.post
        if target == "setup_signoff":
            return (pre.setup_sdc(), pre.setup_sta(), pre.setup_sdf(), pre.setup_power(), pre.setup_fusion())
        if target == "setup_signoff_post_pnr":
            return (post.setup_sta(), post.setup_sdf(), post.setup_power(), post.setup_fusion())
        if target in {"sta", "sta_corners"}:
            return pre.run_sta(on=self.on)
        if target == "sdf":
            return pre.write_sdf(on=self.on)
        if target in {"power_estimate", "power_estimate_corners"}:
            return pre.run_power_estimate(on=self.on)
        if target == "power_analysis":
            return pre.run_power_activity(all_workloads=False, on=self.on)
        if target == "power_analysis_all":
            return pre.run_power_activity(all_workloads=True, on=self.on)
        if target == "fusion_analysis":
            return pre.run_fusion(all_workloads=False, on=self.on)
        if target == "fusion_analysis_all":
            return pre.run_fusion(all_workloads=True, on=self.on)
        if target == "signoff_corners":
            return (pre.write_sdf(on=self.on), pre.run_sta(on=self.on), pre.run_power_estimate(on=self.on))
        if target in {"compile_syn", "compile_post_syn", "sim_syn", "sim_post_syn", "sim_post_syn_all"}:
            timing = v.get("TIMING_MODE", "zero")
            test = v.get("TEST_NAME", "smoke")
            if target.startswith("compile"):
                return pre.gls.compile(test=test, timing=timing, backend=v.get("GLS_BACKEND","sv"), on=self.on)
            return pre.gls.flow(on=self.on) if target.endswith("_all") else pre.run_gls(test=test, timing=timing, backend=v.get("GLS_BACKEND","sv"), on=self.on)
        if target in {"compile_post_pnr", "sim_post_pnr", "sim_post_pnr_all"}:
            timing = v.get("TIMING_MODE", "zero")
            test = v.get("TEST_NAME", "smoke")
            if target == "compile_post_pnr":
                return post.gls.compile(test=test, timing=timing, backend=v.get("GLS_BACKEND","sv"), on=self.on)
            return post.gls.flow(on=self.on) if target.endswith("_all") else post.run_gls(test=test, timing=timing, backend=v.get("GLS_BACKEND","sv"), on=self.on)
        if target in {"sta_post_pnr"}:
            return post.run_sta(on=self.on)
        if target in {"sdf_post_pnr"}:
            return post.write_sdf(on=self.on)
        if target == "power_estimate_post_pnr":
            return post.run_power_estimate(on=self.on)
        if target == "power_analysis_post_pnr":
            return post.run_power_activity(all_workloads=False, on=self.on)
        if target == "power_analysis_post_pnr_all":
            return post.run_power_activity(all_workloads=True, on=self.on)
        if target == "fusion_analysis_post_pnr":
            return post.run_fusion(all_workloads=False, on=self.on)
        if target == "fusion_analysis_post_pnr_all":
            return post.run_fusion(all_workloads=True, on=self.on)
        if target == "signoff_post_pnr":
            return post.flow(on=self.on)
        if target == "sta_violators":
            return pre.run_sta(on=self.on)
        if target == "path_view":
            path = self._path("PATH_VIEW_FILE", p.signoff / "path_view" / "paths.json")
            return self._run_cmd((sys.executable, str(self.client.project_root / "src" / "util" / "plot_path.py"), str(path)), log=p.logs / "signoff" / p.pdk / "path_view.log", inputs=(path,))

        if target == "setup_pnr":
            return self._setup_pnr()
        if target == "pnr":
            return self._run_pnr()
        if target == "pnr_gui":
            return self._run_pnr(gui=True)
        if target == "physical_signoff":
            makefile, config = self._orfs()
            return post.run_physical(makefile=makefile, config=config, workdir=p.impl, top=top, output=p.signoff / "physical" / "summary.json", log=p.logs / "signoff" / p.pdk / "physical" / "physical_signoff.log", on=self.on)

        if target in {"metrics", "manifest", "manifest_show", "check"}:
            return self._report(target)
        if target == "ip_load":
            return b.package.load(
                ip_name=v.get("IP_NAME", top), run_top=p.run_top, run_id=p.run_id,
                workspace=self.client.workdir, load_as=v.get("LOAD_AS") or None,
            )
        if target == "ip_save":
            eqy = self.context.layout.equivalence_dir
            model_paths = tuple(Path(item) for item in self._words("PRIM"))
            return b.package.save(
                ip_name=v.get("IP_NAME", top), top=top, pdk=p.pdk,
                library_root=Path(v.get("IP_LIBRARY_ROOT", self.client.project_root / "hw" / "ips")),
                synth_dir=p.syn, signoff_dir=p.signoff, sdc_file=p.sdc,
                eqy_config=eqy / f"{top}_rtl_vs_syn.eqy",
                eqy_view=eqy / f"{top}_eqy_view.sv",
                filelists=(p.rtl_common, p.rtl_ip), netlist=p.syn / f"{top}_synth.v",
                liberty=Path(v["LIB_SYN"]), cell_models=model_paths,
                clock_gate_model=eqy / "sky130_clock_gates_formal.v",
                impl_dir=p.impl if p.impl.is_dir() else None,
                post_syn_sim_dir=self.context.layout.post_syn_sim_dir,
                coverage_dir=p.coverage, manifest_json=p.manifest, metrics_json=p.metrics,
                force=force,
            )

        if target in {"soc_cfg", "soc_start"} or target.startswith(("soc_", "fsoc", "xbar", "sw_soc")) or target == "soc":
            return self._soc(target)
        if target.startswith("fsm"):
            return self._fsm(target)
        if target.startswith("deps"):
            action = {"deps-bootstrap":"bootstrap","deps":"install","deps-doctor":"doctor","deps-versions":"versions","deps-env":"env","deps-status":"status","deps-prune":"prune"}[target]
            return b.toolchain.deps(action, profile=v.get("DEPS_PROFILE","base"), jobs=int(v.get("DEPS_JOBS","2")), apply=self._bool(v.get("DEPS_PRUNE_APPLY")), prune_cache=self._bool(v.get("DEPS_PRUNE_CACHE")), on=self.on)
        if target.startswith("clean"):
            return self._clean(target)
        if target.endswith("tutorial") or target in {"soc_ibex_fetch", "soc_pless", "full_tutorial"}:
            return self._tutorial(target)
        if target in {"view", "view_cocotb", "view_syn", "plot_postsyn", "view_presyn", "view_presyn_v", "view_presyn_sv", "tb_save", "tb_view"}:
            return self._view(target)
        if target in {"ip_start", "ip_flow", "ip_flow_noreg", "ip_flow_all"}:
            return self._ip_flow(target)
        raise NotImplementedError(f"direct target mapping missing: {target}")

    def _view(self, target: str) -> int:
        """Open or save one viewer artifact without Make indirection."""
        import shutil
        p, v = self.paths, self.values
        if target == "tb_save":
            destination = p.functional / "saved"
            destination.mkdir(parents=True, exist_ok=True)
            for source in p.tb.rglob("*"):
                if source.is_file():
                    out = destination / source.relative_to(p.tb)
                    out.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(source, out)
            return 0
        if target == "tb_view":
            print(p.functional / "saved")
            return 0
        patterns = ["*.fst", "*.vcd"]
        candidates = [x for pat in patterns for x in p.functional.rglob(pat)]
        if not candidates:
            raise FileNotFoundError("no waveform available")
        wave = max(candidates, key=lambda x: x.stat().st_mtime)
        viewer = v.get("WAVE_VIEWER", "surfer")
        return self._run_cmd((viewer, str(wave)), cwd=wave.parent, log=p.logs / "viewer" / f"{target}.log", inputs=(wave,))

    def _clean(self, target: str) -> int:
        """Remove only artifacts owned by the selected cleanup operation."""
        import shutil

        p = self.paths

        def remove_contents(path: Path) -> None:
            if not path.is_dir():
                return
            for item in path.iterdir():
                if item.is_dir() and not item.is_symlink():
                    shutil.rmtree(item, ignore_errors=True)
                else:
                    item.unlink(missing_ok=True)

        def remove_globs(path: Path, *patterns: str) -> None:
            if not path.is_dir():
                return
            for pattern in patterns:
                for item in path.glob(pattern):
                    if item.is_dir() and not item.is_symlink():
                        shutil.rmtree(item, ignore_errors=True)
                    else:
                        item.unlink(missing_ok=True)

        if target == "clean-pyc":
            for directory in self.client.project_root.rglob("__pycache__"):
                shutil.rmtree(directory, ignore_errors=True)
            for file in self.client.project_root.rglob("*.py[co]"):
                file.unlink(missing_ok=True)
            for directory in (
                self.client.project_root / ".pytest_cache",
                self.client.project_root / ".ruff_cache",
            ):
                shutil.rmtree(directory, ignore_errors=True)
            return 0

        if target == "clean_doc":
            remove_contents(p.doc)
        elif target == "clean_log":
            remove_contents(p.logs)
        elif target == "clean_rtl":
            remove_globs(p.rtl, "*.v")
        elif target == "clean_sim":
            remove_globs(p.sim, "*.vvp", "*.vcd", "*.fst")
            shutil.rmtree(p.sim / "verilator", ignore_errors=True)
        elif target == "clean_cocotb":
            cocotb = p.tb / "cocotb"
            remove_globs(cocotb, "*.vcd", "*.fst", "__pycache__", "*.pyc")
            shutil.rmtree(cocotb / "sim_build", ignore_errors=True)
        elif target == "clean_formal":
            shutil.rmtree(p.formal, ignore_errors=True)
            shutil.rmtree(p.logs / "dv" / "formal", ignore_errors=True)
        elif target == "clean_syn":
            shutil.rmtree(p.syn, ignore_errors=True)
            shutil.rmtree(p.logs / "synthesis" / p.pdk, ignore_errors=True)
        elif target == "clean_signoff":
            shutil.rmtree(p.signoff, ignore_errors=True)
            shutil.rmtree(p.logs / "signoff" / p.pdk, ignore_errors=True)
        elif target == "clean_meta":
            remove_contents(p.meta)
        elif target == "clean_pnr":
            shutil.rmtree(p.impl, ignore_errors=True)
            shutil.rmtree(p.logs / "pnr" / p.pdk, ignore_errors=True)
        elif target in {"clean_fsm", "clean_fsm_all", "clean_subdir"}:
            from .backend.design.fsm_gen import FsmFlow

            flow = FsmFlow(p.run, self.runner)
            name = self.values.get("FSM", "fsm_example")
            if target == "clean_subdir":
                flow.clean(name)
                flow.setup(name)
            else:
                flow.clean(name, inputs=target == "clean_fsm_all")
        elif target == "clean_fsoc":
            shutil.rmtree(self.client.project_root / "build", ignore_errors=True)
            shutil.rmtree(p.run / "fusesoc", ignore_errors=True)
        elif target == "clean_soc":
            for name in ("trace_core_00000000.log", "uart0.log", "soc.core", "xbar_main.hjson"):
                (self.client.project_root / name).unlink(missing_ok=True)
            remove_globs(self.client.project_root, "sim.fst*")
            remove_globs(self.client.project_root / "sw", "*.elf", "*.o", "*.csv")
            remove_globs(self.client.project_root / "tb", "top_verilator.*")
            shutil.rmtree(p.run / "soc", ignore_errors=True)
        elif target == "clean_sw":
            remove_globs(p.run / "sw", "*.elf", "*.o", "*.csv")
        elif target == "clean_vendor":
            vendor = self.client.project_root / "vendor"
            for name in ("lowrisc_ip", "lowrisc_ibex"):
                shutil.rmtree(vendor / name, ignore_errors=True)
                (vendor / f"{name}.lock.hjson").unlink(missing_ok=True)
        elif target == "clean_agent":
            shutil.rmtree(self.client.project_root / "flexsoc_make_agent", ignore_errors=True)
        elif target == "clean_all":
            shutil.rmtree(p.run, ignore_errors=True)
            default = self.client.workdir / "runs" / p.run_top / "default"
            if default != p.run:
                shutil.rmtree(default, ignore_errors=True)
            for name in ("build", "dist", ".pytest_cache", ".mypy_cache", ".ruff_cache"):
                shutil.rmtree(self.client.project_root / name, ignore_errors=True)
            self._clean("clean-pyc")
        elif target == "clean":
            for name in (
                "clean-pyc", "clean_log", "clean_rtl", "clean_sim", "clean_syn",
                "clean_signoff", "clean_meta", "clean_pnr", "clean_subdir",
                "clean_fsoc", "clean_soc", "clean_fsm",
            ):
                self._clean(name)
        return 0

    def _fsm(self, target: str) -> object:
        """Dispatch FSM targets to the run-local reusable generator."""
        from .backend.design.fsm_gen import FsmFlow
        p, v = self.paths, self.values
        name = v.get("FSM", "fsm_example")
        flow = FsmFlow(p.run, self.runner)
        if target in {"fsm_init", "fsm_setup"}:
            return flow.setup(name)
        if target == "fsm_example_load":
            return flow.load_example(name)
        if target == "fsm_gen":
            return flow.generate(name, clock_mhz=int(v.get("F_CLK","32")))
        if target == "fsm_plot":
            return flow.plot(name, on=self.on)
        if target == "fsm_flow":
            return flow.flow(name, clock_mhz=int(v.get("F_CLK","32")), plot=True, on=self.on)
        if target in {"fsm_install", "fsm2rtl"}:
            return flow.install(name, rtl_dir=p.rtl, tb_dir=p.tb / "sv", sim_dir=p.sim / "rtl")
        raise ValueError(target)

    def _soc(self, target: str) -> object:
        """Dispatch SoC generation and external tools through SocFlow."""
        from .backend.design.soc import SoCGenerationConfig, SoCModule, SoCSoftwareConfig, SoCStartConfig, XbarConfig, parse_device_rows
        p, v, soc = self.paths, self.values, self.backend.design.soc
        host = v.get("HOST", "uart")
        if target == "soc_start":
            return soc.start(SoCStartConfig(self.client.workdir, p.run_top, p.run_id))
        if target == "soc_cfg":
            cfg = soc.resolve_config(workspace=self.client.workdir, run_top=p.run_top, run_id=p.run_id, default_host=host, mode=v.get("SOC_CFG_MODE","builtin"))
            print(cfg)
            return cfg
        if target == "sw_soc":
            return soc.generate_software(SoCSoftwareConfig(self.client.workdir, p.run_top, p.run_id, host))
        if target == "fsoc_init":
            return soc.generate_fusesoc(v.get("PRJ","flexsoc"), p.top, p.rtl, p.run / "fusesoc" / host / "cores")
        if target == "soc_vendor_deps":
            for vendor in ("lowrisc_ip", "lowrisc_ibex"):
                if not (self.client.project_root / "vendor" / vendor).is_dir():
                    old = self.values.get("VENDOR")
                    self.values["VENDOR"] = vendor
                    self.execute("fetch")
                    if old is None:
                        self.values.pop("VENDOR", None)
                    else:
                        self.values["VENDOR"] = old
            return 0
        if target in {"xbar_init", "xbar"}:
            cfg = soc.resolve_config(workspace=self.client.workdir, run_top=p.run_top, run_id=p.run_id, default_host=host, mode=v.get("SOC_CFG_MODE","builtin"))
            devices = tuple(parse_device_rows([list(device.args()) for device in cfg.devices]))
            out = p.run / "soc" / "xbar.hjson"
            result = soc.init_xbar(XbarConfig(host, devices), out)
            if target == "xbar":
                self._soc("xbar_build")
            return result
        if target == "xbar_build":
            cfg = p.run / "soc" / "xbar.hjson"
            out = p.rtl / "xbar"
            out.mkdir(parents=True, exist_ok=True)
            return soc.run_tool((sys.executable, str(self.client.project_root / "src" / "util" / "tlgen.py"), "-t", str(out), str(cfg)), cwd=self.client.project_root, log=p.logs/"soc"/"xbar.log", inputs=(cfg,), outputs=(out,), on=self.on).returncode
        if target in {"soc", "soc_uart_gen", "soc_ibex_gen"}:
            cfg = soc.resolve_config(self.client.workdir, p.run_top, p.run_id, host=("ibex" if target == "soc_ibex_gen" else "uart" if target == "soc_uart_gen" else host), mode=v.get("SOC_CFG_MODE","builtin"))
            devices = tuple(SoCModule(d.name, d.base, d.size, d.from_lr.strip().lower() in {"1", "true", "yes", "on"}) for d in cfg.devices)
            return soc.generate(SoCGenerationConfig(cfg.host, devices, p.run, p.rtl / "soc.sv"))
        if target in {"soc_flist", "soc_stage_tops"}:
            return self.execute("flist")
        if target == "soc_flow":
            return (self._soc("xbar"), self._soc("soc"), self._soc("soc_flist"))
        if target in {"fsoc", "soc_sim", "soc_prepare"}:
            root = p.run / "fusesoc" / host
            argv=(v.get("FUSESOC","fusesoc"), f"--cores-root={self.client.project_root}", f"--cores-root={root/'cores'}", "run", "--setup", "--build", "--target", v.get("TARGET","sim" if target != "fsoc" else "default"), "--build-root", str(root/"build"), v.get("SOC_CORE_VLNV","enea:soc:main"))
            return soc.run_tool(argv, cwd=root, log=p.logs/"soc"/f"{target}.log", on=self.on).returncode
        if target == "soc_build_sw":
            self._soc("soc_prepare")
            self._soc("sw_soc")
            return soc.run_tool(("make", "-C", str(p.run/"sw")), cwd=p.run, log=p.logs/"soc"/"build_sw.log", on=self.on).returncode
        if target in {"soc_run", "soc_run_only"}:
            exe=p.run/"fusesoc"/host/"build"/"sim-verilator"/"Vtop_verilator"
            return soc.run_tool((str(exe),), cwd=exe.parent, log=p.logs/"soc"/"run.log", inputs=(exe,), on=self.on).returncode
        if target == "soc_view":
            return self._view("view")
        raise ValueError(target)

    def _tutorial(self, target: str) -> object:
        """Compose tutorials from real flow operations instead of Make recipes."""
        sequences = {
            "soc_ibex_fetch": ("fetch",),
            "full_tutorial": ("ip_start", "ip_flow", "pnr", "pnr_gui"),
            "fsm_tutorial": ("setup", "fsm_setup", "fsm_example_load", "fsm_gen", "fsm_plot", "fsm2rtl", "ip_flow_noreg"),
            "ip_tutorial": ("ip_load", "flist", "sim", "syn", "sdf", "sta", "sta_violators", "power_estimate", "view"),
            "soc_pless": ("ip_load", "flist", "sim", "syn", "sdf", "sta", "power_estimate", "view"),
        }
        if target == "soc_uart_tutorial":
            return self._soc("soc_run")
        if target == "soc_ibex_tutorial":
            self._tutorial("soc_ibex_fetch")
            return self._soc("soc_run")
        sequence = sequences.get(target)
        if sequence is None:
            raise ValueError(target)
        return tuple(self.execute(name) for name in sequence)

    def _ip_flow(self, target: str) -> object:
        """Compose high-level IP flows from the new domain APIs."""
        if target == "ip_start":
            sequence = (
                "setup", "hjson", "reg", "doc", "rtl_stub", "top_from_core",
                "flist", "driver", "setup_model", "setup_tb", "setup_cocotb",
                "tests_gen",
            )
        elif target == "ip_flow_noreg":
            sequence = (
                "flist", "lint_suite", "setup_cdc_rdc", "cdc_rdc", "regression",
                "coverage_detail", "formal", "setup_syn", "syn", "setup_eqy", "eqy",
                "signoff_corners", "manifest", "manifest_show", "metrics", "check",
            )
        elif target == "ip_flow":
            sequence = (
                "reg", "doc", "flist", "lint_suite", "setup_cdc_rdc", "cdc_rdc",
                "regression", "coverage_detail", "formal", "setup_syn", "syn",
                "setup_eqy", "eqy", "signoff_corners", "manifest", "manifest_show",
                "metrics", "check",
            )
        else:
            sequence = ("ip_flow", "pnr", "pnr_gui")
        return tuple(self.execute(name) for name in sequence)

# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------

class FlexSoC:
    """Configure and execute FlexSoC backend targets."""

    def __init__(
        self,
        config: FlexSoCConfig | None = None,
        project_root: PathLike = None,
        workdir: PathLike = None,
        execution_targets: Mapping[str, Any] | None = None,
        **values: Any,
    ) -> None:
        """Create a client with paths and initial backend settings."""

        base = config or FlexSoCConfig()
        self.config = FlexSoCConfig(
            project_root if project_root is not None else base.project_root,
            workdir if workdir is not None else base.workdir,
            base.make_values(),
        )
        known = set(DEFAULT_SETTINGS) | {key for _, _, params in TARGETS.values() for key in params}
        env_values = {key: os.environ[f"FLEXSOC_{key}"] for key in known if f"FLEXSOC_{key}" in os.environ}
        self.settings = _upper({**self.config.make_values(), **env_values, **values})
        self.execution_targets = dict(execution_targets or {}) or None

    @property
    def project_root(self) -> Path:
        """Return the repository root used as cwd."""

        return _path(self.config.project_root, Path.cwd())

    @property
    def workdir(self) -> Path:
        """Return the canonical FlexSoC workspace directory."""

        return _path(self.config.workdir, self.project_root / "workspace")

    def flows(self, **overrides: Any):
        """Return the reusable object-oriented backend for this configuration."""

        from .backend import Backend, BackendContext
        from .backend.core import ToolRunner

        values = self.values(overrides)
        context = BackendContext(self.project_root, self.workdir, values)
        runner = ToolRunner(self.execution_targets, project_root=self.project_root)
        return Backend(context, runner)

    def describe(self) -> dict[str, Any]:
        """Return the current client configuration."""

        return {
            "package": "flexsoc",
            "project_root": str(self.project_root),
            "workdir": str(self.workdir),
            "settings": dict(self.settings),
        }

    def set(self, **values: Any) -> "FlexSoC":
        """Update default backend settings in place."""

        self.settings.update(_upper(values))
        return self

    def override(self, **values: Any) -> "FlexSoC":
        """Return a copy with extra backend-setting defaults."""

        return FlexSoC(
            FlexSoCConfig(self.project_root, self.workdir, self.settings),
            execution_targets=self.execution_targets,
            **values,
        )

    def targets(self) -> tuple[FlexSoCTarget, ...]:
        """List every backend target exposed by fx."""

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
            from .backend.core import make_overrides

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
        from .backend.core import clock_config
        from .backend.core import pdk_make_paths

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
        """Build one direct fx command preview without executing it."""
        name = _target(target)
        if name in POST_PNR_SIGNOFF_TARGETS:
            overrides = {**overrides, "SIGNOFF_STAGE": "post_route"}
        values = self.values(overrides)
        params = set(TARGETS[name][2])
        call_values = _upper(overrides)
        shown = {key: value for key, value in {**self.settings, **call_values}.items() if key in params}
        argv = ("fx", name, *(item for key, value in sorted(shown.items()) for item in ("--set", f"{key}={value}")))
        return FlexSoCCommand(name, argv, self.project_root, self._env(values), values)

    def commands(
        self,
        *targets: str,
        auto_setup: bool = True,
        **overrides: Any,
    ) -> tuple[FlexSoCCommand, ...]:
        """Build commands in user order, including setup steps by default."""

        requested = tuple(_target(target) for target in targets)
        expanded: list[str] = []
        seen: set[str] = set()

        def dependencies(target: str) -> tuple[str, ...]:
            return AUTO_SETUP_TARGETS.get(target, ())

        def append(target: str) -> None:
            if target in seen:
                return
            if auto_setup:
                for setup in dependencies(target):
                    append(setup)
            expanded.append(target)
            seen.add(target)

        for target in requested:
            append(target)
        return tuple(self.command(target, **overrides) for target in expanded)

    def run(
        self,
        *targets: str,
        check: bool = True,
        dry_run: bool = False,
        capture: bool = False,
        live: bool = False,
        auto_setup: bool = True,
        on: str = "local",
        **overrides: Any,
    ) -> tuple[FlexSoCCommand | FlexSoCResult, ...]:
        """Execute targets directly through backend flow objects."""
        commands = self.commands(*targets, auto_setup=auto_setup, **overrides)
        if dry_run:
            return commands

        for command in commands:
            self._preflight(command)

        import contextlib
        import io

        from .backend.core.execution import (
            print_label,
            print_log,
            print_target_result,
            print_target_start,
            strip_ansi,
        )

        class _Stream(io.TextIOBase):
            """Mirror backend output to a plain log and an optional console."""

            def __init__(self, log, console, *, compact: bool = False):
                self.log = log
                self.console = console
                self.compact = compact

            def write(self, text: str) -> int:
                plain = strip_ansi(text)
                self.log.write(plain)
                self.log.flush()
                if self.console is not None:
                    visible = not self.compact or plain.lstrip().startswith(("[script]", "[report]"))
                    if visible:
                        self.console.write(text)
                        self.console.flush()
                return len(text)

            def flush(self) -> None:
                if not self.log.closed:
                    self.log.flush()
                if self.console is not None:
                    self.console.flush()

        results: list[FlexSoCResult] = []
        for command in commands:
            _, description, _ = TARGETS.get(command.target, ("Target", "Run target", ()))
            stream = command.target in STREAM_BY_DEFAULT_TARGETS and not capture and not live
            quiet = command.target in QUIET_BY_DEFAULT_TARGETS and not capture and not live
            log_path = self._command_log_path(command)
            log_path.parent.mkdir(parents=True, exist_ok=True)

            stdout = io.StringIO() if capture else None
            stderr = io.StringIO() if capture else None
            rc, error = 0, None

            if not capture:
                print_target_start(command.target, description)
                if command.target in TECHNOLOGY_TARGETS and not live and not stream:
                    print_label(
                        "technology",
                        f"pdk={command.values.get('PDK')} syn={command.values.get('SYNDIR')}",
                    )
                if live or stream or quiet:
                    print_log(log_path)

            try:
                with log_path.open("w", encoding="utf-8") as log, contextlib.ExitStack() as stack:
                    if capture:
                        stack.enter_context(contextlib.redirect_stdout(stdout))
                        stack.enter_context(contextlib.redirect_stderr(stderr))
                    else:
                        console = None if quiet else sys.stdout
                        writer = _Stream(log, console, compact=stream)
                        stack.enter_context(contextlib.redirect_stdout(writer))
                        stack.enter_context(contextlib.redirect_stderr(writer))

                    previous = {
                        "FLEXSOC_LIVE": os.environ.get("FLEXSOC_LIVE"),
                        "PYTHONUNBUFFERED": os.environ.get("PYTHONUNBUFFERED"),
                    }
                    os.environ["FLEXSOC_LIVE"] = "1" if live else "0"
                    os.environ["PYTHONUNBUFFERED"] = "1"
                    try:
                        value = _TargetRouter(self, command.values, on=on).execute(command.target)
                        rc = self._returncode(value)
                    finally:
                        for key, value in previous.items():
                            if value is None:
                                os.environ.pop(key, None)
                            else:
                                os.environ[key] = value

                    if capture:
                        log.write(strip_ansi((stdout.getvalue() if stdout else "") + (stderr.getvalue() if stderr else "")))
            except Exception as exc:
                rc, error = 2, exc
                if capture and stderr is not None:
                    stderr.write(str(exc) + "\n")
                    log_path.write_text(
                        strip_ansi((stdout.getvalue() if stdout else "") + stderr.getvalue()),
                        encoding="utf-8",
                    )

            if not capture:
                print_target_result(command.target, rc)
            result = FlexSoCResult(
                command,
                rc,
                stdout.getvalue() if stdout else None,
                stderr.getvalue() if stderr else None,
                log_path,
            )
            results.append(result)
            if error is not None and check:
                raise RuntimeError(f"target '{command.target}' failed: {error}") from error
            if rc and check:
                raise RuntimeError(f"target '{command.target}' failed with exit code {rc}")
        return tuple(results)

    @staticmethod
    def _returncode(value: object) -> int:
        """Normalize nested backend results to one target return code."""
        if value is None or isinstance(value, (Path, str, dict)):
            return 0
        if isinstance(value, bool):
            return 0 if value else 1
        if isinstance(value, int):
            return value
        if hasattr(value, "returncode"):
            return int(getattr(value, "returncode"))
        if isinstance(value, (tuple, list)):
            return next((rc for item in value if (rc := FlexSoC._returncode(item))), 0)
        return 0

    def _preflight(self, command: FlexSoCCommand) -> None:
        """Validate technology requirements before any target mutates the run."""
        if command.target not in TECHNOLOGY_TARGETS:
            return
        root = command.values.get("PDK_ROOT")
        if root and Path(root).expanduser().is_dir() and command.values.get("LIB_SYN"):
            return
        pdk = command.values.get("PDK", DEFAULT_SETTINGS["PDK"])
        raise RuntimeError(
            f"target {command.target!r} requires an activated digital PDK; {pdk!r} is not ready. "
            f"Run `fx pdk fetch {pdk}` then `fx pdk use {pdk}`."
        )

    def _command_log_path(self, command: FlexSoCCommand) -> Path:
        """Return the per-target command log path."""

        values = command.values
        workspace = Path(values.get("WORKSPACE", str(self.workdir)))
        run_top = values.get("RUN_TOP") or values.get("TOP") or "run"
        run_id = values.get("RUN_ID", "default")
        name = _safe_log_name(command.target)
        if command.target in {"sim", "sim_v", "sim_sv", "cocotb"} and values.get("TEST_NAME"):
            name = f"{name}_{_safe_log_name(values['TEST_NAME'])}"
        if command.target in {"sim_post_syn_all", "sim_post_pnr_all"}:
            selectors = [
                ("tests", values.get("TEST_NAMES", "all")),
                ("timing", _scenario_log_value(values.get("TIMING_MODES", "all"))),
            ]
            backend = values.get("GLS_BACKEND", DEFAULT_SETTINGS["GLS_BACKEND"])
            if backend != DEFAULT_SETTINGS["GLS_BACKEND"]:
                selectors.insert(1, ("backend", backend))
            suffix = _selector_log_suffix(tuple(selectors))
            if suffix:
                name = f"{name}_{suffix}"
        elif command.target in NATIVE_TARGETS and values.get("TEST_NAME"):
            name = "_".join(
                (
                    name,
                    _safe_log_name(values["TEST_NAME"]),
                    _safe_log_name(values.get("GLS_BACKEND", "sv")),
                    _safe_log_name(_scenario_log_value(values.get("TIMING_MODE", "zero"))),
                )
            )
        if command.target in ACTIVITY_ANALYSIS_TARGETS:
            if command.target.endswith("_all"):
                suffix = _selector_log_suffix(
                    (
                        ("tests", values.get("POWER_TEST_NAMES", "all")),
                        ("backends", values.get("POWER_GLS_BACKENDS", "all")),
                        ("timing", _scenario_log_value(values.get("POWER_TIMING_MODES", "all"))),
                    )
                )
                if suffix:
                    name = f"{name}_{suffix}"
            else:
                selectors = (
                    values.get("POWER_TEST_NAME", values.get("TEST_NAME", "smoke")),
                    values.get("POWER_GLS_BACKEND", "sv"),
                    _scenario_log_value(values.get("POWER_TIMING_MODE", "typ")),
                )
                name = "_".join((name, *(_safe_log_name(value) for value in selectors)))
        if command.target in TECHNOLOGY_TARGETS and values.get("COMMAND_LOGDIR"):
            return Path(values["COMMAND_LOGDIR"]) / f"{name}.log"
        return workspace / "runs" / run_top / run_id / "logs" / "commands" / f"{name}.log"

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
        # EQY closure knobs are project settings, not ambient process state.
        # Remove inherited EQY_* values first so a stale shell export cannot
        # silently replace the configured SAT -> SMTBMC -> PDR portfolio.
        for key in tuple(env):
            if key.startswith("EQY_"):
                env.pop(key)
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
