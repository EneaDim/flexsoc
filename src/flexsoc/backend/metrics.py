"""Collect compact machine-readable metrics from one FlexSoC run."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path
from typing import Any, Sequence

from rich.console import Console
from rich.table import Table


LINT_KINDS = ("latch", "undriven", "width", "unconnected", "unused")
FLOAT = r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?"


def read_text(path: Path) -> str:
    """Read a text artifact without failing on tool-specific encoding noise."""

    return path.read_text(encoding="utf-8", errors="replace")


def line_count(path: Path) -> int:
    """Count non-empty lines in a generated diagnostic file."""

    if not path.is_file():
        return 0
    return sum(1 for line in read_text(path).splitlines() if line.strip())


def latest(paths: Sequence[Path]) -> Path | None:
    """Return the newest existing path."""

    existing = [path for path in paths if path.is_file()]
    return max(existing, key=lambda path: path.stat().st_mtime) if existing else None


def last_number(pattern: str, text: str, cast: type[int] | type[float]) -> int | float | None:
    """Return the last numeric regex match."""

    matches = re.findall(pattern, text, flags=re.IGNORECASE | re.MULTILINE)
    return cast(matches[-1]) if matches else None


def relative(path: Path, run_dir: Path) -> str:
    """Return a stable run-relative artifact path."""

    return path.resolve().relative_to(run_dir.resolve()).as_posix()


def marked_section(text: str, start: str, end: str) -> str:
    """Return text between two explicit report markers."""

    if start not in text or end not in text:
        return ""
    return text.split(start, 1)[1].split(end, 1)[0]


def collect_lint(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect diagnostics from the latest lint-suite outputs."""

    log_dir = run_dir / "logs" / "lint"
    full_log = log_dir / f"{top}_lint_all.log"
    raw_log = log_dir / "raw" / f"{top}_lint_all_raw.log"
    if not full_log.is_file():
        return None

    text = read_text(full_log)
    command = read_text(raw_log).splitlines()[0] if raw_log.is_file() else ""
    tool = "slang" if "slang" in command else "verilator" if "verilator" in command else "unknown"

    diagnostics: dict[str, int] = {}
    for kind in LINT_KINDS:
        path = log_dir / f"{top}_lint_{kind}_all.log"
        kind_text = read_text(path) if path.is_file() else ""
        diagnostics[kind] = 0 if kind_text.startswith("No ") else line_count(path)

    warnings = len(re.findall(r"(?:%Warning-|\bwarning:)", text, flags=re.IGNORECASE))
    errors = len(re.findall(r"(?:%Error-|\berror:)", text, flags=re.IGNORECASE))
    return {
        "tool": tool,
        "errors": errors,
        "warnings": warnings,
        "diagnostics": diagnostics,
        "log": relative(full_log, run_dir),
    }


def synthesis_diagnostic_count(text: str, severity: str) -> int:
    """Count real Yosys or Slang diagnostics, not signal names containing error/warning."""

    label = "Warning" if severity == "warning" else "ERROR"
    slang = severity.lower()
    pattern = (
        rf"^(?:{label}:|%{label.capitalize()}-|"
        rf".+:\d+(?::\d+)?:\s*{slang}:)"
    )
    return len(re.findall(pattern, text, flags=re.IGNORECASE | re.MULTILINE))


def yosys_statistics(top: str, text: str) -> dict[str, Any]:
    """Parse the top-module table printed by Yosys `stat -liberty`."""

    headers = list(re.finditer(r"^===\s+(.+?)\s+===$", text, flags=re.MULTILINE))
    section = ""
    for index, header in enumerate(headers):
        module = header.group(1).strip().lstrip("\\")
        if module != top:
            continue
        end = headers[index + 1].start() if index + 1 < len(headers) else len(text)
        section = text[header.end() : end]

    source = section
    fields = {
        "wires": r"^\s*(\d+)\s+-\s+wires\s*$",
        "wire_bits": r"^\s*(\d+)\s+-\s+wire bits\s*$",
        "public_wires": r"^\s*(\d+)\s+-\s+public wires\s*$",
        "public_wire_bits": r"^\s*(\d+)\s+-\s+public wire bits\s*$",
        "ports": r"^\s*(\d+)\s+-\s+ports\s*$",
        "port_bits": r"^\s*(\d+)\s+-\s+port bits\s*$",
    }
    stats: dict[str, Any] = {}
    for name, pattern in fields.items():
        value = last_number(pattern, source, int)
        if value is not None:
            stats[name] = value

    cells = re.search(
        r"^\s*(\d+)\s+(?:" + FLOAT + r")\s+cells\s*$",
        source,
        flags=re.MULTILINE,
    )
    if cells:
        stats["cells"] = int(cells.group(1))
    else:
        legacy_cells = last_number(r"^\s*Number of cells:\s*(\d+)\s*$", text, int)
        if legacy_cells is not None:
            stats["cells"] = legacy_cells

    area_source = source or text
    area = last_number(
        r"^\s*Chip area for module .*?:\s*(" + FLOAT + r")\s*$",
        area_source,
        float,
    )
    if area is not None:
        stats["area"] = area
        stats["area_unit"] = "liberty"

    sequential = re.search(
        r"^\s*of which used for sequential elements:\s*("
        + FLOAT
        + r")\s+\(("
        + FLOAT
        + r")%\)\s*$",
        source,
        flags=re.MULTILINE,
    )
    if sequential:
        stats["sequential_area"] = float(sequential.group(1))
        stats["sequential_area_pct"] = float(sequential.group(2))

    cell_types: dict[str, dict[str, int | float]] = {}
    for count, cell_area, cell_type in re.findall(
        r"^\s*(\d+)\s+(" + FLOAT + r")\s+(\S+)\s*$",
        source,
        flags=re.MULTILINE,
    ):
        if cell_type == "cells":
            continue
        cell_types[cell_type] = {"count": int(count), "area": float(cell_area)}
    if cell_types:
        stats["cell_types"] = cell_types
    return stats


def collect_synthesis(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect useful statistics from the latest Yosys synthesis log."""

    log_dir = run_dir / "logs" / "synthesis"
    log = latest(tuple(log_dir.glob(f"{top}_synth_opt_*.log")))
    if log is None:
        return None

    text = read_text(log)
    prefix = f"{top}_synth_opt_"
    strategy = log.stem[len(prefix) :] if log.stem.startswith(prefix) else "unknown"
    data: dict[str, Any] = {
        "strategy": strategy,
        "warnings": synthesis_diagnostic_count(text, "warning"),
        "errors": synthesis_diagnostic_count(text, "error"),
        "log": relative(log, run_dir),
    }
    data.update(yosys_statistics(top, text))
    return data


def collect_sta(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect timing summary metrics for every available OpenSTA scenario."""

    log_dir = run_dir / "logs" / "signoff"
    prefix = f"{top}_sta_"
    scenarios: dict[str, dict[str, Any]] = {}

    for log in sorted(log_dir.glob(f"{top}_sta_*.log")):
        stem = log.stem
        if not stem.startswith(prefix):
            continue
        name = stem[len(prefix) :]
        if "_" not in name:
            continue
        corner, mode = name.rsplit("_", 1)
        if mode not in {"setup", "hold"}:
            continue

        text = read_text(log)
        wns = last_number(r"^\s*wns\s+(" + FLOAT + r")\s*$", text, float)
        tns = last_number(r"^\s*tns\s+(" + FLOAT + r")\s*$", text, float)
        unconstrained = marked_section(
            text,
            "=== flexsoc unconstrained paths ===",
            "=== flexsoc unconstrained paths end ===",
        )
        data: dict[str, Any] = {
            "reported_violating_paths": len(re.findall(r"slack\s*\(VIOLATED\)", text, flags=re.IGNORECASE)),
            "reported_unconstrained_paths": len(re.findall(r"^Startpoint:", unconstrained, flags=re.MULTILINE)),
            "log": relative(log, run_dir),
        }
        if wns is not None:
            data["wns"] = wns
        if tns is not None:
            data["tns"] = tns
        scenarios.setdefault(corner, {})[mode] = data

    return scenarios or None


def collect_power_estimate(top: str, run_dir: Path) -> dict[str, Any] | None:
    """Collect global-activity power estimates for every available corner."""

    log_dir = run_dir / "logs" / "signoff"
    prefix = f"{top}_power_estimate_"
    corners: dict[str, Any] = {}
    activity: float | None = None
    duty: float | None = None

    for log in sorted(log_dir.glob(f"{top}_power_estimate_*.log")):
        if not log.stem.startswith(prefix):
            continue
        corner = log.stem[len(prefix) :]
        text = read_text(log)

        assumption = re.search(
            r"analysis=estimate\s+activity_source=global\s+activity=("
            + FLOAT
            + r")\s+transitions_per_cycle\s+duty=("
            + FLOAT
            + r")",
            text,
        )
        if assumption:
            activity = float(assumption.group(1))
            duty = float(assumption.group(2))

        total = re.search(
            r"^\s*Total\s+("
            + FLOAT
            + r")\s+("
            + FLOAT
            + r")\s+("
            + FLOAT
            + r")\s+("
            + FLOAT
            + r")",
            text,
            flags=re.MULTILINE,
        )
        data: dict[str, Any] = {"log": relative(log, run_dir)}
        if total:
            internal, switching, leakage, overall = (float(value) for value in total.groups())
            data.update(
                {
                    "internal_w": internal,
                    "switching_w": switching,
                    "leakage_w": leakage,
                    "total_w": overall,
                }
            )
        corners[corner] = data

    if not corners:
        return None

    result: dict[str, Any] = {
        "analysis": "estimate",
        "activity_source": "global",
        "corners": corners,
    }
    if activity is not None:
        result["activity_transitions_per_cycle"] = activity
    if duty is not None:
        result["duty"] = duty
    return result


def collect_metrics(top: str, run_dir: Path) -> dict[str, Any]:
    """Collect the metrics currently available in a run."""

    metrics: dict[str, Any] = {"schema_version": 2, "top": top}
    for name, collector in (
        ("lint", collect_lint),
        ("synthesis", collect_synthesis),
        ("sta", collect_sta),
        ("power_estimate", collect_power_estimate),
    ):
        data = collector(top, run_dir)
        if data is not None:
            metrics[name] = data
    return metrics




def count_color(value: int, *, error: bool = False) -> str:
    """Color zero counts green and non-zero counts by severity."""

    if value == 0:
        return "green"
    return "red" if error else "yellow"


def timing_color(value: float) -> str:
    """Color timing slack by sign without applying a quality policy."""

    return "green" if value >= 0 else "red"


def metric_table() -> Table:
    """Return one compact two-column metrics table."""

    table = Table(show_header=False, box=None, pad_edge=False)
    table.add_column("Metric", style="dim", no_wrap=True)
    table.add_column("Value")
    return table


def show_metrics(path: Path) -> None:
    """Print one aligned colored summary of metrics.json."""

    if not path.is_file():
        raise FileNotFoundError(f"metrics file not found: {path}; run: fx metrics")

    data = json.loads(path.read_text(encoding="utf-8"))
    console = Console()
    console.print(f"[bold cyan]FlexSoC metrics[/bold cyan] — {data.get('top', 'unknown')}")

    lint = data.get("lint")
    if lint:
        console.print("\n[bold]Lint[/bold]")
        table = metric_table()
        errors = int(lint.get("errors", 0))
        warnings = int(lint.get("warnings", 0))
        table.add_row("Tool", str(lint.get("tool", "unknown")))
        table.add_row("Errors", f"[{count_color(errors, error=True)}]{errors}[/]")
        table.add_row("Warnings", f"[{count_color(warnings)}]{warnings}[/]")
        for name, count in lint.get("diagnostics", {}).items():
            if count:
                table.add_row(name.replace("_", " ").title(), f"[yellow]{count}[/yellow]")
        console.print(table)

    synthesis = data.get("synthesis")
    if synthesis:
        console.print("\n[bold]Synthesis[/bold]")
        table = metric_table()
        errors = int(synthesis.get("errors", 0))
        warnings = int(synthesis.get("warnings", 0))
        table.add_row("Strategy", str(synthesis.get("strategy", "unknown")))
        for label, key in (
            ("Wires", "wires"),
            ("Wire bits", "wire_bits"),
            ("Public wires", "public_wires"),
            ("Public wire bits", "public_wire_bits"),
            ("Ports", "ports"),
            ("Port bits", "port_bits"),
            ("Cells", "cells"),
        ):
            if key in synthesis:
                table.add_row(label, str(synthesis[key]))
        total_area = float(synthesis.get("area", 0.0) or 0.0)
        if total_area:
            table.add_row("Area", f"{total_area:.3f} liberty")
        if "sequential_area" in synthesis:
            sequential_area = float(synthesis["sequential_area"])
            pct = synthesis.get("sequential_area_pct")
            value = f"{sequential_area:.3f} liberty"
            if pct is not None:
                value += f" ({float(pct):.2f}%)"
            table.add_row("Sequential area", value)
            if total_area >= sequential_area:
                combinational_area = total_area - sequential_area
                combinational_pct = 100.0 * combinational_area / total_area if total_area else 0.0
                table.add_row(
                    "Combinational area",
                    f"{combinational_area:.3f} liberty ({combinational_pct:.2f}%)",
                )
        cell_types = synthesis.get("cell_types", {})
        if cell_types:
            table.add_row("Cell types", str(len(cell_types)))
        table.add_row("Errors", f"[{count_color(errors, error=True)}]{errors}[/]")
        table.add_row("Warnings", f"[{count_color(warnings)}]{warnings}[/]")
        console.print(table)

        if cell_types:
            ranked = sorted(
                cell_types.items(),
                key=lambda item: float(item[1].get("area", 0.0)),
                reverse=True,
            )[:8]
            console.print("[bold]Top cell types by area[/bold]")
            cells = Table(box=None, pad_edge=False)
            cells.add_column("Cell type")
            cells.add_column("Count", justify="right")
            cells.add_column("Area", justify="right")
            cells.add_column("Area %", justify="right")
            for cell_type, values in ranked:
                cell_area = float(values.get("area", 0.0))
                pct = 100.0 * cell_area / total_area if total_area else 0.0
                cells.add_row(
                    cell_type,
                    str(values.get("count", "-")),
                    f"{cell_area:.3f}",
                    f"{pct:.2f}%",
                )
            console.print(cells)

    sta = data.get("sta")
    if sta:
        console.print("\n[bold]STA[/bold]")
        table = Table(box=None, pad_edge=False)
        table.add_column("Corner")
        table.add_column("Mode")
        table.add_column("WNS", justify="right")
        table.add_column("TNS", justify="right")
        table.add_column("Reported viol.", justify="right")
        table.add_column("Unconstrained", justify="right")
        for corner, modes in sta.items():
            for mode, values in modes.items():
                wns = values.get("wns")
                tns = values.get("tns")
                wns_text = "-" if wns is None else f"[{timing_color(float(wns))}]{wns}[/]"
                tns_text = "-" if tns is None else f"[{timing_color(float(tns))}]{tns}[/]"
                violating = int(values.get("reported_violating_paths", 0))
                unconstrained = int(values.get("reported_unconstrained_paths", 0))
                table.add_row(
                    corner,
                    mode,
                    wns_text,
                    tns_text,
                    f"[{count_color(violating)}]{violating}[/]",
                    f"[{count_color(unconstrained)}]{unconstrained}[/]",
                )
        console.print(table)

    power = data.get("power_estimate")
    if power:
        activity = power.get("activity_transitions_per_cycle", "-")
        duty = power.get("duty", "-")
        console.print(
            f"\n[bold]Power estimate[/bold]  "
            f"activity={activity} transitions/cycle  duty={duty}"
        )
        table = Table(box=None, pad_edge=False)
        table.add_column("Corner")
        table.add_column("Total W", justify="right")
        table.add_column("Internal W", justify="right")
        table.add_column("Switching W", justify="right")
        table.add_column("Leakage W", justify="right")
        for corner, values in power.get("corners", {}).items():
            table.add_row(
                corner,
                str(values.get("total_w", "-")),
                str(values.get("internal_w", "-")),
                str(values.get("switching_w", "-")),
                str(values.get("leakage_w", "-")),
            )
        console.print(table)


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    """Parse the small metrics collector CLI."""

    parser = argparse.ArgumentParser(description="Collect or display FlexSoC run metrics.")
    parser.add_argument("--top")
    parser.add_argument("--run-dir", type=Path)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--show", type=Path)
    args = parser.parse_args(argv)
    if args.show is None and not all((args.top, args.run_dir, args.output)):
        parser.error("collection requires --top, --run-dir, and --output")
    return args


def main(argv: Sequence[str] | None = None) -> int:
    """Write one deterministic metrics.json file."""

    args = parse_args(argv)
    if args.show is not None:
        try:
            show_metrics(args.show)
        except (FileNotFoundError, json.JSONDecodeError) as exc:
            print(f"ERROR: {exc}")
            return 2
        return 0

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(
        json.dumps(collect_metrics(args.top, args.run_dir), indent=2) + "\n",
        encoding="utf-8",
    )
    print(f"[metrics] output: {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
