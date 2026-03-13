# -----------------------------------------------------------------------------
# FSM flow
# -----------------------------------------------------------------------------
define _require_fsm
	@if [ -z "$(strip $(FSM))" ]; then \
	  echo "ERROR: FSM is required. Pass it as: -- FSM=<fsm_name>"; \
	  exit 2; \
	fi
endef

.PHONY: fsm_init fsm_tool_setup fsm_example_load fsm_setup fsm_gen fsm_plot fsm_flow
.PHONY: fsm_install fsm2rtl fsm_save fsm_load
.PHONY: deps deps-soc
.PHONY: clean-pyc clean_doc clean_log clean_rtl clean_sim clean_cocotb clean_syn clean_signoff clean_pnr
.PHONY: clean_fsm clean_fsm_all clean_agent clean_fsoc clean_soc clean_sw clean_vendor clean_subdir clean clean_all
.PHONY: full_tutorial fsm_tutorial ip_tutorial soc_pless

fsm_init:
	$(call _require_fsm)
	$(Q)$(MKDIR) -p "$(FSM_INPUT_DIR)" "$(FSM_OUTPUT_DIR)"

# Legacy name kept for compatibility. It now prepares the run-local FSM workspace
# and also keeps the standalone tool directories available.
fsm_setup: fsm_init
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) setup

# Explicit tool setup alias (clearer than fsm_setup)
fsm_tool_setup:
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

# Backward-compatible alias
fsm2rtl: fsm_install

# Compatibility targets: with run-local FSM directories these are now effectively no-ops
# or simple sync helpers.
fsm_save: fsm_init
	$(call _require_fsm)
	@echo "\n$(ORANGE)FSM $(FSM) already lives inside the run workspace: $(FSMWORKDIR)\n$(RESET)"

fsm_load: fsm_init
	$(call _require_fsm)
	@echo "\n$(ORANGE)FSM $(FSM) is already run-local. Edit inputs under $(FSM_INPUT_DIR)\n$(RESET)"

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

clean_all: clean_fsm_all clean_vendor clean_agent clean
	$(Q)$(RM) *.core
	$(Q)$(RM) $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) $(ORSDIR) \
		$(MODELDIR) $(DATADIR) $(DOCDIR) $(LINTDIR) $(DRIVERDIR) $(PYDIR) $(FSMDIR) > /dev/null 2>&1

# -----------------------------------------------------------------------------
# Tutorials
# -----------------------------------------------------------------------------
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
	$(Q)$(MAKE) sim syn sdf sta sta_violators power view \
		TOP=$(TOP) RUN_TOP=$(TOP) \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)

soc_pless:
	$(Q)$(MAKE) ip_load \
		TOP=tiny-soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
	$(Q)$(MAKE) sim syn sdf sta power view \
		TOP=soc RUN_TOP=tiny-soc \
		WORKSPACE=$(TUTORIAL_WS) RUN_ID=$(TUTORIAL_RUN_ID)
