from __future__ import annotations
from typing import Any, Dict, List, Set, Tuple

OUTS = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]

def sanitize_intent_types(x: Any) -> Dict[str, Any]:
    if not isinstance(x, dict):
        return {}
    if not isinstance(x.get("states"), list):
        x["states"] = []
    if not isinstance(x.get("edges"), list):
        x["edges"] = []
    if not isinstance(x.get("assumptions"), list):
        x["assumptions"] = []
    if not isinstance(x.get("priorities"), list):
        x["priorities"] = []
    if not isinstance(x.get("outputs"), dict):
        x["outputs"] = {}
    if not isinstance(x.get("init_state"), str):
        x["init_state"] = ""
    x["outputs_header"] = OUTS
    return x

def enforce_entities_on_intent(intent: Dict[str, Any], entities: Dict[str, Any]) -> None:
    sc = entities.get("state_candidates", [])
    initc = entities.get("init_state_candidate", "")
    if not isinstance(sc, list) or not all(isinstance(s, str) for s in sc):
        return
    intent["states"] = sc[:]
    if isinstance(initc, str) and initc in sc:
        intent["init_state"] = initc
    else:
        intent["init_state"] = sc[0] if sc else "IDLE"
    intent["outputs_header"] = OUTS

def validate_intent(intent: Dict[str, Any], entities: Dict[str, Any]) -> List[str]:
    errs: List[str] = []
    states = intent.get("states", [])
    init_state = intent.get("init_state", "")
    if not isinstance(states, list) or not states:
        errs.append("states must be non-empty list")
        return errs
    if not isinstance(init_state, str) or init_state not in states:
        errs.append("init_state must be one of states")
    sigs = entities.get("signals_in", [])
    if not isinstance(sigs, list):
        sigs = []
    sigset = set([s for s in sigs if isinstance(s, str)])

    edges = intent.get("edges", [])
    if not isinstance(edges, list):
        errs.append("edges must be list")
        return errs

    for i,e in enumerate(edges):
        if not isinstance(e, dict):
            errs.append(f"edge[{i}] must be object")
            continue
        fr, to, when = e.get("from"), e.get("to"), e.get("when")
        if not (isinstance(fr, str) and isinstance(to, str) and isinstance(when, str)):
            errs.append(f"edge[{i}] fields must be strings")
            continue
        if fr not in states or to not in states:
            errs.append(f"edge[{i}] uses unknown state {fr}->{to}")
        if fr == to:
            errs.append(f"forbidden self-loop: {fr}->{to}")
        w = when.strip()
        if w != "1" and w not in sigset:
            errs.append(f"edge[{i}] when must be '1' or one of signals_in: got {w!r}")
        if any(ch.isspace() for ch in w) or any(op in w for op in ["&","|","!","(",")"]):
            errs.append(f"edge[{i}] when must be atomic (no operators/spaces): got {w!r}")

    # outputs sanity
    outs = intent.get("outputs", {})
    if not isinstance(outs, dict):
        errs.append("outputs must be dict")
    else:
        for s in states:
            row = outs.get(s, None)
            if row is None:
                continue
            if not isinstance(row, dict):
                errs.append(f"outputs[{s}] must be dict")
                continue
            for k in OUTS:
                v = row.get(k, 0)
                if v not in (0,1):
                    errs.append(f"outputs[{s}][{k}] must be 0/1")

    return errs

def default_outputs(states: List[str]) -> Dict[str, Dict[str,int]]:
    o: Dict[str, Dict[str,int]] = {}
    for s in states:
        row = {k: 0 for k in OUTS}
        if s == "RUNNING":
            row["busy_o"] = 1
        if s == "ERROR":
            row["error_o"] = 1
        if s == "LOW_POWER":
            row["low_power_o"] = 1
        o[s] = row
    return o

def ensure_nonempty_edges(intent: Dict[str, Any]) -> None:
    edges = intent.get("edges", [])
    states = intent.get("states", [])
    init_state = intent.get("init_state", "")
    if not isinstance(edges, list) or len(edges) > 0:
        return
    if not isinstance(states, list) or len(states) < 2:
        return
    # minimal 2-edge ping-pong using "1"
    s0 = init_state if init_state in states else states[0]
    s1 = next(s for s in states if s != s0)
    intent["edges"] = [{"from": s0, "to": s1, "when": "1"}, {"from": s1, "to": s0, "when": "1"}]
    intent.setdefault("assumptions", [])
    intent["assumptions"].append("No usable edges produced; added minimal unconditional ping-pong edges for non-emptiness.")

def ensure_graph_closure_edges(intent: Dict[str, Any]) -> None:
    states: List[str] = intent.get("states", [])
    edges: List[Dict[str,str]] = intent.get("edges", [])
    init_state: str = intent.get("init_state", "")
    if not states or not edges:
        return
    st = set(states)
    indeg = {s: 0 for s in st}
    outdeg = {s: 0 for s in st}
    for e in edges:
        fr = e.get("from"); to = e.get("to")
        if fr in st: outdeg[fr] += 1
        if to in st: indeg[to] += 1

    def add_edge(fr: str, to: str, why: str) -> None:
        if fr == to:
            return
        edges.append({"from": fr, "to": to, "when": "1"})
        intent.setdefault("assumptions", [])
        intent["assumptions"].append(why)

    # Outgoing closure
    for s in states:
        if outdeg.get(s, 0) == 0:
            tgt = init_state if init_state in st and init_state != s else next((x for x in states if x != s), None)
            if tgt:
                add_edge(s, tgt, f"Added closure edge {s}->{tgt}:'1' to ensure out-degree>=1.")

    # Recompute indeg/outdeg
    indeg = {s: 0 for s in st}
    outdeg = {s: 0 for s in st}
    for e in edges:
        fr = e.get("from"); to = e.get("to")
        if fr in st: outdeg[fr] += 1
        if to in st: indeg[to] += 1

    # Incoming closure
    for s in states:
        if indeg.get(s, 0) == 0:
            src = init_state if init_state in st and init_state != s else next((x for x in states if x != s), None)
            if src:
                add_edge(src, s, f"Added closure edge {src}->{s}:'1' to ensure in-degree>=1.")

def intent_to_ir(intent: Dict[str, Any]) -> Dict[str, Any]:
    states = intent.get("states", [])
    init_state = intent.get("init_state", "")
    edges = intent.get("edges", [])
    outputs = intent.get("outputs", {})
    priorities = intent.get("priorities", [])
    assumptions = intent.get("assumptions", [])

    if not isinstance(outputs, dict) or not outputs:
        outputs = default_outputs(states)

    transitions = [{"from": e["from"], "to": e["to"], "cond": e["when"]} for e in edges if isinstance(e, dict)]

    ir = {
        "init_state": init_state,
        "states": states,
        "transitions": transitions,
        "outputs_header": OUTS,
        "outputs": outputs,
        "priorities": priorities if isinstance(priorities, list) else [],
        "assumptions": assumptions if isinstance(assumptions, list) else [],
    }
    return ir
