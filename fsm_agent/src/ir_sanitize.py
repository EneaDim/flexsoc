from __future__ import annotations
from typing import Any, Dict, List, Set, Tuple

from .cond_parser import parse_condition, CondParseError, collect_idents

OUTS = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]

def enforce_entities(ir: Dict[str, Any], entities: Dict[str, Any]) -> None:
    """Hard gate: states/init must match entities. Never allow extra states."""
    sc = entities.get("state_candidates", [])
    initc = entities.get("init_state_candidate", "")
    if not isinstance(sc, list) or not all(isinstance(s, str) for s in sc):
        return
    ir["states"] = sc[:]
    if isinstance(initc, str) and initc in sc:
        ir["init_state"] = initc
    else:
        ir["init_state"] = sc[0] if sc else "IDLE"

def sanitize_transitions_inplace(ir: Dict[str, Any], entities: Dict[str, Any]) -> List[str]:
    """
    Keep only valid transitions:
    - from/to must be in states
    - no self-loop
    - cond must parse with allowed DSL
    - cond must use only *_i signals present in entities.signals_in OR "1"
    - forbid reset_i in guards
    - forbid any *_o in guards
    Returns warnings (strings) describing what was dropped.
    """
    warns: List[str] = []
    states: List[str] = ir.get("states", [])
    st: Set[str] = set(states)

    sigs = entities.get("signals_in", [])
    if not isinstance(sigs, list):
        sigs = []
    sigset = set([s for s in sigs if isinstance(s, str)])

    trans = ir.get("transitions", [])
    if not isinstance(trans, list):
        ir["transitions"] = []
        return warns

    kept: List[Dict[str, str]] = []
    for t in trans:
        if not isinstance(t, dict):
            continue
        fr, to, cond = t.get("from"), t.get("to"), t.get("cond")
        if not (isinstance(fr, str) and isinstance(to, str) and isinstance(cond, str)):
            warns.append("Dropped malformed transition (non-string fields).")
            continue
        c = cond.strip()
        if not c:
            warns.append(f"Dropped empty cond: {fr}->{to}")
            continue
        if fr not in st or to not in st:
            warns.append(f"Dropped transition with out-of-set state: {fr}->{to}")
            continue
        if fr == to:
            warns.append(f"Dropped self-loop: {fr}->{to}")
            continue
        try:
            ast = parse_condition(c)
        except CondParseError as ex:
            warns.append(f"Dropped unparsable cond on {fr}->{to}: {c!r}")
            continue
        ids = set(collect_idents(ast))
        if "reset_i" in ids:
            warns.append(f"Dropped guard using reset_i: {fr}->{to}")
            continue
        if any(x.endswith("_o") for x in ids):
            warns.append(f"Dropped guard using *_o: {fr}->{to}")
            continue
        # allow "1" (no idents), otherwise all idents must be declared input signals
        if any((x not in sigset) for x in ids):
            warns.append(f"Dropped guard using unknown signal(s) {sorted([x for x in ids if x not in sigset])}: {fr}->{to}")
            continue

        kept.append({"from": fr, "to": to, "cond": c})

    ir["transitions"] = kept
    return warns

def sanitize_outputs_inplace(ir: Dict[str, Any]) -> None:
    """Make outputs total and well-typed; never crash if LLM returns junk."""
    ir["outputs_header"] = OUTS
    states: List[str] = ir.get("states", [])
    outs = ir.get("outputs", {})
    if not isinstance(outs, dict):
        outs = {}
    for s in states:
        row = outs.get(s, None)
        if not isinstance(row, dict):
            row = {k: 0 for k in OUTS}
        fixed = {}
        for k in OUTS:
            v = row.get(k, 0)
            fixed[k] = 1 if v == 1 else 0
        outs[s] = fixed
    ir["outputs"] = outs

def ensure_reset_arc(ir: Dict[str, Any]) -> None:
    """If RESET exists, ensure one RESET->init '1' (only if init != RESET)."""
    states: List[str] = ir.get("states", [])
    st = set(states)
    init_state = ir.get("init_state", "")
    if "RESET" in st and isinstance(init_state, str) and init_state in st and init_state != "RESET":
        # avoid duplicate
        for t in ir.get("transitions", []):
            if t.get("from") == "RESET" and t.get("to") == init_state and (t.get("cond") or "").strip() == "1":
                return
        ir.setdefault("transitions", []).insert(0, {"from": "RESET", "to": init_state, "cond": "1"})
