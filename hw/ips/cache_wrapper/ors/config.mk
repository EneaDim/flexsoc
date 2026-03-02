export DESIGN_NICKNAME = cache_wrapper
export DESIGN_NAME     = cache_wrapper
export PLATFORM        = sky130hd

# --- filelist (.f) to read at build time ---
FILELIST := rtl/rtl_list.f

# Include dirs from +incdir+ entries
export VERILOG_INCLUDE_DIRS := ips/pkgs

# Source files: ignore blank lines, comments (#) and +incdir lines
export VERILOG_FILES := $(shell awk '!/^\s*($$|#)/ && $$0 !~ /^\+incdir\+/' $(FILELIST))

# HDL frontend and constraints
export SYNTH_HDL_FRONTEND = slang
export SDC_FILE           = ors/cache_wrapper.sdc

# Floorplan / timing targets
export CORE_UTILIZATION      ?= 50
export PLACE_DENSITY_LB_ADDON = 0.20
export TNS_END_PERCENT         = 100
