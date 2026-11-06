'use strict';
/* Paginated compiler-backed hierarchy with bounded search over loaded rows.
 * Never fetch all descendants to satisfy a text filter. */
(function(root){
 function create({host,fetchPage,navigate,onError,onFilterStatus,onVirtualGroup}){
  if(!host||typeof fetchPage!=='function'||typeof navigate!=='function')throw Error('hierarchy dependencies missing');
  const PAGE=64,cache=new Map(),expanded=new Set(['/']);
  let active='/',generation=0,filter='';
  const virtualByScope=new Map();
  function record(path,name,hasChildren=true){
   if(!cache.has(path))cache.set(path,{path,name,hasChildren,items:[],loaded:0,total:null,busy:false,error:null});
   return cache.get(path);
  }
  record('/','Top');
  // Only paths learned from compiler-backed hierarchy pages are loadable scopes.
  // A generate label may occur inside an instance path without being a scope.
  function knownAncestors(path){return [...cache.keys()].filter(p=>p==='/'||p===path||path.startsWith(p+'/'));}
  function visibleButtons(){return Array.from(host.querySelectorAll('.fs-tree-label'));}
  function focusPath(path){const el=visibleButtons().find(el=>el.dataset.path===path);if(el)el.focus();}
  async function load(path){
   const r=record(path,path);if(r.busy||(r.total!==null&&r.loaded>=r.total))return;
   r.busy=true;r.error=null;const token=generation;render();
   try{
    const response=await fetchPage(path,r.loaded,PAGE);
    if(token!==generation)return;
    if(!response||!Array.isArray(response.items)||response.path!==path)throw Error('invalid hierarchy response');
    const seen=new Set(r.items.map(i=>i.path));
    const follow=[];
    for(const child of response.items){
     if(typeof child.path!=='string'||!child.path.startsWith('/')||seen.has(child.path))continue;
     seen.add(child.path);r.items.push(child);
     const c=record(child.path,child.name,child.has_children);c.name=child.name;c.hasChildren=!!child.has_children;c.module=child.module||'';
     if(active===child.path||active.startsWith(child.path+'/')){
      expanded.add(child.path);
      if(c.hasChildren)follow.push(child.path);
     }
    }
    r.loaded+=response.items.length;r.total=Number.isFinite(response.total)?response.total:r.loaded;
    if(response.has_more&&r.total<=r.loaded)r.total=r.loaded+1;
    // Continue along proven instance paths, never through invented generate folders.
    for(const childPath of follow)load(childPath);
   }catch(err){if(token===generation){r.error=String(err.message||err);onError?.(err);}}
   finally{if(token===generation){r.busy=false;render();}}
  }
  function makeRow(r,depth,flat=false){
   const line=document.createElement('div');line.className='fs-tree-row'+(r.path===active?' current':'');
   line.style.paddingLeft=flat?'4px':Math.min(depth,20)*11+'px';line.dataset.path=r.path;
   const exp=document.createElement('button');exp.type='button';exp.className='fs-tree-expander';
   exp.textContent=!r.hasChildren?'·':expanded.has(r.path)?'−':'+';
   exp.disabled=!r.hasChildren||flat;exp.setAttribute('aria-label',(expanded.has(r.path)?'Collapse ':'Expand ')+r.name);
   exp.setAttribute('aria-expanded',String(expanded.has(r.path)));
   exp.onclick=()=>{if(expanded.has(r.path)){expanded.delete(r.path);render();focusPath(r.path);}else{expanded.add(r.path);render();focusPath(r.path);load(r.path);}};
   const btn=document.createElement('button');btn.type='button';btn.className='fs-tree-label';btn.dataset.path=r.path;
   btn.title=(r.module?r.module+' · ':'')+r.path;
   const icon=document.createElement('span');icon.className='fs-tree-icon';icon.textContent='▣';icon.setAttribute('aria-hidden','true');
   const txt=document.createElement('span');txt.className='fs-tree-name';txt.textContent=r.name;
   btn.append(icon,txt);btn.setAttribute('aria-current',r.path===active?'page':'false');
   if(flat){const where=document.createElement('span');where.className='fs-tree-path';where.textContent=r.path;btn.append(where);}
   btn.onclick=()=>navigate(r.path);line.append(exp,btn);host.append(line);
  }
  function makeVirtualRow(scope,group,depth,flat=false){
   // Virtual groups are schematic views; they never become compiler scopes.
   if(typeof group.token!=='string'||!(/^(fsm:[^\s]+|proc:\d+|gen:.+)$/.test(group.token)))return;
   const isFsm=group.token.startsWith('fsm:');
   const entered=group.view==='entered';
   const flattened=group.view==='flattened'||group.view==='expanded';
   const line=document.createElement('div');
   line.className='fs-tree-row fs-tree-virtual'+(entered?' expanded':'');
   line.style.paddingLeft=flat?'4px':Math.min(depth,20)*11+'px';
   line.dataset.fsmGroup=group.token;
   const icon=document.createElement('span');icon.className='fs-tree-icon';
   icon.textContent=isFsm?'◇':'▣';icon.setAttribute('aria-hidden','true');
   const btn=document.createElement('button');btn.type='button';
   btn.className='fs-tree-label fs-tree-fsm';btn.dataset.fsmGroup=group.token;
   btn.setAttribute('aria-expanded',String(entered));
   btn.title=(isFsm?'Virtual AST FSM':'Slang procedural block')+' in '+scope+' · enter dedicated schematic';
   const name=document.createElement('span');name.className='fs-tree-name';
   name.textContent=isFsm?'FSM · '+group.state:String(group.name||group.kind||group.token);
   const mode=document.createElement('span');mode.className='fs-tree-fsm-mode';
   mode.textContent=entered?'← Parent':'Enter ›';btn.append(icon,name,mode);
   btn.onclick=()=>onVirtualGroup?.(scope,group.token,'enter');
   line.append(btn);
   const flatten=document.createElement('button');flatten.type='button';
   flatten.className='fs-tree-expander fs-tree-virtual-flatten';
   flatten.textContent=flattened?'▣':'▥';
   flatten.title=flattened?'Unflatten here · restore the compact block':'Flatten here · display its inner circuit in this diagram';
   flatten.setAttribute('aria-label',(flattened?'Unflatten ':'Flatten ')+name.textContent+' here in the parent diagram');
   flatten.setAttribute('aria-pressed',String(flattened));
   flatten.onclick=()=>onVirtualGroup?.(scope,group.token,'flatten');
   line.append(flatten);host.append(line);
  }
  function walk(r,depth){
   makeRow(r,depth);
   if(!expanded.has(r.path))return;
   // Only display virtual groups for their active schematic scope.
   if(r.path===active){
    for(const group of virtualByScope.get(r.path)||[])makeVirtualRow(r.path,group,depth+1);
   }
   for(const item of r.items)walk(record(item.path,item.name,item.has_children),depth+1);
   if(r.busy){const busy=document.createElement('div');busy.className='fs-tree-error';busy.textContent='Loading…';host.append(busy);}
   if(r.error){const error=document.createElement('div');error.className='fs-tree-error';error.textContent=r.error;host.append(error);}
   if(!r.busy&&(r.total===null||r.loaded<r.total)){
    const more=document.createElement('button');more.type='button';more.className='fs-tree-more';
    more.textContent=r.loaded?'Load more…':'Load children…';more.onclick=()=>load(r.path);host.append(more);
   }
  }
  function render(){
   const keep=host.contains(document.activeElement)?document.activeElement.closest('.fs-tree-row')?.dataset.path:null;
   host.replaceChildren();
   if(!filter){host.removeAttribute('data-filtering');walk(record('/','Top'),0);onFilterStatus?.('',0);if(keep)focusPath(keep);return;}
   host.dataset.filtering='true';
   const matches=[...cache.values()].filter(r=>(r.name+' '+(r.module||'')+' '+r.path).toLocaleLowerCase().includes(filter));
   matches.sort((a,b)=>a.path.localeCompare(b.path));
   for(const r of matches)makeRow(r,0,true);
   const virtualMatches=(virtualByScope.get(active)||[]).filter(g=>
    ('fsm process generate '+(g.state||g.name||g.kind)+' '+g.token+' '+active).toLocaleLowerCase().includes(filter));
   for(const group of virtualMatches)makeVirtualRow(active,group,0,true);
   if(!matches.length&&!virtualMatches.length){const empty=document.createElement('p');empty.className='fs-tree-empty';empty.textContent='No matching loaded instances or virtual processes';host.append(empty);}
   onFilterStatus?.(filter,matches.length+virtualMatches.length);
   if(keep)focusPath(keep);
  }
  function activate(path){active=path||'/';const known=knownAncestors(active);for(const p of known)expanded.add(p);render();for(const p of known)if(cache.get(p).hasChildren)load(p);}
  function setFilter(text){filter=String(text||'').trim().toLocaleLowerCase();render();}
  function setVirtualGroups(scope,groups){
   if(typeof scope!=='string'||!cache.has(scope)||!Array.isArray(groups))return;
   // Derived from the graph returned by /api/diagram. This is presentation
   // metadata, not a second source of truth for hierarchy or connectivity.
   const valid=groups.filter(g=>g&&typeof g.token==='string'&&
    /^(fsm:[^\s]+|proc:\d+|gen:.+)$/.test(g.token)&&(typeof g.state==='string'||typeof g.name==='string')&&
    (g.view==='entered'||g.view==='expanded'||g.view==='flattened'||g.view==='collapsed'));
   virtualByScope.set(scope,valid);
   if(active===scope)render();
  }
  // Navigate visible labels only; the tree stays usable without a pointing device.
  host.addEventListener('keydown',event=>{
   const btn=event.target.closest?.('.fs-tree-label');if(!btn)return;
   const keys=['ArrowDown','ArrowUp','Home','End','ArrowRight','ArrowLeft'];
   if(!keys.includes(event.key))return;
   event.preventDefault();
   const items=visibleButtons(),i=items.indexOf(btn),path=btn.dataset.path;
   if(event.key==='ArrowDown')items[Math.min(items.length-1,i+1)]?.focus();
   else if(event.key==='ArrowUp')items[Math.max(0,i-1)]?.focus();
   else if(event.key==='Home')items[0]?.focus();
   else if(event.key==='End')items[items.length-1]?.focus();
   else if(!filter&&event.key==='ArrowRight'){
    const exp=btn.parentElement.querySelector('.fs-tree-expander');
    if(exp&&!exp.disabled&&!expanded.has(path))exp.click();
    else if(expanded.has(path)){const j=visibleButtons().indexOf(btn);visibleButtons()[j+1]?.focus();}
   }else if(!filter&&event.key==='ArrowLeft'){
    if(expanded.has(path)&&path!=='/'){expanded.delete(path);render();focusPath(path);}
    else{const parent=knownAncestors(path).filter(p=>p!==path).sort((a,b)=>b.length-a.length)[0]||'/';focusPath(parent);}
   }
  });
  return {activate,setFilter,setVirtualGroups};
 }
 const api={create};if(typeof module==='object'&&module.exports)module.exports=api;else root.FlexHierarchyTree=api;
})(typeof window==='object'?window:globalThis);
