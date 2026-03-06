# Root development Makefile
#
# This Makefile is for repository-level developer tasks:
# - help / welcome
# - lint / fix
# - tests
# - clean Python caches and local build artifacts
#
# Flow execution stays available through explicit flow-* targets.

.DEFAULT_GOAL := help

.PHONY: help lint fix test check clean clean-py clean-build clean-all

PYTHON ?= python3
RUFF ?= ruff
PYTEST ?= pytest
MAKEFLAGS += --no-print-directory

help:
	@echo
	@echo "flexsoc ✨"
	@echo
	@echo "Repository developer commands:"
	@echo "  make help        Show this message"
	@echo "  make lint        Run Ruff checks"
	@echo "  make fix         Run Ruff with --fix"
	@echo "  make test        Run pytest"
	@echo "  make check       Run lint + test"
	@echo "  make clean       Remove Python caches and local build artifacts"
	@echo
	@echo "Flow compatibility commands:"
	@echo "  make flow-help   Show flow targets"
	@echo "  make flow-lint   Run flow lint target"
	@echo "  make flow-sim    Run flow sim target"
	@echo "  make flow-syn    Run flow syn target"
	@echo "  make flow-sta    Run flow sta target"
	@echo "  make flow-pnr    Run flow pnr target"
	@echo

lint:
	@echo ">> Running Ruff"
	@$(RUFF) check src/flexsoc/

fix:
	@echo ">> Running Ruff --fix"
	@$(RUFF) check --fix src/flexsoc/

test:
	@echo ">> Running pytest"
	@$(PYTEST) -q

check: lint test

clean: clean-py clean-build
	@echo ">> Clean complete"

clean-py:
	@echo ">> Removing Python caches"
	@find . -type d -name "__pycache__" -prune -exec rm -rf {} +
	@find . -type f -name "*.pyc" -delete
	@find . -type f -name "*.pyo" -delete
	@find . -type f -name "*.pyd" -delete
	@rm -rf .pytest_cache .ruff_cache .mypy_cache

clean-build:
	@echo ">> Removing local build artifacts"
	@find . -type d -name "*.egg-info" -prune -exec rm -rf {} +
	@rm -rf build dist .coverage htmlcov

clean-all: clean
	@echo ">> Removing workspace artifacts"
	@rm -rf workspace

