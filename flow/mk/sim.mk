# SETUP SV TESTBENCH FILE
setup_tb: flist
	@echo "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(Q)$(PYTHON) scripts/setup_tb.py $(OVERWRITE) -top $(TOP) -rtldir $(RTLDIR) \
	$(SOC_MEMORY_MAP) -simdir $(SIMDIR) -syndir $(SYNDIR) -prim $(PRIM) \
	-clk $(CLK_PERIOD) -comp $(COMPILER) -itf $(REG_ITF) -vsv $(VSV) -o $(TBDIR)

# COMPILE THE TESTBENCH THAT INCLUDES ALL THE RTL FILES #
# SIMULATE TESTBENCH #
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

# VIEW WAVEFORMS RTL SIMULATION
view_syn:
	@echo "\n$(ORANGE)Viewing...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) $(SIMDIR)/$(TOP)_syn_tb.vcd $(VIEWER_CONF) &
