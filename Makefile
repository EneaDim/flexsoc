# Include configuration
include config.mk

# HELP
help:
	$(Q)echo "$(ORANGE)"
	$(Q)echo "Available make commands to start:"
	$(Q)echo ""
	$(Q)echo "    make help_ip     Show IP-related help"
	$(Q)echo "    make help_soc    Show SoC-related help"
	$(Q)echo "    make help_doc    Show documentation-related help"
	$(Q)echo "    make help_fsm    Show FSM generator help"
	$(Q)echo "$(RESET)"

help_ip:
	$(Q)$(PYTHON) scripts/help_ip.py
help_soc:
	$(Q)$(PYTHON) scripts/help_soc.py
help_doc: 
	$(Q)$(PYTHON) scripts/help_doc.py
help_fsm:
	$(Q)$(MAKE) -C fsm_gen help


# SETUP FOLDER STRUCTURE
setup: 
	$(Q)$(ECHO) "\n$(ORANGE)Setup Folder Structure...\n$(RESET)"
	$(Q)$(MKDIR) -p $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) \
	 $(SIGNOFFDIR) $(SIGNOFFDIR)/sdf $(MODELDIR) $(UTILDIR) $(DOCDIR) \
	 $(DATADIR) $(DRIVERDIR) $(LINTDIR) $(PYDIR) $(FSMDIR) $(ORSDIR)

# HJSON TEMPLATE GENERATION
hjson:
	$(Q)$(ECHO) "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) scripts/hjson_gen.py $(OVERWRITE) -top $(TOP) -itf $(REG_ITF) -o $(DATADIR) 

# SV REGISTER GENERATOR
reg:
	$(Q)$(ECHO) "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)./$(UTILDIR)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

# MARKDOWN GENERATOR
.PHONY: doc
doc:
	$(Q)$(ECHO) "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)./$(UTILDIR)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)./$(UTILDIR)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

# FETCH VENDOR FROM HJSON
fetch:
	$(Q)$(UTILDIR)/vendor.py --update vendor/$(VENDOR).vendor.hjson

# RTL base generator
rtl_stub:
	$(Q)$(ECHO) "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) scripts/rtl_stub_gen.py $(OVERWRITE) -i $(DATADIR)/$(TOP).hjson -itf $(REG_ITF) -o $(RTLDIR)

# Basic IP start flow
ip_start: setup hjson reg doc rtl_stub setup_tb sim

# SV to single Verilog file
sv2v: clean_rtl
	$(Q)$(ECHO) "\n$(ORANGE)SystemVerilog to Verilog conversion...\n$(RESET)"
	$(Q)$(SV2V) -v -I ips/pkgs ips/pkgs/*.sv ips/prim/*.sv ips/prim_opentitan/*.sv ips/tlul/*.sv rtl/*.sv \
	> $(RTLDIR)/$(TOP).v

# File list generation
flist:
	$(Q)$(PYTHON) scripts/gen_filelist.py --top $(TOP)

###########
# LINTING #
###########

.PHONY: lint lint_v lint_sv
lint: $(if $(filter v,$(Q)$(VSV)),lint_v,lint_sv)

lint_v: sv2v 
	$(Q)$(ECHO) "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
lint_sv: flist
	$(Q)$(ECHO) "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) -f $(RTLDIR)/rtl_list.f --top-module $(TOP) $(RTLDIR)/$(TOP).sv \
	> $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
# SETUP SV TESTBENCH FILE
setup_tb:
	$(Q)$(ECHO) "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(Q)$(PYTHON) scripts/setup_tb.py $(OVERWRITE) -top $(TOP) -rtldir $(RTLDIR) \
	-simdir $(SIMDIR) -syndir $(SYNDIR) -prim $(PRIM) -clk $(CLK_PERIOD) \
	-comp $(COMPILER) -itf $(REG_ITF) -vsv $(VSV) -o $(TBDIR)

#########################################################
# COMPILE THE TESTBENCH THAT INCLUDES ALL THE RTL FILES #
#########################################################

.PHONY: compile compile_v compile_sv
compile: $(if $(filter v,$(Q)$(VSV)),compile_v,compile_sv)

compile_v: lint_v
ifeq ($(Q)$(COMPILER), iverilog)
	$(Q)$(ECHO) "\n$(ORANGE)Compiling...\n$(RESET)"
	$(Q)$(COMPILER) $(IVERILOG_FLAGS) -o $(SIMDIR)/$(TESTBENCH).vvp $(TBDIR)/$(TESTBENCH).sv \
	> $(LOGDIR)/$(TOP)_compile.log 2>&1
else
	$(Q)$(ECHO) "\n$(ORANGE)Compiling...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_compile.log 2>&1
endif

compile_sv: lint_sv
	$(Q)$(ECHO) "\n$(ORANGE)Compiling...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} -f $(RTLDIR)/rtl_list.f > $(LOGDIR)/$(TOP)_compile.log 2>&1

######################
# SIMULATE TESTBENCH #
######################

.PHONY: sim sim_v sim_sv
sim: $(if $(filter v,$(VSV)),sim_v,sim_sv)

sim_v: compile_v
ifeq ($(Q)$(COMPILER), iverilog)
	$(Q)$(ECHO) "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TESTBENCH)_sim.log
else
	$(Q)$(ECHO) "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} --trace --trace-structs
	$(Q)$(TBDIR)/$(TESTBENCH).sv > $(LOGDIR)/$(TOP)_sim.log 2>&1
	$(Q)./$(SIMDIR)/$(COMPILER)/V$(Q)$(TESTBENCH)
endif

sim_sv: compile_sv
ifeq ($(Q)$(COMPILER), iverilog)
	$(Q)$(ECHO) "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TESTBENCH)_sim.log
else
	$(Q)$(ECHO) "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} -f $(RTLDIR)/rtl_list.f --top-module $(TOP)_tb \
	--trace --trace-structs $(TBDIR)/$(TESTBENCH).sv > $(LOGDIR)/$(TOP)_sim.log 2>&1
	$(Q)./$(SIMDIR)/$(COMPILER)/V$(TESTBENCH)
endif

# VIEW WAVEFORMS RTL SIMULATION
view:
	$(Q)$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_tb.vcd $(VIEWER_CONF) & 

view_cocotb:
	$(Q)$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(TBDIR)/cocotb/$(TOP)_tb.vcd $(VIEWER_CONF) & 

# COCOTB
cocotb: 
	$(Q)$(MAKE) -C $(TBDIR)/cocotb

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
	$(Q)$(ECHO) "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) $(SYNDIR)/synth.ys > $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

syn_sv: setup_syn
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	$(Q)$(ECHO) "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -s $(SYNDIR)/synth_sv.ys \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).warnings || true
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).log \
	> $(LOGDIR)/$(TOP)_synth_opt_$(TARGET_OPT).errors || true

yosys-vgen:
	$(Q)$(ECHO) "\n$(ORANGE)Verilog generation with Yosys...\n$(RESET)"
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
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_postsyn.dot &

.PHONY: view_presyn view_presyn_v view_presyn_sv
view_presyn: $(if $(filter v,$(VSV)),view_presyn_v,view_presyn_sv)

view_presyn_v: sv2v
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	$(Q)$(ECHO) "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); \
	show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn' \
	$(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot &

view_presyn_sv:
	$(Q)$(MKDIR) -p $(SYNDIR)/plots
	$(Q)$(ECHO) "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(Q)$(YOSYS) -m /usr/local/share/yosys/plugins/slang.so -p "\
  read_slang -I ips/pkgs -I ips/prim \
             -I ips/prim_opentitan -I ips/tlul \
             -D SYNTHESIS --ignore-assertions \
             -f rtl/rtl_list.f --top $(TOP) ; \
  prep -top $(TOP); select -clear; select -module $(MODULE) ; \
  show -width -format dot -prefix $(SYNDIR)/plots/$(TOP)_presyn" \
	> $(LOGDIR)/$(TOP)_presyn.log 2>&1
	$(Q)xdot $(SYNDIR)/plots/$(TOP)_presyn.dot &


###################################################
###          COMPILE & SIMULATE SYNTHESIS       ###
###################################################

compile_syn:
	$(Q)$(ECHO) "\n$(ORANGE)Compiling synthesis...\n$(RESET)"
	iverilog -g2012 -v -gspecify -s $(TOP)_tb -DSYN -DSIM \
	-o $(SIMDIR)/$(TOP)_syn_tb.vvp $(PRIM) $(TBDIR)/$(TOP)_tb.sv \
	> $(LOGDIR)/$(TOP)_compile_syn.log 2>&1

# SIMULATE POST SYNTHESIS NETLIST
sim_syn: compile_syn
	$(Q)$(ECHO) "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	vvp $(SIMDIR)/$(TOP)_syn_tb.vvp -sdf-verbose > $(LOGDIR)/$(TOP)_syn_sim.log 2>&1

# VIEW WAVEFORMS RTL SIMULATION
view_syn:
	$(Q)$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_syn.vcd $(VIEWER_CONF) & 

##################################################
###              Static Timing Analysis        ###
##################################################

sta: setup_signoff 
	$(Q)$(ECHO) "\n$(ORANGE)Static Timing Analysis...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl > $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log 
	$(Q)$(GREP) -i "warning" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).warnings || true 
	$(Q)$(GREP) -i "error" $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).log > $(LOGDIR)/$(TOP)_sta_opt_$(TARGET_OPT).errors || true 

##################################################
###                  Power Analysis            ###
##################################################

power: setup_signoff 
	$(Q)$(ECHO) "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl > $(LOGDIR)/$(TOP)_power.log 

# STA only violators
sta_violators: setup_signoff 
	$(Q)$(ECHO) "\n$(ORANGE)Static Timing Analysis only timing violators...\n$(RESET)"
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/sta_violators.tcl > $(LOGDIR)/$(TOP)_sta.violators

# Path view of STA timing reports
path_view:
	$(Q)$(ECHO) "\n$(ORANGE)Path view generation of STA report...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/path_view ;
	$(Q)$(PYTHON) $(UTILDIR)/interactiveReport.py -i $(LOGDIR)/$(PATH_VIEW_FILE) \
	-s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)
	
# Write SDF
sdf: setup_signoff
	$(Q)$(ECHO) "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)/sdf
	$(Q)$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl > /dev/null 2>&1


#################################################
###        Place & Route with OpenROAD        ###
#################################################

pnr: setup_pnr 
	$(Q)$(MAKE) --file=$(ORS)/Makefile DESIGN_CONFIG=$(ORSDIR)/config.mk

pnr_gui:
	$(Q)$(MAKE) gui_final --file=$(ORS)/Makefile DESIGN_CONFIG=$(ORSDIR)/config.mk &

######################
# TESTBENCH HANDLING #
######################

tb_save:
	$(Q)$(MKDIR) -p $(REGRESSIONDIR) $(REGRESSIONDIR)/$(TBDIR) $(REGRESSIONDIR)/$(SIMDIR)
	$(Q)$(ECHO) "\n$(ORANGE)Save testbench file...\n$(RESET)"
	$(Q)$(CP) $(TBDIR)/$(TOP)_tb.sv $(REGRESSIONDIR)/$(TBDIR)/$(TOP)_$(OUTNAME)_tb.sv
	$(Q)$(CP) $(SIMDIR)/$(TOP)_tb.vcd $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.vcd
	$(Q)$(CP) $(SIMDIR)/$(TOP)_tb.gtkw $(REGRESSIONDIR)/$(SIMDIR)/$(TOP)_$(OUTNAME)_tb.gtkw

tb_view:
	$(Q)$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
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
	$(Q)$(CP) fsm_gen/outputs/*.sv rtl

fsm_setup:
	$(Q)$(MAKE) -C fsm_gen setup

.PHONY: fsm_gen
fsm_gen:
	$(Q)$(MAKE) -C fsm_gen gen PYTHON=$(PYTHON) FSM=$(FSM) 

fsm_plot:
	$(Q)$(MAKE) -C fsm_gen plot PYTHON=$(PYTHON) FSM=$(FSM) 

fsm_flow: fsm_setup fsm_gen fsm_plot

# BASIC FLOW:
ip_flow: reg doc lint sim syn sdf sta sta_violators power view
ip_flow_noreg: lint sim syn sdf sta sta_violators power view
ip_flow_all: ip_start syn sdf sta sta_violators power view pnr pnr_gui

# FUSESOC
fsoc_init:
	$(Q)$(ECHO) "\n$(ORANGE)FuseSOC setup...\n$(RESET)"
	$(Q)$(PYTHON) scripts/setup_fsoc.py -prj $(PRJ) -top $(TOP) -rtldir $(RTLDIR) -lintdir $(LINTDIR)	-o . 

fsoc:
	$(Q)$(FUSESOC) --cores-root=. run --target $(TARGET) $(PRJ):ip:$(TOP)

# XBAR
xbar: xbar_init xbar_build

xbar_init:
	$(Q)$(MKDIR) -p $(TOPDIR)
	$(Q)$(ECHO) "\n$(ORANGE)XBAR hjson init, assuming ibex host ...\n$(RESET)"
	$(Q)$(PYTHON) scripts/xbar_init.py $(SOC_MEMORY_MAP) --host $(HOST) --output $(TOPDIR)/xbar_main.hjson

xbar_build:
	$(Q)$(ECHO) "\n$(ORANGE)XBAR build ...\n$(RESET)"
	$(Q)$(MKDIR) -p $(TOPDIR)/autogen
	$(Q)$(UTILDIR)/tlgen.py -t $(TOPDIR)/xbar_main.hjson -o $(TOPDIR)/autogen
	$(Q)$(RM) -r $(TOPDIR)/autogen/dv
	mv $(TOPDIR)/autogen/rtl/autogen/* $(TOPDIR)/autogen

###############################
###            SoC          ###
###############################

soc-uart-host: xbar soc_build
	$(Q)$(CP) top/autogen/xbar_main.sv $(RTLDIR)/ 
	$(Q)$(CP) top/autogen/tl_main_pkg.sv $(RTLDIR)/
	$(Q)$(CP) top/soc.sv $(RTLDIR)/
	

soc_flow: soc_build driver soc_sim soc_run 

soc_build:
	$(Q)$(ECHO) "\n$(ORANGE)SoC files building ...\n$(RESET)"
	$(Q)$(MKDIR) -p $(TOPDIR)
	$(Q)$(PYTHON) scripts/soc_gen.py -host $(HOST) $(SOC_MEMORY_MAP) -o $(TOPDIR)/soc.sv

soc_sim:
	$(Q)$(ECHO) "\n$(ORANGE)SoC simulation with FuseSoC ...\n$(RESET)"
	$(Q)$(FUSESOC) --cores-root=. run --target=sim --tool=verilator --setup --build enea:soc:main

soc_run:
	$(Q)$(ECHO) "\n$(ORANGE)GCC compilaiton of hello_world.c ...\n$(RESET)"
	$(Q)$(MAKE) -C sw
	$(Q)$(ECHO) "\n$(ORANGE)Verilator run ... Press <CTRL>-C\n$(RESET)"
	build/enea_soc_main_0/sim-verilator/Vtop_verilator -t -E sw/build/main.elf

soc_view:
	$(Q)$(ECHO) "\n$(ORANGE)Viewing ...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) sim.fst $(SIMDIR)/soc_$(Q)$(TOP)_tb.gtkw&

# SoC Processor-Less
soc_pless: ip_load xbar 
	$(Q)$(CP) top/autogen/xbar_main.sv $(RTLDIR)/ 
	$(Q)$(CP) top/autogen/tl_main_pkg.sv $(RTLDIR)/
	$(Q)$(MAKE) soc_build IPS="pwm gpio rv_timer"
	$(Q)$(CP) top/soc.sv $(RTLDIR)/
	$(Q)$(MAKE) sim syn sdf sta power view TOP=soc

copy-uart-host:
	$(Q)$(CP) ips/soc/$(RTLDIR)/uart* $(RTLDIR)/

copy-soc:
	$(Q)$(CP) ips/soc/$(RTLDIR)/* $(RTLDIR)/
	$(Q)$(CP) ips/soc/$(TBDIR)/* $(TBDIR)/
	$(Q)$(CP) top/autogen/xbar_main.sv $(RTLDIR)/ 
	$(Q)$(CP) top/autogen/tl_main_pkg.sv $(RTLDIR)/
	#$(Q)$(CP) top/soc.sv $(RTLDIR)/

copy-vendor:
	$(Q)$(foreach x,$(Q)$(LOWRISC_IPS),cp vendor/lowrisc_ip/ip/$(x)/rtl/* $(RTLDIR);)

# TUTORIALS

full_tutorial:
	$(Q)$(MAKE) ip_start ip_flow pnr pnr_gui TOP=test

fsm_tutorial: setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl
	$(Q)$(MAKE) setup_tb ip_flow_noreg plot_postsyn TOP=$(FSM)

ip_tutorial:
	$(Q)$(MAKE) ip_load
	$(Q)$(ECHO) "\n$(ORANGE)Run the IP flow ...\n$(RESET)"
	$(Q)$(MAKE) sim syn sdf sta sta_violators power view 

soc_tutorial:
	$(Q)$(ECHO) "\n$(ORANGE)$(TOP) IP load ...\n$(RESET)"
	$(Q)$(MAKE) ip_load
	$(Q)$(ECHO) "\n$(ORANGE)Fetch lowrisc ips ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	$(Q)$(ECHO) "\n$(ORANGE)Fetch ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex
	$(Q)$(ECHO) "\n$(ORANGE)Generate xbar ...\n$(RESET)"
	$(Q)$(MAKE) xbar HOST=ibex
	$(Q)$(MAKE) soc_flow HOST=ibex

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
save_fsm:
	$(Q)$(MKDIR) -p $(FSMDIR)/$(FSM)
	$(Q)$(CP) -r fsm_gen/inputs $(FSMDIR)/$(FSM) || true
	$(Q)$(CP) -r fsm_gen/outputs $(FSMDIR)/$(FSM) || true
	$(Q)$(ECHO) "\n$(ORANGE)$(FSM) FSM saved\n$(RESET)"

# LOAD FSM
load_fsm: fsm_setup
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/inputs/* fsm_gen/inputs
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/outputs/* fsm_gen/outputs
	$(Q)$(ECHO) "\n$(ORANGE)$(FSM) FSM loaded into fsm_gen\n$(RESET)"


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
	$(Q)$(ECHO) "\n$(ORANGE)$(TOP) IP saved\n$(RESET)"

# LOAD IP
ip_load:
	$(Q)$(ECHO) "\n$(ORANGE)$(TOP) IP loaded\n$(RESET)"
	$(Q)$(CP) -r ips/$(TOP)/* .

# DEPENDENCIES
deps:
	$(Q)$(ECHO) "\n$(ORANGE)Installing dependencies for IP development ...\n$(RESET)"
	sudo apt install -y make python3 python3-pip
	sed -i 's/\r$$//' deps.sh
	bash ./deps.sh ip
	pip install -r requirements.txt
	
deps-soc:
	$(Q)$(ECHO) "\n$(ORANGE)Installing dependencies for SoC integration ...\n$(RESET)"
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
	$(Q)$(MAKE) -C $(TBDIR)/cocotb clean
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
	$(Q)$(MAKE) -C fsm_gen clean
clean_fsm_all:
	$(Q)$(MAKE) -C fsm_gen clean_all
clean_fsoc:
	$(Q)$(RM) build
clean_soc:
	$(Q)$(ECHO) "\n$(ORANGE)Cleaning SoC ...\n$(RESET)"
	$(Q)$(RM) build trace_core_00000000.log uart0.log  sim.fst*  sw/*.elf sw/*.o sw/*.csv \
		     tb/top_verilator.* soc.core xbar_main.hjson $(TOPDIR)
clean_sw:
	$(Q)$(MAKE) -C sw clean
clean_vendor:
	$(Q)$(RM) vendor/lowrisc_ip
	$(Q)$(RM) vendor/lowrisc_ibex
	$(Q)$(RM) vendor/lowrisc_ip.lock.hjson
	$(Q)$(RM) vendor/lowrisc_ibex.lock.hjson
clean_subdir:
	$(Q)$(MAKE) -C fsm_gen clean
	$(Q)$(MAKE) -C fsm_gen setup
clean: clean_log clean_rtl clean_sim clean_syn clean_signoff clean_pnr clean_subdir clean_fsoc clean_soc clean_sw clean_fsm
	$(Q)$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec $(RM) -f {} + > /dev/null 2>&1
	$(Q)$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	$(Q)$(CLEAR)
clean_all: clean_fsm_all clean_vendor clean 
	$(Q)$(RM) *.core
	$(Q)$(RM) $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) $(ORSDIR) \
	$(MODELDIR) $(DATADIR) $(DOCDIR) $(LINTDIR) $(DRIVERDIR) $(PYDIR) $(FSMDIR) > /dev/null 2>&1
