# FlexSoC Flow Smoke Guide

This guide lists the safest commands for checking that the current API, CLI,
and Make-backed backend still agree after the refactor.

## Rule of thumb

Start with discovery and dry-runs, then run generator-only steps, and only then
move to EDA-dependent steps.

```text
CLI -> FlexSoC API -> backend Makefile -> backend Python modules / EDA tools
```

## 1. Discover the public surface

```bash
fx help
fx workflows
fx steps
```

Use `step-info` to inspect a single step before launching it:

```bash
fx step-info setup
fx step-info hjson_gen
fx step-info syn --examples
fx step-info soc_flow --json
```

## 2. Preview complete workflows

Preview commands do not execute tools. They are the safest way to validate the
current wiring.

```bash
fx workflow ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

Expected result: a shell script that calls the canonical backend Makefile under
`src/flexsoc/backend/Makefile`.

## 3. Run setup-only smoke checks

`setup` should be the first real command because it mainly creates workspace
structure.

```bash
fx step setup --set TOP=demo --set RUN_ID=smoke --capture
fx workflow workspace --set TOP=demo --set RUN_ID=smoke --capture
```

Inspect generated files:

```bash
tree workspace/runs/demo/smoke | head -80
```

## 4. Run generator-only IP checks

These steps should be cheaper than synthesis, PnR, or signoff. They can still
fail if input files are missing, but they should not require the full EDA stack.

```bash
fx step hjson_gen --set TOP=demo --set RUN_ID=smoke --capture
fx step reg --set TOP=demo --set RUN_ID=smoke --capture
fx step doc --set TOP=demo --set RUN_ID=smoke --capture
fx step rtl_stub --set TOP=demo --set RUN_ID=smoke --capture
fx step setup_tb --set TOP=demo --set RUN_ID=smoke --capture
fx step setup_cocotb --set TOP=demo --set RUN_ID=smoke --capture
```

## 5. Run EDA-dependent IP checks

These commands depend on external tools and local environment setup.

```bash
fx step sim --set TOP=demo --set RUN_ID=smoke --capture
fx step syn --set TOP=demo --set RUN_ID=smoke --capture
fx step sta --set TOP=demo --set RUN_ID=smoke --capture
fx step power --set TOP=demo --set RUN_ID=smoke --capture
fx step pnr --set TOP=demo --set RUN_ID=smoke --capture
fx step sim_syn --set TOP=demo --set RUN_ID=smoke --capture
fx step cocotb --set TOP=demo --set RUN_ID=smoke --capture
```

A failure here does not necessarily mean the refactor broke the API. First check
whether the required simulator, synthesis, signoff, PnR, PDK, or FuseSoC tooling
is available.

## 6. Run SoC development previews

```bash
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
fx step-info sw_soc
fx step-info soc_sim
fx step-info soc_run
```

Run setup first:

```bash
fx step setup --set TOP=soc --set RUN_ID=smoke --capture
fx step soc_start --set TOP=soc --set RUN_ID=smoke --capture
```

Then proceed step by step:

```bash
fx step soc_flow --set TOP=soc --set RUN_ID=smoke --capture
fx step soc_prepare --set TOP=soc --set RUN_ID=smoke --capture
fx step soc_build_sw --set TOP=soc --set RUN_ID=smoke --capture
fx step soc_sim --set TOP=soc --set RUN_ID=smoke --capture
```

## 7. Debug a failing step

For any failing command, first print the planned command:

```bash
fx step STEP_NAME --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Then print structured metadata:

```bash
fx step-info STEP_NAME --json
```

Finally run with captured output:

```bash
fx step STEP_NAME --set TOP=demo --set RUN_ID=smoke --capture --json
```

## One-command smoke check

Use the CLI smoke command when you want a quick API/Make consistency check before running tool-dependent steps:

```bash
fx smoke
fx smoke --json
```

By default this does not launch EDA tools. It resolves the public workflows and previews their Make commands through the `FlexSoC` API layer. To execute only the safe workspace initialization path:

```bash
fx smoke --run-workspace --top demo --run-id smoke
```

Keep synthesis, signoff, PnR, and simulator execution as explicit step or workflow calls after the smoke output looks correct.
