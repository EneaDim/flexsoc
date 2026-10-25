"""Slang hierarchy execution, canonical evidence and presentation."""

from __future__ import annotations

from dataclasses import dataclass, replace
from io import StringIO
import json
from pathlib import Path
import re
import shlex
import shutil
from typing import Any

from rich.console import Console

from ...core import BackendContext, CommandRequest, ToolRunner
from ...core.render.show import ShowRenderer


@dataclass(slots=True)
class SlangHierarchy:
    """Own one slang-hier run and its structured hierarchy evidence."""

    context: BackendContext
    runner: ToolRunner

    def run(self, *, on: str = "local") -> int:
        """Run slang-hier once and normalize its instance hierarchy."""

        stage = self.context.paths.slang_hier
        stage.mkdir(parents=True, exist_ok=True)
        hierarchy = stage / "hierarchy.txt"
        ast = stage / "ast.json"
        hierarchy.unlink(missing_ok=True)
        ast.unlink(missing_ok=True)
        (stage / "summary.json").unlink(missing_ok=True)

        hierarchy_command, top_file, roots = self._command(ast=ast, on=on)
        ast_command = self._ast_command(hierarchy_command, ast=ast, on=on)
        log = self.context.paths.logs / "dv" / "slang_hier" / "slang_hier.log"
        hierarchy_result = self.runner.run(
            CommandRequest(
                hierarchy_command, self.context.project_root, {}, log,
                inputs=(top_file, *roots), outputs=(hierarchy,), stdout=hierarchy,
            ), on=on,
        )
        ast_log = log.with_name("slang_ast.log")
        ast_code = 0
        duration = hierarchy_result.duration_s
        if hierarchy_result.returncode == 0:
            ast_result = self.runner.run(
                CommandRequest(
                    ast_command, self.context.project_root, {}, ast_log,
                    inputs=(top_file, *roots), outputs=(ast,),
                ), on=on,
            )
            ast_code = ast_result.returncode
            duration += ast_result.duration_s
        code = hierarchy_result.returncode or ast_code
        summary = self._write_summary(
            hierarchy_command, code, duration, hierarchy, ast, log,
        )
        summary["ast_command"] = list(ast_command)
        summary["artifacts"]["ast_log"] = ast_log.resolve().relative_to(self.context.paths.run.resolve()).as_posix()
        (stage / "summary.json").write_text(
            json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8",
        )
        return 0 if summary["status"] == "PASS" else (code or 1)

    def debug(self, *, output: str | None = None, as_json: bool = False) -> int:
        """Show canonical evidence plus the command and raw artifact locations."""

        if as_json:
            return self.show(output=output, as_json=True)
        code = self.show(output=output)
        if output is None:
            summary = json.loads(
                (self.context.paths.slang_hier / "summary.json").read_text(encoding="utf-8")
            )
            Console().print(
                f"[grey70]command[/grey70] {shlex.join(summary.get('command', ()))}\n"
                f"[grey70]hierarchy[/grey70] {self.context.paths.slang_hier / 'hierarchy.txt'}\n"
                f"[grey70]ast[/grey70] {self.context.paths.slang_hier / 'ast.json'}\n"
                f"[grey70]log[/grey70] {self.context.paths.logs / 'dv' / 'slang_hier' / 'slang_hier.log'}"
            )
        return code

    def show(
        self,
        *,
        summary: bool = False,
        output: str | None = None,
        as_json: bool = False,
    ) -> int:
        """Render existing hierarchy evidence without rerunning Slang."""

        path = self.context.paths.slang_hier / "summary.json"
        if not path.is_file():
            raise FileNotFoundError(
                f"slang hierarchy summary not found: {path}; run `fx slang_hier` first"
            )
        document = ShowRenderer.load_file(self.context.paths.run, "dv/slang_hier/summary.json")
        data = dict(document.data)
        if summary:
            data["summary_only"] = True
            document = replace(document, data=data)

        capture = StringIO() if output else None
        console = Console(file=capture, force_terminal=False) if capture else Console()
        if as_json:
            print(json.dumps(data, indent=2, sort_keys=True), file=capture or None)
        else:
            ShowRenderer(console).render(document)
        if output and capture is not None:
            destination = Path(output)
            if not destination.is_absolute():
                destination = self.context.project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(capture.getvalue(), encoding="utf-8")
        return 0

    def _resolve_filelist_path(self, item: str, *, filelist: Path, number: int) -> Path:
        """Resolve portable paths in their declared namespace.

        ``rtl/`` belongs to the active run. Shared ``hw/`` and ``vendor/``
        belong to the FlexSoC project, never to a run or a frozen IP package.
        Refuse absolute and escaping paths rather than silently using host files.
        """
        rel = Path(item)
        if rel.is_absolute() or ".." in rel.parts:
            raise ValueError(f"nonportable filelist path: {filelist}:{number}: {item}")
        project = self.context.project_root.resolve()
        run = self.context.paths.run.resolve()
        base = project if rel.parts and rel.parts[0] in {"hw", "vendor"} else run
        result = (base / rel).resolve()
        if not result.is_relative_to(base):
            raise ValueError(f"filelist path escapes its root: {filelist}:{number}: {item}")
        return result

    def _inputs(self) -> tuple[Path, Path, tuple[Path, ...], str]:
        """Resolve the top file, search roots and extra Slang arguments."""

        values, paths = self.context.values, self.context.paths
        root = Path(values.get("SLANG_ROOT", paths.rtl)).expanduser().resolve()
        top_file = Path(
            values.get("SLANG_TOP_FILE", root / f"{paths.top}.sv")
        ).expanduser().resolve()
        tokens = iter(shlex.split(values.get("SLANG_SEARCH_ARGS", "")))
        roots: list[Path] = []
        extra: list[str] = []
        for token in tokens:
            if token == "--search-root":
                try:
                    roots.append(Path(next(tokens)).expanduser().resolve())
                except StopIteration as exc:
                    raise ValueError("SLANG_SEARCH_ARGS: --search-root requires a path") from exc
            elif token.startswith("--search-root="):
                roots.append(Path(token.split("=", 1)[1]).expanduser().resolve())
            else:
                extra.append(token)

        # Search roots are include directories only. Never recurse through an
        # entire staged deps tree: it can contain historical workspace copies.
        if not roots:
            roots = [root]
            for filelist in (paths.rtl_common, paths.rtl_ip):
                if not filelist.is_file():
                    continue
                for number, raw in enumerate(filelist.read_text(encoding="utf-8").splitlines(), 1):
                    item = raw.strip()
                    if item.startswith("+incdir+"):
                        for entry in item.removeprefix("+incdir+").split("+"):
                            if entry:
                                roots.append(self._resolve_filelist_path(
                                    entry, filelist=filelist, number=number
                                ))
        roots = list(dict.fromkeys(roots))
        extra_args = shlex.join((*shlex.split(values.get("SLANG_ARGS", "")), *extra))
        return root, top_file, tuple(roots), extra_args

    def _command(
        self, *, ast: Path, on: str, resolve_tool: bool = True
    ) -> tuple[tuple[str, ...], Path, tuple[Path, ...]]:
        """Build one Slang elaboration that emits hierarchy and AST evidence."""

        root, top_file, roots, extra_args = self._inputs()
        if not top_file.is_file():
            raise FileNotFoundError(f"top source file not found: {top_file}")
        top = self.context.values.get("SLANG_TOP", self.context.paths.top)
        tool = self.context.values.get("SLANG_HIER", "slang-hier")
        executable = tool
        if resolve_tool and on == "local":
            path = Path(tool)
            executable = (
                str(path.resolve())
                if path.is_file() and path.stat().st_mode & 0o111
                else shutil.which(tool) or ""
            )
            if not executable:
                raise FileNotFoundError(f"tool not found: {tool}")

        ordered_roots: list[Path] = []
        for candidate in (top_file.parent, *roots):
            resolved = candidate.expanduser().resolve()
            if not resolved.is_dir():
                raise FileNotFoundError(f"source root not found: {resolved}")
            if resolved not in ordered_roots:
                ordered_roots.append(resolved)
        if not roots:
            resolved_root = root.resolve()
            if not resolved_root.is_dir():
                raise FileNotFoundError(f"source root not found: {resolved_root}")
            if resolved_root not in ordered_roots:
                ordered_roots.append(resolved_root)
        search_args = [f"-I{search_root}" for search_root in ordered_roots]
        # Filelists are release-root-relative, deliberately nonrecursive.
        # This avoids accidentally elaborating a second copy under deps/workspace.
        sources: list[Path] = []
        for filelist in (self.context.paths.rtl_common, self.context.paths.rtl_ip):
            if not filelist.is_file():
                continue
            for number, raw in enumerate(filelist.read_text(encoding="utf-8").splitlines(), 1):
                item = raw.strip()
                if not item or item.startswith(("#", "+incdir+", "+define+")):
                    continue
                if item.startswith(("-", "+")):
                    raise ValueError(f"unsupported filelist directive: {filelist}:{number}: {item}")
                source_file = self._resolve_filelist_path(
                    item, filelist=filelist, number=number
                )
                if not source_file.is_file():
                    raise FileNotFoundError(f"filelist source missing: {filelist}:{number}: {source_file}")
                if source_file not in sources:
                    sources.append(source_file)
        sources = [src for src in sources if src != top_file]

        source = top_file.read_text(encoding="utf-8", errors="replace")
        source = re.sub(r"/\*.*?\*/", " ", source, flags=re.S)
        source = re.sub(r"//.*?$", " ", source, flags=re.M)
        timescale = re.search(r"`timescale\s+([^/\s]+)\s*/\s*([^\s]+)", source)
        timescale_args = ["--timescale", f"{timescale.group(1)}/{timescale.group(2)}"] if timescale else []

        command = (
            executable,
            "--top", top,
            "--custom-format", "{inst}\t{module}\t{file}",
            "-DSYNTHESIS",
            *timescale_args,
            *search_args,
            *shlex.split(extra_args),
            *(str(src) for src in sources),
            str(top_file),
        )
        return command, top_file, roots

    def _ast_command(self, hierarchy_command: tuple[str, ...], *, ast: Path, on: str) -> tuple[str, ...]:
        """Use the Slang driver for AST output; slang-hier does not own that flag."""
        tool = self.context.values.get("SLANG", "slang")
        executable = tool
        if on == "local":
            candidate = Path(tool)
            executable = (
                str(candidate.resolve())
                if candidate.is_file() and candidate.stat().st_mode & 0o111
                else shutil.which(tool) or ""
            )
            if not executable:
                raise FileNotFoundError(f"Slang AST driver not found: {tool}")
        return (
            executable,
            "--top", hierarchy_command[2],
            *hierarchy_command[7:-1],
            "--ast-json", str(ast), "--ast-json-source-info",
            *hierarchy_command[-1:],
        )

    def _write_summary(
        self,
        command: tuple[str, ...],
        returncode: int,
        duration_s: float,
        hierarchy: Path,
        ast: Path,
        log: Path,
    ) -> dict[str, Any]:
        """Normalize hierarchy rows and record the AST from the same elaboration."""

        instances: list[dict[str, str]] = []
        malformed = 0
        non_hierarchy = 0
        if hierarchy.is_file():
            for raw in hierarchy.read_text(encoding="utf-8", errors="replace").splitlines():
                if not raw.strip():
                    continue
                fields = raw.split("\t", 2)
                if len(fields) != 3:
                    # slang-hier can emit human-readable headers / build summaries
                    # on stdout alongside the machine-readable instance rows.
                    # Only tabular records belong to the hierarchy protocol.
                    # Keep a count for diagnostics, but do not fail a successful
                    # elaboration because of non-hierarchy text.
                    non_hierarchy += 1
                    continue
                instance, module, source = (field.strip() for field in fields)
                if not instance or not module:
                    malformed += 1
                    continue
                source = source or "-"
                source_path = Path(source)
                if source != "-" and source_path.is_absolute():
                    try:
                        source = source_path.resolve().relative_to(
                            self.context.project_root.resolve()
                        ).as_posix()
                    except ValueError:
                        source = source_path.as_posix()
                instances.append({"instance": instance, "module": module, "file": source})

        run = self.context.paths.run.resolve()
        summary = {
            "schema": "flexsoc.slang_hier.v3",
            "stage": "slang_hier",
            "status": (
                "PASS"
                if returncode == 0 and hierarchy.is_file() and ast.is_file() and bool(instances) and malformed == 0
                else "FAILED"
            ),
            "tool": "slang-hier",
            "top": self.context.values.get("SLANG_TOP", self.context.paths.top),
            "command": list(command),
            "run": {"exit_code": int(returncode), "duration_s": float(duration_s)},
            "metrics": {
                "instances": len(instances),
                "modules": len({item["module"] for item in instances}),
                "source_files": len({item["file"] for item in instances}),
                "ast_bytes": ast.stat().st_size if ast.is_file() else 0,
                "malformed_rows": malformed,
                "non_hierarchy_rows": non_hierarchy,
            },
            "instances": instances,
            "artifacts": {
                "hierarchy": hierarchy.resolve().relative_to(run).as_posix(),
                "ast": ast.resolve().relative_to(run).as_posix(),
                "log": log.resolve().relative_to(run).as_posix(),
            },
        }
        path = self.context.paths.slang_hier / "summary.json"
        path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return summary
