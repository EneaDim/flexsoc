#################################################
###        Place & Route with OpenROAD        ###
#################################################


# Repo root (robust even when invoked with -C flow)
REPO_ROOT := $(abspath $(CURDIR)/..)

# Include dirs needed for OpenTitan prim_* (prim_assert.sv + macros)
OR_INC_DIRS :=   $(REPO_ROOT)/hw/ips/pkgs   $(REPO_ROOT)/hw/ips/prim_opentitan   $(REPO_ROOT)/hw/ips/prim_opentitan/rtl   $(REPO_ROOT)/hw/ips/prim_opentitan/include

.PHONY: pnr pnr_gui

pnr: setup_pnr
	@echo "\n$(ORANGE)Doing Place&Route...\n$(RESET)"
	$(Q)mkdir -p $(LOGDIR)
	$(Q)mkdir -p $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad
	$(Q)cd $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad && \
	$(MAKE) --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk \
	VERILOG_INCLUDE_DIRS="$(OR_INC_DIRS)" \
	> $(LOGDIR)/$(TOP)_pnr.log 2>&1 || { \
		echo "ERROR: OpenROAD PnR failed. See log: $(LOGDIR)/$(TOP)_pnr.log"; \
		exit 2; \
	}
pnr_gui:
	$(Q)mkdir -p $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad
	$(Q)cd $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/pnr_openroad && \
	$(MAKE) gui_final --file=$(ORS)/Makefile --no-print-dir \
	DESIGN_CONFIG=$(ORSDIR)/config.mk 2>&1 &
