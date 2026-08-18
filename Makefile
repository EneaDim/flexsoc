# Root development Makefile
#
# Repository-level developer tasks only. Hardware flow execution stays in
# src/flexsoc/backend/Makefile and is normally reached through the fx command.

.DEFAULT_GOAL := help

UV ?= uv
PYTHON ?= python3
RUFF ?= ruff
PYTEST ?= $(UV) run --no-sync pytest
LINT_PATHS ?= src/flexsoc/api.py src/flexsoc/backend tests
MAKEFLAGS += --no-print-directory

.PHONY: help install lock sync dev doctor lint fix check clean clean-py clean-build clean-all venv

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nflexsoc ✨\n"} \
		/^##@/ {printf "\n%s\n", substr($$0, 5); next} \
		/^[A-Za-z0-9_.%-]+:.*##/ {gsub(/^ +/, "", $$2); printf "  %-16s %s\n", $$1, $$2} \
		END {printf "\n"}' $(lastword $(MAKEFILE_LIST))
	@printf '%s\n' \
		'Common workflows' \
		'  make lock                              Resolve and write uv.lock' \
		'  make sync                              Install exactly the locked Python environment' \
		'  make doctor                            Check Python lock and local EDA tools' \
		'  make check                             Run Ruff + full E2E closure' \
		'  make test                              Run full E2E on sky130 + ihp-sg13g2' \
		'  make test-smoke                        Run E2E without formal/synthesis/signoff' \
		'  make test E2E_ROOT=~/flexsoc-e2e       Choose where E2E workspaces are created' \
		'  make test E2E_ORS=~/OpenROAD-flow-scripts/flow  Select the ORFS flow root' \
		'  make test SIGNOFF=0 E2E_ROOT=~/fx-e2e  Explicitly skip signoff for a custom run' \
		'  make test-api                          Run fast Python/API tests only' \
		'  uv run fx --help                       Show hardware-flow targets' \
		''

##@ Setup
install: sync ## Sync the local environment

lock: ## Resolve Python dependencies and write uv.lock
	$(UV) lock

sync: ## Install exactly the Python environment recorded in uv.lock
	@test -f uv.lock || { echo "ERROR: uv.lock missing. Run: make lock"; exit 2; }
	$(UV) sync --locked

doctor: ## Check Python lock and local EDA tools
	PYTHONPATH=src $(PYTHON) -m flexsoc.doctor

venv: sync ## Create or update the local uv virtualenv

dev: sync ## Sync and print fx help
	$(UV) run --no-sync fx --help

##@ Quality
lint: ## Run Ruff checks
	@echo ">> Running Ruff"
	@$(UV) run --no-sync $(RUFF) check $(LINT_PATHS)

fix: ## Run Ruff with --fix
	@echo ">> Running Ruff --fix"
	@$(UV) run --no-sync $(RUFF) check --fix $(LINT_PATHS)

check: lint test ## Run Ruff + full E2E closure

##@ Tests
# E2E is the default test surface. Shared RTL/DV/formal runs once, then every
# test qualifies SKY130 and IHP. SIGNOFF=0 is an explicit smoke/debug opt-out.
# The workspace
# root can be moved outside /tmp when a run should be inspected or retained.
.PHONY: test test-smoke test-api

E2E_ROOT ?= /tmp
E2E_ORS ?=
SIGNOFF ?= 1
E2E_SIGNOFF_ARG := $(if $(filter 1 true yes on,$(SIGNOFF)),,--no-signoff)
E2E_ORS_ARG := $(if $(strip $(E2E_ORS)),--e2e-ors "$(E2E_ORS)",)

test: ## Run full E2E closure on SKY130 and IHP (SIGNOFF=1, E2E_ROOT=/tmp)
	$(PYTEST) -s -m e2e tests/test_e2e_fx.py $(E2E_SIGNOFF_ARG) $(E2E_ORS_ARG) --e2e-root "$(E2E_ROOT)"

test-smoke: ## Run E2E without formal/synthesis/signoff
	$(MAKE) test SIGNOFF=0 E2E_ROOT="$(E2E_ROOT)"

test-api: ## Run fast Python/API tests only
	$(PYTEST) -s tests/test_api.py

##@ Cleanup
clean: clean-py clean-build ## Remove Python caches and build artifacts
	@echo ">> Clean complete"

clean-py: ## Remove Python bytecode and tool caches
	@echo ">> Removing Python caches"
	@find . -type d -name "__pycache__" -prune -exec rm -rf {} +
	@find . -type f -name "*.pyc" -delete
	@find . -type f -name "*.pyo" -delete
	@find . -type f -name "*.pyd" -delete
	@rm -rf .pytest_cache .ruff_cache .mypy_cache

clean-build: ## Remove local package/build outputs
	@echo ">> Removing local build artifacts"
	@find . -type d -name "*.egg-info" -prune -exec rm -rf {} +
	@rm -rf build dist .coverage htmlcov
	@rm -rf flow/build

clean-all: clean ## Remove workspace artifacts too
	@echo ">> Removing workspace artifacts"
	@rm -rf workspace
