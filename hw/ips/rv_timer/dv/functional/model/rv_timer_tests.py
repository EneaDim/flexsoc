"""Functional vectors for RV_TIMER."""

import argparse
import random
from pathlib import Path

import rv_timer_regmap as regmap
from rv_timer_model import RvTimerModel


CSR = regmap.PRIMARY
IRQ = "intr_timer_expired_hart0_timer0_o"

TESTS = (
    "smoke",
    "corners",
    "random_seed_1",
    "random_seed_2",
    "reconfig",
    "timer",
)


def ctrl(active=0, gpio0=0, gpio1=0):
    return (active & 1) | ((gpio0 & 1) << 1) | ((gpio1 & 1) << 2)


def cfg(prescale=0, step=1):
    return (prescale & 0xFFF) | ((step & 0xFF) << 12)


def drive(cycle, value):
    return f"{cycle} gpio_intr_i 0x{value & 3:08x}"


def check_irq(cycle, value):
    return f"{cycle} {IRQ} 0x{value & 1:08x}"


def base_config(*, control=0, config=None, timer=0, compare=0xFFFF_FFFF, irq=0):
    if config is None:
        config = cfg()
    return [
        CSR.CTRL.write(control),
        CSR.INTR_ENABLE0.write(irq),
        CSR.CFG0.write(config),
        CSR.TIMER_V0.write(timer),
        CSR.COMPARE_V0.write(compare),
    ]


def smoke():
    return (
        base_config(),
        [drive(0, 0)],
        [
            check_irq(8, 0),
            CSR.CTRL.vector_read(12, 0),
            CSR.CFG0.vector_read(16, cfg()),
            CSR.TIMER_V0.vector_read(20, 0),
            CSR.COMPARE_V0.vector_read(24, 0xFFFF_FFFF),
        ],
    )


def corners():
    return (
        base_config(
            config=cfg(0xFFF, 0xFF),
            timer=0xFFFF_FFFF,
            compare=0,
        ),
        [drive(0, 3)],
        [
            check_irq(8, 0),
            CSR.CFG0.vector_read(12, cfg(0xFFF, 0xFF)),
            CSR.TIMER_V0.vector_read(16, 0xFFFF_FFFF),
            CSR.COMPARE_V0.vector_read(20, 0),
        ],
    )


def random_case(seed):
    rng = random.Random(seed)
    prescale = rng.randrange(0x1000)
    step = rng.randrange(0x100)
    timer = rng.getrandbits(32)
    compare = rng.getrandbits(32)

    return (
        base_config(
            config=cfg(prescale, step),
            timer=timer,
            compare=compare,
        ),
        [drive(0, rng.randrange(4))],
        [
            check_irq(8, 0),
            CSR.CFG0.vector_read(12, cfg(prescale, step)),
            CSR.TIMER_V0.vector_read(16, timer),
            CSR.COMPARE_V0.vector_read(20, compare),
        ],
    )


def reconfig():
    return (
        base_config(
            config=cfg(7, 1),
            timer=0x10,
            compare=0x100,
        ),
        [
            drive(0, 0),
            CSR.CFG0.vector_write(8, cfg(3, 5)),
            CSR.TIMER_V0.vector_write(16, 0x1234_5678),
            CSR.COMPARE_V0.vector_write(24, 0x8765_4321),
        ],
        [
            check_irq(36, 0),
            CSR.CFG0.vector_read(40, cfg(3, 5)),
            CSR.TIMER_V0.vector_read(44, 0x1234_5678),
            CSR.COMPARE_V0.vector_read(48, 0x8765_4321),
        ],
    )


def timer():
    # Compare=0 means the first active cycle must produce an event.
    model = RvTimerModel(active=True, compare=0, irq_enable=True)
    assert model.run(2)["irq"] == 1

    return (
        [
            CSR.CFG0.write(cfg(0, 1)),
            CSR.TIMER_V0.write(0),
            CSR.COMPARE_V0.write(0),
            CSR.INTR_ENABLE0.write(1),
            CSR.CTRL.write(ctrl(active=1)),
        ],
        [
            drive(0, 0),
            # Writing COMPARE clears INTR_STATE in rv_timer.sv.
            CSR.COMPARE_V0.vector_write(32, 0xFFFF_FFFF),
        ],
        [
            check_irq(16, 1),
            CSR.INTR_STATE0.vector_read(20, 1),
            check_irq(48, 0),
            CSR.INTR_STATE0.vector_read(52, 0),
        ],
    )


def make_case(name):
    if name == "smoke":
        return smoke()
    if name == "corners":
        return corners()
    if name == "reconfig":
        return reconfig()
    if name == "timer":
        return timer()
    if name.startswith("random_seed_"):
        return random_case(int(name.rsplit("_", 1)[1]))
    raise ValueError(f"unknown test: {name}")


def write_lines(path, lines):
    Path(path).write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_test(root, name):
    config, data_in, data_out = make_case(name)
    out = Path(root) / name
    out.mkdir(parents=True, exist_ok=True)

    write_lines(out / "config.regs", config)
    write_lines(out / "data_in.vec", data_in)
    write_lines(out / "data_out.vec", data_out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--tests-dir", default="../tests")
    parser.add_argument("--test", action="append")
    parser.add_argument("--list", action="store_true")
    args = parser.parse_args()

    if args.list:
        print("\n".join(TESTS))
        return 0

    for name in args.test or TESTS:
        write_test(args.tests_dir, name)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
