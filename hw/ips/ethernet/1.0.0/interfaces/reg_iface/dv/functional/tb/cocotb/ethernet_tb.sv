`timescale 1ns/1ps

module ethernet_tb;
  logic clk_i;
  logic rst_ni;
  logic phy_gtx_clk_i;
  logic phy_rst_i;
  logic phy_gmii_rx_clk_i;
  logic phy_mii_tx_clk_i;
  ethernet_reg_pkg::reg_req_t reg_req_i;
  ethernet_reg_pkg::reg_rsp_t reg_rsp_o;
  logic core_reg_req_valid;
  logic core_reg_req_write;
  logic [ethernet_reg_pkg::AW-1:0] core_reg_req_addr;
  logic [ethernet_reg_pkg::DW-1:0] core_reg_req_wdata;
  logic [ethernet_reg_pkg::DBW-1:0] core_reg_req_wstrb;
  logic core_reg_rsp_ready;
  logic core_reg_rsp_error;
  logic [ethernet_reg_pkg::DW-1:0] core_reg_rsp_rdata;



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
assign reg_req_i = '{
  valid: core_reg_req_valid, write: core_reg_req_write,
  addr: core_reg_req_addr, wdata: core_reg_req_wdata,
  wstrb: core_reg_req_wstrb
};
assign core_reg_rsp_ready = reg_rsp_o.ready;
assign core_reg_rsp_error = reg_rsp_o.error;
assign core_reg_rsp_rdata = reg_rsp_o.rdata;




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
    .reg_req_i                (reg_req_i),
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
    .reg_rsp_o                (reg_rsp_o)
  );


endmodule
