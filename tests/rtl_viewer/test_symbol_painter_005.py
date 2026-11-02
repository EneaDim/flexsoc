"""Production symbol renderer: Canvas state, label budgeting and ELK endpoints."""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_symbol_painter_is_standalone_and_preserves_canvas_state():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    script = r'''
const assert=require('node:assert/strict');
const W=process.argv[1],G=require(W+'/symbol-geometry.js'),P=require(W+'/symbol-painter.js');
const palette={signal:'#8899bb',port:'#1199cc',register:'#aabba3',counter:'#ffaabb',fsm:'#ff88aa',
 operator:'#dd8800',instance:'#77ccee',generate:'#cc8866',selected:'#ffff66',wire:'#ffffff',
 symbolFill:'#223344',pickedFill:'#335577',stackFill:'#224466',stackStroke:'#555555',
 text:'#ffffff',muted:'#aaccee',binding:'#00ffff',sequential:'#ffa500'};
function context(){
 const trace=[];let level=0;
 const methods=['beginPath','moveTo','lineTo','fill','stroke','arc','closePath','roundRect',
 'strokeRect','fillText','rect','clip','quadraticCurveTo'];
 const ctx={trace,get level(){return level},save(){level++;trace.push(['save'])},restore(){level--;trace.push(['restore'])}};
 for(const m of methods)ctx[m]=(...args)=>trace.push([m,...args]);
 return ctx;
}
const nodes=[
 {id:'sig',type:'signal',name:'foo'},
 {id:'port',type:'port',name:'payload',direction:'inout'},
 {id:'mux',type:'operator',shape:'mux',name:'ConditionalOp',literalOperands:{A:'42'}},
 {id:'sum',type:'operator',shape:'arith',name:'Add'},
 {id:'q',type:'register',name:'state_reg'},
 {id:'array',type:'generate',name:'generate_array',count:6,ports:[
  {name:'input_very_long_payload_bus',direction:'in'},
  {name:'output_another_long_bus',direction:'out'},
  {name:'io',direction:'inout',connection:'partial'}]},
 {id:'mod',type:'instance',name:'u_core',module:'CPUCore',ports:[
  {name:'clk',direction:'input',connection:'bound'},
  {name:'valid',direction:'output',connection:'unbound'}]}
];
for(const n of nodes){
 const rect={x:13,y:22,...G.boxSize(n)},ctx=context(),snapshot=JSON.stringify(n);
 P.paint(ctx,n,rect,{colors:palette,picked:true,zoom:1.2,names:true,
 edges:[{type:'event',target:'q',pin:'CLK'},{type:'event',target:'q',pin:'RST'}]});
 assert.equal(ctx.level,0,'context saved/restored');
 assert.equal(JSON.stringify(n),snapshot,'painter must not mutate the graph');
 assert(ctx.trace.some(x=>x[0]==='stroke'),'a real glyph is drawn');
 assert(ctx.trace.every(command=>command.slice(1).every(v=>typeof v!=='number'||Number.isFinite(v))),
   'finite glyph coordinates');
 if(n.type==='instance'||n.type==='generate'){
  const left=G.portRows(n,'target'),right=G.portRows(n,'source');
  for(const pin of [...left,...right]){
   assert(ctx.trace.some(e=>e[0]==='moveTo'&&e[1]===rect.x+pin.x&&e[2]===rect.y+pin.y),
    'visible lead must originate at physical ELK terminal: '+pin.port.name);
  }
  const labels=ctx.trace.filter(x=>x[0]==='fillText');
  assert(labels.filter(x=>String(x[1]).includes('long_bus')||String(x[1]).includes('payload_bus'))
   .every(x=>Number.isFinite(x[4])&&x[4]<rect.w/2),
    'long port labels must be clipped to half the module width');
 }
}
const long=nodes[5];
assert(G.boxSize(long).w>220,'long module port labels receive more space');
assert(G.boxSize(long).w<=356,'width growth is bounded');
const original=JSON.stringify(nodes);
const empty=context();
P.paint(empty,{type:'signal',name:'unselected'},{x:0,y:0,w:170,h:42},
 {colors:palette,names:false,zoom:.2});
assert.equal(empty.level,0,'early exits restore canvas');
assert.equal(JSON.stringify(nodes),original);
console.log('CANVAS SYMBOL PAINTER PASS');
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                            text=True, timeout=20)
    assert result.returncode == 0, result.stderr + result.stdout
    assert 'CANVAS SYMBOL PAINTER PASS' in result.stdout


def test_elk_real_dynamic_module_width_preserves_pin_routes():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    script = r'''
const assert=require('node:assert/strict');
const W=process.argv[1],ELK=require(W+'/elk.bundled.js').default;
const G=require(W+'/symbol-geometry.js'),A=require(W+'/elk-adapter.js');
const nodes=[{id:'source',type:'port',direction:'in',name:'incoming'},
 {id:'module',type:'instance',name:'u_core',ports:[
  {name:'the_really_long_input_bus',direction:'input'},
  {name:'the_really_long_output_bus',direction:'output'}]},
 {id:'sink',type:'port',name:'outgoing',direction:'out'}];
const edges=[{id:'in',source:'source',target:'module',port:'the_really_long_input_bus',net:'in'},
 {id:'out',source:'module',sourcePin:'the_really_long_output_bus',target:'sink',net:'out'}];
(async()=>{
 const graph={nodes,edges},result=await A.compute(new ELK(),graph,G.boxSize);
 assert.equal(result.edgePaths.size,2);
 const byId=Object.fromEntries(nodes.map(n=>[n.id,n]));
 for(const e of edges){
  const start=G.absoluteAnchor(byId[e.source],result.positions.get(e.source),'source',e);
  const end=G.absoluteAnchor(byId[e.target],result.positions.get(e.target),'target',e);
  const pts=result.edgePaths.get(e.id);
  assert.deepEqual(pts[0],[start.x,start.y]);
  assert.deepEqual(pts.at(-1),[end.x,end.y]);
 }
 console.log('REAL ELK DYNAMIC MODULE PASS');
})().catch(err=>{console.error(err);process.exitCode=1});
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                            text=True, timeout=30)
    assert result.returncode == 0, result.stderr + result.stdout
    assert 'REAL ELK DYNAMIC MODULE PASS' in result.stdout
