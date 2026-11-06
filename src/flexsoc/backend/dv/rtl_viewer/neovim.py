"""Opt-in local Neovim UI bridge (MessagePack-RPC), not a Vim-key emulator.

One in-memory scratch buffer shows only compiler-mapped SystemVerilog source.  The
bridge is localhost-only and disabled by default, since arbitrary user Neovim
configuration and :commands execute with the privileges of the viewer process.
"""
from __future__ import annotations

import os
import secrets
import shutil
import subprocess
import threading
from pathlib import Path
from typing import Any


class NeovimUnavailable(RuntimeError):
    """The optional local Neovim process cannot be used."""


def capability(enabled: bool, local_only: bool) -> dict[str, Any]:
    available = shutil.which('nvim') is not None
    try:
        import msgpack  # noqa: F401
        dependency = True
    except ImportError:
        dependency = False
    return {'enabled': bool(enabled and local_only and available and dependency),
            'executable': available, 'msgpack': dependency, 'local_only': local_only,
            'reason': ('Set FLEXSOC_RTL_NEOVIM=1 before fx rtl-view (localhost only)' if not enabled else
                       'Neovim is restricted to localhost' if not local_only else
                       'Install nvim in WSL' if not available else
                       'Install the optional msgpack Python dependency' if not dependency else '')}


class NeovimGrid:
    """Bounded ext_linegrid state; geometry is owned exclusively by Neovim."""

    def __init__(self):
        self.width = 80
        self.height = 24
        self.cells: list[list[tuple[str, int]]] = []
        self.styles: dict[int, dict] = {}
        self.foreground = 0xffffff
        self.background = 0x161f2e
        self.cursor = [0, 0]
        self.version = 0
        self._resize(80, 24)

    def _resize(self, width: int, height: int) -> None:
        if not 20 <= width <= 220 or not 4 <= height <= 100:
            raise ValueError('Neovim grid size outside allowed bounds')
        old = self.cells
        self.cells = [[old[y][x] if y < len(old) and x < len(old[y]) else (' ', 0)
                       for x in range(width)] for y in range(height)]
        self.width, self.height = width, height

    def update(self, events: list) -> None:
        for event in events:
            if not event:
                continue
            name = event[0]
            for data in event[1:]:
                if name == 'grid_resize' and data[0] == 1:
                    self._resize(int(data[1]), int(data[2]))
                elif name == 'grid_clear' and data[0] == 1:
                    self.cells = [[(' ', 0) for _ in range(self.width)] for _ in range(self.height)]
                elif name == 'grid_line' and data[0] == 1:
                    _, row, col, values, *_ = data
                    if not 0 <= row < self.height:
                        continue
                    style = 0
                    for item in values:
                        if len(item) > 1:
                            style = int(item[1])
                        count = min(int(item[2]) if len(item) > 2 else 1, self.width)
                        for _ in range(count):
                            if 0 <= col < self.width:
                                self.cells[row][col] = (str(item[0]), style)
                            col += 1
                elif name == 'grid_scroll' and data[0] == 1:
                    _, top, bottom, left, right, rows, columns, *_ = data
                    if not (0 <= top <= bottom <= self.height and
                            0 <= left <= right <= self.width):
                        continue
                    old = [r[:] for r in self.cells]
                    for y in range(top, bottom):
                        for x in range(left, right):
                            sy, sx = y + int(rows), x + int(columns)
                            self.cells[y][x] = old[sy][sx] if top <= sy < bottom and left <= sx < right else (' ', 0)
                elif name == 'grid_cursor_goto' and data[0] == 1:
                    self.cursor = [int(data[1]), int(data[2])]
                elif name == 'hl_attr_define':
                    style_id, attributes, *_ = data
                    self.styles[int(style_id)] = {k: v for k, v in attributes.items()
                                                  if k in ('foreground', 'background', 'bold', 'italic', 'underline', 'reverse')}
                elif name == 'default_colors_set':
                    self.foreground, self.background = int(data[0]), int(data[1])
                elif name == 'flush':
                    self.version += 1

    def snapshot(self, since: int) -> dict:
        if self.version == since:
            return {'version': self.version, 'changed': False}
        lines = []
        for row in self.cells:
            spans: list[list[Any]] = []
            for char, style in row:
                if spans and spans[-1][1] == style:
                    spans[-1][0] += char
                else:
                    spans.append([char, style])
            lines.append(spans)
        return {'version': self.version, 'changed': True, 'rows': lines,
                'width': self.width, 'height': self.height, 'cursor': self.cursor[:],
                'styles': self.styles.copy(), 'fg': self.foreground, 'bg': self.background}


class NeovimSession:
    def __init__(self, root: Path, source: dict, *, width: int = 80, height: int = 24):
        try:
            import msgpack
        except ImportError as exc:
            raise NeovimUnavailable('Install msgpack (pip install msgpack)') from exc
        executable = shutil.which('nvim')
        if not executable:
            raise NeovimUnavailable('Install nvim in WSL')
        self._msgpack = msgpack
        self.token = secrets.token_urlsafe(24)
        self.grid = NeovimGrid()
        self.lock = threading.RLock()
        self.write_lock = threading.Lock()
        self.pending: dict[int, tuple[threading.Event, list]] = {}
        self.next_id = 0
        self.error = ''
        self.process = subprocess.Popen([executable, '--embed'], cwd=root,
                                        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                        stderr=subprocess.DEVNULL, bufsize=0)
        self.reader = threading.Thread(target=self._read, daemon=True)
        self.reader.start()
        try:
            self.request('nvim_ui_attach', [width, height, {'rgb': True, 'ext_linegrid': True}], timeout=5)
            # Populate a scratch buffer; do not open real project files for writing.
            self.request('nvim_command', ['enew'], timeout=5)
            self.request('nvim_command', ['setlocal buftype=nofile noswapfile'], timeout=5)
            self.request('nvim_buf_set_lines', [0, 0, -1, True, source['code'].split('\n')], timeout=5)
            self.request('nvim_command', ['setlocal filetype=systemverilog readonly nomodifiable'], timeout=5)
        except Exception:
            self.close()
            raise

    def _send(self, message: list) -> None:
        data = self._msgpack.packb(message, use_bin_type=True)
        with self.write_lock:
            if self.process.poll() is not None or not self.process.stdin:
                raise NeovimUnavailable('Neovim process exited')
            self.process.stdin.write(data)

    def request(self, method: str, params: list, *, timeout: float = 2) -> Any:
        with self.lock:
            self.next_id += 1
            request_id = self.next_id
            ready = threading.Event()
            result: list = []
            self.pending[request_id] = (ready, result)
        try:
            self._send([0, request_id, method, params])
            if not ready.wait(timeout):
                raise NeovimUnavailable('Neovim RPC timed out: ' + method)
            if result[0] is not None:
                raise NeovimUnavailable('Neovim RPC error: ' + str(result[0])[:300])
            return result[1]
        finally:
            with self.lock:
                self.pending.pop(request_id, None)

    def notify(self, method: str, params: list) -> None:
        self._send([2, method, params])

    def _read(self) -> None:
        unpacker = self._msgpack.Unpacker(raw=False, strict_map_key=False)
        try:
            while self.process.poll() is None and self.process.stdout:
                chunk = os.read(self.process.stdout.fileno(), 65536)
                if not chunk:
                    break
                unpacker.feed(chunk)
                for msg in unpacker:
                    if not isinstance(msg, list):
                        continue
                    if msg[0] == 1 and len(msg) >= 4:
                        with self.lock:
                            pending = self.pending.get(msg[1])
                            if pending:
                                pending[1][:] = [msg[2], msg[3]]
                                pending[0].set()
                    elif msg[0] == 2 and len(msg) >= 3 and msg[1] == 'redraw':
                        with self.lock:
                            self.grid.update(msg[2])
                    elif msg[0] == 0 and len(msg) >= 4:
                        # No remote plugin requests are implemented by this UI.
                        self._send([1, msg[1], 'Unsupported UI request', None])
        except (OSError, ValueError, TypeError) as exc:
            self.error = str(exc)[:200]
        finally:
            with self.lock:
                for ready, result in self.pending.values():
                    result[:] = [self.error or 'Neovim disconnected', None]
                    ready.set()

    def snapshot(self, since: int) -> dict:
        with self.lock:
            data = self.grid.snapshot(since)
        if self.process.poll() is not None:
            return {'status': 'closed', 'reason': self.error or 'Neovim exited'}
        return {'status': 'available', **data}

    def close(self) -> None:
        try:
            if self.process.poll() is None:
                self.process.terminate()
                self.process.wait(timeout=1)
        except (OSError, subprocess.TimeoutExpired):
            self.process.kill()


def bounded_size(cols: Any, rows: Any) -> tuple[int, int]:
    try:
        width, height = int(cols), int(rows)
    except (ValueError, TypeError) as exc:
        raise ValueError('Invalid Neovim grid dimensions') from exc
    if not 20 <= width <= 220 or not 4 <= height <= 100:
        raise ValueError('Neovim dimensions outside 20..220 cols or 4..100 rows')
    return width, height
