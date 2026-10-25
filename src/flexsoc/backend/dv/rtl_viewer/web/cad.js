'use strict';
(() => {
 const svg=document.getElementById('schematic'), nav=document.getElementById('hierarchy');
 const NS='http://www.w3.org/2000/svg';let current='/', view=null;
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
  for(const c of layout.components){const g=el('g');g.append(el('rect',{x:c.x,y:c.y,width:c.w,height:c.h,rx:8,class:'component'}));
   g.append(el('text',{x:c.x+12,y:c.y+23,class:'component-label'},c.name));
   g.append(el('text',{x:c.x+12,y:c.y+43,class:'component-type'},c.module));
   g.style.cursor='pointer';g.addEventListener('dblclick',()=>navigate(c.id));svg.append(g);
  }
  for(const p of layout.pins){const g=el('g');g.append(el('circle',{cx:p.x,cy:p.y,r:3,class:'pin'}));
   g.append(el('text',{x:p.side==='left'?p.x+8:p.side==='right'?p.x-8:p.x+12,y:p.y-7,
    'text-anchor':p.side==='right'?'end':'start',class:p.side==='port'?'port-label':'pin-label'},p.name));
   svg.append(g);
  }
  document.getElementById('status').textContent=`${graph.components.length} instances · ${graph.nets.length} nets · ${graph.integrity.status||'integrity checked'}`;
 }
 async function navigate(path){try{current=path;document.getElementById('scope').textContent=path;
  const [graph,source]=await Promise.all([query('schematic',path),query('source',path)]);render(graph);
  document.getElementById('filename').textContent=source.file||source.reason||'Source unavailable';document.getElementById('source').textContent=source.code||'';
  nav.replaceChildren();const root=document.createElement('button');root.textContent='Top /';root.onclick=()=>navigate('/');nav.append(root);
  const up=path.split('/').slice(0,-1).join('/')||'/';if(path!=='/'){const b=document.createElement('button');b.textContent='↑ Parent';b.onclick=()=>navigate(up);nav.append(b);}
  for(const c of graph.components){const b=document.createElement('button');b.textContent=c.name+' · '+c.module;b.onclick=()=>navigate(c.id);nav.append(b);}
 }catch(e){document.getElementById('status').textContent='Error: '+e.message;}}
 document.getElementById('fit').onclick=()=>{if(view)svg.setAttribute('viewBox',view);};
 navigate('/');
})();
