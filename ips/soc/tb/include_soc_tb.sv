// Include source files 
`ifndef SYN
  `include "ips/pkgs/top_pkg.sv"
  `include "ips/pkgs/prim_util_pkg.sv"
  `include "ips/pkgs/prim_mubi_pkg.sv"
  `include "ips/pkgs/prim_secded_pkg.sv"
  `include "rtl/soc.sv"
`else
  `include "verilog/primitives.v"
  `include "verilog/sky130_fd_sc_hd.v"
  `include "syn/soc_synth.v"
`endif
