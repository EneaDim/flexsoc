"""Functional test intent, vector generation and simulator orchestration."""

from __future__ import annotations

from io import StringIO
import json
import shlex
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

from rich.console import Console
from rich.table import Table

from flexsoc.backend.core.runtime.execution import Terminal

@dataclass(slots=True)
class FunctionalFlow:
    """Generate tests and run the same vectors through either DV backend."""

    runner: object | None = None

    def _run_generator(
        self,
        base_dir: Path,
        top: str,
        suffix: str,
        *args: str,
        model_dir: Path | None = None,
        on: str = "local",
    ) -> None:
        """Run one model-owned vector generator through the shared executor."""

        from flexsoc.backend.core import CommandRequest, ToolRunner

        model_dir = Path(model_dir) if model_dir is not None else Path(base_dir).parent / "model"
        script = model_dir / f"{top}_{suffix}.py"
        if not script.is_file():
            raise FileNotFoundError(f"missing vector generator: {script}")
        runner = self.runner or ToolRunner()
        base_dir = Path(base_dir)
        run_root = base_dir.parents[2] if base_dir.parent.name == "functional" else base_dir.parent
        log = run_root / "logs" / "dv" / "functional" / "generation" / f"{top}_{suffix}.log"
        inputs = tuple(sorted(path for path in model_dir.glob("*.py") if path.is_file()))
        request = CommandRequest(
            (sys.executable, str(script), "--tests-dir", str(base_dir), *args),
            model_dir,
            {},
            log,
            inputs=inputs,
            outputs=(base_dir,),
        )
        result = runner.run(request, on=on)
        if result.returncode:
            raise RuntimeError(f"vector generator failed ({result.returncode}): {script}")

    def setup_tests(
        self,
        base_dir: Path,
        top: str,
        *,
        on: str = "local",
    ) -> list[Path]:
        """Materialize authored scenarios plus generated ``auto_toggle`` vectors."""

        self._run_generator(base_dir, top, "tests", on=on)
        self._run_generator(base_dir, top, "regmap_tests", on=on)
        return sorted(path for path in Path(base_dir).rglob("*") if path.is_file())

    def setup_test(
        self,
        name: str,
        base_dir: Path,
        top: str,
        *,
        on: str = "local",
    ) -> list[Path]:
        """Materialize one scenario without touching unrelated vectors."""

        suffix = "regmap_tests" if name == "auto_toggle" else "tests"
        self._run_generator(base_dir, top, suffix, "--test", name, on=on)
        root = Path(base_dir) / name
        return sorted(path for path in root.iterdir() if path.is_file())

    def check_tests(self, base_dir: Path, top: str, *, on: str = "local") -> dict[str, object]:
        """Regenerate vectors in staging and compare them with the checked run catalogue."""

        root = Path(base_dir)
        model_dir = root.parent / "model"
        with tempfile.TemporaryDirectory(prefix=f"flexsoc-{top}-tests-check-") as temporary:
            staged = Path(temporary) / "tests"
            self._run_generator(staged, top, "tests", model_dir=model_dir, on=on)
            self._run_generator(staged, top, "regmap_tests", model_dir=model_dir, on=on)

            expected = {
                path.relative_to(staged).as_posix(): path.read_bytes()
                for path in staged.rglob("*")
                if path.is_file()
            }
            actual = {
                path.relative_to(root).as_posix(): path.read_bytes()
                for path in root.rglob("*")
                if path.is_file()
            } if root.is_dir() else {}

        expected_names = set(expected)
        actual_names = set(actual)
        missing = sorted(expected_names - actual_names)
        extra = sorted(actual_names - expected_names)
        modified = sorted(
            name for name in expected_names & actual_names
            if expected[name] != actual[name]
        )
        return {
            "ok": not (missing or extra or modified),
            "missing": missing,
            "extra": extra,
            "modified": modified,
            "files": len(expected),
        }

    def tests(self, base_dir: Path) -> tuple[str, ...]:
        """Return generated tests in deterministic order."""

        root = Path(base_dir)
        return tuple(path.name for path in sorted(root.iterdir()) if path.is_dir()) if root.is_dir() else ()

    def run_compile_systemverilog(
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
        FunctionalFlow._print_command(argv)
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
        executable: Path | None = None,
        extra_inputs: tuple[Path, ...] = (),
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
            f"+WAVE={wave}", f"+FLEXSOC_SEED={seed}",
        )
        env = {}
        if compiler == "iverilog":
            argv = ("vvp", str(sim_dir / f"{testbench}.vvp"), *plusargs)
        elif compiler == "verilator":
            binary = Path(executable) if executable is not None else sim_dir / compiler / f"V{testbench}"
            argv = (str(binary), *plusargs, f"+verilator+seed+{seed}")
            if coverage_file is not None:
                coverage_file.parent.mkdir(parents=True, exist_ok=True)
                argv += (f"+verilator+coverage+file+{coverage_file}",)
        else:
            raise ValueError("compiler must be iverilog or verilator")
        FunctionalFlow._print_command(argv)
        inputs = (*required, *(Path(path) for path in extra_inputs))
        return runner.run(CommandRequest(tuple(argv), tb_dir, env, log, inputs=inputs, outputs=(wave,)), on=on)

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
        reset_settle_cycles: int = 8,
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
            raise FileNotFoundError("cocotb scaffold missing; run `fx cocotb --setup` first")
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
            f"RESET_SETTLE_CYCLES={max(0, int(reset_settle_cycles))}",
            f"HDL_COVERAGE={1 if coverage_file else 0}",
            f"COVERAGE_FILE={coverage_file or ''}", f"WAVE_FILE={wave}",
            f"WAVES={1 if waves else 0}",
            "VERILOG_SOURCES=" + " ".join(str(path) for path in (*rtl_sources, wrapper)),
        )
        inputs = (*required, makefile, wrapper, *rtl_sources)
        FunctionalFlow._print_command(argv)
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
        reset_settle_cycles: int = 8,
        coverage_dir: Path | None = None,
        log_dir: Path,
        summary_path: Path | None = None,
        run_root: Path | None = None,
        on: str = "local",
    ) -> tuple[object, ...]:
        """Run every generated test and persist the canonical regression outcome."""

        tests = self.tests(test_root)
        if not tests:
            raise FileNotFoundError(f"no generated tests under {test_root}")
        selected = tuple(dict.fromkeys(backends))
        invalid = [name for name in selected if name not in {"sv", "cocotb"}]
        if invalid:
            raise ValueError(f"unsupported regression backend(s): {', '.join(invalid)}")

        results: list[object] = []
        sv_logs = log_dir / "sv"
        cocotb_logs = log_dir / "cocotb"
        matrix: dict[str, dict[str, dict[str, object]]] = {
            name: {
                backend: {
                    "status": "NOT_RUN",
                    "log": (
                        (sv_logs / f"{top}_sv_sim_{name}.log")
                        if backend == "sv"
                        else (cocotb_logs / f"{top}_cocotb_{name}.log")
                    ),
                }
                for backend in selected
            }
            for name in tests
        }
        compile_data: dict[str, object] = {}

        if "sv" in selected:
            compile_log = sv_logs / f"{top}_sv_compile.log"
            Terminal.print_label("regression", f"backend=sv · compiler={compiler} · test=compile")
            Terminal.print_path_label("log", compile_log)
            Terminal.print_status_label("regression", "RUNNING", f"backend=sv · compiler={compiler} · test=compile")
            compile_result = self.run_compile_systemverilog(
                top=top, tb_dir=tb_dir, sim_dir=sim_dir,
                common_filelist=common_filelist, ip_filelist=ip_filelist,
                compiler=compiler, coverage=coverage_dir is not None,
                log=compile_log, on=on,
            )
            results.append(compile_result)
            compile_status = "PASS" if compile_result.returncode == 0 else "FAILED"
            compile_data = {"status": compile_status, "log": compile_log}
            Terminal.print_status_label(
                "regression", "PASS" if compile_status == "PASS" else "FAIL",
                f"backend=sv · compiler={compiler} · test=compile",
            )
            if compile_result.returncode != 0:
                FunctionalFlow._print_failure_tail(compile_log)
                if summary_path is not None:
                    self._write_regression_summary(
                        summary_path, top=top, compiler=compiler, backends=selected, tests=tests,
                        compile_data=compile_data, matrix=matrix, run_root=run_root,
                    )
                return tuple(results)

        for name in tests:
            if "sv" in selected:
                cov = coverage_dir / "sv" / f"{name}.dat" if coverage_dir else None
                run_log = sv_logs / f"{top}_sv_sim_{name}.log"
                Terminal.print_label("regression", f"backend=sv · compiler={compiler} · test={name}")
                Terminal.print_path_label("log", run_log)
                Terminal.print_status_label("regression", "RUNNING", f"backend=sv · compiler={compiler} · test={name}")
                result = self.run_systemverilog(
                    top=top, test_root=test_root, tb_dir=tb_dir, sim_dir=sim_dir,
                    test_name=name, compiler=compiler, seed=seed, coverage_file=cov,
                    log=run_log, on=on,
                )
                results.append(result)
                status = "PASS" if result.returncode == 0 else "FAILED"
                matrix[name]["sv"]["status"] = status
                Terminal.print_status_label(
                    "regression", "PASS" if status == "PASS" else "FAIL",
                    f"backend=sv · compiler={compiler} · test={name}",
                )
                if result.returncode != 0:
                    FunctionalFlow._print_failure_tail(run_log)
            if "cocotb" in selected:
                cov = coverage_dir / "cocotb" / f"{name}.dat" if coverage_dir else None
                run_log = cocotb_logs / f"{top}_cocotb_{name}.log"
                Terminal.print_label("regression", f"backend=cocotb · simulator={compiler} · test={name}")
                Terminal.print_path_label("log", run_log)
                Terminal.print_status_label("regression", "RUNNING", f"backend=cocotb · simulator={compiler} · test={name}")
                Terminal.print_label("follow", f"tail -f {shlex.quote(str(run_log.resolve()))}")
                result = self.run_cocotb(
                    top=top, test_root=test_root, tb_dir=tb_dir, rtl_sources=rtl_sources,
                    test_name=name, simulator=compiler, seed=seed,
                    reset_settle_cycles=reset_settle_cycles, coverage_file=cov,
                    log=run_log, on=on,
                )
                results.append(result)
                status = "PASS" if result.returncode == 0 else "FAILED"
                matrix[name]["cocotb"]["status"] = status
                Terminal.print_status_label(
                    "regression", "PASS" if status == "PASS" else "FAIL",
                    f"backend=cocotb · simulator={compiler} · test={name}",
                )
                if result.returncode != 0:
                    FunctionalFlow._print_failure_tail(run_log)

        if summary_path is not None:
            self._write_regression_summary(
                summary_path, top=top, compiler=compiler, backends=selected, tests=tests,
                compile_data=compile_data, matrix=matrix, run_root=run_root,
            )
        return tuple(results)

    def run_regression_from_context(self, context, *, on: str = "local"):
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
            seed=int(values.get("SEED", "1")),
            reset_settle_cycles=int(values.get("RESET_SETTLE_CYCLES", "8")),
            coverage_dir=paths.coverage,
            log_dir=paths.logs / "dv" / "functional" / "regression",
            summary_path=paths.functional / "regression" / "summary.json",
            run_root=paths.run, on=on,
        )

    def show_regression(
        self,
        context,
        *,
        summary: bool = False,
        debug: bool = False,
        output: str | None = None,
        as_json: bool = False,
    ) -> int:
        """Render the canonical regression summary without reading simulator logs."""

        path = context.paths.functional / "regression" / "summary.json"
        if not path.is_file():
            raise FileNotFoundError(f"regression summary not found: {path}; run `fx regression` first")
        data = json.loads(path.read_text(encoding="utf-8"))
        capture = StringIO() if output else None
        console = Console(file=capture, force_terminal=False) if capture else Console()
        if as_json:
            print(json.dumps(data, indent=2, sort_keys=True), file=capture or None)
        else:
            status = str(data.get("status", "UNKNOWN"))
            color = "green" if status == "PASS" else "red" if status == "FAILED" else "orange1"
            counts = data.get("counts", {}) if isinstance(data.get("counts"), Mapping) else {}
            console.print(
                f"[bold]Regression[/bold] [{color}]{status}[/{color}] · "
                f"tests={data.get('test_count', 0)} · subruns={counts.get('total', 0)} · "
                f"pass={counts.get('passed', 0)} · fail={counts.get('failed', 0)} · "
                f"not-run={counts.get('not_run', 0)}"
            )
            backend_counts = data.get("backend_counts", {})
            table = Table(box=None, show_edge=False, pad_edge=False)
            table.add_column("Backend", style="bright_cyan")
            table.add_column("Pass", justify="right")
            table.add_column("Fail", justify="right")
            table.add_column("Not run", justify="right")
            table.add_column("Total", justify="right")
            for name in data.get("backends", ()):
                item = backend_counts.get(name, {}) if isinstance(backend_counts, Mapping) else {}
                table.add_row(
                    str(name), str(item.get("passed", 0)), str(item.get("failed", 0)),
                    str(item.get("not_run", 0)), str(item.get("total", 0)),
                )
            console.print(table)

            if not summary:
                matrix = data.get("matrix", {}) if isinstance(data.get("matrix"), Mapping) else {}
                table = Table(box=None, show_edge=False, pad_edge=False)
                table.add_column("Test", style="bright_cyan")
                for backend in data.get("backends", ()):
                    table.add_column(str(backend).upper())
                for test in data.get("tests", ()):
                    row = matrix.get(test, {}) if isinstance(matrix, Mapping) else {}
                    table.add_row(
                        str(test),
                        *(str(row.get(name, {}).get("status", "NOT_RUN")) for name in data.get("backends", ())),
                    )
                console.print(table)

            if debug:
                console.print("[bold]Diagnostics[/bold]")
                compile_data = data.get("compile", {}) if isinstance(data.get("compile"), Mapping) else {}
                if compile_data:
                    console.print(
                        f"[grey70]sv compile[/grey70] {compile_data.get('status', 'UNKNOWN')} · "
                        f"{compile_data.get('log', '-')}"
                    )
                matrix = data.get("matrix", {}) if isinstance(data.get("matrix"), Mapping) else {}
                failures = 0
                for test, row in matrix.items():
                    if not isinstance(row, Mapping):
                        continue
                    for backend, item in row.items():
                        if isinstance(item, Mapping) and item.get("status") != "PASS":
                            failures += 1
                            console.print(
                                f"[grey70]{backend}/{test}[/grey70] {item.get('status', 'UNKNOWN')} · "
                                f"{item.get('log', '-')}"
                            )
                if failures == 0 and compile_data.get("status", "PASS") == "PASS":
                    console.print("[green]No failing or incomplete regression sub-runs.[/green]")
                console.print(f"[grey70]summary[/grey70] {path}")

        if output and capture is not None:
            destination = Path(output)
            if not destination.is_absolute():
                destination = context.project_root / destination
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(capture.getvalue(), encoding="utf-8")
        return 0

    def _write_regression_summary(
        self,
        output: Path,
        *,
        top: str,
        compiler: str,
        backends: tuple[str, ...],
        tests: tuple[str, ...],
        compile_data: Mapping[str, object],
        matrix: Mapping[str, Mapping[str, Mapping[str, object]]],
        run_root: Path | None,
    ) -> dict[str, object]:
        """Write the machine-readable regression contract from executed sub-runs."""

        serialized_matrix: dict[str, dict[str, dict[str, object]]] = {}
        backend_counts: dict[str, dict[str, int]] = {}
        statuses: list[str] = []
        for test in tests:
            serialized_matrix[test] = {}
            for backend in backends:
                item = dict(matrix[test][backend])
                log = item.get("log")
                if isinstance(log, Path):
                    item["log"] = (
                        log.relative_to(run_root).as_posix()
                        if run_root is not None and log.is_relative_to(run_root)
                        else str(log)
                    )
                serialized_matrix[test][backend] = item
                statuses.append(str(item.get("status", "NOT_RUN")))

        for backend in backends:
            selected = [str(serialized_matrix[test][backend]["status"]) for test in tests]
            backend_counts[backend] = {
                "passed": selected.count("PASS"),
                "failed": selected.count("FAILED"),
                "not_run": selected.count("NOT_RUN"),
                "total": len(selected),
            }

        compile_record = dict(compile_data)
        compile_log = compile_record.get("log")
        if isinstance(compile_log, Path):
            compile_record["log"] = (
                compile_log.relative_to(run_root).as_posix()
                if run_root is not None and compile_log.is_relative_to(run_root)
                else str(compile_log)
            )
        failed = statuses.count("FAILED") + (1 if compile_record.get("status") == "FAILED" else 0)
        not_run = statuses.count("NOT_RUN")
        status = "FAILED" if failed else "PARTIAL" if not_run else "PASS"
        data: dict[str, object] = {
            "schema": "flexsoc.regression.v1",
            "stage": "regression",
            "status": status,
            "top": top,
            "compiler": compiler,
            "backends": list(backends),
            "tests": list(tests),
            "test_count": len(tests),
            "counts": {
                "passed": statuses.count("PASS"),
                "failed": statuses.count("FAILED"),
                "not_run": not_run,
                "total": len(statuses),
            },
            "backend_counts": backend_counts,
            "compile": compile_record,
            "matrix": serialized_matrix,
            "artifacts": {"summary": "dv/functional/regression/summary.json"},
        }
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return data

    @staticmethod
    def _print_command(argv: Sequence[str]) -> None:
        """Print the exact external command before handing it to the runner."""
    
        Terminal.print_label("command", shlex.join(str(item) for item in argv))

    @staticmethod
    def _print_failure_tail(log: Path, *, lines: int = 40) -> None:
        """Print a compact tail immediately when one regression command fails."""
    
        if not log.is_file():
            return
        content = log.read_text(encoding="utf-8", errors="replace").splitlines()
        Terminal.print_label("failure-tail", f"last {min(lines, len(content))} lines · {log.resolve()}")
        for line in content[-lines:]:
            print(line, flush=True)

    @staticmethod
    def register_entries_for_top(rtldir: str | Path, top: str) -> list[dict[str, Any]]:
        """Return canonical register metadata for flat or named-domain HJSON maps."""
    
        from flexsoc.backend.design.ip.regs import RegsFlow
    
        rtl = Path(rtldir).resolve()
        for data_dir in (rtl.parent / "csr", rtl.parent.parent / "csr"):
            if not data_dir.is_dir():
                continue
            flat = data_dir / f"{top}.hjson"
            named = tuple(data_dir.glob(f"{top}_*.hjson"))
            if not flat.exists() and not named:
                continue
            _, registers = RegsFlow._collect(top, data_dir)
            return [
                {
                    "name": register.name,
                    "clock": register.domain,
                    "key": register.path,
                    "addr": register.offset,
                    "writable": register.writable,
                    "readable": register.readable,
                }
                for register in registers
            ]
        return []
