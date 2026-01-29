from __future__ import annotations
from typing import List
from .model import FSM

def render_transitions_only(fsm: FSM) -> str:
    lines: List[str] = []
    for t in fsm.transitions:
        lines.append(f'{t.from_state} -> {t.to_state} : "{t.cond}";')
    return "\n".join(lines)

def render_outputs_csv(fsm: FSM) -> str:
    lines: List[str] = []
    header = ["StateName"] + list(fsm.outputs_header)
    lines.append(",".join(header))
    for st in fsm.states:
        outs = fsm.outputs.get(st, {})
        row = [st] + [str(int(outs.get(h, 0))) for h in fsm.outputs_header]
        lines.append(",".join(row))
    return "\n".join(lines)

def render_fsm_text(fsm: FSM) -> str:
    # formato richiesto "pulito": transizioni + blank + CSV outputs
    return render_transitions_only(fsm) + "\n\n" + render_outputs_csv(fsm) + "\n"
