###########
# LINTING #
###########

.PHONY: lint lint_v lint_sv
lint: $(if $(filter v,$(Q)$(VSV)),lint_v,lint_sv)

lint_v: sv2v 
	@echo "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) $(RTLDIR)/$(TOP).v > $(LOGDIR)/$(TOP)_lint.log 2>&1 
	
lint_sv: flist
	@echo "\n$(ORANGE)Linting...\n$(RESET)"
	$(Q)$(LINTER) $(LINT_FLAGS) -f $(RTLDIR)/rtl_list.f --top-module $(TOP) $(RTLDIR)/$(TOP).sv \
	> $(LOGDIR)/$(TOP)_lint.log 2>&1 
	

