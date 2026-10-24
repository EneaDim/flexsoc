module DSP_parallel_lane #(
    parameter int WIDTH = 16
) (
    input  logic clk_i,
    input  logic rst_ni,
    input  logic signed [WIDTH-1:0] sample_i,
    input  logic signed [WIDTH-1:0] coeff_i,
    output logic signed [2*WIDTH-1:0] product_o
);
    logic signed [2*WIDTH-1:0] product_d;
    always_comb product_d = sample_i * coeff_i;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) product_o <= '0;
        else product_o <= product_d;
    end
endmodule
