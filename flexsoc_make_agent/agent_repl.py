#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import socket
import subprocess
import sys
import time
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
    ap.add_argument("--cd-affects-make", action="store_true", help="If set, make runs from the current shell-lite cwd.")

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

    # readline optional
    try:
        import readline  # noqa: F401
    except Exception:
        pass

    python = sys.executable
    base_url = f"http://{args.host}:{args.port}"

    # State for shell-lite
    state = {
        "cwd": repo_root,
        "history": [],
    }
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

        # record history (for h)
        state["history"].append(line)

        # shell-lite first
        if try_shell_lite(line, repo_root=repo_root, state=state):
            continue

        # --- Agent routing + Make execution ---
        try:
            route_obj = route_query(base_url, line)
        except Exception as e:
            print(f"ERROR: routing failed: {e}", file=sys.stderr)
            continue

        chosen = route_obj.get("chosen") or "help"
        if args.show_route:
            best = route_obj.get("best_score")
            reason = route_obj.get("override_reason") or ""
            print(f"[route] {chosen} (score={best}) {reason}".rstrip())

        # if you want `cd` to affect make, set cmd["cwd"] accordingly
        rel_cwd = "."
        if args.cd_affects_make:
            try:
                rel_cwd = str(state["cwd"].resolve().relative_to(repo_root.resolve()))
            except Exception:
                rel_cwd = "."

        cmd = {"action": "make", "target": chosen, "vars": {}, "make_flags": [], "cwd": rel_cwd}
        cmd_json = json.dumps(cmd, ensure_ascii=False)

        try:
            runner_validate(python, runner_py, repo_root, catalog, cmd_json)
        except Exception as e:
            print(f"ERROR: validation failed: {e}", file=sys.stderr)
            continue

        # run make with true streaming (runner.py --raw)
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

    # stop router server if we started it
    if server_proc is not None:
        try:
            server_proc.terminate()
        except Exception:
            pass

    print("Bye.")


if __name__ == "__main__":
    main()

