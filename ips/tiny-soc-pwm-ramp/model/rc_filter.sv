module rc_filter #(
  parameter real ALPHA = 0.1,  // filter coefficient, 0 < ALPHA < 1
  parameter real VDD   = 3.3   // supply voltage in volts
  
) (
  input  logic clk_i,
  input  logic rst_ni,
  input  logic in,     // PWM input (0 or 1)
  output real  out    // filtered output (0 to 1)
);

  real y_prev;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      y_prev <= 0.0;
    end else begin
      y_prev <= ALPHA * in + (1.0 - ALPHA) * y_prev;
    end
  end

  assign out = y_prev * VDD;

endmodule

