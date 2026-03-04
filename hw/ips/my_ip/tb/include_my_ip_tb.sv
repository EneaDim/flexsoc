`ifndef SYN
  `include "../hw/ips/pkgs/top_pkg.sv"
  `include "../hw/ips/pkgs/prim_util_pkg.sv"
  `include "../hw/ips/pkgs/prim_mubi_pkg.sv"
  `include "../hw/ips/pkgs/prim_secded_pkg.sv"
  `include "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/rtl/my_ip_reg_pkg.sv"
  `include "../hw/ips/pkgs/tlul_pkg.sv"
  `include "tlul_utils.sv"
  `include "tlul_if.sv"
  `include "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/rtl/my_ip.sv"
`else
  `include "verilog/primitives.v"
  `include "verilog/sky130_fd_sc_hd.no_tc.v"
  `include "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/syn/my_ip_synth.v"
`endif
