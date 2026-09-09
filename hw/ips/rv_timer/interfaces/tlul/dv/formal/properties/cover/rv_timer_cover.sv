// Design-level reachability goals for the RV_TIMER core.
module rv_timer_design_cover #(
  parameter int N = 1
) (
  input logic clk_i, rst_ni,
  input logic active, tick,
  input logic [11:0] prescaler, tick_count,
  input logic [7:0] step,
  input logic [N-1:0] intr
);

  always_ff @(posedge clk_i) begin
    if (rst_ni) begin
      // Timer runs through the prescaler rather than only PRESCALE=0.
      cover (active && (prescaler != 0) && (tick_count != 0));

      // A real prescaled tick is reachable.
      cover (tick && (prescaler != 0) && (step != 0));

      // Every timer interrupt is reachable.
      for (int t = 0; t < N; t++)
        cover (intr[t]);
    end
  end

endmodule

bind rv_timer_core rv_timer_design_cover #(
  .N(N)
) rv_timer_design_cover_i (
  .clk_i(clk_i),
  .rst_ni(rst_ni),
  .active(active),
  .tick(tick),
  .prescaler(prescaler),
  .tick_count(tick_count),
  .step(step),
  .intr(intr)
);
