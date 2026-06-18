"""Generate starter HJSON metadata for a FlexSoC IP block."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

try:
    from .common import colorize, ensure_dir, safe_write_file
except Exception:  # pragma: no cover - keeps direct script execution import-safe.
    def colorize(text: str) -> str:
        """Return text unchanged when package helpers are unavailable."""

        return text

    def ensure_dir(path: str | Path) -> None:
        """Create a directory for direct script execution."""

        Path(path).mkdir(parents=True, exist_ok=True)

    def safe_write_file(path: str | Path, content: str, *, overwrite: bool = False) -> None:
        """Write a file while preserving the existing no-overwrite default."""

        target = Path(path)
        if target.exists() and not overwrite:
            raise FileExistsError(target)
        target.write_text(content, encoding="utf-8")


HJSON_TEMPLATE = r"""{{ 
  name:               "{top}",
  human_name:         "{top}",
  one_line_desc:      "",
  one_paragraph_desc: '''
  '''

  // Unique comportable IP identifier defined under KNOWN_CIP_IDS in the regtool.
  cip_id:             "1",
  design_spec:        "",
  dv_doc:             "",
  hw_checklist:       "",
  sw_checklist:       "",

  revisions: [
    {{
      version:            "1.0.0",
      life_stage:         "",
      design_stage:       "",
      verification_stage: "",
      commit_id:          "",
      notes:              ""
    }}
  ]

  clocking: [{{ clock: "clk_i", reset: "rst_ni" }}]

  bus_interfaces: [
    {{ protocol: "{itf}", direction: "device" }}
  ]

  // available_input_list: [
  //   {{ name: "input_i",  desc: "input"  }}
  // ]
  // available_output_list: [
  //   {{ name: "output_o", desc: "output" }}
  // ]

  // interrupt_list: [
  //   {{ name: "main_interrupt", desc: "main interrupt" }}
  // ]

  // alert_list: [
  //   {{
  //     name: "fatal_fault",
  //     desc: '''
  //       This fatal alert is triggered when ...
  //     '''
  //   }}
  // ]

  // features: [
  //   {{
  //     name: "feature1",
  //     desc: '''
  //       Feature 1.
  //     '''
  //   }}
  // ]

  // inter_signal_list: [
  //   {{
  //     struct: "logic",
  //     type:   "uni",
  //     name:   "trigger",
  //     desc: '''
  //       Trigger request
  //     ''',
  //     act:    "req"
  //   }}
  // ]

  // countermeasures: [
  //   {{ name: "BUS.INTEGRITY", desc: "End-to-end bus integrity scheme." }}
  // ]

  // param_list: [
  //   {{
  //     name:    "FifoDepth",
  //     desc:    "Number of bytes in the FIFO.",
  //     type:    "int",
  //     default: "64",
  //     local:   "true"
  //   }}
  // ]

  regwidth: "32"

  registers: [
    {{
      name: "CTRL",
      desc: "Control register",
      swaccess: "rw",
      hwaccess: "hro",
      fields: [
        {{ bits: "0", name: "EN", desc: "enable" }},
        {{ bits: "1", name: "RST", desc: "reset" }},
        {{ bits: "31:16", name: "SETTING", desc: "Basic setting (16 bits)." }}
      ]
    }},

    {{
      name:     "STATUS",
      desc:     "Status register",
      swaccess: "ro",
      hwaccess: "hrw",
      hwext:    "true",
      hwre:     "true",
      fields: [
        {{ bits: "0", name: "FULL", desc: "Buffer is full" }},
        {{ bits: "1", name: "EMPTY", desc: "Buffer is empty" }}
      ]
    }},

    {{
      name: "RDATA",
      desc: "read data",
      swaccess: "ro",
      hwaccess: "hrw",
      hwext: "true",
      hwre:  "true",
      fields: [{{ bits: "7:0" }}],
      tags: [
        // read wdata when fifo is empty, dut may return unknown data
        "excl:CsrAllTests:CsrExclCheck"
      ]
    }},

    {{
      name: "WDATA",
      desc: "write data",
      swaccess: "wo",
      hwaccess: "hro",
      hwqe: "true",
      fields: [{{ bits: "7:0" }}],
      tags: [
        // do not write to wdata - it affects several other CSRs
        "excl:CsrNonInitTests:CsrExclWrite"
      ]
    }}
  ]
}}
"""


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse Make-compatible HJSON generator arguments."""

    parser = argparse.ArgumentParser(
        prog="hjson_gen",
        description="Generate a starter <TOP>.hjson template for an IP.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument("-t", "-top", "--top", dest="top", required=True, help="Top module name.")
    parser.add_argument("-i", "-itf", "--itf", dest="itf", required=True, help="Bus interface, for example tlul.")
    parser.add_argument("-o", "--output", default=".", help="Output directory.")
    parser.add_argument("-f", "--force", action="store_true", help="Overwrite an existing <TOP>.hjson file.")
    return parser.parse_args(argv)


def render_hjson(top: str, itf: str) -> str:
    """Render a compact default IP HJSON document."""

    return HJSON_TEMPLATE.format(top=top, itf=itf)


def write_hjson(top: str, itf: str, output: str | Path = ".", *, force: bool = False) -> Path:
    """Write a generated HJSON file and return its path."""

    outdir = Path(output or ".")
    ensure_dir(outdir)
    path = outdir / f"{top}.hjson"
    safe_write_file(path, render_hjson(top, itf), overwrite=force)
    return path


def main(argv: list[str] | None = None) -> int:
    """Run the HJSON generator command line entrypoint."""

    try:
        args = parse_args(argv)
        top, itf = args.top.strip(), args.itf.strip()
        if not top or not itf:
            print(colorize("Error: --top and --itf must be non-empty."), file=sys.stderr)
            return 2
        write_hjson(top, itf, args.output, force=args.force)
        return 0
    except FileExistsError as err:
        print(colorize(f"Refusing to overwrite existing file: {err} (use --force)"), file=sys.stderr)
        return 1
    except KeyboardInterrupt:
        print(colorize("Aborted by user."), file=sys.stderr)
        return 130
    except Exception as err:
        print(colorize(f"Error: {err!s}"), file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
