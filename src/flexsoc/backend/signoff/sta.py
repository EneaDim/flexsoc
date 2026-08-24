"""Static timing, SDC and SDF engine shared by pre/post sign-off."""

from __future__ import annotations

import json
import os
import re
import shlex
import signal
import shutil
import subprocess
import sys
from dataclasses import dataclass, replace
from pathlib import Path
from typing import Any, Mapping, Sequence

from flexsoc.backend.core import ClockConfig, ClockDomain, clock_config, layout_from_values
from flexsoc.backend.core.execution import print_label, print_script

TEMPLATE = """current_design {top}

set clk_name {clk_name}
set clk_port_name {clk_port_name}
set clk_period {clk_period}
set clk_io_pct {clk_io_pct}

set clk_port [get_ports $clk_port_name]

create_clock -name $clk_name -period $clk_period $clk_port

set non_clock_inputs [all_inputs -no_clocks]

set_input_delay [expr $clk_period * $clk_io_pct] -clock $clk_name $non_clock_inputs
set_output_delay [expr $clk_period * $clk_io_pct] -clock $clk_name [all_outputs]
"""

def render_sdc(top: str, clk_period: float, clk_name: str = "core_clock", clk_port_name: str = "clk_i", clk_io_pct: float = 0.2) -> str:
    """Render the SDC text for one top module and clock definition."""

    return TEMPLATE.format(
        top=top,
        clk_name=clk_name,
        clk_port_name=clk_port_name,
        clk_period=f"{clk_period:g}",
        clk_io_pct=f"{clk_io_pct:g}",
    )

def render_clock_config_sdc(top: str, cfg: ClockConfig, clk_io_pct: float = 0.2) -> str:
    """Render SDC from the canonical clock model without inventing relationships."""

    by_name = {domain.name: domain for domain in cfg.domains}
    generated = {rel.target: rel for rel in cfg.relationships if rel.kind == "generated"}
    lines = [f"current_design {top}", ""]
    for domain in cfg.domains:
        rel = generated.get(domain.name)
        if rel:
            source = by_name[rel.source]
            lines.append(
                f"create_generated_clock -name {domain.name} -source [get_ports {source.signal}] "
                f"-divide_by {rel.divide_by} [get_ports {domain.signal}]"
            )
        else:
            lines.append(f"create_clock -name {domain.name} -period {domain.period_ns:g} [get_ports {domain.signal}]")
    lines.append("")
    for rel in cfg.relationships:
        if rel.kind == "async":
            lines.append(
                f"set_clock_groups -asynchronous -group [get_clocks {rel.source}] -group [get_clocks {rel.target}]"
            )
        elif rel.kind == "sync":
            lines.append(f"# synchronous relationship: {rel.source} <-> {rel.target}")
    if cfg.n_clocks == 1:
        domain = cfg.domains[0]
        lines += [
            "",
            "set non_clock_inputs [all_inputs -no_clocks]",
            f"set_input_delay [expr {domain.period_ns:g} * {clk_io_pct:g}] -clock {domain.name} $non_clock_inputs",
            f"set_output_delay [expr {domain.period_ns:g} * {clk_io_pct:g}] -clock {domain.name} [all_outputs]",
        ]
    else:
        lines += ["", "# Multi-clock IO delays are integration-specific and are intentionally not inferred."]
    return "\n".join(lines) + "\n"

def write_sdc(path: Path, text: str) -> Path:
    """Write SDC text to disk and return the resolved output path."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")
    return path.resolve()

SIGNOFF_SCENARIOS = {
    "ff": "min",
    "tt": "typ",
    "ss": "max",
}
SDF_MODE_TO_CORNER = {mode: corner for corner, mode in SIGNOFF_SCENARIOS.items()}
SDF_MODES = tuple(SDF_MODE_TO_CORNER)
ANALYSES = ("sta", "power_estimate", "power_analysis", "fusion_analysis")
POWER_RE = re.compile(
    r"^\s*Total\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)",
    re.MULTILINE,
)
ACTIVITY_RE = re.compile(r"Annotated\s+(\d+)\s+(?:pin\s+)?activities", re.IGNORECASE)
ACTIVITY_PERCENT_RE = re.compile(r"^annotated_percent=([0-9]+(?:\.[0-9]+)?)%\s*$", re.MULTILINE)
WNS_RE = re.compile(r"^\s*wns(?:\s+\w+)?\s+([-+0-9.eE]+)\s*$", re.IGNORECASE | re.MULTILINE)
TNS_RE = re.compile(r"^\s*tns(?:\s+\w+)?\s+([-+0-9.eE]+)\s*$", re.IGNORECASE | re.MULTILINE)
COMPLETE_PREFIX = "FLEXSOC_SIGNOFF_COMPLETE"
FLOAT_RE = re.compile(r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?")
PATH_START_RE = re.compile(r"(?=^Startpoint:)", re.MULTILINE)
PATH_PIN_RE = re.compile(r"^\s*(.*?)\s+([\^v])?\s*(\S+)\s+\(([^)]+)\)\s*$")
PATH_SLACK_RE = re.compile(
    r"^\s*(%s)\s+slack\s+\((MET|VIOLATED)\)" % FLOAT_RE.pattern,
    re.MULTILINE,
)

def scenario_corner(timing_mode: str) -> str:
    """Return the Liberty corner aligned with one SDF timing mode."""

    try:
        return SDF_MODE_TO_CORNER[timing_mode]
    except KeyError as exc:
        raise ValueError(
            f"no sign-off scenario for timing mode {timing_mode!r}; "
            f"expected one of {tuple(SDF_MODE_TO_CORNER)}"
        ) from exc

@dataclass(frozen=True, slots=True)
class SignoffContext:
    """Resolved inputs for one concrete OpenSTA script."""

    analysis: str
    design: str
    variant: str
    pdk: str
    stage: str
    corner: str
    mode: str
    workload: str
    top: str
    liberty: Path
    macro_liberties: tuple[Path, ...]
    netlist: Path
    sdc: Path
    report_dir: Path
    spef: Path | None = None
    activity_file: Path | None = None
    activity_scope: str = ""
    gls_report: Path | None = None
    estimated_activity: float = 0.1
    estimated_duty: float = 0.5
    global_activity: bool = False
    endpoint_group_limit: int = 10000
    endpoint_path_limit: int = 10
    near_critical_setup: float = 0.200
    near_critical_hold: float = 0.100
    power_top_instances: int = 20

def liberty_corner(path: Path) -> str:
    """Infer ``ss``, ``tt`` or ``ff`` from a Liberty filename."""

    name = path.name.lower()
    aliases = {
        "ss": ("ss", "slow", "worst"),
        "tt": ("tt", "typ", "typical"),
        "ff": ("ff", "fast", "best"),
    }
    for corner, tokens in aliases.items():
        for token in tokens:
            if (
                f"__{token}_" in name
                or f"_{token}_" in name
                or name.startswith(f"{token}_")
                or name.startswith(f"nom_{token}_")
            ):
                return corner
    return path.stem

def _quote(path: Path | str) -> str:
    """Return a Tcl brace-quoted value."""

    return "{" + str(path).replace("}", "\\}") + "}"

def _write(path: Path, text: str) -> Path:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text.rstrip() + "\n", encoding="utf-8")
    return path

def _require_file(path: Path, label: str) -> Path:
    path = path.expanduser().resolve()
    if not path.is_file():
        raise ValueError(f"missing {label}: {path}")
    return path

def _optional_file(path: Path | None, label: str) -> Path | None:
    if path is None:
        return None
    return _require_file(path, label)

def _split(value: str | None) -> tuple[str, ...]:
    return tuple(item.strip() for item in str(value or "").replace(",", " ").split() if item.strip())

def _truth(value: str | None) -> bool:
    return str(value or "").strip().lower() in {"1", "true", "yes", "on"}

def _selection(
    value: str | None, default: str, allowed: Sequence[str], label: str
) -> tuple[str, ...]:
    selected = _split(value or default)
    if not selected:
        raise ValueError(f"{label} must select at least one value")
    unknown = tuple(item for item in selected if item not in allowed)
    if unknown:
        raise ValueError(f"unsupported {label}: {unknown}; allowed={tuple(allowed)}")
    if len(set(selected)) != len(selected):
        raise ValueError(f"duplicate {label}: {selected}")
    return selected

def _live() -> bool:
    return _truth(os.environ.get("FLEXSOC_LIVE"))

def _paths(value: str | None) -> tuple[Path, ...]:
    return tuple(Path(item).expanduser().resolve() for item in _split(value))

def _liberties(values: Mapping[str, str]) -> dict[str, Path]:
    paths = [path for path in _paths(values.get("LIBS")) if path.is_file()]
    lib_syn = Path(values["LIB_SYN"]).expanduser().resolve() if values.get("LIB_SYN") else None
    if lib_syn and lib_syn.is_file() and lib_syn not in paths:
        paths.append(lib_syn)
    corners: dict[str, Path] = {}
    for path in paths:
        corner = liberty_corner(path)
        if corner in {"ss", "tt", "ff"}:
            corners.setdefault(corner, path)
    if not corners:
        raise ValueError("no ss/tt/ff Liberty views resolved for OpenSTA sign-off")
    return {corner: corners[corner] for corner in ("ss", "tt", "ff") if corner in corners}

def _load_json(path: Path) -> dict[str, Any]:
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as exc:
        raise ValueError(f"invalid JSON artifact {path}: {exc}") from exc
    if not isinstance(data, dict):
        raise ValueError(f"invalid JSON object: {path}")
    return data

def _selector(values: Mapping[str, str], plural: str, singular: str, default: str) -> tuple[str, ...]:
    raw = values.get(plural) or values.get(singular) or default
    return _split(raw)

def _run_sta(command: Sequence[str], *, cwd: Path, log: Path) -> int:
    log.parent.mkdir(parents=True, exist_ok=True)
    live = _live()
    if live:
        print("$ " + shlex.join(command), flush=True)
    with log.open("w", encoding="utf-8") as stream:
        proc = subprocess.Popen(
            list(command), cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True
        )
        assert proc.stdout is not None
        for line in proc.stdout:
            stream.write(line)
            if live:
                sys.stdout.write(line)
        rc = proc.wait()
    return rc

def _returncode_text(returncode: int) -> str:
    if returncode >= 0:
        return f"exit {returncode}"
    number = -returncode
    try:
        name = signal.Signals(number).name
    except ValueError:
        name = "UNKNOWN"
    return f"signal {number} ({name})"

def _timing_values(text: str) -> dict[str, float]:
    """Extract public ``report_wns``/``report_tns`` values when available."""

    values: dict[str, float] = {}
    for name, pattern in (("wns", WNS_RE), ("tns", TNS_RE)):
        match = pattern.search(text)
        if match:
            values[name] = float(match.group(1))
    return values

def _header(ctx: SignoffContext, limitations: Sequence[str]) -> str:
    macros = ", ".join(str(path) for path in ctx.macro_liberties) or "not used"
    lines = [
        "# =============================================================================",
        "# AUTO-GENERATED FLEXSOC OPENSTA ANALYSIS",
        "#",
        f"# Analysis : {ctx.analysis}",
        f"# Design   : {ctx.design}",
        f"# Variant  : {ctx.variant}",
        f"# PDK      : {ctx.pdk}",
        f"# Stage    : {ctx.stage}",
        f"# Corner   : {ctx.corner}",
        f"# Mode     : {ctx.mode or 'not applicable'}",
        f"# Workload : {ctx.workload or 'not applicable'}",
        f"# Top      : {ctx.top}",
        "#",
        "# Inputs:",
        f"#   Liberty       : {ctx.liberty}",
        f"#   Macro Liberty : {macros}",
        f"#   Netlist       : {ctx.netlist}",
        f"#   SDC           : {ctx.sdc}",
        f"#   SPEF          : {ctx.spef or 'not used'}",
        f"#   VCD or SAIF   : {ctx.activity_file or 'not used'}",
        f"#   Activity scope: {ctx.activity_scope or 'not used'}",
        f"#   GLS report    : {ctx.gls_report or 'not used'}",
        f"#   Report dir    : {ctx.report_dir}",
        "#",
        "# Limitations:",
        *[f"#   - {item}" for item in limitations],
        "#",
        "# Generated baseline: review or edit as needed; regeneration replaces this file.",
        "# =============================================================================",
    ]
    return "\n".join(lines)

def _common_init(ctx: SignoffContext, *, activity: bool) -> str:
    macro_list = " ".join(_quote(path) for path in ctx.macro_liberties)
    lines = [
        "",
        "# -----------------------------------------------------------------------------",
        "# Runtime validation and common OpenSTA initialization",
        "#",
        "# Each required input is checked before OpenSTA reads it.  The resulting linked",
        "# network associates netlist instances and pins with Liberty timing arcs,",
        "# sequential checks and power models.  A link failure normally identifies a",
        "# missing standard-cell or macro Liberty view.",
        "# -----------------------------------------------------------------------------",
        "proc flexsoc_require_readable {label path} {",
        "  if {![file exists $path] || ![file readable $path]} {",
        "    puts stderr \"ERROR: missing or unreadable $label: $path\"",
        "    exit 2",
        "  }",
        "}",
        f"set report_dir {_quote(ctx.report_dir)}",
        "file mkdir $report_dir",
        f"set liberty {_quote(ctx.liberty)}",
        f"set macro_liberties {{{macro_list}}}",
        f"set netlist {_quote(ctx.netlist)}",
        f"set sdc {_quote(ctx.sdc)}",
        f"set spef {_quote(ctx.spef) if ctx.spef else '{}'}",
        f"set top {_quote(ctx.top)}",
        f"set stage {_quote(ctx.stage)}",
        "# Validate every file referenced by this script before building the timing graph.",
        "flexsoc_require_readable \"standard-cell Liberty\" $liberty",
        "flexsoc_require_readable \"gate-level netlist\" $netlist",
        "flexsoc_require_readable \"SDC constraints\" $sdc",
        "foreach macro_lib $macro_liberties {flexsoc_require_readable \"macro Liberty\" $macro_lib}",
        "if {$spef ne \"\"} {flexsoc_require_readable \"SPEF parasitics\" $spef}",
        "",
        'puts "=== Step 1/7: Read Liberty ==="',
        'puts "liberty=$liberty"',
        "# Load the standard-cell Liberty view for this PVT corner; it supplies timing arcs, checks, and cell power data.",
        "read_liberty $liberty",
        "foreach macro_lib $macro_liberties {",
        '  puts "macro_liberty=$macro_lib"',
        "  # Load each macro Liberty view so hard macros participate in timing and power analysis.",
        "  read_liberty $macro_lib",
        "}",
        "",
        'puts "=== Step 2/7: Read netlist ==="',
        'puts "netlist=$netlist"',
        "# Read the mapped gate-level Verilog netlist that will be analyzed.",
        "read_verilog $netlist",
        "",
        'puts "=== Step 3/7: Link design ==="',
        'puts "top=$top"',
        "# Link the selected top and resolve every netlist cell against the loaded Liberty views.",
        "link_design $top",
        "",
        'puts "=== Step 4/7: Read SDC ==="',
        'puts "sdc=$sdc"',
        "# Apply clocks, I/O delays, uncertainties, exceptions, and electrical constraints from the SDC.",
        "read_sdc $sdc",
        "",
        'puts "=== Step 5/7: Read parasitics / establish clock model ==="',
        "if {$spef ne \"\"} {",
        '  puts "spef=$spef"',
        "  # Annotate extracted RC parasitics so interconnect delay and capacitance are included.",
        "  read_spef $spef",
        "} else {",
        '  puts "spef=not_used"',
        "}",
        "if {$stage eq \"post_route\"} {",
        "  # Collect all SDC clocks before switching post-route analysis to propagated clock latency.",
        "  set clocks [get_clocks *]",
        "  if {[llength $clocks] > 0} {",
        "    # Propagate clock-tree delay through the linked network instead of assuming ideal clocks.",
        "    set_propagated_clock $clocks",
        "  }",
        '  puts "clock_model=propagated"',
        "} else {",
        '  puts "clock_model=ideal post_synthesis"',
        "}",
        "proc flexsoc_section {path title} {",
        "  set fp [open $path a]",
        '  puts $fp ""',
        '  puts $fp "=== $title ==="',
        "  close $fp",
        "}",
        "proc flexsoc_label {path label} {",
        "  set fp [open $path a]",
        '  puts -nonewline $fp "$label "',
        "  close $fp",
        "}",
        "proc flexsoc_append_opensta {path args} {",
        "  # Capture one public OpenSTA report command without relying on command-specific > / >> support.",
        "  set capture [file join [file dirname $path] .flexsoc_opensta_capture.rpt]",
        "  file delete -force $capture",
        "  log_begin $capture",
        "  set code [catch {uplevel 1 $args} result options]",
        "  log_end",
        "  if {[file exists $capture]} {",
        "    set src [open $capture r]",
        "    set dst [open $path a]",
        "    fcopy $src $dst",
        "    close $src",
        "    close $dst",
        "    file delete -force $capture",
        "  }",
        "  if {$code != 0} {return -options $options $result}",
        "  return $result",
        "}",
        "",
        'puts "=== Step 6/7: Validate timing setup ==="',
        "# Validate clocks, endpoints, constraints, and timing relationships before generating reports.",
        "check_setup -verbose",
    ]
    if activity:
        lines += [
            "proc flexsoc_append_activity_coverage {path} {",
            "  # Keep activity evidence compact: percentage plus only the pins that were not annotated.",
            "  set capture [file join [file dirname $path] .flexsoc_activity_annotation.rpt]",
            "  file delete -force $capture",
            "  log_begin $capture",
            "  set code [catch {report_activity_annotation -report_unannotated} result options]",
            "  log_end",
            "  if {$code != 0} {",
            "    file delete -force $capture",
            "    return -options $options $result",
            "  }",
            "  if {![file exists $capture]} {error {activity annotation report was not captured}}",
            "  set src [open $capture r]",
            "  set text [read $src]",
            "  close $src",
            "  file delete -force $capture",
            "  set annotated 0",
            "  set unannotated 0",
            "  set have_annotated 0",
            "  set have_unannotated 0",
            "  set in_unannotated 0",
            "  set unannotated_pins {}",
            "  foreach line [split $text \"\\n\"] {",
            "    if {[regexp {^[[:space:]]*(vcd|saif|input)[[:space:]]+([0-9]+)[[:space:]]*$} $line -> origin count]} {",
            "      incr annotated $count",
            "      set have_annotated 1",
            "      continue",
            "    }",
            "    if {[regexp {^[[:space:]]*unannotated[[:space:]]+([0-9]+)[[:space:]]*$} $line -> count]} {",
            "      set unannotated $count",
            "      set have_unannotated 1",
            "      continue",
            "    }",
            "    if {[regexp -nocase {^[[:space:]]*Annotated[[:space:]]+([0-9]+).*activities} $line -> count]} {",
            "      set annotated $count",
            "      set have_annotated 1",
            "      continue",
            "    }",
            "    if {[regexp -nocase {^[[:space:]]*Unannotated[[:space:]]+([0-9]+).*activities} $line -> count]} {",
            "      set unannotated $count",
            "      set have_unannotated 1",
            "      continue",
            "    }",
            "    if {[regexp {^Unannotated pins:[[:space:]]*$} $line]} {",
            "      set in_unannotated 1",
            "      continue",
            "    }",
            "    if {$in_unannotated && [string trim $line] ne \"\"} {lappend unannotated_pins [string trim $line]}",
            "  }",
            "  if {!$have_annotated || !$have_unannotated} {error {could not parse OpenSTA activity annotation summary}}",
            "  set total [expr {$annotated + $unannotated}]",
            "  set percent [expr {$total > 0 ? 100.0 * $annotated / $total : 0.0}]",
            "  set dst [open $path a]",
            "  puts $dst [format {annotated_percent=%.2f%%} $percent]",
            "  if {[llength $unannotated_pins] == 0} {",
            "    puts $dst {Unannotated pins: none}",
            "  } else {",
            "    puts $dst {Unannotated pins:}",
            "    foreach pin $unannotated_pins {puts $dst \" $pin\"}",
            "  }",
            "  close $dst",
            "}",
            "",
            'puts "=== Step 7/7: Read activity ==="',
            f"set activity_file {_quote(ctx.activity_file) if ctx.activity_file else '{}'}",
            f"set activity_scope {_quote(ctx.activity_scope)}",
            "flexsoc_require_readable \"activity VCD/SAIF\" $activity_file",
            'puts "activity_file=$activity_file"',
            'puts "activity_scope=$activity_scope"',
            "# Select the public activity reader from the trace extension.",
            "set activity_ext [string tolower [file extension $activity_file]]",
            "if {$activity_ext eq \".saif\"} {",
            "  # Annotate averaged switching activity from SAIF at the GLS hierarchy scope.",
            "  read_saif -scope $activity_scope $activity_file",
            "} elseif {$activity_ext eq \".vcd\"} {",
            "  # Annotate signal transitions from the GLS VCD at the matching hierarchy scope.",
            "  read_vcd -scope $activity_scope $activity_file",
            "} else {",
            '  puts stderr "ERROR: activity file must be VCD or SAIF: $activity_file"',
            "  exit 2",
            "}",
        ]
    else:
        lines += ["", 'puts "=== Step 7/7: Analysis-specific reporting ==="']
    return "\n".join(lines)

def render_sta_tcl(ctx: SignoffContext) -> str:
    """Render one concise timing report for a concrete corner and mode."""

    delay_type = "min" if ctx.mode == "hold" else "max"
    threshold = ctx.near_critical_hold if ctx.mode == "hold" else ctx.near_critical_setup
    limitations = (
        "Violating, near-critical and unconstrained paths are separate sections of one report.",
        "Post-synthesis capacitance excludes routed parasitics unless an explicit SPEF is supplied.",
    )
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=False),
            "",
            f"set delay_type {delay_type}",
            f"set endpoint_group_limit {ctx.endpoint_group_limit}",
            f"set endpoint_path_limit {ctx.endpoint_path_limit}",
            f"set near_critical_limit {threshold:.6f}",
            "# Create one compact timing report for this corner/mode and write its analysis context first.",
            "set report [file join $report_dir timing.rpt]",
            "set fp [open $report w]",
            f'puts $fp "analysis=sta corner={ctx.corner} mode={ctx.mode} stage={ctx.stage}"',
            'puts $fp "liberty=$liberty"',
            'puts $fp "netlist=$netlist"',
            'puts $fp "sdc=$sdc"',
            'puts $fp "spef=$spef"',
            "close $fp",
            "flexsoc_section $report Units",
            "# Record the unit system used by all timing, slew, and capacitance values below.",
            "flexsoc_append_opensta $report report_units",
            "flexsoc_section $report {Delay model}",
            "set fp [open $report a]",
            f'puts $fp "clock_network={"propagated" if ctx.stage == "post_route" else "ideal"}"',
            f'puts $fp "interconnect={"spef" if ctx.stage == "post_route" else "none"}"',
            "close $fp",
            "flexsoc_section $report {Timing summary}",
            'flexsoc_label $report "wns $delay_type"',
            "# Report worst negative slack for the selected max/setup or min/hold analysis.",
            "flexsoc_append_opensta $report report_wns -$delay_type",
            'flexsoc_label $report "tns $delay_type"',
            "# Report total negative slack across all violating endpoints for this analysis type.",
            "flexsoc_append_opensta $report report_tns -$delay_type",
            "flexsoc_section $report {Constraint validation}",
            "# Append setup diagnostics so missing clocks, unconstrained endpoints, or invalid constraints stay visible.",
            "flexsoc_append_opensta $report check_setup -verbose",
            "# Append electrical and sequential timing checks such as slew, capacitance, fanout, recovery, and removal.",
            "flexsoc_append_opensta $report report_check_types -max_slew -max_capacitance -max_fanout -recovery -removal -min_pulse_width -min_period -min_delay -max_delay",
            *(
                [
                    "flexsoc_section $report {Routed parasitic annotation}",
                    "# Show SPEF coverage; unannotated routed nets remain explicit instead of silently using zero parasitics.",
                    "flexsoc_append_opensta $report report_parasitic_annotation -report_unannotated",
                    "flexsoc_section $report {Clock latency and skew}",
                    "# Report propagated clock-tree latency including Liberty internal clock latency where available.",
                    "flexsoc_append_opensta $report report_clock_latency -include_internal_latency -digits 6",
                    "# Report both setup and hold clock skew from the propagated post-route clock network.",
                    "flexsoc_append_opensta $report report_clock_skew -setup -include_internal_latency -digits 6",
                    "flexsoc_append_opensta $report report_clock_skew -hold -include_internal_latency -digits 6",
                    "flexsoc_section $report {Worst routed paths}",
                    "# Always show routed paths, even when timing is met, so cell and interconnect delay remain inspectable.",
                    "flexsoc_append_opensta $report report_checks -path_delay $delay_type -group_path_count 50 -endpoint_path_count 1 -unique_paths_to_endpoint -sort_by_slack -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6",
                ]
                if ctx.stage == "post_route"
                else []
            ),
            "flexsoc_section $report {Violating paths}",
            "# Report the worst violating paths first, including gate slew, capacitance, net, and fanout fields.",
            "flexsoc_append_opensta $report report_checks -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count $endpoint_path_limit -unique_paths_to_endpoint -sort_by_slack -slack_max 0.0 -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6",
            "flexsoc_section $report {Near-critical paths}",
            "# Report met paths close to zero slack so timing margin is visible before it becomes a violation.",
            "flexsoc_append_opensta $report report_checks -path_delay $delay_type -group_path_count 3000 -endpoint_path_count 3 -unique_paths_to_endpoint -sort_by_slack -slack_min 0.0 -slack_max $near_critical_limit -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6",
            "flexsoc_section $report {Unconstrained paths}",
            "# Report paths with no valid timing requirement; review these instead of treating them as passing timing.",
            "flexsoc_append_opensta $report report_checks -unconstrained -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count 1 -sort_by_slack -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6",
            'puts "report=$report"',
        ]
    )

def render_sdf_tcl(ctx: SignoffContext) -> str:
    limitations = ("SDF reflects the linked netlist and timing model for the selected corner.",)
    sdf = ctx.report_dir / f"{ctx.top}_{ctx.corner}.sdf"
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=False),
            "",
            "# write_sdf serializes the linked timing model for gate-level simulation.",
            f"set sdf_file {_quote(sdf)}",
            'puts "sdf=$sdf_file"',
            "write_sdf -divider . -include_typ -no_timestamp -no_version $sdf_file",
            "proc flexsoc_complete_sdf_typ_header {path} {",
            "  set fp [open $path r]",
            "  set text [read $fp]",
            "  close $fp",
            "  # OpenSTA 3.1 leaves PVT header typ empty even with -include_typ.",
            r"  regsub -all {(\(VOLTAGE[ \t]+)([-+0-9.eE]+)::([-+0-9.eE]+)(\))} $text {\1\2:\2:\3\4} text",
            r'  regsub -all {(\(PROCESS[ \t]+")([-+0-9.eE]+)::([-+0-9.eE]+)("\))} $text {\1\2:\2:\3\4} text',
            r"  regsub -all {(\(TEMPERATURE[ \t]+)([-+0-9.eE]+)::([-+0-9.eE]+)(\))} $text {\1\2:\2:\3\4} text",
            "  set fp [open $path w]",
            "  puts -nonewline $fp $text",
            "  close $fp",
            "}",
            "flexsoc_complete_sdf_typ_header $sdf_file",
            "proc flexsoc_strip_sdf_interconnect_cell {path} {",
            "  set fp [open $path r]",
            '  set lines [split [read $fp] "\n"]',
            "  close $fp",
            "  set out {}",
            "  set skipping 0",
            "  set skipped 0",
            "  set depth 0",
            "  set removed 0",
            "  foreach line $lines {",
            r'  if {!$skipped && !$skipping && [string trim $line] eq "(CELL"} {set skipping 1}',
            r'  if {$skipping} {',
            r'    incr removed [regexp -all {\(INTERCONNECT[ 	]} $line]',
            r'    set opens [regexp -all {\(} $line]',
            r'    set closes [regexp -all {\)} $line]',
            r'    incr depth [expr {$opens - $closes}]',
            r'    if {$depth == 0} {set skipping 0; set skipped 1}',
            "    continue",
            "  }",
            "  lappend out $line",
            "  }",
            r'  if {!$skipped} {puts stderr "ERROR: OpenSTA SDF interconnect cell not found: $path"; exit 2}',
            "  set fp [open $path w]",
            '  puts -nonewline $fp [join $out "\n"]',
            "  close $fp",
            r'  puts "sdf_interconnect=omitted count=$removed stage=post_syn"',
            "}",
            r'if {$stage eq "post_syn"} {',
            "  # Pre-implementation timing intentionally has no extracted interconnect model.",
            "  flexsoc_strip_sdf_interconnect_cell $sdf_file",
            "} else {",
            r'  puts "sdf_interconnect=retained stage=post_route"',
            "}",
        ]
    )

def _macro_liberties(values: Mapping[str, str]) -> tuple[Path, ...]:
    """Resolve and validate every configured macro Liberty view."""

    return tuple(_require_file(path, "macro Liberty") for path in _paths(values.get("MACRO_LIBS")))

def _stage_inputs(project_root: Path, values: Mapping[str, str]) -> tuple[Path, Path | None]:
    """Resolve netlist and optional SPEF from the existing synthesis/PnR trees."""

    layout = layout_from_values(project_root, values)
    stage = values.get("SIGNOFF_STAGE", "post_syn").strip().lower()
    if stage not in {"post_syn", "post_route"}:
        raise ValueError(f"SIGNOFF_STAGE must be post_syn or post_route, got {stage!r}")
    top = values.get("TOP", "test")
    if stage == "post_route":
        raw_netlist = values.get("NETLIST") or values.get("PNR_NETLIST")
        if raw_netlist:
            netlist = Path(raw_netlist)
        else:
            candidates = sorted((layout.pnr_dir / "results").glob(f"**/{top}/**/6_final.v"))
            if not candidates:
                candidates = sorted((layout.pnr_dir / "results").glob("**/6_final.v"))
            if not candidates:
                raise ValueError(f"post-route netlist not found under {layout.pnr_dir / 'results'}")
            netlist = candidates[-1]
        raw_spef = values.get("SPEF_FILE", "").strip()
        if raw_spef:
            spef = Path(raw_spef)
        else:
            candidates = sorted((layout.pnr_dir / "results").glob(f"**/{top}/**/6_final.spef"))
            if not candidates:
                candidates = sorted((layout.pnr_dir / "results").glob("**/6_final.spef"))
            if not candidates:
                raise ValueError(f"post-route SPEF not found under {layout.pnr_dir / 'results'}")
            spef = candidates[-1]
        return _require_file(netlist, "post-route netlist"), _require_file(spef, "SPEF")
    netlist = Path(values.get("NETLIST") or layout.syn_dir / f"{top}_synth.v")
    raw_spef = values.get("SPEF_FILE", "").strip()
    spef = Path(raw_spef).expanduser().resolve() if raw_spef else None
    return _require_file(netlist, "gate-level netlist"), _optional_file(spef, "SPEF")

def _stage_sdc(project_root: Path, values: Mapping[str, str]) -> Path:
    """Resolve the canonical pre-synthesis or final routed SDC."""

    layout = layout_from_values(project_root, values)
    raw = values.get("PNR_SDC_FILE", "").strip()
    if raw:
        return _require_file(Path(raw), "SDC")
    if values.get("SIGNOFF_STAGE", "post_syn") == "post_route":
        top = values.get("TOP", "test")
        candidates = sorted((layout.pnr_dir / "results").glob(f"**/{top}/**/6_final.sdc"))
        if not candidates:
            candidates = sorted((layout.pnr_dir / "results").glob("**/6_final.sdc"))
        if not candidates:
            raise ValueError(f"post-route SDC not found under {layout.pnr_dir / 'results'}")
        return _require_file(candidates[-1], "post-route SDC")
    return _require_file(layout.signoff_sdc, "SDC")

def _base_context(
    project_root: Path,
    values: Mapping[str, str],
    *,
    analysis: str,
    corner: str,
    mode: str = "",
    workload: str = "",
    report_dir: Path,
    liberty: Path,
    activity_file: Path | None = None,
    activity_scope: str = "",
    gls_report: Path | None = None,
    validate_stage_inputs: bool = True,
) -> SignoffContext:
    """Resolve one analysis context, optionally before the stage netlist exists."""

    layout = layout_from_values(project_root, values)
    if validate_stage_inputs or values.get("SIGNOFF_STAGE", "post_syn") == "post_route":
        netlist, spef = _stage_inputs(project_root, values)
    else:
        top = values.get("TOP", "test")
        netlist = Path(values.get("NETLIST") or layout.syn_dir / f"{top}_synth.v").expanduser().resolve()
        raw_spef = values.get("SPEF_FILE", "").strip()
        spef = Path(raw_spef).expanduser().resolve() if raw_spef else None
    sdc = _stage_sdc(project_root, values)
    return SignoffContext(
        analysis=analysis,
        design=values.get("RUN_TOP") or values.get("TOP", "test"),
        variant=values.get("RUN_ID", "default"),
        pdk=values.get("PDK", "sky130"),
        stage=values.get("SIGNOFF_STAGE", "post_syn"),
        corner=corner,
        mode=mode,
        workload=workload,
        top=values.get("TOP", "test"),
        liberty=_require_file(liberty, f"{corner} Liberty"),
        macro_liberties=_macro_liberties(values),
        netlist=netlist,
        sdc=sdc,
        report_dir=report_dir.expanduser().resolve(),
        spef=spef,
        activity_file=_optional_file(activity_file, "activity file"),
        activity_scope=activity_scope,
        gls_report=_optional_file(gls_report, "GLS report"),
        estimated_activity=float(values.get("POWER_ACTIVITY", "0.1")),
        estimated_duty=float(values.get("POWER_DUTY", "0.5")),
        global_activity=_truth(values.get("POWER_GLOBAL_ACTIVITY")),
        endpoint_group_limit=int(values.get("STA_ENDPOINT_GROUP_LIMIT", "10000")),
        endpoint_path_limit=int(values.get("STA_ENDPOINT_PATH_LIMIT", "10")),
        near_critical_setup=float(values.get("STA_NEAR_CRITICAL_SETUP", "0.200")),
        near_critical_hold=float(values.get("STA_NEAR_CRITICAL_HOLD", "0.100")),
        power_top_instances=int(values.get("POWER_TOP_INSTANCES", "20")),
    )

def _completion_marker(ctx: SignoffContext) -> str:
    return (
        f"{COMPLETE_PREFIX} analysis={ctx.analysis} corner={ctx.corner} "
        f"mode={ctx.mode or 'n/a'} workload={ctx.workload or 'n/a'}"
    )

def _render(analysis: str, ctx: SignoffContext) -> str:
    """Render one analysis through its owning sign-off engine."""

    if analysis == "sta":
        script = render_sta_tcl(ctx)
    elif analysis == "sdf":
        script = render_sdf_tcl(ctx)
    elif analysis in {"power_estimate", "power_analysis"}:
        from .power import render_power_analysis_tcl, render_power_estimate_tcl
        renderer = render_power_estimate_tcl if analysis == "power_estimate" else render_power_analysis_tcl
        script = renderer(ctx)
    elif analysis == "fusion_analysis":
        from .fusion import render_fusion_analysis_tcl
        script = render_fusion_analysis_tcl(ctx)
    else:
        raise ValueError(f"unsupported sign-off analysis: {analysis}")
    return script.rstrip() + f"\nputs {_quote(_completion_marker(ctx))}\n"

def generate_signoff_sdc(project_root: Path, values: Mapping[str, str]) -> Path:
    """Generate the canonical PDK-scoped SDC consumed by STA and physical implementation."""

    layout = layout_from_values(project_root, values)
    top = values.get("TOP", "test")
    cfg = clock_config(values)
    is_cordic = top.strip().lower() == "cordic"
    default_io_delay_pct = "0.1" if is_cordic else "0.2"
    io_delay_pct = float(values.get("SDC_IO_DELAY_PCT", default_io_delay_pct))
    signoff_period_ns = float(values.get("SDC_CLOCK_PERIOD_NS", "20"))
    if signoff_period_ns <= 0.0:
        raise ValueError("SDC_CLOCK_PERIOD_NS must be positive")
    cfg = ClockConfig(
        tuple(
            ClockDomain(
                domain.name,
                domain.signal,
                domain.reset,
                signoff_period_ns,
                domain.reset_polarity,
            )
            for domain in cfg.domains
        ),
        cfg.relationships,
    )
    print_label(
        "timing",
        f"sdc_clock_period={signoff_period_ns:g}ns · io_delay_pct={io_delay_pct:g}",
    )
    text = render_clock_config_sdc(top, cfg, io_delay_pct)
    path = write_sdc(layout.signoff_sdc, text)
    print_script(
        path,
        details={"owner": "signoff", "pdk": values.get("PDK", "sky130")},
    )
    return path

def generate_family(project_root: Path, values: Mapping[str, str], analysis: str) -> Path:
    """Generate one canonical sign-off Tcl family without side effects elsewhere."""

    supported = {"sta", "sdf", "power_estimate", "power_analysis", "fusion_analysis"}
    if analysis not in supported:
        raise ValueError(f"unsupported sign-off family: {analysis}")
    layout = layout_from_values(project_root, values)
    stage = values.get("SIGNOFF_STAGE", "post_syn")
    liberties = _liberties(values)
    corner = "tt" if "tt" in liberties else next(iter(liberties))
    liberty = liberties[corner]
    root = layout.signoff_stage_root(stage)
    specs = {
        "sta": (root / "sta" / "sta.tcl", "setup", root / "sta" / "template_reports"),
        "sdf": (root / "sdf" / "write_sdf.tcl", "", root / "sdf" / "template_reports"),
        "power_estimate": (
            root / "power" / "estimate" / "power_estimate.tcl",
            "",
            root / "power" / "estimate" / "template_reports",
        ),
        "power_analysis": (
            root / "power" / "analysis" / "power_analysis.tcl",
            "",
            root / "power" / "analysis" / "template_reports",
        ),
        "fusion_analysis": (
            root / "fusion" / "fusion_analysis.tcl",
            "setup",
            root / "fusion" / "template_reports",
        ),
    }
    path, mode, report_dir = specs[analysis]
    workload = "GLS_WORKLOAD_REQUIRED" if analysis in {"power_analysis", "fusion_analysis"} else ""
    ctx = _base_context(
        project_root,
        values,
        analysis=analysis,
        corner=corner,
        mode=mode,
        workload=workload,
        report_dir=report_dir,
        liberty=liberty,
        activity_file=None,
        activity_scope="DUT_SCOPE_REQUIRED" if workload else "",
        gls_report=None,
        validate_stage_inputs=False,
    )
    if workload:
        ctx = replace(
            ctx,
            activity_file=root / "power" / "activity" / "ACTIVITY_REQUIRED.vcd",
            gls_report=root / "power" / "activity" / "GLS_REPORT_REQUIRED.json",
        )
    written = _write(path, _render(analysis, ctx))
    print_script(written, details={
        "analysis": analysis,
        "stage": stage,
        "corner": corner,
        "mode": mode or "n/a",
    })
    return written


def generate_families(project_root: Path, values: Mapping[str, str]) -> tuple[Path, ...]:
    """Generate SDC and every canonical Tcl family in lifecycle order."""

    if values.get("SIGNOFF_STAGE", "post_syn") == "post_syn":
        generate_signoff_sdc(project_root, values)
    order = ("sta", "sdf", "power_estimate", "power_analysis", "fusion_analysis")
    return tuple(generate_family(project_root, values, analysis) for analysis in order)

def _required_reports(analysis: str, ctx: SignoffContext) -> tuple[Path, ...]:
    names = {
        "sta": ("timing.rpt",),
        "power_estimate": ("power.rpt",),
        "power_analysis": ("power.rpt",),
        "fusion_analysis": ("fusion.rpt",),
        "sdf": (f"{ctx.top}_{ctx.corner}.sdf",),
    }
    try:
        selected = names[analysis]
    except KeyError as exc:
        raise ValueError(f"unsupported analysis: {analysis}") from exc
    return tuple(ctx.report_dir / name for name in selected)

def _execute_script(
    project_root: Path,
    values: Mapping[str, str],
    *,
    analysis: str,
    ctx: SignoffContext,
    script: Path,
    log: Path,
    runner=None,
    on: str = "local",
) -> int:
    """Execute one OpenSTA script and reject truncated/incomplete output."""

    if ctx.report_dir.is_symlink() or ctx.report_dir.is_file():
        ctx.report_dir.unlink()
    elif ctx.report_dir.exists():
        shutil.rmtree(ctx.report_dir)
    ctx.report_dir.mkdir(parents=True)
    _write(script, _render(analysis, ctx))
    print_script(
        script,
        details={
            "analysis": analysis,
            "stage": ctx.stage,
            "corner": ctx.corner,
            "mode": ctx.mode or "n/a",
            "workload": ctx.workload or "n/a",
            "liberty": ctx.liberty.name,
            "report_dir": ctx.report_dir,
        },
    )
    command = [values.get("STA", "sta"), "-exit", "-no_init", str(script)]
    if runner is None:
        rc = _run_sta(command, cwd=project_root, log=log)
    else:
        from flexsoc.backend.core import CommandRequest
        result = runner.run(CommandRequest(tuple(command), project_root, {}, log, inputs=(script,), outputs=(ctx.report_dir,)), on=on)
        rc = result.returncode
    if rc != 0:
        return rc
    transcript = (
        log.read_text(encoding="utf-8", errors="replace") if log.is_file() else ""
    )
    marker = _completion_marker(ctx)
    if marker not in transcript:
        tail = "\n".join(transcript.rstrip().splitlines()[-20:])
        raise ValueError(
            f"{analysis} ended before its completion marker; log={log}"
            + (f"\n--- OpenSTA tail ---\n{tail}" if tail else "")
        )
    missing = [path for path in _required_reports(analysis, ctx) if not path.is_file()]
    if missing:
        rendered = "\n  ".join(str(path) for path in missing)
        raise ValueError(f"{analysis} completed without required report(s):\n  {rendered}")
    if analysis in {"power_estimate", "power_analysis", "fusion_analysis"}:
        from .power import _annotate_power_summary
        _annotate_power_summary(
            ctx.report_dir,
            "fusion.rpt" if analysis == "fusion_analysis" else "power.rpt",
        )
    return 0

def _sta_report_violation(path: Path) -> tuple[bool, float | None, int]:
    """Return whether one STA report contains a real negative-slack violation."""

    text = path.read_text(encoding="utf-8", errors="replace")
    timing = _timing_values(text)
    wns = timing.get("wns")
    violated = len(re.findall(r"\bslack\s+\(VIOLATED\)", text, re.IGNORECASE))
    return bool(violated or (wns is not None and wns < 0.0)), wns, violated

def execute_static(analysis: str, project_root: Path, values: Mapping[str, str], *, runner=None, on: str = "local") -> int:
    """Generate and execute STA, SDF or vectorless power at every configured corner."""

    if analysis not in {"sta", "sdf", "power_estimate"}:
        raise ValueError(f"static analysis is not supported: {analysis}")
    layout = layout_from_values(project_root, values)
    stage = values.get("SIGNOFF_STAGE", "post_syn")
    root = layout.signoff_stage_root(stage)
    log_root = layout.signoff_stage_log_root(stage)
    liberties = _liberties(values)
    corners = _selection(
        values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
    )
    modes = (
        _selection(values.get("STA_MODES"), "setup hold", ("setup", "hold"), "STA mode")
        if analysis == "sta"
        else ("",)
    )
    failures: list[str] = []
    violations: list[str] = []
    for corner in corners:
        for mode in modes:
            if analysis == "sta":
                report_dir = root / "sta" / corner / mode
                script = root / "sta" / "sta.tcl"
                log = log_root / "sta" / corner / mode / f"{values.get('TOP', 'test')}.log"
            elif analysis == "sdf":
                report_dir = root / "sdf" / corner
                script = root / "sdf" / "write_sdf.tcl"
                log = log_root / "sdf" / corner / f"{values.get('TOP', 'test')}.log"
            else:
                report_dir = root / "power" / "estimate" / corner
                script = root / "power" / "estimate" / "power_estimate.tcl"
                log = log_root / "power" / "estimate" / corner / f"{values.get('TOP', 'test')}.log"
            ctx = _base_context(
                project_root,
                values,
                analysis=analysis,
                corner=corner,
                mode=mode,
                report_dir=report_dir,
                liberty=liberties[corner],
            )
            try:
                rc = _execute_script(
                    project_root,
                    values,
                    analysis=analysis,
                    ctx=ctx,
                    script=script,
                    log=log,
                    runner=runner,
                    on=on,
                )
            except (OSError, ValueError, subprocess.SubprocessError) as exc:
                failures.append(f"{corner}/{mode or analysis}: {exc}")
                continue
            if rc != 0:
                failures.append(f"{corner}/{mode or analysis}: OpenSTA return code {rc}; log={log}")
            else:
                for report in _required_reports(analysis, ctx):
                    print(f"[report] {corner}/{mode or analysis} {report}", flush=True)
                    if analysis == "sta":
                        violated, wns, path_count = _sta_report_violation(report)
                        if violated:
                            wns_text = "n/a" if wns is None else f"{wns:g}"
                            violations.append(
                                f"{corner}/{mode}: timing violation wns={wns_text} "
                                f"violating_paths={path_count}; report={report}"
                            )
    for failure in failures:
        print(f"ERROR: {failure}", file=sys.stderr)
    for violation in violations:
        print(f"ERROR: {violation}", file=sys.stderr)
    if failures:
        return 2
    return 1 if violations else 0

def execute_activity(analysis: str, action: str, project_root: Path, values: Mapping[str, str]) -> int:
    """Dispatch workload-dependent power or fusion analysis."""

    from .power import execute_activity as run_activity
    return run_activity(analysis, action, project_root, values)


@dataclass(slots=True)
class StaAnalysis:
    """Generate SDC/STA/SDF collateral and execute static timing analyses."""

    project_root: Path
    values: Mapping[str, str]
    runner: object | None = None

    def setup_sdc(self) -> Path:
        """Generate the canonical pre-implementation SDC."""

        return generate_signoff_sdc(self.project_root, self.values)

    def setup_sta(self) -> Path:
        """Generate only the canonical STA Tcl template."""

        return generate_family(self.project_root, self.values, "sta")

    def setup_sdf(self) -> Path:
        """Generate only the canonical SDF Tcl template."""

        return generate_family(self.project_root, self.values, "sdf")

    def run_sta(self, *, on: str = "local") -> int:
        """Run all configured setup/hold timing scenarios."""

        return execute_static("sta", self.project_root, self.values, runner=self.runner, on=on)

    def write_sdf(self, *, on: str = "local") -> int:
        """Write SDF for all configured corners."""

        return execute_static("sdf", self.project_root, self.values, runner=self.runner, on=on)
