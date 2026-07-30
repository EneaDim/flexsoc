"""Collect a compact, automatic manifest for one FlexSoC run."""

from __future__ import annotations

import argparse
import hashlib
import json
import platform
import subprocess
import tomllib
from importlib import metadata
from pathlib import Path
from typing import Sequence

from flexsoc.doctor import collect as collect_environment


def _git(root: Path, *args: str) -> str | None:
    """Return one Git command result, or None outside a Git checkout."""

    result = subprocess.run(
        ["git", "-C", str(root), *args],
        check=False,
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        return None
    return result.stdout.strip()


def _file_sha256(path: Path) -> str | None:
    """Return a SHA256 digest when the file exists."""

    if not path.is_file():
        return None
    return hashlib.sha256(path.read_bytes()).hexdigest()


def _flexsoc_version(repo_root: Path) -> str:
    """Return the installed or repository FlexSoC version."""

    try:
        return metadata.version("flexsoc")
    except metadata.PackageNotFoundError:
        pyproject = repo_root / "pyproject.toml"
        if not pyproject.is_file():
            return "unknown"
        data = tomllib.loads(pyproject.read_text(encoding="utf-8"))
        return str(data.get("project", {}).get("version", "unknown"))


def collect_manifest(
    *,
    top: str,
    run_top: str,
    run_id: str,
    repo_root: Path,
) -> dict[str, object]:
    """Collect run identity, source revision, environment, and tool versions."""

    environment = collect_environment(repo_root)
    commit = _git(repo_root, "rev-parse", "HEAD")
    status = _git(repo_root, "status", "--porcelain")
    tools = {
        item["executable"]: item["version"]
        for item in environment["tools"]
        if item["found"]
    }

    return {
        "schema_version": 1,
        "run": {
            "top": top,
            "run_top": run_top,
            "run_id": run_id,
        },
        "git": {
            "commit": commit,
            "dirty": None if status is None else bool(status),
        },
        "environment": {
            "flexsoc": _flexsoc_version(repo_root),
            "python": platform.python_version(),
            "uv_lock_sha256": _file_sha256(repo_root / "uv.lock"),
        },
        "tools": tools,
    }


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    """Parse the manifest collector command line."""

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--top", required=True)
    parser.add_argument("--run-top", required=True)
    parser.add_argument("--run-id", required=True)
    parser.add_argument("--repo-root", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    return parser.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    """Write the compact run manifest."""

    args = parse_args(argv)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    data = collect_manifest(
        top=args.top,
        run_top=args.run_top,
        run_id=args.run_id,
        repo_root=args.repo_root.resolve(),
    )
    args.output.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    print(f"[manifest] output: {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
