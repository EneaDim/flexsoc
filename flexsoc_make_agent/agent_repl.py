#!/usr/bin/env python3
from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

EXIT_WORDS = {"/exit", "/quit", ":q", "quit", "exit"}

BANNER = r"""
FlexSoC Agent REPL
- Type a natural language command and press Enter to run.
- Exit with: /exit  (also: /quit, :q, quit, exit)
- Show help with: /help

Examples:
  avvia il quickstart dell'IP
  lancia view
  fai lint
  ip_start
"""

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--repo-root", default=".")
    ap.add_argument("--catalog", default="flexsoc_make_agent/catalog.json")
    ap.add_argument("--serve", default="flexsoc_make_agent/serve_embed.py")
    args = ap.parse_args()

    repo_root = Path(args.repo_root).resolve()
    catalog = (repo_root / args.catalog).resolve()
    serve = (repo_root / args.serve).resolve()

    if not serve.exists():
        print(f"ERROR: serve script not found: {serve}", file=sys.stderr)
        raise SystemExit(2)
    if not catalog.exists():
        print(f"ERROR: catalog not found: {catalog}", file=sys.stderr)
        raise SystemExit(2)

    try:
        import readline  # noqa: F401
    except Exception:
        pass

    print(BANNER.strip())

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
        cmd = [
            sys.executable, str(serve),
            "--repo-root", str(repo_root),
            "--catalog", str(catalog),
            "--raw",
            line,
        ]
        subprocess.run(cmd, cwd=str(repo_root))

    print("Bye.")

if __name__ == "__main__":
    main()
