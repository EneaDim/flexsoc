"""Reusable IP package load/save contract."""

from __future__ import annotations

import contextlib
import io
import json
import shutil
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping, Sequence

from .reporting import Reporting


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
            "data", "rtl", "doc", "drivers",
            "dv/formal/properties",
            "dv/functional/model", "dv/functional/tests", "dv/functional/tb",
        ):
            source = run / relative
            if source.is_dir():
                self._replace_tree(source, staged / relative)

    def _stage_analysis_evidence(self, staged: Path, run: Path) -> None:
        """Retain normalized lint and CDC/RDC evidence at run-relative paths."""

        lint = run / "logs" / "lint"
        if lint.is_dir():
            destination = staged / "logs" / "lint"
            destination.mkdir(parents=True, exist_ok=True)
            for source in sorted(lint.glob("*.log")):
                if source.is_file() and not source.name.startswith("."):
                    shutil.copy2(source, destination / source.name)

        cdc = run / "analysis" / "cdc_rdc"
        if cdc.is_dir():
            destination = staged / "analysis" / "cdc_rdc"
            destination.mkdir(parents=True, exist_ok=True)
            for name in (
                "summary.json", "cdc.json", "rdc.json", "setup.json",
                "glitch.json", "obligations.json",
            ):
                source = cdc / name
                if source.is_file():
                    shutil.copy2(source, destination / name)

        cdc_log = run / "logs" / "analysis" / "cdc_rdc" / "cdc_rdc.log"
        if cdc_log.is_file():
            destination = staged / "logs" / "analysis" / "cdc_rdc"
            destination.mkdir(parents=True, exist_ok=True)
            shutil.copy2(cdc_log, destination / "cdc_rdc.log")

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

        if (staged / "constraints" / "design.sdc").is_file():
            content["timing_constraints"] = "constraints/design.sdc"

        design_intent = staged / "meta" / "design_intent.json"
        if design_intent.is_file():
            content["design_intent"] = "meta/design_intent.json"

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
        shutil.copy2(sdc, constraints / "design.sdc")
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
                Reporting().show_metrics(metrics)
            (target / "check.rpt").write_text(buffer.getvalue(), encoding="utf-8")
        if provenance_json and Path(provenance_json).is_file():
            shutil.copy2(provenance_json, target / "provenance.json")
        if settings_json and Path(settings_json).is_file():
            shutil.copy2(settings_json, target / "settings.json")
