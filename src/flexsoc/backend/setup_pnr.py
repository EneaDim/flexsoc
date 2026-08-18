"""Generate OpenROAD-flow-scripts physical-implementation configuration."""

from __future__ import annotations

import argparse
from pathlib import Path
from textwrap import dedent

from flexsoc.backend.output import print_script


def render_config(
    top: str,
    platform: str,
    netlist: Path,
    sdc_file: Path,
) -> str:
    """Render a physical-only ORFS config from FlexSoC synthesis artifacts."""

    return dedent(
        f"""\
        # OpenROAD-flow-scripts physical implementation (generated)
        export DESIGN_NICKNAME = {top}
        export DESIGN_NAME     = {top}
        export PLATFORM        = {platform}

        # FlexSoC owns synthesis and timing intent.
        export SYNTH_NETLIST_FILES := {netlist}
        export SDC_FILE             := {sdc_file}

        # Physical defaults; synthesis strategy does not alter these.
        export CORE_UTILIZATION ?= 50
        export PLACE_DENSITY ?= 0.58
        export PLACE_DENSITY_LB_ADDON = 0.20
        export TNS_END_PERCENT = 100

        export DETAILED_METRICS := 1
        export REPORT_CLOCK_SKEW := 1
        export GUI_TIMING := 1
        export SETUP_SLACK_MARGIN := 0
        export HOLD_SLACK_MARGIN  := 0
        export CELL_PAD_IN_SITES_GLOBAL_PLACEMENT := 0
        export CELL_PAD_IN_SITES_DETAIL_PLACEMENT := 0
        export DETAILED_ROUTE_END_ITERATION := 64
        export USE_FILL := 0
        export GPL_TIMING_DRIVEN := 1
        export GPL_ROUTABILITY_DRIVEN := 1
        """
    )


def write_config(
    top: str,
    outdir: Path,
    platform: str,
    netlist: Path,
    sdc_file: Path,
) -> Path:
    """Write `config.mk` for one physical implementation run."""

    outdir = outdir.expanduser().resolve()
    netlist = netlist.expanduser().resolve()
    sdc_file = sdc_file.expanduser().resolve()
    if not netlist.is_file():
        raise ValueError(f"synthesized netlist not found: {netlist}")
    if not sdc_file.is_file():
        raise ValueError(f"SDC not found: {sdc_file}")
    outdir.mkdir(parents=True, exist_ok=True)
    path = outdir / "config.mk"
    path.write_text(render_config(top, platform, netlist, sdc_file), encoding="utf-8")
    return path


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse CLI arguments for direct script execution."""

    parser = argparse.ArgumentParser(
        description="Generate an ORFS physical-only config from a mapped netlist and SDC."
    )
    parser.add_argument("--top", required=True, help="Top module name")
    parser.add_argument("--platform", required=True, help="Target OpenROAD platform")
    parser.add_argument("--netlist", required=True, help="FlexSoC synthesized implementation netlist")
    parser.add_argument("--sdc-file", required=True, help="Canonical design timing constraints")
    parser.add_argument("--output-dir", dest="outdir", required=True, help="Output directory")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run the command line entrypoint."""

    args = parse_args(argv)
    path = write_config(
        top=args.top,
        outdir=Path(args.outdir),
        platform=args.platform,
        netlist=Path(args.netlist),
        sdc_file=Path(args.sdc_file),
    )
    print_script(path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
