from __future__ import annotations

from pathlib import Path

from cocotb.triggers import RisingEdge, Timer

WRITE_TOKENS = {"@write", "write", "@reg_write", "reg_write"}
READ_TOKENS = {"@read", "read", "@reg_read", "reg_read"}

REGISTER_ADDRS = {'WDATA': 12, 'FIFO_CTRL': 16}


def parse_u32(text):
    """Parse one vector/config integer token.

    Keep this intentionally aligned with the SystemVerilog parser:
      - 0x/0b/0o prefixes select the base explicitly;
      - all-decimal digits are decimal, even with leading zeroes;
      - bare hex is accepted only when A-F/a-f is present.

    This avoids silently parsing vector cycles such as 40 as hex while still
    allowing values like ffffcdbc in legacy generated files.
    """

    raw = str(text).strip().replace("_", "")
    if not raw:
        return 0

    low = raw.lower()
    if low.startswith(("0x", "0b", "0o")):
        return int(raw, 0) & 0xFFFFFFFF

    if any(ch in "abcdefABCDEF" for ch in raw):
        return int(raw, 16) & 0xFFFFFFFF

    return int(raw, 10) & 0xFFFFFFFF


def load_register_map(*paths):
    """Load register aliases from generated metadata and optional comments."""

    regmap = dict(REGISTER_ADDRS)

    for item in paths:
        if item is None:
            continue

        path = Path(item)
        if not path.exists():
            continue

        for raw in path.read_text(encoding="utf-8").splitlines():
            line = raw.strip()
            if not line.startswith("#"):
                continue

            parts = line[1:].strip().split()
            if len(parts) < 3 or parts[0] != "map":
                continue

            value = parse_u32(parts[2])
            key = parts[1]
            regmap[key] = value
            regmap[key.upper()] = value
            regmap[key.split(".")[-1].upper()] = value

    return regmap


def resolve_register(reg_or_addr, regmap=None):
    token = str(reg_or_addr).strip()
    regmap = regmap or {}

    try:
        return parse_u32(token)
    except ValueError:
        pass

    for key in (token, token.upper(), token.split(".")[-1].upper()):
        if key in regmap:
            return int(regmap[key]) & 0xFFFFFFFF

    raise KeyError(f"unknown register/address token: {token}")


def _get(dut, name):
    if not hasattr(dut, name):
        raise AttributeError(f"generated cocotb wrapper does not expose {name}")
    return getattr(dut, name)


def has_tlul_proxy(dut):
    required = [
        "tl_i_a_valid",
        "tl_i_a_opcode",
        "tl_i_a_param",
        "tl_i_a_size",
        "tl_i_a_source",
        "tl_i_a_address",
        "tl_i_a_mask",
        "tl_i_a_data",
        "tl_i_d_ready",
        "tl_o_a_ready",
        "tl_o_d_valid",
        "tl_o_d_error",
        "tl_o_d_data",
    ]
    return all(hasattr(dut, name) for name in required)


def _clock(dut, clk=None):
    if clk is not None:
        return clk
    if hasattr(dut, "clk_i"):
        return dut.clk_i
    raise AttributeError("cannot infer cocotb clock; expected clk_i")


async def _cycle(clk):
    await RisingEdge(clk)
    await Timer(1, units="ps")


def _drive_idle(dut):
    _get(dut, "tl_i_a_valid").value = 0
    _get(dut, "tl_i_a_opcode").value = 4
    _get(dut, "tl_i_a_param").value = 0
    _get(dut, "tl_i_a_size").value = 2
    _get(dut, "tl_i_a_source").value = 0
    _get(dut, "tl_i_a_address").value = 0
    _get(dut, "tl_i_a_mask").value = 0
    _get(dut, "tl_i_a_data").value = 0
    _get(dut, "tl_i_d_ready").value = 1


async def init_register_bus(dut, clk=None):
    if not has_tlul_proxy(dut):
        return

    clk = _clock(dut, clk)
    _drive_idle(dut)
    await _cycle(clk)


async def write_register(dut, reg_or_addr, data, mask=0xFFFFFFFF, *, regmap=None, clk=None):
    if not has_tlul_proxy(dut):
        raise RuntimeError("register write requested, but this cocotb wrapper has no TL-UL proxy signals")

    clk = _clock(dut, clk)
    addr = resolve_register(reg_or_addr, regmap)
    data = parse_u32(data)
    mask = parse_u32(mask) & 0xF

    dut._log.info("reg write addr=0x%08x data=0x%08x mask=0x%x", addr, data, mask)

    _drive_idle(dut)
    await _cycle(clk)

    _get(dut, "tl_i_d_ready").value = 1
    _get(dut, "tl_i_a_valid").value = 1
    _get(dut, "tl_i_a_opcode").value = 0  # PutFullData
    _get(dut, "tl_i_a_param").value = 0
    _get(dut, "tl_i_a_size").value = 2
    _get(dut, "tl_i_a_source").value = 0
    _get(dut, "tl_i_a_address").value = addr
    _get(dut, "tl_i_a_mask").value = mask
    _get(dut, "tl_i_a_data").value = data

    guard = 0
    while int(_get(dut, "tl_o_a_ready").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on write addr=0x{addr:08x}")

    await _cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while int(_get(dut, "tl_o_d_valid").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on write addr=0x{addr:08x}")

    if int(_get(dut, "tl_o_d_error").value):
        raise AssertionError(f"TL-UL write error at addr=0x{addr:08x}")

    _drive_idle(dut)
    await _cycle(clk)


async def read_register(dut, reg_or_addr, *, regmap=None, clk=None):
    if not has_tlul_proxy(dut):
        raise RuntimeError("register read requested, but this cocotb wrapper has no TL-UL proxy signals")

    clk = _clock(dut, clk)
    addr = resolve_register(reg_or_addr, regmap)

    dut._log.info("reg read addr=0x%08x", addr)

    _drive_idle(dut)
    await _cycle(clk)

    _get(dut, "tl_i_d_ready").value = 1
    _get(dut, "tl_i_a_valid").value = 1
    _get(dut, "tl_i_a_opcode").value = 4  # Get
    _get(dut, "tl_i_a_param").value = 0
    _get(dut, "tl_i_a_size").value = 2
    _get(dut, "tl_i_a_source").value = 0
    _get(dut, "tl_i_a_address").value = addr
    _get(dut, "tl_i_a_mask").value = 0xF
    _get(dut, "tl_i_a_data").value = 0

    guard = 0
    while int(_get(dut, "tl_o_a_ready").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting a_ready on read addr=0x{addr:08x}")

    await _cycle(clk)
    _get(dut, "tl_i_a_valid").value = 0

    guard = 0
    while int(_get(dut, "tl_o_d_valid").value) == 0:
        await _cycle(clk)
        guard += 1
        if guard > 1000:
            raise TimeoutError(f"timeout waiting d_valid on read addr=0x{addr:08x}")

    if int(_get(dut, "tl_o_d_error").value):
        raise AssertionError(f"TL-UL read error at addr=0x{addr:08x}")

    data = int(_get(dut, "tl_o_d_data").value) & 0xFFFFFFFF
    dut._log.info("reg read addr=0x%08x data=0x%08x", addr, data)

    _drive_idle(dut)
    await _cycle(clk)

    return data


async def run_register_config(dut, cfg_path, *, regmap=None, clk=None):
    path = Path(cfg_path)
    if not path.exists():
        dut._log.info("register config not found: %s", path)
        return

    merged_map = dict(regmap or {})
    merged_map.update(load_register_map(path))

    writes = 0

    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.split("#", 1)[0].strip()
        if not line:
            continue

        parts = line.split()
        if parts and parts[0] in WRITE_TOKENS:
            parts = parts[1:]

        if len(parts) < 2:
            dut._log.warning("malformed config row: %s", raw_line)
            continue

        reg = parts[0]
        data = parts[1]
        mask = parts[2] if len(parts) >= 3 else "0xffffffff"
        wait_cycles = int(parts[3], 0) if len(parts) >= 4 else 1

        await write_register(dut, reg, data, mask, regmap=merged_map, clk=clk)
        writes += 1

        for _ in range(max(0, wait_cycles)):
            await _cycle(_clock(dut, clk))

    if writes == 0:
        dut._log.info("no register config writes from %s; continuing", path)
