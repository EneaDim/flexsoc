from __future__ import annotations
import re
from typing import Tuple

# Banlist patterns
RE_AND = re.compile(r"\band\b", re.IGNORECASE)
RE_OR  = re.compile(r"\bor\b", re.IGNORECASE)
RE_NOT = re.compile(r"\bnot\b", re.IGNORECASE)

# = '1' / == 1 / = 1 / 1'b1
RE_EQ1 = re.compile(r"\s*(==|=)\s*(?:'1'|\"1\"|1|1'b1)\s*", re.IGNORECASE)
RE_EQ0 = re.compile(r"\s*(==|=)\s*(?:'0'|\"0\"|0|1'b0)\s*", re.IGNORECASE)

# not(x) like forms are not expected, but handle "not error_i" -> "!error_i"
RE_NOT_IDENT = re.compile(r"\bnot\s+([A-Za-z_][A-Za-z0-9_]*)\b", re.IGNORECASE)

# plain words "true"
RE_TRUE = re.compile(r"\btrue\b", re.IGNORECASE)
RE_FALSE = re.compile(r"\bfalse\b", re.IGNORECASE)

def normalize_guard(cond: str) -> Tuple[str, bool]:
    """
    Best-effort rewrite to the allowed DSL:
      - and/or/not -> &/|/!
      - x = '1' -> x
      - x = '0' -> !x
      - true -> 1
      - false -> !(1)  (rare; still parsable)
    Returns (new_cond, changed).
    """
    s0 = cond
    s = cond.strip()

    # Replace boolean keywords
    s = RE_TRUE.sub("1", s)
    s = RE_FALSE.sub("!(1)", s)

    # Handle "not ident" first
    s = RE_NOT_IDENT.sub(r"!\1", s)

    # Replace AND/OR tokens
    s = RE_AND.sub("&", s)
    s = RE_OR.sub("|", s)

    # Replace remaining "not" as unary "!" (conservative)
    s = RE_NOT.sub("!", s)

    # Normalize equality-to-1/0
    # "sig = '1'" -> "sig"
    s = RE_EQ1.sub("", s)
    # "sig = '0'" -> "!sig"  (we transform "sig = 0" by rewriting pattern "sig = 0" into "!sig")
    # This is done by converting "sig<eq0>" into "!sig" via a regex on the whole expression.
    s = re.sub(r"\b([A-Za-z_][A-Za-z0-9_]*)\b" + RE_EQ0.pattern, r"!\1", s, flags=re.IGNORECASE)

    # Fix common textual negations that remain like "! error_i"
    s = re.sub(r"!\s+", "!", s)

    changed = (s != s0)
    return s, changed
