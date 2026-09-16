"""FlexSoC backend package organized by ASIC lifecycle domain."""

from dataclasses import dataclass, field

from .core import (
    BackendContext, PackageFlow, PdkManager, QualificationFlow, Reporting,
    ToolRunner, Toolchain, WorkspaceFlow,
)
from .design import Design, FsmFlow, ModelFlow, RegsFlow, RtlFlow, SocFlow
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
    qualification: QualificationFlow = field(init=False)
    toolchain: Toolchain = field(init=False)
    workspace: WorkspaceFlow = field(init=False)

    def __post_init__(self) -> None:
        root = self.context.project_root
        self.runner = self.runner or ToolRunner(project_root=root)
        self.pdk = PdkManager(root)
        self.design = Design(self.context, self.runner)
        self.dv = DvFlow(self.context, self.runner)
        self.syn = Syn(self.context, self.runner)
        self.signoff = Signoff(self.context, self.runner)
        self.impl = ImplementationFlow(self.context, self.runner)
        self.reporting = Reporting()
        self.package = PackageFlow(root, self.context.values)
        self.qualification = QualificationFlow(self.context)
        self.toolchain = Toolchain(root, self.runner)
        self.workspace = WorkspaceFlow(self.context, self.runner)


__all__ = [
    "Backend", "BackendContext", "PdkManager", "ToolRunner",
    "Design", "RegsFlow", "RtlFlow", "ModelFlow", "SocFlow", "FsmFlow", "DvFlow",
    "Syn", "SynthesisFlow", "EquivalenceFlow", "Signoff", "SignoffStage",
    "ImplementationFlow", "Reporting", "PackageFlow", "QualificationFlow", "Toolchain", "WorkspaceFlow",
]
