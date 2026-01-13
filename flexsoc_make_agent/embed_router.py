#!/usr/bin/env python3
from __future__ import annotations
import json, math, urllib.request, argparse, re
from pathlib import Path

OLLAMA_URL="http://localhost:11434/api/embeddings"

def embed(model: str, text: str):
    payload = json.dumps({"model": model, "prompt": text}).encode("utf-8")
    req = urllib.request.Request(OLLAMA_URL, data=payload, headers={"Content-Type":"application/json"})
    with urllib.request.urlopen(req, timeout=60) as r:
        out = json.loads(r.read().decode("utf-8"))
    return out["embedding"]

def dot(a,b): return sum(x*y for x,y in zip(a,b))
def norm(a): return math.sqrt(sum(x*x for x in a))
def cosine(a,b):
    na, nb = norm(a), norm(b)
    if na == 0 or nb == 0: return 0.0
    return dot(a,b) / (na*nb)

def contains_ip_help(q: str) -> bool:
    ql = q.lower()
    return ("ip" in ql) and (("help" in ql) or ("aiuto" in ql))

def contains_ip_quickstart(q: str) -> bool:
    ql = q.lower()
    return ("ip" in ql) and (("quickstart" in ql) or ("avvia" in ql) or ("inizial" in ql) or ("start" in ql))

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--embed-model", default="nomic-embed-text")
    ap.add_argument("--db", default="flexsoc_make_agent/data/targets_embeddings.json")
    ap.add_argument("--topk", type=int, default=5)
    ap.add_argument("--min-score", type=float, default=0.35)
    ap.add_argument("--soft-gap", type=float, default=0.03, help="If preferred target is within this score gap, pick it.")
    ap.add_argument("query", nargs="+")
    args = ap.parse_args()

    q = " ".join(args.query).strip()
    db = json.loads(Path(args.db).read_text(encoding="utf-8"))

    qvec = embed(args.embed_model, q)

    scored = []
    for it in db:
        s = cosine(qvec, it["embedding"])
        scored.append((s, it["target"], it.get("risk","low")))
    scored.sort(reverse=True, key=lambda x: x[0])

    top = scored[:args.topk]
    best = scored[0]
    chosen = best[1] if best[0] >= args.min_score else "help"

    # Tie-break rules (hybrid router)
    top_targets = {t:s for s,t,_ in top}

    if contains_ip_help(q) and "help_ip" in top_targets:
        if best[0] - top_targets["help_ip"] <= args.soft_gap:
            chosen = "help_ip"

    if contains_ip_quickstart(q) and "ip_start" in top_targets:
        if best[0] - top_targets["ip_start"] <= args.soft_gap:
            chosen = "ip_start"

    print(json.dumps({
        "query": q,
        "chosen": chosen,
        "best_score": round(best[0],4),
        "topk": [{"score": round(s,4), "target": t, "risk": r} for s,t,r in top]
    }, indent=2))

if __name__ == "__main__":
    main()
