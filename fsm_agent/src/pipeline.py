from __future__ import annotations

import json
import os
from typing import Any, Dict, List, Optional, Tuple

from pydantic import ValidationError

from .json_guard import loads_first_json
from .model import FSM
from .render import render_outputs_csv, render_transitions_only
from .validate import validate_fsm_object, validate_rendered_text

# Optional: schema coercion (airbag) if present
try:
    from .json_coerce import coerce_fsm_json  # type: ignore
except Exception:  # pragma: no cover
    coerce_fsm_json = None  # type: ignore


def _project_root() -> str:
    # .../fsm_agent/src/pipeline.py -> .../fsm_agent
    return os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


def _read_text(path: str) -> str:
    with open(path, "r", encoding="utf-8") as f:
        return f.read()


def _write_text(path: str, s: str) -> None:
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        f.write(s)


def _find_gold_pairs() -> List[Tuple[str, str]]:
    """
    Returns list of (nl_txt_path, json_path) found under:
      <root>/data/gold/nl/*.txt
      <root>/data/gold/json/*.json
    with matching basename (example_001).
    """
    root = _project_root()
    nl_dir = os.path.join(root, "data", "gold", "nl")
    js_dir = os.path.join(root, "data", "gold", "json")
    if not os.path.isdir(nl_dir) or not os.path.isdir(js_dir):
        return []

    pairs: List[Tuple[str, str]] = []
    for fn in sorted(os.listdir(nl_dir)):
        if not fn.endswith(".txt"):
            continue
        base = os.path.splitext(fn)[0]
        nl_path = os.path.join(nl_dir, fn)
        js_path = os.path.join(js_dir, base + ".json")
        if os.path.isfile(js_path):
            pairs.append((nl_path, js_path))
    return pairs


def _simple_rank(query: str, docs: List[str]) -> List[int]:
    """
    Very small local ranker: token-overlap score.
    Returns indices sorted by score descending.
    """
    q = query.lower()
    q_tokens = {t for t in _tok(q) if t}
    scores: List[Tuple[int, int]] = []
    for i, d in enumerate(docs):
        d_tokens = {t for t in _tok(d.lower()) if t}
        score = len(q_tokens & d_tokens)
        scores.append((score, i))
    scores.sort(reverse=True)
    return [i for _, i in scores]


def _tok(s: str) -> List[str]:
    out = []
    cur = []
    for ch in s:
        if ch.isalnum() or ch == "_":
            cur.append(ch)
        else:
            if cur:
                out.append("".join(cur))
                cur = []
    if cur:
        out.append("".join(cur))
    return out


def _build_gold_context(
    spec_text: str,
    k: int,
    auto_gold_rank: bool,
    gold_char_budget: int,
) -> str:
    """
    Builds a compact context block containing up to k examples (NL + JSON).
    """
    pairs = _find_gold_pairs()
    if not pairs or k <= 0:
        return ""

    nls: List[str] = []
    jss: List[str] = []
    for nl_path, js_path in pairs:
        try:
            nls.append(_read_text(nl_path).strip())
            jss.append(_read_text(js_path).strip())
        except Exception:
            nls.append("")
            jss.append("")

    order = list(range(len(pairs)))
    if auto_gold_rank:
        order = _simple_rank(spec_text, nls)

    chunks: List[str] = []
    used = 0
    taken = 0
    for idx in order:
        if taken >= k:
            break
        nl = nls[idx].strip()
        js = jss[idx].strip()
        if not nl or not js:
            continue
        block = (
            f"EXAMPLE_{taken+1}\n"
            f"NL:\n{nl}\n"
            f"JSON:\n{js}\n"
        )
        if used + len(block) > gold_char_budget:
            break
        chunks.append(block)
        used += len(block)
        taken += 1

    return "\n".join(chunks).strip()


def _render_fsm_text(fsm: FSM) -> str:
    # No headers like "State transition" / "Outputs" per le tue richieste precedenti.
    trans = render_transitions_only(fsm).rstrip()
    outs = render_outputs_csv(fsm).rstrip()
    if trans and outs:
        return trans + "\n\n" + outs + "\n"
    if trans:
        return trans + "\n"
    if outs:
        return outs + "\n"
    return ""


def _fill_template(tpl: str, mapping: Dict[str, str]) -> str:
    out = tpl
    for k, v in mapping.items():
        out = out.replace("{{" + k + "}}", v)
    return out


def _try_parse_fsm_json(raw_text: str) -> Dict[str, Any]:
    j = loads_first_json(raw_text)
    if coerce_fsm_json is not None and isinstance(j, dict):
        j = coerce_fsm_json(j)  # type: ignore
    return j  # type: ignore


def _errors_from_validation_error(e: ValidationError) -> List[str]:
    errs = []
    for it in e.errors():
        loc = ".".join(str(x) for x in it.get("loc", []))
        msg = it.get("msg", "")
        typ = it.get("type", "")
        errs.append(f"{loc}: {msg} [{typ}]")
    return errs


def run_end_to_end_debug(
    *,
    spec_text: str,
    extract_prompt_path: str,
    fix_prompt_path: str,
    max_fix_iters: int,
    llm: Any,
    use_gold_as_context: int = 0,
    gold_filter: Any = None,  # not used in this self-contained pipeline
    auto_gold_rank: bool = False,
    gold_char_budget: int = 6000,
) -> Tuple[Dict[str, Any], FSM, str, List[str], str, str]:
    """
    Returns:
      (fsm_json_dict, fsm_obj, rendered_text, errors, last_prompt, last_raw)

    Contract:
    - errors is empty only if fully valid (schema+custom validation+render validation)
    - last_prompt/last_raw are always set to the last LLM call that happened.
    """
    extract_tpl = _read_text(extract_prompt_path)
    fix_tpl = _read_text(fix_prompt_path)

    gold_ctx = _build_gold_context(
        spec_text=spec_text,
        k=use_gold_as_context,
        auto_gold_rank=auto_gold_rank,
        gold_char_budget=gold_char_budget,
    )

    last_prompt = ""
    last_raw = ""

    def do_extract() -> Dict[str, Any]:
        nonlocal last_prompt, last_raw
        last_prompt = _fill_template(
            extract_tpl,
            {
                "GOLD_CONTEXT": gold_ctx,
                "SPEC": spec_text,
            },
        )
        last_raw = llm.complete(last_prompt)
        return _try_parse_fsm_json(last_raw)

    def do_fix(prev_json: Dict[str, Any], errs: List[str]) -> Dict[str, Any]:
        nonlocal last_prompt, last_raw
        last_prompt = _fill_template(
            fix_tpl,
            {
                "ERRORS": "\n".join(errs),
                "BAD_JSON": json.dumps(prev_json, ensure_ascii=False),
                "SPEC": spec_text,
                "GOLD_CONTEXT": gold_ctx,
            },
        )
        last_raw = llm.complete(last_prompt)
        return _try_parse_fsm_json(last_raw)

    # ---- main loop ----
    cur_json: Dict[str, Any] = {}
    all_errors: List[str] = []

    cur_json = do_extract()

    for it in range(max_fix_iters + 1):
        all_errors = []

        # 1) Pydantic / schema validation
        try:
            fsm = FSM.model_validate(cur_json)
        except ValidationError as e:
            all_errors.extend(_errors_from_validation_error(e))
            if it < max_fix_iters:
                cur_json = do_fix(cur_json, all_errors)
                continue
            # give up
            raise

        # 2) Custom FSM validation (graph constraints etc.)
        all_errors.extend(validate_fsm_object(fsm))

        # 3) Render + rendered-text validation (format)
        rendered = _render_fsm_text(fsm)
        all_errors.extend(validate_rendered_text(rendered, expected_states=list(fsm.states)))

        if all_errors and it < max_fix_iters:
            cur_json = do_fix(cur_json, all_errors)
            continue

        # Done (even if errors exist; caller will decide)
        return cur_json, fsm, rendered, all_errors, last_prompt, last_raw

    # unreachable
    return cur_json, fsm, _render_fsm_text(fsm), all_errors, last_prompt, last_raw  # type: ignore


def run_end_to_end(
    *,
    spec_text: str,
    extract_prompt_path: str,
    fix_prompt_path: str,
    max_fix_iters: int,
    llm: Any,
    use_gold_as_context: int = 0,
    auto_gold_rank: bool = False,
    gold_char_budget: int = 6000,
) -> Tuple[FSM, str, List[str]]:
    """
    Non-debug wrapper: returns (fsm_obj, rendered_text, errors).
    """
    _, fsm, text, errs, _, _ = run_end_to_end_debug(
        spec_text=spec_text,
        extract_prompt_path=extract_prompt_path,
        fix_prompt_path=fix_prompt_path,
        max_fix_iters=max_fix_iters,
        llm=llm,
        use_gold_as_context=use_gold_as_context,
        gold_filter=None,
        auto_gold_rank=auto_gold_rank,
        gold_char_budget=gold_char_budget,
    )
    return fsm, text, errs
