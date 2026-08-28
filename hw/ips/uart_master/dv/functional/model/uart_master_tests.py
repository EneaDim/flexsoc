"""UART master test catalogue and vector generator.

The shared UART scenarios qualify the serial engine and CSR-visible behavior.
The host scenarios send real UART command frames and check the resulting SoC
host request interface. Protocol semantics live in ``uart_master_model.py``.
"""

from __future__ import annotations

import argparse
import random
from pathlib import Path

from uart_master_model import BIT_CYCLES, INPUTS, NCO, OUTPUTS, HostRequest, uart_frame
import uart_master_regmap as regmap


CSR = regmap.PRIMARY
SHARED_TESTS = (
    "smoke",
    "corners",
    "random_seed_1",
    "random_seed_2",
    "reconfig",
)
HOST_TESTS = (
    "host_read",
    "host_write",
    "host_alignment",
    "host_byte_enable",
)
TESTS = (*SHARED_TESTS, *HOST_TESTS)
TEST_ALIASES = {"random": "random_seed_1"}


def hx(value: int) -> str:
    return f"0x{value & 0xFFFF_FFFF:08x}"


def drive(cycle: int, signal: str, value: int) -> str:
    if signal not in INPUTS:
        raise KeyError(f"unknown functional input {signal!r}; known: {INPUTS}")
    return f"{cycle} {signal} {hx(value)}"


def check(cycle: int, signal: str, expected: int) -> str:
    if signal not in OUTPUTS:
        raise KeyError(f"unknown functional output {signal!r}; known: {OUTPUTS}")
    return f"{cycle} {signal} {hx(expected)}"


def ctrl_fields(test: str) -> dict[str, int]:
    ctrl = {"TX": 1, "RX": 1, "NCO": NCO}
    if test == "reconfig":
        ctrl["SLPBK"] = 1
    elif test.startswith("random_seed_"):
        ctrl.update(NF=1, LLPBK=1)
    elif test in HOST_TESTS:
        pass
    else:
        ctrl["LLPBK"] = 1
    return ctrl


def config(test: str) -> list[str]:
    return [
        CSR.CTRL.write(**ctrl_fields(test)),
        CSR.FIFO_CTRL.write(RXRST=1, TXRST=1),
    ]


def uart_rx_rows(start_cycle: int, byte: int) -> tuple[list[str], int]:
    frame = uart_frame(byte)
    rows = [
        drive(start_cycle + index * BIT_CYCLES, "cio_rx_i", bit)
        for index, bit in enumerate(frame)
    ]
    end_cycle = start_cycle + len(frame) * BIT_CYCLES
    rows.append(drive(end_cycle, "cio_rx_i", 1))
    return rows, end_cycle + BIT_CYCLES


def smoke_vectors() -> tuple[list[str], list[str]]:
    data_in: list[str] = []
    data_out: list[str] = []
    for cycle, value in ((0, 1), (8, 0), (16, 1), (24, 0), (32, 1)):
        data_in.append(drive(cycle, "cio_rx_i", value))
        data_out.append(check(cycle, "cio_tx_o", value))
        data_out.append(check(cycle, "cio_tx_en_o", 1))

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

    check_cycle = cycle + 32
    data_out.extend(
        [
            CSR.FIFO_STATUS.vector_read(check_cycle, TXLVL=0, RXLVL=len(bytes_rx)),
            *(CSR.RDATA.vector_read(check_cycle, RDATA=byte) for byte in bytes_rx),
            CSR.FIFO_STATUS.vector_read(check_cycle, TXLVL=0, RXLVL=0),
        ]
    )
    return data_in, data_out


def random_vectors(seed: int) -> tuple[list[str], list[str]]:
    data_in = [
        drive(0, "cio_rx_i", 1),
        CSR.CTRL.vector_write(4, TX=1, RX=1, NF=1, NCO=NCO),
    ]
    rng = random.Random(f"uart_master:random:rx:{seed}")
    good_bytes = [rng.getrandbits(8) for _ in range(4)]
    cycle = 32
    for byte in good_bytes:
        rows, cycle = uart_rx_rows(cycle, byte)
        data_in.extend(rows)

    check_cycle = cycle + 32
    data_out = [
        CSR.FIFO_STATUS.vector_read(check_cycle, TXLVL=0, RXLVL=len(good_bytes)),
        *(CSR.RDATA.vector_read(check_cycle, RDATA=byte) for byte in good_bytes),
        CSR.FIFO_STATUS.vector_read(check_cycle, TXLVL=0, RXLVL=0),
    ]
    return data_in, data_out


def reconfig_vectors() -> tuple[list[str], list[str]]:
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
        CSR.FIFO_STATUS.vector_read(400, TXLVL=0, RXLVL=1),
        CSR.RDATA.vector_read(400, RDATA=0x5A),
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
        CSR.FIFO_STATUS.vector_read(920, TXLVL=0, RXLVL=1),
        CSR.RDATA.vector_read(920, RDATA=0xC3),
    ]
    return data_in, data_out


def host_vectors(
    request: HostRequest,
    *,
    read_data: int = 0x89ABCDEF,
    error: bool = False,
) -> tuple[list[str], list[str]]:
    """Send one UART command and check the stable SoC-host request outputs."""

    data_in = [
        drive(0, "cio_rx_i", 1),
        drive(0, "gnt_i", 0),
        drive(0, "valid_i", 0),
        drive(0, "rdata_i", read_data),
        drive(0, "err_i", int(error)),
        CSR.CTRL.vector_write(4, TX=1, RX=1, NCO=NCO),
    ]

    cycle = 64
    for byte in request.encode():
        rows, cycle = uart_rx_rows(cycle, byte)
        data_in.extend(rows)

    # Hold the downstream bus stalled so the request interface can be checked
    # while it is valid. Once granted, the bridge deliberately clears req_o;
    # after a completed transaction RXF_IDLE also clears we_o.
    request_cycle = cycle + 64
    grant_cycle = request_cycle + 32
    response_cycle = grant_cycle + 32
    done_cycle = response_cycle + 64

    expected = request.bus_outputs()
    data_out = [
        check(request_cycle, "req_o", 1),
        *(check(request_cycle, name, value) for name, value in expected.items()),
        check(request_cycle, "cio_tx_en_o", 1),
        check(done_cycle, "req_o", 0),
        check(done_cycle, "cio_tx_en_o", 1),
    ]

    data_in.extend(
        [
            drive(grant_cycle, "gnt_i", 1),
            drive(response_cycle, "gnt_i", 0),
            drive(response_cycle, "valid_i", 1),
            drive(done_cycle, "valid_i", 0),
        ]
    )

    if request.write:
        data_out.append(check(done_cycle, "cio_tx_o", 1))
    return data_in, data_out


def normalize_test(test: str) -> str:
    return TEST_ALIASES.get(test, test)


def vectors(test: str) -> tuple[list[str], list[str]]:
    test = normalize_test(test)
    if test.startswith("random_seed_"):
        try:
            return random_vectors(int(test.removeprefix("random_seed_")))
        except ValueError as exc:
            raise ValueError(f"invalid UART master random test {test!r}") from exc

    scenarios = {
        "smoke": smoke_vectors,
        "corners": corners_vectors,
        "reconfig": reconfig_vectors,
        "host_read": lambda: host_vectors(
            HostRequest(address=0x1000_0040), read_data=0x89AB_CDEF
        ),
        "host_write": lambda: host_vectors(
            HostRequest(address=0x1000_0080, write=True, data=0x1234_5678)
        ),
        "host_alignment": lambda: host_vectors(
            HostRequest(address=0x1000_0043)
        ),
        "host_byte_enable": lambda: host_vectors(
            HostRequest(
                address=0x1000_0080,
                write=True,
                data=0xA5A5_5A5A,
                byte_enable=0x5,
            )
        ),
    }
    try:
        return scenarios[test]()
    except KeyError as exc:
        raise ValueError(f"unknown UART master test {test!r}; choose one of {TESTS}") from exc


def write_test(root: str | Path, test: str) -> None:
    test = normalize_test(test)
    if test not in TESTS:
        raise ValueError(f"unknown UART master test {test!r}; choose one of {TESTS}")

    folder = Path(root) / test
    folder.mkdir(parents=True, exist_ok=True)
    regmap.write_config(folder / "config.regs", config(test))
    in_rows, out_rows = vectors(test)
    (folder / "data_in.vec").write_text(
        "\n".join(
            [
                "# UART master stimulus: direct pins, host response and CSR writes.",
                "# <cycle> <signal> <value> or <cycle> @write <reg> <value> [mask]",
                *in_rows,
            ]
        )
        + "\n",
        encoding="utf-8",
    )
    (folder / "data_out.vec").write_text(
        "\n".join(
            [
                "# UART master checks: host request, serial outputs and CSR reads.",
                "# <cycle> <signal> <expected> or <cycle> @read <reg> <expected> [mask]",
                *out_rows,
            ]
        )
        + "\n",
        encoding="utf-8",
    )


def write_all_tests(
    root: str | Path,
    tests: list[str] | tuple[str, ...] | None = None,
) -> None:
    for test in tests or TESTS:
        write_test(root, test)


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Generate UART master FlexSoC vector tests."
    )
    parser.add_argument("--tests-dir", default="../tb/tests")
    parser.add_argument("--test", action="append", default=[])
    parser.add_argument("--list", action="store_true")
    args = parser.parse_args()
    if args.list:
        print("\n".join(TESTS))
        return 0
    write_all_tests(args.tests_dir, args.test or None)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
