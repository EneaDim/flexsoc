# HJSON TEMPLATE GENERATION
hjson: setup
	@echo "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) scripts/hjson_gen.py $(OVERWRITE) -top $(TOP) -itf $(REG_ITF) -o $(DATADIR) 

# SV REGISTER GENERATOR
reg:
	@echo "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)$(UTILROOT)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

# MARKDOWN GENERATOR
.PHONY: doc
doc:
	@echo "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)$(UTILROOT)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)$(UTILROOT)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

# RTL base generator
rtl_stub:
	@echo "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) scripts/rtl_stub_gen.py $(OVERWRITE) -i $(DATADIR)/$(TOP).hjson -itf $(REG_ITF) -o $(RTLDIR)

# Basic IP start flow
ip_start: setup hjson reg doc rtl_stub setup_tb sim

# File list generation
flist:
	$(Q)$(PYTHON) scripts/gen_filelist.py --top $(TOP) --out $(RTLDIR)/rtl_list.f --ips-root $(abspath ../hw/ips) --rtldir $(RTLDIR)

# SW DRIVERS
.PHONY: driver
driver:
	$(Q)$(UTILROOT)/regtool.py -D -o $(DRIVERDIR)/$(TOP).h $(DATADIR)/$(TOP).hjson
	$(Q)$(PYTHON) scripts/driver_gen.py -i $(DATADIR)/$(TOP).hjson -b $(MOD_ADD) -o $(DRIVERDIR)

# Fetch ip from github
fetch:
	$(Q)$(UTILROOT)/vendor.py --update vendor/$(VENDOR).vendor.hjson
