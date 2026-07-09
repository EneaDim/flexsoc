<p align="center">
<img src="assets/open-IP-SoC-logo.png" alt="FlexSoC logo" width="300"/>
</p>

# FlexSoC

FlexSoC is a Python package for IP development and SoC integration. The public
surface is intentionally small: callers use the `FlexSoC` API layer or the thin
`fx` CLI, and both route into the canonical backend Makefile.

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
make install
make test
```

The developer Makefile is `uv`-first. For direct `uv` usage:

```bash
uv venv --allow-existing
uv pip install -e ".[dev]"
uv run pytest -q
```

## Quickstart

List the compact public CLI surface and inspect a target:

```bash
fx commands
fx hjson --info
```

Persist project defaults once:

```bash
fx settings --set TOP=demo --set HOST=uart --set RUN_ID=smoke
```

Preview a workspace/generator path without running tools:

```bash
fx setup hjson reg doc --dry-run --script
```

Run the safe setup path and capture output:

```bash
fx setup --capture
```

Preview an explicit IP development path:

```bash
fx setup hjson reg doc rtl_stub setup_tb sim syn sta power pnr sim_syn cocotb --dry-run --script
```

Preview an explicit SoC development path:

```bash
fx setup soc_start soc_flow soc_prepare soc_build_sw soc_sim soc_run --dry-run --script --set TOP=soc
```

## Public Python API

```python
from flexsoc import FlexSoC

fx = FlexSoC(project_root=".", top="demo", run_id="smoke")
plan = fx.inspect_workflow("ip_development")
print(plan.shell_script())
```

Run a single backend target through the same API boundary:

```python
result = fx.run_step("hjson", capture=True)
print(result.ok, result.returncode)
```

## Common explicit flows

| Flow | Ordered backend targets |
| --- | --- |
| Workspace setup | `setup` |
| IP development | `setup hjson reg doc rtl_stub setup_tb sim syn sta power pnr sim_syn cocotb` |
| SoC development | `setup soc_start soc_flow soc_prepare soc_build_sw soc_sim soc_run` |
| Existing IP load | `setup ip_load flist setup_tb sim` |

EDA-dependent targets such as `sim`, `syn`, `sta`, `power`, `pnr`, `sim_syn`,
and `cocotb` require the corresponding tools and environment to be installed.
Use `--dry-run --script` first when validating wiring.

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
make lint
make test
fx smoke
fx smoke --json
```

`fx smoke` previews safe framework paths. It does not launch synthesis, signoff,
PnR, or simulation tools unless you explicitly run those backend targets.
