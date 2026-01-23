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

# -------- Playbook --------
DEFAULT_PLAYBOOK_PATH = Path("flexsoc_make_agent/data/verilator_playbook.json")


def _load_playbook(path: Path) -> dict:
    try:
        obj = json.loads(path.read_text(encoding="utf-8"))
        return obj if isinstance(obj, dict) else {}
    except Exception:
        return {}


def _normalize_playbook_entry(x: Any) -> Dict[str, Any]:
    """
    Ensure entry has the fields our renderer expects.
    """
    if not isinstance(x, dict):
        x = {}

    def _list_str(v: Any, max_n: int) -> List[str]:
        if not isinstance(v, list):
            return []
        out: List[str] = []
        for a in v:
            if isinstance(a, str):
                s = " ".join(a.split()).strip()
                if s:
                    out.append(s)
            if len(out) >= max_n:
                break
        return out

    cause = x.get("cause")
    cause_s = " ".join(cause.split()).strip() if isinstance(cause, str) else ""
    next_steps = _list_str(x.get("next_steps"), 3)
    make_targets = _list_str(x.get("make_targets"), 3)
    files_to_check = _list_str(x.get("files_to_check"), 5)

    # keep additional fields (suppress_with_waiver, refs, etc.) for future usage
    out = dict(x)
    out["cause"] = cause_s
    out["next_steps"] = next_steps
    out["make_targets"] = make_targets
    out["files_to_check"] = files_to_check

    conf = x.get("confidence", 0.9)  # playbook entries are usually higher confidence
    try:
        conf_f = float(conf)
    except Exception:
        conf_f = 0.9
    if conf_f < 0.0:
        conf_f = 0.0
    if conf_f > 1.0:
        conf_f = 1.0
    out["confidence"] = conf_f
    return out

from typing import Any, Dict, Optional, Tuple

def _playbook_lookup(
    playbook: Dict[str, Any],
    kind: str,          # "warning" | "error"
    gtype: str,         # e.g. "UNUSEDPARAM"
    *,
    engine: str = "verilator",
) -> Tuple[Optional[Dict[str, Any]], str]:
    """
    Returns (entry, reason). Tries multiple key conventions so playbooks can evolve.
    Accepted keys (in order):
      - f"{engine}:{gtype}"         -> "verilator:UNUSEDPARAM"
      - f"{kind}:{gtype}"           -> "warning:UNUSEDPARAM"
      - f"{kind}:{engine}:{gtype}"  -> "warning:verilator:UNUSEDPARAM"
      - gtype                       -> "UNUSEDPARAM"
    """
    if not isinstance(playbook, dict):
        return None, "no_playbook"

    t = str(gtype or "").strip()
    k = str(kind or "").strip().lower()
    eng = str(engine or "").strip().lower()

    if not t:
        return None, "empty_type"

    candidates = [
        f"{eng}:{t}",
        f"{k}:{t}",
        f"{k}:{eng}:{t}",
        t,
    ]

    for key in candidates:
        v = playbook.get(key)
        if isinstance(v, dict):
            return v, f"key:{key}"

    return None, "miss"


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

VERI_WARN_URL_PAT = re.compile(r"verilator\.org/warn/([A-Za-z0-9_]+)")

# ---------------- Local code context (mini-RAG) ----------------
SRC_LOC_PAT = re.compile(r"(?P<path>(?:ips|rtl|tb)/[^:\s]+):(?P<line>\d+):(?P<col>\d+)")

def _extract_first_src_loc(examples: List[str]) -> tuple[str, int] | None:
    """
    Try to extract the first (rel_path, line1) location from examples like:
      "tb/test_tb.sv:69:19: ..."
    Returns (path, line1) with line1 1-based.
    """
    for ex in examples or []:
        m = SRC_LOC_PAT.search(str(ex))
        if m:
            return m.group("path"), int(m.group("line"))
    return None


def _read_context_around(repo_root: Path, rel_path: str, line1: int, radius: int = 10) -> str:
    """
    Return a small code window around (line1) from repo_root/rel_path.
    line1 is 1-based line index.
    """
    try:
        rr = repo_root.resolve()
        p = (repo_root / rel_path).resolve()
    except Exception:
        return ""

    # Safety: do not allow escaping outside repo_root
    if not (rr == p or rr in p.parents):
        return ""

    if not p.exists() or not p.is_file():
        return ""

    try:
        lines = p.read_text(encoding="utf-8", errors="replace").splitlines()
    except Exception:
        return ""

    i = max(0, line1 - 1)
    a = max(0, i - radius)
    b = min(len(lines), i + radius + 1)

    out: List[str] = []
    for j in range(a, b):
        prefix = ">>" if j == i else "  "
        out.append(f"{prefix}{j+1:5d}: {lines[j]}")
    return "\n".join(out)

def read_text_tail(path: Path, max_bytes: int = DEFAULT_MAX_BYTES_PER_FILE) -> str:
    data = path.read_bytes()
    if len(data) > max_bytes:
        data = data[-max_bytes:]
    return data.decode("utf-8", errors="replace")

SRC_LOC_PAT = re.compile(r"(?P<path>(?:ips|rtl|tb)/[^:\s]+):(?P<line>\d+):(?P<col>\d+)")

def _extract_first_src_loc(examples: List[str]) -> tuple[str, int] | None:
    for ex in examples or []:
        m = SRC_LOC_PAT.search(str(ex))
        if m:
            return m.group("path"), int(m.group("line"))
    return None

def _read_context_around(repo_root: Path, rel_path: str, line1: int, radius: int = 10) -> str:
    """
    Return a small code window around (line1) from repo_root/rel_path.
    line1 is 1-based line index.
    """
    p = (repo_root / rel_path).resolve()
    rr = repo_root.resolve()
    if not (rr == p or rr in p.parents):
        return ""
    if not p.exists() or not p.is_file():
        return ""
    try:
        lines = p.read_text(encoding="utf-8", errors="replace").splitlines()
    except Exception:
        return ""
    i = max(0, line1 - 1)
    a = max(0, i - radius)
    b = min(len(lines), i + radius + 1)
    out = []
    for j in range(a, b):
        prefix = ">>" if j == i else "  "
        out.append(f"{prefix}{j+1:5d}: {lines[j]}")
    return "\n".join(out)


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
    """
    Deterministic extraction of warning/error groups from logs.

    Priority:
      1) Verilator typed warnings/errors: %Warning-XXX / %Error-XXX
      2) Verilator generic errors: %Error: ...
      3) URL-coded warnings: "... verilator.org/warn/CODE ..."
      4) Generic fallbacks: ERROR/WARNING-like lines

    Notes:
      - URL-coded warnings are grouped under their CODE (e.g. MODDUP, EOFNEWLINE),
        and we skip adding those same lines to the generic_warning bucket.
      - Generic fallbacks are intentionally broad and may over-count; use typed codes when possible.
    """
    groups: Dict[str, Dict[str, Any]] = {}

    # URL-style warning reference emitted by Verilator wrappers
    VERI_WARN_URL_PAT = re.compile(r"verilator\.org/warn/([A-Za-z0-9_]+)")

    for fp, txt in file_texts:
        lp = fp.as_posix()

        # 1) Typed Verilator warnings/errors (fast, precise)
        for m in VERI_WARN_TYPE_PAT.finditer(txt):
            _add_group(
                groups,
                kind="warning",
                gtype=m.group(1),
                line=m.group(0),
                log_path=lp,
                max_examples=max_examples_per_type,
            )

        for m in VERI_ERR_TYPE_PAT.finditer(txt):
            _add_group(
                groups,
                kind="error",
                gtype=m.group(1),
                line=m.group(0),
                log_path=lp,
                max_examples=max_examples_per_type,
            )

        # 2) Generic Verilator error lines (%Error: ...) that are not typed
        for m in VERI_ERR_GENERIC_PAT.finditer(txt):
            if m.group(0).startswith("%Error-"):
                continue
            _add_group(
                groups,
                kind="error",
                gtype="GENERIC_ERROR",
                line=m.group(0),
                log_path=lp,
                max_examples=max_examples_per_type,
            )

        # 3+4) Line-based scans (URL-coded warnings + generic fallbacks)
        for ln in txt.splitlines():
            # URL-coded warnings (preferred over generic_warning)
            mu = VERI_WARN_URL_PAT.search(ln)
            if mu:
                _add_group(
                    groups,
                    kind="warning",
                    gtype=mu.group(1),
                    line=ln,
                    log_path=lp,
                    max_examples=max_examples_per_type,
                )
                # don't also count it as generic_warning
                continue

            # Generic error fallback
            if GENERIC_ERR_LINE_PAT.search(ln):
                _add_group(
                    groups,
                    kind="error",
                    gtype="generic_error",
                    line=ln,
                    log_path=lp,
                    max_examples=max_examples_per_type,
                )

            # Generic warning fallback
            if GENERIC_WARN_LINE_PAT.search(ln):
                _add_group(
                    groups,
                    kind="warning",
                    gtype="generic_warning",
                    line=ln,
                    log_path=lp,
                    max_examples=max_examples_per_type,
                )

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

def _llm_advise_one_type(
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
    playbook_hint: Optional[Dict[str, Any]] = None,
    code_context: str = "",
) -> Dict[str, Any]:
    """
    One call per type. Returns a small JSON dict with actionable advice.
    Output contract (best effort):
      {
        "cause": str,
        "next_steps": [str, ...],          # max 3
        "make_targets": [str, ...],        # max 3
        "files_to_check": [str, ...],      # max 5
        "confidence": float               # 0..1
      }
    """
    t = str(item.get("type") or "").strip()
    examples = item.get("examples") or []
    ex1 = examples[0] if len(examples) > 0 else ""
    ex2 = examples[1] if len(examples) > 1 else ""
    logs = item.get("logs") or []
    logs_s = ", ".join(map(str, logs[:3]))

    # Normalize playbook hint into a compact string the LLM can leverage
    pb_txt = ""
    if isinstance(playbook_hint, dict) and playbook_hint:
        pb_txt = json.dumps(playbook_hint, ensure_ascii=False)

    # Make the LLM "respect" the playbook instead of replacing it.
    prompt = (
        "Return ONLY valid JSON. No markdown. No extra text.\n"
        "Schema:\n"
        '{"cause": string, "next_steps": [string,...], "make_targets": [string,...], "files_to_check": [string,...], "confidence": number}\n'
        "Rules:\n"
        "- next_steps: 1..3 short imperative actions.\n"
        "- make_targets: 0..3 Make targets (strings). Only if relevant.\n"
        "- files_to_check: 0..5 paths/globs.\n"
        "- confidence: 0..1.\n"
        "- If playbook_hint is present, you MUST start from it: reuse its cause/steps unless log details suggest a concrete improvement.\n"
        "- Do NOT output placeholders like 'make_targets' or 'files_to_check' literally.\n\n"
        f"kind: {kind}\n"
        f"type: {t}\n"
        f"target: {ctx.get('target')}\n"
        f"vars: {json.dumps(ctx.get('vars') or {}, ensure_ascii=False)}\n"
        f"cwd: {ctx.get('cwd')}\n"
        f"exit_code: {ctx.get('exit_code')}\n"
        f"logs: {logs_s}\n"
        f"example1: {ex1}\n"
        f"example2: {ex2}\n"
        f"playbook_hint_json: {pb_txt}\n"
        f"code_context:\n{code_context}\n"
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

    s = raw.strip()
    if s.startswith("```"):
        s = re.sub(r"^```[a-zA-Z0-9]*\s*", "", s)
        s = re.sub(r"\s*```$", "", s).strip()

    try:
        obj = json.loads(s)
    except Exception:
        return {"cause": "", "next_steps": [], "make_targets": [], "files_to_check": [], "confidence": 0.0}

    def _as_list_str(x, max_n: int) -> List[str]:
        if not isinstance(x, list):
            return []
        out: List[str] = []
        for a in x:
            if isinstance(a, str):
                aa = " ".join(a.split()).strip()
                if aa:
                    out.append(aa)
            if len(out) >= max_n:
                break
        return out

    cause = obj.get("cause")
    cause_s = " ".join(cause.split()).strip() if isinstance(cause, str) else ""
    next_steps = _as_list_str(obj.get("next_steps"), 3)
    make_targets = _as_list_str(obj.get("make_targets"), 3)
    files_to_check = _as_list_str(obj.get("files_to_check"), 5)

    conf = obj.get("confidence", 0.0)
    try:
        conf_f = float(conf)
    except Exception:
        conf_f = 0.0
    conf_f = max(0.0, min(1.0, conf_f))

    return {
        "cause": cause_s,
        "next_steps": next_steps,
        "make_targets": make_targets,
        "files_to_check": files_to_check,
        "confidence": conf_f,
    }

def analyze(
    run: Dict[str, Any],
    files: List[Path],
    *,
    user_question: str,
    model: str = DEFAULT_MODEL,
    head_lines: int = DEFAULT_HEAD_LINES,   # (tenuti per compatibilità, non usati qui)
    tail_lines: int = DEFAULT_TAIL_LINES,   # (tenuti per compatibilità, non usati qui)
    win: int = DEFAULT_WIN,                 # (tenuti per compatibilità, non usati qui)
    err_win: Optional[int] = None,          # (tenuti per compatibilità, non usati qui)
    max_windows: int = DEFAULT_MAX_WINDOWS, # (tenuti per compatibilità, non usati qui)
    max_bytes_per_file: int = DEFAULT_MAX_BYTES_PER_FILE,
    timeout_s: int = DEFAULT_TIMEOUT_S,
    temperature: float = DEFAULT_TEMPERATURE,
    num_predict: int = DEFAULT_NUM_PREDICT,
    keep_alive: str = DEFAULT_KEEP_ALIVE,
    playbook_path: Path = DEFAULT_PLAYBOOK_PATH,
    llm_mode: str = "off",          # "off" | "augment"
    augment_top_n: int = 8,
) -> Dict[str, Any]:
    """
    Behavior:
      - Always parses logs deterministically into error_summary / warning_summary
      - Always loads playbook and produces deterministic advice in out["advice"]
      - If llm_mode == "augment": also computes out["llm_advice"] for top-N types,
        using playbook_hint + code_context to help the LLM.
    """
    t0 = time.time()

    # Normalize llm_mode
    llm_mode_n = str(llm_mode or "").strip().lower()
    if llm_mode_n not in ("off", "augment"):
        llm_mode_n = "off"

    playbook = _load_playbook(playbook_path)

    # Read logs (tail)
    file_texts: List[Tuple[Path, str]] = []
    for fp in files:
        if not fp.exists() or not fp.is_file():
            continue
        txt = read_text_tail(fp, max_bytes=max_bytes_per_file)
        file_texts.append((fp, txt))

    if not file_texts:
        return {
            "summary": "No readable log files provided.",
            "status": "unknown",
            "error_summary": [],
            "warning_summary": [],
            "advice": {"errors": {}, "warnings": {}},
            "llm_advice": {"errors": {}, "warnings": {}},
            "_meta": {
                "model": None,
                "analyze_seconds": round(time.time() - t0, 3),
                "files": [f.as_posix() for f in files],
                "playbook_path": str(playbook_path),
                "playbook_loaded": bool(playbook),
                "playbook_hits": {"errors": {}, "warnings": {}},
                "llm": {"llm_mode": llm_mode_n},
            },
        }

    # Deterministic summaries
    error_summary, warning_summary = extract_deterministic_summaries(
        file_texts,
        max_examples_per_type=2,
    )

    # Expand generic warnings (if you keep that logic)
    if "_expand_generic_warning" in globals():
        try:
            warning_summary = _expand_generic_warning(warning_summary)  # type: ignore[name-defined]
        except Exception:
            pass

    # Totals
    err_total = sum(int(x.get("count", 0) or 0) for x in (error_summary or []))
    warn_total = sum(int(x.get("count", 0) or 0) for x in (warning_summary or []))

    # Status
    exit_code = run.get("exit_code")
    if isinstance(exit_code, int) and exit_code == 0 and err_total == 0:
        status = "success" if warn_total == 0 else "unknown"
    elif err_total > 0 or (isinstance(exit_code, int) and exit_code != 0):
        status = "failure"
    else:
        status = "unknown"

    # ---- Deterministic PLAYBOOK advice (ALWAYS) ----
    advice: Dict[str, Dict[str, Dict[str, Any]]] = {"errors": {}, "warnings": {}}
    playbook_hits: Dict[str, Dict[str, str]] = {"errors": {}, "warnings": {}}

    def _fill_playbook_advice(kind: str, items: List[Dict[str, Any]]) -> None:
        # kind: "warning" | "error"
        bucket = "warnings" if kind == "warning" else "errors"
        for it in (items or []):
            if not isinstance(it, dict):
                continue
            t = str(it.get("type") or "").strip()
            if not t:
                continue
            pb, reason = _playbook_lookup(playbook, kind, t, engine="verilator")
            if isinstance(pb, dict):
                advice[bucket][t] = pb
                playbook_hits[bucket][t] = reason

    _fill_playbook_advice("warning", warning_summary or [])
    _fill_playbook_advice("error", error_summary or [])

    out: Dict[str, Any] = {
        "summary": f"Found {err_total} error(s) and {warn_total} warning(s) across {len(file_texts)} log file(s).",
        "status": status,
        "error_summary": error_summary,
        "warning_summary": warning_summary,
        "advice": advice,  # always populated from playbook when keys match
        "llm_advice": {"errors": {}, "warnings": {}},  # filled only in augment
    }

    # If LLM is off, stop here (still includes playbook advice)
    if llm_mode_n != "augment":
        out["_meta"] = {
            "model": None,
            "analyze_seconds": round(time.time() - t0, 3),
            "files": [fp.as_posix() for fp, _ in file_texts],
            "playbook_path": str(playbook_path),
            "playbook_loaded": bool(playbook),
            "playbook_hits": playbook_hits,
            "llm": {"llm_mode": "off"},
        }
        return out

    # ---- LLM augment (top-N) using playbook_hint + context ----
    ctx = {
        "run_id": run.get("id"),
        "target": run.get("target"),
        "vars": run.get("vars") or {},
        "exit_code": run.get("exit_code"),
        "cwd": run.get("cwd"),
    }

    def _topn(summary: List[Dict[str, Any]], n: int) -> List[Dict[str, Any]]:
        s = [x for x in (summary or []) if isinstance(x, dict)]
        s.sort(key=lambda d: -int(d.get("count", 0) or 0))
        return s[: max(0, int(n))]

    def _build_code_context(item: Dict[str, Any], max_lines: int = 120) -> str:
        # Minimal deterministic context: examples only (you can later improve by slicing raw logs)
        ex = item.get("examples") or []
        ex_lines = []
        for x in ex:
            if isinstance(x, str):
                xx = x.strip()
                if xx:
                    ex_lines.append(xx)
        if not ex_lines:
            return ""
        txt = "Examples:\n" + "\n".join(ex_lines[:6])
        lines = txt.splitlines()
        if len(lines) > max_lines:
            lines = lines[:max_lines]
        return "\n".join(lines).strip()

    w_llm: Dict[str, Dict[str, Any]] = {}
    e_llm: Dict[str, Dict[str, Any]] = {}

    # warnings
    for it in _topn(warning_summary or [], augment_top_n):
        t = str(it.get("type") or "").strip()
        if not t:
            continue
        pb_hint = advice["warnings"].get(t)  # may be None
        code_ctx = _build_code_context(it)

        try:
            w_llm[t] = _llm_advise_one_type(
                model=model,
                ctx=ctx,
                kind="warning",
                item=it,
                user_question=user_question,
                temperature=temperature,
                num_predict=num_predict,
                keep_alive=keep_alive,
                timeout_s=timeout_s,
                playbook_hint=pb_hint,
                code_context=code_ctx,
            )
        except Exception:
            w_llm[t] = {"cause": "", "next_steps": [], "make_targets": [], "files_to_check": [], "confidence": 0.0}

    # errors
    for it in _topn(error_summary or [], augment_top_n):
        t = str(it.get("type") or "").strip()
        if not t:
            continue
        pb_hint = advice["errors"].get(t)
        code_ctx = _build_code_context(it)

        try:
            e_llm[t] = _llm_advise_one_type(
                model=model,
                ctx=ctx,
                kind="error",
                item=it,
                user_question=user_question,
                temperature=temperature,
                num_predict=num_predict,
                keep_alive=keep_alive,
                timeout_s=timeout_s,
                playbook_hint=pb_hint,
                code_context=code_ctx,
            )
        except Exception:
            e_llm[t] = {"cause": "", "next_steps": [], "make_targets": [], "files_to_check": [], "confidence": 0.0}

    out["llm_advice"] = {"errors": e_llm, "warnings": w_llm}

    out["_meta"] = {
        "model": model,
        "analyze_seconds": round(time.time() - t0, 3),
        "files": [fp.as_posix() for fp, _ in file_texts],
        "playbook_path": str(playbook_path),
        "playbook_loaded": bool(playbook),
        "playbook_hits": playbook_hits,
        "llm": {
            "llm_mode": "augment",
            "temperature": float(temperature),
            "num_predict": int(num_predict),
            "augment_top_n": int(augment_top_n),
        },
    }
    return out
