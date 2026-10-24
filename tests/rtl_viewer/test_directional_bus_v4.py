"""AST-proof bindings and UI contracts for dense packed/unpacked RTL designs."""
from pathlib import Path
import json

from flexsoc.backend.dv.rtl_viewer import RtlDesign


ROOT = Path(__file__).resolve().parents[2] / 'examples/rtl_schematic_dsp_complex'


def sig(name, direction='', kind='Variable', **extra):
    return {'kind': kind, 'name': name, 'direction': direction, 'type': 'logic [31:0]', **extra}


def ref(name):
    return {'kind': 'NamedValue', 'symbol': '77 ' + name}


def design(binding):
    child = {'kind': 'Instance', 'name': 'random_name',
             'body': {'kind': 'InstanceBody', 'name': 'Child', 'members': [sig('payload', 'In', 'Port')]}}
    if binding is not None:
        if isinstance(binding, tuple):
            # Slang-style port-owned elaborated connection, not a name guess.
            child['body']['members'][0]['connection'] = binding[0]
        else:
            child['connections'] = [{'port': 'payload', 'expression': binding}]
    top = {'kind': 'Instance', 'name': 'Chip', 'body': {'name': 'Chip', 'members': [
        sig('payload', 'In', 'Port', packedDimensions=['[31:0]'], unpackedDimensions=['[0:3]']),
        sig('index'), child]}}
    return RtlDesign({'design': {'kind': 'Root', 'members': [top]}}, root=ROOT, top='Chip')


def test_identical_port_names_do_not_invent_connectivity():
    graph = design(None).diagram()
    assert any(n['name'] == 'payload' for n in graph['nodes'])
    assert not any(e['port'] == 'payload' for e in graph['edges'])


def test_child_port_owned_binding_and_whole_bus_preserves_dimensions():
    viewer = design((ref('payload'),))
    graph = viewer.diagram()
    assert [e['mapping'] for e in graph['edges'] if e['port'] == 'payload'] == ['direct']
    assert viewer.follow('/', '/random_name', '/::sig:payload')['status'] == 'resolved'
    net = next(n for n in graph['nodes'] if n['name'] == 'payload')
    assert net['dimensions'] == {'packedDimensions': ['[31:0]'], 'unpackedDimensions': ['[0:3]']}


def test_partial_packed_array_binding_is_visible_but_not_implicitly_bit_exact():
    index = {'kind': 'ElementSelect', 'value': ref('payload'), 'selector': ref('index')}
    viewer = design(index)
    edge = next(e for e in viewer.diagram()['edges'] if e['port'] == 'payload')
    assert edge['mapping'] == 'partial' and edge['net'] == '/::sig:payload'
    assert viewer.follow('/', '/random_name', '/::sig:payload')['status'] == 'unresolved'


def test_parallel_bindings_are_aggregated_without_guessing_lane_indices():
    ast = json.loads((ROOT / 'DSP_stream.mock_ast.json').read_text())
    viewer = RtlDesign(ast, root=ROOT, top='DSP_stream')
    graph = viewer.diagram('/u_filter')
    stack = next(n for n in graph['nodes'] if n['type'] == 'generate')
    assert stack['count'] == 6
    assert any(e['count'] == 6 for e in graph['edges'])
    assert graph['ancestors'] == [
        {'path': '/', 'name': 'DSP_stream', 'module': 'DSP_stream'},
        {'path': '/u_filter', 'name': 'u_filter', 'module': 'DSP_fir'}]
    generated = viewer.diagram('/u_filter/g_taps/g_taps[0]/u_mult')
    assert [x['path'] for x in generated['ancestors']] == ['/', '/u_filter', '/u_filter/g_taps/g_taps[0]/u_mult']


def test_ui_has_theme_and_clickable_breadcrumbs_without_global_generate():
    assets = ROOT.parents[1] / 'src/flexsoc/backend/dv/rtl_viewer/web'
    html = (assets / 'index.html').read_text()
    js = (assets / 'app.js').read_text()
    css = (assets / 'style.css').read_text()
    assert 'id="themeToggle"' in html
    assert 'id="breadcrumb"' in html
    assert 'id="explode"' not in html
    assert "state.graph.ancestors" in js
    assert ':root[data-theme=light]' in css
    assert "const palettes=" in js
