"""Functional test intent, vector generation and simulator orchestration."""

from __future__ import annotations

import ast
import random
import re
import shlex
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Sequence

from flexsoc.backend.core import ensure_dir, safe_write_file
from flexsoc.backend.core.execution import print_label, print_path_label, print_status_label

TEST_NAMES = ("smoke", "corners", "random")
WRITABLE_SWACCESS = {"rw", "wo", "w1c", "w1s", "rw1c", "rw1s", "rw0c", "rw0w1c"}
Hjson = dict[str, Any]


def _print_command(argv: Sequence[str]) -> None:
    """Print the exact external command before handing it to the runner."""

    print_label("command", shlex.join(str(item) for item in argv))


def _print_failure_tail(log: Path, *, lines: int = 40) -> None:
    """Print a compact tail immediately when one regression command fails."""

    if not log.is_file():
        return
    content = log.read_text(encoding="utf-8", errors="replace").splitlines()
    print_label("failure-tail", f"last {min(lines, len(content))} lines · {log.resolve()}")
    for line in content[-lines:]:
        print(line, flush=True)


try:
    import hjson  # type: ignore
except ImportError:  # pragma: no cover
    hjson = None

def _load_hjson(path: Path) -> Hjson:
    """Load HJSON metadata with the real parser and a tiny fallback for tests."""

    text = path.read_text(encoding="utf-8")
    if hjson is not None:
        return dict(hjson.loads(text))
    normalized = re.sub(r"([{,]\s*)([A-Za-z_][\w]*)\s*:", r'\1"\2":', text)
    normalized = re.sub(r",\s*([}\]])", r"\1", normalized).strip()
    return dict(ast.literal_eval(normalized))

def _candidate_hjson_path(rtldir: str | Path, top: str) -> Path | None:
    """Infer the copied/generated HJSON path for a run directory."""

    rtl = Path(rtldir).resolve()
    candidates = [rtl.parent / "data" / f"{top}.hjson", rtl.parent.parent / "data" / f"{top}.hjson"]
    return next((path for path in candidates if path.exists()), None)

def _hex(value: int, width: int = 8) -> str:
    """Render one zero-padded 32-bit hex value."""

    return f"0x{value & 0xFFFFFFFF:0{width}x}"

def _register_clock(hj: Hjson, reg: dict[str, Any]) -> str:
    """Return the clock-domain name used to make a register key unique."""

    value = reg.get("clock") or reg.get("clk") or reg.get("clock_primary") or hj.get("clock_primary")
    if isinstance(value, dict):
        value = value.get("name")
    if isinstance(value, (list, tuple)):
        value = value[0] if value else None
    return str(value or "clk_i")

def _is_writable_register(reg: dict[str, Any]) -> bool:
    """Return true when software can write the register or one of its fields."""

    swaccess = str(reg.get("swaccess", "")).lower()
    if swaccess in WRITABLE_SWACCESS:
        return True
    for field in reg.get("fields", []) or []:
        if isinstance(field, dict) and str(field.get("swaccess", "")).lower() in WRITABLE_SWACCESS:
            return True
    return False

def _register_entries(hjson_path: Path | None) -> list[dict[str, Any]]:
    """Return every writable register with clock-qualified names and offsets."""

    if hjson_path is None or not hjson_path.exists():
        return []
    hj = _load_hjson(hjson_path)
    entries: list[dict[str, Any]] = []
    offset = 0
    for reg in hj.get("registers", []) or []:
        if not isinstance(reg, dict) or "name" not in reg:
            continue
        current = int(str(reg.get("offset", offset)), 0) if reg.get("offset") is not None else offset
        name = str(reg["name"]).upper()
        clock = _register_clock(hj, reg)
        if _is_writable_register(reg):
            swaccess = str(reg.get("swaccess", "rw")).lower()
            entries.append(
                {
                    "name": name,
                    "clock": clock,
                    "key": f"{clock}.{name}",
                    "addr": current,
                    "swaccess": swaccess,
                }
            )
        offset = current + 4
    return entries

def _register_lookup_entries(hjson_path: Path | None) -> list[dict[str, Any]]:
    """Return all registers for vector read/write name resolution."""

    if hjson_path is None or not hjson_path.exists():
        return []

    hj = _load_hjson(hjson_path)
    entries: list[dict[str, Any]] = []
    offset = 0

    for reg in hj.get("registers", []) or []:
        if not isinstance(reg, dict) or "name" not in reg:
            continue

        current = int(str(reg.get("offset", offset)), 0) if reg.get("offset") is not None else offset
        name = str(reg["name"]).upper()
        clock = _register_clock(hj, reg)
        swaccess = str(reg.get("swaccess", "rw")).lower()

        entries.append(
            {
                "name": name,
                "clock": clock,
                "key": f"{clock}.{name}",
                "addr": current,
                "swaccess": swaccess,
            }
        )

        offset = current + 4

    return entries

def _mode_for_test(top: str, test: str) -> int:
    """Return the generated MODE.SEL value used by vector expectations."""

    if test == "corners":
        return 1
    if test == "random":
        return random.Random(f"{top}:{test}:mode").randrange(3)
    return 0

def _config_value(test: str, reg: dict[str, Any], index: int, *, top: str) -> int:
    """Choose a deterministic register value for one generated test."""

    name = str(reg["name"])
    fixed = {"CTRL": 0x3, "MODE": _mode_for_test(top, test), "SCALE": 1}
    if name in fixed:
        return fixed[name]
    if test == "corners":
        return [0, 1, 0xFFFFFFFF, 0x80000000][index % 4]
    if test == "random":
        return random.Random(f"{top}:{test}:{name}:{index}").getrandbits(32)
    return (index + 1) & 0xFFFFFFFF

def render_reg_config(top: str, test: str, registers: Sequence[dict[str, Any]]) -> str:
    """Render a register config where write is implicit."""

    lines = [
        "# Auto-generated FlexSoC register configuration.",
        f"# top={top} test={test}",
        "# format: <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]",
        "# write is implicit; MASK=0xffffffff and WAIT_CYCLES=1 by default.",
        f"# writable_registers={len(registers)}",
    ]
    for reg in registers:
        lines.append(f"# map {reg['key']} {_hex(int(reg['addr']))} access={reg.get('swaccess', 'rw')}")
    for index, reg in enumerate(registers):
        lines.append(f"{reg['key']} {_hex(_config_value(test, reg, index, top=top))}")
    if not registers:
        lines.append("# no writable registers inferred from HJSON")
    return "\n".join(lines) + "\n"

def _is_control_port(name: str) -> bool:
    """Return true for clocks, resets, and generated bus records."""

    return name in {"tl_i", "tl_o", "reg_req_i", "reg_rsp_o"} or "clk" in name or "rst" in name

def _vector_inputs(sig: dict[str, Any] | None) -> list[str]:
    """Return top inputs that can be driven from data_in.vec."""

    return [name for name, _ in (sig or {}).get("ports_in", []) if not _is_control_port(name)]

def _vector_outputs(sig: dict[str, Any] | None) -> list[str]:
    """Return top outputs that can be checked from data_out.vec."""

    return [name for name, _ in (sig or {}).get("ports_out", []) if not _is_control_port(name)]

def _stimulus_rows(test: str, *, top: str, count: int = 8) -> list[tuple[int, int, int, int]]:
    """Return cycle, data, coeff, and valid rows for generated vectors."""

    if test == "smoke":
        values = [(0, 1, 1), (1, 4, 2), (2, 7, 3), (3, 8, 5)]
    elif test == "corners":
        values = [(0, 0, 1), (1, 0xFFFFFFFF, 1), (2, 0x80000000, 2), (3, 0x7FFFFFFF, 3)]
    else:
        rng = random.Random(f"{top}:{test}:vectors")
        values = [(i, rng.getrandbits(16), rng.getrandbits(8)) for i in range(count)]
    return [(cycle, data, coeff, 1) for cycle, data, coeff in values]

def _expected(data: int, coeff: int, mode: int) -> int:
    """Return the expected data_o value for the generated starter core."""

    if mode == 1:
        return data ^ coeff
    if mode == 2:
        return data << 1
    return data + coeff

def render_data_in(top: str, test: str, sig: dict[str, Any] | None = None) -> str:
    """Render named input vectors for one test."""

    inputs = _vector_inputs(sig) or ["data_i", "coeff_i", "valid_i"]
    lines = [
        "# Auto-generated FlexSoC input vectors.",
        f"# top={top} test={test}",
        "# format: <CYCLE> <SIGNAL> <VALUE> [<SIGNAL> <VALUE> ...]",
        "# one or many signals can be assigned on the same cycle.",
        "# config change: <CYCLE> @cfg <PATH_TO_CONFIG.REGS>",
    ]
    for cycle, data, coeff, valid in _stimulus_rows(test, top=top):
        pairs = []
        if "valid_i" in inputs:
            pairs += ["valid_i", _hex(valid)]
        if "data_i" in inputs:
            pairs += ["data_i", _hex(data)]
        if "coeff_i" in inputs:
            pairs += ["coeff_i", _hex(coeff)]
        if not pairs and inputs:
            pairs += [inputs[0], _hex(data)]
        lines.append(" ".join([str(cycle), *pairs]))
    return "\n".join(lines) + "\n"

def render_data_out(top: str, test: str, sig: dict[str, Any] | None = None, *, latency: int = 2) -> str:
    """Render named expected-output vectors for one test."""

    outputs = _vector_outputs(sig) or ["data_o", "valid_o"]
    mode = _mode_for_test(top, test)
    lines = [
        "# Auto-generated FlexSoC expected output vectors.",
        f"# top={top} test={test} latency={latency}",
        "# format: <CYCLE> <SIGNAL> <EXPECTED> [<SIGNAL> <EXPECTED> ...]",
    ]
    for cycle, data, coeff, valid in _stimulus_rows(test, top=top):
        pairs = []
        if "data_o" in outputs:
            pairs += ["data_o", _hex(_expected(data, coeff, mode))]
        if "valid_o" in outputs:
            pairs += ["valid_o", _hex(valid)]
        if not pairs and outputs:
            pairs += [outputs[0], _hex(_expected(data, coeff, mode))]
        lines.append(" ".join([str(cycle + latency), *pairs]))
    return "\n".join(lines) + "\n"

def write_verification_tests(
    base_dir: str | Path,
    top: str,
    hjson_path: Path | None,
    sig: dict[str, Any] | None = None,
    *,
    force: bool,
) -> list[Path]:
    """Create per-test register, input, and expected-output data files."""

    root = Path(base_dir)
    registers = _register_entries(hjson_path)
    written: list[Path] = []
    for test in TEST_NAMES:
        test_dir = root / test
        ensure_dir(test_dir)
        stale = test_dir / f"{test}.vec"
        if stale.exists():
            stale.unlink()
        files = {
            test_dir / "config.regs": render_reg_config(top, test, registers),
            test_dir / "data_in.vec": render_data_in(top, test, sig),
            test_dir / "data_out.vec": render_data_out(top, test, sig),
        }
        for path, text in files.items():
            safe_write_file(path, text, overwrite=force)
            written.append(path)
    return written


@dataclass(slots=True)
class FunctionalFlow:
    """Generate tests and run the same vectors through either DV backend."""

    runner: object | None = None

    @staticmethod
    def _run_generator(base_dir: Path, top: str, suffix: str, *args: str) -> None:
        """Run one model-owned vector generator without modifying its source."""

        model_dir = Path(base_dir).parent / "model"
        script = model_dir / f"{top}_{suffix}.py"
        if not script.is_file():
            raise FileNotFoundError(f"missing vector generator: {script}")
        result = subprocess.run(
            (sys.executable, str(script), "--tests-dir", str(base_dir), *args),
            cwd=model_dir,
            check=False,
        )
        if result.returncode:
            raise RuntimeError(f"vector generator failed ({result.returncode}): {script}")

    def generate_tests(
        self,
        base_dir: Path,
        top: str,
        hjson_path: Path | None,
        signature: dict[str, Any] | None = None,
        *,
        force: bool = False,
    ) -> list[Path]:
        """Materialize authored scenarios plus generated ``auto_toggle`` vectors."""

        self._run_generator(base_dir, top, "tests")
        self._run_generator(base_dir, top, "regmap_tests")
        return sorted(path for path in Path(base_dir).rglob("*") if path.is_file())

    def generate_test(
        self,
        name: str,
        base_dir: Path,
        top: str,
        hjson_path: Path | None,
        signature: dict[str, Any] | None = None,
        *,
        force: bool = False,
    ) -> list[Path]:
        """Materialize one scenario without touching unrelated vectors."""

        suffix = "regmap_tests" if name == "auto_toggle" else "tests"
        self._run_generator(base_dir, top, suffix, "--test", name)
        root = Path(base_dir) / name
        return sorted(path for path in root.iterdir() if path.is_file())

    def tests(self, base_dir: Path) -> tuple[str, ...]:
        """Return generated tests in deterministic order."""

        root = Path(base_dir)
        return tuple(path.name for path in sorted(root.iterdir()) if path.is_dir()) if root.is_dir() else ()

    def flow(
        self,
        base_dir: Path,
        top: str,
        hjson_path: Path | None,
        signature: dict[str, Any] | None = None,
        *,
        force: bool = False,
    ) -> list[Path]:
        """Generate the standard functional test catalogue."""

        return self.generate_tests(base_dir, top, hjson_path, signature, force=force)
    def compile_systemverilog(
        self,
        *,
        top: str,
        tb_dir: Path,
        sim_dir: Path,
        common_filelist: Path,
        ip_filelist: Path,
        test_name: str = "smoke",
        compiler: str = "verilator",
        coverage: bool = False,
        log: Path,
        on: str = "local",
    ):
        """Compile one SystemVerilog functional testbench."""
        from flexsoc.backend.core import CommandRequest, ToolRunner
        runner = self.runner or ToolRunner()
        testbench = f"{top}_tb"
        sv_dir = tb_dir / "sv"
        source = sv_dir / f"{testbench}.sv"
        if not source.is_file():
            raise FileNotFoundError(f"testbench not found: {source}")
        sim_dir.mkdir(parents=True, exist_ok=True)
        rtl_dir = ip_filelist.parent.resolve()
        if compiler == "iverilog":
            argv = (
                "iverilog", "-g2012", "-v",
                "-I", str(sv_dir), "-I", str(rtl_dir),
                "-f", str(common_filelist), "-f", str(ip_filelist),
                "-o", str(sim_dir / f"{testbench}.vvp"), str(source),
            )
        elif compiler == "verilator":
            build = sim_dir / compiler
            argv = (
                "verilator", "-Wall", "-Wno-fatal", "--binary", "--timing",
                "--Mdir", str(build), "--trace-fst", "--trace-structs",
                *( ("--coverage",) if coverage else () ),
                f"-I{sv_dir}", f"-I{rtl_dir}",
                "-f", str(common_filelist), "-f", str(ip_filelist), str(source),
                "--top-module", testbench,
            )
        else:
            raise ValueError("compiler must be iverilog or verilator")
        tb_inputs = tuple(sorted(path for path in sv_dir.rglob("*") if path.is_file()))
        inputs = tuple(
            path for path in (common_filelist, ip_filelist, *tb_inputs) if path.exists()
        )
        _print_command(argv)
        return runner.run(CommandRequest(tuple(argv), sv_dir, {}, log, inputs=inputs), on=on)

    def run_systemverilog(
        self,
        *,
        top: str,
        test_root: Path,
        tb_dir: Path,
        sim_dir: Path,
        test_name: str = "smoke",
        compiler: str = "verilator",
        seed: int = 1,
        wave_file: Path | None = None,
        coverage_file: Path | None = None,
        log: Path,
        on: str = "local",
    ):
        """Run one generated vector test through the SystemVerilog backend."""
        from flexsoc.backend.core import CommandRequest, ToolRunner
        runner = self.runner or ToolRunner()
        test_dir = test_root / test_name
        required = tuple(test_dir / name for name in ("config.regs", "data_in.vec", "data_out.vec"))
        missing = [str(path) for path in required if not path.is_file()]
        if missing:
            raise FileNotFoundError("missing functional test input(s): " + ", ".join(missing))
        testbench = f"{top}_tb"
        wave = wave_file or sim_dir / f"{testbench}_{test_name}.fst"
        plusargs = (
            f"+TEST_NAME={test_name}", f"+TEST_ROOT={test_root}",
            f"+CFG={required[0]}", f"+DATA_IN={required[1]}", f"+DATA_OUT={required[2]}",
            f"+WAVE={wave}",
        )
        env = {}
        if compiler == "iverilog":
            argv = ("vvp", str(sim_dir / f"{testbench}.vvp"), *plusargs)
        elif compiler == "verilator":
            argv = (str(sim_dir / compiler / f"V{testbench}"), *plusargs, f"+verilator+seed+{seed}")
            if coverage_file is not None:
                coverage_file.parent.mkdir(parents=True, exist_ok=True)
                argv += (f"+verilator+coverage+file+{coverage_file}",)
        else:
            raise ValueError("compiler must be iverilog or verilator")
        _print_command(argv)
        return runner.run(CommandRequest(tuple(argv), tb_dir, env, log, inputs=required, outputs=(wave,)), on=on)

    def run_cocotb(
        self,
        *,
        top: str,
        test_root: Path,
        tb_dir: Path,
        rtl_sources: tuple[Path, ...],
        test_name: str = "smoke",
        simulator: str = "verilator",
        seed: int = 1,
        waves: bool = True,
        coverage_file: Path | None = None,
        wave_file: Path | None = None,
        log: Path,
        on: str = "local",
    ):
        """Run one generated vector test through the cocotb backend."""
        from flexsoc.backend.core import CommandRequest, ToolRunner
        runner = self.runner or ToolRunner()
        cocotb_dir = tb_dir / "cocotb"
        makefile = cocotb_dir / "Makefile"
        wrapper = cocotb_dir / f"{top}_tb.sv"
        if not makefile.is_file() or not wrapper.is_file():
            raise FileNotFoundError("cocotb scaffold missing; run setup_cocotb first")
        test_dir = test_root / test_name
        required = tuple(test_dir / name for name in ("config.regs", "data_in.vec", "data_out.vec"))
        if any(not path.is_file() for path in required):
            raise FileNotFoundError(f"functional test not found: {test_dir}")
        wave = wave_file or cocotb_dir / f"{top}_tb_{test_name}.fst"
        if coverage_file is not None:
            coverage_file.parent.mkdir(parents=True, exist_ok=True)
        argv = (
            "make", "--no-print-dir", "-C", str(cocotb_dir),
            f"SIM={simulator}", f"TEST_NAME={test_name}", f"SEED={seed}",
            f"HDL_COVERAGE={1 if coverage_file else 0}",
            f"COVERAGE_FILE={coverage_file or ''}", f"WAVE_FILE={wave}",
            f"WAVES={1 if waves else 0}",
            "VERILOG_SOURCES=" + " ".join(str(path) for path in (*rtl_sources, wrapper)),
        )
        inputs = (*required, makefile, wrapper, *rtl_sources)
        _print_command(argv)
        return runner.run(CommandRequest(tuple(argv), cocotb_dir, {}, log, inputs=tuple(inputs), outputs=(wave,)), on=on)

    def run_regression(
        self,
        *,
        top: str,
        test_root: Path,
        tb_dir: Path,
        sim_dir: Path,
        common_filelist: Path,
        ip_filelist: Path,
        rtl_sources: tuple[Path, ...],
        compiler: str = "verilator",
        backends: tuple[str, ...] = ("sv", "cocotb"),
        seed: int = 1,
        coverage_dir: Path | None = None,
        log_dir: Path,
        on: str = "local",
    ) -> tuple[object, ...]:
        """Run every generated test through selected functional backends."""
        tests = self.tests(test_root)
        if not tests:
            raise FileNotFoundError(f"no generated tests under {test_root}")
        results = []
        sv_logs = log_dir / "sv"
        cocotb_logs = log_dir / "cocotb"
        if "sv" in backends:
            compile_log = sv_logs / f"{top}_sv_compile.log"
            print_label("regression", f"backend=sv · compiler={compiler} · test=compile")
            print_path_label("log", compile_log)
            print_status_label("regression", "RUNNING", f"backend=sv · compiler={compiler} · test=compile")
            compile_result = self.compile_systemverilog(
                top=top, tb_dir=tb_dir, sim_dir=sim_dir,
                common_filelist=common_filelist, ip_filelist=ip_filelist,
                compiler=compiler, coverage=coverage_dir is not None,
                log=compile_log, on=on,
            )
            results.append(compile_result)
            compile_status = "PASS" if compile_result.returncode == 0 else "FAIL"
            print_status_label(
                "regression", compile_status,
                f"backend=sv · compiler={compiler} · test=compile",
            )
            if compile_result.returncode != 0:
                _print_failure_tail(compile_log)
                return tuple(results)
        for name in tests:
            if "sv" in backends:
                cov = coverage_dir / "sv" / f"{name}.dat" if coverage_dir else None
                run_log = sv_logs / f"{top}_sv_sim_{name}.log"
                print_label("regression", f"backend=sv · compiler={compiler} · test={name}")
                print_path_label("log", run_log)
                print_status_label("regression", "RUNNING", f"backend=sv · compiler={compiler} · test={name}")
                result = self.run_systemverilog(
                    top=top, test_root=test_root, tb_dir=tb_dir, sim_dir=sim_dir,
                    test_name=name, compiler=compiler, seed=seed, coverage_file=cov,
                    log=run_log, on=on,
                )
                results.append(result)
                print_status_label(
                    "regression", "PASS" if result.returncode == 0 else "FAIL",
                    f"backend=sv · compiler={compiler} · test={name}",
                )
                if result.returncode != 0:
                    _print_failure_tail(run_log)
            if "cocotb" in backends:
                cov = coverage_dir / "cocotb" / f"{name}.dat" if coverage_dir else None
                run_log = cocotb_logs / f"{top}_cocotb_{name}.log"
                print_label("regression", f"backend=cocotb · simulator={compiler} · test={name}")
                print_path_label("log", run_log)
                print_status_label("regression", "RUNNING", f"backend=cocotb · simulator={compiler} · test={name}")
                print_label("follow", f"tail -f {shlex.quote(str(run_log.resolve()))}")
                result = self.run_cocotb(
                    top=top, test_root=test_root, tb_dir=tb_dir, rtl_sources=rtl_sources,
                    test_name=name, simulator=compiler, seed=seed, coverage_file=cov,
                    log=run_log, on=on,
                )
                results.append(result)
                print_status_label(
                    "regression", "PASS" if result.returncode == 0 else "FAIL",
                    f"backend=cocotb · simulator={compiler} · test={name}",
                )
                if result.returncode != 0:
                    _print_failure_tail(run_log)
        return tuple(results)

    def flow_from_context(self, context, *, on: str = "local"):
        """Run the canonical functional regression from one BackendContext."""
        paths = context.paths
        values = context.values
        rtl_sources = tuple(
            Path(line.strip())
            for filelist in (paths.rtl_common, paths.rtl_ip)
            if filelist.is_file()
            for line in filelist.read_text(encoding="utf-8").splitlines()
            if line.strip() and not line.lstrip().startswith(("#", "+", "-"))
        )
        return self.run_regression(
            top=paths.top, test_root=paths.tests, tb_dir=paths.tb, sim_dir=paths.sim / "rtl",
            common_filelist=paths.rtl_common, ip_filelist=paths.rtl_ip, rtl_sources=rtl_sources,
            compiler=values.get("COMPILER", "verilator"),
            backends=tuple(values.get("REGRESSION_BACKENDS", "sv cocotb").split()),
            seed=int(values.get("SEED", "1")), coverage_dir=paths.coverage,
            log_dir=paths.logs / "dv" / "functional" / "regression", on=on,
        )

