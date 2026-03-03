# Save/Load IP bundles
#
# ip_save copies:
#   $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)  ->  $(IPS_ROOT)/$(TOP)
#
# ip_load restores:
#   $(IPS_ROOT)/$(TOP)  ->  $(WORKSPACE)/runs/$(TOP)/$(RUN_ID)
#
# fsoc_init: FuseSoC-friendly init target (creates run dir skeleton).
#
# Defaults:
#   IPS_ROOT defaults to ../hw/ips relative to flow/

IPS_ROOT ?= $(abspath ../hw/ips)

# Treat any non-empty OVERWRITE as "force overwrite"
ifeq ($(strip $(OVERWRITE)),)
  FLEXSOC_FORCE := 0
else
  FLEXSOC_FORCE := 1
endif

define _require_var
	@if [ -z "$($1)" ]; then \
		echo "ERROR: missing required variable $1"; \
		echo "Hint: pass $1=... or use flexsoc (it sets variables automatically)"; \
		exit 2; \
	fi
endef

.PHONY: ip_save
ip_save:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	src="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)"; \
	dst="$(IPS_ROOT)/$(TOP)"; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source run dir not found: $$src"; \
		exit 2; \
	fi; \
	mkdir -p "$(IPS_ROOT)"; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination already exists: $$dst"; \
		echo "Hint: re-run with --overwrite (sets OVERWRITE)"; \
		exit 2; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "1" ]; then \
		rm -rf "$$dst"; \
	fi; \
	mkdir -p "$$dst"; \
	echo "Saving IP bundle:"; \
	echo "  from: $$src"; \
	echo "  to:   $$dst"; \
	if command -v rsync >/dev/null 2>&1; then \
		rsync -a "$$src"/ "$$dst"/; \
	else \
		cp -a "$$src"/. "$$dst"/; \
	fi

.PHONY: ip_load
ip_load:
	$(call _require_var,WORKSPACE)
	$(call _require_var,TOP)
	$(call _require_var,RUN_ID)
	@set -eu; \
	src="$(IPS_ROOT)/$(TOP)"; \
	dst="$(WORKSPACE)/runs/$(TOP)/$(RUN_ID)"; \
	if [ ! -d "$$src" ]; then \
		echo "ERROR: source IP bundle not found: $$src"; \
		exit 2; \
	fi; \
	mkdir -p "$(WORKSPACE)/runs/$(TOP)"; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "0" ]; then \
		echo "ERROR: destination run dir already exists: $$dst"; \
		echo "Hint: re-run with --overwrite (sets OVERWRITE)"; \
		exit 2; \
	fi; \
	if [ -e "$$dst" ] && [ "$(FLEXSOC_FORCE)" = "1" ]; then \
		rm -rf "$$dst"; \
	fi; \
	mkdir -p "$$dst"; \
	echo "Loading IP bundle:"; \
	echo "  from: $$src"; \
	echo "  to:   $$dst"; \
	if command -v rsync >/dev/null 2>&1; then \
		rsync -a "$$src"/ "$$dst"/; \
	else \
		cp -a "$$src"/. "$$dst"/; \
	fi
