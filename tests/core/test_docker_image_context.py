"""Regression tests for pinned FlexSoC Docker build-context paths.

No Docker daemon, network or EDA binaries required.
"""
from pathlib import Path
import hashlib
import re
import shlex
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[2]
BASE = "src/flexsoc/backend/core/runtime"


def _shell(script: str, *, cwd: Path = ROOT) -> str:
    p = subprocess.run(["bash", "-c", script], cwd=cwd, text=True,
                       capture_output=True, check=True)
    return p.stdout.strip()


def test_toolchain_files_and_docker_copy_paths():
    for file in ("deps.sh", "toolchain.lock"):
        assert (ROOT / BASE / file).is_file()
    dockerfile = (ROOT / "docker/ci/Dockerfile").read_text()
    common = (ROOT / "docker/scripts/common.sh").read_text()
    for file in ("deps.sh", "toolchain.lock"):
        assert f"{BASE}/{file}" in dockerfile
        assert f"{BASE}/{file}" in common
        assert f"src/flexsoc/backend/core/{file}" not in dockerfile
        assert f"src/flexsoc/backend/core/{file}" not in common
    # All direct COPY sources must exist in the repository's build context.
    for line in dockerfile.splitlines():
        line = line.strip()
        if not line.startswith("COPY ") or line.startswith("COPY --from="):
            continue
        fields = shlex.split(line)[1:]
        assert len(fields) >= 2
        for source in fields[:-1]:
            assert (ROOT / source).exists(), f"unresolvable Docker COPY: {source}"
    ignore = (ROOT / "docker/ci/Dockerfile.dockerignore").read_text()
    assert BASE not in ignore


def test_shell_paths_and_fingerprint():
    common = ROOT / "docker/scripts/common.sh"
    subprocess.run(["bash", "-n", str(common)], check=True)
    subprocess.run(["bash", "-n", str(ROOT / BASE / "deps.sh")], check=True)
    cmd = (f'source "{common}"; '
           'test -s "$TOOLCHAIN_LOCK"; test -s "$DEPS_SCRIPT"; '
           'inputs_sha256')
    got = _shell(cmd)
    assert re.fullmatch(r"[a-f0-9]{64}", got)
    files = _shell(f'source "{common}"; image_input_files').splitlines()
    assert f"{BASE}/deps.sh" in files
    assert f"{BASE}/toolchain.lock" in files
    assert all((ROOT / f).is_file() for f in files)


def test_lock_change_invalidates_image_digest(tmp_path):
    common = ROOT / "docker/scripts/common.sh"
    files = _shell(f'source "{common}"; image_input_files').splitlines()
    for relative in files:
        dest = tmp_path / relative
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(ROOT / relative, dest)
    command = (f'source "{common}"; REPO_ROOT="{tmp_path}"; inputs_sha256')
    before = _shell(command)
    with (tmp_path / BASE / "toolchain.lock").open("a") as handle:
        handle.write("\n# test-only invalidation\n")
    after = _shell(command)
    assert re.fullmatch(r"[a-f0-9]{64}", after)
    assert before != after


def test_workflow_build_verify_publish_lock_then_ci():
    text = (ROOT / ".github/workflows/toolchain-image.yml").read_text()
    labels = [
        "Validate build-context toolchain inputs",
        "Check frozen toolchain image",
        "Build toolchain image",
        "Verify toolchain image",
        "Publish and freeze toolchain image",
        "Commit image lock",
        "Dispatch project CI on frozen image",
    ]
    pos = [text.index(label) for label in labels]
    assert pos == sorted(pos)
    assert 'gh workflow run ci.yml --ref "$BRANCH"' in text
    assert "github.actor != 'github-actions[bot]'" in text
    ci = (ROOT / ".github/workflows/ci.yml").read_text()
    assert 'validate_lock' in ci
    assert 'steps.image.outputs.ref' in ci
