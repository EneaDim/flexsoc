        # Auto-generated Makefile
        SIM               ?= verilator
        TOPLEVEL_LANG     ?= verilog

        PWD               := $(shell pwd)
        COCOTB_TOPLEVEL   = cordic_tb
        COCOTB_TEST_MODULES = cordic_tb

        ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
          SIM := icarus
        endif

        ifeq ($(GATES),yes)
        SIM := icarus
SIM_BUILD ?= sim_build/gls
TIMING_MODE ?= zero
GLS_UNIT_DELAY_DEFINE ?= 1
GLS_INTERCONNECT ?= 0
SDF_FILE ?=
GLS_MODELS ?=
GLS_NETLIST ?= ../../../../syn/$(PDK)/cordic_synth.v

VERILOG_SOURCES += $(GLS_MODELS)
VERILOG_SOURCES += $(GLS_NETLIST)
COMPILE_ARGS += -g2012 -DSIM -DSYN -DFLEXSOC_GLS_EXTERNAL_MODELS -DFLEXSOC_COCOTB_WAVE_OWNER

ifeq ($(TIMING_MODE),zero)
COMPILE_ARGS += -DFUNCTIONAL -DUNIT_DELAY=\#0 -gno-specify
else ifeq ($(TIMING_MODE),unit)
COMPILE_ARGS += -DFUNCTIONAL -gno-specify -DUNIT_DELAY=\#$(GLS_UNIT_DELAY_DEFINE)
else ifneq ($(filter $(TIMING_MODE),min typ max),)
ifeq ($(strip $(SDF_FILE)),)
$(error SDF_FILE is required when TIMING_MODE=$(TIMING_MODE))
endif
COMPILE_ARGS += -gspecify -T$(TIMING_MODE) -DFLEXSOC_ENABLE_SDF
ifeq ($(GLS_INTERCONNECT),1)
COMPILE_ARGS += -ginterconnect
endif
ifeq ($(TIMING_MODE),min)
COMPILE_ARGS += -DFLEXSOC_SDF_MIN
else ifeq ($(TIMING_MODE),typ)
COMPILE_ARGS += -DFLEXSOC_SDF_TYP
else
COMPILE_ARGS += -DFLEXSOC_SDF_MAX
endif
COCOTB_PLUSARGS += +SDF=$(abspath $(SDF_FILE))
else
$(error TIMING_MODE must be zero, unit, min, typ, or max)
endif

        else
        SIM_BUILD ?= sim_build/rtl

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
  /tmp/flexsoc-reference-cordic/runs/cordic/reference/rtl/cordic_lut_pkg.sv \
  /tmp/flexsoc-reference-cordic/runs/cordic/reference/rtl/cordic_reg_pkg.sv \
  /tmp/flexsoc-reference-cordic/runs/cordic/reference/rtl/cordic_reg_top.sv \
  /tmp/flexsoc-reference-cordic/runs/cordic/reference/rtl/cordic_core.sv \
  /tmp/flexsoc-reference-cordic/runs/cordic/reference/rtl/cordic.sv

        COMPILE_ARGS += --sv --timing
        WAVE_FORMAT ?= fst
        ifeq ($(WAVE_FORMAT),vcd)
        COMPILE_ARGS += --trace-vcd --trace-structs
        else
        COMPILE_ARGS += --trace-fst --trace-structs
        export IVERILOG_DUMPER := fst
        endif
        export WAVES ?= 1
        COMPILE_ARGS += -Wno-WIDTHEXPAND
        COMPILE_ARGS += -Wno-WIDTHTRUNC
        COMPILE_ARGS += -Wno-UNOPTFLAT
        endif

        COMPILE_ARGS += -I/tmp/flexsoc-reference-cordic/runs/cordic/reference/rtl -I/home/eneadim/github/flexsoc/hw/ips/pkgs -I/home/eneadim/github/flexsoc/hw/ips/prim -I/home/eneadim/github/flexsoc/hw/ips/prim_opentitan -I/home/eneadim/github/flexsoc/hw/ips/tlul
        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)
        TEST_NAME ?= smoke
        SEED ?= 1
        HDL_COVERAGE ?= 0
        COVERAGE_FILE ?= $(abspath ../../coverage/cocotb/$(TEST_NAME).dat)
        WAVE_FORMAT ?= fst
        WAVE_EXT ?= $(WAVE_FORMAT)
        WAVE_FILE ?= $(abspath ../../sim/rtl/cordic_tb_cocotb_$(TEST_NAME).$(WAVE_EXT))
        COCOTB_PLUSARGS += +WAVE=$(WAVE_FILE)
        ifeq ($(GATES),yes)
        COCOTB_PLUSARGS += +dumpfile_path=$(WAVE_FILE)
        endif

        override COVERAGE :=
        unexport COVERAGE

        ifeq ($(SIM),verilator)
        COCOTB_PLUSARGS += +verilator+seed+$(SEED)
        ifeq ($(HDL_COVERAGE),1)
        COMPILE_ARGS += --coverage-line --coverage-toggle --coverage-expr --coverage-fsm --coverage-user
        COCOTB_PLUSARGS += +verilator+coverage+file+$(COVERAGE_FILE)
        endif
        endif

        export TEST_NAME
        export FLEXSOC_SEED := $(SEED)
        export COCOTB_RANDOM_SEED := $(SEED)
        export TEST_ROOT ?= $(abspath ../../tests)
        export REG_CONFIG ?= $(TEST_ROOT)/$(TEST_NAME)/config.regs
        export CFG ?= $(REG_CONFIG)
        export DATA_IN  ?= $(TEST_ROOT)/$(TEST_NAME)/data_in.vec
        export DATA_OUT ?= $(TEST_ROOT)/$(TEST_NAME)/data_out.vec
        export PYTHONPATH := $(PWD):$(PYTHONPATH)
        VERILOG_SOURCES += /tmp/flexsoc-reference-cordic/runs/cordic/reference/dv/functional/tb/cocotb/cordic_tb.sv

        COCOTB_MAKEFILES := $(shell cocotb-config --makefiles 2>/dev/null)
        ifeq ($(strip $(COCOTB_MAKEFILES)),)
        $(error cocotb is not installed in this environment; run: uv sync)
        endif
        include $(COCOTB_MAKEFILES)/Makefile.sim
