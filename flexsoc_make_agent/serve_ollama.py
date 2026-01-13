#!/usr/bin/env python3
from __future__ import annotations
import argparse, json, subprocess, time, pathlib, sys

ROOT = pathlib.Path(__file__).resolve().parent
CATALOG = ROOT / "catalog.json"
RUNNER  = ROOT / "runner.py"
LOGDIR  = ROOT / "logs"
LOGDIR.mkdir(exist_ok=True)

def load_catalog():
    return json.loads(CATALOG.read_text(encoding="utf-8"))

def slice_catalog(cat, max_targets=120):
    keys = list(cat["targets"].keys())
    preferred = [k for k in keys if k == "help" or k.startswith("help_")]
    for k in ["ip_start", "setup", "deps"]:
        if k in cat["targets"] and k not in preferred:
            preferred.append(k)
    rest = [k for k in keys if k not in preferred]
    keep = preferred + rest[: max(0, max_targets - len(preferred))]
    targets = {k: cat["targets"][k] for k in keep}
    return {
        "targets": targets,
        "vars_allowlist": cat.get("vars_allowlist", {}),
        "make_flags_allowlist": cat.get("make_flags_allowlist", []),
        "default_cwd": cat.get("default_cwd", ".")
    }

def build_prompt(user_text, cat_slice, validator_error=None):
    targets_list = [{"name": k, "risk": v.get("risk","low")} for k,v in cat_slice["targets"].items()]
    vars_list = [{"name": k, "pattern": v.get("pattern","")} for k,v in cat_slice["vars_allowlist"].items()]
    payload = {
        "allowed_targets": targets_list,
        "allowed_vars": vars_list,
        "allowed_make_flags": cat_slice["make_flags_allowlist"],
        "user_request": user_text,
        "required_schema": {
            "single": {"action":"make","target":"<TARGET>","vars":{},"make_flags":[],"cwd":"."},
            "plan":   {"plan":[{"action":"make","target":"<TARGET>","vars":{},"make_flags":[],"cwd":"."}]}
        }
    }
    if validator_error:
        payload["validator_error"] = validator_error
        payload["instruction"] = "Fix your previous JSON to satisfy the validator error. Output ONLY corrected JSON."
    return json.dumps(payload, ensure_ascii=False)

def ollama_run(model, prompt_json):
    res = subprocess.run(["ollama", "run", model, prompt_json], capture_output=True, text=True)
    if res.returncode != 0:
        raise RuntimeError(res.stderr.strip() or "ollama run failed")
    return res.stdout.strip()

def normalize_llm_json(txt: str) -> str:
    try:
        obj = json.loads(txt)
    except Exception:
        return txt

    if isinstance(obj, dict):
        if obj.get("action") == "help":
            obj = {"action":"make","target":"help","vars":{},"make_flags":[],"cwd":"."}
            return json.dumps(obj, ensure_ascii=False)

        if obj.get("target") == "help" and obj.get("action") != "make":
            obj["action"] = "make"
            obj.setdefault("vars", {})
            obj.setdefault("make_flags", [])
            obj.setdefault("cwd", ".")
            return json.dumps(obj, ensure_ascii=False)

        if obj.get("action") == "make" and "target" not in obj:
            obj["target"] = "help"
            obj.setdefault("vars", {})
            obj.setdefault("make_flags", [])
            obj.setdefault("cwd", ".")
            return json.dumps(obj, ensure_ascii=False)

    return txt

def runner_validate(payload_text, workdir: pathlib.Path):
    res = subprocess.run(
        [sys.executable, str(RUNNER), "validate",
         "--json", payload_text,
         "--catalog", str(CATALOG)],
        capture_output=True, text=True,
        cwd=str(workdir)  # IMPORTANT: run from flexsoc root
    )
    return res.returncode, res.stdout, res.stderr

def runner_run(repo_root: pathlib.Path, payload_text, dry_run=False, timeout_s=3600, workdir: pathlib.Path|None=None):
    cmd = [
        sys.executable, str(RUNNER), "run",
        "--json", payload_text,
        "--repo-root", str(repo_root),
        "--timeout-s", str(timeout_s),
        "--catalog", str(CATALOG),
    ]
    if dry_run:
        cmd.append("--dry-run")
    res = subprocess.run(cmd, capture_output=True, text=True, cwd=str(workdir or repo_root))
    return res.returncode, res.stdout, res.stderr

def save_logs(stem, prompt, out, vout, verr, rout, rerr):
    base = LOGDIR / stem
    (base.with_suffix(".prompt.json")).write_text(prompt, encoding="utf-8")
    (base.with_suffix(".llm.txt")).write_text(out, encoding="utf-8")
    (base.with_suffix(".validate.out")).write_text(vout, encoding="utf-8")
    (base.with_suffix(".validate.err")).write_text(verr, encoding="utf-8")
    (base.with_suffix(".run.out")).write_text(rout, encoding="utf-8")
    (base.with_suffix(".run.err")).write_text(rerr, encoding="utf-8")
    return base

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--model", default="flexsoc-make")
    ap.add_argument("--repo-root", default=".")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--timeout-s", type=int, default=3600)
    ap.add_argument("--repair", action="store_true")
    ap.add_argument("request", nargs="+")
    args = ap.parse_args()

    # IMPORTANT: workdir = directory where YOU ran this command (should be flexsoc root)
    workdir = pathlib.Path.cwd()
    repo_root = (workdir / args.repo_root).resolve()

    user_text = " ".join(args.request)
    cat = load_catalog()
    cat_slice = slice_catalog(cat)

    stem = time.strftime("%Y%m%d-%H%M%S")
    prompt = build_prompt(user_text, cat_slice)

    out = ollama_run(args.model, prompt)
    out = normalize_llm_json(out)

    vcode, vout, verr = runner_validate(out, workdir=workdir)

    if vcode != 0 and args.repair:
        for _ in range(2):
            rp = build_prompt(user_text, cat_slice, validator_error=verr.strip())
            out2 = ollama_run(args.model, rp)
            out2 = normalize_llm_json(out2)
            vcode2, vout2, verr2 = runner_validate(out2, workdir=workdir)
            prompt, out, vcode, vout, verr = rp, out2, vcode2, vout2, verr2
            if vcode == 0:
                break

    if vcode != 0:
        base = save_logs(stem, prompt, out, vout, verr, "", "")
        print("❌ Validation failed")
        print(verr)
        print(f"Logs: {base}.*")
        raise SystemExit(2)

    rcode, rout, rerr = runner_run(repo_root, out, dry_run=args.dry_run, timeout_s=args.timeout_s, workdir=workdir)
    base = save_logs(stem, prompt, out, vout, verr, rout, rerr)

    print(rout)
    if rerr.strip():
        print("\nSTDERR:\n", rerr)
    print(f"\nLogs saved: {base}.*")

if __name__ == "__main__":
    main()
