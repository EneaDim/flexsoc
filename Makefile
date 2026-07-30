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

.PHONY: help install sync dev lint fix check clean clean-py clean-build clean-all venv

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nflexsoc ✨\n"} \
		/^##@/ {printf "\n%s\n", substr($$0, 5); next} \
		/^[A-Za-z0-9_.%-]+:.*##/ {gsub(/^ +/, "", $$2); printf "  %-16s %s\n", $$1, $$2} \
		END {printf "\n"}' $(lastword $(MAKEFILE_LIST))
	@printf '%s\n' \
		'Common workflows' \
		'  make sync                              Install/update the local environment' \
		'  make check                             Run Ruff + default E2E regression' \
		'  make test                              Run E2E + Verilator/Slang lint + Slang AST, no signoff' \
		'  make test SIGNOFF=1                    Include synthesis/signoff stages' \
		'  make test E2E_ROOT=~/flexsoc-e2e       Choose where E2E workspaces are created' \
		'  make test SIGNOFF=1 E2E_ROOT=~/fx-e2e  Combine signoff and custom workspace root' \
		'  make test-live                         Stream fx subprocess output live' \
		'  make test-api                          Run fast Python/API tests only' \
		'  uv run fx --help                       Show hardware-flow targets' \
		''

##@ Setup
install: sync ## Sync the local environment

sync: ## Install the editable package and every Python dependency
	$(UV) sync

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

check: lint test ## Run Ruff + default E2E regression

##@ Tests
# E2E is the default test surface. Signoff is opt-in so the normal developer
# loop stays fast, while the workspace root can be moved outside /tmp when a
# run should be inspected or retained on a larger filesystem.
.PHONY: test test-live test-api

FLEXSOC_E2E_FX ?= $(UV) run --no-sync fx
FLEXSOC_E2E_LIVE ?= 0
E2E_ROOT ?= /tmp
SIGNOFF ?= 0
E2E_SIGNOFF_ARG := $(if $(filter 1 true yes on,$(SIGNOFF)),,--no-signoff)

test: ## Run E2E incl. Verilator/Slang lint + Slang AST (SIGNOFF=0, E2E_ROOT=/tmp)
	FLEXSOC_RUN_E2E=1 FLEXSOC_E2E_LIVE=$(FLEXSOC_E2E_LIVE) FLEXSOC_E2E_FX="$(FLEXSOC_E2E_FX)" $(PYTEST) -s -m e2e tests/test_e2e_fx.py $(E2E_SIGNOFF_ARG) --e2e-root "$(E2E_ROOT)"

test-live: ## Run the E2E regression with live fx output
	$(MAKE) test FLEXSOC_E2E_LIVE=1 SIGNOFF=$(SIGNOFF) E2E_ROOT="$(E2E_ROOT)"

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
