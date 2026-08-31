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

from flexsoc.backend.core import layout_from_values
from flexsoc.backend.core.execution import print_label, print_script
from flexsoc.backend.impl.impl import resolve_orfs_artifact

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


@dataclass(frozen=True, slots=True)
class TimingScenario:
    """One explicit STA scenario: analysis mode plus resolved timing view."""

    name: str
    corner: str
    mode: str
    liberty: Path
    stage: str


def timing_scenarios(
    values: Mapping[str, str], liberties: Mapping[str, Path], stage: str
) -> tuple[TimingScenario, ...]:
    """Return deterministic setup/hold scenarios without inventing PDK views."""

    corners = _selection(
        values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
    )
    modes = _selection(values.get("STA_MODES"), "setup hold", ("setup", "hold"), "STA mode")
    return tuple(
        TimingScenario(f"{mode}_{corner}", corner, mode, liberties[corner], stage)
        for corner in corners
        for mode in modes
    )

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

def _report_section(text: str, start: str, end: str) -> str:
    """Return one generated report section, or the full report for legacy output."""

    if start not in text:
        return text
    section = text.split(start, 1)[1]
    if not end:
        return section
    return section.split(end, 1)[0] if end in section else section


def _timing_values(text: str) -> dict[str, float]:
    """Extract WNS/TNS and recover WNS from explicit violating path slack."""

    values: dict[str, float] = {}
    for name, pattern in (("wns", WNS_RE), ("tns", TNS_RE)):
        match = pattern.search(text)
        if match:
            values[name] = float(match.group(1))
    if "wns" not in values:
        section = _report_section(text, "=== Violating paths ===", "=== Near-critical paths ===")
        slacks = [
            float(match.group(1))
            for match in PATH_SLACK_RE.finditer(section)
            if match.group(2) == "VIOLATED"
        ]
        if slacks:
            values["wns"] = min(slacks)
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
            "flexsoc_section $report {Clock QoR}",
            "# OpenSTA reports minimum legal period and Fmax for every constrained clock.",
            "flexsoc_append_opensta $report report_clock_min_period",
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
        platform = values.get("ORS_TECH", values.get("PDK", "")).strip() or None
        raw_netlist = values.get("NETLIST") or values.get("PNR_NETLIST")
        netlist = Path(raw_netlist) if raw_netlist else resolve_orfs_artifact(
            layout.pnr_dir, "results", top, "6_final.v", platform
        )
        if netlist is None:
            raise ValueError(f"post-route netlist not found under {layout.pnr_dir / 'results'}")
        raw_spef = values.get("SPEF_FILE", "").strip()
        spef = Path(raw_spef) if raw_spef else resolve_orfs_artifact(
            layout.pnr_dir, "results", top, "6_final.spef", platform
        )
        if spef is None:
            raise ValueError(f"post-route SPEF not found under {layout.pnr_dir / 'results'}")
        return _require_file(netlist, "post-route netlist"), _require_file(spef, "SPEF")
    netlist = Path(values.get("NETLIST") or layout.syn_dir / f"{top}_synth.v")
    raw_spef = values.get("SPEF_FILE", "").strip()
    spef = Path(raw_spef).expanduser().resolve() if raw_spef else None
    return _require_file(netlist, "gate-level netlist"), _optional_file(spef, "SPEF")

def _stage_sdc(project_root: Path, values: Mapping[str, str]) -> Path:
    """Resolve the single authored design SDC for every sign-off stage."""

    raw = values.get("PNR_SDC_FILE", "").strip()
    if raw:
        return _require_file(Path(raw), "SDC")
    return _require_file(layout_from_values(project_root, values).signoff_sdc, "design SDC")

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

def _command_inputs(ctx: SignoffContext, script: Path) -> tuple[Path, ...]:
    """Return every file consumed by one generated OpenSTA script."""

    paths = [script, ctx.netlist, ctx.sdc, ctx.liberty, *ctx.macro_liberties]
    paths.extend(path for path in (ctx.spef, ctx.activity_file, ctx.gls_report) if path is not None)
    return tuple(dict.fromkeys(path.resolve() for path in paths))

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
    """Generate every canonical sign-off Tcl family in lifecycle order."""

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
    runtime_script = ctx.report_dir / script.name
    _write(runtime_script, _render(analysis, ctx))
    print_script(
        runtime_script,
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
    command = [values.get("STA", "sta"), "-exit", "-no_init", str(runtime_script)]
    if runner is None:
        rc = _run_sta(command, cwd=project_root, log=log)
    else:
        from flexsoc.backend.core import CommandRequest
        result = runner.run(
            CommandRequest(
                tuple(command), project_root, {}, log,
                inputs=_command_inputs(ctx, runtime_script), outputs=(ctx.report_dir,),
            ),
            on=on,
        )
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
    section = _report_section(text, "=== Violating paths ===", "=== Near-critical paths ===")
    wns = _timing_values(text).get("wns")
    violated = len(re.findall(r"\bslack\s+\(VIOLATED\)", section, re.IGNORECASE))
    return bool(violated or (wns is not None and wns < 0.0)), wns, violated

def _sta_scenario_summary(ctx: SignoffContext, report: Path) -> dict[str, Any]:
    """Normalize one scenario report into compact machine-readable QoR."""

    text = report.read_text(encoding="utf-8", errors="replace")
    timing = _timing_values(text)
    violating = _report_section(text, "=== Violating paths ===", "=== Near-critical paths ===")
    unconstrained = _report_section(text, "=== Unconstrained paths ===", "")
    clock_qor = _report_section(text, "=== Clock QoR ===", "=== Constraint validation ===")
    clocks = []
    for match in re.finditer(
        r"^\s*(\S+)\s+period_min\s*=\s*([-+0-9.eE]+)\s+fmax\s*=\s*(INF|[-+0-9.eE]+)\s*$",
        clock_qor,
        flags=re.IGNORECASE | re.MULTILINE,
    ):
        fmax = None if match.group(3).upper() == "INF" else float(match.group(3))
        clocks.append({
            "name": match.group(1),
            "minimum_period": float(match.group(2)),
            "fmax_mhz": fmax,
        })
    violation_count = len(re.findall(r"slack\s+\(VIOLATED\)", violating, flags=re.IGNORECASE))
    unconstrained_count = len(re.findall(r"^Startpoint:", unconstrained, flags=re.MULTILINE))
    return {
        "id": f"{ctx.mode}_{ctx.corner}",
        "corner": ctx.corner,
        "mode": ctx.mode,
        "stage": ctx.stage,
        "liberty": str(ctx.liberty),
        "spef": str(ctx.spef) if ctx.spef else None,
        "wns": timing.get("wns"),
        "tns": timing.get("tns"),
        "violating_paths": violation_count,
        "unconstrained_paths": unconstrained_count,
        "clocks": clocks,
        "status": "fail" if violation_count or unconstrained_count or (timing.get("wns") or 0.0) < 0.0 else "pass",
        "detail_report": str(report),
    }


def _write_sta_qor(
    root: Path,
    *,
    top: str,
    pdk: str,
    stage: str,
    sdc: Path,
    scenarios: Sequence[dict[str, Any]],
    failures: Sequence[str],
) -> tuple[Path, Path]:
    """Write the two canonical STA evidence files: human report plus JSON."""

    sta_root = root / "sta"
    sta_root.mkdir(parents=True, exist_ok=True)
    json_path = sta_root / "sta.json"
    report_path = sta_root / "sta.rpt"
    finite_wns = [float(item["wns"]) for item in scenarios if item.get("wns") is not None]
    finite_tns = [float(item["tns"]) for item in scenarios if item.get("tns") is not None]
    status = "fail" if failures or any(item.get("status") == "fail" for item in scenarios) else "pass"
    data = {
        "schema": 1,
        "top": top,
        "pdk": pdk,
        "stage": stage,
        "sdc": str(sdc),
        "status": status,
        "qor": {
            "scenario_count": len(scenarios),
            "failing_scenarios": sum(item.get("status") == "fail" for item in scenarios),
            "worst_wns": min(finite_wns) if finite_wns else None,
            "worst_tns": min(finite_tns) if finite_tns else None,
            "violating_paths": sum(int(item.get("violating_paths", 0)) for item in scenarios),
            "unconstrained_paths": sum(int(item.get("unconstrained_paths", 0)) for item in scenarios),
        },
        "failures": list(failures),
        "scenarios": list(scenarios),
    }
    json_path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    lines = [
        "FlexSoC Static Timing Analysis",
        "=" * 78,
        f"design      : {top}",
        f"pdk         : {pdk}",
        f"stage       : {stage}",
        f"sdc         : {sdc}",
        f"status      : {status.upper()}",
        "",
        "QoR",
        "-" * 78,
        f"scenarios             : {data['qor']['scenario_count']}",
        f"failing scenarios     : {data['qor']['failing_scenarios']}",
        f"worst WNS             : {data['qor']['worst_wns']}",
        f"worst TNS             : {data['qor']['worst_tns']}",
        f"violating paths       : {data['qor']['violating_paths']}",
        f"unconstrained paths   : {data['qor']['unconstrained_paths']}",
        "",
        "Scenarios",
        "-" * 78,
        f"{'scenario':18} {'mode':8} {'corner':8} {'WNS':>12} {'TNS':>12} {'viol':>6} {'uncon':>6} status",
    ]
    for item in scenarios:
        lines.append(
            f"{item['id']:18} {item['mode']:8} {item['corner']:8} "
            f"{str(item.get('wns')):>12} {str(item.get('tns')):>12} "
            f"{int(item.get('violating_paths', 0)):>6} {int(item.get('unconstrained_paths', 0)):>6} {item['status']}"
        )
    if failures:
        lines += ["", "Execution failures", "-" * 78, *failures]
    lines += ["", "Details", "=" * 78]
    for item in scenarios:
        detail = Path(item["detail_report"])
        lines += ["", f"[{item['id']}]", "-" * 78]
        if detail.is_file():
            lines.append(detail.read_text(encoding="utf-8", errors="replace").rstrip())
    report_path.write_text("\n".join(lines).rstrip() + "\n", encoding="utf-8")
    return report_path, json_path


def execute_static(analysis: str, project_root: Path, values: Mapping[str, str], *, runner=None, on: str = "local") -> int:
    """Execute static analysis across explicit timing scenarios and collect canonical QoR."""

    if analysis not in {"sta", "sdf", "power_estimate"}:
        raise ValueError(f"static analysis is not supported: {analysis}")
    layout = layout_from_values(project_root, values)
    stage = values.get("SIGNOFF_STAGE", "post_syn")
    root = layout.signoff_stage_root(stage)
    log_root = layout.signoff_stage_log_root(stage)
    liberties = _liberties(values)
    if analysis == "sta":
        scenarios = timing_scenarios(values, liberties, stage)
        work = tuple((scenario.corner, scenario.mode, scenario.liberty) for scenario in scenarios)
    else:
        corners = _selection(
            values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
        )
        work = tuple((corner, "", liberties[corner]) for corner in corners)

    failures: list[str] = []
    violations: list[str] = []
    sta_summaries: list[dict[str, Any]] = []
    for corner, mode, liberty in work:
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
            liberty=liberty,
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
            continue
        for report in _required_reports(analysis, ctx):
            print(f"[report] {corner}/{mode or analysis} {report}", flush=True)
            if analysis == "sta":
                summary = _sta_scenario_summary(ctx, report)
                sta_summaries.append(summary)
                if summary["status"] == "fail":
                    violations.append(
                        f"{corner}/{mode}: timing/constraint violation "
                        f"wns={summary.get('wns')} violating_paths={summary['violating_paths']} "
                        f"unconstrained_paths={summary['unconstrained_paths']}; report={report}"
                    )

    if analysis == "sta":
        report, data = _write_sta_qor(
            root,
            top=values.get("TOP", "test"),
            pdk=values.get("PDK", "unknown"),
            stage=stage,
            sdc=_stage_sdc(project_root, values),
            scenarios=sta_summaries,
            failures=failures,
        )
        print(f"[report] STA QoR {report}", flush=True)
        print(f"[report] STA JSON {data}", flush=True)
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
    """Generate and execute STA/SDF collateral from authored SDC intent."""

    project_root: Path
    values: Mapping[str, str]
    runner: object | None = None

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
