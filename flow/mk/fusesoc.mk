# FUSESOC
fsoc_init:
	@echo "\n$(ORANGE)FuseSOC setup...\n$(RESET)"
	$(Q)$(PYTHON) scripts/setup_fsoc.py -prj $(PRJ) -top $(TOP) -rtldir $(RTLDIR) -lintdir $(LINTDIR)	-o . 

fsoc:
	$(Q)$(FUSESOC) --cores-root=. run --target $(TARGET) $(PRJ):ip:$(TOP)
