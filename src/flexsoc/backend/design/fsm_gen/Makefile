PYTHON ?= python3
FSM ?= fsm_example
F_CLK ?= 32
INPUT_DIR ?= inputs
OUTPUT_DIR ?= outputs

.PHONY: help setup gen plot clean clean_all
help:
	@printf "FSM targets: setup gen plot clean clean_all\n"
setup:
	@mkdir -p "$(INPUT_DIR)" "$(OUTPUT_DIR)"
gen: setup
	@PYTHONPATH="$${PYTHONPATH}" $(PYTHON) -c 'from pathlib import Path; from flexsoc.backend.design.fsm_gen import Interface; i=Interface("FlexSoC FSM", inputs_dir=Path("$(INPUT_DIR)"), outputs_dir=Path("$(OUTPUT_DIR)")); i.read_inputs("$(FSM)"); i.write_sv(); i.write_gv(); i.states_walkthrough(); i.write_tb($(F_CLK))'
plot:
	@xdot "$(OUTPUT_DIR)/$(FSM).gv" >/dev/null 2>&1 &
clean:
	@rm -rf "$(OUTPUT_DIR)"
clean_all: clean
	@rm -rf "$(INPUT_DIR)"
