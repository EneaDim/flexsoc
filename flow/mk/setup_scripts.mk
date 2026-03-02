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
setup_syn: setup_sdc flist
	$(Q)$(PYTHON) scripts/setup_syn.py -top $(TOP) -topdir $(RTLDIR) -sdcdir $(ORSDIR) \
	--filelist $(RTLDIR)/rtl_list.f \
	-liberty $(LIB_SYN) -clk $(CLK_PERIOD) -target $(TARGET_SYN) -opt $(TARGET_OPT) -o $(SYNDIR)  

# SETUP STA SCRIPT
setup_signoff: setup_sdc syn
	$(Q)$(PYTHON) scripts/setup_signoff.py -top $(TOP) -rtldir $(RTLDIR) -sdcdir $(ORSDIR) \
	--syndir $(SYNDIR) \
	-libs $(LIBS) -clk $(CLK_PERIOD) -activity $(ACTIVITY) -o $(SIGNOFFDIR) 

# SETUP P&R
setup_pnr:
	$(Q)$(PYTHON) scripts/setup_pnr.py $(TOP) --syn_strategy $(TARGET_OPT) --clk_period $(CLK_PERIOD) \
	--platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f --outdir $(ORSDIR)
