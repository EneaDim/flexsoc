# XBAR
xbar: xbar_init xbar_build

xbar_init:
	@echo "\n$(ORANGE)XBAR init ...\n$(RESET)"
	$(Q)$(PYTHON) scripts/xbar_init.py $(SOC_MEMORY_MAP) --host $(HOST) \
	--output $(DATADIR)/xbar_main.hjson

xbar_build:
	@echo "\n$(ORANGE)XBAR build ...\n$(RESET)"
	$(Q)$(UTILROOT)/tlgen.py -t $(DATADIR)/xbar_main.hjson \
	-o $(DATADIR)/autogen 2>/dev/null
	$(Q)$(CP) -r $(DATADIR)/autogen/rtl/autogen/* $(RTLDIR)
	$(Q)$(RM) -r $(RTLDIR)/autogen

###            SoC          ###
# SoC Processor-Less
soc_pless:
	$(Q)$(MAKE) ip_load TOP=tiny-soc
	$(Q)$(MAKE) sim syn sdf sta power view TOP=soc

# SoC with IBEX
soc_ibex_tutorial: soc_ibex_fetch soc_ibex
