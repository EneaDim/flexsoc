'use strict';
/* Pure per-module RTL schematic layout. The AST graph is never mutated.
 * Rank -> four stable barycentric sweeps -> interval-packed routing channels.
 * Long/feedback nets travel above the blocks; labels remain RTL dependencies,
 * not assertions of bit-exact connectivity or physical timing.
 */
(function(root){
 const isInput=p=>['in','input','inout'].includes(p.direction);
 const isOutput=p=>['out','output','inout'].includes(p.direction);
function boxSize(n){if(n.type==='instance'||n.type==='generate'){const left=(n.ports||[]).filter(p=>['in','input'].includes(p.direction)).length;const right=(n.ports||[]).filter(p=>['out','output'].includes(p.direction)).length;return {w:220,h:Math.max(100,64+Math.max(left,right)*19)};}if(['register','counter','fsm'].includes(n.type))return {w:133,h:73};if(n.type==='operator')return {w:n.shape==='mux'?112:104,h:82};if(n.type==='port')return {w:144,h:44};return {w:170,h:n.dimensions?.unpackedDimensions?56:42};}
function baseRank(n){if(n.type==='port')return ['in','input'].includes(n.direction)?0:['out','output'].includes(n.direction)?6:2;if(n.type==='operator'||n.type==='instance'||n.type==='generate')return 3;if(['register','counter','fsm'].includes(n.type))return 4;return 2;}
// Component pin geometry is shared with Canvas. A/B are data inputs, S is
// the mux selector *below* the trapezoid, Y is the driven output.
function pinGeometry(n,rect,pin,side){
 const {x,y,w,h}=rect;
 if(['register','counter','fsm'].includes(n.type)){
  // Dedicated pins coincide with the sequential symbol drawn by Canvas.
  if(side==='out')return {x:x+w-4,y:y+20,face:'right'};
  if(pin==='CLK')return {x:x+4,y:y+h-13,face:'left'};
  if(pin==='EVENT')return {x:x+4,y:y+h-30,face:'left'};
  return {x:x+4,y:y+20,face:'left'};
 }
 if(n.type!=='operator')return null;
 if(side==='out')return {x:x+w-9,y:y+h/2,face:'right'};
 if(n.shape==='mux'){
  if(pin==='A')return {x:x+9,y:y+22,face:'left'};
  if(pin==='B')return {x:x+9,y:y+h-22,face:'left'};
  if(pin==='S')return {x:x+w/2,y:y+h-6,face:'bottom'};
 }
 if(pin==='A')return {x:x+7,y:y+23,face:'left'};
 if(pin==='B')return {x:x+7,y:y+h-23,face:'left'};
 return {x:x+7,y:y+h/2,face:'left'};
}

 function compact(points){
  const clean=points.filter((p,i)=>!i||p[0]!==points[i-1][0]||p[1]!==points[i-1][1]);
  for(let i=1;i+1<clean.length;){
   const a=clean[i-1],b=clean[i],c=clean[i+1];
   if((a[0]===b[0]&&b[0]===c[0])||(a[1]===b[1]&&b[1]===c[1]))clean.splice(i,1);
   else i++;
  }
  return clean;
 }
 // Interval partitioning: a track can be reused only for disjoint vertical
 // segments. This prevents overlay without allocating one column per wire.
 function tracks(items,clearance=9){
  const ends=[],slots=new Map();
  for(const item of [...items].sort((a,b)=>a.lo-b.lo||a.hi-b.h||String(a.id).localeCompare(String(b.id)))){
   let slot=ends.findIndex(end=>end+clearance<item.lo);
   if(slot<0){slot=ends.length;ends.push(item.hi);}else ends[slot]=item.hi;
   slots.set(item.id,slot);
  }
  return {slots,count:ends.length};
 }
 // Visual bridge metadata at perpendicular crossings of different RTL nets.
 // Sort vertical segments by x; each horizontal segment tests only the x-range
 // it spans. This avoids the quadratic all-wires-pairs scan at high parallelism.
 function bridges(paths,edges){
  const meta=new Map(edges.map(e=>[e.id,e]));
  const vertical=[],horizontal=[];
  for(const [id,points] of paths){
   for(let i=1;i<points.length;i++){
    const a=points[i-1],b=points[i];
    if(a[0]===b[0]&&Math.abs(a[1]-b[1])>16)vertical.push({id,x:a[0],lo:Math.min(a[1],b[1]),hi:Math.max(a[1],b[1])});
    else if(a[1]===b[1]&&Math.abs(a[0]-b[0])>16)horizontal.push({id,y:a[1],lo:Math.min(a[0],b[0]),hi:Math.max(a[0],b[0])});
   }
  }
  vertical.sort((a,b)=>a.x-b.x);
  const result=[],last=new Map();
  for(const h of horizontal){
   let low=0,high=vertical.length;
   while(low<high){const mid=(low+high)>>1;if(vertical[mid].x<h.lo+8)low=mid+1;else high=mid;}
   for(let i=low;i<vertical.length&&vertical[i].x<h.hi-8;i++){
    const v=vertical[i],x=v.x;
    if(v.id===h.id||h.y<=v.lo+8||h.y>=v.hi-8)continue;
    const first=meta.get(h.id),second=meta.get(v.id);
    if(first?.net&&first.net===second?.net)continue;
    if(x-(last.get(h.id)||-Infinity)<13)continue;
    result.push({edge:h.id,x,y:h.y});last.set(h.id,x);
    if(result.length>=3000)return result;
   }
  }
  return result;
 }
 // Conservative geometry verifier + bounded congestion-aware rerouter.
 // Only geometry changes: RTL edge direction and identity are never inferred
 // from coordinates. We score box intersections and distinct-net overlapping
 // conductors independently of line crossings (which have explicit bridges).
 function segments(points){
  return points.slice(1).map((b,i)=>({a:points[i],b})).filter(s=>s.a[0]!==s.b[0]||s.a[1]!==s.b[1]);
 }
 function rectHit(segment,rect){
  const {a,b}=segment,margin=2;
  if(a[0]===b[0])return a[0]>rect.x+margin&&a[0]<rect.x+rect.w-margin&&
     Math.max(a[1],b[1])>rect.y+margin&&Math.min(a[1],b[1])<rect.y+rect.h-margin;
  if(a[1]===b[1])return a[1]>rect.y+margin&&a[1]<rect.y+rect.h-margin&&
     Math.max(a[0],b[0])>rect.x+margin&&Math.min(a[0],b[0])<rect.x+rect.w-margin;
  return true; // diagonal segments are invalid in a Manhattan router
 }
 function sharedLength(first,second){
  if(first.a[1]===first.b[1]&&second.a[1]===second.b[1]&&Math.abs(first.a[1]-second.a[1])<4)
   return Math.max(0,Math.min(Math.max(first.a[0],first.b[0]),Math.max(second.a[0],second.b[0]))-
    Math.max(Math.min(first.a[0],first.b[0]),Math.min(second.a[0],second.b[0])));
  if(first.a[0]===first.b[0]&&second.a[0]===second.b[0]&&Math.abs(first.a[0]-second.a[0])<4)
   return Math.max(0,Math.min(Math.max(first.a[1],first.b[1]),Math.max(second.a[1],second.b[1]))-
    Math.max(Math.min(first.a[1],first.b[1]),Math.min(second.a[1],second.b[1])));
  return 0;
 }
 function geometryScore(id,points,nodes,accepted,meta){
  const edge=meta.get(id),lines=segments(points);let boxHits=0,overlap=0;
  for(const s of lines)for(const [node,rect] of nodes){
   if(node!==edge?.source&&node!==edge?.target&&rectHit(s,rect))boxHits++;
  }
  for(const [other,prior] of accepted){
   const previous=meta.get(other);
   if(edge?.net&&edge.net===previous?.net)continue; // electrically same net may share a conductor
   for(const line of lines)for(const priorLine of segments(prior))overlap+=Math.max(0,sharedLength(line,priorLine)-8);
  }
  const length=lines.reduce((sum,s)=>sum+Math.abs(s.a[0]-s.b[0])+Math.abs(s.a[1]-s.b[1]),0);
  return {boxHits,overlap,length,score:boxHits*100000+overlap*800+length};
 }
 // Spatially indexed design-rule check. Unlike the old global O(E²)
 // scan, this also runs when a parallel design has hundreds of wires.
 // Source/target pin stubs are allowed to touch their own symbol; crossings
 // and unrelated-net overlaps are evaluated separately.
 class RoutingOccupancy {
  constructor(positions,meta,cell=160){
   this.cell=cell;this.positions=positions;this.meta=meta;
   this.boxes=new Map();this.wires=new Map();
   for(const [id,box] of positions)
    this._put(this.boxes,box.x,box.y,box.x+box.w,box.y+box.h,{id,box});
  }
  _cells(x0,y0,x1,y1){
   const xlo=Math.floor(Math.min(x0,x1)/this.cell),xhi=Math.floor(Math.max(x0,x1)/this.cell);
   const ylo=Math.floor(Math.min(y0,y1)/this.cell),yhi=Math.floor(Math.max(y0,y1)/this.cell);
   const out=[];for(let x=xlo;x<=xhi;x++)for(let y=ylo;y<=yhi;y++)out.push(x+':'+y);
   return out;
  }
  _put(map,x0,y0,x1,y1,item){
   for(const key of this._cells(x0,y0,x1,y1)){
    if(!map.has(key))map.set(key,[]);
    map.get(key).push(item);
   }
  }
  _around(map,segment){
   const result=new Set();
   for(const key of this._cells(segment.a[0]-3,segment.a[1]-3,segment.b[0]+3,segment.b[1]+3))
    for(const hit of map.get(key)||[])result.add(hit);
   return result;
  }
  add(id,polyline){
   for(const segment of segments(polyline))
    this._put(this.wires,segment.a[0],segment.a[1],segment.b[0],segment.b[1],{id,segment});
  }
  score(id,polyline){
   const edge=this.meta.get(id),lines=segments(polyline);let boxHits=0,overlap=0,length=0;
   for(const segment of lines){
    length+=Math.abs(segment.a[0]-segment.b[0])+Math.abs(segment.a[1]-segment.b[1]);
    for(const {id:node,box} of this._around(this.boxes,segment))
     if(node!==edge?.source&&node!==edge?.target&&rectHit(segment,box))boxHits++;
    for(const {id:other,segment:prior} of this._around(this.wires,segment)){
     const previous=this.meta.get(other);
     if(edge?.net&&edge.net===previous?.net)continue;
     overlap+=Math.max(0,sharedLength(segment,prior)-8);
    }
   }
   return {boxHits,overlap,length,score:boxHits*100000+overlap*800+length};
  }
 }
 function refine(graph,positions,paths,height,{maxEdges=5000}={}){
  const meta=new Map(graph.edges.map(e=>[e.id,e]));
  const accepted=new Map(), occupancy=new RoutingOccupancy(positions,meta);
  let before=0,after=0,adjusted=0;
  // If a graph exceeds the bounded interactive routing budget, flag it
  // visibly instead of claiming it was collision-checked.
  if(paths.size>maxEdges)return {paths,stats:{refined:0,skipped:paths.size,quality:'not_audited'}};
  const order=[...paths.keys()].sort();
  for(const id of order){
   const original=paths.get(id);
   const baseline=occupancy.score(id,original);
   before+=baseline.boxHits;
   let best=original,bestScore=baseline;
   if(baseline.boxHits||baseline.overlap>15){
    const from=positions.get(meta.get(id).source),to=positions.get(meta.get(id).target);
    const start=original[0],end=original[original.length-1];
    if(meta.get(id).pin==='S' && meta.get(id).target &&
       graph.nodes.some(n=>n.id===meta.get(id).target && n.shape==='mux')){
     // Every alternative must enter S vertically from *below*. A shortest
     // path from above / the side changes circuit semantics visually.
     for(let track=0;track<(paths.size>500?4:12);track++){
      const below=to.y+to.h+20+track*14;
      for(const side of [-1,1]){
       const exit=side<0?from.x-26-track*10:from.x+from.w+26+track*10;
       const candidate=compact([start,[exit,start[1]],[exit,below],[end[0],below],end]);
       const score=occupancy.score(id,candidate);
       if(score.score<bestScore.score){best=candidate;bestScore=score;}
      }
     }
    }else if(['A','B'].includes(meta.get(id).pin) &&
             graph.nodes.some(n=>n.id===meta.get(id).target && n.type==='operator')){
     // A/B functional inputs must be approached from the left even when
     // their logical driver is drawn in a column to the right.
     for(let track=0;track<(paths.size>500?4:12);track++){
      const entry=to.x-20-track*12;
      for(const rail of [Math.max(12,to.y-28-track*14),to.y+to.h+28+track*14]){
       const exit=from.x+from.w+22+track*8;
       const candidate=compact([start,[exit,start[1]],[exit,rail],[entry,rail],[entry,end[1]],end]);
       const score=occupancy.score(id,candidate);
       if(score.score<bestScore.score){best=candidate;bestScore=score;}
      }
     }
    }else{
    // For a plain signal/operator endpoint, the glyph has no fixed named
    // port, so a congested route may enter via the opposite face. Named
    // instance ports must retain the face chosen by the AST binding.
    const landing=[end];
    if(!meta.get(id).port){
     landing.push([to.x+(end[0]>to.x+to.w/2?8:to.w-8),end[1]]);
    }
    for(const finish of landing){
     const leaving=start[0]>from.x+from.w/2?1:-1;
     const entering=finish[0]>to.x+to.w/2?1:-1;
     // Prefer a short, obstacle-free side channel before a long detour to
     // the top/bottom rail; it preserves visual locality for same-rank nets.
     for(let track=0;track<(paths.size>500?3:6);track++){
      const left=Math.max(16,Math.min(from.x,to.x)-24-track*18);
      const right=Math.max(from.x+from.w,to.x+to.w)+24+track*18;
      for(const x of [left,right]){
       const candidate=compact([start,[x,start[1]],[x,finish[1]],finish]);
       const score=occupancy.score(id,candidate);
       if(score.score<bestScore.score){best=candidate;bestScore=score;}
      }
     }
     for(let track=0;track<(paths.size>500?4:8);track++)for(const rail of [
      Math.max(16,Math.min(start[1],finish[1])-48-track*14),
      Math.max(start[1],finish[1])+48+track*14,
      18+track*12,height+24+track*12]){
      const x0=start[0]+leaving*(26+track*7),x1=finish[0]+entering*(26+track*7);
      const candidate=compact([start,[x0,start[1]],[x0,rail],[x1,rail],[x1,finish[1]],finish]);
      const score=geometryScore(id,candidate,positions,accepted,meta);
      if(score.score<bestScore.score){best=candidate;bestScore=score;}
     }
    }
    }
   }
   if(best!==original)adjusted++;
   after+=bestScore.boxHits;
   accepted.set(id,best);
   occupancy.add(id,best);
  }
  return {paths:accepted,stats:{refined:adjusted,nodeConflictsBefore:before,nodeConflictsAfter:after,skipped:0,quality:'audited'}};
 }
 function compute(graph,{boxSize,baseRank}){
  const nodes=new Map(graph.nodes.map(n=>[n.id,n]));
  const rank=new Map(graph.nodes.map(n=>[n.id,baseRank(n)]));
  // Bounded relaxation avoids unbounded ranks on combinational feedback.
  for(let round=0;round<3;round++){
   let updated=false;
   for(const e of graph.edges){
    const target=nodes.get(e.target);
    if(!target||target.type==='port'||!nodes.has(e.source))continue;
    const candidate=Math.min(5,(rank.get(e.source)??2)+1);
    if(candidate>rank.get(e.target)){rank.set(e.target,candidate);updated=true;}
   }
   if(!updated)break;
  }
  const columns=Array.from({length:7},()=>[]);
  for(const n of graph.nodes)columns[rank.get(n.id)].push(n);
  const inputs=new Map(),outputs=new Map();
  for(const e of graph.edges){
   if(!nodes.has(e.source)||!nodes.has(e.target))continue;
   if(!inputs.has(e.target))inputs.set(e.target,[]);
   if(!outputs.has(e.source))outputs.set(e.source,[]);
   inputs.get(e.target).push(e.source);outputs.get(e.source).push(e.target);
  }
  // Two-way sweeps reduce crossings compared with an input-order-only sort.
  // Sorting stays stable for unconnected nodes and does not scan E per compare.
  for(let sweep=0;sweep<4;sweep++){
   const forward=sweep%2===0;
   const order=new Map();columns.forEach(col=>col.forEach((n,i)=>order.set(n.id,i)));
   const first=forward?1:5,last=forward?6:0,step=forward?1:-1;
   for(let c=first;forward?c<=last:c>=last;c+=step){
    const reference=forward?inputs:outputs,weights=new Map();
    for(const n of columns[c]){
     const neighbor=(reference.get(n.id)||[]).filter(id=>rank.get(id)===c-step);
     weights.set(n.id,neighbor.length?neighbor.reduce((a,id)=>a+order.get(id),0)/neighbor.length:order.get(n.id));
    }
    columns[c].sort((a,b)=>weights.get(a.id)-weights.get(b.id)||order.get(a.id)-order.get(b.id));
    columns[c].forEach((n,i)=>order.set(n.id,i));
   }
  }
  const widths=columns.map(col=>Math.max(165,...col.map(n=>boxSize(n).w)));
  // Position Y before allocating tracks; X depends only on required tracks.
  const localY=new Map();let contentHeight=200;
  // Shared row baselines align parallel datapaths even when register and module
  // symbols have different heights. Per-column independent spacing would turn
  // a 180-lane straight bus into 180 overlapping diagonal spans.
  const rows=Math.max(0,...columns.map(col=>col.length));
  let rowY=0;const corridorRows=[];
  for(let i=0;i<rows;i++){
   let rowHeight=0;
   for(const col of columns){
    if(!col[i])continue;
    const d=boxSize(col[i]);rowHeight=Math.max(rowHeight,d.h);
    localY.set(col[i].id,{y:rowY,h:d.h,w:d.w});
   }
   // Three parallel tracks fit inside the 46px gap between aligned rows.
   corridorRows.push([rowY+rowHeight+9,rowY+rowHeight+21,rowY+rowHeight+33]);
   rowY+=rowHeight+46;
  }
  contentHeight=Math.max(contentHeight,rowY+70);
  // Spread fanout/fanin stubs over the symbol boundary. Dedicated module ports
  // preserve their exact symbol pin position, even with multiple fanouts.
  const orderEdges=(ids,other)=>ids.sort((a,b)=>{
   const p=localY.get(other(a)),q=localY.get(other(b));
   return ((p?.y||0)+(p?.h||0)/2)-((q?.y||0)+(q?.h||0)/2)||a.id.localeCompare(b.id);
  });
  const outgoing=new Map(),incoming=new Map(),departures=new Map(),arrivals=new Map();
  for(const e of graph.edges){
   if(!nodes.has(e.source)||!nodes.has(e.target))continue;
   if(!outgoing.has(e.source))outgoing.set(e.source,[]);
   if(!incoming.has(e.target))incoming.set(e.target,[]);
   outgoing.get(e.source).push(e);incoming.get(e.target).push(e);
  }
  const edgeAnchor=(n,edge,side,idx,total)=>{
   const rect=localY.get(n.id);
   const componentPin=pinGeometry(n,{x:0,y:rect.y,w:rect.w,h:rect.h},edge.pin,side);
   if(componentPin)return componentPin.y;
   if(['instance','generate'].includes(n.type)&&edge.port){
    const portList=(n.ports||[]).filter(side==='out'?isOutput:isInput);
    const pos=portList.findIndex(p=>p.name===edge.port);
    if(pos>=0)return rect.y+(side==='out'?65:53)+19*pos;
   }
   return rect.y+rect.h/2+Math.max(-rect.h*.32,Math.min(rect.h*.32,(idx-(total-1)/2)*5));
  };
  for(const [id,edges] of outgoing){
   orderEdges(edges,e=>e.target);
   edges.forEach((e,i)=>departures.set(e.id,edgeAnchor(nodes.get(id),e,'out',i,edges.length)));
  }
  for(const [id,edges] of incoming){
   orderEdges(edges,e=>e.source);
   edges.forEach((e,i)=>arrivals.set(e.id,edgeAnchor(nodes.get(id),e,'in',i,edges.length)));
  }
  const gaps=Array.from({length:7},()=>[]),overhead=[];
  for(const e of graph.edges){
   if(!departures.has(e.id))continue;
   const ra=rank.get(e.source),rb=rank.get(e.target),ya=departures.get(e.id),yb=arrivals.get(e.id);
   if(rb===ra+1)gaps[ra].push({id:e.id,lo:Math.min(ya,yb),hi:Math.max(ya,yb)});
   else overhead.push({id:e.id,lo:Math.min(ra,rb),hi:Math.max(ra,rb)+.1});
  }
  const packed=gaps.map(group=>tracks(group,12));
  // Long and feedback wires first try *free inter-row corridors*. Their
  // horizontal portion crosses all intermediate columns without touching a
  // symbol. Reserving rank-span intervals prevents separate nets from sharing
  // the same corridor track where their spans overlap.
  const corridors=new Map(),used=new Map(),fallback=[];
  const choices=corridorRows.slice(0,-1).flat();
  for(const wire of overhead){
   const y0=departures.get(wire.id),y1=arrivals.get(wire.id);
   const candidates=[...choices].sort((a,b)=>Math.abs(a-y0)+Math.abs(a-y1)-Math.abs(b-y0)-Math.abs(b-y1)||a-b);
   let chosen=null;
   for(const y of candidates){
    const reserved=used.get(y)||[];
    if(reserved.some(w=>wire.lo<=w.hi&&w.lo<=wire.hi))continue;
    chosen=y;reserved.push(wire);used.set(y,reserved);break;
   }
   if(chosen===null)fallback.push(wire);else corridors.set(wire.id,chosen);
  }
  // Overflow takes the top duct; unlike the old router, only those nets
  // consume vertical space above the diagram.
  const topRails=tracks(fallback,.01);
  const topOffset=94+topRails.count*17;
  const start=[];let right=48;
  columns.forEach((col,c)=>{
   start[c]=right;
   if(col.length)right+=widths[c]+Math.max(98,54+packed[c].count*15);
  });
  const positions=new Map();
  for(const col of columns)for(const n of col){
   const p=localY.get(n.id);positions.set(n.id,{x:start[rank.get(n.id)],y:p.y+topOffset,w:p.w,h:p.h});
  }
  const edgePaths=new Map(),portFaces=new Map();
  for(const e of graph.edges){
   const from=positions.get(e.source),to=positions.get(e.target);
   if(!from||!to)continue;
   const ra=rank.get(e.source),rb=rank.get(e.target);
   // A backward connection must really flow right -> left, including its
   // arrowhead. Its source leaves the LEFT face; the sink receives on its
   // RIGHT face. Pin face is exported for the component renderer.
   const backward=rb<=ra && from.x>=to.x;
   const sourcePin=pinGeometry(nodes.get(e.source),from,e.pin,'out');
   const sinkPin=pinGeometry(nodes.get(e.target),to,e.pin,'in');
   const x0=sourcePin?.x??(backward?from.x+8:from.x+from.w-8);
   const x1=sinkPin?.x??(backward?to.x+to.w-8:to.x+8);
   const y0=sourcePin?.y??(departures.get(e.id)+topOffset);
   const y1=sinkPin?.y??(arrivals.get(e.id)+topOffset);
   let path;
   if(sinkPin?.face==='bottom'){
    // The select pin is bottom-facing. Approach from *below*, so the wire
    // cannot masquerade as a data input or pass through the mux body.
    const below=to.y+to.h+20;
    const exit=from.x+from.w+22;
    path=[[x0,y0],[exit,y0],[exit,below],[x1,below],[x1,y1]];
   }else if(sinkPin?.face==='left' && backward){
    // Real drivers may be to the right of their consumers. Keep the AST
    // direction but enter functional-symbol data pins from their left face.
    const exit=from.x+from.w+23;
    const entry=to.x-22;
    const rail=Math.max(14,to.y-34);
    path=[[x0,y0],[exit,y0],[exit,rail],[entry,rail],[entry,y1],[x1,y1]];
   }else if(rb===ra+1&&!backward){
    const track=packed[ra].slots.get(e.id);
    const channel=start[ra]+widths[ra]+22+track*15;
    path=[[x0,y0],[channel,y0],[channel,y1],[x1,y1]];
   }else{
    const fallbackTrack=topRails.slots.get(e.id);
    const track=fallbackTrack??0;
    const rail=corridors.has(e.id)?corridors.get(e.id)+topOffset:60+track*17;
    // Source exit in the next free gap; target entry in the prior free gap.
    // Both are outside the module bounding boxes, even on backward edges.
    const exit=backward?from.x-22-(track%3)*7:from.x+from.w+22+(track%3)*7;
    const entry=backward?to.x+to.w+23+(track%3)*7:to.x-23-(track%3)*7;
    path=[[x0,y0],[exit,y0],[exit,rail],[entry,rail],[entry,y1],[x1,y1]];
   }
   edgePaths.set(e.id,compact(path));
   if(e.port){
    const instance=e.type==='port_out'?e.source:e.target;
    if(nodes.get(instance)?.type==='instance'||nodes.get(instance)?.type==='generate')
     portFaces.set(instance+'::'+e.port,backward?(e.type==='port_out'?'left':'right'):(e.type==='port_out'?'right':'left'));
   }
  }
  const polished=refine(graph,positions,edgePaths,contentHeight+topOffset);
  // Include repaired detours in the canvas extents; otherwise Fit can clip
  // a valid net routed below or to the right of the original layout.
  let routedWidth=Math.max(530,right),routedHeight=contentHeight+topOffset;
  for(const points of polished.paths.values())for(const [x,y] of points){
   routedWidth=Math.max(routedWidth,x+44);routedHeight=Math.max(routedHeight,y+44);
  }
  return {positions,edgePaths:polished.paths,portFaces,bridges:bridges(polished.paths,graph.edges),width:routedWidth,height:routedHeight,
   stats:{channelTracks:packed.reduce((sum,p)=>sum+p.count,0),corridorWires:corridors.size,overheadTracks:topRails.count,...polished.stats}};
 }
 const api={compute,tracks,bridges,geometryScore,refine,RoutingOccupancy,boxSize,baseRank,pinGeometry};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexRouting=api;
})(typeof window==='object'?window:globalThis);
