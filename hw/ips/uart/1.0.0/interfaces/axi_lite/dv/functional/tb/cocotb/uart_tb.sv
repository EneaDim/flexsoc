`timescale 1ns/1ps
module uart_tb;
  import uart_reg_pkg::*;
  logic clk_i;
  logic rst_ni;
  logic rx_i;
  logic tx_o;
  axi_lite_req_t axi_lite_i;
  axi_lite_rsp_t axi_lite_o;
  logic [uart_reg_pkg::AW-1:0] axi_aw_addr_i;
  logic [2:0] axi_aw_prot_i;
  logic axi_aw_valid_i;
  logic axi_aw_ready_o;
  logic [uart_reg_pkg::DW-1:0] axi_w_data_i;
  logic [uart_reg_pkg::DBW-1:0] axi_w_strb_i;
  logic axi_w_valid_i;
  logic axi_w_ready_o;
  logic [1:0] axi_b_resp_o;
  logic axi_b_valid_o;
  logic axi_b_ready_i;
  logic [uart_reg_pkg::AW-1:0] axi_ar_addr_i;
  logic [2:0] axi_ar_prot_i;
  logic axi_ar_valid_i;
  logic axi_ar_ready_o;
  logic [uart_reg_pkg::DW-1:0] axi_r_data_o;
  logic [1:0] axi_r_resp_o;
  logic axi_r_valid_o;
  logic axi_r_ready_i;

  assign axi_lite_i = '{
    aw: '{addr: axi_aw_addr_i, prot: axi_aw_prot_i},
    aw_valid: axi_aw_valid_i,
    w: '{data: axi_w_data_i, strb: axi_w_strb_i},
    w_valid: axi_w_valid_i, b_ready: axi_b_ready_i,
    ar: '{addr: axi_ar_addr_i, prot: axi_ar_prot_i},
    ar_valid: axi_ar_valid_i, r_ready: axi_r_ready_i
  };
  assign axi_aw_ready_o = axi_lite_o.aw_ready;
  assign axi_w_ready_o = axi_lite_o.w_ready;
  assign axi_b_resp_o = axi_lite_o.b.resp;
  assign axi_b_valid_o = axi_lite_o.b_valid;
  assign axi_ar_ready_o = axi_lite_o.ar_ready;
  assign axi_r_data_o = axi_lite_o.r.data;
  assign axi_r_resp_o = axi_lite_o.r.resp;
  assign axi_r_valid_o = axi_lite_o.r_valid;

  initial begin
    rx_i = '1;
    axi_aw_addr_i = '0;
    axi_aw_prot_i = '0;
    axi_aw_valid_i = '0;
    axi_w_data_i = '0;
    axi_w_strb_i = '0;
    axi_w_valid_i = '0;
    axi_b_ready_i = '0;
    axi_ar_addr_i = '0;
    axi_ar_prot_i = '0;
    axi_ar_valid_i = '0;
    axi_r_ready_i = '0;
  end

  string wave_path;
  initial begin
    if (!$value$plusargs("WAVE=%s", wave_path)) begin
      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";
    end
    if (wave_path != "") begin
      `ifdef FLEXSOC_COCOTB_WAVE_OWNER
        $display("[TB] dumpfile = %s owner=cocotb", wave_path);
      `else
        $dumpfile(wave_path);
        $dumpvars(0, uart_tb);
      `endif
    end
    #1;
  end
  `ifdef FLEXSOC_ENABLE_SDF
    string sdf_path;
    initial begin
      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
      if (sdf_path != "") $sdf_annotate(sdf_path, u_uart);
    end
  `endif
  uart u_uart (.*);
endmodule
