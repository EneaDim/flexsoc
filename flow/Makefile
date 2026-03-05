# flow/Makefile (compat shim)
#
# This directory is kept ONLY for backward compatibility:
# - tests and users call: make -C flow <target>
#
# The real Makefile lives in: src/flexsoc/flow/Makefile

# Repo root = parent of this directory
REPO_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))..)

# Include the real flow Makefile from src
include $(REPO_ROOT)/src/flexsoc/flow/Makefile
