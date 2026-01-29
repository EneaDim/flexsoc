from __future__ import annotations
from typing import Any, Dict, List

OUTPUT_KEYS = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]

def _coerce_outputs(outputs: Any) -> Any:
    # outputs deve essere dict: state -> dict(outputs)
    if not isinstance(outputs, dict):
        return outputs

    new_out: Dict[str, Any] = {}
    for st, v in outputs.items():
        # caso sbagliato: lista [b,v,e,lp,d]
        if isinstance(v, list) and len(v) == 5:
            new_out[st] = {k: int(v[i]) for i, k in enumerate(OUTPUT_KEYS)}
        # caso corretto: dict
        elif isinstance(v, dict):
            # assicurati che tutte le chiavi esistano (default 0 se mancanti)
            new_out[st] = {k: int(v.get(k, 0)) for k in OUTPUT_KEYS}
        else:
            new_out[st] = v
    return new_out

def _coerce_assumptions(assumptions: Any) -> Any:
    # assumptions deve essere list[str]
    if not isinstance(assumptions, list):
        return assumptions
    out: List[str] = []
    for a in assumptions:
        if isinstance(a, str):
            out.append(a)
        elif isinstance(a, dict):
            # caso comune: {"name": "...", "value": ...}
            name = a.get("name", "assumption")
            val = a.get("value", a)
            out.append(f"{name}={val}")
        else:
            out.append(str(a))
    return out

def coerce_fsm_json(j: Dict[str, Any]) -> Dict[str, Any]:
    if not isinstance(j, dict):
        return j
    j2 = dict(j)

    if "outputs" in j2:
        j2["outputs"] = _coerce_outputs(j2["outputs"])

    if "assumptions" in j2:
        j2["assumptions"] = _coerce_assumptions(j2["assumptions"])

    return j2
