"""Generate CORDIC CSR-driven FlexSoC vector tests.

Generated test layout:

    tb/tests/<TEST_NAME>/
      config.regs
      data_in.vec
      data_out.vec

Vector format:

    data_in.vec:
      <CYCLE> @write <REG_OR_ADDR> <DATA> [MASK]

    data_out.vec:
      <CYCLE> @read <REG_OR_ADDR> <EXPECTED> [MASK]

The generator provides the FlexSoC base tests:

    smoke
    corners
    random
    reconfig

and keeps the previous CORDIC-focused tests available:

    smoke_zero
    rotate_45deg
    quadrant_sweep
    random_small
"""

from __future__ import annotations

import argparse
import math
import os
import random
from dataclasses import replace
from pathlib import Path

from cordic_fixed_model import CordicFormat, CordicInput, hex32, make_input, rotate_fixed
from regmap_cordic import addr as reg_addr, names as reg_names


BASE_TEST_ORDER = (
    "smoke",
    "corners",
    "random",
    "reconfig",
)

CORDIC_TEST_ORDER = (
    "smoke_zero",
    "rotate_45deg",
    "quadrant_sweep",
    "random_small",
)

DEFAULT_TEST_ORDER = BASE_TEST_ORDER + CORDIC_TEST_ORDER

TEST_ALIASES = {
    "all": "all",
    "*": "all",
}



def _make_sample(
    x: float,
    y: float,
    z: float,
    fmt: CordicFormat,
    *,
    mode: int = 0,
    n_iter: int | None = None,
) -> CordicInput:
    """Build one CORDIC input, overriding n_iter when requested."""

    try:
        if n_iter is None:
            return make_input(x, y, z, fmt, mode=mode)
        return make_input(x, y, z, fmt, mode=mode, n_iter=n_iter)
    except TypeError:
        sample = make_input(x, y, z, fmt, mode=mode)
        if n_iter is None:
            return sample
        try:
            return replace(sample, n_iter=n_iter)
        except TypeError:
            sample.n_iter = n_iter
            return sample


def _random_samples(fmt: CordicFormat, *, count: int, seed: int) -> list[CordicInput]:
    """Return deterministic random CORDIC vectors."""

    rng = random.Random(seed)
    return [
        _make_sample(
            rng.uniform(-0.25, 0.25),
            rng.uniform(-0.25, 0.25),
            rng.uniform(-math.pi, math.pi),
            fmt,
            mode=0,
        )
        for _ in range(count)
    ]


def builtin_tests(fmt: CordicFormat, *, random_count: int, seed: int) -> dict[str, list[CordicInput]]:
    """Return all built-in CORDIC CSR-driven vector tests."""

    random_vectors = _random_samples(fmt, count=random_count, seed=seed)

    smoke = [
        _make_sample(0.0, 0.0, 0.0, fmt, mode=0),
        _make_sample(0.25, 0.0, 0.0, fmt, mode=0),
    ]

    rotate_45deg = [
        _make_sample(0.25, 0.0, math.pi / 4.0, fmt, mode=0),
        _make_sample(0.25, 0.0, -math.pi / 4.0, fmt, mode=0),
        _make_sample(0.125, 0.125, math.pi / 4.0, fmt, mode=0),
    ]

    quadrant_sweep = [
        _make_sample(0.25, 0.0, 0.0, fmt, mode=0),
        _make_sample(0.25, 0.0, math.pi / 2.0, fmt, mode=0),
        _make_sample(0.25, 0.0, -math.pi / 2.0, fmt, mode=0),
        _make_sample(0.25, 0.0, 3.0 * math.pi / 4.0, fmt, mode=0),
        _make_sample(0.25, 0.0, -3.0 * math.pi / 4.0, fmt, mode=0),
    ]

    corners = [
        _make_sample(0.0, 0.0, 0.0, fmt, mode=0),
        _make_sample(0.25, 0.0, math.pi / 2.0, fmt, mode=0),
        _make_sample(0.25, 0.0, -math.pi / 2.0, fmt, mode=0),
        _make_sample(0.25, 0.0, 3.0 * math.pi / 4.0, fmt, mode=0),
        _make_sample(0.25, 0.0, -3.0 * math.pi / 4.0, fmt, mode=0),
    ]

    reconfig = [
        _make_sample(0.25, 0.0, math.pi / 8.0, fmt, mode=0, n_iter=4),
        _make_sample(0.25, 0.0, math.pi / 8.0, fmt, mode=0, n_iter=8),
        _make_sample(0.25, 0.0, math.pi / 8.0, fmt, mode=0, n_iter=12),
        _make_sample(0.25, 0.0, math.pi / 8.0, fmt, mode=0, n_iter=16),
    ]

    return {
        "smoke": smoke,
        "corners": corners,
        "random": random_vectors,
        "reconfig": reconfig,
        "smoke_zero": smoke,
        "rotate_45deg": rotate_45deg,
        "quadrant_sweep": quadrant_sweep,
        "random_small": random_vectors,
    }


def ctrl_value(sample: CordicInput, *, start: bool) -> int:
    """Encode CORDIC CTRL: START, MODE, and N_ITER."""

    start_bit = 1 if start else 0
    mode_bit = (int(sample.mode) & 0x1) << 1
    n_iter = (int(sample.n_iter) & 0xFF) << 8
    return n_iter | mode_bit | start_bit


def csr_hex(value: int) -> str:
    """Format one CSR word with an explicit base prefix."""

    return f"0x{hex32(value)}"

def write_config(test_dir: Path) -> None:
    """Write optional initial CSR configuration for one test."""

    lines = [
        "# CORDIC tests drive CSRs from data_in.vec.",
        "# Format for optional setup rows:",
        "#   <REG_OR_ADDR> <DATA> [MASK] [WAIT_CYCLES] [NOTE]",
        "# This file may intentionally contain comments only.",
        "",
    ]
    (test_dir / "config.regs").write_text("\n".join(lines), encoding="utf-8")


def write_test(test_dir: Path, samples: list[CordicInput], fmt: CordicFormat) -> None:
    """Write one FlexSoC vector-test directory."""

    test_dir.mkdir(parents=True, exist_ok=True)
    write_config(test_dir)

    data_in_lines: list[str] = [
        "# Auto-generated CORDIC register input vectors.",
        "# format: <cycle> @write <reg_or_addr> <data> [mask]",
    ]
    data_out_lines: list[str] = [
        "# Auto-generated CORDIC register expected-output vectors.",
        "# format: <cycle> @read <reg_or_addr> <expected> [mask]",
    ]

    for name in reg_names():
        addr = reg_addr(name)
        data_in_lines.append(f"# map {name} 0x{addr:02x}")
        data_out_lines.append(f"# map {name} 0x{addr:02x}")

    data_in_lines.append("")
    data_out_lines.append("")

    for index, sample in enumerate(samples):
        base_cycle = index * 80
        read_cycle = base_cycle + 40
        expected = rotate_fixed(sample, fmt)

        data_in_lines.extend(
            [
                f"{base_cycle + 0} @write X_IN {csr_hex(sample.x)}",
                f"{base_cycle + 1} @write Y_IN {csr_hex(sample.y)}",
                f"{base_cycle + 2} @write Z_IN {csr_hex(sample.z)}",
                f"{base_cycle + 3} @write CTRL {csr_hex(ctrl_value(sample, start=True))}",
                f"{base_cycle + 4} @write CTRL {csr_hex(ctrl_value(sample, start=False))}",
                "",
            ]
        )

        data_out_lines.extend(
            [
                f"{read_cycle} @read X_OUT {csr_hex(expected.x)} 0xffffffff",
                f"{read_cycle} @read Y_OUT {csr_hex(expected.y)} 0xffffffff",
                f"{read_cycle} @read Z_OUT {csr_hex(expected.z)} 0xffffffff",
                "",
            ]
        )

    (test_dir / "data_in.vec").write_text("\n".join(data_in_lines), encoding="utf-8")
    (test_dir / "data_out.vec").write_text("\n".join(data_out_lines), encoding="utf-8")

    old_expected = test_dir / "expected.json"
    if old_expected.exists():
        old_expected.unlink()


def selected_tests(args: argparse.Namespace, tests: dict[str, list[CordicInput]]) -> dict[str, list[CordicInput]]:
    """Resolve fx/tests_gen selection semantics."""

    env_test = os.environ.get("TEST_NAME", "").strip()
    requested = (args.test or env_test).strip()

    if args.all or not requested or requested.lower() in {"all", "*"}:
        return {name: tests[name] for name in DEFAULT_TEST_ORDER}

    requested = TEST_ALIASES.get(requested, requested)

    if requested not in tests:
        available = ", ".join(DEFAULT_TEST_ORDER)
        raise SystemExit(f"unknown TEST_NAME={requested!r}; available: {available}")

    return {requested: tests[requested]}


def main() -> int:
    """CLI entry point used by fx tests_gen/test_gen."""

    parser = argparse.ArgumentParser()
    parser.add_argument("--tests-dir", type=Path, default=Path("../tb/tests"))
    parser.add_argument("--test", default=None, help="Generate one named test only")
    parser.add_argument("--all", action="store_true", help="Generate all built-in tests")
    parser.add_argument("--random-count", type=int, default=8)
    parser.add_argument("--seed", type=int, default=1)
    args = parser.parse_args()

    fmt = CordicFormat()
    tests = builtin_tests(fmt, random_count=args.random_count, seed=args.seed)

    for name, samples in selected_tests(args, tests).items():
        write_test(args.tests_dir / name, samples, fmt)
        print(f"generated {args.tests_dir / name}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
