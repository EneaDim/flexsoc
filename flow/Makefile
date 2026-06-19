# flow/Makefile
#
# Thin wrapper around the packaged FlexSoC backend Makefile.
# Keep this file small so direct Make, CLI, and API entrypoints stay aligned.

# Repo root = parent of this directory
REPO_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))..)

# Include the canonical backend Makefile from src
include $(REPO_ROOT)/src/flexsoc/backend/Makefile
