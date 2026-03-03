# Thin Makefile: includes all targets from mk/*.mk
.DEFAULT_GOAL := help

include config.mk

# Silence make directory enter/leave spam
MAKEFLAGS += --no-print-directory


include mk/help.mk
include mk/setup.mk
include mk/ipgen.mk
include mk/lint.mk
include mk/sim.mk
include mk/syn.mk
include mk/signoff.mk
include mk/pnr.mk
include mk/tb.mk
include mk/fsm.mk
include mk/fusesoc.mk
include mk/xbar_soc.mk
include mk/tutorials.mk
include mk/save_load.mk
include mk/deps.mk
include mk/clean.mk
