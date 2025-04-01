# MAIN PARAMETERS
FSM   ?=fsm_example
F_CLK ?=32

# Shell functions
ECHO            :=echo

# COLORS
ORANGE          :=\033[38;5;214m
RESET           :=\033[0m

# BASIC FLOW
flow: setup gen
setup:
	mkdir -p inputs outputs  
# HELP
help: clean
	python scripts/help.py
# RUN MAIN
gen: clean
	@$(ECHO) "\n$(ORANGE)Generating .sv and .gv file of FSM...\n$(RESET)"
	python scripts/Main.py -fsm_name $(FSM) -f_clk $(F_CLK)
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
	rm -rf outputs/* plot
