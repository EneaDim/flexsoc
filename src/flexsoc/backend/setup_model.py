"""Generate a Python reference model and vector helpers for FlexSoC tests."""

from __future__ import annotations

import argparse
from pathlib import Path
from textwrap import dedent


def render_model(top: str) -> str:
    """Render a small reference model matching the generated rtl_stub pipeline."""

    return dedent(
        f'''\
        """Auto-generated FlexSoC reference model for {top}."""

        from __future__ import annotations

        import random
        from pathlib import Path


        class Pipeline2Model:
            """Reference model for the default rtl_stub two-flop pipeline."""

            def __init__(self, latency: int = 2) -> None:
                self.latency = latency

            def expected(self, value: int) -> int:
                return value & 0xFFFFFFFF

            def rows(self, values):
                return [
                    (cycle, value, self.expected(value), self.latency, 0xFFFFFFFF, f"model_{{cycle}}")
                    for cycle, value in enumerate(values)
                ]


        def _hex(value: int) -> str:
            return f"0x{{value & 0xFFFFFFFF:08x}}"


        def values_for(test: str, count: int = 12) -> list[int]:
            if test == "smoke":
                return [0, 1, 0, 1, 1, 0]
            if test == "corners":
                return [0, 0, 1, 1, 0, 1, 0, 1]
            rng = random.Random("{top}:" + test + ":vectors")
            return [rng.randrange(2) for _ in range(count)]


        def write_vec(path: str | Path, test: str = "smoke", latency: int = 2) -> Path:
            model = Pipeline2Model(latency=latency)
            target = Path(path)
            target.parent.mkdir(parents=True, exist_ok=True)
            lines = [
                "# Auto-generated FlexSoC vector file.",
                f"# top={top} test={{test}} model=pipeline delay={{latency}}",
                "# format: cycle input expected latency mask note",
            ]
            for cycle, value, expected, row_latency, mask, note in model.rows(values_for(test)):
                lines.append(
                    f"{{cycle}} {{_hex(value)}} {{_hex(expected)}} {{row_latency}} {{_hex(mask)}} {{note}}"
                )
            target.write_text("\\n".join(lines) + "\\n", encoding="utf-8")
            return target
        '''
    )


def write_model(top: str, output: str | Path | None = None) -> Path:
    """Write `model_<top>.py` and return its path."""

    folder = Path(output or ".")
    folder.mkdir(parents=True, exist_ok=True)
    stale = folder / "model.py"
    if stale.exists():
        stale.unlink()
    path = folder / f"model_{top}.py"
    path.write_text(render_model(top), encoding="utf-8")
    return path.resolve()


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line arguments for model template generation."""

    parser = argparse.ArgumentParser(description="Generate Python reference model helpers.")
    parser.add_argument("--top", required=True, help="Top module name.")
    parser.add_argument("--output-dir", dest="output", help="Output folder. Defaults to the current directory.")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Generate Python reference model helpers from command line options."""

    args = parse_args(argv)
    write_model(args.top, args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
