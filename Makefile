include config.mk

# HELP
help: 
	$(PYTHON) scripts/help.py
help_doc: 
	$(PYTHON) scripts/help_doc.py
help_fsm:
	$(MAKE) -C fsm_gen help


# SETUP FOLDER STRUCTURE
setup_fsm:
	$(MAKE) -C fsm_gen setup

setup: setup_fsm
	@$(ECHO) "\n$(ORANGE)Setup Folder Structure...\n$(RESET)"
	@$(MKDIR) -p $(LOGDIR) $(RTLDIR) $(REGRESSIONDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) \
	$(SIGNOFFDIR) $(SIGNOFFDIR)/sdf $(MODELDIR) $(UTILDIR) $(DOCDIR) $(DATADIR)

# HJSON TEMPLATE GENERATION
hjson:
	@$(ECHO) "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(PYTHON) scripts/hjson_gen.py -top $(TOP) -o $(DATADIR) 

# MARKDOWN GENERATOR
.PHONY: doc
doc:
	@$(ECHO) "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	./$(UTILDIR)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	./$(UTILDIR)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

# SV to single Verilog file
sv2v: clean_rtl
	@$(ECHO) "\n$(ORANGE)SystemVerilog to Verilog conversion...\n$(RESET)"
	$(SV2V) -v $(RTLDIR)/*.sv > $(RTLDIR)/$(TOP).v

# LINTING
lint: sv2v
	@$(ECHO) "\n$(ORANGE)Linting...\n$(RESET)"
	$(LINTER) $(LINT_FLAGS) $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
lint_sv:
	@$(ECHO) "\n$(ORANGE)Linting...\n$(RESET)"
	$(LINTER) $(LINT_FLAGS) $(LIST_FILES) --top-module $(TOP) $(RTLDIR)/$(TOP).sv \
	> $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
# SETUP SV TESTBENCH FILE
setup_tb:
	@$(ECHO) "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(PYTHON) scripts/setup_tb.py -top $(TOP) -rtldir $(RTLDIR) -simdir $(SIMDIR) \
	-syndir $(SYNDIR) -prim $(PRIM) -clk $(CLK_PERIOD) -o $(TBDIR)

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
	./$(SIMDIR)/$(COMPILER)/V$(TESTBENCH)_tb >> $(LOGDIR)/$(TESTBENCH)_sim.log 2>&1
endif

# VIEW WAVEFORMS RTL SIMULATION
view:
	@$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
	$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/dump_$(TESTBENCH).vcd $(VIEWER_CONF) & 

# COCOTB
cocotb: 
	$(MAKE) -C $(TBDIR)

# REGRESSION
regression:
	@$(MKDIR) -p $(REGRESSIONDIR) ; \
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
	$(YOSYS) -p 'prep -top $(TOP); select -module $(MODULE); show' $(RTLDIR)/$(TOP).v

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
	./$(SIMDIR)/$(COMPILER)/V$(TOP)_tb >> $(LOGDIR)/$(TOP)_sim_syn.log 2>&1
endif

# VIEW WAVEFORMS RTL SIMULATION
view_syn:
	@$(ECHO) "\n$(ORANGE)Viewing...\n$(RESET)"
	$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/dump_$(TESTBENCH)_syn.vcd $(VIEWER_CONF) & 

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

# SV REGISTER GENERATOR
reg:
	@$(ECHO) "\n$(ORANGE)Generating REGMAP from hjson description...$(RESET)"
	@$(ECHO) "$(ORANGE)Compilation of REGMAP still not supported...$(RESET)"
	@$(ECHO) "$(ORANGE)(FUSESOC flow to be added to handle dependecies)\n$(RESET)"
	./$(UTILDIR)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

# BASIC FLOW:
flow_all: hjson doc lint sim view_presyn syn sdf sta sta_violators power sim_syn
flow: hjson doc lint sim syn sdf sta

# FSM GENERATOR
.PHONY: fsm_gen
fsm_gen:
	$(MAKE) -C fsm_gen gen

fsm_plot:
	$(MAKE) -C fsm_gen plot

# SETUP COCOTB
setup_cocotb:
	$(PYTHON) scripts/setup_cocotb.py -top $(TOP) -o $(TBDIR) 

# DEFINE PYTHON MODELDIR
setup_model:
	$(PYTHON) scripts/setup_model.py -top $(TOP) -o $(MODELDIR) 

# SETUP SYNTHESIS WITH YOSYS 
setup_syn: sv2v
	$(PYTHON) scripts/setup_syn.py -top $(TOP) -topdir $(RTLDIR) -target $(TARGET) \
	-liberty $(LIB_SYN) -clk $(CLK_PERIOD) -o $(SYNDIR) 

# SETUP STA SCRIPT
setup_signoff:
	$(PYTHON) scripts/setup_signoff.py -top $(TOP) -tb $(TESTBENCH) -rtldir $(RTLDIR) \
	-libs $(LIBS) -clk $(CLK_PERIOD) -activity $(ACTIVITY) -o $(SIGNOFFDIR) 

# SIMULATE WITH COCOTB
sim_cocotb:
	$(MAKE) -C ${TBDIR}

# LINT FUSESOC
fsoc_lint:
	@$(ECHO) "\n$(ORANGE)Lint with fusesoc...\n$(RESET)"
	@$(FUSESOC) --cores-root=./cores/ run --target lint $(PRJ):$(TOP):$(TOP)

# CLEAN ENV
fsm_clean:
	$(MAKE) -C fsm_gen clean

clean_log:
	$(RM) $(LOGDIR)/*
clean_rtl:
	$(RM) $(RTLDIR)/*.v
clean_sim:
	$(RM) $(SIMDIR)/*.vvp
	$(RM) $(SIMDIR)/*.vcd
	$(RM) $(SIMDIR)/verilator
clean_regression:
	$(RM) $(LOGDIR)/regression/*
	$(RM) $(SIMDIR)/regression/*
clean_syn:
	$(RM) $(SYNDIR)/*
clean_signoff: 
	$(RM) $(SIGNOFFDIR)/sdf/*
	$(RM) $(SIGNOFFDIR)/*.sdc
	$(RM) $(SIGNOFFDIR)/*.tcl
	$(RM) $(SIGNOFFDIR)/path_view
clean_subdir:
	$(MAKE) -C fsm_gen clean
	$(MAKE) -C fsm_gen setup
clean: clean_log clean_rtl clean_sim clean_syn clean_signoff clean_subdir clean_regression 
	@$(FIND) . -type f \( -name '*~' -o -name '.*' \) -exec rm -f {} + > /dev/null 2>&1
	@$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	@$(CLEAR)
clean_all: clean
	$(RM)  $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) \
	$(SIGNOFFDIR) $(MODELDIR) $(DATADIR) $(DOCDIR) > /dev/null 2>&1
