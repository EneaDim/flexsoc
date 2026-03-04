from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import List, Optional


def default_run_id() -> str:
    # filesystem-safe, human friendly
    return datetime.now().strftime("%Y%m%d_%H%M%S")


@dataclass(frozen=True)
class FlowConfig:
    """
    Minimal config object for make-based flows.

    Design goals:
    - Keep current CLI stable (this is internal).
    - Centralize how we map workspace/top/run_id to make variables.
    - Preserve existing contracts (workspace layout + log/report behavior).
    """
    workspace: Path
    top: Optional[str] = None
    run_id: Optional[str] = None

    def resolved_workspace(self) -> Path:
        return self.workspace

    def flow_run_dir(self) -> Optional[Path]:
        if not self.top or not self.run_id:
            return None
        return self.resolved_workspace() / "runs" / self.top / self.run_id

    def to_make_vars(self) -> List[str]:
        """
        Always enforce WORKSPACE. Optionally add TOP/RUN_ID when present.
        """
        ws = self.resolved_workspace()
        vars_: List[str] = [f"WORKSPACE={ws}"]

        if self.top:
            vars_.append(f"TOP={self.top}")
        if self.run_id:
            vars_.append(f"RUN_ID={self.run_id}")

        return vars_

    def with_run_id_if_needed(self, *, require: bool) -> "FlowConfig":
        """
        Return a config that has run_id set if required.
        If require=True and run_id missing -> generate one.
        """
        if self.run_id:
            return self
        if require:
            return FlowConfig(workspace=self.workspace, top=self.top, run_id=default_run_id())
        return self
