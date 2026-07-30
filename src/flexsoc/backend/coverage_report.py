"""Print uncovered Verilator coverage points from annotated sources."""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path

RESET = "\033[0m"
RED = "\033[31m"
YELLOW = "\033[33m"
BLUE = "\033[34m"

ANNOTATION_RE = re.compile(r"^(?P<status>[ %~+-])(?P<hits>\d+)\s+(?P<body>.*)$")
POINT_RE = re.compile(r"^point:\s+type=(?P<kind>\S+)(?:\s+comment=(?P<comment>.*))?$")


@dataclass(frozen=True)
class MissingPoint:
    path: str
    line: int
    kind: str
    hits: int
    detail: str


def annotated_missing_points(root: Path) -> list[MissingPoint]:
    """Return zero-hit points from Verilator --annotate-points output."""

    points: list[MissingPoint] = []
    for path in sorted(item for item in root.rglob("*") if item.is_file()):
        rel = path.relative_to(root).as_posix()
        source_line = 0
        source_detail = ""
        bad_source: dict[int, tuple[str, int, str]] = {}
        point_lines: set[int] = set()

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
                if status in {"%", "~"}:
                    bad_source[source_line] = (status, hits, body)
                continue

            if status != "-" or source_line == 0:
                continue

            point_lines.add(source_line)
            point = POINT_RE.match(body)
            if point:
                kind = point.group("kind")
                detail = (point.group("comment") or source_detail).strip()
            else:
                kind = "point"
                detail = body

            points.append(MissingPoint(rel, source_line, kind, hits, detail))

        for line, (status, hits, detail) in bad_source.items():
            if line in point_lines:
                continue
            kind = "partial-line" if status == "~" else "line"
            points.append(MissingPoint(rel, line, kind, hits, detail))

    return sorted(points, key=lambda point: (point.path, point.line, point.kind, point.detail))


def _shorten(text: str, width: int) -> str:
    if len(text) <= width:
        return text
    return text[: max(1, width - 1)] + "…"


def print_missing_points(points: list[MissingPoint], *, limit: int) -> None:
    """Print a compact colored table of uncovered coverage points."""

    print(f"\n{BLUE}Coverage detail — uncovered points{RESET}")
    if not points:
        print(f"{BLUE}No zero-hit coverage points found.{RESET}")
        return

    shown = points if limit <= 0 else points[:limit]
    path_width = min(48, max(len("File"), *(len(point.path) for point in shown)))
    kind_width = min(18, max(len("Type"), *(len(point.kind) for point in shown)))
    detail_width = 64

    header = (
        f"{'File':<{path_width}}  {'Line':>6}  "
        f"{'Type':<{kind_width}}  {'Hits':>6}  Detail"
    )
    print(header)
    print("-" * min(140, len(header) + detail_width))
    for point in shown:
        color = RED if point.hits == 0 else YELLOW
        print(
            color
            + f"{_shorten(point.path, path_width):<{path_width}}  "
            + f"{point.line:>6}  "
            + f"{_shorten(point.kind, kind_width):<{kind_width}}  "
            + f"{point.hits:>6}  "
            + _shorten(point.detail, detail_width)
            + RESET
        )

    if len(shown) < len(points):
        print(
            f"{YELLOW}Showing {len(shown)} of {len(points)} uncovered points. "
            "Use --set COVERAGE_DETAIL_LIMIT=0 to print all.{RESET}"
        )
    else:
        print(f"{RED}Uncovered points: {len(points)}{RESET}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--annotated-dir", type=Path, required=True)
    parser.add_argument("--limit", type=int, default=200)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if not args.annotated_dir.is_dir():
        print(f"ERROR: annotated coverage directory not found: {args.annotated_dir}")
        return 2

    print_missing_points(
        annotated_missing_points(args.annotated_dir),
        limit=args.limit,
    )
    print(f"{BLUE}Annotated sources: {args.annotated_dir}{RESET}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
