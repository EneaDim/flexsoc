"""Functional testbench scaffold orchestration."""

from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

from flexsoc.backend.core import ClockConfig, clock_config

from .cocotb_testbench import CocotbConfig, CocotbTestbench
from .sv_testbench import SystemVerilogTestbench, TestbenchConfig


@dataclass(slots=True)
class TestbenchFlow:
    """Generate the complementary SystemVerilog and cocotb scaffolds."""

    systemverilog: SystemVerilogTestbench = field(default_factory=SystemVerilogTestbench)
    cocotb: CocotbTestbench = field(default_factory=CocotbTestbench)

    def setup_systemverilog(
        self, config: TestbenchConfig, *, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        return self.systemverilog.setup(config, clocks=clocks or clock_config())

    def setup_cocotb(
        self, config: CocotbConfig, *, clocks: ClockConfig | None = None
    ) -> list[Path]:
        return self.cocotb.setup(config, clocks=clocks or clock_config())

    def flow(
        self,
        sv_config: TestbenchConfig,
        cocotb_config: CocotbConfig,
        *,
        clocks: ClockConfig | None = None,
    ) -> tuple[tuple[Path, ...], list[Path]]:
        clocks = clocks or clock_config()
        return (
            self.setup_systemverilog(sv_config, clocks=clocks),
            self.setup_cocotb(cocotb_config, clocks=clocks),
        )
