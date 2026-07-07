UV ?= uv
# Root development Makefile
#
# Repository-level developer tasks only:
# - help / install
# - lint / fix
# - tests
# - cleanup of Python caches and local/generated artifacts
#
# Flow execution remains available through explicit flow-* usage or the CLI.

.DEFAULT_GOAL := help

.PHONY: help install lint fix test check clean clean-py clean-build clean-all venv install dev

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
	@echo "  make install     Install dependencies"
	@echo "  make lint        Run Ruff checks"
	@echo "  make fix         Run Ruff with --fix"
	@echo "  make test        Run pytest"
	@echo "  make check       Run lint + test"
	@echo "  make clean       Remove Python caches and local/generated build artifacts"
	@echo

install: venv$(UV) sync
lint:
	@echo ">> Running Ruff"
	@$(RUFF) check src/flexsoc/

fix:
	@echo ">> Running Ruff --fix"
	@$(RUFF) check --fix src/flexsoc/

test:
	$(UV) run pytest -q
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
	@rm -rf flow/build

clean-all: clean
	@echo ">> Removing workspace artifacts"
	@rm -rf workspace

venv:
	$(UV) venv .venv

dev: install
	$(UV) run python -m flexsoc help
