# FlexSoC CLI

`fx` is the command line interface for the public `FlexSoC` API layer. It does not call backend modules directly.

```text
CLI → FlexSoC API → src/flexsoc/backend/Makefile → backend modules
```

## Help and discovery

```bash
fx --help
fx help
fx target sequences
fx commands
```

`fx help` renders a structured guide with colored sections for quickstart, IP development, SoC development, tutorials, and common options.

## Quickstart

Start with safe previews:

```bash
fx target sequences
fx commands
fx target sequence workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
```

Then run the safe setup path:

```bash
fx target sequence workspace --set TOP=demo --set RUN_ID=smoke --capture
```

Inspect the generated workspace:

```bash
tree workspace | head -80
```

## High-level target sequences

Use target sequences for normal operation.

```bash
fx target sequences
fx target sequence workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx target sequence ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx target sequence soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

Workflow dry-runs do not execute tools. They print the exact backend commands that would be launched.

## IP development

The IP development target sequence is explicit:

```text
setup → hjson_gen → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb
```

Use `step-info` before running a specific step:

```bash
fx run --info hjson_gen
fx run --info rtl_stub
fx run --info setup_tb
fx run --info sim
fx run --info syn
fx run --info sta
fx run --info power
fx run --info pnr
fx run --info sim_syn
fx run --info cocotb
```

Preview the full IP flow:

```bash
fx target sequence ip_development --dry-run --script --set TOP=my_ip --set RUN_ID=smoke
```

Run individual safe/generator-oriented steps as needed:

```bash
fx run setup --set TOP=my_ip --set RUN_ID=smoke --capture
fx run hjson_gen --dry-run --set TOP=my_ip --set RUN_ID=smoke
fx run rtl_stub --dry-run --set TOP=my_ip --set RUN_ID=smoke
```

EDA-dependent steps such as `sim`, `syn`, `sta`, `power`, `pnr`, `sim_syn`, and `cocotb` require the corresponding tools and environment to be installed.

## SoC development

The SoC development target sequence is explicit:

```text
setup → soc_start → soc_flow → soc_prepare → soc_build_sw → soc_sim → soc_run
```

Useful SoC step inspection commands:

```bash
fx run --info soc_start
fx run --info soc_flow
fx run --info soc_prepare
fx run --info sw_soc
fx run --info soc_build_sw
fx run --info soc_sim
fx run --info soc_run
```

Preview the full SoC flow:

```bash
fx target sequence soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke --set HOST=uart
```

Run the setup-only path first:

```bash
fx target sequence workspace --set TOP=soc --set RUN_ID=smoke --capture
```

## Step parameters

Use `fx run --info NAME` to see what can be passed to a specific step.

```bash
fx run --info syn
fx run --info syn --examples
fx run --info syn --json
```

The table is grouped by category:

| Category | Meaning |
| --- | --- |
| `common` | Shared variables like `TOP`, `RUN_ID`, `WORKSPACE`, `RUN_TOP`, and `FORCE`. |
| `specific` | Step-specific options such as host, interfaces, source names, or generated artifacts. |
| `tool` | Simulator, synthesis, timing, power, and PnR tool options. |

Overrides use repeated `--set KEY=VALUE` flags:

```bash
fx run syn --dry-run \
  --set TOP=my_ip \
  --set RUN_ID=smoke \
  --set TARGET_SYN=asic \
  --set TARGET_OPT=area
```

## Advanced step execution

Preview one step:

```bash
fx run setup --dry-run --set TOP=demo --set RUN_ID=smoke
fx run setup --dry-run --json --set TOP=demo --set RUN_ID=smoke
```

Run one step:

```bash
fx run setup --set TOP=demo --set RUN_ID=smoke --capture
fx run setup --set TOP=demo --set RUN_ID=smoke --capture --json
```

Direct steps are useful for debugging and automation. Prefer target sequences when a target sequence describes the task.

## JSON mode

Use JSON for frontends, web services, or scripts:

```bash
fx target sequences
fx commands
fx run --info syn --json
fx target sequence ip_development --dry-run --json --set TOP=demo --set RUN_ID=smoke
fx run setup --dry-run --json --set TOP=demo --set RUN_ID=smoke
```

## Shell script previews

Use script previews when you want copyable commands:

```bash
fx target sequence workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx target sequence ip_development --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx target sequence soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke
```

## Tutorials

### Tutorial 1: safe workspace setup

```bash
fx target sequence workspace --dry-run --script --set TOP=demo --set RUN_ID=smoke
fx target sequence workspace --set TOP=demo --set RUN_ID=smoke --capture
```

### Tutorial 2: inspect an IP flow

```bash
fx target sequence ip_development --dry-run --script --set TOP=my_ip --set RUN_ID=smoke
fx run --info rtl_stub
fx run --info syn --examples
```

### Tutorial 3: inspect a SoC flow

```bash
fx target sequence soc_development --dry-run --script --set TOP=soc --set RUN_ID=smoke --set HOST=uart
fx run --info soc
fx run --info sw_soc
```

## Canonical names

Use step names from `fx commands`. Do not use backend module filenames as CLI step names.

Example:

```bash
fx run --info sw_soc      # correct
fx run --info sw_soc_gen  # not a public step name
```

## Local environment files

`uv.lock` is intentionally ignored for now. The public CLI documentation uses package commands such as `fx ...`; local development environments can run those commands however they prefer.

## Quickstart

```bash
fx setting --set TOP=test --set HOST=uart --set RUN_ID=default
fx setup --dry-run --script
fx hjson --force
fx reg
fx doc
fx rtl_stub
fx setup_tb
fx sim
fx view
```

Use `fx <step> --info` to inspect a single backend step before running it.
