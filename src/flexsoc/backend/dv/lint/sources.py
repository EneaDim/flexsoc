"""Resolve portable RTL filelists for tools launched in the run directory."""

from __future__ import annotations

from pathlib import Path


class LintSources:
    """Materialize tool-only filelists without modifying release filelists.

    The portable source contract uses ``hw/`` and ``vendor/`` relative to the
    project and ``rtl/`` relative to the run, as in Slang hierarchy analysis.
    """

    def __init__(self, project: Path, run: Path):
        self.project = project.resolve()
        self.run = run.resolve()

    def resolve(self, token: str) -> Path:
        path = Path(token)
        if path.is_absolute() or ".." in path.parts or not path.parts:
            raise ValueError(f"nonportable RTL filelist path: {token}")
        root = self.project if path.parts[0] in {"hw", "vendor"} else self.run
        result = (root / path).resolve()
        if not result.is_relative_to(root):
            raise ValueError(f"RTL filelist path escapes its root: {token}")
        if not result.exists():
            raise FileNotFoundError(f"RTL filelist dependency missing: {token} ({result})")
        return result

    def prepare(
        self, filelists: tuple[Path, ...], *, directory: Path | None = None
    ) -> tuple[Path, ...]:
        directory = directory or (self.run / "dv" / "lint" / "inputs")
        prepared = []
        contents = []
        for filelist in filelists:
            lines = []
            for number, original in enumerate(filelist.read_text(encoding="utf-8").splitlines(), 1):
                item = original.strip()
                if not item or item.startswith("#"):
                    lines.append(original)
                elif item.startswith("+incdir+"):
                    entries = item[len("+incdir+"):].split("+")
                    lines.append("+incdir+" + "+".join(str(self.resolve(entry)) for entry in entries))
                elif item.startswith("+define+"):
                    lines.append(item)
                elif item.startswith(("+", "-")):
                    raise ValueError(f"unsupported RTL filelist directive: {filelist}:{number}: {item}")
                else:
                    lines.append(str(self.resolve(item)))
            contents.append("\n".join(lines) + "\n")
        directory.mkdir(parents=True, exist_ok=True)
        for index, content in enumerate(contents):
            path = directory / f"source_{index}.f"
            path.write_text(content, encoding="utf-8")
            prepared.append(path)
        return tuple(prepared)
