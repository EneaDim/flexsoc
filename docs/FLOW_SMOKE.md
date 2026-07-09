# FlexSoC Flow Smoke Guide

This guide lists safe commands for checking that the current API, CLI, and
Make-backed backend still agree after the refactor.

## Rule of thumb

Start with discovery and dry-runs, then run generator-only targets, and only
then move to EDA-dependent targets.

```text
CLI -> FlexSoC API -> backend Makefile -> backend Python modules / EDA tools
```

## 1. Discover the public surface

```bash
fx help
fx commands
fx hjson --info
fx syn --info --json
```

## 2. Preview complete explicit paths

Preview commands do not execute tools. They are the safest way to validate the
current wiring.

```bash
fx setup hjson reg doc rtl_stub setup_tb sim syn sta power pnr sim_syn cocotb \
  --dry-run --script \
  --set TOP=demo \
  --set RUN_ID=smoke

fx setup soc_start soc_flow soc_prepare soc_build_sw soc_sim soc_run \
  --dry-run --script \
  --set TOP=soc \
  --set RUN_ID=smoke
```

Expected result: a shell script that calls the canonical backend Makefile under
`src/flexsoc/backend/Makefile`.

## 3. Run setup-only smoke checks

`setup` should be the first real command because it mainly creates workspace
structure.

```bash
fx setup --set TOP=demo --set RUN_ID=smoke --capture
```

Inspect generated files:

```bash
tree workspace/runs/demo/smoke | head -80
```

## 4. Run generator-only IP checks

These targets should be cheaper than synthesis, PnR, or signoff. They can still
fail if input files are missing, but they should not require the full EDA stack.

```bash
fx hjson --set TOP=demo --set RUN_ID=smoke --capture
fx reg --set TOP=demo --set RUN_ID=smoke --capture
fx doc --set TOP=demo --set RUN_ID=smoke --capture
fx rtl_stub --set TOP=demo --set RUN_ID=smoke --capture
fx setup_tb --set TOP=demo --set RUN_ID=smoke --capture
fx setup_cocotb --set TOP=demo --set RUN_ID=smoke --capture
```

## 5. Run EDA-dependent IP checks

These commands depend on external tools and local environment setup.

```bash
fx sim --set TOP=demo --set RUN_ID=smoke --capture
fx syn --set TOP=demo --set RUN_ID=smoke --capture
fx sta --set TOP=demo --set RUN_ID=smoke --capture
fx power --set TOP=demo --set RUN_ID=smoke --capture
fx pnr --set TOP=demo --set RUN_ID=smoke --capture
fx sim_syn --set TOP=demo --set RUN_ID=smoke --capture
fx cocotb --set TOP=demo --set RUN_ID=smoke --capture
```

A failure here does not necessarily mean the refactor broke the API. First check
whether the required simulator, synthesis, signoff, PnR, PDK, or FuseSoC tooling
is available.

## 6. Run SoC development previews

```bash
fx setup soc_start soc_flow soc_prepare soc_build_sw soc_sim soc_run \
  --dry-run --script \
  --set TOP=soc \
  --set RUN_ID=smoke

fx sw_soc --info
fx soc_sim --info
fx soc_run --info
```

Run setup first:

```bash
fx setup --set TOP=soc --set RUN_ID=smoke --capture
fx soc_start --set TOP=soc --set RUN_ID=smoke --capture
```

Then proceed target by target:

```bash
fx soc_flow --set TOP=soc --set RUN_ID=smoke --capture
fx soc_prepare --set TOP=soc --set RUN_ID=smoke --capture
fx soc_build_sw --set TOP=soc --set RUN_ID=smoke --capture
fx soc_sim --set TOP=soc --set RUN_ID=smoke --capture
```

## 7. Debug a failing target

For any failing command, first print the planned command:

```bash
fx TARGET --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Then print structured metadata:

```bash
fx TARGET --info --json
```

Finally run with captured output:

```bash
fx TARGET --set TOP=demo --set RUN_ID=smoke --capture --json
```

## One-command smoke check

Use the CLI smoke command when you want a quick API/Make consistency check before
running tool-dependent targets:

```bash
fx smoke
fx smoke --json
```

By default this does not launch EDA tools. It resolves safe API paths and
previews their Make commands through the `FlexSoC` API layer. To execute only the
safe workspace initialization path:

```bash
fx smoke --run-workspace --top demo --run-id smoke
```

Keep synthesis, signoff, PnR, and simulator execution as explicit target calls
after the smoke output looks correct.
