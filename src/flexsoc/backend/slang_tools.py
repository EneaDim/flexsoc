"""Slang-backed SystemVerilog analysis and filelist helpers.

The helpers start from one explicit top source and let Slang resolve the
reachable hierarchy through recursive library search roots. Filelists can be
emitted either as one portable command file or as FlexSoC's canonical
``rtl_common.f`` / ``rtl_ip.f`` pair.
"""
from __future__ import annotations

import argparse
import re
import shlex
import shutil
import subprocess
from pathlib import Path

MODULE_RE = re.compile(r"\bmodule\s+(?:(?:automatic|static)\s+)?([A-Za-z_][A-Za-z0-9_$]*)")
TIMESCALE_RE = re.compile(r"`timescale\s+([^\s/]+)\s*/\s*([^\s]+)")


def _resolve_tool(name: str) -> str:
    """Resolve one executable or raise a concise error."""

    path = Path(name)
    if path.is_file() and path.stat().st_mode & 0o111:
        return str(path.resolve())
    found = shutil.which(name)
    if found:
        return found
    raise FileNotFoundError(f"tool not found: {name}")


def _source_text(path: Path) -> str:
    """Read source text while removing comments before module-name inference."""

    text = path.read_text(encoding="utf-8", errors="replace")
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    text = re.sub(r"//.*?$", " ", text, flags=re.M)
    return text


def infer_top(top_file: Path) -> str:
    """Infer the intended top module from one SystemVerilog source file."""

    names = MODULE_RE.findall(_source_text(top_file))
    if not names:
        raise ValueError(f"no module declaration found in top file: {top_file}")
    stem = top_file.stem
    if stem in names:
        return stem
    return names[0]


def _ordered_roots(root: Path, top_file: Path, extra_roots: list[Path]) -> list[Path]:
    """Return unique recursive library roots, preferring the top's directory.

    ``root`` is primarily Slang's working directory. It becomes a recursive
    search root only when the caller did not provide explicit ``search_root``
    entries. Flow targets always provide explicit shared/staged roots so an
    unrelated repository workspace cannot shadow the active run.
    """

    candidates = [top_file.parent, *extra_roots]
    if not extra_roots:
        candidates.append(root)

    ordered: list[Path] = []
    seen: set[Path] = set()
    for candidate in candidates:
        resolved = candidate.expanduser().resolve()
        if not resolved.is_dir():
            raise FileNotFoundError(f"source root not found: {resolved}")
        if resolved in seen:
            continue
        seen.add(resolved)
        ordered.append(resolved)
    return ordered


def _recursive_search_args(roots: list[Path]) -> list[str]:
    """Return recursive include and library-search arguments for Slang."""

    args: list[str] = []
    for root in roots:
        recursive = str(root / "...")
        args.extend([f"-I{recursive}", "--libdir", recursive])
    return args


def _default_timescale_args(top_file: Path) -> list[str]:
    """Use the top file's ``timescale`` as the default for loaded libraries."""

    match = TIMESCALE_RE.search(_source_text(top_file))
    if not match:
        return []
    return ["--timescale", f"{match.group(1)}/{match.group(2)}"]


def _run_slang(
    *,
    slang: str,
    root: Path,
    search_roots: list[Path],
    top_file: Path,
    top: str | None,
    extra_args: str,
    action_args: list[str],
    synthesis: bool = True,
) -> str:
    """Run Slang from one explicit top with on-demand recursive resolution."""

    executable = _resolve_tool(slang)
    root = root.expanduser().resolve()
    top_file = top_file.expanduser().resolve()
    if not top_file.is_file():
        raise FileNotFoundError(f"top source file not found: {top_file}")
    roots = _ordered_roots(root, top_file, search_roots)
    top_name = top or infer_top(top_file)

    command = [
        executable,
        "--top",
        top_name,
        *(["-DSYNTHESIS"] if synthesis else []),
        *_default_timescale_args(top_file),
        *_recursive_search_args(roots),
        *shlex.split(extra_args),
        *action_args,
        str(top_file),
    ]
    subprocess.run(command, cwd=root, check=True)
    return top_name


def run_ast(args: argparse.Namespace) -> None:
    """Generate elaborated Slang AST JSON."""

    json_path = args.json_out.resolve()
    json_path.parent.mkdir(parents=True, exist_ok=True)
    action = ["--ast-json", str(json_path), "--ast-json-source-info"]
    if args.scope:
        action.extend(["--ast-json-scope", args.scope])
    _run_slang(
        slang=args.slang,
        root=args.root,
        search_roots=args.search_root,
        top_file=args.top_file,
        top=args.top,
        extra_args=args.extra_args,
        action_args=action,
    )


def _dep_lines(path: Path) -> list[str]:
    """Read one Slang dependency file, preserving first-seen order."""

    seen: set[str] = set()
    lines: list[str] = []
    for raw in path.read_text(encoding="utf-8").splitlines():
        item = raw.strip()
        if not item or item in seen:
            continue
        seen.add(item)
        lines.append(item)
    return lines


def _resolve_dep(item: str, root: Path) -> Path:
    """Resolve one Slang dependency path against the Slang working root."""

    path = Path(item)
    if not path.is_absolute():
        path = root / path
    return path.resolve()


def _command_path(path: Path, root: Path) -> str:
    """Prefer root-relative paths in portable standalone command files."""

    path = path.resolve()
    try:
        return path.relative_to(root.resolve()).as_posix()
    except ValueError:
        return path.as_posix()


def _portable_extra_args(extra_args: str, root: Path) -> list[str]:
    """Keep portable preprocessor options that affect the discovered closure."""

    tokens = shlex.split(extra_args)
    result: list[str] = []
    index = 0
    while index < len(tokens):
        token = tokens[index]
        if token.startswith("+define+") or token.startswith("+incdir+"):
            result.append(token)
        elif token.startswith("-D") and token != "-D":
            result.append(f"+define+{token[2:]}")
        elif token == "-D" and index + 1 < len(tokens):
            index += 1
            result.append(f"+define+{tokens[index]}")
        elif token.startswith("-I") and token != "-I":
            include_dir = Path(token[2:])
            if not include_dir.is_absolute():
                include_dir = root / include_dir
            result.append(f"+incdir+{_command_path(include_dir, root)}")
        elif token == "-I" and index + 1 < len(tokens):
            index += 1
            include_dir = Path(tokens[index])
            if not include_dir.is_absolute():
                include_dir = root / include_dir
            result.append(f"+incdir+{_command_path(include_dir, root)}")
        index += 1
    return result


def _is_under(path: Path, roots: list[Path]) -> bool:
    """Return whether ``path`` belongs to one of the configured common roots."""

    resolved = path.resolve()
    for root in roots:
        try:
            resolved.relative_to(root.resolve())
            return True
        except ValueError:
            continue
    return False


def _write_lines(path: Path, lines: list[str]) -> None:
    """Write one command file with a trailing newline."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def _split_flow_filelists(
    *,
    common_out: Path,
    ip_out: Path,
    modules: list[Path],
    includes: list[Path],
    common_roots: list[Path],
    extra_args: str,
    root: Path,
    synthesis: bool,
) -> None:
    """Write absolute-path FlexSoC common/IP command files from one Slang closure."""

    common_roots = [item.expanduser().resolve() for item in common_roots]
    common_lines = ["# Auto-generated by Slang: shared RTL"]
    if synthesis:
        common_lines.append("+define+SYNTHESIS")
    ip_lines = ["# Auto-generated by Slang: IP/run RTL"]
    seen_common = set(common_lines)
    seen_ip = set(ip_lines)

    def append(lines: list[str], seen: set[str], item: str) -> None:
        if item not in seen:
            seen.add(item)
            lines.append(item)

    for option in _portable_extra_args(extra_args, root):
        if option.startswith("+incdir+"):
            dirs = [part for part in option[len("+incdir+"):].split("+") if part]
            for directory in dirs:
                path = Path(directory)
                if not path.is_absolute():
                    path = (root / path).resolve()
                target_lines, target_seen = (
                    (common_lines, seen_common) if _is_under(path, common_roots) else (ip_lines, seen_ip)
                )
                append(target_lines, target_seen, f"+incdir+{path.as_posix()}")
        else:
            append(common_lines, seen_common, option)

    include_dirs: list[Path] = []
    seen_dirs: set[Path] = set()
    for source in includes:
        directory = source.parent.resolve()
        if directory in seen_dirs:
            continue
        seen_dirs.add(directory)
        include_dirs.append(directory)

    for directory in include_dirs:
        target_lines, target_seen = (
            (common_lines, seen_common) if _is_under(directory, common_roots) else (ip_lines, seen_ip)
        )
        append(target_lines, target_seen, f"+incdir+{directory.as_posix()}")

    for source in modules:
        target_lines, target_seen = (
            (common_lines, seen_common) if _is_under(source, common_roots) else (ip_lines, seen_ip)
        )
        append(target_lines, target_seen, source.resolve().as_posix())

    _write_lines(common_out, common_lines)
    _write_lines(ip_out, ip_lines)


def run_flist(args: argparse.Namespace) -> None:
    """Generate a hierarchy-trimmed Slang filelist, optionally split for FlexSoC."""

    root = args.root.expanduser().resolve()
    outputs = [path for path in (args.output, args.common_out, args.ip_out) if path is not None]
    if not outputs:
        raise ValueError("flist requires --output or both --common-out/--ip-out")
    if (args.common_out is None) != (args.ip_out is None):
        raise ValueError("--common-out and --ip-out must be provided together")

    resolved_outputs = [path.expanduser().resolve() for path in outputs]
    for path in resolved_outputs:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.unlink(missing_ok=True)

    anchor = resolved_outputs[0]
    module_deps = anchor.with_suffix(anchor.suffix + ".modules.tmp")
    include_deps = anchor.with_suffix(anchor.suffix + ".includes.tmp")

    try:
        _run_slang(
            slang=args.slang,
            root=root,
            search_roots=args.search_root,
            top_file=args.top_file,
            top=args.top,
            extra_args=args.extra_args,
            action_args=[
                "--Mmodule",
                str(module_deps),
                "--Minclude",
                str(include_deps),
                "--depfile-trim",
                "--depfile-sort",
            ],
            synthesis=args.synthesis,
        )

        modules = [_resolve_dep(item, root) for item in _dep_lines(module_deps)]
        includes = [_resolve_dep(item, root) for item in _dep_lines(include_deps)]

        if args.output is not None:
            lines: list[str] = []
            seen_lines: set[str] = set()

            def append_unique(item: str) -> None:
                if item not in seen_lines:
                    seen_lines.add(item)
                    lines.append(item)

            if args.synthesis:
                append_unique("+define+SYNTHESIS")
            for option in _portable_extra_args(args.extra_args, root):
                append_unique(option)
            seen_dirs: set[Path] = set()
            for source in includes:
                directory = source.parent.resolve()
                if directory in seen_dirs:
                    continue
                seen_dirs.add(directory)
                append_unique(f"+incdir+{_command_path(directory, root)}")
            for source in modules:
                append_unique(_command_path(source, root))
            _write_lines(args.output.expanduser().resolve(), lines)

        if args.common_out is not None and args.ip_out is not None:
            _split_flow_filelists(
                common_out=args.common_out.expanduser().resolve(),
                ip_out=args.ip_out.expanduser().resolve(),
                modules=modules,
                includes=includes,
                common_roots=args.common_root,
                extra_args=args.extra_args,
                root=root,
                synthesis=args.synthesis,
            )
    finally:
        module_deps.unlink(missing_ok=True)
        include_deps.unlink(missing_ok=True)


def run_hier(args: argparse.Namespace) -> None:
    """Print hierarchy from one top with recursive on-demand library search."""

    executable = _resolve_tool(args.slang_hier)
    root = args.root.expanduser().resolve()
    top_file = args.top_file.expanduser().resolve()
    if not top_file.is_file():
        raise FileNotFoundError(f"top source file not found: {top_file}")
    roots = _ordered_roots(root, top_file, args.search_root)
    top_name = args.top or infer_top(top_file)
    output = args.output.expanduser().resolve()
    output.parent.mkdir(parents=True, exist_ok=True)

    command = [
        executable,
        "--top",
        top_name,
        "-DSYNTHESIS",
        *_default_timescale_args(top_file),
        *_recursive_search_args(roots),
        *shlex.split(args.extra_args),
        str(top_file),
    ]
    with output.open("w", encoding="utf-8") as stream:
        subprocess.run(command, cwd=root, stdout=stream, check=True)


def build_parser() -> argparse.ArgumentParser:
    """Build the command line used by Make targets."""

    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="command", required=True)

    def common(sub: argparse.ArgumentParser) -> None:
        sub.add_argument("--root", type=Path, required=True)
        sub.add_argument("--search-root", type=Path, action="append", default=[])
        sub.add_argument("--top-file", type=Path, required=True)
        sub.add_argument("--top")
        sub.add_argument("--extra-args", default="")

    ast = subparsers.add_parser("ast", help="Generate Slang AST JSON")
    common(ast)
    ast.add_argument("--slang", default="slang")
    ast.add_argument("--json-out", type=Path, required=True)
    ast.add_argument("--scope")
    ast.set_defaults(func=run_ast)

    flist = subparsers.add_parser("flist", help="Generate trimmed topological filelists")
    common(flist)
    flist.add_argument("--slang", default="slang")
    flist.add_argument("--output", type=Path)
    flist.add_argument("--common-out", type=Path)
    flist.add_argument("--ip-out", type=Path)
    flist.add_argument("--common-root", type=Path, action="append", default=[])
    flist.add_argument("--synthesis", action="store_true")
    flist.set_defaults(func=run_flist)

    hier = subparsers.add_parser("hier", help="Generate hierarchy text with slang-hier")
    common(hier)
    hier.add_argument("--slang-hier", default="slang-hier")
    hier.add_argument("--output", type=Path, required=True)
    hier.set_defaults(func=run_hier)
    return parser


def main(argv: list[str] | None = None) -> int:
    """CLI entry point."""

    args = build_parser().parse_args(argv)
    try:
        args.func(args)
    except (FileNotFoundError, ValueError, subprocess.CalledProcessError) as exc:
        raise SystemExit(f"ERROR: {exc}") from exc
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
