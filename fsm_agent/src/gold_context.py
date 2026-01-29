from __future__ import annotations
import glob
import json
import os
import re
from typing import List, Tuple, Optional

from .bm25lite import bm25_rank

def _read_text(path: str) -> str:
    with open(path, "r", encoding="utf-8") as f:
        return f.read().strip()

def _read_json(path: str) -> dict:
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def list_gold_names() -> List[str]:
    json_files = sorted(glob.glob("data/gold/json/*.json"))
    return [os.path.splitext(os.path.basename(p))[0] for p in json_files]

def _normalize_keywords(gold_filter: Optional[str]) -> List[str]:
    if not gold_filter:
        return []
    raw = re.split(r"[,\s]+", gold_filter.strip().lower())
    return [k for k in raw if k]

def _score_match(nl_text: str, js_obj: dict, keywords: List[str]) -> int:
    if not keywords:
        return 0
    blob = (nl_text + "\n" + json.dumps(js_obj, ensure_ascii=False)).lower()
    score = 0
    for kw in keywords:
        if kw in blob:
            score += 1
    return score

def _gold_doc_text(nl_text: str, js_obj: dict) -> str:
    return nl_text + "\n" + json.dumps(js_obj, ensure_ascii=False)

def load_gold_pairs(
    limit: int,
    gold_filter: Optional[str] = None,
    *,
    auto_rank: bool = False,
    rank_query: str = "",
) -> List[Tuple[str, str, dict]]:
    names = list_gold_names()
    keywords = _normalize_keywords(gold_filter)

    entries: List[Tuple[str, str, dict, int]] = []
    docs_for_rank: List[Tuple[str, str]] = []

    for name in names:
        nl_path = f"data/gold/nl/{name}.txt"
        js_path = f"data/gold/json/{name}.json"
        if not os.path.exists(nl_path) or not os.path.exists(js_path):
            continue
        nl = _read_text(nl_path)
        js = _read_json(js_path)

        if keywords:
            score = _score_match(nl, js, keywords)
            if score == 0:
                continue
            entries.append((name, nl, js, score))
        else:
            entries.append((name, nl, js, 0))
            docs_for_rank.append((name, _gold_doc_text(nl, js)))

    if keywords:
        entries.sort(key=lambda x: (-x[3], x[0]))
    elif auto_rank and rank_query.strip():
        ranked = bm25_rank(rank_query, docs_for_rank)
        score_map = {doc_id: score for doc_id, score in ranked}
        entries.sort(key=lambda x: (-score_map.get(x[0], 0.0), x[0]))
    else:
        entries.sort(key=lambda x: x[0])

    if limit > 0:
        entries = entries[:limit]

    return [(n, nl, js) for (n, nl, js, _s) in entries]

def _build_blocks(pairs: List[Tuple[str, str, dict]]) -> List[str]:
    blocks: List[str] = []
    for name, nl, js in pairs:
        blocks.append(
            "ESEMPIO " + name + "\n"
            "NL:\n" + nl + "\n"
            "JSON:\n" + json.dumps(js, indent=2, ensure_ascii=False) + "\n"
        )
    return blocks

def format_gold_context(
    limit: int,
    gold_filter: Optional[str] = None,
    *,
    auto_rank: bool = False,
    rank_query: str = "",
    char_budget: int = 12000,
) -> str:
    pairs = load_gold_pairs(limit=limit, gold_filter=gold_filter, auto_rank=auto_rank, rank_query=rank_query)
    if not pairs:
        if gold_filter:
            return f"(nessun golden trovato per filter='{gold_filter}')"
        return "(nessun golden fornito)"

    blocks = _build_blocks(pairs)

    # Apply char budget: append blocks until budget reached
    out_parts: List[str] = []
    used = 0
    sep = "\n---\n"

    for b in blocks:
        add_len = len(b) + (len(sep) if out_parts else 0)
        if char_budget > 0 and used + add_len > char_budget:
            break
        if out_parts:
            out_parts.append(sep)
            used += len(sep)
        out_parts.append(b)
        used += len(b)

    if not out_parts:
        # if budget too small, include at least the first block truncated (rare)
        b0 = blocks[0]
        if char_budget > 0 and len(b0) > char_budget:
            return b0[:char_budget]
        return b0

    # Add summary line
    included = sum(1 for p in out_parts if p not in (sep,))
    total = len(blocks)
    tail = f"\n(Usati {included}/{total} esempi golden; budget={char_budget} chars)\n"
    if char_budget <= 0:
        tail = f"\n(Usati {included}/{total} esempi golden; budget=disabilitato)\n"
    # respect budget for tail too
    if char_budget > 0 and used + len(tail) <= char_budget:
        out_parts.append(tail)

    return "".join(out_parts)
