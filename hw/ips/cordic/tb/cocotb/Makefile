        # Auto-generated Makefile
        SIM               ?= verilator
        TOPLEVEL_LANG     ?= verilog

        PWD               := $(shell pwd)
        TOPLEVEL          = cordic_tb
        MODULE            = cordic_tb

        ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
          SIM := icarus
        endif

        ifeq ($(GATES),yes)
          SIM := icarus
        else
          SIM ?= verilator
        endif

        SIM_BUILD         ?= sim_build/rtl

        ifneq ($(GATES),yes)

        # RTL sources expanded from rtl_common.f and rtl_ip.f
VERILOG_SOURCES := \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/top_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_reg_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_mubi_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_secded_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_subreg_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_util_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/tlul_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_assert.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_count_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_flop_macros.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_alert_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_bin2gray.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_cdc_2phase.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_div.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_gate.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_counter.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_deglitch.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_edge_detect.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_ff.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_ff_2sync.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_ff_sr.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_fifo.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_gray2bin.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_lifo.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_lzc.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_ram.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_reg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_rom.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_rrarbiter.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim/prim_shreg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_alert_sender.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_arbiter_ppc.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_buf.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_cdc_rand_delay.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_count.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_diff_decode.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_async.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_async_simple.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_async_sram_adapter.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync_cnt.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_filter.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_filter_ctr.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop_2sync.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_intr_hw.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_onehot_check.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_pulse_sync.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_reg_cdc.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_reg_cdc_arb.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_reg_we_check.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sec_anchor_buf.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sec_anchor_flop.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_dec.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_enc.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_dec.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_enc.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_arb.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_ext.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sync_reqack.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/sram2tlul.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_host.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_reg.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_sram.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_assert.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_assert_multiple.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_cmd_intg_chk.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_cmd_intg_gen.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_dec.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_enc.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err_resp.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_fifo_async.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_fifo_sync.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_rsp_intg_chk.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_rsp_intg_gen.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_socket_1n.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_socket_m1.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_sram_byte.sv \
  /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_lut_pkg.sv \
  /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_reg_pkg.sv \
  /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_reg_top.sv \
  /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_core.sv \
  /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic.sv

        COMPILE_ARGS += --sv --timing
        COMPILE_ARGS += --trace --trace-fst --trace-structs
        export WAVES ?= 1
        COMPILE_ARGS += -Wno-WIDTHEXPAND
        COMPILE_ARGS += -Wno-WIDTHTRUNC
        COMPILE_ARGS += -Wno-UNOPTFLAT

        else
        SIM_BUILD         ?= sim_build/gl
        COMPILE_ARGS      += -DFUNCTIONAL -DUSE_POWER_PINS -DSIM -DUNIT_DELAY=#1
        VERILOG_SOURCES   += ../../verilog/primitives.v
        VERILOG_SOURCES   += ../../verilog/sky130_fd_sc_hd.v
        VERILOG_SOURCES   += ../../syn/cordic_synth.v
        endif

        COMPILE_ARGS += -I/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl -I/home/eneadim/github/flexsoc/hw/ips/pkgs -I/home/eneadim/github/flexsoc/hw/ips/prim -I/home/eneadim/github/flexsoc/hw/ips/prim_opentitan -I/home/eneadim/github/flexsoc/hw/ips/tlul
        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)
        TEST_NAME ?= smoke

        export TEST_NAME
        export REG_CONFIG ?= $(abspath ../tests/$(TEST_NAME)/config.regs)
        export DATA_IN  ?= $(abspath ../tests/$(TEST_NAME)/data_in.vec)
        export DATA_OUT ?= $(abspath ../tests/$(TEST_NAME)/data_out.vec)
        export PYTHONPATH := $(PWD):$(PYTHONPATH)
        VERILOG_SOURCES += /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/tb/cocotb/cordic_tb.sv

        COCOTB_MAKEFILES := $(shell cocotb-config --makefiles 2>/dev/null)
        ifeq ($(strip $(COCOTB_MAKEFILES)),)
        $(error cocotb is not installed in this environment; run: uv sync)
        endif
        include $(COCOTB_MAKEFILES)/Makefile.sim
