"""Backend target session: lifecycle, provenance and domain delegation."""

from __future__ import annotations

import hashlib
import json
import os
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping, Sequence

from ...impl import ImplementationFlow
from ...signoff.sta import SDF_MODE_TO_CORNER
from .lifecycle import Lifecycle, PROVENANCE_SETUPS, RUNTIME_STAGES, STAGE_CONTRACTS
from ..core import BackendContext
from ..runtime.execution import CommandRequest, ToolRunner
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
    "eqy": ("eqy.setup",),
}
SETUP_TARGETS.update({name: target.setup for name, target in BACKEND_TARGETS.items() if target.setup})
SETUP_STAGES = frozenset(stage for stages in SETUP_TARGETS.values() for stage in stages)
SETUP_ONLY_TARGETS = frozenset({"sdc", "model", "tb"})
RUN_DEPENDENCIES: dict[str, tuple[str, ...]] = {
    **SETUP_TARGETS,
    "sim_post_syn_all": ("sdf",),
    "sim_post_impl_all": ("sdf_post_impl",),
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
POST_IMPL_SIGNOFF_TARGETS = frozenset(
    name for name, target in BACKEND_TARGETS.items() if target.stage == "post_impl" and not name.endswith(".setup")
)
ACTIVITY_ANALYSIS_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.is_activity)
STREAM_BY_DEFAULT_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.stream)
QUIET_BY_DEFAULT_TARGETS = frozenset(name for name, target in BACKEND_TARGETS.items() if target.quiet)



class TargetSession:
    """Execute one FlexSoC lifecycle target through the domain backend."""

    @staticmethod
    def dependencies(target: str, timing_mode: str) -> tuple[str, ...]:
        """Return declared prerequisites for one run or setup stage."""

        deps = RUN_DEPENDENCIES.get(target, ())
        if timing_mode in SDF_MODE_TO_CORNER:
            if target in {"compile_post_syn", "sim_post_syn"}:
                return (*deps, "sdf")
            if target in {"compile_post_impl", "sim_post_impl"}:
                return (*deps, "sdf_post_impl")
        return deps

    @staticmethod
    def setup_public(stage: str) -> str:
        """Return the public keyword owning one internal setup stage."""

        return {
            "formal.prove.setup": "formal_prove", "formal.cover.setup": "formal_cover",
            "formal.csr_prove.setup": "formal_csr_prove",
            "formal.csr_cover.setup": "formal_csr_cover",
            "signoff.setup": "signoff", "signoff_post_impl.setup": "signoff_post_impl",
        }.get(stage, stage.removesuffix(".setup"))

    @classmethod
    def setup_command(cls, stage: str, *, force: bool = False) -> str:
        """Return the public setup command owning one internal stage."""

        return f"fx {cls.setup_public(stage)} --setup" + (" --force" if force else "")

    @classmethod
    def returncode(cls, value: object) -> int:
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
            return next((rc for item in value if (rc := cls.returncode(item))), 0)
        return 0

    def __init__(
        self, project_root: Path, workdir: Path, values: Mapping[str, str], *,
        settings: Mapping[str, str] | None = None, execution_targets=None, on: str = "local",
    ):
        from ...backend import Backend
        from ..core import BackendContext
        from ..runtime.execution import ToolRunner

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
            if "auto-generated by flexsoc.backend.design.ip.rtl" not in header and "auto-generated by `reggen`" not in header:
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
                makefile, _ = ImplementationFlow.orfs_paths(self.values, self.paths.impl)
                inputs = (*self._execution_inputs("pnr.setup"), makefile)
            elif stage == "physical_signoff":
                makefile, config = ImplementationFlow.orfs_paths(self.values, self.paths.impl)
                inputs = (*self._evidence_paths("pnr"), makefile, config)
            elif stage in {"sdf_post_impl", "sta_post_impl", "power_estimate_post_impl"}:
                inputs = self._execution_inputs("signoff_post_impl.setup")
            elif stage == "sim_post_impl_all":
                inputs = (
                    *rtl, p.tests, *self._execution_inputs("tb.setup"),
                    *self._execution_inputs("signoff_post_impl.setup"),
                    p.signoff / "post_impl" / "sdf",
                )
            elif stage == "power_analysis_post_impl_all":
                inputs = (*self._execution_inputs("signoff_post_impl.setup"), p.sim / "post_impl" / p.pdk)
            elif stage == "fusion_analysis_post_impl_all":
                inputs = (p.signoff / "post_impl" / "power" / "analysis",)
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
            makefile, _ = ImplementationFlow.orfs_paths(self.values, self.paths.impl)
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
        elif stage == "signoff_post_impl.setup":
            from ...signoff.sta import StaAnalysis

            values = {**self.values, "SIGNOFF_STAGE": "post_route"}
            netlist, spef = StaAnalysis._stage_inputs(self.project_root, values)
            inputs = (
                netlist, StaAnalysis._stage_sdc(self.project_root, values),
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
        self._collect_setup_dependencies(target, timing, found)
        if target in GLS_PROVENANCE_TARGETS:
            driver_setup = (
                "cocotb.setup"
                if self.values.get("GLS_BACKEND", "sv").strip().lower() == "cocotb"
                else "tb.setup"
            )
            if driver_setup not in found:
                found.append(driver_setup)
        return tuple(found)

    def _collect_setup_dependencies(
        self,
        target: str,
        timing: str,
        found: list[str],
    ) -> None:
        for dependency in self.dependencies(target, timing):
            if dependency in PROVENANCE_SETUPS:
                if dependency not in found:
                    found.append(dependency)
            else:
                self._collect_setup_dependencies(dependency, timing, found)

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
        return self.backend.release.qualification.status(
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
        returncode = self.returncode(result)
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
            returncode=self.returncode(result) if runtime else None,
        )

    def _contract_parents(self, target: str) -> tuple[str, ...]:
        """Return transitive StageContract prerequisites in deterministic execution order."""

        if target not in STAGE_CONTRACTS:
            return self._setup_stages(target)
        found: list[str] = []
        self._collect_contract_parents(target, found)
        return tuple(found)

    def _collect_contract_parents(self, stage: str, found: list[str]) -> None:
        for parent in STAGE_CONTRACTS[stage].parents:
            self._collect_contract_parents(parent, found)
            if parent not in found:
                found.append(parent)

    def _require_provenance(self, target: str) -> None:
        for stage in self._contract_parents(target):
            state = self._contract_state(stage)
            if state in {"CLEAN", "VALIDATED_OVERRIDE"}:
                continue
            if stage in PROVENANCE_SETUPS:
                if state == "MODIFIED":
                    action = f"run `fx validate_override --set STAGE={self.setup_public(stage)}` or regenerate with `{self.setup_command(stage, force=True)}`"
                elif state == "STALE":
                    action = f"regenerate the setup with `{self.setup_command(stage, force=True)}`"
                elif state == "MISSING":
                    action = f"generate the setup first with `{self.setup_command(stage)}`"
                else:
                    action = f"repair missing/inconsistent inputs, then regenerate with `{self.setup_command(stage, force=True)}`"
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
                f"to keep the edit, or `{self.setup_command(stage, force=True)}` to regenerate it"
            )
        if state == "STALE":
            raise RuntimeError(
                f"{stage}: generated setup is STALE; regenerate explicitly with `{self.setup_command(stage, force=True)}`"
            )
        raise RuntimeError(
            f"{stage}: generated setup provenance is {state}; repair the inputs/artifacts and "
            f"regenerate explicitly with `{self.setup_command(stage, force=True)}`"
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
                return flow.debug(target, output=self.values.get("DEBUG_OUTPUT") or None)
            if target.name.endswith(".setup"):
                return flow.setup(target, on=self.on)
            return flow.run(target, on=self.on)
        if domain == "design":
            return self.backend.design.ip.run_target(target, on=self.on)
        if domain == "dv":
            if self._bool(self.values.get("DEBUG")):
                return self.backend.dv.debug_target(target, output=self.values.get("DEBUG_OUTPUT") or None)
            return self.backend.dv.run_target(target, inputs=inputs, on=self.on)
        if domain == "syn":
            if self._bool(self.values.get("DEBUG")):
                return self.backend.syn.debug_target(target, output=self.values.get("DEBUG_OUTPUT") or None)
            return self.backend.syn.run_target(target, inputs=inputs, on=self.on)
        if domain == "impl":
            return self.backend.impl.run_target(target, on=self.on)
        if domain == "workspace":
            return self.backend.core.workspace.run_target(target, on=self.on)
        if domain == "toolchain":
            return self.backend.core.toolchain.run_target(target, self.values, on=self.on)
        if domain == "soc":
            return self.backend.design.soc.run_target(target, self.context, on=self.on)
        if domain == "fsm":
            return self.backend.design.fsm.run_target(target, self.context, on=self.on)
        if domain == "reporting":
            return self.backend.release.reporting.run(
                target, self.context, provenance=self._provenance_summary(), on=self.on,
            )
        if domain == "qualification":
            if target.action == "spec":
                return self.backend.release.qualification.run(
                    target, force=self._bool(self.values.get("FORCE")),
                )
            states, outcomes = self._qualification_evidence()
            return self.backend.release.qualification.run(
                target, stage_states=states, stage_outcomes=outcomes,
                rtl_sources=self._rtl_sources(),
            )
        if domain == "package":
            qualification = self._contract_status(write=True) if target.action == "save" else None
            return self.backend.release.package.run(
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
    "POST_IMPL_SIGNOFF_TARGETS", "ACTIVITY_ANALYSIS_TARGETS",
    "STREAM_BY_DEFAULT_TARGETS", "QUIET_BY_DEFAULT_TARGETS",
    "setup_public", "setup_command", "dependencies", "_returncode",
]


@dataclass(slots=True)
class WorkspaceFlow:
    """Own workspace settings, run-local artifact viewing, and cleanup."""

    context: BackendContext
    runner: ToolRunner | None = None

    def __post_init__(self) -> None:
        self.runner = self.runner or ToolRunner(project_root=self.context.project_root)

    @staticmethod
    def settings_path(root: Path, workdir: Path | None = None) -> Path:
        """Return the persistent settings file for a project or workspace scope."""

        scope = workdir.expanduser().resolve() if workdir is not None else root.expanduser().resolve()
        return scope / ".flexsoc" / "settings.json"

    @classmethod
    def read_settings(
        cls, root: Path, workdir: Path | None = None, *, defaults: dict[str, str] | None = None,
    ) -> dict[str, str]:
        """Read normalized settings, falling back from workspace to project scope."""

        path = cls.settings_path(root, workdir)
        if workdir is not None and not path.exists():
            path = cls.settings_path(root)
        stored = json.loads(path.read_text(encoding="utf-8")) if path.exists() else {}
        values = {str(key).upper(): str(value) for key, value in stored.items()}
        return {**(defaults or {}), **values}

    @classmethod
    def write_settings(cls, root: Path, values: dict[str, object], workdir: Path | None = None) -> Path:
        """Persist normalized settings in the selected workspace/project scope."""

        path = cls.settings_path(root, workdir)
        path.parent.mkdir(parents=True, exist_ok=True)
        normalized = {str(key).upper(): str(value) for key, value in values.items()}
        path.write_text(json.dumps(normalized, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return path

    @staticmethod
    def _select_waveform(directory: Path, top: str, sim_name: str = "") -> Path:
        """Select one waveform by explicit name, rejecting ambiguous fallbacks."""

        candidates = [path for pattern in ("*.fst", "*.vcd") for path in directory.rglob(pattern)]
        if not candidates:
            raise FileNotFoundError(f"no waveform available in {directory}; run the matching simulation first")
        if not sim_name:
            if len(candidates) == 1:
                return candidates[0]
            names = ", ".join(sorted(path.relative_to(directory).as_posix() for path in candidates))
            raise FileNotFoundError(f"ambiguous waveform in {directory}; set SIM_NAME; candidates: {names}")

        requested = Path(sim_name).name
        if Path(requested).suffix.lower() in {".fst", ".vcd"}:
            requested = Path(requested).stem
        stems = {requested, f"{top}_tb_{requested}"}
        matches = [path for path in candidates if path.stem in stems]
        if len(matches) == 1:
            return matches[0]
        if len(matches) > 1:
            names = ", ".join(sorted(path.relative_to(directory).as_posix() for path in matches))
            raise FileNotFoundError(f"SIM_NAME={sim_name!r} is ambiguous in {directory}: {names}")
        prefix = f"{top}_tb_"
        available = ", ".join(sorted(path.stem.removeprefix(prefix) for path in candidates))
        raise FileNotFoundError(
            f"SIM_NAME={sim_name!r} not found in {directory}; available: {available or 'none'}"
        )

    @staticmethod
    def _viewer_environment(viewer: str, surfer_backend: str = "auto") -> dict[str, str]:
        """Return viewer-specific environment overrides."""

        if Path(viewer).name.lower().removesuffix(".exe") != "surfer":
            return {}
        backend = surfer_backend.strip().lower() or "auto"
        if backend not in {"auto", "x11", "wayland"}:
            raise ValueError("SURFER_BACKEND must be auto, x11, or wayland")
        if backend == "x11" or (backend == "auto" and os.environ.get("WSL_DISTRO_NAME")):
            return {"WAYLAND_DISPLAY": ""}
        return {}

    @staticmethod
    def _remove_contents(path: Path) -> None:
        if not path.is_dir():
            return
        for item in path.iterdir():
            if item.is_dir() and not item.is_symlink():
                shutil.rmtree(item, ignore_errors=True)
            else:
                item.unlink(missing_ok=True)

    @staticmethod
    def _remove_globs(path: Path, *patterns: str) -> None:
        if not path.is_dir():
            return
        for pattern in patterns:
            for item in path.glob(pattern):
                if item.is_dir() and not item.is_symlink():
                    shutil.rmtree(item, ignore_errors=True)
                else:
                    item.unlink(missing_ok=True)

    def run_target(self, target: BackendTarget, *, on: str = "local") -> object:
        action = target.action or ""
        if action == "setup":
            return self.context.paths.ensure()
        if action == "view":
            return self.view(target.name, on=on)
        if action.startswith("clean"):
            return self.clean(action)
        raise ValueError(f"unsupported workspace action: {action!r}")

    def view(self, target: str = "view", *, on: str = "local") -> object:
        """Open or save one waveform artifact."""

        paths, values = self.context.paths, self.context.values
        if target == "tb_save":
            destination = paths.functional / "saved"
            destination.mkdir(parents=True, exist_ok=True)
            for source in paths.tb.rglob("*"):
                if source.is_file():
                    out = destination / source.relative_to(paths.tb)
                    out.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(source, out)
            return destination
        if target == "tb_view":
            saved = paths.functional / "saved"
            print(saved)
            return saved

        sim_name = values.get("SIM_NAME", "").strip() if target == "view" else ""
        if sim_name:
            stage = values.get("SIGNOFF_STAGE", "post_syn").strip().lower()
            if stage == "post_syn":
                directory = self.context.layout.post_syn_sim_dir
            elif stage in {"post_route", "post_impl"}:
                directory = self.context.layout.post_impl_sim_dir
            else:
                raise ValueError("SIGNOFF_STAGE must be post_syn, post_route, or post_impl for view")
            print(f"[wave] stage={stage} pdk={paths.pdk} sim={sim_name} directory={directory}", flush=True)
            wave = self._select_waveform(directory, paths.top, sim_name)
        else:
            wave = self._select_waveform(paths.functional, paths.top)

        viewer = values.get("WAVE_VIEWER", "surfer")
        env = self._viewer_environment(viewer, values.get("SURFER_BACKEND", "auto"))
        print(f"[wave] {wave}", flush=True)
        request = CommandRequest(
            (viewer, str(wave)), wave.parent, env,
            paths.logs / "viewer" / f"{target}.log", inputs=(wave,),
        )
        return self.runner.run(request, on=on)

    def clean(self, action: str) -> int:
        """Remove artifacts owned by one explicit cleanup action."""

        paths = self.context.paths
        root = self.context.project_root

        if action == "clean_pyc":
            for directory in root.rglob("__pycache__"):
                shutil.rmtree(directory, ignore_errors=True)
            for file in root.rglob("*.py[co]"):
                file.unlink(missing_ok=True)
            for directory in (root / ".pytest_cache", root / ".ruff_cache"):
                shutil.rmtree(directory, ignore_errors=True)
            return 0

        simple = {
            "clean_doc": lambda: self._remove_contents(paths.doc),
            "clean_log": lambda: self._remove_contents(paths.logs),
            "clean_rtl": lambda: self._remove_globs(paths.rtl, "*.v"),
            "clean_meta": lambda: self._remove_contents(paths.meta),
            "clean_formal": lambda: (shutil.rmtree(paths.formal, ignore_errors=True), shutil.rmtree(paths.logs / "dv" / "formal", ignore_errors=True)),
            "clean_syn": lambda: (shutil.rmtree(paths.syn, ignore_errors=True), shutil.rmtree(paths.logs / "synthesis" / paths.pdk, ignore_errors=True)),
            "clean_signoff": lambda: (shutil.rmtree(paths.signoff, ignore_errors=True), shutil.rmtree(paths.logs / "signoff" / paths.pdk, ignore_errors=True)),
            "clean_pnr": lambda: (shutil.rmtree(paths.impl, ignore_errors=True), shutil.rmtree(paths.logs / "pnr" / paths.pdk, ignore_errors=True)),
            "clean_agent": lambda: shutil.rmtree(root / "flexsoc_make_agent", ignore_errors=True),
            "clean_fsoc": lambda: (shutil.rmtree(root / "build", ignore_errors=True), shutil.rmtree(paths.run / "fusesoc", ignore_errors=True)),
            "clean_sw": lambda: self._remove_globs(paths.run / "sw", "*.elf", "*.o", "*.csv"),
        }
        if action in simple:
            simple[action]()
            return 0
        if action == "clean_sim":
            self._remove_globs(paths.sim, "*.vvp", "*.vcd", "*.fst")
            shutil.rmtree(paths.sim / "verilator", ignore_errors=True)
            return 0
        if action == "clean_cocotb":
            cocotb = paths.tb / "cocotb"
            self._remove_globs(cocotb, "*.vcd", "*.fst", "__pycache__", "*.pyc")
            shutil.rmtree(cocotb / "sim_build", ignore_errors=True)
            return 0
        if action in {"clean_fsm", "clean_fsm_all", "clean_subdir"}:
            from ..design.fsm.fsm_gen import FsmFlow
            flow = FsmFlow(paths.run, self.runner)
            name = self.context.values.get("FSM", "fsm_example")
            if action == "clean_subdir":
                flow.clean(name)
                flow.setup(name)
            else:
                flow.clean(name, inputs=action == "clean_fsm_all")
            return 0
        if action == "clean_soc":
            for name in ("trace_core_00000000.log", "uart0.log", "soc.core", "xbar_main.hjson"):
                (root / name).unlink(missing_ok=True)
            self._remove_globs(root, "sim.fst*")
            self._remove_globs(root / "sw", "*.elf", "*.o", "*.csv")
            self._remove_globs(root / "tb", "top_verilator.*")
            shutil.rmtree(paths.run / "soc", ignore_errors=True)
            return 0
        if action == "clean_vendor":
            vendor = root / "vendor"
            for name in ("lowrisc_ip", "lowrisc_ibex"):
                shutil.rmtree(vendor / name, ignore_errors=True)
                (vendor / f"{name}.lock.hjson").unlink(missing_ok=True)
            return 0
        if action == "clean_all":
            shutil.rmtree(paths.run, ignore_errors=True)
            default = self.context.workspace / "runs" / paths.run_top / "default"
            if default != paths.run:
                shutil.rmtree(default, ignore_errors=True)
            for name in ("build", "dist", ".pytest_cache", ".mypy_cache", ".ruff_cache"):
                shutil.rmtree(root / name, ignore_errors=True)
            self.clean("clean_pyc")
            return 0
        if action == "clean":
            for item in (
                "clean_pyc", "clean_log", "clean_rtl", "clean_sim", "clean_syn",
                "clean_signoff", "clean_meta", "clean_pnr", "clean_subdir",
                "clean_fsoc", "clean_soc", "clean_fsm",
            ):
                self.clean(item)
            return 0
        raise ValueError(f"unsupported cleanup action: {action!r}")
