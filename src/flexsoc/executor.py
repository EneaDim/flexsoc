from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, Optional

from .manifest import write_flow_manifest
from .reporting import parse_ip_start_flow, write_report_json
from .registry import load_registry  # if you have it; otherwise we load yaml in cli and pass in
from .runner import run_command


@dataclass
class ExecResult:
    exit_code: int
    runner_run_dir: Path
    flow_run_dir: Optional[Path]


def execute_action(
    *,
    action: str,
    params: Dict[str, Any],
    workspace: Path,
    run_id: Optional[str] = None,
) -> ExecResult:
    """
    Pure execution layer. No Typer. Deterministic behavior:
    - For make-based flows, enforce WORKSPACE and (when required) RUN_ID.
    - Write flow manifest.json + report.json for ip_start.
    """
    ws = workspace.resolve()

    registry = load_registry()  # expects src/flexsoc/registry.py wrapper; if not present, replace accordingly
    actions = registry.get("actions", {})
    if action not in actions:
        raise ValueError(f"Unknown action: {action}")

    cmd = list(actions[action]["command"])

    # Deterministic run-id for ip_start (and any other action you decide)
    rid = run_id
    flow_run_dir: Optional[Path] = None

    if action == "ip_start":
        top_name = params.get("top")
        if not top_name:
            raise ValueError("ip_start requires params['top']")
        if not rid:
            raise ValueError("ip_start requires run_id for deterministic workspace outputs")

        cmd.append(f"WORKSPACE={ws}")
        cmd.append(f"RUN_ID={rid}")

    # pass params as KEY=VALUE for make (existing convention)
    # NOTE: keep values JSON-safe primitives
    for k, v in params.items():
        if v is None:
            continue
        cmd.append(f"{k.upper()}={v}")

    rr = run_command(action_id=action, cmd=cmd, params=params, workspace_dir=ws)

    if action == "ip_start":
        top_name = str(params["top"])
        flow_run_dir = ws / "runs" / top_name / str(rid)
        if not flow_run_dir.exists():
            candidates = sorted((ws / "runs" / top_name).glob("*")) if (ws / "runs" / top_name).exists() else []
            raise RuntimeError(f"Expected flow run dir missing: {flow_run_dir}. Existing: {[c.name for c in candidates]}")

        write_flow_manifest(
            flow_run_dir,
            action=action,
            top=top_name,
            run_id=str(rid),
            workspace=ws,
            params=params,
        )
        report = parse_ip_start_flow(flow_run_dir)
        write_report_json(report, flow_run_dir / "report.json")

    return ExecResult(exit_code=rr.exit_code, runner_run_dir=rr.run_dir, flow_run_dir=flow_run_dir)
