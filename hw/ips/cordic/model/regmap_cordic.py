"""Python CSR map for cordic.

Auto-generated from:
  /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_reg_pkg.sv

Re-run:
  fx regmap_py --force

after updating the HJSON regmap and regenerating the RTL register package.
"""
from __future__ import annotations

from dataclasses import dataclass


TOP = 'cordic'
SOURCE = '/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_reg_pkg.sv'


@dataclass(frozen=True)
class Register:
    """One memory-mapped CSR."""

    name: str
    offset: int


REGISTERS: dict[str, Register] = {
    'CTRL': Register(name='CTRL', offset=0x00000000),
    'STATUS': Register(name='STATUS', offset=0x00000004),
    'X_IN': Register(name='X_IN', offset=0x00000008),
    'Y_IN': Register(name='Y_IN', offset=0x0000000c),
    'Z_IN': Register(name='Z_IN', offset=0x00000010),
    'X_OUT': Register(name='X_OUT', offset=0x00000014),
    'Y_OUT': Register(name='Y_OUT', offset=0x00000018),
    'Z_OUT': Register(name='Z_OUT', offset=0x0000001c),
    'CFG': Register(name='CFG', offset=0x00000020),
}

CTRL_OFFSET = 0x00000000
STATUS_OFFSET = 0x00000004
X_IN_OFFSET = 0x00000008
Y_IN_OFFSET = 0x0000000c
Z_IN_OFFSET = 0x00000010
X_OUT_OFFSET = 0x00000014
Y_OUT_OFFSET = 0x00000018
Z_OUT_OFFSET = 0x0000001c
CFG_OFFSET = 0x00000020


def addr(name: str) -> int:
    """Return the byte offset of a CSR by symbolic name."""

    key = name.upper()
    try:
        return REGISTERS[key].offset
    except KeyError as exc:
        known = ", ".join(sorted(REGISTERS))
        raise KeyError(f"unknown {TOP} register {name!r}; known: {known}") from exc


def has(name: str) -> bool:
    """Return True when a CSR name exists."""

    return name.upper() in REGISTERS


def names() -> tuple[str, ...]:
    """Return register names in generated order."""

    return tuple(REGISTERS)


def config_write(name: str, data: int, *, clock: str = "clk_i") -> str:
    """Format one config.regs write row for generated SV tests."""

    return f"{clock}.{name.upper()} 0x{data & 0xFFFF_FFFF:08x}"
