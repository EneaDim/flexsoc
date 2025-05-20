create_clock -name clk -period 10 {clk_i}
set_input_delay  3 -clock clk {rst_ni}
set_input_delay  3 -clock clk {enable_i}
set_input_delay  3 -clock clk {reverse_i}
set_input_delay  3 -clock clk {step_i}
set_input_delay  3 -clock clk {lvds_i}
set_output_delay 3 -clock clk {pwm_o}
set_output_delay 3 -clock clk {adc_value_o}
set_output_delay 3 -clock clk {adc_valid_o}
