from __future__ import annotations

from pathlib import Path

from flexsoc.backend.manifest import collect_manifest


def test_manifest_lists_only_existing_artifact_directories(
    tmp_path: Path, monkeypatch,
) -> None:
    run = tmp_path / "runs" / "demo" / "dev"
    syn = run / "syn" / "sky130"
    syn.mkdir(parents=True)
    monkeypatch.setenv("FLEXSOC_PDK", "sky130")
    monkeypatch.setenv("FLEXSOC_RUN_ROOT", str(run))

    data = collect_manifest(
        top="demo",
        run_top="demo",
        run_id="dev",
        repo_root=tmp_path,
    )

    artifacts = data["run"]["artifacts"]
    assert isinstance(artifacts, dict)
    assert artifacts == {"synthesis": str(syn.resolve())}
