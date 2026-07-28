#!/usr/bin/env python3
"""Generate the Python model-side register map from HJSON.

This module owns all HJSON/reggen-derived model metadata. ``fx setup_model``
calls :func:`generate` directly while ``fx regmap_py`` uses this module as its
standalone entry point. The generated ``<top>_regmap.py`` contains only reusable
CSR structure and serialization helpers; behavioral code belongs in
``<top>_model.py`` and test scenarios belong in ``<top>_tests.py``.
"""
from __future__ import annotations

import argparse
import sys
from dataclasses import dataclass
from pathlib import Path
from textwrap import dedent
from typing import Any

READABLE_SWACCESS = frozenset({"ro", "rc", "rw", "rw1s", "rw1c", "rw0c"})
WRITABLE_SWACCESS = frozenset({"rw", "wo", "r0w1c", "rw1s", "rw1c", "rw0c"})


@dataclass(frozen=True)
class FieldSpec:
    """Normalized field metadata consumed by the Python emitter."""

    name: str
    lsb: int
    msb: int
    swaccess: str
    hwaccess: str
    reset: int | None

    @property
    def mask(self) -> int:
        return ((1 << (self.msb - self.lsb + 1)) - 1) << self.lsb

    @property
    def readable(self) -> bool:
        return self.swaccess in READABLE_SWACCESS

    @property
    def writable(self) -> bool:
        return self.swaccess in WRITABLE_SWACCESS


@dataclass(frozen=True)
class RegisterSpec:
    """Normalized register metadata consumed by the Python emitter."""

    domain: str
    name: str
    offset: int
    reset: int
    reset_mask: int
    fields: tuple[FieldSpec, ...]

    @property
    def path(self) -> str:
        return f"{self.domain}.{self.name}"

    @property
    def readable(self) -> bool:
        return any(field.readable for field in self.fields)

    @property
    def writable(self) -> bool:
        return any(field.writable for field in self.fields)


def _reggen_ip_block() -> Any:
    """Return the bundled reggen ``IpBlock`` class."""

    util_dir = Path(__file__).resolve().parents[2] / "util"
    if util_dir.is_dir() and str(util_dir) not in sys.path:
        sys.path.insert(0, str(util_dir))
    try:
        from reggen.ip_block import IpBlock  # type: ignore
    except ModuleNotFoundError as exc:
        missing = exc.name or "reggen dependency"
        raise SystemExit(
            f"cannot load bundled reggen ({missing!r} missing); run `uv sync` first"
        ) from exc
    return IpBlock


def _source_files(top: str, data_dir: Path, multi: bool) -> list[tuple[str, Path]]:
    """Return ``(domain, HJSON)`` inputs in deterministic order."""

    if multi:
        files = [
            (path.stem[len(top) + 1 :] or "clk_i", path)
            for path in sorted(data_dir.glob(f"{top}_*.hjson"))
        ]
        if not files:
            raise SystemExit(f"no {top}_*.hjson files found under {data_dir}")
        return files

    path = data_dir / f"{top}.hjson"
    if not path.exists():
        raise SystemExit(f"could not find HJSON regmap: {path}")
    return [("clk_i", path)]


def _field_spec(field: Any) -> FieldSpec:
    reset = field.resval if isinstance(field.resval, int) else None
    return FieldSpec(
        name=str(field.name).upper(),
        lsb=int(field.bits.lsb),
        msb=int(field.bits.msb),
        swaccess=str(field.swaccess.key).lower(),
        hwaccess=str(field.hwaccess.key).lower(),
        reset=reset,
    )


def _collect(top: str, data_dir: Path, multi: bool) -> tuple[list[Path], list[RegisterSpec]]:
    """Load HJSON through reggen and return flattened software-visible CSRs."""

    IpBlock = _reggen_ip_block()
    sources: list[Path] = []
    registers: list[RegisterSpec] = []
    seen_paths: set[str] = set()

    for fallback_domain, source in _source_files(top, data_dir, multi):
        try:
            block = IpBlock.from_path(str(source), [])
        except (RuntimeError, ValueError) as exc:
            raise SystemExit(f"invalid HJSON regmap {source}: {exc}") from exc

        sources.append(source)
        primary_clock = getattr(getattr(block.clocking, "primary", None), "clock", None)
        domain = fallback_domain if multi else str(primary_clock or fallback_domain)

        for reg_block in block.reg_blocks.values():
            for register in reg_block.flat_regs:
                spec = RegisterSpec(
                    domain=domain,
                    name=str(register.name).upper(),
                    offset=int(register.offset),
                    reset=int(register.resval),
                    reset_mask=int(register.resmask),
                    fields=tuple(_field_spec(field) for field in register.fields),
                )
                if spec.path in seen_paths:
                    raise SystemExit(
                        f"duplicate model register path {spec.path!r} while reading {source}"
                    )
                seen_paths.add(spec.path)
                registers.append(spec)

    if not registers:
        joined = ", ".join(str(path) for path in sources)
        raise SystemExit(f"no registers found in HJSON source(s): {joined}")
    return sources, registers


def _field_expr(field: FieldSpec) -> str:
    return (
        "Field("
        f"name={field.name!r}, lsb={field.lsb}, msb={field.msb}, "
        f"swaccess={field.swaccess!r}, hwaccess={field.hwaccess!r}, "
        f"reset={field.reset!r})"
    )


def _domain_literal(registers: list[RegisterSpec]) -> str:
    by_domain: dict[str, list[RegisterSpec]] = {}
    for register in registers:
        by_domain.setdefault(register.domain, []).append(register)

    rows: list[str] = []
    for domain, domain_registers in by_domain.items():
        rows.extend(
            [
                f"    {domain!r}: RegisterDomain(",
                f"        name={domain!r},",
                "        registers=(",
            ]
        )
        for register in domain_registers:
            rows.extend(
                [
                    "            Register(",
                    f"                domain={register.domain!r},",
                    f"                name={register.name!r},",
                    f"                offset=0x{register.offset:08x},",
                    f"                reset=0x{register.reset:08x},",
                    f"                mask=0x{register.reset_mask:08x},",
                    "                fields=(",
                    *(
                        f"                    {_field_expr(field)},"
                        for field in register.fields
                    ),
                    "                ),",
                    "            ),",
                ]
            )
        rows.extend(["        ),", "    ),"])
    return "\n".join(rows)


def _emit_python(top: str, sources: list[Path], registers: list[RegisterSpec]) -> str:
    """Render the dependency-free ``<top>_regmap.py`` helper."""

    primary_domain = registers[0].domain
    template = dedent(
        '''\
        """Generated model-side CSR map for __TOP__.

        HJSON source(s): __SOURCE_NAMES__.
        Regenerate with ``fx regmap_py --force``. Behavioral code belongs in
        ``__TOP___model.py`` and test scenarios belong in ``__TOP___tests.py``.
        """
        from __future__ import annotations

        from dataclasses import dataclass
        from pathlib import Path
        from typing import Iterable

        TOP = __TOP_REPR__
        PRIMARY_DOMAIN = __PRIMARY_DOMAIN_REPR__


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
                return self.swaccess in __READABLE_REPR__

            @property
            def writable(self) -> bool:
                return self.swaccess in __WRITABLE_REPR__

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
        __DOMAIN_LITERAL__
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
            out.write_text("\\n".join(lines) + "\\n", encoding="utf-8")
        '''
    )

    replacements = {
        "__TOP__": top,
        "__TOP_REPR__": repr(top),
        "__SOURCE_NAMES__": ", ".join(path.name for path in sources),
        "__PRIMARY_DOMAIN_REPR__": repr(primary_domain),
        "__READABLE_REPR__": repr(tuple(sorted(READABLE_SWACCESS))),
        "__WRITABLE_REPR__": repr(tuple(sorted(WRITABLE_SWACCESS))),
        "__DOMAIN_LITERAL__": _domain_literal(registers),
    }
    for marker, value in replacements.items():
        template = template.replace(marker, value)
    return template


def generate(
    top: str,
    data_dir: Path,
    model_dir: Path,
    *,
    multi: bool = False,
    force: bool = False,
) -> Path:
    """Generate only ``<top>_regmap.py`` from HJSON."""

    model_dir.mkdir(parents=True, exist_ok=True)
    out_path = model_dir / f"{top}_regmap.py"
    if out_path.exists() and not force:
        return out_path

    sources, registers = _collect(top, data_dir, multi)
    out_path.write_text(_emit_python(top, sources, registers), encoding="utf-8")
    print(f"[regmap_py] source: {', '.join(str(path) for path in sources)}")
    print(f"[regmap_py] wrote:   {out_path}")
    print("[regmap_py] registers: " + ", ".join(register.path for register in registers))
    return out_path


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate model/<top>_regmap.py from HJSON.")
    parser.add_argument("--top", required=True)
    parser.add_argument("--data-dir", required=True)
    parser.add_argument("--model-dir", required=True)
    parser.add_argument("--multi", action="store_true")
    parser.add_argument("--force", action="store_true")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    generate(
        args.top,
        Path(args.data_dir),
        Path(args.model_dir),
        multi=args.multi,
        force=args.force,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
