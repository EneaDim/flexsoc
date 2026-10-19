"""Ethernet native 0.1.0 can be loaded without historical build directories."""
import json
from pathlib import Path


def test_ethernet_package_standalone_references():
    root = Path(__file__).resolve().parents[2] / 'hw/ips/ethernet/0.1.0/interfaces/tlul'
    manifest = json.loads((root / 'ip.json').read_text())
    assert manifest['qualification']['technologies'] == {}
    assert manifest['qualification']['summary']['maximum_level'] == 1
    assert manifest['qualification']['summary']['maximum_qualification'] == 'Contract Valid'
    for relative in ('rtl/rtl_ip.f', 'ethernet.core'):
        content = (root / relative).read_text()
        assert 'workspace/ethernet_migration' not in content
        assert 'rtl/deps/flexsoc/workspace/' not in content
    for line in (root / 'rtl/rtl_ip.f').read_text().splitlines():
        if not line.strip() or line.lstrip().startswith('#'):
            continue
        assert not Path(line.strip()).is_absolute()
        assert (root / line.strip()).is_file(), line
