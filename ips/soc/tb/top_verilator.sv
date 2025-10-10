module top_verilator (input logic clk_i, rst_ni);
  logic [3:0] cio_pwm_o;
  logic [3:0] cio_pwm_en_o;
  logic [3:0] cio_gpio_i;
  logic [3:0] cio_gpio_o;
  logic [3:0] cio_gpio_en_o;
  logic spi_cs_o;
  logic spi_sclk_o;
  logic spi_sdioz_o;
  logic spi_sdio_i;
  logic spi_sdio_o;

  // Our SoC
  soc #(
  ) u_soc (
    .clk_i,
    .rst_ni,
    .cio_pwm_o,
    .cio_pwm_en_o,
    .cio_gpio_i,
    .cio_gpio_o,
    .cio_gpio_en_o,
    .spi_cs_o,
    .spi_sclk_o,
    .spi_sdioz_o,
    .spi_sdio_i,
    .spi_sdio_o
);

  // Virtual UART
  uartdpi #(
    .BAUD ( 921_600    ),
    .FREQ ( 50_000_000 )
  ) u_uartdpi (
    .clk_i,
    .rst_ni,
    .active(1'b1       ),
    .tx_o  (cio_rx_i),
    .rx_i  (cio_tx_o)
  );

  export "DPI-C" function mhpmcounter_num;

  function automatic int unsigned mhpmcounter_num();
    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.MHPMCounterNum;
  endfunction

  export "DPI-C" function mhpmcounter_get;

  function automatic longint unsigned mhpmcounter_get(int index);
    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.mhpmcounter[index];
  endfunction

endmodule
