# FlexSoC architecture

FlexSoC is organized as a Python package with a small public API, a compact CLI
frontend, and a Make-backed backend flow implementation.

```text
src/flexsoc/
├── __init__.py          # public package exports
├── __main__.py          # python -m flexsoc entrypoint
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
fx hjson reg doc
```

The CLI calls the `FlexSoC` API. CLI commands should not call backend modules
directly. Backend modules remain implementation details and may change without
public compatibility guarantees.

## Backend flow runner

For now, target execution is intentionally Makefile-backed:

```text
fx TARGET [TARGET...]
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
fx hjson reg doc
```

For one command only:

```bash
fx syn sta --set RUN_ID=trial_01
```

## Target lifecycle

A typical IP path is:

```bash
fx hjson reg doc rtl_stub setup_tb sim
```

A longer physical-design-oriented path is:

```bash
fx hjson reg doc rtl_stub setup_tb sim syn sta power pnr
```

Cocotb setup uses the generated RTL filelist:

```bash
fx hjson reg doc rtl_stub setup_cocotb cocotb
```

Regeneration uses the backend `FORCE` setting. The CLI exposes convenient flags:

```bash
fx hjson reg doc --force
fx hjson reg doc --overwrite
```

Without `--force` or `--overwrite`, generators should refuse to overwrite files
and print a useful message explaining how to proceed.

## Discovery and help

Use CLI discovery before running flows:

```bash
fx commands
fx hjson --info
fx syn --info --json
```

Shell completion can be installed with:

```bash
fx --install-completion bash
```

After reloading the shell, completion should work for commands and target names.

## Cleanup

`clean_all` should be safe and idempotent. It is intended to clean local generated
state, not to be a destructive source-tree operation.

```bash
fx clean_all
```

## Documentation rule

When adding new user-facing behavior, update this file or the README before the
change is tagged. Keep backend-only implementation details out of public help
unless they affect explicit user target calls.

## CLI usage model

The public CLI is intentionally small:

- `fx settings` manages stable project defaults such as `TOP`, `HOST`, `RUN_ID`, and `FORCE`.
- `fx TARGET [TARGET...]` runs explicit backend targets through the `FlexSoC` API facade.
- `fx TARGET --info` shows target metadata and examples.
- `fx commands` shows the compact command catalog.
- The canonical backend flow remains `src/flexsoc/backend/Makefile`; the retired top-level `flow/` tree is not part of the package flow.

The developer Makefile is `uv`-first: `make install` creates/synchronizes the
local `.venv` through `uv`, and `make test` runs tests through `uv run`.

## Waveform viewer

`fx view` opens the latest waveform under the active run with Surfer by default.
Install it with `make install-surfer`, or select GTKWave for one command with:

```bash
fx view --set WAVE_VIEWER=gtkwave
```

Surfer is the default waveform viewer. The backend Makefile exposes
deployment-friendly settings instead of installing GUI tools automatically:

```make
WAVE_VIEWER=surfer
SURFER_BACKEND=auto   # auto, native, x11, or wayland
SURFER=surfer
GTKWAVE=gtkwave
```

`SURFER_BACKEND=auto` keeps native Linux unchanged and launches Surfer through X11
on WSL, where forcing X11 avoids common Wayland compositor issues. Override per
command with `fx view --set SURFER_BACKEND=native` or
`fx view --set WAVE_VIEWER=gtkwave`.

## RTL lint commands

FlexSoC exposes focused lint commands for common RTL quality checks:

```bash
fx lint              # all configured lint diagnostics
fx lint-latch        # inferred latch diagnostics
fx lint-undriven     # undriven signal diagnostics
fx lint-width        # width mismatch diagnostics
fx lint-unconnected  # unconnected port diagnostics
fx lint-unused       # unused signal diagnostics
```

Use `--tool auto|verilator|slang` to select the backend. `auto` prefers Verilator
when it is available because its warning classes are convenient for focused
checks; otherwise it uses `slang`. Install slang locally with:

```bash
make install-slang
```

The downloaded binary is placed under `.tools/bin/` and is not committed.
