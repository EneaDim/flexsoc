'use strict';
/* FlexSoC VS Code / Cursor adapter. All RTL semantics stay in the Slang backend.
 * The embedded webview receives only readonly, whitelisted graph queries.
 */
const vscode = require('vscode');
const fs = require('node:fs');
const path = require('node:path');
const http = require('node:http');
const {spawn} = require('node:child_process');
const {randomBytes} = require('node:crypto');

const API = new Set(['overview', 'diagram', 'source', 'follow', 'cone', 'lint']);
const VIEWS = ['index.html', 'style.css', 'router.js', 'app.js'];

function backendGet(port, route, params, timeoutMs=12000) {
  if (!API.has(route)) return Promise.reject(new Error('Unsupported RTL graph request'));
  const url = new URL(`http://127.0.0.1:${port}/api/${route}`);
  for (const [k,v] of Object.entries(params||{})) url.searchParams.set(k, String(v));
  return new Promise((resolve, reject) => {
    const req = http.get(url, {timeout:timeoutMs}, res=>{
      let buffer='';
      res.setEncoding('utf8');
      res.on('data', part=>{
        buffer+=part;
        if(buffer.length>8_000_000) req.destroy(new Error('Graph response exceeded 8 MB'));
      });
      res.on('end',()=>{
        try {const payload=JSON.parse(buffer); if(res.statusCode!==200) reject(new Error(payload.error||`HTTP ${res.statusCode}`)); else resolve(payload);}
        catch(e){reject(e);}
      });
    });
    req.on('timeout',()=>req.destroy(new Error('RTL backend timeout')));
    req.on('error',reject);
  });
}

function webviewHtml(webview, media) {
  const nonce=randomBytes(16).toString('base64');
  const uri=name=>webview.asWebviewUri(vscode.Uri.file(path.join(media,name))).toString();
  let html=fs.readFileSync(path.join(media,'index.html'),'utf8');
  html=html.replace('href="/style.css"',`href="${uri('style.css')}"`)
    .replace('src="/router.js"',`src="${uri('router.js')}"`)
    .replace('src="/app.js"',`src="${uri('app.js')}"`);
  const bootstrap=`<script nonce="${nonce}">
    (()=>{ const vscode=acquireVsCodeApi(); let next=1; const pending=new Map();
      window.FlexAPI=(route,params={})=>new Promise((resolve,reject)=>{
        const id=next++; pending.set(id,{resolve,reject});
        vscode.postMessage({type:'api',id,route,params});
      });
      window.addEventListener('message',event=>{
        const m=event.data; if(m?.type!=='apiResult'||!pending.has(m.id))return;
        const item=pending.get(m.id);pending.delete(m.id);
        m.error?item.reject(Error(m.error)):item.resolve(m.data);
      });
    })();
  </script>`;
  const csp=`default-src 'none'; img-src ${webview.cspSource} data:; font-src ${webview.cspSource}; style-src ${webview.cspSource}; script-src ${webview.cspSource} 'nonce-${nonce}'; connect-src 'none';`;
  return html.replace('<head>',`<head><meta http-equiv="Content-Security-Policy" content="${csp}">`)
    .replace('</head>',`${bootstrap}</head>`);
}

async function open(context){
  const folder=vscode.workspace.workspaceFolders?.[0];
  if(!folder){vscode.window.showErrorMessage('Open an RTL workspace folder first.');return;}
  const root=folder.uri.fsPath;
  const cfg=vscode.workspace.getConfiguration('flexsoc.rtlExplorer');
  const repo=cfg.get('repository')||root;
  const script=path.join(repo,'scripts','rtl_viewer.py');
  const media=path.join(context.extensionPath,'media');
  if(!fs.existsSync(script)||!VIEWS.every(name=>fs.existsSync(path.join(media,name)))){
    vscode.window.showErrorMessage('FlexSoC backend or viewer media missing. Configure flexsoc.rtlExplorer.repository and package the media assets.');return;
  }
  const filelists=cfg.get('filelists')||[];
  let files=[];
  if(!filelists.length){
    const uris=await vscode.workspace.findFiles('**/*.{sv,v}', '**/{.git,workspace,node_modules,.venv}/**', 1500);
    const active=vscode.window.activeTextEditor?.document.uri.fsPath;
    const choices=uris.map(u=>({label:path.relative(root,u.fsPath),picked:u.fsPath===active}));
    const selection=await vscode.window.showQuickPick(choices,{canPickMany:true,placeHolder:'Select RTL files (or configure filelists in settings)'});
    if(!selection?.length)return;
    files=selection.map(item=>item.label);
  }
  const suggested=vscode.window.activeTextEditor?.document.uri.fsPath;
  const top=await vscode.window.showInputBox({prompt:'Top module (Slang elaboration)',value:suggested?path.basename(suggested).replace(/\.(sv|v)$/,''):''});
  if(!top)return;
  const argv=[script,'--root',root,'--top',top,'--port','0'];
  for(const file of files)argv.push('--file',file);
  for(const file of filelists)argv.push('--filelist',file);
  for(const include of cfg.get('includes')||[])argv.push('--include',include);
  for(const define of cfg.get('defines')||[])argv.push('--define',define);
  const terminal=vscode.window.createOutputChannel('FlexSoC RTL Explorer');
  const child=spawn(cfg.get('python')||'python3',argv,{cwd:repo,stdio:['ignore','pipe','pipe'],shell:false});
  const panel=vscode.window.createWebviewPanel('flexsocRtl',`RTL · ${top}`,vscode.ViewColumn.Active,{
    enableScripts:true,retainContextWhenHidden:true,localResourceRoots:[vscode.Uri.file(media)]
  });
  let dead=false,started=false,buffer='',timeout;
  const stop=()=>{if(dead)return;dead=true;clearTimeout(timeout);child.kill();terminal.dispose();};
  panel.onDidDispose(stop);
  child.stderr.on('data',d=>terminal.append(d.toString()));
  child.stdout.on('data',d=>{
    terminal.append(d.toString());buffer+=d.toString();
    const match=buffer.match(/FlexSoC RTL Explorer:\s*http:\/\/127\.0\.0\.1:(\d+)/);
    if(!match||started||dead)return;
    started=true;clearTimeout(timeout);
    const port=Number(match[1]);panel.webview.html=webviewHtml(panel.webview,media);
    panel.webview.onDidReceiveMessage(async m=>{
      if(m?.type!=='api'||!Number.isSafeInteger(m.id))return;
      try{const data=await backendGet(port,m.route,m.params);if(!dead)panel.webview.postMessage({type:'apiResult',id:m.id,data});}
      catch(error){if(!dead)panel.webview.postMessage({type:'apiResult',id:m.id,error:String(error.message||error)});}
    });
  });
  child.on('error',err=>{terminal.appendLine(String(err));vscode.window.showErrorMessage(`FlexSoC: ${err.message}`);panel.dispose();});
  child.on('exit',code=>{if(!dead){vscode.window.showWarningMessage(`RTL backend exited (${code}). Check FlexSoC RTL Explorer output.`);panel.dispose();}});
  timeout=setTimeout(()=>{if(!started&&!dead){vscode.window.showErrorMessage('Slang startup timed out. Check the FlexSoC RTL Explorer output.');panel.dispose();}},60000);
}
function activate(context){context.subscriptions.push(vscode.commands.registerCommand('flexsoc.rtlExplorer.open',()=>open(context)));}
function deactivate(){}
module.exports={activate,deactivate,backendGet,webviewHtml};
