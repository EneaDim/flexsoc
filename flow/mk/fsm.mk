# FSM FLOW
fsm_example_load:
	$(Q)$(CP) fsm_gen/examples/* fsm_gen/inputs/

fsm2rtl:
	$(Q)$(CP) fsm_gen/outputs/$(FSM).sv $(RTLDIR)
	$(Q)$(CP) fsm_gen/outputs/$(FSM)_pkg.sv $(RTLDIR)
	$(Q)$(CP) fsm_gen/outputs/$(FSM).gtkw $(SIMDIR)
	$(Q)$(CP) fsm_gen/outputs/$(FSM)_tb.sv $(TBDIR)

fsm_setup:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen setup

.PHONY: fsm_gen
fsm_gen:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen gen PYTHON=$(PYTHON) FSM=$(FSM) 

fsm_plot:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen plot PYTHON=$(PYTHON) FSM=$(FSM) 

fsm_flow: fsm_setup fsm_gen fsm_plot

# SAVE FSM
fsm_save:
	$(Q)$(MKDIR) -p $(FSMDIR)/$(FSM)/inputs $(FSMDIR)/$(FSM)/outputs
	$(Q)$(CP) -r fsm_gen/inputs/$(FSM)* $(FSMDIR)/$(FSM)/inputs || true
	$(Q)$(CP) -r fsm_gen/outputs/$(FSM)* $(FSMDIR)/$(FSM)/outputs || true
	@echo "\n$(ORANGE)$(FSM) FSM saved\n$(RESET)"	

# LOAD FSM
fsm_load: fsm_setup
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/inputs/* fsm_gen/inputs
	$(Q)$(CP) -r $(FSMDIR)/$(FSM)/outputs/* fsm_gen/outputs
	@echo "\n$(ORANGE)$(FSM) FSM loaded into fsm_gen\n$(RESET)"
