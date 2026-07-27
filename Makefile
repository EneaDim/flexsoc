# Root development Makefile
#
# Repository-level developer tasks only. Hardware flow execution stays in
# src/flexsoc/backend/Makefile and is normally reached through the fx command.

.DEFAULT_GOAL := help

UV ?= uv
PYTHON ?= python3
RUFF ?= ruff
PYTEST ?= pytest
LINT_PATHS ?= src/flexsoc/api.py src/flexsoc/backend tests
MAKEFLAGS += --no-print-directory

.PHONY: help install sync dev lint fix check clean clean-py clean-build clean-all venv

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nflexsoc ✨\n"} \
		/^##@/ {printf "\n%s\n", substr($$0, 5); next} \
		/^[A-Za-z0-9_.%-]+:.*##/ {gsub(/^ +/, "", $$2); printf "  %-14s %s\n", $$1, $$2} \
		END {printf "\n"}' $(lastword $(MAKEFILE_LIST))

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

check: lint test ## Run lint and tests

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

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
# `make test` is the one-command local regression. It keeps pytest output visible
# so the E2E debug prints look like running the `fx` flow by hand.
.PHONY: test test-api test-e2e test-e2e-live

PYTEST ?= uv run --no-sync pytest
FLEXSOC_E2E_FX ?= uv run --no-sync fx
FLEXSOC_E2E_LIVE ?= 0

test: test-api test-e2e

test-api:
	$(PYTEST) -s tests/test_api.py

test-e2e:
	FLEXSOC_RUN_E2E=1 FLEXSOC_E2E_LIVE=$(FLEXSOC_E2E_LIVE) FLEXSOC_E2E_FX="$(FLEXSOC_E2E_FX)" $(PYTEST) -s -m e2e tests/test_e2e_fx.py

test-e2e-live:
	$(MAKE) test-e2e FLEXSOC_E2E_LIVE=1
