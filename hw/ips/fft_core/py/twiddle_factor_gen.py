import math

def generate_twiddle_rom(N, WIDTH):
    # Number of address bits
    addr_width = int(math.log2(N // 2))
    scale = 2**(WIDTH - 1)  # Q1.(WIDTH-1) scaling factor

    # Prepare header of the SV module
    header = f"""\
module twiddle_rom #(
  parameter int N = {N},
  parameter int WIDTH = {WIDTH}
)(
  input  logic [{addr_width-1}:0] addr,
  output logic signed [WIDTH-1:0] re,
  output logic signed [WIDTH-1:0] im
);

  // ROM arrays to hold precomputed twiddle factors
  logic signed [WIDTH-1:0] rom_re [0:N/2-1];
  logic signed [WIDTH-1:0] rom_im [0:N/2-1];

  initial begin
"""

    # Generate twiddle factor values
    lines_re = []
    lines_im = []
    for k in range(N//2):
        angle = -2 * math.pi * k / N
        re_val = int(round(math.cos(angle) * scale))
        im_val = int(round(math.sin(angle) * scale))
        lines_re.append(f"    rom_re[{k}] = {re_val};")
        lines_im.append(f"    rom_im[{k}] = {im_val};")

    footer = """
  end

  always_comb begin
    re = rom_re[addr];
    im = rom_im[addr];
  end

endmodule
"""

    # Join everything
    sv_code = header + "\n".join(lines_re) + "\n" + "\n".join(lines_im) + footer
    return sv_code

if __name__ == "__main__":
    # Example usage:
    N = 64      # FFT size
    WIDTH = 16    # Bit width for fixed-point representation

    sv_module = generate_twiddle_rom(N, WIDTH)
    with open(f"twiddle_rom_{N}.sv", "w") as f:
        f.write(sv_module)

    print(f"Generated twiddle ROM module for N={N}, WIDTH={WIDTH} bits in twiddle_rom_{N}.sv")

