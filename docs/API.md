# FlexSoC API Layer

`flexsoc.api` is the stable Python boundary for tools, scripts, CLIs, frontends, and future services.
Backend modules remain implementation details and should not be imported by consumers.

## Public import

```python
from flexsoc import FlexSoC, FlexSoCConfig
```

## Client

```python
from flexsoc import FlexSoC

fx = FlexSoC(project_root=".", top="demo")
print(fx.describe())
```

`FlexSoC` stores a small configuration object and exposes workflow-oriented methods first.
Advanced step methods are available for direct control while the backend is being consolidated.

## Configuration

```python
from flexsoc import FlexSoC, FlexSoCConfig

config = FlexSoCConfig(workdir="build/flexsoc", options={"top": "demo"})
fx = FlexSoC(config, project_root=".")
```

Configuration values are normalized into Make variables when a Make-backed step is prepared.
Call-specific keyword arguments override client defaults.

## Discover workflows

```python
fx = FlexSoC()
for workflow in fx.list_workflows():
    print(workflow.name, workflow.steps, workflow.description)
```

Workflows are the preferred public API because they describe user intent.
Current workflows are thin wrappers over existing backend steps.

## Inspect a workflow

```python
plan = fx.inspect_workflow("prepare", top="demo")
print(plan.to_dict())
print(plan.shell_script())
```

Inspection never executes backend commands.
It is intended for CLI dry-runs, web previews, and debugging.

## Run a workflow

```python
results = fx.run_workflow("prepare", top="demo", capture=True)
for result in results:
    print(result.ok, result.returncode)
```

`run_workflow` returns stable `FlowResult` objects when execution is enabled.
Use `dry_run=True` to receive `FlowCommand` previews instead.

## Advanced step API

```python
command = fx.run_step("setup", dry_run=True, top="demo")
print(command.shell_line())

result = fx.run_step("setup", top="demo", capture=True)
print(result.to_dict())
```

Step calls are advanced API entries used to bridge the existing Make flow.
They should remain secondary to high-level workflows.

## JSON-ready objects

The API objects expose `to_dict()` where useful:

- `FlowRequest.to_dict()`
- `FlowCommand.to_dict()`
- `FlowResult.to_dict()`
- `FlowPlan.to_dict()`
- `FlowWorkflow.to_dict()`

These dictionaries are intended for CLIs, frontends, and future web services.
