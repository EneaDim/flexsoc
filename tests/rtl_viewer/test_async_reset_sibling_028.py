"""Regression from real Ethernet Slang AST: independent D drivers per reset target."""
from __future__ import annotations

import copy
import json
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign


FIXTURE = Path(__file__).parent / "fixtures/ethernet_mixed_reset_slang_028.json"


def _graph(ast=None):
    return RtlDesign(json.loads(FIXTURE.read_text()) if ast is None else ast,
                     root=FIXTURE.parent, top="top").diagram(limit=1500)


def _d_edges(graph, name):
    node = next(n for n in graph["nodes"] if n["name"] == name)
    edges = [e for e in graph["edges"] if e["target"] == node["id"]
             and e.get("rendered") and e.get("targetPin") == "D"]
    return node, edges


def test_real_ethernet_slang_direct_ack_synchronizer_d_connections():
    """An unsupported reset on another register must not suppress these NBAs."""
    graph = _graph()
    meta, incoming = _d_edges(graph, "tx_ack_meta_csr")
    assert meta["type"] == "register"
    assert not meta.get("dInputStatus")
    assert len(incoming) == 1
    assert incoming[0]["source"] == "/::sig:tx_ack_mac"

    sync, incoming = _d_edges(graph, "tx_ack_sync_csr")
    assert sync["type"] == "register"
    assert not sync.get("dInputStatus")
    assert len(incoming) == 1
    assert incoming[0]["source"] == "/::sig:tx_ack_meta_csr"

    for name in ("tx_ack_meta_csr", "tx_ack_sync_csr"):
        node = next(n for n in graph["nodes"] if n["name"] == name)
        clock_reset = {e["pin"] for e in graph["edges"] if e["target"] == node["id"]
                       and e.get("rendered") and e["type"] == "event"}
        assert clock_reset == {"CLK", "RST"}


def test_compiler_literal_concat_reset_is_a_supported_reset_value():
    graph = _graph()
    node, edges = _d_edges(graph, "tx_payload_csr")
    assert node["type"] == "register"
    assert not node.get("dInputStatus")
    assert len(edges) == 1
    # This is a supported clock-side D relation, not a second wire from the reset constant.
    assert edges[0]["source"] != node["id"]


def test_multiple_process_writers_do_not_create_a_fake_d():
    ast = json.loads(FIXTURE.read_text())
    members = ast["design"]["members"][0]["body"]["members"]
    process = next(m for m in members if m.get("kind") == "ProceduralBlock")
    # A second process writing the same register invalidates a single D driver.
    other = copy.deepcopy(process)
    body = other["body"]["stmt"]
    # Reuse an AST-backed whole-symbol assignment, but as an independent process.
    def assignments(node):
        if isinstance(node, dict):
            if node.get("kind") == "Assignment":
                yield node
            for value in node.values():
                yield from assignments(value)
        elif isinstance(node, list):
            for item in node:
                yield from assignments(item)
    write = next(x for x in assignments(body)
                 if x.get("left", {}).get("symbol", "").endswith(" tx_ack_meta_csr"))
    other["body"]["stmt"] = {"kind": "ExpressionStatement", "expr": copy.deepcopy(write)}
    members.append(other)
    graph = _graph(ast)
    node, incoming = _d_edges(graph, "tx_ack_meta_csr")
    assert node["type"] == "register"
    assert not incoming


def test_elk_routes_each_ack_d_to_its_own_register_terminal():
    import shutil
    import subprocess
    import pytest

    if shutil.which("node") is None:
        pytest.skip("Node.js required for real ELK")
    graph = _graph()
    web = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web"
    script = r"""
const fs=require('node:fs'), assert=require('node:assert/strict');
const web=process.argv[1],graph=JSON.parse(fs.readFileSync(0,'utf8'));
const ELK=require(web+'/elk.bundled.js').default;
const adapter=require(web+'/elk-adapter.js'), geo=require(web+'/symbol-geometry.js');
(async()=>{
  const layout=await adapter.compute(new ELK(),graph,geo.boxSize);
  for(const name of ['tx_ack_meta_csr','tx_ack_sync_csr']){
    const node=graph.nodes.find(n=>n.name===name);
    const edge=graph.edges.find(e=>e.target===node.id && e.targetPin==='D' && e.rendered);
    assert(edge,'D driver required: '+name);
    const path=layout.edgePaths.get(edge.id);
    assert(path && path.length>=2,'missing ELK edge '+edge.id);
    const pos=layout.positions.get(node.id);
    const anchor=geo.absoluteAnchor(node,pos,'target',edge);
    assert.deepEqual(path.at(-1),[anchor.x,anchor.y]);
  }
})().catch(e=>{console.error(e);process.exitCode=1});
"""
    result = subprocess.run(["node", "-e", script, str(web)], input=json.dumps(graph),
                            capture_output=True, text=True, timeout=45)
    assert result.returncode == 0, result.stdout + result.stderr
