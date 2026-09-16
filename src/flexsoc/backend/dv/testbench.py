"""Functional testbench scaffold orchestration."""

from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

from flexsoc.backend.core import ClockConfig, clock_config

from .cocotb_testbench import CocotbConfig, CocotbTestbench
from .multiclock_testbench import MulticlockDspTestbench
from .sv_testbench import SystemVerilogTestbench, TestbenchConfig


@dataclass(slots=True)
class TestbenchFlow:
    """Select and run the functional-DV scaffold renderers."""

    systemverilog: SystemVerilogTestbench = field(default_factory=SystemVerilogTestbench)
    cocotb: CocotbTestbench = field(default_factory=CocotbTestbench)
    multiclock: MulticlockDspTestbench = field(default_factory=MulticlockDspTestbench)

    def setup_systemverilog(
        self, config: TestbenchConfig, *, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        clocks = clocks or clock_config()
        if clocks.multiclock:
            return self.multiclock.setup_systemverilog(config, clocks)
        return self.systemverilog.setup(config, clocks=clocks)

    def setup_cocotb(
        self, config: CocotbConfig, *, clocks: ClockConfig | None = None
    ) -> list[Path]:
        clocks = clocks or clock_config()
        if clocks.multiclock:
            return self.multiclock.setup_cocotb(config, clocks)
        return self.cocotb.setup(config, clocks=clocks)

    def flow(
        self, sv_config: TestbenchConfig, cocotb_config: CocotbConfig,
        *, clocks: ClockConfig | None = None,
    ) -> tuple[tuple[Path, ...], list[Path]]:
        return (
            self.setup_systemverilog(sv_config, clocks=clocks),
            self.setup_cocotb(cocotb_config, clocks=clocks),
        )
