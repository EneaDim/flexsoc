#!/usr/bin/env python3
from __future__ import annotations
import json, subprocess, time
from pathlib import Path
import streamlit as st

def parse_first_json_object(text: str):
    """
    Robustly parse the first JSON object/array found in a text blob.
    Handles extra lines like 'Logs saved: ...'.
    """
    text = text.strip()
    if not text:
        return None
    # Fast path
    try:
        return json.loads(text)
    except Exception:
        pass

    # Try find a JSON object starting at first '{' or '['
    start_candidates = [i for i,c in enumerate(text) if c in "{["]
    for i in start_candidates:
        chunk = text[i:]
        # progressively trim from the end until it parses
        for end in range(len(chunk), max(len(chunk)-200000, 0), -1):
            try:
                return json.loads(chunk[:end])
            except Exception:
                continue
    return None


REPO_ROOT = Path("/home/eneadim/github/flexsoc").resolve()
AGENT_DIR = REPO_ROOT / "flexsoc_make_agent"
LOG_DIR   = AGENT_DIR / "logs"
SERVE     = AGENT_DIR / "serve_embed.py"

st.set_page_config(page_title="FlexSoC Browser Runner", layout="wide")

def run_serve_embed(user_text: str, dry_run: bool, catalog: str) -> dict:
    cmd = ["python3", str(SERVE), "--repo-root", ".", "--catalog", catalog]
    if dry_run:
        cmd.append("--dry-run")
    cmd.append(user_text)

    t0 = time.time()
    res = subprocess.run(cmd, cwd=str(REPO_ROOT), capture_output=True, text=True)
    dt = time.time() - t0

    out = res.stdout.strip()
    err = res.stderr.strip()
    parsed = None
    try:
        parsed = json.loads(out) if out else None
    except Exception:
        parsed = None

    return {"cmd": cmd, "rc": res.returncode, "elapsed_s": dt, "stdout": out, "stderr": err, "json": parsed}

def safe_join(root: Path, rel: str) -> Path:
    p = (root / rel).resolve()
    if p == root or root in p.parents:
        return p
    raise ValueError("Path traversal blocked")

def read_text(path: Path, max_bytes=400_000) -> str:
    b = path.read_bytes()
    if len(b) > max_bytes:
        b = b[:max_bytes]
        return b.decode("utf-8", errors="replace") + f"\n\n[...truncated to {max_bytes} bytes...]"
    return b.decode("utf-8", errors="replace")

st.title("FlexSoC: Runner + Logs + File Browser")

# -------- Left: runner --------
left, right = st.columns([1.2, 1.0], gap="large")

with left:
    st.subheader("Esegui (serve_embed.py)")
    default_cmd = 'lancia quickstart'
    user_text = st.text_input("Richiesta", value=default_cmd)

    dry_run = st.toggle("Dry-run (make -n)", value=True)

    catalogs = []
    if (AGENT_DIR / "catalog.json").exists():
        catalogs.append("flexsoc_make_agent/catalog.json")
    if (AGENT_DIR / "catalog.safe.json").exists():
        catalogs.append("flexsoc_make_agent/catalog.safe.json")
    catalog = st.selectbox("Catalog", catalogs, index=0) if catalogs else "flexsoc_make_agent/catalog.json"

    if st.button("Esegui", type="primary"):
        with st.spinner("Esecuzione..."):
            st.session_state["last_run"] = run_serve_embed(user_text, dry_run, catalog)

    r = st.session_state.get("last_run")
    if r:
        st.caption(f"rc={r['rc']}  elapsed={r['elapsed_s']:.2f}s")
        st.code(" ".join(r["cmd"]), language="bash")

        if r["json"] is not None:
            st.success("Runner output (JSON)")
            st.json(r["json"])
            results = r["json"].get("results", []) if isinstance(r["json"], dict) else []
            for i, item in enumerate(results):
                with st.expander(f"Result #{i+1} (rc={item.get('returncode')})"):
                    st.write("argv:", item.get("argv"))
                    st.write("cwd:", item.get("cwd"))
                    st.text_area("stdout", item.get("stdout",""), height=220)
                    st.text_area("stderr", item.get("stderr",""), height=120)
        else:
            st.warning("Output non-JSON (raw)")
            st.text_area("stdout", r["stdout"], height=220)
            st.text_area("stderr", r["stderr"], height=120)

# -------- Right: file browser --------
with right:
    st.subheader("File browser (repo root)")

    bases = {
        "repo root": REPO_ROOT,
        "rtl/": REPO_ROOT / "rtl",
        "tb/": REPO_ROOT / "tb",
        "sim/": REPO_ROOT / "sim",
        "syn/": REPO_ROOT / "syn",
        "log/": REPO_ROOT / "log",
        "doc/": REPO_ROOT / "doc",
        "signoff/": REPO_ROOT / "signoff",
        "agent logs/": LOG_DIR,
    }
    base_name = st.selectbox("Base", list(bases.keys()), index=0)
    base = bases[base_name]
    if not base.exists():
        st.info(f"{base} non esiste ancora.")
    else:
        # stateful path
        if "relpath" not in st.session_state:
            st.session_state["relpath"] = "."
        rel = st.text_input("Path relativo", value=st.session_state["relpath"])

        try:
            cur = safe_join(base, rel)
        except Exception as e:
            st.error(str(e))
            cur = base

        if cur.is_dir():
            st.write(f"📁 {cur}")
            entries = sorted(cur.iterdir(), key=lambda p: (p.is_file(), p.name.lower()))
            options = [".."] + [p.name + ("/" if p.is_dir() else "") for p in entries]
            pick = st.selectbox("Contenuti", options, index=0)

            if st.button("Apri"):
                if pick == "..":
                    st.session_state["relpath"] = str(Path(rel).parent)
                else:
                    name = pick[:-1] if pick.endswith("/") else pick
                    st.session_state["relpath"] = str((Path(rel) / name).as_posix())
                st.rerun()
        else:
            st.write(f"📄 {cur}  ({cur.stat().st_size} bytes)")
            suffix = cur.suffix.lower()
            texty = suffix in [".mk",".v",".sv",".tcl",".py",".md",".json",".txt",".f",".ys",".sdc",".hjson",".log",".sh",".yaml",".yml"]
            if cur.stat().st_size < 2_000_000 and texty:
                lang = "text"
                if suffix == ".py": lang = "python"
                elif suffix in [".sv",".v"]: lang = "verilog"
                elif suffix == ".tcl": lang = "tcl"
                elif suffix == ".json": lang = "json"
                elif suffix == ".md": lang = "markdown"
                st.code(read_text(cur), language=lang)
            else:
                st.warning("File grande o binario: usa download.")
            st.download_button("Download", data=cur.read_bytes(), file_name=cur.name)

st.divider()

# -------- Logs viewer --------
st.subheader("Logs (flexsoc_make_agent/logs)")

if not LOG_DIR.exists():
    st.info("Nessun log ancora.")
else:
    all_files = sorted(LOG_DIR.glob("*.*"), key=lambda p: p.stat().st_mtime, reverse=True)
    stems = []
    seen = set()
    for p in all_files:
        stem = p.name.split(".", 1)[0]
        if stem not in seen:
            seen.add(stem)
            stems.append(stem)

    if stems:
        stem = st.selectbox("Run", stems[:100])
        files = sorted(LOG_DIR.glob(stem + ".*"))
        pick = st.selectbox("File", [f.name for f in files])
        p = LOG_DIR / pick
        try:
            st.code(read_text(p), language="text")
        except Exception:
            st.download_button("Download log", data=p.read_bytes(), file_name=p.name)
    else:
        st.info("Nessun run trovato.")
