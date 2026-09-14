from __future__ import annotations

import re
from collections import defaultdict
from pathlib import Path

from drivers.reg_driver import READ_TOKENS, parse_u32

_SIGNAL_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_./:-]*$")


def _looks_like_signal(token):
    return bool(_SIGNAL_RE.match(str(token)))


class LatencyMonitor:
    def __init__(self, dut, expected_path=None, *, register_reader=None):
        self.dut = dut
        self.expected = defaultdict(list)
        self.guarded = []
        self.last_cycle = -1
        self.register_reader = register_reader
        self._load(expected_path)

    def _load(self, path):
        if path is None:
            return

        path = Path(path)
        if not path.exists():
            return

        for lineno, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
            line = raw_line.split("#", 1)[0].strip()
            if not line:
                continue

            parts = line.split()
            if len(parts) < 3:
                raise ValueError(
                    f"{path}:{lineno}: expected cycle/valid signal and command/pairs"
                )

            first = parts[0]
            try:
                cycle = parse_u32(first)
            except ValueError:
                if not _looks_like_signal(first):
                    raise ValueError(f"{path}:{lineno}: invalid cycle/valid token: {first}")
                if (len(parts) - 1) % 2 != 0:
                    raise ValueError(
                        f"{path}:{lineno}: valid-guarded row must be "
                        "<valid_signal> <signal> <expected> [<signal> <expected> ...]"
                    )
                checks = []
                for idx in range(1, len(parts), 2):
                    name = parts[idx]
                    if not _looks_like_signal(name):
                        raise ValueError(f"{path}:{lineno}: invalid signal name: {name}")
                    checks.append((name, parse_u32(parts[idx + 1])))
                self.guarded.append((first, checks))
                continue

            self.last_cycle = max(self.last_cycle, cycle)
            command = parts[1]

            if command in READ_TOKENS:
                if len(parts) not in (4, 5):
                    raise ValueError(f"{path}:{lineno}: @read format is: cycle @read reg expected [mask]")
                mask = parts[4] if len(parts) == 5 else "0xffffffff"
                self.expected[cycle].append(("@read", parts[2], parse_u32(parts[3]), parse_u32(mask)))
                continue

            if (len(parts) - 1) % 2 != 0:
                raise ValueError(f"{path}:{lineno}: expected cycle followed by signal/value pairs")

            for idx in range(1, len(parts), 2):
                name = parts[idx]
                if not _looks_like_signal(name):
                    raise ValueError(f"{path}:{lineno}: invalid signal name: {name}")
                self.expected[cycle].append((name, parse_u32(parts[idx + 1])))

    def has_pending_guarded(self):
        return bool(self.guarded)

    def _read_signal(self, name):
        if not hasattr(self.dut, name):
            raise AssertionError(f"unknown expected-output vector signal: {name}")
        return int(getattr(self.dut, name).value) & 0xFFFFFFFF

    def _check_signal(self, cycle, name, expected):
        got = self._read_signal(name)
        if got != expected:
            raise AssertionError(
                f"cycle={cycle} {name}: got 0x{got:08x}, expected 0x{expected:08x}"
            )
        self.dut._log.info("check %s == 0x%08x", name, expected)

    async def check(self, cycle):
        for item in self.expected.pop(cycle, []):
            name = item[0]

            if name in READ_TOKENS:
                if self.register_reader is None:
                    raise AssertionError("@read row requested but no register_reader was provided")

                _, reg, expected, mask = item
                got = await self.register_reader(reg)
                if (got & mask) != (expected & mask):
                    raise AssertionError(
                        f"cycle={cycle} read {reg}: got 0x{got:08x}, "
                        f"expected 0x{expected:08x}, mask 0x{mask:08x}"
                    )

                self.dut._log.info("read check %s == 0x%08x mask=0x%08x", reg, expected, mask)
                continue

            self._check_signal(cycle, name, item[1])

        if self.guarded:
            valid_signal, checks = self.guarded[0]
            if self._read_signal(valid_signal) & 0x1:
                for name, expected in checks:
                    self._check_signal(cycle, name, expected)
                self.dut._log.info("guarded output row consumed on %s", valid_signal)
                self.guarded.pop(0)
