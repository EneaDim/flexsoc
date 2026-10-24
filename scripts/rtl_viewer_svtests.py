#!/usr/bin/env python3
"""Audit ALL sv-tests cases using Slang elaboration and FlexSoC's AST graph.

The corpus is *not* a set of schematic goldens: some tests are negative, have
no top, or depend on generated wrappers. These are reported, never counted as
rendering PASS. This harness parses ONLY sv-tests comment metadata, never RTL.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass
import json
from pathlib import Path
import re
import textwrap
import shutil
import subprocess
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'src'))
from flexsoc.backend.dv.rtl_viewer.model import RtlDesign, is_instance, name_of


@dataclass(frozen=True)
class Case:
    source: Path
    chapter: str
    metadata: dict

    @property
    def label(self):
        return str(self.source)


def read_metadata(source: Path) -> dict:
    """sv-tests' YAML is in the leading comment, never interpreted as SV."""
    try:
        import yaml
    except ImportError as exc:
        raise RuntimeError('Install PyYAML to parse sv-tests metadata') from exc
    snippet=source.read_text(encoding='utf-8', errors='replace')[:14000].lstrip('\ufeff\n\r ')
    if snippet.startswith('/*'):
        end=snippet.find('*/')
        if end < 0:
            return {}
        header=snippet[2:end]
    elif snippet.startswith('//'):
        lines=[]
        for line in snippet.splitlines():
            if not line.lstrip().startswith('//'):
                break
            lines.append(line.lstrip()[2:])
        header='\n'.join(lines)
    else:
        return {}
    # Remove decorative block-comment stars without destroying YAML list indent.
    header=textwrap.dedent('\n'.join(re.sub(r'^\s*\* ?', '', line) for line in header.splitlines()))
    try:
        data=yaml.safe_load(header)
    except yaml.YAMLError:
        return {}
    return {str(k).lstrip(':'):v for k,v in data.items()} if isinstance(data,dict) else {}


def cases_at(suite: Path) -> list[Case]:
    tests=(suite/'tests').resolve()
    if not tests.is_dir():
        raise FileNotFoundError(f'Expected sv-tests/tests at {tests}')
    cases=[]
    for source in sorted(p for p in tests.rglob('*') if p.is_file() and p.suffix in ('.sv', '.v')):
        if source.name.startswith('.'):
            continue
        metadata=read_metadata(source)
        if 'name' not in metadata:
            continue  # source dependency, not necessarily an independent test
        cases.append(Case(source,source.parent.relative_to(tests).parts[0],metadata))
    return cases


def check_case(case: Case, suite: Path, slang: str, timeout: int, *, layout: bool = True) -> dict:
    info={'case':case.source.relative_to(suite).as_posix(), 'chapter':case.chapter,
          'name':case.metadata.get('name'), 'tags':case.metadata.get('tags', [])}
    meta=case.metadata
    if meta.get('should_fail_because'):
        return {**info,'status':'negative_expected', 'reason':str(meta['should_fail_because'])[:160]}
    sources=meta.get('files') or [case.source.name]
    if isinstance(sources,str): sources=[sources]
    defines=meta.get('defines') or []
    incdirs=meta.get('incdirs') or []
    if isinstance(defines,str):defines=[defines]
    if isinstance(incdirs,str):incdirs=[incdirs]
    if not isinstance(sources,list) or not all(isinstance(x,str) for x in sources):
        return {**info,'status':'unsupported_metadata','reason':'invalid files metadata'}
    try:
        args=[slang,'--ast-json-source-info']
        for definition in defines:args.append('-D'+str(definition))
        for include in incdirs:args.extend(['-I',str((suite/include).resolve())])
        for item in sources:
            candidate=(case.source.parent/item).resolve()
            if not candidate.is_file():candidate=(suite/item).resolve()
            if not candidate.is_relative_to(suite.resolve()) or not candidate.is_file():
                raise FileNotFoundError(item)
            args.append(str(candidate))
        with tempfile.TemporaryDirectory(prefix='svtests-rtl-') as temp:
            ast=Path(temp)/'ast.json'
            args[1:1]=['--ast-json',str(ast)]
            top=meta.get('top_module')
            if top:args[1:1]=['--top',str(top)]
            result=subprocess.run(args,cwd=suite,capture_output=True,text=True,timeout=timeout)
            if result.returncode or not ast.is_file():
                return {**info,'status':'slang_failed','reason':(result.stderr or result.stdout)[-400:]}
            data=json.loads(ast.read_text())
            roots=[name_of(m) for m in data.get('design',{}).get('members',[])
                   if isinstance(m,dict) and is_instance(m)]
            if top:roots=[str(top)]
            if not roots:return {**info,'status':'no_elaborated_top'}
            if len(roots)>8:return {**info,'status':'multiple_tops','top_count':len(roots)}
            total_nodes=total_edges=total_scopes=total_unresolved=total_partial=0
            diagrams=[]
            for root in roots:
                design=RtlDesign(data,root=suite,top=root,verified=True)
                total_scopes+=len(design.scopes)
                for scope in design.scopes:
                    graph=design.diagram(scope,limit=1500)
                    if graph['truncated']:
                        return {**info,'status':'graph_truncated','top':root,'scope':scope}
                    nodes={n['id'] for n in graph['nodes']}
                    if any(e['source'] not in nodes or e['target'] not in nodes for e in graph['edges']):
                        return {**info,'status':'graph_invalid','top':root,'scope':scope}
                    total_nodes+=len(nodes);total_edges+=len(graph['edges'])
                    total_unresolved+=graph.get('connectivity',{}).get('unresolved_pins',0)
                    total_partial+=graph.get('connectivity',{}).get('partial_pins',0)
                    if layout:diagrams.append(graph)
            result={**info,'status':'graph_unresolved' if total_unresolved else 'graph_pass', 'tops':roots,
                    'scopes':total_scopes,'nodes':total_nodes,'edges':total_edges,
                    'unresolved_pins':total_unresolved,'partial_pins':total_partial}
            if not layout:return result
            if len(diagrams)>512:
                return {**result,'status':'layout_partial','reason':'more than 512 elaborated scopes (layout audit bounded)'}
            node=shutil.which('node')
            if not node:return {**result,'status':'layout_not_run','reason':'Node.js executable not available'}
            script=Path(__file__).with_name('rtl_viewer_layout_audit.js')
            measured=subprocess.run([node,str(script)],input=json.dumps(diagrams),capture_output=True,text=True,timeout=timeout)
            if measured.returncode:
                return {**result,'status':'layout_error','reason':measured.stderr[-500:]}
            layout_result=json.loads(measured.stdout)
            visual_status = layout_result['status']
            if total_unresolved and visual_status == 'layout_pass':
                visual_status = 'layout_semantic_partial'
            return {**result,'status':visual_status,
                    'layout_scopes':layout_result['scopes'],
                    'layout_metrics':layout_result['items'][:32],
                    'layout_failures':[x for x in layout_result['items'] if x['status']!='layout_pass'][:32]}
    except subprocess.TimeoutExpired:
        return {**info,'status':'timeout','reason':f'>{timeout}s'}
    except (ValueError,KeyError,RuntimeError,FileNotFoundError,TypeError) as exc:
        return {**info,'status':'unsupported_or_error','reason':str(exc)[:400]}


def report(items: list[dict], suite: Path, *, inventory: bool) -> dict:
    statuses=Counter(item['status'] for item in items)
    chapters=defaultdict(Counter)
    for item in items:chapters[item['chapter']][item['status']]+=1
    return {'schema':'flexsoc.svtests.viewer.v1','source':str(suite.resolve()),
            'mode':'inventory' if inventory else 'slang_ast_layout',
            'total':len(items),'statuses':dict(statuses),
            'chapters':{k:dict(v) for k,v in sorted(chapters.items())},'cases':items,
            'note':'layout_pass checks routed geometry and resolved pin semantics, NOT screenshot similarity or bit-accurate net equivalence; unresolved ports are reported separately.'}


def main(argv=None):
    parser=argparse.ArgumentParser(description='sv-tests → Slang AST → FlexSoC schematic graph audit')
    parser.add_argument('--suite',type=Path,required=True,help='Local checkout of chipsalliance/sv-tests')
    parser.add_argument('--out',type=Path,required=True,help='JSON results path')
    parser.add_argument('--slang',default='slang')
    parser.add_argument('--jobs',type=int,default=4)
    parser.add_argument('--timeout',type=int,default=30)
    parser.add_argument('--max-tests',type=int,default=0,help='Debug limit only; 0 scans all discovered tests')
    parser.add_argument('--inventory',action='store_true',help='Discover tests without claiming compilation/rendering')
    parser.add_argument('--no-layout',action='store_true',help='Run Slang and AST graph checks, but skip JS geometry validation')
    args=parser.parse_args(argv)
    if args.jobs<1 or args.timeout<1:parser.error('--jobs and --timeout must be positive')
    if not args.inventory and not shutil.which(args.slang):parser.error('Slang not in PATH (use --inventory or install slang)')
    try:discovered=cases_at(args.suite.resolve())
    except (RuntimeError,FileNotFoundError) as exc:parser.error(str(exc))
    suite=args.suite.resolve()
    selected=discovered[:args.max_tests] if args.max_tests else discovered
    if args.inventory:
        items=[{'case':c.source.relative_to(suite).as_posix(),'chapter':c.chapter,'name':c.metadata.get('name'),
                'tags':c.metadata.get('tags',[]),'status':'not_run'} for c in selected]
    else:
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            items=list(pool.map(lambda c:check_case(c,suite,args.slang,args.timeout,layout=not args.no_layout),selected))
    result=report(items,suite,inventory=args.inventory)
    result['discovered']=len(discovered)
    result['complete_inventory']=len(selected)==len(discovered)
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    print('sv-tests:',len(selected),'/',len(discovered),'cases;',' '.join(f'{k}={v}' for k,v in result['statuses'].items()))
    print('Report:',args.out)
    return 0 if args.inventory or not any(v in result['statuses'] for v in ('graph_invalid',)) else 1


if __name__=='__main__':raise SystemExit(main())
