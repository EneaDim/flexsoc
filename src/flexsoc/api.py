"""Public API layer for FlexSoC.

This module is the stable boundary used by future CLI, web, and frontend code.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Any


@dataclass(slots=True)
class FlexOCConfig:
    """Configuration object shared by workflow and step calls.

    Extra values keep the first API thin while backend contracts are stabilized.
    """

    project_root: Path | None = None
    workdir: Path | None = None
    options: dict[str, Any] = field(default_factory=dict)

    @classmethod
    def from_values(cls, config: "FlexOCConfig | None" = None, **overrides: Any) -> "FlexOCConfig":
        """Build a config from an optional object plus keyword overrides."""

        base = config or cls()
        options = dict(base.options)
        options.update(overrides.pop("options", {}) or {})
        options.update(overrides)
        return cls(project_root=base.project_root, workdir=base.workdir, options=options)


class FlexOC:
    """Thin public client for FlexSoC workflows and advanced backend steps."""

    def __init__(self, config: FlexOCConfig | None = None, **overrides: Any) -> None:
        """Create a client and normalize user-provided configuration values."""

        self.config = FlexOCConfig.from_values(config, **overrides)

    def describe(self) -> dict[str, Any]:
        """Return a small, testable description of the configured API client."""

        return {
            "package": "flexsoc",
            "api": "FlexOC",
            "project_root": str(self.config.project_root) if self.config.project_root else None,
            "workdir": str(self.config.workdir) if self.config.workdir else None,
            "options": dict(self.config.options),
        }
