"""Node-based contract tests independent of a browser or RTL fixture."""
import subprocess
from pathlib import Path


WEB = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web"


def test_layout_contract():
    source = r"""
const assert = require('node:assert/strict');
const {create,validate}=require(process.argv[1]);
const graph={nodes:[{id:'a'},{id:'b'}],edges:[{id:'e',source:'a',target:'b'}]};
const good=()=>({positions:new Map([['a',{x:0,y:0,w:30,h:30}],['b',{x:100,y:0,w:30,h:30}]]),edgePaths:new Map([['e',[[30,15],[100,15]]]]),width:140,height:50,portFaces:new Map(),bridges:[]});
assert.equal(validate(graph,good()).ok,true);
const lost=good(); lost.edgePaths.delete('e');
assert.match(validate(graph,lost).errors.join(' '),/missing edge/);
const extra=good();extra.positions.set('phantom',{x:1,y:1,w:2,h:2});
assert.match(validate(graph,extra).errors.join(' '),/extraneous node/);
const invalid=good();invalid.edgePaths.set('e',[[NaN,0],[100,15]]);
assert.match(validate(graph,invalid).errors.join(' '),/invalid or missing edge/);
const engine=create({fallback:{compute:good},boxSize:()=>null,baseRank:()=>0});
assert.equal(engine.compute(graph).edgePaths.size,1);
assert.throws(()=>engine.setStrategy('elk'),/unavailable/);
assert.throws(()=>create({fallback:{compute:()=>lost}}).compute(graph),/geometry invalid/);
"""
    subprocess.run(["node", "-e", source, str(WEB / "layout-engine.js")], check=True)


def test_static_server_exposes_layout_contract():
    from flexsoc.backend.dv.rtl_viewer.server import ASSETS
    assert (ASSETS / "layout-engine.js").is_file()
    assert '"/layout-engine.js": "layout-engine.js"' in (ASSETS.parent / "server.py").read_text()
