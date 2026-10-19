"""Auditable engineering deferral annotations; not qualification overrides."""
from __future__ import annotations

import json
from pathlib import Path
from typing import Mapping, Sequence


def manage_deferrals(meta: Path, args: Sequence[str], settings: Mapping[str, str], *, as_json: bool = False) -> int:
    """List/add/remove engineering notes bound to the run contract fingerprint."""
    if not args or args[0] not in {"list", "add", "remove"}:
        raise ValueError("usage: fx defer list | add STAGE REASON --set OWNER=... --set RESOLVE_BY=... | remove STAGE")
    path = meta / "qualification_deferrals.json"
    data = json.loads(path.read_text(encoding="utf-8")) if path.is_file() else {"schema": 1, "deferrals": []}
    if data.get("schema") != 1 or not isinstance(data.get("deferrals"), list):
        raise ValueError("invalid deferral file")
    notes = data["deferrals"]
    command = args[0]
    if command == "list":
        if len(args) != 1:
            raise ValueError("usage: fx defer list")
        if as_json:
            print(json.dumps(data, indent=2, ensure_ascii=False))
        else:
            for note in notes:
                print(f"{note['stage']}: owner={note['owner']} resolve_by={note['resolve_by']}\n  {note['reason']}")
            if not notes:
                print("No engineering deferrals")
        return 0
    if command == "add":
        if len(args) != 3:
            raise ValueError("usage: fx defer add STAGE 'REASON' --set OWNER=... --set RESOLVE_BY=...")
        _, stage, reason = args
        owner, resolve_by = settings.get("OWNER", "").strip(), settings.get("RESOLVE_BY", "").strip()
        if not all((stage.strip(), reason.strip(), owner, resolve_by)):
            raise ValueError("stage, reason, OWNER and RESOLVE_BY must be nonempty")
        report_path = meta / "qualification.json"
        if not report_path.is_file():
            raise ValueError("run `fx qualify` first to generate qualification.json")
        report = json.loads(report_path.read_text(encoding="utf-8"))
        fingerprint = report.get("contract_fingerprint")
        if not isinstance(fingerprint, str) or not fingerprint:
            raise ValueError("qualification report lacks contract fingerprint")
        evidence = report.get("evidence", {})
        if stage not in evidence:
            raise ValueError(f"unknown stage: {stage}")
        if evidence[stage] == "PASS":
            raise ValueError(f"stage already PASS: {stage}")
        if any(n.get("stage") == stage for n in notes):
            raise ValueError(f"stage already has a deferral: {stage}")
        notes.append({"stage": stage, "reason": reason, "owner": owner,
                      "resolve_by": resolve_by, "fingerprint": fingerprint})
    else:
        if len(args) != 2:
            raise ValueError("usage: fx defer remove STAGE")
        stage = args[1]
        if not any(n.get("stage") == stage for n in notes):
            raise ValueError(f"no deferral for: {stage}")
        data["deferrals"] = [n for n in notes if n.get("stage") != stage]
    meta.mkdir(parents=True, exist_ok=True)
    # Avoid following an attacker-supplied symlink out of the run.
    if path.is_symlink():
        raise ValueError("refusing to write symlink deferral file")
    temporary = path.with_suffix(".json.tmp")
    if temporary.exists() or temporary.is_symlink():
        raise ValueError("temporary deferral file already exists")
    temporary.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    temporary.replace(path)
    print(f"Updated {path}; qualification evidence unchanged. Re-run fx qualify.")
    return 0
