// Auto-generated formal protocol view; not functional RTL.
module gpio (
  input wire clk_i,
  input wire rst_ni,
  input wire [3:0] cio_gpio_i,
  output wire [3:0] cio_gpio_o,
  output wire [3:0] cio_gpio_en_o,
  output wire [3:0] intr_gpio_o,
  input wire [108:0] tl_i,
  output wire [1:0] tl_o__flexsoc_eqy_handshake,
  output wire [16:0] tl_o__flexsoc_eqy_d_ctrl,
  output wire [31:0] tl_o__flexsoc_eqy_d_data,
  output wire [14:0] tl_o__flexsoc_eqy_d_meta
);

  wire [65:0] tl_o__raw;

  gpio__eqy_impl u_impl (
    .clk_i (clk_i),
    .rst_ni (rst_ni),
    .cio_gpio_i (cio_gpio_i),
    .cio_gpio_o (cio_gpio_o),
    .cio_gpio_en_o (cio_gpio_en_o),
    .intr_gpio_o (intr_gpio_o),
    .tl_i (tl_i),
    .tl_o (tl_o__raw)
  );

  assign tl_o__flexsoc_eqy_handshake = {tl_o__raw[65], tl_o__raw[0]};
  assign tl_o__flexsoc_eqy_d_ctrl = tl_o__raw[65] ? tl_o__raw[64:48] : '0;
  assign tl_o__flexsoc_eqy_d_data = (tl_o__raw[65] && (tl_o__raw[64:62] == 3'h1) && !tl_o__raw[1]) ? tl_o__raw[47:16] : '0;
  assign tl_o__flexsoc_eqy_d_meta = tl_o__raw[65] ? tl_o__raw[15:1] : '0;

endmodule
