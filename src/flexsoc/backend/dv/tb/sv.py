"""SystemVerilog functional testbench generation."""

from __future__ import annotations

from dataclasses import dataclass, replace
import re
from pathlib import Path
from typing import Any, Sequence

from flexsoc.backend.core import ClockConfig, ClockDomain, Files, RtlSources, templates
from flexsoc.backend.design.ip.regs import RegsFlow
from ..func.functional import FunctionalFlow
from .common import RegisterTransport, TestbenchModel


@dataclass(frozen=True, slots=True)
class TestbenchConfig:
    """Configuration for one generated SystemVerilog functional testbench."""

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


@dataclass(slots=True)
class SystemVerilogTestbench:
    """Generate one clock-topology-independent SystemVerilog testbench scaffold."""

    def setup(
        self, config: TestbenchConfig, *, clocks: ClockConfig | None = None
    ) -> tuple[Path, ...]:
        config = self._canonical_config(config)
        clocks = clocks or ClockConfig.from_values()
        with Files.replace_generated_tree(config.output):
            self._write(config, clocks)
            return tuple(sorted(path for path in Path(config.output).rglob("*") if path.is_file()))

    @staticmethod
    def render_include(top: str) -> str:
        """Render the small protocol-independent functional TB include hook."""

        guard = re.sub(r"[^A-Za-z0-9_]", "_", f"FLEXSOC_{top}_TB_SV").upper()
        return templates.render("dv/sv/testbench/include.sv.j2", top=top, guard=guard)

    @staticmethod
    def render_reg_driver(
        top: str,
        clocks: ClockConfig,
        signature: dict[str, Any],
        registers: Sequence[dict[str, Any]],
        interface: str,
        io_delay_pct: float = 0.2,
    ) -> str:
        """Render register access from the discovered windows and clock ownership."""

        transport = TestbenchModel.register_transport(interface, signature, clocks)
        SystemVerilogTestbench._validate_windows(transport, clocks)
        write_cases, read_cases = SystemVerilogTestbench._register_cases(
            registers, transport
        )
        root = transport.template_root("sv")
        bus_section = templates.render(
            f"{root}/transport.svh.j2",
            top=top,
            windows=transport.windows,
            reset_tasks=SystemVerilogTestbench._reset_tasks(clocks),
            input_defaults=SystemVerilogTestbench._input_defaults(
                signature, clocks, transport
            ),
        )
        values = {
            "top": top,
            "phase_helpers": SystemVerilogTestbench._phase_helpers(
                clocks, io_delay_pct
            ),
            "bus_section": bus_section,
            "write_cases": write_cases,
            "read_cases": read_cases,
        }
        packed = (
            templates.render("dv/sv/common/packed_tokens.svh.j2").rstrip()
            + "\n\n"
            + templates.render("dv/sv/drivers/reg_driver.svh.j2", packed=True, **values)
        )
        return SystemVerilogTestbench._parser_variants(
            templates.render("dv/sv/drivers/reg_driver.svh.j2", packed=False, **values),
            packed,
        )

    @staticmethod
    def render_vec_driver(
        top: str,
        clocks: ClockConfig,
        signature: dict[str, Any],
        interface: str,
        io_delay_pct: float = 0.2,
    ) -> str:
        """Render cycle or stream vector semantics behind one generated driver file."""

        transport = TestbenchModel.register_transport(interface, signature, clocks)
        if TestbenchModel.uses_stream_handshake(signature, clocks):
            values = SystemVerilogTestbench._stream_driver_values(
                signature, clocks, transport
            )
            template = "dv/sv/drivers/vec_driver_stream.svh.j2"
        else:
            values = SystemVerilogTestbench._cycle_driver_values(
                top, signature, clocks, transport, io_delay_pct
            )
            template = "dv/sv/drivers/vec_driver_cycle.svh.j2"
        return SystemVerilogTestbench._parser_variants(
            templates.render(template, packed=False, **values),
            templates.render(template, packed=True, **values),
        )

    @staticmethod
    def render_vec_monitor(
        top: str,
        clocks: ClockConfig,
        signature: dict[str, Any],
        interface: str,
    ) -> str:
        """Render the matching cycle or stream output monitor."""

        transport = TestbenchModel.register_transport(interface, signature, clocks)
        if TestbenchModel.uses_stream_handshake(signature, clocks):
            values = SystemVerilogTestbench._stream_monitor_values(
                signature, clocks, transport
            )
            template = "dv/sv/drivers/vec_monitor_stream.svh.j2"
        else:
            values = SystemVerilogTestbench._cycle_monitor_values(
                top, signature, clocks, transport
            )
            template = "dv/sv/drivers/vec_monitor_cycle.svh.j2"
        return SystemVerilogTestbench._parser_variants(
            templates.render(template, packed=False, **values),
            templates.render(template, packed=True, **values),
        )

    @staticmethod
    def render_top(
        top: str,
        clocks: ClockConfig,
        signature: dict[str, Any],
        interface: str,
    ) -> str:
        """Render one testbench top for any supported clock topology."""

        transport = TestbenchModel.register_transport(interface, signature, clocks)
        SystemVerilogTestbench._validate_windows(transport, clocks)
        bus_decls, bus_helpers = TestbenchModel.render_register_boundary(
            top, transport
        )
        expected_decls = ""
        if TestbenchModel.uses_stream_handshake(signature, clocks):
            expected_decls = SystemVerilogTestbench._stream_monitor_parts(
                signature, clocks, transport
            )[0]
        vector_body = "\n".join(
            (
                "    load_config(cfg_path);",
                "    run_vectors(data_in_path, data_out_path);",
                f"    repeat (10) {clocks.domains[0].name}_sample_cycle();",
            )
        )

        clock_decls = "\n".join(
            f"  logic {domain.signal};\n  logic {domain.reset};"
            for domain in clocks.domains
        )
        clock_drivers = "\n".join(
            "\n".join(SystemVerilogTestbench._clock_driver(domain))
            for domain in clocks.domains
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
        return templates.render(
            "dv/sv/testbench/top.sv.j2",
            top=top,
            tb_module=f"{top}_tb",
            clock_decls=clock_decls,
            bus_decls=bus_decls,
            bus_helpers=bus_helpers,
            signal_decls=TestbenchModel.render_signal_declarations(
                signature, clocks, transport
            ),
            expected_decls=expected_decls,
            clock_drivers=clock_drivers,
            dut_pins=TestbenchModel.render_dut_pins(signature),
            clock_init=clock_init,
            reset_assert=reset_assert,
            reset_release=reset_release,
            primary_clock=clocks.domains[0].signal,
            vector_body=vector_body,
        )

    @staticmethod
    def _write(config: TestbenchConfig, clocks: ClockConfig) -> None:
        """Materialize the canonical five-file SystemVerilog scaffold."""

        out = Path(config.output)
        drivers = out / "drivers"
        Files.ensure_dir(drivers)
        signature = RtlSources.parse_sv_signature(config.rtldir, config.top)
        registers = FunctionalFlow.register_entries_for_top(config.rtldir, config.top)
        files = {
            out / f"include_{config.top}_tb.sv": SystemVerilogTestbench.render_include(config.top),
            drivers / f"{config.top}_reg_driver.svh": SystemVerilogTestbench.render_reg_driver(
                config.top,
                clocks,
                signature,
                registers,
                config.interface,
                config.io_delay_pct,
            ),
            drivers / f"{config.top}_vec_driver.svh": SystemVerilogTestbench.render_vec_driver(
                config.top,
                clocks,
                signature,
                config.interface,
                config.io_delay_pct,
            ),
            drivers / f"{config.top}_vec_monitor.svh": SystemVerilogTestbench.render_vec_monitor(
                config.top, clocks, signature, config.interface
            ),
            out / f"{config.top}_tb.sv": SystemVerilogTestbench.render_top(
                config.top, clocks, signature, config.interface
            ),
        }
        for path, body in files.items():
            Files.safe_write_file(path, body.rstrip() + "\n", overwrite=True)

    @staticmethod
    def _canonical_config(config: TestbenchConfig) -> TestbenchConfig:
        out = Path(config.output)
        canonical = out if out.name == "sv" else out / "sv"
        return replace(
            config,
            output=canonical,
            interface=RegsFlow.normalize_register_interface(config.interface),
        )

    @staticmethod
    def _validate_windows(transport: RegisterTransport, clocks: ClockConfig) -> None:
        domains = {domain.name for domain in clocks.domains}
        missing = sorted(
            {window.domain for window in transport.windows if window.domain not in domains}
        )
        if missing:
            raise ValueError(
                "register window(s) require matching CLOCK_DOMAINS entries: "
                + ", ".join(missing)
            )

    @staticmethod
    def _phase_helpers(clocks: ClockConfig, io_delay_pct: float) -> str:
        rendered = []
        for domain in clocks.domains:
            drive_ns, sample_ns = TestbenchModel.phases(
                domain.period_ns, io_delay_pct
            )
            rendered.append(
                templates.render(
                    "dv/sv/drivers/clock_phase.svh.j2",
                    domain_name=domain.name,
                    signal=domain.signal,
                    drive_ns=f"{drive_ns:g}",
                    sample_ns=f"{sample_ns:g}",
                ).rstrip()
            )
        return "\n\n".join(rendered) + "\n\n"

    @staticmethod
    def _reset_tasks(clocks: ClockConfig) -> str:
        assert_reset = "\n".join(
            f"        {d.reset} = 1'b{1 if d.reset_polarity == 'high' else 0};"
            for d in clocks.domains
        )
        release_reset = "\n".join(
            f"        {d.reset} = 1'b{0 if d.reset_polarity == 'high' else 1};"
            for d in clocks.domains
        )
        wait_all = "\n".join(
            f"          begin repeat (cycles) @(posedge {d.signal}); @(negedge {d.signal}); end"
            for d in clocks.domains
        )
        named = []
        for domain in clocks.domains:
            asserted = 1 if domain.reset_polarity == "high" else 0
            released = 0 if domain.reset_polarity == "high" else 1
            named.extend(
                (
                    f'else if (selector == "{domain.name}" || selector == "{domain.reset}") begin',
                    f"  {domain.reset} = 1'b{asserted};",
                    f"  repeat (cycles) @(posedge {domain.signal});",
                    f"  @(negedge {domain.signal});",
                    f"  {domain.reset} = 1'b{released};",
                    "  matched = 1'b1;",
                    "end",
                )
            )
        return templates.render(
            "dv/sv/drivers/reset.svh.j2",
            assert_reset=assert_reset,
            wait_all=wait_all,
            release_reset=release_reset,
            named_reset="\n".join(named),
            primary_clock=clocks.domains[0].signal,
        )

    @staticmethod
    def _non_bus_inputs(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> tuple[str, ...]:
        excluded = {
            signal
            for domain in clocks.domains
            for signal in (domain.signal, domain.reset)
        }
        excluded.update(transport.pins)
        return tuple(
            name for name, _ in signature.get("ports_in", []) if name not in excluded
        )

    @staticmethod
    def _non_bus_outputs(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> tuple[str, ...]:
        excluded = {
            signal
            for domain in clocks.domains
            for signal in (domain.signal, domain.reset)
        }
        excluded.update(transport.pins)
        return tuple(
            name for name, _ in signature.get("ports_out", []) if name not in excluded
        )

    @staticmethod
    def _input_defaults(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> str:
        ready_inputs = {
            stream.ready
            for stream in TestbenchModel.stream_interfaces(
                signature, clocks, direction="output"
            )
            if stream.ready
        }
        lines = []
        for name in SystemVerilogTestbench._non_bus_inputs(
            signature, clocks, transport
        ):
            value = "'1" if name in ready_inputs or TestbenchModel.serial_idle_high(name) else "'0"
            lines.append(f"  {name} = {value};")
        return "\n".join(lines)

    @staticmethod
    def _register_cases(
        registers: Sequence[dict[str, Any]], transport: RegisterTransport
    ) -> tuple[str, str]:
        write_cases: list[str] = []
        read_cases: list[str] = []
        by_name = {window.name: window for window in transport.windows}
        by_domain = {window.domain: window for window in transport.windows}
        only = transport.windows[0] if len(transport.windows) == 1 else None

        for register in registers:
            key = str(register.get("key") or register.get("name") or "")
            clock = str(register.get("clock") or "")
            prefix = key.split(".", 1)[0] if "." in key else ""
            window = by_name.get(prefix) or by_domain.get(clock) or only
            if window is None or not key:
                continue
            addr = int(register["addr"]) & 0xFFFFFFFF
            name = str(register.get("name") or key.rsplit(".", 1)[-1])
            aliases = [f"{window.name}.{name}"]
            if "." in key:
                aliases.insert(0, key)
            if only is not None:
                aliases.extend((key, name))
            condition = " || ".join(
                f'reg_name == "{alias}"' for alias in dict.fromkeys(aliases) if alias
            )
            if register.get("writable", False):
                write_cases.append(
                    f'        {"if" if len(write_cases) == 0 else "else if"} '
                    f'({condition}) {window.name}_write(32\'h{addr:08x}, value);'
                )
            if register.get("readable", True):
                read_cases.append(
                    f'        {"if" if len(read_cases) == 0 else "else if"} '
                    f'({condition}) {window.name}_read(32\'h{addr:08x}, value);'
                )
        write_cases.append(
            '        else $display("[TB][WARN] unknown config register: %s", reg_name);'
            if write_cases
            else '        $display("[TB][WARN] no writable register map entry for: %s", reg_name);'
        )
        read_cases.append(
            '        else begin $display("[TB][WARN] unknown read register: %s", reg_name); errors++; end'
            if read_cases
            else '        begin $display("[TB][WARN] no readable register map entry for: %s", reg_name); errors++; end'
        )
        return "\n".join(write_cases), "\n".join(read_cases)

    @staticmethod
    def _cycle_driver_values(
        top: str,
        signature: dict[str, Any],
        clocks: ClockConfig,
        transport: RegisterTransport,
        io_delay_pct: float,
    ) -> dict[str, str]:
        primary = clocks.domains[0]
        drive_ns, sample_ns = TestbenchModel.phases(primary.period_ns, io_delay_pct)
        drives = ["  if (1'b0) begin\n    tb_vector_apply_count = tb_vector_apply_count;\n  end"]
        for name in SystemVerilogTestbench._non_bus_inputs(
            signature, clocks, transport
        ):
            drives.append(
                f'  else if (name == "{name}") begin\n'
                f"    {name} = value;\n"
                "    tb_vector_apply_count++;\n"
                f'    $display("[TB][DRV] {name} <= 0x%08h", value);\n'
                "  end"
            )
        defaults = "\n".join(
            f"  {name} = "
            + ("'1" if TestbenchModel.serial_idle_high(name) else "'0")
            + ";"
            for name in SystemVerilogTestbench._non_bus_inputs(
                signature, clocks, transport
            )
        )
        return {
            "top": top,
            "drive_ns": f"{drive_ns:g}",
            "sample_ns": f"{sample_ns:g}",
            "clk": primary.signal,
            "drives_text": "\n".join(drives),
            "reset_defaults": defaults,
            "reset_domain": primary.name,
            "rst": primary.reset,
            "reset_asserted": "1'b1" if primary.reset_polarity == "high" else "1'b0",
            "reset_released": "1'b0" if primary.reset_polarity == "high" else "1'b1",
        }

    @staticmethod
    def _cycle_monitor_values(
        top: str,
        signature: dict[str, Any],
        clocks: ClockConfig,
        transport: RegisterTransport,
    ) -> dict[str, str]:
        checks = ["  if (1'b0) begin\n    known = 1'b0;\n  end"]
        for name in SystemVerilogTestbench._non_bus_outputs(
            signature, clocks, transport
        ):
            checks.append(
                f'  else if (name == "{name}") begin\n'
                f"    actual = {name};\n"
                "    known = 1'b1;\n"
                "  end"
            )
        return {
            "top": top,
            "tokenizer": templates.render("dv/sv/common/tokenizer.svh.j2"),
            "checks_text": "\n".join(checks),
        }

    @staticmethod
    def _stream_driver_values(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> dict[str, str]:
        streams = TestbenchModel.stream_interfaces(signature, clocks, direction="input")
        stream_by_signal = {
            signal: stream
            for stream in streams
            for signal in (*stream.payload, stream.valid)
        }
        state: list[str] = []
        helpers: list[str] = []
        cases: list[str] = []
        for stream in streams:
            for payload in stream.payload:
                state.append(f"logic [31:0] pending_{payload} = '0;")
            body = [f"task automatic send_{stream.name}();", "  integer timeout;", "  begin"]
            body.append(f"  {stream.domain}_drive_cycle();")
            for payload in stream.payload:
                body.append(f"  {payload} = pending_{payload};")
            body.append(f"  {stream.valid} = 1'b1;")
            if stream.ready:
                body.extend(
                    (
                        "  timeout = 0;",
                        f"  while (!{stream.ready} && timeout < 64) begin",
                        f"    {stream.domain}_sample_cycle();",
                        "    timeout++;",
                        "  end",
                        f"  if (!{stream.ready}) begin",
                        f'    $display("[TB][ERROR] timeout waiting for {stream.ready}");',
                        "    errors++;",
                        "  end",
                    )
                )
            else:
                body.append(f"  {stream.domain}_sample_cycle();")
            body.extend(
                (
                    f"  {stream.domain}_drive_cycle();",
                    f"  {stream.valid} = 1'b0;",
                    "  end",
                    "endtask",
                )
            )
            helpers.append("\n".join(body))

        for name in SystemVerilogTestbench._non_bus_inputs(
            signature, clocks, transport
        ):
            stream = stream_by_signal.get(name)
            prefix = "if" if not cases else "else if"
            if stream and name in stream.payload:
                action = f"pending_{name} = value;"
            elif stream and name == stream.valid:
                action = f"if (value[0]) send_{stream.name}();"
            else:
                domain = TestbenchModel.signal_domain(name, clocks)
                action = f"{domain}_drive_cycle(); {name} = value;"
            cases.append(f'      {prefix} (token == "{name}") begin {action} end')
        cases.append(
            '      else begin $display("[TB][WARN] unknown input vector signal: %s", token); errors++; end'
        )

        outputs = TestbenchModel.stream_interfaces(signature, clocks, direction="output")
        if len(outputs) == 1:
            stream = outputs[0]
            wait = "\n".join(
                (
                    f"  while (!{stream.valid} && timeout < 64) begin",
                    f"    {stream.domain}_sample_cycle();",
                    "    timeout++;",
                    "  end",
                    f"  if (!{stream.valid}) begin",
                    f'    $display("[TB][ERROR] @wait_output timeout waiting for {stream.valid}");',
                    "    errors++;",
                    "  end",
                )
            )
        else:
            wait = '  $display("[TB][ERROR] @wait_output requires exactly one *_valid_o stream");\n  errors++;'
        return {
            "stream_state": "\n".join(state),
            "stream_helpers": "\n\n".join(helpers),
            "drive_cases": "\n".join(cases),
            "wait_output_body": wait,
            "settle_cycle": f"{clocks.domains[0].name}_sample_cycle()",
        }

    @staticmethod
    def _stream_monitor_parts(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> tuple[str, str, str, str, str, str]:
        outputs = SystemVerilogTestbench._non_bus_outputs(signature, clocks, transport)
        identifiers = [(name, re.sub(r"[^A-Za-z0-9_]", "_", name)) for name in outputs]
        decls = ["  integer exp_count;", "  integer got_count;"]
        for _, ident in identifiers:
            decls.extend(
                (
                    f"  logic [31:0] exp_{ident} [0:1023];",
                    f"  logic exp_has_{ident} [0:1023];",
                )
            )
        clear = "\n".join(
            f"        exp_has_{ident}[exp_count] = 1'b0;" for _, ident in identifiers
        )
        load: list[str] = []
        checks: list[str] = []
        for index, (name, ident) in enumerate(identifiers):
            load.append(
                f'      {"if" if index == 0 else "else if"} (sig == "{name}") begin '
                f"exp_{ident}[exp_count - 1] = value; exp_has_{ident}[exp_count - 1] = 1'b1; end"
            )
            checks.extend(
                (
                    f"      if (exp_has_{ident}[got_count] && $unsigned({name}) !== exp_{ident}[got_count]) begin",
                    f'        $display("[TB][ERROR] {name}[%0d] got=0x%08x exp=0x%08x", got_count, $unsigned({name}), exp_{ident}[got_count]);',
                    "        errors++;",
                    "      end",
                )
            )
        load.append(
            '      else $display("[TB][WARN] unknown expected-output signal: %s", sig);'
            if identifiers
            else '      $display("[TB][WARN] no monitorable top-level outputs for: %s", sig);'
        )
        streams = TestbenchModel.stream_interfaces(signature, clocks, direction="output")
        if len(streams) == 1:
            sample = f"{streams[0].domain}_sample_cycle()"
            valid = streams[0].valid
        else:
            sample = f"{clocks.domains[0].name}_sample_cycle()"
            valid = "1'b1"
        return "\n".join(decls), clear, "\n".join(load), "\n".join(checks), sample, valid

    @staticmethod
    def _stream_monitor_values(
        signature: dict[str, Any], clocks: ClockConfig, transport: RegisterTransport
    ) -> dict[str, str]:
        _, clear, load, checks, sample, valid = SystemVerilogTestbench._stream_monitor_parts(
            signature, clocks, transport
        )
        return {
            "clear_expected": clear,
            "load_cases": load,
            "check_cases": checks,
            "sample_cycle": sample,
            "valid_expr": valid,
        }

    @staticmethod
    def _parser_variants(verilator: str, icarus: str) -> str:
        return "`ifdef VERILATOR\n" + verilator.rstrip() + "\n`else\n" + icarus.rstrip() + "\n`endif\n"

    @staticmethod
    def _clock_driver(domain: ClockDomain) -> list[str]:
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
