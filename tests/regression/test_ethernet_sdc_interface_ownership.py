"""Native Ethernet PHY timing intent: prohibit incorrect core blanket delays.

This is a contract regression, not an STA or clock-mux signoff test.
"""
from pathlib import Path
import json
import hashlib


def test_ethernet_sdc_does_not_assign_phy_to_core_clock():
    root = Path(__file__).resolve().parents[2]
    package = root / "hw/ips/ethernet/0.1.0/interfaces/tlul"
    sdc = (package / "constraints/ethernet.sdc").read_text()
    active = [line.strip() for line in sdc.splitlines() if line.strip() and not line.lstrip().startswith("#")]
    assert len([line for line in active if line.startswith("create_clock ")]) == 4
    assert not any("$non_clock_inputs" in line or "[all_outputs]" in line for line in active if line.startswith(("set_input_delay", "set_output_delay")))
    assert not any(line.startswith(("set_input_delay", "set_output_delay")) for line in active)
    assert "MII 10 (mii_tx=400 ns)" in sdc
    assert "glitch-free" in sdc
    contract = json.loads((package / "meta/contract.json").read_text())
    sha = hashlib.sha256(sdc.encode()).hexdigest()
    entries = [x for x in contract["source_of_truth"]["constraints"] if x["path"] == "constraints/ethernet.sdc"]
    assert len(entries) == 1 and entries[0]["sha256"] == sha
