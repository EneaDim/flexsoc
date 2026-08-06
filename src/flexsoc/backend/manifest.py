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
        candidates = pdk_run_layout(Path(run_root_value), pdk=pdk, top=top).as_dict()
        artifact_paths = {
            name: value
            for name, value in candidates.items()
            if Path(value).exists()
        }

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
    """Render run identity, artifacts, environment, and tools in flow order."""

    if not path.is_file():
        raise FileNotFoundError(f"manifest file not found: {path}; run: fx manifest")
    data = json.loads(path.read_text(encoding="utf-8"))
    console = Console()
    run = data.get("run", {})
    env = data.get("environment", {})
    console.print(
        "[bold orange1]FlexSoC manifest[/bold orange1] · "
        f"[bold bright_cyan]{run.get('top', 'unknown')} / "
        f"{run.get('run_id', 'unknown')}[/bold bright_cyan]"
    )

    def section(title: str, rows: list[tuple[str, object]]) -> None:
        console.print(f"\n[bold bright_cyan]{title}[/bold bright_cyan]")
        table = Table(show_header=False, box=None, pad_edge=False)
        table.add_column("Field", style="grey70", no_wrap=True)
        table.add_column("Value", style="white")
        for key, value in rows:
            table.add_row(key, str(value))
        console.print(table)

    dirty = data.get("git", {}).get("dirty")
    section(
        "Run",
        [
            ("TOP", run.get("top", "-")),
            ("RUN_TOP", run.get("run_top", "-")),
            ("RUN_ID", run.get("run_id", "-")),
            ("PDK", run.get("pdk") or "-"),
            ("RUN_ROOT", run.get("run_root") or "-"),
        ],
    )
    section(
        "Source / environment",
        [
            ("Git commit", data.get("git", {}).get("commit") or "unavailable"),
            (
                "Git tree",
                "unknown" if dirty is None else ("dirty" if dirty else "clean"),
            ),
            ("FlexSoC", env.get("flexsoc", "unknown")),
            ("Python", env.get("python", "unknown")),
            ("Platform", env.get("platform", "unknown")),
            ("Machine", env.get("machine", "unknown")),
            ("uv.lock SHA256", env.get("uv_lock_sha256") or "missing"),
            (
                "toolchain.lock SHA256",
                env.get("toolchain_lock_sha256") or "missing",
            ),
        ],
    )

    artifacts = run.get("artifacts")
    if isinstance(artifacts, dict):
        section(
            "Artifacts",
            [
                (name.replace("_", " ").title(), value)
                for name, value in artifacts.items()
            ],
        )

    tools = data.get("tools", {})
    if tools:
        groups = (
            ("RTL / lint", {"slang", "verilator", "slang-hier"}),
            (
                "Formal / equivalence",
                {"yosys", "sby", "eqy", "bitwuzla", "boolector", "btormc", "btorsim"},
            ),
            (
                "Simulation / debug",
                {"iverilog", "gtkwave", "fst2vcd", "surfer", "sv2v", "netlistsvg"},
            ),
            ("Implementation / sign-off", {"sta", "openroad", "klayout"}),
            ("Environment", {"uv"}),
        )
        for title, names in groups:
            rows = [(name, tools[name]) for name in sorted(names) if name in tools]
            if not rows:
                continue
            console.print(f"\n[bold bright_cyan]{title} tools[/bold bright_cyan]")
            table = Table(box=None, pad_edge=False, header_style="bold grey70")
            table.add_column("Executable", style="white")
            table.add_column("Version", style="grey70")
            table.add_column("Lock", style="grey70")
            for executable, value in rows:
                if isinstance(value, dict):
                    lock_match = value.get("lock_match")
                    locked = value.get("locked_version")
                    lock = (
                        "match"
                        if lock_match is True
                        else (
                            f"tested {locked}"
                            if lock_match is False and locked
                            else "-"
                        )
                    )
                    table.add_row(
                        executable,
                        str(value.get("version", "unknown")),
                        lock,
                    )
                else:
                    table.add_row(executable, str(value), "-")
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
