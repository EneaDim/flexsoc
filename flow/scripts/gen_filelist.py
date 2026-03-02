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
    raise SystemExit(main())
