// CSR-to-PHY configuration mailboxes must not overwrite an unacknowledged transfer.
module ethernet_mailbox_prove (
  input logic clk_i, rst_ni,
  input logic tx_req_csr, tx_ack_sync_csr,
  input logic [8:0] tx_payload_csr,
  input logic rx_req_csr, rx_ack_sync_csr, rx_payload_csr
);
  logic history_valid = 1'b0;
  always_ff @(posedge clk_i) begin
    if (history_valid && $past(rst_ni) && rst_ni) begin
      if ($past(tx_req_csr != tx_ack_sync_csr)) begin
        assert (tx_req_csr == $past(tx_req_csr));
        assert (tx_payload_csr == $past(tx_payload_csr));
      end
      if ($past(rx_req_csr != rx_ack_sync_csr)) begin
        assert (rx_req_csr == $past(rx_req_csr));
        assert (rx_payload_csr == $past(rx_payload_csr));
      end
    end
    history_valid <= 1'b1;
  end
endmodule

bind ethernet_core ethernet_mailbox_prove ethernet_mailbox_prove_i (
  .clk_i(clk_i), .rst_ni(rst_ni),
  .tx_req_csr(tx_req_csr), .tx_ack_sync_csr(tx_ack_sync_csr),
  .tx_payload_csr(tx_payload_csr),
  .rx_req_csr(rx_req_csr), .rx_ack_sync_csr(rx_ack_sync_csr),
  .rx_payload_csr(rx_payload_csr)
);
