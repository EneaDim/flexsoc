// SPDX-License-Identifier: MIT
// FlexSoC Ethernet MAC integration core, M5 candidate (not FPGA signed off).
// Source-proven MAC leaves are preserved; no register or bus adapter is authored here.
// Packet interfaces run in PHY MAC clocks: no undocumented asynchronous packet crossing.
// PHY_TARGET is GENERIC for behavioral RTL only; FPGA target must be reviewed separately.
`default_nettype none
module ethernet_core
  import ethernet_reg_pkg::*;
#(parameter bit PHY_MII_MODE = 1'b0)
(
  input  logic         clk_i,
  input  logic         rst_ni,
  input  ethernet_reg2hw_t reg2hw,
  output ethernet_hw2reg_t hw2reg,

  // PHY reset (active high). M5 requires coordinated PHY+CSR reset assertion.
  // All PHY clocks must run for mailbox acknowledgments.
  input  logic         phy_rst_i,
  input  logic         phy_gtx_clk_i,
  input  logic         phy_gmii_rx_clk_i,
  input  logic [7:0]   phy_gmii_rxd_i,
  input  logic         phy_gmii_rx_dv_i,
  input  logic         phy_gmii_rx_er_i,
  input  logic         phy_mii_tx_clk_i,
  output logic         phy_gmii_tx_clk_o,
  output logic [7:0]   phy_gmii_txd_o,
  output logic         phy_gmii_tx_en_o,
  output logic         phy_gmii_tx_er_o,

  // Platform-qualified mode: only switch MII/GMII while PHY reset asserted.
  input  logic         phy_mii_select_i,
  // Speed status is provided synchronous to clk_i by platform logic, not guessed from wires.
  input  logic [1:0]   phy_speed_i,
  input  logic         phy_speed_valid_i,

  // Packet producer MUST clock on tx_clk_o, hold data/last/error while !tx_ready_o.
  output logic         tx_clk_o,
  output logic         tx_rst_o,
  input  logic [7:0]   tx_data_i,
  input  logic         tx_valid_i,
  output logic         tx_ready_o,
  input  logic         tx_last_i,
  input  logic         tx_error_i,

  // RX packet sink MUST sample on rx_clk_o; RX cannot be backpressured.
  output logic         rx_clk_o,
  output logic         rx_rst_o,
  output logic [7:0]   rx_data_o,
  output logic         rx_valid_o,
  output logic         rx_last_o,
  output logic         rx_error_o,

  output logic         intr_tx_underflow_o,
  output logic         intr_rx_bad_frame_o,
  output logic         intr_rx_bad_fcs_o
);

  // This core is intentionally fixed to the generic PHY simulation target at M5.
  // FPGA implementation requires platform I/O primitive selection and physical timing.
  logic         mac_tx_clk, mac_tx_rst;
  logic         mac_rx_clk, mac_rx_rst;
  logic [7:0]   mac_gmii_txd, mac_gmii_rxd;
  logic         mac_gmii_tx_en, mac_gmii_tx_er;
  logic         mac_gmii_rx_dv, mac_gmii_rx_er;
  logic         tx_underflow, rx_bad_frame, rx_bad_fcs;

  assign tx_clk_o = mac_tx_clk;
  assign tx_rst_o = mac_tx_rst;
  assign rx_clk_o = mac_rx_clk;
  assign rx_rst_o = mac_rx_rst;

  ethernet_phy_if #(.PHY_MII_MODE(PHY_MII_MODE),
    .TARGET("GENERIC")) u_phy (
    .clk               (phy_gtx_clk_i),
    .rst               (phy_rst_i),
    .mac_gmii_rx_clk   (mac_rx_clk),
    .mac_gmii_rx_rst   (mac_rx_rst),
    .mac_gmii_rxd      (mac_gmii_rxd),
    .mac_gmii_rx_dv    (mac_gmii_rx_dv),
    .mac_gmii_rx_er    (mac_gmii_rx_er),
    .mac_gmii_tx_clk   (mac_tx_clk),
    .mac_gmii_tx_rst   (mac_tx_rst),
    .mac_gmii_txd      (mac_gmii_txd),
    .mac_gmii_tx_en    (mac_gmii_tx_en),
    .mac_gmii_tx_er    (mac_gmii_tx_er),
    .phy_gmii_rx_clk   (phy_gmii_rx_clk_i),
    .phy_gmii_rxd      (phy_gmii_rxd_i),
    .phy_gmii_rx_dv    (phy_gmii_rx_dv_i),
    .phy_gmii_rx_er    (phy_gmii_rx_er_i),
    .phy_mii_tx_clk    (phy_mii_tx_clk_i),
    .phy_gmii_tx_clk   (phy_gmii_tx_clk_o),
    .phy_gmii_txd      (phy_gmii_txd_o),
    .phy_gmii_tx_en    (phy_gmii_tx_en_o),
    .phy_gmii_tx_er    (phy_gmii_tx_er_o),
    .mii_select        (PHY_MII_MODE)
  );

  // CSR->TX coherent configuration mailbox. Data held until synchronized ACK.
  // Data is captured after two synchronizer stages of the request toggle.
  logic [8:0] tx_payload_csr;
  logic tx_req_csr, tx_ack_meta_csr, tx_ack_sync_csr;
  logic tx_ack_mac, tx_req_meta_mac, tx_req_sync_mac;
  logic [8:0] tx_cfg_mac;
  logic tx_applied_en_csr;
  logic tx_busy_csr;
  logic [8:0] tx_desired_csr;

  assign tx_desired_csr = {reg2hw.ctrl.tx_enable.q, reg2hw.ifg.q};
  assign tx_busy_csr = (tx_req_csr != tx_ack_sync_csr) ||
                       (tx_desired_csr != tx_payload_csr);

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      tx_payload_csr    <= {1'b0, 8'd12};
      tx_req_csr        <= 1'b0;
      tx_ack_meta_csr   <= 1'b0;
      tx_ack_sync_csr   <= 1'b0;
      tx_applied_en_csr <= 1'b0;
    end else begin
      tx_ack_meta_csr <= tx_ack_mac;
      tx_ack_sync_csr <= tx_ack_meta_csr;
      if (tx_req_csr == tx_ack_sync_csr) begin
        tx_applied_en_csr <= tx_payload_csr[8];
        if (tx_payload_csr != tx_desired_csr) begin
          tx_payload_csr <= tx_desired_csr;
          tx_req_csr <= ~tx_req_csr;
        end
      end
    end
  end

  always_ff @(posedge mac_tx_clk or posedge mac_tx_rst) begin
    if (mac_tx_rst) begin
      tx_req_meta_mac <= 1'b0;
      tx_req_sync_mac <= 1'b0;
      tx_ack_mac      <= 1'b0;
      tx_cfg_mac      <= {1'b0, 8'd12};
    end else begin
      tx_req_meta_mac <= tx_req_csr;
      tx_req_sync_mac <= tx_req_meta_mac;
      // Apply only while output is not transmitting; stall can postpone ACK.
      if (tx_req_sync_mac != tx_ack_mac && !mac_gmii_tx_en) begin
        tx_cfg_mac <= tx_payload_csr;
        tx_ack_mac <= tx_req_sync_mac;
      end
    end
  end

  // CSR->RX enable mailbox, separate from the TX clock domain.
  logic rx_payload_csr, rx_req_csr, rx_ack_meta_csr, rx_ack_sync_csr;
  logic rx_ack_mac, rx_req_meta_mac, rx_req_sync_mac;
  logic rx_cfg_mac, rx_applied_en_csr, rx_busy_csr;
  assign rx_busy_csr = (rx_req_csr != rx_ack_sync_csr) ||
                       (reg2hw.ctrl.rx_enable.q != rx_payload_csr);

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rx_payload_csr <= 1'b0;
      rx_req_csr <= 1'b0;
      rx_ack_meta_csr <= 1'b0;
      rx_ack_sync_csr <= 1'b0;
      rx_applied_en_csr <= 1'b0;
    end else begin
      rx_ack_meta_csr <= rx_ack_mac;
      rx_ack_sync_csr <= rx_ack_meta_csr;
      if (rx_req_csr == rx_ack_sync_csr) begin
        rx_applied_en_csr <= rx_payload_csr;
        if (rx_payload_csr != reg2hw.ctrl.rx_enable.q) begin
          rx_payload_csr <= reg2hw.ctrl.rx_enable.q;
          rx_req_csr <= ~rx_req_csr;
        end
      end
    end
  end

  always_ff @(posedge mac_rx_clk or posedge mac_rx_rst) begin
    if (mac_rx_rst) begin
      rx_req_meta_mac <= 1'b0;
      rx_req_sync_mac <= 1'b0;
      rx_ack_mac <= 1'b0;
      rx_cfg_mac <= 1'b0;
    end else begin
      rx_req_meta_mac <= rx_req_csr;
      rx_req_sync_mac <= rx_req_meta_mac;
      // Apply only between incoming PHY frames.
      if (rx_req_sync_mac != rx_ack_mac && !mac_gmii_rx_dv) begin
        rx_cfg_mac <= rx_payload_csr;
        rx_ack_mac <= rx_req_sync_mac;
      end
    end
  end

  // GMII/MII is an elaboration-time operating mode. The PHY clock mux
  // and both MAC datapaths consume the SAME constant mode.
  // The legacy phy_mii_select_i port is kept for interface compatibility,
  // but cannot switch the clock at run time.
  logic [1:0] tx_mii_sync, rx_mii_sync;
  assign tx_mii_sync = {2{PHY_MII_MODE}};
  assign rx_mii_sync = {2{PHY_MII_MODE}};

  ethernet_tx #(.PTP_TS_ENABLE(0)) u_tx (
    .clk(mac_tx_clk), .rst(mac_tx_rst),
    .s_axis_tdata(tx_data_i),
    .s_axis_tvalid(tx_valid_i),
    .s_axis_tready(tx_ready_o),
    .s_axis_tlast(tx_last_i),
    .s_axis_tuser(tx_error_i),
    .gmii_txd(mac_gmii_txd),
    .gmii_tx_en(mac_gmii_tx_en),
    .gmii_tx_er(mac_gmii_tx_er),
    .ptp_ts('0), .m_axis_ptp_ts(), .m_axis_ptp_ts_tag(),
    .m_axis_ptp_ts_valid(),
    .clk_enable(1'b1), .mii_select(tx_mii_sync[1]),
    .cfg_ifg(tx_cfg_mac[7:0]),
    .cfg_tx_enable(tx_cfg_mac[8]),
    .start_packet(), .error_underflow(tx_underflow)
  );

  ethernet_rx #(.PTP_TS_ENABLE(0)) u_rx (
    .clk(mac_rx_clk), .rst(mac_rx_rst),
    .gmii_rxd(mac_gmii_rxd),
    .gmii_rx_dv(mac_gmii_rx_dv),
    .gmii_rx_er(mac_gmii_rx_er),
    .m_axis_tdata(rx_data_o),
    .m_axis_tvalid(rx_valid_o),
    .m_axis_tlast(rx_last_o),
    .m_axis_tuser(rx_error_o),
    .ptp_ts('0),
    .clk_enable(1'b1), .mii_select(rx_mii_sync[1]),
    .cfg_rx_enable(rx_cfg_mac),
    .start_packet(), .error_bad_frame(rx_bad_frame),
    .error_bad_fcs(rx_bad_fcs)
  );

  // Lossless-within-modulo-range event CDC: binary event counts in source
  // clock, Gray-coded across domains, 2-flop synchronizers, decode in CSR.
  // Counter must not wrap 2^32 times between adjacent CSR observations.
  function automatic logic [31:0] gray_to_bin(input logic [31:0] gray);
    logic [31:0] result;
    result[31] = gray[31];
    for (int k=30; k>=0; k--) result[k] = result[k+1] ^ gray[k];
    return result;
  endfunction

  logic [31:0] tx_event_bin, rx_bad_event_bin, rx_fcs_event_bin;
  // The Gray buses MUST be source-domain flops before asynchronous sampling.
  // Combinational encoding of a multi-bit binary increment can glitch at CDC.
  logic [31:0] tx_event_gray, rx_bad_event_gray, rx_fcs_event_gray;
  function automatic logic [31:0] gray_of_increment(input logic [31:0] current);
    logic [31:0] next_value;
    next_value = current + 32'd1;
    return next_value ^ (next_value >> 1);
  endfunction

  always_ff @(posedge mac_tx_clk or posedge mac_tx_rst) begin
    if (mac_tx_rst) begin
      tx_event_bin  <= '0;
      tx_event_gray <= '0;
    end else if (tx_underflow) begin
      tx_event_bin  <= tx_event_bin + 32'd1;
      tx_event_gray <= gray_of_increment(tx_event_bin);
    end
  end
  always_ff @(posedge mac_rx_clk or posedge mac_rx_rst) begin
    if (mac_rx_rst) begin
      rx_bad_event_bin  <= '0;
      rx_fcs_event_bin  <= '0;
      rx_bad_event_gray <= '0;
      rx_fcs_event_gray <= '0;
    end else begin
      if (rx_bad_frame) begin
        rx_bad_event_bin  <= rx_bad_event_bin + 32'd1;
        rx_bad_event_gray <= gray_of_increment(rx_bad_event_bin);
      end
      if (rx_bad_fcs) begin
        rx_fcs_event_bin  <= rx_fcs_event_bin + 32'd1;
        rx_fcs_event_gray <= gray_of_increment(rx_fcs_event_bin);
      end
    end
  end

  (* async_reg = "true" *) logic [31:0] tx_gray_meta, rx_bad_gray_meta, rx_fcs_gray_meta;
  (* async_reg = "true" *) logic [31:0] tx_gray_sync, rx_bad_gray_sync, rx_fcs_gray_sync;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      tx_gray_meta <= '0; tx_gray_sync <= '0;
      rx_bad_gray_meta <= '0; rx_bad_gray_sync <= '0;
      rx_fcs_gray_meta <= '0; rx_fcs_gray_sync <= '0;
    end else begin
      tx_gray_meta <= tx_event_gray;
      tx_gray_sync <= tx_gray_meta;
      rx_bad_gray_meta <= rx_bad_event_gray;
      rx_bad_gray_sync <= rx_bad_gray_meta;
      rx_fcs_gray_meta <= rx_fcs_event_gray;
      rx_fcs_gray_sync <= rx_fcs_gray_meta;
    end
  end
  logic [31:0] tx_count_seen, rx_bad_count_seen, rx_fcs_count_seen;
  logic [31:0] tx_count_now, rx_bad_count_now, rx_fcs_count_now;
  assign tx_count_now = gray_to_bin(tx_gray_sync);
  assign rx_bad_count_now = gray_to_bin(rx_bad_gray_sync);
  assign rx_fcs_count_now = gray_to_bin(rx_fcs_gray_sync);

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      tx_count_seen <= '0;
      rx_bad_count_seen <= '0;
      rx_fcs_count_seen <= '0;
    end else begin
      tx_count_seen <= tx_count_now;
      rx_bad_count_seen <= rx_bad_count_now;
      rx_fcs_count_seen <= rx_fcs_count_now;
    end
  end

  always_comb begin
    hw2reg = '0;
    hw2reg.status.speed.d = phy_speed_i;
    hw2reg.status.speed.de = 1'b1;
    hw2reg.status.speed_valid.d = phy_speed_valid_i;
    hw2reg.status.speed_valid.de = 1'b1;
    hw2reg.status.tx_enabled.d = tx_applied_en_csr;
    hw2reg.status.tx_enabled.de = 1'b1;
    hw2reg.status.rx_enabled.d = rx_applied_en_csr;
    hw2reg.status.rx_enabled.de = 1'b1;
    hw2reg.status.cfg_pending.d = tx_busy_csr || rx_busy_csr;
    hw2reg.status.cfg_pending.de = 1'b1;

    hw2reg.tx_underflow_count.d = tx_count_now;
    hw2reg.tx_underflow_count.de = 1'b1;
    hw2reg.rx_bad_frame_count.d = rx_bad_count_now;
    hw2reg.rx_bad_frame_count.de = 1'b1;
    hw2reg.rx_bad_fcs_count.d = rx_fcs_count_now;
    hw2reg.rx_bad_fcs_count.de = 1'b1;

    hw2reg.intr_state.tx_underflow.d = 1'b1;
    hw2reg.intr_state.tx_underflow.de = (tx_count_now != tx_count_seen) ||
       (reg2hw.intr_test.tx_underflow.qe && reg2hw.intr_test.tx_underflow.q);
    hw2reg.intr_state.rx_bad_frame.d = 1'b1;
    hw2reg.intr_state.rx_bad_frame.de = (rx_bad_count_now != rx_bad_count_seen) ||
       (reg2hw.intr_test.rx_bad_frame.qe && reg2hw.intr_test.rx_bad_frame.q);
    hw2reg.intr_state.rx_bad_fcs.d = 1'b1;
    hw2reg.intr_state.rx_bad_fcs.de = (rx_fcs_count_now != rx_fcs_count_seen) ||
       (reg2hw.intr_test.rx_bad_fcs.qe && reg2hw.intr_test.rx_bad_fcs.q);
  end

  assign intr_tx_underflow_o = reg2hw.intr_state.tx_underflow.q & reg2hw.intr_enable.tx_underflow.q;
  assign intr_rx_bad_frame_o = reg2hw.intr_state.rx_bad_frame.q & reg2hw.intr_enable.rx_bad_frame.q;
  assign intr_rx_bad_fcs_o = reg2hw.intr_state.rx_bad_fcs.q & reg2hw.intr_enable.rx_bad_fcs.q;
endmodule
`default_nettype wire
