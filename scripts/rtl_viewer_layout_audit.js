#!/usr/bin/env node
'use strict';
/* Identical routing and symbol geometry to the workbench. Results are a
 * numerical rendering audit, not a claim of pixel/golden-image equivalence.
 */
const fs=require('node:fs');
const R=require('../src/flexsoc/backend/dv/rtl_viewer/web/router.js');
function audit(graph){
 const layout=R.compute(graph,{boxSize:R.boxSize,baseRank:R.baseRank});
 const errors=[],meta=new Map(graph.edges.map(e=>[e.id,e]));
 const nodes=new Map(graph.nodes.map(n=>[n.id,n]));
 for(const node of nodes.keys()){
  const p=layout.positions.get(node);
  if(!p||![p.x,p.y,p.w,p.h].every(Number.isFinite)||p.w<=0||p.h<=0)
   errors.push({type:'node_missing_or_invalid',id:node});
 }
 let collisions=0,overlapPixels=0,segments=0; const accepted=new Map();
 for(const e of graph.edges){
  const points=layout.edgePaths.get(e.id);
  if(!points){errors.push({type:'edge_missing',id:e.id});continue;}
  for(let i=1;i<points.length;i++){
   segments++;
   const a=points[i-1],b=points[i];
   if(!(a[0]===b[0]||a[1]===b[1]))errors.push({type:'diagonal_wire',id:e.id});
  }
  const check=R.geometryScore(e.id,points,layout.positions,accepted,meta);
  collisions+=check.boxHits;overlapPixels+=check.overlap;accepted.set(e.id,points);
 }
 if(graph.truncated)errors.push({type:'graph_truncated'});
 const status=errors.length?'layout_invalid':collisions?'layout_collision':layout.stats?.skipped?'layout_partial':overlapPixels?'layout_overlap':'layout_pass';
 return {status,errors:errors.slice(0,30),metrics:{nodes:graph.nodes.length,edges:graph.edges.length,
  segments,boxCollisions:collisions,overlapPixels,bridges:layout.bridges.length,
  unboundPins:graph.connectivity?.unbound_pins||0,
  ...layout.stats}};
}
let buffer='';process.stdin.setEncoding('utf8');
process.stdin.on('data',data=>{buffer+=data;if(buffer.length>12_000_000){console.error('graph too large');process.exit(2);}});
process.stdin.on('end',()=>{
 try{const input=JSON.parse(buffer); const graphs=Array.isArray(input)?input:[input];
  const items=graphs.map(audit);const statuses=items.map(x=>x.status);
  const status=statuses.includes('layout_invalid')?'layout_invalid':statuses.includes('layout_collision')?'layout_collision':statuses.includes('layout_overlap')?'layout_overlap':statuses.includes('layout_partial')?'layout_partial':'layout_pass';
  process.stdout.write(JSON.stringify({status,scopes:items.length,items})+'\n');}
 catch(e){console.error(e.stack);process.exitCode=2;}
});
module.exports={audit};
