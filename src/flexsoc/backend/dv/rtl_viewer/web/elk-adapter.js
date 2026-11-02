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
  if(node?.type==='instance'||node?.type==='generate')return pinName(e,role);
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
   // Explicit layer regions: input ports left, output ports right. Inout
   // ports are unconstrained: the same bidirectional boundary can be a load
   // and a driver, and neither position is always correct.
   const options={'org.eclipse.elk.portConstraints':'FIXED_POS'};
   if(n.type==='port'){
    const direction=String(n.direction||'').toLowerCase();
    if(['in','input'].includes(direction))options['org.eclipse.elk.layered.layering.layerConstraint']='FIRST';
    if(['out','output'].includes(direction))options['org.eclipse.elk.layered.layering.layerConstraint']='LAST';
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
  // Busy, AST-proven fanouts need room between layers for orthogonal bends.
  // This is a bounded presentation policy, not a connectivity inference.
  let maxFanout=0;
  for(const count of fanout.values())maxFanout=Math.max(maxFanout,count);
  const layerGap=120+Math.min(64,Math.max(0,maxFanout-3)*8);
  return {id:'rtl-scope',layoutOptions:{'elk.algorithm':'layered','elk.direction':'RIGHT',
   'elk.edgeRouting':'ORTHOGONAL','elk.spacing.nodeNode':'64',
   'elk.layered.spacing.nodeNodeBetweenLayers':String(layerGap),
   'elk.spacing.edgeEdge':'24','elk.layered.spacing.edgeEdgeBetweenLayers':'24',
   'elk.spacing.edgeNode':'32','elk.layered.spacing.edgeNodeBetweenLayers':'32',
   'elk.spacing.portPort':'24'},children,edges};
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
  const positions=new Map(),edgePaths=new Map();
  for(const n of result.children||[]){
   if(!nodeIds.has(n.id)||positions.has(n.id)||![n.x,n.y,n.width,n.height].every(Number.isFinite))
    throw Error('invalid ELK node result');
   positions.set(n.id,{x:n.x,y:n.y,w:n.width,h:n.height});
  }
  for(const e of result.edges||[]){
   if(!edgeIds.has(e.id)||edgePaths.has(e.id))throw Error('unexpected/duplicate ELK edge: '+e.id);
   edgePaths.set(e.id,route(e));
  }
  if(positions.size!==nodeIds.size||edgePaths.size!==edgeIds.size)throw Error('ELK dropped semantic entities');
  if(![result.width,result.height].every(Number.isFinite))throw Error('invalid ELK bounds');
  return {positions,edgePaths,width:result.width,height:result.height,
   stats:{engine:'elk',simpleEdges:input.edges.length,semanticEdges:graph.edges.length,
    nonElectricalDependencies:graph.edges.length-input.edges.length}};
 }
 const api={convert,compute,pinKey,anchor};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexElkAdapter=api;
})(typeof window==='object'?window:globalThis);
