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
#!/usr/bin/env python3
# Apache-2.0
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys, os, re
from pathlib import Path
import argparse
from textwrap import dedent

parser = argparse.ArgumentParser(description="Generate a cocotb testbench skeleton")
parser.add_argument("--top","-top", required=True, help="Top module name (without .sv)")
parser.add_argument("--itf","-itf", required=True, choices=["reg_iface","tlul"],
                    help="Register interface: reg_iface or tlul")
parser.add_argument("--output","-o", default="tb", help="Output folder (default: tb)")
parser.add_argument("--rtl-dir", default="rtl", help="RTL directory to scan (recursive)")
parser.add_argument("--sim", choices=["verilator","icarus","questa","vcs","xcelium"],
                    default="verilator", help="Simulator (default: verilator)")
parser.add_argument("--clk", default="clk_i", help="Clock signal name (default: clk_i)")
parser.add_argument("--rst", default="rst_ni", help="Reset signal name (default: rst_ni)")
parser.add_argument("--rst-active", choices=["low","high"], default="low",
                    help="Reset polarity (default: low)")
parser.add_argument("--period-ns", type=float, default=10.0,
                    help="Clock period ns (default: 10)")
parser.add_argument("--nbit", type=int, default=32, help="Default NBIT for utils/tests")
parser.add_argument("--n-op", type=int, default=10, help="Loop iterations")
parser.add_argument("--include-dirs", nargs="*", default=[], help="Extra include dirs")
parser.add_argument("--extra-src", nargs="*", default=[], help="Extra HDL sources")
parser.add_argument("--tlul-wrap", choices=["auto","on","off"], default="auto",
                    help="Auto-genera wrapper TL-UL: auto/on/off (default: auto)")
args = parser.parse_args()

TOP=args.top; ITF=args.itf; OUT=Path(args.output); RTL_DIR=Path(args.rtl_dir)
SIM=args.sim; CLK=args.clk; RST=args.rst; RST_ACTIVE=args.rst_active
PERIOD=args.period_ns; NBIT=args.nbit; N_OP=args.n_op
INC_DIRS=[Path(p) for p in args.include_dirs]; EXTRA_SRC=[Path(p) for p in args.extra_src]
TL_WRAP=args.tlul_wrap

OUT.mkdir(parents=True, exist_ok=True)
(OUT/"drivers").mkdir(parents=True, exist_ok=True)

def is_hdl(p:Path)->bool: return p.suffix.lower() in {".sv",".v",".vh",".svh"}

# --------- Scansione RTL + extra -------------
rtl_files=[]
if RTL_DIR.exists():
    for p in RTL_DIR.rglob("*"):
        if p.is_file() and is_hdl(p):
            if p.stem.lower().endswith("_tb") or p.stem.lower().endswith("_tb_top"):
                continue
            rtl_files.append(p.resolve())
for p in EXTRA_SRC:
    pp = Path(p)
    if pp.exists() and is_hdl(pp):
        rtl_files.append(pp.resolve())
rtl_files = sorted(set(rtl_files))

# --------- Parser semplicissimo dell’header del TOP per capire le porte TL-UL ---------
def read_top_path():
    # prova in rtl_dir
    cand = RTL_DIR / f"{TOP}.sv"
    if cand.exists(): return cand
    # scan alternativa tra i file
    for f in rtl_files:
        if f.stem == TOP: return f
    return None

TOP_PATH = read_top_path()

def parse_top_ports(top_path: Path):
    txt = top_path.read_text()
    # ruba il blocco module (...) ;
    m = re.search(rf"module\s+{re.escape(TOP)}\s*\((.*?)\);\s", txt, flags=re.S|re.M)
    if not m:
        return []
    ports_blob = m.group(1)
    # rimuovi commenti singola linea
    ports_blob = re.sub(r"//.*?$", "", ports_blob, flags=re.M)
    # separa su virgole tenendo gli a capo
    chunks = [c.strip() for c in ports_blob.split(",") if c.strip()]
    ports=[]
    for c in chunks:
        # linee tipo: input  tlul_pkg::tl_h2d_t tl_i
        #             output logic [31:0] foo
        m2 = re.match(r"(input|output|inout)\s+(.+?)\s+([A-Za-z_][A-Za-z0-9_$]*)\s*$", c)
        if not m2: continue
        direction, decl, name = m2.groups()
        ports.append({"dir":direction, "decl":decl.strip(), "name":name})
    return ports

ports = []
if TOP_PATH and ITF=="tlul":
    try:
        ports = parse_top_ports(TOP_PATH)
    except Exception:
        ports = []

# Heuristica: esistono porte tl_i / tl_o (struct)?
has_tl_struct = any(p["name"]=="tl_i" for p in ports) and any(p["name"]=="tl_o" for p in ports)
# Decide se generare il wrapper
GEN_WRAP = (ITF=="tlul") and (TL_WRAP in ("on","auto") and has_tl_struct)

# --------- Genera Makefile ----------
inc_flags=[]
for d in INC_DIRS+[RTL_DIR]:
    if not d or not d.exists(): continue
    if SIM=="verilator": inc_flags.append(f"-I{d.resolve()}")
    elif SIM in {"questa","vcs","xcelium"}: inc_flags.append(f"+incdir+{d.resolve()}")
    elif SIM=="icarus": inc_flags.append(f"-I{d.resolve()}")
EXTRA_ARGS=" ".join(inc_flags)

DISCOVERED=""
for src in rtl_files:
    DISCOVERED += f"VERILOG_SOURCES += $(PWD)/{os.path.relpath(src, OUT.resolve())}\n"

TOPLEVEL = f"{TOP}_cocotb_wrap" if GEN_WRAP else TOP
print(TOP)

mk = dedent(f"""\
# Auto-generated Makefile
SIM ?= {SIM}
TOPLEVEL_LANG = verilog
PWD = $(shell pwd)

# Sorgenti fissi del progetto (se li hai già nel repo)
VERILOG_SOURCES := $(PWD)/../ips/pkgs/top_pkg.sv
VERILOG_SOURCES += $(PWD)/../ips/pkgs/prim_assert.sv
VERILOG_SOURCES += $(PWD)/../ips/pkgs/prim_subreg_pkg.sv
VERILOG_SOURCES += $(PWD)/../ips/pkgs/prim_util_pkg.sv
VERILOG_SOURCES += $(PWD)/../ips/pkgs/prim_count_pkg.sv
VERILOG_SOURCES += $(PWD)/../ips/pkgs/prim_mubi_pkg.sv
VERILOG_SOURCES += $(PWD)/../ips/pkgs/prim_secded_pkg.sv
VERILOG_SOURCES += $(PWD)/../ips/pkgs/tlul_pkg.sv
VERILOG_SOURCES += $(PWD)/../rtl/{TOP}_reg_pkg.sv
VERILOG_SOURCES += $(PWD)/../rtl/{TOP}_reg_top.sv
VERILOG_SOURCES += $(PWD)/../rtl/{TOP}_core.sv
VERILOG_SOURCES += $(PWD)/../rtl/{TOP}.sv
{f"VERILOG_SOURCES += $(PWD)/../rtl/{TOP}_cocotb_wrap.sv" if GEN_WRAP else ""}

TOPLEVEL = {TOPLEVEL}
MODULE = {TOP}_tb

# Parametri testbench
export ITF ?= {ITF}
export NBIT ?= {NBIT}
export N_OP ?= {N_OP}
export CLK_PERIOD_NS ?= {PERIOD}
export TB_CLK ?= {CLK}
export TB_RST ?= {RST}
export TB_RST_ACTIVE ?= {RST_ACTIVE}
export TB_TL_A_PREFIX ?= tl_i
export TB_TL_D_PREFIX ?= tl_o
export TB_TL_SCOPE ?=

EXTRA_ARGS ?= {EXTRA_ARGS} {EXTRA_ARGS[:-3]}ips/pkgs {EXTRA_ARGS[:-3]}ips/prim

ifeq ($(SIM),verilator)
  VERILATOR_ARGS += $(EXTRA_ARGS)
endif
ifeq ($(SIM),icarus)
  IVERILOG_ARGS  += $(EXTRA_ARGS)
endif

include $(shell cocotb-config --makefiles)/Makefile.sim
""")
(OUT/"Makefile").write_text(mk)

# --------- utils.py ----------
(OUT/"utils.py").write_text(dedent("""\
import random, math
def rand_bin_values(nbit:int):
    a = random.randint(0, (1<<nbit)-1)
    b = random.randint(0, (1<<nbit)-1)
    return a, b
"""))
(OUT/"__init__.py").write_text("")

# --------- driver reg_iface ----------
(OUT/"drivers"/"driver_reg_iface.py").write_text(dedent("""\
from cocotb.triggers import RisingEdge

class RegIFDriver:
    def __init__(self, dut, clk_name="clk_i", rst_name="rst_ni", req_base=None, rsp_base=None):
        self.dut=dut
        self.clk=getattr(dut, clk_name)
        self.rst=getattr(dut, rst_name)
        self.req = getattr(dut, req_base, None) if req_base else \
                   getattr(dut, "reg_req_i", None) or getattr(dut, "reg_req", None)
        self.rsp = getattr(dut, rsp_base, None) if rsp_base else \
                   getattr(dut, "reg_rsp_o", None) or getattr(dut, "reg_rsp", None)
        self.struct = self.req is not None and hasattr(self.req, "valid") and hasattr(self.rsp, "ready")
        if not self.struct:
            try:
                self.req_valid = getattr(dut, "reg_req_valid")
                self.req_write = getattr(dut, "reg_req_write")
                self.req_addr  = getattr(dut, "reg_req_addr")
                self.req_wdata = getattr(dut, "reg_req_wdata")
                self.req_wstrb = getattr(dut, "reg_req_wstrb")
                self.rsp_rdata = getattr(dut, "reg_rsp_rdata")
                self.rsp_error = getattr(dut, "reg_rsp_error")
                self.rsp_ready = getattr(dut, "reg_rsp_ready")
            except AttributeError as e:
                raise RuntimeError(f"[RegIFDriver] Segnali reg_if non trovati: {e}")

    async def reset_idle(self):
        if self.struct:
            self.req.valid.value = 0; self.req.write.value = 0
            self.req.addr.value  = 0; self.req.wdata.value = 0; self.req.wstrb.value = 0
        else:
            self.req_valid.value = 0; self.req_write.value = 0
            self.req_addr.value  = 0; self.req_wdata.value = 0; self.req_wstrb.value = 0
        await RisingEdge(self.clk)

    async def write32(self, addr:int, data:int, wstrb:int=0xF):
        if self.struct:
            self.req.addr.value  = addr; self.req.wdata.value = data
            self.req.wstrb.value = wstrb; self.req.write.value = 1; self.req.valid.value = 1
        else:
            self.req_addr.value  = addr; self.req_wdata.value = data
            self.req_wstrb.value = wstrb; self.req_write.value = 1; self.req_valid.value = 1
        while True:
            await RisingEdge(self.clk)
            ready = self.rsp.ready.value.integer if self.struct else self.rsp_ready.value.integer
            if ready: break
        if self.struct: self.req.valid.value = 0; self.req.write.value = 0
        else:           self.req_valid.value = 0; self.req_write.value = 0
        await RisingEdge(self.clk)

    async def read32(self, addr:int) -> int:
        if self.struct:
            self.req.addr.value  = addr; self.req.wdata.value = 0
            self.req.wstrb.value = 0;    self.req.write.value = 0; self.req.valid.value = 1
        else:
            self.req_addr.value  = addr; self.req_wdata.value = 0
            self.req_wstrb.value = 0;    self.req_write.value = 0; self.req_valid.value = 1
        data=0
        while True:
            await RisingEdge(self.clk)
            ready = self.rsp.ready.value.integer if self.struct else self.rsp_ready.value.integer
            if ready:
                data = (self.rsp.rdata.value.integer if self.struct else self.rsp_rdata.value.integer)
                break
        if (self.rsp.error.value.integer if self.struct else self.rsp_error.value.integer):
            raise RuntimeError("[RegIFDriver] Read error")
        if self.struct: self.req.valid.value = 0
        else:           self.req_valid.value = 0
        await RisingEdge(self.clk)
        return data
"""))

# --------- driver tlul (flat + struct + scope) ----------
(OUT/"drivers"/"driver_tlul.py").write_text(dedent("""\
import os
from cocotb.triggers import RisingEdge

# TL-UL UL subset
TL_A_PUT_FULL = 0
TL_A_GET      = 4
TL_D_ACCESS_ACK      = 0
TL_D_ACCESS_ACK_DATA = 1

def _get_attr(obj, name):
    try: return getattr(obj, name)
    except AttributeError: return None

def _descend(scope_root, dotted):
    node = scope_root
    if not dotted: return node
    for part in dotted.split("."):
        node = _get_attr(node, part)
        if node is None: return None
    return node

def _candidates(prefix, suffix):
    if prefix == "": return [suffix]
    return [f"{prefix}_{suffix}", f"{prefix}__{suffix}"]

def _find_many_flat(root, prefix, mapping):
    found = {}
    for key, sfx in mapping.items():
        h = None
        for cand in _candidates(prefix, sfx):
            h = _get_attr(root, cand)
            if h is not None: break
        if h is None:
            return None
        found[key] = h
    return found

def _autodetect_prefix(root, want_suffix):
    for h in root:
        name = getattr(h, "_name", "")
        if name.endswith(want_suffix):
            idx = name.rfind(want_suffix)
            prefix = name[:max(0, idx-1)]
            if prefix.endswith("_"): prefix = prefix[:-1]
            return prefix
    return None

class TLULDriver:
    def __init__(self, dut, clk_name="clk_i", rst_name="rst_ni",
                 a_prefix=None, d_prefix=None, scope=None):
        self.dut = dut
        self.clk = getattr(dut, clk_name)
        self.rst = getattr(dut, rst_name)

        scope = scope or os.getenv("TB_TL_SCOPE", "")
        root  = _descend(dut, scope)
        if root is None:
            raise RuntimeError(f"[TLULDriver] TB_TL_SCOPE='{scope}' non trovato")

        a_prefix = a_prefix if a_prefix is not None else os.getenv("TB_TL_A_PREFIX", "tl_i")
        d_prefix = d_prefix if d_prefix is not None else os.getenv("TB_TL_D_PREFIX", "tl_o")

        a_map = {"a_valid":"a_valid","a_ready":"a_ready","a_opcode":"a_opcode","a_param":"a_param",
                 "a_size":"a_size","a_source":"a_source","a_address":"a_address","a_mask":"a_mask",
                 "a_data":"a_data","d_ready":"d_ready"}
        d_map = {"d_valid":"d_valid","d_opcode":"d_opcode","d_data":"d_data","d_error":"d_error"}

        # (A) FLAT
        a_handles = _find_many_flat(root, a_prefix, a_map)
        d_handles = _find_many_flat(root, d_prefix, d_map)

        # (B) STRUCT FIELDS direttamente sotto tl_i/tl_o
        struct_mode = False
        if a_handles is None or d_handles is None:
            tli = _get_attr(root, "tl_i")
            tlo = _get_attr(root, "tl_o")
            if tli is not None and tlo is not None:
                need_a = ["a_valid","a_opcode","a_param","a_size","a_source","a_address","a_mask","a_data","d_ready"]
                need_d = ["a_ready","d_valid","d_opcode","d_data","d_error"]
                if all(_get_attr(tli, n) is not None for n in need_a) and \
                   all(_get_attr(tlo, n) is not None for n in need_d):
                    struct_mode = True
                    a_handles = { n:_get_attr(tli,n) for n in need_a }
                    d_handles = { n:_get_attr(tlo,n) for n in ["a_ready","d_valid","d_opcode","d_data","d_error"] }

        # (C) auto-detect prefissi FLAT se serve
        if not struct_mode and (a_handles is None or d_handles is None):
            if a_handles is None:
                auto_a = _autodetect_prefix(root, "a_valid")
                if auto_a:
                    a_prefix = auto_a; a_handles = _find_many_flat(root, a_prefix, a_map)
            if d_handles is None:
                auto_d = _autodetect_prefix(root, "d_valid")
                if auto_d:
                    d_prefix = auto_d; d_handles = _find_many_flat(root, d_prefix, d_map)

        if (not struct_mode) and (a_handles is None or d_handles is None):
            child_names = [getattr(h, "_name", "") for h in root]
            hints = [n for n in child_names if ("tl" in n or "_a_" in n or "_d_" in n or n in ("tl_i","tl_o"))]
            raise RuntimeError(f"[TLULDriver] Segnali TL-UL mancanti. hints={hints}")

        self.struct_mode = struct_mode
        if struct_mode:
            self.a_valid   = a_handles["a_valid"]
            self.a_ready   = d_handles["a_ready"]     # a_ready è su tl_o
            self.a_opcode  = a_handles["a_opcode"]
            self.a_param   = a_handles["a_param"]
            self.a_size    = a_handles["a_size"]
            self.a_source  = a_handles["a_source"]
            self.a_address = a_handles["a_address"]
            self.a_mask    = a_handles["a_mask"]
            self.a_data    = a_handles["a_data"]
            self.d_ready   = a_handles["d_ready"]
            self.d_valid   = d_handles["d_valid"]
            self.d_opcode  = d_handles["d_opcode"]
            self.d_data    = d_handles["d_data"]
            self.d_error   = d_handles["d_error"]
        else:
            self.a_valid   = a_handles["a_valid"];  self.a_ready = a_handles["a_ready"]
            self.a_opcode  = a_handles["a_opcode"]; self.a_param = a_handles["a_param"]
            self.a_size    = a_handles["a_size"];   self.a_source= a_handles["a_source"]
            self.a_address = a_handles["a_address"];self.a_mask  = a_handles["a_mask"]
            self.a_data    = a_handles["a_data"];   self.d_ready = a_handles["d_ready"]
            self.d_valid   = d_handles["d_valid"];  self.d_opcode= d_handles["d_opcode"]
            self.d_data    = d_handles["d_data"];   self.d_error = d_handles["d_error"]

    async def _idle(self):
        self.a_valid.value = 0; self.a_opcode.value=0; self.a_param.value=0
        self.a_size.value=2; self.a_source.value=0; self.a_address.value=0
        self.a_mask.value=0; self.a_data.value=0; self.d_ready.value=1
        await RisingEdge(self.clk)

    async def write32(self, addr:int, data:int, mask:int=0xF):
        await self._do_tx(addr, data, mask, TL_A_PUT_FULL)

    async def read32(self, addr:int) -> int:
        return await self._do_tx(addr, 0, 0x0, TL_A_GET)

    async def _do_tx(self, addr:int, data:int, mask:int, opcode:int) -> int:
        self.a_address.value = addr; self.a_data.value = data; self.a_mask.value = mask
        self.a_param.value = 0; self.a_size.value = 2; self.a_source.value = 0
        self.a_opcode.value = opcode; self.a_valid.value = 1
        while not int(self.a_ready.value):
            await RisingEdge(self.clk)
        self.a_valid.value = 0
        data_out=0
        while True:
            await RisingEdge(self.clk)
            if int(self.d_valid.value):
                if opcode==TL_A_GET and int(self.d_opcode.value)==TL_D_ACCESS_ACK_DATA:
                    data_out = int(self.d_data.value)
                elif opcode==TL_A_PUT_FULL and int(self.d_opcode.value) in (TL_D_ACCESS_ACK, TL_D_ACCESS_ACK_DATA):
                    pass
                if int(self.d_error.value):
                    raise RuntimeError("[TLULDriver] D error")
                break
        return data_out
"""))

# --------- test template ----------
(OUT/f"{TOP}_tb.py").write_text(dedent(f"""\
# Auto-generated cocotb test for {TOP}
import os
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import utils

ITF = os.getenv("ITF","{ITF}")
CLK_PERIOD_NS = float(os.getenv("CLK_PERIOD_NS","{PERIOD}"))
TB_CLK = os.getenv("TB_CLK","{CLK}")
TB_RST = os.getenv("TB_RST","{RST}")
TB_RST_ACTIVE = os.getenv("TB_RST_ACTIVE","{RST_ACTIVE}")
N_OP = int(os.getenv("N_OP","{N_OP}"))
NBIT = int(os.getenv("NBIT","{NBIT}"))

if ITF == "reg_iface":
    from drivers.driver_reg_iface import RegIFDriver as BusDriver
elif ITF == "tlul":
    from drivers.driver_tlul import TLULDriver as BusDriver
else:
    raise RuntimeError(f"Unsupported ITF: {{ITF}}")

async def reset(dut, cycles:int=2):
    clk = getattr(dut, TB_CLK)
    rst = getattr(dut, TB_RST)
    active = 0 if TB_RST_ACTIVE == "low" else 1
    inactive = 1 - active
    rst.value = active
    for _ in range(cycles):
        await RisingEdge(clk)
    rst.value = inactive
    await RisingEdge(clk)

@cocotb.test()
async def tb_{TOP}(dut):
    clk = getattr(dut, TB_CLK)
    cocotb.start_soon(Clock(clk, CLK_PERIOD_NS, units="ns").start())
    await reset(dut)

    if ITF == "reg_iface":
        bus = BusDriver(dut, clk_name=TB_CLK, rst_name=TB_RST)
        await bus.reset_idle()
        await bus.write32(0x0, 0x1, 0xF)
        rd = await bus.read32(0x0)
        dut._log.info(f"REG_IFACE read @0x0 = 0x{{rd:08x}}")
    else:
        # TL-UL: nessuno scope/prefisso richiesto se il wrapper è generato; altrimenti autodetect
        bus = BusDriver(dut, clk_name=TB_CLK, rst_name=TB_RST)
        await bus._idle()
        await bus.write32(0x0, 0x1, 0xF)
        rd = await bus.read32(0x0)
        dut._log.info(f"TLUL read @0x0 = 0x{{rd:08x}}")

    for i in range(N_OP):
        a,b = utils.rand_bin_values(NBIT)
        _ = a ^ b
        await RisingEdge(clk)
"""))

# --------- wrapper SV (se richiesto) ----------
if GEN_WRAP:
    # Ricrea porte (tutte tranne tl_i/tl_o) identiche al DUT
    other_ports = [p for p in ports if p["name"] not in ("tl_i","tl_o")]
    # Costruisci elenco porte wrapper
    def port_decl(p):
        # manteniamo la dichiarazione così com'è
        return f'  {p["dir"]} {p["decl"]} {p["name"]}'
    other_port_lines = "\n".join(port_decl(p)+"," for p in other_ports)  # virgole, ultime le TL

    wrap = dedent(f"""\
    // Auto-generated TL-UL wrapper for {TOP}
    `timescale 1ns/1ps
    module {TOP}_cocotb_wrap
    (
      input  logic        {CLK},
      input  logic        {RST},
    {other_port_lines}
      // TL-UL host->device (A + d_ready)
      input  logic        tl_i_a_valid,
      input  logic [2:0]  tl_i_a_opcode,
      input  logic [2:0]  tl_i_a_param,
      input  logic [2:0]  tl_i_a_size,
      input  logic [0:0]  tl_i_a_source,
      input  logic [31:0] tl_i_a_address,
      input  logic [3:0]  tl_i_a_mask,
      input  logic [31:0] tl_i_a_data,
      input  logic        tl_i_d_ready,
      // TL-UL device->host (a_ready + D)
      output logic        tl_o_a_ready,
      output logic        tl_o_d_valid,
      output logic [2:0]  tl_o_d_opcode,
      output logic [31:0] tl_o_d_data,
      output logic        tl_o_d_error
    );
      import tlul_pkg::*;
      tl_h2d_t tl_i_s;
      tl_d2h_t tl_o_s;

      // Flatten -> struct
      assign tl_i_s.a_valid   = tl_i_a_valid;
      assign tl_i_s.a_opcode  = tl_i_a_opcode;
      assign tl_i_s.a_param   = tl_i_a_param;
      assign tl_i_s.a_size    = tl_i_a_size;
      assign tl_i_s.a_source  = tl_i_a_source;
      assign tl_i_s.a_address = tl_i_a_address;
      assign tl_i_s.a_mask    = tl_i_a_mask;
      assign tl_i_s.a_data    = tl_i_a_data;
      assign tl_i_s.d_ready   = tl_i_d_ready;

      // Struct -> flatten
      assign tl_o_a_ready = tl_o_s.a_ready;
      assign tl_o_d_valid = tl_o_s.d_valid;
      assign tl_o_d_opcode= tl_o_s.d_opcode;
      assign tl_o_d_data  = tl_o_s.d_data;
      assign tl_o_d_error = tl_o_s.d_error;

      // DUT con .*, più override esplicito delle TL
      {TOP} u_dut (
        .{CLK}({CLK}),
        .{RST}({RST}),
    """)
    # connessioni pass-through per tutte le altre porte (tranne tl_i/tl_o)
    for p in other_ports:
        wrap += f"    .{p['name']}({p['name']}),\n"
    wrap += dedent("""\
        .tl_i(tl_i_s),
        .tl_o(tl_o_s)
      );
    endmodule
    """)
    (RTL_DIR/f"{TOP}_cocotb_wrap.sv").write_text(wrap)

print(f"Generated in: {OUT.resolve()}")
print("- Makefile")
print(f"- {TOP}_tb.py")
print("- utils.py")
print("- drivers/driver_reg_iface.py")
print("- drivers/driver_tlul.py")
if GEN_WRAP:
    print(f"- Wrapper: {RTL_DIR}/{TOP}_cocotb_wrap.sv (TOPLEVEL={TOP}_cocotb_wrap)")

