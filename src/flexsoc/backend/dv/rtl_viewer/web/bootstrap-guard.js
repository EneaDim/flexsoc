'use strict';
/* Early boot diagnostics: installed before other deferred scripts. No telemetry. */
(function(){
  let failure=null;
  function show(message){
    failure=String(message).slice(0,700);
    const status=document.getElementById('status');
    const detail=document.getElementById('message');
    if(status){status.textContent='RTL VIEWER ERROR';status.title=failure;}
    if(detail)detail.textContent='Initialization: '+failure;
    console.error('FlexSoC RTL Viewer:',failure);
  }
  window.addEventListener('error',function(event){
    const target=event.target;
    if(target&&target.tagName==='SCRIPT')show('Script failed to load: '+(target.getAttribute('src')||'unknown'));
    else show((event.message||'JavaScript error')+' @ '+(event.filename||'?')+':'+(event.lineno||'?'));
  },true);
  window.addEventListener('unhandledrejection',function(event){show('Unhandled promise rejection: '+(event.reason?.message||String(event.reason)));});
  window.addEventListener('DOMContentLoaded',function(){
    // A late, visible diagnostic; never attempts to manufacture a graph.
    setTimeout(function(){
      const status=document.getElementById('status');
      if(!failure&&status&&status.textContent.includes('Loading'))show('Bootstrap did not finish. Check the browser console and /api/overview.');
    },8000);
  });
})();
