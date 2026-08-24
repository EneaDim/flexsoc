"""FlexSoC backend package organized by ASIC lifecycle domain."""

from dataclasses import dataclass, field

from .core import BackendContext, PackageFlow, PdkManager, Reporting, ToolRunner, Toolchain
from .design import Design, ModelFlow, RegsFlow, RtlFlow, SocFlow
from .dv import DvFlow
from .impl import ImplementationFlow
from .signoff import Signoff, SignoffStage
from .syn import EquivalenceFlow, Syn, SynthesisFlow


@dataclass(slots=True)
class Backend:
    """Compose the reusable FlexSoC backend domain facades."""

    context: BackendContext
    runner: ToolRunner | None = None
    pdk: PdkManager = field(init=False)
    design: Design = field(init=False)
    dv: DvFlow = field(init=False)
    syn: Syn = field(init=False)
    signoff: Signoff = field(init=False)
    impl: ImplementationFlow = field(init=False)
    reporting: Reporting = field(init=False)
    package: PackageFlow = field(init=False)
    toolchain: Toolchain = field(init=False)

    def __post_init__(self) -> None:
        root = self.context.project_root
        self.runner = self.runner or ToolRunner(project_root=root)
        self.pdk = PdkManager(root)
        self.design = Design(self.context, self.runner)
        self.dv = DvFlow(self.context, self.runner)
        self.syn = Syn(self.context, self.runner)
        self.signoff = Signoff(root, self.context.values, self.runner)
        self.impl = ImplementationFlow(self.runner)
        self.reporting = Reporting()
        self.package = PackageFlow(root, self.context.values)
        self.toolchain = Toolchain(root, self.runner)


__all__ = [
    "Backend", "BackendContext", "PdkManager", "ToolRunner",
    "Design", "RegsFlow", "RtlFlow", "ModelFlow", "SocFlow", "DvFlow",
    "Syn", "SynthesisFlow", "EquivalenceFlow", "Signoff", "SignoffStage",
    "ImplementationFlow", "Reporting", "PackageFlow", "Toolchain",
]
