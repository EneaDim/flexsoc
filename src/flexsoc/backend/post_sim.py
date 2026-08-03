"""Post-synthesis and post-PnR gate-level simulation orchestration.

Both the generated SystemVerilog testbench and cocotb use Icarus for GLS and
consume the same resolved netlist, cell models, vectors, timing mode and SDF.
Verilator remains the preferred RTL engine, but it is intentionally not used
for SDF timing simulation.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from decimal import Decimal, ROUND_CEILING
from pathlib import Path
from typing import Mapping, Sequence

from flexsoc.backend.output import print_script
from flexsoc.run_layout import layout_from_values


STAGES = {"post_syn", "post_pnr"}
DRIVERS = {"sv", "cocotb"}
WAVE_FORMATS = {"fst", "vcd"}
TIMING_ALIASES = {
    "zero": "zero",
    "unit": "unit",
    "min": "min",
    "typ": "typ",
    "max": "max",
    "sdf_min": "min",
    "sdf_typ": "typ",
    "sdf_max": "max",
}
SDF_MODES = {"min", "typ", "max"}


@dataclass(frozen=True, slots=True)
class GateSimPaths:
    """Resolved artifacts for one PDK-specific GLS stage."""

    run_root: Path
    pnr_dir: Path
    sdf_dir: Path
    sdf_log_dir: Path
    stage_dir: Path
    tb: Path
    netlist: Path
    sdf: Path | None
    wave: Path
    executable: Path
    log: Path
    report: Path


@dataclass(frozen=True, slots=True)
class GateSimInputs:
    """One generated functional test selected for both SV and cocotb."""

    name: str
    root: Path
    config: Path
    data_in: Path
    data_out: Path


@dataclass(frozen=True, slots=True)
class TimingConfig:
    """Canonical GLS timing semantics."""

    mode: str

    @property
    def uses_sdf(self) -> bool:
        return self.mode in SDF_MODES

    @property
    def unit_delay(self) -> bool:
        return self.mode == "unit"


def _truth(value: object) -> bool:
    return str(value).strip().lower() in {"1", "true", "yes", "on"}


def _split_paths(value: str | None) -> tuple[Path, ...]:
    if not value:
        return ()
    return tuple(Path(part).expanduser().resolve() for part in value.split() if part.strip())


_TIMING_CHECK = re.compile(
    r"^\s*\$(?:setuphold|setup|hold|recovery|removal|recrem|width|period|skew|timeskew|fullskew|nochange)\b",
    re.I | re.M,
)
_DELAYED_WIRE = re.compile(
    r"^(?P<indent>\s*)wire\s+(?P<body>[^;]*(?:_delayed|delayed_)[^;]*)\s*;\s*$"
)
_NOTIFIER_REG = re.compile(r"^(?P<indent>\s*)reg\s+(?P<body>[^;]*notifier[^;]*)\s*;\s*$", re.I)
_IFNONE_PATH = re.compile(r"^\s*ifnone\b", re.I)
_IHP_DELAY_INSTANCE = re.compile(
    r"^(?P<indent>\s*)(?P<kind>and|or|not|buf|xor|xnor|nand|nor|"
    r"bufif0|bufif1|notif0|notif1|tranif0|tranif1|rtranif0|rtranif1|"
    r"ihp_[A-Za-z_][A-Za-z0-9_]*)\s*(?P<tail>\()"
)


def _delayed_input(name: str) -> str | None:
    """Return the real input represented by a PDK delayed-net spelling."""

    if name.startswith("delayed_"):
        return name[len("delayed_") :]
    if name.endswith("_delayed"):
        return name[: -len("_delayed")]
    return None


def _icarus_path_delay_model(
    text: str,
    *,
    remove_ifnone: bool = False,
    inject_unit_delay: bool = False,
) -> tuple[str, dict[str, int]]:
    """Render an Icarus-compatible cell model while retaining usable paths.

    SKY130 uses ``*_delayed`` nets, while IHP uses ``delayed_*`` nets and a
    separate UDP support file. Icarus supports ordinary specify path delays but
    not timing checks or edge-sensitive ``ifnone`` paths. Bind delayed inputs
    directly, hold notifiers inactive and, for IHP, remove only unsupported
    ``ifnone`` path clauses. Optional ``UNIT_DELAY`` injection gives IHP a real
    zero/unit functional model without modifying the installed PDK.
    """

    out: list[str] = [
        "// FlexSoC Icarus compatibility: delayed inputs bound; timing checks disabled."
    ]
    if inject_unit_delay:
        out += ["`ifndef UNIT_DELAY", "`define UNIT_DELAY", "`endif"]
    checks = 0
    delayed = 0
    notifiers = 0
    ifnone_paths = 0
    skipping_check = False
    skipping_ifnone = False
    for line in text.splitlines():
        if not skipping_check and _TIMING_CHECK.match(line):
            checks += 1
            skipping_check = ";" not in line
            continue
        if skipping_check:
            if ";" in line:
                skipping_check = False
            continue
        if remove_ifnone and not skipping_ifnone and _IFNONE_PATH.match(line):
            ifnone_paths += 1
            skipping_ifnone = ";" not in line
            continue
        if skipping_ifnone:
            if ";" in line:
                skipping_ifnone = False
            continue

        if inject_unit_delay:
            match = _IHP_DELAY_INSTANCE.match(line)
            if match:
                line = (
                    f"{match.group('indent')}{match.group('kind')} `UNIT_DELAY "
                    f"{line[match.end('kind'):].lstrip()}"
                )
        out.append(line)

        match = _DELAYED_WIRE.match(line)
        if match:
            identifiers = re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*)\b", match.group("body"))
            for name in dict.fromkeys(identifiers):
                base = _delayed_input(name)
                if base:
                    out.append(f"{match.group('indent')}assign {name} = {base};")
                    delayed += 1
        match = _NOTIFIER_REG.match(line)
        if match:
            identifiers = re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*)\b", match.group("body"))
            names = [name for name in identifiers if "notifier" in name.lower()]
            for name in dict.fromkeys(names):
                out.append(f"{match.group('indent')}initial {name} = 1'b0;")
                notifiers += 1
    return "\n".join(out) + "\n", {
        "timing_checks_removed": checks,
        "delayed_inputs_bound": delayed,
        "notifiers_initialized": notifiers,
        "ifnone_paths_removed": ifnone_paths,
    }


def _simulation_models(values: Mapping[str, str], paths: GateSimPaths, timing: TimingConfig) -> tuple[Path, ...]:
    """Resolve cell models and stage PDK-specific Icarus compatibility views."""

    models = tuple(path for path in _split_paths(values.get("PRIM")) if path.is_file())
    pdk = values.get("PDK", "").strip().lower()
    path_only = timing.uses_sdf and _truth(values.get("SDF_ICARUS_PATH_ONLY", "1"))
    ihp = pdk == "ihp-sg13g2"
    if not path_only and not ihp:
        return models

    target_dir = paths.stage_dir / "icarus_timing_models"
    target_dir.mkdir(parents=True, exist_ok=True)
    resolved: list[Path] = []
    summary = {
        "timing_checks_removed": 0,
        "delayed_inputs_bound": 0,
        "notifiers_initialized": 0,
        "ifnone_paths_removed": 0,
    }
    for source in models:
        text = source.read_text(encoding="utf-8", errors="replace")
        needs_delayed_binding = "_delayed" in text or "delayed_" in text
        needs_timing_cleanup = bool(_TIMING_CHECK.search(text))
        needs_ihp_cleanup = ihp and (needs_delayed_binding or "ifnone" in text.lower())
        if not path_only and not needs_ihp_cleanup:
            resolved.append(source)
            continue
        if path_only and not (needs_delayed_binding or needs_timing_cleanup or needs_ihp_cleanup):
            resolved.append(source)
            continue
        rendered, stats = _icarus_path_delay_model(
            text,
            remove_ifnone=ihp,
            inject_unit_delay=ihp and not timing.uses_sdf,
        )
        target = target_dir / source.name
        target.write_text(rendered, encoding="utf-8")
        resolved.append(target.resolve())
        for key, value in stats.items():
            summary[key] += value

    mode = "path-delay-only" if timing.uses_sdf else "functional-zero-unit"
    manifest = target_dir / "manifest.json"
    manifest.write_text(
        json.dumps({"mode": mode, "pdk": pdk, **summary}, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )
    label = "icarus_sdf=path-delay-only" if timing.uses_sdf else "icarus_model=ihp-functional"
    print(
        f"[gate-sim] {label} "
        f"checks_removed={summary['timing_checks_removed']} "
        f"delayed_inputs_bound={summary['delayed_inputs_bound']} "
        f"ifnone_paths_removed={summary['ifnone_paths_removed']}",
        flush=True,
    )
    return tuple(resolved)


def _first_existing(paths: Sequence[Path]) -> Path | None:
    return next((path.resolve() for path in paths if path.is_file()), None)


def _driver(values: Mapping[str, str]) -> str:
    driver = values.get("GLS_BACKEND", "sv").strip().lower()
    if driver not in DRIVERS:
        raise ValueError(f"GLS_BACKEND must be one of {sorted(DRIVERS)}")
    return driver


def timing_config(values: Mapping[str, str]) -> TimingConfig:
    """Resolve explicit zero/unit/SDF timing semantics."""

    raw = values.get("TIMING_MODE", "zero").strip().lower().replace("-", "_")
    try:
        return TimingConfig(TIMING_ALIASES[raw])
    except KeyError as exc:
        choices = "zero, unit, min, typ, max"
        raise ValueError(f"TIMING_MODE must be one of: {choices}") from exc


def _discover_pnr_netlist(pnr_dir: Path, top: str, platform: str) -> Path | None:
    base = pnr_dir / "results"
    direct = base / platform / top / "base" / "6_final.v"
    if direct.is_file():
        return direct.resolve()
    candidates = sorted(base.glob(f"**/{top}/**/6_final.v")) if base.is_dir() else []
    return candidates[-1].resolve() if candidates else None


def _discover_pnr_file(pnr_dir: Path, top: str, platform: str, filename: str) -> Path | None:
    base = pnr_dir / "results"
    direct = base / platform / top / "base" / filename
    if direct.is_file():
        return direct.resolve()
    candidates = sorted(base.glob(f"**/{top}/**/{filename}")) if base.is_dir() else []
    return candidates[-1].resolve() if candidates else None


def _post_syn_sdf(layout, top: str, values: Mapping[str, str], mode: str) -> Path:
    default_corner = {"min": "ff", "typ": "tt", "max": "ss"}[mode]
    corner = values.get("SDF_CORNER", default_corner).strip()
    return (layout.sdf_dir / f"{top}_{corner}.sdf").resolve()


def _cocotb_wrapper(run_root: Path, top: str) -> Path:
    root = run_root / "dv" / "functional" / "tb" / "cocotb"
    nclock = root / f"{top}_cocotb_tb.sv"
    return nclock if nclock.is_file() else root / f"{top}_tb.sv"


def resolve_paths(project_root: Path, values: Mapping[str, str], stage: str) -> GateSimPaths:
    """Resolve canonical TB, netlist, waveform and optional SDF paths."""

    if stage not in STAGES:
        raise ValueError(f"stage must be one of {sorted(STAGES)}")
    top = values.get("TOP", "test")
    driver = _driver(values)
    timing = timing_config(values)
    testbench = values.get("TESTBENCH", f"{top}_tb")
    platform = values.get("ORS_TECH", "")
    layout = layout_from_values(project_root, values)
    run_root = layout.run_root
    tb = (
        run_root / "dv" / "functional" / "tb" / "sv" / f"{testbench}.sv"
        if driver == "sv"
        else _cocotb_wrapper(run_root, top)
    )
    stage_dir = layout.post_syn_sim_dir if stage == "post_syn" else layout.post_pnr_sim_dir
    stage_dir.mkdir(parents=True, exist_ok=True)

    explicit_netlist = Path(values["NETLIST"]).expanduser().resolve() if values.get("NETLIST") else None
    if stage == "post_syn":
        netlist = explicit_netlist or layout.syn_dir / f"{top}_synth.v"
    else:
        netlist = explicit_netlist or _discover_pnr_netlist(layout.pnr_dir, top, platform)
        if netlist is None:
            raise ValueError(
                "post-PnR netlist not found; run pnr first or pass --set NETLIST=/path/to/6_final.v"
            )
    netlist = Path(netlist).expanduser().resolve()

    explicit_sdf = Path(values["SDF_FILE"]).expanduser().resolve() if values.get("SDF_FILE") else None
    if timing.uses_sdf:
        if explicit_sdf:
            sdf = explicit_sdf
        elif stage == "post_syn":
            sdf = _post_syn_sdf(layout, top, values, timing.mode)
        else:
            # Post-layout SDF is corner-specific. Never reuse a mode-less or
            # tool-emitted SDF whose timing corner is not known to FlexSoC.
            sdf = (
                layout.sdf_dir
                / "post_pnr"
                / "sdf"
                / f"{top}_post_pnr_{timing.mode}.sdf"
            ).resolve()
    else:
        if explicit_sdf:
            raise ValueError(
                f"SDF_FILE was provided with TIMING_MODE={timing.mode}; use min, typ, or max to annotate SDF"
            )
        sdf = None

    fmt = values.get("WAVE_FORMAT", "fst").strip().lower()
    if fmt not in WAVE_FORMATS:
        raise ValueError("WAVE_FORMAT must be fst or vcd")
    tag = f"{driver}_{timing.mode}"
    wave = (
        Path(values["WAVE_FILE"]).expanduser().resolve()
        if values.get("WAVE_FILE")
        else stage_dir / f"{testbench}_{tag}.{fmt}"
    )
    executable = stage_dir / f"{testbench}_{tag}.vvp"
    log_dir = layout.post_syn_log_dir if stage == "post_syn" else layout.post_pnr_log_dir
    log = log_dir / f"{top}_{stage}_{tag}.log"
    report = stage_dir / f"{top}_{stage}_{tag}.json"
    return GateSimPaths(
        run_root,
        layout.pnr_dir,
        layout.sdf_dir,
        layout.sdf_log_dir,
        stage_dir,
        tb.resolve(),
        netlist,
        sdf,
        wave.resolve(),
        executable.resolve(),
        log.resolve(),
        report.resolve(),
    )


_DELAY_LITERAL = re.compile(r"^(?:0|[1-9][0-9]*)(?:\.[0-9]+)?(?:fs|ps|ns|us|ms|s)$", re.I)
_TIMESCALE = re.compile(
    r"`timescale\s+(?P<unit>[0-9]+(?:\.[0-9]+)?\s*(?:fs|ps|ns|us|ms|s))"
    r"\s*/\s*(?P<precision>[0-9]+(?:\.[0-9]+)?\s*(?:fs|ps|ns|us|ms|s))",
    re.I,
)
_TIME_FACTORS = {
    "s": Decimal("1"),
    "ms": Decimal("1e-3"),
    "us": Decimal("1e-6"),
    "ns": Decimal("1e-9"),
    "ps": Decimal("1e-12"),
    "fs": Decimal("1e-15"),
}


@dataclass(frozen=True)
class UnitDelayResolution:
    requested: str
    effective: str
    define: str
    model_timeunit: str
    model_precision: str


def _unit_delay_literal(values: Mapping[str, str] | None = None) -> str:
    """Return the requested physical delay for uniform unit-delay GLS."""

    raw = str((values or {}).get("GLS_UNIT_DELAY", "1ps")).strip()
    if raw.startswith("#"):
        raw = raw[1:].strip()
    if not _DELAY_LITERAL.fullmatch(raw):
        raise ValueError(
            "GLS_UNIT_DELAY must be an explicit non-negative time literal "
            "such as 1ps, 10ps, or 1ns"
        )
    return raw.lower()


def _time_seconds(literal: str) -> Decimal:
    match = re.fullmatch(
        r"(?P<value>[0-9]+(?:\.[0-9]+)?)(?P<unit>fs|ps|ns|us|ms|s)",
        literal.replace(" ", ""),
        re.I,
    )
    if not match:
        raise ValueError(f"invalid time literal: {literal}")
    return Decimal(match.group("value")) * _TIME_FACTORS[match.group("unit").lower()]


def _format_decimal(value: Decimal) -> str:
    text = format(value.normalize(), "f")
    if "." in text:
        text = text.rstrip("0").rstrip(".")
    return text or "0"


def _format_time(seconds: Decimal) -> str:
    for unit in ("s", "ms", "us", "ns", "ps", "fs"):
        factor = _TIME_FACTORS[unit]
        value = seconds / factor
        if value == value.to_integral_value():
            return f"{_format_decimal(value)}{unit}"
    return f"{_format_decimal(seconds / _TIME_FACTORS['fs'])}fs"


def _unit_delay_resolution(
    values: Mapping[str, str] | None, models: Sequence[Path]
) -> UnitDelayResolution:
    """Resolve one suffix-free Icarus delay representable by every model.

    Icarus accepts numeric primitive/UDP delays such as ``#0.01`` much more
    consistently than SystemVerilog time literals such as ``#1ps``.  The
    numeric value is interpreted in each model's ``timescale`` time unit, so
    all participating models must share a unit.  The requested physical delay
    is rounded up to the coarsest model precision, preventing a nominal unit
    delay from quantizing to zero.
    """

    requested_literal = _unit_delay_literal(values)
    requested = _time_seconds(requested_literal)
    timeunits: set[Decimal] = set()
    precisions: list[Decimal] = []
    for path in models:
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        for match in _TIMESCALE.finditer(text):
            timeunits.add(_time_seconds(match.group("unit")))
            precisions.append(_time_seconds(match.group("precision")))
    if not timeunits:
        timeunits = {_TIME_FACTORS["ns"]}
        precisions = [_TIME_FACTORS["ps"]]
    if len(timeunits) != 1:
        rendered = ", ".join(sorted(_format_time(value) for value in timeunits))
        raise ValueError(
            "TIMING_MODE=unit requires one common model time unit; "
            f"found: {rendered}"
        )
    timeunit = next(iter(timeunits))
    precision = max(precisions or [_TIME_FACTORS["ps"]])
    if requested == 0:
        effective = Decimal(0)
    else:
        ticks = (requested / precision).to_integral_value(rounding=ROUND_CEILING)
        effective = ticks * precision
    scalar = effective / timeunit
    return UnitDelayResolution(
        requested=requested_literal,
        effective=_format_time(effective),
        define=_format_decimal(scalar),
        model_timeunit=_format_time(timeunit),
        model_precision=_format_time(precision),
    )


def _compile_timing_args(
    timing: TimingConfig,
    values: Mapping[str, str] | None = None,
    models: Sequence[Path] = (),
) -> list[str]:
    if timing.mode == "zero":
        return ["-DFUNCTIONAL", "-DUNIT_DELAY=#0", "-gno-specify"]
    if timing.mode == "unit":
        delay = _unit_delay_resolution(values, models)
        return [
            "-DFUNCTIONAL",
            "-gno-specify",
            f"-DUNIT_DELAY=#{delay.define}",
        ]
    define = {"min": "FLEXSOC_SDF_MIN", "typ": "FLEXSOC_SDF_TYP", "max": "FLEXSOC_SDF_MAX"}[timing.mode]
    return ["-gspecify", f"-T{timing.mode}", "-DFLEXSOC_ENABLE_SDF", f"-D{define}"]


def compile_command(project_root: Path, values: Mapping[str, str], stage: str, paths: GateSimPaths) -> list[str]:
    """Build the direct SystemVerilog/Icarus GLS compile command."""

    if _driver(values) != "sv":
        raise ValueError("compile_command is only valid for GLS_BACKEND=sv")
    if values.get("GLS_SIMULATOR", "iverilog").strip().lower() != "iverilog":
        raise ValueError(
            "gate-level simulation currently requires GLS_SIMULATOR=iverilog; "
            "Verilator ignores specify timing and $sdf_annotate"
        )
    timing = timing_config(values)
    if not paths.tb.is_file():
        raise ValueError(f"testbench not found: {paths.tb}; run setup_tb first")
    if not paths.netlist.is_file():
        raise ValueError(f"gate-level netlist not found: {paths.netlist}")
    if timing.uses_sdf and (not paths.sdf or not paths.sdf.is_file()):
        raise ValueError(
            f"TIMING_MODE={timing.mode} requires an SDF file; not found: {paths.sdf}"
        )

    # Generated SV TBs include <top>_synth.v under SYN. Stage an alias so the
    # same source drives both Yosys and final OpenROAD netlists.
    top = values.get("TOP", "test")
    alias = paths.stage_dir / f"{top}_synth.v"
    if alias.exists() or alias.is_symlink():
        alias.unlink()
    try:
        alias.symlink_to(paths.netlist)
    except OSError:
        shutil.copy2(paths.netlist, alias)

    include_dirs = [
        project_root / "hw" / "ips" / "pkgs",
        project_root / "hw" / "ips" / "prim",
        project_root / "hw" / "ips" / "prim_opentitan",
        project_root / "hw" / "ips" / "tlul",
        paths.run_root / "rtl",
        paths.tb.parent,
        paths.stage_dir,
    ]
    models = _simulation_models(values, paths, timing)
    include_dirs.extend(path.parent for path in models)

    command = [
        "iverilog",
        "-g2012",
        "-DSIM",
        "-DSYN",
        "-DFLEXSOC_GLS_EXTERNAL_MODELS",
        *_compile_timing_args(timing, values, models),
        "-s",
        values.get("TESTBENCH", f"{top}_tb"),
    ]
    for directory in dict.fromkeys(path.resolve() for path in include_dirs if path.is_dir()):
        command += ["-I", str(directory)]
    command += ["-o", str(paths.executable)]
    command += [str(path) for path in models if path.is_file()]
    helpers = [paths.tb.parent / name for name in ("tlul_if.sv", "reg_if.sv", "reg_utils.sv")]
    command += [str(path) for path in helpers if path.is_file()]
    command.append(str(paths.tb))
    return command


def resolve_test_inputs(values: Mapping[str, str], paths: GateSimPaths) -> GateSimInputs:
    """Resolve one command stream identically for SV and cocotb."""

    test_root = (
        Path(values["TEST_ROOT"]).expanduser().resolve()
        if values.get("TEST_ROOT")
        else paths.run_root / "dv" / "functional" / "tests"
    )
    test_name = values.get("TEST_NAME", "").strip()
    if not test_name:
        for candidate in ("smoke", "mac_smoke"):
            if (test_root / candidate).is_dir():
                test_name = candidate
                break
        if not test_name and test_root.is_dir():
            dirs = sorted(path.name for path in test_root.iterdir() if path.is_dir())
            test_name = dirs[0] if dirs else "smoke"
        if not test_name:
            test_name = "smoke"
    test_dir = test_root / test_name

    def selected(key: str, filename: str) -> Path:
        return (
            Path(values[key]).expanduser().resolve()
            if values.get(key)
            else (test_dir / filename).resolve()
        )

    return GateSimInputs(
        test_name,
        test_root.resolve(),
        selected("REGCFG", "config.regs"),
        selected("DATA_IN", "data_in.vec"),
        selected("DATA_OUT", "data_out.vec"),
    )


def run_command(values: Mapping[str, str], paths: GateSimPaths) -> list[str]:
    """Build the direct SV/vvp command from the shared test selection."""

    command = ["vvp", str(paths.executable), f"+WAVE={paths.wave}"]
    if paths.sdf:
        command.append(f"+SDF={paths.sdf}")
    inputs = resolve_test_inputs(values, paths)
    command += [
        f"+TEST_NAME={inputs.name}",
        f"+TEST_ROOT={inputs.root}",
        f"+CFG={inputs.config}",
        f"+REGCFG={inputs.config}",
        f"+DATA_IN={inputs.data_in}",
        f"+DATA_OUT={inputs.data_out}",
    ]
    return command


def run_environment(values: Mapping[str, str]) -> dict[str, str]:
    """Select the Icarus waveform dumper without version-specific vvp flags."""

    return (
        {"IVERILOG_DUMPER": "fst"}
        if values.get("WAVE_FORMAT", "fst").strip().lower() == "fst"
        else {}
    )


def cocotb_command(action: str, values: Mapping[str, str], paths: GateSimPaths) -> list[str]:
    """Build the cocotb Make command using the same GLS artifacts and vectors."""

    if action not in {"compile", "sim"}:
        raise ValueError("cocotb GLS supports compile or sim actions")
    if values.get("GLS_SIMULATOR", "iverilog").strip().lower() != "iverilog":
        raise ValueError("cocotb GLS currently requires GLS_SIMULATOR=iverilog")
    timing = timing_config(values)
    if not paths.tb.is_file():
        raise ValueError(f"cocotb wrapper not found: {paths.tb}; run setup_cocotb first")
    if not paths.netlist.is_file():
        raise ValueError(f"gate-level netlist not found: {paths.netlist}")
    if timing.uses_sdf and (not paths.sdf or not paths.sdf.is_file()):
        raise ValueError(
            f"TIMING_MODE={timing.mode} requires an SDF file; not found: {paths.sdf}"
        )
    tb_dir = paths.tb.parent
    if not (tb_dir / "Makefile").is_file():
        raise ValueError(f"cocotb Makefile not found: {tb_dir / 'Makefile'}; run setup_cocotb first")

    inputs = resolve_test_inputs(values, paths)
    model_paths = _simulation_models(values, paths, timing)
    models = " ".join(str(path) for path in model_paths)
    unit_delay = _unit_delay_resolution(values, model_paths) if timing.unit_delay else None
    target = "compile" if action == "compile" else "sim"
    command = [
        "make",
        "-C",
        str(tb_dir),
        target,
        "GATES=yes",
        "SIM=icarus",
        f"PYTHON_BIN={sys.executable}",
        f"SIM_BUILD={paths.stage_dir / 'cocotb_build'}",
        f"COCOTB_RESULTS_FILE={paths.stage_dir / 'cocotb_results.xml'}",
        f"GLS_NETLIST={paths.netlist}",
        f"GLS_MODELS={models}",
        f"TIMING_MODE={timing.mode}",
        f"GLS_UNIT_DELAY_DEFINE={unit_delay.define if unit_delay else 0}",
        f"SDF_FILE={paths.sdf or ''}",
        f"WAVE_FORMAT={values.get('WAVE_FORMAT', 'fst')}",
        f"WAVE_FILE={paths.wave}",
        # Cocotb owns its Icarus waveform dump through the supported WAVES=1
        # helper. The generated wrapper only prints the selected path in this
        # mode, avoiding both a duplicate hierarchy scan and vvp's -none dump
        # suppression.
        "WAVES=1",
        f"TEST_NAME={inputs.name}",
        f"TEST_ROOT={inputs.root}",
        f"REG_CONFIG={inputs.config}",
        f"CFG={inputs.config}",
        f"DATA_IN={inputs.data_in}",
        f"DATA_OUT={inputs.data_out}",
    ]
    return command


def _run(
    command: Sequence[str],
    *,
    cwd: Path,
    log: Path,
    env: Mapping[str, str] | None = None,
) -> int:
    log.parent.mkdir(parents=True, exist_ok=True)
    env_prefix = " ".join(f"{key}={value}" for key, value in sorted((env or {}).items()))
    shown = " ".join(command)
    print("$ " + (f"{env_prefix} " if env_prefix else "") + shown, flush=True)
    with log.open("w", encoding="utf-8") as stream:
        process_env = None
        if env:
            process_env = dict(os.environ)
            process_env.update(env)
        proc = subprocess.Popen(
            list(command),
            cwd=cwd,
            env=process_env,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
        )
        assert proc.stdout is not None
        for line in proc.stdout:
            sys.stdout.write(line)
            stream.write(line)
        return proc.wait()


def _timing_liberty(values: Mapping[str, str]) -> Path | None:
    """Pick one Liberty view matching an explicit SDF timing mode."""

    mode = timing_config(values).mode
    if mode not in SDF_MODES:
        raise ValueError("post-PnR SDF export requires TIMING_MODE=min, typ, or max")
    libs = tuple(path for path in _split_paths(values.get("LIBS")) if path.is_file())
    lib_syn = (
        Path(values["LIB_SYN"]).expanduser().resolve()
        if values.get("LIB_SYN") and Path(values["LIB_SYN"]).expanduser().is_file()
        else None
    )
    if mode == "typ" and lib_syn:
        return lib_syn
    if libs:
        if mode == "max":
            return libs[0]
        if mode == "min":
            return libs[-1]
        return libs[len(libs) // 2]
    return lib_syn


def render_post_pnr_sdf_tcl(project_root: Path, values: Mapping[str, str], paths: GateSimPaths) -> tuple[Path, Path]:
    """Render OpenSTA Tcl that writes SDF from the final netlist + SPEF."""

    top = values.get("TOP", "test")
    platform = values.get("ORS_TECH", "")
    liberty = _timing_liberty(values)
    if not liberty:
        raise ValueError("no Liberty file resolved; select/activate a usable PDK first")
    spef = Path(values["SPEF_FILE"]).expanduser().resolve() if values.get("SPEF_FILE") else _discover_pnr_file(paths.pnr_dir, top, platform, "6_final.spef")
    sdc = Path(values["PNR_SDC_FILE"]).expanduser().resolve() if values.get("PNR_SDC_FILE") else _discover_pnr_file(paths.pnr_dir, top, platform, "6_final.sdc")
    if not spef or not spef.is_file():
        raise ValueError("post-PnR SPEF not found; pass --set SPEF_FILE=/path/to/6_final.spef")
    if not sdc or not sdc.is_file():
        raise ValueError("post-PnR SDC not found; pass --set PNR_SDC_FILE=/path/to/6_final.sdc")

    outdir = paths.sdf_dir / "post_pnr"
    sdf_dir = outdir / "sdf"
    sdf_dir.mkdir(parents=True, exist_ok=True)
    mode = timing_config(values).mode
    sdf = sdf_dir / f"{top}_post_pnr_{mode}.sdf"
    tcl = outdir / f"{top}_write_sdf.tcl"
    lines = [
        "# Auto-generated FlexSoC post-PnR SDF export",
        f"read_liberty {{{liberty}}}",
        f"read_verilog {{{paths.netlist}}}",
        f"link_design {top}",
        f"read_sdc {{{sdc}}}",
        f"read_spef {{{spef}}}",
        f"write_sdf {{{sdf}}}",
        "exit",
        "",
    ]
    tcl.write_text("\n".join(lines), encoding="utf-8")
    return tcl, sdf


_SDF_WARNING = re.compile(r"\b(?:warning|unsupported|not annotated|not found|unable)\b", re.I)
_SDF_ERROR = re.compile(r"\b(?:error|failed|fatal|invalid)\b", re.I)


def sdf_annotation_summary(text: str) -> dict[str, object]:
    """Summarize observable Icarus SDF diagnostics without inventing counts."""

    lines = text.splitlines()
    relevant = [line.strip() for line in lines if re.search(r"sdf|annotat|timing check", line, re.I)]
    markers = [line for line in relevant if "[TB] sdf =" in line]
    errors = [line for line in relevant if _SDF_ERROR.search(line)]
    warnings = [line for line in relevant if _SDF_WARNING.search(line) and line not in errors]
    return {
        "requested_marker": bool(markers),
        "markers": markers,
        "warnings": warnings,
        "errors": errors,
        # Icarus does not expose stable machine-readable cell/check totals here.
        "annotated_cells": None,
        "timing_checks": None,
    }



def _normalize_cocotb_wave(paths: GateSimPaths, values: Mapping[str, str]) -> Path | None:
    """Move cocotb/Icarus' build-local dump to the requested FlexSoC path."""

    if paths.wave.is_file() and paths.wave.stat().st_size:
        return paths.wave
    extension = values.get("WAVE_FORMAT", "fst").strip().lower() or "fst"
    build = paths.stage_dir / "cocotb_build"
    candidates = [
        path for path in build.glob(f"*.{extension}")
        if path.is_file() and path.stat().st_size
    ]
    if len(candidates) != 1:
        return None
    paths.wave.parent.mkdir(parents=True, exist_ok=True)
    shutil.move(str(candidates[0]), str(paths.wave))
    print(f"[gate-sim] cocotb wave normalized: {paths.wave}", flush=True)
    return paths.wave

def _write_report(
    paths: GateSimPaths,
    values: Mapping[str, str],
    stage: str,
    rc: int,
    *,
    phase: str = "run",
) -> tuple[int, dict[str, object]]:
    timing = timing_config(values)
    text = paths.log.read_text(encoding="utf-8", errors="replace") if paths.log.is_file() else ""
    annotation = sdf_annotation_summary(text) if timing.uses_sdf else None
    strict = _truth(values.get("SDF_STRICT", "1"))
    final_rc = rc
    if rc == 0 and annotation:
        if not annotation["requested_marker"]:
            print("ERROR: SDF was requested but the testbench did not report annotation", file=sys.stderr)
            final_rc = 2
        elif annotation["errors"] or (strict and annotation["warnings"]):
            print(
                "ERROR: SDF annotation diagnostics detected; inspect the gate-simulation log",
                file=sys.stderr,
            )
            final_rc = 2

    unit_delay = (
        _unit_delay_resolution(values, _split_paths(values.get("PRIM")))
        if timing.unit_delay
        else None
    )
    report: dict[str, object] = {
        "status": "pass" if final_rc == 0 else "fail",
        "returncode": final_rc,
        "phase": phase,
        "stage": stage,
        "backend": _driver(values),
        "test_name": values.get("TEST_NAME", "smoke"),
        "simulator": values.get("GLS_SIMULATOR", "iverilog"),
        "timing_mode": timing.mode,
        "unit_delay": unit_delay.effective if unit_delay else None,
        "unit_delay_requested": unit_delay.requested if unit_delay else None,
        "unit_delay_define": unit_delay.define if unit_delay else None,
        "unit_delay_model_timeunit": unit_delay.model_timeunit if unit_delay else None,
        "unit_delay_model_precision": unit_delay.model_precision if unit_delay else None,
        "timing_model": (
            "icarus-path-delay-only"
            if timing.uses_sdf and _truth(values.get("SDF_ICARUS_PATH_ONLY", "1"))
            else ("functional-unit-delay" if timing.unit_delay else "functional-zero-delay")
        ),
        "timing_checks": (
            "disabled-unsupported-by-icarus" if timing.uses_sdf else "not-applicable"
        ),
        "netlist": str(paths.netlist),
        "sdf": str(paths.sdf) if paths.sdf else None,
        "wave": str(paths.wave),
        "log": str(paths.log),
        "annotation": annotation,
    }
    paths.report.parent.mkdir(parents=True, exist_ok=True)
    paths.report.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return final_rc, report


def execute(action: str, stage: str, project_root: Path, values: Mapping[str, str]) -> int:
    """Compile/run GLS or export post-PnR SDF."""

    paths = resolve_paths(project_root, values, stage)
    if action == "sdf":
        if stage != "post_pnr":
            raise ValueError("SDF export action is only valid for post_pnr")
        tcl, sdf = render_post_pnr_sdf_tcl(project_root, values, paths)
        print_script(tcl)
        log = paths.sdf_log_dir / f"{values.get('TOP', 'test')}_post_pnr_sdf.log"
        rc = _run([values.get("STA", "sta"), "-exit", "-no_init", str(tcl)], cwd=project_root, log=log)
        if rc == 0:
            print(f"[post_pnr] sdf: {sdf}")
        return rc

    driver = _driver(values)
    if driver == "sv":
        compile_cmd = compile_command(project_root, values, stage, paths)
        compile_log = paths.log.with_name(paths.log.stem + "_compile.log")
        rc = _run(compile_cmd, cwd=project_root, log=compile_log)
        if rc:
            paths.log.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(compile_log, paths.log)
            rc, _ = _write_report(paths, values, stage, rc, phase="compile")
            return rc
        if action == "compile":
            return rc
        paths.wave.parent.mkdir(parents=True, exist_ok=True)
        rc = _run(
            run_command(values, paths),
            cwd=project_root,
            log=paths.log,
            env=run_environment(values),
        )
    else:
        command = cocotb_command(action, values, paths)
        log = paths.log.with_name(paths.log.stem + "_compile.log") if action == "compile" else paths.log
        rc = _run(command, cwd=project_root, log=log)
        if action == "compile":
            return rc
        if rc == 0:
            _normalize_cocotb_wave(paths, values)

    rc, report = _write_report(paths, values, stage, rc)
    print(
        f"[gate-sim] stage={stage} backend={report['backend']} timing={report['timing_mode']} "
        f"wave={paths.wave} report={paths.report}"
    )
    return rc


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="FlexSoC post-synthesis/post-PnR gate simulation")
    parser.add_argument("--action", choices=("compile", "sim", "sdf"), required=True)
    parser.add_argument("--stage", choices=tuple(sorted(STAGES)), required=True)
    parser.add_argument("--project-root", type=Path, required=True)
    parser.add_argument("--values-json", required=True)
    return parser.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    try:
        values = {str(k): str(v) for k, v in json.loads(args.values_json).items()}
        return execute(args.action, args.stage, args.project_root.resolve(), values)
    except (ValueError, OSError, subprocess.SubprocessError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
