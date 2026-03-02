from __future__ import annotations

from pathlib import Path
from typing import Any, Dict

import yaml


def load_registry() -> Dict[str, Any]:
    p = Path(__file__).parent / "registry.yaml"
    return yaml.safe_load(p.read_text(encoding="utf-8"))
