'use strict';
/* ELK geometry adapter v2. No RTL semantics may originate here. */
(function(root){
 // A pin and a semantic net define a shared anchor. Never merge unrelated nets.
 const own=(o,k)=>Object.prototype.hasOwnProperty.call(o,k);
 const pinKey=(e,role)=>JSON.stringify([role==='source'?e.source:e.target,
    String(e.net||e.id),String(role==='source'?(e.sourcePin||e.source_port||''):(e.type==='event'?(e.pin||'EVENT'):(e.targetPin||e.port||e.pin||''))),role]);
 function portId(node,role,e){
  // Encode arbitrary AST identifiers without delimiter collisions.
  return node.id+':'+role+':'+encodeURIComponent(pinKey(e,role));
 }
 function side(node,role){
  if(node.type==='port'){
   const d=String(node.direction||'').toLowerCase();
   if(!['in','input','out','output'].includes(d))throw Error('undirected top-level port: '+node.id);
   // Semantic edge orientation is not necessarily physical port drive direction.
   // Top-level output can participate as the source in a traced AST relation.
   // Its physical face stays WEST regardless of edge role.
  }
  if(node.type==='port'){const d=String(node.direction||'').toLowerCase();return ['in','input'].includes(d)?'EAST':'WEST';}
  return role==='source'?'EAST':'WEST';
 }
 // FSRTL-0055 anchor contract: exact Canvas pins and compact symbol dimensions.
 // Exact Canvas anchors, expressed relative to the ELK node. Shape and pin
 // identities originate in the Slang-derived graph, never in ELK.
 function anchor(node,role,e,size){
  const w=size.w,h=size.h,source=role==='source',name=String(source?(e.sourcePin||e.source_port||e.port||e.pin||''):(e.type==='event'?(e.pin||'EVENT'):(e.targetPin||e.port||e.pin||'')));
  if(node.type==='port'){const input=['in','input'].includes(String(node.direction||'').toLowerCase());return {x:input?w-7:7,y:h/2,side:input?'EAST':'WEST'};}
  if(node.type==='signal')return {x:source?w-8:8,y:h/2,side:source?'EAST':'WEST'};
  if(node.type==='instance'||node.type==='generate'){
   const dirs=source?['out','output']:['in','input'];
   const candidates=(node.ports||[]).filter(p=>dirs.includes(p.direction));
   const index=candidates.findIndex(p=>p.name===name);
   if(index<0)return {x:source?w-6:0,y:h/2,side:source?'EAST':'WEST'}; // Unmapped semantic port: generic anchor, never invent a pin name
   return {x:source?w-6:0,y:(source?65:53)+index*19,side:source?'EAST':'WEST'};
  }
  if(['register','counter','fsm'].includes(node.type)){
   if(source)return {x:w-4,y:20,side:'EAST'};
   if(name==='CLK')return {x:w*.34,y:h-3,side:'SOUTH'};
   if(name==='RST')return {x:w*.67,y:h-3,side:'SOUTH'};
   if(name==='EVENT')return {x:w*.67,y:h-3,side:'SOUTH'};
   return {x:4,y:20,side:'WEST'};
  }
  if(node.type==='operator'){
   if(source)return {x:w-9,y:h/2,side:'EAST'};
   if(node.shape==='mux'){
    if(name==='A')return {x:9,y:22,side:'WEST'};
    if(name==='B')return {x:9,y:h-22,side:'WEST'};
    if(name==='S')return {x:w/2,y:h-6,side:'SOUTH'};
   }
   if(name==='A')return {x:7,y:18,side:'WEST'};
   if(name==='B')return {x:7,y:h-18,side:'WEST'};
   return {x:7,y:h/2,side:'WEST'};
  }
  return {x:source?w-8:8,y:h/2,side:source?'EAST':'WEST'};
 }
 function convert(graph,boxSize){
  if(!graph||!Array.isArray(graph.nodes)||!Array.isArray(graph.edges))throw Error('invalid graph');
  const byId=new Map();
  for(const n of graph.nodes){if(!n?.id||byId.has(n.id))throw Error('duplicate/missing node id');byId.set(n.id,n);}
  const edgesSeen=new Set();
  const children=graph.nodes.map(n=>{
   const s=boxSize(n);if(!Number.isFinite(s.w)||!Number.isFinite(s.h)||s.w<=0||s.h<=0)throw Error('invalid symbol dimensions: '+n.id);
   const ports=[],seen=new Set();
   for(const role of ['source','target']){
    for(const e of graph.edges){if((role==='source'?e.source:e.target)!==n.id)continue;
     const id=portId(n,role,e);
     if(seen.has(id))continue;
     seen.add(id);
     const facing=side(n,role);const a=anchor(n,role,e,s);
     if(a.side!==facing&&a.side!=='SOUTH')throw Error('ELK anchor side conflict: '+id);
     ports.push({id,width:2,height:2,x:a.x-1,y:a.y-1,layoutOptions:{'org.eclipse.elk.port.side':a.side}});
    }
   }
   // Explicit layer regions: top-level input ports form the leftmost layer,
   // top-level output ports form the rightmost layer. Other logic remains
   // between those regions; ELK still chooses ordering within each layer.
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
  for(const e of graph.edges){
   if(!e?.id||edgesSeen.has(e.id))throw Error('duplicate/missing edge id');
   edgesSeen.add(e.id);
   if(!byId.has(e.source)||!byId.has(e.target))throw Error('unknown semantic endpoint: '+e.id);
   const source=portId(byId.get(e.source),'source',e);
   const target=portId(byId.get(e.target),'target',e);
   edges.push({id:e.id,sources:[source],targets:[target]});
  }
  return {id:'rtl-scope',layoutOptions:{'elk.algorithm':'layered','elk.direction':'RIGHT',
   'elk.edgeRouting':'ORTHOGONAL','elk.spacing.nodeNode':'64',
   'elk.layered.spacing.nodeNodeBetweenLayers':'120',
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
  const nodeIds=new Set(graph.nodes.map(n=>n.id)),edgeIds=new Set(graph.edges.map(e=>e.id));
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
   stats:{engine:'elk',simpleEdges:input.edges.length,semanticEdges:graph.edges.length}};
 }
 const api={convert,compute,pinKey,anchor};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexElkAdapter=api;
})(typeof window==='object'?window:globalThis);
