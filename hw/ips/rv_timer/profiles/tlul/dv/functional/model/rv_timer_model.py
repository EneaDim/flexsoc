"""Small behavioral model of RV_TIMER."""

from dataclasses import dataclass

TOP = "rv_timer"
INPUTS = ("gpio_intr_i",)
OUTPUTS = ("intr_timer_expired_hart0_timer0_o",)

U32 = 0xFFFF_FFFF


@dataclass
class RvTimerModel:
    active: bool = False
    prescaler: int = 0
    step: int = 1
    mtime: int = 0
    compare: int = U32
    irq_enable: bool = False
    gpio_select: int | None = None

    tick_count: int = 0
    irq_state: bool = False
    capture_active: bool = False

    def reset(self) -> None:
        self.tick_count = 0
        self.irq_state = False
        self.capture_active = False
        self.mtime = 0

    def write_compare(self, value: int) -> None:
        self.compare = value & U32
        self.irq_state = False

    def cycle(self, gpio_intr: int = 0) -> dict[str, int]:
        running = self.active or self.capture_active
        tick = running and self.tick_count >= (self.prescaler & 0xFFF)
        event = running and self.mtime >= self.compare

        if event:
            self.irq_state = True
        if tick:
            self.mtime = (self.mtime + self.step) & U32

        if not running or self.tick_count == (self.prescaler & 0xFFF):
            self.tick_count = 0
        else:
            self.tick_count = (self.tick_count + 1) & 0xFFF

        if self.gpio_select in (0, 1):
            bit = (gpio_intr >> self.gpio_select) & 1
            self.capture_active = bool(self.capture_active ^ bit)
        else:
            self.capture_active = False

        return {
            "tick": int(tick),
            "mtime": self.mtime,
            "irq_state": int(self.irq_state),
            "irq": int(self.irq_state and self.irq_enable),
        }

    def run(self, cycles: int, gpio_intr: int = 0) -> dict[str, int]:
        result = {}
        for _ in range(cycles):
            result = self.cycle(gpio_intr)
        return result
