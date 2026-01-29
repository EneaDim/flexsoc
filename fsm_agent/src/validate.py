from __future__ import annotations
import re
from typing import List
from .model import FSM
from .cond_parser import parse_condition, collect_idents, CondParseError

OUTPUTS_HEADER = "StateName,busy_o,valid_o,error_o,low_power_o,dbg_o"
TRANSITION_LINE_RE = re.compile(r'^[A-Za-z_][A-Za-z0-9_]* -> [A-Za-z_][A-Za-z0-9_]* : ".*";$')

_PIPELINE_NAME_RE = re.compile(r'^(STAGE|MID|PIPE|FINAL)\d*', re.IGNORECASE)

def _contains_token(cond: str, token: str) -> bool:
    return re.search(rf'(^|[^A-Za-z0-9_]){re.escape(token)}([^A-Za-z0-9_]|$)', cond) is not None

def validate_fsm_object(fsm: FSM) -> List[str]:
    errors: List[str] = []
    stset = set(fsm.states)

    out_deg = {s: 0 for s in fsm.states}
    in_deg  = {s: 0 for s in fsm.states}

    # discourage invented pipeline states unless justified in assumptions
    invented_pipeline = [s for s in fsm.states if _PIPELINE_NAME_RE.match(s)]
    if invented_pipeline:
        # allow only if assumptions mention "intermedio" or "pipeline"
        joined = " ".join(fsm.assumptions or []).lower()
        if ("intermedio" not in joined) and ("pipeline" not in joined) and ("1 ciclo" not in joined) and ("1-cycle" not in joined):
            errors.append(f"stati pipeline non richiesti dalla spec: {invented_pipeline}")

    for t in fsm.transitions:
        frm = t.from_state
        to  = t.to_state
        cond = (t.cond or "").strip()

        if frm not in stset:
            errors.append(f"transition: from '{frm}' not in states")
            continue
        if to not in stset:
            errors.append(f"transition: to '{to}' not in states")
            continue

        if frm == to:
            errors.append(f"forbidden self-loop: '{frm} -> {to}'")

        if not cond:
            errors.append(f"empty condition on transition {frm}->{to}")
        else:
            # hard reject forbidden operators
            if "&&" in cond or "||" in cond or "~" in cond or "==" in cond or "!=" in cond:
                errors.append(f"forbidden operators in condition {frm}->{to}: '{cond}'")

            if _contains_token(cond, "reset_i"):
                errors.append(f"reset_i forbidden in guards: {frm}->{to}")

            if _contains_token(cond, "done_i") and _contains_token(cond, "error_i"):
                errors.append(f"forbidden mixing done_i and error_i in same condition: {frm}->{to}")

            # error_i only to ERROR
            if _contains_token(cond, "error_i") and to != "ERROR":
                errors.append(f"error_i can only drive transitions to ERROR: found {frm}->{to}")

            # avoid global '!error_i' filters
            if "!error_i" in cond and not _contains_token(cond, "done_i") and not _contains_token(cond, "start_i"):
                errors.append(f"suspicious '!error_i' used as global filter in {frm}->{to}: '{cond}'")

            # parse DSL
            try:
                ast = parse_condition(cond)
                for name in collect_idents(ast):
                    if name.endswith("_o"):
                        errors.append(f"condition {frm}->{to} uses output '{name}' (forbidden; only *_i)")
                    elif not name.endswith("_i"):
                        errors.append(f"condition {frm}->{to} uses identifier '{name}' not ending with _i")
            except CondParseError as e:
                errors.append(f"unparsable condition in {frm}->{to}: {e}")

        out_deg[frm] += 1
        in_deg[to]   += 1

    for s in fsm.states:
        if out_deg.get(s, 0) < 1:
            errors.append(f"graph not closed: state '{s}' has out-degree=0")
        if in_deg.get(s, 0) < 1:
            errors.append(f"graph not closed: state '{s}' has in-degree=0")

    req_cols = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]
    for st in fsm.states:
        if st not in fsm.outputs:
            errors.append(f"outputs: missing state '{st}'")
            continue
        outs = fsm.outputs.get(st, {})
        for col in req_cols:
            if col not in outs:
                errors.append(f"outputs: state '{st}' missing '{col}'")
            else:
                if str(outs[col]) not in ("0", "1"):
                    errors.append(f"outputs: state '{st}' col '{col}' must be 0/1, got '{outs[col]}'")

    for st in fsm.outputs.keys():
        if st not in stset:
            errors.append(f"outputs contains extra state '{st}' not in states")

    return errors

def validate_rendered_text(text: str, expected_states: List[str]) -> List[str]:
    errors: List[str] = []
    lines = [ln.rstrip("\n") for ln in text.splitlines()]

    try:
        idx_hdr = next(i for i, ln in enumerate(lines) if ln.strip() == OUTPUTS_HEADER)
    except StopIteration:
        errors.append(f"missing outputs CSV header exactly: '{OUTPUTS_HEADER}'")
        return errors

    trans_lines = [ln.strip() for ln in lines[:idx_hdr] if ln.strip()]
    for ln in trans_lines:
        if not TRANSITION_LINE_RE.match(ln):
            errors.append(f"invalid transition line: {ln}")

    seen = {}
    for ln in lines[idx_hdr + 1:]:
        if not ln.strip():
            continue
        parts = ln.split(",")
        if len(parts) != 6:
            errors.append(f"outputs row must have 6 columns: {ln}")
            continue
        st = parts[0].strip()
        seen[st] = True
        for bit in parts[1:]:
            if bit.strip() not in ("0", "1"):
                errors.append(f"non-binary outputs for state '{st}': {ln}")

    for st in expected_states:
        if st not in seen:
            errors.append(f"missing outputs row for state '{st}'")

    for st in seen.keys():
        if st not in expected_states:
            errors.append(f"outputs contains extra state '{st}' not in states")

    return errors
