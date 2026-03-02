# TESTBENCH HANDLING #
# SW DRIVERS
.PHONY: driver
driver:
	$(Q)$(UTILDIR)/regtool.py -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) scripts/driver_gen.py -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR)
