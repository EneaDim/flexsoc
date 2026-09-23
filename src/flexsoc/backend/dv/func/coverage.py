"""Coverage collection and report rendering."""

from __future__ import annotations

from io import StringIO
import json
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping, Sequence

from rich.console import Console
from rich.table import Table

RESET = "\033[0m"
WHITE = "\033[97m"
GRAY = "\033[90m"
ORANGE = "\033[38;5;208m"
BOLD = "\033[1m"

ANNOTATION_RE = re.compile(r"^(?P<status>[ %~+-])(?P<hits>\d+)\s+(?P<body>.*)$")
POINT_RE = re.compile(
    r"^point:(?:\s+type=(?P<kind>\S+))?(?:\s+comment=(?P<comment>.*))?$"
)
REGISTER_RE = re.compile(r".+_reg_(?:pkg|top)\.sv$")
SCOPES = ("design", "registers", "common", "other", "all")
TYPE_ORDER = ("line", "toggle", "expr", "branch", "fsm_state", "fsm_arc", "covergroup", "user")
DISPLAY_COLUMNS = ("line", "toggle", "expr", "branch", "fsm", "user", "total")
DISPLAY_TYPE_GROUPS = {
    "line": ("line",),
    "toggle": ("toggle",),
    "expr": ("expr",),
    "branch": ("branch",),
    "fsm": ("fsm_state", "fsm_arc"),
    "user": ("user", "covergroup"),
}


@dataclass(frozen=True)
class CoveragePoint:
    path: str
    line: int
    kind: str
    hits: int
    detail: str


@dataclass(slots=True)
class CoverageFlow:
    """Collect, summarize and detail Verilator coverage artifacts."""

    runner: object | None = None

    def report(
        self,
        data: Path,
        filelists: Sequence[Path],
        output: Path,
        *,
        annotated_dir: Path | None = None,
    ) -> dict[str, object]:
        """Write and print the scoped coverage summary."""

        from flexsoc.backend.core.runtime.execution import (
        Terminal,
        )

        if len(filelists) < 2:
            raise ValueError("coverage reporting requires IP and common RTL filelists")
        if not data.is_file():
            raise FileNotFoundError(f"coverage database missing: {data}")

        ip_files = CoverageFlow.filelist_basenames(filelists[0])
        common_files = CoverageFlow.filelist_basenames(filelists[1])
        points = CoverageFlow.annotated_points(annotated_dir) if annotated_dir else []
        json_output = output.with_suffix(".json")

        Terminal.print_label("coverage", f"stage=report · points={len(points)}")
        Terminal.print_path_label("summary", output)
        Terminal.print_path_label("json", json_output)
        try:
            summary = CoverageFlow.coverage_summary_data(
                points,
                ip_files=ip_files,
                common_files=common_files,
            )
            CoverageFlow.write_summary(
                points,
                ip_files=ip_files,
                common_files=common_files,
                output=output,
                json_output=json_output,
            )
        except Exception:
            Terminal.print_status_label("coverage", "FAIL", "stage=report")
            raise
        Terminal.print_status_label("coverage", "PASS", "stage=report")
        return summary

    def collect(
        self,
        coverage_dir: Path,
        *,
        tool: str = "verilator_coverage",
        on: str = "local",
    ) -> Path:
        """Merge all Verilator coverage databases into merged.dat."""
        from flexsoc.backend.core import CommandRequest, ToolRunner
        files = tuple(sorted(path for path in coverage_dir.rglob("*.dat") if path.name != "merged.dat"))
        if not files:
            raise FileNotFoundError(f"no Verilator coverage data in {coverage_dir}")
        output = coverage_dir / "merged.dat"
        log = coverage_dir / "merge.log"
        argv = (tool, "--write", str(output), *(str(path) for path in files))
        from flexsoc.backend.core.runtime.execution import Terminal
        import shlex

        Terminal.print_label("coverage", f"stage=merge · inputs={len(files)} · tool={tool}")
        Terminal.print_path_label("log", log)
        Terminal.print_label("command", shlex.join(argv))
        runner = self.runner or ToolRunner()
        try:
            result = runner.run(
                CommandRequest(argv, coverage_dir, {}, log, inputs=files, outputs=(output,)),
                on=on,
            )
        except OSError as exc:
            log.parent.mkdir(parents=True, exist_ok=True)
            log.write_text(f"{exc}\n", encoding="utf-8")
            Terminal.print_status_label("coverage", "FAIL", "stage=merge")
            raise
        if result.returncode:
            Terminal.print_status_label("coverage", "FAIL", "stage=merge")
            raise RuntimeError(f"coverage merge failed; log: {log}")
        Terminal.print_status_label("coverage", "PASS", "stage=merge")
        return output

    def annotate(
        self,
        data: Path,
        output: Path,
        *,
        tool: str = "verilator_coverage",
        on: str = "local",
    ) -> Path:
        """Create Verilator point annotations for one merged database."""
        from flexsoc.backend.core import CommandRequest, ToolRunner
        import shutil
        shutil.rmtree(output, ignore_errors=True)
        output.mkdir(parents=True, exist_ok=True)
        log = output.parent / "annotate.log"
        argv = (
            tool, "--annotate", str(output), "--annotate-all",
            "--annotate-points", "--annotate-min", "1", str(data),
        )
        from flexsoc.backend.core.runtime.execution import Terminal
        import shlex

        Terminal.print_label("coverage", f"stage=annotate · tool={tool}")
        Terminal.print_path_label("log", log)
        Terminal.print_label("command", shlex.join(argv))
        runner = self.runner or ToolRunner()
        try:
            result = runner.run(
                CommandRequest(argv, output.parent, {}, log, inputs=(data,), outputs=(output,)),
                on=on,
            )
        except OSError as exc:
            log.parent.mkdir(parents=True, exist_ok=True)
            log.write_text(f"{exc}\n", encoding="utf-8")
            Terminal.print_status_label("coverage", "FAIL", "stage=annotate")
            raise
        if result.returncode:
            Terminal.print_status_label("coverage", "FAIL", "stage=annotate")
            raise RuntimeError(f"coverage annotation failed; log: {log}")
        Terminal.print_status_label("coverage", "PASS", "stage=annotate")
        return output

    def run_from_context(self, context, *, on: str = "local"):
        """Merge, annotate and write the canonical coverage summary."""

        paths = context.paths
        target = self.runner.targets.get(on) if self.runner is not None else None
        tool = (
            str(context.values.get("VERILATOR_COVERAGE") or "verilator_coverage")
            if target is not None and target.kind != "local"
            else CoverageFlow._resolve_verilator_coverage(context.values)
        )
        merged = self.collect(paths.coverage, tool=tool, on=on)
        annotated = self.annotate(merged, paths.coverage / "annotated", tool=tool, on=on)
        summary = self.report(
            merged, (paths.rtl_ip, paths.rtl_common), paths.coverage / "summary.txt",
            annotated_dir=annotated,
        )
        summary.update({
            "stage": "coverage",
            "status": "PASS",
            "top": paths.top,
            "artifacts": {
                "summary": "dv/functional/coverage/summary.json",
                "text": "dv/functional/coverage/summary.txt",
                "merged": "dv/functional/coverage/merged.dat",
                "annotations": "dv/functional/coverage/annotated",
                "merge_log": "dv/functional/coverage/merge.log",
                "annotate_log": "dv/functional/coverage/annotate.log",
            },
        })
        (paths.coverage / "summary.json").write_text(
            json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
        )
        return summary

    def show(
        self,
        context,
        *,
        summary: bool = False,
        debug: bool = False,
        output: str | None = None,
        as_json: bool = False,
    ) -> int:
        """Render coverage exclusively from the canonical summary."""

        path = context.paths.coverage / "summary.json"
        if not path.is_file():
            raise FileNotFoundError(f"coverage summary not found: {path}; run `fx coverage` first")
        data = json.loads(path.read_text(encoding="utf-8"))
        capture = StringIO() if output else None
        console = Console(file=capture, force_terminal=False) if capture else Console()
        if as_json:
            print(json.dumps(data, indent=2, sort_keys=True), file=capture or None)
        else:
            scopes = data.get("scopes", {}) if isinstance(data.get("scopes"), Mapping) else {}
            design = scopes.get("design", {}).get("total", {}) if isinstance(scopes.get("design"), Mapping) else {}
            overall = scopes.get("all", {}).get("total", {}) if isinstance(scopes.get("all"), Mapping) else {}
            console.print(
                f"[bold]Coverage[/bold] [green]{data.get('status', 'PASS')}[/green] · "
                f"design={float(design.get('percent', 0.0)):.2f}% "
                f"({design.get('hit', 0)}/{design.get('total', 0)}) · "
                f"all={float(overall.get('percent', 0.0)):.2f}% "
                f"({overall.get('hit', 0)}/{overall.get('total', 0)}) · "
                f"uncovered={len(data.get('uncovered', ())) }"
            )
            table = Table(box=None, show_edge=False, pad_edge=False)
            table.add_column("Scope", style="bright_cyan")
            table.add_column("Hit", justify="right")
            table.add_column("Total", justify="right")
            table.add_column("Percent", justify="right")
            for name in SCOPES:
                item = scopes.get(name, {}) if isinstance(scopes, Mapping) else {}
                total = item.get("total", {}) if isinstance(item, Mapping) else {}
                table.add_row(
                    name, str(total.get("hit", 0)), str(total.get("total", 0)),
                    f"{float(total.get('percent', 0.0)):.2f}%",
                )
            console.print(table)

            if not summary:
                limit = int(context.values.get("COVERAGE_SHOW_LIMIT", "0"))
                uncovered = [item for item in data.get("uncovered", ()) if isinstance(item, Mapping)]
                shown = uncovered if limit <= 0 else uncovered[:limit]
                table = Table(box=None, show_edge=False, pad_edge=False)
                table.add_column("Line", justify="right")
                table.add_column("Type", style="bright_cyan")
                table.add_column("Hits", justify="right")
                table.add_column("Detail", overflow="fold")
                table.add_column("File", style="grey70", overflow="fold")
                for item in shown:
                    table.add_row(
                        str(item.get("line", "-")), str(item.get("type", "-")),
                        str(item.get("hits", 0)), str(item.get("detail", "")),
                        str(item.get("file", "-")),
                    )
                console.print(table)
                if len(shown) < len(uncovered):
                    console.print(f"[grey70]Showing {len(shown)} of {len(uncovered)} uncovered points.[/grey70]")

            if debug:
                console.print("[bold]Artifacts[/bold]")
                artifacts = data.get("artifacts", {}) if isinstance(data.get("artifacts"), Mapping) else {}
                for name, artifact in artifacts.items():
                    console.print(f"[grey70]{name}[/grey70] {artifact}")

        if output and capture is not None:
            destination = Path(output)
            if not destination.is_absolute():
                destination = context.project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(capture.getvalue(), encoding="utf-8")
        return 0

    @staticmethod
    def _resolve_verilator_coverage(values: object) -> str:
        """Resolve verilator_coverage from settings, PATH, or the Verilator install tree."""
    
        import os
        import shutil
    
        mapping = values if isinstance(values, dict) else values
        get = getattr(mapping, "get", lambda _key, default=None: default)
        explicit = str(get("VERILATOR_COVERAGE", "") or "").strip()
        if explicit:
            return explicit
    
        if found := shutil.which("verilator_coverage"):
            return found
    
        verilator = str(get("VERILATOR", "verilator") or "verilator").strip()
        resolved = shutil.which(verilator)
        candidates: list[Path] = []
        if resolved:
            executable = Path(resolved).expanduser()
            candidates.extend((
                executable.with_name("verilator_coverage"),
                executable.resolve().with_name("verilator_coverage"),
            ))
        elif Path(verilator).expanduser().is_file():
            executable = Path(verilator).expanduser()
            candidates.extend((
                executable.with_name("verilator_coverage"),
                executable.resolve().with_name("verilator_coverage"),
            ))
    
        if root := os.environ.get("VERILATOR_ROOT"):
            candidates.append(Path(root).expanduser() / "bin" / "verilator_coverage")
    
        for candidate in candidates:
            if candidate.is_file():
                return str(candidate)
        return "verilator_coverage"

    @staticmethod
    def annotated_points(root: Path) -> list[CoveragePoint]:
        """Return individual coverage points from Verilator annotated sources."""
    
        points: list[CoveragePoint] = []
        for path in sorted(item for item in root.rglob("*") if item.is_file()):
            rel = path.relative_to(root).as_posix()
            source_line = 0
            source_detail = ""
    
            for raw in path.read_text(encoding="utf-8", errors="replace").splitlines():
                match = ANNOTATION_RE.match(raw)
                if not match:
                    continue
    
                status = match.group("status")
                hits = int(match.group("hits"))
                body = match.group("body").strip()
    
                if status in {" ", "%", "~"}:
                    source_line += 1
                    source_detail = body
                    continue
    
                if status not in {"+", "-"} or source_line == 0:
                    continue
    
                point = POINT_RE.match(body)
                if not point:
                    continue
    
                kind = point.group("kind") or "point"
                detail = (point.group("comment") or source_detail).strip()
                points.append(CoveragePoint(rel, source_line, kind, hits, detail))
    
        return sorted(points, key=lambda point: (point.path, point.line, point.kind, point.detail))

    @staticmethod
    def filelist_basenames(path: Path) -> set[str]:
        """Return HDL basenames from a canonical FlexSoC filelist."""
    
        if not path.is_file():
            return set()
    
        names: set[str] = set()
        for raw in path.read_text(encoding="utf-8", errors="replace").splitlines():
            line = raw.strip()
            if not line or line.startswith(("#", "+", "-")):
                continue
            token = line.split()[0]
            if Path(token).suffix.lower() in {".sv", ".svh", ".v", ".vh"}:
                names.add(Path(token).name)
        return names

    @staticmethod
    def classify(path: str, *, ip_files: set[str], common_files: set[str]) -> str:
        """Classify a coverage point by source ownership."""
    
        name = Path(path).name
        if name in common_files:
            return "common"
        if name in ip_files:
            if REGISTER_RE.fullmatch(name):
                return "registers"
            return "design"
        return "other"

    @staticmethod
    def scoped_points(
        points: list[CoveragePoint],
        scope: str,
        *,
        ip_files: set[str],
        common_files: set[str],
    ) -> list[CoveragePoint]:
        if scope == "all":
            return points
        return [
            point
            for point in points
            if CoverageFlow.classify(point.path, ip_files=ip_files, common_files=common_files) == scope
        ]

    @staticmethod
    def coverage_counts(points: list[CoveragePoint]) -> tuple[int, int, float]:
        total = len(points)
        covered = sum(point.hits > 0 for point in points)
        percent = 100.0 * covered / total if total else 0.0
        return covered, total, percent

    @staticmethod
    def _coverage_cell(text: str) -> str:
        """Render one coverage cell with the neutral white/gray/orange palette."""
    
        if text == "-":
            return f"{GRAY}{text}{RESET}"
        return f"{ORANGE}{text}{RESET}"

    @staticmethod
    def _render_summary_line(line: str) -> str:
        """Render one summary line without applying pass/fail semantics to coverage."""
    
        if not line:
            return line
        if line == "Functional coverage — scope × type":
            return f"{BOLD}{WHITE}{line}{RESET}"
        if line.startswith("Scope") or set(line) == {"-"}:
            return f"{GRAY}{line}{RESET}"
        if line.startswith("fsm ="):
            return f"{GRAY}{line}{RESET}"
    
        parts = line.split()
        if parts and parts[0] in SCOPES and len(parts) == 1 + len(DISPLAY_COLUMNS):
            scope, *cells = parts
            width = 10
            rendered = f"{WHITE}{scope:<12}{RESET}"
            rendered += "".join(
                f"{CoverageFlow._coverage_cell(cell):>{width + len(CoverageFlow._coverage_cell(cell)) - len(cell)}}"
                for cell in cells
            )
            return rendered
        return line

    @staticmethod
    def coverage_record(points: list[CoveragePoint]) -> dict[str, float | int]:
        """Return a JSON-friendly covered/total/percent record."""
    
        covered, total, percent = CoverageFlow.coverage_counts(points)
        return {"hit": covered, "total": total, "percent": percent}

    @staticmethod
    def coverage_types(points: list[CoveragePoint]) -> list[str]:
        """Return stable coverage-type ordering, preserving future Verilator kinds."""
    
        present = {point.kind for point in points}
        ordered = [kind for kind in TYPE_ORDER if kind in present]
        ordered.extend(sorted(present - set(TYPE_ORDER)))
        return ordered

    @staticmethod
    def coverage_summary_data(
        points: list[CoveragePoint],
        *,
        ip_files: set[str],
        common_files: set[str],
    ) -> dict[str, object]:
        """Build raw coverage data plus the stable scope-by-type display matrix."""
    
        kinds = CoverageFlow.coverage_types(points)
        scopes: dict[str, object] = {}
        for scope in SCOPES:
            selected = CoverageFlow.scoped_points(
                points,
                scope,
                ip_files=ip_files,
                common_files=common_files,
            )
            raw_types = {
                kind: CoverageFlow.coverage_record([point for point in selected if point.kind == kind])
                for kind in kinds
            }
            columns = {
                column: CoverageFlow.coverage_record(
                    [point for point in selected if point.kind in DISPLAY_TYPE_GROUPS[column]]
                )
                for column in DISPLAY_TYPE_GROUPS
            }
            columns["total"] = CoverageFlow.coverage_record(selected)
            scopes[scope] = {
                "total": columns["total"],
                "types": raw_types,
                "columns": columns,
            }
        return {
            "schema_version": 3,
            "uncovered": [
                {"line": point.line, "type": point.kind, "hits": point.hits, "detail": point.detail, "file": point.path}
                for point in points if point.hits == 0
            ],
            "types": kinds,
            "display_columns": list(DISPLAY_COLUMNS),
            "scopes": scopes,
        }

    @staticmethod
    def _summary_lines(
        points: list[CoveragePoint],
        *,
        ip_files: set[str],
        common_files: set[str],
    ) -> list[str]:
        data = CoverageFlow.coverage_summary_data(points, ip_files=ip_files, common_files=common_files)
        scopes = data["scopes"]
        columns = data["display_columns"]
    
        width = 10
        lines = [
            "Functional coverage — scope × type",
            "",
            f"{'Scope':<12}" + "".join(f"{column:>{width}}" for column in columns),
            "-" * (12 + width * len(columns)),
        ]
        for scope in SCOPES:
            values = scopes[scope]["columns"]
            cells = []
            for column in columns:
                record = values[column]
                cells.append("-" if record["total"] == 0 else f"{record['percent']:.2f}%")
            lines.append(f"{scope:<12}" + "".join(f"{cell:>{width}}" for cell in cells))
    
        lines.extend(
            [
                "",
                "fsm = fsm_state + fsm_arc; user = user + covergroup",
            ]
        )
        return lines

    @staticmethod
    def write_summary(
        points: list[CoveragePoint],
        *,
        ip_files: set[str],
        common_files: set[str],
        output: Path,
        json_output: Path | None = None,
    ) -> None:
        """Write human and machine-readable coverage summaries."""
    
        lines = CoverageFlow._summary_lines(points, ip_files=ip_files, common_files=common_files)
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text("\n".join(lines) + "\n", encoding="utf-8")
        if json_output is not None:
            import json
    
            data = CoverageFlow.coverage_summary_data(points, ip_files=ip_files, common_files=common_files)
            json_output.parent.mkdir(parents=True, exist_ok=True)
            json_output.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    
        print(f"\n{BOLD}{WHITE}Coverage{RESET}")
        for line in lines:
            print(CoverageFlow._render_summary_line(line))
