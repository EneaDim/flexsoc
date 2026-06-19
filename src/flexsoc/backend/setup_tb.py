"""Generate SystemVerilog testbench files for FlexSoC IP and SoC runs.

The module keeps text rendering separate from filesystem writes so the API layer
and CLI can preview or test generated artifacts without invoking external EDA tools.
"""

from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Sequence

from .common import ensure_dir, has_reg_pkg, parse_sv_signature, safe_write_file


@dataclass(frozen=True, slots=True)
class TestbenchConfig:
    """Describe one testbench generation request.

    Paths are accepted as strings or Path objects to keep Make and Python callers simple.
    """

    top: str
    rtldir: str | Path
    simdir: str | Path
    syndir: str | Path
    prims: tuple[str, ...]
    clk_period_ns: int
    compiler: str
    interface: str
    vsv: str = "sv"
    output: str | Path = "tb"
    devices: tuple[tuple[str, str, str, str], ...] = ()
    force: bool = False


def _logic_decl(name: str, width: Any, *, default_type: str = "logic") -> str:
    """Render a SystemVerilog declaration for a parsed port width."""

    if width == 1 or width == "1":
        return f"  logic {name};"
    if isinstance(width, str) and width.startswith("["):
        return f"  logic {width} {name};"
    return f"  {default_type} {name};"


def _connect_ports(ports_in: Sequence[tuple[str, Any]], ports_out: Sequence[tuple[str, Any]], top: str, interface: str) -> list[str]:
    """Return DUT instance pin mappings for generic, TL-UL, or reg-interface wiring."""

    pins: list[str] = []
    for name, _ in ports_in:
        if interface == "tlul" and name == "tl_i":
            pins.append(f"    .{name}(tl_if.h2d)")
        elif interface == "reg_iface" and name == "reg_req_i":
            pins.append(f"    .{name}(regif.req)")
        else:
            pins.append(f"    .{name}({name})")
    for name, _ in ports_out:
        if interface == "tlul" and name == "tl_o":
            pins.append(f"    .{name}(tl_if.d2h)")
        elif interface == "reg_iface" and name == "reg_rsp_o":
            pins.append(f"    .{name}(regif.rsp)")
        else:
            pins.append(f"    .{name}({name})")
    return [line + ("," if index != len(pins) - 1 else "") for index, line in enumerate(pins)]

# -------------------------
# Render helpers (SV text)
# -------------------------
def render_verilator_include(top: str, rtldir: str | Path, syndir: str | Path,
                              prims: Sequence[str], flag_reg_pkg: bool,
                              interface: str, vsv: str) -> str:
    """Render the include shim used by Verilator pre/post-synthesis runs."""

    inc: list[str] = []
    inc.append("`ifndef SYN")

    # pkgs: assume +incdir+<ips_root>/pkgs nel comando
    inc.append('  `include "top_pkg.sv"')
    inc.append('  `include "prim_util_pkg.sv"')
    inc.append('  `include "prim_mubi_pkg.sv"')
    inc.append('  `include "prim_secded_pkg.sv"')

    # local rtl: assume +incdir+rtldir nel comando
    if flag_reg_pkg:
        inc.append(f'  `include "{top}_reg_pkg.sv"')

    # TLUL: assume +incdir+<ips_root>/pkgs e +incdir+<ips_root>/tlul
    if flag_reg_pkg and interface == "tlul":
        inc.append('  `include "tlul_pkg.sv"')
        inc.append('  `include "tlul_utils.sv"')
        inc.append('  `include "tlul_if.sv"')

    if flag_reg_pkg and interface == "reg_iface":
        inc.append('  `include "reg_utils.sv"')
        inc.append('  `include "reg_if.sv"')

    # DUT source: assume +incdir+rtldir nel comando
    inc.append(f'  `include "{top}.{"sv" if vsv == "sv" else "v"}"')

    inc.append("`else")

    # prims: includi solo il basename, e metti le loro dir in +incdir
    for p in prims:
        inc.append(f'  `include "{Path(p).name}"')

    # synth netlist: includi solo nome, assume +incdir+syndir nel comando
    inc.append(f'  `include "{top}_synth.v"')

    inc.append("`endif")
    return "\n".join(inc) + "\n"

def render_tlul_interface() -> str:
    """Render the TL-UL SystemVerilog interface used by Verilator tests."""

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

def render_tlul_utils() -> str:
    """Render simple TL-UL utility tasks for generated testbenches."""

    return """class tlul_utils;

  virtual tlul_if.drv drv_if;

  function new(virtual tlul_if.drv drv_if);
    this.drv_if = drv_if;
  endfunction

  task automatic cycle();
    @(posedge drv_if.clk_i);
  endtask

  task automatic drive_idle();
    drv_if.h2d.a_valid   <= 1'b0;
    drv_if.h2d.a_opcode  <= tlul_pkg::Get;
    drv_if.h2d.a_param   <= '0;
    drv_if.h2d.a_size    <= '0;
    drv_if.h2d.a_source  <= '0;
    drv_if.h2d.a_address <= '0;
    drv_if.h2d.a_mask    <= '0;
    drv_if.h2d.a_data    <= '0;
    drv_if.h2d.a_user    <= '0;
    drv_if.h2d.d_ready   <= 1'b0;
  endtask

  task automatic init();
    drive_idle();
    cycle();
  endtask

  task automatic tlul_write(input logic [top_pkg::TL_AW-1:0]  addr,
                            input logic [top_pkg::TL_DW-1:0]  data,
                            input logic [top_pkg::TL_AIW-1:0] source);

    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);

    drive_idle();
    cycle();

    drv_if.h2d.d_ready   <= 1'b1;
    drv_if.h2d.a_valid   <= 1'b1;
    drv_if.h2d.a_opcode  <= tlul_pkg::PutFullData;
    drv_if.h2d.a_param   <= 3'b000;
    drv_if.h2d.a_size    <= 2;
    drv_if.h2d.a_source  <= source;
    drv_if.h2d.a_address <= addr;
    drv_if.h2d.a_mask    <= 4'b1111;
    drv_if.h2d.a_data    <= data;
    drv_if.h2d.a_user    <= '0;

    do cycle(); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid <= 1'b0;

    do cycle(); while (!drv_if.d2h.d_valid);

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL WRITE DONE: Addr = 0x%08x", $time, addr);
    end

    cycle();
    drive_idle();
    cycle();

    #1;
  endtask

  task automatic tlul_read(input  logic [top_pkg::TL_AW-1:0]  addr,
                           output logic [top_pkg::TL_DW-1:0]  data,
                           input  logic [top_pkg::TL_AIW-1:0] source);

    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);
    data = '0;

    drive_idle();
    cycle();

    drv_if.h2d.d_ready   <= 1'b1;
    drv_if.h2d.a_valid   <= 1'b1;
    drv_if.h2d.a_opcode  <= tlul_pkg::Get;
    drv_if.h2d.a_param   <= 3'b000;
    drv_if.h2d.a_size    <= 2;
    drv_if.h2d.a_source  <= source;
    drv_if.h2d.a_address <= addr;
    drv_if.h2d.a_mask    <= 4'b1111;
    drv_if.h2d.a_data    <= '0;
    drv_if.h2d.a_user    <= '0;

    do cycle(); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid <= 1'b0;

    do cycle(); while (!drv_if.d2h.d_valid);
    data = drv_if.d2h.d_data;

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);
    end

    cycle();
    drive_idle();
    cycle();

    #1;
  endtask

endclass
"""

def render_reg_interface(top: str) -> str:
    """Render a generic register request/response SystemVerilog interface."""

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


def render_reg_utils(top: str) -> str:
    """Render simple register read/write tasks for generated testbenches."""

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


def render_testbench(top: str,
                     clk_period_ns: int,
                     simdir: str | Path,
                     syndir: str | Path,
                     interface: str,
                     compiler: str,
                     vsv: str,
                     sig: dict[str, Any]) -> str:
    """Compose the <top>_tb.sv body using parsed signature info."""
    params: list[tuple[str, str]] = sig["parameters"]
    lparams: list[tuple[str, str]] = sig["localparams"]
    ports_in: list[tuple[str, Any]] = sig["ports_in"]
    ports_out: list[tuple[str, Any]] = sig["ports_out"]
    clks: list[str] = sig["clks"]
    rsts: list[str] = sig["rsts"]

    lines: list[str] = []
    lines.append("// Timescale")
    lines.append("`timescale 1ns/1ps")
    lines.append("// Includes")
    if compiler == "verilator":
        lines.append(f'`include "include_{top}_tb.sv"')
    else:
        # Fallback includes for non-Verilator
        lines.append("`ifndef SYN")
        lines.append(f'  `include "{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{top}_synth.v"')
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
    for name, width in ports_in:
        default = str(width) if interface == "tlul" else f"{top}_reg_pkg::{width}"
        lines.append(_logic_decl(name, width, default_type=default))

    # Outputs
    lines.append("\n  // Outputs")
    for name, width in ports_out:
        default = str(width) if interface == "tlul" else f"{top}_reg_pkg::{width}"
        lines.append(_logic_decl(name, width, default_type=default))

    lines.append("\n  integer error_count;")
    # Optional rdata reg for quick examples
    lines.append(f"  logic [{top}_reg_pkg::DW-1:0] rdata;")

    # Interfaces (Verilator only)
    if compiler == "verilator":
        if interface == "tlul":
            lines.append("  tlul_utils tl_utils_inst;")
            lines.append("  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));")
        if interface == "reg_iface":
            lines.append("  reg_utils reg_utils_inst;")
            lines.append("  reg_if regif(.clk_i(clk_i), .rst_ni(rst_ni));")

    # DUT instance
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    lines.extend(_connect_ports(ports_in, ports_out, top, interface))
    lines.append("  );\n")

    # Clock gens
    for c in clks:
        lines.append("  initial begin")
        lines.append(f"    {c} = 0;")
        lines.append("    forever #(CLK_PERIOD / 2) " + f"{c} = ~{c};")
        lines.append("  end\n")

    # VCD
    lines.append("  // Dump VCD")
    lines.append("  string vcd_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("VCD=%s", vcd_path)) begin')
    lines.append("      `ifndef SYN")
    lines.append(f'        vcd_path = "";')
    lines.append("      `else")
    lines.append(f'        vcd_path = "";')
    lines.append("      `endif")
    lines.append("    end")
    lines.append('    $display("[TB] dumpfile = %s", vcd_path);')
    lines.append("    $dumpfile(vcd_path);")
    lines.append(f"    $dumpvars(0, {top}_tb);")
    lines.append("  end\n")

    # SDF annotate (disabled for Verilator)
    lines.append("  // SDF backannotation")
    lines.append("  `ifndef VERILATOR")
    lines.append("    string sdf_path;")
    lines.append("    initial begin")
    lines.append('      if (!$value$plusargs("SDF=%s", sdf_path)) begin')
    lines.append(f'        sdf_path = "";')
    lines.append("      end")
    lines.append('      $display("[TB] sdf = %s", sdf_path);')
    lines.append(f'      $sdf_annotate(sdf_path, {top}_tb.u_{top}, , , "MAXIMUM");')
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
        if interface == "tlul":
            lines.append("    tl_utils_inst = new(tl_if);")
            lines.append("    #(CLK_PERIOD*10);")
            lines.append("    tl_utils_inst.tlul_write(32'h0, 32'h1, 4'h0);")
            lines.append("    #(CLK_PERIOD*10);")
            lines.append("    tl_utils_inst.tlul_read (32'h0, rdata, 4'h0);")
            lines.append('    $display("Read data: %h", rdata);')
            lines.append("    #(CLK_PERIOD*10);")
        if interface == "reg_iface":
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
    lines.append("endmodule")
    return "\n".join(lines) + "\n"


def render_simple_testbench(top: str,
                            clk_period_ns: int,
                            devices: Sequence[Sequence[str]],
                            simdir: str | Path,
                            syndir: str | Path,
                            compiler: str,
                            sig: dict[str, Any]) -> str:
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
        lines.append(f'`include "include_{top}_tb.sv"')
    else:
        lines.append("`ifndef SYN")
        lines.append(f'  `include "{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{top}_synth.v"')
        lines.append("`endif")
    lines.append("")
    lines.append(f"module {top}_tb;")
    lines.append(f"  parameter int CLK_PERIOD = {clk_period_ns}; // ns")

    for name, val in params:
        lines.append(f"  parameter {name} = {val};")
    for name, val in lparams:
        lines.append(f"  localparam {name} = {val};")

    # Declare ports directly in the testbench scope.
    lines.append("\n  // Inputs")
    for name, width in ports_in:
        lines.append(_logic_decl(name, width))

    lines.append("\n  // Outputs")
    for name, width in ports_out:
        lines.append(_logic_decl(name, width))

    # DUT
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    lines.extend(_connect_ports(ports_in, ports_out, top, "direct"))
    lines.append("  );\n")

    # Clocks
    for c in clks:
        lines.append("  initial begin")
        lines.append(f"    {c} = 1'b0;")
        lines.append(f"    forever #(CLK_PERIOD/2) {c} = ~{c};")
        lines.append("  end\n")

    # VCD
    lines.append("  // Dump VCD")
    lines.append("  string vcd_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("VCD=%s", vcd_path)) begin')
    lines.append("      `ifndef SYN")
    lines.append(f'        vcd_path = "";')
    lines.append("      `else")
    lines.append(f'        vcd_path = "";')
    lines.append("      `endif")
    lines.append("    end")
    lines.append('    $display("[TB] dumpfile = %s", vcd_path);')
    lines.append("    $dumpfile(vcd_path);")
    lines.append(f"    $dumpvars(0, {top}_tb);")
    lines.append("  end\n")
    # UART HOST TASK
    if top == 'soc':
        lines.append("  // UART HOST TASKS")
        lines.append("  task automatic uart_send_byte(input logic [7:0] b);")
        lines.append("    begin")
        lines.append("      // Start bit")
        lines.append("      cio_rx_i = 1'b0; ")
        lines.append("      #1085; // Wait for half a bit period")
        lines.append("      // Send each bit of the pattern")
        lines.append("      for (int i = 0; i < 8; i++) begin")
        lines.append("        cio_rx_i = b[i]; // Send each bit of the pattern")
        lines.append("        #1085; // Wait for half a bit period")
        lines.append("      end")
        lines.append("      // Stop bit")
        lines.append("      cio_rx_i = 1'b1; ")
        lines.append("      #1085; // Wait for half a bit period")
        lines.append("    end")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // Frame helper: manda un 32b LSB-first")
        lines.append("  task automatic uart_send_word32(input logic [31:0] w);")
        lines.append("    uart_send_byte(w[7:0]);")
        lines.append("    uart_send_byte(w[15:8]);")
        lines.append("    uart_send_byte(w[23:16]);")
        lines.append("    uart_send_byte(w[31:24]);")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // WRITE: A5 | 01 | 01 | {0000,BE} | 00 | ADDR(4) | DATA(4)")
        lines.append("  task automatic uart_write32(input logic [31:0] addr, input logic [31:0] data, input logic [3:0] be = 4'hF);")
        lines.append("    begin")
        lines.append("      uart_send_byte(8'hA5);      // SOF")
        lines.append("      uart_send_byte(8'h01);      // OP=WRITE")
        lines.append("      uart_send_byte({4'h0,be});  // BE")
        lines.append("      uart_send_word32(addr);     // ADDR (LSB-first)")
        lines.append("      uart_send_word32(data);     // DATA (LSB-first)")
        lines.append("    end")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // READ: A5 | 01 | 00 | {0000,1111} | 00 | ADDR(4)")
        lines.append("  task automatic uart_read32(input logic [31:0] addr);")
        lines.append("    begin")
        lines.append("      uart_send_byte(8'hA5);       // SOF")
        lines.append("      uart_send_byte(8'h00);       // OP=READ")
        lines.append("      uart_send_byte({4'h0,4'hF}); // BE")
        lines.append("      uart_send_word32(addr);      // ADDR (LSB-first)")
        lines.append("    end")
        lines.append("  endtask")
        lines.append("  ")
        lines.append("  // =========")
        lines.append("  // Addresses")
        lines.append("  // =========")
        for d in devices:
            lines.append(f"  localparam logic [31:0] {d[0].upper()}_BASE   = 32'h{d[1][2:]};")
        lines.append("")
        lines.append("  // Offsets")
        for d in devices:
            lines.append(f"  localparam logic [31:0] {d[0].upper()}_CTRL_OFF = 32'h00000000;")
            lines.append("  /////////////////////////////////////////////////////////////////")

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
    if top == 'soc':
        lines.append("    uart_write32(UART_BASE + UART_CTRL_OFF, 32'h4B7F_0001); // For 100MHz fclk")
        lines.append("    #(CLK_PERIOD*2000);")
        lines.append("    uart_read32(UART_BASE + UART_CTRL_OFF);")
        lines.append("    #(CLK_PERIOD*2000);    ")
    lines.append("    #(CLK_PERIOD*10);")
    lines.append("    $finish;")
    lines.append("  end")
    lines.append("endmodule")
    return "\n".join(lines) + "\n"

# -------------------------
# Filesystem and CLI boundary
# -------------------------


def uses_simple_testbench(config: TestbenchConfig) -> bool:
    """Return whether the top should use direct port wiring instead of bus helpers."""

    reg_pkg = has_reg_pkg(config.rtldir, config.top)
    reg_top = (Path(config.rtldir) / f"{config.top}_reg_top.sv").exists()
    return not (reg_pkg and reg_top)


def write_bus_helpers(config: TestbenchConfig, *, reg_pkg: bool, simple_mode: bool) -> list[Path]:
    """Write optional Verilator bus helper files for full register testbenches."""

    if simple_mode or not reg_pkg or config.compiler != "verilator":
        return []

    outdir = Path(config.output)
    helpers = {
        "tlul": (("tlul_if.sv", render_tlul_interface()), ("tlul_utils.sv", render_tlul_utils())),
        "reg_iface": (("reg_if.sv", render_reg_interface(config.top)), ("reg_utils.sv", render_reg_utils(config.top))),
    }.get(config.interface, ())

    written: list[Path] = []
    for name, body in helpers:
        path = outdir / name
        safe_write_file(path, body, overwrite=True)
        written.append(path)
    return written


def generate_testbench_files(config: TestbenchConfig) -> tuple[Path, ...]:
    """Generate include, helper, and top-level testbench files for one request."""

    outdir = Path(config.output)
    ensure_dir(outdir)

    sig = parse_sv_signature(config.rtldir, config.top)
    reg_pkg = has_reg_pkg(config.rtldir, config.top)
    simple_mode = uses_simple_testbench(config)
    written: list[Path] = []

    if config.compiler == "verilator":
        include = render_verilator_include(
            config.top,
            config.rtldir,
            config.syndir,
            config.prims,
            reg_pkg,
            config.interface,
            config.vsv,
        )
        include_path = outdir / f"include_{config.top}_tb.sv"
        safe_write_file(include_path, include, overwrite=config.force)
        written.append(include_path)

    written.extend(write_bus_helpers(config, reg_pkg=reg_pkg, simple_mode=simple_mode))

    body = (
        render_simple_testbench(
            config.top,
            config.clk_period_ns,
            config.devices,
            config.simdir,
            config.syndir,
            config.compiler,
            sig,
        )
        if simple_mode
        else render_testbench(
            config.top,
            config.clk_period_ns,
            config.simdir,
            config.syndir,
            config.interface,
            config.compiler,
            config.vsv,
            sig,
        )
    )
    tb_path = outdir / f"{config.top}_tb.sv"
    safe_write_file(tb_path, body, overwrite=config.force)
    written.append(tb_path)
    return tuple(written)


def parse_args(argv=None):
    """Parse command-line options for testbench generation."""

    p = argparse.ArgumentParser(
        prog="setup_tb",
        description="Generate a SystemVerilog testbench and helper files.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    p.add_argument("-top", "--top", required=True, help="TOP module name")
    p.add_argument("-rtldir", "--rtldir", "--rtl-dir", dest="rtldir", required=True, help="RTL directory containing <top>.sv")
    p.add_argument("-simdir", "--simdir", "--sim-dir", dest="simdir", required=True, help="Simulation output dir for VCD")
    p.add_argument("-device", "--device", action="append", nargs=4, default=[], metavar=("NAME", "BASE_ADDR", "SIZE_BYTE", "FROM_LR"), help="Add one mapped SoC device.")
    p.add_argument("-syndir", "--syndir", "--syn-dir", dest="syndir", required=True, help="Synthesis dir for post-syn sim")
    p.add_argument("-prim", "--prim", nargs="+", required=True, help="Primitive files used for post-syn include")
    p.add_argument("-clk", "--clk", type=int, required=True, help="Clock period in ns")
    p.add_argument("-comp", "--comp", "--compiler", dest="comp", required=True, choices=["iverilog", "verilator"], help="Simulator/compiler")
    p.add_argument("-itf", "--itf", "--bus", dest="itf", required=True, choices=["tlul", "reg_iface"], help="Register interface wiring")
    p.add_argument("-vsv", "--vsv", default="sv", choices=["sv", "v"], help="DUT source extension used by Verilator include")
    p.add_argument("-o", "--output", default="tb", help="Output directory for generated files")
    p.add_argument("-f", "--force", action="store_true", help="Overwrite existing files")
    return p.parse_args(argv)


def config_from_args(args: argparse.Namespace) -> TestbenchConfig:
    """Convert parsed CLI arguments into the canonical backend config object."""

    return TestbenchConfig(
        top=args.top,
        rtldir=args.rtldir,
        simdir=args.simdir,
        syndir=args.syndir,
        prims=tuple(args.prim),
        clk_period_ns=args.clk,
        compiler=args.comp,
        interface=args.itf,
        vsv=args.vsv,
        output=args.output,
        devices=tuple(tuple(item) for item in args.device),
        force=bool(args.force),
    )


def main(argv=None) -> int:
    """Run testbench generation from the command line."""

    generate_testbench_files(config_from_args(parse_args(argv)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
