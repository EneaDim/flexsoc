# =========================================
# OpenROAD-flow-scripts — config.mk (generated)
# Absolute paths (cwd-safe)
# =========================================

export DESIGN_NICKNAME = uart
export DESIGN_NAME     = uart
export PLATFORM        = sky130hd

# Sources
export VERILOG_INCLUDE_DIRS := /home/eneadim/github/flexsoc/hw/ips/pkgs /home/eneadim/github/flexsoc/hw/ips/prim /home/eneadim/github/flexsoc/hw/ips/prim_opentitan /home/eneadim/github/flexsoc/hw/ips/tlul
export VERILOG_FILES := /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_enc.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_enc.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/top_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_mubi_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_secded_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/tlul_pkg.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_enc.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_rsp_intg_gen.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_dec.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_dec.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_dec.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_cmd_intg_chk.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_reg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_subreg_pkg.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_arb.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_ext.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_count_pkg.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_count.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_util_pkg.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync_cnt.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop_2sync.sv /home/eneadim/github/flexsoc/workspace/runs/uart/dev/rtl/uart_reg_pkg.sv /home/eneadim/github/flexsoc/workspace/runs/uart/dev/rtl/uart_reg_top.sv /home/eneadim/github/flexsoc/workspace/runs/uart/dev/rtl/uart_tx.sv /home/eneadim/github/flexsoc/workspace/runs/uart/dev/rtl/uart_rx.sv /home/eneadim/github/flexsoc/workspace/runs/uart/dev/rtl/uart_core.sv /home/eneadim/github/flexsoc/workspace/runs/uart/dev/rtl/uart.sv

# Constraints / Frontend
export SYNTH_HDL_FRONTEND = slang
export SDC_FILE           = /home/eneadim/github/flexsoc/workspace/runs/uart/dev/signoff/sky130/uart.sdc

# Strategy / timing knobs
STRATEGY ?= area
TARGET_CLOCK_PS ?= 10000

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
