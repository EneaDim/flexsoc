# =============================================================================
# flexsoc Flow Configuration (workspace-rooted)
# - All artifacts MUST go under: $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/
# - Repo root is discovered from the flow/ directory.
# =============================================================================

# -----------------------------------------------------------------------------
# Roots
# -----------------------------------------------------------------------------
# Repo root (robust when invoked as: make -C flow ...)
REPO_ROOT := $(abspath $(CURDIR)/..)

# Utilities root (if you have flow/util tooling)
UTILROOT  ?= $(CURDIR)/util

# Workspace root (caller may override)
WORKSPACE ?= ../workspace

# Run identity (caller may override; flexsoc will pass RUN_ID)
RUN_ID    ?= $(shell date +%Y%m%d_%H%M%S)

# Place all artifacts under workspace/runs/<top>/<run_id>
OUTROOT   ?= $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)

# Sky130 / PDK inputs (Liberty + primitives)
PDK_ROOT := $(REPO_ROOT)/pdks/sky130

# -----------------------------------------------------------------------------
# Standard output dirs (derived)
# -----------------------------------------------------------------------------
LOGDIR      ?= $(OUTROOT)/logs
RTLDIR      ?= $(OUTROOT)/rtl
TBDIR       ?= $(OUTROOT)/tb
SIMDIR      ?= $(OUTROOT)/sim
SYNDIR      ?= $(OUTROOT)/syn
SIGNOFFDIR  ?= $(OUTROOT)/signoff
MODELDIR    ?= $(OUTROOT)/model
UTILOUT     ?= $(OUTROOT)/util
UTILDIR     ?= $(UTILOUT)          # compat alias
DOCDIR      ?= $(OUTROOT)/doc
DATADIR     ?= $(OUTROOT)/data
DRIVERDIR   ?= $(OUTROOT)/drivers
LINTDIR     ?= $(OUTROOT)/lint
PYDIR       ?= $(OUTROOT)/py
FSMDIR      ?= $(OUTROOT)/fsms
ORSDIR      ?= $(OUTROOT)/openroad

# -----------------------------------------------------------------------------
# Tools
# -----------------------------------------------------------------------------
PYTHON          ?= python3
YOSYS           ?= yosys
STA             ?= sta
VSV             ?= sv
SV2V            ?= sv2v
LINTER          ?= verilator
COMPILER        ?= verilator
FUSESOC         ?= fusesoc

ECHO            ?= echo
MKDIR           ?= mkdir
GREP            ?= grep
CP              ?= cp
RM              ?= rm -rf
FIND            ?= find
CLEAR           ?= clear

MAKEFLAGS       += --no-print-dir

# -----------------------------------------------------------------------------
# Project identifiers
# -----------------------------------------------------------------------------
PRJ             ?= prj
TOP             ?= test
FSM             ?= fsm_example
HOST            ?= uart

# -----------------------------------------------------------------------------
# Vendor / SoC settings
# -----------------------------------------------------------------------------
VENDOR          ?= lowrisc_ip
TARGET_FSOC     ?= lint
REG_ITF         ?= tlul
MOD_ADD         ?= 0x80000000
# -----------------------------------------------------------------------------
# Include dirs (Repo-absolute, cwd-independent)
# -----------------------------------------------------------------------------
# Common include dirs used across tools (OpenTitan-like layout)
INC_PKGS        := $(REPO_ROOT)/hw/ips/pkgs
INC_PRIM        := $(REPO_ROOT)/hw/ips/prim
INC_PRIM_OT     := $(REPO_ROOT)/hw/ips/prim_opentitan
INC_TLUL        := $(REPO_ROOT)/hw/ips/tlul

# OpenROAD/Slang include dirs override (used in pnr.mk)
OR_INC_DIRS     := \
  $(INC_PKGS) \
  $(INC_PRIM_OT) \
  $(INC_PRIM_OT)/rtl \
  $(INC_PRIM_OT)/include

# -----------------------------------------------------------------------------
# Lint / compile flags
# NOTE: keep these as close as possible to original behavior, but make paths
# repo-absolute to avoid cwd issues.
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

# -----------------------------------------------------------------------------
# Simulation
# -----------------------------------------------------------------------------
TESTBENCH       ?= $(TOP)_tb
TESTBENCHES     := $(wildcard $(TBDIR)/*.sv)

# -----------------------------------------------------------------------------
# Waveform viewer
# -----------------------------------------------------------------------------
VIEWER          ?= gtkwave
VIEWER_FLAGS    ?= --dark --rcvar 'fontname_signals Monospace 17' \
                   --rcvar 'fontname_waves Monospace 17' --giga
VIEWER_CONF     ?= $(SIMDIR)/$(TOP)_tb.gtkw

# Liberty files used by STA (multi-corner example)
LIBS ?= \
  $(PDK_ROOT)/lib/sky130_fd_sc_hd__ss_100C_1v40.lib \
  $(PDK_ROOT)/lib/sky130_fd_sc_hd__tt_025C_1v80.lib \
  $(PDK_ROOT)/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib

# Liberty used for synthesis mapping (typical nominal corner)
LIB_SYN ?= $(PDK_ROOT)/lib/sky130_fd_sc_hd__tt_025C_1v80.lib

# Standard-cell primitives / tech verilog (for gate-level sim / iverilog)
PRIM ?= \
  $(PDK_ROOT)/verilog/primitives.v \
  $(PDK_ROOT)/verilog/sky130_fd_sc_hd.no_tc.v


# -----------------------------------------------------------------------------
# Synthesis / sign-off
# -----------------------------------------------------------------------------
CLK_PERIOD      ?= 20
TARGET_SYN      ?= asic
TARGET_OPT      ?= area
ACTIVITY        ?= 10
MODULE          ?= $(TOP)
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
# SoC memory map helpers
# -----------------------------------------------------------------------------
DEVLIST :=
define add_device
DEVLIST += $(1)
BASE_$(1) := $(2)
SIZE_$(1) := $(3)
FROM_LR_$(1) := $(4)
endef

ifeq ($(HOST),ibex)
  $(eval $(call add_device,sram,     0x00100000, 0x00100000, True))
  $(eval $(call add_device,uart,     0x80000000, 0x00001000, False))
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

# -----------------------------------------------------------------------------
# LLM
# -----------------------------------------------------------------------------
OLLAMA_MODEL ?= qwen2.5:3b-instruct

# -----------------------------------------------------------------------------
# Colors
# -----------------------------------------------------------------------------
ORANGE          := \033[38;5;214m
RED             := \033[91m
GREEN           := \033[92m
YELLOW          := \033[93m
BLUE            := \033[94m
RESET           := \033[0m

# -----------------------------------------------------------------------------
# Quiet by default; VERBOSE=1 to see commands
# -----------------------------------------------------------------------------
ifeq ($(VERBOSE),1)
  Q :=
else
  Q := @
endif

# -----------------------------------------------------------------------------
# Overwrite handling (flexsoc uses --overwrite --force)
# -----------------------------------------------------------------------------
ifeq ($(FORCE),1)
  OVERWRITE := --force
else
  OVERWRITE :=
endif
