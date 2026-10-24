// FlexSoC RTL Explorer demo: parameterized parallel DSP datapath.
module DSP #(
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
    DSP_core #(.LANES(LANES), .WIDTH(WIDTH)) u_core (
        .clk_i(clk_i), .rst_ni(rst_ni), .en_i(en_i),
        .samples_i(samples_i), .coeffs_i(coeffs_i),
        .results_o(results_o), .valid_o(valid_o)
    );
endmodule
