"""Yosys/ABC synthesis setup and execution helpers."""

from __future__ import annotations

import os
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence


def _repo_root() -> Path:
    """Return the repository root used for generated synthesis paths."""

    for parent in Path(__file__).resolve().parents:
        if (parent / "pyproject.toml").exists():
            return parent
    return Path.cwd()

def _rewrite_hw_ip_include_paths(script: str) -> str:
    """Resolve hw/ips include paths from the current repository root."""

    ip_root = (_repo_root() / "hw" / "ips").as_posix()
    for ip_name in ("pkgs", "prim_opentitan", "prim", "tlul"):
        script = script.replace(f"../hw/ips/{ip_name}", f"{ip_root}/{ip_name}")
    return script

@dataclass(frozen=True, slots=True)
class SynthesisConfig:
    """Describe one synthesis script generation request.

    The config accepts Path objects so Make, CLI, and Python callers converge on
    the same backend contract.
    """

    top: str
    topdir: Path
    target: str
    clk_period_ns: float
    output: Path = Path("syn")
    liberty: Path | None = None
    sdcdir: Path | None = None
    opt: str = "area"
    filelists: tuple[Path, ...] = (Path("rtl_common.f"), Path("rtl_ip.f"))
    tie_hi: tuple[str, str] | None = None
    tie_lo: tuple[str, str] | None = None
    min_buffer: tuple[str, str, str] | None = None


def pjoin(*parts: str | Path) -> str:
    """Join path fragments and return a POSIX string for generated scripts."""

    return Path(*parts).as_posix()


def write_text(path: Path, text: str) -> Path:
    """Write UTF-8 text after creating the parent directory."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")
    return path


def abc_script_area() -> str:
    """Render the area-oriented ABC recipe."""

    return "\n".join(
        [
            "# AREA-oriented ABC script (portable)",
            "strash",
            "dch",
            "balance",
            "rewrite",
            "refactor",
            "rewrite -z",
            "balance",
            "dch",
            "map -a",
            "topo",
            "dnsize -c",
            "stime -p",
            "print_stats -m",
            "",
        ]
    )


def abc_script_delay(clk_ns: float) -> str:
    """Render the delay-oriented ABC recipe for one clock period."""

    return "\n".join(
        [
            f"# DELAY-oriented ABC script (portable) - target {clk_ns} ns",
            "strash",
            "balance",
            "rewrite",
            "refactor",
            "rewrite -z",
            "balance",
            "dch",
            "# retime -o",
            "map",
            "topo",
            "upsize -c",
            "buffer -c",
            "stime -p",
            "print_stats -m",
            "",
        ]
    )


def render_abc_constraints(driving_cell: str = "", load: float = 10.0) -> str:
    """Render technology-neutral ABC constraints."""

    lines: list[str] = []
    if driving_cell.strip():
        lines.append(f"set_driving_cell {driving_cell.strip()}")
    lines.append(f"set_load {load:g}")
    return "\n".join(lines) + "\n"


def _abc_script_name(opt: str) -> str | None:
    """Return the ABC script file name selected by an optimization mode."""

    return {"area": "area.abc", "delay": "delay.abc"}.get(opt)


def _abc_constraint_arg(cfg: SynthesisConfig) -> str:
    """Return the ABC timing-constraint file generated for the active PDK."""

    return f"\n    -constr {pjoin(cfg.output, 'abc.constr')}"


def render_abc_command(cfg: SynthesisConfig, script_name: str | None) -> str:
    """Render the ABC command for one ASIC synthesis script."""

    if cfg.liberty is None:
        raise ValueError("ASIC synthesis requires a Liberty file.")

    if script_name is None:
        delay_ps = int(round(cfg.clk_period_ns * 1000.0))
        return f"abc -keepff -D {delay_ps} -liberty {cfg.liberty.as_posix()}"

    base = f"abc -keepff -liberty {cfg.liberty.as_posix()}"
    if cfg.opt == "delay":
        delay_ps = int(round(cfg.clk_period_ns * 1000.0))
        base = f"abc -keepff -D {delay_ps} -liberty {cfg.liberty.as_posix()}"
    return f"{base} -script {pjoin(cfg.output, script_name)} \\" + _abc_constraint_arg(cfg)


def _asic_tail(cfg: SynthesisConfig, script_name: str | None) -> list[str]:
    """Return shared ASIC mapping, cleanup, and output commands."""

    if cfg.liberty is None:
        raise ValueError("ASIC synthesis requires a Liberty file.")

    return [
        "",
        "# technology-boundary checkpoints used by equivalence diagnostics",
        f"write_rtlil {pjoin(cfg.output, cfg.top + '_generic.il')}",
        "",
        "# prepare FF types while keeping Yosys FF boundaries visible to ABC",
        f"dfflibmap -prepare -liberty {cfg.liberty.as_posix()}",
        f"write_rtlil {pjoin(cfg.output, cfg.top + '_dffmap.il')}",
        "",
        "# map combinational logic and preserve FF output wires used by EQY",
        render_abc_command(cfg, script_name),
        f"write_rtlil {pjoin(cfg.output, cfg.top + '_abc.il')}",
        "",
        "# bind the prepared FF types to final technology cells after ABC",
        f"dfflibmap -map-only -liberty {cfg.liberty.as_posix()}",
        "",
        "# Validate mapped connectivity before physical-only netlist finalization",
        "check -assert",
        "",
        "# Finalize the implementation-ready technology netlist",
        "splitnets",
        "opt_clean -purge",
        *(
            [
                f"hilomap -singleton -hicell {cfg.tie_hi[0]} {cfg.tie_hi[1]} "
                f"-locell {cfg.tie_lo[0]} {cfg.tie_lo[1]}"
            ]
            if cfg.tie_hi and cfg.tie_lo
            else []
        ),
        *(
            [f"insbuf -buf {cfg.min_buffer[0]} {cfg.min_buffer[1]} {cfg.min_buffer[2]}"]
            if cfg.min_buffer
            else []
        ),
        "check -assert -mapped",
        f"write_rtlil {pjoin(cfg.output, cfg.top + '_clean.il')}",
        "",
        "# Basic stats of std cells and area",
        f"stat -liberty {cfg.liberty.as_posix()}",
        "",
        "# Final netlist consumed directly by physical implementation",
        f"write_verilog -nohex -nodec {pjoin(cfg.output, cfg.top + '_synth.v')}",
        f"write_json {pjoin(cfg.output, cfg.top + '_synth.json')}",
        "",
    ]


def yosys_synth_asic_verilog(
    top: str,
    topdir: Path,
    liberty: Path,
    clk_ns: float,
    opt: str,
    sdcdir: Path | None,
    outdir: Path,
    *,
    tie_hi: tuple[str, str] | None = None,
    tie_lo: tuple[str, str] | None = None,
    min_buffer: tuple[str, str, str] | None = None,
) -> str:
    """Render a Verilog-only ASIC Yosys script."""

    cfg = SynthesisConfig(
        top, topdir, "asic", clk_ns, outdir, liberty, sdcdir, opt,
        tie_hi=tie_hi, tie_lo=tie_lo, min_buffer=min_buffer,
    )
    script_name = _abc_script_name(opt)
    lines = [
        "# read target standard cells as library modules for mapped-cell pin directions",
        f"read_liberty -overwrite -setattr liberty_cell -lib {liberty.as_posix()}",
        "# read files",
        f"read_verilog {pjoin(topdir, top + '.v')}",
        "# basic synth",
        f"synth -top {top}" + (" -noabc" if opt in {"area", "delay"} else ""),
        f"show -width -format dot -prefix {pjoin(outdir, 'plots', top + '_postsyn')}",
        *_asic_tail(cfg, script_name),
    ]
    return "\n".join(lines)


def yosys_synth_asic_slang(
    top: str,
    liberty: Path,
    clk_ns: float,
    opt: str,
    sdcdir: Path | None,
    outdir: Path,
    filelists: Sequence[Path] = (Path("rtl_common.f"), Path("rtl_ip.f")),
    *,
    tie_hi: tuple[str, str] | None = None,
    tie_lo: tuple[str, str] | None = None,
    min_buffer: tuple[str, str, str] | None = None,
) -> str:
    """Render a SystemVerilog ASIC Yosys script through slang."""

    cfg = SynthesisConfig(
        top, Path("rtl"), "asic", clk_ns, outdir, liberty, sdcdir, opt, tuple(filelists),
        tie_hi=tie_hi, tie_lo=tie_lo, min_buffer=min_buffer,
    )
    script_name = _abc_script_name(opt)
    lines = [
        "# read target standard cells as library modules for mapped-cell pin directions",
        f"read_liberty -overwrite -setattr liberty_cell -lib {liberty.as_posix()}",
        "# read files (SystemVerilog via slang)",
        f"read_slang -I {(_repo_root() / 'hw' / 'ips' / 'pkgs').as_posix()} \\",
        "           -I ../hw/ips/prim \\",
        "           -I ../hw/ips/prim_opentitan \\",
        "           -I ../hw/ips/tlul \\",
        "           -D SYNTHESIS \\",
        "           --ignore-assertions \\",
        *(f"           -f {Path(filelist).resolve().as_posix()} \\" for filelist in filelists),
        f"           --top {top}",
        "",
        "# basic synth",
        f"synth -top {top}" + (" -noabc" if opt in {"area", "delay"} else ""),
        *_asic_tail(cfg, script_name),
    ]
    return _rewrite_hw_ip_include_paths("\n".join(lines))


def yosys_synth_xilinx(top: str, topdir: Path, outdir: Path) -> str:
    """Render a Xilinx-oriented Yosys script."""

    return "\n".join(
        [
            "# read files",
            f"read_verilog {pjoin(topdir, top + '.v')}",
            "# basic synth",
            f"synth_xilinx -top {top} -flatten -edif {pjoin(outdir, top + '.edif')}",
            "",
        ]
    )


def vivado_tcl_xilinx(top: str) -> str:
    """Render a compact Vivado TCL implementation script."""

    return "\n".join(
        [
            f"read_xdc {top}.xdc",
            f"read_edif {top}.edif",
            f"link_design -part xc7a35tcpg236-1 -top {top}",
            "opt_design",
            "place_design",
            "route_design",
            "report_utilization",
            "report_timing",
            f"write_bitstream -force {top}.bit",
            "",
        ]
    )


def yosys_synth_ice40(top: str, topdir: Path, outdir: Path) -> str:
    """Render an iCE40-oriented Yosys script."""

    return "\n".join(
        [
            "# read files",
            f"read_verilog {pjoin(topdir, top + '.v')}",
            "# basic synth",
            f"synth_ice40 -top {top} -json {pjoin(outdir, top + '.json')}",
            "",
        ]
    )


def generate_synthesis_scripts(cfg: SynthesisConfig) -> tuple[Path, ...]:
    """Generate synthesis scripts and return the written paths."""

    cfg.output.mkdir(parents=True, exist_ok=True)
    (cfg.output / "plots").mkdir(parents=True, exist_ok=True)
    written: list[Path] = []

    if cfg.target == "asic":
        if cfg.liberty is None:
            raise ValueError("For target=asic you must provide a Liberty file.")
        if cfg.opt == "area":
            written.append(write_text(cfg.output / "area.abc", abc_script_area()))
        elif cfg.opt == "delay":
            written.append(write_text(cfg.output / "delay.abc", abc_script_delay(cfg.clk_period_ns)))
        if cfg.opt in {"area", "delay"}:
            written.append(
                write_text(
                    cfg.output / "abc.constr",
                    render_abc_constraints(os.environ.get("FLEXSOC_DRIVING_CELL", "")),
                )
            )
        written.append(write_text(
            cfg.output / "synth.ys",
            yosys_synth_asic_verilog(
                cfg.top, cfg.topdir, cfg.liberty, cfg.clk_period_ns, cfg.opt, cfg.sdcdir, cfg.output,
                tie_hi=cfg.tie_hi, tie_lo=cfg.tie_lo, min_buffer=cfg.min_buffer,
            ),
        ))
        written.append(write_text(
            cfg.output / "synth_sv.ys",
            yosys_synth_asic_slang(
                cfg.top, cfg.liberty, cfg.clk_period_ns, cfg.opt, cfg.sdcdir, cfg.output, cfg.filelists,
                tie_hi=cfg.tie_hi, tie_lo=cfg.tie_lo, min_buffer=cfg.min_buffer,
            ),
        ))
    elif cfg.target == "xilinx":
        written.append(write_text(cfg.output / "synth.ys", yosys_synth_xilinx(cfg.top, cfg.topdir, cfg.output)))
        written.append(write_text(cfg.output / "xilinx.tcl", vivado_tcl_xilinx(cfg.top)))
    elif cfg.target == "ice40":
        written.append(write_text(cfg.output / "synth.ys", yosys_synth_ice40(cfg.top, cfg.topdir, cfg.output)))
    else:
        raise ValueError(f"Unsupported target: {cfg.target}")

    return tuple(written)


@dataclass(slots=True)
class SynthesisFlow:
    """Generate and execute ASIC/FPGA synthesis with explicit parameters."""

    runner: object | None = None

    def __post_init__(self) -> None:
        if self.runner is None:
            from flexsoc.backend.core.execution import ToolRunner
            self.runner = ToolRunner()

    def setup_asic(
        self,
        *,
        top: str,
        topdir: Path,
        liberty: Path,
        clk_period_ns: float,
        output: Path,
        opt: str = "area",
        filelists: Sequence[Path] = (Path("rtl_common.f"), Path("rtl_ip.f")),
        tie_hi: tuple[str, str] | None = None,
        tie_lo: tuple[str, str] | None = None,
        min_buffer: tuple[str, str, str] | None = None,
    ) -> tuple[Path, ...]:
        """Generate ASIC Yosys/ABC scripts without consuming SDC."""

        cfg = SynthesisConfig(
            top=top,
            topdir=topdir,
            target="asic",
            clk_period_ns=clk_period_ns,
            output=output,
            liberty=liberty,
            opt=opt,
            filelists=tuple(filelists),
            tie_hi=tie_hi,
            tie_lo=tie_lo,
            min_buffer=min_buffer,
        )
        return generate_synthesis_scripts(cfg)

    def setup_xilinx(
        self,
        *,
        top: str,
        topdir: Path,
        clk_period_ns: float,
        output: Path,
    ) -> tuple[Path, ...]:
        """Generate Yosys/Vivado scripts for Xilinx synthesis."""

        return generate_synthesis_scripts(SynthesisConfig(
            top=top, topdir=topdir, target="xilinx",
            clk_period_ns=clk_period_ns, output=output,
        ))

    def setup_ice40(
        self,
        *,
        top: str,
        topdir: Path,
        clk_period_ns: float,
        output: Path,
    ) -> tuple[Path, ...]:
        """Generate the iCE40 Yosys script."""

        return generate_synthesis_scripts(SynthesisConfig(
            top=top, topdir=topdir, target="ice40",
            clk_period_ns=clk_period_ns, output=output,
        ))

    def run_script(
        self,
        script: Path,
        *,
        log: Path,
        yosys: str = "yosys",
        on: str = "local",
        sv: bool = False,
        inputs: Sequence[Path] = (),
        outputs: Sequence[Path] = (),
    ) -> int:
        """Execute one generated Yosys script through the execution layer."""

        from flexsoc.backend.core.execution import CommandRequest

        argv = (yosys, "-s", str(script)) if sv else (yosys, str(script))
        request = CommandRequest(
            argv, script.parent, {}, log,
            inputs=tuple(dict.fromkeys((script.resolve(), *(path.resolve() for path in inputs)))),
            outputs=tuple(path.resolve() for path in outputs),
        )
        result = self.runner.run(request, on=on)
        self._diagnostics(log)
        return result.returncode

    def run_asic(
        self,
        *,
        output: Path,
        top: str,
        log_dir: Path,
        opt: str = "area",
        yosys: str = "yosys",
        systemverilog: bool = True,
        on: str = "local",
        inputs: Sequence[Path] = (),
    ) -> int:
        """Run the mapped ASIC synthesis script."""

        script = output / ("synth_sv.ys" if systemverilog else "synth.ys")
        if not script.is_file():
            raise FileNotFoundError(f"missing synthesis script: {script}")
        log = log_dir / f"{top}_synth_opt_{opt}.log"
        artifacts = tuple(output / f"{top}{suffix}" for suffix in (
            "_generic.il", "_dffmap.il", "_abc.il", "_clean.il", "_synth.v", "_synth.json",
        ))
        support = tuple(
            _repo_root() / "hw" / "ips" / name
            for name in ("pkgs", "prim", "prim_opentitan", "tlul")
        ) if systemverilog else ()
        return self.run_script(
            script, log=log, yosys=yosys, on=on, sv=systemverilog,
            inputs=(*inputs, *support), outputs=artifacts,
        )

    def run_yosys_vgen(
        self,
        *,
        top: str,
        cwd: Path,
        output: Path,
        yosys: str = "yosys",
        on: str = "local",
    ) -> int:
        """Convert the ordered SystemVerilog design to Verilog with Yosys."""

        from flexsoc.backend.core.execution import CommandRequest

        script = (
            "read_slang -I ips/pkgs -I ips/prim -I ips/prim_opentitan -I ips/tlul "
            "-D SYNTHESIS --ignore-assertions -f rtl/rtl_common.f -f rtl/rtl_ip.f "
            f"--top {top}; opt -keepdc; bwmuxmap; opt_clean; "
            f"write_verilog -norename -noattr {output}"
        )
        log = output.with_suffix(output.suffix + ".log")
        request = CommandRequest((yosys, "-p", script), cwd, {}, log)
        return self.runner.run(request, on=on).returncode

    def run_sv2v(
        self,
        sources: Sequence[Path],
        *,
        output: Path,
        sv2v: str = "sv2v",
        on: str = "local",
    ) -> int:
        """Convert selected SystemVerilog sources with sv2v when requested."""

        from flexsoc.backend.core.execution import CommandRequest

        log = output.with_suffix(output.suffix + ".log")
        request = CommandRequest((sv2v, *map(str, sources)), Path.cwd(), {}, log)
        result = self.runner.run(request, on=on)
        if result.returncode == 0:
            output.write_text(log.read_text(encoding="utf-8"), encoding="utf-8")
        return result.returncode

    @staticmethod
    def _diagnostics(log: Path) -> None:
        """Extract stable warning/error sidecars from one Yosys log."""

        if not log.is_file():
            return
        warning = re.compile(r"^(Warning:|%Warning-|.*:[0-9]+(?::[0-9]+)?:\s*warning:)", re.I)
        error = re.compile(r"^(ERROR:|%Error-|.*:[0-9]+(?::[0-9]+)?:\s*error:)", re.I)
        lines = log.read_text(encoding="utf-8", errors="replace").splitlines()
        for suffix, pattern in (("warnings", warning), ("errors", error)):
            rows = [line for line in lines if pattern.search(line)]
            log.with_suffix(f".{suffix}").write_text("\n".join(rows) + ("\n" if rows else ""), encoding="utf-8")

    def flow(self, *, setup: dict, run: dict) -> int:
        """Run the canonical setup followed by one synthesis execution."""

        target = setup.get("target", "asic")
        getattr(self, f"setup_{target}")(**{k: v for k, v in setup.items() if k != "target"})
        if target != "asic":
            return self.run_script(**run)
        return self.run_asic(**run)
