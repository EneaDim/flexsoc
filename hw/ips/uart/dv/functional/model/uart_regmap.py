"""Generated model-side CSR map for uart.

HJSON source(s): uart.hjson.
Regenerate with ``fx regmap_py --force``. Behavioral code belongs in
``uart_model.py`` and test scenarios belong in ``uart_tests.py``.
"""
from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

TOP = 'uart'
PRIMARY_DOMAIN = 'clk_i'


@dataclass(frozen=True)
class Field:
    name: str
    lsb: int
    msb: int
    swaccess: str
    hwaccess: str
    reset: int | None = None

    @property
    def width(self) -> int:
        return self.msb - self.lsb + 1

    @property
    def mask(self) -> int:
        return ((1 << self.width) - 1) << self.lsb

    @property
    def readable(self) -> bool:
        return self.swaccess in ('rc', 'ro', 'rw', 'rw0c', 'rw1c', 'rw1s')

    @property
    def writable(self) -> bool:
        return self.swaccess in ('r0w1c', 'rw', 'rw0c', 'rw1c', 'rw1s', 'wo')

    def encode(self, value: int) -> int:
        if not 0 <= value < (1 << self.width):
            raise ValueError(
                f"value {value} does not fit {self.width}-bit field {self.name}"
            )
        return (value << self.lsb) & self.mask

    def decode(self, register_value: int) -> int:
        return (register_value & self.mask) >> self.lsb


@dataclass(frozen=True)
class Register:
    domain: str
    name: str
    offset: int
    reset: int
    mask: int
    fields: tuple[Field, ...]

    @property
    def path(self) -> str:
        return f"{self.domain}.{self.name}"

    @property
    def readable(self) -> bool:
        return any(item.readable for item in self.fields)

    @property
    def writable(self) -> bool:
        return any(item.writable for item in self.fields)

    def field(self, name: str) -> Field:
        key = name.upper()
        for item in self.fields:
            if item.name == key:
                return item
        known = ", ".join(item.name for item in self.fields)
        raise KeyError(f"unknown field {self.path}.{name}; known: {known}")

    def __call__(self, **values: int) -> int:
        """Build a register value from its HJSON reset plus field overrides."""

        result = self.reset & 0xFFFF_FFFF
        for name, value in values.items():
            item = self.field(name)
            result = (result & ~item.mask) | item.encode(value)
        return result & 0xFFFF_FFFF

    def fields_mask(self, *names: str) -> int:
        """Return the bit mask covering the selected HJSON fields."""

        result = 0
        for name in names:
            result |= self.field(name).mask
        return result & 0xFFFF_FFFF

    def _value(self, value: int | None, fields: dict[str, int]) -> int:
        if value is not None and fields:
            raise ValueError(
                f"pass either a raw value or field values for {self.path}, not both"
            )
        return self(**fields) if value is None else value & 0xFFFF_FFFF

    def write(
        self,
        value: int | None = None,
        *,
        mask: int | None = None,
        **fields: int,
    ) -> str:
        """Format one ``config.regs`` write row from a raw value or fields."""

        if not self.writable:
            raise ValueError(f"register {self.path} is not software-writable")
        encoded = self._value(value, fields)
        row = f"{self.path} 0x{encoded:08x}"
        if mask is not None:
            row += f" 0x{mask & 0xFFFF_FFFF:08x}"
        return row

    def expect(
        self,
        value: int | None = None,
        *,
        mask: int | None = None,
        **fields: int,
    ) -> str:
        """Format one ``config.regs`` check row from a raw value or fields."""

        if not self.readable:
            raise ValueError(f"register {self.path} is not software-readable")
        encoded = self._value(value, fields)
        if fields and mask is None:
            mask = self.fields_mask(*fields)
        row = f"expect {self.path} 0x{encoded:08x}"
        if mask is not None:
            row += f" 0x{mask & 0xFFFF_FFFF:08x}"
        return row

    def vector_write(
        self,
        cycle: int,
        value: int | None = None,
        *,
        mask: int | None = None,
        **fields: int,
    ) -> str:
        """Format one cycle-indexed ``@write`` row from a raw value or fields."""

        if not self.writable:
            raise ValueError(f"register {self.path} is not software-writable")
        encoded = self._value(value, fields)
        row = f"{cycle} @write {self.path} 0x{encoded:08x}"
        if mask is not None:
            row += f" 0x{mask & 0xFFFF_FFFF:08x}"
        return row

    def vector_read(
        self,
        cycle: int,
        expected: int | None = None,
        *,
        mask: int | None = None,
        **fields: int,
    ) -> str:
        """Format one cycle-indexed ``@read`` row from a raw value or fields."""

        if not self.readable:
            raise ValueError(f"register {self.path} is not software-readable")
        encoded = self._value(expected, fields)
        if fields and mask is None:
            mask = self.fields_mask(*fields)
        row = f"{cycle} @read {self.path} 0x{encoded:08x}"
        if mask is not None:
            row += f" 0x{mask & 0xFFFF_FFFF:08x}"
        return row


@dataclass(frozen=True)
class RegisterDomain:
    name: str
    registers: tuple[Register, ...]

    def reg(self, name: str) -> Register:
        key = name.upper()
        for item in self.registers:
            if item.name == key:
                return item
        known = ", ".join(item.name for item in self.registers)
        raise KeyError(f"unknown register {self.name}.{name}; known: {known}")

    def has(self, name: str) -> bool:
        key = name.upper()
        return any(item.name == key for item in self.registers)

    def __getattr__(self, name: str) -> Register:
        try:
            return self.reg(name)
        except KeyError as exc:
            raise AttributeError(name) from exc

    @property
    def readable(self) -> tuple[Register, ...]:
        return tuple(item for item in self.registers if item.readable)

    @property
    def writable(self) -> tuple[Register, ...]:
        return tuple(item for item in self.registers if item.writable)

    def __iter__(self):
        return iter(self.registers)


DOMAINS: dict[str, RegisterDomain] = {
    'clk_i': RegisterDomain(
        name='clk_i',
        registers=(
            Register(
                domain='clk_i',
                name='CTRL',
                offset=0x00000000,
                reset=0x4b7f0000,
                mask=0xffff00f7,
                fields=(
                    Field(name='TX', lsb=0, msb=0, swaccess='rw', hwaccess='hro', reset=0),
                    Field(name='RX', lsb=1, msb=1, swaccess='rw', hwaccess='hro', reset=0),
                    Field(name='NF', lsb=2, msb=2, swaccess='rw', hwaccess='hro', reset=0),
                    Field(name='SLPBK', lsb=4, msb=4, swaccess='rw', hwaccess='hro', reset=0),
                    Field(name='LLPBK', lsb=5, msb=5, swaccess='rw', hwaccess='hro', reset=0),
                    Field(name='PARITY_EN', lsb=6, msb=6, swaccess='rw', hwaccess='hro', reset=0),
                    Field(name='PARITY_ODD', lsb=7, msb=7, swaccess='rw', hwaccess='hro', reset=0),
                    Field(name='NCO', lsb=16, msb=31, swaccess='rw', hwaccess='hro', reset=19327),
                ),
            ),
            Register(
                domain='clk_i',
                name='STATUS',
                offset=0x00000004,
                reset=0x0000003c,
                mask=0x0000003f,
                fields=(
                    Field(name='TXFULL', lsb=0, msb=0, swaccess='ro', hwaccess='hrw', reset=0),
                    Field(name='RXFULL', lsb=1, msb=1, swaccess='ro', hwaccess='hrw', reset=0),
                    Field(name='TXEMPTY', lsb=2, msb=2, swaccess='ro', hwaccess='hrw', reset=1),
                    Field(name='TXIDLE', lsb=3, msb=3, swaccess='ro', hwaccess='hrw', reset=1),
                    Field(name='RXIDLE', lsb=4, msb=4, swaccess='ro', hwaccess='hrw', reset=1),
                    Field(name='RXEMPTY', lsb=5, msb=5, swaccess='ro', hwaccess='hrw', reset=1),
                ),
            ),
            Register(
                domain='clk_i',
                name='RDATA',
                offset=0x00000008,
                reset=0x00000000,
                mask=0x000000ff,
                fields=(
                    Field(name='RDATA', lsb=0, msb=7, swaccess='ro', hwaccess='hrw', reset=None),
                ),
            ),
            Register(
                domain='clk_i',
                name='WDATA',
                offset=0x0000000c,
                reset=0x00000000,
                mask=0x000000ff,
                fields=(
                    Field(name='WDATA', lsb=0, msb=7, swaccess='wo', hwaccess='hro', reset=0),
                ),
            ),
            Register(
                domain='clk_i',
                name='FIFO_CTRL',
                offset=0x00000010,
                reset=0x00000000,
                mask=0x00000003,
                fields=(
                    Field(name='RXRST', lsb=0, msb=0, swaccess='wo', hwaccess='hro', reset=0),
                    Field(name='TXRST', lsb=1, msb=1, swaccess='wo', hwaccess='hro', reset=0),
                ),
            ),
            Register(
                domain='clk_i',
                name='FIFO_STATUS',
                offset=0x00000014,
                reset=0x00000000,
                mask=0x00ff00ff,
                fields=(
                    Field(name='TXLVL', lsb=0, msb=7, swaccess='ro', hwaccess='hwo', reset=None),
                    Field(name='RXLVL', lsb=16, msb=23, swaccess='ro', hwaccess='hwo', reset=None),
                ),
            ),
        ),
    ),
}
PRIMARY = DOMAINS[PRIMARY_DOMAIN]


def domain(name: str) -> RegisterDomain:
    """Return one generated register domain by its HJSON/clock name."""

    try:
        return DOMAINS[name]
    except KeyError as exc:
        known = ", ".join(DOMAINS)
        raise KeyError(f"unknown {TOP} register domain {name!r}; known: {known}") from exc


def write_config(path: str | Path, rows: Iterable[str]) -> None:
    """Write one ``config.regs`` file."""

    out = Path(path)
    out.parent.mkdir(parents=True, exist_ok=True)
    registers = [item for group in DOMAINS.values() for item in group]
    lines = [
        "# format: <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]",
        *(f"# map {item.path} 0x{item.offset:08x}" for item in registers),
        *(str(row) for row in rows),
    ]
    out.write_text("\n".join(lines) + "\n", encoding="utf-8")
