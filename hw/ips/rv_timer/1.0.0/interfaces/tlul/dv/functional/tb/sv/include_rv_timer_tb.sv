`ifndef SYN
  `include "top_pkg.sv"
  `include "prim_util_pkg.sv"
  `include "prim_mubi_pkg.sv"
  `include "prim_secded_pkg.sv"
  `include "rv_timer_reg_pkg.sv"
  `include "tlul_pkg.sv"
  `include "tlul_if.sv"
  `include "rv_timer.sv"
`else
  `ifndef FLEXSOC_GLS_EXTERNAL_MODELS
    `include "primitives.v"
    `include "sky130_fd_sc_hd.v"
  `endif
  `include "rv_timer_synth.v"
`endif
