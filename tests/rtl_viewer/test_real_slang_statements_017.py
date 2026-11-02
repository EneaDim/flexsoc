"""Characterization regressions extracted from Slang-elaborated DSP AST on WSL.

Unlike synthetic normalized ASTs, this fixture preserves Slang's actual
Block(body=List(list=[...])) and ExpressionStatement(expr=Assignment) shapes.
These shape-contract tests do not claim that a compiler was run during pytest.
"""
import copy
import json
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer.model import RtlDesign


FIXTURE = Path(__file__).parent / 'fixtures' / 'dsp_slang_statements_017.json'
ROOT = Path(__file__).parents[2] / 'examples' / 'rtl_schematic_dsp'


def design(top: str, ast=None):
    return RtlDesign(ast or json.loads(FIXTURE.read_text()), root=ROOT, top=top)


def input_edges(graph, destination):
    return [e for e in graph['edges'] if e['target'] == '/::sig:' + destination
            and e.get('targetPin') == 'D' and e.get('rendered')]


@pytest.mark.parametrize('top,register,source,selector', [
    ('u_core', 'valid_q', 'en_i', 'en_i'),
    ('u_lane', 'product_q', 'product_d', 'en_i'),
    ('u_lane', 'accum_q', 'accum_d', 'en_i'),
])
def test_real_slang_reset_enable_lowered_to_one_mux(top, register, source, selector):
    graph = design(top).diagram()
    node = next(n for n in graph['nodes'] if n['name'] == register)
    assert not node.get('dInputStatus')
    [wire] = input_edges(graph, register)
    assert wire['mapping'] == 'procedural_mux'
    mux = next(n for n in graph['nodes'] if n['id'] == wire['source'])
    assert mux.get('origin') == 'procedural_if_ast'
    def incoming(pin):
        return {e['source'] for e in graph['edges'] if e['target'] == mux['id']
                and e.get('pin') == pin and e.get('rendered')}
    assert incoming('S') == {'/::sig:' + selector}
    assert incoming('A') == {'/::sig:' + register}  # Q hold
    if top == 'u_lane':
        assert incoming('B') == {'/::sig:' + source}
    else:
        # valid_q clock-side update is a literal, not an invented signal.
        assert mux.get('literalOperands', {}).get('B')
    controls = {e.get('pin') for e in graph['edges'] if e['target'] == node['id']
                and e.get('type') == 'event' and e.get('rendered')}
    assert controls == {'CLK', 'RST'}
    assert len(input_edges(graph, register)) == 1


def test_real_slang_multi_register_list_is_atomic():
    graph = design('u_lane').diagram()
    muxes = [n for n in graph['nodes'] if n.get('origin') == 'procedural_if_ast']
    assert len(muxes) == 2
    assert len(input_edges(graph, 'product_q')) == 1
    assert len(input_edges(graph, 'accum_q')) == 1
    assert not any(e.get('routingStatus') == 'unresolved_D_mux' and e.get('rendered')
                   for e in graph['edges'])


def test_unknown_statement_inside_real_slang_list_fails_closed():
    ast = json.loads(FIXTURE.read_text())
    lane = next(n for n in ast['design']['members'] if n['name'] == 'u_lane')
    proc = next(n for n in lane['body']['members'] if n.get('kind') == 'ProceduralBlock')
    outer = proc['body']['stmt']['body']
    branch = outer['ifFalse']['ifTrue']['body']
    assert branch['kind'] == 'List'
    branch['list'].append({'kind': 'UnsupportedStatement'})
    graph = design('u_lane', ast).diagram()
    for register in ('product_q', 'accum_q'):
        assert not input_edges(graph, register)
        assert next(n for n in graph['nodes'] if n['name'] == register).get('dInputStatus')


def test_nonblocking_unknown_in_real_slang_list_fails_closed():
    ast = json.loads(FIXTURE.read_text())
    lane = next(n for n in ast['design']['members'] if n['name'] == 'u_lane')
    proc = next(n for n in lane['body']['members'] if n.get('kind') == 'ProceduralBlock')
    branch = proc['body']['stmt']['body']['ifFalse']['ifTrue']['body']
    branch['list'][0]['expr']['isNonBlocking'] = False
    graph = design('u_lane', ast).diagram()
    for register in ('product_q', 'accum_q'):
        assert not input_edges(graph, register)


def test_browser_hierarchy_does_not_fetch_virtual_generate_segments():
    from test_workbench_panels_007 import browser_page
    instance, browser, page = browser_page()
    try:
        # The compiler returns '/pipeline_abc/g_mac/g_mac[0]/PE_random_8'
        # as one child of '/pipeline_abc'. Intermediate g_mac folders
        # are *not* elaborated scopes and must not be queried via HTTP.
        leaf = '/pipeline_abc/g_mac/g_mac[0]/PE_random_8'
        page.evaluate('''async leaf=>{
            window.__hierarchyQueries=[];
            const original=window.FlexAPI;
            window.FlexAPI=async(name,params={})=>{
                if(name==='hierarchy') window.__hierarchyQueries.push(params.path);
                return original(name,params);
            };
            await navigate(leaf);
        }''', leaf)
        page.wait_for_function("document.getElementById('viewName').textContent === 'DSP_lane'")
        page.wait_for_function("window.__hierarchyQueries.includes('/pipeline_abc')")
        page.wait_for_timeout(150)
        paths = page.evaluate('window.__hierarchyQueries')
        assert set(paths) <= {'/', '/pipeline_abc', leaf}
        assert '/pipeline_abc' in paths
        assert page.locator('#hierarchy .fs-tree-label[data-path="'+leaf+'"]').count() == 1
    finally:
        browser.close()
        instance.stop()


def test_real_slang_multi_register_mux_geometry_using_elk():
    import shutil
    import subprocess
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    graph = design('u_lane').diagram()
    web = Path(__file__).parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
    script = r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const graph=JSON.parse(fs.readFileSync(0,'utf8')), web=process.argv[1];
const A=require(web+'/elk-adapter.js'),G=require(web+'/symbol-geometry.js');
const ELK=require(web+'/elk.bundled.js').default;
(async()=>{
 const out=await A.compute(new ELK(),graph,G.boxSize);
 const wires=graph.edges.filter(e=>e.rendered!==false);
 assert.equal(out.edgePaths.size,wires.length);
 for(const e of wires){
  const start=graph.nodes.find(n=>n.id===e.source),end=graph.nodes.find(n=>n.id===e.target);
  const points=out.edgePaths.get(e.id);
  assert(points&&points.length>=2,e.id);
  const a=G.absoluteAnchor(start,out.positions.get(start.id),'source',e);
  const b=G.absoluteAnchor(end,out.positions.get(end.id),'target',e);
  assert.deepEqual(points[0],[a.x,a.y]);
  assert.deepEqual(points.at(-1),[b.x,b.y]);
 }
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(web)], input=json.dumps(graph),
                            text=True, capture_output=True, timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr
