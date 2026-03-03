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
soc:
	@echo "\n$(ORANGE)SoC files building ...\n$(RESET)"
	$(Q)$(PYTHON) scripts/soc_gen.py -host $(HOST) $(SOC_MEMORY_MAP) -o $(RTLDIR)/soc.sv

soc_flow: xbar soc
	
soc_ibex_fetch:
	@echo "\n$(ORANGE)Fetch lowrisc ips ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ip
	@echo "\n$(ORANGE)Fetch ibex ...\n$(RESET)"
	$(Q)$(MAKE) fetch VENDOR=lowrisc_ibex

soc_ibex: setup
	@echo "\n$(ORANGE)SoC files building with IBEX...\n$(RESET)"
	$(Q)$(MAKE) xbar HOST=ibex
	$(Q)$(MAKE) soc HOST=ibex
	$(Q)$(FUSESOC) --cores-root=. run --target=sim --tool=verilator --setup --build enea:soc:main
	$(Q)$(MAKE) soc_run

soc_sim:
	@echo "\n$(ORANGE)SoC simulation with FuseSoC ...\n$(RESET)"
	$(Q)$(FUSESOC) --cores-root=. run --target=sim --tool=verilator --setup --build enea:soc:main

soc_run:
	@echo "\n$(ORANGE)GCC compilaiton of hello_world.c ...\n$(RESET)"
	$(Q)$(MAKE) --no-print-dir -C sw
	@echo "\n$(ORANGE)Verilator run ... Press <CTRL>-C\n$(RESET)"
	build/enea_soc_main_0/sim-verilator/Vtop_verilator -t -E sw/build/main.elf

soc_view:
	@echo "\n$(ORANGE)Viewing ...\n$(RESET)"
	$(Q)$(VIEWER) $(VIEWER_FLAGS) sim.fst $(SIMDIR)/soc_$(TOP)_tb.gtkw&

