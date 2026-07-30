// Include source files 
`ifndef SYN
  `include "top_pkg.sv"
  `include "prim_util_pkg.sv"
  `include "prim_mubi_pkg.sv"
  `include "prim_secded_pkg.sv"
  `include "fft_fsm.sv"
`else
  `include "primitives.v"
  `include "sky130_fd_sc_hd.no_tc.v"
  `include "fft_core_synth.v"
`endif
