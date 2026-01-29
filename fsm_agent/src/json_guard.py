from __future__ import annotations
import json
import re

def extract_first_json(text: str) -> str:
    s = text.strip()

    # remove common fences
    if "```" in s:
        s = s.replace("```json", "```").strip()
        s = s.replace("```", "").strip()

    start = s.find("{")
    if start < 0:
        return s

    depth = 0
    in_str = False
    esc = False
    for i in range(start, len(s)):
        ch = s[i]
        if in_str:
            if esc:
                esc = False
            elif ch == "\\":
                esc = True
            elif ch == "\"":
                in_str = False
            continue
        else:
            if ch == "\"":
                in_str = True
                continue
            if ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    return s[start:i+1].strip()

    return s[start:].strip()

def _strip_jsonc_comments(s: str) -> str:
    # remove // comments outside strings (simple but effective)
    out = []
    in_str = False
    esc = False
    i = 0
    while i < len(s):
        ch = s[i]
        if in_str:
            out.append(ch)
            if esc:
                esc = False
            elif ch == "\\":
                esc = True
            elif ch == "\"":
                in_str = False
            i += 1
            continue

        # not in string
        if ch == "\"":
            in_str = True
            out.append(ch)
            i += 1
            continue

        if ch == "/" and i + 1 < len(s) and s[i + 1] == "/":
            # skip to end of line
            while i < len(s) and s[i] != "\n":
                i += 1
            continue

        out.append(ch)
        i += 1

    return "".join(out)

def _strip_trailing_commas(s: str) -> str:
    # remove trailing commas before } or ]
    return re.sub(r",\s*([}\]])", r"\1", s)

def sanitize_json_like(s: str) -> str:
    s2 = _strip_jsonc_comments(s)
    s2 = _strip_trailing_commas(s2)
    return s2.strip()

def loads_first_json(text: str) -> dict:
    candidate = extract_first_json(text)
    candidate = sanitize_json_like(candidate)
    try:
        return json.loads(candidate)
    except Exception as e:
        snippet = candidate[:900]
        raise ValueError(f"Parsing JSON fallito: {e}. Snippet: {snippet!r}")
