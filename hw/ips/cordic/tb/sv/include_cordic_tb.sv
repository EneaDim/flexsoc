`ifndef SYN
  `include "top_pkg.sv"
  `include "prim_util_pkg.sv"
  `include "prim_mubi_pkg.sv"
  `include "prim_secded_pkg.sv"
  `include "cordic_reg_pkg.sv"
  `include "tlul_pkg.sv"
  `include "tlul_utils.sv"
  `include "tlul_if.sv"
  `include "cordic.sv"
`else
  `include "primitives.v"
  `include "sky130_fd_sc_hd.no_tc.v"
  `include "cordic_synth.v"
`endif
