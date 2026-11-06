'use strict';
/* FlexSoC theme contract: UI colors and Canvas ink must change together.
 * No RTL geometry, Slang facts, or ELK edges are affected by theme choices.
 */
(function(root){
 const presets=Object.freeze({
  graphite:{label:'Graphite',shell:'dark',surface:'#171b24',background:'#0d1118',
   canvas:{counter:'#e6ad78',fsm:'#c5a4f5',port:'#85c8f3',signal:'#a5bdd4',register:'#f0a572',operator:'#e9b985',instance:'#86c8f0',generate:'#e9ae77',wire:'#91afca',binding:'#85cee8',sequential:'#efad81',symbolFill:'#242e3d',pickedFill:'#374457',stackFill:'#333e4e',stackStroke:'#b88f72',text:'#f3f6fd',muted:'#b5c5d8',canvas:'#0e121a'}},
  oled:{label:'OLED Black',shell:'dark',surface:'#111216',background:'#08090c',
   canvas:{counter:'#f1b882',fsm:'#cbb3ff',port:'#91cefa',signal:'#b6c8db',register:'#f2b089',operator:'#ecc08b',instance:'#8ed1ed',generate:'#eba879',wire:'#a2bbd2',binding:'#8bcdea',sequential:'#e8ab85',symbolFill:'#171b22',pickedFill:'#303b4b',stackFill:'#2c3544',stackStroke:'#ad8c6d',text:'#f5f7fa',muted:'#b6c4d1',canvas:'#050609'}},
  midnight:{label:'Midnight Blue',shell:'dark',surface:'#121d31',background:'#0b1324',
   canvas:{counter:'#ffb980',fsm:'#ceadff',port:'#75c8ff',signal:'#9cb9df',register:'#f7a778',operator:'#f0bc7f',instance:'#6ec8fb',generate:'#f4b078',wire:'#91afd9',binding:'#8bccff',sequential:'#f4ac80',symbolFill:'#1c3049',pickedFill:'#2a4666',stackFill:'#31445e',stackStroke:'#a98c6c',text:'#f0f5ff',muted:'#b2c4e1',canvas:'#0a1225'}},
  ocean:{label:'Deep Ocean',shell:'dark',surface:'#10252b',background:'#08191e',
   canvas:{counter:'#f9b582',fsm:'#c6abff',port:'#7bd5e8',signal:'#93c6cf',register:'#ffa978',operator:'#eebd86',instance:'#76d7e8',generate:'#e9ac81',wire:'#86c0c8',binding:'#72d7d5',sequential:'#f6ad7c',symbolFill:'#173840',pickedFill:'#28545b',stackFill:'#2c4851',stackStroke:'#ac8e6d',text:'#f1fafa',muted:'#a8d1d1',canvas:'#091b20'}},
  light:{label:'Light',shell:'light',surface:'#ffffff',background:'#f4f7fb',
   canvas:{counter:'#904416',fsm:'#6446a9',port:'#135b83',signal:'#244a69',register:'#964313',operator:'#995117',instance:'#125d85',generate:'#a34d17',wire:'#255775',binding:'#11657f',sequential:'#9f4b16',symbolFill:'#ffffff',pickedFill:'#d3ebf8',stackFill:'#e7eff7',stackStroke:'#936548',text:'#132d40',muted:'#3a617a',canvas:'#fbfcff'}}
 });
 const accentChoices=Object.freeze({teal:['#67dfc5','#08766c'],blue:['#84bbff','#165cb2'],violet:['#c8a5ff','#7040b5'],amber:['#f6bc74','#99500c']});
 const keyTheme='flexsoc-rtl-theme',keyAccent='flexsoc-rtl-accent';
 const normTheme=value=>Object.hasOwn(presets,value)?value:'graphite';
 function contrast(a,b){
  const l=hex=>{
   const x=hex.match(/^#[0-9a-f]{6}$/i);if(!x)return 0;
   const c=[1,3,5].map(i=>parseInt(hex.slice(i,i+2),16)/255)
    .map(v=>v<=.04045?v/12.92:((v+.055)/1.055)**2.4);
   return .2126*c[0]+.7152*c[1]+.0722*c[2];
  };
  const v=l(a),w=l(b);return (Math.max(v,w)+.05)/(Math.min(v,w)+.05);
 }
 function mix(a,b,t){
  const c=n=>Math.round(parseInt(a.slice(n,n+2),16)*(1-t)+parseInt(b.slice(n,n+2),16)*t);
  return '#'+[1,3,5].map(i=>c(i).toString(16).padStart(2,'0')).join('');
 }
 function readableAccent(hex,base,light){
  const raw=/^#[0-9a-f]{6}$/i.test(hex)?hex.toLowerCase():accentChoices.teal[light?1:0];
  const toward=light?'#000000':'#ffffff';
  if(contrast(raw,base)>=4.5)return raw;
  for(let i=1;i<=20;i++){
   const candidate=mix(raw,toward,i/20);
   if(contrast(candidate,base)>=4.5)return candidate;
  }
  return light?'#111111':'#ffffff';
 }
 function normAccent(value){
  return Object.hasOwn(accentChoices,value)?value:/^#[0-9a-f]{6}$/i.test(value||'')?value.toLowerCase():'teal';
 }
 function stored(key,fallback){try{return root.localStorage?.getItem(key)||fallback;}catch(_){return fallback;}}
 function save(key,value){try{root.localStorage?.setItem(key,value);}catch(_){}}
 function apply(name,choice='teal',element=root.document?.documentElement){
  const presetName=normTheme(name),accentChoice=normAccent(choice),spec=presets[presetName];
  const light=spec.shell==='light';
  const candidate=accentChoices[accentChoice]?.[light?1:0]||accentChoice;
  const accent=readableAccent(candidate,spec.surface,light);
  const soft=mix(accent,spec.surface,light?.86:.79);
  if(element){
   element.dataset.theme=spec.shell;
   element.dataset.palette=presetName;
   element.style.setProperty('--accent',accent);
   element.style.setProperty('--accent-soft',soft);
  }
  save(keyTheme,presetName);save(keyAccent,accentChoice);
  return {name:presetName,accentChoice,accent,colors:{...spec.canvas,selected:accent},spec};
 }
 const api={presets,accentChoices,normTheme,normAccent,contrast,readableAccent,apply,
            readTheme:()=>normTheme(stored(keyTheme,'graphite')),
            readAccent:()=>normAccent(stored(keyAccent,'teal'))};
 if(typeof module==='object'&&module.exports)module.exports=api;
 else root.FlexRTLThemes=api;
})(typeof window==='object'?window:globalThis);
