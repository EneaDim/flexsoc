from __future__ import annotations

import logging
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any, Callable, Dict, Optional

from .flow_config import FlowConfig
from .manifest import write_flow_manifest
from .registry import load_registry
from .reporting import parse_ip_start_flow, write_report_json
from .runner import MakeBackend

log = logging.getLogger(__name__)


@dataclass
class ExecResult:
    exit_code: int
    runner_run_dir: Path
    flow_run_dir: Optional[Path]


def _default_run_id() -> str:
    return datetime.now().strftime("%Y%m%d_%H%M%S")


def _postprocess_ip_start(*, flow_run_dir: Path, cfg: FlowConfig, action: str, params: Dict[str, Any]) -> None:
    """
    Postprocess implementation keyed by registry 'postprocess' string.
    Note: This function name mentions ip_start, but executor does NOT special-case the action id.
    """
    write_flow_manifest(
        flow_run_dir,
        action=action,
        top=str(cfg.top),
        run_id=str(cfg.run_id),
        workspace=cfg.resolved_workspace(),
        params=params,
    )
    report = parse_ip_start_flow(flow_run_dir)
    write_report_json(report, flow_run_dir / "report.json")


_POSTPROCESSORS: Dict[str, Callable[..., None]] = {
    "ip_start": _postprocess_ip_start,
}


def _action_meta(action_entry: Dict[str, Any]) -> Dict[str, Any]:
    """
    Extract action metadata with safe defaults.
    No knowledge of specific action ids.
    """
    def b(key: str, default: bool) -> bool:
        v = action_entry.get(key, default)
        return bool(v)

    return {
        "requires_top": b("requires_top", False),
        "requires_run_id": b("requires_run_id", False),
        "produces_outroot": b("produces_outroot", False),
        "postprocess": action_entry.get("postprocess", None),
    }


def execute_action(
    *,
    action: str,
    params: Dict[str, Any],
    workspace: Path,
    run_id: Optional[str] = None,
) -> ExecResult:
    """
    Pure execution layer. No Typer.

    Generic behavior driven by registry metadata:
    - WORKSPACE always enforced
    - requires_top / requires_run_id validated
    - produces_outroot => if TOP provided and RUN_ID missing, generate one
    - postprocess => optional post-run steps (manifest/report/etc.)
    """
    registry = load_registry()
    actions = registry.get("actions", {})
    if action not in actions:
        raise ValueError(f"Unknown action: {action}")

    action_entry = actions[action]
    if not isinstance(action_entry, dict) or "command" not in action_entry:
        raise ValueError(f"Invalid registry entry for action '{action}': missing 'command'")

    meta = _action_meta(action_entry)

    cmd = list(action_entry["command"])
    cfg = FlowConfig(workspace=workspace, top=params.get("top"), run_id=run_id)

    # Always enforce workspace (absolute)
    cmd.extend(cfg.to_make_vars())

    # Validate required fields
    if meta["requires_top"] and not cfg.top:
        raise ValueError(f"{action} requires params['top']")
    if meta["requires_run_id"] and not cfg.run_id:
        raise ValueError(f"{action} requires run_id")

    # Auto-run-id only if action produces outroot AND top is present AND run_id missing
    if meta["produces_outroot"] and cfg.top and not cfg.run_id and not meta["requires_run_id"]:
        cfg = cfg.with_run_id_if_needed(require=True)
        # ensure make sees the generated run id (vars already appended earlier)
        cmd.append(f"RUN_ID={cfg.run_id}")

    # Pass params as KEY=VALUE for make
    for k, v in params.items():
        if v is None:
            continue
        cmd.append(f"{k.upper()}={v}")

    log.debug(
        "execute_action: action=%s workspace=%s top=%s run_id=%s meta=%s",
        action,
        cfg.resolved_workspace(),
        cfg.top,
        cfg.run_id,
        meta,
    )
    log.debug("execute_action: cmd=%s", " ".join(str(x) for x in cmd))

    backend = MakeBackend()
    br = backend.run(action_id=action, cmd=cmd, params=params, workspace_dir=cfg.resolved_workspace())

    log.info("action_done: action=%s exit_code=%s runner_dir=%s", action, br.exit_code, br.run_dir)

    flow_run_dir: Optional[Path] = None

    post = meta["postprocess"]
    if post:
        fn = _POSTPROCESSORS.get(str(post))
        if fn is None:
            raise ValueError(f"Unknown postprocess '{post}' for action '{action}'")

        flow_run_dir = cfg.flow_run_dir()
        if flow_run_dir is None:
            raise RuntimeError(f"postprocess '{post}' requires top+run_id to resolve flow_run_dir")

        if not flow_run_dir.exists():
            candidates = (
                sorted((cfg.resolved_workspace() / "runs" / str(cfg.top)).glob("*"))
                if (cfg.resolved_workspace() / "runs" / str(cfg.top)).exists()
                else []
            )
            raise RuntimeError(
                f"Expected flow run dir missing: {flow_run_dir}. Existing: {[c.name for c in candidates]}"
            )

        fn(flow_run_dir=flow_run_dir, cfg=cfg, action=action, params=params)
        log.debug("postprocess=%s done in %s", post, flow_run_dir)

    return ExecResult(exit_code=br.exit_code, runner_run_dir=br.run_dir, flow_run_dir=flow_run_dir)
