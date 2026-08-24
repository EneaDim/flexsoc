"""Synthesis and equivalence package API."""

from dataclasses import dataclass, field

from ..core import BackendContext, ToolRunner
from .eqy import EquivalenceConfig, EquivalenceFlow
from .syn import SynthesisConfig, SynthesisFlow


@dataclass(slots=True)
class Syn:
    """Group synthesis and RTL-to-gate equivalence."""

    context: BackendContext
    runner: ToolRunner | None = None
    synthesis: SynthesisFlow = field(init=False)
    eqy: EquivalenceFlow = field(init=False)

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)
        self.synthesis = SynthesisFlow(self.runner)
        self.eqy = EquivalenceFlow(self.runner)


__all__ = [
    "Syn", "SynthesisConfig", "SynthesisFlow",
    "EquivalenceConfig", "EquivalenceFlow",
]
