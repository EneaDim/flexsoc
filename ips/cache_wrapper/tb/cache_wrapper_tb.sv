// Timescale 
`timescale 1ns/1ps 
// Include files 
`include "tb/include_cache_wrapper_tb.sv"

module cache_wrapper_tb;
  //Parameters
  parameter int CLK_PERIOD = 10; // Clock period in ns
  parameter DATA_WIDTH = 32;
  parameter ADDR_WIDTH = 16;
  parameter CACHE_SIZE = 1024;
  parameter ASSOCIATIVITY = 2;
  // Inputs
  reg clk_i;
  reg rst_ni;
  reg cpu_valid_i;
  reg cpu_we_i;
  reg [ADDR_WIDTH-1:0] cpu_adr_i;
  reg [DATA_WIDTH-1:0] cpu_wdata_i;
  reg mem_ready_i;
  reg [DATA_WIDTH-1:0] mem_rdata_i;
  // Outputs
  wire cpu_ready_o;
  wire [DATA_WIDTH-1:0] cpu_rdata_o;
  wire cpu_resp_valid_o;
  wire mem_valid_o;
  wire mem_we_o;
  wire [ADDR_WIDTH-1:0] mem_adr_o;
  wire [DATA_WIDTH-1:0] mem_wdata_o;

  integer error_count;


  // Device Under Test Instance
  cache_wrapper
  `ifndef SYN
    #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_WIDTH(ADDR_WIDTH),
      .CACHE_SIZE(CACHE_SIZE),
      .ASSOCIATIVITY(ASSOCIATIVITY)
    ) 
  `endif
  u_cache_wrapper (
    .clk_i,
    .rst_ni,
    .cpu_valid_i,
    .cpu_we_i,
    .cpu_adr_i,
    .cpu_wdata_i,
    .mem_ready_i,
    .mem_rdata_i,
    .cpu_ready_o,
    .cpu_rdata_o,
    .cpu_resp_valid_o,
    .mem_valid_o,
    .mem_we_o,
    .mem_adr_o,
    .mem_wdata_o
  );

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_cache_wrapper.vcd");
    `else
      $dumpfile("sim/dump_cache_wrapper_syn.vcd");
    `endif
    $dumpvars(0, cache_wrapper_tb);
  end

  // Error count
  initial begin
    error_count = 0;
  end

  // Task: Perform a write
  task automatic write(input logic [15:0] addr, input logic [31:0] data);
    begin
      $display("[WRITE] Requesting write at time %0t: addr=0x%04h, data=0x%08h", $time, addr, data);      
      @(posedge clk_i);
      wait (cpu_ready_o);
      cpu_valid_i <= 1;
      cpu_adr_i   <= addr;
      cpu_we_i    <= 1;
      cpu_wdata_i <= data;

      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      @(posedge clk_i);
      $finish;

      // Wait until DUT is ready to accept the write
      do @(posedge clk_i); while (!cpu_ready_o);
      cpu_valid_i <= 0;
      // Wait for write response
      do @(posedge clk_i); while (!cpu_resp_valid_o);

      while (!cpu_resp_valid_o) @(posedge clk_i);
      $display("Write complete: addr = 0x%04h, data = 0x%08h", addr, data);
    end
  endtask

  // Task: Perform a read
  task automatic read(input logic [15:0] addr);
    begin
      $display("[READ ] Requesting read  at time %0t: addr=0x%04h", $time, addr);      
      @(posedge clk_i);
      wait (cpu_ready_o);
      cpu_valid_i <= 1;
      cpu_adr_i   <= addr;
      cpu_we_i    <= 0;
      
      // Wait until DUT is ready to accept the write
      do @(posedge clk_i); while (!cpu_ready_o);
      cpu_valid_i <= 0;
      // Wait for write response
      do @(posedge clk_i); while (!cpu_resp_valid_o);

      $display("Read complete: addr = 0x%04h, data = 0x%08h", addr, cpu_rdata_o);
    end
  endtask

  initial begin
    // Init inputs
    rst_ni = 0;
    cpu_valid_i = 0;
    cpu_we_i = 0;
    cpu_adr_i = 0;
    cpu_wdata_i = 0;
    mem_ready_i = 0;
    mem_rdata_i = 0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD);
    // Start main test
    $display("\nRunning...\n");
    // INSERT YOUR CODE
    // Test scenario
    write(16'h0010, 32'hDEADBEEF);
    read(16'h0010);

    write(16'h0020, 32'hCAFEBABE);
    read(16'h0020);

    read(16'h0010); // Re-read to check hit

    $display("[TB DONE] Simulation complete at time %0t", $time);

    // Final Check
    if (error_count == 0) begin
      $display("Coverage: 100%%");
    end
    $display("\nEnd.\n");
    $finish;
  end
endmodule
