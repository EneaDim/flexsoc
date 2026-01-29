from __future__ import annotations
from typing import Any, Dict, List
import os

def render_transitions_txt(fsm: Dict[str, Any]) -> str:
    lines: List[str] = []
    for t in fsm.get("transitions", []):
        lines.append(f'{t["from"]} -> {t["to"]} : "{t["cond"]}";')
    return "\n".join(lines) + ("\n" if lines else "")

def render_outputs_csv(fsm: Dict[str, Any]) -> str:
    hdr_all = list(fsm.get("outputs_header", []))
    outputs = fsm.get("outputs", {})
    states = list(fsm.get("states", []))

    hdr = hdr_all
    if os.environ.get("FSM_PRUNE_CONST_OUTPUTS", "0") == "1" and states:
        keep: List[str] = []
        for k in hdr_all:
            vals = [int(outputs.get(s, {}).get(k, 0)) for s in states]
            if any(v != vals[0] for v in vals):
                keep.append(k)
        hdr = keep

    cols = ["StateName"] + hdr
    out = [",".join(cols)]
    for st in states:
        row = outputs.get(st, {})
        out.append(",".join([st] + [str(int(row.get(k, 0))) for k in hdr]))
    return "\n".join(out) + "\n"
