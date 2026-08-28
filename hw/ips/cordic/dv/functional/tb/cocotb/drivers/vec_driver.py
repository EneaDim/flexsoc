from __future__ import annotations

import os
import re
from pathlib import Path

from cocotb.triggers import Combine, FallingEdge, RisingEdge

from drivers.reg_driver import WRITE_TOKENS, _drive_cycle, _sample_cycle, parse_u32

CONFIG_TOKENS = {"@cfg", "cfg", "@config", "config"}
RESET_TOKENS = {"@reset", "reset"}
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

        if command in RESET_TOKENS:
            if len(parts) == 3:
                selector, cycles = "all", parts[2]
            elif len(parts) == 4:
                selector, cycles = parts[2], parts[3]
            else:
                raise ValueError(
                    f"{path}:{lineno}: @reset format is: "
                    "cycle @reset [domain|reset] cycles"
                )
            rows.append((cycle, [("@reset", selector, parse_u32(cycles))]))
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


def _coalesce_rows(rows):
    # Return deterministic atomic vector batches grouped by logical cycle.
    # Multiple signal rows with the same cycle are one transaction and are
    # driven together. Commands consume simulator time and therefore cannot be
    # mixed with signal drives or another command on the same logical cycle.

    ordered = sorted(enumerate(rows), key=lambda item: (item[1][0], item[0]))
    grouped = []
    for _, (cycle, pairs) in ordered:
        if grouped and grouped[-1][0] == cycle:
            grouped[-1][1].extend(pairs)
        else:
            grouped.append([cycle, list(pairs)])

    special_tokens = CONFIG_TOKENS | WRITE_TOKENS | RESET_TOKENS
    result = []
    for cycle, pairs in grouped:
        special = [item for item in pairs if item and item[0] in special_tokens]
        if special and (len(special) != 1 or len(pairs) != 1):
            raise ValueError(
                f"cycle {cycle}: commands cannot share a cycle with another command or signal drive"
            )
        result.append((cycle, pairs))
    return result


async def _advance(clk, count=1):
    for _ in range(max(0, int(count))):
        await _sample_cycle(clk)


def _configured_reset_domains():
    raw = os.environ.get("CLOCK_DOMAINS", "").strip()
    domains = []
    for item in raw.replace(";", ",").split(","):
        parts = [part.strip() for part in item.split(":") if part.strip()]
        if len(parts) in {4, 5}:
            domain, clock, reset = parts[:3]
            polarity = parts[4].lower() if len(parts) == 5 else "low"
            domains.append((domain, clock, reset, polarity))
    return tuple(domains or (("core", "clk_i", "rst_ni", "low"),))


def _selected_reset_domains(selector):
    clean = str(selector or "all")
    domains = _configured_reset_domains()
    if clean in {"all", "*"}:
        return domains
    selected = tuple(item for item in domains if clean in {item[0], item[2]})
    if not selected:
        raise AssertionError(f"unknown reset selector: {clean}")
    return selected


async def _default_reset_runner(dut, selector, cycles):
    selected = _selected_reset_domains(selector)
    for name in ("cio_rx_i", "uart_rx_i", "serial_rx_i"):
        if hasattr(dut, name):
            getattr(dut, name).value = 1
    for _, _, reset, polarity in selected:
        if not hasattr(dut, reset):
            raise AssertionError(f"reset signal not found on DUT: {reset}")
        getattr(dut, reset).value = int(polarity == "high")
    for _ in range(max(1, int(cycles))):
        await Combine(*(RisingEdge(getattr(dut, clock)) for _, clock, _, _ in selected))
    await Combine(*(FallingEdge(getattr(dut, clock)) for _, clock, _, _ in selected))
    for _, _, reset, polarity in selected:
        getattr(dut, reset).value = int(polarity == "low")


async def _drive_one(dut, name, value):
    if not hasattr(dut, name):
        raise AssertionError(f"unknown input vector signal: {name}")

    signal = getattr(dut, name)
    width = len(signal)
    value = int(value) & ((1 << width) - 1)
    signal.value = value
    dut._log.info("drive %s <= 0x%x", name, value)
    return True


async def drive_vectors(
    dut,
    clk,
    rows,
    monitor=None,
    config_runner=None,
    register_writer=None,
    reset_runner=None,
):
    now = -1
    applied = 0

    for cycle, pairs in _coalesce_rows(rows):
        if not pairs:
            continue

        while now < cycle - 1:
            await _advance(clk)
            now += 1
            if monitor is not None:
                await monitor.check(now)

        await _drive_cycle(clk)

        dut._log.info("vector cycle=%d", cycle)

        if pairs[0][0] in RESET_TOKENS:
            _, selector, cycles = pairs[0]
            cycles = max(1, int(cycles))
            dut._log.info(
                "[TB][RESET] cycle=%d selector=%s cycles=%d",
                cycle, selector, cycles,
            )
            if reset_runner is None:
                await _default_reset_runner(dut, selector, cycles)
            else:
                await reset_runner(selector, cycles)
            applied += 1
            now = cycle + cycles - 1
            continue

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

        await _sample_cycle(clk)
        now = cycle

        if monitor is not None:
            await monitor.check(now)

    final_cycle = now + 8
    if monitor is not None:
        final_cycle = max(final_cycle, monitor.last_cycle)
    guarded_deadline = now + 4096

    while now < final_cycle or (monitor is not None and monitor.has_pending_guarded()):
        if (
            monitor is not None
            and monitor.has_pending_guarded()
            and now >= guarded_deadline
        ):
            raise AssertionError("timed out waiting for valid-guarded output checks")
        await _advance(clk)
        now += 1
        if monitor is not None:
            await monitor.check(now)

    if applied == 0:
        raise AssertionError("no vector inputs or register writes were applied")
