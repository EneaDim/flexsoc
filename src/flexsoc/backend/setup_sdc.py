"""Generate a small Synopsys Design Constraints file.

The module is intentionally functional so the API layer can call it later.
"""

from __future__ import annotations

import argparse
from pathlib import Path

TEMPLATE = """current_design {top}

set clk_name {clk_name}
set clk_port_name {clk_port_name}
set clk_period {clk_period}
set clk_io_pct {clk_io_pct}

set clk_port [get_ports $clk_port_name]

create_clock -name $clk_name -period $clk_period $clk_port

set non_clock_inputs [all_inputs -no_clocks]

set_input_delay [expr $clk_period * $clk_io_pct] -clock $clk_name $non_clock_inputs
set_output_delay [expr $clk_period * $clk_io_pct] -clock $clk_name [all_outputs]
"""


def render_sdc(top: str, clk_period: float, clk_name: str = "core_clock", clk_port_name: str = "clk_i", clk_io_pct: float = 0.2) -> str:
    """Render the SDC text for one top module and clock definition."""

    return TEMPLATE.format(
        top=top,
        clk_name=clk_name,
        clk_port_name=clk_port_name,
        clk_period=f"{clk_period:g}",
        clk_io_pct=f"{clk_io_pct:g}",
    )


def write_sdc(path: Path, text: str) -> Path:
    """Write SDC text to disk and return the resolved output path."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")
    return path.resolve()


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command line arguments for standalone SDC generation."""

    parser = argparse.ArgumentParser(description="Generate an SDC snippet and write it to a file.")
    parser.add_argument("top", help="Top module / current_design name, e.g. ibex_core.")
    parser.add_argument("clk_period", type=float, help="Clock period in ns, e.g. 10.0.")
    parser.add_argument("-o", "--out", help="Output file path. Defaults to <top>.sdc.")
    parser.add_argument("--clk-name", default="core_clock", help="Clock name.")
    parser.add_argument("--clk-port-name", default="clk_i", help="Clock port name.")
    parser.add_argument("--clk-io-pct", type=float, default=0.2, help="I/O delay as a fraction of the clock period.")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Generate the requested SDC file from CLI arguments."""

    args = parse_args(argv)
    out = Path(args.out) if args.out else Path(f"{args.top}.sdc")
    text = render_sdc(args.top, args.clk_period, args.clk_name, args.clk_port_name, args.clk_io_pct)
    write_sdc(out, text)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
