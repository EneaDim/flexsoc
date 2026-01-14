#!/usr/bin/env python3
import json
import sys
import urllib.request
from pathlib import Path

OLLAMA_URL = "http://localhost:11434/api/embeddings"

def embed(model: str, text: str):
    payload = json.dumps({"model": model, "prompt": text}).encode("utf-8")
    req = urllib.request.Request(
        OLLAMA_URL, data=payload, headers={"Content-Type": "application/json"}
    )
    with urllib.request.urlopen(req, timeout=120) as r:
        out = json.loads(r.read().decode("utf-8"))
    return out["embedding"]

def pack_for_embedding(target: str, risk: str, lang: str, et: dict) -> str:
    """
    Build a compact but semantically rich text for embeddings
    from embedding_text.<lang>.
    """
    title = (et.get("title") or "").strip()
    summary = (et.get("summary") or "").strip()
    queries = et.get("queries") or []
    keywords = et.get("keywords") or []
    negative = et.get("negative") or []

    q_block = "\n".join(f"- {q}".strip() for q in queries[:10] if str(q).strip())
    k_block = ", ".join(str(k).strip() for k in keywords[:25] if str(k).strip())
    n_block = ", ".join(str(n).strip() for n in negative[:15] if str(n).strip())

    parts = [f"target: {target}", f"risk: {risk}", f"lang: {lang}"]
    if title:
        parts.append(f"title: {title}")
    if summary:
        parts.append(f"summary: {summary}")
    if q_block:
        parts.append(f"user queries:\n{q_block}")
    if k_block:
        parts.append(f"keywords: {k_block}")
    if n_block:
        parts.append(f"avoid / not this: {n_block}")

    return "\n".join(parts)

def main():
    model = sys.argv[1] if len(sys.argv) > 1 else "nomic-embed-text"
    in_path = Path("flexsoc_make_agent/data/targets.json")
    out_path = Path("flexsoc_make_agent/data/targets_embeddings.json")

    items = json.loads(in_path.read_text(encoding="utf-8"))
    out = []

    for i, it in enumerate(items):
        target = it["target"]
        risk = it.get("risk", "low")
        depends_on = it.get("depends_on", [])

        et_all = it.get("embedding_text") or {}
        et_en = et_all.get("en") or {}
        et_it = et_all.get("it") or {}

        text_en = pack_for_embedding(target, risk, "en", et_en)
        text_it = pack_for_embedding(target, risk, "it", et_it)

        vec_en = embed(model, text_en)
        vec_it = embed(model, text_it)

        out.append(
            {
                "target": target,
                "risk": risk,
                "depends_on": depends_on,
                "embedding_en": vec_en,
                "embedding_it": vec_it,
            }
        )

        if (i + 1) % 10 == 0:
            print(f"embedded {i+1}/{len(items)}")

    out_path.write_text(json.dumps(out), encoding="utf-8")
    print("Wrote", out_path)

if __name__ == "__main__":
    main()

