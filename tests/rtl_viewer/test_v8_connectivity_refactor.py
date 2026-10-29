"""Regression cases derived from AST semantics, not RTL identifier conventions."""
from pathlib import Path

from flexsoc.backend.dv.rtl_viewer import RtlDesign
from flexsoc.backend.dv.rtl_viewer.connectivity import GraphEdges, PortResolver, SymbolTable


def signal(name, address, kind='Variable', direction=''):
    return {'kind': kind, 'name': name, 'addr': address, 'direction': direction, 'type': 'logic[31:0]'}


def ref(addr, label='wrong_display_name'):
    return {'kind': 'NamedValue', 'symbol': f'{addr} {label}'}


def assignment(lhs, rhs):
    return {'kind': 'ContinuousAssign', 'assignment': {'kind': 'Assignment', 'left': lhs, 'right': rhs}}


def design(members, top='DUT'):
    ast = {'design': {'kind': 'Root', 'members': [
        {'kind': 'Instance', 'name': top, 'body': {'kind': 'InstanceBody', 'name': top, 'members': members}}]}}
    return RtlDesign(ast, root=Path(__file__).parent, top=top)


def test_array_index_is_not_falsely_classified_as_a_write():
    arr, addr, src = signal('vectors', 101), signal('addr', 102), signal('rhs', 103)
    lhs = {'kind': 'ElementSelect', 'value': ref(101), 'selector': ref(102)}
    symbols = SymbolTable((arr, addr, src), {'vectors', 'addr', 'rhs'})
    assert symbols.writes(lhs) == ('vectors',)
    assert symbols.address_reads(lhs) == ('addr',)
    g = design([arr, addr, src, assignment(lhs, ref(103))]).diagram()
    pairs = {(e['source'], e['target'], e['type']) for e in g['edges']}
    assert ('/::sig:rhs', '/::sig:vectors', 'data') in pairs
    assert ('/::sig:addr', '/::sig:vectors', 'address') in pairs
    assert not any(e['target'] == '/::sig:addr' for e in g['edges'])
    assert all(e['mapping'] == 'partial' for e in g['edges'])


def test_concatenated_lvalue_writes_each_leaf_only():
    members = [signal('x', 11), signal('y', 12), signal('incoming', 13)]
    lhs = {'kind': 'Concatenation', 'operands': [ref(11), ref(12)]}
    g = design([*members, assignment(lhs, ref(13))]).diagram()
    targets = {e['target'] for e in g['edges'] if e['source'] == '/::sig:incoming'}
    assert targets == {'/::sig:x', '/::sig:y'}
    assert all(e['mapping'] == 'partial' for e in g['edges'])


def test_concat_and_selector_port_connections_are_partial_not_invented_exact_bits():
    members = [signal('first', 31), signal('second', 32), signal('index', 33)]
    binding = PortResolver(members, {'first', 'second', 'index'})
    ports = {'data_i': {'direction': 'input'}}
    instance = {'body': {'members': [signal('data_i', 800, 'Port', 'In')]}, 'connections': [
        {'port': 'data_i', 'expression': {'kind': 'Concatenation', 'operands': [
            ref(31), {'kind': 'ElementSelect', 'value': ref(32), 'selector': ref(33)}]}}]}
    actuals = binding.bindings(instance, ports)
    assert {(b.signal, b.mapping) for b in actuals} == {
        ('first', 'partial'), ('second', 'partial'), ('index', 'partial')
    }
    # Unknown widths and index-dependent slices must NOT become CTRL-followable.
    assert all(b.mapping == 'partial' for b in actuals)


def test_implicit_output_assignment_expression_uses_parent_identity():
    parent = [signal('raw_result', 202)]
    consumer = {'body': {'members': [signal('output_port', 901, 'Port', 'Out')]}, 'connections': [
        {'port': 'output_port', 'expression': {'kind': 'AssignmentExpression',
         'left': ref(202), 'right': {'kind': 'NamedValue', 'symbol': '901 output_port'}}}]}
    binds = PortResolver(parent, {'raw_result'}).bindings(consumer, {'output_port': {'direction': 'Out'}})
    assert [(b.signal, b.port, b.direction, b.mapping) for b in binds] == [
        ('raw_result', 'output_port', 'out', 'direct')]


def test_internal_port_backing_declaration_wins_independent_of_ast_order():
    port = {'kind': 'Port', 'name': 'external', 'addr': 51, 'internalSymbol': '55 storage'}
    storage = signal('storage', 55)
    for members in ((port, storage), (storage, port)):
        symbols = SymbolTable(members, {'external', 'storage'})
        assert symbols.refs(ref(55, 'external')) == ('storage',)
        assert symbols.refs(ref(51, 'storage')) == ('external',)


def test_unknown_address_does_not_resolve_by_same_name():
    symbols = SymbolTable((signal('clk', 41), signal('data', 42)), {'clk', 'data'})
    assert symbols.refs(ref(999, 'data')) == ()
    assert symbols.port_actuals(ref(999, 'data')) == ()


def test_stable_unique_wire_ids_do_not_depend_on_edge_insertion_order():
    nodes = [{'id': n} for n in ('a', 'b', 'c')]
    signals = {'a': {'width': 'logic[7:0]'}, 'b': {'width': 'logic'}}
    def build(reverse):
        builder = GraphEdges('/::', nodes, signals)
        edges = [('a', 'b', 'data', 'a'), ('a', 'c', 'data', 'a')]
        for src, dst, kind, net in reversed(edges) if reverse else edges:
            builder.add(src, dst, kind, net=net)
        builder.add('a', 'b', 'data', net='a')  # duplicate AST visit
        builder.add('a', 'missing', 'data')
        return {e['target']: e['id'] for e in builder.all()}, builder
    first, b1 = build(False)
    second, _ = build(True)
    assert first == second and len(b1.all()) == 2
    assert len(set(first.values())) == 2


def test_ports_renamed_and_connections_via_expr_are_not_name_matched():
    parent = [signal('interstage_bus', 101), signal('unrelated', 102)]
    inst = {'body': {'members': [signal('input_payload', 901, 'Port', 'In')]}, 'connections': [
        {'port': {'kind': 'Port', 'name': 'input_payload', 'addr': 901},
         'expression': {'kind': 'Conversion', 'operand': ref(101, 'unrelated')}}]}
    found = PortResolver(parent, {'interstage_bus', 'unrelated'}).bindings(
        inst, {'input_payload': {'direction': 'In'}})
    assert [(b.signal, b.mapping) for b in found] == [('interstage_bus', 'partial')]


def test_unresolved_ast_connection_is_not_reported_as_physically_open():
    parent = [signal('data', 15)]
    child = {'body': {'members': [signal('consumed_i', 880, 'Port', 'In'),
                                  signal('open_i', 881, 'Port', 'In')]}, 'connections': [
        {'port': 'consumed_i', 'expression': {'kind': 'OpaqueNewSlangExpression', 'value': 42}}]}
    bindings, states = PortResolver(parent, {'data'}).resolve(
        child, {'consumed_i': {'direction': 'In'}, 'open_i': {'direction': 'In'}})
    assert bindings == ()
    assert states == {'consumed_i': 'unresolved', 'open_i': 'unbound'}


def test_generate_stack_audits_all_lanes_without_serializing_every_instance_path():
    children = []
    parent = [signal('lane_bus', 11)]
    for i in range(70):
        members = [signal('input_i', 1000+i, 'Port', 'In')]
        child = {'kind': 'Instance', 'name': 'slot',
                 'body': {'kind': 'InstanceBody', 'name': 'SomeLane', 'members': members},
                 'connections': [{'port': 'input_i', 'expression': ref(11)}] if i != 69 else
                                [{'port': 'input_i', 'expression': {'kind': 'FutureAST', 'value': 1}}]}
        children.append({'kind': 'GenerateBlock', 'name': f'par[{i}]', 'members': [child]})
    parent.append({'kind': 'GenerateBlockArray', 'name': 'par', 'members': children})
    graph = design(parent).diagram()
    group = next(n for n in graph['nodes'] if n['type'] == 'generate')
    assert group['count'] == 70
    assert len(group['instancePaths']) == 64
    assert group['ports'][0]['connection'] == 'unresolved'
    assert graph['connectivity']['unresolved_pins'] == 1


def test_dense_graph_has_explicit_edge_limit_not_a_silent_success():
    collector = GraphEdges('/::', [{'id': 'a'}, {'id': 'b'}, {'id': 'c'}], {}, max_edges=1)
    collector.add('a', 'b', 'data')
    collector.add('a', 'c', 'data')
    assert len(collector.all()) == 1
    assert collector.truncated


def test_unknown_address_fails_closed_even_when_declarations_lack_addresses():
    # Some partial serializer outputs contain declaration names but not IDs.
    # An unresolved numeric reference must never be rebound by display name.
    symbols = SymbolTable(({'kind': 'Variable', 'name': 'data'},), {'data'})
    assert symbols.reads(ref(999, 'data')) == ()
    assert symbols.port_actuals(ref(999, 'data')) == ()
    assert symbols.reads({'kind': 'NamedValue', 'symbol': {'addr': 999, 'name': 'data'}}) == ()
    # A genuinely name-only, address-free fixture remains distinguishable.
    assert symbols.reads({'kind': 'NamedValue', 'symbol': {'name': 'data'}}) == ('data',)
