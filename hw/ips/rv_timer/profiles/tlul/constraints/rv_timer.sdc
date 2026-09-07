# FlexSoC canonical design timing intent.
# Authored after first generation: edit this file, then validate it through the flows.
current_design rv_timer

# ============================================================
# 1. CLOCKS
# ============================================================
create_clock -name core -period 10 -waveform {0 5} [get_ports clk_i]

# ============================================================
# 2. GENERATED CLOCKS
# ============================================================
# Add generated clocks here when they are architectural timing intent.
# Example:
# create_generated_clock -name divided_clk -source [get_ports clk_i] -divide_by 2 [get_pins u_div/clk_o]

# ============================================================
# 3. CLOCK QUALITY / ENVIRONMENT
# ============================================================
set_clock_latency -source 0 [get_clocks core]
set_clock_uncertainty -setup 0 [get_clocks core]
set_clock_uncertainty -hold 0 [get_clocks core]
set_clock_transition 0 [get_clocks core]

# ============================================================
# 4. CLOCK RELATIONSHIPS
# ============================================================
# Clocks not declared asynchronous are treated as timing-related.

# ============================================================
# 5. INPUT TIMING
# ============================================================
set non_clock_inputs [all_inputs -no_clocks]
set_input_delay -max 2 -clock core $non_clock_inputs
set_input_delay -min 0.0 -clock core $non_clock_inputs

# ============================================================
# 6. INPUT DRIVE
# ============================================================
set_drive 0.1 [all_inputs -no_clocks]
# If the external driver is a known library cell, replace set_drive with:
# set_driving_cell -lib_cell <driver_cell> -pin <output_pin> [all_inputs -no_clocks]

# ============================================================
# 7. OUTPUT TIMING
# ============================================================
set_output_delay -max 2 -clock core [all_outputs]
set_output_delay -min 0.0 -clock core [all_outputs]

# ============================================================
# 8. OUTPUT LOAD
# ============================================================
set_load 0.01 [all_outputs]

# ============================================================
# 9. TIMING EXCEPTIONS
# ============================================================
# False paths and multicycle paths are architectural intent and are never inferred.
# Example false path:
# set_false_path -from <startpoints> -to <endpoints>
# Example multicycle path pair:
# set_multicycle_path 2 -setup -from <startpoints> -to <endpoints>
# set_multicycle_path 1 -hold  -from <startpoints> -to <endpoints>

# ============================================================
# 10. OPTIONAL DESIGN-RULE CONSTRAINTS
# ============================================================
# Enable only when these limits are part of the intended interface/technology contract.
# set_max_transition <value> [current_design]
# set_max_fanout <value> [current_design]
# set_max_capacitance <value> [all_outputs]
