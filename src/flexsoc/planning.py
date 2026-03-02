from __future__ import annotations

import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict

import yaml


@dataclass
class Plan:
    action: str
    params: Dict[str, Any]


def load_registry(path: Path) -> Dict[str, Any]:
    data = yaml.safe_load(path.read_text(encoding="utf-8"))
    return data


def validate_plan(plan: Plan, registry: Dict[str, Any], *, allow_missing_required: bool = False) -> None:
    actions = registry.get("actions", {})
    if plan.action not in actions:
        raise ValueError(f"Unknown action: {plan.action}")

    spec = actions[plan.action]
    params_spec = spec.get("params", {})

    # required check
    for k, v in params_spec.items():
        if v.get("required") and k not in plan.params and not allow_missing_required:
            raise ValueError(f"Missing required param: {k}")

    # unknown params check
    for k in plan.params:
        if k not in params_spec:
            raise ValueError(f"Unknown param for {plan.action}: {k}")

    # basic type check (string/int/bool only)
    for k, v in plan.params.items():
        t = params_spec.get(k, {}).get("type")
        if t == "string" and not isinstance(v, str):
            raise ValueError(f"Param {k} must be string")
        if t == "int" and not isinstance(v, int):
            raise ValueError(f"Param {k} must be int")
        if t == "bool" and not isinstance(v, bool):
            raise ValueError(f"Param {k} must be bool")


def write_plan_json(plan: Plan, out_path: Path) -> None:
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(json.dumps({"action": plan.action, "params": plan.params}, indent=2) + "\n", encoding="utf-8")


def read_plan_json(path: Path) -> Plan:
    obj = json.loads(path.read_text(encoding="utf-8"))
    return Plan(action=obj["action"], params=obj.get("params", {}))


def naive_intent_to_plan(text: str) -> Plan:
    """
    Deterministic rules-based intent mapping.
    This is the minimal baseline; AI can produce the same Plan JSON later.
    """
    t = text.strip().lower()

    # simple keyword mapping
    if any(w in t for w in ["ip start", "create ip", "new ip", "template ip"]):
        return Plan(action="ip_start", params={})

    if "lint" in t:
        return Plan(action="lint", params={})

    if any(w in t for w in ["compile", "build"]):
        return Plan(action="compile", params={})

    if any(w in t for w in ["sim", "simulate", "run testbench"]):
        return Plan(action="sim", params={})

    raise ValueError(f"Cannot map intent to known action: {text}")
