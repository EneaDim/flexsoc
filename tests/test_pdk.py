"""PDK abstraction checks."""

from __future__ import annotations

from pathlib import Path
from types import SimpleNamespace

import pytest

from flexsoc.pdk import (
    PDKS,
    default_root,
    discover_views,
    fetch,
    fetch_metadata,
    formal_adapter_path,
    installed_root,
    make_overrides,
)


ROOT = Path(__file__).resolve().parents[1]


class _FormalAdapterResponse:
    def __enter__(self):
        return self

    def __exit__(self, *args):
        return False

    def read(self) -> bytes:
        return (
            b"#!/usr/bin/env python3\n"
            b"# Preprocessor for formal-friendly Verilog models for the SkyWater PDK\n"
        )


def _mock_formal_adapter(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr(
        "flexsoc.pdk.urllib.request.urlopen",
        lambda *args, **kwargs: _FormalAdapterResponse(),
    )


def test_catalog_distinguishes_real_predictive_and_reference_pdks() -> None:
    assert PDKS["sky130"].classification == "open-real-preview"
    assert PDKS["gf180mcu"].classification == "open-real-preview"
    assert PDKS["ihp-sg13g2"].classification == "open-real-preview"
    assert PDKS["asap7"].classification == "predictive-academic"
    assert PDKS["nangate45"].classification == "reference-academic"


def test_compact_sky130_bundle_resolves_without_backend_hardcoding() -> None:
    root = ROOT / "pdks" / "sky130"
    views = discover_views(root, "sky130")
    assert views.usable
    assert views.liberty_typ and "__tt_" in views.liberty_typ.name
    assert any(path.name == "primitives.v" for path in views.verilog_models)
    assert any(path.name == "sky130_fd_sc_hd.no_tc.v" for path in views.verilog_models)

    values = make_overrides(ROOT, "sky130", root)
    assert values["ORS_TECH"] == "sky130hd"
    assert values["LIB_SYN"].endswith("sky130_fd_sc_hd__tt_025C_1v80.lib")
    assert values["DRIVING_CELL"] == "sky130_fd_sc_hd__buf_1"


def test_fetch_root_is_ignored_flexsoc_state_and_legacy_bundle_is_ignored(tmp_path: Path) -> None:
    managed = tmp_path / ".flexsoc" / "pdks" / "sky130"
    assert default_root(tmp_path, "sky130") == managed
    legacy = tmp_path / "pdks" / "sky130"
    legacy.mkdir(parents=True)
    assert installed_root(tmp_path, "sky130") == managed.resolve()
    assert installed_root(tmp_path, "sky130", legacy) == legacy.resolve()


def test_sky130_fetch_uses_ciel_prebuilt_open_pdks(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    _mock_formal_adapter(monkeypatch)
    calls: list[list[str]] = []
    revision = "44a43c23c81b45b8e774ae7a84899a5a778b6b0b"

    monkeypatch.setattr("flexsoc.pdk.shutil.which", lambda name: "/usr/bin/ciel" if name == "ciel" else None)

    def fake_run(command, **kwargs):
        calls.append([str(part) for part in command])
        if "ls-remote" in command:
            return SimpleNamespace(
                stdout=f"{revision}\n", stderr="", returncode=0
            )
        if "enable" in command:
            pdk_root = tmp_path / ".flexsoc" / "pdks"
            version_root = pdk_root / "ciel" / "sky130" / "versions" / revision / "sky130A"
            libdir = version_root / "libs.ref" / "sky130_fd_sc_hd" / "lib"
            vdir = version_root / "libs.ref" / "sky130_fd_sc_hd" / "verilog"
            libdir.mkdir(parents=True)
            vdir.mkdir(parents=True)
            (libdir / "sky130_fd_sc_hd__tt_025C_1v80.lib").write_text("library(test) {}\n")
            (vdir / "primitives.v").write_text("primitive sky130_udp_test; endprimitive\n")
            (vdir / "sky130_fd_sc_hd.v").write_text("module sky130_fd_sc_hd__buf_1; endmodule\n")
            (pdk_root / "sky130A").symlink_to(
                Path("ciel") / "sky130" / "versions" / revision / "sky130A",
                target_is_directory=True,
            )
            return SimpleNamespace(stdout="", stderr="", returncode=0)
        raise AssertionError(command)

    monkeypatch.setattr("flexsoc.pdk.subprocess.run", fake_run)
    path = fetch(tmp_path, "sky130")
    assert path == tmp_path / ".flexsoc" / "pdks" / "sky130"
    assert path.is_symlink()
    assert path.resolve().name == "sky130A"
    assert calls[0][1:3] == ["ls-remote", "--pdk-root"]
    assert calls[0][-2:] == ["--pdk-family", "sky130"]
    assert calls[1][1:3] == ["enable", "--pdk-root"]
    assert calls[1][-1] == revision
    assert fetch_metadata(path)["provider"] == "ciel"
    assert fetch_metadata(path)["revision"] == revision
    assert fetch_metadata(path)["variant"] == "sky130A"
    views = discover_views(path, "sky130")
    assert views.usable
    assert views.liberty_typ and views.liberty_typ.name == "sky130_fd_sc_hd__tt_025C_1v80.lib"
    assert [path.name for path in views.verilog_models] == ["primitives.v", "sky130_fd_sc_hd.v"]
    assert all("libs.ref/sky130_fd_sc_hd/verilog" in path.as_posix() for path in views.verilog_models)
    adapter = formal_adapter_path(tmp_path, "sky130")
    assert adapter is not None and adapter.is_file()
    assert fetch_metadata(path)["formal_adapter"]["path"] == str(adapter)
    assert make_overrides(tmp_path, "sky130", path)["FORMAL_PDK_PROC"] == str(adapter)


def test_ihp_reference_layout_discovers_stdcell_verilog_with_the_pdk(tmp_path: Path) -> None:
    root = tmp_path / "ihp-sg13g2"
    libdir = root / "ihp-sg13g2" / "libs.ref" / "sg13g2_stdcell" / "lib"
    vdir = root / "ihp-sg13g2" / "libs.ref" / "sg13g2_stdcell" / "verilog"
    libdir.mkdir(parents=True)
    vdir.mkdir(parents=True)
    (libdir / "sg13g2_stdcell_typ_1p50V_25C.lib").write_text("library(test) {}\n")
    (vdir / "sg13g2_stdcell.v").write_text("module sg13g2_buf_1; endmodule\n")

    views = discover_views(root, "ihp-sg13g2")
    assert views.usable
    assert views.liberty_typ and views.liberty_typ.name == "sg13g2_stdcell_typ_1p50V_25C.lib"
    assert [path.name for path in views.verilog_models] == ["sg13g2_stdcell.v"]

def test_sky130_fetch_accepts_explicit_ciel_revision(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    _mock_formal_adapter(monkeypatch)
    calls: list[list[str]] = []
    revision = "7519dfb04400f224f140749cda44ee7de6f5e095"
    monkeypatch.setattr("flexsoc.pdk.shutil.which", lambda name: "/usr/bin/ciel")

    def fake_run(command, **kwargs):
        calls.append([str(part) for part in command])
        pdk_root = tmp_path / ".flexsoc" / "pdks"
        version_root = pdk_root / "ciel" / "sky130" / "versions" / revision / "sky130A"
        version_root.mkdir(parents=True, exist_ok=True)
        (pdk_root / "sky130A").symlink_to(
            Path("ciel") / "sky130" / "versions" / revision / "sky130A",
            target_is_directory=True,
        )
        return SimpleNamespace(stdout="", stderr="", returncode=0)

    monkeypatch.setattr("flexsoc.pdk.subprocess.run", fake_run)
    path = fetch(tmp_path, "sky130", version=revision)
    assert len(calls) == 1
    assert "ls-remote" not in calls[0]
    assert calls[0][1] == "enable"
    assert calls[0][-1] == revision
    assert path.is_symlink()


def test_ciel_cli_failure_is_actionable(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr("flexsoc.pdk.shutil.which", lambda name: "/usr/bin/ciel")

    def fake_run(command, **kwargs):
        return SimpleNamespace(stdout="", stderr="Usage: ciel ls-remote ...", returncode=2)

    monkeypatch.setattr("flexsoc.pdk.subprocess.run", fake_run)
    with pytest.raises(ValueError, match="Ciel command failed.*ls-remote"):
        fetch(tmp_path, "sky130")

def test_ciel_fetch_has_actionable_missing_dependency_error(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr("flexsoc.pdk.shutil.which", lambda name: None)
    with pytest.raises(ValueError, match="pip install.*ciel"):
        fetch(tmp_path, "sky130")
