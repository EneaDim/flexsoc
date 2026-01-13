#!/usr/bin/env python3
from __future__ import annotations
import argparse, json, subprocess, pathlib, sys

def read_jsonl(path: pathlib.Path):
    for line in path.read_text().splitlines():
        if line.strip():
            yield json.loads(line)

def call_ollama(model: str, prompt: str) -> str:
    res = subprocess.run(["ollama", "run", model, prompt], capture_output=True, text=True)
    if res.returncode != 0:
        raise RuntimeError(res.stderr.strip())
    return res.stdout.strip()

def runner_validate(runner_py: pathlib.Path, catalog: pathlib.Path, payload: str):
    res = subprocess.run(
        [sys.executable, str(runner_py), "validate",
         "--catalog", str(catalog),
         "--json", payload],
        capture_output=True, text=True
    )
    return res.returncode == 0

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--model", required=True)
    ap.add_argument("--catalog", required=True)
    ap.add_argument("--runner", required=True)
    ap.add_argument("--eval", required=True)
    args = ap.parse_args()

    total = json_ok = policy_ok = 0

    for ex in read_jsonl(pathlib.Path(args.eval)):
        total += 1
        user = next(m["content"] for m in ex["messages"] if m["role"] == "user")
        out = call_ollama(args.model, user)

        try:
            json.loads(out)
            json_ok += 1
        except Exception:
            continue

        if runner_validate(pathlib.Path(args.runner),
                           pathlib.Path(args.catalog),
                           out):
            policy_ok += 1

    print(json.dumps({
        "total": total,
        "json_valid_rate": json_ok / total if total else 0,
        "policy_valid_rate": policy_ok / total if total else 0
    }, indent=2))

if __name__ == "__main__":
    main()
