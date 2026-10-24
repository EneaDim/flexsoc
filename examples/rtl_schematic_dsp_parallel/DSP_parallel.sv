// FlexSoC RTL Explorer stress example: unpacked arrays of packed signed words.
module DSP_parallel #(
    parameter int WIDTH = 16,
    parameter int LANES = 64
) (
    input  logic clk_i,
    input  logic rst_ni,
    input  logic signed [WIDTH-1:0] sample_i [LANES],
    input  logic signed [WIDTH-1:0] coeff_i  [LANES],
    output logic signed [2*WIDTH-1:0] product_o [LANES]
);
    // Each element select is a real elaborated port expression: the viewer
    // shows its bus dependency but does not invent bit-exact mapping.
    for (genvar lane = 0; lane < LANES; ++lane) begin : g_lane
        DSP_parallel_lane #(.WIDTH(WIDTH)) u_mac (
            .clk_i(clk_i), .rst_ni(rst_ni),
            .sample_i(sample_i[lane]),
            .coeff_i(coeff_i[lane]),
            .product_o(product_o[lane])
        );
    end
endmodule
