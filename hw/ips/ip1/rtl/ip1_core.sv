// -----------------------------------------------------------------------------
// THIS FILE IS AUTO-GENERATED. Edit the logic below the placeholders as needed.
// -----------------------------------------------------------------------------
module ip1_core
  import ip1_reg_pkg::*;
(
  input        clk_i,
  input        rst_ni,
  input  ip1_reg2hw_t reg2hw,
  output ip1_hw2reg_t hw2reg,

  // TODO: add real IP I/Os
  input  logic port_i,
  output logic port_o
);

  //////////////
  // Signals  //
  //////////////
  logic ctrl_en;
  logic ctrl_rst;
  logic [15:0] ctrl_setting;
  logic status_full;
  logic status_empty;
  logic [7:0] rdata;
  logic rdata_ready;
  logic [7:0] wdata;
  logic wdata_valid;

  //////////////
  // CTRL2REG //
  //////////////
  assign ctrl_en = reg2hw.ctrl.en.q;
  assign ctrl_rst = reg2hw.ctrl.rst.q;
  assign ctrl_setting = reg2hw.ctrl.setting.q;
  assign rdata_ready = reg2hw.rdata.re;
  assign wdata = reg2hw.wdata.q;
  assign wdata_valid = reg2hw.wdata.qe;

  //////////////
  // REG2CTRL //
  //////////////
  assign hw2reg.status.full.d = status_full;
  assign hw2reg.status.empty.d = status_empty;
  assign hw2reg.rdata.d = rdata;

  // ---------------------------------------------------------------------------
  // Example placeholder logic: 2-flop synchronizer
  // Replace with your real core functionality.
  // ---------------------------------------------------------------------------
  prim_ff_2sync #(
    .Width(1),
    .ResetValue('0)
  ) u_sync_name (
    .clk_i (clk_i),
    .rst_ni(rst_ni),
    .d_i   (port_i),
    .q_o   (port_o)
  );

endmodule