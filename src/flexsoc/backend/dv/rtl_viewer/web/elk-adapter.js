'use strict';
/* ELK geometry adapter v2. No RTL semantics may originate here. */
(function(root){
 // A physical terminal is identified by the role it exposes to the renderer.
 // The sink's port name (e.port/e.pin) must NOT create fictitious output
 // terminals on a shared source signal. Distinct module ports and functional
 // input pins still have distinct identities. Net remains part of the key:
 // unrelated AST dependencies never become a single conductor in ELK.
 const symbolGeometry=typeof module==='object'&&module.exports?
  require('./symbol-geometry.js'):root.FlexSymbolGeometry;
 if(!symbolGeometry)throw Error('symbol geometry unavailable');
 const {anchor,pinName}=symbolGeometry;
 function physicalPin(node,role,e){
  if(node?.type==='instance'||node?.type==='generate'||node?.type==='fsm_group'||node?.type==='process_group')return pinName(e,role);
  if(['register','counter','fsm'].includes(node?.type)){
   if(role==='source')return 'Q';
   const name=pinName(e,role);
   return name==='CLK'||name==='RST'||name==='EVENT'?name:'D';
  }
  if(role==='source')return 'OUT';
  if(node?.type==='operator')return pinName(e,role)||'IN';
  return 'IN';
 }
 function pinKey(e,role,node){
  return JSON.stringify([role==='source'?e.source:e.target,
   String(e.net||e.id),node?physicalPin(node,role,e):pinName(e,role),role]);
 }
 function portId(node,role,e){
  // A single net + a single glyph terminal = a single ELK port, even if
  // Slang records several distinct downstream bindings and edge IDs.
  return node.id+':'+role+':'+encodeURIComponent(pinKey(e,role,node));
 }
 function convert(graph,boxSize){
  if(!graph||!Array.isArray(graph.nodes)||!Array.isArray(graph.edges))throw Error('invalid graph');
  const byId=new Map();
  for(const n of graph.nodes){if(!n?.id||byId.has(n.id))throw Error('duplicate/missing node id');byId.set(n.id,n);}
  // Canonical order removes variation from AST/HTTP enumeration and makes
  // identical scopes produce the same placement across reloads. Index pins
  // once: the old per-node full edge scan was quadratic on large SoC slices.
  const edgesSeen=new Set(),incident=new Map(),fanout=new Map();
  for(const n of graph.nodes)incident.set(n.id,{source:[],target:[]});
  const compare=(a,b)=>a<b?-1:a>b?1:0;
  // Semantic guard/address dependencies remain in the AST graph, but are
  // not electrical wires. They must never be routed into a flip-flop D pin.
  const orderedEdges=[...graph.edges].filter(e=>e.rendered!==false)
   .sort((a,b)=>compare(String(a.id),String(b.id)));
  for(const e of orderedEdges){
   if(!e?.id||edgesSeen.has(e.id))throw Error('duplicate/missing edge id');
   edgesSeen.add(e.id);
   if(!byId.has(e.source)||!byId.has(e.target))throw Error('unknown semantic endpoint: '+e.id);
   incident.get(e.source).source.push(e);
   incident.get(e.target).target.push(e);
   const key=JSON.stringify([e.source,String(e.net||e.id),physicalPin(byId.get(e.source),'source',e)]);
   fanout.set(key,(fanout.get(key)||0)+1);
  }
  const children=[...graph.nodes].sort((a,b)=>compare(a.id,b.id)).map(n=>{
   const s=boxSize(n);if(!Number.isFinite(s.w)||!Number.isFinite(s.h)||s.w<=0||s.h<=0)throw Error('invalid symbol dimensions: '+n.id);
   const ports=[],seen=new Set();
   for(const role of ['source','target']){
    for(const e of incident.get(n.id)[role]){
     const id=portId(n,role,e);
     if(seen.has(id))continue;
     seen.add(id);
     const a=anchor(n,role,e,s);
     if(!Number.isFinite(a.x)||!Number.isFinite(a.y)||a.x<0||a.x>s.w||a.y<0||a.y>s.h)
      throw Error('terminal outside symbol: '+n.id+' '+pinName(e,role));
     ports.push({id,width:0,height:0,x:a.x,y:a.y,layoutOptions:{'org.eclipse.elk.port.side':a.side}});
    }
   }
   // Place *pure* external sources first and pure sinks last. A virtual
   // process focus can turn a read-only boundary into an input port while
   // retaining an AST-proven producer edge to that very signal. ELK forbids
   // FIRST on a node with incoming edges (and LAST on a node with outgoing
   // edges). The declared RTL direction is not sufficient evidence for a
   // topological layer constraint. Do not reverse or discard any edge: just
   // leave mixed-role boundary nodes unconstrained and keep their physical
   // terminals fixed on the appropriate sides.
   const options={'org.eclipse.elk.portConstraints':'FIXED_POS'};
   if(n.type==='port'){
    const direction=String(n.direction||'').toLowerCase();
    const incidence=incident.get(n.id);
    if(['in','input'].includes(direction)&&incidence.target.length===0)
     options['org.eclipse.elk.layered.layering.layerConstraint']='FIRST';
    if(['out','output'].includes(direction)&&incidence.source.length===0)
     options['org.eclipse.elk.layered.layering.layerConstraint']='LAST';
   }
   return {id:n.id,width:s.w,height:s.h,layoutOptions:options,ports};
  });
  // ELK Layered requires SIMPLE edges (one source and one target).
  // Semantic fanout is represented by multiple simple edges sharing the exact
  // same source port; never pass a multi-target hyperedge to ELK.
  const edges=[];
  for(const e of orderedEdges){
   const source=portId(byId.get(e.source),'source',e);
   const target=portId(byId.get(e.target),'target',e);
   edges.push({id:e.id,sources:[source],targets:[target]});
  }
  // Flattened procedural scopes must be REAL ELK containment regions, not
  // rectangles calculated AFTER global layout. Otherwise unrelated cells can
  // be placed between a process's gates while the overlay falsely claims
  // they belong to that process. The group itself is purely geometric: all
  // original node/edge IDs, terminal names and net identities survive.
  // A group is accepted only if all its members are visible and no member is
  // claimed by another flattened group. Overlapping metadata is rejected
  // conservatively rather than assigning hardware to an arbitrary owner.
  const childById=new Map(children.map(n=>[n.id,n]));
  const processOwner=new Map(),processGroups=[];
  for(const g of graph.processGroups||[]){
   if(g.view!=='flattened'||!Array.isArray(g.memberIds)||!g.memberIds.length)continue;
   const ids=[...new Set(g.memberIds)];
   if(ids.some(id=>!childById.has(id)))
    throw Error('Flattened process contains nodes absent from current graph: '+g.token);
   if(ids.some(id=>processOwner.has(id)))
    throw Error('Overlapping flattened processes cannot have an exact ELK boundary: '+g.token);
   const id='rtl-layout:'+g.token;
   if(byId.has(id)||processGroups.some(item=>item.id===id))continue;
   for(const member of ids)processOwner.set(member,id);
   processGroups.push({id,token:g.token,ids});
  }

  // Virtual grouping is hierarchical: flattening an FSM reveals its IMMEDIATE
  // process children, not the gates of all descendant always_ff/always_comb
  // processes. A process that partially contributes to a FSM is still one
  // compact child block; it cannot be split into fictitious RTL processes.
  // Group the visible child symbol (or its flattened compound) as a unit.
  const fsmOwner=new Map(),processParent=new Map(),fsmGroups=[];
  for(const g of graph.fsmGroups||[]){
   if(g.view!=='expanded'||!Array.isArray(g.memberIds)||!g.memberIds.length)continue;
   const owned=new Set(g.memberIds);
   const id='rtl-layout:'+g.token;
   if(byId.has(id)||fsmGroups.some(item=>item.id===id))continue;
   const directIds=[];
   for(const node of graph.nodes){
    if(processOwner.has(node.id))continue;
    const children=Array.isArray(node.hiddenNodeIds)?node.hiddenNodeIds:[];
    if(owned.has(node.id)||(node.type==='process_group'&&children.some(member=>owned.has(member)))){
     if(fsmOwner.has(node.id))throw Error('Overlapping flattened FSM children: '+node.id);
     fsmOwner.set(node.id,id);directIds.push(node.id);
    }
   }
   const processIds=[];
   for(const process of processGroups){
    if(!process.ids.some(member=>owned.has(member)))continue;
    if(processParent.has(process.id))throw Error('Overlapping FSM process ownership: '+process.token);
    processParent.set(process.id,id);processIds.push(process.id);
   }
   if(!directIds.length&&!processIds.length)continue;
   fsmGroups.push({id,token:g.token,directIds,processIds});
  }

  const compoundOptions={ 'elk.algorithm':'layered','elk.direction':'RIGHT',
   'elk.edgeRouting':'ORTHOGONAL',
   'elk.padding':'[top=56,left=24,bottom=26,right=24]',
   'elk.spacing.nodeNode':'48'};
  const processChildren=new Map(processGroups.map(g=>[g.id,[]]));
  const processEdges=new Map(processGroups.map(g=>[g.id,[]]));
  const fsmChildren=new Map(fsmGroups.map(g=>[g.id,[]]));
  const fsmEdges=new Map(fsmGroups.map(g=>[g.id,[]]));
  const rootChildren=[];
  for(const node of children){
   const proc=processOwner.get(node.id),fsm=fsmOwner.get(node.id);
   if(proc)processChildren.get(proc).push(node);
   else if(fsm)fsmChildren.get(fsm).push(node);
   else rootChildren.push(node);
  }
  const parentOfNode=id=>{
   const process=processOwner.get(id);
   return process?processParent.get(process)||null:fsmOwner.get(id)||null;
  };
  const rootEdges=[],originalEdgesById=new Map(orderedEdges.map(e=>[e.id,e]));
  for(const edge of edges){
   const original=originalEdgesById.get(edge.id);
   const a=processOwner.get(original.source),b=processOwner.get(original.target);
   if(a&&a===b){processEdges.get(a).push(edge);continue;}
   const fa=parentOfNode(original.source),fb=parentOfNode(original.target);
   if(fa&&fa===fb){fsmEdges.get(fa).push(edge);continue;}
   rootEdges.push(edge);
  }
  for(const process of processGroups){
   const compound={id:process.id,children:processChildren.get(process.id),
    edges:processEdges.get(process.id),layoutOptions:{...compoundOptions}};
   const parent=processParent.get(process.id);
   if(parent)fsmChildren.get(parent).push(compound);
   else rootChildren.push(compound);
  }
  for(const fsm of fsmGroups){
   rootChildren.push({id:fsm.id,children:fsmChildren.get(fsm.id),
    edges:fsmEdges.get(fsm.id),layoutOptions:{...compoundOptions}});
  }
  // Busy, AST-proven fanouts need room between layers for orthogonal bends.
  // This is a bounded presentation policy, not a connectivity inference.
  let maxFanout=0;
  for(const count of fanout.values())maxFanout=Math.max(maxFanout,count);
  const layerGap=120+Math.min(64,Math.max(0,maxFanout-3)*8);
  const options={'elk.algorithm':'layered','elk.direction':'RIGHT',
   'elk.edgeRouting':'ORTHOGONAL','elk.spacing.nodeNode':'64',
   'elk.layered.spacing.nodeNodeBetweenLayers':String(layerGap),
   'elk.spacing.edgeEdge':'24','elk.layered.spacing.edgeEdgeBetweenLayers':'24',
   'elk.spacing.edgeNode':'32','elk.layered.spacing.edgeNodeBetweenLayers':'32',
   'elk.spacing.portPort':'24'};
  if(processGroups.length||fsmGroups.length)options['elk.hierarchyHandling']='INCLUDE_CHILDREN';
  return {id:'rtl-scope',layoutOptions:options,children:rootChildren,edges:rootEdges};
 }
 // A displayed FLATTENED label is a statement of circuit ownership.
 // Check the actual ELK hierarchy, not a post-hoc bounding box: no unrelated
 // operator may be placed inside that process, nor one of its owned operators
 // outside it. Only the AST-derived member IDs are authoritative.
 function checkCompoundOwnership(graph,geometry){
  const errors=[];
  const rectangles=geometry?.groupRects,positions=geometry?.positions;
  for(const group of graph?.processGroups||[]){
   if(group.view!=='flattened')continue;
   const box=rectangles instanceof Map?rectangles.get(group.token):null;
   if(!box){errors.push('missing compound ELK frame: '+group.token);continue;}
   const owned=new Set(group.memberIds||[]);
   for(const node of graph.nodes||[]){
    const r=positions?.get(node.id);
    if(!r)continue;
    const inside=r.x>=box.x-.01&&r.y>=box.y-.01&&
     r.x+r.w<=box.x+box.w+.01&&r.y+r.h<=box.y+box.h+.01;
    if(inside!==owned.has(node.id))
     errors.push('false flattened ownership: '+group.token+' / '+node.id);
   }
  }
  // An expanded FSM is an ELK region containing *immediate* child blocks.
  // A process that contributes to its state machine is counted as one child,
  // even when that process also writes other independent signals. No unrelated
  // visible symbol may be accidentally enclosed by the FSM frame.
  for(const group of graph?.fsmGroups||[]){
   if(group.view!=='expanded')continue;
   const box=rectangles instanceof Map?rectangles.get(group.token):null;
   if(!box){errors.push('missing compound FSM frame: '+group.token);continue;}
   const internal=new Set(group.memberIds||[]),owned=new Set();
   for(const n of graph.nodes||[]){
    const process=graph.processGroups?.find(g=>g.view==='flattened'&&g.memberIds?.includes(n.id));
    const contributes=internal.has(n.id)||
     (n.type==='process_group'&&n.hiddenNodeIds?.some(id=>internal.has(id)))||
     (process?.memberIds||[]).some(id=>internal.has(id));
    if(contributes){
     if(process)for(const id of process.memberIds)owned.add(id);
     else owned.add(n.id);
    }
   }
   for(const n of graph.nodes||[]){
    const r=positions?.get(n.id);if(!r)continue;
    const inside=r.x>=box.x-.01&&r.y>=box.y-.01&&
     r.x+r.w<=box.x+box.w+.01&&r.y+r.h<=box.y+box.h+.01;
    if(inside!==owned.has(n.id))errors.push('false flattened FSM ownership: '+group.token+' / '+n.id);
   }
  }
  return errors;
 }
 // ELK owns both placement and routing. Read back its actual route sections;
 // never move bends, invent bridges, merge unrelated edges or reroute here.
 function route(edge){
  if(!Array.isArray(edge?.sections)||!edge.sections.length)throw Error('ELK route missing: '+edge?.id);
  if(edge.sections.length!==1)throw Error('ELK simple edge returned non-simple sections: '+edge.id);
  const s=edge.sections[0],raw=[s.startPoint,...(s.bendPoints||[]),s.endPoint];
  if(raw.some(p=>!p||!Number.isFinite(p.x)||!Number.isFinite(p.y)))throw Error('invalid ELK route: '+edge.id);
  const path=[];
  for(const p of raw){
   const xy=[p.x,p.y],last=path.at(-1);
   if(!last||Math.abs(xy[0]-last[0])>1e-7||Math.abs(xy[1]-last[1])>1e-7)path.push(xy);
  }
  if(path.length<2)throw Error('degenerate ELK route: '+edge.id);
  for(let i=1;i<path.length;i++){
   const a=path[i-1],b=path[i];
   if(Math.abs(a[0]-b[0])>0.01&&Math.abs(a[1]-b[1])>0.01)
    throw Error('ELK returned nonorthogonal section: '+edge.id);
  }
  return path;
 }
 async function compute(elk,graph,boxSize){
  if(!elk||typeof elk.layout!=='function')throw Error('ELK instance required');
  const input=convert(graph,boxSize),result=await elk.layout(input);
  const nodeIds=new Set(graph.nodes.map(n=>n.id)),
   edgeIds=new Set(graph.edges.filter(e=>e.rendered!==false).map(e=>e.id));
  const positions=new Map(),edgePaths=new Map(),groupRects=new Map(),offsets=new Map();
  // Nested ELK coordinates are relative to their compound parent, while
  // the Canvas and the terminal contract use absolute document coordinates.
  function visit(node,ox=0,oy=0){
   if(![node.x,node.y,node.width,node.height].every(Number.isFinite))
    throw Error('invalid ELK node result');
   const x=ox+node.x,y=oy+node.y;
   offsets.set(node.id,{x,y});
   if(nodeIds.has(node.id)){
    if(positions.has(node.id))throw Error('duplicate ELK node result: '+node.id);
    positions.set(node.id,{x,y,w:node.width,h:node.height});
   }else if(node.id.startsWith('rtl-layout:')){
    groupRects.set(node.id.slice('rtl-layout:'.length),{x,y,w:node.width,h:node.height});
   }else throw Error('unknown ELK node result: '+node.id);
   for(const child of node.children||[])visit(child,x,y);
  }
  for(const n of result.children||[])visit(n);
  const resultEdges=new Map();
  function collect(container){
   for(const e of container.edges||[]){
    // INCLUDE_CHILDREN can expose one nested edge in both the root edge
    // array and its own group's edge array. Both are the SAME semantic edge.
    if(!resultEdges.has(e.id))resultEdges.set(e.id,e);
   }
   for(const child of container.children||[])collect(child);
  }
  collect(result);
  for(const e of resultEdges.values()){
   if(!edgeIds.has(e.id)||edgePaths.has(e.id))throw Error('unexpected/duplicate ELK edge: '+e.id);
   const container=offsets.get(e.container)||{x:0,y:0};
   edgePaths.set(e.id,route(e).map(([x,y])=>[x+container.x,y+container.y]));
  }
  if(positions.size!==nodeIds.size||edgePaths.size!==edgeIds.size)throw Error('ELK dropped semantic entities');
  const ownershipErrors=checkCompoundOwnership(graph,{positions,groupRects});
  if(ownershipErrors.length)throw Error(ownershipErrors[0]);
  if(![result.width,result.height].every(Number.isFinite))throw Error('invalid ELK bounds');
  return {positions,edgePaths,groupRects,width:result.width,height:result.height,
   stats:{engine:'elk',simpleEdges:input.edges.length,semanticEdges:graph.edges.length,
    nonElectricalDependencies:graph.edges.length-input.edges.length}};
 }
 const api={convert,compute,pinKey,anchor,checkCompoundOwnership};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexElkAdapter=api;
})(typeof window==='object'?window:globalThis);
