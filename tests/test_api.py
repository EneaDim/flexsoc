"""Smoke tests for the public FlexSoC API layer."""

from __future__ import annotations

from flexsoc import FlexSoC, FlexSoCConfig


def test_public_api_describes_client() -> None:
    """The package exposes a thin client with a stable smoke contract."""

    client = FlexSoC(FlexSoCConfig(), target="demo")

    assert client.describe()["package"] == "flexsoc"
    assert client.describe()["api"] == "FlexSoC"
    assert client.describe()["options"]["target"] == "demo"


def test_flow_command_uses_backend_make_entrypoint(tmp_path) -> None:
    """The API can preview Make-backed steps with explicit overrides."""

    client = FlexSoC(project_root=tmp_path, workdir=tmp_path / "runs", top="demo")
    command = client.run_step("setup", dry_run=True, run_id="smoke")

    assert command.cwd == tmp_path.resolve()
    assert command.argv[0:3] == ("make", "-f", command.argv[2])
    assert command.argv[3] == "setup"
    assert "TOP=demo" in command.argv
    assert "RUN_ID=smoke" in command.argv
    assert f"WORKSPACE={(tmp_path / 'runs').resolve()}" in command.argv


def test_api_lists_make_backed_steps() -> None:
    """The API exposes discoverable flow steps before the backend is rewritten."""

    client = FlexSoC()

    assert "setup" in client.step_names()
    assert "soc" in client.step_names("soc")
    assert "fsm_gen" in client.step_names("fsm")


def test_prepare_step_merges_call_config_and_overrides(tmp_path) -> None:
    """Step preparation exposes normalized Make variables before execution."""

    client = FlexSoC(project_root=tmp_path, workdir=tmp_path / "runs", top="base")
    request = client.prepare_step(
        "sim",
        FlexSoCConfig(options={"top": "configured", "host": "uart"}),
        top="override",
    )

    assert request.target == "sim"
    assert request.make_vars["TOP"] == "override"
    assert request.make_vars["HOST"] == "uart"
    assert request.make_vars["WORKSPACE"] == str((tmp_path / "runs").resolve())


def test_run_step_returns_stable_result(monkeypatch, tmp_path) -> None:
    """Execution returns a small API result instead of leaking subprocess internals."""

    class Completed:
        """Tiny subprocess stand-in used to keep the API test hermetic."""

        returncode = 0
        stdout = "hi flexsoc\n"
        stderr = ""

    def fake_run(*args, **kwargs):
        """Capture subprocess options without executing a backend tool."""

        assert kwargs["capture_output"] is True
        assert kwargs["text"] is True
        return Completed()

    monkeypatch.setattr("flexsoc.api.subprocess.run", fake_run)
    client = FlexSoC(project_root=tmp_path)

    result = client.run_step("setup", capture=True, NAME="flexsoc")

    assert result.ok
    assert result.returncode == 0
    assert result.stdout == "hi flexsoc\n"
    assert result.command.request.make_vars["NAME"] == "flexsoc"


def test_inspect_step_returns_json_ready_payload(tmp_path) -> None:
    """Step inspection gives frontends structured data without running Make."""

    client = FlexSoC(project_root=tmp_path, workdir=tmp_path / "runs")
    payload = client.inspect_step("setup", top="demo")

    assert payload["request"]["target"] == "setup"
    assert payload["request"]["make_vars"]["TOP"] == "demo"
    assert payload["cwd"] == str(tmp_path.resolve())
    assert payload["shell"].startswith("make -f ")


def test_api_exposes_high_level_workflows() -> None:
    """The public API names workflows separately from advanced flow steps."""

    client = FlexSoC()

    assert "prepare" in client.workflow_names()
    assert client.prepare_workflow("prepare") == ("setup",)


def test_run_workflow_reuses_step_boundary(tmp_path) -> None:
    """Workflow previews return the same command objects as advanced steps."""

    client = FlexSoC(project_root=tmp_path)
    commands = client.run_workflow("prepare", dry_run=True, top="demo")

    assert len(commands) == 1
    assert commands[0].request.target == "setup"
    assert commands[0].request.make_vars["TOP"] == "demo"


def test_inspect_workflow_returns_json_ready_plan(tmp_path) -> None:
    """Workflow inspection previews all resolved backend commands."""

    client = FlexSoC(project_root=tmp_path)
    plan = client.inspect_workflow("prepare", top="demo")
    payload = plan.to_dict()

    assert payload["name"] == "prepare"
    assert payload["commands"][0]["request"]["target"] == "setup"
    assert payload["commands"][0]["request"]["make_vars"]["TOP"] == "demo"


def test_workflow_plan_can_render_shell_script(tmp_path) -> None:
    """Workflow previews can be copied as a reproducible shell script."""

    client = FlexSoC(project_root=tmp_path)
    plan = client.inspect_workflow("prepare", top="demo")
    script = plan.shell_script()

    assert script.startswith("#!/usr/bin/env bash\nset -euo pipefail\n")
    assert "make -f " in script
    assert "TOP=demo" in script
    assert plan.to_dict()["shell"][0] in script


def test_cli_help_guide_mentions_api_boundary(capsys) -> None:
    """The CLI exposes an explicit guide around the public API boundary."""

    from flexsoc.cli import help as help_command

    help_command()
    captured = capsys.readouterr()

    assert "fx workflow prepare --dry-run" in captured.out
    assert "API layer" in captured.out


def test_api_and_cli_docs_exist() -> None:
    """Repository docs describe the Python API and the thin CLI contract."""

    from pathlib import Path

    root = Path(__file__).resolve().parents[1]

    assert "from flexsoc import FlexSoC" in (root / "docs" / "API.md").read_text()
    assert "fx workflow prepare --dry-run" in (root / "docs" / "CLI.md").read_text()


def test_backend_hjson_generator_writes_template(tmp_path) -> None:
    """The HJSON backend helper exposes a pure writer for API integration."""

    from flexsoc.backend.hjson_gen import render_hjson, write_hjson

    text = render_hjson("demo_ip", "tlul")
    path = write_hjson("demo_ip", "tlul", tmp_path)

    assert 'name:               "demo_ip"' in text
    assert 'protocol: "tlul"' in path.read_text()


def test_backend_filelist_header_uses_backend_namespace(tmp_path) -> None:
    """Generated filelists no longer refer to the removed tools namespace."""

    from flexsoc.backend.gen_filelist import write_ip_flist

    rtl = tmp_path / "rtl"
    rtl.mkdir()
    (rtl / "demo.sv").write_text("module demo; endmodule\n")
    out = tmp_path / "rtl_list.f"

    write_ip_flist("demo", out, rtl, tmp_path)

    assert out.read_text().splitlines()[0] == "# Auto-generated by flexsoc.backend.gen_filelist"


def test_backend_driver_generator_exposes_pure_render_helpers(tmp_path) -> None:
    """The C driver backend can be used from the API without shelling out."""

    from flexsoc.backend.driver_gen import generate_driver, render_header_declarations

    hjson_file = tmp_path / "demo.hjson"
    outdir = tmp_path / "out"
    hjson_file.write_text('{ name: "demo" }\n', encoding="utf-8")
    outdir.mkdir()
    (outdir / "demo.h").write_text("#ifdef __cplusplus\n#endif\n", encoding="utf-8")

    header, source = generate_driver(hjson_file, outdir, "0x1000")

    assert "#define DEMO_BASE 0x1000" in render_header_declarations("demo", "0x1000")
    assert "typedef uintptr_t demo_t;" in header.read_text(encoding="utf-8")
    assert "int demo_init(demo_t base)" in source.read_text(encoding="utf-8")


def test_backend_rtl_stub_generator_exposes_pure_api(tmp_path) -> None:
    """The RTL stub backend can generate wrapper/core files without CLI state."""

    from flexsoc.backend.rtl_stub_gen import generate_rtl_stubs, render_core, render_wrapper

    hj = {
        "name": "demo_ip",
        "registers": [
            {
                "name": "CTRL",
                "swaccess": "rw",
                "hwqe": True,
                "fields": [{"name": "EN", "bits": "0"}],
            }
        ],
    }
    hjson_file = tmp_path / "demo.hjson"
    hjson_file.write_text('{ name: "demo_ip", registers: [] }\n', encoding="utf-8")

    core_path, wrapper_path = generate_rtl_stubs(hjson_file, "tlul", tmp_path / "rtl")

    assert "module demo_ip_core" in render_core(hj)
    assert "ctrl_en_valid" in render_core(hj)
    assert "tlul_pkg::tl_h2d_t" in render_wrapper(hj, "tlul")
    assert core_path.name == "demo_ip_core.sv"
    assert wrapper_path.name == "demo_ip.sv"

def test_backend_fsoc_generator_orders_core_file(tmp_path) -> None:
    """The FuseSoC backend exposes pure rendering and a safe writer."""

    from flexsoc.backend.setup_fsoc import list_rtl_sources, render_core, write_core

    rtl = tmp_path / "rtl"
    rtl.mkdir()
    for name in ["demo.sv", "demo_reg_pkg.sv", "helper.sv", "demo_core.sv", "pkg_pkg.sv"]:
        (rtl / name).write_text("module x; endmodule\n", encoding="utf-8")

    ordered = list_rtl_sources(rtl, "demo")
    core_path = write_core("acme", "demo", rtl, tmp_path / "out")
    rendered = render_core("acme", "demo", ordered)

    assert ordered.index("demo.sv") < ordered.index("helper.sv")
    assert 'name: "acme:ip:demo:0.1"' in rendered
    assert "rtl/demo_core.sv" in core_path.read_text(encoding="utf-8")



def test_backend_pnr_generator_writes_openroad_config(tmp_path) -> None:
    """The PnR backend can render config.mk without relying on CLI globals."""

    from flexsoc.backend.setup_pnr import parse_filelist, render_config, write_config

    rtl = tmp_path / "rtl"
    rtl.mkdir()
    inc = rtl / "include"
    inc.mkdir()
    source = rtl / "demo.sv"
    source.write_text("module demo; endmodule\n", encoding="utf-8")
    filelist = tmp_path / "rtl_list.f"
    filelist.write_text(f"+incdir+{inc}\n{source}\n", encoding="utf-8")

    inc_dirs, vfiles = parse_filelist(filelist)
    config = write_config("demo", filelist, tmp_path / "pnr", syn_strategy="delay", clk_period=25)
    rendered = render_config("demo", inc_dirs, vfiles, tmp_path / "pnr")

    assert inc in inc_dirs
    assert source in vfiles
    assert "export DESIGN_NAME     = demo" in rendered
    assert "STRATEGY ?= delay" in config.read_text(encoding="utf-8")
    assert "TARGET_CLOCK_PS ?= 25000" in config.read_text(encoding="utf-8")


def test_backend_signoff_generator_writes_opensta_scripts(tmp_path) -> None:
    """The signoff backend can render OpenSTA scripts through a pure writer."""

    from flexsoc.backend.setup_signoff import STAConfig, render_sta_tcl, write_signoff_scripts

    cfg = STAConfig(
        top="demo",
        output_dir=tmp_path / "signoff",
        syndir=tmp_path / "syn",
        sdcdir=tmp_path / "sdc",
        liberty=[tmp_path / "tech.lib"],
    )

    paths = write_signoff_scripts(cfg)
    sta = render_sta_tcl(cfg)

    assert {path.name for path in paths} == {"sta.tcl", "sta_violators.tcl", "write_sdf.tcl", "power.tcl"}
    assert "read_liberty" in sta
    assert "link_design demo" in sta
    assert (tmp_path / "signoff" / "sta.tcl").exists()


def test_reviewed_backend_parsers_use_canonical_flags(tmp_path) -> None:
    """Reviewed backend entrypoints use one current flag style for Make calls."""

    from flexsoc.backend.hjson_gen import parse_args as parse_hjson
    from flexsoc.backend.rtl_stub_gen import parse_args as parse_rtl_stub
    from flexsoc.backend.setup_fsoc import parse_args as parse_fsoc
    from flexsoc.backend.setup_model import parse_args as parse_model
    from flexsoc.backend.setup_pnr import parse_args as parse_pnr
    from flexsoc.backend.setup_signoff import parse_args as parse_signoff

    rtl_dir = tmp_path / "rtl"
    out_dir = tmp_path / "out"
    rtl_dir.mkdir()

    assert parse_hjson(["--top", "demo", "--interface", "tlul"]).top == "demo"
    assert parse_rtl_stub(["--hjson-file", "demo.hjson", "--interface", "tlul"]).itf == "tlul"
    assert parse_model(["--top", "demo", "--output-dir", str(out_dir)]).output == str(out_dir)
    assert parse_fsoc(["--project", "acme", "--top", "demo", "--rtl-dir", str(rtl_dir)]).project == "acme"
    assert parse_pnr(["--top", "demo", "--filelist", "rtl.f", "--output-dir", str(out_dir)]).top == "demo"
    assert parse_signoff(["--top", "demo", "--output-dir", str(out_dir)]).top == "demo"

    import flexsoc.backend.setup_signoff as signoff

    assert not hasattr(signoff, "build_sta_tcl")

def test_flow_step_serialization_supports_slots() -> None:
    """Step descriptions serialize explicitly even when dataclasses use slots."""

    from flexsoc import FlexSoC

    step = FlexSoC().list_steps()[0]

    assert {"name", "group", "description", "params"} <= set(step.to_dict())


def test_cli_steps_uses_public_serializer(capsys, monkeypatch) -> None:
    """The steps command prints JSON without relying on dataclass __dict__."""

    from flexsoc.api import FlowStep
    from flexsoc import cli

    class Client:
        """Minimal CLI test double exposing API-shaped step data."""

        def list_steps(self, group=None):
            """Return one step while accepting the CLI group argument."""

            return (FlowStep(name="setup", group=group or "setup", description="Create folders."),)

    monkeypatch.setattr(cli, "FlexSoC", Client)

    cli.steps(group=None)
    captured = capsys.readouterr()

    assert '"name"' in captured.out
    assert '"group"' in captured.out

def test_cli_help_documents_public_sections_without_local_runner(capsys) -> None:
    """The help command documents public CLI usage, not local runner details."""

    from flexsoc import cli

    cli.help()
    captured = capsys.readouterr()

    assert "Quickstart" in captured.out
    assert "IP development" in captured.out
    assert "SoC development" in captured.out
    assert "Tutorials" in captured.out
    assert "fx workflows" in captured.out
    assert "uv run" not in captured.out
    assert "CLI commands call FlexSoC" in captured.out


def test_full_ip_development_workflow_is_explicit() -> None:
    """The public workflow exposes the requested end-to-end IP sequence."""

    from flexsoc import FlexSoC

    client = FlexSoC()

    assert client.prepare_workflow("ip_development") == (
        "setup",
        "hjson_gen",
        "reg",
        "doc",
        "rtl_stub",
        "setup_tb",
        "sim",
        "syn",
        "sta",
        "power",
        "pnr",
        "sim_syn",
        "cocotb",
    )


def test_step_info_documents_accepted_parameters() -> None:
    """Each documented step exposes accepted Make variables to callers."""

    from flexsoc import FlexSoC

    step = FlexSoC().step_info("hjson_gen")
    params = {param.name: param for param in step.params}

    assert step.group == "ip"
    assert "TOP" in params
    assert params["REG_ITF"].default == "tlul"


def test_cli_step_info_renders_parameter_table(capsys) -> None:
    """The CLI can explain one step without reading backend modules directly."""

    from flexsoc import cli

    cli.step_info("syn", json_=False)
    captured = capsys.readouterr()

    assert "syn parameters" in captured.out
    assert "TARGET_SYN" in captured.out


def test_hjson_gen_target_is_available_in_backend_makefile() -> None:
    """The API step name hjson_gen maps to a concrete backend Make target."""

    from pathlib import Path

    root = Path(__file__).resolve().parents[1]
    makefile = root / "src" / "flexsoc" / "backend" / "Makefile"

    text = makefile.read_text(encoding="utf-8")

    assert ".PHONY: hjson hjson_gen" in text
    assert "hjson_gen: hjson" in text


def test_api_uses_backend_makefile_as_canonical_entrypoint() -> None:
    """The package runs flow steps through the backend Makefile."""

    from flexsoc import FlexSoC

    command = FlexSoC().flow_command("setup")

    assert command.argv[2].endswith("src/flexsoc/backend/Makefile")
    assert "src/flexsoc/flow/Makefile" not in command.argv[2]




def test_packaged_flow_directory_was_removed() -> None:
    """The packaged Make entrypoint lives in backend, not in a second flow tree."""

    from pathlib import Path

    root = Path(__file__).resolve().parents[1]

    assert not (root / "src" / "flexsoc" / "flow").exists()
    assert (root / "src" / "flexsoc" / "backend" / "Makefile").exists()
    assert "src/flexsoc/backend/Makefile" in (root / "flow" / "Makefile").read_text()

def test_step_catalog_covers_main_make_targets() -> None:
    """Every main development area has documented step-info metadata."""

    from flexsoc import FlexSoC

    names = set(FlexSoC().step_names())

    assert {
        "setup",
        "hjson_gen",
        "reg",
        "doc",
        "rtl_stub",
        "setup_tb",
        "sim",
        "syn",
        "sta",
        "power",
        "pnr",
        "sim_syn",
        "cocotb",
        "soc_flow",
        "fsm_flow",
        "clean_all",
    } <= names


def test_python_module_entrypoint_exists() -> None:
    """The package can expose the same CLI through python -m flexsoc."""

    from pathlib import Path

    root = Path(__file__).resolve().parents[1]

    assert "from .cli import app" in (root / "src" / "flexsoc" / "__main__.py").read_text()


def test_step_catalog_documents_make_phony_targets() -> None:
    """All Make-declared flow targets are visible through step-info."""

    from pathlib import Path
    from flexsoc import FlexSoC

    root = Path(__file__).resolve().parents[1]
    makefile = root / "src" / "flexsoc" / "backend" / "Makefile"
    phony = set()
    for line in makefile.read_text(encoding="utf-8").splitlines():
        if line.startswith(".PHONY:"):
            phony.update(line.removeprefix(".PHONY:").split())

    assert phony <= set(FlexSoC().step_names())


def test_soc_development_workflow_is_explicit() -> None:
    """The SoC workflow exposes setup, generation, software, and run steps."""

    from flexsoc import FlexSoC

    assert FlexSoC().prepare_workflow("soc_development") == (
        "setup",
        "soc_start",
        "soc_flow",
        "soc_prepare",
        "soc_build_sw",
        "soc_sim",
        "soc_run",
    )


def test_cli_help_mentions_package_module_entrypoint(capsys) -> None:
    """The public help shows the package module entrypoint too."""

    from flexsoc import cli

    cli.help()
    captured = capsys.readouterr()

    assert "python -m flexsoc help" in captured.out


def test_step_info_exposes_parameter_categories_and_examples() -> None:
    """Step metadata explains accepted overrides and copy-ready commands."""

    step = FlexSoC().step_info("syn")
    payload = step.to_dict()

    assert {param["category"] for param in payload["params"]} >= {"common", "specific"}
    assert any(param["name"] == "TARGET_SYN" for param in payload["params"])
    assert any("TARGET_SYN=asic" in example["command"] for example in payload["examples"])


def test_step_info_examples_option_prints_copy_ready_commands(capsys) -> None:
    """The CLI can print only examples for a selected step."""

    from flexsoc.cli import step_info

    step_info("setup_tb", examples=True)
    captured = capsys.readouterr()

    assert "setup_tb examples" in captured.out
    assert "COMPILER=verilator" in captured.out


def test_ip_development_workflow_keeps_explicit_order() -> None:
    """The public IP workflow follows the requested development sequence."""

    assert FlexSoC().prepare_workflow("ip_development") == (
        "setup",
        "hjson_gen",
        "reg",
        "doc",
        "rtl_stub",
        "setup_tb",
        "sim",
        "syn",
        "sta",
        "power",
        "pnr",
        "sim_syn",
        "cocotb",
    )


def test_backend_testbench_generator_exposes_config_api(tmp_path) -> None:
    """The testbench backend can generate files through a small config object."""

    from flexsoc.backend.setup_tb import TestbenchConfig, generate_testbench_files, render_verilator_include

    rtl = tmp_path / "rtl"
    rtl.mkdir()
    (rtl / "demo.sv").write_text(
        """module demo #(parameter AW = 32) (
  input logic clk_i,
  input logic rst_ni,
  output logic done_o
);
endmodule
""",
        encoding="utf-8",
    )

    out = tmp_path / "tb"
    written = generate_testbench_files(
        TestbenchConfig(
            top="demo",
            rtldir=rtl,
            simdir=tmp_path / "sim",
            syndir=tmp_path / "syn",
            prims=(),
            clk_period_ns=10,
            compiler="iverilog",
            interface="tlul",
            output=out,
            force=True,
        )
    )

    assert out / "demo_tb.sv" in written
    assert "module demo_tb" in (out / "demo_tb.sv").read_text(encoding="utf-8")
    assert '`include "demo.sv"' in render_verilator_include("demo", rtl, tmp_path / "syn", (), False, "tlul", "sv")


def test_backend_synthesis_generator_exposes_config_api(tmp_path) -> None:
    """The synthesis backend writes scripts through one config object."""

    from pathlib import Path
    from flexsoc.backend.setup_syn import SynthesisConfig, generate_synthesis_scripts, render_abc_constraints

    rtl = tmp_path / "rtl"
    sdc = tmp_path / "sdc"
    out = tmp_path / "syn"
    rtl.mkdir()
    sdc.mkdir()
    (rtl / "demo.v").write_text("module demo; endmodule\n", encoding="utf-8")
    liberty = tmp_path / "demo.lib"
    liberty.write_text("library(demo) {}\n", encoding="utf-8")

    written = generate_synthesis_scripts(
        SynthesisConfig(
            top="demo",
            topdir=rtl,
            target="asic",
            clk_period_ns=10.0,
            output=out,
            liberty=liberty,
            sdcdir=sdc,
            opt="delay",
            filelist=Path("rtl_list.f"),
        )
    )

    assert out / "synth.ys" in written
    assert out / "synth_sv.ys" in written
    assert out / "delay.abc" in written
    assert out / "abc.constr" in written
    assert "abc -D 10000" in (out / "synth.ys").read_text(encoding="utf-8")
    assert "set_driving_cell" in render_abc_constraints()


def test_backend_cocotb_generator_exposes_config_api(tmp_path) -> None:
    """The cocotb backend writes scaffold files through one config object."""

    from flexsoc.backend.setup_cocotb import CocotbConfig, render_makefile, write_cocotb_scaffold

    rtl = tmp_path / "rtl"
    rtl.mkdir()
    (rtl / "demo.sv").write_text(
        """module demo (
  input logic clk_i,
  input logic rst_ni,
  output logic done_o
);
endmodule
""",
        encoding="utf-8",
    )

    cfg = CocotbConfig(top="demo", interface="tlul", output=tmp_path / "cocotb", rtl_dir=rtl)
    written = write_cocotb_scaffold(cfg)
    makefile = render_makefile(cfg, [rtl / "demo.sv"])

    assert cfg.output / "Makefile" in written
    assert cfg.output / "demo_tb.py" in written
    assert cfg.output / "demo_tb.sv" in written
    assert "TOPLEVEL          = demo_tb" in makefile
    assert "module demo_tb" in (cfg.output / "demo_tb.sv").read_text(encoding="utf-8")
    assert "async def demo_smoke_test" in (cfg.output / "demo_tb.py").read_text(encoding="utf-8")
