"""Producer-declared transient build products, excluded from release sealing."""
from __future__ import annotations

import shutil
from pathlib import Path

from flexsoc.backend.core.flow.lifecycle import STAGE_CONTRACTS


class ArtifactPolicy:
    """One cache inventory shared by qualification and packaging."""

    @staticmethod
    def transient_roots(root: Path) -> tuple[Path, ...]:
        return tuple(root / relative for contract in STAGE_CONTRACTS.values()
                     for relative in contract.transient_outputs)

    @classmethod
    def is_transient(cls, root: Path, path: Path) -> bool:
        return any(path == folder or path.is_relative_to(folder)
                   for folder in cls.transient_roots(root))

    @classmethod
    def remove_transients(cls, root: Path) -> None:
        for folder in cls.transient_roots(root):
            if folder.is_symlink() or folder.is_file():
                folder.unlink()
            elif folder.is_dir():
                shutil.rmtree(folder)
