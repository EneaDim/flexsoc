"""Slang-produced mixed next-state functions: unsupported siblings do not hide proven D."""
import json
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign

FIXTURE = Path(__file__).parent / 'fixtures/ethernet_mixed_ff_slang_025.json'


def test_real_slang_counter_inputs_are_proven_with_unrelated_gray_calls():
    ast = json.loads(FIXTURE.read_text())
    model = RtlDesign(ast, root=FIXTURE.parent, top='top')
    graph = model.diagram()
    nodes = {n['name']: n for n in graph['nodes']}
    for signal, guard in [('rx_bad_event_bin', 'rx_bad_frame'),
                          ('rx_fcs_event_bin', 'rx_bad_fcs')]:
        register = nodes[signal]
        assert register['type'] in {'register', 'counter'}
        assert not register.get('dInputStatus')
        dest = register['id']
        drivers = [e for e in graph['edges'] if e['target'] == dest
                   and e['targetPin'] == 'D' and e['rendered']]
        assert len(drivers) == 1
        mux = next(n for n in graph['nodes'] if n['id'] == drivers[0]['source'])
        assert mux['origin'] == 'procedural_if_ast'
        sources = {(e['pin'], e['source']) for e in graph['edges']
                   if e['target'] == mux['id'] and e['rendered']}
        assert ('S', nodes[guard]['id']) in sources
        assert ('A', register['id']) in sources  # Q hold
        add_id = next(source for pin,source in sources if pin == 'B')
        add = next(n for n in graph['nodes'] if n['id'] == add_id)
        assert add['name'] == 'Add' and add['literalOperands']['B'] == "32'd1"
        assert any(e['source'] == dest and e['target'] == add_id and e['rendered']
                   for e in graph['edges'])
    for signal in ['rx_bad_event_gray', 'rx_fcs_event_gray']:
        assert nodes[signal].get('dInputStatus')
        assert not [e for e in graph['edges'] if e['target'] == nodes[signal]['id']
                    and e['targetPin']=='D' and e['rendered']]


def test_elk_real_stops_at_register_d_and_routes_literal_on_operator():
    import shutil, subprocess
    import pytest
    if shutil.which('node') is None:
        pytest.skip('Node.js needed for real ELK')
    ast=json.loads(FIXTURE.read_text())
    graph=RtlDesign(ast,root=FIXTURE.parent,top='top').diagram()
    web=Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
    js=r'''
const fs=require('node:fs'),assert=require('node:assert/strict');
const web=process.argv[1],g=JSON.parse(fs.readFileSync(0,'utf8'));
const ELK=require(web+'/elk.bundled.js').default;
const adapter=require(web+'/elk-adapter.js'),geometry=require(web+'/symbol-geometry.js');
(async()=>{
 const l=await adapter.compute(new ELK(),g,geometry.boxSize);
 for(const edge of g.edges.filter(e=>e.rendered&&e.targetPin==='D')){
  if(!edge.target.includes('event_bin'))continue;
  const path=l.edgePaths.get(edge.id);
  assert(path && path.length>=2,edge.id);
  const target=g.nodes.find(n=>n.id===edge.target);
  const pos=l.positions.get(target.id);
  const pin=geometry.absoluteAnchor(target,pos,'target',edge);
  assert.deepEqual(path.at(-1),[pin.x,pin.y]);
 }
 console.log('ELK connected Q+1 / MUX / D');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    process=subprocess.run(['node','-e',js,str(web)],input=json.dumps(graph),
                           capture_output=True,text=True,timeout=45)
    assert process.returncode==0, process.stdout+process.stderr
