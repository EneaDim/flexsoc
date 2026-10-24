// Eight multiply-accumulate lanes instantiated using a generate loop.
module DSP_core #(
    parameter int LANES = 8,
    parameter int WIDTH = 16
) (
    input  logic                     clk_i,
    input  logic                     rst_ni,
    input  logic                     en_i,
    input  logic [LANES*WIDTH-1:0]   samples_i,
    input  logic [LANES*WIDTH-1:0]   coeffs_i,
    output logic [LANES*WIDTH-1:0]   results_o,
    output logic                     valid_o
);
    logic [LANES*WIDTH-1:0] lane_results;
    logic valid_q;
    for (genvar i = 0; i < LANES; i++) begin : g_mac
        DSP_lane #(.WIDTH(WIDTH)) u_lane (
            .clk_i(clk_i),
            .rst_ni(rst_ni),
            .en_i(en_i),
            .sample_i(samples_i[i*WIDTH +: WIDTH]),
            .coeff_i(coeffs_i[i*WIDTH +: WIDTH]),
            .result_o(lane_results[i*WIDTH +: WIDTH])
        );
    end
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) valid_q <= 1'b0;
        else if (en_i) valid_q <= 1'b1;
    end
    assign results_o = lane_results;
    assign valid_o = valid_q;
endmodule
