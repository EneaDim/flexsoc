"""The actual browser router must continue auditing beyond 140 wires."""
import json
from pathlib import Path
import shutil
import subprocess

import pytest

ROUTER = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web/router.js'


def run_node(source):
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    completed = subprocess.run(['node', '-e', source, str(ROUTER)], text=True,
                               capture_output=True, timeout=30)
    assert completed.returncode == 0, completed.stderr
    return json.loads(completed.stdout)


def test_spatial_index_matches_baseline_collision_score():
    data = run_node(r'''
const R=require(process.argv[1]);
const positions=new Map([
 ['a',{x:0,y:20,w:65,h:45}],['obstacle',{x:130,y:20,w:80,h:80}],
 ['b',{x:290,y:20,w:65,h:45}]]);
const edges=[{id:'a-b',source:'a',target:'b',net:'one'},
             {id:'another',source:'a',target:'b',net:'two'}];
const metadata=new Map(edges.map(e=>[e.id,e]));
const occupants=new R.RoutingOccupancy(positions,metadata);
const route=[[65,42],[320,42]];
const prior=[[65,42],[120,42],[120,130],[310,130],[310,42]];
occupants.add('another',prior);
const spatial=occupants.score('a-b',route);
const reference=R.geometryScore('a-b',route,positions,new Map([['another',prior]]),metadata);
console.log(JSON.stringify({spatial,reference}));
''')
    assert data['spatial'] == data['reference']
    assert data['spatial']['boxHits'] > 0


def test_180_parallel_wires_receive_real_geometry_audit():
    data = run_node(r'''
const R=require(process.argv[1]),positions=new Map(),paths=new Map(),edges=[];
for(let i=0;i<180;i++){
 const y=i*140+100,a='a'+i,b='b'+i,obstacle='wall'+i,id='wire'+i;
 positions.set(a,{x:0,y:y-25,w:80,h:50});
 positions.set(b,{x:400,y:y-25,w:80,h:50});
 positions.set(obstacle,{x:190,y:y-40,w:80,h:80});
 paths.set(id,[[72,y],[210,y],[472,y]]);
 edges.push({id,source:a,target:b,net:'net'+i,type:'data'});
}
const result=R.refine({edges},positions,paths,180*140+100);
console.log(JSON.stringify({before:result.stats.nodeConflictsBefore,
 after:result.stats.nodeConflictsAfter,refined:result.stats.refined,
 skipped:result.stats.skipped,quality:result.stats.quality,size:result.paths.size}));
''')
    assert data['size'] == 180
    assert data['skipped'] == 0 and data['quality'] == 'audited'
    assert data['before'] >= 180
    assert data['after'] < data['before']
    assert data['refined'] > 0
