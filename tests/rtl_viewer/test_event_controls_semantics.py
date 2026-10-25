"""Sequential event controls are electrical dependencies, not data operands."""
from pathlib import Path
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign


def test_explicit_event_controls_connect_to_written_registers():
    members = [
        {'kind': 'Port', 'name': 'clock', 'addr': 101, 'direction': 'In'},
        {'kind': 'Port', 'name': 'reset', 'addr': 102, 'direction': 'In'},
        {'kind': 'Variable', 'name': 'state', 'addr': 103},
        {'kind': 'Variable', 'name': 'data', 'addr': 104},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF', 'body': {
            'kind': 'Timed', 'timing': {'kind': 'EventList', 'events': [
                {'kind': 'SignalEvent', 'edge': 'PosEdge', 'expr': {'kind': 'NamedValue', 'symbol': '101 clock'}},
                {'kind': 'SignalEvent', 'edge': 'NegEdge', 'expr': {'kind': 'NamedValue', 'symbol': '102 reset'}},
            ]}, 'stmt': {'kind': 'Assignment',
                        'left': {'kind': 'NamedValue', 'symbol': '103 state'},
                        'right': {'kind': 'NamedValue', 'symbol': '104 data'}}}},
    ]
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'top', 'body': {'name': 'top', 'members': members}}]}}
    graph = RtlDesign(ast, root=Path(__file__).parent, top='top').diagram()
    events = {(e['source'], e['target'], e['type']) for e in graph['edges'] if e['type'] == 'event'}
    assert events == {('/::sig:clock', '/::sig:state', 'event'),
                      ('/::sig:reset', '/::sig:state', 'event')}
    assert not any(e['target'] == '/::sig:data' and e['type'] == 'event' for e in graph['edges'])


def test_unresolved_event_does_not_guess_signal_by_spelling():
    members = [
        {'kind': 'Port', 'name': 'clk', 'addr': 101, 'direction': 'In'},
        {'kind': 'Variable', 'name': 'state', 'addr': 103},
        {'kind': 'ProceduralBlock', 'procedureKind': 'AlwaysFF', 'body': {
            'kind': 'Timed', 'timing': {'kind': 'SignalEvent', 'edge': 'PosEdge',
                'expr': {'kind': 'NamedValue', 'symbol': '999 clk'}},
            'stmt': {'kind': 'Assignment', 'left': {'kind': 'NamedValue', 'symbol': '103 state'},
                     'right': {'kind': 'NamedValue', 'symbol': '103 state'}}}},
    ]
    ast = {'design': {'members': [{'kind': 'Instance', 'name': 'top', 'body': {'name': 'top', 'members': members}}]}}
    graph = RtlDesign(ast, root=Path(__file__).parent, top='top').diagram()
    assert not any(e['type'] == 'event' for e in graph['edges'])
