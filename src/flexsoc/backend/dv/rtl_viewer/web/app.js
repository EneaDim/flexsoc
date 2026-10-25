'use strict';
const $ = id => document.getElementById(id);
const canvas = $('diagram'), ctx = canvas.getContext('2d', {alpha:false});
const state = {overview:null,graph:null,path:'/',expanded:new Map(),viewport:new Map(),layouts:new Map(),selected:null,pinned:null,hover:null,drag:null,inspector:false,tab:'source',context:null,wire:null,manualView:false,visibility:{wires:true,names:true,lint:false},lintItems:[],lintStatus:"unavailable",lintRequest:0};
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
const boxSize=FlexRouting.boxSize,baseRank=FlexRouting.baseRank;
const layoutEngine=FlexLayoutEngine.create({fallback:FlexRouting,boxSize,baseRank});
function layout(graph){
 const id=graph.path+':'+(graph.expanded||[]).join('|')+':'+graph.revision;
 if(state.layouts.has(id))return state.layouts.get(id);
 const result=layoutEngine.compute(graph);
 state.layouts.set(id,result);
 if(state.layouts.size>80)state.layouts.delete(state.layouts.keys().next().value);
 return result;
}
function round(x,y,w,h,r){ctx.beginPath();ctx.roundRect(x,y,w,h,r);}
function visible(p,v,w,h,margin=60){return(p.x+p.w)*v.z+v.x>=-margin&&p.x*v.z+v.x<=w+margin&&(p.y+p.h)*v.z+v.y>=-margin&&p.y*v.z+v.y<=h+margin;}
function wireVisible(points,v,w,h){const xs=points.map(p=>p[0]),ys=points.map(p=>p[1]);return visible({x:Math.min(...xs),y:Math.min(...ys),w:Math.max(...xs)-Math.min(...xs),h:Math.max(...ys)-Math.min(...ys)},v,w,h);}
function highlighted(e){return state.hover?.id===e.id||state.selected===e.id||state.selected===e.net||state.pinned===e.net;}
function pathDraw(points){ctx.beginPath();points.forEach(([x,y],i)=>i?ctx.lineTo(x,y):ctx.moveTo(x,y));}
function drawWire(e,points,v){
 const hot=highlighted(e),partial=e.mapping==='partial';
 ctx.lineWidth=hot?3.8:e.width?.includes('[')?2.6:1.8;
 ctx.strokeStyle=hot?colors.selected:['sequential','event'].includes(e.type)?colors.sequential:e.type.startsWith('port')?colors.binding:colors.wire;
 ctx.globalAlpha=hot?1:.88;ctx.lineJoin='round';ctx.lineCap='round';
 ctx.setLineDash(partial?[3,5]:e.type==='event'?[2,6]:e.type==='sequential'?[7,4]:[]);
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
  ctx.fillText(label.slice(0,83),points[1][0]+5,points[1][1]-9);
 }
}
function symbol(n,p,diagram){const {x,y,w,h}=p,c=colors[n.type]||colors.signal;let picked=state.selected===n.id||state.pinned===n.id||state.hover?.id===n.id;
 ctx.lineWidth=picked?2.9:1.6;ctx.strokeStyle=picked?colors.selected:c;ctx.fillStyle=picked?colors.pickedFill:colors.symbolFill;
 if(n.type==='signal'){
  ctx.lineWidth=picked?3.5:2;ctx.beginPath();ctx.moveTo(x+8,y+h/2);ctx.lineTo(x+w-8,y+h/2);ctx.stroke();ctx.fillStyle=c;ctx.beginPath();ctx.arc(x+w/2,y+h/2,5,0,Math.PI*2);ctx.fill();
  if(view().z>=.43){ctx.font='12px ui-monospace,monospace';ctx.fillStyle=colors.text;ctx.fillText(n.name.slice(0,21),x+8,y+11);if(view().z>=.7){ctx.font='9px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   const packed=n.dimensions?.packedDimensions,unpacked=n.dimensions?.unpackedDimensions;
   const shape=unpacked?'unpacked '+JSON.stringify(unpacked):packed?'packed '+JSON.stringify(packed):n.width||'';
   if(shape)ctx.fillText(String(shape).slice(0,26),x+9,y+h-3);
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
   ctx.fillText('S',x+w/2+7,y+h-7);
  }else if(n.shape==='arith'){
   ctx.beginPath();ctx.moveTo(x+7,y+8);ctx.lineTo(x+w-9,y+8);ctx.lineTo(x+w-18,y+h/2);ctx.lineTo(x+w-9,y+h-8);ctx.lineTo(x+7,y+h-8);ctx.lineTo(x+16,y+h/2);ctx.closePath();ctx.fill();ctx.stroke();
   for(const role of ['A','B']){
    const p=FlexRouting.pinGeometry(n,{x,y,w,h},role,'in');
    ctx.beginPath();ctx.moveTo(p.x-12,p.y);ctx.lineTo(p.x+3,p.y);ctx.stroke();
    ctx.font='9px ui-monospace,monospace';ctx.fillStyle=colors.muted;ctx.fillText(role,p.x+5,p.y-4);
   }
   const out=FlexRouting.pinGeometry(n,{x,y,w,h},'Y','out');
   ctx.beginPath();ctx.moveTo(out.x-5,out.y);ctx.lineTo(out.x+7,out.y);ctx.stroke();
  }else if(['case','encoder','decoder'].includes(n.shape)){
   // Case-dispatch symbol; ENC/DEC shapes require explicit semantic metadata,
   // never merely a textual match against the module or signal name.
   round(x+7,y+9,w-14,h-18,9);ctx.fill();ctx.stroke();
   ctx.strokeStyle=colors.muted;ctx.beginPath();
   for(let i=0;i<3;i++){ctx.moveTo(x+1,y+21+i*15);ctx.lineTo(x+8,y+21+i*15);}
   ctx.moveTo(x+w-7,y+h/2);ctx.lineTo(x+w,y+h/2);ctx.stroke();
  }else{ctx.beginPath();ctx.moveTo(x+w/2,y+4);ctx.lineTo(x+w-4,y+h/2);ctx.lineTo(x+w/2,y+h-4);ctx.lineTo(x+4,y+h/2);ctx.closePath();ctx.fill();ctx.stroke();}}
 else if(['register','counter','fsm'].includes(n.type)){
  round(x+4,y+3,w-8,h-6,5);ctx.fill();ctx.stroke();ctx.beginPath();ctx.moveTo(x+4,y+h-19);ctx.lineTo(x+15,y+h-13);ctx.lineTo(x+4,y+h-7);ctx.stroke();
  ctx.fillStyle=colors.register;ctx.font='10px ui-monospace,monospace';ctx.fillText('D',x+10,y+16);ctx.fillText('Q',x+w-23,y+16);ctx.fillText('CLK',x+22,y+h-11);ctx.fillText('EVT',x+10,y+h-28);if(n.type==='counter'){ctx.fillText('↻',x+w-29,y+h-11);}if(n.type==='fsm')ctx.fillText('ST',x+w-28,y+h-11);}
 else{
  if(n.type==='generate'){for(let i=2;i>=1;i--){ctx.fillStyle=colors.stackFill;round(x+i*6,y+i*7,w-4,h-4,6);ctx.fill();ctx.strokeStyle=colors.stackStroke;ctx.stroke();}ctx.strokeStyle=picked?colors.selected:c;ctx.fillStyle=colors.symbolFill;}
  round(x,y,w-12,h-12,5);ctx.fill();ctx.stroke();ctx.strokeRect(x+7,y+7,w-26,h-26);
  for(const dir of ['in','out']){const ports=(n.ports||[]).filter(p=>dir==='in'?['in','input'].includes(p.direction):['out','output'].includes(p.direction));ports.forEach((port,i)=>{const py=y+(dir==='out'?65:53)+i*19,left=(diagram.portFaces.get(n.id+'::'+port.name)||dir)==='left'||(!diagram.portFaces.has(n.id+'::'+port.name)&&dir==='in');ctx.strokeStyle=['unbound','unresolved'].includes(port.connection)?colors.generate:port.connection==='partial'?colors.sequential:colors.instance;
   const px=left?x-7:x+w-6;
   ctx.beginPath();ctx.moveTo(left?x-7:x+w-20,py);ctx.lineTo(left?x+8:x+w-6,py);ctx.stroke();
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
 ctx.font=n.type==='operator'?'bold 12px ui-monospace,monospace':'600 13px system-ui,sans-serif';ctx.fillStyle=colors.text;
 if(n.type==='operator'){ctx.textAlign='center';ctx.fillText((n.shape==='mux'?'MUX':n.shape==='case'?'CASE':n.shape==='encoder'?'ENC':n.shape==='decoder'?'DEC':String(n.name)).slice(0,9),x+w/2,y+h/2+5);ctx.textAlign='left';}
 else{const text=n.name.length>23?n.name.slice(0,22)+'…':n.name;ctx.fillText(text,x+16,y+(['register','counter','fsm'].includes(n.type)?36:n.type==='port'?29:35));}
 if(n.type==='instance'||n.type==='generate'){ctx.fillStyle=colors.muted;ctx.font='11px ui-monospace,monospace';ctx.fillText(n.type==='generate'?`${n.count} generated instances`:String(n.module||''),x+17,y+18);}
 if(['register','counter','fsm'].includes(n.type)){ctx.fillStyle=colors.register;ctx.font='10px ui-monospace,monospace';ctx.fillText('always_ff',x+16,y+53);}}
function draw(){if(!state.graph)return;const w=canvas.clientWidth||1,h=canvas.clientHeight||1,v=view(),d=layout(state.graph);ctx.setTransform(canvas.width/w,0,0,canvas.height/h,0,0);ctx.fillStyle=colors.canvas;ctx.fillRect(0,0,w,h);ctx.save();ctx.translate(v.x,v.y);ctx.scale(v.z,v.z);
 if(state.visibility.wires)for(const e of state.graph.edges){const path=d.edgePaths.get(e.id);if(path&&wireVisible(path,v,w,h))drawWire(e,path,v);}
 // A small wire bridge at crossings prevents a perpendicular intersection
 // from reading as an electrical junction. It is decoration, not connectivity.
 if(state.visibility.wires&&v.z>=.44){const netById=new Map(state.graph.edges.map(e=>[e.id,e]));
  for(const hop of d.bridges){
   if(!visible({x:hop.x-7,y:hop.y-7,w:14,h:14},v,w,h,12))continue;
   const edge=netById.get(hop.edge);ctx.lineCap='round';ctx.lineWidth=7;ctx.strokeStyle=colors.canvas;
   ctx.beginPath();ctx.moveTo(hop.x-6,hop.y);ctx.lineTo(hop.x+6,hop.y);ctx.stroke();
   ctx.lineWidth=highlighted(edge)?3.8:1.8;ctx.strokeStyle=highlighted(edge)?colors.selected:edge.type==='sequential'?colors.sequential:edge.type.startsWith('port')?colors.binding:colors.wire;
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
function fit(){state.manualView=false;if(!state.graph)return;const d=layout(state.graph),w=canvas.clientWidth,h=canvas.clientHeight,z=clamp(Math.min((w-90)/d.width,(h-105)/d.height),.13,1.35);animateView({x:(w-d.width*z)/2,y:(h-d.height*z)/2,z});$('zoomLabel').textContent=Math.round(z*100)+'%';}
function zoom(f,x=canvas.clientWidth/2,y=canvas.clientHeight/2,{immediate=false}={}){
 state.manualView=true;
 const v=view(),z=clamp(v.z*f,.12,3.5);
 const target={z,x:x-(x-v.x)*z/v.z,y:y-(y-v.y)*z/v.z};
 if(immediate){cancelAnimationFrame(cameraAnimation);setView(target);draw();}
 else animateView(target);
 $('zoomLabel').textContent=Math.round(z*100)+'%';
}
function selection(item,track=false){if(!item)return;const edge=item.source&&item.target;const id=edge?(item.net||item.id):item.id;state.selected=id;if(track&&id.includes('::sig:'))state.pinned=id;const label=edge?`${item.port?item.port+' · ':''}${item.net.split('::sig:').pop()} · ${item.type} wire`+(item.mapping==='partial'?' · bus slice (not bit-exact)':''):item.name+' · '+item.type;announce((track?'Tracking · ':'Selected · ')+label);
 if(state.inspector&&state.tab==='source'){const node=edge?state.graph.nodes.find(n=>n.id===item.net):item;if(node?.line)focusLine(Number(node.line),node.name);}draw();}
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
   pendingLintLine=line;
   loadTab();
  }
 };
 return row;
}
let pendingLintLine=0;
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
 const previous=state.graph;
 state.graph=await fetchGraph(state.path);
 $('viewName').textContent=state.graph.module;
 $('viewDesc').textContent='Hierarchy ' + state.path + ' · RTL connectivity';
 syncCounts();breadcrumbs();tree();nodeList();
 if(!preserve||!previous||!state.viewport.has(state.path))fit();else draw();if($('search').value)searchGraph($('search').value);
 if(state.inspector)loadTab();
 if(state.visibility.lint)await loadLintOverlay();
}
async function navigate(path){
 try{state.path=path;await refreshGraph(true);}
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
function tree(){const box=$('hierarchy');box.replaceChildren();const button=document.createElement('button');button.className='tree-button';button.textContent='▣ '+state.overview.top;button.onclick=()=>navigate('/');box.append(button);for(const n of state.graph.nodes.filter(n=>n.child)){const b=document.createElement('button');b.className='tree-button depth1';b.textContent=(n.type==='generate'?'▤ ':'◇ ')+n.name;b.onclick=()=>enter(n.child);box.append(b);}}
function inspector(show=true,tab='source'){const changed=show!==state.inspector;state.inspector=show;$('inspector').hidden=!show;if(show)setTab(tab);syncInspectorButtons();requestAnimationFrame(()=>{resize();if(changed&&!state.manualView)fit();else draw();});}
function setTab(tab){
 state.tab=tab;
 for(const t of ['source','lint','cone']){
  $(t+'Pane').hidden=t!==tab;
  $(t+'Tab').classList.toggle('active',t===tab);
  $(t+'Tab').setAttribute('aria-selected',String(t===tab));
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

async function loadTab(){try{if(state.tab==='source'){const result=await api('source',{path:state.path});$('sourceFile').textContent=result.status==='available'?result.file:'Source not mapped';const code=$('sourceCode');code.replaceChildren();$('lineNumbers').textContent='';if(result.code){const fragment=document.createDocumentFragment();result.code.split('\n').forEach((line,i)=>{const span=document.createElement('span');span.className='code-line';span.dataset.line=String(i+1);span.textContent=line||' ';fragment.append(span);});code.append(fragment);$('lineNumbers').textContent=result.code.split('\n').map((_,i)=>i+1).join('\n');}else code.textContent=result.reason||'No source location';$('inspectorFoot').textContent=result.status==='available'?'Click a source line to focus an AST symbol':'Source reference unavailable';const selected=state.graph.nodes.find(n=>n.id===state.selected);if(selected?.line)focusLine(selected.line,selected.name);if(pendingLintLine){focusLine(pendingLintLine,'lint diagnostic');pendingLintLine=0;}}
 if(state.tab==='lint'){const result=await api('lint',{path:state.path}),box=$('lintResults');box.replaceChildren();if(result.status!=='available'||!result.diagnostics.length){box.textContent=result.status==='available'?'No diagnostics for mapped RTL file':'Slang lint report unavailable / no source mapping';return;}for(const warning of result.diagnostics){const article=document.createElement('article'),code=document.createElement('code');code.textContent=String(warning.code||warning.severity||'warning');article.append(code,document.createTextNode(' '+String(warning.message||warning.text||JSON.stringify(warning))));box.append(article);}}
 if(state.tab==='cone'){const list=state.graph.nodes.filter(n=>['port','register','counter','fsm','signal','operator'].includes(n.type));for(const name of ['fromSelect','toSelect']){const el=$(name),previous=el.value;el.replaceChildren();for(const n of list){const opt=document.createElement('option');opt.value=n.id;opt.textContent=n.name;el.append(opt);}if(list.some(n=>n.id===previous))el.value=previous;}}}catch(e){announce(e.message);}}
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
canvas.addEventListener('pointermove',ev=>{const d=state.drag;if(d){const dx=ev.clientX-d.x,dy=ev.clientY-d.y;if(Math.abs(dx)+Math.abs(dy)>5)d.moved=true;if(d.moved){state.manualView=true;cancelAnimationFrame(cameraAnimation);setView({...d.origin,x:d.origin.x+dx,y:d.origin.y+dy});draw();}return;}const item=hit(pointer(ev));if(item?.id!==state.hover?.id){state.hover=item;canvas.style.cursor=item?'pointer':'grab';canvas.title=item?.source?`Wire ${item.net.split('::sig:').pop()} ${item.port||''} · ${item.mapping==='partial'?'partial bus dependency': 'direct mapping'}`:(item?.name||'')+(item?.width?' · '+item.width:'')+(item?.dimensions?.unpackedDimensions?' · unpacked '+JSON.stringify(item.dimensions.unpackedDimensions):'');draw();}});
canvas.addEventListener('pointerup',ev=>{const d=state.drag;state.drag=null;if(!d||d.moved)return;if(d.item)selection(d.item,ev.ctrlKey||ev.metaKey);else{state.selected=null;draw();}});
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
canvas.addEventListener('keydown',ev=>{if(ev.key==='Escape'){state.selected=state.pinned=null;$('context').hidden=true;draw();}
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
for(const t of ['source','lint','cone'])$(t+'Tab').onclick=()=>setTab(t);
$('sourceCode').onclick=ev=>{const row=ev.target.closest('[data-line]');if(!row)return;const line=Number(row.dataset.line),node=state.graph.nodes.find(n=>Number(n.line)===line);if(node){selection(node);focusLine(line,node.name);}else announce('Line '+line+' · no exact AST-mapped symbol');};
$('runCone').onclick=async()=>{try{const r=await api('cone',{path:state.path,from:$('fromSelect').value,to:$('toSelect').value});$('coneResults').textContent=r.status+' · '+r.paths.length+' path(s)\n'+(r.paths.map(p=>p.map(id=>id.split('::').pop()).join(' → ')).join('\n')||r.reason||'No proven path')+'\nSequential boundaries: '+JSON.stringify(r.sequential_boundaries||[]);if(r.paths.length){state.selected=r.paths[0][0];draw();}}catch(e){announce(e.message);}};
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
api('overview').then(async data=>{state.overview=data;$('topLabel').textContent=data.top;$('stats').textContent=data.instances+' elaborated scopes · '+data.modules+' modules';$('status').textContent=data.source==='Slang verified'?'● SLANG VERIFIED':'◌ IMPORTED AST';await navigate('/');}).catch(e=>{$('status').textContent='ERROR';announce(e.message);});
