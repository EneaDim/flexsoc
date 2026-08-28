"""Functional test catalogue for the 4-bit FlexSoC GPIO IP."""

from __future__ import annotations

import argparse
import random
from pathlib import Path

import gpio_model as model
import gpio_regmap as regmap

CSR = regmap.PRIMARY

SHARED_TESTS = (
    "smoke",
    "corners",
    "random_seed_1",
    "random_seed_2",
    "reconfig",
)
DESIGN_TESTS = (
    "interrupt_levels",
    "input_filter",
)
TESTS = (*SHARED_TESTS, *DESIGN_TESTS)


def hx(value: int) -> str:
    return f"0x{int(value) & 0xFFFF_FFFF:08x}"


def drive(cycle: int, signal: str, value: int) -> str:
    if signal not in model.INPUTS:
        raise KeyError(f"unknown GPIO input {signal!r}")
    return f"{cycle} {signal} {hx(value)}"


def check(cycle: int, signal: str, value: int) -> str:
    if signal not in model.OUTPUTS:
        raise KeyError(f"unknown GPIO output {signal!r}")
    return f"{cycle} {signal} {hx(value)}"


def config(_test: str) -> list[str]:
    return []


def smoke_vectors() -> tuple[list[str], list[str]]:
    return (
        [
            drive(0, "cio_gpio_i", 0x0),
            CSR.DIRECT.vector_write(8, GPIO_O=0x5, GPIO_OE=0xF),
        ],
        [
            check(20, "cio_gpio_o", 0x5),
            check(20, "cio_gpio_en_o", 0xF),
            CSR.DIRECT.vector_read(20, GPIO_O=0x5, GPIO_OE=0xF),
            CSR.DATA_IN.vector_read(20, GPIO_IN=0x0),
            check(20, "intr_gpio_o", 0x0),
        ],
    )


def corners_vectors() -> tuple[list[str], list[str]]:
    return (
        [
            drive(0, "cio_gpio_i", 0x0),
            CSR.DIRECT.vector_write(8, GPIO_O=0x0, GPIO_OE=0x0),
            drive(24, "cio_gpio_i", 0xF),
            CSR.DIRECT.vector_write(40, GPIO_O=0xF, GPIO_OE=0xF),
        ],
        [
            CSR.DATA_IN.vector_read(16, GPIO_IN=0x0),
            check(20, "cio_gpio_o", 0x0),
            check(20, "cio_gpio_en_o", 0x0),
            CSR.DATA_IN.vector_read(36, GPIO_IN=0xF),
            check(52, "cio_gpio_o", 0xF),
            check(52, "cio_gpio_en_o", 0xF),
        ],
    )


def random_vectors(seed: int) -> tuple[list[str], list[str]]:
    rng = random.Random(f"gpio:random:{seed}")
    gpio_in = rng.randrange(16)
    gpio_o = rng.randrange(16)
    gpio_oe = rng.randrange(16)
    return (
        [
            drive(0, "cio_gpio_i", gpio_in),
            CSR.DIRECT.vector_write(8, GPIO_O=gpio_o, GPIO_OE=gpio_oe),
        ],
        [
            CSR.DATA_IN.vector_read(20, GPIO_IN=gpio_in),
            check(20, "cio_gpio_o", gpio_o),
            check(20, "cio_gpio_en_o", gpio_oe),
            CSR.DIRECT.vector_read(20, GPIO_O=gpio_o, GPIO_OE=gpio_oe),
        ],
    )


def reconfig_vectors() -> tuple[list[str], list[str]]:
    return (
        [
            drive(0, "cio_gpio_i", 0x3),
            CSR.DIRECT.vector_write(8, GPIO_O=0x3, GPIO_OE=0x3),
            CSR.DIRECT.vector_write(28, GPIO_O=0xC, GPIO_OE=0xA),
        ],
        [
            check(20, "cio_gpio_o", 0x3),
            check(20, "cio_gpio_en_o", 0x3),
            check(40, "cio_gpio_o", 0xC),
            check(40, "cio_gpio_en_o", 0xA),
            CSR.DIRECT.vector_read(40, GPIO_O=0xC, GPIO_OE=0xA),
        ],
    )


def interrupt_level_vectors() -> tuple[list[str], list[str]]:
    cfg = model.InterruptConfig(high=0x5, low=0xA)
    expected = model.interrupt_value(0x0, 0x5, cfg)
    return (
        [
            drive(0, "cio_gpio_i", 0x5),
            CSR.INTR_CTRL.vector_write(
                8,
                EN_RISING=0,
                EN_FALLING=0,
                EN_LVLHIGH=cfg.high,
                EN_LVLLOW=cfg.low,
                EN_INPUT_FILTER=0,
            ),
        ],
        [
            CSR.DATA_IN.vector_read(20, GPIO_IN=0x5),
            check(20, "intr_gpio_o", expected),
        ],
    )


def input_filter_vectors() -> tuple[list[str], list[str]]:
    return (
        [
            drive(0, "cio_gpio_i", 0x0),
            CSR.INTR_CTRL.vector_write(
                8,
                EN_RISING=0,
                EN_FALLING=0,
                EN_LVLHIGH=0,
                EN_LVLLOW=0,
                EN_INPUT_FILTER=0x1,
            ),
            drive(20, "cio_gpio_i", 0x1),
            drive(28, "cio_gpio_i", 0x0),
            drive(40, "cio_gpio_i", 0x1),
        ],
        [
            CSR.DATA_IN.vector_read(36, GPIO_IN=0x0),
            CSR.DATA_IN.vector_read(52, GPIO_IN=0x0),
            CSR.DATA_IN.vector_read(80, GPIO_IN=0x1),
        ],
    )


def vectors(test: str) -> tuple[list[str], list[str]]:
    if test.startswith("random_seed_"):
        return random_vectors(int(test.removeprefix("random_seed_")))

    scenarios = {
        "smoke": smoke_vectors,
        "corners": corners_vectors,
        "reconfig": reconfig_vectors,
        "interrupt_levels": interrupt_level_vectors,
        "input_filter": input_filter_vectors,
    }
    try:
        return scenarios[test]()
    except KeyError as exc:
        raise ValueError(f"unknown GPIO test {test!r}; choose one of {TESTS}") from exc


def write_test(root: str | Path, test: str) -> None:
    if test not in TESTS:
        raise ValueError(f"unknown GPIO test {test!r}; choose one of {TESTS}")

    folder = Path(root) / test
    folder.mkdir(parents=True, exist_ok=True)
    regmap.write_config(folder / "config.regs", config(test))
    in_rows, out_rows = vectors(test)

    (folder / "data_in.vec").write_text(
        "\n".join([
            "# GPIO stimulus: direct inputs and CSR writes.",
            "# <cycle> <signal> <value> or <cycle> @write <reg> <value> [mask]",
            *in_rows,
        ]) + "\n",
        encoding="utf-8",
    )
    (folder / "data_out.vec").write_text(
        "\n".join([
            "# GPIO checks: direct outputs and CSR reads.",
            "# <cycle> <signal> <expected> or <cycle> @read <reg> <expected> [mask]",
            *out_rows,
        ]) + "\n",
        encoding="utf-8",
    )


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate GPIO FlexSoC vector tests.")
    parser.add_argument("--tests-dir", default="../tb/tests")
    parser.add_argument("--test", action="append", default=[])
    parser.add_argument("--list", action="store_true")
    args = parser.parse_args()

    if args.list:
        print("\n".join(TESTS))
        return 0

    for test in args.test or TESTS:
        write_test(args.tests_dir, test)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
