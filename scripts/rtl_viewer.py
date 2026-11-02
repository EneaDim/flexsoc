#!/usr/bin/env python3
"""Run a Slang-backed RTL schematic explorer on localhost.

Usage: python scripts/rtl_viewer.py --root examples/rtl_schematic_dsp --top DSP \
 --file DSP.sv --file DSP_core.sv --file DSP_lane.sv
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path
import sys
import tempfile

# Run without editable pip install; also works from relocated repositories.
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "src"))
from flexsoc.backend.dv.rtl_viewer import RtlDesign, SlangProject  # noqa: E402
from flexsoc.backend.dv.rtl_viewer.server import ViewerServer  # noqa: E402
from flexsoc.run_select import select_run  # noqa: E402


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        description="FlexSoC RTL Explorer — Slang elaboration → scoped graph → interactive schematic",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--run-dir", type=Path, help="existing workspace/runs/<top>/<run-id> directory; auto-select AST, root, top and run")
    parser.add_argument("--root", type=Path, help="project root; sources are resolved under it")
    parser.add_argument("--source-root", type=Path, action="append", default=[],
                        help="additional trusted directory for compiler-proven source files (repeatable)")
    parser.add_argument("--top", help="Slang elaboration top module")
    parser.add_argument("--file", type=Path, action="append", default=[], help="source file relative to root (repeatable)")
    parser.add_argument("--filelist", type=Path, action="append", default=[], help="Slang -F filelist under root (repeatable)")
    parser.add_argument("--include", type=Path, action="append", default=[], help="Slang include directory under root")
    parser.add_argument("--define", action="append", default=[], help="Slang preprocessor definition, e.g. USE_DSP=1")
    parser.add_argument("--slang", default="slang", help="Slang executable")
    parser.add_argument("--expand-cached-instances", action="store_true",
                        help="disable slang instance-body caching (slow; only if repeated bodies are missing)")
    parser.add_argument("--ast", type=Path, help="existing Slang --ast-json file; skips compilation")
    parser.add_argument("--run", type=Path, help="optional FlexSoC run for lint diagnostics")
    parser.add_argument('--enable-neovim', action='store_true',
                        help='opt-in: run native Neovim in the inspector (localhost only; executes user Neovim config)')
    parser.add_argument("--port", type=int, default=8765, help="HTTP port (0 chooses a free port)")
    parser.add_argument("--listen", default="127.0.0.1", choices=("127.0.0.1", "0.0.0.0"),
                        help="bind address; localhost by default")
    parser.add_argument("--allow-remote", action="store_true",
                        help="required to bind outside localhost (e.g. Docker, exposes RTL without auth)")
    parser.add_argument("--check", action="store_true", help="compile and audit every elaborated scope, without starting server")
    parser.add_argument("--strict", action="store_true", help="with --check, fail if any RTL source or port is unresolved, or graph is truncated")
    parser.add_argument("--report", type=Path, help="with --check, save full structured audit JSON to this path")
    args = parser.parse_args(argv)
    if args.run_dir:
        try:
            _, identity = select_run(args.run_dir)
        except (OSError, ValueError) as exc:
            parser.error(str(exc))
        run = args.run_dir.expanduser().resolve()
        if args.root and args.root.resolve() != run:
            parser.error("--root conflicts with --run-dir")
        if args.run and args.run.resolve() != run:
            parser.error("--run conflicts with --run-dir")
        if args.top and args.top != identity["TOP"]:
            parser.error("--top conflicts with --run-dir; use explicit --root/--top for a different top")
        if args.file or args.filelist or args.include or args.define:
            parser.error("--run-dir loads the existing AST; source compilation options require --root/--top")
        ast = run / "dv" / "slang_hier" / "ast.json"
        if not ast.is_file():
            parser.error(f"run has no Slang AST: {ast}")
        if args.ast and args.ast.resolve() != ast:
            parser.error("--ast conflicts with --run-dir")
        args.root, args.run, args.top, args.ast = run, run, identity["TOP"], ast
    elif args.root is None or not args.top:
        parser.error("--root and --top are required unless --run-dir is used")
    if args.enable_neovim and args.listen != '127.0.0.1':
        parser.error('--enable-neovim requires --listen 127.0.0.1')
    if args.listen != "127.0.0.1" and not args.allow_remote:
        parser.error("--allow-remote is required when binding outside localhost: RTL code is private")
    try:
        if args.ast:
            payload = json.loads(args.ast.read_text(encoding="utf-8"))
        else:
            project = SlangProject(args.root, args.top, tuple(args.file), tuple(args.filelist),
                                   tuple(args.include), tuple(args.define), args.slang, args.expand_cached_instances)
            with tempfile.TemporaryDirectory(prefix="flexsoc-slang-") as tmp:
                payload = json.loads(project.compile(Path(tmp) / "ast.json").read_text(encoding="utf-8"))
        # Existing run RTL lives under the run directory; shared sources live
        # under the FlexSoC checkout. Restrict automatic access to runs inside
        # this checkout. External source trees require --source-root explicitly.
        checkout = Path(__file__).resolve().parents[1]
        extra_roots = list(args.source_root)
        if args.run_dir and args.root.resolve().is_relative_to(checkout):
            extra_roots.append(checkout)
        design = RtlDesign(payload, root=args.root, top=args.top, run=args.run,
                           verified=not bool(args.ast), source_roots=tuple(extra_roots))
        if args.check:
            report = design.audit()
            if args.report:
                args.report.parent.mkdir(parents=True, exist_ok=True)
                args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
            print(json.dumps({"top": report["top"], "elaboration_verified": report["elaboration_verified"],
                              "scopes": len(report["scopes"]), "totals": report["totals"],
                              "qualified": report["qualified"], "report": str(args.report or "")}, indent=2))
            return 0 if not args.strict or report["qualified"] else 3
        with ViewerServer((args.listen, args.port), design, enable_neovim=args.enable_neovim) as server:
            print(f"FlexSoC RTL Explorer: http://127.0.0.1:{server.server_port}", flush=True)
            print(f"Top: {design.top} | Slang elaborated scopes: {len(design.scopes)}", flush=True)
            try:
                server.serve_forever()
            except KeyboardInterrupt:
                pass
        return 0
    except (RuntimeError, ValueError, FileNotFoundError, json.JSONDecodeError) as exc:
        print(f"RTL Explorer: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
