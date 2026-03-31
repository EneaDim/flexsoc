#!/usr/bin/env python3
"""
Compatibility wrapper for the refactored CORDIC modeling stack.

This file preserves the old import surface expected by:
- plotting scripts
- dashboard
- CSV generators
- RTL LUT generators
- quick CLI usage

Internally, the implementation is now split into:
- cordic_common.py
- cordic_float_model.py
- cordic_fixed_model.py
"""

from __future__ import annotations

import argparse
import csv
import json
from pathlib import Path
from typing import Sequence

from cordic_common import *
from cordic_float_model import *
from cordic_fixed_model import *


# -----------------------------------------------------------------------------
# Serialization helpers
# -----------------------------------------------------------------------------
def save_vectors_json(vectors: Sequence[TestVector], path: str) -> None:
    """Save vectors to JSON."""
    out_path = Path(path)
    out_path.parent.mkdir(parents=True, exist_ok=True)

    with out_path.open("w", encoding="utf-8") as fh:
        json.dump([asdict(v) for v in vectors], fh, indent=2)


def save_vectors_csv(vectors: Sequence[TestVector], path: str) -> None:
    """Save vectors to CSV."""
    if not vectors:
        raise ValueError("Cannot save an empty vector list to CSV")

    out_path = Path(path)
    out_path.parent.mkdir(parents=True, exist_ok=True)

    fieldnames = list(asdict(vectors[0]).keys())

    with out_path.open("w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(fh, fieldnames=fieldnames)
        writer.writeheader()
        for vector in vectors:
            writer.writerow(asdict(vector))


# -----------------------------------------------------------------------------
# Human-readable reporting helpers
# -----------------------------------------------------------------------------
def print_config_summary(cfg: CordicConfig) -> None:
    """Print a readable summary of the current numerical configuration."""
    internal_fmt = get_internal_data_format(cfg)

    print("CORDIC configuration")
    print("--------------------")
    print(f"Data format         : width={cfg.data_format.width}, frac={cfg.data_format.frac}")
    print(f"Angle format        : width={cfg.angle_format.width}, frac={cfg.angle_format.frac}")
    print(f"Internal data width : width={internal_fmt.width}, frac={internal_fmt.frac}")
    print(f"Iterations          : {cfg.iterations}")
    print(f"Guard bits          : {cfg.internal_guard_bits}")
    print(f"Saturate output     : {cfg.saturate_output}")
    print(f"Gain K              : {cordic_gain(cfg.iterations):.12f}")
    print(f"Gain 1/K            : {cordic_gain_inverse(cfg.iterations):.12f}")
    print()


def print_lut(cfg: CordicConfig) -> None:
    """Print the atan LUT in both floating-point and fixed-point form."""
    lut_f = build_atan_lut_float(cfg.iterations)
    lut_q = build_atan_lut_fixed(cfg.iterations, cfg.angle_format)

    print("CORDIC atan LUT")
    print("----------------")
    for i, (angle_f, angle_q) in enumerate(zip(lut_f, lut_q)):
        print(
            f"i={i:2d}  "
            f"atan(2^-i)={angle_f: .12f} rad  "
            f"fixed={angle_q:8d}  "
            f"float_from_fixed={fixed_to_float(angle_q, cfg.angle_format): .12f}"
        )
    print()


# -----------------------------------------------------------------------------
# CLI
# -----------------------------------------------------------------------------
def build_argparser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="CORDIC Python model wrapper")

    parser.add_argument("--width", type=int, default=16, help="Data path width")
    parser.add_argument("--frac", type=int, default=14, help="Data path fractional bits")
    parser.add_argument("--angle-width", type=int, default=16, help="Angle path width")
    parser.add_argument("--angle-frac", type=int, default=13, help="Angle path fractional bits")
    parser.add_argument("--iterations", type=int, default=16, help="Number of CORDIC iterations")
    parser.add_argument("--guard-bits", type=int, default=3, help="Internal x/y guard bits")
    parser.add_argument(
        "--wrap-output",
        action="store_true",
        help="Wrap x/y outputs instead of saturating them",
    )

    parser.add_argument("--print-config", action="store_true", help="Print configuration summary")
    parser.add_argument("--print-lut", action="store_true", help="Print the atan LUT")
    parser.add_argument("--selfcheck", action="store_true", help="Run internal self-check")

    parser.add_argument("--gen-directed-rotation-json", type=str, default=None)
    parser.add_argument("--gen-directed-vectoring-json", type=str, default=None)
    parser.add_argument("--gen-random-rotation-json", type=str, default=None)
    parser.add_argument("--gen-random-vectoring-json", type=str, default=None)

    parser.add_argument("--gen-directed-rotation-csv", type=str, default=None)
    parser.add_argument("--gen-directed-vectoring-csv", type=str, default=None)
    parser.add_argument("--gen-random-rotation-csv", type=str, default=None)
    parser.add_argument("--gen-random-vectoring-csv", type=str, default=None)

    parser.add_argument("--count", type=int, default=100, help="Number of random vectors")
    parser.add_argument("--seed", type=int, default=1234, help="Random seed")

    return parser


def main() -> None:
    args = build_argparser().parse_args()

    cfg = CordicConfig(
        data_format=FixedFormat(width=args.width, frac=args.frac, signed=True),
        angle_format=FixedFormat(width=args.angle_width, frac=args.angle_frac, signed=True),
        iterations=args.iterations,
        compensate_gain=True,
        internal_guard_bits=args.guard_bits,
        saturate_output=not args.wrap_output,
    )

    if args.print_config:
        print_config_summary(cfg)

    if args.print_lut:
        print_lut(cfg)

    if args.selfcheck:
        run_selfcheck(cfg, count=args.count)

    if args.gen_directed_rotation_json:
        save_vectors_json(generate_directed_rotation_vectors(cfg), args.gen_directed_rotation_json)

    if args.gen_directed_vectoring_json:
        save_vectors_json(generate_directed_vectoring_vectors(cfg), args.gen_directed_vectoring_json)

    if args.gen_random_rotation_json:
        save_vectors_json(generate_random_rotation_vectors(cfg, args.count, args.seed), args.gen_random_rotation_json)

    if args.gen_random_vectoring_json:
        save_vectors_json(generate_random_vectoring_vectors(cfg, args.count, args.seed), args.gen_random_vectoring_json)

    if args.gen_directed_rotation_csv:
        save_vectors_csv(generate_directed_rotation_vectors(cfg), args.gen_directed_rotation_csv)

    if args.gen_directed_vectoring_csv:
        save_vectors_csv(generate_directed_vectoring_vectors(cfg), args.gen_directed_vectoring_csv)

    if args.gen_random_rotation_csv:
        save_vectors_csv(generate_random_rotation_vectors(cfg, args.count, args.seed), args.gen_random_rotation_csv)

    if args.gen_random_vectoring_csv:
        save_vectors_csv(generate_random_vectoring_vectors(cfg, args.count, args.seed), args.gen_random_vectoring_csv)


if __name__ == "__main__":
    main()
