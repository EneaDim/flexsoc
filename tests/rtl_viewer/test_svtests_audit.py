"""A local sv-tests miniature corpus — no fake claims of external coverage."""
from pathlib import Path
import json
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from rtl_viewer_svtests import cases_at, check_case, report


def test_svtests_manifest_classifies_negative_and_positive(tmp_path):
    tests=tmp_path/'tests/chapter-11'
    tests.mkdir(parents=True)
    good=tests/'positive.sv'
    good.write_text('/*\nname: positive\ntop_module: Demo\ntags: [11.4.3]\n*/\nmodule Demo; endmodule\n')
    bad=tests/'negative.sv'
    bad.write_text('/*\nname: negative\nshould_fail_because: invalid syntax\n*/\nmodule Demo; error endmodule\n')
    (tests/'dependency.sv').write_text('module helper; endmodule;\n')
    cases=cases_at(tmp_path)
    assert len(cases)==2
    result={c.metadata['name']:check_case(c,tmp_path,'missing-slang',2) for c in cases}
    assert result['negative']['status']=='negative_expected'
    assert result['positive']['status']=='unsupported_or_error' or result['positive']['status']=='slang_failed'
    assert report(list(result.values()),tmp_path,inventory=False)['total']==2


def test_inventory_reports_not_run_not_fake_pass(tmp_path):
    tests=tmp_path/'tests/chapter-6'
    tests.mkdir(parents=True)
    (tests/'wire.sv').write_text('/*\n:name: wire\n*/\nmodule test; endmodule\n')
    out=tmp_path/'report.json'
    cp=subprocess.run([sys.executable,str(ROOT/'scripts/rtl_viewer_svtests.py'),'--suite',str(tmp_path),'--out',str(out),'--inventory'],capture_output=True,text=True)
    assert cp.returncode==0,cp.stderr
    data=json.loads(out.read_text())
    assert data['statuses']=={'not_run':1}
    assert data['complete_inventory']


def test_yaml_metadata_lists_keep_indentation(tmp_path):
    from rtl_viewer_svtests import read_metadata
    p=tmp_path/'multi.sv'
    p.write_text('/*\n * :name: multi\n * :files:\n *   - a.sv\n *   - b.sv\n * :incdirs:\n *   - include\n */\nmodule Test; endmodule\n')
    assert read_metadata(p)['files']==['a.sv','b.sv']
    assert read_metadata(p)['incdirs']==['include']
