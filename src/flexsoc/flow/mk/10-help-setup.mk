# -----------------------------------------------------------------------------
# Help
# -----------------------------------------------------------------------------
.PHONY: help help_ip help_soc help_doc help_fsm

help:
	@echo "$(ORANGE)"
	@echo "FlexSoC help is now CLI-first."
	@echo ""
	@echo "Recommended commands:"
	@echo "  python -m flexsoc.cli"
	@echo "  python -m flexsoc.cli help overview"
	@echo "  python -m flexsoc.cli help topics"
	@echo "  python -m flexsoc.cli actions"
	@echo "  python -m flexsoc.cli make --list"
	@echo "$(RESET)"

help_ip:
	@echo "$(ORANGE)flexsoc IP flow help moved to the CLI.$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.cli ip

help_soc:
	@echo "$(ORANGE)flexsoc SoC/help topics moved to the CLI.$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.cli help topics

help_doc:
	@echo "$(ORANGE)flexsoc documentation/help overview moved to the CLI.$(RESET)"
	$(Q)$(PYTHON) -m flexsoc.cli help overview

help_fsm:
	$(Q)$(MAKE) --no-print-dir -C $(FSMGEN_DIR) help

# -----------------------------------------------------------------------------
# Setup
# -----------------------------------------------------------------------------
.PHONY: setup setup_tb setup_cocotb setup_model setup_sdc setup_syn setup_signoff setup_pnr

setup:
	@echo "\n$(ORANGE)Setup Folder Structure...\n$(RESET)"
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	$(Q)$(MKDIR) -p \
		$(LOGDIR) \
		$(RTLDIR) \
		$(TBDIR) \
		$(SIMDIR) \
		$(SYNDIR) \
		$(SIGNOFFDIR) \
		$(SIGNOFFDIR)/sdf \
		$(MODELDIR) \
		$(DOCDIR) \
		$(DATADIR) \
		$(DRIVERDIR) \
		$(LINTDIR) \
		$(PYDIR) \
		$(FSMDIR) \
		$(ORSDIR)

setup_tb: setup
	@echo "\n$(ORANGE)Setup SystemVerilog Testbench Template...\n$(RESET)"
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR) $(SIMDIR) $(SYNDIR) $(RTLDIR)
	@if [ "$(TOP)" = "soc" ]; then \
		dev_args="$$( $(PYTHON) -m flexsoc.tools.soc_cfg \
			--workspace $(WORKSPACE) \
			--run-top $(RUN_TOP) \
			--run-id $(RUN_ID) \
			--mode $(SOC_CFG_MODE) \
			--default-host $(HOST) \
			--format args | sed 's/^--host [^ ]* //' )"; \
		$(PYTHON) -m flexsoc.tools.setup_tb $(OVERWRITE) \
			-top $(TOP) \
			-rtldir $(RTLDIR) \
			$$dev_args \
			-simdir $(SIMDIR) \
			-syndir $(SYNDIR) \
			-prim $(PRIM) \
			-clk $(CLK_PERIOD) \
			-comp $(COMPILER) \
			-itf $(REG_ITF) \
			-vsv $(VSV) \
			-o $(TBDIR); \
	else \
		$(PYTHON) -m flexsoc.tools.setup_tb $(OVERWRITE) \
			-top $(TOP) \
			-rtldir $(RTLDIR) \
			-simdir $(SIMDIR) \
			-syndir $(SYNDIR) \
			-prim $(PRIM) \
			-clk $(CLK_PERIOD) \
			-comp $(COMPILER) \
			-itf $(REG_ITF) \
			-vsv $(VSV) \
			-o $(TBDIR); \
	fi

setup_cocotb: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(TBDIR)/cocotb
	$(Q)$(PYTHON) -m flexsoc.tools.setup_cocotb \
		--top $(TOP) --itf $(REG_ITF) \
		--rtl-dir $(RTLDIR) --output $(TBDIR)/cocotb \
		--clk clk_i --rst rst_ni --rst-active low --period-ns 10 \
		--sim $(COMPILER)

setup_model: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(MODELDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_model -top $(TOP) -o $(MODELDIR)

setup_sdc: setup
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_sdc $(TOP) $(CLK_PERIOD) -o $(ORSDIR)/$(TOP).sdc

setup_syn: setup_sdc
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SYNDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_syn \
		-top $(TOP) -topdir $(RTLDIR) -sdcdir $(ORSDIR) \
		--filelist $(RTLDIR)/rtl_list.f \
		-liberty $(LIB_SYN) -clk $(CLK_PERIOD) \
		-target $(TARGET_SYN) -opt $(TARGET_OPT) \
		-o $(SYNDIR)

setup_signoff: setup_sdc syn
	$(call _require_var,TOP)
	$(Q)$(MKDIR) -p $(SIGNOFFDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_signoff \
		-top $(TOP) -rtldir $(RTLDIR) \
		-sdcdir $(ORSDIR) -syndir $(SYNDIR) -simdir $(SIMDIR) \
		-libs $(LIBS) -clk $(CLK_PERIOD) -activity $(ACTIVITY) \
		-o $(SIGNOFFDIR)

setup_pnr:
	$(Q)$(MKDIR) -p $(ORSDIR)
	$(Q)$(PYTHON) -m flexsoc.tools.setup_pnr $(TOP) --syn_strategy $(TARGET_OPT) --clk_period $(CLK_PERIOD) \
		--platform $(ORS_TECH) --filelist $(RTLDIR)/rtl_list.f --outdir $(ORSDIR)
