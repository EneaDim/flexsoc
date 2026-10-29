'use strict';
const $ = id => document.getElementById(id);

// FSRTL-0054 UX: preserve existing inspector layout and supply missing Details tab.
function ensureDetailsUI(){
 const inspector=$('inspector');if(!inspector)return;
 const tabs=inspector.querySelector('.tabs');
 if(tabs&&!$('detailsTab')){const b=document.createElement('button');b.id='detailsTab';b.type='button';b.setAttribute('role','tab');b.textContent='Details';tabs.prepend(b);}
 if(!$('detailsPane')){const p=document.createElement('div');p.id='detailsPane';p.className='pane';p.hidden=true;
 const h=document.createElement('div');h.className='source-head';h.textContent='Selected RTL entity · compiler-backed';
 const r=document.createElement('div');r.id='detailsResults';r.className='results';p.append(h,r);
 const source=$('sourcePane');if(source)source.before(p);else inspector.append(p);}
 if($('detailsTab'))$('detailsTab').onclick=()=>inspectorTab('details');
}
function inspectorTab(tab){inspector(true,tab);}
function installSidebarResize(){
 const side=document.querySelector('.sidebar');if(!side||document.getElementById('rtlSidebarResize'))return;
 const handle=document.createElement('div');handle.id='rtlSidebarResize';handle.className='rtl-sidebar-resizer';
 handle.setAttribute('role','separator');handle.setAttribute('aria-orientation','vertical');handle.setAttribute('aria-label','Resize module navigator');handle.tabIndex=0;
 side.after(handle);
 let dragging=false;
 const setWidth=n=>{const w=Math.max(180,Math.min(520,n));side.style.width=w+'px';side.style.minWidth=w+'px';handle.setAttribute('aria-valuenow',String(w));};
 handle.addEventListener('pointerdown',e=>{dragging=true;handle.setPointerCapture(e.pointerId);e.preventDefault();});
 handle.addEventListener('pointermove',e=>{if(dragging){setWidth(e.clientX-side.getBoundingClientRect().left);resize();}});
 handle.addEventListener('pointerup',()=>{dragging=false;});
 handle.addEventListener('pointercancel',()=>{dragging=false;});
 handle.addEventListener('keydown',e=>{if(e.key==='ArrowLeft'||e.key==='ArrowRight'){setWidth(side.getBoundingClientRect().width+(e.key==='ArrowLeft'?-20:20));resize();e.preventDefault();}});
}
function initExplorerUX(){ensureDetailsUI();installSidebarResize();}
if(document.readyState==='loading')document.addEventListener('DOMContentLoaded',initExplorerUX,{once:true});else initExplorerUX();

const canvas = $('diagram'), ctx = canvas.getContext('2d', {alpha:false});
const state = {overview:null,graph:null,path:'/',expanded:new Map(),viewport:new Map(),layouts:new Map(),selected:null,multiSelected:new Set(),pinned:null,hover:null,drag:null,inspector:false,tab:'source',context:null,wire:null,manualView:false,visibility:{wires:true,names:true,lint:false},lintItems:[],lintStatus:"unavailable",lintRequest:0};
// FlexSoC brand system: orange = transformations, sky = connectivity,
// navy = hierarchy, neutral graphite = chrome. Colors remain legible in both modes.
const palettes={
 dark:{counter:'#ffbd70',fsm:'#9de2ee',port:'#53bfff',signal:'#91b2cd',register:'#ff9954',operator:'#ffb56c',instance:'#54c4ec',generate:'#ffa558',wire:'#6faace',binding:'#48c5ee',sequential:'#fb9a5d',selected:'#ffd089',symbolFill:'#1b3046',pickedFill:'#284560',stackFill:'#34475b',stackStroke:'#9b6e4a',text:'#f0f6ff',muted:'#a9c3d8',canvas:'#111c2b'},
 light:{counter:'#bd5815',fsm:'#1384ba',port:'#0879b2',signal:'#456d88',register:'#d35b1b',operator:'#c36a20',instance:'#0b82bb',generate:'#e06e22',wire:'#4c86aa',binding:'#167eac',sequential:'#c76320',selected:'#ee8429',symbolFill:'#e9f3fa',pickedFill:'#d3e9f9',stackFill:'#dbe4ef',stackStroke:'#b36e3c',text:'#102c4b',muted:'#375b78',canvas:'#f4f9fd'}
};
let colors=palettes.dark;

const clamp=(x,lo,hi)=>Math.min(hi,Math.max(lo,x));
const keyOf=n=>n?.net||n?.id||'';
const isSignal=n=>n?.id?.includes('::sig:');
function applyTheme(mode){
 const next=mode==='light'?'light':'dark';
 document.documentElement.dataset.theme=next;
 colors=palettes[next];
 $('themeToggle').textContent=next==='light'?'☾ Dark':'☀ Light';
 $('themeToggle').setAttribute('aria-label','Switch to '+(next==='light'?'dark':'light')+' theme');
 try{localStorage.setItem('flexsoc-rtl-theme',next);}catch(_e){}
 draw();
}
function announce(message){$('message').textContent=message;}
async function api(name,params={}) {
 if(typeof window.FlexAPI==='function') return window.FlexAPI(name,params);
 const url=new URL('/api/'+name,location.protocol==='about:'?'http://localhost':location.href);
 Object.entries(params).forEach(([k,v])=>url.searchParams.set(k,v));
 const r=await fetch(url);const data=await r.json();if(!r.ok)throw Error(data.error||r.status);return data;
}
function view(){return state.viewport.get(state.path)||{x:90,y:90,z:1};}
function setView(v){state.viewport.set(state.path,v);}
let lastCanvasSize={w:0,h:0};
function resize(){
 const w=canvas.clientWidth||1,h=canvas.clientHeight||1,scale=Math.min(devicePixelRatio||1,2);
 const changed=Math.abs(w-lastCanvasSize.w)>2||Math.abs(h-lastCanvasSize.h)>2;
 lastCanvasSize={w,h};canvas.width=Math.floor(w*scale);canvas.height=Math.floor(h*scale);
 // The inspector changes the *canvas width*. Refit after ResizeObserver has
 // measured the new width, not before CSS flexbox has completed its layout.
 if(changed&&state.graph&&!state.manualView&&w>220&&h>180)fit();else draw();
}
new ResizeObserver(resize).observe(canvas);
// ELK-only: the historical native router must never paint an RTL graph.
// Retain FlexRouting only for symbol dimensions and pin markers.
const boxSize=FlexRouting.boxSize,baseRank=FlexRouting.baseRank;
const layoutEngine=FlexLayoutEngine.create({boxSize,baseRank});
const elkPending=new Set();
const elkFailed=new Set();
let elkEnabled=false;
const emptyGeometry=()=>({positions:new Map(),edgePaths:new Map(),bridges:[],width:1,height:1,stats:{engine:'pending'}});
const layoutIndicator=document.createElement('div');
layoutIndicator.id='layoutEngineStatus';
layoutIndicator.className='rtl-layout-status';
layoutIndicator.setAttribute('role','status');
document.body.append(layoutIndicator);
function setLayoutStatus(kind,reason=''){
 layoutIndicator.textContent='LAYOUT: '+kind+(reason?' — '+String(reason).slice(0,220):'');
 layoutIndicator.title=reason||kind;
}
setLayoutStatus('ELK / LOADING','initializing renderer');
function enableLocalELK(){
 try{
  if(typeof window.ELK!=='function'||!layoutEngine.setELK(new window.ELK()))throw Error('ELK runtime missing');
  elkEnabled=true;setLayoutStatus('ELK / READY');return true;
 }catch(error){setLayoutStatus('ELK / ERROR',error.message);console.error('[rtl-view] ELK initialization failed:',error);return false;}
}
function scheduleELK(graph,id){
 if(!elkEnabled){setLayoutStatus('ELK / ERROR','ELK runtime unavailable; native layout removed');return;}
 if(elkPending.has(id)||elkFailed.has(id))return;
 elkPending.add(id);setLayoutStatus('ELK / COMPUTING');
 Promise.resolve().then(()=>layoutEngine.computeELK(graph)).then(result=>{
  const current=state.graph;
  const key=current?.path+':'+(current?.expanded||[]).join('|')+':'+current?.revision;
  if(key!==id||current!==graph)return;
  state.layouts.set(id,result);
  const problems=(result.stats?.treeStrictErrors||0)+(result.stats?.treeMissingRoutes||0)+(result.stats?.treeFallbacks||0)+(result.stats?.laneUnresolved||0);
  setLayoutStatus(problems?'ELK / ROUTING ISSUES':'ELK',
   'net trees '+(result.stats?.treeNets||0)+'; unresolved '+(result.stats?.treeFallbacks||0)+
   '; missing '+(result.stats?.treeMissingRoutes||0)+'; issues '+(result.stats?.treeStrictErrors||0)+
   '; overlaps '+(result.stats?.laneUnresolved||0)+'; separated '+(result.stats?.laneResolved||0));
  if(result.stats?.treeErrors?.length)console.warn('[rtl-view] Unrouted physical terminals',result.stats.treeErrors);
  if(!state.manualView)fit();else draw();
 }).catch(error=>{
  const current=state.graph;
  const key=current?.path+':'+(current?.expanded||[]).join('|')+':'+current?.revision;
  if(key===id&&current===graph){
   elkFailed.add(id);
   state.layouts.delete(id);
   setLayoutStatus('ELK / ERROR',error.message);
   draw();
  }
  console.error('[rtl-view] ELK layout failed (no native fallback):',error);
 }).finally(()=>elkPending.delete(id));
}
function layout(graph){
 const id=graph.path+':'+(graph.expanded||[]).join('|')+':'+graph.revision;
 if(state.layouts.has(id))return state.layouts.get(id);
 scheduleELK(graph,id);
 return emptyGeometry();
}
function round(x,y,w,h,r){ctx.beginPath();ctx.roundRect(x,y,w,h,r);}
function visible(p,v,w,h,margin=60){return(p.x+p.w)*v.z+v.x>=-margin&&p.x*v.z+v.x<=w+margin&&(p.y+p.h)*v.z+v.y>=-margin&&p.y*v.z+v.y<=h+margin;}
function wireVisible(points,v,w,h){const xs=points.map(p=>p[0]),ys=points.map(p=>p[1]);return visible({x:Math.min(...xs),y:Math.min(...ys),w:Math.max(...xs)-Math.min(...xs),h:Math.max(...ys)-Math.min(...ys)},v,w,h);}
// Selection is one visual conductor identified by its canonical net, not a
// combined selection of direct/partial relationships. Edge details stay AST-backed.
function highlighted(e){const identity=e.net||e.id;return (state.hover?.net||state.hover?.id)===identity||state.selected===identity||state.multiSelected.has(identity)||state.pinned===identity;}
function pathDraw(points){ctx.beginPath();points.forEach(([x,y],i)=>i?ctx.lineTo(x,y):ctx.moveTo(x,y));}
function drawWire(e,points,v){
 const hot=highlighted(e),partial=e.mapping==='partial';
 ctx.lineWidth=hot?3.8:e.width?.includes('[')?2.6:1.8;
 ctx.strokeStyle=hot?colors.selected:colors.wire;
 ctx.globalAlpha=hot?1:.88;ctx.lineJoin='round';ctx.lineCap='round';
 ctx.setLineDash([]);
 pathDraw(points);ctx.stroke();ctx.setLineDash([]);ctx.globalAlpha=1;
 // Arrow points along the *last nonzero* segment: left-going and vertical
 // feedback nets must not be drawn with a misleading right-facing arrow.
 const b=points[points.length-1];let a=points[points.length-2];
 if(!a||!b)return;
 const angle=Math.atan2(b[1]-a[1],b[0]-a[0]);
 ctx.fillStyle=ctx.strokeStyle;ctx.beginPath();ctx.moveTo(b[0],b[1]);
 ctx.lineTo(b[0]-9*Math.cos(angle-.43),b[1]-9*Math.sin(angle-.43));
 ctx.lineTo(b[0]-9*Math.cos(angle+.43),b[1]-9*Math.sin(angle+.43));ctx.closePath();ctx.fill();
 // Packets/slices are displayed as a *proven RTL net type*, never as
 // fabricated per-bit wiring. Partial mapping is explicitly distinguished.
 if(e.width?.includes('[')&&v.z>=.78&&!hot){
  const segment=points.slice(1).map((p,i)=>({a:points[i],b:p})).find(s=>s.a[1]===s.b[1]&&Math.abs(s.a[0]-s.b[0])>75);
  if(segment){const x=(segment.a[0]+segment.b[0])/2,y=segment.a[1];ctx.font='10px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   ctx.fillText((partial?'≈ ':'')+String(e.width).slice(0,22),x,y-8);}
 }
 if(e.count>1&&v.z>=.55){ctx.font='10px ui-monospace,monospace';ctx.fillStyle=colors.selected;ctx.fillText('×'+e.count,points[1][0]+6,points[1][1]-9);}
 if(hot&&v.z>=.55){ctx.font='11px ui-monospace,monospace';ctx.fillStyle=colors.selected;
  const label=(e.port?`${e.port} • `:'')+(e.net?.split('::sig:').pop()||'net')+
   (partial?' [partial dependency]':'')+(e.width?.includes('[')?' '+e.width:'');
  ctx.fillText(rtlLabel(label).slice(0,83),points[1][0]+5,points[1][1]-9);
 }
}
// FSRTL-0055 compact symbols: verified functional operator glyphs and distinct event terminals.
function rtlLabel(value){return String(value).replace(/(^|[.\s])\d{8,}\s+/g,'$1');}
function symbol(n,p,diagram){const {x,y,w,h}=p,c=colors[n.type]||colors.signal;let picked=state.selected===n.id||state.multiSelected.has(n.id)||state.pinned===n.id||state.hover?.id===n.id;
 ctx.lineWidth=picked?2.9:1.6;ctx.strokeStyle=picked?colors.selected:c;ctx.fillStyle=picked?colors.pickedFill:colors.symbolFill;
 if(n.type==='signal'){
  ctx.lineWidth=picked?3.5:2;ctx.beginPath();ctx.moveTo(x+8,y+h/2);ctx.lineTo(x+w-8,y+h/2);ctx.stroke();ctx.fillStyle=c;ctx.beginPath();ctx.arc(x+w/2,y+h/2,5,0,Math.PI*2);ctx.fill();
  if(view().z>=.43){ctx.font='12px ui-monospace,monospace';ctx.fillStyle=colors.text;ctx.fillText(n.name.slice(0,21),x+8,y+11);if(view().z>=.7){ctx.font='9px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   const packed=n.dimensions?.packedDimensions,unpacked=n.dimensions?.unpackedDimensions;
   const shape=unpacked?'unpacked '+JSON.stringify(unpacked):packed?'packed '+JSON.stringify(packed):n.width||'';
   if(shape)ctx.fillText(rtlLabel(shape).slice(0,26),x+9,y+h-3);
  }}
  return;}
 if(n.type==='port'){
  ctx.beginPath();ctx.moveTo(x+7,y+3);ctx.lineTo(x+w-25,y+3);ctx.lineTo(x+w-7,y+h/2);ctx.lineTo(x+w-25,y+h-3);ctx.lineTo(x+7,y+h-3);ctx.closePath();ctx.fill();ctx.stroke();
  ctx.fillStyle=colors.muted;ctx.font='10px ui-monospace,monospace';ctx.fillText(['out','output'].includes(n.direction)?'OUT':'IN',x+16,y+13);}
 else if(n.type==='operator'){
  if(n.shape==='mux'){
   // IEC-style trapezoidal multiplexer symbol. Selected AST conditional,
   // not a heuristic based on the name of a signal.
   ctx.beginPath();ctx.moveTo(x+9,y+6);ctx.lineTo(x+w-15,y+22);ctx.lineTo(x+w-15,y+h-20);ctx.lineTo(x+9,y+h-6);ctx.closePath();ctx.fill();ctx.stroke();
   // Pin ends come from the same geometry used by the router.
   const r={x,y,w,h};
   for(const role of ['A','B','S']){
    const p=FlexRouting.pinGeometry(n,r,role,'in');
    ctx.beginPath();
    if(role==='S'){ctx.moveTo(p.x,p.y+11);ctx.lineTo(p.x,p.y);}
    else{ctx.moveTo(p.x-12,p.y);ctx.lineTo(p.x,p.y);}
    ctx.stroke();
   }
   const out=FlexRouting.pinGeometry(n,r,'Y','out');
   ctx.beginPath();ctx.moveTo(out.x,out.y);ctx.lineTo(out.x+8,out.y);ctx.stroke();
   ctx.font='10px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   ctx.fillText('A·0',x+13,y+20);ctx.fillText('B·1',x+13,y+h-17);
   ctx.fillText('S',x+w/2+7,y+h-7);for(const role of ['A','B','S']){const literal=n.literalOperands?.[role]??(n.operandDetails?.[role]?.includes('.')?n.operandDetails[role]:undefined);if(literal!==undefined){const pin=FlexRouting.pinGeometry(n,r,role,'in');ctx.save();ctx.fillStyle=colors.text;ctx.font='10px ui-monospace,monospace';ctx.textAlign=role==='S'?'center':'right';ctx.fillText(rtlLabel(literal),role==='S'?pin.x:pin.x-12,role==='S'?pin.y+25:pin.y-7,120);ctx.restore();}}
  }else if(n.shape==='arith'){
   // FSRTL-0055 compact symbols: functionality from AST operator name, never net names.
   round(x+6,y+7,w-13,h-14,7);ctx.fill();ctx.stroke();
   const op=String(n.name||'').toLowerCase();
   const exact={add:'+',plus:'+',subtract:'−',sub:'−',multiply:'×',mul:'×',divide:'÷',div:'÷',mod:'%',modulo:'%',equal:'=',equals:'=',not_equal:'≠',notequal:'≠',less_than:'<',greater_than:'>',less_equal:'≤',greater_equal:'≥',less_than_equal:'≤',greater_than_equal:'≥',shift_left:'≪',shift_right:'≫',arithmetic_shift_right:'≫'};
   const known=Object.prototype.hasOwnProperty.call(exact,op)?exact[op]:null;
   ctx.fillStyle=colors.text;ctx.font='bold 20px system-ui,sans-serif';ctx.textAlign='center';
   ctx.fillText(known||'ƒ',x+w/2,y+h/2+7);ctx.textAlign='left';
   for(const role of ['A','B']){const p=FlexRouting.pinGeometry(n,{x,y,w,h},role,'in');ctx.beginPath();ctx.moveTo(p.x-8,p.y);ctx.lineTo(p.x+3,p.y);ctx.stroke();
    // Literal inputs are an AST-proven connection to a constant, not a wire.
    const literal=n.literalOperands?.[role]??(n.operandDetails?.[role]?.includes('.')?n.operandDetails[role]:undefined);
    if(literal!==undefined){ctx.save();ctx.fillStyle=colors.text;ctx.font='600 11px ui-monospace,monospace';ctx.textAlign='left';ctx.fillText(rtlLabel(literal),p.x+9,p.y+4,Math.max(30,w-25));ctx.restore();}
   }
   const out=FlexRouting.pinGeometry(n,{x,y,w,h},'Y','out');ctx.beginPath();ctx.moveTo(out.x-4,out.y);ctx.lineTo(out.x+7,out.y);ctx.stroke();
  }else if(['case','encoder','decoder'].includes(n.shape)){
   // Case-dispatch symbol; ENC/DEC shapes require explicit semantic metadata,
   // never merely a textual match against the module or signal name.
   round(x+7,y+9,w-14,h-18,9);ctx.fill();ctx.stroke();
   ctx.strokeStyle=colors.muted;ctx.beginPath();
   for(let i=0;i<3;i++){ctx.moveTo(x+1,y+21+i*15);ctx.lineTo(x+8,y+21+i*15);}
   ctx.moveTo(x+w-7,y+h/2);ctx.lineTo(x+w,y+h/2);ctx.stroke();
  }else{round(x+6,y+7,w-13,h-14,7);ctx.fill();ctx.stroke();}}
 else if(['register','counter','fsm'].includes(n.type)){
  round(x+4,y+3,w-8,h-6,5);ctx.fill();ctx.stroke();
  const timingPins=new Set((state.graph?.edges||[]).filter(e=>e.target===n.id&&e.type==='event').map(e=>e.pin||'EVENT'));
  const anchor=(role)=>FlexElkAdapter.anchor(n,'target',{type:'event',pin:role},{w,h});
  // ELK and Canvas consume the SAME anchor. The physical border is y+h-3.
  if(timingPins.has('CLK')){
   const pin=anchor('CLK'),px=x+pin.x,py=y+pin.y;
   ctx.beginPath();ctx.moveTo(px-9,py);ctx.lineTo(px,py-12);ctx.lineTo(px+9,py);ctx.stroke();
  }
  if(timingPins.has('RST')){
   const pin=anchor('RST'),px=x+pin.x,py=y+pin.y;
   ctx.beginPath();ctx.moveTo(px,py);ctx.lineTo(px,py-10);ctx.stroke();
  }
  if(timingPins.has('EVENT')){
   const pin=anchor('EVENT'),px=x+pin.x,py=y+pin.y;
   ctx.beginPath();ctx.moveTo(px,py);ctx.lineTo(px,py-9);ctx.stroke();
  }
  ctx.fillStyle=colors.register;ctx.font='10px ui-monospace,monospace';
  ctx.fillText('D',x+10,y+16);ctx.fillText('Q',x+w-23,y+16);
  for(const role of ['CLK','RST','EVENT'])if(timingPins.has(role)){
   const pin=anchor(role);ctx.textAlign='center';ctx.fillText(role==='EVENT'?'EVT':role,x+pin.x,y+h-20);ctx.textAlign='left';
  }
if(n.type==='counter'){ctx.fillText('↻',x+w-29,y+h-11);}if(n.type==='fsm')ctx.fillText('ST',x+w-28,y+h-11);}
 else{
  if(n.type==='generate'){for(let i=2;i>=1;i--){ctx.fillStyle=colors.stackFill;round(x+i*6,y+i*7,w-4,h-4,6);ctx.fill();ctx.strokeStyle=colors.stackStroke;ctx.stroke();}ctx.strokeStyle=picked?colors.selected:c;ctx.fillStyle=colors.symbolFill;}
  round(x,y,w-12,h-12,5);ctx.fill();ctx.stroke();ctx.strokeRect(x+7,y+7,w-26,h-26);
  for(const dir of ['in','out']){const ports=(n.ports||[]).filter(p=>dir==='in'?['in','input'].includes(p.direction):['out','output'].includes(p.direction));ports.forEach((port,i)=>{const py=y+(dir==='out'?65:53)+i*19,left=dir==='in';ctx.strokeStyle=['unbound','unresolved'].includes(port.connection)?colors.generate:port.connection==='partial'?colors.sequential:colors.instance;
   const px=left?x:x+w-6;
   ctx.beginPath();ctx.moveTo(left?x:x+w-20,py);ctx.lineTo(left?x+8:x+w-6,py);ctx.stroke();
   if(port.connection==='unbound'){ctx.beginPath();ctx.arc(px,py,3.3,0,Math.PI*2);ctx.stroke();}
   else if(port.connection==='constant'){
    ctx.fillStyle=colors.binding;ctx.font='bold 11px ui-monospace,monospace';
    ctx.fillText('C',px-3,py-5);
   }
   else if(port.connection==='unresolved'){
    ctx.fillStyle=colors.generate;ctx.font='bold 11px ui-monospace,monospace';
    ctx.fillText('?',px-3,py-5);
   }
   if(state.visibility.names&&view().z>=.48){ctx.fillStyle=['unbound','unresolved'].includes(port.connection)?colors.generate:colors.muted;ctx.font='9px ui-monospace,monospace';ctx.textAlign=left?'left':'right';ctx.fillText(port.name.slice(0,15),left?x+13:x+w-24,py+3);ctx.textAlign='left';}});}}
 if(view().z<.36||!state.visibility.names)return;
 ctx.font=n.type==='operator'?'bold 10px ui-monospace,monospace':'600 13px system-ui,sans-serif';ctx.fillStyle=colors.text;
 if(n.type==='operator'){ctx.textAlign='center';if(n.shape!=='arith')ctx.fillText((n.shape==='mux'?'MUX':n.shape==='case'?'CASE':n.shape==='encoder'?'ENC':n.shape==='decoder'?'DEC':(String(n.name).toLowerCase().includes('conversion')?'CAST':String(n.name))).slice(0,7),x+w/2,y+h/2+4);ctx.textAlign='left';}
 else if(['register','counter','fsm'].includes(n.type)){
  // FSRTL-0058 sequential label layout: bounded, centered; controls use a separate band.
  const name=String(n.name||'');const display=name.length>36?name.slice(0,35)+'…':name;
  ctx.save();ctx.beginPath();ctx.rect(x+12,y+26,Math.max(10,w-24),Math.max(12,h-49));ctx.clip();
  ctx.textAlign='center';ctx.font='600 12px system-ui,sans-serif';
  ctx.fillText(display,x+w/2,y+Math.min(42,h-29),Math.max(20,w-30));ctx.restore();
 }else{const text=n.name.length>23?n.name.slice(0,22)+'…':n.name;ctx.fillText(text,x+16,y+(n.type==='port'?29:35));}
 if(n.type==='instance'||n.type==='generate'){ctx.fillStyle=colors.muted;ctx.font='11px ui-monospace,monospace';ctx.fillText(n.type==='generate'?`${n.count} generated instances`:String(n.module||''),x+17,y+18);}
 /* Register shape conveys always_ff; avoid duplicate caption. */}
// FSRTL-0029 net-based Canvas paint
'use strict';
// Geometry-only grouping. Never join different canonical net identities.
(function(root){
 function segmentsFor(edges,paths){
  const groups=new Map();
  for(const edge of edges){
   const points=paths.get(edge.id);
   if(!points||points.length<2)continue;
   // FSRTL-0059-FIX conductor: combine drawing only for one canonical net.
   const key=JSON.stringify([edge.net||edge.id]);
   if(!groups.has(key))groups.set(key,{net:edge.net||edge.id,edges:[],segments:[]});
   const group=groups.get(key);group.edges.push(edge);
   for(let i=1;i<points.length;i++){
    const a=points[i-1],b=points[i];
    if(a[0]===b[0]&&a[1]===b[1])continue;
    // An orthogonal path should never silently produce a diagonal connection.
    if(a[0]!==b[0]&&a[1]!==b[1]){group.segments.push([a,b]);continue;}
    group.segments.push([a,b]);
   }
  }
  const output=[];
  for(const group of groups.values()){
   const axes=new Map(),diagonals=[];
   for(const [a,b] of group.segments){
    const horizontal=a[1]===b[1],vertical=a[0]===b[0];
    if(!horizontal&&!vertical){diagonals.push([a,b]);continue;}
    const fixed=horizontal?a[1]:a[0],lo=Math.min(horizontal?a[0]:a[1],horizontal?b[0]:b[1]),hi=Math.max(horizontal?a[0]:a[1],horizontal?b[0]:b[1]);
    const key=(horizontal?'H':'V')+':'+fixed;
    if(!axes.has(key))axes.set(key,{horizontal,fixed,spans:[]});
    axes.get(key).spans.push([lo,hi]);
   }
   const strokes=[...diagonals];
   for(const axis of axes.values()){
    axis.spans.sort((a,b)=>a[0]-b[0]||a[1]-b[1]);
    const merged=[];
    for(const span of axis.spans){const last=merged[merged.length-1];if(last&&span[0]<=last[1])last[1]=Math.max(last[1],span[1]);else merged.push([...span]);}
    for(const [lo,hi] of merged)strokes.push(axis.horizontal?[[lo,axis.fixed],[hi,axis.fixed]]:[[axis.fixed,lo],[axis.fixed,hi]]);
   }
   strokes.sort((a,b)=>a[0][0]-b[0][0]||a[0][1]-b[0][1]||a[1][0]-b[1][0]||a[1][1]-b[1][1]);
   output.push({...group,segments:strokes});
  }
  return output;
 }
 const api={segmentsFor};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexNetGeometry=api;
})(typeof window==='object'?window:globalThis);

'use strict';
/* Presentation-only SystemVerilog signal shape classification. Never infers connectivity. */
(function(root){
 function positiveWidth(value){
  if(Number.isSafeInteger(value)&&value>0)return value;
  if(typeof value==='string'&&/^\d+$/.test(value.trim())){const n=Number(value);return Number.isSafeInteger(n)&&n>0?n:null;}
  return null;
 }
 function hasDimension(v){return v!==undefined&&v!==null&&v!==''&&(!(Array.isArray(v))||v.length>0);}
 function classify(signal={}){
  const d=signal.dimensions||{};
  const unpacked=hasDimension(d.unpackedDimensions)||hasDimension(signal.unpackedDimensions);
  const packed=hasDimension(d.packedDimensions)||hasDimension(signal.packedDimensions);
  const width=positiveWidth(signal.bitWidth)||positiveWidth(signal.widthBits)||positiveWidth(signal.width);
  // Text like logic[7:0] is an annotation, not a safe elaborated bit-width.
  const isBus=width!==null?width>1:(packed||Boolean(signal.isVector));
  return Object.freeze({kind:unpacked?'array':isBus?'bus':'scalar',width,packed,unpacked,
   label:unpacked?'unpacked':width!==null&&width>1?String(width):packed?'packed':null,
   // A single bus conductor; *not* one strand per bit.
   strokeWidth:unpacked?3.8:isBus?3.2:1.8});
 }
 const api={classify,positiveWidth};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexSignalStyle=api;
})(typeof window==='object'?window:globalThis);

// FSRTL-0029 net-based Canvas paint. Only geometry is consolidated.
function paintNets(edges,paths,v,w,h){
 const groups=FlexNetGeometry.segmentsFor(edges,paths);
 for(const group of groups){
  const edge=group.edges[0],hot=group.edges.some(highlighted);
  ctx.lineWidth=hot?3.8:FlexSignalStyle.classify(edge).strokeWidth;
  ctx.strokeStyle=hot?colors.selected:colors.wire;
  ctx.globalAlpha=hot?1:.88;ctx.lineCap='round';ctx.lineJoin='round';
  ctx.setLineDash([]); // One conductor style; dependencies stay in edge metadata.
  for(const segment of group.segments){
   if(!wireVisible(segment,v,w,h))continue;
   pathDraw(segment);ctx.stroke();
  }
  ctx.setLineDash([]);ctx.globalAlpha=1;
  // Preserve the original per-edge direction at sink terminals only.
  ctx.fillStyle=ctx.strokeStyle;
  const paintedSinks=new Set();
  for(const e of group.edges){
   const path=paths.get(e.id);if(!path||path.length<2||!wireVisible(path,v,w,h))continue;
   const b=path[path.length-1];let a=null;
   for(let i=path.length-2;i>=0;i--)if(path[i][0]!==b[0]||path[i][1]!==b[1]){a=path[i];break;}
   if(!a)continue;
   const sinkKey=JSON.stringify([e.target,b[0],b[1]]);
   if(paintedSinks.has(sinkKey))continue;
   paintedSinks.add(sinkKey);
   const angle=Math.atan2(b[1]-a[1],b[0]-a[0]);
   ctx.beginPath();ctx.moveTo(b[0],b[1]);
   ctx.lineTo(b[0]-9*Math.cos(angle-.43),b[1]-9*Math.sin(angle-.43));
   ctx.lineTo(b[0]-9*Math.cos(angle+.43),b[1]-9*Math.sin(angle+.43));
   ctx.closePath();ctx.fill();
  }
 }
}

function draw(){if(!state.graph)return;const w=canvas.clientWidth||1,h=canvas.clientHeight||1,v=view(),d=layout(state.graph);ctx.setTransform(canvas.width/w,0,0,canvas.height/h,0,0);ctx.fillStyle=colors.canvas;ctx.fillRect(0,0,w,h);ctx.save();ctx.translate(v.x,v.y);ctx.scale(v.z,v.z);
 if(state.visibility.wires)paintNets(state.graph.edges,d.edgePaths,v,w,h);
 // A small wire bridge at crossings prevents a perpendicular intersection
 // from reading as an electrical junction. It is decoration, not connectivity.
 if(state.visibility.wires&&v.z>=.44){const netById=new Map(state.graph.edges.map(e=>[e.id,e]));
  for(const hop of d.bridges){
   if(!visible({x:hop.x-7,y:hop.y-7,w:14,h:14},v,w,h,12))continue;
   const edge=netById.get(hop.edge);ctx.lineCap='round';ctx.lineWidth=7;ctx.strokeStyle=colors.canvas;
   ctx.beginPath();ctx.moveTo(hop.x-6,hop.y);ctx.lineTo(hop.x+6,hop.y);ctx.stroke();
   ctx.lineWidth=highlighted(edge)?3.8:1.8;ctx.strokeStyle=highlighted(edge)?colors.selected:colors.wire;
   ctx.beginPath();ctx.moveTo(hop.x-7,hop.y);ctx.quadraticCurveTo(hop.x,hop.y-10,hop.x+7,hop.y);ctx.stroke();
  }
 }
 for(const n of state.graph.nodes){const p=d.positions.get(n.id);if(p&&visible(p,v,w,h))symbol(n,p,d);}
 ctx.restore();}
function pointer(ev){const r=canvas.getBoundingClientRect(),v=view();return{x:(ev.clientX-r.left-v.x)/v.z,y:(ev.clientY-r.top-v.y)/v.z};}
function distSeg(p,a,b){const dx=b[0]-a[0],dy=b[1]-a[1],l=dx*dx+dy*dy;const t=l?clamp(((p.x-a[0])*dx+(p.y-a[1])*dy)/l,0,1):0;return Math.hypot(p.x-a[0]-t*dx,p.y-a[1]-t*dy);}
function hit(p){if(!state.graph)return null;const d=layout(state.graph);for(let i=state.graph.nodes.length-1;i>=0;i--){const n=state.graph.nodes[i],r=d.positions.get(n.id);if(r&&p.x>=r.x&&p.x<=r.x+r.w&&p.y>=r.y&&p.y<=r.y+r.h)return n;}
 const radius=clamp(9/view().z,5,23);let best=null,minimum=radius;
 if(!state.visibility.wires)return null;
 for(const edge of state.graph.edges){const poly=d.edgePaths.get(edge.id);if(!poly)continue;for(let i=1;i<poly.length;i++){const dist=distSeg(p,poly[i-1],poly[i]);if(dist<minimum){minimum=dist;best=edge;}}}return best;}
let cameraAnimation=0;
const noMotion=()=>window.matchMedia?.('(prefers-reduced-motion: reduce)').matches;
function animateView(goal){
 cancelAnimationFrame(cameraAnimation);
 if(noMotion()){setView(goal);draw();return;}
 const from={...view()},start=performance.now(),duration=230;
 function frame(now){const t=clamp((now-start)/duration,0,1),ease=1-Math.pow(1-t,3);
  setView({x:from.x+(goal.x-from.x)*ease,y:from.y+(goal.y-from.y)*ease,z:from.z+(goal.z-from.z)*ease});draw();
  if(t<1)cameraAnimation=requestAnimationFrame(frame);}
 cameraAnimation=requestAnimationFrame(frame);
}
function fit(){state.manualView=false;if(!state.graph)return;const d=layout(state.graph);if(d.stats?.engine==='pending')return;const w=canvas.clientWidth,h=canvas.clientHeight,z=clamp(Math.min((w-90)/d.width,(h-105)/d.height),.13,1.35);animateView({x:(w-d.width*z)/2,y:(h-d.height*z)/2,z});$('zoomLabel').textContent=Math.round(z*100)+'%';}
function zoom(f,x=canvas.clientWidth/2,y=canvas.clientHeight/2,{immediate=false}={}){
 state.manualView=true;
 const v=view(),z=clamp(v.z*f,.12,3.5);
 const target={z,x:x-(x-v.x)*z/v.z,y:y-(y-v.y)*z/v.z};
 if(immediate){cancelAnimationFrame(cameraAnimation);setView(target);draw();}
 else animateView(target);
 $('zoomLabel').textContent=Math.round(z*100)+'%';
}
function selection(item,track=false,additive=false){if(!item)return;const edge=item.source&&item.target;const id=edge?(item.net||item.id):item.id;if(additive){if(state.multiSelected.has(id)){state.multiSelected.delete(id);if(state.selected===id)state.selected=state.multiSelected.values().next().value||null;}else{if(state.selected)state.multiSelected.add(state.selected);state.multiSelected.add(id);state.selected=id;}}else{state.multiSelected.clear();state.selected=id;}state.inspectEntityId=item.id;if(track&&id.includes('::sig:'))state.pinned=id;const label=edge?`${item.port?item.port+' · ':''}${String(item.net||item.id).split('::sig:').pop()} · ${item.type} wire`+(item.mapping==='partial'?' · bus slice (not bit-exact)':''):item.name+' · '+item.type;announce((track?'Tracking · ':'Selected · ')+label);
 if(state.inspector&&state.tab==='source'){const node=sourceSelectionNode();if(node?.line)focusLine(Number(node.line),node.name);}if(state.inspector&&['details','source','lint'].includes(state.tab))loadTab();draw();}
// Resolve signal selection by canonical identity, not by a guessed name.
function sourceSelectionNode(){
 if(!state.graph)return null;
 const ids=[state.selected,state.inspectEntityId].filter(Boolean);
 const edge=state.graph.edges.find(e=>ids.includes(e.id));
 if(edge&&edge.net)ids.unshift(edge.net);
 return state.graph.nodes.find(n=>ids.includes(n.id))||null;
}
function sourceEvidenceBanner(node){
 const banner=document.createElement('div');banner.className='source-role-evidence';
 const name=node?.name||'No AST signal selected';
 banner.textContent=node?.line
  ?`Selected: ${name} · Declaration: AST line ${node.line} · Writes: not indexed · Reads: not indexed`
  :`Selected: ${name} · Declaration / writes / reads: no verified locations for this selection`;
 return banner;
}
// Compiler-backed occurrence navigator. Never infer roles by searching source text.
let occurrenceRequest=0;
function selectedSignalName(){
 const node=sourceSelectionNode();
 if(!node || !String(node.id||'').includes('::sig:'))return null;
 return typeof node.name==='string'&&node.name?node.name:null;
}
function addOccurrenceControls(code, result, chosenFile){
 const host=document.createElement('section');host.className='source-occurrences';
 const roleStyles=document.createElement('style');
 roleStyles.textContent='.code-line.occurrence-declaration{background:rgba(74,162,235,.19);border-left:3px solid #4aa2eb}.code-line.occurrence-write{background:rgba(242,160,57,.18);border-left:3px solid #f2a039}.code-line.occurrence-read{background:rgba(63,190,124,.17);border-left:3px solid #3fbe7c}.code-line.occurrence-declaration.occurrence-write,.code-line.occurrence-write.occurrence-read{background:linear-gradient(90deg,rgba(74,162,235,.19),rgba(242,160,57,.19),rgba(63,190,124,.17))}';
 host.append(roleStyles);
 const title=document.createElement('div');title.className='source-role-evidence';
 host.append(title);
 const signal=selectedSignalName();
 if(!signal){title.textContent='Select a signal wire or signal node to inspect declarations, writes and reads.';code.prepend(host);return;}
 title.textContent='AST references for '+signal+' · loading…';code.prepend(host);
 const request=++occurrenceRequest,scope=state.path;
 api('occurrences',{path:scope,signal}).then(data=>{
  if(request!==occurrenceRequest || state.path!==scope || state.tab!=='source' || !state.inspector || !host.isConnected)return;
  host.replaceChildren(roleStyles);
  const heading=document.createElement('div');heading.className='source-role-evidence';
  heading.textContent='AST occurrences · '+signal+' · '+(data.complete?'complete':'partial evidence');host.append(heading);
  if(data.status!=='available'){
   const note=document.createElement('div');note.textContent=String(data.reason||'Source references unavailable');host.append(note);return;
  }
  // FSRTL-0052 semantic source roles: color verified AST lines, not text guesses.
  const sites=Array.isArray(data.sites)?data.sites:[];
  const sameFile=(a,b)=>{
   const clean=v=>String(v||'').replaceAll('\\','/').replace(/^\.\//,'');
   const x=clean(a),y=clean(b);
   return !!x&&!!y&&(x===y||x.endsWith('/'+y)||y.endsWith('/'+x));
  };
  const roleLines=new Map();
  for(const site of sites){
   if(!site||!['declaration','write','read'].includes(site.role)||!sameFile(site.file,chosenFile))continue;
   const line=Number(site.line);
   if(!Number.isSafeInteger(line)||line<=0)continue;
   const row=$('sourceCode').querySelector('[data-line="'+line+'"]');
   if(!row)continue;
   row.classList.add('occurrence-'+site.role);
   const prior=roleLines.get(line)||new Set();prior.add(site.role);roleLines.set(line,prior);
  }
  const summary=document.createElement('div');summary.className='source-role-evidence';
  summary.textContent='Highlighted AST source lines · declaration: '+[...roleLines.values()].filter(v=>v.has('declaration')).length+
    ' · write: '+[...roleLines.values()].filter(v=>v.has('write')).length+
    ' · read: '+[...roleLines.values()].filter(v=>v.has('read')).length+
    ' · only in '+String(chosenFile||'current file');host.append(summary);
  // AST-backed occurrence navigation: no source-text guessing.
  const valid=sites.filter(s=>s&&['declaration','write','read'].includes(s.role)&&Number.isSafeInteger(Number(s.line))&&Number(s.line)>0);
  const nav=document.createElement('nav');nav.className='fs-ast-nav';nav.setAttribute('aria-label','Signal AST references');
  let activeRole='declaration';const cursors={declaration:-1,write:-1,read:-1};
  const jump=(role,delta)=>{
   const matches=valid.filter(s=>s.role===role);
   if(!matches.length){$('inspectorFoot').textContent='No verified '+role+' references for '+signal;return;}
   cursors[role]=(cursors[role]+delta+matches.length)%matches.length;
   const site=matches[cursors[role]];activeRole=role;
   if(!sameFile(site.file,chosenFile)){
    $('inspectorFoot').textContent=role+' '+(cursors[role]+1)+'/'+matches.length+' at '+site.file+':'+site.line+' (another file; not displayed)';
   }else{focusLine(Number(site.line),signal+' · '+role+' '+(cursors[role]+1)+'/'+matches.length);}
   for(const b of nav.querySelectorAll('button[data-role]'))b.setAttribute('aria-current',String(b.dataset.role===role));
  };
  for(const [role,label] of [['declaration','Decl'],['write','Assigned'],['read','Read']]){
   const count=valid.filter(s=>s.role===role).length;
   const b=document.createElement('button');b.type='button';b.dataset.role=role;
   b.textContent=label+' ('+count+')';b.title='Next AST-verified '+role+' reference';b.disabled=!count;
   b.onclick=()=>jump(role,1);nav.append(b);
  }
  const help=document.createElement('span');help.textContent='[d / ]d · [w / ]w · [r / ]r';nav.append(help);
  host.append(nav);
  // One navigator per Source render; discarded as soon as selection changes.
  code._astNavigate=(role,delta)=>{
   if(request!==occurrenceRequest||state.path!==scope||!host.isConnected)return false;
   jump(role,delta);return true;
  };
  const labels={declaration:'Declaration',write:'Write',read:'Read'};
  for(const role of ['declaration','write','read']){
   const matching=sites.filter(s=>s && s.role===role && Number.isSafeInteger(Number(s.line)) && Number(s.line)>0);
   const row=document.createElement('div');row.className='source-occurrence-row';
   const caption=document.createElement('strong');caption.textContent=labels[role]+' ('+matching.length+') ';row.append(caption);
   if(!matching.length){row.append(document.createTextNode('No AST-backed location available'));}
   for(const site of matching){
    const button=document.createElement('button');button.type='button';button.className='source-occurrence-jump';
    button.textContent='L'+site.line;button.title=String(site.file||'')+' · '+String(site.precision||'line');
    button.onclick=()=>{
     if(request!==occurrenceRequest||state.path!==scope)return;
     // Only highlight lines of the file actually visible in this inspector.
     if(!sameFile(site.file,chosenFile)){
      $('inspectorFoot').textContent='Reference belongs to '+site.file+':'+site.line+'; current source is '+chosenFile;
      return;
     }
     focusLine(Number(site.line),signal+' · '+role);
     const line=$('sourceCode').querySelector('[data-line="'+site.line+'"]');
     if(line){line.classList.add('occurrence-'+role);}
    };row.append(button);
   }
   host.append(row);
  }
  const note=document.createElement('div');note.className='source-role-evidence';
  note.textContent=String(data.note||'Only source locations verified by the AST are shown.');host.append(note);
 }).catch(error=>{
  if(request!==occurrenceRequest||!host.isConnected)return;
  title.textContent='AST occurrences unavailable · '+error.message;
 });
}
function focusLine(line,name){const row=$('sourceCode').querySelector(`[data-line="${line}"]`);if(!row)return;$('sourceCode').querySelectorAll('.focus-line').forEach(el=>el.classList.remove('focus-line'));row.classList.add('focus-line');row.scrollIntoView({block:'center',inline:'nearest'});$('inspectorFoot').textContent='AST source line '+line+' · '+name;}
// Lint is an independent evidence layer, not a schematic connectivity edge.
// A file-level diagnostic is never attached to an arbitrary instance.
function priorityOf(d){
 const raw=String(d.priority||d.pri||'').toUpperCase();
 return ['P0','P1','P2','P3'].includes(raw)?raw:'?';
}
function lintRow(d){
 const row=document.createElement('button');row.type='button';row.className='lint-overlay-row';
 const pri=priorityOf(d),name=String(d.code||d.optionName||'warning');
 const head=document.createElement('span');head.className='lint-overlay-code';
 const badge=document.createElement('b');badge.className='lint-priority '+pri.toLowerCase();badge.textContent=pri;
 head.append(badge,document.createTextNode(' '+name));
 const message=document.createElement('span');message.className='lint-overlay-message';message.textContent=String(d.message||d.text||'');
 const where=document.createElement('span');where.className='lint-overlay-location';
 where.textContent=[d.file||'',d.line||''].filter(Boolean).join(':');
 row.append(head,message,where);
 row.onclick=()=>{
  inspector(true,'source');
  const line=Number(d.line);
  if(Number.isInteger(line)&&line>0){
   // Source loading is asynchronous: focus only after the source tab fetch.
   pendingLintLine=line;pendingLintFile=String(d.file||'');
   loadTab();
  }
 };
 return row;
}
let pendingLintLine=0;
let pendingLintFile='';
// Incremented whenever a panel request becomes obsolete.
let inspectorRequest=0;
let navigationRequest=0;
function renderLintOverlay(){
 const box=$('lintOverlayResults');box.replaceChildren();
 const filter=$('lintOverlayPriority').value;
 const matches=state.lintItems.filter(d=>filter==='all'||priorityOf(d)===filter);
 $('lintOverlayCount').textContent=matches.length+' / '+state.lintItems.length;
 if(state.lintStatus!=='available'){box.textContent='Lint report unavailable for this source';return;}
 if(!matches.length){box.textContent='No matching diagnostics';return;}
 const fragment=document.createDocumentFragment();
 for(const d of matches)fragment.append(lintRow(d));
 box.append(fragment);
}
async function loadLintOverlay(){
 const request=++state.lintRequest,path=state.path;
 try{
  const result=await api('lint',{path});
  if(request!==state.lintRequest||path!==state.path)return;
  state.lintStatus=result.status;
  state.lintItems=Array.isArray(result.diagnostics)?result.diagnostics:[];
  state.lintItems.sort((a,b)=>{
   const rank=p=>['P0','P1','P2','P3'].indexOf(priorityOf(p));
   return (rank(a)<0?4:rank(a))-(rank(b)<0?4:rank(b))||Number(a.line||0)-Number(b.line||0);
  });
  renderLintOverlay();
 }catch(error){if(request===state.lintRequest){state.lintStatus='unavailable';state.lintItems=[];renderLintOverlay();announce(error.message);}}
}
function setLintOverlay(enabled){
 state.visibility.lint=enabled;
 $('showLintOverlay').checked=enabled;
 $('lintOverlay').hidden=!enabled;
 if(enabled)loadLintOverlay();else ++state.lintRequest;
}
function nodeList(){const box=$('a11yNodes');box.replaceChildren();for(const n of state.graph.nodes){const button=document.createElement('button');button.textContent=n.name+' · '+n.type;button.onclick=()=>selection(n);box.append(button);}for(const e of state.graph.edges){const button=document.createElement('button');button.textContent='Wire · '+e.net.split('::sig:').pop()+(e.port?' → '+e.port:'');button.onclick=()=>selection(e,true);box.append(button);}}
function expandedGroups(path=state.path){return state.expanded.get(path)||new Set();}
async function fetchGraph(path){return api('diagram',{path,expand:[...expandedGroups(path)].join('|')});}
async function refreshGraph(preserve=true){
  const requestedPath=state.path, request=++navigationRequest;
  const graph=await fetchGraph(requestedPath);
  if(request!==navigationRequest||requestedPath!==state.path)return false;
  const previous=state.graph;
  state.graph=graph;
 $('viewName').textContent=state.graph.module;
 $('viewDesc').textContent='Hierarchy ' + state.path + ' · RTL connectivity';
 syncCounts();breadcrumbs();tree();nodeList();
 if(!preserve||!previous||!state.viewport.has(state.path))fit();else draw();if($('search').value)searchGraph($('search').value);
 if(state.inspector)loadTab();
  if(state.visibility.lint)await loadLintOverlay();
  return true;
}
async function navigate(path){
 try{state.path=path;++inspectorRequest;await refreshGraph(true);}
 catch(e){announce(e.message);}
}
async function toggleGroup(item){
 if(!item?.group)return;
 const group=item.group,groups=new Set(expandedGroups());
 const wasExpanded=groups.has(group);
 const before=new Set(groups);
 if(wasExpanded)groups.delete(group);else groups.add(group);
 state.expanded.set(state.path,groups);
 try{await refreshGraph(false);announce((wasExpanded?'Collapsed ':'Expanded ')+group);}
 catch(e){state.expanded.set(state.path,before);announce('Expand failed: '+e.message);}
}

function syncCounts(){const c=state.graph.connectivity||{};const unbound=c.unbound_pins||0,unknown=c.unresolved_pins||0,partial=c.partial_pins||0;$('counts').textContent=state.graph.nodes.length+' symbols · '+state.graph.edges.length+' wires'+(unbound?' · '+unbound+' unbound':'')+(unknown?' · '+unknown+' unresolved':'')+(partial?' · '+partial+' partial':'')+(state.graph.truncated?' · limited':'');}
async function enter(path,track=false){if(!path)return;let followed=null;if(state.pinned&&(track||state.pinned)){try{followed=await api('follow',{path:state.path,child:path,signal:state.pinned});}catch(e){followed={status:'unresolved',reason:e.message};}}await navigate(path);if(followed){if(followed.status==='resolved'){state.pinned=followed.signal_id;state.selected=followed.signal_id;announce('Resolved hierarchical binding → '+followed.signal);}else{state.pinned=null;announce('Signal tracking '+followed.status+' · '+(followed.reason||'Ambiguous mapping'));}}draw();}
function breadcrumbs(){
 const box=$('breadcrumb');box.replaceChildren();
 // Only *real elaborated module scopes* are clickable. Generate-array folder
 // segments are not modules; linking to those would give invalid navigation.
 const chain=state.graph.ancestors||[{path:'/',name:state.overview.top}];
 chain.forEach((scope,i)=>{
  if(i){const sep=document.createElement('span');sep.className='crumb-sep';sep.textContent='›';sep.setAttribute('aria-hidden','true');box.append(sep);}
  const button=document.createElement('button');button.textContent=scope.path==='/'?state.overview.top:scope.name;
  button.title=scope.module+' · '+scope.path;
  if(scope.path===state.path){button.setAttribute('aria-current','page');button.classList.add('current');}
  button.onclick=()=>navigate(scope.path);box.append(button);
 });
 box.lastElementChild?.scrollIntoView({inline:'nearest',block:'nearest'});
}
const lazyTree=FlexHierarchyTree.create({host:$('hierarchy'),fetchPage:(path,offset,limit)=>api('hierarchy',{path,offset,limit}),navigate:path=>navigate(path),onError:e=>announce('Hierarchy: '+e.message)});
function tree(){lazyTree.activate(state.path);}
function inspector(show=true,tab='source'){if(!show)++inspectorRequest;const changed=show!==state.inspector;state.inspector=show;$('inspector').hidden=!show;if(show)setTab(tab);syncInspectorButtons();requestAnimationFrame(()=>{resize();if(changed&&!state.manualView)fit();else draw();});}
function setTab(tab){
 state.tab=tab;
 for(const t of ['details','source','lint','cone']){
  if($(t+'Pane'))$(t+'Pane').hidden=t!==tab;
  if($(t+'Tab'))$(t+'Tab').classList.toggle('active',t===tab);
  if($(t+'Tab'))$(t+'Tab').setAttribute('aria-selected',String(t===tab));
 }
 syncInspectorButtons();
 if(state.inspector)loadTab();
}
function syncInspectorButtons(){
 for(const [id,tab] of [['toggleSource','source'],['toggleLint','lint'],['toggleCone','cone']]){
  const active=state.inspector&&state.tab===tab;
  $(id).classList.toggle('active',active);
  $(id).setAttribute('aria-pressed',String(active));
 }
}
function togglePanel(tab){
 if(state.inspector&&state.tab===tab)inspector(false);
 else inspector(true,tab);
 syncInspectorButtons();
}

async function loadTab(){
 const request=++inspectorRequest,path=state.path,tab=state.tab;
 if(!state.inspector)return;
 const selectedId=tab==='details'?(state.inspectEntityId||state.selected):state.selected;
 const current=()=>request===inspectorRequest&&path===state.path&&tab===state.tab&&state.inspector;
 const selectedCurrent=()=>current()&&selectedId===(state.inspectEntityId||state.selected);
 try{
  if(tab==='details'){
   const target=$('detailsResults');
   if(!selectedId){target.textContent='Select a schematic symbol or relation';return;}
   target.textContent='Loading compiler-backed details…';
   const result=await api('inspect',{path,id:selectedId,expand:[...expandedGroups(path)].join('|')});
   if(!selectedCurrent())return;
   if(result.status!=='available'){target.textContent='Unresolved · '+String(result.reason||'No verified entity in this graph slice');return;}
   const output=['Entity: '+result.id,'Scope: '+result.scope,'Revision: '+result.revision,'Elaboration: '+(result.elaboration_verified?'verified':'unverified'),'Kind: '+result.kind];
   if(result.entity)for(const [key,value] of Object.entries(result.entity))output.push(key+': '+(typeof value==='object'?JSON.stringify(value):String(value)));
   if(result.entity?.sequentialProfile){
    const seq=result.entity.sequentialProfile;
    output.push('SEQUENTIAL AST EVIDENCE (roles not inferred)');
    output.push('Storage: '+String(seq.kind||'unknown'));
    for(const ev of seq.events||[])output.push('Event: '+String(ev.edge)+' '+String(ev.signal));
    for(const wr of seq.writePaths||[]){
     const guards=(wr.conditions||[]).map(g=>String((g.signals||[]).join(','))+' ['+String(g.branch)+']'+(g.line?' @'+g.line:'')).join(' → ');
     output.push('Write'+(wr.line?' @'+wr.line:'')+': '+(guards||'unconditional')+'; RHS: '+(wr.rhsSignals||[]).join(',')+(wr.constantCandidate?' [constant candidate]':''));
    }
    output.push('Reset/enable/load/priority: not classified; no pin roles inferred from names');
   }
   if(result.relationship)output.push('Relationship: '+JSON.stringify(result.relationship));
   if(result.source?.status==='available')output.push('Source: '+result.source.file+':'+result.source.line+' ('+result.source.provenance+')');
   else if(result.source)output.push('Source: unresolved · '+String(result.source.reason||''));
   for(const relation of result.relationships||[])output.push('Dependency: '+relation.source+' → '+relation.target+' ['+relation.type+', '+relation.mapping+']');
   if(result.relationships_truncated)output.push('Relationships: truncated');
   output.push('Limitations: '+String(result.limitations||'unknown'));
   target.textContent=output.join('\n');
  }else if(tab==='source'){
   const result=await api('source',{path});
   if(!current())return;
   $('sourceFile').textContent=result.status==='available'?result.file:'Source not mapped';
   const code=$('sourceCode');delete code._astNavigate;code.replaceChildren();$('lineNumbers').textContent='';const selectedNode=sourceSelectionNode();code.append(sourceEvidenceBanner(selectedNode));addOccurrenceControls(code,result,result.file);
   if(result.code){
    const fragment=document.createDocumentFragment();
    result.code.split('\n').forEach((line,i)=>{const span=document.createElement('span');span.className='code-line';span.dataset.line=String(i+1);span.textContent=line||' ';fragment.append(span);});
    code.append(fragment);$('lineNumbers').textContent=result.code.split('\n').map((_,i)=>i+1).join('\n');
   }else {const note=document.createElement('div');note.textContent=result.reason||'No source location';code.append(note);}
   $('inspectorFoot').textContent=result.status==='available'?'Click a source line to focus an AST symbol':'Source reference unavailable';
   if(selectedNode?.line)focusLine(selectedNode.line,selectedNode.name);
   if(pendingLintLine){
    const targetFile=String(pendingLintFile||'').replaceAll('\\','/');
    const currentFile=String(result.file||'').replaceAll('\\','/');
    const exactFile=!!targetFile&&!!currentFile&&(targetFile===currentFile||targetFile.endsWith('/'+currentFile)||currentFile.endsWith('/'+targetFile));
    if(exactFile&&result.status==='available')focusLine(pendingLintLine,'lint diagnostic');
    else $('inspectorFoot').textContent='Lint location not highlighted: diagnostic file '+(targetFile||'unknown')+' differs from source '+(currentFile||'unavailable');
    pendingLintLine=0;pendingLintFile='';
   }
  }else if(tab==='lint'){
   const box=$('lintResults');box.replaceChildren();
   const loading=document.createElement('p');loading.textContent='Loading lint for scope '+path+'…';box.append(loading);
   // Scope is the selected elaborated module; lint evidence itself is file-level.
   const [result,evidence]=await Promise.all([api('lint',{path}),api('evidence')]);
   if(!current())return;
   box.replaceChildren();
   const heading=document.createElement('div');heading.className='source-head';
   const moduleName=state.graph?.module||'module unavailable';
   heading.textContent='RTL scope: '+path+' · module: '+moduleName;
   box.append(heading);
   const provenance=document.createElement('p');provenance.className='source-role-evidence';
   const file=result.file?String(result.file):'source file not resolved';
   provenance.textContent='Lint file: '+file+' · '+String(result.scope||'file-level evidence; not attributed to one elaborated instance');
   box.append(provenance);
   const summary=document.createElement('p');summary.className='source-head';
   summary.textContent=evidence.status==='available'
    ?'Run evidence: Slang · '+evidence.total+' diagnostics across '+evidence.source_files+' files'
    :'Run evidence: '+String(evidence.status||'unavailable');
   box.append(summary);
   if(result.status!=='available'){
    const warning=document.createElement('p');warning.textContent='Lint unavailable for this scope: '+String(result.reason||result.status||'no report');box.append(warning);return;
   }
   const diagnostics=Array.isArray(result.diagnostics)?result.diagnostics:[];
   if(!diagnostics.length){const empty=document.createElement('p');empty.textContent='No diagnostics reported for this module source file. This does not mean that a dedicated per-instance lint run was performed.';box.append(empty);return;}
   const types=[...new Set(diagnostics.map(w=>String(w.severity||'unknown').toLowerCase()))].sort();
   const tools=document.createElement('div');tools.className='lint-filter-bar';
   const label=document.createElement('label');label.textContent='Severity: ';
   const selector=document.createElement('select');selector.setAttribute('aria-label','Filter lint severity');
   const all=document.createElement('option');all.value='all';all.textContent='All ('+diagnostics.length+')';selector.append(all);
   for(const severity of types){const option=document.createElement('option');option.value=severity;option.textContent=severity+' ('+diagnostics.filter(d=>String(d.severity||'unknown').toLowerCase()===severity).length+')';selector.append(option);}
   label.append(selector);tools.append(label);box.append(tools);
   const list=document.createElement('div');box.append(list);
   const render=()=>{
    list.replaceChildren();
    for(const warning of diagnostics){
     const severity=String(warning.severity||'unknown').toLowerCase();
     if(selector.value!=='all'&&selector.value!==severity)continue;
     const article=document.createElement('article');article.className='lint-entry';
     const code=document.createElement('code');code.textContent=severity+' · '+String(warning.code||'diagnostic');
     const message=document.createElement('span');message.textContent=' '+String(warning.message||warning.text||'No diagnostic message');
     article.append(code,message);
     const line=Number(warning.line||warning.start_line||warning.location?.line||0);
     if(Number.isSafeInteger(line)&&line>0){
      const jump=document.createElement('button');jump.type='button';jump.textContent='Open source · L'+line;
      jump.onclick=()=>{if(!current())return;pendingLintLine=line;pendingLintFile=String(warning.file||result.file||'');setTab('source');};
      article.append(document.createTextNode(' '),jump);
     }else{
      const note=document.createElement('small');note.textContent=' · no verified line';article.append(note);
     }
     list.append(article);
    }
   };
   selector.addEventListener('change',render);render();
  }else if(tab==='cone'){
   if(!current()||!state.graph)return;
   const list=state.graph.nodes.filter(n=>['port','register','counter','fsm','signal','operator'].includes(n.type));
   for(const name of ['fromSelect','toSelect']){const el=$(name),previous=el.value;el.replaceChildren();for(const n of list){const opt=document.createElement('option');opt.value=n.id;opt.textContent=n.name;el.append(opt);}if(list.some(n=>n.id===previous))el.value=previous;}
  }
 }catch(e){if(current())announce(e.message);}
}
function context(ev,item){
 ev.preventDefault();
 state.context=item;
 if(item)selection(item);
 const box=$('context'),r=$('schematic').getBoundingClientRect();
 $('contextTitle').textContent=item ? (item.source ? 'WIRE · '+item.net.split('::sig:').pop() + (item.mapping==='partial'?' · partial slice':'') : item.type.toUpperCase()+' · '+item.name) : 'MODULE · '+state.graph.module;
 $('contextEnter').hidden=!item?.child;
 $('contextPin').hidden=!(item?.net||isSignal(item));
 $('contextGenerate').hidden=!item?.group;
 if(item?.group)$('contextGenerate').firstChild.textContent=item.type==='generate'?'Expand instances ':'Collapse instances ';
 box.hidden=false;
 box.style.left=clamp(ev.clientX-r.left,5,Math.max(5,r.width-245))+'px';
 box.style.top=clamp(ev.clientY-r.top,5,Math.max(5,r.height-245))+'px';
}

canvas.addEventListener('contextmenu',ev=>context(ev,hit(pointer(ev))));
canvas.addEventListener('pointerdown',ev=>{if(ev.button!==0)return;const item=hit(pointer(ev));state.drag={x:ev.clientX,y:ev.clientY,origin:{...view()},item,moved:false};canvas.setPointerCapture(ev.pointerId);});
canvas.addEventListener('pointermove',ev=>{const d=state.drag;if(d){const dx=ev.clientX-d.x,dy=ev.clientY-d.y;if(Math.abs(dx)+Math.abs(dy)>5)d.moved=true;if(d.moved){state.manualView=true;cancelAnimationFrame(cameraAnimation);setView({...d.origin,x:d.origin.x+dx,y:d.origin.y+dy});draw();}return;}const item=hit(pointer(ev));if(item?.id!==state.hover?.id){state.hover=item;canvas.style.cursor=item?'pointer':'grab';canvas.title=item?.source?`Wire ${String(item.net||item.id).split('::sig:').pop()} ${item.port||''} · ${item.mapping==='partial'?'partial bus dependency': 'direct mapping'}`:(item?.name||'')+(item?.width?' · '+item.width:'')+(item?.dimensions?.unpackedDimensions?' · unpacked '+JSON.stringify(item.dimensions.unpackedDimensions):'');draw();}});
let lastScopeClick=null;
canvas.addEventListener('pointerup',ev=>{const d=state.drag;state.drag=null;if(!d||d.moved)return;if(d.item?.child && ev.button===0 && lastScopeClick && lastScopeClick.id===d.item.id && performance.now()-lastScopeClick.at<450){lastScopeClick=null;enter(d.item.child);return;}lastScopeClick=d.item?.child?{id:d.item.id,at:performance.now()}:null;if(d.item)selection(d.item,false,ev.ctrlKey||ev.metaKey);else if(!(ev.ctrlKey||ev.metaKey)){state.selected=null;state.multiSelected.clear();state.inspectEntityId=null;if(state.inspector&&state.tab==='details')loadTab();draw();}});
canvas.addEventListener('dblclick',ev=>{const item=hit(pointer(ev));if(item?.child)enter(item.child);});
// Normalize line / page wheel units and use continuous, pointer-anchored zoom.
// Never restart the 230 ms camera animation for each wheel event.
canvas.addEventListener('wheel',ev=>{
 ev.preventDefault();
 const unit=ev.deltaMode===1?16:ev.deltaMode===2?canvas.clientHeight:1;
 const dx=ev.deltaX*unit,dy=ev.deltaY*unit;
 if(ev.shiftKey){
  cancelAnimationFrame(cameraAnimation);
  const v=view();state.manualView=true;
  setView({...v,x:v.x-dy,y:v.y-dx});draw();return;
 }
 const rect=canvas.getBoundingClientRect();
 zoom(Math.exp(-clamp(dy,-600,600)*0.0015),ev.clientX-rect.left,ev.clientY-rect.top,{immediate:true});
},{passive:false});
$('showLintOverlay').addEventListener('change',ev=>setLintOverlay(ev.target.checked));
$('closeLintOverlay').onclick=()=>setLintOverlay(false);
$('lintOverlayPriority').addEventListener('change',renderLintOverlay);
for(const [control,layer] of [['showWires','wires'],['showNames','names']]){
 $(control).addEventListener('change',ev=>{
  state.visibility[layer]=ev.target.checked;
  draw();
 });
}
canvas.addEventListener('keydown',ev=>{if(ev.key==='Escape'){state.selected=state.pinned=null;state.multiSelected.clear();$('context').hidden=true;draw();}
 if(ev.key==='ContextMenu'||(ev.shiftKey&&ev.key==='F10')){
  const item=[...state.graph.nodes,...state.graph.edges].find(n=>n.id===state.selected||n.net===state.selected);
  const r=canvas.getBoundingClientRect();
  context({preventDefault(){},clientX:r.left+r.width/2,clientY:r.top+Math.min(r.height/2,180)},item);
  $('context').querySelector('button:not([hidden])')?.focus();
 }
 if(ev.key==='+'||ev.key==='=')zoom(1.1);if(ev.key==='-')zoom(.9);});
$('contextGenerate').onclick=async()=>{$('context').hidden=true;await toggleGroup(state.context);};
$('contextSource').onclick=async()=>{$('context').hidden=true;if(state.context?.child)await enter(state.context.child);inspector(true,'source');};
$('contextLint').onclick=async()=>{$('context').hidden=true;if(state.context?.child)await enter(state.context.child);inspector(true,'lint');};
$('contextEnter').onclick=()=>{$('context').hidden=true;if(state.context?.child)enter(state.context.child);};
$('contextPin').onclick=()=>{$('context').hidden=true;selection(state.context,true);};
document.addEventListener('click',ev=>{if(!ev.target.closest('#context')&&!ev.target.closest('#diagram'))$('context').hidden=true;if(!ev.target.closest('.search-box')&&!ev.target.closest('#searchResults'))$('searchResults').hidden=true;});
$('toggleSource').onclick=()=>togglePanel('source');$('toggleLint').onclick=()=>togglePanel('lint');$('toggleCone').onclick=()=>togglePanel('cone');$('closeInspector').onclick=()=>inspector(false);

$('zoomOut').onclick=()=>zoom(.82);$('zoomIn').onclick=()=>zoom(1.2);$('fit').onclick=fit;
for(const t of ['details','source','lint','cone']){
 const tab=$(t+'Tab');
 if(tab)tab.onclick=()=>setTab(t);
 else console.warn('[FlexSoC RTL] Missing tab:',t+'Tab');
}
// Cross-probing only uses compiler-backed source locations, never a line-number guess.
let sourceProbeRequest=0;
$('sourceCode').onclick=async ev=>{
 const row=ev.target.closest('[data-line]');if(!row||!state.graph)return;
 const line=Number(row.dataset.line),path=state.path,request=++sourceProbeRequest;
 try{
  const result=await api('source_symbols',{path,line});
  if(request!==sourceProbeRequest||path!==state.path||!state.inspector||state.tab!=='source')return;
  const candidates=Array.isArray(result.candidates)?result.candidates:[];
  if(result.status!=='resolved'||candidates.length!==1){
   announce('Line '+line+' · '+(result.status==='ambiguous'?candidates.length+' AST declarations; select a symbol in the schematic':'no uniquely verified AST declaration'));
   return;
  }
  const candidate=candidates[0];
  const matches=state.graph.nodes.filter(n=>n.id===candidate.id);
  if(matches.length!==1){announce('Line '+line+' · AST symbol is outside the current diagram slice');return;}
  selection(matches[0]);focusLine(line,matches[0].name);
 }catch(error){if(request===sourceProbeRequest&&path===state.path)announce('AST cross-probe unavailable · '+error.message);}
};
let coneRequest=0;
$('runCone').onclick=async()=>{const request=++coneRequest,path=state.path;try{const r=await api('cone',{path,from:$('fromSelect').value,to:$('toSelect').value});if(request!==coneRequest||path!==state.path)return;$('coneResults').textContent=r.status+' · '+r.paths.length+' path(s)\n'+(r.paths.map(p=>p.map(id=>id.split('::').pop()).join(' → ')).join('\n')||r.reason||'No proven path')+'\nSequential boundaries: '+JSON.stringify(r.sequential_boundaries||[]);if(r.paths.length){state.selected=r.paths[0][0];draw();}}catch(e){if(request===coneRequest&&path===state.path)announce(e.message);}};
function focusSymbol(item){
 if(!item)return;
 selection(item);
 const node=item.source?state.graph.nodes.find(n=>n.id===item.source):item;
 const box=layout(state.graph).positions.get(node?.id);
 if(box){const v=view();setView({...v,x:canvas.clientWidth*.5-(box.x+box.w/2)*v.z,y:canvas.clientHeight*.48-(box.y+box.h/2)*v.z});draw();}
 $('searchResults').hidden=true;
}
function searchGraph(query){
 const panel=$('searchResults');panel.replaceChildren();
 const q=query.trim().toLocaleLowerCase();
 if(!q){panel.hidden=true;return;}
 const items=[...state.graph.nodes,...state.graph.edges].filter(n=>(n.name||n.net?.split('::sig:').pop()||'').toLocaleLowerCase().includes(q)).slice(0,18);
 for(const item of items){
  const button=document.createElement('button');
  const label=item.name||item.net.split('::sig:').pop();
  button.textContent=label+'   '+(item.type||'wire');
  button.onclick=()=>{focusSymbol(item);$('search').value=label;};
  panel.append(button);
 }
 if(!items.length){const empty=document.createElement('p');empty.textContent='No symbol in this module';panel.append(empty);}
 panel.hidden=false;
}
$('search').addEventListener('input',ev=>searchGraph(ev.target.value));
$('search').addEventListener('keydown',ev=>{
 if(ev.key==='Escape'){$('searchResults').hidden=true;$('search').blur();}
 if(ev.key==='Enter'){const first=$('searchResults').querySelector('button');if(first){ev.preventDefault();first.click();}}
});
document.addEventListener('keydown',ev=>{
 if(ev.key==='/'&&!ev.altKey&&!ev.ctrlKey&&!ev.metaKey&&!['INPUT','TEXTAREA','SELECT'].includes(document.activeElement.tagName)){
  ev.preventDefault();$('search').focus();
 }
 if(ev.key==='Escape'){$('context').hidden=true;$('searchResults').hidden=true;}
});
// Inspector width is local UI state; resizing never reruns layout or recompiles Slang.
let split=null;
$('inspectorResizer').addEventListener('pointerdown',ev=>{
 if(ev.button!==0)return;
 split={start:ev.clientX,width:$('inspector').getBoundingClientRect().width};
 $('inspectorResizer').setPointerCapture(ev.pointerId);
});
$('inspectorResizer').addEventListener('pointermove',ev=>{
 if(!split)return;
 const width=clamp(split.width+split.start-ev.clientX,300,Math.min(window.innerWidth*.72,900));
 $('inspector').style.width=width+'px';
});
$('inspectorResizer').addEventListener('pointerup',()=>{split=null;});
$('inspectorResizer').addEventListener('keydown',ev=>{
 if(!['ArrowLeft','ArrowRight'].includes(ev.key))return;
 ev.preventDefault();const width=$('inspector').getBoundingClientRect().width;
 $('inspector').style.width=clamp(width+(ev.key==='ArrowLeft'?24:-24),300,900)+'px';
});
$('themeToggle').onclick=()=>applyTheme(document.documentElement.dataset.theme==='light'?'dark':'light');
try{applyTheme(localStorage.getItem('flexsoc-rtl-theme')||'dark');}catch(_e){applyTheme('dark');}
$('help').onclick=()=>$('helpDialog').showModal();$('closeHelp').onclick=()=>$('helpDialog').close();
api('overview').then(async data=>{state.overview=data;lazyTree.activate('/');$('topLabel').textContent=data.top;$('stats').textContent=data.instances+' elaborated scopes · '+data.modules+' modules';$('status').textContent=data.source==='Slang verified'?'● SLANG VERIFIED':'◌ IMPORTED AST';await navigate('/');}).catch(e=>{$('status').textContent='ERROR';announce(e.message);});

// ELK is opt-in only when a local vendored runtime is actually available.
enableLocalELK();

// FSRTL-0072: copyable inspector and an opt-in, keyboard-only Vim navigation.
// Does not intercept browser shortcuts outside a focused Source pane.
(function(){
 const source=document.getElementById('sourceCode');
 const copy=document.getElementById('rtlCopyPane');
 const toggle=document.getElementById('rtlVimToggle');
 if(!source||!copy||!toggle)return;
 let vim=false,pendingG=false,pendingY=false,searchText='',searchIndex=-1;
 const report=document.getElementById('inspectorFoot');
 const lines=()=>Array.from(source.querySelectorAll('.code-line'));
 const current=()=>{const all=lines();const i=all.findIndex(x=>x.classList.contains('focus-line'));return Math.max(0,i);};
 const go=index=>{const all=lines();if(!all.length)return;const i=Math.max(0,Math.min(all.length-1,index));
  all.forEach(el=>el.classList.remove('focus-line'));all[i].classList.add('focus-line');all[i].scrollIntoView({block:'center'});
  if(report)report.textContent='Vim navigation · line '+(i+1)+'/'+all.length+' · press y to copy line';
 };
 toggle.addEventListener('click',()=>{vim=!vim;pendingG=false;toggle.textContent='Vim: '+(vim?'on':'off');toggle.setAttribute('aria-pressed',String(vim));if(vim)source.focus();});
 copy.addEventListener('click',async()=>{
  const pane=document.querySelector('#inspector .pane:not([hidden])');
  const selected=window.getSelection()?.toString()||'';
  const content=selected||(pane?.id==='sourcePane'?lines().map(el=>el.textContent).join('\n'):pane?.innerText||'');
  try{await navigator.clipboard.writeText(content);if(report)report.textContent='Copied '+(selected?'selection':'inspector content');}
  catch(error){if(report)report.textContent='Copy blocked: select text and press Ctrl+C';}
 });
 // FSRTL-0091-FIX: AST keyboard navigation, preserving existing Vim bindings.
 let pendingAstBracket='';
 source.addEventListener('keydown',event=>{
  if(vim&&!event.ctrlKey&&!event.altKey&&!event.metaKey){
   if(pendingAstBracket){
    const delta=pendingAstBracket===']'?1:-1;
    pendingAstBracket='';
    const role={d:'declaration',w:'write',r:'read'}[event.key];
    if(role&&typeof source._astNavigate==='function'){
     source._astNavigate(role,delta);event.preventDefault();return;
    }
   }
   if(event.key===']'||event.key==='['){pendingAstBracket=event.key;event.preventDefault();return;}
  }else pendingAstBracket='';
  if(!vim||event.altKey||event.metaKey)return;
  if(event.ctrlKey){if(event.key.toLowerCase()==='d'){go(current()+Math.max(1,Math.floor(source.clientHeight/40)));event.preventDefault();}else if(event.key.toLowerCase()==='u'){go(current()-Math.max(1,Math.floor(source.clientHeight/40)));event.preventDefault();}return;}
  let handled=true;
  switch(event.key){
   case 'j':go(current()+1);break;case 'k':go(current()-1);break;
   case 'g':if(pendingG){go(0);pendingG=false;}else pendingG=true;break;
   case 'G':go(lines().length-1);break;
   case 'y':{const l=lines()[current()];if(l)navigator.clipboard?.writeText(l.textContent).then(()=>{if(report)report.textContent='Copied source line '+(current()+1);}).catch(()=>{});break;}
   case 'n':case 'N':{if(searchText){const all=lines(),step=event.key==='n'?1:-1;for(let i=1;i<=all.length;i++){const idx=(current()+step*i+all.length*i)%all.length;if(all[idx].textContent.toLowerCase().includes(searchText)){go(idx);break;}}}break;}
   case '/':{const q=prompt('Find in RTL source',searchText);if(q!==null){searchText=q.toLowerCase();const idx=lines().findIndex((row,i)=>i>=current()&&row.textContent.toLowerCase().includes(searchText));if(idx>=0)go(idx);}break;}
   case 'Escape':pendingG=false;break;
   default:handled=false;pendingG=false;
  }
  if(handled)event.preventDefault();
 });
})();

// Copy the current ELK diagnostic without needing a DevTools screenshot.
(function(){
 const status=document.getElementById('layoutEngineStatus');if(!status)return;
 status.title='Click to copy layout status';status.classList.add('rtl-copy-layout-status');
 status.addEventListener('click',()=>{
  if(navigator.clipboard?.writeText){navigator.clipboard.writeText(status.textContent).catch(()=>{});}
 });
})();
