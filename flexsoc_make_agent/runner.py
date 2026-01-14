#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

def load_catalog(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))

def validate_cmd(cmd: dict, catalog: dict) -> tuple[bool, str]:
    if not isinstance(cmd, dict):
        return False, "command must be a JSON object"
    if cmd.get("action") != "make":
        return False, 'command.action must be "make"'
    target = cmd.get("target")
    if not isinstance(target, str) or not target:
        return False, "command.target must be a non-empty string"

    targets = catalog.get("targets", {})
    if target not in targets:
        return False, f"target '{target}' not allowed"

    vars_allow = catalog.get("vars_allowlist", {})
    vars_obj = cmd.get("vars", {}) or {}
    if not isinstance(vars_obj, dict):
        return False, "command.vars must be an object"
    for k, v in vars_obj.items():
        if k not in vars_allow:
            return False, f"var '{k}' not allowed"
        pat = vars_allow[k].get("pattern", "")
        if pat and re.fullmatch(pat, str(v)) is None:
            return False, f"var '{k}' value '{v}' does not match pattern {pat}"

    flags_allow = set(catalog.get("make_flags_allowlist", []))
    flags = cmd.get("make_flags", []) or []
    if not isinstance(flags, list) or not all(isinstance(x, str) for x in flags):
        return False, "command.make_flags must be a list of strings"
    for f in flags:
        if f not in flags_allow:
            return False, f"make flag '{f}' not allowed"

    cwd = cmd.get("cwd", ".")
    if not isinstance(cwd, str):
        return False, "command.cwd must be a string"

    return True, "ok"

def build_make_argv(cmd: dict, dry_run: bool) -> list[str]:
    argv = ["make", "--no-print-directory"]
    if dry_run:
        argv.append("-n")
    argv.extend(cmd.get("make_flags", []) or [])
    argv.append(cmd["target"])
    # Vars as VAR=VALUE after target
    vars_obj = cmd.get("vars", {}) or {}
    for k, v in vars_obj.items():
        argv.append(f"{k}={v}")
    return argv

def tee_run(argv: list[str], cwd: Path, env: dict, timeout_s: int, log_path: Path) -> dict:
    """
    Stream stdout/stderr live to terminal AND save to log_path.
    stderr is merged into stdout (like 2>&1).
    """
    log_path.parent.mkdir(parents=True, exist_ok=True)
    t0 = time.time()

    with log_path.open("w", encoding="utf-8", errors="replace") as lf:
        lf.write(f"$ {' '.join(argv)}\n")
        lf.write(f"cwd: {cwd}\n\n")
        lf.flush()

        proc = subprocess.Popen(
            argv,
            cwd=str(cwd),
            env=env,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
            universal_newlines=True,
        )

        out_lines = []
        try:
            for line in proc.stdout:
                sys.stdout.write(line)
                sys.stdout.flush()
                lf.write(line)
                lf.flush()
                out_lines.append(line)
            rc = proc.wait(timeout=timeout_s)
        except subprocess.TimeoutExpired:
            proc.kill()
            rc = 124
            msg = f"\n[runner] TIMEOUT after {timeout_s}s\n"
            sys.stdout.write(msg)
            sys.stdout.flush()
            lf.write(msg)
            lf.flush()

    elapsed = time.time() - t0
    return {
        "argv": argv,
        "cwd": str(cwd),
        "returncode": rc,
        "stdout": "".join(out_lines),
        "stderr": "",
        "elapsed_s": elapsed,
        "log_file": str(log_path),
    }

def capture_run(argv: list[str], cwd: Path, env: dict, timeout_s: int) -> dict:
    t0 = time.time()
    res = subprocess.run(argv, cwd=str(cwd), env=env, capture_output=True, text=True, timeout=timeout_s)
    elapsed = time.time() - t0
    return {
        "argv": argv,
        "cwd": str(cwd),
        "returncode": res.returncode,
        "stdout": res.stdout,
        "stderr": res.stderr,
        "elapsed_s": elapsed,
    }

def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)

    ap_v = sub.add_parser("validate")
    ap_v.add_argument("--json", required=True)
    ap_v.add_argument("--catalog", required=True)

    ap_r = sub.add_parser("run")
    ap_r.add_argument("--json", required=True)
    ap_r.add_argument("--catalog", required=True)
    ap_r.add_argument("--repo-root", required=True)
    ap_r.add_argument("--timeout-s", type=int, default=3600)
    ap_r.add_argument("--dry-run", action="store_true")
    ap_r.add_argument("--tee", action="store_true")
    ap_r.add_argument("--tee-log", default="")
    ap_r.add_argument("--quiet-json", action="store_true", help="Do not print JSON result (raw terminal mode)")

    args = ap.parse_args()
    catalog = load_catalog(Path(args.catalog))

    if args.cmd == "validate":
        cmd = json.loads(args.json)
        ok, msg = validate_cmd(cmd, catalog)
        if ok:
            print(json.dumps({"ok": True}, ensure_ascii=False))
            raise SystemExit(0)
        print(json.dumps({"ok": False, "error": msg}, ensure_ascii=False))
        raise SystemExit(2)

    cmd = json.loads(args.json)
    ok, msg = validate_cmd(cmd, catalog)
    if not ok:
        if not args.quiet_json:
            print(json.dumps({"ok": False, "error": msg}, ensure_ascii=False))
        raise SystemExit(2)

    repo_root = Path(args.repo_root).resolve()
    cwd = (repo_root / cmd.get("cwd", ".")).resolve()
    env = os.environ.copy()

    argv = build_make_argv(cmd, args.dry_run)

    if args.tee:
        log_path = Path(args.tee_log) if args.tee_log else (repo_root / "flexsoc_make_agent" / "logs" / (time.strftime("%Y%m%d-%H%M%S") + ".tee.log"))
        result = tee_run(argv, cwd=cwd, env=env, timeout_s=args.timeout_s, log_path=log_path)
        if not args.quiet_json:
            print(json.dumps({"ok": result["returncode"] == 0, "results": [result]}, ensure_ascii=False))
        raise SystemExit(0 if result["returncode"] == 0 else 1)

    result = capture_run(argv, cwd=cwd, env=env, timeout_s=args.timeout_s)
    if not args.quiet_json:
        print(json.dumps({"ok": result["returncode"] == 0, "results": [result]}, ensure_ascii=False))
    raise SystemExit(0 if result["returncode"] == 0 else 1)

if __name__ == "__main__":
    main()
