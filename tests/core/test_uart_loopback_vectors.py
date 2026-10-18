"""UART loopback checks must observe a settled value after each input edge."""

from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[2]
EDGES = ((0, 1), (8, 0), (16, 1), (24, 0), (32, 1))


@pytest.mark.parametrize("interface", ("tlul", "reg_iface", "axi_lite"))
@pytest.mark.parametrize("test", ("smoke", "line_loopback"))
def test_uart_loopback_vector_phases(interface: str, test: str) -> None:
    path = ROOT / "hw/ips/uart/1.0.0/interfaces" / interface / "dv/functional/tests" / test
    stimulus = [line.split() for line in (path / "data_in.vec").read_text().splitlines()]
    expected = [line.split() for line in (path / "data_out.vec").read_text().splitlines()]
    drives = [(int(row[0]), int(row[2], 0)) for row in stimulus if len(row) == 3 and row[1] == "rx_i"]
    samples = [(int(row[0]), int(row[2], 0)) for row in expected if len(row) == 3 and row[1] == "tx_o"]
    assert drives == list(EDGES)
    assert samples == [(cycle + 1, bit) for cycle, bit in EDGES]
    assert all(cycle < 40 for cycle, _ in samples)
