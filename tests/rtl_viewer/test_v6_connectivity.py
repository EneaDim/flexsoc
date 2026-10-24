"""Port ownership, directional assignment chains, typed operators (AST-only)."""
from pathlib import Path
from flexsoc.backend.dv.rtl_viewer import RtlDesign


def sig(name, addr, *, kind='Variable', direction=''):
    return {'kind': kind, 'name': name, 'addr': addr, 'type': 'logic[7:0]', 'direction': direction}


def ref(address, misleading_name):
    return {'kind': 'NamedValue', 'symbol': f'{address} {misleading_name}'}


def assign(left, right):
    return {'kind': 'ContinuousAssign', 'assignment': {'kind': 'Assignment', 'left': left, 'right': right}}


def instance(name, ports, connections):
    return {'kind': 'Instance', 'name': name, 'body': {'kind': 'InstanceBody', 'name': name+'_type', 'members': ports},
            'connections': connections}


def graph():
    source = instance('u_producer', [sig('tx_word_o', 7001, kind='Port', direction='Out')],
                      [{'port': 'tx_word_o', 'expression': ref(102, 'WRONG_DISPLAY_NAME')}])
    consumer = instance('u_consumer', [sig('operand_i', 8001, kind='Port', direction='In')],
                        [{'port': 'operand_i', 'expression': ref(103, 'SHOULD_NOT_BE_USED')}])
    fake = instance('u_unconnected', [sig('middle_bus', 9001, kind='Port', direction='In')], [])
    parent = [sig('middle_bus', 102), sig('temporary_bus', 103), sig('ctrl', 104),
              sig('accum', 105), sig('filtered', 106),
              source, consumer, fake,
              assign(ref(103, 'alias'), ref(102, 'alias')),
              assign(ref(106, 'other'), {'kind':'ConditionalOp','conditions':[ref(104,'control')],
                                         'left':ref(103,'old'),'right':ref(102,'new')}),
              {'kind':'ProceduralBlock','procedureKind':'AlwaysFF', 'body':{
                 'kind':'Block','statements':[{'kind':'ExpressionStatement','expr':{
                     'kind':'Assignment','left':ref(105,'accum'), 'right':{
                         'kind':'BinaryOp', 'op':'Add','left':ref(105,'accum'),
                         'right':ref(103,'temporary')}}}]}}]
    ast = {'design':{'kind':'Root','members':[{'kind':'Instance','name':'ROOT',
        'body':{'kind':'InstanceBody','name':'ROOT','members':parent}}]}}
    return RtlDesign(ast, root=Path(__file__).resolve().parent, top='ROOT')


def test_proven_port_bindings_and_chained_assignments():
    design = graph()
    diagram = design.diagram()
    edges = {(e['source'],e['target'],e['type'],e['port']) for e in diagram['edges']}
    assert ('/::inst:/u_producer','/::sig:middle_bus','port_out','tx_word_o') in edges
    assert ('/::sig:middle_bus','/::sig:temporary_bus','data','') in edges
    assert ('/::sig:temporary_bus','/::inst:/u_consumer','port_in','operand_i') in edges
    assert not any(e['port']=='middle_bus' for e in diagram['edges'])
    assert design.follow('/', '/u_consumer', '/::sig:temporary_bus')['signal_id']=='/u_consumer::sig:operand_i'
    assert design.cone('/', '/::inst:/u_producer', '/::inst:/u_consumer')['status']=='resolved'


def test_counter_mux_and_stable_symbol_identity():
    diagram = graph().diagram()
    nodes = {n['name']:n for n in diagram['nodes']}
    assert nodes['accum']['type']=='counter'
    assert any(n['type']=='operator' and n['shape']=='mux' for n in diagram['nodes'])
    assert any(n['type']=='operator' and n['shape']=='arith' for n in diagram['nodes'])
    assert graph().diagram()==diagram


def test_unknown_symbol_identity_fails_closed():
    design = graph()
    parent = design.scopes['/'].node['body']['members']
    producer = next(n for n in parent if n.get('name')=='u_producer')
    producer['connections'][0]['expression']['symbol']='987654 middle_bus'
    # Addresses win over labels; never connect a different declaration by spelling.
    design._diagrams.clear()
    assert not any(e['source']=='/::inst:/u_producer' for e in design.diagram()['edges'])


def test_port_to_differently_named_backing_signal_identity():
    top = {'kind':'Instance','name':'ROOT','body':{'kind':'InstanceBody','name':'ROOT','members':[
        {'kind':'Port','name':'external_i','direction':'In','internalSymbol':'9904 internal_value'},
        sig('internal_value',9904),
        {'kind':'Port','name':'outside_o','direction':'Out','internalSymbol':'9905 response'},
        sig('response',9905),
        assign(ref(9905,'wrong'),ref(9904,'wrong'))]}}
    ast={'design':{'kind':'Root','members':[top]}}
    g=RtlDesign(ast,root=Path(__file__).resolve().parent,top='ROOT').diagram()
    paths={(e['source'],e['target']) for e in g['edges']}
    assert ('/::sig:external_i','/::sig:internal_value') in paths
    assert ('/::sig:internal_value','/::sig:response') in paths
    assert ('/::sig:response','/::sig:outside_o') in paths


def test_explicit_enum_case_is_fsm_candidate_not_filename_heuristic():
    members = [sig('chooser', 151),
               {'kind':'Variable','name':'state_reg','addr':152,'type':{'kind':'EnumType','text':'enum state_t'}},
               {'kind':'ProceduralBlock','procedureKind':'AlwaysFF', 'body':{
                    'kind':'Block','statements':[{'kind':'Assignment','left':ref(152,'state_reg'), 'right':ref(151,'chooser')}]}},
               {'kind':'CaseStatement','expr':ref(152,'state_reg'),'items':[
                    {'kind':'CaseItem','body':{'kind':'Assignment','left':ref(152,'state_reg'), 'right':ref(151,'chooser')}}]}]
    root={'design':{'kind':'Root','members':[{'kind':'Instance','name':'UNIT',
          'body':{'kind':'InstanceBody','name':'UNIT','members':members}}]}}
    g=RtlDesign(root,root=Path(__file__).resolve().parent,top='UNIT').diagram()
    assert next(n for n in g['nodes'] if n['name']=='state_reg')['type']=='fsm'
    assert next(n for n in g['nodes'] if n['name']=='state_reg')['classification']=='candidate'
    assert any(n.get('shape')=='case' for n in g['nodes'])
