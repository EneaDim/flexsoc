'use strict';
/* FSRTL-0061: layout-only rectilinear net-tree consolidation.
   Never changes graph nodes, edges, net ids, pin sides or source locations.
   ELK controls placement; this module only reconstructs fanout geometry.
   A route is accepted only when all its segments avoid unrelated symbols. */
(function(root){
 const same=(a,b)=>Math.abs(a-b)<0.001;
 const key=p=>p[0]+','+p[1];
 const dist=(a,b)=>Math.abs(a[0]-b[0])+Math.abs(a[1]-b[1]);
 const compact=points=>{
  const out=[];for(const p of points){if(!out.length||key(out[out.length-1])!==key(p))out.push(p);}
  for(let i=1;i+1<out.length;){const a=out[i-1],b=out[i],c=out[i+1];if((same(a[0],b[0])&&same(b[0],c[0]))||(same(a[1],b[1])&&same(b[1],c[1])))out.splice(i,1);else i++;}
  return out;
 };
 const inside=(p,r)=>p[0]>r.x&&p[0]<r.x+r.w&&p[1]>r.y&&p[1]<r.y+r.h;
 function clear(a,b,boxes,source,target){
  if(a[0]!==b[0]&&a[1]!==b[1])return false;
  for(const [id,r] of boxes){
   if(id===source||id===target)continue;
   const pad=7,L=r.x-pad,R=r.x+r.w+pad,T=r.y-pad,B=r.y+r.h+pad;
   if(a[1]===b[1]&&a[1]>T&&a[1]<B&&Math.max(a[0],b[0])>L&&Math.min(a[0],b[0])<R)return false;
   if(a[0]===b[0]&&a[0]>L&&a[0]<R&&Math.max(a[1],b[1])>T&&Math.min(a[1],b[1])<B)return false;
  }
  return true;
 }
 function line(path){for(let i=1;i<path.length;i++)if(path[i][0]!==path[i-1][0]&&path[i][1]!==path[i-1][1])return false;return true;}
 function findRoute(a,b,boxes,source,target,existing){
  // Sparse coordinate mesh: obstacle edges, known nodes and the shared tree.
  // Bounded to prevent a pathological SoC from blocking the main thread.
  const xs=new Set([a[0],b[0]]),ys=new Set([a[1],b[1]]);
  for(const r of boxes.values()){
   for(const x of [r.x-14,r.x+r.w+14])xs.add(x);
   for(const y of [r.y-14,r.y+r.h+14])ys.add(y);
  }
  for(const p of existing){xs.add(p[0]);ys.add(p[1]);}
  const X=[...xs].sort((x,y)=>x-y),Y=[...ys].sort((x,y)=>x-y);
  if(X.length*Y.length>22000)return null;
  const nx=X.length,ny=Y.length,idx=(i,j)=>i*ny+j;
  const xi=new Map(X.map((v,i)=>[v,i])),yi=new Map(Y.map((v,i)=>[v,i]));
  const start=idx(xi.get(a[0]),yi.get(a[1])),goal=idx(xi.get(b[0]),yi.get(b[1]));
  const best=new Map([[start,0]]),parent=new Map(),open=[[0,start]],visited=new Set();
  // A* with turn penalty; attach to existing geometry where practical.
  let iterations=0;
  const onTree=new Set(existing.map(key));
  while(open.length&&iterations++<22000){
   open.sort((u,v)=>u[0]-v[0]);const [,v]=open.shift();if(visited.has(v))continue;visited.add(v);
   if(v===goal){const result=[];let cur=v;for(;;){result.push([X[Math.floor(cur/ny)],Y[cur%ny]]);if(cur===start)break;cur=parent.get(cur);if(cur===undefined)return null;}result.reverse();return compact(result);}
   const i=Math.floor(v/ny),j=v%ny,p=[X[i],Y[j]];
   for(const [ii,jj] of [[i-1,j],[i+1,j],[i,j-1],[i,j+1]]){
    if(ii<0||ii>=nx||jj<0||jj>=ny)continue;
    const q=[X[ii],Y[jj]],n=idx(ii,jj);
    if(visited.has(n)||!clear(p,q,boxes,source,target))continue;
    const cost=best.get(v)+dist(p,q)+(onTree.has(key(q))?0:2);
    if(cost<(best.get(n)??Infinity)){best.set(n,cost);parent.set(n,v);open.push([cost+dist(q,b),n]);}
   }
  }
  return null;
 }
 function consolidate(graph,geometry){
  // Physical topology is net + source-terminal. ELK's individual bend points
  // are not electrical topology; only the actual endpoint anchors are reused.
  const paths=new Map(geometry.edgePaths), boxes=geometry.positions;
  const stats={treeNets:0,treeFallbacks:0,treeInvalidSinkPins:0,
   treeOriginMismatches:0,treeMissingRoutes:0,treeTerminalCount:0,
   treeStrictErrors:0};
  const groups=new Map();
  const valid=p=>Array.isArray(p)&&p.length>=2&&p.every(q=>Array.isArray(q)&&q.length===2&&q.every(Number.isFinite));
  const near=(a,b)=>Math.abs(a-b)<.01;
  const samePt=(a,b)=>near(a[0],b[0])&&near(a[1],b[1]);
  const errors=[];
  for(const e of graph.edges||[]){
   const p=paths.get(e.id);
   if(!valid(p)){stats.treeMissingRoutes++;errors.push('missing edge geometry '+e.id);continue;}
   if(!e.net)continue;
   // Never group distinct source physical terminals, even on one net.
   const pin=String(e.sourcePin||e.source_port||e.sourcePort||'');
   const k=JSON.stringify([e.net,e.source,pin]);
   if(!groups.has(k))groups.set(k,[]);
   groups.get(k).push({e,p,origin:p[0],end:p.at(-1)});
  }
  const busy=[];
  const pointsOf=p=>p.map(q=>[q[0],q[1]]);
  const safePath=(p,source,target)=>valid(p)&&p.slice(1).every((q,i)=>clear(p[i],q,boxes,source,target));
  const nodes=graph.nodes||[];
  const nodeById=new Map(nodes.map(n=>[n.id,n]));
  const leftSink=(edge,end)=>{
   const r=boxes.get(edge.target),n=nodeById.get(edge.target);
   if(!r||!n)return null;
   const pin=String(edge.targetPin||edge.target_port||edge.pin||edge.port||'').toUpperCase();
   const event=edge.type==='event'||/^(CLK|CLOCK|EVENT|RST|RESET|S|SEL|SELECT)$/.test(pin);
   if(event && n.type!=='port' && near(end[1],r.y+r.h))return 'bottom';
   if(near(end[0],r.x))return 'left';
   if(n.type==='port'&&near(end[0],r.x+7))return 'left';
   return null;
  };
  for(const [id,items] of [...groups].sort(([a],[b])=>a.localeCompare(b))){
   stats.treeTerminalCount+=items.length;
   if(items.length<2)continue;
   const source=items[0].e.source,r=boxes.get(source);
   if(!r){errors.push('unknown source '+id);continue;}
   const origin=items[0].origin;
   if(items.some(it=>!samePt(it.origin,origin))){
    stats.treeOriginMismatches++;
    errors.push('inconsistent physical source anchor '+id);continue;
   }
   const exitRight=near(origin[0],r.x+r.w)||near(origin[0],r.x+r.w-7)||near(origin[0],r.x+r.w-8);
   const exitBottom=near(origin[1],r.y+r.h)||near(origin[1],r.y+r.h-3);
   if(!exitRight&&!exitBottom){errors.push('non-output source pin '+id);continue;}
   const modes=items.map(it=>leftSink(it.e,it.end));
   if(modes.some(x=>!x)){
    stats.treeInvalidSinkPins++;
    errors.push('incorrect sink face '+id);continue;
   }
   // A single physical escape is mandatory. Force a shared trunk before
   // attempting separate destinations. Track separation is deterministic.
   const direction=exitRight?'right':'bottom';
   const spacing=20;
   let accepted=null;
   for(let offset=0;offset<22&&!accepted;offset++){
    const extent=30+spacing*offset;
    const stub=direction==='right'?[origin[0]+extent,origin[1]]:[origin[0],origin[1]+extent];
    if(!safePath([origin,stub],source,null))continue;
    const staged=new Map();
    let ok=true;
    // Route sorted terminals to make the topology deterministic.
    const ordered=[...items].sort((a,b)=>a.end[1]-b.end[1]||a.end[0]-b.end[0]||a.e.id.localeCompare(b.e.id));
    for(const it of ordered){
     const mode=leftSink(it.e,it.end);
     // Reserve an approach from the prescribed side; never route beyond it.
     const pre=mode==='left'?[it.end[0]-14,it.end[1]]:[it.end[0],it.end[1]+14];
     if(!safePath([pre,it.end],source,it.e.target)){ok=false;break;}
     const mid=findRoute(stub,pre,boxes,source,it.e.target,[stub]);
     if(!mid){ok=false;break;}
     const path=compact([origin,...mid,it.end]);
     if(!safePath(path,source,it.e.target)) {ok=false;break;}
     if(mode==='left' && !(path.at(-2)[0]<it.end[0])){ok=false;break;}
     if(mode==='bottom' && !(path.at(-2)[1]>it.end[1])){ok=false;break;}
     staged.set(it.e.id,path);
    }
    if(ok){accepted=staged;busy.push(stub);}
   }
   if(!accepted){
    // Do not pretend the independent ELK traces satisfy net topology.
    // Report explicitly; the original geometry remains for diagnostics.
    stats.treeFallbacks++;errors.push('cannot route shared physical terminal '+id);
    continue;
   }
   for(const [edgeId,p] of accepted)paths.set(edgeId,p);
   stats.treeNets++;
  }
  stats.treeStrictErrors=errors.length;
  // Validate semantic edge coverage and physical continuity after rerouting.
  for(const e of graph.edges||[]){if(!valid(paths.get(e.id))&&!errors.includes('missing edge geometry '+e.id))errors.push('dropped edge '+e.id);}
  return {...geometry,edgePaths:paths,bridges:[],stats:{...(geometry.stats||{}),...stats,
   treeErrors:errors.slice(0,24)}};
 }

 const api={consolidate};
 root.FlexNetTree=api;
 if(typeof module==='object'&&module.exports)module.exports=api;
})(typeof window==='object'?window:globalThis);

'use strict';
/* A stable graph-to-geometry boundary. Slang remains authoritative for
 * graph identities and connections; layout engines may only supply geometry.
 * No graph edge is silently dropped or synthesized by this adapter.
 */
(function(root){
 function validate(graph,geometry){
  const errors=[];
  const positions=geometry?.positions, paths=geometry?.edgePaths;
  if(!(positions instanceof Map)||!(paths instanceof Map))
   return {ok:false,errors:['layout must supply positions and edgePaths maps']};
  const nodes=new Set((graph.nodes||[]).map(n=>n.id));
  const edges=new Set((graph.edges||[]).map(e=>e.id));
  for(const node of graph.nodes||[]){
   const rect=positions.get(node.id);
   if(!rect||![rect.x,rect.y,rect.w,rect.h].every(Number.isFinite)||rect.w<=0||rect.h<=0)
    errors.push('invalid or missing node geometry: '+node.id);
  }
  for(const edge of graph.edges||[]){
   if(!nodes.has(edge.source)||!nodes.has(edge.target)){
    errors.push('edge references unknown node: '+edge.id);continue;
   }
   const points=paths.get(edge.id);
   if(!Array.isArray(points)||points.length<2||points.some(p=>!Array.isArray(p)||p.length!==2||!p.every(Number.isFinite)))
    errors.push('invalid or missing edge route: '+edge.id);
  }
  for(const id of positions.keys())if(!nodes.has(id))errors.push('extraneous node: '+id);
  for(const id of paths.keys())if(!edges.has(id))errors.push('extraneous edge: '+id);
  if(!Number.isFinite(geometry.width)||geometry.width<=0||!Number.isFinite(geometry.height)||geometry.height<=0)
   errors.push('invalid layout extents');
  return {ok:!errors.length,errors};
 }

 /* FSRTL-0071: separate coincident/too-close conductors of DISTINCT nets.
    The Slang graph is untouched. An unrecoverable conflict is reported, never hidden. */
 function separateLanes(graph,geometry){
  // Geometric clearance applies to distinct physical conductors, and to
  // non-adjacent portions of the SAME conductor. Pin-sharing tree segments
  // are intentional; distinct edge IDs do not imply distinct copper tracks.
  const GAP=14,EPS=.04,paths=new Map(geometry.edgePaths),positions=geometry.positions;
  const edges=[...(graph.edges||[])].sort((a,b)=>String(a.id).localeCompare(String(b.id)));
  const net=e=>String(e.net||e.id);
  const segs=p=>{const out=[];for(let i=1;i<p.length;i++){
   const a=p[i-1],b=p[i];if(Math.abs(a[0]-b[0])+Math.abs(a[1]-b[1])<EPS)continue;
   out.push({a,b,index:i-1,h:Math.abs(a[1]-b[1])<EPS,v:Math.abs(a[0]-b[0])<EPS});
  }return out;};
  const collision=(a,b)=>{
   if(a.h&&b.h&&Math.abs(a.a[1]-b.a[1])<GAP)
    return Math.min(Math.max(a.a[0],a.b[0]),Math.max(b.a[0],b.b[0]))-
           Math.max(Math.min(a.a[0],a.b[0]),Math.min(b.a[0],b.b[0]))>EPS;
   if(a.v&&b.v&&Math.abs(a.a[0]-b.a[0])<GAP)
    return Math.min(Math.max(a.a[1],a.b[1]),Math.max(b.a[1],b.b[1]))-
           Math.max(Math.min(a.a[1],a.b[1]),Math.min(b.a[1],b.b[1]))>EPS;
   return false;
  };
  const clearBox=(s,e)=>{
   if(!s.h&&!s.v)return false;
   for(const [id,r] of positions){
    if(id===e.source||id===e.target)continue;
    const pad=5,L=r.x-pad,R=r.x+r.w+pad,T=r.y-pad,B=r.y+r.h+pad;
    if(s.h&&s.a[1]>T&&s.a[1]<B&&Math.max(s.a[0],s.b[0])>L&&Math.min(s.a[0],s.b[0])<R)return false;
    if(s.v&&s.a[0]>L&&s.a[0]<R&&Math.max(s.a[1],s.b[1])>T&&Math.min(s.a[1],s.b[1])<B)return false;
   }return true;
  };
  const simplify=p=>{const r=[];for(const q of p){if(!r.length||Math.abs(r.at(-1)[0]-q[0])+Math.abs(r.at(-1)[1]-q[1])>EPS)r.push(q);}
   for(let i=1;i+1<r.length;){const a=r[i-1],b=r[i],c=r[i+1];
    // Only collapse monotonic straight segments: never collapse a hairpin.
    if(((Math.abs(a[0]-b[0])<EPS&&Math.abs(b[0]-c[0])<EPS)&&((b[1]-a[1])*(c[1]-b[1])>=0))||
       ((Math.abs(a[1]-b[1])<EPS&&Math.abs(b[1]-c[1])<EPS)&&((b[0]-a[0])*(c[0]-b[0])>=0)))r.splice(i,1);else i++;
   }return r;};
  const selfConflicts=p=>{const s=segs(p);const bad=[];
   for(let i=0;i<s.length;i++)for(let j=i+2;j<s.length;j++){
    // Adjacent segments of one polyline may meet at the same turn.
    if(collision(s[i],s[j]))bad.push([i,j]);
   }return bad;};
  const committed=[];let resolved=0,unresolved=0,conflicts=0,selfOverlaps=0;
  const failures=[];
  for(const e of edges){
   const orig=paths.get(e.id);if(!Array.isArray(orig)||orig.length<2)continue;
   let p=simplify(orig.map(q=>[q[0],q[1]]));
   const other=committed.filter(x=>x.net!==net(e));
   const conflictsWith=q=>segs(q).some(s=>other.some(x=>collision(s,x)));
   const invalid=q=>selfConflicts(q).length>0||conflictsWith(q);
   if(invalid(p)){
    conflicts++;
    // Whole-path orthogonal re-routing on a sparse visibility grid. Unlike
    // single-segment offsets, this can move several bends together.
    const source=positions.get(e.source),target=positions.get(e.target);
    const a=p[0],b=p.at(-1),pad=GAP+5;
    const xs=new Set([a[0],b[0]]),ys=new Set([a[1],b[1]]);
    const add=(set,v)=>{if(Number.isFinite(v))set.add(Math.round(v*100)/100);};
    for(const r of positions.values()){
     for(const x of [r.x-pad,r.x+r.w+pad])add(xs,x);
     for(const y of [r.y-pad,r.y+r.h+pad])add(ys,y);
    }
    for(const s of other){
     for(const x of [s.a[0],s.b[0]]){add(xs,x-GAP);add(xs,x+GAP);}
     for(const y of [s.a[1],s.b[1]]){add(ys,y-GAP);add(ys,y+GAP);}
    }
    // Keep a short escape and arrival in the original pin direction.
    const first=p[1],last=p.at(-2),step=10;
    const pinStep=(origin,next,d)=>{
     if(Math.abs(next[0]-origin[0])<EPS)return [origin[0],origin[1]+Math.sign(next[1]-origin[1])*Math.min(step,Math.abs(next[1]-origin[1]))];
     return [origin[0]+Math.sign(next[0]-origin[0])*Math.min(step,Math.abs(next[0]-origin[0])),origin[1]];
    };
    const entry=pinStep(a,first),exit=pinStep(b,last);
    add(xs,entry[0]);add(xs,exit[0]);add(ys,entry[1]);add(ys,exit[1]);
    const X=[...xs].sort((u,v)=>u-v),Y=[...ys].sort((u,v)=>u-v);
    let found=null;
    if(X.length*Y.length<=30000&&X.length&&Y.length){
     const nx=X.length,ny=Y.length,idx=(i,j)=>i*ny+j;
     const xi=new Map(X.map((v,i)=>[v,i])),yi=new Map(Y.map((v,i)=>[v,i]));
     const begin=idx(xi.get(entry[0]),yi.get(entry[1]));
     const goal=idx(xi.get(exit[0]),yi.get(exit[1]));
     const open=[[0,begin,-1]],best=new Map([[begin+':-1',0]]),parent=new Map();
     const segmentOK=(u,v)=>{
      const seg=segs([u,v])[0];
      if(!seg||!clearBox(seg,e))return false;
      if(other.some(o=>collision(seg,o)))return false;
      return true;
     };
     // An endpoint stub is reserved; never silently change its face.
     if(segmentOK(a,entry)&&segmentOK(exit,b)){
      let iterations=0,finish=null;
      while(open.length&&iterations++<50000){
       open.sort((q,r)=>q[0]-r[0]);
       const [score,v,dir]=open.shift(),current=v+':'+dir;
       const cost=best.get(current);
       if(cost===undefined||score>cost+Math.abs(X[Math.floor(v/ny)]-exit[0])+Math.abs(Y[v%ny]-exit[1])+0.001)continue;
       if(v===goal){finish=current;break;}
       const i=Math.floor(v/ny),j=v%ny,u=[X[i],Y[j]];
       for(const [ii,jj,nd] of [[i-1,j,0],[i+1,j,0],[i,j-1,1],[i,j+1,1]]){
        if(ii<0||ii>=nx||jj<0||jj>=ny)continue;
        const w=[X[ii],Y[jj]],next=idx(ii,jj),tag=next+':'+nd;
        if(!segmentOK(u,w))continue;
        const nextCost=cost+Math.abs(u[0]-w[0])+Math.abs(u[1]-w[1])+(dir>=0&&dir!==nd?8:0);
        if(nextCost+EPS<(best.get(tag)??Infinity)){
         best.set(tag,nextCost);parent.set(tag,current);
         const heuristic=Math.abs(w[0]-exit[0])+Math.abs(w[1]-exit[1]);
         open.push([nextCost+heuristic,next,nd]);
        }
       }
      }
      if(finish){
       const rev=[];let state=finish;
       while(state){const v=Number(state.split(':')[0]);rev.push([X[Math.floor(v/ny)],Y[v%ny]]);state=parent.get(state);}
       rev.reverse();
       const candidate=simplify([a,...rev,b]);
       if(segs(candidate).every(q=>clearBox(q,e))&&!invalid(candidate))found=candidate;
      }
     }
    }
    if(found){p=found;resolved++;}
    else {unresolved++;failures.push(e.id);}
   }
   selfOverlaps+=selfConflicts(p).length;
   paths.set(e.id,p);
   for(const s of segs(p))committed.push({net:net(e),...s});
  }
  // Final audit: a later route must not hide an earlier conflict. Same-net
  // coincident stretches are deliberately allowed for shared fanout trunks.
  let remaining=0;const all=[];
  for(const e of edges){const p=paths.get(e.id);if(!Array.isArray(p))continue;
   const s=segs(p);for(const x of s){for(const old of all)if(old.net!==net(e)&&collision(x,old))remaining++;
    all.push({...x,net:net(e)});
   }
  }
  return {...geometry,edgePaths:paths,stats:{...(geometry.stats||{}),laneMinGap:GAP,
   laneConflicts:conflicts,laneResolved:resolved,laneUnresolved:unresolved,
   laneRemaining:remaining,laneSelfOverlaps:selfOverlaps,laneFailures:failures.slice(0,24)}};
 }

 /* FSRTL-0080: export the *actual* ELK geometry on a congested scope.
    Semantic graph exports cannot reproduce spatial conflicts; these snapshots
    carry pins, node rectangles and exact routed polylines for offline replay. */
 function snapshotGeometry(graph,geometry,phase,issue){
  return {
   schema:'flexsoc.rtl_viewer.elk_geometry.v1',phase,issue:issue||'',
   graph:{nodes:graph.nodes,edges:graph.edges},
   geometry:{positions:[...geometry.positions],edgePaths:[...geometry.edgePaths],
    width:geometry.width,height:geometry.height,stats:geometry.stats||{}}
  };
 }
 function captureGeometry(graph,geometry,phase,issue){
  if(typeof window!=='object')return;
  window.__fsrtlRoutingSnapshot=snapshotGeometry(graph,geometry,phase,issue);
  if(!window.document||window.document.getElementById('fsrtl-export-geometry'))return;
  const button=window.document.createElement('button');
  button.id='fsrtl-export-geometry';button.type='button';
  button.textContent='Export ELK Geometry';
  button.title='Export actual ELK positions, routes and semantic net IDs for offline analysis';
  button.className='fsrtl-export-geometry';
  const exportSnapshot=()=>{
   const data=window.__fsrtlRoutingSnapshot;
   if(!data)return;
   const blob=new Blob([JSON.stringify(data)],{type:'application/json'});
   const url=URL.createObjectURL(blob),a=window.document.createElement('a');
   a.href=url;a.download='ethernet-core-elk-geometry.json';
   window.document.body.appendChild(a);a.click();a.remove();
   setTimeout(()=>URL.revokeObjectURL(url),1500);
  };
  button.addEventListener('click',exportSnapshot);
  // Keyboard alternative even when the surrounding layout hides body overflow.
  window.document.addEventListener('keydown',event=>{
   if(event.ctrlKey&&event.shiftKey&&event.code==='KeyE'){
    event.preventDefault();exportSnapshot();
   }
  });
  window.document.body.appendChild(button);
 }

 function create({boxSize,baseRank}){
  let elk=null,sequence=0;
  return {
   get strategy(){return 'elk';},
   compute(){throw Error('Native layout removed: use computeELK()');},
   validate,
   get available(){return !!elk;},
   setELK(engine){elk=engine&&typeof engine.layout==='function'?engine:null;return !!elk;},
   async computeELK(graph){
    if(!elk||!root.FlexElkAdapter)throw Error('ELK runtime unavailable');
    const token=++sequence;
    // ELK is the sole owner of placement, edge routing and junction geometry.
    // No NetTree, no per-edge lane repair, no native fallback.
    const geometry=await root.FlexElkAdapter.compute(elk,graph,boxSize);
    if(token!==sequence)throw Error('superseded ELK layout');
    const checked=validate(graph,geometry);
    if(!checked.ok)throw Error('ELK invalid: '+checked.errors.slice(0,6).join('; '));
    captureGeometry(graph,geometry,'elk',null);
    return {...geometry,bridges:[],portFaces:new Map(),fanoutJunctions:[],
      stats:{...(geometry.stats||{}),engine:'elk',routingOwner:'elk-hyperedges'}};
   },
   setStrategy(next){if(next!=='elk')throw Error('Native layout removed; ELK-only');}
  };
 }
 const api={create,validate,separateLanes,snapshotGeometry};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexLayoutEngine=api;
})(typeof window==='object'?window:globalThis);
