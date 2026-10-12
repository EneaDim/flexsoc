from pathlib import Path


def test_ibex_vendor_pin_remains_pristine() -> None:
    root = Path(__file__).resolve().parents[3]
    manifest = (root / "vendor/lowrisc_ibex.vendor.hjson").read_text(encoding="utf-8")
    patch = root / "vendor/patches/lowrisc_ibex/0001-ibex-top-unused-scramble-continuous-assign.patch"

    assert 'rev: "78739562ce7b2606c4e208d4029ab890255769f6",' in manifest
    assert 'patch_dir: "patches/lowrisc_ibex",' not in manifest
    assert not patch.exists()

    vendor_top = root / "vendor/lowrisc_ibex/rtl/ibex_top.sv"
    if vendor_top.is_file():
        source = vendor_top.read_text(encoding="utf-8")
        assert "logic unused_scramble_inputs = scramble_key_valid_i" in source
        assert "assign unused_scramble_inputs =" not in source
