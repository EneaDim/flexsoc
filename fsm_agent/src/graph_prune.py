from __future__ import annotations
from typing import Any, Dict, List, Set

def prune_disconnected_states(ir: Dict[str, Any]) -> List[str]:
    states: List[str] = ir.get("states", [])
    trans: List[Dict[str, Any]] = ir.get("transitions", [])
    outs: Dict[str, Any] = ir.get("outputs", {})
    init_state: str = ir.get("init_state", "")

    stset: Set[str] = set(states)
    indeg = {s: 0 for s in stset}
    outdeg = {s: 0 for s in stset}
    for t in trans:
        fr = t.get("from"); to = t.get("to")
        if fr in stset: outdeg[fr] += 1
        if to in stset: indeg[to] += 1

    removed: List[str] = []
    keep: List[str] = []
    for s in states:
        if s == init_state:
            keep.append(s)
            continue
        if indeg.get(s, 0) == 0 and outdeg.get(s, 0) == 0:
            removed.append(s)
        else:
            keep.append(s)

    if not removed:
        return []

    keep_set = set(keep)
    ir["states"] = keep
    ir["transitions"] = [t for t in trans if t.get("from") in keep_set and t.get("to") in keep_set]
    if isinstance(outs, dict):
        for s in removed:
            outs.pop(s, None)
        ir["outputs"] = outs
    return removed
