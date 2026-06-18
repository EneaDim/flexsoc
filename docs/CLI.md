# FlexSoC CLI

`fx` is the thin command line interface for the public `FlexSoC` API layer.
It should not call backend modules directly.

## Help

```bash
fx --help
fx help
```

`fx help` prints a compact guide with the common workflow and step commands.

## Describe the API client

```bash
fx describe
```

Prints the configured API client as JSON.

## List high-level workflows

```bash
fx workflows
```

Workflows are the recommended public entrypoints.
They map intent-oriented commands to one or more backend steps.

## Preview a workflow

```bash
fx workflow prepare --dry-run
fx workflow prepare --dry-run --json
fx workflow prepare --dry-run --script
```

Dry-runs do not execute backend tools.
Use `--json` for frontends and `--script` for a copyable shell script.

## Run a workflow

```bash
fx workflow prepare --set TOP=demo
fx workflow prepare --set TOP=demo --capture
fx workflow prepare --set TOP=demo --capture --json
```

`--set KEY=VALUE` forwards an override to the API layer.
The API normalizes the key into the Make-backed backend request.

## List advanced steps

```bash
fx steps
fx steps --group setup
fx steps --group soc
fx steps --group utility
```

Advanced steps expose the existing Make-backed flow while the backend is being refactored.

## Preview one advanced step

```bash
fx step setup --dry-run --set TOP=demo
fx step setup --dry-run --json --set TOP=demo
```

Use this when you need to inspect the exact backend command before execution.

## Run one advanced step

```bash
fx step setup --set TOP=demo
fx step setup --set TOP=demo --capture
fx step setup --set TOP=demo --capture --json
```

Direct step execution is considered advanced.
Prefer workflows whenever one exists for the operation.
