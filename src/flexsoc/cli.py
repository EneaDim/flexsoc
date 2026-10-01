"""Readable Typer/Prompt Toolkit front-end for FlexSoC."""

from __future__ import annotations

import json
import os
import shlex
import sys
from pathlib import Path
from typing import Annotated, Iterable, Mapping

from .api import TARGETS, FlexSoC, FlexSoCConfig
from .backend.core.flow.session import (
    DEBUG_TARGETS, DEFAULT_SETTINGS, SETUP_ONLY_TARGETS, SETUP_TARGETS, WorkspaceFlow,
)
from .backend.core.flow.target import BACKEND_TARGETS

try:  # Keep the entry point understandable if the new CLI deps are not installed yet.
    import click
    import typer
    from rich import box
    from rich.console import Console
    from rich.panel import Panel
    from rich.table import Table
    from .backend.core.render.show import ShowRenderer
except ModuleNotFoundError as exc:  # pragma: no cover - exercised only in incomplete envs.
    _MISSING = exc.name
else:
    _MISSING = ""


if _MISSING:  # pragma: no cover - exercised only in incomplete envs.

    class FlexSoCCli:
        """CLI entry point used when optional front-end dependencies are missing."""

        def __call__(self, argv: list[str] | None = None) -> int:
            del argv
            print(
                f"missing CLI dependency: {_MISSING}\n"
                "run: uv sync\n"
                "then: uv run fx --help",
                file=sys.stderr,
            )
            return 2

    app = FlexSoCCli()


else:
    console = Console()
    error_console = Console(stderr=True)
    PSEUDO_COMMANDS = (
        "help", "settings", "commands", "show", "requirements", "testplan", "meta",
        "doctor", "pdk", "shell",
    )
    PRIVATE_CLI_TARGETS = frozenset({
        "formal_csr", "formal_csr_bmc", "formal_csr_prove", "formal_csr_cover",
        "formal_bmc", "formal_prove", "formal_cover",
        "sim_tests", "sim_post_syn", "sim_post_syn_all", "sim_post_impl", "sim_post_impl_all",
        "sta_post_impl",
        "power_estimate_post_impl",
        "power_analysis_all", "power_analysis_post_impl", "power_analysis_post_impl_all",
        "fusion_analysis", "fusion_analysis_all",
        "fusion_analysis_post_impl", "fusion_analysis_post_impl_all",
    })
    CANONICAL_CLI_TARGETS = ("formal", "sim", "sta", "power-estimate", "power-analysis", "fusion")

    OPTION_WORDS = (
        "--set",
        "--unset",
        "--project-root",
        "--workdir",
        "--user",
        "--system",
        "--profile",
        "--jobs",
        "--reset",
        "--force",
        "--overwrite",
        "--setup",
        "--rtl",
        "--post-syn",
        "--post-impl",
        "--all",
        "--csr",
        "--bmc",
        "--prove",
        "--cover",
        "--dry-run",
        "--script",
        "--capture",
        "--live",
        "--debug",
        "--save-output",
        "-o",
        "--json",
        "--less",
        "--check",
        "--info",
        "--install-completion",
        "--show-completion",
    )

    HELP = """\
FlexSoC command runner.

Run `fx` or `fx --help` to show the readable orange/cyan guide.
Use `fx commands` to list every backend target.
"""

    typer_app = typer.Typer(
        add_completion=True,
        no_args_is_help=False,
        rich_markup_mode="rich",
        pretty_exceptions_show_locals=False,
        context_settings={"help_option_names": ["-h", "--help"]},
    )

    # -----------------------------------------------------------------------
    # Completion and help text
    # -----------------------------------------------------------------------



    HELP_WORDS = {"help", "info", "-h", "--help"}
    SETUP_ONLY = SETUP_ONLY_TARGETS
    PUBLIC_KEYWORDS = tuple(name for name in SETUP_TARGETS if name not in PRIVATE_CLI_TARGETS)

    FLOW_GUIDE = (
        (
            "1. Configure the run",
            (
                ("fx settings TOP=my_ip RUN_TOP=my_ip RUN_ID=dev", "Persist run identity."),
                ("fx settings N_CLOCKS=1 CLOCK_DOMAINS=core:clk_i:rst_ni:10:low", "Declare clock/reset intent once."),
                ("fx doctor", "Check Python and the locally installed EDA tools."),
                ("fx pdk list | fx pdk info sky130 | fx pdk use sky130", "Inspect and activate a digital PDK."),
            ),
        ),
        (
            "2. Create a new IP scaffold",
            (
                ("fx setup --force", "Create the run directory tree."),
                ("fx hjson --force", "Create the CSR HJSON source of truth."),
                ("fx reg doc --force", "Generate register RTL and documentation."),
                ("fx rtl_stub --force", "Create the editable RTL core and aligned wrapper."),
                ("fx top_from_core flist --force", "Refresh the wrapper and ordered RTL filelists."),
            ),
        ),
        (
            "3. Build functional DV",
            (
                ("fx model --setup --force", "Create the model, RegMap API, and scenario source."),
                ("fx tests_gen | fx test_gen --set TEST_NAME=smoke", "Generate all tests or one named test."),
                ("fx tests", "List the generated test catalogue."),
                ("fx regression --setup", "Generate SV and cocotb drivers from the current interfaces."),
                ("fx sim --set TEST_NAME=smoke", "Run one SystemVerilog vector test."),
                ("fx cocotb --set TEST_NAME=smoke", "Run the same vectors through cocotb."),
                ("fx regression | fx coverage", "Run the catalogue and inspect coverage."),
            ),
        ),
        (
            "4. Close RTL and properties",
            (
                ("fx lint", "Run one Slang pass and one Verilator pass with P0-P3 classification."),
                ("fx slang_hier", "Generate elaborated hierarchy and AST evidence in one Slang run."),
                ("fx formal --setup | fx formal", "Run all applicable formal stages; use --csr/--bmc/--prove/--cover to select one view."),
            ),
        ),
        (
            "5. Synthesize and prepare equivalence",
            (
                ("fx syn --setup | fx syn", "Generate synthesis scripts, then produce the mapped netlist."),
                ("fx eqy --setup | fx eqy", "Materialize the authored EQY scaffold, then run equivalence explicitly when desired."),
                ("fx eqy --summary | fx eqy --show | fx eqy --debug", "Inspect canonical equivalence evidence without rerunning EQY."),
            ),
        ),
        (
            "6. Run post-synthesis sign-off",
            (
                ("fx sdc --setup", "Initialize the single authored constraints/<TOP>.sdc timing contract."),
                ("fx signoff --setup", "Generate OpenSTA Tcl families that consume constraints/<TOP>.sdc."),
                ("fx sdf | fx sta | fx power-estimate", "Produce corner SDF, timing, and vectorless power."),
                ("fx compile_post_syn --set TEST_NAME=smoke --set TIMING_MODE=typ", "Compile one named GLS workload."),
                ("fx sim --post-syn --set TEST_NAME=smoke --set TIMING_MODE=typ", "Run one post-synthesis GLS workload."),
                ("fx sim --post-syn --all", "Run all generated tests/timing modes with the selected GLS backend."),
                ("fx power-analysis --set POWER_TEST_NAME=smoke --set POWER_TIMING_MODE=typ", "Analyze power for one GLS workload."),
                ("fx fusion --set POWER_TEST_NAME=smoke --set POWER_TIMING_MODE=typ", "Correlate worst timing paths and gate power for one workload."),
                ("fx fusion --all --set POWER_TEST_NAMES=all", "Run fusion for every matching GLS workload."),
            ),
        ),
        (
            "7. Implement and close routed timing",
            (
                ("fx pnr", "Run OpenROAD and produce the final netlist, SDC, SPEF, ODB, and GDS."),
                ("fx physical_signoff", "Run ORFS physical closure first: route DRC, antenna evidence, GDS DRC, LVS, and IR/PDN evidence."),
                ("fx signoff_post_impl --setup | fx sdf_post_impl | fx sta --post-impl", "Write routed SDF, then consume <TOP>.sdc plus routed SPEF for propagated-clock/interconnect timing."),
                ("fx sim --post-impl --all", "Run timing-aware post-implementation GLS across selected tests and scenarios."),
                ("fx power-estimate --post-impl", "Run vectorless routed power estimation."),
                ("fx power-analysis --post-impl --all | fx fusion --post-impl --all", "Use routed GLS activity for activity power and timing/power correlation."),
                ("fx manifest | fx metrics | fx check", "Collect identity, snapshot metrics, then render the closure dashboard."),
                ("fx ip_save", "Save a reusable IP package after closure."),
            ),
        ),
        (
            "8. Reuse an existing IP",
            (
                ("fx ip_load --set TOP=cordic --set RUN_TOP=cordic", "Load authored and generated IP collateral."),
                ("fx requirements --less | fx testplan --less | fx meta --less", "Inspect the loaded contract and metadata."),
                ("fx regmap_py tests_gen regression --setup", "Refresh generator-owned DV collateral."),
                ("fx tests_gen --check", "Verify config.regs and vector files still match the Python generators."),
                ("fx lint regression formal syn", "Run the standard reusable gates; run EQY explicitly per IP when its profile is ready."),
                ("fx soc_start", "Initialize the SoC workspace from loaded IPs; run later SoC steps explicitly."),
            ),
        ),
    )

    PARAMETER_HELP = {
        "TOP": "Logical IP top module.",
        "RUN_TOP": "Run-directory owner; normally the same as TOP.",
        "RUN_ID": "Named run instance below runs/<RUN_TOP>/.",
        "WORKSPACE": "Persistent workspace root; explicit --workdir overrides it.",
        "FORCE": "Allow regeneration of generator-owned outputs; prefer --force.",
        "N_CLOCKS": "Number of declared clock domains.",
        "CLOCK_DOMAINS": "Comma-separated name:clock:reset:period:polarity domain declarations.",
        "CLOCK_RELATIONSHIPS": "Explicit async/sync/generated relationships between domains.",
        "PDK": "Active technology profile name.",
        "PDK_ROOT": "Root of an already installed PDK.",
        "CLK_PERIOD": "Primary clock period override in nanoseconds.",
        "REG_ITF": "External register interface intent: tlul, reg_iface, or axi_lite.",
        "TESTBENCH": "Testbench module/base name.",
        "TEST_NAME": "Select one functional or GLS test by name.",
        "SIM_NAME": "Select one generated waveform by simulation suffix, for example smoke_sv_tt.",
        "TEST_NAMES": "Select multiple functional tests.",
        "TEST_ROOT": "Override the generated vector-test directory.",
        "REGCFG": "Override the test config.regs input.",
        "DATA_IN": "Override the input command-vector file.",
        "DATA_OUT": "Override the expected-output vector file.",
        "COMPILER": "RTL simulation compiler/backend.",
        "REGRESSION_BACKENDS": "Simulation backends included in regression.",
        "SEED": "Deterministic simulation or vector-generation seed.",
        "RESET_SETTLE_CYCLES": "Post-reset cocotb settling cycles before register traffic.",
        "WAVE_FORMAT": "Waveform format: fst or vcd.",
        "WAVE_FILE": "Explicit waveform output path.",
        "WAVE_VIEWER": "Waveform viewer executable, normally surfer or gtkwave.",
        "SURFER_BACKEND": "Surfer GUI backend policy: auto, x11, or wayland; auto avoids Wayland under WSL.",
        "COCOTB_WAVES": "Enable cocotb waveform generation.",
        "COVERAGE": "Enable or select coverage collection.",
        "COVERAGE_SHOW_LIMIT": "Maximum uncovered points printed by `fx coverage --show`; 0 means all.",
        "LINT_PROFILE": "Lint profile: critical for PRs or everything for full/nightly analysis.",
        "SLANG_WAIVER_FILE": "Optional native Slang TOML waiver file.",
        "SLANG_HIER": "slang-hier executable used for hierarchy + AST structural evidence.",
        "VERILATOR_WAIVER_FILE": "Optional Verilator .vlt control / waiver file.",
        "VSV": "SystemVerilog/Verilog language selection used by backend scripts.",
        "GLS_SIMULATOR": "Gate-level simulator executable/family.",
        "GLS_BACKEND": "Gate-level driver backend, normally sv or cocotb.",
        "TIMING_MODE": "Technical GLS timing selection: zero, unit, min, typ, or max; SDF-backed artifacts use ff/tt/ss scenario names.",
        "TIMING_MODES": "Technical selections for sim_post_syn_all; all means zero/unit/min/typ/max, named zero/unit/ff/tt/ss in artifacts.",
        "GLS_UNIT_DELAY": "Delay assigned in unit-delay GLS mode.",
        "SDF_STRICT": "Fail when SDF annotation is missing or incomplete.",
        "SDF_FILE": "Explicit SDF file used for GLS.",
        "SDF_CORNER": "Corner selected for SDF generation or annotation.",
        "NETLIST": "Explicit synthesized or post-implementation netlist.",
        "SIGNOFF_STAGE": "Sign-off source stage: post_syn or post_impl.",
        "STA_MODES": "STA analyses to run. Defaults to setup for post_syn and setup hold for post_impl.",
        "SPEF_FILE": "Extracted parasitics for post-implementation timing/power.",
        "PNR_SDC_FILE": "Post-implementation SDC override.",
        "LIBS": "Corner Liberty list or mapping.",
        "LIB_SYN": "Synthesis/default Liberty file.",
        "MACRO_LIBS": "Additional macro Liberty files.",
        "PRIM": "Standard-cell functional Verilog models.",
        "STA_ENDPOINT_GROUP_LIMIT": "Maximum path groups reported by STA/fusion.",
        "STA_ENDPOINT_PATH_LIMIT": "Worst paths retained per endpoint/group.",
        "STA_NEAR_CRITICAL_SETUP": "Setup-slack window included as near-critical.",
        "STA_NEAR_CRITICAL_HOLD": "Hold-slack window included as near-critical.",
        "POWER_ACTIVITY": "Default vectorless input switching activity.",
        "POWER_DUTY": "Default vectorless input duty cycle.",
        "POWER_GLOBAL_ACTIVITY": "Global activity assumption for power_estimate.",
        "POWER_TOP_INSTANCES": "Number of highest-power gates analyzed and cross-referenced.",
        "POWER_TEST_NAME": "Select one GLS workload for power/fusion.",
        "POWER_TEST_NAMES": "Select GLS workloads for *_all; use all for discovery.",
        "POWER_GLS_BACKEND": "Preferred workload backend for *_all; exact backend for single power/fusion.",
        "POWER_GLS_BACKENDS": "Candidate workload backends for *_all; they are alternatives, not cumulative requirements.",
        "POWER_TIMING_MODE": "Select one aligned sign-off scenario by GLS mode: min→ff, typ→tt, max→ss.",
        "POWER_TIMING_MODES": "Select aligned sign-off scenarios for *_all by GLS mode; all means min/typ/max.",
        "POWER_VCD_SCOPE": "VCD hierarchy scope to annotate, or auto.",
        "POWER_DUT_INSTANCE": "DUT instance used to resolve activity scope, or auto.",
        "FST2VCD": "FST-to-VCD converter executable.",
        "PATH_VIEW_FILE": "STA report opened by path_view.",
        "NPATHS": "Number of paths loaded into path_view.",
        "FORMAL_DEPTH": "Default formal depth.",
        "FORMAL_BMC_DEPTH": "Bounded model-check depth.",
        "FORMAL_BMC_APPEND": "Additional BMC steps after the base depth.",
        "SBY": "SymbiYosys executable.",
        "EQY": "EQY executable.",
        "EQY_JOBS": "Parallel EQY partition jobs.",
        "EQY_TIMEOUT": "Overall EQY strategy timeout.",
        "EQY_STRATEGY_ORDER": "Ordered SAT/SMTBMC/PDR strategy portfolio.",
        "EQY_RESET_CYCLES": "Reset cycles assumed by reset normalization.",
        "CDC_RDC_HEARTBEAT": "Live-mode progress heartbeat interval in seconds.",
        "CDC_RDC_STRICT": "Return non-zero when structural ERROR findings make CDC/RDC status FAIL.",
        "IP_NAME": "Saved or loaded IP package name.",
        "IP_VERSION": "Saved or loaded IP package release version (for example 1.0.0).",
        "IP_LIBRARY_ROOT": "IP package library root.",
        "QUAL_LEVEL": "Qualification target: auto, contract, rtl, netlist, technology, or physical_signoff.",
        "HOST": "Selected SoC host integration.",
        "SOC_CFG_MODE": "SoC configuration mode.",
        "DEVLIST": "SoC device/IP list.",
        "TARGET_SYN": "Yosys synthesis target/profile.",
        "TARGET_OPT": "Yosys/ABC synthesis profile: area0..area3 or delay0..delay4.",
        "STAGE": "Generated setup stage whose manually modified collateral is being validated.",
        "ORS": "OpenROAD-flow-scripts root.",
        "ORS_TECH": "OpenROAD platform/technology name.",
    }

    TARGET_EXAMPLES = {
        "hjson": ("fx hjson --force",),
        "reg": ("fx reg --force",),
        "rtl_stub": ("fx rtl_stub --force", "fx top_from_core --force"),
        "model": ("fx model --setup --force",),
        "test_gen": ("fx test_gen --set TEST_NAME=smoke",),
        "tests": ("fx tests",),
        "sim": (
            "fx sim --set TEST_NAME=smoke --set COMPILER=verilator",
            "fx sim --all",
            "fx sim --post-syn --set TEST_NAME=smoke --set TIMING_MODE=typ",
            "fx sim --post-impl --all",
        ),
        "cocotb": ("fx cocotb --set TEST_NAME=smoke --set COCOTB_WAVES=1",),
        "regression": ("fx regression", "fx regression --summary", "fx regression --show", "fx regression --debug"),
        "coverage": ("fx coverage", "fx coverage --summary", "fx coverage --show", "fx coverage --debug"),
        "formal": (
            "fx formal --setup", "fx formal", "fx formal --csr",
            "fx formal --csr --prove", "fx formal --bmc", "fx formal --summary",
        ),
        "view": (
            "fx view --set PDK=ihp-sg13g2 --set SIGNOFF_STAGE=post_syn "
            "--set SIM_NAME=smoke_sv_tt --set WAVE_VIEWER=surfer",
            "fx view --set PDK=ihp-sg13g2 --set SIGNOFF_STAGE=post_impl "
            "--set SIM_NAME=smoke_sv_tt --set WAVE_VIEWER=surfer",
        ),
        "syn": (
            "fx syn",
            "fx syn --setup --force",
            "fx syn --set TARGET_OPT=delay1",
        ),
        "eqy": ("fx eqy --setup", "fx eqy", "fx eqy --debug"),
        "pnr": (
            "fx pnr --setup --force", "fx pnr", "fx pnr --summary",
            "fx pnr --show", "fx pnr --debug",
        ),
        "sta": (
            "fx sta", "fx sta --post-impl", "fx sta --all --summary",
        ),
        "power_estimate": (
            "fx power-estimate", "fx power-estimate --post-impl",
            "fx power-estimate --all --summary",
        ),
        "signoff": ("fx signoff --setup --force", "fx signoff"),
        "lint": (
            "fx lint", "fx lint --summary", "fx lint --show --tool slang",
            "fx lint --debug --tool verilator",
        ),
        "slang_hier": (
            "fx slang_hier", "fx slang_hier --summary", "fx slang_hier --show",
            "fx slang_hier --debug",
        ),
        "cdc_rdc": (
            "fx cdc_rdc --setup --force", "fx cdc_rdc", "fx cdc_rdc --summary",
            "fx cdc_rdc --show", "fx cdc_rdc --debug",
        ),
        "compile_post_syn": (
            "fx compile_post_syn --set TEST_NAME=smoke "
            "--set GLS_BACKEND=sv --set TIMING_MODE=typ",
        ),
        "power_analysis": (
            "fx power-analysis --set POWER_TEST_NAME=smoke --set POWER_GLS_BACKEND=sv --set POWER_TIMING_MODE=typ",
            "fx power-analysis --all --set POWER_TEST_NAMES=all --set POWER_TIMING_MODES=all",
            "fx power-analysis --post-impl --all",
        ),
        "fusion_analysis": (
            "fx fusion --set POWER_TEST_NAME=smoke --set POWER_GLS_BACKEND=sv --set POWER_TIMING_MODE=typ",
            "fx fusion --all --set POWER_TEST_NAMES=all --set POWER_TIMING_MODES=all",
            "fx fusion --post-impl --all",
        ),
        "validate_override": (
            "fx validate_override --set STAGE=syn.setup",
            "fx check",
        ),
        "ip_load": ("fx ip_load --set IP_NAME=uart --set IP_VERSION=1.0.0 --set REG_ITF=tlul",),
        "ip_save": (
            "fx ip_save --set IP_NAME=uart --set IP_VERSION=1.0.0 --set REG_ITF=tlul --set QUAL_LEVEL=auto",
            "fx ip_save --force --set IP_NAME=uart --set IP_VERSION=1.0.0 --set REG_ITF=tlul --set QUAL_LEVEL=netlist",
        ),
        "qualify": ("fx qualify --set QUAL_LEVEL=rtl", "fx qualify --set QUAL_LEVEL=technology"),
    }

    PSEUDO_HELP = {
        "settings": (
            "Show or update persistent project settings and derived run paths.",
            ("fx settings", "fx settings TOP=my_ip RUN_ID=dev", "fx settings --reset ..."),
            ("--set KEY=VALUE", "--unset KEY", "--reset", "--workdir PATH", "--json"),
        ),
        "commands": (
            "List the complete backend target catalogue.",
            ("fx commands", "fx commands --json"),
            ("--json",),
        ),
        "show": (
            "Render canonical machine-readable run reports by stable key.",
            ("fx show keys", "fx show qualification", "fx show gls_post_syn", "fx show issues"),
            ("--set KEY=VALUE", "--workdir PATH", "--json"),
        ),
        "requirements": (
            "Render the authoritative requirements.yaml for the configured run.",
            ("fx requirements", "fx requirements --less", "fx requirements --json"),
            ("--less", "--set KEY=VALUE", "--workdir PATH", "--json"),
        ),
        "testplan": (
            "Render the authoritative testplan.yaml for the configured run.",
            ("fx testplan", "fx testplan --less", "fx testplan --json"),
            ("--less", "--set KEY=VALUE", "--workdir PATH", "--json"),
        ),
        "meta": (
            "Render design intent, qualification, provenance, and the configured run metadata inventory.",
            ("fx meta", "fx meta --less", "fx meta --json"),
            ("--less", "--set KEY=VALUE", "--workdir PATH", "--json"),
        ),
        "doctor": (
            "Check Python dependencies and the locally available EDA toolchain.",
            ("fx doctor", "fx doctor --json"),
            ("--json", "--workdir PATH"),
        ),
        "pdk": (
            "List, inspect, fetch, or activate a PDK profile.",
            ("fx pdk list", "fx pdk info sky130", "fx pdk fetch sky130", "fx pdk use sky130"),
            ("--set PDK_ROOT=PATH", "--force", "--json"),
        ),
        "shell": (
            "Open the interactive fx prompt with completion and history.",
            ("fx shell",),
            ("--workdir PATH",),
        ),
    }

    # -----------------------------------------------------------------------
    # Human-readable guide and command help
    # -----------------------------------------------------------------------







    TARGET_HELP_SECTIONS = {
        "lint": (
            (
                "Execution",
                (
                    ("Slang", "One full SystemVerilog elaboration with JSON diagnostics. It catches language/elaboration errors and broad static warnings such as widths, drivers, cases, undriven/unconnected signals, conversions, and related semantic issues."),
                    ("Verilator", "One independent --lint-only SystemVerilog pass with SARIF diagnostics. It adds a second implementation view for structural/control warnings such as width, latch, multidrive, pins/connections, sequencing, and style/static issues."),
                    ("runs", "Exactly one Slang run and one Verilator run. P0-P3 are classification only; --tool filters rendering and never triggers another run."),
                    ("PASS", "Both tools executed and produced valid native diagnostic evidence. Diagnostic priority does not gate lint while the policy is reporting-only."),
                ),
            ),
            (
                "Priority policy",
                (
                    ("P0", "Critical correctness-risk diagnostics: tool errors plus severe width/driver/latch/case/connectivity classes."),
                    ("P1", "High functional-risk diagnostics such as signedness/conversion, sequencing, comparison, shadowing, and related semantic hazards."),
                    ("P2", "Normal engineering warnings that should be reviewed but are not classified as P0/P1/P3."),
                    ("P3", "Low-risk hygiene/style diagnostics such as unused declarations/imports and presentation-oriented warnings."),
                ),
            ),
            (
                "Evidence views",
                (
                    ("--summary", "Status, total diagnostics, P0-P3 counts, and per-tool counts only."),
                    ("--show", "Canonical diagnostics from summary.json; does not rerun or reparse the tool logs."),
                    ("--debug", "Show plus hints, exact tool commands, and native JSON/SARIF/log paths."),
                    ("--tool", "Filter summary/show/debug to slang or verilator; never changes execution."),
                ),
            ),
        ),
        "sim": (
            (
                "Simulation selection",
                (
                    ("default / --rtl", "Run one RTL SystemVerilog vector test."),
                    ("--all", "Run every generated RTL SystemVerilog vector test."),
                    ("--post-syn", "Run one post-synthesis GLS workload."),
                    ("--post-syn --all", "Run the selected post-synthesis GLS matrix."),
                    ("--post-impl", "Run one routed GLS workload."),
                    ("--post-impl --all", "Run the selected routed GLS matrix."),
                ),
            ),
        ),
        "regression": (
            (
                "Execution",
                (
                    ("matrix", "Runs every generated functional test on the selected REGRESSION_BACKENDS. The canonical full regression uses SystemVerilog and cocotb over the same vectors."),
                    ("SV", "Compiles the generated SystemVerilog testbench once, then executes each test. Compile failure is recorded and remaining SV tests become NOT_RUN."),
                    ("cocotb", "Executes each generated test through the cocotb testbench using the selected simulator."),
                    ("coverage", "When enabled, each sub-run writes raw Verilator .dat evidence; coverage reporting is a separate target."),
                    ("PASS", "Every selected test/backend sub-run completed successfully. FAIL is execution outcome, not coverage quality."),
                ),
            ),
            (
                "Evidence views",
                (
                    ("--summary", "Status, test/sub-run counts, and per-backend pass/fail/not-run counts from summary.json."),
                    ("--show", "Canonical test × backend matrix from summary.json; no simulator is rerun and logs are not reparsed."),
                    ("--debug", "Show plus compile/failing/not-run log paths for direct diagnosis."),
                    ("summary.json", "dv/functional/regression/summary.json is the machine-readable execution contract."),
                ),
            ),
        ),
        "coverage": (
            (
                "Execution",
                (
                    ("merge", "Merges existing Verilator coverage databases into merged.dat. It does not rerun simulation."),
                    ("annotate", "Runs verilator_coverage annotation once and records line/type/hit information."),
                    ("report", "Normalizes scope/type percentages and uncovered points into summary.json."),
                    ("PASS", "Merge, annotation, and normalization completed successfully. Coverage percentage itself does not gate PASS."),
                ),
            ),
            (
                "Evidence views",
                (
                    ("--summary", "Compact design/all percentages and scope totals from summary.json."),
                    ("--show", "Summary plus uncovered points stored in summary.json; no coverage tool is rerun."),
                    ("--debug", "Show plus merged database, annotation directory, and merge/annotate log paths."),
                    ("COVERAGE_SHOW_LIMIT", "Limits uncovered rows printed by --show; 0 prints all stored points."),
                ),
            ),
        ),
        "formal": (
            (
                "Execution",
                (
                    ("default / --all", "Run all applicable automatic CSR and designer-authored formal stages."),
                    ("--csr", "Run only automatic CSR formal derived from register semantics."),
                    ("--bmc / --prove / --cover", "Run one designer-authored property stage."),
                    ("--csr --bmc|--prove|--cover", "Run one automatic CSR stage."),
                    ("properties", "Designer-authored properties under dv/formal/properties; absence is not an UNKNOWN result."),
                ),
            ),
            (
                "Lifecycle and evidence",
                (
                    ("--setup", "Generates SBY configurations. Automatic CSR properties are FlexSoC-owned; design formal requires real .sv/.v properties under dv/formal/properties."),
                    ("--summary", "Aggregate status and BMC/prove/cover counts from dv/formal/summary.json."),
                    ("--show", "Canonical CSR/properties × BMC/prove/cover matrix from summary.json."),
                    ("--debug", "Show plus SBY config, workdir, log, and trace paths. It never reruns SBY."),
                    ("PARTIAL", "An applicable formal stage exists but has not produced a valid native status yet."),
                ),
            ),
        ),
        "slang_hier": (
            (
                "Structural evidence",
                (
                    ("one elaboration", "Runs slang-hier once. The same elaborated design emits both the compact instance hierarchy and the full AST JSON with source information."),
                    ("hierarchy.txt", "Compact instance/module/source rows used for human inspection and lightweight structural consumers."),
                    ("ast.json", "Elaborated Slang AST for deeper downstream analysis. FlexSoC stores it as raw evidence and does not duplicate an AST parser here."),
                    ("summary.json", "Canonical status, command, metrics, normalized hierarchy rows, and artifact paths."),
                    ("non-gating", "This is a structural utility. Tool outcome is recorded in summary.json, but hierarchy collection does not qualify or fail the wider flow by itself."),
                ),
            ),
        ),
        "syn": (
            (
                "Execution",
                (
                    ("--setup", "Generates the Yosys/ABC scripts, constraints and repair collateral. It does not run synthesis."),
                    ("Yosys", "Performs logical synthesis and technology mapping using the selected TARGET_OPT profile."),
                    ("OpenROAD repair", "Runs only pre-placement electrical repair_design for slew/capacitance/fanout. It does not perform CTS or min-delay/hold repair."),
                    ("timing", "Post-synthesis release timing is qualified by STA setup checks; hold becomes sign-off blocking only after implementation/CTS."),
                    ("PASS", "The complete synthesis execution returned zero. Fresh setup alone never implies synthesis PASS."),
                ),
            ),
            (
                "Profiles and evidence",
                (
                    ("TARGET_OPT", "area0..area3 or delay0..delay4; the profile is part of setup provenance."),
                    ("summary.json", "Canonical execution status, Yosys QoR, diagnostics, repair metrics, scripts, logs and artifact paths."),
                    ("--summary", "Status, profile, cells, area and diagnostic counts only."),
                    ("--show", "Canonical synthesis QoR and final artifacts from summary.json; it never reparses logs."),
                    ("--debug", "Show plus generated script, raw log and artifact paths; it never reruns Yosys/OpenROAD."),
                    ("provenance", "STALE or MODIFIED setup collateral is rejected before run; regenerate setup or validate an intentional authored override."),
                ),
            ),
        ),
        "eqy": (
            (
                "Execution",
                (
                    ("--setup", "Materializes the authored EQY config/formal view. It does not run equivalence."),
                    ("run", "Runs EQY explicitly against RTL and the synthesized canonical netlist through ToolRunner/Executor."),
                    ("partitions", "EQY partitions the compare problem and may try multiple strategies per partition."),
                    ("PASS", "Execution completed and every discovered equivalence partition is PASS."),
                    ("REVIEW", "Evidence is incomplete or contains ERROR/TIMEOUT/UNKNOWN outcomes; this is not an equivalence PASS."),
                    ("FAILED", "At least one partition is a demonstrated FAIL, or execution failed without complete passing evidence."),
                ),
            ),
            (
                "Evidence views",
                (
                    ("--summary", "Overall execution/result status and partition counts from summary.json."),
                    ("--show", "Partition table with status and failing strategy from summary.json."),
                    ("--debug", "Show plus config/log/result paths and existing failing strategy logs/traces. It never launches probes or viewers."),
                    ("summary.json", "Canonical partition and strategy evidence under signoff/<pdk>/equivalence/rtl_vs_syn/."),
                ),
            ),
        ),
        "validate_override": (
            (
                "When to use it",
                (
                    ("MODIFIED", "Use validate_override only after intentionally editing a generated setup artifact by hand."),
                    ("STALE", "Configuration, source, or parent lineage changed. Rerun the setup phase with the intended settings; do not validate."),
                    ("INVALID", "Required files/provenance are missing or inconsistent. Repair inputs and rerun setup."),
                    ("CLEAN", "Nothing to validate; the generated collateral already matches its canonical setup."),
                    ("VALIDATED_OVERRIDE", "The exact manual edit is already accepted for the current lineage."),
                ),
            ),
            (
                "Typical flows",
                (
                    ("change TARGET_OPT", "`fx settings TARGET_OPT=delay1` → `fx syn --setup --force` → `fx syn`."),
                    ("manual .abc edit", "Run `fx syn --setup`, edit the generated .abc, then validate_override STAGE=syn.setup before `fx syn`."),
                ),
            ),
        ),
        "pnr": (
            (
                "Implementation",
                (
                    ("--setup", "Materializes the ORFS config.mk from the synthesized netlist and authored SDC. It does not run OpenROAD."),
                    ("run", "Runs one ORFS/OpenROAD implementation through CommandRequest -> ToolRunner -> Executor."),
                    ("phases", "Tracks the native ORFS import, floorplan, placement, CTS, routing, extraction, and finish checkpoints."),
                    ("PASS", "OpenROAD/ORFS returned success and all five canonical final artifacts exist: netlist, SDC, SPEF, ODB, and GDS."),
                ),
            ),
            (
                "Evidence views",
                (
                    ("--summary", "Status, phase/artifact counts, platform, and return code from impl/<pdk>/summary.json."),
                    ("--show", "Canonical implementation phases and final artifact paths from summary.json; no ORFS rediscovery."),
                    ("--debug", "Show plus exact command and raw implementation log path; it never reruns OpenROAD."),
                ),
            ),
        ),
        "sta": (
            (
                "Static timing analysis",
                (
                    ("default / --post-syn", "Uses the synthesized netlist with ideal clocks and no extracted interconnect. Setup runs by default and is the timing release gate."),
                    ("--post-impl", "Uses the implemented netlist, propagated clocks, and SPEF. Setup and hold both run by default and are sign-off blocking."),
                    ("--all", "Explicitly request all configured corners; this is already the default STA coverage."),
                    ("setup", "Maximum-delay/setup timing is gating at both stages."),
                    ("hold", "Minimum-delay timing is opt-in/advisory post-synthesis because CTS has not happened; it is gating post-implementation."),
                    ("recovery/removal", "Reset recovery/removal follows the same policy as hold: advisory post-synthesis, gating post-implementation."),
                    ("STA_MODES", "Override the stage default explicitly, for example `--set STA_MODES='setup hold'` to inspect advisory post-synthesis min timing."),
                    ("corners", "Runs the configured Liberty corners; STA corner coverage is independent from the sampled GLS min/typ/max matrix."),
                ),
            ),
            (
                "Evidence views",
                (
                    ("--summary", "Status plus gating WNS/TNS/violations, advisory violations, and unconstrained paths from summary.json."),
                    ("--show", "Per-corner setup/hold table with clock QoR from canonical summary.json."),
                    ("--debug", "Show plus violating/near-critical paths, constraint issues, reports, and artifact paths. It never reruns OpenSTA."),
                ),
            ),
        ),
        "power_estimate": (
            (
                "Vectorless power",
                (
                    ("model", "Runs OpenSTA power with configured input activity/duty assumptions and Liberty corner views; no waveform is required."),
                    ("default / --post-syn", "Use the synthesized netlist and configured Liberty corners."),
                    ("--post-impl", "Use the implemented netlist and SPEF with the same analysis owner."),
                    ("--all", "Explicitly request all configured corners; this is already the default vectorless estimate coverage."),
                    ("metrics", "Reports internal, switching, dynamic, leakage, and total power per corner."),
                ),
            ),
            ("Evidence views", (("--summary", "Status, corner count, and worst total power."), ("--show", "Per-corner canonical power table."), ("--debug", "Show plus power reports/log paths; no OpenSTA rerun."))),
        ),
        "power_activity": (
            (
                "Activity-based power",
                (
                    ("input", "Consumes successful SDF-backed GLS waveform evidence for one or more test/backend/timing workloads."),
                    ("qualification", "A workload is accepted only when GLS metadata, SDF scenario, annotation marker, and waveform are coherent."),
                    ("power", "Runs OpenSTA power for each selected workload/corner and records internal + switching as dynamic power."),
                    ("default / --post-syn", "Analyze one aligned post-synthesis GLS workload."),
                    ("--post-impl", "Use the routed netlist/parasitics and matching post-implementation GLS evidence."),
                    ("--all", "Analyze all matching workloads for the selected stage."),
                ),
            ),
            ("Evidence views", (("--summary", "Status and workload pass/fail counts."), ("--show", "Per-workload canonical power/timing rows."), ("--debug", "Show plus reports/logs and raw artifact paths; no analysis rerun."))),
        ),
        "fusion": (
            (
                "Timing / power fusion",
                (
                    ("purpose", "Correlates timing paths with activity-based power evidence for the same qualified workload."),
                    ("hotspots", "Identifies power-heavy instances and evaluates timing paths that traverse them; it does not replace STA or power sign-off."),
                    ("default / --post-syn", "Correlate one post-synthesis workload."),
                    ("--post-impl", "Correlate one routed workload using the post-implementation timing/parasitic model."),
                    ("--all", "Correlate all matching workloads for the selected stage."),
                ),
            ),
            ("Evidence views", (("--summary", "Status and workload pass/fail counts."), ("--show", "Per-workload fused timing/power results."), ("--debug", "Show plus hotspot paths, reports, and raw artifact paths."))),
        ),
        "gls_all": (
            (
                "Gate-level simulation",
                (
                    ("matrix", "Runs the selected representative tests over the configured timing modes with one GLS backend."),
                    ("min / typ / max", "SDF-backed sampling maps to ff / tt / ss. This is functional GLS sampling, not full STA corner coverage."),
                    ("fx sim --post-syn --all", "Run the post-synthesis GLS matrix."),
                    ("fx sim --post-impl --all", "Run the post-implementation GLS matrix."),
                    ("PASS", "Every selected GLS case executed successfully with the requested timing annotation evidence."),
                ),
            ),
            ("Evidence views", (("--summary", "Status plus total/pass/fail case counts."), ("--show", "Test × timing-scenario matrix from summary.json."), ("--debug", "Show plus failed logs, SDF annotation diagnostics, waveforms, and report paths."))),
        ),
        "physical": (
            (
                "Physical sign-off",
                (
                    ("stage", "Post-implementation only. Physical sign-off is separate evidence from STA and never implies STA PASS."),
                    ("route_drc", "Checks final-route DRC report violations."),
                    ("antenna", "Checks native ORFS antenna evidence or runs the final-ODB antenna check when needed."),
                    ("gds_drc", "Checks final GDS DRC evidence when supported by the platform."),
                    ("lvs", "Checks final layout-vs-schematic database/log evidence."),
                    ("ir_drop", "Collects available supply IR-drop reports; missing/unsupported evidence remains REVIEW, not PASS."),
                ),
            ),
            ("Evidence views", (("--summary", "Overall status and each physical check status."), ("--show", "Canonical physical-check table from summary.json."), ("--debug", "Show plus DRC/LVS/IR/antenna report and log paths; no tool rerun."))),
        ),
        "cdc_rdc": (
            (
                "Lifecycle setup vs analysis setup checks",
                (
                    ("fx cdc_rdc --setup", "Materializes extract.ys only. It prepares the deterministic Yosys/Slang structural extraction and does not run CDC/RDC analysis."),
                    ("setup findings", "A check category executed during fx cdc_rdc. It validates that the structural model and declared intent are coherent; it is unrelated to the lifecycle --setup phase."),
                ),
            ),
            (
                "CDC checks",
                (
                    ("clock_crossings", "Find clock-domain crossings and classify scalar synchronizers, multibit buses, and unsafe/unprotected paths."),
                    ("async_fifo_candidates", "Recognize opposite-direction multibit synchronized buses that look like asynchronous FIFO pointer/data protocols; emit proof obligations rather than assuming safety."),
                    ("closed_loop_handshakes", "Recognize request/acknowledge structures whose synchronized controls are causally connected across both domains."),
                    ("synchronized_reconvergence", "Detect independently synchronized signals that reconverge in one destination domain and may lose coherency."),
                    ("cdc_contracts", "Validate explicit trusted CDC boundaries and their declared source/destination clock/reset intent."),
                ),
            ),
            (
                "RDC checks",
                (
                    ("reset_crossings", "Find data/control paths whose source and destination state belong to different reset domains and classify recognized protection."),
                    ("reset_synchronizers", "Recognize asynchronous-assert / synchronous-release reset synchronizer chains."),
                    ("async_reset_release", "Flag domains that directly use an asynchronous reset without recognized synchronized deassertion; emit a review obligation."),
                    ("reset_sequence", "Require reset sequencing or blocking-control intent when interacting unsafe RDCs span multiple reset families."),
                ),
            ),
            (
                "Setup checks",
                (
                    ("domain_assignment", "Every sequential element must map to a declared clock domain."),
                    ("clock_relationships", "Cross-domain paths should have a declared sync/async/generated relationship; unknown relationships are reported."),
                    ("reset_polarity", "Observed reset polarity on sequential state must agree with the declared clock/reset domain intent."),
                    ("reset_families", "Report multiple or distributed reset families within a clock domain so reset ownership is explicit."),
                    ("cdc_contracts", "Validate contract metadata before trusting a declared CDC boundary."),
                ),
            ),
            (
                "Glitch checks",
                (
                    ("clock path", "Detect combinational logic between a declared clock input and a sequential clock pin. Such logic can create narrow or spurious clock pulses."),
                    ("reset path", "Detect combinational logic between a declared reset input and a sequential reset pin. Such logic can create asynchronous reset glitches."),
                    ("scope", "These are structural hazards on control paths; they are independent evidence and are not CDC/RDC waivers."),
                ),
            ),
            (
                "Summary fields",
                (
                    ("clocks / resets / sequential", "Declared clock domains, reset domains seen on state, and sequential elements analyzed."),
                    ("raw", "Raw structural domain crossings before protocol/synchronizer classification; raw does not mean error."),
                    ("safe", "Findings whose recognized structure is sufficient for the structural checker."),
                    ("review", "Findings that need a verification obligation or design-intent confirmation before closure."),
                    ("warn", "Suspicious or ambiguous structure that deserves review but is not a proven structural violation."),
                    ("error", "Structural violations; these make the overall status FAIL."),
                    ("obligations", "Properties still requiring formal/dynamic evidence, for example stability, Gray coherency, pulse width, or reset sequencing."),
                ),
            ),
            (
                "Finding status",
                (
                    ("SAFE", "Recognized structure is sufficient for this structural check."),
                    ("REVIEW", "The structure is plausible but requires design-intent or formal/dynamic evidence before closure."),
                    ("WARN", "Suspicious or ambiguous structure that deserves inspection but is not a proven violation."),
                    ("ERROR", "Structural violation. With CDC_RDC_STRICT=1, ERROR findings make the command return non-zero."),
                ),
            ),
            (
                "Output and reports",
                (
                    ("--summary", "Compact status, structural counts, CDC/RDC counts, and open obligations from summary.json."),
                    ("--show", "Canonical findings, check groups, classifications, and obligations from summary.json."),
                    ("--debug", "Show plus grouped blockers, contract survival, diagnosis, command/raw artifact paths; never reruns CDC/RDC."),
                    ("summary.json", "Complete machine-readable CDC/RDC analysis: counts, crossings, findings, checks, and verification obligations."),
                    ("cdc_rdc.rpt", "Complete human-readable CDC/RDC finding report."),
                    ("raw evidence", "extract.ys, design.json, and extract.log retain structural/tool evidence for reproduction and diagnosis."),
                ),
            ),
        ),

    }






    # -----------------------------------------------------------------------
    # Persistent project settings and clock/reset intent
    # -----------------------------------------------------------------------


    # -----------------------------------------------------------------------
    # Output helpers
    # -----------------------------------------------------------------------




    # -----------------------------------------------------------------------
    # Command handlers
    # -----------------------------------------------------------------------












    # -----------------------------------------------------------------------
    # Technology and equivalence diagnostics
    # -----------------------------------------------------------------------





    # -----------------------------------------------------------------------
    # Target invocation and one-shot overrides
    # -----------------------------------------------------------------------





    # -----------------------------------------------------------------------
    # Interactive shell
    # -----------------------------------------------------------------------


    # -----------------------------------------------------------------------
    # Typer command and entry point
    # -----------------------------------------------------------------------





    class FlexSoCCli:
        """Thin object-oriented CLI facade: parse, delegate and render."""

        def __call__(self, argv: list[str] | None = None) -> int:
            return self._run_cli(argv)

        @staticmethod
        def _completion_words() -> tuple[str, ...]:
            """Return public words offered by shell and REPL completion."""

            targets = tuple(
                FlexSoCCli._public_name(name)
                for name in TARGETS
                if name not in PRIVATE_CLI_TARGETS
            )
            setup = tuple(FlexSoCCli._public_name(name) for name in PUBLIC_KEYWORDS)
            return tuple(dict.fromkeys((*PSEUDO_COMMANDS, *targets, *CANONICAL_CLI_TARGETS, *setup, *OPTION_WORDS)))

        @staticmethod
        def _complete_items(incomplete: str) -> list[str]:
            """Complete pseudo-commands and backend targets."""

            return [word for word in FlexSoCCli._completion_words() if word.startswith(incomplete)]

        @staticmethod
        def _public_name(target: str) -> str:
            """Return the canonical CLI spelling for one backend target."""

            return {
                "power_estimate": "power-estimate",
                "power_analysis": "power-analysis",
                "fusion_analysis": "fusion",
            }.get(target, target)

        def _guide(self) -> None:
            """Print the canonical IP lifecycle in execution order."""

            console.print()
            console.print(
                Panel(
                    "[white]Production-oriented digital IP flow: scaffold, verify, synthesize, "
                    "sign off, implement, and package.[/white]\n"
                    "[grey70]The same public commands apply to one or many clock domains.[/grey70]",
                    title="[bold orange1]FlexSoC fx[/bold orange1]",
                    subtitle="[bold bright_cyan]IP lifecycle[/bold bright_cyan]",
                    border_style="orange1",
                    padding=(1, 2),
                )
            )
            table = Table(
                title="[bold orange1]Canonical IP lifecycle[/bold orange1]",
                box=box.ROUNDED,
                expand=True,
                header_style="bold white",
                show_lines=True,
            )
            table.add_column("Step", style="orange1", no_wrap=True, width=30)
            table.add_column("Command", style="bright_cyan", ratio=4)
            table.add_column("Purpose", style="white", ratio=3)
            for title, rows in FLOW_GUIDE:
                for index, (command, purpose) in enumerate(rows):
                    table.add_row(title if index == 0 else "", command, purpose)
            console.print(table)
            console.print()
            console.print(
                Panel(
                    "[bold bright_cyan]fx <command> --help[/bold bright_cyan]  "
                    "[white]dedicated command help[/white]\n"
                    "[bold bright_cyan]fx <command> help[/bold bright_cyan] or "
                    "[bold bright_cyan]fx <command> info[/bold bright_cyan]  "
                    "[white]equivalent forms[/white]\n"
                    "[bold bright_cyan]fx commands[/bold bright_cyan]  "
                    "[white]complete target catalogue[/white]\n"
                    "[bold bright_cyan]--set KEY=VALUE[/bold bright_cyan]  "
                    "[white]one-shot selector or backend override[/white]",
                    title="[bold orange1]Help and execution controls[/bold orange1]",
                    border_style="orange1",
                    padding=(1, 2),
                )
            )
            console.print()

        def _target_name(self, value: str) -> str:
            """Resolve dashed or underscored spelling against the target catalogue."""

            for candidate in (value, value.replace("-", "_"), value.replace("_", "-")):
                if candidate in TARGETS:
                    return candidate
            raise ValueError(f"unknown target {value!r}; run `fx commands`")

        def _run_target(self, value: str, *, allow_setup_only: bool = False) -> str:
            """Resolve one public lifecycle keyword to its backend run target."""

            name = value.replace("-", "_")
            target = "fusion_analysis" if name == "fusion" else name
            if target in SETUP_ONLY and not allow_setup_only:
                raise ValueError(f"{name} is setup-only; use `fx {name} --setup`")
            return self._target_name(target)

        def _resolve_domain_command(
            self, values: tuple[str, ...], *, rtl: bool, post_syn: bool, post_impl: bool,
            all_runs: bool, csr: bool, bmc: bool, prove: bool, cover: bool,
        ) -> tuple[str, ...]:
            """Translate one structured public domain command to existing backend target IDs."""

            legacy_root = {"power_estimate": "power-estimate", "power_analysis": "power-analysis"}
            if values and values[0] in legacy_root:
                raise typer.BadParameter(f"use `{legacy_root[values[0]]}` instead of `{values[0]}`")
            normalized = tuple(value.replace("-", "_") for value in values)
            direct_private = next((value for value in normalized if value in PRIVATE_CLI_TARGETS), None)
            if direct_private is not None:
                raise typer.BadParameter(
                    f"{direct_private!r} is internal; use formal/sim/sta/power-estimate/"
                    "power-analysis/fusion options instead"
                )

            selectors = any((rtl, post_syn, post_impl, all_runs, csr, bmc, prove, cover))
            if not selectors and normalized != ("fusion",):
                return normalized if normalized in {("power_estimate",), ("power_analysis",)} else values
            if len(values) != 1:
                raise typer.BadParameter("domain selector options require exactly one command")

            command = normalized[0]
            formal_flags = (csr, bmc, prove, cover)
            stage_flags = (rtl, post_syn, post_impl)

            if command == "formal":
                if any(stage_flags):
                    raise typer.BadParameter("--rtl/--post-syn/--post-impl are not valid with `fx formal`")
                modes = [name for name, enabled in (("bmc", bmc), ("prove", prove), ("cover", cover)) if enabled]
                if len(modes) > 1:
                    raise typer.BadParameter("choose only one of --bmc, --prove, or --cover")
                if all_runs and (csr or modes):
                    raise typer.BadParameter("--all is the default for `fx formal`; do not combine it with --csr/--bmc/--prove/--cover")
                if all_runs or not (csr or modes):
                    return ("formal",)
                mode = modes[0] if modes else ""
                if csr:
                    return (f"formal_csr_{mode}" if mode else "formal_csr",)
                return (f"formal_{mode}",)

            if any(formal_flags):
                raise typer.BadParameter("--csr/--bmc/--prove/--cover are only valid with `fx formal`")

            if command == "sim":
                if sum(stage_flags) > 1:
                    raise typer.BadParameter("choose only one of --rtl, --post-syn, or --post-impl")
                if post_syn:
                    return ("sim_post_syn_all" if all_runs else "sim_post_syn",)
                if post_impl:
                    return ("sim_post_impl_all" if all_runs else "sim_post_impl",)
                return ("sim_tests" if all_runs else "sim",)

            if rtl:
                raise typer.BadParameter("--rtl is only valid with `fx sim`")
            if post_syn and post_impl:
                raise typer.BadParameter("choose only one of --post-syn or --post-impl")

            if command == "sta":
                return ("sta_post_impl" if post_impl else "sta",)
            if command == "power_estimate":
                return ("power_estimate_post_impl" if post_impl else "power_estimate",)
            if command == "power_analysis":
                if post_impl:
                    return ("power_analysis_post_impl_all" if all_runs else "power_analysis_post_impl",)
                return ("power_analysis_all" if all_runs else "power_analysis",)
            if command == "fusion":
                if post_impl:
                    return ("fusion_analysis_post_impl_all" if all_runs else "fusion_analysis_post_impl",)
                return ("fusion_analysis_all" if all_runs else "fusion_analysis",)

            if post_syn or post_impl or all_runs:
                raise typer.BadParameter(
                    "--post-syn/--post-impl/--all are only valid with sim, sta, "
                    "power-estimate, power-analysis, or fusion"
                )
            return values

        @staticmethod
        def _formal_view_selection(target: str) -> tuple[str | None, str | None]:
            """Return formal suite/stage filters for one internal formal target."""

            if target == "formal":
                return None, None
            suite = "csr" if target.startswith("formal_csr") else "properties"
            stage = next((name for name in ("bmc", "prove", "cover") if target.endswith(f"_{name}")), None)
            return suite, stage

        def _mode_targets(self, values: tuple[str, ...], *, setup: bool, debug: bool) -> tuple[str, ...]:
            """Resolve public lifecycle keywords; setup remains an execution mode."""

            if setup and debug:
                raise typer.BadParameter("--setup and --debug are mutually exclusive")
            targets = tuple(self._run_target(value, allow_setup_only=setup or debug) for value in values)
            if setup:
                missing = [target for target in targets if target not in SETUP_TARGETS]
                if missing:
                    raise ValueError(f"{missing[0]} has no setup phase")
            return targets

        def _parameter_description(self, name: str) -> str:
            """Return concise help for one accepted target variable."""

            if name in PARAMETER_HELP:
                return PARAMETER_HELP[name]
            prefixes = {
                "EQY_": "Equivalence-check override",
                "FORMAL_": "Property-formal override",
                "SLANG_": "Slang elaboration override",
                "DEPS_": "Managed dependency override",
                "TUTORIAL_": "Tutorial workspace override",
            }
            for prefix, label in prefixes.items():
                if name.startswith(prefix):
                    suffix = name[len(prefix):].replace("_", " ").lower()
                    return f"{label}: {suffix}."
            return f"Advanced backend override: {name.replace('_', ' ').lower()}."

        def _target_examples(self, name: str, params: tuple[str, ...]) -> tuple[str, ...]:
            """Return practical examples without duplicating the target catalogue."""

            if name in TARGET_EXAMPLES:
                return TARGET_EXAMPLES[name]
            command = f"fx {name}"
            if "FORCE" in params:
                command += " --force"
            return (command,)

        def _target_lifecycle_rows(self, name: str) -> tuple[tuple[str, str], ...]:
            """Describe the public lifecycle supported by one target."""

            internal = name.replace("-", "_")
            public = self._public_name(internal)
            rows: list[tuple[str, str]] = []
            if internal in SETUP_ONLY:
                rows.append(("run", "setup-only target; use --setup"))
            else:
                rows.append(("run", f"fx {public}"))
            rows.append((
                "setup",
                f"fx {public} --setup" if internal in SETUP_TARGETS else "not supported",
            ))
            evidence_view = (
                internal in BACKEND_TARGETS and BACKEND_TARGETS[internal].show is not None
            )
            if evidence_view:
                rows.extend((
                    ("summary", f"fx {public} --summary"),
                    ("show", f"fx {public} --show"),
                ))
            rows.append((
                "debug",
                f"fx {public} --debug" if internal in DEBUG_TARGETS else "not supported",
            ))
            return tuple(rows)

        def _print_target_sections(self, name: str) -> None:
            """Render concise target-specific semantics after the generic options."""

            sections = TARGET_HELP_SECTIONS.get(name)
            if sections is None and name in BACKEND_TARGETS:
                action = BACKEND_TARGETS[name].action
                sections = TARGET_HELP_SECTIONS.get(action or "", ())
            for title, rows in sections or ():
                console.print(f"[bold orange1]{title}[/bold orange1]")
                table = Table(box=box.SIMPLE, expand=True, show_header=False)
                table.add_column("Keyword", style="bright_cyan", no_wrap=True, width=28)
                table.add_column("Meaning", style="white", ratio=4)
                for keyword, meaning in rows:
                    table.add_row(keyword, meaning)
                console.print(table)

        def _print_target_help(self, name: str) -> None:
            """Render dedicated help for one public lifecycle keyword."""

            if name in {"power_estimate", "power_analysis"}:
                raise ValueError(f"use `{name.replace('_', '-')}` as the public command")
            normalized = name.replace("-", "_")
            if normalized in PRIVATE_CLI_TARGETS:
                raise ValueError(f"{name!r} is an internal target; use the canonical domain command")
            target = self._run_target(name, allow_setup_only=True)
            public = self._public_name(target)
            group, description, params = TARGETS[target]
            console.print()
            console.print(
                Panel(
                    f"[white]{description}[/white]",
                    title=f"[bold orange1]fx {public}[/bold orange1]",
                    subtitle=f"[bold bright_cyan]{group}[/bold bright_cyan]",
                    border_style="orange1",
                    padding=(1, 2),
                )
            )
            console.print("[bold orange1]Usage[/bold orange1]")
            examples = (f"fx {public} --setup",) if target in SETUP_ONLY else self._target_examples(target, params)
            for example in examples:
                console.print(f"  [bold bright_cyan]{example}[/bold bright_cyan]")
            if target in SETUP_TARGETS:
                console.print(
                    "[bold orange1]Setup phase[/bold orange1]  "
                    f"[white]fx {public} --setup[/white] "
                    "[grey70](--force regenerates)[/grey70]"
                )
            else:
                console.print("[bold orange1]Setup phase[/bold orange1]  [grey70]none[/grey70]")
            console.print("[bold orange1]Lifecycle[/bold orange1]")
            lifecycle = Table(box=box.SIMPLE, expand=True, show_header=False)
            lifecycle.add_column("Operation", style="bright_cyan", no_wrap=True, width=16)
            lifecycle.add_column("Command", style="white", ratio=4)
            for operation, command in self._target_lifecycle_rows(target):
                lifecycle.add_row(operation, command)
            console.print(lifecycle)
            console.print("[bold orange1]Accepted target variables[/bold orange1]")
            if params:
                table = Table(box=box.SIMPLE_HEAVY, expand=True, header_style="bold white")
                table.add_column("Variable", style="bright_cyan", no_wrap=True, width=30)
                table.add_column("Meaning", style="white", ratio=3)
                table.add_column("Default", style="grey70", no_wrap=True, ratio=1)
                for parameter in params:
                    table.add_row(
                        parameter,
                        self._parameter_description(parameter),
                        str(DEFAULT_SETTINGS.get(parameter, "—")),
                    )
                console.print(table)
                console.print(
                    "[grey70]Pass variables with[/grey70] "
                    "[bold bright_cyan]--set KEY=VALUE[/bold bright_cyan]"
                )
            else:
                console.print("  [grey70]No target-specific variables.[/grey70]")
            console.print(
                "[bold orange1]Common controls[/bold orange1]  "
                "[bright_cyan]--workdir PATH[/bright_cyan], "
                "[bright_cyan]--setup[/bright_cyan] [grey70](when available)[/grey70], "
                "[bright_cyan]--dry-run[/bright_cyan], "
                "[bright_cyan]--live[/bright_cyan], "
                "[bright_cyan]--debug[/bright_cyan], "
                "[bright_cyan]--info[/bright_cyan]"
            )
            self._print_target_sections(target)
            console.print()

        def _print_pseudo_help(self, name: str) -> None:
            """Render dedicated help for one Python-side pseudo-command."""

            description, examples, options = PSEUDO_HELP[name]
            console.print()
            console.print(
                Panel(
                    f"[white]{description}[/white]",
                    title=f"[bold orange1]fx {name}[/bold orange1]",
                    subtitle="[bold bright_cyan]CLI command[/bold bright_cyan]",
                    border_style="orange1",
                    padding=(1, 2),
                )
            )
            console.print("[bold orange1]Usage[/bold orange1]")
            for example in examples:
                console.print(f"  [bold bright_cyan]{example}[/bold bright_cyan]")
            console.print("[bold orange1]Options[/bold orange1]")
            for option in options:
                console.print(f"  [bright_cyan]{option}[/bright_cyan]")
            console.print()

        def _print_command_help(self, name: str) -> None:
            """Render pseudo-command or target help from the installed catalogue."""

            if name in PSEUDO_HELP:
                self._print_pseudo_help(name)
            else:
                self._print_target_help(name)

        def _help_request(self, args: list[str]) -> str | None:
            """Recognize all supported dedicated-help spellings before Typer parsing."""

            if len(args) != 2:
                return None
            if args[0] == "help":
                return args[1]
            if args[1] in HELP_WORDS:
                return args[0]
            return None

        def _assignments(self, items: Iterable[str]) -> dict[str, str]:
            """Parse KEY=VALUE items."""

            values: dict[str, str] = {}
            for item in items:
                if "=" not in item:
                    raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
                key, value = item.split("=", 1)
                values[key.upper()] = value
            return values

        def _print_commands(self, client: FlexSoC, as_json: bool) -> None:
            """Print the canonical public CLI command table."""

            rows: list[dict[str, object]] = []
            for target in client.targets():
                if target.name in PRIVATE_CLI_TARGETS:
                    continue
                data = target.to_dict()
                data["name"] = self._public_name(target.name)
                rows.append(data)
            fusion = client.target_info("fusion_analysis").to_dict()
            fusion["name"] = "fusion"
            insert_at = next(
                (index + 1 for index, item in enumerate(rows) if item["name"] == "power-analysis"),
                len(rows),
            )
            rows.insert(insert_at, fusion)
            if as_json:
                print(json.dumps(rows, indent=2))
                return
            table = Table(title="FlexSoC commands", show_lines=False)
            table.add_column("Command", style="cyan", no_wrap=True)
            table.add_column("Group", style="magenta", no_wrap=True)
            table.add_column("Description")
            table.add_column("Variables")
            for item in rows:
                table.add_row(
                    str(item["name"]), str(item["group"]), str(item["description"]),
                    ", ".join(str(value) for value in item["params"]),
                )
            console.print(table)

        def _print_settings(self, values: Mapping[str, str], as_json: bool) -> None:
            """Print settings grouped by the flow phase they control."""

            if as_json:
                print(json.dumps(dict(values), indent=2))
                return
            groups = (
                ("Run", ("TOP", "RUN_TOP", "RUN_ID", "HOST")),
                ("Clocking", ("N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS")),
                ("Technology", ("PDK", "PDK_ROOT")),
                ("Verification", ("REG_ITF", "COMPILER", "GLS_SIMULATOR", "WAVE_FORMAT", "TIMING_MODE")),
                ("Paths", ("WORKSPACE", "RUN_ROOT", "SYN_DIR", "EQUIV_DIR", "IMPL_DIR")),
            )
            shown: set[str] = set()
            console.print("[bold orange1]FlexSoC settings[/bold orange1]")
            for title, keys in groups:
                rows = [(key, values[key]) for key in keys if key in values]
                if not rows:
                    continue
                console.print(f"[bold bright_cyan]{title}[/bold bright_cyan]")
                table = Table(show_header=False, box=None, pad_edge=False)
                table.add_column("Key", style="grey70", no_wrap=True)
                table.add_column("Value", style="white")
                for key, value in rows:
                    shown.add(key)
                    table.add_row(key, value)
                console.print(table)
            extra = [(key, value) for key, value in sorted(values.items()) if key not in shown]
            if extra:
                console.print("[bold bright_cyan]Advanced[/bold bright_cyan]")
                table = Table(show_header=False, box=None, pad_edge=False)
                table.add_column("Key", style="grey70", no_wrap=True)
                table.add_column("Value", style="white")
                for key, value in extra:
                    table.add_row(key, value)
                console.print(table)

        def _print_info(self, client: FlexSoC, targets: tuple[str, ...], as_json: bool) -> None:
            """Print machine metadata or the full dedicated target help."""

            data = [client.target_info(target).to_dict() for target in targets]
            if as_json:
                print(json.dumps(data[0] if len(data) == 1 else data, indent=2))
                return
            for item in data:
                self._print_target_help(item["name"])

        def _settings(self, root: Path, workdir: Path | None, items: tuple[str, ...], sets: tuple[str, ...], unsets: tuple[str, ...], reset: bool, as_json: bool) -> None:
            """Show or update persistent project settings plus derived run roots."""

            from .backend.core import PDKRunLayout

            values = dict(DEFAULT_SETTINGS if reset else WorkspaceFlow.read_settings(root, workdir, defaults=DEFAULT_SETTINGS))
            for key in unsets:
                values.pop(key.upper(), None)
            updates = self._assignments((*items, *sets))
            if "PDK" in updates and "PDK_ROOT" not in updates:
                values.pop("PDK_ROOT", None)
            clock_updates = {"N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS"} & updates.keys()
            if {"N_CLOCKS", "CLOCK_DOMAINS"} & updates.keys() and "CLOCK_RELATIONSHIPS" not in updates:
                values.pop("CLOCK_RELATIONSHIPS", None)
            values.update(updates)
            if clock_updates:
                from .backend.core import ClockConfig

                values.update(ClockConfig.from_values(values).to_settings())
            if reset or unsets or sets or items:
                WorkspaceFlow.write_settings(root, values, workdir)
            display = dict(values)
            if workdir is not None:
                display["WORKSPACE"] = str(workdir.expanduser().resolve())
            layout = PDKRunLayout.from_values(root, display)
            display["RUN_ROOT"] = str(layout.run_root)
            display["SYN_DIR"] = str(layout.syn_dir)
            display["EQUIV_DIR"] = str(layout.equivalence_dir)
            display["IMPL_DIR"] = str(layout.pnr_dir)
            self._print_settings(display, as_json)

        def _show(self, client: FlexSoC, args: tuple[str, ...], sets: tuple[str, ...], *, as_json: bool) -> int:
            """Render canonical machine-readable reports without rerunning stages."""

            run, values = self._configured_run(client, sets)
            return ShowRenderer(console, error_console).command(
                run,
                top=values.get("TOP", "test"),
                pdk=values.get("PDK", DEFAULT_SETTINGS["PDK"]),
                args=args,
                as_json=as_json,
            )

        def _configured_run(self, client: FlexSoC, sets: tuple[str, ...]) -> tuple[Path, dict[str, str]]:
            """Resolve the configured run path without modifying the workspace."""

            values = {**DEFAULT_SETTINGS, **client.settings, **self._assignments(sets)}
            top = values.get("TOP", "test")
            run_top = values.get("RUN_TOP") or top
            run_id = values.get("RUN_ID", "default")
            return client.workdir / "runs" / run_top / run_id, values

        def _requirements(self, client: FlexSoC, sets: tuple[str, ...], *, less: bool, as_json: bool) -> int:
            """Render the authoritative requirements document for the configured run."""

            run, _ = self._configured_run(client, sets)
            return ShowRenderer(console, error_console).requirements(run, less=less, as_json=as_json)

        def _testplan(self, client: FlexSoC, sets: tuple[str, ...], *, less: bool, as_json: bool) -> int:
            """Render the authoritative test plan for the configured run."""

            run, _ = self._configured_run(client, sets)
            return ShowRenderer(console, error_console).testplan(run, less=less, as_json=as_json)

        def _meta(self, client: FlexSoC, sets: tuple[str, ...], *, less: bool, as_json: bool) -> int:
            """Render release-critical metadata for the configured run."""

            run, _ = self._configured_run(client, sets)
            return ShowRenderer(console, error_console).meta(run, less=less, as_json=as_json)

        def _tests_gen_check(self, client: FlexSoC, sets: tuple[str, ...], *, as_json: bool) -> int:
            """Verify generated vector files against the authoritative Python generators."""

            flow = client.flows(**self._assignments(sets))
            paths = flow.context.paths
            try:
                result = flow.dv.functional.check_tests(paths.tests, paths.top)
            except (FileNotFoundError, RuntimeError, OSError) as exc:
                error_console.print(f"[red]{exc}[/red]")
                return 2
            if as_json:
                print(json.dumps(result, indent=2))
                return 0 if result["ok"] else 1
            if result["ok"]:
                console.print(
                    f"[green]PASS[/green] generated tests match Python source · "
                    f"[white]{result['files']} files[/white]"
                )
                return 0
            table = Table(title="Generated-test drift", header_style="bold white")
            table.add_column("State", no_wrap=True)
            table.add_column("Path", style="white")
            for state in ("missing", "extra", "modified"):
                for path in result[state]:
                    color = "red" if state != "extra" else "orange1"
                    table.add_row(f"[{color}]{state.upper()}[/{color}]", str(path))
            console.print(table)
            error_console.print("[red]generated tests do not match the authoritative Python source; run `fx tests_gen`[/red]")
            return 1

        def _pdk(self,
            root: Path,
            workdir: Path | None,
            args: tuple[str, ...],
            sets: tuple[str, ...],
            *,
            force: bool,
            as_json: bool,
            runner=None,
            on: str = "local",
        ) -> int:
            """List, inspect, fetch, or activate a PDK profile."""

            from .backend.core import PdkManager

            manager = PdkManager(root, runner)
            action = args[0] if args else "list"
            name = args[1] if len(args) > 1 else None
            extra = self._assignments(sets)
            pdk_root = extra.get("PDK_ROOT")

            if action == "list":
                data = PdkManager.catalog(root)
                if as_json:
                    print(PdkManager.json_text(data))
                    return 0
                table = Table(title="FlexSoC PDK catalogue")
                table.add_column("PDK", style="bright_cyan", no_wrap=True)
                table.add_column("Node", no_wrap=True)
                table.add_column("Class")
                table.add_column("ORFS", no_wrap=True)
                table.add_column("Local")
                for item in data:
                    views = item["views"]
                    state = "ready" if views["usable"] else ("fetched" if Path(views["root"]).exists() else "-")
                    table.add_row(str(item["name"]), str(item["node"]), str(item["classification"]), str(item["orfs_platform"]), state)
                console.print(table)
                return 0

            if action not in {"info", "fetch", "use"}:
                raise typer.BadParameter("pdk action must be list, info, fetch, or use")
            if not name:
                raise typer.BadParameter(f"fx pdk {action} requires a PDK name")
            canonical = PdkManager.normalize_name(name)

            if action == "fetch":
                path = manager.fetch(
                    canonical, force=force, version=extra.get("PDK_VERSION"), on=on,
                )
                data = PdkManager.describe(root, canonical, path)
                if as_json:
                    print(PdkManager.json_text(data))
                else:
                    console.print(f"[bold orange1]PDK fetched[/bold orange1]: [bright_cyan]{canonical}[/bright_cyan]")
                    console.print(f"[white]path[/white]: {path}")
                    ready = bool(data["views"]["usable"])
                    state = "ready for digital flow" if ready else "source fetched; digital Liberty/Verilog views still need preparation"
                    console.print(f"[white]status[/white]: {state}")
                return 0

            data = PdkManager.describe(root, canonical, pdk_root)
            if action == "info":
                if as_json:
                    print(PdkManager.json_text(data))
                else:
                    views = data["views"]
                    console.print(f"[bold orange1]PDK profile[/bold orange1] · [bold bright_cyan]{data['title']}[/bold bright_cyan]")
                    for title, rows in (
                        ("Identity", (("Name", canonical), ("Node", data["node"]), ("Class", data["classification"]), ("OpenROAD platform", data["orfs_platform"]))),
                        ("Source / installation", (("Provider", data["fetch_provider"]), ("Source", data["source_url"]), ("Revision", data.get("fetch", {}).get("revision") or "-"), ("Root", views["root"]), ("Status", "ready" if views["usable"] else "not ready"))),
                        ("Digital views", (("Liberty typical", views.get("liberty_typ") or "missing"), ("Liberty slow", views.get("liberty_slow") or "-"), ("Liberty fast", views.get("liberty_fast") or "-"), ("Functional Verilog", f"{len(views['verilog_models'])} model(s)" if views["verilog_models"] else "missing"))),
                    ):
                        console.print(f"[bold bright_cyan]{title}[/bold bright_cyan]")
                        table = Table(show_header=False, box=None, pad_edge=False)
                        table.add_column("Field", style="grey70", no_wrap=True)
                        table.add_column("Value", style="white")
                        for key, value in rows:
                            table.add_row(str(key), str(value))
                        console.print(table)
                    if data.get("formal_adapter_required"):
                        console.print(f"[grey70]Formal adapter:[/grey70] [white]{data.get('formal_adapter') or 'missing'}[/white]")
                    console.print(f"[grey70]{data['note']}[/grey70]")
                return 0

            install = Path(pdk_root).expanduser().resolve() if pdk_root else Path(data["views"]["root"])
            views = PdkManager.discover_views(install, canonical)
            if not views.usable:
                raise typer.BadParameter(
                    f"PDK {canonical} is not ready for digital flow under {install}; "
                    "need at least a typical Liberty and functional gate-level Verilog model"
                )
            current = WorkspaceFlow.read_settings(root, workdir, defaults=DEFAULT_SETTINGS)
            current.update({"PDK": canonical, "PDK_ROOT": str(install)})
            WorkspaceFlow.write_settings(root, current, workdir)
            derived = PdkManager.settings(root, canonical, install)
            if as_json:
                print(PdkManager.json_text({"active": canonical, "settings": current, "derived": derived}))
            else:
                console.print(f"[bold orange1]PDK active[/bold orange1]: [bright_cyan]{canonical}[/bright_cyan]")
                console.print(f"[white]root[/white]: {install}")
                console.print(f"[white]Liberty[/white]: {derived.get('LIB_SYN', '-')}")
                console.print(f"[white]OpenROAD[/white]: {derived.get('ORS_TECH', '-')}")
                console.print(
                    "[grey70]Shared RTL, DV, formal, and SDC artifacts remain valid. "
                    "Rerun syn --setup/syn, regenerate eqy --setup and run eqy when appropriate, signoff --setup, SDF/STA/power, "
                    "GLS activity power, manifest, metrics, and check.[/grey70]"
                )
            return 0

        # -----------------------------------------------------------------------
        # Target invocation and one-shot overrides
        # -----------------------------------------------------------------------
        def _overrides(self, sets: tuple[str, ...], force: bool) -> dict[str, str]:
            """Collect one-shot FlexSoC setting overrides."""

            values = self._assignments(sets)
            if force:
                values["FORCE"] = "1"
            return values

        def _debug_log(self,
            client: FlexSoC, target: str, values: Mapping[str, str], *, as_json: bool
        ) -> int:
            """Show the existing canonical command log for targets without richer diagnostics."""

            path = client.log_path(target, **values)
            if not path.is_file():
                raise FileNotFoundError(f"log not found: {path}; run `fx {target}` first")
            text = path.read_text(encoding="utf-8", errors="replace")
            if as_json:
                print(json.dumps({"target": target, "log": str(path), "text": text}, indent=2))
            else:
                from .backend.core.runtime.execution import Terminal

                Terminal.print_log(path)
                print(text, end="" if text.endswith("\n") else "\n")
            return 0

        def _run(self,
            client: FlexSoC,
            targets: tuple[str, ...],
            *,
            sets: tuple[str, ...],
            force: bool,
            dry_run: bool,
            script: bool,
            capture: bool,
            live: bool,
            debug: bool,
            setup: bool,
            save_output: Path | None,
            as_json: bool,
            info: bool,
            on: str,
        ) -> int:
            """Run, preview, or describe requested targets."""

            if info:
                self._print_info(client, targets, as_json)
                return 0

            try:
                values = self._overrides(sets, force)
                if live:
                    values["LIVE"] = "1"
                if debug:
                    if len(targets) != 1:
                        raise typer.BadParameter("--debug requires exactly one target")
                    if targets[0] not in DEBUG_TARGETS:
                        if save_output is not None:
                            raise typer.BadParameter("--save-output/-o requires a target with structured debug support")
                        return self._debug_log(client, targets[0], values, as_json=as_json)
                    values["DEBUG"] = "1"
                    if save_output is not None:
                        values["DEBUG_OUTPUT"] = str(save_output)
                elif save_output is not None:
                    raise typer.BadParameter("--save-output/-o requires --debug")

                result = client.run(
                    *targets,
                    check=False,
                    dry_run=dry_run,
                    capture=capture,
                    live=live,
                    setup=setup,
                    on=on,
                    **values,
                )
            except (ValueError, RuntimeError, OSError, typer.BadParameter) as exc:
                error_console.print(f"[red]{exc}[/red]")
                return getattr(exc, "returncode", 2) or 2

            items = list(result)

            if dry_run:
                text = "\n".join(item.shell_line() for item in items)
                if script:
                    print("#!/usr/bin/env bash\nset -euo pipefail\n" + text)
                else:
                    print(text)
                return 0

            if as_json:
                data = [item.to_dict() for item in items]
                print(json.dumps(data[0] if len(data) == 1 else data, indent=2))
            elif capture:
                print("".join(item.stdout or "" for item in items), end="")
            failed = [item for item in items if not item.ok]
            return failed[0].returncode if failed else 0

        def _shell(self, root: Path, workdir: Path | None) -> int:
            """Open a Prompt Toolkit shell with command completion."""

            try:
                from prompt_toolkit import PromptSession
                from prompt_toolkit.completion import WordCompleter
                from prompt_toolkit.history import FileHistory
            except ModuleNotFoundError:
                console.print("[red]missing dependency: prompt_toolkit[/red]")
                return 2
            history = WorkspaceFlow.settings_path(root, workdir).with_name("history")
            history.parent.mkdir(parents=True, exist_ok=True)
            session = PromptSession(
                history=FileHistory(str(history)),
                completer=WordCompleter(self._completion_words(), ignore_case=True, sentence=True),
            )
            console.print("[bold cyan]fx shell[/bold cyan]  type 'help', 'commands', 'exit' or backend targets")
            while True:
                try:
                    line = session.prompt("fx> ").strip()
                except (EOFError, KeyboardInterrupt):
                    console.print()
                    return 0
                if not line:
                    continue
                if line in {"exit", "quit", ":q"}:
                    return 0
                if line in {"help", "?"}:
                    self._guide()
                    continue
                self._run_cli([*shlex.split(line), *( ["--workdir", str(workdir)] if workdir else [] )])

        def _entry(self,
            items: Annotated[
                list[str] | None,
                typer.Argument(
                    help="Pseudo-command (`settings`, `commands`, `shell`) or one or more backend targets.",
                    autocompletion=FlexSoCCli._complete_items,
                    show_default=False,
                ),
            ] = None,
            sets: Annotated[
                list[str] | None,
                typer.Option("--set", "-s", help="Add KEY=VALUE override.", rich_help_panel="Settings and overrides"),
            ] = None,
            unsets: Annotated[
                list[str] | None,
                typer.Option("--unset", help="Remove a persistent setting.", rich_help_panel="Settings and overrides"),
            ] = None,
            project_root: Annotated[
                Path | None,
                typer.Option("--project-root", help="Repository root used by backend flows.", rich_help_panel="Paths"),
            ] = None,
            workdir: Annotated[
                Path | None,
                typer.Option("--workdir", help="Workspace used by backend flows.", rich_help_panel="Paths"),
            ] = None,
            deps_user: Annotated[
                bool,
                typer.Option("--user", help="Use rootless user dependency mode.", rich_help_panel="Dependency tooling"),
            ] = False,
            deps_system: Annotated[
                bool,
                typer.Option("--system", help="Use shared/system dependency mode.", rich_help_panel="Dependency tooling"),
            ] = False,
            deps_profile: Annotated[
                str | None,
                typer.Option("--profile", help="Dependency profile: base, impl, or riscv.", rich_help_panel="Dependency tooling"),
            ] = None,
            deps_jobs: Annotated[
                int | None,
                typer.Option("--jobs", help="Parallel dependency build jobs.", rich_help_panel="Dependency tooling"),
            ] = None,
            reset: Annotated[
                bool,
                typer.Option("--reset", help="Reset settings before applying updates.", rich_help_panel="Settings and overrides"),
            ] = False,
            force: Annotated[
                bool,
                typer.Option("--force", "--overwrite", help="Shortcut for FORCE=1.", rich_help_panel="Target options"),
            ] = False,
            setup: Annotated[
                bool,
                typer.Option("--setup", help="Run the setup phase for the selected lifecycle keyword.", rich_help_panel="Target options"),
            ] = False,
            rtl: Annotated[
                bool,
                typer.Option("--rtl", help="Select RTL simulation (the default for fx sim).", rich_help_panel="Domain selection"),
            ] = False,
            post_syn: Annotated[
                bool,
                typer.Option("--post-syn", help="Select the post-synthesis stage.", rich_help_panel="Domain selection"),
            ] = False,
            post_impl: Annotated[
                bool,
                typer.Option("--post-impl", help="Select the post-implementation stage.", rich_help_panel="Domain selection"),
            ] = False,
            all_runs: Annotated[
                bool,
                typer.Option("--all", help="Run all variants/workloads for the selected domain.", rich_help_panel="Domain selection"),
            ] = False,
            csr: Annotated[
                bool,
                typer.Option("--csr", help="Select automatic CSR formal checks.", rich_help_panel="Domain selection"),
            ] = False,
            bmc: Annotated[
                bool,
                typer.Option("--bmc", help="Select bounded model checking.", rich_help_panel="Domain selection"),
            ] = False,
            prove: Annotated[
                bool,
                typer.Option("--prove", help="Select property proof.", rich_help_panel="Domain selection"),
            ] = False,
            cover: Annotated[
                bool,
                typer.Option("--cover", help="Select cover reachability.", rich_help_panel="Domain selection"),
            ] = False,
            on: Annotated[
                str,
                typer.Option("--on", help="Execution target name (local or configured server).", rich_help_panel="Target options"),
            ] = "local",
            dry_run: Annotated[
                bool,
                typer.Option("--dry-run", help="Print backend command previews without running them.", rich_help_panel="Output"),
            ] = False,
            script: Annotated[
                bool,
                typer.Option("--script", help="Render dry-run output as a bash script.", rich_help_panel="Output"),
            ] = False,
            capture: Annotated[
                bool,
                typer.Option("--capture", help="Capture and print target stdout.", rich_help_panel="Output"),
            ] = False,
            live: Annotated[
                bool,
                typer.Option("--live", help="Show generated scripts and the command log while retaining a plain log file.", rich_help_panel="Output"),
            ] = False,
            debug: Annotated[
                bool,
                typer.Option("--debug", help="Show existing target evidence plus debug hints without rerunning the target.", rich_help_panel="Output"),
            ] = False,
            show: Annotated[
                bool,
                typer.Option("--show", help="Show existing target evidence without rerunning the target.", rich_help_panel="Output"),
            ] = False,
            summary: Annotated[
                bool,
                typer.Option("--summary", help="Show only the compact target summary without rerunning the target.", rich_help_panel="Output"),
            ] = False,
            tool: Annotated[
                str | None,
                typer.Option("--tool", help="Filter lint show/debug to slang or verilator.", rich_help_panel="Output"),
            ] = None,
            save_output: Annotated[
                Path | None,
                typer.Option("--save-output", "-o", help="Save filtered --debug output to a file or directory.", rich_help_panel="Output"),
            ] = None,
            as_json: Annotated[
                bool,
                typer.Option("--json", help="Print machine-readable JSON.", rich_help_panel="Output"),
            ] = False,
            less: Annotated[
                bool,
                typer.Option("--less", help="Use the compact human-readable view for requirements, testplan, or meta.", rich_help_panel="Output"),
            ] = False,
            check_generated: Annotated[
                bool,
                typer.Option("--check", help="For tests_gen, verify generated vectors without modifying them.", rich_help_panel="Output"),
            ] = False,
            info: Annotated[
                bool,
                typer.Option("--info", help="Describe targets instead of running them.", rich_help_panel="Output"),
            ] = False,
        ) -> None:
            """Dispatch pseudo-commands or ordered backend targets."""

            root = (project_root or Path.cwd()).resolve()
            args, set_args, unset_args = tuple(items or ()), tuple(sets or ()), tuple(unsets or ())
            args = self._resolve_domain_command(
                args, rtl=rtl, post_syn=post_syn, post_impl=post_impl, all_runs=all_runs,
                csr=csr, bmc=bmc, prove=prove, cover=cover,
            )
            if deps_user and deps_system:
                raise click.BadParameter("choose only one of --user or --system")
            if deps_profile is not None and deps_profile not in {"base", "impl", "riscv"}:
                raise click.BadParameter("--profile must be base, impl, or riscv")
            if deps_jobs is not None and deps_jobs < 1:
                raise click.BadParameter("--jobs must be a positive integer")
            if deps_user or deps_system or deps_profile is not None or deps_jobs is not None:
                dep_targets = {"deps-bootstrap", "deps", "deps-doctor", "deps-versions", "deps-env", "deps-status", "deps-prune"}
                if not args or any(arg not in dep_targets for arg in args):
                    raise click.BadParameter("--user/--system/--profile/--jobs are only valid for dependency targets")
                dep_sets = []
                if deps_user:
                    dep_sets.append("DEPS_MODE=user")
                if deps_system:
                    dep_sets.append("DEPS_MODE=system")
                if deps_profile is not None:
                    dep_sets.append(f"DEPS_PROFILE={deps_profile}")
                if deps_jobs is not None:
                    dep_sets.append(f"DEPS_JOBS={deps_jobs}")
                set_args = (*set_args, *dep_sets)
            client = FlexSoC(FlexSoCConfig(root, workdir), **WorkspaceFlow.read_settings(root, workdir, defaults=DEFAULT_SETTINGS))
            if not args:
                self._guide()
                return
            if args[0] == "commands":
                self._print_commands(client, as_json)
                return
            if args[0] == "settings":
                self._settings(root, workdir, args[1:], set_args, unset_args, reset, as_json)
                return
            if args[0] == "show":
                if args[1:] == ("lint",):
                    raise click.BadParameter("use `fx lint --show` for lint evidence")
                raise typer.Exit(self._show(client, args[1:], set_args, as_json=as_json))
            if args[0] == "requirements":
                if len(args) != 1:
                    raise click.BadParameter("fx requirements accepts no positional arguments")
                raise typer.Exit(self._requirements(client, set_args, less=less, as_json=as_json))
            if args[0] == "testplan":
                if len(args) != 1:
                    raise click.BadParameter("fx testplan accepts no positional arguments")
                raise typer.Exit(self._testplan(client, set_args, less=less, as_json=as_json))
            if args[0] == "meta":
                if len(args) != 1:
                    raise click.BadParameter("fx meta accepts no positional arguments")
                raise typer.Exit(self._meta(client, set_args, less=less, as_json=as_json))
            if less:
                raise click.BadParameter("--less is only valid with requirements, testplan, or meta")
            if check_generated:
                if args != ("tests_gen",):
                    raise click.BadParameter("--check is only valid with `fx tests_gen`")
                raise typer.Exit(self._tests_gen_check(client, set_args, as_json=as_json))
            if args[0] in {"doctor", "pdk"}:
                from .backend.core import ToolRunner

                runner = ToolRunner(client.execution_targets, project_root=root)
                if args[0] == "doctor":
                    from .backend.core.runtime.toolchain import Toolchain

                    raise typer.Exit(Toolchain.run(root, as_json=as_json, runner=runner, on=on))
                raise typer.Exit(
                    self._pdk(
                        root, workdir, args[1:], set_args, force=force, as_json=as_json,
                        runner=runner, on=on,
                    )
                )
            if args[0] == "shell":
                raise typer.Exit(self._shell(root, workdir))
            evidence_target = (
                BACKEND_TARGETS.get(args[0]) if len(args) == 1 else None
            )
            supports_evidence = evidence_target is not None and evidence_target.show is not None
            if (show or summary) and not supports_evidence:
                raise click.BadParameter("--show/--summary are not supported for this target")
            if tool is not None:
                if args != ("lint",):
                    raise click.BadParameter("--tool is only valid with `fx lint`")
                if not (show or summary or debug):
                    raise click.BadParameter("--tool requires `fx lint --show`, `fx lint --summary`, or `fx lint --debug`")
                if tool not in {"slang", "verilator"}:
                    raise click.BadParameter("--tool must be slang or verilator")
            if supports_evidence and (show or summary or debug):
                if sum((show, summary, debug)) > 1:
                    raise click.BadParameter("choose only one of --show, --summary, or --debug")
                target = evidence_target
                flows = client.flows(**self._assignments(set_args))
                try:
                    if target.name == "lint":
                        if debug:
                            code = flows.dv.lint.debug(
                                tool=tool, as_json=as_json,
                                output=str(save_output) if save_output is not None else None,
                            )
                        else:
                            code = flows.dv.lint.show(
                                tool=tool, summary=summary, as_json=as_json,
                                output=str(save_output) if save_output is not None else None,
                            )
                    elif target.show == "slang_hier":
                        if debug:
                            code = flows.dv.hierarchy.debug(
                                output=str(save_output) if save_output is not None else None,
                                as_json=as_json,
                            )
                        else:
                            code = flows.dv.hierarchy.show(
                                summary=summary,
                                output=str(save_output) if save_output is not None else None,
                                as_json=as_json,
                            )
                    elif target.show == "cdc_rdc":
                        if debug:
                            code = flows.dv.cdc.debug(
                                output=str(save_output) if save_output is not None else None,
                                as_json=as_json,
                            )
                        else:
                            code = flows.dv.cdc.show(
                                summary=summary,
                                output=str(save_output) if save_output is not None else None,
                                as_json=as_json,
                            )
                    elif target.show == "regression":
                        code = flows.dv.functional.show_regression(
                            flows.dv.context, summary=summary, debug=debug,
                            output=str(save_output) if save_output is not None else None,
                            as_json=as_json,
                        )
                    elif target.show == "coverage":
                        code = flows.dv.coverage.show(
                            flows.dv.context, summary=summary, debug=debug,
                            output=str(save_output) if save_output is not None else None,
                            as_json=as_json,
                        )
                    elif target.show == "formal":
                        suite, stage = self._formal_view_selection(target.name)
                        code = flows.dv.formal.show(
                            flows.dv.context, summary=summary, debug=debug,
                            output=str(save_output) if save_output is not None else None,
                            as_json=as_json, suite=suite, stage=stage,
                        )
                    elif target.domain == "syn" and target.show == "eqy":
                        code = flows.syn.show_eqy(
                            summary=summary, debug=debug,
                            output=str(save_output) if save_output is not None else None,
                            as_json=as_json,
                        )
                    elif target.domain == "syn":
                        code = flows.syn.show(
                            summary=summary, debug=debug,
                            output=str(save_output) if save_output is not None else None,
                            as_json=as_json,
                        )
                    elif target.domain == "impl":
                        code = flows.impl.show(
                            summary=summary, debug=debug,
                            output=str(save_output) if save_output is not None else None,
                            as_json=as_json,
                        )
                    else:
                        flow = flows.signoff.post_impl if target.stage == "post_impl" else flows.signoff.post_syn
                        code = flow.show(
                            target, summary=summary, debug=debug,
                            output=str(save_output) if save_output is not None else None,
                            as_json=as_json,
                        )
                except (FileNotFoundError, ValueError) as exc:
                    error_console.print(f"[red]{exc}[/red]")
                    raise typer.Exit(2)
                raise typer.Exit(code)
            try:
                targets = self._mode_targets(args, setup=setup, debug=debug)
            except (ValueError, typer.BadParameter) as exc:
                error_console.print(f"[red]{exc}[/red]")
                raise typer.Exit(2)
            raise typer.Exit(
                self._run(
                    client,
                    targets,
                    sets=set_args,
                    force=force,
                    dry_run=dry_run,
                    script=script,
                    capture=capture,
                    live=live,
                    debug=debug,
                    setup=setup,
                    save_output=save_output,
                    as_json=as_json,
                    info=info,
                    on=on,
                )
            )

        def _click_command(self) -> click.Command:
            """Build the Click command generated by Typer."""

            return typer.main.get_command(typer_app)

        def _run_cli(self, argv: list[str] | None = None) -> int:
            """Run the fx command-line interface."""

            args = list(sys.argv[1:] if argv is None else argv)
            if os.environ.get("_FX_COMPLETE") or os.environ.get("_FLEXSOC_COMPLETE"):
                try:
                    return self._click_command().main(
                        args=args, prog_name="fx", standalone_mode=False
                    ) or 0
                except click.exceptions.Exit as exc:
                    return int(exc.exit_code or 0)
            if (
                not args
                or args in (["-h"], ["--help"], ["help"])
                or (len(args) == 2 and args[0] == "help" and args[1] in HELP_WORDS)
            ):
                self._guide()
                return 0
            help_command = self._help_request(args)
            if help_command is not None:
                try:
                    self._print_command_help(help_command)
                except ValueError as exc:
                    error_console.print(f"[red]{exc}[/red]")
                    return 2
                return 0
            try:
                return self._click_command().main(args=args, prog_name="fx", standalone_mode=False) or 0
            except click.exceptions.Exit as exc:
                return int(exc.exit_code or 0)
            except (click.ClickException, typer.BadParameter) as exc:
                exc.show()
                return int(exc.exit_code or 2)
            except KeyboardInterrupt:
                error_console.print("\n[red]interrupted[/red]")
                return 130
    app = FlexSoCCli()
    typer_app.command(name="fx", help=HELP, no_args_is_help=False)(app._entry)
