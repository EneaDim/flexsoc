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

import Interface as itf


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """!
    @brief Parse command-line arguments.

    @param argv Optional list of arguments, mainly for unit tests. If None,
                arguments are taken from sys.argv.

    @return Parsed arguments as an argparse.Namespace instance.
    """
    parser = argparse.ArgumentParser(
        description="FSM generator: from .txt/.csv FSM descriptions to "
                    "SystemVerilog and Graphviz (.gv) files.",
    )

    parser.add_argument(
        "-fsm_name",
        "--fsm_name",
        required=True,
        help="Base name of the FSM (without extension). "
             "The tool expects '<fsm_name>.txt' and '<fsm_name>.csv' "
             "inside the 'inputs/' directory.",
    )

    parser.add_argument(
        "-f_clk",
        "--f_clk",
        type=int,
        required=True,
        help="Clock frequency in MHz to be used in the generated testbench.",
    )

    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """!
    @brief Main entry point.

    This function:
      - parses the command-line arguments,
      - instantiates the Interface object,
      - triggers the generation of SystemVerilog and Graphviz files,
      - optionally generates a testbench.

    @param argv Optional list of arguments, mainly for unit tests. If None,
                arguments are taken from sys.argv.

    @return Process exit code (0 on success, non-zero on error).
    """
    try:
        args = parse_args(argv)
        fsm_name: str = args.fsm_name
        f_clk: int = args.f_clk

        interface = itf.Interface(
            "FSM Interface from .gv and .csv to SystemVerilog Modules"
        )

        # Read and parse the FSM sources (TXT + CSV)
        interface.read_inputs(fsm_name)

        # Generate outputs
        interface.write_sv()
        interface.write_gv()
        interface.states_walkthrough()
        interface.write_tb(f_clk)

        return 0

    except Exception as exc:  # Catch any unexpected error and report nicely.
        # Print a concise error and a short traceback to stderr.
        print("\033[38;5;208m[ERROR] An unhandled exception occurred:\033[0m",
              file=sys.stderr)
        print(f"  Type : {type(exc).__name__}", file=sys.stderr)
        print(f"  Error: {exc}", file=sys.stderr)
        print("  Traceback:", file=sys.stderr)
        traceback.print_exc(limit=5, file=sys.stderr)
        return 1


if __name__ == "__main__":
    # Delegate to main() and use its return value as process exit code.
    sys.exit(main())

