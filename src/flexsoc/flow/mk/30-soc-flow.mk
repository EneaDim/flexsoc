# -----------------------------------------------------------------------------
# SoC / FuseSoC flows
# -----------------------------------------------------------------------------

.PHONY: fsoc_init fsoc
.PHONY: xbar xbar_init xbar_build
.PHONY: soc soc_flist soc_flow soc_sim soc_view
.PHONY: soc_ibex_fetch soc_ibex_prepare_ip soc_ibex_prepare_ips soc_ibex soc_ibex_tutorial
.PHONY: sw_soc soc_run
.PHONY: ip_save ip_load

PRJ    ?= flexsoc
TARGET ?= default

# -----------------------------------------------------------------------------
# Tutorial defaults
# -----------------------------------------------------------------------------

soc_ibex_fetch: HOST ?= ibex
soc_ibex_fetch: RUN_TOP ?= soc_ibex
soc_ibex_fetch: RUN_ID ?= dev
soc_ibex_fetch: TOP ?= soc

soc_ibex: HOST ?= ibex
soc_ibex: SOC_CFG_MODE ?= builtin
soc_ibex: RUN_TOP ?= soc_ibex
soc_ibex: RUN_ID ?= dev
soc_ibex: TOP ?= soc

soc_ibex_tutorial: HOST ?= ibex
soc_ibex_tutorial: SOC_CFG_MODE ?= builtin
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
	@echo "\n$(ORANGE)XBAR init ...\n$(RESET)"
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
	@echo "\n$(ORANGE)SoC files building ...\n$(RESET)"
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
# Ibex tutorial / reference SoC
# -----------------------------------------------------------------------------

soc_ibex_fetch:
	@echo "\n$(ORANGE)Fetch lowrisc ips ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	@echo "\n$(ORANGE)Fetch ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex

# Prepare one standalone IP run so that its bundle includes generated drivers.
# Usage:
#   $(MAKE) soc_ibex_prepare_ip IP_NAME=gpio
soc_ibex_prepare_ip:
	$(call _require_var,WORKSPACE)
	$(call _require_var,IP_NAME)
	@echo "\n$(ORANGE)Preparing standalone IP bundle: $(IP_NAME)\n$(RESET)"
	$(Q)$(MAKE) ip_load TOP=$(IP_NAME) RUN_TOP=$(IP_NAME) RUN_ID=dev WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) driver  TOP=$(IP_NAME) RUN_TOP=$(IP_NAME) RUN_ID=dev WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) ip_save TOP=$(IP_NAME) RUN_TOP=$(IP_NAME) RUN_ID=dev WORKSPACE=$(WORKSPACE) OVERWRITE=--force

soc_ibex_prepare_ips:
	$(Q)$(MAKE) soc_ibex_prepare_ip WORKSPACE=$(WORKSPACE) IP_NAME=gpio
	$(Q)$(MAKE) soc_ibex_prepare_ip WORKSPACE=$(WORKSPACE) IP_NAME=uart
	$(Q)$(MAKE) soc_ibex_prepare_ip WORKSPACE=$(WORKSPACE) IP_NAME=rv_timer
	$(Q)$(MAKE) soc_ibex_prepare_ip WORKSPACE=$(WORKSPACE) IP_NAME=pwm
	$(Q)$(MAKE) soc_ibex_prepare_ip WORKSPACE=$(WORKSPACE) IP_NAME=spi_host

soc_ibex: setup soc_ibex_prepare_ips
	@echo "[soc_ibex] HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) TOP=$(TOP) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID)"
	@echo "\n$(ORANGE)Loading prepared IP bundles into SoC run...\n$(RESET)"
	$(Q)$(MAKE) ip_load TOP=gpio     RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) ip_load TOP=uart     RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) ip_load TOP=rv_timer RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) ip_load TOP=pwm      RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) ip_load TOP=spi_host RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)

	@echo "\n$(ORANGE)XBAR build ...\n$(RESET)"
	$(Q)$(MAKE) xbar HOST=ibex SOC_CFG_MODE=builtin TOP=$(TOP) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)

	@echo "\n$(ORANGE)SoC files building ...\n$(RESET)"
	$(Q)$(MAKE) soc HOST=ibex SOC_CFG_MODE=builtin TOP=$(TOP) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)

	@echo "\n$(ORANGE)FuseSoC setup/build ...\n$(RESET)"
	$(Q)$(FUSESOC) --cores-root=$(REPO_ROOT) run --target=sim --tool=verilator --setup --build enea:soc:main

	$(Q)$(MAKE) soc_run WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) TOP=$(TOP)

soc_ibex_tutorial: soc_ibex_fetch soc_ibex

# -----------------------------------------------------------------------------
# Software generation / run
# -----------------------------------------------------------------------------

sw_soc:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(Q)$(PYTHON) -m flexsoc.tools.sw_soc_gen \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID)

soc_run:
	$(Q)$(MAKE) sw_soc WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID)
	$(Q)$(MKDIR) -p $(OUTROOT)/sim
	@echo "\n$(ORANGE)GCC compilation of SoC software ...\n$(RESET)"
	$(Q)$(MAKE) --no-print-dir -C $(OUTROOT)/sw
	@echo "\n$(ORANGE)Verilator run with automatic timeout...\n$(RESET)"
	$(Q)cd $(OUTROOT)/sim && timeout $${SIM_TIMEOUT:-20}s $(REPO_ROOT)/flow/build/enea_soc_main_0/sim-verilator/Vtop_verilator -t -E ../sw/build/main.elf || test $$? -eq 124
	$(Q)$(MAKE) soc_view WORKSPACE=$(WORKSPACE) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) || true

# -----------------------------------------------------------------------------
# Direct simulation helper
# -----------------------------------------------------------------------------

soc_sim:
	@echo "\n$(ORANGE)SoC simulation with FuseSoC ...\n$(RESET)"
	$(Q)$(FUSESOC) --cores-root=$(REPO_ROOT) run --target=sim --tool=verilator --setup --build enea:soc:main

soc_view:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	fst="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)/sim/sim.fst"; \
	test -f "$$fst" || { echo "ERROR: missing waveform: $$fst"; exit 2; }; \
	if command -v gtkwave >/dev/null 2>&1; then \
		echo "Opening waveform: $$fst"; \
		gtkwave $(VIEWER_FLAGS) "$$fst" >/dev/null 2>&1 & \
	else \
		echo "WARNING: gtkwave not found in PATH"; \
		echo "Waveform available at: $$fst"; \
	fi
