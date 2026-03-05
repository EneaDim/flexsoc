# ruff: noqa
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
\file common.py
\brief Shared helpers for flexsoc scripts (color, I/O, RTL parsing, source lists).
"""

from __future__ import annotations
import os
import sys
import re
from pathlib import Path
from typing import Dict, List, Tuple, Any, Iterable

# -------------------------
# Terminal color
# -------------------------
def colorize(s: str, color_code: str = "\033[38;5;214m") -> str:
    if not sys.stdout.isatty() or os.environ.get("NO_COLOR"):
        return s
    return f"{color_code}{s}\033[0m"

# -------------------------
# Filesystem helpers
# -------------------------
def ensure_dir(path: str | os.PathLike[str]) -> None:
    Path(path).mkdir(parents=True, exist_ok=True)

def safe_write_file(path: str | os.PathLike[str], content: str, *, overwrite: bool = False) -> None:
    p = Path(path)
    if p.exists() and not overwrite:
        raise FileExistsError(str(p))
    p.write_text(content, encoding="utf-8")

# -------------------------
# SystemVerilog lite parsing
# -------------------------
def _strip_line_comment(line: str) -> str:
    return line.split('//', 1)[0] if '//' in line else line

def _read_module_header_text(sv_path: Path) -> str:
    text = sv_path.read_text(encoding="utf-8", errors="ignore")
    i = text.find("module")
    if i != -1: text = text[i:]
    j = text.find(");")
    if j != -1: text = text[:j+2]

    out, in_block, k = [], False, 0
    while k < len(text):
        if not in_block and text.startswith("/*", k): in_block, k = True, k+2; continue
        if  in_block and text.startswith("*/", k): in_block, k = False, k+2; continue
        if not in_block: out.append(text[k])
        k += 1
    return "\n".join(_strip_line_comment(l) for l in "".join(out).splitlines())

def parse_sv_signature(rtldir: str, top: str) -> Dict[str, Any]:
    sv = Path(rtldir) / f"{top}.sv"
    if not sv.exists():
        raise FileNotFoundError(str(sv))
    lines = _read_module_header_text(sv).splitlines()

    parameters: List[Tuple[str,str]] = []
    localparams: List[Tuple[str,str]] = []
    ports_in: List[Tuple[str,Any]] = []
    ports_out: List[Tuple[str,Any]] = []
    clks: List[str] = []
    rsts: List[str] = []

    def push_param(line: str, kind: str) -> None:
        if "=" not in line: return
        l, r = line.split("=", 1)
        name = l.split()[-1].strip()
        val  = r.strip().rstrip(",)")
        (parameters if kind=="parameter" else localparams).append((name, val))

    def push_port(line: str, direction: str) -> None:
        toks = line.strip().rstrip(",)").split()
        if not toks: return
        if toks and toks[0] in ("input","output"): toks = toks[1:]
        if toks and toks[0] == "logic": toks = toks[1:]
        if not toks: return
        width = toks[-2] if len(toks) >= 2 else 1
        name  = toks[-1].rstrip(",")
        (ports_in if direction=="in" else ports_out).append((name, width))
        if "clk_" in name: clks.append(name)
        if "rst_" in name: rsts.append(name)

    for raw in lines:
        line = raw.strip()
        if not line: continue
        if "parameter" in line and "localparam" not in line:
            push_param(line, "parameter")
        elif "localparam" in line:
            push_param(line, "localparam")
        elif line.startswith("input"):
            push_port(line, "in")
        elif line.startswith("output"):
            push_port(line, "out")

    return {
        "parameters": parameters, "localparams": localparams,
        "ports_in": ports_in, "ports_out": ports_out,
        "clks": clks, "rsts": rsts,
    }

def has_reg_pkg(rtldir: str, top: str) -> bool:
    return (Path(rtldir) / f"{top}_reg_pkg.sv").exists()

# -------------------------
# Discovery helpers
# -------------------------
def list_hdl_files(root: str | os.PathLike, *, recursive: bool = True) -> List[Path]:
    rootp = Path(root)
    if not rootp.exists(): return []
    exts = {".sv",".v",".vh",".svh"}
    it: Iterable[Path] = rootp.rglob("*") if recursive else rootp.glob("*")
    files = [p.resolve() for p in it if p.is_file() and p.suffix.lower() in exts]
    return sorted(set(files))

def find_top_sv(rtldir: str | os.PathLike, top: str) -> Path | None:
    p = Path(rtldir) / f"{top}.sv"
    return p if p.exists() else None

# -------------------------
# Fixed IP sources (OpenTitan prims/tlul) builder
# -------------------------
def fixed_ip_paths(ips_root: str | os.PathLike) -> List[Path]:
    """
    Returns the ordered list of *existing* IP source files starting from ips_root.
    Packages are listed first and included even if they don't exist (to match user expectation).
    Non-package files are included only if present. Order mirrors user's requested block.
    """
    IPS = Path(ips_root)
    pkgs = [
        IPS/"pkgs"/"top_pkg.sv",
        IPS/"prim"/"prim_reg_pkg.sv",
        IPS/"pkgs"/"prim_mubi_pkg.sv",
        IPS/"pkgs"/"prim_secded_pkg.sv",
        IPS/"pkgs"/"prim_subreg_pkg.sv",
        IPS/"pkgs"/"prim_util_pkg.sv",
        IPS/"pkgs"/"tlul_pkg.sv",
        IPS/"pkgs"/"prim_assert.sv",
        IPS/"pkgs"/"prim_count_pkg.sv",
        IPS/"pkgs"/"prim_flop_macros.sv",
        IPS/"pkgs"/"prim_alert_pkg.sv",
    ]
    prim = [
        IPS/"prim"/"prim_bin2gray.sv",
        IPS/"prim"/"prim_cdc_2phase.sv",
        IPS/"prim"/"prim_clk_div.sv",
        IPS/"prim"/"prim_clk_gate.sv",
        IPS/"prim"/"prim_counter.sv",
        IPS/"prim"/"prim_deglitch.sv",
        IPS/"prim"/"prim_edge_detect.sv",
        IPS/"prim"/"prim_ff.sv",
        IPS/"prim"/"prim_ff_2sync.sv",
        IPS/"prim"/"prim_fifo.sv",
        IPS/"prim"/"prim_gray2bin.sv",
        IPS/"prim"/"prim_lifo.sv",
        IPS/"prim"/"prim_lzc.sv",
        IPS/"prim"/"prim_ram.sv",
        IPS/"prim"/"prim_reg.sv",
        IPS/"prim"/"prim_rom.sv",
        IPS/"prim"/"prim_rrarbiter.sv",
        IPS/"prim"/"prim_shreg.sv",
    ]
    prim_ot = [
        IPS/"prim_opentitan"/"prim_arbiter_ppc.sv",
        IPS/"prim_opentitan"/"prim_buf.sv",
        IPS/"prim_opentitan"/"prim_cdc_rand_delay.sv",
        IPS/"prim_opentitan"/"prim_count.sv",
        IPS/"prim_opentitan"/"prim_diff_decode.sv",
        IPS/"prim_opentitan"/"prim_fifo_async.sv",
        IPS/"prim_opentitan"/"prim_fifo_async_simple.sv",
        IPS/"prim_opentitan"/"prim_fifo_async_sram_adapter.sv",
        IPS/"prim_opentitan"/"prim_fifo_sync.sv",
        IPS/"prim_opentitan"/"prim_fifo_sync_cnt.sv",
        IPS/"prim_opentitan"/"prim_filter.sv",
        IPS/"prim_opentitan"/"prim_filter_ctr.sv",
        IPS/"prim_opentitan"/"prim_flop.sv",
        IPS/"prim_opentitan"/"prim_flop_2sync.sv",
        IPS/"prim_opentitan"/"prim_intr_hw.sv",
        IPS/"prim_opentitan"/"prim_onehot_check.sv",
        IPS/"prim_opentitan"/"prim_pulse_sync.sv",
        IPS/"prim_opentitan"/"prim_reg_cdc.sv",
        IPS/"prim_opentitan"/"prim_reg_cdc_arb.sv",
        IPS/"prim_opentitan"/"prim_reg_we_check.sv",
        IPS/"prim_opentitan"/"prim_sec_anchor_buf.sv",
        IPS/"prim_opentitan"/"prim_sec_anchor_flop.sv",
        IPS/"prim_opentitan"/"prim_secded_inv_39_32_dec.sv",
        IPS/"prim_opentitan"/"prim_secded_inv_39_32_enc.sv",
        IPS/"prim_opentitan"/"prim_secded_inv_64_57_dec.sv",
        IPS/"prim_opentitan"/"prim_secded_inv_64_57_enc.sv",
        IPS/"prim_opentitan"/"prim_subreg.sv",
        IPS/"prim_opentitan"/"prim_subreg_arb.sv",
        IPS/"prim_opentitan"/"prim_subreg_ext.sv",
        IPS/"prim_opentitan"/"prim_sync_reqack.sv",
        IPS/"prim_opentitan"/"prim_alert_sender.sv",
    ]
    tlul = [
        IPS/"tlul"/"sram2tlul.sv",
        IPS/"tlul"/"tlul_adapter_host.sv",
        IPS/"tlul"/"tlul_adapter_reg.sv",
        IPS/"tlul"/"tlul_adapter_sram.sv",
        IPS/"tlul"/"tlul_assert.sv",
        IPS/"tlul"/"tlul_assert_multiple.sv",
        IPS/"tlul"/"tlul_cmd_intg_chk.sv",
        IPS/"tlul"/"tlul_cmd_intg_gen.sv",
        IPS/"tlul"/"tlul_data_integ_dec.sv",
        IPS/"tlul"/"tlul_data_integ_enc.sv",
        IPS/"tlul"/"tlul_err.sv",
        IPS/"tlul"/"tlul_err_resp.sv",
        IPS/"tlul"/"tlul_fifo_async.sv",
        IPS/"tlul"/"tlul_fifo_sync.sv",
        IPS/"tlul"/"tlul_rsp_intg_chk.sv",
        IPS/"tlul"/"tlul_rsp_intg_gen.sv",
        IPS/"tlul"/"tlul_socket_1n.sv",
        IPS/"tlul"/"tlul_socket_m1.sv",
        IPS/"tlul"/"tlul_sram_byte.sv",
    ]

    # include packages "as-is" (even if missing) to match requested behavior
    out: List[Path] = pkgs.copy()

    # include others only if file exists
    for group in (prim, prim_ot, tlul):
        for f in group:
            if f.exists():
                out.append(f)
    return out

def makefile_block_from_paths(paths: List[Path], root_var: str = "$(ROOT)") -> str:
    """Format a list of project-relative paths as a VERILOG_SOURCES block."""
    lines = ["VERILOG_SOURCES := \\"]
    for i, p in enumerate(paths):
        rel = p.as_posix()
        prefix = f"  {root_var}/" if not rel.startswith("$(ROOT)/") else "  "
        tail = " \\" if i != len(paths)-1 else ""
        lines.append(f"{prefix}{rel}{tail}")
    return "\n".join(lines)

# -------------------------
# Shared IP detection + ordered source building
# -------------------------
def always_include_packages(ips_root: Path) -> list[Path]:
    return [
        ips_root / "pkgs" / "top_pkg.sv",
        ips_root / "prim" / "prim_reg_pkg.sv",
        ips_root / "pkgs" / "prim_mubi_pkg.sv",
        ips_root / "pkgs" / "prim_secded_pkg.sv",
        ips_root / "pkgs" / "prim_subreg_pkg.sv",
        ips_root / "pkgs" / "prim_util_pkg.sv",
        ips_root / "pkgs" / "tlul_pkg.sv",
        ips_root / "pkgs" / "prim_assert.sv",
        ips_root / "pkgs" / "prim_count_pkg.sv",
        ips_root / "pkgs" / "prim_flop_macros.sv",
        ips_root / "pkgs" / "prim_alert_pkg.sv",
    ]

def candidate_ips_in_order(ips_root: Path) -> list[Path]:
    rel = [
        # ../hw/ips/prim/*
        "prim/prim_bin2gray.sv",
        "prim/prim_cdc_2phase.sv",
        "prim/prim_clk_div.sv",
        "prim/prim_clk_gate.sv",
        "prim/prim_counter.sv",
        "prim/prim_deglitch.sv",
        "prim/prim_edge_detect.sv",
        "prim/prim_ff.sv",
        "prim/prim_ff_2sync.sv",
        "prim/prim_fifo.sv",
        "prim/prim_gray2bin.sv",
        "prim/prim_lifo.sv",
        "prim/prim_lzc.sv",
        "prim/prim_ram.sv",
        "prim/prim_reg.sv",
        "prim/prim_rom.sv",
        "prim/prim_rrarbiter.sv",
        "prim/prim_shreg.sv",
        # ../hw/ips/prim_opentitan/*
        "prim_opentitan/prim_arbiter_ppc.sv",
        "prim_opentitan/prim_buf.sv",
        "prim_opentitan/prim_cdc_rand_delay.sv",
        "prim_opentitan/prim_count.sv",
        "prim_opentitan/prim_diff_decode.sv",
        "prim_opentitan/prim_fifo_async.sv",
        "prim_opentitan/prim_fifo_async_simple.sv",
        "prim_opentitan/prim_fifo_async_sram_adapter.sv",
        "prim_opentitan/prim_fifo_sync.sv",
        "prim_opentitan/prim_fifo_sync_cnt.sv",
        "prim_opentitan/prim_filter.sv",
        "prim_opentitan/prim_filter_ctr.sv",
        "prim_opentitan/prim_flop.sv",
        "prim_opentitan/prim_flop_2sync.sv",
        "prim_opentitan/prim_intr_hw.sv",
        "prim_opentitan/prim_onehot_check.sv",
        "prim_opentitan/prim_pulse_sync.sv",
        "prim_opentitan/prim_reg_cdc.sv",
        "prim_opentitan/prim_reg_cdc_arb.sv",
        "prim_opentitan/prim_reg_we_check.sv",
        "prim_opentitan/prim_sec_anchor_buf.sv",
        "prim_opentitan/prim_sec_anchor_flop.sv",
        "prim_opentitan/prim_secded_inv_39_32_dec.sv",
        "prim_opentitan/prim_secded_inv_39_32_enc.sv",
        "prim_opentitan/prim_secded_inv_64_57_dec.sv",
        "prim_opentitan/prim_secded_inv_64_57_enc.sv",
        "prim_opentitan/prim_subreg.sv",
        "prim_opentitan/prim_subreg_arb.sv",
        "prim_opentitan/prim_subreg_ext.sv",
        "prim_opentitan/prim_sync_reqack.sv",
        "prim_opentitan/prim_alert_sender.sv",
        # ../hw/ips/tlul/*
        "tlul/sram2tlul.sv",
        "tlul/tlul_adapter_host.sv",
        "tlul/tlul_adapter_reg.sv",
        "tlul/tlul_adapter_sram.sv",
        "tlul/tlul_assert.sv",
        "tlul/tlul_assert_multiple.sv",
        "tlul/tlul_cmd_intg_chk.sv",
        "tlul/tlul_cmd_intg_gen.sv",
        "tlul/tlul_data_integ_dec.sv",
        "tlul/tlul_data_integ_enc.sv",
        "tlul/tlul_err.sv",
        "tlul/tlul_err_resp.sv",
        "tlul/tlul_fifo_async.sv",
        "tlul/tlul_fifo_sync.sv",
        "tlul/tlul_rsp_intg_chk.sv",
        "tlul/tlul_rsp_intg_gen.sv",
        "tlul/tlul_socket_1n.sv",
        "tlul/tlul_socket_m1.sv",
        "tlul/tlul_sram_byte.sv",
    ]
    return [Path(ips_root) / p for p in rel]

def bundle_dir(paths: list[Path], subdir: str) -> list[Path]:
    sub = f"/{subdir}/"
    out: list[Path] = []
    for q in paths:
        qposix = q.as_posix()
        if sub in qposix or (len(q.parts) >= 2 and q.parts[-2] == subdir):
            out.append(q)
    return out

def gather_rtl_sources(rtl_root: Path) -> list[Path]:
    acc: list[Path] = []
    for ext in ("*.sv", "*.svh", "*.v"):
        acc.extend(Path(rtl_root).rglob(ext))
    return sorted(set(acc))

def file_contains_any_token(path: Path, tokens: Iterable[str]) -> bool:
    try:
        text = Path(path).read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return False
    for t in tokens:
        if re.search(rf"\b{re.escape(t)}\b", text):
            return True
    return False

def select_used_ips_in_order(ips_paths: list[Path], rtl_root: Path) -> list[Path]:
    rtl_files = gather_rtl_sources(rtl_root)
    used: list[Path] = []
    for ip in ips_paths:
        token = ip.stem
        if any(file_contains_any_token(f, (token,)) for f in rtl_files):
            used.append(ip)
    return used

def _parse_instantiated_modules_from_sv(path: Path) -> list[str]:
    """
    Heuristic, multiline-aware SV instantiation parser.
    Detects patterns like:
        prim_deglitch #(.Width(1)) u_sync (
        prim_ff_2sync u_ff[1:0] (
    across newlines and with optional parameterization.
    It ignores declarations like "module <name>" and other non-instantiation keywords.
    Returns a list of candidate *module* names instantiated in this file.
    """
    import re as _re
    try:
        text = Path(path).read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return []

    # Strip /* ... */ comments (including multiline)
    out, i, n, in_block = [], 0, len(text), False
    while i < n:
        if not in_block and text.startswith("/*", i):
            in_block, i = True, i+2
            continue
        if in_block and text.startswith("*/", i):
            in_block, i = False, i+2
            continue
        if not in_block:
            out.append(text[i])
        i += 1
    text = "".join(out)

    # Strip // comments
    text = "\n".join(ln.split("//", 1)[0] for ln in text.splitlines())

    # Multiline regex: capture <modname> [#(...)] <instname> [(...]
    rx = _re.compile(
        r"(?<!\bmodule\s)(?<!\binterface\s)(?<!\bpackage\s)(?<!\btypedef\s)"
        r"\b(?P<mod>[A-Za-z_]\w*)\s*"
        r"(?:#\s*\([^;]*?\))?\s+"
        r"(?P<inst>[A-Za-z_]\w*)\s*"
        r"(?:\[[^\]]+\]\s*)?"
        r"\(",
        _re.M | _re.S,
    )

    blacklist = {
        "if","for","case","assign","always","always_ff","always_comb","always_latch",
        "function","task","typedef","struct","union","enum","logic","wire","reg","genvar",
        "begin","end","unique","priority","virtual","static","automatic","import","export",
        "assert","cover","property","sequence","bind","generate"
    }

    mods: list[str] = []
    for m in rx.finditer(text):
        mod = m.group("mod")
        if mod in blacklist:
            continue
        mods.append(mod)
    return mods

def resolve_ip_dependencies(initial_used: list[Path], ip_candidates: list[Path]) -> list[Path]:
    """
    Given a seed list of used IP files, scan those files for submodule instantiations
    that match other candidates, and include them recursively. Preserve the declared
    order in ip_candidates.
    """
    # Map module-name (stem) -> Path for candidates
    name_to_path = {p.stem: p for p in ip_candidates}

    # Build closure over stems
    used_stems = {p.stem for p in initial_used}
    work = list(initial_used)

    while work:
        cur = work.pop(0)
        for sub in _parse_instantiated_modules_from_sv(cur):
            if sub in name_to_path and sub not in used_stems:
                used_stems.add(sub)
                work.append(name_to_path[sub])

    # Emit in the canonical order of ip_candidates
    ordered = [p for p in ip_candidates if p.stem in used_stems]
    return ordered

def build_ordered_sources(
    top: str,
    rtl_root: Path,
    ips_root: Path,
    *,
    out_file: Path | None = None,
    no_check: bool = False,
) -> list[Path]:
    """
    Compute the ordered list of sources:
      packages (always) + used IPs (order preserved) + rest (pkg first) + TOP-tail.
    If out_file is given, write the rtl list there.
    """
    rtl_root = Path(rtl_root)
    ips_root = Path(ips_root)

    fixed_packages = always_include_packages(ips_root)
    ip_candidates  = candidate_ips_in_order(ips_root)
    used_ips       = resolve_ip_dependencies(select_used_ips_in_order(ip_candidates, rtl_root), ip_candidates)

    need_prim_ot = any("/prim_opentitan/" in q.as_posix() for q in used_ips)
    need_tlul    = any("/tlul/"          in q.as_posix() for q in used_ips)
    if need_prim_ot:
        used_ips = list(dict.fromkeys(used_ips + bundle_dir(ip_candidates, "prim_opentitan")))
    if need_tlul:
        used_ips = list(dict.fromkeys(used_ips + bundle_dir(ip_candidates, "tlul")))

    tail_candidates = [
        rtl_root / f"{top}_reg_pkg.sv",
        rtl_root / f"{top}_reg_top.sv",
        rtl_root / f"{top}_core.sv",
        rtl_root / f"{top}.sv",
    ]
    tail = tail_candidates if no_check else [p for p in tail_candidates if p.exists()]

    all_rtl = gather_rtl_sources(rtl_root)
    exclude = {
        *(p.resolve() for p in fixed_packages),
        *(p.resolve() for p in used_ips),
        *(p.resolve() for p in tail),
    }
    rest = [p for p in all_rtl if p.resolve() not in exclude]
    rest = sorted(rest, key=lambda p: (not p.name.endswith("_pkg.sv"), p.as_posix()))

    paths = fixed_packages + used_ips + rest + tail

    if out_file is not None:
        Path(out_file).parent.mkdir(parents=True, exist_ok=True)
        Path(out_file).write_text("\n".join(p.as_posix() for p in paths) + "\n", encoding="utf-8")
    return paths
