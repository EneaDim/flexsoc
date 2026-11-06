"""Read-only syntax presentation; code-to-AST mapping is never inferred from tokens."""
from pathlib import Path
import subprocess
import shutil
import pytest

WEB = Path(__file__).resolve().parents[2] / 'src/flexsoc/backend/dv/rtl_viewer/web'


def test_systemverilog_lexer_multiline_and_strings():
    if not shutil.which('node'):
        pytest.skip('Node.js unavailable')
    script = r'''
const assert=require('node:assert/strict');
const fs=require('node:fs');
const root=process.argv[1];
const h=require(root+'/sv-highlight.js');
let r=h.tokenize('always_comb begin /* comments');
assert(r.tokens.some(t=>t.kind==='keyword'&&t.text==='always_comb'));
assert(r.tokens.some(t=>t.kind==='comment'));
assert(r.state.comment);
r=h.tokenize('endmodule */ if (sel) q = 8\'hFF;',r.state);
assert(r.tokens[0].kind==='comment');
assert(r.tokens.some(t=>t.kind==='keyword'&&t.text==='if'));
assert(r.tokens.some(t=>t.kind==='number'&&t.text==="8'hFF"));
r=h.tokenize('string s = "// not a comment"; // real');
assert(r.tokens.some(t=>t.kind==='string'&&t.text==='"// not a comment"'));
assert(r.tokens.some(t=>t.kind==='comment'&&t.text==='// real'));
assert(h.tokenize('`ifdef TEST').tokens[0].kind==='directive');
const html=fs.readFileSync(root+'/index.html','utf8');
assert(html.indexOf('/sv-highlight.js')<html.indexOf('/app.js'));
const app=fs.readFileSync(root+'/app.js','utf8');
assert(app.includes('FlexSvHighlight?.renderLine'));
assert(app.includes('rtl-lint-summary'));
assert(app.includes('Filter code or message'));
'''
    result = subprocess.run(['node', '-e', script, str(WEB)], capture_output=True, text=True, timeout=15)
    assert result.returncode == 0, result.stdout + result.stderr
