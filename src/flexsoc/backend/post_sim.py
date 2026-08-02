"""Gate-level simulation orchestration for post-synthesis and post-PnR runs.

Icarus Verilog is the default timed GLS engine because it supports active
``specify`` paths and SDF annotation.  Verilator remains the preferred RTL
engine, but deliberately isn't used here for SDF timing simulation.
"""

from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping, Sequence

from flexsoc.backend.output import print_script
from flexsoc.run_layout import layout_from_values


STAGES = {"post_syn", "post_pnr"}
WAVE_FORMATS = {"fst", "vcd"}
TIMING_MODES = {"min", "typ", "max"}


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


def _truth(value: object) -> bool:
    return str(value).strip().lower() in {"1", "true", "yes", "on"}


def _split_paths(value: str | None) -> tuple[Path, ...]:
    if not value:
        return ()
    return tuple(Path(part).expanduser().resolve() for part in value.split() if part.strip())


def _first_existing(paths: Sequence[Path]) -> Path | None:
    return next((path.resolve() for path in paths if path.is_file()), None)


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


def resolve_paths(project_root: Path, values: Mapping[str, str], stage: str) -> GateSimPaths:
    """Resolve canonical TB, netlist, waveform and optional SDF paths."""

    if stage not in STAGES:
        raise ValueError(f"stage must be one of {sorted(STAGES)}")
    top = values.get("TOP", "test")
    testbench = values.get("TESTBENCH", f"{top}_tb")
    platform = values.get("ORS_TECH", "")
    layout = layout_from_values(project_root, values)
    run_root = layout.run_root
    tb = run_root / "dv" / "functional" / "tb" / "sv" / f"{testbench}.sv"
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
    if explicit_sdf:
        sdf = explicit_sdf
    elif stage == "post_syn":
        corner = values.get("SDF_CORNER", "ss")
        candidate = layout.sdf_dir / f"{top}_{corner}.sdf"
        sdf = candidate.resolve() if candidate.is_file() else None
    else:
        generated = layout.sdf_dir / "post_pnr" / f"{top}_post_pnr.sdf"
        sibling = netlist.with_name("6_final.sdf")
        sdf = _first_existing((generated, sibling))

    fmt = values.get("WAVE_FORMAT", "fst").strip().lower()
    if fmt not in WAVE_FORMATS:
        raise ValueError("WAVE_FORMAT must be fst or vcd")
    wave = Path(values["WAVE_FILE"]).expanduser().resolve() if values.get("WAVE_FILE") else stage_dir / f"{testbench}.{fmt}"
    executable = stage_dir / f"{testbench}.vvp"
    log_dir = layout.post_syn_log_dir if stage == "post_syn" else layout.post_pnr_log_dir
    log = log_dir / f"{top}_{stage}.log"
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
    )


def compile_command(project_root: Path, values: Mapping[str, str], stage: str, paths: GateSimPaths) -> list[str]:
    """Build an Icarus timed gate-level compile command."""

    if values.get("GLS_SIMULATOR", "iverilog").strip().lower() != "iverilog":
        raise ValueError(
            "timed gate-level simulation currently requires GLS_SIMULATOR=iverilog; "
            "Verilator ignores specify timing and $sdf_annotate"
        )
    mode = values.get("TIMING_MODE", "max").strip().lower()
    if mode not in TIMING_MODES:
        raise ValueError("TIMING_MODE must be min, typ, or max")
    if not paths.tb.is_file():
        raise ValueError(f"testbench not found: {paths.tb}; run setup_tb first")
    if not paths.netlist.is_file():
        raise ValueError(f"gate-level netlist not found: {paths.netlist}")

    # The generated TB expects <top>_synth.v when SYN is defined.  Stage an
    # alias so the same TB can drive either Yosys or final OpenROAD netlists.
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
    models = _split_paths(values.get("PRIM"))
    include_dirs.extend(path.parent for path in models)

    sdf_define = {"min": "FLEXSOC_SDF_MIN", "typ": "FLEXSOC_SDF_TYP", "max": "FLEXSOC_SDF_MAX"}[mode]
    command = [
        "iverilog",
        "-g2012",
        "-gspecify",
        f"-T{mode}",
        "-DSIM",
        "-DSYN",
        "-DFLEXSOC_GLS_EXTERNAL_MODELS",
        "-DFLEXSOC_ENABLE_SDF",
        f"-D{sdf_define}",
    ]
    command += ["-s", values.get("TESTBENCH", f"{top}_tb")]
    for directory in dict.fromkeys(path.resolve() for path in include_dirs if path.is_dir()):
        command += ["-I", str(directory)]
    command += ["-o", str(paths.executable)]

    # Supply cell models explicitly from the active PDK. Regenerated single-
    # clock include shims suppress their legacy embedded model list when the
    # FLEXSOC_GLS_EXTERNAL_MODELS define above is present; multi-clock TBs
    # already rely on this explicit list.
    command += [str(path) for path in models if path.is_file()]
    command.append(str(paths.tb))
    return command


def run_command(values: Mapping[str, str], paths: GateSimPaths) -> list[str]:
    """Build the vvp command; FST is the default waveform format."""

    fmt = values.get("WAVE_FORMAT", "fst").strip().lower()
    command = ["vvp"]
    if fmt == "fst":
        command.append("-fst")
    if paths.sdf:
        command.append("-sdf-verbose")
    command.append(str(paths.executable))
    command.append(f"+WAVE={paths.wave}")
    if paths.sdf:
        command.append(f"+SDF={paths.sdf}")

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
    command += [f"+TEST_NAME={test_name}", f"+TEST_ROOT={test_root}"]
    for key, filename in (("REGCFG", "config.regs"), ("DATA_IN", "data_in.vec"), ("DATA_OUT", "data_out.vec")):
        explicit = values.get(key)
        path = Path(explicit).expanduser().resolve() if explicit else (test_dir / filename).resolve()
        if explicit or path.is_file():
            command.append(f"+{key}={path}")
    return command


def _run(command: Sequence[str], *, cwd: Path, log: Path) -> int:
    log.parent.mkdir(parents=True, exist_ok=True)
    print("$ " + " ".join(command), flush=True)
    with log.open("w", encoding="utf-8") as stream:
        proc = subprocess.Popen(
            list(command), cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True
        )
        assert proc.stdout is not None
        for line in proc.stdout:
            sys.stdout.write(line)
            stream.write(line)
        return proc.wait()


def _timing_liberty(values: Mapping[str, str]) -> Path | None:
    """Pick one Liberty view matching TIMING_MODE without double-loading cells."""

    mode = values.get("TIMING_MODE", "max").strip().lower()
    if mode not in TIMING_MODES:
        raise ValueError("TIMING_MODE must be min, typ, or max")
    libs = tuple(path for path in _split_paths(values.get("LIBS")) if path.is_file())
    lib_syn = (
        Path(values["LIB_SYN"]).expanduser().resolve()
        if values.get("LIB_SYN") and Path(values["LIB_SYN"]).expanduser().is_file()
        else None
    )
    if mode == "typ" and lib_syn:
        return lib_syn
    if libs:
        # PDK discovery emits slow, typical, fast in that order when present.
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
    sdf = sdf_dir / f"{top}_post_pnr.sdf"
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

    compile_cmd = compile_command(project_root, values, stage, paths)
    rc = _run(compile_cmd, cwd=project_root, log=paths.log.with_name(paths.log.stem + "_compile.log"))
    if rc or action == "compile":
        return rc
    if paths.sdf and not paths.sdf.is_file():
        raise ValueError(f"SDF path does not exist: {paths.sdf}")
    paths.wave.parent.mkdir(parents=True, exist_ok=True)
    rc = _run(run_command(values, paths), cwd=project_root, log=paths.log)
    if rc == 0:
        timing = str(paths.sdf) if paths.sdf else "zero-delay (no SDF found/provided)"
        print(f"[gate-sim] stage={stage} wave={paths.wave} timing={timing}")
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
