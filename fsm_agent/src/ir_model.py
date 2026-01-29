from __future__ import annotations
from dataclasses import dataclass
from typing import Dict, List, Literal, TypedDict

OutputsHeader = List[Literal["busy_o","valid_o","error_o","low_power_o","dbg_o"]]

class Transition(TypedDict):
    from_: str
    to: str
    cond: str

class PriorityRule(TypedDict):
    state: str
    high_cond: str
    low_cond: str

@dataclass(frozen=True)
class IR:
    init_state: str
    states: List[str]
    transitions: List[dict]          # {"from":..,"to":..,"cond":..} (keep compat with existing JSON)
    outputs_header: OutputsHeader
    outputs: Dict[str, Dict[str, int]]
    priorities: List[dict]           # {"state":..,"high_cond":..,"low_cond":..}
    assumptions: List[str]
