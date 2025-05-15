# SW
PYTHON ?=python3

# MAIN PARAMETERS
FSM    ?=fsm_example
F_CLK  ?=32

# Shell functions
ECHO   :=echo

# COLORS
ORANGE :=\033[38;5;214m
RESET  :=\033[0m

# HELP
help: clean
	$(PYTHON) scripts/help.py

# BASIC FLOW
flow: setup gen

# SETUP
setup:
	mkdir -p inputs outputs  

# GENERATE
gen: clean_py
	@$(ECHO) "\n$(ORANGE)Generating .sv and .gv file of FSM...\n$(RESET)"
	$(PYTHON) scripts/Main.py -fsm_name $(FSM) -f_clk $(F_CLK)

# PLOT FSM
.PHONY: plot
plot:
	@$(ECHO) "\n$(ORANGE)Plotting .gv file of FSM...\n$(RESET)"
	xdot outputs/$(FSM).gv &

# CLEAN PYTHON SCRIPTS FOLDER
clean_py:
	rm -rf scripts/__*
	rm -rf *~
# CLEAN OUTPUT DIRECTORY
clean: clean_py
	rm -rf outputs plot 
# CLEAN ALL
clean_all: clean
	rm -rf inputs/*
