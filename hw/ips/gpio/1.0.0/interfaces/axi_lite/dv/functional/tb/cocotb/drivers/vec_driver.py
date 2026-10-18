from __future__ import annotations

import os
import re
from pathlib import Path

import cocotb
from cocotb.triggers import Combine, FallingEdge, RisingEdge

from drivers.reg_driver import (
    PRIMARY_CLOCK, WRITE_TOKENS, _drive_cycle, _sample_cycle,
    apply_config, apply_reg, parse_u32, reset,
)
from drivers.vec_monitor import CycleMonitor

CONFIG_TOKENS = {"@cfg", "cfg", "@config", "config"}
RESET_TOKENS = {"@reset", "reset"}
WAIT_TOKENS = {"@wait", "wait"}
WAIT_EVENT_TOKENS = {"@wait_event", "wait_event"}
WAIT_SIGNAL_TOKENS = {"@wait_signal", "wait_signal"}
SIGNAL_CLOCKS = {'cio_gpio_i': 'clk_i', 'axi_lite_i': 'clk_i', 'cio_gpio_o': 'clk_i', 'cio_gpio_en_o': 'clk_i', 'intr_gpio_o': 'clk_i', 'axi_lite_o': 'clk_i'}
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
        if len(parts) < 2:
            raise ValueError(f"{path}:{lineno}: expected cycle and command/pairs")
        cycle = parse_u32(parts[0])
        command = parts[1]

        if command in WAIT_TOKENS:
            rows.append((cycle, [("@wait",)]))
            continue
        if command in WAIT_EVENT_TOKENS:
            if len(parts) not in (4, 5):
                raise ValueError(
                    f"{path}:{lineno}: @wait_event format is: "
                    "cycle @wait_event label value [timeout]"
                )
            timeout = parse_u32(parts[4]) if len(parts) == 5 else 1024
            rows.append((cycle, [("@wait_event", parts[2], parse_u32(parts[3]), timeout)]))
            continue
        if command in WAIT_SIGNAL_TOKENS:
            if len(parts) not in (4, 5):
                raise ValueError(
                    f"{path}:{lineno}: @wait_signal format is: "
                    "cycle @wait_signal signal value [timeout]"
                )
            timeout = parse_u32(parts[4]) if len(parts) == 5 else 1024
            rows.append((cycle, [("@wait_signal", parts[2], parse_u32(parts[3]), timeout)]))
            continue
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
                    f"{path}:{lineno}: @reset format is: cycle @reset [domain|reset] cycles"
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
    ordered = sorted(enumerate(rows), key=lambda item: (item[1][0], item[0]))
    grouped = []
    for _, (cycle, pairs) in ordered:
        if grouped and grouped[-1][0] == cycle:
            grouped[-1][1].extend(pairs)
        else:
            grouped.append([cycle, list(pairs)])
    special_tokens = (
        CONFIG_TOKENS | WRITE_TOKENS | RESET_TOKENS | WAIT_TOKENS
        | WAIT_EVENT_TOKENS | WAIT_SIGNAL_TOKENS
    )
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
    for name in ("rx_i", "cio_rx_i", "uart_rx_i", "serial_rx_i"):
        if hasattr(dut, name):
            getattr(dut, name).value = 1
    for _, _, reset_name, polarity in selected:
        if not hasattr(dut, reset_name):
            raise AssertionError(f"reset signal not found on DUT: {reset_name}")
        getattr(dut, reset_name).value = int(polarity == "high")
    for _ in range(max(1, int(cycles))):
        await Combine(*(RisingEdge(getattr(dut, clock)) for _, clock, _, _ in selected))
    await Combine(*(FallingEdge(getattr(dut, clock)) for _, clock, _, _ in selected))
    for _, _, reset_name, polarity in selected:
        getattr(dut, reset_name).value = int(polarity == "low")


async def _wait_event(dut, label, expected, timeout, cursor):
    clk = getattr(dut, PRIMARY_CLOCK)
    for _ in range(max(1, int(timeout))):
        await RisingEdge(clk)
        sequence = int(dut.flexsoc_event_sequence.value)
        if sequence != cursor:
            cursor = sequence
            if int(dut.flexsoc_event_value.value) & 0xFFFFFFFF == int(expected) & 0xFFFFFFFF:
                dut._log.info("[TB][EVENT] observed name=%s value=0x%08x", label, expected)
                return cursor
    raise AssertionError(f"event timeout name={label} value=0x{int(expected) & 0xffffffff:08x}")


async def _wait_signal(dut, name, expected, timeout):
    if not hasattr(dut, name):
        raise AssertionError(f"unknown wait signal: {name}")
    clock = SIGNAL_CLOCKS.get(name, PRIMARY_CLOCK)
    clk = getattr(dut, clock)
    handle = getattr(dut, name)
    mask = (1 << len(handle)) - 1
    expected = int(expected) & mask
    for _ in range(max(1, int(timeout))):
        await RisingEdge(clk)
        if int(handle.value) & mask == expected:
            return
    raise AssertionError(f"signal timeout name={name} value=0x{expected:x}")


async def _drive_one(dut, name, value):
    if not hasattr(dut, name):
        raise AssertionError(f"unknown input vector signal: {name}")
    signal = getattr(dut, name)
    width = len(signal)
    value = int(value) & ((1 << width) - 1)
    signal.value = value
    dut._log.info("drive %s <= 0x%x", name, value)


async def drive_vectors(
    dut,
    clk,
    rows,
    config_runner=None,
    register_writer=None,
    reset_runner=None,
):
    now = -1
    applied = 0
    event_cursor = 0

    for cycle, pairs in _coalesce_rows(rows):
        if not pairs:
            continue
        while now < cycle - 1:
            await _advance(clk)
            now += 1
        await _drive_cycle(clk)
        dut._log.info("vector cycle=%d", cycle)
        item = pairs[0]
        name = item[0]

        if name in WAIT_TOKENS:
            await _sample_cycle(clk)
            now = cycle
            applied += 1
            continue
        if name in WAIT_EVENT_TOKENS:
            event_cursor = await _wait_event(dut, item[1], item[2], item[3], event_cursor)
            now = -1
            applied += 1
            continue
        if name in WAIT_SIGNAL_TOKENS:
            await _wait_signal(dut, item[1], item[2], item[3])
            now = -1
            applied += 1
            continue
        if name in RESET_TOKENS:
            _, selector, cycles = item
            cycles = max(1, int(cycles))
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
            await _drive_one(dut, name, item[1])
            applied += 1
        await _sample_cycle(clk)
        now = cycle

    if applied == 0:
        raise AssertionError("no vector inputs, commands, or register writes were applied")


async def run_vectors(dut, cfg, data_in, data_out):
    async def do_write(reg, data, mask):
        await apply_reg(dut, reg, data, mask)

    async def do_reset(selector, cycles):
        await reset(dut, selector, cycles)

    await apply_config(dut, cfg)
    monitor = CycleMonitor(dut, data_out)
    checker = cocotb.start_soon(monitor.run())
    await drive_vectors(
        dut,
        getattr(dut, PRIMARY_CLOCK),
        load_vectors(data_in),
        register_writer=do_write,
        reset_runner=do_reset,
    )
    await checker
