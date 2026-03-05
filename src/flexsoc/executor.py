from __future__ import annotations

import logging
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, Optional

from .flow_config import FlowConfig
from .registry import load_registry
from .runner import MakeBackend

log = logging.getLogger(__name__)


@dataclass(frozen=True)
class ExecResult:
    """
    Result of a registry-driven action execution.
    - runner_run_dir: where runner logs live (stdout.log/stderr.log/manifest.json)
    - flow_run_dir:   where flow artifacts live (workspace/runs/<top>/<run_id>) if top+run_id are known
    """
    exit_code: int
    runner_run_dir: Path
    flow_run_dir: Optional[Path]


def _default_run_id() -> str:
    return datetime.now().strftime("%Y%m%d_%H%M%S")


def _action_meta(action_entry: Dict[str, Any]) -> Dict[str, Any]:
    def b(key: str, default: bool) -> bool:
        v = action_entry.get(key, default)
        return bool(v)

    return {
        "requires_top": b("requires_top", False),
        "requires_run_id": b("requires_run_id", False),
        "produces_outroot": b("produces_outroot", False),
        # postprocess removed on purpose: executor must be generic
    }


def _normalize_make_vars_from_params(params: Dict[str, Any]) -> list[str]:
    """
    Convert user params to make VAR=VALUE strings.

    Critical compatibility rules:
      - NEVER pass CLI-only 'force' into make vars
      - 'overwrite' must become OVERWRITE=--force when enabled,
        because flow scripts do: python ... $(OVERWRITE) ...
        and expect a flag, not "1".
    """
    out: list[str] = []

    for k, v in params.items():
        if v is None:
            continue

        if k == "force":
            continue

        if k == "overwrite":
            # Accept bool/int/string inputs and normalize to "--force" or empty
            if v is True or v == 1 or v == "1":
                out.append("OVERWRITE=--force")
                continue

            if isinstance(v, str):
                vv = v.strip()
                if vv == "":
                    continue
                if vv in ("-f", "--force"):
                    out.append("OVERWRITE=--force")
                    continue
                if vv == "1":
                    out.append("OVERWRITE=--force")
                    continue
                # Allow explicit flag-like string (backwards compat)
                out.append(f"OVERWRITE={vv}")
                continue

            # Fallback: any truthy non-string value
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
    """
    Generic execution layer (no Typer, no UI).

    Driven by registry metadata:
      - WORKSPACE always enforced (absolute)
      - requires_top / requires_run_id validated
      - produces_outroot => if top present and run_id missing and not required, generate one
      - NO postprocessing here (tool stays generic)
    """
    registry = load_registry()
    actions = registry.get("actions", {})
    if not isinstance(actions, dict) or action not in actions:
        raise ValueError(f"Unknown action: {action}")

    action_entry = actions[action]
    if not isinstance(action_entry, dict) or "command" not in action_entry:
        raise ValueError(f"Invalid registry entry for action '{action}': missing 'command'")

    cmd = list(action_entry["command"])
    meta = _action_meta(action_entry)

    # Workspace: user-friendly relative allowed at CLI, but execution must be stable
    ws_abs = Path(workspace).expanduser().resolve()

    # FlowConfig keeps topology info (top/run_id). It may compute flow_run_dir lazily.
    cfg = FlowConfig(workspace=ws_abs, top=params.get("top"), run_id=run_id)

    # Validate required fields
    if meta["requires_top"] and not cfg.top:
        raise ValueError(f"{action} requires params['top']")
    if meta["requires_run_id"] and not cfg.run_id:
        raise ValueError(f"{action} requires run_id")

    # Auto-run-id when action produces outroot AND top exists AND run_id missing AND run_id not required
    if meta["produces_outroot"] and cfg.top and not cfg.run_id and not meta["requires_run_id"]:
        cfg = cfg.with_run_id(_default_run_id())

    # Always enforce WORKSPACE (make var)
    # NOTE: keep this as absolute because many flows use make -C flow.
    cmd.append(f"WORKSPACE={ws_abs}")

    # If we know run_id/top, pass them too
    if cfg.top:
        cmd.append(f"TOP={cfg.top}")
    if cfg.run_id:
        cmd.append(f"RUN_ID={cfg.run_id}")

    # Add params-derived make vars (with overwrite normalization)
    cmd.extend(_normalize_make_vars_from_params(params))

    log.debug(
        "execute_action: action=%s ws=%s top=%s run_id=%s meta=%s",
        action,
        ws_abs,
        cfg.top,
        cfg.run_id,
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

    flow_run_dir = cfg.flow_run_dir()

    return ExecResult(
        exit_code=br.exit_code,
        runner_run_dir=br.run_dir,
        flow_run_dir=flow_run_dir,
    )
