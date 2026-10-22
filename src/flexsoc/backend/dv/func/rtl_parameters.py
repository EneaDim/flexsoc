"""Portable, per-scenario elaboration parameter request contract.

Parameters are compile-time requests, never runtime CSR writes. A Slang-derived
catalog must validate names and effective values before applying overrides.
"""
from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Mapping

_NAME = re.compile(r"[A-Za-z_][A-Za-z_0-9]*\Z")


def read_rtl_parameters(test_dir: Path) -> dict[str, int | str]:
    """Read an optional IP-generated sidecar; fail closed on malformed requests."""
    path = Path(test_dir) / "rtl_parameters.json"
    if not path.exists():
        return {}
    document = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(document, dict) or set(document) != {"schema", "parameters"} or document["schema"] != 1:
        raise ValueError(f"invalid RTL parameter sidecar schema: {path}")
    params = document["parameters"]
    if not isinstance(params, dict):
        raise ValueError(f"RTL parameters must be a mapping: {path}")
    for name, value in params.items():
        if not isinstance(name, str) or not _NAME.fullmatch(name):
            raise ValueError(f"invalid RTL parameter identifier {name!r}: {path}")
        if isinstance(value, bool) or not (isinstance(value, int) or isinstance(value, str)):
            raise ValueError(f"invalid RTL parameter value for {name}: {path}")
        if isinstance(value, str) and (not value or len(value) > 256 or any(c in value for c in "\n\r\x00")):
            raise ValueError(f"invalid RTL parameter literal for {name}: {path}")
    return dict(sorted(params.items()))


def write_rtl_parameters(test_dir: Path, parameters: Mapping[str, int | str]) -> Path:
    """Write the scenario's deterministic compile-time configuration."""
    path = Path(test_dir) / "rtl_parameters.json"
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps({"schema": 1, "parameters": dict(sorted(parameters.items()))}, indent=2) + "\n", encoding="utf-8")
    read_rtl_parameters(path.parent)
    return path
