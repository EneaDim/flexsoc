# =========================================
# OpenROAD-flow-scripts — config.mk (generated)
# Absolute paths (cwd-safe)
# =========================================

export DESIGN_NICKNAME = cordic
export DESIGN_NAME     = cordic
export PLATFORM        = sky130hd

# Sources
export VERILOG_INCLUDE_DIRS := /home/eneadim/github/flexsoc/hw/ips/pkgs /home/eneadim/github/flexsoc/hw/ips/prim /home/eneadim/github/flexsoc/hw/ips/prim_opentitan /home/eneadim/github/flexsoc/hw/ips/tlul /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl
export VERILOG_FILES := /home/eneadim/github/flexsoc/hw/ips/pkgs/top_pkg.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_reg_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_mubi_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_secded_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_subreg_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_util_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/tlul_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_assert.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_count_pkg.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_flop_macros.sv /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_alert_pkg.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_bin2gray.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_cdc_2phase.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_div.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_gate.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_counter.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_deglitch.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_edge_detect.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_ff.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_ff_2sync.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_ff_sr.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_fifo.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_gray2bin.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_lifo.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_lzc.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_ram.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_reg.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_rom.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_rrarbiter.sv /home/eneadim/github/flexsoc/hw/ips/prim/prim_shreg.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_alert_sender.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_arbiter_ppc.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_buf.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_cdc_rand_delay.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_count.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_diff_decode.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_async.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_async_simple.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_async_sram_adapter.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync_cnt.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_filter.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_filter_ctr.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop_2sync.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_intr_hw.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_onehot_check.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_pulse_sync.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_reg_cdc.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_reg_cdc_arb.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_reg_we_check.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sec_anchor_buf.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sec_anchor_flop.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_dec.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_enc.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_dec.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_enc.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_arb.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_ext.sv /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sync_reqack.sv /home/eneadim/github/flexsoc/hw/ips/tlul/sram2tlul.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_host.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_reg.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_sram.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_assert.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_assert_multiple.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_cmd_intg_chk.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_cmd_intg_gen.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_dec.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_enc.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err_resp.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_fifo_async.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_fifo_sync.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_rsp_intg_chk.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_rsp_intg_gen.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_socket_1n.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_socket_m1.sv /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_sram_byte.sv /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_lut_pkg.sv /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_reg_pkg.sv /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_reg_top.sv /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_core.sv /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic.sv

# Constraints / Frontend
export SYNTH_HDL_FRONTEND = slang
export SDC_FILE           = /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/pnr_openroad/cordic.sdc

# Strategy / timing knobs
STRATEGY ?= area
TARGET_CLOCK_PS ?= 20000

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
