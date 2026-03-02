from pathlib import Path
import yaml

def test_registry_loads():
    reg_path = Path("src/flexsoc/registry.yaml")
    data = yaml.safe_load(reg_path.read_text(encoding="utf-8"))
    assert "actions" in data
    assert "lint" in data["actions"]
