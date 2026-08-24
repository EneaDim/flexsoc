"""Command execution and terminal rendering for FlexSoC backends."""

from __future__ import annotations

import os
import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from time import monotonic
from typing import Any, Callable, Mapping, Protocol, TextIO

from rich.console import Console
from rich.syntax import Syntax


_ANSI = re.compile(r"\x1b(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])")
_ORANGE = "\x1b[38;5;208m"
_BLUE = "\x1b[94m"
_GREEN = "\x1b[92m"
_YELLOW = "\x1b[93m"
_RED = "\x1b[91m"
_GRAY = "\x1b[90m"
_RESET = "\x1b[0m"
_STRUCTURED = re.compile(r"^\s*\[(log|script|report|technology)\]\s*(.*?)(?:\r?\n)?$")


def strip_ansi(text: str) -> str:
    """Remove terminal escape sequences before persisting command logs."""

    return _ANSI.sub("", text)


def color_enabled(stream: TextIO | None = None) -> bool:
    """Return whether FlexSoC terminal blocks should use color."""

    stream = stream or sys.stdout
    mode = os.environ.get("FLEXSOC_COLOR", "auto").strip().lower()
    if mode in {"always", "1", "true", "yes", "on"}:
        return True
    if mode in {"never", "0", "false", "no", "off"}:
        return False
    if os.environ.get("NO_COLOR") is not None or os.environ.get("TERM") == "dumb":
        return False
    return bool(getattr(stream, "isatty", lambda: False)())


def print_path_label(
    label: str,
    path: Path,
    *,
    details: Mapping[str, object] | None = None,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print one labeled absolute path followed by deterministic key/value context."""

    stream = stream or sys.stdout
    resolved = path.expanduser().resolve()
    suffix = " · ".join(
        f"{key}={value}"
        for key, value in (details or {}).items()
        if value is not None and value != ""
    )
    text = f"{resolved}" + (f" · {suffix}" if suffix else "")
    use_color = color_enabled(stream) if color is None else color
    if use_color:
        print(f"{_ORANGE}[{label}]{_RESET} {_BLUE}{text}{_RESET}", file=stream)
    else:
        print(f"[{label}] {text}", file=stream)



def print_target_start(
    target: str,
    description: str,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print the uniform header emitted before every CLI target."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    if use_color:
        print(f"{_ORANGE}→ {target}{_RESET}: {_BLUE}{description}{_RESET}", file=stream, flush=True)
    else:
        print(f"→ {target}: {description}", file=stream, flush=True)


def print_target_result(
    target: str,
    returncode: int,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print the uniform completion line emitted after every CLI target."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    ok = returncode == 0
    mark = "✓" if ok else "✗"
    suffix = "done" if ok else f"failed ({returncode})"
    if use_color:
        status = _GREEN if ok else _RED
        print(
            f"{status}{mark}{_RESET} {_ORANGE}{target}{_RESET}: {status}{suffix}{_RESET}",
            file=stream,
            flush=True,
        )
    else:
        print(f"{mark} {target}: {suffix}", file=stream, flush=True)


def print_label(
    label: str,
    text: str,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print one uniform FlexSoC label/value line."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    if use_color:
        print(f"{_ORANGE}[{label}]{_RESET} {_BLUE}{text}{_RESET}", file=stream, flush=True)
    else:
        print(f"[{label}] {text}", file=stream, flush=True)

def print_status_label(
    label: str,
    status: str,
    text: str = "",
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Print one labeled status using the standard FlexSoC result colors."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    normalized = status.strip().lower()
    status_color = (
        _GREEN if normalized in {"pass", "safe", "done"}
        else _YELLOW if normalized in {"review", "warn", "warning", "partial"}
        else _RED if normalized in {"fail", "error", "failed"}
        else _BLUE
    )
    suffix = f" · {text}" if text else ""
    if use_color:
        print(
            f"{_ORANGE}[{label}]{_RESET} {status_color}{status.upper()}{_RESET}"
            f"{_BLUE}{suffix}{_RESET}",
            file=stream,
            flush=True,
        )
    else:
        print(f"[{label}] {status.upper()}{suffix}", file=stream, flush=True)

def print_script(
    path: Path,
    *,
    details: Mapping[str, object] | None = None,
    stream: TextIO | None = None,
    color: bool | None = None,
    content: bool | None = None,
) -> None:
    """Print a generated script header and, in live mode, highlighted Tcl content."""

    stream = stream or sys.stdout
    resolved = path.expanduser().resolve()
    show_content = (
        os.environ.get("FLEXSOC_LIVE", "0").strip().lower() in {"1", "true", "yes", "on"}
        if content is None
        else content
    )
    use_color = color_enabled(stream) if color is None else color
    print_path_label("script", resolved, details=details, stream=stream, color=use_color)
    if not show_content:
        return
    text = resolved.read_text(encoding="utf-8", errors="replace")
    if use_color:
        Console(file=stream, force_terminal=True, color_system="256", soft_wrap=True).print(
            Syntax(text.rstrip("\n"), "tcl", theme="ansi_dark", word_wrap=False)
        )
    else:
        stream.write(text)
        if not text.endswith("\n"):
            stream.write("\n")
    stream.flush()


def print_log(path: Path, *, stream: TextIO | None = None, color: bool | None = None) -> None:
    """Print the header used before a live command transcript."""

    print_path_label("log", path, stream=stream, color=color)


def print_live_line(
    line: str,
    *,
    stream: TextIO | None = None,
    color: bool | None = None,
) -> None:
    """Write one live line, preserving intentional child-process ANSI styling."""

    stream = stream or sys.stdout
    use_color = color_enabled(stream) if color is None else color
    plain = strip_ansi(line)
    structured = _STRUCTURED.match(plain)
    if structured:
        label, text = structured.groups()
        print_label(label, text, stream=stream, color=use_color)
        return
    if use_color:
        stream.write(line if _ANSI.search(line) else f"{_GRAY}{plain}{_RESET}")
    else:
        stream.write(plain)
    stream.flush()


@dataclass(frozen=True, slots=True)
class CommandRequest:
    """One external command with declared execution inputs and outputs."""

    argv: tuple[str, ...]
    cwd: Path
    env: Mapping[str, str]
    log: Path
    inputs: tuple[Path, ...] = ()
    outputs: tuple[Path, ...] = ()
    timeout_s: int | None = None
    line_callback: Callable[[str], None] | None = None


@dataclass(frozen=True, slots=True)
class CommandResult:
    """Normalized result returned by every executor."""

    returncode: int
    log: Path
    duration_s: float


@dataclass(frozen=True, slots=True)
class ExecutionTarget:
    """Machine and path mapping for one execution environment."""

    name: str = "local"
    kind: str = "local"
    host: str = ""
    work_root: str = ""
    sync: str = "shared"
    orfs_root: str = ""
    pdks: Mapping[str, str] | None = None
    env: Mapping[str, str] | None = None
    path_map: Mapping[str, str] | None = None

    @classmethod
    def from_value(cls, name: str, value: "ExecutionTarget | Mapping[str, Any]") -> "ExecutionTarget":
        """Normalize a target object or user-facing mapping."""

        if isinstance(value, cls):
            return value
        return cls(name=name, **dict(value))

    def remote_path(self, local: Path, project_root: Path | None = None) -> Path:
        """Map a local path into the declared remote workspace."""

        local = local.expanduser().resolve()
        if self.kind == "local" or self.sync == "shared":
            return local
        pairs = sorted(
            ((Path(src).expanduser().resolve(), Path(dst)) for src, dst in (self.path_map or {}).items()),
            key=lambda item: len(str(item[0])), reverse=True,
        )
        for source, target in pairs:
            try:
                return target / local.relative_to(source)
            except ValueError:
                continue
        root = Path(project_root or Path.cwd()).resolve()
        if self.work_root:
            try:
                return Path(self.work_root) / local.relative_to(root)
            except ValueError:
                return Path(self.work_root) / "external" / local.name
        return local


class Executor(Protocol):
    def run(self, request: CommandRequest) -> CommandResult: ...


class LocalExecutor:
    """Execute requests directly on the current host."""

    def run(self, request: CommandRequest) -> CommandResult:
        request.log.parent.mkdir(parents=True, exist_ok=True)
        env = os.environ.copy()
        env.update(request.env)
        start = monotonic()
        with request.log.open("w", encoding="utf-8") as log:
            if request.line_callback is None:
                proc = subprocess.run(
                    request.argv,
                    cwd=request.cwd,
                    env=env,
                    stdout=log,
                    stderr=subprocess.STDOUT,
                    text=True,
                    timeout=request.timeout_s,
                    check=False,
                )
                return CommandResult(proc.returncode, request.log, monotonic() - start)

            proc = subprocess.Popen(
                request.argv,
                cwd=request.cwd,
                env=env,
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True,
                bufsize=1,
            )
            assert proc.stdout is not None
            for line in proc.stdout:
                log.write(strip_ansi(line))
                log.flush()
                request.line_callback(line)
            returncode = proc.wait(timeout=request.timeout_s)
        return CommandResult(returncode, request.log, monotonic() - start)


class SshExecutor:
    """Execute requests through SSH with shared or rsync workspace semantics."""

    def __init__(self, target: ExecutionTarget, *, project_root: Path | None = None):
        if not target.host:
            raise ValueError("SSH execution target requires host")
        if target.sync not in {"shared", "rsync"}:
            raise ValueError("SSH sync mode must be 'shared' or 'rsync'")
        self.target = target
        self.project_root = Path(project_root or Path.cwd()).resolve()

    def _remote(self, path: Path) -> Path:
        return self.target.remote_path(path, self.project_root)

    def _map_text(self, value: str) -> str:
        """Map absolute path arguments without changing ordinary tokens."""

        path = Path(value).expanduser()
        if not path.is_absolute():
            return value
        return str(self._remote(path))

    def _remote_env(self, request: CommandRequest) -> dict[str, str]:
        """Map path-bearing environment values and declared technology roots."""

        env = {**(self.target.env or {}), **request.env}
        for key, value in tuple(env.items()):
            if isinstance(value, str) and Path(value).expanduser().is_absolute():
                env[key] = self._map_text(value)
        pdk = env.get("PDK") or env.get("FLEXSOC_PDK")
        if pdk and self.target.pdks and pdk in self.target.pdks:
            env["PDK_ROOT"] = self.target.pdks[pdk]
        if self.target.orfs_root:
            for key in ("ORS", "ORFS_ROOT"):
                if key in env:
                    env[key] = self.target.orfs_root
        return env

    def _sync_inputs(self, request: CommandRequest) -> None:
        if self.target.sync != "rsync":
            return
        remote_cwd = self._remote(request.cwd)
        subprocess.run(
            ["ssh", self.target.host, "mkdir", "-p", str(remote_cwd)],
            check=True,
        )
        for source in request.inputs:
            source = source.resolve()
            target = self._remote(source)
            subprocess.run(
                ["ssh", self.target.host, "mkdir", "-p", str(target.parent)],
                check=True,
            )
            subprocess.run(
                ["rsync", "-a", str(source), f"{self.target.host}:{target}"],
                check=True,
            )

    def _sync_outputs(self, request: CommandRequest) -> None:
        if self.target.sync != "rsync":
            return
        for output in request.outputs:
            target = output.resolve()
            target.parent.mkdir(parents=True, exist_ok=True)
            remote = self._remote(target)
            subprocess.run(
                ["rsync", "-a", f"{self.target.host}:{remote}", str(target)],
                check=True,
            )

    def run(self, request: CommandRequest) -> CommandResult:
        import shlex

        request.log.parent.mkdir(parents=True, exist_ok=True)
        self._sync_inputs(request)
        remote_cwd = self._remote(request.cwd)
        env = self._remote_env(request)
        exports = " ".join(f"{k}={shlex.quote(str(v))}" for k, v in env.items())
        argv = " ".join(shlex.quote(self._map_text(str(part))) for part in request.argv)
        command = f"cd {shlex.quote(str(remote_cwd))} && {exports} {argv}".strip()
        start = monotonic()
        with request.log.open("w", encoding="utf-8") as log:
            if request.line_callback is None:
                proc = subprocess.run(
                    ["ssh", self.target.host, command],
                    stdout=log,
                    stderr=subprocess.STDOUT,
                    text=True,
                    timeout=request.timeout_s,
                    check=False,
                )
                returncode = proc.returncode
            else:
                proc = subprocess.Popen(
                    ["ssh", self.target.host, command],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.STDOUT,
                    text=True,
                    bufsize=1,
                )
                assert proc.stdout is not None
                for line in proc.stdout:
                    log.write(strip_ansi(line))
                    log.flush()
                    request.line_callback(line)
                returncode = proc.wait(timeout=request.timeout_s)
        if returncode == 0:
            self._sync_outputs(request)
        return CommandResult(returncode, request.log, monotonic() - start)


class ToolRunner:
    """Select an executor without leaking machine policy into flow objects."""

    def __init__(
        self,
        targets: Mapping[str, ExecutionTarget] | None = None,
        *,
        project_root: Path | None = None,
    ):
        raw = dict(targets or {"local": ExecutionTarget()})
        self.targets = {name: ExecutionTarget.from_value(name, value) for name, value in raw.items()}
        self.targets.setdefault("local", ExecutionTarget())
        self.project_root = Path(project_root or Path.cwd()).resolve()

    def run(self, request: CommandRequest, *, on: str = "local") -> CommandResult:
        target = self.targets.get(on)
        if target is None:
            raise ValueError(f"unknown execution target: {on}")
        executor: Executor
        if target.kind == "local":
            executor = LocalExecutor()
        elif target.kind == "ssh":
            executor = SshExecutor(target, project_root=self.project_root)
        else:
            raise ValueError(f"unsupported execution target kind: {target.kind}")
        return executor.run(request)

