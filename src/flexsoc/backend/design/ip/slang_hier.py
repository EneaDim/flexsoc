"""Slang hierarchy setup, execution, summary and presentation."""

from __future__ import annotations

from dataclasses import dataclass, replace
from io import StringIO
import json
from pathlib import Path
import shlex
from typing import Any

from rich.console import Console

from ...core import BackendContext, CommandRequest, ToolRunner
from ...core.render.show import ShowRenderer
from .rtl import RtlFlow


@dataclass(slots=True)
class SlangHierarchy:
    """Own the elaborated hierarchy lifecycle for one configured run."""

    context: BackendContext
    runner: ToolRunner

    def setup(self) -> Path:
        """Materialize the reproducible hierarchy command without running Slang."""

        output = self.context.paths.slang_hier
        output.mkdir(parents=True, exist_ok=True)
        script = output / "run.sh"
        command, _, _ = self._command(on="local", resolve_tool=False)
        script.write_text("#!/usr/bin/env bash\nset -euo pipefail\n" + shlex.join(command) + "\n", encoding="utf-8")
        script.chmod(0o755)
        return script

    def run(self, *, on: str = "local") -> int:
        """Run slang-hier once and write canonical structured evidence."""

        stage = self.context.paths.slang_hier
        stage.mkdir(parents=True, exist_ok=True)
        hierarchy = stage / "hierarchy.txt"
        summary = stage / "summary.json"
        hierarchy.unlink(missing_ok=True)
        summary.unlink(missing_ok=True)

        command, top_file, roots = self._command(on=on)
        log = self.context.paths.logs / "design" / "slang_hier" / "slang_hier.log"
        result = self.runner.run(
            CommandRequest(
                command,
                self.context.project_root,
                {},
                log,
                inputs=(top_file, *roots),
                outputs=(hierarchy,),
                stdout=hierarchy,
            ),
            on=on,
        )
        self._write_summary(result.returncode, result.duration_s, hierarchy, log)
        return int(result.returncode)

    def show(
        self,
        *,
        summary: bool = False,
        output: str | None = None,
        as_json: bool = False,
    ) -> int:
        """Render existing hierarchy evidence without rerunning the frontend."""

        path = self.context.paths.slang_hier / "summary.json"
        if not path.is_file():
            raise FileNotFoundError(f"slang hierarchy summary not found: {path}; run `fx slang_hier` first")
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

    def debug(self, *, output: str | None = None, as_json: bool = False) -> int:
        """Render hierarchy evidence plus the small set of useful debug artifact paths."""

        if as_json:
            return self.show(output=output, as_json=True)
        code = self.show(output=output)
        if output is None:
            Console().print(
                f"[grey70]script[/grey70] {self.context.paths.slang_hier / 'run.sh'}\n"
                f"[grey70]hierarchy[/grey70] {self.context.paths.slang_hier / 'hierarchy.txt'}\n"
                f"[grey70]log[/grey70] {self.context.paths.logs / 'design' / 'slang_hier' / 'slang_hier.log'}"
            )
        return code

    def _inputs(self) -> tuple[Path, Path, tuple[Path, ...], str]:
        """Resolve the same top, search roots and extra arguments for setup and run."""

        values, paths = self.context.values, self.context.paths
        root = Path(values.get("SLANG_ROOT", paths.rtl)).expanduser().resolve()
        top_file = Path(values.get("SLANG_TOP_FILE", root / f"{paths.top}.sv")).expanduser().resolve()
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
                    entries = item.removeprefix("+incdir+").split("+") if item.startswith("+incdir+") else [str(Path(item).parent)]
                    roots.extend((root / path if not path.is_absolute() else path).resolve() for path in map(Path, entries) if str(path))
        roots = list(dict.fromkeys(roots))
        if not roots:
            roots = [
                path for path in (paths.rtl, self.context.project_root / "hw" / "ips", self.context.project_root / "vendor")
                if path.is_dir()
            ]
        extra_args = shlex.join((*shlex.split(values.get("SLANG_ARGS", "")), *extra))
        return root, top_file, tuple(roots), extra_args

    def _command(self, *, on: str, resolve_tool: bool = True) -> tuple[tuple[str, ...], Path, tuple[Path, ...]]:
        """Build the one canonical slang-hier command used by setup and execution."""

        root, top_file, roots, extra_args = self._inputs()
        if not top_file.is_file():
            raise FileNotFoundError(f"top source file not found: {top_file}")
        top = self.context.values.get("SLANG_TOP", self.context.paths.top)
        tool = self.context.values.get("SLANG_HIER", "slang-hier")
        executable = RtlFlow._resolve_tool(tool) if resolve_tool and on == "local" else tool
        command = (
            executable,
            "--top", top,
            "-DSYNTHESIS",
            *RtlFlow._default_timescale_args(top_file),
            *RtlFlow._recursive_search_args(RtlFlow._ordered_roots(root, top_file, roots)),
            *shlex.split(extra_args),
            str(top_file),
        )
        return command, top_file, roots

    def _write_summary(self, returncode: int, duration_s: float, hierarchy: Path, log: Path) -> dict[str, Any]:
        """Normalize hierarchy output into the machine-readable stage contract."""

        lines = hierarchy.read_text(encoding="utf-8", errors="replace").splitlines() if hierarchy.is_file() else []
        run = self.context.paths.run.resolve()
        script_path = (self.context.paths.slang_hier / "run.sh").resolve().relative_to(run).as_posix()
        hierarchy_path = hierarchy.resolve().relative_to(run).as_posix()
        log_path = log.resolve().relative_to(run).as_posix()
        summary = {
            "schema": "flexsoc.slang_hier.v1",
            "stage": "slang_hier",
            "status": "PASS" if returncode == 0 and hierarchy.is_file() else "FAILED",
            "tool": "slang-hier",
            "top": self.context.values.get("SLANG_TOP", self.context.paths.top),
            "run": {"exit_code": int(returncode), "duration_s": float(duration_s)},
            "metrics": {"lines": len(lines)},
            "hierarchy": lines,
            "artifacts": {
                "script": script_path,
                "hierarchy": hierarchy_path,
                "log": log_path,
            },
        }
        path = self.context.paths.slang_hier / "summary.json"
        path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return summary
