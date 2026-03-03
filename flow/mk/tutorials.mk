# TUTORIALS #
full_tutorial:
	$(Q)$(MAKE) ip_start ip_flow pnr pnr_gui TOP=test

fsm_tutorial: setup fsm_setup fsm_example_load fsm_gen fsm_plot fsm2rtl
	$(Q)$(MAKE) ip_flow_noreg TOP=$(FSM)

ip_tutorial:
	$(Q)$(MAKE) ip_load
	@echo "\n$(ORANGE)Run the IP flow ...\n$(RESET)"
	$(Q)$(MAKE) sim syn sdf sta sta_violators power view

# SoC Processor-Less
soc_pless:
	$(Q)$(MAKE) ip_load TOP=tiny-soc
	$(Q)$(MAKE) sim syn sdf sta power view TOP=soc

# SoC with IBEX
soc_ibex_tutorial: soc_ibex_fetch soc_ibex
