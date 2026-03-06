# flexsoc Project Structure and Architecture Guide

## Overview

flexsoc is a lightweight framework designed to support digital IP development and SoC integration.  
The tool combines a Python command‑line interface, a Make-based backend, and a workspace-driven execution model.

The main goals of flexsoc are:

- Deterministic hardware development workflows
- Reproducible builds
- Clear project organization
- Minimal abstractions
- Easy extensibility

flexsoc provides a structured environment where engineers can develop individual hardware IP blocks and later combine them into system-level designs.

The tool manages the lifecycle of hardware development including:

- IP initialization
- Register generation
- Documentation generation
- Testbench generation
- Simulation
- Synthesis
- Signoff analysis
- SoC assembly
- Packaging and reuse


------------------------------------------------------------

# High Level Architecture

flexsoc is organized around four main layers:

1. CLI Layer
2. Execution Layer
3. Flow Backend
4. Workspace Model

Each layer has a clear responsibility and interacts with the others through simple interfaces.


------------------------------------------------------------

# CLI Layer

The CLI layer is implemented with Typer and is responsible for parsing user commands and delegating work to the execution layer.

Main responsibilities:

- Parse command line arguments
- Build execution parameters
- Trigger actions or Make targets
- Display results and formatted output
- Provide help and documentation commands

The CLI exposes several main command groups:

flexsoc run  
Runs a high-level action defined in the action registry.

flexsoc exec  
Executes a prepared action plan.

flexsoc make  
Directly invokes Make targets for advanced users.

flexsoc runs ls  
Lists all runs in the workspace.

flexsoc runs show  
Displays detailed information about a specific run.

flexsoc actions  
Shows all registered actions.

flexsoc action <name>  
Shows information about a specific action.

flexsoc h  
Displays compact help.

flexsoc hd  
Displays a detailed colorful help guide.


------------------------------------------------------------

# Execution Layer

The execution layer connects the CLI with the flow backend.

Its responsibilities include:

- Loading the action registry
- Validating parameters
- Resolving run directories
- Preparing Make commands
- Launching execution through the runner
- Writing manifests and history entries

The main modules involved are:

executor.py  
Central orchestration for running actions.

runner.py  
Responsible for launching subprocesses and recording execution sessions.

manifest.py  
Handles creation of run manifests and history entries.

registry.py  
Loads the action registry that maps actions to Make commands.

workspace.py  
Provides utilities for resolving run directories and run references.

models.py  
Defines small data structures representing run identity.


------------------------------------------------------------

# Flow Backend

The backend flow is implemented using Make.

The Makefile defines targets that represent different hardware development steps.

Typical targets include:

ip_start  
Initialize a new IP project.

reg  
Generate registers from HJSON definitions.

doc  
Generate documentation.

tb  
Generate testbench structures.

lint  
Run linting tools.

sim  
Run simulation.

syn  
Run synthesis.

sta  
Run static timing analysis.

pnr  
Run place and route.

ip_save  
Package an IP for reuse.

ip_load  
Load an IP into a run environment.

These targets interact with scripts in the tools directory that perform specialized generation tasks.

The Make backend keeps the system simple and transparent while leveraging common EDA tool flows.


------------------------------------------------------------

# Workspace Model

The workspace directory is the central location where all runs and execution sessions are stored.

A typical workspace layout looks like this:

workspace/
runs/
<run_top>/
<run_id>/
ips/
history/
run.yaml

sessions/
<timestamp>_<action>/

The runs directory stores design state.  
Each run corresponds to a development context.

The sessions directory stores execution logs and CLI invocation records.


------------------------------------------------------------

# Run Structure

Each run has the following internal structure:

run.yaml  
Main manifest describing the current state of the run.

ips/  
Directory containing loaded or developed IPs.

history/  
A chronological record of actions performed in the run.

Additional build artifacts may be generated depending on the flow steps executed.


------------------------------------------------------------

# Run Identity

A run is uniquely defined by:

workspace  
Root directory containing all runs.

run_top  
Logical namespace grouping one or more IPs.

run_id  
Identifier for a specific run instance.

top  
The active IP being operated on for the current action.

This model supports both:

Single IP development flows  
Multiple IP SoC integration flows.


------------------------------------------------------------

# IP Development Flow

In single IP mode the workflow typically looks like:

Initialize IP
Generate registers
Generate documentation
Run simulation
Run synthesis
Analyze timing

The run_top usually matches the IP name.

Example structure:

runs/my_ip/dev


------------------------------------------------------------

# SoC Integration Flow

In SoC integration flows multiple IPs are loaded into the same run_top.

Example commands:

Load IP0 into run
Load IP1 into run

Example structure:

runs/mysoc/dev/ips/ip0
runs/mysoc/dev/ips/ip1

This allows system-level builds to operate on multiple IP components simultaneously.


------------------------------------------------------------

# Manifest and History

run.yaml stores the current state of the run including:

run identifiers  
workspace path  
loaded IPs  
last executed action  
timestamp of last update  
parameters of the last operation

The history directory stores a JSON file for each executed action containing:

timestamp  
action name  
top module  
loaded IPs  
parameters used


------------------------------------------------------------

# Session Tracking

Every CLI execution generates a session directory under:

workspace/sessions/

Each session contains:

execution metadata  
command invocation  
logs and status information

This separation allows debugging CLI executions independently from run state.


------------------------------------------------------------

# Action Registry

The action registry defines high-level actions exposed by the CLI.

Each action maps to a backend command and may define:

required parameters  
execution command  
post-processing hooks

This registry allows the CLI to remain simple while new actions can be added easily.


------------------------------------------------------------

# Helper Modules

Several helper modules support the main architecture.

helptext.py  
Provides formatted help documentation using Rich.

reporting.py  
Handles formatted summaries printed after runs.

planning.py  
Supports execution planning for batch operations.

tools/  
Contains scripts used by Make targets for generation tasks.


------------------------------------------------------------

# Typical Execution Path

A typical command flows through the system in the following order:

User invokes CLI command

CLI parses arguments

CLI builds execution parameters

Executor validates the action

Run reference is resolved

Runner launches the Make command

Flow generates artifacts

Manifest and history are updated

Results are displayed to the user


------------------------------------------------------------

# Design Principles

flexsoc follows several key design principles.

Minimalism  
Avoid unnecessary frameworks and abstractions.

Transparency  
Makefile flow remains visible and easy to debug.

Determinism  
Workspace-based runs ensure reproducible results.

Separation of concerns  
CLI, execution logic, and backend flow remain clearly separated.

Extensibility  
New actions and tools can be added without restructuring the system.


------------------------------------------------------------

# Summary

flexsoc provides a structured yet lightweight environment for hardware development.

By combining:

a Python CLI  
a Make-based flow backend  
a workspace-based execution model  

the framework supports both small IP development workflows and larger SoC integration flows while remaining easy to understand and extend.