module DSP_frontend #(parameter int WIDTH = 16) (
    input logic clk_i, rst_ni, en_i,
    input logic signed [WIDTH-1:0] sample_i, gain_i,
    output logic signed [WIDTH-1:0] mix_o
);
    logic signed [2*WIDTH-1:0] product_d;
    logic signed [WIDTH-1:0] mix_q;
    assign product_d = sample_i * gain_i;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) mix_q <= '0;
        else if (en_i) mix_q <= product_d[WIDTH-1:0];
    end
    assign mix_o = mix_q;
endmodule
