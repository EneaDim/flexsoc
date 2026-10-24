"""Contextual per-group expansion and generic workbench toolbar."""
from pathlib import Path
import json

from flexsoc.backend.dv.rtl_viewer import RtlDesign

ROOT = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp_complex'


def design():
    return RtlDesign(json.loads((ROOT / 'DSP_stream.mock_ast.json').read_text()), root=ROOT, top='DSP_stream')


def test_expansion_is_scoped_to_one_elaborated_group_and_has_stable_ids():
    rtl = design()
    default = rtl.diagram('/u_filter')
    group = next(n for n in default['nodes'] if n['type'] == 'generate')
    assert group['group']
    assert group['count'] == 6
    expanded = rtl.diagram('/u_filter', expanded=(group['group'],))
    assert not any(n['type'] == 'generate' for n in expanded['nodes'])
    assert sum(n['type'] == 'instance' for n in expanded['nodes']) == 6
    assert all(n['group'] == group['group'] for n in expanded['nodes'] if n['type'] == 'instance')
    assert default == rtl.diagram('/u_filter')  # cached collapsed view is untouched
    assert expanded == rtl.diagram('/u_filter', expanded=(group['group'],))
    assert rtl.diagram('/u_filter', expanded=('nonexistent-group',))['nodes'] == default['nodes']


def test_ui_has_only_global_top_controls_and_contextual_generate():
    assets = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
    html = (assets / 'index.html').read_text()
    js = (assets / 'app.js').read_text()
    assert 'id="explode"' not in html
    assert 'id="toggleSource"' in html and 'id="toggleLint"' in html
    assert 'id="toggleCone"' in html and 'id="search"' in html
    assert 'id="contextGenerate"' in html
    assert 'toggleGroup(state.context)' in js
    assert 'layout(graph)' in js  # no new client-side RTL parsing


def test_local_api_scoped_expansion():
    from threading import Thread
    from urllib.parse import quote
    from urllib.request import urlopen
    from flexsoc.backend.dv.rtl_viewer.server import ViewerServer

    server = ViewerServer(('127.0.0.1', 0), design())
    thread = Thread(target=server.serve_forever, daemon=True)
    thread.start()
    try:
        base = f'http://127.0.0.1:{server.server_port}/api/diagram?path=%2Fu_filter'
        with urlopen(base) as response:
            folded = json.load(response)
        group = next(n['group'] for n in folded['nodes'] if n['type'] == 'generate')
        with urlopen(base + '&expand=' + quote(group, safe='')) as response:
            expanded = json.load(response)
        assert len([n for n in expanded['nodes'] if n['type'] == 'instance']) == 6
        with urlopen(base) as response:
            assert json.load(response) == folded
    finally:
        server.shutdown()
        server.server_close()
        thread.join(timeout=3)
