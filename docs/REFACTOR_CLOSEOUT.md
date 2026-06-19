# FlexSoC Refactor Closeout Plan

This document tracks the final steps needed to close the current API/backend/CLI
refactor without losing the ordering decisions made during development.

## Completed direction

The project now follows this structure:

```text
src/flexsoc/
  __init__.py
  __main__.py
  api.py
  cli.py
  backend/
    Makefile
    *.py
```

The public boundary is:

```python
from flexsoc import FlexSoC
```

The CLI is thin and calls the API layer. The API prepares or runs backend
commands through the canonical backend Makefile.

## Remaining implementation checks

1. Confirm that every backend Make target has an API `FlowStep` entry.
2. Confirm that every public workflow is documented and has a dry-run test.
3. Confirm that every backend Python module starts with a short module docstring.
4. Confirm that refactored backend modules expose config objects and small helper functions.
5. Confirm that no new names exist only for backward compatibility.
6. Confirm that root docs are moved under `docs/`, except `README.md`.
7. Confirm that `uv.lock` remains ignored until lockfile policy is finalized.

## Remaining documentation checks

1. `README.md` should describe the new minimal architecture.
2. `docs/API.md` should describe the stable API objects and examples.
3. `docs/CLI.md` should describe `fx help`, workflows, steps, and step-info.
4. `docs/FLOW_SMOKE.md` should remain the operational smoke-test guide.
5. `docs/BACKEND_MAP.md` should remain the backend ownership map.

## Final smoke sequence

Run these before considering the branch ready for review:

```bash
uv run pytest -q
fx help
fx workflows
fx steps
fx step-info setup
fx step-info syn --examples
fx workflow ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
fx workflow prepare --set TOP=demo --set RUN_ID=smoke --capture
```

Only after these pass should EDA-dependent steps be tested.
