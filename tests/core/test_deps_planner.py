from __future__ import annotations

import os
import subprocess
from pathlib import Path
from types import SimpleNamespace


ROOT = Path(__file__).resolve().parents[2]
DEPS = ROOT / "src/flexsoc/backend/core/runtime/deps.sh"
LOCK = ROOT / "src/flexsoc/backend/core/runtime/toolchain.lock"


FAKE_TOOL = r'''#!/usr/bin/env bash
set -euo pipefail
name=$(basename "$0")
case "$name" in
  verilator) echo "Verilator $FAKE_VERILATOR_VERSION" ;;
  slang) echo "slang version $FAKE_SLANG_VERSION" ;;
  slang-hier) echo "slang-hier $FAKE_SLANG_VERSION" ;;
  verible-verilog-syntax|verible-verilog-lint) echo "$FAKE_VERIBLE_VERSION" ;;
  iverilog) echo "Icarus Verilog version $FAKE_IVERILOG_VERSION" ;;
  yosys-config) echo "Yosys $FAKE_YOSYS_VERSION" ;;
  yosys)
    if [[ "${1-}" == "-V" ]]; then
      if [[ "${FAKE_YOSYS_MISMATCH:-0}" == 1 ]]; then
        echo "Yosys 0.0 (git sha1 deadbee, Release)"
      else
        echo "Yosys $FAKE_YOSYS_VERSION (git sha1 $FAKE_YOSYS_REF, Release)"
      fi
    fi
    ;;
  sby) echo "SBY v$FAKE_SBY_VERSION" ;;
  eqy) echo "EQY v$FAKE_EQY_VERSION" ;;
  bitwuzla) echo "Bitwuzla $FAKE_BITWUZLA_VERSION" ;;
  boolector) echo "Boolector $FAKE_BOOLECTOR_VERSION" ;;
  btormc|btorsim) echo "$name" ;;
  sta) echo "OpenSTA $FAKE_OPENSTA_VERSION" ;;
  gtkwave) echo "GTKWave Analyzer v$FAKE_GTKWAVE_VERSION" ;;
  fst2vcd) echo "fst2vcd" ;;
  surfer) echo "surfer $FAKE_SURFER_VERSION" ;;
  sv2v) echo "sv2v $FAKE_SV2V_VERSION" ;;
  netlistsvg) echo "$FAKE_NETLISTSVG_VERSION" ;;
  *) exit 2 ;;
esac
'''


def _lock_values() -> dict[str, str]:
    values: dict[str, str] = {}
    for raw in LOCK.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, value = line.split("=", 1)
        values[key] = value.strip().strip('"')
    return values


def _fake_bin(tmp_path: Path) -> Path:
    bindir = tmp_path / "bin"
    bindir.mkdir()
    driver = bindir / "fake-tool"
    driver.write_text(FAKE_TOOL, encoding="utf-8")
    driver.chmod(0o755)
    for name in (
        "verilator", "slang", "slang-hier", "verible-verilog-syntax",
        "verible-verilog-lint", "iverilog", "yosys", "yosys-config", "sby", "eqy",
        "bitwuzla", "boolector", "btormc", "btorsim", "sta", "gtkwave",
        "fst2vcd", "surfer", "netlistsvg",
    ):
        (bindir / name).symlink_to(driver.name)
    plugins = bindir.parent / "share" / "yosys" / "plugins"
    plugins.mkdir(parents=True)
    for name in ("eqy_combine.so", "eqy_partition.so", "eqy_recode.so"):
        (plugins / name).write_bytes(b"fixture")
    return bindir


def _plan(tmp_path: Path, *, yosys_mismatch: bool = False) -> str:
    bindir = _fake_bin(tmp_path)
    lock = _lock_values()
    env = os.environ.copy()
    env.update({
        "HOME": str(tmp_path / "home"),
        "PATH": f"{bindir}:{env['PATH']}",
        "FLEXSOC_TOOLCHAIN_LOCK": str(LOCK),
        "FLEXSOC_TOOLCHAIN_ROOT": str(tmp_path / "toolchains"),
        "FLEXSOC_CACHE_HOME": str(tmp_path / "cache"),
        "FAKE_YOSYS_MISMATCH": "1" if yosys_mismatch else "0",
    })
    for key in (
        "VERILATOR", "SLANG", "VERIBLE", "IVERILOG", "YOSYS", "SBY", "EQY",
        "BITWUZLA", "BOOLECTOR", "OPENSTA", "GTKWAVE", "SURFER", "SV2V", "NETLISTSVG",
    ):
        env[f"FAKE_{key}_VERSION"] = lock[f"{key}_VERSION"]
    env["FAKE_YOSYS_REF"] = lock["YOSYS_REF"][:7]
    result = subprocess.run(
        ["bash", str(DEPS), "plan", "--user"],
        cwd=ROOT,
        env=env,
        text=True,
        capture_output=True,
        check=True,
    )
    return result.stdout


def test_yosys_formal_family_is_locked_to_release_069() -> None:
    lock = _lock_values()

    assert lock["YOSYS_VERSION"] == "0.69"
    assert lock["YOSYS_REF"] == "9f75ca1f9834a39a863915b5dae0c7b1e33533bc"
    assert lock["SBY_VERSION"] == "0.69"
    assert lock["SBY_REF"] == "b1a1e98cba941ec8433f8dc27f416cd7bb7f14be"
    assert lock["EQY_VERSION"] == "0.69"
    assert lock["EQY_REF"] == "4a72eb94fc253062464afee4d0018359017bb846"


def test_plan_reuses_exact_external_tools_without_fetching(tmp_path: Path) -> None:
    output = _plan(tmp_path)

    assert "verilator    reuse    external" in output
    assert "yosys        reuse    external" in output
    assert "sby          reuse    external" in output
    assert "eqy          reuse    external" in output
    assert "install  family" not in output
    assert "sv2v" not in output
    assert "slang" in output


def test_yosys_family_moves_together_when_one_member_mismatches(tmp_path: Path) -> None:
    output = _plan(tmp_path, yosys_mismatch=True)

    assert "yosys        install  family" in output
    assert "sby          install  family" in output
    assert "eqy          install  family" in output
    assert output.count("Yosys/SBY/EQY family must move together") == 3


def test_toolchain_dependency_request_preserves_mode_and_prune_cache(tmp_path: Path) -> None:
    from flexsoc.backend.core import Toolchain

    class Runner:
        def __init__(self) -> None:
            self.requests = []

        def run(self, request, *, on):
            self.requests.append((request, on))
            return SimpleNamespace(returncode=0)

    runner = Runner()
    toolchain = Toolchain(tmp_path, runner=runner)

    assert toolchain.deps("plan", mode="system", profile="base", jobs=3) == 0
    request, on = runner.requests[-1]
    assert on == "local"
    assert request.argv[-6:] == ("plan", "--system", "--profile", "base", "--jobs", "3")
    assert request.line_callback is not None

    assert toolchain.deps("install", mode="user", profile="base") == 0
    request, _ = runner.requests[-1]
    assert request.line_callback is not None

    assert toolchain.deps("prune", mode="user", profile="base", apply=True, prune_cache=True) == 0
    request, _ = runner.requests[-1]
    assert "--user" in request.argv
    assert "--apply" in request.argv
    assert "--cache" in request.argv
    assert "--prune-cache" not in request.argv

def test_gtkwave_user_install_disables_global_desktop_database_updates() -> None:
    source = DEPS.read_text(encoding="utf-8")

    assert './configure --enable-gtk3 --disable-mime-update --prefix="$PREFIX"' in source


def test_dependency_progress_stream_is_concise(capsys, tmp_path: Path) -> None:
    from flexsoc.backend.core import Toolchain

    toolchain = Toolchain(tmp_path)
    toolchain._stream_dependency_progress("make[1]: compiling lots of files\n")
    toolchain._stream_dependency_progress("[deps] build yosys 0.69\n")
    toolchain._stream_dependency_progress("make: *** [target] Error 2\n")

    assert capsys.readouterr().out == "[deps] build yosys 0.69\nmake: *** [target] Error 2\n"

