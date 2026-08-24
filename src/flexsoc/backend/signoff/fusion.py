"""Workload timing/power fusion engine for FlexSoC sign-off."""

from __future__ import annotations

from dataclasses import dataclass

import re
from pathlib import Path
from typing import Any, Mapping

from .power import _power_instance_rows
from .sta import (
    FLOAT_RE, PATH_PIN_RE, PATH_SLACK_RE, PATH_START_RE, SignoffContext,
    _common_init, _header, _quote, _returncode_text, _run_sta, _timing_values, _write,
)

def _timing_path_blocks(text: str) -> list[dict[str, Any]]:
    """Parse public ``report_checks`` text into paths and gate stages."""

    paths: list[dict[str, Any]] = []
    for block in PATH_START_RE.split(text):
        if not block.startswith("Startpoint:"):
            continue
        slack_match = PATH_SLACK_RE.search(block)
        if not slack_match:
            continue
        header: dict[str, str] = {}
        for key in ("Startpoint", "Endpoint", "Path Group", "Path Type"):
            match = re.search(rf"^{re.escape(key)}:\s*(.+)$", block, re.MULTILINE)
            header[key] = match.group(1).strip() if match else ""
        data = block.split("data arrival time", 1)[0]
        stages: list[dict[str, Any]] = []
        for line in data.splitlines():
            match = PATH_PIN_RE.match(line)
            if not match:
                continue
            prefix, _edge, pin, cell = match.groups()
            if "/" not in pin:
                continue
            numbers = [float(value) for value in FLOAT_RE.findall(prefix)]
            if not numbers:
                continue
            instance = pin.rsplit("/", 1)[0]
            if cell == "net":
                if stages and len(numbers) >= 2:
                    stages[-1]["fanout"], stages[-1]["capacitance"] = numbers[-2:]
                continue
            values: dict[str, float | None] = {
                "fanout": None,
                "capacitance": None,
                "slew": None,
                "delay": None,
                "arrival": None,
            }
            if len(numbers) >= 5:
                values.update(zip(values, numbers[-5:]))
            elif len(numbers) >= 3:
                values.update({"slew": numbers[-3], "delay": numbers[-2], "arrival": numbers[-1]})
            elif len(numbers) >= 2:
                values.update({"delay": numbers[-2], "arrival": numbers[-1]})
            if stages and stages[-1]["instance"] == instance:
                stage = stages[-1]
                stage["pins"].append(pin.rsplit("/", 1)[1])
                stage["cell"] = cell
                for key, value in values.items():
                    if value is not None:
                        stage[key] = value
            else:
                stages.append(
                    {
                        "instance": instance,
                        "cell": cell,
                        "pins": [pin.rsplit("/", 1)[1]],
                        **values,
                    }
                )
        paths.append(
            {
                "startpoint": header["Startpoint"],
                "endpoint": header["Endpoint"],
                "group": header["Path Group"],
                "type": header["Path Type"],
                "slack": float(slack_match.group(1)),
                "status": slack_match.group(2).lower(),
                "stages": stages,
                "raw": block.rstrip(),
            }
        )
    return paths

def _sta_pattern(name: str) -> str:
    """Escape one exact hierarchical name for OpenSTA collection patterns."""

    return re.sub(r"([\\*?\[\]])", r"\\\1", name)

def _fusion_detail_tcl(
    ctx: SignoffContext,
    instances: Sequence[str],
    hotspots: Sequence[str],
) -> tuple[str, str]:
    """Render a second public-API pass for instance power and hotspot paths."""

    delay_type = "min" if ctx.mode == "hold" else "max"
    marker = (
        f"FLEXSOC_FUSION_DETAIL_COMPLETE corner={ctx.corner} "
        f"mode={ctx.mode} workload={ctx.workload}"
    )
    instance_names = " ".join(_quote(name) for name in instances)
    instance_patterns = " ".join(_quote(_sta_pattern(name)) for name in instances)
    lines = [
        _header(
            ctx,
            (
                "This transient pass reports only selected path and hotspot instances.",
                "Only public report_power/report_checks collection commands are used.",
            ),
        ),
        _common_init(ctx, activity=True),
        "",
        f"set delay_type {delay_type}",
        f"set instance_names [list {instance_names}]",
        f"set instance_patterns [list {instance_patterns}]",
        "set instance_report [file join $report_dir .instance_power.rpt]",
        "set fp [open $instance_report w]",
        'puts $fp "# FlexSoC marked OpenSTA instance-power blocks"',
        "close $fp",
        "foreach instance_name $instance_names instance_pattern $instance_patterns {",
        "  # Resolve one exact hierarchical instance using the public get_cells collection command.",
        "  set instances [get_cells [list $instance_pattern]]",
        "  set fp [open $instance_report a]",
        '  puts $fp "=== FLEXSOC_INSTANCE $instance_name ==="',
        "  close $fp",
        "  if {[llength $instances] == 1} {",
        "    # Query average power for the resolved instance using the public report_power command.",
        "    flexsoc_append_opensta $instance_report report_power -instances $instances -digits 12",
        "  } else {",
        "    set fp [open $instance_report a]",
        '    puts $fp "instance_lookup_count=[llength $instances]"',
        "    close $fp",
        "  }",
        "}",
        "set hotspot_report [file join $report_dir .hotspot_paths.rpt]",
        "set hp [open $hotspot_report w]",
        'puts $hp "analysis=fusion_hotspot_paths"',
        "close $hp",
    ]
    for rank, name in enumerate(hotspots, 1):
        lines.extend(
            (
                "set hp [open $hotspot_report a]",
                f"puts $hp {_quote(f'=== HOTSPOT rank={rank} instance={name} ===')}",
                "close $hp",
                "# Resolve all pins of the hotspot instance so the timing query can require that the path passes through it.",
                f"set pins [get_pins [list {_quote(_sta_pattern(name) + '/*')}]]",
                "if {[llength $pins] == 0} {",
                "  set hp [open $hotspot_report a]",
                '  puts $hp "targeted_timing_path=instance_pins_not_found"',
                "  close $hp",
                "} else {",
                "  # Report the worst timing path through this power hotspot using the public report_checks command.",
                (
                    "  flexsoc_append_opensta $hotspot_report report_checks -through $pins -path_delay $delay_type "
                    "-group_path_count 1 -endpoint_path_count 1 -sort_by_slack "
                    "-format full_clock_expanded "
                    "-fields {slew capacitance input_pin net fanout} -digits 6"
                ),
                "}",
            )
        )
    lines.append(f"puts {_quote(marker)}")
    return "\n".join(lines), marker

def _fusion_power_tcl(
    ctx: SignoffContext,
    instances: Sequence[str],
) -> tuple[str, str]:
    """Render one transient public power query for additional path instances."""

    marker = (
        f"FLEXSOC_FUSION_POWER_COMPLETE corner={ctx.corner} "
        f"mode={ctx.mode} workload={ctx.workload}"
    )
    instance_names = " ".join(_quote(name) for name in instances)
    instance_patterns = " ".join(_quote(_sta_pattern(name)) for name in instances)
    return "\n".join(
        (
            _header(
                ctx,
                ("This transient pass reports power only for newly discovered path instances.",),
            ),
            _common_init(ctx, activity=True),
            f"set instance_names [list {instance_names}]",
            f"set instance_patterns [list {instance_patterns}]",
            "set instance_report [file join $report_dir .additional_power.rpt]",
            "set fp [open $instance_report w]",
            'puts $fp "# FlexSoC marked OpenSTA instance-power blocks"',
            "close $fp",
            "foreach instance_name $instance_names instance_pattern $instance_patterns {",
            "  # Resolve one newly discovered path instance using the public get_cells command.",
            "  set instances [get_cells [list $instance_pattern]]",
            "  set fp [open $instance_report a]",
            '  puts $fp "=== FLEXSOC_INSTANCE $instance_name ==="',
            "  close $fp",
            "  if {[llength $instances] == 1} {",
            "    # Query its average power using the public report_power command.",
            "    flexsoc_append_opensta $instance_report report_power -instances $instances -digits 12",
            "  } else {",
            "    set fp [open $instance_report a]",
            '    puts $fp "instance_lookup_count=[llength $instances]"',
            "    close $fp",
            "  }",
            "}",
            f"puts {_quote(marker)}",
        )
    ), marker

def _format_number(value: Any) -> str:
    return "-" if value is None else f"{float(value):.6g}"

def _path_fusion_lines(
    title: str,
    path: Mapping[str, Any],
    powers: Mapping[str, Mapping[str, Any]],
) -> list[str]:
    """Return one gate-by-gate timing/power table."""

    stages = path.get("stages", [])
    unique = {str(stage.get("instance", "")) for stage in stages}
    missing = sorted(name for name in unique if name not in powers)
    totals = {
        key: sum(float(powers.get(name, {}).get(key, 0.0)) for name in unique)
        for key in ("internal", "switching", "dynamic", "leakage", "total")
    }
    lines = [
        f"{title}: status={path.get('status')} slack={_format_number(path.get('slack'))} "
        f"type={path.get('type')} group={path.get('group')}",
        f"startpoint={path.get('startpoint')}",
        f"endpoint={path.get('endpoint')}",
        f"path_power_complete={'false' if missing else 'true'}"
        + (f" missing_power_instances={','.join(missing)}" if missing else ""),
        "path_average_power_sum "
        + " ".join(f"{key}={_format_number(value)}" for key, value in totals.items()),
        (
            "stage instance cell pins fanout capacitance slew delay arrival "
            "internal switching dynamic leakage total"
        ),
    ]
    for stage_index, stage in enumerate(stages, 1):
        power = powers.get(str(stage.get("instance", "")), {})
        lines.append(
            " ".join(
                (
                    str(stage_index),
                    str(stage.get("instance", "")),
                    str(stage.get("cell", "")),
                    ",".join(str(pin) for pin in stage.get("pins", [])),
                    _format_number(stage.get("fanout")),
                    _format_number(stage.get("capacitance")),
                    _format_number(stage.get("slew")),
                    _format_number(stage.get("delay")),
                    _format_number(stage.get("arrival")),
                    *(
                        _format_number(power.get(key))
                        for key in ("internal", "switching", "dynamic", "leakage", "total")
                    ),
                )
            )
        )
    return lines

def _hotspot_path_blocks(text: str) -> dict[str, dict[str, Any]]:
    """Parse the single worst public timing report emitted for each hotspot."""

    paths: dict[str, dict[str, Any]] = {}
    for block in re.split(r"(?=^=== HOTSPOT rank=)", text, flags=re.MULTILINE):
        marker = re.match(r"^=== HOTSPOT rank=\d+ instance=(.+?) ===", block)
        if not marker:
            continue
        parsed = _timing_path_blocks(block)
        if parsed:
            paths[marker.group(1)] = min(parsed, key=lambda path: float(path["slack"]))
    return paths

def _append_fusion_tables(
    report: Path,
    paths: Sequence[Mapping[str, Any]],
    powers: Mapping[str, Mapping[str, Any]],
    hotspots: Sequence[Mapping[str, Any]],
    hotspot_paths: Mapping[str, Mapping[str, Any]],
) -> None:
    """Append complete path tables and reverse hotspot-to-path lookup."""

    lines = [
        "",
        "=== Gate-level timing/power fusion ===",
        "power_semantics=average_instance_power_from_the_same_VCD_SAIF_context",
        "path_power_sum=unique_instance_average_power_sum_not_incremental_path_energy",
        "fanout_capacitance_source=OpenSTA_report_checks_output_pin_fields",
        "",
    ]
    for index, path in enumerate(paths, 1):
        lines.extend(_path_fusion_lines(f"Worst path {index}", path, powers))
        lines.append("")
    lines.extend(("=== Highest-power instances and worst path through each ===", ""))
    for rank, hotspot in enumerate(hotspots, 1):
        name = str(hotspot.get("instance", ""))
        memberships = sorted(
            {
                index
                for index, path in enumerate(paths, 1)
                if any(stage.get("instance") == name for stage in path.get("stages", []))
            }
        )
        lines.append(
            (
                f"Hotspot {rank}: instance={name} "
                f"selected_worst_paths={','.join(map(str, memberships)) or 'none'} "
            )
            + " ".join(
                f"{key}={_format_number(hotspot.get(key))}"
                for key in ("internal", "switching", "dynamic", "leakage", "total")
            )
        )
        targeted = hotspot_paths.get(name)
        if targeted:
            lines.extend(_path_fusion_lines("Worst path through hotspot", targeted, powers))
            lines.extend(("OpenSTA targeted timing report:", str(targeted.get("raw", ""))))
        else:
            lines.append("targeted_timing_path=not_found_or_unconstrained")
        lines.append("")
    report.write_text(
        report.read_text(encoding="utf-8").rstrip()
        + "\n"
        + "\n".join(lines).rstrip()
        + "\n",
        encoding="utf-8",
    )

def _enrich_fusion_report(
    project_root: Path,
    values: Mapping[str, str],
    ctx: SignoffContext,
    log: Path,
    *,
    progress_label: str,
    run_index: int,
    total_runs: int,
) -> dict[str, Any]:
    """Correlate worst paths and power hotspots using public OpenSTA commands."""

    report = ctx.report_dir / "fusion.rpt"
    paths = _timing_path_blocks(report.read_text(encoding="utf-8", errors="replace"))
    if not paths:
        raise ValueError(
            f"fusion discovery found no constrained timing paths; report={report}"
        )
    hotspots = sorted(
        _power_instance_rows(ctx.report_dir / ".highest_power.rpt"),
        key=lambda row: float(row["total"]),
        reverse=True,
    )[: ctx.power_top_instances]
    if ctx.power_top_instances > 0 and not hotspots:
        raise ValueError(
            "fusion discovery found no instance-power rows; "
            f"report={ctx.report_dir / '.highest_power.rpt'}"
        )
    initial_instances = sorted(
        {
            str(stage.get("instance", ""))
            for path in paths
            for stage in path.get("stages", [])
            if stage.get("instance")
        }
        | {str(row["instance"]) for row in hotspots}
    )
    if progress_label:
        print(
            f"[{progress_label}] run {run_index}/{total_runs} DISCOVERY PASS "
            f"paths={len(paths)} path_instances={len(initial_instances)} hotspots={len(hotspots)}",
            flush=True,
        )
        print(
            f"[{progress_label}] run {run_index}/{total_runs} HOTSPOT TIMING START "
            f"hotspots={len(hotspots)}",
            flush=True,
        )
    detail_script = ctx.report_dir / ".fusion_detail.tcl"
    detail_log = log.with_name(f"{log.stem}_detail{log.suffix}")
    script_text, marker = _fusion_detail_tcl(
        ctx,
        initial_instances,
        [str(row["instance"]) for row in hotspots],
    )
    _write(detail_script, script_text)
    rc = _run_sta(
        [values.get("STA", "sta"), "-exit", "-no_init", str(detail_script)],
        cwd=project_root,
        log=detail_log,
    )
    transcript = detail_log.read_text(encoding="utf-8", errors="replace") if detail_log.is_file() else ""
    if rc or marker not in transcript:
        raise ValueError(
            f"fusion detail pass failed with {_returncode_text(rc)}; log={detail_log}"
            if rc
            else f"fusion detail pass ended before completion marker; log={detail_log}"
        )
    power_rows = _power_instance_rows(ctx.report_dir / ".instance_power.rpt")
    power_map = {str(row["instance"]): row for row in power_rows}
    hotspots = [power_map.get(str(row["instance"]), row) for row in hotspots]
    hotspot_paths = _hotspot_path_blocks(
        (ctx.report_dir / ".hotspot_paths.rpt").read_text(
            encoding="utf-8", errors="replace"
        )
    )
    if progress_label:
        print(
            f"[{progress_label}] run {run_index}/{total_runs} HOTSPOT TIMING PASS "
            f"targeted_paths={len(hotspot_paths)} log={detail_log}",
            flush=True,
        )
    target_instances = {
        str(stage.get("instance", ""))
        for path in hotspot_paths.values()
        for stage in path.get("stages", [])
        if stage.get("instance")
    }
    additional = sorted(target_instances - power_map.keys())
    power_log: Path | None = None
    power_script: Path | None = None
    if additional:
        if progress_label:
            print(
                f"[{progress_label}] run {run_index}/{total_runs} POWER EXTEND START "
                f"instances={len(additional)}",
                flush=True,
            )
        power_script = ctx.report_dir / ".fusion_power.tcl"
        power_log = log.with_name(f"{log.stem}_power{log.suffix}")
        power_text, power_marker = _fusion_power_tcl(ctx, additional)
        _write(power_script, power_text)
        rc = _run_sta(
            [values.get("STA", "sta"), "-exit", "-no_init", str(power_script)],
            cwd=project_root,
            log=power_log,
        )
        transcript = power_log.read_text(encoding="utf-8", errors="replace") if power_log.is_file() else ""
        if rc or power_marker not in transcript:
            raise ValueError(
                f"fusion power extension failed with {_returncode_text(rc)}; log={power_log}"
                if rc
                else f"fusion power extension ended before completion marker; log={power_log}"
            )
        for row in _power_instance_rows(ctx.report_dir / ".additional_power.rpt"):
            power_map[str(row["instance"])] = row
        if progress_label:
            print(
                f"[{progress_label}] run {run_index}/{total_runs} POWER EXTEND PASS "
                f"instances={len(additional)} log={power_log}",
                flush=True,
            )
    _append_fusion_tables(report, paths, power_map, hotspots, hotspot_paths)
    for artifact in (
        ctx.report_dir / ".highest_power.rpt",
        ctx.report_dir / ".instance_power.rpt",
        ctx.report_dir / ".additional_power.rpt",
        ctx.report_dir / ".hotspot_paths.rpt",
        detail_script,
        power_script,
    ):
        if artifact is not None:
            artifact.unlink(missing_ok=True)
    if progress_label:
        print(
            f"[{progress_label}] run {run_index}/{total_runs} FUSION PASS "
            f"worst_paths={len(paths)} hotspot_paths={len(hotspot_paths)} report={report}",
            flush=True,
        )
    return {
        "timing_path_count": len(paths),
        "path_instance_count": len(power_map),
        "power_hotspot_count": len(hotspots),
        "hotspot_path_count": len(hotspot_paths),
        "detail_log": str(detail_log),
        "power_detail_log": str(power_log) if power_log else None,
    }

def render_fusion_analysis_tcl(ctx: SignoffContext) -> str:
    """Render discovery reports used by public-API timing/power fusion."""

    delay_type = "min" if ctx.mode == "hold" else "max"
    limitations = (
        "Timing and average power use the same netlist, corner, mode and activity trace.",
        "Per-cell values are average instance power, not incremental path energy.",
    )
    return "\n".join(
        [
            _header(ctx, limitations),
            _common_init(ctx, activity=True),
            "",
            f"set delay_type {delay_type}",
            f"set endpoint_path_limit {ctx.endpoint_path_limit}",
            "# Create the discovery report that keeps timing and power in the same netlist/corner/mode/activity context.",
            "set report [file join $report_dir fusion.rpt]",
            "set fp [open $report w]",
            f'puts $fp "analysis=fusion_analysis corner={ctx.corner} mode={ctx.mode} stage={ctx.stage}"',
            f'puts $fp "workload={ctx.workload}"',
            'puts $fp "methodology=staged_public_opensta"',
            'puts $fp "path_power_semantics=average_instance_power_in_same_analysis_context"',
            f'puts $fp "activity_file={ctx.activity_file or ""}"',
            f'puts $fp "activity_scope={ctx.activity_scope}"',
            'puts $fp "liberty=$liberty"',
            'puts $fp "netlist=$netlist"',
            'puts $fp "sdc=$sdc"',
            'puts $fp "spef=$spef"',
            "close $fp",
            "flexsoc_section $report Units",
            "# Record units once so timing and power values can be interpreted together.",
            "flexsoc_append_opensta $report report_units",
            "flexsoc_section $report {Constraint validation}",
            "# Re-check the timing setup before correlating paths with power.",
            "flexsoc_append_opensta $report check_setup -verbose",
            "flexsoc_section $report {Timing summary}",
            'flexsoc_label $report "wns $delay_type"',
            "# Record worst negative slack for this setup/hold mode.",
            "flexsoc_append_opensta $report report_wns -$delay_type",
            'flexsoc_label $report "tns $delay_type"',
            "# Record total negative slack for the same mode and corner.",
            "flexsoc_append_opensta $report report_tns -$delay_type",
            "flexsoc_section $report {Power summary}",
            "# Report design-average power using the already annotated GLS activity trace.",
            "flexsoc_append_opensta $report report_power",
            "flexsoc_section $report {Worst timing paths (violated or met)}",
            "# Discover the worst paths even when timing is met; Python later correlates their gates with instance power.",
            (
                "flexsoc_append_opensta $report report_checks -path_delay $delay_type "
                "-group_path_count $endpoint_path_limit -endpoint_path_count 1 "
                "-unique_paths_to_endpoint -sort_by_slack "
                "-format full_clock_expanded "
                "-fields {slew capacitance input_pin net fanout} -digits 6"
            ),
            "# Collect public per-instance power rows; Python ranks the hottest instances for the second fusion pass.",
            "set highest_power_report [file join $report_dir .highest_power.rpt]",
            "file delete -force $highest_power_report",
            "set all_instances [get_cells -hierarchical *]",
            "flexsoc_append_opensta $highest_power_report report_power -instances $all_instances -digits 12",
            'puts "report=$report"',
        ]
    )


@dataclass(slots=True)
class FusionAnalysis:
    """Correlate timing paths and workload power in aligned scenarios."""

    project_root: Path
    values: Mapping[str, str]
    runner: object | None = None

    def setup(self) -> Path:
        """Generate only the fusion Tcl template."""

        from .sta import generate_family
        return generate_family(self.project_root, self.values, "fusion_analysis")

    def run(self, *, all_workloads: bool = False, on: str = "local") -> int:
        """Run one or all aligned timing/power fusion analyses."""

        from .power import execute_activity
        return execute_activity(
            "fusion_analysis",
            "all" if all_workloads else "run",
            self.project_root,
            self.values,
            runner=self.runner,
            on=on,
        )
