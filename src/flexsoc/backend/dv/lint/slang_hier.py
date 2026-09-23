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

        command, top_file, roots = self._command(ast=ast, on=on)
        log = self.context.paths.logs / "dv" / "slang_hier" / "slang_hier.log"
        result = self.runner.run(
            CommandRequest(
                command,
                self.context.project_root,
                {},
                log,
                inputs=(top_file, *roots),
                outputs=(hierarchy, ast),
                stdout=hierarchy,
            ),
            on=on,
        )
        self._write_summary(command, result.returncode, result.duration_s, hierarchy, ast, log)
        return 0

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

        if not roots:
            for filelist in (paths.rtl_common, paths.rtl_ip):
                if not filelist.is_file():
                    continue
                for raw in filelist.read_text(encoding="utf-8").splitlines():
                    item = raw.strip()
                    if not item or item.startswith(("#", "+define+")):
                        continue
                    entries = (
                        item.removeprefix("+incdir+").split("+")
                        if item.startswith("+incdir+")
                        else [str(Path(item).parent)]
                    )
                    roots.extend(
                        (root / path if not path.is_absolute() else path).resolve()
                        for path in map(Path, entries)
                        if str(path)
                    )
        roots = list(dict.fromkeys(roots))
        if not roots:
            roots = [
                path
                for path in (
                    paths.rtl,
                    self.context.project_root / "hw" / "ips",
                    self.context.project_root / "vendor",
                )
                if path.is_dir()
            ]
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
        search_args = [
            arg
            for search_root in ordered_roots
            for arg in (f"-I{search_root / '...'}", "--libdir", str(search_root / "..."))
        ]

        source = top_file.read_text(encoding="utf-8", errors="replace")
        source = re.sub(r"/\*.*?\*/", " ", source, flags=re.S)
        source = re.sub(r"//.*?$", " ", source, flags=re.M)
        timescale = re.search(r"`timescale\s+([^/\s]+)\s*/\s*([^\s]+)", source)
        timescale_args = ["--timescale", f"{timescale.group(1)}/{timescale.group(2)}"] if timescale else []

        command = (
            executable,
            "--top",
            top,
            "--custom-format",
            "{inst}\t{module}\t{file}",
            "--ast-json",
            str(ast),
            "--ast-json-source-info",
            "-DSYNTHESIS",
            *timescale_args,
            *search_args,
            *shlex.split(extra_args),
            str(top_file),
        )
        return command, top_file, roots

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
        if hierarchy.is_file():
            for raw in hierarchy.read_text(encoding="utf-8", errors="replace").splitlines():
                if not raw.strip():
                    continue
                fields = raw.split("\t", 2)
                if len(fields) != 3:
                    malformed += 1
                    continue
                instance, module, source = (field.strip() for field in fields)
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
                if returncode == 0 and hierarchy.is_file() and ast.is_file() and malformed == 0
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
