"""Toolchain compatibility and manifest metadata checks."""

from __future__ import annotations

from pathlib import Path

from flexsoc import doctor
from flexsoc.backend import manifest


def test_lock_records_current_verilator_icarus_and_openroad_baselines() -> None:
    root = Path(__file__).resolve().parents[1]
    lock = doctor.load_toolchain_lock(root)
    assert lock["LOCK_VERSION"] == "3"
    assert lock["VERILATOR_VERSION"] == "5.050"
    assert lock["VERILATOR_MIN_VERSION"] == "5.050"
    assert lock["IVERILOG_VERSION"] == "13.0"
    assert lock["IVERILOG_MIN_VERSION"] == "12.0"
    assert lock["OPENROAD_VERSION"] == "v2.0-26328-gd6e98657f1"
    assert lock["OPENROAD_REF_PREFIX"] == "d6e98657f1"


def test_icarus_12_is_compatible_but_not_lock_exact() -> None:
    version_ok, lock_match = doctor._assess_tool(
        "iverilog",
        "Icarus Verilog version 12.0 (stable) ()",
        {"minimum_version": "12.0", "locked_version": "13.0"},
    )
    assert version_ok is True
    assert lock_match is False


def test_openroad_tested_snapshot_matches_by_version_and_ref() -> None:
    version_ok, lock_match = doctor._assess_tool(
        "openroad",
        "OpenROAD v2.0-26328-gd6e98657f1",
        {
            "locked_version": "v2.0-26328-gd6e98657f1",
            "ref_prefix": "d6e98657f1",
        },
    )
    assert version_ok is True
    assert lock_match is True


def test_manifest_schema_5_preserves_tool_compatibility(monkeypatch, tmp_path: Path) -> None:
    monkeypatch.setattr(
        manifest,
        "collect_environment",
        lambda root: {
            "tools": [
                {
                    "executable": "iverilog",
                    "found": True,
                    "version": "Icarus Verilog version 12.0 (stable) ()",
                    "path": "/usr/bin/iverilog",
                    "version_ok": True,
                    "lock_match": False,
                    "minimum_version": "12.0",
                    "locked_version": "13.0",
                    "locked_ref": None,
                    "install_mode": "managed",
                }
            ],
            "toolchain_lock": {
                "ok": True,
                "lock_version": "3",
                "sha256": "abc",
                "expected": {},
            },
        },
    )
    monkeypatch.setattr(manifest, "_git", lambda root, *args: "deadbeef" if args[:2] == ("rev-parse", "HEAD") else "")
    monkeypatch.setattr(manifest, "_flexsoc_version", lambda root: "0.test")
    data = manifest.collect_manifest(top="demo", run_top="demo", run_id="dev", repo_root=tmp_path)
    assert data["schema_version"] == 5
    assert data["tools"]["iverilog"]["version_ok"] is True
    assert data["tools"]["iverilog"]["lock_match"] is False
    assert data["tools"]["iverilog"]["locked_version"] == "13.0"
