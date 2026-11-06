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
 const setWidth=(n,persist=true)=>{const w=Math.round(Math.max(180,Math.min(520,n)));side.style.width=w+'px';side.style.minWidth=w+'px';handle.setAttribute('aria-valuenow',String(w));handle.setAttribute('aria-valuemin','180');handle.setAttribute('aria-valuemax','520');if(persist)try{localStorage.setItem('flexsoc-rtl-navigator-width',String(w));}catch(_e){}};
 try{const stored=Number(localStorage.getItem('flexsoc-rtl-navigator-width'));if(stored>=180&&stored<=520)setWidth(stored,false);}catch(_e){}
 handle.addEventListener('pointerdown',e=>{dragging=true;handle.setPointerCapture(e.pointerId);e.preventDefault();});
 handle.addEventListener('pointermove',e=>{if(dragging){setWidth(e.clientX-side.getBoundingClientRect().left);resize();}});
 handle.addEventListener('pointerup',()=>{dragging=false;});
 handle.addEventListener('pointercancel',()=>{dragging=false;});
 handle.addEventListener('keydown',e=>{if(e.key==='ArrowLeft'||e.key==='ArrowRight'){setWidth(side.getBoundingClientRect().width+(e.key==='ArrowLeft'?-20:20));resize();e.preventDefault();}});
}
function initExplorerUX(){ensureDetailsUI();installSidebarResize();}
if(document.readyState==='loading')document.addEventListener('DOMContentLoaded',initExplorerUX,{once:true});else initExplorerUX();

const canvas = $('diagram'), ctx = canvas.getContext('2d', {alpha:false});
const semanticTip=$('rtlSemanticTooltip');
function hideSemanticTip(){if(semanticTip)semanticTip.hidden=true;}
function showSemanticTip(item,ev){
 if(!semanticTip||!window.FlexWorkbenchSemantics)return;
 const detail=window.FlexWorkbenchSemantics.semantic(item);
 if(!detail){hideSemanticTip();return;}
 // textContent only: never insert AST metadata as HTML.
 semanticTip.replaceChildren();semanticTip.dataset.tone=detail.tone;
 const heading=document.createElement('strong');heading.textContent=detail.kind;
 const name=document.createElement('div');name.className='rtl-tip-name';name.textContent=detail.name;
 semanticTip.append(heading,name);
 for(const [key,value] of detail.rows.slice(0,6)){
  const row=document.createElement('div');row.className='rtl-tip-row';
  const label=document.createElement('span');label.textContent=key;
  const text=document.createElement('span');text.textContent=value;
  row.append(label,text);semanticTip.append(row);
 }
 semanticTip.hidden=false;
 const bounds=$('schematic').getBoundingClientRect();
 const left=Math.min(Math.max(8,ev.clientX-bounds.left+16),Math.max(8,bounds.width-semanticTip.offsetWidth-12));
 const top=Math.min(Math.max(8,ev.clientY-bounds.top+14),Math.max(8,bounds.height-semanticTip.offsetHeight-12));
 semanticTip.style.left=left+'px';semanticTip.style.top=top+'px';
}
const state = {overview:null,graph:null,path:'/',fsmFocus:null,processFocus:null,processParent:null,generateFocus:null,valueFocus:null,valueParent:null,expanded:new Map(),viewport:new Map(),layouts:new Map(),selected:null,multiSelected:new Set(),pinned:null,freezeSchematic:false,hover:null,drag:null,inspector:false,tab:'source',context:null,wire:null,manualView:false,visibility:{wires:true,names:true}};
// Theme manager owns paired CSS chrome and Canvas palettes. No graph changes.
let colors=window.FlexRTLThemes.presets.graphite.canvas;

const clamp=(x,lo,hi)=>Math.min(hi,Math.max(lo,x));
const keyOf=n=>n?.net||n?.id||'';
const isSignal=n=>n?.id?.includes('::sig:');
function applyTheme(mode,accent=window.FlexRTLThemes.readAccent()){
 const result=window.FlexRTLThemes.apply(mode,accent);
 colors=result.colors;
 const label=$('themeName');if(label)label.textContent=result.spec.label;
 for(const button of document.querySelectorAll('[data-theme-choice]')){
  const pressed=button.dataset.themeChoice===result.name;button.setAttribute('aria-pressed',String(pressed));
 }
 for(const button of document.querySelectorAll('[data-accent-choice]')){
  const pressed=button.dataset.accentChoice===result.accentChoice;button.setAttribute('aria-pressed',String(pressed));
 }
 const picker=$('accentCustom');if(picker&&result.accentChoice.startsWith('#'))picker.value=result.accentChoice;
 if(state.graph)draw();
}
function installThemePicker(){
 const toggle=$('themeToggle'),menu=$('themeMenu');if(!toggle||!menu)return;
 const open=show=>{menu.hidden=!show;toggle.setAttribute('aria-expanded',String(show));};
 toggle.onclick=()=>open(menu.hidden);
 for(const button of menu.querySelectorAll('[data-theme-choice]')){
  button.onclick=()=>{applyTheme(button.dataset.themeChoice);open(false);toggle.focus();};
 }
 for(const button of menu.querySelectorAll('[data-accent-choice]')){
  button.onclick=()=>applyTheme(document.documentElement.dataset.palette,button.dataset.accentChoice);
 }
 const custom=$('accentCustom');if(custom){
  custom.oninput=()=>applyTheme(document.documentElement.dataset.palette,custom.value);
 }
 document.addEventListener('pointerdown',event=>{if(!event.target.closest('#themePicker'))open(false);});
 document.addEventListener('keydown',event=>{if(event.key==='Escape'&&!menu.hidden){open(false);toggle.focus();}});
 open(false);applyTheme(window.FlexRTLThemes.readTheme(),window.FlexRTLThemes.readAccent());
}
function announce(message){$('message').textContent=message;}
async function api(name,params={}) {
 if(typeof window.FlexAPI==='function') return window.FlexAPI(name,params);
 const url=new URL('/api/'+name,location.protocol==='about:'?'http://localhost':location.href);
 Object.entries(params).forEach(([k,v])=>url.searchParams.set(k,v));
 const r=await fetch(url);const data=await r.json();if(!r.ok)throw Error(data.error||r.status);return data;
}
function cameraKey(){return state.path+'|'+(state.valueFocus||state.processFocus||state.fsmFocus||state.generateFocus||'module');}
function view(){return state.viewport.get(cameraKey())||{x:90,y:90,z:1};}
function setView(v){state.viewport.set(cameraKey(),v);}
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
// One physical pin contract for Canvas and ELK; no native-router geometry.
const boxSize=FlexSymbolGeometry.boxSize;
const layoutEngine=FlexLayoutEngine.create({boxSize});
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
  const key=layoutKey(current);
  if(key!==id||current!==graph)return;
  state.layouts.set(id,result);
  setLayoutStatus(result.stats?.crossingBridgesLimited?'ELK / CONGESTED':'ELK',
   'crossing bridges '+(result.stats?.crossingBridges||0)+
   (result.stats?.crossingBridgesLimited?' (display limit reached)':''));
  if(!state.manualView)fit();else draw();
 }).catch(error=>{
  const current=state.graph;
  const key=layoutKey(current);
  if(key===id&&current===graph){
   elkFailed.add(id);
   state.layouts.delete(id);
   setLayoutStatus('ELK / ERROR',error.message);
   draw();
  }
  console.error('[rtl-view] ELK layout failed (no native fallback):',error);
 }).finally(()=>elkPending.delete(id));
}
function layoutKey(graph){return graph?.path+':'+(graph?.expanded||[]).join('|')+':'+graph?.revision+':'+(graph?.virtualFocus||'module');}
function layout(graph){
 const id=layoutKey(graph);
 if(state.layouts.has(id))return state.layouts.get(id);
 scheduleELK(graph,id);
 return emptyGeometry();
}
function round(x,y,w,h,r){ctx.beginPath();ctx.roundRect(x,y,w,h,r);}
function visible(p,v,w,h,margin=60){return(p.x+p.w)*v.z+v.x>=-margin&&p.x*v.z+v.x<=w+margin&&(p.y+p.h)*v.z+v.y>=-margin&&p.y*v.z+v.y<=h+margin;}
function wireVisible(points,v,w,h){const xs=points.map(p=>p[0]),ys=points.map(p=>p[1]);return visible({x:Math.min(...xs),y:Math.min(...ys),w:Math.max(...xs)-Math.min(...xs),h:Math.max(...ys)-Math.min(...ys)},v,w,h);}
// Selection is one visual conductor identified by its canonical net, not a
// combined selection of direct/partial relationships. Edge details stay AST-backed.
function highlighted(e){if(!e)return false;const identity=e.net||e.id;return (state.hover?.net||state.hover?.id)===identity||state.selected===identity||state.multiSelected.has(identity)||state.pinned===identity;}
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
function rtlLabel(value){return String(value).replace(/(^|[.\s])\d{8,}\s+/g,'$1');}
// Symbols render through a stateless Canvas painter; the full symbol geometry
// (including module port rows) is shared with ELK through FlexSymbolGeometry.
function symbol(n,p){
 FlexSymbolPainter.paint(ctx,n,p,{colors,
  picked:state.selected===n.id||state.multiSelected.has(n.id)||state.pinned===n.id||state.hover?.id===n.id,
  zoom:view().z,names:state.visibility.names,edges:state.graph?.edges||[]});
}
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

// A flattened virtual block retains a visible *frame*, even though ELK
// positions the original circuit nodes in the parent diagram. Frames have
// no electrical ports: all wires and source identities remain unchanged.
function flattenedFrames(graph,positions,groupRects){
 if(!graph||!positions)return [];
 const specs=[];
 for(const g of graph.processGroups||[]){
  if(g.view==='flattened'&&Array.isArray(g.memberIds))
   specs.push({token:g.token,name:g.name,type:'process_group',memberIds:g.memberIds});
 }
 for(const g of graph.fsmGroups||[]){
  if(g.view==='expanded'&&Array.isArray(g.memberIds))
   specs.push({token:g.token,name:'FSM · '+g.state,type:'fsm_group',memberIds:g.memberIds});
 }
 for(const g of graph.generateGroups||[]){
  if(g.view==='flattened')specs.push({token:g.token,name:g.name,type:'generate',
   memberIds:graph.nodes.filter(n=>n.type==='instance'&&n.group===g.token.slice(4)).map(n=>n.id)});
 }
 const output=[];
 for(const item of specs){
  // Process AND FSM frames use actual ELK compound-node bounds. A painted
  // post-layout bounding box can surround unrelated logic, particularly
  // when a flattened FSM exposes compact always_ff/always_comb children.
  if((item.type==='process_group'||item.type==='fsm_group')&&groupRects instanceof Map){
   const box=groupRects.get(item.token);
   if(box&&[box.x,box.y,box.w,box.h].every(Number.isFinite))
    output.push({...item,...box});
   continue;
  }
  const rects=item.memberIds.map(id=>positions.get(id)).filter(Boolean);
  if(!rects.length)continue;
  const x=Math.min(...rects.map(r=>r.x))-22,y=Math.min(...rects.map(r=>r.y))-56;
  const right=Math.max(...rects.map(r=>r.x+r.w))+22;
  const bottom=Math.max(...rects.map(r=>r.y+r.h))+26;
  if(![x,y,right,bottom].every(Number.isFinite))continue;
  output.push({...item,x,y,w:right-x,h:bottom-y});
 }
 // Parent frames go behind any smaller nested process frame.
 return output.sort((a,b)=>b.w*b.h-a.w*a.h);
}
function paintFlattenedFrames(frames,v,w,h){
 for(const f of frames){
  if(!visible(f,v,w,h,60))continue;
  const tone=f.type==='fsm_group'?colors.fsm:f.type==='generate'?colors.generate:colors.operator;
  ctx.save();ctx.strokeStyle=tone;ctx.fillStyle=tone;
  ctx.globalAlpha=.035;ctx.beginPath();ctx.roundRect(f.x,f.y,f.w,f.h,11);ctx.fill();
  // Screen-space stroke and caption remain legible even at 12% zoom.
  ctx.globalAlpha=.7;ctx.lineWidth=Math.max(2,1.6/v.z);
  ctx.setLineDash([Math.max(9,7/v.z),Math.max(5,4/v.z)]);ctx.stroke();ctx.setLineDash([]);
  ctx.restore();
 }
}
// Keep the flattened group identity visible even if its 10k-unit ELK cone
// extends beyond the top of a zoomed-out viewport. Labels are screen-space
// overlays and do not add any electrical pin, node or routing edge.
function frameLabelRects(frames,v,w,h){
 return frames.filter(f=>visible(f,v,w,h,10)).map(f=>{
  const width=Math.min(320,Math.max(225,f.name.length*8+132));
  const x=clamp(f.x*v.z+v.x+10,6,Math.max(6,w-width-6));
  const y=clamp(f.y*v.z+v.y+8,56,Math.max(56,h-30));
  return {...f,labelX:x,labelY:y,labelW:width,labelH:25};
 });
}
function paintFrameLabels(labels){
 for(const f of labels){
  const tone=f.type==='fsm_group'?colors.fsm:f.type==='generate'?colors.generate:colors.operator;
  ctx.save();ctx.fillStyle=colors.canvas;ctx.globalAlpha=.96;
  ctx.fillRect(f.labelX,f.labelY,f.labelW,f.labelH);
  ctx.globalAlpha=1;ctx.strokeStyle=tone;ctx.lineWidth=1.2;
  ctx.strokeRect(f.labelX,f.labelY,f.labelW,f.labelH);
  ctx.fillStyle=colors.text;ctx.font='600 12px system-ui,sans-serif';
  ctx.textAlign='left';ctx.fillText(f.name+' · FLATTENED',f.labelX+8,f.labelY+17,f.labelW-102);
  // Canvas overlay only: this click target restores the ORIGINAL compact
  // group in the same scope. No semantic nodes/edges are synthesized.
  ctx.strokeStyle=tone;ctx.beginPath();
  ctx.moveTo(f.labelX+f.labelW-94,f.labelY+4);
  ctx.lineTo(f.labelX+f.labelW-94,f.labelY+f.labelH-4);ctx.stroke();
  ctx.font='600 10px system-ui,sans-serif';
  ctx.fillText('↶ Unflatten',f.labelX+f.labelW-87,f.labelY+17,81);
  ctx.restore();
 }
}
function draw(){if(!state.graph)return;const w=canvas.clientWidth||1,h=canvas.clientHeight||1,v=view(),d=layout(state.graph);ctx.setTransform(canvas.width/w,0,0,canvas.height/h,0,0);ctx.fillStyle=colors.canvas;ctx.fillRect(0,0,w,h);const frames=flattenedFrames(state.graph,d.positions,d.groupRects);ctx.save();ctx.translate(v.x,v.y);ctx.scale(v.z,v.z);
 paintFlattenedFrames(frames,v,w,h);
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
 ctx.restore();paintFrameLabels(frameLabelRects(frames,v,w,h));}
function pointer(ev){const r=canvas.getBoundingClientRect(),v=view();return{x:(ev.clientX-r.left-v.x)/v.z,y:(ev.clientY-r.top-v.y)/v.z};}
function distSeg(p,a,b){const dx=b[0]-a[0],dy=b[1]-a[1],l=dx*dx+dy*dy;const t=l?clamp(((p.x-a[0])*dx+(p.y-a[1])*dy)/l,0,1):0;return Math.hypot(p.x-a[0]-t*dx,p.y-a[1]-t*dy);}
function hit(p){if(!state.graph)return null;const d=layout(state.graph);for(let i=state.graph.nodes.length-1;i>=0;i--){const n=state.graph.nodes[i],r=d.positions.get(n.id);if(r&&p.x>=r.x&&p.x<=r.x+r.w&&p.y>=r.y&&p.y<=r.y+r.h)return n;}
 // The frame header is also a context-menu/navigation target, while its
 // transparent body never steals clicks from wires or schematic operators.
 const v=view(),screenX=p.x*v.z+v.x,screenY=p.y*v.z+v.y;
 for(const frame of frameLabelRects(flattenedFrames(state.graph,d.positions,d.groupRects),v,canvas.clientWidth,canvas.clientHeight)){
  if(screenX>=frame.labelX&&screenX<=frame.labelX+frame.labelW&&
     screenY>=frame.labelY&&screenY<=frame.labelY+frame.labelH){
   if(screenX>=frame.labelX+frame.labelW-94)
    return {id:frame.token+'::unflatten',name:'Unflatten '+frame.name,
     type:'frame_unflatten',group:frame.token};
   return {id:frame.token,name:frame.name,type:frame.type,group:frame.token};
  }
 }
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
function selection(item,track=false,additive=false){if(!item)return;
 if(sourceProbe&&!probeCandidates(sourceProbe.result).some(c=>c.id===item.id)){sourceProbe=null;showProbeChoices();}
 const edge=item.source&&item.target;const id=edge?(item.net||item.id):item.id;if(additive){if(state.multiSelected.has(id)){state.multiSelected.delete(id);if(state.selected===id)state.selected=state.multiSelected.values().next().value||null;}else{if(state.selected)state.multiSelected.add(state.selected);state.multiSelected.add(id);state.selected=id;}}else{state.multiSelected.clear();state.selected=id;}state.inspectEntityId=item.id;if(track&&id.includes('::sig:'))state.pinned=id;const label=edge?`${item.port?item.port+' · ':''}${String(item.signal||item.net||item.id).split('::sig:').pop()} · ${item.type} ${item.rendered===false?'dependency (not a wire)':'wire'}`+(item.mapping==='partial'?' · bus slice (not bit-exact)':''):item.name+' · '+item.type;announce((track?'Tracking · ':'Selected · ')+label);
 if(state.inspector&&state.tab==='source'){const node=sourceSelectionNode();if(node?.line)focusLine(Number(node.line),node.name);}if(state.inspector&&['details','connections','references','source','lint','mapping'].includes(state.tab))loadTab();refreshInspectorIdentity();refreshNavigationStatus();draw();}
// Resolve signal selection by canonical identity, not by a guessed name.
function sourceSelectionNode(){
 if(!state.graph)return null;
 const ids=[state.selected,state.inspectEntityId].filter(Boolean);
 const edge=state.graph.edges.find(e=>ids.includes(e.id));
 // Expression-output wire IDs have no SV declaration of their own. Use
 // explicit AST destination provenance, never the coincident display name.
 if(edge){if(edge.signal)ids.unshift(edge.signal);if(edge.net)ids.unshift(edge.net);}
 return state.graph.nodes.find(n=>ids.includes(n.id))||null;
}
function sourceEvidenceBanner(node){
 const banner=document.createElement('div');banner.className='source-role-evidence';
 const name=node?.name||'No AST signal selected';
 const call=node?.shape==='function'&&node?.function;
 banner.textContent=call&&node?.line
  ?`Selected function: ${name} · Slang call site: AST line ${node.line} · definition: ${String(call.definitionFile||'unknown file')}:${String(call.definitionLine||'?')}`
  :node?.line
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
 // Keep the navigation outside the scrollable <pre>: it must remain visible
 // when the editor is scrolled, including when native Neovim is active.
 document.querySelectorAll('#sourcePane > .source-occurrences').forEach(el=>el.remove());
 const host=document.createElement('section');host.className='source-occurrences';
 $('nvimContainer').before(host);
 const roleStyles=document.createElement('style');
 roleStyles.textContent='.code-line.occurrence-declaration{background:rgba(74,162,235,.19);border-left:3px solid #4aa2eb}.code-line.occurrence-write{background:rgba(242,160,57,.18);border-left:3px solid #f2a039}.code-line.occurrence-read{background:rgba(63,190,124,.17);border-left:3px solid #3fbe7c}.code-line.occurrence-declaration.occurrence-write,.code-line.occurrence-write.occurrence-read{background:linear-gradient(90deg,rgba(74,162,235,.19),rgba(242,160,57,.19),rgba(63,190,124,.17))}';
 host.append(roleStyles);
 const title=document.createElement('div');title.className='source-role-evidence';
 host.append(title);
 const signal=selectedSignalName();
 if(!signal){title.textContent='Select a signal to browse AST references';return;}
 title.textContent='References · '+signal+' · loading…';
 const request=++occurrenceRequest,scope=state.path;
 api('occurrences',{path:scope,signal}).then(data=>{
  if(request!==occurrenceRequest || state.path!==scope || state.tab!=='source' || !state.inspector || !host.isConnected)return;
  host.replaceChildren(roleStyles);
  const heading=document.createElement('div');heading.className='source-role-evidence';
  heading.textContent=signal+' · '+(data.complete?'AST':'partial AST');host.append(heading);
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
  const legend=document.createElement('details');legend.className='rtl-reference-legend';
  const legendHeading=document.createElement('summary');legendHeading.textContent='Legend';
  const legendBody=document.createElement('p');legendBody.textContent='Decl = declaration · Assigned = write · Read = use. Shortcuts: [d/]d · [w/]w · [r/]r. Only Slang source locations are shown.';
  legend.append(legendHeading,legendBody);nav.append(legend);
  host.append(nav);
  // One navigator per Source render; discarded as soon as selection changes.
  code._astNavigate=(role,delta)=>{
   if(request!==occurrenceRequest||state.path!==scope||!host.isConnected)return false;
   jump(role,delta);return true;
  };
  const labels={declaration:'Declaration',write:'Write',read:'Read'};
  const details=document.createElement('details');details.className='rtl-reference-details';
  const detailsTitle=document.createElement('summary');detailsTitle.textContent='All locations';details.append(detailsTitle);
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
   details.append(row);
  }
  host.append(details);
 }).catch(error=>{
  if(request!==occurrenceRequest||!host.isConnected)return;
  title.textContent='AST occurrences unavailable · '+error.message;
 });
}
function focusLine(line,name){window.FlexNativeEditor?.jump(line);const row=$('sourceCode').querySelector(`[data-line="${line}"]`);if(!row)return;$('sourceCode').querySelectorAll('.focus-line').forEach(el=>el.classList.remove('focus-line'));row.classList.add('focus-line');row.scrollIntoView({block:'center',inline:'nearest'});$('inspectorFoot').textContent='AST source line '+line+' · '+name;}
// Lint is an independent evidence layer, not a schematic connectivity edge.
// A file-level diagnostic is never attached to an arbitrary instance.
function priorityOf(d){
 const raw=String(d.priority||d.pri||'').toUpperCase();
 return ['P0','P1','P2','P3'].includes(raw)?raw:'?';
}
let pendingLintLine=0;
let pendingLintFile='';
let pendingLintProbe=false;
// Incremented whenever a panel request becomes obsolete.
let inspectorRequest=0;
let navigationRequest=0;
function nodeList(){const box=$('a11yNodes');box.replaceChildren();for(const n of state.graph.nodes){const button=document.createElement('button');button.textContent=n.name+' · '+n.type;button.onclick=()=>selection(n);box.append(button);}for(const e of state.graph.edges){const button=document.createElement('button');button.textContent='Wire · '+e.net.split('::sig:').pop()+(e.port?' → '+e.port:'');button.onclick=()=>selection(e,true);box.append(button);}}
function expandedGroups(path=state.path){return state.expanded.get(path)||new Set();}
// The default 320-node slice can cut a valid, atomic process-value cone
// from a realistic TX/RX module. Request a bounded 800-node scope; the
// backend still refuses partially emitted expression cones.
function generateGroupSummaries(graph){
 const buckets=new Map();
 for(const node of graph.nodes){
  if(node.type==='generate'&&node.group){
   buckets.set(node.group,{name:'generate · '+node.name,count:node.count||1});
  }else if(node.type==='instance'&&node.group){
   const previous=buckets.get(node.group)||{name:'generate · '+node.group,count:0};
   previous.count++;buckets.set(node.group,previous);
  }
 }
 return [...buckets].sort(([a],[b])=>a.localeCompare(b)).map(([group,meta])=>({
  token:'gen:'+group,name:meta.name,kind:'generate',count:meta.count,
  view:state.generateFocus===group?'entered':expandedGroups().has(group)?'flattened':'collapsed'
 }));
}
function focusGeneratedGraph(graph,group){
 const memberIds=new Set(graph.nodes.filter(n=>n.type==='instance'&&n.group===group).map(n=>n.id));
 if(!memberIds.size)throw Error('No elaborated generate members are visible in this graph slice');
 const visible=new Set(memberIds);
 for(const edge of graph.edges){
  if(memberIds.has(edge.source))visible.add(edge.target);
  if(memberIds.has(edge.target))visible.add(edge.source);
 }
 const nodes=graph.nodes.filter(n=>visible.has(n.id));
 const edges=graph.edges.filter(e=>visible.has(e.source)&&visible.has(e.target));
 return {...graph,nodes,edges,virtualFocus:'gen:'+group,
  module:'generate · '+group,virtualParent:graph.path,total:nodes.length,truncated:false};
}
async function fetchGraph(path){
 const groups=new Set(expandedGroups(path));
 if(state.fsmFocus&&!state.processFocus&&!state.generateFocus)groups.add(state.fsmFocus);
 if(state.generateFocus)groups.add(state.generateFocus);
 const graph=await api('diagram',{path,expand:[...groups].join('|'),
  fsm:state.processFocus||state.generateFocus?0:1,limit:800});
 const generateGroups=generateGroupSummaries(graph);
 if(state.valueFocus){
  // Use the unprojected compiler graph so functions hidden behind virtual
  // process/FSM boxes can still be examined with their real terminals.
  const projection=window.FlexDriverTrace?.valuePath(graph,state.valueFocus);
  if(!projection||projection.status==='not_visible'||projection.status==='unavailable')
   throw Error('Selected signal has no AST-backed value path in this graph slice');
  return {...projection.graph,traceInfo:{...projection.graph.traceInfo,status:projection.status}};
 }
 if(state.generateFocus){
  const focused=focusGeneratedGraph(graph,state.generateFocus);
  return {...focused,generateGroups,virtualFocus:'gen:'+state.generateFocus};
 }
 if(state.processFocus){
  if(typeof FlexVirtualProcess==='undefined')throw Error('Process navigation asset is missing');
  const focused=FlexVirtualProcess.focus(graph,state.processFocus);
  return {...focused,generateGroups,virtualFocus:state.processFocus};
 }
 const focused=state.fsmFocus?focusFsmGraph(graph,state.fsmFocus):graph;
 if(typeof FlexVirtualProcess==='undefined')return {...focused,generateGroups,virtualFocus:state.fsmFocus||null};
 // Flattening one virtual layer must NOT flatten its descendants.
 // An expanded FSM exposes the immediate process shells (always_ff / comb)
 // as COMPACT children. Their own tokens are expanded only when explicitly
 // requested, independently of the parent FSM token. The backend already
 // restores the original FSM nodes before this process projection.
 const grouped=FlexVirtualProcess.project(focused,groups,
  {allowPartial:!!state.fsmFocus});
 return {...grouped,generateGroups,virtualFocus:state.fsmFocus||null};
}
function focusFsmGraph(graph,token){
 const entry=(graph.fsmGroups||[]).find(g=>g.token===token);
 if(!entry||!Array.isArray(entry.memberIds)||!Array.isArray(entry.inputIds)||!Array.isArray(entry.outputIds)){
  throw Error('FSM interior is unavailable in this graph slice');
 }
 const visible=new Set([...entry.memberIds,...entry.inputIds,...entry.outputIds]);
 const nodes=graph.nodes.filter(n=>visible.has(n.id));
 // Unmodified compiler-backed edges, including timing, preserve their IDs
 // and original endpoints. No virtual port is claimed to be electrical RTL.
 const edges=graph.edges.filter(e=>visible.has(e.source)&&visible.has(e.target));
 return {...graph,nodes,edges,total:nodes.length,truncated:false,
  module:'FSM · '+entry.state,virtualParent:graph.path,
  fsmGroups:graph.fsmGroups.map(g=>({...g,view:g.token===token?'entered':g.view}))};
}
async function refreshGraph(preserve=true){
  const requestedPath=state.path, request=++navigationRequest;
  const graph=await fetchGraph(requestedPath);
  if(request!==navigationRequest||requestedPath!==state.path)return false;
  const previous=state.graph;
  state.graph=graph;
 $('viewName').textContent=state.graph.module;
 $('viewDesc').textContent=state.valueFocus?'AST value path · original pins and edges · parent '+state.path:
  state.generateFocus?'Virtual generate array · parent '+state.path:state.processFocus?'Virtual procedural process · parent '+state.path:state.fsmFocus?'Virtual FSM schematic · parent '+state.path:'Hierarchy ' + state.path + ' · RTL connectivity';
 syncCounts();breadcrumbs();tree();nodeList();
 if(!preserve||!previous||!state.viewport.has(cameraKey()))fit();else draw();if($('search').value)searchGraph($('search').value);
 if(state.inspector)loadTab();
  refreshNavigationStatus();
  return true;
}
async function navigate(path){
 const previousPath=state.path,previousFocus=state.fsmFocus,previousProcess=state.processFocus,previousParent=state.processParent,previousGenerate=state.generateFocus;
 const previousValue=state.valueFocus,previousValueParent=state.valueParent;
 try{if(path!==state.path){sourceProbe=null;++sourceProbeRequest;}
  state.path=path;state.fsmFocus=null;state.processFocus=null;state.processParent=null;state.generateFocus=null;
  state.valueFocus=null;state.valueParent=null;++inspectorRequest;
  await refreshGraph(previousFocus===null);
 }catch(e){state.path=previousPath;state.fsmFocus=previousFocus;state.processFocus=previousProcess;state.processParent=previousParent;state.generateFocus=previousGenerate;
  state.valueFocus=previousValue;state.valueParent=previousValueParent;announce(e.message);}
}
async function toggleGroupToken(group){
 if(!group)return false;
 const groups=new Set(expandedGroups());
 const wasExpanded=groups.has(group);
 const before=new Set(groups);
 if(wasExpanded)groups.delete(group);else groups.add(group);
 state.expanded.set(state.path,groups);
 try{const refreshed=await refreshGraph(false);
  if(!refreshed){state.expanded.set(state.path,before);return false;}
  announce((wasExpanded?'Collapsed ':'Expanded ')+group);return true;}
 catch(e){state.expanded.set(state.path,before);announce('FSM view change failed: '+e.message);return false;}
}
async function toggleFsmToken(scope,token){
 if(scope!==state.path||!state.graph?.fsmGroups?.some(g=>g.token===token))return false;
 const previous=state.fsmFocus;
 state.fsmFocus=previous===token?null:token;
 try{
  const ok=await refreshGraph(false);
  if(!ok){state.fsmFocus=previous;return false;}
  announce(state.fsmFocus?'Entered FSM · '+token.slice(4):'Returned to '+state.path);
  return true;
 }catch(e){state.fsmFocus=previous;announce('FSM navigation failed: '+e.message);return false;}
}
async function toggleProcessToken(scope,token){
 if(scope!==state.path||!/^proc:\d+$/.test(token))return false;
 const previous=state.processFocus,parent=state.processParent;
 if(previous===token){state.processFocus=null;state.fsmFocus=parent;state.processParent=null;}
 else{state.processParent=previous?parent:state.fsmFocus;state.processFocus=token;state.fsmFocus=null;}
 try{if(!await refreshGraph(false))throw Error('navigation was superseded');
  announce(state.processFocus?'Entered '+token:'Returned to parent schematic');return true;
 }catch(e){state.processFocus=previous;state.processParent=parent;
  state.fsmFocus=previous?null:parent;announce('Process navigation failed: '+e.message);return false;}
}
async function toggleGenerateToken(scope,group){
 if(scope!==state.path||!group)return false;
 const previous=state.generateFocus;
 state.generateFocus=previous===group?null:group;
 try{if(!await refreshGraph(false))throw Error('navigation was superseded');
  announce(state.generateFocus?'Entered generate · '+group:'Returned to parent module');return true;
 }catch(e){state.generateFocus=previous;announce('Generate navigation failed: '+e.message);return false;}
}
async function enterValuePath(item){
 if(!item||!state.graph||state.valueFocus)return false;
 const prior={fsmFocus:state.fsmFocus,processFocus:state.processFocus,
  processParent:state.processParent,generateFocus:state.generateFocus};
 state.valueParent=prior;state.valueFocus=item.id;
 state.fsmFocus=null;state.processFocus=null;state.processParent=null;state.generateFocus=null;
 try{
  if(!await refreshGraph(false))throw Error('Value path navigation superseded');
  announce('Showing AST value path · '+(item.name||item.id));return true;
 }catch(error){
  state.valueFocus=null;state.valueParent=null;
  Object.assign(state,prior);
  announce('Value path unavailable: '+error.message);return false;
 }
}
async function leaveValuePath(){
 if(!state.valueFocus)return false;
 const previous=state.valueFocus,parent=state.valueParent;
 state.valueFocus=null;state.valueParent=null;
 if(parent)Object.assign(state,parent);
 try{
  if(!await refreshGraph(false))throw Error('Navigation superseded');
  announce('Returned to parent schematic');return true;
 }catch(error){
  state.valueFocus=previous;state.valueParent=parent;
  state.fsmFocus=null;state.processFocus=null;state.processParent=null;state.generateFocus=null;
  announce('Return failed: '+error.message);return false;
 }
}
async function virtualAction(scope,token,mode='enter'){
 if(scope!==state.path)return false;
 if(mode==='flatten')return toggleGroupToken(token.startsWith('gen:')?token.slice(4):token);
 if(token.startsWith('gen:'))return toggleGenerateToken(scope,token.slice(4));
 if(token.startsWith('proc:'))return toggleProcessToken(scope,token);
 if(token.startsWith('fsm:'))return toggleFsmToken(scope,token);
 return false;
}
async function toggleGroup(item){
 if(item?.type==='fsm_group')return toggleFsmToken(state.path,item.group);
 if(item?.type==='process_group')return toggleProcessToken(state.path,item.group);
 if(item?.type==='generate')return toggleGenerateToken(state.path,item.group);
 if(item?.fsmExpanded)return toggleFsmToken(state.path,item.group);
 if(!item?.group)return false;
 return toggleGroupToken(item.group);
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
 // A virtual FSM is a separate schematic view, not a compiler module.
 if(state.fsmFocus&&!state.processFocus){
  const group=(state.graph.fsmGroups||[]).find(g=>g.token===state.fsmFocus);
  if(group){
   const sep=document.createElement('span');sep.className='crumb-sep';sep.textContent='›';sep.setAttribute('aria-hidden','true');box.append(sep);
   const label=document.createElement('span');label.className='fsm-crumb-label';label.textContent='FSM · '+group.state;label.setAttribute('aria-current','page');box.append(label);
   const back=document.createElement('button');back.type='button';back.className='fsm-crumb-back';
   back.textContent='← '+(state.graph.ancestors||[]).at(-1)?.name;
   back.title='Return to parent module schematic';
   back.setAttribute('aria-label','Return to parent module from FSM '+group.state);
   back.onclick=()=>toggleFsmToken(state.path,group.token);box.append(back);
  }
 }
 if(state.generateFocus){
  const sep=document.createElement('span');sep.className='crumb-sep';sep.textContent='›';box.append(sep);
  const label=document.createElement('span');label.className='fsm-crumb-label';label.textContent='generate · '+state.generateFocus;box.append(label);
  const back=document.createElement('button');back.type='button';back.className='fsm-crumb-back';
  back.textContent='← Module';back.title='Return to parent module';
  back.onclick=()=>toggleGenerateToken(state.path,state.generateFocus);box.append(back);
 }
 if(state.processFocus){
  const group=(state.graph.processGroups||[]).find(g=>g.token===state.processFocus);
  if(group){
   const sep=document.createElement('span');sep.className='crumb-sep';sep.textContent='›';box.append(sep);
   const label=document.createElement('span');label.className='fsm-crumb-label';label.textContent=group.name;
   label.setAttribute('aria-current','page');box.append(label);
   const back=document.createElement('button');back.type='button';back.className='fsm-crumb-back';
   back.textContent='← '+(state.processParent?'FSM':'Module');
   back.title='Return to the parent schematic';
   back.onclick=()=>toggleProcessToken(state.path,state.processFocus);box.append(back);
  }
 }
 if(state.valueFocus){
  const sep=document.createElement('span');sep.className='crumb-sep';sep.textContent='›';box.append(sep);
  const label=document.createElement('span');label.className='fsm-crumb-label';label.textContent='Value path';
  label.setAttribute('aria-current','page');box.append(label);
  const back=document.createElement('button');back.type='button';back.className='fsm-crumb-back';
  back.textContent='← Diagram';back.title='Return to the full parent schematic';
  back.onclick=()=>leaveValuePath();box.append(back);
 }
 box.lastElementChild?.scrollIntoView({inline:'nearest',block:'nearest'});
}
const lazyTree=FlexHierarchyTree.create({host:$('hierarchy'),fetchPage:(path,offset,limit)=>api('hierarchy',{path,offset,limit}),navigate:path=>navigate(path),onVirtualGroup:virtualAction,onError:e=>announce('Hierarchy: '+e.message),onFilterStatus:(filter,count)=>{
 $('hierarchyFilterStatus').textContent=filter?count+' loaded match'+(count===1?'':'es')+' · not a full-design search':'Expandable elaborated instances';
}});
$('hierarchyFilter').addEventListener('input',event=>lazyTree.setFilter(event.target.value));
$('hierarchyFilter').addEventListener('keydown',event=>{
 if(event.key==='Escape'){event.target.value='';lazyTree.setFilter('');event.target.blur();}
 if(event.key==='ArrowDown'){event.preventDefault();$('hierarchy').querySelector('.fs-tree-label')?.focus();}
});
function tree(){
 lazyTree.activate(state.path);
 const processes=(state.graph?.processGroups||[]).map(g=>({...g,
  view:state.processFocus===g.token?'entered':expandedGroups().has(g.token)?'flattened':g.view}));
 lazyTree.setVirtualGroups(state.path,[...(state.graph?.fsmGroups||[]),...processes,...(state.graph?.generateGroups||[])]);
}
function inspector(show=true,tab='source'){if(!show)++inspectorRequest;const changed=show!==state.inspector;state.inspector=show;$('inspector').hidden=!show;if(show)setTab(tab);syncInspectorButtons();requestAnimationFrame(()=>{resize();if(changed&&!state.manualView)fit();else draw();});}
function setTab(tab){
 state.tab=tab;
 refreshInspectorIdentity();
 for(const t of ['details','connections','references','mapping','source','lint','cone']){
  if($(t+'Pane'))$(t+'Pane').hidden=t!==tab;
  if($(t+'Tab'))$(t+'Tab').classList.toggle('active',t===tab);
  if($(t+'Tab')){$(t+'Tab').setAttribute('aria-selected',String(t===tab));$(t+'Tab').tabIndex=t===tab?0:-1;}
 }
 syncInspectorButtons();
 if(state.inspector)loadTab();
}
function syncInspectorButtons(){
 const opener=$('toggleInspector');
 opener.classList.toggle('active',state.inspector);
 opener.setAttribute('aria-expanded',String(state.inspector));
}

function inspectedItem(){
 if(!state.graph)return null;
 const id=state.inspectEntityId||state.selected;
 return state.graph.nodes.find(n=>n.id===id)||state.graph.edges.find(e=>e.id===id)
  ||state.graph.edges.find(e=>e.net===state.selected)||null;
}
function refreshInspectorIdentity(){
 const item=inspectedItem();
 const name=$('inspectorEntityName'),meta=$('inspectorEntityMeta');
 if(!name||!meta)return;
 if(!item){name.textContent=state.graph?.module||'Select an entity';meta.textContent='Choose a symbol or wire · '+state.path;refreshNavigationStatus();return;}
 const wire=Boolean(item.source&&item.target);
 name.textContent=String(wire?(item.signal||item.net||item.id):(item.name||item.id)).split('::sig:').pop();
 const mapping=wire?item.rendered===false?'AST dependency, not a physical wire':
  item.mapping==='direct'?'Direct mapping':item.mapping==='partial'?'Partial mapping':'Mapping not established':
  item.type==='operator'?('Operator · '+(item.shape||item.kind||'AST')):String(item.type||'entity');
 meta.textContent=mapping+' · Scope '+state.path;refreshNavigationStatus();
}
function inspectorNote(target,message){
 target.replaceChildren();const element=document.createElement('p');element.className='rtl-inspector-empty';
 element.textContent=message;target.append(element);
}
function inspectorCard(target,heading,body,detail=''){
 const card=document.createElement('article');card.className='rtl-inspector-card';
 const title=document.createElement('strong');title.textContent=heading;card.append(title);
 const main=document.createElement('p');main.textContent=body;card.append(main);
 if(detail){const small=document.createElement('small');small.textContent=detail;card.append(small);}
 target.append(card);return card;
}
function renderConnections(){
 const target=$('connectionsResults'),item=inspectedItem();target.replaceChildren();
 if(!item||!state.graph){inspectorNote(target,'Select a signal, symbol or wire to inspect its AST relationships.');return;}
 const result=window.FlexDriverTrace?.producer(state.graph,item);
 if(!state.valueFocus && item.id && item.type!=='fsm_group' && item.type!=='process_group'){
  const card=inspectorCard(target,'Value path','Isolate the compiler-backed producing circuit',
   'Original inputs, operator pins and output; return with the breadcrumb');
  const button=document.createElement('button');button.type='button';
  button.textContent='↗ View value path';
  button.title='Show the existing input → operator/function → output circuit';
  button.onclick=()=>enterValuePath(item);card.append(button);
 }
 if(state.valueFocus && state.graph.traceInfo){
  const info=state.graph.traceInfo;
  inspectorCard(target,'Value path · '+info.status,
   info.rootDrivers+' direct producer(s)',
   info.limitedEdges?'Some connections exceed the display budget':'Only existing graph edges are shown');
 }
 if(result?.status==='unique'){
  const source=result.source;
  const card=inspectorCard(target,'Upstream producer',
    source.name+' · '+(source.shape==='function'?'FUNCTION':source.kind||source.shape||source.type),
    'Compiler-backed input → operation → destination; no new wires inferred');
  const reveal=document.createElement('button');reveal.type='button';reveal.textContent='⌖ Locate producer';
  reveal.title='Center the proven upstream driver in the ELK schematic';
  reveal.onclick=()=>focusSymbol(source);card.append(reveal);
  if(source.line){const jump=document.createElement('button');jump.type='button';
   jump.textContent='SV · L'+source.line;
   jump.onclick=()=>{selection(source);setTab('source');};card.append(jump);}
  if(result.inputs.length){const detail=document.createElement('small');
   detail.textContent='Inputs: '+result.inputs.map(i=>(i.pin?i.pin+'=':'')+i.source.name).join(', ');
   card.append(detail);}
 }else if(result?.status==='multiple_drivers'){
  inspectorCard(target,'No unique driver',result.count+' visible producers',
   'Multiple inputs cannot be collapsed into one electrical source');
 }
 const wire=Boolean(item.source&&item.target),id=item.id;
 const relationships=state.graph.edges.filter(e=>wire?
  (e.id===id||Boolean(item.net&&e.net===item.net)):
  (e.source===id||e.target===id));
 if(!relationships.length){inspectorNote(target,'No graph relationships in the current scope. This does not prove the hardware has no connections.');return;}
 for(const edge of relationships.slice(0,150)){
  const caption=edge.rendered===false?'AST dependency — not drawn':
   edge.mapping==='partial'?'Partial / non-bit-exact mapping':
   edge.mapping==='direct'?'Compiler-backed relation':'Mapping status unknown';
  const short=id=>state.graph.nodes.find(n=>n.id===id)?.name||String(id).split('::').pop();
  const card=inspectorCard(target,String(edge.type||'relationship'),
   short(edge.source)+' → '+short(edge.target),
   caption+(edge.port?' · Port '+edge.port:'')+(edge.pin?' · Pin '+edge.pin:''));
  if(edge.rendered===false)card.classList.add('rtl-inspector-uncertain');
 }
 if(relationships.length>150)inspectorCard(target,'Results limited',
  'Showing 150 of '+relationships.length+' relationships in this graph slice');
}
async function renderReferences(current){
 const target=$('referencesResults'),signal=selectedSignalName();target.replaceChildren();
 if(!signal){inspectorNote(target,'Choose a named signal to inspect Slang-backed declarations, writes and reads. Expression-output wires may not have a declaration of their own.');return;}
 inspectorNote(target,'Loading AST references for '+signal+'…');
 const result=await api('occurrences',{path:state.path,signal});
 if(!current())return;
 target.replaceChildren();
 if(result.status!=='available'){
  inspectorNote(target,'References unavailable: '+String(result.reason||result.status));return;
 }
 const sites=Array.isArray(result.sites)?result.sites:[];
 for(const [role,label] of [['declaration','Declaration'],['write','Write'],['read','Read']]){
  const hits=sites.filter(s=>s.role===role);
  const card=inspectorCard(target,label+' · '+hits.length,hits.length?'Compiler-backed source locations':'No verified locations');
  for(const site of hits.slice(0,60)){
   const jump=document.createElement('button');jump.type='button';jump.className='rtl-reference-link';
   jump.textContent=String(site.file||'unknown file')+':'+String(site.line||'?');
   jump.title='Open source inspector';
   jump.onclick=()=>{
    // The scope source() API chooses its canonical module file. Avoid
    // pretending that a reference in another file is openable here.
    pendingLintLine=Number(site.line)||0;pendingLintFile=String(site.file||'');setTab('source');
   };card.append(jump);
  }
 }
 inspectorCard(target,'Provenance',result.complete?'Complete for supported AST constructs':'Partial evidence',
  String(result.note||'Unsupported expressions are not guessed from source text.'));
}

// Cross-probing remains strictly scope-local and compiler-backed. No
// source-text token matching or arbitrary instance choice is permitted.
let sourceProbe=null;
let mappingSnapshot=null;
function probeCandidates(result){return (Array.isArray(result?.candidates)?result.candidates:[]).filter(c=>c.visible);}
function refreshNavigationStatus(message=''){
 const box=$('rtlProbeStatus');if(!box)return;
 const item=inspectedItem();const node=sourceSelectionNode();
 const latest=sourceProbe?.path===state.path?sourceProbe:null;
 if(message)box.textContent=message;
 else if(latest)box.textContent='Source L'+latest.line+' · '+latest.result.status+' · '+probeCandidates(latest.result).length+' visible candidate(s)';
 else if(item)box.textContent=(node?.line?('AST '+(node?.shape==='function'?'call':'declaration')+' L'+node.line):'No exact source line for selection')+' · '+(item.mapping||item.type||'AST')+' · '+state.path;
 else box.textContent='Select a schematic entity or click a SystemVerilog line';
 const reveal=$('rtlGoSchematic');if(reveal)reveal.disabled=!(latest&&probeCandidates(latest.result).length===1&&!probeCandidates(latest.result).some(c=>c.visible===false))&&!(node&&state.graph?.nodes.some(n=>n.id===node.id));
}
function showProbeChoices(){
 const panel=$('sourceProbeChoices');if(!panel)return;
 panel.replaceChildren();const probe=sourceProbe?.path===state.path?sourceProbe:null;
 if(!probe){panel.hidden=true;return;}
 panel.hidden=false;
 const candidates=probeCandidates(probe.result);
 const heading=document.createElement('strong');
 heading.textContent='SystemVerilog L'+probe.line+' → '+(candidates.length===1?'one AST match':candidates.length+' AST matches')+' · '+probe.result.status;
 panel.append(heading);
 if(!candidates.length){const note=document.createElement('span');note.textContent=probe.result.reason||'No source-backed entity in this diagram slice';panel.append(note);return;}
 for(const candidate of candidates){
  const b=document.createElement('button');b.type='button';b.textContent=candidate.name+' · '+(candidate.roles||[]).join('/');
  b.title='Reveal '+candidate.name+' in this elaborated schematic scope';
  b.onclick=()=>revealCandidate(candidate);panel.append(b);
 }
}
function revealCandidate(candidate){
 if(!state.graph||!candidate||!sourceProbe||sourceProbe.path!==state.path)return;
 const matched=state.graph.nodes.filter(n=>n.id===candidate.id);
 if(matched.length!==1){
  const group=state.graph.nodes.find(n=>['fsm_group','process_group'].includes(n.type)&&n.hiddenNodeIds?.includes(candidate.id));
  if(group){toggleGroup(group).then(()=>{
   const resolved=state.graph.nodes.find(n=>n.id===candidate.id);
   if(resolved)focusSymbol(resolved);
  });return;}
  refreshNavigationStatus('AST entity is outside the current schematic slice');return;
 }
 focusSymbol(matched[0]);refreshNavigationStatus('Revealed '+candidate.name+' · '+(candidate.roles||[]).join('/')+' · source L'+sourceProbe.line);
}
async function probeSourceLine(line){
 const path=state.path,request=++sourceProbeRequest;
 try{
  const result=await api('source_symbols',{path,line});
  if(request!==sourceProbeRequest||path!==state.path||!state.inspector)return;
  sourceProbe={path,line,result};showProbeChoices();refreshNavigationStatus();
  const candidates=probeCandidates(result);
  if(!state.freezeSchematic&&result.status==='resolved'&&candidates.length===1)revealCandidate(candidates[0]);
  else announce('AST L'+line+' · '+result.status+' · '+candidates.length+' visible match(es)');
 }catch(error){if(request===sourceProbeRequest&&path===state.path){sourceProbe=null;showProbeChoices();refreshNavigationStatus('AST lookup failed · '+error.message);}}
}
async function renderMapping(current){
 const box=$('mappingResults');inspectorNote(box,'Auditing AST signal visibility in this scope…');
 const result=await api('source_coverage',{path:state.path});
 if(!current())return;
 mappingSnapshot={path:state.path,result};
 const drawMapping=()=>{
  if(!current())return;
  box.replaceChildren();
  const data=mappingSnapshot?.result;const counts=data?.counts||{};
  const summary=document.createElement('p');summary.className='rtl-mapping-summary';
  summary.textContent='AST declarations '+(data?.total||0)+' · visible with location '+(counts.visible_mapped||0)+' · visible without location '+(counts.visible_unmapped||0)+' · outside current graph '+(counts.not_in_graph||0)+(data?.graph_truncated?' · GRAPH TRUNCATED':'');box.append(summary);
  const note=document.createElement('p');note.className='rtl-mapping-summary';note.textContent=data?.note||'';box.append(note);
  const filter=$('rtlMappingFilter').value;
  const rows=(data?.signals||[]).filter(r=>filter==='all'||r.status===filter);
  for(const row of rows.slice(0,250)){
   const entry=document.createElement('article');entry.className='rtl-mapping-entry';
   const name=document.createElement('strong');name.textContent=row.name;
   const detail=document.createElement('small');detail.textContent={visible_mapped:'Visible · AST source line',visible_unmapped:'Visible · no verified source location',not_in_graph:'AST signal not in current schematic slice'}[row.status]+(row.file?' · '+row.file+':'+row.line:'');
   entry.append(name,detail);
   if(row.status!=='not_in_graph'){
    const b=document.createElement('button');b.textContent='Reveal';b.onclick=()=>{const n=state.graph?.nodes.find(n=>n.id===row.id);if(n)focusSymbol(n);};entry.append(b);
   }
   if(row.in_scope_source&&row.line>0){const b=document.createElement('button');b.textContent='Source L'+row.line;b.onclick=()=>{const n=state.graph?.nodes.find(n=>n.id===row.id);if(n)selection(n);setTab('source');};entry.append(b);}
   box.append(entry);
  }
  if(rows.length>250){const notice=document.createElement('p');notice.className='rtl-mapping-summary';notice.textContent='Showing first 250 of '+rows.length+' matching AST declarations. Narrow the filter.';box.append(notice);}
 };
 $('rtlMappingFilter').onchange=drawMapping;drawMapping();
}

async function loadTab(){
 const request=++inspectorRequest,path=state.path,tab=state.tab;
 if(!state.inspector)return;
 const selectedId=tab==='details'?(state.inspectEntityId||state.selected):state.selected;
 const current=()=>request===inspectorRequest&&path===state.path&&tab===state.tab&&state.inspector;
 const selectedCurrent=()=>current()&&selectedId===(state.inspectEntityId||state.selected);
 try{
  if(tab==='mapping'){await renderMapping(current);
  }else if(tab==='connections'){renderConnections();
  }else if(tab==='references'){await renderReferences(current);
  }else if(tab==='details'){
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
   target.replaceChildren();
   inspectorCard(target,String(result.entity?.name||result.id),
    String(result.kind||'entity')+' · '+String(result.scope||state.path),
    'Elaboration: '+(result.elaboration_verified?'verified':'imported / not independently verified'));
   if(result.source?.status==='available')inspectorCard(target,'Source provenance',
    String(result.source.file)+':'+String(result.source.line||'?'),
    String(result.source.provenance||'AST-backed'));
   else inspectorCard(target,'Source provenance','No precise source mapping verified',
    String(result.source?.reason||'A source location is not available for this entity'));
   const details=document.createElement('details');details.className='rtl-inspector-evidence';
   const summary=document.createElement('summary');summary.textContent='Show full compiler evidence';
   const pre=document.createElement('pre');pre.textContent=output.join('\n');
   details.append(summary,pre);target.append(details);
  }else if(tab==='source'){
   const result=await api('source',{path});
   if(!current())return;
   $('sourceFile').textContent=result.status==='available'?result.file:'Source unavailable';
   $('rtlSourceStatus').textContent=result.status==='available'?'READ ONLY · Mapped source · '+(result.file||''):'READ ONLY · No verified source mapping';
   const help=$('sourceMappingHelp');
   const selected=inspectedItem(),wire=selected?.source&&selected?.target;
   const selectionProvenance=wire&&(!sourceSelectionNode()?.line||selected.rendered===false);
   help.hidden=result.status==='available'&&!selectionProvenance;
   help.textContent=result.status!=='available'
    ?'This scope has no accessible compiler-backed source. '+String(result.reason||'The AST did not provide a resolvable file')+'. No source location will be guessed.'
    :selectionProvenance?'Showing the module source, not an exact wire occurrence. This connection has no unique verified line or represents an AST dependency rather than an electrical net. Check References or Connections for available evidence.':'';
   showProbeChoices();const code=$('sourceCode');delete code._astNavigate;code.replaceChildren();$('lineNumbers').textContent='';const selectedNode=sourceSelectionNode();code.append(sourceEvidenceBanner(selectedNode));addOccurrenceControls(code,result,result.file);
   if(result.code){
    const fragment=document.createDocumentFragment();let syntaxState={comment:false};
    result.code.split('\n').forEach((line,i)=>{
     const highlighted=window.FlexSvHighlight?.renderLine(line,document,syntaxState);
     const span=highlighted?.span||document.createElement('span');
     if(!highlighted){span.className='code-line';span.textContent=line||' ';}
     else syntaxState=highlighted.state;
     span.dataset.line=String(i+1);fragment.append(span);
    });
    code.append(fragment);$('lineNumbers').textContent=result.code.split('\n').map((_,i)=>i+1).join('\n');
    // Lint is file-level evidence, not an inferred error on this RTL instance.
    // Annotate exact verified source lines only; stale requests must not mark a new scope.
    api('lint',{path}).then(lint=>{
     if(!current()||!window.FlexWorkbenchSemantics||!code.isConnected)return;
     const marks=window.FlexWorkbenchSemantics.lintMarks(lint,result.file,result.code.split('\n').length);
     for(const [line,entries] of marks){
      const row=code.querySelector('[data-line="'+line+'"]');if(!row)continue;
      const p=entries[0].priority.toLowerCase();row.classList.add('rtl-lint-line','rtl-lint-'+p);
      row.dataset.lintCount=String(entries.length);
      row.title=entries.map(e=>e.priority+' '+e.code+': '+e.message).join('\n');
      row.setAttribute('aria-label','Line '+line+' · '+entries.length+' file-level lint diagnostic(s)');
     }
    }).catch(()=>{});

   }else {const note=document.createElement('div');note.textContent=result.reason||'No source location';code.append(note);}
   $('inspectorFoot').textContent=result.status==='available'?'Click a source line to focus an AST symbol':'Source reference unavailable';
   window.FlexNativeEditor?.sync(path,result,selectedNode?.line||1);
   if(selectedNode?.line)focusLine(selectedNode.line,selectedNode.name);
   if(pendingLintLine){
    const targetFile=String(pendingLintFile||'').replaceAll('\\','/');
    const currentFile=String(result.file||'').replaceAll('\\','/');
    const exactFile=!!targetFile&&!!currentFile&&(targetFile===currentFile||targetFile.endsWith('/'+currentFile)||currentFile.endsWith('/'+targetFile));
    if(exactFile&&result.status==='available')focusLine(pendingLintLine,'lint diagnostic');
    else $('inspectorFoot').textContent='Lint location not highlighted: diagnostic file '+(targetFile||'unknown')+' differs from source '+(currentFile||'unavailable');
    if(pendingLintProbe&&exactFile&&result.status==='available')probeSourceLine(pendingLintLine);
    pendingLintLine=0;pendingLintFile='';pendingLintProbe=false;
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
   heading.textContent='Module diagnostics · '+moduleName;
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
   const summaryGrid=document.createElement('div');summaryGrid.className='rtl-lint-summary';
   const levels=['P0','P1','P2','P3'];
   const priority=(d)=>priorityOf(d);
   const addStat=(label,value)=>{const cell=document.createElement('div');cell.className='rtl-lint-stat';
    const number=document.createElement('strong');number.textContent=String(value);
    const title=document.createElement('span');title.textContent=label;cell.append(number,title);summaryGrid.append(cell);};
   addStat('File findings',diagnostics.length);
   for(const level of levels)addStat(level,diagnostics.filter(d=>priority(d)===level).length);
   box.append(summaryGrid);
   if(!diagnostics.length){const empty=document.createElement('p');empty.className='rtl-inspector-empty';empty.textContent='No diagnostics reported for this module source file. This is not a dedicated per-instance lint result.';box.append(empty);return;}
   const types=[...new Set(diagnostics.map(w=>String(w.severity||'unknown').toLowerCase()))].sort();
   const tools=document.createElement('div');tools.className='lint-filter-bar';
   const label=document.createElement('label');label.textContent='Severity: ';
   const selector=document.createElement('select');selector.setAttribute('aria-label','Filter lint severity');
   const search=document.createElement('input');search.type='search';search.className='rtl-lint-search';
   search.placeholder='Filter code or message';search.setAttribute('aria-label','Search lint diagnostics');
   const all=document.createElement('option');all.value='all';all.textContent='All ('+diagnostics.length+')';selector.append(all);
   for(const severity of types){const option=document.createElement('option');option.value=severity;option.textContent=severity+' ('+diagnostics.filter(d=>String(d.severity||'unknown').toLowerCase()===severity).length+')';selector.append(option);}
   label.append(selector);tools.append(label,search);box.append(tools);
   const list=document.createElement('div');box.append(list);
   const render=()=>{
    list.replaceChildren();
    for(const warning of diagnostics){
     const severity=String(warning.severity||'unknown').toLowerCase();
     if(selector.value!=='all'&&selector.value!==severity)continue;
     const searchText=(String(warning.code||'')+' '+String(warning.message||warning.text||'')).toLowerCase();
     if(!searchText.includes(search.value.trim().toLowerCase()))continue;
     const article=document.createElement('article');article.className='lint-entry';
     const code=document.createElement('code');code.textContent=severity+' · '+String(warning.code||'diagnostic');
     const message=document.createElement('span');message.textContent=' '+String(warning.message||warning.text||'No diagnostic message');
     article.append(code,message);
     const line=Number(warning.line||warning.start_line||warning.location?.line||0);
     if(Number.isSafeInteger(line)&&line>0){
      const jump=document.createElement('button');jump.type='button';jump.textContent='Open source · L'+line;
      jump.onclick=()=>{if(!current())return;pendingLintLine=line;pendingLintFile=String(warning.file||result.file||'');setTab('source');};
      article.append(document.createTextNode(' '),jump);
     const probe=document.createElement('button');probe.type='button';probe.textContent='Find in schematic';
     probe.onclick=()=>{if(!current())return;pendingLintLine=line;pendingLintFile=String(warning.file||result.file||'');pendingLintProbe=true;setTab('source');};
     article.append(document.createTextNode(' '),probe);
     }else{
      const note=document.createElement('small');note.textContent=' · no verified line';article.append(note);
     }
     list.append(article);
    }
   };
   selector.addEventListener('change',render);search.addEventListener('input',render);render();
  }else if(tab==='cone'){
   if(!current()||!state.graph)return;
   const list=state.graph.nodes.filter(n=>['port','register','counter','fsm','signal','operator'].includes(n.type));
   for(const name of ['fromSelect','toSelect']){const el=$(name),previous=el.value;el.replaceChildren();for(const n of list){const opt=document.createElement('option');opt.value=n.id;opt.textContent=n.name;el.append(opt);}if(list.some(n=>n.id===previous))el.value=previous;}
  }
 }catch(e){if(current())announce(e.message);}
}
// Right-clicking anywhere *inside* a flattened virtual group targets the
// group itself, not the module-level context menu. Prefer the smallest frame
// when groups are nested; the ordinary left-click hit testing is unchanged.
function flattenedFrameAt(p){
 if(!state.graph)return null;
 const d=layout(state.graph),v=view();
 const frames=flattenedFrames(state.graph,d.positions,d.groupRects);
 const x=p.x*v.z+v.x,y=p.y*v.z+v.y;
 const labels=frameLabelRects(frames,v,canvas.clientWidth,canvas.clientHeight);
 const within=(f)=>({id:f.token+'::unflatten',name:f.name,
  type:'frame_unflatten',group:f.token});
 for(const f of [...labels].sort((a,b)=>a.w*a.h-b.w*b.h)){
  if(x>=f.labelX&&x<=f.labelX+f.labelW&&
     y>=f.labelY&&y<=f.labelY+f.labelH)return within(f);
 }
 for(const f of [...frames].sort((a,b)=>a.w*a.h-b.w*b.h)){
  if(p.x>=f.x&&p.x<=f.x+f.w&&p.y>=f.y&&p.y<=f.y+f.h)
   return within(f);
 }
 return null;
}
function closeContext(){
 $('context').hidden=true;
 state.context=null;
}
function context(ev,item){
 ev.preventDefault();
 const frameOnly=item?.type==='frame_unflatten';
 closeContext();
 state.context=item;
 // The transparent frame is a layout/navigation artifact, not a symbol to
 // inspect or track as if it were a physical net.
 if(item&&!frameOnly)selection(item);
 const box=$('context'),r=$('schematic').getBoundingClientRect();
 $('contextTitle').hidden=frameOnly;
 $('contextTitle').textContent=item ? (item.source ? 'WIRE · '+item.net.split('::sig:').pop() + (item.mapping==='partial'?' · partial slice':'') : item.type.toUpperCase()+' · '+item.name) : 'MODULE · '+state.graph.module;
 $('contextSource').hidden=frameOnly;
 $('contextLint').hidden=frameOnly;
 $('contextEnter').hidden=frameOnly||!item?.child||item.type==='generate';
 $('contextPin').hidden=frameOnly||!(item?.net||isSignal(item));
 $('contextGenerate').hidden=frameOnly||!item?.group;
 $('contextFlatten').hidden=!(item?.group||item?.child);
 if(item?.group&&!frameOnly)$('contextGenerate').firstChild.textContent=
  item.type==='fsm_group'?'Enter FSM ':item.type==='process_group'?'Enter process ':item.type==='generate'?'Enter generate group ':
  item.fsmExpanded?'Return to parent ':item.type==='generate'?'Expand instances ':'Collapse instances ';
 if(item?.group)$('contextFlatten').firstChild.textContent=
  frameOnly||expandedGroups().has(item.group)?'Unflatten here ':'Flatten here ';
 if(item?.child&&!item.group){$('contextFlatten').disabled=true;
  $('contextFlatten').title='Direct child-scope flattening requires proven port remapping (not available in this increment)';}
 else {$('contextFlatten').disabled=false;$('contextFlatten').removeAttribute('title');}
 box.hidden=false;
 box.style.left=clamp(ev.clientX-r.left,5,Math.max(5,r.width-245))+'px';
 box.style.top=clamp(ev.clientY-r.top,5,Math.max(5,r.height-245))+'px';
}

// A flattened parent contains other virtual blocks.  Only its BACKGROUND
// and header have the Unflatten-only menu: a compact child is independently
// actionable and must keep Flatten here / Enter in its own context menu.
// Node hit testing already checks the actual ELK symbol rectangle before
// considering frames; do not let an ancestor's overlay shadow that node.
function contextTargetAt(p){
 const item=hit(p);
 if(item?.group&&['process_group','fsm_group','generate'].includes(item.type))
  return item;
 return flattenedFrameAt(p)||item;
}
canvas.addEventListener('contextmenu',ev=>{
 const p=pointer(ev);context(ev,contextTargetAt(p));
});
canvas.addEventListener('pointerdown',ev=>{hideSemanticTip();if(ev.button!==0)return;const item=hit(pointer(ev));state.drag={x:ev.clientX,y:ev.clientY,origin:{...view()},item,moved:false};canvas.setPointerCapture(ev.pointerId);});
canvas.addEventListener('pointermove',ev=>{const d=state.drag;if(d){hideSemanticTip();const dx=ev.clientX-d.x,dy=ev.clientY-d.y;if(Math.abs(dx)+Math.abs(dy)>5)d.moved=true;if(d.moved){state.manualView=true;cancelAnimationFrame(cameraAnimation);setView({...d.origin,x:d.origin.x+dx,y:d.origin.y+dy});draw();}return;}const item=hit(pointer(ev));if(item?.id!==state.hover?.id){state.hover=item;canvas.style.cursor=item?'pointer':'grab';canvas.removeAttribute('title');draw();}if(item)showSemanticTip(item,ev);else hideSemanticTip();});
canvas.addEventListener('pointerleave',hideSemanticTip);
canvas.addEventListener('wheel',hideSemanticTip,{passive:true});
let lastScopeClick=null;
canvas.addEventListener('pointerup',ev=>{const d=state.drag;state.drag=null;if(!d||d.moved)return;if(d.item?.type==='frame_unflatten'){virtualAction(state.path,d.item.group,'flatten');return;}if(d.item?.child && ev.button===0 && lastScopeClick && lastScopeClick.id===d.item.id && performance.now()-lastScopeClick.at<450){lastScopeClick=null;enter(d.item.child);return;}lastScopeClick=d.item?.child?{id:d.item.id,at:performance.now()}:null;if(d.item)selection(d.item,false,ev.ctrlKey||ev.metaKey);else if(!(ev.ctrlKey||ev.metaKey)){state.selected=null;state.multiSelected.clear();state.inspectEntityId=null;if(state.inspector&&state.tab==='details')loadTab();draw();}});
canvas.addEventListener('dblclick',ev=>{const item=hit(pointer(ev));if(item?.type==='fsm_group'||item?.type==='process_group'||item?.type==='generate'||item?.fsmExpanded)toggleGroup(item);else if(item?.child)enter(item.child);});
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
$('contextFlatten').onclick=async()=>{$('context').hidden=true;if(state.context?.group)await virtualAction(state.path,state.context.group,'flatten');};
$('contextSource').onclick=async()=>{$('context').hidden=true;if(state.context?.child)await enter(state.context.child);inspector(true,'source');};
$('contextLint').onclick=async()=>{$('context').hidden=true;if(state.context?.child)await enter(state.context.child);inspector(true,'lint');};
$('contextEnter').onclick=()=>{$('context').hidden=true;if(state.context?.child)enter(state.context.child);};
$('contextPin').onclick=()=>{$('context').hidden=true;selection(state.context,true);};
// A menu is modal only to itself: click/tap anywhere else (including the
// Canvas, toolbar or inspector), or press Escape, to dismiss it.
document.addEventListener('pointerdown',ev=>{
 if(!ev.target.closest('#context'))closeContext();
});
document.addEventListener('keydown',ev=>{
 if(ev.key==='Escape'&&!$('context').hidden){
  ev.preventDefault();closeContext();
 }
});
document.addEventListener('click',ev=>{
 if(!ev.target.closest('.search-box')&&!ev.target.closest('#searchResults'))$('searchResults').hidden=true;
});
$('toggleInspector').onclick=()=>inspector(!state.inspector,state.tab);$('closeInspector').onclick=()=>inspector(false);

$('zoomOut').onclick=()=>zoom(.82);$('zoomIn').onclick=()=>zoom(1.2);$('fit').onclick=fit;
for(const t of ['details','connections','references','mapping','source','lint','cone']){
 const tab=$(t+'Tab');
 if(tab)tab.onclick=()=>setTab(t);
 else console.warn('[FlexSoC RTL] Missing tab:',t+'Tab');
}
// Accessible roving tab stops. Do not intercept keys inside source or filter inputs.
$('inspector').querySelector('.tabs').addEventListener('keydown',ev=>{
 const inspectorTabs=['details','connections','references','mapping','source','lint','cone'];
 const tabs=inspectorTabs.map(id=>$(id+'Tab'));
 if(!tabs.includes(ev.target))return;
 const index=tabs.indexOf(ev.target);
 const next=ev.key==='Home'?0:ev.key==='End'?tabs.length-1:ev.key==='ArrowRight'?(index+1)%tabs.length:ev.key==='ArrowLeft'?(index+tabs.length-1)%tabs.length:-1;
 if(next<0)return;
 ev.preventDefault();setTab(inspectorTabs[next]);tabs[next].focus();
});
// Source-to-schematic uses the compiler location and the current elaborated scope.
let sourceProbeRequest=0;
window.FlexRTLProbeLine=probeSourceLine;
$('sourceCode').onclick=ev=>{
 const row=ev.target.closest('[data-line]');if(!row||!state.graph)return;
 probeSourceLine(Number(row.dataset.line));
};
$('rtlFreezeSchematic').onclick=()=>{
 state.freezeSchematic=!state.freezeSchematic;
 const button=$('rtlFreezeSchematic');button.setAttribute('aria-pressed',String(state.freezeSchematic));
 button.textContent=state.freezeSchematic?'🔒 Locked':'🔓 Follow';
 button.title=state.freezeSchematic?'Source navigation will not move the schematic. Reveal schematic remains available.':'Automatically reveal unique AST matches from source navigation.';
 refreshNavigationStatus(state.freezeSchematic?'Schematic locked · use Reveal to navigate':'Schematic follows unique source matches');
};
$('rtlTraceDriver').onclick=()=>{
 const result=window.FlexDriverTrace?.producer(state.graph,inspectedItem());
 if(result?.status==='unique'){
  focusSymbol(result.source);
  announce('Proven producer → '+result.source.name+' ('+(result.source.shape||result.source.kind||result.source.type)+')');
  return;
 }
 const descriptions={multiple_drivers:'More than one visible driver; no unique source',
  no_visible_driver:'No driver visible in this graph view',not_visible:'Selected signal not visible',
  unavailable:'No graph available'};
 announce(descriptions[result?.status]||'Select a signal with a verified producer');
};
$('rtlGoSchematic').onclick=()=>{
 const latest=sourceProbe?.path===state.path?probeCandidates(sourceProbe.result):[];
 if(latest.length===1){revealCandidate(latest[0]);return;}
 const node=sourceSelectionNode();
 if(node&&state.graph?.nodes.some(n=>n.id===node.id)){focusSymbol(node);return;}
 refreshNavigationStatus('Select a source line or mapped schematic signal first');
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
 if(ev.key.toLowerCase()==='k'&&(ev.ctrlKey||ev.metaKey)&&!ev.altKey){
  ev.preventDefault();$('hierarchyFilter').focus();$('hierarchyFilter').select();return;
 }
 if(ev.key==='/'&&!ev.altKey&&!ev.ctrlKey&&!ev.metaKey&&!['INPUT','TEXTAREA','SELECT'].includes(document.activeElement.tagName)&&!document.activeElement.closest('#inspector')){
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
function saveInspectorWidth(){
 const width=Math.round($('inspector').getBoundingClientRect().width);
 if(width>=300&&width<=900)try{localStorage.setItem('flexsoc-rtl-inspector-width',String(width));}catch(_e){}
}
$('inspectorResizer').addEventListener('pointerup',()=>{if(split)saveInspectorWidth();split=null;});
$('inspectorResizer').addEventListener('pointercancel',()=>{split=null;});
$('inspectorResizer').addEventListener('keydown',ev=>{
 if(!['ArrowLeft','ArrowRight'].includes(ev.key))return;
 ev.preventDefault();const width=$('inspector').getBoundingClientRect().width;
 $('inspector').style.width=clamp(width+(ev.key==='ArrowLeft'?24:-24),300,900)+'px';saveInspectorWidth();
});
try{const saved=Number(localStorage.getItem('flexsoc-rtl-inspector-width'));if(saved>=300&&saved<=900)$('inspector').style.width=saved+'px';}catch(_e){}
installThemePicker();
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
 toggle.addEventListener('click',()=>{vim=!vim;pendingG=false;toggle.textContent='Vim keys: '+(vim?'on':'off');toggle.setAttribute('aria-pressed',String(vim));if(vim)source.focus();});
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
