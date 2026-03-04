// Timescale 
`timescale 1ns/1ps 
// Include source files 
`include "top_pkg.sv"
`include "prim_util_pkg.sv"
`include "prim_mubi_pkg.sv"
`include "prim_secded_pkg.sv"
`include "tlul_pkg.sv"
`include "tlul_utils.sv"
`include "tlul_if.sv"
`include "spi_host_reg_pkg.sv"
`ifndef SYN
  `include "spi_host.sv"
`else
  `include "primitives.v"
  `include "sky130_fd_sc_hd.no_tc.v"
  `include "spi_host_synth.v"
`endif
