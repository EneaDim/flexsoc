"""Editable CPU-driven SoC functional-test catalogue."""

from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path


TESTS = ("smoke",)


@dataclass(slots=True)
class TestCase:
    config: list[str]
    data_in: list[str]
    data_out: list[str]


def drive(cycle: int, signal: str, value: int) -> str:
    return f"{cycle} {signal} 0x{value & 0xFFFF_FFFF:08x}"


def wait_event(cycle: int, name: str, value: int, timeout: int = 1024) -> str:
    return f"{cycle} @wait_event {name} 0x{value & 0xFFFF_FFFF:08x} {timeout}"


def wait_signal(cycle: int, signal: str, value: int, timeout: int = 1024) -> str:
    return f"{cycle} @wait_signal {signal} 0x{value & 0xFFFF_FFFF:08x} {timeout}"


def smoke() -> TestCase:
    """Replace with one CPU-driven scenario."""

    return TestCase(config=[], data_in=[], data_out=[])


def test_case(test: str) -> TestCase:
    scenarios = {"smoke": smoke}
    try:
        return scenarios[test]()
    except KeyError as exc:
        raise ValueError(f"unknown test {test!r}; choose one of {TESTS}") from exc


def write_test(root: str | Path, test: str) -> None:
    case = test_case(test)
    folder = Path(root) / test
    folder.mkdir(parents=True, exist_ok=True)
    (folder / "config.regs").write_text("\n".join(case.config) + ("\n" if case.config else ""), encoding="utf-8")
    (folder / "data_in.vec").write_text("\n".join(case.data_in) + ("\n" if case.data_in else ""), encoding="utf-8")
    (folder / "data_out.vec").write_text("\n".join(case.data_out) + ("\n" if case.data_out else ""), encoding="utf-8")


def write_all_tests(root: str | Path, tests: list[str] | tuple[str, ...] | None = None) -> None:
    for test in tests or TESTS:
        write_test(root, test)


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate CPU-driven SoC functional vectors.")
    parser.add_argument("--tests-dir", default="../tests")
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
