from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Optional


@dataclass(frozen=True)
class RunRef:
    workspace: Path
    run_top: str
    run_id: str
    top: Optional[str] = None

    @property
    def run_dir(self) -> Path:
        return self.workspace / "runs" / self.run_top / self.run_id

    @property
    def ips_dir(self) -> Path:
        return self.run_dir / "ips"

    @property
    def logs_dir(self) -> Path:
        return self.run_dir / "logs"

    @property
    def reports_dir(self) -> Path:
        return self.run_dir / "reports"

    def ip_dir(self, ip_name: Optional[str] = None) -> Path:
        name = ip_name or self.top
        if not name:
            raise ValueError("ip_dir requires an IP name or RunRef.top")
        return self.ips_dir / name


def resolve_run_ref(
    *,
    workspace: Path,
    top: Optional[str],
    run_top: Optional[str],
    run_id: Optional[str],
) -> Optional[RunRef]:
    effective_run_top = run_top or top
    if not effective_run_top or not run_id:
        return None
    return RunRef(
        workspace=Path(workspace).expanduser().resolve(),
        run_top=effective_run_top,
        run_id=run_id,
        top=top,
    )
