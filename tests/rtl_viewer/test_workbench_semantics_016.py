"""Presentation helpers: only source-attributed lint and compiler-backed tooltip facts."""
from pathlib import Path
import shutil
import subprocess

import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_semantic_hover_and_lint_are_grounded_in_evidence():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    script = r'''
const assert=require('node:assert/strict');
const H=require(process.argv[1]+'/workbench-semantics.js');
const mux=H.semantic({id:'op:2',type:'operator',kind:'ConditionalOp',name:'MUX',controlSource:'state_reg',origin:'ProcessLowerer'});
assert.equal(mux.kind,'RTL operator');
assert(mux.rows.some(([key,value])=>key==='Controller'&&value==='state_reg'));
const virtual=H.semantic({type:'fsm_group',name:'FSM · state_reg'});
assert.equal(virtual.kind,'Virtual FSM');
assert(virtual.rows.some(([key,value])=>key==='Scope'&&value.includes('Virtual')));
const edge=H.semantic({id:'edge',source:'a',target:'b',type:'control',rendered:false,mapping:'partial'});
assert.equal(edge.tone,'partial');
assert(edge.rows.some(([key,value])=>key==='Status'&&value.includes('not routed')));
assert.equal(H.sameFile('workspace/runs/ethernet/rtl/ethernet_rx.sv','rtl/ethernet_rx.sv'),true);
assert.equal(H.sameFile('rtl/ethernet_rx.sv','rtl/ethernet_tx.sv'),false);
const lint={status:'available',file:'rtl/ethernet_rx.sv',diagnostics:[
  {file:'rtl/ethernet_rx.sv',line:17,priority:'P2',code:'CHECK',message:'something'},
  {file:'rtl/ethernet_rx.sv',line:17,priority:'P0',code:'ERROR',message:'bad'},
  {file:'rtl/ethernet_tx.sv',line:17,priority:'P0',message:'foreign'},
  {file:'rtl/ethernet_rx.sv',line:1000,priority:'P1',message:'out of range'},
  {file:'rtl/ethernet_rx.sv',line:0,priority:'P1',message:'no line'}
]};
const marks=H.lintMarks(lint,'workspace/runs/ethernet/rtl/ethernet_rx.sv',100);
assert.equal(marks.size,1);
assert.deepEqual(marks.get(17).map(x=>x.priority),['P0','P2']);
assert.equal(H.lintMarks(lint,'rtl/ethernet_tx.sv',100).size,0);
assert.equal(H.lintMarks({...lint,status:'unavailable'},'rtl/ethernet_rx.sv',100).size,0);
console.log('SEMANTIC WORKBENCH PASS');
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True,
                            text=True, timeout=20)
    assert result.returncode == 0, result.stdout + result.stderr
    assert 'SEMANTIC WORKBENCH PASS' in result.stdout


def test_workbench_ui_contains_one_tooltip_and_existing_legend():
    html = (WEB / 'index.html').read_text()
    js = (WEB / 'app.js').read_text()
    css = (WEB / 'style.css').read_text()
    assert html.count('id="rtlSemanticTooltip"') == 1
    assert 'id="sourceTab"' in html and 'id="lintTab"' in html
    assert 'id="toggleInspector"' in html
    assert 'data-fsrtl0036="legend"' in html
    assert 'workbench-semantics.js' in html
    assert 'showSemanticTip(item,ev)' in js
    assert "api('lint',{path}).then" in js
    assert '.rtl-lint-line' in css and '.rtl-semantic-tooltip' in css
