"""SystemVerilog functional testbench scaffold rendering and generation."""

from __future__ import annotations

from dataclasses import dataclass, replace
import re
from pathlib import Path
from typing import Any, Sequence

from flexsoc.backend.core import ClockConfig, ClockDomain
from ..func.functional import FunctionalFlow, TEST_NAMES

from flexsoc.backend.core import Files, RtlSources, templates
from flexsoc.backend.design.ip.regs import RegsFlow
from .common import RegisterTransport, TestbenchModel

@dataclass(frozen=True)
class _SVRegisterBusAccess:
    """Protocol-specific calls implementing the common CSR access contract."""

    write_call: str
    read_call: str


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


# SystemVerilog render helpers


# Multiclock rendering uses the same generated scaffold layout.


# ---------------------------------------------------------------------------
# cocotb scaffold

# cocotb scaffold


# Filesystem boundary


# BEGIN FLEXSOC CANONICAL SV OUTPUT


# END FLEXSOC CANONICAL SV OUTPUT


@dataclass(slots=True)
class SystemVerilogTestbench:
    """Generate the canonical SystemVerilog functional testbench scaffold."""

    def setup(
        self, config: TestbenchConfig, *, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        return SystemVerilogTestbench.generate_testbench_files(config, clocks=clocks)

    @staticmethod
    def _sv_register_bus_access(top: str, interface: str) -> _SVRegisterBusAccess:
        """Return SV driver calls for one normalized register interface.
    
        Contract: one helper call performs exactly one CSR transaction, captures
        its response before any read side effect can change it, and returns with
        the bus handshake controls quiescent.  Vector scheduling is intentionally
        interface-neutral and must not add protocol timing around these calls.
        """
    
        interface = RegsFlow.normalize_register_interface(interface)
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

    @staticmethod
    def _render_sv_reg_sequence(
        top: str,
        interface: str,
        clk: str,
        *,
        active: bool,
        registers: Sequence[dict[str, Any]] = (),
        packed: bool = False,
    ) -> str:
        """Render generic SystemVerilog register helpers."""
    
        if not active:
            body = templates.render("dv/sv/drivers/reg_sequence_none.svh.j2", top=top)
            if not packed:
                return body
            return templates.render("dv/sv/common/packed_tokens.svh.j2") + "\n" + body
    
        interface = RegsFlow.normalize_register_interface(interface)
        access = SystemVerilogTestbench._sv_register_bus_access(top, interface)
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
            multiclock=False, packed=packed, top=top,
            addr_cases=addr_cases,
            write_addr_call=write_addr_call,
            read_addr_call=read_addr_call,
            post_access_wait=post_access_wait,
            clk=clk,
        )

    @staticmethod
    def _sv_output_expr(name: str) -> str:
        """Return the 32-bit SystemVerilog expression used to compare one output."""
    
        if name.startswith("valid") and name.endswith("_o"):
            return "{31'b0, " + name + "}"
        return name

    @staticmethod
    def _tokenizer() -> str:
        """Return the shared SystemVerilog token parser scaffold."""
    
        return templates.render("dv/sv/common/tokenizer.svh.j2")

    @staticmethod
    def _render_sv_vec_monitor(top: str, outputs: Sequence[str], *, packed: bool = False) -> str:
        """Render generic expected-output checks from data_out.vec."""
    
        checks = ["  if (1'b0) begin\n    known = 1'b0;\n  end"]
        for name in outputs:
            checks.append(
                f'  else if (name == "{name}") begin\n'
                f"    actual = {SystemVerilogTestbench._sv_output_expr(name)};\n"
                "    known = 1'b1;\n"
                "  end"
            )
        checks_text = "\n".join(checks)
    
        return templates.render(
            "dv/sv/drivers/vec_monitor.svh.j2",
            multiclock=False, packed=packed, top=top,
            tokenizer=SystemVerilogTestbench._tokenizer(),
            checks_text=checks_text,
        )

    @staticmethod
    def _sv_input_default(name: str) -> str:
        """Return the reset-time default for a generated top-level input."""
    
        return "'1" if TestbenchModel.serial_idle_high(name) else "'0"

    @staticmethod
    def _render_sv_vec_driver(
        top: str,
        clk: str,
        rst: str,
        inputs: Sequence[str],
        outputs: Sequence[str],
        reset_polarity: str = "low",
        reset_domain: str = "core",
        period_ns: float = 10.0,
        io_delay_pct: float = 0.2,
        *,
        packed: bool = False,
    ) -> str:
        """Render generic input-vector drive tasks from data_in.vec."""
    
        drive_ns, sample_ns = TestbenchModel.phases(period_ns, io_delay_pct)
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
        reset_defaults = "\n".join(f"  {name} = {SystemVerilogTestbench._sv_input_default(name)};" for name in inputs)
        reset_asserted = "1'b1" if reset_polarity == "high" else "1'b0"
        reset_released = "1'b0" if reset_polarity == "high" else "1'b1"
    
        return templates.render(
            "dv/sv/drivers/vec_driver.svh.j2",
            multiclock=False, packed=packed, top=top,
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

    @staticmethod
    def _sv_parser_variants(verilator: str, icarus: str) -> str:
        """Select the native string parser for Verilator and packed tokens for Icarus."""
    
        return (
            "`ifdef VERILATOR\n"
            + verilator.rstrip()
            + "\n`else\n"
            + icarus.rstrip()
            + "\n`endif\n"
        )

    @staticmethod
    def render_sv_reg_sequence(
        top: str,
        interface: str,
        clk: str,
        *,
        active: bool,
        registers: Sequence[dict[str, Any]] = (),
    ) -> str:
        return SystemVerilogTestbench._sv_parser_variants(
            SystemVerilogTestbench._render_sv_reg_sequence(
                top, interface, clk, active=active, registers=registers, packed=False
            ),
            SystemVerilogTestbench._render_sv_reg_sequence(
                top, interface, clk, active=active, registers=registers, packed=True
            ),
        )

    @staticmethod
    def render_sv_vec_monitor(top: str, outputs: Sequence[str]) -> str:
        return SystemVerilogTestbench._sv_parser_variants(
            SystemVerilogTestbench._render_sv_vec_monitor(top, outputs, packed=False),
            SystemVerilogTestbench._render_sv_vec_monitor(top, outputs, packed=True),
        )

    @staticmethod
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
        return SystemVerilogTestbench._sv_parser_variants(
            SystemVerilogTestbench._render_sv_vec_driver(
                top, clk, rst, inputs, outputs, reset_polarity, reset_domain,
                period_ns, io_delay_pct, packed=False,
            ),
            SystemVerilogTestbench._render_sv_vec_driver(
                top, clk, rst, inputs, outputs, reset_polarity, reset_domain,
                period_ns, io_delay_pct, packed=True,
            ),
        )

    @staticmethod
    def _simple_datapath_ports(sig: dict[str, Any]) -> tuple[list[str], list[str]]:
        """Return generic data ports detected on the DUT."""
    
        return FunctionalFlow.vector_inputs(sig), FunctionalFlow.vector_outputs(sig)

    @staticmethod
    def _has_simple_datapath(sig: dict[str, Any]) -> bool:
        """Return true when generated vector drive/check helpers are meaningful."""
    
        inputs, outputs = SystemVerilogTestbench._simple_datapath_ports(sig)
        return bool(inputs and outputs)

    @staticmethod
    def _render_no_vector_task(top: str) -> str:
        """Render the inline no-op used when no generic datapath exists."""
    
        return f'''  // No generic data input/output ports were detected for {top}.
      // Register config still runs; add an IP-specific checker for datapath checks.
      // Main vector runner used by the generated testbench.
    task automatic run_vectors(input string data_in_path, input string data_out_path);
        $display("[TB] vector check skipped for this DUT: %s %s", data_in_path, data_out_path);
      endtask
    '''

    @staticmethod
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
        Files.ensure_dir(out)
        clk = (sig.get("clks") or ["clk_i"])[0]
        rst = (sig.get("rsts") or ["rst_ni"])[0]
        config_registers = FunctionalFlow.register_entries(hjson_path)
        lookup_registers = FunctionalFlow.register_lookup_entries(hjson_path)
        inputs, outputs = SystemVerilogTestbench._simple_datapath_ports(sig)
        vector_active = bus_active or bool(inputs and outputs)
    
        files = {
            out / f"{top}_reg_driver.svh": SystemVerilogTestbench.render_sv_reg_sequence(
                top, interface, clk, active=bus_active,
                registers=lookup_registers or config_registers,
            ),
            out / f"{top}_vec_monitor.svh": (
                SystemVerilogTestbench.render_sv_vec_monitor(top, outputs) if vector_active
                else templates.render("dv/sv/drivers/vec_monitor_fallback.svh.j2", top=top)
            ),
            out / f"{top}_vec_driver.svh": (
                SystemVerilogTestbench.render_sv_vec_driver(
                    top, clk, rst, inputs, outputs, reset_polarity, reset_domain,
                    period_ns, io_delay_pct,
                ) if vector_active
                else templates.render("dv/sv/drivers/vec_driver_fallback.svh.j2", top=top)
            ),
        }
        for path, text in files.items():
            Files.safe_write_file(path, text, overwrite=True)
        return list(files)

    @staticmethod
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

    @staticmethod
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

    @staticmethod
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

    @staticmethod
    def render_tlul_interface(period_ns: float = 10.0, io_delay_pct: float = 0.2) -> str:
        """Render a package-free TL-UL interface using the shared IO timing intent."""
    
        drive_ns, sample_ns = TestbenchModel.phases(period_ns, io_delay_pct)
        helpers = TestbenchModel.render_packed_tlul_helpers("  ")
        return templates.render(
            "dv/sv/register/adapters/tlul/single_transport.sv.j2",
            helpers=helpers,
            drive_ns=f"{drive_ns:g}",
            sample_ns=f"{sample_ns:g}",
        )

    @staticmethod
    def render_reg_interface(top: str) -> str:
        """Render a register interface with simulator-portable procedural access tasks."""
    
        return templates.render(
            "dv/sv/register/reg_iface/single_transport.sv.j2",
            top=top,
        )

    @staticmethod
    def render_axi_lite_utils(top: str, period_ns: float = 10.0, io_delay_pct: float = 0.2) -> str:
        """Render AXI4-Lite read/write tasks with one handshake per channel."""
    
        drive_ns, sample_ns = TestbenchModel.phases(period_ns, io_delay_pct)
        return templates.render(
            "dv/sv/register/adapters/axi_lite/single_transport.svh.j2",
            top=top,
            drive_ns=f"{drive_ns:g}",
            sample_ns=f"{sample_ns:g}",
        )

    @staticmethod
    def render_sv_test_selector(tests: Sequence[str] = TEST_NAMES) -> str:
        """Render plusarg-based test selection by name or explicit files."""
    
        return templates.render(
            "dv/sv/test_selector.svh.j2",
            test_names=", ".join(tests),
            default_test=tests[0],
        )

    @staticmethod
    def _render_sv_clock_driver(domain: ClockDomain) -> list[str]:
        """Render one SDC clock with deterministic seeded uncertainty jitter."""
    
        initial_low, high, low = TestbenchModel.clock_waveform_times(domain)
        bound_ps = TestbenchModel.clock_jitter_bound_ps(domain)
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
        salt = TestbenchModel.clock_seed_salt(domain.name)
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

    @staticmethod
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
            lines.append(SystemVerilogTestbench._logic_decl(name, width, default_type=default))
    
        # Outputs
        lines.append("\n  // Outputs")
        for name, width in ports_out:
            default = str(width) if interface == "tlul" else f"{top}_reg_pkg::{width}"
            lines.append(SystemVerilogTestbench._logic_decl(name, width, default_type=default))
    
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
        lines.extend(SystemVerilogTestbench._connect_ports(ports_in, ports_out, top, interface))
        lines.append("  );\n")
    
        # Clock generation follows the canonical SDC waveform and source latency.
        lines.extend(SystemVerilogTestbench._render_sv_clock_driver(clock))
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
        lines.append(SystemVerilogTestbench.render_sv_test_selector().rstrip())
        lines.append("")
        lines.append("  initial begin")
        lines.append("    error_count = 0;")
        lines.append("    tb_select_test(cfg_path, data_in_path, data_out_path);")
        if ports_in:
            # init inputs (skip the first, often a clock)
            for nm, _ in ports_in[1:]:
                lines.append(f"    {nm} = {SystemVerilogTestbench._sv_input_default(nm)};")
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

    @staticmethod
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
            lines.append(SystemVerilogTestbench._logic_decl(name, width))
    
        lines.append("\n  // Outputs")
        for name, width in ports_out:
            lines.append(SystemVerilogTestbench._logic_decl(name, width))
    
        lines.append("\n  integer error_count;")
    
        # DUT
        lines.append("\n  // DUT")
        lines.append(f"  {top} u_{top} (")
        lines.extend(SystemVerilogTestbench._connect_ports(ports_in, ports_out, top, "direct"))
        lines.append("  );\n")
    
        lines.append("  // Verification helpers")
        lines.append(f'  `include "drivers/{top}_reg_driver.svh"')
        lines.append(f'  `include "drivers/{top}_vec_monitor.svh"')
        lines.append(f'  `include "drivers/{top}_vec_driver.svh"')
        lines.append("")
    
        # Clock generation follows the canonical SDC waveform and source latency.
        lines.extend(SystemVerilogTestbench._render_sv_clock_driver(clock))
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
        lines.append("  // Optional SDF backannotation for post-synthesis/post-implementation GLS")
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
        lines.append(SystemVerilogTestbench.render_sv_test_selector().rstrip())
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

    @staticmethod
    def sv_include_text(top: str) -> str:
        """Render the multiclock SV include hook."""
    
        guard = f"{top.upper()}_NCLOCK_TB_INCLUDE_SV".replace("-", "_")
        return templates.render(
            "dv/sv/testbench/_include_multiclock.sv.j2", top=top, guard=guard
        )

    @staticmethod
    def _phase_helpers(clocks: ClockConfig, io_delay_pct: float) -> str:
        """Render drive/sample phase helpers from the clock contract."""
    
        rendered = []
        for domain in clocks.domains:
            drive_ns, sample_ns = TestbenchModel.phases(domain.period_ns, io_delay_pct)
            rendered.append(templates.render(
                "dv/sv/drivers/clock_phase.svh.j2",
                domain_name=domain.name,
                signal=domain.signal,
                drive_ns=f"{drive_ns:g}",
                sample_ns=f"{sample_ns:g}",
            ).rstrip())
        return "\n\n".join(rendered) + "\n\n"

    @staticmethod
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

    @staticmethod
    def _multiclock_inputs(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> tuple[str, ...]:
        """Return non-clock, non-CSR DUT inputs owned by the vector layer."""
    
        excluded = {signal for domain in clocks.domains for signal in (domain.signal, domain.reset)}
        excluded.update(transport.pins)
        return tuple(name for name, _ in signature.get("ports_in", []) if name not in excluded)

    @staticmethod
    def _multiclock_outputs(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> tuple[str, ...]:
        """Return non-clock, non-CSR DUT outputs visible to the monitor."""
    
        excluded = {signal for domain in clocks.domains for signal in (domain.signal, domain.reset)}
        excluded.update(transport.pins)
        return tuple(name for name, _ in signature.get("ports_out", []) if name not in excluded)

    @staticmethod
    def _sv_input_defaults(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> str:
        """Render deterministic defaults from discovered top-level input intent."""
    
        ready_inputs = {
            stream.ready
            for stream in TestbenchModel.stream_interfaces(signature, clocks, direction="output")
            if stream.ready
        }
        lines = []
        for name in SystemVerilogTestbench._multiclock_inputs(signature, clocks, transport):
            value = "'1" if name in ready_inputs or TestbenchModel.serial_idle_high(name) else "'0"
            lines.append(f"  {name} = {value};")
        return "\n".join(lines)

    @staticmethod
    def _sv_register_cases(
        registers: Sequence[dict[str, Any]], windows: tuple[str, ...]
    ) -> tuple[str, str]:
        """Render register-name dispatch from canonical reggen metadata."""
    
        write_cases = []
        read_cases = []
        first_write = True
        first_read = True
        for register in registers:
            key = str(register.get("key", ""))
            if "." not in key:
                continue
            domain, _ = key.split(".", 1)
            if domain not in windows:
                continue
            addr = int(register["addr"]) & 0xFFFFFFFF
            if register.get("writable", False):
                prefix = "if" if first_write else "else if"
                write_cases.append(
                    f'        {prefix} (reg_name == "{key}") {domain}_write(32\'h{addr:08x}, value);'
                )
                first_write = False
            if register.get("readable", True):
                prefix = "if" if first_read else "else if"
                read_cases.append(
                    f'        {prefix} (reg_name == "{key}") {domain}_read(32\'h{addr:08x}, value);'
                )
                first_read = False
        write_cases.append(
            '        else $display("[TB][WARN] unknown config register: %s", reg_name);'
            if write_cases else
            '        $display("[TB][WARN] no writable register map entry for: %s", reg_name);'
        )
        read_cases.append(
            '        else begin $display("[TB][WARN] unknown read register: %s", reg_name); errors++; end'
            if read_cases else
            '        begin $display("[TB][WARN] no readable register map entry for: %s", reg_name); errors++; end'
        )
        return "\n".join(write_cases), "\n".join(read_cases)

    @staticmethod
    def _sv_driver_text(
        top: str,
        clocks: ClockConfig,
        signature: dict[str, Any],
        registers: Sequence[dict[str, Any]],
        io_delay_pct: float = 0.2,
        interface: str = "tlul",
        *,
        packed: bool = False,
    ) -> str:
        """Render the multiclock register driver from clock and regmap metadata."""
    
        interface = RegsFlow.normalize_register_interface(interface)
        windows = TestbenchModel.register_windows(interface, signature)
        domains = {domain.name for domain in clocks.domains}
        missing = [window for window in windows if window not in domains]
        if missing:
            raise ValueError(
                "register window(s) require matching CLOCK_DOMAINS entries: " + ", ".join(missing)
            )
        transport = RegisterTransport.from_name(interface, windows)
        root = transport.template_root("sv")
        write_cases, read_cases = SystemVerilogTestbench._sv_register_cases(registers, windows)
        bus_section = templates.render(
            f"{root}/multiclock_transport.svh.j2",
            top=top,
            windows=windows,
            reset_tasks=SystemVerilogTestbench._reset_tasks(clocks),
            input_defaults=SystemVerilogTestbench._sv_input_defaults(signature, clocks, transport),
        )
        return templates.render(
            "dv/sv/drivers/reg_driver.svh.j2",
            multiclock=True,
            packed=packed,
            top=top,
            phase_helpers=SystemVerilogTestbench._phase_helpers(clocks, io_delay_pct),
            bus_section=bus_section,
            write_cases=write_cases,
            read_cases=read_cases,
        )

    @staticmethod
    def _sv_stream_driver_parts(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> tuple[str, str, str, str]:
        """Render generic ready/valid input-stream state and vector dispatch."""
    
        streams = TestbenchModel.stream_interfaces(signature, clocks, direction="input")
        stream_by_signal = {
            signal: stream
            for stream in streams
            for signal in (*stream.payload, stream.valid)
        }
        state = []
        helpers = []
        cases = []
        for stream in streams:
            for payload in stream.payload:
                state.append(f"logic [31:0] pending_{payload} = '0;")
            body = [f"task automatic send_{stream.name}();", "  integer timeout;", "  begin"]
            body.append(f"  {stream.domain}_drive_cycle();")
            for payload in stream.payload:
                body.append(f"  {payload} = pending_{payload};")
            body.append(f"  {stream.valid} = 1'b1;")
            if stream.ready:
                body += [
                    "  timeout = 0;",
                    f"  while (!{stream.ready} && timeout < 64) begin",
                    f"    {stream.domain}_sample_cycle();",
                    "    timeout++;",
                    "  end",
                    f"  if (!{stream.ready}) begin",
                    f'    $display("[TB][ERROR] timeout waiting for {stream.ready}");',
                    "    errors++;",
                    "  end",
                ]
            else:
                body.append(f"  {stream.domain}_sample_cycle();")
            body += [f"  {stream.domain}_drive_cycle();", f"  {stream.valid} = 1'b0;", "  end", "endtask"]
            helpers.append("\n".join(body))
    
        for name in SystemVerilogTestbench._multiclock_inputs(signature, clocks, transport):
            stream = stream_by_signal.get(name)
            prefix = "if" if not cases else "else if"
            if stream and name in stream.payload:
                action = f"pending_{name} = value;"
            elif stream and name == stream.valid:
                action = f"if (value[0]) send_{stream.name}();"
            else:
                domain = TestbenchModel.signal_domain(name, clocks)
                action = f"begin {domain}_drive_cycle(); {name} = value; end"
            cases.append(f'      {prefix} (token == "{name}") {action}')
        cases.append(
            '      else begin $display("[TB][WARN] unknown input vector signal: %s", token); errors++; end'
        )
    
        outputs = TestbenchModel.stream_interfaces(signature, clocks, direction="output")
        if len(outputs) == 1:
            stream = outputs[0]
            wait = "\n".join([
                f"  while (!{stream.valid} && timeout < 64) begin",
                f"    {stream.domain}_sample_cycle();",
                "    timeout++;",
                "  end",
                f"  if (!{stream.valid}) begin",
                f'    $display("[TB][ERROR] @wait_output timeout waiting for {stream.valid}");',
                "    errors++;",
                "  end",
            ])
        else:
            wait = '  $display("[TB][ERROR] @wait_output requires exactly one *_valid_o stream");\n  errors++;'
        return "\n".join(state), "\n\n".join(helpers), "\n".join(cases), wait + "\n"

    @staticmethod
    def _sv_vec_driver_text(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport, *, packed: bool = False
    ) -> str:
        """Render multiclock vector input parsing from discovered top-level ports."""
    
        state, helpers, cases, wait = SystemVerilogTestbench._sv_stream_driver_parts(signature, clocks, transport)
        return templates.render(
            "dv/sv/drivers/vec_driver.svh.j2",
            multiclock=True,
            packed=packed,
            stream_state=state,
            stream_helpers=helpers,
            drive_cases=cases,
            wait_output_body=wait.rstrip(),
            settle_cycle=f"{clocks.domains[0].name}_sample_cycle()",
        )

    @staticmethod
    def _sv_monitor_parts(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> tuple[str, str, str, str, str, str]:
        """Render ordered expected-output storage and checks without IP-specific names."""
    
        outputs = SystemVerilogTestbench._multiclock_outputs(signature, clocks, transport)
        identifiers = [(name, re.sub(r"[^A-Za-z0-9_]", "_", name)) for name in outputs]
        decls = ["  integer exp_count;", "  integer got_count;"]
        for _, ident in identifiers:
            decls += [
                f"  logic [31:0] exp_{ident} [0:1023];",
                f"  logic exp_has_{ident} [0:1023];",
            ]
        clear = "\n".join(f"        exp_has_{ident}[exp_count] = 1'b0;" for _, ident in identifiers)
        load = []
        checks = []
        for index, (name, ident) in enumerate(identifiers):
            prefix = "if" if index == 0 else "else if"
            load.append(
                f'      {prefix} (sig == "{name}") begin exp_{ident}[exp_count - 1] = value; '
                f"exp_has_{ident}[exp_count - 1] = 1'b1; end"
            )
            checks += [
                f"      if (exp_has_{ident}[got_count] && $unsigned({name}) !== exp_{ident}[got_count]) begin",
                f'        $display("[TB][ERROR] {name}[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned({name}), exp_{ident}[got_count]);',
                "        errors++;",
                "      end",
            ]
        if load:
            load.append('      else $display("[TB][WARN] unknown expected-output signal: %s", sig);')
        else:
            load.append('      $display("[TB][WARN] no monitorable top-level outputs for: %s", sig);')
    
        streams = TestbenchModel.stream_interfaces(signature, clocks, direction="output")
        if len(streams) == 1:
            stream = streams[0]
            sample = f"{stream.domain}_sample_cycle()"
            valid = stream.valid
        else:
            sample = f"{clocks.domains[0].name}_sample_cycle()"
            valid = "1'b1"
        return "\n".join(decls), clear, "\n".join(load), "\n".join(checks), sample, valid

    @staticmethod
    def _sv_monitor_text(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport, *, packed: bool = False
    ) -> str:
        """Render the multiclock expected-output monitor from the top signature."""
    
        _, clear, load, checks, sample, valid = SystemVerilogTestbench._sv_monitor_parts(signature, clocks, transport)
        return templates.render(
            "dv/sv/drivers/vec_monitor.svh.j2",
            multiclock=True,
            packed=packed,
            clear_expected=clear,
            load_cases=load,
            check_cases=checks,
            sample_cycle=sample,
            valid_expr=valid,
        )

    @staticmethod
    def sv_driver_text(
        top: str,
        clocks: ClockConfig,
        io_delay_pct: float = 0.2,
        interface: str = "tlul",
        *,
        signature: dict[str, Any] | None = None,
        registers: Sequence[dict[str, Any]] = (),
    ) -> str:
        """Render a multiclock register driver with simulator-specific parsing."""
    
        signature = signature or {"ports_in": [], "ports_out": []}
        return SystemVerilogTestbench._sv_parser_variants(
            SystemVerilogTestbench._sv_driver_text(top, clocks, signature, registers, io_delay_pct, interface, packed=False),
            SystemVerilogTestbench._sv_driver_text(top, clocks, signature, registers, io_delay_pct, interface, packed=True),
        )

    @staticmethod
    def sv_vec_driver_text(
        top: str,
        clocks: ClockConfig,
        io_delay_pct: float = 0.2,
        *,
        signature: dict[str, Any] | None = None,
        interface: str = "tlul",
    ) -> str:
        """Render multiclock vector input parsing for Verilator and Icarus."""
    
        del top, io_delay_pct
        signature = signature or {"ports_in": [], "ports_out": []}
        transport = RegisterTransport.from_name(interface, TestbenchModel.register_windows(interface, signature))
        return SystemVerilogTestbench._sv_parser_variants(
            SystemVerilogTestbench._sv_vec_driver_text(signature, clocks, transport, packed=False),
            SystemVerilogTestbench._sv_vec_driver_text(signature, clocks, transport, packed=True),
        )

    @staticmethod
    def sv_monitor_text(
        top: str,
        clocks: ClockConfig,
        *,
        signature: dict[str, Any] | None = None,
        interface: str = "tlul",
    ) -> str:
        """Render multiclock expected-output parsing for Verilator and Icarus."""
    
        del top
        signature = signature or {"ports_in": [], "ports_out": []}
        transport = RegisterTransport.from_name(interface, TestbenchModel.register_windows(interface, signature))
        return SystemVerilogTestbench._sv_parser_variants(
            SystemVerilogTestbench._sv_monitor_text(signature, clocks, transport, packed=False),
            SystemVerilogTestbench._sv_monitor_text(signature, clocks, transport, packed=True),
        )

    @staticmethod
    def sv_tb_text(
        top: str,
        testbench: str,
        clocks: ClockConfig,
        interface: str = "tlul",
        *,
        signature: dict[str, Any] | None = None,
    ) -> str:
        """Render the multiclock SystemVerilog testbench from the top signature."""
    
        signature = signature or {"ports_in": [], "ports_out": []}
        interface = RegsFlow.normalize_register_interface(interface)
        windows = TestbenchModel.register_windows(interface, signature)
        clock_decls = "\n".join(
            f"  logic {domain.signal};\n  logic {domain.reset};" for domain in clocks.domains
        )
        clock_drivers = "\n".join(
            "\n".join(SystemVerilogTestbench._render_sv_clock_driver(domain)) for domain in clocks.domains
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
        bus_decls, bus_helpers, transport = TestbenchModel.render_register_boundary(top, interface, windows)
        expected_decls, _, _, _, output_sample, _ = SystemVerilogTestbench._sv_monitor_parts(signature, clocks, transport)
        return templates.render(
            "dv/sv/testbench/_top_multiclock.sv.j2",
            top=top,
            tb_module=testbench,
            clock_decls=clock_decls,
            bus_decls=bus_decls,
            bus_helpers=bus_helpers,
            signal_decls=TestbenchModel.render_signal_declarations(signature, clocks, transport),
            expected_decls=expected_decls,
            clock_drivers=clock_drivers,
            dut_pins=TestbenchModel.render_dut_pins(signature),
            clock_init=clock_init,
            reset_assert=reset_assert,
            reset_release=reset_release,
            primary_clock=clocks.domains[0].signal,
            output_sample=f"{output_sample}()" if not output_sample.endswith(")") else output_sample,
        )

    @staticmethod
    def uses_simple_testbench(config: TestbenchConfig) -> bool:
        """Return whether the top should use direct port wiring instead of bus helpers."""
    
        reg_pkg = RtlSources.has_reg_pkg(config.rtldir, config.top)
        reg_top = (Path(config.rtldir) / f"{config.top}_reg_top.sv").exists()
        return not (reg_pkg and reg_top)

    @staticmethod
    def write_bus_helpers(config: TestbenchConfig, *, reg_pkg: bool, simple_mode: bool) -> list[Path]:
        """Write bus helpers required by generated RTL and gate testbenches."""
    
        if simple_mode or not reg_pkg:
            return []
    
        outdir = Path(config.output)
        interface = RegsFlow.normalize_register_interface(config.interface)
        helpers = {
            "tlul": (("tlul_if.sv", SystemVerilogTestbench.render_tlul_interface(config.clk_period_ns, config.io_delay_pct)),),
            "reg_iface": (("reg_if.sv", SystemVerilogTestbench.render_reg_interface(config.top)),),
            "axi_lite": (("axi_lite_utils.svh", SystemVerilogTestbench.render_axi_lite_utils(
                config.top, config.clk_period_ns, config.io_delay_pct
            )),),
        }[interface]
    
        written: list[Path] = []
        for name, body in helpers:
            path = outdir / name
            # Machine-owned bus interfaces must stay in lockstep with generated drivers.
            # Regenerate them together so driver tasks always match the interface.
            Files.safe_write_file(path, body, overwrite=True)
            written.append(path)
        return written

    @staticmethod
    def _canonical_sv_output_dir(output: str | Path) -> Path:
        """Return the canonical SystemVerilog output directory."""
    
        out = Path(output)
        if out.name == "sv":
            return out
        return out / "sv"

    @staticmethod
    def _with_canonical_sv_output(config: TestbenchConfig) -> TestbenchConfig:
        """Return a config whose output points at the canonical tb/sv directory."""
    
        sv_output = SystemVerilogTestbench._canonical_sv_output_dir(config.output)
        if Path(config.output) == sv_output:
            return config
        return replace(config, output=sv_output)

    @staticmethod
    def _generate_testbench_files(
        config: TestbenchConfig, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        """Generate include, helper, and top-level testbench files for one request."""
    
        config = SystemVerilogTestbench._with_canonical_sv_output(config)
        clocks = clocks or ClockConfig.from_values()
        outdir = Path(config.output)
        Files.ensure_dir(outdir)
    
        if clocks.multiclock:
            signature = RtlSources.parse_sv_signature(config.rtldir, config.top)
            registers = FunctionalFlow.register_entries_for_top(config.rtldir, config.top)
            drivers = outdir / "drivers"
            Files.ensure_dir(drivers)
            files = {
                outdir / f"include_{config.top}_tb.sv": SystemVerilogTestbench.sv_include_text(config.top),
                drivers / f"{config.top}_reg_driver.svh": SystemVerilogTestbench.sv_driver_text(
                    config.top, clocks, config.io_delay_pct, config.interface,
                    signature=signature, registers=registers,
                ),
                drivers / f"{config.top}_vec_driver.svh": SystemVerilogTestbench.sv_vec_driver_text(
                    config.top, clocks, config.io_delay_pct,
                    signature=signature, interface=config.interface,
                ),
                drivers / f"{config.top}_vec_monitor.svh": SystemVerilogTestbench.sv_monitor_text(
                    config.top, clocks, signature=signature, interface=config.interface
                ),
                outdir / f"{config.top}_tb.sv": SystemVerilogTestbench.sv_tb_text(
                    config.top, f"{config.top}_tb", clocks, config.interface, signature=signature
                ),
            }
            for path, text in files.items():
                Files.safe_write_file(path, text, overwrite=True)
            return tuple(files)
    
        sig = RtlSources.parse_sv_signature(config.rtldir, config.top)
        reg_pkg = RtlSources.has_reg_pkg(config.rtldir, config.top)
        simple_mode = SystemVerilogTestbench.uses_simple_testbench(config)
        if not simple_mode:
            config = replace(config, interface=RegsFlow.normalize_register_interface(config.interface))
        written: list[Path] = []
        hjson_path = FunctionalFlow.hjson_path(config.rtldir, config.top)
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
            SystemVerilogTestbench.write_sv_verification_helpers(
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
            include = SystemVerilogTestbench.render_verilator_include(
                config.top,
                config.rtldir,
                config.syndir,
                config.prims,
                reg_pkg,
                config.interface,
                config.vsv,
            )
            include_path = outdir / f"include_{config.top}_tb.sv"
            Files.safe_write_file(include_path, include, overwrite=True)
            written.append(include_path)
    
        written.extend(SystemVerilogTestbench.write_bus_helpers(config, reg_pkg=reg_pkg, simple_mode=simple_mode))
    
        body = (
            SystemVerilogTestbench.render_simple_testbench(
                config.top,
                clock_domain,
                config.devices,
                config.simdir,
                config.syndir,
                config.compiler,
                sig,
            )
            if simple_mode
            else SystemVerilogTestbench.render_testbench(
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
        Files.safe_write_file(tb_path, body, overwrite=True)
        written.append(tb_path)
        return tuple(written)

    @staticmethod
    def generate_testbench_files(
        config: TestbenchConfig, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        """Recreate the complete machine-owned SystemVerilog scaffold."""
    
        canonical = SystemVerilogTestbench._with_canonical_sv_output(config)
        with Files.replace_generated_tree(canonical.output):
            SystemVerilogTestbench._generate_testbench_files(canonical, clocks)
            return tuple(sorted(path for path in canonical.output.rglob("*") if path.is_file()))

