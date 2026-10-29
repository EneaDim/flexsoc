"""Localhost-only graph queries and static workbench. No application server deps."""
from __future__ import annotations

from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
import hashlib
import os
import sys
from pathlib import Path
from urllib.parse import parse_qs, urlsplit

from .model import RtlDesign


ASSETS = Path(__file__).with_name("web")


class ViewerServer(ThreadingHTTPServer):
    allow_reuse_address = True
    daemon_threads = True

    def __init__(self, address: tuple[str, int], design: RtlDesign):
        self.design = design
        super().__init__(address, ViewerHandler)


class ViewerHandler(BaseHTTPRequestHandler):
    server: ViewerServer

    def do_GET(self) -> None:
        route = urlsplit(self.path)
        params = parse_qs(route.query)
        def arg(key: str, default: str = "") -> str:
            return params.get(key, [default])[0]
        try:
            if route.path.startswith("/api/"):
                resource = route.path.removeprefix("/api/")
                design = self.server.design
                path = arg("path", "/")
                if resource == "runtime":
                    assets = {}
                    for filename in ("app.js", "layout-engine.js", "router.js", "elk-adapter.js"):
                        asset = ASSETS / filename
                        assets[filename] = hashlib.sha256(asset.read_bytes()).hexdigest()[:16] if asset.is_file() else "MISSING"
                    payload = {"asset_dir": str(ASSETS.resolve()), "assets": assets,
                               "pid": os.getpid(), "run": str(getattr(design, "run", ""))}
                elif resource == "overview":
                    payload = design.overview()
                elif resource == "hierarchy":
                    payload = design.hierarchy_children(path, offset=int(arg("offset", "0")),
                                                        limit=int(arg("limit", "64")))
                elif resource == "diagram":
                    payload = design.diagram(path, explode=arg("explode") == "1",
                                             expanded=tuple(filter(None, arg("expand").split("|"))),
                                             limit=int(arg("limit", "320")))
                elif resource == "behavior":
                    payload = design.behavior(path)
                elif resource == "lowering":
                    payload = design.lowering(path)
                elif resource == "circuit":
                    payload = design.circuit(path)
                elif resource == "canonical":
                    payload = design.canonical(path)
                elif resource == "schematic":
                    payload = design.schematic(path)
                elif resource == "source":
                    payload = design.source(path)
                elif resource == "occurrences":
                    payload = design.occurrences(path, arg("signal"))
                elif resource == "follow":
                    payload = design.follow(path, arg("child"), arg("signal"))
                elif resource == "cone":
                    payload = design.cone(path, arg("from"), arg("to"))
                elif resource == "evidence":
                    payload = design.evidence()
                elif resource == "lint":
                    payload = design.lint(path)
                else:
                    self.send_error(404)
                    return
                self._respond(json.dumps(payload).encode(), "application/json; charset=utf-8")
                return
            static = {"/": "index.html", "/index.html": "index.html", "/app.js": "app.js", "/bootstrap-guard.js": "bootstrap-guard.js", "/lazy-hierarchy.js": "lazy-hierarchy.js", "/hierarchy-tree.js": "hierarchy-tree.js", "/router.js": "router.js", "/layout-engine.js": "layout-engine.js", "/elk-adapter.js": "elk-adapter.js", "/elk.bundled.js": "elk.bundled.js", "/style.css": "style.css", "/cad": "cad.html", "/cad.html": "cad.html", "/cad.js": "cad.js", "/cad-layout.js": "cad-layout.js", "/cad.css": "cad.css"}
            file = static.get(route.path)
            if not file:
                self.send_error(404)
                return
            mime = "text/html" if file.endswith(".html") else ("text/javascript" if file.endswith(".js") else "text/css")
            if not (ASSETS / file).is_file():
                self.send_error(404)
                return
            self._respond((ASSETS / file).read_bytes(), mime + "; charset=utf-8")
        except (KeyError, ValueError) as exc:
            self._respond(json.dumps({"error": str(exc)}).encode(), "application/json", status=400)

    def _respond(self, content: bytes, mime: str, *, status: int = 200) -> None:
        self.send_response(status)
        self.send_header("Content-Type", mime)
        self.send_header("Content-Length", str(len(content)))
        self.send_header("Cache-Control", "no-store")
        self.send_header("X-Content-Type-Options", "nosniff")
        self.send_header("Content-Security-Policy", "default-src 'self'; script-src 'self'; style-src 'self'; connect-src 'self'; img-src 'self' data:; object-src 'none'; base-uri 'none'")
        self.end_headers()
        self.wfile.write(content)

    def log_message(self, fmt: str, *args: object) -> None:
        # Standard HTTP request logging, enabled with FLEXSOC_RTL_HTTP_LOG=1.
        # Keep query strings out of logs: they can contain RTL entity names.
        from urllib.parse import urlsplit
        status = str(args[1]) if len(args) > 1 else "?"
        if os.environ.get("FLEXSOC_RTL_HTTP_LOG") != "1" and not status.startswith(("4", "5")):
            return
        route = urlsplit(self.path).path
        print(f"[rtl-view HTTP] {self.command} {route} {status}", file=sys.stderr, flush=True)
