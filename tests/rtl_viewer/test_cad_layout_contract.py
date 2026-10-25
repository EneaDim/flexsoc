"""The CAD layout consumes electrical hyperedges, not dependency edges."""
from __future__ import annotations

import json
import subprocess
from pathlib import Path


def test_hyperedge_routed_once_with_all_terminals():
    script = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web/cad-layout.js'
    payload = {
        'schema': 'flexsoc.rtl_viewer.schematic.v1',
        'components': [{'id': '/a', 'name': 'a', 'module': 'sync'},
                       {'id': '/b', 'name': 'b', 'module': 'sync'}],
        'pins': [{'id': '/a::clk_i', 'component': '/a', 'name': 'clk_i', 'direction': 'input', 'state': 'bound'},
                 {'id': '/b::clk_i', 'component': '/b', 'name': 'clk_i', 'direction': 'input', 'state': 'bound'}],
        'ports': [{'id': '/::port:clk_i', 'name': 'clk_i', 'direction': 'input', 'net': '/::sig:clk_i'}],
        'nets': [{'id': '/::sig:clk_i', 'name': 'clk_i', 'type': 'logic', 'complete': True,
                  'terminals': [{'pin': '/::port:clk_i', 'mapping': 'direct'},
                                {'pin': '/a::clk_i', 'mapping': 'direct'},
                                {'pin': '/b::clk_i', 'mapping': 'direct'}]}],
    }
    js = f"const L=require({json.dumps(str(script))}).compute({json.dumps(payload)}); console.log(JSON.stringify(L))"
    result = subprocess.run(['node', '-e', js], capture_output=True, text=True, check=True)
    layout = json.loads(result.stdout)
    assert len(layout['components']) == 2
    assert len(layout['nets']) == 1
    assert len(layout['nets'][0]['branches']) == 3
    assert len(layout['nets'][0]['junctions']) == 3
    assert len({p['id'] for p in layout['pins']}) == 3
