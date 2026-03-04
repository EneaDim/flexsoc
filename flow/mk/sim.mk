# -----------------------------------------------------------------------------
# COMPILE / SIMULATE
# -----------------------------------------------------------------------------

.PHONY: compile compile_v compile_sv sim sim_v sim_sv

# VSV selects RTL input type:
#   sv -> use rtl_list.f (SystemVerilog)
#   v  -> use $(RTLDIR)/$(TOP).v (Verilog-only)
VSV ?= sv

compile: $(if $(filter v,$(VSV)),compile_v,compile_sv)
sim:     $(if $(filter v,$(VSV)),sim_v,sim_sv)

# -------------------------
# Verilog-only path (VSV=v)
# -------------------------

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
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) > $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

# -------------------------
# SystemVerilog path (VSV=sv)
# -------------------------

compile_sv: lint_sv flist
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
	$(Q)vvp $(SIMDIR)/$(TESTBENCH).vvp > $(LOGDIR)/$(TOP)_sim.log 2>&1
else
	$(Q)$(SIMDIR)/$(COMPILER)/V$(TESTBENCH) > $(LOGDIR)/$(TOP)_sim.log 2>&1
endif

# -----------------------------------------------------------------------------
# POST-SYNTHESIS COMPILE / SIM (iverilog + SDF)
# -----------------------------------------------------------------------------
.PHONY: compile_syn sim_syn

# Expected netlist output from synthesis (adjust if your syn target writes a different name)
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
	  -s $(TOP) \
	  $(IVERILOG_FLAGS) \
	  -o $(SIMDIR)/$(TOP)_syn_tb.vvp \
	  $(PRIM) \
	  $(SYN_NETLIST) \
	  $(TBDIR)/$(TESTBENCH).sv \
	  > $(LOGDIR)/$(TOP)_compile_syn.log 2>&1

sim_syn: compile_syn
	@echo "\n$(ORANGE)Simulating synthesis...\n$(RESET)"
	$(Q)vvp $(SIMDIR)/$(TOP)_syn_tb.vvp -sdf-verbose \
	  > $(LOGDIR)/$(TOP)_syn_sim.log 2>&1

# -----------------------------------------------------------------------------
# COCOTB
# -----------------------------------------------------------------------------
.PHONY: cocotb
cocotb:
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb

# -----------------------------------------------------------------------------
# VIEW WAVEFORMS
# -----------------------------------------------------------------------------
.PHONY: view view_cocotb view_syn

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
# REGRESSION
# -----------------------------------------------------------------------------
.PHONY: regression
regression:
	$(Q)$(MKDIR) -p $(REGRESSIONDIR)
	$(Q)$(PYTHON) scripts/regression.py
