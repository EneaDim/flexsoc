#!/usr/bin/env python3
import json, urllib.request, sys
from pathlib import Path

OLLAMA_URL="http://localhost:11434/api/embeddings"

def embed(model: str, text: str):
    payload = json.dumps({"model": model, "prompt": text}).encode("utf-8")
    req = urllib.request.Request(OLLAMA_URL, data=payload, headers={"Content-Type":"application/json"})
    with urllib.request.urlopen(req, timeout=60) as r:
        out = json.loads(r.read().decode("utf-8"))
    return out["embedding"]

def main():
    model = sys.argv[1] if len(sys.argv)>1 else "nomic-embed-text"
    in_path = Path("flexsoc_make_agent/data/targets.json")
    out_path = Path("flexsoc_make_agent/data/targets_embeddings.json")

    items = json.loads(in_path.read_text(encoding="utf-8"))
    out = []
    for i,it in enumerate(items):
        text = f"target: {it['target']}\nrisk: {it.get('risk','low')}\ntext: {it['text']}"
        vec = embed(model, text)
        out.append({"target": it["target"], "risk": it.get("risk","low"), "text": it["text"], "embedding": vec})
        if (i+1) % 10 == 0:
            print(f"embedded {i+1}/{len(items)}")

    out_path.write_text(json.dumps(out), encoding="utf-8")
    print("Wrote", out_path)

if __name__ == "__main__":
    main()
