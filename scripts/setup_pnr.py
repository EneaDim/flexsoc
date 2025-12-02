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

import argparse
from pathlib import Path
from textwrap import dedent

def main():
    p = argparse.ArgumentParser(
        description="Generate config.mk from rtl/rtl_list.f. "
                    "Only argument is the top module name."
    )
    p.add_argument("top",
                   help="Top module name (used for DESIGN_NAME and DESIGN_NICKNAME)")
    p.add_argument("--syn_strategy", default="area",
                   help="Synthesis strategy : area / delay")
    p.add_argument("--clk_period", type=int, default="50",
                   help="Clock period in ns")
    p.add_argument("--platform", default="sky130hd",
                   help="Target platform (default: sky130hd)")
    p.add_argument("--filelist", default="rtl/rtl_list.f",
                   help="Path to the .f file (default: rtl/rtl_list.f, relative to DESIGN_HOME at build time)")
    p.add_argument("--outdir", default="ors",
                   help="Output directory name (default: ors)")
    args = p.parse_args()

    # Write a Makefile that extracts sources & includes from the .f at build time.
    # Paths in FILELIST are interpreted relative to DESIGN_HOME (via $(DESIGN_HOME)/...).

    mk = f"""\
    # =========================================
    # OpenROAD-flow-scripts — single-file config.mk
    # Strategy-aware: none | area | delay
    # =========================================
    
    ##### [Design identity]
    export DESIGN_NICKNAME = {args.top}
    export DESIGN_NAME     = {args.top}
    export PLATFORM        = {args.platform}
    
    ##### [Sources]
    # Filelist (.f) with +incdir+ and files
    FILELIST := {args.filelist}
    # Include dirs gathered from +incdir+ entries in FILELIST
    export VERILOG_INCLUDE_DIRS := ips/pkgs
    # Source files: ignore blanks, comments (#) and +incdir+ lines
    export VERILOG_FILES := $(shell awk '!/^\\s*($$|#)/ && $$0 !~ /^\\+incdir\\+/' $(FILELIST))
    
    ##### [Constraints / Frontend]
    export SYNTH_HDL_FRONTEND = slang
    export SDC_FILE           = {args.outdir}/{args.top}.sdc
    
    ##### [User knobs (override from Python/CLI)]
    # Strategy for QoR trade-off across the whole flow:
    #   none  = vanilla (no extra bias)
    #   area  = minimize area (keep timing)
    #   delay = push frequency (timing-driven)
    STRATEGY ?={args.syn_strategy}
    
    # ABC target period (ps). Empty = use SDC period.
    TARGET_CLOCK_PS ?={args.clk_period*1000}
    
    # Base core utilization (platform default is also fine)
    export CORE_UTILIZATION ?= 50
    # Ensure a safe lower bound for density
    export PLACE_DENSITY_LB_ADDON = 0.20
    # Repair all violating endpoints by default
    export TNS_END_PERCENT = 100
    
    ##### [General reporting / quality-of-life]
    export DETAILED_METRICS := 1
    export REPORT_CLOCK_SKEW := 1
    export YOSYS_FLAGS := -v 3
    # Keep GUI timing on by default (disable for very large designs)
    export GUI_TIMING := 1
    
    # -------------------------------------------------
    # Common defaults (applied to all strategies)
    # -------------------------------------------------
    # Don’t add artificial guardbands; repair what actually violates
    export SETUP_SLACK_MARGIN := 0
    export HOLD_SLACK_MARGIN  := 0
    
    # Leave padding at 0 unless you hit congestion/DRV
    export CELL_PAD_IN_SITES_GLOBAL_PLACEMENT := 0
    export CELL_PAD_IN_SITES_DETAIL_PLACEMENT := 0
    
    # Keep routing defaults conservative; tune only if needed
    export DETAILED_ROUTE_END_ITERATION := 64
    # export ROUTING_LAYER_ADJUSTMENT := 0.50
    
    # Disable metal fill unless required
    export USE_FILL := 0
    
    # Timing/routability-driven placement on (platform default = 1)
    export GPL_TIMING_DRIVEN    := 1
    export GPL_ROUTABILITY_DRIVEN := 1
    
    # -------------------------------------------------
    # Strategy blocks
    # -------------------------------------------------
    
    # --- NONE: vanilla flow (use platform defaults everywhere) ---
    ifeq ($(STRATEGY),none)
      # Synthesis
      # (No ABC bias; use SDC). To gently guide ABC anyway, uncomment:
      # export ABC_CLOCK_PERIOD_IN_PS := $(TARGET_CLOCK_PS)
    
      # Placement (let platform defaults choose density)
      # export PLACE_DENSITY := (platform default)
    
      # CTS (use platform lists)
      # export CTS_BUF_LIST :=
      # export CTS_CLUSTER_SIZE :=
      # export CTS_CLUSTER_DIAMETER :=
    endif
    
    # --- AREA: minimize area subject to timing ---
    ifeq ($(STRATEGY),area)
      ##### Synthesis (Yosys/ABC)
      export ABC_AREA := 1
      export ABC_CLOCK_PERIOD_IN_PS := $(TARGET_CLOCK_PS)
    
      ##### Placement
      # Slightly higher density shortens wires (watch congestion)
      export PLACE_DENSITY := 0.58
    
      ##### CTS (keep clock tree modest; uncomment to hard-limit)
      # export CTS_BUF_LIST := "sky130_fd_sc_hd__clkbuf_2 sky130_fd_sc_hd__clkbuf_4 sky130_fd_sc_hd__clkbuf_8"
      # export CTS_CLUSTER_SIZE := 20
      # export CTS_CLUSTER_DIAMETER := 50
    
      ##### Post-CTS / Post-route timing repair
      # Defaults already avoid over-repair; keep margins at 0
    
      ##### Routing
      # Keep defaults unless congestion/DRC appears
      # export ROUTING_LAYER_ADJUSTMENT := 0.50
    endif
    
    # --- DELAY: push frequency (timing-driven everywhere) ---
    ifeq ($(STRATEGY),delay)
      ##### Synthesis
      export ABC_AREA := 0
      export ABC_CLOCK_PERIOD_IN_PS := $(TARGET_CLOCK_PS)
    
      ##### Placement
      # Looser density to relieve routing and allow upsizing/buffers
      export PLACE_DENSITY := 0.55
    
      ##### CTS
      # Let platform choose buffers; optionally widen list for stronger tree
      # export CTS_BUF_LIST := "sky130_fd_sc_hd__clkbuf_2 sky130_fd_sc_hd__clkbuf_4 sky130_fd_sc_hd__clkbuf_8 sky130_fd_sc_hd__clkbuf_16"
      # export CTS_CLUSTER_SIZE := 24
      # export CTS_CLUSTER_DIAMETER := 60
    
      ##### Routing
      # If pushing clocks hard, consider extra iterations (uncomment if needed)
      # export DETAILED_ROUTE_END_ITERATION := 96
    endif
    
    # -------------------------------------------------
    # Optional hooks (provide paths if you need custom passes)
    # -------------------------------------------------
    # Run custom Tcl before global route (e.g., layer adjustments, guides)
    # export PRE_GLOBAL_ROUTE_TCL := $(DESIGN_DIR)/scripts/pre_gr.tcl
    # Run custom Tcl after CTS (e.g., specific buffer constraints)
    # export POST_CTS_TCL := $(DESIGN_DIR)/scripts/post_cts.tcl
    # Provide RC extraction rules file if overriding platform defaults
    # export RCX_RULES := $(DESIGN_DIR)/rcx.rules
    
    # -------------------------------------------------
    # Advanced (leave commented unless you know you need them)
    # -------------------------------------------------
    # Mapping files for special operators
    # export ADDER_MAP_FILE   := $(DESIGN_DIR)/maps/adders.v
    # export CLKGATE_MAP_FILE := $(DESIGN_DIR)/maps/clk_gate.v
    # export LATCH_MAP_FILE   := $(DESIGN_DIR)/maps/latches.v
    # Skip in-flow synthesis and supply tech-mapped netlists
    # export SYNTH_NETLIST_FILES := $(DESIGN_DIR)/out/{args.top}_synth.v
    # IR-drop setup (nets/voltages)
    # export PWR_NETS_VOLTAGES := "VDD:1.80"
    # export GND_NETS_VOLTAGES := "VSS:0.00"
    """
    out = Path(args.outdir + '/config.mk')
    out.write_text(dedent(mk), encoding="utf-8")
    #print(f"Wrote {out.resolve()}")

if __name__ == "__main__":
    raise SystemExit(main())

