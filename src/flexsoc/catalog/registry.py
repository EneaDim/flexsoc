from __future__ import annotations

from pathlib import Path
from typing import Any

from .planning import load_registry as _load_registry_file


def registry_path() -> Path:
    return Path(__file__).with_name("registry.yaml")


def load_registry(path: Path | None = None) -> dict[str, Any]:
    return _load_registry_file(path or registry_path())
