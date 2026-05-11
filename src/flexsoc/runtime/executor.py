from __future__ import annotations

import logging
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, Optional

from ..catalog.registry import load_registry
from ..state.workspace import resolve_run_ref
from .orchestration import InvocationSpec, run_orchestrated

# Configura il logger per il modulo
log = logging.getLogger(__name__)

# Definizione di un risultato di esecuzione
@dataclass(frozen=True)
class ExecResult:
    """
    Rappresenta il risultato di un'azione eseguita.

    Attributes:
        exit_code (int): Il codice di uscita del processo.
        runner_run_dir (Path): La directory di esecuzione del runner.
        flow_run_dir (Optional[Path]): La directory di esecuzione del flusso, se presente.
    """
    exit_code: int
    runner_run_dir: Path
    flow_run_dir: Optional[Path]


def _default_run_id() -> str:
    """
    Genera un ID di esecuzione predefinito basato sulla data e ora corrente.

    Returns:
        str: L'ID di esecuzione nel formato 'YYYYMMDD_HHMMSS'.
    """
    return datetime.now().strftime("%Y%m%d_%H%M%S")


def _action_meta(action_entry: Dict[str, Any]) -> Dict[str, Any]:
    """
    Estrae i metadati di un'azione dal registro.

    Args:
        action_entry (Dict[str, Any]): L'entry dell'azione dal registro.

    Returns:
        Dict[str, Any]: Un dizionario con i metadati dell'azione.
    """
    def b(key: str, default: bool) -> bool:
        return bool(action_entry.get(key, default))

    return {
        "requires_top": b("requires_top", False),
        "requires_run_id": b("requires_run_id", False),
        "produces_outroot": b("produces_outroot", False),
    }


def _normalize_make_vars_from_params(params: Dict[str, Any]) -> list[str]:
    """
    Normalizza i parametri in variabili per il comando Make.

    Args:
        params (Dict[str, Any]): I parametri forniti.

    Returns:
        list[str]: Una lista di variabili Make normalizzate.
    """
    out: list[str] = []

    for k, v in params.items():
        if v is None:
            continue

        # Ignora parametri specifici
        if k in {"force", "top", "run_top", "run_id"}:
            continue

        # Gestisce il parametro 'overwrite'
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

        # Aggiunge altri parametri come variabili Make
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
    Esegue un'azione specifica utilizzando i parametri forniti.

    Args:
        action (str): L'ID dell'azione da eseguire.
        params (Dict[str, Any]): I parametri per l'azione.
        workspace (Path): La directory di lavoro.
        run_id (Optional[str]): L'ID di esecuzione, se fornito.

    Returns:
        ExecResult: Il risultato dell'esecuzione.
    """
    # Carica il registro delle azioni
    registry = load_registry()
    actions = registry.get("actions", {})
    if not isinstance(actions, dict) or action not in actions:
        raise ValueError(f"Unknown action: {action}")

    # Recupera l'entry dell'azione dal registro
    action_entry = actions[action]
    if not isinstance(action_entry, dict) or "command" not in action_entry:
        raise ValueError(f"Invalid registry entry for action '{action}': missing 'command'")

    # Prepara il comando e i metadati
    cmd = list(action_entry["command"])
    meta = _action_meta(action_entry)
    postprocess = action_entry.get("postprocess")

    # Risolve i percorsi e i parametri
    ws_abs = Path(workspace).expanduser().resolve()
    top = params.get("top")
    run_top = params.get("run_top") or top
    effective_run_id = run_id

    # Verifica i requisiti dei metadati
    if meta["requires_top"] and not top:
        raise ValueError(f"{action} requires params['top']")
    if meta["requires_run_id"] and not effective_run_id:
        raise ValueError(f"{action} requires run_id")

    # Genera un ID di esecuzione predefinito se necessario
    if meta["produces_outroot"] and top and not effective_run_id:
        effective_run_id = _default_run_id()

    # Risolve il riferimento di esecuzione
    run_ref = resolve_run_ref(
        workspace=ws_abs,
        top=top,
        run_top=run_top,
        run_id=effective_run_id,
    )

    # Costruisce il comando Make
    cmd.append(f"WORKSPACE={ws_abs}")
    if top:
        cmd.append(f"TOP={top}")
    if run_top:
        cmd.append(f"RUN_TOP={run_top}")
    if effective_run_id:
        cmd.append(f"RUN_ID={effective_run_id}")
    cmd.extend(_normalize_make_vars_from_params(params))

    # Determina il top-level del manifest
    manifest_top = top or run_top

    # Crea la specifica di invocazione
    spec = InvocationSpec(
        action_id=action,
        summary_label=action,
        cmd=cmd,
        params=params,
        workspace_dir=ws_abs,
        run_ref=run_ref,
        manifest_action=action,
        manifest_top=manifest_top,
        manifest_run_id=effective_run_id,
        postprocess=postprocess,
    )

    # Esegue l'azione orchestrata
    orch = run_orchestrated(spec)

    # Restituisce il risultato dell'esecuzione
    return ExecResult(
        exit_code=orch.backend.exit_code,
        runner_run_dir=orch.backend.run_dir,
        flow_run_dir=orch.flow_run_dir,
    )