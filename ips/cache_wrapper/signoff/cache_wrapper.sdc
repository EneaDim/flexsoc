create_clock -name clk -period 10 {clk_i}
set_input_delay  3 -clock clk {rst_ni}
set_input_delay  3 -clock clk {cpu_valid_i}
set_input_delay  3 -clock clk {cpu_we_i}
set_input_delay  3 -clock clk {cpu_adr_i}
set_input_delay  3 -clock clk {cpu_wdata_i}
set_input_delay  3 -clock clk {mem_ready_i}
set_input_delay  3 -clock clk {mem_rdata_i}
set_output_delay 3 -clock clk {cpu_ready_o}
set_output_delay 3 -clock clk {cpu_rdata_o}
set_output_delay 3 -clock clk {cpu_resp_valid_o}
set_output_delay 3 -clock clk {mem_valid_o}
set_output_delay 3 -clock clk {mem_we_o}
set_output_delay 3 -clock clk {mem_adr_o}
set_output_delay 3 -clock clk {mem_wdata_o}
