`ifndef SYN
  `include "top_pkg.sv"
  `include "prim_util_pkg.sv"
  `include "prim_mubi_pkg.sv"
  `include "prim_secded_pkg.sv"
  `include "uart_reg_pkg.sv"
  `include "reg_if.sv"
  `include "uart.sv"
`else
  `include "uart_synth.v"
`endif
