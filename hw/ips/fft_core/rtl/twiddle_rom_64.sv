module twiddle_rom_64 #(
  parameter int N = 64,
  parameter int WIDTH = 16
)(
  input  logic [4:0] addr,
  output logic signed [WIDTH-1:0] re,
  output logic signed [WIDTH-1:0] im
);

  // ROM arrays to hold precomputed twiddle factors
  logic signed [WIDTH-1:0] rom_re [0:N/2-1];
  logic signed [WIDTH-1:0] rom_im [0:N/2-1];

  initial begin
    rom_re[0] = 32768;
    rom_re[1] = 32610;
    rom_re[2] = 32138;
    rom_re[3] = 31357;
    rom_re[4] = 30274;
    rom_re[5] = 28899;
    rom_re[6] = 27246;
    rom_re[7] = 25330;
    rom_re[8] = 23170;
    rom_re[9] = 20788;
    rom_re[10] = 18205;
    rom_re[11] = 15447;
    rom_re[12] = 12540;
    rom_re[13] = 9512;
    rom_re[14] = 6393;
    rom_re[15] = 3212;
    rom_re[16] = 0;
    rom_re[17] = -3212;
    rom_re[18] = -6393;
    rom_re[19] = -9512;
    rom_re[20] = -12540;
    rom_re[21] = -15447;
    rom_re[22] = -18205;
    rom_re[23] = -20788;
    rom_re[24] = -23170;
    rom_re[25] = -25330;
    rom_re[26] = -27246;
    rom_re[27] = -28899;
    rom_re[28] = -30274;
    rom_re[29] = -31357;
    rom_re[30] = -32138;
    rom_re[31] = -32610;
    rom_im[0] = 0;
    rom_im[1] = -3212;
    rom_im[2] = -6393;
    rom_im[3] = -9512;
    rom_im[4] = -12540;
    rom_im[5] = -15447;
    rom_im[6] = -18205;
    rom_im[7] = -20788;
    rom_im[8] = -23170;
    rom_im[9] = -25330;
    rom_im[10] = -27246;
    rom_im[11] = -28899;
    rom_im[12] = -30274;
    rom_im[13] = -31357;
    rom_im[14] = -32138;
    rom_im[15] = -32610;
    rom_im[16] = -32768;
    rom_im[17] = -32610;
    rom_im[18] = -32138;
    rom_im[19] = -31357;
    rom_im[20] = -30274;
    rom_im[21] = -28899;
    rom_im[22] = -27246;
    rom_im[23] = -25330;
    rom_im[24] = -23170;
    rom_im[25] = -20788;
    rom_im[26] = -18205;
    rom_im[27] = -15447;
    rom_im[28] = -12540;
    rom_im[29] = -9512;
    rom_im[30] = -6393;
    rom_im[31] = -3212;
  end

  always_comb begin
    re = rom_re[addr];
    im = rom_im[addr];
  end

endmodule
