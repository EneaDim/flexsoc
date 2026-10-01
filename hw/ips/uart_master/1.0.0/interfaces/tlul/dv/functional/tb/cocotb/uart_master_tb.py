"""Generated cocotb functional test for uart_master."""

from __future__ import annotations

import os

import cocotb
from cocotb.triggers import Timer

from drivers.reg_driver import reset, set_defaults
from drivers.vec_driver import run_vectors


def _xorshift32(state):
    state &= 0xFFFFFFFF
    state ^= (state << 13) & 0xFFFFFFFF
    state ^= state >> 17
    state ^= (state << 5) & 0xFFFFFFFF
    return state & 0xFFFFFFFF


async def _flexsoc_clock(signal, period_ns, rise_ns, fall_ns, source_latency_ns, jitter_bound_ps, clock_salt):
    base_seed = int(os.environ.get("FLEXSOC_SEED", "1"), 0) & 0xFFFFFFFF
    jitter_state = (base_seed ^ int(clock_salt)) & 0xFFFFFFFF
    if jitter_state == 0:
        jitter_state = 0x6D2B79F5
    jitter_prev_ps = 0
    signal.value = 0
    initial_low = rise_ns + source_latency_ns
    if initial_low > 0:
        await Timer(initial_low, unit="ns")
    high_ns = fall_ns - rise_ns
    low_ps = int(round((period_ns - high_ns) * 1000.0))
    while True:
        signal.value = 1
        await Timer(high_ns, unit="ns")
        signal.value = 0
        if jitter_bound_ps:
            jitter_state = _xorshift32(jitter_state)
            jitter_next_ps = int(jitter_state % (2 * jitter_bound_ps + 1)) - jitter_bound_ps
        else:
            jitter_next_ps = 0
        low_delay_ps = low_ps + jitter_next_ps - jitter_prev_ps
        if low_delay_ps <= 0:
            raise AssertionError("invalid FlexSoC jittered clock delay")
        await Timer(low_delay_ps, unit="ps")
        jitter_prev_ps = jitter_next_ps


@cocotb.test()
async def vector_test(dut):
    cocotb.start_soon(_flexsoc_clock(getattr(dut, 'clk_i'), 10, 0.05, 5, 0.05, 25, 3713949822))
    set_defaults(dut)
    await reset(dut, "all")
    test_name = os.environ.get("TEST_NAME", "smoke")
    test_root = os.environ.get("TEST_ROOT", "tests")
    cfg = os.environ.get("CFG", f"{test_root}/{test_name}/config.regs")
    data_in = os.environ.get("DATA_IN", f"{test_root}/{test_name}/data_in.vec")
    data_out = os.environ.get("DATA_OUT", f"{test_root}/{test_name}/data_out.vec")
    await run_vectors(dut, cfg, data_in, data_out)
