from __future__ import annotations

import re
from pathlib import Path

from cocotb.triggers import FallingEdge, RisingEdge, Timer

from drivers.reg_driver import WRITE_TOKENS, parse_u32

CONFIG_TOKENS = {"@cfg", "cfg", "@config", "config"}
_SIGNAL_RE = re.compile(r"^[@A-Za-z_][A-Za-z0-9_./:-]*$")


def _looks_like_signal(token):
    return bool(_SIGNAL_RE.match(str(token)))


def load_vectors(path=None):
    rows = []

    if path is None:
        return rows

    path = Path(path)
    if not path.exists():
        return rows

    for lineno, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        line = raw_line.split("#", 1)[0].strip()
        if not line:
            continue

        parts = line.split()
        if len(parts) < 3:
            raise ValueError(f"{path}:{lineno}: expected cycle and command/pairs")

        cycle = parse_u32(parts[0])
        command = parts[1]

        if command in CONFIG_TOKENS:
            if len(parts) != 3:
                raise ValueError(f"{path}:{lineno}: @cfg format is: cycle @cfg path")
            rows.append((cycle, [("@cfg", parts[2])]))
            continue

        if command in WRITE_TOKENS:
            if len(parts) not in (4, 5):
                raise ValueError(f"{path}:{lineno}: @write format is: cycle @write reg data [mask]")
            mask = parts[4] if len(parts) == 5 else "0xffffffff"
            rows.append((cycle, [("@write", parts[2], parse_u32(parts[3]), parse_u32(mask))]))
            continue

        if (len(parts) - 1) % 2 != 0:
            raise ValueError(f"{path}:{lineno}: expected cycle followed by signal/value pairs")

        pairs = []
        for idx in range(1, len(parts), 2):
            name = parts[idx]
            if not _looks_like_signal(name):
                raise ValueError(f"{path}:{lineno}: invalid signal name: {name}")
            pairs.append((name, parse_u32(parts[idx + 1])))

        rows.append((cycle, pairs))

    return rows


async def _advance(clk, count=1):
    for _ in range(max(0, int(count))):
        await RisingEdge(clk)


async def _drive_one(dut, name, value):
    if not hasattr(dut, name):
        raise AssertionError(f"unknown input vector signal: {name}")

    getattr(dut, name).value = value
    dut._log.info("drive %s <= 0x%08x", name, int(value) & 0xFFFFFFFF)
    return True


async def drive_vectors(
    dut,
    clk,
    rows,
    monitor=None,
    config_runner=None,
    register_writer=None,
):
    now = -1
    applied = 0

    for cycle, pairs in sorted(rows, key=lambda item: item[0]):
        if not pairs:
            continue

        while now < cycle - 1:
            await _advance(clk)
            now += 1
            if monitor is not None:
                await monitor.check(now)

        await FallingEdge(clk)
        await Timer(1, units="ps")

        dut._log.info("vector cycle=%d", cycle)

        for item in pairs:
            name = item[0]

            if name in CONFIG_TOKENS:
                if config_runner is None:
                    raise AssertionError("@cfg row requested but no config_runner was provided")
                await config_runner(item[1])
                applied += 1
                continue

            if name in WRITE_TOKENS:
                if register_writer is None:
                    raise AssertionError("@write row requested but no register_writer was provided")
                _, reg, data, mask = item
                await register_writer(reg, data, mask)
                applied += 1
                continue

            if await _drive_one(dut, name, item[1]):
                applied += 1

        await RisingEdge(clk)
        await Timer(1, units="ps")
        now = cycle

        if monitor is not None:
            await monitor.check(now)

    for _ in range(8):
        await _advance(clk)
        now += 1
        if monitor is not None:
            await monitor.check(now)

    if applied == 0:
        raise AssertionError("no vector inputs or register writes were applied")
