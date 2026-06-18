# flow/Makefile
#
# Thin wrapper around the packaged FlexSoC flow Makefile.
# Keep this file small so Make, CLI, and API entrypoints stay aligned.

# Repo root = parent of this directory
REPO_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))..)

# Include the real flow Makefile from src
include $(REPO_ROOT)/src/flexsoc/flow/Makefile
