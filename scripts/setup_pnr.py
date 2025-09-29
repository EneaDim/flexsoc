#!/usr/bin/env python3
import argparse
from pathlib import Path
from textwrap import dedent

def main():
    p = argparse.ArgumentParser(
        description="Generate config.mk from rtl/rtl_list.f. "
                    "Only argument is the top module name."
    )
    p.add_argument("top", help="Top module name (used for DESIGN_NAME and DESIGN_NICKNAME)")
    p.add_argument("--platform", default="sky130hd", help="Target platform (default: sky130hd)")
    p.add_argument("--filelist", default="rtl/rtl_list.f",
                   help="Path to the .f file (default: rtl/rtl_list.f, relative to DESIGN_HOME at build time)")
    p.add_argument("--outfile", default="signoff/config.mk", help="Output file name (default: config.mk)")
    args = p.parse_args()

    # Write a Makefile that extracts sources & includes from the .f at build time.
    # Paths in FILELIST are interpreted relative to DESIGN_HOME (via $(DESIGN_HOME)/...).
    mk = f"""\
    export DESIGN_NICKNAME = {args.top}
    export DESIGN_NAME     = {args.top}
    export PLATFORM        = {args.platform}

    # --- filelist (.f) to read at build time ---
    FILELIST := {args.filelist}

    # Include dirs from +incdir+ entries
    export VERILOG_INCLUDE_DIRS := ips/pkgs

    # Source files: ignore blank lines, comments (#) and +incdir lines
    export VERILOG_FILES := $(shell awk '!/^\\s*($$|#)/ && $$0 !~ /^\\+incdir\\+/' $(FILELIST))

    # HDL frontend and constraints
    export SYNTH_HDL_FRONTEND = slang
    export SDC_FILE           = signoff/{args.top}.sdc

    # Floorplan / timing targets
    export CORE_UTILIZATION      ?= 50
    export PLACE_DENSITY_LB_ADDON = 0.20
    export TNS_END_PERCENT         = 100
    """

    out = Path(args.outfile)
    out.write_text(dedent(mk), encoding="utf-8")
    print(f"Wrote {out.resolve()}")

if __name__ == "__main__":
    main()

