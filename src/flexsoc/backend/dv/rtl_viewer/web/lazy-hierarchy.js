'use strict';
/* Hierarchy queries never request schematic diagrams: all names and children
 * come from the Slang-elaborated backend index. */
(function(root){
 function create({host,fetchPage,navigate,pageSize=64,maxPages=32,onError=()=>{}}){
  const expanded=new Set(['/']), pages=new Map(), versions=new Map();
  let active='/', generation=0;
  function record(path,offset,value){
   const key=JSON.stringify([path,offset]);pages.delete(key);pages.set(key,value);
   while(pages.size>maxPages)pages.delete(pages.keys().next().value);
  }
  function cached(path,offset){const key=JSON.stringify([path,offset]);if(!pages.has(key))return null;const v=pages.get(key);pages.delete(key);pages.set(key,v);return v;}
  function element(tag,text,className){const e=document.createElement(tag);if(text!==undefined)e.textContent=text;if(className)e.className=className;return e;}
  function render(){
   host.replaceChildren();
   const rootItem=element('div',undefined,'hierarchy-root');
   const rootButton=element('button','▣ '+rootButtonLabel,'tree-button');rootButton.onclick=()=>navigate('/');rootItem.append(rootButton);host.append(rootItem);
   function branch(path,depth){
    if(!expanded.has(path))return;
    const first=cached(path,0),items=first?.items||[];
    const data=[]; let next=first?.has_more?items.length:null;
    data.push(...items);
    while(next!==null){const page=cached(path,next);if(!page)break;data.push(...page.items);next=page.has_more?next+page.items.length:null;}
    for(const child of data){
     const line=element('div',undefined,'hierarchy-row');line.style.paddingLeft=(Math.min(depth,24)*13)+'px';
     if(child.has_children){const toggle=element('button',expanded.has(child.path)?'▾':'▸','tree-expander');toggle.setAttribute('aria-label',(expanded.has(child.path)?'Collapse ':'Expand ')+child.name);toggle.setAttribute('aria-expanded',String(expanded.has(child.path)));toggle.onclick=()=>expanded.has(child.path)?collapse(child.path):expand(child.path);line.append(toggle);}
     else line.append(element('span','·','tree-leaf'));
     const button=element('button',child.name+' · '+child.module,'tree-button');button.title=child.path;button.classList.toggle('current',child.path===active);button.onclick=()=>navigate(child.path);line.append(button);host.append(line);
     branch(child.path,depth+1);
    }
    if(next!==null){const more=element('button','Load next '+pageSize+'…','tree-button tree-more');more.style.marginLeft=(Math.min(depth,24)*13+18)+'px';more.onclick=()=>load(path,next);host.append(more);}
   }
   branch('/',1);
  }
  async function load(path,offset=0){
   if(cached(path,offset)){render();return;}
   const key=JSON.stringify([path,offset]),stamp=(versions.get(key)||0)+1;versions.set(key,stamp);
   const thisGeneration=generation;
   try{
    const page=await fetchPage(path,offset,pageSize);
    if(thisGeneration!==generation||versions.get(key)!==stamp||!expanded.has(path))return;
    if(page.path!==path||page.offset!==offset||!Array.isArray(page.items)||page.items.length>pageSize||page.limit>pageSize||page.total<0)throw Error('Invalid hierarchy page');
    record(path,offset,page);render();
   }catch(error){if(thisGeneration===generation&&versions.get(key)===stamp)onError(error);}
  }
  function expand(path){expanded.add(path);render();load(path,0);}
  function collapse(path){expanded.delete(path);generation++;render();}
  function activate(path){active=path;render();}
  function start(top){rootButtonLabel=top;expand('/');}
  let rootButtonLabel='Top';
  function refresh(){render();}
  return {expand,collapse,activate,start,refresh,cacheSize:()=>pages.size};
 }
 root.FlexLazyHierarchy={create};
})(typeof window!=='undefined'?window:globalThis);
