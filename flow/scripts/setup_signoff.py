#!/usr/bin/env python3
# Copyright 2025 Enea Dimroci
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
@file sta_script_generator.py
@brief Generate OpenSTA Tcl scripts for multi-corner STA, power, and SDF export.

This script parses command-line arguments describing a design (top module,
library files, SDC path, etc.) and automatically generates several Tcl
scripts to be consumed by OpenSTA:

- sta_violators.tcl : Focuses on paths with violations only.
- sta.tcl           : Full sign-off style STA report (timing + checks).
- power.tcl         : Probability-based and VCD-based power analysis.
- write_sdf.tcl     : SDF export for all corners.

The generated Tcl files assume a specific directory layout for synthesized
netlists, SDC, simulation VCDs, etc. Adjust the paths in the generation
functions if your flow differs.
"""

from __future__ import annotations

import argparse
import sys
from dataclasses import dataclass
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[2]  # repo root

from typing import Dict, List


# ======================================================================
# Data model
# ======================================================================

@dataclass
class STAConfig:
    """
    @brief Configuration container for STA Tcl script generation.

    This dataclass groups all user-provided parameters so they can be passed
    around in a clean and type-safe manner instead of relying on global
    variables.

    @param top           Name of the top-level module of the design.
    @param rtldir        Directory containing RTL (currently not used directly
                         in the Tcl, but kept for completeness / future use).
    @param sdcdir        Directory where the SDC file for @c top resides.
    @param libs          List of liberty files (must contain _tt_, _ss_, _ff_).
    @param clk_period_ns Clock period in nanoseconds.
    @param activity_pct  Input activity factor in percent (e.g. 20 for 20%).
    @param output_dir    Output directory where the Tcl files will be written.
    @param corners       Mapping "Slowest/Typical/Fastest" -> liberty file.
    """

    top: str
    repo_root: Path
    rtldir: Path
    sdcdir: Path
    libs: List[Path]
    clk_period_ns: int
    activity_pct: int
    output_dir: Path
    corners: Dict[str, Path]
    syndir: Path = Path("syn")
    simdir: Path = Path("sim")


# ======================================================================
# Argument parsing
# ======================================================================
def parse_args(argv: List[str]) -> STAConfig:
    """
    @brief Parse the command-line arguments and build an STAConfig instance.

    This function is responsible for:
    - Setting up argparse with meaningful help messages.
    - Converting string paths into Path objects.
    - Detecting TT/SS/FF liberty files and associating them with the proper
      OpenSTA corners (Slowest, Typical, Fastest).

    @param argv List of command-line arguments, usually @c sys.argv[1:].
    @return STAConfig instance with validated and normalized parameters.
    """
    parser = argparse.ArgumentParser(
        description=(
            "Generate OpenSTA Tcl scripts for timing, power, and SDF export "
            "across multiple corners."
        )
    )

    # Top module name
    parser.add_argument(
        "-top", "--top",
        type=str,
        required=True,
        help="Name of the top module in the design."
    )

    # Directory containing RTL sources (kept for completeness / future use)
    parser.add_argument(
        "-rtldir", "--rtldir",
        type=str,
        required=True,
        help="Directory of RTL source files of the design."
    )

    # Directory for SDC files
    parser.add_argument(
        "-sdcdir", "--sdcdir",
        type=str,
        required=True,
        help="Directory containing the SDC file of the design."
    )

    parser.add_argument(
        "-syndir", "--syndir",
        type=str,
        required=True,
        help="Directory containing the SYN file of the design."
    )

    parser.add_argument(
        "-simdir", "--simdir",
        type=str,
        required=True,
        help="Directory containing the SIM file of the design."
    )

    # Liberty file list (multiple liberty files required)
    parser.add_argument(
        "-libs", "--libs",
        nargs='+',
        type=str,
        required=True,
        help=(
            "Liberty files of the technology used. Must include files with "
            "tags '_tt_', '_ss_', and '_ff_' in their names."
        )
    )

    # Clock period in nanoseconds
    parser.add_argument(
        "-clk", "--clk",
        type=int,
        required=True,
        help="Clock period in nanoseconds."
    )

    # Input activity percentage for power estimation
    parser.add_argument(
        "-activity", "--activity",
        type=int,
        required=True,
        help="Input activity percentage for probability-based power analysis."
    )

    # Optional output folder (default: current directory)
    parser.add_argument(
        "-o", "--output",
        type=str,
        required=False,
        default=".",
        help="Output folder where Tcl scripts will be generated (default: current directory)."
    )

    args = parser.parse_args(argv)

    # Normalize / convert to Path for cleaner path handling
    top = args.top
    rtldir = Path(args.rtldir)
    sdcdir = Path(args.sdcdir)
    syndir = Path(args.syndir)
    simdir = Path(args.simdir)
    libs = [Path(lib) for lib in args.libs]
    clk_period_ns = args.clk
    activity_pct = args.activity
    output_dir = Path(args.output)

    # Derive corners from liberty filenames
    corners = detect_corners(libs)

    return STAConfig(
        repo_root=Path(__file__).resolve().parents[2],
        top=top,
        rtldir=rtldir,
        sdcdir=sdcdir,
        syndir=syndir,
        simdir=simdir,
        libs=libs,
        clk_period_ns=clk_period_ns,
        activity_pct=activity_pct,
        output_dir=output_dir,
        corners=corners,
    )


def detect_corners(libs: List[Path]) -> Dict[str, Path]:
    """
    @brief Detect TT/SS/FF liberty files and associate them with corners.

    This function looks for specific substrings in the liberty file names:
    - @c "_tt_"  → Typical corner
    - @c "_ss_"  → Slowest corner
    - @c "_ff_"  → Fastest corner

    If any of these cannot be found, the script terminates with an error, as
    OpenSTA needs all three corners for the generated Tcl scripts.

    @param libs List of liberty file paths provided by the user.
    @return Mapping of corner name ("Slowest", "Typical", "Fastest") to liberty path.
    """
    lib_tt = None
    lib_ss = None
    lib_ff = None

    for lib in libs:
        name = lib.name
        if "_tt_" in name:
            lib_tt = lib
        if "_ss_" in name:
            lib_ss = lib
        if "_ff_" in name:
            lib_ff = lib

    missing = [corner for corner, lib in
               [("Typical", lib_tt), ("Slowest", lib_ss), ("Fastest", lib_ff)]
               if lib is None]

    if missing:
        # Provide a clear diagnostic if something is wrong
        print(
            f"[ERROR] Missing liberty files for corners: {', '.join(missing)}. "
            "Expected filenames containing '_tt_', '_ss_', and '_ff_'.",
            file=sys.stderr,
        )
        sys.exit(1)

    return {
        "Slowest": lib_ss,   # Usually SS is the slow corner
        "Typical": lib_tt,   # TT is the typical corner
        "Fastest": lib_ff,   # FF is the fast corner
    }


# ======================================================================
# Tcl snippet generation helpers
# ======================================================================

def build_init_opensta(cfg: STAConfig) -> str:
    """
    @brief Build the Tcl header that initializes OpenSTA and reads design data.

    This common preamble is reused by all generated Tcl scripts. It:
    - Defines the OpenSTA corners (Slowest/Typical/Fastest).
    - Reads the liberty files for each corner.
    - Reads the post-synthesis Verilog netlist.
    - Links the top design.
    - Reads the SDC constraints.

    @param cfg Global configuration for STA script generation.
    @return Multi-line Tcl string forming the initialization section.
    """
    lines: List[str] = []

    vcd_abs = (Path(cfg.simdir) / f"{cfg.top}_tb.vcd").resolve().as_posix()

    # Print a small banner to the OpenSTA console
    lines += [
        'puts ""',
        'puts "==========================================================================="',
        'puts "Define corners Slowest Typical Fastest"',
        'puts "==========================================================================="',
        'puts ""',
        'puts "define_corners Slowest Typical Fastest"',
        'define_corners Slowest Typical Fastest',
        "",
    ]

    # Read liberty files per corner
    lines += [
        'puts ""',
        'puts "==========================================================================="',
        'puts "Read liberty files"',
        'puts "==========================================================================="',
        'puts ""',
    ]

    for corner_name, lib_path in cfg.corners.items():
        lp = Path(lib_path)
        lp_abs = (lp if lp.is_absolute() else (Path(cfg.repo_root) / lp)).resolve().as_posix()
        lines.append(f'puts "read_liberty -corner {corner_name} {lp_abs}"')
        lines.append(f"read_liberty -corner {corner_name} {lp_abs}")
    lines.append("")

    # Read synthesized netlist and link top module
    # Note: the path 'syn/<top>_synth.v' comes from the original script.
    #       Adjust if needed for your flow.
    lines += [
        'puts ""',
        'puts "==========================================================================="',
        'puts "Read verilog and link top module"',
        'puts "==========================================================================="',
        'puts ""',
        f'puts "read_verilog {(cfg.syndir / f"{cfg.top}_synth.v").resolve().as_posix()}"',
        f'puts "link_design {cfg.top}"',
        f"read_verilog {(cfg.syndir / f"{cfg.top}_synth.v").resolve().as_posix()}",
        f"link_design {cfg.top}",
        "",
    ]

    # Read SDC file from sdcdir/<top>.sdc
    sdc_path = cfg.sdcdir / f"{cfg.top}.sdc"
    lines += [
        'puts ""',
        'puts "==========================================================================="',
        'puts "Read SDC"',
        'puts "==========================================================================="',
        'puts ""',
        f'puts "read_sdc {sdc_path}"',
        f"read_sdc {sdc_path}",
        'puts ""',
        "",
    ]

    return "\n".join(lines)


def build_write_sdf_tcl(cfg: STAConfig) -> str:
    """
    Build Tcl script for writing SDF files for all corners.

    Outputs under: <output_dir>/sdf
      - <top>_tt.sdf (Typical)
      - <top>_ss.sdf (Slowest)
      - <top>_ff.sdf (Fastest)
    """
    sdf_dir = Path(cfg.output_dir) / "sdf"

    # Explicit filenames (Path-safe)
    sdf_tt = (sdf_dir / f"{cfg.top}_tt.sdf").as_posix()
    sdf_ss = (sdf_dir / f"{cfg.top}_ss.sdf").as_posix()
    sdf_ff = (sdf_dir / f"{cfg.top}_ff.sdf").as_posix()

    lines: List[str] = []

    # Common preamble (defines corners, reads libs, reads netlist, reads sdc, etc.)
    lines.append(build_init_opensta(cfg))

    lines += [
        "",
        'puts "==========================================================================="',
        'puts "Write SDF files for each corner"',
        'puts "==========================================================================="',
        'puts ""',
    ]

    # Typical (TT)
    lines += [
        f'puts "write_sdf -corner Typical -divider . -include_typ {sdf_tt}"',
        f"write_sdf -corner Typical -divider . -include_typ {sdf_tt}",
        "",
    ]

    # Slowest (SS)
    lines += [
        f'puts "write_sdf -corner Slowest -divider . -include_typ {sdf_ss}"',
        f"write_sdf -corner Slowest -divider . -include_typ {sdf_ss}",
        "",
    ]

    # Fastest (FF)
    lines += [
        f'puts "write_sdf -corner Fastest -divider . -include_typ {sdf_ff}"',
        f"write_sdf -corner Fastest -divider . -include_typ {sdf_ff}",
        "",
    ]

    return "\n".join(lines) + "\n"

def build_sta_violators_tcl(cfg: STAConfig) -> str:
    """
    @brief Build Tcl script focusing on timing paths that violate constraints.

    This script:
    - Reports min (hold) and max (setup) timing checks with a fixed slack,
      focusing on violating paths.
    - Reports unconstrained checks.
    - Prints worst slack for both min and max across all corners.

    @param cfg Global configuration for STA script generation.
    @return Multi-line Tcl string for sta_violators.tcl content.
    """
    lines: List[str] = []

    lines.append(build_init_opensta(cfg))

    # Hold violations (min path delay)
    lines += [
        'puts "==========================================================================="',
        'puts "(Hold) report_checks -path_delay min"',
        'puts "==========================================================================="',
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_checks -slack_max -0.01 -path_delay min '
        '        -fields {slew cap input nets fanout} '
        '        -format full_clock_expanded '
        '        -group_path_count 1000 '
        '        -corner [$corner name]',
        '    puts ""',
        '    set ws [sta::format_time [sta::worst_slack_corner $corner "min"] 4]',
        '    puts "worst slack hold corner [$corner name]: $ws"',
        '    puts ""',
        '}',
        "",
    ]

    # Setup violations (max path delay)
    lines += [
        'puts "==========================================================================="',
        'puts "(Setup) report_checks -path_delay max"',
        'puts "============================================================================"',
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_checks -slack_max -0.01 -path_delay max '
        '        -fields {slew cap input nets fanout} '
        '        -format full_clock_expanded '
        '        -group_path_count 1000 '
        '        -corner [$corner name]',
        '    puts ""',
        '    set ws [sta::format_time [sta::worst_slack_corner $corner "max"] 4]',
        '    puts "worst slack setup corner [$corner name]: $ws"',
        '    puts ""',
        '}',
        "",
    ]

    # Unconstrained checks
    lines += [
        'puts "==========================================================================="',
        'puts "(Unconstrained) report_checks -unconstrained"',
        'puts "==========================================================================="',
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_checks -slack_max -0.01 -unconstrained '
        '        -fields {slew cap input nets fanout} '
        '        -format full_clock_expanded '
        '        -corner [$corner name]',
        '    puts ""',
        '}',
        "",
    ]

    # Summary of worst slack
    lines += [
        'puts "==========================================================================="',
        'puts "report_worst_slack -max (Setup)"',
        'puts "============================================================================"',
        'report_worst_slack -max',
        'puts ""',
        'puts "==========================================================================="',
        'puts "report_worst_slack -min (Hold)"',
        'puts "============================================================================"',
        'report_worst_slack -min',
        'puts ""',
    ]

    return "\n".join(lines)


def build_sta_tcl(cfg: STAConfig) -> str:
    """
    @brief Build the more complete STA script with extensive checks.

    This script performs:
    - Full sorted timing reports (min/max) on all corners.
    - Unconstrained path checks.
    - Design rule checks (slew, capacitance, fanout) and violation counts.
    - Parasitic annotation status.
    - Setup sanity checks (unconstrained endpoints, no clocks, loops, etc.).
    - Clock skew, TNS, WNS, and worst slack reports.

    Essentially this is a sign-off-style STA report script.

    @param cfg Global configuration for STA script generation.
    @return Multi-line Tcl string for sta.tcl content.
    """
    lines: List[str] = []

    lines.append(build_init_opensta(cfg))

    # Hold analysis (min path delay)
    lines += [
        'puts "==========================================================================="',
        'puts "(Hold) report_checks -path_delay min"',
        'puts "==========================================================================="',
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_checks -sort_by_slack -path_delay min '
        '        -fields {slew cap input nets fanout} '
        '        -format full_clock_expanded '
        '        -group_path_count 1000 '
        '        -corner [$corner name]',
        '    puts ""',
        '    set ws [sta::format_time [sta::worst_slack_corner $corner "min"] 4]',
        '    puts "worst slack hold corner [$corner name]: $ws"',
        '    puts ""',
        '}',
        "",
    ]

    # Setup analysis (max path delay)
    lines += [
        'puts "==========================================================================="',
        'puts "(Setup) report_checks -path_delay max"',
        'puts "============================================================================"',
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_checks -sort_by_slack -path_delay max '
        '        -fields {slew cap input nets fanout} '
        '        -format full_clock_expanded '
        '        -group_path_count 1000 '
        '        -corner [$corner name]',
        '    puts ""',
        '    set ws [sta::format_time [sta::worst_slack_corner $corner "max"] 4]',
        '    puts "worst slack setup corner [$corner name]: $ws"',
        '    puts ""',
        '}',
        "",
    ]

    # Unconstrained checks (paths without proper constraints)
    lines += [
        'puts "==========================================================================="',
        'puts "(Unconstrained) report_checks -unconstrained"',
        'puts "==========================================================================="',
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_checks -unconstrained '
        '        -fields {slew cap input nets fanout} '
        '        -format full_clock_expanded '
        '        -corner [$corner name]',
        '    puts ""',
        '}',
        "",
    ]

    # DRV checks (max slew, max capacitance, max fanout)
    lines += [
        'puts "==========================================================================="',
        'puts "(All Violators) report_check_types -max_slew -max_cap -max_fanout -violators"',
        'puts "============================================================================"',
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_check_types -max_slew -max_capacitance -max_fanout '
        '        -violators -corner [$corner name]',
        '    puts ""',
        '    set net "NULL"',
        '    set violators 1',
        '    set min_max "max"',
        '    set slew_pins [sta::check_slew_limits $net $violators $corner $min_max]',
        '    puts "max slew violations count [$corner name]: [llength $slew_pins]"',
        '    set fanout_pins [sta::check_fanout_limits $net $violators $min_max]',
        '    puts "max fanout violations count [$corner name]: [llength $fanout_pins]"',
        '    set cap_pins [sta::check_capacitance_limits $net $violators $corner $min_max]',
        '    puts "max cap violations count [$corner name]: [llength $cap_pins]"',
        '    puts ""',
        '}',
        "",
    ]

    # Parasitic annotation report
    lines += [
        'puts "==========================================================================="',
        'puts "report_parasitic_annotation -report_unannotated"',
        'puts "============================================================================"',
        'report_parasitic_annotation -report_unannotated',
        'puts ""',
    ]

    # Global DRV violation counts
    lines += [
        'puts "==========================================================================="',
        'puts "max slew violation count [sta::max_slew_violation_count]"',
        'puts "max fanout violation count [sta::max_fanout_violation_count]"',
        'puts "max cap violation count [sta::max_capacitance_violation_count]"',
        'puts "============================================================================"',
        'puts ""',
    ]

    # Setup checks / constraint sanity
    lines += [
        'puts "==========================================================================="',
        'puts "check_setup -verbose -unconstrained_endpoints -multiple_clock '
        '-no_clock -no_input_delay -loops -generated_clocks"',
        'puts "==========================================================================="',
        'check_setup -verbose -unconstrained_endpoints -multiple_clock '
        '-no_clock -no_input_delay -loops -generated_clocks',
        'puts "============================================================================"',
    ]

    # Clock skew
    lines += [
        'puts "(Clock Skew) report_clock_skew"',
        'puts "============================================================================"',
        'report_clock_skew',
        'puts ""',
    ]

    # TNS (Total Negative Slack)
    lines += [
        'puts "==========================================================================="',
        'puts "report_tns"',
        'puts "============================================================================"',
        'report_tns',
        'puts ""',
    ]

    # WNS (Worst Negative Slack)
    lines += [
        'puts "==========================================================================="',
        'puts "report_wns"',
        'puts "============================================================================"',
        'report_wns',
        'puts ""',
    ]

    # Worst slack (max / min)
    lines += [
        'puts "==========================================================================="',
        'puts "report_worst_slack -max (Setup)"',
        'puts "============================================================================"',
        'report_worst_slack -max',
        'puts ""',
        'puts "==========================================================================="',
        'puts "report_worst_slack -min (Hold)"',
        'puts "============================================================================"',
        'report_worst_slack -min',
        'puts ""',
    ]

    return "\n".join(lines)


def build_power_tcl(cfg: STAConfig) -> str:
    """
    @brief Build Tcl script for probability-based and VCD-based power analysis.

    This script performs:
    - Probability-based power analysis with uniform input activity on all ports.
    - Zero activity on the reset port (rst_ni).
    - VCD-based power analysis using a VCD waveform from simulation.

    The script assumes:
    - The VCD is located at @c sim/<top>_tb.vcd
    - The scope is @c <top>_tb/u_<top>

    Adjust those paths/scope if your environment is different.

    @param cfg Global configuration for STA script generation.
    @return Multi-line Tcl string for power.tcl content.
    """
    lines: List[str] = []

    lines.append(build_init_opensta(cfg))

    # Probability-based power analysis
    activity = cfg.activity_pct
    lines += [
        'puts ""',
        'puts "==========================================================================="',
        'puts "(Probability Power Analysis) report_power"',
        'puts "============================================================================"',
        f'puts "set_power_activity -input -activity .{activity}"',
        'puts "set_power_activity -input_port rst_ni -activity 0"',
        f"set_power_activity -input -activity .{activity}",
        "set_power_activity -input_port rst_ni -activity 0",
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_power -corner [$corner name]',
        '    puts ""',
        '}',
        "",
    ]

    # VCD-based power analysis
# VCD-based power analysis
    # Default: sim/<top>_tb.vcd (generated by your sim target)
    vcd_scope = f"{cfg.top}_tb/u_{cfg.top}"
    vcd_abs = (cfg.simdir / f"{cfg.top}_tb.vcd").resolve().as_posix()

    lines += [
        'puts "==========================================================================="',
        'puts "(VCD Power Analysis) report_power"',
        'puts "============================================================================"',
        f'puts "read_vcd -scope {vcd_scope} {vcd_abs}"',
        f"read_vcd -scope {vcd_scope} {vcd_abs}",
        'foreach corner [sta::corners] {',
        '    puts ""',
        '    puts "======================= [$corner name] Corner ==================================="',
        '    report_power -corner [$corner name]',
        '    puts ""',
        '}',
    ]


    return "\n".join(lines)


# ======================================================================
# File I/O helpers
# ======================================================================

def write_text_file(path: Path, content: str) -> None:
    """
    @brief Write text content to a file, creating parent directories if needed.

    @param path    Target file path.
    @param content Full text content to be written.
    """
    # Ensure parent directory exists (e.g. output_dir, output_dir/sdf, etc.)
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as f:
        f.write(content)


# ======================================================================
# Main entry point
# ======================================================================
def main(argv: List[str]) -> None:
    """
    Main entry point: parse arguments and generate Tcl scripts.

    Flow:
      1) Parse CLI args into an STAConfig
      2) Normalize config path fields to pathlib.Path (defensive)
      3) Emit:
         - sta_violators.tcl
         - sta.tcl
         - power.tcl
         - write_sdf.tcl
    """
    try:
        cfg = parse_args(argv)

        # -----------------------------
        # Defensive normalization
        # -----------------------------
        # NOTE: cfg may contain strings even if annotated as Path.
        # We force normalization here to avoid "str / str" crashes inside builders.
        from pathlib import Path as _Path

        # output_dir is mandatory
        cfg.output_dir = _Path(cfg.output_dir).resolve()

        # Optional/required fields depending on your CLI. Normalize if present.
        if hasattr(cfg, "rtldir") and cfg.rtldir is not None:
            cfg.rtldir = _Path(cfg.rtldir).resolve()

        if hasattr(cfg, "sdcdir") and cfg.sdcdir is not None:
            cfg.sdcdir = _Path(cfg.sdcdir).resolve()

        if hasattr(cfg, "syndir") and cfg.syndir is not None:
            cfg.syndir = _Path(cfg.syndir).resolve()

        # libs may be list[str] or list[Path]
        if hasattr(cfg, "libs") and cfg.libs is not None:
            cfg.libs = [
            (_Path(x) if _Path(x).is_absolute() else (REPO_ROOT / _Path(x))).resolve()
            for x in cfg.libs
        ]

        # -----------------------------
        # Create output locations
        # -----------------------------
        output_dir = cfg.output_dir
        output_dir.mkdir(parents=True, exist_ok=True)

        # For write_sdf.tcl we also want sdf/ directory
        (output_dir / "sdf").mkdir(parents=True, exist_ok=True)

        # -----------------------------
        # Write Tcl scripts
        # -----------------------------
        sta_violators_path = output_dir / "sta_violators.tcl"
        sta_path           = output_dir / "sta.tcl"
        power_path         = output_dir / "power.tcl"
        write_sdf_path     = output_dir / "write_sdf.tcl"

        write_text_file(sta_violators_path, build_sta_violators_tcl(cfg))
        write_text_file(sta_path,           build_sta_tcl(cfg))
        write_text_file(power_path,         build_power_tcl(cfg))
        write_text_file(write_sdf_path,     build_write_sdf_tcl(cfg))

        # Optional info
        # print(f"[INFO] Generated Tcl scripts in: {output_dir}")

    except Exception as exc:
        exc_type, _, exc_traceback = sys.exc_info()
        lineno = exc_traceback.tb_lineno if exc_traceback is not None else "?"
        print(
            f"\033[38;5;208mError during script execution:\n"
            f"Error Type: {exc_type}\n"
            f"Line number: {lineno}\033[0;0m",
            file=sys.stderr,
        )
        print(exc, file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    # Pass sys.argv[1:] so parse_args does not see the script name.
    main(sys.argv[1:])

