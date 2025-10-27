// Auto-generated TL-UL wrapper for soc
`timescale 1ns/1ps
module soc_tb;
  // Clock & Reset sono pilotati da cocotb (via porte)
  wire  clk_i;
  wire  rst_ni;
  wire cio_rx_i;
  wire [3:0] cio_gpio_i;
  wire spi_sdio_i;
  wire cio_tx_o;
  wire cio_tx_en_o;
  wire [1:0] cio_pwm_o;
  wire [1:0] cio_pwm_en_o;
  wire [3:0] cio_gpio_o;
  wire [3:0] cio_gpio_en_o;
  wire spi_cs_o;
  wire spi_sclk_o;
  wire spi_sdioz_o;
  wire spi_sdio_o;


  initial begin
    $dumpfile("soc_tb.vcd");
    $dumpvars(0, soc_tb);
    #1;
  end

`ifdef GL_TEST
  wire VPWR = 1'b1;
  wire VGND = 1'b0;
`endif

  // -------- DUT con porte pass-through --------
  soc u_dut (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .cio_rx_i(cio_rx_i),
    .cio_gpio_i(cio_gpio_i),
    .spi_sdio_i(spi_sdio_i),
    .cio_tx_o(cio_tx_o),
    .cio_tx_en_o(cio_tx_en_o),
    .cio_pwm_o(cio_pwm_o),
    .cio_pwm_en_o(cio_pwm_en_o),
    .cio_gpio_o(cio_gpio_o),
    .cio_gpio_en_o(cio_gpio_en_o),
    .spi_cs_o(spi_cs_o),
    .spi_sclk_o(spi_sclk_o),
    .spi_sdioz_o(spi_sdioz_o),
    .spi_sdio_o(spi_sdio_o)
  );
endmodule
