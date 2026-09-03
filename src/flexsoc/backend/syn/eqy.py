"""RTL-to-synthesis equivalence setup, execution and diagnostics."""

from __future__ import annotations

import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time
from dataclasses import asdict, dataclass, replace
from pathlib import Path
from typing import Callable, Iterable, Mapping, Sequence

from flexsoc.backend.core import clock_config, pdk_run_layout, run_root

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


def optional_path(value: str | None) -> Path | None:
    """Return a path for non-empty values and ``None`` for missing CLI inputs."""

    return Path(value) if value else None


def split_liberties(values: Sequence[str]) -> list[Path]:
    """Expand repeated or comma-separated liberty arguments into paths."""

    return [Path(token.strip()) for item in values for token in str(item).split(",") if token.strip()]


def _resolved(paths: Sequence[Path]) -> tuple[Path, ...]:
    return tuple(path.expanduser().resolve() for path in paths)


def _require_files(paths: Sequence[Path], *, label: str) -> tuple[Path, ...]:
    resolved = _resolved(paths)
    missing = [path for path in resolved if not path.is_file()]
    if missing:
        rendered = "\n  ".join(str(path) for path in missing)
        raise ValueError(f"missing {label}:\n  {rendered}")
    return resolved


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


def _netlist_ports(netlist: Path, top: str) -> tuple[str, ...]:
    """Return top-level port names from a synthesized Verilog netlist."""

    return tuple(port.name for port in _netlist_port_decls(netlist, top))


def _tlul_response_ports(ports: Sequence[NetlistPort]) -> tuple[NetlistPort, ...]:
    """Discover packed TL-UL device responses by public name and ABI width."""

    return tuple(
        port for port in ports
        if port.direction == "output"
        and port.width == 66
        and (port.name == "tl_o" or port.name.endswith("_tl_o"))
    )


def _tlul_contract_ports(ports: Sequence[NetlistPort]) -> tuple[NetlistPort, ...]:
    """Return the formal contract ports used to partition TL-UL responses."""

    responses = {port.name for port in _tlul_response_ports(ports)}
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


def render_formal_protocol_view(top: str, ports: Sequence[NetlistPort]) -> str:
    """Render a symmetric formal view for protocol-defined don't-care outputs."""

    responses = {port.name for port in _tlul_response_ports(ports)}
    if not responses:
        return ""
    impl = f"{top}__eqy_impl"
    contract_ports = _tlul_contract_ports(ports)
    witnesses = tuple(port for port in contract_ports if "__flexsoc_eqy_" in port.name)
    # Keep the raw packed response internal: EQY partitions every public output.
    # Gold and gate expose only the same bounded protocol witnesses.
    view_ports = tuple(port for port in ports if port.name not in responses) + witnesses
    original_names = {port.name for port in ports}
    if any(port.name in original_names for port in witnesses):
        raise ValueError("formal TL-UL witness name collides with a design port")
    lines = [
        "// Auto-generated formal protocol view; not functional RTL.",
        f"module {top} (",
        *[f"  {port.declaration()}{',' if index + 1 < len(view_ports) else ''}" for index, port in enumerate(view_ports)],
        ");",
        "",
    ]
    for port in ports:
        if port.name in responses:
            lines.append(f"  wire [65:0] {port.name}__raw;")
    lines.extend(("", f"  {impl} u_impl ("))
    for index, port in enumerate(ports):
        signal = f"{port.name}__raw" if port.name in responses else port.name
        lines.append(f"    .{port.name} ({signal}){',' if index + 1 < len(ports) else ''}")
    lines.extend(("  );", ""))
    for name in sorted(responses):
        raw = f"{name}__raw"
        prefix = f"{name}__flexsoc_eqy"
        lines.extend((
            f"  assign {prefix}_handshake = {{{raw}[65], {raw}[0]}};",
            f"  assign {prefix}_d_ctrl = {raw}[65] ? {raw}[64:48] : '0;",
            f"  assign {prefix}_d_data = ({raw}[65] && ({raw}[64:62] == 3'h1) && !{raw}[1]) ? {raw}[47:16] : '0;",
            f"  assign {prefix}_d_meta = {raw}[65] ? {raw}[15:1] : '0;",
            "",
        ))
    lines.append("endmodule")
    return "\n".join(lines) + "\n"


def _prepare_formal_protocol_view(cfg: EquivalenceConfig) -> EquivalenceConfig:
    """Write a formal-only wrapper when the top exposes supported protocols."""

    body = render_formal_protocol_view(cfg.top, _netlist_port_decls(cfg.netlist, cfg.top))
    if not body:
        return cfg
    path = cfg.output.expanduser().resolve().parent / f"{cfg.top}_eqy_view.sv"
    return replace(cfg, formal_view=write_text(path, body))


def _eqy_match_sections(top: str, ports: Sequence[NetlistPort]) -> list[str]:
    """Match only the canonical external contract and formal witnesses."""

    return [
        f"[match {top}]",
        "nodefault",
        *(f"gold-match {port.name}" for port in ports),
        "",
    ]


def _eqy_collect_sections(top: str, ports: Sequence[NetlistPort], *, enabled: bool) -> list[str]:
    """Keep every top-level output bus in one equivalence partition."""

    buses = [
        port.name for port in ports
        if enabled and port.direction == "output" and (port.width or 0) > 1
    ]
    return [f"[collect {top}]", *(f"join {name}" for name in buses), ""] if buses else []


def _read_slang_synthesis(top: str, filelists: Sequence[Path]) -> str:
    """Render the canonical Slang/Yosys synthesis frontend for EQY gold RTL."""

    options = ["-D SYNTHESIS", "--ignore-assertions"]
    options.extend(f"-f {path}" for path in filelists)
    options.append(f"--top {top}")
    return "read_slang " + " ".join(options)


def render_sky130_clock_gate_model() -> str:
    """Render formal-compatible SKY130 integrated clock-gate models."""

    def dlclkp(name: str) -> str:
        return f"""module {name} (output wire GCLK, input wire GATE, input wire CLK);
  reg gate_latched;
  always @ (CLK or GATE) begin
    if (!CLK)
      gate_latched <= GATE;
  end
  assign GCLK = CLK & gate_latched;
endmodule"""

    def sdlclkp(name: str) -> str:
        return f"""module {name} (output wire GCLK, input wire SCE, input wire GATE, input wire CLK);
  reg gate_latched;
  always @ (CLK or GATE or SCE) begin
    if (!CLK)
      gate_latched <= (GATE | SCE);
  end
  assign GCLK = CLK & gate_latched;
endmodule"""

    modules = [
        *(dlclkp(f"sky130_fd_sc_hd__dlclkp_{drive}") for drive in (1, 2, 4)),
        *(sdlclkp(f"sky130_fd_sc_hd__sdlclkp_{drive}") for drive in (1, 2, 4)),
    ]
    return "\n\n".join(modules) + "\n"


def _active_pdk(cfg: EquivalenceConfig) -> str:
    """Return the explicit PDK identity, with ambient env only as compatibility fallback."""

    return cfg.pdk.strip().lower() or os.environ.get("FLEXSOC_PDK", "").strip().lower()


def _gate_model_reads(
    cfg: EquivalenceConfig,
    *,
    liberty: Path,
    netlist: Path,
    cell_models: Sequence[Path],
) -> list[str]:
    """Read functional cell models when safe, otherwise use Liberty fallback."""

    pdk = _active_pdk(cfg)
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


def _resolved_strategy_order(cfg: EquivalenceConfig) -> tuple[str, ...]:
    """Return the enabled proof order for this clock model."""

    order = cfg.strategy_order or (("pdr", "smt") if cfg.multiclock else ("sat", "pdr", "smt"))
    enabled = {
        "sat": cfg.use_sat and not cfg.multiclock,
        "smt": True,
        "pdr": cfg.use_pdr,
    }
    return tuple(name for name in order if enabled[name])


def _strategy_lines(cfg: EquivalenceConfig) -> list[str]:
    """Render the ordered portfolio; EQY advances only unresolved partitions."""

    order = _resolved_strategy_order(cfg)
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


def _formal_view_lines(cfg: EquivalenceConfig) -> list[str]:
    """Rename the implementation and read the optional symmetric formal view."""

    if cfg.formal_view is None:
        return []
    view = _require_files((cfg.formal_view,), label="formal protocol view")[0]
    return [
        f"rename {cfg.top} {cfg.top}__eqy_impl",
        f"read_verilog -formal -sv {view}",
    ]


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
    if not _resolved_strategy_order(cfg):
        raise ValueError("EQY strategy order enables no strategies")
    if cfg.reset_normalize and cfg.reset_cycles <= 0:
        raise ValueError("EQY reset cycles must be > 0")

    filelists = _require_files(cfg.filelists, label="RTL filelist(s)")
    netlist = _require_files((cfg.netlist,), label="synthesized netlist")[0]
    liberty = _require_files((cfg.liberty,), label="Liberty file")[0]
    cell_models = _require_files(cfg.cell_models, label="functional cell model(s)") if cfg.cell_models else ()
    port_decls = _netlist_port_decls(netlist, cfg.top)
    contract_ports = _tlul_contract_ports(port_decls) if cfg.formal_view else port_decls

    return "\n".join(
        [
            "[options]",
            f"splitnets {cfg.splitnets}",
            "",
            "[gold]",
            _read_slang_synthesis(cfg.top, filelists),
            *_formal_view_lines(cfg),
            "",
            "[gate]",
            *_gate_model_reads(cfg, liberty=liberty, netlist=netlist, cell_models=cell_models),
            *_formal_view_lines(cfg),
            "",
            "[script]",
            f"hierarchy -check -top {cfg.top}",
            "proc",
            f"prep -top {cfg.top} -flatten",
            "memory -nomap",
            "memory_map -formal",
            *([] if cfg.multiclock else ["async2sync"]),
            *_reset_normalization_lines(cfg),
            "",
            *_eqy_match_sections(cfg.top, contract_ports),
            *_eqy_collect_sections(cfg.top, contract_ports, enabled=cfg.join_outputs),
            *_strategy_lines(cfg),
        ]
    )


def _formal_pdk_processor(cfg: EquivalenceConfig) -> str | None:
    """Return an optional external functional-model preprocessor."""

    if cfg.formal_pdk_proc is not None:
        candidate = cfg.formal_pdk_proc.expanduser().resolve()
        if not candidate.is_file():
            raise ValueError(f"formal PDK processor not found: {candidate}")
        return str(candidate)
    override = os.environ.get("EQY_FORMAL_PDK_PROC", "").strip()
    if override:
        candidate = shutil.which(override) or (override if Path(override).is_file() else None)
        if candidate is None:
            raise ValueError(f"EQY_FORMAL_PDK_PROC not found: {override}")
        return str(candidate)
    return shutil.which("eqy.formal_pdk_proc")


def _prepare_formal_cell_model(cfg: EquivalenceConfig, *, runner=None, on: str = "local") -> EquivalenceConfig:
    """Prepare SKY130 functional Verilog without making LibreLane a dependency."""

    pdk = _active_pdk(cfg)
    if pdk != "sky130" or not cfg.cell_models:
        return cfg

    models = _require_files(cfg.cell_models, label="functional cell model(s)")
    output = cfg.output.expanduser().resolve().parent / "formal_pdk.v"
    output.parent.mkdir(parents=True, exist_ok=True)
    processor = _formal_pdk_processor(cfg)
    if processor is None:
        print(
            "WARNING: SKY130 formal adapter missing; EQY will use Liberty cell semantics. "
            "Run `fx pdk fetch sky130 --force` to install the pinned EQY adapter.",
            file=sys.stderr,
        )
        return cfg
    from flexsoc.backend.core import CommandRequest, ToolRunner

    command = (processor, "--output", str(output), *(str(path) for path in models))
    log = output.with_suffix(".log")
    runner = runner or ToolRunner(project_root=cfg.output.parent)
    result = runner.run(
        CommandRequest(
            command,
            cfg.output.parent,
            {},
            log,
            inputs=tuple(models),
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


def write_text(path: Path, content: str) -> Path:
    """Write UTF-8 text and return the written path."""

    path = path.expanduser().resolve()
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")
    return path


def generate_equivalence_config(cfg: EquivalenceConfig, *, runner=None, on: str = "local") -> Path:
    """Generate optional PDK compatibility models and one EQY config."""

    pdk = _active_pdk(cfg)
    body = (
        render_sky130_clock_gate_model()
        if pdk == "sky130"
        else "// No PDK-specific EQY compatibility model required.\n"
    )
    write_text(cfg.sky130_clock_gate_model, body)
    prepared = _prepare_formal_protocol_view(_prepare_formal_cell_model(cfg, runner=runner, on=on))
    return write_text(cfg.output, render_eqy(prepared))


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


def _bind_sky130_liberty_fallback(config: Path, clock_gate_model: Path) -> Path:
    """Replace an unavailable portable formal model with the standard fallback."""

    formal_read = "read_verilog -formal -sv formal_pdk.v"
    fallback = "\n".join((
        "# FlexSoC SKY130 Liberty fallback begin",
        "read_liberty -ignore_miss_func library.lib",
        f"read_verilog -formal -sv {clock_gate_model.name}",
        "# FlexSoC SKY130 Liberty fallback end",
    ))
    return write_text(config, config.read_text(encoding="utf-8").replace(formal_read, fallback))


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
        *(_replace_symlink(path, output_dir / name)
          for path, name in _eqy_binding_names(filelists, cell_models)),
        _replace_symlink(netlist, output_dir / "netlist.v"),
        _replace_symlink(liberty, output_dir / "library.lib"),
    ]
    clock_gate = output_dir / clock_gate_model.name
    resolved_pdk = (pdk or os.environ.get("FLEXSOC_PDK", "")).strip().lower()
    body = (
        render_sky130_clock_gate_model()
        if resolved_pdk == "sky130"
        else "// No PDK-specific EQY compatibility model required.\n"
    )
    created.append(write_text(clock_gate, body))

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
        prepared = _prepare_formal_cell_model(cfg, runner=runner, on=on)
        created.append(
            prepared.formal_cell_model
            if prepared.formal_cell_model is not None
            else _bind_sky130_liberty_fallback(config, clock_gate)
        )
    return tuple(created)


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

    config, view = _require_files((config, view), label="EQY profile file(s)")
    text = config.read_text(encoding="utf-8")
    replacements = [
        *(_eqy_binding_names(filelists, cell_models)),
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
    saved_config = write_text(output_dir / config.name, text)
    saved_view = write_text(output_dir / view.name, view.read_text(encoding="utf-8"))
    return saved_config, saved_view


_STATUS_ORDER = {"FAIL": 5, "ERROR": 4, "TIMEOUT": 3, "UNKNOWN": 2, "PASS": 1, "MISSING": 0}
_TRACE_NAMES = ("trace.vcd", "trace_induct.vcd", "trace.yw", "trace.smtc", "trace_tb.v")
_LOG_NAMES = ("logfile.txt", "logfile_basecase.txt", "logfile_induction.txt")
_INTERESTING_WORDS = (
    "gold", "gate", "clk", "clock", "rst", "reset", "valid", "ready", "ack",
    "outstanding", "equiv", "trigger", "assert", "compare",
)


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


def _status(path: Path) -> str:
    if not path.is_file():
        return "MISSING"
    words = path.read_text(encoding="utf-8", errors="replace").strip().upper().split()
    return words[0] if words else "UNKNOWN"


def _best_status(values: Iterable[str]) -> str:
    return max(values, key=lambda value: _STATUS_ORDER.get(value, 0), default="MISSING")


def _nested_run_dir(strategy_dir: Path, partition: str) -> Path:
    direct = strategy_dir / partition
    if direct.is_dir():
        return direct
    nested = [path for path in strategy_dir.iterdir() if path.is_dir()] if strategy_dir.is_dir() else []
    return nested[0] if len(nested) == 1 else strategy_dir


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

    shared = run_root(workspace, run_top=run_top, run_id=run_id)
    if not pdk:
        raise ValueError("PDK is required to resolve EQY results")
    layout = pdk_run_layout(shared, pdk=pdk, top=top)
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


def scan(result_dir: Path) -> tuple[Counterexample, ...]:
    """Scan all EQY partitions and strategy result directories."""

    strategy_root = result_dir / "strategies"
    if not strategy_root.is_dir():
        return ()

    output: list[Counterexample] = []
    for partition_dir in sorted(path for path in strategy_root.iterdir() if path.is_dir()):
        strategies: list[StrategyResult] = []
        for strategy_dir in sorted(path for path in partition_dir.iterdir() if path.is_dir()):
            nested = _nested_run_dir(strategy_dir, partition_dir.name)
            statuses = [_status(strategy_dir / "status"), _status(nested / "status")]
            status = _best_status(value for value in statuses if value != "MISSING")
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
        overall = _best_status(item.status for item in strategies)
        output.append(Counterexample(partition_dir.name, overall, partition_dir, tuple(strategies)))
    return tuple(output)


def select(items: Iterable[Counterexample], partition: str | None = None) -> Counterexample:
    """Select an explicit partition or the unique non-PASS partition."""

    rows = tuple(items)
    if partition:
        exact = [item for item in rows if item.partition == partition]
        if exact:
            return exact[0]
        partial = [item for item in rows if partition in item.partition]
        if len(partial) == 1:
            return partial[0]
        if partial:
            names = ", ".join(item.partition for item in partial[:10])
            raise ValueError(f"partition {partition!r} is ambiguous: {names}")
        raise ValueError(f"partition not found: {partition}")

    failing = [item for item in rows if item.status != "PASS"]
    if len(failing) == 1:
        return failing[0]
    if not failing:
        raise ValueError("no EQY counterexamples found: all discovered partitions PASS")
    names = ", ".join(item.partition for item in failing[:10])
    suffix = " ..." if len(failing) > 10 else ""
    raise ValueError(f"multiple non-PASS partitions; choose one explicitly: {names}{suffix}")


def interesting_log_lines(strategy: StrategyResult, *, limit: int = 40) -> list[str]:
    """Extract compact diagnostic lines from SBY/EQY logs."""

    pattern = re.compile(r"fail|counter|assert|basecase|induction|equiv|unreached|timeout|error|trace", re.I)
    lines: list[str] = []
    for path in strategy.logs:
        for raw in path.read_text(encoding="utf-8", errors="replace").splitlines():
            if pattern.search(raw):
                line = raw.strip()
                if line and line not in lines:
                    lines.append(line)
                if len(lines) >= limit:
                    return lines
    return lines


def parse_vcd_signals(vcd: Path) -> tuple[str, ...]:
    """Return fully-qualified signal names found in a VCD header."""

    scope: list[str] = []
    signals: list[str] = []
    try:
        with vcd.open("r", encoding="utf-8", errors="replace") as handle:
            for raw in handle:
                line = raw.strip()
                if line.startswith("$scope "):
                    parts = line.split()
                    if len(parts) >= 3:
                        scope.append(parts[2])
                elif line.startswith("$upscope"):
                    if scope:
                        scope.pop()
                elif line.startswith("$var "):
                    parts = line.split()
                    if len(parts) >= 5:
                        reference = parts[4]
                        if len(parts) >= 6 and parts[5].startswith("["):
                            reference += parts[5]
                        signals.append(".".join((*scope, reference)))
                elif line.startswith("$enddefinitions"):
                    break
    except OSError:
        return ()
    return tuple(signals)


def ranked_signals(vcd: Path, partition: str, *, limit: int = 48) -> tuple[str, ...]:
    """Rank VCD signals for a useful counterexample first view."""

    signals = parse_vcd_signals(vcd)
    tokens = [token.lower() for token in re.split(r"[^A-Za-z0-9_]+", partition) if len(token) >= 2]

    def score(name: str) -> tuple[int, str]:
        lower = name.lower()
        value = 0
        for token in tokens:
            if token in lower:
                value += 8
        for word in _INTERESTING_WORDS:
            if word in lower:
                value += 4
        if "gold" in lower or "gate" in lower:
            value += 4
        return (-value, name)

    ranked = sorted(signals, key=score)
    selected = [name for name in ranked if score(name)[0] < 0][:limit]
    if not selected:
        selected = ranked[: min(limit, len(ranked))]
    return tuple(selected)


def choose_trace(strategy: StrategyResult, kind: str = "auto") -> Path:
    """Choose the VCD trace to open."""

    vcdb = [path for path in strategy.traces if path.suffix.lower() == ".vcd"]
    if not vcdb:
        raise FileNotFoundError(f"no VCD trace found for strategy {strategy.name}")
    normalized = kind.lower().replace("-", "_")
    if normalized in {"induction", "induct"}:
        for path in vcdb:
            if "induct" in path.name:
                return path
        raise FileNotFoundError("induction VCD trace not found")
    if normalized in {"base", "basecase", "auto"}:
        for path in vcdb:
            if "induct" not in path.name:
                return path
        return vcdb[0]
    raise ValueError("trace kind must be auto, basecase, or induction")


def write_gtkwave_session(vcd: Path, partition: str, *, output: Path | None = None) -> Path:
    """Write a small GTKWave save file focused on likely counterexample signals."""

    output = output or vcd.with_name(f"{partition.replace('/', '_')}.gtkw")
    signals = ranked_signals(vcd, partition)
    lines = [
        "[*] FlexSoC EQY counterexample session",
        f'[dumpfile] "{vcd}"',
        "[timestart] 0",
    ]
    for signal in signals:
        lines.extend(("@28", signal))
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return output


def open_wave(vcd: Path, partition: str, *, viewer: str = "gtkwave", background: bool = True) -> tuple[Path | None, tuple[str, ...]]:
    """Open a counterexample waveform and return session/command metadata."""

    viewer = viewer.strip().lower()
    if viewer == "gtkwave":
        executable = shutil.which("gtkwave")
        if not executable:
            raise FileNotFoundError("gtkwave not found in PATH")
        session = write_gtkwave_session(vcd, partition)
        command = (executable, str(vcd), str(session))
    elif viewer == "surfer":
        executable = shutil.which("surfer")
        if not executable:
            raise FileNotFoundError("surfer not found in PATH")
        session = None
        command = (executable, str(vcd))
    else:
        raise ValueError("WAVE_VIEWER must be gtkwave or surfer")

    kwargs: dict[str, object] = {}
    if background:
        kwargs.update(stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True)
    subprocess.Popen(command, **kwargs)  # noqa: S603 - explicit local EDA viewer command.
    return session, command


def json_text(items: Iterable[Counterexample]) -> str:
    return json.dumps([item.to_dict() for item in items], indent=2)


def failure_metadata(strategy: StrategyResult) -> dict[str, object]:
    """Extract the failing phase, bounded step and assertion from SBY logs."""

    result: dict[str, object] = {
        "phase": None,
        "step": None,
        "assertion": None,
    }
    phase_patterns = (
        ("basecase", re.compile(r"basecase.*(?:FAIL|failed)|BMC failed", re.I)),
        ("induction", re.compile(r"induction.*(?:FAIL|failed)|Temporal induction failed", re.I)),
    )
    step_re = re.compile(r"failed assertion .*? step\s+(\d+)", re.I)
    assertion_re = re.compile(r"Assert failed in\s+([^:]+):([^\s]+)", re.I)

    lines: list[str] = []
    for path in strategy.logs:
        lines.extend(path.read_text(encoding="utf-8", errors="replace").splitlines())

    for line in lines:
        if result["phase"] is None:
            for phase, pattern in phase_patterns:
                if pattern.search(line):
                    result["phase"] = phase
                    break
        if result["step"] is None:
            match = step_re.search(line)
            if match:
                result["step"] = int(match.group(1))
        if result["assertion"] is None:
            match = assertion_re.search(line)
            if match:
                result["assertion"] = f"{match.group(1)}:{match.group(2)}"

    return result


def _vcd_header(vcd: Path) -> tuple[dict[str, str], dict[str, str]]:
    """Return VCD identifier-to-name and name-to-identifier maps."""

    scope: list[str] = []
    by_id: dict[str, str] = {}
    by_name: dict[str, str] = {}
    with vcd.open("r", encoding="utf-8", errors="replace") as handle:
        for raw in handle:
            line = raw.strip()
            if line.startswith("$scope "):
                parts = line.split()
                if len(parts) >= 3:
                    scope.append(parts[2])
            elif line.startswith("$upscope"):
                if scope:
                    scope.pop()
            elif line.startswith("$var "):
                parts = line.split()
                if len(parts) >= 5:
                    identifier = parts[3]
                    reference = parts[4]
                    if len(parts) >= 6 and parts[5].startswith("["):
                        reference += parts[5]
                    full = ".".join((*scope, reference))
                    by_id[identifier] = full
                    by_name[full] = identifier
            elif line.startswith("$enddefinitions"):
                break
    return by_id, by_name


def _pair_candidates(names: Iterable[str], partition: str) -> list[tuple[str, str, str]]:
    """Return likely gold/gate VCD signal pairs, ordered by diagnostic value."""

    available = set(names)
    tokens = [token.lower() for token in re.split(r"[^A-Za-z0-9_]+", partition) if token]
    pairs: list[tuple[int, str, str, str]] = []

    def add(gold: str, gate: str, kind: str) -> None:
        if gate not in available:
            return
        lower = gold.lower()
        score = 0
        if all(token in lower for token in tokens[-2:]):
            score += 20
        if "__po_" in lower or "assert" in lower:
            score += 15
        if kind == "value":
            score += 8
        elif kind == "xmask":
            score += 6
        elif kind == "data":
            score += 4
        pairs.append((-score, gold, gate, kind))

    for name in sorted(available):
        lower = name.lower()
        if ".gold." in lower:
            index = lower.index(".gold.")
            gate = name[:index] + ".gate." + name[index + len(".gold."):]
            add(name, gate, "value")
        if "__gold_x" in lower:
            index = lower.index("__gold_x")
            gate = name[:index] + "__gate_x" + name[index + len("__gold_x"):]
            add(name, gate, "xmask")
        elif "__gold_d" in lower:
            index = lower.index("__gold_d")
            gate = name[:index] + "__gate_d" + name[index + len("__gold_d"):]
            add(name, gate, "data")
        elif "__gold" in lower:
            index = lower.index("__gold")
            gate = name[:index] + "__gate" + name[index + len("__gold"):]
            add(name, gate, "value")

    seen: set[tuple[str, str]] = set()
    output: list[tuple[str, str, str]] = []
    for _, gold, gate, kind in sorted(pairs):
        key = (gold, gate)
        if key not in seen:
            seen.add(key)
            output.append((gold, gate, kind))
    return output


def _normalize_vcd_value(raw: str) -> str:
    value = raw.strip().lower()
    if not value:
        return value
    if value[0] in "bBrR":
        return value[1:].split()[0].lower()
    return value[0]


def _xprop_quartets(names: Iterable[str], partition: str) -> list[tuple[str, str, str, str]]:
    """Return ``gold_d/gold_x/gate_d/gate_x`` groups ordered by relevance."""

    available = set(names)
    tokens = [token.lower() for token in re.split(r"[^A-Za-z0-9_]+", partition) if token]
    ranked: list[tuple[int, tuple[str, str, str, str]]] = []
    for gold_d in sorted(available):
        lower = gold_d.lower()
        marker = "__gold_d"
        if marker not in lower:
            continue
        index = lower.index(marker)
        prefix = gold_d[:index]
        suffix = gold_d[index + len(marker):]
        gold_x = prefix + "__gold_x" + suffix
        gate_d = prefix + "__gate_d" + suffix
        gate_x = prefix + "__gate_x" + suffix
        if not all(name in available for name in (gold_x, gate_d, gate_x)):
            continue
        score = 0
        if all(token in lower for token in tokens[-2:]):
            score += 20
        if "__po_" in lower or "assert" in lower:
            score += 15
        ranked.append((-score, (gold_d, gold_x, gate_d, gate_x)))
    return [quartet for _, quartet in sorted(ranked)]


def _mask_is_unknown(value: str) -> bool:
    """Return true when a one-bit/vector X mask contains an asserted bit."""

    value = value.lower()
    return any(bit in value for bit in ("1", "x", "z"))


def first_vcd_divergence(vcd: Path, partition: str) -> dict[str, object] | None:
    """Find the first semantic gold/gate mismatch in an EQY VCD trace."""

    by_id, by_name = _vcd_header(vcd)
    quartets = _xprop_quartets(by_name, partition)
    pairs = _pair_candidates(by_name, partition)
    if not quartets and not pairs:
        return None

    watched_names = {name for quartet in quartets for name in quartet}
    watched_names.update(name for pair in pairs for name in pair[:2])
    context_names = tuple(
        name for name in ranked_signals(vcd, partition, limit=40)
        if any(word in name.lower() for word in ("clk", "clock", "rst", "reset"))
    )[:12]
    watched_names.update(context_names)
    watched_ids = {by_name[name] for name in watched_names if name in by_name}

    state: dict[str, str] = {}
    time = 0
    header_done = False

    def context() -> list[dict[str, str]]:
        return [
            {"signal": name, "value": state.get(by_name[name], "?")}
            for name in context_names
            if name in by_name
        ]

    def check() -> dict[str, object] | None:
        # Formal-X semantic comparison first.  Gold X is a don't-care under
        # EQY safe-replacement semantics; known gold data must match gate data.
        for gold_d, gold_x, gate_d, gate_x in quartets:
            ids = [by_name[name] for name in (gold_d, gold_x, gate_d, gate_x)]
            if any(identifier not in state for identifier in ids):
                continue
            gd, gx, td, tx = (state[identifier] for identifier in ids)
            gold_unknown = _mask_is_unknown(gx)
            gate_unknown = _mask_is_unknown(tx)
            if gate_unknown or (not gold_unknown and gd != td):
                return {
                    "time": time,
                    "gold_signal": gold_d,
                    "gate_signal": gate_d,
                    "gold": gd,
                    "gate": td,
                    "gold_x_signal": gold_x,
                    "gate_x_signal": gate_x,
                    "gold_x": gx,
                    "gate_x": tx,
                    "kind": "xprop",
                    "class": "x-init" if gate_unknown else "boolean-data",
                    "context": context(),
                }

        # Fall back to ordinary gold/gate pairs only when no formal-X quartet
        # exists for that logical pair.  This keeps old/non-xprop traces useful.
        quartet_names = {name for quartet in quartets for name in quartet}
        for gold, gate, kind in pairs:
            if gold in quartet_names or gate in quartet_names:
                continue
            gold_id = by_name[gold]
            gate_id = by_name[gate]
            if gold_id not in state or gate_id not in state:
                continue
            gold_value = state[gold_id]
            gate_value = state[gate_id]
            if gold_value != gate_value:
                category = (
                    "x-init"
                    if kind == "xmask" or any(char in gold_value + gate_value for char in "xz")
                    else "boolean-data"
                )
                return {
                    "time": time,
                    "gold_signal": gold,
                    "gate_signal": gate,
                    "gold": gold_value,
                    "gate": gate_value,
                    "kind": kind,
                    "class": category,
                    "context": context(),
                }
        return None

    with vcd.open("r", encoding="utf-8", errors="replace") as handle:
        pending_check = False
        for raw in handle:
            line = raw.strip()
            if not header_done:
                if line.startswith("$enddefinitions"):
                    header_done = True
                continue
            if not line:
                continue
            if line.startswith("#"):
                if pending_check:
                    found = check()
                    if found:
                        return found
                try:
                    time = int(line[1:])
                except ValueError:
                    pass
                pending_check = False
                continue
            if line.startswith("$"):
                continue
            if line[0] in "bBrR":
                parts = line.split()
                if len(parts) >= 2 and parts[1] in watched_ids:
                    state[parts[1]] = _normalize_vcd_value(parts[0])
                    pending_check = True
            else:
                identifier = line[1:]
                if identifier in watched_ids:
                    state[identifier] = _normalize_vcd_value(line[0])
                    pending_check = True
        if pending_check:
            return check()
    return None


def _eqy_config_for_result(result_dir: Path) -> Path:
    """Return the generated EQY config associated with one result directory."""

    result_dir = result_dir.expanduser().resolve()
    eqy_root = result_dir.parent
    config = eqy_root / f"{result_dir.name}.eqy"
    if config.is_file():
        return config
    candidates = tuple(sorted(eqy_root.glob("*.eqy")))
    if len(candidates) != 1:
        raise FileNotFoundError(f"cannot identify EQY config beside result: {result_dir}")
    return candidates[0]


def _probe_target(result_dir: Path, partition: str) -> str:
    """Return the final generated strategy target for one EQY partition."""

    path = result_dir / "summary_targets.list"
    if not path.is_file():
        raise RuntimeError(f"EQY setup did not create {path}")
    prefix = f"strategies/{partition}/"
    matches = [line.strip() for line in path.read_text(encoding="utf-8").splitlines()
               if line.strip().startswith(prefix) and line.strip().endswith("/status")]
    if len(matches) != 1:
        raise RuntimeError(
            f"cannot identify final EQY strategy target for {partition}: "
            f"found {len(matches)}"
        )
    return matches[0]


def _run_eqy_probe(
    result_dir: Path,
    *,
    name: str,
    config_text: str,
    partition: str,
    eqy: str = "eqy",
) -> dict[str, object]:
    """Set up EQY, then prove only ``partition`` instead of the full design."""

    result_dir = result_dir.expanduser().resolve()
    config = _eqy_config_for_result(result_dir)
    diagnostic_dir = result_dir.parent / "diagnostics" / name
    diagnostic_dir.mkdir(parents=True, exist_ok=True)
    diagnostic_config = diagnostic_dir / config.name
    diagnostic_result = diagnostic_dir / config.stem
    log = diagnostic_dir / "eqy_debug.log"
    stamp = diagnostic_dir / ".probe.json"
    digest = hashlib.sha256(config_text.encode("utf-8")).hexdigest()
    key = {"config_sha256": digest, "partition": partition}

    executable = shutil.which(eqy) or (eqy if Path(eqy).is_file() else None)
    if executable is None:
        raise FileNotFoundError(f"EQY executable not found: {eqy}")

    cached = False
    target = None
    if diagnostic_result.is_dir() and stamp.is_file():
        try:
            cached = json.loads(stamp.read_text(encoding="utf-8")) == key
            if cached:
                target = _probe_target(diagnostic_result, partition)
                cached = (diagnostic_result / target).is_file()
        except (OSError, ValueError, json.JSONDecodeError, RuntimeError):
            cached = False

    setup_seconds = 0.0
    prove_seconds = 0.0
    if not cached:
        diagnostic_config.write_text(config_text, encoding="utf-8")
        if diagnostic_result.exists():
            shutil.rmtree(diagnostic_result)
        started = time.monotonic()
        with log.open("w", encoding="utf-8") as handle:
            setup = subprocess.run(
                (str(executable), "-f", "-m", diagnostic_config.name),
                cwd=diagnostic_dir, stdout=handle, stderr=subprocess.STDOUT,
                text=True, check=False,
            )
        setup_seconds = time.monotonic() - started
        if setup.returncode != 0 or not diagnostic_result.is_dir():
            tail = log.read_text(encoding="utf-8", errors="replace").splitlines()[-20:]
            raise RuntimeError("EQY diagnostic setup failed (rc=%d)%s" % (
                setup.returncode, "\n" + "\n".join(tail) if tail else ""
            ))
        target = _probe_target(diagnostic_result, partition)
        started = time.monotonic()
        with log.open("a", encoding="utf-8") as handle:
            handle.write(f"\n[eqy_debug] make {target}\n")
            prove = subprocess.run(
                ("make", "--no-print-directory", "-C", str(diagnostic_result),
                 "-f", "strategies.mk", target),
                stdout=handle, stderr=subprocess.STDOUT, text=True, check=False,
            )
        prove_seconds = time.monotonic() - started
        stamp.write_text(json.dumps(key, sort_keys=True) + "\n", encoding="utf-8")
        if prove.returncode != 0 and not (diagnostic_result / target).is_file():
            tail = log.read_text(encoding="utf-8", errors="replace").splitlines()[-20:]
            raise RuntimeError("EQY partition probe failed (rc=%d)%s" % (
                prove.returncode, "\n" + "\n".join(tail) if tail else ""
            ))

    assert target is not None
    item = select(scan(diagnostic_result), partition)
    log_tail = [line.rstrip() for line in log.read_text(encoding="utf-8", errors="replace").splitlines()[-16:] if line.strip()] if log.is_file() else []
    return {
        "config": str(diagnostic_config), "result_dir": str(diagnostic_result),
        "log": str(log), "valid": item.status != "MISSING",
        "partition": partition, "status": item.status, "pass": item.status == "PASS",
        "strategy": item.failing_strategy.name if item.failing_strategy else None,
        "cached": cached, "setup_seconds": setup_seconds, "prove_seconds": prove_seconds,
        "log_tail": log_tail,
    }


def _inject_reset_initialization(
    source: str,
    *,
    clock: str,
    reset: str,
    reset_active: str,
    reset_cycles: int,
    domains: Sequence[tuple[str, str, str]] | None = None,
) -> str:
    """Inject reset initialization into the common EQY preprocessing."""

    source = re.sub(
        r"(?ms)^# FlexSoC EQY reset normalization begin\n.*?"
        r"^# FlexSoC EQY reset normalization end\n?",
        "",
        source,
    )
    specs = tuple(domains or ((clock, reset, reset_active),))
    if reset_cycles <= 0:
        raise ValueError("reset_cycles must be > 0")
    commands: list[str] = ["# FlexSoC EQY reset normalization begin"]
    for domain_clock, domain_reset, polarity in specs:
        if polarity not in {"low", "high"}:
            raise ValueError("reset polarity must be 'low' or 'high'")
        for label, signal in (("clock", domain_clock), ("reset", domain_reset)):
            if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_$]*", signal):
                raise ValueError(f"invalid {label} port name: {signal!r}")
        reset_opt = "-resetn" if polarity == "low" else "-reset"
        commands.append(
            f"sim -clock {domain_clock} {reset_opt} {domain_reset} "
            f"-rstlen {reset_cycles} -n {reset_cycles} -w"
        )
    commands.append("# FlexSoC EQY reset normalization end")
    lines = source.splitlines()

    # Apply one preprocessing script to gold and gate; single-clock adds async2sync.
    # Multi-clock leaves event lowering to SBY after memory lowering.
    section = ""
    anchors = ("async2sync", "memory_map -formal", "memory -nomap")
    present = next((anchor for anchor in anchors if any(line.strip() == anchor for line in lines)), None)
    if present:
        out: list[str] = []
        inserted = False
        for line in lines:
            stripped = line.strip()
            if stripped.startswith("[") and stripped.endswith("]"):
                section = stripped[1:-1].split()[0].lower()
            out.append(line)
            if section == "script" and stripped == present and not inserted:
                out.extend(("uniquify", *commands))
                inserted = True
        if inserted:
            return "\n".join(out) + ("\n" if source.endswith("\n") else "")

    # Independently prepared views must uniquify reused technology modules.
    # This keeps state writeback legal before sim -w.
    out = []
    section = ""
    inserted_sides: set[str] = set()
    for line in lines:
        stripped = line.strip()
        if stripped.startswith("[") and stripped.endswith("]"):
            section = stripped[1:-1].split()[0].lower()
        out.append(line)
        if section in {"gold", "gate"} and stripped.startswith("prep "):
            out.extend(("uniquify", *commands))
            inserted_sides.add(section)
    missing = {"gold", "gate"} - inserted_sides
    if missing:
        raise ValueError(
            "cannot inject reset initialization; missing shared normalization anchor or prep "
            "command in EQY section(s): " + ", ".join(sorted(missing))
        )
    return "\n".join(out) + ("\n" if source.endswith("\n") else "")

def run_reset_normalized_diagnostic(
    result_dir: Path,
    *,
    partition: str,
    clock: str = "clk_i",
    reset: str = "rst_ni",
    reset_active: str = "low",
    reset_cycles: int = 1,
    eqy: str = "eqy",
    domains: Sequence[tuple[str, str, str]] | None = None,
) -> dict[str, object]:
    """Replay EQY after initializing both sides through the real reset port."""

    config = _eqy_config_for_result(result_dir)
    source = config.read_text(encoding="utf-8")
    rewritten = _inject_reset_initialization(
        source,
        clock=clock,
        reset=reset,
        reset_active=reset_active,
        reset_cycles=reset_cycles,
        domains=domains,
    )
    baseline = hashlib.sha256()
    for name in ("gold.il", "gate.il"):
        path = result_dir / name
        if path.is_file():
            baseline.update(path.read_bytes())
    rewritten += f"# FlexSoC baseline_sha256 {baseline.hexdigest()}\n"
    result = _run_eqy_probe(
        result_dir, name="reset_normalized", config_text=rewritten,
        partition=partition, eqy=eqy,
    )
    result.update(
        {
            "clock": clock,
            "reset": reset,
            "reset_active": reset_active,
            "reset_cycles": reset_cycles,
            "domains": [
                {"clock": item[0], "reset": item[1], "polarity": item[2]}
                for item in (domains or ((clock, reset, reset_active),))
            ],
        }
    )
    return result

def _replace_gate_netlist(source: str, checkpoint: Path) -> str:
    """Replace only the mapped design read while preserving any formal wrapper."""

    lines = source.splitlines()
    section = ""
    candidates: list[int] = []
    implementation_rename: int | None = None
    for index, line in enumerate(lines):
        stripped = line.strip()
        if stripped.startswith("[") and stripped.endswith("]"):
            section = stripped[1:-1].split()[0].lower()
        elif section == "gate" and stripped.startswith(("read_verilog ", "read_rtlil ")):
            candidates.append(index)
        elif section == "gate" and re.fullmatch(r"rename\s+\S+\s+\S+__eqy_impl", stripped):
            implementation_rename = index
        elif section == "gate" and stripped.startswith("prep "):
            break
    if implementation_rename is not None:
        candidates = [index for index in candidates if index < implementation_rename]
    if not candidates:
        raise ValueError("cannot identify mapped netlist read in EQY [gate] section")
    checkpoint = checkpoint.expanduser().resolve()
    lines[candidates[-1]] = f"read_rtlil {checkpoint}"
    digest = hashlib.sha256(checkpoint.read_bytes()).hexdigest()
    lines.append(f"# FlexSoC checkpoint_sha256 {digest}")
    return "\n".join(lines) + ("\n" if source.endswith("\n") else "")


def synthesis_boundary_diagnosis(stages: Mapping[str, object]) -> str:
    """Classify checkpoint results without turning UNKNOWN or TIMEOUT into mismatches."""

    order = ("generic", "dffmap", "abc", "clean")
    if any(
        isinstance(stages.get(name), Mapping) and stages[name].get("missing")
        for name in order
    ):
        return "missing"
    for name in order:
        stage = stages.get(name)
        status = str(stage.get("status", "UNKNOWN")) if isinstance(stage, Mapping) else "UNKNOWN"
        if status == "FAIL":
            return f"{name}_fail"
        if status != "PASS":
            return f"{name}_inconclusive"
    return "serialization"


def run_synthesis_boundary_diagnostics(
    result_dir: Path,
    *,
    top: str,
    syn_dir: Path,
    partition: str,
    eqy: str = "eqy",
    progress: Callable[[str], None] | None = None,
) -> dict[str, object]:
    """Probe only one failing partition at natural synthesis boundaries."""

    config = _eqy_config_for_result(result_dir)
    source = config.read_text(encoding="utf-8")
    checkpoints = {
        "generic": syn_dir / f"{top}_generic.il",
        "dffmap": syn_dir / f"{top}_dffmap.il",
        "abc": syn_dir / f"{top}_abc.il",
        "clean": syn_dir / f"{top}_clean.il",
    }
    stages: dict[str, object] = {}
    for name, checkpoint in checkpoints.items():
        if not checkpoint.is_file():
            stages[name] = {"valid": False, "missing": str(checkpoint)}
            continue
        if progress:
            progress(name)
        try:
            stages[name] = _run_eqy_probe(
                result_dir, name=f"synthesis_{name}",
                config_text=_replace_gate_netlist(source, checkpoint),
                partition=partition, eqy=eqy,
            )
        except (FileNotFoundError, ValueError, RuntimeError, OSError) as exc:
            stages[name] = {"valid": False, "error": str(exc), "checkpoint": str(checkpoint)}
        else:
            stages[name]["checkpoint"] = str(checkpoint)  # type: ignore[index]
    return {"partition": partition, "stages": stages}


def explain_counterexample(item: Counterexample, *, trace_kind: str = "auto") -> dict[str, object]:
    """Build a machine-readable explanation of one EQY counterexample."""

    strategy = item.failing_strategy
    if strategy is None:
        raise ValueError(f"partition {item.partition} has no failing strategy")
    metadata = failure_metadata(strategy)
    result: dict[str, object] = {
        "partition": item.partition,
        "status": item.status,
        "strategy": strategy.name,
        "failure": metadata,
        "diagnostics": interesting_log_lines(strategy),
        "trace": None,
        "first_divergence": None,
        "classification": "unclassified",
        "interpretation": [],
    }
    try:
        trace = choose_trace(strategy, trace_kind)
    except FileNotFoundError:
        return result

    result["trace"] = str(trace)
    divergence = first_vcd_divergence(trace, item.partition)
    result["first_divergence"] = divergence
    interpretation: list[str] = []
    if divergence:
        category = str(divergence.get("class", "unclassified"))
        result["classification"] = category
        if category == "x-init":
            interpretation.append(
                "Gold/gate X-state encoding diverges first; inspect reset, initialization, and xprop semantics before treating this as a Boolean logic mismatch."
            )
        elif category == "boolean-data":
            interpretation.append(
                "Gold/gate known data values diverge; inspect the mapped sequential/data cone and technology-cell semantics."
            )
    phase = metadata.get("phase")
    step = metadata.get("step")
    if phase == "basecase":
        suffix = f" at step {step}" if step is not None else ""
        interpretation.append(
            f"The failure is a concrete bounded counterexample in the basecase{suffix}, not a solver timeout or incomplete induction."
        )
    elif phase == "induction":
        interpretation.append(
            "The bounded basecase did not identify the first failure; inspect the induction trace and reachable-state assumptions."
        )
    result["interpretation"] = interpretation
    return result


@dataclass(slots=True)
class EquivalenceFlow:
    """Prepare, run and diagnose RTL-to-synthesis equivalence."""

    runner: object | None = None

    def __post_init__(self) -> None:
        if self.runner is None:
            from flexsoc.backend.core.execution import ToolRunner
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

        clocks = clock_config()
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
            use_sat=_env_bool("EQY_USE_SAT", not resolved_multiclock),
            use_pdr=_env_bool("EQY_USE_PDR", True),
            pdr_engine=(
                pdr_engine.strip()
                if pdr_engine is not None and pdr_engine.strip()
                else os.environ.get("EQY_PDR_ENGINE", "abc pdr").strip() or "abc pdr"
            ),
            smt_engine=os.environ.get("EQY_SMT_ENGINE", "smtbmc bitwuzla").strip(),
            smt_depth=int(os.environ.get("EQY_SMT_DEPTH", "5" if resolved_multiclock else "2")),
            xprop=os.environ.get("EQY_XPROP", "on").strip().lower(),
            join_outputs=_env_bool("EQY_JOIN_OUTPUTS", True),
            strategy_order=order,
            reset_normalize=_env_bool("EQY_RESET_NORMALIZE", not resolved_multiclock),
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

        bind_equivalence_profile(
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
                engine=engine,
                depth=depth,
                sat_depth=sat_depth,
                output=config,
                pdr_engine=pdr_engine,
                pdk=pdk,
                multiclock=multiclock,
                reset_domains=reset_domains,
            )
            generate_equivalence_config(cfg, runner=self.runner, on=on)
        if not view.is_file():
            raise FileNotFoundError(f"missing EQY formal view: {view}")
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
        """Run EQY using the prepared profile."""

        from flexsoc.backend.core.execution import CommandRequest

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
        return self.runner.run(request, on=on).returncode

    def debug(
        self,
        result_dir: Path,
        *,
        partition: str | None = None,
        trace_kind: str = "auto",
    ) -> dict[str, object]:
        """Return structured diagnostics for one unresolved partition."""

        results = scan(result_dir)
        item = select(results, partition) if results else None
        if item is None:
            return {"status": "missing", "result_dir": str(result_dir)}
        return explain_counterexample(item, trace_kind=trace_kind)

    def flow(self, *, setup: dict, run: dict) -> int:
        """Prepare the profile and run equivalence."""

        self.setup(**setup)
        return self.run(**run)
