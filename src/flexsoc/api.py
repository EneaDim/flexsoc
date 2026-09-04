"""Public FlexSoC API over the object-oriented backend flow."""

from __future__ import annotations

import hashlib
import json
import os
import re
import shlex
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping, Sequence

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
    "TARGET_OPT": "delay1",
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
SDC_INTENT = (*BASE, "FORCE", "SDC_IO_DELAY_PCT")
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
VIEW = (*COMMON, "PDK", "SIGNOFF_STAGE", "SIM_NAME", "WAVE_VIEWER", "SURFER_BACKEND")
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
    "SDC_IO_DELAY_PCT",
    "SDC_CLOCK_PERIOD_NS",
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
PROVENANCE = (*COMMON, "STAGE")
DEPS = ("DEPS_MODE", "DEPS_PROFILE", "DEPS_JOBS", "DEPS_PRUNE_APPLY", "DEPS_PRUNE_CACHE")


# ---------------------------------------------------------------------------
# Target catalogue: one row per callable lifecycle operation
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
    "signoff": ("Signoff", "Run SDF, multi-corner STA and estimated power", SIGNOFF),
    "hjson": ("IP flow", "Generate an HJSON register template", IP_DEV),
    "sdc": ("IP flow", "Initialize the canonical authored <TOP>.sdc timing intent", SDC_INTENT),
    "model": ("DV functional", "Generate Python model, CSR regmap, and test scaffolds", SIM),
    "tb": ("DV functional", "Generate a SystemVerilog testbench scaffold", SIM),
    "reg": ("IP flow", "Generate register RTL from HJSON", IP_DEV),
    "doc": ("IP flow", "Generate register documentation", IP_DEV),
    "systemrdl": ("Interchange", "Export register maps as SystemRDL", IP_DEV),
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
    "view": ("Viewing", "Open selected or latest waveform", VIEW),
    "view_cocotb": ("Viewing", "Open latest cocotb waveform", VIEW),
    "view_syn": ("Viewing", "Reserved synthesis waveform viewer target", VIEW),
    "plot_postsyn": ("Viewing", "Open post-synthesis graph", VIEW),
    "view_presyn": ("Viewing", "Open pre-synthesis graph", VIEW),
    "view_presyn_v": ("Viewing", "Open pre-synthesis graph from Verilog", VIEW),
    "view_presyn_sv": ("Viewing", "Open pre-synthesis graph from SV", VIEW),
    "tb_save": ("Viewing", "Save testbench regression artifacts", VIEW),
    "tb_view": ("Viewing", "Open saved testbench waveform", VIEW),
    "syn": ("Synthesis", "Run synthesis", SYN),
    "syn_v": ("Synthesis", "Run Verilog synthesis", SYN),
    "syn_sv": ("Synthesis", "Run SystemVerilog synthesis", SYN),
    "yosys-vgen": ("Synthesis", "Convert SV to Verilog with Yosys", SYN),
    "sv2v": ("Synthesis", "Convert SV to Verilog with sv2v", SYN),
    "formal_csr_bmc": ("DV formal", "Bounded-check automatic CSR assertions", FORMAL),
    "formal_csr_prove": ("DV formal", "Prove automatic CSR semantics with SymbiYosys", FORMAL),
    "formal_csr_cover": ("DV formal", "Reach automatic CSR cover points with SymbiYosys", FORMAL),
    "formal_csr": ("DV formal", "Run CSR BMC, prove, then cover", FORMAL),
    "formal": ("DV formal", "Run all formal stages BMC, prove, then cover", FORMAL),
    "formal_bmc": ("DV formal", "Bounded-check authored design assertions", FORMAL),
    "formal_prove": ("DV formal", "Prove authored properties with SymbiYosys", FORMAL),
    "formal_cover": ("DV formal", "Reach authored cover properties with SymbiYosys", FORMAL),
    "eqy": ("Signoff", "Prove RTL equivalent to the post-synthesis netlist with EQY", EQUIV),
    "compile_syn": ("Signoff", "Compile post-synthesis simulation", SIGNOFF),
    "sim_syn": ("Signoff", "Run post-synthesis simulation", SIGNOFF),
    "compile_post_syn": ("Gate simulation", "Compile post-synthesis gate-level simulation with Icarus", GATE_SIM),
    "sim_post_syn": ("Gate simulation", "Run post-synthesis gate-level simulation with optional SDF", GATE_SIM),
    "sim_post_syn_all": ("Gate simulation", "Run every selected post-synthesis GLS test/timing combination with one backend", GATE_SIM_ALL),
    "compile_post_pnr": ("Gate simulation", "Compile post-PnR gate-level simulation with Icarus", GATE_SIM),
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
    "metrics": ("Run metadata", "Collect and save functional/formal/synthesis/signoff metrics", COMMON),
    "manifest": ("Run metadata", "Collect automatic run identity into meta/manifest.json", COMMON),
    "manifest_show": ("Run metadata", "Show the current run manifest in color", COMMON),
    "check": ("Run metadata", "Show saved metrics as the complete technical closure dashboard", COMMON),
    "status": ("Run metadata", "Show live Digital IP Contract and release qualification status", COMMON),
    "validate_override": (
        "Run metadata", "Accept modified generated collateral for the current lineage", PROVENANCE
    ),
    "pnr": ("Implementation", "Run OpenROAD implementation", PNR),
    "pnr_gui": ("Implementation", "Open OpenROAD GUI", PNR),
    "physical_signoff": ("Post Sign-Off", "Run ORFS physical closure checks within post-implementation sign-off", PNR),
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
    """Store project paths and default FlexSoC settings."""

    project_root: PathLike = None
    workdir: PathLike = None
    values: Mapping[str, Any] = field(default_factory=dict)


@dataclass(frozen=True, slots=True)
class FlexSoCTargetInfo:
    """Describe one callable FlexSoC target."""

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
    """Preview one direct ``fx`` invocation."""

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
    """Normalize setting names to uppercase strings."""

    return {str(key).upper(): str(value) for key, value in values.items() if value is not None}


def _safe_log_name(value: str) -> str:
    """Return a filesystem-safe log filename fragment."""

    safe = re.sub(r"[^A-Za-z0-9_.-]+", "_", str(value).strip())
    return safe.strip("._") or "target"


def _select_waveform(directory: Path, top: str, sim_name: str = "") -> Path:
    """Select one waveform by explicit name, rejecting ambiguous fallbacks."""

    candidates = [path for pattern in ("*.fst", "*.vcd") for path in directory.rglob(pattern)]
    if not candidates:
        raise FileNotFoundError(
            f"no waveform available in {directory}; run the matching simulation first"
        )
    if not sim_name:
        if len(candidates) == 1:
            return candidates[0]
        names = ", ".join(sorted(path.relative_to(directory).as_posix() for path in candidates))
        raise FileNotFoundError(f"ambiguous waveform in {directory}; set SIM_NAME; candidates: {names}")

    requested = Path(sim_name).name
    if Path(requested).suffix.lower() in {".fst", ".vcd"}:
        requested = Path(requested).stem
    stems = {requested, f"{top}_tb_{requested}"}
    matches = [path for path in candidates if path.stem in stems]
    if len(matches) == 1:
        return matches[0]
    if len(matches) > 1:
        names = ", ".join(sorted(path.relative_to(directory).as_posix() for path in matches))
        raise FileNotFoundError(f"SIM_NAME={sim_name!r} is ambiguous in {directory}: {names}")

    prefix = f"{top}_tb_"
    available = ", ".join(sorted(path.stem.removeprefix(prefix) for path in candidates))
    raise FileNotFoundError(
        f"SIM_NAME={sim_name!r} not found in {directory}; available: {available or 'none'}"
    )


def _viewer_environment(viewer: str, surfer_backend: str = "auto") -> dict[str, str]:
    """Return viewer-specific environment overrides."""

    if Path(viewer).name.lower().removesuffix(".exe") != "surfer":
        return {}
    backend = surfer_backend.strip().lower() or "auto"
    if backend not in {"auto", "x11", "wayland"}:
        raise ValueError("SURFER_BACKEND must be auto, x11, or wayland")
    if backend == "x11" or (backend == "auto" and os.environ.get("WSL_DISTRO_NAME")):
        return {"WAYLAND_DISPLAY": ""}
    return {}




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


DEBUG_TARGETS = {
    "sta", "sta_corners", "sta_post_pnr",
    "power_estimate", "power_estimate_corners", "power_analysis", "power_analysis_all",
    "power_estimate_post_pnr", "power_analysis_post_pnr", "power_analysis_post_pnr_all",
    "fusion_analysis", "fusion_analysis_all",
    "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
    "sim_syn", "sim_post_syn", "sim_post_syn_all", "sim_post_pnr", "sim_post_pnr_all",
}


TECHNOLOGY_TARGETS = {
    "syn.setup", "eqy.setup", "signoff.setup", "signoff_post_pnr.setup", "pnr.setup",
    "syn", "syn_v", "syn_sv", "eqy",
    "compile_syn", "sim_syn", "compile_post_syn", "sim_post_syn", "sim_post_syn_all",
    "compile_post_pnr", "sim_post_pnr", "sim_post_pnr_all",
    "signoff_post_pnr", "sdf_post_pnr", "sta_post_pnr", "power_estimate_post_pnr",
    "power_analysis_post_pnr", "power_analysis_post_pnr_all", "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
    "sta", "sdf", "power_estimate", "power_analysis", "power_analysis_all", "fusion_analysis", "fusion_analysis_all", "sta_violators",
    "path_view", "sta_corners", "power_estimate_corners", "signoff",
    "pnr", "pnr_gui", "physical_signoff", "ip_save",
    "metrics", "manifest", "manifest_show", "check",
    "clean_syn", "clean_signoff", "clean_pnr", "clean_meta",
}

SETUP_TARGETS: dict[str, tuple[str, ...]] = {
    "sdc": ("sdc.setup",),
    "model": ("model.setup",),
    "tb": ("tb.setup",),
    "cocotb": ("cocotb.setup",),
    "compile": ("tb.setup",),
    "compile_v": ("tb.setup",),
    "compile_sv": ("tb.setup",),
    "sim": ("tb.setup",),
    "sim_v": ("tb.setup",),
    "sim_sv": ("tb.setup",),
    "sim_tests": ("tb.setup",),
    "cocotb_tests": ("cocotb.setup",),
    "regression": ("tb.setup", "cocotb.setup"),
    "cdc_rdc": ("cdc_rdc.setup",),
    "formal_csr_bmc": ("formal.csr_prove.setup",),
    "formal_csr_prove": ("formal.csr_prove.setup",),
    "formal_csr_cover": ("formal.csr_cover.setup",),
    "formal_bmc": ("formal.prove.setup",),
    "formal_prove": ("formal.prove.setup",),
    "formal_cover": ("formal.cover.setup",),
    "formal_csr": ("formal.csr_prove.setup", "formal.csr_cover.setup"),
    "formal": (
        "formal.prove.setup", "formal.cover.setup",
        "formal.csr_prove.setup", "formal.csr_cover.setup",
    ),
    "syn": ("syn.setup",),
    "syn_v": ("syn.setup",),
    "syn_sv": ("syn.setup",),
    "eqy": ("eqy.setup",),
    "sta": ("signoff.setup",),
    "sta_corners": ("signoff.setup",),
    "sdf": ("signoff.setup",),
    "power_estimate": ("signoff.setup",),
    "power_estimate_corners": ("signoff.setup",),
    "sta_violators": ("signoff.setup",),
    "power_analysis": ("signoff.setup",),
    "power_analysis_all": ("signoff.setup",),
    "fusion_analysis": ("signoff.setup",),
    "fusion_analysis_all": ("signoff.setup",),
    "signoff": ("signoff.setup",),
    "sdf_post_pnr": ("signoff_post_pnr.setup",),
    "sta_post_pnr": ("signoff_post_pnr.setup",),
    "power_estimate_post_pnr": ("signoff_post_pnr.setup",),
    "power_analysis_post_pnr": ("signoff_post_pnr.setup",),
    "power_analysis_post_pnr_all": ("signoff_post_pnr.setup",),
    "fusion_analysis_post_pnr": ("signoff_post_pnr.setup",),
    "fusion_analysis_post_pnr_all": ("signoff_post_pnr.setup",),
    "signoff_post_pnr": ("signoff_post_pnr.setup",),
    "pnr": ("pnr.setup",),
    "pnr_gui": ("pnr.setup",),
}

SETUP_STAGES = frozenset(stage for stages in SETUP_TARGETS.values() for stage in stages)
SETUP_ONLY_TARGETS = frozenset({"sdc", "model", "tb"})

RUN_DEPENDENCIES: dict[str, tuple[str, ...]] = {
    **SETUP_TARGETS,
    "sim_post_syn_all": ("sdf",),
    "sim_post_pnr_all": ("sdf_post_pnr",),
    "pnr.setup": ("syn", "signoff.setup"),
}


GLS_PROVENANCE_TARGETS = {
    "compile_syn", "sim_syn", "compile_post_syn", "sim_post_syn", "sim_post_syn_all",
    "compile_post_pnr", "sim_post_pnr", "sim_post_pnr_all",
}

@dataclass(frozen=True, slots=True)
class StageContract:
    """Semantic configuration, lineage, and evidence for one lifecycle stage."""

    config: tuple[str, ...] = ()
    parents: tuple[str, ...] = ()
    evidence: tuple[str, ...] = ()


STAGE_CONTRACTS = {
    # Generated setup collateral.
    "tb.setup": StageContract((*CLOCKS, "TOP", "REG_ITF", "CLK_PERIOD", "COMPILER", "VSV")),
    "cocotb.setup": StageContract((*CLOCKS, "TOP", "REG_ITF", "CLK_PERIOD", "COMPILER", "VSV")),
    "cdc_rdc.setup": StageContract((*CLOCKS, "TOP", "CLK_PERIOD")),
    "formal.prove.setup": StageContract((
        *CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_BMC_DEPTH", "FORMAL_BMC_APPEND",
        "FORMAL_BMC_ENGINE", "FORMAL_PROVE_ENGINE",
    )),
    "formal.cover.setup": StageContract((*CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_COVER_ENGINE")),
    "formal.csr_prove.setup": StageContract((
        *CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_BMC_DEPTH", "FORMAL_BMC_APPEND",
        "FORMAL_BMC_ENGINE", "FORMAL_PROVE_ENGINE",
    )),
    "formal.csr_cover.setup": StageContract((*CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_COVER_ENGINE")),
    "syn.setup": StageContract((
        *CLOCKS, "TOP", "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT",
        "TIEHI_CELL_AND_PORT", "TIELO_CELL_AND_PORT", "MIN_BUF_CELL_AND_PORTS",
    )),
    "eqy.setup": StageContract((
        *CLOCKS, "TOP", "EQY_SAT_DEPTH", "EQY_USE_SAT",
        "EQY_SPLITNETS", "EQY_USE_PDR", "EQY_PDR_ENGINE", "EQY_SMT_ENGINE",
        "EQY_SMT_DEPTH", "EQY_XPROP", "EQY_JOIN_OUTPUTS", "EQY_STRATEGY_ORDER",
        "EQY_RESET_NORMALIZE", "EQY_RESET_CYCLES",
    ), ("syn.setup",)),
    "signoff.setup": StageContract((
        *CLOCKS, "TOP", "PDK", "CLK_PERIOD", "SDC_IO_DELAY_PCT", "SDC_CLOCK_PERIOD_NS",
    )),
    "signoff_post_pnr.setup": StageContract(
        (*CLOCKS, "TOP", "PDK", "CLK_PERIOD", "ORS_TECH", "SDC_IO_DELAY_PCT"),
        ("pnr.setup",),
    ),
    "pnr.setup": StageContract((*CLOCKS, "TOP", "PDK", "ORS_TECH"), ("syn.setup", "signoff.setup")),

    # Runtime qualification evidence. Paths are run-relative and may use {pdk}/{top}.
    "lint_slang_suite": StageContract(("TOP",), evidence=("logs/lint/{top}_lint_slang_all.log",)),
    "lint_verilator_suite": StageContract(("TOP",), evidence=("logs/lint/{top}_lint_verilator_all.log",)),
    "cdc_rdc": StageContract((*CLOCKS, "TOP", "CDC_RDC_STRICT"), ("cdc_rdc.setup",), ("analysis/cdc_rdc/summary.json", "analysis/cdc_rdc/cdc_rdc.rpt")),
    "regression": StageContract(
        (*CLOCKS, "TOP", "COMPILER", "REGRESSION_BACKENDS", "SEED"),
        ("tb.setup", "cocotb.setup"),
        (
            "logs/dv/functional/regression",
            "dv/functional/coverage/sv",
            "dv/functional/coverage/cocotb",
        ),
    ),
    "formal_csr_bmc": StageContract(("TOP", "FORMAL_BMC_DEPTH", "FORMAL_BMC_ENGINE"), ("formal.csr_prove.setup",), ("logs/dv/formal/csr/{top}_bmc.log",)),
    "formal_bmc": StageContract(("TOP", "FORMAL_BMC_DEPTH", "FORMAL_BMC_ENGINE"), ("formal.prove.setup",), ("logs/dv/formal/properties/{top}_bmc.log",)),
    "formal_csr_prove": StageContract(("TOP", "FORMAL_PROVE_ENGINE"), ("formal.csr_prove.setup", "formal_csr_bmc"), ("logs/dv/formal/csr/{top}_prove.log",)),
    "formal_prove": StageContract(("TOP", "FORMAL_PROVE_ENGINE"), ("formal.prove.setup", "formal_bmc"), ("logs/dv/formal/properties/{top}_prove.log",)),
    "formal_csr_cover": StageContract(("TOP", "FORMAL_COVER_ENGINE"), ("formal.csr_cover.setup",), ("logs/dv/formal/csr/{top}_cover.log",)),
    "formal_cover": StageContract(("TOP", "FORMAL_COVER_ENGINE"), ("formal.cover.setup",), ("logs/dv/formal/properties/{top}_cover.log",)),
    "syn": StageContract(("TOP", "PDK", "TARGET_SYN", "TARGET_OPT"), ("syn.setup",), ("syn/{pdk}/{top}_synth.v", "syn/{pdk}/{top}_synth.json")),
    "eqy": StageContract(("TOP", "PDK", "EQY_STRATEGY_ORDER"), ("eqy.setup", "syn"), ("signoff/{pdk}/equivalence",)),
    "sdf": StageContract(("TOP", "PDK"), ("signoff.setup", "syn"), ("signoff/{pdk}/sdf",)),
    "sta": StageContract(("TOP", "PDK"), ("signoff.setup", "syn"), ("signoff/{pdk}/sta/sta.json",)),
    "power_estimate": StageContract(("TOP", "PDK"), ("signoff.setup", "syn"), ("signoff/{pdk}/power/estimate",)),
    "sim_post_syn_all": StageContract(
        ("TOP", "PDK", "GLS_BACKEND", "TIMING_MODES", "TEST_NAMES", "SDF_STRICT"),
        ("tb.setup", "syn", "sdf"),
        ("dv/functional/sim/post_syn/{pdk}/summary_sv.json",),
    ),
    "pnr": StageContract(("TOP", "PDK", "ORS", "ORS_TECH"), ("pnr.setup", "syn"), ("impl/{pdk}",)),
    "physical_signoff": StageContract(("TOP", "PDK", "ORS", "ORS_TECH"), ("pnr",), ("signoff/{pdk}/post_pnr/physical/summary.json",)),
    "sdf_post_pnr": StageContract(("TOP", "PDK"), ("signoff_post_pnr.setup", "pnr"), ("signoff/{pdk}/post_pnr/sdf",)),
    "sta_post_pnr": StageContract(("TOP", "PDK"), ("signoff_post_pnr.setup", "pnr"), ("signoff/{pdk}/post_pnr/sta/sta.json",)),
    "power_estimate_post_pnr": StageContract(("TOP", "PDK"), ("signoff_post_pnr.setup", "pnr"), ("signoff/{pdk}/post_pnr/power/estimate",)),
    "sim_post_pnr_all": StageContract(
        ("TOP", "PDK", "GLS_BACKEND", "TIMING_MODES", "TEST_NAMES", "SDF_STRICT"),
        ("tb.setup", "pnr", "sdf_post_pnr"),
        ("dv/functional/sim/post_pnr/{pdk}/summary_sv.json",),
    ),
}
PROVENANCE_SETUPS = frozenset(stage for stage in STAGE_CONTRACTS if stage.endswith(".setup"))
RUNTIME_STAGES = frozenset(STAGE_CONTRACTS) - PROVENANCE_SETUPS

RELEASE_LEVELS = (
    ("Contract Valid", ()),
    ("RTL Qualified", (
        "lint_slang_suite", "lint_verilator_suite", "cdc_rdc", "regression",
        "formal_csr_bmc", "formal_bmc", "formal_csr_prove", "formal_prove",
        "formal_csr_cover", "formal_cover",
    )),
    ("Netlist Qualified", ("syn", "eqy", "sim_post_syn_all")),
    ("Technology Qualified", ("sdf", "sta", "power_estimate", "sim_post_syn_all")),
    ("Physical Qualified", (
        "pnr", "physical_signoff", "sdf_post_pnr", "sta_post_pnr",
        "power_estimate_post_pnr", "sim_post_pnr_all",
    )),
)


DESIGN_INTENT_KEYS = (
    "TOP", "N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS", "REG_ITF",
)

SETTINGS_EVIDENCE_KEYS = tuple(sorted({
    *DEFAULT_SETTINGS, *DESIGN_INTENT_KEYS,
    *(key for stage in STAGE_CONTRACTS.values() for key in stage.config),
    "PDK", "PDK_ROOT", "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT",
    "LIB_SYN", "LIBS", "PRIM", "MACRO_LIBS",
    "ORS", "ORS_TECH", "SDC_IO_DELAY_PCT", "SDC_CLOCK_PERIOD_NS",
    "GLS_BACKEND", "GLS_SIMULATOR", "TIMING_MODE", "SDF_STRICT",
}) )



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
    # Gate-simulation target names share one implementation selected by stage.
    "compile_syn": ("compile", "post_syn"),
    "sim_syn": ("sim", "post_syn"),
    "compile_post_syn": ("compile", "post_syn"),
    "sim_post_syn": ("sim", "post_syn"),
    "sim_post_syn_all": ("sim_all", "post_syn"),
    "compile_post_pnr": ("compile", "post_pnr"),
    "sim_post_pnr": ("sim", "post_pnr"),
    "sim_post_pnr_all": ("sim_all", "post_pnr"),
}

def _dependencies(target: str, timing_mode: str) -> tuple[str, ...]:
    """Return declared prerequisites for one run or setup stage."""

    deps = RUN_DEPENDENCIES.get(target, ())
    if timing_mode in SDF_MODE_TO_CORNER:
        if target in {"compile_post_syn", "sim_post_syn"}:
            return (*deps, "sdf")
        if target in {"compile_post_pnr", "sim_post_pnr"}:
            return (*deps, "sdf_post_pnr")
    return deps



def _setup_public(stage: str) -> str:
    """Return the public keyword owning one internal setup stage."""

    return {
        "formal.prove.setup": "formal_prove",
        "formal.cover.setup": "formal_cover",
        "formal.csr_prove.setup": "formal_csr_prove",
        "formal.csr_cover.setup": "formal_csr_cover",
        "signoff.setup": "signoff",
        "signoff_post_pnr.setup": "signoff_post_pnr",
    }.get(stage, stage.removesuffix(".setup"))


def _setup_command(stage: str, *, force: bool = False) -> str:
    """Render the public command for one internal setup stage."""

    return f"fx {_setup_public(stage)} --setup" + (" --force" if force else "")

POST_PNR_SIGNOFF_TARGETS = {
    "signoff_post_pnr", "sdf_post_pnr", "sta_post_pnr", "power_estimate_post_pnr",
    "power_analysis_post_pnr", "power_analysis_post_pnr_all",
    "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all", "sim_post_pnr_all",
}


ACTIVITY_ANALYSIS_TARGETS = {
    "power_analysis", "power_analysis_all", "fusion_analysis", "fusion_analysis_all",
    "power_analysis_post_pnr", "power_analysis_post_pnr_all",
    "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
}

STREAM_BY_DEFAULT_TARGETS = {
    "sim_post_syn_all", "sim_post_pnr_all",
    "power_analysis_all", "power_analysis_post_pnr_all",
    "fusion_analysis", "fusion_analysis_all",
    "fusion_analysis_post_pnr", "fusion_analysis_post_pnr_all",
}

QUIET_BY_DEFAULT_TARGETS = {
    "compile_post_syn", "sim_post_syn",
    "compile_post_pnr", "sdf_post_pnr", "sim_post_pnr",
    "power_analysis", "power_analysis_post_pnr",
}


def _target(name: str) -> str:
    """Accept exact, dashed, or underscored target spelling."""

    for item in (name, name.replace("-", "_"), name.replace("_", "-")):
        if item in TARGETS:
            return item
    raise ValueError(f"unknown target {name!r}; run `fx commands` to list targets")


def _target_object(name: str) -> FlexSoCTargetInfo:
    """Build one target object from the unified table."""

    group, description, params = TARGETS[name]
    return FlexSoCTargetInfo(name, group, description, params)


# ---------------------------------------------------------------------------
# Target execution and lifecycle routing
# ---------------------------------------------------------------------------

class FlexSoCTarget:
    """Execute one FlexSoC lifecycle target through the domain backend."""

    def __init__(
        self, client: "FlexSoC", values: Mapping[str, str], *, on: str = "local",
    ):
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

    def _run_cmd(self, argv, *, cwd: Path | None = None, log: Path | None = None, env=None, inputs=(), outputs=()) -> int:
        from .backend.core import CommandRequest

        cwd = (cwd or self.client.project_root).resolve()
        log = log or self.paths.logs / "commands" / f"{_safe_log_name(str(argv[0]))}.log"
        request = CommandRequest(tuple(str(x) for x in argv), cwd, dict(env or {}), log, tuple(inputs), tuple(outputs))
        return self.runner.run(request, on=self.on).returncode

    def _tb_configs(self):
        from .backend.dv import CocotbConfig, TestbenchConfig

        top = self.paths.top
        period = float(self.values.get("CLK_PERIOD", "20"))
        interface = self.values.get("REG_ITF", "tlul")
        io_delay_pct = float(self.values.get("SDC_IO_DELAY_PCT", "0.2"))
        sv = TestbenchConfig(
            top=top,
            rtldir=self.paths.rtl,
            simdir=self.paths.sim / "rtl",
            syndir=self.paths.syn,
            prims=self._words("PRIM"),
            clk_period_ns=max(1, int(period)),
            io_delay_pct=io_delay_pct,
            compiler=self.values.get("COMPILER", "verilator"),
            interface=interface,
            vsv=self.values.get("VSV", "sv"),
            output=self.paths.tb / "sv",
            force=True,
        )
        cocotb = CocotbConfig(
            top=top,
            interface=interface,
            output=self.paths.tb / "cocotb",
            rtl_dir=self.paths.rtl,
            ips_root=self.client.project_root / "hw" / "ips",
            simulator=self.values.get("COMPILER", "verilator"),
            period_ns=period,
            io_delay_pct=io_delay_pct,
            vsv=self.values.get("VSV", "sv"),
            force=True,
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

    @staticmethod
    def _write_json_atomic(path: Path, data: Mapping[str, object]) -> None:
        """Write one deterministic JSON evidence file atomically."""

        path.parent.mkdir(parents=True, exist_ok=True)
        temp = path.with_name(f".{path.name}.{os.getpid()}.tmp")
        temp.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        temp.replace(path)

    def _design_intent_sources(self) -> tuple[Path, ...]:
        """Return canonical authored sources; generated views are excluded."""

        p, top = self.paths, self.paths.top
        generated_model = {f"{top}_regmap.py", f"{top}_regmap_tests.py"}
        sources = [p.data / f"{top}.hjson", p.sdc]
        for path in sorted(p.rtl.glob("*.sv")):
            header = path.read_text(encoding="utf-8", errors="replace")[:512].lower()
            if "auto-generated by flexsoc.backend.design.rtl" not in header and "auto-generated by `reggen`" not in header:
                sources.append(path)
        sources += sorted(path for path in p.model.glob("*.py") if path.name not in generated_model)
        sources += sorted((p.formal / "properties").rglob("*.sv"))
        return tuple(dict.fromkeys(sources))

    def _design_intent_snapshot(self) -> tuple[dict[str, str | None], ...]:
        snapshot = []
        for path in self._design_intent_sources():
            digest = hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else None
            snapshot.append({"path": path.relative_to(self.paths.run).as_posix(), "sha256": digest})
        return tuple(snapshot)

    def _design_intent(self) -> tuple[dict[str, str], tuple[dict[str, str | None], ...], str]:
        """Return canonical authored intent, source snapshot, and aggregate hash."""

        intent = {key: self.values.get(key, "") for key in DESIGN_INTENT_KEYS if key in self.values}
        sources = self._design_intent_snapshot()
        digest = hashlib.sha256(json.dumps(
            {"design_intent": intent, "sources": sources},
            sort_keys=True, separators=(",", ":"),
        ).encode()).hexdigest()
        return intent, sources, digest

    def _write_settings_evidence(self, target: str) -> None:
        """Snapshot authored IP intent separately from run/PDK execution state."""

        intent, sources, intent_sha256 = self._design_intent()
        self._write_json_atomic(
            self.paths.run / "meta" / "design_intent.json",
            {
                "schema": 2,
                "top": self.paths.top,
                "run_top": self.paths.run_top,
                "run_id": self.paths.run_id,
                "ip_intent_sha256": intent_sha256,
                "design_intent": intent,
                "sources": sources,
            },
        )
        if target not in TECHNOLOGY_TARGETS:
            return
        effective = {
            key: self.values[key]
            for key in SETTINGS_EVIDENCE_KEYS
            if key in self.values
        }
        self._write_json_atomic(
            self.paths.meta / "settings.json",
            {
                "schema": 1,
                "pdk": self.paths.pdk,
                "top": self.paths.top,
                "run_top": self.paths.run_top,
                "run_id": self.paths.run_id,
                "persistent": dict(sorted(self.client.settings.items())),
                "ip_intent_sha256": intent_sha256,
                "design_intent": intent,
                "effective": effective,
            },
        )

    def _provenance(self):
        """Return the run-local provenance store."""

        from .backend.core.reporting import Provenance

        return Provenance(self.paths.meta / "provenance.json", self.paths.run)

    def _provenance_config(self, stage: str) -> dict[str, str]:
        """Select only semantic values for one contract stage."""

        return {key: self.values.get(key, "") for key in STAGE_CONTRACTS[stage].config}

    def _configured_paths(self, *keys: str) -> tuple[Path, ...]:
        paths: list[Path] = []
        for key in keys:
            for token in self._words(key):
                path = Path(token).expanduser()
                resolved = self.client.project_root / path if not path.is_absolute() else path
                paths.append(resolved.resolve())
        return tuple(paths)

    def _provenance_inputs(self, stage: str) -> tuple[Path, ...]:
        """Return effective source artifacts consumed by one generated setup."""

        p = self.paths
        rtl = (p.rtl_common, p.rtl_ip, *self._rtl_sources())
        if stage in RUNTIME_STAGES:
            if stage.startswith("lint_"):
                inputs = rtl
            elif stage == "cdc_rdc":
                inputs = self._execution_inputs("cdc_rdc.setup")
            elif stage == "regression":
                inputs = (*rtl, p.sdc, p.tests, p.model, *self._execution_inputs("tb.setup"), *self._execution_inputs("cocotb.setup"))
            elif stage.startswith("formal_"):
                setup = {
                    "formal_csr_bmc": "formal.csr_prove.setup",
                    "formal_csr_prove": "formal.csr_prove.setup",
                    "formal_csr_cover": "formal.csr_cover.setup",
                    "formal_bmc": "formal.prove.setup",
                    "formal_prove": "formal.prove.setup",
                    "formal_cover": "formal.cover.setup",
                }[stage]
                inputs = self._execution_inputs(setup)
            elif stage == "syn":
                inputs = self._execution_inputs("syn.setup")
            elif stage == "eqy":
                inputs = self._execution_inputs("eqy.setup")
            elif stage in {"sdf", "sta", "power_estimate"}:
                inputs = self._execution_inputs("signoff.setup")
            elif stage == "sim_post_syn_all":
                inputs = (*rtl, p.tests, *self._execution_inputs("tb.setup"), p.syn / f"{p.top}_synth.v", p.signoff / "sdf")
            elif stage == "pnr":
                inputs = self._execution_inputs("pnr.setup")
            elif stage == "physical_signoff":
                inputs = (p.impl,)
            elif stage in {"sdf_post_pnr", "sta_post_pnr", "power_estimate_post_pnr"}:
                inputs = self._execution_inputs("signoff_post_pnr.setup")
            elif stage == "sim_post_pnr_all":
                inputs = (*rtl, p.tests, *self._execution_inputs("tb.setup"), p.signoff / "post_pnr" / "sdf", p.impl)
            else:
                raise ValueError(f"provenance inputs are not defined for {stage}")
            return tuple(dict.fromkeys(Path(path).expanduser().resolve() for path in inputs))
        if stage in {"tb.setup", "cocotb.setup"}:
            inputs = (p.data / f"{p.top}.hjson", p.sdc)
        elif stage == "cdc_rdc.setup":
            inputs = (*rtl, p.sdc)
        elif stage in {"formal.prove.setup", "formal.cover.setup"}:
            mode = "cover" if ".cover." in stage else "prove"
            inputs = (*rtl, p.formal / "properties" / mode)
        elif stage.startswith("formal.csr_"):
            inputs = rtl
        elif stage == "syn.setup":
            inputs = (*rtl, p.sdc, *self._configured_paths("LIB_SYN"))
        elif stage == "eqy.setup":
            inputs = (
                *rtl, p.syn / f"{p.top}_synth.v",
                *self._configured_paths("LIB_SYN", "PRIM", "FORMAL_PDK_PROC"),
            )
        elif stage == "signoff.setup":
            inputs = (
                p.sdc, p.syn / f"{p.top}_synth.v",
                *self._configured_paths("LIBS", "LIB_SYN", "PRIM", "MACRO_LIBS"),
            )
        elif stage == "pnr.setup":
            inputs = (p.syn / f"{p.top}_synth.v", p.sdc)
        elif stage == "signoff_post_pnr.setup":
            from .backend.signoff.sta import _stage_inputs, _stage_sdc

            values = {**self.values, "SIGNOFF_STAGE": "post_route"}
            netlist, spef = _stage_inputs(self.client.project_root, values)
            inputs = (
                netlist, _stage_sdc(self.client.project_root, values),
                *(() if spef is None else (spef,)),
                *self._configured_paths("LIBS", "LIB_SYN", "PRIM", "MACRO_LIBS"),
            )
        else:
            raise ValueError(f"provenance is not defined for {stage}")
        return tuple(dict.fromkeys(Path(path).expanduser().resolve() for path in inputs))

    @staticmethod
    def _result_paths(value: object) -> tuple[Path, ...]:
        if isinstance(value, Path):
            return (value,)
        if isinstance(value, (tuple, list)):
            return tuple(path for item in value for path in FlexSoCTarget._result_paths(item))
        return ()

    def _evidence_paths(self, stage: str) -> tuple[Path, ...]:
        """Resolve canonical runtime evidence declared by the stage contract."""

        values = {"pdk": self.paths.pdk, "top": self.paths.top}
        return tuple(self.paths.run / pattern.format(**values) for pattern in STAGE_CONTRACTS[stage].evidence)

    def _generated_paths(self, stage: str, result: object) -> tuple[Path, ...]:
        if stage in RUNTIME_STAGES:
            return self._evidence_paths(stage)
        paths = self._result_paths(result)
        if stage == "cdc_rdc.setup":
            paths = (self.paths.run / "analysis" / "cdc_rdc" / "extract.ys",)
        elif stage == "eqy.setup":
            out = self.context.layout.equivalence_dir
            bindings = [
                *(out / path.name for path in (self.paths.rtl_common, self.paths.rtl_ip)),
                *(out / f"cell_model_{index}{Path(model).suffix or '.v'}"
                  for index, model in enumerate(self._words("PRIM"))),
                out / "netlist.v", out / "library.lib",
                out / "sky130_clock_gates_formal.v", out / "formal_pdk.v",
            ]
            paths += tuple(path for path in bindings if path.exists() or path.is_symlink())
        elif stage.startswith("formal.csr_"):
            mode = "cover" if ".cover." in stage else "prove"
            paths += (self.paths.formal / "csr" / mode / f"{self.paths.top}_csr_auto_{mode}.sv",)
        return tuple(dict.fromkeys(path.expanduser().absolute() for path in paths))

    def _setup_stages(self, target: str) -> tuple[str, ...]:
        """Resolve only provenance-bearing setup dependencies for a runtime target."""

        timing = self.values.get("TIMING_MODE", "zero").strip().lower()
        found: list[str] = []

        def visit(name: str) -> None:
            for dependency in _dependencies(name, timing):
                if dependency in PROVENANCE_SETUPS:
                    if dependency not in found:
                        found.append(dependency)
                else:
                    visit(dependency)

        visit(target)
        if target in GLS_PROVENANCE_TARGETS:
            driver_setup = (
                "cocotb.setup"
                if self.values.get("GLS_BACKEND", "sv").strip().lower() == "cocotb"
                else "tb.setup"
            )
            if driver_setup not in found:
                found.append(driver_setup)
        return tuple(found)

    def _provenance_parents(self, stage: str) -> dict[str, str | None]:
        store = self._provenance()
        return {
            parent: store.current_fingerprint(
                parent, inputs=self._provenance_inputs(parent),
                config=self._provenance_config(parent),
                parents=self._provenance_parents(parent),
            )
            for parent in STAGE_CONTRACTS[stage].parents
        }

    def _execution_inputs(self, stage: str) -> tuple[Path, ...]:
        """Return canonical setup artifacts plus their effective source inputs."""

        paths = (*self._provenance_inputs(stage), *self._provenance().generated(stage))
        return tuple(dict.fromkeys(path.absolute() for path in paths))

    def _provenance_state(self, stage: str) -> str:
        return self._provenance().state(
            stage, inputs=self._provenance_inputs(stage),
            config=self._provenance_config(stage),
            parents=self._provenance_parents(stage),
        )

    def _provenance_summary(self) -> dict[str, object]:
        """Return current states for recorded contract stages in this run."""

        from .backend.core.reporting import provenance_summary

        store = self._provenance()
        states = {
            stage: self._provenance_state(stage)
            for stage in store.stages()
            if stage in STAGE_CONTRACTS
        }
        return provenance_summary(states)

    def _contract_state(self, stage: str) -> str:
        """Return CLEAN/STALE/... or MISSING for one contract stage."""

        return "MISSING" if stage not in self._provenance().stages() else self._provenance_state(stage)

    def _contract_status(self) -> dict[str, object]:
        """Derive live contract state and the highest fully qualified release level."""

        _, _, intent = self._design_intent()
        contract_valid = self.paths.sdc.is_file() and bool(self._rtl_sources())
        states = {
            stage: self._contract_state(stage)
            for stage in STAGE_CONTRACTS
            if stage in RUNTIME_STAGES
        }
        clean = {stage for stage, state in states.items() if state in {"CLEAN", "VALIDATED_OVERRIDE"}}
        level = 0 if contract_valid else -1
        for index, (_, required) in enumerate(RELEASE_LEVELS[1:], 1):
            if level == index - 1 and set(required) <= clean:
                level = index
            else:
                break
        result = {
            "schema": 1,
            "ip_intent_sha256": intent,
            "contract": "VALID" if contract_valid else "INVALID",
            "release_level": level,
            "release": RELEASE_LEVELS[level][0] if level >= 0 else "Not Qualified",
            "stages": states,
        }
        print(f"[contract] {result['contract']} ip_intent_sha256={intent}")
        print(f"[release] level={level} {result['release']}")
        required_stages = set().union(*(set(required) for _, required in RELEASE_LEVELS[1:]))
        for stage, state in result["stages"].items():
            if state != "MISSING" or stage in required_stages:
                print(f"[stage] {stage:<24} {state}")
        return result

    def _record_provenance(self, stage: str, result: object) -> None:
        generated = self._generated_paths(stage, result)
        if not generated:
            raise ValueError(f"{stage}: no contract evidence was produced")
        self._provenance().record(
            stage, inputs=self._provenance_inputs(stage), generated=generated,
            config=self._provenance_config(stage),
            parents=self._provenance_parents(stage),
        )

    def _require_provenance(self, target: str) -> None:
        store = self._provenance()
        recorded = set(store.stages())
        for stage in self._setup_stages(target):
            state = self._provenance_state(stage)
            if state in {"CLEAN", "VALIDATED_OVERRIDE"}:
                continue
            if state == "MODIFIED":
                action = f"run `fx validate_override --set STAGE={_setup_public(stage)}` or regenerate with `{_setup_command(stage, force=True)}`"
            elif state == "STALE":
                action = f"regenerate the setup with `{_setup_command(stage, force=True)}`"
            elif stage not in recorded:
                action = f"generate the setup first with `{_setup_command(stage)}`"
            else:
                action = f"repair missing/inconsistent inputs, then regenerate with `{_setup_command(stage, force=True)}`"
            raise RuntimeError(f"{target}: {stage} provenance is {state}; {action}")

    def _reuse_setup(self, stage: str) -> tuple[Path, ...] | None:
        """Reuse an existing valid setup unless explicit --force requests regeneration."""

        if self._bool(self.values.get("FORCE")):
            return None
        store = self._provenance()
        if stage not in store.stages():
            return None
        state = self._provenance_state(stage)
        if state in {"CLEAN", "VALIDATED_OVERRIDE"}:
            generated = store.generated(stage)
            print(f"[setup] {stage} state={state} reuse={len(generated)}")
            return generated
        if state == "MODIFIED":
            raise RuntimeError(
                f"{stage}: generated setup is MODIFIED; run `fx validate_override --set STAGE={stage}` "
                f"to keep the edit, or `{_setup_command(stage, force=True)}` to regenerate it"
            )
        if state == "STALE":
            raise RuntimeError(
                f"{stage}: generated setup is STALE; regenerate explicitly with `{_setup_command(stage, force=True)}`"
            )
        raise RuntimeError(
            f"{stage}: generated setup provenance is {state}; repair the inputs/artifacts and "
            f"regenerate explicitly with `{_setup_command(stage, force=True)}`"
        )

    def _validate_override(self) -> str:
        stage = self.values.get("STAGE", "").strip().replace("-", "_")
        if stage not in PROVENANCE_SETUPS:
            candidates = self._setup_stages(stage) if stage in TARGETS else ()
            if len(candidates) != 1:
                choices = ", ".join(sorted(PROVENANCE_SETUPS))
                raise ValueError(f"STAGE must name one generated setup: {choices}")
            stage = candidates[0]
        state = self._provenance().validate(
            stage, inputs=self._provenance_inputs(stage),
            config=self._provenance_config(stage),
            parents=self._provenance_parents(stage),
        )
        print(f"[provenance] {stage} state={state}")
        return state

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
            clk_period_ns=period, output=self.paths.syn, sdc=self.paths.sdc,
            opt=self.values.get("TARGET_OPT", "delay1"),
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
            sat_depth=int(self.values.get("EQY_SAT_DEPTH", "20")),
            config=config,
            formal_pdk_proc=Path(formal_proc) if formal_proc else None,
            force=self._bool(self.values.get("FORCE")),
            pdr_engine=self.values.get("EQY_PDR_ENGINE", "abc pdr"),
            on=self.on,
            pdk=self.values.get("PDK", ""),
            multiclock=self.context.clocks.multiclock,
            reset_domains=tuple(
                (domain.signal, domain.reset, domain.reset_polarity)
                for domain in self.context.clocks.domains
            ),
        )

    def _run_eqy(self) -> int:
        layout = self.context.layout
        return self.backend.syn.eqy.run(
            config=layout.equivalence_dir / f"{self.paths.top}_rtl_vs_syn.eqy",
            log=layout.equivalence_log,
            jobs=int(self.values.get("EQY_JOBS", "1")),
            eqy=self.values.get("EQY", "eqy"),
            inputs=self._execution_inputs("eqy.setup"),
            on=self.on,
        )

    def _formal_config(self, *, csr: bool, mode: str) -> Path:
        kind = "csr" if csr else "properties"
        name = f"{self.paths.top}_{'csr_' if csr else ''}{mode}.sby"
        return self.paths.formal / "runs" / kind / mode / name

    def _formal_setup(self, *, csr: bool, mode: str) -> Path:
        flow = self.backend.dv.formal
        top = self.paths.top
        props = self.paths.formal / ("csr" if csr else "properties") / mode
        output = self._formal_config(csr=csr, mode=mode)
        output.parent.mkdir(parents=True, exist_ok=True)
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
            config = self._formal_config(csr=True, mode="cover" if mode == "cover" else "prove")
            log = logs / "csr" / f"{top}_{mode}.log"
            setup = "formal.csr_cover.setup" if mode == "cover" else "formal.csr_prove.setup"
            return getattr(flow, f"run_csr_{mode}")(
                config, **({} if mode == "cover" else {"top": top}), log=log, sby=sby,
                inputs=self._execution_inputs(setup), on=self.on,
            )
        mode = target.rsplit("_", 1)[-1]
        config = self._formal_config(csr=False, mode="cover" if mode == "cover" else "prove")
        log = logs / "properties" / f"{top}_{mode}.log"
        setup = "formal.cover.setup" if mode == "cover" else "formal.prove.setup"
        return getattr(flow, f"run_{mode}")(
            config, **({} if mode == "cover" else {"top": top}), log=log, sby=sby,
            inputs=self._execution_inputs(setup), on=self.on,
        )

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
        layout = self.context.layout
        log = layout.pnr_log_dir / (
            f"{self.paths.top}_pnr_gui.log" if gui else f"{self.paths.top}_pnr.log"
        )
        if gui:
            return self.backend.impl.view(makefile=makefile, config=config, workdir=self.paths.impl, log=log, on=self.on)
        return self.backend.impl.run(makefile=makefile, config=config, workdir=self.paths.impl, log=log, on=self.on)

    def _report(self, target: str) -> object:
        report = self.backend.reporting
        if target == "metrics":
            return report.write_metrics(
                self.paths.top, self.paths.run, self.paths.metrics, pdk=self.paths.pdk,
                provenance=self._provenance_summary(),
            )
        if target == "check":
            return report.check(self.paths.metrics)
        if target == "manifest":
            return report.write_manifest(
                top=self.paths.top, run_top=self.paths.run_top, run_id=self.paths.run_id,
                repo_root=self.client.project_root, output=self.paths.manifest,
                pdk=self.paths.pdk, run_root=self.paths.run,
            )
        if target == "manifest_show":
            return report.show_manifest(self.paths.manifest)
        if target == "status":
            return self._contract_status()
        raise ValueError(f"unsupported report target: {target}")

    def execute(self, target: str) -> object:
        """Apply explicit setup/provenance policy, then execute one backend target."""

        if target == "validate_override":
            return self._validate_override()
        if self._bool(self.values.get("DEBUG")):
            if target not in DEBUG_TARGETS:
                raise ValueError(f"--debug is not supported for target {target!r}")
            return self._execute_target(target)
        self._write_settings_evidence(target)
        if target in PROVENANCE_SETUPS:
            reused = self._reuse_setup(target)
            if reused is not None:
                return reused
            result = self._execute_target(target)
            self._record_provenance(target, result)
            return result
        if target not in SETUP_STAGES:
            self._require_provenance(target)
        result = self._execute_target(target)
        if target in RUNTIME_STAGES and self.client._returncode(result) == 0:
            self._record_provenance(target, result)
        return result

    def _execute_target(self, target: str) -> object:
        """Execute one public target through the owning backend domain."""
        b, p, v = self.backend, self.paths, self.values
        top, force = p.top, self._bool(v.get("FORCE"))
        interface = v.get("REG_ITF", "tlul")

        # Project setup, RTL, register and model generation.
        if target.startswith("help"):
            print(TARGETS[target][1])
            return 0
        if target == "setup":
            return p.ensure()
        if target == "sdc.setup":
            return b.signoff.pre.setup_sdc()
        if target == "hjson":
            return b.design.regs.init_hjson(top, interface, p.data, force=force, clocks=self.context.clocks)
        if target == "reg":
            return b.design.regs.setup_rtl(top, p.data, p.rtl, regmap=v.get("REGMAP"), on=self.on)
        if target == "doc":
            return b.design.regs.setup_docs(top, p.data, p.doc, regmap=v.get("REGMAP"), on=self.on)
        if target == "systemrdl":
            return b.design.regs.setup_systemrdl(
                top, p.data, p.run / "interchange" / "systemrdl",
                regmap=v.get("REGMAP"), on=self.on,
            )
        if target == "driver":
            return b.design.regs.setup_driver(p.data / f"{top}.hjson", p.drivers, base_address=v.get("BASE_ADDRESS", "0x0"))
        if target == "regmap_py":
            return b.design.regs.setup_regmap_py(top, p.data, p.model, force=force, refresh_tests=True, clocks=self.context.clocks)
        if target == "rtl_stub":
            hjson = p.data / f"{top}.hjson"
            return b.design.rtl.init_scaffold(hjson if hjson.exists() else None, interface, p.rtl, top=top, force=force, clocks=self.context.clocks)
        if target == "top_from_core":
            return b.design.rtl.setup_top(top, p.rtl, interface, force=force, clocks=self.context.clocks)
        if target in {"flist", "slang_flist"}:
            ips_root = self.client.project_root / "hw" / "ips"
            common_ip_roots = tuple(
                ips_root / name
                for name in ("pkgs", "prim", "prim_opentitan")
                if (ips_root / name).is_dir()
            )
            vendor_root = self.client.project_root / "vendor"
            vendor_rtl_roots: tuple[Path, ...] = ()
            extra_args = ""
            if interface == "tlul":
                vendor_rtl_roots = (vendor_root / "lowrisc_ip" / "ip" / "tlul" / "rtl",)
            elif interface == "axi_lite":
                pulp_root = vendor_root / "pulp"
                vendor_rtl_roots = (
                    pulp_root / "common_cells" / "src",
                    pulp_root / "axi" / "src",
                    pulp_root / "register_interface" / "src",
                )
                extra_args = shlex.join((
                    "-I", str(pulp_root / "axi" / "include"),
                    "-I", str(pulp_root / "register_interface" / "include"),
                ))
            return b.design.rtl.setup_filelists(
                root=self.client.project_root,
                top_file=p.rtl / f"{top}.sv",
                common_out=p.rtl_common,
                ip_out=p.rtl_ip,
                search_roots=(p.rtl, *common_ip_roots, *vendor_rtl_roots),
                common_roots=(*common_ip_roots, *vendor_rtl_roots),
                top=top, extra_args=extra_args,
                slang=v.get("SLANG", "slang"), on=self.on,
            )
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
        if target == "model.setup":
            return b.design.model.flow(top, p.data, p.model, p.rtl, force=force, clocks=self.context.clocks)
        if target in {"tb.setup", "cocotb.setup"}:
            from .backend.signoff.sdc import read_clock_config
            sv, cocotb = self._tb_configs()
            clocks = read_clock_config(p.sdc, self.context.clocks)
            return b.dv.testbench.setup_systemverilog(sv, clocks=clocks) if target == "tb.setup" else b.dv.testbench.setup_cocotb(cocotb, clocks=clocks)
        if target in {"tests_gen", "test_gen", "tests"}:
            if target == "tests":
                tests = b.dv.functional.tests(p.tests)
                print("\n".join(tests))
                return tests
            hjson = p.data / f"{top}.hjson"
            if target == "test_gen":
                return b.dv.functional.setup_test(v.get("TEST_NAME", "smoke"), p.tests, top, hjson, force=force)
            return b.dv.functional.setup_tests(p.tests, top, hjson, force=force)

        # RTL analysis, CDC/RDC and functional verification.
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
                return self._execute_sequence(("lint_slang_suite", "lint_verilator_suite"))
            if target in {"lint_v", "lint_sv"}:
                return b.dv.lint_verilator(kind="all", on=self.on)
            return b.dv.lint_suite(tools=(v.get("LINT_TOOL", "slang"),), part=v.get("LINT_PART", "ip"), on=self.on) if kind not in {"latch","undriven","width","unconnected","unused"} else (b.dv.lint_slang(kind=kind, part=v.get("LINT_PART","ip"), on=self.on), b.dv.lint_verilator(kind=kind, part=v.get("LINT_PART","ip"), on=self.on))

        if target in {"cdc_rdc.setup", "cdc_rdc"}:
            analysis = p.run / "analysis" / "cdc_rdc"
            script, design_json = analysis / "extract.ys", analysis / "design.json"
            if target == "cdc_rdc.setup":
                return b.dv.cdc.setup(top=top, script=script, design_json=design_json, repo_root=self.client.project_root, filelists=(p.rtl_common, p.rtl_ip))
            return b.dv.cdc.run_from_context(
                self.context, inputs=self._execution_inputs("cdc_rdc.setup"), on=self.on
            )

        if target in {"compile", "compile_v", "compile_sv"}:
            return b.dv.functional.run_compile_systemverilog(top=top, tb_dir=p.tb, sim_dir=p.sim / "rtl", common_filelist=p.rtl_common, ip_filelist=p.rtl_ip, test_name=v.get("TEST_NAME","smoke"), compiler=v.get("COMPILER","verilator"), coverage=self._bool(v.get("COVERAGE")), log=p.logs / "dv" / "functional" / f"{top}_compile.log", on=self.on)
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

        # Formal verification, synthesis and logical equivalence.
        if target in {"formal.prove.setup", "formal.cover.setup", "formal.csr_prove.setup", "formal.csr_cover.setup"}:
            b.dv.formal.init_properties(top, p.formal, multiclock=self.context.clocks.multiclock)
            cover_setup = target in {"formal.cover.setup", "formal.csr_cover.setup"}
            return self._formal_setup(csr=".csr_" in target, mode="cover" if cover_setup else "prove")
        if target in {"formal_bmc", "formal_prove", "formal_cover", "formal_csr_bmc", "formal_csr_prove", "formal_csr_cover"}:
            return self._run_formal(target)
        if target == "formal_csr":
            return self._execute_sequence(
                ("formal_csr_bmc", "formal_csr_prove", "formal_csr_cover"),
            )
        if target == "formal":
            return self._execute_sequence(
                ("formal_csr_bmc", "formal_bmc", "formal_csr_prove", "formal_prove",
                 "formal_csr_cover", "formal_cover"),
            )

        if target == "syn.setup":
            return self._setup_synthesis()
        if target in {"syn", "syn_v", "syn_sv"}:
            return b.syn.synthesis.run_asic(
                output=p.syn, top=top, log_dir=p.logs / "synthesis" / p.pdk,
                opt=v.get("TARGET_OPT", "delay1"), yosys=v.get("YOSYS", "yosys"),
                systemverilog=(target != "syn_v" and v.get("VSV", "sv") != "v"),
                inputs=self._execution_inputs("syn.setup"), on=self.on,
            )
        if target == "yosys-vgen":
            return b.syn.synthesis.run_yosys_vgen(top=top, cwd=p.run, output=p.rtl / f"{top}.v", yosys=v.get("YOSYS","yosys"), on=self.on)
        if target == "sv2v":
            return 0
        if target == "eqy.setup":
            return self._setup_eqy()
        if target == "eqy":
            return self._run_eqy()

        pre = b.signoff.pre
        post = b.signoff.post
        if self._bool(v.get("DEBUG")):
            flow = post if target in POST_PNR_SIGNOFF_TARGETS else pre
            output = v.get("DEBUG_OUTPUT") or None
            if target in {"sta", "sta_corners", "sta_post_pnr"}:
                return flow.debug_sta(output=output)
            if target.startswith("power_"):
                return flow.debug_power(activity=target.startswith("power_analysis"), output=output)
            if target.startswith("fusion_analysis"):
                return flow.debug_fusion(output=output)
            if target in {"sim_syn", "sim_post_syn", "sim_post_syn_all", "sim_post_pnr", "sim_post_pnr_all"}:
                return flow.debug_gls(output=output)
            raise ValueError(f"--debug is not supported for target {target!r}")
        # Pre/post-layout sign-off, SDF, GLS, timing and power.
        if target == "signoff.setup":
            return (pre.setup_sta(), pre.setup_sdf(), pre.setup_power(), pre.setup_fusion())
        if target == "signoff_post_pnr.setup":
            return (post.setup_sta(), post.setup_sdf(), post.setup_power(), post.setup_fusion())
        if target in {"sta", "sta_corners"}:
            return pre.run_sta(on=self.on)
        if target == "sdf":
            return pre.run_sdf(on=self.on)
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
        if target == "signoff":
            return self._execute_sequence(("sdf", "sta", "power_estimate"))
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
            return post.run_sdf(on=self.on)
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
            return self._execute_sequence(
                ("sdf_post_pnr", "sta_post_pnr", "sim_post_pnr_all",
                 "power_estimate_post_pnr", "power_analysis_post_pnr_all",
                 "fusion_analysis_post_pnr_all"),
            )
        if target == "sta_violators":
            return pre.run_sta(on=self.on)
        if target == "path_view":
            path = self._path("PATH_VIEW_FILE", p.signoff / "path_view" / "paths.json")
            return self._run_cmd((sys.executable, str(self.client.project_root / "src" / "util" / "plot_path.py"), str(path)), log=p.logs / "signoff" / p.pdk / "path_view.log", inputs=(path,))

        # Physical implementation and routed sign-off evidence.
        if target == "pnr.setup":
            return self._setup_pnr()
        if target == "pnr":
            return self._run_pnr()
        if target == "pnr_gui":
            return self._run_pnr(gui=True)
        if target == "physical_signoff":
            makefile, config = self._orfs()
            return post.run_physical(
                makefile=makefile,
                config=config,
                workdir=p.impl,
                top=top,
                output=p.signoff / "post_pnr" / "physical" / "summary.json",
                log=p.logs / "signoff" / p.pdk / "post_pnr" / "physical" / "physical_signoff.log",
                on=self.on,
            )

        # Reporting, packaging and higher-level workflow helpers.
        if target in {"metrics", "manifest", "manifest_show", "check", "status"}:
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
                settings_json=p.meta / "settings.json",
                design_intent_json=p.run / "meta" / "design_intent.json",
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

    # Viewer and cleanup helpers ------------------------------------------------

    def _view(self, target: str) -> int:
        """Open or save one viewer artifact directly."""
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
        sim_name = v.get("SIM_NAME", "").strip() if target == "view" else ""
        if sim_name:
            stage = v.get("SIGNOFF_STAGE", "post_syn").strip().lower()
            layout = self.context.layout
            if stage == "post_syn":
                directory = layout.post_syn_sim_dir
            elif stage in {"post_route", "post_pnr"}:
                directory = layout.post_pnr_sim_dir
            else:
                raise ValueError("SIGNOFF_STAGE must be post_syn, post_route, or post_pnr for view")
            print(
                f"[wave] stage={stage} pdk={v.get('PDK', '')} sim={sim_name} directory={directory}",
                flush=True,
            )
            try:
                wave = _select_waveform(directory, p.top, sim_name)
            except FileNotFoundError as exc:
                print(f"[wave] error={exc}", flush=True)
                raise
        else:
            wave = _select_waveform(p.functional, p.top)

        viewer = v.get("WAVE_VIEWER", "surfer")
        env = _viewer_environment(viewer, v.get("SURFER_BACKEND", "auto"))
        print(f"[wave] {wave}", flush=True)
        return self._run_cmd(
            (viewer, str(wave)), cwd=wave.parent, env=env,
            log=p.logs / "viewer" / f"{target}.log", inputs=(wave,),
        )

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

    # Optional FSM and SoC domains --------------------------------------------

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

    # Composite workflows ------------------------------------------------------

    def _execute_sequence(self, sequence: Sequence[str]) -> tuple[object, ...]:
        """Execute one explicit composite flow in order without hidden setup."""

        return tuple(self.execute(name) for name in dict.fromkeys(sequence))

    def _tutorial(self, target: str) -> object:
        """Compose tutorials from the same flow operations used by normal targets."""
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
        return self._execute_sequence(sequence)

    def _ip_flow(self, target: str) -> object:
        """Compose high-level IP flows from the new domain APIs."""
        if target == "ip_start":
            sequence = (
                "setup", "hjson", "reg", "doc", "rtl_stub", "top_from_core",
                "flist", "driver", "model.setup", "tb.setup", "cocotb.setup",
                "tests_gen",
            )
        elif target == "ip_flow_noreg":
            sequence = (
                "flist", "lint_suite", "cdc_rdc.setup", "cdc_rdc",
                "tb.setup", "cocotb.setup", "regression", "coverage_detail",
                "formal.prove.setup", "formal.cover.setup",
                "formal.csr_prove.setup", "formal.csr_cover.setup", "formal",
                "syn.setup", "syn", "eqy.setup", "eqy",
                "signoff.setup", "signoff",
                "manifest", "manifest_show", "metrics", "check",
            )
        elif target == "ip_flow":
            sequence = (
                "reg", "doc", "flist", "lint_suite", "sdc.setup", "cdc_rdc.setup", "cdc_rdc",
                "tb.setup", "cocotb.setup", "regression", "coverage_detail",
                "formal.prove.setup", "formal.cover.setup",
                "formal.csr_prove.setup", "formal.csr_cover.setup", "formal",
                "syn.setup", "syn", "eqy.setup", "eqy",
                "signoff.setup", "signoff",
                "manifest", "manifest_show", "metrics", "check",
            )
        else:
            sequence = (
                "reg", "doc", "flist", "lint_suite", "sdc.setup", "cdc_rdc.setup", "cdc_rdc",
                "tb.setup", "cocotb.setup", "regression", "coverage_detail",
                "formal.prove.setup", "formal.cover.setup",
                "formal.csr_prove.setup", "formal.csr_cover.setup", "formal",
                "syn.setup", "syn", "eqy.setup", "eqy",
                "signoff.setup", "signoff",
                "manifest", "manifest_show", "metrics", "check",
                "pnr.setup", "pnr", "pnr_gui",
            )
        return self._execute_sequence(sequence)

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
        base_values = dict(base.values)
        self.config = FlexSoCConfig(
            project_root if project_root is not None else base.project_root,
            workdir if workdir is not None else base.workdir,
            base_values,
        )
        known = set(DEFAULT_SETTINGS) | {key for _, _, params in TARGETS.values() for key in params}
        env_values = {key: os.environ[f"FLEXSOC_{key}"] for key in known if f"FLEXSOC_{key}" in os.environ}
        self.settings = _upper({**base_values, **env_values, **values})
        self.execution_targets = dict(execution_targets or {}) or None

    @property
    def project_root(self) -> Path:
        """Return the repository root used as cwd."""

        return _path(self.config.project_root, Path.cwd())

    @property
    def workdir(self) -> Path:
        """Return the explicit or persistently configured FlexSoC workspace."""

        selected = self.config.workdir or self.settings.get("WORKSPACE")
        return _path(selected, self.project_root / "workspace")

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

    def targets(self) -> tuple[FlexSoCTargetInfo, ...]:
        """List every backend target exposed by fx."""

        return tuple(_target_object(name) for name in TARGETS)

    def target_names(self) -> tuple[str, ...]:
        """Return only callable target names."""

        return tuple(TARGETS)

    def target_info(self, target: str) -> FlexSoCTargetInfo:
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
            from .backend.core import pdk_settings

            pdk_values = pdk_settings(
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
        from .backend.core import pdk_paths

        values.update(clock_config(values).to_settings())
        values.update(pdk_paths(self.project_root, values))
        fmt = values.get("WAVE_FORMAT", "fst").lower()
        if fmt not in {"fst", "vcd"}:
            raise ValueError("WAVE_FORMAT must be 'fst' or 'vcd'")
        values["WAVE_FORMAT"] = fmt
        values.setdefault("WAVE_EXT", fmt)
        # The generated simulator defaults to FST. Override it here so
        # WAVE_FORMAT=vcd genuinely changes Verilator's trace
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
        """Build one direct run or internal setup command preview."""
        setup = target in SETUP_STAGES
        name = target if setup else _target(target)
        public = _setup_public(name) if setup else name
        if public in POST_PNR_SIGNOFF_TARGETS:
            overrides = {**overrides, "SIGNOFF_STAGE": "post_route"}
        values = self.values(overrides)
        params = set(TARGETS.get(public, ("", "", ()))[2])
        call_values = _upper(overrides)
        shown = {key: value for key, value in {**self.settings, **call_values}.items() if key in params}
        argv = ("fx", public, *(("--setup",) if setup else ()), *(item for key, value in sorted(shown.items()) for item in ("--set", f"{key}={value}")))
        return FlexSoCCommand(name, argv, self.project_root, self._env(values), values)

    def commands(
        self,
        *targets: str,
        setup: bool = False,
        **overrides: Any,
    ) -> tuple[FlexSoCCommand, ...]:
        """Build run commands or the explicit setup phase for public targets."""

        requested = tuple(_target(target) for target in targets)
        if not setup:
            blocked = [target for target in requested if target in SETUP_ONLY_TARGETS]
            if blocked:
                raise ValueError(f"{blocked[0]} is setup-only; use `fx {blocked[0]} --setup`")
            return tuple(self.command(target, **overrides) for target in requested)
        stages = tuple(dict.fromkeys(
            stage for target in requested for stage in SETUP_TARGETS.get(target, ())
        ))
        missing = [target for target in requested if target not in SETUP_TARGETS]
        if missing:
            raise ValueError(f"{missing[0]} has no setup phase")
        return tuple(self.command(stage, **overrides) for stage in stages)

    def run(
        self,
        *targets: str,
        check: bool = True,
        dry_run: bool = False,
        capture: bool = False,
        live: bool = False,
        setup: bool = False,
        on: str = "local",
        **overrides: Any,
    ) -> tuple[FlexSoCCommand | FlexSoCResult, ...]:
        """Execute targets directly through backend flow objects."""
        commands = self.commands(*targets, setup=setup, **overrides)
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

            _COMPACT_PREFIXES = ("[script]", "[report]", "[summary]", "[gate-sim]")

            def __init__(self, log, console, *, compact: bool = False):
                self.log = log
                self.console = console
                self.compact = compact
                self._console_pending = ""

            def _compact_visible(self, line: str) -> bool:
                return line.lstrip().startswith(self._COMPACT_PREFIXES)

            def _write_compact_console(self, text: str) -> None:
                if self.console is None:
                    return
                self._console_pending += text
                while "\n" in self._console_pending:
                    line, self._console_pending = self._console_pending.split("\n", 1)
                    if self._compact_visible(strip_ansi(line)):
                        self.console.write(line + "\n")
                self.console.flush()

            def write(self, text: str) -> int:
                plain = strip_ansi(text)
                self.log.write(plain)
                self.log.flush()
                if self.console is not None:
                    if self.compact:
                        self._write_compact_console(text)
                    else:
                        self.console.write(text)
                        self.console.flush()
                return len(text)

            def flush(self) -> None:
                if not self.log.closed:
                    self.log.flush()
                if self.console is not None and not getattr(self.console, "closed", False):
                    if self.compact and self._console_pending:
                        pending = self._console_pending
                        self._console_pending = ""
                        if self._compact_visible(strip_ansi(pending)):
                            self.console.write(pending)
                    self.console.flush()

        results: list[FlexSoCResult] = []
        for command in commands:
            public = _setup_public(command.target) if command.target in SETUP_STAGES else command.target
            _, description, _ = TARGETS.get(public, ("Target", "Run target", ()))
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
                        value = FlexSoCTarget(
                            self, command.values, on=on
                        ).execute(command.target)
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
                message = f"[error] {exc}\n"
                if capture and stderr is not None:
                    stderr.write(message)
                    log_path.write_text(
                        strip_ansi((stdout.getvalue() if stdout else "") + stderr.getvalue()),
                        encoding="utf-8",
                    )
                else:
                    with log_path.open("a", encoding="utf-8") as log:
                        log.write(strip_ansi(message))
                    print(message, end="", flush=True)

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
        if str(command.values.get("DEBUG", "")).strip().lower() in {"1", "true", "yes", "on"}:
            return
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

    def log_path(self, target: str, **overrides: Any) -> Path:
        """Return the canonical command log path without executing the target."""

        return self._command_log_path(self.command(target, **overrides))

    def _command_log_path(self, command: FlexSoCCommand) -> Path:
        """Return the per-target command log path."""

        values = command.values
        workspace = Path(values.get("WORKSPACE", str(self.workdir)))
        run_top = values.get("RUN_TOP") or values.get("TOP") or "run"
        run_id = values.get("RUN_ID", "default")
        name = _safe_log_name(command.target)
        if str(values.get("DEBUG", "")).strip().lower() in {"1", "true", "yes", "on"}:
            name += "_debug"
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

