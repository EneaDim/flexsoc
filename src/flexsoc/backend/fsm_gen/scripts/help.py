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
help_fsm.py — print a short help message for the FSM generator.

This script is intentionally simple: it just prints a colorized
usage/help banner. It is meant to be invoked from the Makefile
(e.g. `make help`) and does not take any arguments.
"""


def main() -> int:
    """Print the FSM generator help banner and exit."""
    msg = (
        "\033[38;5;214m\n"
        "\n ************************************************************* \n"
        "\n *************************** HELP **************************** \n"
        "\n ************************************************************* \n"
        "\n - CONFIG"
        "\n   . Define the parameters under the Makefile"
        "\n   . Or invoke Main.py with --fsm_name, --f_clk,"
        "\n     --input-dir and --output-dir"
        "\n"
        "\n - STATE TRANSITION"
        "\n   . Describe the state transition with a txt file as"
        "\n     done in the example under examples/"
        "\n"
        "\n - OUTPUT VALUES"
        "\n   . Describe the output values for each state with a csv file as"
        "\n     done in the example under examples/"
        "\n"
        "\n - INPUT / OUTPUT DIRECTORIES"
        "\n   . Preferred mode: provide explicit --input-dir and --output-dir"
        "\n   . Legacy mode still works with tools/fsm_gen/inputs and outputs"
        "\n"
        "\n - GENERATE SV FILE"
        "\n   . Run \"make gen\" to generate the SystemVerilog file of the FSM"
        "\n"
        "\n - PLOT"
        "\n   . Run \"make plot\" to plot the FSM"
        "\n\033[0;0m"
    )
    print(msg)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
