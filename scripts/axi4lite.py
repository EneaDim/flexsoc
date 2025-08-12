#!/usr/bin/env python3
# gen_axi4lite_struct_regs.py
#
# Genera 3 file SystemVerilog da un HJSON stile OpenTitan:
#  1) axi4lite_pkg.sv                  (struct per canali AXI4-Lite + bundle H2D/D2H)
#  2) <ip>_reg_pkg.sv                  (reg2hw/hw2reg e bundle per ogni registro)
#  3) <module>.sv (default <ip>_reg_top.sv)  (top AXI4-Lite che usa i tipi "a struct")
#
# Ogni riga SV è commentata (disattivabile con --no-line-comments).
#
# Uso:
#   python gen_axi4lite_struct_regs.py uart.hjson \
#     --outdir build \
#     --module uart_reg_top
#
# Dipendenze: pip install hjson
#
import argparse
import hjson
import math
import re
from pathlib import Path
from typing import Dict, List, Tuple, Optional

# -----------------------------------------------------------------------------
# Helpers per nomi/bit/mask
# -----------------------------------------------------------------------------
def to_snake(name: str) -> str:
    s = re.sub(r"[^a-zA-Z0-9]", "_", name)
    s = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", s)
    s = re.sub(r"_+", "_", s)
    return s.lower().strip("_")

def to_upper(name: str) -> str:
    return to_snake(name).upper()

def parse_bits(bits: str) -> Tuple[int, int]:
    bits = str(bits).strip()
    if ":" in bits:
        hi, lo = bits.split(":")
        return int(hi), int(lo)
    else:
        b = int(bits)
        return b, b

def slv_mask_from_bits(bits: str) -> int:
    hi, lo = parse_bits(bits)
    w = hi - lo + 1
    return ((1 << w) - 1) << lo

def hex32(v: int) -> str:
    return f"32'h{v:08x}"

# -----------------------------------------------------------------------------
# Strutture dati per registri/campi
# -----------------------------------------------------------------------------
class Field:
    def __init__(self, name: str, bits: str, resval: Optional[int]):
        self.name = name or ""
        self.bits = bits
        self.resval = resval

class Register:
    def __init__(self, name: str, swaccess: str, fields: List[Field],
                 reset: Optional[int], offset: Optional[int],
                 hwext: bool, hwre: bool, hwqe: bool):
        self.name = name
        self.swaccess = (swaccess or "rw").lower()
        self.fields = fields
        self.reset = reset
        self.offset = offset
        self.hwext = hwext or hwre  # se l'HW può scrivere/fornire, esponi interfaccia
        self.hwre = hwre
        self.hwqe = hwqe

# -----------------------------------------------------------------------------
# Lettura HJSON
# -----------------------------------------------------------------------------
def parse_registers(hj: Dict) -> List[Register]:
    regs = []
    for r in hj.get("registers", []):
        name = r["name"]
        swaccess = r.get("swaccess", "rw")
        fields = []
        for f in r.get("fields", []):
            bits = str(f["bits"])
            fname = f.get("name", "")
            fres = f.get("resval")
            if fres is not None:
                fres = int(str(fres), 0)
            fields.append(Field(fname, bits, fres))
        reg_resval = r.get("resval")
        if reg_resval is not None:
            reg_resval = int(str(reg_resval), 0)
        offset = r.get("offset")
        if offset is not None:
            offset = int(str(offset), 0)
        hwext = str(r.get("hwext", "false")).lower() == "true"
        hwre  = str(r.get("hwre",  "false")).lower() == "true"
        hwqe  = str(r.get("hwqe",  "false")).lower() == "true"
        regs.append(Register(name, swaccess, fields, reg_resval, offset, hwext, hwre, hwqe))
    return regs

def compute_reset(reg: Register) -> int:
    if reg.reset is not None:
        return reg.reset
    v = 0
    for f in reg.fields:
        if f.resval is not None:
            mask = slv_mask_from_bits(f.bits)
            lo = parse_bits(f.bits)[1]
            v = (v & ~mask) | ((f.resval << lo) & mask)
    return v

def map_swaccess(sw: str) -> str:
    lut = {
        "rw": "SwAccessRW",
        "ro": "SwAccessRO",
        "wo": "SwAccessWO",
        "w1c": "SwAccessW1C",
        "w1s": "SwAccessW1S",
        "w0c": "SwAccessW0C",
        "rc": "SwAccessRC",
    }
    return lut.get(sw.lower(), "SwAccessRW")

def assign_offsets(regs: List[Register], base: int = 0, step: int = 4) -> None:
    addr = base
    used = set()
    for r in regs:
        if r.offset is not None:
            if r.offset in used:
                raise ValueError(f"Offset duplicato: {r.name} @ {r.offset:#x}")
            used.add(r.offset)
    for r in regs:
        if r.offset is None:
            while addr in used:
                addr += step
            r.offset = addr
            used.add(addr)
            addr += step

# -----------------------------------------------------------------------------
# Emissione SV con commento-per-riga (opzionale)
# -----------------------------------------------------------------------------
class SVLines:
    def __init__(self, with_comments: bool = True):
        self.lines: List[str] = []
        self.with_comments = with_comments

    def add(self, text: str, comment: str = ""):
        if not self.with_comments:
            self.lines.append(text)
            return
        c = comment if comment else "<no comment>"
        if text.strip() == "":
            self.lines.append(f"// {c}")
        else:
            self.lines.append(f"{text}  // {c}")

    def extend_block(self, pairs: List[Tuple[str, str]]):
        for t, c in pairs:
            self.add(t, c)

    def render(self) -> str:
        return "\n".join(self.lines) + "\n"

# -----------------------------------------------------------------------------
# Emetti axi4lite_pkg.sv
# -----------------------------------------------------------------------------
def emit_axi4lite_pkg(with_comments: bool = True) -> str:
    sv = SVLines(with_comments)
    sv.add("// axi4lite_pkg.sv", "Package per tipi AXI4-Lite")
    sv.add("package axi4lite_pkg;", "Inizio package")
    sv.add("", "Parametri fissi per semplicità (32/32)")
    sv.add("  localparam int AXI_ADDR_W = 32;", "Larghezza indirizzo")
    sv.add("  localparam int AXI_DATA_W = 32;", "Larghezza dati")
    sv.add("  localparam int AXI_STRB_W = AXI_DATA_W/8;", "Larghezza WSTRB")
    sv.add("", "Canale AW: H2D e D2H")
    sv.add("  typedef struct packed {", "AW H2D")
    sv.add("    logic                  valid;", "AWVALID")
    sv.add("    logic [AXI_ADDR_W-1:0] addr;", "AWADDR")
    sv.add("    logic [2:0]            prot;", "AWPROT")
    sv.add("  } aw_h2d_t;", "Tipo AW H2D")
    sv.add("  typedef struct packed {", "AW D2H")
    sv.add("    logic                  ready;", "AWREADY")
    sv.add("  } aw_d2h_t;", "Tipo AW D2H")
    sv.add("", "Canale W: H2D e D2H")
    sv.add("  typedef struct packed {", "W H2D")
    sv.add("    logic                  valid;", "WVALID")
    sv.add("    logic [AXI_DATA_W-1:0] data;", "WDATA")
    sv.add("    logic [AXI_STRB_W-1:0] strb;", "WSTRB")
    sv.add("  } w_h2d_t;", "Tipo W H2D")
    sv.add("  typedef struct packed {", "W D2H")
    sv.add("    logic                  ready;", "WREADY")
    sv.add("  } w_d2h_t;", "Tipo W D2H")
    sv.add("", "Canale B: H2D e D2H")
    sv.add("  typedef struct packed {", "B H2D")
    sv.add("    logic                  ready;", "BREADY")
    sv.add("  } b_h2d_t;", "Tipo B H2D")
    sv.add("  typedef struct packed {", "B D2H")
    sv.add("    logic                  valid;", "BVALID")
    sv.add("    logic [1:0]            resp;", "BRESP")
    sv.add("  } b_d2h_t;", "Tipo B D2H")
    sv.add("", "Canale AR: H2D e D2H")
    sv.add("  typedef struct packed {", "AR H2D")
    sv.add("    logic                  valid;", "ARVALID")
    sv.add("    logic [AXI_ADDR_W-1:0] addr;", "ARADDR")
    sv.add("    logic [2:0]            prot;", "ARPROT")
    sv.add("  } ar_h2d_t;", "Tipo AR H2D")
    sv.add("  typedef struct packed {", "AR D2H")
    sv.add("    logic                  ready;", "ARREADY")
    sv.add("  } ar_d2h_t;", "Tipo AR D2H")
    sv.add("", "Canale R: H2D e D2H")
    sv.add("  typedef struct packed {", "R H2D")
    sv.add("    logic                  ready;", "RREADY")
    sv.add("  } r_h2d_t;", "Tipo R H2D")
    sv.add("  typedef struct packed {", "R D2H")
    sv.add("    logic                  valid;", "RVALID")
    sv.add("    logic [AXI_DATA_W-1:0] data;", "RDATA")
    sv.add("    logic [1:0]            resp;", "RRESP")
    sv.add("  } r_d2h_t;", "Tipo R D2H")
    sv.add("", "Bundle completi")
    sv.add("  typedef struct packed {", "Host -> Device: tutti i canali")
    sv.add("    aw_h2d_t aw;", "AW H2D")
    sv.add("    w_h2d_t  w;", "W  H2D")
    sv.add("    b_h2d_t  b;", "B  H2D")
    sv.add("    ar_h2d_t ar;", "AR H2D")
    sv.add("    r_h2d_t  r;", "R  H2D")
    sv.add("  } axi4lite_h2d_t;", "Bundle H2D")
    sv.add("  typedef struct packed {", "Device -> Host: tutti i canali")
    sv.add("    aw_d2h_t aw;", "AW D2H")
    sv.add("    w_d2h_t  w;", "W  D2H")
    sv.add("    b_d2h_t  b;", "B  D2H")
    sv.add("    ar_d2h_t ar;", "AR D2H")
    sv.add("    r_d2h_t  r;", "R  D2H")
    sv.add("  } axi4lite_d2h_t;", "Bundle D2H")
    sv.add("endpackage : axi4lite_pkg", "Fine package")
    return sv.render()

# -----------------------------------------------------------------------------
# Emetti <ip>_reg_pkg.sv
# -----------------------------------------------------------------------------
def emit_ip_reg_pkg(ip: str, regs: List[Register], with_comments: bool = True) -> str:
    pkg = f"{ip}_reg_pkg"
    sv = SVLines(with_comments)
    sv.add(f"// {pkg}.sv", "Package tipi reg2hw/hw2reg")
    sv.add(f"package {pkg};", "Inizio package")
    sv.add("", "Tipi elementari per singolo registro")
    sv.add("  typedef struct packed {", "Verso HW: valore interno + write pulse")
    sv.add("    logic [31:0] q;", "Valore del registro (flop interno)")
    sv.add("    logic        qe;", "Impulso quando SW scrive il registro")
    sv.add("  } reg2hw_reg_t;", "Tipo reg2hw base")
    sv.add("  typedef struct packed {", "Da HW: candidato aggiornamento")
    sv.add("    logic [31:0] d;", "Dato dall'HW")
    sv.add("    logic        de;", "Abilitazione aggiornamento da HW")
    sv.add("  } hw2reg_reg_t;", "Tipo hw2reg base")
    sv.add("", "Bundle complessivo: verso HW (una entry per registro)")
    sv.add(f"  typedef struct packed {{", "reg2hw bundle")
    for r in regs:
        sv.add(f"    reg2hw_reg_t {to_upper(r.name)};", f"{r.name}")
    sv.add(f"  }} {ip}_reg2hw_t;", "fine reg2hw bundle")
    sv.add("", "Bundle complessivo: da HW (una entry per registro)")
    sv.add(f"  typedef struct packed {{", "hw2reg bundle")
    for r in regs:
        sv.add(f"    hw2reg_reg_t {to_upper(r.name)};", f"{r.name}")
    sv.add(f"  }} {ip}_hw2reg_t;", "fine hw2reg bundle")
    sv.add(f"endpackage : {pkg}", "Fine package")
    return sv.render()

# -----------------------------------------------------------------------------
# Emetti modulo top <module>.sv
# -----------------------------------------------------------------------------
def emit_field_params(sv: SVLines, reg: Register):
    rU = to_upper(reg.name)
    for f in reg.fields:
        if not f.name:
            continue
        fU = to_upper(f.name)
        hi, lo = parse_bits(f.bits)
        mask = slv_mask_from_bits(f.bits)
        sv.add(f"localparam int {rU}_{fU}_HI = {hi};", f"bit alto del campo {reg.name}.{f.name}")
        sv.add(f"localparam int {rU}_{fU}_LO = {lo};", f"bit basso del campo {reg.name}.{f.name}")
        sv.add(f"localparam logic [31:0] {rU}_{fU}_MASK = 32'h{mask:08x};", f"maschera del campo {reg.name}.{f.name}")

def emit_module(hj: Dict, regs: List[Register], module_name: str,
                addr_w: int, aperture_bits: Optional[int],
                with_comments: bool = True) -> str:
    ip = to_snake(hj.get("name", module_name))
    human = hj.get("human_name", ip)
    max_off = max((r.offset for r in regs), default=0)
    ap = aperture_bits if aperture_bits is not None else max(8, math.ceil(math.log2(max_off + 4)))
    ap = max(ap, 6)

    sv = SVLines(with_comments)
    sv.add("// -----------------------------------------------------------------------------", "Header")
    sv.add(f"// {module_name}  —  autogenerated from HJSON (“{human}”)", "Titolo")
    sv.add("// DO NOT EDIT BY HAND", "Generato automaticamente")
    sv.add("// -----------------------------------------------------------------------------", "Fine header")

    sv.add(f"module {module_name}", "Inizio modulo")
    sv.add("#(", "Parametri")
    sv.add(f"  parameter int ADDRESS_W = {addr_w},", "Larghezza indirizzi AXI")
    sv.add(f"  parameter int ADDRESS_APERTURE = {ap}", "Apertura locale indirizzi")
    sv.add(")", "Fine parametri")
    sv.add("(", "Porte")
    sv.add("  input  logic                          clk_i,", "Clock")
    sv.add("  input  logic                          rst_ni,", "Reset attivo basso")
    sv.add("", "Interfaccia verso datapath")
    sv.add(f"  output {ip}_reg_pkg::{ip}_reg2hw_t    reg2hw,", "Bundle verso HW (q, qe per ogni registro)")
    sv.add(f"  input  {ip}_reg_pkg::{ip}_hw2reg_t    hw2reg,", "Bundle da HW (d, de per ogni registro)")
    sv.add("", "AXI4-Lite bundle a struct")
    sv.add("  input  axi4lite_pkg::axi4lite_h2d_t   axi_i,", "Canali host->device")
    sv.add("  output axi4lite_pkg::axi4lite_d2h_t   axi_o", "Canali device->host")
    sv.add(");", "Fine porte")
    sv.add("", "Costanti indirizzi")

    for r in regs:
        sv.add(f"localparam logic [{ap-1}:0] ADDR_{to_upper(r.name)} = {ap}'h{r.offset:0x};", f"Offset di {r.name}")

    sv.add("", "Parametri di campo")
    for r in regs:
        emit_field_params(sv, r)

    sv.add("", "Handshake SW comune")
    sv.add("logic        sw_we;", "Strobo write SW al ciclo Dati")
    sv.add("logic [31:0] sw_wdata;", "Dati di write SW")
    sv.add("logic [31:0] sw_wmask;", "Maschera byte da WSTRB (espansa)")
    sv.add("assign sw_we    = (wstate_q == W_DATA) & axi_i.w.valid & axi_o.w.ready;", "Write effettiva")
    sv.add("assign sw_wmask = {", "Costruzione mask da WSTRB")
    sv.add("  {8{axi_i.w.strb[3]}}, {8{axi_i.w.strb[2]}}, {8{axi_i.w.strb[1]}}, {8{axi_i.w.strb[0]}}", "replica per byte")
    sv.add("};", "Fine mask")
    sv.add("assign sw_wdata = axi_i.w.data;", "assegna WDATA")

    # AXI resp
    sv.add("", "Codici AXI")
    sv.add("localparam logic [1:0] AXI_RESP_OKAY   = 2'b00;", "OKAY")
    sv.add("localparam logic [1:0] AXI_RESP_SLVERR = 2'b10;", "SLVERR")

    # Stati
    sv.add("", "Stati FSM")
    sv.add("typedef enum logic [1:0] {W_RST, W_ADDR, W_DATA, W_RESP} wstate_e;", "Write FSM")
    sv.add("typedef enum logic [1:0] {R_RST, R_ADDR, R_DATA} rstate_e;", "Read FSM")
    sv.add("wstate_e wstate_q, wstate_d;", "Stato write")
    sv.add("rstate_e rstate_q, rstate_d;", "Stato read")
    sv.add(f"logic [{ap-1}:0] wr_addr_q, wr_addr_d;", "Indirizzo write latched")
    sv.add(f"logic [{ap-1}:0] rd_addr_q, rd_addr_d;", "Indirizzo read latched")

    # WRITE FSM comb
    sv.add("", "WRITE FSM — combinazionale")
    sv.add("always_comb begin", "Blocco combinazionale")
    sv.add("  axi_o.aw.ready = 1'b0;", "AWREADY default")
    sv.add("  axi_o.w.ready  = 1'b0;", "WREADY  default")
    sv.add("  axi_o.b.valid  = 1'b0;", "BVALID  default")
    sv.add("  axi_o.b.resp   = AXI_RESP_OKAY;", "BRESP  default")
    sv.add("  wstate_d       = wstate_q;", "Hold state di default")
    sv.add("  wr_addr_d      = wr_addr_q;", "Hold indirizzo")
    sv.add("  unique case (wstate_q)", "Switch stato")
    sv.add("    W_RST:  wstate_d = W_ADDR;", "Dopo reset -> attendi AW")
    sv.add("    W_ADDR: begin", "Accetta AW")
    sv.add("      axi_o.aw.ready = 1'b1;", "AWREADY alto")
    sv.add("      if (axi_i.aw.valid) begin", "Se AWVALID")
    sv.add(f"        wr_addr_d = axi_i.aw.addr[ADDRESS_APERTURE-1:0];", "Cattura indirizzo locale")
    sv.add("        wstate_d  = W_DATA;", "Passa a W_DATA")
    sv.add("      end", "fine if")
    sv.add("    end", "fine W_ADDR")
    sv.add("    W_DATA: begin", "Accetta W")
    sv.add("      axi_o.w.ready = 1'b1;", "WREADY alto")
    sv.add("      if (axi_i.w.valid) begin", "Se WVALID")
    sv.add("        wstate_d = W_RESP;", "Vai a response")
    sv.add("      end", "fine if")
    sv.add("    end", "fine W_DATA")
    sv.add("    W_RESP: begin", "Emetti B")
    sv.add("      axi_o.b.valid = 1'b1;", "BVALID alto")
    sv.add("      if (axi_i.b.ready) begin", "Se BREADY")
    sv.add("        wstate_d = W_ADDR;", "Torna a W_ADDR")
    sv.add("      end", "fine if")
    sv.add("    end", "fine W_RESP")
    sv.add("    default: wstate_d = W_RST;", "Safety default")
    sv.add("  endcase", "Fine case")
    sv.add("end", "Fine always_comb")

    # WRITE FSM seq
    sv.add("", "WRITE FSM — sequenziale")
    sv.add("always_ff @(posedge clk_i or negedge rst_ni) begin", "Flop di stato/addr")
    sv.add("  if (!rst_ni) begin", "Reset")
    sv.add("    wstate_q  <= W_RST;", "Stato iniziale")
    sv.add("    wr_addr_q <= '0;", "Azzera indirizzo")
    sv.add("  end else begin", "Run")
    sv.add("    wstate_q  <= wstate_d;", "Avanza stato")
    sv.add("    wr_addr_q <= wr_addr_d;", "Avanza indirizzo")
    sv.add("  end", "Fine else")
    sv.add("end", "Fine always_ff")

    # READ FSM comb
    sv.add("", "READ FSM — segnali mux")
    sv.add("logic [31:0] rdata_mux;", "Mux dati")
    sv.add("logic [1:0]  rresp_mux;", "Mux resp")
    sv.add("", "READ FSM — combinazionale")
    sv.add("always_comb begin", "Blocco combinazionale")
    sv.add("  axi_o.ar.ready = 1'b0;", "ARREADY default")
    sv.add("  axi_o.r.valid  = 1'b0;", "RVALID default")
    sv.add("  axi_o.r.data   = 32'h0;", "RDATA default")
    sv.add("  axi_o.r.resp   = AXI_RESP_OKAY;", "RRESP default")
    sv.add("  rstate_d       = rstate_q;", "Hold stato")
    sv.add("  rd_addr_d      = rd_addr_q;", "Hold indirizzo")
    sv.add("  unique case (rstate_q)", "Switch stato")
    sv.add("    R_RST:  rstate_d = R_ADDR;", "Dopo reset -> attendi AR")
    sv.add("    R_ADDR: begin", "Accetta AR")
    sv.add("      axi_o.ar.ready = 1'b1;", "ARREADY alto")
    sv.add("      if (axi_i.ar.valid) begin", "Se ARVALID")
    sv.add("        rd_addr_d = axi_i.ar.addr[ADDRESS_APERTURE-1:0];", "Cattura indirizzo locale")
    sv.add("        rstate_d  = R_DATA;", "Vai a dati")
    sv.add("      end", "fine if")
    sv.add("    end", "fine R_ADDR")
    sv.add("    R_DATA: begin", "Emetti dati")
    sv.add("      axi_o.r.valid = 1'b1;", "RVALID alto")
    sv.add("      axi_o.r.data  = rdata_mux;", "Applica mux dati")
    sv.add("      axi_o.r.resp  = rresp_mux;", "Applica mux resp")
    sv.add("      if (axi_i.r.ready) begin", "Se RREADY")
    sv.add("        rstate_d = R_ADDR;", "Torna ad AR")
    sv.add("      end", "fine if")
    sv.add("    end", "fine R_DATA")
    sv.add("    default: rstate_d = R_RST;", "Safety default")
    sv.add("  endcase", "Fine case")
    sv.add("end", "Fine always_comb")

    # READ FSM seq
    sv.add("", "READ FSM — sequenziale")
    sv.add("always_ff @(posedge clk_i or negedge rst_ni) begin", "Flop di stato/addr")
    sv.add("  if (!rst_ni) begin", "Reset")
    sv.add("    rstate_q <= R_RST;", "Stato iniziale")
    sv.add("    rd_addr_q <= '0;", "Azzera indirizzo")
    sv.add("  end else begin", "Run")
    sv.add("    rstate_q <= rstate_d;", "Avanza stato")
    sv.add("    rd_addr_q <= rd_addr_d;", "Avanza indirizzo")
    sv.add("  end", "Fine else")
    sv.add("end", "Fine always_ff")

    # Per-registro: segnali + prim_reg + collegamento a reg2hw/hw2reg
    for r in regs:
        base = to_snake(r.name)
        rU = to_upper(r.name)
        resv = compute_reset(r)
        swacc = map_swaccess(r.swaccess)

        sv.add("", f"Sezione registro {r.name}")
        sv.add(f"logic        {base}_we;", "Write enable locale")
        sv.add(f"logic [31:0] {base}_wd_masked;", "WDATA con mask da WSTRB")
        sv.add(f"logic [31:0] {base}_ds, {base}_qs;", "Uscite SW da prim_reg")
        sv.add(f"logic        {base}_qe;", "Impulso di write")
        sv.add(f"logic [31:0] {base}_q;", "Valore interno")

        sv.add(f"assign {base}_we        = sw_we && (wr_addr_q == ADDR_{rU});", "Selezione indirizzo")
        sv.add(f"assign {base}_wd_masked = ({base}_qs & ~sw_wmask) | (sw_wdata & sw_wmask);", "Merge QS/WDATA via WSTRB")

        # HW side from hw2reg bundle (sempre disponibile)
        sv.add(f"logic        {base}_de;", "Enable HW verso prim_reg")
        sv.add(f"logic [31:0] {base}_d;", "Dato HW verso prim_reg")
        sv.add(f"assign {base}_de = hw2reg.{rU}.de;", "Collega de")
        sv.add(f"assign {base}_d  = hw2reg.{rU}.d;", "Collega d")

        sv.add("prim_reg #(", "Istanza prim_reg")
        sv.add("  .DW(32),", "Datasize")
        sv.add(f"  .RESVAL({hex32(resv)}),", "Reset value")
        sv.add(f"  .SwAccess(prim_reg_pkg::{swacc})", "Accesso SW")
        sv.add(f") u_{base} (", "Inizio porta")
        sv.add("  .clk_i (clk_i),", "Clock")
        sv.add("  .rst_ni(rst_ni),", "Reset")
        sv.add(f"  .we    ({base}_we),", "WE SW")
        sv.add(f"  .wd    ({base}_wd_masked),", "WD SW masked")
        sv.add(f"  .ds    ({base}_ds),", "DS")
        sv.add(f"  .qs    ({base}_qs),", "QS")
        sv.add(f"  .de    ({base}_de),", "DE HW")
        sv.add(f"  .d     ({base}_d),", "D  HW")
        sv.add(f"  .qe    ({base}_qe),", "QE")
        sv.add(f"  .q     ({base}_q)", "Q")
        sv.add(");", "Fine istanza")

        # Popola reg2hw bundle
        sv.add(f"assign reg2hw.{rU}.qe = {base}_qe;", "Esporta QE")
        sv.add(f"assign reg2hw.{rU}.q  = {base}_q;", "Esporta Q")

    # Read mux
    sv.add("", "READ mux su indirizzo")
    sv.add("always_comb begin", "Mux combinazionale")
    sv.add("  unique case (rd_addr_q)", "Selezione indirizzo")
    for r in regs:
        base = to_snake(r.name)
        rU = to_upper(r.name)
        sv.add(f"    ADDR_{rU}: begin rdata_mux = {base}_qs; rresp_mux = AXI_RESP_OKAY; end", f"Lettura {r.name}")
    sv.add("    default: begin rdata_mux = 32'h0; rresp_mux = AXI_RESP_SLVERR; end", "Indirizzo non mappato")
    sv.add("  endcase", "Fine case")
    sv.add("end", "Fine always_comb")

    # BRESP decode
    sv.add("", "BRESP in base all'indirizzo scritto")
    sv.add("always_comb begin", "Combinazionale BRESP")
    sv.add("  axi_o.b.resp = AXI_RESP_SLVERR;", "Default errore")
    sv.add("  unique case (wr_addr_q)", "Case su write address")
    for r in regs:
        rU = to_upper(r.name)
        sv.add(f"    ADDR_{rU}: axi_o.b.resp = AXI_RESP_OKAY;", f"Write valida su {r.name}")
    sv.add("    default: axi_o.b.resp = AXI_RESP_SLVERR;", "Indirizzo non valido")
    sv.add("  endcase", "Fine case")
    sv.add("end", "Fine always_comb")
    sv.add("", "Chiusura")
    sv.add("endmodule", "Fine modulo")
    return sv.render()

# -----------------------------------------------------------------------------
# MAIN
# -----------------------------------------------------------------------------
def main():
    ap = argparse.ArgumentParser(description="Generate AXI4-Lite (struct) regfile from HJSON (with per-line comments)")
    ap.add_argument("hjson", type=Path, help="Input HJSON file")
    ap.add_argument("--outdir", type=Path, default=Path("."), help="Output directory (default: .)")
    ap.add_argument("--module", type=str, default=None, help="Top module name (default: <ip>_reg_top)")
    ap.add_argument("--addr-width", type=int, default=32, help="AXI address width (fixed at 32 in pkg)")
    ap.add_argument("--aperture", type=int, default=None, help="Local address aperture bits (auto if omitted)")
    ap.add_argument("--no-line-comments", action="store_true", help="Disable per-line comments in SV")
    args = ap.parse_args()

    with args.hjson.open("r", encoding="utf-8") as f:
        hj = hjson.load(f)

    regs = parse_registers(hj)
    if not regs:
        raise SystemExit("Nessun registro trovato in 'registers'.")

    assign_offsets(regs)

    ip = to_snake(hj.get("name", "ip"))
    module_name = args.module or f"{ip}_reg_top"

    with_comments = not args.no_line_comments

    # Genera i 3 file
    args.outdir.mkdir(parents=True, exist_ok=True)
    axi_pkg_path = args.outdir / "axi4lite_pkg.sv"
    ip_pkg_path  = args.outdir / f"{ip}_reg_pkg.sv"
    top_path     = args.outdir / f"{module_name}.sv"

    axi_pkg = emit_axi4lite_pkg(with_comments=with_comments)
    ip_pkg  = emit_ip_reg_pkg(ip, regs, with_comments=with_comments)
    top_sv  = emit_module(hj, regs, module_name, addr_w=args.addr_width,
                          aperture_bits=args.aperture, with_comments=with_comments)

    axi_pkg_path.write_text(axi_pkg, encoding="utf-8")
    ip_pkg_path.write_text(ip_pkg, encoding="utf-8")
    top_path.write_text(top_sv, encoding="utf-8")

    print(f"[ok] Generated:\n  {axi_pkg_path}\n  {ip_pkg_path}\n  {top_path}")

if __name__ == "__main__":
    main()

