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
import hjson
import os

def parse_bitrange(bits):
    """Convert bits string like '31:16' or '7' into SystemVerilog bit width [N-1:0]"""
    if ':' in bits:
        hi, lo = map(int, bits.split(':'))
        width = abs(hi - lo) + 1
        return f"[{width - 1}:0]", width
    else:
        return "", 1

def get_bit_width(bits):
    if ":" in bits:
        msb, lsb = map(int, bits.split(":"))
        return abs(msb - lsb) + 1
    else:
        return 1

def generate_top_module(data):
    module_name = data["name"]
    reg_pkg = f"{module_name}_reg_pkg"
    reg2hw_struct = f"{module_name}_reg2hw_t"
    hw2reg_struct = f"{module_name}_hw2reg_t"

    fifo_param = "3"
    for param in data.get("param_list", []):
        if param["name"].lower() == "fifodepth":
            fifo_param = param.get("default", "3")

    signal_defs = []
    ctrl2reg_assignments = []
    reg2ctrl_assignments = []

    for reg in data.get("registers", []):
        reg_name = reg["name"].lower()
        swaccess = reg.get("swaccess", "")
        hwaccess = reg.get("hwaccess", "")
        hwqe = reg.get("hwqe", False)
        hwre = reg.get("hwre", False)
        fields = reg.get("fields", [])

        if len(fields) == 1 and "name" not in fields[0]:
            field_name = reg_name
            bits = fields[0]["bits"]
        else:
            for field in fields:
                if "name" not in field:
                    field_name = reg_name
                    bits = field["bits"]
                    break
            else:
                for field in fields:
                    field_name = field["name"].lower()
                    bits = field["bits"]

                    if swaccess in ["rw", "wo"]:
                        ctrl2reg_assignments.append(
                            f"  assign {field_name} = reg2hw.{reg_name}.{field_name}.q;"
                        )
                        if hwqe:
                            valid_name = f"{field_name}_valid"
                            signal_defs.append(f"  logic {valid_name};")
                            ctrl2reg_assignments.append(
                                f"  assign {valid_name} = reg2hw.{reg_name}.{field_name}.qe;"
                            )
                        if hwre:
                            ready_name = f"{field_name}_ready"
                            signal_defs.append(f"  logic {ready_name};")
                            ctrl2reg_assignments.append(
                                f"  assign {ready_name} = reg2hw.{reg_name}.{field_name}.re;"
                            )

                    if swaccess == "ro" and hwaccess in ["hrw", "hro"]:
                        if len(fields) == 1 and "name" not in fields[0]:
                            field_name = reg_name
                            bits = fields[0]["bits"]
                            width = get_bit_width(bits)
                            signal_defs.append(f"  logic [{width - 1}:0] {field_name};")
                            reg2ctrl_assignments.append(
                                f"  assign hw2reg.{reg_name}.d = {field_name};"
                            )
                        else:
                            for field in fields:
                                field_name = field.get("name", reg_name).lower()
                                bits = field["bits"]
                                width = get_bit_width(bits)
                                signal_defs.append(f"  logic [{width - 1}:0] {field_name};")
                                reg2ctrl_assignments.append(
                                    f"  assign hw2reg.{reg_name}.{field_name}.d = {field_name};"
                                )
                continue

        # Handle unnamed single-field register (direct access)
        width = get_bit_width(bits)
        signal_defs.append(f"  logic [{width - 1}:0] {field_name};")

        if swaccess in ["rw", "wo"]:
            ctrl2reg_assignments.append(
                f"  assign {field_name} = reg2hw.{reg_name}.q;"
            )
            if hwqe:
                valid_name = f"{field_name}_valid"
                signal_defs.append(f"  logic {valid_name};")
                ctrl2reg_assignments.append(
                    f"  assign {valid_name} = reg2hw.{reg_name}.qe;"
                )
            if hwre:
                ready_name = f"{field_name}_ready"
                signal_defs.append(f"  logic {ready_name};")
                ctrl2reg_assignments.append(
                    f"  assign {ready_name} = reg2hw.{reg_name}.re;"
                )
    
        if swaccess == "ro" and hwaccess in ["hrw", "hro"]:
            reg2ctrl_assignments.append(
                f"  assign hw2reg.{reg_name}.d = {field_name};"
            )

    # Assemble module
    sv_lines = [f"module {module_name}_core",
                f"  import {reg_pkg}::*;",
                f"#(",
                f"  parameter int unsigned FifoDepth={fifo_param}",
                f")(",
                f"  input        clk_i,",
                f"  input        rst_ni,",
                f"  input  {reg2hw_struct} reg2hw,",
                f"  output {hw2reg_struct} hw2reg,\n",
                f"  //TODO: put the IP IOs",
                f"  input  logic port_i,",
                f"  output logic port_o",
                f");",
                "",
                "  //////////////",
                "  // Signals   //",
                "  //////////////"
                ]
    sv_lines += signal_defs
    sv_lines += ["", "  //////////////", "  // CTRL2REG  //", "  //////////////"]
    sv_lines += ctrl2reg_assignments
    sv_lines += ["", "  //////////////", "  // REG2CTRL  //", "  //////////////"]
    sv_lines += reg2ctrl_assignments
    sv_lines.append("\n  //TODO: put your logic here\n")
    sv_lines.append("  prim_ff_2sync #(")
    sv_lines.append("    .Width(1),")
    sv_lines.append("    .ResetValue('0)")
    sv_lines.append("  ) u_sync_name (")
    sv_lines.append("    .clk_i(clk_i),")
    sv_lines.append("    .rst_ni(rst_ni),")
    sv_lines.append("    .d_i(port_i),")
    sv_lines.append("    .q_o(port_o)")
    sv_lines.append("  );\n")

    sv_lines.append("endmodule")
    return "\n".join(sv_lines)

def generate_top_wrapper(data):
    module_name = data["name"]
    reg_pkg = f"{module_name}_reg_pkg"
    core_inst = f"u_{module_name}_core"
    reg_inst = f"u_{module_name}_reg"
    fifo_param = "3"

    for param in data.get("param_list", []):
        if param["name"].lower() == "fifodepth":
            fifo_param = param.get("default", "3")

    wrapper = f"""module {module_name}
  import {reg_pkg}::*;
#(
  parameter int unsigned FifoDepth={fifo_param}
)(
  // CLK & RSTN
  input           clk_i,
  input           rst_ni,

  // Bus Interface
  input  tlul_pkg::tl_h2d_t tl_i,
  output tlul_pkg::tl_d2h_t tl_o,

  // IO
  input  logic port_i,
  output logic port_o
);

  {module_name}_reg2hw_t reg2hw;
  {module_name}_hw2reg_t hw2reg;

  {module_name}_reg_top {reg_inst} (
    .clk_i,
    .rst_ni,
    .tl_i,
    .tl_o,
    .reg2hw,
    .hw2reg
  );

  {module_name}_core #(
    .FifoDepth(FifoDepth)
  ) {core_inst} (
    .clk_i,
    .rst_ni,
    .reg2hw,
    .hw2reg,
    .port_i,
    .port_o
  );

endmodule
"""
    return wrapper


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--hjson_file", "-i", help="Input HJSON file path")
    parser.add_argument("--output-dir", "-o", default=".", help="Directory to write output .sv file")
    args = parser.parse_args()

    with open(args.hjson_file, 'r') as f:
        data = hjson.load(f)

    top_sv = generate_top_module(data)
    wrapper_sv = generate_top_wrapper(data)

    os.makedirs(args.output_dir, exist_ok=True)
    out_file = os.path.join(args.output_dir, f"{data['name']}_core.sv")
    wrapper_file = os.path.join(args.output_dir, f"{data['name']}.sv")
    with open(out_file, 'w') as f:
        f.write(top_sv)
    with open(wrapper_file, 'w') as f:
        f.write(wrapper_sv)

if __name__ == "__main__":
    main()

