from __future__ import annotations

import logging
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, Optional

from .manifest import write_flow_manifest, write_run_manifest
from .registry import load_registry
from .reporting import postprocess_action
from .runner import MakeBackend
from .workspace import resolve_run_ref

log = logging.getLogger(__name__)


@dataclass(frozen=True)
class ExecResult:
    exit_code: int
    runner_run_dir: Path
    flow_run_dir: Optional[Path]


def _default_run_id() -> str:
    return datetime.now().strftime("%Y%m%d_%H%M%S")


def _action_meta(action_entry: Dict[str, Any]) -> Dict[str, Any]:
    def b(key: str, default: bool) -> bool:
        return bool(action_entry.get(key, default))

    return {
        "requires_top": b("requires_top", False),
        "requires_run_id": b("requires_run_id", False),
        "produces_outroot": b("produces_outroot", False),
    }


def _normalize_make_vars_from_params(params: Dict[str, Any]) -> list[str]:
    out: list[str] = []

    for k, v in params.items():
        if v is None:
            continue

        if k in {"force", "top", "run_top", "run_id"}:
            continue

        if k == "overwrite":
            if v is True or v == 1 or v == "1":
                out.append("OVERWRITE=--force")
                continue

            if isinstance(v, str):
                vv = v.strip()
                if not vv:
                    continue
                if vv in {"-f", "--force", "1"}:
                    out.append("OVERWRITE=--force")
                    continue
                out.append(f"OVERWRITE={vv}")
                continue

            if bool(v):
                out.append("OVERWRITE=--force")
            continue

        out.append(f"{k.upper()}={v}")

    return out


def execute_action(
    *,
    action: str,
    params: Dict[str, Any],
    workspace: Path,
    run_id: Optional[str] = None,
) -> ExecResult:
    registry = load_registry()
    actions = registry.get("actions", {})
    if not isinstance(actions, dict) or action not in actions:
        raise ValueError(f"Unknown action: {action}")

    action_entry = actions[action]
    if not isinstance(action_entry, dict) or "command" not in action_entry:
        raise ValueError(f"Invalid registry entry for action '{action}': missing 'command'")

    cmd = list(action_entry["command"])
    meta = _action_meta(action_entry)
    postprocess = action_entry.get("postprocess")

    ws_abs = Path(workspace).expanduser().resolve()
    top = params.get("top")
    run_top = params.get("run_top") or top
    effective_run_id = run_id

    if meta["requires_top"] and not top:
        raise ValueError(f"{action} requires params['top']")
    if meta["requires_run_id"] and not effective_run_id:
        raise ValueError(f"{action} requires run_id")

    if meta["produces_outroot"] and top and not effective_run_id:
        effective_run_id = _default_run_id()

    run_ref = resolve_run_ref(
        workspace=ws_abs,
        top=top,
        run_top=run_top,
        run_id=effective_run_id,
    )

    cmd.append(f"WORKSPACE={ws_abs}")
    if top:
        cmd.append(f"TOP={top}")
    if run_top:
        cmd.append(f"RUN_TOP={run_top}")
    if effective_run_id:
        cmd.append(f"RUN_ID={effective_run_id}")
    cmd.extend(_normalize_make_vars_from_params(params))

    log.debug(
        "execute_action: action=%s ws=%s top=%s run_top=%s run_id=%s meta=%s",
        action,
        ws_abs,
        top,
        run_top,
        effective_run_id,
        meta,
    )
    log.debug("execute_action: cmd=%s", " ".join(str(x) for x in cmd))

    backend = MakeBackend()
    br = backend.run(
        action_id=action,
        cmd=cmd,
        params=params,
        workspace_dir=ws_abs,
    )

    flow_run_dir = run_ref.run_dir if run_ref else None

    if run_ref is not None:
        try:
            write_run_manifest(
                run_ref,
                action=action,
                params=params,
                top=(top or run_top),
            )
        except Exception:
            log.exception("failed to write run manifest")

    manifest_top = top or run_top
    if flow_run_dir is not None and manifest_top and effective_run_id:
        try:
            write_flow_manifest(
                flow_run_dir,
                action=action,
                top=str(manifest_top),
                run_id=str(effective_run_id),
                workspace=ws_abs,
                params=params,
            )
        except Exception:
            log.exception("failed to write flow manifest")

        try:
            effective_postprocess = postprocess or action
            postprocess_action(
                action=effective_postprocess,
                flow_run_dir=flow_run_dir,
                runner_dir=br.run_dir,
            )
        except Exception:
            log.exception("postprocess failed: %s", postprocess or action)

    return ExecResult(
        exit_code=br.exit_code,
        runner_run_dir=br.run_dir,
        flow_run_dir=flow_run_dir,
    )
