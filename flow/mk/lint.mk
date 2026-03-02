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
	
#########################################################
#########################################################

.PHONY: compile compile_v compile_sv
compile: $(if $(filter v,$(Q)$(VSV)),compile_v,compile_sv)

compile_v: lint_v
ifeq ($(Q)$(COMPILER), iverilog)
	@echo "\n$(ORANGE)Compiling...\n$(RESET)"
	$(Q)$(COMPILER) $(IVERILOG_FLAGS) -o $(SIMDIR)/$(TESTBENCH).vvp $(TBDIR)/$(TESTBENCH).sv \
	> $(LOGDIR)/$(TOP)_compile.log 2>&1
else
	@echo "\n$(ORANGE)Compiling...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_compile.log 2>&1
endif

compile_sv: lint_sv
	@echo "\n$(ORANGE)Compiling...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} -f $(RTLDIR)/rtl_list.f > $(LOGDIR)/$(TOP)_compile.log 2>&1

######################
######################

.PHONY: sim sim_v sim_sv
sim: $(if $(filter v,$(VSV)),sim_v,sim_sv)

sim_v: compile_v
ifeq ($(Q)$(COMPILER), iverilog)
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TESTBENCH)_sim.log
else
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} --trace --trace-structs
	$(Q)$(TBDIR)/$(TESTBENCH).sv > $(LOGDIR)/$(TOP)_sim.log 2>&1
	$(Q)./$(SIMDIR)/$(COMPILER)/V$(Q)$(TESTBENCH)
endif

sim_sv: compile_sv
ifeq ($(Q)$(COMPILER), iverilog)
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TESTBENCH)_sim.log
else
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} -f $(RTLDIR)/rtl_list.f --top-module $(TOP)_tb \
	--trace --trace-structs $(TBDIR)/$(TESTBENCH).sv > $(LOGDIR)/$(TOP)_sim.log 2>&1
	$(Q)./$(SIMDIR)/$(COMPILER)/V$(TESTBENCH)
endif

############################
############################

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

###################################################
###################################################

compile_syn:
	@echo "\n$(ORANGE)Compiling synthesis...\n$(RESET)"
	$(Q)iverilog -g2012 -v -gspecify -DSIM -DSYN -s $(TOP)_tb \
	-o $(SIMDIR)/$(TOP)_syn_tb.vvp $(PRIM) $(TBDIR)/$(TOP)_tb.sv \
	> $(LOGDIR)/$(TOP)_compile_syn.log 2>&1

# SIMULATE POST SYNTHESIS NETLIST
sim_syn: compile_syn
	@echo "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TOP)_syn_tb.vvp -sdf-verbose \
	> $(LOGDIR)/$(TOP)_syn_sim.log 2>&1

############################################
###        Static Timing Analysis        ###
############################################

sta: setup_signoff 
	@echo "\n$(ORANGE)Static Timing Analysis...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl \
	> $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).warnings || true 
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).errors || true 

##################################################
##################################################

power: setup_signoff 
	@echo "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl > $(LOGDIR)/$(TOP)_power.log 

#################################################
###        Place & Route with OpenROAD        ###
#################################################

pnr: setup_pnr 
	@echo "\n$(ORANGE)Doing Place&Route...\n$(RESET)"
	$(Q)$(MAKE) --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk > $(LOGDIR)/$(TOP)_pnr.log 2>/dev/null 

pnr_gui:
	$(Q)$(MAKE) gui_final --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk 2>/dev/null &

######################
######################

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

###############################
###############################

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

soc:
	@echo "\n$(ORANGE)SoC files building ...\n$(RESET)"
	$(Q)$(PYTHON) scripts/soc_gen.py -host $(HOST) $(SOC_MEMORY_MAP) -o $(RTLDIR)/soc.sv

soc_flow: xbar soc
	
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

#############
#############

full_tutorial:
	$(Q)$(MAKE) ip_start ip_flow pnr pnr_gui TOP=test

fsm_tutorial: setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl
	$(Q)$(MAKE) ip_flow_noreg TOP=$(FSM)

ip_tutorial:
	$(Q)$(MAKE) ip_load
	@echo "\n$(ORANGE)Run the IP flow ...\n$(RESET)"
	$(Q)$(MAKE) sim syn sdf sta sta_violators power view
