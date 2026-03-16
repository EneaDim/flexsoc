from flexsoc.catalog.registry import load_registry


def test_registry_loads():
    data = load_registry()
    assert "actions" in data
    assert "lint" in data["actions"]
