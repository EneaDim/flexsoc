module DSP_saturate #(parameter int WIDTH = 16) (
    input logic clk_i, rst_ni, en_i,
    input logic signed [WIDTH-1:0] data_i,
    output logic signed [WIDTH-1:0] data_o
);
    logic signed [WIDTH-1:0] clamp_d, clamp_q;
    assign clamp_d = data_i[WIDTH-1] ? '0 : data_i;
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) clamp_q <= '0;
        else if (en_i) clamp_q <= clamp_d;
    end
    assign data_o = clamp_q;
endmodule
