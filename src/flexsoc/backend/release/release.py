"""Release lifecycle composition for qualification, packaging, and reporting."""

from __future__ import annotations

from dataclasses import dataclass, field

from ..core import BackendContext, ToolRunner
from .package import PackageFlow
from .qualification import QualificationFlow
from .reporting import Reporting


@dataclass(slots=True)
class ReleaseFlow:
    """Own the release-facing backend responsibilities for one session."""

    context: BackendContext
    runner: ToolRunner
    qualification: QualificationFlow = field(init=False)
    package: PackageFlow = field(init=False)
    reporting: Reporting = field(init=False)

    def __post_init__(self) -> None:
        self.qualification = QualificationFlow(self.context)
        self.package = PackageFlow(self.context.project_root, self.context.values)
        self.reporting = Reporting(self.runner)
