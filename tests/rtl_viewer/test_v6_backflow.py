"""A driver physically to the right must route toward the left-hand consumer."""
from pathlib import Path
import shutil
import subprocess
import pytest

ROUTER = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web/router.js'


def test_reverse_driver_is_not_flipped_by_geometry():
    if not shutil.which('node'):
        pytest.skip('Node unavailable')
    script = r'''
const assert = require('node:assert/strict');
const {compute} = require(process.argv[1]);
const graph={nodes:[
 {id:'driver',type:'instance',ports:[{name:'unlike_o',direction:'out'}]},
 {id:'receiver',type:'instance',ports:[{name:'totally_different_i',direction:'in'}]}],
 edges:[{id:'net0',source:'driver',target:'receiver',type:'port_in',port:'totally_different_i',net:'data'}]};
const layout=compute(graph,{boxSize:()=>({w:220,h:100}),baseRank:n=>n.id==='driver'?6:1});
const a=layout.positions.get('driver'),b=layout.positions.get('receiver');
assert.ok(a.x>b.x,'driver to the right, receiver left');
const poly=layout.edgePaths.get('net0');
assert.ok(poly[0][0]<a.x+a.w/2,'source exits LEFT face');
assert.ok(poly.at(-1)[0]>b.x+b.w/2,'sink receives RIGHT face');
assert.ok(poly.at(-2)[0]>poly.at(-1)[0],'last segment arrow points LEFT');
assert.equal(layout.portFaces.get('receiver::totally_different_i'),'right');
for(let i=1;i<poly.length;i++) assert.ok(poly[i-1][0]===poly[i][0]||poly[i-1][1]===poly[i][1]);
'''
    proc = subprocess.run(['node','-e',script,str(ROUTER)],capture_output=True,text=True,timeout=10)
    assert proc.returncode == 0, proc.stderr+proc.stdout
