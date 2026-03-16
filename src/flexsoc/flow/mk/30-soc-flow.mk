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
	$(PYTHON) -m flexsoc.tools.setup_fsoc \
		-prj "$(PRJ)" \
		-top "$(TOP)" \
		-rtldir "$$rtl_dir" \
		-lintdir "$$lint_dir" \
		-o "$$core_rel"; \
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
	@cfg_args="$$( $(PYTHON) -m flexsoc.tools.soc_cfg \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--mode $(SOC_CFG_MODE) \
		--default-host $(HOST) \
		--format args )"; \
	$(PYTHON) -m flexsoc.tools.xbar_init $$cfg_args --output $(DATADIR)/xbar_main.hjson
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
	@cfg_args="$$( $(PYTHON) -m flexsoc.tools.soc_cfg \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--mode $(SOC_CFG_MODE) \
		--default-host $(HOST) \
		--format args )"; \
	$(PYTHON) -m flexsoc.tools.soc_gen $$cfg_args -o $(RTLDIR)/soc.sv
soc_flist:
	@echo "\n$(ORANGE)Generating SoC filelist ...\n$(RESET)"
	$(call _require_soc_run_vars)
	$(Q)$(PYTHON) -m flexsoc.tools.gen_filelist \
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
	$(Q)$(PYTHON) -m flexsoc.tools.sw_soc_gen \
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
