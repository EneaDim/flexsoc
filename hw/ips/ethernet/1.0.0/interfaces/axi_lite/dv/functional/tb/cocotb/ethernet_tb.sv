`timescale 1ns/1ps

module ethernet_tb;
  logic clk_i;
  logic rst_ni;
  logic phy_gtx_clk_i;
  logic phy_rst_i;
  logic phy_gmii_rx_clk_i;
  logic phy_mii_tx_clk_i;
  ethernet_reg_pkg::axi_lite_req_t axi_lite_i;
  ethernet_reg_pkg::axi_lite_rsp_t axi_lite_o;
  logic [ethernet_reg_pkg::AW-1:0] core_axi_aw_addr_i;
  logic [2:0] core_axi_aw_prot_i;
  logic core_axi_aw_valid_i;
  logic core_axi_aw_ready_o;
  logic [ethernet_reg_pkg::DW-1:0] core_axi_w_data_i;
  logic [ethernet_reg_pkg::DBW-1:0] core_axi_w_strb_i;
  logic core_axi_w_valid_i;
  logic core_axi_w_ready_o;
  logic [1:0] core_axi_b_resp_o;
  logic core_axi_b_valid_o;
  logic core_axi_b_ready_i;
  logic [ethernet_reg_pkg::AW-1:0] core_axi_ar_addr_i;
  logic [2:0] core_axi_ar_prot_i;
  logic core_axi_ar_valid_i;
  logic core_axi_ar_ready_o;
  logic [ethernet_reg_pkg::DW-1:0] core_axi_r_data_o;
  logic [1:0] core_axi_r_resp_o;
  logic core_axi_r_valid_o;
  logic core_axi_r_ready_i;



  logic [7:0] phy_gmii_rxd_i;
  logic phy_gmii_rx_dv_i;
  logic phy_gmii_rx_er_i;
  logic phy_mii_select_i;
  logic [1:0] phy_speed_i;
  logic phy_speed_valid_i;
  logic [7:0] tx_data_i;
  logic tx_valid_i;
  logic tx_last_i;
  logic tx_error_i;
  logic phy_gmii_tx_clk_o;
  logic [7:0] phy_gmii_txd_o;
  logic phy_gmii_tx_en_o;
  logic phy_gmii_tx_er_o;
  logic tx_clk_o;
  logic tx_rst_o;
  logic tx_ready_o;
  logic rx_clk_o;
  logic rx_rst_o;
  logic [7:0] rx_data_o;
  logic rx_valid_o;
  logic rx_last_o;
  logic rx_error_o;
  logic intr_tx_underflow_o;
  logic intr_rx_bad_frame_o;
  logic intr_rx_bad_fcs_o;
  logic flexsoc_event_valid = 1'b0;
  logic [31:0] flexsoc_event_value = 32'b0;
  integer flexsoc_event_sequence = 0;
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

  ethernet u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .phy_rst_i                (phy_rst_i),
    .phy_gtx_clk_i            (phy_gtx_clk_i),
    .phy_gmii_rx_clk_i        (phy_gmii_rx_clk_i),
    .phy_gmii_rxd_i           (phy_gmii_rxd_i),
    .phy_gmii_rx_dv_i         (phy_gmii_rx_dv_i),
    .phy_gmii_rx_er_i         (phy_gmii_rx_er_i),
    .phy_mii_tx_clk_i         (phy_mii_tx_clk_i),
    .phy_mii_select_i         (phy_mii_select_i),
    .phy_speed_i              (phy_speed_i),
    .phy_speed_valid_i        (phy_speed_valid_i),
    .tx_data_i                (tx_data_i),
    .tx_valid_i               (tx_valid_i),
    .tx_last_i                (tx_last_i),
    .tx_error_i               (tx_error_i),
    .axi_lite_i               (axi_lite_i),
    .phy_gmii_tx_clk_o        (phy_gmii_tx_clk_o),
    .phy_gmii_txd_o           (phy_gmii_txd_o),
    .phy_gmii_tx_en_o         (phy_gmii_tx_en_o),
    .phy_gmii_tx_er_o         (phy_gmii_tx_er_o),
    .tx_clk_o                 (tx_clk_o),
    .tx_rst_o                 (tx_rst_o),
    .tx_ready_o               (tx_ready_o),
    .rx_clk_o                 (rx_clk_o),
    .rx_rst_o                 (rx_rst_o),
    .rx_data_o                (rx_data_o),
    .rx_valid_o               (rx_valid_o),
    .rx_last_o                (rx_last_o),
    .rx_error_o               (rx_error_o),
    .intr_tx_underflow_o      (intr_tx_underflow_o),
    .intr_rx_bad_frame_o      (intr_rx_bad_frame_o),
    .intr_rx_bad_fcs_o        (intr_rx_bad_fcs_o),
    .axi_lite_o               (axi_lite_o)
  );


endmodule
