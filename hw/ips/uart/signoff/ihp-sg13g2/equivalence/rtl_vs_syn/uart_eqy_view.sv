// Auto-generated formal protocol view; not functional RTL.
module uart (
  input wire clk_i,
  input wire rst_ni,
  input wire [108:0] tl_i,
  input wire cio_rx_i,
  output wire cio_tx_o,
  output wire cio_tx_en_o,
  output wire [1:0] tl_o__flexsoc_eqy_handshake,
  output wire [16:0] tl_o__flexsoc_eqy_d_ctrl,
  output wire [31:0] tl_o__flexsoc_eqy_d_data,
  output wire [14:0] tl_o__flexsoc_eqy_d_meta
);

  wire [65:0] tl_o__raw;

  uart__eqy_impl u_impl (
    .clk_i (clk_i),
    .rst_ni (rst_ni),
    .tl_i (tl_i),
    .tl_o (tl_o__raw),
    .cio_rx_i (cio_rx_i),
    .cio_tx_o (cio_tx_o),
    .cio_tx_en_o (cio_tx_en_o)
  );

  assign tl_o__flexsoc_eqy_handshake = {tl_o__raw[65], tl_o__raw[0]};
  assign tl_o__flexsoc_eqy_d_ctrl = tl_o__raw[65] ? tl_o__raw[64:48] : '0;
  assign tl_o__flexsoc_eqy_d_data = (tl_o__raw[65] && (tl_o__raw[64:62] == 3'h1) && !tl_o__raw[1]) ? tl_o__raw[47:16] : '0;
  assign tl_o__flexsoc_eqy_d_meta = tl_o__raw[65] ? tl_o__raw[15:1] : '0;

endmodule
