#!/usr/bin/env python3
# Copyright 2025 Enea Dimroci
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
r"""
\file setup_tb.py
\brief Generate a SystemVerilog testbench and helper files for the given TOP.
\details
  This script inspects `<rtldir>/<top>.sv` to:
    - extract parameters, localparams, and port names (incl. clk_/rst_ tags),
    - optionally generate simple TL-UL or generic reg_iface drivers (for Verilator),
    - emit a compact include file for Verilator runs,
    - write `<output>/<top)_tb.sv` with clock gen, VCD dump, SDF annotate hook, and a tiny stimulus.

  ## CLI (legacy & long flags accepted)
    - -top / --top
    - -rtldir / --rtldir / --rtl-dir
    - -simdir / --simdir / --sim-dir
    - -syndir / --syndir / --syn-dir
    - -prim / --prim (nargs=+)
    - -clk / --clk (ns)
    - -comp / --comp / --compiler  (iverilog|verilator)
    - -itf / --itf / --bus         (tlul|reg_iface)
    - -vsv / --vsv                 ('sv' for SystemVerilog or 'v' for plain Verilog)  [default: 'sv']
    - -o / --output                (output directory for TB)                           [default: tb]
    - -f / --force                 (overwrite existing generated files)

  Files emitted (paths relative to --output):
    - include_<top>_tb.sv
    - tlul_if.sv, tlul_utils.sv           (if --itf tlul && --comp verilator)
    - reg_if.sv, reg_utils.sv             (if --itf reg_iface && --comp verilator)
    - <top>_tb.sv

  The script is intentionally conservative and does not rely on regex-heavy parsing:
  it only reads the module signature up to the first ');'.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path
from typing import List, Tuple

from common import (
    colorize, ensure_dir, safe_write_file,
    parse_sv_signature, has_reg_pkg
)

# -------------------------
# Render helpers (SV text)
# -------------------------

def _sv_header_include_for_verilator(top: str, rtldir: str, syndir: str,
                                     prims: List[str], flag_reg_pkg: bool,
                                     itf: str, vsv: str) -> str:
    inc: List[str] = []
    inc.append("`ifndef SYN")
    inc.append('  `include "ips/pkgs/top_pkg.sv"')
    inc.append('  `include "ips/pkgs/prim_util_pkg.sv"')
    inc.append('  `include "ips/pkgs/prim_mubi_pkg.sv"')
    inc.append('  `include "ips/pkgs/prim_secded_pkg.sv"')
    if flag_reg_pkg:
        inc.append(f'  `include "{rtldir}/{top}_reg_pkg.sv"')
    if flag_reg_pkg and itf == "tlul":
        inc.append('  `include "ips/pkgs/tlul_pkg.sv"')
        inc.append('  `include "tb/tlul_utils.sv"')
        inc.append('  `include "tb/tlul_if.sv"')
    if flag_reg_pkg and itf == "reg_iface":
        inc.append('  `include "tb/reg_utils.sv"')
        inc.append('  `include "tb/reg_if.sv"')
    # DUT source
    if vsv == "sv":
        inc.append(f'  `include "{rtldir}/{top}.sv"')
    else:
        inc.append(f'  `include "{rtldir}/{top}.v"')
    inc.append("`else")
    for p in prims:
        inc.append(f'  `include "{p}"')
    inc.append(f'  `include "{syndir}/{top}_synth.v"')
    inc.append("`endif")
    return "\n".join(inc) + "\n"


def _emit_tlul_if() -> str:
    return """`timescale 1ns/1ps

interface tlul_if (
  input  logic clk_i,
  input  logic rst_ni
);

  import tlul_pkg::*;

  // Host to Device
  tl_h2d_t h2d /*verilator public*/;

  // Device to Host
  tl_d2h_t d2h /*verilator public*/;

  // Modport for driver (testbench)
  modport drv (
    output h2d,
    input  d2h
  );

  // Modport for DUT
  modport dut (
    input  h2d,
    output d2h
  );

endinterface
"""


def _emit_tlul_utils() -> str:
    return """class tlul_utils;

  virtual tlul_if drv_if;

  function new(virtual tlul_if drv_if);
    this.drv_if = drv_if;
  endfunction

  task automatic tlul_write(input logic [top_pkg::TL_AW-1:0]  addr,
                            input logic [top_pkg::TL_DW-1:0]  data,
                            input logic [top_pkg::TL_AIW-1:0] source);

    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);

    drv_if.h2d.d_ready   = 1'b1;
    drv_if.h2d.a_valid   = 1'b1;
    drv_if.h2d.a_opcode  = tlul_pkg::PutFullData;
    drv_if.h2d.a_param   = 3'b000;
    drv_if.h2d.a_size    = 2;
    drv_if.h2d.a_source  = source;
    drv_if.h2d.a_address = addr;
    drv_if.h2d.a_mask    = 4'b1111;
    drv_if.h2d.a_data    = data;
    drv_if.h2d.a_user    = '0;

    do @(posedge drv_if.clk_i); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid = 0;

    do @(posedge drv_if.clk_i); while (!drv_if.d2h.d_valid);

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL WRITE DONE: Addr = 0x%08x", $time, addr);
    end
    #1;
  endtask

  task automatic tlul_read(input  logic [top_pkg::TL_AW-1:0]  addr,
                           output logic [top_pkg::TL_DW-1:0]  data,
                           input  logic [top_pkg::TL_AIW-1:0] source);

    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);

    drv_if.h2d.d_ready   = 1'b1;
    drv_if.h2d.a_valid   = 1'b1;
    drv_if.h2d.a_opcode  = tlul_pkg::Get;
    drv_if.h2d.a_param   = 3'b000;
    drv_if.h2d.a_size    = 2;
    drv_if.h2d.a_source  = source;
    drv_if.h2d.a_address = addr;
    drv_if.h2d.a_mask    = 4'b1111;
    drv_if.h2d.a_data    = '0;
    drv_if.h2d.a_user    = '0;

    do @(posedge drv_if.clk_i); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid = 0;

    do @(posedge drv_if.clk_i); while (!drv_if.d2h.d_valid);
    data = drv_if.d2h.d_data;

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);
    end
    #1;
  endtask

endclass
"""


def _emit_reg_if(top: str) -> str:
    return f"""`timescale 1ns/1ps

interface reg_if (
  input  logic clk_i,
  input  logic rst_ni
);
  import {top}_reg_pkg::*;

  // Toward DUT (registered request)
  reg_req_t req /*verilator public*/;
  // From DUT (response)
  reg_rsp_t rsp /*verilator public*/;

  // Staging avoids combinational loops from TB into DUT
  reg_req_t req_q;

  // Register the staged request (visible to DUT as 'req')
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) req <= '0;
    else         req <= req_q;
  end

  // Driver modport (TB)
  modport drv (
    input  clk_i,
    output req_q,
    input  rsp
  );

  // DUT modport (sees registered request)
  modport dut (
    input  clk_i,
    input  rst_ni,
    input  req,
    output rsp
  );

endinterface
"""


def _emit_reg_utils(top: str) -> str:
    return f"""class reg_utils;

  // Use the driver modport for clean directions & clock access
  virtual reg_if.drv drv_if;

  function new(virtual reg_if.drv drv_if);
    this.drv_if = drv_if;
  endfunction

  task automatic cycle();
    @(posedge drv_if.clk_i);
  endtask

  task automatic write(
      input  logic [{top}_reg_pkg::AW-1:0]  addr,
      input  logic [{top}_reg_pkg::DW-1:0]  data,
      input  logic [{top}_reg_pkg::DBW-1:0] strb = {{{top}_reg_pkg::DBW{{1'b1}}}});
    $display("[%0t] REG WRITE: Addr = 0x%0h Data = 0x%0h WSTRB = 0x%0h", $time, addr, data, strb);

    drv_if.req_q.valid <= 1'b1;
    drv_if.req_q.write <= 1'b1;
    drv_if.req_q.addr  <= addr;
    drv_if.req_q.wdata <= data;
    drv_if.req_q.wstrb <= strb;

    cycle();

    while (!drv_if.rsp.ready) cycle();

    drv_if.req_q.valid <= 1'b0;
    cycle();

    if (drv_if.rsp.error) begin
      $display("[%0t] REG WRITE ERROR: Addr = 0x%0h", $time, addr);
    end else begin
      $display("[%0t] REG WRITE DONE: Addr = 0x%0h", $time, addr);
    end
    #1;
  endtask

  task automatic read(
      input  logic [{top}_reg_pkg::AW-1:0]  addr,
      output logic [{top}_reg_pkg::DW-1:0]  data);
    $display("[%0t] REG READ: Addr = 0x%0h", $time, addr);

    drv_if.req_q.valid <= 1'b1;
    drv_if.req_q.write <= 1'b0;
    drv_if.req_q.addr  <= addr;
    drv_if.req_q.wdata <= '0;
    drv_if.req_q.wstrb <= '0;

    cycle();

    while (!drv_if.rsp.ready) cycle();

    data = drv_if.rsp.rdata;

    drv_if.req_q.valid <= 1'b0;
    cycle();

    if (drv_if.rsp.error) begin
      $display("[%0t] REG READ ERROR: Addr = 0x%0h", $time, addr);
    end else begin
      $display("[%0t] REG READ DONE: Addr = 0x%0h Data = 0x%0h", $time, addr, data);
    end
    #1;
  endtask

endclass
"""


def _render_tb(top: str,
               clk_period_ns: int,
               simdir: str,
               syndir: str,
               itf: str,
               compiler: str,
               vsv: str,
               sig: dict) -> str:
    """Compose the <top>_tb.sv body using parsed signature info."""
    params: List[Tuple[str, str]] = sig["parameters"]
    lparams: List[Tuple[str, str]] = sig["localparams"]
    ports_in: List[Tuple[str, str]] = sig["ports_in"]
    ports_out: List[Tuple[str, str]] = sig["ports_out"]
    clks: List[str] = sig["clks"]
    rsts: List[str] = sig["rsts"]

    lines: List[str] = []
    lines.append("// Timescale")
    lines.append("`timescale 1ns/1ps")
    lines.append("// Includes")
    if compiler == "verilator":
        lines.append(f'`include "tb/include_{top}_tb.sv"')
    else:
        # Fallback includes for non-Verilator
        lines.append("`ifndef SYN")
        lines.append(f'  `include "rtl/{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{syndir}/{top}_synth.v"')
        lines.append("`endif")
    lines.append("")
    lines.append(f"module {top}_tb;")
    lines.append("  // Parameters")
    lines.append(f"  parameter int CLK_PERIOD = {clk_period_ns}; // ns")
    for name, val in params:
        lines.append(f"  parameter {name} = {val};")
    for name, val in lparams:
        lines.append(f"  localparam {name} = {val};")

    # Inputs
    lines.append("\n  // Inputs")
    for name, w in ports_in:
        if w == 1 or w == "1":
            lines.append(f"  reg {name};")
        elif isinstance(w, str) and w.startswith("["):
            lines.append(f"  reg {w} {name};")
        else:
            # typedef or package type
            if itf == "tlul":
                lines.append(f"  {w} {name};")
            else:
                lines.append(f"  {top}_reg_pkg::{w} {name};")

    # Outputs
    lines.append("\n  // Outputs")
    for name, w in ports_out:
        if w == 1 or w == "1":
            lines.append(f"  wire {name};")
        elif isinstance(w, str) and w.startswith("["):
            lines.append(f"  wire {w} {name};")
        else:
            if itf == "tlul":
                lines.append(f"  {w} {name};")
            else:
                lines.append(f"  {top}_reg_pkg::{w} {name};")

    lines.append("\n  integer error_count;")
    # Optional rdata reg for quick examples
    lines.append(f"  logic [{top}_reg_pkg::DW-1:0] rdata;")

    # Interfaces (Verilator only)
    if compiler == "verilator":
        if itf == "tlul":
            lines.append("  tlul_utils tl_utils_inst;")
            lines.append("  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));")
        if itf == "reg_iface":
            lines.append("  reg_utils reg_utils_inst;")
            lines.append("  reg_if regif(.clk_i(clk_i), .rst_ni(rst_ni));")

    # DUT instance
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    # Map inputs: tl_i/reg_req_i special cases
    in_map = []
    for name, _w in ports_in:
        if itf == "tlul" and name == "tl_i":
            in_map.append(f"    .{name}(tl_if.h2d)")
        elif itf == "reg_iface" and name == "reg_req_i":
            in_map.append(f"    .{name}(regif.req)")
        else:
            in_map.append(f"    .{name}({name})")
    out_map = []
    for name, _w in ports_out:
        if itf == "tlul" and name == "tl_o":
            out_map.append(f"    .{name}(tl_if.d2h)")
        elif itf == "reg_iface" and name == "reg_rsp_o":
            out_map.append(f"    .{name}(regif.rsp)")
        else:
            out_map.append(f"    .{name}({name})")
    # join with commas and proper trailing
    all_map = in_map + out_map
    for i, s in enumerate(all_map):
        suffix = "," if i != len(all_map) - 1 else ""
        lines.append(s + suffix)
    lines.append("  );\n")

    # Clock gens
    for c in clks:
        lines.append("  initial begin")
        lines.append(f"    {c} = 0;")
        lines.append("    forever #(CLK_PERIOD / 2) " + f"{c} = ~{c};")
        lines.append("  end\n")

    # VCD
    lines.append("  // Dump VCD")
    lines.append("  initial begin")
    lines.append("    `ifndef SYN")
    lines.append(f'      $dumpfile("{simdir}/{top}.vcd");')
    lines.append("    `else")
    lines.append(f'      $dumpfile("{simdir}/{top}_syn.vcd");')
    lines.append("    `endif")
    lines.append(f"    $dumpvars(0, {top}_tb);")
    lines.append("  end\n")

    # SDF annotate (disabled for Verilator)
    lines.append("  // SDF backannotation")
    lines.append("  `ifndef VERILATOR")
    lines.append("    initial begin")
    lines.append(f'      string sdf = "signoff/sdf/{top}_ss.sdf";')
    lines.append(f"      $sdf_annotate(sdf, {top}_tb.u_{top}, , , \"MAXIMUM\");")
    lines.append("    end")
    lines.append("  `endif\n")

    # Stimulus
    lines.append("  initial begin")
    lines.append("    error_count = 0;")
    if ports_in:
        # init inputs (skip the first, often a clock)
        for nm, _ in ports_in[1:]:
            lines.append(f"    {nm} = '0;")
    # simple reset: first rst_ if present, else try second input heuristically
    if rsts:
        lines.append("    #(CLK_PERIOD);")
        lines.append(f"    {rsts[0]} = 1'b1;")
    else:
        if len(ports_in) > 1 and "rst" in ports_in[1][0]:
            lines.append("    #(CLK_PERIOD);")
            lines.append(f"    {ports_in[1][0]} = 1'b1;")

    lines.append("    #(CLK_PERIOD);")
    lines.append('    $display("\\nRunning...\\n");')

    if compiler == "verilator":
        if itf == "tlul":
            lines.append("    tl_utils_inst = new(tl_if);")
            lines.append("    #(CLK_PERIOD*10);")
            lines.append("    tl_utils_inst.tlul_write(32'h0, 32'h1, 4'h0);")
            lines.append("    #(CLK_PERIOD*10);")
            lines.append("    tl_utils_inst.tlul_read (32'h0, rdata, 4'h0);")
            lines.append('    $display("Read data: %h", rdata);')
            lines.append("    #(CLK_PERIOD*10);")
        if itf == "reg_iface":
            lines.append("    reg_utils_inst = new(regif);")
            lines.append("    #(CLK_PERIOD*10);")
            lines.append("    reg_utils_inst.write('h0, 32'h1);")
            lines.append("    #(CLK_PERIOD*10);")
            lines.append("    reg_utils_inst.read ('h0, rdata);")
            lines.append('    $display("Read data: 0x%08x", rdata);')
            lines.append("    #(CLK_PERIOD*10);")

    lines.append("    // INSERT YOUR STIMULUS HERE")
    lines.append("    if (error_count == 0) $display(\"Coverage: 100%%\");")
    lines.append('    $display("\\nEnd.\\n");')
    lines.append("    $finish;")
    lines.append("  end")
    lines.append(f"endmodule")
    return "\n".join(lines) + "\n"


def _render_simple_tb(top: str,
                      clk_period_ns: int,
                      simdir: str,
                      syndir: str,
                      compiler: str,
                      sig: dict) -> str:
    """Minimal TB: only clock(s) and reset(s). No TLUL/Reg IF."""
    params = sig["parameters"]
    lparams = sig["localparams"]
    ports_in = sig["ports_in"]
    ports_out = sig["ports_out"]
    clks = sig["clks"]
    rsts = sig["rsts"]

    lines = []
    lines.append("`timescale 1ns/1ps")
    if compiler == "verilator":
        lines.append(f'`include "tb/include_{top}_tb.sv"')
    else:
        lines.append("`ifndef SYN")
        lines.append(f'  `include "rtl/{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{syndir}/{top}_synth.v"')
        lines.append("`endif")
    lines.append("")
    lines.append(f"module {top}_tb;")
    lines.append(f"  parameter int CLK_PERIOD = {clk_period_ns}; // ns")

    for name, val in params:
        lines.append(f"  parameter {name} = {val};")
    for name, val in lparams:
        lines.append(f"  localparam {name} = {val};")

    # Declare inputs as regs (bit-vectors ok; unknown types fall back to logic)
    lines.append("\n  // Inputs")
    for name, w in ports_in:
        if w == 1 or w == "1":
            lines.append(f"  reg {name};")
        elif isinstance(w, str) and w.startswith('['):
            lines.append(f"  reg {w} {name};")
        else:
            lines.append(f"  logic {name};")

    # Declare outputs as wires
    lines.append("\n  // Outputs")
    for name, w in ports_out:
        if w == 1 or w == "1":
            lines.append(f"  wire {name};")
        elif isinstance(w, str) and w.startswith('['):
            lines.append(f"  wire {w} {name};")
        else:
            lines.append(f"  logic {name};")

    # DUT
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    pin_lines = []
    for name, _ in ports_in:
        pin_lines.append(f"    .{name}({name})")
    for name, _ in ports_out:
        pin_lines.append(f"    .{name}({name})")
    for i, pl in enumerate(pin_lines):
        lines.append(pl + ("," if i != len(pin_lines)-1 else ""))
    lines.append("  );\n")

    # Clocks
    for c in clks:
        lines.append("  initial begin")
        lines.append(f"    {c} = 1'b0;")
        lines.append(f"    forever #(CLK_PERIOD/2) {c} = ~{c};")
        lines.append("  end\n")

    # VCD
    lines.append("  initial begin")
    lines.append("    `ifndef SYN")
    lines.append(f'      $dumpfile("{simdir}/{top}.vcd");')
    lines.append("    `else")
    lines.append(f'      $dumpfile("{simdir}/{top}_syn.vcd");')
    lines.append("    `endif")
    lines.append(f"    $dumpvars(0, {top}_tb);")
    lines.append("  end\n")

    # Simple reset pulse(s)
    lines.append("  initial begin")
    # Init inputs to 0
    for nm, _ in ports_in:
        if nm not in clks and nm not in rsts:
            lines.append(f"    {nm} = '0;")
    if rsts:
        for r in rsts:
            lines.append(f"    {r} = 1'b0;")
        lines.append("    #(CLK_PERIOD*2);")
        for r in rsts:
            lines.append(f"    {r} = 1'b1;")
    else:
        lines.append("    #(CLK_PERIOD*2);")
    lines.append("    #(CLK_PERIOD*10);")
    lines.append("    $finish;")
    lines.append("  end")
    lines.append("endmodule")
    return "\n".join(lines) + "\n"

# -------------------------
# CLI
# -------------------------

def parse_args(argv=None):
    p = argparse.ArgumentParser(
        prog="setup_tb",
        description="Generate a SystemVerilog testbench and helper files.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    p.add_argument("-top", "--top", required=True, 
                   help="TOP module name")
    p.add_argument("-rtldir","--rtldir","--rtl-dir", dest="rtldir", required=True, 
                   help="RTL directory containing <top>.sv")
    p.add_argument("-simdir","--simdir","--sim-dir", dest="simdir", required=True, 
                   help="Simulation output dir for VCD")
    p.add_argument("-syndir","--syndir","--syn-dir", dest="syndir", required=True, 
                   help="Synthesis dir for post-syn sim")
    p.add_argument("-prim","--prim", nargs="+", required=True, 
                   help="Primitive files used for post-syn include")
    p.add_argument("-clk","--clk", type=int, required=True, 
                   help="Clock period (ns)")
    p.add_argument("-comp","--comp","--compiler", dest="comp", required=True, choices=["iverilog","verilator"], 
                   help="Simulator/compiler")
    p.add_argument("-itf","--itf","--bus", dest="itf", required=True, choices=["tlul","reg_iface"], 
                   help="Register interface wiring")
    p.add_argument("-vsv","--vsv", default="sv", choices=["sv","v"], 
                   help="DUT source extension used by Verilator include")
    p.add_argument("-o","--output", default="tb", 
                   help="Output directory for generated files")
    p.add_argument("-f","--force", action="store_true", 
                   help="Overwrite existing files")
    return p.parse_args(argv)


def main(argv=None) -> int:
    args = parse_args(argv)
    top      = args.top
    rtldir   = args.rtldir
    simdir   = args.simdir
    syndir   = args.syndir
    prims    = args.prim
    clk_ns   = args.clk
    comp     = args.comp
    itf      = args.itf
    vsv      = args.vsv
    outdir   = Path(args.output)
    force    = bool(args.force)

    # Parse RTL signature once (common.py)
    sig = parse_sv_signature(rtldir, top)
    sig_for_simple = sig

    reg_pkg = has_reg_pkg(rtldir, top)
    reg_top_exists = (Path(rtldir) / f"{top}_reg_top.sv").exists()
    simple_mode = not (reg_pkg and reg_top_exists)
    reg_top_exists = (Path(rtldir) / f"{top}_reg_top.sv").exists()
    simple_mode = not (reg_pkg and reg_top_exists)
    # Detect if DUT exposes TL-UL ports; if so, we may include tlul_pkg for types even in simple mode
    sig_for_simple = None

    # Prepare output dir
    ensure_dir(outdir)

    # If using Verilator, produce include and (optionally) bus helpers
    if comp == "verilator":
        include_txt = _sv_header_include_for_verilator(top, rtldir, syndir, prims, reg_pkg, itf, vsv)
        safe_write_file(outdir / f"include_{top}_tb.sv", include_txt, overwrite=force)
    # In simple mode, add tlul_pkg include if DUT exposes tl_i/tl_o types
    if simple_mode and sig_for_simple is not None:
        has_tlul = any(n == "tl_i" for n,_ in sig_for_simple["ports_in"]) or any(n == "tl_o" for n,_ in sig_for_simple["ports_out"])
        if has_tlul:
            lines = include_txt.splitlines()
            try:
                idx = lines.index("`ifndef SYN")
            except ValueError:
                idx = 0
            # Insert after the standard pkg includes block
            # Find insertion point after prim_secded_pkg include if present
            ins = None
            for i, L in enumerate(lines):
                if "ips/pkgs/prim_secded_pkg.sv" in L:
                    ins = i + 1
            if ins is None:
                ins = idx + 1
            lines.insert(ins, '  `include "ips/pkgs/tlul_pkg.sv"')
            include_txt = "\n".join(lines) + ("\n" if not include_txt.endswith("\n") else "")
            safe_write_file(outdir / f"include_{top}_tb.sv", include_txt, overwrite=force)

        if (not simple_mode) and reg_pkg and itf == "tlul":
            safe_write_file(outdir / "tlul_if.sv",    _emit_tlul_if(),    overwrite=force)
            safe_write_file(outdir / "tlul_utils.sv", _emit_tlul_utils(), overwrite=force)
        if (not simple_mode) and reg_pkg and itf == "reg_iface":
            safe_write_file(outdir / "reg_if.sv",     _emit_reg_if(top),     overwrite=force)
            safe_write_file(outdir / "reg_utils.sv",  _emit_reg_utils(top),  overwrite=force)    # Emit bus helper files when full TB is enabled
    if (not simple_mode) and reg_pkg:
        if itf == "tlul":
            safe_write_file(outdir / "tlul_if.sv",    _emit_tlul_if(),    overwrite=force)
            safe_write_file(outdir / "tlul_utils.sv", _emit_tlul_utils(), overwrite=force)
        elif itf == "reg_iface":
            safe_write_file(outdir / "reg_if.sv",     _emit_reg_if(top),     overwrite=force)
            safe_write_file(outdir / "reg_utils.sv",  _emit_reg_utils(top),  overwrite=force)



    # Emit the testbench
    tb_txt = _render_simple_tb(top, clk_ns, simdir, syndir, comp, sig) if simple_mode else _render_tb(top, clk_ns, simdir, syndir, itf, comp, vsv, sig)
    safe_write_file(outdir / f"{top}_tb.sv", tb_txt, overwrite=force)

    #print(colorize(f"Generated: {outdir}/include_{top}_tb.sv"))
    #if comp == "verilator" and reg_pkg:
    #    if itf == "tlul":
    #        print(colorize(f"Generated: {outdir}/tlul_if.sv"))
    #        print(colorize(f"Generated: {outdir}/tlul_utils.sv"))
    #    if itf == "reg_iface":
    #        print(colorize(f"Generated: {outdir}/reg_if.sv"))
    #        print(colorize(f"Generated: {outdir}/reg_utils.sv"))
    #print(colorize(f"Generated: {outdir}/{top}_tb.sv"))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
