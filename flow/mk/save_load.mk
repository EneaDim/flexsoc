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
