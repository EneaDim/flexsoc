from __future__ import annotations

from pathlib import Path

from cocotb.triggers import RisingEdge

from drivers.reg_driver import PRIMARY_CLOCK, READ_TOKENS, _sample_cycle, parse_u32, read_reg

WAIT_EVENT_TOKENS = {"@wait_event", "wait_event"}
WAIT_SIGNAL_TOKENS = {"@wait_signal", "wait_signal"}
SIGNAL_CLOCKS = {'rx_i': 'clk_i', 'axi_lite_i': 'clk_i', 'tx_o': 'clk_i', 'axi_lite_o': 'clk_i'}


class CycleMonitor:
    def __init__(self, dut, expected_path=None):
        self.dut = dut
        self.path = Path(expected_path) if expected_path is not None else None
        self.now = -1
        self.event_cursor = 0

    def _rows(self):
        if self.path is None or not self.path.exists():
            return ()
        rows = []
        for lineno, raw_line in enumerate(self.path.read_text(encoding="utf-8").splitlines(), start=1):
            line = raw_line.split("#", 1)[0].strip()
            if line:
                rows.append((lineno, line.split()))
        return rows

    async def _advance_to(self, cycle):
        clk = getattr(self.dut, PRIMARY_CLOCK)
        while self.now < cycle:
            await _sample_cycle(clk)
            self.now += 1

    async def _wait_event(self, label, expected, timeout):
        clk = getattr(self.dut, PRIMARY_CLOCK)
        for _ in range(max(1, int(timeout))):
            await RisingEdge(clk)
            sequence = int(self.dut.flexsoc_event_sequence.value)
            if sequence != self.event_cursor:
                self.event_cursor = sequence
                value = int(self.dut.flexsoc_event_value.value) & 0xFFFFFFFF
                if value == int(expected) & 0xFFFFFFFF:
                    self.dut._log.info(
                        "[TB][EVENT] observed name=%s value=0x%08x", label, expected
                    )
                    self.now = -1
                    return
        raise AssertionError(
            f"event timeout name={label} value=0x{int(expected) & 0xffffffff:08x}"
        )

    async def _wait_signal(self, name, expected, timeout):
        if not hasattr(self.dut, name):
            raise AssertionError(f"unknown wait signal: {name}")
        clock = SIGNAL_CLOCKS.get(name, PRIMARY_CLOCK)
        clk = getattr(self.dut, clock)
        handle = getattr(self.dut, name)
        mask = (1 << len(handle)) - 1
        expected = int(expected) & mask
        for _ in range(max(1, int(timeout))):
            await RisingEdge(clk)
            if int(handle.value) & mask == expected:
                self.now = -1
                return
        raise AssertionError(f"signal timeout name={name} value=0x{expected:x}")

    def _read_signal(self, name):
        if not hasattr(self.dut, name):
            raise AssertionError(f"unknown expected-output vector signal: {name}")
        return int(getattr(self.dut, name).value) & 0xFFFFFFFF

    def _check_signal(self, cycle, name, expected):
        got = self._read_signal(name)
        expected &= 0xFFFFFFFF
        if got != expected:
            raise AssertionError(
                f"cycle={cycle} {name}: got 0x{got:08x}, expected 0x{expected:08x}"
            )
        self.dut._log.info("check %s == 0x%08x", name, expected)

    async def run(self):
        for lineno, parts in self._rows():
            if len(parts) < 2:
                continue
            try:
                cycle = parse_u32(parts[0])
            except ValueError:
                if len(parts) < 3:
                    raise ValueError(f"{self.path}:{lineno}: guarded output row is incomplete")
                await self._wait_signal(parts[0], 1, 4096)
                for idx in range(1, len(parts), 2):
                    self._check_signal(self.now, parts[idx], parse_u32(parts[idx + 1]))
                continue

            command = parts[1]
            await self._advance_to(cycle)
            if command in WAIT_EVENT_TOKENS:
                if len(parts) not in (4, 5):
                    raise ValueError(
                        f"{self.path}:{lineno}: @wait_event format is: "
                        "cycle @wait_event label value [timeout]"
                    )
                await self._wait_event(
                    parts[2], parse_u32(parts[3]), parse_u32(parts[4]) if len(parts) == 5 else 1024
                )
                continue
            if command in WAIT_SIGNAL_TOKENS:
                if len(parts) not in (4, 5):
                    raise ValueError(
                        f"{self.path}:{lineno}: @wait_signal format is: "
                        "cycle @wait_signal signal value [timeout]"
                    )
                await self._wait_signal(
                    parts[2], parse_u32(parts[3]), parse_u32(parts[4]) if len(parts) == 5 else 1024
                )
                continue
            if command in READ_TOKENS:
                if len(parts) not in (4, 5):
                    raise ValueError(
                        f"{self.path}:{lineno}: @read format is: cycle @read reg expected [mask]"
                    )
                got = await read_reg(self.dut, parts[2])
                expected = parse_u32(parts[3])
                mask = parse_u32(parts[4]) if len(parts) == 5 else 0xFFFFFFFF
                if (got & mask) != (expected & mask):
                    raise AssertionError(
                        f"cycle={cycle} read {parts[2]}: got 0x{got:08x}, "
                        f"expected 0x{expected:08x}, mask=0x{mask:08x}"
                    )
                continue
            if (len(parts) - 1) % 2 != 0:
                raise ValueError(f"{self.path}:{lineno}: expected signal/value pairs")
            for idx in range(1, len(parts), 2):
                self._check_signal(cycle, parts[idx], parse_u32(parts[idx + 1]))
