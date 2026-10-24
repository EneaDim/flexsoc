"""Compile user-specified SystemVerilog with slang; never parse RTL text."""
from __future__ import annotations

from dataclasses import dataclass
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess


@dataclass(frozen=True)
class SlangProject:
    root: Path
    top: str
    files: tuple[Path, ...] = ()
    filelists: tuple[Path, ...] = ()
    includes: tuple[Path, ...] = ()
    defines: tuple[str, ...] = ()
    slang: str = "slang"
    expand_cached_instances: bool = False

    def __post_init__(self) -> None:
        root = self.root.resolve()
        if not root.is_dir() or not self.top:
            raise ValueError("a project root and a top module are required")
        if not self.files and not self.filelists:
            raise ValueError("specify --file and/or --filelist (Slang is the RTL parser)")
        for entry in (*self.files, *self.filelists, *self.includes):
            resolved = self._resolve(entry)
            if not resolved.exists():
                raise FileNotFoundError(f"project input does not exist: {entry}")

    def _resolve(self, path: Path) -> Path:
        result = (self.root / path).resolve()
        if not result.is_relative_to(self.root.resolve()):
            raise ValueError(f"path outside project root: {path}")
        return result

    def compile(self, output: Path) -> Path:
        exe = shutil.which(self.slang) if not Path(self.slang).is_file() else str(Path(self.slang).resolve())
        if not exe:
            raise RuntimeError("SystemVerilog Slang executable missing; install slang or provide --slang")
        output = output.resolve()
        output.parent.mkdir(parents=True, exist_ok=True)
        argv: list[str] = [exe, "--top", self.top,
                           "--ast-json", str(output), "--ast-json-source-info"]
        # Explicit opt-in: disabling Slang's instance cache can be expensive
        # for large repeated designs, so keep compilation fast by default.
        if self.expand_cached_instances:
            argv.append("--disable-instance-caching")
        for directory in self.includes:
            argv.extend(("-I", str(self._resolve(directory))))
        for define in self.defines:
            argv.append("-D" + define)
        for filelist in self.filelists:
            argv.extend(("-F", str(self._resolve(filelist))))
        argv.extend(str(self._resolve(file)) for file in self.files)
        result = subprocess.run(argv, cwd=self.root.resolve(), capture_output=True, text=True, timeout=180)
        if result.returncode != 0 or not output.is_file():
            output.unlink(missing_ok=True)
            raise RuntimeError("Slang elaboration failed:\n" + (result.stderr + "\n" + result.stdout)[-8000:])
        payload = json.loads(output.read_text(encoding="utf-8"))
        if not isinstance(payload.get("design"), dict):
            output.unlink(missing_ok=True)
            raise ValueError("Slang output lacks elaborated 'design' object")
        return output


def ast_revision(payload: dict, *, top: str) -> str:
    """Stable for equivalent elaborations despite Slang's process-local addr fields."""
    def scrub(item):
        if isinstance(item, dict):
            result = {k: scrub(v) for k, v in item.items() if k not in ("addr", "internalSymbol")}
            symbol = result.get("symbol")
            if isinstance(symbol, str):
                address, separator, name = symbol.partition(" ")
                if separator and address.isdigit():
                    result["symbol"] = name
            return result
        if isinstance(item, list):
            return [scrub(x) for x in item]
        return item
    return sha256((top + json.dumps(scrub(payload), sort_keys=True, separators=(",", ":"))).encode()).hexdigest()[:16]
