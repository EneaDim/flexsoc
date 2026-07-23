# FlexSoC API layer

`flexsoc.api` is the stable Python boundary for scripts, CLIs, notebooks, frontends, and future services. Consumers should import the public client and avoid backend modules directly.

## Public import

```python
from flexsoc import FlexSoC, FlexSoCConfig
```

`FlexSoC` is intentionally thin. It resolves programmatic workflows and direct backend targets into Make commands, keeps previews inspectable, and returns stable objects instead of raw subprocess internals.

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

## Discover programmatic workflows

Workflows are API-level helpers for scripts that want named ordered target groups. The CLI stays smaller and launches explicit target lists directly.

```python
fx = FlexSoC()
for workflow in fx.list_workflows():
    print(workflow.name, workflow.steps, workflow.description)
```

Current public workflows:

| Workflow | Purpose |
| --- | --- |
| `workspace` | Create the workspace and common run folders. |
| `ip_development` | Run the explicit IP development sequence. |
| `soc_development` | Run the explicit SoC development sequence. |
| `soc` | Generate or refresh the SoC project. |
| `fsm` | Run the bundled FSM generator utility. |

## IP development flow

The explicit IP development workflow is ordered as:

```text
setup → hjson → reg → doc → rtl_stub → flist → setup_tb → setup_cocotb → setup_model → sim → syn → sta → power → pnr → sim_syn → cocotb
```

Use this flow when iterating on an IP block from metadata/templates through RTL, generated verification, simulation, synthesis, timing/power, PnR, gate-level simulation, and Cocotb.

```python
plan = fx.inspect_workflow("ip_development", TOP="demo", RUN_ID="smoke")
print(plan.shell_script())
```

## SoC development flow

The explicit SoC workflow is ordered as:

```text
setup → soc_uart_gen/soc_ibex_gen → soc_build_sw → soc_run
```

Use this flow when integrating IPs into UART-host or Ibex-host SoC runs, building software, and preparing simulation/run steps.

```python
plan = fx.inspect_workflow("soc_development", TOP="soc", RUN_ID="smoke")
print(plan.to_dict())
```

## Inspect a workflow

Inspection never executes backend tools. It is intended for CLI dry-runs, frontend previews, web services, and debugging.

```python
plan = fx.inspect_workflow("workspace", TOP="demo", RUN_ID="smoke")
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
results = fx.run_workflow("workspace", TOP="demo", RUN_ID="smoke", capture=True)
for result in results:
    print(result.ok, result.returncode)
```

Use `dry_run=True` to get `FlowCommand` previews instead of executing.

```python
commands = fx.run_workflow("ip_development", dry_run=True, TOP="demo", RUN_ID="smoke")
for command in commands:
    print(command.shell_line())
```

## Discover backend targets

Backend targets are exposed for fine-grained control. They still go through the API layer and the backend Makefile.

```python
for step in fx.list_steps():
    print(step.name, step.group, step.description)
```

Filter by group when building menus:

```python
for step in fx.list_steps(group="soc"):
    print(step.name)
```

## Target metadata and parameters

Use `step_info()` to inspect the parameters accepted by one target.

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


## Generated verification targets

The verification generators share one run-local structure:

```text
setup_tb      # SystemVerilog TB, register sequence, test configs, vectors
setup_cocotb  # Cocotb TB and drivers using the same configs/vectors
setup_model   # Python model_<top>.py
```

Generated `config.regs` files use clock-qualified register names resolved from
the HJSON regmap:

```text
write clk_i.CTRL 0x00000001
write clk_i.WDATA 0x00000002
```

Generated `.vec` files are shared by SystemVerilog and Cocotb:

```text
# cycle input expected latency mask [note]
0 0x00000000 0x00000000 2 0xffffffff
```

Run one generated test from Python by launching the `cocotb` target with
`TEST_NAME`:

```python
result = fx.run_step("cocotb", TOP="quick_ip", RUN_TOP="quick_ip", RUN_ID="smoke", TEST_NAME="smoke")
print(result.ok)
```

## Run one backend target from Python

This is the direct package-level path for launching a single backend target from Python.

```python
command = fx.run_step("setup", dry_run=True, TOP="demo", RUN_ID="smoke")
print(command.shell_line())

result = fx.run_step("setup", TOP="demo", RUN_ID="smoke", capture=True)
print(result.to_dict())
```

Direct target execution is useful for automation and debugging. Programmatic workflows remain available when a script wants a named ordered target group.

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

Use canonical API/Make target names. Module filenames are not public target names.

Example:

```text
sw_soc      # canonical target
sw_soc_gen  # module filename, not a public target name
```

The API reports clear errors for unknown names and may suggest the closest canonical step.

## Design rule

All external callers should use:

```text
consumer → FlexSoC API → backend Makefile → backend modules
```

Do not call backend modules directly from CLI, frontend, or service code unless a file is being refactored internally.
