#!/usr/bin/env python3
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
    activity_pct: float = 10.0


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
    parser.add_argument("--activity-pct", dest="activity_pct", type=float, default=10.0, help="Global activity percentage for power reports.")
    ns, _unknown = parser.parse_known_args(list(argv))

    top = ns.top or os.environ.get("TOP")
    out = ns.output_dir or os.environ.get("OUTPUT_DIR") or os.environ.get("OUTDIR") or os.environ.get("SIGNOFFDIR")
    if not top:
        parser.error("missing top name (use --top or set TOP)")
    if not out:
        parser.error("missing output dir (use --output-dir or set OUTPUT_DIR)")

    return STAConfig(
        top=str(top),
        output_dir=Path(out).resolve(),
        syndir=optional_path(ns.syndir),
        sdcdir=optional_path(ns.sdcdir),
        simdir=optional_path(ns.simdir),
        liberty=split_liberties(ns.liberty),
        activity_pct=float(ns.activity_pct),
    )


def tcl_quote(path: Path) -> str:
    """Quote a filesystem path using Tcl brace syntax."""

    return "{" + path.as_posix() + "}"


def render_init_opensta(config: STAConfig) -> str:
    """Render the common OpenSTA initialization shared by all reports."""

    lines = ['puts ""', 'puts "=== flexsoc OpenSTA init ==="']
    if config.liberty:
        for lib in config.liberty:
            lines += [f'puts "read_liberty {tcl_quote(lib)}"', f"read_liberty {tcl_quote(lib)}"]
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
    """Render the main setup and timing report script."""

    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Timing reports ==="',
            "report_checks -path_delay max -fields {slew cap input_pins} -digits 3",
            "report_checks -path_delay min -fields {slew cap input_pins} -digits 3",
            "report_tns",
            "report_wns",
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
    """Render a compact SDF export script with common corner filenames."""

    sdf_dir = (config.output_dir / "sdf").resolve()
    paths = [sdf_dir / f"{config.top}_{corner}.sdf" for corner in ("tt", "ss", "ff")]
    lines = [render_init_opensta(config), "", 'puts "=== Write SDF ==="']
    for path in paths:
        lines += [f'puts "write_sdf -divider . -include_typ {path.as_posix()}"', f"write_sdf -divider . -include_typ {path.as_posix()}"]
    return "\n".join(lines) + "\n"


def render_power_tcl(config: STAConfig) -> str:
    """Render a simple OpenSTA power script using global activity."""

    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Power ==="',
            f'puts "set_power_activity -global -activity {config.activity_pct}"',
            f"set_power_activity -global -activity {config.activity_pct}",
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
        write_text(config.output_dir / "power.tcl", render_power_tcl(config)),
    ]


def main(argv: Sequence[str]) -> int:
    """Run the command-line entrypoint used by the Make flow."""

    write_signoff_scripts(parse_args(argv))
    return 0



if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
