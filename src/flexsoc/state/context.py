from __future__ import annotations

import json
from pathlib import Path
from typing import Any


_CONTEXT_FILE = Path(".flexsoc_context.json")


def context_file() -> Path:
    return _CONTEXT_FILE.resolve()


def load_context() -> dict[str, Any]:
    path = context_file()
    if not path.exists():
        return {}
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
        if isinstance(data, dict):
            return data
    except Exception:
        pass
    return {}


def save_context(
    *,
    workspace: Path | str | None = None,
    top: str | None = None,
    run_top: str | None = None,
    run_id: str | None = None,
) -> dict[str, Any]:
    current = load_context()

    if workspace is not None:
        current["workspace"] = str(Path(workspace).expanduser().resolve())
    if top is not None:
        current["top"] = top
    if run_top is not None:
        current["run_top"] = run_top
    if run_id is not None:
        current["run_id"] = run_id

    path = context_file()
    path.write_text(json.dumps(current, indent=2) + "\n", encoding="utf-8")
    return current


def clear_context() -> None:
    path = context_file()
    if path.exists():
        path.unlink()


def resolve_context(
    *,
    workspace: Path | None,
    top: str | None,
    run_top: str | None,
    run_id: str | None,
) -> tuple[Path | None, str | None, str | None, str | None]:
    current = load_context()

    ws = workspace
    if ws is None and current.get("workspace"):
        ws = Path(str(current["workspace"])).expanduser().resolve()

    top_eff = top if top is not None else current.get("top")
    run_top_eff = run_top if run_top is not None else current.get("run_top")
    run_id_eff = run_id if run_id is not None else current.get("run_id")

    return ws, top_eff, run_top_eff, run_id_eff
