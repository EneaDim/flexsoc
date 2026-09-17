"""Top-level composition of FlexSoC backend domains."""

from dataclasses import dataclass, field

from .core import BackendContext, Core, ToolRunner
from .design import Design
from .dv import DvFlow
from .impl import ImplementationFlow
from .release import ReleaseFlow
from .signoff import Signoff
from .syn import Syn


@dataclass(slots=True)
class Backend:
    """Compose the backend domains used by one target session."""

    context: BackendContext
    runner: ToolRunner | None = None
    core: Core = field(init=False)
    design: Design = field(init=False)
    dv: DvFlow = field(init=False)
    syn: Syn = field(init=False)
    signoff: Signoff = field(init=False)
    impl: ImplementationFlow = field(init=False)
    release: ReleaseFlow = field(init=False)

    def __post_init__(self) -> None:
        root = self.context.project_root
        self.runner = self.runner or ToolRunner(project_root=root)
        self.core = Core(self.context, self.runner)
        self.design = Design(self.context, self.runner)
        self.dv = DvFlow(self.context, self.runner)
        self.syn = Syn(self.context, self.runner)
        self.signoff = Signoff(self.context, self.runner)
        self.impl = ImplementationFlow(self.context, self.runner)
        self.release = ReleaseFlow(self.context, self.runner)
