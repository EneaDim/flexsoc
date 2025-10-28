# Auto-generated Makefile
# --- Simulator & language ---
SIM               ?= verilator
TOPLEVEL_LANG     ?= verilog

# --- Paths ---
PWD               := $(shell pwd)
ROOT              := $(abspath ../..)
SRC_DIR           := $(PWD)/../../rtl

# --- Top testbench & Python test module ---
TOPLEVEL = soc_tb
MODULE = soc_tb

# Forza Icarus quando il goal è di pulizia (non tocca il workflow)
ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
  SIM := icarus
endif

ifeq ($(GATES),yes)
  SIM := icarus
else
  SIM ?= verilator
endif

# =============================================================================
# RTL SOURCES
# =============================================================================
ifneq ($(GATES),yes)

SIM_BUILD         ?= sim_build/rtl
VERILOG_SOURCES := \
  $(ROOT)/ips/pkgs/top_pkg.sv \
  $(ROOT)/ips/prim/prim_reg_pkg.sv \
  $(ROOT)/ips/pkgs/prim_mubi_pkg.sv \
  $(ROOT)/ips/pkgs/prim_secded_pkg.sv \
  $(ROOT)/ips/pkgs/prim_subreg_pkg.sv \
  $(ROOT)/ips/pkgs/prim_util_pkg.sv \
  $(ROOT)/ips/pkgs/tlul_pkg.sv \
  $(ROOT)/ips/pkgs/prim_assert.sv \
  $(ROOT)/ips/pkgs/prim_count_pkg.sv \
  $(ROOT)/ips/pkgs/prim_flop_macros.sv \
  $(ROOT)/ips/pkgs/prim_alert_pkg.sv \
  $(ROOT)/ips/prim/prim_bin2gray.sv \
  $(ROOT)/ips/prim/prim_cdc_2phase.sv \
  $(ROOT)/ips/prim/prim_clk_div.sv \
  $(ROOT)/ips/prim/prim_clk_gate.sv \
  $(ROOT)/ips/prim/prim_counter.sv \
  $(ROOT)/ips/prim/prim_deglitch.sv \
  $(ROOT)/ips/prim/prim_edge_detect.sv \
  $(ROOT)/ips/prim/prim_ff.sv \
  $(ROOT)/ips/prim/prim_ff_2sync.sv \
  $(ROOT)/ips/prim/prim_fifo.sv \
  $(ROOT)/ips/prim/prim_gray2bin.sv \
  $(ROOT)/ips/prim/prim_lifo.sv \
  $(ROOT)/ips/prim/prim_lzc.sv \
  $(ROOT)/ips/prim/prim_ram.sv \
  $(ROOT)/ips/prim/prim_reg.sv \
  $(ROOT)/ips/prim/prim_rom.sv \
  $(ROOT)/ips/prim/prim_rrarbiter.sv \
  $(ROOT)/ips/prim/prim_shreg.sv \
  $(ROOT)/ips/prim_opentitan/prim_arbiter_ppc.sv \
  $(ROOT)/ips/prim_opentitan/prim_buf.sv \
  $(ROOT)/ips/prim_opentitan/prim_cdc_rand_delay.sv \
  $(ROOT)/ips/prim_opentitan/prim_count.sv \
  $(ROOT)/ips/prim_opentitan/prim_diff_decode.sv \
  $(ROOT)/ips/prim_opentitan/prim_fifo_async.sv \
  $(ROOT)/ips/prim_opentitan/prim_fifo_async_simple.sv \
  $(ROOT)/ips/prim_opentitan/prim_fifo_async_sram_adapter.sv \
  $(ROOT)/ips/prim_opentitan/prim_fifo_sync.sv \
  $(ROOT)/ips/prim_opentitan/prim_fifo_sync_cnt.sv \
  $(ROOT)/ips/prim_opentitan/prim_filter.sv \
  $(ROOT)/ips/prim_opentitan/prim_filter_ctr.sv \
  $(ROOT)/ips/prim_opentitan/prim_flop.sv \
  $(ROOT)/ips/prim_opentitan/prim_flop_2sync.sv \
  $(ROOT)/ips/prim_opentitan/prim_intr_hw.sv \
  $(ROOT)/ips/prim_opentitan/prim_onehot_check.sv \
  $(ROOT)/ips/prim_opentitan/prim_pulse_sync.sv \
  $(ROOT)/ips/prim_opentitan/prim_reg_cdc.sv \
  $(ROOT)/ips/prim_opentitan/prim_reg_cdc_arb.sv \
  $(ROOT)/ips/prim_opentitan/prim_reg_we_check.sv \
  $(ROOT)/ips/prim_opentitan/prim_sec_anchor_buf.sv \
  $(ROOT)/ips/prim_opentitan/prim_sec_anchor_flop.sv \
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_39_32_dec.sv \
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_39_32_enc.sv \
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_64_57_dec.sv \
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_64_57_enc.sv \
  $(ROOT)/ips/prim_opentitan/prim_subreg.sv \
  $(ROOT)/ips/prim_opentitan/prim_subreg_arb.sv \
  $(ROOT)/ips/prim_opentitan/prim_subreg_ext.sv \
  $(ROOT)/ips/prim_opentitan/prim_sync_reqack.sv \
  $(ROOT)/ips/prim_opentitan/prim_alert_sender.sv \
  $(ROOT)/ips/tlul/sram2tlul.sv \
  $(ROOT)/ips/tlul/tlul_adapter_host.sv \
  $(ROOT)/ips/tlul/tlul_adapter_reg.sv \
  $(ROOT)/ips/tlul/tlul_adapter_sram.sv \
  $(ROOT)/ips/tlul/tlul_assert.sv \
  $(ROOT)/ips/tlul/tlul_assert_multiple.sv \
  $(ROOT)/ips/tlul/tlul_cmd_intg_chk.sv \
  $(ROOT)/ips/tlul/tlul_cmd_intg_gen.sv \
  $(ROOT)/ips/tlul/tlul_data_integ_dec.sv \
  $(ROOT)/ips/tlul/tlul_data_integ_enc.sv \
  $(ROOT)/ips/tlul/tlul_err.sv \
  $(ROOT)/ips/tlul/tlul_err_resp.sv \
  $(ROOT)/ips/tlul/tlul_fifo_async.sv \
  $(ROOT)/ips/tlul/tlul_fifo_sync.sv \
  $(ROOT)/ips/tlul/tlul_rsp_intg_chk.sv \
  $(ROOT)/ips/tlul/tlul_rsp_intg_gen.sv \
  $(ROOT)/ips/tlul/tlul_socket_1n.sv \
  $(ROOT)/ips/tlul/tlul_socket_m1.sv \
  $(ROOT)/ips/tlul/tlul_sram_byte.sv \
  $(ROOT)/rtl/gpio_reg_pkg.sv \
  $(ROOT)/rtl/pwm_reg_pkg.sv \
  $(ROOT)/rtl/rv_timer_reg_pkg.sv \
  $(ROOT)/rtl/uart_reg_pkg.sv \
  $(ROOT)/rtl/tl_main_pkg.sv \
  $(ROOT)/rtl/xbar_main.sv \
  $(ROOT)/rtl/uart_tx.sv \
  $(ROOT)/rtl/uart_rx.sv \
  $(ROOT)/rtl/uart_reg_top.sv \
  $(ROOT)/rtl/uart_host_bridge.sv \
  $(ROOT)/rtl/uart_core.sv \
  $(ROOT)/rtl/uart.sv \
  $(ROOT)/rtl/timer_core.sv \
  $(ROOT)/rtl/soc.sv \
  $(ROOT)/rtl/rv_timer_reg_top.sv \
  $(ROOT)/rtl/rv_timer.sv \
  $(ROOT)/rtl/pwm_reg_top.sv \
  $(ROOT)/rtl/pwm_core.sv \
  $(ROOT)/rtl/pwm_chan.sv \
  $(ROOT)/rtl/pwm.sv \
  $(ROOT)/rtl/gpio_reg_top.sv \
  $(ROOT)/rtl/gpio.sv \
  $(ROOT)/tb/cocotb/soc_tb.sv
COMPILE_ARGS += --sv --timing
COMPILE_ARGS += --trace --trace-fst --trace-structs
COMPILE_ARGS += -Wno-WIDTHEXPAND
COMPILE_ARGS += -Wno-WIDTHTRUNC

else
# =============================================================================
# GATE-LEVEL SOURCES
# =============================================================================
SIM_BUILD               = sim_build/gl
COMPILE_ARGS           += -DSIM -DUNIT_DELAY=#1
COMPILE_ARGS           += -gspecify
VERILOG_SOURCES        += ../../verilog/primitives.v
VERILOG_SOURCES        += ../../verilog/sky130_fd_sc_hd.v
VERILOG_SOURCES        += ../../syn/soc_synth.v
VERILOG_SOURCES        += soc_tb.sv

endif

# =============================================================================
# Common compile flags / includes
# =============================================================================
COMPILE_ARGS    += -I$(SRC_DIR) -I$(ROOT)/rtl -I$(ROOT)/ips/pkgs \
									 -I$(ROOT)/ips/prim -I$(ROOT)/ips/prim_opentitan -I$(ROOT)/ips/tlul

# Cocotb: path del report JUnit (usato dalla CI)
export COCOTB_RESULTS_FILE ?= $(abspath results.xml)

# =============================================================================
# Include le regole Cocotb
# =============================================================================
include $(shell cocotb-config --makefiles)/Makefile.sim
