.PHONY: soc_ibex_fetch soc_ibex soc_ibex_tutorial

soc_ibex_fetch: HOST ?= ibex
soc_ibex: HOST ?= ibex
soc_ibex_tutorial: HOST ?= ibex


soc_ibex_fetch: RUN_TOP ?= soc_ibex
soc_ibex_fetch: RUN_ID ?= dev
soc_ibex_fetch: TOP ?= soc

soc_ibex: RUN_TOP ?= soc_ibex
soc_ibex: RUN_ID ?= dev
soc_ibex: TOP ?= soc

soc_ibex_tutorial: RUN_TOP ?= soc_ibex
soc_ibex_tutorial: RUN_ID ?= dev
soc_ibex_tutorial: TOP ?= soc

soc_ibex_tutorial: RUN_TOP ?= soc_ibex
soc_ibex_tutorial: RUN_ID ?= dev
soc_ibex_tutorial: TOP ?= soc

# -----------------------------------------------------------------------------
# FuseSoC
# -----------------------------------------------------------------------------
.PHONY: fsoc_init fsoc xbar xbar_init xbar_build soc soc_flow soc_ibex_fetch soc_ibex soc_sim soc_run soc_view soc_ibex_tutorial
.PHONY: ip_save ip_load

PRJ    ?= flexsoc
TARGET ?= default

fsoc_init:
	@echo "\n$(ORANGE)FuseSOC setup...\n$(RESET)"
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
	$(Q)$(FUSESOC) --cores-root="$$cores_root" run --target "$(TARGET)" "$(PRJ):ip:$(TOP)"

# -----------------------------------------------------------------------------
# XBAR / SoC
# -----------------------------------------------------------------------------
xbar: xbar_init xbar_build

xbar_init: soc_cfg
	@echo "\n$(ORANGE)XBAR init ...\n$(RESET)"
	$(Q)$(MKDIR) -p $(DATADIR) $(RTLDIR)
	@cfg_args="$$( $(PYTHON) -m flexsoc.tools.soc_cfg \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID) \
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

soc_ibex_fetch:
	@echo "\n$(ORANGE)Fetch lowrisc ips ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	@echo "\n$(ORANGE)Fetch ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex

soc_ibex: HOST ?= ibex
soc_ibex: SOC_CFG_MODE ?= builtin
soc_ibex: setup
	@echo "\n$(ORANGE)Preparing internal IPs for SoC IBEX tutorial...\n$(RESET)"
	$(Q)$(MAKE) ip_load TOP=gpio RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) ip_load TOP=uart RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) ip_load TOP=rv_timer RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)

	@echo "\n$(ORANGE)SoC files building with IBEX...\n$(RESET)"
	$(Q)$(MAKE) xbar HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) TOP=$(TOP) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(MAKE) soc  HOST=$(HOST) SOC_CFG_MODE=$(SOC_CFG_MODE) TOP=$(TOP) RUN_TOP=$(RUN_TOP) RUN_ID=$(RUN_ID) WORKSPACE=$(WORKSPACE)
	$(Q)$(FUSESOC) --cores-root=$(REPO_ROOT) run --target=sim --tool=verilator --setup --build enea:soc:main
	$(Q)$(MAKE) soc_run

soc_sim:
	@echo "\n$(ORANGE)SoC simulation with FuseSoC ...\n$(RESET)"
	$(Q)$(FUSESOC) --cores-root=$(REPO_ROOT) run --target=sim --tool=verilator --setup --build enea:soc:main

soc_run:
	@echo "\n$(ORANGE)GCC compilaiton of hello_world.c ...\n$(RESET)"
	$(Q)$(MAKE) --no-print-dir -C sw
	@echo "\n$(ORANGE)Verilator run ... Press <CTRL>-C\n$(RESET)"
	build/enea_soc_main_0/sim-verilator/Vtop_verilator -t -E sw/build/main.elf

soc_view:
	@echo "\n$(ORANGE)Viewing ...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) sim.fst $(SIMDIR)/soc_$(TOP)_tb.gtkw &

soc_ibex_tutorial: soc_ibex_fetch soc_ibex

# -----------------------------------------------------------------------------
# IP save/load
# -----------------------------------------------------------------------------
ip_save: clean_sim
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	run_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
	src_ip="$$run_dir/ips/$(TOP)"; \
	src_run="$$run_dir"; \
	dst="$(IPS_ROOT)/$(TOP)"; \
	if [ -d "$$src_ip" ]; then \
		src="$$src_ip"; \
	else \
		src="$$src_run"; \
	fi; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source IP bundle not found: $$src"; \
		exit 2; \
	fi; \
	mkdir -p "$(IPS_ROOT)"; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination already exists: $$dst"; \
		echo "Hint: re-run with --overwrite"; \
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
		rsync -a \
			--exclude pnr_openroad/results \
			--exclude pnr_openroad/reports \
			--exclude pnr_openroad/objects \
			--exclude signoff/sdf \
			--exclude history/ \
			--exclude logs/ \
			"$$src"/ "$$dst"/; \
	else \
		cp -a "$$src"/. "$$dst"/; \
		rm -rf "$$dst/history" "$$dst/logs"; \
	fi

ip_load:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	src="$(IPS_ROOT)/$(TOP)"; \
	run_dir="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source IP bundle not found: $$src"; \
		exit 2; \
	fi; \
	if [ "$(RUN_TOP)" = "$(TOP)" ]; then \
		dst="$$run_dir"; \
		mode="single-ip"; \
	else \
		dst="$$run_dir/ips/$(TOP)"; \
		mode="multi-ip"; \
		mkdir -p "$$run_dir/ips"; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination already exists: $$dst"; \
		echo "Hint: re-run with --overwrite"; \
		exit 2; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "1" ]; then \
		rm -rf "$$dst"; \
	fi; \
	mkdir -p "$$dst"; \
	echo "Loading IP bundle ($$mode):"; \
	echo "  from: $$src"; \
	echo "  to:   $$dst"; \
	if command -v rsync >/dev/null 2>&1; then \
		rsync -a "$$src"/ "$$dst"/; \
	else \
		cp -a "$$src"/. "$$dst"/; \
	fi


setup_soc_tb: soc_cfg soc_flist
	@echo "\n$(ORANGE)Setup SoC SystemVerilog Testbench Template...\n$(RESET)"
	$(Q)$(MKDIR) -p $(TBDIR) $(SIMDIR) $(SYNDIR) $(RTLDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_tb $(OVERWRITE) \
		-top soc \
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

sim_soc:
	$(Q)$(MAKE) --no-print-dir sim \
		WORKSPACE=$(WORKSPACE) \
		RUN_TOP=$(RUN_TOP) \
		RUN_ID=$(RUN_ID) \
		TOP=soc


soc_save:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	src="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
	dst="$(IPS_ROOT)/$(RUN_TOP)"; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source SoC bundle not found: $$src"; \
		exit 2; \
	fi; \
	mkdir -p "$(IPS_ROOT)"; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination already exists: $$dst"; \
		echo "Hint: re-run with --overwrite"; \
		exit 2; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "1" ]; then \
		rm -rf "$$dst"; \
	fi; \
	mkdir -p "$$dst"; \
	echo "Saving SoC bundle:"; \
	echo "  from: $$src"; \
	echo "  to:   $$dst"; \
	if command -v rsync >/dev/null 2>&1; then \
		rsync -a \
			--exclude history/ \
			--exclude logs/ \
			--exclude sessions/ \
			"$${src}/" "$${dst}/"; \
	else \
		cp -a "$$src"/. "$$dst"/; \
		rm -rf "$$dst/history" "$$dst/logs" "$$dst/sessions"; \
	fi

soc_load:
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	$(call _require_var,TOP)
	@set -eu; \
	src="$(IPS_ROOT)/$(TOP)"; \
	dst="$(WORKSPACE)/runs/$(RUN_TOP)/$(RUN_ID)"; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source SoC bundle not found: $$src"; \
		exit 2; \
	fi; \
	mkdir -p "$(WORKSPACE)/runs/$(RUN_TOP)"; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination already exists: $$dst"; \
		echo "Hint: re-run with --overwrite"; \
		exit 2; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "1" ]; then \
		rm -rf "$$dst"; \
	fi; \
	mkdir -p "$$dst"; \
	echo "Loading SoC bundle:"; \
	echo "  from: $$src"; \
	echo "  to:   $$dst"; \
	if command -v rsync >/dev/null 2>&1; then \
		rsync -a "$$src"/ "$$dst"/; \
	else \
		cp -a "$$src"/. "$$dst"/; \
	fi

