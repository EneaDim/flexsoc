from __future__ import annotations

import os
import sys
from pathlib import Path


def _prepend_path_var(env_name: str, value: str) -> None:
    current = os.environ.get(env_name, "").strip()
    parts = [p for p in current.split(os.pathsep) if p] if current else []
    if value not in parts:
        os.environ[env_name] = value + (os.pathsep + current if current else "")


REPO_ROOT = Path(__file__).resolve().parents[1]
SRC_DIR = REPO_ROOT / "src"

if str(SRC_DIR) not in sys.path:
    sys.path.insert(0, str(SRC_DIR))

_prepend_path_var("PYTHONPATH", str(SRC_DIR))
