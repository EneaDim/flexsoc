#!/usr/bin/env python3
# Copyright 2025
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

r"""
\file setup_cocotb.py
\brief Generate a cocotb testbench skeleton and Makefile whose VERILOG_SOURCES
       mirrors rtl/rtl_list.f. The file list is computed by reusing the
       IP-detection logic from common.py (packages always included,
       prim/prim_opentitan/tlul IPs included only if used, and TOP-tail).

Key features:
- Reuses common.build_ordered_sources to create rtl/rtl_list.f
- Emits tb/cocotb/Makefile with VERILOG_SOURCES := \ matching rtl_list.f
- Generates utils.py, drivers, a smoke test, and a TL-UL wrapper
- Wrapper uses explicit clk/rst/tl_i/tl_o plus '.*' to avoid PINMISSING
"""

from __future__ import annotations

import argparse
import os
import re
from pathlib import Path
from textwrap import dedent
from typing import Iterable, List
from common import build_ordered_sources, makefile_block_from_paths

# -----------------------------------------------------------------------------
# CLI
# -----------------------------------------------------------------------------
def parse_args():
    ap = argparse.ArgumentParser(description="Generate cocotb skeleton + Makefile from rtl/ scan")
    ap.add_argument("--top","-top", required=True, help="Top module name (without .sv)")
    ap.add_argument("--itf","-itf", required=True, choices=["reg_iface","tlul"],
                    help="Register interface: reg_iface or tlul")
    ap.add_argument("--output","-o", default="tb/cocotb", help="Output folder (default: tb/cocotb)")
    ap.add_argument("--vsv", choices=["sv","v"], default="sv", help="SV/V flow (default: sv)")
    ap.add_argument("--rtl-dir", default="rtl", help="RTL directory (recursive)")
    ap.add_argument("--ips-root", default="ips", help="IP root (default: ips)")
    ap.add_argument("--sim", choices=["verilator","icarus","questa","vcs","xcelium"],
                    default="verilator", help="Simulator (default: verilator)")
    ap.add_argument("--clk", default="clk_i", help="Clock signal name (default: clk_i)")
    ap.add_argument("--rst", default="rst_ni", help="Reset signal name (default: rst_ni)")
    ap.add_argument("--rst-active", choices=["low","high"], default="low",
                    help="Reset polarity (default: low)")
    ap.add_argument("--period-ns", type=float, default=10.0,
                    help="Clock period ns (default: 10)")
    ap.add_argument("--nbit", type=int, default=32, help="Default NBIT")
    ap.add_argument("--n-op", type=int, default=10, help="Loop iterations")
    ap.add_argument("--include-dirs", nargs="*", default=[], help="Extra include dirs")
    ap.add_argument("--extra-src", nargs="*", default=[], help="Extra HDL sources")
    return ap.parse_args()

# -----------------------------------------------------------------------------
# Simple TOP header parser (for optional wrapper)
# -----------------------------------------------------------------------------
def read_top_path(rtl_dir: Path, top: str) -> Path | None:
    cand = rtl_dir / f"{top}.sv"
    if cand.exists():
        return cand
    for p in rtl_dir.rglob("*.sv"):
        if p.stem == top:
            return p
    return None

def parse_top_ports(top_file: Path) -> dict:
    """
    Very simple parser of the module header: collects input/output names.
    Robust enough for common single-line and comma-separated declarations.
    """
    try:
        text = top_file.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return {"clk":[], "rst":[], "inputs":[], "outputs":[], "parameters":{}, "localparams":{}}

    # Extract header: from "module <name>" to the first ");"
    m = re.search(r"module\s+\w+\s*\((.*?)\);\s", text, flags=re.S|re.M)
    if not m:
        # Fallback: split by first ');'
        header_text = text.split(");", 1)[0]
    else:
        header_text = m.group(1)

    lines = [re.sub(r"//.*", "", ln).strip() for ln in header_text.splitlines()]
    lines = [ln for ln in lines if ln]

    clk, rst = [], []
    inputs, input_w = [], []
    outputs, output_w = [], []

    def parse_decl(prefix: str, line: str):
        # Accept: input logic [31:0] a, b, c
        body = line[len(prefix):].strip()
        toks = body.split()
        if not toks:
            return None, []
        if toks[0] in ("logic","wire","reg"):
            toks = toks[1:]
            if not toks:
                return None, []
        width_tok = None
        if toks and toks[0].startswith('['):
            width_tok = toks[0]
            toks = toks[1:]
        names = [t.rstrip(",") for t in toks if t.rstrip(",")]
        return width_tok if width_tok else 1, names

    for ln in lines:
        if ln.startswith("input "):
            w, names = parse_decl("input ", ln)
            if names:
                for n in names:
                    if "clk" in n: clk.append(n)
                    if "rst" in n: rst.append(n)
                    inputs.append(n); input_w.append(w)
        elif ln.startswith("output "):
            w, names = parse_decl("output ", ln)
            if names:
                for n in names:
                    outputs.append(n); output_w.append(w)

    return {
        "clk": clk,
        "rst": rst,
        "inputs": [{"name":n, "width": input_w[i]} for i, n in enumerate(inputs)],
        "outputs":[{"name":n, "width": output_w[i]} for i, n in enumerate(outputs)],
        "parameters": {},
        "localparams": {},
    }

def make_other_port_decls(info: dict) -> tuple[list[str], str]:
    """Return (names_list, decl_block) of non-tl/clk/rst ports as logic signals."""
    ctrl = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i","tl_o"}
    def wdecl(w): return "logic" if (w == 1 or str(w) == "1") else f"logic {w}"
    names: list[str] = []
    decls: list[str] = []
    for e in info.get("inputs", []):
        n = e.get("name","")
        if not n or n in ctrl or n.startswith(("clk","rst")) or "::" in n: continue
        names.append(n); decls.append(f"  {wdecl(e.get('width',1))} {n};")
    for e in info.get("outputs", []):
        n = e.get("name","")
        if not n or n in ctrl or n.startswith(("clk","rst")) or "::" in n: continue
        names.append(n); decls.append(f"  {wdecl(e.get('width',1))} {n};")
    return names, "\n".join(decls)

# -----------------------------------------------------------------------------
# Makefile helpers
# -----------------------------------------------------------------------------
def mk_verilog_sources_block(paths: list[Path]) -> str:
    lines = ["VERILOG_SOURCES := \\"]
    for p in paths:
        posix = p.as_posix().lstrip("./")
        lines.append(f"  $(ROOT)/{posix} \\")
    return "\n".join(lines)

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------
def main():
    args = parse_args()

    TOP = args.top
    ITF = args.itf
    OUT = Path(args.output)
    RTL_DIR = Path(args.rtl_dir)
    IPS_ROOT = Path(args.ips_root)

    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / "drivers").mkdir(parents=True, exist_ok=True)

    # 1) Build ordered sources via common (preferred) or fallback
    ordered = build_ordered_sources(TOP, RTL_DIR, IPS_ROOT)

    # 2) Generate Makefile
    verilog_block = makefile_block_from_paths(ordered)
    mk = dedent(f"""\
    # Auto-generated Makefile
    # --- Simulator & language ---
    SIM               ?= {args.sim}
    TOPLEVEL_LANG     ?= verilog

    # --- Paths ---
    PWD               := $(shell pwd)
    ROOT              := $(abspath ../..)
    SRC_DIR           := $(PWD)/../../rtl

    # --- Top testbench & Python test module ---
    TOPLEVEL = {TOP}_tb
    MODULE = {TOP}_tb

    # Force Icarus on clean-only goals
    ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
      SIM := icarus
    endif

    ifeq ($(GATES),yes)
      SIM := icarus
    else
      SIM ?= verilator
    endif

    # --- Where to build ---
    SIM_BUILD         ?= sim_build/rtl

    # =============================================================================
    # RTL SOURCES
    # =============================================================================
    ifneq ($(GATES),yes)

    {verilog_block}

    COMPILE_ARGS \t+= -Wno-WIDTHEXPAND
    COMPILE_ARGS \t+= -Wno-UNOPTFLAT
    COMPILE_ARGS    += --sv --timing
    COMPILE_ARGS    += --trace --trace-fst --trace-structs

    else
    # =============================================================================
    # GATE-LEVEL SOURCES
    # =============================================================================
    SIM_BUILD              ?= sim_build/gl
    COMPILE_ARGS           += -DFUNCTIONAL -DUSE_POWER_PINS -DSIM -DUNIT_DELAY=#1
    VERILOG_SOURCES        += ../../verilog/primitives.v
    VERILOG_SOURCES        += ../../verilog/sky130_fd_sc_hd.v
    VERILOG_SOURCES        += ../../syn/{TOP}_synth.v
    endif

    # =============================================================================
    # Common compile flags / includes
    # =============================================================================
    COMPILE_ARGS += -I$(SRC_DIR) -I$(ROOT)/rtl -I$(ROOT)/ips/pkgs \\
    \t\t       -I$(ROOT)/ips/prim -I$(ROOT)/ips/prim_opentitan -I$(ROOT)/ips/tlul

    # Cocotb: path del report JUnit (usato dalla CI)
    export COCOTB_RESULTS_FILE ?= $(abspath results.xml)

    VERILOG_SOURCES += $(ROOT)/tb/cocotb/{TOP}_tb.sv

    # =============================================================================
    # Include le regole Cocotb
    # =============================================================================
    include $(shell cocotb-config --makefiles)/Makefile.sim
    """)
    (OUT / "Makefile").write_text(mk, encoding="utf-8")

    # 3) Utils + drivers
    (OUT / "utils.py").write_text(dedent("""\
    import random, math
    def rand_bin_values(nbit:int):
        a = random.randint(0, (1<<nbit)-1)
        b = random.randint(0, (1<<nbit)-1)
        return a, b
    """), encoding="utf-8")
    (OUT / "__init__.py").write_text("", encoding="utf-8")

    (OUT / "drivers" / "driver_reg_iface.py").write_text(dedent("""\
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
    """), encoding="utf-8")

    (OUT / "drivers" / "driver_tlul.py").write_text(dedent("""\
    import os
    from cocotb.triggers import RisingEdge

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

            a_map = {"a_valid":"a_valid","a_opcode":"a_opcode","a_param":"a_param",
                    "a_size":"a_size","a_source":"a_source","a_address":"a_address","a_mask":"a_mask",
                    "a_data":"a_data","d_ready":"d_ready"}
            d_map = {"a_ready":"a_ready","d_valid":"d_valid","d_opcode":"d_opcode","d_data":"d_data","d_error":"d_error"}

            a_handles = _find_many_flat(root, a_prefix, a_map)
            d_handles = _find_many_flat(root, d_prefix, d_map)

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
                        d_handles = { n:_get_attr(tlo,n) for n in need_d }

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
                self.a_ready   = d_handles["a_ready"]
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
                self.a_valid   = a_handles["a_valid"];  self.a_ready = d_handles["a_ready"]
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
            self.a_address.value = addr
            self.a_data.value    = data
            self.a_mask.value    = mask
            self.a_param.value   = 0
            self.a_size.value    = 2
            self.a_source.value  = 0
            self.a_opcode.value  = opcode
            self.a_valid.value   = 1

            for _ in range(10000):
                await RisingEdge(self.clk)
                if int(self.a_ready.value):
                    break
            else:
                raise RuntimeError("[TLULDriver] Timeout aspettando a_ready")

            self.a_valid.value = 0

            data_out = 0
            for _ in range(10000):
                await RisingEdge(self.clk)
                if int(self.d_valid.value):
                    if opcode == TL_A_GET and int(self.d_opcode.value) == TL_D_ACCESS_ACK_DATA:
                        data_out = int(self.d_data.value)
                    elif opcode == TL_A_PUT_FULL:
                        pass
                    if int(self.d_error.value):
                        raise RuntimeError("[TLULDriver] d_error=1")
                    break
            else:
                raise RuntimeError("[TLULDriver] Timeout aspettando d_valid")
            return data_out
    """), encoding="utf-8")

    # 4) Test
    (OUT / f"{TOP}_tb.py").write_text(dedent(f"""\
    # Auto-generated cocotb test for {TOP}
    import os
    import cocotb
    from cocotb.clock import Clock
    from cocotb.triggers import RisingEdge
    import utils

    ITF = os.getenv("ITF","{args.itf}")
    CLK_PERIOD_NS = float(os.getenv("CLK_PERIOD_NS","{args.period_ns}"))
    TB_CLK = os.getenv("TB_CLK","{args.clk}")
    TB_RST = os.getenv("TB_RST","{args.rst}")
    TB_RST_ACTIVE = os.getenv("TB_RST_ACTIVE","{args.rst_active}")
    N_OP = int(os.getenv("N_OP","{args.n_op}"))
    NBIT = int(os.getenv("NBIT","{args.nbit}"))

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
        for _ in range(2):
            await RisingEdge(clk)

    @cocotb.test()
    async def {TOP}_smoke_test(dut):
        clk = getattr(dut, TB_CLK)
        cocotb.start_soon(Clock(clk, CLK_PERIOD_NS, unit="ns").start())
        await reset(dut)

        bus = BusDriver(dut, clk_name=TB_CLK, rst_name=TB_RST)

        if ITF == "reg_iface":
            await bus.reset_idle()
            await bus.write32(0x0, 0x1, 0xF)
            rd = await bus.read32(0x0)
            dut._log.info(f"REG_IFACE read @0x0 = 0x{{rd:08x}}")
        else:
            await bus._idle()
            # Optional pre-TX logging if flat signals are present
            try:
                aready = int(getattr(dut, "tl_o_a_ready", 0).value)
                dvalid = int(getattr(dut, "tl_o_d_valid", 0).value)
                derr   = int(getattr(dut, "tl_o_d_error", 0).value)
                dut._log.info(f"pre-TX: a_ready={{aready}} d_valid={{dvalid}} d_error={{derr}}")
            except Exception:
                pass

            addr  = 0x0
            wdata = 0x1
            await bus.write32(addr, wdata, 0xF)
            dut._log.info(f"TLUL WRITE32 @0x{{addr:08x}} = 0x{{wdata:08x}} OK")

            rd = await bus.read32(addr)
            dut._log.info(f"TLUL READ32  @0x{{addr:08x}} -> 0x{{rd:08x}}")

            # Adjust/remove if 0x0 is not R/W in your block
            assert rd == wdata, (
                f"Mismatch: letto 0x{{rd:08x}}, atteso 0x{{wdata:08x}}. "
                "Se 0x0 non è R/W, rimuovi questa assert."
            )

        for _ in range(5):
            await RisingEdge(clk)
    """), encoding="utf-8")

    # 5) TL-UL wrapper: declare extra DUT ports + use .* to avoid PINMISSING
    if args.itf == "tlul":
        top_path = read_top_path(RTL_DIR, TOP)
        port_info = parse_top_ports(top_path) if top_path else {"clk":[],"rst":[],"inputs":[],"outputs":[]}
        other_names, other_decls = make_other_port_decls(port_info)

        wrap = dedent(f"""\
// Auto-generated TL-UL wrapper for {TOP}
`timescale 1ns/1ps
module {TOP}_tb;
  // Clock & Reset
  logic {args.clk};
  logic {args.rst};
{other_decls}

  // TL-UL A (host->device)
  logic                       tl_i_a_valid;
  tlul_pkg::tl_a_op_e         tl_i_a_opcode;
  logic [2:0]                 tl_i_a_param;
  logic [top_pkg::TL_SZW-1:0] tl_i_a_size;
  logic [top_pkg::TL_AIW-1:0] tl_i_a_source;
  logic [top_pkg::TL_AW-1:0]  tl_i_a_address;
  logic [top_pkg::TL_DBW-1:0] tl_i_a_mask;
  logic [top_pkg::TL_DW-1:0]  tl_i_a_data;
  logic                       tl_i_d_ready;

  // TL-UL D (device->host)
  logic                       tl_o_d_valid;
  tlul_pkg::tl_d_op_e         tl_o_d_opcode;
  logic [top_pkg::TL_DW-1:0]  tl_o_d_data;
  logic                       tl_o_d_error;
  logic                       tl_o_a_ready;

  // Packed structs
  tlul_pkg::tl_h2d_t tl_i;
  tlul_pkg::tl_d2h_t tl_o;

  // Pack H2D
  assign tl_i.a_valid   = tl_i_a_valid;
  assign tl_i.a_opcode  = tl_i_a_opcode;
  assign tl_i.a_param   = tl_i_a_param;
  assign tl_i.a_size    = tl_i_a_size;
  assign tl_i.a_source  = tl_i_a_source;
  assign tl_i.a_address = tl_i_a_address;
  assign tl_i.a_mask    = tl_i_a_mask;
  assign tl_i.a_data    = tl_i_a_data;
  assign tl_i.d_ready   = tl_i_d_ready;

  // Integrity fields (cmd & data)
  logic [tlul_pkg::H2DCmdIntgWidth-1:0] cmd_intg_calc;
  logic [tlul_pkg::DataIntgWidth-1:0]   data_intg_calc;

  always_comb begin
    tlul_pkg::tl_h2d_t t = '0;
    t.a_address             = tl_i_a_address;
    t.a_opcode              = tl_i_a_opcode;
    t.a_mask                = tl_i_a_mask;
    t.a_user.instr_type     = prim_mubi_pkg::MuBi4False;
    cmd_intg_calc  = tlul_pkg::get_cmd_intg(t);
    data_intg_calc = tlul_pkg::get_data_intg(tl_i_a_data);
  end

  assign tl_i.a_user.instr_type = prim_mubi_pkg::MuBi4False;
  assign tl_i.a_user.cmd_intg   = cmd_intg_calc;
  assign tl_i.a_user.data_intg  = data_intg_calc;

  // Unpack D2H
  assign tl_o_d_valid = tl_o.d_valid;
  assign tl_o_d_opcode= tl_o.d_opcode;
  assign tl_o_d_data  = tl_o.d_data;
  assign tl_o_d_error = tl_o.d_error;
  assign tl_o_a_ready = tl_o.a_ready;

  // Waves
  initial begin
    $dumpfile("{TOP}_tb.vcd");
    $dumpvars(0, {TOP}_tb);
    #1;
  end

  // Optional SDF backannotation (ignored in Verilator)
  `ifndef VERILATOR
    initial begin
      string sdf = "../../signoff/sdf/{TOP}_ss.sdf";
      $sdf_annotate(sdf, {TOP}_tb.u_{TOP}, , , "MAXIMUM");
    end
  `endif

  // DUT instance: explicit key ports + .* to auto-connect everything else
  {TOP} u_{TOP} (
    .{args.clk}({args.clk}),
    .{args.rst}({args.rst}),
    .tl_i(tl_i),
    .tl_o(tl_o),
    .*
  );

endmodule
""")
        (OUT / f"{TOP}_tb.sv").write_text(wrap, encoding="utf-8")

    print(f"Generated in: {OUT.resolve()}")
    print("- Makefile")
    print(f"- {TOP}_tb.py")
    print("- utils.py")
    print("- drivers/driver_reg_iface.py")
    print("- drivers/driver_tlul.py")
    if args.itf == "tlul":
        print(f"- Wrapper: {OUT}/{TOP}_tb.sv")
    print(f"- Filelist: {RTL_DIR}/rtl_list.f")

if __name__ == "__main__":
    main()


def mk_verilog_sources_block(paths: Iterable[Path],
                             var_name: str = "VERILOG_SOURCES",
                             root_var: str = "$(ROOT)") -> str:
    """
    Build a Makefile block:

        VERILOG_SOURCES := \
          $(ROOT)/path1 \
          $(ROOT)/path2

    - Preserves order, de-duplicates (first wins)
    - Normalizes to POSIX, strips leading './'
    - No trailing backslash on the last line
    """
    seen = set()
    ordered = []
    for p in paths:
        posix = p.as_posix().lstrip("./")
        if posix not in seen:
            seen.add(posix)
            ordered.append(f"{root_var}/{posix}")

    if not ordered:
        return f"{var_name} :="

    lines = [f"{var_name} := \\"]
    for s in ordered[:-1]:
        lines.append(f"  {s} \\")
    lines.append(f"  {ordered[-1]}")
    return "\n".join(lines)

def mk_verilog_sources_block(paths: Iterable[Path],
                             var_name: str = "VERILOG_SOURCES",
                             root_var: str = "$(ROOT)") -> str:
    """
    Costruisce un blocco Makefile del tipo:

        VERILOG_SOURCES := \\
          $(ROOT)/path1 \\
          $(ROOT)/path2

    - Preserva l'ordine, rimuove i duplicati (vince la prima occorrenza)
    - Normalizza i path (POSIX) e toglie l'eventuale './' iniziale
    - Nessuna backslash finale sull'ultima riga
    """
    seen = set()
    ordered = []
    for p in paths:
        posix = p.as_posix().lstrip("./")
        if posix not in seen:
            seen.add(posix)
            ordered.append(f"{root_var}/{posix}")

    if not ordered:
        return f"{var_name} :="

    lines = [f"{var_name} := \\"]
    for s in ordered[:-1]:
        lines.append(f"  {s} \\")
    lines.append(f"  {ordered[-1]}")
    return "\n".join(lines)
