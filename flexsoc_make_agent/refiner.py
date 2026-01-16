#!/usr/bin/env python3
from __future__ import annotations

import json
import re
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple
import urllib.request
import urllib.error


# -----------------------------
# Defaults / knobs
# -----------------------------
DEFAULT_MODEL = "qwen2.5:0.5b"
DEFAULT_TIMEOUT_S = 180

# Preprocess knobs (for snippets only)
DEFAULT_HEAD_LINES = 60
DEFAULT_TAIL_LINES = 120
DEFAULT_WIN = 20
DEFAULT_MAX_WINDOWS = 6
DEFAULT_MAX_BYTES_PER_FILE = 400_000

# Ollama knobs
DEFAULT_TEMPERATURE = 0.1
DEFAULT_NUM_PREDICT = 250
DEFAULT_KEEP_ALIVE = "10m"


SYSTEM_PROMPT = (
    "You are a log analysis assistant.\n"
    "Respond with a SINGLE valid JSON object and nothing else.\n"
    "Be concise. Never contradict deterministic counts provided.\n"
)


# -----------------------------
# Patterns (generic + Verilator)
# -----------------------------
# Verilator typed warnings/errors
VERI_WARN_TYPE_PAT = re.compile(r"^%Warning-([A-Za-z0-9_]+):\s*(.*)$", re.MULTILINE)
VERI_ERR_TYPE_PAT  = re.compile(r"^%Error-([A-Za-z0-9_]+):\s*(.*)$", re.MULTILINE)

# Verilator generic error (no "-TYPE")
VERI_ERR_GENERIC_PAT = re.compile(r"^%Error:\s*(.*)$", re.MULTILINE)

# Generic error-ish lines (keep it simple; avoid matching signal names with "err")
GENERIC_ERR_LINE_PAT = re.compile(
    r"(^|\s)("
    r"FATAL|"
    r"ERROR(\s|:)|"
    r"Error(\s|:)|"
    r"FAILED|"
    r"Traceback|"
    r"Exception|"
    r"Assertion|"
    r"Segmentation fault|"
    r"make:\s+\*\*\*"
    r")",
    re.IGNORECASE,
)

# Generic warning-ish lines (fallback only; Verilator warnings handled above)
GENERIC_WARN_LINE_PAT = re.compile(
    r"(^|\s)(WARNING(\s|:)|Warning(\s|:)|WARN(\s|:))",
    re.IGNORECASE,
)


# -----------------------------
# File reading / preprocessing
# -----------------------------
def read_text_tail(path: Path, max_bytes: int = DEFAULT_MAX_BYTES_PER_FILE) -> str:
    data = path.read_bytes()
    if len(data) > max_bytes:
        data = data[-max_bytes:]
    return data.decode("utf-8", errors="replace")


def _extract_windows(lines: List[str], pat: re.Pattern, win: int, max_windows: int) -> Tuple[str, int]:
    idxs = [i for i, ln in enumerate(lines) if pat.search(ln)]
    windows: List[Tuple[int, int]] = []
    for i in idxs:
        a = max(0, i - win)
        b = min(len(lines), i + win + 1)
        if windows and a <= windows[-1][1]:
            windows[-1] = (windows[-1][0], max(windows[-1][1], b))
        else:
            windows.append((a, b))
        if len(windows) >= max_windows:
            break
    blocks = ["\n".join(lines[a:b]) for a, b in windows]
    return ("\n\n---\n\n".join(blocks)).strip(), len(idxs)


def preprocess_log(
    text: str,
    *,
    head_lines: int = DEFAULT_HEAD_LINES,
    tail_lines: int = DEFAULT_TAIL_LINES,
    win: int = DEFAULT_WIN,
    max_windows: int = DEFAULT_MAX_WINDOWS,
) -> Dict[str, Any]:
    lines = text.splitlines()
    head = "\n".join(lines[:head_lines]).strip()
    tail = ("\n".join(lines[-tail_lines:]) if len(lines) > tail_lines else "\n".join(lines)).strip()

    # For snippets we search for any error-ish/warn-ish line (generic patterns)
    err_windows, err_hits = _extract_windows(lines, GENERIC_ERR_LINE_PAT, win=win, max_windows=max_windows)
    warn_windows, warn_hits = _extract_windows(lines, GENERIC_WARN_LINE_PAT, win=win, max_windows=max_windows)

    return {
        "head": head,
        "tail": tail,
        "error_windows": err_windows,
        "warning_windows": warn_windows,
        "err_hits": int(err_hits),
        "warn_hits": int(warn_hits),
    }


# -----------------------------
# Deterministic grouping helpers
# -----------------------------
def _add_group(
    groups: Dict[str, Dict[str, Any]],
    *,
    kind: str,            # "error" or "warning"
    gtype: str,           # group type label
    line: str,            # example line
    log_path: str,        # originating log
    max_examples: int = 2,
) -> None:
    key = f"{kind}:{gtype}"
    if key not in groups:
        groups[key] = {
            "type": gtype,
            "count": 0,
            "logs": set(),
            "examples": [],
        }
    obj = groups[key]
    obj["count"] += 1
    obj["logs"].add(log_path)
    if len(obj["examples"]) < max_examples:
        obj["examples"].append(line.strip())


def _finalize_groups(groups: Dict[str, Dict[str, Any]]) -> List[Dict[str, Any]]:
    out: List[Dict[str, Any]] = []
    for _key, obj in groups.items():
        out.append({
            "type": obj["type"],
            "count": int(obj["count"]),
            "logs": sorted(list(obj["logs"])),
            "examples": obj["examples"],
        })
    out.sort(key=lambda d: (-d["count"], d["type"]))
    return out


def extract_deterministic_summaries(
    file_texts: List[Tuple[Path, str]],
    *,
    max_examples_per_type: int = 2,
) -> Tuple[List[Dict[str, Any]], List[Dict[str, Any]]]:
    """
    Return (error_summary, warning_summary), deterministic, with log attribution.
    """
    groups: Dict[str, Dict[str, Any]] = {}

    for fp, txt in file_texts:
        lp = fp.as_posix()

        # 1) Verilator typed warnings: %Warning-FOO:
        for m in VERI_WARN_TYPE_PAT.finditer(txt):
            wtype = m.group(1)
            line = m.group(0)
            _add_group(groups, kind="warning", gtype=wtype, line=line, log_path=lp, max_examples=max_examples_per_type)

        # 2) Verilator typed errors: %Error-FOO:
        for m in VERI_ERR_TYPE_PAT.finditer(txt):
            etype = m.group(1)
            line = m.group(0)
            _add_group(groups, kind="error", gtype=etype, line=line, log_path=lp, max_examples=max_examples_per_type)

        # 3) Verilator generic errors: %Error: ...
        for m in VERI_ERR_GENERIC_PAT.finditer(txt):
            # Avoid double counting lines that are actually %Error-FOO:
            if m.group(0).startswith("%Error-"):
                continue
            line = m.group(0)
            _add_group(groups, kind="error", gtype="verilator_error_generic", line=line, log_path=lp, max_examples=max_examples_per_type)

        # 4) Generic errors fallback (only if not already caught by Verilator)
        for ln in txt.splitlines():
            if GENERIC_ERR_LINE_PAT.search(ln):
                _add_group(groups, kind="error", gtype="generic_error", line=ln, log_path=lp, max_examples=max_examples_per_type)

        # 5) Generic warnings fallback (rare; keep but low priority)
        for ln in txt.splitlines():
            if GENERIC_WARN_LINE_PAT.search(ln):
                _add_group(groups, kind="warning", gtype="generic_warning", line=ln, log_path=lp, max_examples=max_examples_per_type)

    # Split back into error/warning lists
    err_groups = {k: v for k, v in groups.items() if k.startswith("error:")}
    warn_groups = {k: v for k, v in groups.items() if k.startswith("warning:")}

    return _finalize_groups(err_groups), _finalize_groups(warn_groups)


# -----------------------------
# Ollama HTTP client (optional)
# -----------------------------
def call_ollama_chat(
    *,
    model: str,
    system_prompt: str,
    user_prompt: str,
    temperature: float = DEFAULT_TEMPERATURE,
    num_predict: int = DEFAULT_NUM_PREDICT,
    keep_alive: str = DEFAULT_KEEP_ALIVE,
    timeout_s: int = DEFAULT_TIMEOUT_S,
) -> str:
    payload = {
        "model": model,
        "messages": [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": user_prompt},
        ],
        "stream": False,
        "keep_alive": keep_alive,
        "options": {
            "temperature": float(temperature),
            "num_predict": int(num_predict),
        },
    }

    req = urllib.request.Request(
        "http://localhost:11434/api/chat",
        data=json.dumps(payload).encode("utf-8"),
        headers={"Content-Type": "application/json"},
        method="POST",
    )

    try:
        with urllib.request.urlopen(req, timeout=timeout_s) as resp:
            body = resp.read().decode("utf-8", errors="replace")
    except urllib.error.HTTPError as e:
        err = e.read().decode("utf-8", errors="replace")
        raise RuntimeError(f"Ollama HTTPError {e.code}: {err}")
    except Exception as e:
        raise RuntimeError(f"Ollama request failed: {e}")

    obj = json.loads(body)
    return obj["message"]["content"]


def _extract_first_json_object(s: str) -> str:
    start = s.find("{")
    if start < 0:
        raise ValueError("No JSON object start '{' found in model output")
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
            elif ch == '"':
                in_str = False
        else:
            if ch == '"':
                in_str = True
            elif ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    return s[start : i + 1]
    raise ValueError("Unbalanced JSON in model output")


# -----------------------------
# Public API
# -----------------------------
def analyze(
    run: Dict[str, Any],
    files: List[Path],
    *,
    user_question: str,
    model: str = DEFAULT_MODEL,
    # speed knobs
    head_lines: int = DEFAULT_HEAD_LINES,
    tail_lines: int = DEFAULT_TAIL_LINES,
    win: int = DEFAULT_WIN,
    err_win: Optional[int] = None,     # alias for older callers
    max_windows: int = DEFAULT_MAX_WINDOWS,
    max_bytes_per_file: int = DEFAULT_MAX_BYTES_PER_FILE,
    timeout_s: int = DEFAULT_TIMEOUT_S,
    temperature: float = DEFAULT_TEMPERATURE,
    num_predict: int = DEFAULT_NUM_PREDICT,
    keep_alive: str = DEFAULT_KEEP_ALIVE,
    use_llm: bool = True,              # set False for :sum to be instant
) -> Dict[str, Any]:
    """
    Analyze one run using only flow logs.
    Always returns deterministic error_summary/warning_summary with log attribution.
    Optionally uses LLM only to enrich the human summary and action items.
    """
    t0 = time.time()
    if err_win is not None:
        win = int(err_win)

    # Read files
    file_texts: List[Tuple[Path, str]] = []
    blocks: List[str] = []
    for fp in files:
        if not fp.exists() or not fp.is_file():
            continue
        txt = read_text_tail(fp, max_bytes=max_bytes_per_file)
        file_texts.append((fp, txt))

        pre = preprocess_log(
            txt,
            head_lines=head_lines,
            tail_lines=tail_lines,
            win=win,
            max_windows=max_windows,
        )
        blocks.append(
            f"=== FILE: {fp.as_posix()} ===\n"
            f"[ERROR_WINDOWS]\n{pre['error_windows']}\n\n"
            f"[WARNING_WINDOWS]\n{pre['warning_windows']}\n\n"
            f"[HEAD]\n{pre['head']}\n\n"
            f"[TAIL]\n{pre['tail']}\n"
        )

    if not file_texts:
        return {
            "summary": "No readable log files provided.",
            "status": "unknown",
            "error_summary": [],
            "warning_summary": [],
            "action_items": [{"type": "check", "text": "Verify that expected log files exist and are readable."}],
            "key_log_snippets": [],
            "_meta": {"model": None, "analyze_seconds": round(time.time() - t0, 3), "files": [f.as_posix() for f in files]},
        }

    # Deterministic summaries (source of truth)
    error_summary, warning_summary = extract_deterministic_summaries(file_texts, max_examples_per_type=2)

    err_total = sum(x["count"] for x in error_summary) if error_summary else 0
    warn_total = sum(x["count"] for x in warning_summary) if warning_summary else 0

    out: Dict[str, Any] = {
        "summary": f"Found {err_total} error(s) and {warn_total} warning(s) across {len(file_texts)} log file(s).",
        "status": "unknown",
        "error_summary": error_summary,
        "warning_summary": warning_summary,
        "action_items": [],
        "key_log_snippets": [],
    }

    # Fast path: deterministic only
    if not use_llm:
        out["_meta"] = {
            "model": None,
            "analyze_seconds": round(time.time() - t0, 3),
            "files": [fp.as_posix() for fp, _ in file_texts],
            "preprocess": {
                "head_lines": head_lines,
                "tail_lines": tail_lines,
                "win": win,
                "max_windows": max_windows,
                "max_bytes_per_file": max_bytes_per_file,
            },
        }
        return out

    # Optional LLM enrichment (cannot override deterministic summaries)
    ctx = {
        "run_id": run.get("id"),
        "target": run.get("target"),
        "vars": run.get("vars") or {},
        "exit_code": run.get("exit_code"),
        "cwd": run.get("cwd"),
    }

    user_prompt = (
        "Task: Provide a short troubleshooting explanation and suggested next steps.\n"
        "Do NOT contradict the deterministic error_summary/warning_summary.\n\n"
        "Context:\n"
        f"- run_id: {ctx['run_id']}\n"
        f"- target: {ctx['target']}\n"
        f"- vars: {json.dumps(ctx['vars'], ensure_ascii=False)}\n"
        f"- exit_code: {ctx['exit_code']}\n"
        f"- cwd: {ctx['cwd']}\n\n"
        f"user_question: {user_question}\n\n"
        "Deterministic summaries (source of truth):\n"
        f"- error_summary: {json.dumps(error_summary, ensure_ascii=False)}\n"
        f"- warning_summary: {json.dumps(warning_summary, ensure_ascii=False)}\n\n"
        "Log snippets:\n"
        + "\n\n".join(blocks)
        + "\n\nReturn JSON only with keys:\n"
          "summary (string, 3-6 lines), status (success|failure|unknown), "
          "action_items (array of {type,...}), key_log_snippets (array of strings).\n"
    )

    raw = call_ollama_chat(
        model=model,
        system_prompt=SYSTEM_PROMPT,
        user_prompt=user_prompt,
        temperature=temperature,
        num_predict=num_predict,
        keep_alive=keep_alive,
        timeout_s=timeout_s,
    ).strip()

    try:
        obj = json.loads(raw)
    except json.JSONDecodeError:
        obj = json.loads(_extract_first_json_object(raw))

    # Merge only allowed enrichments; never override deterministic summaries
    if isinstance(obj, dict):
        if isinstance(obj.get("summary"), str) and obj["summary"].strip():
            s = obj["summary"].strip()
            # Avoid "no errors/warnings" contradictions
            if not ((err_total > 0 or warn_total > 0) and re.search(r"\bno\b.*\b(warn|warning|error)s?\b", s, re.IGNORECASE)):
                out["summary"] = s

        if obj.get("status") in ("success", "failure", "unknown"):
            out["status"] = obj["status"]

        if isinstance(obj.get("action_items"), list):
            out["action_items"] = [
                a for a in obj["action_items"]
                if isinstance(a, dict) and a.get("type") in ("check", "try_target", "set_var")
            ]

        if isinstance(obj.get("key_log_snippets"), list):
            out["key_log_snippets"] = [str(x) for x in obj["key_log_snippets"][:20]]

    out["_meta"] = {
        "model": model,
        "analyze_seconds": round(time.time() - t0, 3),
        "files": [fp.as_posix() for fp, _ in file_texts],
        "preprocess": {
            "head_lines": head_lines,
            "tail_lines": tail_lines,
            "win": win,
            "max_windows": max_windows,
            "max_bytes_per_file": max_bytes_per_file,
        },
    }
    return out

