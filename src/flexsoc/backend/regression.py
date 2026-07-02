"""Run simulation regressions over discovered SystemVerilog testbenches.

Regression discovery is import-safe so API callers can preview it later.
"""

from __future__ import annotations

import argparse
import subprocess
from dataclasses import dataclass
from pathlib import Path

DEFAULT_TB_DIR = Path("tb/regression")


@dataclass(frozen=True, slots=True)
class RegressionConfig:
    """Group the Make target and testbench directory used for regressions."""

    target: str = "sim"
    tb_dir: Path = DEFAULT_TB_DIR


def top_names(tb_dir: Path = DEFAULT_TB_DIR) -> tuple[str, ...]:
    """Return unique top names inferred from `*_tb*.sv` files."""

    names = {path.stem.split("_tb", 1)[0] for path in tb_dir.glob("*_tb*.sv")}
    return tuple(sorted(names))


def testbenches(top: str, tb_dir: Path = DEFAULT_TB_DIR) -> tuple[str, ...]:
    """Return testbench module names for one top."""

    return tuple(sorted(path.stem for path in tb_dir.glob(f"{top}_tb*.sv")))


def regression_plan(config: RegressionConfig) -> tuple[tuple[str, str], ...]:
    """Return ordered `(top, testbench)` pairs without running Make."""

    return tuple((top, tb) for top in top_names(config.tb_dir) for tb in testbenches(top, config.tb_dir))


def run_make(target: str, top: str, tb: str) -> subprocess.CompletedProcess[bytes]:
    """Run one Make target with TOP and TESTBENCH variables set."""

    return subprocess.run(["make", target, f"TOP={top}", f"TESTBENCH=regression/{tb}"], check=True)


def run_regression(config: RegressionConfig | None = None) -> None:
    """Run the selected Make target for every discovered testbench."""

    config = config or RegressionConfig()
    for top, tb in regression_plan(config):
        run_make(config.target, top, tb)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse regression command line options."""

    parser = argparse.ArgumentParser(description="Run Make-backed simulation regressions.")
    parser.add_argument("--target", default="sim", help="Make target to run for each testbench.")
    parser.add_argument("--tb-dir", type=Path, default=DEFAULT_TB_DIR, help="Regression testbench directory.")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run all discovered regressions from the command line."""

    args = parse_args(argv)
    run_regression(RegressionConfig(args.target, args.tb_dir))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
