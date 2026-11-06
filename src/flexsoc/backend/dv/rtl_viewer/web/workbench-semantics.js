'use strict';
/* Read-only presentation helpers. Do not infer hardware connectivity or source lines. */
(function(root){
 function short(value,max=100){const s=String(value??'').trim();return s.length>max?s.slice(0,max-1)+'…':s;}
 function semantic(item){
  if(!item||typeof item!=='object')return null;
  if(item.source&&item.target){
   const kind=item.type==='event'?'Timing relation':item.type==='control'?'Control dependency':
    item.type==='address'?'Address dependency':item.type==='sequential'?'Sequential data':
    item.type==='port_in'||item.type==='port_out'?'Port connection':'Data connection';
   const rendered=item.rendered!==false;
   return {kind,name:short(item.signal||item.net||item.id),tone:!rendered?'partial':item.type==='event'?'timing':'data',
    rows:[['From',short(item.source,84)],['To',short(item.target,84)],
     ['Status',rendered?'Routed in schematic':'Dependency only — not routed'],
     ['Mapping',short(item.mapping||'direct',60)],
     ...(item.pin||item.targetPin?[['Terminal',short(item.targetPin||item.pin,40)]]:[])]};
  }
  const type=String(item.type||'unknown');
  const kind=type==='process_group'?'Procedural block (virtual)':type==='fsm_group'?'Virtual FSM':type==='fsm'?'FSM state register':type==='register'?'Register':
   type==='counter'?'Counter':type==='operator'?'RTL operator':type==='signal'?'Signal':
   type==='port'?'Module port':type==='instance'?'Module instance':type==='generate'?'Generate group':short(type,60);
  const rows=[];
  if(item.kind)rows.push(['Operation',short(item.kind,70)]);
  if(item.controlSource)rows.push(['Controller',short(item.controlSource,70)]);
  if(item.controlPatterns?.length)rows.push(['Case values',short(item.controlPatterns.join(', '),90)]);
  if(item.origin)rows.push(['Derived from',short(item.origin,70)]);
  if(item.source_file)rows.push(['Source',short(item.source_file,80)]);
  if(Number.isInteger(item.line)&&item.line>0)rows.push(['RTL line','L'+item.line]);
  if(item.width)rows.push(['Type / width',short(item.width,90)]);
  if(item.dInputStatus)rows.push(['D input',short(item.dInputStatus,90)]);
  if(type==='fsm_group')rows.push(['Scope','Virtual grouping — original AST and edges preserved']);
  if(type==='process_group'){
   const process=item.processSummary||{};
   rows.push(['Process',short(process.kind||item.name,60)]);
   rows.push(['Projection',short(process.coverage||'partial',60)]);
   if(process.sourceLine)rows.push(['RTL source','L'+process.sourceLine]);
   rows.push(['Scope','Virtual grouping — original Slang nodes and edges']);
   if(process.unresolvedTargets?.length)rows.push(['Unsupported',short(process.unresolvedTargets.join(', '),90)]);
   rows.push(['Actions','Double click: enter · Right click: flatten here']);
  }
  return {kind,name:short(item.name||item.id||kind,90),tone:type==='process_group'?'logic':type.startsWith('fsm')?'fsm':type==='register'?'timing':type==='operator'?'logic':'data',rows};
 }
 function sameFile(a,b){
  const norm=v=>String(v||'').replaceAll('\\','/').replace(/\/+/g,'/').replace(/^\.\//,'');
  const left=norm(a),right=norm(b);
  return !!left&&!!right&&(left===right||left.endsWith('/'+right)||right.endsWith('/'+left));
 }
 function lintMarks(result,sourceFile,lineCount){
  const output=new Map();
  if(!result||result.status!=='available'||!sameFile(result.file,sourceFile))return output;
  const severityRank={P0:0,P1:1,P2:2,P3:3};
  for(const d of Array.isArray(result.diagnostics)?result.diagnostics:[]){
   if(d.file&&!sameFile(d.file,sourceFile))continue;
   const line=Number(d.line??d.start_line??d.location?.line??0);
   if(!Number.isSafeInteger(line)||line<1||line>lineCount)continue;
   const raw=String(d.priority||d.pri||'').toUpperCase();
   const severity=String(d.severity||'').toLowerCase();
   const p=severityRank[raw]!==undefined?raw:severity==='error'||severity==='fatal'?'P0':severity==='warning'?'P2':'P3';
   const entry={priority:p,code:short(d.code||'lint',52),message:short(d.message||d.text||'Diagnostic',180)};
   if(!output.has(line))output.set(line,[]);
   output.get(line).push(entry);
  }
  for(const entries of output.values())entries.sort((a,b)=>severityRank[a.priority]-severityRank[b.priority]);
  return output;
 }
 const api={semantic,sameFile,lintMarks};
 if(typeof module==='object'&&module.exports)module.exports=api;
 root.FlexWorkbenchSemantics=api;
})(typeof globalThis!=='undefined'?globalThis:this);
