"""Generate small C driver helpers from an IP HJSON description."""

from __future__ import annotations

import argparse
from pathlib import Path
from typing import Any



def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse the driver generator CLI arguments."""

    parser = argparse.ArgumentParser(description="Generate C driver source/header helpers from HJSON.")
    parser.add_argument("--hjson_file", "-i", required=True, help="Path to the HJSON IP definition.")
    parser.add_argument("--base_address", "-b", default="0x80002000", help="Base address of the IP block.")
    parser.add_argument("--output_dir", "-o", default=".", help="Directory for generated files.")
    return parser.parse_args(argv)


def load_hjson(path: str | Path) -> dict[str, Any]:
    """Load one HJSON file with hjson, falling back to a tiny name parser."""

    text = Path(path).read_text(encoding="utf-8")
    try:
        import hjson  # type: ignore

        return hjson.loads(text)
    except ImportError:
        import re

        match = re.search(r"\bname\s*:\s*[\"']?([A-Za-z_][A-Za-z0-9_]*)", text)
        if match:
            return {"name": match.group(1)}
        raise


def render_header_declarations(module_name: str, base_address: str) -> str:
    """Render the C declarations injected into the generated header."""

    upper = module_name.upper()
    return "".join(
        [
            "\n",
            "#include <stdint.h>\n\n",
            f"#define {upper}_BASE {base_address}\n\n",
            f"typedef uintptr_t {module_name}_t;\n",
            f"int {module_name}_init({module_name}_t base);\n",
            f"int {module_name}_in({module_name}_t base);\n",
            f"void {module_name}_out({module_name}_t base, char c);\n",
            f"int {module_name}_putchar(int c);\n",
            f"int {module_name}_puts(const char* str);\n\n",
        ]
    )


def insert_function_declarations(header_path: str | Path, base_address: str, module_name: str) -> Path:
    """Inject the common driver declarations before the C++ guard when present."""

    path = Path(header_path)
    lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
    decls = render_header_declarations(module_name, base_address)
    index = next((i for i, line in enumerate(lines) if line.strip().startswith("#ifdef __cplusplus")), len(lines))
    path.write_text("".join(lines[:index]) + decls + "".join(lines[index:]), encoding="utf-8")
    return path


def render_uart_source(module_name: str) -> str:
    """Render the UART-specialized C driver body."""

    upper = module_name.upper()
    return f'''#include "{module_name}.h"

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
    {module_name}_out(({module_name}_t){upper}_BASE, '\\r');
  }}
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


def render_generic_source(module_name: str) -> str:
    """Render the generic memory-mapped C driver body."""

    upper = module_name.upper()
    return f'''#include "{module_name}.h"

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


def write_source(module_name: str, output_dir: str | Path) -> Path:
    """Write the selected C driver body and return the generated path."""

    path = Path(output_dir) / f"{module_name}.c"
    renderer = render_uart_source if module_name == "uart" else render_generic_source
    path.write_text(renderer(module_name), encoding="utf-8")
    return path


def generate_driver(hjson_file: str | Path, output_dir: str | Path, base_address: str) -> tuple[Path, Path]:
    """Generate header declarations and C source for one decoded IP block."""

    module_name = str(load_hjson(hjson_file)["name"])
    outdir = Path(output_dir)
    outdir.mkdir(parents=True, exist_ok=True)
    header = insert_function_declarations(outdir / f"{module_name}.h", base_address, module_name)
    source = write_source(module_name, outdir)
    return header, source


def main(argv: list[str] | None = None) -> int:
    """Run the driver generator CLI."""

    args = parse_args(argv)
    header, source = generate_driver(args.hjson_file, args.output_dir, args.base_address)
    print(f"Updated header: {header}")
    print(f"Generated source file: {source}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
