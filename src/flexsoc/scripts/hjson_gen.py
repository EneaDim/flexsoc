# ruff: noqa
#!/usr/bin/env python3
# Copyright 2025 Enea Dimroci
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
r"""
\file hjson_gen.py
\brief Generate a starter .hjson file for a new IP.
\details
  Creates <TOP>.hjson with sensible defaults and commented sections to guide edits.

  ## CLI (legacy-compatible)
    - -top / -t / --top    : TOP module name (required)
    - -itf / -i / --itf    : bus interface (e.g., "tlul") (required)
    - -o / --output        : output folder (default: current directory)
    - -f / --force         : overwrite existing <TOP>.hjson if present

  Behavior:
    - Creates the output folder if it does not exist.
    - Refuses to overwrite unless --force is provided.
    - Exits with code 0 on success, >0 on error.
"""

from __future__ import annotations

import argparse
import os
import sys

# Shared helpers
try:
    from .common import colorize, ensure_dir, safe_write_file
except Exception:  # pragma: no cover
    def colorize(s: str) -> str: return s
    def ensure_dir(path: str) -> None:
        os.makedirs(path, exist_ok=True)
    def safe_write_file(path: str, content: str, *, overwrite: bool = False) -> None:
        if (not overwrite) and os.path.exists(path):
            raise FileExistsError(path)
        with open(path, "w", encoding="utf-8") as f:
            f.write(content)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    r"""
    \brief Parse command-line arguments (supports legacy flags).
    \details
      Attributes:
        - top: TOP module name (required)
        - itf: bus interface (required, e.g., "tlul")
        - output: destination directory (default ".")
        - force: bool to allow overwriting existing file
    """
    parser = argparse.ArgumentParser(
        prog="hjson_gen",
        description="Generate a starter <TOP>.hjson template for an IP.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument("-t", "-top", "--top", dest="top", required=True,
                        help="Define the TOP module in the design (e.g., my_ip).")
    parser.add_argument("-i", "-itf", "--itf", dest="itf", required=True,
                        help='Define the register interface (e.g., "tlul").')
    parser.add_argument("-o", "--output", dest="output", default=".",
                        help="Output folder (created if missing).")
    parser.add_argument("-f", "--force", dest="force", action="store_true",
                        help="Overwrite <TOP>.hjson if it already exists.")
    return parser.parse_args(argv)


def render_hjson(top: str, itf: str) -> str:
    r"""
    \brief Build the HJSON document content.
    \details Raw triple double-quoted string safely contains ''' blocks.
            Double braces emit literal { } with .format().
    """
    return r"""{{ 
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
        {{
          bits: "0",
          name: "EN",
          desc: "enable"
        }},
        {{
          bits: "1",
          name: "RST",
          desc: "reset"
        }},
        {{
          bits: "31:16",
          name: "SETTING",
          desc: "Basic setting (16 bits)."
        }}
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
        {{
          bits: "0",
          name: "FULL",
          desc: "Buffer is full"
        }},
        {{
          bits: "1",
          name: "EMPTY",
          desc: "Buffer is empty"
        }}
      ]
    }},

    {{
      name: "RDATA",
      desc: "read data",
      swaccess: "ro",
      hwaccess: "hrw",
      hwext: "true",
      hwre:  "true",
      fields: [
        {{ bits: "7:0" }}
      ],
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
      fields: [
        {{ bits: "7:0" }}
      ],
      tags: [
        // do not write to wdata - it affects several other CSRs
        "excl:CsrNonInitTests:CsrExclWrite"
      ]
    }}
  ]
}}
""".format(top=top, itf=itf)


def main(argv: list[str] | None = None) -> int:
    r"""
    \brief Entry point.
    \details Flow: parse args → validate → ensure dir → write (honor --force).
    \returns 0 on success; 2 on bad args; 1 on error; 130 on Ctrl-C.
    """
    try:
        args = parse_args(argv)

        top = (args.top or "").strip()
        itf = (args.itf or "").strip()
        outdir = (args.output or ".").strip() or "."
        force = bool(args.force)

        if not top:
            print(colorize("Error: --top must be a non-empty string."), file=sys.stderr)
            return 2
        if not itf:
            print(colorize("Error: --itf must be a non-empty string."), file=sys.stderr)
            return 2

        ensure_dir(outdir)

        outfile = os.path.join(outdir, f"{top}.hjson")
        try:
            safe_write_file(outfile, render_hjson(top, itf), overwrite=force)
        except FileExistsError:
            print(colorize(f"Refusing to overwrite existing file: {outfile} (use --force)"),
                  file=sys.stderr)
            return 1

        #print(colorize(f"Generated: {outfile}"))
        return 0

    except KeyboardInterrupt:
        print(colorize("Aborted by user."), file=sys.stderr)
        return 130
    except Exception as err:
        tb = sys.exc_info()[2]
        line = tb.tb_lineno if tb and tb.tb_frame else "?"
        print(colorize(f"Error at line {line}: {err!s}"), file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
