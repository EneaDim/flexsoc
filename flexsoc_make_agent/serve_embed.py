#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import re
import subprocess
import sys
import time
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent
RUNNER = ROOT / "runner.py"
LOGDIR = ROOT / "logs"
LOGDIR.mkdir(exist_ok=True)

OLLAMA_EMBED_URL = "http://localhost:11434/api/embeddings"

# ---------------- Embedding utils ----------------
def embed(model: str, text: str):
    payload = json.dumps({"model": model, "prompt": text}).encode("utf-8")
    req = urllib.request.Request(
        OLLAMA_EMBED_URL, data=payload, headers={"Content-Type": "application/json"}
    )
    with urllib.request.urlopen(req, timeout=60) as r:
        out = json.loads(r.read().decode("utf-8"))
    return out["embedding"]

def dot(a, b): return sum(x * y for x, y in zip(a, b))
def norm(a): return math.sqrt(sum(x * x for x in a))
def cosine(a, b):
    na, nb = norm(a), norm(b)
    if na == 0 or nb == 0:
        return 0.0
    return dot(a, b) / (na * nb)

# ---------------- Tie-break rules ----------------
def contains_ip_help(q: str) -> bool:
    ql = q.lower()
    return ("ip" in ql) and (("help" in ql) or ("aiuto" in ql))

def contains_quickstart(q: str) -> bool:
    ql = q.lower()
    return ("quickstart" in ql) or ("bootstrap" in ql) or ("inizial" in ql) or ("start" in ql)

def contains_ip_quickstart(q: str) -> bool:
    ql = q.lower()
    return ("ip" in ql) and contains_quickstart(q)

# ---------------- Explicit override (verbs + target) ----------------
EXEC_VERBS = r"(?:make|lancia|esegui|run|avvia|start|apri|mostra|visualizza)"
def explicit_target_override(user_text: str, allowed_targets: set[str]) -> str | None:
    """
    If user writes an explicit target after an execution verb, always use it.
    Examples:
      - "make view" / "lancia view" / "esegui view" / "run view"
      - "lancia path_view"
    Also disambiguates view vs path_view using presence of 'path' keywords.
    """
    lt = user_text.lower()
    wants_path = ("timing path" in lt) or ("critical path" in lt) or re.search(r"\bpath\b", lt) is not None

    m = re.search(rf"\b{EXEC_VERBS}\s+([A-Za-z0-9_\-]+)\b", user_text, flags=re.IGNORECASE)
    if m:
        t = m.group(1)
        if t in allowed_targets:
            if t == "view" and wants_path and "path_view" in allowed_targets:
                return "path_view"
            return t

    # If user only writes "view" alone, prefer view
    if re.fullmatch(r"\s*view\s*", lt) and "view" in allowed_targets:
        return "view"

    return None

# ---------------- Router ----------------
def choose_target(db, qvec, topk, min_score, soft_gap, user_text):
    scored = []
    for it in db:
        s = cosine(qvec, it["embedding"])
        scored.append((s, it["target"], it.get("risk", "low")))
    scored.sort(reverse=True, key=lambda x: x[0])

    top = scored[:topk]
    best = scored[0]
    chosen = best[1] if best[0] >= min_score else "help"

    top_targets = {t: s for s, t, _ in top}

    # If "ip"+"help", prefer help_ip if close enough
    if contains_ip_help(user_text) and "help_ip" in top_targets:
        if best[0] - top_targets["help_ip"] <= soft_gap:
            chosen = "help_ip"

    # If "quickstart" (even without ip), prefer ip_start if close enough
    if contains_quickstart(user_text) and "ip_start" in top_targets:
        if best[0] - top_targets["ip_start"] <= soft_gap:
            chosen = "ip_start"

    # If specifically ip quickstart, still prefer ip_start (same rule above, but ok)
    if contains_ip_quickstart(user_text) and "ip_start" in top_targets:
        if best[0] - top_targets["ip_start"] <= soft_gap:
            chosen = "ip_start"

    return chosen, best[0], top

# ---------------- Runner wrappers ----------------
def runner_validate(payload_text: str, catalog_path: Path, workdir: Path):
    res = subprocess.run(
        [sys.executable, str(RUNNER), "validate", "--json", payload_text, "--catalog", str(catalog_path)],
        capture_output=True, text=True, cwd=str(workdir)
    )
    return res.returncode, res.stdout, res.stderr

def runner_run(repo_root: Path, payload_text: str, catalog_path: Path, dry_run: bool, timeout_s: int, workdir: Path, tee_log: Path):
    cmd = [
        sys.executable, str(RUNNER), "run",
        "--json", payload_text,
        "--repo-root", str(repo_root),
        "--timeout-s", str(timeout_s),
        "--catalog", str(catalog_path),
        "--tee",
        "--tee-log", str(tee_log),
    ]
    if dry_run:
        cmd.append("--dry-run")
    # IMPORTANT: do NOT capture output in tee mode; runner itself prints JSON at end.
    res = subprocess.run(cmd, text=True, cwd=str(workdir), capture_output=True)
    return res.returncode, res.stdout, res.stderr

def save_logs(stem, user_text, route_obj, cmd_json, vout, verr, rout, rerr):
    base = LOGDIR / stem
    (base.with_suffix(".user.txt")).write_text(user_text, encoding="utf-8")
    (base.with_suffix(".route.json")).write_text(json.dumps(route_obj, indent=2), encoding="utf-8")
    (base.with_suffix(".cmd.json")).write_text(cmd_json, encoding="utf-8")
    (base.with_suffix(".validate.out")).write_text(vout, encoding="utf-8")
    (base.with_suffix(".validate.err")).write_text(verr, encoding="utf-8")
    (base.with_suffix(".run.out")).write_text(rout, encoding="utf-8")
    (base.with_suffix(".run.err")).write_text(rerr, encoding="utf-8")
    return base

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--repo-root", default=".")
    ap.add_argument("--catalog", default="flexsoc_make_agent/catalog.json")
    ap.add_argument("--db", default="flexsoc_make_agent/data/targets_embeddings.json")
    ap.add_argument("--embed-model", default="nomic-embed-text")
    ap.add_argument("--topk", type=int, default=5)
    ap.add_argument("--min-score", type=float, default=0.35)
    ap.add_argument("--soft-gap", type=float, default=0.03)
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--timeout-s", type=int, default=3600)
    ap.add_argument("request", nargs="+")
    args = ap.parse_args()

    workdir = Path.cwd()
    repo_root = (workdir / args.repo_root).resolve()
    catalog_path = (workdir / args.catalog).resolve()
    db_path = (workdir / args.db).resolve()

    user_text = " ".join(args.request).strip()
    db = json.loads(db_path.read_text(encoding="utf-8"))
    allowed_targets = {it["target"] for it in db}

    # 1) explicit override wins
    forced = explicit_target_override(user_text, allowed_targets)
    if forced is not None:
        chosen = forced
        best_score = 1.0
        top = [(1.0, forced, next((it.get("risk","low") for it in db if it["target"]==forced), "low"))]
    else:
        # 2) embedding router
        qvec = embed(args.embed_model, user_text)
        chosen, best_score, top = choose_target(db, qvec, args.topk, args.min_score, args.soft_gap, user_text)

    cmd = {"action": "make", "target": chosen, "vars": {}, "make_flags": [], "cwd": "."}
    cmd_json = json.dumps(cmd, ensure_ascii=False)

    stem = time.strftime("%Y%m%d-%H%M%S")
    tee_log = (LOGDIR / f"{stem}.tee.log")
    vcode, vout, verr = runner_validate(cmd_json, catalog_path, workdir)

    route_obj = {
        "chosen": chosen,
        "best_score": round(float(best_score), 4),
        "topk": [{"score": round(float(s),4), "target": t, "risk": r} for s, t, r in top],
        "override": forced is not None,
    }

    if vcode != 0:
        base = save_logs(stem, user_text, route_obj, cmd_json, vout, verr, "", "")
        # stdout: machine readable error
        sys.stdout.write(json.dumps({"ok": False, "error": "validation_failed", "details": verr.strip()}, ensure_ascii=False) + "\n")
        sys.stderr.write(f"Logs saved: {base}.*\n")
        raise SystemExit(2)

    rcode, rout, rerr = runner_run(repo_root, cmd_json, catalog_path, dry_run=args.dry_run, timeout_s=args.timeout_s, workdir=workdir, tee_log=tee_log)
    base = save_logs(stem, user_text, route_obj, cmd_json, vout, verr, rout, rerr)

    # IMPORTANT for webapp: stdout should be JSON only
    sys.stdout.write(rout if rout.endswith("\n") else rout + "\n")
    if rerr.strip():
        sys.stderr.write(rerr if rerr.endswith("\n") else rerr + "\n")
    sys.stderr.write(f"Logs saved: {base}.*\n")

if __name__ == "__main__":
    main()
