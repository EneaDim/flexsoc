"""Preserve real output boundaries, owned function calls, and Neovim opt-in UX."""
from __future__ import annotations

import json
from pathlib import Path
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.neovim import capability

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
HERE = Path(__file__).resolve().parent


def _out_port_ast():
    def ref(i):
        return {"kind": "NamedValue", "symbol": f"{i} compiled"}
    return {"design": {"members": [{"kind": "Instance", "name": "demo",
        "body": {"kind": "InstanceBody", "name": "demo", "members": [
            {"kind": "Variable", "name": "a", "addr": 1},
            {"kind": "Variable", "name": "b", "addr": 2},
            {"kind": "Port", "name": "hw2reg", "direction": "Out", "addr": 30,
             "internalSymbol": "3 hw2reg"},
            {"kind": "Variable", "name": "hw2reg", "addr": 3},
            {"kind": "ProceduralBlock", "procedureKind": "AlwaysComb", "source_line": 42,
             "body": {"kind": "Block", "body": {"kind": "List", "list": [
                 {"kind": "Assignment", "left": ref(3),
                  "right": {"kind": "BinaryOp", "op": "BitwiseXor",
                            "left": ref(1), "right": ref(2)}}
             ]}}}
        ]}}]}}


def test_compiler_port_is_outside_virtual_process_with_real_driver():
    graph = RtlDesign(_out_port_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    group = next(g for g in graph['processGroups'] if g['kind'] == 'always_comb')
    output = next(n for n in graph['nodes'] if n['name'] == 'hw2reg')
    assert output['type'] == 'port' and output['direction'].lower() == 'out'
    assert output['id'] in group['targetIds']
    assert output['id'] not in group['memberIds'], 'public output must remain in module scope'
    assert output['id'] in group['outputTargets']
    assert group['outputs'] == 1
    assert any(e['target'] == output['id'] and e['source'] in group['memberIds']
               and e['rendered'] for e in graph['edges'])


@pytest.mark.skipif(not shutil.which('node'), reason='node unavailable')
def test_output_port_crosses_virtual_boundary_without_new_edge(tmp_path):
    graph = RtlDesign(_out_port_ast(), root=Path.cwd(), top='demo').diagram(limit=128)
    path = tmp_path / 'graph.json'
    path.write_text(json.dumps(graph))
    script = r'''
const assert=require('node:assert/strict'), fs=require('fs');
const P=require(process.argv[1]),G=require(process.argv[2]),Adapter=require(process.argv[3]);
const ELK=require(process.argv[4]).default;
const original=JSON.parse(fs.readFileSync(process.argv[5]));
(async()=>{
 const compact=P.project(original);
 const block=compact.nodes.find(n=>n.type==='process_group');
 const port=compact.nodes.find(n=>n.name==='hw2reg');
 assert(block&&port,'compact block and real output must coexist');
 const pins=block.ports.filter(p=>p.direction==='output');
 assert.equal(pins.length,1);
 assert.equal(pins[0].name,'O00:hw2reg');
 assert.equal(pins[0].connection,'bound');
 const edges=compact.edges.filter(e=>e.source===block.id&&e.target===port.id&&e.rendered!==false);
 assert(edges.length>0);
 assert(edges.every(e=>e.sourcePin==='O00:hw2reg'));
 assert(edges.every(e=>original.edges.some(old=>old.id===e.id)));
 const layout=await Adapter.compute(new ELK(),compact,G.boxSize);
 for(const e of edges){
   const from=G.absoluteAnchor(block,layout.positions.get(block.id),'source',e);
   const to=G.absoluteAnchor(port,layout.positions.get(port.id),'target',e);
   const route=layout.edgePaths.get(e.id);
   assert(route,'ELK must preserve each original edge');
   assert.deepEqual(route[0],[from.x,from.y]);
   assert.deepEqual(route.at(-1),[to.x,to.y]);
 }
 const focus=P.focus(original,original.processGroups[0].token);
 assert(focus.nodes.some(n=>n.id===port.id));
 console.log('OUTPUT PORT CONTRACT PASS');
})().catch(e=>{console.error(e);process.exitCode=1;});
'''
    cmd = ['node', '-e', script, str(WEB/'virtual-process.js'),
           str(WEB/'symbol-geometry.js'), str(WEB/'elk-adapter.js'),
           str(WEB/'elk.bundled.js'), str(path)]
    p = subprocess.run(cmd, text=True, capture_output=True, timeout=40)
    assert p.returncode == 0, p.stderr+p.stdout
    assert 'OUTPUT PORT CONTRACT PASS' in p.stdout


def test_real_slang_function_operand_belongs_inside_always_ff():
    fixture = HERE/'fixtures/ethernet_function_call_slang_027.json'
    graph = RtlDesign(json.loads(fixture.read_text()), root=Path.cwd(), top='top').diagram(limit=300)
    ff = [g for g in graph['processGroups'] if g['kind'] == 'always_ff']
    calls = {n['id'] for n in graph['nodes'] if n.get('kind') == 'Call'
             and n.get('function',{}).get('name') == 'gray_of_increment'}
    assert calls
    assert ff
    assert calls <= set().union(*(set(g['memberIds']) for g in ff))


def test_disabled_neovim_explains_explicit_opt_in():
    info = capability(False, True)
    assert info['enabled'] is False
    assert 'FLEXSOC_RTL_NEOVIM=1' in info['reason']


def test_neovim_fallback_has_visible_actionable_error_channel():
    page = (WEB/'index.html').read_text()
    script = (WEB/'neovim-editor.js').read_text()
    assert 'id="nvimNotice"' in page and 'role="status"' in page
    assert "notice.hidden = !expose" in script
    assert 'FLEXSOC_RTL_NEOVIM=1' in script
