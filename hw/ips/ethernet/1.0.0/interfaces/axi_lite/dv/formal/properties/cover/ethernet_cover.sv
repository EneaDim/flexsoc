// Demonstrate reachable CSR-to-PHY configuration requests and acknowledgements.
module ethernet_mailbox_cover (
  input logic clk_i, rst_ni,
  input logic tx_req_csr, tx_ack_sync_csr,
  input logic rx_req_csr, rx_ack_sync_csr
);
  logic saw_tx_request = 1'b0;
  logic saw_rx_request = 1'b0;
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      saw_tx_request <= 1'b0;
      saw_rx_request <= 1'b0;
    end else begin
      if (tx_req_csr != tx_ack_sync_csr) saw_tx_request <= 1'b1;
      if (rx_req_csr != rx_ack_sync_csr) saw_rx_request <= 1'b1;
      cover (tx_req_csr != tx_ack_sync_csr);
      cover (rx_req_csr != rx_ack_sync_csr);
      cover (saw_tx_request && tx_req_csr == tx_ack_sync_csr);
      cover (saw_rx_request && rx_req_csr == rx_ack_sync_csr);
    end
  end
endmodule

bind ethernet_core ethernet_mailbox_cover ethernet_mailbox_cover_i (
  .clk_i(clk_i), .rst_ni(rst_ni),
  .tx_req_csr(tx_req_csr), .tx_ack_sync_csr(tx_ack_sync_csr),
  .rx_req_csr(rx_req_csr), .rx_ack_sync_csr(rx_ack_sync_csr)
);
