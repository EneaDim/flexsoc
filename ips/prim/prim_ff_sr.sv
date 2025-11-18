module prim_ff_sr #(
  parameter int               Width      = 1,
  parameter logic [Width-1:0] ResetValue = 0
) (
  input  logic clk_i,
  input  logic rst_ni,
  input  logic [Width-1:0] set_i,
  input  logic [Width-1:0] rst_i,
  output logic [Width-1:0] q_o
);

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (~rst_ni) begin
      q_o <= ResetValue;
    end else if (rst_i) begin
      q_o <= ResetValue;
    end else if (set_i) begin
      q_o <= '1;
    end else begin
      q_o <= ResetValue;
    end
  end

endmodule

