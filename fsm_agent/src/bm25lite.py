from __future__ import annotations
import math
import re
from collections import Counter
from typing import Dict, List, Tuple

STOP = {
    "il","lo","la","i","gli","le","un","una","uno","di","a","da","in","con","su","per","tra","fra",
    "e","o","ma","che","se","poi","quando","mentre","dopo","prima","come","piu","meno","molto",
    "the","a","an","and","or","but","if","then","else","when","while","after","before","to","of","in","on","for","with",
}

def tokenize(text: str) -> List[str]:
    # token semplici, include _ e numeri
    toks = re.findall(r"[a-z0-9_]+", text.lower())
    return [t for t in toks if t not in STOP and len(t) > 1]

def bm25_rank(query: str, docs: List[Tuple[str, str]], k1: float = 1.2, b: float = 0.75) -> List[Tuple[str, float]]:
    """
    docs: list of (doc_id, doc_text)
    returns: list of (doc_id, score) sorted desc
    """
    q_terms = tokenize(query)
    if not q_terms or not docs:
        return [(doc_id, 0.0) for (doc_id, _t) in docs]

    # preprocess docs
    doc_tokens: Dict[str, List[str]] = {}
    doc_tf: Dict[str, Counter] = {}
    doc_len: Dict[str, int] = {}
    df: Counter = Counter()

    for doc_id, text in docs:
        toks = tokenize(text)
        doc_tokens[doc_id] = toks
        tf = Counter(toks)
        doc_tf[doc_id] = tf
        doc_len[doc_id] = len(toks)
        for term in set(toks):
            df[term] += 1

    N = len(docs)
    avgdl = sum(doc_len.values()) / max(1, N)

    # idf with BM25 style smoothing
    def idf(term: str) -> float:
        n_qi = df.get(term, 0)
        return math.log(1.0 + (N - n_qi + 0.5) / (n_qi + 0.5))

    scores: Dict[str, float] = {doc_id: 0.0 for doc_id, _ in docs}
    for term in q_terms:
        term_idf = idf(term)
        for doc_id, _text in docs:
            tf = doc_tf[doc_id].get(term, 0)
            if tf == 0:
                continue
            dl = doc_len[doc_id]
            denom = tf + k1 * (1.0 - b + b * (dl / max(1e-9, avgdl)))
            scores[doc_id] += term_idf * (tf * (k1 + 1.0) / denom)

    ranked = sorted(scores.items(), key=lambda x: (-x[1], x[0]))
    return ranked
