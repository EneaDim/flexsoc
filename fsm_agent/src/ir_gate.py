from __future__ import annotations
from typing import Any, Dict, List

def enforce_entities(ir: Dict[str, Any], entities: Dict[str, Any]) -> None:
    sc = entities.get("state_candidates", [])
    initc = entities.get("init_state_candidate", "")
    if not isinstance(sc, list) or not all(isinstance(s,str) for s in sc):
        return
    ir["states"] = sc[:]  # force exact
    if isinstance(initc, str) and initc in sc:
        ir["init_state"] = initc
    else:
        ir["init_state"] = sc[0] if sc else "IDLE"
