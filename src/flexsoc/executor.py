from __future__ import annotations

import logging
import os
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
    Result of executing a registry action via MakeBackend.
    """
    exit_code: int
    runner_run_dir: Path
    flow_run_dir: Optional[Path]


def _default_run_id() -> str:
    # Stable timestamp-ish id (runner has its own separate run dir)
    return datetime.now().strftime("%Y%m%d_%H%M%S")


def _action_meta(action_entry: Dict[str, Any]) -> Dict[str, Any]:
    """
    Extract action metadata with safe defaults.
    Purely registry-driven; no action-id special cases.
    """
    def b(key: str, default: bool) -> bool:
        v = action_entry.get(key, default)
        return bool(v)

    return {
        "requires_top": b("requires_top", False),
        "requires_run_id": b("requires_run_id", False),
        "produces_outroot": b("produces_outroot", False),
    }


def _make_kv(k: str, v: Any) -> str:
    # Pass to make as KEY=VALUE (uppercased for convention)
    return f"{k.upper()}={v}"


def execute_action(
    *,
    action: str,
    params: Dict[str, Any],
    workspace: Path,
    run_id: Optional[str] = None,
) -> ExecResult:
    """
    Generic execution layer (no Typer / no Rich).

    Registry-driven behavior:
      - command: base command list (usually: make -C flow <target>)
      - requires_top / requires_run_id: validation
      - produces_outroot: if TOP present and RUN_ID missing and not required, generate one

    Contracts:
      - NEVER prints (stdout/stderr) directly (runner handles logs)
      - NEVER writes into flow/ (Makefile targets must honor WORKSPACE)
      - Returns runner dir and (if resolvable) flow run dir
    """
    # Normalize workspace ONCE, early, to avoid cwd-dependent paths later
    ws = Path(workspace).expanduser().resolve()

    # When invoking `make -C flow`, WORKSPACE must be relative to flow/ to keep generated artifacts portable
    repo_root = Path(__file__).resolve().parents[2]
    flow_dir = (repo_root / "flow").resolve()
    ws_for_make = os.path.relpath(ws, flow_dir)

    registry = load_registry()
    actions = registry.get("actions", {})
    if not isinstance(actions, dict) or action not in actions:
        raise ValueError(f"Unknown action: {action}")

    action_entry = actions[action]
    if not isinstance(action_entry, dict):
        raise ValueError(f"Invalid registry entry for action '{action}': expected mapping")

    if "command" not in action_entry:
        raise ValueError(f"Invalid registry entry for action '{action}': missing 'command'")

    base_cmd = action_entry["command"]
    if not isinstance(base_cmd, list) or not all(isinstance(x, (str, int, float)) for x in base_cmd):
        raise ValueError(f"Invalid registry entry for action '{action}': 'command' must be a list")

    meta = _action_meta(action_entry)

    top = params.get("top")
    cfg = FlowConfig(workspace=ws, top=top, run_id=run_id)

    # Validate required fields
    if meta["requires_top"] and not cfg.top:
        raise ValueError(f"{action} requires params['top']")
    if meta["requires_run_id"] and not cfg.run_id:
        raise ValueError(f"{action} requires run_id")

    # Auto-generate run_id if action produces outroot, top is available, and run_id not required
    if meta["produces_outroot"] and cfg.top and not cfg.run_id and not meta["requires_run_id"]:
        cfg = FlowConfig(workspace=ws, top=cfg.top, run_id=_default_run_id())

    # Build command:
    # - start from registry command
    # - always enforce workspace/top/run_id via FlowConfig make vars
    # - then pass remaining params as uppercase make vars
    cmd: list[str] = [str(x) for x in base_cmd]
    # Enforce WORKSPACE/TOP/RUN_ID for make-based flows
    if cmd and cmd[0] == "make":
        # If registry command targets flow/ via -C flow, keep WORKSPACE relative to flow/
        use_rel = (len(cmd) >= 3 and cmd[1] == "-C" and str(cmd[2]) == "flow")
        cmd.append(f"WORKSPACE={ws_for_make}" if use_rel else f"WORKSPACE={ws}")
        if cfg.top:
            cmd.append(f"TOP={cfg.top}")
        if cfg.run_id:
            cmd.append(f"RUN_ID={cfg.run_id}")

    # Pass params as KEY=VALUE (skip Nones; do not override FlowConfig vars)
    for k, v in params.items():
        if v is None:
            continue
        ku = k.upper()
        if ku in ("WORKSPACE", "TOP", "RUN_ID"):
            continue
        cmd.append(_make_kv(k, v))

    log.debug(
        "execute_action: action=%s ws=%s top=%s run_id=%s meta=%s",
        action,
        ws,
        cfg.top,
        cfg.run_id,
        meta,
    )
    log.debug("execute_action: cmd=%s", " ".join(cmd))

    backend = MakeBackend()
    br = backend.run(
        action_id=action,
        cmd=cmd,
        params=params,
        workspace_dir=ws,
    )

    # Flow run dir is only meaningful when we can resolve it (top+run_id)
    flow_run_dir = cfg.flow_run_dir() if (cfg.top and cfg.run_id) else None

    log.info("action_done: action=%s exit_code=%s runner_dir=%s", action, br.exit_code, br.run_dir)

    return ExecResult(
        exit_code=br.exit_code,
        runner_run_dir=br.run_dir,
        flow_run_dir=flow_run_dir,
    )
