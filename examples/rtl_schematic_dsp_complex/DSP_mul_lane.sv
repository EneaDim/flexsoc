module DSP_mul_lane #(parameter int WIDTH = 16) (
    input logic clk_i, rst_ni, en_i,
    input logic signed [WIDTH-1:0] sample_i, coeff_i,
    output logic signed [WIDTH-1:0] product_o
);
    logic signed [2*WIDTH-1:0] product_d;
    logic signed [WIDTH-1:0] product_q;
    assign product_d = sample_i * coeff_i;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) product_q <= '0;
        else if (en_i) product_q <= product_d[WIDTH-1:0];
    end
    assign product_o = product_q;
endmodule
