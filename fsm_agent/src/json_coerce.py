from __future__ import annotations
import json
from typing import Any, Dict

def _extract_json_object(text: str) -> str:
    s = text.strip()
    if s.startswith("{") and s.endswith("}"):
        return s
    start = s.find("{")
    if start < 0:
        raise ValueError("No JSON object start '{' found")
    depth = 0
    for i in range(start, len(s)):
        if s[i] == "{":
            depth += 1
        elif s[i] == "}":
            depth -= 1
            if depth == 0:
                return s[start:i+1]
    raise ValueError("No complete JSON object found")

def coerce_json(raw_text: str) -> Dict[str, Any]:
    js = _extract_json_object(raw_text)
    obj = json.loads(js)
    if not isinstance(obj, dict):
        raise ValueError("Top-level JSON must be an object")
    return obj
