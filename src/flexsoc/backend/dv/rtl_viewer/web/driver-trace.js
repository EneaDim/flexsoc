'use strict';
/* Trace only edges that exist in the current compiler-backed schematic view.
   This never generates a new wire, or guesses drivers by matching names. */
(function(root){
 function producer(graph,selected){
  if(!graph||!Array.isArray(graph.nodes)||!Array.isArray(graph.edges))return {status:'unavailable'};
  const nodes=new Map(graph.nodes.map(n=>[n.id,n]));
  let id=typeof selected==='string'?selected:selected?.id;
  const selectedEdge=graph.edges.find(e=>e.id===id);
  if(selectedEdge){
   // A selectable wire may carry a signal id independent of its edge id.
   id=nodes.has(selectedEdge.signal)?selectedEdge.signal:
      nodes.has(selectedEdge.net)?selectedEdge.net:selectedEdge.target;
  }
  const target=nodes.get(id);
  if(!target)return {status:'not_visible'};
  const incoming=graph.edges.filter(e=>e.target===id&&e.rendered!==false&&
   !['control','address','event'].includes(e.type));
  const distinct=[...new Set(incoming.map(e=>e.source))];
  if(distinct.length===0)return {status:'no_visible_driver',target};
  if(distinct.length!==1)return {status:'multiple_drivers',target,count:distinct.length};
  const source=nodes.get(distinct[0]);
  if(!source)return {status:'not_visible',target};
  const inputs=graph.edges.filter(e=>e.target===source.id&&e.rendered!==false&&
   !['control','address','event'].includes(e.type))
   .map(e=>({pin:e.targetPin||e.pin||'',source:nodes.get(e.source)}))
   .filter(e=>e.source);
  return {status:'unique',target,source,edge:incoming.find(e=>e.source===source.id),inputs};
 }
 /** A small, source-preserving view of one signal's producing expression.
  *
  * This is a projection, NOT a new RTL circuit: keep original node/edge ids,
  * source/target pins and nets. Expand combinational operators until reaching
  * named signals, which are explicit view boundaries (especially registers:
  * never display a cropped flip-flop without its CLK/RST evidence).
  */
 function valuePath(graph,selected,{maxNodes=80,maxDepth=12,maxConsumers=8}={}){
  if(!graph||!Array.isArray(graph.nodes)||!Array.isArray(graph.edges))
   return {status:'unavailable'};
  const byId=new Map(graph.nodes.map(n=>[n.id,n]));
  let id=typeof selected==='string'?selected:selected?.id;
  const wire=graph.edges.find(e=>e.id===id);
  if(wire)id=byId.has(wire.signal)?wire.signal:
   byId.has(wire.net)?wire.net:wire.target;
  const target=byId.get(id);
  if(!target||['process_group','fsm_group','generate'].includes(target.type))
   return {status:'not_visible'};
  const eligible=e=>e&&e.rendered!==false&&
   !['control','address','event'].includes(e.type)&&
   byId.has(e.source)&&byId.has(e.target)&&
   // A partial STRUCT READ into an AST MemberAccess is a valid value input.
   // A partial WRITE to an aggregate output is not a whole-bus driver.
   (e.mapping!=='partial'||(byId.get(e.target)?.kind==='MemberAccess'&&
    byId.get(e.target)?.shape==='field'&&(e.targetPin||e.pin)==='A'));
  const incoming=new Map(),outgoing=new Map();
  for(const e of graph.edges){
   if(!eligible(e))continue;
   if(!incoming.has(e.target))incoming.set(e.target,[]);
   if(!outgoing.has(e.source))outgoing.set(e.source,[]);
   incoming.get(e.target).push(e);outgoing.get(e.source).push(e);
  }
  const keepNodes=new Set([id]),keepEdges=new Set(),limited=[];
  function add(e){
   if(keepNodes.size>=maxNodes&&(!keepNodes.has(e.source)||!keepNodes.has(e.target))){
    limited.push(e.id);return false;
   }
   keepNodes.add(e.source);keepNodes.add(e.target);keepEdges.add(e.id);return true;
  }
  const expanded=new Set(),upstreamNodes=new Set([id]);
  function upstream(nodeId,depth){
   if(depth>=maxDepth||expanded.has(nodeId))return;
   expanded.add(nodeId);
   const current=byId.get(nodeId);
   // A named signal marks the *input* of this particular value cone. No
   // speculative look-through of an external register, module or process.
   if(nodeId!==id&&current?.type!=='operator')return;
   for(const e of incoming.get(nodeId)||[]){
    if(!add(e))continue;
    upstreamNodes.add(e.source);
    upstream(e.source,depth+1);
   }
  }
  upstream(id,0);
  // Keep a bounded sample of actual consumers for context. They are boundary
  // nodes: a sequential consumer's other pins live outside this value view.
  let consumerCount=0;
  for(const e of outgoing.get(id)||[]){
   if(consumerCount>=maxConsumers)break;
   if(add(e))consumerCount++;
  }
  const nodes=graph.nodes.filter(n=>keepNodes.has(n.id)).map(n=>{
   if(n.id===id)return n;
   if(upstreamNodes.has(n.id)){
    if(n.type==='operator'||n.type==='port'||n.type==='signal')return n;
   }
   // A signal/register/operator outside the producing cone is a boundary:
   // never show half of a downstream comparator or a sequential glyph with
   // cropped CLK/RST as though it were a complete circuit cell.
   return {...n,type:'signal',traceBoundary:true,originalType:n.type};
  });
  const edges=graph.edges.filter(e=>keepEdges.has(e.id));
  const rootDrivers=(incoming.get(id)||[]).filter(e=>keepEdges.has(e.id));
  const originalSources=[...new Set(rootDrivers.map(e=>e.source))];
  const missingPins=[];
  for(const node of nodes){
   if(node.type!=='operator'||!upstreamNodes.has(node.id))continue;
   for(const pin of (node.pins||[]).filter(p=>p!=='Y')){
    if(edges.some(e=>e.target===node.id&&(e.targetPin||e.pin)===pin))continue;
    if(node.literalOperands?.[pin]!==undefined)continue;
    missingPins.push({nodeId:node.id,pin});
   }
  }
  const status=graph.truncated?'source_graph_limited':limited.length?'limited':
   missingPins.length?'incomplete':originalSources.length>1?'multiple_drivers':
   originalSources.length===0?'no_proven_driver':'available';
  return {status,graph:{...graph,nodes,edges,
   module:'Value path · '+target.name,virtualFocus:'value:'+id,virtualParent:graph.path,
   total:nodes.length,truncated:false,processGroups:[],fsmGroups:[],generateGroups:[],
   traceInfo:{targetId:id,rootDrivers:originalSources.length,
    boundaryCount:nodes.filter(n=>n.traceBoundary).length,
    limitedEdges:limited.length,sourceGraphTruncated:Boolean(graph.truncated),missingPins,
    semantics:'original AST-backed graph edges only'}
  }};
 }
 const api={producer,valuePath};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexDriverTrace=api;
})(typeof window==='object'?window:globalThis);
