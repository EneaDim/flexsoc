from __future__ import annotations

from pathlib import Path


def test_freeze_rtl_dependencies_makes_release_self_contained(tmp_path: Path) -> None:
    from flexsoc.backend.release.package import PackageFlow

    project = tmp_path / "project"
    common = project / "hw" / "ips" / "pkgs"
    common.mkdir(parents=True)
    (common / "defs.svh").write_text("`define DEMO 1\n", encoding="utf-8")
    (common / "pkg.sv").write_text("package demo_pkg; endpackage\n", encoding="utf-8")
    vendor = project / "vendor" / "demo"
    vendor.mkdir(parents=True)
    (vendor / "dep.sv").write_text("module dep(); endmodule\n", encoding="utf-8")

    release = project / "release"
    rtl = release / "rtl"
    rtl.mkdir(parents=True)
    (rtl / "demo.sv").write_text("module demo(); endmodule\n", encoding="utf-8")
    (rtl / "rtl_common.f").write_text(
        "+incdir+hw/ips/pkgs\nhw/ips/pkgs/pkg.sv\nvendor/demo/dep.sv\n",
        encoding="utf-8",
    )
    (rtl / "rtl_ip.f").write_text("rtl/demo.sv\n", encoding="utf-8")

    PackageFlow._freeze_rtl_dependencies(release, project)
    PackageFlow._validate_frozen_filelists(release)
    common_text = (rtl / "rtl_common.f").read_text(encoding="utf-8")
    assert "+incdir+hw/ips/pkgs" in common_text
    assert "hw/ips/pkgs/pkg.sv" in common_text
    assert "vendor/demo/dep.sv" in common_text
    assert (release / "hw/ips/pkgs/defs.svh").is_file()
    assert (release / "vendor/demo/dep.sv").is_file()

    core = PackageFlow._write_fusesoc_core(release, "demo", "demo")
    assert core is not None
    text = core.read_text(encoding="utf-8")
    assert "ips:dependecies:all" not in text
    assert "hw/ips/pkgs/pkg.sv" in text
    assert "vendor/demo/dep.sv" in text
    assert "is_include_file: true" in text
    assert "include_path: hw/ips/pkgs" in text


def test_staged_release_rejects_external_filelist_paths(tmp_path: Path) -> None:
    from flexsoc.backend.release.package import PackageFlow

    release = tmp_path / "release"
    rtl = release / "rtl"
    rtl.mkdir(parents=True)
    (rtl / "rtl_common.f").write_text("/tmp/external.sv\n", encoding="utf-8")
    (rtl / "rtl_ip.f").write_text("", encoding="utf-8")
    try:
        PackageFlow._validate_frozen_filelists(release)
    except ValueError as exc:
        assert "non-self-contained IP release" in str(exc)
    else:
        raise AssertionError("external filelist path must be rejected")

def test_freeze_lowrisc_tlul_sources_becomes_explicit_core_dependencies(tmp_path: Path) -> None:
    from flexsoc.backend.release.package import PackageFlow

    project = tmp_path / "project"
    vendor = project / "vendor" / "lowrisc_ip" / "ip" / "tlul" / "rtl"
    vendor.mkdir(parents=True)
    for name in ("tlul_pkg.sv", "tlul_data_integ_enc.sv", "tlul_adapter_reg.sv"):
        (vendor / name).write_text(f"// {name}\n", encoding="utf-8")
    release = project / "release"
    rtl = release / "rtl"
    rtl.mkdir(parents=True)
    (rtl / "demo.sv").write_text("module demo(); endmodule\n", encoding="utf-8")
    (rtl / "rtl_common.f").write_text(
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv\n"
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_data_integ_enc.sv\n"
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_adapter_reg.sv\n",
        encoding="utf-8",
    )
    (rtl / "rtl_ip.f").write_text("rtl/demo.sv\n", encoding="utf-8")

    PackageFlow._freeze_rtl_dependencies(release, project)
    PackageFlow._validate_frozen_filelists(release)
    lines = (rtl / "rtl_common.f").read_text(encoding="utf-8").splitlines()
    assert lines == [
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv",
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_data_integ_enc.sv",
        "vendor/lowrisc_ip/ip/tlul/rtl/tlul_adapter_reg.sv",
    ]
    assert not (rtl / "fusesoc_deps.txt").exists()
    assert all((release / line).is_file() for line in lines)
    core = PackageFlow._write_fusesoc_core(release, "demo", "demo")
    text = core.read_text(encoding="utf-8")
    assert "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv" in text
    assert "lowrisc:tlul:common" not in text
    # The staged release remains valid after relocation outside the project tree.
    moved = tmp_path / "different_mount" / "demo"
    moved.parent.mkdir()
    release.rename(moved)
    PackageFlow._validate_frozen_filelists(moved)
    assert (moved / "vendor/lowrisc_ip/ip/tlul/rtl/tlul_pkg.sv").is_file()



def test_freeze_migrates_legacy_run_dependencies(tmp_path: Path) -> None:
    from flexsoc.backend.release.package import PackageFlow

    project = tmp_path / "project"
    release = project / "release"
    rtl = release / "rtl"
    legacy = rtl / "deps" / "flexsoc" / "hw" / "ips" / "prim"
    legacy.mkdir(parents=True)
    (legacy / "prim_ff_2sync.sv").write_text("module prim_ff_2sync; endmodule\n", encoding="utf-8")
    (rtl / "gpio.sv").write_text("module gpio; endmodule\n", encoding="utf-8")
    (rtl / "rtl_common.f").write_text(
        "rtl/deps/flexsoc/hw/ips/prim/prim_ff_2sync.sv\n", encoding="utf-8"
    )
    (rtl / "rtl_ip.f").write_text("rtl/gpio.sv\n", encoding="utf-8")

    PackageFlow._freeze_rtl_dependencies(release, project)
    PackageFlow._validate_frozen_filelists(release)
    assert (release / "hw/ips/prim/prim_ff_2sync.sv").is_file()
    assert not (rtl / "deps").exists()
    assert (rtl / "rtl_common.f").read_text(encoding="utf-8").strip() == (
        "hw/ips/prim/prim_ff_2sync.sv"
    )
