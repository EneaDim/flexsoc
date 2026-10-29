"""Managed POSIX lifecycle for the local RTL viewer."""
from __future__ import annotations

import os
from pathlib import Path
import signal
import sys
import tempfile
import time


def _start_ticks(pid: int) -> str | None:
    """Linux process birth marker: prevents PID-reuse mistakes."""
    try:
        stat = Path(f"/proc/{pid}/stat").read_text()
        return stat.rsplit(')', 1)[1].split()[19]
    except (OSError, IndexError):
        return None


def _owned_viewer(pid: int, marker: str | None) -> bool:
    if pid <= 1 or pid == os.getpid():
        return False
    try:
        proc = Path(f"/proc/{pid}")
        if proc.stat().st_uid != os.getuid():
            return False
        if marker is not None and _start_ticks(pid) != marker:
            return False
        argv = proc.joinpath('cmdline').read_bytes().replace(b'\0', b' ').decode('utf-8', 'replace').lower()
        return 'rtl-view' in argv or 'rtl_viewer' in argv
    except OSError:
        return False


def _stop_previous(pidfile: Path) -> None:
    if not pidfile.exists():
        return
    try:
        old_pid = int(pidfile.read_text().strip())
    except ValueError:
        raise RuntimeError(f"invalid viewer PID file: {pidfile}; inspect it before removing")
    markerfile = pidfile.with_suffix('.start')
    marker = markerfile.read_text().strip() if markerfile.exists() else None
    if not Path(f'/proc/{old_pid}').exists():
        pidfile.unlink(missing_ok=True)
        markerfile.unlink(missing_ok=True)
        return
    if not _owned_viewer(old_pid, marker):
        raise RuntimeError(f"PID {old_pid} in {pidfile} is not a verified RTL viewer; refusing to terminate it")
    print(f'[rtl-view] Stopping previous viewer PID={old_pid}', flush=True)
    os.kill(old_pid, signal.SIGTERM)
    for _ in range(30):
        if not _owned_viewer(old_pid, marker):
            break
        # A terminated child may linger briefly as a zombie.
        try:
            if Path(f'/proc/{old_pid}/stat').read_text().rsplit(')', 1)[1].strip().startswith('Z'):
                break
        except OSError:
            break
        time.sleep(0.1)
    else:
        raise RuntimeError(f'old RTL viewer PID {old_pid} did not stop; refusing to start a second server')
    pidfile.unlink(missing_ok=True)
    markerfile.unlink(missing_ok=True)


def serve_detached(server, *, run: Path, url: str) -> int:
    """Stop a verified previous instance, fork, return shell control."""
    if not hasattr(os, 'fork'):
        raise RuntimeError('background RTL viewer requires POSIX (WSL/Linux)')
    state = Path(run) / 'dv' / 'rtl_viewer'
    state.mkdir(parents=True, exist_ok=True)
    pidfile = state / 'server.pid'
    markerfile = pidfile.with_suffix('.start')
    logfile = state / 'server.log'
    _stop_previous(pidfile)
    pid = os.fork()
    if pid:
        server.server_close()
        def atomic_write(path: Path, value: str) -> None:
            with tempfile.NamedTemporaryFile(mode='w', dir=state, prefix='.server-', delete=False) as temp:
                temp.write(value)
                name = temp.name
            os.replace(name, path)
        atomic_write(pidfile, f'{pid}\n')
        marker = _start_ticks(pid)
        if marker:
            atomic_write(markerfile, marker + '\n')
        print(f'[rtl-view] Background server PID={pid}: {url}', flush=True)
        print(f'[rtl-view] Log: {logfile}', flush=True)
        return pid
    try:
        os.setsid()
        fd_in = os.open(os.devnull, os.O_RDONLY)
        fd_out = os.open(str(logfile), os.O_WRONLY | os.O_CREAT | os.O_APPEND, 0o600)
        for dst, source in ((0, fd_in), (1, fd_out), (2, fd_out)):
            os.dup2(source, dst)
        os.close(fd_in)
        os.close(fd_out)
        signal.signal(signal.SIGTERM, lambda *_: sys.exit(0))
        try:
            server.serve_forever(poll_interval=0.2)
        finally:
            server.server_close()
            try:
                if int(pidfile.read_text().strip()) == os.getpid():
                    pidfile.unlink(missing_ok=True)
                    markerfile.unlink(missing_ok=True)
            except (FileNotFoundError, ValueError):
                pass
    except BaseException as exc:
        print(f'[rtl-view] Detached server failed: {exc}', file=sys.stderr, flush=True)
    os._exit(0)
