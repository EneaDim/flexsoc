# FlexSoC Architecture and Project Structure Guide

## 1. Introduction

FlexSoC is a lightweight framework designed to support **digital IP development and SoC integration workflows**. It combines a **Python command‑line interface**, a **Make‑based backend flow**, and a **workspace‑driven execution model**.

The framework aims to provide a deterministic and inspectable development environment for hardware engineers while keeping the implementation simple and extensible.

FlexSoC intentionally avoids heavy orchestration frameworks and instead builds on familiar tools such as **Make**, **Python**, and **standard filesystem organization**.

The system supports the full lifecycle of hardware development including:

* IP initialization
* Register generation
* Documentation generation
* Testbench generation
* Simulation
* Synthesis
* Timing analysis
* Power analysis
* SoC integration
* Packaging and reuse

The guiding philosophy is:

* deterministic workflows
* reproducible builds
* transparent backend flow
* structured project organization
* minimal abstraction layers

---

# 2. Architectural Overview

FlexSoC is organized into five conceptual layers:

1. CLI Layer
2. Orchestration Layer
3. Execution Layer
4. Flow Backend
5. Workspace Model

Each layer has a clearly defined responsibility and communicates with adjacent layers through simple data structures.

```
User
  ↓
CLI Layer (Typer)
  ↓
Orchestration Layer
  ↓
Execution Layer
  ↓
Runner
  ↓
Make Backend
  ↓
EDA Tools
```

This separation ensures the system remains modular and maintainable.

---

# 3. CLI Layer

The CLI layer is implemented using **Typer**.

This layer provides the primary user interface and is responsible for parsing commands and delegating work to the orchestration and execution layers.

### Responsibilities

* Parse command line arguments
* Provide user help and documentation
* Construct execution parameters
* Trigger actions or Make targets
* Display execution summaries

### Core Commands

```
flexsoc run <action>
```

Execute a high‑level action defined in the registry.

```
flexsoc exec <plan>
```

Execute a prepared action plan.

```
flexsoc make <target>
```

Direct entrypoint into the Make backend.

```
flexsoc runs ls
```

List workspace runs.

```
flexsoc runs show
```

Inspect a specific run.

```
flexsoc actions
```

List available high‑level actions.

```
flexsoc action <name>
```

Show detailed information about an action.

### Help Commands

```
flexsoc h
flexsoc hd
flexsoc q
flexsoc t
flexsoc ip
```

These commands provide structured help through the **helptext module**.

Help output is formatted using **Rich** and printed to stderr so structured outputs on stdout remain stable.

---

# 4. Orchestration Layer

The orchestration layer connects CLI commands to the backend execution system.

It prepares execution specifications and coordinates the interaction between the runner, manifests, and reporting systems.

### Responsibilities

* Convert CLI invocations into execution specifications
* Attach run metadata
* Invoke the backend runner
* Record execution metadata
* Trigger post‑processing and reporting

### Key Concepts

**InvocationSpec**

A data structure describing a backend execution request.

Fields include:

* action identifier
* command to execute
* parameters
* workspace location
* run reference
* manifest metadata

### Orchestrated Execution

The orchestration layer ensures the following steps occur consistently:

1. Backend command execution
2. Session manifest creation
3. Run manifest updates
4. Flow manifest updates
5. Post‑processing and reporting

This guarantees consistent tracking of all workflow steps.

---

# 5. Execution Layer

The execution layer is responsible for translating actions into backend commands and coordinating the execution lifecycle.

### Responsibilities

* Load the action registry
* Validate parameters
* Resolve run references
* Construct backend commands
* Launch the runner

### Main Modules

**executor.py**

Central coordination for executing registry actions.

**runner.py**

Launches subprocesses and manages session tracking.

**manifest.py**

Writes run manifests and execution history entries.

**workspace.py**

Resolves run directories and workspace paths.

**registry.py**

Loads the action registry and maps actions to commands.

**models.py**

Defines small data structures representing run identity.

---

# 6. Runner System

The runner is responsible for executing backend commands and recording execution metadata.

Each invocation creates a **session directory** containing logs and a structured manifest.

### Runner Responsibilities

* Launch subprocesses
* Capture stdout and stderr
* Track execution time
* Handle timeouts
* Record metadata

### Session Manifest

Each run produces a manifest containing:

* action identifier
* command executed
* parameters
* exit code
* execution timestamps
* duration
* log file paths

Example session directory:

```
workspace/sessions/20260101_123000_make_sim/
  manifest.json
  stdout.log
  stderr.log
```

---

# 7. Reporting and Diagnostics

FlexSoC includes a reporting system that analyzes backend logs and produces structured summaries.

Reports are generated automatically after flow actions.

### Report Features

Reports can include:

* error counts
* warning counts
* coverage information
* tool detection
* diagnostic summaries

Example report location:

```
workspace/runs/<run_top>/<run_id>/report.json
```

The report system enables:

* quick diagnostics
* machine‑readable summaries
* easier debugging of flows

---

# 8. Flow Backend

The backend flow is implemented using **Make**.

Each Make target represents a hardware development stage.

Typical targets include:

```
ip_start
reg
lint
sim
syn
sta
power
pnr
ip_save
ip_load
```

Makefiles orchestrate the execution of open‑source EDA tools such as:

* Verilator
* Yosys
* OpenSTA
* OpenROAD

The Make backend ensures that the hardware flow remains:

* transparent
* reproducible
* easy to debug

---

# 9. Workspace Model

The workspace directory stores all persistent development state.

```
workspace/

runs/
  <run_top>/
    <run_id>/

sessions/
  <timestamp>_<action>/
```

### runs/

Stores **design state**.

Each run represents a development environment for one IP or SoC configuration.

### sessions/

Stores **CLI execution records**.

These sessions track how commands were executed independently of the run state.

This separation enables better debugging and reproducibility.

---

# 10. Run Structure

Each run directory contains:

```
run.yaml
ips/
history/
logs/
report.json
```

### run.yaml

Primary run manifest storing:

* run identifiers
* workspace path
* loaded IPs
* last executed action
* timestamps

### ips/

Contains IPs loaded into the run.

### history/

Stores chronological records of executed actions.

---

# 11. Run Identity

A run is uniquely defined by four parameters:

```
workspace
run_top
run_id
top
```

### workspace

Root directory containing runs.

### run_top

Logical namespace grouping related IPs.

### run_id

Specific instance of a development run.

### top

Active IP for the current command.

---

# 12. IP Development Workflow

Typical workflow for developing an IP:

1. Initialize IP
2. Generate registers
3. Generate documentation
4. Run simulation
5. Run synthesis
6. Run timing analysis
7. Package IP

Example run structure:

```
runs/my_ip/dev
```

---

# 13. SoC Integration Workflow

For system‑level integration multiple IPs are loaded into a single run.

Example structure:

```
runs/mysoc/dev/ips/ip0
runs/mysoc/dev/ips/ip1
```

Commands may include:

```
flexsoc make ip_load --top uart
flexsoc make ip_load --top gpio
flexsoc make soc_start
```

This allows system‑level builds to operate across multiple components.

---

# 14. Action Registry

High‑level actions are defined in a registry file.

Each entry defines:

* command
* required parameters
* optional parameters
* post‑processing behavior

Example concept:

```
actions:
  ip_start:
    command: ["make", "ip_start"]
    requires_top: true
```

The registry enables extending the CLI without modifying the core codebase.

---

# 15. Helper Modules

Several modules provide supporting functionality.

### helptext.py

Rich‑formatted CLI documentation.

### reporting.py

Generates structured run reports.

### planning.py

Supports execution plans for batch operations.

### tools/

Contains scripts used by backend Make targets.

---

# 16. Typical Execution Path

A command flows through the system as follows:

1. User invokes CLI command
2. CLI parses arguments
3. Execution parameters are constructed
4. Orchestration layer prepares invocation
5. Runner launches backend command
6. Flow generates artifacts
7. Manifests and reports are written
8. CLI displays results

---

# 17. Design Principles

FlexSoC follows several guiding principles.

### Minimalism

Avoid unnecessary abstraction layers.

### Transparency

The Make backend remains visible and debuggable.

### Determinism

Workspace‑based runs ensure reproducibility.

### Separation of Concerns

CLI, orchestration, execution, and backend flow remain independent.

### Extensibility

New actions and tools can be added easily.

---

# 18. Summary

FlexSoC provides a structured yet lightweight hardware development framework.

By combining:

* a Python CLI
* a Make‑based backend
* a workspace‑driven execution model

FlexSoC supports both **single IP development** and **complex SoC integration workflows** while remaining simple, deterministic, and extensible.

