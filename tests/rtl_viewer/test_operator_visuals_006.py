"""AST-driven operator glyphs and proven sequential event polarities.

The tests record Canvas commands and exercise real ELK endpoint routing.
No generic signal-name heuristic is used for hardware semantics.
"""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def _node(script):
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    result = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                            text=True, timeout=35)
    assert result.returncode == 0, result.stderr + result.stdout


def test_operator_faces_and_sequential_polarities_are_compiler_backed():
    _node(r'''
const assert=require('node:assert/strict'),W=process.argv[1];
const G=require(W+'/symbol-geometry.js'),P=require(W+'/symbol-painter.js');
const palette={signal:'#8899bb',port:'#1199cc',register:'#aabba3',counter:'#ffaabb',fsm:'#ff88aa',
 operator:'#dd8800',instance:'#77ccee',generate:'#cc8866',selected:'#ffff66',wire:'#ffffff',
 symbolFill:'#223344',pickedFill:'#335577',stackFill:'#224466',stackStroke:'#555555',
 text:'#ffffff',muted:'#aaccee',binding:'#00ffff',sequential:'#ffa500'};
function context(){
 const trace=[];let depth=0;
 const ctx={trace,get depth(){return depth},save(){depth++;trace.push(['save'])},
  restore(){depth--;trace.push(['restore'])}};
 for(const method of ['beginPath','moveTo','lineTo','fill','stroke','arc','closePath','roundRect',
   'strokeRect','fillText','rect','clip','quadraticCurveTo'])
  ctx[method]=(...args)=>trace.push([method,...args]);
 return ctx;
}
function render(n,edges=[]){
 const rect={x:20,y:30,...G.boxSize(n)},ctx=context(),frozen=JSON.stringify(n);
 P.paint(ctx,n,rect,{colors:palette,zoom:1.2,names:true,edges});
 assert.equal(ctx.depth,0);
 assert.equal(JSON.stringify(n),frozen,'glyph never modifies compiler data');
 assert(ctx.trace.every(e=>e.slice(1).every(v=>typeof v!=='number'||Number.isFinite(v))));
 return {trace:ctx.trace,rect};
}
for(const [op,mark,family] of [
 ['BitwiseAnd','&','and'],['LogicalAnd','&&','and'],['BitwiseOr','|','or'],
 ['LogicalOr','||','or'],['BitwiseXor','^','xor'],['Add','+','arithmetic'],
 ['LessThan','<','compare'],['NotEqual','≠','compare'],['Conversion','CAST','generic']]){
 const n={id:op,type:'operator',kind:'BinaryOp',shape:'arith',name:op,pins:['A','B','Y']};
 assert.equal(G.operatorFace(n).mark,mark);
 assert.equal(G.operatorFace(n).family,family);
 const {trace,rect}=render(n);
 assert(trace.some(e=>e[0]==='fillText'&&e[1]===mark),op+': expected glyph');
 for(const role of ['A','B']){
  const a=G.absoluteAnchor(n,rect,'target',{targetPin:role});
  assert(trace.some(e=>e[0]==='moveTo'&&e[1]===a.x&&e[2]===a.y),op+': pin '+role);
 }
 const a=G.absoluteAnchor(n,rect,'source',{sourcePin:'Y'});
 assert(trace.some(e=>e[0]==='lineTo'&&e[1]===a.x&&e[2]===a.y),op+': output pin');
 if(['and','or','xor'].includes(family))assert(trace.some(e=>e[0]==='quadraticCurveTo'));
}
const unknown={id:'op',type:'operator',kind:'BinaryOp',shape:'arith',name:'FutureASTOperation'};
const tr=render(unknown).trace;
assert(tr.some(e=>e[0]==='fillText'&&e[1]==='OP'));
assert(tr.some(e=>e[0]==='fillText'&&e[1]==='FutureASTOpe…'));
assert(G.boxSize({type:'register'}).h>=100,'timing glyph and name need separate visual bands');
assert.equal(G.operatorFace({...unknown,name:'and_signal'}).known,false,
 'a signal-like name is not an AST operation');
const reg={id:'q',type:'register',name:'output_reg'};
const ev=[{type:'event',target:'q',pin:'CLK'},{type:'event',target:'q',pin:'RST'}];
const counts=n=>render(n,ev).trace.filter(e=>e[0]==='arc').length;
assert.equal(counts(reg),0,'without provenance do not invent polarity bubbles');
assert.equal(counts({...reg,sequentialTiming:[{role:'ambiguous_event',edge:'NegEdge'}]}),0);
assert.equal(counts({...reg,sequentialTiming:[{role:'clock',edge:'PosEdge'},{role:'async_reset',edge:'NegEdge'}]}),1);
assert.equal(counts({...reg,sequentialTiming:[{role:'clock',edge:'NegEdge'},{role:'async_reset',edge:'NegEdge'}]}),2);
assert.equal(counts({...reg,sequentialTiming:[{role:'clock',edge:'NegEdge'},{role:'clock',edge:'PosEdge'}]}),0);
console.log('AST-DRIVEN SYMBOL VISUALS PASS');
''')


def test_real_elk_operator_shapes_still_hit_canonical_terminals():
    _node(r'''
const assert=require('node:assert/strict'),W=process.argv[1];
const ELK=require(W+'/elk.bundled.js').default,G=require(W+'/symbol-geometry.js');
const A=require(W+'/elk-adapter.js');
const nodes=[{id:'a',type:'port',direction:'in'}, {id:'b',type:'port',direction:'in'},
 {id:'and',type:'operator',kind:'BinaryOp',name:'BitwiseAnd',shape:'arith',pins:['A','B','Y']},
 {id:'cmp',type:'operator',kind:'BinaryOp',name:'LessThan',shape:'arith',pins:['A','B','Y']},
 {id:'out',type:'port',direction:'out'}];
const edges=[{id:'a-and',source:'a',target:'and',targetPin:'A',net:'a'},
 {id:'b-and',source:'b',target:'and',targetPin:'B',net:'b'},
 {id:'and-cmp',source:'and',target:'cmp',targetPin:'A',net:'and-result'},
 {id:'b-cmp',source:'b',target:'cmp',targetPin:'B',net:'b'},
 {id:'cmp-out',source:'cmp',target:'out',net:'cmp-result'}];
(async()=>{
 const original=JSON.stringify({nodes,edges}),out=await A.compute(new ELK(),{nodes,edges},G.boxSize);
 const byId=Object.fromEntries(nodes.map(n=>[n.id,n]));
 for(const e of edges){
  const line=out.edgePaths.get(e.id);
  assert.deepEqual(line[0],Object.values(G.absoluteAnchor(byId[e.source],out.positions.get(e.source),'source',e)).slice(0,2));
  assert.deepEqual(line.at(-1),Object.values(G.absoluteAnchor(byId[e.target],out.positions.get(e.target),'target',e)).slice(0,2));
 }
 assert.equal(JSON.stringify({nodes,edges}),original);
 console.log('REAL ELK OPERATOR TERMINALS PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
''')
