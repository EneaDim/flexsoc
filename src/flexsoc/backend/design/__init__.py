"""Design-generation package API."""

from dataclasses import dataclass, field

from ..core import BackendContext, ToolRunner
from .model import ModelFlow
from .regs import RegsFlow
from .rtl import RtlFlow
from .soc import SocFlow


@dataclass(slots=True)
class Design:
    """Group register, RTL, model and SoC generation flows."""

    context: BackendContext
    runner: ToolRunner | None = None
    regs: RegsFlow = field(init=False)
    rtl: RtlFlow = field(init=False)
    model: ModelFlow = field(init=False)
    soc: SocFlow = field(init=False)

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)
        self.regs = RegsFlow(self.context.project_root, self.runner)
        self.rtl = RtlFlow(self.context.project_root, self.runner)
        self.model = ModelFlow(self.context.project_root)
        self.soc = SocFlow(self.context.project_root, self.runner)


__all__ = ["Design", "RegsFlow", "RtlFlow", "ModelFlow", "SocFlow"]
