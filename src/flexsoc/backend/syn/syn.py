"""Yosys/ABC synthesis setup and execution helpers."""

from __future__ import annotations

import json
import re
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence


SYNTHESIS_PROFILES = (
    "area0", "area1", "area2", "area3",
    "delay0", "delay1", "delay2", "delay3", "delay4",
)


def _repo_root() -> Path:
    """Return the repository root used for generated synthesis paths."""

    for parent in Path(__file__).resolve().parents:
        if (parent / "pyproject.toml").exists():
            return parent
    return Path.cwd()

def _rewrite_hw_ip_include_paths(script: str) -> str:
    """Resolve hw/ips include paths from the current repository root."""

    ip_root = (_repo_root() / "hw" / "ips").as_posix()
    for ip_name in ("pkgs", "prim_opentitan", "prim"):
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
    sdc: Path | None = None
    sdcdir: Path | None = None
    opt: str = "delay1"
    filelists: tuple[Path, ...] = (Path("rtl_common.f"), Path("rtl_ip.f"))
    tie_hi: tuple[str, str] | None = None
    tie_lo: tuple[str, str] | None = None
    min_buffer: tuple[str, str, str] | None = None
    platform: str | None = None



_YOSYS_SEQ_PORTS: dict[str, dict[str, str | None]] = {
    "$dff": {"clock": "CLK", "data": "D", "async": None, "sync": None, "async_value": None, "async_value_param": None, "async_polarity": None},
    "$dffe": {"clock": "CLK", "data": "D", "async": None, "sync": None, "async_value": None, "async_value_param": None, "async_polarity": None},
    "$adff": {"clock": "CLK", "data": "D", "async": "ARST", "sync": None, "async_value": None, "async_value_param": "ARST_VALUE", "async_polarity": "ARST_POLARITY"},
    "$adffe": {"clock": "CLK", "data": "D", "async": "ARST", "sync": None, "async_value": None, "async_value_param": "ARST_VALUE", "async_polarity": "ARST_POLARITY"},
    "$aldff": {"clock": "CLK", "data": "D", "async": "ALOAD", "sync": None, "async_value": "AD", "async_value_param": None, "async_polarity": "ALOAD_POLARITY"},
    "$aldffe": {"clock": "CLK", "data": "D", "async": "ALOAD", "sync": None, "async_value": "AD", "async_value_param": None, "async_polarity": "ALOAD_POLARITY"},
    "$sdff": {"clock": "CLK", "data": "D", "async": None, "sync": "SRST", "async_value": None, "async_value_param": None, "async_polarity": None},
    "$sdffe": {"clock": "CLK", "data": "D", "async": None, "sync": "SRST", "async_value": None, "async_value_param": None, "async_polarity": None},
    "$sdffce": {"clock": "CLK", "data": "D", "async": None, "sync": "SRST", "async_value": None, "async_value_param": None, "async_polarity": None},
}
_YOSYS_KEEP_ONE = "00000000000000000000000000000001"


def _json_bits(cell: dict, port: str | None) -> tuple[int | str, ...]:
    if port is None:
        return ()
    return tuple(cell.get("connections", {}).get(port, ()))


def _json_parameter_bool(cell: dict, name: str | None) -> str | None:
    if name is None:
        return None
    value = cell.get("parameters", {}).get(name)
    if value is None:
        return None
    text = str(value).strip()
    if not text:
        return None
    return "high" if text[-1] == "1" else "low"


def _json_constant_bits(bits: tuple[int | str, ...]) -> bool:
    """Return True when a Yosys JSON signal is a fully defined constant."""

    return bool(bits) and all(bit in {"0", "1"} for bit in bits)


def _json_parameter_bits(cell: dict, name: str | None) -> tuple[str, ...]:
    """Return a fully defined binary Yosys parameter value as bits."""

    if name is None:
        return ()
    value = cell.get("parameters", {}).get(name)
    if value is None:
        return ()
    text = str(value).strip()
    if not text or any(bit not in {"0", "1"} for bit in text):
        return ()
    return tuple(text)


def _json_async_value(cell: dict, spec: dict[str, str | None]) -> tuple[int | str, ...]:
    """Return the asynchronous reset/load value encoded by one Yosys cell."""

    port = spec.get("async_value")
    if port is not None:
        return _json_bits(cell, port)
    return _json_parameter_bits(cell, spec.get("async_value_param"))


def _json_async_reset_like(cell: dict, spec: dict[str, str | None]) -> bool:
    """Return whether the cell's asynchronous control has reset semantics.

    ``$adff``/``$adffe`` are reset cells by construction. ``$aldff`` and
    ``$aldffe`` are more general asynchronous-load cells, so FlexSoC only
    treats them as reset-like when the asynchronous data is a fully defined
    constant. This excludes functional asynchronous loads whose AD input
    carries live data.
    """

    async_port = spec["async"]
    if async_port is None:
        return False
    async_value_port = spec.get("async_value")
    if async_value_port is None:
        return True
    return _json_constant_bits(_json_bits(cell, async_value_port))


def _json_simple_signal_graph(cells: dict[str, dict]) -> tuple[
    dict[int | str, tuple[int | str, bool]],
    dict[int | str, tuple[int | str, ...]],
]:
    """Return backward/forward edges for scalar buffer/inverter logic.

    Reset polarity adaptation commonly lowers to ``$logic_not`` before the
    sequential cell. These edges are safe to traverse for reset ancestry and
    fanout because they contain no state or dynamic gating.
    """

    transparent = {"$buf", "$pos", "$_BUF_"}
    inverting = {"$not", "$logic_not", "$_NOT_"}
    backward: dict[int | str, tuple[int | str, bool]] = {}
    forward_sets: dict[int | str, set[int | str]] = {}
    for cell in cells.values():
        typ = str(cell.get("type", ""))
        if typ not in transparent | inverting:
            continue
        a = _json_bits(cell, "A")
        y = _json_bits(cell, "Y")
        # $logic_not is a reduction for vector A, so only scalar use is a
        # simple inverter. $not/$buf/$pos are bitwise and may be paired.
        if typ == "$logic_not" and (len(a) != 1 or len(y) != 1):
            continue
        if len(a) != len(y) or not a:
            continue
        invert = typ in inverting
        for src, dst in zip(a, y):
            backward[dst] = (src, invert)
            forward_sets.setdefault(src, set()).add(dst)
    forward = {bit: tuple(sorted(bits, key=str)) for bit, bits in forward_sets.items()}
    return backward, forward


def _json_control_signature(
    bit: int | str,
    polarity: str | None,
    backward: dict[int | str, tuple[int | str, bool]],
) -> tuple[int | str, str | None]:
    """Normalize one control through pure buffer/inverter ancestry."""

    current = bit
    active = polarity
    seen: set[int | str] = set()
    while current not in seen and current in backward:
        seen.add(current)
        current, invert = backward[current]
        if invert and active in {"low", "high"}:
            active = "high" if active == "low" else "low"
    return current, active


def _json_reachable_simple_bits(
    bit: int | str,
    forward: dict[int | str, tuple[int | str, ...]],
) -> set[int | str]:
    """Return bits reachable through only simple buffer/inverter logic."""

    reachable = {bit}
    pending = [bit]
    while pending:
        current = pending.pop()
        for nxt in forward.get(current, ()):
            if nxt in reachable:
                continue
            reachable.add(nxt)
            pending.append(nxt)
    return reachable


def reset_distribution_cells(design: dict, top: str) -> tuple[str, ...]:
    """Return reset-release FFs that must remain structurally distinct.

    Recognition is name-, design-, and PDK-independent. A reset-release stage
    is a scalar asynchronously reset/load sequential cell. The first stage has
    a constant normal D value different from its constant asynchronous value;
    later stages consume the previous stage Q while sharing clock, reset root,
    effective polarity, and asynchronous value.

    Buffer/inverter-only paths are normalized so frontend polarity adaptation
    (for example active-low reset lowered as active-high ``ALOAD`` behind a
    ``$logic_not``) does not change reset identity. A chain is retained only
    when its terminal Q reaches a reset-like control of another sequential cell
    through buffer/inverter-only logic. Dynamic gating and functional async
    loads are deliberately excluded.
    """

    modules = design.get("modules", {})
    if top not in modules:
        raise ValueError(f"top module not found in pre-synthesis JSON: {top}")
    cells = modules[top].get("cells", {})
    backward, forward = _json_simple_signal_graph(cells)

    seq: dict[str, dict] = {}
    q_driver: dict[int | str, str] = {}
    for name, cell in cells.items():
        spec = _YOSYS_SEQ_PORTS.get(str(cell.get("type", "")))
        if spec is None:
            continue
        clk = _json_bits(cell, spec["clock"])
        data = _json_bits(cell, spec["data"])
        q = _json_bits(cell, "Q")
        async_bits = _json_bits(cell, spec["async"])
        if len(clk) != 1 or len(data) != 1 or len(q) != 1:
            continue
        if not _json_async_reset_like(cell, spec) or len(async_bits) != 1:
            continue
        polarity = _json_parameter_bool(cell, spec["async_polarity"])
        async_value = _json_async_value(cell, spec)
        info = {
            "clock": clk[0],
            "data": data[0],
            "q": q[0],
            "control": _json_control_signature(async_bits[0], polarity, backward),
            "async_value": async_value,
        }
        seq[name] = info
        q_driver[q[0]] = name

    stages: set[str] = set()
    parent: dict[str, str] = {}
    changed = True
    while changed:
        changed = False
        for name, item in seq.items():
            if name in stages:
                continue
            reset_value = item["async_value"]
            if (
                len(reset_value) == 1
                and item["data"] in {"0", "1"}
                and item["data"] != reset_value[0]
            ):
                stages.add(name)
                changed = True
                continue
            parent_name = q_driver.get(item["data"])
            parent_item = seq.get(parent_name or "")
            if parent_name not in stages or parent_item is None:
                continue
            if (
                parent_item["clock"] != item["clock"]
                or parent_item["control"] != item["control"]
                or parent_item["async_value"] != item["async_value"]
            ):
                continue
            stages.add(name)
            parent[name] = parent_name
            changed = True

    reset_consumers: set[int | str] = set()
    for cell in cells.values():
        spec = _YOSYS_SEQ_PORTS.get(str(cell.get("type", "")))
        if spec is None:
            continue
        if _json_async_reset_like(cell, spec):
            reset_consumers.update(_json_bits(cell, spec["async"]))
        reset_consumers.update(_json_bits(cell, spec["sync"]))

    endpoints = {
        name
        for name in stages
        if _json_reachable_simple_bits(seq[name]["q"], forward) & reset_consumers
    }
    preserve: set[str] = set()
    for name in endpoints:
        current = name
        while current in stages and current not in preserve:
            preserve.add(current)
            current = parent.get(current, "")
    return tuple(sorted(preserve))


def apply_reset_distribution_preservation(source: Path, destination: Path, top: str) -> tuple[str, ...]:
    """Add Yosys ``keep`` only to structurally recognized reset-release cells."""

    design = json.loads(source.read_text(encoding="utf-8"))
    preserved = reset_distribution_cells(design, top)
    cells = design["modules"][top].get("cells", {})
    for name in preserved:
        attrs = cells[name].setdefault("attributes", {})
        attrs["keep"] = _YOSYS_KEEP_ONE
    destination.write_text(json.dumps(design, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return preserved


def apply_async_sequential_preservation(source: Path, destination: Path, top: str) -> tuple[str, ...]:
    """Fallback: preserve all asynchronously controlled sequential cells.

    This deliberately broad backend-only policy is used only when structural
    reset-distribution recognition returns no cells.  It is conservative for
    optimization, but keeps functional RTL free of synthesis attributes and
    provides a deterministic way to validate reset fanout partitioning.
    """

    design = json.loads(source.read_text(encoding="utf-8"))
    modules = design.get("modules", {})
    if top not in modules:
        raise ValueError(f"top module not found in pre-synthesis JSON: {top}")
    cells = modules[top].get("cells", {})
    async_types = {"$adff", "$adffe", "$aldff", "$aldffe"}
    preserved = tuple(sorted(
        name for name, cell in cells.items()
        if str(cell.get("type", "")) in async_types
    ))
    for name in preserved:
        attrs = cells[name].setdefault("attributes", {})
        attrs["keep"] = _YOSYS_KEEP_ONE
    destination.write_text(json.dumps(design, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return preserved



@dataclass(frozen=True, slots=True)
class ClockGateCell:
    """One positive-edge integrated clock-gating cell described by Liberty."""

    name: str
    clock_pin: str
    enable_pin: str
    output_pin: str
    test_pin: str | None
    tie_lo_pins: tuple[str, ...]
    area: float


def _matching_brace(text: str, start: int) -> int:
    """Return the matching closing brace while ignoring strings and comments."""

    depth = 0
    quote = False
    escape = False
    line_comment = False
    block_comment = False
    i = start
    while i < len(text):
        ch = text[i]
        nxt = text[i + 1] if i + 1 < len(text) else ""
        if line_comment:
            if ch == "\n":
                line_comment = False
            i += 1
            continue
        if block_comment:
            if ch == "*" and nxt == "/":
                block_comment = False
                i += 2
            else:
                i += 1
            continue
        if quote:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                quote = False
            i += 1
            continue
        if ch == "/" and nxt == "/":
            line_comment = True
            i += 2
            continue
        if ch == "/" and nxt == "*":
            block_comment = True
            i += 2
            continue
        if ch == '"':
            quote = True
        elif ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    raise ValueError("unterminated Liberty group")


def _liberty_groups(text: str, keyword: str):
    """Yield ``(name, body)`` for named Liberty groups of one kind."""

    pattern = re.compile(rf"\b{re.escape(keyword)}\s*\(\s*(?:\"([^\"]+)\"|([^\s)]+))\s*\)\s*\{{")
    pos = 0
    while True:
        match = pattern.search(text, pos)
        if match is None:
            return
        brace = text.find("{", match.start())
        end = _matching_brace(text, brace)
        yield (match.group(1) or match.group(2), text[brace + 1:end])
        pos = end + 1


def _liberty_attr(body: str, name: str) -> str | None:
    match = re.search(rf"\b{re.escape(name)}\s*:\s*(?:\"([^\"]*)\"|([^;\s]+))\s*;", body)
    if match is None:
        return None
    return match.group(1) if match.group(1) is not None else match.group(2)


def select_clock_gate_cell(liberty: Path) -> ClockGateCell:
    """Select a positive-edge ICG generically from Liberty metadata.

    The priority mirrors Yosys' native ``clockgate -liberty`` policy used by
    FlexSoC probes: prefer cells requiring fewer auxiliary low ties, then the
    smaller-area implementation.  No PDK cell or pin name is encoded here.
    """

    text = liberty.read_text(encoding="utf-8", errors="replace")
    candidates: list[tuple[tuple[int, float, str], ClockGateCell]] = []
    for cell_name, cell_body in _liberty_groups(text, "cell"):
        kind = (_liberty_attr(cell_body, "clock_gating_integrated_cell") or "").lower()
        if not kind.startswith("latch_posedge"):
            continue
        clock_pin = enable_pin = output_pin = test_pin = None
        input_pins: list[str] = []
        for pin_name, pin_body in _liberty_groups(cell_body, "pin"):
            direction = (_liberty_attr(pin_body, "direction") or "").lower()
            if direction == "input":
                input_pins.append(pin_name)
            if (_liberty_attr(pin_body, "clock_gate_clock_pin") or "").lower() == "true":
                clock_pin = pin_name
            if (_liberty_attr(pin_body, "clock_gate_enable_pin") or "").lower() == "true":
                enable_pin = pin_name
            if (_liberty_attr(pin_body, "clock_gate_out_pin") or "").lower() == "true":
                output_pin = pin_name
            if (_liberty_attr(pin_body, "clock_gate_test_pin") or "").lower() == "true":
                test_pin = pin_name
        if not (clock_pin and enable_pin and output_pin):
            continue
        role_inputs = {clock_pin, enable_pin}
        if test_pin:
            role_inputs.add(test_pin)
        tie_lo = tuple(pin for pin in input_pins if pin not in role_inputs)
        try:
            area = float(_liberty_attr(cell_body, "area") or "inf")
        except ValueError:
            area = float("inf")
        cell = ClockGateCell(
            cell_name, clock_pin, enable_pin, output_pin, test_pin, tie_lo, area,
        )
        # Yosys prefers ICGs needing fewer tied-low auxiliary/test inputs.
        low_ties = len(tie_lo) + (1 if test_pin else 0)
        candidates.append(((low_ties, area, cell_name), cell))
    if not candidates:
        raise ValueError(f"Liberty has no positive-edge integrated clock-gating cell: {liberty}")
    candidates.sort(key=lambda item: item[0])
    return candidates[0][1]


def render_clock_gate_techmap(cell: ClockGateCell) -> str:
    """Map the readable RTL ``prim_clk_gate`` abstraction to one Liberty ICG."""

    connections: list[tuple[str, str]] = [
        (cell.clock_pin, "clk_i"),
        (cell.enable_pin, "en_i" if cell.test_pin else "gate_en"),
        (cell.output_pin, "clk_o"),
    ]
    if cell.test_pin:
        connections.append((cell.test_pin, "test_en_i"))
    connections.extend((pin, "1'b0") for pin in cell.tie_lo_pins)
    lines = [
        '(* techmap_celltype = "prim_clk_gate" *)',
        "module _flexsoc_prim_clk_gate_map (",
        "  input  wire clk_i,",
        "  input  wire en_i,",
        "  input  wire test_en_i,",
        "  output wire clk_o",
        ");",
    ]
    if not cell.test_pin:
        lines += [
            "  wire gate_en;",
            "  assign gate_en = en_i | test_en_i;",
        ]
    lines.append(f"  {cell.name} _TECHMAP_REPLACE_ (")
    for index, (pin, signal) in enumerate(connections):
        comma = "," if index + 1 < len(connections) else ""
        lines.append(f"    .{pin} ({signal}){comma}")
    lines += ["  );", "endmodule", ""]
    return "\n".join(lines)


def _uses_explicit_clock_gate(topdir: Path) -> bool:
    """Return true when generated design RTL explicitly instantiates prim_clk_gate."""

    if not topdir.is_dir():
        return False
    for suffix in ("*.sv", "*.v"):
        for path in topdir.rglob(suffix):
            if path.name == "prim_clk_gate.sv":
                continue
            try:
                if re.search(r"\bprim_clk_gate\b", path.read_text(encoding="utf-8", errors="replace")):
                    return True
            except OSError:
                continue
    return False


def pjoin(*parts: str | Path) -> str:
    """Join path fragments and return a POSIX string for generated scripts."""

    return Path(*parts).as_posix()


def write_text(path: Path, text: str) -> Path:
    """Write UTF-8 text after creating the parent directory."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")
    return path


def _validate_profile(opt: str) -> str:
    """Return a canonical synthesis profile or reject an unknown value."""

    profile = opt.strip().lower()
    if profile not in SYNTHESIS_PROFILES:
        choices = ", ".join(SYNTHESIS_PROFILES)
        raise ValueError(f"TARGET_OPT must be one of: {choices}")
    return profile


def _abc_command_comment(command: str) -> str:
    """Explain one generated ABC command in plain synthesis terms."""

    if command == "strash":
        return "Convert the current logic network to a structurally hashed AIG."
    if command == "dch":
        return "Compute don't-care information so later optimization can simplify more logic."
    if command == "balance":
        return "Balance AIG depth to shorten long Boolean logic chains."
    if command == "rewrite":
        return "Rewrite local AIG cones to reduce logic while preserving function."
    if command == "rewrite -z":
        return "Rewrite again allowing zero-cost moves that can expose later improvements."
    if command == "refactor":
        return "Refactor larger logic cones into alternative equivalent structures."
    if command.startswith("resub -K "):
        return "Resubstitute logic using bounded cuts to remove redundant nodes."
    if command == "map -a":
        return "Map to standard cells with area as the primary optimization objective."
    if command.startswith("map -B "):
        return "Map to standard cells with an explicit delay-weight bias."
    if command.startswith("map -D "):
        return "Map to standard cells against the explicit delay target in picoseconds."
    if command == "topo":
        return "Recompute topological order before timing-driven sizing and buffering."
    if command == "stime -c":
        return "Recompute mapped-network timing using the active library constraints."
    if command.startswith("buffer -c -N "):
        return "Insert timing-aware buffers and cap each buffered branch at the requested fanout."
    if command == "upsize -c":
        return "Upsize timing-critical cells while honoring the active constraints."
    if command.startswith("upsize "):
        return "Upsize timing-critical cells toward the explicit delay target in picoseconds."
    if command == "dnsize -c":
        return "Recover area by downsizing cells while honoring the active constraints."
    if command.startswith("dnsize "):
        return "Recover area while preserving the explicit delay target in picoseconds."
    if command == "stime -p":
        return "Print final mapped timing so the synthesis log records the achieved delay."
    if command == "print_stats -m":
        return "Print final mapped network statistics for area/profile comparison."
    return f"Run ABC command: {command}."


def abc_script(profile: str, clk_ns: float) -> str:
    """Render one self-documenting ABC optimization profile.

    Yosys substitutes ``{D}`` only in its built-in ABC command strings. Custom
    ``-script <file>`` recipes are sourced by ABC as ordinary files, so FlexSoC
    writes the numeric picosecond target directly into delay-oriented commands.
    """

    profile = _validate_profile(profile)
    delay_ps = int(round(clk_ns * 1000.0))
    recipes: dict[str, tuple[str, ...]] = {
        "area0": (
            "strash", "dch", "balance", "rewrite", "refactor", "rewrite -z",
            "balance", "dch", "map -a", "topo", "dnsize -c",
        ),
        "area1": (
            "strash", "dch", "balance", "rewrite", "refactor", "rewrite -z",
            "balance", "rewrite", "refactor", "rewrite -z", "dch",
            "map -a", "topo", "dnsize -c",
        ),
        "area2": (
            "strash", "dch", "balance", "resub -K 6", "rewrite", "refactor",
            "resub -K 8", "rewrite -z", "balance", "dch", "map -a", "topo",
            "buffer -c -N 32", "dnsize -c",
        ),
        "area3": (
            "strash", "dch", "map -B 0.9", "topo", "stime -c",
            "buffer -c -N 24", "upsize -c", "dnsize -c",
        ),
        "delay0": (
            "strash", "balance", "rewrite", "refactor", "rewrite -z", "balance",
            "dch", f"map -D {delay_ps}", "topo", f"upsize {delay_ps}",
        ),
        "delay1": (
            "strash", "dch", "balance", "rewrite", "refactor", "dch",
            f"map -D {delay_ps}", "topo", "buffer -c -N 32",
            f"upsize {delay_ps}", f"dnsize {delay_ps}",
        ),
        "delay2": (
            "strash", "dch", "balance", "rewrite", "refactor", "rewrite -z",
            "balance", "dch", f"map -D {delay_ps}", "topo", "stime -c",
            "buffer -c -N 32", f"upsize {delay_ps}",
        ),
        "delay3": (
            "strash", "dch", "balance", "rewrite", "refactor", "rewrite -z",
            "balance", "rewrite", "refactor", "dch", f"map -D {delay_ps}", "topo",
            "stime -c", "buffer -c -N 24", f"upsize {delay_ps}", f"dnsize {delay_ps}",
        ),
        "delay4": (
            "strash", "dch", "balance", "rewrite", "refactor", "rewrite -z",
            "balance", "rewrite", "refactor", "rewrite -z", "dch",
            f"map -D {delay_ps}", "topo", "stime -c", "buffer -c -N 16",
            f"upsize {delay_ps}",
        ),
    }
    title = profile.upper().replace("AREA", "AREA ").replace("DELAY", "DELAY ")
    lines = [
        f"# {title} ABC profile",
        f"# Clock target: {clk_ns:g} ns ({delay_ps} ps).",
    ]
    for command in (*recipes[profile], "stime -p", "print_stats -m"):
        lines.extend((f"# {_abc_command_comment(command)}", command))
    return "\n".join((*lines, ""))


def _abc_load_ff(liberty: Path, load: float) -> float:
    """Convert an SDC load in Liberty units to ABC femtofarads."""

    match = re.search(
        r'capacitive_load_unit\s*\(\s*([-+0-9.eE]+)\s*,\s*"?([fpn]f)"?\s*\)',
        liberty.read_text(encoding="utf-8", errors="replace"),
        re.IGNORECASE,
    )
    if not match:
        raise ValueError(f"Liberty capacitive_load_unit is missing or unsupported: {liberty}")
    scale = {"ff": 1.0, "pf": 1e3, "nf": 1e6}[match.group(2).lower()]
    return load * float(match.group(1)) * scale


def render_abc_constraints(driving_cell: str = "", load: float = 10.0) -> str:
    """Render the ABC subset derivable from authored SDC I/O intent."""

    lines: list[str] = []
    if driving_cell.strip():
        lines.append(f"set_driving_cell {driving_cell.strip()}")
    lines.append(f"set_load {load:g}")
    return "\n".join(lines) + "\n"


def _abc_script_name(opt: str) -> str:
    """Return the ABC script file name selected by a synthesis profile."""

    return f"{_validate_profile(opt)}.abc"


def _abc_constraint_arg(cfg: SynthesisConfig) -> str:
    """Return the ABC timing-constraint file generated for the active PDK."""

    return f"\n    -constr {pjoin(cfg.output, 'abc.constr')}"


def render_abc_command(cfg: SynthesisConfig, script_name: str) -> str:
    """Render the ABC command for one ASIC synthesis script."""

    if cfg.liberty is None:
        raise ValueError("ASIC synthesis requires a Liberty file.")

    _validate_profile(cfg.opt)
    base = f"abc -keepff -liberty {cfg.liberty.as_posix()}"
    return f"{base} -script {pjoin(cfg.output, script_name)} \\" + _abc_constraint_arg(cfg)


def _asic_tail(cfg: SynthesisConfig, script_name: str) -> list[str]:
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
        "# keep final public identifiers portable across Verilog, SDF and P&R consumers",
        "rename -unescape",
        "check -assert -mapped",
        f"write_rtlil {pjoin(cfg.output, cfg.top + '_clean.il')}",
        "",
        "# Basic stats of std cells and area",
        f"stat -liberty {cfg.liberty.as_posix()}",
        "",
        "# Raw mapped netlist; OpenROAD pre-placement repair publishes the canonical netlist",
        f"write_verilog -nohex -nodec {pjoin(cfg.output, cfg.top + '_synth_raw.v')}",
        f"write_json {pjoin(cfg.output, cfg.top + '_synth_raw.json')}",
        "",
    ]



def render_openroad_syn_repair_tcl(*, slew_margin: int = 10, cap_margin: int = 10) -> str:
    """Render the lightweight OpenROAD post-synthesis electrical repair stage.

    The stage intentionally stops before global placement, CTS and routing.  ORFS
    supplies only a minimal floorplan/OpenDB import so Resizer has technology and
    physical-library context; ``repair_design -pre_placement`` then repairs
    fanout, capacitance and slew on the mapped netlist.
    """

    if not 0 <= slew_margin <= 100 or not 0 <= cap_margin <= 100:
        raise ValueError("OpenROAD synthesis-repair margins must be in [0, 100]")
    return "\n".join([
        "# FlexSoC post-synthesis electrical repair; no placement/CTS/routing",
        "read_liberty $::env(FLEXSOC_REPAIR_LIBERTY)",
        "read_db $::env(FLEXSOC_REPAIR_ODB)",
        "read_sdc $::env(FLEXSOC_REPAIR_SDC)",
        "",
        "puts {=== FLEXSOC BEFORE REPAIR ===}",
        "report_wns",
        "report_tns",
        "",
        f"repair_design -pre_placement -slew_margin {slew_margin} -cap_margin {cap_margin} -verbose",
        "",
        "puts {=== FLEXSOC AFTER REPAIR ===}",
        "report_wns",
        "report_tns",
        "write_verilog $::env(FLEXSOC_REPAIR_OUT)",
        "",
    ])


def yosys_repaired_json(top: str, outdir: Path, liberty: Path) -> str:
    """Render the tiny Yosys import used to publish JSON for the repaired netlist."""

    return "\n".join([
        "# Canonical machine-readable view of the OpenROAD-repaired netlist",
        f"read_liberty -overwrite -setattr liberty_cell -lib {liberty.as_posix()}",
        f"read_verilog {pjoin(outdir, top + '_synth.v')}",
        f"hierarchy -check -top {top}",
        f"write_json {pjoin(outdir, top + '_synth.json')}",
        "",
    ])


def synthesis_repair_report(log: Path, *, top: str, raw: Path, repaired: Path, floorplan: Path, liberty: Path) -> dict[str, object]:
    """Return compact machine-readable evidence from one OpenROAD repair log."""

    text = log.read_text(encoding="utf-8", errors="replace") if log.is_file() else ""
    inserted = re.search(r"Inserted\s+(\d+)\s+buffers in\s+(\d+)\s+nets", text)
    runtime = re.search(r"Runtime:\s*([0-9.]+)s", text)
    wns = re.findall(r"wns max\s+([-+0-9.eE]+)", text)
    tns = re.findall(r"tns max\s+([-+0-9.eE]+)", text)
    return {
        "schema": 1,
        "top": top,
        "classification": "openroad_pre_placement_repair",
        "raw_netlist": str(raw),
        "repaired_netlist": str(repaired),
        "floorplan_db": str(floorplan),
        "repair_liberty": str(liberty),
        "buffers_inserted": int(inserted.group(1)) if inserted else None,
        "nets_repaired": int(inserted.group(2)) if inserted else None,
        "runtime_seconds": float(runtime.group(1)) if runtime else None,
        "wns_before": float(wns[0]) if len(wns) >= 1 else None,
        "wns_after": float(wns[-1]) if len(wns) >= 2 else None,
        "tns_before": float(tns[0]) if len(tns) >= 1 else None,
        "tns_after": float(tns[-1]) if len(tns) >= 2 else None,
    }

def yosys_presynth_asic_verilog(
    top: str,
    topdir: Path,
    liberty: Path,
    outdir: Path,
) -> str:
    """Render the process-lowering prepass used for structural reset analysis."""

    return "\n".join([
        "# pre-synthesis structural snapshot; no optimization",
        f"read_liberty -overwrite -setattr liberty_cell -lib {liberty.as_posix()}",
        f"read_verilog {pjoin(topdir, top + '.v')}",
        f"hierarchy -check -top {top}",
        "proc",
        f"select -module {top}",
        "# flatten only the structural analysis view so hierarchical reset FFs are visible",
        "flatten",
        "check -assert",
        f"write_json -selected {pjoin(outdir, top + '_pre.json')}",
        "select -clear",
        "",
    ])


def yosys_presynth_asic_slang(
    top: str,
    liberty: Path,
    outdir: Path,
    filelists: Sequence[Path] = (Path("rtl_common.f"), Path("rtl_ip.f")),
    *,
    clock_gate_map: Path | None = None,
) -> str:
    """Render the SystemVerilog process-lowering prepass for reset analysis."""

    lines = [
        "# pre-synthesis structural snapshot; no optimization",
        f"read_liberty -overwrite -setattr liberty_cell -lib {liberty.as_posix()}",
        f"read_slang -I {(_repo_root() / 'hw' / 'ips' / 'pkgs').as_posix()} \\",
        "           -I ../hw/ips/prim \\",
        "           -I ../hw/ips/prim_opentitan \\",
        "           -D SYNTHESIS \\",
        "           --ignore-assertions \\",
        *(
            ["           --blackboxed-module prim_clk_gate \\"]
            if clock_gate_map is not None else []
        ),
        *(f"           -f {Path(filelist).resolve().as_posix()} \\" for filelist in filelists),
        f"           --top {top}",
        "",
        f"hierarchy -check -top {top}",
        *(
            [
                "# legalize explicit RTL clock-gating intent before structural snapshot",
                f"techmap -map {clock_gate_map.resolve().as_posix()}",
                "select -assert-count 0 t:prim_clk_gate",
                "select -clear",
            ] if clock_gate_map is not None else []
        ),
        "proc",
        f"select -module {top}",
        "# flatten only the structural analysis view so hierarchical reset FFs are visible",
        "flatten",
        "check -assert",
        f"write_json -selected {pjoin(outdir, top + '_pre.json')}",
        "select -clear",
        "",
    ]
    return _rewrite_hw_ip_include_paths("\n".join(lines))


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
    """Render a Verilog ASIC Yosys script from preserved pre-synthesis JSON."""

    profile = _validate_profile(opt)
    cfg = SynthesisConfig(
        top, topdir, "asic", clk_ns, outdir, liberty,
        sdcdir=sdcdir, opt=profile,
        tie_hi=tie_hi, tie_lo=tie_lo, min_buffer=min_buffer,
    )
    script_name = _abc_script_name(profile)
    lines = [
        "# read target standard cells as library modules for mapped-cell pin directions",
        f"read_liberty -overwrite -setattr liberty_cell -lib {liberty.as_posix()}",
        "# read process-lowered design with backend-only reset preservation attributes",
        f"read_json {pjoin(outdir, top + '_pre_preserved.json')}",
        "# basic synth",
        f"synth -top {top} -noabc",
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
    clock_gate_map: Path | None = None,
) -> str:
    """Render the SystemVerilog ASIC Yosys script from preserved JSON."""

    profile = _validate_profile(opt)
    cfg = SynthesisConfig(
        top, Path("rtl"), "asic", clk_ns, outdir, liberty,
        sdcdir=sdcdir, opt=profile, filelists=tuple(filelists),
        tie_hi=tie_hi, tie_lo=tie_lo, min_buffer=min_buffer,
    )
    script_name = _abc_script_name(profile)
    lines = [
        "# read target standard cells as library modules for mapped-cell pin directions",
        f"read_liberty -overwrite -setattr liberty_cell -lib {liberty.as_posix()}",
        "# read process-lowered design with backend-only reset preservation attributes",
        f"read_json {pjoin(outdir, top + '_pre_preserved.json')}",
        "# basic synth",
        f"synth -top {top} -noabc",
        *_asic_tail(cfg, script_name),
    ]
    return "\n".join(lines)

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
        profile = _validate_profile(cfg.opt)
        written.append(write_text(cfg.output / f"{profile}.abc", abc_script(profile, cfg.clk_period_ns)))
        if cfg.sdc is None or not cfg.sdc.is_file():
            raise FileNotFoundError("ASIC synthesis requires the canonical SDC")
        from flexsoc.backend.signoff.sdc import read_io_environment
        io = read_io_environment(cfg.sdc)
        if io.load is None:
            raise ValueError(f"canonical SDC must define set_load for synthesis: {cfg.sdc}")
        written.append(
            write_text(
                cfg.output / "abc.constr",
                render_abc_constraints(
                    io.driving_cell or "",
                    _abc_load_ff(cfg.liberty, io.load),
                ),
            )
        )
        clock_gate_map: Path | None = None
        if _uses_explicit_clock_gate(cfg.topdir):
            clock_gate_cell = select_clock_gate_cell(cfg.liberty)
            clock_gate_map = write_text(
                cfg.output / "clock_gate_map.v",
                render_clock_gate_techmap(clock_gate_cell),
            )
            written.append(clock_gate_map)
        written.append(write_text(
            cfg.output / "synth_pre.ys",
            yosys_presynth_asic_verilog(cfg.top, cfg.topdir, cfg.liberty, cfg.output),
        ))
        written.append(write_text(
            cfg.output / "synth_pre_sv.ys",
            yosys_presynth_asic_slang(
                cfg.top, cfg.liberty, cfg.output, cfg.filelists, clock_gate_map=clock_gate_map,
            ),
        ))
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
                clock_gate_map=clock_gate_map,
            ),
        ))
        if cfg.platform:
            from flexsoc.backend.impl.impl import render_config
            written.append(write_text(
                cfg.output / "repair_config.mk",
                "# OpenROAD/ORFS floorplan context for post-synthesis electrical repair\n"
                + render_config(
                    cfg.top, cfg.platform, cfg.output / f"{cfg.top}_synth_raw.v", cfg.sdc,
                ),
            ))
            written.append(write_text(
                cfg.output / "repair.tcl", render_openroad_syn_repair_tcl(),
            ))
            written.append(write_text(
                cfg.output / "repair_json.ys", yosys_repaired_json(cfg.top, cfg.output, cfg.liberty),
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
        sdc: Path,
        opt: str = "delay1",
        filelists: Sequence[Path] = (Path("rtl_common.f"), Path("rtl_ip.f")),
        tie_hi: tuple[str, str] | None = None,
        tie_lo: tuple[str, str] | None = None,
        min_buffer: tuple[str, str, str] | None = None,
        platform: str | None = None,
    ) -> tuple[Path, ...]:
        """Generate ASIC Yosys/ABC scripts from the canonical authored SDC."""

        cfg = SynthesisConfig(
            top=top,
            topdir=topdir,
            target="asic",
            clk_period_ns=clk_period_ns,
            output=output,
            liberty=liberty,
            sdc=sdc,
            opt=opt,
            filelists=tuple(filelists),
            tie_hi=tie_hi,
            tie_lo=tie_lo,
            min_buffer=min_buffer,
            platform=platform,
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
        opt: str = "delay1",
        yosys: str = "yosys",
        systemverilog: bool = True,
        on: str = "local",
        inputs: Sequence[Path] = (),
        sdc: Path | None = None,
        repair_liberty: Path | None = None,
        platform: str | None = None,
        orfs_makefile: Path | None = None,
        openroad: str = "openroad",
    ) -> int:
        """Run mapped ASIC synthesis and publish an electrically repaired netlist.

        Yosys owns logical synthesis.  A minimal ORFS floorplan is then created
        only to supply OpenDB technology context; OpenROAD Resizer runs
        ``repair_design -pre_placement`` and publishes the canonical
        ``<top>_synth.v``.  Global placement, CTS, routing and extraction are not
        part of this stage.
        """

        pre_script = output / ("synth_pre_sv.ys" if systemverilog else "synth_pre.ys")
        script = output / ("synth_sv.ys" if systemverilog else "synth.ys")
        repair_tcl = output / "repair.tcl"
        repair_json_script = output / "repair_json.ys"
        repair_config = output / "repair_config.mk"
        for required in (pre_script, script, repair_tcl, repair_json_script, repair_config):
            if not required.is_file():
                raise FileNotFoundError(f"missing synthesis collateral: {required}")
        if sdc is None or repair_liberty is None or platform is None or orfs_makefile is None:
            raise ValueError("ASIC synthesis repair requires SDC, slow Liberty, ORFS platform and Makefile")

        support = tuple(
            _repo_root() / "hw" / "ips" / name
            for name in ("pkgs", "prim", "prim_opentitan", "tlul")
        ) if systemverilog else ()

        pre_json = output / f"{top}_pre.json"
        preserved_json = output / f"{top}_pre_preserved.json"
        preserve_report = output / f"{top}_reset_preserve.json"
        pre_log = log_dir / f"{top}_synth_pre.log"
        rc = self.run_script(
            pre_script, log=pre_log, yosys=yosys, on=on, sv=systemverilog,
            inputs=(*inputs, *support), outputs=(pre_json,),
        )
        if rc != 0:
            return rc

        preserved = apply_reset_distribution_preservation(pre_json, preserved_json, top)
        preservation_class = "structural_reset_distribution"
        if not preserved:
            preserved = apply_async_sequential_preservation(pre_json, preserved_json, top)
            preservation_class = "async_sequential_fallback"
        preserve_report.write_text(
            json.dumps(
                {
                    "schema": 1,
                    "top": top,
                    "classification": preservation_class,
                    "preserved_cells": list(preserved),
                    "count": len(preserved),
                },
                indent=2,
                sort_keys=True,
            ) + "\n",
            encoding="utf-8",
        )

        log = log_dir / f"{top}_synth_opt_{opt}.log"
        raw_netlist = output / f"{top}_synth_raw.v"
        raw_json = output / f"{top}_synth_raw.json"
        raw_artifacts = tuple(output / f"{top}{suffix}" for suffix in (
            "_generic.il", "_dffmap.il", "_abc.il", "_clean.il",
        )) + (raw_netlist, raw_json)
        rc = self.run_script(
            script, log=log, yosys=yosys, on=on, sv=systemverilog,
            inputs=(*inputs, *support, pre_json, preserved_json, preserve_report),
            outputs=(*raw_artifacts, preserve_report),
        )
        if rc != 0:
            return rc

        from flexsoc.backend.core.execution import CommandRequest
        from flexsoc.backend.core.toolchain import orfs_environment
        from flexsoc.backend.impl.impl import orfs_make_argv

        repair_work = output / "repair_work"
        if repair_work.exists():
            shutil.rmtree(repair_work)
        repair_work.mkdir(parents=True, exist_ok=True)
        floorplan = repair_work / "results" / platform / top / "base" / "2_1_floorplan.odb"
        floorplan_log = log_dir / f"{top}_synth_repair_floorplan.log"
        floorplan_request = CommandRequest(
            orfs_make_argv(
                makefile=orfs_makefile, config=repair_config, workdir=repair_work,
                targets=("2_1_floorplan",),
            ),
            repair_work.resolve(),
            orfs_environment(),
            floorplan_log.resolve(),
            inputs=(orfs_makefile.resolve(), repair_config.resolve(), raw_netlist.resolve(), sdc.resolve()),
            outputs=(floorplan.resolve(),),
        )
        rc = self.runner.run(floorplan_request, on=on).returncode
        if rc != 0:
            return rc

        repaired = output / f"{top}_synth.v"
        repair_log = log_dir / f"{top}_synth_repair.log"
        repair_base_env = orfs_environment()
        openroad_exe = repair_base_env.get("OPENROAD_EXE", openroad)
        repair_env = {
            **repair_base_env,
            "FLEXSOC_REPAIR_LIBERTY": str(repair_liberty.resolve()),
            "FLEXSOC_REPAIR_ODB": str(floorplan.resolve()),
            "FLEXSOC_REPAIR_SDC": str(sdc.resolve()),
            "FLEXSOC_REPAIR_OUT": str(repaired.resolve()),
        }
        repair_request = CommandRequest(
            (openroad_exe, "-exit", str(repair_tcl.resolve())),
            output.resolve(),
            repair_env,
            repair_log.resolve(),
            inputs=(repair_tcl.resolve(), floorplan.resolve(), repair_liberty.resolve(), sdc.resolve()),
            outputs=(repaired.resolve(),),
        )
        rc = self.runner.run(repair_request, on=on).returncode
        if rc != 0:
            return rc

        repair_report = output / f"{top}_synth_repair.json"
        repair_report.write_text(
            json.dumps(
                synthesis_repair_report(
                    repair_log, top=top, raw=raw_netlist, repaired=repaired,
                    floorplan=floorplan, liberty=repair_liberty,
                ),
                indent=2,
                sort_keys=True,
            ) + "\n",
            encoding="utf-8",
        )

        canonical_json = output / f"{top}_synth.json"
        json_log = log_dir / f"{top}_synth_repair_json.log"
        rc = self.run_script(
            repair_json_script, log=json_log, yosys=yosys, on=on, sv=True,
            inputs=(repaired, repair_liberty), outputs=(canonical_json,),
        )
        if rc != 0:
            return rc
        return 0

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
