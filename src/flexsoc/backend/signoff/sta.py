"""Static timing, SDC and SDF engine shared by pre/post sign-off."""

from __future__ import annotations

import json
import os
import re
import signal
import shutil
import sys
from dataclasses import dataclass, replace
from pathlib import Path
from typing import Any, Mapping, Sequence

from flexsoc.backend.core import PDKRunLayout
from flexsoc.backend.core.render.templates import templates
from flexsoc.backend.core.runtime.execution import CommandRequest, ToolRunner, Terminal
from flexsoc.backend.impl import ImplementationFlow

SIGNOFF_SCENARIOS = {
    "ff": "min",
    "tt": "typ",
    "ss": "max",
}
SDF_MODE_TO_CORNER = {mode: corner for corner, mode in SIGNOFF_SCENARIOS.items()}
SDF_MODES = tuple(SDF_MODE_TO_CORNER)
ANALYSES = ("sta", "power_estimate", "power_analysis", "fusion_analysis")
POWER_RE = re.compile(
    r"^\s*Total\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)",
    re.MULTILINE,
)
ACTIVITY_RE = re.compile(r"Annotated\s+(\d+)\s+(?:pin\s+)?activities", re.IGNORECASE)
ACTIVITY_PERCENT_RE = re.compile(r"^annotated_percent=([0-9]+(?:\.[0-9]+)?)%\s*$", re.MULTILINE)
WNS_RE = re.compile(r"^\s*wns(?:\s+\w+)?\s+([-+0-9.eE]+)\s*$", re.IGNORECASE | re.MULTILINE)
TNS_RE = re.compile(r"^\s*tns(?:\s+\w+)?\s+([-+0-9.eE]+)\s*$", re.IGNORECASE | re.MULTILINE)
COMPLETE_PREFIX = "FLEXSOC_SIGNOFF_COMPLETE"
FLOAT_RE = re.compile(r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?")
PATH_START_RE = re.compile(r"(?=^Startpoint:)", re.MULTILINE)
PATH_PIN_RE = re.compile(r"^\s*(.*?)\s+([\^v])?\s*(\S+)\s+\(([^)]+)\)\s*$")
PATH_SLACK_RE = re.compile(
    r"^\s*(%s)\s+slack\s+\((MET|VIOLATED)\)" % FLOAT_RE.pattern,
    re.MULTILINE,
)
UNCONSTRAINED_ENDPOINT_RE = re.compile(
    r"\bThere (?:is|are)\s+(\d+)\s+unconstrained endpoints?\b", re.IGNORECASE
)


@dataclass(frozen=True, slots=True)
class SignoffContext:
    """Resolved inputs for one concrete OpenSTA script."""

    analysis: str
    design: str
    variant: str
    pdk: str
    stage: str
    corner: str
    mode: str
    workload: str
    top: str
    liberty: Path
    macro_liberties: tuple[Path, ...]
    netlist: Path
    sdc: Path
    report_dir: Path
    spef: Path | None = None
    activity_file: Path | None = None
    activity_scope: str = ""
    gls_report: Path | None = None
    estimated_activity: float = 0.1
    estimated_duty: float = 0.5
    global_activity: bool = False
    endpoint_group_limit: int = 10000
    endpoint_path_limit: int = 10
    near_critical_setup: float = 0.200
    near_critical_hold: float = 0.100
    power_top_instances: int = 20


@dataclass(frozen=True, slots=True)
class TimingScenario:
    """One explicit STA scenario: analysis mode plus resolved timing view."""

    name: str
    corner: str
    mode: str
    liberty: Path
    stage: str


@dataclass(slots=True)
class StaAnalysis:
    """Generate and execute STA/SDF collateral from authored SDC intent."""

    project_root: Path
    values: Mapping[str, str]
    runner: object | None = None

    def setup_sta(self) -> Path:
        """Generate only the canonical STA Tcl template."""

        return StaAnalysis.generate_family(self.project_root, self.values, "sta")

    def setup_sdf(self) -> Path:
        """Generate only the canonical SDF Tcl template."""

        return StaAnalysis.generate_family(self.project_root, self.values, "sdf")

    def run_sta(self, *, on: str = "local") -> int:
        """Run all configured setup/hold timing scenarios."""

        return StaAnalysis.execute_static("sta", self.project_root, self.values, runner=self.runner, on=on)

    def write_sdf(self, *, on: str = "local") -> int:
        """Write SDF for all configured corners."""

        return StaAnalysis.execute_static("sdf", self.project_root, self.values, runner=self.runner, on=on)

    @staticmethod
    def scenario_corner(timing_mode: str) -> str:
        """Return the Liberty corner aligned with one SDF timing mode."""

        try:
            return SDF_MODE_TO_CORNER[timing_mode]
        except KeyError as exc:
            raise ValueError(
                f"no sign-off scenario for timing mode {timing_mode!r}; "
                f"expected one of {tuple(SDF_MODE_TO_CORNER)}"
            ) from exc

    @staticmethod
    def timing_scenarios(
        values: Mapping[str, str], liberties: Mapping[str, Path], stage: str
    ) -> tuple[TimingScenario, ...]:
        """Return deterministic setup/hold scenarios without inventing PDK views."""

        corners = StaAnalysis._selection(
            values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
        )
        modes = StaAnalysis._selection(values.get("STA_MODES"), "setup hold", ("setup", "hold"), "STA mode")
        return tuple(
            TimingScenario(f"{mode}_{corner}", corner, mode, liberties[corner], stage)
            for corner in corners
            for mode in modes
        )

    @staticmethod
    def liberty_corner(path: Path) -> str:
        """Infer ``ss``, ``tt`` or ``ff`` from a Liberty filename."""

        name = path.name.lower()
        aliases = {
            "ss": ("ss", "slow", "worst"),
            "tt": ("tt", "typ", "typical"),
            "ff": ("ff", "fast", "best"),
        }
        for corner, tokens in aliases.items():
            for token in tokens:
                if (
                    f"__{token}_" in name
                    or f"_{token}_" in name
                    or name.startswith(f"{token}_")
                    or name.startswith(f"nom_{token}_")
                ):
                    return corner
        return path.stem

    @staticmethod
    def _quote(path: Path | str) -> str:
        """Return a Tcl brace-quoted value."""

        return "{" + str(path).replace("}", "\\}") + "}"

    @staticmethod
    def _write(path: Path, text: str) -> Path:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text.rstrip() + "\n", encoding="utf-8")
        return path

    @staticmethod
    def _require_file(path: Path, label: str) -> Path:
        path = path.expanduser().resolve()
        if not path.is_file():
            raise ValueError(f"missing {label}: {path}")
        return path

    @staticmethod
    def _optional_file(path: Path | None, label: str) -> Path | None:
        if path is None:
            return None
        return StaAnalysis._require_file(path, label)

    @staticmethod
    def _split(value: str | None) -> tuple[str, ...]:
        return tuple(item.strip() for item in str(value or "").replace(",", " ").split() if item.strip())

    @staticmethod
    def _truth(value: str | None) -> bool:
        return str(value or "").strip().lower() in {"1", "true", "yes", "on"}

    @staticmethod
    def _selection(
        value: str | None, default: str, allowed: Sequence[str], label: str
    ) -> tuple[str, ...]:
        selected = StaAnalysis._split(value or default)
        if not selected:
            raise ValueError(f"{label} must select at least one value")
        unknown = tuple(item for item in selected if item not in allowed)
        if unknown:
            raise ValueError(f"unsupported {label}: {unknown}; allowed={tuple(allowed)}")
        if len(set(selected)) != len(selected):
            raise ValueError(f"duplicate {label}: {selected}")
        return selected

    @staticmethod
    def _live() -> bool:
        return StaAnalysis._truth(os.environ.get("FLEXSOC_LIVE"))

    @staticmethod
    def _paths(value: str | None) -> tuple[Path, ...]:
        return tuple(Path(item).expanduser().resolve() for item in StaAnalysis._split(value))

    @staticmethod
    def _liberties(values: Mapping[str, str]) -> dict[str, Path]:
        paths = [path for path in StaAnalysis._paths(values.get("LIBS")) if path.is_file()]
        lib_syn = Path(values["LIB_SYN"]).expanduser().resolve() if values.get("LIB_SYN") else None
        if lib_syn and lib_syn.is_file() and lib_syn not in paths:
            paths.append(lib_syn)
        corners: dict[str, Path] = {}
        for path in paths:
            corner = StaAnalysis.liberty_corner(path)
            if corner in {"ss", "tt", "ff"}:
                corners.setdefault(corner, path)
        if not corners:
            raise ValueError("no ss/tt/ff Liberty views resolved for OpenSTA sign-off")
        return {corner: corners[corner] for corner in ("ss", "tt", "ff") if corner in corners}

    @staticmethod
    def _load_json(path: Path) -> dict[str, Any]:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            raise ValueError(f"invalid JSON artifact {path}: {exc}") from exc
        if not isinstance(data, dict):
            raise ValueError(f"invalid JSON object: {path}")
        return data

    @staticmethod
    def _selector(values: Mapping[str, str], plural: str, singular: str, default: str) -> tuple[str, ...]:
        raw = values.get(plural) or values.get(singular) or default
        return StaAnalysis._split(raw)

    @staticmethod
    def _run_sta(
        command: Sequence[str], *, cwd: Path, log: Path, runner=None, on: str = "local",
        inputs: Sequence[Path] = (), outputs: Sequence[Path] = (),
    ) -> int:
        """Run OpenSTA through the configured execution backend."""

        active_runner = runner or ToolRunner(project_root=cwd)
        callback = StaAnalysis._stream_line if StaAnalysis._live() else None

        request = CommandRequest(
            tuple(command), cwd, {}, log, inputs=tuple(inputs), outputs=tuple(outputs),
            line_callback=callback,
        )
        return active_runner.run(request, on=on).returncode


    @staticmethod
    def _stream_line(line: str) -> None:
        sys.stdout.write(line)
        sys.stdout.flush()

    @staticmethod
    def _returncode_text(returncode: int) -> str:
        if returncode >= 0:
            return f"exit {returncode}"
        number = -returncode
        try:
            name = signal.Signals(number).name
        except ValueError:
            name = "UNKNOWN"
        return f"signal {number} ({name})"

    @staticmethod
    def _report_section(text: str, start: str, end: str) -> str:
        """Return one generated report section, or the full unsectioned report."""

        if start not in text:
            return text
        section = text.split(start, 1)[1]
        if not end:
            return section
        return section.split(end, 1)[0] if end in section else section

    @staticmethod
    def _unconstrained_endpoint_count(text: str) -> int:
        """Return the real unconstrained endpoint count reported by ``check_setup``."""

        section = StaAnalysis._report_section(text, "=== Constraint validation ===", "=== Violating paths ===")
        match = UNCONSTRAINED_ENDPOINT_RE.search(section)
        return int(match.group(1)) if match else 0

    @staticmethod
    def _timing_values(text: str) -> dict[str, float]:
        """Extract WNS/TNS and recover WNS from explicit violating path slack."""

        values: dict[str, float] = {}
        for name, pattern in (("wns", WNS_RE), ("tns", TNS_RE)):
            match = pattern.search(text)
            if match:
                values[name] = float(match.group(1))
        if "wns" not in values:
            section = StaAnalysis._report_section(text, "=== Violating paths ===", "=== Near-critical paths ===")
            slacks = [
                float(match.group(1))
                for match in PATH_SLACK_RE.finditer(section)
                if match.group(2) == "VIOLATED"
            ]
            if slacks:
                values["wns"] = min(slacks)
        return values

    @staticmethod
    def _header(ctx: SignoffContext, limitations: Sequence[str]) -> str:
        return templates.render(
            "signoff/opensta/header.tcl.j2",
            analysis=ctx.analysis,
            design=ctx.design,
            variant=ctx.variant,
            pdk=ctx.pdk,
            stage=ctx.stage,
            corner=ctx.corner,
            mode=ctx.mode or "not applicable",
            workload=ctx.workload or "not applicable",
            top=ctx.top,
            liberty=ctx.liberty,
            macro_liberties=", ".join(str(path) for path in ctx.macro_liberties) or "not used",
            netlist=ctx.netlist,
            sdc=ctx.sdc,
            spef=ctx.spef or "not used",
            activity_file=ctx.activity_file or "not used",
            activity_scope=ctx.activity_scope or "not used",
            gls_report=ctx.gls_report or "not used",
            report_dir=ctx.report_dir,
            limitations="\n".join(f"#   - {item}" for item in limitations),
        )

    @staticmethod
    def _common_init(ctx: SignoffContext, *, activity: bool) -> str:
        macro_list = " ".join(StaAnalysis._quote(path) for path in ctx.macro_liberties)
        final_block = (
            templates.render(
                "signoff/opensta/activity.tcl.j2",
                activity_file=StaAnalysis._quote(ctx.activity_file),
                activity_scope=StaAnalysis._quote(ctx.activity_scope),
            )
            if activity
            else '\nputs "=== Step 7/7: Analysis-specific reporting ==="'
        )
        return templates.render(
            "signoff/opensta/common.tcl.j2",
            report_dir=StaAnalysis._quote(ctx.report_dir),
            liberty=StaAnalysis._quote(ctx.liberty),
            macro_liberties=f"{{{macro_list}}}",
            netlist=StaAnalysis._quote(ctx.netlist),
            sdc=StaAnalysis._quote(ctx.sdc),
            spef=StaAnalysis._quote(ctx.spef) if ctx.spef else "{}",
            top=StaAnalysis._quote(ctx.top),
            stage=StaAnalysis._quote(ctx.stage),
            final_block=final_block,
        )

    @staticmethod
    def render_opensta_script(
        ctx: SignoffContext,
        limitations: Sequence[str],
        template: str,
        *,
        read_activity: bool = False,
        **values: object,
    ) -> str:
        """Assemble one OpenSTA script from shared setup plus one analysis body."""

        body = templates.render(template, **values)
        return "\n".join((StaAnalysis._header(ctx, limitations), StaAnalysis._common_init(ctx, activity=read_activity), body))

    @staticmethod
    def render_sta_tcl(ctx: SignoffContext) -> str:
        """Render one concise timing report for a concrete corner and mode."""

        delay_type = "min" if ctx.mode == "hold" else "max"
        threshold = ctx.near_critical_hold if ctx.mode == "hold" else ctx.near_critical_setup
        limitations = (
            "Violating, near-critical and unconstrained paths are separate sections of one report.",
            "Post-synthesis capacitance excludes routed parasitics unless an explicit SPEF is supplied.",
        )
        routed = (
            templates.render("signoff/opensta/sta_routed.tcl.j2")
            if ctx.stage == "post_route"
            else ""
        )
        return StaAnalysis.render_opensta_script(
            ctx,
            limitations,
            "signoff/opensta/sta.tcl.j2",
            delay_type=delay_type,
            endpoint_group_limit=ctx.endpoint_group_limit,
            endpoint_path_limit=ctx.endpoint_path_limit,
            near_critical_limit=f"{threshold:.6f}",
            corner=ctx.corner,
            mode=ctx.mode,
            stage=ctx.stage,
            clock_network="propagated" if ctx.stage == "post_route" else "ideal",
            interconnect="spef" if ctx.stage == "post_route" else "none",
            routed_block=routed,
        )

    @staticmethod
    def render_sdf_tcl(ctx: SignoffContext) -> str:
        """Render SDF generation for one sign-off corner."""

        limitations = ("SDF reflects the linked netlist and timing model for the selected corner.",)
        sdf = ctx.report_dir / f"{ctx.top}_{ctx.corner}.sdf"
        return StaAnalysis.render_opensta_script(
            ctx,
            limitations,
            "signoff/opensta/sdf.tcl.j2",
            sdf_file=StaAnalysis._quote(sdf),
            divider="/" if ctx.stage == "post_syn" else ".",
        )

    @staticmethod
    def _macro_liberties(values: Mapping[str, str]) -> tuple[Path, ...]:
        """Resolve and validate every configured macro Liberty view."""

        return tuple(StaAnalysis._require_file(path, "macro Liberty") for path in StaAnalysis._paths(values.get("MACRO_LIBS")))

    @staticmethod
    def _stage_inputs(project_root: Path, values: Mapping[str, str]) -> tuple[Path, Path | None]:
        """Resolve netlist and optional SPEF from the existing synthesis/PnR trees."""

        layout = PDKRunLayout.from_values(project_root, values)
        stage = values.get("SIGNOFF_STAGE", "post_syn").strip().lower()
        if stage not in {"post_syn", "post_route"}:
            raise ValueError(f"SIGNOFF_STAGE must be post_syn or post_route, got {stage!r}")
        top = values.get("TOP", "test")
        if stage == "post_route":
            platform = values.get("ORS_TECH", values.get("PDK", "")).strip() or None
            raw_netlist = values.get("NETLIST") or values.get("PNR_NETLIST")
            netlist = Path(raw_netlist) if raw_netlist else ImplementationFlow.resolve_orfs_artifact(
                layout.pnr_dir, "results", top, "6_final.v", platform
            )
            if netlist is None:
                raise ValueError(f"post-route netlist not found under {layout.pnr_dir / 'results'}")
            raw_spef = values.get("SPEF_FILE", "").strip()
            spef = Path(raw_spef) if raw_spef else ImplementationFlow.resolve_orfs_artifact(
                layout.pnr_dir, "results", top, "6_final.spef", platform
            )
            if spef is None:
                raise ValueError(f"post-route SPEF not found under {layout.pnr_dir / 'results'}")
            return StaAnalysis._require_file(netlist, "post-route netlist"), StaAnalysis._require_file(spef, "SPEF")
        netlist = Path(values.get("NETLIST") or layout.syn_dir / f"{top}_synth.v")
        raw_spef = values.get("SPEF_FILE", "").strip()
        spef = Path(raw_spef).expanduser().resolve() if raw_spef else None
        return StaAnalysis._require_file(netlist, "gate-level netlist"), StaAnalysis._optional_file(spef, "SPEF")

    @staticmethod
    def _stage_sdc(project_root: Path, values: Mapping[str, str]) -> Path:
        """Resolve the single authored design SDC for every sign-off stage."""

        raw = values.get("PNR_SDC_FILE", "").strip()
        if raw:
            return StaAnalysis._require_file(Path(raw), "SDC")
        return StaAnalysis._require_file(PDKRunLayout.from_values(project_root, values).signoff_sdc, "design SDC")

    @staticmethod
    def _base_context(
        project_root: Path,
        values: Mapping[str, str],
        *,
        analysis: str,
        corner: str,
        mode: str = "",
        workload: str = "",
        report_dir: Path,
        liberty: Path,
        activity_file: Path | None = None,
        activity_scope: str = "",
        gls_report: Path | None = None,
        validate_stage_inputs: bool = True,
    ) -> SignoffContext:
        """Resolve one analysis context, optionally before the stage netlist exists."""

        layout = PDKRunLayout.from_values(project_root, values)
        if validate_stage_inputs or values.get("SIGNOFF_STAGE", "post_syn") == "post_route":
            netlist, spef = StaAnalysis._stage_inputs(project_root, values)
        else:
            top = values.get("TOP", "test")
            netlist = Path(values.get("NETLIST") or layout.syn_dir / f"{top}_synth.v").expanduser().resolve()
            raw_spef = values.get("SPEF_FILE", "").strip()
            spef = Path(raw_spef).expanduser().resolve() if raw_spef else None
        sdc = StaAnalysis._stage_sdc(project_root, values)
        return SignoffContext(
            analysis=analysis,
            design=values.get("RUN_TOP") or values.get("TOP", "test"),
            variant=values.get("RUN_ID", "default"),
            pdk=values.get("PDK", "sky130"),
            stage=values.get("SIGNOFF_STAGE", "post_syn"),
            corner=corner,
            mode=mode,
            workload=workload,
            top=values.get("TOP", "test"),
            liberty=StaAnalysis._require_file(liberty, f"{corner} Liberty"),
            macro_liberties=StaAnalysis._macro_liberties(values),
            netlist=netlist,
            sdc=sdc,
            report_dir=report_dir.expanduser().resolve(),
            spef=spef,
            activity_file=StaAnalysis._optional_file(activity_file, "activity file"),
            activity_scope=activity_scope,
            gls_report=StaAnalysis._optional_file(gls_report, "GLS report"),
            estimated_activity=float(values.get("POWER_ACTIVITY", "0.1")),
            estimated_duty=float(values.get("POWER_DUTY", "0.5")),
            global_activity=StaAnalysis._truth(values.get("POWER_GLOBAL_ACTIVITY")),
            endpoint_group_limit=int(values.get("STA_ENDPOINT_GROUP_LIMIT", "10000")),
            endpoint_path_limit=int(values.get("STA_ENDPOINT_PATH_LIMIT", "10")),
            near_critical_setup=float(values.get("STA_NEAR_CRITICAL_SETUP", "0.200")),
            near_critical_hold=float(values.get("STA_NEAR_CRITICAL_HOLD", "0.100")),
            power_top_instances=int(values.get("POWER_TOP_INSTANCES", "20")),
        )

    @staticmethod
    def _completion_marker(ctx: SignoffContext) -> str:
        return (
            f"{COMPLETE_PREFIX} analysis={ctx.analysis} corner={ctx.corner} "
            f"mode={ctx.mode or 'n/a'} workload={ctx.workload or 'n/a'}"
        )

    @staticmethod
    def _command_inputs(ctx: SignoffContext, script: Path) -> tuple[Path, ...]:
        """Return every file consumed by one generated OpenSTA script."""

        paths = [script, ctx.netlist, ctx.sdc, ctx.liberty, *ctx.macro_liberties]
        paths.extend(path for path in (ctx.spef, ctx.activity_file, ctx.gls_report) if path is not None)
        return tuple(dict.fromkeys(path.resolve() for path in paths))

    @staticmethod
    def _render(analysis: str, ctx: SignoffContext) -> str:
        """Render one analysis through its owning sign-off engine."""

        if analysis == "sta":
            script = StaAnalysis.render_sta_tcl(ctx)
        elif analysis == "sdf":
            script = StaAnalysis.render_sdf_tcl(ctx)
        elif analysis in {"power_estimate", "power_analysis"}:
            from .power import PowerAnalysis
            renderer = (
                PowerAnalysis.render_power_estimate_tcl
                if analysis == "power_estimate"
                else PowerAnalysis.render_power_analysis_tcl
            )
            script = renderer(ctx)
        elif analysis == "fusion_analysis":
            from .fusion import FusionAnalysis
            script = FusionAnalysis.render_fusion_analysis_tcl(ctx)
        else:
            raise ValueError(f"unsupported sign-off analysis: {analysis}")
        return script.rstrip() + f"\nputs {StaAnalysis._quote(StaAnalysis._completion_marker(ctx))}\n"

    @staticmethod
    def generate_family(project_root: Path, values: Mapping[str, str], analysis: str) -> Path:
        """Generate one canonical sign-off Tcl family without side effects elsewhere."""

        supported = {"sta", "sdf", "power_estimate", "power_analysis", "fusion_analysis"}
        if analysis not in supported:
            raise ValueError(f"unsupported sign-off family: {analysis}")
        layout = PDKRunLayout.from_values(project_root, values)
        stage = values.get("SIGNOFF_STAGE", "post_syn")
        liberties = StaAnalysis._liberties(values)
        corner = "tt" if "tt" in liberties else next(iter(liberties))
        liberty = liberties[corner]
        root = layout.signoff_stage_root(stage)
        specs = {
            "sta": (root / "sta" / "sta.tcl", "setup", root / "sta" / "template_reports"),
            "sdf": (root / "sdf" / "write_sdf.tcl", "", root / "sdf" / "template_reports"),
            "power_estimate": (
                root / "power" / "estimate" / "power_estimate.tcl",
                "",
                root / "power" / "estimate" / "template_reports",
            ),
            "power_analysis": (
                root / "power" / "analysis" / "power_analysis.tcl",
                "",
                root / "power" / "analysis" / "template_reports",
            ),
            "fusion_analysis": (
                root / "fusion" / "fusion_analysis.tcl",
                "setup",
                root / "fusion" / "template_reports",
            ),
        }
        path, mode, report_dir = specs[analysis]
        workload = "GLS_WORKLOAD_REQUIRED" if analysis in {"power_analysis", "fusion_analysis"} else ""
        ctx = StaAnalysis._base_context(
            project_root,
            values,
            analysis=analysis,
            corner=corner,
            mode=mode,
            workload=workload,
            report_dir=report_dir,
            liberty=liberty,
            activity_file=None,
            activity_scope="DUT_SCOPE_REQUIRED" if workload else "",
            gls_report=None,
            validate_stage_inputs=False,
        )
        if workload:
            ctx = replace(
                ctx,
                activity_file=root / "power" / "activity" / "ACTIVITY_REQUIRED.vcd",
                gls_report=root / "power" / "activity" / "GLS_REPORT_REQUIRED.json",
            )
        written = StaAnalysis._write(path, StaAnalysis._render(analysis, ctx))
        Terminal.print_script(written, details={
            "analysis": analysis,
            "stage": stage,
            "corner": corner,
            "mode": mode or "n/a",
        })
        return written

    @staticmethod
    def generate_families(project_root: Path, values: Mapping[str, str]) -> tuple[Path, ...]:
        """Generate every canonical sign-off Tcl family in lifecycle order."""

        order = ("sta", "sdf", "power_estimate", "power_analysis", "fusion_analysis")
        return tuple(StaAnalysis.generate_family(project_root, values, analysis) for analysis in order)

    @staticmethod
    def _required_reports(analysis: str, ctx: SignoffContext) -> tuple[Path, ...]:
        names = {
            "sta": ("timing.rpt",),
            "power_estimate": ("power.rpt",),
            "power_analysis": ("power.rpt",),
            "fusion_analysis": ("fusion.rpt",),
            "sdf": (f"{ctx.top}_{ctx.corner}.sdf",),
        }
        try:
            selected = names[analysis]
        except KeyError as exc:
            raise ValueError(f"unsupported analysis: {analysis}") from exc
        return tuple(ctx.report_dir / name for name in selected)

    @staticmethod
    def _execute_script(
        project_root: Path,
        values: Mapping[str, str],
        *,
        analysis: str,
        ctx: SignoffContext,
        script: Path,
        log: Path,
        runner=None,
        on: str = "local",
    ) -> int:
        """Execute one OpenSTA script and reject truncated/incomplete output."""

        if ctx.report_dir.is_symlink() or ctx.report_dir.is_file():
            ctx.report_dir.unlink()
        elif ctx.report_dir.exists():
            shutil.rmtree(ctx.report_dir)
        ctx.report_dir.mkdir(parents=True)
        runtime_script = ctx.report_dir / script.name
        StaAnalysis._write(runtime_script, StaAnalysis._render(analysis, ctx))
        Terminal.print_script(
            runtime_script,
            details={
                "analysis": analysis,
                "stage": ctx.stage,
                "corner": ctx.corner,
                "mode": ctx.mode or "n/a",
                "workload": ctx.workload or "n/a",
                "liberty": ctx.liberty.name,
                "report_dir": ctx.report_dir,
            },
        )
        command = [values.get("STA", "sta"), "-exit", "-no_init", str(runtime_script)]
        rc = StaAnalysis._run_sta(
            command, cwd=project_root, log=log, runner=runner, on=on,
            inputs=StaAnalysis._command_inputs(ctx, runtime_script), outputs=(ctx.report_dir,),
        )
        if rc != 0:
            return rc
        transcript = (
            log.read_text(encoding="utf-8", errors="replace") if log.is_file() else ""
        )
        marker = StaAnalysis._completion_marker(ctx)
        if marker not in transcript:
            tail = "\n".join(transcript.rstrip().splitlines()[-20:])
            raise ValueError(
                f"{analysis} ended before its completion marker; log={log}"
                + (f"\n--- OpenSTA tail ---\n{tail}" if tail else "")
            )
        missing = [path for path in StaAnalysis._required_reports(analysis, ctx) if not path.is_file()]
        if missing:
            rendered = "\n  ".join(str(path) for path in missing)
            raise ValueError(f"{analysis} completed without required report(s):\n  {rendered}")
        if analysis in {"power_estimate", "power_analysis", "fusion_analysis"}:
            from .power import PowerAnalysis
            PowerAnalysis._annotate_power_summary(
                ctx.report_dir,
                "fusion.rpt" if analysis == "fusion_analysis" else "power.rpt",
            )
        return 0

    @staticmethod
    def _sta_report_violation(path: Path) -> tuple[bool, float | None, int]:
        """Return whether one STA report contains a real negative-slack violation."""

        text = path.read_text(encoding="utf-8", errors="replace")
        section = StaAnalysis._report_section(text, "=== Violating paths ===", "=== Near-critical paths ===")
        wns = StaAnalysis._timing_values(text).get("wns")
        violated = len(re.findall(r"\bslack\s+\(VIOLATED\)", section, re.IGNORECASE))
        return bool(violated or (wns is not None and wns < 0.0)), wns, violated

    @staticmethod
    def _sta_scenario_summary(ctx: SignoffContext, report: Path) -> dict[str, Any]:
        """Normalize one scenario report into compact machine-readable QoR."""

        text = report.read_text(encoding="utf-8", errors="replace")
        timing = StaAnalysis._timing_values(text)
        violating = StaAnalysis._report_section(text, "=== Violating paths ===", "=== Near-critical paths ===")
        clock_qor = StaAnalysis._report_section(text, "=== Clock QoR ===", "=== Constraint validation ===")
        clocks = []
        for match in re.finditer(
            r"^\s*(\S+)\s+period_min\s*=\s*([-+0-9.eE]+)\s+fmax\s*=\s*(INF|[-+0-9.eE]+)\s*$",
            clock_qor,
            flags=re.IGNORECASE | re.MULTILINE,
        ):
            fmax = None if match.group(3).upper() == "INF" else float(match.group(3))
            clocks.append({
                "name": match.group(1),
                "minimum_period": float(match.group(2)),
                "fmax_mhz": fmax,
            })
        violation_count = len(re.findall(r"slack\s+\(VIOLATED\)", violating, flags=re.IGNORECASE))
        unconstrained_count = StaAnalysis._unconstrained_endpoint_count(text)
        timing_violation = bool(violation_count or (timing.get("wns") or 0.0) < 0.0)
        blocking_timing = ctx.mode == "setup" or ctx.stage == "post_route"
        status = (
            "fail" if unconstrained_count or (blocking_timing and timing_violation)
            else "warn" if timing_violation
            else "pass"
        )
        return {
            "id": f"{ctx.mode}_{ctx.corner}",
            "corner": ctx.corner,
            "mode": ctx.mode,
            "stage": ctx.stage,
            "liberty": str(ctx.liberty),
            "spef": str(ctx.spef) if ctx.spef else None,
            "wns": timing.get("wns"),
            "tns": timing.get("tns"),
            "violating_paths": violation_count,
            "unconstrained_paths": unconstrained_count,
            "clocks": clocks,
            "status": status,
            "detail_report": str(report),
        }

    @staticmethod
    def _write_sta_qor(
        root: Path,
        *,
        top: str,
        pdk: str,
        stage: str,
        sdc: Path,
        scenarios: Sequence[dict[str, Any]],
        failures: Sequence[str],
    ) -> tuple[Path, Path]:
        """Write the two canonical STA evidence files: human report plus JSON."""

        sta_root = root / "sta"
        sta_root.mkdir(parents=True, exist_ok=True)
        json_path = sta_root / "summary.json"
        report_path = sta_root / "sta.rpt"
        finite_wns = [float(item["wns"]) for item in scenarios if item.get("wns") is not None]
        finite_tns = [float(item["tns"]) for item in scenarios if item.get("tns") is not None]
        status = "fail" if failures or any(item.get("status") == "fail" for item in scenarios) else "pass"
        json_scenarios = [
            {key: value for key, value in item.items() if key not in {"detail_report", "liberty", "spef"}}
            for item in scenarios
        ]
        data = {
            "schema": 1,
            "top": top,
            "pdk": pdk,
            "stage": stage,
            "sdc": sdc.name,
            "status": status,
            "qor": {
                "scenario_count": len(scenarios),
                "failing_scenarios": sum(item.get("status") == "fail" for item in scenarios),
                "worst_wns": min(finite_wns) if finite_wns else None,
                "worst_tns": min(finite_tns) if finite_tns else None,
                "violating_paths": sum(int(item.get("violating_paths", 0)) for item in scenarios),
                "unconstrained_paths": sum(int(item.get("unconstrained_paths", 0)) for item in scenarios),
            },
            "failures": list(failures),
            "scenarios": json_scenarios,
        }
        json_path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")

        lines = [
            "FlexSoC Static Timing Analysis",
            "=" * 78,
            f"design      : {top}",
            f"pdk         : {pdk}",
            f"stage       : {stage}",
            f"sdc         : {sdc}",
            f"status      : {status.upper()}",
            "",
            "QoR",
            "-" * 78,
            f"scenarios             : {data['qor']['scenario_count']}",
            f"failing scenarios     : {data['qor']['failing_scenarios']}",
            f"worst WNS             : {data['qor']['worst_wns']}",
            f"worst TNS             : {data['qor']['worst_tns']}",
            f"violating paths       : {data['qor']['violating_paths']}",
            f"unconstrained paths   : {data['qor']['unconstrained_paths']}",
            "",
            "Scenarios",
            "-" * 78,
            f"{'scenario':18} {'mode':8} {'corner':8} {'WNS':>12} {'TNS':>12} {'viol':>6} {'uncon':>6} status",
        ]
        for item in scenarios:
            lines.append(
                f"{item['id']:18} {item['mode']:8} {item['corner']:8} "
                f"{str(item.get('wns')):>12} {str(item.get('tns')):>12} "
                f"{int(item.get('violating_paths', 0)):>6} {int(item.get('unconstrained_paths', 0)):>6} {item['status']}"
            )
        if failures:
            lines += ["", "Execution failures", "-" * 78, *failures]
        lines += ["", "Details", "=" * 78]
        for item in scenarios:
            detail = Path(item["detail_report"])
            lines += ["", f"[{item['id']}]", "-" * 78]
            if detail.is_file():
                lines.append(detail.read_text(encoding="utf-8", errors="replace").rstrip())
        report_path.write_text("\n".join(lines).rstrip() + "\n", encoding="utf-8")
        return report_path, json_path

    @staticmethod
    def execute_static(analysis: str, project_root: Path, values: Mapping[str, str], *, runner=None, on: str = "local") -> int:
        """Execute static analysis across explicit timing scenarios and collect canonical QoR."""

        if analysis not in {"sta", "sdf", "power_estimate"}:
            raise ValueError(f"static analysis is not supported: {analysis}")
        layout = PDKRunLayout.from_values(project_root, values)
        stage = values.get("SIGNOFF_STAGE", "post_syn")
        root = layout.signoff_stage_root(stage)
        log_root = layout.signoff_stage_log_root(stage)
        liberties = StaAnalysis._liberties(values)
        if analysis == "sta":
            scenarios = StaAnalysis.timing_scenarios(values, liberties, stage)
            work = tuple((scenario.corner, scenario.mode, scenario.liberty) for scenario in scenarios)
        else:
            corners = StaAnalysis._selection(
                values.get("SIGNOFF_CORNERS"), "ss tt ff", tuple(liberties), "sign-off corner"
            )
            work = tuple((corner, "", liberties[corner]) for corner in corners)

        failures: list[str] = []
        violations: list[str] = []
        sta_summaries: list[dict[str, Any]] = []
        power_summaries: dict[str, dict[str, Any]] = {}
        power_activity: float | None = None
        power_duty: float | None = None
        for corner, mode, liberty in work:
            if analysis == "sta":
                report_dir = root / "sta" / corner / mode
                script = root / "sta" / "sta.tcl"
                log = log_root / "sta" / corner / mode / f"{values.get('TOP', 'test')}.log"
            elif analysis == "sdf":
                report_dir = root / "sdf" / corner
                script = root / "sdf" / "write_sdf.tcl"
                log = log_root / "sdf" / corner / f"{values.get('TOP', 'test')}.log"
            else:
                report_dir = root / "power" / "estimate" / corner
                script = root / "power" / "estimate" / "power_estimate.tcl"
                log = log_root / "power" / "estimate" / corner / f"{values.get('TOP', 'test')}.log"
            ctx = StaAnalysis._base_context(
                project_root,
                values,
                analysis=analysis,
                corner=corner,
                mode=mode,
                report_dir=report_dir,
                liberty=liberty,
            )
            try:
                rc = StaAnalysis._execute_script(
                    project_root,
                    values,
                    analysis=analysis,
                    ctx=ctx,
                    script=script,
                    log=log,
                    runner=runner,
                    on=on,
                )
            except (OSError, ValueError) as exc:
                failures.append(f"{corner}/{mode or analysis}: {exc}")
                continue
            if rc != 0:
                failures.append(f"{corner}/{mode or analysis}: OpenSTA return code {rc}; log={log}")
                continue
            for report in StaAnalysis._required_reports(analysis, ctx):
                print(f"[report] {corner}/{mode or analysis} {report}", flush=True)
                if analysis == "sta":
                    summary = StaAnalysis._sta_scenario_summary(ctx, report)
                    sta_summaries.append(summary)
                    if summary["status"] == "fail":
                        violations.append(
                            f"{corner}/{mode}: timing/constraint violation "
                            f"wns={summary.get('wns')} violating_paths={summary['violating_paths']} "
                            f"unconstrained_paths={summary['unconstrained_paths']}; report={report}"
                        )
                elif analysis == "power_estimate":
                    from .power import PowerAnalysis

                    text = report.read_text(encoding="utf-8", errors="replace")
                    activity = re.search(r"^activity=(" + FLOAT_RE.pattern + r")$", text, flags=re.MULTILINE)
                    duty = re.search(r"^duty=(" + FLOAT_RE.pattern + r")$", text, flags=re.MULTILINE)
                    if activity:
                        power_activity = float(activity.group(1))
                    if duty:
                        power_duty = float(duty.group(1))
                    values_qor = PowerAnalysis._power_values(text)
                    if values_qor:
                        values_qor["dynamic_w"] = values_qor["internal_w"] + values_qor["switching_w"]
                    power_summaries[corner] = values_qor

        if analysis == "sta":
            report, data = StaAnalysis._write_sta_qor(
                root,
                top=values.get("TOP", "test"),
                pdk=values.get("PDK", "unknown"),
                stage=stage,
                sdc=StaAnalysis._stage_sdc(project_root, values),
                scenarios=sta_summaries,
                failures=failures,
            )
            print(f"[report] STA QoR {report}", flush=True)
            print(f"[report] STA JSON {data}", flush=True)
        elif analysis == "power_estimate":
            summary = {
                "schema": 1,
                "analysis": "power_estimate",
                "top": values.get("TOP", "test"),
                "pdk": values.get("PDK", "unknown"),
                "stage": stage,
                "status": "fail" if failures else "pass",
                "activity_source": "input_assumption",
                "corners": power_summaries,
            }
            if power_activity is not None:
                summary["activity"] = power_activity
            if power_duty is not None:
                summary["duty"] = power_duty
            path = root / "power" / "estimate" / "summary.json"
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
            print(f"[report] Power estimate JSON {path}", flush=True)
        for failure in failures:
            print(f"ERROR: {failure}", file=sys.stderr)
        for violation in violations:
            print(f"ERROR: {violation}", file=sys.stderr)
        if failures:
            return 2
        return 1 if violations else 0

    @staticmethod
    def execute_activity(analysis: str, action: str, project_root: Path, values: Mapping[str, str]) -> int:
        """Dispatch workload-dependent power or fusion analysis."""

        from .power import PowerAnalysis
        return PowerAnalysis.execute_activity(analysis, action, project_root, values)
