// -----------------------------------------------------------------------------
// Top-level CORDIC peripheral
// -----------------------------------------------------------------------------
// This module connects the auto-generated register block to the custom RTL core.
// The CORDIC IP is fully controlled through CSR registers, so no extra user I/O
// ports are required at this level.
// -----------------------------------------------------------------------------
module cordic
  import cordic_reg_pkg::*;
(
  // Clocks & Reset
  input  clk_i,
  input  rst_ni,

  // Bus interface
  input  tlul_pkg::tl_h2d_t tl_i,
  output tlul_pkg::tl_d2h_t tl_o
);

  cordic_reg2hw_t reg2hw;
  cordic_hw2reg_t hw2reg;

  // ---------------------------------------------------------------------------
  // Register block
  // ---------------------------------------------------------------------------
  cordic_reg_top u_cordic_reg (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),
    .tl_i     (tl_i),
    .tl_o     (tl_o),
    .reg2hw   (reg2hw),
    .hw2reg   (hw2reg),
    .devmode_i(1'b1)
  );

  // ---------------------------------------------------------------------------
  // Core
  // ---------------------------------------------------------------------------
  cordic_core u_cordic_core (
    .clk_i (clk_i),
    .rst_ni(rst_ni),
    .reg2hw(reg2hw),
    .hw2reg(hw2reg)
  );

endmodule
