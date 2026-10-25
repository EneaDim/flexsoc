"""Launch the local RTL schematic viewer using the active FlexSoC run settings."""
from __future__ import annotations

import json
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

    run = context.paths.run
    top = str(context.values.get("SLANG_TOP") or context.paths.top)
    rtl = run / "rtl" / f"{top}.sv"
    if not rtl.is_file():
        raise FileNotFoundError(f"configured RTL top not found: {rtl}; select the correct TOP/RUN_ID")

    result = hierarchy.run(on="local")
    if result != 0:
        raise RuntimeError("Slang RTL elaboration failed; inspect dv/slang_hier/summary.json")
    ast = context.paths.slang_hier / "ast.json"
    design = RtlDesign(json.loads(ast.read_text(encoding="utf-8")),
                       root=context.project_root, top=top, run=run, verified=True)
    server = ViewerServer(("127.0.0.1", 0), design)
    url = f"http://127.0.0.1:{server.server_port}/"
    print(f"[rtl-view] IP={context.values.get('IP_NAME') or context.paths.top} top={top} run={run}")
    print(f"[rtl-view] {url} (Ctrl+C to stop)")
    try:
        if not webbrowser.open(url):
            print("[rtl-view] Browser not launched automatically; open the URL above")
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()
    return 0
