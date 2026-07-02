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

"""
@file Main.py
@brief Command-line entry point for generating SystemVerilog and Graphviz
       artifacts from a textual FSM description.

This script parses command-line arguments, instantiates the Interface class and
invokes the high-level generation methods.
"""

from __future__ import annotations

import argparse
import sys
import traceback
from pathlib import Path

import Interface as itf


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(
        description=(
            "FSM generator: from .txt/.csv FSM descriptions to "
            "SystemVerilog, Graphviz, and testbench files."
        ),
    )

    parser.add_argument(
        "-fsm_name",
        "--fsm_name",
        required=True,
        help=(
            "Base name of the FSM (without extension). "
            "The tool expects '<fsm_name>.txt' and '<fsm_name>.csv' "
            "inside the selected input directory."
        ),
    )

    parser.add_argument(
        "-f_clk",
        "--f_clk",
        type=int,
        required=True,
        help="Clock frequency in MHz to be used in the generated testbench.",
    )

    parser.add_argument(
        "--input-dir",
        type=Path,
        default=None,
        help=(
            "Directory containing FSM input files. "
            "If omitted, the bundled tools/fsm_gen/inputs directory is used."
        ),
    )

    parser.add_argument(
        "--output-dir",
        type=Path,
        default=None,
        help=(
            "Directory where generated artifacts are written. "
            "If omitted, the bundled tools/fsm_gen/outputs directory is used."
        ),
    )

    parser.add_argument(
        "--verbose-paths",
        action="store_true",
        help="Print resolved input/output directories.",
    )

    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Main entry point."""
    try:
        args = parse_args(argv)
        fsm_name: str = args.fsm_name
        f_clk: int = args.f_clk
        input_dir: Path | None = args.input_dir
        output_dir: Path | None = args.output_dir

        interface = itf.Interface(
            "FSM Interface from .gv and .csv to SystemVerilog Modules",
            inputs_dir=input_dir,
            outputs_dir=output_dir,
        )

        if args.verbose_paths:
            print(f"[fsm_gen] input_dir : {interface.inputs_dir}", file=sys.stderr)
            print(f"[fsm_gen] output_dir: {interface.outputs_dir}", file=sys.stderr)

        interface.read_inputs(fsm_name)
        interface.write_sv()
        interface.write_gv()
        interface.states_walkthrough()
        interface.write_tb(f_clk)

        return 0

    except Exception as exc:
        print("\033[38;5;208m[ERROR] An unhandled exception occurred:\033[0m", file=sys.stderr)
        print(f"  Type : {type(exc).__name__}", file=sys.stderr)
        print(f"  Error: {exc}", file=sys.stderr)
        print("  Traceback:", file=sys.stderr)
        traceback.print_exc(limit=5, file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
