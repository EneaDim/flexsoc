# SW
PYTHON ?= python3

# MAIN PARAMETERS
FSM       ?= fsm_example
F_CLK     ?= 32
INPUT_DIR ?= inputs
OUTPUT_DIR ?= outputs

# Shell functions
ECHO   := echo
MKDIR  := mkdir -p
RM     := rm -rf

# COLORS
ORANGE := \033[38;5;214m
RESET  := \033[0m

# HELP
help: clean
	@$(PYTHON) scripts/help.py

# SETUP
setup:
	@$(MKDIR) "$(INPUT_DIR)" "$(OUTPUT_DIR)"

# GENERATE
gen: clean_py setup
	@$(ECHO) "\n$(ORANGE)Generating .sv, .gv and TB artifacts of FSM...\n$(RESET)"
	@$(PYTHON) scripts/Main.py \
		--fsm_name "$(FSM)" \
		--f_clk "$(F_CLK)" \
		--input-dir "$(INPUT_DIR)" \
		--output-dir "$(OUTPUT_DIR)"

# PLOT FSM
.PHONY: plot
plot:
	@$(ECHO) "\n$(ORANGE)Plotting .gv file of FSM...\n$(RESET)"
	@xdot "$(OUTPUT_DIR)/$(FSM).gv" 2>/dev/null &

# CLEAN PYTHON SCRIPTS FOLDER
clean_py:
	@$(RM) scripts/__*
	@$(RM) *~

# CLEAN OUTPUT DIRECTORY
clean: clean_py
	@$(RM) "$(OUTPUT_DIR)" plot

# CLEAN ALL
clean_all: clean
	@$(RM) "$(INPUT_DIR)"/*
