`timescale 1ns/1ps

module ethernet_tb;
  logic clk_i;
  logic rst_ni;
  logic phy_gtx_clk_i;
  logic phy_rst_i;
  logic phy_gmii_rx_clk_i;
  logic phy_mii_tx_clk_i;
  logic [108:0] tl_i;
  logic [65:0]  tl_o;
  logic        core_a_valid;
  logic [2:0]  core_a_opcode;
  logic [2:0]  core_a_param;
  logic [1:0]  core_a_size;
  logic [7:0]  core_a_source;
  logic [31:0] core_a_address;
  logic [3:0]  core_a_mask;
  logic [31:0] core_a_data;
  logic        core_d_ready;
  logic        core_a_ready;
  logic        core_d_valid;
  logic [31:0] core_d_data;
  logic        core_d_error;



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
  localparam logic [2:0] FLEXSOC_TL_PUT_FULL    = 3'h0;
  localparam logic [2:0] FLEXSOC_TL_PUT_PARTIAL = 3'h1;
  localparam logic [2:0] FLEXSOC_TL_GET         = 3'h4;

  function automatic logic [6:0] flexsoc_tlul_data_intg(input logic [31:0] data_i);
    logic [38:0] data_o;
    begin
      data_o = {7'b0, data_i};
      data_o[32] = ^(data_o & 39'h002606BD25);
      data_o[33] = ^(data_o & 39'h00DEBA8050);
      data_o[34] = ^(data_o & 39'h00413D89AA);
      data_o[35] = ^(data_o & 39'h0031234ED1);
      data_o[36] = ^(data_o & 39'h00C2C1323B);
      data_o[37] = ^(data_o & 39'h002DCC624C);
      data_o[38] = ^(data_o & 39'h0098505586);
      data_o = data_o ^ 39'h2A00000000;
      flexsoc_tlul_data_intg = data_o[38:32];
    end
  endfunction

  function automatic logic [6:0] flexsoc_tlul_cmd_intg(
    input logic [2:0] opcode,
    input logic [31:0] address,
    input logic [3:0] mask
  );
    logic [56:0] payload;
    logic [63:0] data_o;
    begin
      payload = {14'b0, 4'h9, address, opcode, mask};
      data_o = {7'b0, payload};
      data_o[57] = ^(data_o & 64'h0103FFF800007FFF);
      data_o[58] = ^(data_o & 64'h017C1FF801FF801F);
      data_o[59] = ^(data_o & 64'h01BDE1F87E0781E1);
      data_o[60] = ^(data_o & 64'h01DEEE3B8E388E22);
      data_o[61] = ^(data_o & 64'h01EF76CDB2C93244);
      data_o[62] = ^(data_o & 64'h01F7BB56D5525488);
      data_o[63] = ^(data_o & 64'h01FBDDA769A46910);
      data_o = data_o ^ 64'h5400000000000000;
      flexsoc_tlul_cmd_intg = data_o[63:57];
    end
  endfunction

  function automatic logic [108:0] flexsoc_tlul_h2d(
    input logic valid,
    input logic [2:0] opcode,
    input logic [2:0] param,
    input logic [1:0] size,
    input logic [7:0] source,
    input logic [31:0] address,
    input logic [3:0] mask,
    input logic [31:0] data,
    input logic ready
  );
    logic [108:0] value;
    begin
      value = '0;
      value[108]     = valid;
      value[107:105] = opcode;
      value[104:102] = param;
      value[101:100] = size;
      value[99:92]   = source;
      value[91:60]   = address;
      value[59:56]   = mask;
      value[55:24]   = data;
      value[23:19]   = 5'b0;
      value[18:15]   = 4'h9;
      value[14:8]    = flexsoc_tlul_cmd_intg(opcode, address, mask);
      value[7:1]     = flexsoc_tlul_data_intg(data);
      value[0]       = ready;
      flexsoc_tlul_h2d = value;
    end
  endfunction

assign tl_i = flexsoc_tlul_h2d(
  core_a_valid, core_a_opcode, core_a_param, core_a_size,
  core_a_source, core_a_address, core_a_mask, core_a_data,
  core_d_ready
);
assign core_a_ready = tl_o[0];
assign core_d_valid = tl_o[65];
assign core_d_data  = tl_o[47:16];
assign core_d_error = tl_o[1];



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

  ethernet #(

      .PHY_MII_MODE(1)

  ) u_dut (
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
    .tl_i                     (tl_i),
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
    .tl_o                     (tl_o)
  );


endmodule
