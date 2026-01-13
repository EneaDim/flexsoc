#!/usr/bin/env python3
from __future__ import annotations
import argparse, json, random

SYSTEM_PROMPT = (
  "You are a make orchestrator for flexsoc. "
  "Reply ONLY with valid JSON that matches the schema. "
  "Do not include extra text. "
  "Targets must exist in the catalog. "
  "If the request is vague, prefer help or a help_* target."
)

TEMPLATES = {
  "help": ["Mostrami i comandi disponibili", "Che target make ci sono?", "Voglio vedere l'help generale",
           "Show me available make commands", "List the available targets"],
  "help_ip": ["Mi serve l'help per la parte IP", "Mostrami i comandi IP", "Help IP", "Show IP-related help"],
  "help_soc": ["Help SoC", "Mostrami i comandi per il SoC", "Che comandi ci sono per il SoC?"],
  "help_doc": ["Help documentazione", "Come genero la doc?", "Mostrami comandi per docs"],
  "help_fsm": ["Help FSM", "Che comandi ci sono per la FSM?", "Mostrami help fsm"],
  "ip_start": ["Avvia il quickstart per sviluppare un IP", "Esegui il flow base per l'IP",
               "Start IP flow", "Genera tutto per l'IP e fai lint e sim"],
  "setup": ["Prepara l'ambiente", "Setup del progetto", "Initialize the environment"],
  "deps": ["Installa le dipendenze", "Setup dependencies", "Install all dependencies"]
}

VAR_EXAMPLES = [{}, {"TOP":"my_ip"}, {"FSM":"my_fsm"}, {"VSV":"sv"}, {"VSV":"v"}, {"TOP":"my_ip","VSV":"sv"}]

def load_catalog(path: str):
  with open(path, "r", encoding="utf-8") as f:
    return json.load(f)

def assistant_obj(target: str, vars_obj: dict, risk: str):
  base = {"action":"make","target":target,"vars":vars_obj,"make_flags":[],"cwd":"."}
  if risk == "high":
    base["risk_ack"] = True
  return base

def main():
  ap = argparse.ArgumentParser()
  ap.add_argument("--catalog", required=True)
  ap.add_argument("--out", required=True)
  ap.add_argument("--n-per-target", type=int, default=30)
  ap.add_argument("--seed", type=int, default=7)
  args = ap.parse_args()
  random.seed(args.seed)

  cat = load_catalog(args.catalog)
  allowed_vars = set(cat.get("vars_allowlist", {}).keys())

  selected = [t for t in TEMPLATES.keys() if t in cat["targets"]]
  n = 0
  with open(args.out, "w", encoding="utf-8") as f:
    for t in selected:
      risk = cat["targets"][t].get("risk", "low")
      phrases = TEMPLATES[t]
      for i in range(args.n_per_target):
        user = random.choice(phrases)
        vv = random.choice(VAR_EXAMPLES)
        vv = {k:v for k,v in vv.items() if k in allowed_vars}
        assistant = assistant_obj(t, vv, risk)
        rec = {
          "id": f"seed-{t}-{i:04d}",
          "messages": [
            {"role":"system","content": SYSTEM_PROMPT},
            {"role":"user","content": user},
            {"role":"assistant","content": json.dumps(assistant, separators=(",",":"))}
          ],
          "meta": {"target": t, "risk": risk, "source":"seed"}
        }
        f.write(json.dumps(rec, ensure_ascii=False) + "\n")
        n += 1
  print(f"Wrote {n} examples to {args.out}")

if __name__ == "__main__":
  main()
