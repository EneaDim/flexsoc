"""Resolve an existing FlexSoC run directory without guessing tool settings.

Only the filesystem run identity is derived. Clock domains, PDK, defines,
parameterization, and REG_ITF are deliberately *not* guessed from folder names.
"""
from __future__ import annotations

from pathlib import Path


def select_run(directory: Path) -> tuple[Path, dict[str, str]]:
    """Return (workspace, run identity) for workspace/runs/<owner>/<run-id>."""
    run = directory.expanduser().resolve(strict=True)
    if not run.is_dir():
        raise ValueError(f"not a FlexSoC run directory: {run}")
    if run.parent.parent.name != "runs" or not run.parent.name or not run.name:
        raise ValueError("expected a directory under workspace/runs/<run-top>/<run-id>")
    # Fail closed on an arbitrary directory named 'runs'. Existing IP runs
    # must carry at least one repository-owned artifact root.
    if not any((run / name).is_dir() for name in ("rtl", "meta", "dv")):
        raise ValueError(f"directory has no FlexSoC run artifacts: {run}")
    workspace = run.parent.parent.parent
    return workspace, {"TOP": run.parent.name, "RUN_TOP": run.parent.name,
                       "RUN_ID": run.name, "WORKSPACE": str(workspace)}
