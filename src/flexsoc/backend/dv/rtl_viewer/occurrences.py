"""AST-evidenced read/write locations; no source-text identity guessing."""
from __future__ import annotations
from typing import Any

from .connectivity import SymbolTable, REFERENCES
from .model import ASSIGN_KINDS, SIGNAL_KINDS, extract_location, objects, name_of, is_instance


def occurrences(design, path: str, signal: str) -> dict[str, Any]:
    scope = design._scope(path)
    signals = design._signals(scope)
    if signal not in signals:
        raise ValueError('unknown signal in selected scope')
    source = design._source_path(scope)
    if source is None:
        return {'status': 'unresolved', 'signal': signal, 'path': path, 'sites': [], 'reason': 'module source is not project-local'}
    members = scope.node['body'].get('members', ())
    symbols = SymbolTable(members, set(signals))
    target_file = source.resolve()
    sites: list[dict[str, Any]] = []
    seen: set[tuple[str, int, str]] = set()
    def record(node: dict, role: str) -> None:
        file, line = extract_location(node)
        if not file or line <= 0:
            return
        # Reuse the same authorized-root resolver as design.source() and
        # source_symbols(): imported ASTs often name checkout-relative files
        # while design.root points at workspace/runs/<ip>/<run>.
        resolved = design._resolve_source_reference(file)
        if resolved != target_file:
            return
        key = (role, line, file)
        if key not in seen:
            seen.add(key)
            sites.append({'role': role, 'file': design._source_label(target_file),
                          'line': line, 'column': None, 'precision': 'line', 'evidence': 'slang-ast'})
    for member in members:
        if not isinstance(member, dict):
            continue
        if member.get('kind') in SIGNAL_KINDS and name_of(member) == signal:
            record(member, 'declaration')

    def references(node: Any):
        for entry in objects(node):
            if entry.get('kind') in REFERENCES and symbols.direct(entry) == signal:
                yield entry

    def walk(node: Any):
        if isinstance(node, list):
            for item in node:
                walk(item)
            return
        if not isinstance(node, dict) or is_instance(node):
            return
        kind = str(node.get('kind', ''))
        if kind in ASSIGN_KINDS or ('Assignment' in kind and 'Pattern' not in kind):
            lhs = node.get('left', node.get('lhs'))
            rhs = node.get('right', node.get('rhs'))
            if lhs is not None and rhs is not None:
                # Track exact reference-node locations, not parent assignment lines.
                if signal in symbols.writes(lhs):
                    for ref in references(lhs):
                        record(ref, 'write')
                for ref in references(rhs):
                    record(ref, 'read')
                # Dynamic indices of lvalues are reads, not writes.
                if signal in symbols.address_reads(lhs):
                    for key in ('selector','index','range','selection'):
                        for ref in references(lhs.get(key)):
                            record(ref, 'read')
                return
        # Declarations are handled separately; their initializer may read refs.
        for key, value in node.items():
            if isinstance(value, (dict, list)) and key not in ('symbol', 'internalSymbol'):
                walk(value)
        # Non-assignment reference sites are reads, including conditions.
        if kind in REFERENCES and symbols.direct(node) == signal:
            record(node, 'read')

    walk(members)
    # Elaborated instance connections are genuine uses of parent-scope
    # declarations. They are outside the instance body and the regular walk
    # deliberately skips instances to avoid traversing child declarations.
    # Attribute direction only when Slang supplies the formal Port's
    # direction and the actual expression contains a resolved parent ref.
    for instance in members:
        if not isinstance(instance, dict) or not is_instance(instance):
            continue
        bindings = instance.get('connections', instance.get('portConnections', ()))
        if not isinstance(bindings, (list, tuple)):
            continue
        for binding in bindings:
            if not isinstance(binding, dict):
                continue
            formal = binding.get('port')
            if not isinstance(formal, dict) or formal.get('kind') not in ('Port', 'InterfacePort'):
                continue
            direction = str(formal.get('direction', '')).lower()
            if direction not in ('in', 'input', 'out', 'output'):
                continue
            actual = next((binding[k] for k in ('expr', 'expression', 'externalExpr')
                           if isinstance(binding.get(k), dict)), None)
            if actual is None:
                continue
            role = 'read' if direction in ('in', 'input') else 'write'
            if role == 'write' and actual.get('kind') in ASSIGN_KINDS:
                actual = actual.get('left', actual.get('lhs'))
            for ref in references(actual):
                record(ref, role)

    sites.sort(key=lambda s: (s['file'], s['line'], {'declaration':0,'write':1,'read':2}[s['role']]))
    return {'status': 'available', 'path': path, 'module': scope.module, 'signal': signal,
            'sites': sites, 'precision': 'line', 'complete': False,
            'note': 'Only AST references with source lines are shown; missing sites are not inferred.'}
