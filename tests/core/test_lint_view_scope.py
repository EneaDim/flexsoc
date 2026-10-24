"""Lint ownership and classification used by show and JSON views."""

from flexsoc.backend.dv.lint.lint import Lint


def test_scope_classification_and_ownership():
    assert Lint._scope("rtl/gpio.sv") == "ip"
    assert Lint._scope("hw/ips/prim/prim_ff_2sync.sv") == "common"
    assert Lint._scope("vendor/lowrisc/tlul.sv") == "common"
    assert Lint._scope("soc/soc_top.sv") == "soc"
    assert Lint._owner("hw/ips/gpio/rtl/gpio.sv", "soc_top") == "gpio"
    assert Lint._owner("rtl/gpio.sv", "gpio") == "gpio"


def test_scope_grouping():
    diagnostics = [
        {"scope": "common", "priority": "P1", "type": "UNUSED", "owner": "gpio"},
        {"scope": "ip", "priority": "P0", "type": "WIDTH", "owner": "gpio"},
        {"scope": "ip", "priority": "P2", "type": "WIDTH", "owner": "uart"},
    ]
    scopes = Lint._scope_counts(diagnostics)
    assert scopes["common"]["counts"]["P1"] == 1
    assert scopes["ip"]["types"]["WIDTH"] == 2
    assert scopes["ip"]["owners"] == {"gpio": 1, "uart": 1}
    assert scopes["soc"]["total"] == 0


def test_show_filters_existing_lint_report(tmp_path, capsys):
    import json
    from types import SimpleNamespace

    from flexsoc.backend.core.render.show import ShowDocument, ShowRenderer

    path = tmp_path / "dv/lint/summary.json"
    path.parent.mkdir(parents=True)
    data = {
        "status": "PASS", "top": "gpio", "profile": "everything",
        "order": ["slang"], "tools": {"slang": {"status": "PASS", "total": 2}},
        "diagnostics": [
            {"tool": "slang", "priority": "P0", "code": "WIDTH", "file": "rtl/gpio.sv"},
            {"tool": "slang", "priority": "P1", "code": "UNUSED", "file": "hw/ips/prim/prim_ff_2sync.sv"},
        ],
    }
    path.write_text(json.dumps(data))
    lint = object.__new__(Lint)
    lint.context = SimpleNamespace(paths=SimpleNamespace(run=tmp_path, lint=path.parent), project_root=tmp_path)
    assert lint.show(scope="common", warning_type="UNUSED", priority="all", as_json=True) == 0
    result = json.loads(capsys.readouterr().out)
    assert result["visible_total"] == 1
    assert result["diagnostics"][0]["scope"] == "common"
    assert result["diagnostics"][0]["type"] == "UNUSED"
    assert lint.show(scope="soc", priority="all", as_json=True) == 0
    assert json.loads(capsys.readouterr().out)["visible_total"] == 0
