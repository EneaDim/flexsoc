from __future__ import annotations
from typing import Any, Dict, List, Set, Tuple
from .cond_parser import parse_condition, collect_idents

OUTS = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]

def _idents(cond: str) -> Set[str]:
    try:
        return set(collect_idents(parse_condition(cond)))
    except Exception:
        return set()

def sanitize_ir_inplace(ir: Dict[str, Any]) -> None:
    """
    Deterministic cleanup:
    - Fix init_state if not in states.
    - Drop self-loops.
    - Drop transitions whose condition uses reset_i or any *_o signal.
    """
    states: List[str] = [s for s in ir.get("states", []) if isinstance(s, str)]
    ir["states"] = states
    stset = set(states)

    init_state = ir.get("init_state", "")
    if not isinstance(init_state, str) or init_state not in stset:
        if "IDLE" in stset:
            ir["init_state"] = "IDLE"
        else:
            non_reset = [s for s in states if s != "RESET"]
            ir["init_state"] = (non_reset[0] if non_reset else (states[0] if states else "IDLE"))
        ir.setdefault("assumptions", []).append("init_state non valido: assegnato automaticamente a uno stato esistente.")

    trans_in: List[Dict[str, Any]] = ir.get("transitions", [])
    trans_out: List[Dict[str, Any]] = []
    for t in trans_in:
        if not isinstance(t, dict):
            continue
        fr, to, cond = t.get("from"), t.get("to"), t.get("cond")
        if not (isinstance(fr, str) and isinstance(to, str) and isinstance(cond, str)):
            continue
        if fr not in stset or to not in stset:
            continue
        c = cond.strip()
        if not c:
            continue

        if fr == to:
            ir.setdefault("assumptions", []).append(f"Rimossa self-loop {fr}->{to} (stay implicito).")
            continue

        ids = _idents(c)
        if "reset_i" in ids:
            ir.setdefault("assumptions", []).append(f"Rimossa transizione {fr}->{to}: reset_i vietato nelle condizioni.")
            continue
        if any(x.endswith("_o") for x in ids):
            ir.setdefault("assumptions", []).append(f"Rimossa transizione {fr}->{to}: output *_o vietati nelle condizioni.")
            continue

        trans_out.append({"from": fr, "to": to, "cond": c})

    ir["transitions"] = trans_out

def repair_common_llm_mistakes(ir: Dict[str, Any]) -> None:
    """
    Fix common small-LLM mistake:
      RESET->READY:"1"; READY->RUNNING:"start_i"; RUNNING->ERROR:"error_i"; DONE->READY:"done_i";
    Where DONE is erroneously used as a state instead of a condition out of RUNNING.
    Rule:
      If there is a transition FROM "DONE" with cond == "done_i",
      and state "RUNNING" exists, rewrite it to RUNNING-><to> with same cond.
      Then remove state DONE if it becomes isolated.
    """
    states: List[str] = [s for s in ir.get("states", []) if isinstance(s, str)]
    stset = set(states)
    trans: List[Dict[str, Any]] = ir.get("transitions", [])

    if "DONE" not in stset:
        return
    if "RUNNING" not in stset:
        return

    rewrote = False
    new_trans: List[Dict[str, Any]] = []
    for t in trans:
        fr = t.get("from"); to = t.get("to"); cond = (t.get("cond") or "").strip()
        if fr == "DONE" and cond == "done_i":
            new_trans.append({"from": "RUNNING", "to": to, "cond": "done_i"})
            rewrote = True
        else:
            new_trans.append(t)

    if rewrote:
        ir["transitions"] = new_trans
        ir.setdefault("assumptions", []).append("Corretto errore LLM: stato DONE spurio; riscritta transizione come RUNNING -> READY : done_i.")

def prune_unreachable_and_dangling_states(ir: Dict[str, Any]) -> None:
    """
    Remove states that are completely disconnected (no in and no out) after repairs/sanitization.
    This prevents 'graph not closed' due to hallucinated states like DONE.
    """
    states: List[str] = [s for s in ir.get("states", []) if isinstance(s, str)]
    trans: List[Dict[str, Any]] = ir.get("transitions", [])
    outs: Dict[str, Dict[str,int]] = ir.get("outputs", {})
    stset: Set[str] = set(states)

    indeg = {s:0 for s in stset}
    outdeg = {s:0 for s in stset}
    for t in trans:
        fr = t.get("from"); to = t.get("to")
        if fr in stset: outdeg[fr] += 1
        if to in stset: indeg[to] += 1

    keep = [s for s in states if (indeg.get(s,0) > 0 or outdeg.get(s,0) > 0)]
    removed = [s for s in states if s not in keep]

    if removed:
        ir.setdefault("assumptions", []).append(f"Rimossi stati disconnessi: {removed}")
        ir["states"] = keep
        for s in removed:
            outs.pop(s, None)

        # Drop transitions referencing removed states
        keep_set = set(keep)
        ir["transitions"] = [t for t in trans if t.get("from") in keep_set and t.get("to") in keep_set]

def apply_priority_rules(ir: Dict[str, Any]) -> None:
    trans = ir.get("transitions", [])
    for p in ir.get("priorities", []):
        st = p.get("state","")
        high = (p.get("high_cond") or "").strip()
        low  = (p.get("low_cond")  or "").strip()
        if not st or not high or not low:
            continue
        highs = sorted(_idents(high))
        if not highs:
            continue
        neg = " & ".join([f"!{h}" for h in highs])
        for t in trans:
            if t.get("from") == st and (t.get("cond") or "").strip() == low:
                c = (t.get("cond") or "").strip()
                t["cond"] = neg if c == "1" else f"({c}) & ({neg})"

def auto_error_priority(ir: Dict[str, Any], *, error_sig: str = "error_i", error_state: str = "ERROR") -> None:
    trans = ir.get("transitions", [])
    by_from: Dict[str, List[Dict[str, Any]]] = {}
    for t in trans:
        fr = t.get("from","")
        if isinstance(fr, str):
            by_from.setdefault(fr, []).append(t)

    for st, outs in by_from.items():
        has_err = any((o.get("to")==error_state and (o.get("cond") or "").strip()==error_sig) for o in outs)
        if not has_err:
            continue
        for t in outs:
            if t.get("to")==error_state:
                continue
            c = (t.get("cond") or "").strip()
            if error_sig in _idents(c):
                continue
            t["cond"] = f"!{error_sig}" if c == "1" else f"({c}) & (!{error_sig})"

def ensure_reset_and_closure(ir: Dict[str, Any]) -> None:
    states: List[str] = [s for s in ir.get("states", []) if isinstance(s, str)]
    ir["states"] = states
    trans: List[Dict[str, Any]] = ir.get("transitions", [])
    outs: Dict[str, Dict[str,int]] = ir.get("outputs", {})
    init_state: str = ir.get("init_state","")

    stset: Set[str] = set(states)

    def degs() -> Tuple[Dict[str,int], Dict[str,int]]:
        indeg = {s:0 for s in stset}
        outdeg = {s:0 for s in stset}
        for t in trans:
            fr, to = t.get("from"), t.get("to")
            if fr in stset: outdeg[fr]+=1
            if to in stset: indeg[to]+=1
        return indeg, outdeg

    indeg, outdeg = degs()
    if init_state in stset and indeg.get(init_state,0)==0:
        if "RESET" not in stset:
            states.insert(0,"RESET"); stset.add("RESET")
            outs.setdefault("RESET", {k:0 for k in OUTS})
        trans.insert(0, {"from":"RESET","to":init_state,"cond":"1"})
        ir.setdefault("assumptions", []).append("Aggiunto RESET -> init_state : 1 per chiudere in-degree dello stato iniziale.")
