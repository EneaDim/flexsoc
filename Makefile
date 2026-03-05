# Root wrapper Makefile (keeps legacy workflow)
# Delegates to flow/Makefile

.PHONY: help lint sim syn synth sta pnr clean doctor

help:
	@$(MAKE) -C flow help

lint:
	@$(MAKE) -C flow lint

sim:
	@$(MAKE) -C flow sim

# some repos use "syn" as target name
syn:
	@$(MAKE) -C flow syn

synth:
	@$(MAKE) -C flow syn

sta:
	@$(MAKE) -C flow sta

pnr:
	@$(MAKE) -C flow pnr

clean: clean-pyc
	@$(MAKE) -C flow clean

clean-pyc:
	@find . -type d -name "__pycache__" -prune -exec rm -rf {} +
	@find . -type f -name "*.pyc" -delete
	@find . -type f -name "*.pyo" -delete
	@rm -rf .pytest_cache .ruff_cache src/*.egg-info

doctor:
	@echo "Use: flexsoc doctor"
