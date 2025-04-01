# SW
PYTHON          ?=python3
# TOP NAME
PRJ             ?=prj
TOP             ?=fsm_example
# DIRECTORIES
RTLDIR          ?=rtl
TBDIR           ?=tb
SIMDIR          ?=sim
SYNDIR          ?=syn
SIGNOFFDIR      ?=signoff
MODELDIR        ?=model
LOGDIR          ?=log
DOCDIR          ?=doc
DATADIR         ?=data
UTILDIR         :=util
SCRIPTSDIR      :=scripts
REGRESSIONDIR   :=$(TBDIR)/regression \
                  $(SIMDIR)/regression \
                  $(LOGDIR)/regression
# COMPILE TOOL
SV2V            :=sv2v
LINTER          ?=verilator
COMPILER        ?=iverilog
# LINT FLAGS
LINT_FLAGS      := --lint-only -Wall -Wno-fatal
LINT_FILES      ?=
# COMPILE FLAG
IVERILOG_FLAGS  := -g2012 -v
VERILATOR_FLAGS := -Wall -Wno-fatal --binary --timing \
                   --Mdir $(SIMDIR)/$(COMPILER)
# SIMULATION
TESTBENCH       ?= $(TOP)_tb
TESTBENCHES     := $(wildcard $(TBDIR)/*.sv)
# WAVEFORM VIEWER 
VIEWER          ?=gtkwave
VIEWER_FLAGS    ?=--dark --rcvar 'fontname_signals Monospace 17' \
                  --rcvar 'fontname_waves Monospace 17' 
VIEWER_CONF     ?=$(SIMDIR)/$(TESTBENCH).gtkw
# SYNTHESIS AND SIGN-OFF
YOSYS           :=yosys
STA             :=sta
CLK_PERIOD      ?=10
TARGET          ?=asic
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
