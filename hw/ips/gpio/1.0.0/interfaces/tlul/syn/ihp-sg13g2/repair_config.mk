# OpenROAD/ORFS floorplan context for post-synthesis electrical repair
# OpenROAD-flow-scripts physical implementation (generated)
export DESIGN_NICKNAME = gpio
export DESIGN_NAME     = gpio
export PLATFORM        = ihp-sg13g2

# FlexSoC owns synthesis and timing intent.
export SYNTH_NETLIST_FILES := /tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/syn/ihp-sg13g2/gpio_synth_raw.v
export SDC_FILE             := /tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/constraints/gpio.sdc

# Platform-owned physical views (LEF/GDS/CDL/LVS decks) stay with ORFS.
# Physical defaults; synthesis strategy does not alter these.
export CORE_UTILIZATION ?= 50
export PLACE_DENSITY ?= 0.58
export PLACE_DENSITY_LB_ADDON = 0.20
export TNS_END_PERCENT = 100

export DETAILED_METRICS := 1
export REPORT_CLOCK_SKEW := 1
export GUI_TIMING := 1
export SETUP_SLACK_MARGIN := 0
export HOLD_SLACK_MARGIN  := 0.10
export CELL_PAD_IN_SITES_GLOBAL_PLACEMENT := 0
export CELL_PAD_IN_SITES_DETAIL_PLACEMENT := 0
export DETAILED_ROUTE_END_ITERATION := 64
export USE_FILL := 0
export GPL_TIMING_DRIVEN := 1
export GPL_ROUTABILITY_DRIVEN := 1
export CTS_CLUSTER_SIZE := 8
