# 🏗 flexsoc Architecture

The architecture of **flexsoc** is designed to keep the framework:

✔ modular\
✔ understandable\
✔ extensible

Each module has a **very specific responsibility**.

The entire execution pipeline looks like this:

    CLI
     │
     ▼
    Runtime Engine
     │
     ▼
    Action Catalog
     │
     ▼
    Make Flows
     │
     ▼
    EDA Tools (Verilator / Yosys / OpenROAD / FuseSoC)

------------------------------------------------------------------------

# 🖥 CLI Layer

📄 `cli.py`

The CLI is the **main user entry point**.

Responsibilities:

-   parse command line arguments
-   resolve commands and actions
-   initialize workspace context
-   dispatch execution to the runtime

The CLI intentionally contains **very little logic**.

Its job is orchestration, not execution.

------------------------------------------------------------------------

# ⚙ Runtime Layer

Directory:

    runtime/

This layer implements the **execution engine** of flexsoc.

## executor.py

Responsible for:

-   executing actions
-   invoking flows
-   coordinating runtime operations

## orchestration.py

Defines the orchestration model for running commands.

Handles:

-   command preparation
-   dependency sequencing
-   execution control

## runner.py

Manages execution sessions.

Responsibilities:

-   create session directories
-   capture logs
-   maintain runtime state

## manifest.py

Stores metadata describing a run.

Examples:

-   run configuration
-   flow parameters
-   execution metadata

## reporting.py

Generates structured reports of execution results.

These reports help integrate flexsoc with:

-   CI pipelines
-   dashboards
-   automated tooling

------------------------------------------------------------------------

# 📚 Catalog Layer

Directory:

    catalog/

Defines the **action registry system**.

## registry.yaml

Central registry describing available actions.

Each entry defines:

-   action name
-   parameters
-   associated flow

## registry.py

Loads and validates the registry.

Provides runtime lookup for CLI commands.

## planning.py

Handles action planning.

Responsibilities:

-   dependency resolution
-   action expansion
-   execution planning

------------------------------------------------------------------------

# 📦 State Layer

Directory:

    state/

Manages workspace state.

## workspace.py

Defines workspace structure.

Handles:

-   run directory creation
-   artifact layout
-   path resolution

## context.py

Stores the active CLI context.

Example parameters:

    workspace
    run_top
    run_id
    top

This allows commands to reuse the current context.

## clean.py

Provides utilities for cleaning runs and artifacts.

------------------------------------------------------------------------

# 🎨 Presentation Layer

Directory:

    presentation/

Responsible for terminal output.

Uses the **Rich** library.

## ui.py

Provides formatted CLI output such as:

-   tables
-   panels
-   summaries
-   action descriptions

## helptext.py

Implements structured help messages.

Includes:

-   home help
-   quickstart guide
-   tutorial overview

------------------------------------------------------------------------

# 🩺 Diagnostics Layer

Directory:

    diagnostics/

## doctor.py

The **doctor command** verifies the development environment.

Checks:

-   Python version
-   toolchain availability
-   FuseSoC installation
-   required tools

This prevents misconfigured setups.

------------------------------------------------------------------------

# 🔧 Tools Layer

Directory:

    tools/

These modules generate hardware collateral.

Examples:

## soc_gen.py

Generates SoC RTL from configuration.

## soc_cfg.py

Builds the SoC memory map and device configuration.

## driver_gen.py

Generates software driver skeletons.

## gen_filelist.py

Creates simulation filelists.

## rtl_stub_gen.py

Creates RTL stubs for IP modules.

## regression.py

Supports regression testing infrastructure.

These tools are designed as **stateless generators**.

------------------------------------------------------------------------

# 🛠 Flow Layer

Directory:

    flow/mk/

Contains the Make-based backend.

## 00-common.mk

Defines common Make utilities and shared variables.

## 10-help-setup.mk

Defines CLI helper targets and setup utilities.

## 20-ip-flow.mk

Implements IP development flows such as:

-   ip_start
-   simulation
-   synthesis

## 30-soc-flow.mk

Implements SoC flows:

-   crossbar generation
-   SoC RTL assembly
-   FuseSoC integration
-   simulation execution

## 40-fsm-clean.mk

Handles FSM generation cleanup utilities.

------------------------------------------------------------------------

# 🧠 Run Model

The run model is the **central concept of flexsoc**.

    workspace/runs/<run_top>/<run_id>

Example:

    workspace/runs/soc_ibex/dev

Each run contains:

    rtl/
    tb/
    sim/
    sw/
    fusesoc/
    lint/

This ensures:

-   isolation between runs
-   reproducibility
-   easy debugging

------------------------------------------------------------------------

# 🔁 Execution lifecycle

Typical execution flow:

    User CLI command
     → CLI parses command
     → Catalog resolves action
     → Runtime prepares execution
     → Make flow executes tools
     → Artifacts generated in workspace
     → Reports generated

------------------------------------------------------------------------

# 🌱 Extensibility

The architecture allows new capabilities to be added easily:

-   new flows
-   new generators
-   new actions
-   new backends

without redesigning the framework.

------------------------------------------------------------------------

# 📚 Summary

flexsoc is:

🧠 a workflow orchestrator\
📦 a workspace manager\
⚙ a hardware flow engine

built to make hardware development **cleaner, safer, and more
reproducible**.
