"""Collect a compact, automatic manifest for one FlexSoC run."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import platform
import subprocess
import tomllib
from importlib import metadata
from pathlib import Path
from typing import Sequence

from rich.console import Console
from rich.table import Table

from flexsoc.doctor import collect as collect_environment
from flexsoc.run_layout import pdk_run_layout


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
    pdk = os.environ.get("FLEXSOC_PDK") or None
    run_root_value = os.environ.get("FLEXSOC_RUN_ROOT") or None
    artifact_paths: dict[str, str] | None = None
    if pdk and run_root_value:
        artifact_paths = pdk_run_layout(Path(run_root_value), pdk=pdk, top=top).as_dict()

    tools = {
        item["executable"]: {
            "version": item["version"],
            "path": item["path"],
            "version_ok": item.get("version_ok", True),
            "lock_match": item.get("lock_match"),
            "minimum_version": item.get("minimum_version"),
            "locked_version": item.get("locked_version"),
            "locked_ref": item.get("locked_ref"),
            "install_mode": item.get("install_mode"),
        }
        for item in environment["tools"]
        if item["found"]
    }

    return {
        "schema_version": 5,
        "run": {
            "top": top,
            "run_top": run_top,
            "run_id": run_id,
            "pdk": pdk,
            "run_root": run_root_value,
            "artifacts": artifact_paths,
        },
        "git": {
            "commit": commit,
            "dirty": None if status is None else bool(status),
        },
        "environment": {
            "flexsoc": _flexsoc_version(repo_root),
            "python": platform.python_version(),
            "platform": platform.platform(),
            "machine": platform.machine(),
            "uv_lock_sha256": _file_sha256(repo_root / "uv.lock"),
            "toolchain_lock_sha256": _file_sha256(repo_root / "src" / "flexsoc" / "backend" / "toolchain.lock"),
        },
        "toolchain": environment.get("toolchain_lock", {}),
        "tools": tools,
    }


def show_manifest(path: Path) -> None:
    """Render one run manifest as a compact colored terminal report."""

    if not path.is_file():
        raise FileNotFoundError(f"manifest file not found: {path}; run: fx manifest")
    data = json.loads(path.read_text(encoding="utf-8"))
    console = Console()
    run = data.get("run", {})
    console.print(
        f"[bold cyan]FlexSoC manifest[/bold cyan] — "
        f"{run.get('top', 'unknown')} / {run.get('run_id', 'unknown')}"
    )

    identity = Table(show_header=False, box=None, pad_edge=False)
    identity.add_column("Field", style="dim")
    identity.add_column("Value")
    identity.add_row("RUN_TOP", str(run.get("run_top", "-")))
    if run.get("pdk"):
        identity.add_row("PDK", str(run.get("pdk")))
    artifacts = run.get("artifacts")
    if isinstance(artifacts, dict):
        identity.add_row("Synthesis", str(artifacts.get("synthesis", "-")))
        identity.add_row("Equivalence", str(artifacts.get("equivalence", "-")))
    identity.add_row("Git commit", str(data.get("git", {}).get("commit") or "unavailable"))
    dirty = data.get("git", {}).get("dirty")
    dirty_text = "unknown" if dirty is None else ("dirty" if dirty else "clean")
    dirty_color = "yellow" if dirty else "green"
    identity.add_row("Git tree", f"[{dirty_color}]{dirty_text}[/{dirty_color}]")
    env = data.get("environment", {})
    identity.add_row("FlexSoC", str(env.get("flexsoc", "unknown")))
    identity.add_row("Python", str(env.get("python", "unknown")))
    identity.add_row("Platform", str(env.get("platform", "unknown")))
    identity.add_row("Machine", str(env.get("machine", "unknown")))
    identity.add_row("uv.lock", str(env.get("uv_lock_sha256") or "missing"))
    identity.add_row("toolchain.lock", str(env.get("toolchain_lock_sha256") or "missing"))
    console.print(identity)

    tools = data.get("tools", {})
    if tools:
        console.print("\n[bold cyan]Resolved tools[/bold cyan]")
        table = Table(box=None, pad_edge=False)
        table.add_column("Executable", style="bright_cyan")
        table.add_column("Version")
        for executable, value in sorted(tools.items()):
            if isinstance(value, dict):
                version = value.get("version", "unknown")
                lock_match = value.get("lock_match")
                locked = value.get("locked_version")
                suffix = ""
                if lock_match is False and locked:
                    suffix = f"  [dim](lock {locked})[/dim]"
                elif lock_match is True and locked:
                    suffix = f"  [dim](locked {locked})[/dim]"
                table.add_row(executable, f"{version}{suffix}")
            else:
                # Backward-compatible rendering for schema_version <= 2.
                table.add_row(executable, str(value))
        console.print(table)


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    """Parse the manifest collector command line."""

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--top")
    parser.add_argument("--run-top")
    parser.add_argument("--run-id")
    parser.add_argument("--repo-root", type=Path)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--show", type=Path)
    args = parser.parse_args(argv)
    if args.show is None and not all((args.top, args.run_top, args.run_id, args.repo_root, args.output)):
        parser.error("collection requires --top, --run-top, --run-id, --repo-root, and --output")
    return args


def main(argv: Sequence[str] | None = None) -> int:
    """Write the compact run manifest."""

    args = parse_args(argv)
    if args.show is not None:
        try:
            show_manifest(args.show)
        except (FileNotFoundError, json.JSONDecodeError) as exc:
            print(f"ERROR: {exc}")
            return 2
        return 0

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
