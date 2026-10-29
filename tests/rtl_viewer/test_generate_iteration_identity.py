"""Elaborated Slang loop iterations have distinct canonical instance paths."""
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign


def test_slanged_loop_iteration_index_survives_unnamed_blocks(tmp_path: Path):
    def leaf():
        return {"kind": "Instance", "name": "u_lane", "body": {
            "kind": "InstanceBody", "name": "Lane", "members": []}}
    top = {"kind": "Instance", "name": "top", "body": {"kind": "InstanceBody", "name": "Top",
        "members": [{"kind": "GenerateBlockArray", "name": "g_parallel", "members": [
            {"kind": "GenerateBlock", "branchKind": "LoopIteration", "constructIndex": i,
             "members": [leaf()]} for i in range(3)]}]}}
    rtl = RtlDesign({"design": {"kind": "Root", "members": [top]}}, root=tmp_path, top="top")
    expected = {f"/g_parallel/g_parallel[{i}]/u_lane" for i in range(3)}
    assert expected.issubset(rtl.scopes)
    assert len(set(rtl.scopes)) == 4
    graph = rtl.diagram("/", explode=True)
    assert {n['child'] for n in graph['nodes'] if n['type'] == 'instance'} == expected
