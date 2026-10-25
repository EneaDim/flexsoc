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
    # Fixture integrity is not a property of the IP name: frozen releases
    # may be clean or stale depending on the checked-out source inventory.
    # Requalification must be supported independently of frozen evidence.
    loaded = flow.load(**args, requalify=True)
    assert (loaded / "spec" / "customer.md").is_file()
    model_tests = loaded / "dv" / "functional" / "py" / "model" / f"{ip}_model_tests.py"
    assert model_tests.is_file()
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
    assert flow.load(**args, requalify=True) == loaded


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


def test_force_reload_existing_uart_run(tmp_path: Path) -> None:
    """Repeated force loads replace old evidence without changing the run identity."""
    flow = PackageFlow(ROOT, {})
    args = dict(ip_name="uart", reg_interface="tlul", run_top="uart", run_id="l2_uart",
                version="1.0.0", workspace=tmp_path, requalify=True)
    run = flow.load(**args)
    (run / "meta").mkdir(exist_ok=True)
    (run / "meta" / "settings.json").write_text("{}", encoding="utf-8")
    (run / "meta" / "qualification.json").write_text("old", encoding="utf-8")
    (run / "rtl" / "old.sv").write_text("old", encoding="utf-8")
    (run / "logs").mkdir(exist_ok=True)
    (run / "logs" / "commands.log").write_text("keep", encoding="utf-8")

    assert flow.load(**args) == run
    assert (run / "csr" / "uart.hjson").is_file()
    assert not (run / "rtl" / "old.sv").exists()
    assert not (run / "meta" / "qualification.json").exists()
    assert (run / "meta" / "settings.json").read_text(encoding="utf-8") == "{}"
    assert (run / "logs" / "commands.log").read_text(encoding="utf-8") == "keep"
