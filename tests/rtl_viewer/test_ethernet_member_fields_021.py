"""Characterization of a small, unmodified slice of real Ethernet Slang JSON.

The fixture retains compiler identifiers, member access metadata and an
elaborated FIFO port binding from axi_lite_to_reg.sv. It is not a parsed RTL
approximation and does not claim field bit offsets or physical equivalence.
"""
import json
import shutil
import subprocess
from pathlib import Path

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

FIXTURE = Path(__file__).parent / 'fixtures' / 'ethernet_slang_members_021.json'
WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'
SOURCE = 'vendor/pulp/register_interface/src/axi_lite_to_reg.sv'


def design(tmp_path, payload=None):
    source = tmp_path / SOURCE
    source.parent.mkdir(parents=True, exist_ok=True)
    # Only the line numbers matter for source resolution. The AST fixture
    # supplies every declaration/identity; this file is not parsed as RTL.
    source.write_text('module example;\n' + '\n' * 150 + 'endmodule\n')
    return RtlDesign(payload or json.loads(FIXTURE.read_text()),
                     root=tmp_path, top='top')


def test_real_slang_member_accesses_are_separate_projection_values(tmp_path):
    graph = design(tmp_path).diagram(limit=300)
    fields = {n['field']: n for n in graph['nodes'] if n.get('shape') == 'field'}
    assert {'aw_valid', 'w_valid'} <= fields.keys()
    assert len({fields['aw_valid']['id'], fields['w_valid']['id']}) == 2
    for name in ('aw_valid', 'w_valid'):
        selection = fields[name]
        assert selection['line'] == 107
        incoming = [e for e in graph['edges'] if e['target'] == selection['id']]
        assert len(incoming) == 1
        assert incoming[0]['source'] == '/::sig:axi_lite_req_i'
        assert incoming[0]['mapping'] == 'partial', 'No invented struct bit positions'
        assert incoming[0]['rendered'] is True
    consumers = [e for e in graph['edges'] if e['source'] in {fields[k]['id'] for k in ('aw_valid', 'w_valid')}]
    assert len(consumers) == 2
    assert all(e['rendered'] and e['mapping'] == 'expression' for e in consumers)
    assert {e['pin'] for e in consumers} == {'A', 'B'}
    assert all(e['net'] == '/::expr:' + e['source'].split('::')[-1] for e in consumers)
    # Each selected field has a distinct expression net; the two full-struct
    # dependencies must never be joined as two full-width wires on AND inputs.
    assert len({e['net'] for e in consumers}) == 2


def test_missing_field_metadata_is_not_reconstructed_from_base_or_text(tmp_path):
    payload = json.loads(FIXTURE.read_text())
    def walk(node):
        if isinstance(node, dict):
            if node.get('kind') == 'MemberAccess' and str(node.get('member', '')).endswith('aw_valid'):
                node['member'] = '6338716865104 ???'
            for v in node.values(): walk(v)
        elif isinstance(node, list):
            for v in node: walk(v)
    walk(payload)
    graph = design(tmp_path, payload).diagram()
    assert not any(n.get('field') == 'aw_valid' for n in graph['nodes'])
    assert any(e.get('routingStatus', '').startswith('unresolved_operand_')
               for e in graph['edges']), 'Unsafe field must remain non-wired'


def test_real_fifo_input_port_occurrence_uses_parent_ast_location(tmp_path):
    view = design(tmp_path)
    sites = view.occurrences('/', 'write_resp_fifo_pop')['sites']
    assert [(x['role'], x['line']) for x in sites] == [
        ('declaration', 72), ('read', 128), ('write', 135)]
    assert all(x['file'] == SOURCE and x['evidence'] == 'slang-ast' for x in sites)


def test_unknown_or_output_formal_is_not_falsely_marked_input_read(tmp_path):
    payload = json.loads(FIXTURE.read_text())
    members = payload['design']['members'][0]['body']['members']
    fifo = next(n for n in members if n.get('kind') == 'Instance')
    fifo['connections'][0]['port']['direction'] = 'Out'
    sites = design(tmp_path, payload).occurrences('/', 'write_resp_fifo_pop')['sites']
    assert ('read', 128) not in {(s['role'], s['line']) for s in sites}
    assert ('write', 128) in {(s['role'], s['line']) for s in sites}
    fifo['connections'][0]['port']['direction'] = 'InOut'
    sites = design(tmp_path, payload).occurrences('/', 'write_resp_fifo_pop')['sites']
    assert all(s['line'] != 128 for s in sites), 'Ambiguous inout direction must stay unknown'


@pytest.mark.skipif(not shutil.which('node'), reason='Node.js with bundled ELK required')
def test_real_elk_routes_both_selected_fields_to_distinct_and_pins(tmp_path):
    graph = design(tmp_path).diagram()
    script = r'''
const fs = require('node:fs'), assert = require('node:assert/strict');
const graph = JSON.parse(fs.readFileSync(0,'utf8'));
const web = process.argv[1];
const geom = require(web+'/symbol-geometry.js');
const adapter = require(web+'/elk-adapter.js');
const ELK = require(web+'/elk.bundled.js').default;
(async () => {
 const result = await adapter.compute(new ELK(),graph,geom.boxSize);
 const fields = graph.nodes.filter(n=>n.shape==='field'&&['aw_valid','w_valid'].includes(n.field));
 assert(fields.length>=2);
 for(const field of fields){
  const base=graph.edges.find(e=>e.target===field.id);
  const into=graph.edges.find(e=>e.source===field.id);
  assert(base && into && base.mapping==='partial');
  assert(result.edgePaths.has(base.id) && result.edgePaths.has(into.id));
  const route = result.edgePaths.get(into.id);
  const start = geom.absoluteAnchor(field,result.positions.get(field.id),'source',into);
  assert.deepEqual(route[0],[start.x,start.y]);
 }
 console.log('Real Slang field projections and ELK routing PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    proc = subprocess.run(['node','-e',script,str(WEB)], input=json.dumps(graph),
                          text=True, capture_output=True, timeout=30)
    assert proc.returncode == 0, proc.stdout+proc.stderr
    assert 'ELK routing PASS' in proc.stdout
