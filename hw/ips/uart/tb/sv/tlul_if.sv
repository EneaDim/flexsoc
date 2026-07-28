`timescale 1ns/1ps

interface tlul_if (
  input  logic clk_i,
  input  logic rst_ni
);

  import tlul_pkg::*;

  // Host to Device
  tl_h2d_t h2d /* simulator public*/;

  // Device to Host
  tl_d2h_t d2h /* simulator public*/;

  // Modport for driver (testbench)
  modport drv (
    output h2d,
    input  d2h
  );

  // Modport for DUT
  modport dut (
    input  h2d,
    output d2h
  );

endinterface
