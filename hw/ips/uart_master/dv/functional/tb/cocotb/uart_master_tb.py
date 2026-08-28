from __future__ import annotations

import os
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Combine, FallingEdge, RisingEdge, Timer

from drivers.reg_driver import (
    init_register_bus,
    load_register_map,
    read_register,
    run_register_config,
    write_register,
)
from drivers.vec_driver import drive_vectors, load_vectors
from drivers.vec_monitor import LatencyMonitor


RESET_DOMAINS = {'core': ('clk_i', 'rst_ni', 'low')}


def _selected_resets(selector):
    clean = str(selector or "all")
    if clean in {"all", "*"}:
        return tuple(RESET_DOMAINS.values())
    for domain, item in RESET_DOMAINS.items():
        if clean in {domain, item[1]}:
            return (item,)
    raise AssertionError(f"unknown reset selector: {clean}")


async def apply_reset(dut, selector="all", cycles=5):
    selected = _selected_resets(selector)
    for name in ("cio_rx_i", "uart_rx_i", "serial_rx_i"):
        if hasattr(dut, name):
            getattr(dut, name).value = 1
    for _, reset, polarity in selected:
        getattr(dut, reset).value = int(polarity == "high")
    for _ in range(max(1, int(cycles))):
        await Combine(*(RisingEdge(getattr(dut, clock)) for clock, _, _ in selected))
    await Combine(*(FallingEdge(getattr(dut, clock)) for clock, _, _ in selected))
    for _, reset, polarity in selected:
        getattr(dut, reset).value = int(polarity == "low")
    await Timer(1, unit="ns")


@cocotb.test()
async def uart_master_generated_test(dut):
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())
    for _, reset, polarity in RESET_DOMAINS.values():
        getattr(dut, reset).value = int(polarity == "low")
    await init_register_bus(dut, dut.clk_i)
    reset_cycles = max(1, int(os.environ.get("INITIAL_RESET_CYCLES", "5")))
    dut._log.info("initial reset cycles=%d", reset_cycles)
    await apply_reset(dut, "all", reset_cycles)
    for _ in range(2):
        await RisingEdge(dut.clk_i)

    test_name = os.environ.get("TEST_NAME", "smoke")
    test_root = Path(os.environ.get("TEST_ROOT", "tests"))
    test_dir = test_root / test_name

    cfg_path = Path(os.environ.get("REG_CONFIG", test_dir / "config.regs"))
    data_in = Path(os.environ.get("DATA_IN", test_dir / "data_in.vec"))
    data_out = Path(os.environ.get("DATA_OUT", test_dir / "data_out.vec"))

    dut._log.info("TEST_NAME=%s", test_name)
    dut._log.info("REG_CONFIG=%s", cfg_path)
    dut._log.info("DATA_IN=%s", data_in)
    dut._log.info("DATA_OUT=%s", data_out)

    regmap = load_register_map(cfg_path, data_in, data_out)

    async def apply_config(path):
        await run_register_config(dut, path, regmap=regmap, clk=dut.clk_i)

    async def do_write(reg, data, mask):
        await write_register(dut, reg, data, mask, regmap=regmap, clk=dut.clk_i)

    async def do_read(reg):
        return await read_register(dut, reg, regmap=regmap, clk=dut.clk_i)

    async def do_reset(selector, cycles):
        await apply_reset(dut, selector, cycles)

    await apply_config(cfg_path)

    await drive_vectors(
        dut,
        dut.clk_i,
        load_vectors(data_in),
        LatencyMonitor(dut, data_out, register_reader=do_read),
        config_runner=apply_config,
        register_writer=do_write,
        reset_runner=do_reset,
    )
