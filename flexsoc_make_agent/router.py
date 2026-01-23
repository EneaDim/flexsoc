#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import re
import time
import urllib.request
from http.server import BaseHTTPRequestHandler, HTTPServer
from pathlib import Path
from typing import Any, Dict, List, Tuple

OLLAMA_EMBED_URL = "http://localhost:11434/api/embeddings"

# ---------------- Embedding utils ----------------
def embed(model: str, text: str) -> List[float]:
    payload = json.dumps({"model": model, "prompt": text}).encode("utf-8")
    req = urllib.request.Request(
        OLLAMA_EMBED_URL, data=payload, headers={"Content-Type": "application/json"}
    )
    with urllib.request.urlopen(req, timeout=60) as r:
        out = json.loads(r.read().decode("utf-8"))
    return out["embedding"]

def dot(a, b): return sum(x * y for x, y in zip(a, b))
def norm(a): return math.sqrt(sum(x * x for x in a))

def cosine(a, b) -> float:
    na, nb = norm(a), norm(b)
    if na == 0 or nb == 0:
        return 0.0
    return dot(a, b) / (na * nb)

def guess_lang(user_text: str) -> str:
    lt = user_text.lower()
    en_markers = [" help", "please", " how ", " run ", " show ", " install ", " setup "]
    it_markers = [" aiuto", " come ", " per favore", " esegui", " mostra", " installa", " avvia", " setup "]

    en_score = sum(1 for m in en_markers if m in lt)
    it_score = sum(1 for m in it_markers if m in lt)

    if en_score > it_score:
        return "en"
    if it_score > en_score:
        return "it"

    # fallback: very short queries → treat as English to avoid "help me" routed with IT embeddings
    if len(lt.split()) <= 3:
        return "en"
    return "it"


# ---------------- Tokenization (Patch 2) ----------------
WORD_RE = re.compile(r"[a-z0-9_]+")

def tokenize(s: str) -> List[str]:
    return WORD_RE.findall((s or "").lower())


# ---------------- Query heuristics ----------------
def contains_waveform(q: str) -> bool:
    ql = q.lower()
    return any(k in ql for k in ["waveform", "waveforms", "wave", "gtkwave", "vcd", "fst", "trace", "segnali"])

def contains_ip_help(q: str) -> bool:
    ql = q.lower()
    return ("ip" in ql) and (("help" in ql) or ("aiuto" in ql))

def contains_quickstart(q: str) -> bool:
    ql = q.lower()
    return ("quickstart" in ql) or ("bootstrap" in ql) or ("inizial" in ql) or ("start" in ql)

def contains_ip_quickstart(q: str) -> bool:
    ql = q.lower()
    return ("ip" in ql) and contains_quickstart(q)

# ---------------- Override rules ----------------
EXEC_VERBS = r"(?:make|lancia|esegui|run|avvia|start|apri|mostra|visualizza)"

CLEAN_TRIGGERS = (
    "clean", "pulisci", "ripulisci", "cancella", "rimuovi", "elimina",
    "svuota", "reset", "wipe", "delete", "remove", "clear"
)

CLEAN_OBJECT_ALIASES = {
    # doc
    "doc": "clean_doc",
    "docs": "clean_doc",
    "documentation": "clean_doc",
    "documentazione": "clean_doc",
    "regmap": "clean_doc",
    "csr": "clean_doc",
    "pdf": "clean_doc",
    "html": "clean_doc",

    # log
    "log": "clean_log",
    "logs": "clean_log",

    # rtl
    "rtl": "clean_rtl",
    "stub": "clean_rtl",
    "stubs": "clean_rtl",
    "filelist": "clean_rtl",
    "filelists": "clean_rtl",

    # sim / waves
    "sim": "clean_sim",
    "simulation": "clean_sim",
    "simulazione": "clean_sim",
    "wave": "clean_sim",
    "waves": "clean_sim",
    "waveform": "clean_sim",
    "waveforms": "clean_sim",
    "vcd": "clean_sim",
    "fst": "clean_sim",

    # cocotb
    "cocotb": "clean_cocotb",
    "python": "clean_cocotb",
    "pytest": "clean_cocotb",

    # syn
    "syn": "clean_syn",
    "synthesis": "clean_syn",
    "sintesi": "clean_syn",
    "netlist": "clean_syn",
    "yosys": "clean_syn",

    # signoff / sta / power
    "signoff": "clean_signoff",
    "sta": "clean_signoff",
    "timing": "clean_signoff",
    "slack": "clean_signoff",
    "power": "clean_signoff",
    "sdf": "clean_signoff",

    # pnr
    "pnr": "clean_pnr",
    "place": "clean_pnr",
    "route": "clean_pnr",
    "routing": "clean_pnr",
    "openroad": "clean_pnr",
    "floorplan": "clean_pnr",
    "def": "clean_pnr",
    "gds": "clean_pnr",

    # fsm
    "fsm": "clean_fsm",
    "state machine": "clean_fsm",
    "macchina a stati": "clean_fsm",

    # soc
    "soc": "clean_soc",
    "crossbar": "clean_soc",
    "xbar": "clean_soc",
    "fabric": "clean_soc",

    # sw
    "sw": "clean_sw",
    "software": "clean_sw",
    "firmware": "clean_sw",
    "toolchain": "clean_sw",

    # vendor/deps
    "vendor": "clean_vendor",
    "third-party": "clean_vendor",
    "dependencies": "clean_vendor",
    "dipendenze": "clean_vendor",

    # scope
    "subdir": "clean_subdir",
    "subdirectory": "clean_subdir",
    "module": "clean_subdir",
    "modulo": "clean_subdir",
    "here": "clean_subdir",
    "qui": "clean_subdir",
    "questa cartella": "clean_subdir",
    "directory corrente": "clean_subdir",
}

def clean_target_override(user_text: str, allowed_targets: set[str]) -> str | None:
    """
    Returns a clean_* target ONLY if the request contains a cleaning trigger
    (clean/pulisci/remove/...) AND a recognizable object (doc/sim/syn/...).
    Never triggers for plain 'doc', 'sim', etc. without a clean trigger.
    """
    lt = user_text.lower()

    # 1) must contain a clean trigger as a standalone word-ish token
    if not any(re.search(rf"\b{re.escape(t)}\b", lt) for t in CLEAN_TRIGGERS):
        return None

    # 2) special cases: "clean all", "pulisci tutto", "reset totale"
    if re.search(r"\b(all|everything|tutto|totale|completo)\b", lt):
        if "clean_all" in allowed_targets and re.search(r"\b(deep|nuclear|profondo|totale)\b", lt):
            return "clean_all"
        if "clean" in allowed_targets:
            return "clean"

    # 3) match object aliases (prefer longer phrases first)
    for phrase, tgt in sorted(CLEAN_OBJECT_ALIASES.items(), key=lambda x: len(x[0]), reverse=True):
        if phrase in lt and tgt in allowed_targets:
            return tgt

    # 4) if user says just "clean" or "pulisci" without object, don't guess a subtype
    return "clean" if "clean" in allowed_targets and re.search(r"\bclean\b", lt) else None

HELP_TRIGGERS = ("help", "aiuto", "assist", "support")
HELP_SCOPES = {
    "help_ip": ("ip", "peripheral", "regmap", "csr", "rtl"),
    "help_soc": ("soc", "system", "xbar", "crossbar", "fabric"),
    "help_doc": ("doc", "docs", "documentation", "regmap", "hjson"),
    "help_fsm": ("fsm", "state machine", "macchina a stati"),
}

def help_target_override(user_text: str, allowed_targets: set[str]) -> str | None:
    lt = user_text.lower()

    # must ask for help
    if not any(re.search(rf"\b{re.escape(t)}\b", lt) for t in HELP_TRIGGERS):
        return None

    # if a specific scope is clearly mentioned, route to that
    for tgt, kws in HELP_SCOPES.items():
        if tgt in allowed_targets and any(k in lt for k in kws):
            return tgt

    # otherwise prefer generic help (if it exists)
    return "help" if "help" in allowed_targets else None

def explicit_target_override(user_text: str, allowed_targets: set[str]) -> str | None:
    lt = user_text.lower().strip()

    # 0) exact match (VERY IMPORTANT): "setup" -> setup
    if lt in {t.lower() for t in allowed_targets}:
        # return the canonical cased target from allowed_targets
        for t in allowed_targets:
            if t.lower() == lt:
                return t

    # 1) verb + target (make setup)
    wants_path = ("timing path" in lt) or ("critical path" in lt) or re.search(r"\bpath\b", lt) is not None
    m = re.search(rf"\b{EXEC_VERBS}\s+([A-Za-z0-9_\-]+)\b", user_text, flags=re.IGNORECASE)
    if m:
        t = m.group(1)
        if t in allowed_targets:
            if t == "view" and wants_path and "path_view" in allowed_targets:
                return "path_view"
            return t

    # 2) "view" alone
    if re.fullmatch(r"\s*view\s*", lt) and "view" in allowed_targets:
        return "view"

    return None

# ---------------- Loading & building embeddings ----------------
def pack_for_embedding(target: str, risk: str, lang: str, et: dict) -> str:
    """
    Build a compact but semantically rich text for embeddings
    from embedding_text.<lang>.
    """
    title = (et.get("title") or "").strip()
    summary = (et.get("summary") or "").strip()
    queries = et.get("queries") or []
    keywords = et.get("keywords") or []
    negative = et.get("negative") or []

    q_block = "\n".join(f"- {q}".strip() for q in queries[:10] if str(q).strip())
    k_block = ", ".join(str(k).strip() for k in keywords[:25] if str(k).strip())
    n_block = ", ".join(str(n).strip() for n in negative[:15] if str(n).strip())

    parts = [f"target: {target}", f"risk: {risk}", f"lang: {lang}"]
    if title:
        parts.append(f"title: {title}")
    if summary:
        parts.append(f"summary: {summary}")
    if q_block:
        parts.append(f"user queries:\n{q_block}")
    if k_block:
        parts.append(f"keywords: {k_block}")
    if n_block:
        parts.append(f"avoid / not this: {n_block}")

    return "\n".join(parts)

def load_targets_json(path: Path) -> List[Dict[str, Any]]:
    obj = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(obj, list):
        raise SystemExit(f"{path} must contain a JSON list of target objects.")
    return obj

def build_embeddings(
    targets: List[Dict[str, Any]],
    embed_model: str,
) -> List[Dict[str, Any]]:
    out: List[Dict[str, Any]] = []
    for it in targets:
        target = it["target"]
        risk = it.get("risk", "low")
        depends_on = it.get("depends_on", [])

        et_all = it.get("embedding_text") or {}
        et_en = et_all.get("en") or {}
        et_it = et_all.get("it") or {}

        text_en = pack_for_embedding(target, risk, "en", et_en)
        text_it = pack_for_embedding(target, risk, "it", et_it)

        emb_en = embed(embed_model, text_en)
        emb_it = embed(embed_model, text_it)

        # NEW: keep lexical fields for Patch 2 scoring
        out.append({
            "target": target,
            "risk": risk,
            "depends_on": depends_on,
            "embedding_en": emb_en,
            "embedding_it": emb_it,
            "keywords_en": (et_en.get("keywords") or []),
            "keywords_it": (et_it.get("keywords") or []),
            "negative_en": (et_en.get("negative") or []),
            "negative_it": (et_it.get("negative") or []),
        })

    return out

# ---------------- Router ----------------
def choose_target(
    db: List[Dict[str, Any]],
    qvec: List[float],
    topk: int,
    min_score: float,
    soft_gap: float,
    user_text: str,
    lang: str,  # kept for compat/telemetry; not used for scoring
) -> Tuple[str, float, List[Tuple[float, str, str]]]:
    q_tokens = set(tokenize(user_text))

    scored: List[Tuple[float, str, str]] = []

    for it in db:
        target = it["target"]
        risk = it.get("risk", "low")

        # bilingual embedding score: max(en, it) with legacy fallback
        emb_en = it.get("embedding_en")
        emb_it = it.get("embedding_it")
        emb_legacy = it.get("embedding")

        s_candidates: List[float] = []
        if emb_en is not None:
            s_candidates.append(cosine(qvec, emb_en))
        if emb_it is not None:
            s_candidates.append(cosine(qvec, emb_it))
        if not s_candidates and emb_legacy is not None:
            s_candidates.append(cosine(qvec, emb_legacy))

        s = max(s_candidates) if s_candidates else 0.0

        # Patch 2: negative penalty + keywords tie-break
        neg_en = it.get("negative_en") or []
        neg_it = it.get("negative_it") or []
        kw_en = it.get("keywords_en") or []
        kw_it = it.get("keywords_it") or []

        neg_tokens = set(tokenize(" ".join(map(str, neg_en + neg_it))))
        kw_tokens = set(tokenize(" ".join(map(str, kw_en + kw_it + [target]))))

        if neg_tokens and (q_tokens & neg_tokens):
            s -= 0.08  # tune 0.05..0.12

        overlap = len(q_tokens & kw_tokens)
        if overlap:
            s += 0.01 * min(overlap, 5)

        scored.append((s, target, risk))

    scored.sort(reverse=True, key=lambda x: x[0])

    top = scored[:topk] if scored else []
    best = scored[0] if scored else (0.0, "help", "low")

    chosen = best[1] if best[0] >= min_score else "help"

    top_targets = {t: s for s, t, _ in top}

    if contains_waveform(user_text):
        prefer = ["view", "tb_view", "view_cocotb", "view_presyn", "view_syn", "view_signoff", "view_pnr"]
        for t in prefer:
            if t in top_targets and (best[0] - top_targets[t] <= soft_gap):
                chosen = t
                break

    if contains_ip_help(user_text) and "help_ip" in top_targets:
        if best[0] - top_targets["help_ip"] <= soft_gap:
            chosen = "help_ip"

    # IMPORTANT: only IP quickstart; no generic quickstart override
    if contains_ip_quickstart(user_text) and "ip_start" in top_targets:
        if best[0] - top_targets["ip_start"] <= soft_gap:
            chosen = "ip_start"

    return chosen, float(best[0]), top

MAKE_ASSIGN_RE = re.compile(r'(?<!\S)([A-Za-z_][A-Za-z0-9_]*)=([^\s]+)')

def extract_make_vars(text: str) -> tuple[str, dict[str, str]]:
    vars_out: dict[str, str] = {}

    def _repl(m: re.Match) -> str:
        k, v = m.group(1), m.group(2)
        vars_out[k] = v
        return ""  # remove token from routing text

    cleaned = MAKE_ASSIGN_RE.sub(_repl, text)
    cleaned = re.sub(r"\s+", " ", cleaned).strip()
    return cleaned, vars_out

def route_query(
    db: List[Dict[str, Any]],
    embed_model: str,
    user_text: str,
    topk: int,
    min_score: float,
    soft_gap: float,
) -> Dict[str, Any]:
    allowed_targets = {it["target"] for it in db}

    # Extract VAR=VALUE tokens (e.g., TOP=test-ip) before routing
    routed_text, vars_found = extract_make_vars(user_text)

    forced: str | None = None
    override_reason: str | None = None

    # 1) Explicit "make <target>" always wins
    forced = explicit_target_override(routed_text, allowed_targets)
    if forced is not None:
        override_reason = "explicit_target"

    if forced is None:
        forced = help_target_override(routed_text, allowed_targets)
        if forced is not None:
            override_reason = "help_intent"

    if forced is None:
        forced = clean_target_override(routed_text, allowed_targets)
        if forced is not None:
            override_reason = "clean_intent"

    lang = None

    if forced is not None:
        chosen = forced
        best_score = 1.0
        risk = next((it.get("risk", "low") for it in db if it["target"] == forced), "low")
        top = [(1.0, forced, risk)]
    else:
        # still compute for telemetry
        lang = guess_lang(routed_text)
        qvec = embed(embed_model, routed_text)
        chosen, best_score, top = choose_target(db, qvec, topk, min_score, soft_gap, routed_text, lang)

    return {
        "query": user_text,                 # original
        "query_routed": routed_text,        # cleaned for routing
        "vars": vars_found,
        "chosen": chosen,
        "best_score": round(float(best_score), 4),
        "topk": [{"score": round(float(s), 4), "target": t, "risk": r} for s, t, r in top],
        "override": forced is not None,
        "override_reason": override_reason,
        "lang": lang if forced is None else None,
        "ts": int(time.time()),
    }

# ---------------- Simple HTTP server ----------------
class RouterHandler(BaseHTTPRequestHandler):
    db: List[Dict[str, Any]] = []
    embed_model: str = "nomic-embed-text"
    topk: int = 5
    min_score: float = 0.35
    soft_gap: float = 0.03

    def _json(self, code: int, obj: Dict[str, Any]):
        body = json.dumps(obj, ensure_ascii=False).encode("utf-8")
        self.send_response(code)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        if self.path.rstrip("/") == "/health":
            self._json(200, {"ok": True})
        else:
            self._json(404, {"ok": False, "error": "not_found"})

    def do_POST(self):
        if self.path.rstrip("/") != "/route":
            self._json(404, {"ok": False, "error": "not_found"})
            return
        try:
            n = int(self.headers.get("Content-Length", "0"))
            raw = self.rfile.read(n).decode("utf-8")
            data = json.loads(raw) if raw else {}
            q = (data.get("query") or "").strip()
            if not q:
                self._json(400, {"ok": False, "error": "missing_query"})
                return
            out = route_query(
                self.db, self.embed_model, q,
                self.topk, self.min_score, self.soft_gap
            )
            out["ok"] = True
            self._json(200, out)
        except Exception as e:
            self._json(500, {"ok": False, "error": "internal_error", "details": str(e)})

def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)

    # build
    apb = sub.add_parser("build", help="Build targets_embeddings.json from targets.json")
    apb.add_argument("--targets", default="flexsoc_make_agent/data/targets.json")
    apb.add_argument("--out", default="flexsoc_make_agent/data/targets_embeddings.json")
    apb.add_argument("--embed-model", default="nomic-embed-text")

    # route
    apr = sub.add_parser("route", help="Route a query and print JSON")
    apr.add_argument("--db", default="flexsoc_make_agent/data/targets_embeddings.json")
    apr.add_argument("--embed-model", default="nomic-embed-text")
    apr.add_argument("--topk", type=int, default=5)
    apr.add_argument("--min-score", type=float, default=0.35)
    apr.add_argument("--soft-gap", type=float, default=0.03)
    apr.add_argument("query", nargs="+")

    # serve
    aps = sub.add_parser("serve", help="HTTP server: POST /route, GET /health")
    aps.add_argument("--db", default="flexsoc_make_agent/data/targets_embeddings.json")
    aps.add_argument("--embed-model", default="nomic-embed-text")
    aps.add_argument("--host", default="127.0.0.1")
    aps.add_argument("--port", type=int, default=8099)
    aps.add_argument("--topk", type=int, default=5)
    aps.add_argument("--min-score", type=float, default=0.35)
    aps.add_argument("--soft-gap", type=float, default=0.03)

    args = ap.parse_args()

    if args.cmd == "build":
        targets = load_targets_json(Path(args.targets))
        db = build_embeddings(targets, args.embed_model)
        Path(args.out).write_text(json.dumps(db), encoding="utf-8")
        print(f"Wrote {args.out} ({len(db)} targets)")
        return

    if args.cmd == "route":
        user_text = " ".join(args.query).strip()
        db = json.loads(Path(args.db).read_text(encoding="utf-8"))
        out = route_query(db, args.embed_model, user_text, args.topk, args.min_score, args.soft_gap)
        print(json.dumps(out, indent=2, ensure_ascii=False))
        return

    if args.cmd == "serve":
        RouterHandler.db = json.loads(Path(args.db).read_text(encoding="utf-8"))
        RouterHandler.embed_model = args.embed_model
        RouterHandler.topk = args.topk
        RouterHandler.min_score = args.min_score
        RouterHandler.soft_gap = args.soft_gap

        httpd = HTTPServer((args.host, args.port), RouterHandler)
        print(f"Listening on http://{args.host}:{args.port}  (POST /route, GET /health)")
        httpd.serve_forever()

if __name__ == "__main__":
    main()

