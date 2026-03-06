# ruff: noqa
#!/usr/bin/env python3
from __future__ import annotations

"""
Shared helpers for flexsoc tools.

Goals:
- keep this file small and readable
- provide filesystem helpers
- provide light SV parsing helpers
- provide canonical RTL ordering for rtl_list.f generation
"""

import os
import re
import sys
from pathlib import Path
from typing import Any, Dict, Iterable, List, Tuple


# -----------------------------------------------------------------------------
# Terminal helpers
# -----------------------------------------------------------------------------

def colorize(text: str, color_code: str = "\033[38;5;214m") -> str:
    if not sys.stdout.isatty() or os.environ.get("NO_COLOR"):
        return text
    return f"{color_code}{text}\033[0m"


# -----------------------------------------------------------------------------
# Filesystem helpers
# -----------------------------------------------------------------------------

def ensure_dir(path: str | os.PathLike[str]) -> None:
    Path(path).mkdir(parents=True, exist_ok=True)


def safe_write_file(
    path: str | os.PathLike[str],
    content: str,
    *,
    overwrite: bool = False,
) -> None:
    p = Path(path)
    if p.exists() and not overwrite:
        raise FileExistsError(str(p))
    p.write_text(content, encoding="utf-8")


# -----------------------------------------------------------------------------
# Small SV parsing helpers
# -----------------------------------------------------------------------------

def _strip_line_comment(line: str) -> str:
    if "//" in line:
        return line.split("//", 1)[0]
    return line


def _read_module_header_text(sv_path: Path) -> str:
    text = sv_path.read_text(encoding="utf-8", errors="ignore")

    start = text.find("module")
    if start != -1:
        text = text[start:]

    end = text.find(");")
    if end != -1:
        text = text[: end + 2]

    out: list[str] = []
    i = 0
    in_block = False
    while i < len(text):
        if not in_block and text.startswith("/*", i):
            in_block = True
            i += 2
            continue
        if in_block and text.startswith("*/", i):
            in_block = False
            i += 2
            continue
        if not in_block:
            out.append(text[i])
        i += 1

    clean = "".join(out)
    return "\n".join(_strip_line_comment(line) for line in clean.splitlines())


def parse_sv_signature(rtldir: str | os.PathLike[str], top: str) -> Dict[str, Any]:
    sv = Path(rtldir) / f"{top}.sv"
    if not sv.exists():
        raise FileNotFoundError(str(sv))

    lines = _read_module_header_text(sv).splitlines()

    parameters: List[Tuple[str, str]] = []
    localparams: List[Tuple[str, str]] = []
    ports_in: List[Tuple[str, Any]] = []
    ports_out: List[Tuple[str, Any]] = []
    clks: List[str] = []
    rsts: List[str] = []

    def push_param(line: str, kind: str) -> None:
        if "=" not in line:
            return
        left, right = line.split("=", 1)
        name = left.split()[-1].strip()
        value = right.strip().rstrip(",)")
        if kind == "parameter":
            parameters.append((name, value))
        else:
            localparams.append((name, value))

    def push_port(line: str, direction: str) -> None:
        toks = line.strip().rstrip(",)").split()
        if not toks:
            return
        if toks[0] in ("input", "output"):
            toks = toks[1:]
        if toks and toks[0] == "logic":
            toks = toks[1:]
        if not toks:
            return

        width = toks[-2] if len(toks) >= 2 else 1
        name = toks[-1].rstrip(",")

        if direction == "in":
            ports_in.append((name, width))
        else:
            ports_out.append((name, width))

        if "clk_" in name:
            clks.append(name)
        if "rst_" in name:
            rsts.append(name)

    for raw in lines:
        line = raw.strip()
        if not line:
            continue
        if "parameter" in line and "localparam" not in line:
            push_param(line, "parameter")
        elif "localparam" in line:
            push_param(line, "localparam")
        elif line.startswith("input"):
            push_port(line, "in")
        elif line.startswith("output"):
            push_port(line, "out")

    return {
        "parameters": parameters,
        "localparams": localparams,
        "ports_in": ports_in,
        "ports_out": ports_out,
        "clks": clks,
        "rsts": rsts,
    }


def has_reg_pkg(rtldir: str | os.PathLike[str], top: str) -> bool:
    return (Path(rtldir) / f"{top}_reg_pkg.sv").exists()


# -----------------------------------------------------------------------------
# Discovery helpers
# -----------------------------------------------------------------------------

def list_hdl_files(root: str | os.PathLike[str], *, recursive: bool = True) -> List[Path]:
    rootp = Path(root)
    if not rootp.exists():
        return []

    exts = {".sv", ".svh", ".v", ".vh"}
    it: Iterable[Path]
    if recursive:
        it = rootp.rglob("*")
    else:
        it = rootp.glob("*")

    files = [p.resolve() for p in it if p.is_file() and p.suffix.lower() in exts]
    return sorted(set(files))


def gather_rtl_sources(root: Path) -> list[Path]:
    return list_hdl_files(root, recursive=True)


def find_top_sv(rtldir: str | os.PathLike[str], top: str) -> Path | None:
    p = Path(rtldir) / f"{top}.sv"
    return p if p.exists() else None


# -----------------------------------------------------------------------------
# Canonical source ordering
# -----------------------------------------------------------------------------

def always_include_packages(ips_root: Path) -> list[Path]:
    """
    Canonical package order.

    Important:
    - top_pkg.sv MUST come before tlul_pkg.sv
    - order here is intentional and should not be alphabetized
    """
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
    return [ips_root / p for p in rel]


def _parse_instantiated_modules_from_sv(path: Path) -> list[str]:
    """
    Small multiline-aware instantiation parser.

    Detects patterns like:
      prim_deglitch u_x (...);
      prim_ff_2sync #(.Width(1)) u_y (...);

    This is intentionally heuristic, not a full parser.
    """
    try:
        text = path.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return []

    # Remove block comments
    out: list[str] = []
    i = 0
    in_block = False
    while i < len(text):
        if not in_block and text.startswith("/*", i):
            in_block = True
            i += 2
            continue
        if in_block and text.startswith("*/", i):
            in_block = False
            i += 2
            continue
        if not in_block:
            out.append(text[i])
        i += 1
    text = "".join(out)

    # Remove line comments
    text = "\n".join(line.split("//", 1)[0] for line in text.splitlines())

    rx = re.compile(
        r"(?<!\bmodule\s)"
        r"(?<!\binterface\s)"
        r"(?<!\bpackage\s)"
        r"\b(?P<mod>[A-Za-z_]\w*)\s*"
        r"(?:#\s*\([^;]*?\))?\s+"
        r"(?P<inst>[A-Za-z_]\w*)\s*"
        r"(?:\[[^\]]+\]\s*)?"
        r"\(",
        re.M | re.S,
    )

    blacklist = {
        "if",
        "for",
        "case",
        "assign",
        "always",
        "always_ff",
        "always_comb",
        "always_latch",
        "function",
        "task",
        "typedef",
        "struct",
        "union",
        "enum",
        "logic",
        "wire",
        "reg",
        "genvar",
        "begin",
        "end",
        "unique",
        "priority",
        "virtual",
        "static",
        "automatic",
        "import",
        "export",
        "assert",
        "cover",
        "property",
        "sequence",
        "bind",
        "generate",
    }

    mods: list[str] = []
    for m in rx.finditer(text):
        mod = m.group("mod")
        if mod not in blacklist:
            mods.append(mod)
    return mods


def file_contains_any_token(path: Path, tokens: Iterable[str]) -> bool:
    try:
        text = path.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return False

    for tok in tokens:
        if re.search(rf"\b{re.escape(tok)}\b", text):
            return True
    return False


def select_used_ips_in_order(ip_candidates: list[Path], rtl_root: Path) -> list[Path]:
    rtl_files = gather_rtl_sources(rtl_root)

    used: list[Path] = []
    for ip in ip_candidates:
        token = ip.stem
        if any(file_contains_any_token(rtl, (token,)) for rtl in rtl_files):
            used.append(ip)

    return used


def resolve_ip_dependencies(initial_used: list[Path], ip_candidates: list[Path]) -> list[Path]:
    """
    Expand the initial used IP set by following submodule instantiations recursively.
    Emit in canonical candidate order.
    """
    name_to_path = {p.stem: p for p in ip_candidates}
    used_stems = {p.stem for p in initial_used}
    queue = list(initial_used)

    while queue:
        cur = queue.pop(0)
        for sub in _parse_instantiated_modules_from_sv(cur):
            if sub in name_to_path and sub not in used_stems:
                used_stems.add(sub)
                queue.append(name_to_path[sub])

    return [p for p in ip_candidates if p.stem in used_stems]


def build_ordered_sources(
    top: str,
    rtl_root: Path,
    ips_root: Path,
    *,
    out_file: Path | None = None,
) -> list[Path]:
    """
    Canonical source ordering for rtl_list.f:
      1. always-include packages (explicit order)
      2. used IP support files (explicit order)
      3. remaining RTL package files
      4. remaining RTL non-package files
      5. top-tail files in explicit order
    """
    rtl_root = Path(rtl_root).resolve()
    ips_root = Path(ips_root).resolve()

    fixed_packages = always_include_packages(ips_root)
    ip_candidates = candidate_ips_in_order(ips_root)

    used_ips_seed = select_used_ips_in_order(ip_candidates, rtl_root)
    used_ips = resolve_ip_dependencies(used_ips_seed, ip_candidates)

    tail_candidates = [
        rtl_root / f"{top}_reg_pkg.sv",
        rtl_root / f"{top}_reg_top.sv",
        rtl_root / f"{top}_core.sv",
        rtl_root / f"{top}.sv",
    ]
    tail = [p for p in tail_candidates if p.exists()]

    all_rtl = gather_rtl_sources(rtl_root)

    exclude = {
        *(p.resolve() for p in fixed_packages if p.exists()),
        *(p.resolve() for p in used_ips if p.exists()),
        *(p.resolve() for p in tail),
    }

    rest = [p for p in all_rtl if p.resolve() not in exclude]
    rest_pkgs = [p for p in rest if p.name.endswith("_pkg.sv")]
    rest_others = [p for p in rest if not p.name.endswith("_pkg.sv")]
    rest_pkgs.sort(key=lambda p: p.as_posix())
    rest_others.sort(key=lambda p: p.as_posix())

    ordered: list[Path] = []

    for p in fixed_packages:
        if p.exists():
            ordered.append(p)

    for p in used_ips:
        if p.exists():
            ordered.append(p)

    ordered.extend(rest_pkgs)
    ordered.extend(rest_others)

    for p in tail:
        if p not in ordered:
            ordered.append(p)

    # de-dup while preserving order
    final: list[Path] = []
    seen: set[Path] = set()
    for p in ordered:
        rp = p.resolve()
        if rp in seen:
            continue
        seen.add(rp)
        final.append(rp)

    if out_file is not None:
        out_path = Path(out_file)
        out_path.parent.mkdir(parents=True, exist_ok=True)
        out_path.write_text("\n".join(p.as_posix() for p in final) + "\n", encoding="utf-8")

    return final
