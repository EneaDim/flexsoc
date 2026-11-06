'use strict';
/* Offline renderer structural audit: original graph, compressed/flattened
 * views, focused process interiors, and optional actual ELK route geometry.
 * Does not modify an AST or generate any circuit nodes/edges.
 */
const fs=require('node:fs');
const path=require('node:path');
const root=path.resolve(__dirname,'../src/flexsoc/backend/dv/rtl_viewer/web');
const P=require(path.join(root,'virtual-process.js'));
const C=require(path.join(root,'render-contract.js'));
const ELK=require(path.join(root,'elk.bundled.js')).default;
async function main(){
 if(process.argv.length!==4)throw Error('Usage: node scripts/rtl_viewer_render_check.js graphs.json result.json');
 const request=JSON.parse(fs.readFileSync(process.argv[2]));
 const results=[],summary={scopes:0,views:0,errors:0,warnings:0,layoutScopes:0};
 const maxSamples=Number.isInteger(request.maxSamples)?request.maxSamples:40;
 const layout=new Set(request.layoutScopes||[]);
 for(const entry of request.graphs){
  const g=entry.graph,scope=entry.scope;
  const checks=[];
  const add=(name,value)=>{
   checks.push({view:name,...value});summary.views++;
   summary.errors+=value.errors?.length||0;
   summary.warnings+=value.warnings?.length||0;
  };
  add('canonical',C.check(g,{limit:maxSamples}));
  const compact=P.project(g);
  add('compact',C.checkProjection(g,compact,{limit:maxSamples}));
  const tokens=(g.processGroups||[]).map(p=>p.token);
  if(tokens.length){
   add('flatten',C.checkProjection(g,P.project(g,tokens),{limit:maxSamples}));
   for(const token of tokens){
    try{
     const focus=P.focus(g,token);
     add('focus:'+token,C.checkProjection(g,focus,{limit:maxSamples}));
    }catch(e){
     add('focus:'+token,{errors:[{code:'focus_projection_failure',id:token,description:String(e)}],warnings:[]});
    }
   }
  }
  if(entry.fsmGraph){
   add('fsm:compact',C.checkProjection(g,entry.fsmGraph,{limit:maxSamples}));
   for(const fsm of entry.fsmExpanded||[]){
    add('fsm:expanded',C.checkProjection(g,fsm,{limit:maxSamples}));
    // What the actual UI shows when Flatten is invoked on the FSM. Do not
    // merely audit a raw backend expansion: the next virtual hierarchy level
    // must contain process shells, with original edges and named terminals.
    const expandedFsmTokens=new Set((fsm.fsmGroups||[])
     .filter(group=>group.view==='expanded').map(group=>group.token));
    const oneLevel=P.project(fsm,expandedFsmTokens);
    add('fsm:one-level',C.checkProjection(g,oneLevel,{limit:maxSamples}));
    for(const group of fsm.fsmGroups||[]){
     if(group.view!=='expanded')continue;
     const members=new Set(group.memberIds||[]);
     const present=new Set(fsm.nodes.map(n=>n.id));
     const expected=(fsm.processGroups||[]).filter(p=>p.memberIds?.length&&
      p.memberIds.every(id=>present.has(id))&&p.memberIds.some(id=>members.has(id)));
     const compactTokens=new Set(oneLevel.nodes.filter(n=>n.type==='process_group')
      .map(n=>n.group));
     const missing=expected.filter(p=>!compactTokens.has(p.token));
     if(missing.length)
      add('fsm:level-contract',{errors:missing.map(p=>({code:'fsm_flatten_cascade',
       id:p.token,description:'expanded FSM lost the compact child '+p.name})),warnings:[]});
    }
    if(layout.has(scope))add('elk:fsm:one-level',await C.checkLayout(oneLevel,new ELK()));
    for(const group of fsm.fsmGroups||[]){
     if(group.view!=='expanded')continue;
     const visible=new Set([...(group.memberIds||[]),...(group.inputIds||[]),...(group.outputIds||[])]);
     const focused={...fsm,nodes:fsm.nodes.filter(n=>visible.has(n.id)),
       edges:fsm.edges.filter(e=>visible.has(e.source)&&visible.has(e.target)),
       // This is an ENTERED FSM slice, not an expanded parent schematic.
       // The exterior of the FSM is intentionally absent in this mode.
       fsmGroups:(fsm.fsmGroups||[]).map(g=>({...g,
        view:g.token===group.token?'entered':g.view}))};
     add('fsm:focus:'+group.token,C.checkProjection(g,focused,{limit:maxSamples}));
    }
   }
  }
  if(entry.exploded){
   add('generate:exploded',C.check(entry.exploded,{limit:maxSamples}));
  }
  if(layout.has(scope)){
   add('elk:compact',await C.checkLayout(compact,new ELK()));
   if(entry.fsmGraph)add('elk:fsm',await C.checkLayout(entry.fsmGraph,new ELK()));
   summary.layoutScopes++;
  }
  results.push({scope,graph:{nodes:g.nodes.length,edges:g.edges.length,processes:tokens.length},checks});
  summary.scopes++;
 }
 fs.writeFileSync(process.argv[3],JSON.stringify({schema:'flexsoc.rtl_viewer.render_contract.v1',summary,results},null,2)+'\n');
 if(summary.errors)process.exitCode=1;
}
main().catch(e=>{console.error(e.stack||String(e));process.exitCode=2;});
