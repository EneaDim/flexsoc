<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="FlexSoC logo" width="280"/>
</p>

# FlexSoC

**FlexSoC** is a Python package for digital IP development and SoC integration.
It keeps one public API boundary, one thin CLI, and one canonical backend flow.

```text
CLI / future web / future frontend
        ↓
from flexsoc import FlexSoC
        ↓
src/flexsoc/backend/Makefile
        ↓
src/flexsoc/backend/*.py
```

The project is currently in active refactor mode. The goal is to preserve the
core hardware-generation features while making the package smaller, clearer, and
easier to drive from Python, a command line, or a future service layer.

## Quickstart

Install the package in an active Python environment:

```bash
python -m pip install -e ".[dev]"
```

Discover the public CLI surface:

```bash
fx help
fx workflows
fx steps
fx step-info setup
```

Preview an IP-development workflow without running tools:

```bash
fx workflow ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Preview a SoC-development workflow without running tools:

```bash
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

Run the safe setup workflow:

```bash
fx workflow prepare --set TOP=demo --set RUN_ID=smoke --capture
```

## Python API

The API layer is the stable boundary for CLI, future web services, and future
frontends.

```python
from flexsoc import FlexSoC

fx = FlexSoC(top="demo")
print(fx.workflow_names())
print(fx.step_info("syn").to_dict())

plan = fx.inspect_workflow("ip_development", run_id="smoke")
print(plan.shell_script())
```

The CLI and any future frontend should call this API layer instead of importing
backend modules directly.

## CLI model

`fx` is intentionally thin. It exposes discovery, inspection, dry-runs, and
execution while delegating all real work to the API layer.

Useful commands:

```bash
fx help
fx workflows
fx steps
fx step-info syn
fx step-info syn --examples
fx step-info syn --json
fx step setup --dry-run --set TOP=demo
fx workflow ip_development --dry-run --script --set TOP=demo
```

## Canonical IP flow

The explicit IP-development workflow is:

```text
setup → hjson_gen → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb
```

Use `fx step-info NAME` to inspect accepted parameters for a specific step.
Common variables include `TOP`, `RUN_ID`, `WORKSPACE`, `HOST`, and tool-specific
values described per step.

## Canonical SoC flow

The explicit SoC-development workflow is:

```text
setup → soc_start → soc_flow → soc_prepare → soc_build_sw → soc_sim → soc_run
```

The SoC flow is also Make-backed and routed through the same API boundary.

## Repository layout

```text
.
├── README.md
├── docs/
│   ├── API.md
│   ├── CLI.md
│   ├── ARCHITECTURE.md
│   ├── BACKEND_MAP.md
│   ├── FLOW_SMOKE.md
│   ├── REFACTOR_CLOSEOUT.md
│   └── SPEC_REFACTOR.md
├── flow/
│   └── Makefile              # thin wrapper to the backend Makefile
├── src/flexsoc/
│   ├── __init__.py
│   ├── __main__.py
│   ├── api.py                # public Python API layer
│   ├── cli.py                # thin CLI over the API layer
│   └── backend/
│       ├── Makefile          # canonical flow entrypoint
│       ├── fsm_gen/
│       └── *.py              # core backend generators and setup helpers
├── tests/
│   └── test_api.py
├── assets/
└── vendor/
```

## Documentation

Detailed docs live under `docs/`:

- `docs/API.md` documents the Python API layer.
- `docs/CLI.md` documents the `fx` CLI.
- `docs/BACKEND_MAP.md` maps backend modules and responsibilities.
- `docs/FLOW_SMOKE.md` gives safe flow checks and tool-dependent checks.
- `docs/REFACTOR_CLOSEOUT.md` tracks remaining closeout work.
- `docs/ARCHITECTURE.md` describes the target architecture.
- `docs/SPEC_REFACTOR.md` records the active refactor specification.

## Development checks

Run the test suite:

```bash
python -m pytest -q
```

Run import and CLI smoke checks:

```bash
python -m flexsoc --help
fx help
fx workflows
fx steps
```

## Design principles

- Keep the public surface small.
- Route every interface through `FlexSoC`.
- Keep backend modules functional and importable.
- Avoid compatibility shims while the package is in development.
- Prefer explicit parameters over hidden state.
- Keep generated artifacts in workspaces, not in the repository.
- Document each module, class, and function with short triple-quoted docstrings.
