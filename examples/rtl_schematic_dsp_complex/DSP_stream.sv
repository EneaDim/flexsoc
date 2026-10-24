// Multi-stage, parameterized DSP demonstrator for Slang elaboration.
module DSP_stream #(
    parameter int WIDTH = 16,
    parameter int TAPS  = 6
) (
    input  logic                           clk_i,
    input  logic                           rst_ni,
    input  logic                           en_i,
    input  logic signed [WIDTH-1:0]        sample_i,
    input  logic signed [WIDTH-1:0]        gain_i,
    input  logic signed [TAPS*WIDTH-1:0]   coeff_i,
    output logic signed [WIDTH-1:0]        data_o,
    output logic                           valid_o
);
    logic signed [WIDTH-1:0] mix_i;
    logic signed [WIDTH-1:0] fir_raw;
    logic signed [WIDTH-1:0] clamped;
    logic                    valid_q;

    DSP_frontend #(.WIDTH(WIDTH)) u_gain (
        .clk_i(clk_i), .rst_ni(rst_ni), .en_i(en_i),
        .sample_i(sample_i), .gain_i(gain_i), .mix_o(mix_i)
    );
    DSP_fir #(.WIDTH(WIDTH), .TAPS(TAPS)) u_filter (
        .clk_i(clk_i), .rst_ni(rst_ni), .en_i(en_i),
        .sample_i(mix_i), .coeff_i(coeff_i), .result_o(fir_raw)
    );
    DSP_saturate #(.WIDTH(WIDTH)) u_round (
        .clk_i(clk_i), .rst_ni(rst_ni), .en_i(en_i),
        .data_i(fir_raw), .data_o(clamped)
    );
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) valid_q <= 1'b0;
        else if (en_i) valid_q <= 1'b1;
    end
    assign data_o = clamped;
    assign valid_o = valid_q;
endmodule
