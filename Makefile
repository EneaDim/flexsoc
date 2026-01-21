# Include configuration
include config.mk

# LLM Agent
.PHONY: agent
agent:
	@python3 flexsoc_make_agent/agent_repl.py --repo-root . --catalog flexsoc_make_agent/catalog.json

# HELP
help:
	@echo "$(ORANGE)"
	@echo "Available make commands to start:"
	@echo ""
	@echo "    make help_ip     Show IP-related help"
	@echo "    make help_soc    Show SoC-related help"
	@echo "    make help_doc    Show documentation-related help"
	@echo "    make help_fsm    Show FSM generator help"
	@echo "$(RESET)"

help_ip:
	$(Q)$(PYTHON) scripts/help_ip.py
help_soc:
	$(Q)$(PYTHON) scripts/help_soc.py
help_doc: 
	$(Q)$(PYTHON) scripts/help_doc.py
help_fsm:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen help


# SETUP FOLDER STRUCTURE
setup: 
	@echo "\n$(ORANGE)Setup Folder Structure...\n$(RESET)"
	$(Q)$(MKDIR) -p $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) \
	 $(SIGNOFFDIR) $(SIGNOFFDIR)/sdf $(MODELDIR) $(UTILDIR) $(DOCDIR) \
	 $(DATADIR) $(DRIVERDIR) $(LINTDIR) $(PYDIR) $(FSMDIR) $(ORSDIR)

# HJSON TEMPLATE GENERATION
hjson: setup
	@echo "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) scripts/hjson_gen.py $(OVERWRITE) -top $(TOP) -itf $(REG_ITF) -o $(DATADIR) 

# SV REGISTER GENERATOR
reg:
	@echo "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)./$(UTILDIR)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

# MARKDOWN GENERATOR
.PHONY: doc
doc:
	@echo "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)./$(UTILDIR)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)./$(UTILDIR)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

# RTL base generator
rtl_stub:
	@echo "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) scripts/rtl_stub_gen.py $(OVERWRITE) -i $(DATADIR)/$(TOP).hjson -itf $(REG_ITF) -o $(RTLDIR)

# Basic IP start flow
ip_start: setup hjson reg doc rtl_stub setup_tb sim

# File list generation
flist:
	$(Q)$(PYTHON) scripts/gen_filelist.py --top $(TOP)

# SV to single Verilog file
sv2v: clean_rtl
	@echo "\n$(ORANGE)SystemVerilog to Verilog conversion...\n$(RESET)"
	$(Q)$(SV2V) -v -I ips/pkgs ips/pkgs/*.sv ips/prim/*.sv ips/prim_opentitan/*.sv ips/tlul/*.sv rtl/*.sv \
	> $(RTLDIR)/$(TOP).v
# FETCH VENDOR FROM HJSON
fetch:
	$(Q)$(UTILDIR)/vendor.py --update vendor/$(VENDOR).vendor.hjson

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
	
# SETUP SV TESTBENCH FILE
setup_tb: flist
	@echo "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(Q)$(PYTHON) scripts/setup_tb.py $(OVERWRITE) -top $(TOP) -rtldir $(RTLDIR) \
	$(SOC_MEMORY_MAP) -simdir $(SIMDIR) -syndir $(SYNDIR) -prim $(PRIM) \
	-clk $(CLK_PERIOD) -comp $(COMPILER) -itf $(REG_ITF) -vsv $(VSV) -o $(TBDIR)

#########################################################
# COMPILE THE TESTBENCH THAT INCLUDES ALL THE RTL FILES #
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
# SIMULATE TESTBENCH #
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

# VIEW WAVEFORMS RTL SIMULATION
view:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_tb.vcd $(VIEWER_CONF) & 

view_cocotb:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(TBDIR)/cocotb/$(TOP)_tb.vcd $(VIEWER_CONF) & 

# COCOTB
cocotb: 
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb

# REGRESSION
regression:
	$(Q)$(MKDIR) -p $(REGRESSIONDIR)
	$(Q)$(PYTHON) scripts/regression.py

############################
# RUN SYNTHESIS WITH YOSYS #
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

# Use it only if small design
plot_postsyn:
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_postsyn.dot 2>/dev/null &

.PHONY: view_presyn view_presyn_v view_presyn_sv
view_presyn: $(if $(filter v,$(VSV)),view_presyn_v,view_presyn_sv)

view_presyn_v: sv2v
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); \
	show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn' \
	$(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &

view_presyn_sv:
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	@echo "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p "\
  read_slang -I ips/pkgs -I ips/prim \
             -I ips/prim_opentitan -I ips/tlul \
             -D SYNTHESIS --ignore-assertions \
             -f rtl/rtl_list.f --top $(TOP) ; \
  prep -top $(TOP); select -clear; select -module $(MODULE) ; \
  show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn" \
	> $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot 2>/dev/null &


###################################################
###          COMPILE & SIMULATE SYNTHESIS       ###
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

# VIEW WAVEFORMS RTL SIMULATION
view_syn:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_syn_tb.vcd $(VIEWER_CONF) & 

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
###                  Power Analysis            ###
##################################################

power: setup_signoff 
	@echo "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl > $(LOGDIR)/$(TOP)_power.log 

# STA only violators
sta_violators: setup_signoff 
	@echo "\n$(ORANGE)Static Timing Analysis only timing violators...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta_violators.tcl > $(LOGDIR)/$(TOP)_sta.violators

# Path view of STA timing reports
path_view:
	@echo "\n$(ORANGE)Path view generation of STA report...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/path_view ;
	$(Q)$(PYTHON) $(UTILDIR)/interactiveReport.py -i $(LOGDIR)/$(PATH_VIEW_FILE) \
	-s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)
	
# Write SDF
sdf: setup_signoff
	@echo "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/sdf
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl > /dev/null 2>&1


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
# TESTBENCH HANDLING #
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

# SW DRIVERS
.PHONY: driver
driver:
	./$(UTILDIR)/regtool.py -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) scripts/driver_gen.py -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR) 

# FSM FLOW
fsm_example_load:
	$(Q)$(CP) fsm_gen/examples/* fsm_gen/inputs/

fsm2rtl:
	$(Q)$(CP) fsm_gen/outputs/$(FSM).sv $(RTLDIR)
	$(Q)$(CP) fsm_gen/outputs/$(FSM)_pkg.sv $(RTLDIR)
	$(Q)$(CP) fsm_gen/outputs/$(FSM).gtkw $(SIMDIR)
	$(Q)$(CP) fsm_gen/outputs/$(FSM)_tb.sv $(TBDIR)

fsm_setup:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen setup

.PHONY: fsm_gen
fsm_gen:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen gen PYTHON=$(PYTHON) FSM=$(FSM) 

fsm_plot:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen plot PYTHON=$(PYTHON) FSM=$(FSM) 

fsm_flow: fsm_setup fsm_gen fsm_plot

# BASIC FLOW:
ip_flow: reg doc lint sim syn sdf sta sta_violators power view
ip_flow_noreg: lint sim syn sdf sta sta_violators power view
ip_flow_all: ip_start syn sdf sta sta_violators power view pnr pnr_gui

# FUSESOC
fsoc_init:
	@echo "\n$(ORANGE)FuseSOC setup...\n$(RESET)"
	$(Q)$(PYTHON) scripts/setup_fsoc.py -prj $(PRJ) -top $(TOP) -rtldir $(RTLDIR) -lintdir $(LINTDIR)	-o . 

fsoc:
	$(Q)$(FUSESOC) --cores-root=. run --target $(TARGET) $(PRJ):ip:$(TOP)

# XBAR
xbar: xbar_init xbar_build

xbar_init:
	@echo "\n$(ORANGE)XBAR init ...\n$(RESET)"
	$(Q)$(PYTHON) scripts/xbar_init.py $(SOC_MEMORY_MAP) --host $(HOST) \
	--output $(DATADIR)/xbar_main.hjson

xbar_build:
	@echo "\n$(ORANGE)XBAR build ...\n$(RESET)"
	$(Q)$(UTILDIR)/tlgen.py -t $(DATADIR)/xbar_main.hjson \
	-o $(DATADIR)/autogen 2>/dev/null
	$(Q)$(CP) -r $(DATADIR)/autogen/rtl/autogen/* $(RTLDIR)
	$(Q)$(RM) -r $(RTLDIR)/autogen

###############################
###            SoC          ###
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

load-uart-host:
	$(Q)$(CP) ips/soc/$(RTLDIR)/uart* $(RTLDIR)/

copy-soc:
	$(Q)$(CP) ips/soc/$(RTLDIR)/* $(RTLDIR)/
	$(Q)$(CP) ips/soc/$(TBDIR)/* $(TBDIR)/
	$(Q)$(CP) top/autogen/xbar_main.sv $(RTLDIR)/ 
	$(Q)$(CP) top/autogen/tl_main_pkg.sv $(RTLDIR)/
	#$(Q)$(CP) top/soc.sv $(RTLDIR)/

copy-vendor:
	$(Q)$(foreach x,$(Q)$(LOWRISC_IPS),cp vendor/lowrisc_ip/ip/$(x)/rtl/* $(RTLDIR);)

#############
# TUTORIALS #
#############

full_tutorial:
	$(Q)$(MAKE) ip_start ip_flow pnr pnr_gui TOP=test

fsm_tutorial: setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl
	$(Q)$(MAKE) ip_flow_noreg TOP=$(FSM)

ip_tutorial:
	$(Q)$(MAKE) ip_load
	@echo "\n$(ORANGE)Run the IP flow ...\n$(RESET)"
	$(Q)$(MAKE) sim syn sdf sta sta_violators power view 

# SoC Processor-Less
soc_pless:
	$(Q)$(MAKE) ip_load TOP=tiny-soc
	$(Q)$(MAKE) sim syn sdf sta power view TOP=soc

# SoC with IBEX
soc_ibex_tutorial: soc_ibex_fetch soc_ibex

# SETUP COCOTB
setup_cocotb:
	$(Q)$(MKDIR) -p $(TBDIR)/cocotb
	$(Q)$(PYTHON) scripts/setup_cocotb.py --top $(TOP) --itf $(REG_ITF) \
	--rtl-dir $(RTLDIR) --output $(TBDIR)/cocotb --clk clk_i --rst rst_ni \
	--rst-active low --period-ns 10 --sim $(COMPILER) 

# DEFINE PYTHON MODELDIR
setup_model:
	$(Q)$(PYTHON) scripts/setup_model.py -top $(TOP) -o $(MODELDIR) 

# SETUP SDC FILE
setup_sdc:
	$(Q)$(PYTHON) scripts/setup_sdc.py $(TOP) $(CLK_PERIOD) -o $(ORSDIR)/$(TOP).sdc 

# SETUP SYNTHESIS WITH YOSYS 
setup_syn: setup_sdc
	$(Q)$(PYTHON) scripts/setup_syn.py -top $(TOP) -topdir $(RTLDIR) -sdcdir $(ORSDIR) \
	-liberty $(LIB_SYN) -clk $(CLK_PERIOD) -target $(TARGET_SYN) -opt $(TARGET_OPT) -o $(SYNDIR)  

# SETUP STA SCRIPT
setup_signoff: setup_sdc
	$(Q)$(PYTHON) scripts/setup_signoff.py -top $(TOP) -rtldir $(RTLDIR) -sdcdir $(ORSDIR) \
	-libs $(LIBS) -clk $(CLK_PERIOD) -activity $(ACTIVITY) -o $(SIGNOFFDIR) 

# SETUP P&R
setup_pnr:
	$(Q)$(PYTHON) scripts/setup_pnr.py $(TOP) --syn_strategy $(TARGET_OPT) --clk_period $(CLK_PERIOD) \
	--platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f --outdir $(ORSDIR)

# SAVE FSM
fsm_save:
	$(Q)$(MKDIR) -p $(FSMDIR)/$(FSM)/inputs $(FSMDIR)/$(FSM)/outputs
	$(Q)$(CP) -r fsm_gen/inputs/$(FSM)* $(FSMDIR)/$(FSM)/inputs || true
	$(Q)$(CP) -r fsm_gen/outputs/$(FSM)* $(FSMDIR)/$(FSM)/outputs || true
	@echo "\n$(ORANGE)$(FSM) FSM saved\n$(RESET)"	

# LOAD FSM
fsm_load: fsm_setup
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/inputs/* fsm_gen/inputs
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/outputs/* fsm_gen/outputs
	@echo "\n$(ORANGE)$(FSM) FSM loaded into fsm_gen\n$(RESET)"


# SAVE IP
ip_save: clean_sim clean_rtl
	$(Q)$(MKDIR) -p ips/$(TOP) 
	$(Q)$(CP) -r $(DATADIR)    ips/$(TOP) || true
	$(Q)$(CP) -r $(DOCDIR)     ips/$(TOP) || true
	$(Q)$(CP) -r $(DRIVERDIR)  ips/$(TOP) || true
	$(Q)$(CP) -r $(LINTDIR)    ips/$(TOP) || true
	$(Q)$(CP) -r $(RTLDIR)     ips/$(TOP) || true
	$(Q)$(CP) -r $(TBDIR)      ips/$(TOP) || true
	$(Q)$(CP) -r $(SIMDIR)     ips/$(TOP) || true
	$(Q)$(CP) -r $(SYNDIR)     ips/$(TOP) || true
	$(Q)$(CP) -r $(SIGNOFFDIR) ips/$(TOP) || true
	$(Q)$(CP) -r $(ORSDIR)     ips/$(TOP) || true
	$(Q)$(CP) -r $(LOGDIR)     ips/$(TOP) || true
	$(Q)$(CP) -r $(MODELDIR)   ips/$(TOP) || true
	$(Q)$(CP) -r $(PYDIR)      ips/$(TOP) || true
	$(Q)$(CP) -r $(FSMDIR)     ips/$(TOP) || true
	$(Q)$(CP)    $(TOP).core   ips/$(TOP) || true
	@echo "\n$(ORANGE)$(TOP) IP saved\n$(RESET)"

# LOAD IP
ip_load:
	@echo "\n$(ORANGE)$(TOP) Loaded\n$(RESET)"
	$(Q)$(CP) -r ips/$(TOP)/* .

# DEPENDENCIES
deps:
	@echo "\n$(ORANGE)Installing dependencies for IP development ...\n$(RESET)"
	sudo apt install -y make python3 python3-pip
	sed -i 's/\r$$//' deps.sh
	bash ./deps.sh ip
	pip install -r requirements.txt
	
deps-soc:
	@echo "\n$(ORANGE)Installing dependencies for SoC integration ...\n$(RESET)"
	bash ./deps.sh soc
	echo
	export PATH=$$PATH:/tools/riscv32/bin
	echo "export PATH=/tools/riscv32/bin" >> ~/.bashrc

# CLEAN
clean_doc:
	$(Q)$(RM) $(DOCDIR)/*
clean_log:
	$(Q)$(RM) $(LOGDIR)/*
clean_rtl:
	$(Q)$(RM) $(RTLDIR)/*.v
clean_sim:
	$(Q)$(RM) $(SIMDIR)/*.vvp
	$(Q)$(RM) $(SIMDIR)/*.vcd
	$(Q)$(RM) $(SIMDIR)/verilator
clean_cocotb:
	$(Q)$(RM) $(TBDIR)/cocotb/*.vcd 
	$(Q)$(RM) $(TBDIR)/cocotb/sim_build
	$(Q)$(RM) $(TBDIR)/cocotb/__py*
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb clean
clean_syn:
	$(Q)$(RM) $(SYNDIR)/*
clean_signoff: 
	$(Q)$(RM) $(SIGNOFFDIR)/sdf/*
	$(Q)$(RM) $(SIGNOFFDIR)/*.sdc
clean_pnr:
	$(Q)$(RM) $(ORSDIR)/*
	$(Q)$(RM) $(ORS_LOGS)
	$(Q)$(RM) $(ORS_REPORTS)
	$(Q)$(RM) $(ORS_RESULTS)
	$(Q)$(RM) $(ORS_OBJECTS)
clean_fsm:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean
clean_fsm_all:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean_all
clean_agent:
	$(Q)$(RM) flexsoc_make_agent/logs
	$(Q)$(RM) flexsoc_make_agent/runs
clean_fsoc:
	$(Q)$(RM) build
clean_soc:
	@echo "\n$(ORANGE)Cleaning SoC ...\n$(RESET)"
	$(Q)$(RM) build trace_core_00000000.log uart0.log  sim.fst*  sw/*.elf sw/*.o sw/*.csv \
		     tb/top_verilator.* soc.core xbar_main.hjson $(TOPDIR)
clean_sw:
	$(Q)$(MAKE) --no-print-dir -C sw clean
clean_vendor:
	$(Q)$(RM) vendor/lowrisc_ip
	$(Q)$(RM) vendor/lowrisc_ibex
	$(Q)$(RM) vendor/lowrisc_ip.lock.hjson
	$(Q)$(RM) vendor/lowrisc_ibex.lock.hjson
clean_subdir:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean
	$(Q)$(MAKE) --no-print-dir -C fsm_gen setup
clean: clean_log clean_rtl clean_sim clean_syn clean_signoff clean_pnr clean_subdir clean_fsoc clean_soc clean_sw clean_fsm
	$(Q)$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec $(RM) -f {} + > /dev/null 2>&1
	$(Q)$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	$(Q)$(CLEAR)
clean_all: clean_fsm_all clean_vendor clean_agent clean 
	$(Q)$(RM) *.core
	$(Q)$(RM) $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) $(ORSDIR) \
	$(MODELDIR) $(DATADIR) $(DOCDIR) $(LINTDIR) $(DRIVERDIR) $(PYDIR) $(FSMDIR) > /dev/null 2>&1
