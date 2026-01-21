`ifndef SYN
  `include "ips/pkgs/top_pkg.sv"
  `include "ips/pkgs/prim_util_pkg.sv"
  `include "ips/pkgs/prim_mubi_pkg.sv"
  `include "ips/pkgs/prim_secded_pkg.sv"
  `include "rtl/pwm_reg_pkg.sv"
  `include "ips/pkgs/tlul_pkg.sv"
  `include "tb/tlul_utils.sv"
  `include "tb/tlul_if.sv"
  `include "rtl/pwm.sv"
`else
  `include "verilog/primitives.v"
  `include "verilog/sky130_fd_sc_hd.no_tc.v"
  `include "syn/pwm_synth.v"
`endif
