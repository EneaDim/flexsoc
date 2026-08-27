"""Readable Typer/Prompt Toolkit front-end for FlexSoC."""

from __future__ import annotations

import json
import os
import shlex
import sys
from pathlib import Path
from typing import Annotated, Any, Iterable, Mapping

from .api import AUTO_SETUP_TARGETS, DEFAULT_SETTINGS, TARGETS, FlexSoC, FlexSoCConfig

try:  # Keep the entry point understandable if the new CLI deps are not installed yet.
    import click
    import typer
    from rich import box
    from rich.console import Console
    from rich.panel import Panel
    from rich.table import Table
except ModuleNotFoundError as exc:  # pragma: no cover - exercised only in incomplete envs.
    _MISSING = exc.name
else:
    _MISSING = ""


if _MISSING:  # pragma: no cover - exercised only in incomplete envs.

    def app(argv: list[str] | None = None) -> int:
        """Explain how to install the CLI dependencies."""

        print(
            f"missing CLI dependency: {_MISSING}\n"
            "run: uv sync\n"
            "then: uv run fx --help",
            file=sys.stderr,
        )
        return 2


else:
    console = Console()
    error_console = Console(stderr=True)
    PSEUDO_COMMANDS = ("help", "settings", "commands", "doctor", "pdk", "eqy_debug", "shell")
    OPTION_WORDS = (
        "--set",
        "--unset",
        "--project-root",
        "--workdir",
        "--tool",
        "--user",
        "--system",
        "--profile",
        "--jobs",
        "--reset",
        "--force",
        "--overwrite",
        "--no-setup",
        "--dry-run",
        "--script",
        "--capture",
        "--live",
        "--json",
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

    def _completion_words() -> tuple[str, ...]:
        """Return words offered by shell and REPL completion."""

        return tuple(dict.fromkeys((*PSEUDO_COMMANDS, *TARGETS, *OPTION_WORDS)))

    def _complete_items(incomplete: str) -> list[str]:
        """Complete pseudo-commands and backend targets."""

        return [word for word in _completion_words() if word.startswith(incomplete)]

    HELP_WORDS = {"help", "info", "-h", "--help"}

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
                ("fx setup_model --force", "Create the model, RegMap API, and scenario source."),
                ("fx tests_gen | fx test_gen --set TEST_NAME=smoke", "Generate all tests or one named test."),
                ("fx tests", "List the generated test catalogue."),
                ("fx setup_tb setup_cocotb", "Generate SV and cocotb drivers from the current interfaces."),
                ("fx sim --set TEST_NAME=smoke", "Run one SystemVerilog vector test."),
                ("fx cocotb --set TEST_NAME=smoke", "Run the same vectors through cocotb."),
                ("fx regression | fx coverage | fx coverage_detail", "Run the catalogue and inspect coverage."),
            ),
        ),
        (
            "4. Close RTL and properties",
            (
                ("fx lint_suite", "Run the complete Slang and Verilator lint suites."),
                ("fx slang_hier | fx slang_ast", "Inspect elaborated hierarchy and AST."),
                ("fx setup_formal | fx formal", "Generate and run BMC, prove, and cover stages."),
            ),
        ),
        (
            "5. Synthesize and prove equivalence",
            (
                ("fx syn", "Prepare Yosys/ABC scripts and produce the mapped netlist."),
                ("fx eqy", "Prepare and prove RTL versus mapped-netlist equivalence."),
                ("fx eqy_debug [partition]", "Diagnose unresolved equivalence partitions."),
            ),
        ),
        (
            "6. Run post-synthesis sign-off",
            (
                ("fx setup_signoff", "Generate the PDK-scoped SDC and OpenSTA Tcl families."),
                ("fx sdf | fx sta | fx power_estimate", "Produce corner SDF, timing, and vectorless power."),
                ("fx compile_post_syn --set TEST_NAME=smoke --set TIMING_MODE=typ", "Compile one named GLS workload."),
                ("fx sim_post_syn --set TEST_NAME=smoke --set TIMING_MODE=typ", "Run one post-synthesis GLS workload."),
                ("fx sim_post_syn_all", "Run all generated tests/timing modes with the selected GLS backend."),
                ("fx power_analysis --set POWER_TEST_NAME=smoke --set POWER_TIMING_MODE=typ", "Analyze power for one GLS workload."),
                ("fx fusion_analysis --set POWER_TEST_NAME=smoke --set POWER_TIMING_MODE=typ", "Correlate worst timing paths and gate power for one workload."),
                ("fx fusion_analysis_all --set POWER_TEST_NAMES=all", "Run fusion for every matching GLS workload."),
            ),
        ),
        (
            "7. Implement and close routed timing",
            (
                ("fx pnr", "Run OpenROAD and produce the final netlist, SDC, SPEF, ODB, and GDS."),
                ("fx physical_signoff", "Run ORFS physical closure first: route DRC, antenna evidence, GDS DRC, LVS, and IR/PDN evidence."),
                ("fx setup_signoff_post_pnr | fx sdf_post_pnr | fx sta_post_pnr", "Write routed SDF, then consume routed SDC/SPEF for propagated-clock/interconnect timing."),
                ("fx sim_post_pnr_all", "Run timing-aware post-PnR GLS across selected tests and scenarios."),
                ("fx power_estimate_post_pnr", "Run vectorless routed power estimation."),
                ("fx power_analysis_post_pnr_all | fx fusion_analysis_post_pnr_all", "Use routed GLS activity for activity power and timing/power correlation."),
                ("fx manifest | fx metrics | fx check", "Collect release identity, metrics, and closure status."),
                ("fx ip_save", "Save a reusable IP package after closure."),
            ),
        ),
        (
            "8. Reuse an existing IP",
            (
                ("fx ip_load --set TOP=cordic --set RUN_TOP=cordic", "Load authored and generated IP collateral."),
                ("fx regmap_py tests_gen setup_tb setup_cocotb", "Refresh generator-owned DV collateral."),
                ("fx lint_suite regression formal syn eqy", "Run the same qualification gates as a scaffolded IP."),
                ("fx soc_start | fx soc_flow", "Use loaded IPs as building blocks for a later SoC flow."),
            ),
        ),
    )

    PARAMETER_HELP = {
        "TOP": "Logical IP top module.",
        "RUN_TOP": "Run-directory owner; normally the same as TOP.",
        "RUN_ID": "Named run instance below runs/<RUN_TOP>/.",
        "WORKSPACE": "External workspace root; prefer the --workdir option.",
        "FORCE": "Allow regeneration of generator-owned outputs; prefer --force.",
        "N_CLOCKS": "Number of declared clock domains.",
        "CLOCK_DOMAINS": "Comma-separated name:clock:reset:period:polarity domain declarations.",
        "CLOCK_RELATIONSHIPS": "Explicit async/sync/generated relationships between domains.",
        "PDK": "Active technology profile name.",
        "PDK_ROOT": "Root of an already installed PDK.",
        "CLK_PERIOD": "Primary clock period override in nanoseconds.",
        "REG_ITF": "Generated register bus/interface type.",
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
        "WAVE_FORMAT": "Waveform format: fst or vcd.",
        "WAVE_FILE": "Explicit waveform output path.",
        "WAVE_VIEWER": "Waveform viewer executable, normally surfer or gtkwave.",
        "SURFER_BACKEND": "Surfer GUI backend policy: auto, x11, or wayland; auto avoids Wayland under WSL.",
        "COCOTB_WAVES": "Enable cocotb waveform generation.",
        "COVERAGE": "Enable or select coverage collection.",
        "COVERAGE_DETAIL_LIMIT": "Maximum uncovered points printed by coverage_detail.",
        "LINT_TOOL": "Selected lint implementation.",
        "LINT_PART": "Selected lint diagnostic subset.",
        "VSV": "SystemVerilog/Verilog language selection used by backend scripts.",
        "GLS_SIMULATOR": "Gate-level simulator executable/family.",
        "GLS_BACKEND": "Gate-level driver backend, normally sv or cocotb.",
        "TIMING_MODE": "Technical GLS timing selection: zero, unit, min, typ, or max; SDF-backed artifacts use ff/tt/ss scenario names.",
        "TIMING_MODES": "Technical selections for sim_post_syn_all; all means zero/unit/min/typ/max, named zero/unit/ff/tt/ss in artifacts.",
        "GLS_UNIT_DELAY": "Delay assigned in unit-delay GLS mode.",
        "SDF_STRICT": "Fail when SDF annotation is missing or incomplete.",
        "SDF_FILE": "Explicit SDF file used for GLS.",
        "SDF_CORNER": "Corner selected for SDF generation or annotation.",
        "NETLIST": "Explicit synthesized or post-route netlist.",
        "SIGNOFF_STAGE": "Sign-off source stage: post_syn or post_route; view also accepts post_pnr.",
        "SDC_CLOCK_PERIOD_NS": (
            "Optional single-clock sign-off period override; "
            "multi-clock periods come from CLOCK_DOMAINS."
        ),
        "SPEF_FILE": "Extracted parasitics for post-route timing/power.",
        "PNR_SDC_FILE": "Post-route SDC override.",
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
        "IP_LIBRARY_ROOT": "IP package library root.",
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
        "setup_model": ("fx setup_model --force",),
        "test_gen": ("fx test_gen --set TEST_NAME=smoke",),
        "tests": ("fx tests",),
        "sim": ("fx sim --set TEST_NAME=smoke --set COMPILER=verilator",),
        "cocotb": ("fx cocotb --set TEST_NAME=smoke --set COCOTB_WAVES=1",),
        "regression": ("fx regression --no-setup",),
        "view": (
            "fx view --set PDK=ihp-sg13g2 --set SIGNOFF_STAGE=post_syn "
            "--set SIM_NAME=smoke_sv_tt --set WAVE_VIEWER=surfer",
            "fx view --set PDK=ihp-sg13g2 --set SIGNOFF_STAGE=post_pnr "
            "--set SIM_NAME=smoke_sv_tt --set WAVE_VIEWER=surfer",
        ),
        "setup_syn": (
            "fx setup_syn",
            "fx setup_syn --set TARGET_OPT=delay1",
        ),
        "syn": (
            "fx syn",
            "fx syn --set TARGET_OPT=delay1",
            "fx settings TARGET_OPT=delay1 && fx setup_syn && fx syn --no-setup",
        ),
        "eqy": ("fx eqy", "fx setup_eqy && fx eqy --no-setup"),
        "cdc_rdc": ("fx cdc_rdc", "fx cdc_rdc --live", "fx cdc_rdc --set CDC_RDC_STRICT=1"),
        "compile_post_syn": (
            "fx compile_post_syn --no-setup --set TEST_NAME=smoke "
            "--set GLS_BACKEND=sv --set TIMING_MODE=typ",
        ),
        "sim_post_syn": (
            "fx sim_post_syn --no-setup --set TEST_NAME=smoke "
            "--set GLS_BACKEND=sv --set TIMING_MODE=typ --set SDF_STRICT=1",
        ),
        "sim_post_syn_all": (
            "fx sim_post_syn_all",
            "fx sim_post_syn_all --no-setup --set TEST_NAMES=all "
            "--set GLS_BACKEND=sv --set TIMING_MODES=all",
            "fx sim_post_syn_all --no-setup --set TEST_NAMES=all "
            "--set GLS_BACKEND=cocotb --set TIMING_MODES=all",
        ),
        "power_analysis": (
            "fx power_analysis --no-setup --set POWER_TEST_NAME=smoke "
            "--set POWER_GLS_BACKEND=sv --set POWER_TIMING_MODE=typ",
        ),
        "power_analysis_all": (
            "fx power_analysis_all --no-setup --set POWER_TEST_NAMES=all "
            "--set POWER_GLS_BACKENDS=all --set POWER_TIMING_MODES=all",
        ),
        "fusion_analysis": (
            "fx fusion_analysis --no-setup --set POWER_TEST_NAME=smoke "
            "--set POWER_GLS_BACKEND=sv --set POWER_TIMING_MODE=typ",
        ),
        "fusion_analysis_all": (
            "fx fusion_analysis_all --no-setup --set POWER_TEST_NAMES=all "
            "--set POWER_GLS_BACKENDS=all --set POWER_TIMING_MODES=all",
        ),
        "validate_override": (
            "fx validate_override --set STAGE=setup_syn",
            "fx check",
        ),
        "ip_load": ("fx ip_load --set TOP=cordic --set RUN_TOP=cordic",),
        "ip_save": ("fx ip_save --set IP_NAME=cordic_release", "fx ip_save --force --set IP_NAME=cordic_release"),
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
        "eqy_debug": (
            "Summarize EQY closure or inspect one unresolved partition.",
            ("fx eqy_debug", "fx eqy_debug partition_name", "fx eqy_debug --wave partition_name"),
            ("--wave", "--files", "--set KEY=VALUE", "--json"),
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

    def _guide() -> None:
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
                "[white]one-shot selector or backend override[/white]\n"
                "[bold bright_cyan]--no-setup[/bold bright_cyan]  "
                "[white]run only explicitly named targets[/white]",
                title="[bold orange1]Help and execution controls[/bold orange1]",
                border_style="orange1",
                padding=(1, 2),
            )
        )
        console.print()

    def _target_name(value: str) -> str:
        """Resolve dashed or underscored spelling against the target catalogue."""

        for candidate in (value, value.replace("-", "_"), value.replace("_", "-")):
            if candidate in TARGETS:
                return candidate
        raise ValueError(f"unknown command {value!r}; run `fx commands`")

    def _parameter_description(name: str) -> str:
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

    def _target_examples(name: str, params: tuple[str, ...]) -> tuple[str, ...]:
        """Return practical examples without duplicating the target catalogue."""

        if name in TARGET_EXAMPLES:
            return TARGET_EXAMPLES[name]
        command = f"fx {name}"
        if "FORCE" in params:
            command += " --force"
        return (command,)

    TARGET_HELP_SECTIONS = {
        "setup_syn": (
            (
                "TARGET_OPT and provenance",
                (
                    ("one command", "Prefer `fx syn --set TARGET_OPT=delay1`; automatic setup uses the same one-shot override."),
                    ("explicit pipeline", "Repeat the same --set on setup and consumer, or persist it first with `fx settings TARGET_OPT=delay1`."),
                    ("STALE", "The effective configuration/source/parent lineage differs from the recorded setup; regenerate setup, do not validate it."),
                    ("MODIFIED", "A generated setup file was edited manually; only this state is eligible for validate_override."),
                ),
            ),
        ),
        "syn": (
            (
                "Synthesis profile workflow",
                (
                    ("one-shot", "`fx syn --set TARGET_OPT=delay1` runs setup_syn and syn with one coherent effective configuration."),
                    ("persistent", "For several commands, use `fx settings TARGET_OPT=delay1` once, then run setup/synthesis/sign-off normally."),
                    ("--no-setup", "The existing setup must match the exact effective settings of this invocation; STALE collateral is rejected."),
                ),
            ),
        ),
        "validate_override": (
            (
                "When to use it",
                (
                    ("MODIFIED", "Use validate_override only after intentionally editing a generated setup artifact by hand."),
                    ("STALE", "Configuration, source, or parent lineage changed. Rerun the setup target with the intended settings; do not validate."),
                    ("INVALID", "Required files/provenance are missing or inconsistent. Repair inputs and rerun setup."),
                    ("CLEAN", "Nothing to validate; the generated collateral already matches its canonical setup."),
                    ("VALIDATED_OVERRIDE", "The exact manual edit is already accepted for the current lineage."),
                ),
            ),
            (
                "Typical flows",
                (
                    ("change TARGET_OPT", "`fx settings TARGET_OPT=delay1` → `fx setup_syn` → `fx syn --no-setup`."),
                    ("manual .abc edit", "Run setup_syn, edit the generated .abc, then validate_override STAGE=setup_syn before --no-setup execution."),
                ),
            ),
        ),
        "cdc_rdc": (
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
                    ("PASS", "No WARN, REVIEW, or ERROR findings remain."),
                    ("REVIEW", "At least one WARN/REVIEW exists and no ERROR exists; the run completed but closure is not complete."),
                    ("SAFE", "A specific recognized crossing/check is structurally safe."),
                    ("WARN", "A specific finding needs inspection; it does not make the run fail by itself."),
                    ("ERROR", "A structural violation. With CDC_RDC_STRICT=1, ERROR findings make the command return non-zero."),
                ),
            ),
            (
                "Output and reports",
                (
                    ("default", "Print only the colored final summary plus the detailed cdc_rdc.log path."),
                    ("--live", "Show extraction progress, domains, checker counts, every finding and obligation, and report paths."),
                    ("JSON", "Machine-readable inventory, CDC, RDC, setup, glitch, obligations, and summary reports are written under analysis/cdc_rdc/."),
                    ("log", "The complete human-readable analysis is written under logs/analysis/cdc_rdc/cdc_rdc.log."),
                ),
            ),
        ),
    }

    def _print_target_sections(name: str) -> None:
        """Render concise target-specific semantics after the generic options."""

        for title, rows in TARGET_HELP_SECTIONS.get(name, ()):
            console.print(f"[bold orange1]{title}[/bold orange1]")
            table = Table(box=box.SIMPLE, expand=True, show_header=False)
            table.add_column("Keyword", style="bright_cyan", no_wrap=True, width=28)
            table.add_column("Meaning", style="white", ratio=4)
            for keyword, meaning in rows:
                table.add_row(keyword, meaning)
            console.print(table)

    def _print_target_help(name: str) -> None:
        """Render dedicated help for one backend target."""

        target = _target_name(name)
        group, description, params = TARGETS[target]
        console.print()
        console.print(
            Panel(
                f"[white]{description}[/white]",
                title=f"[bold orange1]fx {target}[/bold orange1]",
                subtitle=f"[bold bright_cyan]{group}[/bold bright_cyan]",
                border_style="orange1",
                padding=(1, 2),
            )
        )
        console.print("[bold orange1]Usage[/bold orange1]")
        for example in _target_examples(target, params):
            console.print(f"  [bold bright_cyan]{example}[/bold bright_cyan]")
        setup = AUTO_SETUP_TARGETS.get(target)
        if setup:
            console.print(
                "[bold orange1]Automatic setup[/bold orange1]  "
                f"[white]{', '.join(setup)}[/white] "
                "[grey70](disable with --no-setup)[/grey70]"
            )
        else:
            console.print(
                "[bold orange1]Automatic setup[/bold orange1]  "
                "[grey70]none; prerequisites remain explicit[/grey70]"
            )
        console.print("[bold orange1]Accepted target variables[/bold orange1]")
        if params:
            table = Table(box=box.SIMPLE_HEAVY, expand=True, header_style="bold white")
            table.add_column("Variable", style="bright_cyan", no_wrap=True, width=30)
            table.add_column("Meaning", style="white", ratio=3)
            table.add_column("Default", style="grey70", no_wrap=True, ratio=1)
            for parameter in params:
                table.add_row(
                    parameter,
                    _parameter_description(parameter),
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
            "[bright_cyan]--dry-run[/bright_cyan], "
            "[bright_cyan]--live[/bright_cyan], "
            "[bright_cyan]--info[/bright_cyan]"
        )
        _print_target_sections(target)
        console.print()

    def _print_pseudo_help(name: str) -> None:
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

    def _print_command_help(name: str) -> None:
        """Render pseudo-command or target help from the installed catalogue."""

        if name in PSEUDO_HELP:
            _print_pseudo_help(name)
        else:
            _print_target_help(name)

    def _help_request(args: list[str]) -> str | None:
        """Recognize all supported dedicated-help spellings before Typer parsing."""

        if len(args) != 2:
            return None
        if args[0] == "help":
            return args[1]
        if args[1] in HELP_WORDS:
            return args[0]
        return None

    # -----------------------------------------------------------------------
    # Persistent project settings and clock/reset intent
    # -----------------------------------------------------------------------

    def _upper(values: Mapping[str, Any]) -> dict[str, str]:
        """Convert settings to normalized uppercase strings."""

        return {str(key).upper(): str(value) for key, value in values.items() if value is not None}

    def _settings_path(root: Path) -> Path:
        """Return the project-local settings file."""

        return root / ".flexsoc" / "settings.json"

    def _read_settings(root: Path) -> dict[str, str]:
        """Read persisted settings merged over defaults."""

        path = _settings_path(root)
        values = json.loads(path.read_text(encoding="utf-8")) if path.exists() else {}
        return {**DEFAULT_SETTINGS, **_upper(values)}

    def _write_settings(root: Path, values: Mapping[str, Any]) -> None:
        """Write project-local settings."""

        path = _settings_path(root)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(_upper(values), indent=2, sort_keys=True) + "\n", encoding="utf-8")

    def _assignments(items: Iterable[str]) -> dict[str, str]:
        """Parse KEY=VALUE items."""

        values: dict[str, str] = {}
        for item in items:
            if "=" not in item:
                raise typer.BadParameter(f"expected KEY=VALUE, got {item!r}")
            key, value = item.split("=", 1)
            values[key.upper()] = value
        return values

    # -----------------------------------------------------------------------
    # Output helpers
    # -----------------------------------------------------------------------

    def _print_commands(client: FlexSoC, as_json: bool) -> None:
        """Print the unified target table."""

        targets = client.targets()
        if as_json:
            print(json.dumps([target.to_dict() for target in targets], indent=2))
            return
        table = Table(title="FlexSoC backend targets", show_lines=False)
        table.add_column("Target", style="cyan", no_wrap=True)
        table.add_column("Group", style="magenta", no_wrap=True)
        table.add_column("Description")
        table.add_column("Variables")
        for target in targets:
            table.add_row(target.name, target.group, target.description, ", ".join(target.params))
        console.print(table)

    def _print_settings(values: Mapping[str, str], as_json: bool) -> None:
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

    def _print_info(client: FlexSoC, targets: tuple[str, ...], as_json: bool) -> None:
        """Print machine metadata or the full dedicated target help."""

        data = [client.target_info(target).to_dict() for target in targets]
        if as_json:
            print(json.dumps(data[0] if len(data) == 1 else data, indent=2))
            return
        for item in data:
            _print_target_help(item["name"])

    # -----------------------------------------------------------------------
    # Command handlers
    # -----------------------------------------------------------------------

    def _settings(root: Path, workdir: Path | None, items: tuple[str, ...], sets: tuple[str, ...], unsets: tuple[str, ...], reset: bool, as_json: bool) -> None:
        """Show or update persistent project settings plus derived run roots."""

        from .backend.core import layout_from_values

        values = dict(DEFAULT_SETTINGS if reset else _read_settings(root))
        for key in unsets:
            values.pop(key.upper(), None)
        updates = _assignments((*items, *sets))
        if "PDK" in updates and "PDK_ROOT" not in updates:
            values.pop("PDK_ROOT", None)
        clock_updates = {"N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS"} & updates.keys()
        if {"N_CLOCKS", "CLOCK_DOMAINS"} & updates.keys() and "CLOCK_RELATIONSHIPS" not in updates:
            values.pop("CLOCK_RELATIONSHIPS", None)
        values.update(updates)
        if clock_updates:
            from .backend.core import clock_config

            values.update(clock_config(values).to_settings())
        if reset or unsets or sets or items:
            _write_settings(root, values)
        display = dict(values)
        if workdir is not None:
            display["WORKSPACE"] = str(workdir.expanduser().resolve())
        layout = layout_from_values(root, display)
        display["RUN_ROOT"] = str(layout.run_root)
        display["SYN_DIR"] = str(layout.syn_dir)
        display["EQUIV_DIR"] = str(layout.equivalence_dir)
        display["IMPL_DIR"] = str(layout.pnr_dir)
        _print_settings(display, as_json)

    # -----------------------------------------------------------------------
    # Technology and equivalence diagnostics
    # -----------------------------------------------------------------------

    def _pdk(
        root: Path,
        args: tuple[str, ...],
        sets: tuple[str, ...],
        *,
        force: bool,
        as_json: bool,
    ) -> int:
        """List, inspect, fetch, or activate a PDK profile."""

        from .backend.core import (
            describe, discover_views, fetch, json_text, list_data, normalize_name, pdk_settings,
        )

        action = args[0] if args else "list"
        name = args[1] if len(args) > 1 else None
        extra = _assignments(sets)
        pdk_root = extra.get("PDK_ROOT")

        if action == "list":
            data = list_data(root)
            if as_json:
                print(json_text(data))
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
        canonical = normalize_name(name)

        if action == "fetch":
            path = fetch(root, canonical, force=force, version=extra.get("PDK_VERSION"))
            data = describe(root, canonical, path)
            if as_json:
                print(json_text(data))
            else:
                console.print(f"[bold orange1]PDK fetched[/bold orange1]: [bright_cyan]{canonical}[/bright_cyan]")
                console.print(f"[white]path[/white]: {path}")
                ready = bool(data["views"]["usable"])
                state = "ready for digital flow" if ready else "source fetched; digital Liberty/Verilog views still need preparation"
                console.print(f"[white]status[/white]: {state}")
            return 0

        data = describe(root, canonical, pdk_root)
        if action == "info":
            if as_json:
                print(json_text(data))
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
        views = discover_views(install, canonical)
        if not views.usable:
            raise typer.BadParameter(
                f"PDK {canonical} is not ready for digital flow under {install}; "
                "need at least a typical Liberty and functional gate-level Verilog model"
            )
        current = _read_settings(root)
        current.update({"PDK": canonical, "PDK_ROOT": str(install)})
        _write_settings(root, current)
        derived = pdk_settings(root, canonical, install)
        if as_json:
            print(json_text({"active": canonical, "settings": current, "derived": derived}))
        else:
            console.print(f"[bold orange1]PDK active[/bold orange1]: [bright_cyan]{canonical}[/bright_cyan]")
            console.print(f"[white]root[/white]: {install}")
            console.print(f"[white]Liberty[/white]: {derived.get('LIB_SYN', '-')}")
            console.print(f"[white]OpenROAD[/white]: {derived.get('ORS_TECH', '-')}")
            console.print(
                "[grey70]Shared RTL, DV, formal, and SDC artifacts remain valid. "
                "Rerun setup_syn/syn, setup_eqy/eqy, setup_signoff, SDF/STA/power, "
                "GLS activity power, manifest, metrics, and check.[/grey70]"
            )
        return 0



    def _eqy_debug(
        root: Path,
        workdir: Path | None,
        args: tuple[str, ...],
        sets: tuple[str, ...],
        *,
        as_json: bool,
    ) -> int:
        """Explain one EQY failure; expensive probes target only the selected partition."""

        from .backend.syn.eqy import (
            choose_trace, describe_partition, discover_result_dir, explain_counterexample, open_wave,
            run_reset_normalized_diagnostic, run_synthesis_boundary_diagnostics,
            scan, select, synthesis_boundary_diagnosis,
        )

        settings = _read_settings(root)
        settings.update(_assignments(sets))
        top = settings.get("TOP", "test")
        run_top = settings.get("RUN_TOP") or top
        run_id = settings.get("RUN_ID", "default")
        pdk = settings.get("PDK", DEFAULT_SETTINGS["PDK"])
        workspace = (workdir or Path(settings.get("WORKSPACE", root / "workspace"))).expanduser().resolve()

        values = list(args)
        action = "show"
        if values and values[0] in {"--wave", "wave", "open"}:
            action = "wave"
            values.pop(0)
        elif values and values[0] in {"--files", "files"}:
            action = "files"
            values.pop(0)
        partition = values.pop(0) if values else None
        trace_kind = values.pop(0) if values else "auto"
        if values:
            error_console.print("[red]eqy_debug accepts at most one partition and one trace kind[/red]")
            return 2

        try:
            result_dir = discover_result_dir(root, workspace, top=top, run_top=run_top, run_id=run_id, pdk=pdk)
            rows = scan(result_dir)
        except (FileNotFoundError, ValueError) as exc:
            error_console.print(f"[red]{exc}[/red]")
            return 2

        total = len(rows)
        passed = sum(row.status == "PASS" for row in rows)
        closure = 100.0 * passed / total if total else 0.0
        non_pass = tuple(row for row in rows if row.status != "PASS")
        if not non_pass:
            payload = {"pdk": pdk, "result_dir": str(result_dir), "passed": passed, "total": total, "closure_pct": closure}
            if as_json:
                print(json.dumps(payload, indent=2))
            else:
                console.print(Panel.fit(
                    f"PDK: [white]{pdk}[/white]\n[green]{passed}/{total} partitions proven · {closure:.2f}%[/green]\n[green]EQY PASS[/green]",
                    title="EQY debug", border_style="green",
                ))
            return 0

        try:
            item = select(rows, partition)
        except ValueError as exc:
            if partition is not None:
                error_console.print(f"[red]{exc}[/red]")
                return 2
            if as_json:
                print(json.dumps({"pdk": pdk, "passed": passed, "total": total, "closure_pct": closure,
                                  "counterexamples": [entry.to_dict() for entry in non_pass]}, indent=2))
            else:
                table = Table(title=f"EQY debug · {passed}/{total} PASS · {closure:.2f}%",
                              header_style="bold grey70", border_style="grey50")
                table.add_column("Partition", style="white")
                table.add_column("Status")
                table.add_column("Strategy", style="grey70")
                max_rows = 24
                for entry in non_pass[:max_rows]:
                    strategy = entry.failing_strategy
                    color = "red" if entry.status == "FAIL" else "orange1"
                    table.add_row(entry.partition, f"[{color}]{entry.status}[/{color}]", strategy.name if strategy else "-")
                console.print(table)
                hidden = len(non_pass) - max_rows
                if hidden > 0:
                    console.print(
                        f"[grey70]Showing {max_rows}/{len(non_pass)} non-PASS partitions; "
                        f"{hidden} omitted. Use[/grey70] [white]fx eqy_debug --json[/white] [grey70]for the complete list.[/grey70]"
                    )
                console.print("[grey70]Select one:[/grey70] [white]fx eqy_debug <partition>[/white]")
            return 0

        strategy = item.failing_strategy
        if strategy is None:
            error_console.print(
                f"[red]partition {item.partition} has no failing strategy[/red]"
            )
            return 2
        if action == "files":
            files = (*strategy.traces, *strategy.logs)
            if as_json:
                print(json.dumps({"partition": item.partition, "strategy": strategy.name,
                                  "directory": str(strategy.directory), "files": [str(path) for path in files]}, indent=2))
            else:
                console.print(f"[orange1]{item.partition}[/orange1] · [white]{strategy.name}[/white]")
                console.print(f"[grey70]directory:[/grey70] [white]{strategy.directory}[/white]")
                for path in files:
                    console.print(f"  [white]{path}[/white]")
            return 0
        if action == "wave":
            try:
                trace = choose_trace(strategy, trace_kind)
                viewer = settings.get("WAVE_VIEWER", "gtkwave")
                session, _ = open_wave(trace, item.partition, viewer=viewer)
            except (FileNotFoundError, ValueError, OSError) as exc:
                error_console.print(f"[red]{exc}[/red]")
                return 2
            if as_json:
                print(json.dumps({"partition": item.partition, "trace": str(trace), "viewer": viewer,
                                  "session": str(session) if session else None}, indent=2))
            else:
                console.print(f"[orange1][eqy_debug][/orange1] waveform · [white]{item.partition}[/white]")
                console.print(f"[grey70]trace:[/grey70] [white]{trace}[/white]")
                console.print(f"[grey70]viewer:[/grey70] [white]{viewer}[/white]")
            return 0

        try:
            explanation = explain_counterexample(item)
        except (FileNotFoundError, ValueError, OSError) as exc:
            error_console.print(f"[red]{exc}[/red]")
            return 2

        if not as_json:
            console.print(Panel.fit(
                f"PDK: [white]{pdk}[/white]\n[white]{passed}/{total} partitions proven[/white] · [orange1]{closure:.2f}%[/orange1]\n"
                f"partition: [white]{item.partition}[/white]\nstatus: [red]{item.status}[/red] · strategy: [white]{strategy.name}[/white]",
                title="EQY debug", border_style="orange1",
            ))
            failure = explanation.get("failure") or {}
            divergence = explanation.get("first_divergence")
            facts = Table(title="Counterexample", header_style="bold grey70", border_style="grey50")
            facts.add_column("Field", style="grey70")
            facts.add_column("Value", style="white")
            phase = failure.get("phase") or "unknown"
            step = failure.get("step")
            facts.add_row("Proof", phase + (f" · step {step}" if step is not None else ""))
            facts.add_row("Class", str(explanation.get("classification", "unclassified")))
            decoded = describe_partition(item.partition)
            if decoded:
                facts.add_row("Signal", decoded)
            if divergence:
                facts.add_row("First divergence", f"t={divergence.get('time')}")
                facts.add_row("Gold", f"{divergence.get('gold_signal')} = {divergence.get('gold')}")
                facts.add_row("Gate", f"{divergence.get('gate_signal')} = {divergence.get('gate')}")
                if divergence.get("gold_x_signal"):
                    facts.add_row("X masks", f"gold={divergence.get('gold_x')} · gate={divergence.get('gate_x')}")
            console.print(facts)

        clock = settings.get("EQY_CLOCK", "clk_i").strip() or "clk_i"
        reset = settings.get("EQY_RESET", "rst_ni").strip() or "rst_ni"
        reset_active = settings.get("EQY_RESET_ACTIVE", "low").strip().lower() or "low"
        explicit_reset = any(key in settings for key in ("EQY_CLOCK", "EQY_RESET", "EQY_RESET_ACTIVE"))
        reset_domains = None
        if not explicit_reset:
            try:
                from .backend.core import clock_config
                reset_domains = tuple(
                    (domain.signal, domain.reset, domain.reset_polarity)
                    for domain in clock_config(settings).domains
                )
            except (TypeError, ValueError):
                reset_domains = None
        try:
            reset_cycles = int(settings.get("EQY_RESET_CYCLES", "1"))
        except ValueError:
            reset_cycles = 1
        eqy = str(settings.get("EQY", "eqy"))

        if not as_json:
            console.print(f"[bold orange1][eqy_debug][/bold orange1] reset-state probe · [bright_cyan]{item.partition}[/bright_cyan]")
        try:
            reset_probe = run_reset_normalized_diagnostic(
                result_dir, partition=item.partition, clock=clock, reset=reset,
                reset_active=reset_active, reset_cycles=reset_cycles, eqy=eqy,
                domains=reset_domains,
            )
        except (FileNotFoundError, ValueError, RuntimeError, OSError) as exc:
            reset_probe = {"valid": False, "error": str(exc)}
        if not as_json:
            if reset_probe.get("valid"):
                status = str(reset_probe.get("status", "UNKNOWN"))
                color = "green" if status == "PASS" else "red" if status == "FAIL" else "orange1"
                cached = " · cached" if reset_probe.get("cached") else ""
                console.print(f"  [{color}]{status}[/{color}]{cached}")
            else:
                console.print("  [orange1]INCONCLUSIVE[/orange1]")

        synthesis_probe: dict[str, object] | None = None
        if reset_probe.get("valid") and reset_probe.get("status") != "PASS":
            from .backend.core import pdk_run_layout, run_root
            layout = pdk_run_layout(run_root(workspace, run_top=run_top, run_id=run_id), pdk=pdk, top=top)
            def progress(stage: str) -> None:
                if not as_json:
                    labels = {
                        "generic": "generic synthesis",
                        "dffmap": "after dfflibmap",
                        "abc": "after ABC",
                        "clean": "after final cleanup",
                    }
                    console.print(f"[bold orange1][eqy_debug][/bold orange1] {labels.get(stage, stage)} · [bright_cyan]{item.partition}[/bright_cyan]")
            synthesis_probe = run_synthesis_boundary_diagnostics(
                result_dir, top=top, syn_dir=layout.syn_dir, partition=item.partition,
                eqy=eqy, progress=progress,
            )
            if not as_json:
                for stage_name in ("generic", "dffmap", "abc", "clean"):
                    stage = (synthesis_probe.get("stages") or {}).get(stage_name, {})
                    if stage.get("valid"):
                        status = str(stage.get("status", "UNKNOWN"))
                        color = (
                            "green"
                            if status == "PASS"
                            else "red" if status == "FAIL" else "orange1"
                        )
                        cached = " · cached" if stage.get("cached") else ""
                        console.print(f"  [{color}]{status}[/{color}]{cached}")

        payload = {"pdk": pdk, "result_dir": str(result_dir), "passed": passed, "total": total,
                   "closure_pct": closure, "counterexample": explanation,
                   "reset_probe": reset_probe, "synthesis_probe": synthesis_probe}
        if as_json:
            print(json.dumps(payload, indent=2))
            return 0

        probe = Table(title="Targeted probes", header_style="bold grey70", border_style="grey50")
        probe.add_column("Boundary", style="white")
        probe.add_column("Selected partition", style="white")
        probe.add_row("mapped baseline", f"[red]{item.status}[/red]")
        if reset_probe.get("valid"):
            rs = str(reset_probe.get("status", "UNKNOWN"))
            rc = (
                "green"
                if rs == "PASS"
                else "red" if rs == "FAIL" else "orange1"
            )
            probe.add_row("after reset", f"[{rc}]{rs}[/{rc}]")
        else:
            probe.add_row("after reset", "[orange1]inconclusive[/orange1]")
        stages = (synthesis_probe or {}).get("stages", {}) if synthesis_probe else {}
        for key, label in (
            ("generic", "generic synthesis"),
            ("dffmap", "after dfflibmap"),
            ("abc", "after ABC"),
            ("clean", "after final cleanup"),
        ):
            stage = stages.get(key, {}) if isinstance(stages, dict) else {}
            if stage.get("valid"):
                ss = str(stage.get("status", "UNKNOWN"))
                sc = (
                    "green"
                    if ss == "PASS"
                    else "red" if ss == "FAIL" else "orange1"
                )
                probe.add_row(label, f"[{sc}]{ss}[/{sc}]")
            elif stage.get("missing"):
                probe.add_row(label, "[grey70]checkpoint missing[/grey70]")
        console.print(probe)

        if reset_probe.get("status") == "PASS":
            console.print("[orange1]Diagnosis:[/orange1] [white]mismatch disappears after deterministic reset initialization.[/white]")
        elif synthesis_probe:
            diagnosis = synthesis_boundary_diagnosis(stages if isinstance(stages, dict) else {})
            messages = {
                "missing": "synthesis checkpoints missing; run `fx syn --force`, `fx eqy --force`, then `fx eqy_debug`.",
                "generic_fail": "mismatch already exists after generic Yosys synthesis, before technology mapping.",
                "dffmap_fail": "generic synthesis passes; mismatch appears across dfflibmap/sequential mapping.",
                "abc_fail": "dfflibmap passes; mismatch is introduced by ABC combinational technology mapping.",
                "clean_fail": "ABC mapping passes but the cleanup checkpoint fails. Because cleanup is function-preserving, suspect loss of EQY match-points/names rather than a logic change; keep public names during final cleanup.",
                "serialization": "all RTLIL checkpoints pass; mismatch appears only after final Verilog serialization/readback in the EQY gate flow.",
            }
            message = messages.get(
                diagnosis,
                "synthesis-boundary probe is inconclusive; UNKNOWN and TIMEOUT are not evidence of a logic mismatch.",
            )
            console.print(f"[orange1]Diagnosis:[/orange1] [white]{message}[/white]")
        else:
            console.print("[orange1]Diagnosis:[/orange1] [white]reset probe inconclusive; inspect its log before synthesis-boundary attribution.[/white]")
        console.print(f"[grey70]Waveform:[/grey70] [white]fx eqy_debug --wave {item.partition}[/white]")
        console.print(f"[grey70]Artifacts:[/grey70] [white]fx eqy_debug --files {item.partition}[/white]")
        return 0

    # -----------------------------------------------------------------------
    # Target invocation and one-shot overrides
    # -----------------------------------------------------------------------

    def _overrides(sets: tuple[str, ...], tool: str | None, force: bool) -> dict[str, str]:
        """Collect one-shot FlexSoC setting overrides."""

        values = _assignments(sets)
        if tool:
            values["LINT_TOOL"] = tool
        if force:
            values["FORCE"] = "1"
        return values

    def _run(
        client: FlexSoC,
        targets: tuple[str, ...],
        *,
        sets: tuple[str, ...],
        tool: str | None,
        force: bool,
        dry_run: bool,
        script: bool,
        capture: bool,
        live: bool,
        as_json: bool,
        info: bool,
        no_setup: bool,
        on: str,
    ) -> int:
        """Run, preview, or describe requested targets."""

        if info:
            _print_info(client, targets, as_json)
            return 0

        try:
            values = _overrides(sets, tool, force)
            if live:
                values["LIVE"] = "1"

            result = client.run(
                *targets,
                check=False,
                dry_run=dry_run,
                capture=capture,
                live=live,
                auto_setup=not no_setup,
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

    # -----------------------------------------------------------------------
    # Interactive shell
    # -----------------------------------------------------------------------

    def _shell(root: Path, workdir: Path | None) -> int:
        """Open a Prompt Toolkit shell with command completion."""

        try:
            from prompt_toolkit import PromptSession
            from prompt_toolkit.completion import WordCompleter
            from prompt_toolkit.history import FileHistory
        except ModuleNotFoundError:
            console.print("[red]missing dependency: prompt_toolkit[/red]")
            return 2
        history = _settings_path(root).with_name("history")
        history.parent.mkdir(parents=True, exist_ok=True)
        session = PromptSession(
            history=FileHistory(str(history)),
            completer=WordCompleter(_completion_words(), ignore_case=True, sentence=True),
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
                _guide()
                continue
            app([*shlex.split(line), *( ["--workdir", str(workdir)] if workdir else [] )])

    # -----------------------------------------------------------------------
    # Typer command and entry point
    # -----------------------------------------------------------------------

    @typer_app.command(name="fx", help=HELP, no_args_is_help=False)
    def _entry(
        items: Annotated[
            list[str] | None,
            typer.Argument(
                help="Pseudo-command (`settings`, `commands`, `shell`) or one or more backend targets.",
                autocompletion=_complete_items,
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
        tool: Annotated[
            str | None,
            typer.Option("--tool", help="Shortcut for LINT_TOOL=VALUE.", rich_help_panel="Target options"),
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
        no_setup: Annotated[
            bool,
            typer.Option(
                "--no-setup",
                help="Run only the requested targets; do not prepend generated-script setup steps.",
                rich_help_panel="Target options",
            ),
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
        as_json: Annotated[
            bool,
            typer.Option("--json", help="Print machine-readable JSON.", rich_help_panel="Output"),
        ] = False,
        info: Annotated[
            bool,
            typer.Option("--info", help="Describe targets instead of running them.", rich_help_panel="Output"),
        ] = False,
    ) -> None:
        """Dispatch pseudo-commands or ordered backend targets."""

        root = (project_root or Path.cwd()).resolve()
        args, set_args, unset_args = tuple(items or ()), tuple(sets or ()), tuple(unsets or ())
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
        client = FlexSoC(FlexSoCConfig(root, workdir), **_read_settings(root))
        if not args:
            _guide()
            return
        if args[0] == "commands":
            _print_commands(client, as_json)
            return
        if args[0] == "settings":
            _settings(root, workdir, args[1:], set_args, unset_args, reset, as_json)
            return
        if args[0] == "doctor":
            from .backend.core.toolchain import run as run_doctor

            raise typer.Exit(run_doctor(root, as_json=as_json))
        if args[0] == "pdk":
            raise typer.Exit(_pdk(root, args[1:], set_args, force=force, as_json=as_json))
        if args[0] == "eqy_debug":
            raise typer.Exit(_eqy_debug(root, workdir, args[1:], set_args, as_json=as_json))
        if args[0] == "shell":
            raise typer.Exit(_shell(root, workdir))
        raise typer.Exit(
            _run(
                client,
                args,
                sets=set_args,
                tool=tool,
                force=force,
                dry_run=dry_run,
                script=script,
                capture=capture,
                live=live,
                as_json=as_json,
                info=info,
                no_setup=no_setup,
                on=on,
            )
        )

    def _click_command() -> click.Command:
        """Build the Click command generated by Typer."""

        return typer.main.get_command(typer_app)

    def app(argv: list[str] | None = None) -> int:
        """Run the fx command-line interface."""

        args = list(sys.argv[1:] if argv is None else argv)
        if "eqy_debug" in args:
            index = args.index("eqy_debug")
            args[index + 1:] = [
                token[2:] if token in {"--wave", "--files"} else token
                for token in args[index + 1:]
            ]
        if os.environ.get("_FX_COMPLETE") or os.environ.get("_FLEXSOC_COMPLETE"):
            try:
                return _click_command().main(
                    args=args, prog_name="fx", standalone_mode=False
                ) or 0
            except click.exceptions.Exit as exc:
                return int(exc.exit_code or 0)
        if (
            not args
            or args in (["-h"], ["--help"], ["help"])
            or (len(args) == 2 and args[0] == "help" and args[1] in HELP_WORDS)
        ):
            _guide()
            return 0
        help_command = _help_request(args)
        if help_command is not None:
            try:
                _print_command_help(help_command)
            except ValueError as exc:
                error_console.print(f"[red]{exc}[/red]")
                return 2
            return 0
        try:
            return _click_command().main(args=args, prog_name="fx", standalone_mode=False) or 0
        except click.exceptions.Exit as exc:
            return int(exc.exit_code or 0)
        except (click.ClickException, typer.BadParameter) as exc:
            exc.show()
            return int(exc.exit_code or 2)
        except KeyboardInterrupt:
            error_console.print("\n[red]interrupted[/red]")
            return 130

