"""AST-only tests. No SystemVerilog regex or invented port connections."""
import json
from pathlib import Path
from threading import Thread
from urllib.request import urlopen

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign, SlangProject
from flexsoc.backend.dv.rtl_viewer.server import ViewerServer


ROOT = Path(__file__).resolve().parents[2] / "examples/rtl_schematic_dsp"


def signal(name, direction="", kind="Variable", file="DSP.sv", line=1):
    return {"kind": kind, "name": name, "direction": direction,
            "type": "logic [15:0]", "sourceRange": {"start": {"file": file, "line": line}}}


def instance(name, module, members, file, connections=None):
    return {"kind": "Instance", "name": name, "sourceRange": {"start": {"file": file, "line": 1}},
            "body": {"kind": "InstanceBody", "name": module, "members": members},
            "connections": connections or []}


def ref(name):
    return {"kind": "NamedValue", "symbol": name}


def fixture_ast():
    lane_members = [signal("sample_i", "In", "Port", "DSP_lane.sv", 7),
                    signal("product_d", file="DSP_lane.sv", line=13),
                    signal("product_q", file="DSP_lane.sv", line=14),
                    {"kind": "ContinuousAssign", "assignment": {"kind": "Assignment", "left": ref("product_d"), "right": ref("sample_i")}},
                    {"kind": "ProceduralBlock", "procedureKind": "AlwaysFF", "body": {"kind": "Block", "statements": [
                        {"kind": "ExpressionStatement", "expr": {"kind": "Assignment", "left": ref("product_q"), "right": ref("product_d")}}]}}]
    blocks = []
    for idx in range(8):
        lane = instance("PE_random_8", "DSP_lane", lane_members, "DSP_lane.sv")
        blocks.append({"kind": "GenerateBlock", "name": f"g_mac[{idx}]", "members": [lane]})
    core_members = [signal("clk_i", "In", "Port", "DSP_core.sv"),
                    signal("samples_i", "In", "Port", "DSP_core.sv"),
                    signal("results_o", "Out", "Port", "DSP_core.sv"),
                    {"kind": "GenerateBlockArray", "name": "g_mac", "members": blocks}]
    core = instance("pipeline_abc", "DSP_core", core_members, "DSP_core.sv", connections=[
        {"port": "samples_i", "expression": ref("samples_i")},
        {"port": "clk_i", "expression": {"kind": "ElementSelect", "value": ref("clk_i")}}])
    root_members = [signal("clk_i", "In", "Port"), signal("samples_i", "In", "Port"),
                    signal("results_o", "Out", "Port"), core]
    return {"design": {"kind": "Root", "name": "$root", "members": [instance("DSP", "DSP", root_members, "DSP.sv")]}}


def test_hierarchy_generate_and_stability():
    ast = fixture_ast()
    viewer = RtlDesign(ast, root=ROOT, top="DSP")
    a = viewer.diagram()
    assert any(n.get("module") == "DSP_core" and n["name"] == "pipeline_abc" for n in a["nodes"])
    core = viewer.diagram("/pipeline_abc")
    stacks = [n for n in core["nodes"] if n["type"] == "generate"]
    assert len(stacks) == 1 and stacks[0]["count"] == 8
    exploded = viewer.diagram("/pipeline_abc", explode=True)
    assert len([n for n in exploded["nodes"] if n["type"] == "instance"]) == 8
    assert len(viewer.scopes) == 10  # top, core, eight elaborated lanes
    assert viewer.revision == RtlDesign(ast, root=ROOT, top="DSP").revision
    mutated = fixture_ast()
    mutated["design"]["members"][0]["addr"] = 999
    assert viewer.revision == RtlDesign(mutated, root=ROOT, top="DSP").revision


def test_real_ast_only_connections_and_register():
    viewer = RtlDesign(fixture_ast(), root=ROOT, top="DSP")
    tracked = viewer.follow("/", "/pipeline_abc", "/::sig:samples_i")
    assert tracked["status"] == "resolved"
    assert tracked["signal_id"] == "/pipeline_abc::sig:samples_i"
    assert viewer.follow("/", "/pipeline_abc", "/::sig:clk_i")["status"] == "unresolved"
    lane = viewer.diagram("/pipeline_abc/g_mac/g_mac[0]/PE_random_8")
    regs = [node for node in lane["nodes"] if node["type"] == "register"]
    assert [n["name"] for n in regs] == ["product_q"]
    cone = viewer.cone(lane["path"], lane["path"]+"::sig:sample_i", lane["path"]+"::sig:product_q")
    assert cone["status"] == "resolved" and len(cone["paths"]) == 1
    assert cone["sequential_boundaries"][0]


def test_missing_evidence_is_not_fabricated():
    viewer = RtlDesign(fixture_ast(), root=ROOT, top="DSP")
    assert viewer.source("/")["status"] == "available"
    assert viewer.lint("/")["status"] == "unavailable"
    assert viewer.overview()["source"] == "imported AST (unverified)"
    with pytest.raises(ValueError, match="hierarchy"):
        viewer.diagram("/does-not-exist")
    with pytest.raises(ValueError, match="missing"):
        RtlDesign(fixture_ast(), root=ROOT, top="UNKNOWN")


def test_compiler_fails_closed_without_slang(tmp_path):
    project = SlangProject(ROOT, "DSP", (Path("DSP.sv"),), slang="definitely-not-installed-slang")
    with pytest.raises(RuntimeError, match="missing"):
        project.compile(tmp_path / "compiled.json")
    with pytest.raises(ValueError, match="outside"):
        SlangProject(ROOT, "DSP", (Path("../../../etc/passwd"),))


def test_local_api():
    server = ViewerServer(("127.0.0.1", 0), RtlDesign(fixture_ast(), root=ROOT, top="DSP"))
    thread = Thread(target=server.serve_forever, daemon=True)
    thread.start()
    try:
        origin = f"http://127.0.0.1:{server.server_port}"
        with urlopen(origin + "/api/diagram?path=%2Fpipeline_abc") as response:
            graph = json.load(response)
        assert graph["module"] == "DSP_core" and graph["children"] == 8
        with urlopen(origin + "/") as response:
            assert b"RTL EXPLORER" in response.read()
    finally:
        server.shutdown()
        server.server_close()
