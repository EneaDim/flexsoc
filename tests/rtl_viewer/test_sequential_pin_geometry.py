"""Register inputs are routed to the same physical anchor drawn on the symbol."""
import shutil
import subprocess
from pathlib import Path
import pytest


def test_clock_event_and_data_use_distinct_register_pins():
    if not shutil.which('node'):
        pytest.skip('Node is required for the frontend router tests')
    router = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web/router.js'
    code = r'''
const assert=require('node:assert/strict');
const {pinGeometry,compute}=require(process.argv[1]);
const r={x:100,y:200,w:133,h:73},n={id:'q',type:'register'};
const d=pinGeometry(n,r,'','in'),c=pinGeometry(n,r,'CLK','in');
const e=pinGeometry(n,r,'EVENT','in'),q=pinGeometry(n,r,'','out');
assert.equal(d.x,104);assert.equal(q.x,229);
assert.deepEqual([d.y,c.y,e.y,q.y],[220,260,243,220]);
assert.equal(pinGeometry({type:'operator',shape:'mux'},r,'S','in').face,'bottom');
console.log('register pin anchors PASS');
'''
    run = subprocess.run(['node', '-e', code, str(router)], capture_output=True, text=True, timeout=12)
    assert run.returncode == 0, run.stderr + run.stdout
