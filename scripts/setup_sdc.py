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

def main():
    ap = argparse.ArgumentParser(description="Generate an SDC snippet and write it to a file.")
    ap.add_argument("top", help="Top module / current_design name (e.g., ibex_core)")
    ap.add_argument("clk_period", type=float, help="Clock period in ns (e.g., 10.0)")
    ap.add_argument("-o", "--out", help="Output file path (default: <top>.sdc)")
    ap.add_argument("--clk-name", default="core_clock", help="Clock name (default: core_clock)")
    ap.add_argument("--clk-port-name", default="clk_i", help="Clock port name (default: clk_i)")
    ap.add_argument("--clk-io-pct", type=float, default=0.2, help="I/O delay as fraction of period (default: 0.2)")
    args = ap.parse_args()

    sdc_text = TEMPLATE.format(
        top=args.top,
        clk_name=args.clk_name,
        clk_port_name=args.clk_port_name,
        clk_period=f"{args.clk_period:g}",
        clk_io_pct=f"{args.clk_io_pct:g}",
    )

    out_path = Path(args.out) if args.out else Path(f"{args.top}.sdc")
    out_path.write_text(sdc_text, encoding="utf-8")
    print(f"Wrote SDC to: {out_path.resolve()}")

if __name__ == "__main__":
    main()


