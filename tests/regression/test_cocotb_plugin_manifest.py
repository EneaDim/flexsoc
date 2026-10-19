"""Protocol-agnostic cocotb plugin staging validation."""
import json
import pytest
from flexsoc.backend.dv.tb.cocotb import CocotbPluginManifest


def test_manifest_modules_and_shared_model(tmp_path):
    rtl = tmp_path / "py" / "rtl"
    model = tmp_path / "py" / "model"
    rtl.mkdir(parents=True)
    model.mkdir(parents=True)
    (rtl / "axi_lite_master.py").write_text("class AxiLiteMaster: pass\n")
    (model / "transactions.py").write_text("class Transaction: pass\n")
    manifest = rtl / "cocotb_plugins.json"
    manifest.write_text(json.dumps({"schema": 1, "modules": ["axi_lite_master"], "sources": ["../model/transactions.py"]}))
    assert [p.name for p in CocotbPluginManifest(manifest).sources()] == ["axi_lite_master.py", "transactions.py"]


@pytest.mark.parametrize("bad", ["../other.py", "../../etc/passwd", "x/../foo.py", "missing.py"])
def test_invalid_sources_are_rejected(tmp_path, bad):
    root = tmp_path / "rtl"
    root.mkdir()
    (root / "plugin.py").write_text("pass\n")
    manifest = root / "cocotb_plugins.json"
    manifest.write_text(json.dumps({"schema": 1, "modules": ["plugin"], "sources": [bad]}))
    with pytest.raises(ValueError):
        CocotbPluginManifest(manifest).sources()


def test_duplicate_module_fails(tmp_path):
    (tmp_path / "bus.py").write_text("pass\n")
    manifest = tmp_path / "cocotb_plugins.json"
    manifest.write_text(json.dumps({"schema": 1, "modules": ["bus", "bus"]}))
    with pytest.raises(ValueError):
        CocotbPluginManifest(manifest).sources()
