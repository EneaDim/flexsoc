BACKEND_DIR ?= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
FLEXSOC_BACKEND_DIR ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TB_SV_DIR ?= $(TBDIR)/sv
TESTS_DIR ?= $(FUNCTIONALDIR)/tests
N_CLOCKS ?= 1
CLOCK_DOMAINS ?=
CLOCK_RELATIONSHIPS ?=
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
#   8. signoff: SDF, STA, estimated power, path analysis
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
BACKEND_MAKE ?= $(MAKE) -f $(BACKEND_MAKEFILE)
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
DV_DIR ?= $(RUN_DIR)/dv
FUNCTIONALDIR ?= $(DV_DIR)/functional
FORMALDIR ?= $(DV_DIR)/formal
FORMAL_CSR_DIR ?= $(FORMALDIR)/csr
FORMAL_CSR_PROVE_DIR ?= $(FORMAL_CSR_DIR)/prove
FORMAL_CSR_COVER_DIR ?= $(FORMAL_CSR_DIR)/cover
FORMAL_PROPERTIES_DIR ?= $(FORMALDIR)/properties
FORMAL_PROVE_PROPERTIES_DIR ?= $(FORMAL_PROPERTIES_DIR)/prove
FORMAL_COVER_PROPERTIES_DIR ?= $(FORMAL_PROPERTIES_DIR)/cover
FORMAL_RUN_DIR ?= $(FORMALDIR)/runs
FORMAL_PROVE_DIR ?= $(FORMAL_RUN_DIR)/properties/prove
FORMAL_COVER_DIR ?= $(FORMAL_RUN_DIR)/properties/cover
FORMAL_CSR_PROVE_RUN_DIR ?= $(FORMAL_RUN_DIR)/csr/prove
FORMAL_CSR_COVER_RUN_DIR ?= $(FORMAL_RUN_DIR)/csr/cover
TB_DIR ?= $(FUNCTIONALDIR)/tb
SV_TB_DIR := $(TB_DIR)/sv

# -----------------------------------------------------------------------------
# Derived directories
# -----------------------------------------------------------------------------
LOGDIR         ?= $(OUTROOT)/logs
VERIFY_LOGDIR  ?= $(LOGDIR)/dv/functional
COVERAGEDIR    ?= $(FUNCTIONALDIR)/coverage
COVERAGE_SUMMARY_JSON ?= $(COVERAGEDIR)/summary.json
COVERAGE_ANNOTATEDDIR ?= $(COVERAGEDIR)/annotated
COVERAGE_DETAIL_LIMIT ?= 0
COVERAGE_LOGDIR ?= $(VERIFY_LOGDIR)/coverage
COVERAGE_DETAIL_LOG ?= $(COVERAGE_LOGDIR)/$(TOP)_coverage_detail.log
REGRESSION_LOGDIR ?= $(VERIFY_LOGDIR)/regression
FORMAL_LOGDIR ?= $(abspath $(LOGDIR)/dv/formal)
FORMAL_BMC_LOG ?= $(FORMAL_LOGDIR)/properties/$(TOP)_bmc.log
FORMAL_PROVE_LOG ?= $(FORMAL_LOGDIR)/properties/$(TOP)_prove.log
FORMAL_COVER_LOG ?= $(FORMAL_LOGDIR)/properties/$(TOP)_cover.log
FORMAL_CSR_BMC_LOG ?= $(FORMAL_LOGDIR)/csr/$(TOP)_bmc.log
FORMAL_CSR_PROVE_LOG ?= $(FORMAL_LOGDIR)/csr/$(TOP)_prove.log
FORMAL_CSR_COVER_LOG ?= $(FORMAL_LOGDIR)/csr/$(TOP)_cover.log
SYNTH_LOGDIR   ?= $(LOGDIR)/synthesis/$(PDK)
EQUIV_LOG      ?= $(LOGDIR)/signoff/$(PDK)/equivalence/$(TOP)_rtl_vs_syn.log
STA_LOGDIR     ?= $(LOGDIR)/signoff/$(PDK)/sta
POWER_LOGDIR   ?= $(LOGDIR)/signoff/$(PDK)/power
SDF_LOGDIR     ?= $(LOGDIR)/signoff/$(PDK)/sdf
FUSION_LOGDIR  ?= $(LOGDIR)/signoff/$(PDK)/fusion
SV_COMPILE_LOG ?= $(VERIFY_LOGDIR)/$(TOP)_sv_compile_$(TEST_NAME).log
SV_SIM_LOG     ?= $(VERIFY_LOGDIR)/$(TOP)_sv_sim_$(TEST_NAME).log
COCOTB_LOG     ?= $(VERIFY_LOGDIR)/$(TOP)_cocotb_$(TEST_NAME).log
COCOTB_WRAPPER ?= $(TBDIR)/cocotb/$(TOP)_tb.sv
COCOTB_RTL_SOURCES = $(shell awk 'NF && $$1 !~ /^#/ && $$1 !~ /^[+-]/ {print $$1}' $(RTL_COMMON_LIST) $(RTL_IP_LIST) 2>/dev/null)
RTLDIR         ?= $(OUTROOT)/rtl
TBDIR          ?= $(FUNCTIONALDIR)/tb
SIMROOT        ?= $(FUNCTIONALDIR)/sim
SIMDIR         ?= $(SIMROOT)/rtl
POST_SYN_SIMDIR ?= $(SIMROOT)/post_syn/$(PDK)
POST_LAYOUT_SIMDIR ?= $(SIMROOT)/post_pnr/$(PDK)
CONSTRAINTSDIR ?= $(OUTROOT)/constraints
SYNDIR         ?= $(OUTROOT)/syn/$(PDK)
SIGNOFFDIR      ?= $(OUTROOT)/signoff
SIGNOFF_PDK_DIR  ?= $(SIGNOFFDIR)/$(PDK)
EQUIVDIR         ?= $(SIGNOFF_PDK_DIR)/equivalence/rtl_vs_syn
SIGNOFF_STA_DIR  ?= $(SIGNOFF_PDK_DIR)/sta
SIGNOFF_POWER_DIR ?= $(SIGNOFF_PDK_DIR)/power
SIGNOFF_SDF_DIR  ?= $(SIGNOFF_PDK_DIR)/sdf
SIGNOFF_FUSION_DIR ?= $(SIGNOFF_PDK_DIR)/fusion
SIGNOFF_PATH_VIEW_DIR ?= $(SIGNOFF_PDK_DIR)/path_view
METADIR        ?= $(OUTROOT)/meta/$(PDK)
METRICS_JSON   ?= $(METADIR)/metrics.json
MANIFEST_JSON  ?= $(METADIR)/manifest.json
MODELDIR       ?= $(FUNCTIONALDIR)/model
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
ORSDIR         ?= $(OUTROOT)/pnr_openroad/$(PDK)
TB_SAVEDIR     ?= $(FUNCTIONALDIR)/saved
TEST_NAMES     ?= smoke corners random reconfig
REGMAP ?=
SIGNOFF_CORNERS    ?= ss tt ff
STA_MODES          ?= setup hold
STA_PATHS          ?= 100
STA_GROUPS         ?= 20
TEST_NAME      ?= smoke
SEED           ?= 1
REGRESSION_BACKENDS ?= sv cocotb
COVERAGE       ?= 0
TEST_ROOT      ?= $(FUNCTIONALDIR)/tests
TESTDIR        ?= $(TEST_ROOT)/$(TEST_NAME)
REGCFG         ?= $(TESTDIR)/config.regs
DATA_IN        ?= $(TESTDIR)/data_in.vec
DATA_OUT       ?= $(TESTDIR)/data_out.vec
SIM_TEST_SEL   := +TEST_NAME=$(TEST_NAME)
SIM_TEST_FILES := +TEST_ROOT=$(TEST_ROOT) +CFG=$(REGCFG) +DATA_IN=$(DATA_IN) +DATA_OUT=$(DATA_OUT)
SIM_PLUSARGS   ?= $(SIM_TEST_SEL) $(SIM_TEST_FILES)
COCOTB_WAVES   ?= 1
SV_COVERAGE_FILE ?= $(COVERAGEDIR)/sv/$(TEST_NAME).dat
COCOTB_COVERAGE_FILE ?= $(COVERAGEDIR)/cocotb/$(TEST_NAME).dat
VERILATOR_RUNTIME_ARGS = +verilator+seed+$(SEED) $(if $(filter 1,$(COVERAGE)),+verilator+coverage+file+$(SV_COVERAGE_FILE),)

# -----------------------------------------------------------------------------
# Toolchain
# -----------------------------------------------------------------------------
PYTHON          ?= python3
YOSYS           ?= yosys
SBY             ?= sby
EQY             ?= eqy
STA             ?= sta
SV2V            ?= sv2v
LINTER          ?= verilator
COMPILER        ?= verilator
VERILATOR_COVERAGE ?= verilator_coverage
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
                   --trace-fst --trace-structs \
                   +incdir+$(RTLDIR) +incdir+$(TBDIR) +incdir+$(MODELDIR) \
                   +incdir+$(INC_PRIM) \
                   +incdir+$(INC_PKGS) \
                   +incdir+$(INC_PRIM_OT) \
                   +incdir+$(INC_TLUL)

TESTBENCH       ?= $(TOP)_tb
TESTBENCHES     := $(wildcard $(TBDIR)/*.sv)
VSV             ?= sv
WAVE_EXT        ?= $(if $(filter verilator,$(COMPILER)),fst,vcd)
WAVE_FILE       ?= $(SIMDIR)/$(TESTBENCH)_$(TEST_NAME).$(WAVE_EXT)
VCD_SYN_FILE    ?= $(POST_SYN_SIMDIR)/$(TOP)_syn_tb.vcd
SDF_FILE        ?= $(SIGNOFF_SDF_DIR)/ss/$(TOP)_ss.sdf

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
FORMAL_DEPTH ?= 20
FORMAL_BMC_DEPTH ?= 30
FORMAL_BMC_APPEND ?= 5
FORMAL_BMC_ENGINE ?= smtbmc bitwuzla
FORMAL_PROVE_ENGINE ?= abc pdr
FORMAL_COVER_ENGINE ?= btor btormc
EQY_SAT_DEPTH ?= 5
EQY_DEPTH ?= 2
EQY_ENGINE ?= abc pdr
EQY_JOBS ?= 4
EQY_RESET_NORMALIZE ?= 1
EQY_RESET_CYCLES ?= 2
POWER_ACTIVITY  ?= 0.1
POWER_DUTY      ?= 0.5
POWER_GLOBAL_ACTIVITY ?= 0
POWER_VCD_SCOPE ?= auto
POWER_DUT_INSTANCE ?= auto
FST2VCD ?= fst2vcd
MACRO_LIBS ?=
SIGNOFF_STAGE ?= post_syn
STA_ENDPOINT_GROUP_LIMIT ?= 10000
STA_ENDPOINT_PATH_LIMIT ?= 10
STA_NEAR_CRITICAL_SETUP ?= 0.200
STA_NEAR_CRITICAL_HOLD ?= 0.100
POWER_TOP_INSTANCES ?= 200
FUSION_PATHS_PER_INSTANCE ?= 2
FUSION_TOP_PATHS ?= 100
FUSION_POWER_METRIC ?= dynamic
FUSION_HIGH_FANOUT_THRESHOLD ?= 16
PATH_VIEW_FILE  ?= tt/setup/violating.rpt
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
OR_WORKDIR  ?= $(abspath $(OUTROOT))/pnr_openroad/$(PDK)
OR_LOGDIR   ?= $(abspath $(LOGDIR))/pnr/$(PDK)
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
LIVE ?= 0

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

define _require_file
	@if [ ! -f "$1" ]; then \
		echo "ERROR: missing required artifact: $1"; \
		echo "Hint: run: fx $2"; \
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
PHONY_TARGETS += setup soc_cfg soc_start sta_corners power_estimate_corners signoff_corners metrics manifest manifest_show check
PHONY_TARGETS += hjson hjson_gen reg doc rtl_stub top_from_core flist driver fetch regmap_py
PHONY_TARGETS += ip_start ip_flow ip_flow_noreg ip_flow_all
PHONY_TARGETS += lint lint_slang lint_verilator lint_slang_suite lint_verilator_suite lint_suite lint_v lint_sv lint_latch lint_undriven lint_width lint_unconnected lint_unused _lint_run slang_hier slang_ast slang_flist
PHONY_TARGETS += setup_tb setup_cocotb setup_model tests_gen test_gen tests compile compile_v compile_sv sim sim_v sim_sv sim_tests cocotb cocotb_tests regression coverage coverage_detail
PHONY_TARGETS += view view_cocotb view_syn plot_postsyn view_presyn view_presyn_v view_presyn_sv tb_save tb_view
PHONY_TARGETS += setup_sdc setup_syn syn syn_v syn_sv yosys-vgen sv2v
PHONY_TARGETS += _formal_scaffold setup_formal setup_formal_prove setup_formal_cover formal_bmc formal_prove formal_cover setup_formal_csr_prove setup_formal_csr_cover formal_csr_bmc formal_csr_prove formal_csr_cover formal_csr formal
PHONY_TARGETS += setup_eqy eqy setup_signoff compile_syn sim_syn sta sdf power_estimate power_analysis power_analysis_all fusion_analysis fusion_analysis_all sta_violators path_view
PHONY_TARGETS += setup_pnr pnr pnr_gui
PHONY_TARGETS += ip_load ip_save
PHONY_TARGETS += soc_vendor_deps fsoc_init fsoc xbar xbar_init xbar_build soc soc_stage_tops soc_flist soc_flow soc_uart_gen soc_ibex_gen
PHONY_TARGETS += sw_soc soc_prepare soc_build_sw soc_sim soc_run soc_run_only soc_view
PHONY_TARGETS += fsm_init fsm_setup fsm_example_load fsm_gen fsm_plot fsm_flow fsm_install fsm2rtl
PHONY_TARGETS += soc_uart_tutorial soc_ibex_fetch soc_ibex_tutorial full_tutorial fsm_tutorial ip_tutorial soc_pless
PHONY_TARGETS += deps-bootstrap deps deps-doctor deps-versions deps-env deps-status deps-prune
PHONY_TARGETS += clean-pyc clean_doc clean_log clean_rtl clean_sim clean_cocotb clean_formal clean_syn clean_signoff clean_meta clean_pnr
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
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	$(Q)$(MKDIR) -p \
		$(LOGDIR) \
		$(VERIFY_LOGDIR) \
		$(RTLDIR) \
		$(TBDIR) \
		$(TEST_ROOT) \
		$(SIMDIR) \
		$(CONSTRAINTSDIR) \
		$(SIGNOFFDIR) \
		$(FORMAL_CSR_PROVE_DIR) \
		$(FORMAL_CSR_COVER_DIR) \
		$(FORMAL_PROVE_PROPERTIES_DIR) \
		$(FORMAL_COVER_PROPERTIES_DIR) \
		$(MODELDIR) \
		$(DOCDIR) \
		$(DATADIR) \
		$(DRIVERDIR) \
		$(LINTDIR) \
		$(PYDIR) \
		$(FSMDIR)

soc_cfg: ## Render SoC configuration variables
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
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
	$(Q)$(PYTHON) -m flexsoc.backend.soc_start \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID)

# ============================================================================
# 4. IP metadata, RTL stubs, filelists and IP flow aliases
# ============================================================================
##@ IP flow



hjson: setup ## Generate an HJSON register template
	$(Q)$(PYTHON) -m flexsoc.backend.hjson_gen $(OVERWRITE) --top $(TOP) --interface $(REG_ITF) --output-dir $(DATADIR)

hjson_gen: hjson ## Compatibility alias for HJSON generation
	@$(MKDIR) -p $(DATADIR)

reg: setup ## Generate register RTL for every generated register map
	@$(MKDIR) -p $(RTLDIR)
	@set -eu; found=0; \
	for file in $(DATADIR)/$(TOP).hjson $(DATADIR)/$(TOP)_*.hjson; do \
		[ -f "$$file" ] || continue; \
		[ -z "$(REGMAP)" ] || [ "$$(basename "$$file" .hjson)" = "$(TOP)_$(REGMAP)" ] || continue; \
		found=1; $(PYTHON) $(REGTOOL) -r -t $(RTLDIR) "$$file"; \
	done; \
	[ $$found -eq 1 ] || { echo "ERROR: no HJSON register maps found for $(TOP) under $(DATADIR)"; exit 2; }

doc: setup ## Generate documentation for every generated register map
	@$(MKDIR) -p $(DOCDIR)
	@set -eu; found=0; \
	for file in $(DATADIR)/$(TOP).hjson $(DATADIR)/$(TOP)_*.hjson; do \
		[ -f "$$file" ] || continue; \
		base=$$(basename "$$file" .hjson); \
		[ -z "$(REGMAP)" ] || [ "$$base" = "$(TOP)_$(REGMAP)" ] || continue; \
		found=1; $(PYTHON) $(REGTOOL) -d -o "$(DOCDIR)/$$base.md" "$$file"; \
		$(PYTHON) $(REGTOOL) --interfaces -o "$(DOCDIR)/$${base}_interfaces.md" "$$file"; \
	done; \
	[ $$found -eq 1 ] || { echo "ERROR: no HJSON register maps found for $(TOP) under $(DATADIR)"; exit 2; }

rtl_stub: ## Generate RTL core and top wrapper
	$(Q)$(PYTHON) -m flexsoc.backend.rtl_stub_gen $(OVERWRITE) --top $(TOP) --hjson-file $(DATADIR)/$(TOP).hjson --interface $(REG_ITF) --output-dir $(RTLDIR)

top_from_core: ## Regenerate $(TOP).sv from edited $(TOP)_core.sv
	$(call _require_var,TOP)
	$(Q)$(PYTHON) -m flexsoc.backend.top_from_core $(OVERWRITE) --top $(TOP) --rtl-dir $(RTLDIR) --interface $(REG_ITF)

ip_start: setup hjson reg doc rtl_stub flist lint setup_model tests_gen setup_tb sim ## Bootstrap a complete IP run

RTL_COMMON_LIST ?= $(RTLDIR)/rtl_common.f
RTL_IP_LIST ?= $(RTLDIR)/rtl_ip.f
RTL_FILELISTS = -f $(RTL_COMMON_LIST) -f $(RTL_IP_LIST)
RTL_FILELIST_ARGS = --filelist $(RTL_COMMON_LIST) --filelist $(RTL_IP_LIST)
FLIST_LOG ?= $(LOGDIR)/$(TOP)_flist.log
FLIST_ROOT ?= $(REPO_ROOT)
FLIST_TOP_FILE ?= $(RTLDIR)/$(TOP).sv
FLIST_COMMON_ARGS = \
	--common-root "$(INC_PKGS)" \
	--common-root "$(INC_PRIM)" \
	--common-root "$(INC_PRIM_OT)" \
	--common-root "$(INC_TLUL)"
FLIST_SEARCH_ARGS = \
	--search-root "$(INC_PKGS)" \
	--search-root "$(INC_PRIM)" \
	--search-root "$(INC_PRIM_OT)" \
	--search-root "$(INC_TLUL)"
FLIST_CMD = $(PYTHON) -m flexsoc.backend.slang_tools flist --slang "$(SLANG)" --root "$(FLIST_ROOT)" $(FLIST_SEARCH_ARGS) --top-file "$(FLIST_TOP_FILE)" --top "$(TOP)" --extra-args "$(SLANG_ARGS)" --common-out "$(RTL_COMMON_LIST)" --ip-out "$(RTL_IP_LIST)" $(FLIST_COMMON_ARGS)

flist: setup ## Generate Slang-ordered common/IP RTL filelists
	@$(MKDIR) -p $(LOGDIR)
	@log="$(FLIST_LOG)"; status_file="$$log.status"; rm -f "$$status_file"; \
	if [ "$(LIVE)" = "1" ]; then \
		{ $(FLIST_CMD); echo $$? > "$$status_file"; } 2>&1 | tee "$$log"; \
		status=$$(cat "$$status_file"); rm -f "$$status_file"; \
	else \
		$(FLIST_CMD) > "$$log" 2>&1; status=$$?; \
	fi; \
	if [ $$status -ne 0 ]; then echo "[flist] failed. log: $$log"; [ "$(LIVE)" = "1" ] || cat "$$log"; exit $$status; fi; \
	[ -s "$$log" ] || rm -f "$$log"
	@rm -f $(RTLDIR)/rtl_list.f $(RTLDIR)/rtl_lint.f

driver: ## Generate C driver files from HJSON
	$(Q)$(PYTHON) $(REGTOOL) -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) -m flexsoc.backend.driver_gen -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR)

fetch: ## Fetch or update a vendored dependency
	$(Q)$(PYTHON) $(VENDOR_TOOL) --update $(REPO_ROOT)/vendor/$(VENDOR).vendor.hjson

ip_flow: reg doc ## Run regression through formal/synthesis/signoff, then report the run
	@$(BACKEND_MAKE) flist
	@$(BACKEND_MAKE) lint_suite
	@$(BACKEND_MAKE) regression
	@$(BACKEND_MAKE) coverage_detail
	@$(BACKEND_MAKE) formal
	@$(BACKEND_MAKE) setup_sdc
	@$(BACKEND_MAKE) setup_syn
	@$(BACKEND_MAKE) syn
	@$(BACKEND_MAKE) setup_eqy
	@$(BACKEND_MAKE) eqy
	@$(BACKEND_MAKE) signoff_corners
	@$(BACKEND_MAKE) manifest
	@$(BACKEND_MAKE) manifest_show
	-@$(BACKEND_MAKE) metrics
	-@$(BACKEND_MAKE) check

ip_flow_noreg: ## Run the standard closure without regenerating registers
	@$(BACKEND_MAKE) flist
	@$(BACKEND_MAKE) lint_suite
	@$(BACKEND_MAKE) regression
	@$(BACKEND_MAKE) coverage_detail
	@$(BACKEND_MAKE) formal
	@$(BACKEND_MAKE) setup_sdc
	@$(BACKEND_MAKE) setup_syn
	@$(BACKEND_MAKE) syn
	@$(BACKEND_MAKE) setup_eqy
	@$(BACKEND_MAKE) eqy
	@$(BACKEND_MAKE) signoff_corners
	@$(BACKEND_MAKE) manifest
	@$(BACKEND_MAKE) manifest_show
	-@$(BACKEND_MAKE) metrics
	-@$(BACKEND_MAKE) check

ip_flow_all: ip_flow pnr pnr_gui ## Run the standard IP flow plus PnR

# ============================================================================
# 5. Linting
# Supports the aggregate lint target and filtered diagnostics by kind.
# ============================================================================
##@ Linting
SLANG ?= slang
SLANG_HIER ?= slang-hier
VERILATOR ?= verilator

LINT_TOOL ?= both
LINT_PART ?= ip
LINT_LOGDIR ?= $(LOGDIR)/lint
LINT_RAW_LOG ?= $(LINT_LOGDIR)/raw/$(TOP)_lint_$(LINT_TOOL)_$(LINT_KIND)_raw.log
LINT_FULL_LOG ?= $(LINT_LOGDIR)/$(TOP)_lint_$(LINT_TOOL)_$(if $(filter all,$(LINT_KIND)),all,$(LINT_KIND)_all).log
LINT_COMMON_LOG ?= $(LINT_LOGDIR)/$(TOP)_lint_$(LINT_TOOL)_$(LINT_KIND)_common.log
LINT_IP_LOG ?= $(LINT_LOGDIR)/$(TOP)_lint_$(LINT_TOOL)_$(LINT_KIND)_ip.log

VERILATOR_LINT_BASE ?= --lint-only --sv -Wno-fatal
VERILATOR_FOCUSED_OFF ?= -Wno-DECLFILENAME -Wno-PINMISSING -Wno-PINCONNECTEMPTY -Wno-PINNOCONNECT -Wno-UNDRIVEN -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM -Wno-WIDTH -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC -Wno-LATCH
SLANG_LINT_BASE ?= --lint-only --single-unit --top $(TOP) -DSYNTHESIS --diag-abs-paths --diag-hierarchy never

LINT_KINDS := latch undriven width unconnected unused

LINT_PATTERN_all := %Warning-|%Error-|warning:|error:
LINT_PATTERN_latch := %Warning-LATCH|\[-Winferred-latch\]|inferred latch
LINT_PATTERN_undriven := %Warning-UNDRIVEN|\[-Wundriven-port\]|undriven port|no driver|not driven
LINT_PATTERN_width := %Warning-(WIDTH|WIDTHEXPAND|WIDTHTRUNC)\b|\[-W(width-trunc|width-expand|port-width-trunc|port-width-expand)\]
LINT_PATTERN_unconnected := %Warning-(PINMISSING|PINCONNECTEMPTY|PINNOCONNECT)\b|\[-W(unconnected-|empty-.*connection)
LINT_PATTERN_unused := %Warning-(UNUSEDSIGNAL|UNUSEDPARAM)\b|\[-Wunused-

VERILATOR_FLAGS_all := -Wall
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

LINT_ARGS = TOP="$(TOP)" HOST="$(HOST)" FORCE="$(FORCE)" RUN_ID="$(RUN_ID)" RUN_TOP="$(RUN_TOP)" WORKSPACE="$(WORKSPACE)" LINT_PART="$(LINT_PART)"

# Compatibility aliases used by compile_v/compile_sv prerequisites.
lint_v lint_sv: lint

lint: flist ## Run Slang lint first, then Verilator lint
	@set -eu; \
	tools="$(LINT_TOOL)"; \
	case "$$tools" in auto|both) tools="slang verilator" ;; slang|verilator) ;; *) echo "Unsupported LINT_TOOL=$$tools. Use both, slang, or verilator."; exit 2 ;; esac; \
	for tool in $$tools; do \
		$(BACKEND_MAKE) _lint_run $(LINT_ARGS) LINT_TOOL="$$tool" \
			LINT_KIND=all LINT_PATTERN="$(LINT_PATTERN_all)" \
			LINT_VERILATOR_FLAGS="$(VERILATOR_FLAGS_all)" LINT_SLANG_FLAGS="$(SLANG_FLAGS_all)"; \
	done

lint_slang: flist ## Run Slang HDL lint
	@$(BACKEND_MAKE) _lint_run $(LINT_ARGS) LINT_TOOL=slang LINT_KIND=all LINT_PATTERN="$(LINT_PATTERN_all)" LINT_VERILATOR_FLAGS="$(VERILATOR_FLAGS_all)" LINT_SLANG_FLAGS="$(SLANG_FLAGS_all)"

lint_verilator: flist ## Run Verilator HDL lint
	@$(BACKEND_MAKE) _lint_run $(LINT_ARGS) LINT_TOOL=verilator LINT_KIND=all LINT_PATTERN="$(LINT_PATTERN_all)" LINT_VERILATOR_FLAGS="$(VERILATOR_FLAGS_all)" LINT_SLANG_FLAGS="$(SLANG_FLAGS_all)"

lint_slang_suite: flist ## Run the full Slang lint suite
	@set -eu; \
	for kind in all latch undriven width unconnected unused; do \
		case "$$kind" in \
			all) pattern='$(LINT_PATTERN_all)'; vflags='$(VERILATOR_FLAGS_all)'; sflags='$(SLANG_FLAGS_all)' ;; \
			latch) pattern='$(LINT_PATTERN_latch)'; vflags='$(VERILATOR_FLAGS_latch)'; sflags='$(SLANG_FLAGS_latch)' ;; \
			undriven) pattern='$(LINT_PATTERN_undriven)'; vflags='$(VERILATOR_FLAGS_undriven)'; sflags='$(SLANG_FLAGS_undriven)' ;; \
			width) pattern='$(LINT_PATTERN_width)'; vflags='$(VERILATOR_FLAGS_width)'; sflags='$(SLANG_FLAGS_width)' ;; \
			unconnected) pattern='$(LINT_PATTERN_unconnected)'; vflags='$(VERILATOR_FLAGS_unconnected)'; sflags='$(SLANG_FLAGS_unconnected)' ;; \
			unused) pattern='$(LINT_PATTERN_unused)'; vflags='$(VERILATOR_FLAGS_unused)'; sflags='$(SLANG_FLAGS_unused)' ;; \
		esac; \
		$(BACKEND_MAKE) _lint_run $(LINT_ARGS) LINT_TOOL=slang LINT_KIND="$$kind" LINT_PATTERN="$$pattern" LINT_VERILATOR_FLAGS="$$vflags" LINT_SLANG_FLAGS="$$sflags"; \
	done

lint_verilator_suite: flist ## Run the full Verilator lint suite
	@set -eu; \
	for kind in all latch undriven width unconnected unused; do \
		case "$$kind" in \
			all) pattern='$(LINT_PATTERN_all)'; vflags='$(VERILATOR_FLAGS_all)'; sflags='$(SLANG_FLAGS_all)' ;; \
			latch) pattern='$(LINT_PATTERN_latch)'; vflags='$(VERILATOR_FLAGS_latch)'; sflags='$(SLANG_FLAGS_latch)' ;; \
			undriven) pattern='$(LINT_PATTERN_undriven)'; vflags='$(VERILATOR_FLAGS_undriven)'; sflags='$(SLANG_FLAGS_undriven)' ;; \
			width) pattern='$(LINT_PATTERN_width)'; vflags='$(VERILATOR_FLAGS_width)'; sflags='$(SLANG_FLAGS_width)' ;; \
			unconnected) pattern='$(LINT_PATTERN_unconnected)'; vflags='$(VERILATOR_FLAGS_unconnected)'; sflags='$(SLANG_FLAGS_unconnected)' ;; \
			unused) pattern='$(LINT_PATTERN_unused)'; vflags='$(VERILATOR_FLAGS_unused)'; sflags='$(SLANG_FLAGS_unused)' ;; \
		esac; \
		$(BACKEND_MAKE) _lint_run $(LINT_ARGS) LINT_TOOL=verilator LINT_KIND="$$kind" LINT_PATTERN="$$pattern" LINT_VERILATOR_FLAGS="$$vflags" LINT_SLANG_FLAGS="$$sflags"; \
	done

lint_suite: flist ## Run the full Slang suite first, then the full Verilator suite
	@$(BACKEND_MAKE) lint_slang_suite $(LINT_ARGS)
	@$(BACKEND_MAKE) lint_verilator_suite $(LINT_ARGS)

lint_latch lint_undriven lint_width lint_unconnected lint_unused: lint_%: flist
	@set -eu; \
	tools="$(LINT_TOOL)"; \
	case "$$tools" in auto|both) tools="slang verilator" ;; slang|verilator) ;; *) echo "Unsupported LINT_TOOL=$$tools. Use both, slang, or verilator."; exit 2 ;; esac; \
	for tool in $$tools; do \
		$(BACKEND_MAKE) _lint_run $(LINT_ARGS) LINT_TOOL="$$tool" \
			LINT_KIND="$*" LINT_PATTERN="$(LINT_PATTERN_$*)" \
			LINT_VERILATOR_FLAGS="$(VERILATOR_FLAGS_$*)" LINT_SLANG_FLAGS="$(SLANG_FLAGS_$*)"; \
	done

_lint_run:
	@label="lint_$(LINT_TOOL)$(if $(filter-out all,$(LINT_KIND)),_$(LINT_KIND),)"; printf "%b\n" "$(ORANGE)[$$label]$(RESET) $(BLUE)$(TOP) part=$(LINT_PART)$(RESET)"
	@mkdir -p $(LINT_LOGDIR) $(LINT_LOGDIR)/raw
	@if [ ! -f "$(RTL_COMMON_LIST)" ] || [ ! -f "$(RTL_IP_LIST)" ]; then echo "missing filelists. Run: fx flist"; exit 2; fi
	@tool="$(LINT_TOOL)"; \
	if [ "$$tool" = "verilator" ]; then \
		extra="$(LINT_VERILATOR_FLAGS)"; \
		if [ "$(LINT_KIND)" != "all" ]; then extra="$(VERILATOR_FOCUSED_OFF) $$extra"; fi; \
		cmd="$(VERILATOR) $(VERILATOR_LINT_BASE) $$extra -f $(RTL_COMMON_LIST) -f $(RTL_IP_LIST) --top-module $(TOP)"; \
	elif [ "$$tool" = "slang" ]; then \
		if [ -x "$(SLANG)" ]; then slang_cmd="$(SLANG)"; elif command -v slang >/dev/null 2>&1; then slang_cmd="slang"; else echo "slang not found. Run: make install-slang"; exit 2; fi; \
		cmd="$$slang_cmd $(SLANG_LINT_BASE) $(LINT_SLANG_FLAGS) -f $(RTL_COMMON_LIST) -f $(RTL_IP_LIST)"; \
	else \
		echo "Unsupported LINT_TOOL=$$tool. Use slang or verilator."; exit 2; \
	fi; \
	printf "%b\n" "$(BLUE)raw: $(LINT_RAW_LOG)$(RESET)"; \
	status_file="$(LINT_RAW_LOG).status"; rm -f "$$status_file"; \
	if [ "$(LIVE)" = "1" ]; then \
		{ echo "$$cmd"; eval "$$cmd"; echo $$? > "$$status_file"; } 2>&1 | tee "$(LINT_RAW_LOG)"; \
		status=$$(cat "$$status_file"); rm -f "$$status_file"; \
	else \
		echo "$$cmd" > "$(LINT_RAW_LOG)"; \
		eval "$$cmd" >> "$(LINT_RAW_LOG)" 2>&1; status=$$?; \
	fi; \
	if [ "$(LINT_KIND)" = "all" ]; then \
		cp "$(LINT_RAW_LOG)" "$(LINT_FULL_LOG)"; \
		printf "%b\n" "$(BLUE)log: $(LINT_FULL_LOG)$(RESET)"; \
		if [ $$status -ne 0 ]; then \
			printf "%b\n" "$(RED)[lint] failed$(RESET) $(BLUE)log: $(LINT_FULL_LOG)$(RESET)"; \
			[ "$(LIVE)" = "1" ] || tail -n 80 "$(LINT_FULL_LOG)"; \
			exit $$status; \
		fi; \
		printf "%b\n" "$(GREEN)[lint] passed$(RESET) $(BLUE)log: $(LINT_FULL_LOG)$(RESET)"; \
		exit 0; \
	fi; \
	if [ $$status -ne 0 ]; then \
		printf "%b\n" "$(RED)[lint] tool failed$(RESET) $(BLUE)raw: $(LINT_RAW_LOG)$(RESET)"; \
		[ "$(LIVE)" = "1" ] || tail -n 80 "$(LINT_RAW_LOG)"; \
		exit $$status; \
	fi; \
	grep -E -i "$(LINT_PATTERN)" "$(LINT_RAW_LOG)" | grep -vF "$(RTLDIR)" > "$(LINT_COMMON_LOG)" || true; \
	grep -E -i "$(LINT_PATTERN)" "$(LINT_RAW_LOG)" | grep -F "$(RTLDIR)" > "$(LINT_IP_LOG)" || true; \
	common_count=$$(wc -l < "$(LINT_COMMON_LOG)" | tr -d ' '); \
	ip_count=$$(wc -l < "$(LINT_IP_LOG)" | tr -d ' '); \
	case "$(LINT_PART)" in \
		common) count="$$common_count"; selected="$(LINT_COMMON_LOG)" ;; \
		ip) count="$$ip_count"; selected="$(LINT_IP_LOG)" ;; \
		all) count=$$((common_count + ip_count)); selected="$(LINT_FULL_LOG)"; { printf "# common diagnostics\n"; cat "$(LINT_COMMON_LOG)"; printf "\n# ip diagnostics\n"; cat "$(LINT_IP_LOG)"; } > "$$selected" ;; \
		*) echo "Unsupported LINT_PART=$(LINT_PART). Use ip, common, or all."; exit 2 ;; \
	esac; \
	if [ "$(LINT_PART)" != "all" ]; then cp "$$selected" "$(LINT_FULL_LOG)"; fi; \
	if [ $$count -gt 0 ]; then \
		printf "%b\n" "$(ORANGE)[lint]$(RESET) $(BLUE)found $$count $(LINT_KIND) diagnostic line(s)$(RESET)"; \
		printf "%b\n" "$(BLUE)filtered: $$selected$(RESET)"; \
		printf "%b\n" "$(BLUE)raw: $(LINT_RAW_LOG)$(RESET)"; \
		[ "$(LIVE)" = "1" ] && { printf "\n"; cat "$$selected"; } || true; \
	else \
		printf "No $(LINT_KIND) diagnostics for $(LINT_PART).\n" > "$$selected"; \
		cp "$$selected" "$(LINT_FULL_LOG)"; \
		printf "%b\n" "$(GREEN)[lint] no $(LINT_KIND) diagnostics for $(LINT_PART)$(RESET) $(BLUE)log: $$selected$(RESET)"; \
		printf "%b\n" "$(BLUE)raw: $(LINT_RAW_LOG)$(RESET)"; \
	fi

SLANG_ROOT ?= $(REPO_ROOT)
SLANG_TOP_FILE ?= $(RTLDIR)/$(TOP).sv
SLANG_TOP ?=
SLANG_ARGS ?=
SLANG_SEARCH_ARGS ?=
SLANG_OUTDIR ?= $(OUTROOT)/analysis/slang
SLANG_HIER_LOG ?= $(SLANG_OUTDIR)/$(TOP)_hier.txt
SLANG_AST_JSON ?= $(SLANG_OUTDIR)/$(TOP)_ast.json
SLANG_AST_SCOPE ?=
SLANG_FLIST_OUT ?= $(RTLDIR)/rtl_slang.f
SLANG_TOP_ARG = $(if $(strip $(SLANG_TOP)),--top $(SLANG_TOP),)
SLANG_SCOPE_ARG = $(if $(strip $(SLANG_AST_SCOPE)),--scope $(SLANG_AST_SCOPE),)

slang_hier: ## Generate hierarchy text with slang-hier from a top file and recursive root
	$(Q)$(PYTHON) -m flexsoc.backend.slang_tools hier \
		--slang-hier "$(SLANG_HIER)" \
		--root "$(SLANG_ROOT)" \
		$(SLANG_SEARCH_ARGS) \
		--top-file "$(SLANG_TOP_FILE)" \
		$(SLANG_TOP_ARG) \
		--extra-args "$(SLANG_ARGS)" \
		--output "$(SLANG_HIER_LOG)"

slang_ast: ## Generate Slang AST JSON from a top file and recursive root
	$(Q)$(PYTHON) -m flexsoc.backend.slang_tools ast \
		--slang "$(SLANG)" \
		--root "$(SLANG_ROOT)" \
		$(SLANG_SEARCH_ARGS) \
		--top-file "$(SLANG_TOP_FILE)" \
		$(SLANG_TOP_ARG) \
		$(SLANG_SCOPE_ARG) \
		--extra-args "$(SLANG_ARGS)" \
		--json-out "$(SLANG_AST_JSON)"

slang_flist: ## Generate a trimmed topological RTL filelist with Slang
	$(Q)$(PYTHON) -m flexsoc.backend.slang_tools flist \
		--slang "$(SLANG)" \
		--root "$(SLANG_ROOT)" \
		$(SLANG_SEARCH_ARGS) \
		--top-file "$(SLANG_TOP_FILE)" \
		$(SLANG_TOP_ARG) \
		--extra-args "$(SLANG_ARGS)" \
		--synthesis \
		--output "$(SLANG_FLIST_OUT)"

# ============================================================================
# 6. Functional design verification
# ============================================================================
##@ Simulation
setup_tb: setup flist ## Generate a SystemVerilog testbench scaffold
	@mkdir -p $(TB_SV_DIR)
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
	$(Q)$(PYTHON) -m flexsoc.backend.setup_cocotb $(OVERWRITE) \
		--top $(TOP) --itf $(REG_ITF) \
		--rtl-dir $(RTLDIR) --output $(TBDIR)/cocotb \
		--sim $(COMPILER)

setup_model: setup ## Generate/update Python model and CSR regmap scaffolds
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(MODELDIR) $(TEST_ROOT)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_model $(OVERWRITE) \
		--top $(TOP) \
		--output-dir $(MODELDIR) \
		--data-dir $(DATADIR) \
		--rtl-dir $(RTLDIR)


tests_gen: setup ## Recreate all editable tests plus machine-owned coverage stimulus
	$(call _require_var,TOP)
	@if [ ! -f "$(MODELDIR)/$(TOP)_tests.py" ]; then \
		echo "ERROR: missing model test scaffold; run: fx setup_model"; exit 1; \
	fi
	$(Q)$(RM) -rf $(TEST_ROOT)
	$(Q)$(MKDIR) -p $(TEST_ROOT)
	$(Q)FLEXSOC_SEED="$(SEED)" $(PYTHON) $(MODELDIR)/$(TOP)_tests.py --tests-dir $(TEST_ROOT)
	$(Q)if [ -f "$(MODELDIR)/$(TOP)_regmap_tests.py" ]; then $(PYTHON) "$(MODELDIR)/$(TOP)_regmap_tests.py" --tests-dir "$(TEST_ROOT)"; fi

test_gen: setup ## Generate TEST_NAME plus the machine-owned coverage stimulus
	$(call _require_var,TOP)
	@if [ ! -f "$(MODELDIR)/$(TOP)_tests.py" ]; then \
		echo "ERROR: missing model test scaffold; run: fx setup_model"; exit 1; \
	fi
	$(Q)$(MKDIR) -p $(TEST_ROOT)
	@if [ "$(TEST_NAME)" = "auto_toggle" ] && [ -f "$(MODELDIR)/$(TOP)_regmap_tests.py" ]; then \
		$(PYTHON) "$(MODELDIR)/$(TOP)_regmap_tests.py" --tests-dir "$(TEST_ROOT)" --test auto_toggle; \
	else \
		FLEXSOC_SEED="$(SEED)" $(PYTHON) "$(MODELDIR)/$(TOP)_tests.py" --tests-dir "$(TEST_ROOT)" --test "$(TEST_NAME)"; \
		if [ -f "$(MODELDIR)/$(TOP)_regmap_tests.py" ]; then $(PYTHON) "$(MODELDIR)/$(TOP)_regmap_tests.py" --tests-dir "$(TEST_ROOT)"; fi; \
	fi


_require_test_vectors:
	@if [ ! -d "$(TEST_ROOT)/$(TEST_NAME)" ]; then \
		echo "ERROR: missing vector test: $(TEST_ROOT)/$(TEST_NAME)"; \
		echo "Run: fx tests_gen or fx test_gen --set TEST_NAME=$(TEST_NAME)"; \
		exit 1; \
	fi

tests: ## List generated vector tests without regenerating them
	@set -eu; \
	printf '\n$(BLUE)Available vector tests in $(TEST_ROOT):$(RESET)\n'; \
	if [ ! -d "$(TEST_ROOT)" ]; then \
		echo "  no tests directory found; run: fx tests_gen"; \
		exit 0; \
	fi; \
	found=0; \
	for dir in "$(TEST_ROOT)"/*; do \
		[ -d "$$dir" ] || continue; \
		found=1; \
		name=$$(basename "$$dir"); \
		printf '  $(ORANGE)%s$(RESET)\n' "$$name"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "  no tests found; run: fx tests_gen"; \
	fi

regmap_py: setup ## Regenerate dv/functional/model/<top>_regmap.py from HJSON
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(MODELDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_model_regmap --top $(TOP) --data-dir $(DATADIR) --model-dir $(MODELDIR) --force

compile: $(if $(filter v,$(VSV)),compile_v,compile_sv) ## Compile the current testbench
sim:     $(if $(filter v,$(VSV)),sim_v,sim_sv) ## Run simulation


sim_tests: ## Run every generated SystemVerilog vector test
	@set -eu; \
	if [ ! -d "$(TEST_ROOT)" ]; then \
		echo "ERROR: no vector tests found in $(TEST_ROOT)"; \
		echo "Run: fx tests_gen"; \
		exit 1; \
	fi; \
	if [ ! -f "$(TB_SV_DIR)/$(TESTBENCH).sv" ]; then \
		echo "ERROR: SystemVerilog testbench not found: $(TB_SV_DIR)/$(TESTBENCH).sv"; \
		echo "Run: fx setup_tb --force"; \
		exit 1; \
	fi; \
	found=0; \
	for dir in "$(TEST_ROOT)"/*; do \
		[ -d "$$dir" ] || continue; \
		found=1; \
		test=$$(basename "$$dir"); \
		printf '\n$(ORANGE)[sim_tests]$(RESET) $(BLUE)TEST_NAME=%s$(RESET)\n' "$$test"; \
		$(MAKE) --no-print-dir -f $(lastword $(MAKEFILE_LIST)) sim TEST_NAME="$$test"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "ERROR: no vector tests found in $(TEST_ROOT)"; \
		exit 1; \
	fi

compile_v: flist ## Compile Verilog simulation
	@printf "%b\n" "$(ORANGE)[compile_v]$(RESET) $(BLUE)compile Verilog testbench$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)$(MKDIR) -p $(SIMDIR) $(LOGDIR)
	$(Q)iverilog $(IVERILOG_FLAGS) \
		-o $(SIMDIR)/$(TESTBENCH).vvp \
		$(TB_SV_DIR)/$(TESTBENCH).sv \
		> $(LOGDIR)/$(TOP)_compile.log 2>&1
else
	$(Q)$(MKDIR) -p $(SIMDIR)/$(COMPILER) $(LOGDIR)
	$(Q)verilator $(VERILATOR_FLAGS) $(if $(filter 1,$(COVERAGE)),--coverage,) -I$(TB_SV_DIR) -I$(TB_SV_DIR)/drivers \
		$(RTLDIR)/$(TOP).v \
		$(TB_SV_DIR)/$(TESTBENCH).sv \
		--top-module $(TESTBENCH) \
		> $(LOGDIR)/$(TOP)_compile.log 2>&1
endif

sim_v: compile_v _require_test_vectors ## Run Verilog simulation
	@printf "%b\n" "$(ORANGE)[sim_v]$(RESET) $(BLUE)run Verilog simulation$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp +WAVE=$(WAVE_FILE) $(SIM_PLUSARGS) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)if [ "$(COVERAGE)" = "1" ]; then $(MKDIR) -p "$(dir $(SV_COVERAGE_FILE))"; fi
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) +WAVE=$(WAVE_FILE) $(SIM_PLUSARGS) $(VERILATOR_RUNTIME_ARGS) \
		> $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

compile_sv: flist ## Compile SystemVerilog simulation
	@printf "%b\n" "$(ORANGE)[compile_sv]$(RESET) $(BLUE)compile SystemVerilog testbench$(RESET)"
	@printf "%b\n" "$(BLUE)log: $(SV_COMPILE_LOG)$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)$(MKDIR) -p $(SIMDIR) $(VERIFY_LOGDIR)
	$(Q)iverilog $(IVERILOG_FLAGS) \
		-o $(SIMDIR)/$(TESTBENCH).vvp \
		$(TB_SV_DIR)/$(TESTBENCH).sv \
		> $(SV_COMPILE_LOG) 2>&1
else
	$(Q)$(MKDIR) -p $(SIMDIR)/$(COMPILER) $(VERIFY_LOGDIR)
	$(Q)verilator $(VERILATOR_FLAGS) $(if $(filter 1,$(COVERAGE)),--coverage,) \
	  -I$(TB_DIR) -I$(SV_TB_DIR) \
		$(RTL_FILELISTS) \
		$(TB_SV_DIR)/$(TESTBENCH).sv \
		--top-module $(TESTBENCH) \
		> $(SV_COMPILE_LOG) 2>&1
endif

sim_sv: compile_sv _require_test_vectors ## Run SystemVerilog simulation
	@printf "%b\n" "$(ORANGE)[sim_sv]$(RESET) $(BLUE)run SystemVerilog test TEST_NAME=$(TEST_NAME)$(RESET)"
	@printf "%b\n" "$(BLUE)log: $(SV_SIM_LOG)$(RESET)"
ifeq ($(COMPILER),iverilog)
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp +WAVE=$(WAVE_FILE) $(SIM_PLUSARGS) \
		> $(SV_SIM_LOG) 2>&1
else
	$(Q)if [ "$(COVERAGE)" = "1" ]; then $(MKDIR) -p "$(dir $(SV_COVERAGE_FILE))"; fi
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) +WAVE=$(WAVE_FILE) $(SIM_PLUSARGS) $(VERILATOR_RUNTIME_ARGS) \
		> $(SV_SIM_LOG) 2>&1
endif

cocotb: _require_test_vectors ## Run one cocotb vector test selected by TEST_NAME
	$(Q)$(MKDIR) -p $(VERIFY_LOGDIR)
	$(Q)if [ ! -f "$(TBDIR)/cocotb/Makefile" ]; then \
		echo "cocotb scaffold not found: $(TBDIR)/cocotb/Makefile"; \
		echo "Generate it first, for example:"; \
		echo "  fx setup_cocotb --set TOP=$(TOP) --set RUN_TOP=$(RUN_TOP) --set RUN_ID=$(RUN_ID)"; \
		exit 1; \
	fi
	$(Q)if [ ! -f "$(COCOTB_WRAPPER)" ]; then \
		echo "cocotb wrapper not found: $(COCOTB_WRAPPER)"; exit 1; \
	fi
	$(Q)if [ -z "$(strip $(COCOTB_RTL_SOURCES))" ]; then \
		echo "cocotb RTL sources not found in $(RTL_COMMON_LIST) and $(RTL_IP_LIST)"; \
		echo "Run: fx flist"; exit 1; \
	fi
	$(Q)$(PYTHON) -c "import importlib.util, sys; sys.exit(0 if importlib.util.find_spec('cocotb_tools') else 1)" || { \
		echo "cocotb is not installed in this environment."; \
		echo "Run uv sync from the repository root, then retry."; \
		exit 1; \
	}
	@printf "%b\n" "$(ORANGE)[cocotb]$(RESET) $(BLUE)run cocotb test TEST_NAME=$(TEST_NAME) SEED=$(SEED)$(RESET)"
	@printf "%b\n" "$(BLUE)log: $(COCOTB_LOG)$(RESET)"
	$(Q)if [ "$(COVERAGE)" = "1" ] && [ "$(COMPILER)" = "verilator" ]; then $(MKDIR) -p "$(dir $(COCOTB_COVERAGE_FILE))"; fi
	$(Q)if [ "$(LIVE)" = "1" ]; then \
		$(MAKE) --no-print-dir -C $(TBDIR)/cocotb TEST_NAME="$(TEST_NAME)" SEED="$(SEED)" HDL_COVERAGE="$(COVERAGE)" COVERAGE_FILE="$(COCOTB_COVERAGE_FILE)" WAVE_FILE="$(WAVE_FILE)" WAVES=$(COCOTB_WAVES) VERILOG_SOURCES="$(COCOTB_RTL_SOURCES) $(COCOTB_WRAPPER)" 2>&1 | tee $(COCOTB_LOG); \
	else \
		$(MAKE) --no-print-dir -C $(TBDIR)/cocotb TEST_NAME="$(TEST_NAME)" SEED="$(SEED)" HDL_COVERAGE="$(COVERAGE)" COVERAGE_FILE="$(COCOTB_COVERAGE_FILE)" WAVE_FILE="$(WAVE_FILE)" WAVES=$(COCOTB_WAVES) VERILOG_SOURCES="$(COCOTB_RTL_SOURCES) $(COCOTB_WRAPPER)" > $(COCOTB_LOG) 2>&1; \
	fi


cocotb_tests: ## Run every generated cocotb vector test
	@set -eu; \
	if [ ! -d "$(TEST_ROOT)" ]; then \
		echo "ERROR: no vector tests found in $(TEST_ROOT)"; \
		echo "Run: fx tests_gen"; \
		exit 1; \
	fi; \
	if [ ! -f "$(TBDIR)/cocotb/Makefile" ]; then \
		echo "ERROR: cocotb scaffold not found: $(TBDIR)/cocotb/Makefile"; \
		echo "Run: fx setup_cocotb --force"; \
		exit 1; \
	fi; \
	found=0; \
	for dir in "$(TEST_ROOT)"/*; do \
		[ -d "$$dir" ] || continue; \
		found=1; \
		test=$$(basename "$$dir"); \
		printf '\n$(ORANGE)[cocotb_tests]$(RESET) $(BLUE)TEST_NAME=%s$(RESET)\n' "$$test"; \
		$(MAKE) --no-print-dir -f $(lastword $(MAKEFILE_LIST)) cocotb TEST_NAME="$$test"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "ERROR: no vector tests found in $(TEST_ROOT)"; \
		exit 1; \
	fi

regression: ## Run every existing vector test on each selected backend and collect coverage
	@set -eu; \
	if [ ! -d "$(TEST_ROOT)" ]; then \
		echo "ERROR: no vector tests found in $(TEST_ROOT)"; \
		echo "Run: fx tests_gen, or load an IP package containing saved vectors"; \
		exit 1; \
	fi; \
	if [ ! -f "$(TB_SV_DIR)/$(TESTBENCH).sv" ]; then \
		echo "ERROR: SystemVerilog testbench not found: $(TB_SV_DIR)/$(TESTBENCH).sv"; \
		echo "Run: fx setup_tb, or load an IP package containing the saved testbench"; \
		exit 1; \
	fi; \
	case " $(REGRESSION_BACKENDS) " in *" cocotb "*) \
		if [ ! -f "$(TBDIR)/cocotb/Makefile" ]; then \
			echo "ERROR: cocotb scaffold not found: $(TBDIR)/cocotb/Makefile"; \
			echo "Run: fx setup_cocotb, or load an IP package containing the saved cocotb scaffold"; \
			exit 1; \
		fi ;; \
	esac; \
	rm -rf "$(COVERAGEDIR)" "$(REGRESSION_LOGDIR)"; \
	mkdir -p "$(COVERAGEDIR)" "$(REGRESSION_LOGDIR)"; \
	tests=""; \
	for dir in "$(TEST_ROOT)"/*; do \
		[ -d "$$dir" ] || continue; \
		tests="$$tests $$(basename "$$dir")"; \
	done; \
	if [ -z "$$tests" ]; then \
		echo "ERROR: regression found no tests in $(TEST_ROOT)"; \
		exit 2; \
	fi; \
	total=0; failed=0; \
	for backend in $(REGRESSION_BACKENDS); do \
		case "$$backend" in \
			sv) target=sim ;; \
			cocotb) target=cocotb ;; \
			*) echo "ERROR: unsupported regression backend: $$backend (use sv or cocotb)"; exit 2 ;; \
		esac; \
		for test in $$tests; do \
			total=$$((total + 1)); \
			test_seed="$(SEED)"; \
			case "$$test" in random_seed_*) test_seed=$${test#random_seed_} ;; esac; \
			printf '\n$(ORANGE)[regression]$(RESET) $(BLUE)backend=%s test=%s$(RESET)\n' "$$backend" "$$test"; \
			if $(BACKEND_MAKE) $$target TOP="$(TOP)" RUN_TOP="$(RUN_TOP)" RUN_ID="$(RUN_ID)" WORKSPACE="$(WORKSPACE)" \
				N_CLOCKS="$(N_CLOCKS)" CLOCK_DOMAINS="$(CLOCK_DOMAINS)" CLOCK_RELATIONSHIPS="$(CLOCK_RELATIONSHIPS)" COMPILER="$(COMPILER)" TEST_NAME="$$test" SEED="$$test_seed" COVERAGE=1 \
				WAVE_FILE="$(SIMDIR)/$(TESTBENCH)_$${backend}_$${test}.$(WAVE_EXT)" \
				VERIFY_LOGDIR="$(REGRESSION_LOGDIR)/$$backend"; then \
				printf '$(GREEN)  PASS$(RESET) %s/%s\n' "$$backend" "$$test"; \
			else \
				failed=$$((failed + 1)); \
				printf '$(RED)  FAIL$(RESET) %s/%s\n' "$$backend" "$$test"; \
			fi; \
		done; \
	done; \
	coverage_failed=0; \
	if [ "$(COMPILER)" = "verilator" ]; then \
		if ! $(BACKEND_MAKE) coverage TOP="$(TOP)" RUN_TOP="$(RUN_TOP)" RUN_ID="$(RUN_ID)" WORKSPACE="$(WORKSPACE)"; then \
			coverage_failed=1; \
		fi; \
	else \
		printf '$(ORANGE)[regression]$(RESET) coverage skipped: COMPILER=$(COMPILER)\n'; \
	fi; \
	printf '\n$(BLUE)[regression] total=%s failed=%s$(RESET)\n' "$$total" "$$failed"; \
	if [ "$$failed" -ne 0 ] || [ "$$coverage_failed" -ne 0 ]; then exit 1; fi

coverage: ## Merge Verilator coverage and print a scoped summary
	@set -eu; \
	if ! command -v "$(VERILATOR_COVERAGE)" >/dev/null 2>&1; then \
		echo "ERROR: verilator_coverage not found"; \
		exit 2; \
	fi; \
	files=$$(find "$(COVERAGEDIR)" -type f -name '*.dat' ! -name 'merged.dat' 2>/dev/null | sort); \
	if [ -z "$$files" ]; then \
		echo "ERROR: no Verilator coverage data in $(COVERAGEDIR)"; \
		echo "Run: fx regression"; \
		exit 2; \
	fi; \
	mkdir -p "$(COVERAGEDIR)"; \
	$(VERILATOR_COVERAGE) --write "$(COVERAGEDIR)/merged.dat" $$files; \
	tmp=$$(mktemp -d "$(COVERAGEDIR)/.summary.XXXXXX"); \
	trap 'rm -rf "$$tmp"' EXIT INT TERM; \
	$(VERILATOR_COVERAGE) \
		--annotate "$$tmp" \
		--annotate-all \
		--annotate-points \
		--annotate-min 1 \
		"$(COVERAGEDIR)/merged.dat" >/dev/null; \
	$(PYTHON) "$(TOOLSROOT)/coverage_report.py" summary \
		--annotated-dir "$$tmp" \
		--ip-filelist "$(RTLDIR)/rtl_ip.f" \
		--common-filelist "$(RTLDIR)/rtl_common.f" \
		--output "$(COVERAGEDIR)/summary.txt" \
		--json-output "$(COVERAGE_SUMMARY_JSON)"; \
	printf '%b\n' "$(GREEN)[coverage] merged$(RESET) $(BLUE)$(COVERAGEDIR)/merged.dat$(RESET)"; \
	printf '%b\n' "$(BLUE)summary: $(COVERAGEDIR)/summary.txt$(RESET)"; \
	printf '%b\n' "$(BLUE)summary json: $(COVERAGE_SUMMARY_JSON)$(RESET)"


coverage_detail: coverage ## Write uncovered authored-RTL coverage points to a log
	@set -eu; \
	rm -rf "$(COVERAGE_ANNOTATEDDIR)"; \
	mkdir -p "$(COVERAGE_ANNOTATEDDIR)" "$(COVERAGE_LOGDIR)"; \
	$(VERILATOR_COVERAGE) \
		--annotate "$(COVERAGE_ANNOTATEDDIR)" \
		--annotate-all \
		--annotate-points \
		--annotate-min 1 \
		"$(COVERAGEDIR)/merged.dat" >/dev/null; \
	$(PYTHON) "$(TOOLSROOT)/coverage_report.py" detail \
		--annotated-dir "$(COVERAGE_ANNOTATEDDIR)" \
		--ip-filelist "$(RTLDIR)/rtl_ip.f" \
		--common-filelist "$(RTLDIR)/rtl_common.f" \
		--scope design \
		--limit "$(COVERAGE_DETAIL_LIMIT)" \
		--output "$(COVERAGE_DETAIL_LOG)"

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

view_cocotb: ## Open latest cocotb waveform
	@wave=$$(find "$(TBDIR)/cocotb" -type f \( -name "*.fst" -o -name "*.vcd" -o -name "*.ghw" \) 2>/dev/null | sort | tail -n 1); \
	if [ -z "$$wave" ]; then \
		echo "No cocotb waveform found in $(TBDIR)/cocotb."; \
		echo "Run cocotb first, for example:"; \
		echo "  fx cocotb --set TOP=$(TOP) --set RUN_TOP=$(RUN_TOP) --set RUN_ID=$(RUN_ID) --set TEST_NAME=$(TEST_NAME)"; \
		echo "Wave dumping is controlled by COCOTB_WAVES=$(COCOTB_WAVES)."; \
		exit 1; \
	fi; \
	echo "Opening $$wave with $(WAVE_VIEWER)"; \
	case "$(WAVE_VIEWER)" in \
		surfer) $(SURFER_ENV) $(SURFER) "$$wave" ;; \
		gtkwave) $(GTKWAVE) "$$wave" ;; \
		*) echo "Unknown WAVE_VIEWER=$(WAVE_VIEWER). Use surfer or gtkwave."; exit 2 ;; \
	esac

view_syn: ## Reserved synthesis waveform viewer target

plot_postsyn: ## Open post-synthesis graph
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_postsyn.dot 2>/dev/null &

view_presyn: $(if $(filter v,$(VSV)),view_presyn_v,view_presyn_sv) ## Open pre-synthesis graph

view_presyn_v: sv2v ## Open pre-synthesis graph from Verilog
	$(Q)$(MKDIR) -p $(SYNDIR)/plots $(SYNTH_LOGDIR)
	$(Q)$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn' \
		$(RTLDIR)/$(TOP).v > $(SYNTH_LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

view_presyn_sv: ## Open pre-synthesis graph from SV
	$(Q)$(MKDIR) -p $(SYNDIR)/plots $(SYNTH_LOGDIR)
	$(Q)$(YOSYS) -p "\
	read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul -D SYNTHESIS --ignore-assertions \
		-f rtl/rtl_common.f -f rtl/rtl_ip.f --top $(TOP) ; \
	prep -top $(TOP); select -clear; select -module $(MODULE) ; \
	show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn" \
		> $(SYNTH_LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

# Signoff

tb_save: ## Save selected testbench and waveform artifacts
	$(Q)$(MKDIR) -p $(TB_SAVEDIR)/tb $(TB_SAVEDIR)/sim
	$(Q)$(CP) $(TB_SV_DIR)/$(TOP)_tb.sv $(TB_SAVEDIR)/tb/$(TOP)_$(OUTNAME)_tb.sv
	$(Q)$(CP) $(WAVE_FILE) $(TB_SAVEDIR)/sim/$(TOP)_$(OUTNAME)_tb.$(WAVE_EXT)
	$(Q)$(CP) $(SIMDIR)/$(TOP)_tb.gtkw $(TB_SAVEDIR)/sim/$(TOP)_$(OUTNAME)_tb.gtkw

tb_view: ## Open saved testbench waveform
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(TB_SAVEDIR)/sim/$(TOP)_$(OUTNAME)_tb.$(WAVE_EXT) \
		$(TB_SAVEDIR)/sim/$(TOP)_$(OUTNAME)_tb.gtkw &

# ============================================================================
# 8. Synthesis and netlist generation
# ============================================================================
##@ Synthesis
setup_sdc: ## Generate timing constraints
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(CONSTRAINTSDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_sdc $(TOP) $(CLK_PERIOD) -o $(CONSTRAINTSDIR)/$(TOP).sdc

setup_syn: ## Generate Yosys synthesis scripts
	$(call _require_file,$(CONSTRAINTSDIR)/$(TOP).sdc,setup_sdc)
	$(call _require_file,$(RTL_COMMON_LIST),flist)
	$(call _require_file,$(RTL_IP_LIST),flist)
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SYNDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_syn \
		-top $(TOP) -topdir $(RTLDIR) -sdcdir $(CONSTRAINTSDIR) \
		$(RTL_FILELIST_ARGS) \
		-liberty $(LIB_SYN) -clk $(CLK_PERIOD) \
		-target $(TARGET_SYN) -opt $(TARGET_OPT) \
		-o $(SYNDIR)

syn: $(if $(filter v,$(VSV)),syn_v,syn_sv) ## Run synthesis

syn_v: ## Run Verilog synthesis
	$(call _require_file,$(SYNDIR)/synth.ys,setup_syn)
	$(Q)$(MKDIR) -p $(SYNDIR)/plots $(SYNTH_LOGDIR)
	@printf "%b\n" "$(BLUE)log: $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log$(RESET)"
	$(Q)$(YOSYS) $(SYNDIR)/synth.ys > $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log
	$(Q)$(GREP) -Ei '^(Warning:|%Warning-|.*:[0-9]+(:[0-9]+)?:[[:space:]]*warning:)' $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -Ei '^(ERROR:|%Error-|.*:[0-9]+(:[0-9]+)?:[[:space:]]*error:)' $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

syn_sv: ## Run SystemVerilog synthesis
	$(call _require_file,$(SYNDIR)/synth_sv.ys,setup_syn)
	$(Q)$(MKDIR) -p $(SYNDIR)/plots $(SYNTH_LOGDIR)
	@printf "%b\n" "$(BLUE)log: $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log$(RESET)"
	$(Q)$(YOSYS) -s $(SYNDIR)/synth_sv.ys > $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log
	$(Q)$(GREP) -Ei '^(Warning:|%Warning-|.*:[0-9]+(:[0-9]+)?:[[:space:]]*warning:)' $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -Ei '^(ERROR:|%Error-|.*:[0-9]+(:[0-9]+)?:[[:space:]]*error:)' $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log > $(SYNTH_LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

yosys-vgen: ## Convert SV to Verilog with Yosys
	$(Q)$(YOSYS) -p "\
	read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul -D SYNTHESIS --ignore-assertions \
		-f rtl/rtl_common.f -f rtl/rtl_ip.f \
		--top $(TOP); \
	opt -keepdc; \
	bwmuxmap; \
	opt_clean; \
	write_verilog -norename -noattr rtl/$(TOP).v" > /dev/null 2>&1

# Legacy extension point kept explicit. Implement conversion here if SV2V is required.
sv2v: ## Convert SV to Verilog with sv2v
	@true

# ============================================================================
# Formal verification: authored CSR and design properties
# ============================================================================
##@ Formal verification
FORMAL_PROVE_CONFIG ?= $(FORMAL_PROVE_DIR)/$(TOP)_prove.sby
FORMAL_COVER_CONFIG ?= $(FORMAL_COVER_DIR)/$(TOP)_cover.sby
FORMAL_CSR_PROVE_AUTO ?= $(FORMAL_CSR_PROVE_DIR)/$(TOP)_csr_auto_prove.sv
FORMAL_CSR_COVER_AUTO ?= $(FORMAL_CSR_COVER_DIR)/$(TOP)_csr_auto_cover.sv
FORMAL_CSR_PROVE_CONFIG ?= $(FORMAL_CSR_PROVE_RUN_DIR)/$(TOP)_csr_prove.sby
FORMAL_CSR_COVER_CONFIG ?= $(FORMAL_CSR_COVER_RUN_DIR)/$(TOP)_csr_cover.sby

_formal_scaffold:
	$(call _require_var,TOP)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_formal scaffold --top $(TOP) --formal-dir $(FORMALDIR) >/dev/null
	@printf "%b\n" "$(GREEN)[formal]$(RESET) $(FORMALDIR) clocks=$(N_CLOCKS)"

setup_formal: _formal_scaffold ## Create or preserve starter design assertions and covers
	@printf "%b\n" "$(GREEN)[formal]$(RESET) property scaffold ready"

setup_formal_csr_prove: ## Generate shared CSR BMC/prove configuration
	$(call _require_var,TOP)
	$(Q)rm -rf $(FORMAL_CSR_DIR)/generated
	$(Q)$(MKDIR) -p $(FORMAL_CSR_PROVE_DIR) $(FORMAL_CSR_PROVE_RUN_DIR) $(dir $(FORMAL_CSR_PROVE_LOG))
	$(Q)$(PYTHON) -m flexsoc.backend.setup_formal csr \
		--top $(TOP) $(RTL_FILELIST_ARGS) \
		--properties-dir $(FORMAL_CSR_PROVE_DIR) --mode prove \
		--engine "$(FORMAL_PROVE_ENGINE)" --depth $(FORMAL_DEPTH) \
		--bmc-engine "$(FORMAL_BMC_ENGINE)" --bmc-depth $(FORMAL_BMC_DEPTH) --bmc-append $(FORMAL_BMC_APPEND) \
		--generated $(FORMAL_CSR_PROVE_AUTO) --output $(FORMAL_CSR_PROVE_CONFIG) >/dev/null
	@printf "%b\n" "$(ORANGE)[script]$(RESET) $(BLUE)$(FORMAL_CSR_PROVE_CONFIG)$(RESET)"

formal_csr_bmc: ## Bounded-check automatic CSR assertions before proof
	$(call _require_file,$(FORMAL_CSR_PROVE_CONFIG),setup_formal_csr_prove)
	@command -v "$(SBY)" >/dev/null 2>&1 || { echo "ERROR: SymbiYosys executable not found: $(SBY)"; exit 2; }
	@printf "%b\n" "$(BLUE)log: $(FORMAL_CSR_BMC_LOG)$(RESET)"
	@cd "$(FORMAL_CSR_PROVE_RUN_DIR)" && \
		"$(SBY)" -f -d "$(TOP)_csr_bmc" "$(notdir $(FORMAL_CSR_PROVE_CONFIG))" bmc > "$(FORMAL_CSR_BMC_LOG)" 2>&1 || { \
			status=$$?; cat "$(FORMAL_CSR_BMC_LOG)"; \
			find "$(TOP)_csr_bmc" -type f \
				\( -name 'trace*.vcd' -o -name 'trace*.yw' -o -name 'trace*.v' -o -name 'trace*.smtc' \) \
				-print 2>/dev/null | sed 's#^#[counterexample] #'; \
			exit $$status; \
		}

formal_csr_prove: ## Prove automatic CSR semantics with SymbiYosys
	$(call _require_file,$(FORMAL_CSR_PROVE_CONFIG),setup_formal_csr_prove)
	@command -v "$(SBY)" >/dev/null 2>&1 || { echo "ERROR: SymbiYosys executable not found: $(SBY)"; exit 2; }
	@printf "%b\n" "$(BLUE)log: $(FORMAL_CSR_PROVE_LOG)$(RESET)"
	@cd "$(FORMAL_CSR_PROVE_RUN_DIR)" && \
		"$(SBY)" -f -d "$(TOP)_csr_prove" "$(notdir $(FORMAL_CSR_PROVE_CONFIG))" prove > "$(FORMAL_CSR_PROVE_LOG)" 2>&1 || { \
			status=$$?; cat "$(FORMAL_CSR_PROVE_LOG)"; exit $$status; \
		}

setup_formal_csr_cover: ## Generate automatic CSR cover configuration
	$(call _require_var,TOP)
	$(Q)rm -rf $(FORMAL_CSR_DIR)/generated
	$(Q)$(MKDIR) -p $(FORMAL_CSR_COVER_DIR) $(FORMAL_CSR_COVER_RUN_DIR) $(dir $(FORMAL_CSR_COVER_LOG))
	$(Q)$(PYTHON) -m flexsoc.backend.setup_formal csr \
		--top $(TOP) $(RTL_FILELIST_ARGS) \
		--properties-dir $(FORMAL_CSR_COVER_DIR) --mode cover \
		--engine "$(FORMAL_COVER_ENGINE)" --depth $(FORMAL_DEPTH) \
		--generated $(FORMAL_CSR_COVER_AUTO) --output $(FORMAL_CSR_COVER_CONFIG) >/dev/null
	@printf "%b\n" "$(ORANGE)[script]$(RESET) $(BLUE)$(FORMAL_CSR_COVER_CONFIG)$(RESET)"

formal_csr_cover: ## Cover every software-writable CSR primitive
	$(call _require_file,$(FORMAL_CSR_COVER_CONFIG),setup_formal_csr_cover)
	@command -v "$(SBY)" >/dev/null 2>&1 || { echo "ERROR: SymbiYosys executable not found: $(SBY)"; exit 2; }
	@printf "%b\n" "$(BLUE)log: $(FORMAL_CSR_COVER_LOG)$(RESET)"
	@cd "$(FORMAL_CSR_COVER_RUN_DIR)" && \
		"$(SBY)" -f "$(notdir $(FORMAL_CSR_COVER_CONFIG))" > "$(FORMAL_CSR_COVER_LOG)" 2>&1 || { \
			status=$$?; cat "$(FORMAL_CSR_COVER_LOG)"; exit $$status; \
		}

formal_csr: ## Run CSR BMC, prove, then cover
	@$(BACKEND_MAKE) setup_formal_csr_prove
	@$(BACKEND_MAKE) formal_csr_bmc
	@$(BACKEND_MAKE) formal_csr_prove
	@$(BACKEND_MAKE) setup_formal_csr_cover
	@$(BACKEND_MAKE) formal_csr_cover

formal: ## Run all formal stages BMC, prove, then cover
	@$(BACKEND_MAKE) setup_formal
	@$(BACKEND_MAKE) setup_formal_csr_prove
	@$(BACKEND_MAKE) setup_formal_prove
	@$(BACKEND_MAKE) formal_csr_bmc
	@$(BACKEND_MAKE) formal_bmc
	@$(BACKEND_MAKE) formal_csr_prove
	@$(BACKEND_MAKE) formal_prove
	@$(BACKEND_MAKE) setup_formal_csr_cover
	@$(BACKEND_MAKE) setup_formal_cover
	@$(BACKEND_MAKE) formal_csr_cover
	@$(BACKEND_MAKE) formal_cover

setup_formal_prove: ## Generate shared design BMC/prove configuration
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(FORMAL_PROVE_DIR) $(dir $(FORMAL_PROVE_LOG))
	$(Q)$(PYTHON) -m flexsoc.backend.setup_formal properties \
		--top $(TOP) $(RTL_FILELIST_ARGS) \
		--properties-dir $(FORMAL_PROVE_PROPERTIES_DIR) \
		--mode prove --engine "$(FORMAL_PROVE_ENGINE)" --depth $(FORMAL_DEPTH) \
		--bmc-engine "$(FORMAL_BMC_ENGINE)" --bmc-depth $(FORMAL_BMC_DEPTH) --bmc-append $(FORMAL_BMC_APPEND) \
		--output $(FORMAL_PROVE_CONFIG) >/dev/null
	@printf "%b\n" "$(ORANGE)[script]$(RESET) $(BLUE)$(FORMAL_PROVE_CONFIG)$(RESET)"

formal_bmc: ## Bounded-check authored assertions before proof
	$(call _require_file,$(FORMAL_PROVE_CONFIG),setup_formal_prove)
	@command -v "$(SBY)" >/dev/null 2>&1 || { echo "ERROR: SymbiYosys executable not found: $(SBY)"; exit 2; }
	@printf "%b\n" "$(BLUE)log: $(FORMAL_BMC_LOG)$(RESET)"
	@cd "$(FORMAL_PROVE_DIR)" && \
		"$(SBY)" -f -d "$(TOP)_bmc" "$(notdir $(FORMAL_PROVE_CONFIG))" bmc > "$(FORMAL_BMC_LOG)" 2>&1 || { \
			status=$$?; cat "$(FORMAL_BMC_LOG)"; \
			find "$(TOP)_bmc" -type f \
				\( -name 'trace*.vcd' -o -name 'trace*.yw' -o -name 'trace*.v' -o -name 'trace*.smtc' \) \
				-print 2>/dev/null | sed 's#^#[counterexample] #'; \
			exit $$status; \
		}

formal_prove: ## Prove authored SystemVerilog properties with SymbiYosys
	$(call _require_file,$(FORMAL_PROVE_CONFIG),setup_formal_prove)
	@command -v "$(SBY)" >/dev/null 2>&1 || { echo "ERROR: SymbiYosys executable not found: $(SBY)"; exit 2; }
	@printf "%b\n" "$(BLUE)log: $(FORMAL_PROVE_LOG)$(RESET)"
	@cd "$(FORMAL_PROVE_DIR)" && \
		"$(SBY)" -f -d "$(TOP)_prove" "$(notdir $(FORMAL_PROVE_CONFIG))" prove > "$(FORMAL_PROVE_LOG)" 2>&1 || { \
			status=$$?; cat "$(FORMAL_PROVE_LOG)"; exit $$status; \
		}

setup_formal_cover: ## Generate SymbiYosys cover configuration for authored cover properties
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(FORMAL_COVER_DIR) $(dir $(FORMAL_COVER_LOG))
	$(Q)$(PYTHON) -m flexsoc.backend.setup_formal properties \
		--top $(TOP) $(RTL_FILELIST_ARGS) \
		--properties-dir $(FORMAL_COVER_PROPERTIES_DIR) \
		--mode cover --engine "$(FORMAL_COVER_ENGINE)" --depth $(FORMAL_DEPTH) \
		--output $(FORMAL_COVER_CONFIG) >/dev/null
	@printf "%b\n" "$(ORANGE)[script]$(RESET) $(BLUE)$(FORMAL_COVER_CONFIG)$(RESET)"

formal_cover: ## Reach authored cover properties with SymbiYosys
	$(call _require_file,$(FORMAL_COVER_CONFIG),setup_formal_cover)
	@command -v "$(SBY)" >/dev/null 2>&1 || { echo "ERROR: SymbiYosys executable not found: $(SBY)"; exit 2; }
	@printf "%b\n" "$(BLUE)log: $(FORMAL_COVER_LOG)$(RESET)"
	@cd "$(FORMAL_COVER_DIR)" && \
		"$(SBY)" -f "$(notdir $(FORMAL_COVER_CONFIG))" > "$(FORMAL_COVER_LOG)" 2>&1 || { \
			status=$$?; cat "$(FORMAL_COVER_LOG)"; exit $$status; \
		}

# ============================================================================
# 9. Gate-level simulation and signoff analysis
# SDF, STA, violator extraction, estimated power and path-view reports.
# ============================================================================
##@ Signoff
EQY_CONFIG ?= $(EQUIVDIR)/$(TOP)_rtl_vs_syn.eqy
EQY_VIEW ?= $(EQUIVDIR)/$(TOP)_eqy_view.sv
EQY_SKY130_CLOCK_GATE_MODEL ?= $(EQUIVDIR)/sky130_clock_gates_formal.v
EQY_RESULT_DIR ?= $(EQUIVDIR)/$(TOP)_rtl_vs_syn
IP_NAME ?= $(TOP)
IP_LIBRARY_ROOT ?= $(REPO_ROOT)/hw/ips
IP_ROOT ?= $(IP_LIBRARY_ROOT)/$(IP_NAME)
IP_SIGNOFF_DIR ?= $(IP_ROOT)/signoff

setup_eqy: ## Prepare an existing EQY profile, or generate it when absent/forced
	$(call _require_file,$(SYNDIR)/$(TOP)_synth.v,syn)
	$(call _require_file,$(RTL_COMMON_LIST),flist)
	$(call _require_file,$(RTL_IP_LIST),flist)
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(EQUIVDIR) $(dir $(EQUIV_LOG))
	$(Q)$(PYTHON) -m flexsoc.backend.setup_eqy eqy-bind \
		--top $(TOP) $(RTL_FILELIST_ARGS) \
		--netlist $(SYNDIR)/$(TOP)_synth.v --liberty $(LIB_SYN) \
		$(foreach model,$(PRIM),--cell-model $(model)) \
		$(if $(FORMAL_PDK_PROC),--formal-pdk-proc "$(FORMAL_PDK_PROC)") \
		--sky130-clock-gate-model $(EQY_SKY130_CLOCK_GATE_MODEL) \
		--config $(EQY_CONFIG) --output-dir $(EQUIVDIR) >/dev/null
	@if [ -f "$(EQY_CONFIG)" ] && [ "$(FORCE)" != "1" ]; then \
		test -f "$(EQY_VIEW)" || { \
			echo "ERROR: EQY config exists but its formal view is missing: $(EQY_VIEW)"; \
			echo "Hint: regenerate both files with: fx eqy --force"; exit 2; \
		}; \
		printf "%b\n" "$(ORANGE)[script]$(RESET) $(BLUE)$(EQY_CONFIG)$(RESET) $(GREEN)(existing)$(RESET)"; \
	else \
		$(PYTHON) -m flexsoc.backend.setup_eqy eqy \
			--top $(TOP) $(RTL_FILELIST_ARGS) \
			--netlist $(SYNDIR)/$(TOP)_synth.v --liberty $(LIB_SYN) \
			$(foreach model,$(PRIM),--cell-model $(model)) \
			$(if $(FORMAL_PDK_PROC),--formal-pdk-proc "$(FORMAL_PDK_PROC)") \
			--sky130-clock-gate-model $(EQY_SKY130_CLOCK_GATE_MODEL) \
			--engine "$(EQY_ENGINE)" --depth $(EQY_DEPTH) --sat-depth $(EQY_SAT_DEPTH) \
			--output $(EQY_CONFIG) >/dev/null; \
		printf "%b\n" "$(ORANGE)[script]$(RESET) $(BLUE)$(EQY_CONFIG)$(RESET) $(YELLOW)(generated)$(RESET)"; \
	fi

eqy: ## Prove RTL equivalent to the mapped post-synthesis netlist with EQY
	$(call _require_file,$(EQY_CONFIG),setup_eqy)
	$(call _require_file,$(EQY_VIEW),setup_eqy)
	@command -v "$(EQY)" >/dev/null 2>&1 || { echo "ERROR: EQY executable not found: $(EQY)"; exit 2; }
	@command -v "$(SBY)" >/dev/null 2>&1 || { echo "ERROR: SymbiYosys executable not found for EQY SBY fallback: $(SBY)"; exit 2; }
	@printf "%b\n" "$(ORANGE)[eqy]$(RESET) PDK=$(PDK) · RTL -> mapped synthesis · jobs=$(EQY_JOBS)"
	@printf "%b\n" "$(BLUE)log: $(EQUIV_LOG)$(RESET)"
	@$(RM) -rf "$(EQY_RESULT_DIR)"
	@cd "$(EQUIVDIR)" && { \
		"$(EQY)" -j "$(EQY_JOBS)" -f "$(notdir $(EQY_CONFIG))" > "$(EQUIV_LOG)" 2>&1; status=$$?; \
		if [ $$status -eq 0 ]; then \
			printf "%b\n" "$(GREEN)[eqy] PASS$(RESET)"; \
		else \
			cat "$(EQUIV_LOG)"; printf "%b\n" "$(RED)[eqy] FAIL$(RESET)"; exit $$status; \
		fi; \
	}


SIGNOFF_PY_ARGS = \
	--project-root "$(REPO_ROOT)" --workspace "$(WORKSPACE)" \
	--run-top "$(RUN_TOP)" --run-id "$(RUN_ID)" --top "$(TOP)" --pdk "$(PDK)" \
	--signoff-stage "$(SIGNOFF_STAGE)" --sta "$(STA)" \
	--corners "$(SIGNOFF_CORNERS)" --modes "$(STA_MODES)" \
	$(foreach lib,$(LIBS),--liberty "$(lib)") --lib-syn "$(LIB_SYN)" \
	$(foreach lib,$(MACRO_LIBS),--macro-liberty "$(lib)") \
	$(if $(strip $(NETLIST)),--netlist "$(NETLIST)") \
	$(if $(strip $(SPEF_FILE)),--spef "$(SPEF_FILE)") \
	--sdc "$(CONSTRAINTSDIR)/$(TOP).sdc" \
	--power-activity "$(POWER_ACTIVITY)" --power-duty "$(POWER_DUTY)" \
	$(if $(filter 1,$(POWER_GLOBAL_ACTIVITY)),--power-global-activity) \
	--power-vcd-scope "$(POWER_VCD_SCOPE)" --power-dut-instance "$(POWER_DUT_INSTANCE)" \
	--fst2vcd "$(FST2VCD)" \
	--endpoint-group-limit "$(STA_ENDPOINT_GROUP_LIMIT)" \
	--endpoint-path-limit "$(STA_ENDPOINT_PATH_LIMIT)" \
	--near-critical-setup "$(STA_NEAR_CRITICAL_SETUP)" \
	--near-critical-hold "$(STA_NEAR_CRITICAL_HOLD)" \
	--power-top-instances "$(POWER_TOP_INSTANCES)" \
	--fusion-paths-per-instance "$(FUSION_PATHS_PER_INSTANCE)" \
	--fusion-top-paths "$(FUSION_TOP_PATHS)" \
	--fusion-power-metric "$(FUSION_POWER_METRIC)" \
	--fusion-high-fanout-threshold "$(FUSION_HIGH_FANOUT_THRESHOLD)"

setup_signoff: ## Generate all PDK-scoped OpenSTA Tcl families
	$(call _require_file,$(CONSTRAINTSDIR)/$(TOP).sdc,setup_sdc)
	$(call _require_var,TOP)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff generate $(SIGNOFF_PY_ARGS)

SYN_NETLIST ?= $(SYNDIR)/$(TOP)_synth.v

compile_syn: syn ## Compile post-synthesis simulation
	$(Q)$(MKDIR) -p $(POST_SYN_SIMDIR) $(SYNTH_LOGDIR)
	@if [ ! -f "$(SYN_NETLIST)" ]; then \
		echo "ERROR: missing synthesized netlist: $(SYN_NETLIST)"; \
		echo "Hint: check outputs under: $(SYNDIR)"; \
		exit 2; \
	fi
	@if [ ! -f "$(TB_SV_DIR)/$(TESTBENCH).sv" ]; then \
		echo "ERROR: missing testbench file: $(TB_SV_DIR)/$(TESTBENCH).sv"; \
		echo "Hint: run: make -C flow setup_tb WORKSPACE=... TOP=... RUN_ID=..."; \
		exit 2; \
	fi
	$(Q)iverilog -g2012 -v -gspecify -DSIM -DSYN \
		-s $(TESTBENCH) \
		$(IVERILOG_FLAGS) \
		-o $(POST_SYN_SIMDIR)/$(TOP)_syn_tb.vvp \
		$(PRIM) \
		$(TB_SV_DIR)/$(TESTBENCH).sv \
		> $(SYNTH_LOGDIR)/$(TOP)_compile_syn.log 2>&1

sim_syn: compile_syn ## Run post-synthesis simulation
	$(Q)vvp $(POST_SYN_SIMDIR)/$(TOP)_syn_tb.vvp -sdf-verbose +VCD=$(VCD_SYN_FILE) +SDF=$(SDF_FILE) \
		> $(SYNTH_LOGDIR)/$(TOP)_syn_sim.log 2>&1



sta_corners: ## Run STA for every configured corner and setup/hold mode
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff run --analysis sta $(SIGNOFF_PY_ARGS)

power_estimate_corners: ## Estimate power for every configured corner using input activity
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff run --analysis power_estimate $(SIGNOFF_PY_ARGS)

signoff_corners: ## Run SDF, multi-corner STA and estimated power
	@$(BACKEND_MAKE) setup_signoff
	@$(BACKEND_MAKE) sdf
	@$(BACKEND_MAKE) sta
	@$(BACKEND_MAKE) power_estimate

sta: sta_corners ## Run STA for every corner and setup/hold mode

sdf: ## Write one SDF timing file per configured corner
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff run --analysis sdf $(SIGNOFF_PY_ARGS)

power_estimate: power_estimate_corners ## Estimate power for every configured corner

power_analysis: ## Analyze one qualified GLS workload with OpenSTA
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff activity --analysis power_analysis --action single $(SIGNOFF_PY_ARGS) \
		--test-name "$(or $(POWER_TEST_NAME),$(TEST_NAME))" \
		--gls-backend "$(or $(POWER_GLS_BACKEND),$(GLS_BACKEND),sv)" \
		--timing-mode "$(or $(POWER_TIMING_MODE),$(TIMING_MODE),typ)"

power_analysis_all: ## Analyze all matching qualified GLS workloads with OpenSTA
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff activity --analysis power_analysis --action all $(SIGNOFF_PY_ARGS) \
		--test-names "$(or $(POWER_TEST_NAMES),all)" \
		--gls-backends "$(or $(POWER_GLS_BACKENDS),all)" \
		--timing-modes "$(or $(POWER_TIMING_MODES),all)"

fusion_analysis: ## Correlate timing and workload power for one qualified GLS trace
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff activity --analysis fusion_analysis --action single $(SIGNOFF_PY_ARGS) \
		--test-name "$(or $(POWER_TEST_NAME),$(TEST_NAME))" \
		--gls-backend "$(or $(POWER_GLS_BACKEND),$(GLS_BACKEND),sv)" \
		--timing-mode "$(or $(POWER_TIMING_MODE),$(TIMING_MODE),typ)"

fusion_analysis_all: ## Correlate timing and workload power for all matching GLS traces
	$(Q)$(PYTHON) -m flexsoc.backend.setup_signoff activity --analysis fusion_analysis --action all $(SIGNOFF_PY_ARGS) \
		--test-names "$(or $(POWER_TEST_NAMES),all)" \
		--gls-backends "$(or $(POWER_GLS_BACKENDS),all)" \
		--timing-modes "$(or $(POWER_TIMING_MODES),all)"

sta_violators: sta ## Generate the per-corner violating.rpt files

path_view: ## Build interactive STA path view for the selected PDK
	$(Q)$(MKDIR) -p $(SIGNOFF_PATH_VIEW_DIR)
	$(Q)cd $(SIGNOFF_PATH_VIEW_DIR) && $(PYTHON) $(UTILDIR)/interactiveReport.py -i $(SIGNOFF_STA_DIR)/$(PATH_VIEW_FILE) -s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)

# ============================================================================
# 10. Run metadata
# ============================================================================
##@ Run metadata
metrics: ## Collect verification, implementation, and sign-off metrics for the selected PDK
	$(Q)$(PYTHON) -m flexsoc.backend.metrics \
		--top $(TOP) \
		--run-dir $(OUTROOT) \
		--output $(METRICS_JSON)

manifest: ## Collect the automatic run identity and tool manifest
	$(Q)$(PYTHON) -m flexsoc.backend.manifest \
		--top $(TOP) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--repo-root $(REPO_ROOT) \
		--output $(MANIFEST_JSON)

manifest_show: ## Show the current run manifest in a colored terminal view
	$(Q)$(PYTHON) -m flexsoc.backend.manifest --show $(MANIFEST_JSON)

check: ## Show the existing complete functional/formal/synthesis/signoff run status
	@test -f "$(METRICS_JSON)" || { echo "ERROR: metrics not found: $(METRICS_JSON)"; echo "Hint: run: fx metrics"; exit 2; }
	$(Q)$(PYTHON) -m flexsoc.backend.metrics --show $(METRICS_JSON)

# ============================================================================
# 11. OpenROAD place and route
# ============================================================================
##@ Place and route
setup_pnr: ## Generate OpenROAD config
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.backend.setup_pnr --top $(TOP) \
		--synthesis-strategy $(TARGET_OPT) --clock-period $(CLK_PERIOD) \
		--platform $(ORS_TECH) --sdc-file $(CONSTRAINTSDIR)/$(TOP).sdc \
		$(RTL_FILELIST_ARGS) --output-dir $(ORSDIR)

pnr: ## Run OpenROAD place and route
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

pnr_gui: ## Open OpenROAD GUI
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
# 12. IP load/save
# ============================================================================
##@ IP load/save
ip_load: ## Load the complete saved IP package into a run workspace
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	src_ip="$(REPO_ROOT)/hw/ips/$(TOP)"; \
	load_name="$(TOP)"; \
	if [ -n "$${LOAD_AS:-}" ]; then load_name="$$LOAD_AS"; fi; \
	test -d "$$src_ip" || { echo "ERROR: missing source IP directory: $$src_ip"; exit 2; }; \
	if [ "$(RUN_TOP)" = "$(TOP)" ]; then \
		dst_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
		mkdir -p "$$dst_dir"; \
		for entry in "$$src_ip"/* "$$src_ip"/.[!.]* "$$src_ip"/..?*; do \
			[ -e "$$entry" ] || continue; \
			name="$${entry##*/}"; \
			rm -rf "$$dst_dir/$$name"; \
			cp -a "$$entry" "$$dst_dir/$$name"; \
		done; \
	else \
		dst_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)/ips/$$load_name"; \
		mkdir -p "$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)/ips"; \
		rm -rf "$$dst_dir"; \
		mkdir -p "$$dst_dir"; \
		cp -a "$$src_ip"/. "$$dst_dir"/; \
	fi; \
	find "$$dst_dir" -type d -name __pycache__ -prune -exec rm -rf {} +; \
	find "$$dst_dir" -type f -name '*.pyc' -delete

ip_save: ## Save current-PDK synthesis, PnR, EQY and OpenSTA Tcl into the IP library
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	ip_root="$(IP_ROOT)"; library_root="$(IP_LIBRARY_ROOT)"; pdk="$(PDK)"; \
	test -d "$(SYNDIR)" || { echo "ERROR: synthesis branch not found: $(SYNDIR)"; exit 2; }; \
	test -d "$(SIGNOFF_PDK_DIR)" || { echo "ERROR: signoff branch not found: $(SIGNOFF_PDK_DIR)"; exit 2; }; \
	for source in "$(EQY_CONFIG)" "$(EQY_VIEW)" \
		"$(SIGNOFF_STA_DIR)/sta.tcl" \
		"$(SIGNOFF_SDF_DIR)/write_sdf.tcl" \
		"$(SIGNOFF_POWER_DIR)/estimate/power_estimate.tcl"; do \
		test -f "$$source" || { echo "ERROR: required ip_save input not found: $$source"; exit 2; }; \
	done; \
	mkdir -p "$$library_root"; \
	temporary=$$(mktemp -d "$$library_root/.ip-save.$(IP_NAME).XXXXXX"); \
	staged="$$temporary/$(IP_NAME)"; backup="$$library_root/.$(IP_NAME).backup"; backed_up=0; \
	cleanup() { \
		status=$$?; trap - EXIT HUP INT TERM; \
		if [ "$$status" -ne 0 ] && [ "$$backed_up" -eq 1 ] && [ ! -e "$$ip_root" ] && [ -e "$$backup" ]; then \
			mv "$$backup" "$$ip_root" || true; \
		fi; \
		rm -rf "$$temporary"; exit "$$status"; \
	}; \
	trap cleanup EXIT HUP INT TERM; \
	if [ -d "$$ip_root" ]; then cp -a "$$ip_root" "$$staged"; else mkdir -p "$$staged"; fi; \
	rm -rf "$$staged/syn/$$pdk" "$$staged/pnr_openroad/$$pdk" "$$staged/signoff/$$pdk"; \
	mkdir -p "$$staged/syn" "$$staged/pnr_openroad" "$$staged/signoff/$$pdk/equivalence/rtl_vs_syn"; \
	cp -a "$(SYNDIR)" "$$staged/syn/$$pdk"; \
	if [ -d "$(ORSDIR)" ]; then cp -a "$(ORSDIR)" "$$staged/pnr_openroad/$$pdk"; fi; \
	$(PYTHON) -m flexsoc.backend.setup_eqy eqy-export \
		$(RTL_FILELIST_ARGS) \
		--netlist "$(SYNDIR)/$(TOP)_synth.v" --liberty "$(LIB_SYN)" \
		$(foreach model,$(PRIM),--cell-model "$(model)") \
		--sky130-clock-gate-model "$(EQY_SKY130_CLOCK_GATE_MODEL)" \
		--config "$(EQY_CONFIG)" --view "$(EQY_VIEW)" \
		--output-dir "$$staged/signoff/$$pdk/equivalence/rtl_vs_syn" >/dev/null; \
	cd "$(SIGNOFF_PDK_DIR)"; \
	find . -type f -name '*.tcl' -print | while IFS= read -r relative; do \
		target="$$staged/signoff/$$pdk/$${relative#./}"; mkdir -p "$${target%/*}"; cp -p "$$relative" "$$target"; \
	done; \
	cd "$(REPO_ROOT)"; \
	rm -rf "$$backup"; \
	if [ -e "$$ip_root" ]; then mv "$$ip_root" "$$backup"; backed_up=1; fi; \
	mv "$$staged" "$$ip_root"; backed_up=0; rm -rf "$$backup" "$$temporary"; \
	trap - EXIT HUP INT TERM; \
	tcl_count=$$(find "$$ip_root/signoff/$$pdk" -type f -name '*.tcl' | wc -l); \
	printf "%b\n" "$(GREEN)[ip_save]$(RESET) IP=$(IP_NAME) PDK=$(PDK) · syn/<pdk>, pnr_openroad/<pdk>, signoff/<pdk> · Tcl=$$tcl_count"

# ============================================================================
# 13. SoC, FuseSoC, XBAR and software flow
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

soc_vendor_deps: ## Fetch pinned lowRISC dependencies required by SoC simulation
	$(call _require_var,REPO_ROOT)
	@set -eu; \
	for vendor in lowrisc_ip lowrisc_ibex; do \
		if [ ! -d "$(REPO_ROOT)/vendor/$$vendor" ]; then \
			echo "[soc_vendor_deps] fetching $$vendor ..."; \
			$(MAKE) -f "$(REPO_ROOT)/src/flexsoc/backend/Makefile" fetch VENDOR=$$vendor; \
		else \
			echo "[soc_vendor_deps] $$vendor already present"; \
		fi; \
	done

fsoc_init: ## Initialize FuseSoC metadata
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
soc_flist: ## Generate Slang-ordered SoC common/IP filelists
	$(call _require_soc_run_vars)
	$(Q)$(PYTHON) -m flexsoc.backend.slang_tools flist \
		--slang "$(SLANG)" \
		--root "$(REPO_ROOT)" \
		$(if $(wildcard $(OUTROOT)/ips),--search-root "$(OUTROOT)/ips",) \
		$(FLIST_SEARCH_ARGS) \
		--top-file "$(RTLDIR)/soc.sv" \
		--top soc \
		--extra-args "$(SLANG_ARGS)" \
		--common-out "$(RTL_COMMON_LIST)" \
		--ip-out "$(RTL_IP_LIST)" \
		$(FLIST_COMMON_ARGS)
	@rm -f $(RTLDIR)/rtl_list.f $(RTLDIR)/rtl_lint.f
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
soc_prepare: soc_sim ## Prepare SoC build directory
	$(call _require_soc_run_vars)
	$(Q)$(MKDIR) -p $(SIMDIR)

soc_build_sw: soc_prepare sw_soc ## Build SoC software
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,HOST)
	$(Q)$(MAKE) --no-print-dir -C $(OUTROOT)/sw
# Simulation / run
soc_sim: TARGET := sim
soc_sim: FUSESOC_TOOL := verilator
soc_sim: soc_vendor_deps xbar soc fsoc_init fsoc ## Build SoC simulator
	$(call _require_soc_run_vars)
soc_run: ## Run SoC simulation
	$(call _require_soc_run_vars)
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
	cd "$(SIMDIR)"; \
	echo "SIM_TIMEOUT=$${SIM_TIMEOUT:-20}s"; \
	timeout --foreground -s INT -k 5s $${SIM_TIMEOUT:-20}s \
		"$(SOC_SIM_EXE)" \
		-t -E ../sw/build/main.elf || rc=$$?; \
	echo "sim rc=$$rc"; \
	if [ "$$rc" -ne 0 ] && [ "$$rc" -ne 124 ] && [ "$$rc" -ne 130 ]; then \
		exit "$$rc"; \
	fi
	$(Q)$(BACKEND_MAKE) soc_view WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) || true
# Waveform viewer
soc_view: ## Open SoC waveform
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	simdir="$(SIMDIR)"; \
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
# 14. FSM flow
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

# Backwards-compatible name used by fsm_tutorial in the original flow.
fsm2rtl: fsm_install ## Alias for FSM RTL installation

# ============================================================================
# 15. Tutorial and composed flows
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
	@printf "%b\n" "$(ORANGE)[soc_uart_tutorial]$(RESET) $(BLUE)load tutorial IPs$(RESET)"
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=uart_master LOAD_AS=uart
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=gpio
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=rv_timer
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=pwm
	$(Q)$(BACKEND_MAKE) soc_run HOST=uart SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
soc_ibex_fetch: ## Fetch Ibex tutorial dependencies
	@printf "%b\n" "$(ORANGE)[soc_ibex_fetch]$(RESET) $(BLUE)fetch lowRISC IPs$(RESET)"
	$(Q)$(BACKEND_MAKE) fetch VENDOR=lowrisc_ip
	@printf "%b\n" "$(ORANGE)[soc_ibex_fetch]$(RESET) $(BLUE)fetch Ibex$(RESET)"
	$(Q)$(BACKEND_MAKE) fetch VENDOR=lowrisc_ibex
soc_ibex_tutorial: soc_ibex_fetch ## Run Ibex-host SoC tutorial
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 1/8: load uart$(RESET)"
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=uart
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 2/8: load gpio$(RESET)"
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=gpio
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 3/8: load rv_timer$(RESET)"
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=rv_timer
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 4/8: load pwm$(RESET)"
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=pwm
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 5/8: load spi_host$(RESET)"
	$(Q)$(BACKEND_MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=spi_host
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 6/8: generate xbar + soc$(RESET)"
	$(Q)$(BACKEND_MAKE) xbar soc HOST=ibex SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 7/8: build sim model + software$(RESET)"
	$(Q)$(BACKEND_MAKE) soc_build_sw HOST=ibex \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID)
	@printf "%b\n" "$(ORANGE)[soc_ibex_tutorial]$(RESET) $(BLUE)step 8/8: run simulation$(RESET)"
	$(Q)$(BACKEND_MAKE) soc_run HOST=ibex SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)

# FSM and clean targets
# FSM flow

full_tutorial: ## Run the full IP tutorial flow
	$(Q)$(BACKEND_MAKE) ip_start ip_flow pnr pnr_gui \
		TOP=test RUN_TOP=test \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

fsm_tutorial: ## Run the FSM tutorial flow
	$(call _require_var,TOP)
	$(Q)$(BACKEND_MAKE) setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(BACKEND_MAKE) ip_flow_noreg \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

ip_tutorial: ## Run the IP tutorial flow
	$(call _require_var,TOP)
	$(Q)$(BACKEND_MAKE) ip_load \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(BACKEND_MAKE) flist sim syn sdf sta sta_violators power_estimate view \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

soc_pless: ## Run the tiny SoC tutorial flow
	$(Q)$(BACKEND_MAKE) ip_load \
		TOP=tiny-soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(BACKEND_MAKE) flist sim syn sdf sta power_estimate view \
		TOP=soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

# ============================================================================
# 16. Dependencies
# ============================================================================
##@ Dependencies
DEPS_MODE ?= user
DEPS_PROFILE ?= base
DEPS_JOBS ?= 2
DEPS_PRUNE_APPLY ?= 0
DEPS_PRUNE_CACHE ?= 0

deps-bootstrap: ## Check/install prerequisites for DEPS_PROFILE=base|impl|riscv
	bash $(TOOLSROOT)/deps.sh bootstrap --$(DEPS_MODE) --profile $(DEPS_PROFILE)

deps: ## Install pinned dependency profile (base|impl|riscv)
	bash $(TOOLSROOT)/deps.sh install --$(DEPS_MODE) --profile $(DEPS_PROFILE) --jobs $(DEPS_JOBS)

deps-doctor: ## Verify the selected pinned dependency profile
	bash $(TOOLSROOT)/deps.sh doctor --$(DEPS_MODE) --profile $(DEPS_PROFILE)

deps-versions: ## Show pinned tool versions and source revisions
	bash $(TOOLSROOT)/deps.sh versions

deps-env: ## Print shell exports for the pinned toolchain
	bash $(TOOLSROOT)/deps.sh env --$(DEPS_MODE)

deps-status: ## Show managed toolchain paths, sizes, and command duplicates
	bash $(TOOLSROOT)/deps.sh status --$(DEPS_MODE) --profile $(DEPS_PROFILE)

deps-prune: ## Dry-run/apply removal of obsolete managed prefixes and optional build caches
	bash $(TOOLSROOT)/deps.sh prune --$(DEPS_MODE) --profile $(DEPS_PROFILE) \
		$(if $(filter 1 true yes,$(DEPS_PRUNE_APPLY)),--apply,) \
		$(if $(filter 1 true yes,$(DEPS_PRUNE_CACHE)),--cache,)

# ============================================================================
# 17. Clean targets
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

clean_sim: ## Remove simulation and verification outputs
	$(Q)$(RM) $(SIMDIR)/*.vvp
	$(Q)$(RM) $(SIMDIR)/*.vcd $(SIMDIR)/*.fst
	$(Q)$(RM) -r $(SIMDIR)/verilator
	$(Q)$(RM) -r $(VERIFYDIR)

clean_cocotb: ## Remove cocotb outputs
	$(Q)$(RM) $(TBDIR)/cocotb/*.vcd $(TBDIR)/cocotb/*.fst
	$(Q)$(RM) $(TBDIR)/cocotb/sim_build
	$(Q)$(RM) $(TBDIR)/cocotb/__py*
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb clean

clean_formal: ## Remove PDK-independent property-formal outputs and logs
	$(Q)$(RM) -rf $(FORMALDIR) $(FORMAL_LOGDIR)

clean_syn: ## Remove synthesis outputs for the selected PDK
	$(Q)$(RM) -rf $(SYNDIR) $(SYNTH_LOGDIR)

clean_signoff: ## Remove signoff outputs for the selected PDK
	$(Q)$(RM) -rf $(SIGNOFF_PDK_DIR)
	$(Q)$(RM) -rf $(dir $(EQUIV_LOG)) $(STA_LOGDIR) $(POWER_LOGDIR) $(SDF_LOGDIR) $(FUSION_LOGDIR)

clean_meta: ## Remove run metadata
	$(Q)$(RM) -rf $(METADIR)/*

clean_pnr: ## Remove PnR outputs for the selected PDK
	$(Q)$(RM) -rf $(ORSDIR) $(OR_LOGDIR)

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

clean: clean-pyc clean_log clean_rtl clean_sim clean_syn clean_signoff clean_meta clean_pnr clean_subdir clean_fsoc clean_soc clean_fsm ## Clean generated flow outputs
	$(Q)$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec $(RM) -f {} + > /dev/null 2>&1
	$(Q)$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	$(Q)$(CLEAR)

clean_all: ## Remove all generated run outputs
	@rm -rf $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)
	@rm -rf $(WORKSPACE)/runs/$(TOP)/default
	@find $(WORKSPACE)/runs/$(TOP) -maxdepth 1 -type d -empty -delete 2>/dev/null || true
	@rm -rf build dist .pytest_cache .mypy_cache .ruff_cache
	@find . -type d -name __pycache__ -prune -exec rm -rf {} + 2>/dev/null || true
	@find . -type f -name '*.pyc' -delete 2>/dev/null || true
	@true

.PHONY:


.PHONY: regmap_py
