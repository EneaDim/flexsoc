# =========================
# Toolchain / executables
# =========================
PYTHON          ?= python3
YOSYS           := yosys
STA             := sta
VSV             ?= sv
SV2V            := sv2v
LINTER          ?= verilator
COMPILER        ?= verilator
FUSESOC         := fusesoc
ECHO            := echo
MKDIR           := mkdir
GREP            := grep
CP              := cp
RM              := rm -rf
FIND            := find
CLEAR           := clear
MAKEFLAGS       += --no-print-dir
# =========================
# Project identifiers
# =========================
PRJ             ?= prj
TOP             ?= test
FSM             ?= fsm_example
HOST            ?= uart

# =========================
# Directories
# =========================
RTLDIR          ?= rtl
TBDIR           ?= tb
LINTDIR         ?= lint
SIMDIR          ?= sim
SYNDIR          ?= syn
SIGNOFFDIR      ?= signoff
ORSDIR          ?= ors
MODELDIR        ?= model
PYDIR           ?= py
FSMDIR          ?= fsms
LOGDIR          ?= log
DOCDIR          ?= doc
DATADIR         ?= data
DRIVERDIR       ?= driver
VENDORDIR       := vendor
TOPDIR          := top
UTILDIR         := util
SCRIPTSDIR      ?= scripts
REGRESSIONDIR   := $(TBDIR)/regression
OUTNAME         ?= ok

# =========================
# Vendor / SoC settings
# =========================
VENDOR          ?= lowrisc_ip
TARGET_FSOC     ?= lint
REG_ITF         ?= tlul

# =========================
# Lint / compile flags
# =========================
LINT_FLAGS      := --lint-only -Wall -Wno-fatal --timing \
                   +incdir+model +incdir+ips/pkgs +incdir+ips/prim \
                   +incdir+ips/prim_opentitan +incdir+ips/tlul

IVERILOG_FLAGS  := -g2012 -v -Iips/pkgs -Iips/prim -I$(RTLDIR) -I$(TBDIR)
VERILATOR_FLAGS := -Wall -Wno-fatal --binary --timing --Mdir $(SIMDIR)/$(COMPILER) \
                   +incdir+$(RTLDIR) +incdir+$(TBDIR) +incdir+model +incdir+ips/prim \
                   +incdir+ips/pkgs +incdir+ips/prim_opentitan +incdir+ips/tlul

# =========================
# Simulation
# =========================
TESTBENCH       ?= $(TOP)_tb
TESTBENCHES     := $(wildcard $(TBDIR)/*.sv)

# =========================
# Waveform viewer
# =========================
VIEWER          ?= gtkwave
VIEWER_FLAGS    ?= --dark --rcvar 'fontname_signals Monospace 17' \
                   --rcvar 'fontname_waves Monospace 17' --giga
VIEWER_CONF     ?= $(SIMDIR)/$(TOP)_tb.gtkw

# =========================
# Synthesis / sign-off
# =========================
CLK_PERIOD      ?= 20
TARGET_SYN      ?= asic
TARGET_OPT      ?= area
ACTIVITY        ?= 10
MODULE          ?= $(TOP)
PATH_VIEW_FILE  ?= $(TOP)_sta.violators
NPATHS          ?= 20

# Sky130 libs (example)
LIBS            ?= lib/sky130_fd_sc_hd__ss_100C_1v40.lib \
                   lib/sky130_fd_sc_hd__tt_025C_1v80.lib \
                   lib/sky130_fd_sc_hd__ff_n40C_1v95.lib
LIB_SYN         ?= lib/sky130_fd_sc_hd__tt_025C_1v80.lib
PRIM            ?= verilog/primitives.v \
                   verilog/sky130_fd_sc_hd.v

# OpenROAD
ORS             ?= ~/openroad/flow
ORS_LOGS        ?= logs
ORS_REPORTS     ?= reports
ORS_RESULTS     ?= results
ORS_OBJECTS     ?= objects
ORS_TECH        ?= sky130hd

# =========================
# SoC memory map helpers
# =========================
DEVLIST :=
define add_device
DEVLIST += $(1)
BASE_$(1) := $(2)
SIZE_$(1) := $(3)
FROM_LR_$(1) := $(4)
endef

ifeq ($(HOST),ibex)
  $(eval $(call add_device,sram,     0x00100000, 0x00100000, True))
  $(eval $(call add_device,uart,     0x80000000, 0x00001000, True))
  $(eval $(call add_device,pwm,      0x80020000, 0x00001000, False))
  $(eval $(call add_device,gpio,     0x80040000, 0x00001000, False))
  $(eval $(call add_device,rv_timer, 0x80060000, 0x00001000, False))
  $(eval $(call add_device,spi_host, 0x80080000, 0x00001000, False))
else ifeq ($(HOST),uart)
  $(eval $(call add_device,uart,     0x80000000, 0x00001000, False))
  $(eval $(call add_device,pwm,      0x80020000, 0x00001000, False))
  $(eval $(call add_device,gpio,     0x80040000, 0x00001000, False))
  $(eval $(call add_device,rv_timer, 0x80060000, 0x00001000, False))
else
  $(error Unknown HOST '$(HOST)'. Supported: ibex, uart)
endif

SOC_MEMORY_MAP := $(foreach d,$(DEVLIST),--device $(d) $(BASE_$(d)) $(SIZE_$(d)) $(FROM_LR_$(d)))

# =========================
# Colors
# =========================
ORANGE          := \033[38;5;214m
RED             := \033[91m
GREEN           := \033[92m
YELLOW          := \033[93m
BLUE            := \033[94m
RESET           := \033[0m

# Quiet by default; VERBOSE=1 to see commands
ifeq ($(VERBOSE),1)
  Q :=
else
  Q := @
endif

# Overwrite
ifeq ($(FORCE),1)
  OVERWRITE :=--force
else
  OVERWRITE :=
endif
