from __future__ import annotations

from pathlib import Path


def default_workspace() -> Path:
    # default workspace at repo root /workspace
    return Path("workspace")
