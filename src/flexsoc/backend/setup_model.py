"""Generate a minimal Python reference model template.

The template is intentionally small and import-safe for API-driven usage.
"""

from __future__ import annotations

import argparse
from pathlib import Path

MODEL_TEMPLATE = """import math
import time


def _sum(a, b):
    expected_outcome = a + b
    return expected_outcome


def _sub(a, b):
    expected_outcome = a - b
    return expected_outcome


def _multiply(a, b):
    expected_outcome = a * b
    return expected_outcome


def _divide(a, b):
    expected_outcome = a / b
    return expected_outcome
"""


def write_model(output: str | Path | None = None) -> Path:
    """Write the default `model.py` template and return its path."""

    folder = Path(output or ".")
    folder.mkdir(parents=True, exist_ok=True)
    path = folder / "model.py"
    path.write_text(MODEL_TEMPLATE, encoding="utf-8")
    return path.resolve()


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line arguments for model template generation."""

    parser = argparse.ArgumentParser(description="Generate a small Python model.py template.")
    parser.add_argument("--top", required=True, help="Top module name.")
    parser.add_argument("--output-dir", dest="output", help="Output folder. Defaults to the current directory.")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Generate `model.py` from command line options."""

    args = parse_args(argv)
    write_model(args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
