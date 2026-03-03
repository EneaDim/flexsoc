.PHONY: setup setup_tb setup_cocotb setup_model setup_sdc setup_syn setup_signoff setup_pnr


# SETUP FOLDER STRUCTURE
setup:
	@echo "\n$(ORANGE)Setup Folder Structure...\n$(RESET)"
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	$(Q)$(MKDIR) -p \
		$(LOGDIR) \
		$(RTLDIR) \
		$(TBDIR) \
		$(SIMDIR) \
		$(SYNDIR) \
		$(SIGNOFFDIR) \
		$(SIGNOFFDIR)/sdf \
		$(MODELDIR) \
		$(DOCDIR) \
		$(DATADIR) \
		$(DRIVERDIR) \
		$(LINTDIR) \
		$(PYDIR) \
		$(FSMDIR) \
		$(ORSDIR)

# SETUP SV TESTBENCH FILE
# NOTE: keep setup_tb working: same script + args, but ensure dirs exist.
setup_tb: setup flist
	@echo "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR) $(SIMDIR) $(SYNDIR) $(RTLDIR)
	$(Q)$(PYTHON) scripts/setup_tb.py $(OVERWRITE) \
		-top $(TOP) \
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

# SETUP COCOTB
setup_cocotb: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR)/cocotb
	$(Q)$(PYTHON) scripts/setup_cocotb.py \
		--top $(TOP) --itf $(REG_ITF) \
		--rtl-dir $(RTLDIR) --output $(TBDIR)/cocotb \
		--clk clk_i --rst rst_ni --rst-active low --period-ns 10 \
		--sim $(COMPILER)

# DEFINE PYTHON MODELDIR
setup_model: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(MODELDIR)
	$(Q)$(PYTHON) scripts/setup_model.py -top $(TOP) -o $(MODELDIR)

# SETUP SDC FILE
setup_sdc: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) scripts/setup_sdc.py $(TOP) $(CLK_PERIOD) -o $(ORSDIR)/$(TOP).sdc

# SETUP SYNTHESIS WITH YOSYS
setup_syn: setup_sdc flist
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SYNDIR)
	$(Q)$(PYTHON) scripts/setup_syn.py \
		-top $(TOP) -topdir $(RTLDIR) -sdcdir $(ORSDIR) \
		--filelist $(RTLDIR)/rtl_list.f \
		-liberty $(LIB_SYN) -clk $(CLK_PERIOD) \
		-target $(TARGET_SYN) -opt $(TARGET_OPT) \
		-o $(SYNDIR)

# SETUP STA SCRIPT
setup_signoff: setup_sdc syn
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)
	$(Q)$(PYTHON) scripts/setup_signoff.py \
		-top $(TOP) -rtldir $(RTLDIR) \
		-sdcdir $(ORSDIR) -syndir $(SYNDIR) -simdir $(SIMDIR) \
		-libs $(LIBS) -clk $(CLK_PERIOD) -activity $(ACTIVITY) \
		-o $(SIGNOFFDIR)

# SETUP P&R (OpenROAD config generation)
setup_pnr: setup flist
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) scripts/setup_pnr.py $(TOP) \
	  --syn_strategy $(TARGET_OPT) --clk_period $(CLK_PERIOD) \
	  --platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f \
		--outdir $(ORSDIR) $(if $(strip $(OVERWRITE)),--overwrite,)
