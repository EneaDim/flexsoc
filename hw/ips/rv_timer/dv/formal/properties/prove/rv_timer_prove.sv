// Design-level invariants for the RV_TIMER core. RTL remains designer-owned.
module rv_timer_design_prove #(
  parameter int N = 1
) (
  input logic clk_i, rst_ni,
  input logic active, tick,
  input logic [11:0] prescaler, tick_count,
  input logic [7:0] step,
  input logic [31:0] mtime, mtime_d,
  input logic [31:0] mtimecmp [N],
  input logic [N-1:0] intr
);

  logic past_valid = 1'b0;

  // Combinational behavior of the timer datapath.
  always_comb begin
    assert (tick == (active && (tick_count >= prescaler)));
    assert (mtime_d == (mtime + {{24{1'b0}}, step}));

    for (int t = 0; t < N; t++)
      assert (intr[t] == (active && (mtime >= mtimecmp[t])));
  end

  // Prescaler counter state transition.
  always_ff @(posedge clk_i) begin
    if (!rst_ni)
      assert (tick_count == '0);

    if (past_valid && rst_ni && $past(rst_ni)) begin
      if (!$past(active) || ($past(tick_count) == $past(prescaler)))
        assert (tick_count == '0);
      else
        assert (tick_count == ($past(tick_count) + 12'd1));
    end

    past_valid <= 1'b1;
  end

endmodule

bind rv_timer_core rv_timer_design_prove #(
  .N(N)
) rv_timer_design_prove_i (
  .clk_i(clk_i),
  .rst_ni(rst_ni),
  .active(active),
  .tick(tick),
  .prescaler(prescaler),
  .tick_count(tick_count),
  .step(step),
  .mtime(mtime),
  .mtime_d(mtime_d),
  .mtimecmp(mtimecmp),
  .intr(intr)
);
