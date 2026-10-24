"""Routing contract tested without a browser or fabricated RTL elaboration."""
from pathlib import Path
import shutil
import subprocess

import pytest


ROUTER = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web/router.js'


def test_orthogonal_routing_stability_tracks_and_bridges():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable: optional pure JS router contract test')
    script = r'''
const assert=require('node:assert/strict');
const {compute,tracks,bridges}=require(process.argv[1]);
const dims=n=>({w:n.type==='instance'?220:170,h:n.type==='instance'?80:42});
const ranks=n=>n.type==='signal'?2:3;
// Reversed target ordering should be repaired by the bidirectional sweeps.
const nodes=[];const edges=[];
for(let i=0;i<180;i++) nodes.push({id:'s'+i,type:'signal'});
for(let i=179;i>=0;i--) nodes.push({id:'d'+i,type:'instance'});
for(let i=0;i<180;i++) edges.push({id:'e'+i,source:'s'+i,target:'d'+i,net:'n'+i,type:'data'});
const graph={path:'/',nodes,edges};
const a=compute(graph,{boxSize:dims,baseRank:ranks});
const b=compute(graph,{boxSize:dims,baseRank:ranks});
assert.deepEqual([...a.edgePaths],[...b.edgePaths], 'layout deterministic');
assert.equal(a.edgePaths.size,180);
assert.ok(a.stats.channelTracks<8,`overallocated tracks: ${a.stats.channelTracks}`);
assert.equal(a.stats.overheadTracks,0);
for(const e of edges){
 const s=a.positions.get(e.source),t=a.positions.get(e.target);
 assert.ok(s.y<t.y+100 && Math.abs(s.y-t.y)<100,'pair order repaired by sweeps');
 const poly=a.edgePaths.get(e.id);
 for(let i=1;i<poly.length;i++)assert.ok(poly[i-1][0]===poly[i][0]||poly[i-1][1]===poly[i][1],'orthogonal');
}
// Independent vertical intervals share one track; overlapping intervals do not.
assert.equal(tracks([{id:'a',lo:0,hi:12},{id:'b',lo:40,hi:52}]).count,1);
assert.equal(tracks([{id:'a',lo:0,hi:30},{id:'b',lo:10,hi:52}]).count,2);
// Explicit hops at perpendicular intersections of *different* RTL nets.
const paths=new Map([['wire1',[[0,30],[100,30]]],['wire2',[[50,0],[50,60]]]]);
assert.deepEqual(bridges(paths,[{id:'wire1',net:'a'},{id:'wire2',net:'b'}]),[{edge:'wire1',x:50,y:30}]);
assert.equal(bridges(paths,[{id:'wire1',net:'a'},{id:'wire2',net:'a'}]).length,0);
// A forward long edge and a feedback edge must never cross through a node.
const dense={path:'/feedback',nodes:[
 {id:'a',type:'signal'},{id:'b',type:'instance'},
 {id:'c',type:'instance'},{id:'d',type:'signal'}],edges:[
 {id:'e1',source:'a',target:'b',net:'n1'},
 {id:'e2',source:'b',target:'a',net:'n2'},
 {id:'e3',source:'d',target:'c',net:'n3'}]};
const result=compute(dense,{boxSize:dims,baseRank:ranks});
assert.ok(result.stats.overheadTracks+result.stats.corridorWires>0);
for(const [id,poly] of result.edgePaths){
 for(const [node,rect] of result.positions){
  const e=dense.edges.find(e=>e.id===id);
  if(node===e.source||node===e.target)continue;
  for(let i=1;i<poly.length;i++){
   const u=poly[i-1],v=poly[i];
   if(u[0]===v[0])assert.ok(!(u[0]>rect.x&&u[0]<rect.x+rect.w&&Math.min(u[1],v[1])<rect.y+rect.h&&Math.max(u[1],v[1])>rect.y),`${id} crosses ${node}`);
  }
 }
}
console.log('router: PASS 180 wires, bounded tracks, stable routing, feedback');
'''
    run = subprocess.run(['node', '-e', script, str(ROUTER)], capture_output=True, text=True, timeout=15)
    assert run.returncode == 0, run.stderr + run.stdout


def test_router_is_served_and_offline_fixture_embeds_it():
    assets = ROUTER.parent
    html = (assets / 'index.html').read_text()
    server = (assets.parent / 'server.py').read_text()
    mockup = Path(__file__).resolve().parents[2] / 'scripts/build_rtl_viewer_mockup.py'
    assert '<script defer src="/router.js"></script>' in html
    assert '"/router.js": "router.js"' in server
    assert "(assets / 'router.js').read_text()" in mockup.read_text()
