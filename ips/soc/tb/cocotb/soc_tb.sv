// Auto-generated TL-UL wrapper for soc
`timescale 1ns/1ps
module soc_tb;
  // Clock & Reset sono pilotati da cocotb (via porte)
  logic  clk_i;
  logic  rst_ni;
  logic cio_rx_i;
  logic [3:0] cio_gpio_i;
  logic cio_tx_o;
  logic cio_tx_en_o;
  logic [1:0] cio_pwm_o;
  logic [1:0] cio_pwm_en_o;
  logic [3:0] cio_gpio_o;
  logic [3:0] cio_gpio_en_o;

  initial begin
    $dumpfile("soc_tb.vcd");
    $dumpvars(0, soc_tb);
    #1;
  end

  // -------- DUT con porte pass-through --------
  soc u_dut (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .cio_rx_i(cio_rx_i),
    .cio_gpio_i(cio_gpio_i),
    .cio_tx_o(cio_tx_o),
    .cio_tx_en_o(cio_tx_en_o),
    .cio_pwm_o(cio_pwm_o),
    .cio_pwm_en_o(cio_pwm_en_o),
    .cio_gpio_o(cio_gpio_o),
    .cio_gpio_en_o(cio_gpio_en_o)
  );
endmodule
