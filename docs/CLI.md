# FlexSoC CLI

`fx` is the command-line interface for the public `FlexSoC` API layer. It does
not call backend modules directly.

```text
CLI → FlexSoC API → src/flexsoc/backend/Makefile → backend modules
```

## Command surface

The CLI is intentionally compact:

```bash
fx help
fx commands
fx settings
fx TARGET [TARGET...]
fx TARGET --info
fx smoke
```

`TARGET` is a backend target exposed as a direct CLI command, for example
`setup`, `hjson`, `reg`, `doc`, `rtl_stub`, `setup_tb`, `sim`, `syn`, `sta`,
`power`, `pnr`, `view`, or the focused lint targets. When more than one target is
provided, FlexSoC launches them in the exact order given.

## Help and discovery

```bash
fx --help
fx help
fx commands
fx hjson --info
fx syn --info --json
```

`fx help` renders a short guide with the compact command surface and practical
examples. `fx commands --json` is intended for scripts and frontends.

## Project settings

Persist project defaults under `.flexsoc/settings.json`:

```bash
fx settings --set TOP=test --set HOST=uart --set RUN_ID=default
```

Show resolved defaults, saved values, and computed workspace path:

```bash
fx settings
fx settings --json
```

Reset saved values and return to defaults:

```bash
fx settings --reset
```

One-shot overrides use repeated `--set KEY=VALUE` flags and do not change saved
settings:

```bash
fx syn sta --dry-run --script --set TOP=my_ip --set RUN_ID=trial_01
```

## Quickstart

Start with safe previews:

```bash
fx commands
fx setup hjson reg doc --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Then run the safe setup path:

```bash
fx setup --set TOP=demo --set RUN_ID=smoke --capture
```

Inspect the generated workspace:

```bash
tree workspace | head -80
```

## IP development

A typical explicit IP path is:

```text
setup → hjson → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb
```

Inspect targets before running them:

```bash
fx hjson --info
fx rtl_stub --info
fx setup_tb --info
fx sim --info
fx syn --info
fx sta --info
fx power --info
fx pnr --info
fx sim_syn --info
fx cocotb --info
```

Preview the full IP path:

```bash
fx setup hjson reg doc rtl_stub setup_tb sim syn sta power pnr sim_syn cocotb \
  --dry-run --script \
  --set TOP=my_ip \
  --set RUN_ID=smoke
```

Run individual safe/generator-oriented targets as needed:

```bash
fx setup --set TOP=my_ip --set RUN_ID=smoke --capture
fx hjson --dry-run --set TOP=my_ip --set RUN_ID=smoke
fx rtl_stub --dry-run --set TOP=my_ip --set RUN_ID=smoke
```

EDA-dependent targets such as `sim`, `syn`, `sta`, `power`, `pnr`, `sim_syn`,
and `cocotb` require the corresponding tools and environment to be installed.

## SoC development

A typical explicit SoC path is:

```text
setup → soc_start → soc_flow → soc_prepare → soc_build_sw → soc_sim → soc_run
```

Useful SoC inspection commands:

```bash
fx soc_start --info
fx soc_flow --info
fx soc_prepare --info
fx sw_soc --info
fx soc_build_sw --info
fx soc_sim --info
fx soc_run --info
```

Preview the full SoC path:

```bash
fx setup soc_start soc_flow soc_prepare soc_build_sw soc_sim soc_run \
  --dry-run --script \
  --set TOP=soc \
  --set RUN_ID=smoke \
  --set HOST=uart
```

Run the setup-only path first:

```bash
fx setup --set TOP=soc --set RUN_ID=smoke --capture
```

## Target parameters

Use `fx TARGET --info` to see accepted parameters:

```bash
fx syn --info
fx syn --info --json
```

The metadata table is grouped by category:

| Category | Meaning |
| --- | --- |
| `common` | Shared variables like `TOP`, `RUN_ID`, `WORKSPACE`, `RUN_TOP`, and `FORCE`. |
| `specific` | Target-specific options such as host, interfaces, source names, or generated artifacts. |
| `tool` | Simulator, synthesis, timing, power, and PnR tool options. |

Overrides use repeated `--set KEY=VALUE` flags:

```bash
fx syn --dry-run \
  --set TOP=my_ip \
  --set RUN_ID=smoke \
  --set TARGET_SYN=asic \
  --set TARGET_OPT=area
```

## Execution modes

Preview one target:

```bash
fx setup --dry-run --set TOP=demo --set RUN_ID=smoke
fx setup --dry-run --json --set TOP=demo --set RUN_ID=smoke
```

Preview multiple targets as a copyable shell script:

```bash
fx setup hjson reg doc --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Run one target:

```bash
fx setup --set TOP=demo --set RUN_ID=smoke --capture
fx setup --set TOP=demo --set RUN_ID=smoke --capture --json
```

Run multiple targets in order:

```bash
fx hjson reg doc rtl_stub --set TOP=demo --set RUN_ID=smoke --capture
```

## JSON mode

Use JSON for frontends, web services, or scripts:

```bash
fx commands --json
fx syn --info --json
fx setup hjson reg doc --dry-run --json --set TOP=demo --set RUN_ID=smoke
fx setup --capture --json --set TOP=demo --set RUN_ID=smoke
```

## Shell script previews

Use script previews when you want copyable commands:

```bash
fx setup --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx setup hjson reg doc rtl_stub setup_tb --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx setup soc_start soc_flow soc_prepare --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

## Tutorials

### Tutorial 1: safe workspace setup

```bash
fx setup --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx setup --set TOP=demo --set RUN_ID=smoke --capture
```

### Tutorial 2: inspect an IP path

```bash
fx setup hjson reg doc rtl_stub setup_tb --dry-run --script --set TOP=my_ip --set RUN_ID=smoke
fx rtl_stub --info
fx syn --info --json
```

### Tutorial 3: inspect a SoC path

```bash
fx setup soc_start soc_flow soc_prepare --dry-run --script --set TOP=soc --set RUN_ID=smoke --set HOST=uart
fx soc_flow --info
fx sw_soc --info
```

## Canonical names

Use target names from `fx commands`. Do not use backend module filenames as CLI
target names.

Example:

```bash
fx sw_soc --info      # correct
fx sw_soc_gen --info  # not a public target name
```

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

Use `--tool auto|verilator|slang` to select the backend. `auto` prefers
Verilator when it is available because its warning classes are convenient for
focused checks; otherwise it uses `slang`. Install slang locally with:

```bash
make install-slang
```

The downloaded binary is placed under `.tools/bin/` and is not committed.

## Local environment files

`uv.lock` is intentionally ignored for now. The public CLI documentation uses
package commands such as `fx ...`; local development environments can run those
commands through an editable install, the project virtual environment, or
`python -m flexsoc`.
