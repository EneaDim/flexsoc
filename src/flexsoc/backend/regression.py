"""Run simulation regressions over discovered SystemVerilog testbenches.

The module keeps Make execution isolated behind small import-safe helpers.
"""

from __future__ import annotations

import argparse
import subprocess
from pathlib import Path

DEFAULT_TB_DIR = Path("tb/regression")


def top_names(tb_dir: Path = DEFAULT_TB_DIR) -> tuple[str, ...]:
    """Return unique top names inferred from `*_tb*.sv` files."""

    names = {path.stem.split("_tb", 1)[0] for path in tb_dir.glob("*_tb*.sv")}
    return tuple(sorted(names))


def testbenches(top: str, tb_dir: Path = DEFAULT_TB_DIR) -> tuple[str, ...]:
    """Return testbench module names for one top."""

    return tuple(sorted(path.stem for path in tb_dir.glob(f"{top}_tb*.sv")))


def run_make(target: str, top: str | None = None, tb: str | None = None) -> subprocess.CompletedProcess[bytes]:
    """Run one Make target, optionally binding TOP and TESTBENCH."""

    command = ["make", target]
    if top and tb:
        command.extend([f"TOP={top}", f"TESTBENCH=regression/{tb}"])
    return subprocess.run(command, check=True)


def run_regression(target: str = "sim", tb_dir: Path = DEFAULT_TB_DIR) -> None:
    """Run the selected Make target for every discovered regression testbench."""

    for top in top_names(tb_dir):
        for tb in testbenches(top, tb_dir):
            run_make(target, top, tb)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse regression command line options."""

    parser = argparse.ArgumentParser(description="Run Make-backed simulation regressions.")
    parser.add_argument("--target", default="sim", help="Make target to run for each testbench.")
    parser.add_argument("--tb-dir", type=Path, default=DEFAULT_TB_DIR, help="Regression testbench directory.")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run all discovered regressions from the command line."""

    args = parse_args(argv)
    run_regression(args.target, args.tb_dir)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
