#!/usr/bin/env python3
from __future__ import annotations

import os
import argparse
import json
import socket
import subprocess
import sys
import time
import datetime
import re
import urllib.request
import shlex
from pathlib import Path
from typing import List, Tuple
import glob

EXIT_WORDS = {"/exit", "/quit", ":q", "quit", "exit"}

BANNER = r"""
FlexSoC Embedding Agent
- Type a natural language command and press Enter to execute Make targets.
- Built-in shell-lite commands: ll, ls, cd, pwd, cat, head, tail, g, h, gvim
- Exit with: /exit  (also: /quit, :q, quit, exit)

Examples:
  help me
  start
  run view
  syn

""".strip()

# Block obvious shell injection. (We do NOT use shell=True anyway, but keep it strict.)
DANGEROUS_CHARS = set(";|&><`$(){}[]\\")


# ---------------- HTTP helpers ----------------
def http_get(url: str, timeout_s: int = 2) -> str:
    with urllib.request.urlopen(url, timeout=timeout_s) as r:
        return r.read().decode("utf-8")


def http_post_json(url: str, payload: dict, timeout_s: int = 10) -> dict:
    data = json.dumps(payload).encode("utf-8")
    req = urllib.request.Request(
        url, data=data, headers={"Content-Type": "application/json"}, method="POST"
    )
    with urllib.request.urlopen(req, timeout=timeout_s) as r:
        return json.loads(r.read().decode("utf-8"))


def is_listening(host: str, port: int) -> bool:
    try:
        with socket.create_connection((host, port), timeout=0.5):
            return True
    except Exception:
        return False


def wait_health(base_url: str, timeout_s: float = 6.0) -> bool:
    t0 = time.time()
    while time.time() - t0 < timeout_s:
        try:
            _ = http_get(f"{base_url}/health", timeout_s=1)
            return True
        except Exception:
            time.sleep(0.1)
    return False

def snapshot_log_dir(repo_root: Path) -> dict[str, float]:
    log_dir = repo_root / "log"
    snap: dict[str, float] = {}
    if not log_dir.exists():
        return snap
    for p in log_dir.rglob("*"):
        if p.is_file():
            try:
                rel = str(p.relative_to(repo_root))  # es: "log/test_lint.log"
                snap[rel] = p.stat().st_mtime
            except OSError:
                pass
    return snap

def diff_log_snapshot(before: dict[str, float], after: dict[str, float]) -> list[str]:
    """
    Return list of files that are new or modified (mtime increased).
    """
    changed: list[str] = []
    for path, mtime_after in after.items():
        mtime_before = before.get(path)
        if mtime_before is None or mtime_after > mtime_before + 1e-6:
            changed.append(path)
    changed.sort(key=lambda p: after.get(p, 0.0), reverse=True)  # newest first
    return changed

def ensure_dir(p: Path) -> None:
    p.mkdir(parents=True, exist_ok=True)

def make_run_id(target: str) -> str:
    # Zulu-ish, filesystem safe
    ts = datetime.datetime.utcnow().strftime("%Y-%m-%dT%H-%M-%SZ")
    return f"{ts}_{target}"

def write_run_record(runs_dir: Path, record: dict) -> Path:
    ensure_dir(runs_dir)
    out = runs_dir / f"{record['id']}.json"
    out.write_text(json.dumps(record, indent=2, ensure_ascii=False), encoding="utf-8")
    return out

def list_run_records(runs_dir: Path) -> list[Path]:
    if not runs_dir.exists():
        return []
    files = sorted(runs_dir.glob("*.json"), key=lambda p: p.stat().st_mtime, reverse=True)
    return files

def load_json_file(p: Path) -> dict:
    return json.loads(p.read_text(encoding="utf-8"))

def get_last_run_record(runs_dir: Path, prefer_failed: bool = False) -> dict | None:
    for p in list_run_records(runs_dir):
        try:
            rec = load_json_file(p)
            if prefer_failed and rec.get("exit_code", 0) == 0:
                continue
            return rec
        except Exception:
            continue
    return None

def pick_logs_for_analysis(rec: dict, repo_root: Path, max_files: int = 3) -> list[Path]:
    paths = [Path(p) for p in (rec.get("flow_logs") or [])]
    # keep only existing files under repo
    good: list[Path] = []
    for p in paths:
        pp = (repo_root / p) if not p.is_absolute() else p
        if pp.exists() and pp.is_file():
            good.append(pp)

    def rank(p: Path) -> tuple[int, float]:
        s = p.name
        pri = 2
        if s.endswith(".errors"):
            pri = 0
        elif s.endswith(".log"):
            pri = 1
        elif s.endswith(".warnings"):
            pri = 3
        return (pri, -(p.stat().st_mtime if p.exists() else 0.0))

    good.sort(key=rank)
    return good[:max_files]

# ---------------- Router server management ----------------
def ensure_router_server(
    python: str,
    router_py: Path,
    cwd: Path,
    host: str,
    port: int,
    db: str,
    embed_model: str,
    topk: int,
    min_score: float,
    soft_gap: float,
) -> subprocess.Popen | None:
    """
    Ensure `router.py serve` is running.
    Returns Popen handle if started by us, else None.
    """
    base_url = f"http://{host}:{port}"

    # Already healthy?
    try:
        _ = http_get(f"{base_url}/health", timeout_s=1)
        return None
    except Exception:
        pass

    # Port in use but not healthy -> don't guess
    if is_listening(host, port):
        raise RuntimeError(
            f"Port {port} is in use but {base_url}/health is not responding. "
            f"Stop that process or choose another port (--port 8100)."
        )

    # Start in background, log to file
    log_dir = cwd / "flexsoc_make_agent" / "logs"
    log_dir.mkdir(parents=True, exist_ok=True)
    log_path = log_dir / "router_server.log"
    log_f = open(log_path, "a", encoding="utf-8")

    cmd = [
        python,
        str(router_py),
        "serve",
        "--host",
        host,
        "--port",
        str(port),
        "--db",
        db,
        "--embed-model",
        embed_model,
        "--topk",
        str(topk),
        "--min-score",
        str(min_score),
        "--soft-gap",
        str(soft_gap),
    ]
    p = subprocess.Popen(cmd, cwd=str(cwd), stdout=log_f, stderr=log_f, text=True)

    if not wait_health(base_url, timeout_s=6.0):
        try:
            p.terminate()
        except Exception:
            pass
        raise RuntimeError(
            f"Started router server but {base_url}/health did not become ready. "
            f"Check {log_path}"
        )

    return p


def route_query(base_url: str, user_text: str) -> dict:
    return http_post_json(f"{base_url}/route", {"query": user_text}, timeout_s=20)


# ---------------- Runner calls ----------------
def runner_validate(python: str, runner_py: Path, cwd: Path, catalog: Path, cmd_json: str) -> None:
    p = subprocess.run(
        [python, str(runner_py), "validate", "--json", cmd_json, "--catalog", str(catalog), "--quiet-json"],
        cwd=str(cwd),
        text=True,
        capture_output=True,
    )
    if p.returncode != 0:
        msg = (p.stderr or "").strip() or (p.stdout or "").strip() or "validation_failed"
        raise RuntimeError(msg)


def runner_run_raw(
    python: str,
    runner_py: Path,
    cwd: Path,
    repo_root: Path,
    catalog: Path,
    cmd_json: str,
    timeout_s: int,
    dry_run: bool,
) -> int:
    cmd = [
        python,
        str(runner_py),
        "run",
        "--json",
        cmd_json,
        "--repo-root",
        str(repo_root),
        "--catalog",
        str(catalog),
        "--timeout-s",
        str(timeout_s),
        "--raw",
    ]
    if dry_run:
        cmd.append("--dry-run")

    p = subprocess.run(cmd, cwd=str(cwd), text=True)
    return p.returncode


# ---------------- Shell-lite ----------------
def has_dangerous_chars(s: str) -> bool:
    return any(c in s for c in DANGEROUS_CHARS)


def resolve_in_repo(repo_root: Path, base_dir: Path, user_path: str) -> Path:
    """
    Resolve user_path relative to base_dir inside repo_root.
    Reject escaping outside repo_root.
    """
    rr = repo_root.resolve()
    p = (base_dir / user_path).resolve()
    if rr == p or rr in p.parents:
        return p
    raise ValueError(f"path escapes repo: {user_path}")


def run_cmd(argv: List[str], cwd: Path) -> int:
    # No shell. Direct exec.
    p = subprocess.run(argv, cwd=str(cwd), text=True)
    return p.returncode


def is_shell_lite_command(cmd: str) -> bool:
    return cmd in {"ll", "ls", "pwd", "cd", "cat", "head", "tail", "g", "grep", "h", "history", "gvim", "vim"}


def try_shell_lite(line: str, repo_root: Path, state: dict) -> bool:
    """
    Handle a small, safe set of read-only shell-ish commands + gvim.
    Returns True if handled, False to fall back to agent routing.
    """
    if not line:
        return True

    if has_dangerous_chars(line):
        return False

    try:
        toks = shlex.split(line)
    except Exception:
        return False

    if not toks:
        return True

    cmd = toks[0]
    args = toks[1:]
    cwd: Path = state["cwd"]

    # Only treat as shell-lite if first token matches whitelist
    if not is_shell_lite_command(cmd):
        return False

    # aliases
    if cmd == "ll":
        cmd = "ls"
        args = ["-la"] + args

    # history
    if cmd in {"h", "history"}:
        for i, x in enumerate(state["history"], 1):
            print(f"{i:4d}  {x}")
        return True

    # pwd
    if cmd == "pwd":
        print(str(cwd))
        return True

    # cd <path>
    if cmd == "cd":
        dest = args[0] if args else "."
        try:
            new_cwd = resolve_in_repo(repo_root, cwd, dest)
        except Exception as e:
            print(f"cd: {e}", file=sys.stderr)
            return True
        if not new_cwd.exists() or not new_cwd.is_dir():
            print(f"cd: no such directory: {dest}", file=sys.stderr)
            return True
        state["cwd"] = new_cwd
        return True

    # ls [path] (limited flags)
    if cmd == "ls":
        allowed_flags = {"-l", "-la", "-a", "-lh", "-lah", "-h"}
        flags = [a for a in args if a.startswith("-")]
        if any(f not in allowed_flags for f in flags):
            print("ls: unsupported flags", file=sys.stderr)
            return True

        # choose last non-flag as path, else "."
        path = "."
        for a in args:
            if not a.startswith("-"):
                path = a
        target = resolve_in_repo(repo_root, cwd, path)
        argv = ["ls"] + flags + [str(target)]
        run_cmd(argv, cwd=repo_root)
        return True

    # cat/head/tail
    if cmd in {"cat", "head", "tail"}:
        if not args:
            print(f"{cmd}: missing file", file=sys.stderr)
            return True

        file_path = args[0]
        try:
            p = resolve_in_repo(repo_root, cwd, file_path)
        except Exception as e:
            print(f"{cmd}: {e}", file=sys.stderr)
            return True
        if not p.exists() or not p.is_file():
            print(f"{cmd}: no such file: {file_path}", file=sys.stderr)
            return True

        if cmd == "cat":
            run_cmd(["cat", str(p)], cwd=repo_root)
            return True

        # head/tail optional N
        n = "50"
        if len(args) >= 2 and args[1].isdigit():
            n = args[1]
        run_cmd([cmd, "-n", n, str(p)], cwd=repo_root)
        return True

    # g <pattern> [path] -> grep -RIn -- <pattern> <path>
    if cmd in {"g", "grep"}:
        if not args:
            print("g: usage: g <pattern> [path]", file=sys.stderr)
            return True
        pattern = args[0]
        path = args[1] if len(args) > 1 else "."
        try:
            p = resolve_in_repo(repo_root, cwd, path)
        except Exception as e:
            print(f"g: {e}", file=sys.stderr)
            return True
        run_cmd(["grep", "-RIn", "--", pattern, str(p)], cwd=repo_root)
        return True

    # gvim <file> [more files...]
    if cmd in {"gvim", "vim"}:
        if not args:
            print("gvim: missing file", file=sys.stderr)
            return True
        files: List[str] = []
        for a in args:
            try:
                p = resolve_in_repo(repo_root, cwd, a)
            except Exception as e:
                print(f"gvim: {e}", file=sys.stderr)
                return True
            # allow creating new file only inside repo (still safe)
            parent = p.parent
            if not parent.exists():
                print(f"gvim: parent directory does not exist: {parent}", file=sys.stderr)
                return True
            files.append(str(p))

        exe = "gvim" if cmd == "gvim" else "vim"
        # Don't block REPL: spawn and return immediately
        try:
            subprocess.Popen([exe] + files, cwd=str(cwd))
        except FileNotFoundError:
            print(f"{exe}: not found. Install it or use another editor.", file=sys.stderr)
        return True

    # If we got here, we handled it (or it's unknown but whitelisted)
    return True

SHELL_LITE_CMDS = {"ll", "ls", "cd", "pwd", "cat", "head", "tail", "g", "grep", "h", "history", "gvim", "vim"}
REPL_CMDS = {"/help", "/exit", "/quit"}

def _list_dir_entries(base: Path, prefix: str) -> list[str]:
    """
    Return possible completions for prefix relative to base.
    Adds trailing '/' for directories.
    """
    # If prefix is empty, match everything
    pat = prefix + "*"
    # Use glob against filesystem
    matches = []
    for s in glob.glob(str((base / pat))):
        p = Path(s)
        name = p.name
        # If prefix included subdirs, keep that part
        # Example: prefix="rtl/to" -> completion should be "rtl/top.sv"
        if "/" in prefix or prefix.startswith("./"):
            # compute relative to base
            try:
                rel = p.relative_to(base)
                out = str(rel)
            except Exception:
                out = str(p)
        else:
            out = name

        if p.is_dir():
            out = out.rstrip("/") + "/"
        matches.append(out)

    # Sort for stable completion
    matches.sort()
    return matches

def install_readline_completion(repo_root: Path, state: dict) -> None:
    """
    Install TAB completion:
      - first token: completes shell-lite commands + /help,/exit
      - after certain commands: completes paths relative to current cwd (state["cwd"])
    """
    try:
        import readline
    except Exception:
        return

    def completer(text: str, state_idx: int) -> str | None:
        # Current buffer
        buf = readline.get_line_buffer()
        beg = readline.get_begidx()
        end = readline.get_endidx()

        # Tokenize safely (shlex may throw if quotes not closed)
        try:
            parts = shlex.split(buf[:beg])
        except Exception:
            parts = buf[:beg].split()

        # Are we completing first token?
        if not parts:
            options = sorted(SHELL_LITE_CMDS | REPL_CMDS)
            matches = [c for c in options if c.startswith(text)]
            return matches[state_idx] if state_idx < len(matches) else None

        cmd = parts[0]

        # If completing the command itself (still first token)
        if len(parts) == 1 and beg <= len(cmd):
            options = sorted(SHELL_LITE_CMDS | REPL_CMDS)
            matches = [c for c in options if c.startswith(text)]
            return matches[state_idx] if state_idx < len(matches) else None

        # Commands that should complete paths
        path_cmds = {"cd", "ls", "ll", "cat", "head", "tail", "gvim", "vim", "g", "grep"}
        if cmd in path_cmds:
            base = state["cwd"]
            # For grep: first arg is pattern, second is path
            if cmd in {"g", "grep"}:
                # if user is typing the pattern (first arg), do not complete paths yet
                # we start path completion from the 2nd argument
                # Example: "g TODO <TAB>" -> completes path, but "g <TAB>" shouldn't.
                if len(parts) < 2:
                    return None

            matches = _list_dir_entries(base, text)
            return matches[state_idx] if state_idx < len(matches) else None

        return None

    # Enable tab completion
    readline.set_completer(completer)

    # This is the key line: bind TAB to completion
    # GNU readline:
    try:
        readline.parse_and_bind("tab: complete")
    except Exception:
        pass

    # Better word delimiters: keep '/' as part of token
    try:
        readline.set_completer_delims(" \t\n")
    except Exception:
        pass

# ---------------- REPL ----------------
def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--repo-root", default=".")
    ap.add_argument("--catalog", default="flexsoc_make_agent/catalog.json")
    ap.add_argument("--router", default="flexsoc_make_agent/router.py")
    ap.add_argument("--runner", default="flexsoc_make_agent/runner.py")

    # Router server config
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--port", type=int, default=8099)
    ap.add_argument("--db", default="flexsoc_make_agent/data/targets_embeddings.json")
    ap.add_argument("--embed-model", default="nomic-embed-text")
    ap.add_argument("--topk", type=int, default=5)
    ap.add_argument("--min-score", type=float, default=0.35)
    ap.add_argument("--soft-gap", type=float, default=0.03)

    # Execution options
    ap.add_argument("--timeout-s", type=int, default=3600)
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--show-route", action="store_true", help="Print chosen target before running.")
    ap.add_argument(
        "--cd-affects-make",
        action="store_true",
        help="If set, make runs from the current shell-lite cwd.",
    )

    args = ap.parse_args()

    repo_root = Path(args.repo_root).resolve()
    catalog = (repo_root / args.catalog).resolve()
    router_py = (repo_root / args.router).resolve()
    runner_py = (repo_root / args.runner).resolve()

    if not repo_root.exists():
        print(f"ERROR: repo-root not found: {repo_root}", file=sys.stderr)
        raise SystemExit(2)
    if not catalog.exists():
        print(f"ERROR: catalog not found: {catalog}", file=sys.stderr)
        raise SystemExit(2)
    if not router_py.exists():
        print(f"ERROR: router.py not found: {router_py}", file=sys.stderr)
        raise SystemExit(2)
    if not runner_py.exists():
        print(f"ERROR: runner.py not found: {runner_py}", file=sys.stderr)
        raise SystemExit(2)

    # Ensure repo root is on sys.path so `import flexsoc_make_agent` works reliably
    repo_root_str = str(repo_root.resolve())
    if repo_root_str not in sys.path:
        sys.path.insert(0, repo_root_str)

    # readline optional
    try:
        import readline  # noqa: F401
    except Exception:
        pass

    python = sys.executable
    base_url = f"http://{args.host}:{args.port}"

    # shell-lite state
    state: Dict[str, Any] = {"cwd": repo_root, "history": []}
    install_readline_completion(repo_root, state)

    # Start router server if needed
    server_proc = None
    try:
        server_proc = ensure_router_server(
            python=python,
            router_py=router_py,
            cwd=repo_root,
            host=args.host,
            port=args.port,
            db=args.db,
            embed_model=args.embed_model,
            topk=args.topk,
            min_score=args.min_score,
            soft_gap=args.soft_gap,
        )
    except Exception as e:
        print(f"ERROR: {e}", file=sys.stderr)
        raise SystemExit(2)

    print(BANNER)

    while True:
        try:
            line = input("\nagent> ").strip()
        except (EOFError, KeyboardInterrupt):
            print("\n/exit")
            break

        if not line:
            continue

        low = line.lower().strip()
        if low in EXIT_WORDS:
            break

        state["history"].append(line)

        # shell-lite first
        if try_shell_lite(line, repo_root=repo_root, state=state):
            continue

        # -------------------------
        # Refiner commands: :why / :sum
        # -------------------------
        if line.startswith(":"):
            cmdline = line.strip().lower()
            if cmdline not in (":why", ":sum"):
                print("Unknown command. Available: :why, :sum", file=sys.stderr)
                continue

            runs_dir = repo_root / "flexsoc_make_agent" / "runs"
            # Always analyze the last run (same behavior for :why and :sum)
            rec = get_last_run_record(runs_dir, prefer_failed=False)            
            #rec = (
            #    get_last_run_record(runs_dir, prefer_failed=(cmdline == ":why"))
            #    or get_last_run_record(runs_dir, prefer_failed=False)
            #)
            if not rec:
                print("No runs found.", file=sys.stderr)
                continue

            logs = pick_logs_for_analysis(rec, repo_root, max_files=3)
            if not logs:
                log_dir = repo_root / "log"
                if log_dir.exists():
                    candidates = [
                        p for p in log_dir.iterdir()
                        if p.is_file() and p.name.endswith((".errors", ".warnings", ".log"))
                    ]
                    candidates.sort(key=lambda p: p.stat().st_mtime, reverse=True)
                    logs = candidates[:3]

            if not logs:
                print("No flow logs found to analyze.", file=sys.stderr)
                continue

            question = (
                "Explain each warning/error type with one short sentence."
                if cmdline == ":why"
                else "Return JSON only with keys: summary, error_summary, warning_summary."
            )

            try:
                from flexsoc_make_agent import refiner
                import importlib

                importlib.reload(refiner)

                use_llm = (cmdline == ":why")
                report = refiner.analyze(
                    rec,
                    logs,
                    user_question=question,
                    model="qwen2.5:0.5b",
                    head_lines=80,
                    tail_lines=120,
                    err_win=20,
                    max_windows=6,
                    max_bytes_per_file=400_000,
                    timeout_s=120,
                    use_llm=use_llm,
                )
            except Exception as e:
                print(f"ERROR: refiner failed: {e}", file=sys.stderr)
                continue

            # ----- Render -----
            summary = (report.get("summary") or "").strip()
            if summary:
                print(summary)

            if cmdline == ":why":
                status = report.get("status")
                if status:
                    print(f"\nStatus: {status}")

            err_sum = report.get("error_summary") or []
            warn_sum = report.get("warning_summary") or []

            llm_sent = report.get("llm_sentences") or {}
            w_sent: Dict[str, str] = llm_sent.get("warnings") or {}
            e_sent: Dict[str, str] = llm_sent.get("errors") or {}

            print("\nErrors:")
            if isinstance(err_sum, list) and err_sum:
                for it in err_sum[:50]:
                    if not isinstance(it, dict):
                        continue
                    t = it.get("type") or "unknown"
                    c = it.get("count")
                    ex = it.get("examples") or []
                    hdr = f"- {t}" + (f" (count={c})" if c is not None else "")
                    print(hdr)
                    for s in ex[:2]:
                        print(f"  * {s}")
                    if cmdline == ":why":
                        sent = (e_sent.get(t) or "").strip()
                        if sent:
                            print(f"  -> {sent}")
            else:
                print("- (none)")

            print("\nWarnings:")
            if isinstance(warn_sum, list) and warn_sum:
                for it in warn_sum[:50]:
                    if not isinstance(it, dict):
                        continue
                    t = it.get("type") or "unknown"
                    c = it.get("count")
                    ex = it.get("examples") or []
                    hdr = f"- {t}" + (f" (count={c})" if c is not None else "")
                    print(hdr)
                    for s in ex[:2]:
                        print(f"  * {s}")
                    if cmdline == ":why":
                        sent = (w_sent.get(t) or "").strip()
                        if sent:
                            print(f"  -> {sent}")
            else:
                print("- (none)")

            continue

        # -------------------------
        # Agent routing + Make execution
        # -------------------------
        try:
            route_obj = route_query(base_url, line)
        except Exception as e:
            print(f"ERROR: routing failed: {e}", file=sys.stderr)
            continue

        chosen = route_obj.get("chosen") or "help"
        vars_from_route = route_obj.get("vars") or {}
        if not isinstance(vars_from_route, dict):
            vars_from_route = {}

        if args.show_route:
            best = route_obj.get("best_score")
            reason = route_obj.get("override_reason") or ""
            vtxt = ""
            if vars_from_route:
                pairs = " ".join(f"{k}={vars_from_route[k]}" for k in sorted(vars_from_route))
                vtxt = f" [{pairs}]"
            print(f"[route] {chosen} (score={best}) {reason}{vtxt}".rstrip())

        rel_cwd = "."
        if args.cd_affects_make:
            try:
                rel_cwd = str(state["cwd"].resolve().relative_to(repo_root.resolve()))
            except Exception:
                rel_cwd = "."

        cmd = {
            "action": "make",
            "target": chosen,
            "vars": vars_from_route,
            "make_flags": [],
            "cwd": rel_cwd,
        }
        cmd_json = json.dumps(cmd, ensure_ascii=False)

        try:
            runner_validate(python, runner_py, repo_root, catalog, cmd_json)
        except Exception as e:
            print(f"ERROR: validation failed: {e}", file=sys.stderr)
            continue

        # Risk gating (only for high-risk targets)
        try:
            catalog_obj = json.loads(Path(catalog).read_text(encoding="utf-8"))
        except Exception as e:
            print(f"ERROR: failed to read catalog for risk gating: {e}", file=sys.stderr)
            continue

        risk = ((catalog_obj.get("targets") or {}).get(chosen) or {}).get("risk", "low")
        if (not args.dry_run) and risk == "high":
            v = cmd.get("vars") or {}
            f = cmd.get("make_flags") or []
            preview = " ".join(["make"] + list(f) + [chosen] + [f"{k}={v[k]}" for k in sorted(v)])
            print(f"⚠ high-risk target: {chosen}", file=sys.stderr)
            print(f"About to run: {preview}", file=sys.stderr)
            if input("Type 'y' to continue: ").strip().lower() != "y":
                print("Aborted.", file=sys.stderr)
                continue

        before_snap = snapshot_log_dir(repo_root)
        run_id = make_run_id(chosen)
        start_ts = int(time.time())

        rc = runner_run_raw(
            python=python,
            runner_py=runner_py,
            cwd=state["cwd"] if args.cd_affects_make else repo_root,
            repo_root=repo_root,
            catalog=catalog,
            cmd_json=cmd_json,
            timeout_s=args.timeout_s,
            dry_run=args.dry_run,
        )
        if rc != 0:
            print(f"(make exited with code {rc})", file=sys.stderr)

        end_ts = int(time.time())
        after_snap = snapshot_log_dir(repo_root)
        flow_logs = diff_log_snapshot(before_snap, after_snap)

        record = {
            "id": run_id,
            "ts_start": start_ts,
            "ts_end": end_ts,
            "target": chosen,
            "vars": cmd.get("vars") or {},
            "cwd": cmd.get("cwd"),
            "exit_code": rc,
            "flow_logs": flow_logs,
        }

        runs_dir = repo_root / "flexsoc_make_agent" / "runs"
        rec_path = write_run_record(runs_dir, record)

        if args.show_route:
            print(f"[run] saved record: {rec_path}", file=sys.stderr)

    # stop router server if we started it
    if server_proc is not None:
        try:
            server_proc.terminate()
        except Exception:
            pass

    print("Bye.")


if __name__ == "__main__":
    main()

