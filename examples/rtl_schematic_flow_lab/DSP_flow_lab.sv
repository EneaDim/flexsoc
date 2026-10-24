// Schematic connectivity test: port names intentionally differ at every boundary.
// Elaborate with slang --top DSP_flow_lab --ast-json ... (not a synthesis netlist).
module DSP_producer #(parameter int W=12) (
    input  logic [W-1:0] operand_i,
    output logic [W-1:0] produced_o
);
  assign produced_o = operand_i + W'(1);
endmodule

module DSP_consumer #(parameter int W=12) (
    input  logic [W-1:0] payload_i,
    output logic [W-1:0] consumed_o
);
  assign consumed_o = payload_i ^ W'(12'h055);
endmodule

module DSP_lane #(parameter int W=12) (
    input  logic [W-1:0] source_word_i,
    output logic [W-1:0] transformed_o
);
  assign transformed_o = source_word_i * W'(3);
endmodule

module DSP_flow_lab #(parameter int W=12, LANES=4) (
    input  logic clk_i, rst_ni, enable_i, select_i,
    input  logic [W-1:0] sample_i,
    output logic [W-1:0] result_o
);
  logic [W-1:0] from_producer;
  logic [W-1:0] middle_wire;
  logic [W-1:0] after_consumer;
  logic [W-1:0] tally_q;
  logic [W-1:0] lanes_in  [LANES];
  logic [W-1:0] lanes_out [LANES];

  DSP_producer #(.W(W)) u_right (
    .operand_i(sample_i), .produced_o(from_producer)
  );
  assign middle_wire = from_producer;
  DSP_consumer #(.W(W)) u_left (
    .payload_i(middle_wire), .consumed_o(after_consumer)
  );

  for (genvar lane=0;lane<LANES;lane++) begin : g_parallel
    assign lanes_in[lane] = after_consumer + W'(lane);
    DSP_lane #(.W(W)) arbitrary_instance_name (
      .source_word_i(lanes_in[lane]), .transformed_o(lanes_out[lane])
    );
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) tally_q <= '0;
    else if (enable_i) tally_q <= tally_q + after_consumer;
  end
  assign result_o = select_i ? tally_q : lanes_out[0];
endmodule
