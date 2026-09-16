"""Workspace artifact viewing and cleanup."""

from __future__ import annotations

import os
import shutil
from dataclasses import dataclass
from pathlib import Path

from .core import BackendContext
from .execution import CommandRequest, ToolRunner
from .target import Target


def _select_waveform(directory: Path, top: str, sim_name: str = "") -> Path:
    """Select one waveform by explicit name, rejecting ambiguous fallbacks."""

    candidates = [path for pattern in ("*.fst", "*.vcd") for path in directory.rglob(pattern)]
    if not candidates:
        raise FileNotFoundError(f"no waveform available in {directory}; run the matching simulation first")
    if not sim_name:
        if len(candidates) == 1:
            return candidates[0]
        names = ", ".join(sorted(path.relative_to(directory).as_posix() for path in candidates))
        raise FileNotFoundError(f"ambiguous waveform in {directory}; set SIM_NAME; candidates: {names}")

    requested = Path(sim_name).name
    if Path(requested).suffix.lower() in {".fst", ".vcd"}:
        requested = Path(requested).stem
    stems = {requested, f"{top}_tb_{requested}"}
    matches = [path for path in candidates if path.stem in stems]
    if len(matches) == 1:
        return matches[0]
    if len(matches) > 1:
        names = ", ".join(sorted(path.relative_to(directory).as_posix() for path in matches))
        raise FileNotFoundError(f"SIM_NAME={sim_name!r} is ambiguous in {directory}: {names}")
    prefix = f"{top}_tb_"
    available = ", ".join(sorted(path.stem.removeprefix(prefix) for path in candidates))
    raise FileNotFoundError(
        f"SIM_NAME={sim_name!r} not found in {directory}; available: {available or 'none'}"
    )


def _viewer_environment(viewer: str, surfer_backend: str = "auto") -> dict[str, str]:
    """Return viewer-specific environment overrides."""

    if Path(viewer).name.lower().removesuffix(".exe") != "surfer":
        return {}
    backend = surfer_backend.strip().lower() or "auto"
    if backend not in {"auto", "x11", "wayland"}:
        raise ValueError("SURFER_BACKEND must be auto, x11, or wayland")
    if backend == "x11" or (backend == "auto" and os.environ.get("WSL_DISTRO_NAME")):
        return {"WAYLAND_DISPLAY": ""}
    return {}


def _remove_contents(path: Path) -> None:
    if not path.is_dir():
        return
    for item in path.iterdir():
        if item.is_dir() and not item.is_symlink():
            shutil.rmtree(item, ignore_errors=True)
        else:
            item.unlink(missing_ok=True)


def _remove_globs(path: Path, *patterns: str) -> None:
    if not path.is_dir():
        return
    for pattern in patterns:
        for item in path.glob(pattern):
            if item.is_dir() and not item.is_symlink():
                shutil.rmtree(item, ignore_errors=True)
            else:
                item.unlink(missing_ok=True)


@dataclass(slots=True)
class WorkspaceFlow:
    """Own run-local artifact viewing and cleanup operations."""

    context: BackendContext
    runner: ToolRunner | None = None

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)

    def run_target(self, target: Target, *, on: str = "local") -> object:
        action = target.action or ""
        if action == "setup":
            return self.context.paths.ensure()
        if action == "view":
            return self.view(target.name, on=on)
        if action.startswith("clean"):
            return self.clean(action)
        raise ValueError(f"unsupported workspace action: {action!r}")

    def view(self, target: str = "view", *, on: str = "local") -> object:
        """Open or save one waveform artifact."""

        paths, values = self.context.paths, self.context.values
        if target == "tb_save":
            destination = paths.functional / "saved"
            destination.mkdir(parents=True, exist_ok=True)
            for source in paths.tb.rglob("*"):
                if source.is_file():
                    out = destination / source.relative_to(paths.tb)
                    out.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(source, out)
            return destination
        if target == "tb_view":
            saved = paths.functional / "saved"
            print(saved)
            return saved

        sim_name = values.get("SIM_NAME", "").strip() if target == "view" else ""
        if sim_name:
            stage = values.get("SIGNOFF_STAGE", "post_syn").strip().lower()
            if stage == "post_syn":
                directory = self.context.layout.post_syn_sim_dir
            elif stage in {"post_route", "post_pnr"}:
                directory = self.context.layout.post_pnr_sim_dir
            else:
                raise ValueError("SIGNOFF_STAGE must be post_syn, post_route, or post_pnr for view")
            print(f"[wave] stage={stage} pdk={paths.pdk} sim={sim_name} directory={directory}", flush=True)
            wave = _select_waveform(directory, paths.top, sim_name)
        else:
            wave = _select_waveform(paths.functional, paths.top)

        viewer = values.get("WAVE_VIEWER", "surfer")
        env = _viewer_environment(viewer, values.get("SURFER_BACKEND", "auto"))
        print(f"[wave] {wave}", flush=True)
        request = CommandRequest(
            (viewer, str(wave)), wave.parent, env,
            paths.logs / "viewer" / f"{target}.log", inputs=(wave,),
        )
        return self.runner.run(request, on=on)

    def clean(self, action: str) -> int:
        """Remove artifacts owned by one explicit cleanup action."""

        paths = self.context.paths
        root = self.context.project_root

        if action == "clean_pyc":
            for directory in root.rglob("__pycache__"):
                shutil.rmtree(directory, ignore_errors=True)
            for file in root.rglob("*.py[co]"):
                file.unlink(missing_ok=True)
            for directory in (root / ".pytest_cache", root / ".ruff_cache"):
                shutil.rmtree(directory, ignore_errors=True)
            return 0

        simple = {
            "clean_doc": lambda: _remove_contents(paths.doc),
            "clean_log": lambda: _remove_contents(paths.logs),
            "clean_rtl": lambda: _remove_globs(paths.rtl, "*.v"),
            "clean_meta": lambda: _remove_contents(paths.meta),
            "clean_formal": lambda: (shutil.rmtree(paths.formal, ignore_errors=True), shutil.rmtree(paths.logs / "dv" / "formal", ignore_errors=True)),
            "clean_syn": lambda: (shutil.rmtree(paths.syn, ignore_errors=True), shutil.rmtree(paths.logs / "synthesis" / paths.pdk, ignore_errors=True)),
            "clean_signoff": lambda: (shutil.rmtree(paths.signoff, ignore_errors=True), shutil.rmtree(paths.logs / "signoff" / paths.pdk, ignore_errors=True)),
            "clean_pnr": lambda: (shutil.rmtree(paths.impl, ignore_errors=True), shutil.rmtree(paths.logs / "pnr" / paths.pdk, ignore_errors=True)),
            "clean_agent": lambda: shutil.rmtree(root / "flexsoc_make_agent", ignore_errors=True),
            "clean_fsoc": lambda: (shutil.rmtree(root / "build", ignore_errors=True), shutil.rmtree(paths.run / "fusesoc", ignore_errors=True)),
            "clean_sw": lambda: _remove_globs(paths.run / "sw", "*.elf", "*.o", "*.csv"),
        }
        if action in simple:
            simple[action]()
            return 0
        if action == "clean_sim":
            _remove_globs(paths.sim, "*.vvp", "*.vcd", "*.fst")
            shutil.rmtree(paths.sim / "verilator", ignore_errors=True)
            return 0
        if action == "clean_cocotb":
            cocotb = paths.tb / "cocotb"
            _remove_globs(cocotb, "*.vcd", "*.fst", "__pycache__", "*.pyc")
            shutil.rmtree(cocotb / "sim_build", ignore_errors=True)
            return 0
        if action in {"clean_fsm", "clean_fsm_all", "clean_subdir"}:
            from ..design.fsm_gen import FsmFlow
            flow = FsmFlow(paths.run, self.runner)
            name = self.context.values.get("FSM", "fsm_example")
            if action == "clean_subdir":
                flow.clean(name)
                flow.setup(name)
            else:
                flow.clean(name, inputs=action == "clean_fsm_all")
            return 0
        if action == "clean_soc":
            for name in ("trace_core_00000000.log", "uart0.log", "soc.core", "xbar_main.hjson"):
                (root / name).unlink(missing_ok=True)
            _remove_globs(root, "sim.fst*")
            _remove_globs(root / "sw", "*.elf", "*.o", "*.csv")
            _remove_globs(root / "tb", "top_verilator.*")
            shutil.rmtree(paths.run / "soc", ignore_errors=True)
            return 0
        if action == "clean_vendor":
            vendor = root / "vendor"
            for name in ("lowrisc_ip", "lowrisc_ibex"):
                shutil.rmtree(vendor / name, ignore_errors=True)
                (vendor / f"{name}.lock.hjson").unlink(missing_ok=True)
            return 0
        if action == "clean_all":
            shutil.rmtree(paths.run, ignore_errors=True)
            default = self.context.workspace / "runs" / paths.run_top / "default"
            if default != paths.run:
                shutil.rmtree(default, ignore_errors=True)
            for name in ("build", "dist", ".pytest_cache", ".mypy_cache", ".ruff_cache"):
                shutil.rmtree(root / name, ignore_errors=True)
            self.clean("clean_pyc")
            return 0
        if action == "clean":
            for item in (
                "clean_pyc", "clean_log", "clean_rtl", "clean_sim", "clean_syn",
                "clean_signoff", "clean_meta", "clean_pnr", "clean_subdir",
                "clean_fsoc", "clean_soc", "clean_fsm",
            ):
                self.clean(item)
            return 0
        raise ValueError(f"unsupported cleanup action: {action!r}")


__all__ = ["WorkspaceFlow"]
