"""Localhost-only graph queries and static workbench. No application server deps."""
from __future__ import annotations

from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
import hashlib
import os
import sys
import threading
from pathlib import Path
from urllib.parse import parse_qs, urlsplit

from .model import RtlDesign
from .neovim import NeovimSession, NeovimUnavailable, bounded_size, capability


ASSETS = Path(__file__).with_name("web")


class ViewerServer(ThreadingHTTPServer):
    allow_reuse_address = True
    daemon_threads = True

    def __init__(self, address: tuple[str, int], design: RtlDesign, *, enable_neovim: bool = False):
        self.design = design
        self.enable_neovim = enable_neovim
        self.neovim_lock = threading.RLock()
        self.neovim_session: NeovimSession | None = None
        super().__init__(address, ViewerHandler)

    def server_close(self) -> None:
        with self.neovim_lock:
            if self.neovim_session:
                self.neovim_session.close()
                self.neovim_session = None
        super().server_close()


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
                if resource == 'neovim/capability':
                    payload = capability(self.server.enable_neovim,
                                         self.server.server_address[0] == '127.0.0.1')
                elif resource == 'neovim/state':
                    with self.server.neovim_lock:
                        session = self.server.neovim_session
                        if not session or arg('token') != session.token:
                            self._respond(b'{"error":"Neovim session not found"}', 'application/json', status=404)
                            return
                        payload = session.snapshot(int(arg('since', '0')))
                        if payload.get('changed'):
                            try:
                                payload['source_line'] = session.request('nvim_win_get_cursor', [0], timeout=0.5)[0]
                            except NeovimUnavailable:
                                pass
                elif resource == "runtime":
                    assets = {}
                    for filename in ("app.js", "layout-engine.js", "router.js", "symbol-geometry.js", "symbol-painter.js", "elk-adapter.js"):
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
                elif resource == "source_coverage":
                    payload = design.source_coverage(path)
                elif resource == "source_symbols":
                    payload = design.source_symbols(path, int(arg("line", "0")))
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
            static = {"/": "index.html", "/index.html": "index.html", "/app.js": "app.js", "/neovim-editor.js": "neovim-editor.js", "/bootstrap-guard.js": "bootstrap-guard.js", "/lazy-hierarchy.js": "lazy-hierarchy.js", "/hierarchy-tree.js": "hierarchy-tree.js", "/router.js": "router.js", "/layout-engine.js": "layout-engine.js", "/elk-adapter.js": "elk-adapter.js", "/symbol-geometry.js": "symbol-geometry.js", "/symbol-painter.js": "symbol-painter.js", "/elk.bundled.js": "elk.bundled.js", "/style.css": "style.css", "/cad": "cad.html", "/cad.html": "cad.html", "/cad.js": "cad.js", "/cad-layout.js": "cad-layout.js", "/cad.css": "cad.css"}
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

    def do_POST(self) -> None:
        """Local opt-in editor actions. All writes stay in a scratch Neovim buffer."""
        route = urlsplit(self.path).path
        if not route.startswith('/api/neovim/'):
            self.send_error(404)
            return
        host = self.headers.get('Host', '')
        expected = {f'127.0.0.1:{self.server.server_port}',
                    f'localhost:{self.server.server_port}'}
        origin = self.headers.get('Origin', '')
        if (not self.server.enable_neovim or
                self.server.server_address[0] != '127.0.0.1' or
                host not in expected or
                (origin and origin not in {f'http://{h}' for h in expected})):
            self._respond(b'{"error":"Neovim endpoint is localhost-only"}', 'application/json', status=403)
            return
        try:
            length = int(self.headers.get('Content-Length', '0'))
            if not 0 < length <= 4096:
                raise ValueError('Neovim request size outside bounds')
            body = json.loads(self.rfile.read(length))
            if not isinstance(body, dict):
                raise ValueError('Invalid request body')
            action = route.removeprefix('/api/neovim/')
            with self.server.neovim_lock:
                if action == 'start':
                    path = str(body.get('path', ''))
                    if len(path) > 1024:
                        raise ValueError('Invalid hierarchy path')
                    cols, rows = bounded_size(body.get('cols', 80), body.get('rows', 24))
                    result = self.server.design.source(path)
                    if result.get('status') != 'available':
                        raise ValueError('No compiler-mapped source for this scope')
                    # Create before replacing the existing session, preserving it if startup fails.
                    new_session = NeovimSession(self.server.design.root, result, width=cols, height=rows)
                    previous = self.server.neovim_session
                    self.server.neovim_session = new_session
                    if previous:
                        previous.close()
                    payload = {'status': 'available', 'token': new_session.token,
                               'file': result['file'], 'readonly': True}
                else:
                    session = self.server.neovim_session
                    if not session or body.get('token') != session.token:
                        self._respond(b'{"error":"Neovim session not found"}', 'application/json', status=404)
                        return
                    if action == 'input':
                        keys = body.get('keys')
                        if not isinstance(keys, str) or not 0 < len(keys.encode('utf-8')) <= 1024:
                            raise ValueError('Invalid Neovim input length')
                        session.notify('nvim_input', [keys])
                        payload = {'status': 'ok'}
                    elif action == 'scroll':
                        direction = body.get('direction')
                        count = body.get('count')
                        if direction not in {'up', 'down'} or type(count) is not int or not 1 <= count <= 60:
                            raise ValueError('Invalid Neovim scroll request')
                        # Native mouse wheel events drive the Neovim viewport.
                        # Mouse position is relative to the currently attached UI grid.
                        grid = getattr(session, 'grid', None)
                        row = max(0, int(getattr(grid, 'height', 1)) // 2)
                        col = max(0, int(getattr(grid, 'width', 1)) // 2)
                        for _ in range(count):
                            session.notify('nvim_input_mouse', ['wheel', direction, '', 0, row, col])
                        payload = {'status': 'ok'}
                    elif action == 'resize':
                        cols, rows = bounded_size(body.get('cols'), body.get('rows'))
                        session.notify('nvim_ui_try_resize', [cols, rows])
                        payload = {'status': 'ok'}
                    elif action == 'cursor':
                        line = int(body.get('line', 0))
                        if not 1 <= line <= 1_000_000:
                            raise ValueError('Invalid source line')
                        session.request('nvim_win_set_cursor', [0, [line, 0]])
                        payload = {'status': 'ok'}
                    elif action == 'stop':
                        session.close()
                        self.server.neovim_session = None
                        payload = {'status': 'stopped'}
                    else:
                        self.send_error(404)
                        return
            self._respond(json.dumps(payload).encode(), 'application/json; charset=utf-8')
        except (ValueError, NeovimUnavailable, OSError, json.JSONDecodeError) as exc:
            self._respond(json.dumps({'error': str(exc)}).encode(), 'application/json', status=400)

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
