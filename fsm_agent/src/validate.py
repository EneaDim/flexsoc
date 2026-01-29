from __future__ import annotations
from typing import Any, Dict, List, Set
import re
from .cond_parser import parse_condition, CondParseError, collect_idents

OUTS = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]
STATE_RE = re.compile(r"^[A-Z][A-Z0-9_]*$")

def validate_fsm(fsm: Dict[str, Any]) -> List[str]:
    e: List[str] = []
    for k in ["states","transitions","outputs_header","outputs","assumptions"]:
        if k not in fsm:
            e.append(f"missing key: {k}")
    if e: return e

    if fsm["outputs_header"] != OUTS:
        e.append(f"outputs_header must be exactly {OUTS}")

    states = fsm.get("states", [])
    if not isinstance(states, list) or not all(isinstance(s,str) and s for s in states):
        e.append("states must be array of non-empty strings")
        return e

    for s in states:
        if s.endswith("_i") or s.endswith("_o"):
            e.append(f"invalid state name (looks like signal): '{s}'")
        if not STATE_RE.match(s):
            e.append(f"invalid state name (must be UPPERCASE like WAIT_CMD): '{s}'")

    st: Set[str] = set(states)

    trans = fsm.get("transitions", [])
    if not isinstance(trans, list) or not trans:
        e.append("transitions must be non-empty list")
        return e

    indeg = {s:0 for s in st}
    outdeg = {s:0 for s in st}

    for i,t in enumerate(trans):
        fr, to, cond = t.get("from"), t.get("to"), t.get("cond")
        if fr == to:
            e.append(f"forbidden self-loop: {fr}->{to}")
        if fr not in st: e.append(f"transition[{i}] unknown from-state '{fr}'")
        else: outdeg[fr]+=1
        if to not in st: e.append(f"transition[{i}] unknown to-state '{to}'")
        else: indeg[to]+=1

        c = str(cond).strip()
        try:
            ast = parse_condition(c)
        except CondParseError as ex:
            e.append(str(ex))
            continue

        ids = set(collect_idents(ast))
        if "reset_i" in ids:
            e.append(f"reset_i is forbidden in conditions: {fr}->{to}")

    for s in st:
        if indeg[s]==0: e.append(f"graph not closed: state '{s}' has in-degree=0")
        if outdeg[s]==0: e.append(f"graph not closed: state '{s}' has out-degree=0")

    # error_i rule (local)
    ERROR_SIG="error_i"; ERROR_STATE="ERROR"
    by_from: Dict[str, List[Dict[str, Any]]] = {}
    for t in trans:
        by_from.setdefault(t.get("from",""), []).append(t)
    has_err_edge = {s:any((o.get("to")==ERROR_STATE and (o.get("cond") or "").strip()==ERROR_SIG) for o in outs)
                    for s,outs in by_from.items()}

    for t in trans:
        fr, to, cond = t.get("from"), t.get("to"), (t.get("cond") or "").strip()
        try:
            ids = set(collect_idents(parse_condition(cond)))
        except Exception:
            ids = set()
        if ERROR_SIG in ids and to != ERROR_STATE:
            if ("!error_i" in cond) and has_err_edge.get(fr, False) and cond != ERROR_SIG:
                continue
            e.append(f"error_i can only drive transitions to ERROR: found {fr}->{to}")
        if cond == "!error_i" and not has_err_edge.get(fr, False):
            e.append(f"suspicious '!error_i' used as global filter in {fr}->{to}: '!error_i'")

    return e
