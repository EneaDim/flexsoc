from __future__ import annotations

import shutil
from pathlib import Path

from rich import print


def clean_run(workspace: Path, top: str, run_id: str) -> Path:
    run_dir = workspace / "runs" / top / run_id
    if run_dir.exists():
        shutil.rmtree(run_dir)
        print(f"[green]Removed[/green] {run_dir}")
    else:
        print(f"[yellow]Not found[/yellow] {run_dir}")
    return run_dir


def clean_workspace(workspace: Path) -> None:
    if workspace.exists():
        shutil.rmtree(workspace)
        print(f"[green]Removed[/green] {workspace}")
    else:
        print(f"[yellow]Not found[/yellow] {workspace}")
