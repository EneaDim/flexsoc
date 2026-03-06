<p align="center">
<img src="assets/open-IP-SoC-logo.png" alt="Digital IP SoC Dev Env Logo" width="300"/>
</p>

<a id="setup"></a>


# flexsoc ✨

**A framework for IP development and SoC integration**

`flexsoc` is a workspace-based hardware development framework for building, verifying, and integrating digital IPs using an open-source flow.

It provides a consistent developer experience across:

* **IP bring-up**
* **register-map generation**
* **testbench setup**
* **simulation**
* **synthesis**
* **STA / power signoff**
* **PnR**
* **SoC-oriented integration flows**

The project combines a modern **Python CLI** with a deterministic **Make-based backend**, so users get both a guided interface and full low-level control.

## Why flexsoc

Digital IP development often ends up split across ad-hoc scripts, fragile Makefiles, and project-specific conventions.
`flexsoc` aims to provide a cleaner model:

* a **single entry point** for designers
* a **workspace-based execution model**
* reproducible flow steps
* support for **OpenTitan-style collateral generation**
* a path from **standalone IP design** to **SoC integration**

The framework is intentionally incremental: it helps you start fast, iterate quickly, and still keep the flow transparent.

## Core ideas

### 1. Workspace-first execution

All generated artifacts live in a workspace, not inside the source flow directory.

This keeps the repository clean and makes runs easier to compare, archive, and reproduce.

### 2. Modern CLI + deterministic backend

The user-facing interface is the `flexsoc` CLI.
Under the hood, the implementation still relies on Make targets and scriptable flow steps.

This gives you:

* a higher-level user experience
* explicit commands
* compatibility with direct Make usage when needed

### 3. IP development and SoC integration in one environment

The same framework can be used both to develop standalone IPs and to exercise small SoC-oriented integration flows and tutorials.

## Highlights

* **Typer-based CLI**
* **registry-backed actions**
* **workspace-based runs**
* **runner-level manifests**
* **flow-level manifests and reports**
* **pure JSON output for structured commands**
* **stderr-only CLI UI**
* **Verilator simulation**
* **Yosys synthesis**
* **OpenSTA signoff**
* **coverage reporting during simulation**
* **tutorial targets for IP, FSM, and SoC-like examples**

## Project structure

```text
flexsoc/
├── Makefile                   # root developer Makefile
├── flow/                      # compatibility shim for make -C flow ...
│   ├── util/                  # opentitan utilities
├── src/
│   ├── flexsoc/
│   │   ├── cli.py             # CLI entry point
│   │   ├── ui.py              # terminal UI / summaries / help views
│   │   ├── executor.py        # action execution + backend orchestration
│   │   ├── runner.py          # command runner and runner-level manifest
│   │   ├── reporting.py       # flow-level report.json generation
│   │   ├── registry.yaml      # action registry and descriptions
│   │   ├── flow/
│   │   │   └── Makefile       # actual flow Makefile
│   │   └── tools/             # Python tools used by the flow
│   └── util/                  # imported third-party / utility tooling
├── hw/
│   └── ips/                   # reusable IPs, packages, primitives, examples
├── workspace/                 # generated runs (default)
└── tests/
    └── e2e/                   # end-to-end tests
```

## Execution model

`flexsoc` distinguishes between two kinds of run artifacts.

### Runner-level artifacts

These capture the execution of a CLI command itself.

```text
workspace/runs/<timestamp>_<action>/
    stdout.log
    stderr.log
    manifest.json
```

### Flow-level artifacts

These contain the actual design artifacts for a given top/run pair.

```text
workspace/runs/<top>/<run_id>/
    rtl/
    tb/
    sim/
    syn/
    signoff/
    logs/
    manifest.json
    report.json
```

This separation is intentional:

* runner-level data tells you **how a command was executed**
* flow-level data tells you **what was produced for the design run**

## Installation

### Python environment

Create and activate a virtual environment, then install the project in editable mode.

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -e .
```

### Developer checks

```bash
make lint
make test
make check
```

## Command-line interface

The main entry point is:

```bash
flexsoc
```

### Main commands

```bash
flexsoc run ...
flexsoc exec ...
flexsoc make ...
flexsoc actions
flexsoc action <name>
flexsoc dump-registry
```

### Shortcuts

```bash
flexsoc h      # hub
flexsoc q      # quickstart
flexsoc t      # tutorials
flexsoc ip     # IP development guide
flexsoc a      # actions
```

## Typical usage

### Start a new IP workspace

```bash
flexsoc run ip_start --top my_ip --run-id dev --overwrite
```

### Run multiple flow targets in sequence

```bash
flexsoc make syn sta power --top my_ip --run-id dev --workspace workspace --overwrite
```

### Use a different run folder name than the actual design top

```bash
flexsoc make sim --run-top tiny-soc --top soc --workspace workspace --run-id dev1 --overwrite
```

This is useful when:

* the design top module is `soc`
* but you want the run to live under `workspace/runs/tiny-soc/dev1`

## `run` vs `make`

### `flexsoc run`

Use `run` for registry-backed actions and a more guided user experience.

Example:

```bash
flexsoc run ip_start --top my_ip --run-id dev --overwrite
```

### `flexsoc make`

Use `make` as the escape hatch for raw flow targets.

Example:

```bash
flexsoc make sta --top my_ip --run-id dev --workspace workspace --overwrite
```

It also supports multiple targets:

```bash
flexsoc make ip_start syn sta power --top my_ip --run-id dev --workspace workspace --overwrite
```

## IP development flow

The framework supports an end-to-end IP workflow.

### 1. Author the register description

* `hjson`

Generates a starter HJSON template.
You then edit it with the real register map and metadata.

### 2. Generate register collateral and documentation

* `reg`
* `doc`

Generate register-related RTL and documentation from HJSON.

### 3. Generate the RTL skeleton

* `rtl_stub`

Creates the initial wrapper / stub structure.
You then write the real core implementation.

### 4. Set up verification

* `setup_tb`

Creates the testbench scaffold.
You then write or extend the actual testbench.

### 5. Verify the design

* `lint`
* `sim`

Simulation is expected to print a `Coverage:` line on stdout.

### 6. Implement and sign off

* `synth`
* `sta`
* `power`
* `pnr`
* `pnr_gui`

### 7. Package and integrate

* `driver`
* `fsoc_init`
* `ip_save`

## Quickstart

A practical first sequence is:

```bash
flexsoc run ip_start --top my_ip --run-id dev --overwrite
flexsoc make view --top my_ip --run-id dev --workspace workspace --overwrite
flexsoc make syn --top my_ip --run-id dev --workspace workspace --overwrite
flexsoc make sta --top my_ip --run-id dev --workspace workspace --overwrite
flexsoc make power --top my_ip --run-id dev --workspace workspace --overwrite
flexsoc make pnr --top my_ip --run-id dev --workspace workspace --overwrite
flexsoc make pnr_gui --top my_ip --run-id dev --workspace workspace --overwrite
```

For fast iteration on the same run, using `--overwrite` from the start is recommended.

## Tutorials

The repository includes tutorial flows that exercise different parts of the framework.

### FSM tutorial

Run the FSM generation and RTL flow.

```bash
flexsoc make fsm_tutorial --top fsm_example --overwrite
```

### IP tutorial

Run an IP example flow for a predefined IP.

```bash
flexsoc make ip_tutorial --top spi_host --overwrite
flexsoc make ip_tutorial --top pwm_ramp --overwrite
```

### Processor-less SoC-style tutorial

Load a prebuilt SoC-like bundle and run the flow with a distinct run-top / design-top model.

```bash
flexsoc make soc_pless --overwrite
```

### Full tutorial

End-to-end example.

```bash
flexsoc make full_tutorial --overwrite
```

## Developer Makefile

The root `Makefile` is for repository-level developer operations.

### Useful targets

```bash
make help
make lint
make fix
make test
make check
make clean
```

## Reports and manifests

### `manifest.json`

Flow-level metadata for a given design run.

### `report.json`

Structured run summary produced after post-processing.

### Runner manifest

Each CLI invocation also emits a runner-level manifest under the timestamped runner directory.

This makes the flow easier to debug, archive, and inspect programmatically.

## UI principles

The CLI tries to follow a few strict rules:

* structured outputs remain on **stdout**
* human-facing UI goes to **stderr**
* `dump-registry` produces **pure JSON**
* summaries show:

  * exit code
  * runner directory
  * flow directory
  * command
  * stdout/stderr logs

The UI is intentionally modern but still testable and script-friendly.

## Current status

The project currently provides:

* a stable workspace-based flow
* a modernized CLI
* tutorial coverage
* end-to-end tests
* support for both guided and escape-hatch workflows

It is designed to remain practical for real IP work, not just for toy examples.

## Roadmap / next steps

### AI-assisted workflow

Introduce AI assistants for:

* guided use of the tool
* natural-language help and flow navigation
* automated FSM generation from natural-language descriptions
* future structured design-assist workflows without compromising determinism of execution

### Formal verification

Add **SymbiYosys**-based formal checks for selected IP classes and protocol adapters.

### AXI interface support

Extend the register / integration side with **AXI4 / AXI-Lite** support, ideally reusing existing work and conventions from the **PULP Platform** ecosystem where appropriate.

### Broader SoC integration

Continue improving the path from standalone IP work to system-level integration, especially for crossbar/interconnect-oriented flows.

### Flow polish

Further refine:

* summaries and reports
* tutorial onboarding
* action discoverability
* formalized target metadata
* export / packaging of generated IPs

## Philosophy

`flexsoc` is not trying to hide the hardware flow.
It is trying to make it:

* **cleaner**
* **more reproducible**
* **more discoverable**
* **easier to use**
* **easier to integrate into larger systems**

The backend remains explicit.
The user experience becomes friendlier.

## License

**Apache License 2.0**.


