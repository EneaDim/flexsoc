"""Top-level composition of FlexSoC design domains."""

from __future__ import annotations

from dataclasses import dataclass, field

from ..core import BackendContext, ToolRunner
from .fsm.fsm_gen import FsmFlow
from .ip.ip import IpDesign
from .soc.soc import SocFlow


@dataclass(slots=True)
class Design:
    """Own IP, FSM, and SoC design flows for one backend context."""

    context: BackendContext
    runner: ToolRunner | None = None
    ip: IpDesign = field(init=False)
    fsm: FsmFlow = field(init=False)
    soc: SocFlow = field(init=False)

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)
        self.ip = IpDesign(self.context, self.runner)
        self.fsm = FsmFlow(self.context.paths.run, self.runner)
        self.soc = SocFlow(self.context.project_root, self.runner)
