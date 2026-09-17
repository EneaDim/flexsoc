"""Functional testbench scaffold orchestration."""

from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

from flexsoc.backend.core import ClockConfig

from .cocotb import CocotbConfig, CocotbTestbench
from .sv import SystemVerilogTestbench, TestbenchConfig


@dataclass(slots=True)
class Testbench:
    """Generate the complementary SystemVerilog and cocotb scaffolds."""

    systemverilog: SystemVerilogTestbench = field(default_factory=SystemVerilogTestbench)
    cocotb: CocotbTestbench = field(default_factory=CocotbTestbench)

    def setup_systemverilog(
        self, config: TestbenchConfig, *, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        return self.systemverilog.setup(config, clocks=clocks or ClockConfig.from_values())

    def setup_cocotb(
        self, config: CocotbConfig, *, clocks: ClockConfig | None = None
    ) -> list[Path]:
        return self.cocotb.setup(config, clocks=clocks or ClockConfig.from_values())
