"""Synthesis and equivalence package API."""

from dataclasses import dataclass, field
from pathlib import Path

from ..core import BackendContext, Target, ToolRunner
from ..impl.impl import orfs_paths
from .eqy import EquivalenceConfig, EquivalenceFlow
from .syn import SynthesisConfig, SynthesisFlow


def _words(value: str) -> tuple[str, ...]:
    return tuple(part for part in str(value).replace(",", " ").split() if part)


def _tuple(value: str, size: int):
    parts = _words(value)
    return tuple(parts) if len(parts) == size else None


def _paths(context: BackendContext, value: str) -> tuple[Path, ...]:
    result: list[Path] = []
    for token in _words(value):
        path = Path(token).expanduser()
        if not path.is_absolute():
            path = context.project_root / path
        result.append(path.resolve())
    return tuple(result)


@dataclass(slots=True)
class Syn:
    """Group synthesis and RTL-to-gate equivalence."""

    context: BackendContext
    runner: ToolRunner | None = None
    synthesis: SynthesisFlow = field(init=False)
    eqy: EquivalenceFlow = field(init=False)

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)
        self.synthesis = SynthesisFlow(self.runner)
        self.eqy = EquivalenceFlow(self.runner)

    def setup_synthesis(self) -> object:
        """Generate synthesis collateral from the current backend context."""

        paths, values = self.context.paths, self.context.values
        target = values.get("TARGET_SYN", "asic").lower()
        period = float(values.get("CLK_PERIOD", "20"))
        if target in {"xilinx", "xc7"}:
            return self.synthesis.setup_xilinx(
                top=paths.top, topdir=paths.rtl, clk_period_ns=period, output=paths.syn,
            )
        if target in {"ice40", "ice"}:
            return self.synthesis.setup_ice40(
                top=paths.top, topdir=paths.rtl, clk_period_ns=period, output=paths.syn,
            )

        liberty = Path(values["LIB_SYN"])
        makefile, _ = orfs_paths(values, paths.impl)
        platform = values.get("ORS_TECH", values.get("PDK", ""))
        platform_config = makefile.parent / "platforms" / platform / "config.mk"
        if not makefile.is_file():
            raise FileNotFoundError(f"OpenROAD-flow-scripts Makefile not found: {makefile}")
        if not platform_config.is_file():
            raise FileNotFoundError(f"OpenROAD platform config not found: {platform_config}")
        return self.synthesis.setup_asic(
            top=paths.top,
            topdir=paths.rtl,
            liberty=liberty,
            clk_period_ns=period,
            output=paths.syn,
            sdc=paths.sdc,
            opt=values.get("TARGET_OPT", "delay1"),
            filelists=(paths.rtl_common, paths.rtl_ip),
            tie_hi=_tuple(values.get("TIEHI_CELL_AND_PORT", ""), 2),
            tie_lo=_tuple(values.get("TIELO_CELL_AND_PORT", ""), 2),
            min_buffer=_tuple(values.get("MIN_BUF_CELL_AND_PORTS", ""), 3),
            platform=platform,
        )

    def run_synthesis(self, target: Target, *, inputs=(), on: str = "local") -> int:
        """Run the configured synthesis target."""

        paths, values = self.context.paths, self.context.values
        libs = _paths(self.context, values.get("LIBS", ""))
        repair_liberty = libs[0] if libs else _paths(self.context, values["LIB_SYN"])[0]
        makefile, _ = orfs_paths(values, paths.impl)
        return self.synthesis.run_asic(
            output=paths.syn,
            top=paths.top,
            log_dir=paths.logs / "synthesis" / paths.pdk,
            opt=values.get("TARGET_OPT", "delay1"),
            yosys=values.get("YOSYS", "yosys"),
            systemverilog=(target.action != "syn_v" and values.get("VSV", "sv") != "v"),
            inputs=inputs,
            on=on,
            sdc=paths.sdc,
            repair_liberty=repair_liberty,
            platform=values.get("ORS_TECH", values.get("PDK", "")),
            orfs_makefile=makefile,
            openroad=values.get("OPENROAD", "openroad"),
        )

    def setup_eqy(self, *, on: str = "local") -> object:
        """Generate the EQY profile without running equivalence."""

        paths, values = self.context.paths, self.context.values
        layout = self.context.layout
        out = layout.equivalence_dir
        formal_proc = values.get("FORMAL_PDK_PROC")
        return self.eqy.setup(
            top=paths.top,
            output_dir=out,
            filelists=(paths.rtl_common, paths.rtl_ip),
            netlist=paths.syn / f"{paths.top}_synth.v",
            liberty=Path(values["LIB_SYN"]),
            cell_models=tuple(Path(item) for item in _words(values.get("PRIM", ""))),
            clock_gate_model=out / "sky130_clock_gates_formal.v",
            sat_depth=int(values.get("EQY_SAT_DEPTH", "20")),
            config=out / f"{paths.top}_rtl_vs_syn.eqy",
            formal_pdk_proc=Path(formal_proc) if formal_proc else None,
            force=str(values.get("FORCE", "0")).lower() in {"1", "true", "yes", "on"},
            pdr_engine=values.get("EQY_PDR_ENGINE", "abc pdr"),
            on=on,
            pdk=values.get("PDK", ""),
            multiclock=self.context.clocks.multiclock,
            reset_domains=tuple(
                (domain.signal, domain.reset, domain.reset_polarity)
                for domain in self.context.clocks.domains
            ),
        )

    def run_eqy(self, *, inputs=(), on: str = "local") -> int:
        """Run one prepared EQY profile."""

        paths, values = self.context.paths, self.context.values
        layout = self.context.layout
        return self.eqy.run(
            config=layout.equivalence_dir / f"{paths.top}_rtl_vs_syn.eqy",
            log=layout.equivalence_log,
            jobs=int(values.get("EQY_JOBS", "1")),
            eqy=values.get("EQY", "eqy"),
            inputs=inputs,
            on=on,
        )

    def _rtl_sources(self) -> tuple[Path, ...]:
        """Return ordered RTL sources from the canonical filelists."""

        sources: list[Path] = []
        for filelist in (self.context.paths.rtl_common, self.context.paths.rtl_ip):
            if not filelist.is_file():
                continue
            for raw in filelist.read_text(encoding="utf-8").splitlines():
                item = raw.strip()
                if item and not item.startswith(("#", "+", "-")):
                    sources.append(Path(item))
        return tuple(sources)

    def run_target(self, target: Target, *, inputs=(), on: str = "local") -> object:
        """Execute one registered synthesis/equivalence target."""

        paths, values = self.context.paths, self.context.values
        if target.action == "yosys_vgen":
            return self.synthesis.run_yosys_vgen(
                top=paths.top, cwd=paths.run, output=paths.rtl / f"{paths.top}.v",
                yosys=values.get("YOSYS", "yosys"), on=on,
            )
        if target.action == "sv2v":
            return self.synthesis.run_sv2v(
                self._rtl_sources(), output=paths.rtl / f"{paths.top}.v",
                sv2v=values.get("SV2V", "sv2v"), on=on,
            )
        if target.action == "syn_setup":
            return self.setup_synthesis()
        if target.action in {"syn", "syn_v", "syn_sv"}:
            return self.run_synthesis(target, inputs=inputs, on=on)
        if target.action == "eqy_setup":
            return self.setup_eqy(on=on)
        if target.action == "eqy":
            return self.run_eqy(inputs=inputs, on=on)
        raise ValueError(f"unsupported synthesis action: {target.action!r}")


__all__ = [
    "Syn", "SynthesisConfig", "SynthesisFlow",
    "EquivalenceConfig", "EquivalenceFlow",
]
