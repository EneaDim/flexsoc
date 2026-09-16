"""Dedicated scaffold renderer for the FlexSoC multiclock DSP E2E design."""

from __future__ import annotations

from pathlib import Path

from flexsoc.backend.core import ClockConfig, replace_generated_tree, safe_write_file, templates
from flexsoc.backend.design.regs import normalize_register_interface

from .cocotb_testbench import CocotbConfig, collect_sources, render_makefile
from .sv_testbench import (
    TestbenchConfig, _packed_token_support, _render_sv_clock_driver, _sv_parser_variants,
    _with_canonical_sv_output,
)
from .testbench_common import (
    _clock_jitter_bound_ps, _clock_seed_salt, _tb_phases,
)

def _multiclock_bus_sv(
    top: str, interface: str, *, cocotb: bool = False
) -> tuple[str, str, tuple[str, ...]]:
    """Render the scaffold CSR boundary for one register interface."""

    interface = normalize_register_interface(interface)
    mode = "cocotb" if cocotb else "sv"
    root = f"dv/scaffolds/multiclock_dsp/sv/bus/{mode}/{interface}"
    declarations = templates.render(f"{root}/declarations.sv.j2", top=top)
    helpers = templates.render(f"{root}/helpers.sv.j2", top=top)
    pins = {
        "tlul": ("cfg_tl_i", "cfg_tl_o", "dsp_tl_i", "dsp_tl_o"),
        "reg_iface": (
            "cfg_reg_req_i", "cfg_reg_rsp_o", "dsp_reg_req_i", "dsp_reg_rsp_o",
        ),
        "axi_lite": (
            "cfg_axi_lite_i", "cfg_axi_lite_o", "dsp_axi_lite_i", "dsp_axi_lite_o",
        ),
    }[interface]
    return declarations, helpers, pins


def _dut_pins(clocks: ClockConfig, bus_pins: tuple[str, ...]) -> str:
    """Render deterministic DUT connections for the multiclock scaffold."""

    pins = [signal for domain in clocks.domains for signal in (domain.signal, domain.reset)]
    pins += [
        *bus_pins,
        "rx_valid_i", "rx_ready_o", "rx_sample_i", "rx_coeff_i",
        "dsp_valid_o", "dsp_ready_i", "dsp_result_o",
        "dsp_above_threshold_o", "dsp_overflow_o",
    ]
    return ",\n".join(f"    .{name:<25}({name})" for name in pins)


def sv_include_text(top: str) -> str:
    """Render the multiclock SV include hook."""

    guard = f"{top.upper()}_NCLOCK_TB_INCLUDE_SV".replace("-", "_")
    return templates.render(
        "dv/scaffolds/multiclock_dsp/sv/include.sv.j2", top=top, guard=guard
    )


def _phase_helpers(clocks: ClockConfig, io_delay_pct: float) -> str:
    """Render drive/sample phase helpers from the clock contract."""

    rendered = []
    for domain in clocks.domains:
        drive_ns, sample_ns = _tb_phases(domain.period_ns, io_delay_pct)
        rendered.append(templates.render(
            "dv/scaffolds/multiclock_dsp/sv/drivers/clock_phase.svh.j2",
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
        "dv/scaffolds/multiclock_dsp/sv/drivers/reset.svh.j2",
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
    bus_section = templates.render(
        f"dv/scaffolds/multiclock_dsp/sv/bus/{interface}.svh.j2",
        top=top,
        reset_tasks=_reset_tasks(clocks),
    )
    return templates.render(
        "dv/scaffolds/multiclock_dsp/sv/drivers/reg_driver.svh.j2",
        top=top,
        phase_helpers=_phase_helpers(clocks, io_delay_pct),
        bus_section=bus_section,
    )


def _sv_vec_driver_text_string(
    top: str, clocks: ClockConfig, io_delay_pct: float = 0.2
) -> str:
    """Render native-string multiclock vector commands."""

    del top, clocks, io_delay_pct
    return templates.render("dv/scaffolds/multiclock_dsp/sv/drivers/vec_driver.svh.j2")


def _sv_monitor_text_string(top: str) -> str:
    """Render the native-string multiclock output monitor."""

    del top
    return templates.render("dv/scaffolds/multiclock_dsp/sv/drivers/vec_monitor.svh.j2")


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
    bus_decls, bus_helpers, bus_pins = _multiclock_bus_sv(top, interface)
    return templates.render(
        "dv/scaffolds/multiclock_dsp/sv/tb.sv.j2",
        top=top,
        tb_module=testbench,
        clock_decls=clock_decls,
        bus_decls=bus_decls,
        bus_helpers=bus_helpers,
        clock_drivers=clock_drivers,
        dut_pins=_dut_pins(clocks, bus_pins),
        clock_init=clock_init,
        reset_assert=reset_assert,
        reset_release=reset_release,
        primary_clock=clocks.domains[0].signal,
    )


# ---------------------------------------------------------------------------
# cocotb scaffold

# cocotb scaffold


def _generate_nclock_testbench(
    top: str, output: Path, clocks: ClockConfig, *, force: bool,
    io_delay_pct: float = 0.2, interface: str = "tlul",
) -> None:
    """Write the generated N-clock SV testbench and split drivers."""

    del force
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


def generate_nclock_testbench(
    top: str, output: Path, clocks: ClockConfig, *, force: bool,
    io_delay_pct: float = 0.2, interface: str = "tlul",
) -> tuple[Path, ...]:
    """Recreate the complete machine-owned N-clock SystemVerilog scaffold."""

    with replace_generated_tree(output):
        _generate_nclock_testbench(
            top, output, clocks, force=force, io_delay_pct=io_delay_pct, interface=interface
        )
    return (
        output / f"include_{top}_tb.sv",
        output / "drivers" / f"{top}_reg_driver.svh",
        output / "drivers" / f"{top}_vec_monitor.svh",
        output / "drivers" / f"{top}_vec_driver.svh",
        output / f"{top}_tb.sv",
    )


def cocotb_sv_text(top: str, clocks: ClockConfig, interface: str = "tlul") -> str:
    """Render the multiclock cocotb wrapper for one CSR transport."""

    interface = normalize_register_interface(interface)
    clock_decls = "\n".join(
        f"  logic {domain.signal};\n  logic {domain.reset};" for domain in clocks.domains
    )
    bus_decls, bus_helpers, bus_pins = _multiclock_bus_sv(top, interface, cocotb=True)
    return templates.render(
        f"dv/scaffolds/multiclock_dsp/cocotb/wrapper_{interface}.sv.j2",
        top=top,
        clock_decls=clock_decls,
        bus_decls=bus_decls,
        bus_helpers=bus_helpers,
        dut_pins=_dut_pins(clocks, bus_pins),
    )


def _nclock_cocotb_bus_py(interface: str) -> tuple[str, str, str]:
    """Render defaults/write/read snippets for one multiclock CSR transport."""

    interface = normalize_register_interface(interface)
    root = f"dv/scaffolds/multiclock_dsp/cocotb/bus/{interface}"
    return tuple(
        templates.render(f"{root}/{name}.py.j2")
        for name in ("defaults", "write", "read")
    )


def cocotb_reg_driver_py_text(
    top: str, clocks: ClockConfig, io_delay_pct: float = 0.2, interface: str = "tlul"
) -> str:
    """Render multiclock register helpers over the selected CSR transport."""

    del top
    clock_map = {domain.name: domain.signal for domain in clocks.domains}
    reset_map = {
        domain.name: (domain.signal, domain.reset, domain.reset_polarity)
        for domain in clocks.domains
    }
    period_ps = {domain.signal: int(round(domain.period_ns * 1000)) for domain in clocks.domains}
    drive_ps: dict[str, int] = {}
    sample_ps: dict[str, int] = {}
    for domain in clocks.domains:
        drive_ns, sample_ns = _tb_phases(domain.period_ns, io_delay_pct)
        drive_ps[domain.signal] = int(round(drive_ns * 1000))
        sample_ps[domain.signal] = int(round(sample_ns * 1000))
    defaults, write, read = _nclock_cocotb_bus_py(interface)
    return templates.render(
        "dv/scaffolds/multiclock_dsp/cocotb/reg_driver.py.j2",
        clock_map=repr(clock_map),
        period_ps=repr(period_ps),
        drive_ps=repr(drive_ps),
        sample_ps=repr(sample_ps),
        reset_map=repr(reset_map),
        primary=repr(clocks.domains[0].signal),
        settle=repr(clocks.domains[-1].signal),
        bus_defaults=defaults.rstrip(),
        bus_write=write.rstrip(),
        bus_read=read.rstrip(),
    )


def cocotb_vec_driver_py_text(top: str) -> str:
    """Render multiclock vector commands."""

    del top
    return templates.render("dv/scaffolds/multiclock_dsp/cocotb/vec_driver.py.j2")


def cocotb_monitor_py_text(top: str) -> str:
    """Render multiclock output monitor helpers."""

    del top
    return templates.render("dv/scaffolds/multiclock_dsp/cocotb/vec_monitor.py.j2")


def cocotb_py_text(top: str, clocks: ClockConfig) -> str:
    """Render the multiclock cocotb test entry point."""

    starts = "\n".join(
        f"    cocotb.start_soon(_flexsoc_clock(getattr(dut, {domain.signal!r}), "
        f"{domain.period_ns:g}, {domain.rise_ns:g}, "
        f"{(domain.fall_ns if domain.fall_ns is not None else domain.period_ns / 2.0):g}, "
        f"{domain.source_latency_ns:g}, {_clock_jitter_bound_ps(domain)}, "
        f"{_clock_seed_salt(domain.name)}))"
        for domain in clocks.domains
    )
    return templates.render(
        "dv/scaffolds/multiclock_dsp/cocotb/test.py.j2",
        top=top, clock_starts=starts,
    )


# N-clock scaffold writer


def _write_nclock_cocotb_tree(cfg: CocotbConfig, clocks: ClockConfig) -> list[Path]:
    """Write the generated N-clock cocotb scaffold into an empty tree."""

    out, drivers = cfg.output, cfg.output / "drivers"
    sources = collect_sources(cfg.top, cfg.rtl_dir.resolve(), cfg.ips_root)
    files = {
        out / "Makefile": render_makefile(cfg, sources),
        out / f"{cfg.top}_tb.sv": cocotb_sv_text(cfg.top, clocks, cfg.interface),
        drivers / "__init__.py": "",
        drivers / "reg_driver.py": cocotb_reg_driver_py_text(
            cfg.top, clocks, cfg.io_delay_pct, cfg.interface
        ),
        drivers / "vec_driver.py": cocotb_vec_driver_py_text(cfg.top),
        drivers / "vec_monitor.py": cocotb_monitor_py_text(cfg.top),
        out / f"{cfg.top}_tb.py": cocotb_py_text(cfg.top, clocks),
    }
    for path, text in files.items():
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text.rstrip() + "\n", encoding="utf-8")
    return list(files)


def write_nclock_cocotb(cfg: CocotbConfig, clocks: ClockConfig) -> list[Path]:
    """Recreate the complete machine-owned N-clock cocotb scaffold."""

    with replace_generated_tree(cfg.output):
        return _write_nclock_cocotb_tree(cfg, clocks)



class MulticlockDspTestbench:
    """Generate the dedicated multiclock DSP E2E scaffold."""

    def setup_systemverilog(
        self, config: TestbenchConfig, clocks: ClockConfig
    ) -> tuple[Path, ...]:
        canonical = _with_canonical_sv_output(config)
        return generate_nclock_testbench(
            canonical.top, canonical.output, clocks, force=canonical.force,
            io_delay_pct=canonical.io_delay_pct, interface=canonical.interface,
        )

    def setup_cocotb(
        self, config: CocotbConfig, clocks: ClockConfig
    ) -> list[Path]:
        return write_nclock_cocotb(config, clocks)
