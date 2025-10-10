# SW
PYTHON          ?=python3
# TOP NAME
PRJ             ?=prj
TOP             ?=spi_host
FSM             ?=fsm_example
# DIRECTORIES
RTLDIR          ?=rtl
TBDIR           ?=tb
LINTDIR         ?=lint
SIMDIR          ?=sim
SYNDIR          ?=syn
SIGNOFFDIR      ?=signoff
ORSDIR					?=ors
MODELDIR        ?=model
PYDIR           ?=py
FSMDIR          ?=fsms
LOGDIR          ?=log
DOCDIR          ?=doc
DATADIR         ?=data
DRIVERDIR       ?=driver
VENDORDIR       :=vendor
TOPDIR          :=top
UTILDIR         :=util
SCRIPTSDIR      :=scripts
REGRESSIONDIR   :=$(TBDIR)/regression \
                  $(SIMDIR)/regression \
                  $(LOGDIR)/regression
# VENDOR
VENDOR          ?=lowrisc_ip
# FUSESOC
TARGET_FSOC     ?=lint
# REGISTER INTERFACE
REG_ITF         ?=tlul
# COMPILE TOOL
VSV             ?=sv
SV2V            :=sv2v
LINTER          ?=verilator
COMPILER        ?=verilator
# LINT FLAGS
LINT_FLAGS      := --lint-only -Wall -Wno-fatal --timing \
									 +incdir+model +incdir+ips/pkgs +incdir+ips/prim \
									 +incdir+ips/prim_opentitan +incdir+ips/tlul \
# COMPILE FLAG
IVERILOG_FLAGS  := -g2012 -v -Iips/pkgs -Iips/prim -I$(RTLDIR) -I$(TBDIR)
VERILATOR_FLAGS := -Wall -Wno-fatal --binary --timing --Mdir $(SIMDIR)/$(COMPILER) \
                   +incdir+$(RTLDIR) +incdir+$(TBDIR) +incdir+model +incdir+ips/prim \
									 +incdir+ips/pkgs +incdir+ips/prim_opentitan +incdir+ips/tlul \
# SIMULATION
TESTBENCH       ?= $(TOP)_tb
TESTBENCHES     := $(wildcard $(TBDIR)/*.sv)
# WAVEFORM VIEWER 
VIEWER          ?=gtkwave
VIEWER_FLAGS    ?=--dark --rcvar 'fontname_signals Monospace 17' \
                  --rcvar 'fontname_waves Monospace 17' \
									--giga
VIEWER_CONF     ?=$(SIMDIR)/$(TOP)_tb.gtkw
# SYNTHESIS AND SIGN-OFF
YOSYS           :=yosys
STA             :=sta
CLK_PERIOD      ?=10
TARGET_SYN      ?=asic
TARGET_OPT      ?=none
ACTIVITY        ?=10
MODULE          ?=$(TOP)
PATH_VIEW_FILE  ?=$(TOP)_sta.violators
NPATHS          ?=20
# SKY130 LIBS
LIBS            ?=lib/sky130_fd_sc_hd__ss_100C_1v40.lib \
                  lib/sky130_fd_sc_hd__tt_025C_1v80.lib \
                  lib/sky130_fd_sc_hd__ff_n40C_1v95.lib
LIB_SYN         ?=lib/sky130_fd_sc_hd__tt_025C_1v80.lib
PRIM            ?=verilog/primitives.v \
                  verilog/sky130_fd_sc_hd.v
# OPENROAD
ORS             ?=~/openroad/flow
ORS_LOGS        ?=logs
ORS_REPORTS			?=reports
ORS_RESULTS			?=results
ORS_OBJECTS     ?=objects
ORS_TECH        ?=sky130hd

# SoC MEMORY MAP
DEVLIST :=
define add_device
DEVLIST += $(1)
BASE_$(1) := $(2)
SIZE_$(1) := $(3)
endef

HOST            ?= uart

# Needed for the .c driver definition
MOD_ADD  ?= 0x80040000

IPS             :=
LOWRISC_IPS     ?=

ifeq ($(HOST),ibex)
  LOWRISC_IPS += uart pwm
  $(eval $(call add_device,sram,     0x00100000, 0x00100000))
  $(eval $(call add_device,uart,     0x80000000, 0x00001000))
  $(eval $(call add_device,pwm,      0x80020000, 0x00001000))
  $(eval $(call add_device,spi_host, $(MOD_ADD), 0x00001000))

else ifeq ($(HOST),uart)
  LOWRISC_IPS += 
  $(eval $(call add_device,uart,     0x80000000, 0x00001000))
  $(eval $(call add_device,pwm,      0x80020000, 0x00001000))
  $(eval $(call add_device,spi_host, $(MOD_ADD), 0x00001000))
  $(eval $(call add_device,gpio,     0x80060000, 0x00001000))
  $(eval $(call add_device,rv_timer, 0x80080000, 0x00001000))

else
  $(error Unknown HOST '$(HOST)'. Supported: ibex, uart)
endif

## Compose flags
SOC_MEMORY_MAP := $(foreach d,$(DEVLIST),--device $(d) $(BASE_$(d)) $(SIZE_$(d)))

# Shell functions
ECHO            :=echo
MKDIR           :=mkdir
GREP            :=grep
CP              :=cp
RM              :=rm -rf
FIND            :=find
CLEAR           :=clear
FUSESOC         :=fusesoc

# Define color codes
ORANGE          :=\033[38;5;214m
RED             :=\033[91m
GREEN           :=\033[92m
YELLOW          :=\033[93m
BLUE            :=\033[94m
RESET           :=\033[0m
