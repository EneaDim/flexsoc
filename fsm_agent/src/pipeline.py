from __future__ import annotations
from typing import Any, Dict
import json

from .io_utils import read_text
from .llm_client import llm_complete
from .json_coerce import coerce_json

from .intent_ir import (
    sanitize_intent_types,
    enforce_entities_on_intent,
    validate_intent,
    ensure_nonempty_edges,
    ensure_graph_closure_edges,
    intent_to_ir,
)

from .ir_validate import validate_ir
from .rtl_passes import apply_priority_rules, auto_error_priority
from .rtl_synth import ir_to_fsm
from .validate import validate_fsm


def _render(tmpl_path: str, mapping: Dict[str, str]) -> str:
    s = read_text(tmpl_path)
    for k, v in mapping.items():
        s = s.replace(k, v)
    return s


def run_pipeline(*, spec_text: str, prompts_dir: str) -> Dict[str, Any]:
    # STEP 1: entities
    p1 = _render(f"{prompts_dir}/step1_extract_entities.txt", {"{{SPEC}}": spec_text})
    raw1 = llm_complete(p1)
    entities = coerce_json(raw1)

    # STEP 2: intent-ir
    p2 = _render(
        f"{prompts_dir}/step2_entities_to_ir.txt",
        {"{{ENTITIES_JSON}}": json.dumps(entities, ensure_ascii=False)},
    )
    raw2 = llm_complete(p2)
    intent0 = sanitize_intent_types(coerce_json(raw2))

    # Hard gate: states/init MUST match entities
    enforce_entities_on_intent(intent0, entities)

    # Ensure some edges exist and then close the graph deterministically (generic, no signal invention)
    ensure_nonempty_edges(intent0)
    ensure_graph_closure_edges(intent0)

    errs0 = validate_intent(intent0, entities)
    intent = intent0

    if errs0:
        # STEP 3: fix intent-ir using errors + current intent
        fix_tmpl = read_text(f"{prompts_dir}/step3_fix_ir_from_errors.txt")
        fix_prompt = fix_tmpl.replace("{{ERRORS}}", "\n".join(errs0)).replace(
            "{{INTENT_JSON}}", json.dumps(intent0, ensure_ascii=False)
        )
        raw3 = llm_complete(fix_prompt)
        intent1 = sanitize_intent_types(coerce_json(raw3))
        enforce_entities_on_intent(intent1, entities)

        ensure_nonempty_edges(intent1)
        ensure_graph_closure_edges(intent1)

        errs1 = validate_intent(intent1, entities)
        if errs1:
            raise RuntimeError("INTENT-IR still invalid after step3 fix:\n" + "\n".join(errs1))
        intent = intent1

    # Convert intent -> IR (with real transitions/cond)
    ir = intent_to_ir(intent)

    # IR validation (should pass; guards are atomic)
    ir_errs = validate_ir(ir)
    if ir_errs:
        raise RuntimeError("IR invalid after intent->IR:\n" + "\n".join(ir_errs))

    # Priorities and error handling (safe, generic)
    apply_priority_rules(ir)
    auto_error_priority(ir, error_sig="error_i", error_state="ERROR")

    fsm = ir_to_fsm(ir)
    verrs = validate_fsm(fsm)
    if verrs:
        raise RuntimeError("FSM validation failed:\n" + "\n".join(verrs))

    return fsm
