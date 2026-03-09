# ruff: noqa
#!/usr/bin/env python3
# Copyright 2025 Enea Dimroci
# Licensed under the Apache License, Version 2.0

import argparse
from pathlib import Path
from textwrap import dedent


def uniq(seq):
    out = []
    seen = set()
    for x in seq:
        s = str(x)
        if s in seen:
            continue
        seen.add(s)
        out.append(x)
    return out


def parse_filelist(filelist: Path):
    """
    Parse a Verilog/SystemVerilog filelist (.f).
    Supports:
      - blank lines / comments (#)
      - +incdir+<path>
      - file paths (absolute or relative to filelist directory)
    Returns: (include_dirs: list[Path], files: list[Path])
    """
    inc_dirs = []
    files = []
    base = filelist.parent

    for raw in filelist.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue

        if line.startswith("+incdir+"):
            d = line[len("+incdir+") :].strip()
            if not d:
                continue
            p = Path(d)
            if not p.is_absolute():
                p = (base / p).resolve()
            inc_dirs.append(p)
            continue

        p = Path(line)
        if not p.is_absolute():
            p = (base / p).resolve()
        files.append(p)

    return uniq(inc_dirs), uniq(files)


def repo_common_incdirs() -> list[Path]:
    repo_root = Path(__file__).resolve().parents[3]
    return uniq(
        [
            repo_root / "hw/ips/pkgs",
            repo_root / "hw/ips/prim",
            repo_root / "hw/ips/prim_opentitan",
            repo_root / "hw/ips/tlul",
        ]
    )


def main() -> int:
    ap = argparse.ArgumentParser(
        description="Generate OpenROAD-flow-scripts config.mk from an rtl_list.f (absolute, cwd-safe paths)."
    )
    ap.add_argument("top", help="Top module name")
    ap.add_argument("--syn_strategy", default="area", help="Synthesis strategy: none|area|delay")
    ap.add_argument("--clk_period", type=int, default=50, help="Clock period in ns")
    ap.add_argument("--platform", default="sky130hd", help="Target platform (default: sky130hd)")
    ap.add_argument("--filelist", required=True, help="Path to the .f file")
    ap.add_argument("--outdir", required=True, help="Output directory (will write <outdir>/config.mk)")
    args = ap.parse_args()

    top = args.top
    filelist = Path(args.filelist).expanduser().resolve()
    outdir = Path(args.outdir).expanduser().resolve()
    outdir.mkdir(parents=True, exist_ok=True)

    inc_dirs, vfiles = parse_filelist(filelist)

    # Always enforce the common include dirs needed by OpenTitan-style sources.
    inc_dirs = uniq(repo_common_incdirs() + inc_dirs)

    inc_str = " ".join(str(p) for p in inc_dirs)
    vfiles_str = " ".join(str(p) for p in vfiles)

    sdc_file = outdir / f"{top}.sdc"

    mk = f"""\
    # =========================================
    # OpenROAD-flow-scripts — config.mk (generated)
    # Absolute paths (cwd-safe)
    # =========================================

    export DESIGN_NICKNAME = {top}
    export DESIGN_NAME     = {top}
    export PLATFORM        = {args.platform}

    # Sources
    export VERILOG_INCLUDE_DIRS := {inc_str}
    export VERILOG_FILES := {vfiles_str}

    # Constraints / Frontend
    export SYNTH_HDL_FRONTEND = slang
    export SDC_FILE           = {sdc_file}

    # Strategy / timing knobs
    STRATEGY ?= {args.syn_strategy}
    TARGET_CLOCK_PS ?= {args.clk_period * 1000}

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

    (outdir / "config.mk").write_text(dedent(mk), encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
