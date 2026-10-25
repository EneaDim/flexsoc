"""Digital IP contract, requirement traceability, and release qualification."""

from __future__ import annotations

import hashlib
import json
import re
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import TYPE_CHECKING, Mapping, Sequence

import yaml

from .artifact_policy import ArtifactPolicy
from .deferrals import QualificationDeferrals


if TYPE_CHECKING:
    from flexsoc.backend.core.core import BackendContext
    from flexsoc.backend.core.flow.target import Target


PROVENANCE_STATES = (
    "MISSING",
    "CLEAN",
    "STALE",
    "INVALID",
    "MODIFIED",
    "VALIDATED_OVERRIDE",
)

EVIDENCE_STATES = (
    "MISSING",
    "PASS",
    "FAILED",
    "REVIEW",
    "WAIVED",
    "STALE",
    "INVALID",
)

QUALIFICATION_LEVELS = (
    ("Not Qualified", "none"),
    ("Contract Valid", "contract"),
    ("RTL Qualified", "rtl"),
    ("Netlist Qualified", "netlist"),
    ("Technology Qualified", "technology"),
    ("Physical / Signoff Complete Digital Macro", "physical_signoff"),
)

LEVEL_ALIASES = {
    "auto": None,
    "0": 0,
    "none": 0,
    "1": 1,
    "l1": 1,
    "contract": 1,
    "contract_valid": 1,
    "2": 2,
    "l2": 2,
    "rtl": 2,
    "rtl_qualified": 2,
    "3": 3,
    "netlist": 3,
    "netlist_qualified": 3,
    "4": 4,
    "technology": 4,
    "technology_qualified": 4,
    "5": 5,
    "physical": 5,
    "physical_signoff": 5,
    "signoff": 5,
}

# Stage groups deliberately reuse the existing FlexSoC provenance graph.
EVIDENCE_GROUPS: Mapping[str, tuple[str, ...]] = {
    "lint": ("lint",),
    "functional": ("regression",),
    "model": ("model_tests",),
    "traceability": ("requirements_traceability",),
    "cdc_rdc": ("cdc_rdc",),
    "formal": (
        "formal_csr_bmc",
        "formal_bmc",
        "formal_csr_prove",
        "formal_prove",
        "formal_csr_cover",
        "formal_cover",
    ),
    "netlist": ("syn", "sta"),
    "technology": (
        "sdf",
        "power_estimate",
        "sim_post_syn_all",
        "power_analysis_all",
        "fusion_analysis_all",
    ),
    "physical_signoff": (
        "pnr",
        "physical_signoff",
        "sdf_post_impl",
        "sta_post_impl",
        "power_estimate_post_impl",
        "sim_post_impl_all",
        "power_analysis_post_impl_all",
        "fusion_analysis_post_impl_all",
    ),
}

SPEC_FILES = ("ip.md", "requirements.yaml", "testplan.yaml")
OPTIONAL_SPEC_FILES = ("customer.md",)
GLS_QUALIFICATION_SCENARIOS = ("ss", "tt", "ff")
GLS_SCENARIO_TO_TIMING_MODE = {"ss": "max", "tt": "typ", "ff": "min"}
GLS_QUALIFICATION_BACKEND = "sv"
GLS_MAX_QUALIFICATION_TESTS = 3

@dataclass(slots=True)
class EvidenceOwnership:
    """Immutable source and stage-generated inventories for one sealed release.

    Ownership is derived from recorded stage provenance, not filename conventions.
    A path without a recorded producer stays an immutable input.
    """

    sources: dict[str, str]
    generated: dict[str, dict[str, str]]

    @staticmethod
    def _output_key(root: Path, raw: str, files: Mapping[str, str]) -> str | None:
        """Resolve recorded producer output across run/package relocation.

        The old provenance may contain an absolute path from the producing run.
        Match a domain-rooted suffix against the release inventory; never
        classify a basename without its source domain as generated.
        """
        path = Path(raw)
        if ".." in path.parts or not raw.strip():
            return None
        if not path.is_absolute():
            return path.as_posix()
        try:
            return path.relative_to(root.resolve()).as_posix()
        except ValueError:
            pass
        candidates = set()
        parts = path.parts
        for index in range(1, len(parts)):
            suffix = Path(*parts[index:]).as_posix()
            if any(name == suffix or name.startswith(suffix + "/") for name in files):
                candidates.add(suffix)
        # Only domain-rooted paths qualify; a shared filename is not evidence.
        roots = ("dv/", "syn/", "signoff/", "impl/")
        return min((key for key in candidates if key.startswith(roots)),
                   key=len, default=None)

    @classmethod
    def from_provenance(cls, root: Path, pdk: str, files: Mapping[str, str]) -> "EvidenceOwnership":
        root = Path(root)
        producers: dict[str, str] = {}
        from flexsoc.backend.core.flow.lifecycle import STAGE_CONTRACTS
        for record in (root / "meta/provenance.json", root / "meta" / pdk / "provenance.json"):
            if not record.is_file():
                continue
            payload = json.loads(record.read_text(encoding="utf-8"))
            for stage, stage_data in payload.get("stages", {}).items():
                if not isinstance(stage_data, dict):
                    continue
                contract = STAGE_CONTRACTS.get(stage)
                if contract is not None and (contract.scope == "pdk") != (record.parent != root / "meta"):
                    continue
                for output_root in contract.owned_outputs if contract is not None else ():
                    producers[output_root] = str(stage)
                for entry in stage_data.get("generated", ()):
                    if isinstance(entry, dict) and isinstance(entry.get("path"), str):
                        key = cls._output_key(root, entry["path"], files)
                        if key is not None:
                            producers[key] = str(stage)
        generated: dict[str, dict[str, str]] = {}
        sources: dict[str, str] = {}
        for name, digest in files.items():
            matches = [(len(key), stage) for key, stage in producers.items()
                       if name == key or name.startswith(key.rstrip("/") + "/")]
            if matches and not name.startswith(("rtl/", "csr/", "constraints/")):
                generated[name] = {"sha256": digest, "stage": max(matches)[1]}
            else:
                sources[name] = digest
        return cls(sources, generated)

    @classmethod
    def from_manifest(cls, data: Mapping[str, object]) -> "EvidenceOwnership":
        sources = data.get("sources")
        generated = data.get("generated")
        if not isinstance(sources, dict) or not isinstance(generated, dict):
            raise ValueError("invalid evidence ownership manifest")
        if any(not isinstance(value, str) for value in sources.values()):
            raise ValueError("invalid source hash")
        if any(not isinstance(value, dict) or not isinstance(value.get("sha256"), str)
               or not isinstance(value.get("stage"), str) for value in generated.values()):
            raise ValueError("invalid stage evidence entry")
        if set(sources) & set(generated):
            raise ValueError("conflicting evidence ownership")
        return cls(dict(sources), dict(generated))

    def as_manifest(self) -> dict[str, object]:
        return {"schema": 2, "sources": self.sources, "generated": self.generated}


@dataclass(slots=True)
class QualificationFlow:
    """Evaluate the Digital IP contract from canonical lifecycle evidence."""

    context: "BackendContext"

    def run(
        self,
        target: "Target",
        *,
        stage_states: Mapping[str, str] | None = None,
        stage_outcomes: Mapping[str, str | None] | None = None,
        rtl_sources: Sequence[Path] = (),
        force: bool = False,
    ) -> object:
        """Execute one registered contract/qualification target."""

        if target.action == "spec":
            paths = self.context.paths
            clocks = self.context.clocks
            return QualificationFlow.write_spec_scaffold(
                paths.spec,
                ip_name=self.context.values.get("IP_NAME", paths.top),
                clock_domains=tuple(domain.encode() for domain in clocks.domains),
                clock_relationships=tuple(rel.encode() for rel in clocks.relationships),
                force=force,
            )
        stage_states = stage_states or {}
        stage_outcomes = stage_outcomes or {}
        write = target.action == "qualify"
        report = self.status(
            stage_states=stage_states, stage_outcomes=stage_outcomes,
            rtl_sources=rtl_sources, write=write,
        )
        if target.action == "status":
            return report
        if target.action == "qualify":
            return 0 if report.get("target_satisfied", False) else 1
        raise ValueError(f"unsupported qualification target: {target.name}")

    def _frozen_evidence(
        self,
        *,
        spec_root: Path,
        spec: Mapping[str, object],
        ip_name: str,
        reg_interface: str,
        allow_updated_generated: bool = False,
    ) -> dict[str, str]:
        """Return reusable evidence from a loaded release whose contract is still valid."""

        paths = self.context.paths
        contract_path = paths.run / "meta" / "contract.json"
        if not contract_path.is_file():
            return {}
        try:
            QualificationFlow.validate_contract_snapshot(paths.run, spec_root=spec_root)
        except (OSError, ValueError, json.JSONDecodeError):
            return {}

        rtl_path = paths.run / "meta" / "rtl_qualification.json"
        rtl_report = None
        if rtl_path.is_file():
            try:
                candidate = json.loads(rtl_path.read_text(encoding="utf-8"))
                if (candidate.get("ip") == ip_name
                        and candidate.get("reg_interface") == reg_interface
                        and candidate.get("contract_fingerprint") == spec.get("fingerprint")
                        and candidate == QualificationFlow.rtl_qualification_report(candidate)):
                    rtl_report = candidate
            except (OSError, ValueError, json.JSONDecodeError, TypeError):
                pass

        # Frozen RTL is reusable across implementation technologies, but only
        # when the original sealed technology branch still authenticates the
        # shipped RTL and DV evidence. A free-standing JSON PASS is not proof.
        technology_roots = paths.run / "meta"
        branches = [paths.pdk]
        if rtl_report is not None and technology_roots.is_dir():
            branches.extend(sorted(folder.name for folder in technology_roots.iterdir()
                                   if folder.is_dir() and folder.name != paths.pdk))
        if rtl_report is not None:
            try:
                if QualificationFlow.rtl_evidence_integrity(paths.run):
                    durable = {"PASS", "FAILED", "REVIEW", "WAIVED"}
                    return {str(stage): state for stage, value in rtl_report.get("evidence", {}).items()
                            if (state := str(value).upper()) in durable}
            except (OSError, ValueError, json.JSONDecodeError):
                pass
        for branch in dict.fromkeys(branches):
            report_path = technology_roots / branch / "qualification.json"
            if not report_path.is_file():
                continue
            try:
                report = json.loads(report_path.read_text(encoding="utf-8"))
                if (report.get("ip") != ip_name
                        or report.get("reg_interface") != reg_interface
                        or str(report.get("pdk", "")) != str(branch)
                        or report.get("contract_fingerprint") != spec.get("fingerprint")):
                    continue
                if branch != paths.pdk:
                    if rtl_report is None or rtl_report != QualificationFlow.rtl_qualification_report(report):
                        continue
                if not QualificationFlow.evidence_integrity(
                    paths.run, branch, allow_updated_generated=allow_updated_generated,
                ):
                    continue
            except (OSError, ValueError, json.JSONDecodeError, TypeError):
                continue
            evidence = (rtl_report or report).get("evidence", {}) if branch != paths.pdk else report.get("evidence", {})
            if not isinstance(evidence, Mapping):
                continue
            durable = {"PASS", "FAILED", "REVIEW", "WAIVED"}
            result = {str(stage): state for stage, value in evidence.items()
                      if (state := str(value).upper()) in durable}
            if branch != paths.pdk:
                result = {stage: state for stage, state in result.items()
                          if stage in QualificationFlow.required_stages(spec, 2)}
            return result
        return {}

    def status(
        self,
        *,
        stage_states: Mapping[str, str],
        stage_outcomes: Mapping[str, str | None],
        rtl_sources: Sequence[Path],
        write: bool = False,
    ) -> dict[str, object]:
        """Validate the live contract and derive its maximum qualification level."""

        paths = self.context.paths
        values = self.context.values
        ip_name = values.get("IP_NAME", paths.top)
        reg_interface = values.get("REG_ITF", "tlul")
        spec_root = paths.spec if paths.spec.is_dir() else paths.run / "contract"

        spec_error = None
        try:
            spec = QualificationFlow.validate_spec_bundle(spec_root, ip_name=ip_name)
        except Exception as exc:
            spec_error = str(exc)
            spec = {
                "fingerprint": None,
                "baselined_requirements": 0,
                "covered_requirements": 0,
                "required_evidence": ["traceability", "lint", "functional", "cdc_rdc", "formal"],
                "tests": [],
                "properties": [],
                "traceability": {},
            }

        states = dict(stage_states)
        outcomes = dict(stage_outcomes)
        for stage, outcome in self._frozen_evidence(
            spec_root=spec_root, spec=spec, ip_name=ip_name, reg_interface=reg_interface,
            allow_updated_generated=write,
        ).items():
            if states.get(stage, "MISSING") in {"MISSING", "STALE", "INVALID"}:
                states[stage] = "CLEAN"
                outcomes[stage] = outcome
        # Model regression is an L2 gate whenever the test plan defines model cases.
        # Validate the tested Python bytes and contract, not just a recorded PASS.
        from .traceability import TraceabilityFlow

        model_plan = spec.get("spec_traceability", {}).get("model_cases_to_testplan", {})
        if model_plan:
            model_dir = paths.run / "dv" / "functional" / "py" / "model"
            runtime = model_dir / "results" / "summary.json"
            frozen = paths.run / "dv" / "functional" / "model_tests" / "summary.json"
            model = TraceabilityFlow.model_evidence(
                report=spec["spec_traceability"],
                summary=runtime if runtime.is_file() else frozen,
                fingerprint=str(spec["fingerprint"]), model_dir=model_dir, ip=ip_name,
            )
            outcome = str(model["status"]).upper()
            states["model_tests"] = "CLEAN" if outcome in {"PASS", "FAILED"} else "MISSING"
            outcomes["model_tests"] = outcome if outcome in {"PASS", "FAILED"} else "MISSING"

        available_tests = {
            path.name for path in paths.tests.iterdir() if path.is_dir()
        } if paths.tests.is_dir() else set()
        planned_tests = {str(item) for item in spec.get("tests", ())}
        missing_tests = sorted(planned_tests - available_tests)

        prove = paths.formal / "properties" / "prove"
        cover = paths.formal / "properties" / "cover"
        available_properties = {
            path.stem for root in (prove, cover) if root.is_dir() for path in root.glob("*.sv")
        }
        planned_properties = {str(item) for item in spec.get("properties", ())}
        missing_properties = sorted(
            name for name in planned_properties
            if not any(name == item or item.startswith(name) for item in available_properties)
        )
        states["requirements_traceability"] = "CLEAN"
        outcomes["requirements_traceability"] = (
            "FAILED" if missing_tests or missing_properties or spec_error else "PASS"
        )

        contract_ready = (
            spec_error is None
            and paths.sdc.is_file()
            and bool(rtl_sources)
            and any(paths.csr.glob("*.hjson"))
        )
        # Engineering deferrals are annotations, never replacements for tool results.
        deferrals = QualificationDeferrals.load(
            paths.meta / "qualification_deferrals.json",
            fingerprint=spec.get("fingerprint"),
            allowed_stages=(*QualificationFlow.required_stages(spec, 5), "requirements_coverage"),
        )
        review_acceptance = QualificationFlow.cdc_rdc_review_acceptance(
            paths.cdc_rdc / "summary.json",
            enabled=str(values.get("CDC_RDC_L2_ACCEPT_REVIEW", "0")).strip().lower()
            in {"1", "true", "yes"},
            evidence_state=QualificationFlow.evidence_state(
                states.get("cdc_rdc", "MISSING"), outcome=outcomes.get("cdc_rdc")
            ),
        )
        report = QualificationFlow.build_qualification_report(
            ip_name=ip_name, reg_interface=reg_interface, pdk=paths.pdk,
            spec=spec, stage_states=states, contract_ready=contract_ready,
            requested_level=values.get("QUAL_LEVEL", "auto"), stage_outcomes=outcomes,
            deferrals=deferrals,
            accepted_reviews={"cdc_rdc": review_acceptance} if review_acceptance else {},
        )
        report["contract"] = "VALID" if contract_ready else "INVALID"
        report["spec_error"] = spec_error

        requirement_traceability: dict[str, object] = {}
        for req_id, entries in (spec.get("traceability", {}) or {}).items():
            traced_tests = sorted({
                str(name) for entry in entries for name in entry.get("tests", [])
            })
            traced_properties = sorted({
                str(name) for entry in entries for name in entry.get("properties", [])
            })
            req_missing_tests = sorted(set(traced_tests) - available_tests)
            req_missing_properties = sorted(
                name for name in traced_properties
                if not any(name == item or item.startswith(name) for item in available_properties)
            )
            requirement_traceability[str(req_id)] = {
                "status": "PASS" if not req_missing_tests and not req_missing_properties else "FAILED",
                "testplan": entries,
                "missing_tests": req_missing_tests,
                "missing_properties": req_missing_properties,
            }
        report["traceability"] = {
            "missing_tests": missing_tests,
            "missing_properties": missing_properties,
            "requirements": requirement_traceability,
        }

        print(
            f"[contract] {report['contract']} fingerprint={report.get('contract_fingerprint')} "
            f"requirements={report['requirements']['covered']}/{report['requirements']['total']}"
        )
        requested_level = report.get("requested_level")
        rtl_only = (requested_level if requested_level is not None
                    else report.get("maximum_level", 0)) <= 2
        view = self.rtl_qualification_report(report) if rtl_only else report
        print(
            f"[release] level={view['maximum_level']} "
            f"{view['maximum_qualification']} interface={reg_interface}"
            + ("" if rtl_only else f" pdk={paths.pdk}")
        )
        for level, item in view["levels"].items():
            blocking = item["blocking_evidence"]
            suffix = "" if not blocking else " blocking=" + ",".join(blocking)
            print(f"[level] L{level} {item['name']}: {item['status']}{suffix}")
        for level, item in view["levels"].items():
            if item["deferred_evidence"]:
                print(f"[development] L{level} {item['development_status']} deferred=" + ",".join(item["deferred_evidence"]))
        for stage, note in sorted(deferrals.items()):
            print(f"[deferral] {stage} owner={note['owner']} resolve_by={note['resolve_by']} reason={note['reason']}")
        for stage in QualificationFlow.required_stages(spec, 2 if rtl_only else 5):
            state = view["evidence"].get(stage, "MISSING")
            print(f"[evidence] {stage:<26} {state}")

        if write:
            self.write_rtl_qualification_report(paths.run, report)
            if not rtl_only:
                self.write_qualification_report(paths.run, str(paths.pdk), report)
            print(f"[qualification] {paths.run / 'meta' / 'rtl_qualification.json' if rtl_only else paths.meta / 'qualification.json'}")
        return report

    @staticmethod
    def rtl_qualification_report(report: Mapping[str, object]) -> dict[str, object]:
        """Technology-neutral L1/L2 projection of a live qualification decision.

        Physical/implementation evidence never enters the RTL release contract.
        A technology branch may still retain its legacy aggregate report.
        """
        from copy import deepcopy

        result = deepcopy(dict(report))
        result.pop("pdk", None)
        levels = result.get("levels", {})
        result["levels"] = {key: value for key, value in levels.items() if key in {"1", "2"}}
        rtl_stages = {stage for group, stages in EVIDENCE_GROUPS.items()
                      if group not in {"netlist", "technology", "physical_signoff"}
                      for stage in stages}
        for key in ("evidence", "freshness", "outcomes", "engineering_deferrals", "review_acceptances"):
            values = result.get(key)
            if isinstance(values, dict):
                result[key] = {stage: value for stage, value in values.items() if stage in rtl_stages}
        level = max((int(key) for key, value in result["levels"].items()
                     if value.get("status") == "PASS"), default=0)
        result["maximum_level"] = level
        result["maximum_qualification"] = QualificationFlow.qualification_name(level)
        result["maximum_pass_level"] = level
        result["maximum_pass_qualification"] = QualificationFlow.qualification_name(level)
        result["qualification_status"] = result["levels"].get(str(level), {}).get("status", "BLOCKED")
        requested = result.get("requested_level")
        if requested is not None and requested > 2:
            result["requested_level"] = 2
        result["target_status"] = result["levels"].get(str(result.get("requested_level") or level), {}).get("status", "BLOCKED")
        result["target_satisfied"] = result["target_status"] == "PASS"
        return result

    @staticmethod
    def write_rtl_qualification_report(run: Path, report: Mapping[str, object]) -> Path:
        """Publish portable L1/L2 evidence at IP scope, independently of PDK."""
        output = Path(run) / "meta" / "rtl_qualification.json"
        output.parent.mkdir(parents=True, exist_ok=True)
        temporary = output.with_name(f".{output.name}.tmp")
        temporary.write_text(json.dumps(QualificationFlow.rtl_qualification_report(report), indent=2, sort_keys=True) + "\n", encoding="utf-8")
        temporary.replace(output)
        return output

    @staticmethod
    def write_qualification_report(run: Path, pdk: str, report: Mapping[str, object]) -> Path:
        """Write a live result and reseal only an already verified loaded run."""
        root = Path(run)
        sealed = root / "meta" / pdk / "evidence_integrity.json"
        reseal = sealed.is_file() and QualificationFlow.evidence_integrity(root, pdk, allow_updated_generated=True)
        output = root / "meta" / pdk / "qualification.json"
        output.parent.mkdir(parents=True, exist_ok=True)
        temporary = output.with_name(f".{output.name}.tmp")
        temporary.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        temporary.replace(output)
        if reseal:
            QualificationFlow.evidence_integrity(root, pdk, write=True)
        return output

    @staticmethod
    def _req_prefix(ip_name: str) -> str:
        value = re.sub(r"[^A-Za-z0-9]+", "-", ip_name.strip()).strip("-").upper()
        return value or "IP"

    @staticmethod
    def _write_authored(path: Path, text: str, *, force: bool) -> Path:
        """Write one designer-owned scaffold without silent replacement."""

        if path.exists() and not force:
            return path
        path.parent.mkdir(parents=True, exist_ok=True)
        temporary = path.with_name(f".{path.name}.tmp")
        temporary.write_text(text, encoding="utf-8")
        temporary.replace(path)
        return path

    @staticmethod
    def _single_clock_spec(ip_name: str, clock_domains: Sequence[str]) -> tuple[str, dict[str, object], dict[str, object]]:
        prefix = QualificationFlow._req_prefix(ip_name)
        domain = clock_domains[0] if clock_domains else "core:clk_i:rst_ni:10:low"
        spec = f"""# {ip_name} — single-clock scaffold specification

    Status: starter baseline generated by FlexSoC. Edit and review this file as the IP contract matures.

    ## Purpose

    `{ip_name}` is the minimal single-clock Digital Soft IP scaffold. It demonstrates a register-controlled two-stage datapath while keeping CSR semantics independent from the selected external register transport.

    ## Clock and reset

    - One declared clock/reset domain: `{domain}`.
    - Reset assertion is asynchronous and release is synchronized by the generated wrapper.

    ## Functional behavior

    - The starter datapath accepts `data_i`, `coeff_i` and `valid_i`.
    - When enabled, the configured mode selects add, XOR, left-shift, or passthrough behavior.
    - Accepted data advances through a fixed two-stage pipeline to `data_o`/`valid_o`.
    - Reset or the software clear control returns pipeline state and valid state to the inactive value.

    ## CSR and integration contract

    The CSR map is the common software-visible contract. `REG_ITF=reg_iface|tlul|axi_lite` changes only the external register transport shell and its verification driver, not CSR semantics or functional intent.

    ## Assumptions and limitations

    This is a didactic scaffold, not an application-specific algorithm. Requirements below are intentionally small and must be refined when the scaffold becomes a real IP.
    """
        requirements = {
            "schema": 1,
            "ip": ip_name,
            "requirements": [
                {"id": f"{prefix}-CLK-001", "statement": "The IP shall operate from one declared clock/reset domain and shall use asynchronous reset assertion with synchronized release at the generated top wrapper.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-REG-001", "statement": "The software-visible CSR semantics shall remain unchanged across reg_iface, TL-UL, and AXI-Lite register-interface releases.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-FUNC-001", "statement": "When enabled, an accepted input transaction shall produce the configured add, XOR, left-shift, or passthrough result through the starter two-stage pipeline.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-CTRL-001", "statement": "Runtime CSR reconfiguration shall affect subsequent transactions, and reset or software clear shall return pipeline valid/state to the inactive value.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-STAT-001", "statement": "Starter status/result CSRs shall reflect the generated pipeline busy, completion, error, and latest-result state defined by the scaffold.", "scope": "common", "origin": "scaffold", "status": "baselined"},
            ],
        }
        testplan = {
            "schema": 1,
            "ip": ip_name,
            "qualification": {
                "required_evidence": ["traceability", "lint", "functional", "cdc_rdc", "formal"],
                "gls": {
                    "backend": GLS_QUALIFICATION_BACKEND,
                    "scenarios": list(GLS_QUALIFICATION_SCENARIOS),
                    "tests": ["smoke", "corners", "reconfig"],
                    "max_tests": GLS_MAX_QUALIFICATION_TESTS,
                    "stages": ["post_syn", "post_impl"],
                },
            },
            "items": [
                {"id": f"{prefix}-TP-001", "requirements": [f"{prefix}-CLK-001"], "methods": ["formal", "cdc_rdc"], "properties": [f"{ip_name}_prove"]},
                {"id": f"{prefix}-TP-002", "requirements": [f"{prefix}-REG-001"], "methods": ["simulation", "formal"], "tests": ["smoke", "reconfig"]},
                {"id": f"{prefix}-TP-003", "requirements": [f"{prefix}-FUNC-001"], "methods": ["simulation"], "tests": ["smoke", "corners", "random_seed_1"]},
                {"id": f"{prefix}-TP-004", "requirements": [f"{prefix}-CTRL-001"], "methods": ["simulation", "formal"], "tests": ["reconfig", "auto_toggle"], "properties": [f"{ip_name}_prove"]},
                {"id": f"{prefix}-TP-005", "requirements": [f"{prefix}-STAT-001"], "methods": ["simulation", "formal"], "tests": ["smoke", "corners"], "properties": [f"{ip_name}_prove"]},
            ],
        }
        return spec, requirements, testplan

    @staticmethod
    def _multi_clock_spec(
        ip_name: str,
        clock_domains: Sequence[str],
        clock_relationships: Sequence[str],
    ) -> tuple[str, dict[str, object], dict[str, object]]:
        prefix = QualificationFlow._req_prefix(ip_name)
        domains = ", ".join(f"`{item}`" for item in clock_domains) or "declared clock domains"
        relationships = ", ".join(f"`{item}`" for item in clock_relationships) or "explicitly declared relationships"
        spec = f"""# {ip_name} — multi-clock scaffold specification

    Status: starter baseline generated by FlexSoC. Edit and review this file as the IP contract matures.

    ## Purpose

    `{ip_name}` is the didactic multi-clock Digital Soft IP scaffold. It demonstrates explicit clock/reset ownership, CDC structures, a small DSP datapath, clock gating, register windows, functional DV and technology qualification without pretending to be an application-specific design.

    ## Clock and reset

    Declared domains: {domains}.

    Declared relationships: {relationships}.

    Each domain owns one synchronized reset release. Cross-domain communication uses explicit synchronizers or an asynchronous FIFO rather than implicit combinational crossings. The RX-to-DSP FIFO uses a partial-reset-safe handshake so either endpoint may reset independently.

    ## Functional behavior

    - Global enable/software-reset controls originate in the cfg domain; DSP algorithm, gain and threshold controls remain in the DSP register domain.
    - RX samples cross into the DSP domain through a partial-reset-safe asynchronous FIFO handshake.
    - The DSP scaffold supports multiply-accumulate, absolute-difference and energy operations.
    - Output ready/valid backpressure is preserved.
    - The DSP datapath clock may be gated by the scaffold control while the control register window remains writable for restart.
    - Status is returned to the appropriate register domain using explicit CDC structures.

    ## CSR and integration contract

    The CSR semantics are shared by the `reg_iface`, `tlul`, and `axi_lite` releases. The selected `REG_ITF` changes the external register transport shell only.

    ## Assumptions and limitations

    The CDC mechanisms are starter patterns suitable for this scaffold topology. A real IP must replace them when its coherency, throughput, safety, or latency requirements differ.
    """
        requirements = {
            "schema": 1,
            "ip": ip_name,
            "requirements": [
                {"id": f"{prefix}-CLK-001", "statement": "The IP shall preserve the declared cfg, RX, and DSP clock/reset domains and their explicit clock relationships.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-REG-001", "statement": "The software-visible CSR semantics shall remain unchanged across reg_iface, TL-UL, and AXI-Lite register-interface releases.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-CDC-001", "statement": "Control/status crossings shall use explicit synchronizers, and RX payloads shall cross into the DSP domain through the partial-reset-safe asynchronous FIFO scaffold.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-FUNC-001", "statement": "The DSP scaffold shall implement multiply-accumulate, absolute-difference, and energy operations selected by configuration.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-FLOW-001", "statement": "RX and DSP output interfaces shall obey the generated ready/valid flow-control and shall preserve output state under backpressure.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-GATE-001", "statement": "DSP clock gating shall stop inactive datapath activity while preserving a control path that can re-enable the DSP domain.", "scope": "common", "origin": "scaffold", "status": "baselined"},
                {"id": f"{prefix}-RST-001", "statement": "External domain resets shall reset their domain-local state and the associated asynchronous-FIFO endpoint; the DSP-domain software reset shall synchronously clear DSP datapath, pipeline-valid, output and status state without acting as a FIFO flush.", "scope": "common", "origin": "scaffold", "status": "baselined"},
            ],
        }
        testplan = {
            "schema": 1,
            "ip": ip_name,
            "qualification": {
                "required_evidence": ["traceability", "lint", "functional", "cdc_rdc", "formal"],
                "gls": {
                    "backend": GLS_QUALIFICATION_BACKEND,
                    "scenarios": list(GLS_QUALIFICATION_SCENARIOS),
                    "tests": ["mac_smoke", "corners", "clock_gate"],
                    "max_tests": GLS_MAX_QUALIFICATION_TESTS,
                    "stages": ["post_syn", "post_impl"],
                },
            },
            "items": [
                {"id": f"{prefix}-TP-001", "requirements": [f"{prefix}-CLK-001", f"{prefix}-CDC-001"], "methods": ["cdc_rdc", "formal"], "tests": ["smoke"], "properties": [f"{ip_name}_prove"]},
                {"id": f"{prefix}-TP-002", "requirements": [f"{prefix}-REG-001"], "methods": ["simulation", "formal"], "tests": ["smoke", "reconfig"]},
                {"id": f"{prefix}-TP-003", "requirements": [f"{prefix}-FUNC-001"], "methods": ["simulation"], "tests": ["mac_smoke", "absdiff", "energy", "corners"]},
                {"id": f"{prefix}-TP-004", "requirements": [f"{prefix}-FLOW-001"], "methods": ["simulation", "formal"], "tests": ["smoke", "mac_smoke"], "properties": [f"{ip_name}_prove"]},
                {"id": f"{prefix}-TP-005", "requirements": [f"{prefix}-GATE-001"], "methods": ["simulation", "cdc_rdc"], "tests": ["clock_gate"]},
                {"id": f"{prefix}-TP-006", "requirements": [f"{prefix}-RST-001"], "methods": ["simulation", "formal", "cdc_rdc"], "tests": ["smoke", "reconfig"], "properties": [f"{ip_name}_prove"]},
            ],
        }
        return spec, requirements, testplan

    @staticmethod
    def write_spec_scaffold(
        spec_root: Path,
        *,
        ip_name: str,
        clock_domains: Sequence[str],
        clock_relationships: Sequence[str] = (),
        force: bool = False,
    ) -> tuple[Path, Path, Path]:
        """Create the minimal authoritative spec/requirements/test-plan scaffold."""

        if len(tuple(clock_domains)) > 1:
            spec, requirements, testplan = QualificationFlow._multi_clock_spec(ip_name, tuple(clock_domains), tuple(clock_relationships))
        else:
            spec, requirements, testplan = QualificationFlow._single_clock_spec(ip_name, tuple(clock_domains))
        root = Path(spec_root)
        outputs = (
            QualificationFlow._write_authored(root / "ip.md", spec, force=force),
            QualificationFlow._write_authored(
                root / "requirements.yaml",
                yaml.safe_dump(requirements, sort_keys=False, allow_unicode=True),
                force=force,
            ),
            QualificationFlow._write_authored(
                root / "testplan.yaml",
                yaml.safe_dump(testplan, sort_keys=False, allow_unicode=True),
                force=force,
            ),
        )
        QualificationFlow.validate_spec_bundle(root, ip_name=ip_name)
        return outputs

    @staticmethod
    def _validated_gls_policy(
        qualification: Mapping[str, object],
        *,
        planned_tests: set[str],
    ) -> dict[str, object] | None:
        raw = qualification.get("gls")
        if raw is None:
            return None
        if not isinstance(raw, dict):
            raise ValueError("qualification.gls must be a mapping")
        backend = str(raw.get("backend", GLS_QUALIFICATION_BACKEND)).strip()
        if backend != GLS_QUALIFICATION_BACKEND:
            raise ValueError("qualification.gls.backend must be 'sv'")
        tests = [str(item).strip() for item in raw.get("tests", []) if str(item).strip()]
        max_tests = int(raw.get("max_tests", GLS_MAX_QUALIFICATION_TESTS))
        if not 1 <= max_tests <= GLS_MAX_QUALIFICATION_TESTS:
            raise ValueError(f"qualification.gls.max_tests must be 1..{GLS_MAX_QUALIFICATION_TESTS}")
        if not tests or len(tests) > max_tests or len(set(tests)) != len(tests):
            raise ValueError(f"qualification.gls.tests must contain 1..{max_tests} unique tests")
        unknown_tests = sorted(set(tests) - planned_tests)
        if unknown_tests:
            raise ValueError("qualification.gls references unknown test(s): " + ", ".join(unknown_tests))
        scenarios = [str(item).strip().lower() for item in raw.get("scenarios", GLS_QUALIFICATION_SCENARIOS)]
        if tuple(scenarios) != GLS_QUALIFICATION_SCENARIOS:
            raise ValueError("qualification.gls.scenarios must be exactly [ss, tt, ff]")
        stages = [str(item).strip() for item in raw.get("stages", ["post_syn", "post_impl"])]
        if any(item not in {"post_syn", "post_impl"} for item in stages) or not stages:
            raise ValueError("qualification.gls.stages must contain post_syn and/or post_impl")
        return {
            "backend": backend,
            "tests": tests,
            "max_tests": max_tests,
            "scenarios": scenarios,
            "timing_modes": [GLS_SCENARIO_TO_TIMING_MODE[item] for item in scenarios],
            "stages": stages,
        }

    @staticmethod
    def sha256_file(path: Path) -> str:
        h = hashlib.sha256()
        with path.open("rb") as handle:
            for chunk in iter(lambda: handle.read(1024 * 1024), b""):
                h.update(chunk)
        return h.hexdigest()

    @staticmethod
    def normalize_qualification_level(value: str | int | None) -> int | None:
        """Return a requested qualification level; None means automatic maximum."""

        if value is None:
            return None
        key = str(value).strip().lower().replace("-", "_").replace(" ", "_") or "auto"
        if key not in LEVEL_ALIASES:
            choices = "auto, contract (L1), rtl (L2), netlist, technology, physical_signoff"
            raise ValueError(f"QUAL_LEVEL must be one of: {choices}")
        return LEVEL_ALIASES[key]

    @staticmethod
    def qualification_name(level: int) -> str:
        if not 0 <= level < len(QUALIFICATION_LEVELS):
            raise ValueError(f"invalid qualification level: {level}")
        return QUALIFICATION_LEVELS[level][0]

    @staticmethod
    def _load_yaml(path: Path) -> object:
        return yaml.safe_load(path.read_text(encoding="utf-8"))

    @staticmethod
    def validate_spec_bundle(spec_root: Path, *, ip_name: str | None = None) -> dict[str, object]:
        """Validate the authoritative spec/requirements/test-plan bundle."""

        root = Path(spec_root)
        missing = [root / name for name in SPEC_FILES if not (root / name).is_file()]
        if missing:
            raise FileNotFoundError("missing Digital IP specification file(s): " + ", ".join(map(str, missing)))

        requirements_doc = QualificationFlow._load_yaml(root / "requirements.yaml")
        testplan_doc = QualificationFlow._load_yaml(root / "testplan.yaml")
        if not isinstance(requirements_doc, dict) or not isinstance(testplan_doc, dict):
            raise ValueError("requirements.yaml and testplan.yaml must contain mappings")

        req_ip = str(requirements_doc.get("ip", "")).strip()
        plan_ip = str(testplan_doc.get("ip", "")).strip()
        if ip_name and (req_ip != ip_name or plan_ip != ip_name):
            raise ValueError(
                f"spec identity mismatch: requirements.ip={req_ip!r} testplan.ip={plan_ip!r} expected={ip_name!r}"
            )
        req_version = str(requirements_doc.get("version", "")).strip() or None
        plan_version = str(testplan_doc.get("version", "")).strip() or None
        if req_version != plan_version:
            raise ValueError(
                f"spec version mismatch: requirements.version={req_version!r} "
                f"testplan.version={plan_version!r}"
            )

        requirements = requirements_doc.get("requirements", [])
        items = testplan_doc.get("items", [])
        if not isinstance(requirements, list) or not isinstance(items, list):
            raise ValueError("requirements and testplan items must be lists")

        req_ids: list[str] = []
        baselined: set[str] = set()
        for entry in requirements:
            if not isinstance(entry, dict):
                raise ValueError("each requirement must be a mapping")
            req_id = str(entry.get("id", "")).strip()
            statement = str(entry.get("statement", "")).strip()
            if not req_id or not statement:
                raise ValueError("each requirement needs non-empty id and statement")
            req_ids.append(req_id)
            if str(entry.get("status", "baselined")).strip().lower() == "baselined":
                baselined.add(req_id)
        if len(set(req_ids)) != len(req_ids):
            raise ValueError("duplicate requirement id")

        plan_ids: list[str] = []
        covered: set[str] = set()
        test_names: set[str] = set()
        properties: set[str] = set()
        traceability: dict[str, list[dict[str, object]]] = {req_id: [] for req_id in req_ids}
        for entry in items:
            if not isinstance(entry, dict):
                raise ValueError("each test-plan item must be a mapping")
            plan_id = str(entry.get("id", "")).strip()
            if not plan_id:
                raise ValueError("each test-plan item needs an id")
            plan_ids.append(plan_id)
            refs = entry.get("requirements", [])
            if not isinstance(refs, list) or not refs:
                raise ValueError(f"{plan_id}: requirements must be a non-empty list")
            fields: dict[str, list[str]] = {}
            for key in ("methods", "tests", "properties"):
                raw = entry.get(key, []) or []
                if not isinstance(raw, list):
                    raise ValueError(f"{plan_id}: {key} must be a list")
                fields[key] = [str(item).strip() for item in raw if str(item).strip()]
            record = {
                "testplan_id": plan_id,
                "methods": fields["methods"],
                "tests": fields["tests"],
                "properties": fields["properties"],
            }
            for ref in refs:
                req_id = str(ref)
                if req_id not in req_ids:
                    raise ValueError(f"{plan_id}: unknown requirement {req_id!r}")
                covered.add(req_id)
                traceability[req_id].append(record)
            test_names.update(fields["tests"])
            properties.update(fields["properties"])
        if len(set(plan_ids)) != len(plan_ids):
            raise ValueError("duplicate test-plan item id")

        uncovered = sorted(baselined - covered)

        qualification = testplan_doc.get("qualification", {}) or {}
        if not isinstance(qualification, dict):
            raise ValueError("testplan.qualification must be a mapping")
        required_evidence = qualification.get(
            "required_evidence", ["traceability", "lint", "functional", "cdc_rdc", "formal"]
        )
        if not isinstance(required_evidence, list):
            raise ValueError("qualification.required_evidence must be a list")
        unknown = [str(item) for item in required_evidence if str(item) not in EVIDENCE_GROUPS]
        if unknown:
            raise ValueError("unknown qualification evidence group(s): " + ", ".join(unknown))
        required_evidence = [
            "traceability",
            *(str(item) for item in required_evidence if str(item) != "traceability"),
        ]
        gls_policy = QualificationFlow._validated_gls_policy(qualification, planned_tests=test_names)

        from .traceability import TraceabilityFlow

        extended_trace = TraceabilityFlow(root).validate(requirements_doc, testplan_doc)
        files = (*SPEC_FILES, *(name for name in OPTIONAL_SPEC_FILES if (root / name).is_file()))
        hashes = {name: QualificationFlow.sha256_file(root / name) for name in files}
        fingerprint = hashlib.sha256(
            json.dumps(hashes, sort_keys=True, separators=(",", ":")).encode()
        ).hexdigest()
        return {
            "schema": 1,
            "ip": req_ip or plan_ip or ip_name,
            "version": req_version,
            "requirements": len(req_ids),
            "baselined_requirements": len(baselined),
            "covered_requirements": len(baselined & covered),
            "uncovered_requirements": uncovered,
            "testplan_items": len(plan_ids),
            "tests": sorted(test_names),
            "properties": sorted(properties),
            "traceability": traceability,
            "spec_traceability": extended_trace,
            "required_evidence": [str(item) for item in required_evidence],
            "gls_policy": gls_policy,
            "hashes": hashes,
            "fingerprint": fingerprint,
        }

    @staticmethod
    def required_stages(spec: Mapping[str, object], level: int) -> tuple[str, ...]:
        """Expand the policy for one qualification level into provenance stages."""

        stages: list[str] = []
        if level >= 2:
            groups = (
                "traceability",
                *(
                    str(group)
                    for group in spec.get(
                        "required_evidence",
                        ("traceability", "lint", "functional", "cdc_rdc", "formal"),
                    )
                    if str(group) != "traceability"
                ),
            )
            for group in groups:
                stages.extend(EVIDENCE_GROUPS[group])
        if level >= 2 and spec.get("spec_traceability", {}).get("model_cases_to_testplan"):
            # Display model verification immediately after requirements traceability.
            stages[1:1] = EVIDENCE_GROUPS["model"]
        if level >= 3:
            stages.extend(EVIDENCE_GROUPS["netlist"])
        if level >= 4:
            stages.extend(EVIDENCE_GROUPS["technology"])
        if level >= 5:
            stages.extend(EVIDENCE_GROUPS["physical_signoff"])
        return tuple(dict.fromkeys(stages))

    @staticmethod
    def evidence_state(
        provenance_state: str, *, outcome: str | None = None, waived: bool = False,
    ) -> str:
        """Combine provenance freshness with an independently recorded tool outcome."""

        if waived:
            return "WAIVED"
        freshness = str(provenance_state).upper()
        if freshness == "MISSING":
            return "MISSING"
        if freshness == "STALE":
            return "STALE"
        if freshness == "MODIFIED":
            return "INVALID"

        normalized = str(outcome).upper() if outcome is not None else None
        if normalized in {"FAILED", "REVIEW", "WAIVED"}:
            return normalized
        if freshness == "INVALID":
            return "INVALID"
        if freshness in {"CLEAN", "VALIDATED_OVERRIDE"}:
            if normalized == "PASS":
                return "PASS"
            # Fresh artifacts without a recorded runtime outcome are not an EDA PASS.
            return "REVIEW" if normalized is None else "INVALID"
        return "INVALID"

    @staticmethod
    def cdc_rdc_review_acceptance(
        summary_path: Path, *, enabled: bool, evidence_state: str,
    ) -> dict[str, object] | None:
        """Accept reviewed structural analysis as an explicit release policy decision.

        This does not waive CDC/RDC verification obligations or rewrite tool evidence.
        """
        if not enabled or evidence_state != "REVIEW" or not summary_path.is_file():
            return None
        try:
            raw = summary_path.read_bytes()
            summary = json.loads(raw)
            if not isinstance(summary, dict) or str(summary.get("status", "")).lower() != "review":
                return None
            obligations = summary.get("verification_obligations")
            if type(obligations) is not int or obligations < 0:
                return None
            for scope in ("cdc", "rdc", "setup", "glitch"):
                block = summary.get(scope)
                if not isinstance(block, dict):
                    return None
                for count in ("errors", "warnings"):
                    if type(block.get(count)) is not int or block[count] != 0:
                        return None
            return {
                "policy": "cdc_rdc_structural_review_v1",
                "summary_sha256": hashlib.sha256(raw).hexdigest(),
                "open_obligations": obligations,
                "analysis_status": "REVIEW",
                "scope": "Structural acceptance only; verification obligations remain open",
            }
        except (OSError, ValueError, TypeError, json.JSONDecodeError):
            return None

    @staticmethod
    def build_qualification_report(
        *,
        ip_name: str,
        reg_interface: str,
        pdk: str,
        spec: Mapping[str, object],
        stage_states: Mapping[str, str],
        contract_ready: bool,
        requested_level: str | int | None = None,
        stage_outcomes: Mapping[str, str | None] | None = None,
        deferrals: Mapping[str, Mapping[str, str]] | None = None,
        accepted_reviews: Mapping[str, Mapping[str, object]] | None = None,
    ) -> dict[str, object]:
        """Derive the maximum release level from freshness plus independent outcomes."""

        outcomes = dict(stage_outcomes or {})
        deferrals = dict(deferrals or {})
        accepted_reviews = dict(accepted_reviews or {})
        evidence = {
            stage: QualificationFlow.evidence_state(state, outcome=outcomes.get(stage))
            for stage, state in stage_states.items()
        }
        for stage, outcome in outcomes.items():
            if stage not in evidence and outcome is not None:
                evidence[stage] = str(outcome).upper()
        # Coverage is a reviewable qualification gate, not a synthetic EDA PASS.
        # Keep uncovered IDs in the report even when an engineering deferral exists.
        evidence["requirements_coverage"] = (
            "REVIEW" if spec.get("uncovered_requirements") else "PASS"
        )
        maximum = 1 if contract_ready else 0
        maximum_pass = maximum
        levels: dict[str, object] = {}
        for level in range(1, 6):
            required = QualificationFlow.required_stages(spec, level)
            blocking = [
                stage for stage in required
                if evidence.get(stage) not in {"PASS", "WAIVED"}
                and not (stage == "cdc_rdc" and evidence.get(stage) == "REVIEW"
                         and stage in accepted_reviews)
            ]
            if level >= 2 and evidence["requirements_coverage"] != "PASS":
                blocking.append("requirements_coverage")
            if level >= 3 and evidence.get("eqy") == "FAILED":
                blocking.append("eqy")
            blocking = list(dict.fromkeys(blocking))
            waived = [stage for stage in required if evidence.get(stage) == "WAIVED"]
            deferred = [stage for stage in blocking if stage in deferrals]
            development_blocking = [stage for stage in blocking if stage not in deferrals]
            satisfied = contract_ready and not blocking and (level == 1 or maximum == level - 1)
            status = "BLOCKED"
            if satisfied:
                maximum = level
                status = "WAIVED" if waived else "PASS"
                if status == "PASS":
                    maximum_pass = level
            levels[str(level)] = {
                "name": QualificationFlow.qualification_name(level),
                "status": status,
                "required_evidence": list(required),
                "blocking_evidence": blocking,
                "waived_evidence": waived,
                "accepted_review_evidence": sorted(
                    stage for stage in required if stage in accepted_reviews
                    and evidence.get(stage) == "REVIEW"
                ),
                "deferred_evidence": deferred,
                "development_blocking_evidence": development_blocking,
                "development_status": "CONDITIONAL" if contract_ready and deferred and not development_blocking else ("READY" if status == "PASS" else "BLOCKED"),
            }

        requested = QualificationFlow.normalize_qualification_level(requested_level)
        target_status = (
            levels[str(requested)]["status"]
            if requested is not None and requested > 0
            else (levels[str(maximum)]["status"] if maximum > 0 else "BLOCKED")
        )
        target_satisfied = True if requested is None else target_status in {"PASS", "WAIVED"}
        return {
            "schema": 1,
            "ip": ip_name,
            "reg_interface": reg_interface,
            "pdk": pdk,
            "contract_fingerprint": spec.get("fingerprint"),
            "requirements": {
                "total": spec.get("baselined_requirements", 0),
                "covered": spec.get("covered_requirements", 0),
                "uncovered": list(spec.get("uncovered_requirements", ())),
                "status": "PASS" if not spec.get("uncovered_requirements") else "PARTIAL",
            },
            "maximum_level": maximum,
            "maximum_qualification": QualificationFlow.qualification_name(maximum),
            "maximum_pass_level": maximum_pass,
            "maximum_pass_qualification": QualificationFlow.qualification_name(maximum_pass),
            "qualification_status": levels[str(maximum)]["status"] if maximum > 0 else "BLOCKED",
            "requested_level": requested,
            "target_status": target_status,
            "target_satisfied": target_satisfied,
            "levels": levels,
            "evidence": evidence,
            "engineering_deferrals": deferrals,
            "review_acceptances": accepted_reviews,
            "freshness": {stage: str(state).upper() for stage, state in sorted(stage_states.items())},
            "outcomes": {
                stage: (str(value).upper() if value is not None else None)
                for stage, value in sorted(outcomes.items())
            },
        }

    @staticmethod
    def write_contract_snapshot(
        *,
        staged: Path,
        spec_root: Path,
        ip_name: str,
        reg_interface: str,
        version: str | None = None,
    ) -> Path:
        """Write one release contract metadata file against the common IP spec."""

        staged = Path(staged)
        spec = QualificationFlow.validate_spec_bundle(spec_root, ip_name=ip_name)
        meta = staged / "meta"
        meta.mkdir(parents=True, exist_ok=True)

        source_of_truth: dict[str, object] = {
            "specification": {
                name: {
                    "source": f"spec/{name}",
                    "sha256": spec["hashes"][name],
                }
                for name in spec["hashes"]
            }
        }
        csr = []
        for path in sorted((staged / "csr").glob("*.hjson")):
            csr.append({"path": path.relative_to(staged).as_posix(), "sha256": QualificationFlow.sha256_file(path)})
        source_of_truth["registers"] = csr

        authored_rtl = []
        for path in sorted((staged / "rtl").glob("*.sv")):
            text = path.read_text(encoding="utf-8", errors="replace")
            if "Auto-generated by flexsoc" in text or "Generated by reggen" in text:
                continue
            authored_rtl.append({"path": path.relative_to(staged).as_posix(), "sha256": QualificationFlow.sha256_file(path)})
        source_of_truth["authored_rtl"] = authored_rtl

        constraints = []
        for path in sorted((staged / "constraints").glob("*.sdc")):
            constraints.append({
                "path": path.relative_to(staged).as_posix(),
                "sha256": QualificationFlow.sha256_file(path),
            })
        source_of_truth["constraints"] = constraints

        formal_properties = []
        properties_root = staged / "dv" / "formal" / "properties"
        if properties_root.is_dir():
            for path in sorted(properties_root.rglob("*.sv")):
                formal_properties.append({
                    "path": path.relative_to(staged).as_posix(),
                    "sha256": QualificationFlow.sha256_file(path),
                })
        source_of_truth["formal_properties"] = formal_properties

        contract: dict[str, object] = {
            "schema": 2,
            "ip": ip_name,
            "reg_interface": reg_interface,
            "spec_fingerprint": spec["fingerprint"],
            "source_of_truth": source_of_truth,
        }
        if version:
            contract["version"] = version
        design_intent = meta / "design_intent.json"
        if design_intent.is_file():
            intent = json.loads(design_intent.read_text(encoding="utf-8"))
            for key in ("top", "ip_intent_sha256", "design_intent", "sources"):
                if key in intent:
                    contract[key] = intent[key]
            design_intent.unlink()

        shutil.rmtree(staged / "contract", ignore_errors=True)
        output = meta / "contract.json"
        output.write_text(json.dumps(contract, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        return output

    @staticmethod
    def validate_contract_snapshot(
        package_root: Path, *, spec_root: Path | None = None,
        allow_spec_drift: bool = False,
    ) -> dict[str, object]:
        """Validate the current interface release contract and common specification."""

        root = Path(package_root)
        contract_file = root / "meta" / "contract.json"
        if not contract_file.is_file():
            raise FileNotFoundError(f"missing release contract: {contract_file}")
        contract = json.loads(contract_file.read_text(encoding="utf-8"))
        effective_spec_root = Path(spec_root) if spec_root is not None else root.parent.parent / "spec"
        spec = QualificationFlow.validate_spec_bundle(effective_spec_root, ip_name=str(contract.get("ip", "")))
        if contract.get("spec_fingerprint") != spec["fingerprint"] and not allow_spec_drift:
            raise ValueError("IP-level spec fingerprint does not match packaged contract snapshot")
        if allow_spec_drift and str(contract.get("version", "")) != str(spec.get("version", "")):
            raise ValueError("IP-level specification version differs from source release")

        source_of_truth = contract.get("source_of_truth", {}) or {}
        if not isinstance(source_of_truth, dict):
            raise ValueError("release contract source_of_truth must be a mapping")
        for group in ("registers", "authored_rtl", "constraints", "formal_properties"):
            entries = source_of_truth.get(group, []) or []
            if not isinstance(entries, list):
                raise ValueError(f"release contract source_of_truth.{group} must be a list")
            for entry in entries:
                if not isinstance(entry, dict):
                    raise ValueError(f"release contract {group} entry must be a mapping")
                relative = str(entry.get("path", "")).strip()
                expected = str(entry.get("sha256", "")).strip()
                if not relative or not expected:
                    raise ValueError(f"release contract {group} entry is incomplete")
                path = root / relative
                try:
                    path.resolve().relative_to(root.resolve())
                except ValueError as exc:
                    raise ValueError(f"release contract path escapes package: {relative}") from exc
                if not path.is_file():
                    raise FileNotFoundError(f"release source-of-truth artifact missing: {relative}")
                actual = QualificationFlow.sha256_file(path)
                if actual != expected:
                    raise ValueError(
                        f"release source-of-truth artifact is stale: {relative} "
                        f"expected={expected} actual={actual}"
                    )

        return {"contract": contract, "spec": spec}

    @staticmethod
    def rtl_evidence_integrity(root: Path, *, write: bool = False) -> bool:
        """Seal exactly the portable L1/L2 files without a PDK identity.

        This record authenticates both source bytes and the stored verification
        summaries; adding unexpected non-transient evidence is an integrity error.
        """
        root = Path(root)
        output = root / "meta" / "rtl_evidence_integrity.json"
        report = root / "meta" / "rtl_qualification.json"
        if not report.is_file():
            return False
        files = [report]
        for folder in ("rtl", "csr", "constraints", "dv"):
            path = root / folder
            if path.is_dir():
                files.extend(file for file in path.rglob("*") if file.is_file()
                             and not ArtifactPolicy.is_transient(root, file)
                             and "__pycache__" not in file.relative_to(root).parts
                             and file.suffix not in {".pyc", ".pyo"}
                             and file.relative_to(root).parts[:5]
                             != ("dv", "functional", "py", "model", "results"))
        actual = {file.relative_to(root).as_posix(): QualificationFlow.sha256_file(file)
                  for file in sorted(set(files))}
        if write:
            output.parent.mkdir(parents=True, exist_ok=True)
            output.write_text(json.dumps({"schema": 1, "files": actual}, indent=2, sort_keys=True) + "\n",
                              encoding="utf-8")
            return True
        if not output.is_file():
            return False
        saved = json.loads(output.read_text(encoding="utf-8"))
        if saved.get("schema") != 1 or not isinstance(saved.get("files"), dict):
            raise ValueError("invalid RTL evidence integrity manifest")
        expected = saved["files"]
        if expected != actual:
            changed = next((name for name in sorted(set(expected) | set(actual))
                            if expected.get(name) != actual.get(name)), "unknown")
            raise ValueError(f"RTL qualification evidence or sources changed: {changed}")
        return True

    @staticmethod
    def evidence_integrity(
        root: Path, pdk: str, *, write: bool = False, allow_updated_generated: bool = False,
    ) -> bool:
        """Bind reusable qualification to the exact source and evidence bytes shipped."""
        root = Path(root)
        record = root / "meta" / pdk / "evidence_integrity.json"
        def runtime_only(path: Path) -> bool:
            if ArtifactPolicy.is_transient(root, path):
                return True
            relative = path.relative_to(root)
            return ("__pycache__" in relative.parts
                    or relative.suffix in (".pyc", ".pyo")
                    or relative.parts[:5] == ("dv", "functional", "py", "model", "results"))

        paths = [
            path for folder in (
                *(root / name for name in ("rtl", "csr", "constraints", "dv")),
                *(root / name / pdk for name in ("syn", "signoff", "impl")),
            )
            if folder.is_dir()
            for path in folder.rglob("*")
            if path.is_file() and not runtime_only(path)
        ]
        report = root / "meta" / pdk / "qualification.json"
        if not report.is_file():
            return False
        paths.append(report)
        actual = {
            path.relative_to(root).as_posix(): QualificationFlow.sha256_file(path)
            for path in sorted(paths)
        }
        if write:
            ownership = EvidenceOwnership.from_provenance(root, pdk, actual)
            if record.is_file():
                previous = json.loads(record.read_text(encoding="utf-8"))
                if previous.get("schema") == 2:
                    old = EvidenceOwnership.from_manifest(previous)
                    # An authored input never becomes mutable on reseal.
                    for name in old.sources:
                        if name in actual:
                            ownership.sources[name] = actual[name]
                            ownership.generated.pop(name, None)
                    # Keep a generated stage identity even if provenance was reset.
                    for name, item in old.generated.items():
                        if name in actual and name not in old.sources:
                            ownership.generated[name] = {"sha256": actual[name], "stage": item["stage"]}
                            ownership.sources.pop(name, None)
            record.parent.mkdir(parents=True, exist_ok=True)
            record.write_text(json.dumps(ownership.as_manifest(), indent=2, sort_keys=True) + "\n", encoding="utf-8")
            return True
        if not record.is_file():
            return False
        saved = json.loads(record.read_text(encoding="utf-8"))
        if saved.get("schema") == 2:
            inventory = EvidenceOwnership.from_manifest(saved)
            expected = dict(inventory.sources)
            expected.update({name: item["sha256"] for name, item in inventory.generated.items()})
            refreshable = set(inventory.generated) if allow_updated_generated else set()
        elif saved.get("schema") == 1 and isinstance(saved.get("files"), dict):
            # Old releases are conservative: provenance may prove ownership,
            # but an unregistered file can never become mutable by guessing a path.
            expected = {name: digest for name, digest in saved["files"].items()
                        if not ("__pycache__" in Path(name).parts
                                or Path(name).suffix in (".pyc", ".pyo")
                                or Path(name).parts[:5] == ("dv", "functional", "py", "model", "results"))}
            inventory = EvidenceOwnership.from_provenance(root, pdk, expected)
            refreshable = set(inventory.generated) if allow_updated_generated else set()
        else:
            raise ValueError(f"{pdk}: invalid packaged evidence integrity manifest")
        # Ignore only producer-declared cache, including historical v1 entries.
        expected = {name: digest for name, digest in expected.items()
                    if not ArtifactPolicy.is_transient(root, root / name)}
        # Shared primitives materialized during load are not packaged content.
        common = root / "rtl" / "rtl_common.f"
        shared = set()
        if common.is_file():
            shared = {
                line.strip() for line in common.read_text(encoding="utf-8").splitlines()
                if line.strip().startswith(("rtl/deps/flexsoc/prim/", "rtl/deps/flexsoc/hw/ips/prim/"))
                and line.strip().endswith(".sv")
            }
        # Generated files are only eligible for *modification*, never deletion;
        # newly created output files require a fresh stage provenance record.
        allowed = set(shared) & (set(actual) - set(expected))
        if allow_updated_generated:
            provenance = EvidenceOwnership.from_provenance(root, pdk, actual)
            # New results belong to a recorded producer, never to an authored input.
            allowed.update(set(provenance.generated) - set(expected))
        changed = next((name for name in sorted(set(expected) | set(actual))
                        if name not in allowed and
                        (name not in refreshable or name not in actual) and
                        expected.get(name) != actual.get(name)), None)
        if changed:
            raise ValueError(f"{pdk}: packaged qualification evidence or sources changed: {changed}")
        return True
    @staticmethod
    def validate_release_package(
        package_root: Path, *, spec_root: Path | None = None,
    ) -> dict[str, object]:
        """Validate one frozen interface release, common spec, and evidence references."""

        root = Path(package_root)
        manifest_path = root / "ip.json"
        if not manifest_path.is_file():
            raise FileNotFoundError(f"missing release manifest: {manifest_path}")
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        if manifest.get("format") != "flexsoc-ip":
            raise ValueError(f"invalid release format in {manifest_path}")
        if "profile" in manifest:
            raise ValueError("legacy profile identity is not allowed in interface releases")
        reg_interface = str(manifest.get("reg_interface", "")).strip()
        if not reg_interface or root.name != reg_interface:
            raise ValueError(
                f"release path/interface mismatch: path={root.name!r} reg_interface={reg_interface!r}"
            )
        version = str(manifest.get("version", "")).strip() or None
        interfaces_root = next(
            (parent for parent in root.parents if parent.name == "interfaces"),
            None,
        )
        if version:
            path_version = interfaces_root.parent.name if interfaces_root is not None else None
            if path_version != version:
                raise ValueError(
                    f"release path/version mismatch: path={path_version!r} version={version!r}"
                )

        contract_data = QualificationFlow.validate_contract_snapshot(root, spec_root=spec_root)
        contract = contract_data["contract"]
        if contract.get("reg_interface") != reg_interface:
            raise ValueError("release manifest and contract snapshot disagree on reg_interface")
        if contract.get("ip") != manifest.get("name"):
            raise ValueError("release manifest and contract snapshot disagree on IP identity")
        if version and contract.get("version") != version:
            raise ValueError("release manifest and contract snapshot disagree on version")

        common_spec_root = (
            Path(spec_root)
            if spec_root is not None
            else (interfaces_root.parent / "spec" if interfaces_root is not None else root.parent.parent / "spec")
        )
        common_spec = QualificationFlow.validate_spec_bundle(common_spec_root, ip_name=str(manifest.get("name", "")))
        # IP_SAVE_VERSIONLESS_COMMON_SPEC_M18: versionless specs are reusable
        # across releases; an explicitly versioned spec must still match.
        if version and common_spec.get("version") not in (None, version):
            raise ValueError("release manifest and common spec disagree on version")
        if common_spec.get("fingerprint") != contract.get("spec_fingerprint"):
            raise ValueError("IP-level spec fingerprint does not match packaged contract snapshot")

        qualification = manifest.get("qualification", {}) or {}
        if not isinstance(qualification, dict):
            raise ValueError("ip.json qualification must be a mapping")
        rtl_path = root / "meta" / "rtl_qualification.json"
        if rtl_path.is_file():
            rtl = json.loads(rtl_path.read_text(encoding="utf-8"))
            if rtl.get("pdk") is not None:
                raise ValueError("L1/L2 qualification must not contain PDK metadata")
            if rtl.get("contract_fingerprint") != contract.get("spec_fingerprint"):
                raise ValueError("L1/L2 qualification fingerprint mismatch")
            if rtl.get("ip") != manifest.get("name") or rtl.get("reg_interface") != reg_interface:
                raise ValueError("L1/L2 qualification IP/interface mismatch")
            if rtl != QualificationFlow.rtl_qualification_report(rtl):
                raise ValueError("L1/L2 qualification report is not canonical")
        neutral_seal = root / "meta" / "rtl_evidence_integrity.json"
        if neutral_seal.is_file():
            if not rtl_path.is_file() or not QualificationFlow.rtl_evidence_integrity(root):
                raise ValueError("invalid technology-independent RTL evidence")
        technologies = qualification.get("technologies", {}) or {}
        if not isinstance(technologies, dict):
            raise ValueError("ip.json qualification.technologies must be a mapping")

        checked_refs = 0
        report_levels: list[int] = []
        metadata_keys = {
            "maximum_level", "maximum_qualification", "maximum_pass_level",
            "maximum_pass_qualification", "qualification_status",
        }
        for pdk, evidence in technologies.items():
            if not isinstance(evidence, dict):
                raise ValueError(f"qualification technology {pdk!r} must be a mapping")
            for key, value in evidence.items():
                if key in metadata_keys:
                    continue
                if not isinstance(value, str):
                    continue
                path = root / value
                if not path.is_file() and not path.is_dir():
                    raise FileNotFoundError(f"qualification evidence reference missing: {value}")
                checked_refs += 1
            # New releases bind qualification to the packaged bytes. Older
            # releases remain readable, but are not trusted for evidence reuse.
            QualificationFlow.evidence_integrity(root, str(pdk))
            report_ref = evidence.get("qualification")
            if isinstance(report_ref, str):
                report = json.loads((root / report_ref).read_text(encoding="utf-8"))
                if report.get("reg_interface") != reg_interface:
                    raise ValueError(f"{pdk}: qualification report has wrong reg_interface")
                if str(report.get("pdk", "")) != str(pdk):
                    raise ValueError(f"{pdk}: qualification report has wrong PDK identity")
                if report.get("contract_fingerprint") != contract.get("spec_fingerprint"):
                    raise ValueError(f"{pdk}: qualification report is stale against packaged contract")
                try:
                    level = int(report.get("maximum_level", 0))
                except (TypeError, ValueError) as exc:
                    raise ValueError(f"{pdk}: qualification report has invalid maximum_level") from exc
                if not 0 <= level < len(QUALIFICATION_LEVELS):
                    raise ValueError(f"{pdk}: qualification report has invalid maximum_level {level}")
                expected_name = QualificationFlow.qualification_name(level)
                if report.get("maximum_qualification") != expected_name:
                    raise ValueError(f"{pdk}: qualification report level/name mismatch")
                for key in metadata_keys:
                    if key in evidence and evidence.get(key) != report.get(key):
                        raise ValueError(f"{pdk}: ip.json {key} disagrees with qualification report")
                report_levels.append(level)

        summary = qualification.get("summary", {}) or {}
        if not isinstance(summary, dict):
            raise ValueError("ip.json qualification.summary must be a mapping")
        rtl_level = int(rtl.get("maximum_level", 0)) if rtl_path.is_file() and neutral_seal.is_file() else 0
        expected_level = max([1, rtl_level, *report_levels])
        try:
            declared_level = int(summary.get("maximum_level", -1))
        except (TypeError, ValueError) as exc:
            raise ValueError("ip.json qualification.summary.maximum_level is invalid") from exc
        if declared_level != expected_level:
            raise ValueError(
                f"ip.json qualification summary is stale: maximum_level={declared_level} "
                f"expected={expected_level}"
            )
        if summary.get("maximum_qualification") != QualificationFlow.qualification_name(expected_level):
            raise ValueError("ip.json qualification summary level/name mismatch")

        return {
            "schema": 1,
            "ip": manifest.get("name"),
            "version": version,
            "reg_interface": reg_interface,
            "contract_fingerprint": contract.get("spec_fingerprint"),
            "technology_branches": sorted(str(item) for item in technologies),
            "checked_evidence_refs": checked_refs,
        }
