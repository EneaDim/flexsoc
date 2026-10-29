'use strict';
/* Accessible, paginated AST hierarchy. Expand never navigates; clicking a name navigates. */
(function(root){
 function create({host,fetchPage,navigate,onError}){
  if(!host||typeof fetchPage!=='function'||typeof navigate!=='function')throw Error('hierarchy dependencies missing');
  const PAGE=64,cache=new Map(),expanded=new Set(['/']);let active='/',generation=0;
  function record(path,name,hasChildren=true){
   if(!cache.has(path))cache.set(path,{path,name,hasChildren,items:[],loaded:0,total:null,busy:false,error:null});
   return cache.get(path);
  }
  record('/','Top');
  async function load(path){
   const r=record(path,path);if(r.busy||r.total!==null&&r.loaded>=r.total)return;
   r.busy=true;r.error=null;const token=generation;render();
   try{
    const response=await fetchPage(path,r.loaded,PAGE);
    if(token!==generation)return;
    if(!response||!Array.isArray(response.items)||response.path!==path)throw Error('invalid hierarchy response');
    const seen=new Set(r.items.map(i=>i.path));
    for(const child of response.items){
     if(typeof child.path!=='string'||!child.path.startsWith('/')||seen.has(child.path))continue;
     seen.add(child.path);r.items.push(child);
     const c=record(child.path,child.name,child.has_children);c.name=child.name;c.hasChildren=!!child.has_children;
    }
    r.loaded+=response.items.length;r.total=Number.isFinite(response.total)?response.total:r.loaded;
    if(response.has_more&&r.total<=r.loaded)r.total=r.loaded+1;
   }catch(err){if(token===generation){r.error=String(err.message||err);onError?.(err);}}
   finally{if(token===generation){r.busy=false;render();}}
  }
  function ancestors(path){const parts=path.split('/').filter(Boolean),result=['/'];let p='';for(const part of parts){p+='/'+part;result.push(p);}return result;}
  function row(r,depth){
   const line=document.createElement('div');line.className='fs-tree-row'+(r.path===active?' current':'');line.style.paddingLeft=Math.min(depth,20)*11+'px';
   const exp=document.createElement('button');exp.type='button';exp.className='fs-tree-expander';
   exp.textContent=!r.hasChildren?'·':expanded.has(r.path)?'−':'+';
   exp.disabled=!r.hasChildren;exp.setAttribute('aria-label',(expanded.has(r.path)?'Collapse ':'Expand ')+r.name);
   exp.setAttribute('aria-expanded',String(expanded.has(r.path)));
   exp.onclick=()=>{if(expanded.has(r.path)){expanded.delete(r.path);render();}else{expanded.add(r.path);render();load(r.path);}};
   const btn=document.createElement('button');btn.type='button';btn.className='fs-tree-label';btn.title=r.name+' · '+r.path;
   const icon=document.createElement('span');icon.className='fs-tree-icon';icon.textContent='▣';icon.setAttribute('aria-hidden','true');
   const txt=document.createElement('span');txt.className='fs-tree-name';txt.textContent=r.name;
   btn.append(icon,txt);btn.setAttribute('aria-current',r.path===active?'page':'false');btn.onclick=()=>navigate(r.path);
   line.append(exp,btn);host.append(line);
   if(expanded.has(r.path)){
    for(const item of r.items)walk(record(item.path,item.name,item.has_children),depth+1);
    if(r.busy){const busy=document.createElement('div');busy.className='fs-tree-error';busy.textContent='Loading…';host.append(busy);}
    if(r.error){const error=document.createElement('div');error.className='fs-tree-error';error.textContent=r.error;host.append(error);}
    if(!r.busy&&(r.total===null||r.loaded<r.total)){
     const more=document.createElement('button');more.type='button';more.className='fs-tree-more';more.textContent=r.loaded?'Load more…':'Load children…';more.onclick=()=>load(r.path);host.append(more);
    }
   }
  }
  function walk(r,depth){row(r,depth);}
  function render(){host.replaceChildren();walk(record('/','Top'),0);}
  function activate(path){active=path||'/';for(const p of ancestors(active))expanded.add(p);render();for(const p of ancestors(active))if(record(p,p).hasChildren)load(p);}
  return {activate};
 }
 const api={create};if(typeof module==='object'&&module.exports)module.exports=api;else root.FlexHierarchyTree=api;
})(typeof window==='object'?window:globalThis);
