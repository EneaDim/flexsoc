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
 function create({fallback,boxSize,baseRank}){
  if(typeof fallback?.compute!=='function')throw Error('validated fallback router required');
  let strategy='native';
  return {
   get strategy(){return strategy;},
   compute(graph){
    const result=fallback.compute(graph,{boxSize,baseRank});
    const checked=validate(graph,result);
    if(!checked.ok)throw Error('RTL layout geometry invalid: '+checked.errors.slice(0,6).join('; '));
    return result;
   },
   validate,
   // New layout implementations are registered only after they pass the same
   // graph invariants. This version intentionally leaves native as default.
   setStrategy(next){if(next!=='native')throw Error('layout strategy unavailable: '+next);strategy=next;}
  };
 }
 const api={create,validate};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexLayoutEngine=api;
})(typeof window==='object'?window:globalThis);
