#################################################
###        Place & Route with OpenROAD        ###
#################################################

pnr: setup_pnr 
	@echo "\n$(ORANGE)Doing Place&Route...\n$(RESET)"
	$(Q)$(MAKE) --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk > $(LOGDIR)/$(TOP)_pnr.log 2>/dev/null 

pnr_gui:
	$(Q)$(MAKE) gui_final --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk 2>/dev/null &


