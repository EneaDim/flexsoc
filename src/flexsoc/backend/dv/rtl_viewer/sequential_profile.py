"""Conservative, deterministic summary of Slang-derived sequential facts.

A sensitivity edge and a guarded assignment are facts; reset/enable/load
semantics are NOT implied by a signal name or by a constant RHS alone.
"""
from __future__ import annotations

VALID_EDGES = frozenset({'PosEdge', 'NegEdge'})


def summarize(timing, guards):
    events = []
    for event in timing or ():
        if not isinstance(event, dict):
            continue
        signal, edge = event.get('signal'), event.get('edge')
        if not isinstance(signal, str) or not signal or edge not in VALID_EDGES:
            continue
        fact = {'signal': signal, 'edge': edge}
        if fact not in events:
            events.append(fact)
    events.sort(key=lambda e: (e['signal'], e['edge']))
    writes = []
    gate_signals = set()
    for path in guards or ():
        if not isinstance(path, dict):
            continue
        conditions = []
        for guard in path.get('guards', ()) or ():
            if not isinstance(guard, dict):
                continue
            names = guard.get('signals', ())
            if not isinstance(names, (list, tuple)):
                names = ()
            names = sorted({name for name in names if isinstance(name, str) and name})
            branch = guard.get('branch', '')
            if branch not in ('true', 'false'):
                branch = 'unknown'
            conditions.append({'signals': names, 'branch': branch,
                               'line': guard.get('line') if isinstance(guard.get('line'), int) else 0})
            gate_signals.update(names)
        writes.append({'line': path.get('line') if isinstance(path.get('line'), int) else 0,
                       'conditions': conditions,
                       'constantCandidate': path.get('constantRhsCandidate') is True,
                       'rhsSignals': sorted({s for s in path.get('rhsSignals', ())
                                             if isinstance(s, str) and s})})
    writes.sort(key=lambda w: (w['line'], str(w['conditions']), str(w['rhsSignals'])))
    # Single event is sufficient to know event-driven storage timing, but not
    # to infer a reset, enable, or mux priority from arbitrary logic.
    kind = 'single_edge_storage' if len(events) == 1 else ('multi_event_storage' if events else 'unknown_storage')
    return {
        'kind': kind,
        'events': events,
        'writePaths': writes,
        'guardSignals': sorted(gate_signals),
        'hasConditionalWrites': any(w['conditions'] for w in writes),
        'hasConstantAssignmentCandidate': any(w['constantCandidate'] for w in writes),
        'controls': {'reset': 'unclassified', 'enable': 'unclassified',
                     'load': 'unclassified', 'priority': 'unclassified'},
        'evidence': 'Slang AST events and guarded assignment paths',
    }
