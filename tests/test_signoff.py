"""Focused contracts for the OpenSTA/EQY sign-off generators."""

from __future__ import annotations

from pathlib import Path

import pytest

from flexsoc.backend.setup_signoff import (
    SignoffContext,
    render_fusion_analysis_tcl,
    render_power_analysis_tcl,
    render_power_estimate_tcl,
    render_sta_tcl,
    generate_families,
    _annotate_power_summary,
    _run_sta,
)
from flexsoc.run_layout import pdk_run_layout


def _context(tmp_path: Path, *, analysis: str, mode: str = "setup") -> SignoffContext:
    liberty = tmp_path / "demo__tt.lib"
    netlist = tmp_path / "demo_synth.v"
    sdc = tmp_path / "demo.sdc"
    activity = tmp_path / "smoke.vcd"
    gls = tmp_path / "smoke.json"
    for path, text in (
        (liberty, "library(demo) {}\n"),
        (netlist, "module demo; endmodule\n"),
        (sdc, "create_clock -period 10 [get_ports clk]\n"),
        (activity, "$enddefinitions $end\n"),
        (gls, "{}\n"),
    ):
        path.write_text(text, encoding="utf-8")
    return SignoffContext(
        analysis=analysis,
        design="demo",
        variant="dev",
        pdk="sky130",
        stage="post_syn",
        corner="tt",
        mode=mode,
        workload="smoke_sv_typ" if "analysis" in analysis else "",
        top="demo",
        liberty=liberty,
        macro_liberties=(),
        netlist=netlist,
        sdc=sdc,
        report_dir=tmp_path / "reports",
        activity_file=activity if analysis in {"power_analysis", "fusion_analysis"} else None,
        activity_scope="demo_tb/u_demo",
        gls_report=gls if analysis in {"power_analysis", "fusion_analysis"} else None,
    )


def test_failed_opensta_keeps_details_in_log(
    tmp_path: Path, capsys: pytest.CaptureFixture[str]
) -> None:
    tool = tmp_path / "fake_sta.py"
    tool.write_text(
        "#!/usr/bin/env python3\n"
        "print('Error: synthetic OpenSTA failure')\n"
        "raise SystemExit(7)\n",
        encoding="utf-8",
    )
    tool.chmod(0o755)
    log = tmp_path / "sta.log"

    assert _run_sta([str(tool)], cwd=tmp_path, log=log) == 7

    captured = capsys.readouterr()
    assert captured.out == ""
    assert captured.err == ""
    assert "synthetic OpenSTA failure" in log.read_text(encoding="utf-8")


def test_sdf_writer_uses_pinned_opensta_command_contract(tmp_path: Path) -> None:
    from flexsoc.backend.setup_signoff import render_sdf_tcl

    script = render_sdf_tcl(_context(tmp_path, analysis="sdf", mode=""))
    assert "write_sdf -divider . -include_typ $sdf_file" in script
    assert "demo_tt.sdf" in script
    assert "report_units >" not in script
    assert "report_units >>" not in script
    assert "sta::redirect_file_begin [file join $report_dir units.rpt]" in script
    assert "sta::redirect_file_end" in script


def test_sta_setup_hold_and_report_contract(tmp_path: Path) -> None:
    setup = render_sta_tcl(_context(tmp_path, analysis="sta", mode="setup"))
    hold = render_sta_tcl(_context(tmp_path, analysis="sta", mode="hold"))

    assert "set delay_type max" in setup
    assert "report_wns -max" in setup and "report_tns -max" in setup
    assert "set delay_type min" in hold
    assert "report_wns -min" in hold and "report_tns -min" in hold
    for name in (
        "summary.rpt",
        "check_setup.rpt",
        "endpoint_coverage.rpt",
        "violating.rpt",
        "near_critical.rpt",
        "unconstrained.rpt",
        "check_types.rpt",
    ):
        assert name in setup
    assert "-group_path_count" in setup
    assert "-endpoint_path_count" in setup
    assert "-unique_paths_to_endpoint" in setup
    assert "sta::redirect_file_append_begin $summary" in setup
    assert "report_units >>" not in setup


def test_power_estimate_uses_input_activity_by_default(tmp_path: Path) -> None:
    script = render_power_estimate_tcl(_context(tmp_path, analysis="power_estimate"))

    assert "set_power_activity -input" in script
    assert "set_power_activity -global" not in script
    assert "analysis=estimate" in script
    assert "activity_source=input_assumption" in script
    for name in (
        "activity_assumptions.rpt",
        "activity_annotation.rpt",
        "power_summary.rpt",
        "highest_power_instances.rpt",
    ):
        assert name in script


def test_activity_power_reads_trace_and_reports_annotation(tmp_path: Path) -> None:
    script = render_power_analysis_tcl(_context(tmp_path, analysis="power_analysis"))

    assert "read_vcd -scope $activity_scope $activity_file" in script
    assert "read_saif -scope $activity_scope $activity_file" in script
    assert "report_activity_annotation -report_annotated -report_unannotated" in script
    assert "report_power -highest_power_instances" in script
    assert "power.json" in script


def test_fusion_keeps_timing_and_power_selections_independent(tmp_path: Path) -> None:
    script = render_fusion_analysis_tcl(_context(tmp_path, analysis="fusion_analysis"))

    assert "timing_violating_power.rpt" in script
    assert "timing_near_critical_power.rpt" in script
    assert "power_driven_paths.rpt" in script
    assert "paths.csv" in script and "path_instances.csv" in script
    assert "sta::instance_power" in script
    assert "set power_corner NULL" in script
    assert "sta::cmd_scene" not in script
    assert "sta::network_leaf_instances" in script
    assert "find_timing_paths -through" in script
    power_driven = script.split("set hotspot_rows", 1)[1]
    assert "-slack_min" not in power_driven
    assert "-slack_max" not in power_driven
    for field in (
        "dynamic_power_proxy",
        "total_power_proxy",
        "max_output_capacitance",
        "sum_output_capacitance_proxy",
        "max_fanout",
        "max_slew",
        "switched_capacitance_proxy",
        "activity_weighted_capacitance_proxy",
    ):
        assert field in script
    assert "role ne \"CAPTURE_SEQ\"" in script
    assert "timing-safe paths are valid results" in script


def test_pdk_first_layout_for_all_technology_artifacts(tmp_path: Path) -> None:
    layout = pdk_run_layout(tmp_path / "run", pdk="ihp-sg13g2", top="demo")

    assert layout.syn_dir == tmp_path / "run/syn/ihp-sg13g2"
    assert layout.pnr_dir == tmp_path / "run/pnr_openroad/ihp-sg13g2"
    assert layout.equivalence_dir == tmp_path / "run/signoff/ihp-sg13g2/equivalence/rtl_vs_syn"
    assert layout.sta_dir == tmp_path / "run/signoff/ihp-sg13g2/sta"
    assert layout.power_dir == tmp_path / "run/signoff/ihp-sg13g2/power"
    assert layout.fusion_dir == tmp_path / "run/signoff/ihp-sg13g2/fusion"
    assert layout.sdf_dir == tmp_path / "run/signoff/ihp-sg13g2/sdf"


def test_eqy_and_opensta_modules_are_separated() -> None:
    root = Path(__file__).resolve().parents[1] / "src/flexsoc/backend"
    signoff = (root / "setup_signoff.py").read_text(encoding="utf-8")
    eqy = (root / "setup_eqy.py").read_text(encoding="utf-8")

    assert "eqy-export" not in signoff
    assert "generate_equivalence_config" not in signoff
    assert "render_sta_tcl" not in eqy
    assert "render_power_analysis_tcl" not in eqy
    assert not (root / "power_analysis.py").exists()


def test_saved_ip_packages_use_pdk_first_technology_branches() -> None:
    root = Path(__file__).resolve().parents[1] / "hw/ips"
    technology_packages = []
    for package in sorted(path for path in root.iterdir() if path.is_dir()):
        if not any((package / stage).is_dir() for stage in ("syn", "pnr_openroad", "signoff")):
            continue
        technology_packages.append(package.name)
        for stage in ("syn", "pnr_openroad"):
            directory = package / stage
            if directory.is_dir():
                assert not any(path.is_file() for path in directory.iterdir()), (
                    package.name,
                    stage,
                )
        signoff = package / "signoff"
        if signoff.is_dir():
            assert not any(path.is_file() for path in signoff.iterdir()), package.name
            assert not (signoff / "equivalence").exists(), package.name
    assert {"cordic", "uart", "cache_wrapper", "fft_core", "gpio", "pwm"}.issubset(
        technology_packages
    )
    for top in ("cordic", "uart"):
        package = root / top
        assert (package / "syn/sky130").is_dir()
        assert (package / "pnr_openroad/sky130").is_dir()
        assert (package / "signoff/sky130/equivalence/rtl_vs_syn").is_dir()
        assert (package / "signoff/ihp-sg13g2/equivalence/rtl_vs_syn").is_dir()



def test_setup_signoff_generates_five_families_without_activity_scripts(
    tmp_path: Path,
) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    (run / "syn/sky130").mkdir(parents=True)
    (run / "constraints").mkdir(parents=True)
    (run / "syn/sky130/demo_synth.v").write_text(
        "module demo; endmodule\n", encoding="utf-8"
    )
    (run / "constraints/demo.sdc").write_text(
        "create_clock -period 10 [get_ports clk]\n", encoding="utf-8"
    )
    liberties = []
    for corner in ("ss", "tt", "ff"):
        path = tmp_path / f"demo__{corner}_view.lib"
        path.write_text("library(demo) {}\n", encoding="utf-8")
        liberties.append(path)
    values = {
        "WORKSPACE": str(workspace),
        "RUN_TOP": "demo",
        "RUN_ID": "dev",
        "TOP": "demo",
        "PDK": "sky130",
        "LIBS": " ".join(str(path) for path in liberties),
        "PNR_SDC_FILE": str(run / "constraints/demo.sdc"),
    }

    paths = generate_families(tmp_path, values)

    assert {path.relative_to(run).as_posix() for path in paths} == {
        "signoff/sky130/sta/sta.tcl",
        "signoff/sky130/sdf/write_sdf.tcl",
        "signoff/sky130/power/estimate/power_estimate.tcl",
        "signoff/sky130/power/analysis/power_analysis.tcl",
        "signoff/sky130/fusion/fusion_analysis.tcl",
    }
    assert not (run / "signoff/sky130/power/activity/scripts").exists()


def test_common_header_and_runtime_validation_are_complete(tmp_path: Path) -> None:
    ctx = _context(tmp_path, analysis="sta", mode="setup")
    script = render_sta_tcl(ctx)

    for label in (
        "Analysis : sta",
        "Design   : demo",
        "Variant  : dev",
        "PDK      : sky130",
        "Stage    : post_syn",
        "Corner   : tt",
        "Mode     : setup",
        "Top      : demo",
        "Macro Liberty",
        "Report dir",
        "Limitations:",
    ):
        assert label in script
    assert "flexsoc_require_readable" in script
    assert "read_liberty $liberty" in script
    assert "read_verilog $netlist" in script
    assert "link_design $top" in script
    assert "read_sdc $sdc" in script
    assert "report_units" in script


def test_post_route_context_uses_pnr_netlist_spef_and_propagated_clocks(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    results = run / "pnr_openroad/sky130/results/demo/base"
    results.mkdir(parents=True)
    (results / "6_final.v").write_text("module demo; endmodule\n", encoding="utf-8")
    (results / "6_final.spef").write_text("*SPEF \"IEEE 1481-1998\"\n", encoding="utf-8")
    (run / "constraints").mkdir(parents=True)
    (run / "constraints/demo.sdc").write_text("create_clock -period 10 [get_ports clk]\n", encoding="utf-8")
    liberty = tmp_path / "demo__tt_view.lib"
    liberty.write_text("library(demo) {}\n", encoding="utf-8")
    paths = generate_families(
        tmp_path,
        {
            "WORKSPACE": str(workspace),
            "RUN_TOP": "demo",
            "RUN_ID": "dev",
            "TOP": "demo",
            "PDK": "sky130",
            "SIGNOFF_STAGE": "post_route",
            "LIBS": str(liberty),
            "PNR_SDC_FILE": str(run / "constraints/demo.sdc"),
        },
    )
    sta = next(path for path in paths if path.name == "sta.tcl").read_text(encoding="utf-8")
    assert str(results / "6_final.v") in sta
    assert str(results / "6_final.spef") in sta
    assert "set_propagated_clock" in sta
    assert "Stage    : post_route" in sta


def test_missing_configured_macro_liberty_is_an_error(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    run = workspace / "runs/demo/dev"
    (run / "syn/sky130").mkdir(parents=True)
    (run / "constraints").mkdir(parents=True)
    (run / "syn/sky130/demo_synth.v").write_text("module demo; endmodule\n", encoding="utf-8")
    (run / "constraints/demo.sdc").write_text("create_clock -period 10 [get_ports clk]\n", encoding="utf-8")
    liberty = tmp_path / "demo__tt_view.lib"
    liberty.write_text("library(demo) {}\n", encoding="utf-8")
    with pytest.raises(ValueError, match="missing macro Liberty"):
        generate_families(
            tmp_path,
            {
                "WORKSPACE": str(workspace),
                "RUN_TOP": "demo",
                "RUN_ID": "dev",
                "TOP": "demo",
                "PDK": "sky130",
                "LIBS": str(liberty),
                "MACRO_LIBS": str(tmp_path / "missing_macro.lib"),
                "PNR_SDC_FILE": str(run / "constraints/demo.sdc"),
            },
        )


def test_power_summary_gets_explicit_dynamic_definition(tmp_path: Path) -> None:
    report = tmp_path / "power_summary.rpt"
    report.write_text("Total 1.0 2.5 0.25 3.75\n", encoding="utf-8")
    _annotate_power_summary(tmp_path)
    text = report.read_text(encoding="utf-8")
    assert "dynamic_power_definition=internal_power+switching_power" in text
    assert "internal_power=1.0" in text
    assert "switching_power=2.5" in text
    assert "dynamic_power=3.5" in text
    assert "total_power=3.75" in text

