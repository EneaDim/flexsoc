#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime
import json
import pathlib
import re

VAR_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)\s*(\?=|:=|=)')

# Starter vars allowlist: expand as needed (values validated by regex in runner)
DEFAULT_VARS_ALLOWLIST = {
  "TOP":        {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Top/IP name"},
  "FSM":        {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "FSM name"},
  "HOST":       {"pattern": r"^[A-Za-z0-9_\-\.]+$", "desc": "Host identifier"},
  "VSV":        {"pattern": r"^(sv|v)$",           "desc": "Verilog flavor: sv or v"},
  "MODULE":     {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Module name"},
  "TARGET_SYN": {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Synthesis target"},
  "TARGET_OPT": {"pattern": r"^[A-Za-z0-9_\-]+$", "desc": "Optimization target"},
  "ACTIVITY":   {"pattern": r"^[0-9]*\.?[0-9]+$", "desc": "Toggle activity (float)"},
  "NPATHS":     {"pattern": r"^[0-9]+$",          "desc": "Number of timing paths (int)"},
}

def parse_vars(cfg_text: str) -> dict[str, str]:
  out: dict[str, str] = {}
  for l in cfg_text.splitlines():
    s = l.strip()
    if not s or s.startswith("#"):
      continue
    m = VAR_RE.match(s)
    if m:
      out[m.group(1)] = m.group(2)
  return out

def load_targets_json(path: str) -> list[dict]:
  p = pathlib.Path(path)
  data = json.loads(p.read_text(encoding="utf-8"))
  if not isinstance(data, list):
    raise ValueError(f"{path} must be a JSON list")
  out: list[dict] = []
  for it in data:
    if isinstance(it, dict) and "target" in it:
      out.append(it)
  return out

def main():
  ap = argparse.ArgumentParser(description="Build catalog.json from targets.json (+ parse config.mk vars).")
  ap.add_argument("--targets", default="flexsoc_make_agent/data/targets.json",
    help="Path to targets.json (default: flexsoc_make_agent/data/targets.json)")
  ap.add_argument("--config", default="config.mk",
    help="Path to config.mk to detect available vars (default: config.mk)")
  ap.add_argument("--out", default="flexsoc_make_agent/catalog.json",
    help="Output catalog.json path (default: flexsoc_make_agent/catalog.json)")

  args = ap.parse_args()

  targets_list = load_targets_json(args.targets)

  cfg_text = pathlib.Path(args.config).read_text(encoding="utf-8")
  cfg_vars = parse_vars(cfg_text)

  # Build targets map purely from targets.json (makefile is NOT read)
  targets_map: dict[str, dict] = {}
  for it in targets_list:
    t = it.get("target")
    if not isinstance(t, str) or not t.strip():
      continue
    t = t.strip()

    # risk comes ONLY from targets.json; default to low if missing/invalid
    r = it.get("risk", "low")
    if r not in ("low", "medium", "high"):
      r = "low"

    # description (optional): pick something useful if present
    desc = ""
    emb = it.get("embedding_text.en") or {}
    if isinstance(emb, dict):
      title = emb.get("title")
      summary = emb.get("summary")
      if isinstance(title, str) and title.strip():
        desc = title.strip()
      elif isinstance(summary, str) and summary.strip():
        desc = summary.strip()

    targets_map[t] = {
      "desc": desc,
      "risk": r,
      "decl_line": None,
      "deps_decl": "",
    }

  catalog = {
    "repo": "flexsoc",
    "generated_at": datetime.datetime.utcnow().isoformat() + "Z",
    "default_cwd": ".",
    "make_flags_allowlist": ["-j", "--no-print-directory", "-n"],
    "vars_allowlist": DEFAULT_VARS_ALLOWLIST,
    "config_vars_detected": sorted(cfg_vars.keys()),
    "targets": dict(sorted(targets_map.items())),
  }

  pathlib.Path(args.out).write_text(json.dumps(catalog, indent=2, ensure_ascii=False), encoding="utf-8")
  print(f"Wrote catalog to {args.out} with {len(catalog['targets'])} targets.")

if __name__ == "__main__":
  main()

