"""Optional CRS/TDS and executable scenario traceability for Digital IP specs.

All matrices are derived views; requirements.yaml and testplan.yaml remain authoritative.
"""

from __future__ import annotations

import hashlib
import json
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Mapping

import yaml


@dataclass(frozen=True, slots=True)
class TraceabilityFlow:
    """Validate and invert the existing IP specification relationships."""

    root: Path

    @staticmethod
    def model_evidence(*, report: Mapping[str, object], summary: Path,
                       fingerprint: str, model_dir: Path, ip: str) -> dict[str, object]:
        """Join actual model results only when their source/spec fingerprints agree."""

        planned = report.get("model_cases_to_testplan", {})
        cases = {str(name): "NOT_RUN" for name in planned}
        result: dict[str, object] = {"status": "NOT_RUN", "cases": cases}
        if summary is None or not summary.is_file():
            return result
        try:
            data = json.loads(summary.read_text(encoding="utf-8"))
            inputs = data["inputs_sha256"]
            current = {
                name: hashlib.sha256((model_dir / name).read_bytes()).hexdigest()
                for name in (path.name for path in model_dir.glob("*.py") if path.is_file())
            }
            if (data.get("contract_fingerprint") != fingerprint or data.get("ip") != ip
                    or inputs != current):
                return {"status": "STALE", "cases": cases}
            if set(data.get("cases", {})) != set(cases):
                return {"status": "INVALID", "cases": cases}
            cases.update(data["cases"])
            return {"status": data["status"], "cases": cases,
                    "summary": str(summary), "log": data.get("log"), "junit": data.get("junit"),
                    "started_at_utc": data.get("started_at_utc"),
                    "finished_at_utc": data.get("finished_at_utc")}
        except (OSError, ValueError, KeyError, TypeError, json.JSONDecodeError):
            return {"status": "INVALID", "cases": cases}

    @staticmethod
    def rtl_evidence(*, report: Mapping[str, object], summary: Path | None, ip: str) -> dict[str, object]:
        """Display recorded RTL subrun results without asserting EDA provenance.

        The regression summary is an index; only qualification can validate the
        active RTL closure, run provenance, and other required evidence.
        """

        planned = report.get("tests_to_testplan", {})
        tests = {str(name): {} for name in planned}
        result: dict[str, object] = {
            "status": "NOT_RUN", "tests": tests, "summary": str(summary) if summary is not None else None,
            "provenance": "NOT_VERIFIED",
            "note": "Recorded RTL results are not proof of qualification or current RTL provenance.",
        }
        if summary is None or not summary.is_file():
            return result
        try:
            raw = json.loads(summary.read_text(encoding="utf-8"))
            if (raw.get("top") != ip or raw.get("status") not in {"PASS", "FAILED", "PARTIAL"}
                    or not isinstance(raw.get("matrix"), dict)
                    or not isinstance(raw.get("backends"), list)):
                return {**result, "status": "INVALID"}
            matrix = raw["matrix"]
            backends = raw["backends"]
            if not backends or len(backends) != len(set(backends)):
                return {**result, "status": "INVALID"}
            all_states = []
            for test in tests:
                recorded = matrix.get(test, {})
                for backend in backends:
                    entry = recorded.get(backend, {}) if isinstance(recorded, dict) else {}
                    state = entry.get("status", "NOT_RUN") if isinstance(entry, dict) else "NOT_RUN"
                    if state not in ("PASS", "FAILED", "NOT_RUN"):
                        state = "INVALID"
                    tests[test][backend] = {"reported": state, "log": entry.get("log") if isinstance(entry, dict) else None}
                    all_states.append(state)
            covered = all(
                any(tests[test][backend]["reported"] == "PASS" for backend in backends)
                for test in tests
            )
            status = ("INVALID" if "INVALID" in all_states else
                      "FAILED" if raw["status"] == "FAILED" or "FAILED" in all_states else
                      "RECORDED_PASS" if covered and tests and raw["status"] == "PASS" else "PARTIAL")
            return {**result, "status": status, "backends": backends, "tests": tests}
        except (OSError, ValueError, TypeError, KeyError):
            return {**result, "status": "INVALID"}

    @staticmethod
    def execution_matrix(*, report: Mapping[str, object], model: Mapping[str, object],
                         rtl: Mapping[str, object]) -> dict[str, object]:
        """Join testplan IDs to independently recorded model and RTL outcomes."""

        matrix = {}
        model_cases = model.get("cases", {})
        rtl_tests = rtl.get("tests", {})
        for plan, links in report.get("testplan_to_tests", {}).items():
            matrix[plan] = {
                "model": {case: model_cases.get(case, "NOT_RUN") for case in links["model"]},
                "rtl": {test: rtl_tests.get(test, {}) for test in links["rtl"]},
                "properties": list(links["properties"]),
            }
        return matrix

    @staticmethod
    def _ids(path: Path, prefix: str) -> list[str]:
        pattern = re.compile(r"^#{2,4}\s+(" + re.escape(prefix) + r"-\d{3})\b", re.M)
        identifiers = pattern.findall(path.read_text(encoding="utf-8"))
        if len(identifiers) != len(set(identifiers)):
            raise ValueError(f"{path}: duplicate {prefix} heading")
        return identifiers

    @staticmethod
    def _strings(value: object, where: str) -> list[str]:
        if (
            not isinstance(value, list) or not value
            or any(not isinstance(x, str) or not x.strip() for x in value)
        ):
            raise ValueError(f"{where}: expected non-empty list of identifiers")
        if len(value) != len(set(value)):
            raise ValueError(f"{where}: duplicate identifiers")
        return value

    def validate(self, requirements: Mapping[str, object] | None = None,
                 testplan: Mapping[str, object] | None = None) -> dict[str, object]:
        root = Path(self.root)
        customer = root / "customer.md"
        if not customer.is_file():
            return {
                "status": "NOT_CONFIGURED", "customer_to_technical": {},
                "technical_to_customer": {}, "technical_to_requirements": {},
                "requirements_to_testplan": {}, "testplan_to_tests": {},
                "tests_to_testplan": {}, "model_cases_to_testplan": {},
            }
        if requirements is None:
            requirements = yaml.safe_load((root / "requirements.yaml").read_text(encoding="utf-8"))
        if testplan is None:
            testplan = yaml.safe_load((root / "testplan.yaml").read_text(encoding="utf-8"))
        if not isinstance(requirements, Mapping) or not isinstance(testplan, Mapping):
            raise ValueError("requirements and testplan must be mappings")
        crs_ids = self._ids(customer, "CRS")
        tds_ids = self._ids(root / "ip.md", "TDS")
        if not crs_ids or not tds_ids:
            raise ValueError("customer.md must have CRS headings and ip.md must have TDS headings")
        crs_to_tds: dict[str, list[str]] = {k: [] for k in crs_ids}
        tds_to_crs: dict[str, list[str]] = {}
        content = (root / "ip.md").read_text(encoding="utf-8")
        headings = list(re.finditer(r"^#{2,4}\s+(TDS-\d{3})\b[^\n]*", content, re.M))
        for index, heading in enumerate(headings):
            next_start = headings[index + 1].start() if index + 1 < len(headings) else len(content)
            section = content[heading.end():next_start]
            match = re.search(r"^Customer refs:\s*(.+)$", section, re.M)
            if not match:
                raise ValueError(f"{heading.group(1)}: missing Customer refs")
            refs = [value.strip() for value in match.group(1).split(",")]
            refs = self._strings(refs, heading.group(1))
            for ref in refs:
                if ref not in crs_to_tds:
                    raise ValueError(f"{heading.group(1)}: unknown customer reference {ref}")
                crs_to_tds[ref].append(heading.group(1))
            tds_to_crs[heading.group(1)] = refs
        req_to_tds: dict[str, list[str]] = {}
        tds_to_req: dict[str, list[str]] = {key: [] for key in tds_ids}
        req_to_tp: dict[str, list[str]] = {}
        for entry in requirements.get("requirements", []):
            if not isinstance(entry, Mapping):
                raise ValueError("requirement must be a mapping")
            req_id = str(entry.get("id", ""))
            refs = self._strings(entry.get("spec_refs"), f"{req_id}.spec_refs")
            if entry.get("category") not in ("architectural", "technical"):
                raise ValueError(f"{req_id}: category must be architectural or technical")
            for ref in refs:
                if ref not in tds_to_req:
                    raise ValueError(f"{req_id}: unknown technical reference {ref}")
                tds_to_req[ref].append(req_id)
            req_to_tds[req_id] = refs
            req_to_tp[req_id] = []
        tp_to_tests: dict[str, dict[str, list[str]]] = {}
        test_to_tp: dict[str, list[str]] = {}
        model_to_tp: dict[str, list[str]] = {}
        for entry in testplan.get("items", []):
            if not isinstance(entry, Mapping):
                raise ValueError("testplan item must be a mapping")
            tp = str(entry.get("id", ""))
            refs = self._strings(entry.get("requirements"), f"{tp}.requirements")
            tests = entry.get("tests", []) or []
            models = entry.get("model_cases", []) or []
            if not isinstance(tests, list) or not isinstance(models, list):
                raise ValueError(f"{tp}: tests and model_cases must be lists")
            if any(not isinstance(x, str) or not x.strip() for x in (*tests, *models)):
                raise ValueError(f"{tp}: invalid test or model case")
            for ref in refs:
                if ref not in req_to_tp:
                    raise ValueError(f"{tp}: unknown requirement {ref}")
                req_to_tp[ref].append(tp)
            for test in tests:
                if tp not in test_to_tp.setdefault(test, []):
                    test_to_tp[test].append(tp)
            for case in models:
                if tp not in model_to_tp.setdefault(case, []):
                    model_to_tp[case].append(tp)
            tp_to_tests[tp] = {
                "rtl": list(tests), "model": list(models),
                "properties": list(entry.get("properties", []) or []),
            }
        if any(not links for links in crs_to_tds.values()):
            orphans = [key for key, links in crs_to_tds.items() if not links]
            raise ValueError("orphan customer requirement(s): " + ", ".join(orphans))
        if any(not links for links in tds_to_req.values()):
            orphans = [key for key, links in tds_to_req.items() if not links]
            raise ValueError("unallocated technical specification(s): " + ", ".join(orphans))
        if any(not links for links in req_to_tp.values()):
            orphans = [key for key, links in req_to_tp.items() if not links]
            raise ValueError("requirement(s) without testplan: " + ", ".join(orphans))
        return {
            "status": "MAPPED_NOT_EXECUTED", "customer_to_technical": crs_to_tds,
            "technical_to_customer": tds_to_crs, "technical_to_requirements": tds_to_req,
            "requirements_to_technical": req_to_tds, "requirements_to_testplan": req_to_tp,
            "testplan_to_tests": tp_to_tests, "tests_to_testplan": test_to_tp,
            "model_cases_to_testplan": model_to_tp,
            "summary": {"customers": len(crs_ids), "technical": len(tds_ids),
                        "requirements": len(req_to_tds), "testplan": len(tp_to_tests),
                        "rtl_scenarios": len(test_to_tp), "model_cases": len(model_to_tp)},
        }
