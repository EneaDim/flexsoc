"""The redesigned workbench CSS must be reachable via the production server.

Keep the visual pass out of the AST, graph and ELK semantics.
"""
from pathlib import Path
import re

from flexsoc.backend.dv.rtl_viewer import server


WEB = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web"


def test_redesign_stylesheet_exists_after_legacy_css():
    html = (WEB / "index.html").read_text()
    legacy = html.index('href="/style.css"')
    redesign = html.index('href="/workbench-017.css?v=017"')
    assert redesign > legacy
    css = (WEB / "workbench-017.css").read_text()
    for selector in (".header", ".sidebar", ".toolbar", ".inspector", ".schematic", "#sourceCode"):
        assert selector in css
    assert ":root[data-theme='light']" in css
    assert "Slang" in css and "ELK" in css


def test_redesign_route_is_explicitly_allowlisted():
    source = Path(server.__file__).read_text()
    assert '"/workbench-017.css": "workbench-017.css"' in source
    assert not re.search(r"\.\./", (WEB / "index.html").read_text())
