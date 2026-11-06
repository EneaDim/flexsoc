'use strict';
/* Reversible, presentation-only process shells. Never synthesize a wire. */
(function(root){
 function project(graph, expanded=[], {allowPartial=false, excludedIds=[]}={}){
  const expandedSet=new Set(expanded),excluded=new Set(excludedIds);
  let nodes=[...graph.nodes],edges=[...graph.edges];
  const groups=[];
  const originalNodes=new Map(graph.nodes.map(n=>[n.id,n]));
  const used=new Set();
  // An FSM is a *subset* of the procedural cones that implement it. A single
  // always_comb can also produce unrelated outputs in the parent module.
  // Collapsing its entire cone as a child of the flattened FSM would steal
  // those external nodes and even swallow compiler-backed edges crossing
  // the FSM boundary. Only the FSM-owned part may become a nested child.
  const flattenedFsms=(graph.fsmGroups||[])
   .filter(g=>expandedSet.has(g.token)&&g.view==='expanded'&&Array.isArray(g.memberIds))
   .map(g=>({...g,owned:new Set(g.memberIds),externalInputs:new Set(g.inputIds||[])}));
  for(const item of graph.processGroups||[]){
   if(!item||!/^proc:\d+$/.test(item.token)||!Array.isArray(item.memberIds))continue;
   const present=new Set(nodes.map(n=>n.id));
   const candidates=item.memberIds.filter(id=>present.has(id)&&!excluded.has(id)&&!used.has(id));
   const parents=flattenedFsms.filter(g=>candidates.some(id=>g.owned.has(id)));
   // A single virtual process must never be assigned to two FSM compounds.
   // Leave such a process ungrouped rather than silently hide either cone.
   if(parents.length>1)continue;
   const parentFsm=parents[0],nestedFsm=!!parentFsm;
   const members=nestedFsm?candidates.filter(id=>parentFsm.owned.has(id)):candidates;
   if(!members.length)continue;
   if(!allowPartial&&!nestedFsm&&members.length!==item.memberIds.length)continue;
   const partial=members.length!==item.memberIds.length;
   const group={...item,view:expandedSet.has(item.token)?'flattened':'collapsed',
     // A focus view (e.g. an FSM interior) may expose only a subset of this
     // process. Keep the canonical members separately, but give ELK exactly
     // the visible members it may enclose. Never claim that omitted cells are
     // inside a flattened frame.
     ...(partial?{originalMemberIds:item.memberIds,memberIds:members}:{}),
     coverage:partial?'fragment':item.coverage};
   groups.push(group);
   if(expandedSet.has(item.token))continue;
   const owned=new Set(members);
   const boundary=edges.filter(e=>e.rendered!==false&&
      (owned.has(e.source)!==owned.has(e.target)));
   // A partial write to one field of a public output is not a second
   // whole-bus electrical driver. The AST proves which process reads a bare
   // RHS reference (partialPortInputs); project that original dependency onto
   // the process input instead of leaving a misleading bypass to the Port.
   // Every projected edge retains the original ID, net and provenance target.
   const fieldInputPairs=new Set((item.partialPortInputs||[]).filter(p=>p&&
    typeof p.source==='string'&&typeof p.target==='string').map(p=>
     p.source+'\u001f'+p.target));
   const redirectedFieldInputs=edges.filter(e=>e.rendered!==false&&!owned.has(e.source)&&
     !owned.has(e.target)&&e.mapping==='partial'&&
     fieldInputPairs.has(String(e.processOriginalSource||e.source)+'\u001f'+String(e.processOriginalTarget||e.target))&&
     originalNodes.get(e.processOriginalTarget||e.target)?.type==='port');
   const redirectedIds=new Set(redirectedFieldInputs.map(e=>e.id));
   // A collapsed instance can source multiple different outputs.  Pair the
   // source identity with its named pin or we would short those nets.
   const sourceKey=e=>e.source+'\u001f'+String(e.sourcePin||'');
   // A process assigning a real output Port must still connect to that Port
   // when collapsed. Every output-port write retains its ORIGINAL AST edge,
   // but shares one visible bus boundary pin named after the port. Do not
   // merge arbitrary non-port operator outputs or unrelated nets.
   const processTargets=new Set(item.targetIds||[]);
   const outputKey=e=>{
    const target=originalNodes.get(e.target);
    // An upstream FF can feed a field written into a public struct by a
    // different always_comb. It does NOT thereby become a driver for the
    // complete struct output. Only the process that actually WRITES that
    // public port may claim a port-aggregated output pin.
    if(processTargets.has(e.target)&&target?.type==='port'&&
       ['out','output'].includes(String(target.direction||'').toLowerCase()))
     return 'port\u001f'+e.target;
    return sourceKey(e);
   };
   const incoming=[...new Set([...boundary.filter(e=>owned.has(e.target)),
       ...redirectedFieldInputs].map(sourceKey))].sort();
   const outgoing=[...new Set(boundary.filter(e=>owned.has(e.source)).map(outputKey))].sort();
   if(incoming.length>128||outgoing.length>128){groups.pop();continue;}
   // The physical sourcePin is part of the identity and must never be
   // discarded. Its displayed name, however, must not accumulate prefixes
   // when a virtual output feeds another virtual input (I03:O06:reset_crc).
   const originalName=key=>{
    const [id,pin]=key.split('\u001f');
    const node=originalNodes.get(id);
    const nested=pin&&(!node||['process_group','fsm_group','instance','generate'].includes(node.type));
    let label=String((nested?pin:node?.name)||pin||id.split('::sig:').at(-1).split('::').at(-1));
    if(nested){
     for(let i=0;i<8;i++){
      const cleaned=label.replace(/^(?:(?:I|O)\d+|CLK|RST|EVENT):/,'');
      if(cleaned===label)break;
      label=cleaned;
     }
    }
    return label;
   };
   const clockIds=new Set(item.clockIds||[]),asyncResetIds=new Set(item.asyncResetIds||[]);
   const pinSource=key=>key.split('\u001f')[0];
   // Use the CURRENT boundary's compiler-backed event role as well as the
   // original metadata. In nested projections an upstream virtual block can
   // replace the edge source ID; the event type/pin survives, but clockIds
   // still refers to the original source signal. A stale ID must never turn
   // an incoming CLK into a normal data pin (or an output pin).
   const timingByKey=new Map();
   for(const e of boundary){
    if(!owned.has(e.target)||e.type!=='event')continue;
    const role=e.timingRole==='async_reset'||e.pin==='RST'?'async_reset':
      e.timingRole==='clock'||e.timingRole==='single_event'||e.pin==='CLK'?'clock':null;
    if(!role)continue;
    const key=sourceKey(e),previous=timingByKey.get(key);
    timingByKey.set(key,previous&&previous!==role?'ambiguous':role);
   }
   const roleForKey=key=>{
    const eventRole=timingByKey.get(key);
    if(eventRole)return eventRole==='ambiguous'?'data':eventRole;
    // A same-named clock used as data in this process is still an input,
    // but must not gain a fake timing glyph when no event edge proves it.
    const sourceId=pinSource(key);
    return clockIds.has(sourceId)?'clock':asyncResetIds.has(sourceId)?'async_reset':'data';
   };
   // Timing is an INPUT to a process. Show its proven event terminals at
   // the top of the WEST side; normal data (including synchronous reset)
   // follows. This is ordering only: edge IDs and ELK endpoints are intact.
   const rank=key=>roleForKey(key)==='clock'?0:roleForKey(key)==='async_reset'?1:2;
   const orderedIncoming=[...incoming].sort((a,b)=>rank(a)-rank(b)||originalName(a).localeCompare(originalName(b))||a.localeCompare(b));
   const usedPortNames=new Set();
   const uniqueName=label=>{
    if(!usedPortNames.has(label)){usedPortNames.add(label);return label;}
    let index=2;
    while(usedPortNames.has(label+' #'+index))index++;
    label=label+' #'+index;usedPortNames.add(label);return label;
   };
   const inputPorts=new Map(orderedIncoming.map((key,i)=>[key,uniqueName(
    (roleForKey(key)==='clock'?'CLK:':roleForKey(key)==='async_reset'?'RST:':
     `I${String(i).padStart(2,'0')}:`)+originalName(key).slice(0,36))]));
   const unresolvedInputs=(item.unresolvedInputIds||[]).filter(id=>
    (!nestedFsm||parentFsm.externalInputs.has(id))&&
    !incoming.some(k=>pinSource(k)===id));
   for(const id of unresolvedInputs){
    const key=id+'\u001f';
    inputPorts.set(key,uniqueName(`I${String(inputPorts.size).padStart(2,'0')}:`+originalName(key).slice(0,36)));
   }
   const outputName=key=>key.startsWith('port\u001f')?
    String(originalNodes.get(key.slice(5))?.name||key.slice(5)):originalName(key);
   const outputPorts=new Map(outgoing.map((key,i)=>[key,
    `O${String(i).padStart(2,'0')}:`+outputName(key).slice(0,36)]));
   // Outputs are the destinations written by this process, even when a
   // truncated view contains no consumer. Such pins remain visibly unbound;
   // they are NOT backed by a fabricated electrical edge.
   const targetIds=(item.targetIds||[]);
   for(const target of targetIds){
    // On an FSM subset, the other writes of this same always block are
    // outside the selected FSM. Do not advertise them as unbound outputs of
    // its child process; only emit pins proven by the visible boundary.
    if(nestedFsm&&!owned.has(target))continue;
    if([...outputPorts.keys()].some(key=>key.split('\u001f')[0]===target||key==='port\u001f'+target))continue;
    const key=target+'\u001f';
    outputPorts.set(key,`O${String(outputPorts.size).padStart(2,'0')}:`+originalName(key).slice(0,36));
   }
   if(inputPorts.size>128||outputPorts.size>128){groups.pop();continue;}
   const id=graph.path+'::procgroup:'+item.token.slice(5);
   const ports=[...inputPorts].map(([source,name])=>{
    return {name,direction:'input',connection:incoming.includes(source)?'bound':'unresolved',
      timingRole:roleForKey(source)};
   }).concat([...outputPorts].map(([key,name])=>({name,direction:'output',
    connection:outgoing.includes(key)?'bound':item.unresolvedTargets?.includes(originalName(key))?'unresolved':'unbound'})));
   const box={id,name:item.name,type:'process_group',group:item.token,ports,
    module:'Virtual '+item.kind+' · enter or flatten',processSummary:group,
    hiddenNodeIds:[...owned],classification:'Slang process + existing circuit edges'};
   const next=[];
   for(const edge of edges){
    const a=owned.has(edge.source),b=owned.has(edge.target);
    if(a&&b)continue;
    if((a||b)&&edge.rendered===false)continue;
    if(!a&&!b&&!redirectedIds.has(edge.id)){next.push(edge);continue;}
    const updated={...edge,
      processOriginalSource:edge.processOriginalSource||edge.source,
      processOriginalTarget:edge.processOriginalTarget||edge.target,
      processProjection:'boundary-only'};
    if(b||redirectedIds.has(edge.id)){
     updated.target=id;
     updated.targetPin=inputPorts.get(sourceKey(edge));
     if(redirectedIds.has(edge.id)){
      updated.partialWriteSource='Slang direct RHS of a partial public-port assignment';
      updated.processProjection='partial-field input';
     }
    }else{updated.source=id;updated.sourcePin=outputPorts.get(outputKey(edge));}
    next.push(updated);
   }
   edges=next;nodes=nodes.filter(n=>!owned.has(n.id));nodes.push(box);
   for(const member of owned)used.add(member);
  }
  return {...graph,nodes,edges,processGroups:groups};
 }
 function focus(graph,token){
  const group=(graph.processGroups||[]).find(g=>g.token===token);
  if(!group||!Array.isArray(group.memberIds))throw Error('Process interior is unavailable');
  const members=new Set(group.memberIds);
  const inputIds=new Set([...(group.inputIds||[]),...(group.unresolvedInputIds||[])]);
  const outputIds=new Set(group.outputTargets||[]);
  const visible=new Set([...members,...inputIds,...outputIds]);
  // Every symbol OUTSIDE the process is a boundary terminal, regardless
  // of whether it is a signal, function result, FF or another operator.
  // Rendering the full external symbol in this focused slice falsely
  // implies that its driver and *all* of its inputs are present here. In
  // particular a continuous assign outside an always_comb must appear as
  // IN rx_fcs_count_now, not as an un-driven wire inside this process.
  // Preserve the exact original ID and all compiler-backed boundary edges.
  const nodes=graph.nodes.filter(n=>visible.has(n.id)).map(n=>{
   if(members.has(n.id))return n;
   const direction=inputIds.has(n.id)&&outputIds.has(n.id)?'inout':
    inputIds.has(n.id)?'in':'out';
   return {...n,type:'port',direction,boundaryProjection:'external-process-signal',
    boundaryOriginalType:n.type};
  });
  const edges=graph.edges.filter(e=>visible.has(e.source)&&visible.has(e.target));
  if(!nodes.length)throw Error('Process is not present in the current graph slice');
  return {...graph,nodes,edges,total:nodes.length,truncated:false,
    module:group.name,virtualParent:graph.path,processGroups:graph.processGroups.map(g=>({
      ...g,view:g.token===token?'entered':g.view}))};
 }
 const api={project,focus};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexVirtualProcess=api;
})(typeof window==='object'?window:globalThis);
