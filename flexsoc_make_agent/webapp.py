#!/usr/bin/env python3
from __future__ import annotations

import json
import subprocess
import time
from pathlib import Path
import streamlit as st

REPO_ROOT = Path("/home/eneadim/github/flexsoc").resolve()
AGENT_DIR = REPO_ROOT / "flexsoc_make_agent"
AGENT_LOGS = AGENT_DIR / "logs"
SERVE = AGENT_DIR / "serve_embed.py"

# FlexSoC artifact dirs (what you actually care about)
RESULT_DIRS = {
    "log/": REPO_ROOT / "log",
    "sim/": REPO_ROOT / "sim",
    "doc/": REPO_ROOT / "doc",
    "rtl/": REPO_ROOT / "rtl",
    "tb/": REPO_ROOT / "tb",
    "syn/": REPO_ROOT / "syn",
    "signoff/": REPO_ROOT / "signoff",
}

TEXT_EXT = {".mk",".v",".sv",".tcl",".py",".md",".json",".txt",".f",".ys",".sdc",".hjson",".log",".sh",".yaml",".yml",".csv"}
PREVIEW_LIMIT = 800_000  # bytes

st.set_page_config(page_title="FlexSoC UI", layout="wide")

def safe_join(root: Path, rel: str) -> Path:
    p = (root / rel).resolve()
    if p == root or root in p.parents:
        return p
    raise ValueError("Path traversal blocked")

def read_text(path: Path, max_bytes: int = PREVIEW_LIMIT) -> str:
    b = path.read_bytes()
    if len(b) > max_bytes:
        b = b[:max_bytes]
        return b.decode("utf-8", errors="replace") + f"\n\n[...truncated to {max_bytes} bytes...]"
    return b.decode("utf-8", errors="replace")

def nice_time(ts: float) -> str:
    return time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(ts))

def detect_latest_agent_stem(after_ts: float) -> str | None:
    if not AGENT_LOGS.exists():
        return None
    cands = sorted(AGENT_LOGS.glob("*.route.json"), key=lambda p: p.stat().st_mtime, reverse=True)
    for c in cands[:50]:
        if c.stat().st_mtime >= after_ts - 1:
            return c.name.split(".", 1)[0]
    return None

def run_agent(user_text: str, dry_run: bool, catalog: str, terminal_live: bool) -> dict:
    cmd = ["python3", str(SERVE), "--repo-root", ".", "--catalog", catalog]
    if dry_run:
        cmd.append("--dry-run")
    cmd.append(user_text)

    t0 = time.time()

    if terminal_live:
        # Inherit stdout/stderr: you'll see everything in the terminal running Streamlit.
        res = subprocess.run(cmd, cwd=str(REPO_ROOT), text=True)
        elapsed = time.time() - t0
        stem = detect_latest_agent_stem(t0)
        return {
            "cmd": cmd,
            "rc": res.returncode,
            "elapsed_s": elapsed,
            "stdout": "",
            "stderr": "",
            "json": None,
            "agent_stem": stem,
            "started_at": t0,
            "terminal_live": True,
        }

    # UI-capture mode
    res = subprocess.run(cmd, cwd=str(REPO_ROOT), capture_output=True, text=True)
    elapsed = time.time() - t0
    out = res.stdout.strip()
    err = res.stderr.strip()

    parsed = None
    if out:
        try:
            parsed = json.loads(out)
        except Exception:
            parsed = None

    # Try to get stem from stderr ("Logs saved: .../<stem>.*"), fallback to scanning
    stem = None
    for line in err.splitlines():
        if "Logs saved:" in line and "flexsoc_make_agent/logs/" in line:
            s2 = line.split("logs/")[-1].split(".*")[0].strip()
            if s2:
                stem = s2
                break
    if stem is None:
        stem = detect_latest_agent_stem(t0)

    return {
        "cmd": cmd,
        "rc": res.returncode,
        "elapsed_s": elapsed,
        "stdout": out,
        "stderr": err,
        "json": parsed,
        "agent_stem": stem,
        "started_at": t0,
        "terminal_live": False,
    }

def list_new_files(since_ts: float, roots: dict[str, Path], max_files: int = 500):
    found = []
    for label, root in roots.items():
        if not root.exists():
            continue
        for p in root.rglob("*"):
            if not p.is_file():
                continue
            try:
                mt = p.stat().st_mtime
            except Exception:
                continue
            if mt >= since_ts:
                found.append((mt, label, p))
    found.sort(reverse=True, key=lambda x: x[0])
    return found[:max_files]

def categorize_files(files):
    cats = {
        "Waveforms (.vcd/.fst)": [],
        "Logs (.log/.out/.err/.txt)": [],
        "Docs (.md)": [],
        "RTL / TB (.sv/.v)": [],
        "Reports (syn/signoff)": [],
        "Other": [],
    }
    for mt, label, p in files:
        rel = str(p.relative_to(REPO_ROOT))
        suf = p.suffix.lower()
        item = (mt, label, p, rel)

        if suf in {".vcd", ".fst"}:
            cats["Waveforms (.vcd/.fst)"].append(item)
        elif suf in {".log", ".out", ".err", ".txt"}:
            cats["Logs (.log/.out/.err/.txt)"].append(item)
        elif suf == ".md":
            cats["Docs (.md)"].append(item)
        elif suf in {".sv", ".v"}:
            cats["RTL / TB (.sv/.v)"].append(item)
        elif ("syn/" in rel) or ("signoff/" in rel) or suf in {".rpt"}:
            cats["Reports (syn/signoff)"].append(item)
        else:
            cats["Other"].append(item)

    for k in cats:
        cats[k].sort(reverse=True, key=lambda x: x[0])
    return cats

st.title("FlexSoC UI (Results-first)")

tab_run, tab_art, tab_repo, tab_agent = st.tabs(
    ["Run", "Artifacts (FlexSoC results)", "Repo browser", "Agent logs (debug)"]
)

with tab_run:
    st.subheader("Run FlexSoC via natural language")
    user_text = st.text_input("Request", value="avvia il quickstart dell'IP")
    col1, col2, col3 = st.columns([1,1,1])
    with col1:
        dry_run = st.toggle("Dry-run (make -n) — NO files will be created", value=True)
    with col2:
        terminal_live = st.toggle("Show live output in terminal", value=True)
    with col3:
        show_agent_debug = st.toggle("Show agent debug in UI", value=False)

    catalogs = []
    if (AGENT_DIR / "catalog.json").exists():
        catalogs.append("flexsoc_make_agent/catalog.json")
    if (AGENT_DIR / "catalog.safe.json").exists():
        catalogs.append("flexsoc_make_agent/catalog.safe.json")
    catalog = st.selectbox("Catalog", catalogs, index=0) if catalogs else "flexsoc_make_agent/catalog.json"

    cA, cB = st.columns([1, 1])
    with cA:
        if st.button("Run", type="primary"):
            with st.spinner("Running..."):
                r = run_agent(user_text, dry_run, catalog, terminal_live)
            st.session_state["last_run"] = r
    with cB:
        if st.button("Clear last run"):
            st.session_state.pop("last_run", None)

    r = st.session_state.get("last_run")
    if r:
        st.caption(f"rc={r['rc']}  elapsed={r['elapsed_s']:.2f}s  started={nice_time(r['started_at'])}")
        st.code(" ".join(r["cmd"]), language="bash")

        if r["agent_stem"]:
            st.info(f"Agent log stem: {r['agent_stem']}  (see Agent logs tab)")
        else:
            st.info("Agent log stem not detected yet (check Agent logs tab).")

        if show_agent_debug:
            with st.expander("Agent raw output"):
                st.text_area("stdout (captured)", r["stdout"], height=160)
                st.text_area("stderr (captured)", r["stderr"], height=120)
        else:
            st.caption("Agent output hidden (results are in Artifacts tab).")

with tab_art:
    st.subheader("Artifacts produced by FlexSoC")
    r = st.session_state.get("last_run")
    if not r:
        st.info("Run something in the **Run** tab first. Then artifacts will appear here.")
    else:
        since_ts = r["started_at"]
        st.caption(f"Showing files modified after: {nice_time(since_ts)}")

        files = list_new_files(since_ts, RESULT_DIRS)
        cats = categorize_files(files)
        total = sum(len(v) for v in cats.values())
        st.write(f"Found **{total}** updated files (limited view).")

        st.markdown("### Quick picks")
        quick = []
        if cats["Waveforms (.vcd/.fst)"]:
            quick.append(cats["Waveforms (.vcd/.fst)"][0])
        if cats["Logs (.log/.out/.err/.txt)"]:
            quick.append(cats["Logs (.log/.out/.err/.txt)"][0])
        if cats["Docs (.md)"]:
            quick.append(cats["Docs (.md)"][0])

        if quick:
            for mt, _, _, rel in quick:
                st.write(f"- `{rel}`  (mtime: {nice_time(mt)})")
        else:
            st.write("- (No obvious artifacts yet)")

        st.markdown("---")
        st.markdown("### Browse artifacts by category")
        cat_name = st.selectbox("Category", list(cats.keys()), index=0)
        items = cats[cat_name]

        if not items:
            st.info("No files in this category for the last run.")
        else:
            options = [f"{nice_time(mt)} | {rel}" for mt, _, _, rel in items[:200]]
            choice = st.selectbox("File", options, index=0)
            idx = options.index(choice)
            mt, _, p, rel = items[idx]

            st.write(f"**Path:** `{rel}`")
            st.write(f"**Modified:** {nice_time(mt)}")
            st.write(f"**Size:** {p.stat().st_size} bytes")

            suf = p.suffix.lower()
            if suf in TEXT_EXT and p.stat().st_size <= 2_000_000:
                if suf == ".md":
                    st.markdown(read_text(p))
                else:
                    lang = "text"
                    if suf == ".py": lang = "python"
                    elif suf in {".sv",".v"}: lang = "verilog"
                    elif suf == ".tcl": lang = "tcl"
                    elif suf == ".json": lang = "json"
                    st.code(read_text(p), language=lang)
            else:
                st.warning("Binary or large file: use download.")
            st.download_button("Download", data=p.read_bytes(), file_name=p.name)

        st.markdown("---")
        st.markdown("### GUI note (gtkwave)")
        st.write(
            "If a target launches GUI tools (e.g. `make view` → `gtkwave`), "
            "they open on the machine running Streamlit. "
            "For remote sessions you need X forwarding / WSLg."
        )

with tab_repo:
    st.subheader("Repository browser")
    bases = {"repo root": REPO_ROOT} | RESULT_DIRS | {"agent logs/": AGENT_LOGS}
    base_name = st.selectbox("Base", list(bases.keys()), index=0)
    base = bases[base_name]

    if not base.exists():
        st.info(f"{base} does not exist yet.")
    else:
        if "repo_rel" not in st.session_state:
            st.session_state["repo_rel"] = "."
        rel = st.text_input("Relative path", value=st.session_state["repo_rel"])

        try:
            cur = safe_join(base, rel)
        except Exception as e:
            st.error(str(e))
            cur = base

        if cur.is_dir():
            st.write(f"📁 {cur}")
            entries = sorted(cur.iterdir(), key=lambda p: (p.is_file(), p.name.lower()))
            options = [".."] + [p.name + ("/" if p.is_dir() else "") for p in entries]
            pick = st.selectbox("Contents", options, index=0)
            if st.button("Open"):
                if pick == "..":
                    st.session_state["repo_rel"] = str(Path(rel).parent)
                else:
                    name = pick[:-1] if pick.endswith("/") else pick
                    st.session_state["repo_rel"] = str((Path(rel) / name).as_posix())
                st.rerun()
        else:
            st.write(f"📄 {cur}")
            st.caption(f"Size: {cur.stat().st_size} bytes")
            suf = cur.suffix.lower()
            if suf in TEXT_EXT and cur.stat().st_size <= 2_000_000:
                st.code(read_text(cur), language="text")
            else:
                st.warning("Binary or large file: use download.")
            st.download_button("Download", data=cur.read_bytes(), file_name=cur.name)

with tab_agent:
    st.subheader("Agent logs (debug)")
    if not AGENT_LOGS.exists():
        st.info("No agent logs directory found.")
    else:
        files = sorted(AGENT_LOGS.glob("*.*"), key=lambda p: p.stat().st_mtime, reverse=True)
        stems = []
        seen = set()
        for fp in files:
            stem = fp.name.split(".", 1)[0]
            if stem not in seen:
                seen.add(stem)
                stems.append(stem)

        stem = st.selectbox("Run", stems[:100]) if stems else None
        if stem:
            candidates = sorted(AGENT_LOGS.glob(stem + ".*"))
            pick = st.selectbox("File", [c.name for c in candidates])
            p = AGENT_LOGS / pick
            st.code(read_text(p), language="text")
            st.download_button("Download", data=p.read_bytes(), file_name=p.name)
