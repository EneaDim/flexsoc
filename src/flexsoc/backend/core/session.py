"""Backend target session: lifecycle, provenance and domain delegation."""

from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
from typing import Mapping, Sequence

from ..impl.impl import orfs_paths
from ..signoff.sta import SDF_MODE_TO_CORNER
from .lifecycle import Lifecycle, PROVENANCE_SETUPS, RUNTIME_STAGES, STAGE_CONTRACTS
from .target import BACKEND_TARGETS, Target as BackendTarget


DEFAULT_SETTINGS = {
    "TOP": "test", "HOST": "uart", "FORCE": "0", "RUN_ID": "default",
    "N_CLOCKS": "1", "PDK": "sky130", "TARGET_OPT": "delay1",
    "PNR_HOLD_SLACK_MARGIN": "0.10", "WAVE_FORMAT": "fst",
    "GLS_SIMULATOR": "iverilog", "GLS_BACKEND": "sv", "TIMING_MODE": "zero",
    "GLS_UNIT_DELAY": "1ps", "SDF_STRICT": "1", "FST2VCD": "fst2vcd",
    "SIGNOFF_STAGE": "post_syn", "POWER_VCD_SCOPE": "auto",
    "POWER_DUT_INSTANCE": "auto", "QUAL_LEVEL": "auto",
}

DEBUG_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.debug)
TECHNOLOGY_TARGETS = {name for name, target in BACKEND_TARGETS.items() if target.technology} | {
    "path_view", "ip_save", "metrics", "manifest", "manifest_show", "check",
    "clean_syn", "clean_signoff", "clean_pnr", "clean_meta",
}
SETUP_TARGETS: dict[str, tuple[str, ...]] = {
    "sdc": ("sdc.setup",), "model": ("model.setup",),
    "tb": ("tb.setup",), "cocotb": ("cocotb.setup",),
}
SETUP_TARGETS.update({name: target.setup for name, target in BACKEND_TARGETS.items() if target.setup})
SETUP_STAGES = frozenset(stage for stages in SETUP_TARGETS.values() for stage in stages)
SETUP_ONLY_TARGETS = frozenset({"sdc", "model", "tb"})
RUN_DEPENDENCIES: dict[str, tuple[str, ...]] = {
    **SETUP_TARGETS,
    "sim_post_syn_all": ("sdf",),
    "sim_post_pnr_all": ("sdf_post_pnr",),
    "pnr.setup": ("syn", "signoff.setup"),
}
GLS_PROVENANCE_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.is_gls)
DESIGN_INTENT_KEYS = ("TOP", "N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS", "REG_ITF")
SETTINGS_EVIDENCE_KEYS = tuple(sorted({
    *DEFAULT_SETTINGS, *DESIGN_INTENT_KEYS,
    *(key for stage in STAGE_CONTRACTS.values() for key in stage.config),
    "PDK", "PDK_ROOT", "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT",
    "LIB_SYN", "LIBS", "PRIM", "MACRO_LIBS", "ORS", "ORS_TECH",
    "SDC_IO_DELAY_PCT", "GLS_BACKEND", "GLS_SIMULATOR", "TIMING_MODE", "SDF_STRICT",
}))
POST_PNR_SIGNOFF_TARGETS = frozenset(
    name for name, target in BACKEND_TARGETS.items() if target.stage == "post_impl" and not name.endswith(".setup")
)
ACTIVITY_ANALYSIS_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.is_activity)
STREAM_BY_DEFAULT_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.stream)
QUIET_BY_DEFAULT_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.quiet)


def dependencies(target: str, timing_mode: str) -> tuple[str, ...]:
    """Return declared prerequisites for one run or setup stage."""

    deps = RUN_DEPENDENCIES.get(target, ())
    if timing_mode in SDF_MODE_TO_CORNER:
        if target in {"compile_post_syn", "sim_post_syn"}:
            return (*deps, "sdf")
        if target in {"compile_post_pnr", "sim_post_pnr"}:
            return (*deps, "sdf_post_pnr")
    return deps


def setup_public(stage: str) -> str:
    """Return the public keyword owning one internal setup stage."""

    return {
        "formal.prove.setup": "formal_prove", "formal.cover.setup": "formal_cover",
        "formal.csr_prove.setup": "formal_csr_prove",
        "formal.csr_cover.setup": "formal_csr_cover",
        "signoff.setup": "signoff", "signoff_post_pnr.setup": "signoff_post_pnr",
    }.get(stage, stage.removesuffix(".setup"))


def setup_command(stage: str, *, force: bool = False) -> str:
    return f"fx {setup_public(stage)} --setup" + (" --force" if force else "")


def _returncode(value: object) -> int:
    """Normalize nested backend results to one target return code."""

    if value is None or isinstance(value, (Path, str, dict)):
        return 0
    if isinstance(value, bool):
        return 0 if value else 1
    if isinstance(value, int):
        return value
    if hasattr(value, "returncode"):
        return int(getattr(value, "returncode"))
    if isinstance(value, (tuple, list)):
        return next((rc for item in value if (rc := _returncode(item))), 0)
    return 0


class TargetSession:
    """Execute one FlexSoC lifecycle target through the domain backend."""

    def __init__(
        self, project_root: Path, workdir: Path, values: Mapping[str, str], *,
        settings: Mapping[str, str] | None = None, execution_targets=None, on: str = "local",
    ):
        from .. import Backend
        from .core import BackendContext
        from .execution import ToolRunner

        self.project_root = Path(project_root).resolve()
        self.workdir = Path(workdir).resolve()
        self.settings = dict(settings or {})
        self.values = dict(values)
        self.on = on
        self.context = BackendContext(self.project_root, self.workdir, self.values)
        self.runner = ToolRunner(execution_targets, project_root=self.project_root)
        self.backend = Backend(self.context, self.runner)
        self.paths = self.context.paths
        self.lifecycle = Lifecycle(
            project_root=self.project_root,
            run_root=self.paths.run,
            pdk_meta=self.paths.meta,
            values=self.values,
            pdk=self.paths.pdk,
            top=self.paths.top,
        )

    @staticmethod
    def _bool(value: object, default: bool = False) -> bool:
        if value is None:
            return default
        return str(value).strip().lower() in {"1", "true", "yes", "on"}

    def _words(self, key: str, default: str = "") -> tuple[str, ...]:
        return tuple(part for part in self.values.get(key, default).replace(",", " ").split() if part)


    def _rtl_sources(self) -> tuple[Path, ...]:
        sources: list[Path] = []
        for filelist in (self.paths.rtl_common, self.paths.rtl_ip):
            if not filelist.is_file():
                continue
            for line in filelist.read_text(encoding="utf-8").splitlines():
                item = line.strip()
                if item and not item.startswith(("#", "+", "-")):
                    sources.append(Path(item))
        return tuple(sources)

    @staticmethod
    def _write_json_atomic(path: Path, data: Mapping[str, object]) -> None:
        """Write one deterministic JSON evidence file atomically."""

        path.parent.mkdir(parents=True, exist_ok=True)
        temp = path.with_name(f".{path.name}.{os.getpid()}.tmp")
        temp.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        temp.replace(path)

    def _design_intent_sources(self) -> tuple[Path, ...]:
        """Return canonical authored sources; generated views are excluded."""

        p, top = self.paths, self.paths.top
        generated_model = {f"{top}_regmap.py", f"{top}_regmap_tests.py"}
        sources = [p.csr / f"{top}.hjson", p.sdc]
        for path in sorted(p.rtl.glob("*.sv")):
            header = path.read_text(encoding="utf-8", errors="replace")[:512].lower()
            if "auto-generated by flexsoc.backend.design.rtl" not in header and "auto-generated by `reggen`" not in header:
                sources.append(path)
        sources += sorted(path for path in p.model.glob("*.py") if path.name not in generated_model)
        sources += sorted((p.formal / "properties").rglob("*.sv"))
        return tuple(dict.fromkeys(sources))

    def _design_intent_snapshot(self) -> tuple[dict[str, str | None], ...]:
        snapshot = []
        for path in self._design_intent_sources():
            digest = hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else None
            snapshot.append({"path": path.relative_to(self.paths.run).as_posix(), "sha256": digest})
        return tuple(snapshot)

    def _design_intent(self) -> tuple[dict[str, str], tuple[dict[str, str | None], ...], str]:
        """Return canonical authored intent, source snapshot, and aggregate hash."""

        intent = {key: self.values.get(key, "") for key in DESIGN_INTENT_KEYS if key in self.values}
        sources = self._design_intent_snapshot()
        digest = hashlib.sha256(json.dumps(
            {"design_intent": intent, "sources": sources},
            sort_keys=True, separators=(",", ":"),
        ).encode()).hexdigest()
        return intent, sources, digest

    def _write_settings_evidence(self, target: str) -> None:
        """Snapshot authored IP intent separately from run/PDK execution state."""

        intent, sources, intent_sha256 = self._design_intent()
        self._write_json_atomic(
            self.paths.run / "meta" / "design_intent.json",
            {
                "schema": 2,
                "top": self.paths.top,
                "run_top": self.paths.run_top,
                "run_id": self.paths.run_id,
                "ip_intent_sha256": intent_sha256,
                "design_intent": intent,
                "sources": sources,
            },
        )
        if target not in TECHNOLOGY_TARGETS:
            return
        effective = {
            key: self.values[key]
            for key in SETTINGS_EVIDENCE_KEYS
            if key in self.values
        }
        self._write_json_atomic(
            self.paths.meta / "settings.json",
            {
                "schema": 1,
                "pdk": self.paths.pdk,
                "top": self.paths.top,
                "run_top": self.paths.run_top,
                "run_id": self.paths.run_id,
                "persistent": dict(sorted(self.settings.items())),
                "ip_intent_sha256": intent_sha256,
                "design_intent": intent,
                "effective": effective,
            },
        )

    def _configured_paths(self, *keys: str) -> tuple[Path, ...]:
        paths: list[Path] = []
        for key in keys:
            for token in self._words(key):
                path = Path(token).expanduser()
                resolved = self.project_root / path if not path.is_absolute() else path
                paths.append(resolved.resolve())
        return tuple(paths)

    def _provenance_inputs(self, stage: str) -> tuple[Path, ...]:
        """Return effective source artifacts consumed by one generated setup."""

        p = self.paths
        rtl = (p.rtl_common, p.rtl_ip, *self._rtl_sources())
        if stage in RUNTIME_STAGES:
            if stage.startswith("lint_"):
                inputs = rtl
            elif stage == "cdc_rdc":
                inputs = self._execution_inputs("cdc_rdc.setup")
            elif stage == "regression":
                inputs = (*rtl, p.sdc, p.tests, p.model, *self._execution_inputs("tb.setup"), *self._execution_inputs("cocotb.setup"))
            elif stage.startswith("formal_"):
                setup = {
                    "formal_csr_bmc": "formal.csr_prove.setup",
                    "formal_csr_prove": "formal.csr_prove.setup",
                    "formal_csr_cover": "formal.csr_cover.setup",
                    "formal_bmc": "formal.prove.setup",
                    "formal_prove": "formal.prove.setup",
                    "formal_cover": "formal.cover.setup",
                }[stage]
                inputs = self._execution_inputs(setup)
            elif stage == "syn":
                inputs = self._execution_inputs("syn.setup")
            elif stage == "eqy":
                inputs = self._execution_inputs("eqy.setup")
            elif stage in {"sdf", "sta", "power_estimate"}:
                inputs = self._execution_inputs("signoff.setup")
            elif stage == "sim_post_syn_all":
                inputs = (*rtl, p.tests, *self._execution_inputs("tb.setup"), p.syn / f"{p.top}_synth.v", p.signoff / "sdf")
            elif stage == "power_analysis_all":
                inputs = (*self._execution_inputs("signoff.setup"), p.sim / "post_syn" / p.pdk)
            elif stage == "fusion_analysis_all":
                inputs = (p.signoff / "power" / "analysis",)
            elif stage == "pnr":
                makefile, _ = orfs_paths(self.values, self.paths.impl)
                inputs = (*self._execution_inputs("pnr.setup"), makefile)
            elif stage == "physical_signoff":
                makefile, config = orfs_paths(self.values, self.paths.impl)
                inputs = (*self._evidence_paths("pnr"), makefile, config)
            elif stage in {"sdf_post_pnr", "sta_post_pnr", "power_estimate_post_pnr"}:
                inputs = self._execution_inputs("signoff_post_pnr.setup")
            elif stage == "sim_post_pnr_all":
                inputs = (
                    *rtl, p.tests, *self._execution_inputs("tb.setup"),
                    *self._execution_inputs("signoff_post_pnr.setup"),
                    p.signoff / "post_pnr" / "sdf",
                )
            elif stage == "power_analysis_post_pnr_all":
                inputs = (*self._execution_inputs("signoff_post_pnr.setup"), p.sim / "post_pnr" / p.pdk)
            elif stage == "fusion_analysis_post_pnr_all":
                inputs = (p.signoff / "post_pnr" / "power" / "analysis",)
            else:
                raise ValueError(f"provenance inputs are not defined for {stage}")
            return tuple(dict.fromkeys(Path(path).expanduser().resolve() for path in inputs))
        if stage == "model.setup":
            inputs = (*sorted(p.csr.glob("*.hjson")), p.rtl / f"{p.top}.sv")
        elif stage == "sdc.setup":
            top_file = p.rtl / f"{p.top}.sv"
            inputs = (top_file,) if self.context.clocks.multiclock else ()
        elif stage in {"tb.setup", "cocotb.setup"}:
            inputs = (p.csr / f"{p.top}.hjson", p.sdc)
        elif stage == "cdc_rdc.setup":
            inputs = (*rtl, p.sdc)
        elif stage in {"formal.prove.setup", "formal.cover.setup"}:
            mode = "cover" if ".cover." in stage else "prove"
            inputs = (*rtl, p.formal / "properties" / mode)
        elif stage.startswith("formal.csr_"):
            inputs = rtl
        elif stage == "syn.setup":
            makefile, _ = orfs_paths(self.values, self.paths.impl)
            platform = self.values.get("ORS_TECH", self.values.get("PDK", ""))
            platform_config = makefile.parent / "platforms" / platform / "config.mk"
            inputs = (
                *rtl, p.sdc, *self._configured_paths("LIB_SYN", "LIBS"),
                makefile, platform_config,
            )
        elif stage == "eqy.setup":
            inputs = (
                *rtl, p.syn / f"{p.top}_synth.v",
                *self._configured_paths("LIB_SYN", "PRIM", "FORMAL_PDK_PROC"),
            )
        elif stage == "signoff.setup":
            inputs = (
                p.sdc, p.syn / f"{p.top}_synth.v",
                *self._configured_paths("LIBS", "LIB_SYN", "PRIM", "MACRO_LIBS"),
            )
        elif stage == "pnr.setup":
            inputs = (p.syn / f"{p.top}_synth.v", p.sdc)
        elif stage == "signoff_post_pnr.setup":
            from .backend.signoff.sta import _stage_inputs, _stage_sdc

            values = {**self.values, "SIGNOFF_STAGE": "post_route"}
            netlist, spef = _stage_inputs(self.project_root, values)
            inputs = (
                netlist, _stage_sdc(self.project_root, values),
                *(() if spef is None else (spef,)),
                *self._configured_paths("LIBS", "LIB_SYN", "PRIM", "MACRO_LIBS"),
            )
        else:
            raise ValueError(f"provenance is not defined for {stage}")
        return tuple(dict.fromkeys(Path(path).expanduser().resolve() for path in inputs))

    @staticmethod
    def _result_paths(value: object) -> tuple[Path, ...]:
        if isinstance(value, Path):
            return (value,)
        if isinstance(value, (tuple, list)):
            return tuple(path for item in value for path in TargetSession._result_paths(item))
        return ()

    def _evidence_paths(self, stage: str) -> tuple[Path, ...]:
        return self.lifecycle.evidence(stage)

    def _generated_paths(self, stage: str, result: object) -> tuple[Path, ...]:
        if stage in RUNTIME_STAGES:
            return self._evidence_paths(stage)
        paths = self._result_paths(result)
        if stage == "cdc_rdc.setup":
            paths = (self.paths.cdc_rdc / "extract.ys",)
        elif stage == "eqy.setup":
            out = self.context.layout.equivalence_dir
            bindings = [
                *(out / path.name for path in (self.paths.rtl_common, self.paths.rtl_ip)),
                *(out / f"cell_model_{index}{Path(model).suffix or '.v'}"
                  for index, model in enumerate(self._words("PRIM"))),
                out / "netlist.v", out / "library.lib",
                out / "sky130_clock_gates_formal.v", out / "formal_pdk.v",
            ]
            paths += tuple(path for path in bindings if path.exists() or path.is_symlink())
        elif stage.startswith("formal.csr_"):
            mode = "cover" if ".cover." in stage else "prove"
            paths += (self.paths.formal / "csr" / mode / f"{self.paths.top}_csr_auto_{mode}.sv",)
        return tuple(dict.fromkeys(path.expanduser().absolute() for path in paths))

    def _setup_stages(self, target: str) -> tuple[str, ...]:
        """Resolve only provenance-bearing setup dependencies for a runtime target."""

        timing = self.values.get("TIMING_MODE", "zero").strip().lower()
        found: list[str] = []

        def visit(name: str) -> None:
            for dependency in dependencies(name, timing):
                if dependency in PROVENANCE_SETUPS:
                    if dependency not in found:
                        found.append(dependency)
                else:
                    visit(dependency)

        visit(target)
        if target in GLS_PROVENANCE_TARGETS:
            driver_setup = (
                "cocotb.setup"
                if self.values.get("GLS_BACKEND", "sv").strip().lower() == "cocotb"
                else "tb.setup"
            )
            if driver_setup not in found:
                found.append(driver_setup)
        return tuple(found)

    def _execution_inputs(self, stage: str) -> tuple[Path, ...]:
        return self.lifecycle.execution_inputs(stage, self._provenance_inputs)

    def _provenance_state(self, stage: str) -> str:
        return self.lifecycle.state(stage, self._provenance_inputs)

    def _provenance_summary(self) -> dict[str, object]:
        return self.lifecycle.summary(self._provenance_inputs)

    def _contract_state(self, stage: str) -> str:
        return self.lifecycle.contract_state(stage, self._provenance_inputs)

    def _contract_outcome(self, stage: str) -> str | None:
        return self.lifecycle.outcome(stage)

    def _qualification_evidence(
        self,
    ) -> tuple[dict[str, str], dict[str, str | None]]:
        """Return lifecycle freshness and outcomes consumed by qualification."""

        states = {
            stage: self._contract_state(stage)
            for stage in STAGE_CONTRACTS
            if stage in RUNTIME_STAGES
        }
        outcomes = {
            stage: self._contract_outcome(stage)
            for stage, state in states.items()
            if state != "MISSING"
        }
        return states, outcomes

    def _contract_status(self, *, write: bool = False) -> dict[str, object]:
        """Evaluate qualification from canonical lifecycle evidence."""

        states, outcomes = self._qualification_evidence()
        return self.backend.qualification.status(
            stage_states=states, stage_outcomes=outcomes,
            rtl_sources=self._rtl_sources(), write=write,
        )

    @staticmethod
    def _status_outcome(value: object) -> str | None:
        token = str(value).strip().lower()
        if token in {"pass", "passed", "ok", "success"}:
            return "PASS"
        if token in {"fail", "failed", "error", "fatal"}:
            return "FAILED"
        if token in {"review", "partial", "incomplete", "unknown", "unsupported", "warn", "warning"}:
            return "REVIEW"
        return None

    def _runtime_outcome(self, stage: str, result: object) -> str:
        """Derive a runtime outcome from canonical evidence, then from the return code."""

        statuses: list[str] = []
        for path in self._evidence_paths(stage):
            candidates = (path,) if path.is_file() else (path / "summary.json",)
            for candidate in candidates:
                if candidate.suffix != ".json" or not candidate.is_file():
                    continue
                try:
                    payload = json.loads(candidate.read_text(encoding="utf-8"))
                except (OSError, json.JSONDecodeError):
                    statuses.append("REVIEW")
                    continue
                if isinstance(payload, Mapping) and (status := self._status_outcome(payload.get("status"))) is not None:
                    statuses.append(status)
            if path.is_dir():
                if (path / "FAIL").is_file():
                    statuses.append("FAILED")
                elif (path / "PASS").is_file():
                    statuses.append("PASS")

        if "FAILED" in statuses:
            return "FAILED"
        if "REVIEW" in statuses:
            return "REVIEW"
        returncode = _returncode(result)
        if returncode != 0:
            return "FAILED"
        return "PASS"

    def _record_provenance(self, stage: str, result: object) -> None:
        generated = self._generated_paths(stage, result)
        if not generated:
            raise ValueError(f"{stage}: no contract evidence was produced")
        runtime = stage in RUNTIME_STAGES
        self.lifecycle.record(
            stage,
            inputs_for=self._provenance_inputs,
            generated=generated,
            outcome=self._runtime_outcome(stage, result) if runtime else None,
            returncode=_returncode(result) if runtime else None,
        )

    def _contract_parents(self, target: str) -> tuple[str, ...]:
        """Return transitive StageContract prerequisites in deterministic execution order."""

        if target not in STAGE_CONTRACTS:
            return self._setup_stages(target)
        found: list[str] = []

        def visit(stage: str) -> None:
            for parent in STAGE_CONTRACTS[stage].parents:
                visit(parent)
                if parent not in found:
                    found.append(parent)

        visit(target)
        return tuple(found)

    def _require_provenance(self, target: str) -> None:
        for stage in self._contract_parents(target):
            state = self._contract_state(stage)
            if state in {"CLEAN", "VALIDATED_OVERRIDE"}:
                continue
            if stage in PROVENANCE_SETUPS:
                if state == "MODIFIED":
                    action = f"run `fx validate_override --set STAGE={setup_public(stage)}` or regenerate with `{setup_command(stage, force=True)}`"
                elif state == "STALE":
                    action = f"regenerate the setup with `{setup_command(stage, force=True)}`"
                elif state == "MISSING":
                    action = f"generate the setup first with `{setup_command(stage)}`"
                else:
                    action = f"repair missing/inconsistent inputs, then regenerate with `{setup_command(stage, force=True)}`"
            else:
                public = stage if stage in BACKEND_TARGETS else stage.replace("_all", "")
                if state == "MISSING":
                    action = f"run the required parent first with `fx {public}`"
                else:
                    action = f"rerun the required parent with `fx {public}`"
            raise RuntimeError(f"{target}: {stage} provenance is {state}; {action}")

    def _reuse_setup(self, stage: str) -> tuple[Path, ...] | None:
        """Reuse an existing valid setup unless explicit --force requests regeneration."""

        if self._bool(self.values.get("FORCE")):
            return None
        store = self.lifecycle.store(stage)
        if stage not in store.stages():
            return None
        state = self._provenance_state(stage)
        if state in {"CLEAN", "VALIDATED_OVERRIDE"}:
            generated = store.generated(stage)
            print(f"[setup] {stage} state={state} reuse={len(generated)}")
            return generated
        if state == "MODIFIED":
            raise RuntimeError(
                f"{stage}: generated setup is MODIFIED; run `fx validate_override --set STAGE={stage}` "
                f"to keep the edit, or `{setup_command(stage, force=True)}` to regenerate it"
            )
        if state == "STALE":
            raise RuntimeError(
                f"{stage}: generated setup is STALE; regenerate explicitly with `{setup_command(stage, force=True)}`"
            )
        raise RuntimeError(
            f"{stage}: generated setup provenance is {state}; repair the inputs/artifacts and "
            f"regenerate explicitly with `{setup_command(stage, force=True)}`"
        )

    def _validate_override(self) -> str:
        stage = self.values.get("STAGE", "").strip().replace("-", "_")
        if stage not in PROVENANCE_SETUPS:
            candidates = self._setup_stages(stage) if stage in SETUP_TARGETS or stage in BACKEND_TARGETS else ()
            if len(candidates) != 1:
                choices = ", ".join(sorted(PROVENANCE_SETUPS))
                raise ValueError(f"STAGE must name one generated setup: {choices}")
            stage = candidates[0]
        state = self.lifecycle.validate(stage, self._provenance_inputs)
        print(f"[provenance] {stage} state={state}")
        return state

    def _execute_sequence(self, sequence: Sequence[str]) -> tuple[object, ...]:
        """Execute one explicit backend sequence in deterministic order."""

        return tuple(self.execute(name) for name in dict.fromkeys(sequence))

    def _execute_registered_target(self, target: BackendTarget) -> object:
        """Delegate one declarative target to its owning backend domain."""

        if target.sequence:
            return self._execute_sequence(target.sequence)

        inputs = ()
        if target.name not in PROVENANCE_SETUPS and len(target.setup) == 1:
            setup = target.setup[0]
            if setup in PROVENANCE_SETUPS:
                inputs = self._execution_inputs(setup)

        domain = target.domain
        if domain == "signoff":
            flow = self.backend.signoff.post_impl if target.stage == "post_impl" else self.backend.signoff.post_syn
            if self._bool(self.values.get("DEBUG")):
                return flow.debug_target(target, output=self.values.get("DEBUG_OUTPUT") or None)
            return flow.run_target(target, on=self.on)
        if domain == "design":
            return self.backend.design.run_target(target, on=self.on)
        if domain == "dv":
            if self._bool(self.values.get("DEBUG")):
                return self.backend.dv.debug_target(target, output=self.values.get("DEBUG_OUTPUT") or None)
            return self.backend.dv.run_target(target, inputs=inputs, on=self.on)
        if domain == "syn":
            return self.backend.syn.run_target(target, inputs=inputs, on=self.on)
        if domain == "impl":
            return self.backend.impl.run_target(target, on=self.on)
        if domain == "workspace":
            return self.backend.workspace.run_target(target, on=self.on)
        if domain == "toolchain":
            return self.backend.toolchain.run_target(target, self.values, on=self.on)
        if domain == "soc":
            return self.backend.design.soc.run_target(target, self.context, on=self.on)
        if domain == "fsm":
            return self.backend.design.fsm.run_target(target, self.context, on=self.on)
        if domain == "reporting":
            return self.backend.reporting.run_target(
                target, self.context, provenance=self._provenance_summary(),
            )
        if domain == "qualification":
            if target.action == "spec":
                return self.backend.qualification.run_target(
                    target, force=self._bool(self.values.get("FORCE")),
                )
            states, outcomes = self._qualification_evidence()
            return self.backend.qualification.run_target(
                target, stage_states=states, stage_outcomes=outcomes,
                rtl_sources=self._rtl_sources(),
            )
        if domain == "package":
            qualification = self._contract_status(write=True) if target.action == "save" else None
            return self.backend.package.run_target(
                target, self.context, qualification=qualification,
                cell_models=tuple(Path(item) for item in self._words("PRIM")),
                force=self._bool(self.values.get("FORCE")),
            )
        raise ValueError(f"unsupported backend domain: {domain!r}")

    def execute(self, target: str) -> object:
        """Apply explicit setup/provenance policy, then execute one backend target."""

        if target == "validate_override":
            return self._validate_override()
        if self._bool(self.values.get("DEBUG")):
            if target not in DEBUG_TARGETS:
                raise ValueError(f"--debug is not supported for target {target!r}")
            return self._execute_target(target)
        self._write_settings_evidence(target)
        if target in PROVENANCE_SETUPS:
            reused = self._reuse_setup(target)
            if reused is not None:
                return reused
            result = self._execute_target(target)
            self._record_provenance(target, result)
            return result
        if target not in SETUP_STAGES:
            self._require_provenance(target)
        result = self._execute_target(target)
        if target in RUNTIME_STAGES:
            self._record_provenance(target, result)
        return result

    def _execute_target(self, target: str) -> object:
        """Execute one public target through the declarative backend registry."""

        registered = BACKEND_TARGETS.get(target)
        if registered is None:
            raise NotImplementedError(f"backend target is not registered: {target}")
        return self._execute_registered_target(registered)


__all__ = [
    "TargetSession", "DEFAULT_SETTINGS", "DEBUG_TARGETS", "TECHNOLOGY_TARGETS",
    "SETUP_TARGETS", "SETUP_STAGES", "SETUP_ONLY_TARGETS",
    "POST_PNR_SIGNOFF_TARGETS", "ACTIVITY_ANALYSIS_TARGETS",
    "STREAM_BY_DEFAULT_TARGETS", "QUIET_BY_DEFAULT_TARGETS",
    "setup_public", "setup_command", "dependencies", "_returncode",
]
