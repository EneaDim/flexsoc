# CLEAN
clean_doc:
	$(Q)$(RM) $(DOCDIR)/*
clean_log:
	$(Q)$(RM) $(LOGDIR)/*
clean_rtl:
	$(Q)$(RM) $(RTLDIR)/*.v
clean_sim:
	$(Q)$(RM) $(SIMDIR)/*.vvp
	$(Q)$(RM) $(SIMDIR)/*.vcd
	$(Q)$(RM) $(SIMDIR)/verilator
clean_cocotb:
	$(Q)$(RM) $(TBDIR)/cocotb/*.vcd 
	$(Q)$(RM) $(TBDIR)/cocotb/sim_build
	$(Q)$(RM) $(TBDIR)/cocotb/__py*
	$(Q)$(MAKE) --no-print-dir -C $(TBDIR)/cocotb clean
clean_syn:
	$(Q)$(RM) $(SYNDIR)/*
clean_signoff: 
	$(Q)$(RM) $(SIGNOFFDIR)/sdf/*
	$(Q)$(RM) $(SIGNOFFDIR)/*.sdc
clean_pnr:
	$(Q)$(RM) $(ORSDIR)/*
	$(Q)$(RM) $(ORS_LOGS)
	$(Q)$(RM) $(ORS_REPORTS)
	$(Q)$(RM) $(ORS_RESULTS)
	$(Q)$(RM) $(ORS_OBJECTS)
clean_fsm:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean
clean_fsm_all:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean_all
clean_agent:
	$(Q)$(RM) flexsoc_make_agent/logs
	$(Q)$(RM) flexsoc_make_agent/runs
	$(Q)$(RM) fsm_agent/src/__py*
	$(Q)$(RM) fsm_agent/data/inbox/out*
clean_fsoc:
	$(Q)$(RM) build
clean_soc:
	@echo "\n$(ORANGE)Cleaning SoC ...\n$(RESET)"
	$(Q)$(RM) build trace_core_00000000.log uart0.log  sim.fst*  sw/*.elf sw/*.o sw/*.csv \
		     tb/top_verilator.* soc.core xbar_main.hjson $(TOPDIR)
clean_sw:
	$(Q)$(MAKE) --no-print-dir -C sw clean
clean_vendor:
	$(Q)$(RM) vendor/lowrisc_ip
	$(Q)$(RM) vendor/lowrisc_ibex
	$(Q)$(RM) vendor/lowrisc_ip.lock.hjson
	$(Q)$(RM) vendor/lowrisc_ibex.lock.hjson
clean_subdir:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen clean
	$(Q)$(MAKE) --no-print-dir -C fsm_gen setup
clean: clean_log clean_rtl clean_sim clean_syn clean_signoff clean_pnr clean_subdir clean_fsoc clean_soc clean_sw clean_fsm
	$(Q)$(FIND) . -type f \( -name '*~' -o -name '*.swp' \) -exec $(RM) -f {} + > /dev/null 2>&1
	$(Q)$(FIND) . -type d -name '__pycache__' -exec $(RM) {} + > /dev/null 2>&1
	$(Q)$(CLEAR)
clean_all: clean_fsm_all clean_vendor clean_agent clean 
	$(Q)$(RM) *.core
	$(Q)$(RM) $(LOGDIR) $(RTLDIR) $(TBDIR) $(SIMDIR) $(SYNDIR) $(SIGNOFFDIR) $(ORSDIR) \
	$(MODELDIR) $(DATADIR) $(DOCDIR) $(LINTDIR) $(DRIVERDIR) $(PYDIR) $(FSMDIR) > /dev/null 2>&1
