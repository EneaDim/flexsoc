create_clock -name clk -period 10 {clk_i}
set_input_delay  3 -clock clk {rst_ni}
set_input_delay  3 -clock clk {tl_i}
set_input_delay  3 -clock clk {spi_sdio_i}
set_output_delay 3 -clock clk {tl_o}
set_output_delay 3 -clock clk {spi_cs_o}
set_output_delay 3 -clock clk {spi_sclk_o}
set_output_delay 3 -clock clk {spi_sdioz_o}
set_output_delay 3 -clock clk {spi_sdio_o}
