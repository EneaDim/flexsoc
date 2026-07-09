# FlexSoC backend flow Makefile
#
# Canonical Make-backed flow entrypoint used by the Python API, CLI wrappers,
# and direct Make users.
#
# Reordered by flow phase:
#   1. global configuration and helper macros
#   2. help and setup/init
#   3. IP metadata, RTL/stub/filelist generation
#   4. linting
#   5. testbench/model setup and simulation
#   6. waveform/netlist viewing and regression artifacts
#   7. synthesis
#   8. signoff: SDF, STA, power, path analysis
#   9. OpenROAD place & route
#  10. IP load/save
#  11. SoC/FuseSoC/XBAR/software flow
#  12. FSM flow
#  13. tutorials, dependencies, cleanup
#
# Notes:
# - Target-specific variables are kept close to their targets.
# - Late ?= defaults from the original SoC section are preserved; they only
#   apply when the variable was not set earlier by the command line/environment.
# - Legacy phony-only targets are made explicit where useful.

# ============================================================================
# 1. Global configuration
# ============================================================================
MAKEFILE_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT ?= $(abspath $(MAKEFILE_DIR)/../../..)


# -----------------------------------------------------------------------------
# Common configuration
# -----------------------------------------------------------------------------
RUN_TOP ?= $(TOP)

.DEFAULT_GOAL := help
MAKEFLAGS += --no-print-directory
MAKEFLAGS += --no-print-dir
MAKE_DRY_RUN := $(filter n,$(MAKEFLAGS))$(findstring --just-print,$(MAKEFLAGS))$(findstring --dry-run,$(MAKEFLAGS))$(findstring --recon,$(MAKEFLAGS))

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
BACKEND_MAKEFILE ?= $(abspath $(lastword $(MAKEFILE_LIST)))
RUN_ID ?= default
# BEGIN FLEXSOC_PORTABLE_VIEWER
# Waveform viewer settings. Use SURFER_BACKEND=auto|native|x11|wayland.
WAVE_VIEWER ?= surfer
SURFER ?= surfer
GTKWAVE ?= gtkwave
SURFER_BACKEND ?= auto
WSL_DETECTED := $(shell grep -qiE 'microsoft|wsl' /proc/version 2>/dev/null && echo 1 || echo 0)
ifeq ($(SURFER_BACKEND),x11)
SURFER_ENV ?= env -u WAYLAND_DISPLAY WINIT_UNIX_BACKEND=x11
else ifeq ($(SURFER_BACKEND),wayland)
SURFER_ENV ?= env WINIT_UNIX_BACKEND=wayland
else ifeq ($(SURFER_BACKEND),native)
SURFER_ENV ?= env
else ifeq ($(WSL_DETECTED),1)
SURFER_ENV ?= env -u WAYLAND_DISPLAY WINIT_UNIX_BACKEND=x11
else
SURFER_ENV ?= env
endif
# END FLEXSOC_PORTABLE_VIEWER

# Waveform viewer defaults. Override with WAVE_VIEWER=gtkwave or SURFER=/path/to/surfer.
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

# OpenROAD run-local layout
OR_WORKDIR  := $(abspath $(OUTROOT))/pnr_openroad
OR_LOGDIR   := $(abspath $(LOGDIR))
OR_CFG_MK   := $(abspath $(ORSDIR))/config.mk
OR_MAKEFILE := $(ORS)/Makefile


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

# Internal run guards
define _require_soc_run_vars
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,TOP)
endef

define _require_fsm
	@if [ -z "$(strip $(FSM))" ]; then \
	  echo "ERROR: FSM is required. Pass it as: -- FSM=<fsm_name>"; \
	  exit 2; \
	fi
endef

# Consolidated phony declarations, grouped in file order.
PHONY_TARGETS :=
PHONY_TARGETS += help help_ip help_soc help_doc help_fsm
PHONY_TARGETS += setup soc_cfg soc_start
PHONY_TARGETS += hjson hjson_gen reg doc rtl_stub flist flist_split driver fetch
PHONY_TARGETS += ip_start ip_flow ip_flow_noreg ip_flow_all
PHONY_TARGETS += lint lint_v lint_sv lint_latch lint_undriven lint_width lint_unconnected lint_unused _lint_run slang_hier
PHONY_TARGETS += setup_tb setup_cocotb setup_model compile compile_v compile_sv sim sim_v sim_sv cocotb
PHONY_TARGETS += view view_cocotb view_syn plot_postsyn view_presyn view_presyn_v view_presyn_sv tb_save tb_view
PHONY_TARGETS += setup_sdc setup_syn syn syn_v syn_sv yosys-vgen sv2v
PHONY_TARGETS += setup_signoff compile_syn sim_syn sta sdf power sta_violators path_view
PHONY_TARGETS += setup_pnr pnr pnr_gui
PHONY_TARGETS += ip_load ip_save
PHONY_TARGETS += fsoc_init fsoc xbar xbar_init xbar_build soc soc_stage_tops soc_flist soc_flow soc_uart_gen soc_ibex_gen
PHONY_TARGETS += sw_soc soc_prepare soc_build_sw soc_sim soc_run soc_run_only soc_view
PHONY_TARGETS += fsm_init fsm_setup fsm_example_load fsm_gen fsm_plot fsm_flow fsm_install fsm2rtl
PHONY_TARGETS += soc_uart_tutorial soc_ibex_fetch soc_ibex_tutorial full_tutorial fsm_tutorial ip_tutorial soc_pless
PHONY_TARGETS += deps deps-soc
PHONY_TARGETS += clean-pyc clean_doc clean_log clean_rtl clean_sim clean_cocotb clean_syn clean_signoff clean_pnr
PHONY_TARGETS += clean_fsm clean_fsm_all clean_agent clean_fsoc clean_soc clean_sw clean_vendor clean_subdir clean clean_all

.PHONY: $(PHONY_TARGETS)

# ============================================================================
# 2. Help
# ============================================================================
##@ Help
help: ## Show backend target help
	@awk 'BEGIN {FS = ":.*##"; printf "\nFlexSoC backend targets\n"} \
		/^##@/ {printf "\n%s\n", substr($$0, 5); next} \
		/^[A-Za-z0-9_.%-]+:.*##/ {gsub(/^ +/, "", $$2); printf "  %-20s %s\n", $$1, $$2} \
		END {printf "\nTip: prefer the CLI for day-to-day use, e.g. fx setup hjson reg --dry-run --script\n\n"}' $(lastword $(MAKEFILE_LIST))

help_ip: help ## Show IP-flow help
help_soc: help ## Show SoC-flow help
help_doc: help ## Show documentation-flow help
help_fsm: help ## Show FSM-flow help

# ============================================================================
# 3. Setup and run initialization
# ============================================================================
##@ Setup
setup: ## Create the run directory tree
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

soc_cfg: ## Render SoC configuration variables
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

soc_start: flist ## Initialize a SoC run from loaded IPs
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@echo "\n$(ORANGE)Initializing SoC run from loaded IP bundles...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.backend.soc_start \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID)

# ============================================================================
# 4. IP metadata, RTL stubs, filelists and IP flow aliases
# ============================================================================
##@ IP flow
hjson: setup ## Generate an HJSON register template
	@echo "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.backend.hjson_gen $(OVERWRITE) --top $(TOP) --interface $(REG_ITF) --output-dir $(DATADIR)

hjson_gen: hjson ## Compatibility alias for HJSON generation
	@$(MKDIR) -p $(DATADIR)

reg: ## Generate register RTL from HJSON
	@$(MKDIR) -p $(RTLDIR)
	@echo "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)$(PYTHON) $(REGTOOL) -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

doc: ## Generate register documentation
	@$(MKDIR) -p $(DOCDIR)
	@echo "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)$(PYTHON) $(REGTOOL) -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) $(REGTOOL) --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

rtl_stub: ## Generate RTL wrapper/core stubs
	@echo "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.backend.rtl_stub_gen $(OVERWRITE) --hjson-file $(DATADIR)/$(TOP).hjson --interface $(REG_ITF) --output-dir $(RTLDIR)

ip_start: setup hjson reg doc rtl_stub flist setup_tb sim ## Bootstrap a complete IP run

flist: ## Generate the RTL filelist
	$(Q)$(PYTHON) -m flexsoc.backend.gen_filelist --top $(TOP) --out $(RTLDIR)/rtl_list.f --ips-root $(IPS_ROOT) --rtldir $(RTLDIR)

RTL_COMMON_LIST ?= $(RTLDIR)/rtl_common.f
RTL_IP_LIST ?= $(RTLDIR)/rtl_ip.f
RTL_LINT_LIST ?= $(RTLDIR)/rtl_lint.f

flist_split: flist ## Split common and IP RTL filelists
	@grep -E '/hw/ips/(pkgs|prim|prim_opentitan|tlul)/' $(RTLDIR)/rtl_list.f > $(RTL_COMMON_LIST) || true
	@grep -vE '/hw/ips/(pkgs|prim|prim_opentitan|tlul)/' $(RTLDIR)/rtl_list.f > $(RTL_IP_LIST) || true
	@cat $(RTL_COMMON_LIST) $(RTL_IP_LIST) > $(RTL_LINT_LIST)
	@echo $(RTL_COMMON_LIST)
	@echo $(RTL_IP_LIST)
	@echo $(RTL_LINT_LIST)

driver: ## Generate C driver files from HJSON
	$(Q)$(PYTHON) $(REGTOOL) -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) -m flexsoc.backend.driver_gen -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR)

fetch: ## Fetch or update a vendored dependency
	$(Q)$(PYTHON) $(VENDOR_TOOL) --update $(REPO_ROOT)/vendor/$(VENDOR).vendor.hjson

ip_flow: reg doc lint sim syn sdf sta sta_violators power view ## Run the standard IP flow
ip_flow_noreg: flist lint sim syn sdf sta sta_violators power view ## Run IP flow without regenerating registers
ip_flow_all: ip_start syn sdf sta sta_violators power view pnr pnr_gui ## Run full IP flow including PnR

# ============================================================================
# 5. Linting
# Supports the aggregate lint target and filtered diagnostics by kind.
# ============================================================================
##@ Linting
SLANG ?= slang
SLANG_HIER ?= slang-hier
VERILATOR ?= verilator

RTL_COMMON_LIST ?= $(RTLDIR)/rtl_common.f
RTL_IP_LIST ?= $(RTLDIR)/rtl_list.f

LINT_TOOL ?= auto
LINT_PART ?= ip
LINT_FULL_LOG ?= $(LOGDIR)/$(TOP)_lint_$(LINT_KIND)_full.log
LINT_COMMON_LOG ?= $(LOGDIR)/$(TOP)_lint_$(LINT_KIND)_common.log
LINT_IP_LOG ?= $(LOGDIR)/$(TOP)_lint_$(LINT_KIND)_ip.log

VERILATOR_LINT_BASE ?= --lint-only --sv -Wall -Wno-fatal
SLANG_LINT_BASE ?= --lint-only --single-unit --top $(TOP) -DSYNTHESIS --diag-hierarchy never

LINT_KINDS := latch undriven width unconnected unused

LINT_PATTERN_all := %Warning-|%Error-|warning:|error:
LINT_PATTERN_latch := %Warning-LATCH|\[-Winferred-latch\]|inferred latch
LINT_PATTERN_undriven := %Warning-UNDRIVEN|\[-Wundriven-port\]|undriven port|no driver|not driven
LINT_PATTERN_width := %Warning-(WIDTH|WIDTHEXPAND|WIDTHTRUNC)\b|\[-W(width-trunc|width-expand|port-width-trunc|port-width-expand)\]
LINT_PATTERN_unconnected := %Warning-(PINMISSING|PINCONNECTEMPTY|PINNOCONNECT)\b|\[-W(unconnected-|empty-.*connection)
LINT_PATTERN_unused := %Warning-(UNUSEDSIGNAL|UNUSEDPARAM)\b|\[-Wunused-

VERILATOR_FLAGS_all :=
VERILATOR_FLAGS_latch := -Wwarn-LATCH
VERILATOR_FLAGS_undriven := -Wwarn-UNDRIVEN
VERILATOR_FLAGS_width := -Wwarn-WIDTH -Wwarn-WIDTHEXPAND -Wwarn-WIDTHTRUNC
VERILATOR_FLAGS_unconnected := -Wwarn-PINMISSING -Wwarn-PINCONNECTEMPTY -Wwarn-PINNOCONNECT
VERILATOR_FLAGS_unused := -Wwarn-UNUSEDSIGNAL -Wwarn-UNUSEDPARAM

SLANG_FLAGS_all :=
SLANG_FLAGS_latch := -Winferred-latch
SLANG_FLAGS_undriven := -Wundriven-port
SLANG_FLAGS_width := -Wwidth-trunc -Wwidth-expand -Wport-width-trunc -Wport-width-expand
SLANG_FLAGS_unconnected := -Wunconnected-input-port -Wunconnected-output-port -Wunconnected-inout-port -Wempty-input-connection -Wempty-output-connection -Wempty-inout-connection
SLANG_FLAGS_unused := -Wunused-def -Wunused-net -Wunused-port -Wunused-variable -Wunused-parameter -Wunused-typedef -Wunused-import

LINT_ARGS = TOP="$(TOP)" HOST="$(HOST)" FORCE="$(FORCE)" RUN_ID="$(RUN_ID)" WORKSPACE="$(WORKSPACE)" LINT_TOOL="$(LINT_TOOL)" LINT_PART="$(LINT_PART)"

# Compatibility aliases used by compile_v/compile_sv prerequisites.
lint_v lint_sv: lint

lint: flist_split ## Run HDL lint checks
	@$(MAKE) -f $(lastword $(MAKEFILE_LIST)) _lint_run $(LINT_ARGS) \
		LINT_KIND=all LINT_PATTERN="$(LINT_PATTERN_all)" \
		LINT_VERILATOR_FLAGS="$(VERILATOR_FLAGS_all)" \
		LINT_SLANG_FLAGS="$(SLANG_FLAGS_all)"

lint_latch lint_undriven lint_width lint_unconnected lint_unused: lint_%: flist_split
	@$(MAKE) -f $(lastword $(MAKEFILE_LIST)) _lint_run $(LINT_ARGS) \
		LINT_KIND="$*" LINT_PATTERN="$(LINT_PATTERN_$*)" \
		LINT_VERILATOR_FLAGS="$(VERILATOR_FLAGS_$*)" \
		LINT_SLANG_FLAGS="$(SLANG_FLAGS_$*)"

_lint_run:
	@printf "\n$(ORANGE)Linting $(TOP) ($(LINT_KIND), $(LINT_PART))...$(RESET)\n"
	@mkdir -p $(LOGDIR)
	@if [ ! -f "$(RTL_COMMON_LIST)" ] || [ ! -f "$(RTL_IP_LIST)" ]; then echo "missing filelists. Run: fx flist"; exit 2; fi
	@tool="$(LINT_TOOL)"; \
	if [ "$$tool" = "auto" ]; then \
		if command -v "$(VERILATOR)" >/dev/null 2>&1; then tool="verilator"; \
		elif [ -x "$(SLANG)" ] || command -v slang >/dev/null 2>&1; then tool="slang"; \
		else echo "No lint backend found. Run: make install-slang or install verilator"; exit 2; fi; \
	fi; \
	if [ "$$tool" = "verilator" ]; then \
		cmd="$(VERILATOR) $(VERILATOR_LINT_BASE) $(LINT_VERILATOR_FLAGS) -f $(RTL_COMMON_LIST) -f $(RTL_IP_LIST) --top-module $(TOP)"; \
	elif [ "$$tool" = "slang" ]; then \
		if [ -x "$(SLANG)" ]; then slang_cmd="$(SLANG)"; elif command -v slang >/dev/null 2>&1; then slang_cmd="slang"; else echo "slang not found. Run: make install-slang"; exit 2; fi; \
		cmd="$$slang_cmd $(SLANG_LINT_BASE) $(LINT_SLANG_FLAGS) -f $(RTL_COMMON_LIST) -f $(RTL_IP_LIST)"; \
	else \
		echo "Unsupported LINT_TOOL=$$tool. Use auto, verilator, or slang."; exit 2; \
	fi; \
	echo "$$cmd"; \
	eval "$$cmd" > "$(LINT_FULL_LOG)" 2>&1; status=$$?; \
	if [ "$(LINT_KIND)" = "all" ]; then cat "$(LINT_FULL_LOG)"; exit $$status; fi; \
	grep -E -i "$(LINT_PATTERN)" "$(LINT_FULL_LOG)" | grep -vF "$(RTLDIR)" > "$(LINT_COMMON_LOG)" || true; \
	grep -E -i "$(LINT_PATTERN)" "$(LINT_FULL_LOG)" | grep -F "$(RTLDIR)" > "$(LINT_IP_LOG)" || true; \
	case "$(LINT_PART)" in \
		common) show="$(LINT_COMMON_LOG)" ;; \
		ip) show="$(LINT_IP_LOG)" ;; \
		all) printf "\n[common]\n"; cat "$(LINT_COMMON_LOG)"; printf "\n[ip]\n"; cat "$(LINT_IP_LOG)"; show="" ;; \
		*) echo "Unsupported LINT_PART=$(LINT_PART). Use ip, common, or all."; exit 2 ;; \
	esac; \
	if [ -n "$$show" ]; then cat "$$show"; fi; \
	if [ "$(LINT_PART)" = "all" ]; then \
		if [ -s "$(LINT_COMMON_LOG)" ] || [ -s "$(LINT_IP_LOG)" ]; then echo ""; echo "Found $(LINT_KIND) diagnostics."; exit 1; fi; \
	elif [ -s "$$show" ]; then \
		echo ""; echo "Found $(LINT_KIND) diagnostics. Full log: $(LINT_FULL_LOG)"; exit 1; \
	fi; \
	if [ $$status -ne 0 ]; then cat "$(LINT_FULL_LOG)"; exit $$status; fi; \
	echo "No $(LINT_KIND) diagnostics found for $(LINT_PART). Full log: $(LINT_FULL_LOG)"

SLANG_HIER_LOG ?= $(LOGDIR)/$(TOP)_hier.txt

slang_hier: flist_split ## Print hierarchy with slang-hier
	@mkdir -p $(LOGDIR)
	@if [ ! -x "$(SLANG_HIER)" ]; then echo "slang-hier not found. Run: make install-slang"; exit 2; fi
	$(Q)$(SLANG_HIER) --top $(TOP) -DSYNTHESIS -f $(RTL_LINT_LIST) > $(SLANG_HIER_LOG)

# ============================================================================
# 6. Testbench/model setup and simulation
# ============================================================================
##@ Simulation
setup_tb: setup flist ## Generate a SystemVerilog testbench
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

setup_cocotb: setup flist ## Generate a cocotb scaffold
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR)/cocotb
	$(Q)$(PYTHON) -m flexsoc.backend.setup_cocotb \
		--top $(TOP) --itf $(REG_ITF) \
		--rtl-dir $(RTLDIR) --output $(TBDIR)/cocotb \
		--clk clk_i --rst rst_ni --rst-active low --period-ns 10 \
		--sim $(COMPILER)

setup_model: setup ## Generate a Python model scaffold
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(MODELDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_model --top $(TOP) --output-dir $(MODELDIR)

compile: $(if $(filter v,$(VSV)),compile_v,compile_sv) ## Compile the current testbench
sim:     $(if $(filter v,$(VSV)),sim_v,sim_sv) ## Run simulation

compile_v: lint_v ## Compile Verilog simulation
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

sim_v: compile_v ## Run Verilog simulation
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

compile_sv: lint_sv ## Compile SystemVerilog simulation
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

sim_sv: compile_sv ## Run SystemVerilog simulation
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) +VCD=$(VCD_FILE) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

cocotb: ## Run cocotb tests
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb

# ============================================================================
# 7. Viewing, waveform inspection and regression artifacts
# ============================================================================
##@ Viewing
view: setup ## Open latest waveform
	@wave=$$(find "$(SIMDIR)" -maxdepth 1 -type f \( -name "*.fst" -o -name "*.vcd" -o -name "*.ghw" \) 2>/dev/null | sort | tail -n 1); \
	if [ -z "$$wave" ]; then \
		echo "No waveform found in $(SIMDIR). Run a simulation first, for example: fx sim"; \
		exit 1; \
	fi; \
	echo "Opening $$wave with $(WAVE_VIEWER)"; \
	case "$(WAVE_VIEWER)" in \
		surfer) $(SURFER_ENV) $(SURFER) "$$wave" ;; \
		gtkwave) $(GTKWAVE) "$$wave" ;; \
		*) echo "Unknown WAVE_VIEWER=$(WAVE_VIEWER). Use surfer or gtkwave."; exit 2 ;; \
	esac

view_cocotb: ## Open cocotb waveform
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(TBDIR)/cocotb/$(TOP)_tb.vcd $(VIEWER_CONF) &

view_syn: ## Reserved synthesis waveform viewer target

plot_postsyn: ## Open post-synthesis graph
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_postsyn.dot 2>/dev/null &

view_presyn: $(if $(filter v,$(VSV)),view_presyn_v,view_presyn_sv) ## Open pre-synthesis graph

view_presyn_v: sv2v ## Open pre-synthesis graph from Verilog
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn' \
		$(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

view_presyn_sv: ## Open pre-synthesis graph from SV
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p "\
	read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul -D SYNTHESIS --ignore-assertions \
		-f rtl/rtl_list.f --top $(TOP) ; \
	prep -top $(TOP); select -clear; select -module $(MODULE) ; \
	show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn" \
		> $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

# Signoff

tb_save: ## Save testbench regression artifacts
	$(Q)$(MKDIR) -p $(REGRESSIONDIR) $(REGRESSIONDIR)/$(TBDIR) $(REGRESSIONDIR)/$(SIMDIR)
	@echo "\n$(ORANGE)Save testbench file...\n$(RESET)"
	$(Q)$(CP) $(TBDIR)/$(TOP)_tb.sv $(REGRESSIONDIR)/$(TBDIR)/$(TOP)_$(OUTNAME)_tb.sv
	$(Q)$(CP) $(SIMDIR)/$(TOP)_tb.vcd $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.vcd
	$(Q)$(CP) $(SIMDIR)/$(TOP)_tb.gtkw $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.gtkw

tb_view: ## Open saved testbench waveform
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.vcd \
		$(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.gtkw &

# ============================================================================
# 8. Synthesis and netlist generation
# ============================================================================
##@ Synthesis
setup_sdc: setup ## Generate timing constraints
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_sdc $(TOP) $(CLK_PERIOD) -o $(ORSDIR)/$(TOP).sdc

setup_syn: setup_sdc ## Generate Yosys synthesis scripts
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SYNDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_syn \
		-top $(TOP) -topdir $(RTLDIR) -sdcdir $(ORSDIR) \
		--filelist $(RTLDIR)/rtl_list.f \
		-liberty $(LIB_SYN) -clk $(CLK_PERIOD) \
		-target $(TARGET_SYN) -opt $(TARGET_OPT) \
		-o $(SYNDIR)

syn: $(if $(filter v,$(VSV)),syn_v,syn_sv) ## Run synthesis

syn_v: setup_syn ## Run Verilog synthesis
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) $(SYNDIR)/synth.ys > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

syn_sv: setup_syn ## Run SystemVerilog synthesis
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -s $(SYNDIR)/synth_sv.ys > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

yosys-vgen: ## Convert SV to Verilog with Yosys
	@echo "\n$(ORANGE)Verilog generation with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p "\
	read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul -D SYNTHESIS --ignore-assertions \
		-f rtl/rtl_list.f \
		--top $(TOP); \
	opt -keepdc; \
	bwmuxmap; \
	opt_clean; \
	write_verilog -norename -noattr rtl/$(TOP).v" > /dev/null 2>&1

# Legacy extension point kept explicit. Implement conversion here if SV2V is required.
sv2v: ## Convert SV to Verilog with sv2v
	@true

# ============================================================================
# 9. Gate-level simulation and signoff analysis
# SDF, STA, violator extraction, power and path-view reports.
# ============================================================================
##@ Signoff
setup_signoff: setup_sdc syn ## Generate signoff scripts
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff \
		--top $(TOP) \
		--constraints-dir $(ORSDIR) --synthesis-dir $(SYNDIR) --simulation-dir $(SIMDIR) \
		--liberty $(LIBS) --activity-pct $(ACTIVITY) \
		--output-dir $(SIGNOFFDIR)

SYN_NETLIST ?= $(SYNDIR)/$(TOP)_synth.v

compile_syn: syn ## Compile post-synthesis simulation
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

sim_syn: compile_syn ## Run post-synthesis simulation
	@echo "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TOP)_syn_tb.vvp -sdf-verbose +VCD=$(VCD_SYN_FILE) +SDF=$(SDF_FILE) \
		> $(LOGDIR)/$(TOP)_syn_sim.log 2>&1

sta: setup_signoff ## Run static timing analysis
	@echo "\n$(ORANGE)Static Timing Analysis...\n$(RESET)"
	$(Q)bash -o pipefail -c '$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl 2>&1 | tee $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log'
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).errors || true

sdf: setup_signoff ## Write SDF timing files
	@echo "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/sdf
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl 2>&1

power: setup_signoff ## Run power analysis
	@echo "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(Q)bash -o pipefail -c '$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl 2>&1 | tee $(LOGDIR)/$(TOP)_power.log'

sta_violators: setup_signoff ## Report timing violators
	@echo "\n$(ORANGE)Static Timing Analysis only timing violators...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta_violators.tcl > $(LOGDIR)/$(TOP)_sta.violators

path_view: ## Build interactive STA path view
	@echo "\n$(ORANGE)Path view generation of STA report...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/path_view
	$(Q)$(PYTHON) $(UTILDIR)/interactiveReport.py -i $(LOGDIR)/$(PATH_VIEW_FILE) -s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)

# ============================================================================
# 10. OpenROAD place and route
# ============================================================================
##@ Place and route
setup_pnr: ## Generate OpenROAD config
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_pnr --top $(TOP) \
		--synthesis-strategy $(TARGET_OPT) --clock-period $(CLK_PERIOD) \
		--platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f --output-dir $(ORSDIR)

pnr: setup_pnr ## Run OpenROAD place and route
	@echo "\n$(ORANGE)Doing Place&Route...\n$(RESET)"
	$(Q)$(MKDIR) -p $(OR_LOGDIR)
	$(Q)$(MKDIR) -p $(OR_WORKDIR)
	@log="$(OR_LOGDIR)/$(TOP)_pnr.log"; \
	cfg="$(OR_CFG_MK)"; \
	if [ -n "$(MAKE_DRY_RUN)" ]; then \
		echo "cd $(OR_WORKDIR) && $(MAKE) --file=$(OR_MAKEFILE) --no-print-dir DESIGN_CONFIG=$$cfg > $$log 2>&1"; \
		exit 0; \
	fi; \
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

pnr_gui: setup_pnr ## Open OpenROAD GUI
	$(Q)$(MKDIR) -p $(OR_WORKDIR)
	@cfg="$(OR_CFG_MK)"; \
	if [ -n "$(MAKE_DRY_RUN)" ]; then \
		echo "cd $(OR_WORKDIR) && $(MAKE) gui_final --file=$(OR_MAKEFILE) --no-print-dir DESIGN_CONFIG=$$cfg 2>/dev/null &"; \
		exit 0; \
	fi; \
	if [ ! -f "$$cfg" ]; then \
		echo "ERROR: OpenROAD config.mk not found: $$cfg"; \
		exit 2; \
	fi; \
	cd "$(OR_WORKDIR)" && \
	$(MAKE) gui_final --file="$(OR_MAKEFILE)" --no-print-dir \
		DESIGN_CONFIG="$$cfg" 2>/dev/null &

# ============================================================================
# 11. IP load/save
# ============================================================================
##@ IP load/save
ip_load: ## Load an IP into a run workspace
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
	$(MAKE) -f $(BACKEND_MAKEFILE) flist HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)

ip_save: ## Save run artifacts back to hw/ips
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

# ============================================================================
# 12. SoC, FuseSoC, XBAR and software flow
# ============================================================================
##@ SoC flow
PRJ           ?= flexsoc
TARGET        ?= default
TOP           ?= soc
HOST          ?= uart
SOC_CFG_MODE  ?= builtin
FUSESOC_TOOL  ?=
SOC_CORE_VLNV ?= enea:soc:main
# Run-local FuseSoC layout
# Host-specific to avoid stale UART/IBEX reuse inside the same run.
FUSESOC_ROOT       ?= $(OUTROOT)/fusesoc/$(HOST)
FUSESOC_CORES_ROOT ?= $(FUSESOC_ROOT)/cores
FUSESOC_BUILD_ROOT ?= $(FUSESOC_ROOT)/build
SOC_SIM_EXE        ?= $(FUSESOC_BUILD_ROOT)/sim-verilator/Vtop_verilator

fsoc_init: ## Initialize FuseSoC metadata
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
# FuseSoC build/run entry
fsoc: ## Generate FuseSoC core file
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
# XBAR generation
xbar: xbar_init xbar_build ## Generate crossbar artifacts
xbar_init: soc_cfg ## Generate crossbar input config
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
xbar_build: ## Run tlgen for crossbar RTL
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
# Stage loaded IP top modules into SoC RTL dir
#
# Why:
# - soc_gen validates that referenced module wrappers exist.
# - loaded IPs live under $(OUTROOT)/ips/<ip>/rtl/<ip>.sv
# - stage only the top wrapper <ip>.sv into $(RTLDIR)
soc_stage_tops: ## Stage SoC top-level files
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
# SoC RTL generation
soc: soc_stage_tops ## Generate SoC RTL
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
soc_flist: ## Generate SoC filelist
	@echo "\n$(ORANGE)Generating SoC filelist ...\n$(RESET)"
	$(call _require_soc_run_vars)
	$(Q)$(PYTHON) -m flexsoc.backend.gen_filelist \
		--soc \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--top soc \
		--out $(RTLDIR)/rtl_list.f
soc_flow: xbar soc soc_flist ## Generate crossbar, SoC RTL and filelist
# Host-specific wrappers
soc_uart_gen: HOST := uart
soc_uart_gen: SOC_CFG_MODE := builtin
soc_uart_gen: xbar soc soc_flist ## Generate UART-host SoC artifacts
soc_ibex_gen: HOST := ibex
soc_ibex_gen: SOC_CFG_MODE := builtin
soc_ibex_gen: xbar soc soc_flist ## Generate Ibex-host SoC artifacts
# Software generation
sw_soc: ## Generate SoC software scaffold
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,HOST)
	$(Q)$(PYTHON) -m flexsoc.backend.sw_soc_gen \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--host $(HOST)
soc_prepare: ## Prepare SoC build directory
	$(call _require_soc_run_vars)
	@echo "\n$(ORANGE)[soc_prepare] build simulation model (HOST=$(HOST)) ...\n$(RESET)"
	$(Q)$(MKDIR) -p $(OUTROOT)/sim
	$(Q)$(MAKE) soc_sim HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)

soc_build_sw: soc_prepare ## Build SoC software
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,HOST)
	@echo "\n$(ORANGE)[soc_build_sw] generate software sources ...\n$(RESET)"
	$(Q)$(MAKE) sw_soc WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) HOST=$(HOST)
	@echo "\n$(ORANGE)[soc_build_sw] compile software ...\n$(RESET)"
	$(Q)$(MAKE) --no-print-dir -C $(OUTROOT)/sw
# Simulation / run
soc_sim: ## Build SoC simulator
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
soc_run: ## Run SoC simulation
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
# Waveform viewer
soc_view: ## Open SoC waveform
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

# Explicit alias for the phony target declared in the original file.
soc_run_only: soc_run ## Alias for SoC simulation run

# ============================================================================
# 13. FSM flow
# ============================================================================
##@ FSM flow
fsm_init: ## Create FSM workspace directories
	$(call _require_fsm)
	$(Q)$(MKDIR) -p "$(FSM_INPUT_DIR)" "$(FSM_OUTPUT_DIR)"

fsm_setup: fsm_init ## Set up the FSM generator
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) setup

fsm_example_load: fsm_init ## Load the FSM example inputs
	$(call _require_fsm)
	$(Q)$(CP) "$(FSMGEN_DIR)/examples/fsm_example.txt" "$(FSM_INPUT_DIR)/$(FSM).txt"
	$(Q)$(CP) "$(FSMGEN_DIR)/examples/fsm_example.csv" "$(FSM_INPUT_DIR)/$(FSM).csv"
	@echo "\n$(ORANGE)Loaded FSM example into $(FSM_INPUT_DIR) as $(FSM)\n$(RESET)"

fsm_gen: fsm_init ## Generate FSM RTL
	$(call _require_fsm)
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) gen \
		PYTHON="$(PYTHON)" FSM="$(FSM)" F_CLK="$(or $(strip $(F_CLK)),32)" \
		INPUT_DIR="$(FSM_INPUT_DIR)" OUTPUT_DIR="$(FSM_OUTPUT_DIR)"

fsm_plot: fsm_init ## Plot FSM diagrams
	$(call _require_fsm)
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) plot \
		PYTHON=$(PYTHON) FSM=$(FSM) \
		INPUT_DIR="$(FSM_INPUT_DIR)" OUTPUT_DIR="$(FSM_OUTPUT_DIR)"

fsm_flow: fsm_gen fsm_plot ## Generate and plot FSM artifacts

fsm_install: fsm_init ## Install FSM artifacts into the IP run
	$(call _require_fsm)
	$(Q)$(MKDIR) -p "$(RTLDIR)" "$(TBDIR)" "$(SIMDIR)"
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM).sv" "$(RTLDIR)/"
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM)_pkg.sv" "$(RTLDIR)/"
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM).gtkw" "$(SIMDIR)/" || true
	$(Q)$(CP) "$(FSM_OUTPUT_DIR)/$(FSM)_tb.sv" "$(TBDIR)/"
	@echo "\n$(ORANGE)Installed FSM $(FSM) artifacts into IP run directories\n$(RESET)"

# Backwards-compatible name used by fsm_tutorial in the original flow.
fsm2rtl: fsm_install ## Alias for FSM RTL installation

# ============================================================================
# 14. Tutorial and composed flows
# ============================================================================
##@ Tutorials
# Tutorial defaults
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

soc_uart_tutorial: ## Run UART-host SoC tutorial
	@echo "\n$(ORANGE)Loading IPs for UART-host SoC tutorial ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=uart-master LOAD_AS=uart
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=gpio
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=rv_timer
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=pwm
	$(Q)$(MAKE) soc_run HOST=uart SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
soc_ibex_fetch: ## Fetch Ibex tutorial dependencies
	@echo "\n$(ORANGE)Fetch lowRISC IPs ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	@echo "\n$(ORANGE)Fetch Ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex
soc_ibex_tutorial: soc_ibex_fetch ## Run Ibex-host SoC tutorial
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

# FSM and clean targets
# FSM flow

full_tutorial: ## Run the full IP tutorial flow
	$(Q)$(MAKE) ip_start ip_flow pnr pnr_gui \
		TOP=test RUN_TOP=test \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

fsm_tutorial: ## Run the FSM tutorial flow
	$(call _require_var,TOP)
	$(Q)$(MAKE) setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(MAKE) ip_flow_noreg \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

ip_tutorial: ## Run the IP tutorial flow
	$(call _require_var,TOP)
	$(Q)$(MAKE) ip_load \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	@echo "\n$(ORANGE)Run the IP flow ...\n$(RESET)"
	$(Q)$(MAKE) flist sim syn sdf sta sta_violators power view \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

soc_pless: ## Run the tiny SoC tutorial flow
	$(Q)$(MAKE) ip_load \
		TOP=tiny-soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(MAKE) flist sim syn sdf sta power view \
		TOP=soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

# ============================================================================
# 15. Dependencies
# ============================================================================
##@ Dependencies
deps: ## Install IP development dependencies
	@echo "\n$(ORANGE)Installing dependencies for IP development ...\n$(RESET)"
	sudo apt install -y make python3 python3-pip
	sed -i 's/\r$$//' $(TOOLSROOT)/deps.sh
	bash $(TOOLSROOT)/deps.sh ip
	pip install -r requirements.txt

deps-soc: ## Install SoC development dependencies
	@echo "\n$(ORANGE)Installing dependencies for SoC integration ...\n$(RESET)"
	bash $(TOOLSROOT)/deps.sh soc
	echo
	export PATH=$$PATH:/tools/riscv32/bin
	printf "%s\n" "export PATH=/tools/riscv32/bin" >> ~/.bashrc

# ============================================================================
# 16. Clean targets
# ============================================================================
##@ Cleanup
clean-pyc: ## Remove Python caches
	@find . -type d -name "__pycache__" -prune -exec rm -rf {} +
	@find . -type f -name "*.pyc" -delete
	@find . -type f -name "*.pyo" -delete
	@rm -rf .pytest_cache .ruff_cache

clean_doc: ## Remove generated docs
	$(Q)$(RM) $(DOCDIR)/*

clean_log: ## Remove logs
	$(Q)$(RM) $(LOGDIR)/*

clean_rtl: ## Remove generated RTL
	$(Q)$(RM) $(RTLDIR)/*.v

clean_sim: ## Remove simulation outputs
	$(Q)$(RM) $(SIMDIR)/*.vvp
	$(Q)$(RM) $(SIMDIR)/*.vcd
	$(Q)$(RM) -r $(SIMDIR)/verilator

clean_cocotb: ## Remove cocotb outputs
	$(Q)$(RM) $(TBDIR)/cocotb/*.vcd
	$(Q)$(RM) $(TBDIR)/cocotb/sim_build
	$(Q)$(RM) $(TBDIR)/cocotb/__py*
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb clean

clean_syn: ## Remove synthesis outputs
	$(Q)$(RM) -rf $(SYNDIR)/*

clean_signoff: ## Remove signoff outputs
	$(Q)$(RM) $(SIGNOFFDIR)/sdf/*
	$(Q)$(RM) $(SIGNOFFDIR)/*.sdc

clean_pnr: ## Remove PnR outputs
	$(Q)$(RM) -rf $(ORSDIR)/*
	$(Q)$(RM) -rf $(ORS_LOGS)
	$(Q)$(RM) -rf $(ORS_REPORTS)
	$(Q)$(RM) -rf $(ORS_RESULTS)
	$(Q)$(RM) -rf $(ORS_OBJECTS)

clean_fsm: ## Clean FSM generator outputs
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) clean

clean_fsm_all: ## Deep-clean FSM generator outputs
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) clean_all

clean_agent: ## Remove old agent outputs
	$(Q)$(RM) flexsoc_make_agent/logs
	$(Q)$(RM) flexsoc_make_agent/runs
	$(Q)$(RM) fsm_agent/src/__py*
	$(Q)$(RM) fsm_agent/data/inbox/out*

clean_fsoc: ## Remove FuseSoC build outputs
	$(Q)$(RM) build

clean_soc: ## Remove SoC build outputs
	@echo "\n$(ORANGE)Cleaning SoC ...\n$(RESET)"
	$(Q)$(RM) build trace_core_00000000.log uart0.log sim.fst* sw/*.elf sw/*.o sw/*.csv tb/top_verilator.* soc.core xbar_main.hjson $(TOPDIR)

clean_sw: ## Clean SoC software outputs
	$(Q)$(MAKE) --no-print-dir -C sw clean

clean_vendor: ## Remove vendored IP checkouts
	$(Q)$(RM) vendor/lowrisc_ip
	$(Q)$(RM) vendor/lowrisc_ibex
	$(Q)$(RM) vendor/lowrisc_ip.lock.hjson
	$(Q)$(RM) vendor/lowrisc_ibex.lock.hjson

clean_subdir: ## Clean helper subdirectories
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) clean
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) setup

clean: clean-pyc clean_log clean_rtl clean_sim clean_syn clean_signoff clean_pnr clean_subdir clean_fsoc clean_soc clean_fsm ## Clean generated flow outputs
	$(Q)$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec $(RM) -f {} + > /dev/null 2>&1
	$(Q)$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	$(Q)$(CLEAR)

clean_all: ## Remove all generated run outputs
	@echo "Cleaning generated FlexSoC outputs..."
	@rm -rf $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)
	@rm -rf $(WORKSPACE)/runs/$(TOP)/default
	@find $(WORKSPACE)/runs/$(TOP) -maxdepth 1 -type d -empty -delete 2>/dev/null || true
	@rm -rf build dist .pytest_cache .mypy_cache .ruff_cache
	@find . -type d -name __pycache__ -prune -exec rm -rf {} + 2>/dev/null || true
	@find . -type f -name '*.pyc' -delete 2>/dev/null || true
	@true
