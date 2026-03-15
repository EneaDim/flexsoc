from __future__ import annotations

import logging
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, Optional

from ..state.workspace import RunRef
from .manifest import update_runner_manifest, write_flow_manifest, write_run_manifest
from .reporting import postprocess_action
from .runner import BackendResult, MakeBackend

log = logging.getLogger(__name__)


@dataclass(frozen=True)
class InvocationSpec:
    action_id: str
    summary_label: str
    cmd: list[str]
    params: Dict[str, Any]
    workspace_dir: Path
    cwd: Optional[Path] = None
    env: Optional[Dict[str, str]] = None
    timeout_s: Optional[int] = None
    run_ref: Optional[RunRef] = None
    manifest_action: Optional[str] = None
    manifest_top: Optional[str] = None
    manifest_run_id: Optional[str] = None
    postprocess: Optional[str] = None


@dataclass(frozen=True)
class OrchestratedResult:
    backend: BackendResult
    flow_run_dir: Optional[Path]


def _maybe_link_runner_manifest(
    spec: InvocationSpec,
    backend_result: BackendResult,
    flow_run_dir: Optional[Path],
) -> None:
    try:
        update_runner_manifest(
            backend_result.run_dir,
            {
                "workspace_dir": str(spec.workspace_dir),
                "flow_run_dir": str(flow_run_dir) if flow_run_dir else None,
                "run_top": spec.run_ref.run_top if spec.run_ref else None,
                "run_id": spec.run_ref.run_id if spec.run_ref else None,
                "top": spec.manifest_top,
                "manifest_action": spec.manifest_action or spec.action_id,
            },
        )
    except Exception:
        log.exception("failed to update runner manifest linkage")


def _maybe_write_manifests(
    spec: InvocationSpec,
    backend_result: BackendResult,
    flow_run_dir: Optional[Path],
) -> None:
    if spec.run_ref is None:
        return

    try:
        write_run_manifest(
            spec.run_ref,
            action=spec.manifest_action or spec.action_id,
            params=spec.params,
            top=spec.manifest_top,
            session_dir=backend_result.run_dir,
        )
    except Exception:
        log.exception("failed to write run manifest")

    if flow_run_dir is None:
        return
    if not spec.manifest_top or not spec.manifest_run_id:
        return

    try:
        write_flow_manifest(
            flow_run_dir,
            action=spec.manifest_action or spec.action_id,
            top=str(spec.manifest_top),
            run_id=str(spec.manifest_run_id),
            workspace=spec.workspace_dir,
            params=spec.params,
            runner_session_dir=backend_result.run_dir,
            runner_action_id=spec.action_id,
        )
    except Exception:
        log.exception("failed to write flow manifest")


def _maybe_postprocess(
    spec: InvocationSpec,
    backend_result: BackendResult,
    flow_run_dir: Optional[Path],
) -> None:
    if flow_run_dir is None:
        return

    try:
        effective_action = spec.postprocess or spec.manifest_action or spec.action_id
        postprocess_action(
            action=effective_action,
            flow_run_dir=flow_run_dir,
            runner_dir=backend_result.run_dir,
        )
    except Exception:
        log.exception("postprocess failed: %s", spec.postprocess or spec.manifest_action or spec.action_id)


def run_orchestrated(spec: InvocationSpec) -> OrchestratedResult:
    backend = MakeBackend()
    backend_result = backend.run(
        action_id=spec.action_id,
        cmd=spec.cmd,
        params=spec.params,
        workspace_dir=spec.workspace_dir,
        cwd=spec.cwd,
        env=spec.env,
        timeout_s=spec.timeout_s,
    )

    flow_run_dir = spec.run_ref.run_dir if spec.run_ref is not None else None

    _maybe_link_runner_manifest(spec, backend_result, flow_run_dir)
    _maybe_write_manifests(spec, backend_result, flow_run_dir)
    _maybe_postprocess(spec, backend_result, flow_run_dir)

    return OrchestratedResult(
        backend=backend_result,
        flow_run_dir=flow_run_dir,
    )
