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
from typing import Any


# ---------------- Catalog / Validation ----------------
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
        pat = (vars_allow[k].get("pattern") or "").strip()
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


# ---------------- Make argv ----------------
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


# ---------------- Execution helpers ----------------
def _ensure_log_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def run_stream_to_terminal(argv: list[str], cwd: Path, env: dict, timeout_s: int) -> int:
    """
    True streaming to terminal (stdout/stderr pass-through).
    No capture. Best for interactive / GUI targets.
    """
    try:
        p = subprocess.run(argv, cwd=str(cwd), env=env, text=True, timeout=timeout_s)
        return p.returncode
    except subprocess.TimeoutExpired:
        # Mimic common CLI timeout code
        sys.stderr.write(f"\n[runner] TIMEOUT after {timeout_s}s\n")
        sys.stderr.flush()
        return 124


def run_tee(argv: list[str], cwd: Path, env: dict, timeout_s: int, log_path: Path) -> dict:
    """
    Stream stdout/stderr live to terminal AND save to log_path.
    stderr is merged into stdout (2>&1) for a single chronological log.
    """
    _ensure_log_parent(log_path)
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
            bufsize=1,  # line-buffered
            universal_newlines=True,
        )

        out_lines: list[str] = []
        rc = 1
        try:
            assert proc.stdout is not None
            for line in proc.stdout:
                # live terminal
                sys.stdout.write(line)
                sys.stdout.flush()
                # tee file
                lf.write(line)
                lf.flush()
                # keep for JSON result
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


def run_capture(argv: list[str], cwd: Path, env: dict, timeout_s: int) -> dict:
    t0 = time.time()
    res = subprocess.run(
        argv, cwd=str(cwd), env=env, capture_output=True, text=True, timeout=timeout_s
    )
    elapsed = time.time() - t0
    return {
        "argv": argv,
        "cwd": str(cwd),
        "returncode": res.returncode,
        "stdout": res.stdout,
        "stderr": res.stderr,
        "elapsed_s": elapsed,
    }


def default_tee_log(repo_root: Path) -> Path:
    return repo_root / "flexsoc_make_agent" / "logs" / (time.strftime("%Y%m%d-%H%M%S") + ".tee.log")


def print_json(obj: dict[str, Any], quiet_json: bool) -> None:
    if quiet_json:
        return
    sys.stdout.write(json.dumps(obj, ensure_ascii=False) + ("\n" if not str(obj).endswith("\n") else ""))
    sys.stdout.flush()


# ---------------- CLI ----------------
def main() -> None:
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)

    # validate
    ap_v = sub.add_parser("validate", help="Validate a JSON command against catalog.json")
    ap_v.add_argument("--json", required=True)
    ap_v.add_argument("--catalog", required=True)
    ap_v.add_argument("--quiet-json", action="store_true", help="Do not print JSON output")

    # run
    ap_r = sub.add_parser("run", help="Run a validated make target")
    ap_r.add_argument("--json", required=True)
    ap_r.add_argument("--catalog", required=True)
    ap_r.add_argument("--repo-root", required=True)
    ap_r.add_argument("--timeout-s", type=int, default=3600)
    ap_r.add_argument("--dry-run", action="store_true")

    # Output modes
    ap_r.add_argument("--tee", action="store_true", help="Stream to terminal and also save a tee log")
    ap_r.add_argument("--tee-log", default="", help="Path for tee log (if --tee)")
    ap_r.add_argument(
        "--raw",
        action="store_true",
        help="Stream make output directly to terminal (no JSON wrapper). Best for REPL / GUIs.",
    )
    ap_r.add_argument(
        "--quiet-json",
        action="store_true",
        help="Do not print JSON result (useful with --tee; implied by --raw)",
    )

    args = ap.parse_args()
    catalog = load_catalog(Path(args.catalog))

    # ---------------- validate ----------------
    if args.cmd == "validate":
        try:
            cmd_obj = json.loads(args.json)
        except Exception as e:
            print_json({"ok": False, "error": f"invalid json: {e}"}, args.quiet_json)
            raise SystemExit(2)

        ok, msg = validate_cmd(cmd_obj, catalog)
        if ok:
            print_json({"ok": True}, args.quiet_json)
            raise SystemExit(0)

        print_json({"ok": False, "error": msg}, args.quiet_json)
        raise SystemExit(2)

    # ---------------- run ----------------
    try:
        cmd_obj = json.loads(args.json)
    except Exception as e:
        print_json({"ok": False, "error": f"invalid json: {e}"}, args.quiet_json)
        raise SystemExit(2)

    ok, msg = validate_cmd(cmd_obj, catalog)
    if not ok:
        print_json({"ok": False, "error": msg}, args.quiet_json or bool(getattr(args, "raw", False)))
        raise SystemExit(2)

    repo_root = Path(args.repo_root).resolve()
    cwd = (repo_root / cmd_obj.get("cwd", ".")).resolve()
    env = os.environ.copy()
    argv = build_make_argv(cmd_obj, args.dry_run)

    # raw implies quiet JSON
    quiet_json = bool(args.quiet_json) or bool(args.raw)

    # 1) RAW: best UX (streaming), no JSON
    if args.raw and not args.tee:
        rc = run_stream_to_terminal(argv, cwd=cwd, env=env, timeout_s=args.timeout_s)
        raise SystemExit(0 if rc == 0 else 1)

    # 2) TEE: streaming + logs, JSON optional
    if args.tee:
        log_path = Path(args.tee_log) if args.tee_log else default_tee_log(repo_root)
        result = run_tee(argv, cwd=cwd, env=env, timeout_s=args.timeout_s, log_path=log_path)
        print_json({"ok": result["returncode"] == 0, "results": [result]}, quiet_json)
        raise SystemExit(0 if result["returncode"] == 0 else 1)

    # 3) CAPTURE: machine-readable JSON (webapp)
    result = run_capture(argv, cwd=cwd, env=env, timeout_s=args.timeout_s)
    print_json({"ok": result["returncode"] == 0, "results": [result]}, quiet_json)
    raise SystemExit(0 if result["returncode"] == 0 else 1)


if __name__ == "__main__":
    main()

