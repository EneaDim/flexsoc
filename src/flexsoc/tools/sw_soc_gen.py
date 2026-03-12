from __future__ import annotations

import argparse
import shutil
import sys
from pathlib import Path


BOOT_S = r"""# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0.

.section .text

default_exc_handler:
  j default_exc_handler

reset_handler:
  mv  x1, x0
  mv  x2, x1
  mv  x3, x1
  mv  x4, x1
  mv  x5, x1
  mv  x6, x1
  mv  x7, x1
  mv  x8, x1
  mv  x9, x1
  mv x10, x1
  mv x11, x1
  mv x12, x1
  mv x13, x1
  mv x14, x1
  mv x15, x1
  mv x16, x1
  mv x17, x1
  mv x18, x1
  mv x19, x1
  mv x20, x1
  mv x21, x1
  mv x22, x1
  mv x23, x1
  mv x24, x1
  mv x25, x1
  mv x26, x1
  mv x27, x1
  mv x28, x1
  mv x29, x1
  mv x30, x1
  mv x31, x1

  la   x2, _stack_start

_start:
  .global _start

  la x26, _bss_start
  la x27, _bss_end

  bge x26, x27, zero_loop_end

zero_loop:
  sw x0, 0(x26)
  addi x26, x26, 4
  ble x26, x27, zero_loop
zero_loop_end:

main_entry:
  addi x10, x0, 0
  addi x11, x0, 0
  jal x1, main

sleep_loop:
  wfi
  j sleep_loop

  .section .vectors, "ax"
  .option norvc;

  .org 0x00
  .rept 32
  jal x0, default_exc_handler
  .endr

  .org 0x80
  jal x0, reset_handler
"""

LINK_LD = r"""OUTPUT_ARCH(riscv)

MEMORY
{
    ram   : ORIGIN = 0x00100000, LENGTH = 0x1F000
    stack : ORIGIN = 0x0011F000, LENGTH = 0x01000
}

_min_stack    = 0x1000;
_stack_len    = LENGTH(stack);
_stack_start  = ORIGIN(stack) + LENGTH(stack);

_entry_point = _vectors_start + 0x80;
ENTRY(_entry_point)

PROVIDE(_stext = ORIGIN(ram));
PROVIDE(_stack_start = ORIGIN(stack) + LENGTH(stack));
PROVIDE(_max_hart_id = 0);
PROVIDE(_hart_stack_size = LENGTH(stack));
PROVIDE(_heap_size = 0);
PROVIDE(UserSoft = DefaultHandler);
PROVIDE(SupervisorSoft = DefaultHandler);
PROVIDE(MachineSoft = DefaultHandler);
PROVIDE(UserTimer = DefaultHandler);
PROVIDE(SupervisorTimer = DefaultHandler);
PROVIDE(MachineTimer = DefaultHandler);
PROVIDE(UserExternal = DefaultHandler);
PROVIDE(SupervisorExternal = DefaultHandler);
PROVIDE(MachineExternal = DefaultHandler);
PROVIDE(DefaultHandler = DefaultInterruptHandler);
PROVIDE(ExceptionHandler = DefaultExceptionHandler);
PROVIDE(__pre_init = default_pre_init);
PROVIDE(_mp_hook = default_mp_hook);
PROVIDE(_start_trap = default_start_trap);
PROVIDE(_setup_interrupts = default_setup_interrupts);

SECTIONS
{
    .text : {
        . = ALIGN(4);
        _vectors_start = .;
        KEEP(*(.vectors))
        _vectors_end = .;
        *(.text)
        *(.text.*)
        . = ALIGN(4);
    } > ram

    .rodata : {
        . = ALIGN(4);
        *(.srodata)
        *(.srodata.*)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
    } > ram

    .data : {
        . = ALIGN(4);
        *(.sdata)
        *(.sdata.*)
        *(.data)
        *(.data.*)
        . = ALIGN(4);
    } > ram

    .bss : {
        . = ALIGN(4);
        _bss_start = .;
        *(.sbss)
        *(.sbss.*)
        *(.bss)
        *(.bss.*)
        *(COMMON)
        _bss_end = .;
        . = ALIGN(4);
    } > ram

    _sbss = _bss_start;
    _ebss = _bss_end;

    .stack (NOLOAD): {
        . = ALIGN(4);
        . = . + _min_stack;
        . = ALIGN(4);
        stack = .;
        _stack = .;
    } > stack
}
"""


def run_dir(workspace: Path, run_top: str, run_id: str) -> Path:
    return workspace / "runs" / run_top / run_id


def copy_driver_files(ips_dir: Path, sw_dir: Path) -> list[str]:
    if not ips_dir.exists():
        raise SystemExit(f"ERROR: missing loaded IP directory: {ips_dir}")

    copied_modules: list[str] = []

    for ip_dir in sorted((p for p in ips_dir.iterdir() if p.is_dir()), key=lambda p: p.name):
        drv_dir = ip_dir / "drivers"
        if not drv_dir.exists():
            continue

        copied_any = False
        for ext in ("*.h", "*.c"):
            for src in sorted(drv_dir.glob(ext)):
                shutil.copy2(src, sw_dir / src.name)
                copied_any = True

        if copied_any:
            copied_modules.append(ip_dir.name)

    return copied_modules


def generate_main_c(sw_dir: Path, modules: list[str]) -> None:
    includes = [f'#include "{mod}.h"' for mod in sorted(modules)]

    body = ["int main(void) {"]

    for mod in modules:
        body.append(f"  {mod}_init(({mod}_t){mod.upper()}_BASE);")

    if "uart" in modules:
        body.append('  uart_puts("FlexSoC SoC boot\\n");')
        body.append("  (void)uart_in((uart_t)UART_BASE);")

    body.append("  for (;;) {")
    if "uart" in modules:
        body.append("    int ch = uart_in((uart_t)UART_BASE);")
        body.append("    if (ch >= 0) {")
        body.append("      uart_putchar(ch);")
        body.append("    }")
    body.append("  }")
    body.append("  return 0;")
    body.append("}")

    text = f"""{chr(10).join(includes)}

{chr(10).join(body)}
"""
    (sw_dir / "main.c").write_text(text, encoding="utf-8")


def generate_makefile(sw_dir: Path, modules: list[str]) -> None:
    c_modules = ["main"] + modules
    obj_list = " ".join(f"$(BUILD_DIR)/{m}.o" for m in c_modules) + " $(BUILD_DIR)/boot.o"

    text = f"""CC = riscv32-unknown-elf-gcc
CFLAGS = -march=rv32imc -mabi=ilp32 -static -mcmodel=medany -Wall -g -fvisibility=hidden -ffreestanding
LDFLAGS = -nostdlib -nostartfiles -T link.ld
BUILD_DIR = build

OBJS = {obj_list}

all: $(BUILD_DIR)/main.elf

$(BUILD_DIR):
\tmkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
\t$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/boot.o: boot.S | $(BUILD_DIR)
\t$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.elf: $(OBJS)
\t$(CC) $(LDFLAGS) $(OBJS) -o $@

clean:
\trm -rf $(BUILD_DIR)

.PHONY: all clean
"""
    (sw_dir / "Makefile").write_text(text, encoding="utf-8")


def main():
    ap = argparse.ArgumentParser(description="Generate SoC software workspace from loaded IP drivers.")
    ap.add_argument("--workspace", required=True)
    ap.add_argument("--run-top", required=True)
    ap.add_argument("--run-id", required=True)
    args = ap.parse_args()

    ws = Path(args.workspace).expanduser().resolve()
    rd = run_dir(ws, args.run_top, args.run_id)
    ips_dir = rd / "ips"
    sw_dir = rd / "sw"
    sw_dir.mkdir(parents=True, exist_ok=True)

    modules = copy_driver_files(ips_dir, sw_dir)
    if not modules:
        raise SystemExit(f"ERROR: no driver files found under loaded IPs: {ips_dir}")

    (sw_dir / "boot.S").write_text(BOOT_S, encoding="utf-8")
    (sw_dir / "link.ld").write_text(LINK_LD, encoding="utf-8")
    generate_main_c(sw_dir, modules)
    generate_makefile(sw_dir, modules)

    print(f"Generated SoC software under: {sw_dir}")
    print(f"Modules: {', '.join(modules)}")


if __name__ == "__main__":
    main()
