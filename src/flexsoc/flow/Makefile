# flexsoc flow entrypoint
FLOWMK_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
include $(FLOWMK_DIR)/mk/00-common.mk
include $(FLOWMK_DIR)/mk/10-help-setup.mk
include $(FLOWMK_DIR)/mk/20-ip-flow.mk
include $(FLOWMK_DIR)/mk/30-soc-flow.mk
include $(FLOWMK_DIR)/mk/40-fsm-clean.mk
