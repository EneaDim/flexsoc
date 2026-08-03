"""Generate FlexSoC design-signoff configurations.

This module owns technology-dependent sign-off intent: RTL-to-mapped-netlist
EQY equivalence plus OpenSTA timing, SDF, and power scripts.  Property formal
(BMC/PROVE/COVER) deliberately remains in :mod:`setup_formal`.
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass, field, replace
from pathlib import Path
from typing import Sequence

from flexsoc.backend.output import print_script
from flexsoc.clocking import clock_config


@dataclass
class STAConfig:
    """Configuration used to render OpenSTA timing, SDF, and power scripts."""

    top: str
    sta_dir: Path
    power_dir: Path
    sdf_dir: Path
    syndir: Path | None = None
    sdcdir: Path | None = None
    simdir: Path | None = None
    liberty: list[Path] = field(default_factory=list)
    power_activity: float = 0.1
    power_duty: float = 0.5


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
    engine: str
    depth: int
    sat_depth: int
    output: Path
    formal_cell_model: Path | None = None
    formal_pdk_proc: Path | None = None
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
    """Return the formal contract ports used to partition TL-UL responses.

    A packed 66-bit ``tl_o`` response is a poor monolithic EQY partition.  The
    formal wrapper therefore exposes five canonical witness outputs per TL-UL
    response.  They preserve the exact protocol care set while allowing EQY to
    prove handshake, control, payload, and metadata in bounded-size partitions.
    """

    responses = {port.name for port in _tlul_response_ports(ports)}
    contract: list[NetlistPort] = []
    for port in ports:
        if port.name not in responses:
            contract.append(port)
            continue
        prefix = f"{port.name}__flexsoc_eqy"
        contract.extend((
            NetlistPort("output", f"{prefix}_a_ready"),
            NetlistPort("output", f"{prefix}_d_valid"),
            NetlistPort("output", f"{prefix}_d_ctrl", "[16:0]"),
            NetlistPort("output", f"{prefix}_d_data", "[31:0]"),
            NetlistPort("output", f"{prefix}_d_meta", "[14:0]"),
        ))
    return tuple(contract)


def render_formal_protocol_view(top: str, ports: Sequence[NetlistPort]) -> str:
    """Render a symmetric formal view for protocol-defined don't-care outputs.

    The functional RTL and synthesized netlist remain untouched.  The view only
    canonicalizes TL-UL response fields outside their protocol care set: the
    D-channel payload is ignored while ``d_valid`` is low, and ``d_data`` is
    ignored for error responses.  Valid, successful read data is compared in
    full.  Each packed response is also projected onto five formal-only witness
    outputs so EQY does not have to solve one monolithic 66-bit partition.
    The packed response remains internal to the wrapper: exposing it as a
    public output would cause EQY to create duplicate raw bit partitions in
    addition to the canonical witnesses.
    """

    responses = {port.name for port in _tlul_response_ports(ports)}
    if not responses:
        return ""
    impl = f"{top}__eqy_impl"
    contract_ports = _tlul_contract_ports(ports)
    witnesses = tuple(port for port in contract_ports if "__flexsoc_eqy_" in port.name)
    # Do not expose the packed protocol response itself at the formal-view
    # boundary.  EQY partitions every public output even when it is excluded
    # from the explicit match list; retaining the raw 66-bit response would
    # therefore recreate one bit partition per raw output alongside the
    # canonical witnesses.  Both gold and gate instantiate the same wrapper,
    # so the raw response can remain an internal wire while the externally
    # visible contract consists only of the bounded protocol witnesses.
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
            f"  assign {prefix}_a_ready = {raw}[0];",
            f"  assign {prefix}_d_valid = {raw}[65];",
            f"  assign {prefix}_d_ctrl = {raw}[65] ? {raw}[64:48] : '0;",
            f"  assign {prefix}_d_data = ({raw}[65] && !{raw}[1]) ? {raw}[47:16] : '0;",
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


def _gate_model_reads(
    cfg: EquivalenceConfig,
    *,
    liberty: Path,
    netlist: Path,
    cell_models: Sequence[Path],
) -> list[str]:
    """Read functional cell models when safe, otherwise use Liberty fallback.

    LibreLane's EQY flow uses functional standard-cell Verilog and a dedicated
    SKY130 formal-PDK preprocessor.  FlexSoC follows that model when a prepared
    model is available.  SKY130 falls back to Liberty if the external processor
    is unavailable; other PDKs use their FUNCTIONAL Verilog models directly.
    """

    pdk = os.environ.get("FLEXSOC_PDK", "").strip().lower()
    reads: list[str] = []
    if cfg.formal_cell_model is not None:
        reads.append(f"read_verilog -formal -sv {cfg.formal_cell_model}")
    elif pdk == "ihp-sg13g2":
        # The official IHP aggregate Verilog model contains conditional specify
        # paths that are accepted by event-driven simulators but not by the
        # Yosys frontend used by EQY.  The selected Liberty view is discovered
        # from the actual IHP PDK_ROOT and provides the formal cell semantics
        # without depending on the PDK's nested filesystem layout.
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

    order = cfg.strategy_order or (("pdr", "smt") if cfg.multiclock else ("sat", "smt", "pdr"))
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

    if cfg.depth <= 0:
        raise ValueError("EQY SBY depth must be > 0")
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


def _prepare_formal_cell_model(cfg: EquivalenceConfig) -> EquivalenceConfig:
    """Prepare SKY130 functional Verilog without making LibreLane a dependency."""

    pdk = os.environ.get("FLEXSOC_PDK", "").strip().lower()
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
    command = [processor, "--output", str(output), *(str(path) for path in models)]

    result = subprocess.run(command, text=True, capture_output=True, check=False)
    if result.returncode != 0:
        detail = (result.stderr or result.stdout).strip()
        raise ValueError(
            f"formal PDK preprocessing failed ({result.returncode}): {' '.join(command)}"
            + (f"\n{detail}" if detail else "")
        )
    if not output.is_file():
        raise ValueError(f"formal PDK preprocessor did not create: {output}")
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


def generate_equivalence_config(cfg: EquivalenceConfig) -> Path:
    """Generate optional PDK compatibility models and one EQY config."""

    pdk = os.environ.get("FLEXSOC_PDK", "").strip().lower()
    body = (
        render_sky130_clock_gate_model()
        if pdk == "sky130"
        else "// No PDK-specific EQY compatibility model required.\n"
    )
    write_text(cfg.sky130_clock_gate_model, body)
    prepared = _prepare_formal_protocol_view(_prepare_formal_cell_model(cfg))
    return write_text(cfg.output, render_eqy(prepared))


def liberty_corner(path: Path) -> str:
    """Infer a short process corner name from a Liberty filename."""

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


def tcl_quote(path: Path) -> str:
    """Quote a filesystem path using Tcl brace syntax."""

    return "{" + path.as_posix() + "}"


def render_init_opensta(config: STAConfig) -> str:
    """Render OpenSTA initialization shared by timing, SDF, and power."""

    lines = [
        'puts ""',
        'puts "=== flexsoc OpenSTA init ==="',
        'if {[info exists ::env(STA_CORNER)]} {set sta_corner $::env(STA_CORNER)} else {set sta_corner "default"}',
    ]
    if config.liberty:
        entries = " ".join("{" + liberty_corner(lib) + " " + lib.resolve().as_posix() + "}" for lib in config.liberty)
        fallback = next((lib for lib in config.liberty if liberty_corner(lib) == "tt"), config.liberty[0])
        lines += [
            f"set liberty_files {{{entries}}}",
            'set selected_lib ""',
            'foreach item $liberty_files {',
            '  lassign $item corner path',
            '  if {$corner == $sta_corner} {set selected_lib $path}',
            '}',
            'if {$selected_lib == "" && $sta_corner != "default"} {',
            '  puts stderr "ERROR: no Liberty configured for corner=$sta_corner"',
            '  exit 2',
            '}',
            f'if {{$selected_lib == ""}} {{set selected_lib "{fallback.resolve().as_posix()}"}}',
            'puts "corner=$sta_corner liberty=$selected_lib"',
            'read_liberty $selected_lib',
        ]
    else:
        lines.append('puts "WARNING: no --liberty provided"')

    if config.syndir:
        netlist = (config.syndir / f"{config.top}_synth.v").resolve()
        lines += [f'puts "read_verilog {tcl_quote(netlist)}"', f"read_verilog {tcl_quote(netlist)}"]
    else:
        lines.append('puts "WARNING: no --synthesis-dir provided; skipping read_verilog"')

    lines += [f'puts "link_design {config.top}"', f"link_design {config.top}"]
    if config.sdcdir:
        sdc = (config.sdcdir / f"{config.top}.sdc").resolve()
        lines += [f'puts "read_sdc {tcl_quote(sdc)}"', f"read_sdc {tcl_quote(sdc)}"]
    else:
        lines.append('puts "WARNING: no --constraints-dir provided; skipping read_sdc"')
    return "\n".join(lines)


def render_sta_tcl(config: STAConfig) -> str:
    """Render a corner/mode aware OpenSTA timing report script."""

    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'if {[info exists ::env(STA_MODE)]} {set sta_mode $::env(STA_MODE)} else {set sta_mode "setup"}',
            'if {$sta_mode == "hold"} {set delay_type "min"} else {set delay_type "max"}',
            'puts "=== Static timing analysis ==="',
            'puts "corner=$sta_corner mode=$sta_mode path_delay=$delay_type"',
            'if {[info exists ::env(STA_PATHS)]} {set sta_paths $::env(STA_PATHS)} else {set sta_paths 100}',
            'if {[info exists ::env(STA_GROUPS)]} {set sta_groups $::env(STA_GROUPS)} else {set sta_groups 20}',
            'puts "report_checks group_count=$sta_groups endpoint_count=$sta_paths"',
            'report_checks -path_delay $delay_type -fields {slew cap input_pins nets fanout} -digits 3 -group_count $sta_groups -endpoint_count $sta_paths -sort_by_slack',
            'report_tns',
            'report_wns',
            'puts "=== flexsoc unconstrained paths ==="',
            'report_checks -unconstrained -path_delay $delay_type -group_count $sta_groups -endpoint_count $sta_paths',
            'puts "=== flexsoc unconstrained paths end ==="',
            "",
        ]
    )


def render_sta_violators_tcl(config: STAConfig) -> str:
    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Violators ==="',
            "report_check_types -max_slew -max_cap -max_fanout -violators",
            "report_checks -path_delay max -slack_max 0.0",
            "report_checks -path_delay min -slack_max 0.0",
            "",
        ]
    )


def render_write_sdf_tcl(config: STAConfig) -> str:
    """Render one SDF export into the PDK-specific SDF branch."""

    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Write SDF ==="',
            f'set sdf_file [file join {tcl_quote(config.sdf_dir.resolve())} "{config.top}_${{sta_corner}}.sdf"]',
            'puts "corner=$sta_corner sdf=$sdf_file"',
            'write_sdf -divider . -include_typ $sdf_file',
            "",
        ]
    )


def render_power_estimate_tcl(config: STAConfig) -> str:
    return "\n".join(
        [
            render_init_opensta(config),
            "",
            'puts "=== Estimated power analysis ==="',
            f'puts "analysis=estimate activity_source=global activity={config.power_activity} transitions_per_cycle duty={config.power_duty}"',
            'puts "corner=$sta_corner"',
            f"set_power_activity -global -activity {config.power_activity} -duty {config.power_duty}",
            'puts "report_power"',
            "report_power",
            "",
        ]
    )


def write_signoff_scripts(config: STAConfig) -> list[Path]:
    """Write STA, power, and SDF scripts into function-first PDK directories."""

    for directory in (config.sta_dir, config.power_dir, config.sdf_dir):
        directory.mkdir(parents=True, exist_ok=True)
    return [
        write_text(config.sta_dir / "sta.tcl", render_sta_tcl(config)),
        write_text(config.sta_dir / "sta_violators.tcl", render_sta_violators_tcl(config)),
        write_text(config.sdf_dir / "write_sdf.tcl", render_write_sdf_tcl(config)),
        write_text(config.power_dir / "power_estimate.tcl", render_power_estimate_tcl(config)),
    ]


def _add_equivalence_args(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--top", required=True)
    parser.add_argument("--filelist", action="append", type=Path, required=True)
    parser.add_argument("--netlist", type=Path, required=True)
    parser.add_argument("--liberty", type=Path, required=True)
    parser.add_argument("--cell-model", action="append", type=Path, default=[])
    parser.add_argument("--formal-pdk-proc", type=Path)
    parser.add_argument("--sky130-clock-gate-model", type=Path, required=True)
    parser.add_argument("--engine", required=True)
    parser.add_argument("--depth", type=int, default=20)
    parser.add_argument("--sat-depth", type=int, default=5)
    parser.add_argument("--timeout", type=int, default=60)
    parser.add_argument("--output", type=Path, required=True)


def parse_args(argv: Sequence[str]) -> argparse.Namespace:
    """Parse the sign-off generator CLI."""

    parser = argparse.ArgumentParser(description="Generate FlexSoC sign-off configurations.")
    subparsers = parser.add_subparsers(dest="command", required=True)

    analysis = subparsers.add_parser("analysis", help="Generate OpenSTA STA/SDF/power scripts.")
    analysis.add_argument("--top", required=True)
    analysis.add_argument("--sta-dir", type=Path, required=True)
    analysis.add_argument("--power-dir", type=Path, required=True)
    analysis.add_argument("--sdf-dir", type=Path, required=True)
    analysis.add_argument("--synthesis-dir", dest="syndir")
    analysis.add_argument("--constraints-dir", dest="sdcdir")
    analysis.add_argument("--simulation-dir", dest="simdir")
    analysis.add_argument("--liberty", dest="liberty", action="append", default=[])
    analysis.add_argument("--power-activity", type=float, default=0.1)
    analysis.add_argument("--power-duty", type=float, default=0.5)

    eqy = subparsers.add_parser("eqy", help="Generate RTL-vs-synthesis EQY config.")
    _add_equivalence_args(eqy)
    return parser.parse_args(list(argv))


def _sta_config(args: argparse.Namespace) -> STAConfig:
    if args.power_activity < 0.0:
        raise ValueError("--power-activity must be >= 0")
    if not 0.0 <= args.power_duty <= 1.0:
        raise ValueError("--power-duty must be between 0 and 1")
    return STAConfig(
        top=args.top,
        sta_dir=args.sta_dir.resolve(),
        power_dir=args.power_dir.resolve(),
        sdf_dir=args.sdf_dir.resolve(),
        syndir=optional_path(args.syndir),
        sdcdir=optional_path(args.sdcdir),
        simdir=optional_path(args.simdir),
        liberty=split_liberties(args.liberty),
        power_activity=float(args.power_activity),
        power_duty=float(args.power_duty),
    )


def _equivalence_config(args: argparse.Namespace) -> EquivalenceConfig:
    clocks = clock_config()
    multiclock = clocks.multiclock
    timeout = int(os.environ.get("EQY_TIMEOUT", "30" if multiclock else str(args.timeout)))
    quick_timeout = int(os.environ.get("EQY_QUICK_TIMEOUT", "5"))
    splitnets = os.environ.get("EQY_SPLITNETS", "off").strip().lower()
    use_sat = _env_bool("EQY_USE_SAT", not multiclock)
    use_pdr = _env_bool("EQY_USE_PDR", True)
    pdr_engine = os.environ.get("EQY_PDR_ENGINE", args.engine).strip() or "abc pdr"
    smt_engine = os.environ.get("EQY_SMT_ENGINE", "smtbmc bitwuzla").strip()
    smt_depth = int(os.environ.get("EQY_SMT_DEPTH", "5" if multiclock else "2"))
    xprop = os.environ.get("EQY_XPROP", "on").strip().lower()
    join_outputs = _env_bool("EQY_JOIN_OUTPUTS", True)
    reset_normalize = _env_bool("EQY_RESET_NORMALIZE", not multiclock)
    reset_cycles = int(os.environ.get("EQY_RESET_CYCLES", "2"))
    raw_order = os.environ.get("EQY_STRATEGY_ORDER", "auto").strip().lower()
    strategy_order = () if raw_order in {"", "auto"} else tuple(
        token.strip() for token in raw_order.split(",") if token.strip()
    )
    return EquivalenceConfig(
        top=args.top,
        filelists=tuple(args.filelist),
        netlist=args.netlist,
        liberty=args.liberty,
        cell_models=tuple(args.cell_model),
        formal_pdk_proc=args.formal_pdk_proc,
        sky130_clock_gate_model=args.sky130_clock_gate_model,
        engine=args.engine,
        depth=args.depth,
        sat_depth=args.sat_depth,
        output=args.output,
        timeout=timeout,
        quick_timeout=quick_timeout,
        multiclock=multiclock,
        splitnets=splitnets,
        use_sat=use_sat,
        use_pdr=use_pdr,
        pdr_engine=pdr_engine,
        smt_engine=smt_engine,
        smt_depth=smt_depth,
        xprop=xprop,
        join_outputs=join_outputs,
        strategy_order=strategy_order,
        reset_normalize=reset_normalize,
        reset_cycles=reset_cycles,
        reset_domains=tuple(
            (domain.signal, domain.reset, domain.reset_polarity)
            for domain in clocks.domains
        ),
    )


def main(argv: Sequence[str]) -> int:
    """Generate the requested sign-off configuration."""

    args = parse_args(argv)
    try:
        if args.command == "analysis":
            for path in write_signoff_scripts(_sta_config(args)):
                print_script(path)
        else:
            print(generate_equivalence_config(_equivalence_config(args)))
    except ValueError as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
