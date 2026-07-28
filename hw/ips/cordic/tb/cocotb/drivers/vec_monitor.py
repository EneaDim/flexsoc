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
                raise ValueError(f"{path}:{lineno}: expected cycle and command/pairs")

            cycle = parse_u32(parts[0])
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

            expected = item[1]
            if not hasattr(self.dut, name):
                raise AssertionError(f"unknown expected-output vector signal: {name}")

            got = int(getattr(self.dut, name).value) & 0xFFFFFFFF
            if got != expected:
                raise AssertionError(
                    f"cycle={cycle} {name}: got 0x{got:08x}, expected 0x{expected:08x}"
                )

            self.dut._log.info("check %s == 0x%08x", name, expected)
