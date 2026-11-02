"""Compiler-evidenced, scope-local source-to-schematic navigation.

Never infer a signal from source text or names in an expression. For a source
line, walk the elaborated AST once and associate only resolved declaration
identities with the visible graph. Different instances of the same module are
queried separately using their own scope path.
"""
from __future__ import annotations

from typing import Any

from .connectivity import REFERENCES, SymbolTable
from .model import ASSIGN_KINDS, is_instance, name_of, SIGNAL_KINDS, extract_location


def source_line_candidates(design, path: str, line: int) -> dict[str, Any]:
    if not 1 <= line <= 1_000_000:
        raise ValueError('source line outside 1..1000000')
    scope = design._scope(path)
    source = design._source_path(scope)
    if source is None:
        return {'status': 'unresolved', 'candidates': [], 'scope': path,
                'reason': 'no compiler-mapped module file'}
    signals = design._signals(scope)
    members = scope.node['body'].get('members', ())
    symbols = SymbolTable(members, set(signals))
    graph = design.diagram(path, limit=1500)
    visible_ids = {node['id'] for node in graph['nodes']}
    roles: dict[str, set[str]] = {}

    def record(node: dict, role: str) -> None:
        raw, site_line = extract_location(node)
        if site_line != line or not raw or design._resolve_source_reference(raw) != source:
            return
        name = name_of(node) if role == 'declaration' else symbols.direct(node)
        if name in signals:
            roles.setdefault(name, set()).add(role)

    for member in members:
        if isinstance(member, dict) and member.get('kind') in SIGNAL_KINDS:
            record(member, 'declaration')

    def walk(node: Any, role: str = 'read') -> None:
        if isinstance(node, (tuple, list)):
            for item in node:
                walk(item, role)
            return
        if not isinstance(node, dict):
            return
        if is_instance(node):
            # Only the parent-side actual expressions can refer to signals in
            # this scope. Never traverse the child's declarations or body.
            bindings = node.get('connections', node.get('portConnections', ()))
            if isinstance(bindings, (list, tuple)):
                for binding in bindings:
                    if not isinstance(binding, dict):
                        continue
                    formal = binding.get('port')
                    if not isinstance(formal, dict) or formal.get('kind') not in ('Port', 'InterfacePort'):
                        continue
                    direction = str(formal.get('direction') or '').lower()
                    if direction not in ('in', 'input', 'out', 'output'):
                        continue
                    actual = next((binding[k] for k in ('expr', 'expression', 'externalExpr')
                                   if isinstance(binding.get(k), dict)), None)
                    if actual is not None:
                        walk(actual, 'write' if direction in ('out', 'output') else 'read')
            return
        kind = str(node.get('kind', ''))
        if kind in ASSIGN_KINDS or ('Assignment' in kind and 'Pattern' not in kind):
            walk(node.get('left', node.get('lhs')), 'write')
            walk(node.get('right', node.get('rhs')), 'read')
            for key, value in node.items():
                if key not in ('left','lhs','right','rhs','symbol','internalSymbol') and isinstance(value, (dict, list)):
                    walk(value, 'read')
            return
        if kind in REFERENCES:
            record(node, role)
        for key, value in node.items():
            if key not in ('symbol', 'internalSymbol') and isinstance(value, (dict, list, tuple)):
                walk(value, role)

    walk(members)
    candidates = [{'id': path + '::sig:' + name, 'name': name, 'line': line,
                   'roles': sorted(roles[name]), 'visible': path + '::sig:' + name in visible_ids}
                  for name in sorted(roles)]
    visible = [candidate for candidate in candidates if candidate['visible']]
    status = ('resolved' if len(visible) == 1 else 'ambiguous' if len(visible) > 1 else
              'outside_view' if candidates else 'unresolved')
    return {'status': status, 'candidates': candidates, 'scope': path,
            'file': design._source_label(source), 'line': line,
            'graph_truncated': bool(graph.get('truncated')),
            'reason': '' if visible else ('AST signals exist but are not present in the current schematic slice'
                                      if candidates else 'no compiler-backed signal reference on this line')}
