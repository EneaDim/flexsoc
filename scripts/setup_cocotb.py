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
parser.add_argument("--vsv", default="sv", help="Verilog or SystemVerilog flow (default: sv)")
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
COCOTB_DIR=Path('tb/cocotb')
SIM=args.sim; CLK=args.clk; RST=args.rst; RST_ACTIVE=args.rst_active
PERIOD=args.period_ns; NBIT=args.nbit; N_OP=args.n_op
INC_DIRS=[Path(p) for p in args.include_dirs]; EXTRA_SRC=[Path(p) for p in args.extra_src]
#TL_WRAP=args.tlul_wrap
TL_WRAP='on'

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

def parse_top_ports(rtldir: str | os.PathLike, top: str):
    """
    Parse the port/param header of <rtldir>/<top>.sv and return a dict:
      {
        "clk": [<names>],
        "rst": [<names>],
        "inputs":  [{"name": ..., "width": <str|int>} ...],
        "outputs": [{"name": ..., "width": <str|int>} ...],
        "parameters":   {"NAME": "VALUE", ...},
        "localparams":  {"NAME": "VALUE", ...}
      }

    Notes:
    - Width is the token right after the type (e.g. "[31:0]") or 1 if scalar.
    - Comments (//...) on lines with ports/params are stripped; pure comment lines are skipped.
    - Multi-name declarations like "input logic [3:0] a, b" are split into two entries with same width.
    """
    top_path = Path(rtldir)
    with open(top_path, "r") as f:
        content = f.readlines()

    clk, rst = [], []
    inputs, input_w = [], []
    outputs, output_w = [], []
    parameters, param_values = [], []
    localparams, localparam_values = [], []

    # Grab everything up to the first ');' after the module header
    header_text = ''.join(''.join(content).split(');')[0]).split('\n')

    for line in header_text:
        # Strip trailing // comments only if line actually contains tokens we care about
        if '//' in line:
            if any(tok in line for tok in ('input', 'output', 'parameter', 'localparam')):
                line = line.split('//', 1)[0]
            else:
                continue  # pure comment line

        line = line.strip()
        if not line:
            continue

        # Parameters
        if 'parameter' in line and 'localparam' not in line:
            lhs_rhs = line.split('=', 1)
            if len(lhs_rhs) == 2:
                lhs, rhs = lhs_rhs
                par = lhs.split()
                value = rhs.split()[0].rstrip(',')  # drop trailing comma if present
                parameters.append(par[-1])
                param_values.append(value)
            continue

        # Localparams
        if 'localparam' in line:
            lhs_rhs = line.split('=', 1)
            if len(lhs_rhs) == 2:
                lhs, rhs = lhs_rhs
                par = lhs.split()
                value = rhs.split()[0].rstrip(',')
                localparams.append(par[-1])
                localparam_values.append(value)
            continue

        # Inputs
        if line.startswith('input '):
            body = line[len('input '):].strip()
            toks = body.split()
            if not toks:
                continue
            # drop leading 'logic'
            if toks[0] == 'logic':
                toks = toks[1:]
                if not toks:
                    continue

            # Optional width in first token (e.g., [31:0])
            width_tok = None
            if toks and toks[0].startswith('['):
                width_tok = toks[0]
                toks = toks[1:]

            # Remainder are names, possibly comma-terminated
            names = [t.rstrip(',') for t in toks if t.rstrip(',')]
            if not names:
                continue

            # Heuristics for clock/reset tagging
            for nm in names:
                if 'clk_' in nm:
                    clk.append(nm)
                if 'rst_' in nm:
                    rst.append(nm)

            w = width_tok if width_tok is not None else 1
            for nm in names:
                inputs.append(nm)
                input_w.append(w)
            continue

        # Outputs
        if line.startswith('output '):
            body = line[len('output '):].strip()
            toks = body.split()
            if not toks:
                continue
            if toks[0] == 'logic':
                toks = toks[1:]
                if not toks:
                    continue

            width_tok = None
            if toks and toks[0].startswith('['):
                width_tok = toks[0]
                toks = toks[1:]

            names = [t.rstrip(',') for t in toks if t.rstrip(',')]
            if not names:
                continue

            w = width_tok if width_tok is not None else 1
            for nm in names:
                outputs.append(nm)
                output_w.append(w)
            continue

    # Build the structured result
    params_dict = {k: v for k, v in zip(parameters, param_values)}
    localparams_dict = {k: v for k, v in zip(localparams, localparam_values)}

    inputs_struct = [{"name": n, "width": input_w[i]} for i, n in enumerate(inputs)]
    outputs_struct = [{"name": n, "width": output_w[i]} for i, n in enumerate(outputs)]

    return {
        "clk": clk,
        "rst": rst,
        "inputs": inputs_struct,
        "outputs": outputs_struct,
        "parameters": params_dict,
        "localparams": localparams_dict,
    }

TOP_PATH = read_top_path()

ports = []
if TOP_PATH and ITF=="tlul":
    try:
        ports = parse_top_ports(TOP_PATH, TOP)
    except Exception:
        ports = []

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

# Gather all .sv files directly under rtl (non-recursive; change to rglob if you need recursion)
sv_files = sorted([f.name for f in RTL_DIR.glob("*.sv")])

# Group 1: *_pkg.sv plus tl_main_pkg.sv (if present)
pkg = sorted([f for f in sv_files if f.endswith("_pkg.sv")])

# Group 2: everything else (exclude group 1)
others = sorted([f for f in sv_files if f not in pkg])
others = others[::-1]

lines = []
# First block
for f in pkg:
    lines.append(f"$(ROOT)/{RTL_DIR}/{f} \\")

# Second block
for f in others:
    lines.append(f"  $(ROOT)/{RTL_DIR}/{f} \\")

text = "\n".join(lines)


mk = dedent(f"""\
# Auto-generated Makefile
# --- Simulator & language ---
SIM               ?= {SIM}
TOPLEVEL_LANG     ?= verilog

# --- Paths ---
PWD               := $(shell pwd)
ROOT              := $(abspath ../..)
SRC_DIR           := $(PWD)/../../rtl

# --- Top testbench & Python test module ---
TOPLEVEL = {TOP}_tb
MODULE = {TOP}_tb

# Forza Icarus quando il goal è di pulizia (non tocca il workflow)
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

VERILOG_SOURCES := \\
  $(ROOT)/ips/pkgs/top_pkg.sv \\
  $(ROOT)/ips/prim/prim_reg_pkg.sv \\
  $(ROOT)/ips/pkgs/prim_mubi_pkg.sv \\
  $(ROOT)/ips/pkgs/prim_secded_pkg.sv \\
  $(ROOT)/ips/pkgs/prim_subreg_pkg.sv \\
  $(ROOT)/ips/pkgs/prim_util_pkg.sv \\
  $(ROOT)/ips/pkgs/tlul_pkg.sv \\
  $(ROOT)/ips/pkgs/prim_assert.sv \\
  $(ROOT)/ips/pkgs/prim_count_pkg.sv \\
  $(ROOT)/ips/pkgs/prim_flop_macros.sv \\
  $(ROOT)/ips/pkgs/prim_alert_pkg.sv \\
  $(ROOT)/ips/prim/prim_bin2gray.sv \\
  $(ROOT)/ips/prim/prim_cdc_2phase.sv \\
  $(ROOT)/ips/prim/prim_clk_div.sv \\
  $(ROOT)/ips/prim/prim_clk_gate.sv \\
  $(ROOT)/ips/prim/prim_counter.sv \\
  $(ROOT)/ips/prim/prim_deglitch.sv \\
  $(ROOT)/ips/prim/prim_edge_detect.sv \\
  $(ROOT)/ips/prim/prim_ff.sv \\
  $(ROOT)/ips/prim/prim_ff_2sync.sv \\
  $(ROOT)/ips/prim/prim_fifo.sv \\
  $(ROOT)/ips/prim/prim_gray2bin.sv \\
  $(ROOT)/ips/prim/prim_lifo.sv \\
  $(ROOT)/ips/prim/prim_lzc.sv \\
  $(ROOT)/ips/prim/prim_ram.sv \\
  $(ROOT)/ips/prim/prim_reg.sv \\
  $(ROOT)/ips/prim/prim_rom.sv \\
  $(ROOT)/ips/prim/prim_rrarbiter.sv \\
  $(ROOT)/ips/prim/prim_shreg.sv \\
  $(ROOT)/ips/prim_opentitan/prim_arbiter_ppc.sv \\
  $(ROOT)/ips/prim_opentitan/prim_buf.sv \\
  $(ROOT)/ips/prim_opentitan/prim_cdc_rand_delay.sv \\
  $(ROOT)/ips/prim_opentitan/prim_count.sv \\
  $(ROOT)/ips/prim_opentitan/prim_diff_decode.sv \\
  $(ROOT)/ips/prim_opentitan/prim_fifo_async.sv \\
  $(ROOT)/ips/prim_opentitan/prim_fifo_async_simple.sv \\
  $(ROOT)/ips/prim_opentitan/prim_fifo_async_sram_adapter.sv \\
  $(ROOT)/ips/prim_opentitan/prim_fifo_sync.sv \\
  $(ROOT)/ips/prim_opentitan/prim_fifo_sync_cnt.sv \\
  $(ROOT)/ips/prim_opentitan/prim_filter.sv \\
  $(ROOT)/ips/prim_opentitan/prim_filter_ctr.sv \\
  $(ROOT)/ips/prim_opentitan/prim_flop.sv \\
  $(ROOT)/ips/prim_opentitan/prim_flop_2sync.sv \\
  $(ROOT)/ips/prim_opentitan/prim_intr_hw.sv \\
  $(ROOT)/ips/prim_opentitan/prim_onehot_check.sv \\
  $(ROOT)/ips/prim_opentitan/prim_pulse_sync.sv \\
  $(ROOT)/ips/prim_opentitan/prim_reg_cdc.sv \\
  $(ROOT)/ips/prim_opentitan/prim_reg_cdc_arb.sv \\
  $(ROOT)/ips/prim_opentitan/prim_reg_we_check.sv \\
  $(ROOT)/ips/prim_opentitan/prim_sec_anchor_buf.sv \\
  $(ROOT)/ips/prim_opentitan/prim_sec_anchor_flop.sv \\
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_39_32_dec.sv \\
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_39_32_enc.sv \\
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_64_57_dec.sv \\
  $(ROOT)/ips/prim_opentitan/prim_secded_inv_64_57_enc.sv \\
  $(ROOT)/ips/prim_opentitan/prim_subreg.sv \\
  $(ROOT)/ips/prim_opentitan/prim_subreg_arb.sv \\
  $(ROOT)/ips/prim_opentitan/prim_subreg_ext.sv \\
  $(ROOT)/ips/prim_opentitan/prim_sync_reqack.sv \\
  $(ROOT)/ips/prim_opentitan/prim_alert_sender.sv \\
  $(ROOT)/ips/tlul/sram2tlul.sv \\
  $(ROOT)/ips/tlul/tlul_adapter_host.sv \\
  $(ROOT)/ips/tlul/tlul_adapter_reg.sv \\
  $(ROOT)/ips/tlul/tlul_adapter_sram.sv \\
  $(ROOT)/ips/tlul/tlul_assert.sv \\
  $(ROOT)/ips/tlul/tlul_assert_multiple.sv \\
  $(ROOT)/ips/tlul/tlul_cmd_intg_chk.sv \\
  $(ROOT)/ips/tlul/tlul_cmd_intg_gen.sv \\
  $(ROOT)/ips/tlul/tlul_data_integ_dec.sv \\
  $(ROOT)/ips/tlul/tlul_data_integ_enc.sv \\
  $(ROOT)/ips/tlul/tlul_err.sv \\
  $(ROOT)/ips/tlul/tlul_err_resp.sv \\
  $(ROOT)/ips/tlul/tlul_fifo_async.sv \\
  $(ROOT)/ips/tlul/tlul_fifo_sync.sv \\
  $(ROOT)/ips/tlul/tlul_rsp_intg_chk.sv \\
  $(ROOT)/ips/tlul/tlul_rsp_intg_gen.sv \\
  $(ROOT)/ips/tlul/tlul_socket_1n.sv \\
  $(ROOT)/ips/tlul/tlul_socket_m1.sv \\
  $(ROOT)/ips/tlul/tlul_sram_byte.sv \\
  {text}

COMPILE_ARGS 	+= -Wno-WIDTHEXPAND
COMPILE_ARGS 	+= -Wno-UNOPTFLAT
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
			       -I$(ROOT)/ips/prim -I$(ROOT)/ips/prim_opentitan -I$(ROOT)/ips/tlul

# Cocotb: path del report JUnit (usato dalla CI)
export COCOTB_RESULTS_FILE ?= $(abspath results.xml)

VERILOG_SOURCES += $(ROOT)/tb/cocotb/{TOP}_tb.sv

# =============================================================================
# Include le regole Cocotb
# =============================================================================
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

        a_map = {"a_valid":"a_valid","a_opcode":"a_opcode","a_param":"a_param",
                 "a_size":"a_size","a_source":"a_source","a_address":"a_address","a_mask":"a_mask",
                 "a_data":"a_data","d_ready":"d_ready"}
        d_map = {"a_ready":"a_ready","d_valid":"d_valid","d_opcode":"d_opcode","d_data":"d_data","d_error":"d_error"}

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
                if all(_get_attr(tli, n) is not None for n in need_a) and                    all(_get_attr(tlo, n) is not None for n in need_d):
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
        # Programma A
        self.a_address.value = addr
        self.a_data.value    = data
        self.a_mask.value    = mask
        self.a_param.value   = 0
        self.a_size.value    = 2
        self.a_source.value  = 0
        self.a_opcode.value  = opcode
    
        # Avvia la richiesta
        self.a_valid.value = 1
    
        # Attendi POSedge con a_ready=1 (handshake) — con timeout
        for i in range(10000):
            await RisingEdge(self.clk)
            if int(self.a_ready.value):
                break
        else:
            raise RuntimeError("[TLULDriver] Timeout aspettando a_ready (nessun handshake)")
    
        # Handshake avvenuto al fronte appena passato
        self.a_valid.value = 0
    
        # Attendi risposta D — con timeout
        data_out = 0
        for i in range(10000):
            await RisingEdge(self.clk)
            if int(self.d_valid.value):
                # Decodifica risposta
                if opcode == TL_A_GET and int(self.d_opcode.value) == TL_D_ACCESS_ACK_DATA:
                    data_out = int(self.d_data.value)
                elif opcode == TL_A_PUT_FULL and int(self.d_opcode.value) in (TL_D_ACCESS_ACK, TL_D_ACCESS_ACK_DATA):
                    pass
                if int(self.d_error.value):
                    raise RuntimeError("[TLULDriver] D error (d_error=1)")
                break
        else:
            raise RuntimeError("[TLULDriver] Timeout aspettando d_valid (nessuna risposta)")
    
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

        # Log di stato utili
        try:
            aready = int(dut.tl_o_a_ready.value)
            dvalid = int(dut.tl_o_d_valid.value)
            derr   = int(dut.tl_o_d_error.value)
            dut._log.info(f"pre-TX: a_ready={{aready}} d_valid={{dvalid}} d_error={{derr}}")
        except Exception:
            # se non sei in wrapper flat, questi potrebbero non esistere: ignora
            pass

        # write + read base
        addr  = 0x0
        wdata = 0x1
        await bus.write32(addr, wdata, 0xF)
        dut._log.info(f"TLUL WRITE32 @0x{{addr:08x}} = 0x{{wdata:08x}} OK")

        rd = await bus.read32(addr)
        dut._log.info(f"TLUL READ32  @0x{{addr:08x}} -> 0x{{rd:08x}}")

        # Se il registro 0x0 è R/W, controlla il dato
        # (commenta l'assert se 0x0 non è R/W nel tuo block)
        assert rd == wdata, (
            f"Mismatch: letto 0x{{rd:08x}}, atteso 0x{{wdata:08x}}. "
            "Se 0x0 non è R/W, rimuovi questa assert."
        )

    # 4) Qualche ciclo extra
    for _ in range(5):
        await RisingEdge(clk)

"""))

# --------- wrapper SV (se richiesto) ----------
# Ricrea porte (tutte tranne tl_i/tl_o) identiche al DUT

# escludi clock/reset/TL-UL
def make_other_port_lines(info: dict, include_dir: bool = False) -> str:
    """
    Converte le porte del dict 'info' in dichiarazioni SystemVerilog.
    - Se include_dir=True: 'input logic foo;' / 'output logic bar;'
    - Se include_dir=False: 'logic foo;' / 'logic [..] bar;'
    """
    # escludi clk/rst e TL-UL
    ctrl = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}

    def width_to_decl(w):
        return "logic" if (w == 1 or str(w) == "1") else f"logic {w}"

    flat = []

    # Inputs
    for e in info.get("inputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        wdecl = width_to_decl(e.get("width", 1))
        flat.append({
            "dir": "input",
            "decl": wdecl,
            "name": n,
        })

    # Outputs
    for e in info.get("outputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        wdecl = width_to_decl(e.get("width", 1))
        flat.append({
            "dir": "output",
            "decl": wdecl,
            "name": n,
        })

    def line(p):
        if include_dir:
            return f'  {p["dir"]} {p["decl"]} {p["name"]};'
        else:
            return f'  {p["decl"]} {p["name"]};'

    return "\n".join(line(p) for p in flat)

other_port_lines = make_other_port_lines(ports, include_dir=False)
# ====== build "other_ports" (lista) e "other_port_lines" (stringa) ======
def collect_other_ports(info: dict):
    """Ritorna la lista filtrata di porte non-ctrl e non-TL come dict {name, decl}."""
    ctrl = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}

    def width_to_decl(w):
        return "logic" if (w == 1 or str(w) == "1") else f"logic {w}"

    flat = []
    for e in info.get("inputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        flat.append({"name": n, "decl": width_to_decl(e.get("width", 1))})

    for e in info.get("outputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        flat.append({"name": n, "decl": width_to_decl(e.get("width", 1))})

    return flat

other_ports = collect_other_ports(ports)  # <- ports è il tuo dict ricco
other_port_lines = "\n".join(f"  {p['decl']} {p['name']};" for p in other_ports)


wrap = dedent(f"""\
// Auto-generated TL-UL wrapper for {TOP}
`timescale 1ns/1ps
module {TOP}_tb;
  // Clock & Reset sono pilotati da cocotb (via porte)
  logic                 {CLK};
  logic                 {RST};
{other_port_lines}

  // === PORTE TL-UL FLAT lato A (host->device) ===
  logic                       tl_i_a_valid;
  tlul_pkg::tl_a_op_e         tl_i_a_opcode;
  logic [2:0]                 tl_i_a_param;
  logic [top_pkg::TL_SZW-1:0] tl_i_a_size;
  logic [top_pkg::TL_AIW-1:0] tl_i_a_source;
  logic [top_pkg::TL_AW-1:0]  tl_i_a_address;
  logic [top_pkg::TL_DBW-1:0] tl_i_a_mask;
  logic [top_pkg::TL_DW-1:0]  tl_i_a_data;
  logic                       tl_i_d_ready;

  // === PORTE TL-UL FLAT lato D (device->host) ===
  logic                       tl_o_d_valid;
  tlul_pkg::tl_d_op_e         tl_o_d_opcode;
  // d_param, d_size, d_source, d_sink non servono al driver attuale
  logic [top_pkg::TL_DW-1:0]  tl_o_d_data;
  logic                       tl_o_d_error;
  logic                       tl_o_a_ready;

  // ==== Pack/unpack verso i struct del DUT ====
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
  // default/unused user
  //assign tl_i.a_user    = tlul_pkg::TL_A_USER_DEFAULT;
  // === ECC / integrità TL-UL senza riferirsi a tl_i per evitare anelli ===
  logic [tlul_pkg::H2DCmdIntgWidth-1:0] cmd_intg_calc;
  logic [tlul_pkg::DataIntgWidth-1:0]   data_intg_calc;
  
  always_comb begin
    // Costruisco un "mini" tl_h2d_t SOLO con i campi usati da extract_h2d_cmd_intg()
    tlul_pkg::tl_h2d_t t = '0;
    t.a_address             = tl_i_a_address;
    t.a_opcode              = tl_i_a_opcode;
    t.a_mask                = tl_i_a_mask;
    t.a_user.instr_type     = prim_mubi_pkg::MuBi4False;
    // Nota: non tocchiamo t.a_user.cmd_intg qui
  
    cmd_intg_calc  = tlul_pkg::get_cmd_intg(t);
    data_intg_calc = tlul_pkg::get_data_intg(tl_i_a_data); // prende solo i dati
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

  // Dump Waves
  initial begin
    $dumpfile("{TOP}_tb.vcd");
    $dumpvars(0, {TOP}_tb);
    #1;
  end

  // SDF backannotation
  `ifndef VERILATOR
    initial begin
      string sdf = "../../signoff/sdf/{TOP}_ss.sdf";
      $sdf_annotate(sdf, {TOP}_tb.u_{TOP}, , , "MAXIMUM");
    end
  `endif
  
  // -------- DUT con porte pass-through --------
  {TOP} u_{TOP} (
    .{CLK}({CLK}),
    .{RST}({RST}),
""")
other_ports = collect_other_ports(ports)
for p in other_ports:
    wrap += f'    .{p["name"]}({p["name"]}),\n'
wrap += dedent("""\
    .tl_i(tl_i),
    .tl_o(tl_o)
  );
endmodule
""")
(COCOTB_DIR/f"{TOP}_tb.sv").write_text(wrap)

print(f"Generated in: {OUT.resolve()}")
print("- Makefile")
print(f"- {TOP}_tb.py")
print("- utils.py")
print("- drivers/driver_reg_iface.py")
print("- drivers/driver_tlul.py")
print(f"- Wrapper: {RTL_DIR}/{TOP}_tb.sv (TOPLEVEL={TOP}_cocotb_wrap)")
