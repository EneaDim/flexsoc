include config.mk

# HELP
help: 
	$(PYTHON) scripts/help.py
help_doc: 
	$(PYTHON) scripts/help_doc.py
help_fsm:
	$(MAKE) -C fsm_gen help


# SETUP FOLDER STRUCTURE
setup: 
	@$(ECHO) "\n$(ORANGE)Setup Folder Structure...\n$(RESET)"
	@$(MKDIR) -p $(LOGDIR) $(RTLDIR) $(REGRESSIONDIR) $(TBDIR) \
	 $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) $(SIGNOFFDIR)/sdf $(MODELDIR) \
	 $(UTILDIR) $(DOCDIR) $(DATADIR) $(LINTDIR)

# HJSON TEMPLATE GENERATION
hjson:
	@$(ECHO) "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(PYTHON) scripts/hjson_gen.py -top $(TOP) -o $(DATADIR) 

# SV REGISTER GENERATOR
reg:
	@$(ECHO) "\n$(ORANGE)Generating REGMAP from hjson description...$(RESET)"
	./$(UTILDIR)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

# MARKDOWN GENERATOR
.PHONY: doc
doc:
	@$(ECHO) "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	./$(UTILDIR)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	./$(UTILDIR)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

# FETCH VENDOR FROM HJSON
fetch:
	$(UTILDIR)/vendor.py --update vendor/$(VENDOR).vendor.hjson

# SV to single Verilog file
sv2v: clean_rtl
	@$(ECHO) "\n$(ORANGE)SystemVerilog to Verilog conversion...\n$(RESET)"
	$(SV2V) -v -I ips/pkgs ips/pkgs/*.sv ips/prim_opentitan/*.sv ips/tlul/*.sv rtl/*.sv > $(RTLDIR)/$(TOP).v

# LINTING
lint: sv2v
	@$(ECHO) "\n$(ORANGE)Linting...\n$(RESET)"
	$(LINTER) $(LINT_FLAGS) $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
lint_sv:
	@$(ECHO) "\n$(ORANGE)Linting...\n$(RESET)"
	$(LINTER) $(LINT_FLAGS) $(LINT_FILES) --top-module $(TOP) $(RTLDIR)/$(TOP).sv \
	> $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
# SETUP SV TESTBENCH FILE
setup_tb:
	@$(ECHO) "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(PYTHON) scripts/setup_tb.py -top $(TOP) -rtldir $(RTLDIR) -simdir $(SIMDIR) \
	-syndir $(SYNDIR) -prim $(PRIM) -clk $(CLK_PERIOD) -comp $(COMPILER) -o $(TBDIR)

# COMPILE THE TESTBENCH THAT INCLUDES ALL THE RTL FILES
compile: lint
ifeq ($(COMPILER), iverilog)
	@$(ECHO) "\n$(ORANGE)Compiling...\n$(RESET)"
	$(COMPILER) $(IVERILOG_FLAGS) -o $(SIMDIR)/$(TESTBENCH).vvp $(TBDIR)/$(TESTBENCH).sv \
	> $(LOGDIR)/$(TOP)_compile.log 2>&1
else
	@$(ECHO) "\n$(ORANGE)Compiling...\n$(RESET)"
	$(COMPILER) ${VERILATOR_FLAGS} $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_compile.log 2>&1
endif

# SIMULATE TESTBENCH
.PHONY: sim
sim: compile 
ifeq ($(COMPILER), iverilog)
	@$(ECHO) "\n$(ORANGE)Simulating...\n$(RESET)"
	vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TESTBENCH)_sim.log
else
	@$(ECHO) "\n$(ORANGE)Simulating...\n$(RESET)"
	$(COMPILER) ${VERILATOR_FLAGS} --trace $(TBDIR)/$(TESTBENCH).sv \
	> $(LOGDIR)/$(TOP)_sim.log 2>&1
	./$(SIMDIR)/$(COMPILER)/V$(TESTBENCH)
endif

# VIEW WAVEFORMS RTL SIMULATION
view:
	@$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
	$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/dump_$(TOP).vcd $(VIEWER_CONF) & 

# COCOTB
cocotb: 
	$(MAKE) -C $(TBDIR)

# REGRESSION
regression:
	@$(MKDIR) -p $(REGRESSIONDIR)\
	$(PYTHON) scripts/regression.py

# RUN SYNTHESIS WITH YOSYS
.PHONY: syn
syn: clean_rtl setup_syn
	@$(ECHO) "\n$(ORANGE)Synthesis with Yosys...\n$(RESET)"
	$(YOSYS) $(SYNDIR)/synth.ys > $(LOGDIR)/$(TOP)_synth.log 
	@$(GREP) -i "warning" $(LOGDIR)/$(TOP)_synth.log > $(LOGDIR)/$(TOP)_synth.warnings || true
	@$(GREP) -i "error" $(LOGDIR)/$(TOP)_synth.log > $(LOGDIR)/$(TOP)_synth.errors || true

view_presyn:
	@$(ECHO) "\n$(ORANGE)View netlist with Yosys...\n$(RESET)"
	$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); show' $(RTLDIR)/$(TOP).v \
	> $(LOGDIR)/$(TOP)_presyn.log 2>&1

# COMPILE POST SYNTHESIS NETLIST
compile_syn:
ifeq ($(COMPILER), iverilog)
	@$(ECHO) "\n$(ORANGE)Compiling synthesis...\n$(RESET)"
	$(COMPILER) $(IVERILOG_FLAGS) -DSYN -o $(SIMDIR)/$(TOP)_syn_tb.vvp $(PRIM) $(TBDIR)/$(TOP)_tb.sv \
	> $(LOGDIR)/$(TOP)_compile_syn.log 2>&1
else
	@$(ECHO) "\n$(ORANGE)Compiling synthesis...\n$(RESET)"
	$(COMPILER) ${VERILATOR_FLAGS} -DSYN=1 --bbox-unsup $(PRIM) $(SYNDIR)/$(TOP)_synth.v  \
	> $(LOGDIR)/$(TOP)_compile_syn.log 2>&1
endif

# SIMULATE POST SYNTHESIS NETLIST
sim_syn: compile_syn
ifeq ($(COMPILER), iverilog)
	@$(ECHO) "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	vvp $(SIMDIR)/$(TOP)_syn_tb.vvp > $(LOGDIR)/$(TOP)_syn_sim.log \
	> $(LOGDIR)/$(TOP)_sim_syn.log
else
	@$(ECHO) "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	$(COMPILER) ${VERILATOR_FLAGS} -DSYN=1 --bbox-unsup --trace $(TBDIR)/$(TOP)_tb.sv \
	> $(LOGDIR)/$(TOP)_sim_syn.log 2>&1
	./$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) > $(LOGDIR)/$(TESTBENCH)_sim_syn.log 2>&1
endif

# VIEW WAVEFORMS RTL SIMULATION
view_syn:
	@$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
	$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/dump_$(TOP)_syn.vcd $(VIEWER_CONF) & 

# STA analysis
sta: setup_signoff 
	@$(ECHO) "\n$(ORANGE)Static Timing Analysis...\n$(RESET)"
	$(STA) -exit -no_init $(SIGNOFFDIR)/sta.tcl > $(LOGDIR)/$(TOP)_sta.log 
	@$(GREP) -i "warning" $(LOGDIR)/$(TOP)_sta.log > $(LOGDIR)/$(TOP)_sta.warnings || true 
	@$(GREP) -i "error" $(LOGDIR)/$(TOP)_sta.log > $(LOGDIR)/$(TOP)_sta.errors || true 

#Power analysis
power: setup_signoff 
	@$(ECHO) "\n$(ORANGE)Power Analysis, static and with .vcd...\n$(RESET)"
	$(STA) -exit -no_init $(SIGNOFFDIR)/power.tcl > $(LOGDIR)/$(TOP)_power.log 

# STA only violators
sta_violators: setup_signoff 
	@$(ECHO) "\n$(ORANGE)Static Timing Analysis only timing violators...\n$(RESET)"
	$(STA) -exit -no_init $(SIGNOFFDIR)/sta_violators.tcl > $(LOGDIR)/$(TOP)_sta.violators

# Path view of STA timing reports
path_view:
	@$(ECHO) "\n$(ORANGE)Path view generation of STA report...\n$(RESET)"
	@$(MKDIR) -p $(SIGNOFFDIR)/path_view ; \
	$(PYTHON) $(UTILDIR)/interactiveReport.py -i $(LOGDIR)/$(PATH_VIEW_FILE) \
	-s $(UTILDIR)/default.svg -t opensta -n $(NPATHS)
	
# Write SDF
sdf: setup_signoff
	@$(ECHO) "\n$(ORANGE)Write sdf files...\n$(RESET)"
	$(STA) -exit -no_init $(SIGNOFFDIR)/write_sdf.tcl > /dev/null 2>&1

# SAVE TESTBENCH
save_tb:
	@$(ECHO) "\n$(ORANGE)Save testbench file...\n$(RESET)"
	@$(CP) $(TBDIR)/$(TOP)_tb.sv $(TBDIR)/$(TOP)_tb_ok.sv

# FUSESOC
fsoc_init:
	@$(ECHO) "\n$(ORANGE)FuseSOC setup...\n$(RESET)"
	$(PYTHON) scripts/setup_fsoc.py -prj $(PRJ) -top $(TOP) -rtldir $(RTLDIR) -lintdir $(LINTDIR)	-o . 

fsoc:
	@$(FUSESOC) --cores-root=. run --target $(TARGET) $(PRJ):ip:$(TOP)

# XBAR
xbar: xbar_init xbar_build

xbar_init:
	@$(ECHO) "\n$(ORANGE)XBAR hjson init, assuming ibex host ...\n$(RESET)"
	$(PYTHON) scripts/xbar_init.py $(SOC_MEMORY_MAP) --output xbar_main.hjson

xbar_build:
	@$(ECHO) "\n$(ORANGE)XBAR build ...\n$(RESET)"
	mkdir -p top/autogen ; \
	$(UTILDIR)/tlgen.py -t xbar_main.hjson -o top/autogen ; \
	rm -r top/autogen/dv ; \
	mv top/autogen/rtl/autogen/* top/autogen

# SoC

soc_flow: soc_build soc_sim soc_run 

soc_build:
	@$(ECHO) "\n$(ORANGE)SoC files building ...\n$(RESET)"
	@$(MKDIR) -p top
	@$(PYTHON) scripts/soc_gen.py -m uart $(TOP) -o top/soc.sv

soc_sim:
	@$(ECHO) "\n$(ORANGE)SoC simulation with FuseSoC ...\n$(RESET)"
	@$(FUSESOC) --cores-root=. run --target=sim --tool=verilator --setup --build enea:soc:main

soc_run:
	@$(ECHO) "\n$(ORANGE)GCC compilaiton of hello_world.c ...\n$(RESET)"
	$(MAKE) -C sw
	@$(ECHO) "\n$(ORANGE)Verilator run ... Press <CTRL>-C\n$(RESET)"
	build/enea_soc_main_0/sim-verilator/Vtop_verilator -t -E sw/main.elf

soc_view:
	@$(ECHO) "\n$(ORANGE)Viewing ...\n$(RESET)"
	$(VIEWER) $(VIEWER_FLAGS) sim.fst $(SIMDIR)/soc_$(TOP)_tb.gtkw&

full_flow:
	@$(ECHO) "\n$(ORANGE)$(TOP) IP load ...\n$(RESET)"
	$(MAKE) load_ip
	@$(ECHO) "\n$(ORANGE)Fetch lowrisc ips ...\n$(RESET)"
	$(MAKE) fetch VENDOR=lowrisc_ip
	@$(ECHO) "\n$(ORANGE)Fetch ibex ...\n$(RESET)"
	$(MAKE) fetch VENDOR=lowrisc_ibex
	@$(ECHO) "\n$(ORANGE)Generate xbar ...\n$(RESET)"
	$(MAKE) xbar
	$(MAKE) soc_flow

# FSM GENERATOR
fsm_tutorial: setup fsm_setup fsm_example fsm_gen fsm_plot
	@$(CP) fsm_gen/outputs/*.sv rtl
	@$(MAKE) setup_tb flow_all view

fsm_example:
	@$(CP) fsm_gen/examples/* fsm_gen/inputs/

fsm_setup:
	$(MAKE) -C fsm_gen setup

.PHONY: fsm_gen
fsm_gen:
	$(MAKE) -C fsm_gen gen PYTHON=$(PYTHON) FSM=$(TOP) 

fsm_plot:
	$(MAKE) -C fsm_gen plot PYTHON=$(PYTHON) FSM=$(TOP) 

# BASIC FLOW:
flow_all: hjson doc sim view_presyn syn sdf sta sta_violators power
flow: reg doc lint sim syn sdf sta power

# SETUP COCOTB
setup_cocotb:
	$(PYTHON) scripts/setup_cocotb.py -top $(TOP) -o $(TBDIR) 

# DEFINE PYTHON MODELDIR
setup_model:
	$(PYTHON) scripts/setup_model.py -top $(TOP) -o $(MODELDIR) 

# SETUP SYNTHESIS WITH YOSYS 
setup_syn: sv2v
	$(PYTHON) scripts/setup_syn.py -top $(TOP) -topdir $(RTLDIR) -target $(TARGET_SYN) \
	-liberty $(LIB_SYN) -clk $(CLK_PERIOD) -o $(SYNDIR) 

# SETUP STA SCRIPT
setup_signoff:
	$(PYTHON) scripts/setup_signoff.py -top $(TOP) -rtldir $(RTLDIR) -libs $(LIBS) \
	-clk $(CLK_PERIOD) -activity $(ACTIVITY) -o $(SIGNOFFDIR) 

# SIMULATE WITH COCOTB
sim_cocotb:
	$(MAKE) -C ${TBDIR}

# SAVE IP
save_ip:
	@$(MKDIR) -p ips/$(TOP) 
	@$(CP) -r $(DATADIR)    ips/$(TOP)
	@$(CP) -r $(DOCDIR)     ips/$(TOP)
	@$(CP) -r $(LINTDIR)    ips/$(TOP)
	@$(CP) -r $(RTLDIR)     ips/$(TOP)
	@$(CP) -r $(TBDIR)      ips/$(TOP)
	@$(CP) -r $(SIMDIR)     ips/$(TOP)
	@$(CP) -r $(SYNDIR)     ips/$(TOP)
	@$(CP) -r $(SIGNOFFDIR) ips/$(TOP)
	@$(CP) -r $(LOGDIR)     ips/$(TOP)
	@$(CP) -r $(MODELDIR)   ips/$(TOP)
	@$(CP)    $(TOP).core   ips/$(TOP)

# LOAD IP
load_ip:
	@$(CP) -r ips/$(TOP)/* .

# DEPENDENCIES
deps-ip:
	@$(ECHO) "\n$(ORANGE)Installing dependencies for IP development ...\n$(RESET)"
	source ./deps.sh ip

deps-soc:
	@$(ECHO) "\n$(ORANGE)Installing dependencies for SoC integration ...\n$(RESET)"
	source ./deps.sh soc

# CLEAN
clean_doc:
	$(RM) $(DOCDIR)/*
clean_log:
	$(RM) $(LOGDIR)/*
clean_rtl:
	$(RM) $(RTLDIR)/*.v
clean_sim:
	$(RM) $(SIMDIR)/*.vvp
	$(RM) $(SIMDIR)/*.vcd
	$(RM) $(SIMDIR)/verilator
clean_syn:
	$(RM) $(SYNDIR)/*
clean_signoff: 
	$(RM) $(SIGNOFFDIR)/sdf/*
	$(RM) $(SIGNOFFDIR)/*.sdc
	$(RM) $(SIGNOFFDIR)/*.tcl
	$(RM) $(SIGNOFFDIR)/path_view
clean_fsm:
	$(MAKE) -C fsm_gen clean
clean_fsm_all:
	$(MAKE) -C fsm_gen clean_all
clean_fsoc:
	$(RM) build
clean_soc:
	@$(ECHO) "\n$(ORANGE)Cleaning SoC ...\n$(RESET)"
	@$(RM) build trace_core_00000000.log uart0.log  sim.fst*  sw/*.elf sw/*.o sw/*.csv \
		     tb/top_verilator.* soc.core xbar_main.hjson top
clean_sw:
	$(MAKE) -C sw clean
clean_vendor:
	$(RM) vendor/lowrisc_ip
	$(RM) vendor/lowrisc_ibex
	$(RM) vendor/lowrisc_ip.lock.hjson
	$(RM) vendor/lowrisc_ibex.lock.hjson
clean_subdir:
	$(MAKE) -C fsm_gen clean
	$(MAKE) -C fsm_gen setup
clean: clean_log clean_rtl clean_sim clean_syn clean_signoff clean_subdir clean_fsoc clean_soc clean_sw clean_fsm
	@$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec rm -f {} + > /dev/null 2>&1
	@$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	@$(CLEAR)
clean_all: clean_fsm_all clean_vendor clean 
	@$(RM) $(TOP).core
	@$(RM) $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) \
	       $(MODELDIR) $(DATADIR) $(DOCDIR) $(LINTDIR) > /dev/null 2>&1
