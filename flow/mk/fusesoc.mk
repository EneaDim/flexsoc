# Defaults (can be overridden by caller)
PRJ    ?= flexsoc
TARGET ?= default

.PHONY: fsoc_init fsoc

# FuseSoC setup:
# Generates:
#   $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/fusesoc/$(TOP).core
fsoc_init:
	@echo "\n$(ORANGE)FuseSOC setup...\n$(RESET)"
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	run_dir="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)"; \
	rtl_dir="$$run_dir/rtl"; \
	lint_dir="$$run_dir/lint"; \
	out_abs="$$run_dir"; \
	mkdir -p "$$out_abs" "$$lint_dir"; \
	out_rel="$$(python3 -c 'import os,sys; print(os.path.relpath(sys.argv[1], sys.argv[2]))' "$$out_abs" "$$(pwd)")"; \
	$(PYTHON) scripts/setup_fsoc.py \
		-prj "$(PRJ)" \
		-top "$(TOP)" \
		-rtldir "$$rtl_dir" \
		-lintdir "$$lint_dir" \
		-o "$$out_rel"; \
	test -f "$$out_abs/$(TOP).core" || { \
		echo "ERROR: expected core not generated: $$out_abs/$(TOP).core"; \
		exit 2; \
	}; \
	echo "Generated: $$out_abs/$(TOP).core"

# FuseSoC run (workspace-based cores-root)
fsoc:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	cores_root="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)/fusesoc"; \
	$(Q)$(FUSESOC) --cores-root="$$cores_root" run --target "$(TARGET)" "$(PRJ):ip:$(TOP)"
