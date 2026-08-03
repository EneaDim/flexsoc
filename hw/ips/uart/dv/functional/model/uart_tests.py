"""UART test catalogue and vector generator.

UART exercises both FlexSoC verification transports: direct ``cio_*`` pins and
software-visible CSRs. Test scenarios live here; serial framing/timing comes
from ``uart_model.py`` and CSR layout/serialization from ``uart_regmap.py``.
"""

from __future__ import annotations

import argparse
import random
from pathlib import Path

from uart_model import BIT_CYCLES, INPUTS, NCO, OUTPUTS, uart_frame
import uart_regmap as regmap


CSR = regmap.PRIMARY
SHARED_TESTS = (
    "smoke",
    "corners",
    "random_seed_1",
    "random_seed_2",
    "reconfig",
)
CUSTOM_TESTS = (
    "line_loopback",
    "rx_fifo",
    "noise_filter",
    "parity_reconfig",
)
TESTS = (*SHARED_TESTS, *CUSTOM_TESTS)
TEST_ALIASES = {"random": "random_seed_1"}

def hx(value: int) -> str:
    """Format one vector value as a 32-bit hexadecimal word."""

    return f"0x{value & 0xFFFF_FFFF:08x}"


def drive(cycle: int, signal: str, value: int) -> str:
    """Format one direct UART-input drive row."""

    if signal not in INPUTS:
        raise KeyError(f"unknown functional input {signal!r}; known: {INPUTS}")
    return f"{cycle} {signal} {hx(value)}"


def check(cycle: int, signal: str, expected: int) -> str:
    """Format one direct UART-output check row."""

    if signal not in OUTPUTS:
        raise KeyError(f"unknown functional output {signal!r}; known: {OUTPUTS}")
    return f"{cycle} {signal} {hx(expected)}"


def ctrl_fields(test: str) -> dict[str, int]:
    """Return the CTRL fields used by one UART scenario."""

    ctrl = {"TX": 1, "RX": 1, "NCO": NCO}
    if test in {"reconfig", "parity_reconfig"}:
        ctrl["SLPBK"] = 1
    elif test.startswith("random_seed_") or test == "noise_filter":
        ctrl.update(NF=1, LLPBK=1)
    else:
        ctrl["LLPBK"] = 1
    return ctrl


def config(test: str) -> list[str]:
    """Return safe initial CSR writes for one UART scenario.

    Generated testbenches hold asynchronous serial RX inputs idle-high before
    reset. Tests that exercise the external RX path may still enable line
    loopback so the transmitter follows the physical pin directly.
    """

    return [
        CSR.CTRL.write(**ctrl_fields(test)),
        CSR.FIFO_CTRL.write(RXRST=1, TXRST=1),
    ]


def uart_rx_rows(
    start_cycle: int,
    byte: int,
    *,
    parity: bool = False,
    odd: bool = False,
    bad_parity: bool = False,
) -> tuple[list[str], int]:
    """Return pin-drive rows for one UART frame and the next free cycle."""

    frame = uart_frame(byte, parity=parity, odd=odd, bad_parity=bad_parity)
    rows = [
        drive(start_cycle + index * BIT_CYCLES, "cio_rx_i", bit)
        for index, bit in enumerate(frame)
    ]
    end_cycle = start_cycle + len(frame) * BIT_CYCLES
    rows.append(drive(end_cycle, "cio_rx_i", 1))
    return rows, end_cycle + BIT_CYCLES


def smoke_vectors() -> tuple[list[str], list[str]]:
    """Check line loopback, output-enable, CTRL, STATUS, and FIFO state."""

    data_in: list[str] = []
    data_out: list[str] = []
    for cycle, value in ((0, 1), (8, 0), (16, 1), (24, 0), (32, 1)):
        data_in.append(drive(cycle, "cio_rx_i", value))
        data_out.append(check(cycle, "cio_tx_o", value))
        data_out.append(check(cycle, "cio_tx_en_o", 1))

    # The 8-cycle line-loopback pulses above are intentionally shorter than
    # one UART bit cell. Reset the receiver state and restore configuration
    # before inspecting live RX/FIFO status in unit-delay or SDF simulations.
    data_in.extend(
        [
            "40 @reset 4",
            CSR.CTRL.vector_write(48, **ctrl_fields("smoke")),
            CSR.FIFO_CTRL.vector_write(52, RXRST=1, TXRST=1),
        ]
    )

    cycle = 80
    data_out.extend(
        [
            CSR.CTRL.vector_read(
                cycle,
                TX=1,
                RX=1,
                NF=0,
                SLPBK=0,
                LLPBK=1,
                PARITY_EN=0,
                PARITY_ODD=0,
                NCO=NCO,
            ),
            CSR.STATUS.vector_read(
                cycle,
                TXFULL=0,
                RXFULL=0,
                TXEMPTY=1,
                TXIDLE=1,
                RXIDLE=1,
                RXEMPTY=1,
            ),
            CSR.FIFO_STATUS.vector_read(cycle, TXLVL=0, RXLVL=0),
        ]
    )
    return data_in, data_out


def corners_vectors() -> tuple[list[str], list[str]]:
    """Receive corner-case bytes from the physical RX pin and read them back."""

    data_in = [
        drive(0, "cio_rx_i", 1),
        CSR.CTRL.vector_write(4, TX=1, RX=1, NCO=NCO),
    ]
    data_out: list[str] = []

    bytes_rx = [0x00, 0xFF, 0x55, 0xAA]
    cycle = 32
    for byte in bytes_rx:
        rows, cycle = uart_rx_rows(cycle, byte)
        data_in.extend(rows)

    for sample_cycle in (16, 512, 1024):
        data_out.append(check(sample_cycle, "cio_tx_o", 1))
        data_out.append(check(sample_cycle, "cio_tx_en_o", 1))

    check_cycle = cycle + 32
    data_out.extend(
        [
            CSR.CTRL.vector_read(
                check_cycle,
                TX=1,
                RX=1,
                NF=0,
                SLPBK=0,
                LLPBK=0,
                PARITY_EN=0,
                PARITY_ODD=0,
                NCO=NCO,
            ),
            CSR.STATUS.vector_read(
                check_cycle,
                TXFULL=0,
                RXFULL=0,
                TXEMPTY=1,
                TXIDLE=1,
                RXIDLE=1,
                RXEMPTY=0,
            ),
            CSR.FIFO_STATUS.vector_read(
                check_cycle, TXLVL=0, RXLVL=len(bytes_rx)
            ),
            *(CSR.RDATA.vector_read(check_cycle, RDATA=byte) for byte in bytes_rx),
            CSR.STATUS.vector_read(
                check_cycle,
                TXFULL=0,
                RXFULL=0,
                TXEMPTY=1,
                TXIDLE=1,
                RXIDLE=1,
                RXEMPTY=1,
            ),
            CSR.FIFO_STATUS.vector_read(check_cycle, TXLVL=0, RXLVL=0),
        ]
    )
    return data_in, data_out


def random_vectors(seed: int) -> tuple[list[str], list[str]]:
    """Receive deterministic pseudo-random bytes with the RTL noise filter on."""

    data_in = [
        drive(0, "cio_rx_i", 1),
        CSR.CTRL.vector_write(4, TX=1, RX=1, NF=1, NCO=NCO),
    ]

    rng_key = "uart:random:rx" if seed == 1 else f"uart:random:rx:{seed}"
    rng = random.Random(rng_key)
    good_bytes = [rng.getrandbits(8) for _ in range(4)]
    cycle = 32
    for byte in good_bytes:
        rows, cycle = uart_rx_rows(cycle, byte)
        data_in.extend(rows)

    check_cycle = cycle + 32
    data_out = [
        check(16, "cio_tx_o", 1),
        check(16, "cio_tx_en_o", 1),
        CSR.CTRL.vector_read(
            check_cycle,
            TX=1,
            RX=1,
            NF=1,
            SLPBK=0,
            LLPBK=0,
            PARITY_EN=0,
            PARITY_ODD=0,
            NCO=NCO,
        ),
        CSR.FIFO_STATUS.vector_read(
            check_cycle, TXLVL=0, RXLVL=len(good_bytes)
        ),
        *(CSR.RDATA.vector_read(check_cycle, RDATA=byte) for byte in good_bytes),
        CSR.STATUS.vector_read(
            check_cycle,
            TXFULL=0,
            RXFULL=0,
            TXEMPTY=1,
            TXIDLE=1,
            RXIDLE=1,
            RXEMPTY=1,
        ),
        CSR.FIFO_STATUS.vector_read(check_cycle, TXLVL=0, RXLVL=0),
    ]
    return data_in, data_out


def reconfig_vectors() -> tuple[list[str], list[str]]:
    """Transmit through system loopback, then reconfigure parity and repeat."""

    data_in = [
        drive(0, "cio_rx_i", 1),
        CSR.WDATA.vector_write(8, WDATA=0x5A),
        CSR.CTRL.vector_write(
            480,
            TX=1,
            RX=1,
            SLPBK=1,
            PARITY_EN=1,
            PARITY_ODD=1,
            NCO=NCO,
        ),
        CSR.WDATA.vector_write(496, WDATA=0xC3),
    ]
    data_out = [
        check(16, "cio_tx_o", 1),
        check(16, "cio_tx_en_o", 1),
        CSR.FIFO_STATUS.vector_read(400, TXLVL=0, RXLVL=1),
        CSR.RDATA.vector_read(400, RDATA=0x5A),
        CSR.FIFO_STATUS.vector_read(400, TXLVL=0, RXLVL=0),
        CSR.CTRL.vector_read(
            488,
            TX=1,
            RX=1,
            NF=0,
            SLPBK=1,
            LLPBK=0,
            PARITY_EN=1,
            PARITY_ODD=1,
            NCO=NCO,
        ),
        check(520, "cio_tx_o", 1),
        check(520, "cio_tx_en_o", 1),
        CSR.FIFO_STATUS.vector_read(920, TXLVL=0, RXLVL=1),
        CSR.RDATA.vector_read(920, RDATA=0xC3),
        CSR.STATUS.vector_read(
            920,
            TXFULL=0,
            RXFULL=0,
            TXEMPTY=1,
            TXIDLE=1,
            RXIDLE=1,
            RXEMPTY=1,
        ),
        CSR.FIFO_STATUS.vector_read(920, TXLVL=0, RXLVL=0),
    ]
    return data_in, data_out


def normalize_test(test: str) -> str:
    """Map legacy names to the canonical shared catalogue."""

    return TEST_ALIASES.get(test, test)


def vectors(test: str) -> tuple[list[str], list[str]]:
    """Return data_in/data_out rows for one named UART scenario."""

    test = normalize_test(test)
    if test.startswith("random_seed_"):
        try:
            return random_vectors(int(test.removeprefix("random_seed_")))
        except ValueError as exc:
            raise ValueError(f"invalid UART random test {test!r}") from exc

    scenarios = {
        "smoke": smoke_vectors,
        "corners": corners_vectors,
        "reconfig": reconfig_vectors,
        "line_loopback": smoke_vectors,
        "rx_fifo": corners_vectors,
        "noise_filter": lambda: random_vectors(0xA5),
        "parity_reconfig": reconfig_vectors,
    }
    try:
        return scenarios[test]()
    except KeyError as exc:
        raise ValueError(f"unknown UART test {test!r}; choose one of {TESTS}") from exc


def write_test(root: str | Path, test: str) -> None:
    """Write one complete UART vector-test directory."""

    test = normalize_test(test)
    if test not in TESTS:
        raise ValueError(f"unknown UART test {test!r}; choose one of {TESTS}")

    folder = Path(root) / test
    folder.mkdir(parents=True, exist_ok=True)
    regmap.write_config(folder / "config.regs", config(test))
    in_rows, out_rows = vectors(test)

    data_in = [
        "# UART stimulus: direct pins and CSR writes.",
        "# <cycle> <signal> <value> or <cycle> @write <reg> <value> [mask]",
        *in_rows,
    ]
    data_out = [
        "# UART checks: direct pins and CSR reads.",
        "# <cycle> <signal> <expected> or <cycle> @read <reg> <expected> [mask]",
        *out_rows,
    ]
    (folder / "data_in.vec").write_text("\n".join(data_in) + "\n", encoding="utf-8")
    (folder / "data_out.vec").write_text("\n".join(data_out) + "\n", encoding="utf-8")


def write_all_tests(
    root: str | Path,
    tests: list[str] | tuple[str, ...] | None = None,
) -> None:
    """Generate all UART tests, or the explicitly requested subset."""

    for test in tests or TESTS:
        write_test(root, test)


def main() -> int:
    """CLI used by ``fx tests_gen`` / ``fx test_gen``."""

    parser = argparse.ArgumentParser(
        description="Generate UART FlexSoC vector tests from the behavioral model."
    )
    parser.add_argument("--tests-dir", default="../tb/tests")
    parser.add_argument(
        "--test",
        action="append",
        default=[],
        help="Generate only this TEST_NAME. May be repeated.",
    )
    parser.add_argument(
        "--list",
        action="store_true",
        help="Print the UART TESTS catalogue and exit.",
    )
    args = parser.parse_args()
    if args.list:
        for test in TESTS:
            print(test)
        return 0
    write_all_tests(args.tests_dir, args.test or None)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
