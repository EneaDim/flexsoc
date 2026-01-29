from __future__ import annotations
from typing import Dict, List, Literal
from pydantic import BaseModel, Field, field_validator

OutputsHeader = List[Literal["busy_o","valid_o","error_o","low_power_o","dbg_o"]]

class Transition(BaseModel):
    from_state: str = Field(alias="from")
    to_state: str = Field(alias="to")
    cond: str

class FSM(BaseModel):
    states: List[str]
    transitions: List[Transition]
    outputs_header: OutputsHeader = ["busy_o","valid_o","error_o","low_power_o","dbg_o"]
    outputs: Dict[str, Dict[str, int]]
    assumptions: List[str] = []

    @field_validator("states")
    @classmethod
    def states_non_empty(cls, v):
        if not v:
            raise ValueError("states must be non-empty")
        for s in v:
            if not isinstance(s, str) or not s.strip():
                raise ValueError("state names must be non-empty strings")
        return v

    @field_validator("outputs")
    @classmethod
    def outputs_bits_only(cls, v):
        for st, outs in v.items():
            if not isinstance(outs, dict):
                raise ValueError(f"outputs[{st}] must be a dict")
            for k, val in outs.items():
                if val not in (0, 1):
                    raise ValueError(f"Output {k} for state {st} must be 0 or 1")
        return v
