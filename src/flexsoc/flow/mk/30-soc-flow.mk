# -----------------------------------------------------------------------------
# SoC / FuseSoC flows
# -----------------------------------------------------------------------------

.PHONY: fsoc_init fsoc
.PHONY: xbar xbar_init xbar_build
.PHONY: soc soc_flist soc_flow soc_view
.PHONY: soc_uart_gen soc_ibex_gen
.PHONY: soc_sim soc_run sw_soc
.PHONY: soc_uart_tutorial soc_ibex_fetch soc_ibex_tutorial

PRJ    ?= flexsoc
TARGET ?= default
HOST   ?= uart
SOC_CFG_MODE ?= builtin

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
# FuseSoC init for single IP
# -----------------------------------------------------------------------------

fsoc_init:
	@echo "\n$(ORANGE)FuseSoC setup...\n$(RESET)"
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	run_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
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

fsoc:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	cores_root="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)/fusesoc"; \
	$(FUSESOC) --cores-root="$$cores_root" run --target "$(TARGET)" "$(PRJ):ip:$(TOP)"

# -----------------------------------------------------------------------------
# XBAR / SoC generation
# -----------------------------------------------------------------------------

xbar: xbar_init xbar_build

xbar_init: soc_cfg
	@echo "\n$(ORANGE)XBAR init (HOST=$(HOST)) ...\n$(RESET)"
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

soc: soc_cfg
	@echo "\n$(ORANGE)SoC files building (HOST=$(HOST)) ...\n$(RESET)"
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
	$(Q)$(PYTHON) -m flexsoc.tools.gen_filelist \
		--soc \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
		--top soc \
		--out $(RTLDIR)/rtl_list.f

soc_flow: xbar soc

# -----------------------------------------------------------------------------
# Host-specific wrappers
# -----------------------------------------------------------------------------

soc_uart_gen: HOST := uart
soc_uart_gen: SOC_CFG_MODE := builtin
soc_uart_gen: xbar soc

soc_ibex_gen: HOST := ibex
soc_ibex_gen: SOC_CFG_MODE := builtin
soc_ibex_gen: xbar soc

# -----------------------------------------------------------------------------
# Software generation
# -----------------------------------------------------------------------------

sw_soc:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(Q)$(PYTHON) -m flexsoc.tools.sw_soc_gen \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID)

# -----------------------------------------------------------------------------
# Simulation / run
# -----------------------------------------------------------------------------

soc_sim:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,TOP)
	@echo "\n$(ORANGE)Preparing SoC build (HOST=$(HOST)) ...\n$(RESET)"
	$(Q)$(MAKE) xbar HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
	$(Q)$(MAKE) soc HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
	@echo "\n$(ORANGE)SoC simulation model build with FuseSoC ...\n$(RESET)"
	$(Q)$(FUSESOC) --cores-root=$(REPO_ROOT) run --target=sim --tool=verilator --setup --build enea:soc:main

soc_run:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,TOP)
	$(Q)$(MAKE) sw_soc WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID)
	$(Q)$(MKDIR) -p $(OUTROOT)/sim
	@if [ ! -x "$(REPO_ROOT)/flow/build/enea_soc_main_0/sim-verilator/Vtop_verilator" ]; then \
		echo "\n$(ORANGE)Simulation model missing, building with soc_sim (HOST=$(HOST)) ...\n$(RESET)"; \
		$(MAKE) soc_sim HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) \
			WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP); \
	fi
	@echo "\n$(ORANGE)GCC compilation of SoC software ...\n$(RESET)"
	$(Q)$(MAKE) --no-print-dir -C $(OUTROOT)/sw
	@echo "\n$(ORANGE)Verilator run with automatic timeout...\n$(RESET)"
	$(Q)cd $(OUTROOT)/sim && timeout $${SIM_TIMEOUT:-20}s \
		$(REPO_ROOT)/flow/build/enea_soc_main_0/sim-verilator/Vtop_verilator \
		-t -E ../sw/build/main.elf || test $$? -eq 124
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
	@echo "\n$(ORANGE)Fetch lowrisc ips ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	@echo "\n$(ORANGE)Fetch ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex

soc_ibex_tutorial: soc_ibex_fetch
	@echo "\n$(ORANGE)Loading IPs for IBEX-host SoC tutorial ...\n$(RESET)"
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=uart-master LOAD_AS=uart
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=gpio
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=rv_timer
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=pwm
	$(Q)$(MAKE) ip_load WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=spi_host
	$(Q)$(MAKE) soc_run HOST=ibex SOC_CFG_MODE=builtin \
		WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)
