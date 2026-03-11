<p align="center">
<img src="assets/open-IP-SoC-logo.png" alt="Digital IP SoC Dev Env Logo" width="300"/>
</p>

<a id="setup"></a>

# flexsoc ✨

**A framework for IP development and SoC integration**

`flexsoc` is a workspace‑based hardware development framework for building, verifying, and integrating digital IPs using a fully open‑source flow.

It provides a consistent developer experience across the entire hardware lifecycle:

* IP bring‑up
* register‑map generation
* testbench setup
* simulation
* synthesis
* STA / power signoff
* place and route
* SoC integration

The project combines a modern **Python CLI** with a deterministic **Make‑based backend**, giving designers both a guided interface and full low‑level control of the flow.

---

# Why flexsoc

Digital IP development often evolves into a collection of ad‑hoc scripts, fragile Makefiles, and project‑specific conventions.

`flexsoc` tries to solve this by introducing a cleaner model based on:

* a **single entry point** for designers
* a **workspace‑based execution model**
* reproducible flow steps
* automated **OpenTitan‑style collateral generation**
* a smooth path from **standalone IP development → SoC integration**

The framework is intentionally incremental: it helps you start quickly, iterate rapidly, and still keep the flow completely transparent.

---

# Core ideas

## Workspace‑first execution

All generated artifacts live in a workspace instead of inside the repository.

This keeps the repository clean and makes runs easier to compare, archive, and reproduce.

```
workspace/
  runs/
    <top>/<run_id>/
```

Multiple runs can coexist safely without overwriting previous results.

---

## Modern CLI + deterministic backend

Users interact through the `flexsoc` CLI.

Under the hood the system still uses Make targets and explicit scripts.

This provides:

* a high‑level interface
* explicit commands
* compatibility with direct Make usage
* easy debugging

---

## IP development and SoC integration in one environment

The same framework supports:

* standalone IP development
* SoC assembly and crossbar integration
* bundled IP reuse
* reproducible SoC runs

---

# Highlights

* Typer‑based CLI
* registry‑driven actions
* workspace‑based runs
* runner‑level manifests
* flow‑level manifests
* pure JSON structured outputs
* Verilator simulation
* Yosys synthesis
* OpenSTA signoff
* OpenROAD PnR
* Cocotb testbench generation
* OpenTitan‑compatible register generation

---

# Project structure

```
flexsoc/
├── Makefile
├── flow/
│   └── util/
├── src/
│   └── flexsoc/
│       ├── cli.py
│       ├── ui.py
│       ├── executor.py
│       ├── runner.py
│       ├── reporting.py
│       ├── registry.yaml
│       ├── flow/
│       │   └── Makefile
│       └── tools/
├── hw/
│   └── ips/
├── workspace/
└── tests/
```

---

# Execution model

`flexsoc` produces two categories of artifacts.

## Runner‑level artifacts

Capture execution of the CLI command itself.

```
workspace/sessions/<timestamp>_<action>/
  stdout.log
  stderr.log
```

## Flow‑level artifacts

Contain actual design outputs.

```
workspace/runs/<top>/<run_id>/
  rtl/
  tb/
  sim/
  syn/
  signoff/
  logs/
```

---

# Installation

Create a Python virtual environment and install flexsoc in editable mode.

```
python3 -m venv .venv
source .venv/bin/activate
pip install -e .
```

Developer checks:

```
make lint
make test
make check
```

---

# CLI overview

Main entry point:

```
flexsoc
```

Main commands:

```
flexsoc run
flexsoc make
flexsoc use
flexsoc actions
flexsoc action <name>
```

Convenience shortcuts:

```
flexsoc h
flexsoc q
flexsoc t
flexsoc ip
```

---

# Workspace context (`use`)

Instead of repeating options for every command, you can set the working context once.

```
flexsoc use --workspace workspace --run-top my_ip --run-id dev --top my_ip
```

Subsequent commands will automatically reuse those values.

You can still override them per command if needed.

---

# Typical usage

Initialize an IP workspace:

```
flexsoc run ip_start --top my_ip --run-id dev --overwrite
```

Run synthesis and analysis:

```
flexsoc make syn sta power
```

Run PnR:

```
flexsoc make pnr
```

Open the OpenROAD GUI:

```
flexsoc make pnr_gui
```

---

# IP development flow

## 1. Create the IP workspace

```
flexsoc run ip_start --top my_ip --run-id dev
```

Directory created:

```
workspace/runs/my_ip/dev/
```

---

## 2. Generate register collateral

```
flexsoc make reg doc
```

Inputs:

```
data/my_ip.hjson
```

Outputs:

* register RTL
* documentation

---

## 3. Implement the RTL

Main files:

```
rtl/my_ip_core.sv
rtl/my_ip.sv
```

---

## 4. Create the testbench

```
flexsoc make setup_tb
```

or cocotb:

```
flexsoc make setup_cocotb
```

---

## 5. Simulation

```
flexsoc make sim
```

---

## 6. Implementation

```
flexsoc make syn
flexsoc make sta
flexsoc make power
flexsoc make pnr
```

---

## 7. Package the IP

```
flexsoc make ip_save
```

This stores the IP under:

```
hw/ips/<ip_name>/
```

---

# SoC integration flow

The framework supports simple SoC assembly using IP bundles.

## Load IPs

```
flexsoc make ip_load --top uart-master
flexsoc make ip_load --top gpio
```

## Create SoC

```
flexsoc make soc
```

This generates:

* crossbar
* SoC RTL
* memory map

```
workspace/runs/<soc>/<run_id>/rtl/
```

---

## SoC simulation

```
flexsoc make setup_cocotb
flexsoc make cocotb
```

---

## Save / load SoC bundles

Save a SoC configuration:

```
flexsoc make soc_save
```

Reload it later:

```
flexsoc make soc_load
```

---

# Tutorials

## FSM tutorial

```
flexsoc make fsm_tutorial
```

## IP tutorial

```
flexsoc make ip_tutorial
```

## SoC tutorial

```
flexsoc make soc_tutorial
```

---

# Developer Makefile

```
make help
make lint
make fix
make test
make check
```

---

# Reports

Flow metadata:

```
manifest.json
```

Run summaries:

```
report.json
```

---

# Philosophy

`flexsoc` does not hide the hardware flow.

Instead it aims to make it:

* cleaner
* reproducible
* discoverable
* easier to integrate

The backend remains explicit.

The user experience becomes friendlier.

## Roadmap / next steps 

### AI-assisted workflow 
* guided use of the tool * natural-language help and flow Navigation.
* automated FSM generation from natural-language descriptions.
* future structured design-assist workflows without compromising determinism of execution.

### Formal verification 
* Add **SymbiYosys**-based formal checks for selected IP classes and protocol adapters. 

### AXI interface support 
* Extend the register / integration side with **AXI4 / AXI-Lite** support, ideally reusing existing work and conventions from the **PULP Platform** ecosystem where appropriate. 

### Broader SoC Integration
* Continue improving the path from standalone IP work to system-level integration, especially for crossbar/interconnect-oriented flows.

---

# License

Apache License 2.0

