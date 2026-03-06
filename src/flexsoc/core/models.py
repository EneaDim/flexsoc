from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class RunRef:
    workspace: Path
    run_top: str
    run_id: str
    top: str | None = None
