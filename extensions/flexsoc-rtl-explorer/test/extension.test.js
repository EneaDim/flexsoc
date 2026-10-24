'use strict';
const test=require('node:test');
const assert=require('node:assert/strict');
const path=require('node:path');
const fs=require('node:fs');
const http=require('node:http');
const Module=require('node:module');
const actual=Module._load;
Module._load=function(id,...args){
 if(id==='vscode')return {Uri:{file:p=>({fsPath:p})}};
 return actual.call(this,id,...args);
};
const {backendGet,webviewHtml}=require('../src/extension');
Module._load=actual;

test('webview bootstraps a restricted message bridge without external scripts',()=>{
 const media=path.join(__dirname,'..','media');
 const webview={cspSource:'vscode-resource:',asWebviewUri:uri=>({toString:()=>`vscode-resource:/${path.basename(uri.fsPath)}`})};
 const html=webviewHtml(webview,media);
 assert.match(html,/Content-Security-Policy/);
 assert.match(html,/connect-src 'none'/);
 assert.match(html,/window.FlexAPI=/);
 assert.match(html,/router\.js/);
 assert.doesNotMatch(html,/src="\/app.js"/);
 for(const name of ['index.html','app.js','style.css','router.js'])assert.ok(fs.existsSync(path.join(media,name)));
});

test('only fixed graph API paths allowed, backend errors never reclassified PASS',async()=>{
 const server=http.createServer((req,res)=>{
  res.setHeader('Content-Type','application/json');
  if(req.url.startsWith('/api/overview'))res.end(JSON.stringify({top:'DSP'}));
  else {res.statusCode=400;res.end(JSON.stringify({error:'invalid graph path'}));}
 });
 await new Promise(resolve=>server.listen(0,'127.0.0.1',resolve));
 try{
  const port=server.address().port;
  assert.deepEqual(await backendGet(port,'overview',{}),{top:'DSP'});
  await assert.rejects(backendGet(port,'source',{path:'/broken'}),/invalid graph path/);
  await assert.rejects(backendGet(port,'../../etc/passwd',{}),/Unsupported/);
 }finally{await new Promise(resolve=>server.close(resolve));}
});
