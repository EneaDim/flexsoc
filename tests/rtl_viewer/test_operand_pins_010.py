"""Pin safety regression across patches 010 and 011.

Recognized AST subexpressions now have actual intermediate expression nodes;
unsupported selections retain their non-rendered dependency evidence.
"""
from pathlib import Path
import json
import shutil
import subprocess

import pytest

from flexsoc.backend.dv.rtl_viewer import RtlDesign

WEB = Path(__file__).resolve().parents[2] / "src/flexsoc/backend/dv/rtl_viewer/web"


def ref(n):
    return {"kind": "NamedValue", "symbol": f"{n} arbitrary_display_text"}


def schematic(expression):
    members = [{"kind": "Variable", "name": n, "addr": i}
               for i, n in enumerate(("q", "a", "b", "c", "clk"), 1)]
    members.append({"kind": "ProceduralBlock", "procedureKind": "AlwaysFF",
                    "body": {"kind": "Timed",
                             "timing": {"kind": "SignalEvent", "edge": "PosEdge", "expr": ref(5)},
                             "stmt": {"kind": "Assignment", "left": ref(1), "right": expression}}})
    ast = {"design": {"members": [{"kind": "Instance", "name": "top", "body": {
        "kind": "InstanceBody", "name": "top", "members": members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top="top").diagram()


def nested():
    return {"kind": "BinaryOp", "op": "BitwiseXor",
            "left": {"kind": "BinaryOp", "op": "Add", "left": ref(2), "right": ref(3)},
            "right": ref(4)}


def test_compound_operand_is_not_multiple_physical_drivers():
    graph = schematic(nested())
    nodes = {n['name']: n for n in graph['nodes'] if n['type'] == 'operator'}
    xor, add = nodes['BitwiseXor'], nodes['Add']
    inputs = [e for e in graph['edges'] if e['target'] == xor['id']]
    assert {(e['pin'], e['source']) for e in inputs} == {
        ('A', add['id']), ('B', '/::sig:c')}
    assert all(e['rendered'] for e in inputs)
    assert next(e for e in inputs if e['pin'] == 'A')['net'] == '/::expr:op:1'
    assert {(e['pin'], e['source']) for e in graph['edges'] if e['target'] == add['id']} == {
        ('A', '/::sig:a'), ('B', '/::sig:b')}
    assert 'operandStatus' not in xor
    assert any(e['source'] == xor['id'] and e['target'] == '/::sig:q' and e['rendered']
               for e in graph['edges']), 'operator Y -> register D is independent'


def test_simple_operand_keeps_its_valid_wire():
    graph = schematic({"kind": "BinaryOp", "op": "Add", "left": ref(2), "right": ref(3)})
    op = next(n for n in graph["nodes"] if n["type"] == "operator")
    inputs = [e for e in graph["edges"] if e["target"] == op["id"]]
    assert {(e["pin"], e["source"]) for e in inputs} == {("A", "/::sig:a"), ("B", "/::sig:b")}
    assert all(e["rendered"] for e in inputs)
    assert "operandStatus" not in op


def test_same_decl_in_nested_operand_does_not_create_false_collision():
    expression = {"kind": "BinaryOp", "op": "BitwiseXor",
                  "left": {"kind": "BinaryOp", "op": "Add", "left": ref(2), "right": ref(2)},
                  "right": ref(3)}
    graph = schematic(expression)
    xor, add = [n for n in graph['nodes'] if n['type'] == 'operator']
    outer_a = [e for e in graph['edges'] if e['target'] == xor['id'] and e['pin'] == 'A']
    assert len(outer_a) == 1 and outer_a[0]['source'] == add['id'] and outer_a[0]['rendered']
    inner = [e for e in graph['edges'] if e['target'] == add['id']]
    assert len(inner) == 2 and {e['pin'] for e in inner} == {'A', 'B'}
    assert all(e['source'] == '/::sig:a' and e['rendered'] for e in inner)


@pytest.mark.skipif(not shutil.which("node"), reason="Node.js required")
def test_real_elk_does_not_route_unresolved_compound_operand():
    graph = schematic(nested())
    script = r'''
const fs=require('node:fs'), assert=require('node:assert/strict');
const g=JSON.parse(fs.readFileSync(0,'utf8')), w=process.argv[1];
const G=require(w+'/symbol-geometry.js'),A=require(w+'/elk-adapter.js');
const ELK=require(w+'/elk.bundled.js').default;
(async()=>{
 const expected=g.edges.filter(e=>e.rendered!==false);
 const layout=await A.compute(new ELK(),g,G.boxSize);
 assert.equal(layout.edgePaths.size,expected.length);
 const xor=g.nodes.find(n=>n.name==='BitwiseXor'), add=g.nodes.find(n=>n.name==='Add');
 const link=g.edges.find(e=>e.source===add.id&&e.target===xor.id);
 assert(link&&link.rendered&&link.pin==='A');
 assert(layout.edgePaths.has(link.id));
 const output=g.edges.find(e=>e.source===xor.id&&e.target.endsWith('::sig:q'));
 assert(layout.edgePaths.has(output.id));
 const xy=G.absoluteAnchor(add,layout.positions.get(add.id),'source',link);
 assert.deepEqual(layout.edgePaths.get(link.id)[0],[xy.x,xy.y]);
 console.log('Nested AST operators routed independently PASS');
})().catch(e=>{console.error(e);process.exitCode=1});
'''
    completed = subprocess.run(["node", "-e", script, str(WEB)], input=json.dumps(graph),
                               text=True, capture_output=True, timeout=30)
    assert completed.returncode == 0, completed.stdout + completed.stderr
    assert "routed independently PASS" in completed.stdout


def test_indexed_operand_is_separate_ast_select_operator():
    expr = {"kind": "BinaryOp", "op": "Add", "left": {
        "kind": "ElementSelect", "value": ref(2), "selector": ref(3)}, "right": ref(4)}
    graph = schematic(expr)
    select = next(n for n in graph["nodes"] if n.get("name") == "IndexedSelect")
    add = next(n for n in graph["nodes"] if n.get("name") == "Add")
    assert {(e["source"], e["pin"]) for e in graph["edges"]
            if e["target"] == select["id"] and e["rendered"]} == {
                ("/::sig:a", "A"), ("/::sig:b", "S")}
    assert [(e["source"], e["pin"]) for e in graph["edges"]
            if e["target"] == add["id"] and e["rendered"] and e["pin"] == "A"] == [
                (select["id"], "A")]


def test_same_pin_two_distinct_explicit_nets_fails_closed():
    from flexsoc.backend.dv.rtl_viewer.connectivity import GraphEdges
    nodes = [{"id": "s1", "type": "signal"}, {"id": "s2", "type": "signal"},
             {"id": "op", "type": "operator"}]
    collector = GraphEdges("/::", nodes, {"a": {}, "b": {}})
    collector.add("s1", "op", "data", net="a", pin="A")
    collector.add("s2", "op", "data", net="b", pin="A")
    result = collector.all()
    assert len(result) == 2
    assert all(e["routingStatus"] == "unresolved_operand_multiple_nets" for e in result)
    assert all(e["rendered"] is False for e in result)


@pytest.mark.skipif(not shutil.which("node"), reason="Node.js required")
def test_canvas_draws_dynamic_indexed_select_without_unresolved_marker():
    # A dynamic select has an explicit AST-backed data+selector operation.
    expr = {"kind": "BinaryOp", "op": "Add", "left": {
        "kind": "ElementSelect", "value": ref(2), "selector": ref(3)}, "right": ref(4)}
    graph = schematic(expr)
    script = r'''
const assert=require('node:assert/strict'),fs=require('node:fs');
const w=process.argv[1],g=JSON.parse(fs.readFileSync(0,'utf8'));
const P=require(w+'/symbol-painter.js');
const op=g.nodes.find(n=>n.name==='IndexedSelect'),labels=[];
const ctx={save(){},restore(){},beginPath(){},moveTo(){},lineTo(){},stroke(){},
 roundRect(){},fill(){},closePath(){},quadraticCurveTo(){},arc(){},
 fillText(t){labels.push(String(t));},clearRect(){}};
const colors=new Proxy({}, {get:(_,key)=>'#aaa'});
P.paint(ctx,op,{x:20,y:20,w:120,h:76},{colors,picked:false,zoom:1,names:true});
assert(!labels.includes('?'),'lowered dynamic select must not appear unresolved');
console.log('DYNAMIC SELECT GLYPH PASS');
'''
    done = subprocess.run(["node", "-e", script, str(WEB)], input=json.dumps(graph),
                          text=True, capture_output=True, timeout=10)
    assert done.returncode == 0, done.stdout + done.stderr
    assert "DYNAMIC SELECT GLYPH PASS" in done.stdout
