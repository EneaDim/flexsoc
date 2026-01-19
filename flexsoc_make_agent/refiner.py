#!/usr/bin/env python3
from __future__ import annotations

import json
import re
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple
import urllib.request
import urllib.error


DEFAULT_MODEL = "qwen2.5:0.5b"
DEFAULT_TIMEOUT_S = 180

DEFAULT_HEAD_LINES = 60
DEFAULT_TAIL_LINES = 120
DEFAULT_WIN = 20
DEFAULT_MAX_WINDOWS = 6
DEFAULT_MAX_BYTES_PER_FILE = 400_000

DEFAULT_TEMPERATURE = 0.0
DEFAULT_NUM_PREDICT = 120
DEFAULT_KEEP_ALIVE = "10m"

SYSTEM_PROMPT = (
    "You are a log analysis assistant.\n"
    "Follow the user's output format exactly.\n"
    "Be concise.\n"
)


# Verilator typed warnings/errors
VERI_WARN_TYPE_PAT = re.compile(r"^%Warning-([A-Za-z0-9_]+):\s*(.*)$", re.MULTILINE)
VERI_ERR_TYPE_PAT  = re.compile(r"^%Error-([A-Za-z0-9_]+):\s*(.*)$", re.MULTILINE)
VERI_ERR_GENERIC_PAT = re.compile(r"^%Error:\s*(.*)$", re.MULTILINE)

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

GENERIC_WARN_LINE_PAT = re.compile(
    r"(^|\s)(WARNING(\s|:)|Warning(\s|:)|WARN(\s|:))",
    re.IGNORECASE,
)


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
    err_windows, _ = _extract_windows(lines, GENERIC_ERR_LINE_PAT, win=win, max_windows=max_windows)
    warn_windows, _ = _extract_windows(lines, GENERIC_WARN_LINE_PAT, win=win, max_windows=max_windows)
    return {"head": head, "tail": tail, "error_windows": err_windows, "warning_windows": warn_windows}


def _add_group(
    groups: Dict[str, Dict[str, Any]],
    *,
    kind: str,     # "error" or "warning"
    gtype: str,
    line: str,
    log_path: str,
    max_examples: int = 2,
) -> None:
    key = f"{kind}:{gtype}"
    if key not in groups:
        groups[key] = {"type": gtype, "count": 0, "logs": set(), "examples": []}
    obj = groups[key]
    obj["count"] += 1
    obj["logs"].add(log_path)
    if len(obj["examples"]) < max_examples:
        obj["examples"].append(line.strip())


def _finalize_groups(groups: Dict[str, Dict[str, Any]]) -> List[Dict[str, Any]]:
    out: List[Dict[str, Any]] = []
    for _k, obj in groups.items():
        out.append(
            {
                "type": obj["type"],
                "count": int(obj["count"]),
                "logs": sorted(list(obj["logs"])),
                "examples": obj["examples"],
            }
        )
    out.sort(key=lambda d: (-d["count"], d["type"]))
    return out


def extract_deterministic_summaries(
    file_texts: List[Tuple[Path, str]],
    *,
    max_examples_per_type: int = 2,
) -> Tuple[List[Dict[str, Any]], List[Dict[str, Any]]]:
    groups: Dict[str, Dict[str, Any]] = {}

    for fp, txt in file_texts:
        lp = fp.as_posix()

        for m in VERI_WARN_TYPE_PAT.finditer(txt):
            _add_group(groups, kind="warning", gtype=m.group(1), line=m.group(0), log_path=lp, max_examples=max_examples_per_type)

        for m in VERI_ERR_TYPE_PAT.finditer(txt):
            _add_group(groups, kind="error", gtype=m.group(1), line=m.group(0), log_path=lp, max_examples=max_examples_per_type)

        for m in VERI_ERR_GENERIC_PAT.finditer(txt):
            if m.group(0).startswith("%Error-"):
                continue
            _add_group(groups, kind="error", gtype="verilator_error_generic", line=m.group(0), log_path=lp, max_examples=max_examples_per_type)

        # Generic fallbacks
        for ln in txt.splitlines():
            if GENERIC_ERR_LINE_PAT.search(ln):
                _add_group(groups, kind="error", gtype="generic_error", line=ln, log_path=lp, max_examples=max_examples_per_type)
        for ln in txt.splitlines():
            if GENERIC_WARN_LINE_PAT.search(ln):
                _add_group(groups, kind="warning", gtype="generic_warning", line=ln, log_path=lp, max_examples=max_examples_per_type)

    err_groups = {k: v for k, v in groups.items() if k.startswith("error:")}
    warn_groups = {k: v for k, v in groups.items() if k.startswith("warning:")}
    return _finalize_groups(err_groups), _finalize_groups(warn_groups)


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
        raise RuntimeError(f"Ollama HTTPError {e.code}: {err}") from e
    except Exception as e:
        raise RuntimeError(f"Ollama request failed: {e}") from e

    obj = json.loads(body)
    return obj["message"]["content"]


def _llm_explain_one_type(
    *,
    model: str,
    ctx: Dict[str, Any],
    kind: str,  # "warning" or "error"
    item: Dict[str, Any],
    user_question: str,
    temperature: float,
    num_predict: int,
    keep_alive: str,
    timeout_s: int,
) -> str:
    """
    One call per type. Returns a single raw sentence (plain text).
    """
    t = str(item.get("type") or "").strip()
    examples = item.get("examples") or []
    ex1 = examples[0] if len(examples) > 0 else ""
    ex2 = examples[1] if len(examples) > 1 else ""
    logs = item.get("logs") or []
    logs_s = ", ".join(logs[:3])

    prompt = (
        "Write ONE short sentence that explains the following log issue.\n"
        "Output MUST be plain text only (no JSON, no bullets, no markdown).\n"
        "Keep it <= 160 characters.\n\n"
        f"kind: {kind}\n"
        f"type: {t}\n"
        f"target: {ctx.get('target')}\n"
        f"vars: {json.dumps(ctx.get('vars') or {}, ensure_ascii=False)}\n"
        f"logs: {logs_s}\n"
        f"example1: {ex1}\n"
        f"example2: {ex2}\n"
        f"user_question: {user_question}\n"
    )

    raw = call_ollama_chat(
        model=model,
        system_prompt=SYSTEM_PROMPT,
        user_prompt=prompt,
        temperature=temperature,
        num_predict=num_predict,
        keep_alive=keep_alive,
        timeout_s=timeout_s,
    ).strip()

    # sanitize to one line
    s = " ".join(raw.splitlines()).strip()
    # strip quotes if model returns them
    if len(s) >= 2 and ((s[0] == s[-1]) and s[0] in ("'", '"')):
        s = s[1:-1].strip()
    if len(s) > 200:
        s = s[:197].rstrip() + "..."
    return s


def analyze(
    run: Dict[str, Any],
    files: List[Path],
    *,
    user_question: str,
    model: str = DEFAULT_MODEL,
    head_lines: int = DEFAULT_HEAD_LINES,
    tail_lines: int = DEFAULT_TAIL_LINES,
    win: int = DEFAULT_WIN,
    err_win: Optional[int] = None,
    max_windows: int = DEFAULT_MAX_WINDOWS,
    max_bytes_per_file: int = DEFAULT_MAX_BYTES_PER_FILE,
    timeout_s: int = DEFAULT_TIMEOUT_S,
    temperature: float = DEFAULT_TEMPERATURE,
    num_predict: int = DEFAULT_NUM_PREDICT,
    keep_alive: str = DEFAULT_KEEP_ALIVE,
    use_llm: bool = False,
) -> Dict[str, Any]:
    t0 = time.time()
    if err_win is not None:
        win = int(err_win)

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
            "llm_sentences": {"errors": {}, "warnings": {}},
            "_meta": {"model": None, "analyze_seconds": round(time.time() - t0, 3), "files": [f.as_posix() for f in files]},
        }

    error_summary, warning_summary = extract_deterministic_summaries(file_texts, max_examples_per_type=2)

    err_total = sum(int(x.get("count", 0)) for x in (error_summary or []))
    warn_total = sum(int(x.get("count", 0)) for x in (warning_summary or []))

    out: Dict[str, Any] = {
        "summary": f"Found {err_total} error(s) and {warn_total} warning(s) across {len(file_texts)} log file(s).",
        "status": "unknown",
        "error_summary": error_summary,
        "warning_summary": warning_summary,
        "llm_sentences": {"errors": {}, "warnings": {}},
    }

    exit_code = run.get("exit_code")
    if isinstance(exit_code, int) and exit_code == 0 and err_total == 0:
        out["status"] = "success" if warn_total == 0 else "unknown"
    elif err_total > 0 or (isinstance(exit_code, int) and exit_code != 0):
        out["status"] = "failure"
    else:
        out["status"] = "unknown"

    if not use_llm:
        out["_meta"] = {
            "model": None,
            "analyze_seconds": round(time.time() - t0, 3),
            "files": [fp.as_posix() for fp, _ in file_texts],
        }
        return out

    ctx = {
        "run_id": run.get("id"),
        "target": run.get("target"),
        "vars": run.get("vars") or {},
        "exit_code": run.get("exit_code"),
        "cwd": run.get("cwd"),
    }

    wmap: Dict[str, str] = {}
    emap: Dict[str, str] = {}

    # ONE CALL PER TYPE (simple, slow, but exactly what you want)
    for it in warning_summary:
        if not isinstance(it, dict):
            continue
        t = it.get("type")
        if not isinstance(t, str) or not t.strip():
            continue
        try:
            wmap[t] = _llm_explain_one_type(
                model=model,
                ctx=ctx,
                kind="warning",
                item=it,
                user_question=user_question,
                temperature=temperature,
                num_predict=num_predict,
                keep_alive=keep_alive,
                timeout_s=timeout_s,
            )
        except Exception:
            wmap[t] = ""

    for it in error_summary:
        if not isinstance(it, dict):
            continue
        t = it.get("type")
        if not isinstance(t, str) or not t.strip():
            continue
        try:
            emap[t] = _llm_explain_one_type(
                model=model,
                ctx=ctx,
                kind="error",
                item=it,
                user_question=user_question,
                temperature=temperature,
                num_predict=num_predict,
                keep_alive=keep_alive,
                timeout_s=timeout_s,
            )
        except Exception:
            emap[t] = ""

    out["llm_sentences"] = {"errors": emap, "warnings": wmap}

    # make summary from first few types (optional)
    lines: List[str] = []
    if warning_summary:
        lines.append("Warnings:")
        for d in warning_summary:
            t = d.get("type")
            if isinstance(t, str) and t in wmap and wmap[t]:
                lines.append(f"- {t}: {wmap[t]}")
            elif isinstance(t, str):
                lines.append(f"- {t}: (no explanation)")
    
    if error_summary:
        lines.append("Notable errors:")
        for d in error_summary[:2]:
            t = d.get("type")
            if isinstance(t, str) and t in emap and emap[t]:
                lines.append(f"- {t}: {emap[t]}")
            elif isinstance(t, str):
                lines.append(f"- {t}: (no explanation)")
    if lines:
        out["summary"] = "\n".join(lines)

    out["_meta"] = {
        "model": model,
        "analyze_seconds": round(time.time() - t0, 3),
        "files": [fp.as_posix() for fp, _ in file_texts],
        "llm": {
            "use_llm": True,
            "temperature": float(temperature),
            "num_predict": int(num_predict),
        },
    }
    return out

