# ------------------------------------------------------------------
# Canonical repository roots
# ------------------------------------------------------------------
REPO_ROOT ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../../..)
FLOWROOT ?= $(REPO_ROOT)/flow
FLEXSOCROOT ?= $(REPO_ROOT)/src/flexsoc
TOOLSROOT ?= $(FLEXSOCROOT)/tools
UTILROOT ?= $(REPO_ROOT)/src/util
export PYTHONPATH := $(REPO_ROOT)/src$(if $(PYTHONPATH),:$(PYTHONPATH),)

# Ensure Python can import src/ when invoked via `make -C flow`
# ------------------------------------------------------------------
# Canonical repository roots
# ------------------------------------------------------------------
REPO_ROOT ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../../..)
FLOWROOT ?= $(REPO_ROOT)/flow

UTILROOT ?= $(REPO_ROOT)/src/util
export PYTHONPATH := $(REPO_ROOT)/src$(if $(PYTHONPATH),:$(PYTHONPATH),)

REPO_ROOT := $(abspath ..)
export PYTHONPATH := $(REPO_ROOT)/src$(if $(PYTHONPATH),:$(PYTHONPATH),)

# Single Makefile (merged) — generated from config.mk + mk/*.mk
.DEFAULT_GOAL := help

# Silence make directory enter/leave spam
MAKEFLAGS += --no-print-directory

# ---- config.mk (inlined) ----
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
UTILROOT ?= $(REPO_ROOT)/src/util
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

# ---- mk/help.mk (inlined) ----
# Include configuration

# HELP
help:
	@echo "$(ORANGE)"
	@echo "Available make commands to start:"
	@echo ""
	@echo "    make help_ip     Show IP-related help"
	@echo "    make help_soc    Show SoC-related help"
	@echo "    make help_doc    Show documentation-related help"
	@echo "    make help_fsm    Show FSM generator help"
	@echo "$(RESET)"

help_ip:
	$(Q)$(PYTHON) -m flexsoc.tools.help_ip
help_soc:
	$(Q)$(PYTHON) -m flexsoc.tools.help_soc
help_doc: 
	$(Q)$(PYTHON) -m flexsoc.tools.help_doc
help_fsm:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen help

# ---- mk/setup.mk (inlined) ----
.PHONY: setup setup_tb setup_cocotb setup_model setup_sdc setup_syn setup_signoff setup_pnr

# SETUP FOLDER STRUCTURE
setup:
	@echo "\n$(ORANGE)Setup Folder Structure...\n$(RESET)"
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	$(Q)$(MKDIR) -p \
		$(LOGDIR) \
		$(RTLDIR) \
		$(TBDIR) \
		$(SIMDIR) \
		$(SYNDIR) \
		$(SIGNOFFDIR) \
		$(SIGNOFFDIR)/sdf \
		$(MODELDIR) \
		$(DOCDIR) \
		$(DATADIR) \
		$(DRIVERDIR) \
		$(LINTDIR) \
		$(PYDIR) \
		$(FSMDIR) \
		$(ORSDIR)

# SETUP SV TESTBENCH FILE
# NOTE: keep setup_tb working: same script + args, but ensure dirs exist.
setup_tb: setup flist
	@echo "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR) $(SIMDIR) $(SYNDIR) $(RTLDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_tb $(OVERWRITE) \
		-top $(TOP) \
		-rtldir $(RTLDIR) \
		$(SOC_MEMORY_MAP) \
		-simdir $(SIMDIR) \
		-syndir $(SYNDIR) \
		-prim $(PRIM) \
		-clk $(CLK_PERIOD) \
		-comp $(COMPILER) \
		-itf $(REG_ITF) \
		-vsv $(VSV) \
		-o $(TBDIR)

# SETUP COCOTB
setup_cocotb: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR)/cocotb
	$(Q)$(PYTHON) -m flexsoc.tools.setup_cocotb \
		--top $(TOP) --itf $(REG_ITF) \
		--rtl-dir $(RTLDIR) --output $(TBDIR)/cocotb \
		--clk clk_i --rst rst_ni --rst-active low --period-ns 10 \
		--sim $(COMPILER)

# DEFINE PYTHON MODELDIR
setup_model: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(MODELDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_model -top $(TOP) -o $(MODELDIR)

# SETUP SDC FILE
setup_sdc: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_sdc $(TOP) $(CLK_PERIOD) -o $(ORSDIR)/$(TOP).sdc

# SETUP SYNTHESIS WITH YOSYS
setup_syn: setup_sdc flist
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SYNDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_syn \
		-top $(TOP) -topdir $(RTLDIR) -sdcdir $(ORSDIR) \
		--filelist $(RTLDIR)/rtl_list.f \
		-liberty $(LIB_SYN) -clk $(CLK_PERIOD) \
		-target $(TARGET_SYN) -opt $(TARGET_OPT) \
		-o $(SYNDIR)

# SETUP STA SCRIPT
setup_signoff: setup_sdc syn
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_signoff \
		-top $(TOP) -rtldir $(RTLDIR) \
		-sdcdir $(ORSDIR) -syndir $(SYNDIR) -simdir $(SIMDIR) \
		-libs $(LIBS) -clk $(CLK_PERIOD) -activity $(ACTIVITY) \
		-o $(SIGNOFFDIR)

# ---- mk/ipgen.mk (inlined) ----
# HJSON TEMPLATE GENERATION
hjson: setup
	@echo "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.tools.hjson_gen $(OVERWRITE) -top $(TOP) -itf $(REG_ITF) -o $(DATADIR) 

# SV REGISTER GENERATOR
reg:
	@echo "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)$(UTILROOT)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

# MARKDOWN GENERATOR
.PHONY: doc
doc:
	@echo "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)$(UTILROOT)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)$(UTILROOT)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

# RTL base generator
rtl_stub:
	@echo "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.tools.rtl_stub_gen $(OVERWRITE) -i $(DATADIR)/$(TOP).hjson -itf $(REG_ITF) -o $(RTLDIR)

# Basic IP start flow
ip_start: setup hjson reg doc rtl_stub setup_tb sim

# File list generation
flist:
	$(Q)$(PYTHON) -m flexsoc.tools.gen_filelist --top $(TOP) --out $(RTLDIR)/rtl_list.f --ips-root $(abspath ../hw/ips) --rtldir $(RTLDIR)

# SW DRIVERS
.PHONY: driver
driver:
	$(Q)$(UTILROOT)/regtool.py -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) -m flexsoc.tools.driver_gen -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR)

# Fetch ip from github
fetch:
	$(Q)$(UTILROOT)/vendor.py --update vendor/$(VENDOR).vendor.hjson

# BASIC FLOW:
ip_flow: reg doc lint sim syn sdf sta sta_violators power view
ip_flow_noreg: flist lint sim syn sdf sta sta_violators power view
ip_flow_all: ip_start syn sdf sta sta_violators power view pnr pnr_gui

# ---- mk/lint.mk (inlined) ----
###########
# LINTING #
###########

.PHONY: lint lint_v lint_sv
lint: $(if $(filter v,$(Q)$(VSV)),lint_v,lint_sv)

lint_v: sv2v 
	@echo "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
lint_sv: flist
	@echo "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) -f $(RTLDIR)/rtl_list.f --top-module $(TOP) $(RTLDIR)/$(TOP).sv \
	> $(LOGDIR)/$(TOP)_lint.log 2>&1

# ---- mk/sim.mk (inlined) ----
# -----------------------------------------------------------------------------
# COMPILE / SIMULATE
# -----------------------------------------------------------------------------

.PHONY: compile compile_v compile_sv sim sim_v sim_sv

# VSV selects RTL input type:
#   sv -> use rtl_list.f (SystemVerilog)
#   v  -> use $(RTLDIR)/$(TOP).v (Verilog-only)
VSV ?= sv

compile: $(if $(filter v,$(VSV)),compile_v,compile_sv)
sim:     $(if $(filter v,$(VSV)),sim_v,sim_sv)

# -------------------------
# Verilog-only path (VSV=v)
# -------------------------

compile_v: lint_v
	@echo "\n$(ORANGE)Compiling...\n$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)$(MKDIR) -p $(SIMDIR) $(LOGDIR)
	$(Q)iverilog $(IVERILOG_FLAGS) \
	  -o $(SIMDIR)/$(TESTBENCH).vvp \
	  $(TBDIR)/$(TESTBENCH).sv \
	  > $(LOGDIR)/$(TOP)_compile.log 2>&1
else
	$(Q)$(MKDIR) -p $(SIMDIR)/$(COMPILER) $(LOGDIR)
	$(Q)verilator $(VERILATOR_FLAGS) \
	  $(RTLDIR)/$(TOP).v \
	  $(TBDIR)/$(TESTBENCH).sv \
	  --top-module $(TESTBENCH) \
	  > $(LOGDIR)/$(TOP)_compile.log 2>&1
endif

sim_v: compile_v
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) > $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

# -------------------------
# SystemVerilog path (VSV=sv)
# -------------------------

compile_sv: lint_sv flist
	@echo "\n$(ORANGE)Compiling...\n$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)$(MKDIR) -p $(SIMDIR) $(LOGDIR)
	$(Q)iverilog $(IVERILOG_FLAGS) \
	  -o $(SIMDIR)/$(TESTBENCH).vvp \
	  $(TBDIR)/$(TESTBENCH).sv \
	  > $(LOGDIR)/$(TOP)_compile.log 2>&1
else
	$(Q)$(MKDIR) -p $(SIMDIR)/$(COMPILER) $(LOGDIR)
	$(Q)verilator $(VERILATOR_FLAGS) \
	  -f $(RTLDIR)/rtl_list.f \
	  $(TBDIR)/$(TESTBENCH).sv \
	  --top-module $(TESTBENCH) \
	  > $(LOGDIR)/$(TOP)_compile.log 2>&1
endif

sim_sv: compile_sv
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) > $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

# -----------------------------------------------------------------------------
# POST-SYNTHESIS COMPILE / SIM (iverilog + SDF)
# -----------------------------------------------------------------------------
.PHONY: compile_syn sim_syn

# Expected netlist output from synthesis (adjust if your syn target writes a different name)
SYN_NETLIST ?= $(SYNDIR)/$(TOP)_synth.v

compile_syn: syn
	@echo "\n$(ORANGE)Compiling synthesis...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIMDIR) $(LOGDIR)
	@if [ ! -f "$(SYN_NETLIST)" ]; then \
		echo "ERROR: missing synthesized netlist: $(SYN_NETLIST)"; \
		echo "Hint: check outputs under: $(SYNDIR)"; \
		exit 2; \
	fi
	@if [ ! -f "$(TBDIR)/$(TESTBENCH).sv" ]; then \
		echo "ERROR: missing testbench file: $(TBDIR)/$(TESTBENCH).sv"; \
		echo "Hint: run: make -C flow setup_tb WORKSPACE=... TOP=... RUN_ID=..."; \
		exit 2; \
	fi
	$(Q)iverilog -g2012 -v -gspecify -DSIM -DSYN \
	  -s $(TOP) \
	  $(IVERILOG_FLAGS) \
	  -o $(SIMDIR)/$(TOP)_syn_tb.vvp \
	  $(PRIM) \
	  $(SYN_NETLIST) \
	  $(TBDIR)/$(TESTBENCH).sv \
	  > $(LOGDIR)/$(TOP)_compile_syn.log 2>&1

sim_syn: compile_syn
	@echo "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TOP)_syn_tb.vvp -sdf-verbose \
	  > $(LOGDIR)/$(TOP)_syn_sim.log 2>&1

# -----------------------------------------------------------------------------
# COCOTB
# -----------------------------------------------------------------------------
.PHONY: cocotb
cocotb:
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb

# -----------------------------------------------------------------------------
# VIEW WAVEFORMS
# -----------------------------------------------------------------------------
.PHONY: view view_cocotb view_syn

view:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_tb.vcd $(VIEWER_CONF) &

view_cocotb:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(TBDIR)/cocotb/$(TOP)_tb.vcd $(VIEWER_CONF) &

view_syn:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_syn_tb.vcd $(VIEWER_CONF) &

# -----------------------------------------------------------------------------
# REGRESSION
# -----------------------------------------------------------------------------
.PHONY: regression
regression:
	$(Q)$(MKDIR) -p $(REGRESSIONDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.regression

# ---- mk/syn.mk (inlined) ----
.PHONY: syn syn_v syn_sv
syn: $(if $(filter v,$(VSV)),syn_v,syn_sv)

syn_v: setup_syn
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) $(SYNDIR)/synth.ys > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

syn_sv: setup_syn
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -s $(SYNDIR)/synth_sv.ys \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

yosys-vgen:
	@echo "\n$(ORANGE)Verilog generation with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p " \
	read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul -D SYNTHESIS --ignore-assertions \
	           -f rtl/rtl_list.f \
	           --top $(TOP); \
	opt -keepdc; \
	bwmuxmap; \
	opt_clean; \
	write_verilog -norename -noattr rtl/$(TOP).v" > /dev/null 2>&1

# Use it only if small design
plot_postsyn:
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_postsyn.dot 2>/dev/null &

.PHONY: view_presyn view_presyn_v view_presyn_sv
view_presyn: $(if $(filter v,$(VSV)),view_presyn_v,view_presyn_sv)

view_presyn_v: sv2v
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); \
	show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn' \
	$(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

view_presyn_sv:
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p "\
  read_slang -I ips/pkgs -I ips/prim \
             -I ips/prim_opentitan -I ips/tlul \
             -D SYNTHESIS --ignore-assertions \
             -f rtl/rtl_list.f --top $(TOP) ; \
  prep -top $(TOP); select -clear; select -module $(MODULE) ; \
  show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn" \
	> $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

###          COMPILE & SIMULATE SYNTHESIS       ###

# ---- mk/signoff.mk (inlined) ----
############################################
###        Static Timing Analysis        ###
############################################

sta: setup_signoff 
	@echo "\n$(ORANGE)Static Timing Analysis...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl 2>&1 | tee \
	$(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).warnings || true 
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).errors || true 

# Write SDF
sdf: setup_signoff
	@echo "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/sdf
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl 2>&1 

#####################################
###        Power Analysis        ###
####################################
power: setup_signoff 
	@echo "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl  2>&1 | tee $(LOGDIR)/$(TOP)_power.log 

# STA only violators
sta_violators: setup_signoff 
	@echo "\n$(ORANGE)Static Timing Analysis only timing violators...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta_violators.tcl > $(LOGDIR)/$(TOP)_sta.violators

# Path view of STA timing reports
path_view:
	@echo "\n$(ORANGE)Path view generation of STA report...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/path_view ;
	$(Q)$(PYTHON) $(UTILDIR)/interactiveReport.py -i $(LOGDIR)/$(PATH_VIEW_FILE) \
	-s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)

# ---- mk/pnr.mk (inlined) ----
# -----------------------------------------------------------------------------
# Place & Route (OpenROAD) — workspace-rooted (no writes under flow/)
# -----------------------------------------------------------------------------

.PHONY: setup_pnr pnr pnr_gui

# Absolute paths (critical because we `cd` into a work directory)
OR_WORKDIR  := $(abspath $(OUTROOT))/pnr_openroad
OR_LOGDIR   := $(abspath $(LOGDIR))
OR_CFG_MK   := $(abspath $(ORSDIR))/config.mk
OR_MAKEFILE := $(ORS)/Makefile

setup_pnr:
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_pnr $(TOP) --syn_strategy $(TARGET_OPT) --clk_period $(CLK_PERIOD) \
	  --platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f --outdir $(ORSDIR)

pnr: setup_pnr
	@echo "\n$(ORANGE)Doing Place&Route...\n$(RESET)"
	$(Q)$(MKDIR) -p $(OR_LOGDIR)
	$(Q)$(MKDIR) -p $(OR_WORKDIR)
	@log="$(OR_LOGDIR)/$(TOP)_pnr.log"; \
	cfg="$(OR_CFG_MK)"; \
	if [ ! -f "$$cfg" ]; then \
		echo "ERROR: OpenROAD config.mk not found: $$cfg"; \
		exit 2; \
	fi; \
	cd "$(OR_WORKDIR)" && \
	$(MAKE) --file="$(OR_MAKEFILE)" --no-print-dir \
	  DESIGN_CONFIG="$$cfg" \
	  > "$$log" 2>&1 || { \
		echo "ERROR: OpenROAD PnR failed. See log: $$log"; \
		exit 2; \
	  }

pnr_gui: setup_pnr
	$(Q)$(MKDIR) -p $(OR_WORKDIR)
	@cfg="$(OR_CFG_MK)"; \
	if [ ! -f "$$cfg" ]; then \
		echo "ERROR: OpenROAD config.mk not found: $$cfg"; \
		exit 2; \
	fi; \
	cd "$(OR_WORKDIR)" && \
	$(MAKE) gui_final --file="$(OR_MAKEFILE)" --no-print-dir \
	  DESIGN_CONFIG="$$cfg" 2>/dev/null &

# ---- mk/tb.mk (inlined) ----
# TESTBENCH HANDLING #

tb_save:
	$(Q)$(MKDIR) -p $(REGRESSIONDIR) $(REGRESSIONDIR)/$(TBDIR) $(REGRESSIONDIR)/$(SIMDIR)
	@echo "\n$(ORANGE)Save testbench file...\n$(RESET)"
	$(Q)$(CP) $(TBDIR)/$(TOP)_tb.sv $(REGRESSIONDIR)/$(TBDIR)/$(TOP)_$(OUTNAME)_tb.sv
	$(Q)$(CP) $(SIMDIR)/$(TOP)_tb.vcd $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.vcd
	$(Q)$(CP) $(SIMDIR)/$(TOP)_tb.gtkw $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.gtkw

tb_view:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.vcd \
	$(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.gtkw &

# ---- mk/fsm.mk (inlined) ----
# -----------------------------------------------------------------------------
# FSM FLOW (tools/fsm_gen)
# -----------------------------------------------------------------------------
# fsm_gen tool lives under repo_root/tools
FSMGEN_DIR := $(REPO_ROOT)/tools/fsm_gen

.PHONY: fsm_example_load fsm_setup fsm_gen fsm_plot fsm_flow fsm2rtl fsm_save fsm_load

# Copy example FSM inputs into the tool inputs directory
fsm_example_load:
	$(Q)$(CP) $(FSMGEN_DIR)/examples/* $(FSMGEN_DIR)/inputs/ || true

# Run tool setup (creates venv/dirs inside tool)
fsm_setup:
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) setup

# Generate RTL/TB/etc for selected FSM
fsm_gen: fsm_setup
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) gen PYTHON=$(PYTHON) FSM=$(FSM)

# Plot FSM graph (optional)
fsm_plot: fsm_setup
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) plot PYTHON=$(PYTHON) FSM=$(FSM)

# Full flow
fsm_flow: fsm_gen fsm_plot

# Copy generated artifacts into the current run (workspace-rooted)
fsm2rtl:
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM).sv $(RTLDIR)/
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM)_pkg.sv $(RTLDIR)/
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM).gtkw $(SIMDIR)/ || true
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM)_tb.sv $(TBDIR)/

# Save FSM bundle into the run workspace under fsms/<fsm>/{inputs,outputs}
fsm_save:
	$(Q)$(MKDIR) -p $(FSMDIR)/$(FSM)/inputs $(FSMDIR)/$(FSM)/outputs
	$(Q)$(CP) -r $(FSMGEN_DIR)/inputs/$(FSM)* $(FSMDIR)/$(FSM)/inputs/ || true
	$(Q)$(CP) -r $(FSMGEN_DIR)/outputs/$(FSM)* $(FSMDIR)/$(FSM)/outputs/ || true
	@echo "\n$(ORANGE)$(FSM) FSM saved\n$(RESET)"

# Load FSM bundle from the run workspace into the tool (fsm_gen)
fsm_load: fsm_setup
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/inputs/* $(FSMGEN_DIR)/inputs/ || true
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/outputs/* $(FSMGEN_DIR)/outputs/ || true
	@echo "\n$(ORANGE)$(FSM) FSM loaded into fsm_gen\n$(RESET)"

# ---- mk/fusesoc.mk (inlined) ----
# Defaults (can be overridden by caller)
PRJ    ?= flexsoc
TARGET ?= default

.PHONY: fsoc_init fsoc

# FuseSoC setup:
# Generates:
#   $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/fusesoc/$(TOP).core
fsoc_init:
	@echo "\n$(ORANGE)FuseSOC setup...\n$(RESET)"
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	run_dir="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)"; \
	rtl_dir="$$run_dir/rtl"; \
	lint_dir="$$run_dir/lint"; \
	out_abs="$$run_dir"; \
	mkdir -p "$$out_abs" "$$lint_dir"; \
	out_rel="$$(python3 -c 'import os,sys; print(os.path.relpath(sys.argv[1], sys.argv[2]))' "$$out_abs" "$$(pwd)")"; \
	$(PYTHON) -m flexsoc.tools.setup_fsoc \
		-prj "$(PRJ)" \
		-top "$(TOP)" \
		-rtldir "$$rtl_dir" \
		-lintdir "$$lint_dir" \
		-o "$$out_rel"; \
	test -f "$$out_abs/$(TOP).core" || { \
		echo "ERROR: expected core not generated: $$out_abs/$(TOP).core"; \
		exit 2; \
	}; \
	echo "Generated: $$out_abs/$(TOP).core"

# FuseSoC run (workspace-based cores-root)
fsoc:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	cores_root="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/fusesoc"; \
	$(Q)$(FUSESOC) --cores-root="$$cores_root" run --target "$(TARGET)" "$(PRJ):ip:$(TOP)"

# ---- mk/xbar_soc.mk (inlined) ----
# XBAR
xbar: xbar_init xbar_build

xbar_init:
	@echo "\n$(ORANGE)XBAR init ...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.tools.xbar_init $(SOC_MEMORY_MAP) --host $(HOST) \
	--output $(DATADIR)/xbar_main.hjson

xbar_build:
	@echo "\n$(ORANGE)XBAR build ...\n$(RESET)"
	$(Q)$(UTILROOT)/tlgen.py -t $(DATADIR)/xbar_main.hjson \
	-o $(DATADIR)/autogen 2>/dev/null
	$(Q)$(CP) -r $(DATADIR)/autogen/rtl/autogen/* $(RTLDIR)
	$(Q)$(RM) -r $(RTLDIR)/autogen

###            SoC          ###
soc:
	@echo "\n$(ORANGE)SoC files building ...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.tools.soc_gen -host $(HOST) $(SOC_MEMORY_MAP) -o $(RTLDIR)/soc.sv

soc_flow: xbar soc
	
soc_ibex_fetch:
	@echo "\n$(ORANGE)Fetch lowrisc ips ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	@echo "\n$(ORANGE)Fetch ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex

soc_ibex: setup
	@echo "\n$(ORANGE)SoC files building with IBEX...\n$(RESET)"
	$(Q)$(MAKE) xbar HOST=ibex
	$(Q)$(MAKE) soc HOST=ibex
	$(Q)$(FUSESOC) --cores-root=. run --target=sim --tool=verilator --setup --build enea:soc:main
	$(Q)$(MAKE) soc_run

soc_sim:
	@echo "\n$(ORANGE)SoC simulation with FuseSoC ...\n$(RESET)"
	$(Q)$(FUSESOC) --cores-root=. run --target=sim --tool=verilator --setup --build enea:soc:main

soc_run:
	@echo "\n$(ORANGE)GCC compilaiton of hello_world.c ...\n$(RESET)"
	$(Q)$(MAKE) --no-print-dir -C sw
	@echo "\n$(ORANGE)Verilator run ... Press <CTRL>-C\n$(RESET)"
	build/enea_soc_main_0/sim-verilator/Vtop_verilator -t -E sw/build/main.elf

soc_view:
	@echo "\n$(ORANGE)Viewing ...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) sim.fst $(SIMDIR)/soc_$(TOP)_tb.gtkw&

# ---- mk/tutorials.mk (inlined) ----
# TUTORIALS #
full_tutorial:
	$(Q)$(MAKE) ip_start ip_flow pnr pnr_gui TOP=test

fsm_tutorial: setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl
	$(Q)$(MAKE) ip_flow_noreg TOP=$(FSM)

ip_tutorial:
	$(Q)$(MAKE) ip_load
	@echo "\n$(ORANGE)Run the IP flow ...\n$(RESET)"
	$(Q)$(MAKE) sim syn sdf sta sta_violators power view

# SoC Processor-Less
soc_pless:
	$(Q)$(MAKE) ip_load TOP=tiny-soc
	$(Q)$(MAKE) sim syn sdf sta power view TOP=soc

# SoC with IBEX
soc_ibex_tutorial: soc_ibex_fetch soc_ibex

# ---- mk/save_load.mk (inlined) ----
# Save/Load IP bundles
#
# ip_save copies:
#   $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)  ->  $(IPS_ROOT)/$(TOP)
#
# ip_load restores:
#   $(IPS_ROOT)/$(TOP)  ->  $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)
#
# fsoc_init: FuseSoC-friendly init target (creates run dir skeleton).
#
# Defaults:
#   IPS_ROOT defaults to ../hw/ips relative to flow/

IPS_ROOT ?= $(abspath ../hw/ips)

# Treat any non-empty OVERWRITE as "force overwrite"
ifeq ($(strip $(OVERWRITE)),)
  FLEXSOC_FORCE := 0
else
  FLEXSOC_FORCE := 1
endif

define _require_var
	@if [ -z "$($1)" ]; then \
		echo "ERROR: missing required variable $1"; \
		echo "Hint: pass $1=... or use flexsoc (it sets variables automatically)"; \
		exit 2; \
	fi
endef

.PHONY: ip_save
ip_save:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	src="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)"; \
	dst="$(IPS_ROOT)/$(TOP)"; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source run dir not found: $$src"; \
		exit 2; \
	fi; \
	mkdir -p "$(IPS_ROOT)"; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination already exists: $$dst"; \
		echo "Hint: re-run with --overwrite (sets OVERWRITE)"; \
		exit 2; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "1" ]; then \
		rm -rf "$$dst"; \
	fi; \
	mkdir -p "$$dst"; \
	echo "Saving IP bundle:"; \
	echo "  from: $$src"; \
	echo "  to:   $$dst"; \
	if command -v rsync >/dev/null 2>&1; then \
		rsync -a "$$src"/ "$$dst"/; \
	else \
		cp -a "$$src"/. "$$dst"/; \
	fi

.PHONY: ip_load
ip_load:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	src="$(IPS_ROOT)/$(TOP)"; \
	dst="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)"; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source IP bundle not found: $$src"; \
		exit 2; \
	fi; \
	mkdir -p "$(WORKSPACE)/runs/$(TOP)"; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination run dir already exists: $$dst"; \
		echo "Hint: re-run with --overwrite (sets OVERWRITE)"; \
		exit 2; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "1" ]; then \
		rm -rf "$$dst"; \
	fi; \
	mkdir -p "$$dst"; \
	echo "Loading IP bundle:"; \
	echo "  from: $$src"; \
	echo "  to:   $$dst"; \
	if command -v rsync >/dev/null 2>&1; then \
		rsync -a "$$src"/ "$$dst"/; \
	else \
		cp -a "$$src"/. "$$dst"/; \
	fi

# ---- mk/deps.mk (inlined) ----
# DEPENDENCIES
deps:
	@echo "\n$(ORANGE)Installing dependencies for IP development ...\n$(RESET)"
	sudo apt install -y make python3 python3-pip
	sed -i 's/\r$$//' $(REPO_ROOT)/src/flexsoc/tools/$(TOOLSROOT)/deps.sh
	bash $(REPO_ROOT)/src/flexsoc/tools/$(TOOLSROOT)/deps.sh ip
	pip install -r requirements.txt
	
deps-soc:
	@echo "\n$(ORANGE)Installing dependencies for SoC integration ...\n$(RESET)"
	bash $(REPO_ROOT)/src/flexsoc/tools/$(TOOLSROOT)/deps.sh soc
	echo
	export PATH=$$PATH:/tools/riscv32/bin
	echo "export PATH=/tools/riscv32/bin" >> ~/.bashrc

# ---- mk/clean.mk (inlined) ----
# CLEAN

clean-pyc:
	@find . -type d -name "__pycache__" -prune -exec rm -rf {} +
	@find . -type f -name "*.pyc" -delete
	@find . -type f -name "*.pyo" -delete
	@rm -rf .pytest_cache .ruff_cache

clean_doc:
	$(Q)$(RM) $(DOCDIR)/*
clean_log:
	$(Q)$(RM) $(LOGDIR)/*
clean_rtl:
	$(Q)$(RM) $(RTLDIR)/*.v
clean_sim:
	$(Q)$(RM) $(SIMDIR)/*.vvp
	$(Q)$(RM) $(SIMDIR)/*.vcd
	$(Q)$(RM) $(SIMDIR)/verilator
clean_cocotb:
	$(Q)$(RM) $(TBDIR)/cocotb/*.vcd 
	$(Q)$(RM) $(TBDIR)/cocotb/sim_build
	$(Q)$(RM) $(TBDIR)/cocotb/__py*
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb clean
clean_syn:
	$(Q)$(RM) $(SYNDIR)/*
clean_signoff: 
	$(Q)$(RM) $(SIGNOFFDIR)/sdf/*
	$(Q)$(RM) $(SIGNOFFDIR)/*.sdc
clean_pnr:
	$(Q)$(RM) $(ORSDIR)/*
	$(Q)$(RM) $(ORS_LOGS)
	$(Q)$(RM) $(ORS_REPORTS)
	$(Q)$(RM) $(ORS_RESULTS)
	$(Q)$(RM) $(ORS_OBJECTS)
clean_fsm:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean
clean_fsm_all:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean_all
clean_agent:
	$(Q)$(RM) flexsoc_make_agent/logs
	$(Q)$(RM) flexsoc_make_agent/runs
	$(Q)$(RM) fsm_agent/src/__py*
	$(Q)$(RM) fsm_agent/data/inbox/out*
clean_fsoc:
	$(Q)$(RM) build
clean_soc:
	@echo "\n$(ORANGE)Cleaning SoC ...\n$(RESET)"
	$(Q)$(RM) build trace_core_00000000.log uart0.log  sim.fst*  sw/*.elf sw/*.o sw/*.csv \
		     tb/top_verilator.* soc.core xbar_main.hjson $(TOPDIR)
clean_sw:
	$(Q)$(MAKE) --no-print-dir -C sw clean
clean_vendor:
	$(Q)$(RM) vendor/lowrisc_ip
	$(Q)$(RM) vendor/lowrisc_ibex
	$(Q)$(RM) vendor/lowrisc_ip.lock.hjson
	$(Q)$(RM) vendor/lowrisc_ibex.lock.hjson
clean_subdir:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean
	$(Q)$(MAKE) --no-print-dir -C fsm_gen setup
clean: clean-pyc clean_log clean_rtl clean_sim clean_syn clean_signoff clean_pnr clean_subdir clean_fsoc clean_soc clean_sw clean_fsm
	$(Q)$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec $(RM) -f {} + > /dev/null 2>&1
	$(Q)$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	$(Q)$(CLEAR)
clean_all: clean_fsm_all clean_vendor clean_agent clean 
	$(Q)$(RM) *.core
	$(Q)$(RM) $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) $(ORSDIR) \
	$(MODELDIR) $(DATADIR) $(DOCDIR) $(LINTDIR) $(DRIVERDIR) $(PYDIR) $(FSMDIR) > /dev/null 2>&1

# =============================================================
# BEGIN MERGED INCLUDES (auto-generated)
# =============================================================

# =============================================================
# END MERGED INCLUDES
# =============================================================

