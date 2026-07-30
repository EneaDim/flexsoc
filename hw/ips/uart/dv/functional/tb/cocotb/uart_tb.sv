`timescale 1ns/1ps

// Auto-generated Cocotb TL-UL wrapper for uart.
// Edit setup_cocotb.py instead of this generated file.
module uart_tb;

  // Clock and reset.
  logic clk_i;
  logic rst_ni;

  // Scalar DUT ports discovered from the RTL header.
  logic cio_rx_i;
  logic cio_tx_o;
  logic cio_tx_en_o;

  // TL-UL request channel fields driven from Cocotb.
  logic                       tl_i_a_valid;
  tlul_pkg::tl_a_op_e         tl_i_a_opcode;
  logic [2:0]                 tl_i_a_param;
  logic [top_pkg::TL_SZW-1:0] tl_i_a_size;
  logic [top_pkg::TL_AIW-1:0] tl_i_a_source;
  logic [top_pkg::TL_AW-1:0]  tl_i_a_address;
  logic [top_pkg::TL_DBW-1:0] tl_i_a_mask;
  logic [top_pkg::TL_DW-1:0]  tl_i_a_data;
  logic                       tl_i_d_ready;

  // TL-UL response channel fields sampled by Cocotb.
  logic                       tl_o_d_valid;
  tlul_pkg::tl_d_op_e         tl_o_d_opcode;
  logic [top_pkg::TL_DW-1:0]  tl_o_d_data;
  logic                       tl_o_d_error;
  logic                       tl_o_a_ready;

  // Packed TL-UL buses connected to the DUT.
  tlul_pkg::tl_h2d_t          tl_i;
  tlul_pkg::tl_d2h_t          tl_o;

  assign tl_i.a_valid   = tl_i_a_valid;
  assign tl_i.a_opcode  = tl_i_a_opcode;
  assign tl_i.a_param   = tl_i_a_param;
  assign tl_i.a_size    = tl_i_a_size;
  assign tl_i.a_source  = tl_i_a_source;
  assign tl_i.a_address = tl_i_a_address;
  assign tl_i.a_mask    = tl_i_a_mask;
  assign tl_i.a_data    = tl_i_a_data;
  assign tl_i.d_ready   = tl_i_d_ready;

  // Generate TL-UL integrity sideband values from the unpacked fields.
  logic [tlul_pkg::H2DCmdIntgWidth-1:0] cmd_intg_calc;
  logic [tlul_pkg::DataIntgWidth-1:0]   data_intg_calc;

  always_comb begin
    /* verilator lint_off IMPLICITSTATIC */
    tlul_pkg::tl_h2d_t t = '0;
    /* verilator lint_on */

    t.a_address         = tl_i_a_address;
    t.a_opcode          = tl_i_a_opcode;
    t.a_mask            = tl_i_a_mask;
    t.a_user.instr_type = prim_mubi_pkg::MuBi4False;

    cmd_intg_calc       = tlul_pkg::get_cmd_intg(t);
    data_intg_calc      = tlul_pkg::get_data_intg(tl_i_a_data);
  end

  assign tl_i.a_user.instr_type = prim_mubi_pkg::MuBi4False;
  assign tl_i.a_user.cmd_intg   = cmd_intg_calc;
  assign tl_i.a_user.data_intg  = data_intg_calc;

  assign tl_o_d_valid  = tl_o.d_valid;
  assign tl_o_d_opcode = tl_o.d_opcode;
  assign tl_o_d_data   = tl_o.d_data;
  assign tl_o_d_error  = tl_o.d_error;
  assign tl_o_a_ready  = tl_o.a_ready;

  // Wave dump for local debug.
  initial begin
    $dumpfile("uart_tb.vcd");
    $dumpvars(0, uart_tb);
    #1;
  end

  // Device under test.
  uart u_uart (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .*
  );

endmodule
