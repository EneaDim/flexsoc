#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
app.py — General-purpose FSM generator for HW / Protocol / RTL specs (Ollama)

Goals (refactor):
- Fewer LLM calls: adaptive retries instead of fixed multi-sampling loops
- More structure: typed-ish dataclasses, single contract runner, caching
- Better prompts: one MASTER system prompt, compact JSON-first contracts
- Deterministic repair stays the "last word" for invariants/policies

Pipeline (compact):
  S1 Normalize spec (C01)
  S2 Extract entities (C02)
  S3 Canonical maps (C03) + deterministic enrich
  S4 State roles (C04)
  S5 Transitions synth (C05X) + deterministic repair + validate
       if invalid -> one patch (C06X) + repair + validate
       if still invalid -> one fallback regen (C05X hotter) + validate
  S6 Output tags synth (C09X) + deterministic sanitize/build
  S7 Trace generation (C11) + deterministic simulation
  S8 Final audit (C12)

Exports:
  inputs/<fsm>.txt        GraphViz-like "FROM -> TO : "event_i""
  inputs/<fsm>.csv        state output table 0/1
  inputs/<fsm>.report.json provenance, contracts, issues, scores, final
"""

import os
import re
import sys
import json
import csv
import time
import argparse
import hashlib
import urllib.request
import urllib.error
from dataclasses import dataclass, field
from typing import Any, Dict, List, Tuple, Set, Optional

# ---------------- CONFIG ----------------
EXPORT_DIR = "fsm_gen/inputs"
MODEL_GEN = "qwen2.5:3b-instruct"
MODEL_VER = "qwen2.5:3b-instruct"
OLLAMA_URL = "http://127.0.0.1:11434/api/generate"

# Suffixing policy
IN_SUFFIX = "_i"
OUT_SUFFIX = "_o"
DONE_CLEAR_BASE = "clear"
ERR_CLEAR_BASE = "clear_err"

# Adaptive controls (much lower than old)
MAX_PATCH_ONCE = 1     # patch attempt count (0/1)
ALLOW_FALLBACK_REGEN = True
TEMP_TRANSITIONS = 0.35
TEMP_TRANSITIONS_FALLBACK = 0.55
TEMP_TAGS = 0.25
TEMP_TRACES = 0.15

# JSON parsing
JSON_BLOCK = re.compile(r"<<<JSON\s*(\{.*?\})\s*JSON", re.S)

# Terminal detection
TERM_RE = re.compile(r"^(done|final|complete|end|finish)$", re.I)

# Forbidden event triggers
BAD_EVENTS = {"1", "true", "always", "default", ""}

# Heuristic detection
RX_RESET = re.compile(r"\b(reset|rst|nreset|nrst)\b", re.I)
RX_TIMEOUT = re.compile(r"\b(timeout|watchdog|wdt)\b", re.I)
RX_ERROR = re.compile(r"\b(error|errore|fault|fail|failure|exception)\b", re.I)

# Common mode patterns (very general)
MODE_PATTERNS = [
    (re.compile(r"\blow\s*power\b", re.I), "low_power"),
    (re.compile(r"\bsleep\b", re.I), "sleep"),
    (re.compile(r"\bstandby\b", re.I), "standby"),
    (re.compile(r"\bcharging\b", re.I), "charging"),
]

# ---------------- DEBUG ----------------
DEBUG = True

def dbg(msg: str) -> None:
    if DEBUG:
        print(f"[DBG] {msg}", flush=True)

def clip(s: str, n: int = 260) -> str:
    return s if len(s) <= n else s[:n] + " ..."

# ---------------- UTIL (naming) ----------------
def snake_token(s: str) -> str:
    s = (s or "").strip().lower()
    s = re.sub(r"[\s\-]+", "_", s)
    s = re.sub(r"[^a-z0-9_]", "", s)
    s = re.sub(r"_+", "_", s).strip("_")
    return s

def to_input_name(base: str) -> str:
    b = snake_token(base) or "event"
    return b if b.endswith(IN_SUFFIX) else (b + IN_SUFFIX)

def to_output_name(base: str) -> str:
    b = snake_token(base) or "out"
    return b if b.endswith(OUT_SUFFIX) else (b + OUT_SUFFIX)

# ---------------- OLLAMA + CACHE ----------------
_llm_cache: Dict[str, str] = {}

def ollama_raw(prompt: str, model: str, temperature: float, top_p: float = 0.9, timeout_s: int = 60) -> str:
    payload = {
        "model": model,
        "prompt": prompt,
        "stream": False,
        "options": {"temperature": temperature, "top_p": top_p},
    }
    data = json.dumps(payload).encode("utf-8")
    req = urllib.request.Request(
        OLLAMA_URL, data=data,
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    dbg(f"Ollama POST model={model} temp={temperature} bytes={len(data)}")
    t0 = time.time()
    try:
        with urllib.request.urlopen(req, timeout=timeout_s) as resp:
            body = resp.read().decode("utf-8", errors="replace")
    except urllib.error.URLError as e:
        raise RuntimeError(f"Ollama connection error: {e} (run: ollama serve)") from e
    dbg(f"Ollama OK {time.time()-t0:.2f}s chars={len(body)}")
    obj = json.loads(body)
    if not isinstance(obj.get("response"), str):
        raise RuntimeError("Ollama response missing 'response'")
    return obj["response"]

def cached_ollama(prompt: str, model: str, temperature: float, top_p: float = 0.9) -> str:
    h = hashlib.sha256((model + "|" + str(temperature) + "|" + str(top_p) + "|" + prompt).encode("utf-8")).hexdigest()
    if h in _llm_cache:
        dbg(f"Ollama cache hit {h[:10]}")
        return _llm_cache[h]
    resp = ollama_raw(prompt, model=model, temperature=temperature, top_p=top_p)
    _llm_cache[h] = resp
    return resp

# ---------------- JSON SALVAGE ----------------
def strip_code_fences(s: str) -> str:
    s = s.strip()
    if s.startswith("```"):
        s = re.sub(r"^```[a-zA-Z]*\s*", "", s)
        s = re.sub(r"\s*```$", "", s)
    return s.strip()

def salvage_json_text(js: str) -> str:
    js = strip_code_fences(js)
    js = js.replace("[...]", "[]")
    js = re.sub(r':\s*\.\.\.\s*([,\}])', r": null\1", js)
    return js

def parse_json_block(text: str) -> Dict[str, Any]:
    dbg("LLM head: " + clip(text.replace("\n", "\\n")))
    m = JSON_BLOCK.search(text)
    if m:
        js = m.group(1)
        dbg(f"JSON block found len={len(js)}")
    else:
        i, j = text.find("{"), text.rfind("}")
        if i < 0 or j < 0 or j <= i:
            raise ValueError("No JSON found in LLM output")
        js = text[i:j+1]
        dbg(f"JSON fallback slice len={len(js)}")
    js2 = salvage_json_text(js)
    if js2 != js:
        dbg("JSON salvage applied.")
    return json.loads(js2)

# ---------------- MASTER PROMPT ----------------
MASTER_SYSTEM = """You are a strict JSON generator for an HW/Protocol/RTL FSM toolchain.

Hard rules:
- Output ONLY one JSON object enclosed exactly like this:
  <<<JSON
  {...}
  JSON
- No markdown. No code fences. No commentary. No extra keys beyond the contract.
- Use valid JSON only (double quotes, no trailing commas, no NaN, no comments).
- Never use placeholders like "...", "[...]", "<...>".
- If information is missing, use empty arrays/objects or conservative defaults stated in the contract.
- Do not invent new states/events/tags unless the contract explicitly allows adding them.
- Respect provided allowed lists/enums EXACTLY.
"""

def mk_prompt(contract_id: str, user_body: str) -> str:
    return f"SYSTEM:\n{MASTER_SYSTEM}\n\nUSER:\nContract: {contract_id}\n\n{user_body}\n"

def run_contract(contract_id: str, user_body: str, model: str, temp: float, top_p: float = 0.9) -> Dict[str, Any]:
    prompt = mk_prompt(contract_id, user_body)
    raw = cached_ollama(prompt, model=model, temperature=temp, top_p=top_p)
    return parse_json_block(raw)

# ---------------- CANONICALIZERS ----------------
def uniq_upper_list(xs: Any, default: List[str]) -> List[str]:
    if not isinstance(xs, list):
        return default[:]
    out = [x.strip().upper() for x in xs if isinstance(x, str) and x.strip()]
    out = list(dict.fromkeys(out))
    return out or default[:]

def uniq_lower_list(xs: Any, default: List[str]) -> List[str]:
    if not isinstance(xs, list):
        return default[:]
    out = [snake_token(x) for x in xs if isinstance(x, str)]
    out = [x for x in out if x]
    out = list(dict.fromkeys(out))
    return out or default[:]

def infer_terminals(states: List[str], terms: List[str]) -> List[str]:
    norm = []
    for t in terms:
        if isinstance(t, str):
            norm.append(t.strip().upper())
    s = set(norm)
    for st in states:
        if TERM_RE.match(st.lower()):
            s.add(st)
    out = list(dict.fromkeys(list(s)))
    return out or ["DONE"]

# ---------------- MODE HELPERS ----------------
def detect_modes_from_text(spec: str) -> List[str]:
    found: List[str] = []
    for rx, mode in MODE_PATTERNS:
        if rx.search(spec):
            found.append(mode)
    return list(dict.fromkeys(found))

def mode_state_name(mode: str) -> str:
    return mode.upper()

def mode_enter_event(mode: str) -> str:
    return f"enter_{mode}"

def mode_exit_event(mode: str) -> str:
    if mode in ("sleep", "standby", "low_power"):
        return "wake"
    return f"exit_{mode}"

# ---------------- TRANSITIONS ----------------
Transition = Dict[str, str]  # {"from": "STATE", "to":"STATE", "on":"event_base"}

def canon_transitions(x: Any, states: List[str], events: List[str]) -> List[Transition]:
    stset = set(states)
    evset = set(events)
    out: List[Transition] = []
    if isinstance(x, list):
        for t in x:
            if not isinstance(t, dict):
                continue
            fr, to, on = t.get("from"), t.get("to"), t.get("on")
            if isinstance(fr, str) and isinstance(to, str) and isinstance(on, str):
                fru, tou = fr.strip().upper(), to.strip().upper()
                onb = snake_token(on)
                if fru in stset and tou in stset and onb in evset and onb not in BAD_EVENTS:
                    out.append({"from": fru, "to": tou, "on": onb})
    uniq = []
    seen = set()
    for t in out:
        key = (t["from"], t["to"], t["on"])
        if key not in seen:
            uniq.append(t)
            seen.add(key)
    return uniq

def degrees(states: List[str], trans: List[Transition]) -> Tuple[Dict[str, int], Dict[str, int]]:
    indeg = {s: 0 for s in states}
    outdeg = {s: 0 for s in states}
    for t in trans:
        outdeg[t["from"]] += 1
        indeg[t["to"]] += 1
    return indeg, outdeg

def add_if_missing(trans: List[Transition], fr: str, to: str, on: str, provenance: List[Dict[str, Any]], origin: str) -> None:
    onb = snake_token(on)
    for t in trans:
        if t["from"] == fr and t["to"] == to and t["on"] == onb:
            return
    trans.append({"from": fr, "to": to, "on": onb})
    provenance.append({"op": "add_transition", "from": fr, "to": to, "on": onb, "origin": origin})
    dbg(f"repair add {fr}->{to} on {onb} ({origin})")

# ---------------- OUTPUT TAGS ----------------
def sanitize_state_tags(tags: Dict[str, List[str]], states: List[str]) -> Dict[str, List[str]]:
    out: Dict[str, List[str]] = {}
    for st in states:
        arr = tags.get(st, [])
        if not isinstance(arr, list):
            arr = []
        cleaned = [snake_token(x) for x in arr if isinstance(x, str)]
        cleaned = [x for x in cleaned if x]
        out[st] = list(dict.fromkeys(cleaned))
    return out

def remove_state_name_outputs(outputs: List[str], states: List[str], protected: Set[str]) -> List[str]:
    st_tokens = {snake_token(s) for s in states}
    out = []
    for o in outputs:
        if o in protected:
            out.append(o)
        elif o not in st_tokens:
            out.append(o)
    return list(dict.fromkeys(out))

def build_outputs_from_tags(states: List[str],
                            tags: Dict[str, List[str]],
                            extra_outputs: List[str],
                            mode_tags: Dict[str, str],
                            mode_states: Dict[str, str],
                            state_roles: Dict[str, List[str]]) -> Tuple[List[str], Dict[str, Dict[str, int]]]:
    protected = {snake_token(v) for v in mode_tags.values() if v}

    out_set: Set[str] = set()
    for st in states:
        for t in tags.get(st, []):
            out_set.add(t)
    for o in extra_outputs:
        if o:
            out_set.add(o)

    for _, tag in mode_tags.items():
        t = snake_token(tag)
        if t:
            out_set.add(t)

    # Backstops (RTL-friendly)
    if "WORKING" in states and not tags.get("WORKING"):
        tags["WORKING"] = tags.get("WORKING", []) + ["busy"]
        out_set.add("busy")
    if "DONE" in states and "done" not in tags.get("DONE", []):
        tags["DONE"] = tags.get("DONE", []) + ["done"]
        out_set.add("done")
    if "ERROR" in states and "error" not in tags.get("ERROR", []):
        tags["ERROR"] = tags.get("ERROR", []) + ["error"]
        out_set.add("error")
    if "IDLE" in states and not tags.get("IDLE"):
        tags["IDLE"] = tags.get("IDLE", []) + ["idle"]
        out_set.add("idle")

    # Role-based hardening
    for st, roles in state_roles.items():
        rset = set(roles or [])
        if "fault" in rset and "error" not in tags.get(st, []):
            tags[st] = tags.get(st, []) + ["error"]
            out_set.add("error")
        if "terminal" in rset and "done" not in tags.get(st, []):
            tags[st] = tags.get(st, []) + ["done"]
            out_set.add("done")
        if "safe" in rset and st == "IDLE" and "idle" not in tags.get(st, []):
            tags[st] = tags.get(st, []) + ["idle"]
            out_set.add("idle")

    outputs = sorted(out_set)
    outputs = remove_state_name_outputs(outputs, states, protected)
    outputs = list(dict.fromkeys([snake_token(x) for x in outputs if snake_token(x)]))

    so: Dict[str, Dict[str, int]] = {}
    for st in states:
        tset = set(tags.get(st, []))

        for mode, stname in mode_states.items():
            if st == stname:
                t = snake_token(mode_tags.get(mode, mode))
                if t:
                    tset.add(t)

        so[st] = {o: (1 if o in tset else 0) for o in outputs}

    return outputs, so

# ---------------- APPLY SUFFIXING ----------------
def apply_suffixing(events: List[str],
                    trans: List[Transition],
                    outputs_base: List[str],
                    so_base: Dict[str, Dict[str, int]]) -> Tuple[List[str], List[Dict[str, str]], List[str], Dict[str, Dict[str, int]]]:
    dbg("Applying deterministic suffixing (_i/_o)...")
    inputs_i = list(dict.fromkeys([to_input_name(e) for e in events]))

    trans_i: List[Dict[str, str]] = []
    for t in trans:
        onb = snake_token(t["on"])
        if onb in BAD_EVENTS or not onb:
            onb = "event"
        trans_i.append({"from": t["from"], "to": t["to"], "on": to_input_name(onb)})

    outputs_o = list(dict.fromkeys([to_output_name(o) for o in outputs_base]))

    so_o: Dict[str, Dict[str, int]] = {}
    for st, m in so_base.items():
        so_o[st] = {}
        for o in outputs_base:
            so_o[st][to_output_name(o)] = 1 if m.get(o, 0) == 1 else 0
        for o in outputs_o:
            if so_o[st].get(o) not in (0, 1):
                so_o[st][o] = 0

    return inputs_i, trans_i, outputs_o, so_o

# ---------------- DETERMINISTIC INVARIANTS + REPAIR ----------------
def ensure_core_entities(spec: str, states: List[str], events: List[str], terminals: List[str], provenance: List[Dict[str, Any]]) -> None:
    for core in ("IDLE", "WORKING", "DONE"):
        if core not in states:
            states.append(core)
            provenance.append({"op": "add_state", "state": core, "origin": "repair_core"})
    for ev in ("start", "done", DONE_CLEAR_BASE):
        if ev not in events:
            events.append(ev)
            provenance.append({"op": "add_event", "event": ev, "origin": "repair_core"})

    if RX_RESET.search(spec) and "reset" not in events:
        events.append("reset")
        provenance.append({"op": "add_event", "event": "reset", "origin": "repair_infer"})
    if RX_TIMEOUT.search(spec) and "timeout" not in events:
        events.append("timeout")
        provenance.append({"op": "add_event", "event": "timeout", "origin": "repair_infer"})
    if RX_ERROR.search(spec):
        if "ERROR" not in states:
            states.append("ERROR")
            provenance.append({"op": "add_state", "state": "ERROR", "origin": "repair_infer"})
        if "error" not in events:
            events.append("error")
            provenance.append({"op": "add_event", "event": "error", "origin": "repair_infer"})
        if ERR_CLEAR_BASE not in events:
            events.append(ERR_CLEAR_BASE)
            provenance.append({"op": "add_event", "event": ERR_CLEAR_BASE, "origin": "repair_infer"})

    if "DONE" in states and DONE_CLEAR_BASE not in events:
        events.append(DONE_CLEAR_BASE)
        provenance.append({"op": "add_event", "event": DONE_CLEAR_BASE, "origin": "repair_core"})
    if "ERROR" in states and ERR_CLEAR_BASE not in events:
        events.append(ERR_CLEAR_BASE)
        provenance.append({"op": "add_event", "event": ERR_CLEAR_BASE, "origin": "repair_core"})

    terminals[:] = infer_terminals(states, terminals)

def ensure_mode_entities(spec: str, states: List[str], events: List[str], modes: List[str],
                         mode_states: Dict[str, str], mode_tags: Dict[str, str], provenance: List[Dict[str, Any]]) -> None:
    for m in detect_modes_from_text(spec):
        if m not in modes:
            modes.append(m)
            provenance.append({"op": "add_mode", "mode": m, "origin": "repair_infer"})

    for m in modes:
        st = (mode_states.get(m) or mode_state_name(m)).strip().upper()
        mode_states[m] = st
        mode_tags[m] = snake_token(mode_tags.get(m, m) or m) or m

        if st not in states:
            states.append(st)
            provenance.append({"op": "add_state", "state": st, "origin": "repair_mode", "mode": m})

        ent = mode_enter_event(m)
        ext = mode_exit_event(m)
        if ent not in events:
            events.append(ent)
            provenance.append({"op": "add_event", "event": ent, "origin": "repair_mode", "mode": m})
        if ext not in events:
            events.append(ext)
            provenance.append({"op": "add_event", "event": ext, "origin": "repair_mode", "mode": m})

def deterministic_repair_transitions(states: List[str], events: List[str], terminals: List[str],
                                    trans: List[Transition], provenance: List[Dict[str, Any]]) -> None:
    if "start" in events:
        add_if_missing(trans, "IDLE", "WORKING", "start", provenance, "repair_edges")
    if "done" in events:
        add_if_missing(trans, "WORKING", "DONE", "done", provenance, "repair_edges")

    if "ERROR" in states and "error" in events:
        add_if_missing(trans, "WORKING", "ERROR", "error", provenance, "repair_edges")

    if "DONE" in states and "clear" in events:
        add_if_missing(trans, "DONE", "IDLE", "clear", provenance, "repair_edges")
    if "ERROR" in states and "clear_err" in events:
        add_if_missing(trans, "ERROR", "IDLE", "clear_err", provenance, "repair_edges")

    if "reset" in events:
        for st in states:
            if st == "IDLE":
                continue
            add_if_missing(trans, st, "IDLE", "reset", provenance, "repair_reset")

    indeg, outdeg = degrees(states, trans)
    fallback_on = "clear" if "clear" in events else ("reset" if "reset" in events else "start")

    for st in list(states):
        if outdeg.get(st, 0) >= 1:
            continue
        if st == "DONE" and "clear" in events:
            add_if_missing(trans, "DONE", "IDLE", "clear", provenance, "repair_deg")
        elif st == "ERROR" and "clear_err" in events:
            add_if_missing(trans, "ERROR", "IDLE", "clear_err", provenance, "repair_deg")
        elif st != "IDLE":
            add_if_missing(trans, st, "IDLE", fallback_on, provenance, "repair_deg")
        else:
            on = "start" if "start" in events else fallback_on
            add_if_missing(trans, "IDLE", "WORKING" if "WORKING" in states else states[0], on, provenance, "repair_deg")

    indeg, _ = degrees(states, trans)
    for st in list(states):
        if indeg.get(st, 0) >= 1:
            continue
        if st == "IDLE":
            cand = [x for x in states if x != "IDLE"]
            if cand:
                add_if_missing(trans, cand[0], "IDLE", fallback_on, provenance, "repair_deg")
        else:
            on = "start" if "start" in events else ("reset" if "reset" in events else fallback_on)
            add_if_missing(trans, "IDLE", st, on, provenance, "repair_deg")
    # Ensure every event is used at least once (avoid validate() failure)
    used = set(t["on"] for t in trans)
    for ev in events:
        if ev in used:
            continue
        # Choose a safe default source state
        src = "WORKING" if "WORKING" in states else ("IDLE" if "IDLE" in states else states[0])

        # Choose a safe destination:
        # - error-like events -> ERROR if exists else IDLE
        # - reset -> IDLE
        # - clear/clear_err -> IDLE
        # - otherwise -> stay in src or go to IDLE (prefer IDLE)
        if ev == "reset" and "IDLE" in states:
            dst = "IDLE"
        elif ev in ("clear", "clear_err") and "IDLE" in states:
            dst = "IDLE"
        elif ev in ("error", "timeout") and "ERROR" in states:
            dst = "ERROR"
        elif "IDLE" in states:
            dst = "IDLE"
        else:
            dst = src

        add_if_missing(trans, src, dst, ev, provenance, "repair_unused_event")
        used.add(ev)

    termset = set(terminals)
    before = len(trans)
    trans[:] = [t for t in trans if not (t["from"] == t["to"] and t["from"] in termset)]
    if len(trans) != before:
        provenance.append({"op": "remove_terminal_self_loops", "count": before - len(trans), "origin": "repair_edges"})

# ---------------- VALIDATION ----------------
def validate(states: List[str], events: List[str], terminals: List[str], trans: List[Transition]) -> List[str]:
    errs: List[str] = []
    stset = set(states)
    evset = set(events)
    indeg, outdeg = degrees(states, trans)
    termset = set(terminals)

    for s in states:
        if indeg.get(s, 0) < 1:
            errs.append(f"State {s} has no incoming")
        if outdeg.get(s, 0) < 1:
            errs.append(f"State {s} has no outgoing")

    for t in trans:
        if t["from"] not in stset:
            errs.append(f"Unknown from {t['from']}")
        if t["to"] not in stset:
            errs.append(f"Unknown to {t['to']}")
        if t["on"] not in evset:
            errs.append(f"Transition uses unknown event: {t}")
        if t["on"] in BAD_EVENTS:
            errs.append(f"Forbidden event name: {t}")
        if t["from"] == t["to"] and t["from"] in termset:
            errs.append(f"Forbidden terminal self-loop: {t}")

    if "DONE" in states and "clear" in events:
        if not any(t["from"] == "DONE" and t["to"] == "IDLE" and t["on"] == "clear" for t in trans):
            errs.append("Missing default DONE->IDLE on clear")
    if "ERROR" in states and "clear_err" in events:
        if not any(t["from"] == "ERROR" and t["to"] == "IDLE" and t["on"] == "clear_err" for t in trans):
            errs.append("Missing default ERROR->IDLE on clear_err")

    if "reset" in events:
        if not any(t["on"] == "reset" for t in trans):
            errs.append("Event reset exists but no transition uses reset")

    used = set(t["on"] for t in trans)
    for ev in events:
        if ev not in used:
            errs.append(f"Event {ev} is unused in transitions")

    return errs

# ---------------- SIMULATION (traces) ----------------
def simulate_trace(states: List[str], trans: List[Transition], start_state: str, events: List[str]) -> Tuple[str, List[str]]:
    st = start_state
    misses: List[str] = []
    for ev in events:
        next_st = None
        for t in trans:
            if t["from"] == st and t["on"] == ev:
                next_st = t["to"]
                break
        if next_st is None:
            misses.append(f"no_edge:{st} on {ev}")
        else:
            st = next_st
    return st, misses

def check_expectations(final_state: str, visited: Set[str], expects: List[str]) -> List[str]:
    fails: List[str] = []
    for e in expects:
        if not isinstance(e, str):
            continue
        e = e.strip()
        if e.startswith("reach:"):
            st = e.split(":", 1)[1].strip().upper()
            if st and st not in visited:
                fails.append(f"expect {e} failed")
        elif e.startswith("end:"):
            st = e.split(":", 1)[1].strip().upper()
            if st and final_state != st:
                fails.append(f"expect {e} failed (got end:{final_state})")
    return fails

# ---------------- EXPORT ----------------
def export_files(fsm_name: str,
                 states: List[str],
                 outputs_o: List[str],
                 so_o: Dict[str, Dict[str, int]],
                 trans_i: List[Dict[str, str]],
                 report: Dict[str, Any]) -> None:
    os.makedirs(EXPORT_DIR, exist_ok=True)
    txtp = os.path.join(EXPORT_DIR, f"{fsm_name}.txt")
    csvp = os.path.join(EXPORT_DIR, f"{fsm_name}.csv")
    rep = os.path.join(EXPORT_DIR, f"{fsm_name}.report.json")
    dbg(f"EXPORT -> {txtp}, {csvp}, {rep}")

    with open(txtp, "w", encoding="utf-8") as f:
        for t in trans_i:
            f.write(f"{t['from']} -> {t['to']} : \"{t['on']}\";\n")

    with open(csvp, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["StateName"] + outputs_o)
        for s in states:
            w.writerow([s] + [so_o[s][o] for o in outputs_o])

    with open(rep, "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2, ensure_ascii=False)

# ---------------- CONTRACT BODIES ----------------
def contract_C01_body(spec: str) -> str:
    return f"""
Spec (IT/EN):
<<<SPEC
{spec}
SPEC

Return exactly:
<<<JSON
{{
  "domain":"hw_fsm",
  "glossary":{{}},
  "requirements":[],
  "assumptions":[],
  "forbidden":[],
  "signals":[],
  "timing":[]
}}
JSON

Rules:
- "requirements": only explicit must-haves stated in the spec text.
- "assumptions": only if needed and clearly optional (common HW practice).
- Do NOT invent signals, protocols, or behaviors not present.
- If reset/timeout/handshake is explicitly mentioned, reflect it in requirements/signals/timing.
- Keep arrays empty if unknown.
"""

def contract_C02_body(spec: str, norm: Dict[str, Any]) -> str:
    return f"""
Spec (IT/EN):
<<<SPEC
{spec}
SPEC

Normalized requirements:
{json.dumps(norm.get("requirements", []), ensure_ascii=False)}

Return exactly:
<<<JSON
{{
  "states":["IDLE","WORKING","DONE"],
  "events":["start","done","clear"],
  "terminal_states":["DONE"],
  "modes":[],
  "mode_states":{{}},
  "mode_tags":{{}}
}}
JSON

Rules:
- If underspecified use defaults shown above.
- If spec mentions error/errore/fault: include state "ERROR", event "error", and event "clear_err".
- If mentions reset/rst: include event "reset".
- If mentions timeout/watchdog: include event "timeout".
- Detect modes like: low power, sleep, standby, charging.
- states uppercase; events/modes/tags lowercase snake_case base names only.
- Ensure DONE has event 'clear'.
- Ensure ERROR has event 'clear_err' if ERROR exists.
- Use ONLY JSON (no extra keys).
"""

def contract_C03_body(spec: str, norm: Dict[str, Any], states: List[str], events: List[str], modes: List[str]) -> str:
    return f"""
Spec (IT/EN):
<<<SPEC
{spec}
SPEC

Glossary (may be empty):
{json.dumps(norm.get("glossary", {}), ensure_ascii=False)}

Allowed canonical lists:
States: {states}
Events: {events}
Modes: {modes}

Return exactly:
<<<JSON
{{
  "state_map":{{}},
  "event_map":{{}},
  "mode_map":{{}},
  "tag_map":{{}}
}}
JSON

Rules:
- Maps may only map synonyms/variants to existing canonical items above.
- Do NOT invent new states/events/modes/tags.
- Keys can be variants; values must be canonical.
"""

def contract_C04_body(spec: str, norm: Dict[str, Any], states: List[str]) -> str:
    return f"""
Spec (IT/EN):
<<<SPEC
{spec}
SPEC

Normalized requirements:
{json.dumps(norm.get("requirements", []), ensure_ascii=False)}

States: {states}

Return exactly:
<<<JSON
{{
  "state_roles":{{"STATE":[]}}
}}
JSON

Rules:
- allowed roles: safe, active, terminal, fault, reset_sink, wait_handshake, low_power
- ERROR-like => include fault
- DONE-like  => include terminal
- IDLE => include safe and reset_sink
- JSON only. No extra keys.
"""

def contract_C05X_body(spec: str, requirements: List[Any], states: List[str], events: List[str], terminals: List[str]) -> str:
    payload = {
        "spec": spec,
        "requirements": requirements,
        "states": states,
        "events": events,
        "terminal_states": terminals,
        "policies": {
            "require_event_coverage": True,
            "no_terminal_self_loops": True,
            "require_done_clear": True,
            "require_error_recovery": True,
            "require_reset_to_idle_if_present": True,
            "prefer_minimal_transitions": True
        }
    }
    return f"""
Input (JSON):
{json.dumps(payload, ensure_ascii=False)}

Return exactly:
<<<JSON
{{
  "transitions":[{{"from":"STATE","to":"STATE","on":"event"}}],
  "coverage": {{
    "unused_events":[],
    "states_no_in":[],
    "states_no_out":[]
  }}
}}
JSON

Rules:
- Use ONLY the provided states/events.
- Each event must appear in >=1 transition (event coverage).
- No terminal self-loop (e.g. DONE->DONE).
- Include policy arcs if relevant:
  - DONE -> IDLE on clear (if DONE and clear exist)
  - ERROR -> IDLE on clear_err (if ERROR and clear_err exist)
  - If reset exists: from every non-IDLE state add a reset->IDLE transition.
- Prefer minimal transitions while satisfying coverage and degree constraints.
- coverage fields must reflect your own draft result (best effort).
"""

def contract_C06X_body(states: List[str], events: List[str], terminals: List[str], transitions: List[Transition], validate_errs: List[str]) -> str:
    payload = {
        "states": states,
        "events": events,
        "terminal_states": terminals,
        "transitions": transitions,
        "validate_errs": validate_errs[:60],
        "priority_fix_order": [
            "unused_events",
            "missing_reset_policy_if_present",
            "missing_done_clear",
            "missing_error_recovery",
            "dead_states_in_or_out"
        ]
    }
    return f"""
Input (JSON):
{json.dumps(payload, ensure_ascii=False)}

Return exactly:
<<<JSON
{{
  "patches":[
    {{"op":"add_transition","from":"STATE","to":"STATE","on":"event"}},
    {{"op":"remove_transition","from":"STATE","to":"STATE","on":"event"}}
  ],
  "reason":""
}}
JSON

Rules:
- Only use provided states/events.
- Minimal patch set.
- Prefer add_transition over remove_transition unless necessary.
- reason must be <= 200 chars.
"""

def contract_C09X_body(spec: str, requirements: List[Any], states: List[str],
                       state_roles: Dict[str, List[str]],
                       mode_states: Dict[str, str], mode_tags: Dict[str, str]) -> str:
    payload = {
        "spec": spec,
        "requirements": requirements,
        "states": states,
        "state_roles": state_roles,
        "mode_states": mode_states,
        "mode_tags": mode_tags
    }
    return f"""
Input (JSON):
{json.dumps(payload, ensure_ascii=False)}

Return exactly:
<<<JSON
{{
  "state_tags":{{"STATE":[]}},
  "extra_outputs":[],
  "notes":[]
}}
JSON

Rules:
- 0..3 tags per state, snake_case, no empty.
- If role includes terminal => include "done".
- If role includes fault => include "error".
- If IDLE has safe/reset_sink => include "idle" or "safe" (prefer "idle").
- Do not use event names as tags unless unavoidable.
- notes is a JSON array of short strings (can be []).
- No additional keys.
"""

def contract_C11_body(spec: str, events: List[str], states: List[str]) -> str:
    payload = {"spec": spec, "events": events, "states": states}
    return f"""
Input (JSON):
{json.dumps(payload, ensure_ascii=False)}

Return exactly:
<<<JSON
{{
  "traces":[
    {{"events":[], "expect":[]}}
  ]
}}
JSON

Rules:
- Generate 5..12 traces.
- Include reset behavior if "reset" in events.
- Include nominal start->done->clear if start/done/clear exist.
- Include error recovery if ERROR exists or error/clear_err exist.
- Include timeout path if "timeout" in events.
- "expect" items can be: "reach:STATE", "end:STATE".
- Use ONLY events from the provided list.
- JSON only. No extra keys.
"""

def contract_C12_body(spec: str, requirements: List[Any], fsm_payload: Dict[str, Any], trace_summary: Dict[str, Any]) -> str:
    payload = {
        "requirements": requirements,
        "fsm": fsm_payload,
        "trace_summary": trace_summary
    }
    return f"""
Spec (IT/EN):
<<<SPEC
{spec}
SPEC

Input (JSON):
{json.dumps(payload, ensure_ascii=False)}

Return exactly:
<<<JSON
{{
  "pass": true,
  "missing": [],
  "contradictions": [],
  "hallucinations": [],
  "suggested_actions": []
}}
JSON

Rules:
- missing: requirements not reflected in FSM (be conservative).
- hallucinations: states/events/tags that are not implied by spec/requirements (be conservative).
- suggested_actions must reference existing states/events OR say "revise entities".
- JSON only. No extra keys.
"""

# ---------------- APPLY CANONICAL MAP ----------------
def apply_maps(states: List[str], events: List[str], modes: List[str],
               mode_states: Dict[str, str], mode_tags: Dict[str, str],
               maps: Dict[str, Any], provenance: List[Dict[str, Any]]) -> Tuple[List[str], List[str], List[str], Dict[str, str], Dict[str, str]]:
    state_map = maps.get("state_map") if isinstance(maps.get("state_map"), dict) else {}
    event_map = maps.get("event_map") if isinstance(maps.get("event_map"), dict) else {}
    mode_map  = maps.get("mode_map") if isinstance(maps.get("mode_map"), dict) else {}
    tag_map   = maps.get("tag_map") if isinstance(maps.get("tag_map"), dict) else {}

    canon_states = []
    for s in states:
        mapped = None
        for k, v in state_map.items():
            if isinstance(k, str) and isinstance(v, str) and k.strip().upper() == s.strip().upper():
                mapped = v.strip().upper()
                break
        canon_states.append(mapped or s.strip().upper())
    canon_states = list(dict.fromkeys([s for s in canon_states if s]))
    if canon_states != states:
        provenance.append({"op": "apply_state_map", "origin": "C03", "diff": {"before": states, "after": canon_states}})
    states = canon_states

    canon_events = []
    for e in events:
        mapped = None
        for k, v in event_map.items():
            if isinstance(k, str) and isinstance(v, str) and snake_token(k) == snake_token(e):
                mapped = snake_token(v)
                break
        canon_events.append(mapped or snake_token(e))
    canon_events = list(dict.fromkeys([e for e in canon_events if e]))
    if canon_events != events:
        provenance.append({"op": "apply_event_map", "origin": "C03", "diff": {"before": events, "after": canon_events}})
    events = canon_events

    canon_modes = []
    for m in modes:
        mapped = None
        for k, v in mode_map.items():
            if isinstance(k, str) and isinstance(v, str) and snake_token(k) == snake_token(m):
                mapped = snake_token(v)
                break
        canon_modes.append(mapped or snake_token(m))
    canon_modes = list(dict.fromkeys([m for m in canon_modes if m]))
    if canon_modes != modes:
        provenance.append({"op": "apply_mode_map", "origin": "C03", "diff": {"before": modes, "after": canon_modes}})
    modes = canon_modes

    new_mode_states: Dict[str, str] = {}
    new_mode_tags: Dict[str, str] = {}
    for m in modes:
        st = mode_states.get(m, mode_state_name(m)).strip().upper()
        new_mode_states[m] = st
        tag = mode_tags.get(m, m)
        tag = snake_token(tag)
        for k, v in tag_map.items():
            if isinstance(k, str) and isinstance(v, str) and snake_token(k) == tag:
                tag = snake_token(v)
                break
        new_mode_tags[m] = tag or m
    mode_states = new_mode_states
    mode_tags = new_mode_tags

    return states, events, modes, mode_states, mode_tags

# ---------------- PATCH APPLICATION ----------------
def apply_patch_plan(states: List[str], events: List[str], trans: List[Transition],
                     plan: Dict[str, Any], provenance: List[Dict[str, Any]]) -> None:
    patches = plan.get("patches")
    if not isinstance(patches, list):
        return
    stset = set(states)
    evset = set(events)

    def remove_one(fr: str, to: str, on: str) -> bool:
        onb = snake_token(on)
        for i, t in enumerate(trans):
            if t["from"] == fr and t["to"] == to and t["on"] == onb:
                trans.pop(i)
                return True
        return False

    for p in patches:
        if not isinstance(p, dict):
            continue
        op = p.get("op")
        fr = p.get("from")
        to = p.get("to")
        on = p.get("on")
        if not (isinstance(op, str) and isinstance(fr, str) and isinstance(to, str) and isinstance(on, str)):
            continue
        fru = fr.strip().upper()
        tou = to.strip().upper()
        onb = snake_token(on)
        if fru not in stset or tou not in stset or onb not in evset:
            continue
        if op == "add_transition":
            add_if_missing(trans, fru, tou, onb, provenance, "C06X_patch")
        elif op == "remove_transition":
            if remove_one(fru, tou, onb):
                provenance.append({"op": "remove_transition", "from": fru, "to": tou, "on": onb, "origin": "C06X_patch"})

# ---------------- PIPELINE HELPERS ----------------
def synthesize_transitions_adaptive(spec: str,
                                    requirements: List[Any],
                                    states: List[str],
                                    events: List[str],
                                    terminals: List[str],
                                    modes: List[str],
                                    mode_states: Dict[str, str],
                                    provenance: List[Dict[str, Any]]) -> Tuple[List[Transition], Dict[str, Any]]:
    """
    1) C05X once
    2) deterministic repair + validate
    3) if invalid -> one C06X patch + repair + validate
    4) if still invalid and fallback enabled -> regen C05X hotter once
    """
    # Generate (C05X)
    body = contract_C05X_body(spec, requirements, states, events, terminals)
    r = run_contract("C05X_TRANSITIONS_SYNTH", body, model=MODEL_GEN, temp=TEMP_TRANSITIONS)

    trans = canon_transitions(r.get("transitions"), states, events)

    # Mode scaffolding edges (policy)
    local_prov: List[Dict[str, Any]] = []
    for m, st in mode_states.items():
        if st in states:
            add_if_missing(trans, "IDLE", st, mode_enter_event(m), local_prov, "repair_mode_edges")
            add_if_missing(trans, st, "IDLE", mode_exit_event(m), local_prov, "repair_mode_edges")

    deterministic_repair_transitions(states, events, terminals, trans, local_prov)

    errs = validate(states, events, terminals, trans)
    if not errs:
        provenance.extend(local_prov)
        return trans, {"method": "C05X", "validate_errs": []}

    # Patch once (C06X)
    if MAX_PATCH_ONCE >= 1:
        bodyp = contract_C06X_body(states, events, terminals, trans, errs)
        plan = run_contract("C06X_PATCH_MIN", bodyp, model=MODEL_VER, temp=0.0)
        apply_patch_plan(states, events, trans, plan, local_prov)
        deterministic_repair_transitions(states, events, terminals, trans, local_prov)
        errs2 = validate(states, events, terminals, trans)
        if not errs2:
            provenance.extend(local_prov)
            return trans, {"method": "C05X+patch", "validate_errs": []}

    # Fallback regen
    if ALLOW_FALLBACK_REGEN:
        body2 = contract_C05X_body(spec, requirements, states, events, terminals)
        r2 = run_contract("C05X_TRANSITIONS_SYNTH", body2, model=MODEL_GEN, temp=TEMP_TRANSITIONS_FALLBACK)
        trans2 = canon_transitions(r2.get("transitions"), states, events)

        for m, st in mode_states.items():
            if st in states:
                add_if_missing(trans2, "IDLE", st, mode_enter_event(m), local_prov, "repair_mode_edges")
                add_if_missing(trans2, st, "IDLE", mode_exit_event(m), local_prov, "repair_mode_edges")

        deterministic_repair_transitions(states, events, terminals, trans2, local_prov)
        errs3 = validate(states, events, terminals, trans2)
        if not errs3:
            provenance.extend(local_prov)
            return trans2, {"method": "fallback_regen", "validate_errs": []}

        provenance.extend(local_prov)
        return trans2, {"method": "fallback_regen_failed", "validate_errs": errs3[:80]}

    provenance.extend(local_prov)
    return trans, {"method": "no_fallback", "validate_errs": errs[:80]}

# ---------------- MAIN PIPELINE ----------------
def run_pipeline(spec: str, fsm_name: str) -> None:
    dbg("=== PIPELINE START ===")
    dbg(f"fsm_name={fsm_name} spec_len={len(spec)}")

    report: Dict[str, Any] = {
        "fsm_name": fsm_name,
        "model_gen": MODEL_GEN,
        "model_ver": MODEL_VER,
        "ollama_url": OLLAMA_URL,
        "contracts": [],
        "provenance": [],
        "scores": [],
        "final": {},
    }
    provenance: List[Dict[str, Any]] = report["provenance"]

    # ---- C01 normalize
    r01 = run_contract("C01_SPEC_NORMALIZE", contract_C01_body(spec), model=MODEL_VER, temp=0.1)
    report["contracts"].append({"id": "C01", "out": r01})

    # ---- C02 entities
    r02 = run_contract("C02_ENTITIES_EXTRACT", contract_C02_body(spec, r01), model=MODEL_GEN, temp=0.2)
    report["contracts"].append({"id": "C02", "out": r02})

    states = uniq_upper_list(r02.get("states"), ["IDLE", "WORKING", "DONE"])
    events = uniq_lower_list(r02.get("events"), ["start", "done", DONE_CLEAR_BASE])
    terminals = infer_terminals(states, uniq_upper_list(r02.get("terminal_states"), ["DONE"]))

    modes = uniq_lower_list(r02.get("modes"), [])
    mode_states_in = r02.get("mode_states") if isinstance(r02.get("mode_states"), dict) else {}
    mode_tags_in   = r02.get("mode_tags") if isinstance(r02.get("mode_tags"), dict) else {}

    mode_states: Dict[str, str] = {}
    mode_tags: Dict[str, str] = {}
    for m in modes:
        st = mode_state_name(m)
        if isinstance(mode_states_in.get(m), str) and mode_states_in[m].strip():
            st = mode_states_in[m].strip().upper()
        mode_states[m] = st
        tagv = mode_tags_in.get(m, m)
        mode_tags[m] = snake_token(tagv) if isinstance(tagv, str) else m

    # deterministic enrich
    ensure_core_entities(spec, states, events, terminals, provenance)
    ensure_mode_entities(spec, states, events, modes, mode_states, mode_tags, provenance)

    dbg(f"S2 states={states}")
    dbg(f"S2 events={events}")
    dbg(f"S2 modes={modes} mode_states={mode_states} mode_tags={mode_tags}")

    # ---- C03 canonical map + apply
    r03 = run_contract("C03_CANONICAL_MAP", contract_C03_body(spec, r01, states, events, modes), model=MODEL_VER, temp=0.0)
    report["contracts"].append({"id": "C03", "out": r03})
    states, events, modes, mode_states, mode_tags = apply_maps(states, events, modes, mode_states, mode_tags, r03, provenance)

    # Re-run deterministic ensures after mapping
    ensure_core_entities(spec, states, events, terminals, provenance)
    ensure_mode_entities(spec, states, events, modes, mode_states, mode_tags, provenance)
    terminals = infer_terminals(states, terminals)

    # ---- C04 roles
    r04 = run_contract("C04_STATE_ROLE_ANNOTATION", contract_C04_body(spec, r01, states), model=MODEL_VER, temp=0.0)
    report["contracts"].append({"id": "C04", "out": r04})
    state_roles_in = r04.get("state_roles") if isinstance(r04.get("state_roles"), dict) else {}
    state_roles: Dict[str, List[str]] = {}
    allowed_roles = {"safe","active","terminal","fault","reset_sink","wait_handshake","low_power"}
    for st in states:
        arr = state_roles_in.get(st, [])
        if not isinstance(arr, list):
            arr = []
        roles: List[str] = []
        for x in arr:
            if isinstance(x, str):
                r = snake_token(x)
                if r in allowed_roles:
                    roles.append(r)
        # backstops
        if st == "IDLE":
            roles = list(dict.fromkeys(["safe","reset_sink"] + roles))
        if st == "DONE":
            roles = list(dict.fromkeys(["terminal"] + roles))
        if st == "ERROR":
            roles = list(dict.fromkeys(["fault"] + roles))
        state_roles[st] = roles

    # ---- S5 transitions (adaptive)
    trans, trans_meta = synthesize_transitions_adaptive(
        spec=spec,
        requirements=r01.get("requirements", []),
        states=states,
        events=events,
        terminals=terminals,
        modes=modes,
        mode_states=mode_states,
        provenance=provenance
    )
    errs_final = validate(states, events, terminals, trans)
    report["scores"].append({
        "stage": "transitions",
        "method": trans_meta.get("method"),
        "validate_errs": errs_final[:60],
        "num_transitions": len(trans)
    })
    if errs_final:
        dbg("Transitions invalid. Top errs: " + "; ".join(errs_final[:10]))
        raise RuntimeError("Invalid FSM after adaptive transitions synthesis (see report).")

    # ---- S6 tags (C09X)
    r09 = run_contract("C09X_TAGS_SYNTH", contract_C09X_body(spec, r01.get("requirements", []), states, state_roles, mode_states, mode_tags),
                       model=MODEL_GEN, temp=TEMP_TAGS)
    report["contracts"].append({"id": "C09X", "out": r09})

    state_tags_in = r09.get("state_tags") if isinstance(r09.get("state_tags"), dict) else {}
    extra_outs = uniq_lower_list(r09.get("extra_outputs"), [])
    tags: Dict[str, List[str]] = {}
    for st, arr in state_tags_in.items():
        if isinstance(st, str) and isinstance(arr, list):
            tags[st.strip().upper()] = [snake_token(x) for x in arr if isinstance(x, str)]
    tags = sanitize_state_tags(tags, states)

    outputs_base, so_base = build_outputs_from_tags(states, tags, extra_outs, mode_tags, mode_states, state_roles)

    # ---- S7 traces (C11)
    r11 = run_contract("C11_TRACE_TESTGEN", contract_C11_body(spec, events, states), model=MODEL_VER, temp=TEMP_TRACES)
    report["contracts"].append({"id": "C11", "out": r11})
    traces = r11.get("traces") if isinstance(r11.get("traces"), list) else []

    trace_results: Dict[str, Any] = {"runs": [], "failures": 0}
    evset = set(events)
    for tr in traces[:30]:
        if not isinstance(tr, dict):
            continue
        evs = tr.get("events")
        exp = tr.get("expect")
        if not isinstance(evs, list) or not isinstance(exp, list):
            continue
        evs_b = [snake_token(x) for x in evs if isinstance(x, str)]
        evs_b = [e for e in evs_b if e in evset]
        start_state = "IDLE" if "IDLE" in states else states[0]
        visited = {start_state}
        st = start_state
        misses = []
        for e in evs_b:
            st, miss = simulate_trace(states, trans, st, [e])
            visited.add(st)
            misses.extend(miss)
        fails = check_expectations(st, visited, [x for x in exp if isinstance(x, str)])
        if fails:
            trace_results["failures"] += 1
        trace_results["runs"].append({
            "events": evs_b,
            "expect": exp,
            "end": st,
            "visited": sorted(list(visited)),
            "misses": misses,
            "fails": fails
        })

    trace_summary = {
        "failures": trace_results["failures"],
        "num_runs": len(trace_results["runs"]),
        "failed_examples": [
            {"events": r["events"], "fails": r["fails"], "end": r["end"]}
            for r in trace_results["runs"] if r["fails"]
        ][:3]
    }

    # ---- S8 final audit (C12)
    fsm_payload = {
        "states": states,
        "events": events,
        "terminal_states": terminals,
        "modes": modes,
        "mode_states": mode_states,
        "mode_tags": mode_tags,
        "transitions": trans,
        "state_roles": state_roles,
        "state_tags": tags,
        "outputs": outputs_base
    }
    r12 = run_contract("C12_SPEC_COVERAGE_AUDIT",
                       contract_C12_body(spec, r01.get("requirements", []), fsm_payload, trace_summary),
                       model=MODEL_VER, temp=0.0)
    report["contracts"].append({"id": "C12", "out": r12})

    # ---- finalize suffixing + export
    inputs_i, trans_i, outputs_o, so_o = apply_suffixing(events, trans, outputs_base, so_base)

    # final validation of suffixed outputs matrix shape
    if any(s not in so_o for s in states):
        raise RuntimeError("Missing state outputs after suffixing.")
    for s in states:
        for o in outputs_o:
            if so_o[s].get(o) not in (0, 1):
                raise RuntimeError(f"Invalid output value for {s}:{o}")

    report["final"] = {
        "states": states,
        "events": events,
        "inputs_i": inputs_i,
        "outputs_base": outputs_base,
        "outputs_o": outputs_o,
        "num_transitions": len(trans),
        "trace_failures": trace_results["failures"],
        "audit": r12,
        "cache_entries": len(_llm_cache)
    }

    export_files(fsm_name, states, outputs_o, so_o, trans_i, report)
    dbg("=== PIPELINE OK ===")

# ---------------- REPL / CLI ----------------
@dataclass
class REPL:
    name: str = "test"
    buf: List[str] = field(default_factory=list)

def banner() -> None:
    print("FSM Agent REPL (Ollama) — HW/Protocol/RTL generalized (compact pipeline)", flush=True)
    print(f"Model GEN  : {MODEL_GEN}", flush=True)
    print(f"Model VER  : {MODEL_VER}", flush=True)
    print(f"Export dir : {EXPORT_DIR}", flush=True)
    print("Comandi:", flush=True)
    print("  .            => genera + export", flush=True)
    print("  :q           => esci", flush=True)
    print("  :name <n>    => cambia nome FSM", flush=True)
    print("  :show        => mostra buffer", flush=True)
    print("  :clear       => svuota buffer", flush=True)
    print("  :debug on|off=> abilita/disabilita DBG", flush=True)
    print("  :cache clear => svuota cache LLM", flush=True)
    print("", flush=True)

def repl() -> int:
    global DEBUG, _llm_cache
    st = REPL()
    banner()
    while True:
        try:
            line = input("> ")
        except (EOFError, KeyboardInterrupt):
            print("\n:q", flush=True)
            return 0

        cmd = line.strip()
        if cmd == ":q":
            return 0
        if cmd.startswith(":debug "):
            v = cmd[len(":debug "):].strip().lower()
            DEBUG = (v == "on")
            print(f"DEBUG={DEBUG}", flush=True)
            continue
        if cmd.startswith(":cache "):
            v = cmd[len(":cache "):].strip().lower()
            if v == "clear":
                _llm_cache.clear()
                print("Cache LLM svuotata.", flush=True)
            continue
        if cmd.startswith(":name "):
            st.name = cmd[len(":name "):].strip() or st.name
            print(f"FSM name: {st.name}", flush=True)
            continue
        if cmd == ":show":
            print("\n--- SPEC BUFFER ---", flush=True)
            print("\n".join(st.buf), flush=True)
            print("--- END ---\n", flush=True)
            continue
        if cmd == ":clear":
            st.buf.clear()
            print("Buffer svuotato.", flush=True)
            continue
        if cmd == ".":
            spec = "\n".join(st.buf).strip()
            if not spec:
                print("Spec vuota.", flush=True)
                continue
            try:
                run_pipeline(spec, st.name)
                print("[OK] Export completato.", flush=True)
            except Exception as e:
                print("[FATAL]", str(e), flush=True)
            continue

        st.buf.append(line)

def main() -> int:
    p = argparse.ArgumentParser(description="HW/Protocol/RTL FSM generator (Ollama) — compact pipeline")
    p.add_argument("--name", default="test", help="FSM name (export basename)")
    p.add_argument("--spec", default=None, help="Spec string (if omitted, run REPL)")
    p.add_argument("--spec-file", default=None, help="Path to spec text file")
    p.add_argument("--export-dir", default=None, help="Override export directory")
    p.add_argument("--model-gen", default=None, help="Override generator model")
    p.add_argument("--model-ver", default=None, help="Override verifier model")
    p.add_argument("--ollama-url", default=None, help="Override ollama URL")
    p.add_argument("--debug", action="store_true", help="Enable debug logs")
    args = p.parse_args()

    global EXPORT_DIR, MODEL_GEN, MODEL_VER, OLLAMA_URL, DEBUG
    if args.export_dir:
        EXPORT_DIR = args.export_dir
    if args.model_gen:
        MODEL_GEN = args.model_gen
    if args.model_ver:
        MODEL_VER = args.model_ver
    if args.ollama_url:
        OLLAMA_URL = args.ollama_url
    DEBUG = True if args.spec is None and args.spec_file is None else bool(args.debug)    

    try:
        if args.spec is None and args.spec_file is None:
            return repl()
        if args.spec_file:
            with open(args.spec_file, "r", encoding="utf-8") as f:
                spec = f.read()
        else:
            spec = args.spec or ""
        spec = spec.strip()
        if not spec:
            print("[FATAL] Empty spec.", flush=True)
            return 1
        run_pipeline(spec, args.name)
        print("[OK] Export completato.", flush=True)
        return 0
    except Exception as e:
        print("[FATAL] Unhandled:", str(e), flush=True)
        return 1

if __name__ == "__main__":
    sys.exit(main())

