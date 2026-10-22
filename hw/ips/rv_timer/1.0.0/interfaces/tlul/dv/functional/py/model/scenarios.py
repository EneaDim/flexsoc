"""RV Timer functional cases, independent of register packing."""
from dataclasses import dataclass

@dataclass(frozen=True)
class TimerConfig:
    active: bool = True
    prescaler: int = 0
    step: int = 1
    mtime: int = 0
    compare: int = 0
    irq_enable: bool = True

TIMER = TimerConfig()
RECONFIG_BEFORE = TimerConfig(active=False, prescaler=7, step=1, mtime=0x10, compare=0x100, irq_enable=False)
RECONFIG_AFTER = TimerConfig(active=False, prescaler=3, step=5, mtime=0x12345678, compare=0x87654321, irq_enable=False)
MODEL_CASES = ("timer", "reconfig")
