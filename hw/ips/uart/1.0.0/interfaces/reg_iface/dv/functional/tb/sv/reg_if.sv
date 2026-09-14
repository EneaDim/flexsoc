`timescale 1ns/1ps

interface reg_if (
  input  logic clk_i,
  input  logic rst_ni
);
  import uart_reg_pkg::*;

  // Toward DUT (registered request)
  reg_req_t req /* simulator public*/;
  // From DUT (response)
  reg_rsp_t rsp /* simulator public*/;

  // Staging avoids combinational loops from TB into DUT.
  reg_req_t req_q;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) req <= '0;
    else         req <= req_q;
  end

  task automatic cycle();
    @(posedge clk_i);
    @(negedge clk_i);
  endtask

  task automatic init();
    req_q = '0;
  endtask

  task automatic write(
      input logic [uart_reg_pkg::AW-1:0]  addr,
      input logic [uart_reg_pkg::DW-1:0]  data,
      input logic [uart_reg_pkg::DBW-1:0] strb);
    logic response_error;

    $display("[%0t] REG WRITE: Addr = 0x%0h Data = 0x%0h WSTRB = 0x%0h", $time, addr, data, strb);

    req_q.valid = 1'b1;
    req_q.write = 1'b1;
    req_q.addr  = addr;
    req_q.wdata = data;
    req_q.wstrb = strb;

    // First edge registers req_q into req.  ready may already be high while
    // the bus is idle, so do not treat that idle level as an acceptance.
    cycle();
    while (!rsp.ready) cycle();

    // Capture the response while the accepted request is still visible.
    // Response fields may return to their idle values after the acceptance
    // edge, so never sample them after deasserting the staged request.
    response_error = rsp.error;
    req_q.valid = 1'b0;
    cycle();

    if (response_error) begin
      $display("[%0t] REG WRITE ERROR: Addr = 0x%0h", $time, addr);
    end else begin
      $display("[%0t] REG WRITE DONE: Addr = 0x%0h", $time, addr);
    end
    #1;
  endtask

  task automatic read(
      input  logic [uart_reg_pkg::AW-1:0] addr,
      output logic [uart_reg_pkg::DW-1:0] data);
    logic response_error;

    $display("[%0t] REG READ: Addr = 0x%0h", $time, addr);

    req_q.valid = 1'b1;
    req_q.write = 1'b0;
    req_q.addr  = addr;
    req_q.wdata = '0;
    req_q.wstrb = '0;

    // Register the request first; an idle-high ready is not a response.
    cycle();
    while (!rsp.ready) cycle();

    // Capture read data before the acceptance edge can trigger read-side
    // effects such as FIFO pop/clear-on-read.  Sampling one cycle later can
    // observe the next element or the idle response instead of this read.
    data = rsp.rdata;
    response_error = rsp.error;
    req_q.valid = 1'b0;
    cycle();

    if (response_error) begin
      $display("[%0t] REG READ ERROR: Addr = 0x%0h", $time, addr);
    end else begin
      $display("[%0t] REG READ DONE: Addr = 0x%0h Data = 0x%0h", $time, addr, data);
    end
    #1;
  endtask

  modport drv (
    input  clk_i,
    output req_q,
    input  rsp
  );

  modport dut (
    input  clk_i,
    input  rst_ni,
    input  req,
    output rsp
  );

endinterface
