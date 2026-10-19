"""Packet runner extension is explicit and never turns unrun tests into PASS."""
from pathlib import Path
import ast

ROOT = Path(__file__).resolve().parents[2]
PACKAGE = ROOT / "hw/ips/ethernet/0.1.0/interfaces/tlul/dv/functional/py/rtl"


def test_packet_suite_is_real_and_restricted():
    tree = ast.parse((PACKAGE / "ethernet_packet_test.py").read_text())
    classes = {node.name for node in tree.body if isinstance(node, ast.ClassDef)}
    assert {"RxScoreboard", "PhyRxDriver", "EthernetPacketTest", "PhyTxDriver", "PhyTxMonitor", "TxScoreboard"} <= classes
    text = (PACKAGE / "ethernet_packet_test.py").read_text()
    assert "assert_valid_frame(expect_error=" in text
    assert "apply_reg(dut, \"CTRL\", 2)" in text
    assert "gmii_bad_fcs" in text
    assert "gmii_ifg_20" in text


def test_plugin_staging_is_opt_in():
    from flexsoc.backend.dv.tb.cocotb import CocotbTestbench
    import inspect
    src = inspect.getsource(CocotbTestbench._write)
    assert 'CocotbPluginManifest(manifest).sources()' in src
    assert 'files[target] = ""' in src
