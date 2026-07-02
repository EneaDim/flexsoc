# FlexSoC architecture

FlexSoC is organized as a Python package with a small public API, a CLI frontend,
and a backend flow implementation.

```text
src/flexsoc/
├── __init__.py          # public package exports
├── api.py               # FlexSoC public API
├── cli.py               # fx command-line frontend
└── backend/             # implementation details and flow backends
    ├── Makefile         # canonical backend flow runner
    ├── setup_*.py       # Python generators for flow setup files
    └── ...
```

## Public boundary

External users should enter through one of these interfaces:

```python
from flexsoc import FlexSoC
```

```bash
fx help
fx commands
fx settings
fx steps
fx step hjson reg doc
```

The CLI calls the `FlexSoC` API. CLI commands should not call backend modules
directly. Backend modules remain implementation details and may change without
public compatibility guarantees.

## Backend flow runner

For now, step execution is intentionally Makefile-backed:

```text
fx step ...
  -> flexsoc.cli
  -> FlexSoC.run_step(...)
  -> src/flexsoc/backend/Makefile
  -> Python generators, vendor tools, and EDA tools
```

The canonical Makefile is:

```text
src/flexsoc/backend/Makefile
```

The retired top-level `flow/` directory is not part of the package flow anymore.
Do not add new flow logic there.

## Project settings

Project defaults are managed by:

```bash
fx settings
fx settings --set TOP=test --set HOST=uart --set RUN_ID=default
```

The local project state is stored under `.flexsoc/` and should not be committed.

Default settings are deterministic:

```text
TOP=test
HOST=uart
FORCE=0
RUN_ID=default
```

`RUN_ID` is static by default. It does not use timestamps automatically. Change it
only when you explicitly want a different run:

```bash
fx settings --set RUN_ID=smoke
fx step hjson reg doc
```

For one command only:

```bash
fx step syn sta --set RUN_ID=trial_01
```

## Step lifecycle

A typical IP flow is:

```bash
fx step hjson reg doc rtl_stub setup_tb sim
```

A longer physical-design-oriented flow is:

```bash
fx step hjson reg doc rtl_stub setup_tb sim syn sta power pnr
```

Cocotb setup uses the generated RTL filelist:

```bash
fx step hjson reg doc rtl_stub setup_cocotb cocotb
```

Regeneration uses the backend `FORCE` setting. The CLI exposes convenient aliases:

```bash
fx step hjson reg doc --force
fx step hjson reg doc --overwrite
```

Without `--force` or `--overwrite`, generators should refuse to overwrite files
and print a useful message explaining how to proceed.

## Discovery and help

Use CLI discovery before running flows:

```bash
fx commands
fx steps
fx workflows
fx step-info hjson
```

Shell completion can be installed with:

```bash
fx --install-completion bash
```

After reloading the shell, completion should work for commands, steps, and
workflows.

## Cleanup

`clean_all` should be safe and idempotent. It is intended to clean local generated
state, not to be a destructive source-tree operation.

```bash
fx step clean_all
```

## Documentation rule

When adding new user-facing behavior, update this file or the README before the
change is tagged. Keep backend-only implementation details out of public help
unless they affect the user workflow.
