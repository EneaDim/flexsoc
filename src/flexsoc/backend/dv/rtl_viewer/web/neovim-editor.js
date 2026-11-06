'use strict';
/* Real Neovim --embed UI: server owns buffer + RPC; this module only paints its
   ext_linegrid and forwards actual Vim input. No hand-written modal parser. */
(() => {
 const $ = id => document.getElementById(id);
 const button = $('rtlNeovimToggle'), panel = $('nvimContainer'), screen = $('nvimScreen');
 if (!button || !panel || !screen) return;
 const fallback = $('sourceFallback'), status = $('nvimStatus'), notice = $('nvimNotice');
 let enabled = false, token = '', path = '', file = '', source = null, version = -1;
 let generation = 0, pollTimer = null, desiredLine = 1, latestLine = 0;
 let lastDimensions = '';
 const post = async (action, body) => {
  const reply = await fetch('/api/neovim/' + action, {method: 'POST',
   headers: {'Content-Type':'application/json'}, body: JSON.stringify(body)});
  const data = await reply.json();
  if (!reply.ok) throw Error(data.error || 'Neovim endpoint failed');
  return data;
 };
 const message = (value, expose=false) => {
  status.textContent = value;
  if (notice) {notice.textContent = expose ? value : ''; notice.hidden = !expose;}
 };
 const dimensions = () => {
  const style = getComputedStyle(screen);
  const probe = document.createElement('span');probe.textContent = 'MMMMMMMMMM';
  probe.style.cssText = 'position:absolute;visibility:hidden;white-space:pre;font:'+style.font;
  screen.append(probe);
  const cw = Math.max(5, probe.getBoundingClientRect().width / 10);
  const ch = Math.max(12, parseFloat(style.lineHeight) || 19);
  probe.remove();
  return {cols: Math.max(20,Math.min(220,Math.floor((screen.clientWidth-16)/cw))),
          rows: Math.max(4,Math.min(100,Math.floor((screen.clientHeight-16)/ch)))};
 };
 const color = n => '#' + (n >>> 0).toString(16).padStart(6,'0').slice(-6);
 const draw = data => {
  if (!data.changed) return;
  version = data.version;
  screen.style.backgroundColor = color(data.bg);
  screen.style.color = color(data.fg);
  const fragment = document.createDocumentFragment();
  data.rows.forEach((spans, y) => {
   const line = document.createElement('div');line.className = 'nvim-row';line.dataset.row = String(y);
   let x = 0;
   for (const [text, styleId] of spans) {
    const run = document.createElement('span');
    run.textContent = text;
    const style = data.styles[styleId] || {};
    if (style.foreground !== undefined) run.style.color = color(style.foreground);
    if (style.background !== undefined) run.style.backgroundColor = color(style.background);
    if (style.bold) run.style.fontWeight = 'bold';
    if (style.italic) run.style.fontStyle = 'italic';
    if (style.underline) run.style.textDecoration = 'underline';
    if (style.reverse) {run.style.color = color(style.background ?? data.bg);run.style.backgroundColor = color(style.foreground ?? data.fg);}
    if (data.cursor[0] === y && data.cursor[1] >= x && data.cursor[1] < x + text.length) {
     const at = data.cursor[1]-x;
     run.textContent = text.slice(0,at);
     line.append(run);
     const caret = document.createElement('span');caret.className = 'nvim-caret';caret.textContent = text[at] || ' ';
     line.append(caret);
     const tail = run.cloneNode(false);tail.textContent = text.slice(at+1);line.append(tail);
    } else line.append(run);
    x += text.length;
   }
   fragment.append(line);
  });
  screen.replaceChildren(fragment);
 };
 const query = async (myGeneration, myToken) => {
  try {
   const reply = await fetch('/api/neovim/state?token='+encodeURIComponent(myToken)+'&since='+version);
   if (!reply.ok) throw Error('Neovim session disconnected');
   const data = await reply.json();
   if (myGeneration !== generation || !enabled) return;
   if (data.status !== 'available') throw Error(data.reason || 'Neovim exited');
   draw(data);
   // Source-to-schematic uses the existing AST mapping, never textual heuristics.
   const line = Number(data.source_line||0);
   if (line > 0 && line !== latestLine && line !== desiredLine) {
    latestLine = line;
    if (document.activeElement === screen && $('sourcePane') && !$('sourcePane').hidden) {
     // Shared cross-probe controller also handles ambiguous AST matches.
     // Do not choose an arbitrary signal when one source line has many uses.
     if (typeof window.FlexRTLProbeLine === 'function')
      window.FlexRTLProbeLine(line);

    }
   }
  } catch(error) {if(myGeneration === generation){message('Neovim unavailable: '+error.message, true);clearInterval(pollTimer);pollTimer=null;}}
 };
 const refresh = () => {
  if (!enabled || !token || panel.hidden) return;
  const size = dimensions(), key = size.cols+'x'+size.rows;
  if (key !== lastDimensions) {lastDimensions=key;post('resize',{token,...size}).catch(e=>message(e.message));}
 };
 const shutdown = async () => {
  generation++;
  if(pollTimer) clearInterval(pollTimer);
  pollTimer = null;
  const previous = token;token='';version=-1;lastDimensions='';
  if (previous) try {await post('stop',{token:previous});} catch (_e) {}
 };
 const start = async () => {
  if (!enabled) return;
  if (!source || source.status !== 'available') {
   message('Neovim cannot start: '+(source?.reason || 'no compiler-mapped source for this scope'), true);
   enabled=false;panel.hidden=true;fallback.hidden=false;
   button.setAttribute('aria-pressed','false');button.textContent='Neovim';
   return;
  }
  const myGeneration = ++generation;
  if(pollTimer)clearInterval(pollTimer);pollTimer=null;
  message('Starting local Neovim…');
  const previous = token;token='';version=-1;
  if(previous)try{await post('stop',{token:previous});}catch(_e){}
  try {
   // The desktop bridge is deliberately opt-in. Preflight before POST so a
   // disabled bridge or missing nvim/msgpack dependency gives the user a
   // meaningful action rather than an opaque 403 in the editor pane.
   const capabilityReply = await fetch('/api/neovim/capability');
   const bridge = await capabilityReply.json();
   if(!capabilityReply.ok || bridge.enabled !== true)
    throw Error(bridge.reason || 'Set FLEXSOC_RTL_NEOVIM=1 before fx rtl-view');
   const size = dimensions();lastDimensions=size.cols+'x'+size.rows;
   const result = await post('start',{path, ...size});
   if(myGeneration!==generation){post('stop',{token:result.token}).catch(()=>{});return;}
   token = result.token;file=result.file;latestLine=0;
   message('Neovim · '+file+' · read-only buffer');
   if(desiredLine>1)post('cursor',{token,line:desiredLine}).catch(()=>{});
   screen.focus();
   await query(myGeneration, token);
   pollTimer = setInterval(()=>query(myGeneration, token), 220);
  } catch (error) {
   if(myGeneration!==generation)return;
   message('Neovim unavailable: '+error.message+' · read-only fallback active', true);
   enabled=false;panel.hidden=true;fallback.hidden=false;button.setAttribute('aria-pressed','false');
   button.textContent='Neovim';
  }
 };
 button.addEventListener('click',async () => {
  enabled=!enabled;
  button.setAttribute('aria-pressed',String(enabled));
  button.textContent=enabled?'Source view':'Neovim';
  panel.hidden=!enabled;fallback.hidden=enabled;
  if(enabled)await start();else {message('Neovim session closed');await shutdown();}
 });
 const special = {Escape:'Esc',Enter:'CR',Backspace:'BS',Tab:'Tab',Delete:'Del',
  ArrowUp:'Up',ArrowDown:'Down',ArrowLeft:'Left',ArrowRight:'Right',
  Home:'Home',End:'End',PageUp:'PageUp',PageDown:'PageDown',Insert:'Insert'};
 screen.addEventListener('keydown', e => {
  if(!enabled||!token||e.isComposing)return;
  // Deliver Ctrl+V (visual block), Ctrl+C and custom mappings to native Neovim.
  let key = special[e.key] || (e.key.length===1?e.key:null);
  if(!key)return;
  const modifiers = (e.ctrlKey?'C-':'')+(e.altKey?'M-':'')+(e.metaKey?'D-':'');
  if(e.key==='<')key='<lt>';
  else if(modifiers||special[e.key])key='<'+modifiers+key+'>';
  e.preventDefault();e.stopPropagation();
  post('input',{token,keys:key}).catch(err=>message(err.message));
 });
 // Wheel and touchpad scrolling must reach the native UI. The ext_linegrid
 // is a viewport, not a scrollable document: overflow:auto cannot scroll it.
 let wheelFraction = 0;
 screen.addEventListener('wheel', e => {
  if (!enabled || !token) return;
  e.preventDefault();
  const unit = e.deltaMode === 1 ? 1 : e.deltaMode === 2 ? Math.max(4,dimensions().rows-2) : 1/35;
  wheelFraction += e.deltaY * unit;
  const steps = Math.trunc(wheelFraction);
  wheelFraction -= steps;
  if (!steps) return;
  const direction = steps > 0 ? 'down' : 'up';
  post('scroll',{token,direction,count:Math.min(60,Math.abs(steps))}).catch(err=>message(err.message));
 },{passive:false});
 screen.addEventListener('paste',e=>{
  if(!token)return;
  e.preventDefault();
  const text=e.clipboardData?.getData('text/plain')||'';
  if(text)post('input',{token,keys:text.slice(0,512)}).catch(err=>message(err.message));
 });
 const observer = new ResizeObserver(refresh);observer.observe(screen);
 window.FlexNativeEditor = {
  sync(scope,data,line){const old = path;path=scope;source=data;desiredLine=Math.max(1,Number(line)||1);
   if(enabled && (old!==scope || !token || data?.status!=='available'))start();else if(enabled)this.jump(desiredLine);},
  jump(line){desiredLine=Math.max(1,Number(line)||1);if(enabled&&token)post('cursor',{token,line:desiredLine}).catch(()=>{});},
  active(){return enabled&&!!token;}
 };
})();
