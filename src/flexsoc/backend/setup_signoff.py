"""Render OpenSTA signoff scripts for a FlexSoC run directory."""

from __future__ import annotations

import argparse
import os
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Sequence


@dataclass
class STAConfig:
    """Configuration used to render OpenSTA timing, SDF, and power scripts."""

    top: str
    output_dir: Path
    syndir: Path | None = None
    sdcdir: Path | None = None
    simdir: Path | None = None
    liberty: list[Path] = field(default_factory=list)
    power_activity: float = 0.1
    power_duty: float = 0.5


def optional_path(value: str | None) -> Path | None:
    """Return a path for non-empty values and `None` for missing CLI inputs."""

    return Path(value) if value else None


def split_liberties(values: Sequence[str]) -> list[Path]:
    """Expand repeated or comma-separated liberty arguments into paths."""

    return [Path(token.strip()) for item in values for token in str(item).split(",") if token.strip()]


def parse_args(argv: Sequence[str]) -> STAConfig:
    """Parse the command-line arguments used by the Make flow."""

    parser = argparse.ArgumentParser(description="Generate OpenSTA signoff scripts.")
    parser.add_argument("--top", required=False, help="Top module name.")
    parser.add_argument("--output-dir", required=False, help="Output directory for generated signoff scripts.")
    parser.add_argument("--synthesis-dir", dest="syndir", help="Directory containing the synthesized netlist.")
    parser.add_argument("--constraints-dir", dest="sdcdir", help="Directory containing the generated SDC file.")
    parser.add_argument("--simulation-dir", dest="simdir", help="Directory containing simulation activity data.")
    parser.add_argument("--liberty", dest="liberty", action="append", default=[], help="Liberty file; repeat or comma-separate values.")
    parser.add_argument("--power-activity", type=float, default=0.1, help="Estimated transitions per clock cycle for power analysis.")
    parser.add_argument("--power-duty", type=float, default=0.5, help="Estimated probability that a signal is high for power analysis.")
    ns, _unknown = parser.parse_known_args(list(argv))

    top = ns.top or os.environ.get("TOP")
    out = ns.output_dir or os.environ.get("OUTPUT_DIR") or os.environ.get("OUTDIR") or os.environ.get("SIGNOFFDIR")
    if not top:
        parser.error("missing top name (use --top or set TOP)")
    if not out:
        parser.error("missing output dir (use --output-dir or set OUTPUT_DIR)")

    if ns.power_activity < 0.0:
        parser.error("--power-activity must be >= 0")
    if not 0.0 <= ns.power_duty <= 1.0:
        parser.error("--power-duty must be between 0 and 1")

    return STAConfig(
        top=str(top),
        output_dir=Path(out).resolve(),
        syndir=optional_path(ns.syndir),
        sdcdir=optional_path(ns.sdcdir),
        simdir=optional_path(ns.simdir),
        liberty=split_liberties(ns.liberty),
        power_activity=float(ns.power_activity),
        power_duty=float(ns.power_duty),
    )


def liberty_corner(path: Path) -> str:
    """Infer a short process corner name from a Liberty filename."""

    name = path.name.lower()
    for corner in ("ss", "tt", "ff"):
        if f"__{corner}_" in name or f"_{corner}_" in name or name.startswith(f"{corner}_"):
            return corner
    return path.stem


def tcl_quote(path: Path) -> str:
    """Quote a filesystem path using Tcl brace syntax."""

    return "{" + path.as_posix() + "}"


def render_init_opensta(config: STAConfig) -> str:
    """Render OpenSTA initialization shared by timing, SDF, and power."""

    lines = [
        'puts ""',
        'puts "=== flexsoc OpenSTA init ==="',
        'if {[info exists ::env(STA_CORNER)]} {set sta_corner $::env(STA_CORNER)} else {set sta_corner "default"}',
    ]
    if config.liberty:
        entries = " ".join("{" + liberty_corner(lib) + " " + lib.resolve().as_posix() + "}" for lib in config.liberty)
        fallback = next((lib for lib in config.liberty if liberty_corner(lib) == "tt"), config.liberty[0])
        lines += [
            f"set liberty_files {{{entries}}}",
            'set selected_lib ""',
            'foreach item $liberty_files {',
            '  lassign $item corner path',
            '  if {$corner == $sta_corner} {set selected_lib $path}',
            '}',
            'if {$selected_lib == "" && $sta_corner != "default"} {',
            '  puts stderr "ERROR: no Liberty configured for corner=$sta_corner"',
            '  exit 2',
            '}',
            f'if {{$selected_lib == ""}} {{set selected_lib "{fallback.resolve().as_posix()}"}}',
            'puts "corner=$sta_corner liberty=$selected_lib"',
            'read_liberty $selected_lib',
        ]
    else:
        lines.append('puts "WARNING: no --liberty provided"')

    if config.syndir:
        netlist = (config.syndir / f"{config.top}_synth.v").resolve()
        lines += [f'puts "read_verilog {tcl_quote(netlist)}"', f"read_verilog {tcl_quote(netlist)}"]
    else:
        lines.append('puts "WARNING: no --syndir provided; skipping read_verilog"')

    lines += [f'puts "link_design {config.top}"', f"link_design {config.top}"]
    if config.sdcdir:
        sdc = (config.sdcdir / f"{config.top}.sdc").resolve()
        lines += [f'puts "read_sdc {tcl_quote(sdc)}"', f"read_sdc {tcl_quote(sdc)}"]
    else:
        lines.append('puts "WARNING: no --sdcdir provided; skipping read_sdc"')
    return "\n".join(lines)


def render_sta_tcl(config: STAConfig) -> str:
    """Render a corner/mode aware OpenSTA timing report script."""

    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'if {[info exists ::env(STA_MODE)]} {set sta_mode $::env(STA_MODE)} else {set sta_mode "setup"}',
            'if {$sta_mode == "hold"} {set delay_type "min"} else {set delay_type "max"}',
            'puts "=== Static timing analysis ==="',
            'puts "corner=$sta_corner mode=$sta_mode path_delay=$delay_type"',
            'if {[info exists ::env(STA_PATHS)]} {set sta_paths $::env(STA_PATHS)} else {set sta_paths 100}',
            'if {[info exists ::env(STA_GROUPS)]} {set sta_groups $::env(STA_GROUPS)} else {set sta_groups 20}',
            'puts "report_checks group_count=$sta_groups endpoint_count=$sta_paths"',
            'report_checks -path_delay $delay_type -fields {slew cap input_pins nets fanout} -digits 3 -group_count $sta_groups -endpoint_count $sta_paths -sort_by_slack',
            'report_tns',
            'report_wns',
            'puts "=== flexsoc unconstrained paths ==="',
            'report_checks -unconstrained -path_delay $delay_type -group_count $sta_groups -endpoint_count $sta_paths',
            'puts "=== flexsoc unconstrained paths end ==="',
            "",
        ]
    )


def render_sta_violators_tcl(config: STAConfig) -> str:
    """Render a focused OpenSTA timing violators report script."""

    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Violators ==="',
            "report_check_types -max_slew -max_cap -max_fanout -violators",
            "report_checks -path_delay max -slack_max 0.0",
            "report_checks -path_delay min -slack_max 0.0",
            "",
        ]
    )


def render_write_sdf_tcl(config: STAConfig) -> str:
    """Render one SDF export for the Liberty selected by STA_CORNER."""

    sdf_dir = (config.output_dir / "sdf").resolve()
    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Write SDF ==="',
            f'set sdf_file [file join {tcl_quote(sdf_dir)} "{config.top}_${{sta_corner}}.sdf"]',
            'puts "corner=$sta_corner sdf=$sdf_file"',
            'write_sdf -divider . -include_typ $sdf_file',
            "",
        ]
    )


def render_power_estimate_tcl(config: STAConfig) -> str:
    """Render a corner-aware OpenSTA power estimate using global activity."""

    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Estimated power analysis ==="',
            f'puts "analysis=estimate activity_source=global activity={config.power_activity} transitions_per_cycle duty={config.power_duty}"',
            'puts "corner=$sta_corner"',
            f"set_power_activity -global -activity {config.power_activity} -duty {config.power_duty}",
            'puts "report_power"',
            "report_power",
            "",
        ]
    )


def write_text(path: Path, content: str) -> Path:
    """Write UTF-8 text and return the written path."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")
    return path


def write_signoff_scripts(config: STAConfig) -> list[Path]:
    """Write the OpenSTA script set and return the generated paths."""

    config.output_dir.mkdir(parents=True, exist_ok=True)
    return [
        write_text(config.output_dir / "sta.tcl", render_sta_tcl(config)),
        write_text(config.output_dir / "sta_violators.tcl", render_sta_violators_tcl(config)),
        write_text(config.output_dir / "write_sdf.tcl", render_write_sdf_tcl(config)),
        write_text(config.output_dir / "power_estimate.tcl", render_power_estimate_tcl(config)),
    ]


def main(argv: Sequence[str]) -> int:
    """Run the command-line entrypoint used by the Make flow."""

    write_signoff_scripts(parse_args(argv))
    return 0



if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
