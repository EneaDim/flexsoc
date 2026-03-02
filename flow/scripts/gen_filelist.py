#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from pathlib import Path
from typing import List

# Uses the canonical ordered library list from common.py
from common import fixed_ip_paths  # type: ignore


def write_list(out_path: Path, paths: List[Path]) -> None:
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text("\n".join(p.as_posix() for p in paths) + "\n", encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser(description="Generate rtl_list.f for lint/sim/synth flows.")
    ap.add_argument("--top", required=True, help="Top module name (e.g. my_ip)")
    ap.add_argument("--out", default="rtl/rtl_list.f", help="Output filelist path")
    ap.add_argument("--rtldir", default="rtl", help="Directory containing generated RTL for the IP")
    ap.add_argument("--ips-root", default="../hw/ips", help="Root dir for shared IP library (pkgs/prim/tlul/...)")
    ap.add_argument("--no-check", action="store_true", help="Do not warn on missing local RTL files")
    args = ap.parse_args()

    top = args.top
    out_path = Path(args.out)
    rtldir = Path(args.rtldir)
    ips_root = Path(args.ips_root)

    # 1) Shared fixed libs (OpenTitan-style): pkgs always listed; prim/prim_opentitan/tlul appended if exist
    shared = fixed_ip_paths(ips_root)

    # 2) Local generated RTL for this IP (must be at the bottom, ordered)
    local = [
        rtldir / f"{top}_reg_pkg.sv",
        rtldir / f"{top}_reg_top.sv",
        rtldir / f"{top}_core.sv",
        rtldir / f"{top}.sv",
    ]

    missing: List[Path] = []
    if not args.no_check:
        for p in local:
            if not p.exists():
                missing.append(p)

    paths = shared + local
    write_list(out_path, paths)

    # Warnings to stderr (do not fail; downstream tools decide)
    for m in missing:
        print(f"Warning: {m.as_posix()} does not exist.", file=sys.stderr)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
