#!/usr/bin/env python3
"""Generate model/regmap_<top>.py from an RTL reg package.

The generated helper is intentionally small and dependency-free.  It lets the
Python reference model and vector generator use symbolic CSR names instead of
hard-coded addresses.  Re-run this target after updating the HJSON/reggen RTL.
"""
from __future__ import annotations

import os
import re
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class Register:
    """One parsed CSR register."""

    name: str
    offset: int


def _env(name: str, default: str | None = None) -> str:
    value = os.environ.get(name, default)
    if value is None or value == "":
        raise SystemExit(f"missing required environment variable: {name}")
    return value


def _run_dir() -> Path:
    workspace = Path(_env("WORKSPACE", "workspace"))
    top = _env("TOP")
    run_id = _env("RUN_ID", "dev")
    return workspace / "runs" / top / run_id


def _find_reg_pkg(run_dir: Path, top: str) -> Path:
    candidates = [
        run_dir / "rtl" / f"{top}_reg_pkg.sv",
        run_dir / "rtl" / f"{top.lower()}_reg_pkg.sv",
    ]
    candidates.extend(sorted((run_dir / "rtl").glob("*_reg_pkg.sv")))
    for candidate in candidates:
        if candidate.exists():
            return candidate
    raise SystemExit(f"could not find *_reg_pkg.sv under {run_dir / 'rtl'}")


def _parse_registers(reg_pkg: Path) -> list[Register]:
    text = reg_pkg.read_text()
    pattern = re.compile(
        r"parameter\s+logic\s+\[[^\]]+\]\s+"
        r"(?P<const>[A-Za-z0-9_]+)_OFFSET\s*=\s*"
        r"(?P<bits>\d+)'h\s*(?P<hex>[0-9a-fA-F_]+)\s*;"
    )
    registers: list[Register] = []
    for match in pattern.finditer(text):
        const_name = match.group("const")
        value = int(match.group("hex").replace("_", ""), 16)
        # Constants are generated as <TOP>_<REGISTER>_OFFSET.
        parts = const_name.split("_")
        if len(parts) > 1:
            reg_name = "_".join(parts[1:])
        else:
            reg_name = const_name
        registers.append(Register(reg_name.upper(), value))

    if not registers:
        raise SystemExit(f"no register offsets found in {reg_pkg}")
    return registers


def _emit_python(top: str, source: Path, registers: list[Register]) -> str:
    entries = [
        f"    {reg.name!r}: Register(name={reg.name!r}, offset=0x{reg.offset:08x}),"
        for reg in registers
    ]
    constants = [
        f"{reg.name}_OFFSET = 0x{reg.offset:08x}"
        for reg in registers
    ]

    lines: list[str] = [
        '\"\"\"Python CSR map for ' + top + '.',
        '',
        'Auto-generated from:',
        '  ' + str(source),
        '',
        'Re-run:',
        '  fx regmap_py --force',
        '',
        'after updating the HJSON regmap and regenerating the RTL register package.',
        '\"\"\"',
        'from __future__ import annotations',
        '',
        'from dataclasses import dataclass',
        '',
        '',
        f'TOP = {top!r}',
        f'SOURCE = {str(source)!r}',
        '',
        '',
        '@dataclass(frozen=True)',
        'class Register:',
        '    \"\"\"One memory-mapped CSR.\"\"\"',
        '',
        '    name: str',
        '    offset: int',
        '',
        '',
        'REGISTERS: dict[str, Register] = {',
        *entries,
        '}',
        '',
        *constants,
        '',
        '',
        'def addr(name: str) -> int:',
        '    \"\"\"Return the byte offset of a CSR by symbolic name.\"\"\"',
        '',
        '    key = name.upper()',
        '    try:',
        '        return REGISTERS[key].offset',
        '    except KeyError as exc:',
        '        known = ", ".join(sorted(REGISTERS))',
        '        raise KeyError(f"unknown {TOP} register {name!r}; known: {known}") from exc',
        '',
        '',
        'def has(name: str) -> bool:',
        '    \"\"\"Return True when a CSR name exists.\"\"\"',
        '',
        '    return name.upper() in REGISTERS',
        '',
        '',
        'def names() -> tuple[str, ...]:',
        '    \"\"\"Return register names in generated order.\"\"\"',
        '',
        '    return tuple(REGISTERS)',
        '',
        '',
        'def config_write(name: str, data: int, *, clock: str = "clk_i") -> str:',
        '    \"\"\"Format one config.regs write row for generated SV tests.\"\"\"',
        '',
        '    return f"{clock}.{name.upper()} 0x{data & 0xFFFF_FFFF:08x}"',
        '',
    ]
    return "\n".join(lines)


def main() -> int:
    top = _env("TOP")
    run_dir = _run_dir()
    reg_pkg = _find_reg_pkg(run_dir, top)
    registers = _parse_registers(reg_pkg)

    out_dir = run_dir / "model"
    out_dir.mkdir(parents=True, exist_ok=True)
    out_path = out_dir / f"regmap_{top}.py"
    out_path.write_text(_emit_python(top, reg_pkg, registers))
    print(f"[regmap_py] source: {reg_pkg}")
    print(f"[regmap_py] wrote:   {out_path}")
    print("[regmap_py] registers: " + ", ".join(reg.name for reg in registers))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
