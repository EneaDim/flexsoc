"""A source baseline must never inherit frozen L2/L3/L4 outcomes."""
from __future__ import annotations

import shutil
from pathlib import Path

import pytest

from flexsoc.backend.release.package import PackageFlow


ROOT = Path(__file__).resolve().parents[2]


@pytest.mark.parametrize("ip", ("gpio", "uart", "rv_timer", "uart_master"))
def test_requalification_load_is_explicit_and_unqualified(ip: str, tmp_path: Path) -> None:
    flow = PackageFlow(ROOT, {})
    args = dict(ip_name=ip, reg_interface="tlul", run_top=ip, run_id="l2", version="1.0.0", workspace=tmp_path)
    with pytest.raises(ValueError, match="IP-level spec fingerprint"):
        flow.load(**args)
    loaded = flow.load(**args, requalify=True)
    assert (loaded / "spec" / "customer.md").is_file()
    assert (loaded / "dv" / "functional" / "py" / f"{ip}_model_tests.py").is_file()
    assert (loaded / "rtl" / "rtl_ip.f").is_file()
    assert (loaded / "csr" / f"{ip}.hjson").is_file()
    assert not (loaded / "meta" / "contract.json").exists()
    assert not (loaded / "ip.json").exists()
    assert not (loaded / "dv" / "lint" / "summary.json").exists()
    assert not (loaded / "dv" / "cdc_rdc" / "summary.json").exists()
    assert not (loaded / "dv" / "functional" / "regression" / "summary.json").exists()
    assert not (loaded / "syn").exists()
    assert not (loaded / "signoff").exists()
    assert (loaded / "dv" / "formal" / "properties").is_dir()
    with pytest.raises(ValueError, match="fresh run"):
        flow.load(**args, requalify=True)


def test_requalification_never_ignores_modified_hardware_source(tmp_path: Path) -> None:
    source = ROOT / "hw" / "ips" / "gpio" / "1.0.0"
    project = tmp_path / "checkout"
    release = project / "hw" / "ips" / "gpio" / "1.0.0"
    shutil.copytree(source, release)
    reg = release / "interfaces" / "tlul" / "csr" / "gpio.hjson"
    reg.write_text(reg.read_text(encoding="utf-8") + "\n// unexpected mutation\n", encoding="utf-8")
    with pytest.raises(ValueError, match="source-of-truth artifact is stale"):
        PackageFlow(project, {}).load(ip_name="gpio", reg_interface="tlul", version="1.0.0", run_top="gpio", run_id="l2", workspace=tmp_path / "runs", requalify=True)
    assert not (tmp_path / "runs" / "runs" / "gpio" / "l2" / "rtl").exists()
