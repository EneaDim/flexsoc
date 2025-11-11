# (auto-refactored) Use common.build_ordered_sources
from __future__ import annotations

import argparse
from pathlib import Path
from typing import List
from common import build_ordered_sources

def main() -> None:
    ap = argparse.ArgumentParser(
        description="Generate rtl/rtl_list.f with packages + used IPs + project RTL (+ TOP tail)."
    )
    ap.add_argument("--top", required=True, help="Top module base name (e.g. spi_host)")
    ap.add_argument("--out", default="rtl/rtl_list.f", help="Output filename")
    ap.add_argument("--ips-root", default="ips", help="Root dir for ips")
    ap.add_argument("--rtl-root", default="rtl", help="Root dir for rtl")
    ap.add_argument("--no-check", action="store_true", help="Do not check existence for TOP-tail")
    args = ap.parse_args()

    ips_root = Path(args.ips_root)
    rtl_root = Path(args.rtl_root)
    top      = args.top

    paths: List[Path] = build_ordered_sources(
        top, rtl_root, ips_root, out_file=Path(args.out), no_check=bool(args.no_check)
    )

    if not args.no_check:
        for p in paths:
            if not p.exists():
                print(f"Warning: {p.as_posix()} does not exist.")

if __name__ == "__main__":
    main()
