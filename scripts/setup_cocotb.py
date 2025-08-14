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
import sys, os
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
args = parser.parse_args()

TOP=args.top; ITF=args.itf; OUT=Path(args.output); RTL_DIR=Path(args.rtl_dir)
SIM=args.sim; CLK=args.clk; RST=args.rst; RST_ACTIVE=args.rst_active
PERIOD=args.period_ns; NBIT=args.nbit; N_OP=args.n_op
INC_DIRS=[Path(p) for p in args.include_dirs]; EXTRA_SRC=[Path(p) for p in args.extra_src]

OUT.mkdir(parents=True, exist_ok=True)
(OUT/"drivers").mkdir(parents=True, exist_ok=True)

def is_hdl(p:Path)->bool: return p.suffix.lower() in {".sv",".v",".vh",".svh"}
rtl_files=[]
if RTL_DIR.exists():
    for p in RTL_DIR.rglob("*"):
        if p.is_file() and is_hdl(p):
            if p.stem.lower().endswith("_tb"): continue
            rtl_files.append(p.resolve())
for p in EXTRA_SRC:
    if p.exists() and is_hdl(p): rtl_files.append(p.resolve())
rtl_files=sorted(set(rtl_files))

# Makefile
inc_flags=[]
for d in INC_DIRS+[RTL_DIR]:
    if not d.exists(): continue
    if SIM=="verilator": inc_flags.append(f"-I{d.resolve()}")
    elif SIM in {"questa","vcs","xcelium"}: inc_flags.append(f"+incdir+{d.resolve()}")
    elif SIM=="icarus": inc_flags.append(f"-I{d.resolve()}")
EXTRA_ARGS=" ".join(inc_flags)

VERILOG_SOURCES=""
for i,src in enumerate(rtl_files):
    prefix="VERILOG_SOURCES +=" if i>0 else "VERILOG_SOURCES :="
    VERILOG_SOURCES+=f"{prefix} $(PWD)/{os.path.relpath(src, OUT.resolve())}\n"

mk = dedent(f"""\
# Auto-generated Makefile
SIM ?= {SIM}
TOPLEVEL_LANG = verilog
PWD = $(shell pwd)

{VERILOG_SOURCES if VERILOG_SOURCES else 'VERILOG_SOURCES :='}
VERILOG_SOURCES += $(PWD)/../{args.rtl_dir}/{TOP}.sv

TOPLEVEL = {TOP}
MODULE = {TOP}_tb

export ITF ?= {ITF}
export NBIT ?= {NBIT}
export N_OP ?= {N_OP}
export CLK_PERIOD_NS ?= {PERIOD}
export TB_CLK ?= {CLK}
export TB_RST ?= {RST}
export TB_RST_ACTIVE ?= {RST_ACTIVE}

EXTRA_ARGS ?= {EXTRA_ARGS}

include $(shell cocotb-config --makefiles)/Makefile.sim
""")
(OUT/"Makefile").write_text(mk)

# utils.py
utils_py = dedent("""\
import random, math
def rand_bin_values(nbit:int):
    a = random.randint(0, (1<<nbit)-1)
    b = random.randint(0, (1<<nbit)-1)
    return a,b
""")
(OUT/"utils.py").write_text(utils_py)
(OUT/"__init__.py").write_text("")

# driver: reg_iface
driver_reg = dedent("""\
import cocotb
from cocotb.triggers import RisingEdge

class RegIFDriver:
    \"\"\"Driver per interfaccia 'register_interface' (req/rsp valid/ready).
    Supporta sia porta STRUCT (dut.reg_req_i.valid) sia FLAT (dut.reg_req_valid).
    \"\"\"
    def __init__(self, dut, clk_name="clk_i", rst_name="rst_ni", req_base=None, rsp_base=None):
        self.dut=dut
        self.clk=getattr(dut, clk_name)
        self.rst=getattr(dut, rst_name)
        # heuristics: try typical names
        self.req = getattr(dut, req_base, None) if req_base else \
                   getattr(dut, "reg_req_i", None) or getattr(dut, "reg_req", None)
        self.rsp = getattr(dut, rsp_base, None) if rsp_base else \
                   getattr(dut, "reg_rsp_o", None) or getattr(dut, "reg_rsp", None)
        # struct or flat?
        self.struct = self.req is not None and hasattr(self.req, "valid") and hasattr(self.rsp, "ready")
        if not self.struct:
            # map flat signals
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
                raise RuntimeError(f"[RegIFDriver] Impossibile trovare segnali struct o flat tipici. "
                                   f"Attesi struct (reg_req_i/reg_rsp_o) oppure flat "
                                   f"(reg_req_valid, reg_req_write, ...). Dettaglio: {e}")

    async def reset_idle(self):
        if self.struct:
            self.req.valid.value = 0
            self.req.write.value = 0
            self.req.addr.value  = 0
            self.req.wdata.value = 0
            self.req.wstrb.value = 0
        else:
            self.req_valid.value = 0
            self.req_write.value = 0
            self.req_addr.value  = 0
            self.req_wdata.value = 0
            self.req_wstrb.value = 0
        await RisingEdge(self.clk)

    async def write32(self, addr:int, data:int, wstrb:int=0xF):
        if self.struct:
            self.req.addr.value  = addr
            self.req.wdata.value = data
            self.req.wstrb.value = wstrb
            self.req.write.value = 1
            self.req.valid.value = 1
        else:
            self.req_addr.value  = addr
            self.req_wdata.value = data
            self.req_wstrb.value = wstrb
            self.req_write.value = 1
            self.req_valid.value = 1
        # attendi ready
        while True:
            await RisingEdge(self.clk)
            ready = self.rsp.ready.value.integer if self.struct else self.rsp_ready.value.integer
            if ready: break
        # deassert
        if self.struct:
            self.req.valid.value = 0
            self.req.write.value = 0
        else:
            self.req_valid.value = 0
            self.req_write.value = 0
        await RisingEdge(self.clk)

    async def read32(self, addr:int) -> int:
        if self.struct:
            self.req.addr.value  = addr
            self.req.wdata.value = 0
            self.req.wstrb.value = 0
            self.req.write.value = 0
            self.req.valid.value = 1
        else:
            self.req_addr.value  = addr
            self.req_wdata.value = 0
            self.req_wstrb.value = 0
            self.req_write.value = 0
            self.req_valid.value = 1
        data=0
        while True:
            await RisingEdge(self.clk)
            ready = self.rsp.ready.value.integer if self.struct else self.rsp_ready.value.integer
            if ready:
                data = (self.rsp.rdata.value.integer if self.struct else self.rsp_rdata.value.integer)
                break
        if (self.rsp.error.value.integer if self.struct else self.rsp_error.value.integer):
            raise RuntimeError("[RegIFDriver] Read returned error at 0x%08x" % addr)
        # deassert
        if self.struct: self.req.valid.value = 0
        else:           self.req_valid.value = 0
        await RisingEdge(self.clk)
        return data
""")
(OUT/"drivers"/"driver_reg_iface.py").write_text(driver_reg)

# driver: tlul
driver_tlul = dedent("""\
import cocotb
from cocotb.triggers import RisingEdge

# TL-UL opcodes (UL subset)
TL_A_PUT_FULL = 0
TL_A_GET      = 4
TL_D_ACCESS_ACK      = 0
TL_D_ACCESS_ACK_DATA = 1

class TLULDriver:
    \"\"\"Driver per TL-UL UL subset (Get/PutFullData).
    Supporta naming FLAT tipico (tl_a_valid, tl_a_ready, tl_a_address, tl_a_data, tl_a_mask, tl_d_*)
    oppure via canalizzazione 'a'/'d' sotto 'tl'/'tl_i'/'tl_o' (se il simulatore espone i campi).
    \"\"\"
    def __init__(self, dut, clk_name="clk_i", rst_name="rst_ni", base=None):
        self.dut=dut
        self.clk=getattr(dut, clk_name)
        self.rst=getattr(dut, rst_name)
        # tenta flat
        try:
            self.a_valid = getattr(dut, "tl_a_valid")
            self.a_ready = getattr(dut, "tl_a_ready")
            self.a_opcode= getattr(dut, "tl_a_opcode")
            self.a_param = getattr(dut, "tl_a_param")
            self.a_size  = getattr(dut, "tl_a_size")
            self.a_source= getattr(dut, "tl_a_source")
            self.a_address=getattr(dut, "tl_a_address")
            self.a_mask  = getattr(dut, "tl_a_mask")
            self.a_data  = getattr(dut, "tl_a_data")
            self.d_ready = getattr(dut, "tl_d_ready")
            self.d_valid = getattr(dut, "tl_d_valid")
            self.d_opcode=getattr(dut, "tl_d_opcode")
            self.d_data  = getattr(dut, "tl_d_data")
            self.d_error = getattr(dut, "tl_d_error")
            self.flat = True
        except AttributeError:
            # prova stile canalizzato: tl_i.a.*, tl_o.d.*
            self.flat = False
            tl_i = getattr(dut, base, None) if base else (getattr(dut, "tl_i", None) or getattr(dut, "tl", None))
            tl_o = getattr(dut, "tl_o", None) or getattr(dut, "tl", None)
            if tl_i is None or tl_o is None:
                raise RuntimeError("[TLULDriver] Non trovo segnali flat (tl_a_*) né handle tl_i/tl_o.")
            try:
                self.a = tl_i.a
                self.d = tl_o.d
            except AttributeError as e:
                raise RuntimeError("[TLULDriver] tl_i/tl_o presenti ma senza canali a/d visibili. Dettaglio: %s" % e)

    async def _idle(self):
        if self.flat:
            self.a_valid.value = 0
            self.a_opcode.value= 0
            self.a_param.value = 0
            self.a_size.value  = 2   # 4B
            self.a_source.value= 0
            self.a_address.value=0
            self.a_mask.value  = 0
            self.a_data.value  = 0
            self.d_ready.value = 1
        else:
            self.a.valid.value = 0
            self.a.opcode.value= 0
            self.a.param.value = 0
            self.a.size.value  = 2
            self.a.source.value= 0
            self.a.address.value=0
            self.a.mask.value  = 0
            self.a.data.value  = 0
            self.d.ready.value = 1
        await RisingEdge(self.clk)

    async def write32(self, addr:int, data:int, mask:int=0xF):
        await self._do_tx(addr, data, mask, TL_A_PUT_FULL)

    async def read32(self, addr:int) -> int:
        return await self._do_tx(addr, 0, 0x0, TL_A_GET)

    async def _do_tx(self, addr:int, data:int, mask:int, opcode:int) -> int:
        # Drive A
        if self.flat:
            self.a_address.value = addr
            self.a_data.value    = data
            self.a_mask.value    = mask
            self.a_param.value   = 0
            self.a_size.value    = 2
            self.a_source.value  = 0
            self.a_opcode.value  = opcode
            self.a_valid.value   = 1
            # handshake A
            while not self.a_ready.value:
                await RisingEdge(self.clk)
            self.a_valid.value = 0
        else:
            self.a.address.value = addr
            self.a.data.value    = data
            self.a.mask.value    = mask
            self.a.param.value   = 0
            self.a.size.value    = 2
            self.a.source.value  = 0
            self.a.opcode.value  = opcode
            self.a.valid.value   = 1
            while not self.a.ready.value:
                await RisingEdge(self.clk)
            self.a.valid.value = 0
        # Attendi D
        data_out=0
        while True:
            await RisingEdge(self.clk)
            d_valid = (self.d_valid.value if self.flat else self.d.valid.value)
            if d_valid:
                if self.flat:
                    if opcode==TL_A_GET and self.d_opcode.value.integer==TL_D_ACCESS_ACK_DATA:
                        data_out = self.d_data.value.integer
                    elif opcode==TL_A_PUT_FULL and self.d_opcode.value.integer in (TL_D_ACCESS_ACK, TL_D_ACCESS_ACK_DATA):
                        pass
                    if self.d_error.value:
                        raise RuntimeError("[TLULDriver] D error")
                else:
                    if opcode==TL_A_GET and self.d.opcode.value.integer==TL_D_ACCESS_ACK_DATA:
                        data_out = self.d.data.value.integer
                    elif opcode==TL_A_PUT_FULL and self.d.opcode.value.integer in (TL_D_ACCESS_ACK, TL_D_ACCESS_ACK_DATA):
                        pass
                    if self.d.error.value:
                        raise RuntimeError("[TLULDriver] D error")
                break
        return data_out
""")
(OUT/"drivers"/"driver_tlul.py").write_text(driver_tlul)

# test template
tb_py = dedent(f"""\
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

    # Crea bus driver (puoi specificare nomi custom se non standard)
    if ITF == "reg_iface":
        bus = BusDriver(dut, clk_name=TB_CLK, rst_name=TB_RST)
        await bus.reset_idle()
        # Esempio: write/read 0x0
        await bus.write32(0x0, 0x1, 0xF)
        rd = await bus.read32(0x0)
        dut._log.info(f"REG_IFACE read @0x0 = 0x{{rd:08x}}")
    else:
        bus = BusDriver(dut, clk_name=TB_CLK, rst_name=TB_RST)
        await bus._idle()
        await bus.write32(0x0, 0x1, 0xF)
        rd = await bus.read32(0x0)
        dut._log.info(f"TLUL read @0x0 = 0x{{rd:08x}}")

    # Loop esempio
    for i in range(N_OP):
        a,b = utils.rand_bin_values(NBIT)
        _ = a ^ b
        await RisingEdge(clk)
""")
(OUT/f"{TOP}_tb.py").write_text(tb_py)

print(f"Generated in: {OUT.resolve()}")
print("- Makefile")
print(f"- {TOP}_tb.py")
print("- utils.py")
print("- drivers/driver_reg_iface.py")
print("- drivers/driver_tlul.py")

