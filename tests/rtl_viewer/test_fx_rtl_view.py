"""The public viewer target follows the active FlexSoC run, not a hardcoded IP."""
import json
from types import SimpleNamespace
from unittest.mock import Mock

import pytest

from flexsoc.api import TARGETS
from flexsoc.backend.core.flow.target import BACKEND_TARGETS
from flexsoc.backend.dv.rtl_viewer import launch


def test_public_target_is_registered():
    assert "rtl_view" in TARGETS
    assert BACKEND_TARGETS["rtl_view"].action == "rtl_view"
    assert BACKEND_TARGETS["rtl_view"].domain == "dv"


def test_viewer_uses_configured_top_and_run(tmp_path, monkeypatch):
    root = tmp_path
    run = root / "workspace" / "runs" / "my_ip" / "r2"
    rtl = run / "rtl"
    rtl.mkdir(parents=True)
    (rtl / "my_ip.sv").write_text("module my_ip; endmodule\n")
    ast_dir = run / "dv" / "slang_hier"
    ast_dir.mkdir(parents=True)
    (ast_dir / "ast.json").write_text(json.dumps({"design": {"kind": "Root", "members": [
        {"kind": "Instance", "name": "my_ip", "body": {"kind": "InstanceBody", "name": "my_ip", "members": []}}
    ]}}))
    context = SimpleNamespace(project_root=root, values={"IP_NAME": "my_ip"},
                              paths=SimpleNamespace(top="my_ip", run=run, slang_hier=ast_dir))
    hierarchy = Mock()
    hierarchy.run.return_value = 0
    created = []

    class DummyServer:
        server_port = 12345
        def __init__(self, address, design):
            created.append((address, design))
        def serve_forever(self):
            raise KeyboardInterrupt
        def server_close(self):
            pass

    monkeypatch.setattr(launch, "ViewerServer", DummyServer)
    # Detached serving is the current contract. Never fork a test child process.
    from flexsoc.backend.dv.rtl_viewer import background
    detached = Mock()
    monkeypatch.setattr(background, "serve_detached", detached)
    # Headless/WSL-disabled mode must not attempt a Windows browser launch.
    monkeypatch.setenv("FLEXSOC_RTL_NO_BROWSER", "1")
    browser = Mock(return_value=True)
    monkeypatch.setattr(launch.webbrowser, "open", browser)
    assert launch.open_viewer(context, hierarchy) == 0
    assert created[0][1].top == "my_ip"
    assert created[0][1].verified
    detached.assert_called_once()
    args, kwargs = detached.call_args
    assert args[0].server_port == 12345
    assert kwargs["run"] == run
    assert kwargs["url"] == "http://127.0.0.1:12345/"
    browser.assert_not_called()
    hierarchy.run.assert_called_once_with(on="local")


def test_missing_top_does_not_launch(tmp_path):
    context = SimpleNamespace(project_root=tmp_path, values={},
                              paths=SimpleNamespace(top="absent", run=tmp_path, slang_hier=tmp_path))
    hierarchy = Mock()
    with pytest.raises(FileNotFoundError, match="configured RTL top"):
        launch.open_viewer(context, hierarchy)
    hierarchy.run.assert_not_called()
