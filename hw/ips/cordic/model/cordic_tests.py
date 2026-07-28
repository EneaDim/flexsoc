"""CORDIC test catalogue and vector generator.

CORDIC has no functional data pins at the top level: operands, control, status,
and results are all software-visible CSRs. Test scenarios live here; behavioral
results come from ``cordic_model.py`` and CSR layout from ``cordic_regmap.py``.
"""

from __future__ import annotations

import argparse
import math
import os
import random
from pathlib import Path

from cordic_model import CordicFormat, CordicInput, make_input, rotate_fixed
import cordic_regmap as regmap


CSR = regmap.PRIMARY

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
TEST_ALIASES = {"all": "all", "*": "all"}


def _make_sample(
    x: float,
    y: float,
    z: float,
    fmt: CordicFormat,
    *,
    mode: int = 0,
    n_iter: int | None = None,
) -> CordicInput:
    """Build one CORDIC input from real-valued stimulus."""

    return make_input(x, y, z, fmt, mode=mode, n_iter=n_iter)


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


def builtin_tests(
    fmt: CordicFormat,
    *,
    random_count: int,
    seed: int,
) -> dict[str, list[CordicInput]]:
    """Return all built-in CORDIC CSR-driven scenarios."""

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


def write_config(test_dir: Path) -> None:
    """Write the empty initial configuration used by CSR-vector tests."""

    regmap.write_config(test_dir / "config.regs", [])


def input_rows(base_cycle: int, sample: CordicInput) -> list[str]:
    """Program one operation exclusively through HJSON-derived CSR objects."""

    control = {
        "MODE": int(sample.mode),
        "SOFT_RST": 0,
        "N_ITER": int(sample.n_iter),
    }
    return [
        CSR.X_IN.vector_write(base_cycle + 0, VALUE=int(sample.x)),
        CSR.Y_IN.vector_write(base_cycle + 1, VALUE=int(sample.y)),
        CSR.Z_IN.vector_write(base_cycle + 2, VALUE=int(sample.z)),
        CSR.CTRL.vector_write(base_cycle + 3, START=1, **control),
        CSR.CTRL.vector_write(base_cycle + 4, START=0, **control),
    ]


def output_rows(read_cycle: int, sample: CordicInput, fmt: CordicFormat) -> list[str]:
    """Check completion status and software-visible result CSRs."""

    expected = rotate_fixed(sample, fmt)
    return [
        CSR.STATUS.vector_read(read_cycle, BUSY=0, VALID=1, ERROR=0),
        CSR.X_OUT.vector_read(read_cycle, VALUE=int(expected.x)),
        CSR.Y_OUT.vector_read(read_cycle, VALUE=int(expected.y)),
        CSR.Z_OUT.vector_read(read_cycle, VALUE=int(expected.z)),
    ]


def write_test(test_dir: Path, samples: list[CordicInput], fmt: CordicFormat) -> None:
    """Write one FlexSoC CSR-driven vector-test directory."""

    test_dir.mkdir(parents=True, exist_ok=True)
    write_config(test_dir)

    data_in_lines = [
        "# CORDIC CSR stimulus generated from the behavioral model.",
        "# format: <cycle> @write <clock.reg> <data> [mask]",
    ]
    data_out_lines = [
        "# CORDIC CSR checks generated from the behavioral model.",
        "# format: <cycle> @read <clock.reg> <expected> [mask]",
        CSR.CFG.vector_read(
            0,
            DATA_WIDTH=fmt.data_width,
            FRAC_WIDTH=fmt.data_frac_bits,
            MAX_ITER=fmt.max_iter,
        ),
    ]

    for index, sample in enumerate(samples):
        base_cycle = index * 80
        read_cycle = base_cycle + 40
        data_in_lines.extend(input_rows(base_cycle, sample))
        data_out_lines.extend(output_rows(read_cycle, sample, fmt))

    (test_dir / "data_in.vec").write_text("\n".join(data_in_lines) + "\n", encoding="utf-8")
    (test_dir / "data_out.vec").write_text("\n".join(data_out_lines) + "\n", encoding="utf-8")

    old_expected = test_dir / "expected.json"
    if old_expected.exists():
        old_expected.unlink()


def selected_tests(
    args: argparse.Namespace,
    tests: dict[str, list[CordicInput]],
) -> dict[str, list[CordicInput]]:
    """Resolve ``fx tests_gen`` / ``fx test_gen`` selection semantics."""

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
    """CLI entry point used by ``fx tests_gen`` / ``fx test_gen``."""

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
