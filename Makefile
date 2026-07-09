# Root development Makefile
#
# Repository-level developer tasks only. Hardware flow execution stays in
# src/flexsoc/backend/Makefile and is normally reached through the CLI.

.DEFAULT_GOAL := help

UV ?= uv
PYTHON ?= python3
RUFF ?= ruff
PYTEST ?= pytest
LINT_PATHS ?= src/flexsoc/api.py src/flexsoc/backend tests
MAKEFLAGS += --no-print-directory

.PHONY: help install install-flow install-cocotb sync dev lint fix test check clean clean-py clean-build clean-all venv

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nflexsoc ✨\n"} \
		/^##@/ {printf "\n%s\n", substr($$0, 5); next} \
		/^[A-Za-z0-9_.%-]+:.*##/ {gsub(/^ +/, "", $$2); printf "  %-14s %s\n", $$1, $$2} \
		END {printf "\n"}' $(lastword $(MAKEFILE_LIST))

##@ Setup
install: sync ## Install dependencies

install-flow: venv ## Install dev plus full optional flow dependencies
	$(UV) pip install -e ".[dev,flow]"

install-cocotb: venv ## Install only the cocotb runner for cocotb experiments
	$(UV) pip install cocotb==2.0.0

sync: venv ## Install the editable package with dev tools
	$(UV) pip install -e ".[dev]"

venv: ## Create or reuse the local uv virtualenv
	$(UV) venv --allow-existing .venv

dev: install ## Install and print CLI help
	$(UV) run --no-sync python -m flexsoc help

##@ Quality
lint: ## Run Ruff checks
	@echo ">> Running Ruff"
	@$(UV) run --no-sync $(RUFF) check $(LINT_PATHS)

fix: ## Run Ruff with --fix
	@echo ">> Running Ruff --fix"
	@$(UV) run --no-sync $(RUFF) check --fix $(LINT_PATHS)

test: ## Run pytest
	$(UV) run --no-sync $(PYTEST) -q

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
