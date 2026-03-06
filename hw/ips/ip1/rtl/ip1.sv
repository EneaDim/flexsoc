// -----------------------------------------------------------------------------
// THIS FILE IS AUTO-GENERATED. It wires the register block with the core.
// -----------------------------------------------------------------------------
module ip1
  import ip1_reg_pkg::*;
(
  // Clocks & Reset
  input  clk_i,
  input  rst_ni,

  // Bus interface
  input  tlul_pkg::tl_h2d_t tl_i,
  output tlul_pkg::tl_d2h_t tl_o,

  // User I/O
  input  logic port_i,
  output logic port_o
);

  ip1_reg2hw_t reg2hw;
  ip1_hw2reg_t hw2reg;

  // Register block
  ip1_reg_top u_ip1_reg (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .tl_i(tl_i),
    .tl_o(tl_o),
    .reg2hw(reg2hw),
    .hw2reg(hw2reg),
    .devmode_i(1'b1)
  );

  // Core
  ip1_core u_ip1_core (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .reg2hw(reg2hw),
    .hw2reg(hw2reg),
    .port_i(port_i),
    .port_o(port_o)
  );

endmodule