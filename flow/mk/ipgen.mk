# HJSON TEMPLATE GENERATION
hjson: setup
	@echo "\n$(ORANGE)Generating HJSON template file...\n$(RESET)"
	$(Q)$(PYTHON) scripts/hjson_gen.py $(OVERWRITE) -top $(TOP) -itf $(REG_ITF) -o $(DATADIR) 

# SV REGISTER GENERATOR
reg:
	@echo "\n$(ORANGE)Generating REGMAP from hjson description...\n$(RESET)"
	$(Q)./$(UTILDIR)/regtool.py -r -t $(RTLDIR) $(DATADIR)/$(TOP).hjson

# MARKDOWN GENERATOR
.PHONY: doc
doc:
	@echo "\n$(ORANGE)Generating documentation from hjson description...\n$(RESET)"
	$(Q)./$(UTILDIR)/regtool.py -d -o $(DOCDIR)/$(TOP).md $(DATADIR)/$(TOP).hjson
	$(Q)./$(UTILDIR)/regtool.py --interfaces -o $(DOCDIR)/$(TOP)_interfaces.md $(DATADIR)/$(TOP).hjson

# RTL base generator
rtl_stub:
	@echo "\n$(ORANGE)RTL stub generation...\n$(RESET)"
	$(Q)$(PYTHON) scripts/rtl_stub_gen.py $(OVERWRITE) -i $(DATADIR)/$(TOP).hjson -itf $(REG_ITF) -o $(RTLDIR)

# Basic IP start flow
ip_start: setup hjson reg doc rtl_stub setup_tb sim

# File list generation
flist:
	$(Q)$(PYTHON) scripts/gen_filelist.py --top $(TOP)

# SV to single Verilog file
sv2v: clean_rtl
	@echo "\n$(ORANGE)SystemVerilog to Verilog conversion...\n$(RESET)"
	$(Q)$(SV2V) -v -I ips/pkgs ips/pkgs/*.sv ips/prim/*.sv ips/prim_opentitan/*.sv ips/tlul/*.sv rtl/*.sv \
	> $(RTLDIR)/$(TOP).v
# FETCH VENDOR FROM HJSON
fetch:
	$(Q)$(UTILDIR)/vendor.py --update vendor/$(VENDOR).vendor.hjson
