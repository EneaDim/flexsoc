from __future__ import annotations

from pathlib import Path

from cocotb.triggers import Combine, FallingEdge, RisingEdge, Timer
from cocotb.simtime import get_sim_time


CLOCKS = {'core': 'clk_i'}
CLOCK_PERIOD_PS = {'clk_i': 10000}
CLOCK_DRIVE_PS = {'clk_i': 2000}
CLOCK_SAMPLE_PS = {'clk_i': 8000}
_PHASE_ORIGINS = {}
RESET_DOMAINS = {'core': ('clk_i', 'rst_ni', 'low')}
PRIMARY_CLOCK = 'clk_i'
SETTLE_CLOCK = 'clk_i'

ADDR = {'core': {'CTRL': 0, 'STATUS': 4, 'RDATA': 8, 'WDATA': 12, 'FIFO_CTRL': 16, 'FIFO_STATUS': 20}}
WINDOWS = ('core',)
DEFAULT_DOMAIN = 'core'


WRITE_TOKENS = {"@write", "write", "@reg_write", "reg_write"}
READ_TOKENS = {"@read", "read", "@reg_read", "reg_read"}


def parse_u32(raw):
    return int(str(raw), 0) & 0xFFFFFFFF


def _clock_key(clk):
    return getattr(clk, "_name", None) or str(clk.value)


async def _wait_phase(clk, offsets):
    key = _clock_key(clk)
    if key not in CLOCK_PERIOD_PS:
        raise KeyError(f"unknown generated clock: {key}")
    period = CLOCK_PERIOD_PS[key]
    if key not in _PHASE_ORIGINS:
        await RisingEdge(clk)
        _PHASE_ORIGINS[key] = int(get_sim_time(unit="ps"))
    now = int(get_sim_time(unit="ps"))
    phase = (now - _PHASE_ORIGINS[key]) % period
    delta = (offsets[key] - phase) % period
    if delta == 0:
        delta = period
    await Timer(delta, unit="ps")


async def _sample_cycle(clk):
    await _wait_phase(clk, CLOCK_SAMPLE_PS)


async def _drive_cycle(clk):
    await _wait_phase(clk, CLOCK_DRIVE_PS)


async def _wait_cycles(clk, count=1):
    for _ in range(max(0, int(count))):
        await _sample_cycle(clk)


def rows(path: str):
    for raw in Path(path).read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if line and not line.startswith("#"):
            yield line.split()


def _set_domain_defaults(dut, domain: str):

    for name in ("valid", "write", "addr", "wdata", "wstrb"):
        getattr(dut, f"{domain}_reg_req_{name}").value = 0


def set_defaults(dut):
    for domain in WINDOWS:
        _set_domain_defaults(dut, domain)
    dut.rx_i.value = 1


def _selected_resets(selector: str):
    clean = str(selector or "all")
    if clean in {"all", "*"}:
        return tuple(RESET_DOMAINS.values())
    for domain, item in RESET_DOMAINS.items():
        if clean in {domain, item[1]}:
            return (item,)
    raise AssertionError(f"unknown reset selector: {clean}")


async def _wait_reset_cycles(dut, selected, cycles: int):
    for _ in range(max(1, int(cycles))):
        await Combine(*(RisingEdge(getattr(dut, clock)) for clock, _, _ in selected))


async def reset(dut, selector: str = "all", cycles: int = 5):
    selected = _selected_resets(selector)
    set_defaults(dut)
    for _, signal, polarity in selected:
        getattr(dut, signal).value = int(polarity == "high")
    await _wait_reset_cycles(dut, selected, cycles)
    await Combine(*(FallingEdge(getattr(dut, clock)) for clock, _, _ in selected))
    for _, signal, polarity in selected:
        getattr(dut, signal).value = int(polarity == "low")
    set_defaults(dut)
    await _wait_cycles(getattr(dut, PRIMARY_CLOCK), 8)


async def _wait_high(dut, signal: str, clk, limit: int = 256):
    for _ in range(limit):
        await _sample_cycle(clk)
        if bool(getattr(dut, signal).value):
            return
    raise TimeoutError(f"timeout waiting for {signal}")


async def _bus_write(dut, domain: str, clk, addr: int, data: int):

    await _drive_cycle(clk)
    _set_domain_defaults(dut, domain)
    for name, value in (("valid", 1), ("write", 1), ("addr", addr), ("wdata", data), ("wstrb", 0xF)):
        getattr(dut, f"{domain}_reg_req_{name}").value = value
    await _wait_high(dut, f"{domain}_reg_rsp_ready", clk)
    if int(getattr(dut, f"{domain}_reg_rsp_error").value):
        raise AssertionError(f"reg_iface write error on {domain} addr=0x{addr:08x}")
    await _drive_cycle(clk)
    _set_domain_defaults(dut, domain)


async def _bus_read(dut, domain: str, clk, addr: int) -> int:

    await _drive_cycle(clk)
    _set_domain_defaults(dut, domain)
    for name, value in (("valid", 1), ("write", 0), ("addr", addr), ("wdata", 0), ("wstrb", 0)):
        getattr(dut, f"{domain}_reg_req_{name}").value = value
    await _wait_high(dut, f"{domain}_reg_rsp_ready", clk)
    data = int(getattr(dut, f"{domain}_reg_rsp_rdata").value) & 0xFFFFFFFF
    if int(getattr(dut, f"{domain}_reg_rsp_error").value):
        raise AssertionError(f"reg_iface read error on {domain} addr=0x{addr:08x}")
    await _drive_cycle(clk)
    _set_domain_defaults(dut, domain)
    return data


def _decode_reg(name: str) -> tuple[str, int]:
    clean = str(name)
    if DEFAULT_DOMAIN is not None:
        domain, reg = DEFAULT_DOMAIN, clean.rsplit(".", 1)[-1]
    else:
        if "." not in clean:
            raise KeyError(f"register name must include its domain: {name!r}")
        domain, reg = clean.split(".", 1)
    try:
        return domain, ADDR[domain][reg.upper()]
    except KeyError as exc:
        raise KeyError(f"unknown register {name!r}; update drivers/reg_driver.py") from exc


async def apply_reg(dut, name: str, value: int, mask: int = 0xFFFFFFFF):
    domain, addr = _decode_reg(name)
    clk = getattr(dut, CLOCKS[domain])
    if mask != 0xFFFFFFFF:
        current = await _bus_read(dut, domain, clk, addr)
        value = (current & ~mask) | (value & mask)
    await _bus_write(dut, domain, clk, addr, value)


async def read_reg(dut, name: str) -> int:
    domain, addr = _decode_reg(name)
    return await _bus_read(dut, domain, getattr(dut, CLOCKS[domain]), addr)


async def expect_reg(dut, name: str, expected: int, mask: int = 0xFFFFFFFF):
    got = await read_reg(dut, name)
    if (got & mask) != (expected & mask):
        raise AssertionError(
            f"{name} got=0x{got & mask:08x} exp=0x{expected & mask:08x} mask=0x{mask:08x}"
        )


async def settle(dut, cycles: int = 8):
    await _wait_cycles(getattr(dut, SETTLE_CLOCK), cycles)


async def apply_config(dut, path: str):
    for parts in rows(path):
        if len(parts) >= 2:
            mask = int(parts[2], 0) if len(parts) >= 3 else 0xFFFFFFFF
            await apply_reg(dut, parts[0], int(parts[1], 0), mask)
    await settle(dut)
