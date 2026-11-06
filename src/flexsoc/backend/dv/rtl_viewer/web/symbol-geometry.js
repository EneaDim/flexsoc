'use strict';
/* Canonical drawing geometry. Hardware identity/connectivity come from Slang,
 * layout positions and routes from ELK; this module owns ONLY glyph sizes,
 * named pin terminals and module-port row placement. No graph mutations. */
(function(root){
 const directions={in:'input',input:'input',out:'output',output:'output',inout:'inout'};
 const direction=p=>directions[String(p?.direction||'').toLowerCase()]||null;
 const sequential=new Set(['register','counter','fsm']);
 // Names are emitted by Slang's operator AST, never derived from signal names.
 // Unknown operations receive an explicit fallback rather than a fabricated gate.
 const operations=Object.freeze({
  add:['+','arithmetic'],plus:['+','arithmetic'],subtract:['−','arithmetic'],sub:['−','arithmetic'],
  multiply:['×','arithmetic'],mul:['×','arithmetic'],divide:['÷','arithmetic'],div:['÷','arithmetic'],
  mod:['%','arithmetic'],modulo:['%','arithmetic'],power:['^','arithmetic'],
  bitwiseand:['&','and'],binaryand:['&','and'],logicaland:['&&','and'],and:['&','and'],
  bitwiseor:['|','or'],binaryor:['|','or'],logicalor:['||','or'],or:['|','or'],
  bitwisexor:['^','xor'],binaryxor:['^','xor'],logicalxor:['^^','xor'],xor:['^','xor'],
  bitwisenot:['~','not'],unarybitwisenot:['~','not'],unarylogicalnot:['!','not'],logicalnot:['!','not'],not:['!','not'],
  unaryminus:['−','arithmetic'],unaryplus:['+','arithmetic'],
  equal:['=','compare'],equals:['=','compare'],equality:['=','compare'],
  notequal:['≠','compare'],inequality:['≠','compare'],
  casenotequal:['≢','compare'],caseequal:['≡','compare'],
  lessthan:['<','compare'],greaterthan:['>','compare'],
  lessequal:['≤','compare'],lessorequal:['≤','compare'],lessthanequal:['≤','compare'],
  greaterequal:['≥','compare'],greaterorequal:['≥','compare'],greaterthanequal:['≥','compare'],
  shiftleft:['≪','arithmetic'],shiftright:['≫','arithmetic'],
  arithmeticshiftright:['≫','arithmetic'],arithmeticshiftleft:['≪','arithmetic'],
  conversion:['CAST','generic'],concatenation:['CONCAT','generic'],replication:['REP','generic']
 });
 function operatorFace(node){
  const normalized=String(node.name||node.kind||'').replace(/[\s_-]/g,'').toLowerCase();
  const entry=operations[normalized];
  if(entry)return {mark:entry[0],family:entry[1],known:true};
  // A backed AST operator can still be unsupported by the glyph catalog.
  return {mark:'OP',family:'generic',known:false};
 }
 function boxSize(n){
  if(n.type==='instance'||n.type==='generate'||n.type==='process_group'||n.type==='fsm_group'){
   const inputs=(n.ports||[]).filter(p=>['input','inout'].includes(direction(p))).length;
   const outputs=(n.ports||[]).filter(p=>['output','inout'].includes(direction(p))).length;
   // Measure *labels* predictably using the renderer's monospace font. Long
   // port names must not collide across the two columns. Capped width keeps
   // complex instances usable without expanding whole graphs indefinitely.
   const widest=(role)=>Math.max(0,...(n.ports||[])
    .filter(p=>[role,'inout'].includes(direction(p)))
    .map(p=>String(p.name||'').length));
   const labels=widest('input')+widest('output');
   const w=Math.min(356,Math.max(220,64+Math.min(labels,38)*7));
   return {w,h:Math.max(100,64+Math.max(inputs,outputs)*19)};
  }
  if(sequential.has(n.type))return {w:144,h:102};
  if(n.type==='operator'){
   // An elaboration-time constant is one inline value source. Its original
   // expression kind and type stay available to the inspector.
   if(n.shape==='constant')return {w:Math.min(172,Math.max(64,28+String(n.constantValue||'?').length*8)),h:34};
   // Field extraction is a lightweight value projection, not a logic cell.
   // Keep the inline capsule bounded even for long member names.
   if(n.shape==='field')return {w:Math.min(126,Math.max(62,24+String(n.field||'').length*6)),h:32};
   if(n.shape==='slice')return {w:Math.min(136,Math.max(72,26+String(n.selection||'').length*8)),h:Math.max(36,20+Math.max(1,(n.pins||[]).length-1)*20)};
   if(n.shape==='case')return {w:120,h:78};
   if(n.shape==='mux')return {w:102,h:82};
   if(n.shape==='function'){
    const count=Array.isArray(n.pins)?n.pins.filter(p=>/^I\d+$/.test(p)).length:0;
    return {w:Math.min(184,Math.max(116,34+String(n.name||'').length*7)),
            h:Math.max(54,20+Math.min(count,16)*20)};
   }
   if(operatorFace(n).mark==='CAST')return {w:56,h:32};
   if(n.kind==='Concatenation'||n.kind==='Replication'){
    const inputs=Array.isArray(n.pins)?n.pins.filter(p=>/^I\d+$/.test(p)).length:0;
    // Distinct WEST terminals, in source order, with enough room for labels.
    return {w:92,h:Math.max(44,20+Math.min(inputs,32)*20)};
   }
   if(['and','or','xor'].includes(operatorFace(n).family))return {w:96,h:72};
   if(operatorFace(n).family==='not')return {w:66,h:50};
   if(!operatorFace(n).known)return {w:114,h:76};
   return {w:n.shape==='arith'?88:78,h:66};
  }
  if(n.type==='port')return {w:144,h:44};
  return {w:170,h:n.dimensions?.unpackedDimensions?56:42};
 }
 // The row contract is shared by the Canvas port glyph and by ELK ports.
 function portRows(node,role,size=boxSize(node)){
  const source=role==='source';
  const requested=source?'output':'input';
  return (node.ports||[]).filter(p=>[requested,'inout'].includes(direction(p)))
   .map((port,index)=>({port,index,x:source?size.w:0,
      y:(source?65:53)+index*19,side:source?'EAST':'WEST'}));
 }
 function pinName(e,role){
  // A rewritten virtual boundary owns an explicit named target terminal.
  // In particular, event edges retain their source timingRole/pin as AST
  // evidence, but must anchor at the *new* CLK:/RST: virtual port, never
  // at the old FF pin name or at an unnamed fallback center.
  return String(role==='source'?(e.sourcePin||e.source_port||e.port||e.pin||''):
   (e.targetPin||e.port||(e.type==='event'?(e.pin||'EVENT'):(e.pin||''))));
 }
 function anchor(node,role,e,size=boxSize(node)){
  const {w,h}=size,source=role==='source',name=pinName(e,role);
  if(node.type==='port'){
   const d=direction(node);if(!d)throw Error('undirected top-level port: '+node.id);
   const east=d==='input'||(d==='inout'&&source);
   return {x:east?w:0,y:h/2,side:east?'EAST':'WEST'};
  }
  if(node.type==='signal')return {x:source?w:0,y:h/2,side:source?'EAST':'WEST'};
  if(node.type==='instance'||node.type==='generate'||node.type==='fsm_group'||node.type==='process_group'){
   const row=portRows(node,role,size).find(r=>r.port.name===name);
   // Virtual process/FSM port names must match exactly. A fallback center
   // falsely depicts the wire attached to the wrong pin (especially CLK/RST).
   if(!row&&['fsm_group','process_group'].includes(node.type))
    throw Error('Unmatched virtual boundary port: '+node.id+' / '+name);
   return row?{x:row.x,y:row.y,side:row.side}:
    {x:source?w:0,y:h/2,side:source?'EAST':'WEST'};
  }
  if(sequential.has(node.type)){
   // Reads of an always_ff destination leave Q; assignment writes enter D.
   // Equal SV declaration names do not mean the Q and D terminals coincide.
   if(source)return {x:w,y:20,side:'EAST'};
   if(name==='CLK')return {x:w*.34,y:h,side:'SOUTH'};
   if(name==='RST'||name==='EVENT')return {x:w*.67,y:h,side:'SOUTH'};
   return {x:0,y:20,side:'WEST'};
  }
  if(node.type==='operator'){
   if(source)return {x:w,y:h/2,side:'EAST'};
   // The terminal count comes from AST-derived pin roles, never from the
   // name of a connected signal. Single-input operations (FIELD, CAST, NOT,
   // unary arithmetic, etc.) have one physical lead at the WEST midpoint.
   const roles=Array.isArray(node.pins)?node.pins.filter(p=>p!=='Y'&&p!=='S'):[];
   const unary=roles.length===1 || (roles.length===0 &&
    (node.shape==='field'||['CAST','CONCAT'].includes(operatorFace(node).mark)||
     operatorFace(node).family==='not'||node.kind==='UnaryOp'));
   if(node.kind==='Concatenation'||node.kind==='Replication'||node.shape==='function'){
    const index=roles.indexOf(name);
    if(index>=0 && /^I\d+$/.test(name)){
     return {x:0,y:roles.length===1?h/2:20+index*20,side:'WEST'};
    }
   }
   if(node.shape==='slice'&&roles.length>1){
    const index=roles.indexOf(name);
    if(index>=0)return {x:0,y:20+index*20,side:'WEST'};
   }
   if(unary)return {x:0,y:h/2,side:'WEST'};
   if(node.shape==='mux'){
    if(name==='A')return {x:0,y:22,side:'WEST'};
    if(name==='B')return {x:0,y:h-22,side:'WEST'};
    if(name==='S')return {x:w/2,y:h,side:'SOUTH'};
   }
   if(name==='A')return {x:0,y:18,side:'WEST'};
   if(name==='B')return {x:0,y:h-18,side:'WEST'};
   return {x:0,y:h/2,side:'WEST'};
  }
  return {x:source?w:0,y:h/2,side:source?'EAST':'WEST'};
 }
 function absoluteAnchor(node,rect,role,e){
  const p=anchor(node,role,e,{w:rect.w,h:rect.h});
  return {x:rect.x+p.x,y:rect.y+p.y,side:p.side};
 }
 const api={boxSize,portRows,anchor,absoluteAnchor,pinName,operatorFace};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexSymbolGeometry=api;
})(typeof window==='object'?window:globalThis);
