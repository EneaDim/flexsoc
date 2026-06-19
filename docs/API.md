# FlexSoC API layer

`flexsoc.api` is the stable Python boundary for scripts, CLIs, notebooks, frontends, and future services. Consumers should import the public client and avoid backend modules directly.

## Public import

```python
from flexsoc import FlexSoC, FlexSoCConfig
```

`FlexSoC` is intentionally thin. It resolves workflows and steps into backend commands, keeps previews inspectable, and returns stable objects instead of raw subprocess internals.

## Basic client

```python
from flexsoc import FlexSoC

fx = FlexSoC(project_root=".", top="demo", run_id="smoke")
print(fx.describe())
```

The client stores a small configuration object. Call-specific keyword arguments override client defaults.

```python
from flexsoc import FlexSoC, FlexSoCConfig

config = FlexSoCConfig(
    project_root=".",
    workdir="workspace",
    options={"TOP": "demo", "RUN_ID": "smoke"},
)
fx = FlexSoC(config)
```

Configuration is normalized into Make variables when a backend command is prepared. The API always routes through the canonical backend Makefile:

```text
src/flexsoc/backend/Makefile
```

## Discover workflows

Workflows are the preferred public entrypoints because they describe user intent.

```python
fx = FlexSoC()
for workflow in fx.list_workflows():
    print(workflow.name, workflow.steps, workflow.description)
```

Current public workflows:

| Workflow | Purpose |
| --- | --- |
| `prepare` | Create the workspace and common run folders. |
| `ip_development` | Run the explicit IP development sequence. |
| `soc_development` | Run the explicit SoC development sequence. |
| `soc` | Generate or refresh the SoC project. |
| `fsm` | Run the bundled FSM generator utility. |

## IP development flow

The explicit IP development workflow is ordered as:

```text
setup → hjson_gen → reg → doc → rtl_stub → setup_tb → sim → syn → sta → power → pnr → sim_syn → cocotb
```

Use this flow when iterating on an IP block from metadata/templates through RTL, simulation, synthesis, timing/power, PnR, gate-level simulation, and Cocotb scaffolding.

```python
plan = fx.inspect_workflow("ip_development", TOP="demo", RUN_ID="smoke")
print(plan.shell_script())
```

## SoC development flow

The explicit SoC workflow is ordered as:

```text
setup → soc_start → soc_flow → soc_prepare → soc_build_sw → soc_sim → soc_run
```

Use this flow when integrating IPs into a SoC, generating the SoC wrapper/configuration, building software, and preparing simulation/run steps.

```python
plan = fx.inspect_workflow("soc_development", TOP="soc", RUN_ID="smoke")
print(plan.to_dict())
```

## Inspect a workflow

Inspection never executes backend tools. It is intended for CLI dry-runs, frontend previews, web services, and debugging.

```python
plan = fx.inspect_workflow("prepare", TOP="demo", RUN_ID="smoke")
print(plan.to_dict())
print(plan.shell_script())
```

`FlowPlan` exposes:

| Method | Description |
| --- | --- |
| `shell_lines()` | Return one shell command per workflow step. |
| `shell_script()` | Return a copy-ready shell script preview. |
| `to_dict()` | Return a JSON-ready workflow preview. |

## Run a workflow

```python
results = fx.run_workflow("prepare", TOP="demo", RUN_ID="smoke", capture=True)
for result in results:
    print(result.ok, result.returncode)
```

Use `dry_run=True` to get `FlowCommand` previews instead of executing.

```python
commands = fx.run_workflow("ip_development", dry_run=True, TOP="demo", RUN_ID="smoke")
for command in commands:
    print(command.shell_line())
```

## Discover advanced steps

Advanced steps are exposed for fine-grained control. They still go through the API layer and the backend Makefile.

```python
for step in fx.list_steps():
    print(step.name, step.group, step.description)
```

Filter by group when building menus:

```python
for step in fx.list_steps(group="soc"):
    print(step.name)
```

## Step metadata and parameters

Use `step_info()` to inspect the parameters accepted by one step.

```python
step = fx.step_info("syn")
print(step.description)
for param in step.params:
    print(param.category, param.name, param.default, param.required)
```

Parameter categories:

| Category | Meaning |
| --- | --- |
| `common` | Shared workspace/run variables such as `TOP`, `RUN_ID`, and `WORKSPACE`. |
| `specific` | Step-specific knobs such as interfaces, host choices, or source names. |
| `tool` | Tool-dependent values such as simulator, synthesis target, or timing options. |

Every `FlowStep` also carries copy-ready examples:

```python
for example in fx.step_info("syn").examples:
    print(example.command, "#", example.description)
```

## Run one advanced step from Python

This is the direct package-level path for launching a single backend step from Python.

```python
command = fx.run_step("setup", dry_run=True, TOP="demo", RUN_ID="smoke")
print(command.shell_line())

result = fx.run_step("setup", TOP="demo", RUN_ID="smoke", capture=True)
print(result.to_dict())
```

Direct step execution is useful for automation and debugging. Workflows remain the preferred public abstraction when a workflow exists.

## JSON-ready API objects

The public objects expose `to_dict()` for CLI, frontend, and service integration:

| Object | Purpose |
| --- | --- |
| `FlowParameter` | One documented step parameter. |
| `FlowExample` | One copy-ready usage example. |
| `FlowStep` | One documented advanced step. |
| `FlowWorkflow` | One public workflow. |
| `FlowPlan` | One workflow preview. |
| `FlowRequest` | One normalized Make-backed request. |
| `FlowCommand` | One command preview or execution command. |
| `FlowResult` | One stable execution result. |

## Naming rules

Use canonical API/Make step names. Module filenames are not public step names.

Example:

```text
sw_soc      # canonical step
sw_soc_gen  # module filename, not a public step name
```

The API reports clear errors for unknown names and may suggest the closest canonical step.

## Design rule

All external callers should use:

```text
consumer → FlexSoC API → backend Makefile → backend modules
```

Do not call backend modules directly from CLI, frontend, or service code unless a file is being refactored internally.
