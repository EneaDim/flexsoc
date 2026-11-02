"""Real ELK regression: the physical wire endpoints match Canvas glyph pins.

These tests execute the bundled ELK runtime, not a synthetic placement stub.
They deliberately do not validate compiler connectivity: that has independent tests.
"""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_elk_endpoints_match_symbol_terminals_and_layout_is_stable():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    script = r'''
const assert = require('node:assert/strict');
const WEB = process.argv[1];
const ELK = require(WEB + '/elk.bundled.js').default;
const G = require(WEB + '/symbol-geometry.js');
const A = require(WEB + '/elk-adapter.js');
const L = require(WEB + '/layout-engine.js');
const nodes = [
 {id:'input',type:'port',direction:'input'},
 {id:'select',type:'port',direction:'in'},
 {id:'mux',type:'operator',shape:'mux'},
 {id:'reg',type:'register'},
 {id:'clk',type:'port',direction:'in'},
 {id:'reset',type:'port',direction:'in'},
 {id:'mod',type:'instance',ports:[
   {name:'data_i',direction:'input'},{name:'clk_i',direction:'in'},
   {name:'data_o',direction:'output'},{name:'ready_o',direction:'out'}]},
 {id:'out',type:'port',direction:'out'}
];
const edges = [
 {id:'a',source:'input',target:'mux',targetPin:'A',net:'data'},
 {id:'b',source:'input',target:'mux',targetPin:'B',net:'data'},
 {id:'s',source:'select',target:'mux',targetPin:'S',net:'sel'},
 {id:'d',source:'mux',target:'reg',net:'mux_out'},
 {id:'clock',source:'clk',target:'reg',type:'event',pin:'CLK',net:'clock'},
 {id:'reset_event',source:'reset',target:'reg',type:'event',pin:'RST',net:'reset'},
 {id:'into_mod',source:'reg',target:'mod',port:'data_i',net:'registered'},
 {id:'mod_clk',source:'clk',target:'mod',port:'clk_i',net:'clock'},
 {id:'out_mod',source:'mod',sourcePin:'data_o',target:'out',net:'out_net'},
];
const graph = {nodes,edges};
const before = JSON.stringify(graph);
const converted = A.convert(graph,G.boxSize);
assert.equal(converted.edges.length,edges.length);
for (const n of converted.children) {
 assert.deepEqual({w:n.width,h:n.height},G.boxSize(nodes.find(node=>node.id===n.id)));
 for(const port of n.ports) assert.equal(port.width,0,'ELK physical terminals have no artificial 2px offset');
}
for(const n of nodes.filter(n=>n.type==='instance')) {
 const inputs=G.portRows(n,'target'),outputs=G.portRows(n,'source');
 assert.equal(inputs.length,2);assert.equal(outputs.length,2);
 assert.deepEqual(inputs.map(p=>p.y),[53,72]);
 assert.deepEqual(outputs.map(p=>p.y),[65,84]);
 for(const p of [...inputs,...outputs])assert(p.y<G.boxSize(n).h);
}
for(const n of nodes.filter(n=>n.type==='register')) {
 const clk=G.anchor(n,'target',{type:'event',pin:'CLK'});
 const rst=G.anchor(n,'target',{type:'event',pin:'RST'});
 assert.equal(clk.side,'SOUTH');assert.equal(rst.side,'SOUTH');
 assert.notEqual(clk.x,rst.x);
}
(async()=>{
 const elk = new ELK();
 const first=await A.compute(elk,graph,G.boxSize);
 const second=await A.compute(elk,graph,G.boxSize);
 assert.deepEqual([...first.positions],[...second.positions],'ELK node placement must be deterministic');
 assert.deepEqual([...first.edgePaths],[...second.edgePaths],'ELK routing must be deterministic');
 assert.deepEqual(L.validate(graph,first),{ok:true,errors:[]});
 const byId=new Map(nodes.map(n=>[n.id,n]));
 for (const e of edges) {
   const route=first.edgePaths.get(e.id);
   assert(route && route.length>=2,e.id);
   for(let i=1;i<route.length;i++)
    assert(route[i-1][0]===route[i][0]||route[i-1][1]===route[i][1],e.id+': nonorthogonal');
   const start=G.absoluteAnchor(byId.get(e.source),first.positions.get(e.source),'source',e);
   const end=G.absoluteAnchor(byId.get(e.target),first.positions.get(e.target),'target',e);
   assert(Math.abs(route[0][0]-start.x)<.001 && Math.abs(route[0][1]-start.y)<.001,
     e.id+': source wire misses glyph '+JSON.stringify({route:route[0],start}));
   assert(Math.abs(route.at(-1)[0]-end.x)<.001 && Math.abs(route.at(-1)[1]-end.y)<.001,
     e.id+': target wire misses glyph '+JSON.stringify({route:route.at(-1),end}));
 }
 const rects=[...first.positions];
 for(let i=0;i<rects.length;i++)for(let j=i+1;j<rects.length;j++){
  const a=rects[i][1],b=rects[j][1];
  assert(a.x+a.w<=b.x||b.x+b.w<=a.x||a.y+a.h<=b.y||b.y+b.h<=a.y,
    rects[i][0]+' overlaps '+rects[j][0]);
 }
 assert.equal(JSON.stringify(graph),before,'ELK adapter cannot mutate semantic graph');
 console.log('REAL ELK terminal geometry PASS');
})().catch(err=>{console.error(err);process.exitCode=1;});
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], text=True,
                            capture_output=True, timeout=40)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'REAL ELK terminal geometry PASS' in result.stdout


def test_canonical_glyph_contract_is_loaded_before_elk_and_rendering():
    html = (WEB / 'index.html').read_text()
    server = (WEB.parent / 'server.py').read_text()
    assert html.index('/symbol-geometry.js') < html.index('/elk-adapter.js') < html.index('/app.js')
    assert '"/symbol-geometry.js": "symbol-geometry.js"' in server
    app = (WEB / 'app.js').read_text()
    assert 'FlexSymbolGeometry.boxSize' in app
    assert 'FlexRouting.pinGeometry' not in app
    assert 'FlexSymbolPainter.paint' in app
    painter = (WEB / 'symbol-painter.js').read_text()
    assert 'FlexSymbolGeometry.portRows' in painter
    assert html.index('/symbol-geometry.js') < html.index('/symbol-painter.js') < html.index('/app.js')
    assert '"/symbol-painter.js": "symbol-painter.js"' in server


def test_real_browser_loads_canonical_geometry_with_bundled_elk():
    """Actual production HTML/JS in Chromium; mock only the AST HTTP responses."""
    import json
    import re
    import sys
    from test_rtl_viewer import fixture_ast, ROOT
    from flexsoc.backend.dv.rtl_viewer import RtlDesign

    chromium = shutil.which('chromium') or shutil.which('google-chrome')
    if not chromium:
        pytest.skip('Chromium unavailable')
    playwright = pytest.importorskip('playwright.sync_api')
    design = RtlDesign(fixture_ast(), root=ROOT, top='DSP')
    payloads = {
        'overview': design.overview(), 'hierarchy': design.hierarchy_children('/'),
        'diagram': design.diagram('/'), 'source': design.source('/'),
        'lint': design.lint('/'),
    }
    html = (WEB / 'index.html').read_text()
    scripts = re.findall(r'<script defer src="/([^"]+)"></script>', html)
    html = re.sub(r'<script defer src="/[^"]+"></script>', '', html)
    assert 'symbol-geometry.js' in scripts
    with playwright.sync_playwright() as driver:
        browser = driver.chromium.launch(headless=True, executable_path=chromium,
                                         args=['--no-sandbox'])
        try:
            page = browser.new_page(viewport={'width': 1500, 'height': 900})
            errors = []
            page.on('pageerror', lambda error: errors.append(str(error)))
            page.set_content(html, wait_until='domcontentloaded')
            page.add_style_tag(path=str(WEB / 'style.css'))
            page.evaluate('''responses => {
                window.fetch = async path => {
                    const key = String(path).split('/api/')[1]?.split('?')[0];
                    if (!Object.hasOwn(responses,key)) throw Error('Unexpected mocked API: '+path);
                    return {ok:true,status:200,json:async()=>responses[key]};
                };
            }''', payloads)
            for script in scripts:
                page.add_script_tag(path=str(WEB / script))
            page.wait_for_function('state.layouts.size === 1', timeout=15000)
            assert page.locator('#layoutEngineStatus').inner_text().startswith('LAYOUT: ELK')
            assert len(payloads['diagram']['nodes']) == page.evaluate('state.graph.nodes.length')
            assert page.evaluate('state.layouts.values().next().value.edgePaths.size') == len(payloads['diagram']['edges'])
            assert not errors, errors
        finally:
            browser.close()
