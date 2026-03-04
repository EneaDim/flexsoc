# -----------------------------------------------------------------------------
# FSM FLOW (tools/fsm_gen)
# -----------------------------------------------------------------------------
# fsm_gen tool lives under repo_root/tools
FSMGEN_DIR := $(REPO_ROOT)/tools/fsm_gen

.PHONY: fsm_example_load fsm_setup fsm_gen fsm_plot fsm_flow fsm2rtl fsm_save fsm_load

# Copy example FSM inputs into the tool inputs directory
fsm_example_load:
	$(Q)$(CP) $(FSMGEN_DIR)/examples/* $(FSMGEN_DIR)/inputs/ || true

# Run tool setup (creates venv/dirs inside tool)
fsm_setup:
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) setup

# Generate RTL/TB/etc for selected FSM
fsm_gen: fsm_setup
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) gen PYTHON=$(PYTHON) FSM=$(FSM)

# Plot FSM graph (optional)
fsm_plot: fsm_setup
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) plot PYTHON=$(PYTHON) FSM=$(FSM)

# Full flow
fsm_flow: fsm_gen fsm_plot

# Copy generated artifacts into the current run (workspace-rooted)
fsm2rtl:
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM).sv $(RTLDIR)/
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM)_pkg.sv $(RTLDIR)/
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM).gtkw $(SIMDIR)/ || true
	$(Q)$(CP) $(FSMGEN_DIR)/outputs/$(FSM)_tb.sv $(TBDIR)/

# Save FSM bundle into the run workspace under fsms/<fsm>/{inputs,outputs}
fsm_save:
	$(Q)$(MKDIR) -p $(FSMDIR)/$(FSM)/inputs $(FSMDIR)/$(FSM)/outputs
	$(Q)$(CP) -r $(FSMGEN_DIR)/inputs/$(FSM)* $(FSMDIR)/$(FSM)/inputs/ || true
	$(Q)$(CP) -r $(FSMGEN_DIR)/outputs/$(FSM)* $(FSMDIR)/$(FSM)/outputs/ || true
	@echo "\n$(ORANGE)$(FSM) FSM saved\n$(RESET)"

# Load FSM bundle from the run workspace into the tool (fsm_gen)
fsm_load: fsm_setup
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/inputs/* $(FSMGEN_DIR)/inputs/ || true
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/outputs/* $(FSMGEN_DIR)/outputs/ || true
	@echo "\n$(ORANGE)$(FSM) FSM loaded into fsm_gen\n$(RESET)"
