// Sequential MAC with clear register boundaries (D/Q/clk/reset/enable).
module DSP_lane #(
    parameter int WIDTH = 16
) (
    input  logic                   clk_i,
    input  logic                   rst_ni,
    input  logic                   en_i,
    input  logic [WIDTH-1:0]       sample_i,
    input  logic [WIDTH-1:0]       coeff_i,
    output logic [WIDTH-1:0]       result_o
);
    logic [WIDTH-1:0] product_d;
    logic [WIDTH-1:0] product_q;
    logic [WIDTH-1:0] accum_d;
    logic [WIDTH-1:0] accum_q;
    assign product_d = sample_i * coeff_i;
    assign accum_d = accum_q + product_q;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            product_q <= '0;
            accum_q <= '0;
        end else if (en_i) begin
            product_q <= product_d;
            accum_q <= accum_d;
        end
    end
    assign result_o = accum_q;
endmodule
