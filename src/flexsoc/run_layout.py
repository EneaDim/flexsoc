"""Canonical FlexSoC run paths with local PDK scoping.

FlexSoC keeps logical design/DV artifacts under one shared run root and adds the
PDK name only where an artifact becomes technology dependent.  This preserves a
human-readable hierarchy such as ``syn/sky130`` and
``signoff/ihp-sg13g2/equivalence`` instead of introducing a parallel ``tech``
tree.
"""

from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping


def _slug(value: str) -> str:
    """Return a safe deterministic directory component."""

    text = re.sub(r"[^A-Za-z0-9_.-]+", "_", str(value).strip())
    text = text.strip("._")
    if not text or text in {".", ".."}:
        raise ValueError(f"invalid path component {value!r}")
    return text


def run_root(workspace: Path, *, run_top: str, run_id: str) -> Path:
    """Return the PDK-independent root for one logical run."""

    return workspace.expanduser().resolve() / "runs" / _slug(run_top) / _slug(run_id)


@dataclass(frozen=True, slots=True)
class PDKRunLayout:
    """Technology-dependent artifact locations for one selected PDK."""

    run_root: Path
    pdk: str
    top: str

    @property
    def syn_dir(self) -> Path:
        return self.run_root / "syn" / self.pdk

    @property
    def synthesis_log_dir(self) -> Path:
        return self.run_root / "logs" / "synthesis" / self.pdk

    @property
    def signoff_pdk_root(self) -> Path:
        return self.signoff_root / self.pdk

    def signoff_stage_root(self, stage: str) -> Path:
        """Return the stage-specific sign-off root without moving post-synthesis outputs."""

        if stage == "post_syn":
            return self.signoff_pdk_root
        if stage in {"post_route", "post_pnr"}:
            return self.signoff_pdk_root / "post_pnr"
        raise ValueError(f"unsupported sign-off stage: {stage}")

    def signoff_stage_log_root(self, stage: str) -> Path:
        """Return the matching stage-specific sign-off log root."""

        root = self.run_root / "logs" / "signoff" / self.pdk
        if stage == "post_syn":
            return root
        if stage in {"post_route", "post_pnr"}:
            return root / "post_pnr"
        raise ValueError(f"unsupported sign-off stage: {stage}")

    @property
    def equivalence_dir(self) -> Path:
        return self.signoff_pdk_root / "equivalence" / "rtl_vs_syn"

    @property
    def equivalence_log(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "equivalence" / f"{self.top}_rtl_vs_syn.log"

    @property
    def post_syn_sim_dir(self) -> Path:
        return self.run_root / "dv" / "functional" / "sim" / "post_syn" / self.pdk

    @property
    def post_pnr_sim_dir(self) -> Path:
        return self.run_root / "dv" / "functional" / "sim" / "post_pnr" / self.pdk

    @property
    def post_syn_log_dir(self) -> Path:
        return self.run_root / "logs" / "dv" / "functional" / "post_syn" / self.pdk

    @property
    def post_pnr_log_dir(self) -> Path:
        return self.run_root / "logs" / "dv" / "functional" / "post_pnr" / self.pdk

    @property
    def pnr_dir(self) -> Path:
        """Return the physical-implementation branch for the selected PDK."""

        return self.run_root / "impl" / self.pdk

    @property
    def signoff_sdc(self) -> Path:
        """Return the canonical PDK-scoped SDC owned by sign-off setup."""

        return self.signoff_pdk_root / f"{self.top}.sdc"

    @property
    def pnr_log_dir(self) -> Path:
        return self.run_root / "logs" / "pnr" / self.pdk

    @property
    def signoff_root(self) -> Path:
        return self.run_root / "signoff"

    @property
    def sta_dir(self) -> Path:
        return self.signoff_pdk_root / "sta"

    @property
    def power_dir(self) -> Path:
        return self.signoff_pdk_root / "power"

    @property
    def sdf_dir(self) -> Path:
        return self.signoff_pdk_root / "sdf"


    @property
    def fusion_dir(self) -> Path:
        return self.signoff_pdk_root / "fusion"

    @property
    def fusion_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "fusion"

    @property
    def path_view_dir(self) -> Path:
        return self.signoff_pdk_root / "path_view"

    @property
    def sta_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "sta"

    @property
    def power_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "power"

    @property
    def sdf_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "sdf"

    @property
    def meta_dir(self) -> Path:
        return self.run_root / "meta" / self.pdk

    @property
    def command_log_dir(self) -> Path:
        return self.run_root / "logs" / "commands" / self.pdk

    def as_dict(self) -> dict[str, str]:
        """Return stable paths suitable for manifests and diagnostics."""

        return {
            "synthesis": str(self.syn_dir),
            "equivalence": str(self.equivalence_dir),
            "post_syn_sim": str(self.post_syn_sim_dir),
            "post_pnr_sim": str(self.post_pnr_sim_dir),
            "implementation": str(self.pnr_dir),
            "post_pnr_signoff": str(self.signoff_stage_root("post_route")),
            "sdc": str(self.signoff_sdc),
            "sta": str(self.sta_dir),
            "power": str(self.power_dir),
            "fusion": str(self.fusion_dir),
            "sdf": str(self.sdf_dir),
            "path_view": str(self.path_view_dir),
            "meta": str(self.meta_dir),
        }


def pdk_run_layout(run_dir: Path, *, pdk: str, top: str) -> PDKRunLayout:
    """Build the canonical PDK-scoped layout below an existing run root."""

    return PDKRunLayout(run_dir.expanduser().resolve(), _slug(pdk), _slug(top))


def layout_from_values(project_root: Path, values: Mapping[str, str]) -> PDKRunLayout:
    """Resolve the canonical layout from standard FlexSoC values."""

    workspace = Path(values.get("WORKSPACE", project_root / "workspace"))
    top = values.get("TOP", "test")
    run_top = values.get("RUN_TOP") or top
    run_id = values.get("RUN_ID", "default")
    pdk = values.get("PDK", "sky130")
    shared = run_root(workspace, run_top=run_top, run_id=run_id)
    return pdk_run_layout(shared, pdk=pdk, top=top)


def pdk_make_paths(project_root: Path, values: Mapping[str, str]) -> dict[str, str]:
    """Return Make-path overrides for technology-dependent outputs."""

    layout = layout_from_values(project_root, values)
    return {
        "RUN_ROOT": str(layout.run_root),
        "SIGNOFF_SDC_FILE": str(layout.signoff_sdc),
        "SYNDIR": str(layout.syn_dir),
        "SYNTH_LOGDIR": str(layout.synthesis_log_dir),
        "EQUIVDIR": str(layout.equivalence_dir),
        "EQUIV_LOG": str(layout.equivalence_log),
        "SIGNOFFDIR": str(layout.signoff_root),
        "SIGNOFF_PDK_DIR": str(layout.signoff_pdk_root),
        "SIGNOFF_STA_DIR": str(layout.sta_dir),
        "SIGNOFF_POWER_DIR": str(layout.power_dir),
        "SIGNOFF_SDF_DIR": str(layout.sdf_dir),
        "SIGNOFF_FUSION_DIR": str(layout.fusion_dir),
        "SIGNOFF_PATH_VIEW_DIR": str(layout.path_view_dir),
        "STA_LOGDIR": str(layout.sta_log_dir),
        "POWER_LOGDIR": str(layout.power_log_dir),
        "SDF_LOGDIR": str(layout.sdf_log_dir),
        "FUSION_LOGDIR": str(layout.fusion_log_dir),
        "ORSDIR": str(layout.pnr_dir),
        "OR_WORKDIR": str(layout.pnr_dir),
        "OR_LOGDIR": str(layout.pnr_log_dir),
        "POST_SYN_SIMDIR": str(layout.post_syn_sim_dir),
        "POST_LAYOUT_SIMDIR": str(layout.post_pnr_sim_dir),
        "METADIR": str(layout.meta_dir),
        "METRICS_JSON": str(layout.meta_dir / "metrics.json"),
        "MANIFEST_JSON": str(layout.meta_dir / "manifest.json"),
        "COMMAND_LOGDIR": str(layout.command_log_dir),
    }
