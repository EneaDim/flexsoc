# -----------------------------------------------------------------------------
# Place & Route (OpenROAD) — workspace-rooted (no writes under flow/)
# -----------------------------------------------------------------------------

.PHONY: setup_pnr pnr pnr_gui

# Absolute paths (critical because we `cd` into a work directory)
OR_WORKDIR  := $(abspath $(OUTROOT))/pnr_openroad
OR_LOGDIR   := $(abspath $(LOGDIR))
OR_CFG_MK   := $(abspath $(ORSDIR))/config.mk
OR_MAKEFILE := $(ORS)/Makefile

setup_pnr:
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) scripts/setup_pnr.py $(TOP) --syn_strategy $(TARGET_OPT) --clk_period $(CLK_PERIOD) \
	  --platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f --outdir $(ORSDIR)

pnr: setup_pnr
	@echo "\n$(ORANGE)Doing Place&Route...\n$(RESET)"
	$(Q)$(MKDIR) -p $(OR_LOGDIR)
	$(Q)$(MKDIR) -p $(OR_WORKDIR)
	@log="$(OR_LOGDIR)/$(TOP)_pnr.log"; \
	cfg="$(OR_CFG_MK)"; \
	if [ ! -f "$$cfg" ]; then \
		echo "ERROR: OpenROAD config.mk not found: $$cfg"; \
		exit 2; \
	fi; \
	cd "$(OR_WORKDIR)" && \
	$(MAKE) --file="$(OR_MAKEFILE)" --no-print-dir \
	  DESIGN_CONFIG="$$cfg" \
	  > "$$log" 2>&1 || { \
		echo "ERROR: OpenROAD PnR failed. See log: $$log"; \
		exit 2; \
	  }

pnr_gui: setup_pnr
	$(Q)$(MKDIR) -p $(OR_WORKDIR)
	@cfg="$(OR_CFG_MK)"; \
	if [ ! -f "$$cfg" ]; then \
		echo "ERROR: OpenROAD config.mk not found: $$cfg"; \
		exit 2; \
	fi; \
	cd "$(OR_WORKDIR)" && \
	$(MAKE) gui_final --file="$(OR_MAKEFILE)" --no-print-dir \
	  DESIGN_CONFIG="$$cfg" 2>/dev/null &
