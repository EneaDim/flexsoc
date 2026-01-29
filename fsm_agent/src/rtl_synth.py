from __future__ import annotations
from typing import Any, Dict

def ir_to_fsm(ir: Dict[str, Any]) -> Dict[str, Any]:
    out = {
        "states": ir["states"],
        "transitions": ir["transitions"],
        "outputs_header": ir["outputs_header"],
        "outputs": ir["outputs"],
        "assumptions": list(ir.get("assumptions", [])),
    }
    return out
