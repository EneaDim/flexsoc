MAKEFILE_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT ?= $(abspath $(MAKEFILE_DIR)/../../..)

# FlexSoC backend flow Makefile
#
# This is the canonical Make-backed flow entrypoint used by the Python API.
# Keep commands here explicit so CLI, API, and direct Make users run the same steps.

# -----------------------------------------------------------------------------
# Common configuration
# -----------------------------------------------------------------------------
RUN_TOP ?= $(TOP)

.DEFAULT_GOAL := help
MAKEFLAGS += --no-print-directory
MAKEFLAGS += --no-print-dir

# -----------------------------------------------------------------------------
# Canonical roots
# -----------------------------------------------------------------------------
THIS_MK_DIR  := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
FLOW_DIR     := $(abspath $(THIS_MK_DIR)/..)
REPO_ROOT    ?= $(abspath $(THIS_MK_DIR)/../../..)
FLEXSOCROOT  ?= $(REPO_ROOT)/src/flexsoc
TOOLSROOT    ?= $(FLEXSOCROOT)/backend
UTILROOT     ?= $(REPO_ROOT)/src/util
REGTOOL     ?= $(UTILROOT)/regtool.py
TLGEN       ?= $(UTILROOT)/tlgen.py
VENDOR_TOOL ?= $(UTILROOT)/vendor.py
FLOWROOT     ?= $(REPO_ROOT)/flow
export PYTHONPATH := $(REPO_ROOT)/src$(if $(PYTHONPATH),:$(PYTHONPATH),)

# -----------------------------------------------------------------------------
# Workspace / run identity
# -----------------------------------------------------------------------------
WORKSPACE   ?= ../workspace
RUN_ID ?= default
OUTROOT     ?= $(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)
RUN_DIR     ?= $(OUTROOT)

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
FSMWORKDIR     ?= $(FSMDIR)/$(FSM)
FSM_INPUT_DIR  ?= $(FSMWORKDIR)/inputs
FSM_OUTPUT_DIR ?= $(FSMWORKDIR)/outputs
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
FSMGEN_DIR      := $(FLEXSOCROOT)/backend/fsm_gen

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

FCLK						?= 32
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

SOC_CFG_MODE ?= auto
SOC_CFG_MK := $(OUTROOT)/soc_config.mk
-include $(SOC_CFG_MK)

.PHONY: soc_cfg
soc_cfg:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@echo "[soc_cfg.mk] HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID)"
	$(Q)$(MKDIR) -p $(OUTROOT)
	$(Q)$(PYTHON) -m flexsoc.backend.soc_cfg \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--mode $(SOC_CFG_MODE) \
		--default-host $(HOST) > $(SOC_CFG_MK)

# -----------------------------------------------------------------------------
# Misc
# -----------------------------------------------------------------------------
OLLAMA_MODEL    ?= qwen2.5:3b-instruct
TUTORIAL_WS     ?= $(REPO_ROOT)/workspace
TUTORIAL_RUN_ID ?= dev

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

# -----------------------------------------------------------------------------
# Help and setup targets
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# Help
# -----------------------------------------------------------------------------
.PHONY: help help_ip help_soc help_doc help_fsm

help:
	@echo "$(ORANGE)"
	@echo "FlexSoC help is now CLI-first."
	@echo ""
	@echo "Recommended commands:"
	@echo "  python -m flexsoc.cli"
	@echo "  python -m flexsoc.cli help overview"
	@echo "  python -m flexsoc.cli help topics"
	@echo "  python -m flexsoc.cli actions"
	@echo "  python -m flexsoc.cli make --list"
	@echo "$(RESET)"

help_ip:
	@echo "$(ORANGE)flexsoc IP flow help moved to the CLI.$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.cli ip

help_soc:
	@echo "$(ORANGE)flexsoc SoC/help topics moved to the CLI.$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.cli help topics

help_doc:
	@echo "$(ORANGE)flexsoc documentation/help overview moved to the CLI.$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.cli help overview

help_fsm:
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) help

# -----------------------------------------------------------------------------
# Setup
# -----------------------------------------------------------------------------
.PHONY: setup setup_tb setup_cocotb setup_model setup_sdc setup_syn setup_signoff setup_pnr

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

setup_tb: setup flist
	@echo "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR) $(SIMDIR) $(SYNDIR) $(RTLDIR)
	@if [ "$(TOP)" = "soc" ]; then \
		dev_args="$$( $(PYTHON) -m flexsoc.backend.soc_cfg \
			--workspace $(WORKSPACE) \
			--run-top $(RUN_TOP) \
			--run-id $(RUN_ID) \
			--mode $(SOC_CFG_MODE) \
			--default-host $(HOST) \
			--format args | sed 's/^--host [^ ]* //' )"; \
		$(PYTHON) -m flexsoc.backend.setup_tb $(OVERWRITE) \
			-top $(TOP) \
			-rtldir $(RTLDIR) \
			$$dev_args \
			-simdir $(SIMDIR) \
			-syndir $(SYNDIR) \
			-prim $(PRIM) \
			-clk $(CLK_PERIOD) \
			-comp $(COMPILER) \
			-itf $(REG_ITF) \
			-vsv $(VSV) \
			-o $(TBDIR); \
	else \
		$(PYTHON) -m flexsoc.backend.setup_tb $(OVERWRITE) \
			-top $(TOP) \
			-rtldir $(RTLDIR) \
			-simdir $(SIMDIR) \
			-syndir $(SYNDIR) \
			-prim $(PRIM) \
			-clk $(CLK_PERIOD) \
			-comp $(COMPILER) \
			-itf $(REG_ITF) \
			-vsv $(VSV) \
			-o $(TBDIR); \
	fi

setup_cocotb: setup flist
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR)/cocotb
	$(Q)$(PYTHON) -m flexsoc.backend.setup_cocotb \
		--top $(TOP) --itf $(REG_ITF) \
		--rtl-dir $(RTLDIR) --output $(TBDIR)/cocotb \
		--clk clk_i --rst rst_ni --rst-active low --period-ns 10 \
		--sim $(COMPILER)

setup_model: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(MODELDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_model --top $(TOP) --output-dir $(MODELDIR)

setup_sdc: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_sdc $(TOP) $(CLK_PERIOD) -o $(ORSDIR)/$(TOP).sdc

setup_syn: setup_sdc
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SYNDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_syn \
		-top $(TOP) -topdir $(RTLDIR) -sdcdir $(ORSDIR) \
		--filelist $(RTLDIR)/rtl_list.f \
		-liberty $(LIB_SYN) -clk $(CLK_PERIOD) \
		-target $(TARGET_SYN) -opt $(TARGET_OPT) \
		-o $(SYNDIR)

setup_signoff: setup_sdc syn
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff \
		--top $(TOP) \
		--constraints-dir $(ORSDIR) --synthesis-dir $(SYNDIR) --simulation-dir $(SIMDIR) \
		--liberty $(LIBS) --activity-pct $(ACTIVITY) \
		--output-dir $(SIGNOFFDIR)

setup_pnr:
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_pnr --top $(TOP) \
		--synthesis-strategy $(TARGET_OPT) --clock-period $(CLK_PERIOD) \
		--platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f --output-dir $(ORSDIR)

# -----------------------------------------------------------------------------
# IP development targets
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# IP generation
# -----------------------------------------------------------------------------
.PHONY: hjson hjson_gen reg doc rtl_stub ip_start soc_start flist driver fetch ip_flow ip_flow_noreg ip_flow_all
.PHONY: lint lint_v lint_sv compile compile_v compile_sv sim sim_v sim_sv
.PHONY: compile_syn sim_syn cocotb view view_cocotb view_syn
.PHONY: syn syn_v syn_sv yosys-vgen plot_postsyn view_presyn view_presyn_v view_presyn_sv
.PHONY: sta sdf power sta_violators path_view pnr pnr_gui tb_save tb_view sv2v

hjson: setup
	@echo "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.backend.hjson_gen $(OVERWRITE) --top $(TOP) --interface $(REG_ITF) --output-dir $(DATADIR)

hjson_gen: hjson
	@$(MKDIR) -p $(DATADIR)

reg:
	@$(MKDIR) -p $(RTLDIR)
	@echo "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)$(PYTHON) $(REGTOOL) -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

doc:
	@$(MKDIR) -p $(DOCDIR)
	@echo "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)$(PYTHON) $(REGTOOL) -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) $(REGTOOL) --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

rtl_stub:
	@echo "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.backend.rtl_stub_gen $(OVERWRITE) --hjson-file $(DATADIR)/$(TOP).hjson --interface $(REG_ITF) --output-dir $(RTLDIR)

ip_start: setup hjson reg doc rtl_stub flist setup_tb sim

soc_start: flist
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@echo "\n$(ORANGE)Initializing SoC run from loaded IP bundles...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.backend.soc_start \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID)

flist:
	$(Q)$(PYTHON) -m flexsoc.backend.gen_filelist --top $(TOP) --out $(RTLDIR)/rtl_list.f --ips-root $(IPS_ROOT) --rtldir $(RTLDIR)

driver:
	$(Q)$(PYTHON) $(REGTOOL) -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) -m flexsoc.backend.driver_gen -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR)

fetch:
	$(Q)$(PYTHON) $(VENDOR_TOOL) --update $(REPO_ROOT)/vendor/$(VENDOR).vendor.hjson

ip_flow: reg doc lint sim syn sdf sta sta_violators power view
ip_flow_noreg: flist lint sim syn sdf sta sta_violators power view
ip_flow_all: ip_start syn sdf sta sta_violators power view pnr pnr_gui

# -----------------------------------------------------------------------------
# Lint
# -----------------------------------------------------------------------------
lint: $(if $(filter v,$(VSV)),lint_v,lint_sv)

sv2v: flist
	@echo "\n$(ORANGE)Converting SystemVerilog to Verilog with sv2v...\n$(RESET)"
	$(Q)$(SV2V) $(RTLDIR)/$(TOP).sv > $(RTLDIR)/$(TOP).v

lint_v: sv2v
	@echo "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_lint.log 2>&1

lint_sv: setup flist
	@echo "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) -f $(RTLDIR)/rtl_list.f --top-module $(TOP) $(RTLDIR)/$(TOP).sv \
		> $(LOGDIR)/$(TOP)_lint.log 2>&1

# -----------------------------------------------------------------------------
# Sim
# -----------------------------------------------------------------------------
compile: $(if $(filter v,$(VSV)),compile_v,compile_sv)
sim:     $(if $(filter v,$(VSV)),sim_v,sim_sv)

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
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

compile_sv: lint_sv
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
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

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
		-s $(TESTBENCH) \
		$(IVERILOG_FLAGS) \
		-o $(SIMDIR)/$(TOP)_syn_tb.vvp \
		$(PRIM) \
		$(TBDIR)/$(TESTBENCH).sv \
		> $(LOGDIR)/$(TOP)_compile_syn.log 2>&1

sim_syn: compile_syn
	@echo "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TOP)_syn_tb.vvp -sdf-verbose +VCD=$(VCD_SYN_FILE) +SDF=$(SDF_FILE) \
		> $(LOGDIR)/$(TOP)_syn_sim.log 2>&1

cocotb:
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb

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
# Synthesis
# -----------------------------------------------------------------------------
syn: $(if $(filter v,$(VSV)),syn_v,syn_sv)

syn_v: setup_syn
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) $(SYNDIR)/synth.ys > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

syn_sv: setup_syn
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -s $(SYNDIR)/synth_sv.ys > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

yosys-vgen:
	@echo "\n$(ORANGE)Verilog generation with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p "\
	read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul -D SYNTHESIS --ignore-assertions \
		-f rtl/rtl_list.f \
		--top $(TOP); \
	opt -keepdc; \
	bwmuxmap; \
	opt_clean; \
	write_verilog -norename -noattr rtl/$(TOP).v" > /dev/null 2>&1

plot_postsyn:
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_postsyn.dot 2>/dev/null &

view_presyn: $(if $(filter v,$(VSV)),view_presyn_v,view_presyn_sv)

view_presyn_v: sv2v
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn' \
		$(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

view_presyn_sv:
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p "\
	read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul -D SYNTHESIS --ignore-assertions \
		-f rtl/rtl_list.f --top $(TOP) ; \
	prep -top $(TOP); select -clear; select -module $(MODULE) ; \
	show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn" \
		> $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

# -----------------------------------------------------------------------------
# Signoff
# -----------------------------------------------------------------------------
sta: setup_signoff
	@echo "\n$(ORANGE)Static Timing Analysis...\n$(RESET)"
	$(Q)bash -o pipefail -c '$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl 2>&1 | tee $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log'
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).errors || true

sdf: setup_signoff
	@echo "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/sdf
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl 2>&1

power: setup_signoff
	@echo "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(Q)bash -o pipefail -c '$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl 2>&1 | tee $(LOGDIR)/$(TOP)_power.log'

sta_violators: setup_signoff
	@echo "\n$(ORANGE)Static Timing Analysis only timing violators...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta_violators.tcl > $(LOGDIR)/$(TOP)_sta.violators

path_view:
	@echo "\n$(ORANGE)Path view generation of STA report...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/path_view
	$(Q)$(PYTHON) $(UTILDIR)/interactiveReport.py -i $(LOGDIR)/$(PATH_VIEW_FILE) -s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)

# -----------------------------------------------------------------------------
# Place & Route
# -----------------------------------------------------------------------------
OR_WORKDIR  := $(abspath $(OUTROOT))/pnr_openroad
OR_LOGDIR   := $(abspath $(LOGDIR))
OR_CFG_MK   := $(abspath $(ORSDIR))/config.mk
OR_MAKEFILE := $(ORS)/Makefile

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

# -----------------------------------------------------------------------------
# Testbench save/view
# -----------------------------------------------------------------------------
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
# -----------------------------------------------------------------------------
# IP load / save
# -----------------------------------------------------------------------------

.PHONY: ip_load ip_save

ip_load:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@echo "\n$(ORANGE)Loading IP\n$(RESET)"
	@set -eu; \
	src_ip="$(REPO_ROOT)/hw/ips/$(TOP)"; \
	load_name="$(TOP)"; \
	if [ -n "$${LOAD_AS:-}" ]; then load_name="$$LOAD_AS"; fi; \
	test -d "$$src_ip" || { echo "ERROR: missing source IP directory: $$src_ip"; exit 2; }; \
	echo "TOP=$(TOP)"; \
	echo "RUN_TOP=$(RUN_TOP)"; \
	echo "RUN_ID=$(RUN_ID)"; \
	echo "LOAD_AS=$${LOAD_AS:-}"; \
	echo "Effective load name=$$load_name"; \
	if [ "$(RUN_TOP)" = "$(TOP)" ]; then \
		dst_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
		echo "Mode: standalone"; \
		mkdir -p "$$dst_dir"; \
		for sub in rtl tb data doc drivers py model fsms lint syn signoff pnr_openroad sim ips; do \
			if [ -d "$$src_ip/$$sub" ]; then \
				rm -rf "$$dst_dir/$$sub"; \
				cp -a "$$src_ip/$$sub" "$$dst_dir/$$sub"; \
			fi; \
		done; \
		for f in manifest.json run.yaml report.json *.core; do \
			for x in "$$src_ip"/$$f; do \
				if [ -e "$$x" ]; then cp -a "$$x" "$$dst_dir"/; fi; \
			done; \
		done; \
	else \
		dst_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)/ips/$$load_name"; \
		echo "Mode: integration"; \
		mkdir -p "$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)/ips"; \
		rm -rf "$$dst_dir"; \
		mkdir -p "$$dst_dir"; \
		cp -a "$$src_ip"/. "$$dst_dir"/; \
	fi; \
	echo "Loaded IP from $$src_ip to $$dst_dir"; \
	$(MAKE) flist HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)

ip_save:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@echo "\n$(ORANGE)Saving IP\n$(RESET)"
	@set -eu; \
	src_run="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
	dst_ip="$(REPO_ROOT)/hw/ips/$(TOP)"; \
	test -d "$$src_run" || { echo "ERROR: missing run directory: $$src_run"; exit 2; }; \
	mkdir -p "$$dst_ip"; \
	for sub in rtl tb data doc drivers py model fsms lint syn; do \
		if [ -d "$$src_run/$$sub" ]; then \
			rm -rf "$$dst_ip/$$sub"; \
			cp -a "$$src_run/$$sub" "$$dst_ip/$$sub"; \
		fi; \
	done; \
	if [ -d "$$src_run/signoff" ]; then \
		rm -rf "$$dst_ip/signoff"; \
		mkdir -p "$$dst_ip/signoff"; \
		find "$$src_run/signoff" -mindepth 1 -maxdepth 1 \
			! -name sdf \
			-exec cp -a {} "$$dst_ip/signoff"/ \; ; \
	fi; \
	if [ -d "$$src_run/pnr_openroad" ]; then \
		rm -rf "$$dst_ip/pnr_openroad"; \
		mkdir -p "$$dst_ip/pnr_openroad"; \
		find "$$src_run/pnr_openroad" -maxdepth 1 -type f \
			-exec cp -a {} "$$dst_ip/pnr_openroad"/ \; ; \
	fi; \
	if [ -d "$$src_run/sim" ]; then \
		rm -rf "$$dst_ip/sim"; \
		mkdir -p "$$dst_ip/sim"; \
		find "$$src_run/sim" -maxdepth 1 -type f -name '*.gtkw' \
			-exec cp -a {} "$$dst_ip/sim"/ \; ; \
	fi; \
	for f in manifest.json run.yaml report.json *.core; do \
		for x in "$$src_run"/$$f; do \
			if [ -e "$$x" ]; then cp -a "$$x" "$$dst_ip"/; fi; \
		done; \
	done; \
	echo "Saved IP from $$src_run to $$dst_ip"

# -----------------------------------------------------------------------------
# SoC development targets
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# SoC / FuseSoC flows
# -----------------------------------------------------------------------------
.PHONY: fsoc_init fsoc
.PHONY: xbar xbar_init xbar_build
.PHONY: soc soc_stage_tops soc_flist soc_flow soc_view
.PHONY: soc_uart_gen soc_ibex_gen
.PHONY: soc_sim soc_run sw_soc
.PHONY: soc_uart_tutorial soc_ibex_fetch soc_ibex_tutorial
.PHONY: soc_prepare soc_build_sw soc_run_only
# -----------------------------------------------------------------------------
# User-facing configuration
# -----------------------------------------------------------------------------
PRJ           ?= flexsoc
TARGET        ?= default
TOP           ?= soc
HOST          ?= uart
SOC_CFG_MODE  ?= builtin
FUSESOC_TOOL  ?=
SOC_CORE_VLNV ?= enea:soc:main
# -----------------------------------------------------------------------------
# Run-local FuseSoC layout
# Host-specific to avoid stale UART/IBEX reuse inside the same run.
# -----------------------------------------------------------------------------
FUSESOC_ROOT       ?= $(OUTROOT)/fusesoc/$(HOST)
FUSESOC_CORES_ROOT ?= $(FUSESOC_ROOT)/cores
FUSESOC_BUILD_ROOT ?= $(FUSESOC_ROOT)/build
SOC_SIM_EXE        ?= $(FUSESOC_BUILD_ROOT)/sim-verilator/Vtop_verilator
# -----------------------------------------------------------------------------
# Tutorial defaults
# -----------------------------------------------------------------------------
soc_uart_tutorial: HOST ?= uart
soc_uart_tutorial: RUN_TOP ?= soc_uart
soc_uart_tutorial: RUN_ID ?= dev
soc_uart_tutorial: TOP ?= soc
soc_ibex_fetch: HOST ?= ibex
soc_ibex_fetch: RUN_TOP ?= soc_ibex
soc_ibex_fetch: RUN_ID ?= dev
soc_ibex_fetch: TOP ?= soc
soc_ibex_tutorial: HOST ?= ibex
soc_ibex_tutorial: RUN_TOP ?= soc_ibex
soc_ibex_tutorial: RUN_ID ?= dev
soc_ibex_tutorial: TOP ?= soc
# -----------------------------------------------------------------------------
# Internal guards
# -----------------------------------------------------------------------------
define _require_soc_run_vars
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,TOP)
endef
# -----------------------------------------------------------------------------
# FuseSoC init for run-local SoC core
# -----------------------------------------------------------------------------
fsoc_init:
	@echo "\n$(ORANGE)FuseSoC setup (run-local core generation)...\n$(RESET)"
	$(call _require_soc_run_vars)
	@set -eu; \
	run_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
	rtl_dir="$$run_dir/rtl"; \
	lint_dir="$$run_dir/lint"; \
	cores_dir="$(FUSESOC_CORES_ROOT)"; \
	mkdir -p "$$rtl_dir" "$$lint_dir" "$$cores_dir"; \
	core_out="$$cores_dir"; \
	core_rel="$$(python3 -c 'import os,sys; print(os.path.relpath(sys.argv[1], sys.argv[2]))' "$$core_out" "$$(pwd)")"; \
	$(PYTHON) -m flexsoc.backend.setup_fsoc \
		--project "$(PRJ)" \
		--top "$(TOP)" \
		--rtl-dir "$$rtl_dir" \
		--output-dir "$$core_rel"; \
	test -f "$$core_out/$(TOP).core" || { \
		echo "ERROR: expected core not generated: $$core_out/$(TOP).core"; \
		exit 2; \
	}; \
	echo "Generated: $$core_out/$(TOP).core"; \
	echo "$(HOST)" > "$(FUSESOC_ROOT)/.host"
# -----------------------------------------------------------------------------
# FuseSoC build/run entry
# -----------------------------------------------------------------------------
fsoc:
	$(call _require_soc_run_vars)
	@set -eu; \
	tool_arg=""; \
	mkdir -p "$(FUSESOC_CORES_ROOT)" "$(FUSESOC_BUILD_ROOT)"; \
	if [ -n "$(strip $(FUSESOC_TOOL))" ]; then \
		tool_arg="--tool $(FUSESOC_TOOL)"; \
	fi; \
	cd "$(FUSESOC_ROOT)"; \
	$(FUSESOC) \
		--cores-root="$(REPO_ROOT)" \
		--cores-root="$(FUSESOC_CORES_ROOT)" \
		run \
		--setup \
		--build \
		--target "$(TARGET)" \
		$$tool_arg \
		--build-root "$(FUSESOC_BUILD_ROOT)" \
		"$(SOC_CORE_VLNV)"
# -----------------------------------------------------------------------------
# XBAR generation
# -----------------------------------------------------------------------------
xbar: xbar_init xbar_build
xbar_init: soc_cfg
	@echo "\n$(ORANGE)XBAR init (HOST=$(HOST)) ...\n$(RESET)"
	$(call _require_soc_run_vars)
	$(Q)$(MKDIR) -p $(DATADIR) $(RTLDIR)
	@cfg_args="$$( $(PYTHON) -m flexsoc.backend.soc_cfg \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--mode $(SOC_CFG_MODE) \
		--default-host $(HOST) \
		--format args )"; \
	$(PYTHON) -m flexsoc.backend.xbar_init $$cfg_args --output $(DATADIR)/xbar_main.hjson
xbar_build:
	@echo "\n$(ORANGE)XBAR build ...\n$(RESET)"
	$(call _require_soc_run_vars)
	$(Q)$(MKDIR) -p $(DATADIR)/autogen $(RTLDIR)
	$(Q)$(PYTHON) $(UTILROOT)/tlgen.py -t $(DATADIR)/xbar_main.hjson -o $(DATADIR)/autogen
	@if [ -d "$(DATADIR)/autogen/rtl/autogen" ]; then \
		$(CP) -r $(DATADIR)/autogen/rtl/autogen/* $(RTLDIR)/; \
	elif [ -d "$(DATADIR)/autogen/rtl" ]; then \
		$(CP) -r $(DATADIR)/autogen/rtl/* $(RTLDIR)/; \
	else \
		echo "ERROR: tlgen did not generate rtl output under $(DATADIR)/autogen"; \
		exit 2; \
	fi
	@if [ ! -f "$(RTLDIR)/xbar_main.sv" ]; then \
		echo "ERROR: missing generated $(RTLDIR)/xbar_main.sv"; \
		exit 2; \
	fi
# -----------------------------------------------------------------------------
# Stage loaded IP top modules into SoC RTL dir
#
# Why:
# - soc_gen validates that referenced module wrappers exist.
# - loaded IPs live under $(OUTROOT)/ips/<ip>/rtl/<ip>.sv
# - stage only the top wrapper <ip>.sv into $(RTLDIR)
# -----------------------------------------------------------------------------
soc_stage_tops:
	@echo "\n$(ORANGE)Staging loaded IP top RTL wrappers into run rtl/ ...\n$(RESET)"
	$(call _require_soc_run_vars)
	$(Q)$(MKDIR) -p $(RTLDIR)
	@set -eu; \
	ips_root="$(OUTROOT)/ips"; \
	if [ ! -d "$$ips_root" ]; then \
		echo "INFO: no loaded IPs found under $$ips_root"; \
		exit 0; \
	fi; \
	found_any=0; \
	for ipdir in "$$ips_root"/*; do \
		[ -d "$$ipdir" ] || continue; \
		ipname="$$(basename "$$ipdir")"; \
		src="$$ipdir/rtl/$$ipname.sv"; \
		if [ -f "$$src" ]; then \
			cp -f "$$src" "$(RTLDIR)/"; \
			echo "Staged $$src -> $(RTLDIR)/"; \
			found_any=1; \
		fi; \
	done; \
	if [ "$$found_any" -eq 0 ]; then \
		echo "INFO: no IP top wrappers staged from $$ips_root"; \
	fi
# -----------------------------------------------------------------------------
# SoC RTL generation
# -----------------------------------------------------------------------------
soc: soc_stage_tops
	@echo "\n$(ORANGE)SoC RTL generation (HOST=$(HOST)) ...\n$(RESET)"
	$(call _require_soc_run_vars)
	$(Q)$(MKDIR) -p $(DATADIR) $(RTLDIR) $(TBDIR) $(SIMDIR)
	@cfg_args="$$( $(PYTHON) -m flexsoc.backend.soc_cfg \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--mode $(SOC_CFG_MODE) \
		--default-host $(HOST) \
		--format args )"; \
	$(PYTHON) -m flexsoc.backend.soc_gen $$cfg_args -o $(RTLDIR)/soc.sv
soc_flist:
	@echo "\n$(ORANGE)Generating SoC filelist ...\n$(RESET)"
	$(call _require_soc_run_vars)
	$(Q)$(PYTHON) -m flexsoc.backend.gen_filelist \
		--soc \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--top soc \
		--out $(RTLDIR)/rtl_list.f
soc_flow: xbar soc soc_flist
# -----------------------------------------------------------------------------
# Host-specific wrappers
# -----------------------------------------------------------------------------
soc_uart_gen: HOST := uart
soc_uart_gen: SOC_CFG_MODE := builtin
soc_uart_gen: xbar soc soc_flist
soc_ibex_gen: HOST := ibex
soc_ibex_gen: SOC_CFG_MODE := builtin
soc_ibex_gen: xbar soc soc_flist
# -----------------------------------------------------------------------------
# Software generation
# -----------------------------------------------------------------------------
sw_soc:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,HOST)
	$(Q)$(PYTHON) -m flexsoc.backend.sw_soc_gen \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--host $(HOST)
soc_prepare:
	$(call _require_soc_run_vars)
	@echo "\n$(ORANGE)[soc_prepare] build simulation model (HOST=$(HOST)) ...\n$(RESET)"
	$(Q)$(MKDIR) -p $(OUTROOT)/sim
	$(Q)$(MAKE) soc_sim HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)

soc_build_sw: soc_prepare
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,HOST)
	@echo "\n$(ORANGE)[soc_build_sw] generate software sources ...\n$(RESET)"
	$(Q)$(MAKE) sw_soc WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) HOST=$(HOST)
	@echo "\n$(ORANGE)[soc_build_sw] compile software ...\n$(RESET)"
	$(Q)$(MAKE) --no-print-dir -C $(OUTROOT)/sw
# -----------------------------------------------------------------------------
# Simulation / run
# -----------------------------------------------------------------------------
soc_sim:
	$(call _require_soc_run_vars)
	@echo "\n$(ORANGE)Preparing SoC simulation model (HOST=$(HOST)) ...\n$(RESET)"
	$(Q)$(MAKE) xbar HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
	$(Q)$(MAKE) soc HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
	$(Q)$(MAKE) fsoc_init \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP) \
		PRJ=$(PRJ)
	@echo "\n$(ORANGE)Building SoC simulation model with FuseSoC ...\n$(RESET)"
	$(Q)$(MAKE) fsoc \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP) \
		PRJ=$(PRJ) TARGET=sim FUSESOC_TOOL=verilator SOC_CORE_VLNV="$(SOC_CORE_VLNV)"
soc_run:
	$(call _require_soc_run_vars)
	@echo "\n$(ORANGE)[soc_run] run simulator only (HOST=$(HOST)) ...\n$(RESET)"
	@if [ ! -x "$(SOC_SIM_EXE)" ]; then \
		echo "ERROR: missing simulation model: $(SOC_SIM_EXE)"; \
		echo "Run: make soc_prepare HOST=$(HOST) WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)"; \
		exit 2; \
	fi
	@if [ ! -f "$(OUTROOT)/sw/build/main.elf" ]; then \
		echo "ERROR: missing software ELF: $(OUTROOT)/sw/build/main.elf"; \
		echo "Run: make soc_build_sw HOST=$(HOST) WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID)"; \
		exit 2; \
	fi
	@set -eu; \
	if ! command -v timeout >/dev/null 2>&1; then \
		echo "ERROR: 'timeout' command not found in PATH"; \
		exit 2; \
	fi; \
	rc=0; \
	cd "$(OUTROOT)/sim"; \
	echo "SIM_TIMEOUT=$${SIM_TIMEOUT:-20}s"; \
	timeout --foreground -s INT -k 5s $${SIM_TIMEOUT:-20}s \
		"$(SOC_SIM_EXE)" \
		-t -E ../sw/build/main.elf || rc=$$?; \
	echo "sim rc=$$rc"; \
	if [ "$$rc" -ne 0 ] && [ "$$rc" -ne 124 ] && [ "$$rc" -ne 130 ]; then \
		exit "$$rc"; \
	fi
	$(Q)$(MAKE) soc_view WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) || true
# -----------------------------------------------------------------------------
# Waveform viewer
# -----------------------------------------------------------------------------
soc_view:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	simdir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)/sim"; \
	fst="$$simdir/sim.fst"; \
	gtkw=""; \
	for f in "$$simdir"/*.gtkw; do \
		if [ -f "$$f" ]; then gtkw="$$f"; break; fi; \
	done; \
	test -f "$$fst" || { echo "ERROR: missing waveform: $$fst"; exit 2; }; \
	if command -v gtkwave >/dev/null 2>&1; then \
		if [ -n "$$gtkw" ]; then \
			echo "Opening waveform: $$fst with savefile $$gtkw"; \
			gtkwave $(VIEWER_FLAGS) "$$gtkw" "$$fst" >/dev/null 2>&1 & \
		else \
			echo "Opening waveform: $$fst"; \
			gtkwave $(VIEWER_FLAGS) "$$fst" >/dev/null 2>&1 & \
		fi; \
	else \
		echo "WARNING: gtkwave not found in PATH"; \
		echo "Waveform available at: $$fst"; \
	fi
# -----------------------------------------------------------------------------
# Tutorials
# -----------------------------------------------------------------------------
soc_uart_tutorial:
	@echo "\n$(ORANGE)Loading IPs for UART-host SoC tutorial ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=uart-master LOAD_AS=uart
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=gpio
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=rv_timer
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=pwm
	$(Q)$(MAKE) soc_run HOST=uart SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
soc_ibex_fetch:
	@echo "\n$(ORANGE)Fetch lowRISC IPs ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	@echo "\n$(ORANGE)Fetch Ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex
soc_ibex_tutorial: soc_ibex_fetch
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 1/8: load uart ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=uart
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 2/8: load gpio ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=gpio
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 3/8: load rv_timer ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=rv_timer
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 4/8: load pwm ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=pwm
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 5/8: load spi_host ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=spi_host
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 6/8: generate xbar + soc ...\n$(RESET)"
	$(Q)$(MAKE) xbar soc HOST=ibex SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 7/8: build sim model + software ...\n$(RESET)"
	$(Q)$(MAKE) soc_build_sw HOST=ibex \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID)
	@echo "\n$(ORANGE)[soc_ibex_tutorial] step 8/8: run simulation ...\n$(RESET)"
	$(Q)$(MAKE) soc_run HOST=ibex SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)

# -----------------------------------------------------------------------------
# FSM and clean targets
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# FSM flow
# -----------------------------------------------------------------------------
define _require_fsm
	@if [ -z "$(strip $(FSM))" ]; then \
	  echo "ERROR: FSM is required. Pass it as: -- FSM=<fsm_name>"; \
	  exit 2; \
	fi
endef

.PHONY: fsm_init fsm_example_load fsm_setup fsm_gen fsm_plot fsm_flow
.PHONY: fsm_install
.PHONY: deps deps-soc
.PHONY: clean-pyc clean_doc clean_log clean_rtl clean_sim clean_cocotb clean_syn clean_signoff clean_pnr
.PHONY: clean_fsm clean_fsm_all clean_agent clean_fsoc clean_soc clean_sw clean_vendor clean_subdir clean clean_all
.PHONY: full_tutorial fsm_tutorial ip_tutorial soc_pless

fsm_init:
	$(call _require_fsm)
	$(Q)$(MKDIR) -p "$(FSM_INPUT_DIR)" "$(FSM_OUTPUT_DIR)"

fsm_setup: fsm_init
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) setup

fsm_example_load: fsm_init
	$(call _require_fsm)
	$(Q)$(CP) "$(FSMGEN_DIR)/examples/fsm_example.txt" "$(FSM_INPUT_DIR)/$(FSM).txt"
	$(Q)$(CP) "$(FSMGEN_DIR)/examples/fsm_example.csv" "$(FSM_INPUT_DIR)/$(FSM).csv"
	@echo "\n$(ORANGE)Loaded FSM example into $(FSM_INPUT_DIR) as $(FSM)\n$(RESET)"

fsm_gen: fsm_init
	$(call _require_fsm)
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) gen \
		PYTHON="$(PYTHON)" FSM="$(FSM)" F_CLK="$(or $(strip $(F_CLK)),32)" \
		INPUT_DIR="$(FSM_INPUT_DIR)" OUTPUT_DIR="$(FSM_OUTPUT_DIR)"

fsm_plot: fsm_init
	$(call _require_fsm)
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) plot \
		PYTHON=$(PYTHON) FSM=$(FSM) \
		INPUT_DIR="$(FSM_INPUT_DIR)" OUTPUT_DIR="$(FSM_OUTPUT_DIR)"

fsm_flow: fsm_gen fsm_plot

fsm_install: fsm_init
	$(call _require_fsm)
	$(Q)$(MKDIR) -p "$(RTLDIR)" "$(TBDIR)" "$(SIMDIR)"
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM).sv" "$(RTLDIR)/"
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM)_pkg.sv" "$(RTLDIR)/"
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM).gtkw" "$(SIMDIR)/" || true
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM)_tb.sv" "$(TBDIR)/"
	@echo "\n$(ORANGE)Installed FSM $(FSM) artifacts into IP run directories\n$(RESET)"

# -----------------------------------------------------------------------------
# Dependencies
# -----------------------------------------------------------------------------
deps:
	@echo "\n$(ORANGE)Installing dependencies for IP development ...\n$(RESET)"
	sudo apt install -y make python3 python3-pip
	sed -i 's/\r$$//' $(TOOLSROOT)/deps.sh
	bash $(TOOLSROOT)/deps.sh ip
	pip install -r requirements.txt

deps-soc:
	@echo "\n$(ORANGE)Installing dependencies for SoC integration ...\n$(RESET)"
	bash $(TOOLSROOT)/deps.sh soc
	echo
	export PATH=$$PATH:/tools/riscv32/bin
	printf "%s\n" "export PATH=/tools/riscv32/bin" >> ~/.bashrc

# -----------------------------------------------------------------------------
# Clean
# -----------------------------------------------------------------------------
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
	$(Q)$(RM) -r $(SIMDIR)/verilator

clean_cocotb:
	$(Q)$(RM) $(TBDIR)/cocotb/*.vcd
	$(Q)$(RM) $(TBDIR)/cocotb/sim_build
	$(Q)$(RM) $(TBDIR)/cocotb/__py*
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb clean

clean_syn:
	$(Q)$(RM) -rf $(SYNDIR)/*

clean_signoff:
	$(Q)$(RM) $(SIGNOFFDIR)/sdf/*
	$(Q)$(RM) $(SIGNOFFDIR)/*.sdc

clean_pnr:
	$(Q)$(RM) -rf $(ORSDIR)/*
	$(Q)$(RM) -rf $(ORS_LOGS)
	$(Q)$(RM) -rf $(ORS_REPORTS)
	$(Q)$(RM) -rf $(ORS_RESULTS)
	$(Q)$(RM) -rf $(ORS_OBJECTS)

clean_fsm:
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) clean

clean_fsm_all:
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) clean_all

clean_agent:
	$(Q)$(RM) flexsoc_make_agent/logs
	$(Q)$(RM) flexsoc_make_agent/runs
	$(Q)$(RM) fsm_agent/src/__py*
	$(Q)$(RM) fsm_agent/data/inbox/out*

clean_fsoc:
	$(Q)$(RM) build

clean_soc:
	@echo "\n$(ORANGE)Cleaning SoC ...\n$(RESET)"
	$(Q)$(RM) build trace_core_00000000.log uart0.log sim.fst* sw/*.elf sw/*.o sw/*.csv tb/top_verilator.* soc.core xbar_main.hjson $(TOPDIR)

clean_sw:
	$(Q)$(MAKE) --no-print-dir -C sw clean

clean_vendor:
	$(Q)$(RM) vendor/lowrisc_ip
	$(Q)$(RM) vendor/lowrisc_ibex
	$(Q)$(RM) vendor/lowrisc_ip.lock.hjson
	$(Q)$(RM) vendor/lowrisc_ibex.lock.hjson

clean_subdir:
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) clean
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) setup

clean: clean-pyc clean_log clean_rtl clean_sim clean_syn clean_signoff clean_pnr clean_subdir clean_fsoc clean_soc clean_fsm
	$(Q)$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec $(RM) -f {} + > /dev/null 2>&1
	$(Q)$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	$(Q)$(CLEAR)

clean_all:
	@echo "Cleaning generated FlexSoC outputs..."
	@rm -rf $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)
	@rm -rf $(WORKSPACE)/runs/$(TOP)/default
	@find $(WORKSPACE)/runs/$(TOP) -maxdepth 1 -type d -empty -delete 2>/dev/null || true
	@rm -rf build dist .pytest_cache .mypy_cache .ruff_cache
	@find . -type d -name __pycache__ -prune -exec rm -rf {} + 2>/dev/null || true
	@find . -type f -name '*.pyc' -delete 2>/dev/null || true
	@true
full_tutorial:
	$(Q)$(MAKE) ip_start ip_flow pnr pnr_gui \
		TOP=test RUN_TOP=test \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

fsm_tutorial:
	$(call _require_var,TOP)
	$(Q)$(MAKE) setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(MAKE) ip_flow_noreg \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

ip_tutorial:
	$(call _require_var,TOP)
	$(Q)$(MAKE) ip_load \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	@echo "\n$(ORANGE)Run the IP flow ...\n$(RESET)"
	$(Q)$(MAKE) flist sim syn sdf sta sta_violators power view \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

soc_pless:
	$(Q)$(MAKE) ip_load \
		TOP=tiny-soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(MAKE) flist sim syn sdf sta power view \
		TOP=soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
