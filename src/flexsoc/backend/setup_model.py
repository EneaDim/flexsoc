"""Generate a small editable Python reference-model scaffold."""

from __future__ import annotations

import argparse
from pathlib import Path


MODEL_TEMPLATE = r'''# Editable FlexSoC reference model for __TOP__.
# Implement expected(), rows(), and config_lines() for the IP under test.

from __future__ import annotations

import random
from pathlib import Path


TESTS = ("smoke", "corners", "random")


def expected(data: int, coeff: int, mode: int = 0) -> int:
    # Return the expected DUT result for one input transaction.
    if mode == 1:
        return (data ^ coeff) & 0xFFFFFFFF
    if mode == 2:
        return (data << 1) & 0xFFFFFFFF
    return (data + coeff) & 0xFFFFFFFF


def _hex(value: int) -> str:
    # Format one 32-bit hexadecimal value.
    return f"0x{value & 0xFFFFFFFF:08x}"


def mode(test: str) -> int:
    # Choose the MODE register value for one generated test.
    if test == "corners":
        return 1
    if test == "random":
        return random.Random("__TOP__:" + test + ":mode").randrange(3)
    return 0


def rows(test: str = "smoke", count: int = 8):
    # Return cycle, data, coeff, and valid rows.
    if test == "smoke":
        base = [(0, 1, 1), (1, 4, 2), (2, 7, 3), (3, 8, 5)]
    elif test == "corners":
        base = [(0, 0, 1), (1, 0xFFFFFFFF, 1), (2, 0x80000000, 2), (3, 0x7FFFFFFF, 3)]
    else:
        rng = random.Random("__TOP__:" + test + ":vectors")
        base = [(i, rng.getrandbits(16), rng.getrandbits(8)) for i in range(count)]
    return [(cycle, data, coeff, 1) for cycle, data, coeff in base]


def config_lines(test: str = "smoke") -> list[str]:
    # Return default register writes; edit this for larger regmaps.
    return [
        "# format: <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]",
        "clk_i.CTRL 0x00000003",
        f"clk_i.MODE {_hex(mode(test))}",
        "clk_i.OPERAND_A 0x00000001",
        "clk_i.OPERAND_B 0x00000002",
        "clk_i.SCALE 0x00000001",
    ]


def write_test(root: str | Path, test: str = "smoke", latency: int = 2) -> None:
    # Write config.regs, data_in.vec, and data_out.vec for one test.
    folder = Path(root) / test
    folder.mkdir(parents=True, exist_ok=True)
    data_in = [
        "# format: <CYCLE> <SIGNAL> <VALUE> [<SIGNAL> <VALUE> ...]",
        "# config change: <CYCLE> @cfg <PATH_TO_CONFIG.REGS>",
    ]
    data_out = ["# format: <CYCLE> <SIGNAL> <EXPECTED> [<SIGNAL> <EXPECTED> ...]"]
    for cycle, data, coeff, valid in rows(test):
        data_in.append(f"{cycle} valid_i {_hex(valid)} data_i {_hex(data)} coeff_i {_hex(coeff)}")
        data_out.append(f"{cycle + latency} data_o {_hex(expected(data, coeff, mode(test)))} valid_o {_hex(valid)}")
    (folder / "config.regs").write_text("\n".join(config_lines(test)) + "\n", encoding="utf-8")
    (folder / "data_in.vec").write_text("\n".join(data_in) + "\n", encoding="utf-8")
    (folder / "data_out.vec").write_text("\n".join(data_out) + "\n", encoding="utf-8")


def write_all_tests(root: str | Path) -> None:
    # Write every generated test.
    for test in TESTS:
        write_test(root, test)


def write_vectors(folder: str | Path, test: str = "smoke", mode: int = 0, latency: int = 2) -> None:
    # Compatibility wrapper for older generated projects.
    del mode
    write_test(Path(folder).parent, test, latency)
'''


def render_model(top: str) -> str:
    """Render a small editable reference model and vector generator."""

    return MODEL_TEMPLATE.replace("__TOP__", top)


def write_model(top: str, output: str | Path | None = None) -> Path:
    """Write model_<top>.py and return its path."""

    folder = Path(output or ".")
    folder.mkdir(parents=True, exist_ok=True)
    path = folder / f"model_{top}.py"
    path.write_text(render_model(top), encoding="utf-8")
    return path.resolve()


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line arguments."""

    parser = argparse.ArgumentParser(description="Generate Python reference model helpers.")
    parser.add_argument("--top", required=True, help="Top module name.")
    parser.add_argument("--output-dir", dest="output", help="Output folder.")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Run model generation."""

    args = parse_args(argv)
    write_model(args.top, args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
