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
   // An AST dependency is not a conductor and deliberately has no route.
   if(edge.rendered===false){
    if(paths.has(edge.id))errors.push('non-electrical dependency has a wire route: '+edge.id);
    continue;
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

 /* Decorative only: a jump over a perpendicular DIFFERENT-net wire.
    Neither the Slang graph nor ELK polylines are changed. No joint is
    synthesized at an intersection. A y-sorted range scan avoids an all-pairs
    segment loop; cap visible hops on pathologically congested diagrams. */
 function crossingBridges(graph,geometry,{limit=1024}={}){
  const edgeById=new Map((graph.edges||[]).map(e=>[e.id,e]));
  const horizontal=[],vertical=[],EPS=.05,STUB=10;
  for(const [id,path] of geometry.edgePaths){
   const e=edgeById.get(id);if(!e||!Array.isArray(path))continue;
   for(let i=1;i<path.length;i++){
    const [a,b]=[path[i-1],path[i]];
    if(Math.abs(a[1]-b[1])<EPS&&Math.abs(a[0]-b[0])>2*STUB)
     horizontal.push({id,net:String(e.net||id),y:a[1],lo:Math.min(a[0],b[0]),hi:Math.max(a[0],b[0])});
    if(Math.abs(a[0]-b[0])<EPS&&Math.abs(a[1]-b[1])>2*STUB)
     vertical.push({id,net:String(e.net||id),x:a[0],lo:Math.min(a[1],b[1]),hi:Math.max(a[1],b[1])});
   }
  }
  const compare=(a,b)=>a<b?-1:a>b?1:0;
  horizontal.sort((a,b)=>a.y-b.y||compare(a.id,b.id));
  vertical.sort((a,b)=>a.x-b.x||a.lo-b.lo||compare(a.id,b.id));
  const lowerBound=y=>{let lo=0,hi=horizontal.length;
   while(lo<hi){const mid=(lo+hi)>>1;if(horizontal[mid].y<y)lo=mid+1;else hi=mid;}
   return lo;
  };
  const bridges=[],seen=new Set();
  for(const v of vertical){
   for(let i=lowerBound(v.lo+STUB);i<horizontal.length;i++){
    const h=horizontal[i];if(h.y>=v.hi-STUB)break;
    if(h.id===v.id||h.net===v.net||v.x<=h.lo+STUB||v.x>=h.hi-STUB)continue;
    const key=v.x.toFixed(3)+':'+h.y.toFixed(3);
    if(seen.has(key))continue;
    seen.add(key);bridges.push({edge:h.id,x:v.x,y:h.y});
    if(bridges.length>=limit)return {bridges,limited:true};
   }
  }
  return {bridges,limited:false};
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

 function create({boxSize}){
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
    const crossings=crossingBridges(graph,geometry);
    captureGeometry(graph,geometry,'elk',null);
    return {...geometry,bridges:crossings.bridges,portFaces:new Map(),fanoutJunctions:[],
      stats:{...(geometry.stats||{}),engine:'elk',routingOwner:'elk-simple-edges',
       crossingBridges:crossings.bridges.length,crossingBridgesLimited:crossings.limited}};
   },
   setStrategy(next){if(next!=='elk')throw Error('Native layout removed; ELK-only');}
  };
 }
 const api={create,validate,crossingBridges,snapshotGeometry};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexLayoutEngine=api;
})(typeof window==='object'?window:globalThis);
