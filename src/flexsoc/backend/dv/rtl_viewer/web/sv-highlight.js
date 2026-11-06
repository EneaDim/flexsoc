'use strict';
/* Read-only SystemVerilog lexical coloring. Slang remains the sole semantic
 * authority: tokens are presentation only, never used for cross-probing. */
(function(root){
 const keywords=new Set(('module endmodule interface endinterface package endpackage program endprogram '
  +'always always_comb always_ff always_latch initial final assign generate endgenerate '
  +'if else case casez casex endcase default begin end for foreach while repeat '
  +'function endfunction task endtask return break continue import export '
  +'parameter localparam typedef enum struct union packed logic wire reg bit byte shortint '
  +'int integer longint time realtime real string signed unsigned input output inout ref '
  +'posedge negedge or and unique priority inside automatic static genvar const '
  +'assert assume cover property endproperty sequence endsequence').split(/\s+/));
 function tokenize(line,state={comment:false}){
  const out=[];let i=0,comment=Boolean(state.comment);
  function emit(kind,value){if(value)out.push({kind,text:value});}
  while(i<line.length){
   if(comment){const end=line.indexOf('*/',i);
    if(end<0){emit('comment',line.slice(i));i=line.length;break;}
    emit('comment',line.slice(i,end+2));i=end+2;comment=false;continue;}
   if(line.startsWith('//',i)){emit('comment',line.slice(i));break;}
   if(line.startsWith('/*',i)){comment=true;continue;}
   if(line[i]==='"'){
    let j=i+1;
    while(j<line.length){if(line[j]==='\\'){j+=2;continue;}if(line[j++]==='"')break;}
    emit('string',line.slice(i,Math.min(j,line.length)));i=Math.min(j,line.length);continue;
   }
   if(line[i]==='`'){
    const m=/^`[a-zA-Z_$][\w$]*/.exec(line.slice(i));
    if(m){emit('directive',m[0]);i+=m[0].length;continue;}
   }
   const number=/^(?:(?:\d+(?:_\d+)*\s*)?'[sS]?[bodhBODH][0-9a-fA-F_xXzZ?]+|'[01xXzZ]|\d[\d_]*(?:\.[\d_]+)?)/.exec(line.slice(i));
   if(number){emit('number',number[0]);i+=number[0].length;continue;}
   const word=/^[a-zA-Z_$][\w$]*/.exec(line.slice(i));
   if(word){emit(keywords.has(word[0])?'keyword':'plain',word[0]);i+=word[0].length;continue;}
   emit('plain',line[i]);i++;
  }
  return {tokens:out,state:{comment}};
 }
 function renderLine(line,document,state){
  const span=document.createElement('span');span.className='code-line';
  const result=tokenize(line,state);const fragment=document.createDocumentFragment();
  for(const token of result.tokens){
   if(token.kind==='plain')fragment.append(document.createTextNode(token.text));
   else{const t=document.createElement('span');t.className='sv-'+token.kind;t.textContent=token.text;fragment.append(t);}
  }
  if(!result.tokens.length)fragment.append(document.createTextNode(' '));
  span.append(fragment);return {span,state:result.state};
 }
 const api={tokenize,renderLine};
 if(typeof module==='object'&&module.exports)module.exports=api;
 root.FlexSvHighlight=api;
})(typeof window==='object'?window:globalThis);
