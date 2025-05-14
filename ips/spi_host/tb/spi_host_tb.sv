// Include files 
`include "tb/include_tb.sv"

module spi_host_tb;
  //Parameters
  parameter int CLK_PERIOD = 10; // Clock period in ns
  parameter FifoDepth = 3;
  // Inputs
  reg clk_i;
  reg rst_ni;
  tlul_pkg::tl_h2d_t tl_i;
  reg spi_sdio_i;
  // Outputs
  tlul_pkg::tl_d2h_t tl_o;
  wire spi_cs_o;
  wire spi_sclk_o;
  wire spi_sdioz_o;
  wire spi_sdio_o;

  integer error_count;

  logic [top_pkg::TL_DW-1:0] read_data;

  // Class instance
  tlul_utils tl_utils_inst;
  // Interface
  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));

  // Device Under Test Instance
  spi_host
  `ifndef SYN
    #(
      .FifoDepth(FifoDepth)
    ) 
  `endif
  u_spi_host (
    .clk_i,
    .rst_ni,
    .tl_i(tl_if.h2d),
    .spi_sdio_i,
    .tl_o(tl_if.d2h),
    .spi_cs_o,
    .spi_sclk_o,
    .spi_sdioz_o,
    .spi_sdio_o
  );

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_spi_host.vcd");
    `else
      $dumpfile("sim/dump_spi_host_syn.vcd");
    `endif
    $dumpvars(0, spi_host_tb);
  end

  // Error count
  initial begin
    error_count = 0;
  end

  initial begin
    // Init inputs
    rst_ni = 0;
    tl_i = 0;
    spi_sdio_i = 0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD);
    // Start main test
    $display("\nRunning...\n");
    // Instantiate utility
    tl_utils_inst = new(tl_if); 
    // Wait
    #(CLK_PERIOD*100);
    // Write
    tl_utils_inst.tlul_write(32'h0, 32'h1, 4'h0);
    tl_utils_inst.tlul_write(32'h4, 32'hF, 4'h1);
    #(CLK_PERIOD*100);
    // Read
    tl_utils_inst.tlul_read(32'h8, read_data, 4'h2);
    $display("Read data: %h", read_data);
    #(CLK_PERIOD*100);
    // INSERT YOUR CODE


    // Final Check
    if (error_count == 0) begin
      $display("Coverage: 100%%");
    end
    $display("\nEnd.\n");
    $finish;
  end
endmodule
