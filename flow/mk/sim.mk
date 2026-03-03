# COMPILE
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

# SIMULATE
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
	$(Q)$(SIMDIR)/$(COMPILER)/V$(Q)$(TESTBENCH) > $(LOGDIR)/$(TOP)_sim.log 
endif

sim_sv: compile_sv
ifeq ($(Q)$(COMPILER), iverilog)
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TESTBENCH)_sim.log
else
	@echo "\n$(ORANGE)Simulating...\n$(RESET)"
	$(Q)$(COMPILER) ${VERILATOR_FLAGS} -f $(RTLDIR)/rtl_list.f --top-module $(TOP)_tb \
	--trace --trace-structs $(TBDIR)/$(TESTBENCH).sv > $(LOGDIR)/$(TOP)_sim.log 2>&1
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) > $(LOGDIR)/$(TOP)_sim.log 
endif

# Compile	Post Synthesis
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

# COCOTB
cocotb: 
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb

# VIEW WAVEFORMS RTL SIMULATION
view:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_tb.vcd $(VIEWER_CONF) & 

view_cocotb:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(TBDIR)/cocotb/$(TOP)_tb.vcd $(VIEWER_CONF) & 

# VIEW WAVEFORMS RTL SIMULATION
view_syn:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_syn_tb.vcd $(VIEWER_CONF) &

# REGRESSION
regression:
	$(Q)$(MKDIR) -p $(REGRESSIONDIR)
	$(Q)$(PYTHON) scripts/regression.py

