module twiddle_rom_8 #(
  parameter int N = 8,
  parameter int WIDTH = 16
)(
  input  logic [1:0] addr,
  output logic signed [WIDTH-1:0] re,
  output logic signed [WIDTH-1:0] im
);

  // ROM arrays to hold precomputed twiddle factors
  logic signed [WIDTH-1:0] rom_re [0:N/2-1];
  logic signed [WIDTH-1:0] rom_im [0:N/2-1];

  initial begin
    rom_re[0] = 32767;
    rom_re[1] = 23170;
    rom_re[2] = 0;
    rom_re[3] = -23170;
    rom_im[0] = 0;
    rom_im[1] = -23170;
    rom_im[2] = -32768;
    rom_im[3] = -23170;
  end

  always_comb begin
    re = rom_re[addr];
    im = rom_im[addr];
  end

endmodule
