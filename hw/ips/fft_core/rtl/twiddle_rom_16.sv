module twiddle_rom_16 #(
  parameter int N = 16,
  parameter int WIDTH = 16
)(
  input  logic [2:0] addr,
  output logic signed [WIDTH-1:0] re,
  output logic signed [WIDTH-1:0] im
);

  // ROM arrays to hold precomputed twiddle factors
  logic signed [WIDTH-1:0] rom_re [0:N/2-1];
  logic signed [WIDTH-1:0] rom_im [0:N/2-1];

  initial begin
    rom_re[0] = 32768;
    rom_re[1] = 30274;
    rom_re[2] = 23170;
    rom_re[3] = 12540;
    rom_re[4] = 0;
    rom_re[5] = -12540;
    rom_re[6] = -23170;
    rom_re[7] = -30274;
    rom_im[0] = 0;
    rom_im[1] = -12540;
    rom_im[2] = -23170;
    rom_im[3] = -30274;
    rom_im[4] = -32768;
    rom_im[5] = -30274;
    rom_im[6] = -23170;
    rom_im[7] = -12540;
  end

  always_comb begin
    re = rom_re[addr];
    im = rom_im[addr];
  end

endmodule
