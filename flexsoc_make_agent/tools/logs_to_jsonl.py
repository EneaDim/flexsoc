#!/usr/bin/env python3
from __future__ import annotations
import argparse, json, pathlib

SYSTEM_PROMPT = (
  "You are a make orchestrator for flexsoc. "
  "Reply ONLY with valid JSON that matches the schema. "
  "Do not include extra text. "
  "Targets must exist in the catalog. "
  "If the request is vague, prefer help or a help_* target."
)

def infer_user_request(prompt_json_text: str) -> str:
  try:
    p = json.loads(prompt_json_text)
    return str(p.get("user_request","")).strip()
  except Exception:
    return ""

def load_json_maybe(path: pathlib.Path):
  try:
    return json.loads(path.read_text(encoding="utf-8"))
  except Exception:
    return None

def main():
  ap = argparse.ArgumentParser()
  ap.add_argument("--logs", required=True)
  ap.add_argument("--out", required=True)
  ap.add_argument("--require-success", action="store_true")
  args = ap.parse_args()

  logs = pathlib.Path(args.logs)
  outp = pathlib.Path(args.out)
  outp.parent.mkdir(parents=True, exist_ok=True)

  records = []
  for llm_path in sorted(logs.glob("*.llm.txt")):
    stem = llm_path.name.replace(".llm.txt","")
    prompt_path = logs / f"{stem}.prompt.json"
    vout_path   = logs / f"{stem}.validate.out"
    rout_path   = logs / f"{stem}.run.out"

    if not prompt_path.exists() or not vout_path.exists():
      continue

    user_req = infer_user_request(prompt_path.read_text(encoding="utf-8"))
    assistant_json = llm_path.read_text(encoding="utf-8").strip()

    vout = load_json_maybe(vout_path)
    if not isinstance(vout, dict) or not vout.get("ok", False):
      continue

    if args.require_success:
      run_obj = load_json_maybe(rout_path) if rout_path.exists() else None
      if not isinstance(run_obj, dict) or not run_obj.get("ok", False):
        continue

    records.append({
      "id": f"gold-{stem}",
      "messages": [
        {"role":"system","content": SYSTEM_PROMPT},
        {"role":"user","content": user_req},
        {"role":"assistant","content": assistant_json}
      ],
      "meta": {"source":"log", "stem": stem}
    })

  with outp.open("w", encoding="utf-8") as f:
    for r in records:
      f.write(json.dumps(r, ensure_ascii=False) + "\n")

  print(f"Wrote {len(records)} records to {outp}")

if __name__ == "__main__":
  main()
