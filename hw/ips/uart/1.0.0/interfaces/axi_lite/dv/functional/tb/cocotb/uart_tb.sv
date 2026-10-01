`timescale 1ns/1ps

module uart_tb;
  logic clk_i;
  logic rst_ni;
  uart_reg_pkg::axi_lite_req_t axi_lite_i;
  uart_reg_pkg::axi_lite_rsp_t axi_lite_o;
  logic [uart_reg_pkg::AW-1:0] core_axi_aw_addr_i;
  logic [2:0] core_axi_aw_prot_i;
  logic core_axi_aw_valid_i;
  logic core_axi_aw_ready_o;
  logic [uart_reg_pkg::DW-1:0] core_axi_w_data_i;
  logic [uart_reg_pkg::DBW-1:0] core_axi_w_strb_i;
  logic core_axi_w_valid_i;
  logic core_axi_w_ready_o;
  logic [1:0] core_axi_b_resp_o;
  logic core_axi_b_valid_o;
  logic core_axi_b_ready_i;
  logic [uart_reg_pkg::AW-1:0] core_axi_ar_addr_i;
  logic [2:0] core_axi_ar_prot_i;
  logic core_axi_ar_valid_i;
  logic core_axi_ar_ready_o;
  logic [uart_reg_pkg::DW-1:0] core_axi_r_data_o;
  logic [1:0] core_axi_r_resp_o;
  logic core_axi_r_valid_o;
  logic core_axi_r_ready_i;



  logic rx_i;
  logic tx_o;
  assign axi_lite_i = '{
    aw: '{addr: core_axi_aw_addr_i, prot: core_axi_aw_prot_i},
    aw_valid: core_axi_aw_valid_i,
    w: '{data: core_axi_w_data_i, strb: core_axi_w_strb_i},
    w_valid: core_axi_w_valid_i, b_ready: core_axi_b_ready_i,
    ar: '{addr: core_axi_ar_addr_i, prot: core_axi_ar_prot_i},
    ar_valid: core_axi_ar_valid_i, r_ready: core_axi_r_ready_i
  };
  assign core_axi_aw_ready_o = axi_lite_o.aw_ready;
  assign core_axi_w_ready_o = axi_lite_o.w_ready;
  assign core_axi_b_resp_o = axi_lite_o.b.resp;
  assign core_axi_b_valid_o = axi_lite_o.b_valid;
  assign core_axi_ar_ready_o = axi_lite_o.ar_ready;
  assign core_axi_r_data_o = axi_lite_o.r.data;
  assign core_axi_r_resp_o = axi_lite_o.r.resp;
  assign core_axi_r_valid_o = axi_lite_o.r_valid;



  `ifdef FLEXSOC_ENABLE_SDF
    string sdf_path;
    initial begin
      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
      if (sdf_path != "") begin
        `ifdef FLEXSOC_SDF_MIN
          $sdf_annotate(sdf_path, u_dut);
        `elsif FLEXSOC_SDF_TYP
          $sdf_annotate(sdf_path, u_dut);
        `else
          $sdf_annotate(sdf_path, u_dut);
        `endif
      end
    end
  `endif

  uart u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .rx_i                     (rx_i),
    .axi_lite_i               (axi_lite_i),
    .tx_o                     (tx_o),
    .axi_lite_o               (axi_lite_o)
  );
endmodule
