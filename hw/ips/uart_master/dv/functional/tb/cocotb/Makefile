        # Auto-generated Makefile
        SIM               ?= verilator
        TOPLEVEL_LANG     ?= verilog

        PWD               := $(shell pwd)
        COCOTB_TOPLEVEL   = uart_master_tb
        COCOTB_TEST_MODULES = uart_master_tb

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
GLS_NETLIST ?= ../../../../syn/$(PDK)/uart_master_synth.v

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
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_enc.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_enc.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/top_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_mubi_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_secded_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/tlul_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_enc.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_rsp_intg_gen.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_64_57_dec.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_secded_inv_39_32_dec.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_data_integ_dec.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_cmd_intg_chk.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv \
  /home/eneadim/github/flexsoc/hw/ips/tlul/tlul_adapter_reg.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_subreg_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_arb.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_subreg_ext.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_count_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_count.sv \
  /home/eneadim/github/flexsoc/hw/ips/pkgs/prim_util_pkg.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync_cnt.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_fifo_sync.sv \
  /home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_flop_2sync.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_master_reg_pkg.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_master_reg_top.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_tx.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_rx.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_core.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_host_bridge.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_master_core.sv \
  /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl/uart_master.sv

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

        COMPILE_ARGS += -I/tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/rtl -I/home/eneadim/github/flexsoc/hw/ips/pkgs -I/home/eneadim/github/flexsoc/hw/ips/prim -I/home/eneadim/github/flexsoc/hw/ips/prim_opentitan -I/home/eneadim/github/flexsoc/hw/ips/tlul
        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)
        TEST_NAME ?= smoke
        SEED ?= 1
        HDL_COVERAGE ?= 0
        COVERAGE_FILE ?= $(abspath ../../coverage/cocotb/$(TEST_NAME).dat)
        WAVE_FORMAT ?= fst
        WAVE_EXT ?= $(WAVE_FORMAT)
        WAVE_FILE ?= $(abspath ../../sim/rtl/uart_master_tb_cocotb_$(TEST_NAME).$(WAVE_EXT))
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
        VERILOG_SOURCES += /tmp/flexsoc-migrate-uart-master/runs/uart_master/migrate/dv/functional/tb/cocotb/uart_master_tb.sv

        COCOTB_MAKEFILES := $(shell cocotb-config --makefiles 2>/dev/null)
        ifeq ($(strip $(COCOTB_MAKEFILES)),)
        $(error cocotb is not installed in this environment; run: uv sync)
        endif
        include $(COCOTB_MAKEFILES)/Makefile.sim
