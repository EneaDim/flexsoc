# FlexSoC CLI

`fx` is the command line interface for the public `FlexSoC` API layer. It does not call backend modules directly.

```text
CLI → FlexSoC API → src/flexsoc/backend/Makefile → backend modules
```

## Help and discovery

```bash
fx --help
fx help
fx workflows
fx steps
```

`fx help` renders a structured guide with colored sections for quickstart, IP development, SoC development, tutorials, and common options.

## Quickstart

Start with safe previews:

```bash
fx workflows
fx steps
fx workflow workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Then run the safe setup path:

```bash
fx workflow workspace --set TOP=demo --set RUN_ID=smoke --capture
```

Inspect the generated workspace:

```bash
tree workspace | head -80
```

## High-level workflows

Use workflows for normal operation.

```bash
fx workflows
fx workflow workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx workflow ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

Workflow dry-runs do not execute tools. They print the exact backend commands that would be launched.

## IP development

The IP development workflow is explicit:

```text
setup → hjson_gen → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb
```

Use `step-info` before running a specific step:

```bash
fx step-info hjson_gen
fx step-info rtl_stub
fx step-info setup_tb
fx step-info sim
fx step-info syn
fx step-info sta
fx step-info power
fx step-info pnr
fx step-info sim_syn
fx step-info cocotb
```

Preview the full IP flow:

```bash
fx workflow ip_development --dry-run --script --set TOP=my_ip --set RUN_ID=smoke
```

Run individual safe/generator-oriented steps as needed:

```bash
fx step setup --set TOP=my_ip --set RUN_ID=smoke --capture
fx step hjson_gen --dry-run --set TOP=my_ip --set RUN_ID=smoke
fx step rtl_stub --dry-run --set TOP=my_ip --set RUN_ID=smoke
```

EDA-dependent steps such as `sim`, `syn`, `sta`, `power`, `pnr`, `sim_syn`, and `cocotb` require the corresponding tools and environment to be installed.

## SoC development

The SoC development workflow is explicit:

```text
setup → soc_start → soc_flow → soc_prepare → soc_build_sw → soc_sim → soc_run
```

Useful SoC step inspection commands:

```bash
fx step-info soc_start
fx step-info soc_flow
fx step-info soc_prepare
fx step-info sw_soc
fx step-info soc_build_sw
fx step-info soc_sim
fx step-info soc_run
```

Preview the full SoC flow:

```bash
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke --set HOST=uart
```

Run the setup-only path first:

```bash
fx workflow workspace --set TOP=soc --set RUN_ID=smoke --capture
```

## Step parameters

Use `fx step-info NAME` to see what can be passed to a specific step.

```bash
fx step-info syn
fx step-info syn --examples
fx step-info syn --json
```

The table is grouped by category:

| Category | Meaning |
| --- | --- |
| `common` | Shared variables like `TOP`, `RUN_ID`, `WORKSPACE`, `RUN_TOP`, and `FORCE`. |
| `specific` | Step-specific options such as host, interfaces, source names, or generated artifacts. |
| `tool` | Simulator, synthesis, timing, power, and PnR tool options. |

Overrides use repeated `--set KEY=VALUE` flags:

```bash
fx step syn --dry-run \
  --set TOP=my_ip \
  --set RUN_ID=smoke \
  --set TARGET_SYN=asic \
  --set TARGET_OPT=area
```

## Advanced step execution

Preview one step:

```bash
fx step setup --dry-run --set TOP=demo --set RUN_ID=smoke
fx step setup --dry-run --json --set TOP=demo --set RUN_ID=smoke
```

Run one step:

```bash
fx step setup --set TOP=demo --set RUN_ID=smoke --capture
fx step setup --set TOP=demo --set RUN_ID=smoke --capture --json
```

Direct steps are useful for debugging and automation. Prefer workflows when a workflow describes the task.

## JSON mode

Use JSON for frontends, web services, or scripts:

```bash
fx workflows
fx steps
fx step-info syn --json
fx workflow ip_development --dry-run --json --set TOP=demo --set RUN_ID=smoke
fx step setup --dry-run --json --set TOP=demo --set RUN_ID=smoke
```

## Shell script previews

Use script previews when you want copyable commands:

```bash
fx workflow workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx workflow ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

## Tutorials

### Tutorial 1: safe workspace setup

```bash
fx workflow workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx workflow workspace --set TOP=demo --set RUN_ID=smoke --capture
```

### Tutorial 2: inspect an IP flow

```bash
fx workflow ip_development --dry-run --script --set TOP=my_ip --set RUN_ID=smoke
fx step-info rtl_stub
fx step-info syn --examples
```

### Tutorial 3: inspect a SoC flow

```bash
fx workflow soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke --set HOST=uart
fx step-info soc
fx step-info sw_soc
```

## Canonical names

Use step names from `fx steps`. Do not use backend module filenames as CLI step names.

Example:

```bash
fx step-info sw_soc      # correct
fx step-info sw_soc_gen  # not a public step name
```

## Local environment files

`uv.lock` is intentionally ignored for now. The public CLI documentation uses package commands such as `fx ...`; local development environments can run those commands however they prefer.
