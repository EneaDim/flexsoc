"""Minimal checks for the FlexSoC API and fx CLI."""

from __future__ import annotations

import json
import subprocess
from pathlib import Path

from flexsoc import FlexSoC, FlexSoCConfig
from flexsoc.api import NATIVE_TARGETS
from flexsoc.backend.metrics import eqy_solver_stats
from flexsoc.cli import app


ROOT = Path(__file__).resolve().parents[1]
BACKEND_MAKEFILE = ROOT / "src" / "flexsoc" / "backend" / "Makefile"


def _makefile_targets() -> set[str]:
    """Return every target declared in PHONY_TARGETS."""

    targets: set[str] = set()
    for line in BACKEND_MAKEFILE.read_text(encoding="utf-8").splitlines():
        if line.startswith("PHONY_TARGETS +="):
            targets.update(line.split("+=", 1)[1].split())
    return targets


def test_api_catalog_matches_makefile_targets() -> None:
    """The API covers public Make targets plus intentional Python-native ones."""

    api = set(FlexSoC(project_root=ROOT).target_names())
    make = _makefile_targets() - {"_formal_scaffold"}
    api_only = {"deps-bootstrap", "deps-doctor", "deps-versions", "deps-env"} | (set(NATIVE_TARGETS) - make)
    assert make <= api
    assert api - make == api_only


def test_api_builds_ordered_commands_and_overrides(tmp_path: Path) -> None:
    """Settings, overrides, dashed names, and command order stay explicit."""

    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"), top="base")
    first, second = fx.override(top="cordic").commands("lint-width", "yosys_vgen", RUN_ID="r1")

    assert [first.target, second.target] == ["lint_width", "yosys-vgen"]
    assert first.cwd == tmp_path.resolve()
    assert "TOP=cordic" in first.argv
    assert "RUN_ID=r1" in first.argv
    assert f"WORKSPACE={tmp_path / 'ws'}" in first.argv

    gate = fx.command("sim_post_syn", TOP="cordic")
    legacy_alias = fx.command("sim_syn", TOP="cordic")
    assert gate.argv[1:4] == ("-m", "flexsoc.backend.post_sim", "--action")
    assert legacy_alias.argv[1:4] == ("-m", "flexsoc.backend.post_sim", "--action")
    assert "post_syn" in gate.argv
    assert gate.values["WAVE_FORMAT"] == "fst"



def test_slang_targets_forward_explicit_analysis_roots(tmp_path: Path) -> None:
    """Slang analysis overrides must reach Make instead of falling back to REPO_ROOT."""

    rtl = tmp_path / "run" / "rtl"
    top_file = rtl / "demo.sv"
    search = tmp_path / "shared"
    command = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws")).command(
        "slang_ast", SLANG_ROOT=rtl, SLANG_TOP_FILE=top_file, SLANG_SEARCH_ARGS=f"--search-root {search}"
    )
    joined = " ".join(command.argv)
    assert f"SLANG_ROOT={rtl}" in joined
    assert f"SLANG_TOP_FILE={top_file}" in joined
    assert f"SLANG_SEARCH_ARGS=--search-root {search}" in joined


def test_eqy_solver_stats_reports_the_strategy_that_closes_partitions(tmp_path: Path) -> None:
    log = tmp_path / "eqy.log"
    log.write_text(
        "Running strategy 'sat' on 'demo.out.0'..\n"
        "Could not prove equivalence of partition 'demo.out.0' using strategy 'sat'\n"
        "Running strategy 'pdr' on 'demo.out.0'..\n"
        "Proved equivalence of partition 'demo.out.0' using strategy 'pdr'\n"
        "Running strategy 'pdr' on 'demo.out.1'..\n"
        "Proved equivalence of partition 'demo.out.1' using strategy 'pdr'\n",
        encoding="utf-8",
    )
    assert eqy_solver_stats(log) == {
        "sat": {"attempts": 1, "proved": 0, "unproved": 1, "errors": 0},
        "pdr": {"attempts": 2, "proved": 2, "unproved": 0, "errors": 0},
    }


def test_rtl_make_commands_do_not_leak_pdk_libs_into_verilator(tmp_path: Path) -> None:
    """Technology libraries are scoped to technology-dependent Make targets."""

    pdk = tmp_path / ".flexsoc" / "pdks" / "sky130"
    (pdk / "lib").mkdir(parents=True)
    (pdk / "verilog").mkdir(parents=True)
    (pdk / "lib" / "sky130_fd_sc_hd__tt_025C_1v80.lib").write_text("library(test) {}\n")
    (pdk / "verilog" / "sky130_fd_sc_hd.v").write_text("module sky130_fd_sc_hd__buf_1; endmodule\n")

    fx = FlexSoC(FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"), TOP="demo")
    rtl = fx.command("compile_sv")
    syn = fx.command("syn")

    assert not any(arg.startswith("LIBS=") or arg.startswith("LIB_SYN=") for arg in rtl.argv)
    assert any(arg.startswith("LIB_SYN=") for arg in syn.argv)
    assert "CLOCK_MODE=" in " ".join(rtl.argv)

def test_api_dry_run_does_not_spawn_processes(monkeypatch, tmp_path: Path) -> None:
    """Dry-run returns previews only."""

    def fail(*args, **kwargs):  # noqa: ANN001, ANN002, ANN003
        raise AssertionError("subprocess.run should not be called")

    monkeypatch.setattr(subprocess, "run", fail)
    result = FlexSoC(project_root=tmp_path).run("setup", "reg", dry_run=True, TOP="demo")

    assert [item.target for item in result] == ["setup", "reg"]
    assert all(item.cwd == tmp_path.resolve() for item in result)


def test_cli_help_settings_commands_and_dry_run(capsys, monkeypatch, tmp_path: Path) -> None:
    """fx keeps Typer help, settings, catalog, and dry-runs minimal."""

    monkeypatch.chdir(tmp_path)

    assert app(["--help"]) == 0
    help_out = capsys.readouterr().out
    assert "IP development" in help_out
    assert "System-on-chip building" in help_out
    assert "--install-completion" in help_out

    assert app(["settings", "TOP=cordic", "RUN_ID=e2e"]) == 0
    assert json.loads((tmp_path / ".flexsoc" / "settings.json").read_text())["TOP"] == "cordic"
    capsys.readouterr()

    assert app(["commands", "--json"]) == 0
    names = {item["name"] for item in json.loads(capsys.readouterr().out)}
    assert {"lint_latch", "lint_width", "top_from_core", "ip_load", "soc_run", "clean_all"} <= names

    assert app(["pdk", "list", "--json"]) == 0
    pdk_rows = json.loads(capsys.readouterr().out)
    assert {"sky130", "gf180mcu", "ihp-sg13g2", "asap7", "nangate45"} <= {row["name"] for row in pdk_rows}

    assert app(["lint_width", "syn", "--dry-run", "--set", "LINT_PART=all"]) == 0
    out = capsys.readouterr().out
    assert " lint_width " in out
    assert " syn " in out
    assert "TOP=cordic" in out
    assert "LINT_PART=all" in out


def test_technology_targets_are_isolated_by_pdk(tmp_path: Path) -> None:
    """PDK names appear locally under each technology-dependent flow branch."""

    for name in ("sky130", "ihp-sg13g2"):
        pdk = tmp_path / ".flexsoc" / "pdks" / name
        (pdk / "lib").mkdir(parents=True)
        (pdk / "verilog").mkdir(parents=True)
        (pdk / "lib" / f"{name}_tt.lib").write_text("library(test) {}\n")
        (pdk / "verilog" / f"{name}.v").write_text("module cell; endmodule\n")

    fx = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"),
        TOP="demo",
        RUN_TOP="demo",
        RUN_ID="r1",
        PDK="sky130",
    )
    rtl = fx.command("regression")
    sky_syn = fx.command("syn")
    ihp_syn = fx.command("syn", PDK="ihp-sg13g2")
    sky_eq = fx.command("eqy")

    shared = tmp_path / "ws" / "runs" / "demo" / "r1"
    assert not any("SYNDIR=" in arg for arg in rtl.argv)
    assert f"SYNDIR={shared / 'syn' / 'sky130'}" in sky_syn.argv
    assert f"EQUIVDIR={shared / 'signoff' / 'equivalence' / 'sky130' / 'rtl_vs_syn'}" in sky_eq.argv
    assert any(
        arg.startswith("PRIM=") and str(tmp_path / ".flexsoc" / "pdks" / "sky130" / "verilog" / "sky130.v") in arg
        for arg in sky_eq.argv
    )
    assert f"SYNDIR={shared / 'syn' / 'ihp-sg13g2'}" in ihp_syn.argv
    assert ihp_syn.values["PDK_ROOT"].endswith("/.flexsoc/pdks/ihp-sg13g2")


def test_one_shot_pdk_switch_does_not_reuse_stale_root(tmp_path: Path) -> None:
    """PDK override without PDK_ROOT resolves the new managed installation."""

    sky = tmp_path / ".flexsoc" / "pdks" / "sky130"
    ihp = tmp_path / ".flexsoc" / "pdks" / "ihp-sg13g2"
    for root in (sky, ihp):
        (root / "lib").mkdir(parents=True)
        (root / "verilog").mkdir(parents=True)
        (root / "lib" / "tt.lib").write_text("library(test) {}\n")
        (root / "verilog" / "cells.v").write_text("module cell; endmodule\n")

    fx = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"),
        PDK="sky130",
        PDK_ROOT=str(sky),
    )
    command = fx.command("syn", PDK="ihp-sg13g2")
    assert command.values["PDK"] == "ihp-sg13g2"
    assert command.values["PDK_ROOT"] == str(ihp.resolve())


def test_equivalence_generator_belongs_to_setup_signoff() -> None:
    """The Make surface routes EQY generation through the sign-off backend."""

    text = BACKEND_MAKEFILE.read_text(encoding="utf-8")
    block = text.split("setup_eqy:", 1)[1].split("\neqy:", 1)[0]
    assert "flexsoc.backend.setup_signoff eqy" in block
    assert "flexsoc.backend.setup_formal eqy" not in text


def test_pdk_scoped_paths_keep_flow_before_technology(tmp_path: Path) -> None:
    """Technology-dependent targets share one logical run and split only at local PDK leaves."""

    for name in ("sky130", "ihp-sg13g2"):
        root = tmp_path / ".flexsoc" / "pdks" / name
        (root / "lib").mkdir(parents=True)
        (root / "verilog").mkdir(parents=True)
        (root / "lib" / "tt.lib").write_text("library(test) {}\n")
        (root / "verilog" / "cells.v").write_text("module cell; endmodule\n")

    fx = FlexSoC(
        FlexSoCConfig(project_root=tmp_path, workdir=tmp_path / "ws"),
        TOP="demo",
        RUN_TOP="demo",
        RUN_ID="r1",
        PDK="sky130",
    )
    shared = tmp_path / "ws" / "runs" / "demo" / "r1"
    for pdk in ("sky130", "ihp-sg13g2"):
        values = fx.command("eqy", PDK=pdk).values
        assert values["RUN_ROOT"] == str(shared)
        assert values["SYNDIR"] == str(shared / "syn" / pdk)
        assert values["EQUIVDIR"] == str(shared / "signoff" / "equivalence" / pdk / "rtl_vs_syn")
        assert values["SIGNOFF_STA_DIR"] == str(shared / "signoff" / "sta" / pdk)
        assert values["SIGNOFF_POWER_DIR"] == str(shared / "signoff" / "power" / pdk)
        assert values["SIGNOFF_SDF_DIR"] == str(shared / "signoff" / "sdf" / pdk)
        assert values["ORSDIR"] == str(shared / "pnr_openroad" / pdk)
        assert values["POST_SYN_SIMDIR"] == str(shared / "dv" / "functional" / "sim" / "post_syn" / pdk)
        assert values["POST_LAYOUT_SIMDIR"] == str(shared / "dv" / "functional" / "sim" / "post_pnr" / pdk)
        assert values["METADIR"] == str(shared / "meta" / pdk)
        assert "/tech/" not in "\n".join(values.values())
