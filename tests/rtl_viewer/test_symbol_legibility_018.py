"""Ethernet-scale glyph labels cannot collide with functional glyphs."""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web"


def test_ethernet_operator_glyphs_and_elk_anchor_contract():
    if not shutil.which("node"):
        pytest.skip("Node unavailable")
    script = r'''
const assert=require('node:assert/strict'),W=process.argv[1];
const G=require(W+'/symbol-geometry.js'),P=require(W+'/symbol-painter.js');
const A=require(W+'/elk-adapter.js'),ELK=require(W+'/elk.bundled.js').default;
const palette={signal:'#abc',port:'#abc',register:'#abc',counter:'#abc',fsm:'#abc',
 operator:'#fa5',instance:'#abc',generate:'#abc',selected:'#fa6',symbolFill:'#223344',
 pickedFill:'#345',stackFill:'#123',stackStroke:'#345',text:'#fff',muted:'#aac',binding:'#aaf'};
function traceNode(n){
 const cmds=[],ctx={save(){cmds.push(['save'])},restore(){cmds.push(['restore'])}};
 for(const method of ['beginPath','moveTo','lineTo','fill','stroke','arc','closePath','roundRect',
  'fillText','rect','clip','quadraticCurveTo'])ctx[method]=(...args)=>cmds.push([method,...args]);
 P.paint(ctx,n,{x:0,y:0,...G.boxSize(n)},{colors:palette,zoom:1,names:true,edges:[]});
 return cmds;
}
for(const [name,mark,family] of [['BinaryAnd','&','and'],['BinaryOr','|','or'],
 ['BinaryXor','^','xor'],['UnaryBitwiseNot','~','not']]){
 const n={id:name,name,type:'operator',kind:'BinaryOp',shape:'logic',pins:['A','B','Y']};
 assert.equal(G.operatorFace(n).known,true,name);
 assert.equal(G.operatorFace(n).family,family,name);
 const trace=traceNode(n);
 assert(!trace.some(x=>x[0]==='fillText'&&x[1]==='OP'),name);
 if(family!=='not')assert(trace.some(x=>x[0]==='fillText'&&x[1]===mark));
}
const andNode={id:'and',type:'operator',kind:'BinaryOp',name:'BinaryAnd',pins:['A','B','Y'],
 operandDetails:{A:'axi_lite_req_i.aw_valid',B:'axi_lite_req_i.w_valid'},shape:'logic'};
assert(!traceNode(andNode).some(x=>x[0]==='fillText'&&String(x[1]).includes('axi_lite')),
 'full source paths belong in inspector, not on the glyph');
const cast={id:'cast',type:'operator',kind:'Conversion',name:'Conversion',pins:['A','Y']};
assert(G.boxSize(cast).h<66,'conversion should not occupy a full logic-cell footprint');
const mux={id:'mux',type:'operator',kind:'ConditionalOp',name:'ConditionalOp',shape:'mux',
 pins:['A','B','S','Y'],literalOperands:{A:"1'b0",B:"1'b1"}};
const muxTexts=traceNode(mux).filter(x=>x[0]==='fillText').map(x=>x[1]);
assert(muxTexts.includes('MUX'));assert(muxTexts.includes("1'b0"));assert(muxTexts.includes("1'b1"));
const nodes=[{id:'a',type:'signal'},{id:'b',type:'signal'},andNode,{id:'out',type:'port',direction:'out'}],
 edges=[{id:'a-and',source:'a',target:'and',net:'a',targetPin:'A'},
 {id:'b-and',source:'b',target:'and',net:'b',targetPin:'B'},
 {id:'and-out',source:'and',target:'out',net:'result'}];
(async()=>{
 const layout=await A.compute(new ELK(),{nodes,edges},G.boxSize);
 for(const e of edges){
  const path=layout.edgePaths.get(e.id);
  const src=G.absoluteAnchor(nodes.find(n=>n.id===e.source),layout.positions.get(e.source),'source',e);
  const dst=G.absoluteAnchor(nodes.find(n=>n.id===e.target),layout.positions.get(e.target),'target',e);
  assert.deepEqual(path[0],[src.x,src.y]);assert.deepEqual(path.at(-1),[dst.x,dst.y]);
 }
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    r = subprocess.run(["node", "-e", script, str(WEB)], capture_output=True, text=True,
                       timeout=45)
    assert r.returncode == 0, r.stderr + r.stdout
