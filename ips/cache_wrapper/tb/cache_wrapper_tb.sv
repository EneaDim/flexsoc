`timescale 1ns/1ps

module cache_wrapper_tb;

  parameter ADDR_WIDTH = 16;
  parameter DATA_WIDTH = 32;

  // Clock and reset
  logic clk;
  logic rst_n;

  // Instantiate the interface
  cache_wrapper_if #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH)
  ) cache_bus (
    .clk_i(clk),
    .rst_ni(rst_n)
  );

  // Clock generation
  always #5 clk = ~clk;

  // DUT instantiation
  cache_wrapper #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH)
  ) dut (
    .clk_i           (clk),
    .rst_ni          (rst_n),

    // CPU Interface
    .cpu_valid_i     (cache_bus.cpu_valid_i),
    .cpu_ready_o     (cache_bus.cpu_ready_o),
    .cpu_we_i        (cache_bus.cpu_we_i),
    .cpu_adr_i       (cache_bus.cpu_adr_i),
    .cpu_wdata_i     (cache_bus.cpu_wdata_i),
    .cpu_rdata_o     (cache_bus.cpu_rdata_o),
    .cpu_resp_valid_o(cache_bus.cpu_resp_valid_o),

    // Memory Interface
    .mem_valid_o     (cache_bus.mem_valid_o),
    .mem_ready_i     (cache_bus.mem_ready_i),
    .mem_we_o        (cache_bus.mem_we_o),
    .mem_adr_o       (cache_bus.mem_adr_o),
    .mem_wdata_o     (cache_bus.mem_wdata_o),
    .mem_rdata_i     (cache_bus.mem_rdata_i)
  );

  // Stimulus logic
  initial begin
    // Initialize
    clk = 0;
    rst_n = 0;
    #20;
    rst_n = 1;
    #20;

    // Write to address 0x10
    drive_cpu_transaction(1'b1, 16'h0010, 32'hABCD1234);
    wait_for_response();

    // Read from address 0x10
    drive_cpu_transaction(1'b0, 16'h0010, 32'h00000000);
    wait_for_response();

    $finish;
  end

  // Task to drive CPU request
  task drive_cpu_transaction(input bit we, input logic [ADDR_WIDTH-1:0] addr, input logic [DATA_WIDTH-1:0] data);
    cache_bus.cpu_valid_i  = 1;
    cache_bus.cpu_we_i     = we;
    cache_bus.cpu_adr_i    = addr;
    cache_bus.cpu_wdata_i  = data;

    // Wait until ready
    @(posedge clk);
    while (!cache_bus.cpu_ready_o) @(posedge clk);

    cache_bus.cpu_valid_i = 0;
  endtask

  // Task to wait for a response
  task wait_for_response();
    @(posedge clk);
    while (!cache_bus.cpu_resp_valid_o) @(posedge clk);
    $display("[%0t] Read Data: 0x%08h", $time, cache_bus.cpu_rdata_o);
  endtask

  // Memory model (simple, combinational or synchronous)
  always_ff @(posedge clk) begin
    if (!rst_n) begin
      cache_bus.mem_ready_i <= 0;
      cache_bus.mem_rdata_i <= '0;
    end else begin
      if (cache_bus.mem_valid_o) begin
        cache_bus.mem_ready_i <= 1;
        if (!cache_bus.mem_we_o) begin
          // Read - return a dummy value based on address
          cache_bus.mem_rdata_i <= {16'hBEEF, cache_bus.mem_adr_o[15:0]};
        end
      end else begin
        cache_bus.mem_ready_i <= 0;
      end
    end
  end

endmodule

