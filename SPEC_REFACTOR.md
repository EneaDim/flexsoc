# FlexSoC Refactor Spec

## Goal

Refactor FlexSoC into a minimal Python package with a thin public API layer and a future CLI/web/frontend surface that calls only that API layer.

## Public package contract

```python
from flexsoc import FlexOC

fx = FlexOC(...)
```

The public API is centered on `FlexOC` in `src/flexsoc/api.py`. External users, future CLI commands, web services, and frontends must call this API instead of importing backend modules directly.

## Target layout

```text
src/flexsoc/
├── __init__.py
├── api.py
└── backend/
    ├── fsm_gen/
    └── <core modules moved from src/flexsoc/tools/>
```

## Core migration rules

- Move current `src/flexsoc/tools/*` into `src/flexsoc/backend/`.
- Move current `tools/fsm_gen/` into `src/flexsoc/backend/fsm_gen/`.
- Do not preserve backwards-compatible `flexsoc.tools.*` imports.
- Do not rewrite the core module logic in the first patch.
- Later patches will review backend files one by one.

## API philosophy

- Keep `FlexOC` thin.
- Prefer high-level workflows in the public API.
- Allow advanced EDA step calls where useful.
- Do not expose a large placeholder catalog of methods.
- Add only methods justified by the existing project workflow.

## Backend philosophy

- Prefer functional modules over class-heavy designs.
- Keep file count low.
- Minimize lines of code.
- Every new or modified Python file must have a short module docstring.
- Every new or modified class/function must have a concise docstring of one to three lines.

## Configuration philosophy

Support both a single config object and explicit keyword arguments when useful. Internally, converge toward one normalized configuration model.

## Build and test direction

- Keep `pyproject.toml`.
- Use modern Python build flow, not a pip-first project layout.
- Use `pytest`.
- Delete most existing tests and restart with a minimal `tests/test_api.py` smoke/API test.

## Keep for now

- `vendor/`
- `assets/`
- docs such as `README.md` and `ARCHITECTURE.md`
- root `Makefile`
- existing make-based flow references under `src/flexsoc/flow/`

## Cut aggressively

Remove orchestration/presentation/runtime/state/catalog infrastructure that is not part of the minimal API/backend package direction.

## Makefile direction

The existing Makefile/mk system is a valuable reference. Future direction:

```text
Makefile / CLI / Web / GUI
    ↓
FlexOC API layer
    ↓
backend modules
```

Make commands should eventually become thin wrappers around API calls. Step-level commands should support overriding parameters for the selected step.

## Current interview decisions

- Package name remains `flexsoc`.
- Public import is `from flexsoc import FlexOC`.
- Future CLI command name may be `fx`.
- API layer lives in `src/flexsoc/api.py`.
- Backend lives in `src/flexsoc/backend/`.
- No compatibility shim for old `flexsoc.tools` imports.
- Backend modules stay mostly functional.
- API supports both workflow-level and advanced step-level operations.

## Patch 0001 - structural cut

- Public import is `from flexsoc import FlexOC`.
- `src/flexsoc/api.py` owns the first thin API boundary.
- `src/flexsoc/tools/*` moved to `src/flexsoc/backend/*` with no compatibility shim.
- `tools/fsm_gen/*` moved to `src/flexsoc/backend/fsm_gen/*`.
- Old orchestration layers were removed from `src/flexsoc`.
- Tests were reset to a single public API smoke test.
- CLI is intentionally minimal and routes through the API layer.
