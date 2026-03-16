<p align="center">
<img src="assets/open-IP-SoC-logo.png" alt="Digital IP SoC Dev Env Logo" width="300"/>
</p>

<a id="setup"></a>

# ✨ flexsoc

> **A framework for IP development and SoC integration**

`flexsoc` is a **workspace‑based hardware development framework**
designed to make the full digital design lifecycle **structured,
reproducible, and transparent**.

It combines a modern **Python CLI 🐍**, deterministic **Make-based
hardware flows 🛠**, and a clean **workspace execution model 📦** to
support everything from **standalone IP development** to **complete SoC
integration**.

The goal is simple:

> Keep hardware development **powerful**, **scriptable**, and
> **engineer‑friendly**, without hiding the underlying tools.

------------------------------------------------------------------------

# 🚀 What FlexSoC Enables

With **FlexSoC**, you can manage the full lifecycle of digital IPs and SoCs:

* 🧩 **IP development**
* 📋 **Register-map generation**
* 🧰 **Testbench scaffolding**
* 🧪 **Simulation and verification**
* ⚙️ **Synthesis**
* 📊 **Static timing analysis**
* 🔋 **Power analysis**
* 🏗 **Place & route**
* 🧠 **Crossbar / interconnect generation**
* 🔗 **SoC integration**

All within **a single coherent development model**.

------------------------------------------------------------------------

# 🎯 Project Objectives

FlexSoC was created to address a common challenge in hardware development:
**tool fragmentation and fragile project setups**.

Its goals are to:

* Enable digital designers to **develop, document, validate, and integrate IPs** with minimal setup, allowing them to focus on the core logic.

* Make **open-source EDA tools** practical and usable for real-world hardware development.

* Provide a smooth **integration path into SoCs**, including systems based on the **lowRISC ecosystem**.

* Serve as a launchpad for **future IP contributions to the lowRISC ecosystem**, following its Comportable IP principles and tooling flow.

* Explore **natural-language-assisted hardware workflows**, while maintaining deterministic execution through Makefile-based flows.

---

> **FlexSoC bridges structured hardware engineering with modern developer workflows.**

------------------------------------------------------------------------

# 🧠 Core philosophy

`flexsoc` is designed around a few strong ideas.

## 1️⃣ Workspace‑first execution

All generated artifacts live in a **workspace**, never inside the
repository.

    workspace/
      runs/
        <run_top>/<run_id>/

This ensures:

-   clean repositories
-   reproducible runs
-   easy comparison between runs
-   safe experimentation

Multiple runs can coexist without overwriting results.

------------------------------------------------------------------------

## 2️⃣ Modern CLI + deterministic backend

Users interact with the system through a modern CLI:

    flexsoc

But internally the system still relies on **Make-based flows**.

This means:

✔ high-level interface\
✔ explicit low-level commands\
✔ easy debugging\
✔ transparent flows

Nothing is hidden.

------------------------------------------------------------------------

## 3️⃣ Incremental workflow

`flexsoc` is designed for **iterative hardware development**.

You can start with a single IP:

    flexsoc run ip_start

and grow naturally into:

-   subsystem design
-   SoC integration
-   multi-IP systems

without changing tools.

------------------------------------------------------------------------

# 🌟 Key Features

FlexSoC provides a modern and structured hardware development workflow:

* ✨ **Python CLI** with a Typer-style user experience
* 📦 **Workspace-based execution model**
* 📜 **Action registry system** for extensible flows
* 📊 **Run manifests and reports** for reproducibility
* 📁 **Deterministic directory structure**
* ⚡ **Make-based flow backend**
* 🧩 **Automatic SoC generation tools**
* 🔗 **FuseSoC integration**
* 🧪 **Verilator simulation support**
* 🧰 **Compatibility with open-source EDA tools**

------------------------------------------------------------------------

# 📂 Project structure

    src/flexsoc
    │
    ├── cli.py                    🖥 CLI entry point
    ├── config.py                 ⚙ global configuration
    │
    ├── catalog/                  📚 action registry system
    │   ├── planning.py
    │   ├── registry.py
    │   └── registry.yaml
    │
    ├── runtime/                  ⚙ execution engine
    │   ├── executor.py
    │   ├── orchestration.py
    │   ├── runner.py
    │   ├── manifest.py
    │   └── reporting.py
    │
    ├── state/                    📦 workspace state
    │   ├── workspace.py
    │   ├── context.py
    │   └── clean.py
    │
    ├── presentation/             🎨 CLI output
    │   ├── ui.py
    │   └── helptext.py
    │
    ├── diagnostics/              🩺 environment checks
    │   └── doctor.py
    │
    ├── flow/                     🛠 Make-based flows
    │   └── mk/
    │       ├── 00-common.mk
    │       ├── 10-help-setup.mk
    │       ├── 20-ip-flow.mk
    │       ├── 30-soc-flow.mk
    │       └── 40-fsm-clean.mk
    │
    └── tools/                    🔧 generators and utilities
        ├── soc_gen.py
        ├── soc_cfg.py
        ├── driver_gen.py
        ├── gen_filelist.py
        ├── regression.py
        ├── rtl_stub_gen.py
        └── ...

------------------------------------------------------------------------
# 📦 Dependencies

FlexSoC can run **locally** or inside **Docker** (recommended for reproducibility).

---

## Install Docker

Ubuntu / Debian:

```bash
curl -fsSL https://get.docker.com | sh
sudo groupadd docker
sudo usermod -aG docker $USER
newgrp docker
docker version
```

---

## Run with Docker

Pull the container:

```bash
docker pull ghcr.io/eneadim/flexsoc:latest
```

Run it:

```bash
docker run --rm -it \
  -e DISPLAY=$DISPLAY \
  -e GDK_BACKEND=x11 -e QT_X11_NO_MITSHM=1 -e NO_AT_BRIDGE=1 \
  -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
  ghcr.io/eneadim/flexsoc:latest bash

cd /opt/flexsoc
```

The container includes the full open-source hardware toolchain.

------------------------------------------------------------------------

# 🧭 Execution model

`flexsoc` produces **two categories of artifacts**.

## 🧾 Runner‑level artifacts

Capture the execution of a CLI command.

    workspace/sessions/<timestamp>_<action>/
      stdout.log
      stderr.log

These logs help debug CLI-level execution.

------------------------------------------------------------------------

## 🏗 Flow‑level artifacts

Contain the actual hardware outputs.

    workspace/runs/<run_top>/<run_id>/
      rtl/
      tb/
      sim/
      syn/
      signoff/
      logs/

These directories contain the real design outputs.

------------------------------------------------------------------------


# ⚙️ CLI overview

Main commands:

    flexsoc run
    flexsoc make
    flexsoc use
    flexsoc actions
    flexsoc action <name>
    flexsoc doctor

Convenience shortcuts:

    flexsoc h   → help
    flexsoc q   → quickstart
    flexsoc t   → tutorials
    flexsoc ip  → IP development guide

------------------------------------------------------------------------

# 📦 Workspace context (`use`)

Instead of repeating parameters for every command, you can define a
working context:

    flexsoc use --workspace workspace --run-top my_ip --run-id dev --top my_ip

Subsequent commands automatically reuse this context.

------------------------------------------------------------------------

# 🧩 Typical IP workflow

Initialize an IP workspace:

    flexsoc run ip_start --top my_ip --run-id dev

Run simulation:

    flexsoc make sim

Run implementation:

    flexsoc make syn
    flexsoc make sta
    flexsoc make power
    flexsoc make pnr

Package the IP:

    flexsoc make ip_save

------------------------------------------------------------------------

# 🏗 SoC integration flow

Load IP bundles:

    flexsoc make ip_load --top uart
    flexsoc make ip_load --top gpio

Generate SoC:

    flexsoc make xbar soc

Simulate:

    flexsoc make soc_run

------------------------------------------------------------------------

# 🧪 Tutorials

Example tutorials included in the framework:

    flexsoc make fsm_tutorial
    flexsoc make ip_tutorial
    flexsoc make soc_ibex_tutorial

------------------------------------------------------------------------

# 🧑 💻 Developer commands

    make help
    make lint
    make test
    make check

------------------------------------------------------------------------

# 🧠 Philosophy

`flexsoc` deliberately avoids hiding the hardware flow.

Instead it makes the process:

✨ structured
✨ reproducible
✨ discoverable
✨ easy to integrate

while keeping the underlying tools visible.

------------------------------------------------------------------------

# 🧭 Roadmap

Future directions include:

🤖 AI-assisted workflow navigation
🧠 natural-language FSM generation
🔬 formal verification integration
🔗 AXI interface support
🏗 larger SoC assembly workflows

------------------------------------------------------------------------

# 📜 License

Apache License 2.0
