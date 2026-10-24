module DSP_fir #(
    parameter int WIDTH = 16,
    parameter int TAPS = 6
) (
    input logic clk_i, rst_ni, en_i,
    input logic signed [WIDTH-1:0] sample_i,
    input logic signed [TAPS*WIDTH-1:0] coeff_i,
    output logic signed [WIDTH-1:0] result_o
);
    logic signed [TAPS*WIDTH-1:0] products;
    logic signed [WIDTH-1:0] acc_d, acc_q;

    for (genvar tap = 0; tap < TAPS; tap++) begin : g_taps
        DSP_mul_lane #(.WIDTH(WIDTH)) u_mult (
            .clk_i(clk_i), .rst_ni(rst_ni), .en_i(en_i),
            .sample_i(sample_i),
            .coeff_i(coeff_i[tap*WIDTH +: WIDTH]),
            .product_o(products[tap*WIDTH +: WIDTH])
        );
    end
    always_comb begin
        acc_d = '0;
        for (int k = 0; k < TAPS; k++)
            acc_d = acc_d + products[k*WIDTH +: WIDTH];
    end
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) acc_q <= '0;
        else if (en_i) acc_q <= acc_d;
    end
    assign result_o = acc_q;
endmodule
