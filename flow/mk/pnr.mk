#################################################
###        Place & Route with OpenROAD        ###
#################################################

.PHONY: pnr pnr_gui

pnr: setup_pnr
	@echo "\n$(ORANGE)Doing Place&Route...\n$(RESET)"
	$(Q)mkdir -p $(LOGDIR)
	$(Q)mkdir -p $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad
	$(Q)cd $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad && \
	$(MAKE) --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk \
	> $(LOGDIR)/$(TOP)_pnr.log 2>/dev/null

pnr_gui:
	$(Q)mkdir -p $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad
	$(Q)cd $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad && \
	$(MAKE) gui_final --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk 2>/dev/null &
