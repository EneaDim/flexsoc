<p align="center">
<img src="assets/open-IP-SoC-logo.png" alt="FlexSoC logo" width="300"/>
</p>

# FlexSoC

FlexSoC is a Python package for IP development and SoC integration.  The
public surface is intentionally small: callers use the `FlexSoC` API layer or
the thin `fx` CLI, and both route into the canonical backend Makefile.

```text
CLI / Python / future UI
        ↓
FlexSoC API layer
        ↓
src/flexsoc/backend/Makefile
        ↓
src/flexsoc/backend/*.py and external EDA tools
```

## Install for development

```bash
uv sync
uv run pytest -q
```

For local interactive use you can also install the package in editable mode.

```bash
uv run python -m pip install -e .
```

## Quickstart

List public workflows and advanced steps:

```bash
fx workflows
fx steps
fx step-info hjson_gen
```

Preview the workspace initialization path without running tools:

```bash
fx workflow workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Create the workspace and common run folders:

```bash
fx workflow workspace --set TOP=demo --set RUN_ID=smoke --capture
```

Preview the full IP development flow:

```bash
fx workflow ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Preview the SoC development flow:

```bash
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

## Public Python API

```python
from flexsoc import FlexSoC

fx = FlexSoC(project_root=".", top="demo", run_id="smoke")
plan = fx.inspect_workflow("ip_development")
print(plan.shell_script())
```

Run a single step through the same API boundary:

```python
result = fx.run_step("hjson_gen", capture=True)
print(result.ok, result.returncode)
```

## Public workflows

| Workflow | Purpose |
| --- | --- |
| `workspace` | Create the workspace and common run folders. |
| `ip_development` | Run the explicit IP development sequence. |
| `soc_development` | Run the explicit SoC development sequence. |
| `soc` | Generate or refresh the SoC project. |
| `fsm` | Run the bundled FSM generator utility. |

The IP development sequence is explicit:

```text
setup → hjson_gen → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb
```

The SoC development sequence is explicit:

```text
setup → soc_start → soc_flow → soc_prepare → soc_build_sw → soc_sim → soc_run
```

## Project layout

```text
src/flexsoc/
├── __init__.py
├── __main__.py
├── api.py
├── cli.py
└── backend/
    ├── Makefile
    ├── fsm_gen/
    └── *.py
```

Long-form framework documentation lives under `docs/`:

- `docs/API.md` for the Python API layer.
- `docs/CLI.md` for the `fx` CLI.
- `docs/ARCHITECTURE.md` for the framework architecture.
- `docs/FLOW_SMOKE.md` for safe smoke and flow validation commands.

## Development checks

```bash
uv run pytest -q
fx smoke
fx smoke --json
```

`fx smoke` previews safe framework workflows. It does not launch synthesis,
signoff, PnR, or simulation tools unless you explicitly run those steps.
