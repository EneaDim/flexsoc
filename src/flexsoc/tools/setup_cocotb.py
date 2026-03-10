# ruff: noqa
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

from __future__ import annotations

import argparse
import re
from pathlib import Path
from textwrap import dedent
from typing import Iterable

from .common import build_ordered_sources


def repo_root() -> Path:
    return Path(__file__).resolve().parents[3]


def parse_args() -> argparse.Namespace:
    ap = argparse.ArgumentParser(description="Generate cocotb skeleton + Makefile from RTL scan")
    ap.add_argument("--top", "-top", required=True, help="Top module name (without .sv)")
    ap.add_argument(
        "--itf",
        "-itf",
        required=True,
        choices=["reg_iface", "tlul"],
        help="Register interface: reg_iface or tlul",
    )
    ap.add_argument("--output", "-o", default="tb/cocotb", help="Output folder (default: tb/cocotb)")
    ap.add_argument("--vsv", choices=["sv", "v"], default="sv", help="SV/V flow (default: sv)")
    ap.add_argument("--rtl-dir", default="rtl", help="RTL directory")
    ap.add_argument("--ips-root", default=None, help="IP root (default: <repo>/hw/ips)")
    ap.add_argument(
        "--sim",
        choices=["verilator", "icarus", "questa", "vcs", "xcelium"],
        default="verilator",
        help="Simulator (default: verilator)",
    )
    ap.add_argument("--clk", default="clk_i", help="Clock signal name (default: clk_i)")
    ap.add_argument("--rst", default="rst_ni", help="Reset signal name (default: rst_ni)")
    ap.add_argument("--rst-active", choices=["low", "high"], default="low", help="Reset polarity (default: low)")
    ap.add_argument("--period-ns", type=float, default=10.0, help="Clock period ns (default: 10)")
    ap.add_argument("--nbit", type=int, default=32, help="Default NBIT")
    ap.add_argument("--n-op", type=int, default=10, help="Loop iterations")
    return ap.parse_args()


def makefile_block_from_paths(paths: Iterable[Path], *, var_name: str = "VERILOG_SOURCES") -> str:
    seen = set()
    ordered: list[str] = []

    for p in paths:
        item = str(Path(p).resolve())
        if item not in seen:
            seen.add(item)
            ordered.append(item)

    if not ordered:
        return f"{var_name} :="

    lines = [f"{var_name} := \\"]
    for item in ordered[:-1]:
        lines.append(f"  {item} \\")
    lines.append(f"  {ordered[-1]}")
    return "\n".join(lines)


def read_top_path(rtl_dir: Path, top: str) -> Path | None:
    cand = rtl_dir / f"{top}.sv"
    if cand.exists():
        return cand
    for p in rtl_dir.rglob("*.sv"):
        if p.stem == top:
            return p
    return None


def parse_top_ports(top_file: Path) -> dict:
    try:
        text = top_file.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return {"clk": [], "rst": [], "inputs": [], "outputs": [], "parameters": {}, "localparams": {}}

    m = re.search(r"module\s+\w+\s*\((.*?)\);\s", text, flags=re.S | re.M)
    if not m:
        header_text = text.split(");", 1)[0]
    else:
        header_text = m.group(1)

    lines = [re.sub(r"//.*", "", ln).strip() for ln in header_text.splitlines()]
    lines = [ln for ln in lines if ln]

    clk, rst = [], []
    inputs, input_w = [], []
    outputs, output_w = [], []

    def parse_decl(prefix: str, line: str):
        body = line[len(prefix):].strip()
        toks = body.split()
        if not toks:
            return None, []
        if toks[0] in ("logic", "wire", "reg"):
            toks = toks[1:]
            if not toks:
                return None, []
        width_tok = None
        if toks and toks[0].startswith("["):
            width_tok = toks[0]
            toks = toks[1:]
        names = [t.rstrip(",") for t in toks if t.rstrip(",")]
        return width_tok if width_tok else 1, names

    for ln in lines:
        if ln.startswith("input "):
            w, names = parse_decl("input ", ln)
            if names:
                for n in names:
                    if "clk" in n:
                        clk.append(n)
                    if "rst" in n:
                        rst.append(n)
                    inputs.append(n)
                    input_w.append(w)
        elif ln.startswith("output "):
            w, names = parse_decl("output ", ln)
            if names:
                for n in names:
                    outputs.append(n)
                    output_w.append(w)

    return {
        "clk": clk,
        "rst": rst,
        "inputs": [{"name": n, "width": input_w[i]} for i, n in enumerate(inputs)],
        "outputs": [{"name": n, "width": output_w[i]} for i, n in enumerate(outputs)],
        "parameters": {},
        "localparams": {},
    }


def make_other_port_decls(info: dict) -> tuple[list[str], str]:
    ctrl = set(info.get("clk", [])) | set(info.get("rst", [])) | {"tl_i", "tl_o"}

    def wdecl(w):
        return "logic" if (w == 1 or str(w) == "1") else f"logic {w}"

    names: list[str] = []
    decls: list[str] = []

    for e in info.get("inputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        names.append(n)
        decls.append(f"  {wdecl(e.get('width', 1))} {n};")

    for e in info.get("outputs", []):
        n = e.get("name", "")
        if not n or n in ctrl or n.startswith(("clk", "rst")) or "::" in n:
            continue
        names.append(n)
        decls.append(f"  {wdecl(e.get('width', 1))} {n};")

    return names, "\n".join(decls)


def emit_makefile(args: argparse.Namespace, out_dir: Path, ordered_sources: list[Path], rtl_dir: Path) -> None:
    top = args.top
    repo = repo_root()
    inc_pkgs = repo / "hw/ips/pkgs"
    inc_prim = repo / "hw/ips/prim"
    inc_prim_ot = repo / "hw/ips/prim_opentitan"
    inc_tlul = repo / "hw/ips/tlul"

    verilog_block = makefile_block_from_paths(ordered_sources)

    mk = dedent(
        f"""\
        # Auto-generated Makefile
        SIM               ?= {args.sim}
        TOPLEVEL_LANG     ?= verilog

        PWD               := $(shell pwd)
        TOPLEVEL          = {top}_tb
        MODULE            = {top}_tb

        ifneq ($(filter clean veryclean distclean,$(MAKECMDGOALS)),)
          SIM := icarus
        endif

        ifeq ($(GATES),yes)
          SIM := icarus
        else
          SIM ?= {args.sim}
        endif

        SIM_BUILD         ?= sim_build/rtl

        ifneq ($(GATES),yes)

        {verilog_block}

        COMPILE_ARGS += --sv --timing
        COMPILE_ARGS += --trace --trace-fst --trace-structs
        COMPILE_ARGS += -Wno-WIDTHEXPAND
        COMPILE_ARGS += -Wno-WIDTHTRUNC
        COMPILE_ARGS += -Wno-UNOPTFLAT

        else
        SIM_BUILD         ?= sim_build/gl
        COMPILE_ARGS      += -DFUNCTIONAL -DUSE_POWER_PINS -DSIM -DUNIT_DELAY=#1
        VERILOG_SOURCES   += ../../verilog/primitives.v
        VERILOG_SOURCES   += ../../verilog/sky130_fd_sc_hd.v
        VERILOG_SOURCES   += ../../syn/{top}_synth.v
        endif

        COMPILE_ARGS += -I{rtl_dir.resolve()} -I{inc_pkgs} -I{inc_prim} -I{inc_prim_ot} -I{inc_tlul}

        export COCOTB_RESULTS_FILE ?= $(abspath results.xml)

        VERILOG_SOURCES += {(out_dir / f"{top}_tb.sv").resolve()}

        include $(shell cocotb-config --makefiles)/Makefile.sim
        """
    )
    (out_dir / "Makefile").write_text(mk, encoding="utf-8")


def emit_utils(out_dir: Path) -> None:
    (out_dir / "utils.py").write_text(
        dedent(
            """\
            import random

            def rand_bin_values(nbit: int):
                a = random.randint(0, (1 << nbit) - 1)
                b = random.randint(0, (1 << nbit) - 1)
                return a, b
            """
        ),
        encoding="utf-8",
    )
    (out_dir / "__init__.py").write_text("", encoding="utf-8")


def emit_reg_driver(out_dir: Path) -> None:
    (out_dir / "drivers" / "driver_reg_iface.py").write_text(
        dedent(
            """\
            from cocotb.triggers import RisingEdge


            class RegIFDriver:
                def __init__(self, dut, clk_name="clk_i", rst_name="rst_ni", req_base=None, rsp_base=None):
                    self.dut = dut
                    self.clk = getattr(dut, clk_name)
                    self.rst = getattr(dut, rst_name)
                    self.req = getattr(dut, req_base, None) if req_base else getattr(dut, "reg_req_i", None) or getattr(dut, "reg_req", None)
                    self.rsp = getattr(dut, rsp_base, None) if rsp_base else getattr(dut, "reg_rsp_o", None) or getattr(dut, "reg_rsp", None)
                    self.struct = self.req is not None and hasattr(self.req, "valid") and hasattr(self.rsp, "ready")
                    if not self.struct:
                        try:
                            self.req_valid = getattr(dut, "reg_req_valid")
                            self.req_write = getattr(dut, "reg_req_write")
                            self.req_addr = getattr(dut, "reg_req_addr")
                            self.req_wdata = getattr(dut, "reg_req_wdata")
                            self.req_wstrb = getattr(dut, "reg_req_wstrb")
                            self.rsp_rdata = getattr(dut, "reg_rsp_rdata")
                            self.rsp_error = getattr(dut, "reg_rsp_error")
                            self.rsp_ready = getattr(dut, "reg_rsp_ready")
                        except AttributeError as e:
                            raise RuntimeError(f"[RegIFDriver] Missing reg_if signals: {e}")

                async def reset_idle(self):
                    if self.struct:
                        self.req.valid.value = 0
                        self.req.write.value = 0
                        self.req.addr.value = 0
                        self.req.wdata.value = 0
                        self.req.wstrb.value = 0
                    else:
                        self.req_valid.value = 0
                        self.req_write.value = 0
                        self.req_addr.value = 0
                        self.req_wdata.value = 0
                        self.req_wstrb.value = 0
                    await RisingEdge(self.clk)

                async def write32(self, addr: int, data: int, wstrb: int = 0xF):
                    if self.struct:
                        self.req.addr.value = addr
                        self.req.wdata.value = data
                        self.req.wstrb.value = wstrb
                        self.req.write.value = 1
                        self.req.valid.value = 1
                    else:
                        self.req_addr.value = addr
                        self.req_wdata.value = data
                        self.req_wstrb.value = wstrb
                        self.req_write.value = 1
                        self.req_valid.value = 1

                    while True:
                        await RisingEdge(self.clk)
                        ready = self.rsp.ready.value.integer if self.struct else self.rsp_ready.value.integer
                        if ready:
                            break

                    if self.struct:
                        self.req.valid.value = 0
                        self.req.write.value = 0
                    else:
                        self.req_valid.value = 0
                        self.req_write.value = 0

                    await RisingEdge(self.clk)

                async def read32(self, addr: int) -> int:
                    if self.struct:
                        self.req.addr.value = addr
                        self.req.wdata.value = 0
                        self.req.wstrb.value = 0
                        self.req.write.value = 0
                        self.req.valid.value = 1
                    else:
                        self.req_addr.value = addr
                        self.req_wdata.value = 0
                        self.req_wstrb.value = 0
                        self.req_write.value = 0
                        self.req_valid.value = 1

                    data = 0
                    while True:
                        await RisingEdge(self.clk)
                        ready = self.rsp.ready.value.integer if self.struct else self.rsp_ready.value.integer
                        if ready:
                            data = self.rsp.rdata.value.integer if self.struct else self.rsp_rdata.value.integer
                            break

                    if self.struct:
                        if self.rsp.error.value.integer:
                            raise RuntimeError("[RegIFDriver] Read error")
                        self.req.valid.value = 0
                    else:
                        if self.rsp_error.value.integer:
                            raise RuntimeError("[RegIFDriver] Read error")
                        self.req_valid.value = 0

                    await RisingEdge(self.clk)
                    return data
            """
        ),
        encoding="utf-8",
    )


def emit_tlul_driver(out_dir: Path) -> None:
    (out_dir / "drivers" / "driver_tlul.py").write_text(
        dedent(
            """\
            import os
            from cocotb.triggers import RisingEdge

            TL_A_PUT_FULL = 0
            TL_A_GET = 4
            TL_D_ACCESS_ACK_DATA = 1


            def _get_attr(obj, name):
                try:
                    return getattr(obj, name)
                except AttributeError:
                    return None


            def _descend(scope_root, dotted):
                node = scope_root
                if not dotted:
                    return node
                for part in dotted.split("."):
                    node = _get_attr(node, part)
                    if node is None:
                        return None
                return node


            def _candidates(prefix, suffix):
                if prefix == "":
                    return [suffix]
                return [f"{prefix}_{suffix}", f"{prefix}__{suffix}"]


            def _find_many_flat(root, prefix, mapping):
                found = {}
                for key, sfx in mapping.items():
                    h = None
                    for cand in _candidates(prefix, sfx):
                        h = _get_attr(root, cand)
                        if h is not None:
                            break
                    if h is None:
                        return None
                    found[key] = h
                return found


            def _autodetect_prefix(root, want_suffix):
                for h in root:
                    name = getattr(h, "_name", "")
                    if name.endswith(want_suffix):
                        idx = name.rfind(want_suffix)
                        prefix = name[: max(0, idx - 1)]
                        if prefix.endswith("_"):
                            prefix = prefix[:-1]
                        return prefix
                return None


            class TLULDriver:
                def __init__(self, dut, clk_name="clk_i", rst_name="rst_ni", a_prefix=None, d_prefix=None, scope=None):
                    self.dut = dut
                    self.clk = getattr(dut, clk_name)
                    self.rst = getattr(dut, rst_name)

                    scope = scope or os.getenv("TB_TL_SCOPE", "")
                    root = _descend(dut, scope)
                    if root is None:
                        raise RuntimeError(f"[TLULDriver] TB_TL_SCOPE='{scope}' not found")

                    a_prefix = a_prefix if a_prefix is not None else os.getenv("TB_TL_A_PREFIX", "tl_i")
                    d_prefix = d_prefix if d_prefix is not None else os.getenv("TB_TL_D_PREFIX", "tl_o")

                    a_map = {
                        "a_valid": "a_valid",
                        "a_opcode": "a_opcode",
                        "a_param": "a_param",
                        "a_size": "a_size",
                        "a_source": "a_source",
                        "a_address": "a_address",
                        "a_mask": "a_mask",
                        "a_data": "a_data",
                        "d_ready": "d_ready",
                    }
                    d_map = {
                        "a_ready": "a_ready",
                        "d_valid": "d_valid",
                        "d_opcode": "d_opcode",
                        "d_data": "d_data",
                        "d_error": "d_error",
                    }

                    a_handles = _find_many_flat(root, a_prefix, a_map)
                    d_handles = _find_many_flat(root, d_prefix, d_map)

                    if a_handles is None or d_handles is None:
                        tli = _get_attr(root, "tl_i")
                        tlo = _get_attr(root, "tl_o")
                        if tli is not None and tlo is not None:
                            need_a = ["a_valid", "a_opcode", "a_param", "a_size", "a_source", "a_address", "a_mask", "a_data", "d_ready"]
                            need_d = ["a_ready", "d_valid", "d_opcode", "d_data", "d_error"]
                            if all(_get_attr(tli, n) is not None for n in need_a) and all(_get_attr(tlo, n) is not None for n in need_d):
                                a_handles = {n: _get_attr(tli, n) for n in need_a}
                                d_handles = {n: _get_attr(tlo, n) for n in need_d}

                    if a_handles is None or d_handles is None:
                        if a_handles is None:
                            auto_a = _autodetect_prefix(root, "a_valid")
                            if auto_a:
                                a_prefix = auto_a
                                a_handles = _find_many_flat(root, a_prefix, a_map)
                        if d_handles is None:
                            auto_d = _autodetect_prefix(root, "d_valid")
                            if auto_d:
                                d_prefix = auto_d
                                d_handles = _find_many_flat(root, d_prefix, d_map)

                    if a_handles is None or d_handles is None:
                        child_names = [getattr(h, "_name", "") for h in root]
                        hints = [n for n in child_names if ("tl" in n or "_a_" in n or "_d_" in n or n in ("tl_i", "tl_o"))]
                        raise RuntimeError(f"[TLULDriver] Missing TL-UL signals. hints={hints}")

                    self.a_valid = a_handles["a_valid"]
                    self.a_ready = d_handles["a_ready"]
                    self.a_opcode = a_handles["a_opcode"]
                    self.a_param = a_handles["a_param"]
                    self.a_size = a_handles["a_size"]
                    self.a_source = a_handles["a_source"]
                    self.a_address = a_handles["a_address"]
                    self.a_mask = a_handles["a_mask"]
                    self.a_data = a_handles["a_data"]
                    self.d_ready = a_handles["d_ready"]
                    self.d_valid = d_handles["d_valid"]
                    self.d_opcode = d_handles["d_opcode"]
                    self.d_data = d_handles["d_data"]
                    self.d_error = d_handles["d_error"]

                async def _idle(self):
                    self.a_valid.value = 0
                    self.a_opcode.value = 0
                    self.a_param.value = 0
                    self.a_size.value = 2
                    self.a_source.value = 0
                    self.a_address.value = 0
                    self.a_mask.value = 0
                    self.a_data.value = 0
                    self.d_ready.value = 1
                    await RisingEdge(self.clk)

                async def write32(self, addr: int, data: int, mask: int = 0xF):
                    await self._do_tx(addr, data, mask, TL_A_PUT_FULL)

                async def read32(self, addr: int) -> int:
                    return await self._do_tx(addr, 0, 0x0, TL_A_GET)

                async def _do_tx(self, addr: int, data: int, mask: int, opcode: int) -> int:
                    self.a_address.value = addr
                    self.a_data.value = data
                    self.a_mask.value = mask
                    self.a_param.value = 0
                    self.a_size.value = 2
                    self.a_source.value = 0
                    self.a_opcode.value = opcode
                    self.a_valid.value = 1

                    for _ in range(10000):
                        await RisingEdge(self.clk)
                        if int(self.a_ready.value):
                            break
                    else:
                        raise RuntimeError("[TLULDriver] Timeout waiting a_ready")

                    self.a_valid.value = 0

                    data_out = 0
                    for _ in range(10000):
                        await RisingEdge(self.clk)
                        if int(self.d_valid.value):
                            if opcode == TL_A_GET and int(self.d_opcode.value) == TL_D_ACCESS_ACK_DATA:
                                data_out = int(self.d_data.value)
                            if int(self.d_error.value):
                                raise RuntimeError("[TLULDriver] d_error=1")
                            break
                    else:
                        raise RuntimeError("[TLULDriver] Timeout waiting d_valid")

                    return data_out
            """
        ),
        encoding="utf-8",
    )


def emit_test(args: argparse.Namespace, out_dir: Path) -> None:
    top = args.top
    (out_dir / f"{top}_tb.py").write_text(
        dedent(
            f"""\
            import os
            import cocotb
            from cocotb.clock import Clock
            from cocotb.triggers import RisingEdge

            ITF = os.getenv("ITF", "{args.itf}")
            CLK_PERIOD_NS = float(os.getenv("CLK_PERIOD_NS", "{args.period_ns}"))
            TB_CLK = os.getenv("TB_CLK", "{args.clk}")
            TB_RST = os.getenv("TB_RST", "{args.rst}")
            TB_RST_ACTIVE = os.getenv("TB_RST_ACTIVE", "{args.rst_active}")

            if ITF == "reg_iface":
                from drivers.driver_reg_iface import RegIFDriver as BusDriver
            elif ITF == "tlul":
                from drivers.driver_tlul import TLULDriver as BusDriver
            else:
                raise RuntimeError(f"Unsupported ITF: {{ITF}}")


            async def reset(dut, cycles: int = 2):
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
            async def {top}_smoke_test(dut):
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
                    addr = 0x0
                    wdata = 0x1
                    await bus.write32(addr, wdata, 0xF)
                    dut._log.info(f"TLUL WRITE32 @0x{{addr:08x}} = 0x{{wdata:08x}} OK")
                    rd = await bus.read32(addr)
                    dut._log.info(f"TLUL READ32  @0x{{addr:08x}} -> 0x{{rd:08x}}")

                for _ in range(5):
                    await RisingEdge(clk)
            """
        ),
        encoding="utf-8",
    )


def emit_tlul_wrapper(args: argparse.Namespace, out_dir: Path, rtl_dir: Path) -> None:
    top = args.top
    top_path = read_top_path(rtl_dir, top)
    port_info = parse_top_ports(top_path) if top_path else {"clk": [], "rst": [], "inputs": [], "outputs": []}
    _, other_decls = make_other_port_decls(port_info)

    wrap = dedent(
        f"""\
        `timescale 1ns/1ps
        module {top}_tb;
          logic {args.clk};
          logic {args.rst};
        {other_decls}

          logic                       tl_i_a_valid;
          tlul_pkg::tl_a_op_e         tl_i_a_opcode;
          logic [2:0]                 tl_i_a_param;
          logic [top_pkg::TL_SZW-1:0] tl_i_a_size;
          logic [top_pkg::TL_AIW-1:0] tl_i_a_source;
          logic [top_pkg::TL_AW-1:0]  tl_i_a_address;
          logic [top_pkg::TL_DBW-1:0] tl_i_a_mask;
          logic [top_pkg::TL_DW-1:0]  tl_i_a_data;
          logic                       tl_i_d_ready;

          logic                       tl_o_d_valid;
          tlul_pkg::tl_d_op_e         tl_o_d_opcode;
          logic [top_pkg::TL_DW-1:0]  tl_o_d_data;
          logic                       tl_o_d_error;
          logic                       tl_o_a_ready;

          tlul_pkg::tl_h2d_t tl_i;
          tlul_pkg::tl_d2h_t tl_o;

          assign tl_i.a_valid   = tl_i_a_valid;
          assign tl_i.a_opcode  = tl_i_a_opcode;
          assign tl_i.a_param   = tl_i_a_param;
          assign tl_i.a_size    = tl_i_a_size;
          assign tl_i.a_source  = tl_i_a_source;
          assign tl_i.a_address = tl_i_a_address;
          assign tl_i.a_mask    = tl_i_a_mask;
          assign tl_i.a_data    = tl_i_a_data;
          assign tl_i.d_ready   = tl_i_d_ready;

          logic [tlul_pkg::H2DCmdIntgWidth-1:0] cmd_intg_calc;
          logic [tlul_pkg::DataIntgWidth-1:0]   data_intg_calc;

          always_comb begin
            tlul_pkg::tl_h2d_t t = '0;
            t.a_address         = tl_i_a_address;
            t.a_opcode          = tl_i_a_opcode;
            t.a_mask            = tl_i_a_mask;
            t.a_user.instr_type = prim_mubi_pkg::MuBi4False;
            cmd_intg_calc       = tlul_pkg::get_cmd_intg(t);
            data_intg_calc      = tlul_pkg::get_data_intg(tl_i_a_data);
          end

          assign tl_i.a_user.instr_type = prim_mubi_pkg::MuBi4False;
          assign tl_i.a_user.cmd_intg   = cmd_intg_calc;
          assign tl_i.a_user.data_intg  = data_intg_calc;

          assign tl_o_d_valid  = tl_o.d_valid;
          assign tl_o_d_opcode = tl_o.d_opcode;
          assign tl_o_d_data   = tl_o.d_data;
          assign tl_o_d_error  = tl_o.d_error;
          assign tl_o_a_ready  = tl_o.a_ready;

          initial begin
            $dumpfile("{top}_tb.vcd");
            $dumpvars(0, {top}_tb);
            #1;
          end

          `ifndef VERILATOR
            initial begin
              string sdf = "../../signoff/sdf/{top}_ss.sdf";
              $sdf_annotate(sdf, {top}_tb.u_{top}, , , "MAXIMUM");
            end
          `endif

          {top} u_{top} (
            .{args.clk}({args.clk}),
            .{args.rst}({args.rst}),
            .tl_i(tl_i),
            .tl_o(tl_o),
            .*
          );

        endmodule
        """
    )
    (out_dir / f"{top}_tb.sv").write_text(wrap, encoding="utf-8")


def main() -> None:
    args = parse_args()

    top = args.top
    out_dir = Path(args.output).resolve()
    rtl_dir = Path(args.rtl_dir).resolve()
    ips_root = Path(args.ips_root).resolve() if args.ips_root else (repo_root() / "hw/ips").resolve()

    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "drivers").mkdir(parents=True, exist_ok=True)

    ordered_sources = build_ordered_sources(top, rtl_dir, ips_root)

    emit_makefile(args, out_dir, ordered_sources, rtl_dir)
    emit_utils(out_dir)
    emit_reg_driver(out_dir)
    emit_tlul_driver(out_dir)
    emit_test(args, out_dir)

    if args.itf == "tlul":
        emit_tlul_wrapper(args, out_dir, rtl_dir)

    print(f"Generated in: {out_dir}")
    print("- Makefile")
    print(f"- {top}_tb.py")
    print("- utils.py")
    print("- drivers/driver_reg_iface.py")
    print("- drivers/driver_tlul.py")
    if args.itf == "tlul":
        print(f"- Wrapper: {out_dir / f'{top}_tb.sv'}")


if __name__ == "__main__":
    main()
