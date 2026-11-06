'use strict';
/* Geometry-only Canvas glyph painter. ELK owns placement; Slang owns semantics.
 * The same FlexSymbolGeometry anchors are consumed by drawing and routing.
 * This module neither reads UI state nor mutates graph/ELK objects. */
(function(root){
 const FlexSymbolGeometry=typeof module==='object'&&module.exports?
  require('./symbol-geometry.js'):root.FlexSymbolGeometry;
 if(!FlexSymbolGeometry)throw Error('Symbol geometry unavailable');
 function round(ctx,x,y,w,h,r){ctx.beginPath();ctx.roundRect(x,y,w,h,r);}
// FSRTL-0055 compact symbols: verified functional operator glyphs and distinct event terminals.
function rtlLabel(value){return String(value).replace(/(^|[.\s])\d{8,}\s+/g,'$1');}

// Only AST-proven event polarity may decorate a timing terminal. An event
// edge by itself does not establish that a signal is clock or reset.
function negEdgeIsProven(node,pin){
 const roles=pin==='CLK'?new Set(['clock','single_event']):
  pin==='RST'?new Set(['async_reset']):null;
 if(!roles)return false;
 const facts=(node.sequentialTiming||[]).filter(f=>roles.has(f.role));
 return facts.length>0&&facts.every(f=>f.edge==='NegEdge');
}
// Render hardware operations without using operand text as a substitute for
// electrical topology. Long AST paths live in the inspector, not on pin glyphs.
function smallOperand(value){
 const text=rtlLabel(value).trim();
 if(!text)return '';
 // Only short literal constants should be drawn on the schematic: a long
 // expression path obscures the glyph and is not an electrical net label.
 if(text.length>9||/[\s.\[\]]/.test(text))return '';
 return text;
}
function summarizeCaseLabels(values){
 const list=Array.isArray(values)?values.filter(v=>typeof v==='string').map(v=>rtlLabel(v).trim()).filter(Boolean):[];
 if(!list.length)return '';
 const clipped=list.map(v=>v.length>16?v.slice(0,15)+'…':v);
 const head=clipped.slice(0,2).join(' | ');
 return clipped.length>2?head+' …':head;
}
function summarizeControlText(node){
 const source=rtlLabel(String(node.controlSource||'')).trim();
 const patterns=summarizeCaseLabels(node.controlPatterns||node.casePatterns||node.literalOperands?.patterns);
 if(source&&patterns)return (source+' · '+patterns).slice(0,28);
 return (patterns||source).slice(0,28);
}
function paintOperatorFace(ctx,n,{x,y,w,h},colors){
 const face=FlexSymbolGeometry.operatorFace(n),mid=y+h/2;
 const left=x+12,right=x+w-12,top=y+8,bottom=y+h-8;
 // No input terminal is drawn for a compiler-proven constant. In
 // particular, a folded parameter replication is not an unknown wire.
 if(n.shape==='constant'){
  round(ctx,left,top,right-left,bottom-top,5);ctx.fill();ctx.stroke();
  ctx.save();ctx.fillStyle=colors.text;ctx.textAlign='center';
  ctx.font='bold 11px ui-monospace,monospace';
  ctx.fillText(String(n.constantValue||'?'),x+w/2,mid+4,w-30);
  ctx.restore();
 }else
 // A field selector represents a Slang MemberAccess expression. Its input
 // is a partial struct dependency; the Y wire is the selected field value.
 // Do not suggest a bit-exact unpacking position that the model lacks.
 if(n.shape==='field'){
  // Small inline projection: the field name is the useful information.
  // Keeping a single text row avoids wasting vertical space on a header.
  round(ctx,left,top,right-left,bottom-top,5);ctx.fill();ctx.stroke();
  ctx.save();ctx.textAlign='center';ctx.fillStyle=colors.text;
  ctx.font='bold 10px ui-monospace,monospace';
  ctx.fillText('.'+String(n.field||'?'),x+w/2,mid+3.5,w-30);
  ctx.restore();
 }else if(n.shape==='slice'){
  // Packed-range extraction is an AST value projection, not a new bus.
  round(ctx,left,top,right-left,bottom-top,5);ctx.fill();ctx.stroke();
  ctx.save();ctx.textAlign='center';ctx.fillStyle=colors.text;
  ctx.font='bold 10px ui-monospace,monospace';
  ctx.fillText(String(n.selection|| (n.selectionKind==='ElementSelect'?'[index]':'?')),x+w/2,mid+3.5,w-26);
  ctx.restore();
 }else if(n.shape==='function'){
  // A function call is a compiler-backed, opaque value transform, not a
  // synthesized logic gate. Show the actual subroutine name and typed pins.
  round(ctx,left,top,right-left,bottom-top,7);ctx.fill();ctx.stroke();
 }else if(face.mark==='CAST'||face.mark==='CONCAT'||face.mark==='REP'){
  // Compact horizontal type conversion; no second oversized caption.
  ctx.beginPath();ctx.moveTo(left,mid);ctx.lineTo(left+6,top);
  ctx.lineTo(right-6,top);ctx.lineTo(right,mid);
  ctx.lineTo(right-6,bottom);ctx.lineTo(left+6,bottom);
  ctx.closePath();ctx.fill();ctx.stroke();
 }else if(face.family==='and'){
  ctx.beginPath();ctx.moveTo(left,top);ctx.lineTo(x+w*.51,top);
  ctx.quadraticCurveTo(right+12,mid,x+w*.51,bottom);
  ctx.lineTo(left,bottom);ctx.closePath();ctx.fill();ctx.stroke();
 }else if(face.family==='or'||face.family==='xor'){
  ctx.beginPath();ctx.moveTo(left+6,top);
  ctx.quadraticCurveTo(right-3,top-1,right,mid);
  ctx.quadraticCurveTo(right-3,bottom+1,left+6,bottom);
  ctx.quadraticCurveTo(left+22,mid,left+6,top);
  ctx.closePath();ctx.fill();ctx.stroke();
  if(face.family==='xor'){
   ctx.beginPath();ctx.moveTo(left,top);ctx.quadraticCurveTo(left+16,mid,left,bottom);ctx.stroke();
  }
 }else if(face.family==='not'){
  // Inversion bubble stays inside the reserved glyph box and touches the
  // triangle, never the electrical end-point owned by ELK.
  const tip=right-8;
  ctx.beginPath();ctx.moveTo(left,top);ctx.lineTo(tip,mid);
  ctx.lineTo(left,bottom);ctx.closePath();ctx.fill();ctx.stroke();
  ctx.beginPath();ctx.arc(tip+5,mid,5,0,Math.PI*2);ctx.fill();ctx.stroke();
 }else{
  round(ctx,left,top,right-left,bottom-top,9);ctx.fill();ctx.stroke();
 }
 // Draw precisely the compiler-derived terminals, including generic IN.
 // No extra B stub is added to an operator whose AST has only operand A.
 const inputs=Array.isArray(n.pins)?n.pins.filter(role=>role!=='Y'&&role!=='S'):
  (n.shape==='field'||face.mark==='CAST'||face.family==='not'?['A']:['A','B']);
 for(const role of inputs){
  const pin=FlexSymbolGeometry.absoluteAnchor(n,{x,y,w,h},'target',{targetPin:role});
  ctx.beginPath();ctx.moveTo(pin.x,pin.y);
  ctx.lineTo(left+(face.family==='or'||face.family==='xor'?6:0),pin.y);ctx.stroke();
  // CONCAT and REP have indexed AST input pins, not generic A/B roles.
  if((n.kind==='Concatenation'||n.kind==='Replication'||n.shape==='function')&&/^I\d+$/.test(role)){
   ctx.save();ctx.fillStyle=colors.muted;ctx.font='8px ui-monospace,monospace';
   ctx.textAlign='left';ctx.fillText(role,left+3,pin.y-4,21);ctx.restore();
  }
  const literal=smallOperand(n.literalOperands?.[role]||'');
  if(literal){
   ctx.save();ctx.fillStyle=colors.muted;ctx.font='9px ui-monospace,monospace';
   ctx.textAlign='right';ctx.fillText(literal,pin.x-5,pin.y-5,62);
   ctx.restore();
  }
 }
 const out=FlexSymbolGeometry.absoluteAnchor(n,{x,y,w,h},'source',{sourcePin:'Y'});
 ctx.beginPath();ctx.moveTo(right,out.y);ctx.lineTo(out.x,out.y);ctx.stroke();
 // Never print a large mark over the operand labels or inside an inversion
 // triangle; shape itself already identifies NOT.
 if(n.shape==='function'){
  ctx.fillStyle=colors.text;ctx.textAlign='center';
  ctx.font='bold 11px ui-monospace,monospace';
  ctx.fillText(String(n.function?.name||n.name||'FUNCTION').slice(0,28),
   x+w/2,mid+4,Math.max(36,w-30));ctx.textAlign='left';
 }else if(face.family!=='not'&&n.shape!=='field'&&n.shape!=='slice'&&n.shape!=='constant'){
  ctx.fillStyle=colors.text;ctx.textAlign='center';
  ctx.font=['CAST','CONCAT','REP'].includes(face.mark)?'bold 9px ui-monospace,monospace':
   face.mark.length>3?'bold 10px ui-monospace,monospace':'bold 19px system-ui,sans-serif';
  ctx.fillText(face.mark,x+w/2+((n.kind==='Concatenation'||n.kind==='Replication')?7:0),
   mid+(['CAST','CONCAT','REP'].includes(face.mark)?3:6),Math.max(25,w-36));
  if(n.kind==='Replication'&&Number.isInteger(n.repeatCount)){
   ctx.font='9px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   ctx.fillText('×'+n.repeatCount,x+w/2+7,mid+16,50);
  }
  ctx.textAlign='left';
 }
 if(!face.known&&n.shape!=='field'&&n.shape!=='slice'&&n.shape!=='function'&&n.shape!=='constant'){
  ctx.font='9px ui-monospace,monospace';ctx.fillStyle=colors.muted;
  ctx.textAlign='center';ctx.fillText(String(n.name||n.kind||'unknown').slice(0,12)+(String(n.name||n.kind||'unknown').length>12?'…':''),x+w/2,bottom-7,w-25);
  ctx.textAlign='left';
 }
}
function paintGlyph(ctx,n,p,{colors,picked=false,zoom=1,names=true,edges=[]}={}){
  const {x,y,w,h}=p,c=(n.type==='fsm_group'?colors.fsm:n.type==='process_group'?colors.operator:colors[n.type])||colors.signal;
 ctx.lineWidth=picked?2.9:1.6;ctx.strokeStyle=picked?colors.selected:c;ctx.fillStyle=picked?colors.pickedFill:colors.symbolFill;
 if(n.type==='signal'){
  ctx.lineWidth=picked?3.5:2;ctx.beginPath();ctx.moveTo(x,y+h/2);ctx.lineTo(x+w,y+h/2);ctx.stroke();ctx.fillStyle=c;ctx.beginPath();ctx.arc(x+w/2,y+h/2,5,0,Math.PI*2);ctx.fill();
  if(zoom>=.43){ctx.font='12px ui-monospace,monospace';ctx.fillStyle=colors.text;ctx.fillText(n.name.slice(0,21),x+8,y+11);if(zoom>=.7){ctx.font='9px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   const packed=n.dimensions?.packedDimensions,unpacked=n.dimensions?.unpackedDimensions;
   const shape=unpacked?'unpacked '+JSON.stringify(unpacked):packed?'packed '+JSON.stringify(packed):n.width||'';
   if(shape)ctx.fillText(rtlLabel(shape).slice(0,26),x+9,y+h-3);
  }}
  return;}
 if(n.type==='port'){
  ctx.beginPath();ctx.moveTo(x+7,y+3);ctx.lineTo(x+w-25,y+3);ctx.lineTo(x+w-7,y+h/2);ctx.lineTo(x+w-25,y+h-3);ctx.lineTo(x+7,y+h-3);ctx.closePath();ctx.fill();ctx.stroke();
  const d=String(n.direction||'').toLowerCase(),bidirectional=d==='inout';
  ctx.beginPath();if(['in','input'].includes(d)||bidirectional){ctx.moveTo(x+w-7,y+h/2);ctx.lineTo(x+w,y+h/2);}
  if(['out','output'].includes(d)||bidirectional){ctx.moveTo(x,y+h/2);ctx.lineTo(x+7,y+h/2);}ctx.stroke();
  ctx.fillStyle=colors.muted;ctx.font='10px ui-monospace,monospace';ctx.fillText(bidirectional?'INOUT':['out','output'].includes(d)?'OUT':'IN',x+16,y+13);}
 else if(n.type==='operator'){
  if(n.shape==='mux'){
   // IEC-style trapezoidal multiplexer symbol. Selected AST conditional,
   // not a heuristic based on the name of a signal.
   ctx.beginPath();ctx.moveTo(x+9,y+6);ctx.lineTo(x+w-15,y+22);ctx.lineTo(x+w-15,y+h-20);ctx.lineTo(x+9,y+h-6);ctx.closePath();ctx.fill();ctx.stroke();
   // Pin ends come from the same geometry used by the router.
   const r={x,y,w,h};
   for(const role of ['A','B','S']){
    const p=FlexSymbolGeometry.absoluteAnchor(n,r,'target',{targetPin:role});
    ctx.beginPath();
    if(role==='S'){ctx.moveTo(p.x,p.y-11);ctx.lineTo(p.x,p.y);}
    else{ctx.moveTo(p.x,p.y);ctx.lineTo(p.x+9,p.y);}
    ctx.stroke();
   }
   const out=FlexSymbolGeometry.absoluteAnchor(n,r,'source',{sourcePin:'Y'});
   ctx.beginPath();ctx.moveTo(x+w-15,out.y);ctx.lineTo(out.x,out.y);ctx.stroke();
   // Only AST-proven scalar constants are shown as values. Label the two
   // alternatives at the input side, not on top of the MUX body, so the
   // user can read the selected values as incoming wires.
   ctx.font='10px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   ctx.textAlign='center';ctx.fillText('MUX',x+w*.57,y+h/2+3,45);
   for(const [role,bit] of [['A','0'],['B','1']]){
    const pin=FlexSymbolGeometry.absoluteAnchor(n,r,'target',{targetPin:role});
    const literal=smallOperand(n.literalOperands?.[role]||'');
    ctx.save();ctx.textAlign='right';ctx.font='bold 10px ui-monospace,monospace';
    ctx.fillStyle=literal?colors.text:colors.muted;
    ctx.fillText(literal||role+'·'+bit,pin.x-8,pin.y+4,72);ctx.restore();
   }
   const selector=FlexSymbolGeometry.absoluteAnchor(n,r,'target',{targetPin:'S'});
   const badge=String(n.controlBadge||('case'===n.controlKind?'CASE':'')||'S');
   const summary=summarizeControlText(n);
   ctx.textAlign='center';ctx.fillStyle=colors.muted;
   if(summary){ctx.font='8px ui-monospace,monospace';ctx.fillText(summary,selector.x,selector.y-24,86);}
   ctx.font='10px ui-monospace,monospace';
   ctx.fillText(badge,selector.x,selector.y-13,68);ctx.textAlign='left';
  }else if(['case','encoder','decoder'].includes(n.shape)){
   // Case-dispatch symbol; ENC/DEC shapes require explicit semantic metadata,
   // never merely a textual match against the module or signal name.
   round(ctx,x+7,y+9,w-14,h-18,9);ctx.fill();ctx.stroke();
   ctx.strokeStyle=colors.muted;ctx.beginPath();
   for(let i=0;i<3;i++){ctx.moveTo(x,y+21+i*15);ctx.lineTo(x+8,y+21+i*15);}
   ctx.moveTo(x+w-7,y+h/2);ctx.lineTo(x+w,y+h/2);ctx.stroke();
   ctx.save();ctx.textAlign='center';ctx.fillStyle=colors.text;
   ctx.font='bold 10px ui-monospace,monospace';
   ctx.fillText((n.controlBadge==='FSM'?'FSM CASE':'CASE'),x+w/2,y+h/2-6,w-28);
   const selector=rtlLabel(String(n.controlSource||'')).trim();
   const patterns=summarizeCaseLabels(n.casePatterns||n.literalOperands?.patterns);
   ctx.font='8px ui-monospace,monospace';ctx.fillStyle=colors.muted;
   if(selector)ctx.fillText(selector,x+w/2,y+h/2+6,w-24);
   if(patterns)ctx.fillText(patterns,x+w/2,y+h/2+18,w-20);
   ctx.restore();
  }else{paintOperatorFace(ctx,n,{x,y,w,h},colors);}
  // Unknown operand input: show an explicit '?' at the correct terminal.
  // No invented electrical segment is drawn to cover the missing topology.
  for(const role of Object.keys(n.operandStatus||{})){
   const a=FlexSymbolGeometry.absoluteAnchor(n,{x,y,w,h},'target',{targetPin:role});
   ctx.save();ctx.fillStyle=colors.generate;ctx.font='bold 11px ui-monospace,monospace';
   ctx.textAlign=role==='S'?'center':'left';
   ctx.fillText('?',role==='S'?a.x:a.x+10,role==='S'?a.y-12:a.y-6);
   ctx.restore();
  }
 }
 else if(['register','counter','fsm'].includes(n.type)){
  round(ctx,x+4,y+3,w-8,h-6,5);ctx.fill();ctx.stroke();
  const timingPins=new Set(edges.filter(e=>e.target===n.id&&e.type==='event').map(e=>e.pin||'EVENT'));
  const anchor=(role)=>FlexSymbolGeometry.anchor(n,'target',{type:'event',pin:role},{w,h});
  // ELK and Canvas consume the SAME anchor. The physical border is y+h-3.
  if(timingPins.has('CLK')){
   const pin=anchor('CLK'),px=x+pin.x,py=y+pin.y;
   const neg=negEdgeIsProven(n,'CLK'),base=neg?py-11:py-3;
   ctx.beginPath();ctx.moveTo(px,py);ctx.lineTo(px,base);
   ctx.moveTo(px-9,base);ctx.lineTo(px,base-12);ctx.lineTo(px+9,base);ctx.stroke();
   if(neg){ctx.beginPath();ctx.arc(px,py-5,3.4,0,Math.PI*2);ctx.fill();ctx.stroke();}
  }
  if(timingPins.has('RST')){
   const pin=anchor('RST'),px=x+pin.x,py=y+pin.y;
   ctx.beginPath();ctx.moveTo(px,py);ctx.lineTo(px,py-14);ctx.stroke();
   if(negEdgeIsProven(n,'RST')){
    ctx.beginPath();ctx.arc(px,py-6,3.4,0,Math.PI*2);ctx.fill();ctx.stroke();
   }
  }
  if(timingPins.has('EVENT')){
   const pin=anchor('EVENT'),px=x+pin.x,py=y+pin.y;
   ctx.beginPath();ctx.moveTo(px,py);ctx.lineTo(px,py-12);ctx.stroke();
  }
  ctx.beginPath();ctx.moveTo(x,y+20);ctx.lineTo(x+4,y+20);ctx.moveTo(x+w-4,y+20);ctx.lineTo(x+w,y+20);ctx.stroke();
  ctx.fillStyle=colors.register;ctx.font='10px ui-monospace,monospace';
  ctx.fillText('D',x+10,y+16);ctx.fillText('Q',x+w-23,y+16);
  if(n.dInputStatus){
   // Unsupported conditional lowering is never shown as multiple D drivers.
   // Keep the missing D-mux status visible even without the inspector open.
   ctx.fillStyle=colors.generate;ctx.font='bold 10px ui-monospace,monospace';
   ctx.fillText('D ?',x+12,y+h-12);
   ctx.fillStyle=colors.register;
  }
  for(const role of ['CLK','RST','EVENT'])if(timingPins.has(role)){
   const pin=anchor(role);ctx.textAlign='center';ctx.fillText(role==='EVENT'?'EVT':role,x+pin.x,y+h-39);ctx.textAlign='left';
  }
if(n.type==='counter'){ctx.fillText('↻',x+w-29,y+h-11);}if(n.type==='fsm')ctx.fillText('ST',x+w-28,y+h-11);}
 else if(n.type==='instance'||n.type==='generate'||n.type==='fsm_group'||n.type==='process_group'){
  // The outer ports belong to the ELK box, while the visual chassis is inset
  // by eight pixels on both sides. Every visible stub reaches its real anchor.
  if(n.type==='generate')for(let i=2;i>=1;i--){
   ctx.fillStyle=colors.stackFill;ctx.strokeStyle=colors.stackStroke;
   round(ctx,x+8+i*2,y+6+i*3,w-16,h-12,9);ctx.fill();ctx.stroke();
  }
  ctx.fillStyle=picked?colors.pickedFill:colors.symbolFill;
  ctx.strokeStyle=picked?colors.selected:c;
  round(ctx,x+8,y+6,w-16,h-12,9);ctx.fill();ctx.stroke();
  ctx.save();ctx.globalAlpha=.13;ctx.fillStyle=c;
  round(ctx,x+9,y+7,w-18,37,8);ctx.fill();ctx.restore();
  ctx.strokeStyle=c;ctx.globalAlpha=.45;ctx.beginPath();
  ctx.moveTo(x+9,y+44);ctx.lineTo(x+w-9,y+44);ctx.stroke();ctx.globalAlpha=1;
  for(const role of ['target','source']){
   const left=role==='target';
   for(const {port,x:pxLocal,y:pyLocal} of FlexSymbolGeometry.portRows(n,role,{w,h})){
    const px=x+pxLocal,py=y+pyLocal;
    const untrusted=['unbound','unresolved'].includes(port.connection);
    ctx.strokeStyle=untrusted?colors.generate:port.connection==='partial'?colors.sequential:c;
    ctx.lineWidth=1.7;ctx.beginPath();
    ctx.moveTo(px,py);ctx.lineTo(px+(left?8:-8),py);ctx.stroke();
    if((n.type==='fsm_group'||n.type==='process_group')&&left&&port.timingRole==='clock'){
     // The clock glyph is allowed only for a compiler-backed event edge to
     // the FSM state register. It is not inferred from a signal name.
     ctx.beginPath();ctx.moveTo(px+9,py-5);ctx.lineTo(px+15,py);
     ctx.lineTo(px+9,py+5);ctx.stroke();
    }
    if((n.type==='fsm_group'||n.type==='process_group')&&left&&port.timingRole==='async_reset'){
     // The exact event role comes from Slang; synchronous reset is a plain
     // signal input and must not acquire an asynchronous timing glyph.
     ctx.beginPath();ctx.arc(px+12,py,3,0,Math.PI*2);ctx.stroke();
    }
    if(port.connection==='unbound'||port.connection==='unresolved'){
     ctx.beginPath();ctx.arc(px,py,3,0,Math.PI*2);ctx.stroke();
    }
    if(port.connection==='constant'||port.connection==='unresolved'){
     // An input constant is an external actual, not text inside the
     // instance chassis. Only a literal proven by Slang may be displayed.
     const literal=port.connection==='constant'&&typeof port.constantValue==='string'
      ?port.constantValue:'';
     ctx.save();ctx.fillStyle=port.connection==='constant'?colors.binding:colors.generate;
     ctx.font='bold 10px ui-monospace,monospace';
     ctx.textAlign=left?'right':'left';
     // This is an actual-connection label: vertically centre it on the
     // SAME ELK port row as the wire, not above the pin like a caption.
     ctx.textBaseline='middle';
     ctx.fillText(port.connection==='constant'?(literal||'CONST'):'?',
      px+(left?-8:8),py,72);ctx.restore();
    }
    if(String(port.direction).toLowerCase()==='inout'){
     ctx.fillStyle=c;ctx.beginPath();ctx.arc(px+(left?8:-8),py,2,0,Math.PI*2);ctx.fill();
    }
    if(names&&zoom>=.48){
     ctx.fillStyle=untrusted?colors.generate:colors.text;
     ctx.font='11px ui-monospace,monospace';ctx.textAlign=left?'left':'right';
     ctx.fillText(String(port.name||''),left?x+19:x+w-19,py+4,
      Math.max(24,(w-52)/2));ctx.textAlign='left';
    }
   }
  }
  if(names&&zoom>=.36){
   ctx.fillStyle=colors.text;ctx.font='600 12px system-ui,sans-serif';
   ctx.fillText(String(n.name||''),x+18,y+23,Math.max(20,w-38));
   ctx.fillStyle=colors.muted;ctx.font='10px ui-monospace,monospace';
   const detail=n.type==='process_group'?`${n.processSummary?.members||0} circuit nodes · enter / flatten`+(n.processSummary?.coverage!=='connected'?` · ${n.processSummary?.coverage||'partial'}`:''):n.type==='fsm_group'?`${n.fsmSummary?.members||0} AST symbols · double-click to enter`+(n.fsmSummary?.hiddenDependencies?` · ${n.fsmSummary.hiddenDependencies} non-routed`:``):n.type==='generate'?String(n.count||0)+' generated instances':String(n.module||'');
   ctx.fillText(detail,x+18,y+38,Math.max(20,w-38));
  }
  return;
 }
 else{
  round(ctx,x+6,y+7,w-13,h-14,7);ctx.fill();ctx.stroke();
 }
 if(zoom<.36||!names)return;
 ctx.font=n.type==='operator'?'bold 10px ui-monospace,monospace':'600 13px system-ui,sans-serif';ctx.fillStyle=colors.text;
 if(n.type==='operator'){
  // The compact constant value has already been drawn by paintOperatorFace.
  if(n.shape!=='constant'){
   ctx.textAlign='center';
   if(['case','encoder','decoder'].includes(n.shape))
    ctx.fillText((n.shape==='case'?'CASE':n.shape==='encoder'?'ENC':'DEC'),x+w/2,y+h/2+4);
   ctx.textAlign='left';
  }
 }
 else if(['register','counter','fsm'].includes(n.type)){
  // Reserve an upper name band and a lower timing-control band; long
  // register names must not overlap clocks, resets or their edge markers.
  const name=String(n.name||'');const display=name.length>36?name.slice(0,35)+'…':name;
  ctx.save();ctx.beginPath();ctx.rect(x+12,y+26,Math.max(10,w-24),25);ctx.clip();
  ctx.textAlign='center';ctx.font='600 12px system-ui,sans-serif';
  ctx.fillText(display,x+w/2,y+43,Math.max(20,w-30));ctx.restore();
 }else{const text=n.name.length>23?n.name.slice(0,22)+'…':n.name;ctx.fillText(text,x+16,y+(n.type==='port'?29:35));}

 /* Register shape conveys always_ff; avoid duplicate caption. */}

 // Canvas properties (alignment, font, opacity, line dash) must not leak
 // into routing or neighboring glyphs. In particular, early exits are safe.
 function paint(ctx,node,rect,options){
  ctx.save();try{paintGlyph(ctx,node,rect,options);}finally{ctx.restore();}
 }
 const api={paint};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexSymbolPainter=api;
})(typeof window==='object'?window:globalThis);
