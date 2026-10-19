from __future__ import annotations

from cocotb.triggers import ReadOnly

from .reg_driver import PRIMARY_CLOCK, _sample_cycle, rows

SIGNAL_CLOCKS = {'phy_rst_i': 'clk_i', 'phy_gtx_clk_i': 'clk_i', 'phy_gmii_rx_clk_i': 'clk_i', 'phy_gmii_rxd_i': 'clk_i', 'phy_gmii_rx_dv_i': 'clk_i', 'phy_gmii_rx_er_i': 'clk_i', 'phy_mii_tx_clk_i': 'clk_i', 'phy_mii_select_i': 'clk_i', 'phy_speed_i': 'clk_i', 'phy_speed_valid_i': 'clk_i', 'tx_data_i': 'clk_i', 'tx_valid_i': 'clk_i', 'tx_last_i': 'clk_i', 'tx_error_i': 'clk_i', 'tl_i': 'clk_i', 'phy_gmii_tx_clk_o': 'clk_i', 'phy_gmii_txd_o': 'clk_i', 'phy_gmii_tx_en_o': 'clk_i', 'phy_gmii_tx_er_o': 'clk_i', 'tx_clk_o': 'clk_i', 'tx_rst_o': 'clk_i', 'tx_ready_o': 'clk_i', 'rx_clk_o': 'clk_i', 'rx_rst_o': 'clk_i', 'rx_data_o': 'clk_i', 'rx_valid_o': 'clk_i', 'rx_last_o': 'clk_i', 'rx_error_o': 'clk_i', 'intr_tx_underflow_o': 'clk_i', 'intr_rx_bad_frame_o': 'clk_i', 'intr_rx_bad_fcs_o': 'clk_i', 'tl_o': 'clk_i'}
OUTPUT_VALID = ('rx_valid_o', 'clk_i')


def expected_outputs(path: str):
    """Group expected signals by logical vector step, preserving file order."""
    out = []
    current_step = None
    current = None
    for parts in rows(path):
        if len(parts) < 3:
            continue
        step, signal, raw = parts[:3]
        if step != current_step:
            current_step = step
            current = {}
            out.append(current)
        current[signal] = int(raw, 0)
    return out


async def check_outputs(dut, expected):
    """Consume expected output transactions without design-specific signal names."""
    for index, transaction in enumerate(expected):
        if OUTPUT_VALID is not None:
            valid, clock = OUTPUT_VALID
            for _ in range(4096):
                await _sample_cycle(getattr(dut, clock))
                if bool(getattr(dut, valid).value):
                    break
            else:
                raise AssertionError(f"timed out waiting for {valid}")
        else:
            await _sample_cycle(getattr(dut, PRIMARY_CLOCK))
        await ReadOnly()
        for signal, value in transaction.items():
            if not hasattr(dut, signal):
                raise AssertionError(f"unknown expected-output vector signal: {signal}")
            got = int(getattr(dut, signal).value) & 0xFFFFFFFF
            expected_value = int(value) & 0xFFFFFFFF
            if got != expected_value:
                raise AssertionError(
                    f"{signal}[{index}] got=0x{got:08x} exp=0x{expected_value:08x}"
                )
