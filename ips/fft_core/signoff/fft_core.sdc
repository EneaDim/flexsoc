create_clock -name clk -period 10 {clk_i}
set_input_delay  3 -clock clk {rst_ni}
set_input_delay  3 -clock clk {read_ram_i}
set_input_delay  3 -clock clk {adc_data_i}
set_input_delay  3 -clock clk {adc_valid_i}
set_input_delay  3 -clock clk {fft_out_ready_i}
set_output_delay 3 -clock clk {adc_ready_o}
set_output_delay 3 -clock clk {fft_out_valid_o}
set_output_delay 3 -clock clk {fft_out_data_o}
