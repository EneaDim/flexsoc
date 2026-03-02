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

clean:
	@$(MAKE) -C flow clean

doctor:
	@echo "Use: flexsoc doctor"
