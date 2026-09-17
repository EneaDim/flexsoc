"""Formal scaffold and property verification flow."""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Sequence

from flexsoc.backend.core import ClockConfig
from flexsoc.backend.core.render.templates import templates


@dataclass(frozen=True, slots=True)
class PropertyFormalConfig:
    """Inputs required to build one authored-property SBY configuration."""

    top: str
    filelists: tuple[Path, ...]
    properties_dir: Path
    mode: str
    engine: str
    depth: int
    output: Path
    bmc_engine: str = "smtbmc bitwuzla"
    bmc_depth: int = 30
    bmc_append: int = 5
    multiclock: bool = False


@dataclass(slots=True)
class FormalFlow:
    """Create property-formal scaffolds and SBY configurations."""

    runner: object | None = None

    def init_properties(
        self, top: str, formal_dir: Path, *, multiclock: bool | None = None
    ) -> tuple[Path, ...]:
        """Create or preserve designer-owned property sources."""

        return FormalFlow.generate_scaffold(top, formal_dir, multiclock=multiclock)

    def setup_design(
        self,
        *,
        top: str,
        filelists: Sequence[Path],
        properties_dir: Path,
        mode: str,
        engine: str,
        output: Path,
        depth: int = 20,
        bmc_engine: str = "smtbmc bitwuzla",
        bmc_depth: int = 30,
        bmc_append: int = 5,
        multiclock: bool | None = None,
    ) -> Path:
        """Generate one authored-property SBY configuration."""

        cfg = PropertyFormalConfig(
            top=top,
            filelists=tuple(filelists),
            properties_dir=properties_dir,
            mode=mode,
            engine=engine,
            depth=depth,
            output=output,
            bmc_engine=bmc_engine,
            bmc_depth=bmc_depth,
            bmc_append=bmc_append,
            multiclock=ClockConfig.from_values().multiclock if multiclock is None else multiclock,
        )
        return FormalFlow.generate_property_config(cfg)

    def setup_csr(
        self,
        *,
        top: str,
        filelists: Sequence[Path],
        properties_dir: Path,
        generated: Path,
        mode: str,
        engine: str,
        output: Path,
        depth: int = 20,
        bmc_engine: str = "smtbmc bitwuzla",
        bmc_depth: int = 30,
        bmc_append: int = 5,
        multiclock: bool | None = None,
    ) -> Path:
        """Generate automatic CSR properties and their SBY configuration."""

        cfg = PropertyFormalConfig(
            top=top,
            filelists=tuple(filelists),
            properties_dir=properties_dir,
            mode=mode,
            engine=engine,
            depth=depth,
            output=output,
            bmc_engine=bmc_engine,
            bmc_depth=bmc_depth,
            bmc_append=bmc_append,
            multiclock=ClockConfig.from_values().multiclock if multiclock is None else multiclock,
        )
        return FormalFlow.generate_csr_config(cfg, generated)
    def _run_sby(
        self,
        config: Path,
        *,
        task: str | None,
        run_name: str | None,
        log: Path,
        sby: str = "sby",
        inputs: Sequence[Path] = (),
        on: str = "local",
    ):
        """Execute one SBY task with deterministic cwd and logging."""
        from flexsoc.backend.core import CommandRequest, ToolRunner
        runner = self.runner or ToolRunner()
        if not config.is_file():
            raise FileNotFoundError(f"formal configuration not found: {config}")
        argv = [sby, "-f"]
        if run_name:
            argv += ["-d", run_name]
        argv.append(config.name)
        if task:
            argv.append(task)
        declared = tuple(
            dict.fromkeys((config.resolve(), *(path.resolve() for path in inputs)))
        )
        output = config.parent / (run_name or config.stem)
        result = runner.run(
            CommandRequest(
                tuple(argv), config.parent, {}, log, inputs=declared, outputs=(output,),
            ),
            on=on,
        )
        if result.returncode:
            raise RuntimeError(f"formal task failed; log: {log}")
        return result

    def run_bmc(
        self, config: Path, *, top: str, log: Path,
        sby: str = "sby", inputs: Sequence[Path] = (), on: str = "local",
    ):
        """Run authored-property bounded model checking."""
        return self._run_sby(
            config, task="bmc", run_name=f"{top}_bmc", log=log, sby=sby, inputs=inputs, on=on
        )

    def run_prove(
        self, config: Path, *, top: str, log: Path,
        sby: str = "sby", inputs: Sequence[Path] = (), on: str = "local",
    ):
        """Run authored-property induction/PDR proof."""
        return self._run_sby(
            config, task="prove", run_name=f"{top}_prove", log=log, sby=sby, inputs=inputs, on=on
        )

    def run_cover(
        self, config: Path, *, log: Path,
        sby: str = "sby", inputs: Sequence[Path] = (), on: str = "local",
    ):
        """Run authored-property cover analysis."""
        return self._run_sby(
            config, task=None, run_name=None, log=log, sby=sby, inputs=inputs, on=on
        )

    def run_csr_bmc(
        self, config: Path, *, top: str, log: Path,
        sby: str = "sby", inputs: Sequence[Path] = (), on: str = "local",
    ):
        """Run automatic CSR bounded model checking."""
        return self._run_sby(
            config, task="bmc", run_name=f"{top}_csr_bmc", log=log, sby=sby, inputs=inputs, on=on
        )

    def run_csr_prove(
        self, config: Path, *, top: str, log: Path,
        sby: str = "sby", inputs: Sequence[Path] = (), on: str = "local",
    ):
        """Run automatic CSR proof."""
        return self._run_sby(
            config, task="prove", run_name=f"{top}_csr_prove", log=log, sby=sby, inputs=inputs, on=on
        )

    def run_csr_cover(
        self, config: Path, *, log: Path,
        sby: str = "sby", inputs: Sequence[Path] = (), on: str = "local",
    ):
        """Run automatic CSR cover analysis."""
        return self._run_sby(
            config, task=None, run_name=None, log=log, sby=sby, inputs=inputs, on=on
        )

    @staticmethod
    def _config_from_context(context, *, csr: bool, mode: str) -> Path:
        paths = context.paths
        kind = "csr" if csr else "properties"
        name = f"{paths.top}_{'csr_' if csr else ''}{mode}.sby"
        return paths.formal / "runs" / kind / mode / name

    def setup_from_context(self, context, *, csr: bool, mode: str) -> Path:
        """Generate one formal scaffold/configuration from BackendContext."""

        paths, values = context.paths, context.values
        top = paths.top
        self.init_properties(top, paths.formal, multiclock=context.clocks.multiclock)
        props = paths.formal / ("csr" if csr else "properties") / mode
        output = self._config_from_context(context, csr=csr, mode=mode)
        output.parent.mkdir(parents=True, exist_ok=True)
        kwargs = dict(
            top=top,
            filelists=(paths.rtl_common, paths.rtl_ip),
            properties_dir=props,
            mode=mode,
            engine=values.get(
                "FORMAL_PROVE_ENGINE" if mode == "prove" else "FORMAL_COVER_ENGINE",
                "abc pdr" if mode == "prove" else "btor btormc",
            ),
            output=output,
            depth=int(values.get("FORMAL_DEPTH", "20")),
            bmc_engine=values.get("FORMAL_BMC_ENGINE", "smtbmc bitwuzla"),
            bmc_depth=int(values.get("FORMAL_BMC_DEPTH", "30")),
            bmc_append=int(values.get("FORMAL_BMC_APPEND", "5")),
            multiclock=context.clocks.multiclock,
        )
        if csr:
            return self.setup_csr(
                **kwargs, generated=props / f"{top}_csr_auto_{mode}.sv",
            )
        return self.setup_design(**kwargs)

    def run_target(self, target, context, *, inputs=(), on: str = "local"):
        """Execute one registered formal setup or run target."""

        action = target.action or ""
        if action in {"formal_setup", "formal_csr_setup"}:
            return self.setup_from_context(
                context, csr=action == "formal_csr_setup", mode=target.stage or "prove",
            )

        paths, values = context.paths, context.values
        csr = action.startswith("formal_csr_")
        mode = action.rsplit("_", 1)[-1]
        config_mode = "cover" if mode == "cover" else "prove"
        config = self._config_from_context(context, csr=csr, mode=config_mode)
        suite = "csr" if csr else "properties"
        log = paths.logs / "dv" / "formal" / suite / f"{paths.top}_{mode}.log"
        method = getattr(self, f"run_{'csr_' if csr else ''}{mode}")
        kwargs = dict(log=log, sby=values.get("SBY", "sby"), inputs=inputs, on=on)
        if mode != "cover":
            kwargs["top"] = paths.top
        return method(config, **kwargs)

    @staticmethod
    def _resolved(paths: Sequence[Path]) -> tuple[Path, ...]:
        """Resolve paths without requiring them to share a common parent."""
    
        return tuple(path.expanduser().resolve() for path in paths)

    @staticmethod
    def _require_files(paths: Sequence[Path], *, label: str) -> tuple[Path, ...]:
        """Return resolved paths or fail early with an actionable error."""
    
        resolved = FormalFlow._resolved(paths)
        missing = [path for path in resolved if not path.is_file()]
        if missing:
            rendered = "\n  ".join(str(path) for path in missing)
            raise ValueError(f"missing {label}:\n  {rendered}")
        return resolved

    @staticmethod
    def property_files(directory: Path, *, required: bool = True) -> tuple[Path, ...]:
        """Return authored Verilog/SystemVerilog property files recursively."""
    
        root = directory.expanduser().resolve()
        if not root.is_dir():
            if not required:
                return ()
            raise ValueError(
                f"formal property directory does not exist: {root}\n"
                "create it and add at least one .sv/.v property file before running formal"
            )
        files = tuple(
            sorted(
                path.resolve()
                for path in root.rglob("*")
                if path.is_file() and path.suffix.lower() in {".sv", ".v"}
            )
        )
        if not files and required:
            raise ValueError(
                f"no formal property files found under: {root}\n"
                "FlexSoC refuses to report a vacuous formal PASS with zero authored properties"
            )
        return files

    @staticmethod
    def _read_slang_command(
        *,
        top: str,
        filelists: Sequence[Path],
        extra_sources: Sequence[Path] = (),
        formal: bool,
    ) -> str:
        """Render the canonical Slang-backed Yosys frontend command."""
    
        define = "FORMAL" if formal else "SYNTHESIS"
        options = [f"-D {define}"]
        if not formal:
            options.append("--ignore-assertions")
        # yosys-slang forwards literal quote characters in command-file arguments.
        # FlexSoC run paths have no spaces, so pass filelist/source paths unquoted.
        options.extend(f"-f {path}" for path in filelists)
        options.extend(str(path) for path in extra_sources)
        options.append(f"--top {top}")
        return "read_slang " + " ".join(options)

    @staticmethod
    def render_csr_properties(mode: str) -> str:
        """Render automatic prove or cover checks for reggen CSR primitives."""
    
        name = "csr_cover.sv.j2" if mode == "cover" else "csr_prove.sv.j2"
        return templates.render(f"dv/formal/{name}")

    @staticmethod
    def render_design_prove(top: str, *, multiclock: bool) -> str:
        """Render starter assertions for the generated single- or N-clock core."""
    
        kind = "multiclock" if multiclock else "single"
        return templates.render(f"dv/formal/design_prove_{kind}.sv.j2", top=top)

    @staticmethod
    def render_design_cover(top: str, *, multiclock: bool) -> str:
        """Render starter covers for the generated single- or N-clock core."""
    
        kind = "multiclock" if multiclock else "single"
        return templates.render(f"dv/formal/design_cover_{kind}.sv.j2", top=top)

    @staticmethod
    def _write_scaffold(path: Path, text: str, *, incompatible: str | None = None) -> Path:
        """Create one designer-owned starter and reject an untouched stale topology."""
    
        path.parent.mkdir(parents=True, exist_ok=True)
        if path.exists():
            if incompatible is not None and path.read_text(encoding="utf-8") == incompatible:
                raise ValueError(
                    f"formal scaffold topology changed: {path}; preserve authored work, "
                    "then remove or update the stale generated starter"
                )
            return path.resolve()
        path.write_text(text, encoding="utf-8")
        return path.resolve()

    @staticmethod
    def generate_scaffold(
        top: str, formal_dir: Path, *, multiclock: bool | None = None
    ) -> tuple[Path, ...]:
        """Create non-destructive design-property starters for the generated core."""
    
        root = formal_dir.expanduser().resolve() / "properties"
        is_multiclock = ClockConfig.from_values().multiclock if multiclock is None else multiclock
        prove = FormalFlow._write_scaffold(
            root / "prove" / f"{top}_prove.sv",
            FormalFlow.render_design_prove(top, multiclock=is_multiclock),
            incompatible=FormalFlow.render_design_prove(top, multiclock=not is_multiclock),
        )
        cover = FormalFlow._write_scaffold(
            root / "cover" / f"{top}_cover.sv",
            FormalFlow.render_design_cover(top, multiclock=is_multiclock),
            incompatible=FormalFlow.render_design_cover(top, multiclock=not is_multiclock),
        )
        return prove, cover

    @staticmethod
    def render_sby(cfg: PropertyFormalConfig, generated_sources: Sequence[Path] = ()) -> str:
        """Render one prove/BMC task file or one cover configuration."""
    
        if cfg.mode not in {"prove", "cover"}:
            raise ValueError(f"unsupported formal mode: {cfg.mode!r}")
        if cfg.depth <= 0:
            raise ValueError("formal depth must be > 0")
        if not cfg.engine.strip():
            raise ValueError("formal engine must not be empty")
        if cfg.mode == "prove" and (cfg.bmc_depth <= 0 or cfg.bmc_append < 0 or not cfg.bmc_engine.strip()):
            raise ValueError("BMC engine/depth/append are invalid")
    
        filelists = FormalFlow._require_files(cfg.filelists, label="RTL filelist(s)")
        generated = FormalFlow._require_files(generated_sources, label="generated property source(s)") if generated_sources else ()
        authored = tuple(
            path for path in FormalFlow.property_files(cfg.properties_dir, required=not generated)
            if path not in generated
        )
        properties = (*generated, *authored)
        read_cmd = FormalFlow._read_slang_command(
            top=cfg.top,
            filelists=filelists,
            extra_sources=properties,
            formal=True,
        )
    
        if cfg.mode == "prove":
            header = [
                "[tasks]",
                "bmc",
                "prove",
                "",
                "[options]",
                "bmc: mode bmc",
                f"bmc: depth {cfg.bmc_depth}",
                f"bmc: append {cfg.bmc_append}",
                *(["bmc: multiclock on"] if cfg.multiclock else []),
                "prove: mode prove",
                *(["prove: multiclock on"] if cfg.multiclock else []),
                "",
                "[engines]",
                f"bmc: {cfg.bmc_engine.strip()}",
                f"prove: {cfg.engine.strip()}",
            ]
        else:
            header = [
                "[options]",
                "mode cover",
                f"depth {cfg.depth}",
                *(["multiclock on"] if cfg.multiclock else []),
                "cover_assert off",
                "",
                "[engines]",
                cfg.engine.strip(),
            ]
    
        return templates.render(
            "dv/formal/sby.sby.j2",
            header="\n".join(header),
            read_cmd=read_cmd,
            top=cfg.top,
        )

    @staticmethod
    def write_config(path: Path, text: str) -> Path:
        """Write one generated formal configuration."""
    
        output = path.expanduser().resolve()
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(text, encoding="utf-8")
        return output

    @staticmethod
    def generate_property_config(
        cfg: PropertyFormalConfig, generated_sources: Sequence[Path] = ()
    ) -> Path:
        """Generate one SBY file and return its path."""
    
        return FormalFlow.write_config(cfg.output, FormalFlow.render_sby(cfg, generated_sources))

    @staticmethod
    def generate_csr_config(cfg: PropertyFormalConfig, generated: Path) -> Path:
        """Generate automatic CSR properties plus one SBY configuration."""
    
        source = FormalFlow.write_config(generated, FormalFlow.render_csr_properties(cfg.mode))
        return FormalFlow.generate_property_config(cfg, (source,))
