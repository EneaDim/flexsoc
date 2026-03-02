# Include configuration

# HELP
help:
	@echo "$(ORANGE)"
	@echo "Available make commands to start:"
	@echo ""
	@echo "    make help_ip     Show IP-related help"
	@echo "    make help_soc    Show SoC-related help"
	@echo "    make help_doc    Show documentation-related help"
	@echo "    make help_fsm    Show FSM generator help"
	@echo "$(RESET)"

help_ip:
	$(Q)$(PYTHON) scripts/help_ip.py
help_soc:
	$(Q)$(PYTHON) scripts/help_soc.py
help_doc: 
	$(Q)$(PYTHON) scripts/help_doc.py
help_fsm:
	$(Q)$(MAKE) --no-print-dir -C fsm_gen help
