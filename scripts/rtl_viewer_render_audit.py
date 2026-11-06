#!/usr/bin/env python3
"""Audit *display correctness* of the RTL Viewer across elaborated scopes.

Checks stable edge identities, pins, group input/output ownership, process
boundary projections, focused/flattened navigation, and optional real ELK
routes against the same Canvas anchors. It is NOT an equivalence checker and
must not be used as a claim that arbitrary SystemVerilog is synthesized.
"""
from __future__ import annotations

import argparse
from collections import Counter
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / 'src'
sys.path.insert(0, str(SRC))
from flexsoc.backend.dv.rtl_viewer import RtlDesign  # noqa: E402
from flexsoc.backend.dv.rtl_viewer.semantic_contracts import audit_scope_semantics  # noqa: E402


def ast_kind_inventory(value, counter):
    if isinstance(value, dict):
        kind = value.get('kind')
        if isinstance(kind, str):
            counter[kind] += 1
        for child in value.values():
            if isinstance(child, (dict, list)):
                ast_kind_inventory(child, counter)
    elif isinstance(value, list):
        for child in value:
            ast_kind_inventory(child, counter)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ast', type=Path, required=True, help='Slang elaborated AST JSON')
    parser.add_argument('--top', required=True)
    parser.add_argument('--scope', action='append', default=[], help='Exact elaborated scope (default: all)')
    parser.add_argument('--limit', type=int, default=800, help='Schematic node limit (1..1500)')
    parser.add_argument('--elk-scope', action='append', default=[], help='Run real ELK/Canvas endpoint audit on this scope')
    parser.add_argument('--report', type=Path, required=True)
    parser.add_argument('--strict-coverage', action='store_true',
                        help='Also fail if supported compiler values are not represented (semantic warnings)')
    args = parser.parse_args()
    if not args.ast.is_file():
        parser.error(f'AST not found: {args.ast}')
    if not 1 <= args.limit <= 1500:
        parser.error('limit must be 1..1500')
    if not shutil.which('node'):
        parser.error('Node.js is required to verify frontend projections')
    design = RtlDesign(json.loads(args.ast.read_text()), root=ROOT, top=args.top)
    paths = sorted(args.scope or list(design.scopes))
    for path in paths + args.elk_scope:
        if path not in design.scopes:
            parser.error(f'Unknown elaborated scope: {path}')
    if any(path not in paths for path in args.elk_scope):
        parser.error('--elk-scope must also be among selected --scope values')
    graphs = []
    counts = Counter()
    semantic_checks = []
    for path in paths:
        graph = design.diagram(path, limit=args.limit)
        scope = design.scopes[path]
        semantic_checks.append({"scope": path, **audit_scope_semantics(
            list(scope.node.get('body', {}).get('members', ())),
            set(design._signals(scope)), graph, design.subroutines)})
        # Verify both compiler-scope and virtual FSM projections, including
        # the dedicated interior. Also cover actual expanded generate nodes.
        fsm = design.diagram(path, limit=args.limit, fsm_view=True)
        fsm_groups = fsm.get('fsmGroups', [])
        fsm_expanded = [design.diagram(path, limit=args.limit, fsm_view=True,
                                      expanded=(group['token'],)) for group in fsm_groups]
        exploded = design.diagram(path, limit=args.limit, explode=True) if any(
            node.get('type') == 'generate' for node in graph['nodes']) else None
        graphs.append({'scope': path, 'graph': graph,
                       'fsmGraph': fsm if fsm_groups else None,
                       'fsmExpanded': fsm_expanded,
                       'exploded': exploded})
        counts['nodes'] += len(graph['nodes'])
        counts['edges'] += len(graph['edges'])
        counts['not_rendered'] += sum(e.get('rendered') is False for e in graph['edges'])
    kinds = Counter()
    for path in paths:
        # AST kind counts describe encountered language constructs; they are
        # NOT a claim of successful electrical lowering for each construct.
        ast_kind_inventory(design.scopes[path].node.get('body', {}), kinds)
    with tempfile.TemporaryDirectory(prefix='rtl_render_audit_') as temp:
        input_file = Path(temp) / 'graphs.json'
        output_file = Path(temp) / 'result.json'
        input_file.write_text(json.dumps({'graphs': graphs, 'layoutScopes': args.elk_scope}))
        node_script = ROOT / 'scripts/rtl_viewer_render_check.js'
        p = subprocess.run(['node', str(node_script), str(input_file), str(output_file)],
                           cwd=ROOT, text=True, capture_output=True, timeout=240)
        if p.returncode not in (0, 1) or not output_file.is_file():
            print(p.stdout + p.stderr, file=sys.stderr)
            return 2
        result = json.loads(output_file.read_text())
    result['semanticChecks'] = semantic_checks
    semantic_errors = sum(len(v['errors']) for v in semantic_checks)
    semantic_warnings = sum(len(v['warnings']) for v in semantic_checks)
    result['summary']['semanticErrors'] = semantic_errors
    result['summary']['semanticWarnings'] = semantic_warnings
    result['summary']['functionCalls'] = sum(v['functionCalls'] for v in semantic_checks)
    result['summary']['functionCallsRepresented'] = sum(v['functionCallsRepresented'] for v in semantic_checks)
    result['summary']['aggregateValues'] = sum(v['aggregateValues'] for v in semantic_checks)
    result['summary']['aggregateValuesRepresented'] = sum(v['aggregateValuesRepresented'] for v in semantic_checks)
    result['summary']['errors'] += semantic_errors
    result['summary']['warnings'] += semantic_warnings
    result['top'] = args.top
    result['ast'] = str(args.ast)
    result['limit'] = args.limit
    result['counts'] = dict(sorted(counts.items()))
    result['astKinds'] = dict(sorted(kinds.items()))
    result['qualification'] = ('Structural rendering contracts only; warnings include partial AST '
                              'dependencies and are not electrical-driver conflicts. '
                              'Does not prove four-state RTL equivalence or all SV language coverage.')
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2) + '\n')
    s = result['summary']
    print(f"Render contract audit: scopes={s['scopes']} views={s['views']} "
          f"errors={s['errors']} warnings={s['warnings']} ELK={s['layoutScopes']}")
    print('Report:', args.report)
    print(f"Semantic coverage: functions={s['functionCallsRepresented']}/{s['functionCalls']} "
          f"ordered aggregates={s['aggregateValuesRepresented']}/{s['aggregateValues']} "
          f"semantic errors={semantic_errors}, gaps={semantic_warnings}")
    if s['errors']:
        print('FAIL: structural or semantic contracts violated (see report)')
        return 1
    if args.strict_coverage and semantic_warnings:
        print('FAIL: strict semantic coverage has unresolved cases (see report)')
        return 1
    print('PASS: checked contracts; unresolved coverage is reported, not silently accepted')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
