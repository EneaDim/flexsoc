#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import socket
import subprocess
import sys
import time
import urllib.request
from pathlib import Path

EXIT_WORDS = {"/exit", "/quit", ":q", "quit", "exit"}

BANNER = r"""
FlexSoC Embedding Agent
- Type a natural language command and press Enter to execute.
- Exit with: /exit  (also: /quit, :q, quit, exit)

Examples:
  help me
  start
  run view
  syn
""".strip()


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

    # already healthy?
    try:
        _ = http_get(f"{base_url}/health", timeout_s=1)
        return None
    except Exception:
        pass

    # port taken but not healthy -> do not guess
    if is_listening(host, port):
        raise RuntimeError(
            f"Port {port} is in use but {base_url}/health is not responding. "
            f"Stop that process or choose another port (--port 8100)."
        )

    # start in background, log to file
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


def runner_run_raw(python: str, runner_py: Path, cwd: Path, repo_root: Path, catalog: Path, cmd_json: str, timeout_s: int, dry_run: bool) -> int:
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

        # 1) Route
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

        # 2) Validate + Run (RAW streaming via runner.py --raw)
        cmd = {"action": "make", "target": chosen, "vars": {}, "make_flags": [], "cwd": "."}
        cmd_json = json.dumps(cmd, ensure_ascii=False)

        try:
            runner_validate(python, runner_py, repo_root, catalog, cmd_json)
        except Exception as e:
            print(f"ERROR: validation failed: {e}", file=sys.stderr)
            continue

        rc = runner_run_raw(
            python=python,
            runner_py=runner_py,
            cwd=repo_root,
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

