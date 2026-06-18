# ruff: noqa
import argparse
import os
from pathlib import Path

import hjson


def parse_args():
    parser = argparse.ArgumentParser(description="Generate C driver source/header helpers from HJSON.")
    parser.add_argument("--hjson_file", "-i", required=True, help="Path to the HJSON IP definition.")
    parser.add_argument("--base_address", "-b", default="0x80002000", help="Base address of the IP block.")
    parser.add_argument("--output_dir", "-o", default=".", help="Directory for generated files.")
    return parser.parse_args()


def insert_function_declarations(header_path, base_address, module_name):
    with open(header_path, "r", encoding="utf-8") as f:
        lines = f.readlines()

    base_upper = module_name.upper()
    decls = [
        "\n",
        "#include <stdint.h>\n\n",
        f"#define {base_upper}_BASE {base_address}\n\n",
        f"typedef uintptr_t {module_name}_t;\n",
        f"int {module_name}_init({module_name}_t base);\n",
        f"int {module_name}_in({module_name}_t base);\n",
        f"void {module_name}_out({module_name}_t base, char c);\n",
        f"int {module_name}_putchar(int c);\n",
        f"int {module_name}_puts(const char* str);\n",
        "\n",
    ]

    insert_index = None
    for i, line in enumerate(lines):
        if line.strip().startswith("#ifdef __cplusplus"):
            insert_index = i
            break

    if insert_index is None:
        lines.extend(decls)
    else:
        lines = lines[:insert_index] + decls + lines[insert_index:]

    with open(header_path, "w", encoding="utf-8") as f:
        f.writelines(lines)

    print(f"Updated header: {header_path}")


def generate_uart_source(module_name, output_dir):
    source_file = Path(output_dir) / f"{module_name}.c"
    text = f'''#include "{module_name}.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

#ifndef BAUD_RATE
#define BAUD_RATE 115200u
#endif

#ifndef SYSCLK_FREQ
#define SYSCLK_FREQ 50000000u
#endif

#ifndef UART_EOF
#define UART_EOF (-1)
#endif

int {module_name}_init({module_name}_t base) {{
  uint32_t nco = (uint32_t)(((uint64_t)BAUD_RATE << 20) / SYSCLK_FREQ);
  DEV_WRITE(base + UART_CTRL_REG_OFFSET, (nco << 16) | 0x3U);
  return 0;
}}

int {module_name}_in({module_name}_t base) {{
  int res = UART_EOF;
#ifdef UART_STATUS_REG_OFFSET
#ifdef UART_STATUS_RXEMPTY_BIT
  if (!(DEV_READ(base + UART_STATUS_REG_OFFSET) & (1u << UART_STATUS_RXEMPTY_BIT))) {{
    res = (int)DEV_READ(base + UART_RDATA_REG_OFFSET);
  }}
#else
  res = (int)DEV_READ(base + UART_RDATA_REG_OFFSET);
#endif
#else
  res = (int)DEV_READ(base + UART_RDATA_REG_OFFSET);
#endif
  return res;
}}

void {module_name}_out({module_name}_t base, char c) {{
#ifdef UART_STATUS_REG_OFFSET
#ifdef UART_STATUS_TXFULL_BIT
  while (DEV_READ(base + UART_STATUS_REG_OFFSET) & (1u << UART_STATUS_TXFULL_BIT)) {{
  }}
#endif
#endif
  DEV_WRITE(base + UART_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
}}

int {module_name}_putchar(int c) {{
  if (c == '\\n') {{
    {module_name}_out(({module_name}_t){module_name.upper()}_BASE, '\\r');
  }}
  {module_name}_out(({module_name}_t){module_name.upper()}_BASE, (char)c);
  return c;
}}

int {module_name}_puts(const char* str) {{
  while (*str) {{
    {module_name}_putchar(*str++);
  }}
  return 0;
}}
'''
    source_file.write_text(text, encoding="utf-8")
    print(f"Generated source file: {source_file}")


def generate_generic_source(module_name, output_dir):
    source_file = Path(output_dir) / f"{module_name}.c"
    upper = module_name.upper()
    text = f'''#include "{module_name}.h"

#define DEV_WRITE(addr, val) (*((volatile uint32_t *)(uintptr_t)(addr)) = (uint32_t)(val))
#define DEV_READ(addr) (*((volatile uint32_t *)(uintptr_t)(addr)))

int {module_name}_init({module_name}_t base) {{
#ifdef {upper}_CTRL_REG_OFFSET
  DEV_WRITE(base + {upper}_CTRL_REG_OFFSET, 0x1u);
#else
  DEV_WRITE(base + 0x0u, 0x1u);
#endif
  return 0;
}}

int {module_name}_in({module_name}_t base) {{
#ifdef {upper}_RDATA_REG_OFFSET
  return (int)DEV_READ(base + {upper}_RDATA_REG_OFFSET);
#else
  return (int)DEV_READ(base + 0x0u);
#endif
}}

void {module_name}_out({module_name}_t base, char c) {{
#ifdef {upper}_WDATA_REG_OFFSET
  DEV_WRITE(base + {upper}_WDATA_REG_OFFSET, (uint32_t)(uint8_t)c);
#else
  DEV_WRITE(base + 0x0u, (uint32_t)(uint8_t)c);
#endif
}}

int {module_name}_putchar(int c) {{
  {module_name}_out(({module_name}_t){upper}_BASE, (char)c);
  return c;
}}

int {module_name}_puts(const char* str) {{
  while (*str) {{
    {module_name}_putchar(*str++);
  }}
  return 0;
}}
'''
    source_file.write_text(text, encoding="utf-8")
    print(f"Generated source file: {source_file}")


def main():
    args = parse_args()

    with open(args.hjson_file, "r", encoding="utf-8") as f:
        data = hjson.load(f)

    module_name = data["name"]
    outdir = Path(args.output_dir)
    outdir.mkdir(parents=True, exist_ok=True)

    header_file = outdir / f"{module_name}.h"
    insert_function_declarations(str(header_file), args.base_address, module_name)

    if module_name == "uart":
        generate_uart_source(module_name, outdir)
    else:
        generate_generic_source(module_name, outdir)


if __name__ == "__main__":
    main()
