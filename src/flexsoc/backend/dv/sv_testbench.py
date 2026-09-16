"""SystemVerilog functional testbench scaffold rendering and generation."""

from __future__ import annotations

import re
from dataclasses import dataclass, replace
from pathlib import Path
from textwrap import dedent
from typing import Any, Sequence

from flexsoc.backend.core import ClockConfig, ClockDomain, clock_config
from .functional import (
    TEST_NAMES, _candidate_hjson_path, _register_entries, _register_lookup_entries,
    _vector_inputs, _vector_outputs,
)

from flexsoc.backend.core import (
    ensure_dir,
    has_reg_pkg,
    parse_sv_signature,
    replace_generated_tree,
    safe_write_file,
    templates,
)
from flexsoc.backend.design.regs import normalize_register_interface
from .testbench_common import (
    _clock_jitter_bound_ps,
    _clock_seed_salt,
    _clock_waveform_times,
    _serial_idle_high,
    _tb_phases,
    RegisterTransport,
    render_dut_pins,
    render_packed_tlul_helpers,
    render_register_boundary,
)

@dataclass(frozen=True)
class _SVRegisterBusAccess:
    """Protocol-specific calls implementing the common CSR access contract."""

    write_call: str
    read_call: str


def _sv_register_bus_access(top: str, interface: str) -> _SVRegisterBusAccess:
    """Return SV driver calls for one normalized register interface.

    Contract: one helper call performs exactly one CSR transaction, captures
    its response before any read side effect can change it, and returns with
    the bus handshake controls quiescent.  Vector scheduling is intentionally
    interface-neutral and must not add protocol timing around these calls.
    """

    interface = normalize_register_interface(interface)
    if interface == "tlul":
        return _SVRegisterBusAccess(
            write_call="tl_if.tlul_write(addr[31:0], data, 8'h00, mask[3:0]);",
            read_call="tl_if.tlul_read(addr[31:0], data, 8'h00);",
        )
    if interface == "axi_lite":
        return _SVRegisterBusAccess(
            write_call=(
                f"axi_lite_write(addr[{top}_reg_pkg::AW-1:0], data, "
                f"mask[{top}_reg_pkg::DBW-1:0]);"
            ),
            read_call=f"axi_lite_read(addr[{top}_reg_pkg::AW-1:0], data);",
        )
    if interface == "reg_iface":
        return _SVRegisterBusAccess(
            write_call=(
                f"regif.write(addr[{top}_reg_pkg::AW-1:0], data, "
                f"mask[{top}_reg_pkg::DBW-1:0]);"
            ),
            read_call=f"regif.read(addr[{top}_reg_pkg::AW-1:0], data);",
        )
    raise ValueError(f"unsupported register interface for SV driver: {interface}")



def _render_sv_reg_sequence_string(
    top: str,
    interface: str,
    clk: str,
    *,
    active: bool,
    registers: Sequence[dict[str, Any]] = (),
) -> str:
    """Render generic SystemVerilog register helpers."""

    if not active:
        return templates.render(
            "dv/sv/drivers/reg_sequence_none.svh.j2", top=top
        )

    interface = normalize_register_interface(interface)
    access = _sv_register_bus_access(top, interface)
    write_addr_call = access.write_call
    read_addr_call = access.read_call

    # Register-bus tasks own their complete protocol transaction and must
    # return with request/response handshake controls quiescent.  The vector
    # layer therefore never adds a protocol-independent clock edge here: that
    # would make logical vector timing depend on TL-UL/reg_iface/AXI-Lite
    # latency and can race registered request drivers.
    post_access_wait = ""

    cases: list[str] = []
    seen: set[str] = set()
    for reg in registers:
        addr = int(reg["addr"]) & 0xFFFFFFFF
        names = [
            str(reg.get("key", "")),
            str(reg.get("name", "")),
            str(reg.get("name", "")).upper(),
        ]
        for key in names:
            if not key or key in seen:
                continue
            seen.add(key)
            cases.append(f'    "{key}": begin addr = 32\'h{addr:08x}; found = 1\'b1; end')

    cases.append("    default: begin end")
    addr_cases = "\n".join(cases)

    return templates.render(
        "dv/sv/drivers/reg_driver.svh.j2",
        multiclock=False, top=top,
        addr_cases=addr_cases,
        write_addr_call=write_addr_call,
        read_addr_call=read_addr_call,
        post_access_wait=post_access_wait,
        clk=clk,
    )

def _sv_output_expr(name: str) -> str:
    """Return the 32-bit SystemVerilog expression used to compare one output."""

    if name.startswith("valid") and name.endswith("_o"):
        return "{31'b0, " + name + "}"
    return name


def _tokenizer() -> str:
    """Return the shared SystemVerilog token parser scaffold."""

    return templates.render("dv/sv/common/tokenizer.svh.j2")


def _render_sv_vec_monitor_string(top: str, outputs: Sequence[str]) -> str:
    """Render generic expected-output checks from data_out.vec."""

    checks = ["  if (1'b0) begin\n    known = 1'b0;\n  end"]
    for name in outputs:
        checks.append(
            f'  else if (name == "{name}") begin\n'
            f"    actual = {_sv_output_expr(name)};\n"
            "    known = 1'b1;\n"
            "  end"
        )
    checks_text = "\n".join(checks)

    return templates.render(
        "dv/sv/drivers/vec_monitor.svh.j2",
        multiclock=False, top=top,
        tokenizer=_tokenizer(),
        checks_text=checks_text,
    )




def _sv_input_default(name: str) -> str:
    """Return the reset-time default for a generated top-level input."""

    return "'1" if _serial_idle_high(name) else "'0"


def _render_sv_vec_driver_string(
    top: str,
    clk: str,
    rst: str,
    inputs: Sequence[str],
    outputs: Sequence[str],
    reset_polarity: str = "low",
    reset_domain: str = "core",
    period_ns: float = 10.0,
    io_delay_pct: float = 0.2,
) -> str:
    """Render generic input-vector drive tasks from data_in.vec."""

    drive_ns, sample_ns = _tb_phases(period_ns, io_delay_pct)
    drives = ["  if (1'b0) begin\n    tb_vector_apply_count = tb_vector_apply_count;\n  end"]
    for name in inputs:
        drives.append(
            f'  else if (name == "{name}") begin\n'
            f"    {name} = value;\n"
            "    tb_vector_apply_count++;\n"
            f'    $display("[TB][DRV] {name} <= 0x%08h", value);\n'
            "  end"
        )
    drives_text = "\n".join(drives)
    reset_defaults = "\n".join(f"  {name} = {_sv_input_default(name)};" for name in inputs)
    reset_asserted = "1'b1" if reset_polarity == "high" else "1'b0"
    reset_released = "1'b0" if reset_polarity == "high" else "1'b1"

    return templates.render(
        "dv/sv/drivers/vec_driver.svh.j2",
        multiclock=False, top=top,
        drive_ns=f"{drive_ns:g}",
        sample_ns=f"{sample_ns:g}",
        clk=clk,
        drives_text=drives_text,
        reset_defaults=reset_defaults,
        reset_domain=reset_domain,
        rst=rst,
        reset_asserted=reset_asserted,
        reset_released=reset_released,
    )


# Keep paths as strings, but parse file contents through packed vectors.
# This avoids unreliable automatic-string coercion in older Icarus builds.
_STRING_RENDER_SV_REG_SEQUENCE = _render_sv_reg_sequence_string
_STRING_RENDER_SV_VEC_MONITOR = _render_sv_vec_monitor_string
_STRING_RENDER_SV_VEC_DRIVER = _render_sv_vec_driver_string

def _packed_token_support() -> str:
    """Return packed-token helpers used by older Icarus builds."""

    return templates.render("dv/sv/common/packed_tokens.svh.j2")


def _drop_sv_span(text: str, start: str, end: str) -> str:
    """Drop one generated SV span, retaining the end marker."""

    begin = text.find(start)
    if begin < 0:
        return text
    finish = text.find(end, begin)
    if finish < 0:
        raise RuntimeError(f"cannot locate generated SV marker: {end}")
    return text[:begin] + text[finish:]


def _packed_reg_sequence(text: str) -> str:
    text = _drop_sv_span(
        text,
        "function automatic bit tb_cfg_is_dec_char",
        "function automatic logic [32:0] tb_lookup_reg_addr",
    )
    text = _packed_token_support() + "\n" + text
    text = text.replace(
        "function automatic logic [32:0] tb_parse_cfg_u32(input string raw);",
        "function automatic logic [32:0] tb_parse_cfg_u32(input tb_token_t raw);",
    )
    # The active implementation no longer uses the removed string parser.
    if "function automatic logic [32:0] tb_parse_cfg_u32" not in text:
        anchor = "function automatic logic [32:0] tb_lookup_reg_addr"
        text = text.replace(
            anchor,
            "function automatic logic [32:0] tb_parse_cfg_u32(input tb_token_t raw);\n"
            "  return tb_parse_u32(raw);\n"
            "endfunction\n\n" + anchor,
            1,
        )
    else:
        start = text.find("function automatic logic [32:0] tb_parse_cfg_u32")
        end = text.find("endfunction", start) + len("endfunction")
        text = text[:start] + (
            "function automatic logic [32:0] tb_parse_cfg_u32(input tb_token_t raw);\n"
            "  return tb_parse_u32(raw);\n"
            "endfunction"
        ) + text[end:]

    text = text.replace("input string reg_key", "input tb_token_t reg_key")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    for name in ("t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8",
                 "reg_key", "data_raw", "mask_raw", "wait_raw"):
        text = text.replace(f"  string {name};", f"  tb_token_t {name};")
    text = text.replace("tb_cfg_tokenize9", "tb_tokenize9")
    text = text.replace(
        "    line = \"\";\n    tb_tokenize9(line, code, t0, t1, t2, t3, t4, t5, t6, t7, t8);\n\n",
        "",
    )
    text = text.replace("    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);",
                        "    code = $fgets(line_buf, fd);")
    text = text.replace("tb_tokenize9(line,", "tb_tokenize9(line_buf,")
    text = text.replace('t0.len() > 0 && t0.substr(0, 0) == "#"', "tb_token_comment(t0)")
    text = text.replace('data_raw.len() > 0 && data_raw.substr(0, 0) == "#"', "tb_token_comment(data_raw)")
    text = text.replace('mask_raw.len() > 0 && mask_raw.substr(0, 0) != "#"',
                        "!tb_token_empty(mask_raw) && !tb_token_comment(mask_raw)")
    text = text.replace('wait_raw.len() > 0 && wait_raw.substr(0, 0) != "#"',
                        "!tb_token_empty(wait_raw) && !tb_token_comment(wait_raw)")
    text = text.replace("malformed config write row: %s\", line", "malformed config write row: %0s\", line_buf")
    text = text.replace("malformed config row: %s\", line", "malformed config row: %0s\", line_buf")
    return text


def _sv_parser_variants(verilator: str, icarus: str) -> str:
    """Select the native string parser for Verilator and packed tokens for Icarus."""

    return (
        "`ifdef VERILATOR\n"
        + verilator.rstrip()
        + "\n`else\n"
        + icarus.rstrip()
        + "\n`endif\n"
    )


def render_sv_reg_sequence(
    top: str,
    interface: str,
    clk: str,
    *,
    active: bool,
    registers: Sequence[dict[str, Any]] = (),
) -> str:
    string_parser = _STRING_RENDER_SV_REG_SEQUENCE(
        top, interface, clk, active=active, registers=registers
    )
    return _sv_parser_variants(string_parser, _packed_reg_sequence(string_parser))


def _packed_vec_monitor(text: str) -> str:
    text = _drop_sv_span(
        text,
        "function automatic bit tb_vec_is_dec_char",
        "function automatic logic [32:0] tb_read_output",
    )
    text = text.replace("input string name", "input tb_token_t name")
    text = text.replace("input string raw", "input tb_token_t raw")
    text = text.replace("input string reg_key", "input tb_token_t reg_key")
    text = text.replace("input string expected_raw", "input tb_token_t expected_raw")
    text = text.replace("input string mask_raw", "input tb_token_t mask_raw")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    for name in ("cycle_raw", "first", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"):
        text = text.replace(f"  string {name};", f"  tb_token_t {name};")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace("    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);",
                        "    code = $fgets(line_buf, fd);")
    text = text.replace("tb_tokenize9(line,", "tb_tokenize9(line_buf,")
    text = text.replace(
        "    tb_tokenize9(line_buf, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);\n\n"
        "    line_buf = '0;",
        "    line_buf = '0;",
    )
    text = text.replace('name == ""', "tb_token_empty(name)")
    text = text.replace('mask_raw.len() > 0', "!tb_token_empty(mask_raw)")
    text = text.replace('cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#"',
                        "tb_token_comment(cycle_raw)")
    text = text.replace('first.len() > 0 && first.substr(0, 0) == "#"',
                        "tb_token_comment(first)")
    text = text.replace('t0.len() > 0 && t0.substr(0, 0) == "#"', "tb_token_comment(t0)")
    text = text.replace("malformed @read row: %s\", line", "malformed @read row: %0s\", line_buf")
    return text


def render_sv_vec_monitor(top: str, outputs: Sequence[str]) -> str:
    string_parser = _STRING_RENDER_SV_VEC_MONITOR(top, outputs)
    return _sv_parser_variants(string_parser, _packed_vec_monitor(string_parser))


def _packed_vec_driver(text: str) -> str:
    text = text.replace("input string name", "input tb_token_t name")
    text = text.replace("input string raw", "input tb_token_t raw")
    text = text.replace("input string reg_key", "input tb_token_t reg_key")
    text = text.replace("input string data_raw", "input tb_token_t data_raw")
    text = text.replace("input string mask_raw", "input tb_token_t mask_raw")
    text = text.replace("input string selector", "input tb_token_t selector")
    for name in ("t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"):
        text = text.replace(f"  input string {name}", f"  input tb_token_t {name}")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    for name in (
        "cycle_raw", "reset_selector", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"
    ):
        text = text.replace(f"  string {name};", f"  tb_token_t {name};")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace("    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);",
                        "    code = $fgets(line_buf, fd);")
    text = text.replace("tb_tokenize9(line,", "tb_tokenize9(line_buf,")
    text = text.replace('name == ""', "tb_token_empty(name)")
    text = text.replace('mask_raw.len() > 0', "!tb_token_empty(mask_raw)")
    text = text.replace('cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#"',
                        "tb_token_comment(cycle_raw)")
    text = text.replace('t0.len() > 0 && t0.substr(0, 0) == "#"', "tb_token_comment(t0)")
    text = text.replace("malformed @write row: %s\", line", "malformed @write row: %0s\", line_buf")
    text = text.replace("malformed signal vector row: %s\", line", "malformed signal vector row: %0s\", line_buf")
    return text


def render_sv_vec_driver(
    top: str,
    clk: str,
    rst: str,
    inputs: Sequence[str],
    outputs: Sequence[str],
    reset_polarity: str = "low",
    reset_domain: str = "core",
    period_ns: float = 10.0,
    io_delay_pct: float = 0.2,
) -> str:
    string_parser = _STRING_RENDER_SV_VEC_DRIVER(
        top, clk, rst, inputs, outputs, reset_polarity, reset_domain, period_ns, io_delay_pct
    )
    return _sv_parser_variants(string_parser, _packed_vec_driver(string_parser))

def _simple_datapath_ports(sig: dict[str, Any]) -> tuple[list[str], list[str]]:
    """Return generic data ports detected on the DUT."""

    return _vector_inputs(sig), _vector_outputs(sig)


def _has_simple_datapath(sig: dict[str, Any]) -> bool:
    """Return true when generated vector drive/check helpers are meaningful."""

    inputs, outputs = _simple_datapath_ports(sig)
    return bool(inputs and outputs)


def _render_no_vector_task(top: str) -> str:
    """Render the inline no-op used when no generic datapath exists."""

    return f'''  // No generic data input/output ports were detected for {top}.
  // Register config still runs; add an IP-specific checker for datapath checks.
  // Main vector runner used by the generated testbench.
task automatic run_vectors(input string data_in_path, input string data_out_path);
    $display("[TB] vector check skipped for this DUT: %s %s", data_in_path, data_out_path);
  endtask
'''


def write_sv_verification_helpers(
    outdir: str | Path,
    top: str,
    interface: str,
    sig: dict[str, Any],
    *,
    hjson_path: Path | None = None,
    bus_active: bool,
    force: bool,
    reset_polarity: str = "low",
    reset_domain: str = "core",
    period_ns: float = 10.0,
    io_delay_pct: float = 0.2,
) -> list[Path]:
    """Write the canonical SystemVerilog driver/monitor tree directly."""

    out = Path(outdir) / "drivers"
    ensure_dir(out)
    clk = (sig.get("clks") or ["clk_i"])[0]
    rst = (sig.get("rsts") or ["rst_ni"])[0]
    config_registers = _register_entries(hjson_path)
    lookup_registers = _register_lookup_entries(hjson_path)
    inputs, outputs = _simple_datapath_ports(sig)
    vector_active = bus_active or bool(inputs and outputs)

    files = {
        out / f"{top}_reg_driver.svh": render_sv_reg_sequence(
            top, interface, clk, active=bus_active,
            registers=lookup_registers or config_registers,
        ),
        out / f"{top}_vec_monitor.svh": (
            render_sv_vec_monitor(top, outputs) if vector_active
            else templates.render("dv/sv/drivers/vec_monitor_fallback.svh.j2", top=top)
        ),
        out / f"{top}_vec_driver.svh": (
            render_sv_vec_driver(
                top, clk, rst, inputs, outputs, reset_polarity, reset_domain,
                period_ns, io_delay_pct,
            ) if vector_active
            else templates.render("dv/sv/drivers/vec_driver_fallback.svh.j2", top=top)
        ),
    }
    for path, text in files.items():
        safe_write_file(path, text, overwrite=True)
    return list(files)


@dataclass(frozen=True, slots=True)
class TestbenchConfig:
    """Describe one testbench generation request.

    Paths are accepted as strings or Path objects to keep Make and Python callers simple.
    """

    top: str
    rtldir: str | Path
    simdir: str | Path
    syndir: str | Path
    prims: tuple[str, ...]
    clk_period_ns: int
    compiler: str
    interface: str
    io_delay_pct: float = 0.2
    vsv: str = "sv"
    output: str | Path = "tb"
    devices: tuple[tuple[str, str, str, str], ...] = ()
    force: bool = False


def _logic_decl(name: str, width: Any, *, default_type: str = "logic") -> str:
    """Render a SystemVerilog declaration for a parsed port width."""

    packed_tlul = {
        "tlul_pkg::tl_h2d_t": "[108:0]",
        "tlul_pkg::tl_d2h_t": "[65:0]",
    }
    if width in packed_tlul:
        return f"  logic {packed_tlul[width]} {name};"
    if width == 1 or width == "1":
        return f"  logic {name};"
    if isinstance(width, str) and width.startswith("["):
        return f"  logic {width} {name};"
    if isinstance(width, str) and "::" in width:
        return f"  {width} {name};"
    return f"  {default_type} {name};"


def _connect_ports(ports_in: Sequence[tuple[str, Any]], ports_out: Sequence[tuple[str, Any]], top: str, interface: str) -> list[str]:
    """Return DUT instance pin mappings for generic, TL-UL, or reg-interface wiring."""

    pins: list[str] = []
    for name, _ in ports_in:
        if interface == "tlul" and name == "tl_i":
            pins.append(f"    .{name}(tl_if.h2d)")
        elif interface == "reg_iface" and name == "reg_req_i":
            pins.append(f"    .{name}(regif.req)")
        else:
            pins.append(f"    .{name}({name})")
    for name, _ in ports_out:
        if interface == "tlul" and name == "tl_o":
            pins.append(f"    .{name}(tl_if.d2h)")
        elif interface == "reg_iface" and name == "reg_rsp_o":
            pins.append(f"    .{name}(regif.rsp)")
        else:
            pins.append(f"    .{name}({name})")
    return [line + ("," if index != len(pins) - 1 else "") for index, line in enumerate(pins)]

# SystemVerilog render helpers
def render_verilator_include(top: str, rtldir: str | Path, syndir: str | Path,
                              prims: Sequence[str], flag_reg_pkg: bool,
                              interface: str, vsv: str) -> str:
    """Render the include shim used by Verilator pre/post-synthesis runs."""

    inc: list[str] = []
    inc.append("`ifndef SYN")

    # pkgs: assume +incdir+<ips_root>/pkgs nel comando
    inc.append('  `include "top_pkg.sv"')
    inc.append('  `include "prim_util_pkg.sv"')
    inc.append('  `include "prim_mubi_pkg.sv"')
    inc.append('  `include "prim_secded_pkg.sv"')

    # local rtl: assume +incdir+rtldir nel comando
    if flag_reg_pkg:
        inc.append(f'  `include "{top}_reg_pkg.sv"')

    # TLUL package is compiled through rtl_common.f. Only include the local
    # testbench interface shim here; including tlul_pkg.sv again couples the
    # testbench to a source-tree include path and duplicates package ownership.
    if flag_reg_pkg and interface == "tlul":
        inc.append('  `include "tlul_if.sv"')

    if flag_reg_pkg and interface == "reg_iface":
        inc.append('  `include "reg_if.sv"')

    # DUT source: assume +incdir+rtldir nel comando
    inc.append(f'  `include "{top}.{"sv" if vsv == "sv" else "v"}"')

    inc.append("`else")

    # Native GLS supplies active-PDK models externally. Keep the generated
    # testbench itself technology-independent so RTL regression provenance is
    # stable across PDK switches.

    # synth netlist: includi solo nome, assume +incdir+syndir nel comando
    inc.append(f'  `include "{top}_synth.v"')

    inc.append("`endif")
    return "\n".join(inc) + "\n"



def render_tlul_interface(period_ns: float = 10.0, io_delay_pct: float = 0.2) -> str:
    """Render a package-free TL-UL interface using the shared IO timing intent."""

    drive_ns, sample_ns = _tb_phases(period_ns, io_delay_pct)
    helpers = render_packed_tlul_helpers("  ")
    return templates.render(
        "dv/sv/register/adapters/tlul/single_transport.sv.j2",
        helpers=helpers,
        drive_ns=f"{drive_ns:g}",
        sample_ns=f"{sample_ns:g}",
    )

def render_reg_interface(top: str) -> str:
    """Render a register interface with simulator-portable procedural access tasks."""

    return templates.render(
        "dv/sv/register/reg_iface/single_transport.sv.j2",
        top=top,
    )

def render_axi_lite_utils(top: str, period_ns: float = 10.0, io_delay_pct: float = 0.2) -> str:
    """Render AXI4-Lite read/write tasks with one handshake per channel."""

    drive_ns, sample_ns = _tb_phases(period_ns, io_delay_pct)
    return templates.render(
        "dv/sv/register/adapters/axi_lite/single_transport.svh.j2",
        top=top,
        drive_ns=f"{drive_ns:g}",
        sample_ns=f"{sample_ns:g}",
    )

def render_sv_test_selector(tests: Sequence[str] = TEST_NAMES) -> str:
    """Render plusarg-based test selection by name or explicit files."""

    return templates.render(
        "dv/sv/test_selector.svh.j2",
        test_names=", ".join(tests),
        default_test=tests[0],
    )







def _render_sv_clock_driver(domain: ClockDomain) -> list[str]:
    """Render one SDC clock with deterministic seeded uncertainty jitter."""

    initial_low, high, low = _clock_waveform_times(domain)
    bound_ps = _clock_jitter_bound_ps(domain)
    if bound_ps == 0:
        return [
            "  initial begin",
            f"    {domain.signal} = 1'b0;",
            f"    #{initial_low:g};",
            "    forever begin",
            f"      {domain.signal} = 1'b1;",
            f"      #{high:g};",
            f"      {domain.signal} = 1'b0;",
            f"      #{low:g};",
            "    end",
            "  end",
        ]

    low_ps = int(round(low * 1000.0))
    span = 2 * bound_ps + 1
    salt = _clock_seed_salt(domain.name)
    return [
        "  initial begin",
        "    integer flexsoc_seed;",
        "    integer jitter_prev_ps;",
        "    integer jitter_next_ps;",
        "    real low_delay_ns;",
        "    logic [31:0] jitter_state;",
        f"    {domain.signal} = 1'b0;",
        '    if (!$value$plusargs("FLEXSOC_SEED=%d", flexsoc_seed)) flexsoc_seed = 1;',
        f"    jitter_state = flexsoc_seed ^ 32'h{salt:08x};",
        "    if (jitter_state == 0) jitter_state = 32'h6d2b79f5;",
        "    jitter_prev_ps = 0;",
        f'    $display("[FLEXSOC CLOCK] clock={domain.name} jitter=uniform bound_ps={bound_ps} seed=%0d", flexsoc_seed);',
        f"    #{initial_low:g};",
        "    forever begin",
        f"      {domain.signal} = 1'b1;",
        f"      #{high:g};",
        f"      {domain.signal} = 1'b0;",
        "      jitter_state = jitter_state ^ (jitter_state << 13);",
        "      jitter_state = jitter_state ^ (jitter_state >> 17);",
        "      jitter_state = jitter_state ^ (jitter_state << 5);",
        f"      jitter_next_ps = (jitter_state % {span}) - {bound_ps};",
        f"      low_delay_ns = ({low_ps} + jitter_next_ps - jitter_prev_ps) / 1000.0;",
        '      if (low_delay_ns <= 0.0) $fatal(1, "invalid FlexSoC jittered clock delay");',
        "      #(low_delay_ns);",
        "      jitter_prev_ps = jitter_next_ps;",
        "    end",
        "  end",
    ]


def render_testbench(top: str,
                     clock: ClockDomain,
                     simdir: str | Path,
                     syndir: str | Path,
                     interface: str,
                     compiler: str,
                     vsv: str,
                     sig: dict[str, Any]) -> str:
    """Compose the <top>_tb.sv body using parsed signature info."""
    params: list[tuple[str, str]] = sig["parameters"]
    lparams: list[tuple[str, str]] = sig["localparams"]
    ports_in: list[tuple[str, Any]] = sig["ports_in"]
    ports_out: list[tuple[str, Any]] = sig["ports_out"]
    clks: list[str] = sig["clks"]
    rsts: list[str] = sig["rsts"]

    lines: list[str] = []
    lines.append("// Timescale")
    lines.append("`timescale 1ns/1ps")
    lines.append("// Includes")
    if compiler == "verilator":
        lines.append(f'`include "include_{top}_tb.sv"')
    else:
        # Fallback includes for non-Verilator
        lines.append("`ifndef SYN")
        lines.append(f'  `include "{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{top}_synth.v"')
        lines.append("`endif")
    lines.append("")
    lines.append(f"module {top}_tb;")
    lines.append("  // Parameters")
    lines.append(f"  parameter real CLK_PERIOD = {clock.period_ns:g}; // ns")
    lines.append("  parameter int INITIAL_RESET_CYCLES = 5;")
    for name, val in params:
        lines.append(f"  parameter {name} = {val};")
    for name, val in lparams:
        lines.append(f"  localparam {name} = {val};")

    # Inputs
    lines.append("\n  // Inputs")
    for name, width in ports_in:
        default = str(width) if interface == "tlul" else f"{top}_reg_pkg::{width}"
        lines.append(_logic_decl(name, width, default_type=default))

    # Outputs
    lines.append("\n  // Outputs")
    for name, width in ports_out:
        default = str(width) if interface == "tlul" else f"{top}_reg_pkg::{width}"
        lines.append(_logic_decl(name, width, default_type=default))

    lines.append("\n  integer error_count;")
    # TL-UL is fixed at 32 data bits; reg-interface mode keeps the generated package width.
    lines.append("  logic [31:0] rdata;" if interface == "tlul" else f"  logic [{top}_reg_pkg::DW-1:0] rdata;")

    # TL-UL uses procedural interface tasks in both RTL and gate simulation.
    if interface == "tlul":
        lines.append("  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));")
    elif interface == "reg_iface":
        lines.append("  reg_if regif(.clk_i(clk_i), .rst_ni(rst_ni));")

    lines.append("\n  // Verification helpers")
    if interface == "axi_lite":
        lines.append('  `include "axi_lite_utils.svh"')
    lines.append(f'  `include "drivers/{top}_reg_driver.svh"')
    lines.append(f'  `include "drivers/{top}_vec_monitor.svh"')
    lines.append(f'  `include "drivers/{top}_vec_driver.svh"')

    # DUT instance
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    lines.extend(_connect_ports(ports_in, ports_out, top, interface))
    lines.append("  );\n")

    # Clock generation follows the canonical SDC waveform and source latency.
    lines.extend(_render_sv_clock_driver(clock))
    lines.append("")

    # Wave path is simulator-independent; runtime selects FST or VCD encoding.
    # An empty path means no dump, so never invent a cwd-local filename.
    lines.append("  string wave_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("WAVE=%s", wave_path)) begin')
    lines.append('      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";')
    lines.append("    end")
    lines.append('    if (wave_path != "") begin')
    lines.append('      $display("[TB] dumpfile = %s", wave_path);')
    lines.append("      $dumpfile(wave_path);")
    lines.append(f"      $dumpvars(0, {top}_tb);")
    lines.append("    end")
    lines.append("  end\n")

    # SDF exists only in gate-level builds; RTL simulators never parse it.
    lines.append("  // SDF backannotation")
    lines.append("  `ifdef FLEXSOC_ENABLE_SDF")
    lines.append("    string sdf_path;")
    lines.append("    initial begin")
    lines.append('      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";')
    lines.append('      if (sdf_path != "") begin')
    lines.append('        `ifdef FLEXSOC_SDF_MIN')
    lines.append('          $display("[TB] sdf = %s (MINIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `elsif FLEXSOC_SDF_TYP')
    lines.append('          $display("[TB] sdf = %s (TYPICAL)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `else')
    lines.append('          $display("[TB] sdf = %s (MAXIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `endif')
    lines.append("      end")
    lines.append("    end")
    lines.append("  `endif\n")

    # Stimulus
    lines.append("  string cfg_path;")
    lines.append("  string data_in_path;")
    lines.append("  string data_out_path;")
    lines.append("")
    lines.append(render_sv_test_selector().rstrip())
    lines.append("")
    lines.append("  initial begin")
    lines.append("    error_count = 0;")
    lines.append("    tb_select_test(cfg_path, data_in_path, data_out_path);")
    if ports_in:
        # init inputs (skip the first, often a clock)
        for nm, _ in ports_in[1:]:
            lines.append(f"    {nm} = {_sv_input_default(nm)};")
    if interface == "tlul":
        lines.append("    tl_if.init();")
    elif interface == "reg_iface":
        lines.append("    regif.init();")

    # Every generated test starts from an initialized, race-free reset boundary.
    reset_name = rsts[0] if rsts else (ports_in[1][0] if len(ports_in) > 1 and "rst" in ports_in[1][0] else "")
    if reset_name:
        lines.append(f"    {reset_name} = 1'b1;")
        lines.append(f"    repeat (2) @(posedge {clks[0]});")
        lines.append(f"    @(negedge {clks[0]}); #1;")
        lines.append(f"    {reset_name} = 1'b0;")
        lines.append('    $display("[TB] initial reset pulse cycles=%0d", INITIAL_RESET_CYCLES);')
        lines.append(f"    repeat (INITIAL_RESET_CYCLES) @(posedge {clks[0]});")
        lines.append(f"    @(negedge {clks[0]}); #1;")
        lines.append(f"    {reset_name} = 1'b1;")
        lines.append(f"    repeat (2) @(posedge {clks[0]});")
    else:
        lines.append("    #(CLK_PERIOD*2);")

    lines.append('    $display("\\nRunning...\\n");')

    if interface in {"tlul", "reg_iface", "axi_lite"}:
        lines.append("    #(CLK_PERIOD*10);")
        lines.append("    run_reg_config(cfg_path);")
        lines.append("    run_vectors(data_in_path, data_out_path);")
        lines.append("    #(CLK_PERIOD*10);")

    lines.append("    // INSERT ADDITIONAL TEST-SPECIFIC STIMULUS HERE")
    lines.append("    if (error_count == 0) $display(\"Coverage: 100%%\");")
    lines.append('    $display("\\nEnd.\\n");')
    lines.append('    if (error_count != 0) $fatal(1, "[TB] %0d vector check(s) failed", error_count);')
    lines.append("    $finish;")
    lines.append("  end")
    lines.append("endmodule")
    return "\n".join(lines) + "\n"


def render_simple_testbench(top: str,
                            clock: ClockDomain,
                            devices: Sequence[Sequence[str]],
                            simdir: str | Path,
                            syndir: str | Path,
                            compiler: str,
                            sig: dict[str, Any]) -> str:
    """Minimal TB: only clock(s) and reset(s). No TLUL/Reg IF."""
    params = sig["parameters"]
    lparams = sig["localparams"]
    ports_in = sig["ports_in"]
    ports_out = sig["ports_out"]
    clks = sig["clks"]
    rsts = sig["rsts"]

    lines = []
    lines.append("`timescale 1ns/1ps")
    if compiler == "verilator":
        lines.append(f'`include "include_{top}_tb.sv"')
    else:
        lines.append("`ifndef SYN")
        lines.append(f'  `include "{top}.v"')
        lines.append("`else")
        lines.append(f'  `include "{top}_synth.v"')
        lines.append("`endif")
    lines.append("")
    lines.append(f"module {top}_tb;")
    lines.append(f"  parameter real CLK_PERIOD = {clock.period_ns:g}; // ns")

    for name, val in params:
        lines.append(f"  parameter {name} = {val};")
    for name, val in lparams:
        lines.append(f"  localparam {name} = {val};")

    # Declare ports directly in the testbench scope.
    lines.append("\n  // Inputs")
    for name, width in ports_in:
        lines.append(_logic_decl(name, width))

    lines.append("\n  // Outputs")
    for name, width in ports_out:
        lines.append(_logic_decl(name, width))

    lines.append("\n  integer error_count;")

    # DUT
    lines.append("\n  // DUT")
    lines.append(f"  {top} u_{top} (")
    lines.extend(_connect_ports(ports_in, ports_out, top, "direct"))
    lines.append("  );\n")

    lines.append("  // Verification helpers")
    lines.append(f'  `include "drivers/{top}_reg_driver.svh"')
    lines.append(f'  `include "drivers/{top}_vec_monitor.svh"')
    lines.append(f'  `include "drivers/{top}_vec_driver.svh"')
    lines.append("")

    # Clock generation follows the canonical SDC waveform and source latency.
    lines.extend(_render_sv_clock_driver(clock))
    lines.append("")

    # Runtime-selected FST/VCD path; never fall back to a cwd-local dump.
    lines.append("  string wave_path;")
    lines.append("  initial begin")
    lines.append('    if (!$value$plusargs("WAVE=%s", wave_path)) begin')
    lines.append('      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";')
    lines.append("    end")
    lines.append('    if (wave_path != "") begin')
    lines.append('      $display("[TB] dumpfile = %s", wave_path);')
    lines.append("      $dumpfile(wave_path);")
    lines.append(f"      $dumpvars(0, {top}_tb);")
    lines.append("    end")
    lines.append("  end\n")
    lines.append("  // Optional SDF backannotation for post-synthesis/post-PnR GLS")
    lines.append("  `ifdef FLEXSOC_ENABLE_SDF")
    lines.append("    string sdf_path;")
    lines.append("    initial begin")
    lines.append('      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";')
    lines.append('      if (sdf_path != "") begin')
    lines.append('        `ifdef FLEXSOC_SDF_MIN')
    lines.append('          $display("[TB] sdf = %s (MINIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `elsif FLEXSOC_SDF_TYP')
    lines.append('          $display("[TB] sdf = %s (TYPICAL)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `else')
    lines.append('          $display("[TB] sdf = %s (MAXIMUM)", sdf_path);')
    lines.append(f'          $sdf_annotate(sdf_path, {top}_tb.u_{top});')
    lines.append('        `endif')
    lines.append("      end")
    lines.append("    end")
    lines.append("  `endif\n")
    lines.append("  string cfg_path;")
    lines.append("  string data_in_path;")
    lines.append("  string data_out_path;")
    lines.append("")
    lines.append(render_sv_test_selector().rstrip())
    lines.append("")

    # Simple reset pulse(s)
    lines.append("  initial begin")
    lines.append("    error_count = 0;")
    lines.append("    tb_select_test(cfg_path, data_in_path, data_out_path);")
    # Init inputs to 0
    for nm, _ in ports_in:
        if nm not in clks and nm not in rsts:
            lines.append(f"    {nm} = '0;")
    if rsts:
        for r in rsts:
            lines.append(f"    {r} = 1'b0;")
        lines.append("    #(CLK_PERIOD*2);")
        for r in rsts:
            lines.append(f"    {r} = 1'b1;")
    else:
        lines.append("    #(CLK_PERIOD*2);")
    lines.append("    run_reg_config(cfg_path);")
    lines.append("    run_vectors(data_in_path, data_out_path);")
    lines.append("    #(CLK_PERIOD*10);")
    lines.append('    if (error_count != 0) $fatal(1, "[TB] %0d vector check(s) failed", error_count);')
    lines.append("    $finish;")
    lines.append("  end")
    lines.append("endmodule")
    return "\n".join(lines) + "\n"

# Multiclock rendering uses the same generated scaffold layout.

def sv_include_text(top: str) -> str:
    """Render the multiclock SV include hook."""

    guard = f"{top.upper()}_NCLOCK_TB_INCLUDE_SV".replace("-", "_")
    return templates.render(
        "dv/sv/testbench/_include_multiclock.sv.j2", top=top, guard=guard
    )


def _phase_helpers(clocks: ClockConfig, io_delay_pct: float) -> str:
    """Render drive/sample phase helpers from the clock contract."""

    rendered = []
    for domain in clocks.domains:
        drive_ns, sample_ns = _tb_phases(domain.period_ns, io_delay_pct)
        rendered.append(templates.render(
            "dv/sv/drivers/clock_phase.svh.j2",
            domain_name=domain.name,
            signal=domain.signal,
            drive_ns=f"{drive_ns:g}",
            sample_ns=f"{sample_ns:g}",
        ).rstrip())
    return "\n\n".join(rendered) + "\n\n"


def _reset_tasks(clocks: ClockConfig) -> str:
    """Render reset selection directly from the clock/reset contract."""

    assert_reset = "\n".join(
        f"        {domain.reset} = 1'b{1 if domain.reset_polarity == 'high' else 0};"
        for domain in clocks.domains
    )
    release_reset = "\n".join(
        f"        {domain.reset} = 1'b{0 if domain.reset_polarity == 'high' else 1};"
        for domain in clocks.domains
    )
    wait_all = "\n".join(
        f"          begin repeat (cycles) @(posedge {domain.signal}); "
        f"@(negedge {domain.signal}); end"
        for domain in clocks.domains
    )
    named = []
    for domain in clocks.domains:
        asserted = 1 if domain.reset_polarity == "high" else 0
        released = 0 if domain.reset_polarity == "high" else 1
        named.extend([
            f'else if (selector == "{domain.name}" || selector == "{domain.reset}") begin',
            f"  {domain.reset} = 1'b{asserted};",
            f"  repeat (cycles) @(posedge {domain.signal});",
            f"  @(negedge {domain.signal});",
            f"  {domain.reset} = 1'b{released};",
            "  matched = 1'b1;",
            "end",
        ])
    return templates.render(
        "dv/sv/drivers/reset.svh.j2",
        assert_reset=assert_reset,
        wait_all=wait_all,
        release_reset=release_reset,
        named_reset="\n".join(named),
        primary_clock=clocks.domains[0].signal,
    )


def _sv_driver_text_string(
    top: str, clocks: ClockConfig, io_delay_pct: float = 0.2, interface: str = "tlul"
) -> str:
    """Render the native-string multiclock register driver."""

    interface = normalize_register_interface(interface)
    root = RegisterTransport.from_name(interface).template_root("sv")
    bus_section = templates.render(
        f"{root}/multiclock_transport.svh.j2",
        top=top,
        reset_tasks=_reset_tasks(clocks),
    )
    return templates.render(
        "dv/sv/drivers/reg_driver.svh.j2",
        multiclock=True, top=top,
        phase_helpers=_phase_helpers(clocks, io_delay_pct),
        bus_section=bus_section,
    )


def _sv_vec_driver_text_string(
    top: str, clocks: ClockConfig, io_delay_pct: float = 0.2
) -> str:
    """Render native-string multiclock vector commands."""

    del top, clocks, io_delay_pct
    return templates.render("dv/sv/drivers/vec_driver.svh.j2", multiclock=True)


def _sv_monitor_text_string(top: str) -> str:
    """Render the native-string multiclock output monitor."""

    del top
    return templates.render("dv/sv/drivers/vec_monitor.svh.j2", multiclock=True)


_STRING_SV_DRIVER_TEXT = _sv_driver_text_string
_STRING_SV_VEC_DRIVER_TEXT = _sv_vec_driver_text_string
_STRING_SV_MONITOR_TEXT = _sv_monitor_text_string

def _packed_sv_driver_variant(text: str) -> str:
    """Convert the N-clock register driver parser to packed tokens for Icarus."""

    text = text.replace("input string reg_name", "input tb_token_t reg_name")
    text = text.replace("  string reg_name;", "  tb_token_t reg_name;")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace(
        "          void'($fgets(line_buf, fd));\n          line = $sformatf(\"%0s\", line_buf);\n"
        "          if (line.len() == 0 || line.substr(0, 0) == \"#\") disable tb_nclk_cfg_line;\n"
        "          code = $sscanf(line, \"%s %h\", reg_name, value);",
        "          code = $fgets(line_buf, fd);\n"
        "          code = $sscanf(line_buf, \"%s %h\", reg_name, value);",
    )
    text = text.replace("$sscanf(line,", "$sscanf(line_buf,")
    text = text.replace(
        '            if (reg_name.len() > 6 && reg_name.substr(0, 5) == "clk_i.") reg_name = reg_name.substr(6, reg_name.len() - 1);',
        '            begin\n'
        '              tb_token_t short_name;\n'
        "              short_name = '0;\n"
        '              if ($sscanf(reg_name, "clk_i.%s", short_name) == 1) reg_name = short_name;\n'
        '            end',
    )
    # Add the packed parser after rewriting generated task bodies.
    # Earlier insertion lets broad replacements corrupt the parser argument.
    return _packed_token_support() + "\n" + text


def _packed_sv_driver_text(top: str, clocks: ClockConfig, io_delay_pct: float = 0.2) -> str:
    return _packed_sv_driver_variant(_STRING_SV_DRIVER_TEXT(top, clocks, io_delay_pct))


def _packed_sv_vec_driver_text(top: str, clocks: ClockConfig, io_delay_pct: float = 0.2) -> str:
    text = _STRING_SV_VEC_DRIVER_TEXT(top, clocks, io_delay_pct)
    text = text.replace("  string token;", "  tb_token_t token;")
    text = text.replace("  string reg_name;", "  tb_token_t reg_name;")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace(
        "    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);\n"
        "    if (line.len() == 0 || line.substr(0, 0) == \"#\") disable tb_nclk_input_line;\n"
        "    code = $sscanf(line, \"%d %s\", step, token);",
        "    code = $fgets(line_buf, fd);\n"
        "    code = $sscanf(line_buf, \"%d %s\", step, token);",
    )
    text = text.replace("$sscanf(line,", "$sscanf(line_buf,")
    return text


def _packed_sv_monitor_text(top: str) -> str:
    text = _STRING_SV_MONITOR_TEXT(top)
    text = text.replace("  string sig;", "  tb_token_t sig;")
    text = text.replace("  string line;\n", "")
    text = text.replace("  reg [8*4096-1:0] line_buf;", "  tb_line_t line_buf;")
    text = text.replace("    line = \"\";\n", "")
    text = text.replace(
        "    void'($fgets(line_buf, fd));\n    line = $sformatf(\"%0s\", line_buf);\n"
        "    if (line.len() == 0 || line.substr(0, 0) == \"#\") disable tb_nclk_expected_line;\n"
        "    code = $sscanf(line, \"%d %s %h\", step, sig, value);",
        "    code = $fgets(line_buf, fd);\n"
        "    code = $sscanf(line_buf, \"%d %s %h\", step, sig, value);",
    )
    text = text.replace("$sscanf(line,", "$sscanf(line_buf,")
    return text



def _sv_reg_iface_driver_text(top: str, clocks: ClockConfig, io_delay_pct: float) -> str:
    return _sv_driver_text_string(top, clocks, io_delay_pct, "reg_iface")


def _sv_axi_lite_driver_text(top: str, clocks: ClockConfig, io_delay_pct: float) -> str:
    return _sv_driver_text_string(top, clocks, io_delay_pct, "axi_lite")


def sv_driver_text(
    top: str, clocks: ClockConfig, io_delay_pct: float = 0.2, interface: str = "tlul"
) -> str:
    """Render a multiclock register driver with simulator-specific parsing."""

    interface = normalize_register_interface(interface)
    string = _sv_driver_text_string(top, clocks, io_delay_pct, interface)
    packed = (
        _packed_sv_driver_text(top, clocks, io_delay_pct)
        if interface == "tlul"
        else _packed_sv_driver_variant(string)
    )
    return _sv_parser_variants(string, packed)


def sv_vec_driver_text(top: str, clocks: ClockConfig, io_delay_pct: float = 0.2) -> str:
    """Render multiclock vector input parsing for Verilator and Icarus."""

    return _sv_parser_variants(
        _sv_vec_driver_text_string(top, clocks, io_delay_pct),
        _packed_sv_vec_driver_text(top, clocks, io_delay_pct),
    )


def sv_monitor_text(top: str) -> str:
    """Render multiclock expected-output parsing for Verilator and Icarus."""

    return _sv_parser_variants(_sv_monitor_text_string(top), _packed_sv_monitor_text(top))


def sv_tb_text(
    top: str, testbench: str, clocks: ClockConfig, interface: str = "tlul"
) -> str:
    """Render the multiclock SystemVerilog testbench."""

    interface = normalize_register_interface(interface)
    clock_decls = "\n".join(
        f"  logic {domain.signal};\n  logic {domain.reset};" for domain in clocks.domains
    )
    clock_drivers = "\n".join(
        "\n".join(_render_sv_clock_driver(domain)) for domain in clocks.domains
    )
    clock_init = "\n".join(
        [f"    {domain.signal} = 1'b0;" for domain in clocks.domains]
        + [
            f"    {domain.reset} = 1'b{0 if domain.reset_polarity == 'high' else 1};"
            for domain in clocks.domains
        ]
    )
    reset_assert = "\n".join(
        f"    {domain.reset} = 1'b{1 if domain.reset_polarity == 'high' else 0};"
        for domain in clocks.domains
    )
    reset_release = "\n".join(
        f"    {domain.reset} = 1'b{0 if domain.reset_polarity == 'high' else 1};"
        for domain in clocks.domains
    )
    bus_decls, bus_helpers, transport = render_register_boundary(top, interface)
    return templates.render(
        "dv/sv/testbench/_top_multiclock.sv.j2",
        top=top,
        tb_module=testbench,
        clock_decls=clock_decls,
        bus_decls=bus_decls,
        bus_helpers=bus_helpers,
        clock_drivers=clock_drivers,
        dut_pins=render_dut_pins(clocks, transport),
        clock_init=clock_init,
        reset_assert=reset_assert,
        reset_release=reset_release,
        primary_clock=clocks.domains[0].signal,
    )


# ---------------------------------------------------------------------------
# cocotb scaffold

# cocotb scaffold


def _write_multiclock_testbench(
    top: str, output: Path, clocks: ClockConfig, *,
    io_delay_pct: float = 0.2, interface: str = "tlul",
) -> None:
    """Write the generated N-clock SV testbench and split drivers."""

    drivers = output / "drivers"
    drivers.mkdir(parents=True, exist_ok=True)
    files = {
        output / f"include_{top}_tb.sv": sv_include_text(top),
        drivers / f"{top}_reg_driver.svh": sv_driver_text(top, clocks, io_delay_pct, interface),
        drivers / f"{top}_vec_driver.svh": sv_vec_driver_text(top, clocks, io_delay_pct),
        drivers / f"{top}_vec_monitor.svh": sv_monitor_text(top),
        output / f"{top}_tb.sv": sv_tb_text(top, f"{top}_tb", clocks, interface),
    }
    for path, text in files.items():
        safe_write_file(path, text, overwrite=True)


def _generate_multiclock_testbench_files(
    config: TestbenchConfig, clocks: ClockConfig,
) -> tuple[Path, ...]:
    """Recreate the complete machine-owned N-clock SystemVerilog scaffold."""

    canonical = _with_canonical_sv_output(config)
    output = Path(canonical.output)
    with replace_generated_tree(output):
        _write_multiclock_testbench(
            canonical.top, output, clocks,
            io_delay_pct=canonical.io_delay_pct, interface=canonical.interface,
        )
    return tuple(sorted(path for path in output.rglob("*") if path.is_file()))

# Filesystem boundary


def uses_simple_testbench(config: TestbenchConfig) -> bool:
    """Return whether the top should use direct port wiring instead of bus helpers."""

    reg_pkg = has_reg_pkg(config.rtldir, config.top)
    reg_top = (Path(config.rtldir) / f"{config.top}_reg_top.sv").exists()
    return not (reg_pkg and reg_top)


def write_bus_helpers(config: TestbenchConfig, *, reg_pkg: bool, simple_mode: bool) -> list[Path]:
    """Write bus helpers required by generated RTL and gate testbenches."""

    if simple_mode or not reg_pkg:
        return []

    outdir = Path(config.output)
    interface = normalize_register_interface(config.interface)
    helpers = {
        "tlul": (("tlul_if.sv", render_tlul_interface(config.clk_period_ns, config.io_delay_pct)),),
        "reg_iface": (("reg_if.sv", render_reg_interface(config.top)),),
        "axi_lite": (("axi_lite_utils.svh", render_axi_lite_utils(
            config.top, config.clk_period_ns, config.io_delay_pct
        )),),
    }[interface]

    written: list[Path] = []
    for name, body in helpers:
        path = outdir / name
        # Machine-owned bus interfaces must stay in lockstep with generated drivers.
        # Regenerate them together so driver tasks always match the interface.
        safe_write_file(path, body, overwrite=True)
        written.append(path)
    return written


# BEGIN FLEXSOC CANONICAL SV OUTPUT
def _canonical_sv_output_dir(output: str | Path) -> Path:
    """Return the canonical SystemVerilog output directory."""

    out = Path(output)
    if out.name == "sv":
        return out
    return out / "sv"


def _with_canonical_sv_output(config: TestbenchConfig) -> TestbenchConfig:
    """Return a config whose output points at the canonical tb/sv directory."""

    sv_output = _canonical_sv_output_dir(config.output)
    if Path(config.output) == sv_output:
        return config
    return replace(config, output=sv_output)
# END FLEXSOC CANONICAL SV OUTPUT

def _generate_testbench_files(
    config: TestbenchConfig, clocks: ClockConfig | None = None
) -> tuple[Path, ...]:
    """Generate include, helper, and top-level testbench files for one request."""

    config = _with_canonical_sv_output(config)
    clocks = clocks or clock_config()
    if clocks.multiclock:
        return _generate_multiclock_testbench_files(config, clocks)
    outdir = Path(config.output)
    ensure_dir(outdir)

    sig = parse_sv_signature(config.rtldir, config.top)
    reg_pkg = has_reg_pkg(config.rtldir, config.top)
    simple_mode = uses_simple_testbench(config)
    if not simple_mode:
        config = replace(config, interface=normalize_register_interface(config.interface))
    written: list[Path] = []
    hjson_path = _candidate_hjson_path(config.rtldir, config.top)
    # Model setup owns config.regs/data_in.vec/data_out.vec generation.
    primary_reset = (sig.get("rsts") or ["rst_ni"])[0]
    reset_domain = next(
        (domain for domain in clocks.domains if domain.reset == primary_reset),
        clocks.domains[0],
    )
    clock_domain = next(
        (domain for domain in clocks.domains if domain.signal in (sig.get("clks") or [])),
        reset_domain,
    )
    written.extend(
        write_sv_verification_helpers(
            outdir,
            config.top,
            config.interface,
            sig,
            hjson_path=hjson_path,
            bus_active=(not simple_mode and config.interface in {"tlul", "reg_iface", "axi_lite"}),
            force=True,
            reset_polarity=reset_domain.reset_polarity,
            reset_domain=reset_domain.name,
            period_ns=clock_domain.period_ns,
            io_delay_pct=config.io_delay_pct,
        )
    )

    if config.compiler == "verilator":
        include = render_verilator_include(
            config.top,
            config.rtldir,
            config.syndir,
            config.prims,
            reg_pkg,
            config.interface,
            config.vsv,
        )
        include_path = outdir / f"include_{config.top}_tb.sv"
        safe_write_file(include_path, include, overwrite=True)
        written.append(include_path)

    written.extend(write_bus_helpers(config, reg_pkg=reg_pkg, simple_mode=simple_mode))

    body = (
        render_simple_testbench(
            config.top,
            clock_domain,
            config.devices,
            config.simdir,
            config.syndir,
            config.compiler,
            sig,
        )
        if simple_mode
        else render_testbench(
            config.top,
            clock_domain,
            config.simdir,
            config.syndir,
            config.interface,
            config.compiler,
            config.vsv,
            sig,
        )
    )
    tb_path = outdir / f"{config.top}_tb.sv"
    safe_write_file(tb_path, body, overwrite=True)
    written.append(tb_path)
    return tuple(written)


def generate_testbench_files(
    config: TestbenchConfig, clocks: ClockConfig | None = None
) -> tuple[Path, ...]:
    """Recreate the complete machine-owned SystemVerilog scaffold."""

    canonical = _with_canonical_sv_output(config)
    with replace_generated_tree(canonical.output):
        _generate_testbench_files(canonical, clocks)
        return tuple(sorted(path for path in canonical.output.rglob("*") if path.is_file()))


@dataclass(slots=True)
class SystemVerilogTestbench:
    """Generate the canonical SystemVerilog functional testbench scaffold."""

    def setup(
        self, config: TestbenchConfig, *, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        return generate_testbench_files(config, clocks=clocks)

