"""Native FlexSoC Ethernet model API: the pinned independent M4 semantic oracle.

Packet/CSR semantics only. Not a cycle-accurate clock, CDC or PHY model.
The implementation lives in dv/functional/model/ethernet_oracle.py.
"""
from __future__ import annotations
from pathlib import Path
import sys
_model_dir = Path(__file__).resolve().parents[1] / "model"
if not (_model_dir / "ethernet_oracle.py").is_file():
    raise RuntimeError("Pinned Ethernet oracle not installed")
if str(_model_dir) not in sys.path:
    sys.path.insert(0, str(_model_dir))
from ethernet_oracle import *  # noqa: F403 -- preserve public oracle API
TOP = "ethernet"
