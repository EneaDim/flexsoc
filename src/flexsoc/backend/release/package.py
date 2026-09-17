"""Reusable IP package load/save contract."""

from __future__ import annotations

import json
import os
import re
import shutil
import tempfile
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from pathlib import Path
from typing import TYPE_CHECKING, Mapping, Sequence

from .qualification import QualificationFlow, SPEC_FILES
from .reporting import Reporting


IPXACT_NS = "http://www.accellera.org/XMLSchema/IPXACT/1685-2022"
XSI_NS = "http://www.w3.org/2001/XMLSchema-instance"
ET.register_namespace("ipxact", IPXACT_NS)
ET.register_namespace("xsi", XSI_NS)


if TYPE_CHECKING:
    from flexsoc.backend.core.core import BackendContext
    from flexsoc.backend.core.flow.target import Target


SYNTHESIS_RELEASE_FILES = (
    "abc.constr", "synth_pre.ys", "synth_pre_sv.ys", "synth.ys", "synth_sv.ys",
    "repair_config.mk", "repair.tcl", "repair_json.ys",
)
SIGNOFF_RELEASE_FILES = (
    "sta/sta.tcl", "sta/summary.json",
    "sdf/write_sdf.tcl",
    "power/estimate/power_estimate.tcl", "power/estimate/summary.json",
    "power/analysis/power_analysis.tcl", "power/analysis/summary.json",
    "fusion/fusion_analysis.tcl", "fusion/summary.json",
)
PHYSICAL_RELEASE_FILES = ("physical/summary.json",)
PNR_FINAL_FILES = ("6_final.v", "6_final.sdc", "6_final.spef", "6_final.odb", "6_final.gds")


_RUNTIME_QOR_KEYS = frozenset({
    "activity_file", "conversion_log", "detail_log", "detail_report", "liberty", "log",
    "power_detail_log", "report", "script", "source_gls_report", "source_wave", "spef",
    "table", "vcd_scopes",
})

@dataclass(slots=True)
class PackageFlow:
    """Load and atomically save reusable IP artifacts without Make indirection."""

    project_root: Path
    values: Mapping[str, str]

    def run(
        self,
        target: "Target",
        context: "BackendContext",
        *,
        qualification: Mapping[str, object] | None = None,
        cell_models: Sequence[Path] = (),
        force: bool = False,
    ) -> Path:
        """Execute one package target from the declarative registry."""

        paths = context.paths
        values = context.values
        interface = values.get("REG_ITF", "tlul")
        ip_name = values.get("IP_NAME", paths.top)

        if target.action == "load":
            return self.load(
                ip_name=ip_name, reg_interface=interface,
                run_top=paths.run_top, run_id=paths.run_id,
                workspace=context.workspace, load_as=values.get("LOAD_AS") or None,
                version=values.get("IP_VERSION") or None,
            )
        if target.action == "ipxact":
            return self.export_ipxact(
                top=paths.top, csr_dir=paths.csr, rtl_dir=paths.rtl, output=paths.run / "component.xml",
                vendor=values.get("IPXACT_VENDOR", "flexsoc"),
                library=values.get("IPXACT_LIBRARY", "ip"),
                version=values.get("IPXACT_VERSION", "1.0.0"),
            )
        if target.action != "save":
            raise ValueError(f"unsupported package target: {target.name}")
        if qualification is None:
            raise ValueError("ip_save requires qualification evidence")

        requested = QualificationFlow.normalize_qualification_level(values.get("QUAL_LEVEL", "auto"))
        if requested is not None and not qualification.get("target_satisfied", False):
            raise RuntimeError(
                f"requested qualification level L{requested} is not satisfied; "
                f"maximum is L{qualification.get('maximum_level', 0)}"
            )

        implementation = Reporting.collect_implementation(paths.top, paths.run, paths.pdk)
        impl_available = (
            isinstance(implementation, dict) and implementation.get("status") == "pass"
        )
        eqy = context.layout.equivalence_dir
        return self.save(
            ip_name=ip_name, reg_interface=interface, top=paths.top, pdk=paths.pdk,
            library_root=Path(values.get("IP_LIBRARY_ROOT", context.project_root / "hw" / "ips")),
            synth_dir=paths.syn, signoff_dir=paths.signoff, sdc_file=paths.sdc,
            eqy_config=eqy / f"{paths.top}_rtl_vs_syn.eqy",
            eqy_view=eqy / f"{paths.top}_eqy_view.sv",
            filelists=(paths.rtl_common, paths.rtl_ip),
            netlist=paths.syn / f"{paths.top}_synth.v",
            liberty=Path(values["LIB_SYN"]), cell_models=cell_models,
            clock_gate_model=eqy / "sky130_clock_gates_formal.v",
            impl_dir=paths.impl if impl_available else None,
            post_syn_sim_dir=context.layout.post_syn_sim_dir,
            coverage_dir=paths.coverage, manifest_json=paths.manifest, metrics_json=paths.metrics,
            settings_json=paths.meta / "settings.json",
            design_intent_json=paths.run / "meta" / "design_intent.json",
            qualification_json=paths.meta / "qualification.json",
            version=values.get("IP_VERSION") or None, force=force,
        )

    def load(
        self,
        *,
        ip_name: str,
        reg_interface: str,
        run_top: str,
        run_id: str,
        workspace: Path,
        load_as: str | None = None,
        version: str | None = None,
    ) -> Path:
        """Load one frozen register-interface release into a canonical run workspace."""

        reg_interface = PackageFlow._package_interface(reg_interface)
        release_root = self.project_root / "hw" / "ips" / ip_name
        if version:
            release_root = release_root / version
        source = release_root / "interfaces" / reg_interface
        if not source.is_dir():
            raise FileNotFoundError(f"missing source IP interface release: {source}")
        PackageFlow._validate_package_manifest(
            source, ip_name=ip_name, reg_interface=reg_interface, version=version
        )
        QualificationFlow.validate_release_package(source)
        run = Path(workspace) / "runs" / run_top / run_id
        destination = run if run_top == ip_name else run / "ips" / (load_as or ip_name)
        if destination.exists() and destination != run:
            shutil.rmtree(destination)
        PackageFlow._copy_contents(source, destination)
        common_spec = source.parent.parent / "spec"
        if common_spec.is_dir():
            self._replace_tree(common_spec, destination / "spec")
        # Release packages group technology evidence under signoff/<pdk>/post_syn
        # and physical evidence under signoff/<pdk>/post_impl. The operational
        # run layout keeps post-synthesis evidence directly under signoff/<pdk>/,
        # so materialize that view without changing the frozen package contract.
        packaged_signoff = destination / "signoff"
        if packaged_signoff.is_dir():
            staged_signoff = destination / ".packaged_signoff"
            packaged_signoff.rename(staged_signoff)
            packaged_signoff.mkdir(parents=True, exist_ok=True)
            for pdk_dir in sorted(path for path in staged_signoff.iterdir() if path.is_dir()):
                run_pdk = packaged_signoff / pdk_dir.name
                post_syn = pdk_dir / "post_syn"
                post_impl = pdk_dir / "post_impl"
                if post_syn.is_dir():
                    PackageFlow._copy_contents(post_syn, run_pdk)
                if post_impl.is_dir():
                    self._replace_tree(post_impl, run_pdk / "post_impl")
            shutil.rmtree(staged_signoff)
        PackageFlow._clean_python_cache(destination)
        PackageFlow._rebind_filelists(destination, self.project_root)
        return destination

    def export_ipxact(
        self,
        *,
        top: str,
        csr_dir: Path,
        rtl_dir: Path,
        output: Path,
        vendor: str = "flexsoc",
        library: str = "ip",
        version: str = "1.0.0",
    ) -> Path:
        """Export deterministic IEEE 1685-2022 component metadata for one IP run."""

        from flexsoc.backend.design.ip.regs import RegsFlow
        from flexsoc.backend.design.ip.rtl import RtlFlow

        top_file = Path(rtl_dir) / f"{top}.sv"
        if not top_file.is_file():
            raise FileNotFoundError(f"missing generated top RTL: {top_file}")
        _, registers = RegsFlow._collect(top, Path(csr_dir))
        output = Path(output)
        output.parent.mkdir(parents=True, exist_ok=True)

        root = ET.Element(
            f"{{{IPXACT_NS}}}component",
            {f"{{{XSI_NS}}}schemaLocation": f"{IPXACT_NS} {IPXACT_NS}/index.xsd"},
        )
        for name, value in (("vendor", vendor), ("library", library), ("name", top), ("version", version)):
            PackageFlow._xe(root, name, value)

        by_domain: dict[str, list[object]] = {}
        for register in registers:
            by_domain.setdefault(register.domain, []).append(register)
        memory_maps = PackageFlow._xe(root, "memoryMaps")
        for domain in sorted(by_domain):
            domain_regs = sorted(by_domain[domain], key=lambda reg: (reg.offset, reg.name))
            memory_map = PackageFlow._xe(memory_maps, "memoryMap")
            PackageFlow._xe(memory_map, "name", f"{domain}_register_map")
            block = PackageFlow._xe(memory_map, "addressBlock")
            PackageFlow._xe(block, "name", f"{domain}_registers")
            PackageFlow._xe(block, "baseAddress", "0")
            PackageFlow._xe(block, "range", str(max(4, max(reg.offset + 4 for reg in domain_regs))))
            PackageFlow._xe(block, "width", "32")
            policies = PackageFlow._xe(block, "accessPolicies")
            PackageFlow._xe(PackageFlow._xe(policies, "accessPolicy"), "access", "read-write")
            for register in domain_regs:
                reg = PackageFlow._xe(block, "register")
                PackageFlow._xe(reg, "name", register.name)
                PackageFlow._xe(reg, "addressOffset", str(register.offset))
                PackageFlow._xe(reg, "size", "32")
                access = PackageFlow._xe(reg, "accessPolicies")
                PackageFlow._xe(
                    PackageFlow._xe(access, "accessPolicy"),
                    "access",
                    PackageFlow._ipxact_access(register.readable, register.writable),
                )
                for field in register.fields:
                    field_xml = PackageFlow._xe(reg, "field")
                    PackageFlow._xe(field_xml, "name", field.name)
                    PackageFlow._xe(field_xml, "bitOffset", str(field.lsb))
                    PackageFlow._xe(field_xml, "bitWidth", str(field.msb - field.lsb + 1))
                    if field.reset is not None:
                        resets = PackageFlow._xe(field_xml, "resets")
                        reset = PackageFlow._xe(resets, "reset")
                        PackageFlow._xe(reset, "value", str(field.reset))
                        PackageFlow._xe(reset, "mask", str((1 << (field.msb - field.lsb + 1)) - 1))
                    policies = PackageFlow._xe(field_xml, "fieldAccessPolicies")
                    policy = PackageFlow._xe(policies, "fieldAccessPolicy")
                    PackageFlow._xe(policy, "access", PackageFlow._ipxact_access(field.readable, field.writable))
                    modified = {
                        "rw1c": "oneToClear", "r0w1c": "oneToClear",
                        "rw1s": "oneToSet", "rw0c": "zeroToClear",
                    }.get(field.swaccess)
                    if modified:
                        PackageFlow._xe(policy, "modifiedWriteValue", modified)
            PackageFlow._xe(memory_map, "addressUnitBits", "8")

        model = PackageFlow._xe(root, "model")
        views = PackageFlow._xe(model, "views")
        view = PackageFlow._xe(views, "view")
        PackageFlow._xe(view, "name", "rtl")
        PackageFlow._xe(view, "componentInstantiationRef", "rtl")
        instantiations = PackageFlow._xe(model, "instantiations")
        instantiation = PackageFlow._xe(instantiations, "componentInstantiation")
        PackageFlow._xe(instantiation, "name", "rtl")
        PackageFlow._xe(instantiation, "language", "SystemVerilog")
        PackageFlow._xe(instantiation, "moduleName", top)
        file_ref = PackageFlow._xe(instantiation, "fileSetRef")
        PackageFlow._xe(file_ref, "localName", "rtl")
        ports = PackageFlow._xe(model, "ports")
        for port in RtlFlow.parse_ports(top_file):
            PackageFlow._ipxact_port(ports, port)

        file_sets = PackageFlow._xe(root, "fileSets")
        file_set = PackageFlow._xe(file_sets, "fileSet")
        PackageFlow._xe(file_set, "name", "rtl")
        for source in PackageFlow._ipxact_rtl_files(Path(rtl_dir)):
            file_xml = PackageFlow._xe(file_set, "file")
            PackageFlow._xe(file_xml, "name", os.path.relpath(source, output.parent).replace(os.sep, "/"))
            PackageFlow._xe(file_xml, "fileType", "systemVerilogSource")

        ET.indent(root, space="  ")
        ET.ElementTree(root).write(output, encoding="utf-8", xml_declaration=True)
        return output

    def save(
        self,
        *,
        ip_name: str,
        reg_interface: str,
        top: str,
        pdk: str,
        library_root: Path,
        synth_dir: Path,
        signoff_dir: Path,
        sdc_file: Path,
        eqy_config: Path,
        eqy_view: Path,
        filelists: Sequence[Path],
        netlist: Path,
        liberty: Path,
        cell_models: Sequence[Path],
        clock_gate_model: Path,
        impl_dir: Path | None = None,
        post_syn_sim_dir: Path | None = None,
        coverage_dir: Path | None = None,
        manifest_json: Path | None = None,
        metrics_json: Path | None = None,
        settings_json: Path | None = None,
        design_intent_json: Path | None = None,
        qualification_json: Path | None = None,
        spec_root: Path | None = None,
        version: str | None = None,
        force: bool = False,
    ) -> Path:
        """Atomically update one PDK branch in the reusable interface release."""

        required = (synth_dir, signoff_dir, sdc_file, eqy_config, eqy_view, netlist, liberty)
        missing = [path for path in required if not Path(path).exists()]
        if missing:
            raise FileNotFoundError("required ip_save input not found: " + ", ".join(map(str, missing)))

        library_root = Path(library_root)
        reg_interface = PackageFlow._package_interface(reg_interface)
        release_root = library_root / ip_name
        if version:
            release_root = release_root / version
        interface_root = release_root / "interfaces"
        target = interface_root / reg_interface
        conflicts = [target / "syn" / pdk, target / "signoff" / pdk / "post_syn"]
        if impl_dir and Path(impl_dir).is_dir():
            conflicts.append(target / "impl" / pdk)
        existing = [path for path in conflicts if path.exists()]
        if existing and not force:
            names = ", ".join(str(path.relative_to(target)) for path in existing)
            raise FileExistsError(f"ip_save would overwrite existing package content: {names}")

        interface_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(
            prefix=f".ip-save.{ip_name}.{reg_interface}.", dir=interface_root
        ) as tmp:
            staged = Path(tmp) / reg_interface
            if target.is_dir():
                shutil.copytree(target, staged, symlinks=True)
            else:
                staged.mkdir(parents=True)

            run = Path(synth_dir).parents[1]
            self._stage_sources(staged, run)
            self._stage_dv_evidence(staged, run, top)
            self._stage_synthesis(staged, pdk, synth_dir, top)
            self._stage_post_syn_signoff(staged, pdk, signoff_dir, sdc_file, top)
            self._stage_equivalence(
                staged, pdk, top, eqy_config, eqy_view, filelists,
                netlist, liberty, cell_models, clock_gate_model,
            )
            packaged_impl = staged / "impl" / pdk
            if impl_dir and Path(impl_dir).is_dir():
                self._stage_implementation(staged, pdk, Path(impl_dir), top)
                self._stage_physical_signoff(staged, pdk, Path(signoff_dir) / "post_impl", top)
            else:
                shutil.rmtree(packaged_impl, ignore_errors=True)
                impl_root = staged / "impl"
                if impl_root.is_dir() and not any(impl_root.iterdir()):
                    impl_root.rmdir()
                shutil.rmtree(staged / "signoff" / pdk / "post_impl", ignore_errors=True)
            self._stage_optional_reports(
                staged, pdk, post_syn_sim_dir, coverage_dir,
                manifest_json, metrics_json, run / "meta" / pdk / "provenance.json",
                settings_json, design_intent_json, qualification_json,
            )
            if spec_root is None:
                live_spec = run / "spec"
                frozen_spec = run / "contract"
                spec_root = live_spec if live_spec.is_dir() else frozen_spec
            spec_root = Path(spec_root)
            QualificationFlow.write_contract_snapshot(
                staged=staged, spec_root=spec_root, ip_name=ip_name,
                reg_interface=reg_interface, version=version,
            )
            staged_spec = Path(tmp) / "spec"
            staged_spec.mkdir()
            for name in SPEC_FILES:
                shutil.copy2(spec_root / name, staged_spec / name)
            PackageFlow._portable_filelists(staged, self.project_root, run)
            PackageFlow._clean_python_cache(staged)
            PackageFlow._clean_hidden_paths(staged)
            self._write_package_manifest(
                staged, ip_name, top, reg_interface, version=version
            )
            QualificationFlow.validate_release_package(staged, spec_root=staged_spec)

            backup = interface_root / f".{reg_interface}.backup"
            spec_target = release_root / "spec"
            spec_backup = release_root / ".spec.backup"
            for path in (backup, spec_backup):
                if path.exists():
                    shutil.rmtree(path)
            if target.exists():
                target.rename(backup)
            if spec_target.exists():
                spec_target.rename(spec_backup)
            try:
                staged.rename(target)
                staged_spec.rename(spec_target)
            except Exception:
                shutil.rmtree(target, ignore_errors=True)
                shutil.rmtree(spec_target, ignore_errors=True)
                if backup.exists():
                    backup.rename(target)
                if spec_backup.exists():
                    spec_backup.rename(spec_target)
                raise
            shutil.rmtree(backup, ignore_errors=True)
            shutil.rmtree(spec_backup, ignore_errors=True)
        return target

    @staticmethod
    def _replace_tree(source: Path, destination: Path) -> None:
        if destination.exists():
            shutil.rmtree(destination)
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(source, destination, symlinks=True)

    def _stage_sources(self, staged: Path, run: Path) -> None:
        """Copy reusable source/generated collateral and drop simulator runtime state."""

        for relative in (
            "csr", "rtl", "doc", "sw/drivers",
            "dv/formal/properties",
            "dv/functional/model", "dv/functional/tests", "dv/functional/tb",
        ):
            source = run / relative
            if source.is_dir():
                self._replace_tree(source, staged / relative)
        if (run / "component.xml").is_file():
            shutil.copy2(run / "component.xml", staged / "component.xml")

        tb = staged / "dv" / "functional" / "tb"
        if tb.is_dir():
            for name in ("sim_build", "obj_dir", "__pycache__"):
                for path in sorted(tb.rglob(name), key=lambda item: len(item.parts), reverse=True):
                    if path.is_dir():
                        shutil.rmtree(path, ignore_errors=True)
            for pattern in ("*.fst", "*.vcd", "*.vvp", "*.pyc", "*.pyo", "results.xml"):
                for path in tb.rglob(pattern):
                    if path.is_file():
                        path.unlink()

    def _stage_dv_evidence(self, staged: Path, run: Path, top: str) -> None:
        """Retain only machine-readable lint and CDC/RDC QoR below dv/."""

        shutil.rmtree(staged / "logs", ignore_errors=True)
        shutil.rmtree(staged / "analysis", ignore_errors=True)

        destination = staged / "dv" / "lint"
        shutil.rmtree(destination, ignore_errors=True)
        summary = Reporting.collect_lint(top, run)
        if summary:
            for values in summary.get("tools", {}).values():
                values.pop("command", None)
                values.pop("log", None)
            destination.mkdir(parents=True, exist_ok=True)
            (destination / "summary.json").write_text(
                json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
            )

        source = run / "dv" / "cdc_rdc" / "summary.json"
        destination = staged / "dv" / "cdc_rdc"
        shutil.rmtree(destination, ignore_errors=True)
        if source.is_file():
            destination.mkdir(parents=True, exist_ok=True)
            shutil.copy2(source, destination / "summary.json")

    def _write_package_manifest(
        self, staged: Path, ip_name: str, top: str, reg_interface: str,
        *, version: str | None = None,
    ) -> None:
        """Write the minimal native package index without duplicating design intent."""

        content = {}
        for key, relative in (
            ("registers", "csr"), ("rtl", "rtl"), ("documentation", "doc"),
            ("drivers", "sw/drivers"), ("functional_model", "dv/functional/model"),
            ("functional_tests", "dv/functional/tests"),
            ("functional_tb", "dv/functional/tb"),
            ("formal_properties", "dv/formal/properties"),
        ):
            if (staged / relative).is_dir():
                content[key] = relative

        sdc = staged / "constraints" / f"{top}.sdc"
        if sdc.is_file():
            content["timing_constraints"] = f"constraints/{top}.sdc"

        contract = staged / "meta" / "contract.json"
        if contract.is_file():
            content["contract"] = "meta/contract.json"
        if (staged / "component.xml").is_file():
            content["ipxact"] = "component.xml"
        if (staged / "csr" / "systemrdl").is_dir():
            content["systemrdl"] = "csr/systemrdl"
        qualification = {}
        meta = staged / "meta"
        if meta.is_dir():
            for branch in sorted(path for path in meta.iterdir() if path.is_dir()):
                evidence = {}
                for key, name in (
                    ("manifest", "manifest.json"), ("metrics", "metrics.json"),
                    ("provenance", "provenance.json"), ("settings", "settings.json"),
                    ("qualification", "qualification.json"),
                ):
                    if (branch / name).is_file():
                        evidence[key] = f"meta/{branch.name}/{name}"
                report_path = branch / "qualification.json"
                if report_path.is_file():
                    report = json.loads(report_path.read_text(encoding="utf-8"))
                    for key, default in (
                        ("maximum_level", 0),
                        ("maximum_qualification", "Not Qualified"),
                        ("maximum_pass_level", 0),
                        ("maximum_pass_qualification", "Not Qualified"),
                        ("qualification_status", "BLOCKED"),
                    ):
                        if key in report:
                            evidence[key] = report.get(key, default)
                if evidence:
                    qualification[branch.name] = evidence

        levels = [
            int(item.get("maximum_level", 0))
            for item in qualification.values()
            if isinstance(item, dict)
        ]
        contract_level = 1 if (staged / "meta" / "contract.json").is_file() else 0
        maximum = max([contract_level, *levels])
        summary = {
            "maximum_level": maximum,
            "maximum_qualification": QualificationFlow.qualification_name(maximum),
        }
        data = {
            "schema": 2,
            "format": "flexsoc-ip",
            "name": ip_name,
            "top": top,
            "reg_interface": reg_interface,
            "content": content,
            "qualification": {"summary": summary, "technologies": qualification},
        }
        if version:
            data["version"] = version
        (staged / "ip.json").write_text(
            json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8"
        )

    def _stage_synthesis(self, staged: Path, pdk: str, source: Path, top: str) -> None:
        """Retain synthesis setup plus the canonical stage outputs, not ORFS repair work."""

        source = Path(source)
        destination = staged / "syn" / pdk
        shutil.rmtree(destination, ignore_errors=True)
        destination.mkdir(parents=True, exist_ok=True)
        names = (*SYNTHESIS_RELEASE_FILES, f"{top}_synth.v", f"{top}_synth.json", f"{top}_synth_repair.json")
        for name in names:
            path = source / name
            if path.is_file():
                shutil.copy2(path, destination / name)
        for path in source.glob("*.abc"):
            shutil.copy2(path, destination / path.name)

    def _stage_equivalence(
        self,
        staged: Path,
        pdk: str,
        top: str,
        config: Path,
        view: Path,
        filelists: Sequence[Path],
        netlist: Path,
        liberty: Path,
        cell_models: Sequence[Path],
        clock_gate_model: Path,
    ) -> None:
        from flexsoc.backend.syn.eqy import Eqy

        output = staged / "signoff" / pdk / "post_syn" / "equivalence" / "rtl_vs_syn"
        Eqy.export_equivalence_profile(
            config=config,
            view=view,
            output_dir=output,
            filelists=filelists,
            netlist=netlist,
            liberty=liberty,
            cell_models=cell_models,
            clock_gate_model=clock_gate_model,
        )

    @staticmethod
    def _copy_signoff_evidence(source: Path, destination: Path, *, physical: bool = False) -> None:
        """Copy setup-owned collateral and compact QoR only."""

        source = Path(source)
        shutil.rmtree(destination, ignore_errors=True)
        destination.mkdir(parents=True, exist_ok=True)
        keep = SIGNOFF_RELEASE_FILES + (PHYSICAL_RELEASE_FILES if physical else ())
        for relative in keep:
            path = source / relative
            if not path.is_file():
                continue
            target = destination / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            if path.suffix == ".json":
                data = json.loads(path.read_text(encoding="utf-8"))
                target.write_text(
                    json.dumps(PackageFlow._portable_qor(data), indent=2, sort_keys=True) + "\n",
                    encoding="utf-8",
                )
            else:
                shutil.copy2(path, target)
    @classmethod
    def _stage_post_syn_signoff(
        cls, staged: Path, pdk: str, source: Path, sdc: Path, top: str
    ) -> None:
        """Save reusable post-synthesis signoff without scenario-local reports."""

        destination = staged / "signoff" / pdk / "post_syn"
        cls._copy_signoff_evidence(Path(source), destination)
        constraints = staged / "constraints"
        constraints.mkdir(parents=True, exist_ok=True)
        shutil.copy2(sdc, constraints / sdc.name)

        estimate = destination / "power" / "estimate" / "summary.json"
        if not estimate.is_file():
            run = Path(source).parents[1]
            summary = Reporting.collect_power_estimate(top, run, pdk)
            if summary:
                for values in summary.get("corners", {}).values():
                    values.pop("report", None)
                    values.pop("log", None)
                estimate.parent.mkdir(parents=True, exist_ok=True)
                estimate.write_text(
                    json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
                )

    @classmethod
    def _stage_physical_signoff(
        cls, staged: Path, pdk: str, source: Path, top: str
    ) -> None:
        """Package Level-5 signoff as setup-owned collateral plus canonical summaries."""

        destination = staged / "signoff" / pdk / "post_impl"
        if not Path(source).is_dir():
            shutil.rmtree(destination, ignore_errors=True)
            return
        cls._copy_signoff_evidence(Path(source), destination, physical=True)

        estimate = destination / "power" / "estimate" / "summary.json"
        if not estimate.is_file():
            run = Path(source).parents[2]
            summary = Reporting.collect_power_estimate(top, run, pdk, "post_route")
            if summary:
                for values in summary.get("corners", {}).values():
                    values.pop("report", None)
                    values.pop("log", None)
                estimate.parent.mkdir(parents=True, exist_ok=True)
                estimate.write_text(
                    json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
                )

    @staticmethod
    def _stage_implementation(staged: Path, pdk: str, source: Path, top: str) -> None:
        """Retain PnR setup plus only the five canonical final ORFS artifacts."""

        destination = staged / "impl" / pdk
        shutil.rmtree(destination, ignore_errors=True)
        destination.mkdir(parents=True, exist_ok=True)
        config = Path(source) / "config.mk"
        if config.is_file():
            shutil.copy2(config, destination / "config.mk")
        roots = sorted(path for path in (Path(source) / "results").glob(f"*/{top}/base") if path.is_dir())
        if len(roots) != 1:
            raise ValueError(f"expected one canonical ORFS result branch for {top}, found {len(roots)}")
        root = roots[0]
        target_root = destination / root.relative_to(source)
        target_root.mkdir(parents=True, exist_ok=True)
        for name in PNR_FINAL_FILES:
            path = root / name
            if not path.is_file():
                raise FileNotFoundError(f"missing canonical PnR artifact: {path}")
            shutil.copy2(path, target_root / name)

    @staticmethod
    def _stage_optional_reports(
        staged: Path,
        pdk: str,
        post_syn_sim_dir: Path | None,
        coverage_dir: Path | None,
        manifest_json: Path | None,
        metrics_json: Path | None,
        provenance_json: Path | None,
        settings_json: Path | None,
        design_intent_json: Path | None,
        qualification_json: Path | None,
    ) -> None:
        if post_syn_sim_dir and Path(post_syn_sim_dir).is_dir():
            reports = list(Path(post_syn_sim_dir).glob("summary*.json"))
            if reports:
                target = staged / "dv" / "functional" / "sim" / "post_syn" / pdk
                target.mkdir(parents=True, exist_ok=True)
                for report in reports:
                    data = json.loads(report.read_text(encoding="utf-8"))
                    (target / report.name).write_text(
                        json.dumps(PackageFlow._portable_qor(data), indent=2, sort_keys=True) + "\n",
                        encoding="utf-8",
                    )
        if coverage_dir:
            reports = [Path(coverage_dir) / "summary.json"]
            reports = [path for path in reports if path.is_file()]
            if reports:
                target = staged / "dv" / "functional" / "coverage"
                target.mkdir(parents=True, exist_ok=True)
                for report in reports:
                    shutil.copy2(report, target / report.name)
        if not any(
            path and Path(path).is_file()
            for path in (manifest_json, metrics_json, provenance_json, settings_json, design_intent_json, qualification_json)
        ):
            return
        common_meta = staged / "meta"
        if design_intent_json and Path(design_intent_json).is_file():
            common_meta.mkdir(parents=True, exist_ok=True)
            shutil.copy2(design_intent_json, common_meta / "design_intent.json")
        target = staged / "meta" / pdk
        target.mkdir(parents=True, exist_ok=True)
        if manifest_json and Path(manifest_json).is_file():
            shutil.copy2(manifest_json, target / "manifest.json")
        if metrics_json and Path(metrics_json).is_file():
            shutil.copy2(metrics_json, target / "metrics.json")
        if provenance_json and Path(provenance_json).is_file():
            shutil.copy2(provenance_json, target / "provenance.json")
        if settings_json and Path(settings_json).is_file():
            shutil.copy2(settings_json, target / "settings.json")
        if qualification_json and Path(qualification_json).is_file():
            shutil.copy2(qualification_json, target / "qualification.json")

    @staticmethod
    def _xe(parent: ET.Element, name: str, text: str | None = None, **attrs: str) -> ET.Element:
        element = ET.SubElement(parent, f"{{{IPXACT_NS}}}{name}", attrs)
        element.text = text
        return element

    @staticmethod
    def _ipxact_access(readable: bool, writable: bool) -> str:
        if readable and writable:
            return "read-write"
        if readable:
            return "read-only"
        if writable:
            return "write-only"
        return "no-access"

    @staticmethod
    def _ipxact_rtl_files(rtl_dir: Path) -> list[Path]:
        """Return deterministic run-local RTL sources from canonical filelists."""

        root = rtl_dir.resolve()
        files: set[Path] = set()
        for filelist in (rtl_dir / "rtl_common.f", rtl_dir / "rtl_ip.f"):
            if not filelist.is_file():
                continue
            for raw in filelist.read_text(encoding="utf-8").splitlines():
                value = raw.strip()
                if not value or value.startswith(("#", "+", "-")):
                    continue
                source = Path(value)
                if not source.is_absolute():
                    source = filelist.parent / source
                source = source.resolve()
                try:
                    source.relative_to(root)
                except ValueError:
                    continue
                if source.is_file():
                    files.add(source)
        if not files:
            files.update(path.resolve() for path in rtl_dir.glob("*.sv") if path.is_file())
        return sorted(files, key=lambda path: path.relative_to(root).as_posix())

    @staticmethod
    def _ipxact_port(parent: ET.Element, port: object) -> None:
        item = PackageFlow._xe(parent, "port")
        PackageFlow._xe(item, "name", str(port.name))
        wire = PackageFlow._xe(item, "wire")
        PackageFlow._xe(wire, "direction", {"input": "in", "output": "out"}[str(port.direction)])
        svtype = str(port.svtype).strip()
        vector = re.search(r"\[\s*([^:\]]+)\s*:\s*([^\]]+)\s*\]", svtype)
        if vector:
            vectors = PackageFlow._xe(wire, "vectors")
            entry = PackageFlow._xe(vectors, "vector")
            PackageFlow._xe(entry, "left", vector.group(1).strip())
            PackageFlow._xe(entry, "right", vector.group(2).strip())
        base = re.sub(r"\[[^\]]+\]", "", svtype).strip()
        if base and not base.startswith(("logic", "wire", "reg")):
            defs = PackageFlow._xe(wire, "wireTypeDefs")
            definition = PackageFlow._xe(defs, "wireTypeDef")
            PackageFlow._xe(definition, "typeName", base)
            PackageFlow._xe(definition, "viewRef", "rtl")

    @staticmethod
    def _copy_contents(source: Path, destination: Path) -> None:
        destination.mkdir(parents=True, exist_ok=True)
        for entry in source.iterdir():
            target = destination / entry.name
            if target.exists() or target.is_symlink():
                shutil.rmtree(target) if target.is_dir() and not target.is_symlink() else target.unlink()
            if entry.is_dir() and not entry.is_symlink():
                shutil.copytree(entry, target, symlinks=True)
            elif entry.is_symlink():
                target.symlink_to(entry.readlink())
            else:
                shutil.copy2(entry, target)

    @staticmethod
    def _package_interface(value: str) -> str:
        """Return the canonical external register-interface package key."""

        from flexsoc.backend.design.ip.regs import RegsFlow

        return RegsFlow.normalize_register_interface(value)

    @staticmethod
    def _validate_package_manifest(
        source: Path, *, ip_name: str, reg_interface: str, version: str | None = None
    ) -> None:
        """Reject packages whose identity does not match their interface path."""

        manifest = source / "ip.json"
        if not manifest.is_file():
            raise FileNotFoundError(f"missing FlexSoC IP manifest: {manifest}")
        data = json.loads(manifest.read_text(encoding="utf-8"))
        expected = {
            "format": "flexsoc-ip",
            "name": ip_name,
            "reg_interface": reg_interface,
        }
        if version is not None:
            expected["version"] = version
        mismatches = [
            f"{key}={data.get(key)!r} (expected {value!r})"
            for key, value in expected.items()
            if data.get(key) != value
        ]
        if mismatches:
            raise ValueError(
                f"invalid FlexSoC IP interface manifest {manifest}: " + ", ".join(mismatches)
            )

    @staticmethod
    def _clean_python_cache(root: Path) -> None:
        for path in list(root.rglob("__pycache__")):
            shutil.rmtree(path, ignore_errors=True)
        for pattern in ("*.pyc", "*.pyo"):
            for path in root.rglob(pattern):
                path.unlink(missing_ok=True)

    @staticmethod
    def _clean_hidden_paths(root: Path) -> None:
        """Remove dotfiles and dot-directories from a reusable package."""

        for path in sorted(root.rglob(".*"), key=lambda item: len(item.parts), reverse=True):
            if path.is_dir() and not path.is_symlink():
                shutil.rmtree(path, ignore_errors=True)
            else:
                path.unlink(missing_ok=True)

    @staticmethod
    def _portable_qor(value: object) -> object:
        """Drop runtime-only paths from a machine-readable release summary."""

        if isinstance(value, dict):
            return {
                key: PackageFlow._portable_qor(item)
                for key, item in value.items()
                if key not in _RUNTIME_QOR_KEYS
            }
        if isinstance(value, list):
            return [PackageFlow._portable_qor(item) for item in value]
        return value

    @staticmethod
    def _portable_filelists(root: Path, project_root: Path, run_root: Path) -> None:
        """Store operational filelists without checkout/workspace absolute paths."""

        run_rtl = (run_root / "rtl").resolve()
        project = project_root.resolve()
        for filelist in (root / "rtl" / "rtl_common.f", root / "rtl" / "rtl_ip.f"):
            if not filelist.is_file():
                continue
            lines = []
            for line in filelist.read_text(encoding="utf-8").splitlines():
                prefix, value = ("+incdir+", line[8:]) if line.startswith("+incdir+") else ("", line)
                if not value or value.startswith(("#", "+")):
                    lines.append(line)
                    continue
                path = Path(value)
                try:
                    value = (Path("rtl") / path.resolve().relative_to(run_rtl)).as_posix()
                except ValueError:
                    try:
                        value = path.resolve().relative_to(project).as_posix()
                    except ValueError:
                        pass
                lines.append(prefix + value)
            filelist.write_text("\n".join(lines) + "\n", encoding="utf-8")

    @staticmethod
    def _rebind_filelists(destination: Path, project_root: Path) -> None:
        """Bind copied saved-IP filelists to the current checkout and run."""

        rtl = destination / "rtl"
        for filelist in (rtl / "rtl_common.f", rtl / "rtl_ip.f"):
            if not filelist.is_file():
                continue
            local = filelist.name == "rtl_ip.f"
            lines = []
            for line in filelist.read_text(encoding="utf-8").splitlines():
                prefix, value = ("+incdir+", line[8:]) if line.startswith("+incdir+") else ("", line)
                if not value or value.startswith(("#", "+")):
                    lines.append(line)
                    continue
                normalized = value.replace("\\", "/")
                rebound = None
                if local:
                    if prefix:
                        rebound = rtl
                    else:
                        matches = [path for path in rtl.rglob(Path(value).name) if path.is_file()]
                        if len(matches) == 1:
                            rebound = matches[0]
                else:
                    relative = normalized.removeprefix("./")
                    for prefix_path in ("hw/ips/", "vendor/"):
                        if relative.startswith(prefix_path):
                            rebound = project_root / relative
                            break
                    if rebound is None:
                        for marker, base in (
                            ("/hw/ips/", project_root / "hw" / "ips"),
                            ("/vendor/", project_root / "vendor"),
                        ):
                            if marker in normalized:
                                rebound = base / normalized.split(marker, 1)[1]
                                break
                lines.append(prefix + (rebound.resolve().as_posix() if rebound else value))
            filelist.write_text("\n".join(lines) + "\n", encoding="utf-8")
