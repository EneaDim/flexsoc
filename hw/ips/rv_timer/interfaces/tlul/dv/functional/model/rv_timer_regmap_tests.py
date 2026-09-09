"""Generated FlexSoC coverage stimulus for rv_timer.

This file is machine-owned. It reads the current generated regmap at
runtime, so HJSON/regmap changes are reflected by the next ``tests_gen``.
"""
from __future__ import annotations

import argparse
from pathlib import Path

import rv_timer_model as model
import rv_timer_regmap as regmap


TOP = 'rv_timer'
TEST = "auto_toggle"
SAFE_CONTROLS = False


def _toggle_mask(register: regmap.Register) -> int:
    """Return software-owned bits safe for repeated toggle writes."""

    if SAFE_CONTROLS and register.name == "CTRL":
        return 0
    mask = 0
    for field in register.fields:
        if field.swaccess == "rw" and field.hwaccess == "hro":
            mask |= field.mask
    return mask & 0xFFFF_FFFF


def _write_mask(register: regmap.Register) -> int:
    """Return TL-UL byte enables covering the declared register width."""

    byte_count = max(1, min(4, (register.mask.bit_length() + 7) // 8))
    return (1 << byte_count) - 1


def _safe_config_rows() -> list[str]:
    """Return the non-disruptive control baseline required by N-clock traffic.

    The verification harness already resets the DUT before loading
    ``config.regs``. Runtime reset commands would clear these controls
    again, so the N-clock auto-toggle test establishes ENABLE here and
    then leaves reset/clock-gating controls untouched.
    """

    if not SAFE_CONTROLS:
        return []

    rows: list[str] = []
    for domain in regmap.DOMAINS.values():
        for register in domain.writable:
            if register.name != "CTRL":
                continue
            field_names = {field.name for field in register.fields}
            values: dict[str, int] = {}
            if "ENABLE" in field_names:
                values["ENABLE"] = 1
            if "SOFT_RESET" in field_names:
                values["SOFT_RESET"] = 0
            if "CLK_GATE_EN" in field_names:
                values["CLK_GATE_EN"] = 0
            if values:
                rows.append(register.write(**values))
    return rows


def stimulus() -> list[str]:
    rows: list[str] = []
    cycle = 0

    for domain in regmap.DOMAINS.values():
        for register in domain.writable:
            mask = _toggle_mask(register)
            if not mask:
                continue
            base = register.reset & 0xFFFF_FFFF
            write_mask = _write_mask(register)
            for value in (base ^ mask, base, base ^ mask, base):
                rows.append(register.vector_write(cycle, value, mask=write_mask))
                cycle += 4

    for value in (0xFFFF_FFFF, 0x0000_0000, 0xFFFF_FFFF, 0x0000_0000):
        for name in model.INPUTS:
            rows.append(f"{cycle} {name} 0x{value:08x}")
        if model.INPUTS:
            cycle += 4

    if not SAFE_CONTROLS:
        rows.append(f"{cycle} @reset 2")
    return rows


def write_test(root: str | Path) -> None:
    folder = Path(root) / TEST
    folder.mkdir(parents=True, exist_ok=True)
    regmap.write_config(folder / "config.regs", _safe_config_rows())
    (folder / "data_in.vec").write_text(
        "# Generated CSR/input toggle stimulus.\n"
        + "\n".join(stimulus())
        + "\n",
        encoding="utf-8",
    )
    (folder / "data_out.vec").write_text(
        "# Coverage stimulus intentionally has no functional checks.\n",
        encoding="utf-8",
    )


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate FlexSoC automatic coverage vectors.")
    parser.add_argument("--tests-dir", default="../tests")
    parser.add_argument("--test", action="append", default=[])
    args = parser.parse_args()
    unknown = [name for name in args.test if name != TEST]
    if unknown:
        raise SystemExit(f"unknown automatic test(s): {', '.join(unknown)}")
    write_test(args.tests_dir)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
