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

import hjson
import argparse
import os

def parse_args():
    parser = argparse.ArgumentParser(description="Generate C driver source from HJSON and inject declarations into existing header.")
    parser.add_argument("--hjson_file", "-i", required=True, help="Path to the HJSON IP definition.")
    parser.add_argument("--base_address", "-b", default="0x80002000", help="Base address of the IP block.")
    parser.add_argument("--output_dir", "-o", default=".", help="Directory for generated .c source file.")
    return parser.parse_args()

def insert_function_declarations(header_path, base_address, module_name):
    with open(header_path, "r") as f:
        lines = f.readlines()

    decls = [
        f"\n",
        f"#include <stdint.h>\n\n",
        f"#define {module_name.upper()}_BASE {base_address}\n\n",
        f"typedef void* {module_name}_t;\n",
        f"int {module_name}_init({module_name}_t {module_name});\n",
        f"int {module_name}_in({module_name}_t {module_name});\n",
        f"void {module_name}_out({module_name}_t {module_name}, char c);\n",
        f"int {module_name}_putchar(int c);\n",
        f"int {module_name}_puts(const char* str);\n",
        "\n"
    ]

    insert_index = None
    for i, line in enumerate(lines):
        if line.strip().startswith("#ifdef __cplusplus"):
            insert_index = i
            break

    if insert_index is not None:
        lines = lines[:insert_index] + decls + lines[insert_index:]
        with open(header_path, "w") as f:
            f.writelines(lines)
        print(f"Inserted function declarations into: {header_path}")
    else:
        print("Warning: Couldn't find insertion point in header file.")

def generate_source_file(module_name, output_dir):
    base_name = module_name.upper()
    source_file = os.path.join(output_dir, f"{module_name}.c")

    lines = [
        f'#include "{module_name}.h"\n',
        "#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(addr)) = (val))",
        "#define DEV_READ(addr) (*((volatile uint32_t *)(addr)))\n",

        f"int {module_name}_init({module_name}_t {module_name}) {{",
        f"  DEV_WRITE({module_name} + {base_name}_CTRL_REG_OFFSET, 0x1);",
        "  return 0;",
        "}\n",

        f"int {module_name}_in({module_name}_t {module_name}) {{",
        f"  int res = -1;",
        f"  res = DEV_READ({module_name} + {base_name}_RDATA_REG_OFFSET);",
        "  return res;",
        "}\n",

        f"void {module_name}_out({module_name}_t {module_name}, char c) {{",
        f"  DEV_WRITE({module_name} + {base_name}_WDATA_REG_OFFSET, c);",
        "}\n",

        f"int {module_name}_putchar(int c) {{",
        f"  {module_name}_out(({module_name}_t) {base_name}_BASE, c);",
        "  return c;",
        "}\n",

        f"int {module_name}_puts(const char* str) {{",
        "  while (*str) {",
        f"    {module_name}_putchar(*str++);",
        "  }",
        "  return 0;",
        "}"
    ]

    os.makedirs(output_dir, exist_ok=True)
    with open(source_file, "w") as f:
        f.write("\n".join(lines))

    print(f"Generated source file: {source_file}")

def main():
    args = parse_args()

    with open(args.hjson_file, "r") as f:
        data = hjson.load(f)

    module_name = data["name"]

    # Modify header
    header_file = args.output_dir + '/' + module_name + '.h'
    insert_function_declarations(header_file, args.base_address, module_name)

    # Generate C source file
    generate_source_file(module_name, args.output_dir)

if __name__ == "__main__":
    main()

