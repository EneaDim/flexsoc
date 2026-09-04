"""Reusable IP package load/save contract."""

from __future__ import annotations

import contextlib
import io
import json
import os
import re
import shutil
import tempfile
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping, Sequence

from .reporting import Reporting


IPXACT_NS = "http://www.accellera.org/XMLSchema/IPXACT/1685-2022"
XSI_NS = "http://www.w3.org/2001/XMLSchema-instance"
ET.register_namespace("ipxact", IPXACT_NS)
ET.register_namespace("xsi", XSI_NS)


def _xe(parent: ET.Element, name: str, text: str | None = None, **attrs: str) -> ET.Element:
    element = ET.SubElement(parent, f"{{{IPXACT_NS}}}{name}", attrs)
    element.text = text
    return element


def _ipxact_access(readable: bool, writable: bool) -> str:
    if readable and writable:
        return "read-write"
    if readable:
        return "read-only"
    if writable:
        return "write-only"
    return "no-access"


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


def _ipxact_port(parent: ET.Element, port: object) -> None:
    item = _xe(parent, "port")
    _xe(item, "name", str(port.name))
    wire = _xe(item, "wire")
    _xe(wire, "direction", {"input": "in", "output": "out"}[str(port.direction)])
    svtype = str(port.svtype).strip()
    vector = re.search(r"\[\s*([^:\]]+)\s*:\s*([^\]]+)\s*\]", svtype)
    if vector:
        vectors = _xe(wire, "vectors")
        entry = _xe(vectors, "vector")
        _xe(entry, "left", vector.group(1).strip())
        _xe(entry, "right", vector.group(2).strip())
    base = re.sub(r"\[[^\]]+\]", "", svtype).strip()
    if base and not base.startswith(("logic", "wire", "reg")):
        defs = _xe(wire, "wireTypeDefs")
        definition = _xe(defs, "wireTypeDef")
        _xe(definition, "typeName", base)
        _xe(definition, "viewRef", "rtl")


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


def _clean_python_cache(root: Path) -> None:
    for path in list(root.rglob("__pycache__")):
        shutil.rmtree(path, ignore_errors=True)
    for pattern in ("*.pyc", "*.pyo"):
        for path in root.rglob(pattern):
            path.unlink(missing_ok=True)


def _clean_hidden_paths(root: Path) -> None:
    """Remove dotfiles and dot-directories from a reusable package."""

    for path in sorted(root.rglob(".*"), key=lambda item: len(item.parts), reverse=True):
        if path.is_dir() and not path.is_symlink():
            shutil.rmtree(path, ignore_errors=True)
        else:
            path.unlink(missing_ok=True)


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


@dataclass(slots=True)
class PackageFlow:
    """Load and atomically save reusable IP artifacts without Make indirection."""

    project_root: Path
    values: Mapping[str, str]

    def load(
        self,
        *,
        ip_name: str,
        run_top: str,
        run_id: str,
        workspace: Path,
        load_as: str | None = None,
    ) -> Path:
        """Load one packaged IP into a canonical run workspace."""

        source = self.project_root / "hw" / "ips" / ip_name
        if not source.is_dir():
            raise FileNotFoundError(f"missing source IP directory: {source}")
        run = Path(workspace) / "runs" / run_top / run_id
        destination = run if run_top == ip_name else run / "ips" / (load_as or ip_name)
        if destination.exists() and destination != run:
            shutil.rmtree(destination)
        _copy_contents(source, destination)
        _clean_python_cache(destination)
        _rebind_filelists(destination, self.project_root)
        return destination

    def export_ipxact(
        self,
        *,
        top: str,
        data_dir: Path,
        rtl_dir: Path,
        output: Path,
        vendor: str = "flexsoc",
        library: str = "ip",
        version: str = "1.0.0",
    ) -> Path:
        """Export deterministic IEEE 1685-2022 component metadata for one IP run."""

        from flexsoc.backend.design.regs import _collect
        from flexsoc.backend.design.rtl import parse_ports

        top_file = Path(rtl_dir) / f"{top}.sv"
        if not top_file.is_file():
            raise FileNotFoundError(f"missing generated top RTL: {top_file}")
        _, registers = _collect(top, Path(data_dir))
        output = Path(output)
        output.parent.mkdir(parents=True, exist_ok=True)

        root = ET.Element(
            f"{{{IPXACT_NS}}}component",
            {f"{{{XSI_NS}}}schemaLocation": f"{IPXACT_NS} {IPXACT_NS}/index.xsd"},
        )
        for name, value in (("vendor", vendor), ("library", library), ("name", top), ("version", version)):
            _xe(root, name, value)

        by_domain: dict[str, list[object]] = {}
        for register in registers:
            by_domain.setdefault(register.domain, []).append(register)
        memory_maps = _xe(root, "memoryMaps")
        for domain in sorted(by_domain):
            domain_regs = sorted(by_domain[domain], key=lambda reg: (reg.offset, reg.name))
            memory_map = _xe(memory_maps, "memoryMap")
            _xe(memory_map, "name", f"{domain}_register_map")
            block = _xe(memory_map, "addressBlock")
            _xe(block, "name", f"{domain}_registers")
            _xe(block, "baseAddress", "0")
            _xe(block, "range", str(max(4, max(reg.offset + 4 for reg in domain_regs))))
            _xe(block, "width", "32")
            policies = _xe(block, "accessPolicies")
            _xe(_xe(policies, "accessPolicy"), "access", "read-write")
            for register in domain_regs:
                reg = _xe(block, "register")
                _xe(reg, "name", register.name)
                _xe(reg, "addressOffset", str(register.offset))
                _xe(reg, "size", "32")
                access = _xe(reg, "accessPolicies")
                _xe(
                    _xe(access, "accessPolicy"),
                    "access",
                    _ipxact_access(register.readable, register.writable),
                )
                for field in register.fields:
                    field_xml = _xe(reg, "field")
                    _xe(field_xml, "name", field.name)
                    _xe(field_xml, "bitOffset", str(field.lsb))
                    _xe(field_xml, "bitWidth", str(field.msb - field.lsb + 1))
                    if field.reset is not None:
                        resets = _xe(field_xml, "resets")
                        reset = _xe(resets, "reset")
                        _xe(reset, "value", str(field.reset))
                        _xe(reset, "mask", str((1 << (field.msb - field.lsb + 1)) - 1))
                    policies = _xe(field_xml, "fieldAccessPolicies")
                    policy = _xe(policies, "fieldAccessPolicy")
                    _xe(policy, "access", _ipxact_access(field.readable, field.writable))
                    modified = {
                        "rw1c": "oneToClear", "r0w1c": "oneToClear",
                        "rw1s": "oneToSet", "rw0c": "zeroToClear",
                    }.get(field.swaccess)
                    if modified:
                        _xe(policy, "modifiedWriteValue", modified)
            _xe(memory_map, "addressUnitBits", "8")

        model = _xe(root, "model")
        views = _xe(model, "views")
        view = _xe(views, "view")
        _xe(view, "name", "rtl")
        _xe(view, "componentInstantiationRef", "rtl")
        instantiations = _xe(model, "instantiations")
        instantiation = _xe(instantiations, "componentInstantiation")
        _xe(instantiation, "name", "rtl")
        _xe(instantiation, "language", "SystemVerilog")
        _xe(instantiation, "moduleName", top)
        file_ref = _xe(instantiation, "fileSetRef")
        _xe(file_ref, "localName", "rtl")
        ports = _xe(model, "ports")
        for port in parse_ports(top_file):
            _ipxact_port(ports, port)

        file_sets = _xe(root, "fileSets")
        file_set = _xe(file_sets, "fileSet")
        _xe(file_set, "name", "rtl")
        for source in _ipxact_rtl_files(Path(rtl_dir)):
            file_xml = _xe(file_set, "file")
            _xe(file_xml, "name", os.path.relpath(source, output.parent).replace(os.sep, "/"))
            _xe(file_xml, "fileType", "systemVerilogSource")

        ET.indent(root, space="  ")
        ET.ElementTree(root).write(output, encoding="utf-8", xml_declaration=True)
        return output

    def save(
        self,
        *,
        ip_name: str,
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
        force: bool = False,
    ) -> Path:
        """Atomically update one PDK branch in the reusable IP library."""

        required = (synth_dir, signoff_dir, sdc_file, eqy_config, eqy_view, netlist, liberty)
        missing = [path for path in required if not Path(path).exists()]
        if missing:
            raise FileNotFoundError("required ip_save input not found: " + ", ".join(map(str, missing)))

        library_root = Path(library_root)
        target = library_root / ip_name
        conflicts = [target / "syn" / pdk, target / "signoff" / pdk]
        if impl_dir and Path(impl_dir).is_dir():
            conflicts.append(target / "impl" / pdk)
        existing = [path for path in conflicts if path.exists()]
        if existing and not force:
            names = ", ".join(str(path.relative_to(target)) for path in existing)
            raise FileExistsError(f"ip_save would overwrite existing package content: {names}")

        library_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix=f".ip-save.{ip_name}.", dir=library_root) as tmp:
            staged = Path(tmp) / ip_name
            if target.is_dir():
                shutil.copytree(target, staged, symlinks=True)
            else:
                staged.mkdir(parents=True)

            run = Path(synth_dir).parents[1]
            self._stage_sources(staged, run)
            self._stage_analysis_evidence(staged, run)
            self._stage_synthesis(staged, pdk, synth_dir, top)
            self._stage_signoff(staged, pdk, signoff_dir, sdc_file, top)
            self._stage_equivalence(
                staged, pdk, top, eqy_config, eqy_view, filelists,
                netlist, liberty, cell_models, clock_gate_model,
            )
            if impl_dir and Path(impl_dir).is_dir():
                self._replace_tree(Path(impl_dir), staged / "impl" / pdk)
            self._stage_optional_reports(
                staged, pdk, post_syn_sim_dir, coverage_dir,
                manifest_json, metrics_json, run / "meta" / pdk / "provenance.json",
                settings_json, design_intent_json,
            )
            _portable_filelists(staged, self.project_root, run)
            _clean_python_cache(staged)
            _clean_hidden_paths(staged)
            self._write_package_manifest(staged, ip_name, top)

            backup = library_root / f".{ip_name}.backup"
            if backup.exists():
                shutil.rmtree(backup)
            if target.exists():
                target.rename(backup)
            try:
                staged.rename(target)
            except Exception:
                if backup.exists() and not target.exists():
                    backup.rename(target)
                raise
            shutil.rmtree(backup, ignore_errors=True)
        return target

    @staticmethod
    def _replace_tree(source: Path, destination: Path) -> None:
        if destination.exists():
            shutil.rmtree(destination)
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(source, destination, symlinks=True)

    def _stage_sources(self, staged: Path, run: Path) -> None:
        """Copy reusable source and generated collateral from the current run."""

        for relative in (
            "data", "rtl", "doc", "drivers", "interchange/systemrdl",
            "dv/formal/properties",
            "dv/functional/model", "dv/functional/tests", "dv/functional/tb",
        ):
            source = run / relative
            if source.is_dir():
                self._replace_tree(source, staged / relative)
        if (run / "component.xml").is_file():
            shutil.copy2(run / "component.xml", staged / "component.xml")

    def _stage_analysis_evidence(self, staged: Path, run: Path) -> None:
        """Retain compact lint and CDC/RDC evidence under analysis/."""

        shutil.rmtree(staged / "logs", ignore_errors=True)

        lint = run / "logs" / "lint"
        destination = staged / "analysis" / "lint"
        shutil.rmtree(destination, ignore_errors=True)
        if lint.is_dir():
            destination.mkdir(parents=True, exist_ok=True)
            for source in sorted(lint.glob("*.log")):
                if source.is_file() and not source.name.startswith("."):
                    shutil.copy2(source, destination / source.name)

        cdc = run / "analysis" / "cdc_rdc"
        if cdc.is_dir():
            destination = staged / "analysis" / "cdc_rdc"
            destination.mkdir(parents=True, exist_ok=True)
            for name in ("summary.json", "cdc_rdc.rpt"):
                source = cdc / name
                if source.is_file():
                    shutil.copy2(source, destination / name)

    def _write_package_manifest(self, staged: Path, ip_name: str, top: str) -> None:
        """Write the minimal native package index without duplicating design intent."""

        content = {}
        for key, relative in (
            ("registers", "data"), ("rtl", "rtl"), ("documentation", "doc"),
            ("drivers", "drivers"), ("functional_model", "dv/functional/model"),
            ("functional_tests", "dv/functional/tests"),
            ("functional_tb", "dv/functional/tb"),
            ("formal_properties", "dv/formal/properties"),
        ):
            if (staged / relative).is_dir():
                content[key] = relative

        sdc = staged / "constraints" / f"{top}.sdc"
        if sdc.is_file():
            content["timing_constraints"] = f"constraints/{top}.sdc"

        design_intent = staged / "meta" / "design_intent.json"
        if design_intent.is_file():
            content["design_intent"] = "meta/design_intent.json"
        if (staged / "component.xml").is_file():
            content["ipxact"] = "component.xml"
        if (staged / "interchange" / "systemrdl").is_dir():
            content["systemrdl"] = "interchange/systemrdl"

        qualification = {}
        meta = staged / "meta"
        if meta.is_dir():
            for branch in sorted(path for path in meta.iterdir() if path.is_dir()):
                evidence = {}
                for key, name in (
                    ("manifest", "manifest.json"), ("metrics", "metrics.json"),
                    ("provenance", "provenance.json"), ("settings", "settings.json"),
                    ("check", "check.rpt"),
                ):
                    if (branch / name).is_file():
                        evidence[key] = f"meta/{branch.name}/{name}"
                if evidence:
                    qualification[branch.name] = evidence

        data = {
            "schema": 1,
            "format": "flexsoc-ip",
            "name": ip_name,
            "top": top,
            "content": content,
            "qualification": qualification,
        }
        (staged / "ip.json").write_text(
            json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8"
        )

    def _stage_synthesis(self, staged: Path, pdk: str, source: Path, top: str) -> None:
        destination = staged / "syn" / pdk
        self._replace_tree(Path(source), destination)
        for checkpoint in ("generic", "dffmap", "abc", "clean"):
            (destination / f"{top}_{checkpoint}.il").unlink(missing_ok=True)

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
        from flexsoc.backend.syn.eqy import export_equivalence_profile

        output = staged / "signoff" / pdk / "equivalence" / "rtl_vs_syn"
        export_equivalence_profile(
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
    def _stage_signoff(staged: Path, pdk: str, source: Path, sdc: Path, top: str) -> None:
        """Save canonical setup scripts plus final sign-off evidence.

        Scenario-local Tcl files are runtime copies of setup-owned collateral;
        they are useful inside a run but must not become reusable package state.
        """

        destination = staged / "signoff" / pdk
        if destination.exists():
            shutil.rmtree(destination)
        destination.mkdir(parents=True, exist_ok=True)
        constraints = staged / "constraints"
        constraints.mkdir(parents=True, exist_ok=True)
        shutil.copy2(sdc, constraints / sdc.name)
        canonical_tcl = {
            Path("sta/sta.tcl"),
            Path("sdf/write_sdf.tcl"),
            Path("power/estimate/power_estimate.tcl"),
            Path("power/analysis/power_analysis.tcl"),
            Path("fusion/fusion_analysis.tcl"),
        }
        for path in Path(source).rglob("*"):
            if not path.is_file() or path.name.startswith("."):
                continue
            relative = path.relative_to(source)
            if path.suffix == ".tcl" and relative not in canonical_tcl:
                continue
            if path.name == "timing.rpt" and len(relative.parts) >= 4 and relative.parts[0] == "sta":
                continue
            if path.suffix not in {".tcl", ".rpt", ".json", ".sdf"}:
                continue
            target = destination / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(path, target)

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
    ) -> None:
        if post_syn_sim_dir and Path(post_syn_sim_dir).is_dir():
            reports = list(Path(post_syn_sim_dir).glob("*.json"))
            if reports:
                target = staged / "dv" / "functional" / "sim" / "post_syn" / pdk
                target.mkdir(parents=True, exist_ok=True)
                for report in reports:
                    shutil.copy2(report, target / report.name)
        if coverage_dir:
            reports = [Path(coverage_dir) / name for name in ("summary.txt", "summary.json")]
            reports = [path for path in reports if path.is_file()]
            if reports:
                target = staged / "dv" / "functional" / "coverage"
                target.mkdir(parents=True, exist_ok=True)
                for report in reports:
                    shutil.copy2(report, target / report.name)
        if not any(
            path and Path(path).is_file()
            for path in (manifest_json, metrics_json, provenance_json, settings_json, design_intent_json)
        ):
            return
        if design_intent_json and Path(design_intent_json).is_file():
            common_meta = staged / "meta"
            common_meta.mkdir(parents=True, exist_ok=True)
            shutil.copy2(design_intent_json, common_meta / "design_intent.json")
        target = staged / "meta" / pdk
        target.mkdir(parents=True, exist_ok=True)
        if manifest_json and Path(manifest_json).is_file():
            shutil.copy2(manifest_json, target / "manifest.json")
        if metrics_json and Path(metrics_json).is_file():
            metrics = target / "metrics.json"
            shutil.copy2(metrics_json, metrics)
            buffer = io.StringIO()
            with contextlib.redirect_stdout(buffer):
                Reporting().check(metrics)
            (target / "check.rpt").write_text(buffer.getvalue(), encoding="utf-8")
        if provenance_json and Path(provenance_json).is_file():
            shutil.copy2(provenance_json, target / "provenance.json")
        if settings_json and Path(settings_json).is_file():
            shutil.copy2(settings_json, target / "settings.json")
