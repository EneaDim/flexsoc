#!/usr/bin/env python3
"""Generate OpenROAD-flow-scripts `config.mk` files from RTL filelists."""

from __future__ import annotations

import argparse
from pathlib import Path
from textwrap import dedent


def unique_paths(paths: list[Path]) -> list[Path]:
    """Return paths in first-seen order while removing duplicates by string value."""

    seen: set[str] = set()
    out: list[Path] = []
    for path in paths:
        key = str(path)
        if key not in seen:
            seen.add(key)
            out.append(path)
    return out


def resolve_from(base: Path, value: str) -> Path:
    """Resolve a filelist entry against its filelist directory when needed."""

    path = Path(value.strip())
    return path if path.is_absolute() else (base / path).resolve()


def parse_filelist(filelist: Path) -> tuple[list[Path], list[Path]]:
    """Parse include directories and RTL files from a Verilog `.f` file."""

    inc_dirs: list[Path] = []
    files: list[Path] = []
    base = filelist.parent
    for raw in filelist.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        if line.startswith("+incdir+"):
            inc_dirs.append(resolve_from(base, line.removeprefix("+incdir+")))
        else:
            files.append(resolve_from(base, line))
    return unique_paths(inc_dirs), unique_paths(files)


def repo_common_incdirs() -> list[Path]:
    """Return common OpenTitan-style include directories used by FlexSoC RTL."""

    root = Path(__file__).resolve().parents[3]
    return unique_paths(
        [
            root / "hw/ips/pkgs",
            root / "hw/ips/prim",
            root / "hw/ips/prim_opentitan",
            root / "hw/ips/tlul",
        ]
    )


def render_config(
    top: str,
    inc_dirs: list[Path],
    vfiles: list[Path],
    outdir: Path,
    platform: str = "sky130hd",
    syn_strategy: str = "area",
    clk_period: int = 50,
) -> str:
    """Render an OpenROAD `config.mk` with absolute source and constraint paths."""

    return dedent(
        f"""\
        # =========================================
        # OpenROAD-flow-scripts — config.mk (generated)
        # Absolute paths (cwd-safe)
        # =========================================

        export DESIGN_NICKNAME = {top}
        export DESIGN_NAME     = {top}
        export PLATFORM        = {platform}

        # Sources
        export VERILOG_INCLUDE_DIRS := {' '.join(str(path) for path in inc_dirs)}
        export VERILOG_FILES := {' '.join(str(path) for path in vfiles)}

        # Constraints / Frontend
        export SYNTH_HDL_FRONTEND = slang
        export SDC_FILE           = {outdir / f'{top}.sdc'}

        # Strategy / timing knobs
        STRATEGY ?= {syn_strategy}
        TARGET_CLOCK_PS ?= {clk_period * 1000}

        export CORE_UTILIZATION ?= 50
        export PLACE_DENSITY_LB_ADDON = 0.20
        export TNS_END_PERCENT = 100

        export DETAILED_METRICS := 1
        export REPORT_CLOCK_SKEW := 1
        export YOSYS_FLAGS := -v 3
        export GUI_TIMING := 1

        export SETUP_SLACK_MARGIN := 0
        export HOLD_SLACK_MARGIN  := 0

        export CELL_PAD_IN_SITES_GLOBAL_PLACEMENT := 0
        export CELL_PAD_IN_SITES_DETAIL_PLACEMENT := 0

        export DETAILED_ROUTE_END_ITERATION := 64
        export USE_FILL := 0
        export GPL_TIMING_DRIVEN := 1
        export GPL_ROUTABILITY_DRIVEN := 1

        ifeq ($(STRATEGY),none)
          # vanilla
        endif

        ifeq ($(STRATEGY),area)
          export ABC_AREA := 1
          export ABC_CLOCK_PERIOD_IN_PS := $(TARGET_CLOCK_PS)
          export PLACE_DENSITY := 0.58
        endif

        ifeq ($(STRATEGY),delay)
          export ABC_AREA := 0
          export ABC_CLOCK_PERIOD_IN_PS := $(TARGET_CLOCK_PS)
          export PLACE_DENSITY := 0.55
        endif
        """
    )


def write_config(
    top: str,
    filelist: Path,
    outdir: Path,
    platform: str = "sky130hd",
    syn_strategy: str = "area",
    clk_period: int = 50,
) -> Path:
    """Write `config.mk` for a PnR run and return the generated path."""

    inc_dirs, vfiles = parse_filelist(filelist.expanduser().resolve())
    outdir = outdir.expanduser().resolve()
    outdir.mkdir(parents=True, exist_ok=True)
    text = render_config(
        top=top,
        inc_dirs=unique_paths(repo_common_incdirs() + inc_dirs),
        vfiles=vfiles,
        outdir=outdir,
        platform=platform,
        syn_strategy=syn_strategy,
        clk_period=clk_period,
    )
    path = outdir / "config.mk"
    path.write_text(text, encoding="utf-8")
    return path


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse CLI arguments for direct script execution."""

    parser = argparse.ArgumentParser(
        description="Generate OpenROAD-flow-scripts config.mk from an rtl_list.f."
    )
    parser.add_argument("top", help="Top module name")
    parser.add_argument("--syn_strategy", default="area", help="Synthesis strategy: none|area|delay")
    parser.add_argument("--clk_period", type=int, default=50, help="Clock period in ns")
    parser.add_argument("--platform", default="sky130hd", help="Target platform")
    parser.add_argument("--filelist", required=True, help="Path to the .f file")
    parser.add_argument("--outdir", required=True, help="Output directory")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run the command line entrypoint."""

    args = parse_args(argv)
    write_config(
        top=args.top,
        filelist=Path(args.filelist),
        outdir=Path(args.outdir),
        platform=args.platform,
        syn_strategy=args.syn_strategy,
        clk_period=args.clk_period,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
