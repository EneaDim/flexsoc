"""Render Verilator coverage summaries and detailed uncovered-point logs."""

from __future__ import annotations

import argparse
import re
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

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
        if classify(point.path, ip_files=ip_files, common_files=common_files) == scope
    ]


def coverage_counts(points: list[CoveragePoint]) -> tuple[int, int, float]:
    total = len(points)
    covered = sum(point.hits > 0 for point in points)
    percent = 100.0 * covered / total if total else 0.0
    return covered, total, percent


def _coverage_cell(text: str) -> str:
    """Render one coverage cell with the neutral white/gray/orange palette."""

    if text == "-":
        return f"{GRAY}{text}{RESET}"
    return f"{ORANGE}{text}{RESET}"


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
            f"{_coverage_cell(cell):>{width + len(_coverage_cell(cell)) - len(cell)}}"
            for cell in cells
        )
        return rendered
    return line


def coverage_record(points: list[CoveragePoint]) -> dict[str, float | int]:
    """Return a JSON-friendly covered/total/percent record."""

    covered, total, percent = coverage_counts(points)
    return {"hit": covered, "total": total, "percent": percent}


def coverage_types(points: list[CoveragePoint]) -> list[str]:
    """Return stable coverage-type ordering, preserving future Verilator kinds."""

    present = {point.kind for point in points}
    ordered = [kind for kind in TYPE_ORDER if kind in present]
    ordered.extend(sorted(present - set(TYPE_ORDER)))
    return ordered


def coverage_summary_data(
    points: list[CoveragePoint],
    *,
    ip_files: set[str],
    common_files: set[str],
) -> dict[str, object]:
    """Build raw coverage data plus the stable scope-by-type display matrix."""

    kinds = coverage_types(points)
    scopes: dict[str, object] = {}
    for scope in SCOPES:
        selected = scoped_points(
            points,
            scope,
            ip_files=ip_files,
            common_files=common_files,
        )
        raw_types = {
            kind: coverage_record([point for point in selected if point.kind == kind])
            for kind in kinds
        }
        columns = {
            column: coverage_record(
                [point for point in selected if point.kind in DISPLAY_TYPE_GROUPS[column]]
            )
            for column in DISPLAY_TYPE_GROUPS
        }
        columns["total"] = coverage_record(selected)
        scopes[scope] = {
            "total": columns["total"],
            "types": raw_types,
            "columns": columns,
        }
    return {
        "schema_version": 2,
        "types": kinds,
        "display_columns": list(DISPLAY_COLUMNS),
        "scopes": scopes,
    }


def _summary_lines(
    points: list[CoveragePoint],
    *,
    ip_files: set[str],
    common_files: set[str],
) -> list[str]:
    data = coverage_summary_data(points, ip_files=ip_files, common_files=common_files)
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


def write_summary(
    points: list[CoveragePoint],
    *,
    ip_files: set[str],
    common_files: set[str],
    output: Path,
    json_output: Path | None = None,
) -> None:
    """Write human and machine-readable coverage summaries."""

    lines = _summary_lines(points, ip_files=ip_files, common_files=common_files)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    if json_output is not None:
        import json

        data = coverage_summary_data(points, ip_files=ip_files, common_files=common_files)
        json_output.parent.mkdir(parents=True, exist_ok=True)
        json_output.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    print(f"\n{BOLD}{WHITE}Coverage{RESET}")
    for line in lines:
        print(_render_summary_line(line))


def _shorten(text: str, width: int) -> str:
    if len(text) <= width:
        return text
    return text[: max(1, width - 1)] + "…"


def detail_lines(points: list[CoveragePoint], *, limit: int, scope: str) -> list[str]:
    missing = [point for point in points if point.hits == 0]
    shown = missing if limit <= 0 else missing[:limit]
    lines = [f"Coverage detail — uncovered points (scope={scope})", ""]

    if not shown:
        lines.append("No zero-hit coverage points found.")
        return lines

    path_width = min(64, max(len("File"), *(len(point.path) for point in shown)))
    kind_width = min(18, max(len("Type"), *(len(point.kind) for point in shown)))
    detail_width = 96
    header = (
        f"{'File':<{path_width}}  {'Line':>6}  "
        f"{'Type':<{kind_width}}  {'Hits':>6}  Detail"
    )
    lines.extend([header, "-" * min(180, len(header) + detail_width)])
    for point in shown:
        lines.append(
            f"{_shorten(point.path, path_width):<{path_width}}  "
            f"{point.line:>6}  "
            f"{_shorten(point.kind, kind_width):<{kind_width}}  "
            f"{point.hits:>6}  "
            f"{_shorten(point.detail, detail_width)}"
        )

    if len(shown) < len(missing):
        lines.extend(["", f"Showing {len(shown)} of {len(missing)} uncovered points."])
    else:
        lines.extend(["", f"Uncovered points: {len(missing)}"])
    return lines


def write_detail(
    points: list[CoveragePoint],
    *,
    scope: str,
    ip_files: set[str],
    common_files: set[str],
    limit: int,
    output: Path,
) -> int:
    """Write detailed uncovered points to a log and return the uncovered count."""

    selected = scoped_points(
        points,
        scope,
        ip_files=ip_files,
        common_files=common_files,
    )
    missing = sum(point.hits == 0 for point in selected)
    lines = detail_lines(selected, limit=limit, scope=scope)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return missing


def common_args(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--annotated-dir", type=Path, required=True)
    parser.add_argument("--ip-filelist", type=Path, required=True)
    parser.add_argument("--common-filelist", type=Path, required=True)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    sub = parser.add_subparsers(dest="command", required=True)

    summary = sub.add_parser("summary")
    common_args(summary)
    summary.add_argument("--output", type=Path, required=True)
    summary.add_argument("--json-output", type=Path)

    detail = sub.add_parser("detail")
    common_args(detail)
    detail.add_argument("--scope", choices=SCOPES, default="design")
    detail.add_argument("--limit", type=int, default=0)
    detail.add_argument("--output", type=Path, required=True)

    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if not args.annotated_dir.is_dir():
        print(f"ERROR: annotated coverage directory not found: {args.annotated_dir}")
        return 2

    points = annotated_points(args.annotated_dir)
    if not points:
        print("ERROR: no annotated Verilator coverage points found")
        return 2

    ip_files = filelist_basenames(args.ip_filelist)
    common_files = filelist_basenames(args.common_filelist)

    if args.command == "summary":
        write_summary(
            points,
            ip_files=ip_files,
            common_files=common_files,
            output=args.output,
            json_output=args.json_output,
        )
        return 0

    missing = write_detail(
        points,
        scope=args.scope,
        ip_files=ip_files,
        common_files=common_files,
        limit=args.limit,
        output=args.output,
    )
    print(f"{ORANGE}[coverage_detail]{RESET} {WHITE}scope={args.scope}{RESET} {GRAY}uncovered={missing}{RESET}")
    print(f"{GRAY}log:{RESET} {WHITE}{args.output}{RESET}")
    print(f"{GRAY}annotated:{RESET} {WHITE}{args.annotated_dir}{RESET}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
