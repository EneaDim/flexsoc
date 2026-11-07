"""Patch 003: compiler-backed inspector and frontend/server API contract."""
import json
import re
from pathlib import Path
from threading import Thread
from urllib.parse import urlencode
from urllib.request import urlopen

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.server import ViewerServer

ROOT = Path(__file__).resolve().parents[2]
WEB = ROOT / 'src/flexsoc/backend/dv/rtl_viewer/web/app.js'
EXT = ROOT / 'extensions/flexsoc-rtl-explorer/src/extension.js'
SERVER = ROOT / 'src/flexsoc/backend/dv/rtl_viewer/server.py'


def design(tmp_path):
    (tmp_path / 'top.sv').write_text('logic a;\nlogic b;\n')
    members = [
        {'kind': 'Variable', 'name': name, 'type': 'logic',
         'sourceRange': {'start': {'file': 'top.sv', 'line': i}}}
        for i, name in enumerate(('a', 'b'), 1)]
    return RtlDesign({'design': {'members': [{'kind': 'Instance', 'name': 'top',
        'body': {'kind': 'InstanceBody', 'name': 'top', 'members': members}}]}},
        root=tmp_path, top='top')


def test_inspect_visible_identity_and_safe_miss(tmp_path):
    model = design(tmp_path)
    node = next(n for n in model.diagram()['nodes'] if n['name'] == 'a')
    result = model.inspect('/', node['id'])
    assert result['id'] == node['id']
    assert result['entity']['name'] == 'a'
    assert result['source'] == {'status': 'available', 'file': 'top.sv',
                                'line': 1, 'provenance': 'Slang AST'}
    assert result['elaboration_verified'] is False
    assert model.inspect('/', '/::sig:does_not_exist')['status'] == 'unresolved'
    with pytest.raises(ValueError):
        model.inspect('/', 'x' * 1025)


def test_real_http_inspect(tmp_path):
    server = ViewerServer(('127.0.0.1', 0), design(tmp_path))
    thread = Thread(target=server.serve_forever, daemon=True)
    thread.start()
    try:
        node_id = server.design.diagram()['nodes'][0]['id']
        query = urlencode({'path': '/', 'id': node_id})
        with urlopen(f'http://127.0.0.1:{server.server_port}/api/inspect?{query}') as response:
            payload = json.load(response)
        assert payload['status'] == 'available'
        assert payload['id'] == node_id
    finally:
        server.shutdown()
        server.server_close()
        thread.join(timeout=3)


def test_frontend_routes_exist_in_server_and_extension():
    frontend = set(re.findall(r"api\(['\"]([^'\"]+)", WEB.read_text()))
    handlers = set(re.findall(r"resource == [\"']([^\"']+)", SERVER.read_text()))
    extension = EXT.read_text().split('const API = new Set([', 1)[1].split(']);', 1)[0]
    allowed = set(re.findall(r"['\"]([^'\"]+)['\"]", extension))
    assert frontend <= handlers, f'Backend missing: {frontend - handlers}'
    assert frontend <= allowed, f'Extension missing: {frontend - allowed}'
