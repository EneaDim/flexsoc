'use strict';
(() => {
 const svg=document.getElementById('schematic'), nav=document.getElementById('hierarchy');
 const NS='http://www.w3.org/2000/svg';let current='/', view=null, navigationId=0;
 const viewport=new Map();let homeView=null;
 const el=(tag,attrs={},text='')=>{const n=document.createElementNS(NS,tag);for(const [k,v] of Object.entries(attrs))n.setAttribute(k,String(v));if(text)n.textContent=text;return n;};
 const query=async (name,path)=>{const r=await fetch('/api/'+name+'?path='+encodeURIComponent(path));const x=await r.json();if(!r.ok)throw Error(x.error||r.status);return x;};
 function render(graph){svg.replaceChildren();const layout=FlexCADLayout.compute(graph);const {w,h}=layout.bounds;view=`0 0 ${w} ${h}`;svg.setAttribute('viewBox',view);
  const wires=el('g');svg.append(wires);
  for(const net of layout.nets){const group=el('g',{'data-net':net.id});const partial=!net.complete;
   const line=points=>group.append(el('polyline',{points:points.map(p=>p.join(',')).join(' '),class:'net'+(partial?' partial':'')}));
   if(net.trunk[0][1]!==net.trunk[1][1])line(net.trunk);
   for(const branch of net.branches)line(branch.points);
   for(const [x,y] of net.junctions)group.append(el('circle',{cx:x,cy:y,r:3,class:'junction'}));
   group.append(el('title',{},net.name+' · '+net.type+(partial?' · partial binding':'')));wires.append(group);
  }
  // Draw one shared physical stub per pin, before the net forks.
  const stems=el('g',{'data-layer':'shared-pin-stubs'});
  for(const stub of layout.stubs||[])stems.append(el('polyline',{
   points:stub.points.map(p=>p.join(',')).join(' '),class:'net'}));
  wires.append(stems);
  // Draw an insulated bridge over foreign trunks; never add a junction dot.
  // The CSS background is inherited from the schematic's computed theme.
  const backing=getComputedStyle(svg).backgroundColor;
  const netsById=new Map(layout.nets.map(n=>[n.id,n]));
  for(const crossing of layout.crossings||[]){
   const owner=netsById.get(crossing.net);
   if(!owner)continue;
   const g=el('g',{'data-crossing':crossing.net});
   g.append(el('line',{x1:crossing.x-6,y1:crossing.y,x2:crossing.x+6,y2:crossing.y,
    stroke:backing, 'stroke-width':7}));
   g.append(el('line',{x1:crossing.x-7,y1:crossing.y,x2:crossing.x+7,y2:crossing.y,
    class:'net'+(!owner.complete?' partial':''),fill:'none'}));
   wires.append(g);
  }
  for(const c of layout.components){const g=el('g');g.append(el('rect',{x:c.x,y:c.y,width:c.w,height:c.h,rx:8,class:'component'}));
   g.append(el('text',{x:c.x+12,y:c.y+23,class:'component-label'},c.name));
   g.append(el('text',{x:c.x+12,y:c.y+43,class:'component-type'},c.module));
   g.style.cursor='pointer';g.addEventListener('dblclick',()=>navigate(c.id));svg.append(g);
  }
  for(const p of layout.pins){const g=el('g');g.append(el('circle',{cx:p.x,cy:p.y,r:3,class:'pin'}));
   g.append(el('text',{x:p.side==='left'?p.x+8:p.side==='right'?p.x-8:p.x+12,y:p.y-7,
    'text-anchor':p.side==='right'?'end':'start',class:p.scopePort?'port-label':'pin-label'},p.name));
   svg.append(g);
  }
  homeView=view; if(viewport.has(current))svg.setAttribute('viewBox',viewport.get(current));
  document.getElementById('status').textContent=`${graph.components.length} instances · ${graph.nets.length} nets · ${graph.integrity.status||'integrity checked'}`;
 }
 async function navigate(path,{history=true}={}){
  const request=++navigationId;
  if(view)viewport.set(current,svg.getAttribute('viewBox'));
  document.getElementById('status').textContent='Loading ' + path + '…';
  try {
  const [graph,source]=await Promise.all([query('schematic',path),query('source',path)]);
  // A slower, obsolete request must never replace a newer selected scope.
  if(request!==navigationId)return;
  current=path;document.getElementById('scope').textContent=path;
  render(graph);
  if(history && window.history && window.history.pushState)
    window.history.pushState({scope:path},'', '#scope='+encodeURIComponent(path));
  document.getElementById('filename').textContent=source.file||source.reason||'Source unavailable';document.getElementById('source').textContent=source.code||'';
  nav.replaceChildren();const root=document.createElement('button');root.textContent='Top /';root.onclick=()=>navigate('/');nav.append(root);
  const up=path.split('/').slice(0,-1).join('/')||'/';if(path!=='/'){const b=document.createElement('button');b.textContent='↑ Parent';b.onclick=()=>navigate(up);nav.append(b);}
  for(const c of graph.components){const b=document.createElement('button');b.textContent=c.name+' · '+c.module;b.onclick=()=>navigate(c.id);nav.append(b);}
 }catch(e){if(request===navigationId)document.getElementById('status').textContent='Error: '+e.message;}}
 document.getElementById('fit').onclick=()=>{if(homeView){svg.setAttribute('viewBox',homeView);viewport.set(current,homeView);}};
 // Browser navigation is scope-aware, including forward/back after a deep link.
 window.addEventListener('popstate',()=>{
  const hash=new URLSearchParams(location.hash.slice(1));
  navigate(hash.get('scope')||'/',{history:false});
 });
 const initial=new URLSearchParams(location.hash.slice(1)).get('scope')||'/';
 navigate(initial,{history:false});
})();
