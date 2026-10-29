"""Paginated hierarchy API, real elaborated AST fixture (not an RTL parser)."""
import json
from threading import Thread
from urllib.error import HTTPError
from urllib.parse import quote
from urllib.request import urlopen
import pytest
from test_rtl_viewer import fixture_ast, ROOT
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign
from flexsoc.backend.dv.rtl_viewer.server import ViewerServer


def test_direct_children_are_paged_and_deterministic():
    design = RtlDesign(fixture_ast(), root=ROOT, top="DSP")
    parent = "/pipeline_abc"
    pages = [design.hierarchy_children(parent, offset=i, limit=3) for i in (0, 3, 6)]
    names = [item["path"] for page in pages for item in page["items"]]
    assert len(names) == 8 and len(set(names)) == 8
    assert names == sorted(names)
    assert [page["has_more"] for page in pages] == [True, True, False]
    assert all(page["total"] == 8 for page in pages)
    assert design.hierarchy_children(parent, offset=10)["items"] == []
    assert design.hierarchy_children(parent, limit=3) == pages[0]
    assert not design._diagrams  # No schematic work for expanding the tree.


def test_bounds_and_unknown_scopes():
    design = RtlDesign(fixture_ast(), root=ROOT, top="DSP")
    for args in ({"limit": 0}, {"limit": 257}, {"offset": -1}):
        with pytest.raises(ValueError):
            design.hierarchy_children("/", **args)
    with pytest.raises(ValueError, match="unrecognized"):
        design.hierarchy_children("/wrong")


def test_http_pages_and_validation():
    server = ViewerServer(("127.0.0.1", 0), RtlDesign(fixture_ast(), root=ROOT, top="DSP"))
    thread = Thread(target=server.serve_forever, daemon=True)
    thread.start()
    try:
        origin = f"http://127.0.0.1:{server.server_port}"
        url = origin + "/api/hierarchy?path=" + quote("/pipeline_abc") + "&limit=2&offset=2"
        with urlopen(url) as response:
            page = json.load(response)
        assert page["offset"] == 2 and len(page["items"]) == 2 and page["total"] == 8
        with pytest.raises(HTTPError) as exc:
            urlopen(origin + "/api/hierarchy?limit=9999")
        assert exc.value.code == 400
    finally:
        server.shutdown()
        server.server_close()
