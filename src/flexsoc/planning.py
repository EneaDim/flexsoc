from __future__ import annotations

import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import yaml


@dataclass(frozen=True)
class Plan:
    action: str
    params: dict[str, Any]


def _as_path(path: Path | str) -> Path:
    return Path(path).expanduser().resolve()


def _require_mapping(value: Any, *, what: str) -> dict[str, Any]:
    if not isinstance(value, dict):
        raise ValueError(f"{what} must be a mapping/object")
    return value


def _require_string(value: Any, *, what: str) -> str:
    if not isinstance(value, str):
        raise ValueError(f"{what} must be a string")
    text = value.strip()
    if not text:
        raise ValueError(f"{what} must not be empty")
    return text


def load_registry(path: Path) -> dict[str, Any]:
    """
    Load and validate the registry YAML structure.

    Minimum contract:
    - file must exist
    - YAML root must be a mapping
    - top-level key 'actions' must exist and be a mapping
    """
    registry_path = _as_path(path)

    if not registry_path.exists():
        raise FileNotFoundError(f"Registry file not found: {registry_path}")

    if not registry_path.is_file():
        raise ValueError(f"Registry path is not a file: {registry_path}")

    try:
        raw = registry_path.read_text(encoding="utf-8")
    except OSError as e:
        raise OSError(f"Cannot read registry file {registry_path}: {e}") from e

    if not raw.strip():
        raise ValueError(f"Registry file is empty: {registry_path}")

    try:
        data = yaml.safe_load(raw)
    except yaml.YAMLError as e:
        raise ValueError(f"Invalid YAML in registry file {registry_path}: {e}") from e

    if data is None:
        raise ValueError(f"Registry file is empty: {registry_path}")

    registry = _require_mapping(data, what=f"Registry root in {registry_path}")
    actions = registry.get("actions")

    if actions is None:
        raise ValueError(f"Registry missing required top-level key 'actions': {registry_path}")

    if not isinstance(actions, dict):
        raise ValueError(f"Registry key 'actions' must be a mapping/object: {registry_path}")

    return registry


def validate_plan(
    plan: Plan,
    registry: dict[str, Any],
    *,
    allow_missing_required: bool = False,
) -> None:
    """
    Validate a plan against the registry.

    Checks:
    - plan structure
    - action existence
    - params shape
    - required params
    - unknown params
    - basic declared types (string/int/bool)
    """
    if not isinstance(plan, Plan):
        raise ValueError("plan must be a Plan instance")

    action = _require_string(plan.action, what="Plan action")

    if not isinstance(plan.params, dict):
        raise ValueError("Plan params must be a mapping/object")

    actions = registry.get("actions", {})
    if not isinstance(actions, dict):
        raise ValueError("Registry key 'actions' must be a mapping/object")

    if action not in actions:
        available = ", ".join(sorted(str(k) for k in actions.keys())) if actions else "(none)"
        raise ValueError(f"Unknown action: {action}. Available actions: {available}")

    spec = actions[action]
    if not isinstance(spec, dict):
        raise ValueError(f"Registry entry for action '{action}' must be a mapping/object")

    params_spec = spec.get("params", {})
    if params_spec is None:
        params_spec = {}
    if not isinstance(params_spec, dict):
        raise ValueError(f"Registry params spec for action '{action}' must be a mapping/object")

    # required params
    for param_name, param_spec in params_spec.items():
        if not isinstance(param_spec, dict):
            raise ValueError(
                f"Registry param spec for action '{action}' and param '{param_name}' must be a mapping/object"
            )

        required = bool(param_spec.get("required", False))
        if required and param_name not in plan.params and not allow_missing_required:
            raise ValueError(f"Missing required param for {action}: {param_name}")

    # unknown params
    for param_name in plan.params:
        if param_name not in params_spec:
            raise ValueError(f"Unknown param for {action}: {param_name}")

    # basic type checks
    for param_name, param_value in plan.params.items():
        declared_type = params_spec.get(param_name, {}).get("type")

        if declared_type == "string" and not isinstance(param_value, str):
            raise ValueError(f"Param {param_name} must be string")
        if declared_type == "int" and not isinstance(param_value, int):
            raise ValueError(f"Param {param_name} must be int")
        if declared_type == "bool" and not isinstance(param_value, bool):
            raise ValueError(f"Param {param_name} must be bool")


def write_plan_json(plan: Plan, out_path: Path) -> None:
    """
    Serialize a plan to JSON, creating parent directories if needed.
    """
    if not isinstance(plan, Plan):
        raise ValueError("plan must be a Plan instance")

    action = _require_string(plan.action, what="Plan action")

    if not isinstance(plan.params, dict):
        raise ValueError("Plan params must be a mapping/object")

    path = _as_path(out_path)
    path.parent.mkdir(parents=True, exist_ok=True)

    payload = {
        "action": action,
        "params": plan.params,
    }

    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def read_plan_json(path: Path) -> Plan:
    """
    Read a plan from JSON and validate its basic structure.
    """
    plan_path = _as_path(path)

    if not plan_path.exists():
        raise FileNotFoundError(f"Plan file not found: {plan_path}")

    if not plan_path.is_file():
        raise ValueError(f"Plan path is not a file: {plan_path}")

    try:
        raw = plan_path.read_text(encoding="utf-8")
    except OSError as e:
        raise OSError(f"Cannot read plan file {plan_path}: {e}") from e

    if not raw.strip():
        raise ValueError(f"Plan file is empty: {plan_path}")

    try:
        obj = json.loads(raw)
    except json.JSONDecodeError as e:
        raise ValueError(f"Invalid JSON in plan file {plan_path}: {e}") from e

    if not isinstance(obj, dict):
        raise ValueError(f"Plan JSON root must be an object: {plan_path}")

    if "action" not in obj:
        raise ValueError(f"Plan JSON missing required key 'action': {plan_path}")

    action = _require_string(obj.get("action"), what="Plan action")

    params = obj.get("params", {})
    if params is None:
        params = {}
    if not isinstance(params, dict):
        raise ValueError(f"Plan JSON key 'params' must be an object: {plan_path}")

    return Plan(action=action, params=params)


def naive_intent_to_plan(text: str) -> Plan:
    """
    Deterministic rules-based intent mapping.

    This is a minimal baseline mapper. It should stay simple,
    transparent, and predictable.
    """
    if not isinstance(text, str):
        raise ValueError("Intent text must be a string")

    raw = text.strip()
    if not raw:
        raise ValueError("Intent text must not be empty")

    t = raw.lower()

    if any(phrase in t for phrase in ["ip start", "create ip", "new ip", "template ip"]):
        return Plan(action="ip_start", params={})

    if "lint" in t:
        return Plan(action="lint", params={})

    if any(phrase in t for phrase in ["compile", "build"]):
        return Plan(action="compile", params={})

    if any(phrase in t for phrase in ["sim", "simulate", "run testbench"]):
        return Plan(action="sim", params={})

    raise ValueError(f"Cannot map intent to known action: {text}")
