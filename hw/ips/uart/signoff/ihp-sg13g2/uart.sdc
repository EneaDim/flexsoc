current_design uart

create_clock -name core -period 10 [get_ports clk_i]


set non_clock_inputs [all_inputs -no_clocks]
set_input_delay [expr 10 * 0.2] -clock core $non_clock_inputs
set_output_delay [expr 10 * 0.2] -clock core [all_outputs]
