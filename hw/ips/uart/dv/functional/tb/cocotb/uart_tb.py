from __future__ import annotations

import os
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

from drivers.reg_driver import (
    init_register_bus,
    load_register_map,
    read_register,
    run_register_config,
    write_register,
)
from drivers.vec_driver import drive_vectors, load_vectors
from drivers.vec_monitor import LatencyMonitor


async def reset_dut(dut):
    cocotb.start_soon(Clock(dut.clk_i, 10, units="ns").start())

    if hasattr(dut, "rst_ni"):
        dut.rst_ni.value = 0
    await Timer(25, units="ns")
    await RisingEdge(dut.clk_i)
    if hasattr(dut, "rst_ni"):
        dut.rst_ni.value = 1
    await RisingEdge(dut.clk_i)
    await Timer(1, units="ns")


@cocotb.test()
async def uart_generated_test(dut):
    await reset_dut(dut)
    await init_register_bus(dut, dut.clk_i)

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

    await apply_config(cfg_path)

    await drive_vectors(
        dut,
        dut.clk_i,
        load_vectors(data_in),
        LatencyMonitor(dut, data_out, register_reader=do_read),
        config_runner=apply_config,
        register_writer=do_write,
    )
