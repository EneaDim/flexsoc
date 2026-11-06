'use strict';
/* Structural proof obligations for every displayed RTL graph.
 * This is NOT SystemVerilog formal equivalence. It validates that the view is
 * an identity-preserving projection of Slang-backed semantic graph edges,
 * including virtual process boundaries and exact ELK/Canvas terminals.
 */
(function(root){
 const P=typeof module==='object'&&module.exports?require('./virtual-process.js'):root.FlexVirtualProcess;
 const G=typeof module==='object'&&module.exports?require('./symbol-geometry.js'):root.FlexSymbolGeometry;
 const A=typeof module==='object'&&module.exports?require('./elk-adapter.js'):root.FlexElkAdapter;
 function check(graph,{limit=40,checkOriginalGroups=true}={}){
  const errors=[],warnings=[];
  const err=(code,id,description)=>{if(errors.length<limit)errors.push({code,id,description});};
  const warn=(code,id,description)=>{if(warnings.length<limit)warnings.push({code,id,description});};
  if(!graph||!Array.isArray(graph.nodes)||!Array.isArray(graph.edges)){
   err('invalid_graph','','Nodes and edges arrays required');return {errors,warnings};
  }
  const nodes=new Map(),edges=new Map();
  for(const n of graph.nodes){
   if(typeof n.id!=='string'||!n.id||nodes.has(n.id))err('node_identity',String(n.id),'Missing/duplicate node identity');
   nodes.set(n.id,n);
  }
  for(const e of graph.edges){
   if(typeof e.id!=='string'||!e.id||edges.has(e.id))err('edge_identity',String(e.id),'Missing/duplicate edge identity');
   edges.set(e.id,e);
   if(!nodes.has(e.source)||!nodes.has(e.target))err('orphan_endpoint',String(e.id),'Edge endpoint absent');
   if(e.rendered!==false&&['address','control'].includes(e.type))
    err('nonphysical_wire',e.id,'Guard/address AST dependency treated as electrical wire');
   for(const [role,required] of [['source','port_out'],['target','port_in']]){
    const node=nodes.get(e[role]);
    if(!node||!['instance','generate'].includes(node.type)||e.type!==required)continue;
    const direction=role==='source'?new Set(['out','output','inout']):
      new Set(['in','input','inout']);
    const port=(node.ports||[]).find(p=>p.name===e.port);
    if(!port||!direction.has(String(port.direction||'').toLowerCase()))
     err('instance_port_direction',e.id,role+' port '+String(e.port)+' has no matching declaration');
   }
  }
  for(const g of (checkOriginalGroups?graph.processGroups:[])||[]){
   const members=new Set(g.memberIds||[]);
   if(!members.size)warn('empty_process_group',g.token,'No attributable circuit nodes');
   for(const id of members)if(!nodes.has(id))err('process_member_missing',g.token,id);
   for(const id of g.clockIds||[]){
    const proven=graph.edges.some(e=>e.rendered!==false&&e.type==='event'&&
      e.source===id&&members.has(e.target)&&['CLK','EVENT'].includes(e.pin||e.targetPin));
    if(!proven)err('unproven_clock',g.token,'Missing AST event edge for '+id);
   }
   for(const id of g.asyncResetIds||[]){
    const proven=graph.edges.some(e=>e.rendered!==false&&e.type==='event'&&
      e.source===id&&members.has(e.target)&&
      ((e.pin||e.targetPin)==='RST'||e.timingRole==='async_reset'));
    if(!proven)err('unproven_async_reset',g.token,'Missing AST async reset edge for '+id);
   }
   for(const pair of g.partialPortInputs||[]){
    if(!pair||!nodes.has(pair.source)||!nodes.has(pair.target)||
       nodes.get(pair.target).type!=='port'||
       !['out','output'].includes(String(nodes.get(pair.target).direction||'').toLowerCase()))
      err('invalid_partial_port_input',g.token,'Not a known output port assignment');
    else if(!graph.edges.some(e=>e.rendered!==false&&e.source===pair.source&&
        e.target===pair.target&&e.mapping==='partial'))
      err('unproven_partial_port_input',g.token,'No compiler-backed partial dependency');
   }
  }
  // This is a *warning*, not an error. Several structured field writes can
  // legitimately feed one aggregate port; none alone proves a full-bus driver.
  for(const node of graph.nodes.filter(n=>n.type==='port'&&
      ['out','output'].includes(String(n.direction||'').toLowerCase()))){
   const partial=graph.edges.filter(e=>e.rendered!==false&&e.target===node.id&&e.mapping==='partial');
   if(partial.length>1)warn('aggregate_field_writes',node.id,partial.length+' partial write edges: do not interpret as conflicting whole-bus drivers');
  }
  // If a full FF glyph is visible, its compiler-proven timing pins must
  // still have their incoming wires. Focused process views may replace an
  // external FF with an INPUT boundary symbol, but must never keep an
  // apparently clockless/resetless register in the schematic.
  for(const n of graph.nodes.filter(n=>['register','counter','fsm'].includes(n.type))){
   const timing=n.sequentialTiming||[];
   for(const [role,pin] of [['clock','CLK'],['async_reset','RST']]){
    const facts=timing.filter(f=>f.role===role||(role==='clock'&&f.role==='single_event'));
    if(!facts.length)continue;
    for(const fact of facts){
     if(!graph.edges.some(e=>e.rendered!==false&&e.target===n.id&&
       e.type==='event'&&(e.pin||e.targetPin)===pin&&
       (e.source.endsWith('::sig:'+fact.signal)||e.source===fact.signal)))
      err('missing_sequential_terminal',n.id,
       pin+' event from '+fact.signal+' omitted from visible FF');
    }
   }
  }
  // Operators and D pins have one *electrical* driver per input terminal.
  // Multiple AST control relationships are not electrical conductors.
  const sinks=new Map();
  for(const e of graph.edges.filter(e=>e.rendered!==false)){
   const n=nodes.get(e.target);if(!n)continue;
   if(n.type!=='operator'&&!['register','counter','fsm'].includes(n.type))continue;
   if(e.type==='event')continue;
   const pin=n.type==='operator'?(e.targetPin||e.pin||'IN'):'D';
   const key=n.id+'\u001f'+pin;
   const drivers=sinks.get(key)||new Set();drivers.add(e.source+'\u001f'+String(e.sourcePin||''));sinks.set(key,drivers);
  }
  for(const [key,sources] of sinks)if(sources.size>1)
   err('multiple_electrical_input_drivers',key,sources.size+' sources to same operator/FF terminal');
  return {errors,warnings,nodes:graph.nodes.length,edges:graph.edges.length};
 }
 function checkProjection(original,display,{limit=40}={}){
  const result=check(display,{limit,checkOriginalGroups:false});
  const errors=result.errors,warnings=result.warnings;
  const err=(code,id,description)=>{if(errors.length<limit)errors.push({code,id,description});};
  const src=new Map(original.edges.map(e=>[e.id,e]));
  const originalNodes=new Map(original.nodes.map(n=>[n.id,n]));
  const displayNodes=new Map(display.nodes.map(n=>[n.id,n]));
  const groups=new Map((original.processGroups||[]).map(g=>[g.token,g]));
  const projectedIds=new Set();
  for(const e of display.edges){
   const prior=src.get(e.id);
   if(!prior){err('invented_edge',e.id,'No original Slang-backed edge');continue;}
   projectedIds.add(e.id);
   if(e.rendered!==prior.rendered||e.net!==prior.net||e.type!==prior.type)
    err('altered_electrical_fact',e.id,'Render state, net or edge kind changed');
   if(e.processOriginalSource&&e.processOriginalSource!==prior.source)
    err('incorrect_source_provenance',e.id,'Original source identity changed');
   if(e.processOriginalTarget&&e.processOriginalTarget!==prior.target)
    err('incorrect_target_provenance',e.id,'Original target identity changed');
   for(const [role,key] of [['source','sourcePin'],['target','targetPin']]){
    const n=displayNodes.get(e[role]);
    if(!n||!['process_group','fsm_group'].includes(n.type))continue;
    const expectedDirection=role==='source'?'output':'input';
    const port=(n.ports||[]).find(p=>p.name===e[key]&&p.direction===expectedDirection);
    if(!port)err('missing_group_terminal',e.id,role+' '+String(e[key]));
    if(role==='source'&&port?.timingRole==='clock')err('clock_on_output',e.id,'Clock rendered on output side');
    const group=n.type==='process_group'?groups.get(n.group):
      (display.fsmGroups||[]).find(g=>g.token===n.group);
    if(!group){err('unknown_virtual_group',e.id,'Virtual block missing AST provenance');continue;}
    if(n.type==='fsm_group')continue;
    if(e.processProjection==='partial-field input'&&role==='target'){
     const pairs=group.partialPortInputs||[];
     if(!pairs.some(p=>p.source===prior.source&&p.target===prior.target))
      err('unauthorized_field_redirect',e.id,'Partial field edge not from this AST process');
    }
    if(role==='source'&&e.sourcePin?.includes(':')){
     const target=originalNodes.get(prior.target);
     if(target?.type==='port'&&['out','output'].includes(String(target.direction||'').toLowerCase())&&
        !new Set(group.targetIds||[]).has(prior.target)&&
        e.sourcePin?.endsWith(':'+target.name))
      err('foreign_port_claim',e.id,'Process claims a module port written by another process');
    }
   }
  }
  // Flattening an FSM exposes only its *immediate* process layer. Its
  // processes can also own logic outside the FSM cone. That outside logic
  // and every original crossing edge must survive the transformation; an
  // ordinary per-process edge accounting check would miss this loss because
  // it would call the edge "internal to the collapsed always block".
  for(const fsm of (display.fsmGroups||[]).filter(g=>g.view==='expanded')){
   const owned=new Set(fsm.memberIds||[]);
   for(const edge of original.edges){
    if(edge.rendered===false||owned.has(edge.source)===owned.has(edge.target))continue;
    if(!projectedIds.has(edge.id))
     err('fsm_boundary_edge_lost',edge.id,
      'Flatten removed a compiler-backed edge across FSM '+fsm.token);
   }
   for(const process of original.processGroups||[]){
    const members=process.memberIds||[];
    if(!members.some(id=>owned.has(id)))continue;
    for(const id of members){
     if(owned.has(id)||!originalNodes.has(id))continue;
     if(!displayNodes.has(id))
      err('fsm_external_process_node_lost',id,
       'Flatten swallowed non-FSM logic belonging to '+process.token);
    }
   }
  }
  for(const n of display.nodes.filter(n=>['process_group','fsm_group'].includes(n.type))){
   const group=n.type==='process_group'?groups.get(n.group):
     (display.fsmGroups||[]).find(g=>g.token===n.group);
   if(!group)continue;
   const names=new Set();
   for(const p of n.ports||[]){
    if(names.has(p.name))err('duplicate_group_port',n.id,p.name);
    names.add(p.name);
    if(!['input','output'].includes(p.direction))err('group_port_direction',n.id,p.name);
    if(p.direction==='output'&&['clock','async_reset'].includes(p.timingRole))
     err('timing_on_output',n.id,p.name);
   }
   for(const p of n.ports||[]){
    const incidents=display.edges.filter(e=>e.rendered!==false&&
     ((p.direction==='input'&&e.target===n.id&&e.targetPin===p.name)||
      (p.direction==='output'&&e.source===n.id&&e.sourcePin===p.name)));
    if(p.connection==='bound'&&!incidents.length)err('false_bound_terminal',n.id,p.name);
    if(p.connection!=='bound'&&incidents.length)err('false_unbound_terminal',n.id,p.name);
   }
  }
  for(const g of display.fsmGroups||[]){
   const state=originalNodes.get(g.stateId);
   if(!state||state.type!=='fsm')err('unproven_fsm_state',g.token,'No compiler-backed FSM state register');
   const members=new Set(g.memberIds||[]);
   for(const id of members)if(!originalNodes.has(id))err('fsm_member_missing',g.token,id);
   for(const id of g.clockIds||[]){
    if(!new Set(g.inputIds||[]).has(id)||!original.edges.some(e=>e.rendered!==false&&
        e.source===id&&e.target===g.stateId&&e.type==='event'))
     err('unproven_fsm_clock',g.token,id);
   }
   for(const id of g.asyncResetIds||[]){
    if(!new Set(g.inputIds||[]).has(id)||!original.edges.some(e=>e.rendered!==false&&
        e.source===id&&e.target===g.stateId&&e.type==='event'))
     err('unproven_fsm_async_reset',g.token,id);
   }
  }
  return {...result,originalEdges:original.edges.length,visibleEdges:display.edges.length};
 }
 async function checkLayout(graph,elk){
  const errors=[];
  try{
   const out=await A.compute(elk,graph,G.boxSize);
   for(const failure of A.checkCompoundOwnership(graph,out))
    errors.push({code:'flatten_compound_ownership',id:'',description:failure});
   const byId=new Map(graph.nodes.map(n=>[n.id,n]));
   for(const e of graph.edges.filter(e=>e.rendered!==false)){
    const p=out.edgePaths.get(e.id);
    if(!p||p.length<2){errors.push({code:'missing_elk_path',id:e.id});continue;}
    const from=G.absoluteAnchor(byId.get(e.source),out.positions.get(e.source),'source',e);
    const to=G.absoluteAnchor(byId.get(e.target),out.positions.get(e.target),'target',e);
    const eq=(a,b)=>Math.abs(a-b)<0.001;
    if(!eq(p[0][0],from.x)||!eq(p[0][1],from.y)||
       !eq(p.at(-1)[0],to.x)||!eq(p.at(-1)[1],to.y))
     errors.push({code:'elk_canvas_endpoint_mismatch',id:e.id});
   }
  }catch(e){errors.push({code:'elk_layout_failure',id:'',description:String(e)});}
  return {errors};
 }
 const api={check,checkProjection,checkLayout};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexRenderContract=api;
})(typeof window==='object'?window:globalThis);
