RUN_TOP ?= $(TOP)

.DEFAULT_GOAL := help
MAKEFLAGS += --no-print-directory
MAKEFLAGS += --no-print-dir

# -----------------------------------------------------------------------------
# Canonical roots
# -----------------------------------------------------------------------------
THIS_MK_DIR  := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
FLOW_DIR     := $(abspath $(THIS_MK_DIR)/..)
REPO_ROOT    ?= $(abspath $(FLOW_DIR)/../../..)
FLEXSOCROOT  ?= $(REPO_ROOT)/src/flexsoc
TOOLSROOT    ?= $(FLEXSOCROOT)/tools
UTILROOT     ?= $(REPO_ROOT)/src/util
FLOWROOT     ?= $(REPO_ROOT)/flow
export PYTHONPATH := $(REPO_ROOT)/src$(if $(PYTHONPATH),:$(PYTHONPATH),)

# -----------------------------------------------------------------------------
# Workspace / run identity
# -----------------------------------------------------------------------------
WORKSPACE   ?= ../workspace
RUN_ID      ?= $(shell date +%Y%m%d_%H%M%S)
OUTROOT     ?= $(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)

# -----------------------------------------------------------------------------
# Derived directories
# -----------------------------------------------------------------------------
LOGDIR         ?= $(OUTROOT)/logs
RTLDIR         ?= $(OUTROOT)/rtl
TBDIR          ?= $(OUTROOT)/tb
SIMDIR         ?= $(OUTROOT)/sim
SYNDIR         ?= $(OUTROOT)/syn
SIGNOFFDIR     ?= $(OUTROOT)/signoff
MODELDIR       ?= $(OUTROOT)/model
UTILOUT        ?= $(OUTROOT)/util
UTILDIR        ?= $(UTILOUT)
DOCDIR         ?= $(OUTROOT)/doc
DATADIR        ?= $(OUTROOT)/data
DRIVERDIR      ?= $(OUTROOT)/drivers
LINTDIR        ?= $(OUTROOT)/lint
PYDIR          ?= $(OUTROOT)/py
FSMDIR         ?= $(OUTROOT)/fsms
ORSDIR         ?= $(OR_WORKDIR)
REGRESSIONDIR  ?= $(OUTROOT)/regression

# -----------------------------------------------------------------------------
# Toolchain
# -----------------------------------------------------------------------------
PYTHON          ?= python3
YOSYS           ?= yosys
STA             ?= sta
SV2V            ?= sv2v
LINTER          ?= verilator
COMPILER        ?= verilator
FUSESOC         ?= fusesoc
VIEWER          ?= gtkwave
VIEWER_FLAGS    ?= --dark --rcvar 'fontname_signals Monospace 17' --rcvar 'fontname_waves Monospace 17' --giga
VIEWER_CONF     ?= $(SIMDIR)/$(TOP)_tb.gtkw

ECHO            ?= echo
MKDIR           ?= mkdir
GREP            ?= grep
CP              ?= cp
RM              ?= rm -rf
FIND            ?= find
CLEAR           ?= clear

# -----------------------------------------------------------------------------
# Project identifiers
# -----------------------------------------------------------------------------
PRJ             ?= prj
TOP             ?= test
FSM             ?= fsm_example
HOST            ?= uart
VENDOR          ?= lowrisc_ip
TARGET_FSOC     ?= lint
TARGET          ?= default
REG_ITF         ?= tlul
MOD_ADD         ?= 0x80000000
MODULE          ?= $(TOP)

# -----------------------------------------------------------------------------
# Include / dependency roots
# -----------------------------------------------------------------------------
PDK_ROOT        ?= $(REPO_ROOT)/pdks/sky130
INC_PKGS        := $(REPO_ROOT)/hw/ips/pkgs
INC_PRIM        := $(REPO_ROOT)/hw/ips/prim
INC_PRIM_OT     := $(REPO_ROOT)/hw/ips/prim_opentitan
INC_TLUL        := $(REPO_ROOT)/hw/ips/tlul
IPS_ROOT        ?= $(REPO_ROOT)/hw/ips
FSMGEN_DIR      := $(REPO_ROOT)/tools/fsm_gen

OR_INC_DIRS     := \
  $(INC_PKGS) \
  $(INC_PRIM_OT) \
  $(INC_PRIM_OT)/rtl \
  $(INC_PRIM_OT)/include

# -----------------------------------------------------------------------------
# Lint / sim flags
# -----------------------------------------------------------------------------
LINT_FLAGS      := --lint-only -Wall -Wno-fatal --timing \
                   +incdir+model \
                   +incdir+$(INC_PKGS) \
                   +incdir+$(INC_PRIM) \
                   +incdir+$(INC_PRIM_OT) \
                   +incdir+$(INC_TLUL)

IVERILOG_FLAGS  := -g2012 -v -I$(INC_PKGS) -I$(INC_PRIM) -I$(RTLDIR) \
                   -I$(TBDIR) -I$(PDK_ROOT)/verilog -I$(SYNDIR)

VERILATOR_FLAGS := -Wall -Wno-fatal --binary --timing --Mdir $(SIMDIR)/$(COMPILER) \
                   --trace \
                   +incdir+$(RTLDIR) +incdir+$(TBDIR) +incdir+$(MODELDIR) \
                   +incdir+$(INC_PRIM) \
                   +incdir+$(INC_PKGS) \
                   +incdir+$(INC_PRIM_OT) \
                   +incdir+$(INC_TLUL)

TESTBENCH       ?= $(TOP)_tb
TESTBENCHES     := $(wildcard $(TBDIR)/*.sv)
VSV             ?= sv
VCD_FILE        ?= $(SIMDIR)/$(TESTBENCH).vcd
VCD_SYN_FILE    ?= $(SIMDIR)/$(TOP)_syn_tb.vcd
SDF_FILE        ?= $(SIGNOFFDIR)/sdf/$(TOP)_ss.sdf

# -----------------------------------------------------------------------------
# Synthesis / signoff
# -----------------------------------------------------------------------------
LIBS ?= \
  $(PDK_ROOT)/lib/sky130_fd_sc_hd__ss_100C_1v40.lib \
  $(PDK_ROOT)/lib/sky130_fd_sc_hd__tt_025C_1v80.lib \
  $(PDK_ROOT)/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib

LIB_SYN ?= $(PDK_ROOT)/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

PRIM ?= \
  $(PDK_ROOT)/verilog/primitives.v \
  $(PDK_ROOT)/verilog/sky130_fd_sc_hd.no_tc.v

CLK_PERIOD      ?= 20
TARGET_SYN      ?= asic
TARGET_OPT      ?= area
ACTIVITY        ?= 10
PATH_VIEW_FILE  ?= $(TOP)_sta.violators
NPATHS          ?= 20

# -----------------------------------------------------------------------------
# OpenROAD
# -----------------------------------------------------------------------------
ORS             ?= ~/openroad/flow
ORS_LOGS        ?= logs
ORS_REPORTS     ?= reports
ORS_RESULTS     ?= results
ORS_OBJECTS     ?= objects
ORS_TECH        ?= sky130hd

# -----------------------------------------------------------------------------
# SoC defaults (overrideable from CLI / make command line)
# -----------------------------------------------------------------------------
DEVLIST :=
define add_device
DEVLIST += $(1)
BASE_$(1) := $(2)
SIZE_$(1) := $(3)
FROM_LR_$(1) := $(4)
endef

SOC_CFG_MK := $(OUTROOT)/soc_config.mk
-include $(SOC_CFG_MK)

.PHONY: soc_cfg
soc_cfg:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(Q)$(MKDIR) -p $(OUTROOT)
	$(Q)$(PYTHON) -m flexsoc.tools.soc_cfg \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--default-host $(HOST) > $(SOC_CFG_MK)

# -----------------------------------------------------------------------------
# Misc
# -----------------------------------------------------------------------------
OLLAMA_MODEL    ?= qwen2.5:3b-instruct
TUTORIAL_WS     ?= $(REPO_ROOT)/workspace
TUTORIAL_RUN_ID ?= dev1

ORANGE          := \033[38;5;214m
RED             := \033[91m
GREEN           := \033[92m
YELLOW          := \033[93m
BLUE            := \033[94m
RESET           := \033[0m

ifeq ($(VERBOSE),1)
  Q :=
else
  Q := @
endif

ifeq ($(FORCE),1)
  OVERWRITE := --force
else
  OVERWRITE :=
endif

ifeq ($(strip $(OVERWRITE)),)
  FLEXSOC_FORCE := 0
else
  FLEXSOC_FORCE := 1
endif

define _require_var
	@if [ -z "$($1)" ]; then \
		echo "ERROR: missing required variable $1"; \
		echo "Hint: pass $1=... or use flexsoc"; \
		exit 2; \
	fi
endef
