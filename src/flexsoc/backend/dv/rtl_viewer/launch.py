"""Launch the local RTL schematic viewer using the active FlexSoC run settings."""
from __future__ import annotations

import json
import os
import time
import webbrowser
from pathlib import Path

from ...core import BackendContext
from ..lint.slang_hier import SlangHierarchy
from .model import RtlDesign
from .server import ViewerServer


def open_viewer(context: BackendContext, hierarchy: SlangHierarchy, *, on: str = "local") -> int:
    """Elaborate the current IP, then serve its verified AST on localhost.

    The Slang run is refreshed on each invocation, avoiding stale diagrams after
    edited RTL. Neither qualification evidence nor authored RTL is modified.
    """
    if on != "local":
        raise ValueError("rtl-view is interactive and only supports local execution")

    started = time.perf_counter()
    def log(message: str) -> None:
        print(f"[rtl-view] {message}", flush=True)

    run = context.paths.run
    top = str(context.values.get("SLANG_TOP") or context.paths.top)
    rtl = run / "rtl" / f"{top}.sv"
    if not rtl.is_file():
        raise FileNotFoundError(f"configured RTL top not found: {rtl}; select the correct TOP/RUN_ID")

    log(f"Run: {run}")
    log(f"Top: {top} | interface: {context.values.get('REG_ITF', '?')}")
    log("Slang: elaborating current RTL...")
    slang_started = time.perf_counter()
    result = hierarchy.run(on="local")
    log(f"Slang finished: rc={result}, elapsed={time.perf_counter()-slang_started:.2f}s")
    if result != 0:
        raise RuntimeError("Slang RTL elaboration failed; inspect dv/slang_hier/summary.json")
    ast = context.paths.slang_hier / "ast.json"
    log(f"AST: {ast} ({ast.stat().st_size / (1024*1024):.1f} MiB)")
    index_started = time.perf_counter()
    design = RtlDesign(json.loads(ast.read_text(encoding="utf-8")),
                       root=context.project_root, top=top, run=run, verified=True)
    log(f"Model indexed: scopes={len(design.scopes)}, elapsed={time.perf_counter()-index_started:.2f}s")
    from .server import ASSETS
    import hashlib
    layout_asset = ASSETS / "layout-engine.js"
    log(f"Serving frontend from: {ASSETS.resolve()}")
    log(f"layout-engine.js SHA256: {hashlib.sha256(layout_asset.read_bytes()).hexdigest()[:16] if layout_asset.is_file() else 'MISSING'}")
    server = ViewerServer(("127.0.0.1", 0), design)
    url = f"http://127.0.0.1:{server.server_port}/"
    log("Verify served assets at: " + url + "api/runtime")
    log(f"Ready after {time.perf_counter()-started:.2f}s | HTTP log: {'verbose' if os.environ.get('FLEXSOC_RTL_HTTP_LOG') == '1' else 'errors only'}")
    # WSL can run a localhost server even when Windows executable interop is disabled.
    # Avoid invoking wslview/cmd.exe in that case; do not change system configuration.
    browser_enabled = os.environ.get("FLEXSOC_RTL_NO_BROWSER", "").lower() not in ("1", "true", "yes")
    if os.environ.get("WSL_DISTRO_NAME") and not Path("/proc/sys/fs/binfmt_misc/WSLInterop").exists():
        browser_enabled = False
        log("WSL interop unavailable: open URL manually; viewer server remains available")
    foreground = os.environ.get("FLEXSOC_RTL_FOREGROUND", "").lower() in ("1", "true", "yes")
    if not foreground:
        from .background import serve_detached
        serve_detached(server, run=run, url=url)
        try:
            if browser_enabled and not webbrowser.open(url):
                print("[rtl-view] Browser not launched automatically; open the URL above")
        except Exception:
            print("[rtl-view] Browser not launched automatically; open the URL above")
        return 0
    print(f"[rtl-view] {url} (Ctrl+C to stop)")
    try:
        if browser_enabled and not webbrowser.open(url):
            print("[rtl-view] Browser not launched automatically; open the URL above")
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()
    return 0
