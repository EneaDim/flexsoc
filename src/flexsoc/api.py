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
from .backend.core.flow.target import BACKEND_TARGETS
from .backend.core.flow.session import (
    ACTIVITY_ANALYSIS_TARGETS, DEFAULT_SETTINGS,
    POST_IMPL_SIGNOFF_TARGETS, QUIET_BY_DEFAULT_TARGETS, SETUP_ONLY_TARGETS,
    SETUP_STAGES, SETUP_TARGETS, STREAM_BY_DEFAULT_TARGETS, TECHNOLOGY_TARGETS,
    TargetSession,
)



# ---------------------------------------------------------------------------
# Configuration data
# ---------------------------------------------------------------------------

PathLike = str | os.PathLike[str] | Path | None
TargetSpec = tuple[str, str, tuple[str, ...]]
# Parameter bundles keep the target table compact; every value is still overrideable.
NONE = ()
CLOCKS = ("N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS")
BASE = ("TOP", "RUN_ID", "WORKSPACE", *CLOCKS)
COMMON = (*BASE, "RUN_TOP", "FORCE")
IP_DEV = (*BASE, "REG_ITF", "FORCE")
IPXACT = (*IP_DEV, "IPXACT_VENDOR", "IPXACT_LIBRARY", "IPXACT_VERSION")
SDC_INTENT = (*BASE, "FORCE", "SDC_IO_DELAY_PCT")
SPEC = (*BASE, "IP_NAME", "FORCE")
FETCH = (*BASE, "VENDOR", "TARGET", "FORCE")
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
    "RESET_SETTLE_CYCLES",
    "REGRESSION_BACKENDS",
    "COVERAGE",
    "COVERAGE_DETAIL_LIMIT",
    "WAVE_FORMAT",
    "WAVE_FILE",
)
VIEW = (*COMMON, "PDK", "SIGNOFF_STAGE", "SIM_NAME", "WAVE_VIEWER", "SURFER_BACKEND")
SYN = (*COMMON, "PDK", "PDK_ROOT", "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT", "VSV", "LIB_SYN", "LIBS", "ORS", "ORS_TECH", "TIEHI_CELL_AND_PORT", "TIELO_CELL_AND_PORT", "MIN_BUF_CELL_AND_PORTS")
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
PNR = (*COMMON, "PDK", "PDK_ROOT", "CLK_PERIOD", "ORS", "ORS_TECH", "PNR_HOLD_SLACK_MARGIN")
IP_LOAD = (*COMMON, "REG_ITF", "IP_NAME", "IP_VERSION")
QUALIFY = (*COMMON, "REG_ITF", "IP_NAME", "IP_VERSION", "QUAL_LEVEL")
IP_SAVE = tuple(dict.fromkeys((*EQUIV, *SIGNOFF, "REG_ITF", "IP_NAME", "IP_VERSION", "IP_LIBRARY_ROOT", "QUAL_LEVEL")))
SOC = (*COMMON, "HOST", "SOC_CFG_MODE", "DEVLIST")
FSM = (*BASE, "FSM", "FORCE")
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
    "spec": ("IP flow", "Generate the authoritative Digital IP spec/requirements/test-plan scaffold", SPEC),
    "hjson": ("IP flow", "Generate an HJSON register template", IP_DEV),
    "sdc": ("IP flow", "Initialize the canonical authored <TOP>.sdc timing intent", SDC_INTENT),
    "model": ("DV functional", "Generate Python model, CSR regmap, and test scaffolds", SIM),
    "tb": ("DV functional", "Generate a SystemVerilog testbench scaffold", SIM),
    "reg": ("IP flow", "Generate register RTL from HJSON", IP_DEV),
    "doc": ("IP flow", "Generate register documentation", IP_DEV),
    "systemrdl": ("Interchange", "Export register maps as SystemRDL", IP_DEV),
    "ipxact": ("Interchange", "Export IEEE 1685-2022 IP-XACT component metadata", IPXACT),
    "rtl_stub": ("IP flow", "Generate RTL core and aligned top wrapper", IP_DEV),
    "top_from_core": ("IP flow", "Regenerate top wrapper from edited core ports", IP_DEV),
    "flist": ("IP flow", "Generate Slang-ordered common/IP RTL filelists", IP_DEV),
    "driver": ("IP flow", "Generate C driver files from HJSON", IP_DEV),
    "fetch": ("IP flow", "Fetch or update a vendored dependency", FETCH),
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
    "eqy": ("Signoff", "Run RTL-to-synthesis EQY equivalence from the authored scaffold", EQUIV),
    "compile_syn": ("Signoff", "Compile post-synthesis simulation", SIGNOFF),
    "sim_syn": ("Signoff", "Run post-synthesis simulation", SIGNOFF),
    "compile_post_syn": ("Gate simulation", "Compile post-synthesis gate-level simulation with Icarus", GATE_SIM),
    "sim_post_syn": ("Gate simulation", "Run post-synthesis gate-level simulation with optional SDF", GATE_SIM),
    "sim_post_syn_all": ("Gate simulation", "Run every selected post-synthesis GLS test/timing combination with one backend", GATE_SIM_ALL),
    "compile_post_impl": ("Gate simulation", "Compile post-implementation gate-level simulation with Icarus", GATE_SIM),
    "signoff_post_impl": ("Post-implementation signoff", "Run post-implementation SDF, STA and vectorless power", SIGNOFF),
    "sdf_post_impl": ("Post-implementation signoff", "Write post-implementation SDF from final netlist, SDC and SPEF", SIGNOFF),
    "sta_post_impl": ("Post-implementation signoff", "Run SPEF-aware STA with propagated clock reporting", SIGNOFF),
    "power_estimate_post_impl": ("Post-implementation signoff", "Estimate post-implementation power with extracted parasitics", SIGNOFF),
    "sim_post_impl": ("Gate simulation", "Run post-implementation gate-level simulation with optional SDF", GATE_SIM),
    "sim_post_impl_all": ("Gate simulation", "Run every selected post-implementation GLS test/timing combination", GATE_SIM_ALL),
    "power_analysis_post_impl": ("Post-implementation signoff", "Analyze post-implementation power for one GLS workload", SIGNOFF),
    "power_analysis_post_impl_all": ("Post-implementation signoff", "Analyze post-implementation power for all matching GLS workloads", SIGNOFF),
    "fusion_analysis_post_impl": ("Post-implementation signoff", "Correlate routed timing and power for one GLS workload", SIGNOFF),
    "fusion_analysis_post_impl_all": ("Post-implementation signoff", "Correlate routed timing and power for all GLS workloads", SIGNOFF),
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
    "qualify": ("Run metadata", "Validate the current release against the Digital IP qualification policy", QUALIFY),
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
    "fsoc_init": ("SoC flow", "Initialize FuseSoC metadata", SOC),
    "fsoc": ("SoC flow", "Generate FuseSoC core file", SOC),
    "xbar_init": ("SoC flow", "Generate crossbar input config", SOC),
    "xbar_build": ("SoC flow", "Run tlgen for crossbar RTL", SOC),
    "soc": ("SoC flow", "Generate SoC RTL", SOC),
    "soc_uart_gen": ("SoC flow", "Generate UART-host SoC artifacts", SOC),
    "soc_ibex_gen": ("SoC flow", "Generate Ibex-host SoC artifacts", SOC),
    "sw_soc": ("SoC flow", "Generate SoC software scaffold", SOC),
    "soc_prepare": ("SoC flow", "Prepare SoC build directory", SOC),
    "soc_build_sw": ("SoC flow", "Build SoC software", SOC),
    "soc_sim": ("SoC flow", "Build SoC simulator", SOC),
    "soc_run": ("SoC flow", "Run SoC simulation", SOC),
    "soc_view": ("SoC flow", "Open SoC waveform", SOC),
    "fsm_setup": ("FSM flow", "Set up the FSM generator", FSM),
    "fsm_example_load": ("FSM flow", "Load the FSM example inputs", FSM),
    "fsm_gen": ("FSM flow", "Generate FSM RTL", FSM),
    "fsm_plot": ("FSM flow", "Plot FSM diagrams", FSM),
    "fsm_install": ("FSM flow", "Install FSM artifacts into the IP run", FSM),
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
# Public API
# ---------------------------------------------------------------------------

class FlexSoC:
    """Configure and execute FlexSoC backend targets."""

    @staticmethod
    def _target(name: str) -> str:
        """Accept exact, dashed, or underscored target spelling."""
        for item in (name, name.replace("-", "_"), name.replace("_", "-")):
            if item in TARGETS:
                return item
        raise ValueError(f"unknown target {name!r}; run `fx commands` to list targets")

    @staticmethod
    def _target_object(name: str) -> FlexSoCTargetInfo:
        """Build one target object from the unified table."""
        group, description, params = TARGETS[name]
        return FlexSoCTargetInfo(name, group, description, params)

    @staticmethod
    def _path(value: PathLike, fallback: Path) -> Path:
        """Resolve a path-like value or fallback."""
        return (Path(value) if value is not None else fallback).resolve()

    @staticmethod
    def _upper(values: Mapping[str, Any]) -> dict[str, str]:
        """Normalize setting names to uppercase strings."""
        return {str(key).upper(): str(value) for key, value in values.items() if value is not None}

    @staticmethod
    def _safe_log_name(value: str) -> str:
        """Return a filesystem-safe log filename fragment."""
        safe = re.sub(r"[^A-Za-z0-9_.-]+", "_", str(value).strip())
        return safe.strip("._") or "target"

    @staticmethod
    def _scenario_log_value(value: str) -> str:
        """Render SDF min/typ/max selectors as their aligned ff/tt/ss scenarios."""
        tokens = [part for part in re.split(r"[\s,]+", str(value).strip()) if part]
        return " ".join(SDF_MODE_TO_CORNER.get(token.lower(), token) for token in tokens)

    @classmethod
    def _selector_log_suffix(cls, selectors: tuple[tuple[str, str], ...]) -> str:
        """Return a concise suffix containing only non-default matrix selectors."""
        parts: list[str] = []
        for label, value in selectors:
            text = str(value).strip()
            if not text or text.lower() == "all":
                continue
            parts.extend((label, cls._safe_log_name(text)))
        return "_".join(parts)

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
        self.settings = self._upper({**base_values, **env_values, **values})
        self.execution_targets = dict(execution_targets or {}) or None

    @property
    def project_root(self) -> Path:
        """Return the repository root used as cwd."""

        return self._path(self.config.project_root, Path.cwd())

    @property
    def workdir(self) -> Path:
        """Return the explicit or persistently configured FlexSoC workspace."""

        selected = self.config.workdir or self.settings.get("WORKSPACE")
        return self._path(selected, self.project_root / "workspace")

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

        self.settings.update(self._upper(values))
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

        return tuple(self._target_object(name) for name in TARGETS)

    def target_names(self) -> tuple[str, ...]:
        """Return only callable target names."""

        return tuple(TARGETS)

    def target_info(self, target: str) -> FlexSoCTargetInfo:
        """Return metadata for one target."""

        return self._target_object(self._target(target))

    def values(self, overrides: Mapping[str, Any] | None = None) -> dict[str, str]:
        """Merge defaults, discovered PDK views, workspace, and call overrides."""

        call_overrides = self._upper(dict(overrides or {}))
        explicit = self._upper({**DEFAULT_SETTINGS, **self.settings, **call_overrides})
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
            from .backend.core import PdkManager

            pdk_values = PdkManager.settings(
                self.project_root,
                pdk_name,
                explicit.get("PDK_ROOT"),
            )
        except ValueError:
            # Preserve target preview/help for a not-yet-fetched PDK. Commands
            # that actually need technology views will fail at their tool
            # boundary with the missing LIB/PRIM path instead of breaking lint.
            pdk_values = {"PDK": pdk_name}

        values = self._upper({"WORKSPACE": self.workdir, **pdk_values, **explicit})
        from .backend.core import ClockConfig
        from .backend.core import PDKRunLayout

        values.update(ClockConfig.from_values(values).to_settings())
        values.update(PDKRunLayout.settings_from_values(self.project_root, values))
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
        name = target if setup else self._target(target)
        public = TargetSession.setup_public(name) if setup else name
        if public in POST_IMPL_SIGNOFF_TARGETS:
            overrides = {**overrides, "SIGNOFF_STAGE": "post_route"}
        values = self.values(overrides)
        params = set(TARGETS.get(public, ("", "", ()))[2])
        call_values = self._upper(overrides)
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

        requested = tuple(self._target(target) for target in targets)
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

        from .backend.core.runtime.execution import (
        Terminal,
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
                    if self._compact_visible(Terminal.strip_ansi(line)):
                        self.console.write(line + "\n")
                self.console.flush()

            def write(self, text: str) -> int:
                plain = Terminal.strip_ansi(text)
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
                        if self._compact_visible(Terminal.strip_ansi(pending)):
                            self.console.write(pending)
                    self.console.flush()

        results: list[FlexSoCResult] = []
        for command in commands:
            public = TargetSession.setup_public(command.target) if command.target in SETUP_STAGES else command.target
            _, description, _ = TARGETS.get(public, ("Target", "Run target", ()))
            stream = command.target in STREAM_BY_DEFAULT_TARGETS and not capture and not live
            quiet = command.target in QUIET_BY_DEFAULT_TARGETS and not capture and not live
            log_path = self._command_log_path(command)
            log_path.parent.mkdir(parents=True, exist_ok=True)

            stdout = io.StringIO() if capture else None
            stderr = io.StringIO() if capture else None
            rc, error = 0, None

            if not capture:
                Terminal.print_target_start(command.target, description)
                if command.target in TECHNOLOGY_TARGETS and not live and not stream:
                    Terminal.print_label(
                        "technology",
                        f"pdk={command.values.get('PDK')} syn={command.values.get('SYNDIR')}",
                    )
                Terminal.print_log(log_path)

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
                        value = TargetSession(
                            self.project_root, self.workdir, command.values,
                            settings=self.settings, execution_targets=self.execution_targets, on=on,
                        ).execute(command.target)
                        rc = self._returncode(value)
                    finally:
                        for key, value in previous.items():
                            if value is None:
                                os.environ.pop(key, None)
                            else:
                                os.environ[key] = value

                    if capture:
                        log.write(Terminal.strip_ansi((stdout.getvalue() if stdout else "") + (stderr.getvalue() if stderr else "")))
            except Exception as exc:
                rc, error = 2, exc
                message = f"[error] {exc}\n"
                if capture and stderr is not None:
                    stderr.write(message)
                    log_path.write_text(
                        Terminal.strip_ansi((stdout.getvalue() if stdout else "") + stderr.getvalue()),
                        encoding="utf-8",
                    )
                else:
                    with log_path.open("a", encoding="utf-8") as log:
                        log.write(Terminal.strip_ansi(message))
                    print(message, end="", flush=True)

            if not capture:
                Terminal.print_target_result(command.target, rc)
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
        """Normalize a backend result to one public target return code."""
        return TargetSession.returncode(value)

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
        name = self._safe_log_name(command.target)
        if str(values.get("DEBUG", "")).strip().lower() in {"1", "true", "yes", "on"}:
            name += "_debug"
        if command.target in {"sim", "sim_v", "sim_sv", "cocotb"} and values.get("TEST_NAME"):
            name = f"{name}_{self._safe_log_name(values['TEST_NAME'])}"
        if command.target in {"sim_post_syn_all", "sim_post_impl_all"}:
            selectors = [
                ("tests", values.get("TEST_NAMES", "all")),
                ("timing", self._scenario_log_value(values.get("TIMING_MODES", "all"))),
            ]
            backend = values.get("GLS_BACKEND", DEFAULT_SETTINGS["GLS_BACKEND"])
            if backend != DEFAULT_SETTINGS["GLS_BACKEND"]:
                selectors.insert(1, ("backend", backend))
            suffix = self._selector_log_suffix(tuple(selectors))
            if suffix:
                name = f"{name}_{suffix}"
        elif (
            (registered := BACKEND_TARGETS.get(command.target)) is not None
            and registered.is_gls
            and registered.action != "gls_all"
            and values.get("TEST_NAME")
        ):
            name = "_".join(
                (
                    name,
                    self._safe_log_name(values["TEST_NAME"]),
                    self._safe_log_name(values.get("GLS_BACKEND", "sv")),
                    self._safe_log_name(self._scenario_log_value(values.get("TIMING_MODE", "zero"))),
                )
            )
        if command.target in ACTIVITY_ANALYSIS_TARGETS:
            if command.target.endswith("_all"):
                suffix = self._selector_log_suffix(
                    (
                        ("tests", values.get("POWER_TEST_NAMES", "all")),
                        ("backends", values.get("POWER_GLS_BACKENDS", "all")),
                        ("timing", self._scenario_log_value(values.get("POWER_TIMING_MODES", "all"))),
                    )
                )
                if suffix:
                    name = f"{name}_{suffix}"
            else:
                selectors = (
                    values.get("POWER_TEST_NAME", values.get("TEST_NAME", "smoke")),
                    values.get("POWER_GLS_BACKEND", "sv"),
                    self._scenario_log_value(values.get("POWER_TIMING_MODE", "typ")),
                )
                name = "_".join((name, *(self._safe_log_name(value) for value in selectors)))
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

