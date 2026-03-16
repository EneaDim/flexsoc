# -----------------------------------------------------------------------------
# IP generation
# -----------------------------------------------------------------------------
.PHONY: hjson reg doc rtl_stub ip_start soc_start flist driver fetch ip_flow ip_flow_noreg ip_flow_all
.PHONY: lint lint_v lint_sv compile compile_v compile_sv sim sim_v sim_sv
.PHONY: compile_syn sim_syn cocotb view view_cocotb view_syn
.PHONY: syn syn_v syn_sv yosys-vgen plot_postsyn view_presyn view_presyn_v view_presyn_sv
.PHONY: sta sdf power sta_violators path_view pnr pnr_gui tb_save tb_view sv2v

hjson: setup
	@echo "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.tools.hjson_gen $(OVERWRITE) -top $(TOP) -itf $(REG_ITF) -o $(DATADIR)

reg:
	@echo "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)$(UTILROOT)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

doc:
	@echo "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)$(UTILROOT)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)$(UTILROOT)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

rtl_stub:
	@echo "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.tools.rtl_stub_gen $(OVERWRITE) -i $(DATADIR)/$(TOP).hjson -itf $(REG_ITF) -o $(RTLDIR)

ip_start: setup hjson reg doc rtl_stub flist setup_tb sim

soc_start: flist
	$(call _require_var,WORKSPACE)
	$(call _require_var,RUN_TOP)
	$(call _require_var,RUN_ID)
	@echo "\n$(ORANGE)Initializing SoC run from loaded IP bundles...\n$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.tools.soc_start \
		--workspace $(WORKSPACE) \
		--run-top $(RUN_TOP) \
		--run-id $(RUN_ID)

flist:
	$(Q)$(PYTHON) -m flexsoc.tools.gen_filelist --top $(TOP) --out $(RTLDIR)/rtl_list.f --ips-root $(IPS_ROOT) --rtldir $(RTLDIR)

driver:
	$(Q)$(UTILROOT)/regtool.py -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) -m flexsoc.tools.driver_gen -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR)

fetch:
	$(Q)$(UTILROOT)/vendor.py --update $(REPO_ROOT)/vendor/$(VENDOR).vendor.hjson

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

lint_sv: setup
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
