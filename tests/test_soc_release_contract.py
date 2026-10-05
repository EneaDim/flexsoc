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
    assert "+incdir+rtl/deps/flexsoc/pkgs" in common_text
    assert "rtl/deps/flexsoc/pkgs/pkg.sv" in common_text
    assert "rtl/deps/flexsoc/vendor/demo/dep.sv" in common_text
    assert (release / "rtl/deps/flexsoc/pkgs/defs.svh").is_file()
    assert (release / "rtl/deps/flexsoc/vendor/demo/dep.sv").is_file()

    core = PackageFlow._write_fusesoc_core(release, "demo", "demo")
    assert core is not None
    text = core.read_text(encoding="utf-8")
    assert "ips:dependecies:all" not in text
    assert "rtl/deps/flexsoc/pkgs/pkg.sv" in text
    assert "rtl/deps/flexsoc/vendor/demo/dep.sv" in text
    assert "is_include_file: true" in text
    assert "include_path: rtl/deps/flexsoc/pkgs" in text


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
    assert (rtl / "rtl_common.f").read_text(encoding="utf-8").strip() == ""
    deps = (rtl / "fusesoc_deps.txt").read_text(encoding="utf-8").splitlines()
    assert deps == ["lowrisc:tlul:common", "lowrisc:tlul:adapter_reg"]
    core = PackageFlow._write_fusesoc_core(release, "demo", "demo")
    text = core.read_text(encoding="utf-8")
    assert "- lowrisc:tlul:common" in text
    assert "- lowrisc:tlul:adapter_reg" in text
    assert "vendor/lowrisc_ip" not in text
