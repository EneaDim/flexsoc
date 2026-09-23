"""RTL-to-synthesis equivalence setup and diagnostics."""

from __future__ import annotations

from io import StringIO
import json
import os
import re
import shutil
import sys
from dataclasses import asdict, dataclass, replace
from pathlib import Path
from typing import Iterable, Mapping, Sequence

from rich.console import Console

from flexsoc.backend.core import ClockConfig, PDKRunLayout
from flexsoc.backend.core.runtime.execution import CommandRequest
from flexsoc.backend.core.render.show import ShowRenderer
from flexsoc.backend.core.render.templates import templates

@dataclass(frozen=True, slots=True)
class NetlistPort:
    """One simple top-level port recovered from a synthesized netlist."""

    direction: str
    name: str
    packed_range: str = ""

    @property
    def width(self) -> int | None:
        """Return a constant packed width, or ``None`` for symbolic ranges."""

        if not self.packed_range:
            return 1
        match = re.fullmatch(r"\[\s*(-?\d+)\s*:\s*(-?\d+)\s*\]", self.packed_range)
        return abs(int(match.group(1)) - int(match.group(2))) + 1 if match else None

    def declaration(self) -> str:
        """Render an ANSI-style wrapper declaration."""

        packed = f" {self.packed_range}" if self.packed_range else ""
        return f"{self.direction} wire{packed} {self.name}"


@dataclass(frozen=True, slots=True)
class EquivalenceConfig:
    """Inputs required to compare RTL against a synthesized gate netlist."""

    top: str
    filelists: tuple[Path, ...]
    netlist: Path
    liberty: Path
    cell_models: tuple[Path, ...]
    sky130_clock_gate_model: Path
    sat_depth: int
    output: Path
    formal_cell_model: Path | None = None
    formal_pdk_proc: Path | None = None
    pdk: str = ""
    timeout: int = 60
    quick_timeout: int = 5
    multiclock: bool = False
    splitnets: str = "off"
    use_sat: bool = False
    use_pdr: bool = False
    pdr_engine: str = "abc pdr"
    smt_engine: str = "smtbmc bitwuzla"
    smt_depth: int = 5
    xprop: str = "on"
    formal_view: Path | None = None
    join_outputs: bool = True
    strategy_order: tuple[str, ...] = ()
    reset_normalize: bool = False
    reset_cycles: int = 2
    reset_domains: tuple[tuple[str, str, str], ...] = ()


_STATUS_ORDER = {"FAIL": 5, "ERROR": 4, "TIMEOUT": 3, "UNKNOWN": 2, "PASS": 1, "MISSING": 0}
_TRACE_NAMES = ("trace.vcd", "trace_induct.vcd", "trace.yw", "trace.smtc", "trace_tb.v")
_LOG_NAMES = ("logfile.txt", "logfile_basecase.txt", "logfile_induction.txt")
@dataclass(frozen=True, slots=True)
class StrategyResult:
    """One EQY strategy result for one partition."""

    name: str
    status: str
    directory: Path
    traces: tuple[Path, ...]
    logs: tuple[Path, ...]

    def to_dict(self) -> dict[str, object]:
        data = asdict(self)
        data["directory"] = str(self.directory)
        data["traces"] = [str(path) for path in self.traces]
        data["logs"] = [str(path) for path in self.logs]
        return data


@dataclass(frozen=True, slots=True)
class Counterexample:
    """Aggregate EQY result for one partition."""

    partition: str
    status: str
    directory: Path
    strategies: tuple[StrategyResult, ...]

    @property
    def failing_strategy(self) -> StrategyResult | None:
        """Return the non-PASS strategy that carries the best diagnostic evidence."""

        candidates = [item for item in self.strategies if item.status != "PASS"]
        if not candidates:
            return None

        def diagnostic_rank(item: StrategyResult) -> tuple[int, int, int, int]:
            vcd_count = sum(path.suffix.lower() == ".vcd" for path in item.traces)
            evidence_count = len(item.traces) + len(item.logs)
            executed = int(evidence_count > 0 or item.directory.name == self.partition)
            return (
                int(vcd_count > 0),
                int(evidence_count > 0),
                executed,
                _STATUS_ORDER.get(item.status, 0),
            )

        return max(candidates, key=diagnostic_rank)

    def to_dict(self) -> dict[str, object]:
        return {
            "partition": self.partition,
            "status": self.status,
            "directory": str(self.directory),
            "strategies": [item.to_dict() for item in self.strategies],
            "failing_strategy": self.failing_strategy.name if self.failing_strategy else None,
        }


@dataclass(slots=True)
class Eqy:
    """Prepare, run, inspect and diagnose RTL-to-synthesis equivalence."""

    runner: object | None = None

    def __post_init__(self) -> None:
        if self.runner is None:
            from flexsoc.backend.core.runtime.execution import ToolRunner
            self.runner = ToolRunner()

    def config(
        self,
        *,
        top: str,
        filelists: Sequence[Path],
        netlist: Path,
        liberty: Path,
        cell_models: Sequence[Path],
        clock_gate_model: Path,
        sat_depth: int,
        output: Path,
        formal_pdk_proc: Path | None = None,
        timeout: int = 60,
        quick_timeout: int = 5,
        pdr_engine: str | None = None,
        pdk: str | None = None,
        multiclock: bool | None = None,
        reset_domains: Sequence[tuple[str, str, str]] | None = None,
    ) -> EquivalenceConfig:
        """Build a configuration from explicit inputs and active clock intent."""

        clocks = ClockConfig.from_values()
        resolved_multiclock = clocks.multiclock if multiclock is None else bool(multiclock)
        resolved_reset_domains = (
            tuple((d.signal, d.reset, d.reset_polarity) for d in clocks.domains)
            if reset_domains is None else tuple(reset_domains)
        )
        raw_order = os.environ.get("EQY_STRATEGY_ORDER", "auto").strip().lower()
        order = () if raw_order in {"", "auto"} else tuple(
            token.strip() for token in raw_order.split(",") if token.strip()
        )
        return EquivalenceConfig(
            top=top,
            filelists=tuple(filelists),
            netlist=netlist,
            liberty=liberty,
            cell_models=tuple(cell_models),
            formal_pdk_proc=formal_pdk_proc,
            pdk=(pdk or os.environ.get("FLEXSOC_PDK", "")).strip().lower(),
            sky130_clock_gate_model=clock_gate_model,
            sat_depth=sat_depth,
            output=output,
            timeout=int(os.environ.get("EQY_TIMEOUT", "30" if resolved_multiclock else str(timeout))),
            quick_timeout=int(os.environ.get("EQY_QUICK_TIMEOUT", str(quick_timeout))),
            multiclock=resolved_multiclock,
            splitnets=os.environ.get("EQY_SPLITNETS", "off").strip().lower(),
            use_sat=Eqy._env_bool("EQY_USE_SAT", not resolved_multiclock),
            use_pdr=Eqy._env_bool("EQY_USE_PDR", True),
            pdr_engine=(
                pdr_engine.strip()
                if pdr_engine is not None and pdr_engine.strip()
                else os.environ.get("EQY_PDR_ENGINE", "abc pdr").strip() or "abc pdr"
            ),
            smt_engine=os.environ.get("EQY_SMT_ENGINE", "smtbmc bitwuzla").strip(),
            smt_depth=int(os.environ.get("EQY_SMT_DEPTH", "5" if resolved_multiclock else "2")),
            xprop=os.environ.get("EQY_XPROP", "on").strip().lower(),
            join_outputs=Eqy._env_bool("EQY_JOIN_OUTPUTS", True),
            strategy_order=order,
            reset_normalize=Eqy._env_bool("EQY_RESET_NORMALIZE", not resolved_multiclock),
            reset_cycles=int(os.environ.get("EQY_RESET_CYCLES", "2")),
            reset_domains=resolved_reset_domains,
        )

    def setup(
        self,
        *,
        top: str,
        output_dir: Path,
        filelists: Sequence[Path],
        netlist: Path,
        liberty: Path,
        cell_models: Sequence[Path],
        clock_gate_model: Path,
        sat_depth: int,
        config: Path,
        formal_pdk_proc: Path | None = None,
        force: bool = False,
        on: str = "local",
        pdr_engine: str | None = None,
        pdk: str | None = None,
        multiclock: bool | None = None,
        reset_domains: Sequence[tuple[str, str, str]] | None = None,
    ) -> tuple[Path, Path]:
        """Bind the portable view and generate the EQY config when required."""

        Eqy.bind_equivalence_profile(
            top=top,
            output_dir=output_dir,
            filelists=filelists,
            netlist=netlist,
            liberty=liberty,
            cell_models=cell_models,
            formal_pdk_proc=formal_pdk_proc,
            clock_gate_model=clock_gate_model,
            config=config if config.is_file() and not force else None,
            runner=self.runner,
            on=on,
            pdk=pdk,
        )
        view = output_dir / f"{top}_eqy_view.sv"
        if force or not config.is_file():
            cfg = self.config(
                top=top,
                filelists=filelists,
                netlist=netlist,
                liberty=liberty,
                cell_models=cell_models,
                clock_gate_model=clock_gate_model,
                formal_pdk_proc=formal_pdk_proc,
                sat_depth=sat_depth,
                output=config,
                pdr_engine=pdr_engine,
                pdk=pdk,
                multiclock=multiclock,
                reset_domains=reset_domains,
            )
            Eqy.generate_equivalence_config(cfg, runner=self.runner, on=on)
        Eqy._ensure_formal_view_artifact(config, view)
        return config, view

    def run(
        self,
        *,
        config: Path,
        log: Path,
        jobs: int = 1,
        eqy: str = "eqy",
        inputs: Sequence[Path] = (),
        on: str = "local",
    ) -> int:
        """Run one prepared EQY profile and publish canonical partition evidence."""

        result_dir = config.parent / config.stem
        if result_dir.is_dir():
            shutil.rmtree(result_dir)
        request = CommandRequest(
            (eqy, "-j", str(jobs), "-f", config.name),
            config.parent,
            {},
            log,
            inputs=tuple(dict.fromkeys((config.absolute(), *(path.absolute() for path in inputs)))),
            outputs=(result_dir.resolve(),),
        )
        result = self.runner.run(request, on=on)
        self._write_summary(
            config, log, result_dir, result.returncode,
            float(getattr(result, "duration_s", 0.0)), request.argv,
        )
        return result.returncode

    def debug(
        self, summary_path: Path, *, run_root: Path, output: str | None = None,
        project_root: Path | None = None, as_json: bool = False,
    ) -> int:
        """Show canonical EQY evidence plus existing failing logs and traces."""

        return self.show(
            summary_path, run_root=run_root, debug=True, output=output,
            project_root=project_root, as_json=as_json,
        )

    def show(
        self, summary_path: Path, *, run_root: Path, summary: bool = False,
        debug: bool = False, output: str | None = None, project_root: Path | None = None,
        as_json: bool = False,
    ) -> int:
        """Render existing EQY evidence; debug only adds paths and failing traces."""

        if not summary_path.is_file():
            raise FileNotFoundError(f"EQY summary not found: {summary_path}; run `fx eqy` first")
        document = ShowRenderer.load_file(run_root, summary_path.relative_to(run_root).as_posix())
        data = dict(document.data)
        if summary:
            data["summary_only"] = True
            document = replace(document, data=data)

        capture = StringIO() if output else None
        console = Console(file=capture, force_terminal=False) if capture else Console()
        if as_json:
            print(json.dumps(data, indent=2, sort_keys=True), file=capture or None)
        else:
            ShowRenderer(console).render(document)
            if debug:
                self._show_debug(console, data)

        if output and capture is not None:
            destination = Path(output)
            if not destination.is_absolute() and project_root is not None:
                destination = project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(capture.getvalue(), encoding="utf-8")
        return 0

    def _write_summary(
        self, config: Path, log: Path, result_dir: Path, returncode: int,
        duration_s: float, command: Sequence[str],
    ) -> dict[str, object]:
        """Normalize native EQY partition/strategy results into summary.json."""

        results = Eqy.scan(result_dir)
        counts = {name: 0 for name in ("PASS", "FAIL", "ERROR", "TIMEOUT", "UNKNOWN", "MISSING")}
        strategies: dict[str, dict[str, int]] = {}
        partitions: list[dict[str, object]] = []
        for item in results:
            counts[item.status if item.status in counts else "UNKNOWN"] += 1
            row = item.to_dict()
            row["directory"] = Eqy._relative(item.directory, config.parent)
            normalized_strategies = []
            for strategy in item.strategies:
                bucket = strategies.setdefault(strategy.name, {name: 0 for name in counts})
                bucket[strategy.status if strategy.status in bucket else "UNKNOWN"] += 1
                entry = strategy.to_dict()
                entry["directory"] = Eqy._relative(strategy.directory, config.parent)
                entry["traces"] = [Eqy._relative(path, config.parent) for path in strategy.traces]
                entry["logs"] = [Eqy._relative(path, config.parent) for path in strategy.logs]
                normalized_strategies.append(entry)
            row["strategies"] = normalized_strategies
            partitions.append(row)

        if results and all(item.status == "PASS" for item in results):
            result_status = "PASS"
        elif any(item.status == "FAIL" for item in results) or (result_dir / "FAIL").is_file():
            result_status = "FAILED"
        elif any(item.status in {"ERROR", "TIMEOUT", "UNKNOWN"} for item in results):
            result_status = "REVIEW"
        elif (result_dir / "PASS").is_file():
            result_status = "PASS"
        else:
            result_status = "REVIEW"

        execution_status = "PASS" if returncode == 0 else "FAILED"
        if execution_status == "FAILED" or result_status == "FAILED":
            status = "FAILED"
        elif result_status == "PASS":
            status = "PASS"
        else:
            status = "REVIEW"
        top = config.stem.removesuffix("_rtl_vs_syn")
        summary = {
            "schema": "flexsoc.eqy.v1",
            "stage": "eqy",
            "status": status,
            "top": top,
            "execution": {
                "status": execution_status, "exit_code": int(returncode),
                "duration_s": float(duration_s), "command": list(command),
            },
            "result": {"status": result_status, "counts": counts, "total": len(results)},
            "strategies": strategies,
            "partitions": partitions,
            "artifacts": {
                "config": Eqy._relative(config, config.parent),
                "log": Eqy._relative(log, config.parent),
                "result_dir": Eqy._relative(result_dir, config.parent),
            },
        }
        path = config.parent / "summary.json"
        path.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return summary

    @staticmethod
    def _show_debug(console: Console, data: Mapping[str, object]) -> None:
        """Append unresolved EQY evidence without launching probes or viewers."""

        console.print()
        console.print("[bold]Debug evidence[/bold]")
        artifacts = data.get("artifacts", {})
        if isinstance(artifacts, Mapping):
            for name, path in artifacts.items():
                console.print(f"[grey70]{name}[/grey70] {path}")
        for item in data.get("partitions", ()) if isinstance(data.get("partitions"), list) else ():
            if not isinstance(item, Mapping) or item.get("status") == "PASS":
                continue
            console.print(
                f"[orange1]{item.get('status', 'UNKNOWN')}[/orange1] "
                f"[white]{item.get('partition', '-')}[/white]"
            )
            for strategy in item.get("strategies", ()) if isinstance(item.get("strategies"), list) else ():
                if not isinstance(strategy, Mapping) or strategy.get("status") == "PASS":
                    continue
                console.print(
                    f"  [grey70]{strategy.get('name', '-')}[/grey70] "
                    f"{strategy.get('status', 'UNKNOWN')}"
                )
                for path in strategy.get("logs", ()) if isinstance(strategy.get("logs"), list) else ():
                    console.print(f"    [grey70]log[/grey70] {path}")
                for path in strategy.get("traces", ()) if isinstance(strategy.get("traces"), list) else ():
                    console.print(f"    [grey70]trace[/grey70] {path}")

    @staticmethod
    def _relative(path: Path, root: Path) -> str:
        try:
            return path.resolve().relative_to(root.resolve()).as_posix()
        except ValueError:
            return str(path)

    @staticmethod
    def optional_path(value: str | None) -> Path | None:
        """Return a path for non-empty values and ``None`` for missing CLI inputs."""

        return Path(value) if value else None

    @staticmethod
    def split_liberties(values: Sequence[str]) -> list[Path]:
        """Expand repeated or comma-separated liberty arguments into paths."""

        return [Path(token.strip()) for item in values for token in str(item).split(",") if token.strip()]

    @staticmethod
    def _resolved(paths: Sequence[Path]) -> tuple[Path, ...]:
        return tuple(path.expanduser().resolve() for path in paths)

    @staticmethod
    def _require_files(paths: Sequence[Path], *, label: str) -> tuple[Path, ...]:
        resolved = Eqy._resolved(paths)
        missing = [path for path in resolved if not path.is_file()]
        if missing:
            rendered = "\n  ".join(str(path) for path in missing)
            raise ValueError(f"missing {label}:\n  {rendered}")
        return resolved

    @staticmethod
    def _netlist_port_decls(netlist: Path, top: str) -> tuple[NetlistPort, ...]:
        """Return simple top-level declarations from a Yosys Verilog netlist."""

        text = netlist.read_text(encoding="utf-8", errors="replace")
        module = re.search(
            rf"(?ms)^\s*module\s+{re.escape(top)}\s*\(.*?^\s*endmodule\b",
            text,
        )
        if module is None:
            raise ValueError(f"cannot find top module {top!r} in synthesized netlist: {netlist}")

        ports: list[NetlistPort] = []
        for decl in re.finditer(r"\b(input|output|inout)\b([^;]*);", module.group(0)):
            direction, body = decl.groups()
            range_match = re.search(r"\[[^]]+\]", body)
            packed_range = range_match.group(0) if range_match else ""
            body = re.sub(r"\[[^]]+\]", " ", body)
            body = re.sub(r"\b(?:wire|logic|reg|signed|unsigned)\b", " ", body)
            for item in body.split(","):
                tokens = item.split()
                if tokens and re.fullmatch(r"[A-Za-z_][A-Za-z0-9_$]*", tokens[-1]):
                    port = NetlistPort(direction, tokens[-1], packed_range)
                    if port.name not in {known.name for known in ports}:
                        ports.append(port)

        if not ports:
            raise ValueError(f"cannot discover top-level ports in synthesized netlist: {netlist}")
        return tuple(ports)

    @staticmethod
    def _netlist_ports(netlist: Path, top: str) -> tuple[str, ...]:
        """Return top-level port names from a synthesized Verilog netlist."""

        return tuple(port.name for port in Eqy._netlist_port_decls(netlist, top))

    @staticmethod
    def _tlul_response_ports(ports: Sequence[NetlistPort]) -> tuple[NetlistPort, ...]:
        """Discover packed TL-UL device responses by public name and ABI width."""

        return tuple(
            port for port in ports
            if port.direction == "output"
            and port.width == 66
            and (port.name == "tl_o" or port.name.endswith("_tl_o"))
        )

    @staticmethod
    def _tlul_contract_ports(ports: Sequence[NetlistPort]) -> tuple[NetlistPort, ...]:
        """Return the formal contract ports used to partition TL-UL responses."""

        responses = {port.name for port in Eqy._tlul_response_ports(ports)}
        contract: list[NetlistPort] = []
        for port in ports:
            if port.name not in responses:
                contract.append(port)
                continue
            prefix = f"{port.name}__flexsoc_eqy"
            contract.extend((
                NetlistPort("output", f"{prefix}_handshake", "[1:0]"),
                NetlistPort("output", f"{prefix}_d_ctrl", "[16:0]"),
                NetlistPort("output", f"{prefix}_d_data", "[31:0]"),
                NetlistPort("output", f"{prefix}_d_meta", "[14:0]"),
            ))
        return tuple(contract)

    @staticmethod
    def render_formal_protocol_view(top: str, ports: Sequence[NetlistPort]) -> str:
        """Render a symmetric formal view for protocol-defined don't-care outputs."""

        responses = {port.name for port in Eqy._tlul_response_ports(ports)}
        if not responses:
            return ""
        impl = f"{top}__eqy_impl"
        contract_ports = Eqy._tlul_contract_ports(ports)
        witnesses = tuple(port for port in contract_ports if "__flexsoc_eqy_" in port.name)
        view_ports = tuple(port for port in ports if port.name not in responses) + witnesses
        original_names = {port.name for port in ports}
        if any(port.name in original_names for port in witnesses):
            raise ValueError("formal TL-UL witness name collides with a design port")
        port_declarations = "\n".join(
            f"  {port.declaration()}{',' if index + 1 < len(view_ports) else ''}"
            for index, port in enumerate(view_ports)
        )
        raw_wires = "\n".join(
            f"  wire [65:0] {port.name}__raw;" for port in ports if port.name in responses
        )
        implementation_ports = "\n".join(
            f"    .{port.name} ({port.name + '__raw' if port.name in responses else port.name})"
            f"{',' if index + 1 < len(ports) else ''}"
            for index, port in enumerate(ports)
        )
        assignments: list[str] = []
        for name in sorted(responses):
            raw = f"{name}__raw"
            prefix = f"{name}__flexsoc_eqy"
            assignments.extend((
                f"  assign {prefix}_handshake = {{{raw}[65], {raw}[0]}};",
                f"  assign {prefix}_d_ctrl = {raw}[65] ? {raw}[64:48] : '0;",
                f"  assign {prefix}_d_data = ({raw}[65] && ({raw}[64:62] == 3'h1) && !{raw}[1]) ? {raw}[47:16] : '0;",
                f"  assign {prefix}_d_meta = {raw}[65] ? {raw}[15:1] : '0;",
                "",
            ))
        return templates.render(
            "syn/eqy/formal_protocol_view.sv.j2",
            top=top, impl=impl, port_declarations=port_declarations, raw_wires=raw_wires,
            implementation_ports=implementation_ports, witness_assignments="\n".join(assignments),
        )

    @staticmethod
    def _prepare_formal_protocol_view(cfg: EquivalenceConfig) -> EquivalenceConfig:
        """Write a formal-only wrapper when the top exposes supported protocols."""

        body = Eqy.render_formal_protocol_view(cfg.top, Eqy._netlist_port_decls(cfg.netlist, cfg.top))
        if not body:
            return cfg
        path = cfg.output.expanduser().resolve().parent / f"{cfg.top}_eqy_view.sv"
        return replace(cfg, formal_view=Eqy.write_text(path, body))

    @staticmethod
    def _eqy_match_sections(top: str, ports: Sequence[NetlistPort]) -> list[str]:
        """Match only the canonical external contract and formal witnesses."""

        return [
            f"[match {top}]",
            "nodefault",
            *(f"gold-match {port.name}" for port in ports),
            "",
        ]

    @staticmethod
    def _eqy_collect_sections(top: str, ports: Sequence[NetlistPort], *, enabled: bool) -> list[str]:
        """Keep every top-level output bus in one equivalence partition."""

        buses = [
            port.name for port in ports
            if enabled and port.direction == "output" and (port.width or 0) > 1
        ]
        return [f"[collect {top}]", *(f"join {name}" for name in buses), ""] if buses else []

    @staticmethod
    def _read_slang_synthesis(top: str, filelists: Sequence[Path]) -> str:
        """Render the canonical Slang/Yosys synthesis frontend for EQY gold RTL."""

        options = ["-D SYNTHESIS", "--ignore-assertions"]
        options.extend(f"-f {path}" for path in filelists)
        options.append(f"--top {top}")
        return "read_slang " + " ".join(options)

    @staticmethod
    def render_sky130_clock_gate_model() -> str:
        """Render formal-compatible SKY130 integrated clock-gate models."""

        drives = (1, 2, 4)
        return templates.render(
            "syn/eqy/sky130_clock_gates.sv.j2",
            dlclkp=tuple(f"sky130_fd_sc_hd__dlclkp_{drive}" for drive in drives),
            sdlclkp=tuple(f"sky130_fd_sc_hd__sdlclkp_{drive}" for drive in drives),
        )

    @staticmethod
    def _active_pdk(cfg: EquivalenceConfig) -> str:
        """Return the explicit PDK identity, with ambient env only as compatibility fallback."""

        return cfg.pdk.strip().lower() or os.environ.get("FLEXSOC_PDK", "").strip().lower()

    @staticmethod
    def _gate_model_reads(
        cfg: EquivalenceConfig,
        *,
        liberty: Path,
        netlist: Path,
        cell_models: Sequence[Path],
    ) -> list[str]:
        """Read functional cell models when safe, otherwise use Liberty fallback."""

        pdk = Eqy._active_pdk(cfg)
        reads: list[str] = []
        if cfg.formal_cell_model is not None:
            reads.append(f"read_verilog -formal -sv {cfg.formal_cell_model}")
        elif pdk == "ihp-sg13g2":
            # IHP aggregate Verilog uses specify syntax Yosys cannot parse for EQY.
            # Use the discovered Liberty view as the formal cell semantics instead.
            reads.append(f"read_liberty -ignore_miss_func {liberty}")
        elif cell_models and pdk != "sky130":
            rendered = " ".join(str(path) for path in cell_models)
            reads.append(f"read_verilog -formal -sv -DFUNCTIONAL {rendered}")
        else:
            reads.append(f"read_liberty -ignore_miss_func {liberty}")
            if pdk == "sky130":
                reads.append(f"read_verilog -formal -sv {cfg.sky130_clock_gate_model.expanduser().resolve()}")
        reads.append(f"read_verilog -formal -sv {netlist}")
        return reads

    @staticmethod
    def _resolved_strategy_order(cfg: EquivalenceConfig) -> tuple[str, ...]:
        """Return the enabled proof order for this clock model."""

        order = cfg.strategy_order or (("pdr", "smt") if cfg.multiclock else ("sat", "pdr", "smt"))
        enabled = {
            "sat": cfg.use_sat and not cfg.multiclock,
            "smt": True,
            "pdr": cfg.use_pdr,
        }
        return tuple(name for name in order if enabled[name])

    @staticmethod
    def _strategy_lines(cfg: EquivalenceConfig) -> list[str]:
        """Render the ordered portfolio; EQY advances only unresolved partitions."""

        order = Eqy._resolved_strategy_order(cfg)
        strategies: list[str] = []
        multiclock = ["option multiclock on"] if cfg.multiclock else []
        for index, name in enumerate(order):
            if name == "sat":
                strategies.extend(["[strategy sat]", "use sat", f"depth {cfg.sat_depth}", ""])
            elif name == "pdr":
                strategies.extend([
                    "[strategy pdr]",
                    "use sby",
                    f"engine {cfg.pdr_engine.strip()}",
                    f"timeout {cfg.timeout}",
                    f"xprop {cfg.xprop}",
                    *multiclock,
                    "",
                ])
            else:
                timeout = cfg.quick_timeout if "pdr" in order[index + 1:] else cfg.timeout
                strategies.extend([
                    "[strategy smt]",
                    "use sby",
                    f"engine {cfg.smt_engine.strip()}",
                    f"depth {cfg.smt_depth}",
                    f"timeout {timeout}",
                    f"xprop {cfg.xprop}",
                    *multiclock,
                    "",
                ])
        return strategies

    @staticmethod
    def _formal_view_lines(cfg: EquivalenceConfig) -> list[str]:
        """Rename the implementation and read the optional symmetric formal view."""

        if cfg.formal_view is None:
            return []
        view = Eqy._require_files((cfg.formal_view,), label="formal protocol view")[0]
        return [
            f"rename {cfg.top} {cfg.top}__eqy_impl",
            f"read_verilog -formal -sv {view}",
        ]

    @staticmethod
    def _reset_normalization_lines(cfg: EquivalenceConfig) -> list[str]:
        """Initialize both designs through their declared reset contract."""

        if not cfg.reset_normalize:
            return []
        if cfg.reset_cycles <= 0:
            raise ValueError("EQY reset cycles must be > 0")
        if not cfg.reset_domains:
            raise ValueError("EQY reset normalization requires at least one clock domain")
        commands = ["# FlexSoC EQY reset normalization begin", "uniquify"]
        for clock, reset, polarity in cfg.reset_domains:
            for label, signal in (("clock", clock), ("reset", reset)):
                if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_$]*", signal):
                    raise ValueError(f"invalid EQY {label} port name: {signal!r}")
            if polarity not in {"low", "high"}:
                raise ValueError(f"invalid EQY reset polarity: {polarity!r}")
            option = "-resetn" if polarity == "low" else "-reset"
            commands.append(
                f"sim -clock {clock} {option} {reset} "
                f"-rstlen {cfg.reset_cycles} -n {cfg.reset_cycles} -w"
            )
        commands.append("# FlexSoC EQY reset normalization end")
        return commands

    @staticmethod
    def render_eqy(cfg: EquivalenceConfig) -> str:
        """Render RTL-vs-synthesis EQY with symmetric formal normalization."""

        if cfg.sat_depth <= 0:
            raise ValueError("EQY SAT depth must be > 0")
        if cfg.smt_depth <= 0:
            raise ValueError("EQY SMT depth must be > 0")
        if cfg.timeout <= 0:
            raise ValueError("EQY SBY timeout must be > 0")
        if cfg.quick_timeout <= 0:
            raise ValueError("EQY quick timeout must be > 0")
        if cfg.splitnets not in {"on", "off"}:
            raise ValueError("EQY splitnets must be 'on' or 'off'")
        if cfg.xprop not in {"on", "off"}:
            raise ValueError("EQY xprop must be 'on' or 'off'")
        valid_strategies = {"sat", "smt", "pdr"}
        if len(set(cfg.strategy_order)) != len(cfg.strategy_order):
            raise ValueError("EQY strategy order must not contain duplicates")
        invalid = set(cfg.strategy_order) - valid_strategies
        if invalid:
            raise ValueError(f"invalid EQY strategies: {', '.join(sorted(invalid))}")
        if cfg.use_pdr and not cfg.pdr_engine.strip():
            raise ValueError("EQY PDR engine must not be empty")
        if not cfg.smt_engine.strip():
            raise ValueError("EQY SMT engine must not be empty")
        if not Eqy._resolved_strategy_order(cfg):
            raise ValueError("EQY strategy order enables no strategies")
        if cfg.reset_normalize and cfg.reset_cycles <= 0:
            raise ValueError("EQY reset cycles must be > 0")

        filelists = Eqy._require_files(cfg.filelists, label="RTL filelist(s)")
        netlist = Eqy._require_files((cfg.netlist,), label="synthesized netlist")[0]
        liberty = Eqy._require_files((cfg.liberty,), label="Liberty file")[0]
        cell_models = Eqy._require_files(cfg.cell_models, label="functional cell model(s)") if cfg.cell_models else ()
        port_decls = Eqy._netlist_port_decls(netlist, cfg.top)
        contract_ports = Eqy._tlul_contract_ports(port_decls) if cfg.formal_view else port_decls

        def block(lines: Sequence[str]) -> str:
            return "\n".join(lines)

        return templates.render(
            "syn/eqy/equivalence.eqy.j2",
            splitnets=cfg.splitnets,
            gold_read=Eqy._read_slang_synthesis(cfg.top, filelists),
            gold_view=block((*Eqy._formal_view_lines(cfg), "")),
            gate_reads=block(Eqy._gate_model_reads(cfg, liberty=liberty, netlist=netlist, cell_models=cell_models)),
            gate_view=block((*Eqy._formal_view_lines(cfg), "")),
            top=cfg.top,
            multiclock=cfg.multiclock,
            reset_normalization=block((*Eqy._reset_normalization_lines(cfg), "")),
            match_sections=block(Eqy._eqy_match_sections(cfg.top, contract_ports)),
            collect_sections=block(Eqy._eqy_collect_sections(cfg.top, contract_ports, enabled=cfg.join_outputs)),
            strategies=block(Eqy._strategy_lines(cfg)),
        ).rstrip("\n")

    @staticmethod
    def _formal_pdk_processor(cfg: EquivalenceConfig, *, local: bool = True) -> str | None:
        """Return the configured functional-model preprocessor command."""

        if cfg.formal_pdk_proc is not None:
            candidate = cfg.formal_pdk_proc.expanduser().resolve()
            if not candidate.is_file():
                raise ValueError(f"formal PDK processor not found: {candidate}")
            return str(candidate)
        override = os.environ.get("EQY_FORMAL_PDK_PROC", "").strip()
        if override:
            if not local:
                return override
            candidate = shutil.which(override) or (override if Path(override).is_file() else None)
            if candidate is None:
                raise ValueError(f"EQY_FORMAL_PDK_PROC not found: {override}")
            return str(candidate)
        return shutil.which("eqy.formal_pdk_proc") if local else "eqy.formal_pdk_proc"

    @staticmethod
    def _prepare_formal_cell_model(cfg: EquivalenceConfig, *, runner=None, on: str = "local") -> EquivalenceConfig:
        """Prepare SKY130 functional Verilog without making LibreLane a dependency."""

        pdk = Eqy._active_pdk(cfg)
        if pdk != "sky130" or not cfg.cell_models:
            return cfg

        models = Eqy._require_files(cfg.cell_models, label="functional cell model(s)")
        output = cfg.output.expanduser().resolve().parent / "formal_pdk.v"
        output.parent.mkdir(parents=True, exist_ok=True)
        from flexsoc.backend.core import CommandRequest, ToolRunner

        runner = runner or ToolRunner(project_root=cfg.output.parent)
        target = runner.targets.get(on)
        processor = Eqy._formal_pdk_processor(cfg, local=target is None or target.kind == "local")
        if processor is None:
            print(
                "WARNING: SKY130 formal adapter missing; EQY will use Liberty cell semantics. "
                "Run `fx pdk fetch sky130 --force` to install the pinned EQY adapter.",
                file=sys.stderr,
            )
            return cfg
        command = (processor, "--output", str(output), *(str(path) for path in models))
        log = output.with_suffix(".log")
        processor_path = Path(processor)
        inputs = (*models, processor_path) if processor_path.is_file() else models
        result = runner.run(
            CommandRequest(
                command,
                cfg.output.parent,
                {},
                log,
                inputs=tuple(inputs),
                outputs=(output,),
            ),
            on=on,
        )
        if result.returncode != 0:
            detail = log.read_text(encoding="utf-8", errors="replace").strip() if log.is_file() else ""
            raise ValueError(
                f"formal PDK preprocessing failed ({result.returncode}): {' '.join(command)}"
                + (f"\n{detail}" if detail else "")
            )
        if not output.is_file():
            raise ValueError(f"formal PDK preprocessor did not create: {output}")
        log.unlink(missing_ok=True)
        return replace(cfg, formal_cell_model=output)

    @staticmethod
    def _env_bool(name: str, default: bool) -> bool:
        value = os.environ.get(name)
        if value is None or not value.strip():
            return default
        normalized = value.strip().lower()
        if normalized in {"1", "true", "yes", "on"}:
            return True
        if normalized in {"0", "false", "no", "off"}:
            return False
        raise ValueError(f"{name} must be one of 1/0, true/false, yes/no, on/off")

    @staticmethod
    def write_text(path: Path, content: str) -> Path:
        """Write UTF-8 text and return the written path."""

        path = path.expanduser().resolve()
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content, encoding="utf-8")
        return path

    @staticmethod
    def _ensure_formal_view_artifact(config: Path, view: Path) -> Path:
        """Keep the EQY profile artifact complete without masking a required wrapper."""

        if view.is_file():
            return view
        text = config.read_text(encoding="utf-8", errors="replace")
        if view.name in text:
            raise FileNotFoundError(f"missing EQY formal view: {view}")
        return Eqy.write_text(view, "// No protocol-specific EQY formal view required.\n")

    @staticmethod
    def generate_equivalence_config(cfg: EquivalenceConfig, *, runner=None, on: str = "local") -> Path:
        """Generate optional PDK compatibility models and one EQY config."""

        pdk = Eqy._active_pdk(cfg)
        body = (
            Eqy.render_sky130_clock_gate_model()
            if pdk == "sky130"
            else "// No PDK-specific EQY compatibility model required.\n"
        )
        Eqy.write_text(cfg.sky130_clock_gate_model, body)
        prepared = Eqy._prepare_formal_protocol_view(Eqy._prepare_formal_cell_model(cfg, runner=runner, on=on))
        return Eqy.write_text(cfg.output, Eqy.render_eqy(prepared))

    @staticmethod
    def _eqy_binding_names(
        filelists: Sequence[Path],
        cell_models: Sequence[Path],
    ) -> tuple[tuple[Path, str], ...]:
        """Return stable local names for portable EQY dependencies."""

        bindings: list[tuple[Path, str]] = []
        used: set[str] = set()
        for path in filelists:
            name = path.name
            if not name or name in used:
                raise ValueError(f"EQY filelist basename must be unique: {path}")
            used.add(name)
            bindings.append((path, name))
        for index, path in enumerate(cell_models):
            suffix = path.suffix or ".v"
            name = f"cell_model_{index}{suffix}"
            bindings.append((path, name))
        return tuple(bindings)

    @staticmethod
    def _replace_symlink(source: Path, destination: Path) -> Path:
        """Create one deterministic absolute symlink, replacing an old binding."""

        source = source.expanduser().resolve()
        if not source.is_file():
            raise ValueError(f"missing EQY binding source: {source}")
        destination = destination.expanduser().absolute()
        destination.parent.mkdir(parents=True, exist_ok=True)
        if destination.exists() or destination.is_symlink():
            destination.unlink()
        destination.symlink_to(source)
        return destination

    @staticmethod
    def _bind_sky130_liberty_fallback(config: Path, clock_gate_model: Path) -> Path:
        """Replace an unavailable portable formal model with the standard fallback."""

        formal_read = "read_verilog -formal -sv formal_pdk.v"
        fallback = "\n".join((
            "# FlexSoC SKY130 Liberty fallback begin",
            "read_liberty -ignore_miss_func library.lib",
            f"read_verilog -formal -sv {clock_gate_model.name}",
            "# FlexSoC SKY130 Liberty fallback end",
        ))
        return Eqy.write_text(config, config.read_text(encoding="utf-8").replace(formal_read, fallback))

    @staticmethod
    def bind_equivalence_profile(
        *,
        top: str,
        output_dir: Path,
        filelists: Sequence[Path],
        netlist: Path,
        liberty: Path,
        cell_models: Sequence[Path],
        formal_pdk_proc: Path | None,
        clock_gate_model: Path,
        config: Path | None = None,
        runner=None,
        on: str = "local",
        pdk: str | None = None,
    ) -> tuple[Path, ...]:
        """Bind a portable, design-owned EQY profile to the active run and PDK."""

        output_dir = output_dir.expanduser().absolute()
        output_dir.mkdir(parents=True, exist_ok=True)
        created = [
            *(Eqy._replace_symlink(path, output_dir / name)
              for path, name in Eqy._eqy_binding_names(filelists, cell_models)),
            Eqy._replace_symlink(netlist, output_dir / "netlist.v"),
            Eqy._replace_symlink(liberty, output_dir / "library.lib"),
        ]
        clock_gate = output_dir / clock_gate_model.name
        resolved_pdk = (pdk or os.environ.get("FLEXSOC_PDK", "")).strip().lower()
        body = (
            Eqy.render_sky130_clock_gate_model()
            if resolved_pdk == "sky130"
            else "// No PDK-specific EQY compatibility model required.\n"
        )
        created.append(Eqy.write_text(clock_gate, body))

        config_text = ""
        if config is not None and config.is_file():
            config_text = config.read_text(encoding="utf-8", errors="replace")
        if "formal_pdk.v" in config_text:
            cfg = EquivalenceConfig(
                top=top,
                filelists=tuple(filelists),
                netlist=netlist,
                liberty=liberty,
                cell_models=tuple(cell_models),
                formal_pdk_proc=formal_pdk_proc,
                pdk=resolved_pdk,
                sky130_clock_gate_model=clock_gate,
                sat_depth=1,
                output=output_dir / "_bind.eqy",
            )
            prepared = Eqy._prepare_formal_cell_model(cfg, runner=runner, on=on)
            created.append(
                prepared.formal_cell_model
                if prepared.formal_cell_model is not None
                else Eqy._bind_sky130_liberty_fallback(config, clock_gate)
            )
        return tuple(created)

    @staticmethod
    def export_equivalence_profile(
        *,
        config: Path,
        view: Path,
        output_dir: Path,
        filelists: Sequence[Path],
        netlist: Path,
        liberty: Path,
        cell_models: Sequence[Path],
        clock_gate_model: Path,
    ) -> tuple[Path, Path]:
        """Save only the portable EQY config and formal view for one PDK."""

        config, view = Eqy._require_files((config, view), label="EQY profile file(s)")
        text = config.read_text(encoding="utf-8")
        replacements = [
            *(Eqy._eqy_binding_names(filelists, cell_models)),
            (netlist, "netlist.v"),
            (liberty, "library.lib"),
            (clock_gate_model, clock_gate_model.name),
            (view, view.name),
        ]
        for source, local_name in replacements:
            expanded = source.expanduser()
            for spelling in {str(expanded.absolute()), str(expanded.resolve())}:
                text = text.replace(spelling, local_name)
        text = re.sub(r"(?<!\S)\S*formal_pdk\.v", "formal_pdk.v", text)

        output_dir = output_dir.expanduser().absolute()
        output_dir.mkdir(parents=True, exist_ok=True)
        saved_config = Eqy.write_text(output_dir / config.name, text)
        saved_view = Eqy.write_text(output_dir / view.name, view.read_text(encoding="utf-8"))
        return saved_config, saved_view

    @staticmethod
    def describe_partition(partition: str) -> str | None:
        """Decode flattened TL-UL response bits into protocol field names."""

        match = re.fullmatch(r"(.+(?:_tl_o|\.tl_o))\.(\d+)", partition)
        if not match:
            return None
        base, raw_bit = match.groups()
        bit = int(raw_bit)
        fields = (
            (0, 0, "a_ready"),
            (1, 1, "d_error"),
            (2, 8, "d_user.data_intg"),
            (9, 15, "d_user.rsp_intg"),
            (16, 47, "d_data"),
            (48, 48, "d_sink"),
            (49, 56, "d_source"),
            (57, 58, "d_size"),
            (59, 61, "d_param"),
            (62, 64, "d_opcode"),
            (65, 65, "d_valid"),
        )
        for lo, hi, name in fields:
            if lo <= bit <= hi:
                suffix = f"[{bit - lo}]" if hi > lo else ""
                return f"{base.rsplit('.', 1)[-1]}.{name}{suffix}"
        return None

    @staticmethod
    def _status(path: Path) -> str:
        if not path.is_file():
            return "MISSING"
        words = path.read_text(encoding="utf-8", errors="replace").strip().upper().split()
        return words[0] if words else "UNKNOWN"

    @staticmethod
    def _best_status(values: Iterable[str]) -> str:
        return max(values, key=lambda value: _STATUS_ORDER.get(value, 0), default="MISSING")

    @staticmethod
    def _nested_run_dir(strategy_dir: Path, partition: str) -> Path:
        direct = strategy_dir / partition
        if direct.is_dir():
            return direct
        nested = [path for path in strategy_dir.iterdir() if path.is_dir()] if strategy_dir.is_dir() else []
        return nested[0] if len(nested) == 1 else strategy_dir

    @staticmethod
    def discover_result_dir(
        project_root: Path,
        workspace: Path,
        *,
        top: str,
        run_top: str,
        run_id: str,
        pdk: str | None = None,
    ) -> Path:
        """Find the EQY result directory for the selected run/technology."""

        shared = PDKRunLayout.build_run_root(workspace, run_top=run_top, run_id=run_id)
        if not pdk:
            raise ValueError("PDK is required to resolve EQY results")
        layout = PDKRunLayout.from_run(shared, pdk=pdk, top=top)
        expected = layout.equivalence_dir / f"{top}_rtl_vs_syn"
        if expected.is_dir():
            return expected

        base = expected.parent
        candidates = sorted(path for path in base.glob("*_rtl_vs_syn") if path.is_dir()) if base.is_dir() else []
        if len(candidates) == 1:
            return candidates[0]
        if len(candidates) > 1:
            raise FileNotFoundError(
                f"ambiguous EQY result beside {expected}: " + ", ".join(str(path) for path in candidates)
            )

        technology = f" PDK={pdk}"
        raise FileNotFoundError(
            f"EQY result directory not found for TOP={top} RUN_TOP={run_top} RUN_ID={run_id}{technology}: {expected}"
        )

    @staticmethod
    def scan(result_dir: Path) -> tuple[Counterexample, ...]:
        """Scan all EQY partitions and strategy result directories."""

        strategy_root = result_dir / "strategies"
        if not strategy_root.is_dir():
            return ()

        output: list[Counterexample] = []
        for partition_dir in sorted(path for path in strategy_root.iterdir() if path.is_dir()):
            strategies: list[StrategyResult] = []
            for strategy_dir in sorted(path for path in partition_dir.iterdir() if path.is_dir()):
                nested = Eqy._nested_run_dir(strategy_dir, partition_dir.name)
                statuses = [Eqy._status(strategy_dir / "status"), Eqy._status(nested / "status")]
                status = Eqy._best_status(value for value in statuses if value != "MISSING")
                traces: list[Path] = []
                logs: list[Path] = []
                engine_dirs = sorted(path for path in nested.glob("engine_*") if path.is_dir())
                search_dirs = [nested, *engine_dirs]
                for directory in search_dirs:
                    for name in _TRACE_NAMES:
                        path = directory / name
                        if path.is_file() and path not in traces:
                            traces.append(path)
                    for name in _LOG_NAMES:
                        path = directory / name
                        if path.is_file() and path not in logs:
                            logs.append(path)
                strategies.append(
                    StrategyResult(
                        name=strategy_dir.name,
                        status=status,
                        directory=nested,
                        traces=tuple(traces),
                        logs=tuple(logs),
                    )
                )
            overall = Eqy._best_status(item.status for item in strategies)
            output.append(Counterexample(partition_dir.name, overall, partition_dir, tuple(strategies)))
        return tuple(output)
