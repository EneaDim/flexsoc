from __future__ import annotations
from typing import Any, Dict, List, Set
import re
from .cond_parser import parse_condition, CondParseError, collect_idents

OUTS = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]
STATE_RE = re.compile(r"^[A-Z][A-Z0-9_]*$")

RE_FORBIDDEN = re.compile(r"(\band\b|\bor\b|\bnot\b|==|=|~|&&|\|\||'|\")", re.IGNORECASE)

def _is_standalone_negation(cond: str) -> bool:
    c = cond.strip()
    return c.startswith("!") and ("&" not in c) and ("|" not in c) and ("(" not in c) and (")" not in c) and len(c) > 1

def validate_ir(ir: Dict[str, Any]) -> List[str]:
    e: List[str] = []
    for k in ["init_state","states","transitions","outputs_header","outputs","priorities","assumptions"]:
        if k not in ir:
            e.append(f"missing key: {k}")
    if e: return e

    if ir["outputs_header"] != OUTS:
        e.append(f"outputs_header must be exactly {OUTS}")

    states = ir.get("states", [])
    if not isinstance(states, list) or not all(isinstance(s,str) and s for s in states):
        e.append("states must be array of non-empty strings")
        return e

    for s in states:
        if s.endswith("_i") or s.endswith("_o"):
            e.append(f"invalid state name (looks like signal): '{s}'")
        if not STATE_RE.match(s):
            e.append(f"invalid state name (must be UPPERCASE like WAIT_CMD): '{s}'")

    st: Set[str] = set(states)

    init_state = ir.get("init_state","")
    if not isinstance(init_state,str) or not init_state or init_state not in st:
        e.append("init_state must be a state in states")

    trans = ir.get("transitions", [])
    if not isinstance(trans, list) or not trans:
        e.append("transitions must be non-empty list")
        return e

    for i,t in enumerate(trans):
        for k in ["from","to","cond"]:
            if k not in t:
                e.append(f"transition[{i}] missing '{k}'")
        fr, to, cond = t.get("from"), t.get("to"), t.get("cond")

        if fr == to:
            e.append(f"forbidden self-loop: {fr}->{to}")
        if fr not in st: e.append(f"transition[{i}] unknown from-state '{fr}'")
        if to not in st: e.append(f"transition[{i}] unknown to-state '{to}'")

        c = str(cond).strip()
        if not c:
            e.append(f"transition[{i}] empty condition")
            continue

        if RE_FORBIDDEN.search(c):
            e.append(f"forbidden token in condition: {fr}->{to} : {c!r}")
        if _is_standalone_negation(c):
            e.append(f"forbidden standalone negation condition: {fr}->{to} : {c!r}")

        try:
            ast = parse_condition(c)
        except CondParseError as ex:
            e.append(str(ex))
            continue

        ids = set(collect_idents(ast))
        if "reset_i" in ids:
            e.append(f"reset_i is forbidden in conditions: {fr}->{to}")
        if any(x.endswith("_o") for x in ids):
            e.append(f"outputs are forbidden in conditions: {fr}->{to} uses {sorted([x for x in ids if x.endswith('_o')])}")

    outs = ir.get("outputs", {})
    if not isinstance(outs, dict):
        e.append("outputs must be dict")
        return e

    for s in states:
        if s not in outs:
            e.append(f"outputs missing for state '{s}'")
            continue
        row = outs[s]
        if not isinstance(row, dict):
            e.append(f"outputs[{s}] must be an object/dict, got {type(row).__name__}")
            continue
        for k in OUTS:
            v = row.get(k, None)
            if v not in (0,1):
                e.append(f"outputs[{s}][{k}] must be 0/1")

    pr = ir.get("priorities", [])
    if not isinstance(pr, list):
        e.append("priorities must be list")

    return e
