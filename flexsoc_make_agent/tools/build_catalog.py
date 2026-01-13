#!/usr/bin/env python3
from __future__ import annotations
import argparse, json, re, pathlib, datetime

TARGET_RE = re.compile(r'^([A-Za-z0-9_.%/\- ]+)\s*:(?![=])')
VAR_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)\s*(\?=|:=|=)')

RISK_PATTERNS = {
  "high": [
    r'\bsudo\b', r'\bapt(-get)?\b', r'\bpip(3)?\b\s+install', r'\bcurl\b', r'\bwget\b',
    r'\bgit\s+clone\b', r'\brm\s+-rf\b', r'\bchmod\b', r'\bchown\b'
  ],
  "medium": [
    r'\byosys\b', r'\bverilator\b', r'\bvsim\b|\bquesta\b', r'\bvcs\b', r'\biverilog\b',
    r'\bfusesoc\b', r'\bsv2v\b', r'\bopenroad\b', r'\bsta\b'
  ]
}

def parse_targets(make_text: str):
  lines = make_text.splitlines()
  targets = {}
  current = None
  for i, l in enumerate(lines):
    m = TARGET_RE.match(l)
    if m and not l.strip().startswith('.'):
      tpart = m.group(1).strip()
      names = [t for t in re.split(r'\s+', tpart) if t]
      for t in names:
        if '%' in t:
          continue
        targets.setdefault(t, {"deps_decl": l.split(':',1)[1].strip(), "recipe": [], "decl_line": i+1})
      current = names[0] if names else None
      continue
    if current and l.startswith('\t'):
      targets[current]["recipe"].append(l.lstrip())
    else:
      if current and not l.startswith('\t'):
        current = None
  return targets

def classify_risk(target: str, recipe_lines: list[str]) -> str:
  if target == "help" or target.startswith("help_"):
    return "low"
  txt = " ".join(recipe_lines)
  for p in RISK_PATTERNS["high"]:
    if re.search(p, txt):
      return "high"
  for p in RISK_PATTERNS["medium"]:
    if re.search(p, txt):
      return "medium"
  if target.startswith("clean"):
    return "medium"
  return "low"

def parse_vars(cfg_text: str):
  out = {}
  for l in cfg_text.splitlines():
    s = l.strip()
    if not s or s.startswith("#"):
      continue
    m = VAR_RE.match(s)
    if m:
      out[m.group(1)] = m.group(2)
  return out

def main():
  ap = argparse.ArgumentParser()
  ap.add_argument("--makefile", required=True)
  ap.add_argument("--config", required=True)
  ap.add_argument("--out", required=True)
  args = ap.parse_args()

  make_text = pathlib.Path(args.makefile).read_text(encoding="utf-8")
  cfg_text  = pathlib.Path(args.config).read_text(encoding="utf-8")

  targets = parse_targets(make_text)
  for t in targets:
    targets[t]["risk"] = classify_risk(t, targets[t]["recipe"])

  cfg_vars = parse_vars(cfg_text)

  # Starter vars allowlist: expand as needed
  vars_allowlist = {
    "TOP":        {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Top/IP name"},
    "FSM":        {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "FSM name"},
    "HOST":       {"pattern": r"^[A-Za-z0-9_\-\.]+$", "desc": "Host identifier"},
    "VSV":        {"pattern": r"^(sv|v)$",           "desc": "Verilog flavor: sv or v"},
    "MODULE":     {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Module name"},
    "TARGET_SYN": {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Synthesis target"},
    "TARGET_OPT": {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Optimization target"},
    "ACTIVITY":   {"pattern": r"^[0-9]*\.?[0-9]+$", "desc": "Toggle activity (float)"},
    "NPATHS":     {"pattern": r"^[0-9]+$",          "desc": "Number of timing paths (int)"}
  }

  catalog = {
    "repo": "flexsoc",
    "generated_at": datetime.datetime.utcnow().isoformat() + "Z",
    "default_cwd": ".",
    "make_flags_allowlist": ["-j", "--no-print-directory", "-n"],
    "vars_allowlist": vars_allowlist,
    "config_vars_detected": sorted(cfg_vars.keys()),
    "targets": {}
  }

  for t, info in sorted(targets.items()):
    catalog["targets"][t] = {
      "desc": "",
      "risk": info["risk"],
      "decl_line": info["decl_line"],
      "deps_decl": info["deps_decl"],
    }

  pathlib.Path(args.out).write_text(json.dumps(catalog, indent=2), encoding="utf-8")
  print(f"Wrote catalog to {args.out} with {len(catalog['targets'])} targets.")

if __name__ == "__main__":
  main()
