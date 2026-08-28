`ifndef SYN
  `include "top_pkg.sv"
  `include "prim_util_pkg.sv"
  `include "prim_mubi_pkg.sv"
  `include "prim_secded_pkg.sv"
  `include "uart_reg_pkg.sv"
  `include "tlul_pkg.sv"
  `include "tlul_if.sv"
  `include "uart.sv"
`else
  `ifndef FLEXSOC_GLS_EXTERNAL_MODELS
    `include "sg13g2_udp.v"
    `include "sg13g2_stdcell.v"
  `endif
  `include "uart_synth.v"
`endif
