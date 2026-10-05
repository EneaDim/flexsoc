from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def test_soc_declares_tlul_socket_for_generated_crossbar() -> None:
    text = (ROOT / "src/flexsoc/templates/design/soc/soc.core.j2").read_text(encoding="utf-8")
    assert "- lowrisc:tlul:socket_1n" in text


def test_uart_release_uses_fusesoc_ownership_not_mirror_copies() -> None:
    release = ROOT / "hw/ips/uart/1.0.0/interfaces/tlul"
    common = (release / "rtl/rtl_common.f").read_text(encoding="utf-8")
    core = (release / "uart.core").read_text(encoding="utf-8")
    assert "rtl/deps/flexsoc/prim_opentitan/" not in common
    assert "rtl/deps/flexsoc/pkgs/" not in common
    assert "rtl/deps/flexsoc/prim/prim_ff_2sync.sv" in common
    assert "lowrisc:prim:flop" in core
    assert "lowrisc:prim:subreg" in core
    assert "lowrisc:prim:fifo" in core
    assert "lowrisc:prim:secded" in core
    assert "lowrisc:constants:top_pkg" in core


def test_package_mapper_keeps_flexsoc_prim_local() -> None:
    from flexsoc.backend.release.package import PackageFlow

    assert PackageFlow._fusesoc_dependency_for_external_source(
        ROOT / "hw/ips/prim_opentitan/prim_flop.sv", ROOT
    ) == "lowrisc:prim:flop"
    assert PackageFlow._fusesoc_dependency_for_external_source(
        ROOT / "hw/ips/pkgs/prim_subreg_pkg.sv", ROOT
    ) == "lowrisc:prim:subreg"
    assert PackageFlow._fusesoc_dependency_for_external_source(
        ROOT / "hw/ips/prim/prim_ff_2sync.sv", ROOT
    ) is None

def test_checkout_path_alone_does_not_imply_lowrisc_ownership(tmp_path: Path) -> None:
    from flexsoc.backend.release.package import PackageFlow

    project = tmp_path / "project"
    pkgs = project / "hw" / "ips" / "pkgs"
    pkgs.mkdir(parents=True)
    package = pkgs / "prim_subreg_pkg.sv"
    package.write_text("package local_pkg; endpackage\n", encoding="utf-8")

    assert PackageFlow._fusesoc_dependency_for_external_source(package, project) is None
    assert PackageFlow._is_external_mirror_include_dir(pkgs, project) is False

