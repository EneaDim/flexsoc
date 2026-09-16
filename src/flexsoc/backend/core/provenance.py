"""Run-local provenance storage and lifecycle state derivation."""

from __future__ import annotations

import hashlib
import json
import os
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence


def _file_sha256(path: Path) -> str | None:
    if not path.is_file():
        return None
    return hashlib.sha256(path.read_bytes()).hexdigest()


def _path_sha256(path: Path) -> str | None:
    """Hash one file or directory tree without embedding its absolute path."""

    path = path.expanduser().absolute()
    if path.is_file():
        return _file_sha256(path)
    if not path.is_dir():
        return None
    digest = hashlib.sha256()
    for item in sorted(candidate for candidate in path.rglob("*") if candidate.is_file()):
        digest.update(item.relative_to(path).as_posix().encode())
        digest.update(bytes.fromhex(_file_sha256(item) or ""))
    return digest.hexdigest()


def _json_sha256(data: object) -> str:
    """Hash canonical JSON for deterministic configuration fingerprints."""

    payload = json.dumps(data, sort_keys=True, separators=(",", ":"), ensure_ascii=True)
    return hashlib.sha256(payload.encode()).hexdigest()


@dataclass(slots=True)
class Provenance:
    """Track generated collateral against effective inputs and validated overrides."""

    path: Path
    run_root: Path

    def _load(self) -> dict[str, Any]:
        if not self.path.is_file():
            return {"schema_version": 1, "stages": {}}
        try:
            data = json.loads(self.path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            raise ValueError(f"invalid provenance manifest {self.path}: {exc}") from exc
        if data.get("schema_version") != 1 or not isinstance(data.get("stages"), dict):
            raise ValueError(f"invalid provenance manifest: {self.path}")
        return data

    def _write(self, data: Mapping[str, Any]) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        temp = self.path.with_name(f".{self.path.name}.{os.getpid()}.tmp")
        temp.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        temp.replace(self.path)

    def _key(self, path: Path) -> str:
        resolved = path.expanduser().absolute()
        try:
            return resolved.relative_to(self.run_root.resolve()).as_posix()
        except ValueError:
            return str(resolved)

    def _resolve(self, key: str) -> Path:
        path = Path(key)
        return path if path.is_absolute() else self.run_root / path

    def _snapshot(self, paths: Sequence[Path]) -> list[dict[str, str | None]]:
        return [{"path": self._key(path), "sha256": _path_sha256(path)} for path in paths]

    @staticmethod
    def _fingerprint(record: Mapping[str, Any]) -> str:
        payload: dict[str, Any] = {
            "config": record.get("config", {}),
            "parents": record.get("parents", {}),
            "inputs": [item.get("sha256") for item in record.get("inputs", ())],
            "input_paths_match": record.get("input_paths_match", True),
            "generated": [
                (item.get("path"), item.get("effective_sha256"))
                for item in record.get("generated", ())
            ],
        }
        payload["tools"] = record.get("tools", {})
        return _json_sha256(payload)

    def current_fingerprint(
        self, stage: str, *, inputs: Sequence[Path], config: Mapping[str, object],
        parents: Mapping[str, str | None] | None = None,
        tools: Mapping[str, object] | None = None,
    ) -> str | None:
        """Fingerprint the effective stage state, including unsaved upstream changes."""

        record = self._load()["stages"].get(stage)
        if not isinstance(record, dict):
            return None
        current_inputs = self._snapshot(inputs)
        current = {
            "config": dict(sorted(config.items())),
            "parents": dict(parents or {}),
            "inputs": current_inputs,
            "input_paths_match": [item.get("path") for item in record.get("inputs", ())]
            == [item["path"] for item in current_inputs],
            "generated": [
                {
                    "path": item.get("path"),
                    "effective_sha256": _path_sha256(
                        self._resolve(str(item.get("path", "")))
                    ),
                }
                for item in record.get("generated", ())
            ],
        }
        current["tools"] = dict(sorted((tools or {}).items()))
        return self._fingerprint(current)

    def record(
        self, stage: str, *, inputs: Sequence[Path], generated: Sequence[Path],
        config: Mapping[str, object], parents: Mapping[str, str | None] | None = None,
        tools: Mapping[str, object] | None = None, outcome: str | None = None,
        returncode: int | None = None, allow_missing: bool = False,
    ) -> str:
        """Record canonical stage lineage; runtime outcome is stored independently."""

        generated_state = self._snapshot(generated)
        missing = [item["path"] for item in generated_state if item["sha256"] is None]
        if missing and not allow_missing:
            raise FileNotFoundError(f"{stage}: generated artifact missing: {', '.join(missing)}")
        data = self._load()
        record: dict[str, Any] = {
            "config": dict(sorted(config.items())),
            "parents": dict(parents or {}),
            "tools": dict(sorted((tools or {}).items())),
            "inputs": self._snapshot(inputs),
            "input_paths_match": True,
            "generated": [
                {
                    "path": item["path"],
                    "generated_sha256": item["sha256"],
                    "effective_sha256": item["sha256"],
                }
                for item in generated_state
            ],
        }
        if outcome is not None:
            record["outcome"] = str(outcome).upper()
        if returncode is not None:
            record["returncode"] = int(returncode)
        record["fingerprint"] = self._fingerprint(record)
        data["stages"][stage] = record
        self._write(data)
        return str(record["fingerprint"])

    def generated(self, stage: str) -> tuple[Path, ...]:
        """Return generated artifacts recorded for one stage."""

        record = self._load()["stages"].get(stage)
        if not isinstance(record, dict):
            return ()
        return tuple(
            self._resolve(str(item["path"]))
            for item in record.get("generated", ())
            if isinstance(item, dict) and item.get("path")
        )

    def stages(self) -> tuple[str, ...]:
        """Return recorded stages in deterministic order."""

        return tuple(sorted(self._load()["stages"]))

    def outcome(self, stage: str) -> str | None:
        """Return the recorded runtime outcome, or None for setup/legacy records."""

        record = self._load()["stages"].get(stage)
        if not isinstance(record, dict) or record.get("outcome") is None:
            return None
        return str(record["outcome"]).upper()

    def state(
        self, stage: str, *, inputs: Sequence[Path], config: Mapping[str, object],
        parents: Mapping[str, str | None] | None = None,
        tools: Mapping[str, object] | None = None,
    ) -> str:
        """Derive the current stage state from disk; stored status is never trusted."""

        record = self._load()["stages"].get(stage)
        if not isinstance(record, dict):
            return "MISSING"
        generated = record.get("generated")
        if not isinstance(generated, list) or not generated:
            return "INVALID"
        current_inputs = self._snapshot(inputs)
        if (
            record.get("config") != dict(sorted(config.items()))
            or record.get("parents") != dict(parents or {})
            or record.get("tools") != dict(sorted((tools or {}).items()))
        ):
            return "STALE"
        if record.get("inputs") != current_inputs:
            return "INVALID" if any(item["sha256"] is None for item in current_inputs) else "STALE"

        overridden = False
        for item in generated:
            current = _path_sha256(self._resolve(str(item.get("path", ""))))
            if current is None:
                return "INVALID"
            canonical = item.get("generated_sha256")
            if current == canonical:
                continue
            if current != item.get("effective_sha256"):
                return "MODIFIED"
            overridden = True
        return "VALIDATED_OVERRIDE" if overridden else "CLEAN"

    def validate(
        self, stage: str, *, inputs: Sequence[Path], config: Mapping[str, object],
        parents: Mapping[str, str | None] | None = None,
        tools: Mapping[str, object] | None = None,
    ) -> str:
        """Accept only current generated-file edits; stale lineage remains rejected."""

        state = self.state(stage, inputs=inputs, config=config, parents=parents, tools=tools)
        if state != "MODIFIED":
            if state == "STALE":
                raise ValueError(
                    f"{stage}: provenance is STALE; source, configuration, or parent lineage changed. "
                    f"Rerun the corresponding `fx <keyword> --setup` phase with the intended effective settings; for a multi-command "
                    "flow persist them with `fx settings ...`. validate_override is only for manually "
                    "MODIFIED generated collateral."
                )
            if state == "MISSING":
                raise ValueError(
                    f"{stage}: provenance is MISSING; generate the corresponding setup before validating an override."
                )
            if state == "INVALID":
                raise ValueError(
                    f"{stage}: provenance is INVALID; required inputs, generated files, or provenance "
                    f"metadata are missing/inconsistent. Rerun the corresponding `fx <keyword> --setup` phase after repairing the inputs."
                )
            raise ValueError(
                f"{stage}: override cannot be validated from state {state}; "
                "validate_override only accepts MODIFIED generated collateral."
            )
        data = self._load()
        record = data["stages"][stage]
        for item in record["generated"]:
            item["effective_sha256"] = _path_sha256(self._resolve(item["path"]))
        record["fingerprint"] = self._fingerprint(record)
        self._write(data)
        return "VALIDATED_OVERRIDE"


def provenance_summary(states: Mapping[str, str]) -> dict[str, Any]:
    """Return deterministic setup states and the strongest provenance condition."""

    normalized = {stage: str(state).upper() for stage, state in sorted(states.items())}
    order = ("INVALID", "STALE", "MODIFIED", "MISSING", "VALIDATED_OVERRIDE", "CLEAN")
    overall = next((state for state in order if state in normalized.values()), "INVALID")
    return {"status": overall, "stages": normalized}


