// Authored reachability goals for the 4-bit GPIO core.

module gpio_design_cover (
  input logic       clk_i,
  input logic       rst_ni,
  input logic [3:0] cio_gpio_i,
  input logic [3:0] cio_gpio_o,
  input logic [3:0] cio_gpio_en_o,
  input logic [3:0] intr_gpio_o
);

  logic reset_seen = 1'b0;

  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      reset_seen <= 1'b1;
    end else if (reset_seen) begin
      cover (cio_gpio_i != 4'h0);
      cover (cio_gpio_o != 4'h0);
      cover (cio_gpio_en_o != 4'h0);
      cover (intr_gpio_o != 4'h0);
    end
  end

endmodule

bind gpio_core gpio_design_cover gpio_design_cover_i (
  .clk_i         (clk_i),
  .rst_ni        (rst_ni),
  .cio_gpio_i    (cio_gpio_i),
  .cio_gpio_o    (cio_gpio_o),
  .cio_gpio_en_o (cio_gpio_en_o),
  .intr_gpio_o   (intr_gpio_o)
);
